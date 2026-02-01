#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftComputerProcessBehavior(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A4AC: lbu         $t6, 0x1CF($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1CF);
    // 0x8013A4B0: sltiu       $at, $t6, 0x14
    ctx->r1 = ctx->r14 < 0X14 ? 1 : 0;
    // 0x8013A4B4: beq         $at, $zero, L_8013A634
    if (ctx->r1 == 0) {
        // 0x8013A4B8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8013A634;
    }
    // 0x8013A4B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013A4BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013A4C0: addu        $at, $at, $t6
    gpr jr_addend_8013A4C8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8013A4C4: lw          $t6, -0x4054($at)
    ctx->r14 = ADD32(ctx->r1, -0X4054);
    // 0x8013A4C8: jr          $t6
    // 0x8013A4CC: nop

    switch (jr_addend_8013A4C8 >> 2) {
        case 0: goto L_8013A4D0; break;
        case 1: goto L_8013A4EC; break;
        case 2: goto L_8013A508; break;
        case 3: goto L_8013A524; break;
        case 4: goto L_8013A540; break;
        case 5: goto L_8013A55C; break;
        case 6: goto L_8013A634; break;
        case 7: goto L_8013A578; break;
        case 8: goto L_8013A594; break;
        case 9: goto L_8013A5B0; break;
        case 10: goto L_8013A634; break;
        case 11: goto L_8013A634; break;
        case 12: goto L_8013A634; break;
        case 13: goto L_8013A5CC; break;
        case 14: goto L_8013A634; break;
        case 15: goto L_8013A5E8; break;
        case 16: goto L_8013A5F8; break;
        case 17: goto L_8013A608; break;
        case 18: goto L_8013A618; break;
        case 19: goto L_8013A628; break;
        default: switch_error(__func__, 0x8013A4C8, 0x8018BFAC);
    }
    // 0x8013A4CC: nop

L_8013A4D0:
    // 0x8013A4D0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013A4D4: addiu       $t7, $t7, 0x7778
    ctx->r15 = ADD32(ctx->r15, 0X7778);
    // 0x8013A4D8: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A4DC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8013A4E0: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8013A4E4: jr          $ra
    // 0x8013A4E8: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    return;
    // 0x8013A4E8: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
L_8013A4EC:
    // 0x8013A4EC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013A4F0: addiu       $t9, $t9, 0x7778
    ctx->r25 = ADD32(ctx->r25, 0X7778);
    // 0x8013A4F4: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A4F8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x8013A4FC: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x8013A500: jr          $ra
    // 0x8013A504: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    return;
    // 0x8013A504: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
L_8013A508:
    // 0x8013A508: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013A50C: addiu       $t1, $t1, 0x7778
    ctx->r9 = ADD32(ctx->r9, 0X7778);
    // 0x8013A510: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A514: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x8013A518: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8013A51C: jr          $ra
    // 0x8013A520: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    return;
    // 0x8013A520: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
L_8013A524:
    // 0x8013A524: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8013A528: addiu       $t3, $t3, 0x7778
    ctx->r11 = ADD32(ctx->r11, 0X7778);
    // 0x8013A52C: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A530: addiu       $t4, $zero, 0x9
    ctx->r12 = ADD32(0, 0X9);
    // 0x8013A534: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x8013A538: jr          $ra
    // 0x8013A53C: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
    return;
    // 0x8013A53C: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
L_8013A540:
    // 0x8013A540: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8013A544: addiu       $t5, $t5, 0x7778
    ctx->r13 = ADD32(ctx->r13, 0X7778);
    // 0x8013A548: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A54C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x8013A550: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x8013A554: jr          $ra
    // 0x8013A558: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    return;
    // 0x8013A558: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
L_8013A55C:
    // 0x8013A55C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013A560: addiu       $t7, $t7, 0x7778
    ctx->r15 = ADD32(ctx->r15, 0X7778);
    // 0x8013A564: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A568: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8013A56C: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8013A570: jr          $ra
    // 0x8013A574: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    return;
    // 0x8013A574: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
L_8013A578:
    // 0x8013A578: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013A57C: addiu       $t9, $t9, 0x7778
    ctx->r25 = ADD32(ctx->r25, 0X7778);
    // 0x8013A580: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A584: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x8013A588: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x8013A58C: jr          $ra
    // 0x8013A590: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    return;
    // 0x8013A590: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
L_8013A594:
    // 0x8013A594: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013A598: addiu       $t1, $t1, 0x7778
    ctx->r9 = ADD32(ctx->r9, 0X7778);
    // 0x8013A59C: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A5A0: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8013A5A4: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8013A5A8: jr          $ra
    // 0x8013A5AC: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    return;
    // 0x8013A5AC: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
L_8013A5B0:
    // 0x8013A5B0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8013A5B4: addiu       $t3, $t3, 0x7778
    ctx->r11 = ADD32(ctx->r11, 0X7778);
    // 0x8013A5B8: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A5BC: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x8013A5C0: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x8013A5C4: jr          $ra
    // 0x8013A5C8: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
    return;
    // 0x8013A5C8: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
L_8013A5CC:
    // 0x8013A5CC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8013A5D0: addiu       $t5, $t5, 0x7778
    ctx->r13 = ADD32(ctx->r13, 0X7778);
    // 0x8013A5D4: addiu       $v0, $a0, 0x1CC
    ctx->r2 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A5D8: addiu       $t6, $zero, 0xB
    ctx->r14 = ADD32(0, 0XB);
    // 0x8013A5DC: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x8013A5E0: jr          $ra
    // 0x8013A5E4: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    return;
    // 0x8013A5E4: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
L_8013A5E8:
    // 0x8013A5E8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013A5EC: addiu       $t7, $t7, 0x7A18
    ctx->r15 = ADD32(ctx->r15, 0X7A18);
    // 0x8013A5F0: jr          $ra
    // 0x8013A5F4: sw          $t7, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r15;
    return;
    // 0x8013A5F4: sw          $t7, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r15;
L_8013A5F8:
    // 0x8013A5F8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013A5FC: addiu       $t8, $t8, 0x7AA4
    ctx->r24 = ADD32(ctx->r24, 0X7AA4);
    // 0x8013A600: jr          $ra
    // 0x8013A604: sw          $t8, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r24;
    return;
    // 0x8013A604: sw          $t8, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r24;
L_8013A608:
    // 0x8013A608: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013A60C: addiu       $t9, $t9, 0x7C7C
    ctx->r25 = ADD32(ctx->r25, 0X7C7C);
    // 0x8013A610: jr          $ra
    // 0x8013A614: sw          $t9, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r25;
    return;
    // 0x8013A614: sw          $t9, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r25;
L_8013A618:
    // 0x8013A618: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8013A61C: addiu       $t0, $t0, 0x7CD8
    ctx->r8 = ADD32(ctx->r8, 0X7CD8);
    // 0x8013A620: jr          $ra
    // 0x8013A624: sw          $t0, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r8;
    return;
    // 0x8013A624: sw          $t0, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r8;
L_8013A628:
    // 0x8013A628: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013A62C: addiu       $t1, $t1, 0x7E70
    ctx->r9 = ADD32(ctx->r9, 0X7E70);
    // 0x8013A630: sw          $t1, 0x1D8($a0)
    MEM_W(0X1D8, ctx->r4) = ctx->r9;
L_8013A634:
    // 0x8013A634: jr          $ra
    // 0x8013A638: nop

    return;
    // 0x8013A638: nop

;}
RECOMP_FUNC void func_ovl29_80133C14(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133C14: jr          $ra
    // 0x80133C18: nop

    return;
    // 0x80133C18: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C88C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015C890: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015C894: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8015C898: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015C89C: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x8015C8A0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015C8A4: jal         0x800E6F24
    // 0x8015C8A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015C8A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015C8AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C8B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015C8B4: jr          $ra
    // 0x8015C8B8: nop

    return;
    // 0x8015C8B8: nop

;}
RECOMP_FUNC void mpCommonCheckFighterOnEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDE50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DDE54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDE58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DDE5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DDE60: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DDE64: addiu       $a1, $a1, -0x23B0
    ctx->r5 = ADD32(ctx->r5, -0X23B0);
    // 0x800DDE68: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800DDE6C: jal         0x800DA034
    // 0x800DDE70: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DDE70: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DDE74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DDE78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DDE7C: jr          $ra
    // 0x800DDE80: nop

    return;
    // 0x800DDE80: nop

;}
RECOMP_FUNC void mnVSModeGetNumberOfDigits(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BF4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131BF8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131BFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131C00: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80131C04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131C08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131C0C: blez        $a1, L_80131C84
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80131C10: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80131C84;
    }
    // 0x80131C10: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_80131C14:
    // 0x80131C14: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x80131C18: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80131C1C: jal         0x80131B24
    // 0x80131C20: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    mnVSModePow(rdram, ctx);
        goto after_0;
    // 0x80131C20: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80131C24: beq         $v0, $zero, L_80131C6C
    if (ctx->r2 == 0) {
        // 0x80131C28: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131C6C;
    }
    // 0x80131C28: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131C2C: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80131C30: jal         0x80131B24
    // 0x80131C34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnVSModePow(rdram, ctx);
        goto after_1;
    // 0x80131C34: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80131C38: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80131C3C: mflo        $v1
    ctx->r3 = lo;
    // 0x80131C40: bne         $v0, $zero, L_80131C4C
    if (ctx->r2 != 0) {
        // 0x80131C44: nop
    
            goto L_80131C4C;
    }
    // 0x80131C44: nop

    // 0x80131C48: break       7
    do_break(2148736072);
L_80131C4C:
    // 0x80131C4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131C50: bne         $v0, $at, L_80131C64
    if (ctx->r2 != ctx->r1) {
        // 0x80131C54: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131C64;
    }
    // 0x80131C54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131C58: bne         $s2, $at, L_80131C64
    if (ctx->r18 != ctx->r1) {
        // 0x80131C5C: nop
    
            goto L_80131C64;
    }
    // 0x80131C5C: nop

    // 0x80131C60: break       6
    do_break(2148736096);
L_80131C64:
    // 0x80131C64: b           L_80131C6C
    // 0x80131C68: nop

        goto L_80131C6C;
    // 0x80131C68: nop

L_80131C6C:
    // 0x80131C6C: beq         $v1, $zero, L_80131C7C
    if (ctx->r3 == 0) {
        // 0x80131C70: nop
    
            goto L_80131C7C;
    }
    // 0x80131C70: nop

    // 0x80131C74: b           L_80131C88
    // 0x80131C78: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80131C88;
    // 0x80131C78: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80131C7C:
    // 0x80131C7C: bne         $s0, $zero, L_80131C14
    if (ctx->r16 != 0) {
        // 0x80131C80: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80131C14;
    }
    // 0x80131C80: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80131C84:
    // 0x80131C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131C88:
    // 0x80131C88: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131C8C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131C90: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131C94: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131C98: jr          $ra
    // 0x80131C9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131C9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_8037BD44(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BD44: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037BD48: lw          $v1, -0x1034($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1034);
    // 0x8037BD4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037BD50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037BD54: beql        $v1, $zero, L_8037BD88
    if (ctx->r3 == 0) {
        // 0x8037BD58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037BD88;
    }
    goto skip_0;
    // 0x8037BD58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8037BD5C: beq         $v1, $zero, L_8037BD7C
    if (ctx->r3 == 0) {
        // 0x8037BD60: nop
    
            goto L_8037BD7C;
    }
    // 0x8037BD60: nop

    // 0x8037BD64: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x8037BD68: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8037BD6C: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8037BD70: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x8037BD74: jalr        $t9
    // 0x8037BD78: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037BD78: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
L_8037BD7C:
    // 0x8037BD7C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037BD80: sw          $zero, -0x1034($at)
    MEM_W(-0X1034, ctx->r1) = 0;
    // 0x8037BD84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037BD88:
    // 0x8037BD88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037BD8C: jr          $ra
    // 0x8037BD90: nop

    return;
    // 0x8037BD90: nop

;}
RECOMP_FUNC void itNyarsWeaponCoinProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F1CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017F1D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F1D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017F1D8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017F1DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017F1E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017F1E4: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x8017F1E8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017F1EC: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x8017F1F0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8017F1F4: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x8017F1F8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8017F1FC: jal         0x80019438
    // 0x8017F200: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x8017F200: nop

    after_0:
    // 0x8017F204: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F208: lwc1        $f12, 0x24($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8017F20C: jal         0x8001863C
    // 0x8017F210: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8017F210: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    after_1:
    // 0x8017F214: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x8017F218: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F21C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017F220: lw          $t7, 0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X74);
    // 0x8017F224: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017F228: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017F22C: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
    // 0x8017F230: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x8017F234: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8017F238: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8017F23C: swc1        $f10, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f10.u32l;
    // 0x8017F240: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8017F244: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8017F248: nop

    // 0x8017F24C: bc1fl       L_8017F260
    if (!c1cs) {
        // 0x8017F250: sw          $t0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r8;
            goto L_8017F260;
    }
    goto skip_0;
    // 0x8017F250: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    skip_0:
    // 0x8017F254: b           L_8017F260
    // 0x8017F258: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
        goto L_8017F260;
    // 0x8017F258: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x8017F25C: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_8017F260:
    // 0x8017F260: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017F264: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017F268: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F26C: jr          $ra
    // 0x8017F270: nop

    return;
    // 0x8017F270: nop

;}
RECOMP_FUNC void itBoxMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801799A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801799A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801799AC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801799B0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x801799B4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801799B8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801799BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801799C0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801799C4: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801799C8: addiu       $a1, $a1, -0x5CB0
    ctx->r5 = ADD32(ctx->r5, -0X5CB0);
    // 0x801799CC: jal         0x8016E174
    // 0x801799D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x801799D0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x801799D4: beq         $v0, $zero, L_80179A20
    if (ctx->r2 == 0) {
        // 0x801799D8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80179A20;
    }
    // 0x801799D8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801799DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801799E0: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x801799E4: lwc1        $f4, -0x328C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X328C);
    // 0x801799E8: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x801799EC: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    // 0x801799F0: lbu         $t9, 0x2CF($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2CF);
    // 0x801799F4: lbu         $t2, 0x2D3($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X2D3);
    // 0x801799F8: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x801799FC: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x80179A00: sb          $t0, 0x2CF($a0)
    MEM_B(0X2CF, ctx->r4) = ctx->r8;
    // 0x80179A04: sb          $t3, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r11;
    // 0x80179A08: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80179A0C: jal         0x80111EC0
    // 0x80179A10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80179A10: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80179A14: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80179A18: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80179A1C: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_80179A20:
    // 0x80179A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80179A24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80179A28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80179A2C: jr          $ra
    // 0x80179A30: nop

    return;
    // 0x80179A30: nop

;}
RECOMP_FUNC void ftFoxSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BC78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015BC7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BC80: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015BC84: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015BC88: addiu       $a1, $zero, 0xE1
    ctx->r5 = ADD32(0, 0XE1);
    // 0x8015BC8C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015BC90: jal         0x800E6F24
    // 0x8015BC94: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BC94: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015BC98: jal         0x800E0830
    // 0x8015BC9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015BC9C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015BCA0: jal         0x8015BC68
    // 0x8015BCA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015BCA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015BCA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015BCAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015BCB0: jr          $ra
    // 0x8015BCB4: nop

    return;
    // 0x8015BCB4: nop

;}
RECOMP_FUNC void itKamexAttackMakeHydro(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180F9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80180FA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180FA4: jal         0x80180EDC
    // 0x80180FA8: nop

    itKamexWeaponHydroMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80180FA8: nop

    after_0:
    // 0x80180FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180FB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80180FB4: jr          $ra
    // 0x80180FB8: nop

    return;
    // 0x80180FB8: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiJibakuProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801547EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801547F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801547F4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801547F8: lw          $t6, 0xB28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB28);
    // 0x801547FC: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80154800: bne         $t7, $zero, L_80154810
    if (ctx->r15 != 0) {
        // 0x80154804: sw          $t7, 0xB28($v0)
        MEM_W(0XB28, ctx->r2) = ctx->r15;
            goto L_80154810;
    }
    // 0x80154804: sw          $t7, 0xB28($v0)
    MEM_W(0XB28, ctx->r2) = ctx->r15;
    // 0x80154808: jal         0x80154558
    // 0x8015480C: nop

    ftNessSpecialAirHiEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015480C: nop

    after_0:
L_80154810:
    // 0x80154810: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80154814: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80154818: jr          $ra
    // 0x8015481C: nop

    return;
    // 0x8015481C: nop

;}
RECOMP_FUNC void func_ovl8_80384BD4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80384BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384BDC: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80384BE0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80384BE4: lh          $a1, 0x3C($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X3C);
    // 0x80384BE8: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x80384BEC: lh          $t6, 0xD0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XD0);
    // 0x80384BF0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80384BF4: jalr        $t9
    // 0x80384BF8: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80384BF8: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80384BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384C00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384C04: jr          $ra
    // 0x80384C08: nop

    return;
    // 0x80384C08: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133D9C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80133DA0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133DA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133DA8: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80133DAC: addiu       $t7, $t7, -0x7564
    ctx->r15 = ADD32(ctx->r15, -0X7564);
    // 0x80133DB0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133DB4: addiu       $t6, $sp, 0x5C
    ctx->r14 = ADD32(ctx->r29, 0X5C);
    // 0x80133DB8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80133DBC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133DC0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133DC4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133DC8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80133DCC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133DD0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80133DD4: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133DD8: addiu       $t1, $t1, -0x7550
    ctx->r9 = ADD32(ctx->r9, -0X7550);
    // 0x80133DDC: addiu       $t4, $t1, 0x24
    ctx->r12 = ADD32(ctx->r9, 0X24);
    // 0x80133DE0: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x80133DE4: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80133DE8: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
L_80133DEC:
    // 0x80133DEC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80133DF0: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80133DF4: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80133DF8: sw          $t3, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r11;
    // 0x80133DFC: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x80133E00: sw          $t2, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r10;
    // 0x80133E04: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x80133E08: bne         $t1, $t4, L_80133DEC
    if (ctx->r9 != ctx->r12) {
        // 0x80133E0C: sw          $t3, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r11;
            goto L_80133DEC;
    }
    // 0x80133E0C: sw          $t3, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r11;
    // 0x80133E10: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80133E14: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133E18: addiu       $t6, $t6, -0x7528
    ctx->r14 = ADD32(ctx->r14, -0X7528);
    // 0x80133E1C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80133E20: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133E24: addiu       $t5, $sp, 0x24
    ctx->r13 = ADD32(ctx->r29, 0X24);
    // 0x80133E28: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80133E2C: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x80133E30: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80133E34: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80133E38: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80133E3C: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
    // 0x80133E40: lwr         $t8, 0xE($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0XE);
    // 0x80133E44: swr         $t8, 0xE($t5)
    do_swr(rdram, 0XE, ctx->r13, ctx->r24);
    // 0x80133E48: lw          $a1, -0x7044($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X7044);
    // 0x80133E4C: beql        $a1, $zero, L_80133E60
    if (ctx->r5 == 0) {
        // 0x80133E50: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80133E60;
    }
    goto skip_0;
    // 0x80133E50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
    // 0x80133E54: jal         0x80009A84
    // 0x80133E58: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80133E58: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80133E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80133E60:
    // 0x80133E60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133E64: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80133E68: jal         0x80009968
    // 0x80133E6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80133E6C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133E70: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80133E74: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80133E78: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80133E7C: sw          $v0, -0x7044($at)
    MEM_W(-0X7044, ctx->r1) = ctx->r2;
    // 0x80133E80: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80133E84: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80133E88: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80133E8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133E90: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x80133E94: jal         0x80009DF4
    // 0x80133E98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80133E98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80133E9C: lw          $t4, 0x78($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X78);
    // 0x80133EA0: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80133EA4: lw          $t2, -0x6948($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6948);
    // 0x80133EA8: sll         $t1, $t4, 2
    ctx->r9 = S32(ctx->r12 << 2);
    // 0x80133EAC: addu        $t0, $sp, $t1
    ctx->r8 = ADD32(ctx->r29, ctx->r9);
    // 0x80133EB0: lw          $t0, 0x5C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5C);
    // 0x80133EB4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80133EB8: jal         0x800CCFDC
    // 0x80133EBC: addu        $a1, $t0, $t2
    ctx->r5 = ADD32(ctx->r8, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80133EBC: addu        $a1, $t0, $t2
    ctx->r5 = ADD32(ctx->r8, ctx->r10);
    after_3:
    // 0x80133EC0: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x80133EC4: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x80133EC8: addiu       $t2, $sp, 0x24
    ctx->r10 = ADD32(ctx->r29, 0X24);
    // 0x80133ECC: andi        $t6, $t3, 0xFFDF
    ctx->r14 = ctx->r11 & 0XFFDF;
    // 0x80133ED0: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80133ED4: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80133ED8: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80133EDC: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80133EE0: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80133EE4: addu        $a0, $t9, $t4
    ctx->r4 = ADD32(ctx->r25, ctx->r12);
    // 0x80133EE8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80133EEC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80133EF0: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80133EF4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80133EF8: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x80133EFC: sll         $t0, $t1, 2
    ctx->r8 = S32(ctx->r9 << 2);
    // 0x80133F00: subu        $t0, $t0, $t1
    ctx->r8 = SUB32(ctx->r8, ctx->r9);
    // 0x80133F04: addu        $v1, $t0, $t2
    ctx->r3 = ADD32(ctx->r8, ctx->r10);
    // 0x80133F08: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80133F0C: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80133F10: lbu         $t5, 0x1($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X1);
    // 0x80133F14: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80133F18: lbu         $t6, 0x2($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X2);
    // 0x80133F1C: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80133F20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133F24: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x80133F28: jr          $ra
    // 0x80133F2C: nop

    return;
    // 0x80133F2C: nop

;}
RECOMP_FUNC void gcGetTrackAObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E008: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000E00C: beq         $a0, $zero, L_8000E038
    if (ctx->r4 == 0) {
        // 0x8000E010: andi        $a1, $a1, 0xFF
        ctx->r5 = ctx->r5 & 0XFF;
            goto L_8000E038;
    }
    // 0x8000E010: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000E014: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8000E018: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
L_8000E01C:
    // 0x8000E01C: bnel        $v0, $t6, L_8000E030
    if (ctx->r2 != ctx->r14) {
        // 0x8000E020: lw          $a0, 0x0($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X0);
            goto L_8000E030;
    }
    goto skip_0;
    // 0x8000E020: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x8000E024: jr          $ra
    // 0x8000E028: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8000E028: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8000E02C: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
L_8000E030:
    // 0x8000E030: bnel        $a0, $zero, L_8000E01C
    if (ctx->r4 != 0) {
        // 0x8000E034: lbu         $t6, 0x4($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X4);
            goto L_8000E01C;
    }
    goto skip_1;
    // 0x8000E034: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    skip_1:
L_8000E038:
    // 0x8000E038: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E03C: jr          $ra
    // 0x8000E040: nop

    return;
    // 0x8000E040: nop

;}
RECOMP_FUNC void func_ovl8_803730DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803730DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803730E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803730E4: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x803730E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x803730EC: beql        $v0, $zero, L_80373108
    if (ctx->r2 == 0) {
        // 0x803730F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80373108;
    }
    goto skip_0;
    // 0x803730F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x803730F4: jalr        $v0
    // 0x803730F8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x803730F8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x803730FC: b           L_8037310C
    // 0x80373100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8037310C;
    // 0x80373100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80373104: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80373108:
    // 0x80373108: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037310C:
    // 0x8037310C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80373110: jr          $ra
    // 0x80373114: nop

    return;
    // 0x80373114: nop

;}
RECOMP_FUNC void mnPlayers1PBonusUpdateCursorNoRecall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013545C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80135460: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80135464: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80135468: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8013546C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80135470: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80135474: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80135478: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8013547C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80135480: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x80135484: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135488: lwc1        $f0, 0x5C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x8013548C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80135490: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80135494: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80135498: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8013549C: addiu       $s2, $s2, 0x7648
    ctx->r18 = ADD32(ctx->r18, 0X7648);
    // 0x801354A0: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x801354A4: bc1tl       L_801354C8
    if (c1cs) {
        // 0x801354A8: lw          $v0, 0x28($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X28);
            goto L_801354C8;
    }
    goto skip_0;
    // 0x801354A8: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
    skip_0:
    // 0x801354AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801354B0: nop

    // 0x801354B4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x801354B8: nop

    // 0x801354BC: bc1f        L_801354F0
    if (!c1cs) {
        // 0x801354C0: nop
    
            goto L_801354F0;
    }
    // 0x801354C0: nop

    // 0x801354C4: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
L_801354C8:
    // 0x801354C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801354CC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801354D0: beq         $v0, $zero, L_801354E8
    if (ctx->r2 == 0) {
        // 0x801354D4: nop
    
            goto L_801354E8;
    }
    // 0x801354D4: nop

    // 0x801354D8: jal         0x80134364
    // 0x801354DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mnPlayers1PBonusUpdateCursor(rdram, ctx);
        goto after_0;
    // 0x801354DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801354E0: sw          $zero, 0x28($s2)
    MEM_W(0X28, ctx->r18) = 0;
    // 0x801354E4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801354E8:
    // 0x801354E8: b           L_80135558
    // 0x801354EC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80135558;
    // 0x801354EC: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_801354F0:
    // 0x801354F0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801354F4: addiu       $s2, $s2, 0x7648
    ctx->r18 = ADD32(ctx->r18, 0X7648);
    // 0x801354F8: lw          $t7, 0x54($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X54);
    // 0x801354FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80135500: bnel        $t7, $at, L_80135538
    if (ctx->r15 != ctx->r1) {
        // 0x80135504: lw          $v0, 0x28($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X28);
            goto L_80135538;
    }
    goto skip_1;
    // 0x80135504: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
    skip_1:
    // 0x80135508: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
    // 0x8013550C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80135510: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80135514: beq         $v0, $at, L_8013552C
    if (ctx->r2 == ctx->r1) {
        // 0x80135518: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_8013552C;
    }
    // 0x80135518: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8013551C: jal         0x80134364
    // 0x80135520: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayers1PBonusUpdateCursor(rdram, ctx);
        goto after_1;
    // 0x80135520: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80135524: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80135528: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
L_8013552C:
    // 0x8013552C: b           L_80135558
    // 0x80135530: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_80135558;
    // 0x80135530: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80135534: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
L_80135538:
    // 0x80135538: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8013553C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80135540: beq         $s3, $v0, L_80135558
    if (ctx->r19 == ctx->r2) {
        // 0x80135544: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80135558;
    }
    // 0x80135544: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80135548: jal         0x80134364
    // 0x8013554C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    mnPlayers1PBonusUpdateCursor(rdram, ctx);
        goto after_2;
    // 0x8013554C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x80135550: sw          $s3, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r19;
    // 0x80135554: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_80135558:
    // 0x80135558: bnel        $v0, $zero, L_801355C0
    if (ctx->r2 != 0) {
        // 0x8013555C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801355C0;
    }
    goto skip_2;
    // 0x8013555C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80135560: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x80135564: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80135568: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x8013556C: beql        $t9, $zero, L_801355C0
    if (ctx->r25 == 0) {
        // 0x80135570: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801355C0;
    }
    goto skip_3;
    // 0x80135570: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80135574: lw          $t0, 0x2C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X2C);
L_80135578:
    // 0x80135578: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8013557C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80135580: bnel        $s3, $t0, L_801355B4
    if (ctx->r19 != ctx->r8) {
        // 0x80135584: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_801355B4;
    }
    goto skip_4;
    // 0x80135584: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x80135588: jal         0x8013464C
    // 0x8013558C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mnPlayers1PBonusCheckPuckInRange(rdram, ctx);
        goto after_3;
    // 0x8013558C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80135590: beq         $v0, $zero, L_801355B0
    if (ctx->r2 == 0) {
        // 0x80135594: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_801355B0;
    }
    // 0x80135594: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80135598: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8013559C: jal         0x80134364
    // 0x801355A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayers1PBonusUpdateCursor(rdram, ctx);
        goto after_4;
    // 0x801355A0: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x801355A4: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x801355A8: b           L_801355BC
    // 0x801355AC: sw          $t1, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r9;
        goto L_801355BC;
    // 0x801355AC: sw          $t1, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r9;
L_801355B0:
    // 0x801355B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_801355B4:
    // 0x801355B4: bnel        $s0, $s1, L_80135578
    if (ctx->r16 != ctx->r17) {
        // 0x801355B8: lw          $t0, 0x2C($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X2C);
            goto L_80135578;
    }
    goto skip_5;
    // 0x801355B8: lw          $t0, 0x2C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X2C);
    skip_5:
L_801355BC:
    // 0x801355BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801355C0:
    // 0x801355C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801355C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801355C8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801355CC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801355D0: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x801355D4: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x801355D8: jr          $ra
    // 0x801355DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801355DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gcMakeCameraGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B93C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000B940: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8000B944: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000B948: jal         0x80009968
    // 0x8000B94C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8000B94C: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    after_0:
    // 0x8000B950: bne         $v0, $zero, L_8000B960
    if (ctx->r2 != 0) {
        // 0x8000B954: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000B960;
    }
    // 0x8000B954: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B958: b           L_8000B9E8
    // 0x8000B95C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000B9E8;
    // 0x8000B95C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000B960:
    // 0x8000B960: lw          $t6, 0x50($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X50);
    // 0x8000B964: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x8000B968: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8000B96C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B970: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8000B974: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x8000B978: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8000B97C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8000B980: jal         0x80009F74
    // 0x8000B984: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_80009F74(rdram, ctx);
        goto after_1;
    // 0x8000B984: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x8000B988: jal         0x80009760
    // 0x8000B98C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddCameraForGObj(rdram, ctx);
        goto after_2;
    // 0x8000B98C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8000B990: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x8000B994: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8000B998: beql        $t9, $zero, L_8000B9AC
    if (ctx->r25 == 0) {
        // 0x8000B99C: lw          $a1, 0x64($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X64);
            goto L_8000B9AC;
    }
    goto skip_0;
    // 0x8000B99C: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x8000B9A0: jal         0x8000B47C
    // 0x8000B9A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddCameraMatrixSets(rdram, ctx);
        goto after_3;
    // 0x8000B9A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8000B9A8: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
L_8000B9AC:
    // 0x8000B9AC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B9B0: lbu         $a2, 0x63($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X63);
    // 0x8000B9B4: beql        $a1, $zero, L_8000B9C8
    if (ctx->r5 == 0) {
        // 0x8000B9B8: lw          $t0, 0x6C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X6C);
            goto L_8000B9C8;
    }
    goto skip_1;
    // 0x8000B9B8: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    skip_1:
    // 0x8000B9BC: jal         0x80008188
    // 0x8000B9C0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8000B9C0: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    after_4:
    // 0x8000B9C4: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
L_8000B9C8:
    // 0x8000B9C8: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8000B9CC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8000B9D0: beq         $t0, $zero, L_8000B9E8
    if (ctx->r8 == 0) {
        // 0x8000B9D4: addiu       $t1, $zero, 0x7
        ctx->r9 = ADD32(0, 0X7);
            goto L_8000B9E8;
    }
    // 0x8000B9D4: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8000B9D8: sw          $t1, 0x80($t2)
    MEM_W(0X80, ctx->r10) = ctx->r9;
    // 0x8000B9DC: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8000B9E0: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8000B9E4: sw          $t3, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->r11;
L_8000B9E8:
    // 0x8000B9E8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B9EC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000B9F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8000B9F4: jr          $ra
    // 0x8000B9F8: nop

    return;
    // 0x8000B9F8: nop

;}
RECOMP_FUNC void itNBumperGDisappearSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BF1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017BF20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BF24: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017BF28: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017BF2C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017BF30: lw          $t6, 0x80($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X80);
    // 0x8017BF34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BF38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017BF3C: swc1        $f4, 0x88($t6)
    MEM_W(0X88, ctx->r14) = ctx->f4.u32l;
    // 0x8017BF40: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x8017BF44: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x8017BF48: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x8017BF4C: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8017BF50: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8017BF54: sw          $t7, 0x2C0($v0)
    MEM_W(0X2C0, ctx->r2) = ctx->r15;
    // 0x8017BF58: sb          $zero, 0x54($v1)
    MEM_B(0X54, ctx->r3) = 0;
    // 0x8017BF5C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017BF60: addiu       $a1, $a1, -0x593C
    ctx->r5 = ADD32(ctx->r5, -0X593C);
    // 0x8017BF64: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x8017BF68: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x8017BF6C: swc1        $f2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f2.u32l;
    // 0x8017BF70: swc1        $f2, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f2.u32l;
    // 0x8017BF74: jal         0x80172EC8
    // 0x8017BF78: swc1        $f2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f2.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017BF78: swc1        $f2, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f2.u32l;
    after_0:
    // 0x8017BF7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017BF80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017BF84: jr          $ra
    // 0x8017BF88: nop

    return;
    // 0x8017BF88: nop

;}
RECOMP_FUNC void ftDisplayMainCalcFogColor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F17E8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800F17EC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800F17F0: lbu         $v0, 0x11($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X11);
    // 0x800F17F4: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x800F17F8: bnel        $v0, $zero, L_800F181C
    if (ctx->r2 != 0) {
        // 0x800F17FC: lw          $t0, 0x9C8($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X9C8);
            goto L_800F181C;
    }
    goto skip_0;
    // 0x800F17FC: lw          $t0, 0x9C8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X9C8);
    skip_0:
    // 0x800F1800: lbu         $v0, 0xA68($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA68);
    // 0x800F1804: lbu         $v1, 0xA69($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XA69);
    // 0x800F1808: lbu         $a1, 0xA6A($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0XA6A);
    // 0x800F180C: lbu         $a2, 0xA6B($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0XA6B);
    // 0x800F1810: b           L_800F1AB8
    // 0x800F1814: lw          $t0, 0x9C8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X9C8);
        goto L_800F1AB8;
    // 0x800F1814: lw          $t0, 0x9C8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X9C8);
    // 0x800F1818: lw          $t0, 0x9C8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X9C8);
L_800F181C:
    // 0x800F181C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800F1820: lbu         $a3, 0xA6B($a0)
    ctx->r7 = MEM_BU(ctx->r4, 0XA6B);
    // 0x800F1824: addu        $v1, $t0, $t6
    ctx->r3 = ADD32(ctx->r8, ctx->r14);
    // 0x800F1828: lbu         $t7, 0xEF($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XEF);
    // 0x800F182C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    // 0x800F1830: subu        $t9, $s0, $a3
    ctx->r25 = SUB32(ctx->r16, ctx->r7);
    // 0x800F1834: subu        $t8, $s0, $t7
    ctx->r24 = SUB32(ctx->r16, ctx->r15);
    // 0x800F1838: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F183C: addiu       $v1, $v1, 0xEC
    ctx->r3 = ADD32(ctx->r3, 0XEC);
    // 0x800F1840: mflo        $t6
    ctx->r14 = lo;
    // 0x800F1844: nop

    // 0x800F1848: nop

    // 0x800F184C: div         $zero, $t6, $s0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r16)));
    // 0x800F1850: mflo        $t1
    ctx->r9 = lo;
    // 0x800F1854: bne         $s0, $zero, L_800F1860
    if (ctx->r16 != 0) {
        // 0x800F1858: nop
    
            goto L_800F1860;
    }
    // 0x800F1858: nop

    // 0x800F185C: break       7
    do_break(2148472924);
L_800F1860:
    // 0x800F1860: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F1864: bne         $s0, $at, L_800F1878
    if (ctx->r16 != ctx->r1) {
        // 0x800F1868: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F1878;
    }
    // 0x800F1868: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F186C: bne         $t6, $at, L_800F1878
    if (ctx->r14 != ctx->r1) {
        // 0x800F1870: nop
    
            goto L_800F1878;
    }
    // 0x800F1870: nop

    // 0x800F1874: break       6
    do_break(2148472948);
L_800F1878:
    // 0x800F1878: bnel        $t1, $s0, L_800F1898
    if (ctx->r9 != ctx->r16) {
        // 0x800F187C: addiu       $a3, $a0, 0xA68
        ctx->r7 = ADD32(ctx->r4, 0XA68);
            goto L_800F1898;
    }
    goto skip_1;
    // 0x800F187C: addiu       $a3, $a0, 0xA68
    ctx->r7 = ADD32(ctx->r4, 0XA68);
    skip_1:
    // 0x800F1880: lbu         $v0, 0xA68($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA68);
    // 0x800F1884: lbu         $v1, 0xA69($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XA69);
    // 0x800F1888: lbu         $a1, 0xA6A($a0)
    ctx->r5 = MEM_BU(ctx->r4, 0XA6A);
    // 0x800F188C: b           L_800F1AB8
    // 0x800F1890: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
        goto L_800F1AB8;
    // 0x800F1890: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800F1894: addiu       $a3, $a0, 0xA68
    ctx->r7 = ADD32(ctx->r4, 0XA68);
L_800F1898:
    // 0x800F1898: lbu         $t7, 0x0($a3)
    ctx->r15 = MEM_BU(ctx->r7, 0X0);
    // 0x800F189C: lbu         $v1, 0xA90($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XA90);
    // 0x800F18A0: lbu         $t5, 0x3($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X3);
    // 0x800F18A4: subu        $t1, $s0, $t1
    ctx->r9 = SUB32(ctx->r16, ctx->r9);
    // 0x800F18A8: subu        $t8, $t7, $v1
    ctx->r24 = SUB32(ctx->r15, ctx->r3);
    // 0x800F18AC: multu       $t8, $t5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F18B0: mflo        $t9
    ctx->r25 = lo;
    // 0x800F18B4: nop

    // 0x800F18B8: nop

    // 0x800F18BC: div         $zero, $t9, $s0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r16)));
    // 0x800F18C0: mflo        $t6
    ctx->r14 = lo;
    // 0x800F18C4: addu        $t2, $t6, $v1
    ctx->r10 = ADD32(ctx->r14, ctx->r3);
    // 0x800F18C8: bne         $s0, $zero, L_800F18D4
    if (ctx->r16 != 0) {
        // 0x800F18CC: nop
    
            goto L_800F18D4;
    }
    // 0x800F18CC: nop

    // 0x800F18D0: break       7
    do_break(2148473040);
L_800F18D4:
    // 0x800F18D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F18D8: bne         $s0, $at, L_800F18EC
    if (ctx->r16 != ctx->r1) {
        // 0x800F18DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F18EC;
    }
    // 0x800F18DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F18E0: bne         $t9, $at, L_800F18EC
    if (ctx->r25 != ctx->r1) {
        // 0x800F18E4: nop
    
            goto L_800F18EC;
    }
    // 0x800F18E4: nop

    // 0x800F18E8: break       6
    do_break(2148473064);
L_800F18EC:
    // 0x800F18EC: multu       $t2, $s0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F18F0: mflo        $a1
    ctx->r5 = lo;
    // 0x800F18F4: nop

    // 0x800F18F8: nop

    // 0x800F18FC: div         $zero, $a1, $t1
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r9)));
    // 0x800F1900: mflo        $t3
    ctx->r11 = lo;
    // 0x800F1904: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x800F1908: bne         $t1, $zero, L_800F1914
    if (ctx->r9 != 0) {
        // 0x800F190C: nop
    
            goto L_800F1914;
    }
    // 0x800F190C: nop

    // 0x800F1910: break       7
    do_break(2148473104);
L_800F1914:
    // 0x800F1914: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F1918: bne         $t1, $at, L_800F192C
    if (ctx->r9 != ctx->r1) {
        // 0x800F191C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F192C;
    }
    // 0x800F191C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F1920: bne         $a1, $at, L_800F192C
    if (ctx->r5 != ctx->r1) {
        // 0x800F1924: nop
    
            goto L_800F192C;
    }
    // 0x800F1924: nop

    // 0x800F1928: break       6
    do_break(2148473128);
L_800F192C:
    // 0x800F192C: beql        $t3, $zero, L_800F196C
    if (ctx->r11 == 0) {
        // 0x800F1930: subu        $t7, $t1, $t2
        ctx->r15 = SUB32(ctx->r9, ctx->r10);
            goto L_800F196C;
    }
    goto skip_2;
    // 0x800F1930: subu        $t7, $t1, $t2
    ctx->r15 = SUB32(ctx->r9, ctx->r10);
    skip_2:
    // 0x800F1934: div         $zero, $a1, $t3
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r11)));
    // 0x800F1938: mflo        $a2
    ctx->r6 = lo;
    // 0x800F193C: bne         $t3, $zero, L_800F1948
    if (ctx->r11 != 0) {
        // 0x800F1940: nop
    
            goto L_800F1948;
    }
    // 0x800F1940: nop

    // 0x800F1944: break       7
    do_break(2148473156);
L_800F1948:
    // 0x800F1948: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F194C: bne         $t3, $at, L_800F1960
    if (ctx->r11 != ctx->r1) {
        // 0x800F1950: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F1960;
    }
    // 0x800F1950: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F1954: bne         $a1, $at, L_800F1960
    if (ctx->r5 != ctx->r1) {
        // 0x800F1958: nop
    
            goto L_800F1960;
    }
    // 0x800F1958: nop

    // 0x800F195C: break       6
    do_break(2148473180);
L_800F1960:
    // 0x800F1960: b           L_800F19AC
    // 0x800F1964: lbu         $t3, 0xA91($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA91);
        goto L_800F19AC;
    // 0x800F1964: lbu         $t3, 0xA91($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA91);
    // 0x800F1968: subu        $t7, $t1, $t2
    ctx->r15 = SUB32(ctx->r9, ctx->r10);
L_800F196C:
    // 0x800F196C: multu       $t7, $s0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F1970: mflo        $t8
    ctx->r24 = lo;
    // 0x800F1974: nop

    // 0x800F1978: nop

    // 0x800F197C: div         $zero, $t8, $s0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r16)));
    // 0x800F1980: mflo        $a2
    ctx->r6 = lo;
    // 0x800F1984: bne         $s0, $zero, L_800F1990
    if (ctx->r16 != 0) {
        // 0x800F1988: nop
    
            goto L_800F1990;
    }
    // 0x800F1988: nop

    // 0x800F198C: break       7
    do_break(2148473228);
L_800F1990:
    // 0x800F1990: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F1994: bne         $s0, $at, L_800F19A8
    if (ctx->r16 != ctx->r1) {
        // 0x800F1998: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F19A8;
    }
    // 0x800F1998: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F199C: bne         $t8, $at, L_800F19A8
    if (ctx->r24 != ctx->r1) {
        // 0x800F19A0: nop
    
            goto L_800F19A8;
    }
    // 0x800F19A0: nop

    // 0x800F19A4: break       6
    do_break(2148473252);
L_800F19A8:
    // 0x800F19A8: lbu         $t3, 0xA91($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0XA91);
L_800F19AC:
    // 0x800F19AC: lbu         $t9, 0x1($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X1);
    // 0x800F19B0: lbu         $t4, 0xA92($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0XA92);
    // 0x800F19B4: subu        $t6, $t9, $t3
    ctx->r14 = SUB32(ctx->r25, ctx->r11);
    // 0x800F19B8: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F19BC: lbu         $t6, 0x2($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X2);
    // 0x800F19C0: mflo        $t7
    ctx->r15 = lo;
    // 0x800F19C4: nop

    // 0x800F19C8: nop

    // 0x800F19CC: div         $zero, $t7, $s0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r16)));
    // 0x800F19D0: mflo        $t8
    ctx->r24 = lo;
    // 0x800F19D4: addu        $t2, $t8, $t3
    ctx->r10 = ADD32(ctx->r24, ctx->r11);
    // 0x800F19D8: bne         $s0, $zero, L_800F19E4
    if (ctx->r16 != 0) {
        // 0x800F19DC: nop
    
            goto L_800F19E4;
    }
    // 0x800F19DC: nop

    // 0x800F19E0: break       7
    do_break(2148473312);
L_800F19E4:
    // 0x800F19E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F19E8: bne         $s0, $at, L_800F19FC
    if (ctx->r16 != ctx->r1) {
        // 0x800F19EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F19FC;
    }
    // 0x800F19EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F19F0: bne         $t7, $at, L_800F19FC
    if (ctx->r15 != ctx->r1) {
        // 0x800F19F4: nop
    
            goto L_800F19FC;
    }
    // 0x800F19F4: nop

    // 0x800F19F8: break       6
    do_break(2148473336);
L_800F19FC:
    // 0x800F19FC: multu       $t2, $s0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F1A00: subu        $t7, $t6, $t4
    ctx->r15 = SUB32(ctx->r14, ctx->r12);
    // 0x800F1A04: mflo        $t9
    ctx->r25 = lo;
    // 0x800F1A08: nop

    // 0x800F1A0C: nop

    // 0x800F1A10: div         $zero, $t9, $t1
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r9)));
    // 0x800F1A14: mflo        $v1
    ctx->r3 = lo;
    // 0x800F1A18: bne         $t1, $zero, L_800F1A24
    if (ctx->r9 != 0) {
        // 0x800F1A1C: nop
    
            goto L_800F1A24;
    }
    // 0x800F1A1C: nop

    // 0x800F1A20: break       7
    do_break(2148473376);
L_800F1A24:
    // 0x800F1A24: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F1A28: bne         $t1, $at, L_800F1A3C
    if (ctx->r9 != ctx->r1) {
        // 0x800F1A2C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F1A3C;
    }
    // 0x800F1A2C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F1A30: bne         $t9, $at, L_800F1A3C
    if (ctx->r25 != ctx->r1) {
        // 0x800F1A34: nop
    
            goto L_800F1A3C;
    }
    // 0x800F1A34: nop

    // 0x800F1A38: break       6
    do_break(2148473400);
L_800F1A3C:
    // 0x800F1A3C: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F1A40: mflo        $t8
    ctx->r24 = lo;
    // 0x800F1A44: nop

    // 0x800F1A48: nop

    // 0x800F1A4C: div         $zero, $t8, $s0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r16)));
    // 0x800F1A50: mflo        $t9
    ctx->r25 = lo;
    // 0x800F1A54: addu        $t2, $t9, $t4
    ctx->r10 = ADD32(ctx->r25, ctx->r12);
    // 0x800F1A58: bne         $s0, $zero, L_800F1A64
    if (ctx->r16 != 0) {
        // 0x800F1A5C: nop
    
            goto L_800F1A64;
    }
    // 0x800F1A5C: nop

    // 0x800F1A60: break       7
    do_break(2148473440);
L_800F1A64:
    // 0x800F1A64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F1A68: bne         $s0, $at, L_800F1A7C
    if (ctx->r16 != ctx->r1) {
        // 0x800F1A6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F1A7C;
    }
    // 0x800F1A6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F1A70: bne         $t8, $at, L_800F1A7C
    if (ctx->r24 != ctx->r1) {
        // 0x800F1A74: nop
    
            goto L_800F1A7C;
    }
    // 0x800F1A74: nop

    // 0x800F1A78: break       6
    do_break(2148473464);
L_800F1A7C:
    // 0x800F1A7C: multu       $t2, $s0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F1A80: mflo        $t6
    ctx->r14 = lo;
    // 0x800F1A84: nop

    // 0x800F1A88: nop

    // 0x800F1A8C: div         $zero, $t6, $t1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r9)));
    // 0x800F1A90: mflo        $a1
    ctx->r5 = lo;
    // 0x800F1A94: bne         $t1, $zero, L_800F1AA0
    if (ctx->r9 != 0) {
        // 0x800F1A98: nop
    
            goto L_800F1AA0;
    }
    // 0x800F1A98: nop

    // 0x800F1A9C: break       7
    do_break(2148473500);
L_800F1AA0:
    // 0x800F1AA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F1AA4: bne         $t1, $at, L_800F1AB8
    if (ctx->r9 != ctx->r1) {
        // 0x800F1AA8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F1AB8;
    }
    // 0x800F1AA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F1AAC: bne         $t6, $at, L_800F1AB8
    if (ctx->r14 != ctx->r1) {
        // 0x800F1AB0: nop
    
            goto L_800F1AB8;
    }
    // 0x800F1AB0: nop

    // 0x800F1AB4: break       6
    do_break(2148473524);
L_800F1AB8:
    // 0x800F1AB8: lbu         $a0, 0xFC($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0XFC);
    // 0x800F1ABC: beq         $s0, $a0, L_800F1B00
    if (ctx->r16 == ctx->r4) {
        // 0x800F1AC0: nop
    
            goto L_800F1B00;
    }
    // 0x800F1AC0: nop

    // 0x800F1AC4: multu       $a0, $a2
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F1AC8: mflo        $t7
    ctx->r15 = lo;
    // 0x800F1ACC: nop

    // 0x800F1AD0: nop

    // 0x800F1AD4: div         $zero, $t7, $s0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r16)));
    // 0x800F1AD8: mflo        $a2
    ctx->r6 = lo;
    // 0x800F1ADC: bne         $s0, $zero, L_800F1AE8
    if (ctx->r16 != 0) {
        // 0x800F1AE0: nop
    
            goto L_800F1AE8;
    }
    // 0x800F1AE0: nop

    // 0x800F1AE4: break       7
    do_break(2148473572);
L_800F1AE8:
    // 0x800F1AE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F1AEC: bne         $s0, $at, L_800F1B00
    if (ctx->r16 != ctx->r1) {
        // 0x800F1AF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F1B00;
    }
    // 0x800F1AF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F1AF4: bne         $t7, $at, L_800F1B00
    if (ctx->r15 != ctx->r1) {
        // 0x800F1AF8: nop
    
            goto L_800F1B00;
    }
    // 0x800F1AF8: nop

    // 0x800F1AFC: break       6
    do_break(2148473596);
L_800F1B00:
    // 0x800F1B00: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F1B04: addiu       $a0, $a0, 0x12F4
    ctx->r4 = ADD32(ctx->r4, 0X12F4);
    // 0x800F1B08: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800F1B0C: sb          $v0, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r2;
    // 0x800F1B10: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
    // 0x800F1B14: sb          $a1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r5;
    // 0x800F1B18: sb          $a2, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r6;
    // 0x800F1B1C: jr          $ra
    // 0x800F1B20: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800F1B20: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void efManagerNessPKThunderTrailProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102630: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102634: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102638: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8010263C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80102640: lw          $t6, 0x18($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X18);
    // 0x80102644: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80102648: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8010264C: beql        $t7, $zero, L_80102670
    if (ctx->r15 == 0) {
        // 0x80102650: lw          $t8, 0x1C($a1)
        ctx->r24 = MEM_W(ctx->r5, 0X1C);
            goto L_80102670;
    }
    goto skip_0;
    // 0x80102650: lw          $t8, 0x1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1C);
    skip_0:
    // 0x80102654: jal         0x800FD4F8
    // 0x80102658: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_0;
    // 0x80102658: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8010265C: jal         0x80009A84
    // 0x80102660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80102660: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80102664: b           L_8010275C
    // 0x80102668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010275C;
    // 0x80102668: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010266C: lw          $t8, 0x1C($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X1C);
L_80102670:
    // 0x80102670: lw          $a0, 0x84($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X84);
    // 0x80102674: lw          $v1, 0xAE0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0XAE0);
    // 0x80102678: addiu       $v1, $v1, -0xA
    ctx->r3 = ADD32(ctx->r3, -0XA);
    // 0x8010267C: bgezl       $v1, L_8010268C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80102680: sll         $t9, $v1, 1
        ctx->r25 = S32(ctx->r3 << 1);
            goto L_8010268C;
    }
    goto skip_1;
    // 0x80102680: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    skip_1:
    // 0x80102684: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80102688: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
L_8010268C:
    // 0x8010268C: addu        $v0, $a0, $t9
    ctx->r2 = ADD32(ctx->r4, ctx->r25);
    // 0x80102690: lh          $t0, 0xAE4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0XAE4);
    // 0x80102694: lw          $t1, 0x74($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X74);
    // 0x80102698: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8010269C: nop

    // 0x801026A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801026A4: swc1        $f6, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f6.u32l;
    // 0x801026A8: lh          $t2, 0xAFC($v0)
    ctx->r10 = MEM_H(ctx->r2, 0XAFC);
    // 0x801026AC: lw          $t3, 0x74($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X74);
    // 0x801026B0: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x801026B4: nop

    // 0x801026B8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801026BC: blez        $v1, L_80102704
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801026C0: swc1        $f10, 0x20($t3)
        MEM_W(0X20, ctx->r11) = ctx->f10.u32l;
            goto L_80102704;
    }
    // 0x801026C0: swc1        $f10, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f10.u32l;
    // 0x801026C4: lh          $t4, 0xAFC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XAFC);
    // 0x801026C8: lh          $t5, 0xAFA($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XAFA);
    // 0x801026CC: lh          $t7, 0xAE4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XAE4);
    // 0x801026D0: lh          $t8, 0xAE2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XAE2);
    // 0x801026D4: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x801026D8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x801026DC: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x801026E0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x801026E4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801026E8: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801026EC: jal         0x8001863C
    // 0x801026F0: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    syUtilsArcTan2(rdram, ctx);
        goto after_2;
    // 0x801026F0: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    after_2:
    // 0x801026F4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801026F8: lw          $t0, 0x74($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X74);
    // 0x801026FC: b           L_80102740
    // 0x80102700: swc1        $f0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f0.u32l;
        goto L_80102740;
    // 0x80102700: swc1        $f0, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f0.u32l;
L_80102704:
    // 0x80102704: lh          $t1, 0xAFC($v0)
    ctx->r9 = MEM_H(ctx->r2, 0XAFC);
    // 0x80102708: lh          $t2, 0xB12($a0)
    ctx->r10 = MEM_H(ctx->r4, 0XB12);
    // 0x8010270C: lh          $t4, 0xAE4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XAE4);
    // 0x80102710: lh          $t5, 0xAFA($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XAFA);
    // 0x80102714: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80102718: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8010271C: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x80102720: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80102724: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80102728: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010272C: jal         0x8001863C
    // 0x80102730: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    syUtilsArcTan2(rdram, ctx);
        goto after_3;
    // 0x80102730: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_3:
    // 0x80102734: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80102738: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x8010273C: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
L_80102740:
    // 0x80102740: lw          $v0, 0x74($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X74);
    // 0x80102744: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80102748: lwc1        $f10, 0xA08($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XA08);
    // 0x8010274C: lwc1        $f8, 0x38($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80102750: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80102754: swc1        $f16, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f16.u32l;
    // 0x80102758: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010275C:
    // 0x8010275C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102760: jr          $ra
    // 0x80102764: nop

    return;
    // 0x80102764: nop

;}
RECOMP_FUNC void ifCommonBattleEndUpdateInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801146DC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801146E0: lw          $t9, 0x182C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X182C);
    // 0x801146E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801146E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801146EC: jalr        $t9
    // 0x801146F0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x801146F0: nop

    after_0:
    // 0x801146F4: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x801146F8: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x801146FC: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80114700: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80114704: sb          $t6, 0x11($t7)
    MEM_B(0X11, ctx->r15) = ctx->r14;
    // 0x80114708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8011470C: addiu       $v0, $v0, 0x185A
    ctx->r2 = ADD32(ctx->r2, 0X185A);
    // 0x80114710: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80114714: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80114718: sb          $zero, 0x1859($at)
    MEM_B(0X1859, ctx->r1) = 0;
    // 0x8011471C: jr          $ra
    // 0x80114720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80114720: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftCaptainSpecialHiThrowSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160730: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80160734: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80160738: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8016073C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80160740: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80160744: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80160748: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016074C: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    // 0x80160750: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80160754: jal         0x800E6F24
    // 0x80160758: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80160758: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8016075C: jal         0x800E0830
    // 0x80160760: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80160760: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80160764: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80160768: jal         0x800E8098
    // 0x8016076C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x8016076C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80160770: lw          $t7, 0x190($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X190);
    // 0x80160774: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80160778: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x8016077C: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80160780: bnel        $t9, $at, L_801607A0
    if (ctx->r25 != ctx->r1) {
        // 0x80160784: sw          $zero, 0x840($s0)
        MEM_W(0X840, ctx->r16) = 0;
            goto L_801607A0;
    }
    goto skip_0;
    // 0x80160784: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    skip_0:
    // 0x80160788: lw          $t0, 0x840($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X840);
    // 0x8016078C: beql        $t0, $zero, L_801607A0
    if (ctx->r8 == 0) {
        // 0x80160790: sw          $zero, 0x840($s0)
        MEM_W(0X840, ctx->r16) = 0;
            goto L_801607A0;
    }
    goto skip_1;
    // 0x80160790: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    skip_1:
    // 0x80160794: jal         0x8014ADB0
    // 0x80160798: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonThrownReleaseFighterLoseGrip(rdram, ctx);
        goto after_3;
    // 0x80160798: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8016079C: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
L_801607A0:
    // 0x801607A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801607A4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801607A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801607AC: jr          $ra
    // 0x801607B0: nop

    return;
    // 0x801607B0: nop

;}
RECOMP_FUNC void n_alLoadParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002A070: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002A074: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8002A078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002A07C: beq         $a1, $at, L_8002A1C0
    if (ctx->r5 == ctx->r1) {
        // 0x8002A080: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_8002A1C0;
    }
    // 0x8002A080: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8002A084: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002A088: bnel        $a1, $at, L_8002A224
    if (ctx->r5 != ctx->r1) {
        // 0x8002A08C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002A224;
    }
    goto skip_0;
    // 0x8002A08C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002A090: sw          $a2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r6;
    // 0x8002A094: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8002A098: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
    // 0x8002A09C: sw          $t6, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r14;
    // 0x8002A0A0: lbu         $v0, 0x8($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X8);
    // 0x8002A0A4: beql        $v0, $zero, L_8002A0C4
    if (ctx->r2 == 0) {
        // 0x8002A0A8: lw          $v0, 0x20($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X20);
            goto L_8002A0C4;
    }
    goto skip_1;
    // 0x8002A0A8: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    skip_1:
    // 0x8002A0AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002A0B0: beql        $v0, $a0, L_8002A180
    if (ctx->r2 == ctx->r4) {
        // 0x8002A0B4: lw          $v0, 0x20($a3)
        ctx->r2 = MEM_W(ctx->r7, 0X20);
            goto L_8002A180;
    }
    goto skip_2;
    // 0x8002A0B4: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    skip_2:
    // 0x8002A0B8: b           L_8002A224
    // 0x8002A0BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002A224;
    // 0x8002A0BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A0C0: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
L_8002A0C4:
    // 0x8002A0C4: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x8002A0C8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8002A0CC: div         $zero, $t7, $a1
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r5))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r5)));
    // 0x8002A0D0: mflo        $t8
    ctx->r24 = lo;
    // 0x8002A0D4: bne         $a1, $zero, L_8002A0E0
    if (ctx->r5 != 0) {
        // 0x8002A0D8: nop
    
            goto L_8002A0E0;
    }
    // 0x8002A0D8: nop

    // 0x8002A0DC: break       7
    do_break(2147655900);
L_8002A0E0:
    // 0x8002A0E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002A0E4: bne         $a1, $at, L_8002A0F8
    if (ctx->r5 != ctx->r1) {
        // 0x8002A0E8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002A0F8;
    }
    // 0x8002A0E8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002A0EC: bne         $t7, $at, L_8002A0F8
    if (ctx->r15 != ctx->r1) {
        // 0x8002A0F0: nop
    
            goto L_8002A0F8;
    }
    // 0x8002A0F0: nop

    // 0x8002A0F4: break       6
    do_break(2147655924);
L_8002A0F8:
    // 0x8002A0F8: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A0FC: mflo        $t9
    ctx->r25 = lo;
    // 0x8002A100: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8002A104: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    // 0x8002A108: lw          $a0, 0x10($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X10);
    // 0x8002A10C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x8002A110: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    // 0x8002A114: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8002A118: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002A11C: mflo        $t3
    ctx->r11 = lo;
    // 0x8002A120: sw          $t3, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r11;
    // 0x8002A124: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8002A128: beql        $v1, $zero, L_8002A170
    if (ctx->r3 == 0) {
        // 0x8002A12C: sw          $zero, 0x1C($a3)
        MEM_W(0X1C, ctx->r7) = 0;
            goto L_8002A170;
    }
    goto skip_3;
    // 0x8002A12C: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    skip_3:
    // 0x8002A130: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x8002A134: lw          $a1, 0x10($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X10);
    // 0x8002A138: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8002A13C: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x8002A140: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x8002A144: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8002A148: sw          $t6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r14;
    // 0x8002A14C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x8002A150: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8002A154: sw          $t8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r24;
    // 0x8002A158: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8002A15C: jal         0x80035740
    // 0x8002A160: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    alCopy(rdram, ctx);
        goto after_0;
    // 0x8002A160: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    after_0:
    // 0x8002A164: b           L_8002A224
    // 0x8002A168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8002A224;
    // 0x8002A168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002A16C: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_8002A170:
    // 0x8002A170: sw          $zero, 0x18($a3)
    MEM_W(0X18, ctx->r7) = 0;
    // 0x8002A174: b           L_8002A220
    // 0x8002A178: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
        goto L_8002A220;
    // 0x8002A178: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
    // 0x8002A17C: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
L_8002A180:
    // 0x8002A180: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8002A184: beql        $v1, $zero, L_8002A1B4
    if (ctx->r3 == 0) {
        // 0x8002A188: sw          $zero, 0x1C($a3)
        MEM_W(0X1C, ctx->r7) = 0;
            goto L_8002A1B4;
    }
    goto skip_4;
    // 0x8002A188: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    skip_4:
    // 0x8002A18C: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8002A190: sw          $t9, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r25;
    // 0x8002A194: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x8002A198: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8002A19C: sw          $t1, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r9;
    // 0x8002A1A0: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x8002A1A4: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x8002A1A8: b           L_8002A220
    // 0x8002A1AC: sw          $t3, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r11;
        goto L_8002A220;
    // 0x8002A1AC: sw          $t3, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r11;
    // 0x8002A1B0: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
L_8002A1B4:
    // 0x8002A1B4: sw          $zero, 0x18($a3)
    MEM_W(0X18, ctx->r7) = 0;
    // 0x8002A1B8: b           L_8002A220
    // 0x8002A1BC: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
        goto L_8002A220;
    // 0x8002A1BC: sw          $zero, 0x14($a3)
    MEM_W(0X14, ctx->r7) = 0;
L_8002A1C0:
    // 0x8002A1C0: lw          $v0, 0x20($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X20);
    // 0x8002A1C4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8002A1C8: sw          $zero, 0x34($a3)
    MEM_W(0X34, ctx->r7) = 0;
    // 0x8002A1CC: sw          $a0, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->r4;
    // 0x8002A1D0: beq         $v0, $zero, L_8002A220
    if (ctx->r2 == 0) {
        // 0x8002A1D4: sw          $zero, 0x30($a3)
        MEM_W(0X30, ctx->r7) = 0;
            goto L_8002A220;
    }
    // 0x8002A1D4: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x8002A1D8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8002A1DC: sw          $t4, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->r12;
    // 0x8002A1E0: lbu         $v1, 0x8($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X8);
    // 0x8002A1E4: bne         $v1, $zero, L_8002A204
    if (ctx->r3 != 0) {
        // 0x8002A1E8: nop
    
            goto L_8002A204;
    }
    // 0x8002A1E8: nop

    // 0x8002A1EC: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8002A1F0: beql        $v1, $zero, L_8002A224
    if (ctx->r3 == 0) {
        // 0x8002A1F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002A224;
    }
    goto skip_5;
    // 0x8002A1F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x8002A1F8: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x8002A1FC: b           L_8002A220
    // 0x8002A200: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
        goto L_8002A220;
    // 0x8002A200: sw          $t5, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r13;
L_8002A204:
    // 0x8002A204: bnel        $a0, $v1, L_8002A224
    if (ctx->r4 != ctx->r3) {
        // 0x8002A208: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002A224;
    }
    goto skip_6;
    // 0x8002A208: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x8002A20C: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x8002A210: beql        $v1, $zero, L_8002A224
    if (ctx->r3 == 0) {
        // 0x8002A214: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002A224;
    }
    goto skip_7;
    // 0x8002A214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x8002A218: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8002A21C: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
L_8002A220:
    // 0x8002A220: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002A224:
    // 0x8002A224: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002A228: jr          $ra
    // 0x8002A22C: nop

    return;
    // 0x8002A22C: nop

;}
RECOMP_FUNC void ftCommonSquatWaitCheckInterruptLanding(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143354: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80143358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014335C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80143360: lb          $t6, 0x1C3($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C3);
    // 0x80143364: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80143368: slti        $at, $t6, -0x36
    ctx->r1 = SIGNED(ctx->r14) < -0X36 ? 1 : 0;
    // 0x8014336C: beq         $at, $zero, L_80143384
    if (ctx->r1 == 0) {
        // 0x80143370: nop
    
            goto L_80143384;
    }
    // 0x80143370: nop

    // 0x80143374: jal         0x801432F0
    // 0x80143378: nop

    ftCommonSquatWaitSetStatusNoPass(rdram, ctx);
        goto after_0;
    // 0x80143378: nop

    after_0:
    // 0x8014337C: b           L_80143384
    // 0x80143380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80143384;
    // 0x80143380: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80143384:
    // 0x80143384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80143388: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014338C: jr          $ra
    // 0x80143390: nop

    return;
    // 0x80143390: nop

;}
RECOMP_FUNC void mpCollisionCheckLWallLineCollisionSame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F7F00: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x800F7F04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F7F08: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F7F0C: sw          $ra, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r31;
    // 0x800F7F10: sw          $fp, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r30;
    // 0x800F7F14: sw          $s7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r23;
    // 0x800F7F18: sw          $s6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r22;
    // 0x800F7F1C: sw          $s5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r21;
    // 0x800F7F20: sw          $s4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r20;
    // 0x800F7F24: sw          $s3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r19;
    // 0x800F7F28: sw          $s2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r18;
    // 0x800F7F2C: sw          $s1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r17;
    // 0x800F7F30: sw          $s0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r16;
    // 0x800F7F34: sdc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X58, ctx->r29);
    // 0x800F7F38: sdc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X50, ctx->r29);
    // 0x800F7F3C: sdc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X48, ctx->r29);
    // 0x800F7F40: sdc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X40, ctx->r29);
    // 0x800F7F44: sdc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X38, ctx->r29);
    // 0x800F7F48: sdc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X30, ctx->r29);
    // 0x800F7F4C: sw          $a0, 0x100($sp)
    MEM_W(0X100, ctx->r29) = ctx->r4;
    // 0x800F7F50: sw          $a1, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r5;
    // 0x800F7F54: sw          $a3, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r7;
    // 0x800F7F58: lw          $t4, 0x10($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X10);
    // 0x800F7F5C: sw          $zero, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = 0;
    // 0x800F7F60: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F7F64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F7F68: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800F7F6C: blez        $t0, L_800F84E4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F7F70: lwc1        $f22, 0x890($at)
        ctx->f22.u32l = MEM_W(ctx->r1, 0X890);
            goto L_800F84E4;
    }
    // 0x800F7F70: lwc1        $f22, 0x890($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X890);
    // 0x800F7F74: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F7F78: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F7F7C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x800F7F80: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F7F84: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F7F88: lw          $fp, 0x110($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X110);
    // 0x800F7F8C: lw          $s6, 0x114($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X114);
    // 0x800F7F90: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F7F94:
    // 0x800F7F94: addiu       $a0, $t4, 0xE
    ctx->r4 = ADD32(ctx->r12, 0XE);
    // 0x800F7F98: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x800F7F9C: lhu         $t7, 0x0($t4)
    ctx->r15 = MEM_HU(ctx->r12, 0X0);
    // 0x800F7FA0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F7FA4: lw          $t6, 0x1304($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1304);
    // 0x800F7FA8: lhu         $t5, 0x10($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X10);
    // 0x800F7FAC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800F7FB0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800F7FB4: beq         $t5, $zero, L_800F84CC
    if (ctx->r13 == 0) {
        // 0x800F7FB8: lw          $v0, 0x0($t9)
        ctx->r2 = MEM_W(ctx->r25, 0X0);
            goto L_800F84CC;
    }
    // 0x800F7FB8: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x800F7FBC: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800F7FC0: lw          $t7, 0x100($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X100);
    // 0x800F7FC4: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800F7FC8: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F7FCC: beql        $at, $zero, L_800F84D0
    if (ctx->r1 == 0) {
        // 0x800F7FD0: lw          $t8, 0xF0($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XF0);
            goto L_800F84D0;
    }
    goto skip_0;
    // 0x800F7FD0: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
    skip_0:
    // 0x800F7FD4: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800F7FD8: lwc1        $f0, 0x0($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800F7FDC: lwc1        $f2, 0x4($t7)
    ctx->f2.u32l = MEM_W(ctx->r15, 0X4);
    // 0x800F7FE0: lwc1        $f12, 0x0($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800F7FE4: bne         $t8, $zero, L_800F7FF4
    if (ctx->r24 != 0) {
        // 0x800F7FE8: lwc1        $f14, 0x4($t6)
        ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
            goto L_800F7FF4;
    }
    // 0x800F7FE8: lwc1        $f14, 0x4($t6)
    ctx->f14.u32l = MEM_W(ctx->r14, 0X4);
    // 0x800F7FEC: beql        $v1, $zero, L_800F801C
    if (ctx->r3 == 0) {
        // 0x800F7FF0: mov.s       $f30, $f24
        CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
            goto L_800F801C;
    }
    goto skip_1;
    // 0x800F7FF0: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
    skip_1:
L_800F7FF4:
    // 0x800F7FF4: lwc1        $f30, 0x20($v0)
    ctx->f30.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F7FF8: lwc1        $f28, 0x1C($v0)
    ctx->f28.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800F7FFC: sub.s       $f4, $f2, $f30
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f30.fl;
    // 0x800F8000: sub.s       $f6, $f14, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f30.fl;
    // 0x800F8004: swc1        $f4, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f4.u32l;
    // 0x800F8008: sub.s       $f20, $f0, $f28
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f28.fl;
    // 0x800F800C: swc1        $f6, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f6.u32l;
    // 0x800F8010: b           L_800F8030
    // 0x800F8014: sub.s       $f26, $f12, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f12.fl - ctx->f28.fl;
        goto L_800F8030;
    // 0x800F8014: sub.s       $f26, $f12, $f28
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f26.fl = ctx->f12.fl - ctx->f28.fl;
    // 0x800F8018: mov.s       $f30, $f24
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 24);
    ctx->f30.fl = ctx->f24.fl;
L_800F801C:
    // 0x800F801C: mov.s       $f28, $f24
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 24);
    ctx->f28.fl = ctx->f24.fl;
    // 0x800F8020: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800F8024: swc1        $f2, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f2.u32l;
    // 0x800F8028: mov.s       $f26, $f12
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    ctx->f26.fl = ctx->f12.fl;
    // 0x800F802C: swc1        $f14, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f14.u32l;
L_800F8030:
    // 0x800F8030: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800F8034: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8038: bc1f        L_800F8064
    if (!c1cs) {
        // 0x800F803C: nop
    
            goto L_800F8064;
    }
    // 0x800F803C: nop

    // 0x800F8040: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F8044: lwc1        $f8, 0x894($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X894);
    // 0x800F8048: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F804C: lwc1        $f16, 0x898($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X898);
    // 0x800F8050: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x800F8054: add.s       $f18, $f26, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f26.fl + ctx->f16.fl;
    // 0x800F8058: swc1        $f10, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f10.u32l;
    // 0x800F805C: b           L_800F8080
    // 0x800F8060: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
        goto L_800F8080;
    // 0x800F8060: swc1        $f18, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f18.u32l;
L_800F8064:
    // 0x800F8064: lwc1        $f4, 0x89C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X89C);
    // 0x800F8068: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F806C: lwc1        $f8, 0x8A0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X8A0);
    // 0x800F8070: sub.s       $f6, $f26, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x800F8074: add.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f8.fl;
    // 0x800F8078: swc1        $f6, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f6.u32l;
    // 0x800F807C: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
L_800F8080:
    // 0x800F8080: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F8084: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
    // 0x800F8088: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x800F808C: sll         $a0, $v0, 2
    ctx->r4 = S32(ctx->r2 << 2);
    // 0x800F8090: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800F8094: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x800F8098: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800F809C: beq         $at, $zero, L_800F84C8
    if (ctx->r1 == 0) {
        // 0x800F80A0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800F84C8;
    }
    // 0x800F80A0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800F80A4: sll         $a0, $a0, 1
    ctx->r4 = S32(ctx->r4 << 1);
    // 0x800F80A8: sw          $t4, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->r12;
L_800F80AC:
    // 0x800F80AC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F80B0: lw          $t7, 0x136C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X136C);
    // 0x800F80B4: lwc1        $f4, 0xEC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800F80B8: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x800F80BC: addu        $v0, $t7, $a0
    ctx->r2 = ADD32(ctx->r15, ctx->r4);
    // 0x800F80C0: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x800F80C4: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800F80C8: nop

    // 0x800F80CC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F80D0: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x800F80D4: nop

    // 0x800F80D8: bc1fl       L_800F80F4
    if (!c1cs) {
        // 0x800F80DC: sw          $v1, 0xC8($sp)
        MEM_W(0XC8, ctx->r29) = ctx->r3;
            goto L_800F80F4;
    }
    goto skip_2;
    // 0x800F80DC: sw          $v1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r3;
    skip_2:
    // 0x800F80E0: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800F80E4: lhu         $t5, 0x2($t8)
    ctx->r13 = MEM_HU(ctx->r24, 0X2);
    // 0x800F80E8: b           L_800F84AC
    // 0x800F80EC: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
        goto L_800F84AC;
    // 0x800F80EC: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
    // 0x800F80F0: sw          $v1, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r3;
L_800F80F4:
    // 0x800F80F4: sw          $a0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r4;
    // 0x800F80F8: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800F80FC: lwc1        $f6, 0xE8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800F8100: lw          $s7, 0xC8($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XC8);
    // 0x800F8104: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800F8108: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F810C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F8110: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x800F8114: nop

    // 0x800F8118: bc1f        L_800F8130
    if (!c1cs) {
        // 0x800F811C: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800F8130;
    }
    // 0x800F811C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F8120: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800F8124: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
    // 0x800F8128: b           L_800F84CC
    // 0x800F812C: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
        goto L_800F84CC;
    // 0x800F812C: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
L_800F8130:
    // 0x800F8130: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F8134: sll         $s7, $s7, 2
    ctx->r23 = S32(ctx->r23 << 2);
    // 0x800F8138: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800F813C: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F8140: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800F8144: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F8148: sll         $s2, $v1, 1
    ctx->r18 = S32(ctx->r3 << 1);
    // 0x800F814C: addu        $t7, $t5, $s2
    ctx->r15 = ADD32(ctx->r13, ctx->r18);
    // 0x800F8150: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x800F8154: lhu         $t5, 0x2($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X2);
    // 0x800F8158: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F815C: addu        $t7, $t5, $v1
    ctx->r15 = ADD32(ctx->r13, ctx->r3);
    // 0x800F8160: addiu       $t6, $t7, -0x1
    ctx->r14 = ADD32(ctx->r15, -0X1);
    // 0x800F8164: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800F8168: mflo        $t8
    ctx->r24 = lo;
    // 0x800F816C: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    // 0x800F8170: lh          $s3, 0x0($a0)
    ctx->r19 = MEM_H(ctx->r4, 0X0);
    // 0x800F8174: beq         $at, $zero, L_800F8494
    if (ctx->r1 == 0) {
        // 0x800F8178: lh          $s4, 0x2($a0)
        ctx->r20 = MEM_H(ctx->r4, 0X2);
            goto L_800F8494;
    }
    // 0x800F8178: lh          $s4, 0x2($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X2);
    // 0x800F817C: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
L_800F8180:
    // 0x800F8180: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800F8184: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x800F8188: addu        $t5, $t8, $s2
    ctx->r13 = ADD32(ctx->r24, ctx->r18);
    // 0x800F818C: lhu         $t7, 0x2($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X2);
    // 0x800F8190: or          $s1, $s4, $zero
    ctx->r17 = ctx->r20 | 0;
    // 0x800F8194: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F8198: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F819C: addiu       $t5, $sp, 0xAC
    ctx->r13 = ADD32(ctx->r29, 0XAC);
    // 0x800F81A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F81A4: mflo        $t6
    ctx->r14 = lo;
    // 0x800F81A8: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800F81AC: lh          $s3, 0x0($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X0);
    // 0x800F81B0: lh          $s4, 0x2($v0)
    ctx->r20 = MEM_H(ctx->r2, 0X2);
    // 0x800F81B4: addiu       $t6, $sp, 0xB0
    ctx->r14 = ADD32(ctx->r29, 0XB0);
    // 0x800F81B8: bne         $s0, $s3, L_800F8310
    if (ctx->r16 != ctx->r19) {
        // 0x800F81BC: or          $a2, $s3, $zero
        ctx->r6 = ctx->r19 | 0;
            goto L_800F8310;
    }
    // 0x800F81BC: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x800F81C0: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800F81C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F81C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F81CC: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800F81D0: bc1f        L_800F8464
    if (!c1cs) {
        // 0x800F81D4: lwc1        $f16, 0xE0($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0XE0);
            goto L_800F8464;
    }
    // 0x800F81D4: lwc1        $f16, 0xE0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800F81D8: lwc1        $f18, 0xD8($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F81DC: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x800F81E0: addiu       $t8, $sp, 0xB0
    ctx->r24 = ADD32(ctx->r29, 0XB0);
    // 0x800F81E4: addiu       $t5, $sp, 0xAC
    ctx->r13 = ADD32(ctx->r29, 0XAC);
    // 0x800F81E8: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x800F81EC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800F81F0: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x800F81F4: swc1        $f26, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f26.u32l;
    // 0x800F81F8: jal         0x800F7D24
    // 0x800F81FC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    mpCollisionCheckLRSurfaceFlat(rdram, ctx);
        goto after_0;
    // 0x800F81FC: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x800F8200: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F8204: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F8208: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F820C: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F8210: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F8214: lw          $t0, 0x10C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10C);
    // 0x800F8218: bne         $v0, $at, L_800F8464
    if (ctx->r2 != ctx->r1) {
        // 0x800F821C: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F8464;
    }
    // 0x800F821C: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F8220: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F8224: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F8228: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F822C: c.lt.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl < ctx->f20.fl;
    // 0x800F8230: nop

    // 0x800F8234: bc1fl       L_800F824C
    if (!c1cs) {
        // 0x800F8238: sub.s       $f0, $f8, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f20.fl;
            goto L_800F824C;
    }
    goto skip_3;
    // 0x800F8238: sub.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f20.fl;
    skip_3:
    // 0x800F823C: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800F8240: b           L_800F824C
    // 0x800F8244: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F824C;
    // 0x800F8244: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F8248: sub.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f20.fl;
L_800F824C:
    // 0x800F824C: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F8250: nop

    // 0x800F8254: bc1f        L_800F827C
    if (!c1cs) {
        // 0x800F8258: nop
    
            goto L_800F827C;
    }
    // 0x800F8258: nop

    // 0x800F825C: lw          $t7, 0x1378($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1378);
    // 0x800F8260: addu        $v0, $t7, $s7
    ctx->r2 = ADD32(ctx->r15, ctx->r23);
    // 0x800F8264: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800F8268: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800F826C: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x800F8270: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F8274: b           L_800F8484
    // 0x800F8278: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F8484;
    // 0x800F8278: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F827C:
    // 0x800F827C: beq         $s5, $zero, L_800F829C
    if (ctx->r21 == 0) {
        // 0x800F8280: lwc1        $f6, 0xB0($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F829C;
    }
    // 0x800F8280: lwc1        $f6, 0xB0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F8284: add.s       $f10, $f6, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f28.fl;
    // 0x800F8288: swc1        $f10, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f10.u32l;
    // 0x800F828C: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F8290: swc1        $f24, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f24.u32l;
    // 0x800F8294: add.s       $f18, $f16, $f30
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f30.fl;
    // 0x800F8298: swc1        $f18, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f18.u32l;
L_800F829C:
    // 0x800F829C: beq         $t0, $zero, L_800F82A8
    if (ctx->r8 == 0) {
        // 0x800F82A0: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_800F82A8;
    }
    // 0x800F82A0: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x800F82A4: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
L_800F82A8:
    // 0x800F82A8: beq         $s6, $zero, L_800F82C0
    if (ctx->r22 == 0) {
        // 0x800F82AC: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_800F82C0;
    }
    // 0x800F82AC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800F82B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800F82B4: swc1        $f24, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->f24.u32l;
    // 0x800F82B8: swc1        $f24, 0x4($s6)
    MEM_W(0X4, ctx->r22) = ctx->f24.u32l;
    // 0x800F82BC: swc1        $f4, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f4.u32l;
L_800F82C0:
    // 0x800F82C0: beql        $fp, $zero, L_800F82F0
    if (ctx->r30 == 0) {
        // 0x800F82C4: lwc1        $f8, 0xB0($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F82F0;
    }
    goto skip_4;
    // 0x800F82C4: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    skip_4:
    // 0x800F82C8: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F82CC: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800F82D0: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800F82D4: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800F82D8: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F82DC: mflo        $t8
    ctx->r24 = lo;
    // 0x800F82E0: addu        $t7, $t5, $t8
    ctx->r15 = ADD32(ctx->r13, ctx->r24);
    // 0x800F82E4: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x800F82E8: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x800F82EC: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
L_800F82F0:
    // 0x800F82F0: c.lt.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl < ctx->f20.fl;
    // 0x800F82F4: sub.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x800F82F8: bc1f        L_800F8308
    if (!c1cs) {
        // 0x800F82FC: nop
    
            goto L_800F8308;
    }
    // 0x800F82FC: nop

    // 0x800F8300: b           L_800F8464
    // 0x800F8304: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F8464;
    // 0x800F8304: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
L_800F8308:
    // 0x800F8308: b           L_800F8464
    // 0x800F830C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
        goto L_800F8464;
    // 0x800F830C: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F8310:
    // 0x800F8310: lwc1        $f6, 0xE0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800F8314: lwc1        $f10, 0xD8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD8);
    // 0x800F8318: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x800F831C: swc1        $f20, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f20.u32l;
    // 0x800F8320: swc1        $f26, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f26.u32l;
    // 0x800F8324: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800F8328: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800F832C: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800F8330: jal         0x800F8548
    // 0x800F8334: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    mpCollisionCheckLWallSurfaceTilt(rdram, ctx);
        goto after_1;
    // 0x800F8334: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800F8338: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F833C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F8340: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F8344: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F8348: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F834C: lw          $t0, 0x10C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X10C);
    // 0x800F8350: bne         $v0, $at, L_800F8464
    if (ctx->r2 != ctx->r1) {
        // 0x800F8354: addiu       $t3, $zero, 0x6
        ctx->r11 = ADD32(0, 0X6);
            goto L_800F8464;
    }
    // 0x800F8354: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
    // 0x800F8358: lwc1        $f16, 0xB0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F835C: lwc1        $f18, 0xB0($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F8360: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F8364: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x800F8368: nop

    // 0x800F836C: bc1fl       L_800F8384
    if (!c1cs) {
        // 0x800F8370: sub.s       $f0, $f18, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f20.fl;
            goto L_800F8384;
    }
    goto skip_5;
    // 0x800F8370: sub.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f20.fl;
    skip_5:
    // 0x800F8374: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x800F8378: b           L_800F8384
    // 0x800F837C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_800F8384;
    // 0x800F837C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800F8380: sub.s       $f0, $f18, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f20.fl;
L_800F8384:
    // 0x800F8384: c.le.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl <= ctx->f0.fl;
    // 0x800F8388: nop

    // 0x800F838C: bc1f        L_800F83B4
    if (!c1cs) {
        // 0x800F8390: nop
    
            goto L_800F83B4;
    }
    // 0x800F8390: nop

    // 0x800F8394: lw          $t8, 0x1378($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1378);
    // 0x800F8398: addu        $v0, $t8, $s7
    ctx->r2 = ADD32(ctx->r24, ctx->r23);
    // 0x800F839C: lhu         $t7, 0x2($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X2);
    // 0x800F83A0: lhu         $t9, 0x0($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X0);
    // 0x800F83A4: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x800F83A8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F83AC: b           L_800F8484
    // 0x800F83B0: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
        goto L_800F8484;
    // 0x800F83B0: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F83B4:
    // 0x800F83B4: beq         $s5, $zero, L_800F83D4
    if (ctx->r21 == 0) {
        // 0x800F83B8: lwc1        $f4, 0xB0($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F83D4;
    }
    // 0x800F83B8: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F83BC: add.s       $f8, $f4, $f28
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f28.fl;
    // 0x800F83C0: swc1        $f8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f8.u32l;
    // 0x800F83C4: lwc1        $f6, 0xAC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F83C8: swc1        $f24, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->f24.u32l;
    // 0x800F83CC: add.s       $f10, $f6, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f30.fl;
    // 0x800F83D0: swc1        $f10, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->f10.u32l;
L_800F83D4:
    // 0x800F83D4: beq         $t0, $zero, L_800F83E0
    if (ctx->r8 == 0) {
        // 0x800F83D8: lw          $t6, 0xC8($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XC8);
            goto L_800F83E0;
    }
    // 0x800F83D8: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800F83DC: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
L_800F83E0:
    // 0x800F83E0: beq         $s6, $zero, L_800F8418
    if (ctx->r22 == 0) {
        // 0x800F83E4: or          $a0, $s6, $zero
        ctx->r4 = ctx->r22 | 0;
            goto L_800F8418;
    }
    // 0x800F83E4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800F83E8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800F83EC: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800F83F0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F83F4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800F83F8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800F83FC: jal         0x800F71A0
    // 0x800F8400: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRAngle(rdram, ctx);
        goto after_2;
    // 0x800F8400: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800F8404: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F8408: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F840C: addiu       $t2, $t2, 0x1374
    ctx->r10 = ADD32(ctx->r10, 0X1374);
    // 0x800F8410: addiu       $t1, $t1, 0x1370
    ctx->r9 = ADD32(ctx->r9, 0X1370);
    // 0x800F8414: addiu       $t3, $zero, 0x6
    ctx->r11 = ADD32(0, 0X6);
L_800F8418:
    // 0x800F8418: beql        $fp, $zero, L_800F8448
    if (ctx->r30 == 0) {
        // 0x800F841C: lwc1        $f16, 0xB0($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
            goto L_800F8448;
    }
    goto skip_6;
    // 0x800F841C: lwc1        $f16, 0xB0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
    skip_6:
    // 0x800F8420: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800F8424: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800F8428: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x800F842C: lhu         $t6, 0x0($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X0);
    // 0x800F8430: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F8434: mflo        $t5
    ctx->r13 = lo;
    // 0x800F8438: addu        $t7, $t8, $t5
    ctx->r15 = ADD32(ctx->r24, ctx->r13);
    // 0x800F843C: lhu         $t9, 0x4($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X4);
    // 0x800F8440: sw          $t9, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r25;
    // 0x800F8444: lwc1        $f16, 0xB0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XB0);
L_800F8448:
    // 0x800F8448: c.lt.s      $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f16.fl < ctx->f20.fl;
    // 0x800F844C: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x800F8450: bc1fl       L_800F8464
    if (!c1cs) {
        // 0x800F8454: mov.s       $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
            goto L_800F8464;
    }
    goto skip_7;
    // 0x800F8454: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    skip_7:
    // 0x800F8458: b           L_800F8464
    // 0x800F845C: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
        goto L_800F8464;
    // 0x800F845C: neg.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = -ctx->f0.fl;
    // 0x800F8460: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_800F8464:
    // 0x800F8464: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F8468: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800F846C: addu        $v0, $t6, $s7
    ctx->r2 = ADD32(ctx->r14, ctx->r23);
    // 0x800F8470: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x800F8474: lhu         $t5, 0x0($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X0);
    // 0x800F8478: addu        $v1, $t8, $t5
    ctx->r3 = ADD32(ctx->r24, ctx->r13);
    // 0x800F847C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800F8480: sll         $a0, $v1, 1
    ctx->r4 = S32(ctx->r3 << 1);
L_800F8484:
    // 0x800F8484: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x800F8488: slt         $at, $s2, $a0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800F848C: bnel        $at, $zero, L_800F8180
    if (ctx->r1 != 0) {
        // 0x800F8490: lw          $t8, 0x0($t2)
        ctx->r24 = MEM_W(ctx->r10, 0X0);
            goto L_800F8180;
    }
    goto skip_8;
    // 0x800F8490: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    skip_8:
L_800F8494:
    // 0x800F8494: lw          $v1, 0xF8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF8);
    // 0x800F8498: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800F849C: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x800F84A0: lhu         $t9, 0x2($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X2);
    // 0x800F84A4: lw          $v1, 0xC8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC8);
    // 0x800F84A8: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
L_800F84AC:
    // 0x800F84AC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800F84B0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800F84B4: bne         $at, $zero, L_800F80AC
    if (ctx->r1 != 0) {
        // 0x800F84B8: addiu       $a0, $a0, 0xA
        ctx->r4 = ADD32(ctx->r4, 0XA);
            goto L_800F80AC;
    }
    // 0x800F84B8: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x800F84BC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F84C0: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800F84C4: lhu         $t0, 0x0($t6)
    ctx->r8 = MEM_HU(ctx->r14, 0X0);
L_800F84C8:
    // 0x800F84C8: lw          $t4, 0xFC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XFC);
L_800F84CC:
    // 0x800F84CC: lw          $t8, 0xF0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF0);
L_800F84D0:
    // 0x800F84D0: addiu       $t4, $t4, 0x12
    ctx->r12 = ADD32(ctx->r12, 0X12);
    // 0x800F84D4: addiu       $t5, $t8, 0x1
    ctx->r13 = ADD32(ctx->r24, 0X1);
    // 0x800F84D8: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F84DC: bne         $at, $zero, L_800F7F94
    if (ctx->r1 != 0) {
        // 0x800F84E0: sw          $t5, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->r13;
            goto L_800F7F94;
    }
    // 0x800F84E0: sw          $t5, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r13;
L_800F84E4:
    // 0x800F84E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F84E8: lwc1        $f18, 0x8A4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X8A4);
    // 0x800F84EC: ldc1        $f20, 0x30($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X30);
    // 0x800F84F0: ldc1        $f24, 0x40($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X40);
    // 0x800F84F4: c.eq.s      $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f22.fl == ctx->f18.fl;
    // 0x800F84F8: ldc1        $f22, 0x38($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X38);
    // 0x800F84FC: ldc1        $f26, 0x48($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X48);
    // 0x800F8500: ldc1        $f28, 0x50($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X50);
    // 0x800F8504: bc1f        L_800F8514
    if (!c1cs) {
        // 0x800F8508: ldc1        $f30, 0x58($sp)
        CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
            goto L_800F8514;
    }
    // 0x800F8508: ldc1        $f30, 0x58($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X58);
    // 0x800F850C: b           L_800F8518
    // 0x800F8510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F8518;
    // 0x800F8510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F8514:
    // 0x800F8514: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F8518:
    // 0x800F8518: lw          $ra, 0x84($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X84);
    // 0x800F851C: lw          $s0, 0x60($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X60);
    // 0x800F8520: lw          $s1, 0x64($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X64);
    // 0x800F8524: lw          $s2, 0x68($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X68);
    // 0x800F8528: lw          $s3, 0x6C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X6C);
    // 0x800F852C: lw          $s4, 0x70($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X70);
    // 0x800F8530: lw          $s5, 0x74($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X74);
    // 0x800F8534: lw          $s6, 0x78($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X78);
    // 0x800F8538: lw          $s7, 0x7C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X7C);
    // 0x800F853C: lw          $fp, 0x80($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X80);
    // 0x800F8540: jr          $ra
    // 0x800F8544: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x800F8544: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void sySchedulerCheckReadyFramebuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000A34: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80000A38: addiu       $a3, $a3, 0x4F9C
    ctx->r7 = ADD32(ctx->r7, 0X4F9C);
    // 0x80000A3C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80000A40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80000A44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000A48: beq         $t6, $zero, L_80000A58
    if (ctx->r14 == 0) {
        // 0x80000A4C: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80000A58;
    }
    // 0x80000A4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80000A50: b           L_80000B44
    // 0x80000A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80000B44;
    // 0x80000A54: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80000A58:
    // 0x80000A58: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80000A5C: lw          $t7, 0x4FA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4FA0);
    // 0x80000A60: beq         $t7, $zero, L_80000A70
    if (ctx->r15 == 0) {
        // 0x80000A64: nop
    
            goto L_80000A70;
    }
    // 0x80000A64: nop

    // 0x80000A68: b           L_80000B44
    // 0x80000A6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80000B44;
    // 0x80000A6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80000A70:
    // 0x80000A70: jal         0x80032690
    // 0x80000A74: nop

    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x80000A74: nop

    after_0:
    // 0x80000A78: jal         0x80039630
    // 0x80000A7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80000A7C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80000A80: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80000A84: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80000A88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80000A8C: lw          $v1, 0x70($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X70);
    // 0x80000A90: addiu       $a3, $a3, 0x4F9C
    ctx->r7 = ADD32(ctx->r7, 0X4F9C);
    // 0x80000A94: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80000A98: beq         $v1, $at, L_80000AE8
    if (ctx->r3 == ctx->r1) {
        // 0x80000A9C: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80000AE8;
    }
    // 0x80000A9C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80000AA0: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000AA4: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80000AA8: lw          $a0, 0x4F90($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4F90);
    // 0x80000AAC: beq         $a0, $zero, L_80000AE8
    if (ctx->r4 == 0) {
        // 0x80000AB0: nop
    
            goto L_80000AE8;
    }
    // 0x80000AB0: nop

    // 0x80000AB4: beq         $v0, $a0, L_80000AE8
    if (ctx->r2 == ctx->r4) {
        // 0x80000AB8: nop
    
            goto L_80000AE8;
    }
    // 0x80000AB8: nop

    // 0x80000ABC: beq         $a2, $a0, L_80000AE8
    if (ctx->r6 == ctx->r4) {
        // 0x80000AC0: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_80000AE8;
    }
    // 0x80000AC0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000AC4: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
    // 0x80000AC8: sw          $a0, 0x4FA0($at)
    MEM_W(0X4FA0, ctx->r1) = ctx->r4;
    // 0x80000ACC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000AD0: jal         0x80033490
    // 0x80000AD4: sw          $zero, 0x4FC8($at)
    MEM_W(0X4FC8, ctx->r1) = 0;
    osGetCount_recomp(rdram, ctx);
        goto after_2;
    // 0x80000AD4: sw          $zero, 0x4FC8($at)
    MEM_W(0X4FC8, ctx->r1) = 0;
    after_2:
    // 0x80000AD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000ADC: sw          $v0, 0x4FAC($at)
    MEM_W(0X4FAC, ctx->r1) = ctx->r2;
    // 0x80000AE0: b           L_80000B44
    // 0x80000AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80000B44;
    // 0x80000AE4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80000AE8:
    // 0x80000AE8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80000AEC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80000AF0: addiu       $a1, $a1, 0x4F9C
    ctx->r5 = ADD32(ctx->r5, 0X4F9C);
    // 0x80000AF4: addiu       $v1, $v1, 0x4F90
    ctx->r3 = ADD32(ctx->r3, 0X4F90);
    // 0x80000AF8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
L_80000AFC:
    // 0x80000AFC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80000B00: beq         $a0, $zero, L_80000B38
    if (ctx->r4 == 0) {
        // 0x80000B04: nop
    
            goto L_80000B38;
    }
    // 0x80000B04: nop

    // 0x80000B08: beq         $v0, $a0, L_80000B38
    if (ctx->r2 == ctx->r4) {
        // 0x80000B0C: nop
    
            goto L_80000B38;
    }
    // 0x80000B0C: nop

    // 0x80000B10: beq         $a2, $a0, L_80000B38
    if (ctx->r6 == ctx->r4) {
        // 0x80000B14: nop
    
            goto L_80000B38;
    }
    // 0x80000B14: nop

    // 0x80000B18: sw          $a0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r4;
    // 0x80000B1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000B20: jal         0x80033490
    // 0x80000B24: sw          $zero, 0x4FC8($at)
    MEM_W(0X4FC8, ctx->r1) = 0;
    osGetCount_recomp(rdram, ctx);
        goto after_3;
    // 0x80000B24: sw          $zero, 0x4FC8($at)
    MEM_W(0X4FC8, ctx->r1) = 0;
    after_3:
    // 0x80000B28: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000B2C: sw          $v0, 0x4FAC($at)
    MEM_W(0X4FAC, ctx->r1) = ctx->r2;
    // 0x80000B30: b           L_80000B44
    // 0x80000B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80000B44;
    // 0x80000B34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80000B38:
    // 0x80000B38: bnel        $v1, $a1, L_80000AFC
    if (ctx->r3 != ctx->r5) {
        // 0x80000B3C: lw          $a0, 0x0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X0);
            goto L_80000AFC;
    }
    goto skip_0;
    // 0x80000B3C: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x80000B40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80000B44:
    // 0x80000B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000B48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80000B4C: jr          $ra
    // 0x80000B50: nop

    return;
    // 0x80000B50: nop

;}
RECOMP_FUNC void itTomatoDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801745CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801745D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801745D4: lui         $a1, 0x3E99
    ctx->r5 = S32(0X3E99 << 16);
    // 0x801745D8: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801745DC: addiu       $a3, $a3, 0x4554
    ctx->r7 = ADD32(ctx->r7, 0X4554);
    // 0x801745E0: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x801745E4: jal         0x80173B24
    // 0x801745E8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x801745E8: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x801745EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801745F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801745F4: jr          $ra
    // 0x801745F8: nop

    return;
    // 0x801745F8: nop

;}
RECOMP_FUNC void efDisplayZPerspCLDProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCFCC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800FCFD0: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x800FCFD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FCFD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FCFDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FCFE0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800FCFE4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800FCFE8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800FCFEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FCFF0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FCFF4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FCFF8: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800FCFFC: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x800FD000: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800FD004: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800FD008: ori         $t0, $t0, 0x4340
    ctx->r8 = ctx->r8 | 0X4340;
    // 0x800FD00C: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800FD010: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800FD014: jal         0x800D0D34
    // 0x800FD018: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    lbParticleDrawTextures(rdram, ctx);
        goto after_0;
    // 0x800FD018: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    after_0:
    // 0x800FD01C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800FD020: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x800FD024: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD028: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x800FD02C: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x800FD030: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x800FD034: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800FD038: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FD03C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800FD040: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD044: ori         $t4, $t4, 0xC00
    ctx->r12 = ctx->r12 | 0XC00;
    // 0x800FD048: lui         $t5, 0x8
    ctx->r13 = S32(0X8 << 16);
    // 0x800FD04C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800FD050: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800FD054: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800FD058: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800FD05C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD060: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x800FD064: ori         $t7, $t7, 0x1D00
    ctx->r15 = ctx->r15 | 0X1D00;
    // 0x800FD068: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800FD06C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800FD070: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800FD074: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800FD078: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800FD07C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800FD080: lui         $t0, 0x55
    ctx->r8 = S32(0X55 << 16);
    // 0x800FD084: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800FD088: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800FD08C: ori         $t0, $t0, 0x2078
    ctx->r8 = ctx->r8 | 0X2078;
    // 0x800FD090: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800FD094: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800FD098: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800FD09C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FD0A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FD0A4: jr          $ra
    // 0x800FD0A8: nop

    return;
    // 0x800FD0A8: nop

;}
RECOMP_FUNC void func_ovl8_80376A04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376A04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80376A08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80376A0C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80376A10: jal         0x8037217C
    // 0x80376A14: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    func_ovl8_8037217C(rdram, ctx);
        goto after_0;
    // 0x80376A14: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_0:
    // 0x80376A18: jal         0x80375354
    // 0x80376A1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_ovl8_80375354(rdram, ctx);
        goto after_1;
    // 0x80376A1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80376A20: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80376A24: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    // 0x80376A28: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x80376A2C: lh          $t6, 0x80($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X80);
    // 0x80376A30: jalr        $t9
    // 0x80376A34: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x80376A34: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_2:
    // 0x80376A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80376A3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80376A40: jr          $ra
    // 0x80376A44: nop

    return;
    // 0x80376A44: nop

;}
RECOMP_FUNC void itSwordFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174BB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174BB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174BBC: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80174BC0: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80174BC4: addiu       $a3, $a3, 0x4BE4
    ctx->r7 = ADD32(ctx->r7, 0X4BE4);
    // 0x80174BC8: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80174BCC: jal         0x80173B24
    // 0x80174BD0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80174BD0: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80174BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174BD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174BDC: jr          $ra
    // 0x80174BE0: nop

    return;
    // 0x80174BE0: nop

;}
RECOMP_FUNC void itLinkBombExplodeInitAttackColl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801864E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801864EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801864F0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801864F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801864F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801864FC: lbu         $t6, 0x340($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X340);
    // 0x80186500: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x80186504: swc1        $f4, 0x114($v0)
    MEM_W(0X114, ctx->r2) = ctx->f4.u32l;
    // 0x80186508: andi        $t7, $t6, 0xFF0F
    ctx->r15 = ctx->r14 & 0XFF0F;
    // 0x8018650C: jal         0x801863AC
    // 0x80186510: sb          $t7, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r15;
    itLinkBombExplodeUpdateAttackEvent(rdram, ctx);
        goto after_0;
    // 0x80186510: sb          $t7, 0x340($v0)
    MEM_B(0X340, ctx->r2) = ctx->r15;
    after_0:
    // 0x80186514: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80186518: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018651C: jr          $ra
    // 0x80186520: nop

    return;
    // 0x80186520: nop

;}
RECOMP_FUNC void itTargetMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EE5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018EE60: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8018EE64: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8018EE68: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8018EE6C: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8018EE70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8018EE74: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018EE78: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018EE7C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x8018EE80: addiu       $a1, $a1, -0xED0
    ctx->r5 = ADD32(ctx->r5, -0XED0);
    // 0x8018EE84: jal         0x8016E174
    // 0x8018EE88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8018EE88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8018EE8C: beq         $v0, $zero, L_8018EEA4
    if (ctx->r2 == 0) {
        // 0x8018EE90: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8018EEA4;
    }
    // 0x8018EE90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EE94: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8018EE98: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8018EE9C: sw          $zero, 0x108($v1)
    MEM_W(0X108, ctx->r3) = 0;
    // 0x8018EEA0: sw          $t7, 0xAC($v1)
    MEM_W(0XAC, ctx->r3) = ctx->r15;
L_8018EEA4:
    // 0x8018EEA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018EEA8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018EEAC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8018EEB0: jr          $ra
    // 0x8018EEB4: nop

    return;
    // 0x8018EEB4: nop

;}
RECOMP_FUNC void ftPublicProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80165134: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80165138: addiu       $v1, $v1, -0x3070
    ctx->r3 = ADD32(ctx->r3, -0X3070);
    // 0x8016513C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80165140: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80165144: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80165148: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8016514C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80165150: beq         $at, $zero, L_80165160
    if (ctx->r1 == 0) {
        // 0x80165154: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80165160;
    }
    // 0x80165154: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80165158: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8016515C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80165160:
    // 0x80165160: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80165164: addiu       $a0, $a0, -0x3040
    ctx->r4 = ADD32(ctx->r4, -0X3040);
    // 0x80165168: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x8016516C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80165170: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80165174: lw          $v0, 0x66FC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66FC);
    // 0x80165178: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8016517C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x80165180: beq         $v0, $zero, L_801651FC
    if (ctx->r2 == 0) {
        // 0x80165184: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_801651FC;
    }
    // 0x80165184: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80165188: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x8016518C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80165190: addiu       $a3, $a3, 0x1308
    ctx->r7 = ADD32(ctx->r7, 0X1308);
    // 0x80165194: lw          $a1, 0x50E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X50E8);
    // 0x80165198: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8016519C: lbu         $t7, 0x3($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X3);
L_801651A0:
    // 0x801651A0: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x801651A4: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x801651A8: beql        $t8, $zero, L_801651C0
    if (ctx->r24 == 0) {
        // 0x801651AC: lwc1        $f6, 0x24($a3)
        ctx->f6.u32l = MEM_W(ctx->r7, 0X24);
            goto L_801651C0;
    }
    goto skip_0;
    // 0x801651AC: lwc1        $f6, 0x24($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X24);
    skip_0:
    // 0x801651B0: lb          $t9, 0x14($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X14);
    // 0x801651B4: beql        $a2, $t9, L_801651F4
    if (ctx->r6 == ctx->r25) {
        // 0x801651B8: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_801651F4;
    }
    goto skip_1;
    // 0x801651B8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x801651BC: lwc1        $f6, 0x24($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X24);
L_801651C0:
    // 0x801651C0: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x801651C4: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x801651C8: lwc1        $f4, 0x20($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X20);
    // 0x801651CC: c.lt.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl < ctx->f8.fl;
    // 0x801651D0: nop

    // 0x801651D4: bc1fl       L_801651F0
    if (!c1cs) {
        // 0x801651D8: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_801651F0;
    }
    goto skip_2;
    // 0x801651D8: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    skip_2:
    // 0x801651DC: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x801651E0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801651E4: b           L_801651F0
    // 0x801651E8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
        goto L_801651F0;
    // 0x801651E8: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x801651EC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_801651F0:
    // 0x801651F0: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_801651F4:
    // 0x801651F4: bnel        $v0, $zero, L_801651A0
    if (ctx->r2 != 0) {
        // 0x801651F8: lbu         $t7, 0x3($a1)
        ctx->r15 = MEM_BU(ctx->r5, 0X3);
            goto L_801651A0;
    }
    goto skip_3;
    // 0x801651F8: lbu         $t7, 0x3($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X3);
    skip_3:
L_801651FC:
    // 0x801651FC: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80165200: beq         $at, $zero, L_80165250
    if (ctx->r1 == 0) {
        // 0x80165204: nop
    
            goto L_80165250;
    }
    // 0x80165204: nop

    // 0x80165208: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8016520C: addiu       $a0, $zero, 0x267
    ctx->r4 = ADD32(0, 0X267);
    // 0x80165210: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80165214: bne         $at, $zero, L_80165250
    if (ctx->r1 != 0) {
        // 0x80165218: nop
    
            goto L_80165250;
    }
    // 0x80165218: nop

    // 0x8016521C: jal         0x80164C44
    // 0x80165220: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    ftPublicPlayCommon(rdram, ctx);
        goto after_0;
    // 0x80165220: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_0:
    // 0x80165224: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80165228: beq         $t0, $zero, L_80165250
    if (ctx->r8 == 0) {
        // 0x8016522C: nop
    
            goto L_80165250;
    }
    // 0x8016522C: nop

    // 0x80165230: lw          $t7, 0x84($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X84);
    // 0x80165234: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80165238: lw          $t6, -0x3054($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3054);
    // 0x8016523C: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80165240: bne         $t6, $t8, L_80165250
    if (ctx->r14 != ctx->r24) {
        // 0x80165244: nop
    
            goto L_80165250;
    }
    // 0x80165244: nop

    // 0x80165248: jal         0x80164C18
    // 0x8016524C: nop

    ftPublicTryInterruptCall(rdram, ctx);
        goto after_1;
    // 0x8016524C: nop

    after_1:
L_80165250:
    // 0x80165250: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80165254: addiu       $a1, $a1, -0x3048
    ctx->r5 = ADD32(ctx->r5, -0X3048);
    // 0x80165258: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8016525C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80165260: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80165264: slti        $at, $a0, 0x9
    ctx->r1 = SIGNED(ctx->r4) < 0X9 ? 1 : 0;
    // 0x80165268: beq         $at, $zero, L_80165320
    if (ctx->r1 == 0) {
        // 0x8016526C: addiu       $v1, $v1, -0x3058
        ctx->r3 = ADD32(ctx->r3, -0X3058);
            goto L_80165320;
    }
    // 0x8016526C: addiu       $v1, $v1, -0x3058
    ctx->r3 = ADD32(ctx->r3, -0X3058);
    // 0x80165270: addiu       $a2, $a2, -0x3050
    ctx->r6 = ADD32(ctx->r6, -0X3050);
    // 0x80165274: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80165278: addiu       $t2, $a0, 0x1
    ctx->r10 = ADD32(ctx->r4, 0X1);
    // 0x8016527C: slti        $at, $t2, 0x9
    ctx->r1 = SIGNED(ctx->r10) < 0X9 ? 1 : 0;
    // 0x80165280: beq         $v1, $zero, L_801652A4
    if (ctx->r3 == 0) {
        // 0x80165284: nop
    
            goto L_801652A4;
    }
    // 0x80165284: nop

    // 0x80165288: lhu         $v0, 0x26($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X26);
    // 0x8016528C: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80165290: beq         $v0, $zero, L_801652A4
    if (ctx->r2 == 0) {
        // 0x80165294: nop
    
            goto L_801652A4;
    }
    // 0x80165294: nop

    // 0x80165298: lhu         $t9, -0x304C($t9)
    ctx->r25 = MEM_HU(ctx->r25, -0X304C);
    // 0x8016529C: beq         $t9, $v0, L_80165334
    if (ctx->r25 == ctx->r2) {
        // 0x801652A0: nop
    
            goto L_80165334;
    }
    // 0x801652A0: nop

L_801652A4:
    // 0x801652A4: beq         $at, $zero, L_80165304
    if (ctx->r1 == 0) {
        // 0x801652A8: sw          $t2, 0x0($a1)
        MEM_W(0X0, ctx->r5) = ctx->r10;
            goto L_80165304;
    }
    // 0x801652A8: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x801652AC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x801652B0: addiu       $v0, $v0, -0x305C
    ctx->r2 = ADD32(ctx->r2, -0X305C);
    // 0x801652B4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x801652B8: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x801652BC: addiu       $v1, $v1, -0x3058
    ctx->r3 = ADD32(ctx->r3, -0X3058);
    // 0x801652C0: beq         $t4, $zero, L_801652D8
    if (ctx->r12 == 0) {
        // 0x801652C4: addiu       $t5, $zero, 0x9
        ctx->r13 = ADD32(0, 0X9);
            goto L_801652D8;
    }
    // 0x801652C4: addiu       $t5, $zero, 0x9
    ctx->r13 = ADD32(0, 0X9);
    // 0x801652C8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801652CC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801652D0: b           L_80165334
    // 0x801652D4: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
        goto L_80165334;
    // 0x801652D4: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
L_801652D8:
    // 0x801652D8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801652DC: jal         0x800269C0
    // 0x801652E0: lhu         $a0, -0x3042($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3042);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x801652E0: lhu         $a0, -0x3042($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3042);
    after_2:
    // 0x801652E4: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x801652E8: addiu       $a2, $a2, -0x3050
    ctx->r6 = ADD32(ctx->r6, -0X3050);
    // 0x801652EC: beq         $v0, $zero, L_80165334
    if (ctx->r2 == 0) {
        // 0x801652F0: sw          $v0, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r2;
            goto L_80165334;
    }
    // 0x801652F0: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x801652F4: lhu         $t7, 0x26($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X26);
    // 0x801652F8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801652FC: b           L_80165334
    // 0x80165300: sh          $t7, -0x304C($at)
    MEM_H(-0X304C, ctx->r1) = ctx->r15;
        goto L_80165334;
    // 0x80165300: sh          $t7, -0x304C($at)
    MEM_H(-0X304C, ctx->r1) = ctx->r15;
L_80165304:
    // 0x80165304: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80165308: addiu       $v1, $v1, -0x3058
    ctx->r3 = ADD32(ctx->r3, -0X3058);
    // 0x8016530C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80165310: jal         0x80164C44
    // 0x80165314: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    ftPublicPlayCommon(rdram, ctx);
        goto after_3;
    // 0x80165314: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    after_3:
    // 0x80165318: b           L_80165334
    // 0x8016531C: nop

        goto L_80165334;
    // 0x8016531C: nop

L_80165320:
    // 0x80165320: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80165324: slti        $at, $v0, 0x4B0
    ctx->r1 = SIGNED(ctx->r2) < 0X4B0 ? 1 : 0;
    // 0x80165328: beq         $at, $zero, L_80165334
    if (ctx->r1 == 0) {
        // 0x8016532C: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80165334;
    }
    // 0x8016532C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80165330: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_80165334:
    // 0x80165334: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80165338: addiu       $a2, $a2, -0x3024
    ctx->r6 = ADD32(ctx->r6, -0X3024);
    // 0x8016533C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80165340: lw          $t8, -0x3020($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3020);
    // 0x80165344: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80165348: beq         $t8, $a1, L_801653D0
    if (ctx->r24 == ctx->r5) {
        // 0x8016534C: lui         $a3, 0x8019
        ctx->r7 = S32(0X8019 << 16);
            goto L_801653D0;
    }
    // 0x8016534C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x80165350: addiu       $a3, $a3, -0x301C
    ctx->r7 = ADD32(ctx->r7, -0X301C);
    // 0x80165354: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80165358: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8016535C: sll         $t2, $a1, 1
    ctx->r10 = S32(ctx->r5 << 1);
    // 0x80165360: beq         $v1, $zero, L_8016537C
    if (ctx->r3 == 0) {
        // 0x80165364: lui         $a0, 0x8019
        ctx->r4 = S32(0X8019 << 16);
            goto L_8016537C;
    }
    // 0x80165364: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80165368: lhu         $v0, -0x3018($v0)
    ctx->r2 = MEM_HU(ctx->r2, -0X3018);
    // 0x8016536C: beql        $v0, $zero, L_80165380
    if (ctx->r2 == 0) {
        // 0x80165370: addu        $a0, $a0, $t2
        ctx->r4 = ADD32(ctx->r4, ctx->r10);
            goto L_80165380;
    }
    goto skip_4;
    // 0x80165370: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
    skip_4:
    // 0x80165374: lhu         $t9, 0x26($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X26);
    // 0x80165378: beq         $v0, $t9, L_801653D0
    if (ctx->r2 == ctx->r25) {
        // 0x8016537C: addu        $a0, $a0, $t2
        ctx->r4 = ADD32(ctx->r4, ctx->r10);
            goto L_801653D0;
    }
L_8016537C:
    // 0x8016537C: addu        $a0, $a0, $t2
    ctx->r4 = ADD32(ctx->r4, ctx->r10);
L_80165380:
    // 0x80165380: jal         0x800269C0
    // 0x80165384: lhu         $a0, -0x3038($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3038);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80165384: lhu         $a0, -0x3038($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3038);
    after_4:
    // 0x80165388: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8016538C: addiu       $a3, $a3, -0x301C
    ctx->r7 = ADD32(ctx->r7, -0X301C);
    // 0x80165390: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80165394: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x80165398: addiu       $a2, $a2, -0x3024
    ctx->r6 = ADD32(ctx->r6, -0X3024);
    // 0x8016539C: addiu       $a0, $a0, -0x3018
    ctx->r4 = ADD32(ctx->r4, -0X3018);
    // 0x801653A0: beq         $v0, $zero, L_801653B4
    if (ctx->r2 == 0) {
        // 0x801653A4: sw          $v0, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r2;
            goto L_801653B4;
    }
    // 0x801653A4: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x801653A8: lhu         $t3, 0x26($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X26);
    // 0x801653AC: b           L_801653B8
    // 0x801653B0: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
        goto L_801653B8;
    // 0x801653B0: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
L_801653B4:
    // 0x801653B4: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
L_801653B8:
    // 0x801653B8: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x801653BC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801653C0: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x801653C4: bne         $t5, $at, L_801653D0
    if (ctx->r13 != ctx->r1) {
        // 0x801653C8: sw          $t5, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r13;
            goto L_801653D0;
    }
    // 0x801653C8: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x801653CC: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_801653D0:
    // 0x801653D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801653D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801653D8: jr          $ra
    // 0x801653DC: nop

    return;
    // 0x801653DC: nop

;}
RECOMP_FUNC void func_ovl65_8018D3D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D3D0: jr          $ra
    // 0x8018D3D4: nop

    return;
    // 0x8018D3D4: nop

;}
RECOMP_FUNC void ftBossOkuhikouki2ProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801595F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801595F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801595F8: jal         0x800D938C
    // 0x801595FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPhysicsSetAirVelTransN(rdram, ctx);
        goto after_0;
    // 0x801595FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80159600: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80159604: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80159608: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8015960C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80159610: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80159614: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80159618: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015961C: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x80159620: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80159624: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x80159628: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8015962C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80159630: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80159634: nop

    // 0x80159638: bc1fl       L_8015964C
    if (!c1cs) {
        // 0x8015963C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8015964C;
    }
    goto skip_0;
    // 0x8015963C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80159640: b           L_8015964C
    // 0x80159644: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8015964C;
    // 0x80159644: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80159648: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8015964C:
    // 0x8015964C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80159650: nop

    // 0x80159654: bc1fl       L_80159690
    if (!c1cs) {
        // 0x80159658: lwc1        $f16, 0x48($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
            goto L_80159690;
    }
    goto skip_1;
    // 0x80159658: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    skip_1:
    // 0x8015965C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80159660: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x80159664: bc1fl       L_80159678
    if (!c1cs) {
        // 0x80159668: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80159678;
    }
    goto skip_2;
    // 0x80159668: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x8015966C: b           L_8015967C
    // 0x80159670: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_8015967C;
    // 0x80159670: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x80159674: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80159678:
    // 0x80159678: nop

L_8015967C:
    // 0x8015967C: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x80159680: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80159684: b           L_80159698
    // 0x80159688: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
        goto L_80159698;
    // 0x80159688: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x8015968C: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
L_80159690:
    // 0x80159690: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80159694: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
L_80159698:
    // 0x80159698: jal         0x80158528
    // 0x8015969C: nop

    ftBossCommonUpdateFogColor(rdram, ctx);
        goto after_1;
    // 0x8015969C: nop

    after_1:
    // 0x801596A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801596A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801596A8: jr          $ra
    // 0x801596AC: nop

    return;
    // 0x801596AC: nop

;}
RECOMP_FUNC void syMatrixTraRotRpyRF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C1C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001C1CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001C1D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8001C1D4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8001C1D8: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8001C1DC: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8001C1E0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C1E4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8001C1E8: jal         0x8001BDEC
    // 0x8001C1EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    syMatrixRotRpyRF(rdram, ctx);
        goto after_0;
    // 0x8001C1EC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8001C1F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8001C1F4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001C1F8: swc1        $f4, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f4.u32l;
    // 0x8001C1FC: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8001C200: swc1        $f6, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f6.u32l;
    // 0x8001C204: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8001C208: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x8001C20C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001C210: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001C214: jr          $ra
    // 0x8001C218: nop

    return;
    // 0x8001C218: nop

;}
RECOMP_FUNC void mnPlayersVSUpdateTeamSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013287C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132880: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132884: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132888: jal         0x80132824
    // 0x8013288C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayersVSDestroyTeamSelect(rdram, ctx);
        goto after_0;
    // 0x8013288C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80132890: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80132894: jal         0x8013271C
    // 0x80132898: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    mnPlayersVSMakeTeamSelect(rdram, ctx);
        goto after_1;
    // 0x80132898: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8013289C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801328A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801328A4: jr          $ra
    // 0x801328A8: nop

    return;
    // 0x801328A8: nop

;}
RECOMP_FUNC void _decodeChunk(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029720: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029724: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x80029728: sw          $s6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r22;
    // 0x8002972C: sll         $s6, $s6, 16
    ctx->r22 = S32(ctx->r22 << 16);
    // 0x80029730: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x80029734: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x80029738: sra         $s6, $s6, 16
    ctx->r22 = S32(SIGNED(ctx->r22) >> 16);
    // 0x8002973C: blez        $s1, L_8002979C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80029740: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8002979C;
    }
    // 0x80029740: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029744: lw          $t9, 0x28($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X28);
    // 0x80029748: lw          $a0, 0x3C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X3C);
    // 0x8002974C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80029750: jalr        $t9
    // 0x80029754: lw          $a2, 0x2C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X2C);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80029754: lw          $a2, 0x2C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X2C);
    after_0:
    // 0x80029758: andi        $a1, $v0, 0x7
    ctx->r5 = ctx->r2 & 0X7;
    // 0x8002975C: addu        $s1, $s1, $a1
    ctx->r17 = ADD32(ctx->r17, ctx->r5);
    // 0x80029760: andi        $t6, $s1, 0x7
    ctx->r14 = ctx->r17 & 0X7;
    // 0x80029764: subu        $t7, $s1, $t6
    ctx->r15 = SUB32(ctx->r17, ctx->r14);
    // 0x80029768: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x8002976C: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80029770: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80029774: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80029778: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8002977C: andi        $t8, $s4, 0xFFF
    ctx->r24 = ctx->r20 & 0XFFF;
    // 0x80029780: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80029784: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80029788: subu        $t6, $v0, $a1
    ctx->r14 = SUB32(ctx->r2, ctx->r5);
    // 0x8002978C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80029790: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80029794: b           L_800297A0
    // 0x80029798: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
        goto L_800297A0;
    // 0x80029798: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8002979C:
    // 0x8002979C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800297A0:
    // 0x800297A0: andi        $t7, $s3, 0x2
    ctx->r15 = ctx->r19 & 0X2;
    // 0x800297A4: beq         $t7, $zero, L_800297CC
    if (ctx->r15 == 0) {
        // 0x800297A8: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_800297CC;
    }
    // 0x800297A8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800297AC: lui         $t8, 0xF00
    ctx->r24 = S32(0XF00 << 16);
    // 0x800297B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800297B4: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x800297B8: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800297BC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800297C0: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x800297C4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800297C8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_800297CC:
    // 0x800297CC: lw          $t7, 0xC($s2)
    ctx->r15 = MEM_W(ctx->r18, 0XC);
    // 0x800297D0: lui         $at, 0x1FFF
    ctx->r1 = S32(0X1FFF << 16);
    // 0x800297D4: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800297D8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800297DC: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800297E0: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800297E4: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800297E8: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800297EC: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x800297F0: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x800297F4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800297F8: sll         $t9, $s5, 1
    ctx->r25 = S32(ctx->r21 << 1);
    // 0x800297FC: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80029800: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x80029804: sll         $t8, $s3, 28
    ctx->r24 = S32(ctx->r19 << 28);
    // 0x80029808: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8002980C: andi        $t6, $a1, 0xF
    ctx->r14 = ctx->r5 & 0XF;
    // 0x80029810: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80029814: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80029818: andi        $t6, $s6, 0xFFF
    ctx->r14 = ctx->r22 & 0XFFF;
    // 0x8002981C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80029820: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80029824: sw          $zero, 0x38($s2)
    MEM_W(0X38, ctx->r18) = 0;
    // 0x80029828: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002982C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80029830: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80029834: jr          $ra
    // 0x80029838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80029838: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void dbBattleGetSetShade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CD8: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80131CDC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80131CE0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80131CE4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80131CE8: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80131CEC: addiu       $t7, $t7, 0x4D08
    ctx->r15 = ADD32(ctx->r15, 0X4D08);
    // 0x80131CF0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80131CF4: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80131CF8: addiu       $t0, $t0, 0x4D08
    ctx->r8 = ADD32(ctx->r8, 0X4D08);
    // 0x80131CFC: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x80131D00: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131D04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131D08: addiu       $t1, $zero, 0x74
    ctx->r9 = ADD32(0, 0X74);
    // 0x80131D0C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
L_80131D10:
    // 0x80131D10: beql        $v0, $a0, L_80131D60
    if (ctx->r2 == ctx->r4) {
        // 0x80131D14: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80131D60;
    }
    goto skip_0;
    // 0x80131D14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
L_80131D18:
    // 0x80131D18: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131D1C: lbu         $t2, 0x23($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X23);
    // 0x80131D20: mflo        $t8
    ctx->r24 = lo;
    // 0x80131D24: addu        $a1, $t0, $t8
    ctx->r5 = ADD32(ctx->r8, ctx->r24);
    // 0x80131D28: lbu         $t9, 0x23($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X23);
    // 0x80131D2C: bnel        $t9, $t2, L_80131D60
    if (ctx->r25 != ctx->r10) {
        // 0x80131D30: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80131D60;
    }
    goto skip_1;
    // 0x80131D30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x80131D34: lbu         $t3, 0x26($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X26);
    // 0x80131D38: lbu         $t4, 0x26($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X26);
    // 0x80131D3C: bnel        $t3, $t4, L_80131D60
    if (ctx->r11 != ctx->r12) {
        // 0x80131D40: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80131D60;
    }
    goto skip_2;
    // 0x80131D40: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x80131D44: lbu         $t5, 0x27($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X27);
    // 0x80131D48: bnel        $v1, $t5, L_80131D60
    if (ctx->r3 != ctx->r13) {
        // 0x80131D4C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80131D60;
    }
    goto skip_3;
    // 0x80131D4C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_3:
    // 0x80131D50: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80131D54: bne         $zero, $a0, L_80131D18
    if (0 != ctx->r4) {
        // 0x80131D58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80131D18;
    }
    // 0x80131D58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131D5C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80131D60:
    // 0x80131D60: bne         $v0, $a3, L_80131D10
    if (ctx->r2 != ctx->r7) {
        // 0x80131D64: nop
    
            goto L_80131D10;
    }
    // 0x80131D64: nop

    // 0x80131D68: sb          $v1, 0x27($a2)
    MEM_B(0X27, ctx->r6) = ctx->r3;
    // 0x80131D6C: jr          $ra
    // 0x80131D70: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131D70: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnPlayers1PTrainingMakePlayerKindSelectCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A44: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132A48: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132A4C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132A50: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132A54: addiu       $t7, $zero, 0x23
    ctx->r15 = ADD32(0, 0X23);
    // 0x80132A58: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132A5C: lui         $t9, 0x4000
    ctx->r25 = S32(0X4000 << 16);
    // 0x80132A60: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132A64: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132A68: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132A6C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132A70: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132A74: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132A78: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132A7C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132A80: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132A84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132A88: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132A8C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132A90: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132A94: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132A98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132A9C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132AA0: jal         0x8000B93C
    // 0x80132AA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132AA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132AA8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132AAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132AB0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132AB4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132AB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132ABC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132AC0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132AC4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132AC8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132ACC: jal         0x80007080
    // 0x80132AD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132AD0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132AD4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132AD8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132ADC: jr          $ra
    // 0x80132AE0: nop

    return;
    // 0x80132AE0: nop

;}
RECOMP_FUNC void ftAnimEndCheckSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9480: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D9484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9488: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x800D948C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D9490: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D9494: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x800D9498: nop

    // 0x800D949C: bc1f        L_800D94B4
    if (!c1cs) {
        // 0x800D94A0: nop
    
            goto L_800D94B4;
    }
    // 0x800D94A0: nop

    // 0x800D94A4: jalr        $a1
    // 0x800D94A8: nop

    LOOKUP_FUNC(ctx->r5)(rdram, ctx);
        goto after_0;
    // 0x800D94A8: nop

    after_0:
    // 0x800D94AC: b           L_800D94B4
    // 0x800D94B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D94B4;
    // 0x800D94B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D94B4:
    // 0x800D94B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D94B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D94BC: jr          $ra
    // 0x800D94C0: nop

    return;
    // 0x800D94C0: nop

;}
RECOMP_FUNC void syMatrixTraRotRpyD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D58C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8001D590: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D594: lwc1        $f0, -0x1C20($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C20);
    // 0x8001D598: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8001D59C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D5A0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001D5A4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D5A8: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8001D5AC: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001D5B0: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D5B4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001D5B8: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D5BC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D5C0: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8001D5C4: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D5C8: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D5CC: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001D5D0: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8001D5D4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001D5D8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D5DC: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8001D5E0: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8001D5E4: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001D5E8: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8001D5EC: jal         0x8001C1C8
    // 0x8001D5F0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixTraRotRpyRF(rdram, ctx);
        goto after_0;
    // 0x8001D5F0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8001D5F4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8001D5F8: jal         0x80019EA0
    // 0x8001D5FC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001D5FC: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x8001D600: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D604: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8001D608: jr          $ra
    // 0x8001D60C: nop

    return;
    // 0x8001D60C: nop

;}
RECOMP_FUNC void gcRemoveMatAnimJointAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BCBC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000BCC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000BCC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000BCC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000BCCC: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x8000BCD0: beql        $s1, $zero, L_8000BD0C
    if (ctx->r17 == 0) {
        // 0x8000BCD4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000BD0C;
    }
    goto skip_0;
    // 0x8000BCD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8000BCD8:
    // 0x8000BCD8: lw          $s0, 0x80($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X80);
    // 0x8000BCDC: beq         $s0, $zero, L_8000BCF8
    if (ctx->r16 == 0) {
        // 0x8000BCE0: nop
    
            goto L_8000BCF8;
    }
    // 0x8000BCE0: nop

L_8000BCE4:
    // 0x8000BCE4: jal         0x80008FB0
    // 0x8000BCE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveAObjFromMObj(rdram, ctx);
        goto after_0;
    // 0x8000BCE8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000BCEC: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000BCF0: bne         $s0, $zero, L_8000BCE4
    if (ctx->r16 != 0) {
        // 0x8000BCF4: nop
    
            goto L_8000BCE4;
    }
    // 0x8000BCF4: nop

L_8000BCF8:
    // 0x8000BCF8: jal         0x8000BAA0
    // 0x8000BCFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_1;
    // 0x8000BCFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8000BD00: bne         $v0, $zero, L_8000BCD8
    if (ctx->r2 != 0) {
        // 0x8000BD04: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000BCD8;
    }
    // 0x8000BD04: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000BD08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000BD0C:
    // 0x8000BD0C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000BD10: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000BD14: jr          $ra
    // 0x8000BD18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000BD18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftCaptainSpecialLwProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FDB4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015FDB8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015FDBC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8015FDC0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8015FDC4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015FDC8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8015FDCC: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
    // 0x8015FDD0: bnel        $t6, $zero, L_8015FE04
    if (ctx->r14 != 0) {
        // 0x8015FDD4: lw          $t8, 0x17C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X17C);
            goto L_8015FE04;
    }
    goto skip_0;
    // 0x8015FDD4: lw          $t8, 0x17C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X17C);
    skip_0:
    // 0x8015FDD8: lwc1        $f12, 0xF8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x8015FDDC: jal         0x8001863C
    // 0x8015FDE0: lwc1        $f14, 0xFC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XFC);
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8015FDE0: lwc1        $f14, 0xFC($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0XFC);
    after_0:
    // 0x8015FDE4: lw          $t7, 0x8E8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8E8);
    // 0x8015FDE8: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x8015FDEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8015FDF0: jal         0x800D8C14
    // 0x8015FDF4: swc1        $f4, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f4.u32l;
    ftPhysicsApplyGroundVelTransN(rdram, ctx);
        goto after_1;
    // 0x8015FDF4: swc1        $f4, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f4.u32l;
    after_1:
    // 0x8015FDF8: b           L_8015FE28
    // 0x8015FDFC: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
        goto L_8015FE28;
    // 0x8015FDFC: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8015FE00: lw          $t8, 0x17C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X17C);
L_8015FE04:
    // 0x8015FE04: beq         $t8, $zero, L_8015FE1C
    if (ctx->r24 == 0) {
        // 0x8015FE08: nop
    
            goto L_8015FE1C;
    }
    // 0x8015FE08: nop

    // 0x8015FE0C: jal         0x800D91EC
    // 0x8015FE10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsApplyAirVelFriction(rdram, ctx);
        goto after_2;
    // 0x8015FE10: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8015FE14: b           L_8015FE28
    // 0x8015FE18: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
        goto L_8015FE28;
    // 0x8015FE18: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
L_8015FE1C:
    // 0x8015FE1C: jal         0x800D93E4
    // 0x8015FE20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsApplyAirVelTransNAll(rdram, ctx);
        goto after_3;
    // 0x8015FE20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8015FE24: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
L_8015FE28:
    // 0x8015FE28: jal         0x800190B0
    // 0x8015FE2C: lw          $a1, 0xB1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB1C);
    syVectorScale3D(rdram, ctx);
        goto after_4;
    // 0x8015FE2C: lw          $a1, 0xB1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XB1C);
    after_4:
    // 0x8015FE30: jal         0x8015FC30
    // 0x8015FE34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCaptainSpecialLwUpdateEffect(rdram, ctx);
        goto after_5;
    // 0x8015FE34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x8015FE38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015FE3C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8015FE40: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8015FE44: jr          $ra
    // 0x8015FE48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8015FE48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void sc1PTrainingModeItemDisplayProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E9AC: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018E9B0: lbu         $t7, 0x4AE3($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4AE3);
    // 0x8018E9B4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E9B8: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018E9BC: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018E9C0: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018E9C4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018E9C8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E9CC: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018E9D0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E9D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018E9D8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8018E9DC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8018E9E0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018E9E4: lw          $t0, 0x78($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X78);
    // 0x8018E9E8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8018E9EC: lw          $v0, 0x84($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X84);
    // 0x8018E9F0: lw          $v1, 0x84C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84C);
    // 0x8018E9F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018E9F8: beq         $v1, $zero, L_8018EA50
    if (ctx->r3 == 0) {
        // 0x8018E9FC: nop
    
            goto L_8018EA50;
    }
    // 0x8018E9FC: nop

    // 0x8018EA00: lw          $s0, 0x84($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X84);
    // 0x8018EA04: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8018EA08: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x8018EA0C: beql        $at, $zero, L_8018EA38
    if (ctx->r1 == 0) {
        // 0x8018EA10: slti        $at, $a1, 0x14
        ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
            goto L_8018EA38;
    }
    goto skip_0;
    // 0x8018EA10: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
    skip_0:
    // 0x8018EA14: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018EA18: addiu       $s1, $s1, 0x920
    ctx->r17 = ADD32(ctx->r17, 0X920);
L_8018EA1C:
    // 0x8018EA1C: jal         0x80023624
    // 0x8018EA20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x8018EA20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x8018EA24: jal         0x800A3040
    // 0x8018EA28: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x8018EA28: nop

    after_1:
    // 0x8018EA2C: b           L_8018EA1C
    // 0x8018EA30: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
        goto L_8018EA1C;
    // 0x8018EA30: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8018EA34: slti        $at, $a1, 0x14
    ctx->r1 = SIGNED(ctx->r5) < 0X14 ? 1 : 0;
L_8018EA38:
    // 0x8018EA38: beq         $at, $zero, L_8018EA48
    if (ctx->r1 == 0) {
        // 0x8018EA3C: nop
    
            goto L_8018EA48;
    }
    // 0x8018EA3C: nop

    // 0x8018EA40: b           L_8018EA50
    // 0x8018EA44: addiu       $v0, $a1, -0x3
    ctx->r2 = ADD32(ctx->r5, -0X3);
        goto L_8018EA50;
    // 0x8018EA44: addiu       $v0, $a1, -0x3
    ctx->r2 = ADD32(ctx->r5, -0X3);
L_8018EA48:
    // 0x8018EA48: b           L_8018EA50
    // 0x8018EA4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018EA50;
    // 0x8018EA4C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018EA50:
    // 0x8018EA50: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018EA54: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018EA58: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x8018EA5C: beq         $v0, $t1, L_8018EA6C
    if (ctx->r2 == ctx->r9) {
        // 0x8018EA60: nop
    
            goto L_8018EA6C;
    }
    // 0x8018EA60: nop

    // 0x8018EA64: jal         0x8018E90C
    // 0x8018EA68: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    sc1PTrainingModeUpdateItemDisplaySprite(rdram, ctx);
        goto after_2;
    // 0x8018EA68: sw          $v0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r2;
    after_2:
L_8018EA6C:
    // 0x8018EA6C: jal         0x800CCF00
    // 0x8018EA70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_3;
    // 0x8018EA70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8018EA74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018EA78: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8018EA7C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8018EA80: jr          $ra
    // 0x8018EA84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8018EA84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_8037D9A8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D9A8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D9AC: jr          $ra
    // 0x8037D9B0: sw          $a0, -0x460($at)
    MEM_W(-0X460, ctx->r1) = ctx->r4;
    return;
    // 0x8037D9B0: sw          $a0, -0x460($at)
    MEM_W(-0X460, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void syControllerInitDevices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800040A0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800040A4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800040A8: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x800040AC: addiu       $s4, $s4, 0x50F0
    ctx->r20 = ADD32(ctx->r20, 0X50F0);
    // 0x800040B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800040B4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800040B8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800040BC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800040C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800040C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800040C8: addiu       $a1, $a1, 0x5108
    ctx->r5 = ADD32(ctx->r5, 0X5108);
    // 0x800040CC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800040D0: jal         0x80034480
    // 0x800040D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800040D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800040D8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    // 0x800040DC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800040E0: jal         0x800334A0
    // 0x800040E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800040E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x800040E8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x800040EC: addiu       $a2, $a2, 0x5178
    ctx->r6 = ADD32(ctx->r6, 0X5178);
    // 0x800040F0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800040F4: jal         0x80031AE0
    // 0x800040F8: addiu       $a1, $sp, 0x43
    ctx->r5 = ADD32(ctx->r29, 0X43);
    osContInit_recomp(rdram, ctx);
        goto after_2;
    // 0x800040F8: addiu       $a1, $sp, 0x43
    ctx->r5 = ADD32(ctx->r29, 0X43);
    after_2:
    // 0x800040FC: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80004100: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80004104: addiu       $s2, $s2, 0x52C8
    ctx->r18 = ADD32(ctx->r18, 0X52C8);
    // 0x80004108: addiu       $s1, $s1, 0x5178
    ctx->r17 = ADD32(ctx->r17, 0X5178);
    // 0x8000410C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80004110: addiu       $s3, $zero, 0x68
    ctx->r19 = ADD32(0, 0X68);
L_80004114:
    // 0x80004114: lbu         $t6, 0x2($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X2);
    // 0x80004118: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x8000411C: beql        $t7, $zero, L_80004144
    if (ctx->r15 == 0) {
        // 0x80004120: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80004144;
    }
    goto skip_0;
    // 0x80004120: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80004124: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80004128: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000412C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80004130: mflo        $t8
    ctx->r24 = lo;
    // 0x80004134: addu        $a1, $s2, $t8
    ctx->r5 = ADD32(ctx->r18, ctx->r24);
    // 0x80004138: jal         0x800318C4
    // 0x8000413C: nop

    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x8000413C: nop

    after_3:
    // 0x80004140: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80004144:
    // 0x80004144: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80004148: bne         $at, $zero, L_80004114
    if (ctx->r1 != 0) {
        // 0x8000414C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80004114;
    }
    // 0x8000414C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80004150: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80004154: addiu       $s1, $s1, 0x5160
    ctx->r17 = ADD32(ctx->r17, 0X5160);
    // 0x80004158: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x8000415C: addiu       $a1, $a1, 0x5150
    ctx->r5 = ADD32(ctx->r5, 0X5150);
    // 0x80004160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80004164: jal         0x80034480
    // 0x80004168: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_4;
    // 0x80004168: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_4:
    // 0x8000416C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80004170: addiu       $v0, $v0, 0x5268
    ctx->r2 = ADD32(ctx->r2, 0X5268);
    // 0x80004174: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80004178: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
L_8000417C:
    // 0x8000417C: sw          $s0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r16;
    // 0x80004180: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80004184: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80004188: addiu       $v0, $v0, 0x18
    ctx->r2 = ADD32(ctx->r2, 0X18);
    // 0x8000418C: sw          $zero, -0x18($v0)
    MEM_W(-0X18, ctx->r2) = 0;
    // 0x80004190: sw          $a2, -0x14($v0)
    MEM_W(-0X14, ctx->r2) = ctx->r6;
    // 0x80004194: bne         $at, $zero, L_8000417C
    if (ctx->r1 != 0) {
        // 0x80004198: sw          $s1, -0xC($v0)
        MEM_W(-0XC, ctx->r2) = ctx->r17;
            goto L_8000417C;
    }
    // 0x80004198: sw          $s1, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r17;
    // 0x8000419C: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800041A0: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800041A4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800041A8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800041AC: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800041B0: addiu       $t0, $t0, 0x5250
    ctx->r8 = ADD32(ctx->r8, 0X5250);
    // 0x800041B4: addiu       $v1, $v1, 0x5228
    ctx->r3 = ADD32(ctx->r3, 0X5228);
    // 0x800041B8: addiu       $v0, $v0, 0x51A8
    ctx->r2 = ADD32(ctx->r2, 0X51A8);
    // 0x800041BC: addiu       $a1, $a1, 0x5188
    ctx->r5 = ADD32(ctx->r5, 0X5188);
    // 0x800041C0: addiu       $s1, $s1, 0x5178
    ctx->r17 = ADD32(ctx->r17, 0X5178);
    // 0x800041C4: addiu       $a3, $zero, 0x1E
    ctx->r7 = ADD32(0, 0X1E);
L_800041C8:
    // 0x800041C8: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x800041CC: sb          $zero, 0x9($v1)
    MEM_B(0X9, ctx->r3) = 0;
    // 0x800041D0: lb          $t9, 0xF($v0)
    ctx->r25 = MEM_B(ctx->r2, 0XF);
    // 0x800041D4: lbu         $t1, 0x3($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X3);
    // 0x800041D8: lbu         $t2, 0x2($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X2);
    // 0x800041DC: lb          $t3, 0x9($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X9);
    // 0x800041E0: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x800041E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800041E8: addiu       $a1, $a1, 0x6
    ctx->r5 = ADD32(ctx->r5, 0X6);
    // 0x800041EC: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800041F0: sh          $zero, -0x6($a1)
    MEM_H(-0X6, ctx->r5) = 0;
    // 0x800041F4: sh          $zero, -0x1A($v0)
    MEM_H(-0X1A, ctx->r2) = 0;
    // 0x800041F8: sh          $zero, -0x1E($v0)
    MEM_H(-0X1E, ctx->r2) = 0;
    // 0x800041FC: sh          $zero, -0x20($v0)
    MEM_H(-0X20, ctx->r2) = 0;
    // 0x80004200: sw          $a3, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = ctx->r7;
    // 0x80004204: sw          $a3, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = ctx->r7;
    // 0x80004208: sw          $a2, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = ctx->r6;
    // 0x8000420C: sh          $zero, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = 0;
    // 0x80004210: sh          $zero, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = 0;
    // 0x80004214: sh          $zero, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = 0;
    // 0x80004218: sb          $t9, -0x12($v0)
    MEM_B(-0X12, ctx->r2) = ctx->r25;
    // 0x8000421C: sb          $t1, -0x4($v0)
    MEM_B(-0X4, ctx->r2) = ctx->r9;
    // 0x80004220: sb          $t2, -0x3($v0)
    MEM_B(-0X3, ctx->r2) = ctx->r10;
    // 0x80004224: bne         $v1, $t0, L_800041C8
    if (ctx->r3 != ctx->r8) {
        // 0x80004228: sb          $t3, -0x2($v1)
        MEM_B(-0X2, ctx->r3) = ctx->r11;
            goto L_800041C8;
    }
    // 0x80004228: sb          $t3, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r11;
    // 0x8000422C: jal         0x80003C00
    // 0x80004230: nop

    syControllerUpdateDeviceIndexes(rdram, ctx);
        goto after_5;
    // 0x80004230: nop

    after_5:
    // 0x80004234: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004238: sw          $zero, 0x5250($at)
    MEM_W(0X5250, ctx->r1) = 0;
    // 0x8000423C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004240: sw          $zero, 0x5254($at)
    MEM_W(0X5254, ctx->r1) = 0;
    // 0x80004244: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80004248: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000424C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80004250: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80004254: sw          $v0, 0x5258($at)
    MEM_W(0X5258, ctx->r1) = ctx->r2;
    // 0x80004258: addiu       $v1, $v1, 0x525C
    ctx->r3 = ADD32(ctx->r3, 0X525C);
    // 0x8000425C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80004260: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80004264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004268: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000426C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80004270: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80004274: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80004278: sw          $v0, 0x5260($at)
    MEM_W(0X5260, ctx->r1) = ctx->r2;
    // 0x8000427C: jr          $ra
    // 0x80004280: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80004280: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ftPikachuSpecialLwStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151ED4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151ED8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151EDC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151EE0: jal         0x800DDE84
    // 0x80151EE4: addiu       $a1, $a1, 0x1F5C
    ctx->r5 = ADD32(ctx->r5, 0X1F5C);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80151EE4: addiu       $a1, $a1, 0x1F5C
    ctx->r5 = ADD32(ctx->r5, 0X1F5C);
    after_0:
    // 0x80151EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151EF0: jr          $ra
    // 0x80151EF4: nop

    return;
    // 0x80151EF4: nop

;}
RECOMP_FUNC void ifCommonBattleUpdateScoreStocks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011388C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80113890: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80113894: lw          $t1, 0x50E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50E8);
    // 0x80113898: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8011389C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801138A0: lbu         $a2, 0xC($a0)
    ctx->r6 = MEM_BU(ctx->r4, 0XC);
    // 0x801138A4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801138A8: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801138AC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x801138B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801138B4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801138B8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801138BC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
L_801138C0:
    // 0x801138C0: lbu         $t7, 0x22($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X22);
    // 0x801138C4: beql        $a0, $t7, L_80113910
    if (ctx->r4 == ctx->r15) {
        // 0x801138C8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80113910;
    }
    goto skip_0;
    // 0x801138C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_0:
    // 0x801138CC: lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X2);
    // 0x801138D0: beq         $v0, $zero, L_801138E8
    if (ctx->r2 == 0) {
        // 0x801138D4: nop
    
            goto L_801138E8;
    }
    // 0x801138D4: nop

    // 0x801138D8: beql        $v0, $t2, L_801138F4
    if (ctx->r2 == ctx->r10) {
        // 0x801138DC: lbu         $a3, 0x24($v1)
        ctx->r7 = MEM_BU(ctx->r3, 0X24);
            goto L_801138F4;
    }
    goto skip_1;
    // 0x801138DC: lbu         $a3, 0x24($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X24);
    skip_1:
    // 0x801138E0: b           L_801138F4
    // 0x801138E4: nop

        goto L_801138F4;
    // 0x801138E4: nop

L_801138E8:
    // 0x801138E8: b           L_801138F4
    // 0x801138EC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
        goto L_801138F4;
    // 0x801138EC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801138F0: lbu         $a3, 0x24($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X24);
L_801138F4:
    // 0x801138F4: bnel        $a3, $a2, L_80113910
    if (ctx->r7 != ctx->r6) {
        // 0x801138F8: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80113910;
    }
    goto skip_2;
    // 0x801138F8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_2:
    // 0x801138FC: lb          $t8, 0x2B($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X2B);
    // 0x80113900: beql        $t3, $t8, L_80113910
    if (ctx->r11 == ctx->r24) {
        // 0x80113904: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_80113910;
    }
    goto skip_3;
    // 0x80113904: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    skip_3:
    // 0x80113908: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8011390C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80113910:
    // 0x80113910: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80113914: bne         $at, $zero, L_801138C0
    if (ctx->r1 != 0) {
        // 0x80113918: addiu       $v1, $v1, 0x74
        ctx->r3 = ADD32(ctx->r3, 0X74);
            goto L_801138C0;
    }
    // 0x80113918: addiu       $v1, $v1, 0x74
    ctx->r3 = ADD32(ctx->r3, 0X74);
    // 0x8011391C: bne         $t0, $zero, L_80113A38
    if (ctx->r8 != 0) {
        // 0x80113920: sw          $a3, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r7;
            goto L_80113A38;
    }
    // 0x80113920: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80113924: lbu         $v0, 0x2($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X2);
    // 0x80113928: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8011392C: addiu       $v1, $v1, 0x17F4
    ctx->r3 = ADD32(ctx->r3, 0X17F4);
    // 0x80113930: beq         $v0, $zero, L_80113948
    if (ctx->r2 == 0) {
        // 0x80113934: sll         $t4, $a2, 3
        ctx->r12 = S32(ctx->r6 << 3);
            goto L_80113948;
    }
    // 0x80113934: sll         $t4, $a2, 3
    ctx->r12 = S32(ctx->r6 << 3);
    // 0x80113938: beq         $v0, $t2, L_80113968
    if (ctx->r2 == ctx->r10) {
        // 0x8011393C: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80113968;
    }
    // 0x8011393C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80113940: b           L_80113A1C
    // 0x80113944: addiu       $v1, $v1, 0x17F4
    ctx->r3 = ADD32(ctx->r3, 0X17F4);
        goto L_80113A1C;
    // 0x80113944: addiu       $v1, $v1, 0x17F4
    ctx->r3 = ADD32(ctx->r3, 0X17F4);
L_80113948:
    // 0x80113948: subu        $t4, $t4, $a2
    ctx->r12 = SUB32(ctx->r12, ctx->r6);
    // 0x8011394C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80113950: addu        $t4, $t4, $a2
    ctx->r12 = ADD32(ctx->r12, ctx->r6);
    // 0x80113954: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x80113958: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8011395C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x80113960: b           L_80113A1C
    // 0x80113964: sb          $t9, 0x2D($t5)
    MEM_B(0X2D, ctx->r13) = ctx->r25;
        goto L_80113A1C;
    // 0x80113964: sb          $t9, 0x2D($t5)
    MEM_B(0X2D, ctx->r13) = ctx->r25;
L_80113968:
    // 0x80113968: lbu         $t6, 0x22($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0X22);
    // 0x8011396C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80113970: bne         $a0, $t6, L_80113980
    if (ctx->r4 != ctx->r14) {
        // 0x80113974: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80113980;
    }
    // 0x80113974: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80113978: b           L_801139AC
    // 0x8011397C: addiu       $v1, $v1, 0x17F4
    ctx->r3 = ADD32(ctx->r3, 0X17F4);
        goto L_801139AC;
    // 0x8011397C: addiu       $v1, $v1, 0x17F4
    ctx->r3 = ADD32(ctx->r3, 0X17F4);
L_80113980:
    // 0x80113980: lbu         $t7, 0x24($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X24);
    // 0x80113984: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80113988: addiu       $v1, $v1, 0x17F4
    ctx->r3 = ADD32(ctx->r3, 0X17F4);
    // 0x8011398C: bne         $a2, $t7, L_801139A4
    if (ctx->r6 != ctx->r15) {
        // 0x80113990: nop
    
            goto L_801139A4;
    }
    // 0x80113990: nop

    // 0x80113994: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80113998: sb          $t8, 0x2D($v0)
    MEM_B(0X2D, ctx->r2) = ctx->r24;
    // 0x8011399C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801139A0: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
L_801139A4:
    // 0x801139A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801139A8: addiu       $v1, $v1, 0x17F4
    ctx->r3 = ADD32(ctx->r3, 0X17F4);
L_801139AC:
    // 0x801139AC: lbu         $t4, 0x96($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X96);
    // 0x801139B0: beql        $a0, $t4, L_801139D8
    if (ctx->r4 == ctx->r12) {
        // 0x801139B4: lbu         $t6, 0x10A($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X10A);
            goto L_801139D8;
    }
    goto skip_4;
    // 0x801139B4: lbu         $t6, 0x10A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10A);
    skip_4:
    // 0x801139B8: lbu         $t9, 0x98($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X98);
    // 0x801139BC: bnel        $a2, $t9, L_801139D8
    if (ctx->r6 != ctx->r25) {
        // 0x801139C0: lbu         $t6, 0x10A($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X10A);
            goto L_801139D8;
    }
    goto skip_5;
    // 0x801139C0: lbu         $t6, 0x10A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10A);
    skip_5:
    // 0x801139C4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801139C8: sb          $t5, 0xA1($v0)
    MEM_B(0XA1, ctx->r2) = ctx->r13;
    // 0x801139CC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801139D0: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x801139D4: lbu         $t6, 0x10A($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10A);
L_801139D8:
    // 0x801139D8: beql        $a0, $t6, L_80113A00
    if (ctx->r4 == ctx->r14) {
        // 0x801139DC: lbu         $t4, 0x17E($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X17E);
            goto L_80113A00;
    }
    goto skip_6;
    // 0x801139DC: lbu         $t4, 0x17E($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X17E);
    skip_6:
    // 0x801139E0: lbu         $t7, 0x10C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X10C);
    // 0x801139E4: bnel        $a2, $t7, L_80113A00
    if (ctx->r6 != ctx->r15) {
        // 0x801139E8: lbu         $t4, 0x17E($v0)
        ctx->r12 = MEM_BU(ctx->r2, 0X17E);
            goto L_80113A00;
    }
    goto skip_7;
    // 0x801139E8: lbu         $t4, 0x17E($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X17E);
    skip_7:
    // 0x801139EC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x801139F0: sb          $t8, 0x115($v0)
    MEM_B(0X115, ctx->r2) = ctx->r24;
    // 0x801139F4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801139F8: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x801139FC: lbu         $t4, 0x17E($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X17E);
L_80113A00:
    // 0x80113A00: beql        $a0, $t4, L_80113A20
    if (ctx->r4 == ctx->r12) {
        // 0x80113A04: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80113A20;
    }
    goto skip_8;
    // 0x80113A04: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_8:
    // 0x80113A08: lbu         $t9, 0x180($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X180);
    // 0x80113A0C: bnel        $a2, $t9, L_80113A20
    if (ctx->r6 != ctx->r25) {
        // 0x80113A10: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_80113A20;
    }
    goto skip_9;
    // 0x80113A10: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_9:
    // 0x80113A14: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80113A18: sb          $t5, 0x189($v0)
    MEM_B(0X189, ctx->r2) = ctx->r13;
L_80113A1C:
    // 0x80113A1C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_80113A20:
    // 0x80113A20: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80113A24: bne         $t7, $zero, L_80113A38
    if (ctx->r15 != 0) {
        // 0x80113A28: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80113A38;
    }
    // 0x80113A28: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80113A2C: jal         0x80114C80
    // 0x80113A30: nop

    ifCommonAnnounceEndMessage(rdram, ctx);
        goto after_0;
    // 0x80113A30: nop

    after_0:
    // 0x80113A34: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80113A38:
    // 0x80113A38: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80113A3C: addiu       $v1, $v1, 0x17F4
    ctx->r3 = ADD32(ctx->r3, 0X17F4);
    // 0x80113A40: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80113A44: beql        $t4, $zero, L_80113A9C
    if (ctx->r12 == 0) {
        // 0x80113A48: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80113A9C;
    }
    goto skip_10;
    // 0x80113A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x80113A4C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80113A50: lb          $t5, 0x14($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X14);
    // 0x80113A54: bnel        $t3, $t5, L_80113A9C
    if (ctx->r11 != ctx->r13) {
        // 0x80113A58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80113A9C;
    }
    goto skip_11;
    // 0x80113A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x80113A5C: lw          $t6, 0x20($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X20);
    // 0x80113A60: bne         $t6, $zero, L_80113A88
    if (ctx->r14 != 0) {
        // 0x80113A64: nop
    
            goto L_80113A88;
    }
    // 0x80113A64: nop

    // 0x80113A68: lbu         $t7, 0xD($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0XD);
    // 0x80113A6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80113A70: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80113A74: addu        $a0, $a0, $t8
    ctx->r4 = ADD32(ctx->r4, ctx->r24);
    // 0x80113A78: jal         0x801650F8
    // 0x80113A7C: lhu         $a0, -0xE7C($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0XE7C);
    ftPublicDefeatedAddID(rdram, ctx);
        goto after_1;
    // 0x80113A7C: lhu         $a0, -0xE7C($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0XE7C);
    after_1:
    // 0x80113A80: b           L_80113A90
    // 0x80113A84: nop

        goto L_80113A90;
    // 0x80113A84: nop

L_80113A88:
    // 0x80113A88: jal         0x801650F8
    // 0x80113A8C: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    ftPublicDefeatedAddID(rdram, ctx);
        goto after_2;
    // 0x80113A8C: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    after_2:
L_80113A90:
    // 0x80113A90: jal         0x801650F8
    // 0x80113A94: addiu       $a0, $zero, 0x1FF
    ctx->r4 = ADD32(0, 0X1FF);
    ftPublicDefeatedAddID(rdram, ctx);
        goto after_3;
    // 0x80113A94: addiu       $a0, $zero, 0x1FF
    ctx->r4 = ADD32(0, 0X1FF);
    after_3:
    // 0x80113A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80113A9C:
    // 0x80113A9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80113AA0: jr          $ra
    // 0x80113AA4: nop

    return;
    // 0x80113AA4: nop

;}
RECOMP_FUNC void mvOpeningLinkInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DE40: jr          $ra
    // 0x8018DE44: sw          $zero, -0x1E38($at)
    MEM_W(-0X1E38, ctx->r1) = 0;
    return;
    // 0x8018DE44: sw          $zero, -0x1E38($at)
    MEM_W(-0X1E38, ctx->r1) = 0;
;}

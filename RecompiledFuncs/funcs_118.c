#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void syMatrixRotD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D2F4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D2F8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D2FC: lwc1        $f4, -0x1C38($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1C38);
    // 0x8001D300: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D304: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001D308: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8001D30C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001D310: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D314: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001D318: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001D31C: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8001D320: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D324: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001D328: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001D32C: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001D330: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    // 0x8001D334: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8001D338: jal         0x8001BA78
    // 0x8001D33C: nop

    syMatrixRotRF(rdram, ctx);
        goto after_0;
    // 0x8001D33C: nop

    after_0:
    // 0x8001D340: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001D344: jal         0x80019EA0
    // 0x8001D348: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001D348: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x8001D34C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001D350: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8001D354: jr          $ra
    // 0x8001D358: nop

    return;
    // 0x8001D358: nop

;}
RECOMP_FUNC void itMSBombMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176F60: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80176F64: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80176F68: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80176F6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80176F70: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80176F74: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80176F78: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80176F7C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80176F80: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80176F84: addiu       $a1, $a1, -0x61B0
    ctx->r5 = ADD32(ctx->r5, -0X61B0);
    // 0x80176F88: jal         0x8016E174
    // 0x80176F8C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80176F8C: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80176F90: beq         $v0, $zero, L_8017704C
    if (ctx->r2 == 0) {
        // 0x80176F94: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_8017704C;
    }
    // 0x80176F94: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80176F98: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x80176F9C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80176FA0: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x80176FA4: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x80176FA8: addiu       $v0, $s0, 0x1C
    ctx->r2 = ADD32(ctx->r16, 0X1C);
    // 0x80176FAC: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80176FB0: sb          $t7, 0x54($t8)
    MEM_B(0X54, ctx->r24) = ctx->r15;
    // 0x80176FB4: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x80176FB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80176FBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80176FC0: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x80176FC4: sb          $zero, 0x54($t0)
    MEM_B(0X54, ctx->r8) = 0;
    // 0x80176FC8: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80176FCC: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x80176FD0: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x80176FD4: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x80176FD8: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80176FDC: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    // 0x80176FE0: jal         0x80008CC0
    // 0x80176FE4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80176FE4: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80176FE8: lw          $t4, 0x10($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X10);
    // 0x80176FEC: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x80176FF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80176FF4: jal         0x80008CC0
    // 0x80176FF8: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80176FF8: lw          $a0, 0x8($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X8);
    after_2:
    // 0x80176FFC: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80177000: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80177004: lw          $t5, 0x2C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X2C);
    // 0x80177008: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x8017700C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80177010: sw          $t7, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r15;
    // 0x80177014: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80177018: sw          $t8, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r24;
    // 0x8017701C: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80177020: lw          $a0, 0x84($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X84);
    // 0x80177024: lbu         $t1, 0x2D3($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X2D3);
    // 0x80177028: sh          $zero, 0x33E($a0)
    MEM_H(0X33E, ctx->r4) = 0;
    // 0x8017702C: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x80177030: sb          $t2, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r10;
    // 0x80177034: jal         0x80111EC0
    // 0x80177038: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_3;
    // 0x80177038: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    after_3:
    // 0x8017703C: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80177040: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80177044: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
    // 0x80177048: swc1        $f4, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f4.u32l;
L_8017704C:
    // 0x8017704C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80177050: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80177054: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80177058: jr          $ra
    // 0x8017705C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8017705C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnCharactersBackupFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013366C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133674: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133678: jal         0x80131B58
    // 0x8013367C: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x8013367C: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    after_0:
    // 0x80133680: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80133684: jal         0x800D45F4
    // 0x80133688: sb          $v0, 0x4936($at)
    MEM_B(0X4936, ctx->r1) = ctx->r2;
    lbBackupWrite(rdram, ctx);
        goto after_1;
    // 0x80133688: sb          $v0, 0x4936($at)
    MEM_B(0X4936, ctx->r1) = ctx->r2;
    after_1:
    // 0x8013368C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133690: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133694: jr          $ra
    // 0x80133698: nop

    return;
    // 0x80133698: nop

;}
RECOMP_FUNC void mnItemSwitchMakeSubtitle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F30: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80131F34: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131F38: addiu       $t7, $t7, 0x3298
    ctx->r15 = ADD32(ctx->r15, 0X3298);
    // 0x80131F3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131F40: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80131F44: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80131F48: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
L_80131F4C:
    // 0x80131F4C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131F50: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131F54: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131F58: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80131F5C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80131F60: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80131F64: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80131F68: bne         $t7, $t0, L_80131F4C
    if (ctx->r15 != ctx->r8) {
        // 0x80131F6C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80131F4C;
    }
    // 0x80131F6C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80131F70: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131F74: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131F78: addiu       $t2, $t2, 0x32D8
    ctx->r10 = ADD32(ctx->r10, 0X32D8);
    // 0x80131F7C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131F80: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80131F84: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131F88: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
    // 0x80131F8C: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x80131F90: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80131F94: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x80131F98: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x80131F9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FA0: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x80131FA4: sw          $t3, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r11;
    // 0x80131FA8: lw          $t3, 0x14($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X14);
    // 0x80131FAC: lw          $t4, 0x10($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X10);
    // 0x80131FB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FB4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131FB8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80131FBC: sw          $t3, 0x14($t1)
    MEM_W(0X14, ctx->r9) = ctx->r11;
    // 0x80131FC0: jal         0x80009968
    // 0x80131FC4: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131FC4: sw          $t4, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r12;
    after_0:
    // 0x80131FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131FCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131FD0: sw          $v0, 0x33DC($at)
    MEM_W(0X33DC, ctx->r1) = ctx->r2;
    // 0x80131FD4: jr          $ra
    // 0x80131FD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80131FD8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void gmCollisionSetInvertMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED6EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ED6F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ED6F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ED6F8: lwc1        $f4, 0x14($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800ED6FC: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800ED700: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800ED704: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800ED708: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED70C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800ED710: addiu       $s0, $s0, 0x1E0
    ctx->r16 = ADD32(ctx->r16, 0X1E0);
    // 0x800ED714: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800ED718: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800ED71C: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800ED720: swc1        $f6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f6.u32l;
    // 0x800ED724: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800ED728: lwc1        $f18, 0x28($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800ED72C: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800ED730: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800ED734: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800ED738: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800ED73C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED740: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ED744: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x800ED748: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800ED74C: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800ED750: lwc1        $f18, 0x14($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800ED754: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800ED758: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED75C: lwc1        $f2, 0x10($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800ED760: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800ED764: lwc1        $f18, 0x0($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800ED768: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800ED76C: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x800ED770: lwc1        $f10, 0x30($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800ED774: lwc1        $f4, 0x34($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800ED778: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800ED77C: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800ED780: lwc1        $f12, 0x20($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800ED784: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED788: lwc1        $f6, 0x38($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800ED78C: lwc1        $f4, 0x20($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800ED790: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ED794: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED798: add.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800ED79C: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x800ED7A0: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED7A4: lwc1        $f6, 0x28($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800ED7A8: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED7AC: lwc1        $f18, 0x24($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800ED7B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED7B4: nop

    // 0x800ED7B8: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800ED7BC: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800ED7C0: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x800ED7C4: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED7C8: lwc1        $f10, 0x28($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X28);
    // 0x800ED7CC: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED7D0: lwc1        $f4, 0x20($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800ED7D4: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800ED7D8: nop

    // 0x800ED7DC: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED7E0: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800ED7E4: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800ED7E8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED7EC: lwc1        $f6, 0x24($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X24);
    // 0x800ED7F0: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED7F4: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800ED7F8: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED7FC: nop

    // 0x800ED800: mul.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800ED804: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800ED808: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800ED80C: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x800ED810: lwc1        $f18, 0x30($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800ED814: lwc1        $f4, 0x34($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800ED818: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800ED81C: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800ED820: nop

    // 0x800ED824: mul.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED828: lwc1        $f6, 0x38($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800ED82C: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800ED830: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800ED834: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED838: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800ED83C: swc1        $f18, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f18.u32l;
    // 0x800ED840: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED844: lwc1        $f6, 0x18($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800ED848: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED84C: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800ED850: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED854: nop

    // 0x800ED858: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800ED85C: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800ED860: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
    // 0x800ED864: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED868: lwc1        $f18, 0x18($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800ED86C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED870: lwc1        $f4, 0x10($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800ED874: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800ED878: nop

    // 0x800ED87C: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED880: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800ED884: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800ED888: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED88C: lwc1        $f6, 0x14($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800ED890: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED894: lwc1        $f10, 0x10($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X10);
    // 0x800ED898: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED89C: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800ED8A0: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800ED8A4: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800ED8A8: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x800ED8AC: lwc1        $f18, 0x38($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800ED8B0: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800ED8B4: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x800ED8B8: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800ED8BC: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800ED8C0: lwc1        $f18, 0x34($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X34);
    // 0x800ED8C4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED8C8: nop

    // 0x800ED8CC: mul.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800ED8D0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800ED8D4: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800ED8D8: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
    // 0x800ED8DC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED8E0: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED8E4: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800ED8E8: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED8EC: mul.s       $f6, $f8, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800ED8F0: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800ED8F4: mul.s       $f8, $f12, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800ED8F8: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800ED8FC: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x800ED900: swc1        $f4, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f4.u32l;
    // 0x800ED904: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800ED908: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800ED90C: add.s       $f0, $f8, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800ED910: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800ED914: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x800ED918: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800ED91C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800ED920: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x800ED924: lwc1        $f8, 0x38($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800ED928: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800ED92C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800ED930: neg.s       $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = -ctx->f16.fl;
    // 0x800ED934: neg.s       $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = -ctx->f8.fl;
    // 0x800ED938: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x800ED93C: swc1        $f10, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f10.u32l;
    // 0x800ED940: bc1f        L_800ED960
    if (!c1cs) {
        // 0x800ED944: swc1        $f18, 0x38($a0)
        MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
            goto L_800ED960;
    }
    // 0x800ED944: swc1        $f18, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f18.u32l;
L_800ED948:
    // 0x800ED948: jal         0x80023624
    // 0x800ED94C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800ED94C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800ED950: jal         0x800A3040
    // 0x800ED954: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800ED954: nop

    after_1:
    // 0x800ED958: b           L_800ED948
    // 0x800ED95C: nop

        goto L_800ED948;
    // 0x800ED95C: nop

L_800ED960:
    // 0x800ED960: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800ED964: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800ED968: div.s       $f0, $f6, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED96C: lwc1        $f6, 0x30($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800ED970: mul.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800ED974: nop

    // 0x800ED978: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800ED97C: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800ED980: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x800ED984: swc1        $f10, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f10.u32l;
    // 0x800ED988: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED98C: swc1        $f18, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f18.u32l;
    // 0x800ED990: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800ED994: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800ED998: lwc1        $f4, 0x14($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800ED99C: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x800ED9A0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800ED9A4: lwc1        $f10, 0x24($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800ED9A8: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x800ED9AC: lwc1        $f18, 0x34($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800ED9B0: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ED9B4: nop

    // 0x800ED9B8: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800ED9BC: swc1        $f6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f6.u32l;
    // 0x800ED9C0: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800ED9C4: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
    // 0x800ED9C8: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800ED9CC: lwc1        $f8, 0x18($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800ED9D0: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x800ED9D4: lwc1        $f4, 0x28($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800ED9D8: mul.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800ED9DC: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x800ED9E0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800ED9E4: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800ED9E8: swc1        $f18, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->f18.u32l;
    // 0x800ED9EC: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800ED9F0: swc1        $f6, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f6.u32l;
    // 0x800ED9F4: swc1        $f8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f8.u32l;
    // 0x800ED9F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800ED9FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EDA00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800EDA04: jr          $ra
    // 0x800EDA08: nop

    return;
    // 0x800EDA08: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiEndBackupVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801535C4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801535C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801535CC: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x801535D0: lwc1        $f6, 0x4C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x801535D4: lwc1        $f8, 0x60($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X60);
    // 0x801535D8: swc1        $f4, 0xB30($v0)
    MEM_W(0XB30, ctx->r2) = ctx->f4.u32l;
    // 0x801535DC: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x801535E0: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x801535E4: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
    // 0x801535E8: swc1        $f6, 0xB34($v0)
    MEM_W(0XB34, ctx->r2) = ctx->f6.u32l;
    // 0x801535EC: jr          $ra
    // 0x801535F0: swc1        $f8, 0xB38($v0)
    MEM_W(0XB38, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x801535F0: swc1        $f8, 0xB38($v0)
    MEM_W(0XB38, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeSpotlightFadeCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133474: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133478: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013347C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133480: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133484: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80133488: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013348C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80133490: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133494: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133498: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013349C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801334A0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801334A4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801334A8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801334AC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801334B0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801334B4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801334B8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801334BC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801334C0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801334C4: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801334C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801334CC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801334D0: jal         0x8000B93C
    // 0x801334D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801334D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801334D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801334DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801334E0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801334E4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801334E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801334EC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801334F0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801334F4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801334F8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801334FC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80133500: jal         0x80007080
    // 0x80133504: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133504: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133508: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8013350C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80133510: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x80133514: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133518: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8013351C: jr          $ra
    // 0x80133520: nop

    return;
    // 0x80133520: nop

;}
RECOMP_FUNC void wpFoxBlasterProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168964: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80168968: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016896C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x80168970: jal         0x80103320
    // 0x80168974: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerFoxBlasterGlowMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80168974: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x80168978: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016897C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80168980: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80168984: jr          $ra
    // 0x80168988: nop

    return;
    // 0x80168988: nop

;}
RECOMP_FUNC void sySchedulerUpdateViMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000F30: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80000F34: sltiu       $at, $a0, 0x141
    ctx->r1 = ctx->r4 < 0X141 ? 1 : 0;
    // 0x80000F38: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80000F3C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80000F40: beq         $at, $zero, L_80000F54
    if (ctx->r1 == 0) {
        // 0x80000F44: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_80000F54;
    }
    // 0x80000F44: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80000F48: sltiu       $at, $a1, 0xF1
    ctx->r1 = ctx->r5 < 0XF1 ? 1 : 0;
    // 0x80000F4C: bne         $at, $zero, L_80000F5C
    if (ctx->r1 != 0) {
        // 0x80000F50: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80000F5C;
    }
    // 0x80000F50: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_80000F54:
    // 0x80000F54: b           L_80000F5C
    // 0x80000F58: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
        goto L_80000F5C;
    // 0x80000F58: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_80000F5C:
    // 0x80000F5C: andi        $t8, $a2, 0x4
    ctx->r24 = ctx->r6 & 0X4;
    // 0x80000F60: beq         $t8, $zero, L_80000F8C
    if (ctx->r24 == 0) {
        // 0x80000F64: lui         $v0, 0x8004
        ctx->r2 = S32(0X8004 << 16);
            goto L_80000F8C;
    }
    // 0x80000F64: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000F68: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000F6C: addiu       $a0, $a0, 0x4FBC
    ctx->r4 = ADD32(ctx->r4, 0X4FBC);
    // 0x80000F70: addiu       $v0, $v0, 0x4F38
    ctx->r2 = ADD32(ctx->r2, 0X4F38);
    // 0x80000F74: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80000F78: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80000F7C: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x80000F80: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x80000F84: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x80000F88: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80000F8C:
    // 0x80000F8C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000F90: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000F94: andi        $t6, $a2, 0x8
    ctx->r14 = ctx->r6 & 0X8;
    // 0x80000F98: addiu       $a0, $a0, 0x4FBC
    ctx->r4 = ADD32(ctx->r4, 0X4FBC);
    // 0x80000F9C: beq         $t6, $zero, L_80000FC0
    if (ctx->r14 == 0) {
        // 0x80000FA0: addiu       $v0, $v0, 0x4F38
        ctx->r2 = ADD32(ctx->r2, 0X4F38);
            goto L_80000FC0;
    }
    // 0x80000FA0: addiu       $v0, $v0, 0x4F38
    ctx->r2 = ADD32(ctx->r2, 0X4F38);
    // 0x80000FA4: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80000FA8: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80000FAC: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80000FB0: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x80000FB4: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x80000FB8: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x80000FBC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80000FC0:
    // 0x80000FC0: andi        $t7, $a2, 0x10
    ctx->r15 = ctx->r6 & 0X10;
    // 0x80000FC4: beql        $t7, $zero, L_80000FF4
    if (ctx->r15 == 0) {
        // 0x80000FC8: andi        $t6, $a2, 0x20
        ctx->r14 = ctx->r6 & 0X20;
            goto L_80000FF4;
    }
    goto skip_0;
    // 0x80000FC8: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
    skip_0:
    // 0x80000FCC: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x80000FD0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80000FD4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80000FD8: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x80000FDC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80000FE0: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x80000FE4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80000FE8: ori         $t9, $t7, 0x2
    ctx->r25 = ctx->r15 | 0X2;
    // 0x80000FEC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80000FF0: andi        $t6, $a2, 0x20
    ctx->r14 = ctx->r6 & 0X20;
L_80000FF4:
    // 0x80000FF4: beql        $t6, $zero, L_80001024
    if (ctx->r14 == 0) {
        // 0x80000FF8: andi        $t6, $a2, 0x40
        ctx->r14 = ctx->r6 & 0X40;
            goto L_80001024;
    }
    goto skip_1;
    // 0x80000FF8: andi        $t6, $a2, 0x40
    ctx->r14 = ctx->r6 & 0X40;
    skip_1:
    // 0x80000FFC: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x80001000: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80001004: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80001008: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8000100C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80001010: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x80001014: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80001018: ori         $t9, $t7, 0x3
    ctx->r25 = ctx->r15 | 0X3;
    // 0x8000101C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80001020: andi        $t6, $a2, 0x40
    ctx->r14 = ctx->r6 & 0X40;
L_80001024:
    // 0x80001024: beql        $t6, $zero, L_80001048
    if (ctx->r14 == 0) {
        // 0x80001028: andi        $t8, $a2, 0x80
        ctx->r24 = ctx->r6 & 0X80;
            goto L_80001048;
    }
    goto skip_2;
    // 0x80001028: andi        $t8, $a2, 0x80
    ctx->r24 = ctx->r6 & 0X80;
    skip_2:
    // 0x8000102C: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x80001030: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80001034: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x80001038: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x8000103C: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x80001040: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80001044: andi        $t8, $a2, 0x80
    ctx->r24 = ctx->r6 & 0X80;
L_80001048:
    // 0x80001048: beql        $t8, $zero, L_80001070
    if (ctx->r24 == 0) {
        // 0x8000104C: andi        $t9, $a2, 0x1000
        ctx->r25 = ctx->r6 & 0X1000;
            goto L_80001070;
    }
    goto skip_3;
    // 0x8000104C: andi        $t9, $a2, 0x1000
    ctx->r25 = ctx->r6 & 0X1000;
    skip_3:
    // 0x80001050: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x80001054: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80001058: addiu       $at, $zero, -0x9
    ctx->r1 = ADD32(0, -0X9);
    // 0x8000105C: andi        $t6, $t9, 0xFFEF
    ctx->r14 = ctx->r25 & 0XFFEF;
    // 0x80001060: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x80001064: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x80001068: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000106C: andi        $t9, $a2, 0x1000
    ctx->r25 = ctx->r6 & 0X1000;
L_80001070:
    // 0x80001070: beql        $t9, $zero, L_80001094
    if (ctx->r25 == 0) {
        // 0x80001074: andi        $t7, $a2, 0x2000
        ctx->r15 = ctx->r6 & 0X2000;
            goto L_80001094;
    }
    goto skip_4;
    // 0x80001074: andi        $t7, $a2, 0x2000
    ctx->r15 = ctx->r6 & 0X2000;
    skip_4:
    // 0x80001078: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8000107C: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80001080: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x80001084: ori         $t6, $t9, 0x4
    ctx->r14 = ctx->r25 | 0X4;
    // 0x80001088: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x8000108C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80001090: andi        $t7, $a2, 0x2000
    ctx->r15 = ctx->r6 & 0X2000;
L_80001094:
    // 0x80001094: beql        $t7, $zero, L_800010BC
    if (ctx->r15 == 0) {
        // 0x80001098: andi        $t8, $a2, 0x4000
        ctx->r24 = ctx->r6 & 0X4000;
            goto L_800010BC;
    }
    goto skip_5;
    // 0x80001098: andi        $t8, $a2, 0x4000
    ctx->r24 = ctx->r6 & 0X4000;
    skip_5:
    // 0x8000109C: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800010A0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800010A4: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800010A8: andi        $t9, $t8, 0xFFFD
    ctx->r25 = ctx->r24 & 0XFFFD;
    // 0x800010AC: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x800010B0: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x800010B4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800010B8: andi        $t8, $a2, 0x4000
    ctx->r24 = ctx->r6 & 0X4000;
L_800010BC:
    // 0x800010BC: beql        $t8, $zero, L_800010E4
    if (ctx->r24 == 0) {
        // 0x800010C0: andi        $t6, $a2, 0x8000
        ctx->r14 = ctx->r6 & 0X8000;
            goto L_800010E4;
    }
    goto skip_6;
    // 0x800010C0: andi        $t6, $a2, 0x8000
    ctx->r14 = ctx->r6 & 0X8000;
    skip_6:
    // 0x800010C4: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800010C8: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800010CC: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800010D0: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x800010D4: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800010D8: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x800010DC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800010E0: andi        $t6, $a2, 0x8000
    ctx->r14 = ctx->r6 & 0X8000;
L_800010E4:
    // 0x800010E4: beql        $t6, $zero, L_80001110
    if (ctx->r14 == 0) {
        // 0x800010E8: sll         $t7, $a2, 15
        ctx->r15 = S32(ctx->r6 << 15);
            goto L_80001110;
    }
    goto skip_7;
    // 0x800010E8: sll         $t7, $a2, 15
    ctx->r15 = S32(ctx->r6 << 15);
    skip_7:
    // 0x800010EC: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x800010F0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x800010F4: lui         $at, 0xFFFE
    ctx->r1 = S32(0XFFFE << 16);
    // 0x800010F8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800010FC: andi        $t8, $t7, 0xFFFE
    ctx->r24 = ctx->r15 & 0XFFFE;
    // 0x80001100: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x80001104: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x80001108: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000110C: sll         $t7, $a2, 15
    ctx->r15 = S32(ctx->r6 << 15);
L_80001110:
    // 0x80001110: bgezl       $t7, L_80001134
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80001114: sll         $t9, $a2, 14
        ctx->r25 = S32(ctx->r6 << 14);
            goto L_80001134;
    }
    goto skip_8;
    // 0x80001114: sll         $t9, $a2, 14
    ctx->r25 = S32(ctx->r6 << 14);
    skip_8:
    // 0x80001118: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8000111C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80001120: ori         $t6, $t9, 0x80
    ctx->r14 = ctx->r25 | 0X80;
    // 0x80001124: ori         $t8, $t7, 0x10
    ctx->r24 = ctx->r15 | 0X10;
    // 0x80001128: sb          $t6, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r14;
    // 0x8000112C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80001130: sll         $t9, $a2, 14
    ctx->r25 = S32(ctx->r6 << 14);
L_80001134:
    // 0x80001134: bgezl       $t9, L_8000115C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80001138: andi        $t6, $a2, 0x100
        ctx->r14 = ctx->r6 & 0X100;
            goto L_8000115C;
    }
    goto skip_9;
    // 0x80001138: andi        $t6, $a2, 0x100
    ctx->r14 = ctx->r6 & 0X100;
    skip_9:
    // 0x8000113C: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x80001140: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80001144: addiu       $at, $zero, -0x11
    ctx->r1 = ADD32(0, -0X11);
    // 0x80001148: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x8000114C: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80001150: sb          $t7, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r15;
    // 0x80001154: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80001158: andi        $t6, $a2, 0x100
    ctx->r14 = ctx->r6 & 0X100;
L_8000115C:
    // 0x8000115C: beql        $t6, $zero, L_80001174
    if (ctx->r14 == 0) {
        // 0x80001160: andi        $t6, $a2, 0x200
        ctx->r14 = ctx->r6 & 0X200;
            goto L_80001174;
    }
    goto skip_10;
    // 0x80001160: andi        $t6, $a2, 0x200
    ctx->r14 = ctx->r6 & 0X200;
    skip_10:
    // 0x80001164: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x80001168: ori         $t9, $t8, 0x8
    ctx->r25 = ctx->r24 | 0X8;
    // 0x8000116C: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
    // 0x80001170: andi        $t6, $a2, 0x200
    ctx->r14 = ctx->r6 & 0X200;
L_80001174:
    // 0x80001174: beq         $t6, $zero, L_80001188
    if (ctx->r14 == 0) {
        // 0x80001178: andi        $t9, $a2, 0x400
        ctx->r25 = ctx->r6 & 0X400;
            goto L_80001188;
    }
    // 0x80001178: andi        $t9, $a2, 0x400
    ctx->r25 = ctx->r6 & 0X400;
    // 0x8000117C: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x80001180: andi        $t8, $t7, 0xFFF7
    ctx->r24 = ctx->r15 & 0XFFF7;
    // 0x80001184: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
L_80001188:
    // 0x80001188: beql        $t9, $zero, L_800011A0
    if (ctx->r25 == 0) {
        // 0x8000118C: andi        $t9, $a2, 0x800
        ctx->r25 = ctx->r6 & 0X800;
            goto L_800011A0;
    }
    goto skip_11;
    // 0x8000118C: andi        $t9, $a2, 0x800
    ctx->r25 = ctx->r6 & 0X800;
    skip_11:
    // 0x80001190: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80001194: ori         $t8, $t6, 0x4
    ctx->r24 = ctx->r14 | 0X4;
    // 0x80001198: sb          $t8, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r24;
    // 0x8000119C: andi        $t9, $a2, 0x800
    ctx->r25 = ctx->r6 & 0X800;
L_800011A0:
    // 0x800011A0: beq         $t9, $zero, L_800011B4
    if (ctx->r25 == 0) {
        // 0x800011A4: andi        $t8, $a2, 0x1
        ctx->r24 = ctx->r6 & 0X1;
            goto L_800011B4;
    }
    // 0x800011A4: andi        $t8, $a2, 0x1
    ctx->r24 = ctx->r6 & 0X1;
    // 0x800011A8: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800011AC: andi        $t7, $t6, 0xFFFB
    ctx->r15 = ctx->r14 & 0XFFFB;
    // 0x800011B0: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_800011B4:
    // 0x800011B4: beql        $t8, $zero, L_800011D0
    if (ctx->r24 == 0) {
        // 0x800011B8: andi        $t8, $a2, 0x2
        ctx->r24 = ctx->r6 & 0X2;
            goto L_800011D0;
    }
    goto skip_12;
    // 0x800011B8: andi        $t8, $a2, 0x2
    ctx->r24 = ctx->r6 & 0X2;
    skip_12:
    // 0x800011BC: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800011C0: andi        $t6, $t9, 0xFF7F
    ctx->r14 = ctx->r25 & 0XFF7F;
    // 0x800011C4: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x800011C8: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x800011CC: andi        $t8, $a2, 0x2
    ctx->r24 = ctx->r6 & 0X2;
L_800011D0:
    // 0x800011D0: beql        $t8, $zero, L_800011E8
    if (ctx->r24 == 0) {
        // 0x800011D4: lw          $t7, 0x4($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X4);
            goto L_800011E8;
    }
    goto skip_13;
    // 0x800011D4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    skip_13:
    // 0x800011D8: lbu         $t9, 0x0($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X0);
    // 0x800011DC: andi        $t6, $t9, 0xFF7F
    ctx->r14 = ctx->r25 & 0XFF7F;
    // 0x800011E0: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
    // 0x800011E4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
L_800011E8:
    // 0x800011E8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800011EC: addiu       $at, $zero, -0x301
    ctx->r1 = ADD32(0, -0X301);
    // 0x800011F0: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800011F4: srl         $t9, $v1, 31
    ctx->r25 = S32(U32(ctx->r3) >> 31);
    // 0x800011F8: beq         $t9, $zero, L_80001238
    if (ctx->r25 == 0) {
        // 0x800011FC: sw          $t8, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r24;
            goto L_80001238;
    }
    // 0x800011FC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80001200: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80001204: sll         $t1, $v1, 5
    ctx->r9 = S32(ctx->r3 << 5);
    // 0x80001208: srl         $t1, $t1, 31
    ctx->r9 = S32(U32(ctx->r9) >> 31);
    // 0x8000120C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80001210: beq         $t7, $zero, L_80001220
    if (ctx->r15 == 0) {
        // 0x80001214: addiu       $a0, $zero, 0x100
        ctx->r4 = ADD32(0, 0X100);
            goto L_80001220;
    }
    // 0x80001214: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80001218: b           L_80001220
    // 0x8000121C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80001220;
    // 0x8000121C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80001220:
    // 0x80001220: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80001224: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80001228: srl         $t0, $t0, 31
    ctx->r8 = S32(U32(ctx->r8) >> 31);
    // 0x8000122C: or          $t9, $t8, $a0
    ctx->r25 = ctx->r24 | ctx->r4;
    // 0x80001230: b           L_8000127C
    // 0x80001234: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_8000127C;
    // 0x80001234: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80001238:
    // 0x80001238: sll         $t1, $v1, 5
    ctx->r9 = S32(ctx->r3 << 5);
    // 0x8000123C: srl         $t1, $t1, 31
    ctx->r9 = S32(U32(ctx->r9) >> 31);
    // 0x80001240: bne         $t1, $zero, L_80001268
    if (ctx->r9 != 0) {
        // 0x80001244: sll         $t0, $v1, 2
        ctx->r8 = S32(ctx->r3 << 2);
            goto L_80001268;
    }
    // 0x80001244: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80001248: srl         $t0, $t0, 31
    ctx->r8 = S32(U32(ctx->r8) >> 31);
    // 0x8000124C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001250: bnel        $t0, $at, L_8000126C
    if (ctx->r8 != ctx->r1) {
        // 0x80001254: lw          $t8, 0x4($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X4);
            goto L_8000126C;
    }
    goto skip_14;
    // 0x80001254: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    skip_14:
    // 0x80001258: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8000125C: ori         $t7, $t6, 0x300
    ctx->r15 = ctx->r14 | 0X300;
    // 0x80001260: b           L_8000127C
    // 0x80001264: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
        goto L_8000127C;
    // 0x80001264: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_80001268:
    // 0x80001268: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
L_8000126C:
    // 0x8000126C: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80001270: srl         $t0, $t0, 31
    ctx->r8 = S32(U32(ctx->r8) >> 31);
    // 0x80001274: ori         $t9, $t8, 0x200
    ctx->r25 = ctx->r24 | 0X200;
    // 0x80001278: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8000127C:
    // 0x8000127C: beq         $t2, $zero, L_800012A0
    if (ctx->r10 == 0) {
        // 0x80001280: lh          $a1, 0x4E($sp)
        ctx->r5 = MEM_H(ctx->r29, 0X4E);
            goto L_800012A0;
    }
    // 0x80001280: lh          $a1, 0x4E($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X4E);
    // 0x80001284: sll         $t6, $v1, 1
    ctx->r14 = S32(ctx->r3 << 1);
    // 0x80001288: bgez        $t6, L_80001298
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000128C: nop
    
            goto L_80001298;
    }
    // 0x8000128C: nop

    // 0x80001290: b           L_800012B0
    // 0x80001294: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800012B0;
    // 0x80001294: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80001298:
    // 0x80001298: b           L_800012B0
    // 0x8000129C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800012B0;
    // 0x8000129C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800012A0:
    // 0x800012A0: beq         $t1, $zero, L_800012B0
    if (ctx->r9 == 0) {
        // 0x800012A4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800012B0;
    }
    // 0x800012A4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800012A8: b           L_800012B0
    // 0x800012AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800012B0;
    // 0x800012AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800012B0:
    // 0x800012B0: lh          $a2, 0x52($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X52);
    // 0x800012B4: andi        $a1, $a1, 0xFFFE
    ctx->r5 = ctx->r5 & 0XFFFE;
    // 0x800012B8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800012BC: andi        $a2, $a2, 0xFFFE
    ctx->r6 = ctx->r6 & 0XFFFE;
    // 0x800012C0: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x800012C4: sltiu       $a3, $t2, 0x1
    ctx->r7 = ctx->r10 < 0X1 ? 1 : 0;
    // 0x800012C8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800012CC: beq         $a3, $zero, L_800012EC
    if (ctx->r7 == 0) {
        // 0x800012D0: sra         $a2, $a2, 16
        ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
            goto L_800012EC;
    }
    // 0x800012D0: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800012D4: sltiu       $t8, $v1, 0x1
    ctx->r24 = ctx->r3 < 0X1 ? 1 : 0;
    // 0x800012D8: beql        $t8, $zero, L_800012F0
    if (ctx->r24 == 0) {
        // 0x800012DC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800012F0;
    }
    goto skip_15;
    // 0x800012DC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    skip_15:
    // 0x800012E0: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800012E4: b           L_800012F4
    // 0x800012E8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
        goto L_800012F4;
    // 0x800012E8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
L_800012EC:
    // 0x800012EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_800012F0:
    // 0x800012F0: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
L_800012F4:
    // 0x800012F4: beq         $t2, $zero, L_80001304
    if (ctx->r10 == 0) {
        // 0x800012F8: lw          $t4, 0x3C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X3C);
            goto L_80001304;
    }
    // 0x800012F8: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800012FC: b           L_80001308
    // 0x80001300: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80001308;
    // 0x80001300: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80001304:
    // 0x80001304: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_80001308:
    // 0x80001308: subu        $t7, $a2, $a1
    ctx->r15 = SUB32(ctx->r6, ctx->r5);
    // 0x8000130C: addiu       $t8, $t7, 0x1E0
    ctx->r24 = ADD32(ctx->r15, 0X1E0);
    // 0x80001310: sll         $t4, $t4, 11
    ctx->r12 = S32(ctx->r12 << 11);
    // 0x80001314: divu        $zero, $t4, $t8
    lo = S32(U32(ctx->r12) / U32(ctx->r24)); hi = S32(U32(ctx->r12) % U32(ctx->r24));
    // 0x80001318: mflo        $t9
    ctx->r25 = lo;
    // 0x8000131C: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80001320: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80001324: divu        $zero, $t9, $a0
    lo = S32(U32(ctx->r25) / U32(ctx->r4)); hi = S32(U32(ctx->r25) % U32(ctx->r4));
    // 0x80001328: mflo        $t6
    ctx->r14 = lo;
    // 0x8000132C: bne         $t8, $zero, L_80001338
    if (ctx->r24 != 0) {
        // 0x80001330: nop
    
            goto L_80001338;
    }
    // 0x80001330: nop

    // 0x80001334: break       7
    do_break(2147488564);
L_80001338:
    // 0x80001338: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000133C: bne         $a0, $zero, L_80001348
    if (ctx->r4 != 0) {
        // 0x80001340: nop
    
            goto L_80001348;
    }
    // 0x80001340: nop

    // 0x80001344: break       7
    do_break(2147488580);
L_80001348:
    // 0x80001348: mflo        $t3
    ctx->r11 = lo;
    // 0x8000134C: beql        $a3, $zero, L_80001368
    if (ctx->r7 == 0) {
        // 0x80001350: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80001368;
    }
    goto skip_16;
    // 0x80001350: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_16:
    // 0x80001354: beql        $v1, $zero, L_80001368
    if (ctx->r3 == 0) {
        // 0x80001358: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80001368;
    }
    goto skip_17;
    // 0x80001358: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    skip_17:
    // 0x8000135C: b           L_80001368
    // 0x80001360: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
        goto L_80001368;
    // 0x80001360: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80001364: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80001368:
    // 0x80001368: multu       $a0, $t5
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000136C: lui         $a0, 0x8000
    ctx->r4 = S32(0X8000 << 16);
    // 0x80001370: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001374: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80001378: mflo        $t8
    ctx->r24 = lo;
    // 0x8000137C: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x80001380: lw          $a0, 0x300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X300);
    // 0x80001384: bne         $a0, $at, L_800013D4
    if (ctx->r4 != ctx->r1) {
        // 0x80001388: lui         $t9, 0x3E5
        ctx->r25 = S32(0X3E5 << 16);
            goto L_800013D4;
    }
    // 0x80001388: lui         $t9, 0x3E5
    ctx->r25 = S32(0X3E5 << 16);
    // 0x8000138C: ori         $t9, $t9, 0x2239
    ctx->r25 = ctx->r25 | 0X2239;
    // 0x80001390: addiu       $t6, $zero, 0x20C
    ctx->r14 = ADD32(0, 0X20C);
    // 0x80001394: addiu       $t7, $zero, 0xC15
    ctx->r15 = ADD32(0, 0XC15);
    // 0x80001398: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x8000139C: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x800013A0: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x800013A4: lui         $t8, 0xC15
    ctx->r24 = S32(0XC15 << 16);
    // 0x800013A8: lui         $t9, 0x6C
    ctx->r25 = S32(0X6C << 16);
    // 0x800013AC: lui         $t6, 0x25
    ctx->r14 = S32(0X25 << 16);
    // 0x800013B0: lui         $t7, 0xE
    ctx->r15 = S32(0XE << 16);
    // 0x800013B4: ori         $t8, $t8, 0xC15
    ctx->r24 = ctx->r24 | 0XC15;
    // 0x800013B8: ori         $t9, $t9, 0x2EC
    ctx->r25 = ctx->r25 | 0X2EC;
    // 0x800013BC: ori         $t6, $t6, 0x1FF
    ctx->r14 = ctx->r14 | 0X1FF;
    // 0x800013C0: ori         $t7, $t7, 0x204
    ctx->r15 = ctx->r15 | 0X204;
    // 0x800013C4: sw          $t8, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r24;
    // 0x800013C8: sw          $t9, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r25;
    // 0x800013CC: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
    // 0x800013D0: sw          $t7, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r15;
L_800013D4:
    // 0x800013D4: bne         $a3, $a0, L_80001424
    if (ctx->r7 != ctx->r4) {
        // 0x800013D8: lui         $t8, 0x465
        ctx->r24 = S32(0X465 << 16);
            goto L_80001424;
    }
    // 0x800013D8: lui         $t8, 0x465
    ctx->r24 = S32(0X465 << 16);
    // 0x800013DC: ori         $t8, $t8, 0x1E39
    ctx->r24 = ctx->r24 | 0X1E39;
    // 0x800013E0: addiu       $t9, $zero, 0x20C
    ctx->r25 = ADD32(0, 0X20C);
    // 0x800013E4: addiu       $t6, $zero, 0xC10
    ctx->r14 = ADD32(0, 0XC10);
    // 0x800013E8: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x800013EC: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x800013F0: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x800013F4: lui         $t7, 0xC1C
    ctx->r15 = S32(0XC1C << 16);
    // 0x800013F8: lui         $t8, 0x6C
    ctx->r24 = S32(0X6C << 16);
    // 0x800013FC: lui         $t9, 0x25
    ctx->r25 = S32(0X25 << 16);
    // 0x80001400: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x80001404: ori         $t7, $t7, 0xC1C
    ctx->r15 = ctx->r15 | 0XC1C;
    // 0x80001408: ori         $t8, $t8, 0x2EC
    ctx->r24 = ctx->r24 | 0X2EC;
    // 0x8000140C: ori         $t9, $t9, 0x1FF
    ctx->r25 = ctx->r25 | 0X1FF;
    // 0x80001410: ori         $t6, $t6, 0x204
    ctx->r14 = ctx->r14 | 0X204;
    // 0x80001414: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x80001418: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x8000141C: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
    // 0x80001420: sw          $t6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r14;
L_80001424:
    // 0x80001424: lw          $t8, 0x1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X1C);
    // 0x80001428: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x8000142C: sw          $t8, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r24;
    // 0x80001430: sw          $t7, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r15;
    // 0x80001434: srl         $t6, $t8, 16
    ctx->r14 = S32(U32(ctx->r24) >> 16);
    // 0x80001438: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x8000143C: lh          $t8, 0x46($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X46);
    // 0x80001440: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80001444: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80001448: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8000144C: bgez        $t9, L_80001458
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80001450: sw          $t9, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r25;
            goto L_80001458;
    }
    // 0x80001450: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x80001454: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_80001458:
    // 0x80001458: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8000145C: lh          $t6, 0x4A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4A);
    // 0x80001460: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80001464: bgez        $t8, L_80001470
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80001468: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80001470;
    }
    // 0x80001468: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8000146C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80001470:
    // 0x80001470: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80001474: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80001478: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x8000147C: lw          $t9, 0x30($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X30);
    // 0x80001480: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x80001484: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x80001488: srl         $t6, $t9, 16
    ctx->r14 = S32(U32(ctx->r25) >> 16);
    // 0x8000148C: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x80001490: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x80001494: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80001498: addu        $t9, $t6, $a1
    ctx->r25 = ADD32(ctx->r14, ctx->r5);
    // 0x8000149C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800014A0: bgez        $t9, L_800014AC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800014A4: sw          $t9, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r25;
            goto L_800014AC;
    }
    // 0x800014A4: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    // 0x800014A8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800014AC:
    // 0x800014AC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800014B0: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x800014B4: bgez        $t8, L_800014C0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800014B8: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_800014C0;
    }
    // 0x800014B8: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800014BC: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_800014C0:
    // 0x800014C0: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800014C4: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800014C8: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x800014CC: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x800014D0: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800014D4: sw          $t8, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r24;
    // 0x800014D8: srl         $t7, $t6, 16
    ctx->r15 = S32(U32(ctx->r14) >> 16);
    // 0x800014DC: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x800014E0: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800014E4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800014E8: addu        $t6, $t7, $a1
    ctx->r14 = ADD32(ctx->r15, ctx->r5);
    // 0x800014EC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x800014F0: bgez        $t6, L_800014FC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800014F4: sw          $t6, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r14;
            goto L_800014FC;
    }
    // 0x800014F4: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x800014F8: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
L_800014FC:
    // 0x800014FC: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80001500: addu        $t8, $t9, $a2
    ctx->r24 = ADD32(ctx->r25, ctx->r6);
    // 0x80001504: bgez        $t8, L_80001510
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80001508: sw          $t8, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r24;
            goto L_80001510;
    }
    // 0x80001508: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x8000150C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
L_80001510:
    // 0x80001510: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80001514: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80001518: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x8000151C: lw          $t7, 0x34($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X34);
    // 0x80001520: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80001524: sw          $t8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r24;
    // 0x80001528: beq         $t2, $zero, L_8000157C
    if (ctx->r10 == 0) {
        // 0x8000152C: sw          $t7, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->r15;
            goto L_8000157C;
    }
    // 0x8000152C: sw          $t7, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r15;
    // 0x80001530: beql        $v1, $zero, L_80001580
    if (ctx->r3 == 0) {
        // 0x80001534: lw          $t8, 0x30($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X30);
            goto L_80001580;
    }
    goto skip_18;
    // 0x80001534: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    skip_18:
    // 0x80001538: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x8000153C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80001540: bne         $a3, $a0, L_8000155C
    if (ctx->r7 != ctx->r4) {
        // 0x80001544: sw          $t9, 0x10($v0)
        MEM_W(0X10, ctx->r2) = ctx->r25;
            goto L_8000155C;
    }
    // 0x80001544: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x80001548: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x8000154C: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80001550: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80001554: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x80001558: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
L_8000155C:
    // 0x8000155C: bnel        $a3, $a0, L_800015C8
    if (ctx->r7 != ctx->r4) {
        // 0x80001560: lh          $t6, 0x4A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X4A);
            goto L_800015C8;
    }
    goto skip_19;
    // 0x80001560: lh          $t6, 0x4A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4A);
    skip_19:
    // 0x80001564: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80001568: lui         $at, 0xFFFC
    ctx->r1 = S32(0XFFFC << 16);
    // 0x8000156C: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x80001570: addu        $t9, $t6, $at
    ctx->r25 = ADD32(ctx->r14, ctx->r1);
    // 0x80001574: b           L_800015C4
    // 0x80001578: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
        goto L_800015C4;
    // 0x80001578: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
L_8000157C:
    // 0x8000157C: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
L_80001580:
    // 0x80001580: lui         $at, 0xFFFD
    ctx->r1 = S32(0XFFFD << 16);
    // 0x80001584: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x80001588: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x8000158C: bne         $a3, $a0, L_800015A8
    if (ctx->r7 != ctx->r4) {
        // 0x80001590: sw          $t7, 0x30($v0)
        MEM_W(0X30, ctx->r2) = ctx->r15;
            goto L_800015A8;
    }
    // 0x80001590: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x80001594: lw          $t6, 0x34($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X34);
    // 0x80001598: lui         $at, 0xFFFC
    ctx->r1 = S32(0XFFFC << 16);
    // 0x8000159C: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x800015A0: addu        $t9, $t6, $at
    ctx->r25 = ADD32(ctx->r14, ctx->r1);
    // 0x800015A4: sw          $t9, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r25;
L_800015A8:
    // 0x800015A8: bnel        $a0, $zero, L_800015C8
    if (ctx->r4 != 0) {
        // 0x800015AC: lh          $t6, 0x4A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X4A);
            goto L_800015C8;
    }
    goto skip_20;
    // 0x800015AC: lh          $t6, 0x4A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4A);
    skip_20:
    // 0x800015B0: lw          $t8, 0x48($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X48);
    // 0x800015B4: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x800015B8: ori         $at, $at, 0xFFFE
    ctx->r1 = ctx->r1 | 0XFFFE;
    // 0x800015BC: addu        $t7, $t8, $at
    ctx->r15 = ADD32(ctx->r24, ctx->r1);
    // 0x800015C0: sw          $t7, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r15;
L_800015C4:
    // 0x800015C4: lh          $t6, 0x4A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X4A);
L_800015C8:
    // 0x800015C8: lh          $t9, 0x46($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X46);
    // 0x800015CC: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x800015D0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x800015D4: subu        $t8, $t6, $t9
    ctx->r24 = SUB32(ctx->r14, ctx->r25);
    // 0x800015D8: addiu       $t7, $t8, 0x280
    ctx->r15 = ADD32(ctx->r24, 0X280);
    // 0x800015DC: sll         $t6, $t5, 10
    ctx->r14 = S32(ctx->r13 << 10);
    // 0x800015E0: divu        $zero, $t6, $t7
    lo = S32(U32(ctx->r14) / U32(ctx->r15)); hi = S32(U32(ctx->r14) % U32(ctx->r15));
    // 0x800015E4: mflo        $t9
    ctx->r25 = lo;
    // 0x800015E8: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    // 0x800015EC: bne         $t7, $zero, L_800015F8
    if (ctx->r15 != 0) {
        // 0x800015F0: nop
    
            goto L_800015F8;
    }
    // 0x800015F0: nop

    // 0x800015F4: break       7
    do_break(2147489268);
L_800015F8:
    // 0x800015F8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800015FC: bne         $t0, $zero, L_8000160C
    if (ctx->r8 != 0) {
        // 0x80001600: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8000160C;
    }
    // 0x80001600: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80001604: b           L_8000160C
    // 0x80001608: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8000160C;
    // 0x80001608: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8000160C:
    // 0x8000160C: multu       $a0, $t5
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001610: lui         $at, 0xB
    ctx->r1 = S32(0XB << 16);
    // 0x80001614: ori         $at, $at, 0x4000
    ctx->r1 = ctx->r1 | 0X4000;
    // 0x80001618: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8000161C: sltu        $at, $t4, $at
    ctx->r1 = ctx->r12 < ctx->r1 ? 1 : 0;
    // 0x80001620: mflo        $t8
    ctx->r24 = lo;
    // 0x80001624: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80001628: bne         $t0, $zero, L_80001638
    if (ctx->r8 != 0) {
        // 0x8000162C: sw          $t6, 0x28($v0)
        MEM_W(0X28, ctx->r2) = ctx->r14;
            goto L_80001638;
    }
    // 0x8000162C: sw          $t6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r14;
    // 0x80001630: b           L_8000163C
    // 0x80001634: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
        goto L_8000163C;
    // 0x80001634: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
L_80001638:
    // 0x80001638: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
L_8000163C:
    // 0x8000163C: beq         $t2, $zero, L_8000164C
    if (ctx->r10 == 0) {
        // 0x80001640: nop
    
            goto L_8000164C;
    }
    // 0x80001640: nop

    // 0x80001644: b           L_8000164C
    // 0x80001648: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8000164C;
    // 0x80001648: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8000164C:
    // 0x8000164C: multu       $a0, $t5
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80001650: lw          $t7, 0x14($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14);
    // 0x80001654: sw          $t3, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r11;
    // 0x80001658: sw          $t3, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r11;
    // 0x8000165C: mflo        $t8
    ctx->r24 = lo;
    // 0x80001660: sll         $t6, $t8, 1
    ctx->r14 = S32(ctx->r24 << 1);
    // 0x80001664: nop

    // 0x80001668: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000166C: mflo        $t9
    ctx->r25 = lo;
    // 0x80001670: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x80001674: beql        $t1, $zero, L_800016BC
    if (ctx->r9 == 0) {
        // 0x80001678: addiu       $v1, $zero, 0x2
        ctx->r3 = ADD32(0, 0X2);
            goto L_800016BC;
    }
    goto skip_21;
    // 0x80001678: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    skip_21:
    // 0x8000167C: beq         $at, $zero, L_8000169C
    if (ctx->r1 == 0) {
        // 0x80001680: lui         $at, 0x300
        ctx->r1 = S32(0X300 << 16);
            goto L_8000169C;
    }
    // 0x80001680: lui         $at, 0x300
    ctx->r1 = S32(0X300 << 16);
    // 0x80001684: addu        $t6, $t3, $at
    ctx->r14 = ADD32(ctx->r11, ctx->r1);
    // 0x80001688: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x8000168C: addu        $t9, $t3, $at
    ctx->r25 = ADD32(ctx->r11, ctx->r1);
    // 0x80001690: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x80001694: b           L_800016B8
    // 0x80001698: sw          $t9, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r25;
        goto L_800016B8;
    // 0x80001698: sw          $t9, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r25;
L_8000169C:
    // 0x8000169C: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x800016A0: lw          $t7, 0x40($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X40);
    // 0x800016A4: lui         $v1, 0x200
    ctx->r3 = S32(0X200 << 16);
    // 0x800016A8: addu        $t6, $t8, $v1
    ctx->r14 = ADD32(ctx->r24, ctx->r3);
    // 0x800016AC: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800016B0: sw          $t6, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r14;
    // 0x800016B4: sw          $t9, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r25;
L_800016B8:
    // 0x800016B8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800016BC:
    // 0x800016BC: sw          $v1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r3;
    // 0x800016C0: sw          $v1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r3;
    // 0x800016C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800016C8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800016CC: sw          $t8, 0x4F88($at)
    MEM_W(0X4F88, ctx->r1) = ctx->r24;
    // 0x800016D0: jr          $ra
    // 0x800016D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800016D4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnBackupClearMakeHeaderSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131BCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131BD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131BD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131BD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131BDC: jal         0x80009968
    // 0x80131BE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131BE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131BE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131BE8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131BEC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131BF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131BF4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131BF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131BFC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131C00: jal         0x80009DF4
    // 0x80131C04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131C04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131C08: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131C0C: lw          $t7, 0x31B8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X31B8);
    // 0x80131C10: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131C14: addiu       $t8, $t8, 0xB40
    ctx->r24 = ADD32(ctx->r24, 0XB40);
    // 0x80131C18: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131C1C: jal         0x800CCFDC
    // 0x80131C20: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131C20: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131C24: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131C28: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80131C2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131C30: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80131C34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131C38: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131C3C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131C40: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131C44: addiu       $t3, $zero, 0x5F
    ctx->r11 = ADD32(0, 0X5F);
    // 0x80131C48: addiu       $t4, $zero, 0x58
    ctx->r12 = ADD32(0, 0X58);
    // 0x80131C4C: addiu       $t5, $zero, 0x46
    ctx->r13 = ADD32(0, 0X46);
    // 0x80131C50: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131C54: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80131C58: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80131C5C: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80131C60: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131C64: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131C68: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131C6C: lw          $t6, 0x31B4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31B4);
    // 0x80131C70: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131C74: addiu       $t7, $t7, 0xB60
    ctx->r15 = ADD32(ctx->r15, 0XB60);
    // 0x80131C78: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131C7C: jal         0x800CCFDC
    // 0x80131C80: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131C80: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_3:
    // 0x80131C84: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80131C88: lui         $at, 0x4305
    ctx->r1 = S32(0X4305 << 16);
    // 0x80131C8C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131C90: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80131C94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131C98: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x80131C9C: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80131CA0: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80131CA4: addiu       $t2, $zero, 0xF2
    ctx->r10 = ADD32(0, 0XF2);
    // 0x80131CA8: addiu       $t3, $zero, 0xC7
    ctx->r11 = ADD32(0, 0XC7);
    // 0x80131CAC: addiu       $t4, $zero, 0xD
    ctx->r12 = ADD32(0, 0XD);
    // 0x80131CB0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131CB4: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80131CB8: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80131CBC: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80131CC0: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80131CC4: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80131CC8: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x80131CCC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131CD0: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80131CD4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131CD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131CDC: jr          $ra
    // 0x80131CE0: nop

    return;
    // 0x80131CE0: nop

;}
RECOMP_FUNC void dbUiNodeDispatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381BD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80381BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80381BD8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80381BDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80381BE0: jal         0x80381C2C
    // 0x80381BE4: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    dbUiNodeTypeFindIndex(rdram, ctx);
        goto after_0;
    // 0x80381BE4: lw          $a0, 0x14($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X14);
    after_0:
    // 0x80381BE8: beq         $v0, $zero, L_80381C18
    if (ctx->r2 == 0) {
        // 0x80381BEC: andi        $v1, $v0, 0xFFFF
        ctx->r3 = ctx->r2 & 0XFFFF;
            goto L_80381C18;
    }
    // 0x80381BEC: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x80381BF0: sll         $t7, $v1, 3
    ctx->r15 = S32(ctx->r3 << 3);
    // 0x80381BF4: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80381BF8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x80381BFC: lw          $t9, -0x444($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X444);
    // 0x80381C00: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80381C04: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80381C08: jalr        $t9
    // 0x80381C0C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80381C0C: nop

    after_1:
    // 0x80381C10: b           L_80381C20
    // 0x80381C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80381C20;
    // 0x80381C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80381C18:
    // 0x80381C18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80381C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80381C20:
    // 0x80381C20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80381C24: jr          $ra
    // 0x80381C28: nop

    return;
    // 0x80381C28: nop

;}
RECOMP_FUNC void mnPlayersVSMakeTeamSelectAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132904: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132908: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013290C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80132910: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80132914: jal         0x801328AC
    // 0x80132918: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    mnPlayersVSDestroyTeamSelectAll(rdram, ctx);
        goto after_0;
    // 0x80132918: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8013291C: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80132920: addiu       $s1, $s1, -0x4578
    ctx->r17 = ADD32(ctx->r17, -0X4578);
    // 0x80132924: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80132928: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_8013292C:
    // 0x8013292C: lw          $a0, 0x40($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X40);
    // 0x80132930: jal         0x8013271C
    // 0x80132934: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayersVSMakeTeamSelect(rdram, ctx);
        goto after_1;
    // 0x80132934: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80132938: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8013293C: bne         $s0, $s2, L_8013292C
    if (ctx->r16 != ctx->r18) {
        // 0x80132940: addiu       $s1, $s1, 0xBC
        ctx->r17 = ADD32(ctx->r17, 0XBC);
            goto L_8013292C;
    }
    // 0x80132940: addiu       $s1, $s1, 0xBC
    ctx->r17 = ADD32(ctx->r17, 0XBC);
    // 0x80132944: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132948: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013294C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80132950: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80132954: jr          $ra
    // 0x80132958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80132958: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnScreenAdjustMakeFrame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80131D04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131D08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D10: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131D14: jal         0x80009968
    // 0x80131D18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131D1C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131D20: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131D24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131D28: addiu       $a1, $a1, 0x1B24
    ctx->r5 = ADD32(ctx->r5, 0X1B24);
    // 0x80131D2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131D34: jal         0x80009DF4
    // 0x80131D38: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131D38: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131D3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131D40: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80131D44: jr          $ra
    // 0x80131D48: nop

    return;
    // 0x80131D48: nop

;}
RECOMP_FUNC void mnVSItemSwitchMakeDecalCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801325B4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801325B8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801325BC: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801325C0: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801325C4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801325C8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x801325CC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801325D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801325D4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801325D8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801325DC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801325E0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801325E4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801325E8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801325EC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801325F0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801325F4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801325F8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801325FC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132600: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132608: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013260C: jal         0x8000B93C
    // 0x80132610: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132610: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132614: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132618: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013261C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132620: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132624: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132628: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8013262C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132630: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132634: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132638: jal         0x80007080
    // 0x8013263C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8013263C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132640: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132644: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132648: jr          $ra
    // 0x8013264C: nop

    return;
    // 0x8013264C: nop

;}
RECOMP_FUNC void itProcessUpdateAttackStatItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016FD4C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8016FD50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016FD54: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8016FD58: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8016FD5C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8016FD60: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8016FD64: jal         0x801727F4
    // 0x8016FD68: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    itMainGetDamageOutput(rdram, ctx);
        goto after_0;
    // 0x8016FD68: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x8016FD6C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8016FD70: jal         0x801727F4
    // 0x8016FD74: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    itMainGetDamageOutput(rdram, ctx);
        goto after_1;
    // 0x8016FD74: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_1:
    // 0x8016FD78: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8016FD7C: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x8016FD80: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x8016FD84: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8016FD88: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8016FD8C: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8016FD90: jal         0x800F0EFC
    // 0x8016FD94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    gmCollisionGetItemAttackItemAttackPosition(rdram, ctx);
        goto after_2;
    // 0x8016FD94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_2:
    // 0x8016FD98: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8016FD9C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8016FDA0: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x8016FDA4: lw          $v1, 0x44($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X44);
    // 0x8016FDA8: lw          $a0, 0x44($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X44);
    // 0x8016FDAC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8016FDB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016FDB4: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8016FDB8: bnel        $at, $zero, L_8016FE00
    if (ctx->r1 != 0) {
        // 0x8016FDBC: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8016FE00;
    }
    goto skip_0;
    // 0x8016FDBC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    skip_0:
    // 0x8016FDC0: jal         0x8016F930
    // 0x8016FDC4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    itProcessSetHitInteractStats(rdram, ctx);
        goto after_3;
    // 0x8016FDC4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_3:
    // 0x8016FDC8: lw          $v0, 0x4C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X4C);
    // 0x8016FDCC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x8016FDD0: lw          $t9, 0x270($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X270);
    // 0x8016FDD4: slt         $at, $t9, $a1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8016FDD8: beq         $at, $zero, L_8016FDE4
    if (ctx->r1 == 0) {
        // 0x8016FDDC: nop
    
            goto L_8016FDE4;
    }
    // 0x8016FDDC: nop

    // 0x8016FDE0: sw          $a1, 0x270($v0)
    MEM_W(0X270, ctx->r2) = ctx->r5;
L_8016FDE4:
    // 0x8016FDE4: jal         0x80100BF0
    // 0x8016FDE8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8016FDE8: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_4:
    // 0x8016FDEC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x8016FDF0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8016FDF4: lw          $v1, 0x44($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X44);
    // 0x8016FDF8: lw          $a0, 0x44($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X44);
    // 0x8016FDFC: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
L_8016FE00:
    // 0x8016FE00: bne         $at, $zero, L_8016FE3C
    if (ctx->r1 != 0) {
        // 0x8016FE04: lw          $a0, 0x44($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X44);
            goto L_8016FE3C;
    }
    // 0x8016FE04: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8016FE08: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8016FE0C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x8016FE10: jal         0x8016F930
    // 0x8016FE14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itProcessSetHitInteractStats(rdram, ctx);
        goto after_5;
    // 0x8016FE14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8016FE18: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x8016FE1C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8016FE20: lw          $t2, 0x270($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X270);
    // 0x8016FE24: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8016FE28: beq         $at, $zero, L_8016FE34
    if (ctx->r1 == 0) {
        // 0x8016FE2C: nop
    
            goto L_8016FE34;
    }
    // 0x8016FE2C: nop

    // 0x8016FE30: sw          $a1, 0x270($v0)
    MEM_W(0X270, ctx->r2) = ctx->r5;
L_8016FE34:
    // 0x8016FE34: jal         0x80100BF0
    // 0x8016FE38: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_6;
    // 0x8016FE38: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_6:
L_8016FE3C:
    // 0x8016FE3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016FE40: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8016FE44: jr          $ra
    // 0x8016FE48: nop

    return;
    // 0x8016FE48: nop

;}
RECOMP_FUNC void func_ovl8_80372FEC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372FEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80372FF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80372FF4: jal         0x80373160
    // 0x80372FF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    func_ovl8_80373160(rdram, ctx);
        goto after_0;
    // 0x80372FF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x80372FFC: beq         $v0, $zero, L_80373030
    if (ctx->r2 == 0) {
        // 0x80373000: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80373030;
    }
    // 0x80373000: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80373004: beql        $v0, $zero, L_80373034
    if (ctx->r2 == 0) {
        // 0x80373008: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80373034;
    }
    goto skip_0;
    // 0x80373008: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8037300C: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
L_80373010:
    // 0x80373010: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80373014: lw          $t9, 0x5C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X5C);
    // 0x80373018: lh          $t6, 0x58($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X58);
    // 0x8037301C: jalr        $t9
    // 0x80373020: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80373020: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_1:
    // 0x80373024: lw          $s0, 0x28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X28);
    // 0x80373028: bnel        $s0, $zero, L_80373010
    if (ctx->r16 != 0) {
        // 0x8037302C: lw          $v1, 0x38($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X38);
            goto L_80373010;
    }
    goto skip_1;
    // 0x8037302C: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    skip_1:
L_80373030:
    // 0x80373030: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80373034:
    // 0x80373034: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80373038: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037303C: jr          $ra
    // 0x80373040: nop

    return;
    // 0x80373040: nop

;}
RECOMP_FUNC void mpCommonUpdateFighterProjectFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE34C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE350: jal         0x800DE324
    // 0x800DE354: nop

    mpCommonSetFighterProjectFloor(rdram, ctx);
        goto after_0;
    // 0x800DE354: nop

    after_0:
    // 0x800DE358: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE35C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE360: jr          $ra
    // 0x800DE364: nop

    return;
    // 0x800DE364: nop

;}
RECOMP_FUNC void scStaffrollCheckCursorHighlightPrompt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133200: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80133204: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80133208: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013320C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80133210: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133214: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x80133218: sw          $t6, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r14;
    // 0x8013321C: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80133220: lw          $a3, 0x40($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X40);
    // 0x80133224: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80133228: lw          $a1, 0x30($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30);
    // 0x8013322C: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x80133230: jal         0x80131E70
    // 0x80133234: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    func_ovl59_80131E70(rdram, ctx);
        goto after_0;
    // 0x80133234: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80133238: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8013323C: lw          $a1, 0x38($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X38);
    // 0x80133240: lw          $a2, 0x3C($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X3C);
    // 0x80133244: lw          $a3, 0x48($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X48);
    // 0x80133248: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8013324C: jal         0x80131E70
    // 0x80133250: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    func_ovl59_80131E70(rdram, ctx);
        goto after_1;
    // 0x80133250: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80133254: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80133258: lw          $a1, 0x30($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X30);
    // 0x8013325C: lw          $a2, 0x34($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X34);
    // 0x80133260: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80133264: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x80133268: jal         0x80131E70
    // 0x8013326C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    func_ovl59_80131E70(rdram, ctx);
        goto after_2;
    // 0x8013326C: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    after_2:
    // 0x80133270: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80133274: lw          $a1, 0x40($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X40);
    // 0x80133278: lw          $a2, 0x44($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X44);
    // 0x8013327C: lw          $a3, 0x48($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X48);
    // 0x80133280: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x80133284: jal         0x80131E70
    // 0x80133288: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    func_ovl59_80131E70(rdram, ctx);
        goto after_3;
    // 0x80133288: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x8013328C: jal         0x80131EB8
    // 0x80133290: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    scStaffrollCheckCursorNameOverlap(rdram, ctx);
        goto after_4;
    // 0x80133290: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    after_4:
    // 0x80133294: bnel        $v0, $zero, L_801332FC
    if (ctx->r2 != 0) {
        // 0x80133298: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801332FC;
    }
    goto skip_0;
    // 0x80133298: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8013329C: jal         0x80131EB8
    // 0x801332A0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    scStaffrollCheckCursorNameOverlap(rdram, ctx);
        goto after_5;
    // 0x801332A0: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_5:
    // 0x801332A4: beql        $v0, $zero, L_801332FC
    if (ctx->r2 == 0) {
        // 0x801332A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801332FC;
    }
    goto skip_1;
    // 0x801332A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x801332AC: jal         0x80131EB8
    // 0x801332B0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    scStaffrollCheckCursorNameOverlap(rdram, ctx);
        goto after_6;
    // 0x801332B0: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    after_6:
    // 0x801332B4: beql        $v0, $zero, L_801332FC
    if (ctx->r2 == 0) {
        // 0x801332B8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801332FC;
    }
    goto skip_2;
    // 0x801332B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x801332BC: jal         0x80131EB8
    // 0x801332C0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    scStaffrollCheckCursorNameOverlap(rdram, ctx);
        goto after_7;
    // 0x801332C0: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_7:
    // 0x801332C4: bnel        $v0, $zero, L_801332FC
    if (ctx->r2 != 0) {
        // 0x801332C8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_801332FC;
    }
    goto skip_3;
    // 0x801332C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x801332CC: jal         0x800269C0
    // 0x801332D0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x801332D0: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_8:
    // 0x801332D4: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x801332D8: jal         0x8013202C
    // 0x801332DC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    func_ovl59_8013202C(rdram, ctx);
        goto after_9;
    // 0x801332DC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_9:
    // 0x801332E0: jal         0x801327A4
    // 0x801332E4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    scStaffrollMakeHighlightGObj(rdram, ctx);
        goto after_10;
    // 0x801332E4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_10:
    // 0x801332E8: jal         0x80132E74
    // 0x801332EC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    scStaffrollMakeStaffRoleTextGObj(rdram, ctx);
        goto after_11;
    // 0x801332EC: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_11:
    // 0x801332F0: jal         0x80133184
    // 0x801332F4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    scStaffrollMakeCompanyTextGObj(rdram, ctx);
        goto after_12;
    // 0x801332F4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    after_12:
    // 0x801332F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801332FC:
    // 0x801332FC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80133300: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80133304: jr          $ra
    // 0x80133308: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80133308: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void mnPlayers1PGameLevelThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133BC0: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80133BC4: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80133BC8: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80133BCC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80133BD0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80133BD4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80133BD8: lwc1        $f22, -0x7184($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X7184);
    // 0x80133BDC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80133BE0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80133BE4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80133BE8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80133BEC: lui         $at, 0x431E
    ctx->r1 = S32(0X431E << 16);
    // 0x80133BF0: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80133BF4: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80133BF8: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80133BFC: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80133C00: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80133C04: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80133C08: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80133C0C: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80133C10: lui         $s7, 0x1
    ctx->r23 = S32(0X1 << 16);
    // 0x80133C14: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80133C18: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80133C1C: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80133C20: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80133C24: addiu       $s7, $s7, -0x1238
    ctx->r23 = ADD32(ctx->r23, -0X1238);
    // 0x80133C28: addiu       $s4, $s4, -0x6960
    ctx->r20 = ADD32(ctx->r20, -0X6960);
    // 0x80133C2C: addiu       $s3, $s3, -0x704C
    ctx->r19 = ADD32(ctx->r19, -0X704C);
    // 0x80133C30: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80133C34: addiu       $s5, $zero, -0x21
    ctx->r21 = ADD32(0, -0X21);
    // 0x80133C38: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x80133C3C: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80133C40: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80133C44:
    // 0x80133C44: bne         $s1, $zero, L_80133C68
    if (ctx->r17 != 0) {
        // 0x80133C48: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80133C68;
    }
    // 0x80133C48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133C4C: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80133C50: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80133C54: bnel        $s2, $t6, L_80133C68
    if (ctx->r18 != ctx->r14) {
        // 0x80133C58: sw          $s2, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r18;
            goto L_80133C68;
    }
    goto skip_0;
    // 0x80133C58: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
    skip_0:
    // 0x80133C5C: b           L_80133C68
    // 0x80133C60: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
        goto L_80133C68;
    // 0x80133C60: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x80133C64: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
L_80133C68:
    // 0x80133C68: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80133C6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133C70: bne         $t7, $zero, L_80133C98
    if (ctx->r15 != 0) {
        // 0x80133C74: nop
    
            goto L_80133C98;
    }
    // 0x80133C74: nop

    // 0x80133C78: jal         0x80133B74
    // 0x80133C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameGetArrowSObj(rdram, ctx);
        goto after_0;
    // 0x80133C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80133C80: beq         $v0, $zero, L_80133CDC
    if (ctx->r2 == 0) {
        // 0x80133C84: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80133CDC;
    }
    // 0x80133C84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133C88: jal         0x800096EC
    // 0x80133C8C: nop

    gcEjectSObj(rdram, ctx);
        goto after_1;
    // 0x80133C8C: nop

    after_1:
    // 0x80133C90: b           L_80133CE0
    // 0x80133C94: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
        goto L_80133CE0;
    // 0x80133C94: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80133C98:
    // 0x80133C98: jal         0x80133B74
    // 0x80133C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    mnPlayers1PGameGetArrowSObj(rdram, ctx);
        goto after_2;
    // 0x80133C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80133CA0: bne         $v0, $zero, L_80133CDC
    if (ctx->r2 != 0) {
        // 0x80133CA4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80133CDC;
    }
    // 0x80133CA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133CA8: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80133CAC: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80133CB0: addiu       $t9, $t9, -0x1318
    ctx->r25 = ADD32(ctx->r25, -0X1318);
    // 0x80133CB4: jal         0x800CCFDC
    // 0x80133CB8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80133CB8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x80133CBC: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80133CC0: swc1        $f24, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f24.u32l;
    // 0x80133CC4: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x80133CC8: and         $t2, $t0, $s5
    ctx->r10 = ctx->r8 & ctx->r21;
    // 0x80133CCC: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133CD0: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80133CD4: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80133CD8: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
L_80133CDC:
    // 0x80133CDC: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_80133CE0:
    // 0x80133CE0: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80133CE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133CE8: bne         $s6, $t4, L_80133D10
    if (ctx->r22 != ctx->r12) {
        // 0x80133CEC: nop
    
            goto L_80133D10;
    }
    // 0x80133CEC: nop

    // 0x80133CF0: jal         0x80133B74
    // 0x80133CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameGetArrowSObj(rdram, ctx);
        goto after_4;
    // 0x80133CF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80133CF8: beq         $v0, $zero, L_80133D50
    if (ctx->r2 == 0) {
        // 0x80133CFC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80133D50;
    }
    // 0x80133CFC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133D00: jal         0x800096EC
    // 0x80133D04: nop

    gcEjectSObj(rdram, ctx);
        goto after_5;
    // 0x80133D04: nop

    after_5:
    // 0x80133D08: b           L_80133D50
    // 0x80133D0C: nop

        goto L_80133D50;
    // 0x80133D0C: nop

L_80133D10:
    // 0x80133D10: jal         0x80133B74
    // 0x80133D14: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    mnPlayers1PGameGetArrowSObj(rdram, ctx);
        goto after_6;
    // 0x80133D14: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_6:
    // 0x80133D18: bne         $v0, $zero, L_80133D50
    if (ctx->r2 != 0) {
        // 0x80133D1C: nop
    
            goto L_80133D50;
    }
    // 0x80133D1C: nop

    // 0x80133D20: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80133D24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133D28: jal         0x800CCFDC
    // 0x80133D2C: addu        $a1, $t5, $s7
    ctx->r5 = ADD32(ctx->r13, ctx->r23);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x80133D2C: addu        $a1, $t5, $s7
    ctx->r5 = ADD32(ctx->r13, ctx->r23);
    after_7:
    // 0x80133D30: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80133D34: swc1        $f22, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f22.u32l;
    // 0x80133D38: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x80133D3C: and         $t8, $t6, $s5
    ctx->r24 = ctx->r14 & ctx->r21;
    // 0x80133D40: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80133D44: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80133D48: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80133D4C: sw          $fp, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r30;
L_80133D50:
    // 0x80133D50: jal         0x8000B1E8
    // 0x80133D54: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_8;
    // 0x80133D54: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_8:
    // 0x80133D58: b           L_80133C44
    // 0x80133D5C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80133C44;
    // 0x80133D5C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80133D60: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80133D64: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80133D68: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80133D6C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80133D70: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80133D74: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80133D78: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80133D7C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80133D80: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80133D84: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80133D88: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80133D8C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80133D90: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80133D94: jr          $ra
    // 0x80133D98: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80133D98: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void gcEjectSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800096EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800096F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800096F4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x800096F8: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x800096FC: bnel        $a0, $t6, L_80009724
    if (ctx->r4 != ctx->r14) {
        // 0x80009700: lw          $v0, 0xC($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XC);
            goto L_80009724;
    }
    goto skip_0;
    // 0x80009700: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    skip_0:
    // 0x80009704: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x80009708: sw          $t7, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r15;
    // 0x8000970C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80009710: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x80009714: bnel        $t8, $zero, L_80009724
    if (ctx->r24 != 0) {
        // 0x80009718: lw          $v0, 0xC($a0)
        ctx->r2 = MEM_W(ctx->r4, 0XC);
            goto L_80009724;
    }
    goto skip_1;
    // 0x80009718: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    skip_1:
    // 0x8000971C: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
    // 0x80009720: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
L_80009724:
    // 0x80009724: beql        $v0, $zero, L_80009738
    if (ctx->r2 == 0) {
        // 0x80009728: lw          $v0, 0x8($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X8);
            goto L_80009738;
    }
    goto skip_2;
    // 0x80009728: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    skip_2:
    // 0x8000972C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x80009730: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80009734: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
L_80009738:
    // 0x80009738: beq         $v0, $zero, L_80009748
    if (ctx->r2 == 0) {
        // 0x8000973C: nop
    
            goto L_80009748;
    }
    // 0x8000973C: nop

    // 0x80009740: lw          $t0, 0xC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XC);
    // 0x80009744: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
L_80009748:
    // 0x80009748: jal         0x800080B0
    // 0x8000974C: nop

    gcSetSObjPrevAlloc(rdram, ctx);
        goto after_0;
    // 0x8000974C: nop

    after_0:
    // 0x80009750: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80009754: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80009758: jr          $ra
    // 0x8000975C: nop

    return;
    // 0x8000975C: nop

;}
RECOMP_FUNC void gmCameraPlayerFollowFuncCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CDAC: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8010CDB0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8010CDB4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010CDB8: addiu       $s0, $s0, 0x14B0
    ctx->r16 = ADD32(ctx->r16, 0X14B0);
    // 0x8010CDBC: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8010CDC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010CDC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8010CDC8: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x8010CDCC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8010CDD0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8010CDD4: lw          $t8, 0x1C($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X1C);
    // 0x8010CDD8: lw          $s1, 0x74($a1)
    ctx->r17 = MEM_W(ctx->r5, 0X74);
    // 0x8010CDDC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010CDE0: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8010CDE4: lw          $t7, 0x20($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X20);
    // 0x8010CDE8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8010CDEC: lw          $t8, 0x24($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X24);
    // 0x8010CDF0: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8010CDF4: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8010CDF8: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010CDFC: lw          $t9, 0x9C8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X9C8);
    // 0x8010CE00: lwc1        $f6, 0x8C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X8C);
    // 0x8010CE04: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x8010CE08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8010CE0C: jal         0x8010B8BC
    // 0x8010CE10: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    gmCameraSetBoundsPosition(rdram, ctx);
        goto after_0;
    // 0x8010CE10: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8010CE14: jal         0x8010C70C
    // 0x8010CE18: lwc1        $f12, 0x88($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X88);
    gmCameraAdjustFOV(rdram, ctx);
        goto after_1;
    // 0x8010CE18: lwc1        $f12, 0x88($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X88);
    after_1:
    // 0x8010CE1C: lwc1        $f16, 0x80($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X80);
    // 0x8010CE20: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010CE24: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8010CE28: lw          $a2, 0x84($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X84);
    // 0x8010CE2C: jal         0x8010C55C
    // 0x8010CE30: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    gmCameraPan(rdram, ctx);
        goto after_2;
    // 0x8010CE30: swc1        $f16, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f16.u32l;
    after_2:
    // 0x8010CE34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010CE38: lwc1        $f18, 0x1468($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X1468);
    // 0x8010CE3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010CE40: lwc1        $f4, 0x78($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8010CE44: lwc1        $f8, 0x1464($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X1464);
    // 0x8010CE48: lwc1        $f10, 0x7C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X7C);
    // 0x8010CE4C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8010CE50: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010CE54: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8010CE58: jal         0x800C7840
    // 0x8010CE5C: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    lbCommonSin(rdram, ctx);
        goto after_3;
    // 0x8010CE5C: swc1        $f12, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x8010CE60: neg.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = -ctx->f0.fl;
    // 0x8010CE64: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8010CE68: jal         0x800C78B8
    // 0x8010CE6C: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    lbCommonCos(rdram, ctx);
        goto after_4;
    // 0x8010CE6C: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    after_4:
    // 0x8010CE70: swc1        $f0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f0.u32l;
    // 0x8010CE74: jal         0x800C7840
    // 0x8010CE78: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    lbCommonSin(rdram, ctx);
        goto after_5;
    // 0x8010CE78: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    after_5:
    // 0x8010CE7C: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8010CE80: lwc1        $f12, 0x58($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8010CE84: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8010CE88: jal         0x800C78B8
    // 0x8010CE8C: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    lbCommonCos(rdram, ctx);
        goto after_6;
    // 0x8010CE8C: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    after_6:
    // 0x8010CE90: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8010CE94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010CE98: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x8010CE9C: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x8010CEA0: jal         0x8010C5C0
    // 0x8010CEA4: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    func_ovl2_8010C5C0(rdram, ctx);
        goto after_7;
    // 0x8010CEA4: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    after_7:
    // 0x8010CEA8: jal         0x8010C6B8
    // 0x8010CEAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gmCameraApplyVel(rdram, ctx);
        goto after_8;
    // 0x8010CEAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8010CEB0: jal         0x8010C6FC
    // 0x8010CEB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gmCameraApplyFOV(rdram, ctx);
        goto after_9;
    // 0x8010CEB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x8010CEB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010CEBC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8010CEC0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8010CEC4: jr          $ra
    // 0x8010CEC8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8010CEC8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void ftCommonWallDamageProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141AC0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80141AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141AC8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80141ACC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80141AD0: jal         0x80140454
    // 0x80141AD4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftCommonDamageUpdateDustEffect(rdram, ctx);
        goto after_0;
    // 0x80141AD4: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80141AD8: jal         0x801404B8
    // 0x80141ADC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonDamageDecHitStunSetPublic(rdram, ctx);
        goto after_1;
    // 0x80141ADC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80141AE0: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80141AE4: lw          $t8, 0xB18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XB18);
    // 0x80141AE8: bnel        $t8, $zero, L_80141AFC
    if (ctx->r24 != 0) {
        // 0x80141AEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80141AFC;
    }
    goto skip_0;
    // 0x80141AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80141AF0: jal         0x80143664
    // 0x80141AF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonDamageFallSetStatusFromDamage(rdram, ctx);
        goto after_2;
    // 0x80141AF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80141AF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141AFC:
    // 0x80141AFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80141B00: jr          $ra
    // 0x80141B04: nop

    return;
    // 0x80141B04: nop

;}
RECOMP_FUNC void itLGunWeaponAmmoProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175958: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017595C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175960: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80175964: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x80175968: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x8017596C: jal         0x800FE068
    // 0x80175970: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80175970: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x80175974: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175978: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017597C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80175980: jr          $ra
    // 0x80175984: nop

    return;
    // 0x80175984: nop

;}
RECOMP_FUNC void ftCommonCliffEscapeSlow2SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014594C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80145950: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80145954: jal         0x80145490
    // 0x80145958: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftCommonCliffCommon2UpdateCollData(rdram, ctx);
        goto after_0;
    // 0x80145958: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014595C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80145960: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
    // 0x80145964: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80145968: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014596C: jal         0x800E6F24
    // 0x80145970: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80145970: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80145974: jal         0x8014557C
    // 0x80145978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonCliffCommon2InitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80145978: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8014597C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80145980: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80145984: jr          $ra
    // 0x80145988: nop

    return;
    // 0x80145988: nop

;}
RECOMP_FUNC void mnPlayersVSMakePortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132520: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80132524: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132528: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013252C: addiu       $t7, $t7, -0x4A9C
    ctx->r15 = ADD32(ctx->r15, -0X4A9C);
    // 0x80132530: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80132534: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132538: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x8013253C: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
L_80132540:
    // 0x80132540: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132544: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132548: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013254C: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132550: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132554: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132558: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8013255C: bne         $t7, $t0, L_80132540
    if (ctx->r15 != ctx->r8) {
        // 0x80132560: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132540;
    }
    // 0x80132560: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132564: jal         0x80132118
    // 0x80132568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x80132568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8013256C: jal         0x80132044
    // 0x80132570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayersVSCheckFighterLocked(rdram, ctx);
        goto after_1;
    // 0x80132570: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80132574: beq         $v0, $zero, L_8013258C
    if (ctx->r2 == 0) {
        // 0x80132578: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8013258C;
    }
    // 0x80132578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013257C: jal         0x80132278
    // 0x80132580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSMakePortraitShadow(rdram, ctx);
        goto after_2;
    // 0x80132580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80132584: b           L_801326CC
    // 0x80132588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801326CC;
    // 0x80132588: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8013258C:
    // 0x8013258C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132590: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80132594: jal         0x80009968
    // 0x80132598: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80132598: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x8013259C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801325A0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801325A4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801325A8: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x801325AC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801325B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801325B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801325B8: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x801325BC: jal         0x80009DF4
    // 0x801325C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x801325C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x801325C4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x801325C8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801325CC: addiu       $a1, $a1, 0x1EE4
    ctx->r5 = ADD32(ctx->r5, 0X1EE4);
    // 0x801325D0: sw          $s0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r16;
    // 0x801325D4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x801325D8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801325DC: jal         0x80008188
    // 0x801325E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x801325E0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x801325E4: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801325E8: lw          $t2, -0x3B4C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X3B4C);
    // 0x801325EC: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x801325F0: addiu       $t3, $t3, 0x24D0
    ctx->r11 = ADD32(ctx->r11, 0X24D0);
    // 0x801325F4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x801325F8: jal         0x800CCFDC
    // 0x801325FC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x801325FC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_6:
    // 0x80132600: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132604: jal         0x80131F54
    // 0x80132608: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayersVSSetPortraitWallpaperPosition(rdram, ctx);
        goto after_7;
    // 0x80132608: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x8013260C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132610: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132614: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132618: jal         0x80009968
    // 0x8013261C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_8;
    // 0x8013261C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_8:
    // 0x80132620: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80132624: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80132628: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8013262C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132630: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80132634: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132638: jal         0x80009DF4
    // 0x8013263C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_9;
    // 0x8013263C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_9:
    // 0x80132640: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80132644: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80132648: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013264C: jal         0x80008188
    // 0x80132650: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_10;
    // 0x80132650: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80132654: jal         0x80132118
    // 0x80132658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSGetFighterKind(rdram, ctx);
        goto after_11;
    // 0x80132658: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8013265C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80132660: addu        $t0, $sp, $t5
    ctx->r8 = ADD32(ctx->r29, ctx->r13);
    // 0x80132664: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132668: lw          $t7, -0x3B4C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3B4C);
    // 0x8013266C: lw          $t0, 0x34($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X34);
    // 0x80132670: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x80132674: jal         0x800CCFDC
    // 0x80132678: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_12;
    // 0x80132678: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    after_12:
    // 0x8013267C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80132680: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132688: andi        $t9, $t6, 0xFFDF
    ctx->r25 = ctx->r14 & 0XFFDF;
    // 0x8013268C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132690: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x80132694: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132698: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8013269C: jal         0x80132118
    // 0x801326A0: sw          $s0, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r16;
    mnPlayersVSGetFighterKind(rdram, ctx);
        goto after_13;
    // 0x801326A0: sw          $s0, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r16;
    after_13:
    // 0x801326A4: jal         0x80131ED8
    // 0x801326A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayersVSCheckFighterCrossed(rdram, ctx);
        goto after_14;
    // 0x801326A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x801326AC: beq         $v0, $zero, L_801326BC
    if (ctx->r2 == 0) {
        // 0x801326B0: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_801326BC;
    }
    // 0x801326B0: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x801326B4: jal         0x80131FB0
    // 0x801326B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayersVSPortraitAddCross(rdram, ctx);
        goto after_15;
    // 0x801326B8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
L_801326BC:
    // 0x801326BC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x801326C0: jal         0x80131F54
    // 0x801326C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayersVSSetPortraitWallpaperPosition(rdram, ctx);
        goto after_16;
    // 0x801326C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x801326C8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801326CC:
    // 0x801326CC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801326D0: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x801326D4: jr          $ra
    // 0x801326D8: nop

    return;
    // 0x801326D8: nop

;}
RECOMP_FUNC void EFGroundActorProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801168CC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801168D0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801168D4: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801168D8: addiu       $s0, $s0, 0x1AD8
    ctx->r16 = ADD32(ctx->r16, 0X1AD8);
    // 0x801168DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801168E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801168E4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801168E8: bnel        $v0, $zero, L_801169B8
    if (ctx->r2 != 0) {
        // 0x801168EC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801169B8;
    }
    goto skip_0;
    // 0x801168EC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801168F0: lhu         $v0, 0x6($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X6);
    // 0x801168F4: lhu         $a2, 0x4($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4);
    // 0x801168F8: bne         $v0, $zero, L_801169A4
    if (ctx->r2 != 0) {
        // 0x801168FC: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_801169A4;
    }
    // 0x801168FC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80116900: jal         0x80018994
    // 0x80116904: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80116904: lbu         $a0, 0x8($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X8);
    after_0:
    // 0x80116908: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8011690C: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    // 0x80116910: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80116914: lbu         $v1, 0x0($t7)
    ctx->r3 = MEM_BU(ctx->r15, 0X0);
    // 0x80116918: lw          $a0, 0x4($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X4);
    // 0x8011691C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80116920: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80116924: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80116928: addu        $a1, $t9, $a0
    ctx->r5 = ADD32(ctx->r25, ctx->r4);
    // 0x8011692C: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x80116930: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80116934: sh          $t0, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r8;
    // 0x80116938: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x8011693C: andi        $a2, $t0, 0xFFFF
    ctx->r6 = ctx->r8 & 0XFFFF;
    // 0x80116940: bne         $t1, $zero, L_80116974
    if (ctx->r9 != 0) {
        // 0x80116944: sw          $t1, 0x10($s0)
        MEM_W(0X10, ctx->r16) = ctx->r9;
            goto L_80116974;
    }
    // 0x80116944: sw          $t1, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r9;
    // 0x80116948: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8011694C: jal         0x80018994
    // 0x80116950: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80116950: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_1:
    // 0x80116954: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80116958: bne         $v0, $zero, L_8011696C
    if (ctx->r2 != 0) {
        // 0x8011695C: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_8011696C;
    }
    // 0x8011695C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80116960: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80116964: b           L_80116974
    // 0x80116968: sw          $t3, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r11;
        goto L_80116974;
    // 0x80116968: sw          $t3, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r11;
L_8011696C:
    // 0x8011696C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80116970: sw          $t4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r12;
L_80116974:
    // 0x80116974: lhu         $t5, 0x2($a1)
    ctx->r13 = MEM_HU(ctx->r5, 0X2);
    // 0x80116978: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8011697C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x80116980: beq         $t6, $zero, L_801169A8
    if (ctx->r14 == 0) {
        // 0x80116984: sh          $t5, 0x6($s0)
        MEM_H(0X6, ctx->r16) = ctx->r13;
            goto L_801169A8;
    }
    // 0x80116984: sh          $t5, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r13;
    // 0x80116988: jal         0x80018994
    // 0x8011698C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x8011698C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_2:
    // 0x80116990: lhu         $t7, 0x6($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X6);
    // 0x80116994: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80116998: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8011699C: b           L_801169A8
    // 0x801169A0: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
        goto L_801169A8;
    // 0x801169A0: sh          $t8, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r24;
L_801169A4:
    // 0x801169A4: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
L_801169A8:
    // 0x801169A8: jal         0x8011677C
    // 0x801169AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    efGroundMakeEffectID(rdram, ctx);
        goto after_3;
    // 0x801169AC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x801169B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801169B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801169B8:
    // 0x801169B8: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x801169BC: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801169C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801169C4: jr          $ra
    // 0x801169C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801169C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void itRShellWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A7C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017A7C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A7CC: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017A7D0: jal         0x801735A0
    // 0x8017A7D4: addiu       $a1, $a1, -0x567C
    ctx->r5 = ADD32(ctx->r5, -0X567C);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x8017A7D4: addiu       $a1, $a1, -0x567C
    ctx->r5 = ADD32(ctx->r5, -0X567C);
    after_0:
    // 0x8017A7D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A7DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017A7E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017A7E4: jr          $ra
    // 0x8017A7E8: nop

    return;
    // 0x8017A7E8: nop

;}
RECOMP_FUNC void ftKirbySpecialAirLwHoldProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801616D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801616D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801616D8: jal         0x801615E4
    // 0x801616DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftKirbySpecialLwUnkDecideNextStatus(rdram, ctx);
        goto after_0;
    // 0x801616DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x801616E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801616E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801616E8: jr          $ra
    // 0x801616EC: nop

    return;
    // 0x801616EC: nop

;}
RECOMP_FUNC void ftManagerSetupFileSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6FE0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800D6FE4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x800D6FE8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x800D6FEC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800D6FF0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800D6FF4: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x800D6FF8: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x800D6FFC: addiu       $t8, $t8, 0xDA0
    ctx->r24 = ADD32(ctx->r24, 0XDA0);
    // 0x800D7000: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800D7004: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x800D7008: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x800D700C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800D7010: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800D7014: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800D7018: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800D701C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D7020: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D7024: sw          $t6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r14;
    // 0x800D7028: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x800D702C: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x800D7030: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x800D7034: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800D7038: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800D703C: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x800D7040: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x800D7044: jal         0x800CDF78
    // 0x800D7048: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x800D7048: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x800D704C: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x800D7050: lui         $s5, 0x8011
    ctx->r21 = S32(0X8011 << 16);
    // 0x800D7054: lui         $s7, 0x8011
    ctx->r23 = S32(0X8011 << 16);
    // 0x800D7058: addiu       $s7, $s7, 0x6E7C
    ctx->r23 = ADD32(ctx->r23, 0X6E7C);
    // 0x800D705C: addiu       $s5, $s5, 0x6E10
    ctx->r21 = ADD32(ctx->r21, 0X6E10);
    // 0x800D7060: addiu       $s4, $s4, 0x50F8
    ctx->r20 = ADD32(ctx->r20, 0X50F8);
L_800D7064:
    // 0x800D7064: lw          $s2, 0x0($s5)
    ctx->r18 = MEM_W(ctx->r21, 0X0);
    // 0x800D7068: or          $s6, $s4, $zero
    ctx->r22 = ctx->r20 | 0;
    // 0x800D706C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800D7070: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D7074: jal         0x800CDBD0
    // 0x800D7078: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    lbRelocGetFileSize(rdram, ctx);
        goto after_1;
    // 0x800D7078: lw          $a0, 0x0($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X0);
    after_1:
    // 0x800D707C: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x800D7080: lw          $t0, 0x6C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X6C);
    // 0x800D7084: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D7088: blezl       $t0, L_800D70EC
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800D708C: sw          $s3, 0x4($s4)
        MEM_W(0X4, ctx->r20) = ctx->r19;
            goto L_800D70EC;
    }
    goto skip_0;
    // 0x800D708C: sw          $s3, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r19;
    skip_0:
    // 0x800D7090: lw          $t1, 0x64($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X64);
L_800D7094:
    // 0x800D7094: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x800D7098: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800D709C: beql        $t2, $zero, L_800D70D0
    if (ctx->r10 == 0) {
        // 0x800D70A0: lw          $t6, 0x6C($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X6C);
            goto L_800D70D0;
    }
    goto skip_1;
    // 0x800D70A0: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    skip_1:
    // 0x800D70A4: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x800D70A8: sll         $t5, $t3, 30
    ctx->r13 = S32(ctx->r11 << 30);
    // 0x800D70AC: bltzl       $t5, L_800D70D0
    if (SIGNED(ctx->r13) < 0) {
        // 0x800D70B0: lw          $t6, 0x6C($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X6C);
            goto L_800D70D0;
    }
    goto skip_2;
    // 0x800D70B0: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    skip_2:
    // 0x800D70B4: jal         0x800CDBD0
    // 0x800D70B8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    lbRelocGetFileSize(rdram, ctx);
        goto after_2;
    // 0x800D70B8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_2:
    // 0x800D70BC: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x800D70C0: beql        $at, $zero, L_800D70D0
    if (ctx->r1 == 0) {
        // 0x800D70C4: lw          $t6, 0x6C($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X6C);
            goto L_800D70D0;
    }
    goto skip_3;
    // 0x800D70C4: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
    skip_3:
    // 0x800D70C8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D70CC: lw          $t6, 0x6C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X6C);
L_800D70D0:
    // 0x800D70D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D70D4: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800D70D8: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800D70DC: bnel        $at, $zero, L_800D7094
    if (ctx->r1 != 0) {
        // 0x800D70E0: lw          $t1, 0x64($s2)
        ctx->r9 = MEM_W(ctx->r18, 0X64);
            goto L_800D7094;
    }
    goto skip_4;
    // 0x800D70E0: lw          $t1, 0x64($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X64);
    skip_4:
    // 0x800D70E4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800D70E8: sw          $s3, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r19;
L_800D70EC:
    // 0x800D70EC: lw          $t7, 0x70($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X70);
    // 0x800D70F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D70F4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800D70F8: blezl       $t8, L_800D715C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800D70FC: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_800D715C;
    }
    goto skip_5;
    // 0x800D70FC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    skip_5:
    // 0x800D7100: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
L_800D7104:
    // 0x800D7104: addu        $v0, $t9, $s0
    ctx->r2 = ADD32(ctx->r25, ctx->r16);
    // 0x800D7108: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800D710C: beql        $t0, $zero, L_800D7140
    if (ctx->r8 == 0) {
        // 0x800D7110: lw          $t4, 0x70($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X70);
            goto L_800D7140;
    }
    goto skip_6;
    // 0x800D7110: lw          $t4, 0x70($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X70);
    skip_6:
    // 0x800D7114: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800D7118: sll         $t3, $t1, 30
    ctx->r11 = S32(ctx->r9 << 30);
    // 0x800D711C: bltzl       $t3, L_800D7140
    if (SIGNED(ctx->r11) < 0) {
        // 0x800D7120: lw          $t4, 0x70($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X70);
            goto L_800D7140;
    }
    goto skip_7;
    // 0x800D7120: lw          $t4, 0x70($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X70);
    skip_7:
    // 0x800D7124: jal         0x800CDBD0
    // 0x800D7128: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    lbRelocGetFileSize(rdram, ctx);
        goto after_3;
    // 0x800D7128: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    after_3:
    // 0x800D712C: sltu        $at, $s3, $v0
    ctx->r1 = ctx->r19 < ctx->r2 ? 1 : 0;
    // 0x800D7130: beql        $at, $zero, L_800D7140
    if (ctx->r1 == 0) {
        // 0x800D7134: lw          $t4, 0x70($s2)
        ctx->r12 = MEM_W(ctx->r18, 0X70);
            goto L_800D7140;
    }
    goto skip_8;
    // 0x800D7134: lw          $t4, 0x70($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X70);
    skip_8:
    // 0x800D7138: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800D713C: lw          $t4, 0x70($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X70);
L_800D7140:
    // 0x800D7140: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D7144: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x800D7148: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800D714C: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800D7150: bnel        $at, $zero, L_800D7104
    if (ctx->r1 != 0) {
        // 0x800D7154: lw          $t9, 0x68($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X68);
            goto L_800D7104;
    }
    goto skip_9;
    // 0x800D7154: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    skip_9:
    // 0x800D7158: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800D715C:
    // 0x800D715C: addiu       $s4, $s4, 0xC
    ctx->r20 = ADD32(ctx->r20, 0XC);
    // 0x800D7160: bne         $s5, $s7, L_800D7064
    if (ctx->r21 != ctx->r23) {
        // 0x800D7164: sw          $s3, 0x8($s6)
        MEM_W(0X8, ctx->r22) = ctx->r19;
            goto L_800D7064;
    }
    // 0x800D7164: sw          $s3, 0x8($s6)
    MEM_W(0X8, ctx->r22) = ctx->r19;
    // 0x800D7168: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800D716C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D7170: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D7174: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D7178: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D717C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800D7180: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800D7184: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800D7188: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x800D718C: jr          $ra
    // 0x800D7190: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800D7190: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void itMainSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172EC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80172ECC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80172ED0: sll         $t6, $a2, 5
    ctx->r14 = S32(ctx->r6 << 5);
    // 0x80172ED4: addu        $v0, $a1, $t6
    ctx->r2 = ADD32(ctx->r5, ctx->r14);
    // 0x80172ED8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80172EDC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80172EE0: lbu         $t5, 0x2CF($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2CF);
    // 0x80172EE4: sw          $t7, 0x378($v1)
    MEM_W(0X378, ctx->r3) = ctx->r15;
    // 0x80172EE8: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80172EEC: lhu         $t7, 0x15C($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X15C);
    // 0x80172EF0: andi        $t6, $t5, 0xFFDF
    ctx->r14 = ctx->r13 & 0XFFDF;
    // 0x80172EF4: sw          $t8, 0x37C($v1)
    MEM_W(0X37C, ctx->r3) = ctx->r24;
    // 0x80172EF8: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80172EFC: andi        $t8, $t7, 0xFC00
    ctx->r24 = ctx->r15 & 0XFC00;
    // 0x80172F00: sw          $t9, 0x380($v1)
    MEM_W(0X380, ctx->r3) = ctx->r25;
    // 0x80172F04: lw          $t0, 0xC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XC);
    // 0x80172F08: ori         $t9, $t8, 0x39
    ctx->r25 = ctx->r24 | 0X39;
    // 0x80172F0C: sw          $t0, 0x384($v1)
    MEM_W(0X384, ctx->r3) = ctx->r8;
    // 0x80172F10: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x80172F14: sw          $t1, 0x388($v1)
    MEM_W(0X388, ctx->r3) = ctx->r9;
    // 0x80172F18: lw          $t2, 0x14($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X14);
    // 0x80172F1C: sw          $t2, 0x38C($v1)
    MEM_W(0X38C, ctx->r3) = ctx->r10;
    // 0x80172F20: lw          $t3, 0x18($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X18);
    // 0x80172F24: sw          $t3, 0x390($v1)
    MEM_W(0X390, ctx->r3) = ctx->r11;
    // 0x80172F28: lw          $t4, 0x1C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X1C);
    // 0x80172F2C: sh          $t9, 0x15C($v1)
    MEM_H(0X15C, ctx->r3) = ctx->r25;
    // 0x80172F30: lbu         $t0, 0x15C($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X15C);
    // 0x80172F34: sw          $t4, 0x394($v1)
    MEM_W(0X394, ctx->r3) = ctx->r12;
    // 0x80172F38: sb          $t6, 0x2CF($v1)
    MEM_B(0X2CF, ctx->r3) = ctx->r14;
    // 0x80172F3C: andi        $t4, $t0, 0xFFFB
    ctx->r12 = ctx->r8 & 0XFFFB;
    // 0x80172F40: sb          $t4, 0x15C($v1)
    MEM_B(0X15C, ctx->r3) = ctx->r12;
    // 0x80172F44: lw          $a0, 0x15C($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X15C);
    // 0x80172F48: andi        $t5, $t4, 0xF7
    ctx->r13 = ctx->r12 & 0XF7;
    // 0x80172F4C: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    // 0x80172F50: srl         $a0, $a0, 31
    ctx->r4 = S32(U32(ctx->r4) >> 31);
    // 0x80172F54: sll         $t2, $a0, 3
    ctx->r10 = S32(ctx->r4 << 3);
    // 0x80172F58: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x80172F5C: or          $t9, $t3, $t5
    ctx->r25 = ctx->r11 | ctx->r13;
    // 0x80172F60: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x80172F64: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80172F68: andi        $t0, $t9, 0xEF
    ctx->r8 = ctx->r25 & 0XEF;
    // 0x80172F6C: or          $t1, $t8, $t0
    ctx->r9 = ctx->r24 | ctx->r8;
    // 0x80172F70: sb          $t9, 0x15C($v1)
    MEM_B(0X15C, ctx->r3) = ctx->r25;
    // 0x80172F74: sb          $t1, 0x15C($v1)
    MEM_B(0X15C, ctx->r3) = ctx->r9;
    // 0x80172F78: jal         0x800EA74C
    // 0x80172F7C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftParamGetStatUpdateCount(rdram, ctx);
        goto after_0;
    // 0x80172F7C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80172F80: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80172F84: sh          $v0, 0x15E($v1)
    MEM_H(0X15E, ctx->r3) = ctx->r2;
    // 0x80172F88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80172F8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80172F90: jr          $ra
    // 0x80172F94: nop

    return;
    // 0x80172F94: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirHiStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801529EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801529F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801529F4: jal         0x80152934
    // 0x801529F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftPikachuSpecialHiStartInitStatusVars(rdram, ctx);
        goto after_0;
    // 0x801529F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801529FC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80152A00: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80152A04: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x80152A08: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80152A0C: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80152A10: jal         0x800E6F24
    // 0x80152A14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80152A14: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80152A18: jal         0x800E0830
    // 0x80152A1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80152A1C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80152A20: jal         0x80152960
    // 0x80152A24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPikachuSpecialHiInitMiscVars(rdram, ctx);
        goto after_3;
    // 0x80152A24: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80152A28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80152A2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80152A30: jr          $ra
    // 0x80152A34: nop

    return;
    // 0x80152A34: nop

;}
RECOMP_FUNC void ftCommonRebirthStandSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D2DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013D2E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013D2E4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013D2E8: addiu       $t6, $zero, 0x106
    ctx->r14 = ADD32(0, 0X106);
    // 0x8013D2EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013D2F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013D2F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8013D2F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013D2FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013D300: jal         0x800E6F24
    // 0x8013D304: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013D304: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013D308: jal         0x800E0830
    // 0x8013D30C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8013D30C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8013D310: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8013D314: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013D318: lbu         $t8, 0x191($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X191);
    // 0x8013D31C: lbu         $t4, 0x18E($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X18E);
    // 0x8013D320: ori         $t1, $t8, 0x10
    ctx->r9 = ctx->r24 | 0X10;
    // 0x8013D324: ori         $t7, $t4, 0x80
    ctx->r15 = ctx->r12 | 0X80;
    // 0x8013D328: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x8013D32C: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8013D330: sb          $t1, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r9;
    // 0x8013D334: sb          $t7, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r15;
    // 0x8013D338: sb          $t2, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r10;
    // 0x8013D33C: sb          $t8, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r24;
    // 0x8013D340: lwc1        $f4, -0x3FA8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3FA8);
    // 0x8013D344: swc1        $f4, 0x864($v0)
    MEM_W(0X864, ctx->r2) = ctx->f4.u32l;
    // 0x8013D348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013D34C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013D350: jr          $ra
    // 0x8013D354: nop

    return;
    // 0x8013D354: nop

;}
RECOMP_FUNC void itMewFlySetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017ED20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017ED24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017ED28: jal         0x8017EC84
    // 0x8017ED2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMewFlyInitVars(rdram, ctx);
        goto after_0;
    // 0x8017ED2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017ED30: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017ED34: addiu       $a1, $a1, -0x538C
    ctx->r5 = ADD32(ctx->r5, -0X538C);
    // 0x8017ED38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017ED3C: jal         0x80172EC8
    // 0x8017ED40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017ED40: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8017ED44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017ED48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017ED4C: jr          $ra
    // 0x8017ED50: nop

    return;
    // 0x8017ED50: nop

;}
RECOMP_FUNC void func_ovl8_8037354C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037354C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80373550: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373554: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80373558: beq         $a0, $zero, L_803735D4
    if (ctx->r4 == 0) {
        // 0x8037355C: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_803735D4;
    }
    // 0x8037355C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80373560: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80373564: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80373568: addiu       $t6, $t6, -0x6F60
    ctx->r14 = ADD32(ctx->r14, -0X6F60);
    // 0x8037356C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80373570: addiu       $t7, $t7, -0x6E90
    ctx->r15 = ADD32(ctx->r15, -0X6E90);
    // 0x80373574: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80373578: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x8037357C: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80373580: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80373584: addiu       $t9, $t9, -0x6D38
    ctx->r25 = ADD32(ctx->r25, -0X6D38);
    // 0x80373588: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8037358C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80373590: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80373594: beql        $t1, $zero, L_803735C0
    if (ctx->r9 == 0) {
        // 0x80373598: lw          $t2, 0x1C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X1C);
            goto L_803735C0;
    }
    goto skip_0;
    // 0x80373598: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8037359C: lw          $a0, 0x34($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X34);
    // 0x803735A0: jal         0x8037C30C
    // 0x803735A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_ovl8_8037C30C(rdram, ctx);
        goto after_0;
    // 0x803735A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x803735A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x803735AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803735B0: jal         0x803718C4
    // 0x803735B4: lw          $a0, 0x38($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X38);
    func_ovl8_803718C4(rdram, ctx);
        goto after_1;
    // 0x803735B4: lw          $a0, 0x38($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X38);
    after_1:
    // 0x803735B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x803735BC: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
L_803735C0:
    // 0x803735C0: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x803735C4: beql        $t3, $zero, L_803735D8
    if (ctx->r11 == 0) {
        // 0x803735C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803735D8;
    }
    goto skip_1;
    // 0x803735C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x803735CC: jal         0x803717C0
    // 0x803735D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_2;
    // 0x803735D0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_803735D4:
    // 0x803735D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803735D8:
    // 0x803735D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803735DC: jr          $ra
    // 0x803735E0: nop

    return;
    // 0x803735E0: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetCharacterSpacing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FD4: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x80131FD8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80131FDC: addiu       $t7, $t6, -0x27
    ctx->r15 = ADD32(ctx->r14, -0X27);
    // 0x80131FE0: sltiu       $at, $t7, 0x33
    ctx->r1 = ctx->r15 < 0X33 ? 1 : 0;
    // 0x80131FE4: beq         $at, $zero, L_801320C8
    if (ctx->r1 == 0) {
        // 0x80131FE8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_801320C8;
    }
    // 0x80131FE8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80131FEC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80131FF0: addu        $at, $at, $t7
    gpr jr_addend_80131FF8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80131FF4: lw          $t7, -0x72A0($at)
    ctx->r15 = ADD32(ctx->r1, -0X72A0);
    // 0x80131FF8: jr          $t7
    // 0x80131FFC: nop

    switch (jr_addend_80131FF8 >> 2) {
        case 0: goto L_801320A8; break;
        case 1: goto L_801320C8; break;
        case 2: goto L_801320C8; break;
        case 3: goto L_801320C8; break;
        case 4: goto L_801320C8; break;
        case 5: goto L_801320C8; break;
        case 6: goto L_801320C8; break;
        case 7: goto L_801320B8; break;
        case 8: goto L_801320C8; break;
        case 9: goto L_801320C8; break;
        case 10: goto L_801320C8; break;
        case 11: goto L_801320C8; break;
        case 12: goto L_801320C8; break;
        case 13: goto L_801320C8; break;
        case 14: goto L_801320C8; break;
        case 15: goto L_801320C8; break;
        case 16: goto L_801320C8; break;
        case 17: goto L_801320C8; break;
        case 18: goto L_801320C8; break;
        case 19: goto L_801320C8; break;
        case 20: goto L_801320C8; break;
        case 21: goto L_801320C8; break;
        case 22: goto L_801320C8; break;
        case 23: goto L_801320C8; break;
        case 24: goto L_801320C8; break;
        case 25: goto L_801320C8; break;
        case 26: goto L_80132000; break;
        case 27: goto L_801320C8; break;
        case 28: goto L_801320C8; break;
        case 29: goto L_801320C8; break;
        case 30: goto L_801320C8; break;
        case 31: goto L_80132044; break;
        case 32: goto L_801320C8; break;
        case 33: goto L_801320C8; break;
        case 34: goto L_801320C8; break;
        case 35: goto L_801320C8; break;
        case 36: goto L_801320C8; break;
        case 37: goto L_801320C8; break;
        case 38: goto L_801320C8; break;
        case 39: goto L_801320C8; break;
        case 40: goto L_801320C8; break;
        case 41: goto L_80132044; break;
        case 42: goto L_80132078; break;
        case 43: goto L_801320C8; break;
        case 44: goto L_801320C8; break;
        case 45: goto L_80132078; break;
        case 46: goto L_801320C8; break;
        case 47: goto L_80132044; break;
        case 48: goto L_801320C8; break;
        case 49: goto L_801320C8; break;
        case 50: goto L_80132044; break;
        default: switch_error(__func__, 0x80131FF8, 0x80138D60);
    }
    // 0x80131FFC: nop

L_80132000:
    // 0x80132000: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80132004: addiu       $t9, $t8, -0x46
    ctx->r25 = ADD32(ctx->r24, -0X46);
    // 0x80132008: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x8013200C: beq         $at, $zero, L_80132034
    if (ctx->r1 == 0) {
        // 0x80132010: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80132034;
    }
    // 0x80132010: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80132014: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80132018: addu        $at, $at, $t9
    gpr jr_addend_80132020 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8013201C: lw          $t9, -0x71D4($at)
    ctx->r25 = ADD32(ctx->r1, -0X71D4);
    // 0x80132020: jr          $t9
    // 0x80132024: nop

    switch (jr_addend_80132020 >> 2) {
        case 0: goto L_80132028; break;
        case 1: goto L_80132034; break;
        case 2: goto L_80132034; break;
        case 3: goto L_80132034; break;
        case 4: goto L_80132034; break;
        case 5: goto L_80132034; break;
        case 6: goto L_80132034; break;
        case 7: goto L_80132034; break;
        case 8: goto L_80132034; break;
        case 9: goto L_80132034; break;
        case 10: goto L_80132028; break;
        case 11: goto L_80132034; break;
        case 12: goto L_80132034; break;
        case 13: goto L_80132034; break;
        case 14: goto L_80132028; break;
        case 15: goto L_80132034; break;
        case 16: goto L_80132028; break;
        case 17: goto L_80132034; break;
        case 18: goto L_80132034; break;
        case 19: goto L_80132028; break;
        default: switch_error(__func__, 0x80132020, 0x80138E2C);
    }
    // 0x80132024: nop

L_80132028:
    // 0x80132028: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8013202C: jr          $ra
    // 0x80132030: nop

    return;
    // 0x80132030: nop

L_80132034:
    // 0x80132034: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132038: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013203C: jr          $ra
    // 0x80132040: nop

    return;
    // 0x80132040: nop

L_80132044:
    // 0x80132044: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x80132048: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8013204C: beq         $v1, $at, L_8013205C
    if (ctx->r3 == ctx->r1) {
        // 0x80132050: addiu       $at, $zero, 0x54
        ctx->r1 = ADD32(0, 0X54);
            goto L_8013205C;
    }
    // 0x80132050: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x80132054: bnel        $v1, $at, L_8013206C
    if (ctx->r3 != ctx->r1) {
        // 0x80132058: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8013206C;
    }
    goto skip_0;
    // 0x80132058: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
L_8013205C:
    // 0x8013205C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80132060: jr          $ra
    // 0x80132064: nop

    return;
    // 0x80132064: nop

    // 0x80132068: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8013206C:
    // 0x8013206C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132070: jr          $ra
    // 0x80132074: nop

    return;
    // 0x80132074: nop

L_80132078:
    // 0x80132078: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8013207C: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80132080: beq         $v1, $at, L_8013208C
    if (ctx->r3 == ctx->r1) {
        // 0x80132084: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_8013208C;
    }
    // 0x80132084: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80132088: bne         $v1, $at, L_8013209C
    if (ctx->r3 != ctx->r1) {
        // 0x8013208C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8013209C;
    }
L_8013208C:
    // 0x8013208C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132090: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132094: jr          $ra
    // 0x80132098: nop

    return;
    // 0x80132098: nop

L_8013209C:
    // 0x8013209C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801320A0: jr          $ra
    // 0x801320A4: nop

    return;
    // 0x801320A4: nop

L_801320A8:
    // 0x801320A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801320AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801320B0: jr          $ra
    // 0x801320B4: nop

    return;
    // 0x801320B4: nop

L_801320B8:
    // 0x801320B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801320BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801320C0: jr          $ra
    // 0x801320C4: nop

    return;
    // 0x801320C4: nop

L_801320C8:
    // 0x801320C8: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x801320CC: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x801320D0: bnel        $t0, $at, L_801320E8
    if (ctx->r8 != ctx->r1) {
        // 0x801320D4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801320E8;
    }
    goto skip_1;
    // 0x801320D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x801320D8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801320DC: jr          $ra
    // 0x801320E0: nop

    return;
    // 0x801320E0: nop

    // 0x801320E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_801320E8:
    // 0x801320E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801320EC: nop

    // 0x801320F0: jr          $ra
    // 0x801320F4: nop

    return;
    // 0x801320F4: nop

;}
RECOMP_FUNC void ftCommonAttackHi4CheckInterruptKneeBend(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801506CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801506D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801506D4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801506D8: jal         0x80150628
    // 0x801506DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftCommonAttackHi4CheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x801506DC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x801506E0: beq         $v0, $zero, L_801506F8
    if (ctx->r2 == 0) {
        // 0x801506E4: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_801506F8;
    }
    // 0x801506E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801506E8: jal         0x80150660
    // 0x801506EC: nop

    ftCommonAttackHi4CheckInterruptMain(rdram, ctx);
        goto after_1;
    // 0x801506EC: nop

    after_1:
    // 0x801506F0: b           L_80150700
    // 0x801506F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80150700;
    // 0x801506F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801506F8:
    // 0x801506F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801506FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150700:
    // 0x80150700: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80150704: jr          $ra
    // 0x80150708: nop

    return;
    // 0x80150708: nop

;}
RECOMP_FUNC void mvEndingRoomLightProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132244: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132248: lw          $t6, 0x2BCC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2BCC);
    // 0x8013224C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80132250: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80132254: slti        $at, $t6, 0x154
    ctx->r1 = SIGNED(ctx->r14) < 0X154 ? 1 : 0;
    // 0x80132258: bne         $at, $zero, L_801322AC
    if (ctx->r1 != 0) {
        // 0x8013225C: addiu       $t4, $t4, 0x65B0
        ctx->r12 = ADD32(ctx->r12, 0X65B0);
            goto L_801322AC;
    }
    // 0x8013225C: addiu       $t4, $t4, 0x65B0
    ctx->r12 = ADD32(ctx->r12, 0X65B0);
    // 0x80132260: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132264: addiu       $t3, $t3, 0x2BFC
    ctx->r11 = ADD32(ctx->r11, 0X2BFC);
    // 0x80132268: lui         $at, 0x435C
    ctx->r1 = S32(0X435C << 16);
    // 0x8013226C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132270: lwc1        $f0, 0x0($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80132274: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132278: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8013227C: nop

    // 0x80132280: bc1fl       L_801322B0
    if (!c1cs) {
        // 0x80132284: lw          $v1, 0x0($t4)
        ctx->r3 = MEM_W(ctx->r12, 0X0);
            goto L_801322B0;
    }
    goto skip_0;
    // 0x80132284: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    skip_0:
    // 0x80132288: lwc1        $f4, 0x2BBC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2BBC);
    // 0x8013228C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80132290: swc1        $f6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f6.u32l;
    // 0x80132294: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x80132298: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8013229C: nop

    // 0x801322A0: bc1fl       L_801322B0
    if (!c1cs) {
        // 0x801322A4: lw          $v1, 0x0($t4)
        ctx->r3 = MEM_W(ctx->r12, 0X0);
            goto L_801322B0;
    }
    goto skip_1;
    // 0x801322A4: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    skip_1:
    // 0x801322A8: swc1        $f2, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f2.u32l;
L_801322AC:
    // 0x801322AC: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
L_801322B0:
    // 0x801322B0: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x801322B4: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801322B8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801322BC: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801322C0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801322C4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x801322C8: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x801322CC: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x801322D0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801322D4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801322D8: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x801322DC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801322E0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801322E4: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x801322E8: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x801322EC: addiu       $t3, $t3, 0x2BFC
    ctx->r11 = ADD32(ctx->r11, 0X2BFC);
    // 0x801322F0: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x801322F4: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x801322F8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801322FC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80132300: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80132304: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80132308: lwc1        $f10, 0x0($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8013230C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80132310: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80132314: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80132318: nop

    // 0x8013231C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80132320: beql        $t9, $zero, L_80132370
    if (ctx->r25 == 0) {
        // 0x80132324: mfc1        $t9, $f16
        ctx->r25 = (int32_t)ctx->f16.u32l;
            goto L_80132370;
    }
    goto skip_2;
    // 0x80132324: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    skip_2:
    // 0x80132328: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013232C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132330: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80132334: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80132338: nop

    // 0x8013233C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80132340: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80132344: nop

    // 0x80132348: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x8013234C: bne         $t9, $zero, L_80132364
    if (ctx->r25 != 0) {
        // 0x80132350: nop
    
            goto L_80132364;
    }
    // 0x80132350: nop

    // 0x80132354: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80132358: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8013235C: b           L_8013237C
    // 0x80132360: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_8013237C;
    // 0x80132360: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80132364:
    // 0x80132364: b           L_8013237C
    // 0x80132368: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_8013237C;
    // 0x80132368: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8013236C: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
L_80132370:
    // 0x80132370: nop

    // 0x80132374: bltz        $t9, L_80132364
    if (SIGNED(ctx->r25) < 0) {
        // 0x80132378: nop
    
            goto L_80132364;
    }
    // 0x80132378: nop

L_8013237C:
    // 0x8013237C: or          $t6, $t9, $zero
    ctx->r14 = ctx->r25 | 0;
    // 0x80132380: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80132384: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80132388: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8013238C: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x80132390: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80132394: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80132398: lui         $t7, 0xFFFD
    ctx->r15 = S32(0XFFFD << 16);
    // 0x8013239C: lui         $t6, 0xFCFF
    ctx->r14 = S32(0XFCFF << 16);
    // 0x801323A0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801323A4: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x801323A8: ori         $t6, $t6, 0xFFFF
    ctx->r14 = ctx->r14 | 0XFFFF;
    // 0x801323AC: ori         $t7, $t7, 0xF6FB
    ctx->r15 = ctx->r15 | 0XF6FB;
    // 0x801323B0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801323B4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801323B8: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x801323BC: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x801323C0: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x801323C4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801323C8: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x801323CC: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x801323D0: ori         $t6, $t6, 0x4340
    ctx->r14 = ctx->r14 | 0X4340;
    // 0x801323D4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801323D8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801323DC: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x801323E0: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x801323E4: lui         $t8, 0xF64D
    ctx->r24 = S32(0XF64D << 16);
    // 0x801323E8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801323EC: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x801323F0: ori         $t8, $t8, 0x8398
    ctx->r24 = ctx->r24 | 0X8398;
    // 0x801323F4: ori         $t9, $t9, 0x8028
    ctx->r25 = ctx->r25 | 0X8028;
    // 0x801323F8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x801323FC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132400: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80132404: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80132408: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x8013240C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80132410: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80132414: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132418: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8013241C: lw          $v1, 0x0($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X0);
    // 0x80132420: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x80132424: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80132428: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8013242C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80132430: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80132434: jr          $ra
    // 0x80132438: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x80132438: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void mpCommonSetFighterLandingParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DE36C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE370: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DE374: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800DE378: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800DE37C: lwc1        $f2, 0x82C($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X82C);
    // 0x800DE380: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x800DE384: nop

    // 0x800DE388: bc1tl       L_800DE408
    if (c1cs) {
        // 0x800DE38C: lw          $t7, 0x8($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X8);
            goto L_800DE408;
    }
    goto skip_0;
    // 0x800DE38C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x800DE390: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800DE394: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800DE398: addiu       $v1, $v1, 0x1308
    ctx->r3 = ADD32(ctx->r3, 0X1308);
    // 0x800DE39C: c.le.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl <= ctx->f2.fl;
    // 0x800DE3A0: lui         $at, 0x43E1
    ctx->r1 = S32(0X43E1 << 16);
    // 0x800DE3A4: bc1fl       L_800DE3FC
    if (!c1cs) {
        // 0x800DE3A8: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_800DE3FC;
    }
    goto skip_1;
    // 0x800DE3A8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
    // 0x800DE3AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800DE3B0: lwc1        $f8, 0x2C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x800DE3B4: lw          $t6, 0x8E8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8E8);
    // 0x800DE3B8: add.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f12.fl;
    // 0x800DE3BC: lwc1        $f0, 0x1C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800DE3C0: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x800DE3C4: nop

    // 0x800DE3C8: bc1tl       L_800DE3EC
    if (c1cs) {
        // 0x800DE3CC: mfc1        $a1, $f2
        ctx->r5 = (int32_t)ctx->f2.u32l;
            goto L_800DE3EC;
    }
    goto skip_2;
    // 0x800DE3CC: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    skip_2:
    // 0x800DE3D0: lwc1        $f16, 0x28($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X28);
    // 0x800DE3D4: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800DE3D8: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800DE3DC: nop

    // 0x800DE3E0: bc1fl       L_800DE3FC
    if (!c1cs) {
        // 0x800DE3E4: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_800DE3FC;
    }
    goto skip_3;
    // 0x800DE3E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_3:
    // 0x800DE3E8: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
L_800DE3EC:
    // 0x800DE3EC: jal         0x80164F70
    // 0x800DE3F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftPublicPlayCliffReact(rdram, ctx);
        goto after_0;
    // 0x800DE3F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800DE3F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800DE3F8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_800DE3FC:
    // 0x800DE3FC: nop

    // 0x800DE400: swc1        $f4, 0x82C($v0)
    MEM_W(0X82C, ctx->r2) = ctx->f4.u32l;
    // 0x800DE404: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
L_800DE408:
    // 0x800DE408: sltiu       $at, $t7, 0x19
    ctx->r1 = ctx->r15 < 0X19 ? 1 : 0;
    // 0x800DE40C: beq         $at, $zero, L_800DE44C
    if (ctx->r1 == 0) {
        // 0x800DE410: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800DE44C;
    }
    // 0x800DE410: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800DE414: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800DE418: addu        $at, $at, $t7
    gpr jr_addend_800DE420 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800DE41C: lw          $t7, -0x4FC($at)
    ctx->r15 = ADD32(ctx->r1, -0X4FC);
    // 0x800DE420: jr          $t7
    // 0x800DE424: nop

    switch (jr_addend_800DE420 >> 2) {
        case 0: goto L_800DE428; break;
        case 1: goto L_800DE44C; break;
        case 2: goto L_800DE44C; break;
        case 3: goto L_800DE430; break;
        case 4: goto L_800DE438; break;
        case 5: goto L_800DE44C; break;
        case 6: goto L_800DE44C; break;
        case 7: goto L_800DE440; break;
        case 8: goto L_800DE44C; break;
        case 9: goto L_800DE44C; break;
        case 10: goto L_800DE448; break;
        case 11: goto L_800DE44C; break;
        case 12: goto L_800DE44C; break;
        case 13: goto L_800DE428; break;
        case 14: goto L_800DE428; break;
        case 15: goto L_800DE44C; break;
        case 16: goto L_800DE44C; break;
        case 17: goto L_800DE430; break;
        case 18: goto L_800DE438; break;
        case 19: goto L_800DE44C; break;
        case 20: goto L_800DE44C; break;
        case 21: goto L_800DE440; break;
        case 22: goto L_800DE44C; break;
        case 23: goto L_800DE44C; break;
        case 24: goto L_800DE448; break;
        default: switch_error(__func__, 0x800DE420, 0x8012FB04);
    }
    // 0x800DE424: nop

L_800DE428:
    // 0x800DE428: b           L_800DE44C
    // 0x800DE42C: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
        goto L_800DE44C;
    // 0x800DE42C: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
L_800DE430:
    // 0x800DE430: b           L_800DE44C
    // 0x800DE434: sw          $zero, 0xAE0($v0)
    MEM_W(0XAE0, ctx->r2) = 0;
        goto L_800DE44C;
    // 0x800DE434: sw          $zero, 0xAE0($v0)
    MEM_W(0XAE0, ctx->r2) = 0;
L_800DE438:
    // 0x800DE438: b           L_800DE44C
    // 0x800DE43C: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
        goto L_800DE44C;
    // 0x800DE43C: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
L_800DE440:
    // 0x800DE440: b           L_800DE44C
    // 0x800DE444: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
        goto L_800DE44C;
    // 0x800DE444: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
L_800DE448:
    // 0x800DE448: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
L_800DE44C:
    // 0x800DE44C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE450: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DE454: jr          $ra
    // 0x800DE458: nop

    return;
    // 0x800DE458: nop

;}
RECOMP_FUNC void mnMessageMakeExclaimCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320C8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801320CC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801320D0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801320D4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801320D8: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801320DC: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801320E0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x801320E4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801320E8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801320EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801320F0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801320F4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801320F8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801320FC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132100: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132104: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132108: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013210C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132110: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132114: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132118: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013211C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132120: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132124: jal         0x8000B93C
    // 0x80132128: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132128: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013212C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132130: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132134: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132138: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013213C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132140: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132144: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132148: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013214C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132150: jal         0x80007080
    // 0x80132154: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132154: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132158: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013215C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132160: jr          $ra
    // 0x80132164: nop

    return;
    // 0x80132164: nop

;}
RECOMP_FUNC void mnStartupActorFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C20: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131C24: addiu       $v1, $v1, 0x2070
    ctx->r3 = ADD32(ctx->r3, 0X2070);
    // 0x80131C28: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131C34: beq         $v0, $zero, L_80131C48
    if (ctx->r2 == 0) {
        // 0x80131C38: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80131C48;
    }
    // 0x80131C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80131C3C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80131C40: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131C44: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80131C48:
    // 0x80131C48: bne         $v0, $zero, L_80131C80
    if (ctx->r2 != 0) {
        // 0x80131C4C: nop
    
            goto L_80131C80;
    }
    // 0x80131C4C: nop

    // 0x80131C50: jal         0x8039076C
    // 0x80131C54: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x80131C54: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x80131C58: beq         $v0, $zero, L_80131C80
    if (ctx->r2 == 0) {
        // 0x80131C5C: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80131C80;
    }
    // 0x80131C5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80131C60: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80131C64: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80131C68: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80131C6C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80131C70: jal         0x80005C74
    // 0x80131C74: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x80131C74: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    after_1:
    // 0x80131C78: b           L_80131CAC
    // 0x80131C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80131CAC;
    // 0x80131C7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131C80:
    // 0x80131C80: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131C84: lw          $t9, 0x2074($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2074);
    // 0x80131C88: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80131C8C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80131C90: beq         $t9, $zero, L_80131CA8
    if (ctx->r25 == 0) {
        // 0x80131C94: addiu       $t1, $zero, 0x1C
        ctx->r9 = ADD32(0, 0X1C);
            goto L_80131CA8;
    }
    // 0x80131C94: addiu       $t1, $zero, 0x1C
    ctx->r9 = ADD32(0, 0X1C);
    // 0x80131C98: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80131C9C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80131CA0: jal         0x80005C74
    // 0x80131CA4: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_2;
    // 0x80131CA4: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_2:
L_80131CA8:
    // 0x80131CA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80131CAC:
    // 0x80131CAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131CB0: jr          $ra
    // 0x80131CB4: nop

    return;
    // 0x80131CB4: nop

;}
RECOMP_FUNC void sc1PGameBossWallpaperProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192620: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80192624: addiu       $v0, $v0, 0x38D8
    ctx->r2 = ADD32(ctx->r2, 0X38D8);
    // 0x80192628: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8019262C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80192630: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80192634: bne         $t6, $zero, L_80192678
    if (ctx->r14 != 0) {
        // 0x80192638: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80192678;
    }
    // 0x80192638: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8019263C: jal         0x80191A94
    // 0x80192640: nop

    sc1PGameBossUpdateWallpaperColorID(rdram, ctx);
        goto after_0;
    // 0x80192640: nop

    after_0:
    // 0x80192644: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80192648: addiu       $v0, $v0, 0x38D8
    ctx->r2 = ADD32(ctx->r2, 0X38D8);
    // 0x8019264C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80192650: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x80192654: addiu       $t9, $t9, 0x2D4C
    ctx->r25 = ADD32(ctx->r25, 0X2D4C);
    // 0x80192658: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8019265C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80192660: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80192664: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80192668: jal         0x801924E0
    // 0x8019266C: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    sc1PGameBossAdvanceWallpaper(rdram, ctx);
        goto after_1;
    // 0x8019266C: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
    after_1:
    // 0x80192670: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80192674: addiu       $v0, $v0, 0x38D8
    ctx->r2 = ADD32(ctx->r2, 0X38D8);
L_80192678:
    // 0x80192678: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8019267C: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80192680: beq         $a0, $v1, L_8019268C
    if (ctx->r4 == ctx->r3) {
        // 0x80192684: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8019268C;
    }
    // 0x80192684: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x80192688: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
L_8019268C:
    // 0x8019268C: lw          $t2, 0x10($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X10);
    // 0x80192690: lw          $v1, 0x1C($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X1C);
    // 0x80192694: beql        $a0, $v1, L_801926DC
    if (ctx->r4 == ctx->r3) {
        // 0x80192698: lw          $t8, 0x8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X8);
            goto L_801926DC;
    }
    goto skip_0;
    // 0x80192698: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x8019269C: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    // 0x801926A0: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x801926A4: lw          $t3, 0x50E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50E8);
    // 0x801926A8: sll         $t5, $t4, 3
    ctx->r13 = S32(ctx->r12 << 3);
    // 0x801926AC: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x801926B0: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801926B4: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x801926B8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x801926BC: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x801926C0: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x801926C4: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801926C8: beql        $at, $zero, L_801926EC
    if (ctx->r1 == 0) {
        // 0x801926CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801926EC;
    }
    goto skip_1;
    // 0x801926CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801926D0: b           L_801926E8
    // 0x801926D4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_801926E8;
    // 0x801926D4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x801926D8: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
L_801926DC:
    // 0x801926DC: bnel        $t8, $zero, L_801926EC
    if (ctx->r24 != 0) {
        // 0x801926E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801926EC;
    }
    goto skip_2;
    // 0x801926E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801926E4: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_801926E8:
    // 0x801926E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801926EC:
    // 0x801926EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801926F0: jr          $ra
    // 0x801926F4: nop

    return;
    // 0x801926F4: nop

;}
RECOMP_FUNC void ftBossGootsubusuWaitProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159BD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80159BD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159BD8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80159BDC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80159BE0: jal         0x800D9414
    // 0x80159BE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftPhysicsApplyAirVelTransNYZ(rdram, ctx);
        goto after_0;
    // 0x80159BE4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80159BE8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80159BEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80159BF0: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80159BF4: lh          $t6, 0xB18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB18);
    // 0x80159BF8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80159BFC: sh          $t7, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r15;
    // 0x80159C00: lh          $t8, 0xB18($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XB18);
    // 0x80159C04: bnel        $t8, $zero, L_80159C20
    if (ctx->r24 != 0) {
        // 0x80159C08: lw          $t9, 0xADC($v0)
        ctx->r25 = MEM_W(ctx->r2, 0XADC);
            goto L_80159C20;
    }
    goto skip_0;
    // 0x80159C08: lw          $t9, 0xADC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XADC);
    skip_0:
    // 0x80159C0C: jal         0x80159E50
    // 0x80159C10: nop

    ftBossGootsubusuDownSetStatus(rdram, ctx);
        goto after_1;
    // 0x80159C10: nop

    after_1:
    // 0x80159C14: b           L_80159C98
    // 0x80159C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80159C98;
    // 0x80159C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159C1C: lw          $t9, 0xADC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XADC);
L_80159C20:
    // 0x80159C20: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x80159C24: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80159C28: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x80159C2C: lwc1        $f6, 0x1C($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80159C30: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80159C34: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x80159C38: lwc1        $f4, 0x1C($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x80159C3C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80159C40: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80159C44: nop

    // 0x80159C48: bc1fl       L_80159C5C
    if (!c1cs) {
        // 0x80159C4C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80159C5C;
    }
    goto skip_1;
    // 0x80159C4C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x80159C50: b           L_80159C5C
    // 0x80159C54: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80159C5C;
    // 0x80159C54: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80159C58: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80159C5C:
    // 0x80159C5C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80159C60: nop

    // 0x80159C64: bc1fl       L_80159C94
    if (!c1cs) {
        // 0x80159C68: swc1        $f0, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
            goto L_80159C94;
    }
    goto skip_2;
    // 0x80159C68: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    skip_2:
    // 0x80159C6C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80159C70: lui         $at, 0xC20C
    ctx->r1 = S32(0XC20C << 16);
    // 0x80159C74: bc1fl       L_80159C88
    if (!c1cs) {
        // 0x80159C78: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80159C88;
    }
    goto skip_3;
    // 0x80159C78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x80159C7C: b           L_80159C94
    // 0x80159C80: swc1        $f14, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f14.u32l;
        goto L_80159C94;
    // 0x80159C80: swc1        $f14, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f14.u32l;
    // 0x80159C84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80159C88:
    // 0x80159C88: b           L_80159C94
    // 0x80159C8C: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
        goto L_80159C94;
    // 0x80159C8C: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x80159C90: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
L_80159C94:
    // 0x80159C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80159C98:
    // 0x80159C98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80159C9C: jr          $ra
    // 0x80159CA0: nop

    return;
    // 0x80159CA0: nop

;}
RECOMP_FUNC void unref_80017DE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017DE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80017DE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80017DEC: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80017DF0: addiu       $a1, $a1, 0x65B4
    ctx->r5 = ADD32(ctx->r5, 0X65B4);
    // 0x80017DF4: jal         0x80017D3C
    // 0x80017DF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80017D3C(rdram, ctx);
        goto after_0;
    // 0x80017DF8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80017DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80017E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80017E04: jr          $ra
    // 0x80017E08: nop

    return;
    // 0x80017E08: nop

;}
RECOMP_FUNC void itLinkBombFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185CF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80185CF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80185CF8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80185CFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80185D00: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80185D04: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80185D08: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80185D0C: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80185D10: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    // 0x80185D14: jal         0x80172558
    // 0x80185D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80185D18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80185D1C: lw          $v0, 0x2C0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C0);
    // 0x80185D20: bnel        $v0, $zero, L_80185D38
    if (ctx->r2 != 0) {
        // 0x80185D24: mtc1        $v0, $f4
        ctx->f4.u32l = ctx->r2;
            goto L_80185D38;
    }
    goto skip_0;
    // 0x80185D24: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    skip_0:
    // 0x80185D28: jal         0x80186368
    // 0x80185D2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itLinkBombExplodeInitVars(rdram, ctx);
        goto after_1;
    // 0x80185D2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80185D30: lw          $v0, 0x2C0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C0);
    // 0x80185D34: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
L_80185D38:
    // 0x80185D38: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x80185D3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80185D40: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80185D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80185D48: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x80185D4C: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x80185D50: nop

    // 0x80185D54: bc1fl       L_80185D80
    if (!c1cs) {
        // 0x80185D58: lui         $at, 0x42C0
        ctx->r1 = S32(0X42C0 << 16);
            goto L_80185D80;
    }
    goto skip_1;
    // 0x80185D58: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    skip_1:
    // 0x80185D5C: jal         0x80172F98
    // 0x80185D60: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    itMainCheckSetColAnimID(rdram, ctx);
        goto after_2;
    // 0x80185D60: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    after_2:
    // 0x80185D64: lw          $v0, 0x2C0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C0);
    // 0x80185D68: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80185D6C: sh          $t6, 0x354($s0)
    MEM_H(0X354, ctx->r16) = ctx->r14;
    // 0x80185D70: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80185D74: nop

    // 0x80185D78: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80185D7C: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
L_80185D80:
    // 0x80185D80: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80185D84: nop

    // 0x80185D88: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80185D8C: nop

    // 0x80185D90: bc1fl       L_80185DA8
    if (!c1cs) {
        // 0x80185D94: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80185DA8;
    }
    goto skip_2;
    // 0x80185D94: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_2:
    // 0x80185D98: jal         0x801859C0
    // 0x80185D9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itLinkBombExplodeWaitUpdateScale(rdram, ctx);
        goto after_3;
    // 0x80185D9C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80185DA0: lw          $v0, 0x2C0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X2C0);
    // 0x80185DA4: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_80185DA8:
    // 0x80185DA8: sw          $t7, 0x2C0($s0)
    MEM_W(0X2C0, ctx->r16) = ctx->r15;
    // 0x80185DAC: jal         0x801713F4
    // 0x80185DB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itVisualsUpdateSpin(rdram, ctx);
        goto after_4;
    // 0x80185DB0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80185DB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80185DB8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80185DBC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80185DC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80185DC4: jr          $ra
    // 0x80185DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80185DC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void wpNessPKReflectHeadProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B7FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016B800: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B804: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016B808: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8016B80C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016B810: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x8016B814: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8016B818: jal         0x800FE068
    // 0x8016B81C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016B81C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016B820: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8016B824: jal         0x8016B6A0
    // 0x8016B828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKReflectHeadSetDestroyTrails(rdram, ctx);
        goto after_1;
    // 0x8016B828: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x8016B82C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B830: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016B834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016B838: jr          $ra
    // 0x8016B83C: nop

    return;
    // 0x8016B83C: nop

;}
RECOMP_FUNC void syVectorAngleDiff3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800191FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80019200: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019204: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80019208: jal         0x80018F7C
    // 0x8001920C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    syVectorMag3D(rdram, ctx);
        goto after_0;
    // 0x8001920C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80019210: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80019214: jal         0x80018F7C
    // 0x80019218: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    syVectorMag3D(rdram, ctx);
        goto after_1;
    // 0x80019218: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x8001921C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80019220: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80019224: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80019228: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8001922C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80019230: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    // 0x80019234: nop

    // 0x80019238: bc1tl       L_800192C0
    if (c1cs) {
        // 0x8001923C: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_800192C0;
    }
    goto skip_0;
    // 0x8001923C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    skip_0:
    // 0x80019240: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80019244: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019248: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001924C: lwc1        $f18, 0x4($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019250: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80019254: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80019258: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001925C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80019260: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019264: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80019268: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001926C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80019270: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80019274: add.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x80019278: div.s       $f12, $f10, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8001927C: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80019280: nop

    // 0x80019284: bc1fl       L_80019294
    if (!c1cs) {
        // 0x80019288: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80019294;
    }
    goto skip_1;
    // 0x80019288: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_1:
    // 0x8001928C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80019290: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80019294:
    // 0x80019294: nop

    // 0x80019298: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001929C: nop

    // 0x800192A0: bc1f        L_800192AC
    if (!c1cs) {
        // 0x800192A4: nop
    
            goto L_800192AC;
    }
    // 0x800192A4: nop

    // 0x800192A8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_800192AC:
    // 0x800192AC: jal         0x800187C0
    // 0x800192B0: nop

    syUtilsArcCos(rdram, ctx);
        goto after_2;
    // 0x800192B0: nop

    after_2:
    // 0x800192B4: b           L_800192C4
    // 0x800192B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800192C4;
    // 0x800192B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800192BC: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_800192C0:
    // 0x800192C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800192C4:
    // 0x800192C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800192C8: jr          $ra
    // 0x800192CC: nop

    return;
    // 0x800192CC: nop

;}
RECOMP_FUNC void ifCommonTrafficMakeSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112234: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80112238: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x8011223C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80112240: addiu       $t7, $t7, -0x131C
    ctx->r15 = ADD32(ctx->r15, -0X131C);
    // 0x80112244: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80112248: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    // 0x8011224C: lbu         $v1, 0x4($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X4);
    // 0x80112250: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80112254: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80112258: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8011225C: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80112260: lw          $t9, -0x12C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X12C0);
    // 0x80112264: lw          $t0, 0xD44($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XD44);
    // 0x80112268: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8011226C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80112270: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x80112274: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80112278: jal         0x800CCFDC
    // 0x8011227C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x8011227C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_0:
    // 0x80112280: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80112284: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80112288: addiu       $t1, $zero, 0x1200
    ctx->r9 = ADD32(0, 0X1200);
    // 0x8011228C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80112290: lh          $t2, 0x0($a2)
    ctx->r10 = MEM_H(ctx->r6, 0X0);
    // 0x80112294: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80112298: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x8011229C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801122A0: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801122A4: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x801122A8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801122AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801122B0: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x801122B4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x801122B8: lh          $t3, 0x2($a2)
    ctx->r11 = MEM_H(ctx->r6, 0X2);
    // 0x801122BC: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x801122C0: nop

    // 0x801122C4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801122C8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801122CC: lbu         $t4, -0x1358($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X1358);
    // 0x801122D0: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x801122D4: lbu         $t5, -0x134C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X134C);
    // 0x801122D8: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x801122DC: lbu         $t6, -0x1340($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1340);
    // 0x801122E0: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x801122E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801122E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801122EC: jr          $ra
    // 0x801122F0: nop

    return;
    // 0x801122F0: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015286C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152874: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80152878: jal         0x800DDDDC
    // 0x8015287C: addiu       $a1, $a1, 0x28F4
    ctx->r5 = ADD32(ctx->r5, 0X28F4);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015287C: addiu       $a1, $a1, 0x28F4
    ctx->r5 = ADD32(ctx->r5, 0X28F4);
    after_0:
    // 0x80152880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152888: jr          $ra
    // 0x8015288C: nop

    return;
    // 0x8015288C: nop

;}
RECOMP_FUNC void mvOpeningDonkeyFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD80: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DD84: addiu       $v0, $v0, -0x1E38
    ctx->r2 = ADD32(ctx->r2, -0X1E38);
    // 0x8018DD88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DD8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DD90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DD94: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018DD98: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018DD9C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DDA0: jal         0x8039076C
    // 0x8018DDA4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x8018DDA4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x8018DDA8: beq         $v0, $zero, L_8018DDC8
    if (ctx->r2 == 0) {
        // 0x8018DDAC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018DDC8;
    }
    // 0x8018DDAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DDB0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DDB4: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DDB8: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DDBC: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8018DDC0: jal         0x80005C74
    // 0x8018DDC4: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8018DDC4: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_1:
L_8018DDC8:
    // 0x8018DDC8: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DDCC: lw          $v0, -0x1E38($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1E38);
    // 0x8018DDD0: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018DDD4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DDD8: bnel        $v0, $at, L_8018DE0C
    if (ctx->r2 != ctx->r1) {
        // 0x8018DDDC: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_8018DE0C;
    }
    goto skip_0;
    // 0x8018DDDC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_0:
    // 0x8018DDE0: jal         0x80009A84
    // 0x8018DDE4: lw          $a0, -0x1E34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E34);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8018DDE4: lw          $a0, -0x1E34($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E34);
    after_2:
    // 0x8018DDE8: jal         0x8018D604
    // 0x8018DDEC: nop

    mvOpeningDonkeyMakeMotionWindow(rdram, ctx);
        goto after_3;
    // 0x8018DDEC: nop

    after_3:
    // 0x8018DDF0: jal         0x8018D934
    // 0x8018DDF4: nop

    mvOpeningDonkeyMakePosedWallpaper(rdram, ctx);
        goto after_4;
    // 0x8018DDF4: nop

    after_4:
    // 0x8018DDF8: jal         0x8018DA50
    // 0x8018DDFC: nop

    mvOpeningDonkeyMakePosedFighter(rdram, ctx);
        goto after_5;
    // 0x8018DDFC: nop

    after_5:
    // 0x8018DE00: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE04: lw          $v0, -0x1E38($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1E38);
    // 0x8018DE08: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_8018DE0C:
    // 0x8018DE0C: bne         $v0, $at, L_8018DE2C
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE10: addiu       $t1, $zero, 0x22
        ctx->r9 = ADD32(0, 0X22);
            goto L_8018DE2C;
    }
    // 0x8018DE10: addiu       $t1, $zero, 0x22
    ctx->r9 = ADD32(0, 0X22);
    // 0x8018DE14: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE18: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DE1C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DE20: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8018DE24: jal         0x80005C74
    // 0x8018DE28: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x8018DE28: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_6:
L_8018DE2C:
    // 0x8018DE2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DE30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DE34: jr          $ra
    // 0x8018DE38: nop

    return;
    // 0x8018DE38: nop

;}
RECOMP_FUNC void mvOpeningPortraitsBlockRow2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E60: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80131E64: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x80131E68: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131E6C: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80131E70: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131E74: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131E78: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131E7C: ori         $t8, $t8, 0x81E0
    ctx->r24 = ctx->r24 | 0X81E0;
    // 0x80131E80: ori         $t7, $t7, 0x82BC
    ctx->r15 = ctx->r15 | 0X82BC;
    // 0x80131E84: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131E88: jr          $ra
    // 0x80131E8C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131E8C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}

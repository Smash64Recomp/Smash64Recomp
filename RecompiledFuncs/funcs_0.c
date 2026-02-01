#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itMBallMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CE0C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8017CE10: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8017CE14: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8017CE18: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017CE1C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8017CE20: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8017CE24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017CE28: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017CE2C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x8017CE30: addiu       $a1, $a1, -0x5770
    ctx->r5 = ADD32(ctx->r5, -0X5770);
    // 0x8017CE34: jal         0x8016E174
    // 0x8017CE38: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017CE38: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x8017CE3C: beq         $v0, $zero, L_8017CF08
    if (ctx->r2 == 0) {
        // 0x8017CE40: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8017CF08;
    }
    // 0x8017CE40: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8017CE44: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x8017CE48: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    // 0x8017CE4C: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x8017CE50: addiu       $v0, $a0, 0x1C
    ctx->r2 = ADD32(ctx->r4, 0X1C);
    // 0x8017CE54: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8017CE58: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8017CE5C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x8017CE60: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8017CE64: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8017CE68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017CE6C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8017CE70: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x8017CE74: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x8017CE78: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x8017CE7C: sb          $t9, 0x54($t0)
    MEM_B(0X54, ctx->r8) = ctx->r25;
    // 0x8017CE80: lw          $t1, 0x10($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X10);
    // 0x8017CE84: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8017CE88: sb          $zero, 0x54($t2)
    MEM_B(0X54, ctx->r10) = 0;
    // 0x8017CE8C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8017CE90: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8017CE94: jal         0x80008CC0
    // 0x8017CE98: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8017CE98: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    after_1:
    // 0x8017CE9C: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8017CEA0: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    // 0x8017CEA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017CEA8: lw          $t3, 0x10($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X10);
    // 0x8017CEAC: jal         0x80008CC0
    // 0x8017CEB0: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8017CEB0: lw          $a0, 0x8($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X8);
    after_2:
    // 0x8017CEB4: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x8017CEB8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8017CEBC: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8017CEC0: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8017CEC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017CEC8: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8017CECC: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x8017CED0: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8017CED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8017CED8: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8017CEDC: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x8017CEE0: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x8017CEE4: lbu         $t0, 0x2D3($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X2D3);
    // 0x8017CEE8: sh          $t8, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r24;
    // 0x8017CEEC: sh          $zero, 0x350($s0)
    MEM_H(0X350, ctx->r16) = 0;
    // 0x8017CEF0: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x8017CEF4: sb          $t1, 0x2D3($s0)
    MEM_B(0X2D3, ctx->r16) = ctx->r9;
    // 0x8017CEF8: jal         0x80111EC0
    // 0x8017CEFC: swc1        $f4, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f4.u32l;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_3;
    // 0x8017CEFC: swc1        $f4, 0x38($a3)
    MEM_W(0X38, ctx->r7) = ctx->f4.u32l;
    after_3:
    // 0x8017CF00: sw          $v0, 0x348($s0)
    MEM_W(0X348, ctx->r16) = ctx->r2;
    // 0x8017CF04: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_8017CF08:
    // 0x8017CF08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8017CF0C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017CF10: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8017CF14: jr          $ra
    // 0x8017CF18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8017CF18: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl8_80373160(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373160: jr          $ra
    // 0x80373164: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    return;
    // 0x80373164: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
;}
RECOMP_FUNC void mnMessageInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132168: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013216C: lw          $t6, 0x265C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X265C);
    // 0x80132170: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80132174: addiu       $t7, $t7, 0x4AD0
    ctx->r15 = ADD32(ctx->r15, 0X4AD0);
    // 0x80132178: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8013217C: lbu         $t8, 0x2($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X2);
    // 0x80132180: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132184: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80132188: sw          $t8, 0x2658($at)
    MEM_W(0X2658, ctx->r1) = ctx->r24;
    // 0x8013218C: sb          $t9, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r25;
    // 0x80132190: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132194: sw          $zero, 0x2660($at)
    MEM_W(0X2660, ctx->r1) = 0;
    // 0x80132198: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013219C: jr          $ra
    // 0x801321A0: sw          $zero, 0x2664($at)
    MEM_W(0X2664, ctx->r1) = 0;
    return;
    // 0x801321A0: sw          $zero, 0x2664($at)
    MEM_W(0X2664, ctx->r1) = 0;
;}
RECOMP_FUNC void itStarRodWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177EBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177EC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177EC4: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80177EC8: jal         0x801735A0
    // 0x80177ECC: addiu       $a1, $a1, 0x7F4C
    ctx->r5 = ADD32(ctx->r5, 0X7F4C);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80177ECC: addiu       $a1, $a1, 0x7F4C
    ctx->r5 = ADD32(ctx->r5, 0X7F4C);
    after_0:
    // 0x80177ED0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177ED4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177ED8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177EDC: jr          $ra
    // 0x80177EE0: nop

    return;
    // 0x80177EE0: nop

;}
RECOMP_FUNC void func_ovl8_80384124(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384124: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80384128: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8038412C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80384130: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80384134: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80384138: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8038413C: bne         $a0, $zero, L_80384154
    if (ctx->r4 != 0) {
        // 0x80384140: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80384154;
    }
    // 0x80384140: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80384144: jal         0x803717A0
    // 0x80384148: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80384148: addiu       $a0, $zero, 0xD4
    ctx->r4 = ADD32(0, 0XD4);
    after_0:
    // 0x8038414C: beq         $v0, $zero, L_803841C8
    if (ctx->r2 == 0) {
        // 0x80384150: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803841C8;
    }
    // 0x80384150: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80384154:
    // 0x80384154: bne         $s1, $zero, L_80384178
    if (ctx->r17 != 0) {
        // 0x80384158: addiu       $a0, $s0, 0x6C
        ctx->r4 = ADD32(ctx->r16, 0X6C);
            goto L_80384178;
    }
    // 0x80384158: addiu       $a0, $s0, 0x6C
    ctx->r4 = ADD32(ctx->r16, 0X6C);
    // 0x8038415C: addiu       $a1, $s0, 0xC8
    ctx->r5 = ADD32(ctx->r16, 0XC8);
    // 0x80384160: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80384164: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80384168: jal         0x803717E0
    // 0x8038416C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8038416C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    after_1:
    // 0x80384170: jal         0x8037C2D0
    // 0x80384174: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80384174: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
L_80384178:
    // 0x80384178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8038417C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80384180: jal         0x803833A0
    // 0x80384184: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_803833A0(rdram, ctx);
        goto after_3;
    // 0x80384184: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80384188: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x8038418C: jal         0x80372430
    // 0x80384190: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_ovl8_80372430(rdram, ctx);
        goto after_4;
    // 0x80384190: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
    // 0x80384194: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80384198: addiu       $t6, $t6, -0x3270
    ctx->r14 = ADD32(ctx->r14, -0X3270);
    // 0x8038419C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x803841A0: addiu       $t7, $t7, -0x3120
    ctx->r15 = ADD32(ctx->r15, -0X3120);
    // 0x803841A4: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x803841A8: sw          $t7, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->r15;
    // 0x803841AC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x803841B0: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x803841B4: addiu       $t8, $t8, -0x2FC8
    ctx->r24 = ADD32(ctx->r24, -0X2FC8);
    // 0x803841B8: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x803841BC: addiu       $t0, $t0, -0x2FA0
    ctx->r8 = ADD32(ctx->r8, -0X2FA0);
    // 0x803841C0: sw          $t8, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r24;
    // 0x803841C4: sw          $t0, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r8;
L_803841C8:
    // 0x803841C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803841CC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x803841D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x803841D4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x803841D8: jr          $ra
    // 0x803841DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x803841DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_80375270(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375270: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80375274: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80375278: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037527C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80375280: beq         $a0, $zero, L_80375340
    if (ctx->r4 == 0) {
        // 0x80375284: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80375340;
    }
    // 0x80375284: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80375288: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x8037528C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80375290: addiu       $t6, $t6, -0x6990
    ctx->r14 = ADD32(ctx->r14, -0X6990);
    // 0x80375294: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80375298: addiu       $t7, $t7, -0x6958
    ctx->r15 = ADD32(ctx->r15, -0X6958);
    // 0x8037529C: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x803752A0: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x803752A4: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x803752A8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803752AC: addiu       $t9, $t9, -0x6800
    ctx->r25 = ADD32(ctx->r25, -0X6800);
    // 0x803752B0: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x803752B4: lw          $a0, 0x8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8);
    // 0x803752B8: beql        $a0, $zero, L_803752CC
    if (ctx->r4 == 0) {
        // 0x803752BC: lw          $a0, 0xC($s0)
        ctx->r4 = MEM_W(ctx->r16, 0XC);
            goto L_803752CC;
    }
    goto skip_0;
    // 0x803752BC: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x803752C0: jal         0x8037B3E4
    // 0x803752C4: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_0;
    // 0x803752C4: nop

    after_0:
    // 0x803752C8: lw          $a0, 0xC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC);
L_803752CC:
    // 0x803752CC: beql        $a0, $zero, L_803752E0
    if (ctx->r4 == 0) {
        // 0x803752D0: lw          $a0, 0x10($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X10);
            goto L_803752E0;
    }
    goto skip_1;
    // 0x803752D0: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    skip_1:
    // 0x803752D4: jal         0x8037B3E4
    // 0x803752D8: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_1;
    // 0x803752D8: nop

    after_1:
    // 0x803752DC: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
L_803752E0:
    // 0x803752E0: beql        $a0, $zero, L_803752F4
    if (ctx->r4 == 0) {
        // 0x803752E4: lw          $a0, 0x14($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X14);
            goto L_803752F4;
    }
    goto skip_2;
    // 0x803752E4: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    skip_2:
    // 0x803752E8: jal         0x8037B3E4
    // 0x803752EC: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_2;
    // 0x803752EC: nop

    after_2:
    // 0x803752F0: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
L_803752F4:
    // 0x803752F4: beql        $a0, $zero, L_80375308
    if (ctx->r4 == 0) {
        // 0x803752F8: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80375308;
    }
    goto skip_3;
    // 0x803752F8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x803752FC: jal         0x8037B3E4
    // 0x80375300: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_3;
    // 0x80375300: nop

    after_3:
    // 0x80375304: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80375308:
    // 0x80375308: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037530C: beql        $t1, $zero, L_8037532C
    if (ctx->r9 == 0) {
        // 0x80375310: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_8037532C;
    }
    goto skip_4;
    // 0x80375310: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80375314: jal         0x8037C30C
    // 0x80375318: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_4;
    // 0x80375318: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_4:
    // 0x8037531C: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80375320: jal         0x803718C4
    // 0x80375324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_5;
    // 0x80375324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80375328: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_8037532C:
    // 0x8037532C: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80375330: beql        $t3, $zero, L_80375344
    if (ctx->r11 == 0) {
        // 0x80375334: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80375344;
    }
    goto skip_5;
    // 0x80375334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x80375338: jal         0x803717C0
    // 0x8037533C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_6;
    // 0x8037533C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80375340:
    // 0x80375340: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80375344:
    // 0x80375344: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80375348: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037534C: jr          $ra
    // 0x80375350: nop

    return;
    // 0x80375350: nop

;}
RECOMP_FUNC void func_ovl8_8037CEE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CEE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037CEEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037CEF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037CEF4: beq         $a0, $zero, L_8037CF3C
    if (ctx->r4 == 0) {
        // 0x8037CEF8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8037CF3C;
    }
    // 0x8037CEF8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037CEFC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037CF00: addiu       $t6, $t6, -0x5900
    ctx->r14 = ADD32(ctx->r14, -0X5900);
    // 0x8037CF04: sw          $t6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r14;
    // 0x8037CF08: lw          $a0, 0x48($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48);
    // 0x8037CF0C: jal         0x80009A84
    // 0x8037CF10: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x8037CF10: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8037CF14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037CF18: jal         0x803718C4
    // 0x8037CF1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_ovl8_803718C4(rdram, ctx);
        goto after_1;
    // 0x8037CF1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8037CF20: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8037CF24: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8037CF28: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8037CF2C: beql        $t8, $zero, L_8037CF40
    if (ctx->r24 == 0) {
        // 0x8037CF30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037CF40;
    }
    goto skip_0;
    // 0x8037CF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8037CF34: jal         0x803717C0
    // 0x8037CF38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_2;
    // 0x8037CF38: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_8037CF3C:
    // 0x8037CF3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037CF40:
    // 0x8037CF40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037CF44: jr          $ra
    // 0x8037CF48: nop

    return;
    // 0x8037CF48: nop

;}
RECOMP_FUNC void ftCommonAttack11CheckGoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014EEC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014EEC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014EEC8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014EECC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014EED0: lwc1        $f0, 0x150($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X150);
    // 0x8014EED4: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x8014EED8: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8014EEDC: nop

    // 0x8014EEE0: bc1tl       L_8014EF40
    if (c1cs) {
        // 0x8014EEE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014EF40;
    }
    goto skip_0;
    // 0x8014EEE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014EEE8: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8014EEEC: lhu         $t7, 0x1BE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1BE);
    // 0x8014EEF0: lhu         $t8, 0x1B4($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1B4);
    // 0x8014EEF4: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8014EEF8: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8014EEFC: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8014EF00: beq         $t9, $zero, L_8014EF3C
    if (ctx->r25 == 0) {
        // 0x8014EF04: swc1        $f8, 0x150($v0)
        MEM_W(0X150, ctx->r2) = ctx->f8.u32l;
            goto L_8014EF3C;
    }
    // 0x8014EF04: swc1        $f8, 0x150($v0)
    MEM_W(0X150, ctx->r2) = ctx->f8.u32l;
    // 0x8014EF08: lw          $t0, 0x100($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X100);
    // 0x8014EF0C: srl         $t1, $t0, 31
    ctx->r9 = S32(U32(ctx->r8) >> 31);
    // 0x8014EF10: beql        $t1, $zero, L_8014EF40
    if (ctx->r9 == 0) {
        // 0x8014EF14: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014EF40;
    }
    goto skip_1;
    // 0x8014EF14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014EF18: lw          $t2, 0x180($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X180);
    // 0x8014EF1C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8014EF20: beql        $t2, $zero, L_8014EF3C
    if (ctx->r10 == 0) {
        // 0x8014EF24: sw          $t3, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r11;
            goto L_8014EF3C;
    }
    goto skip_2;
    // 0x8014EF24: sw          $t3, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r11;
    skip_2:
    // 0x8014EF28: jal         0x8014EA44
    // 0x8014EF2C: nop

    ftCommonAttack11SetStatus(rdram, ctx);
        goto after_0;
    // 0x8014EF2C: nop

    after_0:
    // 0x8014EF30: b           L_8014EF40
    // 0x8014EF34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014EF40;
    // 0x8014EF34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014EF38: sw          $t3, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r11;
L_8014EF3C:
    // 0x8014EF3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014EF40:
    // 0x8014EF40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014EF44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014EF48: jr          $ra
    // 0x8014EF4C: nop

    return;
    // 0x8014EF4C: nop

;}
RECOMP_FUNC void ftPhysicsSetGroundVelStickRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8ADC: lb          $t6, 0x1C2($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1C2);
    // 0x800D8AE0: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x800D8AE4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D8AE8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800D8AEC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800D8AF0: lwc1        $f2, 0x60($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D8AF4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D8AF8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800D8AFC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800D8B00: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D8B04: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800D8B08: c.le.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl <= ctx->f2.fl;
    // 0x800D8B0C: mul.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800D8B10: bc1fl       L_800D8B58
    if (!c1cs) {
        // 0x800D8B14: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_800D8B58;
    }
    goto skip_0;
    // 0x800D8B14: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x800D8B18: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800D8B1C: nop

    // 0x800D8B20: bc1fl       L_800D8B34
    if (!c1cs) {
        // 0x800D8B24: sub.s       $f4, $f2, $f14
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
            goto L_800D8B34;
    }
    goto skip_1;
    // 0x800D8B24: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
    skip_1:
    // 0x800D8B28: jr          $ra
    // 0x800D8B2C: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800D8B2C: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
    // 0x800D8B30: sub.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f14.fl;
L_800D8B34:
    // 0x800D8B34: swc1        $f4, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f4.u32l;
    // 0x800D8B38: lwc1        $f6, 0x60($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D8B3C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800D8B40: nop

    // 0x800D8B44: bc1f        L_800D8B8C
    if (!c1cs) {
        // 0x800D8B48: nop
    
            goto L_800D8B8C;
    }
    // 0x800D8B48: nop

    // 0x800D8B4C: jr          $ra
    // 0x800D8B50: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800D8B50: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
    // 0x800D8B54: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_800D8B58:
    // 0x800D8B58: nop

    // 0x800D8B5C: bc1fl       L_800D8B70
    if (!c1cs) {
        // 0x800D8B60: add.s       $f10, $f2, $f14
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
            goto L_800D8B70;
    }
    goto skip_2;
    // 0x800D8B60: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
    skip_2:
    // 0x800D8B64: jr          $ra
    // 0x800D8B68: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x800D8B68: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
    // 0x800D8B6C: add.s       $f10, $f2, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f14.fl;
L_800D8B70:
    // 0x800D8B70: swc1        $f10, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f10.u32l;
    // 0x800D8B74: lwc1        $f8, 0x60($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D8B78: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800D8B7C: nop

    // 0x800D8B80: bc1f        L_800D8B8C
    if (!c1cs) {
        // 0x800D8B84: nop
    
            goto L_800D8B8C;
    }
    // 0x800D8B84: nop

    // 0x800D8B88: swc1        $f0, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f0.u32l;
L_800D8B8C:
    // 0x800D8B8C: jr          $ra
    // 0x800D8B90: nop

    return;
    // 0x800D8B90: nop

;}
RECOMP_FUNC void scManagerRunLoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A1980: addiu       $sp, $sp, -0x418
    ctx->r29 = ADD32(ctx->r29, -0X418);
    // 0x800A1984: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A1988: sw          $a0, 0x418($sp)
    MEM_W(0X418, ctx->r29) = ctx->r4;
    // 0x800A198C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800A1990: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800A1994: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800A1998: jal         0x80004394
    // 0x800A199C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    syControllerSetStatusDelay(rdram, ctx);
        goto after_0;
    // 0x800A199C: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_0:
    // 0x800A19A0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A19A4: jal         0x80023004
    // 0x800A19A8: addiu       $a0, $a0, 0x2E84
    ctx->r4 = ADD32(ctx->r4, 0X2E84);
    syDebugSetFuncPrint(rdram, ctx);
        goto after_1;
    // 0x800A19A8: addiu       $a0, $a0, 0x2E84
    ctx->r4 = ADD32(ctx->r4, 0X2E84);
    after_1:
    // 0x800A19AC: jal         0x800235D0
    // 0x800A19B0: nop

    syDebugStartRmonThread5Hang(rdram, ctx);
        goto after_2;
    // 0x800A19B0: nop

    after_2:
    // 0x800A19B4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A19B8: jal         0x80002BE4
    // 0x800A19BC: addiu       $a0, $a0, 0x3070
    ctx->r4 = ADD32(ctx->r4, 0X3070);
    syDmaLoadOverlay(rdram, ctx);
        goto after_3;
    // 0x800A19BC: addiu       $a0, $a0, 0x3070
    ctx->r4 = ADD32(ctx->r4, 0X3070);
    after_3:
    // 0x800A19C0: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x800A19C4: addiu       $s1, $s1, 0x30B8
    ctx->r17 = ADD32(ctx->r17, 0X30B8);
    // 0x800A19C8: jal         0x80002BE4
    // 0x800A19CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_4;
    // 0x800A19CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800A19D0: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x800A19D4: addiu       $s0, $s0, 0x3094
    ctx->r16 = ADD32(ctx->r16, 0X3094);
    // 0x800A19D8: jal         0x80002BE4
    // 0x800A19DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_5;
    // 0x800A19DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800A19E0: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800A19E4: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x800A19E8: addiu       $t7, $t7, 0x3994
    ctx->r15 = ADD32(ctx->r15, 0X3994);
    // 0x800A19EC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800A19F0: addiu       $s2, $s2, 0x4AD0
    ctx->r18 = ADD32(ctx->r18, 0X4AD0);
    // 0x800A19F4: addiu       $v0, $sp, 0x30
    ctx->r2 = ADD32(ctx->r29, 0X30);
    // 0x800A19F8: addiu       $v1, $sp, 0x220
    ctx->r3 = ADD32(ctx->r29, 0X220);
    // 0x800A19FC: addiu       $t6, $t6, 0x44E0
    ctx->r14 = ADD32(ctx->r14, 0X44E0);
    // 0x800A1A00: addiu       $t0, $t7, 0x5E8
    ctx->r8 = ADD32(ctx->r15, 0X5E8);
L_800A1A04:
    // 0x800A1A04: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800A1A08: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800A1A0C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800A1A10: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x800A1A14: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x800A1A18: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x800A1A1C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800A1A20: bne         $t7, $t0, L_800A1A04
    if (ctx->r15 != ctx->r8) {
        // 0x800A1A24: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_800A1A04;
    }
    // 0x800A1A24: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x800A1A28: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800A1A2C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800A1A30: addiu       $t1, $t1, 0x3F80
    ctx->r9 = ADD32(ctx->r9, 0X3F80);
    // 0x800A1A34: addiu       $t5, $t1, 0x48
    ctx->r13 = ADD32(ctx->r9, 0X48);
    // 0x800A1A38: or          $t4, $s2, $zero
    ctx->r12 = ctx->r18 | 0;
    // 0x800A1A3C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
L_800A1A40:
    // 0x800A1A40: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x800A1A44: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x800A1A48: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x800A1A4C: sw          $t3, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r11;
    // 0x800A1A50: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x800A1A54: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
    // 0x800A1A58: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x800A1A5C: bne         $t1, $t5, L_800A1A40
    if (ctx->r9 != ctx->r13) {
        // 0x800A1A60: sw          $t3, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r11;
            goto L_800A1A40;
    }
    // 0x800A1A60: sw          $t3, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r11;
    // 0x800A1A64: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800A1A68: addiu       $t0, $t0, 0x3FC8
    ctx->r8 = ADD32(ctx->r8, 0X3FC8);
    // 0x800A1A6C: addiu       $t9, $t0, 0x1EC
    ctx->r25 = ADD32(ctx->r8, 0X1EC);
    // 0x800A1A70: or          $t8, $v0, $zero
    ctx->r24 = ctx->r2 | 0;
L_800A1A74:
    // 0x800A1A74: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A1A78: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x800A1A7C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800A1A80: sw          $t6, -0xC($t8)
    MEM_W(-0XC, ctx->r24) = ctx->r14;
    // 0x800A1A84: lw          $t7, -0x8($t0)
    ctx->r15 = MEM_W(ctx->r8, -0X8);
    // 0x800A1A88: sw          $t7, -0x8($t8)
    MEM_W(-0X8, ctx->r24) = ctx->r15;
    // 0x800A1A8C: lw          $t6, -0x4($t0)
    ctx->r14 = MEM_W(ctx->r8, -0X4);
    // 0x800A1A90: bne         $t0, $t9, L_800A1A74
    if (ctx->r8 != ctx->r25) {
        // 0x800A1A94: sw          $t6, -0x4($t8)
        MEM_W(-0X4, ctx->r24) = ctx->r14;
            goto L_800A1A74;
    }
    // 0x800A1A94: sw          $t6, -0x4($t8)
    MEM_W(-0X4, ctx->r24) = ctx->r14;
    // 0x800A1A98: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A1A9C: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x800A1AA0: addiu       $t5, $t5, 0x4EF8
    ctx->r13 = ADD32(ctx->r13, 0X4EF8);
    // 0x800A1AA4: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800A1AA8: addiu       $t3, $v0, 0x1EC
    ctx->r11 = ADD32(ctx->r2, 0X1EC);
    // 0x800A1AAC: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_800A1AB0:
    // 0x800A1AB0: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800A1AB4: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x800A1AB8: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x800A1ABC: sw          $t4, -0xC($t5)
    MEM_W(-0XC, ctx->r13) = ctx->r12;
    // 0x800A1AC0: lw          $t1, -0x8($t2)
    ctx->r9 = MEM_W(ctx->r10, -0X8);
    // 0x800A1AC4: sw          $t1, -0x8($t5)
    MEM_W(-0X8, ctx->r13) = ctx->r9;
    // 0x800A1AC8: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x800A1ACC: bne         $t2, $t3, L_800A1AB0
    if (ctx->r10 != ctx->r11) {
        // 0x800A1AD0: sw          $t4, -0x4($t5)
        MEM_W(-0X4, ctx->r13) = ctx->r12;
            goto L_800A1AB0;
    }
    // 0x800A1AD0: sw          $t4, -0x4($t5)
    MEM_W(-0X4, ctx->r13) = ctx->r12;
    // 0x800A1AD4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800A1AD8: or          $t8, $v0, $zero
    ctx->r24 = ctx->r2 | 0;
    // 0x800A1ADC: or          $t7, $v1, $zero
    ctx->r15 = ctx->r3 | 0;
    // 0x800A1AE0: addiu       $t6, $v0, 0x1EC
    ctx->r14 = ADD32(ctx->r2, 0X1EC);
    // 0x800A1AE4: sw          $t4, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r12;
L_800A1AE8:
    // 0x800A1AE8: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800A1AEC: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x800A1AF0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800A1AF4: sw          $t0, -0xC($t7)
    MEM_W(-0XC, ctx->r15) = ctx->r8;
    // 0x800A1AF8: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x800A1AFC: sw          $t9, -0x8($t7)
    MEM_W(-0X8, ctx->r15) = ctx->r25;
    // 0x800A1B00: lw          $t0, -0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, -0X4);
    // 0x800A1B04: bne         $t8, $t6, L_800A1AE8
    if (ctx->r24 != ctx->r14) {
        // 0x800A1B08: sw          $t0, -0x4($t7)
        MEM_W(-0X4, ctx->r15) = ctx->r8;
            goto L_800A1AE8;
    }
    // 0x800A1B08: sw          $t0, -0x4($t7)
    MEM_W(-0X4, ctx->r15) = ctx->r8;
    // 0x800A1B0C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x800A1B10: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800A1B14: addiu       $t3, $t3, 0x4D08
    ctx->r11 = ADD32(ctx->r11, 0X4D08);
    // 0x800A1B18: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800A1B1C: addiu       $t4, $v1, 0x1EC
    ctx->r12 = ADD32(ctx->r3, 0X1EC);
    // 0x800A1B20: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
L_800A1B24:
    // 0x800A1B24: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A1B28: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x800A1B2C: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x800A1B30: sw          $t5, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r13;
    // 0x800A1B34: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x800A1B38: sw          $t2, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r10;
    // 0x800A1B3C: lw          $t5, -0x4($t1)
    ctx->r13 = MEM_W(ctx->r9, -0X4);
    // 0x800A1B40: bne         $t1, $t4, L_800A1B24
    if (ctx->r9 != ctx->r12) {
        // 0x800A1B44: sw          $t5, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r13;
            goto L_800A1B24;
    }
    // 0x800A1B44: sw          $t5, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r13;
    // 0x800A1B48: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800A1B4C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800A1B50: addiu       $t6, $t6, 0x4B18
    ctx->r14 = ADD32(ctx->r14, 0X4B18);
    // 0x800A1B54: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
    // 0x800A1B58: addiu       $t0, $v1, 0x1EC
    ctx->r8 = ADD32(ctx->r3, 0X1EC);
    // 0x800A1B5C: sw          $t5, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r13;
L_800A1B60:
    // 0x800A1B60: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800A1B64: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x800A1B68: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800A1B6C: sw          $t7, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r15;
    // 0x800A1B70: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x800A1B74: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x800A1B78: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x800A1B7C: bne         $t9, $t0, L_800A1B60
    if (ctx->r25 != ctx->r8) {
        // 0x800A1B80: sw          $t7, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r15;
            goto L_800A1B60;
    }
    // 0x800A1B80: sw          $t7, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r15;
    // 0x800A1B84: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800A1B88: jal         0x800D6FE0
    // 0x800A1B8C: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    ftManagerSetupFileSize(rdram, ctx);
        goto after_6;
    // 0x800A1B8C: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
    after_6:
    // 0x800A1B90: addiu       $t4, $zero, 0x48
    ctx->r12 = ADD32(0, 0X48);
    // 0x800A1B94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800A1B98: jal         0x8002102C
    // 0x800A1B9C: sb          $t4, -0x3493($at)
    MEM_B(-0X3493, ctx->r1) = ctx->r12;
    syAudioSetSettingsUpdated(rdram, ctx);
        goto after_7;
    // 0x800A1B9C: sb          $t4, -0x3493($at)
    MEM_B(-0X3493, ctx->r1) = ctx->r12;
    after_7:
    // 0x800A1BA0: jal         0x8002103C
    // 0x800A1BA4: nop

    syAudioGetSettingsUpdated(rdram, ctx);
        goto after_8;
    // 0x800A1BA4: nop

    after_8:
    // 0x800A1BA8: beq         $v0, $zero, L_800A1BC0
    if (ctx->r2 == 0) {
        // 0x800A1BAC: nop
    
            goto L_800A1BC0;
    }
    // 0x800A1BAC: nop

L_800A1BB0:
    // 0x800A1BB0: jal         0x8002103C
    // 0x800A1BB4: nop

    syAudioGetSettingsUpdated(rdram, ctx);
        goto after_9;
    // 0x800A1BB4: nop

    after_9:
    // 0x800A1BB8: bne         $v0, $zero, L_800A1BB0
    if (ctx->r2 != 0) {
        // 0x800A1BBC: nop
    
            goto L_800A1BB0;
    }
    // 0x800A1BBC: nop

L_800A1BC0:
    // 0x800A1BC0: jal         0x80020A40
    // 0x800A1BC4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    syAudioSetFXType(rdram, ctx);
        goto after_10;
    // 0x800A1BC4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_10:
    // 0x800A1BC8: jal         0x80021048
    // 0x800A1BCC: nop

    syAudioGetRestarting(rdram, ctx);
        goto after_11;
    // 0x800A1BCC: nop

    after_11:
    // 0x800A1BD0: beq         $v0, $zero, L_800A1BE8
    if (ctx->r2 == 0) {
        // 0x800A1BD4: nop
    
            goto L_800A1BE8;
    }
    // 0x800A1BD4: nop

L_800A1BD8:
    // 0x800A1BD8: jal         0x80021048
    // 0x800A1BDC: nop

    syAudioGetRestarting(rdram, ctx);
        goto after_12;
    // 0x800A1BDC: nop

    after_12:
    // 0x800A1BE0: bne         $v0, $zero, L_800A1BD8
    if (ctx->r2 != 0) {
        // 0x800A1BE4: nop
    
            goto L_800A1BD8;
    }
    // 0x800A1BE4: nop

L_800A1BE8:
    // 0x800A1BE8: jal         0x800D4644
    // 0x800A1BEC: nop

    lbBackupIsSramValid(rdram, ctx);
        goto after_13;
    // 0x800A1BEC: nop

    after_13:
    // 0x800A1BF0: jal         0x800D46F4
    // 0x800A1BF4: nop

    lbBackupApplyOptions(rdram, ctx);
        goto after_14;
    // 0x800A1BF4: nop

    after_14:
    // 0x800A1BF8: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x800A1BFC: addiu       $v0, $v1, 0x2A00
    ctx->r2 = ADD32(ctx->r3, 0X2A00);
    // 0x800A1C00: lui         $a0, 0x8040
    ctx->r4 = S32(0X8040 << 16);
    // 0x800A1C04: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800A1C08: beq         $at, $zero, L_800A1C24
    if (ctx->r1 == 0) {
        // 0x800A1C0C: lui         $t1, 0x8004
        ctx->r9 = S32(0X8004 << 16);
            goto L_800A1C24;
    }
    // 0x800A1C0C: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x800A1C10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800A1C14:
    // 0x800A1C14: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800A1C18: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x800A1C1C: bne         $at, $zero, L_800A1C14
    if (ctx->r1 != 0) {
        // 0x800A1C20: sh          $v1, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r3;
            goto L_800A1C14;
    }
    // 0x800A1C20: sh          $v1, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r3;
L_800A1C24:
    // 0x800A1C24: lw          $t1, 0x51A0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X51A0);
    // 0x800A1C28: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1C2C: bne         $t1, $zero, L_800A1C38
    if (ctx->r9 != 0) {
        // 0x800A1C30: nop
    
            goto L_800A1C38;
    }
    // 0x800A1C30: nop

    // 0x800A1C34: sb          $zero, 0x0($s2)
    MEM_B(0X0, ctx->r18) = 0;
L_800A1C38:
    // 0x800A1C38: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x800A1C3C: addiu       $s2, $s2, 0x30DC
    ctx->r18 = ADD32(ctx->r18, 0X30DC);
    // 0x800A1C40: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1C44:
    // 0x800A1C44: sltiu       $at, $v0, 0x3E
    ctx->r1 = ctx->r2 < 0X3E ? 1 : 0;
L_800A1C48:
    // 0x800A1C48: beql        $at, $zero, L_800A1C48
    if (ctx->r1 == 0) {
        // 0x800A1C4C: sltiu       $at, $v0, 0x3E
        ctx->r1 = ctx->r2 < 0X3E ? 1 : 0;
            goto L_800A1C48;
    }
    goto skip_0;
    // 0x800A1C4C: sltiu       $at, $v0, 0x3E
    ctx->r1 = ctx->r2 < 0X3E ? 1 : 0;
    skip_0:
    // 0x800A1C50: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800A1C54: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800A1C58: addu        $at, $at, $t3
    gpr jr_addend_800A1C60 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800A1C5C: lw          $t3, 0x43BC($at)
    ctx->r11 = ADD32(ctx->r1, 0X43BC);
    // 0x800A1C60: jr          $t3
    // 0x800A1C64: nop

    switch (jr_addend_800A1C60 >> 2) {
        case 0: goto L_800A1C68; break;
        case 1: goto L_800A1C88; break;
        case 2: goto L_800A1CC8; break;
        case 3: goto L_800A1D00; break;
        case 4: goto L_800A1D40; break;
        case 5: goto L_800A1D88; break;
        case 6: goto L_800A1DA8; break;
        case 7: goto L_800A1DC8; break;
        case 8: goto L_800A1DF0; break;
        case 9: goto L_800A1E68; break;
        case 10: goto L_800A1E90; break;
        case 11: goto L_800A1EB8; break;
        case 12: goto L_800A1EE0; break;
        case 13: goto L_800A1F10; break;
        case 14: goto L_800A1F40; break;
        case 15: goto L_800A1F70; break;
        case 16: goto L_800A1FA0; break;
        case 17: goto L_800A23FC; break;
        case 18: goto L_800A242C; break;
        case 19: goto L_800A245C; break;
        case 20: goto L_800A248C; break;
        case 21: goto L_800A1FD0; break;
        case 22: goto L_800A1FF8; break;
        case 23: goto L_800A2028; break;
        case 24: goto L_800A20D4; break;
        case 25: goto L_800A2104; break;
        case 26: goto L_800A212C; break;
        case 27: goto L_800A215C; break;
        case 28: goto L_800A2184; break;
        case 29: goto L_800A21AC; break;
        case 30: goto L_800A21CC; break;
        case 31: goto L_800A21F4; break;
        case 32: goto L_800A2214; break;
        case 33: goto L_800A2234; break;
        case 34: goto L_800A2254; break;
        case 35: goto L_800A2274; break;
        case 36: goto L_800A2294; break;
        case 37: goto L_800A22B4; break;
        case 38: goto L_800A22D4; break;
        case 39: goto L_800A22F4; break;
        case 40: goto L_800A2314; break;
        case 41: goto L_800A2334; break;
        case 42: goto L_800A2354; break;
        case 43: goto L_800A2374; break;
        case 44: goto L_800A2394; break;
        case 45: goto L_800A23B4; break;
        case 46: goto L_800A23DC; break;
        case 47: goto L_800A24BC; break;
        case 48: goto L_800A24EC; break;
        case 49: goto L_800A251C; break;
        case 50: goto L_800A254C; break;
        case 51: goto L_800A257C; break;
        case 52: goto L_800A2060; break;
        case 53: goto L_800A2074; break;
        case 54: goto L_800A20A4; break;
        case 55: goto L_800A25CC; break;
        case 56: goto L_800A25AC; break;
        case 57: goto L_800A1E18; break;
        case 58: goto L_800A1E40; break;
        case 59: goto L_800A25EC; break;
        case 60: goto L_800A2614; break;
        case 61: goto L_800A2644; break;
        default: switch_error(__func__, 0x800A1C60, 0x800A43BC);
    }
    // 0x800A1C64: nop

L_800A1C68:
    // 0x800A1C68: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1C6C: jal         0x80002BE4
    // 0x800A1C70: addiu       $a0, $a0, 0x31FC
    ctx->r4 = ADD32(ctx->r4, 0X31FC);
    syDmaLoadOverlay(rdram, ctx);
        goto after_15;
    // 0x800A1C70: addiu       $a0, $a0, 0x31FC
    ctx->r4 = ADD32(ctx->r4, 0X31FC);
    after_15:
    // 0x800A1C74: jal         0x800D6604
    // 0x800A1C78: nop

    mnNoControllerStartScene(rdram, ctx);
        goto after_16;
    // 0x800A1C78: nop

    after_16:
    // 0x800A1C7C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1C80: b           L_800A1C44
    // 0x800A1C84: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1C84: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1C88:
    // 0x800A1C88: jal         0x80002BE4
    // 0x800A1C8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_17;
    // 0x800A1C8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x800A1C90: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1C94: jal         0x80002BE4
    // 0x800A1C98: addiu       $a0, $a0, 0x31D8
    ctx->r4 = ADD32(ctx->r4, 0X31D8);
    syDmaLoadOverlay(rdram, ctx);
        goto after_18;
    // 0x800A1C98: addiu       $a0, $a0, 0x31D8
    ctx->r4 = ADD32(ctx->r4, 0X31D8);
    after_18:
    // 0x800A1C9C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1CA0: jal         0x80002BE4
    // 0x800A1CA4: addiu       $a0, $a0, 0x3190
    ctx->r4 = ADD32(ctx->r4, 0X3190);
    syDmaLoadOverlay(rdram, ctx);
        goto after_19;
    // 0x800A1CA4: addiu       $a0, $a0, 0x3190
    ctx->r4 = ADD32(ctx->r4, 0X3190);
    after_19:
    // 0x800A1CA8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1CAC: jal         0x80002BE4
    // 0x800A1CB0: addiu       $a0, $a0, 0x31B4
    ctx->r4 = ADD32(ctx->r4, 0X31B4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_20;
    // 0x800A1CB0: addiu       $a0, $a0, 0x31B4
    ctx->r4 = ADD32(ctx->r4, 0X31B4);
    after_20:
    // 0x800A1CB4: jal         0x801340B8
    // 0x800A1CB8: nop

    mnTitleStartScene(rdram, ctx);
        goto after_21;
    // 0x800A1CB8: nop

    after_21:
    // 0x800A1CBC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1CC0: b           L_800A1C44
    // 0x800A1CC4: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1CC4: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1CC8:
    // 0x800A1CC8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1CCC: jal         0x80002BE4
    // 0x800A1CD0: addiu       $a0, $a0, 0x3220
    ctx->r4 = ADD32(ctx->r4, 0X3220);
    syDmaLoadOverlay(rdram, ctx);
        goto after_22;
    // 0x800A1CD0: addiu       $a0, $a0, 0x3220
    ctx->r4 = ADD32(ctx->r4, 0X3220);
    after_22:
    // 0x800A1CD4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1CD8: jal         0x80002BE4
    // 0x800A1CDC: addiu       $a0, $a0, 0x3190
    ctx->r4 = ADD32(ctx->r4, 0X3190);
    syDmaLoadOverlay(rdram, ctx);
        goto after_23;
    // 0x800A1CDC: addiu       $a0, $a0, 0x3190
    ctx->r4 = ADD32(ctx->r4, 0X3190);
    after_23:
    // 0x800A1CE0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1CE4: jal         0x80002BE4
    // 0x800A1CE8: addiu       $a0, $a0, 0x31B4
    ctx->r4 = ADD32(ctx->r4, 0X31B4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_24;
    // 0x800A1CE8: addiu       $a0, $a0, 0x31B4
    ctx->r4 = ADD32(ctx->r4, 0X31B4);
    after_24:
    // 0x800A1CEC: jal         0x800D6620
    // 0x800A1CF0: nop

    dbMapsStartScene(rdram, ctx);
        goto after_25;
    // 0x800A1CF0: nop

    after_25:
    // 0x800A1CF4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1CF8: b           L_800A1C44
    // 0x800A1CFC: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1CFC: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1D00:
    // 0x800A1D00: jal         0x80002BE4
    // 0x800A1D04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_26;
    // 0x800A1D04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_26:
    // 0x800A1D08: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1D0C: jal         0x80002BE4
    // 0x800A1D10: addiu       $a0, $a0, 0x3244
    ctx->r4 = ADD32(ctx->r4, 0X3244);
    syDmaLoadOverlay(rdram, ctx);
        goto after_27;
    // 0x800A1D10: addiu       $a0, $a0, 0x3244
    ctx->r4 = ADD32(ctx->r4, 0X3244);
    after_27:
    // 0x800A1D14: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1D18: jal         0x80002BE4
    // 0x800A1D1C: addiu       $a0, $a0, 0x3190
    ctx->r4 = ADD32(ctx->r4, 0X3190);
    syDmaLoadOverlay(rdram, ctx);
        goto after_28;
    // 0x800A1D1C: addiu       $a0, $a0, 0x3190
    ctx->r4 = ADD32(ctx->r4, 0X3190);
    after_28:
    // 0x800A1D20: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1D24: jal         0x80002BE4
    // 0x800A1D28: addiu       $a0, $a0, 0x31B4
    ctx->r4 = ADD32(ctx->r4, 0X31B4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_29;
    // 0x800A1D28: addiu       $a0, $a0, 0x31B4
    ctx->r4 = ADD32(ctx->r4, 0X31B4);
    after_29:
    // 0x800A1D2C: jal         0x8013214C
    // 0x800A1D30: nop

    LOOKUP_FUNC(0x8013214C)(rdram, ctx);
        goto after_30;
    // 0x800A1D30: nop

    after_30:
    // 0x800A1D34: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1D38: b           L_800A1C44
    // 0x800A1D3C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1D3C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1D40:
    // 0x800A1D40: jal         0x80002BE4
    // 0x800A1D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_31;
    // 0x800A1D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_31:
    // 0x800A1D48: jal         0x80002BE4
    // 0x800A1D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_32;
    // 0x800A1D4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_32:
    // 0x800A1D50: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1D54: jal         0x80002BE4
    // 0x800A1D58: addiu       $a0, $a0, 0x3268
    ctx->r4 = ADD32(ctx->r4, 0X3268);
    syDmaLoadOverlay(rdram, ctx);
        goto after_33;
    // 0x800A1D58: addiu       $a0, $a0, 0x3268
    ctx->r4 = ADD32(ctx->r4, 0X3268);
    after_33:
    // 0x800A1D5C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1D60: jal         0x80002BE4
    // 0x800A1D64: addiu       $a0, $a0, 0x3190
    ctx->r4 = ADD32(ctx->r4, 0X3190);
    syDmaLoadOverlay(rdram, ctx);
        goto after_34;
    // 0x800A1D64: addiu       $a0, $a0, 0x3190
    ctx->r4 = ADD32(ctx->r4, 0X3190);
    after_34:
    // 0x800A1D68: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1D6C: jal         0x80002BE4
    // 0x800A1D70: addiu       $a0, $a0, 0x31B4
    ctx->r4 = ADD32(ctx->r4, 0X31B4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_35;
    // 0x800A1D70: addiu       $a0, $a0, 0x31B4
    ctx->r4 = ADD32(ctx->r4, 0X31B4);
    after_35:
    // 0x800A1D74: jal         0x80132638
    // 0x800A1D78: nop

    LOOKUP_FUNC(0x80132638)(rdram, ctx);
        goto after_36;
    // 0x800A1D78: nop

    after_36:
    // 0x800A1D7C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1D80: b           L_800A1C44
    // 0x800A1D84: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1D84: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1D88:
    // 0x800A1D88: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1D8C: jal         0x80002BE4
    // 0x800A1D90: addiu       $a0, $a0, 0x328C
    ctx->r4 = ADD32(ctx->r4, 0X328C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_37;
    // 0x800A1D90: addiu       $a0, $a0, 0x328C
    ctx->r4 = ADD32(ctx->r4, 0X328C);
    after_37:
    // 0x800A1D94: jal         0x800D6688
    // 0x800A1D98: nop

    dbFallsStartScene(rdram, ctx);
        goto after_38;
    // 0x800A1D98: nop

    after_38:
    // 0x800A1D9C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1DA0: b           L_800A1C44
    // 0x800A1DA4: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1DA4: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1DA8:
    // 0x800A1DA8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1DAC: jal         0x80002BE4
    // 0x800A1DB0: addiu       $a0, $a0, 0x32B0
    ctx->r4 = ADD32(ctx->r4, 0X32B0);
    syDmaLoadOverlay(rdram, ctx);
        goto after_39;
    // 0x800A1DB0: addiu       $a0, $a0, 0x32B0
    ctx->r4 = ADD32(ctx->r4, 0X32B0);
    after_39:
    // 0x800A1DB4: jal         0x800D6FB0
    // 0x800A1DB8: nop

    mnUnusedFightersStartScene(rdram, ctx);
        goto after_40;
    // 0x800A1DB8: nop

    after_40:
    // 0x800A1DBC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1DC0: b           L_800A1C44
    // 0x800A1DC4: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1DC4: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1DC8:
    // 0x800A1DC8: jal         0x80002BE4
    // 0x800A1DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_41;
    // 0x800A1DCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_41:
    // 0x800A1DD0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1DD4: jal         0x80002BE4
    // 0x800A1DD8: addiu       $a0, $a0, 0x32D4
    ctx->r4 = ADD32(ctx->r4, 0X32D4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_42;
    // 0x800A1DD8: addiu       $a0, $a0, 0x32D4
    ctx->r4 = ADD32(ctx->r4, 0X32D4);
    after_42:
    // 0x800A1DDC: jal         0x80132B34
    // 0x800A1DE0: nop

    mnModeSelectStartScene(rdram, ctx);
        goto after_43;
    // 0x800A1DE0: nop

    after_43:
    // 0x800A1DE4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1DE8: b           L_800A1C44
    // 0x800A1DEC: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1DEC: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1DF0:
    // 0x800A1DF0: jal         0x80002BE4
    // 0x800A1DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_44;
    // 0x800A1DF4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_44:
    // 0x800A1DF8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1DFC: jal         0x80002BE4
    // 0x800A1E00: addiu       $a0, $a0, 0x32F8
    ctx->r4 = ADD32(ctx->r4, 0X32F8);
    syDmaLoadOverlay(rdram, ctx);
        goto after_45;
    // 0x800A1E00: addiu       $a0, $a0, 0x32F8
    ctx->r4 = ADD32(ctx->r4, 0X32F8);
    after_45:
    // 0x800A1E04: jal         0x80133020
    // 0x800A1E08: nop

    mn1PModeStartScene(rdram, ctx);
        goto after_46;
    // 0x800A1E08: nop

    after_46:
    // 0x800A1E0C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1E10: b           L_800A1C44
    // 0x800A1E14: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1E14: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1E18:
    // 0x800A1E18: jal         0x80002BE4
    // 0x800A1E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_47;
    // 0x800A1E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_47:
    // 0x800A1E20: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1E24: jal         0x80002BE4
    // 0x800A1E28: addiu       $a0, $a0, 0x38E0
    ctx->r4 = ADD32(ctx->r4, 0X38E0);
    syDmaLoadOverlay(rdram, ctx);
        goto after_48;
    // 0x800A1E28: addiu       $a0, $a0, 0x38E0
    ctx->r4 = ADD32(ctx->r4, 0X38E0);
    after_48:
    // 0x800A1E2C: jal         0x801335C0
    // 0x800A1E30: nop

    mnOptionStartScene(rdram, ctx);
        goto after_49;
    // 0x800A1E30: nop

    after_49:
    // 0x800A1E34: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1E38: b           L_800A1C44
    // 0x800A1E3C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1E3C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1E40:
    // 0x800A1E40: jal         0x80002BE4
    // 0x800A1E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_50;
    // 0x800A1E44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_50:
    // 0x800A1E48: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1E4C: jal         0x80002BE4
    // 0x800A1E50: addiu       $a0, $a0, 0x3904
    ctx->r4 = ADD32(ctx->r4, 0X3904);
    syDmaLoadOverlay(rdram, ctx);
        goto after_51;
    // 0x800A1E50: addiu       $a0, $a0, 0x3904
    ctx->r4 = ADD32(ctx->r4, 0X3904);
    after_51:
    // 0x800A1E54: jal         0x80132EC0
    // 0x800A1E58: nop

    LOOKUP_FUNC(0x80132EC0)(rdram, ctx);
        goto after_52;
    // 0x800A1E58: nop

    after_52:
    // 0x800A1E5C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1E60: b           L_800A1C44
    // 0x800A1E64: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1E64: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1E68:
    // 0x800A1E68: jal         0x80002BE4
    // 0x800A1E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_53;
    // 0x800A1E6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_53:
    // 0x800A1E70: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1E74: jal         0x80002BE4
    // 0x800A1E78: addiu       $a0, $a0, 0x331C
    ctx->r4 = ADD32(ctx->r4, 0X331C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_54;
    // 0x800A1E78: addiu       $a0, $a0, 0x331C
    ctx->r4 = ADD32(ctx->r4, 0X331C);
    after_54:
    // 0x800A1E7C: jal         0x80134758
    // 0x800A1E80: nop

    LOOKUP_FUNC(0x80134758)(rdram, ctx);
        goto after_55;
    // 0x800A1E80: nop

    after_55:
    // 0x800A1E84: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1E88: b           L_800A1C44
    // 0x800A1E8C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1E8C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1E90:
    // 0x800A1E90: jal         0x80002BE4
    // 0x800A1E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_56;
    // 0x800A1E94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_56:
    // 0x800A1E98: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1E9C: jal         0x80002BE4
    // 0x800A1EA0: addiu       $a0, $a0, 0x3340
    ctx->r4 = ADD32(ctx->r4, 0X3340);
    syDmaLoadOverlay(rdram, ctx);
        goto after_57;
    // 0x800A1EA0: addiu       $a0, $a0, 0x3340
    ctx->r4 = ADD32(ctx->r4, 0X3340);
    after_57:
    // 0x800A1EA4: jal         0x80134668
    // 0x800A1EA8: nop

    mnVSOptionsStartScene(rdram, ctx);
        goto after_58;
    // 0x800A1EA8: nop

    after_58:
    // 0x800A1EAC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1EB0: b           L_800A1C44
    // 0x800A1EB4: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1EB4: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1EB8:
    // 0x800A1EB8: jal         0x80002BE4
    // 0x800A1EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_59;
    // 0x800A1EBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_59:
    // 0x800A1EC0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1EC4: jal         0x80002BE4
    // 0x800A1EC8: addiu       $a0, $a0, 0x3364
    ctx->r4 = ADD32(ctx->r4, 0X3364);
    syDmaLoadOverlay(rdram, ctx);
        goto after_60;
    // 0x800A1EC8: addiu       $a0, $a0, 0x3364
    ctx->r4 = ADD32(ctx->r4, 0X3364);
    after_60:
    // 0x800A1ECC: jal         0x801331B0
    // 0x800A1ED0: nop

    LOOKUP_FUNC(0x801331B0)(rdram, ctx);
        goto after_61;
    // 0x800A1ED0: nop

    after_61:
    // 0x800A1ED4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1ED8: b           L_800A1C44
    // 0x800A1EDC: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1EDC: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1EE0:
    // 0x800A1EE0: jal         0x80002BE4
    // 0x800A1EE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_62;
    // 0x800A1EE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_62:
    // 0x800A1EE8: jal         0x80002BE4
    // 0x800A1EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_63;
    // 0x800A1EEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_63:
    // 0x800A1EF0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1EF4: jal         0x80002BE4
    // 0x800A1EF8: addiu       $a0, $a0, 0x3388
    ctx->r4 = ADD32(ctx->r4, 0X3388);
    syDmaLoadOverlay(rdram, ctx);
        goto after_64;
    // 0x800A1EF8: addiu       $a0, $a0, 0x3388
    ctx->r4 = ADD32(ctx->r4, 0X3388);
    after_64:
    // 0x800A1EFC: jal         0x801323F8
    // 0x800A1F00: nop

    LOOKUP_FUNC(0x801323F8)(rdram, ctx);
        goto after_65;
    // 0x800A1F00: nop

    after_65:
    // 0x800A1F04: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1F08: b           L_800A1C44
    // 0x800A1F0C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1F0C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1F10:
    // 0x800A1F10: jal         0x80002BE4
    // 0x800A1F14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_66;
    // 0x800A1F14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_66:
    // 0x800A1F18: jal         0x80002BE4
    // 0x800A1F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_67;
    // 0x800A1F1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_67:
    // 0x800A1F20: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1F24: jal         0x80002BE4
    // 0x800A1F28: addiu       $a0, $a0, 0x33AC
    ctx->r4 = ADD32(ctx->r4, 0X33AC);
    syDmaLoadOverlay(rdram, ctx);
        goto after_68;
    // 0x800A1F28: addiu       $a0, $a0, 0x33AC
    ctx->r4 = ADD32(ctx->r4, 0X33AC);
    after_68:
    // 0x800A1F2C: jal         0x80132310
    // 0x800A1F30: nop

    sc1PChallengerStartScene(rdram, ctx);
        goto after_69;
    // 0x800A1F30: nop

    after_69:
    // 0x800A1F34: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1F38: b           L_800A1C44
    // 0x800A1F3C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1F3C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1F40:
    // 0x800A1F40: jal         0x80002BE4
    // 0x800A1F44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_70;
    // 0x800A1F44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_70:
    // 0x800A1F48: jal         0x80002BE4
    // 0x800A1F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_71;
    // 0x800A1F4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_71:
    // 0x800A1F50: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1F54: jal         0x80002BE4
    // 0x800A1F58: addiu       $a0, $a0, 0x33D0
    ctx->r4 = ADD32(ctx->r4, 0X33D0);
    syDmaLoadOverlay(rdram, ctx);
        goto after_72;
    // 0x800A1F58: addiu       $a0, $a0, 0x33D0
    ctx->r4 = ADD32(ctx->r4, 0X33D0);
    after_72:
    // 0x800A1F5C: jal         0x80134D98
    // 0x800A1F60: nop

    sc1PIntroStartScene(rdram, ctx);
        goto after_73;
    // 0x800A1F60: nop

    after_73:
    // 0x800A1F64: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1F68: b           L_800A1C44
    // 0x800A1F6C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1F6C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1F70:
    // 0x800A1F70: jal         0x80002BE4
    // 0x800A1F74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_74;
    // 0x800A1F74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_74:
    // 0x800A1F78: jal         0x80002BE4
    // 0x800A1F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_75;
    // 0x800A1F7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_75:
    // 0x800A1F80: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1F84: jal         0x80002BE4
    // 0x800A1F88: addiu       $a0, $a0, 0x33F4
    ctx->r4 = ADD32(ctx->r4, 0X33F4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_76;
    // 0x800A1F88: addiu       $a0, $a0, 0x33F4
    ctx->r4 = ADD32(ctx->r4, 0X33F4);
    after_76:
    // 0x800A1F8C: jal         0x801327D8
    // 0x800A1F90: nop

    mnScreenAdjustStartScene(rdram, ctx);
        goto after_77;
    // 0x800A1F90: nop

    after_77:
    // 0x800A1F94: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1F98: b           L_800A1C44
    // 0x800A1F9C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1F9C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1FA0:
    // 0x800A1FA0: jal         0x80002BE4
    // 0x800A1FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_78;
    // 0x800A1FA4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_78:
    // 0x800A1FA8: jal         0x80002BE4
    // 0x800A1FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_79;
    // 0x800A1FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_79:
    // 0x800A1FB0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1FB4: jal         0x80002BE4
    // 0x800A1FB8: addiu       $a0, $a0, 0x3418
    ctx->r4 = ADD32(ctx->r4, 0X3418);
    syDmaLoadOverlay(rdram, ctx);
        goto after_80;
    // 0x800A1FB8: addiu       $a0, $a0, 0x3418
    ctx->r4 = ADD32(ctx->r4, 0X3418);
    after_80:
    // 0x800A1FBC: jal         0x8013B33C
    // 0x800A1FC0: nop

    mnPlayersVSStartScene(rdram, ctx);
        goto after_81;
    // 0x800A1FC0: nop

    after_81:
    // 0x800A1FC4: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1FC8: b           L_800A1C44
    // 0x800A1FCC: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1FCC: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1FD0:
    // 0x800A1FD0: jal         0x80002BE4
    // 0x800A1FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_82;
    // 0x800A1FD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_82:
    // 0x800A1FD8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A1FDC: jal         0x80002BE4
    // 0x800A1FE0: addiu       $a0, $a0, 0x34A8
    ctx->r4 = ADD32(ctx->r4, 0X34A8);
    syDmaLoadOverlay(rdram, ctx);
        goto after_83;
    // 0x800A1FE0: addiu       $a0, $a0, 0x34A8
    ctx->r4 = ADD32(ctx->r4, 0X34A8);
    after_83:
    // 0x800A1FE4: jal         0x8013446C
    // 0x800A1FE8: nop

    mnMapsStartScene(rdram, ctx);
        goto after_84;
    // 0x800A1FE8: nop

    after_84:
    // 0x800A1FEC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A1FF0: b           L_800A1C44
    // 0x800A1FF4: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A1FF4: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A1FF8:
    // 0x800A1FF8: jal         0x80002BE4
    // 0x800A1FFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_85;
    // 0x800A1FFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_85:
    // 0x800A2000: jal         0x80002BE4
    // 0x800A2004: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_86;
    // 0x800A2004: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_86:
    // 0x800A2008: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A200C: jal         0x80002BE4
    // 0x800A2010: addiu       $a0, $a0, 0x3100
    ctx->r4 = ADD32(ctx->r4, 0X3100);
    syDmaLoadOverlay(rdram, ctx);
        goto after_87;
    // 0x800A2010: addiu       $a0, $a0, 0x3100
    ctx->r4 = ADD32(ctx->r4, 0X3100);
    after_87:
    // 0x800A2014: jal         0x8018E190
    // 0x800A2018: nop

    scVSBattleStartScene(rdram, ctx);
        goto after_88;
    // 0x800A2018: nop

    after_88:
    // 0x800A201C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A2020: b           L_800A1C44
    // 0x800A2024: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2024: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2028:
    // 0x800A2028: jal         0x80002BE4
    // 0x800A202C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_89;
    // 0x800A202C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_89:
    // 0x800A2030: jal         0x80002BE4
    // 0x800A2034: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_90;
    // 0x800A2034: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_90:
    // 0x800A2038: jal         0x80002BE4
    // 0x800A203C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_91;
    // 0x800A203C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_91:
    // 0x800A2040: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2044: jal         0x80002BE4
    // 0x800A2048: addiu       $a0, $a0, 0x3124
    ctx->r4 = ADD32(ctx->r4, 0X3124);
    syDmaLoadOverlay(rdram, ctx);
        goto after_92;
    // 0x800A2048: addiu       $a0, $a0, 0x3124
    ctx->r4 = ADD32(ctx->r4, 0X3124);
    after_92:
    // 0x800A204C: jal         0x8018D508
    // 0x800A2050: nop

    mvUnknownMarioStartScene(rdram, ctx);
        goto after_93;
    // 0x800A2050: nop

    after_93:
    // 0x800A2054: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A2058: b           L_800A1C44
    // 0x800A205C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A205C: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2060:
    // 0x800A2060: jal         0x800D67DC
    // 0x800A2064: nop

    sc1PManagerUpdateScene(rdram, ctx);
        goto after_94;
    // 0x800A2064: nop

    after_94:
    // 0x800A2068: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A206C: b           L_800A1C44
    // 0x800A2070: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2070: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2074:
    // 0x800A2074: jal         0x80002BE4
    // 0x800A2078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_95;
    // 0x800A2078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_95:
    // 0x800A207C: jal         0x80002BE4
    // 0x800A2080: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_96;
    // 0x800A2080: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_96:
    // 0x800A2084: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2088: jal         0x80002BE4
    // 0x800A208C: addiu       $a0, $a0, 0x3148
    ctx->r4 = ADD32(ctx->r4, 0X3148);
    syDmaLoadOverlay(rdram, ctx);
        goto after_97;
    // 0x800A208C: addiu       $a0, $a0, 0x3148
    ctx->r4 = ADD32(ctx->r4, 0X3148);
    after_97:
    // 0x800A2090: jal         0x8018EACC
    // 0x800A2094: nop

    sc1PBonusStageStartScene(rdram, ctx);
        goto after_98;
    // 0x800A2094: nop

    after_98:
    // 0x800A2098: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A209C: b           L_800A1C44
    // 0x800A20A0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A20A0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A20A4:
    // 0x800A20A4: jal         0x80002BE4
    // 0x800A20A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_99;
    // 0x800A20A8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_99:
    // 0x800A20AC: jal         0x80002BE4
    // 0x800A20B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_100;
    // 0x800A20B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_100:
    // 0x800A20B4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A20B8: jal         0x80002BE4
    // 0x800A20BC: addiu       $a0, $a0, 0x316C
    ctx->r4 = ADD32(ctx->r4, 0X316C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_101;
    // 0x800A20BC: addiu       $a0, $a0, 0x316C
    ctx->r4 = ADD32(ctx->r4, 0X316C);
    after_101:
    // 0x800A20C0: jal         0x801905F4
    // 0x800A20C4: nop

    sc1PTrainingModeStartScene(rdram, ctx);
        goto after_102;
    // 0x800A20C4: nop

    after_102:
    // 0x800A20C8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A20CC: b           L_800A1C44
    // 0x800A20D0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A20D0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A20D4:
    // 0x800A20D4: jal         0x80002BE4
    // 0x800A20D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_103;
    // 0x800A20D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_103:
    // 0x800A20DC: jal         0x80002BE4
    // 0x800A20E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_104;
    // 0x800A20E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_104:
    // 0x800A20E4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A20E8: jal         0x80002BE4
    // 0x800A20EC: addiu       $a0, $a0, 0x34CC
    ctx->r4 = ADD32(ctx->r4, 0X34CC);
    syDmaLoadOverlay(rdram, ctx);
        goto after_105;
    // 0x800A20EC: addiu       $a0, $a0, 0x34CC
    ctx->r4 = ADD32(ctx->r4, 0X34CC);
    after_105:
    // 0x800A20F0: jal         0x80138E64
    // 0x800A20F4: nop

    mnVSResultsStartScene(rdram, ctx);
        goto after_106;
    // 0x800A20F4: nop

    after_106:
    // 0x800A20F8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A20FC: b           L_800A1C44
    // 0x800A2100: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2100: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2104:
    // 0x800A2104: jal         0x80002BE4
    // 0x800A2108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_107;
    // 0x800A2108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_107:
    // 0x800A210C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2110: jal         0x80002BE4
    // 0x800A2114: addiu       $a0, $a0, 0x34F0
    ctx->r4 = ADD32(ctx->r4, 0X34F0);
    syDmaLoadOverlay(rdram, ctx);
        goto after_108;
    // 0x800A2114: addiu       $a0, $a0, 0x34F0
    ctx->r4 = ADD32(ctx->r4, 0X34F0);
    after_108:
    // 0x800A2118: jal         0x801365D0
    // 0x800A211C: nop

    LOOKUP_FUNC(0x801365D0)(rdram, ctx);
        goto after_109;
    // 0x800A211C: nop

    after_109:
    // 0x800A2120: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A2124: b           L_800A1C44
    // 0x800A2128: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2128: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A212C:
    // 0x800A212C: jal         0x80002BE4
    // 0x800A2130: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_110;
    // 0x800A2130: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_110:
    // 0x800A2134: jal         0x80002BE4
    // 0x800A2138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_111;
    // 0x800A2138: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_111:
    // 0x800A213C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2140: jal         0x80002BE4
    // 0x800A2144: addiu       $a0, $a0, 0x3514
    ctx->r4 = ADD32(ctx->r4, 0X3514);
    syDmaLoadOverlay(rdram, ctx);
        goto after_112;
    // 0x800A2144: addiu       $a0, $a0, 0x3514
    ctx->r4 = ADD32(ctx->r4, 0X3514);
    after_112:
    // 0x800A2148: jal         0x80134050
    // 0x800A214C: nop

    mnCharactersStartScene(rdram, ctx);
        goto after_113;
    // 0x800A214C: nop

    after_113:
    // 0x800A2150: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A2154: b           L_800A1C44
    // 0x800A2158: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2158: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A215C:
    // 0x800A215C: jal         0x80002BE4
    // 0x800A2160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_114;
    // 0x800A2160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_114:
    // 0x800A2164: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2168: jal         0x80002BE4
    // 0x800A216C: addiu       $a0, $a0, 0x3898
    ctx->r4 = ADD32(ctx->r4, 0X3898);
    syDmaLoadOverlay(rdram, ctx);
        goto after_115;
    // 0x800A216C: addiu       $a0, $a0, 0x3898
    ctx->r4 = ADD32(ctx->r4, 0X3898);
    after_115:
    // 0x800A2170: jal         0x80131EF0
    // 0x800A2174: nop

    LOOKUP_FUNC(0x80131EF0)(rdram, ctx);
        goto after_116;
    // 0x800A2174: nop

    after_116:
    // 0x800A2178: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A217C: b           L_800A1C44
    // 0x800A2180: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2180: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2184:
    // 0x800A2184: jal         0x80002BE4
    // 0x800A2188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_117;
    // 0x800A2188: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_117:
    // 0x800A218C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2190: jal         0x80002BE4
    // 0x800A2194: addiu       $a0, $a0, 0x3538
    ctx->r4 = ADD32(ctx->r4, 0X3538);
    syDmaLoadOverlay(rdram, ctx);
        goto after_118;
    // 0x800A2194: addiu       $a0, $a0, 0x3538
    ctx->r4 = ADD32(ctx->r4, 0X3538);
    after_118:
    // 0x800A2198: jal         0x801349BC
    // 0x800A219C: nop

    mvOpeningRoomStartScene(rdram, ctx);
        goto after_119;
    // 0x800A219C: nop

    after_119:
    // 0x800A21A0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A21A4: b           L_800A1C44
    // 0x800A21A8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A21A8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A21AC:
    // 0x800A21AC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A21B0: jal         0x80002BE4
    // 0x800A21B4: addiu       $a0, $a0, 0x355C
    ctx->r4 = ADD32(ctx->r4, 0X355C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_120;
    // 0x800A21B4: addiu       $a0, $a0, 0x355C
    ctx->r4 = ADD32(ctx->r4, 0X355C);
    after_120:
    // 0x800A21B8: jal         0x8013283C
    // 0x800A21BC: nop

    LOOKUP_FUNC(0x8013283C)(rdram, ctx);
        goto after_121;
    // 0x800A21BC: nop

    after_121:
    // 0x800A21C0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A21C4: b           L_800A1C44
    // 0x800A21C8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A21C8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A21CC:
    // 0x800A21CC: jal         0x80002BE4
    // 0x800A21D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_122;
    // 0x800A21D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_122:
    // 0x800A21D4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A21D8: jal         0x80002BE4
    // 0x800A21DC: addiu       $a0, $a0, 0x3580
    ctx->r4 = ADD32(ctx->r4, 0X3580);
    syDmaLoadOverlay(rdram, ctx);
        goto after_123;
    // 0x800A21DC: addiu       $a0, $a0, 0x3580
    ctx->r4 = ADD32(ctx->r4, 0X3580);
    after_123:
    // 0x800A21E0: jal         0x8018E030
    // 0x800A21E4: nop

    mvOpeningMarioStartScene(rdram, ctx);
        goto after_124;
    // 0x800A21E4: nop

    after_124:
    // 0x800A21E8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A21EC: b           L_800A1C44
    // 0x800A21F0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A21F0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A21F4:
    // 0x800A21F4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A21F8: jal         0x80002BE4
    // 0x800A21FC: addiu       $a0, $a0, 0x35A4
    ctx->r4 = ADD32(ctx->r4, 0X35A4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_125;
    // 0x800A21FC: addiu       $a0, $a0, 0x35A4
    ctx->r4 = ADD32(ctx->r4, 0X35A4);
    after_125:
    // 0x800A2200: jal         0x8018E018
    // 0x800A2204: nop

    LOOKUP_FUNC(0x8018E018)(rdram, ctx);
        goto after_126;
    // 0x800A2204: nop

    after_126:
    // 0x800A2208: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A220C: b           L_800A1C44
    // 0x800A2210: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2210: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2214:
    // 0x800A2214: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2218: jal         0x80002BE4
    // 0x800A221C: addiu       $a0, $a0, 0x35C8
    ctx->r4 = ADD32(ctx->r4, 0X35C8);
    syDmaLoadOverlay(rdram, ctx);
        goto after_127;
    // 0x800A221C: addiu       $a0, $a0, 0x35C8
    ctx->r4 = ADD32(ctx->r4, 0X35C8);
    after_127:
    // 0x800A2220: jal         0x8018E0C8
    // 0x800A2224: nop

    mvOpeningSamusStartScene(rdram, ctx);
        goto after_128;
    // 0x800A2224: nop

    after_128:
    // 0x800A2228: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A222C: b           L_800A1C44
    // 0x800A2230: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2230: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2234:
    // 0x800A2234: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2238: jal         0x80002BE4
    // 0x800A223C: addiu       $a0, $a0, 0x35EC
    ctx->r4 = ADD32(ctx->r4, 0X35EC);
    syDmaLoadOverlay(rdram, ctx);
        goto after_129;
    // 0x800A223C: addiu       $a0, $a0, 0x35EC
    ctx->r4 = ADD32(ctx->r4, 0X35EC);
    after_129:
    // 0x800A2240: jal         0x8018E02C
    // 0x800A2244: nop

    mvOpeningFoxStartScene(rdram, ctx);
        goto after_130;
    // 0x800A2244: nop

    after_130:
    // 0x800A2248: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A224C: b           L_800A1C44
    // 0x800A2250: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2250: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2254:
    // 0x800A2254: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2258: jal         0x80002BE4
    // 0x800A225C: addiu       $a0, $a0, 0x3610
    ctx->r4 = ADD32(ctx->r4, 0X3610);
    syDmaLoadOverlay(rdram, ctx);
        goto after_131;
    // 0x800A225C: addiu       $a0, $a0, 0x3610
    ctx->r4 = ADD32(ctx->r4, 0X3610);
    after_131:
    // 0x800A2260: jal         0x8018E018
    // 0x800A2264: nop

    LOOKUP_FUNC(0x8018E018)(rdram, ctx);
        goto after_132;
    // 0x800A2264: nop

    after_132:
    // 0x800A2268: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A226C: b           L_800A1C44
    // 0x800A2270: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2270: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2274:
    // 0x800A2274: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2278: jal         0x80002BE4
    // 0x800A227C: addiu       $a0, $a0, 0x3634
    ctx->r4 = ADD32(ctx->r4, 0X3634);
    syDmaLoadOverlay(rdram, ctx);
        goto after_133;
    // 0x800A227C: addiu       $a0, $a0, 0x3634
    ctx->r4 = ADD32(ctx->r4, 0X3634);
    after_133:
    // 0x800A2280: jal         0x8018E05C
    // 0x800A2284: nop

    LOOKUP_FUNC(0x8018E05C)(rdram, ctx);
        goto after_134;
    // 0x800A2284: nop

    after_134:
    // 0x800A2288: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A228C: b           L_800A1C44
    // 0x800A2290: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2290: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2294:
    // 0x800A2294: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2298: jal         0x80002BE4
    // 0x800A229C: addiu       $a0, $a0, 0x3658
    ctx->r4 = ADD32(ctx->r4, 0X3658);
    syDmaLoadOverlay(rdram, ctx);
        goto after_135;
    // 0x800A229C: addiu       $a0, $a0, 0x3658
    ctx->r4 = ADD32(ctx->r4, 0X3658);
    after_135:
    // 0x800A22A0: jal         0x8018E05C
    // 0x800A22A4: nop

    LOOKUP_FUNC(0x8018E05C)(rdram, ctx);
        goto after_136;
    // 0x800A22A4: nop

    after_136:
    // 0x800A22A8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A22AC: b           L_800A1C44
    // 0x800A22B0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A22B0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A22B4:
    // 0x800A22B4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A22B8: jal         0x80002BE4
    // 0x800A22BC: addiu       $a0, $a0, 0x367C
    ctx->r4 = ADD32(ctx->r4, 0X367C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_137;
    // 0x800A22BC: addiu       $a0, $a0, 0x367C
    ctx->r4 = ADD32(ctx->r4, 0X367C);
    after_137:
    // 0x800A22C0: jal         0x8018E058
    // 0x800A22C4: nop

    mvOpeningKirbyStartScene(rdram, ctx);
        goto after_138;
    // 0x800A22C4: nop

    after_138:
    // 0x800A22C8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A22CC: b           L_800A1C44
    // 0x800A22D0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A22D0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A22D4:
    // 0x800A22D4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A22D8: jal         0x80002BE4
    // 0x800A22DC: addiu       $a0, $a0, 0x36A0
    ctx->r4 = ADD32(ctx->r4, 0X36A0);
    syDmaLoadOverlay(rdram, ctx);
        goto after_139;
    // 0x800A22DC: addiu       $a0, $a0, 0x36A0
    ctx->r4 = ADD32(ctx->r4, 0X36A0);
    after_139:
    // 0x800A22E0: jal         0x8013256C
    // 0x800A22E4: nop

    mvOpeningRunStartScene(rdram, ctx);
        goto after_140;
    // 0x800A22E4: nop

    after_140:
    // 0x800A22E8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A22EC: b           L_800A1C44
    // 0x800A22F0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A22F0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A22F4:
    // 0x800A22F4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A22F8: jal         0x80002BE4
    // 0x800A22FC: addiu       $a0, $a0, 0x36C4
    ctx->r4 = ADD32(ctx->r4, 0X36C4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_141;
    // 0x800A22FC: addiu       $a0, $a0, 0x36C4
    ctx->r4 = ADD32(ctx->r4, 0X36C4);
    after_141:
    // 0x800A2300: jal         0x801322CC
    // 0x800A2304: nop

    mvOpeningYosterStartScene(rdram, ctx);
        goto after_142;
    // 0x800A2304: nop

    after_142:
    // 0x800A2308: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A230C: b           L_800A1C44
    // 0x800A2310: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2310: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2314:
    // 0x800A2314: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2318: jal         0x80002BE4
    // 0x800A231C: addiu       $a0, $a0, 0x36E8
    ctx->r4 = ADD32(ctx->r4, 0X36E8);
    syDmaLoadOverlay(rdram, ctx);
        goto after_143;
    // 0x800A231C: addiu       $a0, $a0, 0x36E8
    ctx->r4 = ADD32(ctx->r4, 0X36E8);
    after_143:
    // 0x800A2320: jal         0x80132674
    // 0x800A2324: nop

    LOOKUP_FUNC(0x80132674)(rdram, ctx);
        goto after_144;
    // 0x800A2324: nop

    after_144:
    // 0x800A2328: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A232C: b           L_800A1C44
    // 0x800A2330: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2330: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2334:
    // 0x800A2334: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2338: jal         0x80002BE4
    // 0x800A233C: addiu       $a0, $a0, 0x370C
    ctx->r4 = ADD32(ctx->r4, 0X370C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_145;
    // 0x800A233C: addiu       $a0, $a0, 0x370C
    ctx->r4 = ADD32(ctx->r4, 0X370C);
    after_145:
    // 0x800A2340: jal         0x8013286C
    // 0x800A2344: nop

    LOOKUP_FUNC(0x8013286C)(rdram, ctx);
        goto after_146;
    // 0x800A2344: nop

    after_146:
    // 0x800A2348: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A234C: b           L_800A1C44
    // 0x800A2350: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2350: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2354:
    // 0x800A2354: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2358: jal         0x80002BE4
    // 0x800A235C: addiu       $a0, $a0, 0x3730
    ctx->r4 = ADD32(ctx->r4, 0X3730);
    syDmaLoadOverlay(rdram, ctx);
        goto after_147;
    // 0x800A235C: addiu       $a0, $a0, 0x3730
    ctx->r4 = ADD32(ctx->r4, 0X3730);
    after_147:
    // 0x800A2360: jal         0x80132344
    // 0x800A2364: nop

    mvOpeningYamabukiStartScene(rdram, ctx);
        goto after_148;
    // 0x800A2364: nop

    after_148:
    // 0x800A2368: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A236C: b           L_800A1C44
    // 0x800A2370: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2370: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2374:
    // 0x800A2374: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2378: jal         0x80002BE4
    // 0x800A237C: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    syDmaLoadOverlay(rdram, ctx);
        goto after_149;
    // 0x800A237C: addiu       $a0, $a0, 0x3754
    ctx->r4 = ADD32(ctx->r4, 0X3754);
    after_149:
    // 0x800A2380: jal         0x80132874
    // 0x800A2384: nop

    LOOKUP_FUNC(0x80132874)(rdram, ctx);
        goto after_150;
    // 0x800A2384: nop

    after_150:
    // 0x800A2388: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A238C: b           L_800A1C44
    // 0x800A2390: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2390: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2394:
    // 0x800A2394: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2398: jal         0x80002BE4
    // 0x800A239C: addiu       $a0, $a0, 0x3778
    ctx->r4 = ADD32(ctx->r4, 0X3778);
    syDmaLoadOverlay(rdram, ctx);
        goto after_151;
    // 0x800A239C: addiu       $a0, $a0, 0x3778
    ctx->r4 = ADD32(ctx->r4, 0X3778);
    after_151:
    // 0x800A23A0: jal         0x80132898
    // 0x800A23A4: nop

    mvOpeningSectorStartScene(rdram, ctx);
        goto after_152;
    // 0x800A23A4: nop

    after_152:
    // 0x800A23A8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A23AC: b           L_800A1C44
    // 0x800A23B0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A23B0: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A23B4:
    // 0x800A23B4: jal         0x80002BE4
    // 0x800A23B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_153;
    // 0x800A23B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_153:
    // 0x800A23BC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A23C0: jal         0x80002BE4
    // 0x800A23C4: addiu       $a0, $a0, 0x379C
    ctx->r4 = ADD32(ctx->r4, 0X379C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_154;
    // 0x800A23C4: addiu       $a0, $a0, 0x379C
    ctx->r4 = ADD32(ctx->r4, 0X379C);
    after_154:
    // 0x800A23C8: jal         0x8018D818
    // 0x800A23CC: nop

    mvOpeningJungleStartScene(rdram, ctx);
        goto after_155;
    // 0x800A23CC: nop

    after_155:
    // 0x800A23D0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A23D4: b           L_800A1C44
    // 0x800A23D8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A23D8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A23DC:
    // 0x800A23DC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A23E0: jal         0x80002BE4
    // 0x800A23E4: addiu       $a0, $a0, 0x37C0
    ctx->r4 = ADD32(ctx->r4, 0X37C0);
    syDmaLoadOverlay(rdram, ctx);
        goto after_156;
    // 0x800A23E4: addiu       $a0, $a0, 0x37C0
    ctx->r4 = ADD32(ctx->r4, 0X37C0);
    after_156:
    // 0x800A23E8: jal         0x801325E0
    // 0x800A23EC: nop

    mvOpeningNewcomersStartScene(rdram, ctx);
        goto after_157;
    // 0x800A23EC: nop

    after_157:
    // 0x800A23F0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A23F4: b           L_800A1C44
    // 0x800A23F8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A23F8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A23FC:
    // 0x800A23FC: jal         0x80002BE4
    // 0x800A2400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_158;
    // 0x800A2400: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_158:
    // 0x800A2404: jal         0x80002BE4
    // 0x800A2408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_159;
    // 0x800A2408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_159:
    // 0x800A240C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2410: jal         0x80002BE4
    // 0x800A2414: addiu       $a0, $a0, 0x343C
    ctx->r4 = ADD32(ctx->r4, 0X343C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_160;
    // 0x800A2414: addiu       $a0, $a0, 0x343C
    ctx->r4 = ADD32(ctx->r4, 0X343C);
    after_160:
    // 0x800A2418: jal         0x80138558
    // 0x800A241C: nop

    mnPlayers1PGameStartScene(rdram, ctx);
        goto after_161;
    // 0x800A241C: nop

    after_161:
    // 0x800A2420: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A2424: b           L_800A1C44
    // 0x800A2428: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2428: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A242C:
    // 0x800A242C: jal         0x80002BE4
    // 0x800A2430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_162;
    // 0x800A2430: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_162:
    // 0x800A2434: jal         0x80002BE4
    // 0x800A2438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_163;
    // 0x800A2438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_163:
    // 0x800A243C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2440: jal         0x80002BE4
    // 0x800A2444: addiu       $a0, $a0, 0x3460
    ctx->r4 = ADD32(ctx->r4, 0X3460);
    syDmaLoadOverlay(rdram, ctx);
        goto after_164;
    // 0x800A2444: addiu       $a0, $a0, 0x3460
    ctx->r4 = ADD32(ctx->r4, 0X3460);
    after_164:
    // 0x800A2448: jal         0x80137F00
    // 0x800A244C: nop

    mnPlayers1PTrainingStartScene(rdram, ctx);
        goto after_165;
    // 0x800A244C: nop

    after_165:
    // 0x800A2450: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A2454: b           L_800A1C44
    // 0x800A2458: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2458: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A245C:
    // 0x800A245C: jal         0x80002BE4
    // 0x800A2460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_166;
    // 0x800A2460: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_166:
    // 0x800A2464: jal         0x80002BE4
    // 0x800A2468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_167;
    // 0x800A2468: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_167:
    // 0x800A246C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2470: jal         0x80002BE4
    // 0x800A2474: addiu       $a0, $a0, 0x3484
    ctx->r4 = ADD32(ctx->r4, 0X3484);
    syDmaLoadOverlay(rdram, ctx);
        goto after_168;
    // 0x800A2474: addiu       $a0, $a0, 0x3484
    ctx->r4 = ADD32(ctx->r4, 0X3484);
    after_168:
    // 0x800A2478: jal         0x80136EF4
    // 0x800A247C: nop

    mnPlayers1PBonusStartScene(rdram, ctx);
        goto after_169;
    // 0x800A247C: nop

    after_169:
    // 0x800A2480: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A2484: b           L_800A1C44
    // 0x800A2488: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2488: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A248C:
    // 0x800A248C: jal         0x80002BE4
    // 0x800A2490: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_170;
    // 0x800A2490: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_170:
    // 0x800A2494: jal         0x80002BE4
    // 0x800A2498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_171;
    // 0x800A2498: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_171:
    // 0x800A249C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A24A0: jal         0x80002BE4
    // 0x800A24A4: addiu       $a0, $a0, 0x3484
    ctx->r4 = ADD32(ctx->r4, 0X3484);
    syDmaLoadOverlay(rdram, ctx);
        goto after_172;
    // 0x800A24A4: addiu       $a0, $a0, 0x3484
    ctx->r4 = ADD32(ctx->r4, 0X3484);
    after_172:
    // 0x800A24A8: jal         0x80136EF4
    // 0x800A24AC: nop

    mnPlayers1PBonusStartScene(rdram, ctx);
        goto after_173;
    // 0x800A24AC: nop

    after_173:
    // 0x800A24B0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A24B4: b           L_800A1C44
    // 0x800A24B8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A24B8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A24BC:
    // 0x800A24BC: jal         0x80002BE4
    // 0x800A24C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_174;
    // 0x800A24C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_174:
    // 0x800A24C4: jal         0x80002BE4
    // 0x800A24C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_175;
    // 0x800A24C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_175:
    // 0x800A24CC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A24D0: jal         0x80002BE4
    // 0x800A24D4: addiu       $a0, $a0, 0x37E4
    ctx->r4 = ADD32(ctx->r4, 0X37E4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_176;
    // 0x800A24D4: addiu       $a0, $a0, 0x37E4
    ctx->r4 = ADD32(ctx->r4, 0X37E4);
    after_176:
    // 0x800A24D8: jal         0x80132E28
    // 0x800A24DC: nop

    mnBackupClearStartScene(rdram, ctx);
        goto after_177;
    // 0x800A24DC: nop

    after_177:
    // 0x800A24E0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A24E4: b           L_800A1C44
    // 0x800A24E8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A24E8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A24EC:
    // 0x800A24EC: jal         0x80002BE4
    // 0x800A24F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_178;
    // 0x800A24F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_178:
    // 0x800A24F4: jal         0x80002BE4
    // 0x800A24F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_179;
    // 0x800A24F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_179:
    // 0x800A24FC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2500: jal         0x80002BE4
    // 0x800A2504: addiu       $a0, $a0, 0x3808
    ctx->r4 = ADD32(ctx->r4, 0X3808);
    syDmaLoadOverlay(rdram, ctx);
        goto after_180;
    // 0x800A2504: addiu       $a0, $a0, 0x3808
    ctx->r4 = ADD32(ctx->r4, 0X3808);
    after_180:
    // 0x800A2508: jal         0x80132A78
    // 0x800A250C: nop

    mvEndingStartScene(rdram, ctx);
        goto after_181;
    // 0x800A250C: nop

    after_181:
    // 0x800A2510: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A2514: b           L_800A1C44
    // 0x800A2518: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2518: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A251C:
    // 0x800A251C: jal         0x80002BE4
    // 0x800A2520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_182;
    // 0x800A2520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_182:
    // 0x800A2524: jal         0x80002BE4
    // 0x800A2528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_183;
    // 0x800A2528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_183:
    // 0x800A252C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2530: jal         0x80002BE4
    // 0x800A2534: addiu       $a0, $a0, 0x382C
    ctx->r4 = ADD32(ctx->r4, 0X382C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_184;
    // 0x800A2534: addiu       $a0, $a0, 0x382C
    ctx->r4 = ADD32(ctx->r4, 0X382C);
    after_184:
    // 0x800A2538: jal         0x801340FC
    // 0x800A253C: nop

    mnPlayers1PGameContinueStartScene(rdram, ctx);
        goto after_185;
    // 0x800A253C: nop

    after_185:
    // 0x800A2540: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A2544: b           L_800A1C44
    // 0x800A2548: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2548: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A254C:
    // 0x800A254C: jal         0x80002BE4
    // 0x800A2550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_186;
    // 0x800A2550: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_186:
    // 0x800A2554: jal         0x80002BE4
    // 0x800A2558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_187;
    // 0x800A2558: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_187:
    // 0x800A255C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2560: jal         0x80002BE4
    // 0x800A2564: addiu       $a0, $a0, 0x3850
    ctx->r4 = ADD32(ctx->r4, 0X3850);
    syDmaLoadOverlay(rdram, ctx);
        goto after_188;
    // 0x800A2564: addiu       $a0, $a0, 0x3850
    ctx->r4 = ADD32(ctx->r4, 0X3850);
    after_188:
    // 0x800A2568: jal         0x80134E84
    // 0x800A256C: nop

    sc1PStageClearStartScene(rdram, ctx);
        goto after_189;
    // 0x800A256C: nop

    after_189:
    // 0x800A2570: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A2574: b           L_800A1C44
    // 0x800A2578: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2578: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A257C:
    // 0x800A257C: jal         0x80002BE4
    // 0x800A2580: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_190;
    // 0x800A2580: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_190:
    // 0x800A2584: jal         0x80002BE4
    // 0x800A2588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_191;
    // 0x800A2588: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_191:
    // 0x800A258C: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2590: jal         0x80002BE4
    // 0x800A2594: addiu       $a0, $a0, 0x3850
    ctx->r4 = ADD32(ctx->r4, 0X3850);
    syDmaLoadOverlay(rdram, ctx);
        goto after_192;
    // 0x800A2594: addiu       $a0, $a0, 0x3850
    ctx->r4 = ADD32(ctx->r4, 0X3850);
    after_192:
    // 0x800A2598: jal         0x80134E84
    // 0x800A259C: nop

    sc1PStageClearStartScene(rdram, ctx);
        goto after_193;
    // 0x800A259C: nop

    after_193:
    // 0x800A25A0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A25A4: b           L_800A1C44
    // 0x800A25A8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A25A8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A25AC:
    // 0x800A25AC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A25B0: jal         0x80002BE4
    // 0x800A25B4: addiu       $a0, $a0, 0x38BC
    ctx->r4 = ADD32(ctx->r4, 0X38BC);
    syDmaLoadOverlay(rdram, ctx);
        goto after_194;
    // 0x800A25B4: addiu       $a0, $a0, 0x38BC
    ctx->r4 = ADD32(ctx->r4, 0X38BC);
    after_194:
    // 0x800A25B8: jal         0x801351B8
    // 0x800A25BC: nop

    scStaffrollStartScene(rdram, ctx);
        goto after_195;
    // 0x800A25BC: nop

    after_195:
    // 0x800A25C0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A25C4: b           L_800A1C44
    // 0x800A25C8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A25C8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A25CC:
    // 0x800A25CC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A25D0: jal         0x80002BE4
    // 0x800A25D4: addiu       $a0, $a0, 0x3874
    ctx->r4 = ADD32(ctx->r4, 0X3874);
    syDmaLoadOverlay(rdram, ctx);
        goto after_196;
    // 0x800A25D4: addiu       $a0, $a0, 0x3874
    ctx->r4 = ADD32(ctx->r4, 0X3874);
    after_196:
    // 0x800A25D8: jal         0x8013200C
    // 0x800A25DC: nop

    mnCongraStartScene(rdram, ctx);
        goto after_197;
    // 0x800A25DC: nop

    after_197:
    // 0x800A25E0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A25E4: b           L_800A1C44
    // 0x800A25E8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A25E8: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A25EC:
    // 0x800A25EC: jal         0x80002BE4
    // 0x800A25F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_198;
    // 0x800A25F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_198:
    // 0x800A25F4: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A25F8: jal         0x80002BE4
    // 0x800A25FC: addiu       $a0, $a0, 0x3928
    ctx->r4 = ADD32(ctx->r4, 0X3928);
    syDmaLoadOverlay(rdram, ctx);
        goto after_199;
    // 0x800A25FC: addiu       $a0, $a0, 0x3928
    ctx->r4 = ADD32(ctx->r4, 0X3928);
    after_199:
    // 0x800A2600: jal         0x80133988
    // 0x800A2604: nop

    mnSoundTestStartScene(rdram, ctx);
        goto after_200;
    // 0x800A2604: nop

    after_200:
    // 0x800A2608: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A260C: b           L_800A1C44
    // 0x800A2610: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2610: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2614:
    // 0x800A2614: jal         0x80002BE4
    // 0x800A2618: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_201;
    // 0x800A2618: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_201:
    // 0x800A261C: jal         0x80002BE4
    // 0x800A2620: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_202;
    // 0x800A2620: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_202:
    // 0x800A2624: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2628: jal         0x80002BE4
    // 0x800A262C: addiu       $a0, $a0, 0x394C
    ctx->r4 = ADD32(ctx->r4, 0X394C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_203;
    // 0x800A262C: addiu       $a0, $a0, 0x394C
    ctx->r4 = ADD32(ctx->r4, 0X394C);
    after_203:
    // 0x800A2630: jal         0x8018E5C0
    // 0x800A2634: nop

    scExplainStartScene(rdram, ctx);
        goto after_204;
    // 0x800A2634: nop

    after_204:
    // 0x800A2638: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A263C: b           L_800A1C44
    // 0x800A2640: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2640: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
L_800A2644:
    // 0x800A2644: jal         0x80002BE4
    // 0x800A2648: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_205;
    // 0x800A2648: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_205:
    // 0x800A264C: jal         0x80002BE4
    // 0x800A2650: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_206;
    // 0x800A2650: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_206:
    // 0x800A2654: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800A2658: jal         0x80002BE4
    // 0x800A265C: addiu       $a0, $a0, 0x3970
    ctx->r4 = ADD32(ctx->r4, 0X3970);
    syDmaLoadOverlay(rdram, ctx);
        goto after_207;
    // 0x800A265C: addiu       $a0, $a0, 0x3970
    ctx->r4 = ADD32(ctx->r4, 0X3970);
    after_207:
    // 0x800A2660: jal         0x8018E014
    // 0x800A2664: nop

    LOOKUP_FUNC(0x8018E014)(rdram, ctx);
        goto after_208;
    // 0x800A2664: nop

    after_208:
    // 0x800A2668: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800A266C: b           L_800A1C44
    // 0x800A2670: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
        goto L_800A1C44;
    // 0x800A2670: lbu         $v0, 0x4AD0($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD0);
    // 0x800A2674: nop

    // 0x800A2678: nop

    // 0x800A267C: nop

    // 0x800A2680: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A2684: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800A2688: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800A268C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800A2690: jr          $ra
    // 0x800A2694: addiu       $sp, $sp, 0x418
    ctx->r29 = ADD32(ctx->r29, 0X418);
    return;
    // 0x800A2694: addiu       $sp, $sp, 0x418
    ctx->r29 = ADD32(ctx->r29, 0X418);
;}
RECOMP_FUNC void mnPlayers1PTrainingMakePlayerKindCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132AE4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132AE8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132AEC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132AF0: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132AF4: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80132AF8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132AFC: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x80132B00: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132B04: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132B08: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132B0C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132B10: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132B14: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132B18: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132B1C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132B20: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132B24: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132B28: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132B2C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132B30: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132B34: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132B38: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132B3C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132B40: jal         0x8000B93C
    // 0x80132B44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132B44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132B48: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132B4C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132B50: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132B54: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132B58: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132B5C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132B60: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132B64: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132B68: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132B6C: jal         0x80007080
    // 0x80132B70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132B70: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132B74: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132B78: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132B7C: jr          $ra
    // 0x80132B80: nop

    return;
    // 0x80132B80: nop

;}
RECOMP_FUNC void efManagerCaptainEntryCarProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801034D0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801034D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801034D8: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x801034DC: lw          $a2, 0x10($t6)
    ctx->r6 = MEM_W(ctx->r14, 0X10);
    // 0x801034E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801034E4: jal         0x8000DF34
    // 0x801034E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    gcPlayAnimAll(rdram, ctx);
        goto after_0;
    // 0x801034E8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801034EC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801034F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801034F4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801034F8: lwc1        $f6, 0x7C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X7C);
    // 0x801034FC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80103500: nop

    // 0x80103504: bc1fl       L_8010352C
    if (!c1cs) {
        // 0x80103508: lw          $t7, 0x74($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X74);
            goto L_8010352C;
    }
    goto skip_0;
    // 0x80103508: lw          $t7, 0x74($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X74);
    skip_0:
    // 0x8010350C: lw          $a0, 0x84($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X84);
    // 0x80103510: jal         0x800FD4F8
    // 0x80103514: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x80103514: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_1:
    // 0x80103518: jal         0x80009A84
    // 0x8010351C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8010351C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80103520: b           L_80103560
    // 0x80103524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103560;
    // 0x80103524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103528: lw          $t7, 0x74($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X74);
L_8010352C:
    // 0x8010352C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80103530: lwc1        $f10, 0x34($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X34);
    // 0x80103534: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80103538: nop

    // 0x8010353C: bc1f        L_80103554
    if (!c1cs) {
        // 0x80103540: nop
    
            goto L_80103554;
    }
    // 0x80103540: nop

    // 0x80103544: jal         0x800FD60C
    // 0x80103548: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    efManagerSortZNeg(rdram, ctx);
        goto after_3;
    // 0x80103548: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x8010354C: b           L_80103560
    // 0x80103550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80103560;
    // 0x80103550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103554:
    // 0x80103554: jal         0x800FD68C
    // 0x80103558: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    efManagerSortZPos(rdram, ctx);
        goto after_4;
    // 0x80103558: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x8010355C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80103560:
    // 0x80103560: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80103564: jr          $ra
    // 0x80103568: nop

    return;
    // 0x80103568: nop

;}
RECOMP_FUNC void ftMainUpdateAttackStatWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2F04: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E2F08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800E2F0C: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800E2F10: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800E2F14: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800E2F18: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800E2F1C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800E2F20: jal         0x80168128
    // 0x800E2F24: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    wpMainGetStaledDamage(rdram, ctx);
        goto after_0;
    // 0x800E2F24: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E2F28: lw          $s0, 0x50($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X50);
    // 0x800E2F2C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800E2F30: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800E2F34: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800E2F38: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800E2F3C: jal         0x800F0C08
    // 0x800E2F40: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gmCollisionGetWeaponAttackFighterAttackPosition(rdram, ctx);
        goto after_1;
    // 0x800E2F40: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x800E2F44: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
    // 0x800E2F48: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800E2F4C: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800E2F50: addiu       $t6, $v1, -0xA
    ctx->r14 = ADD32(ctx->r3, -0XA);
    // 0x800E2F54: slt         $at, $t6, $s1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800E2F58: beq         $at, $zero, L_800E2F98
    if (ctx->r1 == 0) {
        // 0x800E2F5C: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800E2F98;
    }
    // 0x800E2F5C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800E2F60: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800E2F64: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800E2F68: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800E2F6C: jal         0x800E26BC
    // 0x800E2F70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetHitInteractStats(rdram, ctx);
        goto after_2;
    // 0x800E2F70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x800E2F74: lw          $a0, 0x58($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X58);
    // 0x800E2F78: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800E2F7C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800E2F80: jal         0x800E287C
    // 0x800E2F84: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    ftMainSetHitRebound(rdram, ctx);
        goto after_3;
    // 0x800E2F84: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x800E2F88: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800E2F8C: jal         0x80100BF0
    // 0x800E2F90: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_4;
    // 0x800E2F90: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    after_4:
    // 0x800E2F94: lw          $v1, 0xC($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XC);
L_800E2F98:
    // 0x800E2F98: addiu       $t0, $s1, -0xA
    ctx->r8 = ADD32(ctx->r17, -0XA);
    // 0x800E2F9C: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800E2FA0: beq         $at, $zero, L_800E3034
    if (ctx->r1 == 0) {
        // 0x800E2FA4: lw          $a0, 0x40($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X40);
            goto L_800E3034;
    }
    // 0x800E2FA4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800E2FA8: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800E2FAC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800E2FB0: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800E2FB4: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800E2FB8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800E2FBC: jal         0x8016679C
    // 0x800E2FC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    wpProcessUpdateHitInteractStats(rdram, ctx);
        goto after_5;
    // 0x800E2FC0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_5:
    // 0x800E2FC4: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800E2FC8: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800E2FCC: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x800E2FD0: lw          $t1, 0x23C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X23C);
    // 0x800E2FD4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800E2FD8: slt         $at, $t1, $s1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800E2FDC: beq         $at, $zero, L_800E2FE8
    if (ctx->r1 == 0) {
        // 0x800E2FE0: nop
    
            goto L_800E2FE8;
    }
    // 0x800E2FE0: nop

    // 0x800E2FE4: sw          $s1, 0x23C($t9)
    MEM_W(0X23C, ctx->r25) = ctx->r17;
L_800E2FE8:
    // 0x800E2FE8: jal         0x80100BF0
    // 0x800E2FEC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_6;
    // 0x800E2FEC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    after_6:
    // 0x800E2FF0: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x800E2FF4: lw          $t2, 0x50E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50E8);
    // 0x800E2FF8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E2FFC: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800E3000: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800E3004: bne         $t3, $at, L_800E3034
    if (ctx->r11 != ctx->r1) {
        // 0x800E3008: slti        $at, $t0, 0xA
        ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
            goto L_800E3034;
    }
    // 0x800E3008: slti        $at, $t0, 0xA
    ctx->r1 = SIGNED(ctx->r8) < 0XA ? 1 : 0;
    // 0x800E300C: bne         $at, $zero, L_800E3034
    if (ctx->r1 != 0) {
        // 0x800E3010: lw          $t5, 0x4C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X4C);
            goto L_800E3034;
    }
    // 0x800E3010: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3014: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x800E3018: lbu         $t4, 0x4AE3($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4AE3);
    // 0x800E301C: lbu         $t6, 0xD($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0XD);
    // 0x800E3020: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800E3024: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x800E3028: bnel        $t4, $t6, L_800E3038
    if (ctx->r12 != ctx->r14) {
        // 0x800E302C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800E3038;
    }
    goto skip_0;
    // 0x800E302C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800E3030: sb          $t7, 0x36AC($at)
    MEM_B(0X36AC, ctx->r1) = ctx->r15;
L_800E3034:
    // 0x800E3034: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800E3038:
    // 0x800E3038: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800E303C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800E3040: jr          $ra
    // 0x800E3044: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800E3044: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftPhysicsClampAirVelX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8E78: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D8E7C: lwc1        $f0, 0x48($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800D8E80: neg.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = -ctx->f12.fl;
    // 0x800D8E84: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800D8E88: nop

    // 0x800D8E8C: bc1fl       L_800D8EA0
    if (!c1cs) {
        // 0x800D8E90: c.lt.s      $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
            goto L_800D8EA0;
    }
    goto skip_0;
    // 0x800D8E90: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    skip_0:
    // 0x800D8E94: jr          $ra
    // 0x800D8E98: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x800D8E98: swc1        $f2, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f2.u32l;
    // 0x800D8E9C: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
L_800D8EA0:
    // 0x800D8EA0: nop

    // 0x800D8EA4: bc1f        L_800D8EB0
    if (!c1cs) {
        // 0x800D8EA8: nop
    
            goto L_800D8EB0;
    }
    // 0x800D8EA8: nop

    // 0x800D8EAC: swc1        $f12, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f12.u32l;
L_800D8EB0:
    // 0x800D8EB0: jr          $ra
    // 0x800D8EB4: nop

    return;
    // 0x800D8EB4: nop

;}
RECOMP_FUNC void wpFoxBlasterMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168A74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80168A78: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80168A7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168A80: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80168A84: addiu       $a1, $a1, -0x7130
    ctx->r5 = ADD32(ctx->r5, -0X7130);
    // 0x80168A88: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80168A8C: jal         0x801655C8
    // 0x80168A90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80168A90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80168A94: bne         $v0, $zero, L_80168AA4
    if (ctx->r2 != 0) {
        // 0x80168A98: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80168AA4;
    }
    // 0x80168A98: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80168A9C: b           L_80168AEC
    // 0x80168AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80168AEC;
    // 0x80168AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80168AA4:
    // 0x80168AA4: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x80168AA8: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80168AAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80168AB0: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80168AB4: lwc1        $f12, 0x24($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80168AB8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80168ABC: nop

    // 0x80168AC0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80168AC4: mul.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80168AC8: swc1        $f14, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f14.u32l;
    // 0x80168ACC: jal         0x8001863C
    // 0x80168AD0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x80168AD0: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_1:
    // 0x80168AD4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80168AD8: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x80168ADC: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x80168AE0: jal         0x80103320
    // 0x80168AE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    efManagerFoxBlasterGlowMakeEffect(rdram, ctx);
        goto after_2;
    // 0x80168AE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80168AE8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_80168AEC:
    // 0x80168AEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168AF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80168AF4: jr          $ra
    // 0x80168AF8: nop

    return;
    // 0x80168AF8: nop

;}
RECOMP_FUNC void func_ovl8_803798A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803798A0: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x803798A4: lw          $t6, 0xCC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XCC);
    // 0x803798A8: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803798AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x803798B0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x803798B4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x803798B8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x803798BC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x803798C0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x803798C4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x803798C8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x803798CC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x803798D0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803798D4: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x803798D8: sw          $t6, -0x60A0($at)
    MEM_W(-0X60A0, ctx->r1) = ctx->r14;
    // 0x803798DC: lbu         $v0, 0x31($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X31);
    // 0x803798E0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x803798E4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x803798E8: bne         $v0, $at, L_803798F8
    if (ctx->r2 != ctx->r1) {
        // 0x803798EC: or          $s2, $a1, $zero
        ctx->r18 = ctx->r5 | 0;
            goto L_803798F8;
    }
    // 0x803798EC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x803798F0: b           L_80379914
    // 0x803798F4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80379914;
    // 0x803798F4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_803798F8:
    // 0x803798F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x803798FC: bnel        $v0, $at, L_80379910
    if (ctx->r2 != ctx->r1) {
        // 0x80379900: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_80379910;
    }
    goto skip_0;
    // 0x80379900: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_0:
    // 0x80379904: b           L_80379910
    // 0x80379908: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80379910;
    // 0x80379908: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8037990C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80379910:
    // 0x80379910: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80379914:
    // 0x80379914: lw          $v0, 0xC8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC8);
    // 0x80379918: sw          $s0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r16;
    // 0x8037991C: lw          $t9, 0xC0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC0);
    // 0x80379920: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x80379924: addiu       $a0, $sp, 0xB0
    ctx->r4 = ADD32(ctx->r29, 0XB0);
    // 0x80379928: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x8037992C: sh          $t7, 0xB0($sp)
    MEM_H(0XB0, ctx->r29) = ctx->r15;
    // 0x80379930: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x80379934: sh          $a3, 0xB6($sp)
    MEM_H(0XB6, ctx->r29) = ctx->r7;
    // 0x80379938: sh          $zero, 0x98($sp)
    MEM_H(0X98, ctx->r29) = 0;
    // 0x8037993C: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x80379940: sh          $t9, 0xB4($sp)
    MEM_H(0XB4, ctx->r29) = ctx->r25;
    // 0x80379944: sh          $t8, 0xB2($sp)
    MEM_H(0XB2, ctx->r29) = ctx->r24;
    // 0x80379948: lh          $t0, 0x4($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X4);
    // 0x8037994C: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    // 0x80379950: sh          $t0, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r8;
    // 0x80379954: lh          $t1, 0x6($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X6);
    // 0x80379958: sw          $s1, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r17;
    // 0x8037995C: jal         0x8037A67C
    // 0x80379960: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    func_ovl8_8037A67C(rdram, ctx);
        goto after_0;
    // 0x80379960: sh          $t1, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r9;
    after_0:
    // 0x80379964: jal         0x8037AA5C
    // 0x80379968: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    func_ovl8_8037AA5C(rdram, ctx);
        goto after_1;
    // 0x80379968: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    after_1:
    // 0x8037996C: bne         $v0, $zero, L_80379D44
    if (ctx->r2 != 0) {
        // 0x80379970: addiu       $a0, $sp, 0xA8
        ctx->r4 = ADD32(ctx->r29, 0XA8);
            goto L_80379D44;
    }
    // 0x80379970: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    // 0x80379974: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80379978: addiu       $a1, $a1, -0x6098
    ctx->r5 = ADD32(ctx->r5, -0X6098);
    // 0x8037997C: jal         0x8037A67C
    // 0x80379980: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_ovl8_8037A67C(rdram, ctx);
        goto after_2;
    // 0x80379980: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_2:
    // 0x80379984: jal         0x8037AA5C
    // 0x80379988: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    func_ovl8_8037AA5C(rdram, ctx);
        goto after_3;
    // 0x80379988: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    after_3:
    // 0x8037998C: bne         $v0, $zero, L_80379D44
    if (ctx->r2 != 0) {
        // 0x80379990: lh          $t2, 0xAA($sp)
        ctx->r10 = MEM_H(ctx->r29, 0XAA);
            goto L_80379D44;
    }
    // 0x80379990: lh          $t2, 0xAA($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XAA);
    // 0x80379994: lh          $t3, 0xB2($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XB2);
    // 0x80379998: lw          $t5, 0xC0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XC0);
    // 0x8037999C: lh          $t7, 0xA8($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XA8);
    // 0x803799A0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x803799A4: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803799A8: lh          $t8, 0xB0($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XB0);
    // 0x803799AC: lw          $t3, 0xB8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB8);
    // 0x803799B0: addiu       $fp, $sp, 0xA0
    ctx->r30 = ADD32(ctx->r29, 0XA0);
    // 0x803799B4: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x803799B8: lw          $v0, 0x34($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X34);
    // 0x803799BC: lh          $s3, 0x0($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X0);
    // 0x803799C0: lh          $s6, 0xC($v0)
    ctx->r22 = MEM_H(ctx->r2, 0XC);
    // 0x803799C4: mflo        $t6
    ctx->r14 = lo;
    // 0x803799C8: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x803799CC: nop

    // 0x803799D0: multu       $t0, $s0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803799D4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x803799D8: mflo        $t1
    ctx->r9 = lo;
    // 0x803799DC: addu        $a3, $s2, $t1
    ctx->r7 = ADD32(ctx->r18, ctx->r9);
    // 0x803799E0: nop

    // 0x803799E4: div         $zero, $t7, $s3
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r19)));
    // 0x803799E8: mflo        $t4
    ctx->r12 = lo;
    // 0x803799EC: sw          $t4, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r12;
    // 0x803799F0: bne         $s3, $zero, L_803799FC
    if (ctx->r19 != 0) {
        // 0x803799F4: nop
    
            goto L_803799FC;
    }
    // 0x803799F4: nop

    // 0x803799F8: break       7
    do_break(2151127544);
L_803799FC:
    // 0x803799FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80379A00: bne         $s3, $at, L_80379A14
    if (ctx->r19 != ctx->r1) {
        // 0x80379A04: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80379A14;
    }
    // 0x80379A04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80379A08: bne         $t7, $at, L_80379A14
    if (ctx->r15 != ctx->r1) {
        // 0x80379A0C: nop
    
            goto L_80379A14;
    }
    // 0x80379A0C: nop

    // 0x80379A10: break       6
    do_break(2151127568);
L_80379A14:
    // 0x80379A14: div         $zero, $t2, $s6
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r22)));
    // 0x80379A18: mflo        $t5
    ctx->r13 = lo;
    // 0x80379A1C: sw          $t5, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r13;
    // 0x80379A20: lh          $v1, 0x4($t3)
    ctx->r3 = MEM_H(ctx->r11, 0X4);
    // 0x80379A24: bne         $s6, $zero, L_80379A30
    if (ctx->r22 != 0) {
        // 0x80379A28: nop
    
            goto L_80379A30;
    }
    // 0x80379A28: nop

    // 0x80379A2C: break       7
    do_break(2151127596);
L_80379A30:
    // 0x80379A30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80379A34: bne         $s6, $at, L_80379A48
    if (ctx->r22 != ctx->r1) {
        // 0x80379A38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80379A48;
    }
    // 0x80379A38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80379A3C: bne         $t2, $at, L_80379A48
    if (ctx->r10 != ctx->r1) {
        // 0x80379A40: nop
    
            goto L_80379A48;
    }
    // 0x80379A40: nop

    // 0x80379A44: break       6
    do_break(2151127620);
L_80379A48:
    // 0x80379A48: div         $zero, $v1, $s3
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r19)));
    // 0x80379A4C: mfhi        $t8
    ctx->r24 = hi;
    // 0x80379A50: bne         $s3, $zero, L_80379A5C
    if (ctx->r19 != 0) {
        // 0x80379A54: nop
    
            goto L_80379A5C;
    }
    // 0x80379A54: nop

    // 0x80379A58: break       7
    do_break(2151127640);
L_80379A5C:
    // 0x80379A5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80379A60: bne         $s3, $at, L_80379A74
    if (ctx->r19 != ctx->r1) {
        // 0x80379A64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80379A74;
    }
    // 0x80379A64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80379A68: bne         $v1, $at, L_80379A74
    if (ctx->r3 != ctx->r1) {
        // 0x80379A6C: nop
    
            goto L_80379A74;
    }
    // 0x80379A6C: nop

    // 0x80379A70: break       6
    do_break(2151127664);
L_80379A74:
    // 0x80379A74: beq         $t8, $zero, L_80379A84
    if (ctx->r24 == 0) {
        // 0x80379A78: nop
    
            goto L_80379A84;
    }
    // 0x80379A78: nop

    // 0x80379A7C: b           L_80379A84
    // 0x80379A80: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80379A84;
    // 0x80379A80: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80379A84:
    // 0x80379A84: div         $zero, $v1, $s3
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r19)));
    // 0x80379A88: lhu         $v0, 0xAC($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0XAC);
    // 0x80379A8C: mflo        $t6
    ctx->r14 = lo;
    // 0x80379A90: addu        $t9, $t6, $s0
    ctx->r25 = ADD32(ctx->r14, ctx->r16);
    // 0x80379A94: bne         $s3, $zero, L_80379AA0
    if (ctx->r19 != 0) {
        // 0x80379A98: nop
    
            goto L_80379AA0;
    }
    // 0x80379A98: nop

    // 0x80379A9C: break       7
    do_break(2151127708);
L_80379AA0:
    // 0x80379AA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80379AA4: bne         $s3, $at, L_80379AB8
    if (ctx->r19 != ctx->r1) {
        // 0x80379AA8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80379AB8;
    }
    // 0x80379AA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80379AAC: bne         $v1, $at, L_80379AB8
    if (ctx->r3 != ctx->r1) {
        // 0x80379AB0: nop
    
            goto L_80379AB8;
    }
    // 0x80379AB0: nop

    // 0x80379AB4: break       6
    do_break(2151127732);
L_80379AB8:
    // 0x80379AB8: div         $zero, $v0, $s3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19)));
    // 0x80379ABC: mfhi        $t0
    ctx->r8 = hi;
    // 0x80379AC0: sw          $t9, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r25;
    // 0x80379AC4: bne         $s3, $zero, L_80379AD0
    if (ctx->r19 != 0) {
        // 0x80379AC8: nop
    
            goto L_80379AD0;
    }
    // 0x80379AC8: nop

    // 0x80379ACC: break       7
    do_break(2151127756);
L_80379AD0:
    // 0x80379AD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80379AD4: bne         $s3, $at, L_80379AE8
    if (ctx->r19 != ctx->r1) {
        // 0x80379AD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80379AE8;
    }
    // 0x80379AD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80379ADC: bne         $v0, $at, L_80379AE8
    if (ctx->r2 != ctx->r1) {
        // 0x80379AE0: nop
    
            goto L_80379AE8;
    }
    // 0x80379AE0: nop

    // 0x80379AE4: break       6
    do_break(2151127780);
L_80379AE8:
    // 0x80379AE8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80379AEC: beq         $t0, $zero, L_80379AFC
    if (ctx->r8 == 0) {
        // 0x80379AF0: nop
    
            goto L_80379AFC;
    }
    // 0x80379AF0: nop

    // 0x80379AF4: b           L_80379AFC
    // 0x80379AF8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80379AFC;
    // 0x80379AF8: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80379AFC:
    // 0x80379AFC: div         $zero, $v0, $s3
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r19)));
    // 0x80379B00: lhu         $a0, 0xAE($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XAE);
    // 0x80379B04: mflo        $t1
    ctx->r9 = lo;
    // 0x80379B08: addu        $t7, $t1, $s0
    ctx->r15 = ADD32(ctx->r9, ctx->r16);
    // 0x80379B0C: bne         $s3, $zero, L_80379B18
    if (ctx->r19 != 0) {
        // 0x80379B10: nop
    
            goto L_80379B18;
    }
    // 0x80379B10: nop

    // 0x80379B14: break       7
    do_break(2151127828);
L_80379B18:
    // 0x80379B18: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80379B1C: bne         $s3, $at, L_80379B30
    if (ctx->r19 != ctx->r1) {
        // 0x80379B20: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80379B30;
    }
    // 0x80379B20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80379B24: bne         $v0, $at, L_80379B30
    if (ctx->r2 != ctx->r1) {
        // 0x80379B28: nop
    
            goto L_80379B30;
    }
    // 0x80379B28: nop

    // 0x80379B2C: break       6
    do_break(2151127852);
L_80379B30:
    // 0x80379B30: div         $zero, $a0, $s6
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r22)));
    // 0x80379B34: addiu       $t4, $t7, 0x1
    ctx->r12 = ADD32(ctx->r15, 0X1);
    // 0x80379B38: mfhi        $t2
    ctx->r10 = hi;
    // 0x80379B3C: sw          $t4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r12;
    // 0x80379B40: bne         $s6, $zero, L_80379B4C
    if (ctx->r22 != 0) {
        // 0x80379B44: nop
    
            goto L_80379B4C;
    }
    // 0x80379B44: nop

    // 0x80379B48: break       7
    do_break(2151127880);
L_80379B4C:
    // 0x80379B4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80379B50: bne         $s6, $at, L_80379B64
    if (ctx->r22 != ctx->r1) {
        // 0x80379B54: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80379B64;
    }
    // 0x80379B54: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80379B58: bne         $a0, $at, L_80379B64
    if (ctx->r4 != ctx->r1) {
        // 0x80379B5C: nop
    
            goto L_80379B64;
    }
    // 0x80379B5C: nop

    // 0x80379B60: break       6
    do_break(2151127904);
L_80379B64:
    // 0x80379B64: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80379B68: beq         $t2, $zero, L_80379B78
    if (ctx->r10 == 0) {
        // 0x80379B6C: nop
    
            goto L_80379B78;
    }
    // 0x80379B6C: nop

    // 0x80379B70: b           L_80379B78
    // 0x80379B74: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_80379B78;
    // 0x80379B74: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_80379B78:
    // 0x80379B78: div         $zero, $a0, $s6
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r22)));
    // 0x80379B7C: mflo        $t5
    ctx->r13 = lo;
    // 0x80379B80: addu        $v1, $t5, $s0
    ctx->r3 = ADD32(ctx->r13, ctx->r16);
    // 0x80379B84: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80379B88: bne         $s6, $zero, L_80379B94
    if (ctx->r22 != 0) {
        // 0x80379B8C: nop
    
            goto L_80379B94;
    }
    // 0x80379B8C: nop

    // 0x80379B90: break       7
    do_break(2151127952);
L_80379B94:
    // 0x80379B94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80379B98: bne         $s6, $at, L_80379BAC
    if (ctx->r22 != ctx->r1) {
        // 0x80379B9C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80379BAC;
    }
    // 0x80379B9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80379BA0: bne         $a0, $at, L_80379BAC
    if (ctx->r4 != ctx->r1) {
        // 0x80379BA4: nop
    
            goto L_80379BAC;
    }
    // 0x80379BA4: nop

    // 0x80379BA8: break       6
    do_break(2151127976);
L_80379BAC:
    // 0x80379BAC: sw          $v1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r3;
    // 0x80379BB0: blez        $v1, L_80379D44
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80379BB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80379D44;
    }
    // 0x80379BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80379BB8: lw          $s7, 0x70($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X70);
    // 0x80379BBC: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80379BC0: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
L_80379BC4:
    // 0x80379BC4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80379BC8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80379BCC: blez        $t3, L_80379D0C
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80379BD0: lw          $t8, 0x78($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X78);
            goto L_80379D0C;
    }
    // 0x80379BD0: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x80379BD4: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379BD8: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80379BDC: sw          $v0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r2;
    // 0x80379BE0: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80379BE4: addu        $s4, $t6, $v0
    ctx->r20 = ADD32(ctx->r14, ctx->r2);
    // 0x80379BE8: mflo        $s2
    ctx->r18 = lo;
    // 0x80379BEC: nop

    // 0x80379BF0: nop

    // 0x80379BF4: multu       $s4, $s6
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379BF8: mflo        $s5
    ctx->r21 = lo;
    // 0x80379BFC: nop

    // 0x80379C00: nop

    // 0x80379C04: sh          $s2, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r18;
L_80379C08:
    // 0x80379C08: sh          $s5, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r21;
    // 0x80379C0C: sh          $s3, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r19;
    // 0x80379C10: sh          $s6, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r22;
    // 0x80379C14: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80379C18: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x80379C1C: jal         0x8037A67C
    // 0x80379C20: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    func_ovl8_8037A67C(rdram, ctx);
        goto after_4;
    // 0x80379C20: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    after_4:
    // 0x80379C24: beq         $v0, $zero, L_80379CDC
    if (ctx->r2 == 0) {
        // 0x80379C28: lh          $t9, 0x98($sp)
        ctx->r25 = MEM_H(ctx->r29, 0X98);
            goto L_80379CDC;
    }
    // 0x80379C28: lh          $t9, 0x98($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X98);
    // 0x80379C2C: div         $zero, $t9, $s3
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r19)));
    // 0x80379C30: mfhi        $t0
    ctx->r8 = hi;
    // 0x80379C34: lh          $t1, 0x9A($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X9A);
    // 0x80379C38: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x80379C3C: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x80379C40: div         $zero, $t1, $s6
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r22)));
    // 0x80379C44: mfhi        $t7
    ctx->r15 = hi;
    // 0x80379C48: sh          $t0, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r8;
    // 0x80379C4C: bne         $s3, $zero, L_80379C58
    if (ctx->r19 != 0) {
        // 0x80379C50: nop
    
            goto L_80379C58;
    }
    // 0x80379C50: nop

    // 0x80379C54: break       7
    do_break(2151128148);
L_80379C58:
    // 0x80379C58: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80379C5C: bne         $s3, $at, L_80379C70
    if (ctx->r19 != ctx->r1) {
        // 0x80379C60: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80379C70;
    }
    // 0x80379C60: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80379C64: bne         $t9, $at, L_80379C70
    if (ctx->r25 != ctx->r1) {
        // 0x80379C68: nop
    
            goto L_80379C70;
    }
    // 0x80379C68: nop

    // 0x80379C6C: break       6
    do_break(2151128172);
L_80379C70:
    // 0x80379C70: multu       $s4, $t2
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379C74: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80379C78: lw          $t4, 0x34($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X34);
    // 0x80379C7C: lw          $t0, 0x78($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X78);
    // 0x80379C80: sll         $t6, $s0, 4
    ctx->r14 = S32(ctx->r16 << 4);
    // 0x80379C84: bne         $s6, $zero, L_80379C90
    if (ctx->r22 != 0) {
        // 0x80379C88: nop
    
            goto L_80379C90;
    }
    // 0x80379C88: nop

    // 0x80379C8C: break       7
    do_break(2151128204);
L_80379C90:
    // 0x80379C90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80379C94: bne         $s6, $at, L_80379CA8
    if (ctx->r22 != ctx->r1) {
        // 0x80379C98: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80379CA8;
    }
    // 0x80379C98: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80379C9C: bne         $t1, $at, L_80379CA8
    if (ctx->r9 != ctx->r1) {
        // 0x80379CA0: nop
    
            goto L_80379CA8;
    }
    // 0x80379CA0: nop

    // 0x80379CA4: break       6
    do_break(2151128228);
L_80379CA8:
    // 0x80379CA8: mflo        $t5
    ctx->r13 = lo;
    // 0x80379CAC: sll         $t3, $t5, 4
    ctx->r11 = S32(ctx->r13 << 4);
    // 0x80379CB0: addu        $t8, $t4, $t3
    ctx->r24 = ADD32(ctx->r12, ctx->r11);
    // 0x80379CB4: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80379CB8: addiu       $t7, $sp, 0x98
    ctx->r15 = ADD32(ctx->r29, 0X98);
    // 0x80379CBC: lbu         $a3, 0x31($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X31);
    // 0x80379CC0: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80379CC4: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    // 0x80379CC8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80379CCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80379CD0: jal         0x80379070
    // 0x80379CD4: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    func_ovl8_80379070(rdram, ctx);
        goto after_5;
    // 0x80379CD4: lw          $a1, 0xC0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XC0);
    after_5:
    // 0x80379CD8: lhu         $s7, 0x9E($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X9E);
L_80379CDC:
    // 0x80379CDC: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80379CE0: lhu         $t2, 0x9C($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X9C);
    // 0x80379CE4: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x80379CE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80379CEC: multu       $t2, $v1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379CF0: addu        $s2, $s2, $s3
    ctx->r18 = ADD32(ctx->r18, ctx->r19);
    // 0x80379CF4: mflo        $t5
    ctx->r13 = lo;
    // 0x80379CF8: addu        $s1, $s1, $t5
    ctx->r17 = ADD32(ctx->r17, ctx->r13);
    // 0x80379CFC: bnel        $s0, $t4, L_80379C08
    if (ctx->r16 != ctx->r12) {
        // 0x80379D00: sh          $s2, 0xA0($sp)
        MEM_H(0XA0, ctx->r29) = ctx->r18;
            goto L_80379C08;
    }
    goto skip_1;
    // 0x80379D00: sh          $s2, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r18;
    skip_1:
    // 0x80379D04: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80379D08: lw          $v0, 0x90($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X90);
L_80379D0C:
    // 0x80379D0C: lw          $t3, 0xC0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC0);
    // 0x80379D10: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x80379D14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80379D18: multu       $s7, $t3
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379D1C: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80379D20: mflo        $t8
    ctx->r24 = lo;
    // 0x80379D24: nop

    // 0x80379D28: nop

    // 0x80379D2C: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80379D30: mflo        $t6
    ctx->r14 = lo;
    // 0x80379D34: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x80379D38: bnel        $at, $zero, L_80379BC4
    if (ctx->r1 != 0) {
        // 0x80379D3C: lw          $t3, 0x8C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X8C);
            goto L_80379BC4;
    }
    goto skip_2;
    // 0x80379D3C: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    skip_2:
    // 0x80379D40: sw          $s7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r23;
L_80379D44:
    // 0x80379D44: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80379D48: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80379D4C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80379D50: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80379D54: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80379D58: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80379D5C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80379D60: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80379D64: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80379D68: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80379D6C: jr          $ra
    // 0x80379D70: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80379D70: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void ftCaptainSpecialLwAirSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160060: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80160064: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80160068: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8016006C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80160070: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80160074: lw          $t7, 0x8E8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8E8);
    // 0x80160078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016007C: lwc1        $f4, 0x38($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X38);
    // 0x80160080: jal         0x800DEEC8
    // 0x80160084: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80160084: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80160088: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8016008C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80160090: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80160094: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x80160098: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8016009C: jal         0x800E6F24
    // 0x801600A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801600A0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801600A4: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801600A8: lw          $t9, 0x8E8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8E8);
    // 0x801600AC: lui         $t2, 0x800F
    ctx->r10 = S32(0X800F << 16);
    // 0x801600B0: lui         $t3, 0x800F
    ctx->r11 = S32(0X800F << 16);
    // 0x801600B4: swc1        $f6, 0x38($t9)
    MEM_W(0X38, ctx->r25) = ctx->f6.u32l;
    // 0x801600B8: lw          $t0, 0x8E8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8E8);
    // 0x801600BC: lw          $t1, 0x8EC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8EC);
    // 0x801600C0: addiu       $t2, $t2, -0x6374
    ctx->r10 = ADD32(ctx->r10, -0X6374);
    // 0x801600C4: lwc1        $f8, 0x38($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X38);
    // 0x801600C8: addiu       $t3, $t3, -0x633C
    ctx->r11 = ADD32(ctx->r11, -0X633C);
    // 0x801600CC: swc1        $f8, 0x38($t1)
    MEM_W(0X38, ctx->r9) = ctx->f8.u32l;
    // 0x801600D0: sw          $t2, 0xA04($s0)
    MEM_W(0XA04, ctx->r16) = ctx->r10;
    // 0x801600D4: sw          $t3, 0xA08($s0)
    MEM_W(0XA08, ctx->r16) = ctx->r11;
    // 0x801600D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801600DC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801600E0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801600E4: jr          $ra
    // 0x801600E8: nop

    return;
    // 0x801600E8: nop

;}
RECOMP_FUNC void sc1PStageClearCheckHaveBonusStatID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133668: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013366C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133670: slti        $at, $a0, 0x60
    ctx->r1 = SIGNED(ctx->r4) < 0X60 ? 1 : 0;
    // 0x80133674: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80133678: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013367C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80133680: beq         $at, $zero, L_801336DC
    if (ctx->r1 == 0) {
        // 0x80133684: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_801336DC;
    }
    // 0x80133684: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80133688: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8013368C: addiu       $s2, $s2, 0x5320
    ctx->r18 = ADD32(ctx->r18, 0X5320);
    // 0x80133690: addiu       $s1, $sp, 0x28
    ctx->r17 = ADD32(ctx->r29, 0X28);
    // 0x80133694: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80133698:
    // 0x80133698: jal         0x80132FF8
    // 0x8013369C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    sc1PStageClearSetupBonusStats(rdram, ctx);
        goto after_0;
    // 0x8013369C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x801336A0: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x801336A4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801336A8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801336AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x801336B0: addu        $t8, $s2, $t7
    ctx->r24 = ADD32(ctx->r18, ctx->r15);
    // 0x801336B4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801336B8: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x801336BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x801336C0: and         $t3, $t9, $t2
    ctx->r11 = ctx->r25 & ctx->r10;
    // 0x801336C4: beq         $t3, $zero, L_801336D4
    if (ctx->r11 == 0) {
        // 0x801336C8: slti        $at, $s0, 0x60
        ctx->r1 = SIGNED(ctx->r16) < 0X60 ? 1 : 0;
            goto L_801336D4;
    }
    // 0x801336C8: slti        $at, $s0, 0x60
    ctx->r1 = SIGNED(ctx->r16) < 0X60 ? 1 : 0;
    // 0x801336CC: b           L_801336E0
    // 0x801336D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801336E0;
    // 0x801336D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801336D4:
    // 0x801336D4: bnel        $at, $zero, L_80133698
    if (ctx->r1 != 0) {
        // 0x801336D8: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80133698;
    }
    goto skip_0;
    // 0x801336D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_801336DC:
    // 0x801336DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801336E0:
    // 0x801336E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801336E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801336E8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801336EC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801336F0: jr          $ra
    // 0x801336F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801336F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftDonkeySpecialNLoopProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B188: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015B18C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B190: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015B194: lw          $t6, 0x14C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14C);
    // 0x8015B198: bnel        $t6, $zero, L_8015B1B4
    if (ctx->r14 != 0) {
        // 0x8015B19C: lhu         $t7, 0x1B6($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X1B6);
            goto L_8015B1B4;
    }
    goto skip_0;
    // 0x8015B19C: lhu         $t7, 0x1B6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1B6);
    skip_0:
    // 0x8015B1A0: jal         0x8014935C
    // 0x8015B1A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftCommonEscapeCheckInterruptSpecialNDonkey(rdram, ctx);
        goto after_0;
    // 0x8015B1A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015B1A8: bne         $v0, $zero, L_8015B1EC
    if (ctx->r2 != 0) {
        // 0x8015B1AC: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8015B1EC;
    }
    // 0x8015B1AC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B1B0: lhu         $t7, 0x1B6($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1B6);
L_8015B1B4:
    // 0x8015B1B4: lhu         $t8, 0x1B4($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X1B4);
    // 0x8015B1B8: lhu         $v0, 0x1BE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1BE);
    // 0x8015B1BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8015B1C0: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8015B1C4: and         $t0, $v0, $t9
    ctx->r8 = ctx->r2 & ctx->r25;
    // 0x8015B1C8: beq         $t0, $zero, L_8015B1D8
    if (ctx->r8 == 0) {
        // 0x8015B1CC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8015B1D8;
    }
    // 0x8015B1CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8015B1D0: sw          $t1, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r9;
    // 0x8015B1D4: lhu         $v0, 0x1BE($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X1BE);
L_8015B1D8:
    // 0x8015B1D8: lhu         $t2, 0x1B8($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X1B8);
    // 0x8015B1DC: and         $t3, $v0, $t2
    ctx->r11 = ctx->r2 & ctx->r10;
    // 0x8015B1E0: beql        $t3, $zero, L_8015B1F0
    if (ctx->r11 == 0) {
        // 0x8015B1E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015B1F0;
    }
    goto skip_1;
    // 0x8015B1E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8015B1E8: sw          $t4, 0xB24($v1)
    MEM_W(0XB24, ctx->r3) = ctx->r12;
L_8015B1EC:
    // 0x8015B1EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015B1F0:
    // 0x8015B1F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015B1F4: jr          $ra
    // 0x8015B1F8: nop

    return;
    // 0x8015B1F8: nop

;}
RECOMP_FUNC void sc1PManagerGetFighterKindsNum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6490: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D6494: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800D6498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D649C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D64A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_800D64A4:
    // 0x800D64A4: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800D64A8: beq         $t6, $zero, L_800D64B4
    if (ctx->r14 == 0) {
        // 0x800D64AC: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800D64B4;
    }
    // 0x800D64AC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D64B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D64B4:
    // 0x800D64B4: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800D64B8: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x800D64BC: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x800D64C0: beq         $t7, $zero, L_800D64CC
    if (ctx->r15 == 0) {
        // 0x800D64C4: sra         $a0, $a1, 1
        ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800D64CC;
    }
    // 0x800D64C4: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800D64C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D64CC:
    // 0x800D64CC: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x800D64D0: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x800D64D4: beq         $t8, $zero, L_800D64E0
    if (ctx->r24 == 0) {
        // 0x800D64D8: sra         $a0, $a1, 1
        ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
            goto L_800D64E0;
    }
    // 0x800D64D8: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800D64DC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D64E0:
    // 0x800D64E0: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x800D64E4: andi        $t9, $a1, 0x1
    ctx->r25 = ctx->r5 & 0X1;
    // 0x800D64E8: beq         $t9, $zero, L_800D64F4
    if (ctx->r25 == 0) {
        // 0x800D64EC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800D64F4;
    }
    // 0x800D64EC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D64F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D64F4:
    // 0x800D64F4: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800D64F8: bne         $v0, $a2, L_800D64A4
    if (ctx->r2 != ctx->r6) {
        // 0x800D64FC: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_800D64A4;
    }
    // 0x800D64FC: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800D6500: jr          $ra
    // 0x800D6504: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D6504: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void unref_80000478(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000478: jr          $ra
    // 0x8000047C: addiu       $v0, $zero, 0x3400
    ctx->r2 = ADD32(0, 0X3400);
    return;
    // 0x8000047C: addiu       $v0, $zero, 0x3400
    ctx->r2 = ADD32(0, 0X3400);
;}
RECOMP_FUNC void ifCommonPlayerTagMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111BE4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80111BE8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80111BEC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80111BF0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80111BF4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80111BF8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80111BFC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80111C00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80111C04: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x80111C08: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80111C0C: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x80111C10: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80111C14: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80111C18: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80111C1C: addiu       $fp, $fp, 0xD40
    ctx->r30 = ADD32(ctx->r30, 0XD40);
    // 0x80111C20: addiu       $s7, $s7, -0x1054
    ctx->r23 = ADD32(ctx->r23, -0X1054);
    // 0x80111C24: addiu       $s4, $s4, 0x50E8
    ctx->r20 = ADD32(ctx->r20, 0X50E8);
    // 0x80111C28: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80111C2C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80111C30: lui         $s5, 0x8000
    ctx->r21 = S32(0X8000 << 16);
    // 0x80111C34: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
L_80111C38:
    // 0x80111C38: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80111C3C: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80111C40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80111C44: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80111C48: lbu         $t8, 0x22($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X22);
    // 0x80111C4C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80111C50: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    // 0x80111C54: beq         $s6, $t8, L_80111D24
    if (ctx->r22 == ctx->r24) {
        // 0x80111C58: lui         $s3, 0x8011
        ctx->r19 = S32(0X8011 << 16);
            goto L_80111D24;
    }
    // 0x80111C58: lui         $s3, 0x8011
    ctx->r19 = S32(0X8011 << 16);
    // 0x80111C5C: jal         0x80009968
    // 0x80111C60: addiu       $s3, $s3, 0x1A3C
    ctx->r19 = ADD32(ctx->r19, 0X1A3C);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80111C60: addiu       $s3, $s3, 0x1A3C
    ctx->r19 = ADD32(ctx->r19, 0X1A3C);
    after_0:
    // 0x80111C64: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80111C68: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80111C6C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80111C70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80111C74: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80111C78: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80111C7C: jal         0x80009DF4
    // 0x80111C80: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80111C80: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_1:
    // 0x80111C84: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80111C88: lw          $t6, 0x18($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X18);
    // 0x80111C8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80111C90: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x80111C94: lbu         $t2, 0x2A($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X2A);
    // 0x80111C98: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80111C9C: addu        $t4, $s7, $t3
    ctx->r12 = ADD32(ctx->r23, ctx->r11);
    // 0x80111CA0: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80111CA4: jal         0x800CCFDC
    // 0x80111CA8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80111CA8: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x80111CAC: addiu       $t7, $zero, 0x201
    ctx->r15 = ADD32(0, 0X201);
    // 0x80111CB0: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80111CB4: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80111CB8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80111CBC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80111CC0: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80111CC4: lbu         $v1, 0x28($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X28);
    // 0x80111CC8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80111CCC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80111CD0: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x80111CD4: lbu         $t0, -0x1084($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1084);
    // 0x80111CD8: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x80111CDC: addu        $t2, $t2, $v1
    ctx->r10 = ADD32(ctx->r10, ctx->r3);
    // 0x80111CE0: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x80111CE4: lbu         $t1, -0x107C($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X107C);
    // 0x80111CE8: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x80111CEC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80111CF0: sb          $t1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r9;
    // 0x80111CF4: lbu         $t2, -0x1074($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X1074);
    // 0x80111CF8: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x80111CFC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80111D00: sb          $t2, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r10;
    // 0x80111D04: lbu         $t3, -0x106C($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X106C);
    // 0x80111D08: addu        $t5, $t5, $v1
    ctx->r13 = ADD32(ctx->r13, ctx->r3);
    // 0x80111D0C: sb          $t3, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r11;
    // 0x80111D10: lbu         $t4, -0x1064($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X1064);
    // 0x80111D14: sb          $t4, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r12;
    // 0x80111D18: lbu         $t5, -0x105C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X105C);
    // 0x80111D1C: sb          $t5, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r13;
    // 0x80111D20: sw          $s2, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->r18;
L_80111D24:
    // 0x80111D24: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80111D28: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80111D2C: bne         $s2, $at, L_80111C38
    if (ctx->r18 != ctx->r1) {
        // 0x80111D30: addiu       $s0, $s0, 0x74
        ctx->r16 = ADD32(ctx->r16, 0X74);
            goto L_80111C38;
    }
    // 0x80111D30: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    // 0x80111D34: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80111D38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80111D3C: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80111D40: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80111D44: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80111D48: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80111D4C: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80111D50: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80111D54: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80111D58: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80111D5C: jr          $ra
    // 0x80111D60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80111D60: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ftCommonFireFlowerShootUpdateAmmoStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801472D4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801472D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801472DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801472E0: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x801472E4: lw          $t6, 0x84C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84C);
    // 0x801472E8: addiu       $t7, $t7, -0x7988
    ctx->r15 = ADD32(ctx->r15, -0X7988);
    // 0x801472EC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801472F0: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x801472F4: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x801472F8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x801472FC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80147300: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80147304: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80147308: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8014730C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80147310: sw          $t9, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r25;
    // 0x80147314: lhu         $t0, 0x33E($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X33E);
    // 0x80147318: slt         $at, $t0, $a1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8014731C: bnel        $at, $zero, L_801473C4
    if (ctx->r1 != 0) {
        // 0x80147320: lw          $t7, 0xB24($s0)
        ctx->r15 = MEM_W(ctx->r16, 0XB24);
            goto L_801473C4;
    }
    goto skip_0;
    // 0x80147320: lw          $t7, 0xB24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB24);
    skip_0:
    // 0x80147324: lw          $t1, 0x9C8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X9C8);
    // 0x80147328: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014732C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80147330: lwc1        $f6, 0x0($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X0);
    // 0x80147334: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80147338: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8014733C: div.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80147340: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80147344: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80147348: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8014734C: nop

    // 0x80147350: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80147354: nop

    // 0x80147358: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8014735C: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x80147360: swc1        $f18, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f18.u32l;
    // 0x80147364: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x80147368: lw          $t2, 0x9C8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X9C8);
    // 0x8014736C: lw          $t3, 0x33C($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X33C);
    // 0x80147370: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80147374: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x80147378: lw          $a0, 0x8E8($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X8E8);
    // 0x8014737C: jal         0x800EDF24
    // 0x80147380: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80147380: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    after_0:
    // 0x80147384: lw          $v0, 0xB18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB18);
    // 0x80147388: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x8014738C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80147390: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80147394: bne         $at, $zero, L_801473A8
    if (ctx->r1 != 0) {
        // 0x80147398: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_801473A8;
    }
    // 0x80147398: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8014739C: addiu       $t6, $zero, 0x8
    ctx->r14 = ADD32(0, 0X8);
    // 0x801473A0: b           L_801473A8
    // 0x801473A4: subu        $a2, $t6, $v0
    ctx->r6 = SUB32(ctx->r14, ctx->r2);
        goto L_801473A8;
    // 0x801473A4: subu        $a2, $t6, $v0
    ctx->r6 = SUB32(ctx->r14, ctx->r2);
L_801473A8:
    // 0x801473A8: jal         0x8017604C
    // 0x801473AC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    itFFlowerShootFlame(rdram, ctx);
        goto after_1;
    // 0x801473AC: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    after_1:
    // 0x801473B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801473B4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801473B8: jal         0x800E806C
    // 0x801473BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_2;
    // 0x801473BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801473C0: lw          $t7, 0xB24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB24);
L_801473C4:
    // 0x801473C4: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x801473C8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x801473CC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801473D0: slt         $at, $t8, $at
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x801473D4: bne         $at, $zero, L_801473E4
    if (ctx->r1 != 0) {
        // 0x801473D8: sw          $t8, 0xB24($s0)
        MEM_W(0XB24, ctx->r16) = ctx->r24;
            goto L_801473E4;
    }
    // 0x801473D8: sw          $t8, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->r24;
    // 0x801473DC: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x801473E0: sw          $t0, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->r8;
L_801473E4:
    // 0x801473E4: lw          $t1, 0xB18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XB18);
    // 0x801473E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801473EC: addiu       $a1, $zero, 0x36
    ctx->r5 = ADD32(0, 0X36);
    // 0x801473F0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x801473F4: slti        $at, $t2, 0x8
    ctx->r1 = SIGNED(ctx->r10) < 0X8 ? 1 : 0;
    // 0x801473F8: bne         $at, $zero, L_80147420
    if (ctx->r1 != 0) {
        // 0x801473FC: sw          $t2, 0xB18($s0)
        MEM_W(0XB18, ctx->r16) = ctx->r10;
            goto L_80147420;
    }
    // 0x801473FC: sw          $t2, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r10;
    // 0x80147400: jal         0x800EA5E8
    // 0x80147404: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    ftParamSetMotionID(rdram, ctx);
        goto after_3;
    // 0x80147404: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    after_3:
    // 0x80147408: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014740C: jal         0x800EA778
    // 0x80147410: lhu         $a1, 0x28E($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X28E);
    ftParamSetStatUpdate(rdram, ctx);
        goto after_4;
    // 0x80147410: lhu         $a1, 0x28E($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X28E);
    after_4:
    // 0x80147414: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80147418: jal         0x800EA7B0
    // 0x8014741C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamUpdate1PGameAttackStats(rdram, ctx);
        goto after_5;
    // 0x8014741C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
L_80147420:
    // 0x80147420: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80147424: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80147428: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8014742C: jr          $ra
    // 0x80147430: nop

    return;
    // 0x80147430: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetForcePuckFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135F34: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135F38: lw          $t6, -0x7114($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7114);
    // 0x80135F3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135F40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135F44: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80135F48: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135F4C: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135F50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80135F54: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80135F58: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80135F5C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80135F60: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80135F64: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80135F68: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
    // 0x80135F6C: bne         $at, $zero, L_80135F88
    if (ctx->r1 != 0) {
        // 0x80135F70: addiu       $a1, $a1, 0xD
        ctx->r5 = ADD32(ctx->r5, 0XD);
            goto L_80135F88;
    }
    // 0x80135F70: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    // 0x80135F74: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80135F78: beq         $at, $zero, L_80135F88
    if (ctx->r1 == 0) {
        // 0x80135F7C: nop
    
            goto L_80135F88;
    }
    // 0x80135F7C: nop

    // 0x80135F80: b           L_80135F88
    // 0x80135F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80135F88;
    // 0x80135F84: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135F88:
    // 0x80135F88: beq         $v0, $zero, L_80135FD0
    if (ctx->r2 == 0) {
        // 0x80135F8C: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_80135FD0;
    }
    // 0x80135F8C: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x80135F90: bne         $at, $zero, L_80135FAC
    if (ctx->r1 != 0) {
        // 0x80135F94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80135FAC;
    }
    // 0x80135F94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80135F98: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x80135F9C: beq         $at, $zero, L_80135FAC
    if (ctx->r1 == 0) {
        // 0x80135FA0: nop
    
            goto L_80135FAC;
    }
    // 0x80135FA0: nop

    // 0x80135FA4: b           L_80135FAC
    // 0x80135FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80135FAC;
    // 0x80135FA8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135FAC:
    // 0x80135FAC: beq         $v0, $zero, L_80135FD0
    if (ctx->r2 == 0) {
        // 0x80135FB0: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_80135FD0;
    }
    // 0x80135FB0: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x80135FB4: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80135FB8: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80135FBC: mflo        $a0
    ctx->r4 = lo;
    // 0x80135FC0: jal         0x8013279C
    // 0x80135FC4: nop

    mnPlayers1PGameGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x80135FC4: nop

    after_0:
    // 0x80135FC8: b           L_80136044
    // 0x80135FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80136044;
    // 0x80135FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80135FD0:
    // 0x80135FD0: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80135FD4: bne         $at, $zero, L_80135FF0
    if (ctx->r1 != 0) {
        // 0x80135FD8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80135FF0;
    }
    // 0x80135FD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80135FDC: slti        $at, $v1, 0x7A
    ctx->r1 = SIGNED(ctx->r3) < 0X7A ? 1 : 0;
    // 0x80135FE0: beq         $at, $zero, L_80135FF0
    if (ctx->r1 == 0) {
        // 0x80135FE4: nop
    
            goto L_80135FF0;
    }
    // 0x80135FE4: nop

    // 0x80135FE8: b           L_80135FF0
    // 0x80135FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80135FF0;
    // 0x80135FEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80135FF0:
    // 0x80135FF0: beq         $v0, $zero, L_8013603C
    if (ctx->r2 == 0) {
        // 0x80135FF4: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_8013603C;
    }
    // 0x80135FF4: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x80135FF8: bne         $at, $zero, L_80136014
    if (ctx->r1 != 0) {
        // 0x80135FFC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136014;
    }
    // 0x80135FFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80136000: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x80136004: beq         $at, $zero, L_80136014
    if (ctx->r1 == 0) {
        // 0x80136008: nop
    
            goto L_80136014;
    }
    // 0x80136008: nop

    // 0x8013600C: b           L_80136014
    // 0x80136010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136014;
    // 0x80136010: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136014:
    // 0x80136014: beq         $v0, $zero, L_8013603C
    if (ctx->r2 == 0) {
        // 0x80136018: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_8013603C;
    }
    // 0x80136018: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x8013601C: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80136020: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80136024: mflo        $a0
    ctx->r4 = lo;
    // 0x80136028: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x8013602C: jal         0x8013279C
    // 0x80136030: nop

    mnPlayers1PGameGetFighterKind(rdram, ctx);
        goto after_1;
    // 0x80136030: nop

    after_1:
    // 0x80136034: b           L_80136044
    // 0x80136038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80136044;
    // 0x80136038: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013603C:
    // 0x8013603C: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // 0x80136040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136044:
    // 0x80136044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136048: jr          $ra
    // 0x8013604C: nop

    return;
    // 0x8013604C: nop

;}
RECOMP_FUNC void mnUnusedFightersTimeProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D64C4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800D64C8: lhu         $v0, 0x5470($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X5470);
    // 0x800D64CC: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800D64D0: addiu       $v1, $v1, 0x716C
    ctx->r3 = ADD32(ctx->r3, 0X716C);
    // 0x800D64D4: andi        $t6, $v0, 0x200
    ctx->r14 = ctx->r2 & 0X200;
    // 0x800D64D8: beq         $t6, $zero, L_800D64F4
    if (ctx->r14 == 0) {
        // 0x800D64DC: andi        $t7, $v0, 0x100
        ctx->r15 = ctx->r2 & 0X100;
            goto L_800D64F4;
    }
    // 0x800D64DC: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x800D64E0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D64E4: lwc1        $f6, 0x7100($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7100);
    // 0x800D64E8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800D64EC: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D64F0: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
L_800D64F4:
    // 0x800D64F4: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800D64F8: beq         $t7, $zero, L_800D6514
    if (ctx->r15 == 0) {
        // 0x800D64FC: addiu       $v1, $v1, 0x716C
        ctx->r3 = ADD32(ctx->r3, 0X716C);
            goto L_800D6514;
    }
    // 0x800D64FC: addiu       $v1, $v1, 0x716C
    ctx->r3 = ADD32(ctx->r3, 0X716C);
    // 0x800D6500: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D6504: lwc1        $f16, 0x7104($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X7104);
    // 0x800D6508: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800D650C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800D6510: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
L_800D6514:
    // 0x800D6514: andi        $t8, $v0, 0x8000
    ctx->r24 = ctx->r2 & 0X8000;
    // 0x800D6518: beql        $t8, $zero, L_800D654C
    if (ctx->r24 == 0) {
        // 0x800D651C: lwc1        $f16, 0x0($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
            goto L_800D654C;
    }
    goto skip_0;
    // 0x800D651C: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x800D6520: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800D6524: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x800D6528: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800D652C: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800D6530: nop

    // 0x800D6534: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800D6538: nop

    // 0x800D653C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D6540: jr          $ra
    // 0x800D6544: swc1        $f10, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f10.u32l;
    return;
    // 0x800D6544: swc1        $f10, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f10.u32l;
    // 0x800D6548: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
L_800D654C:
    // 0x800D654C: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x800D6550: swc1        $f16, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f16.u32l;
    // 0x800D6554: jr          $ra
    // 0x800D6558: nop

    return;
    // 0x800D6558: nop

;}
RECOMP_FUNC void func_80005D10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005D10: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80005D14: addiu       $v0, $v0, 0x54BC
    ctx->r2 = ADD32(ctx->r2, 0X54BC);
    // 0x80005D18: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80005D1C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80005D20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005D24: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005D28: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80005D2C: bne         $t6, $at, L_80005D8C
    if (ctx->r14 != ctx->r1) {
        // 0x80005D30: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_80005D8C;
    }
    // 0x80005D30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80005D34: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80005D38: addiu       $s1, $s1, 0x54C8
    ctx->r17 = ADD32(ctx->r17, 0X54C8);
    // 0x80005D3C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80005D40: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80005D44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80005D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005D4C: jal         0x80030210
    // 0x80005D50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x80005D50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80005D54: addiu       $s0, $zero, -0x1
    ctx->r16 = ADD32(0, -0X1);
    // 0x80005D58: beq         $v0, $s0, L_80005D74
    if (ctx->r2 == ctx->r16) {
        // 0x80005D5C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80005D74;
    }
    // 0x80005D5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80005D60:
    // 0x80005D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005D64: jal         0x80030210
    // 0x80005D68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80005D68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80005D6C: bnel        $v0, $s0, L_80005D60
    if (ctx->r2 != ctx->r16) {
        // 0x80005D70: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80005D60;
    }
    goto skip_0;
    // 0x80005D70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_80005D74:
    // 0x80005D74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80005D78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005D7C: jal         0x80030210
    // 0x80005D80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80005D80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x80005D84: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005D88: sw          $zero, 0x54BC($at)
    MEM_W(0X54BC, ctx->r1) = 0;
L_80005D8C:
    // 0x80005D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80005D90: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80005D94: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80005D98: jr          $ra
    // 0x80005D9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80005D9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_80374548(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374548: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037454C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80374550: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80374554: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80374558: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8037455C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80374560: jal         0x803717A0
    // 0x80374564: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80374564: addiu       $a0, $zero, 0x120
    ctx->r4 = ADD32(0, 0X120);
    after_0:
    // 0x80374568: beq         $v0, $zero, L_803745A4
    if (ctx->r2 == 0) {
        // 0x8037456C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803745A4;
    }
    // 0x8037456C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80374570: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x80374574: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80374578: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8037457C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80374580: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80374584: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80374588: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8037458C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80374590: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80374594: jal         0x8037E97C
    // 0x80374598: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_ovl8_8037E97C(rdram, ctx);
        goto after_1;
    // 0x80374598: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_1:
    // 0x8037459C: b           L_803745A8
    // 0x803745A0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
        goto L_803745A8;
    // 0x803745A0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_803745A4:
    // 0x803745A4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803745A8:
    // 0x803745A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x803745AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x803745B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803745B4: jr          $ra
    // 0x803745B8: nop

    return;
    // 0x803745B8: nop

;}
RECOMP_FUNC void unref_8000641C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000641C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80006420: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80006424: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80006428: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000642C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80006430: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80006434: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80006438: jal         0x80005AE4
    // 0x8000643C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syTaskmanSwitchContext(rdram, ctx);
        goto after_0;
    // 0x8000643C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80006440: jal         0x800049B0
    // 0x80006444: nop

    syTaskmanResetGraphicsHeap(rdram, ctx);
        goto after_1;
    // 0x80006444: nop

    after_1:
    // 0x80006448: jal         0x80004AB0
    // 0x8000644C: nop

    func_80004AB0(rdram, ctx);
        goto after_2;
    // 0x8000644C: nop

    after_2:
    // 0x80006450: lw          $t9, 0x2C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X2C);
    // 0x80006454: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006458: jalr        $t9
    // 0x8000645C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8000645C: nop

    after_3:
    // 0x80006460: jal         0x800053CC
    // 0x80006464: nop

    func_800053CC(rdram, ctx);
        goto after_4;
    // 0x80006464: nop

    after_4:
    // 0x80006468: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8000646C: addiu       $s1, $s1, 0x6630
    ctx->r17 = ADD32(ctx->r17, 0X6630);
    // 0x80006470: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80006474: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80006478: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x8000647C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80006480: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80006484: lw          $a0, 0x6560($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6560);
    // 0x80006488: addiu       $s2, $s2, 0x5500
    ctx->r18 = ADD32(ctx->r18, 0X5500);
    // 0x8000648C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80006490: bne         $a0, $zero, L_800064AC
    if (ctx->r4 != 0) {
        // 0x80006494: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800064AC;
    }
    // 0x80006494: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80006498: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000649C: jal         0x80023624
    // 0x800064A0: addiu       $a0, $a0, -0x27B8
    ctx->r4 = ADD32(ctx->r4, -0X27B8);
    syDebugPrintf(rdram, ctx);
        goto after_5;
    // 0x800064A0: addiu       $a0, $a0, -0x27B8
    ctx->r4 = ADD32(ctx->r4, -0X27B8);
    after_5:
L_800064A4:
    // 0x800064A4: b           L_800064A4
    pause_self(rdram);
    // 0x800064A8: nop

L_800064AC:
    // 0x800064AC: jal         0x80004E90
    // 0x800064B0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    syTaskmanScheduleGfxEnd(rdram, ctx);
        goto after_6;
    // 0x800064B0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_6:
    // 0x800064B4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800064B8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800064BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800064C0: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800064C4: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x800064C8: lw          $t7, 0x6548($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6548);
    // 0x800064CC: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x800064D0: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800064D4: addiu       $s0, $s0, 0x6638
    ctx->r16 = ADD32(ctx->r16, 0X6638);
    // 0x800064D8: addiu       $s3, $sp, 0x34
    ctx->r19 = ADD32(ctx->r29, 0X34);
    // 0x800064DC: sw          $t7, 0x6550($at)
    MEM_W(0X6550, ctx->r1) = ctx->r15;
    // 0x800064E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800064E4:
    // 0x800064E4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800064E8: jal         0x80030210
    // 0x800064EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_7;
    // 0x800064EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_7:
    // 0x800064F0: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800064F4: sll         $t0, $t8, 2
    ctx->r8 = S32(ctx->r24 << 2);
    // 0x800064F8: addu        $t1, $s0, $t0
    ctx->r9 = ADD32(ctx->r16, ctx->r8);
    // 0x800064FC: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x80006500: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80006504: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80006508: addu        $t4, $s0, $t3
    ctx->r12 = ADD32(ctx->r16, ctx->r11);
    // 0x8000650C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80006510: bnel        $t5, $zero, L_800064E4
    if (ctx->r13 != 0) {
        // 0x80006514: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800064E4;
    }
    goto skip_0;
    // 0x80006514: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80006518: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000651C: addiu       $v0, $v0, -0x4918
    ctx->r2 = ADD32(ctx->r2, -0X4918);
    // 0x80006520: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80006524: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80006528: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000652C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80006530: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80006534: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80006538: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x8000653C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80006540: jr          $ra
    // 0x80006544: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80006544: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftYoshiSpecialAirNReleaseProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E558: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E55C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E560: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E564: jal         0x800DE6E4
    // 0x8015E568: addiu       $a1, $a1, -0x1940
    ctx->r5 = ADD32(ctx->r5, -0X1940);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015E568: addiu       $a1, $a1, -0x1940
    ctx->r5 = ADD32(ctx->r5, -0X1940);
    after_0:
    // 0x8015E56C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E574: jr          $ra
    // 0x8015E578: nop

    return;
    // 0x8015E578: nop

;}
RECOMP_FUNC void func_ovl8_80376164(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376164: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80376168: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037616C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80376170: lw          $v1, 0x14($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X14);
    // 0x80376174: lui         $at, 0x4646
    ctx->r1 = S32(0X4646 << 16);
    // 0x80376178: ori         $at, $at, 0x4857
    ctx->r1 = ctx->r1 | 0X4857;
    // 0x8037617C: beq         $v1, $at, L_8037619C
    if (ctx->r3 == ctx->r1) {
        // 0x80376180: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_8037619C;
    }
    // 0x80376180: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80376184: lui         $at, 0x4646
    ctx->r1 = S32(0X4646 << 16);
    // 0x80376188: ori         $at, $at, 0x574E
    ctx->r1 = ctx->r1 | 0X574E;
    // 0x8037618C: beql        $v1, $at, L_803761A0
    if (ctx->r3 == ctx->r1) {
        // 0x80376190: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_803761A0;
    }
    goto skip_0;
    // 0x80376190: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_0:
    // 0x80376194: b           L_803761A0
    // 0x80376198: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_803761A0;
    // 0x80376198: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037619C:
    // 0x8037619C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_803761A0:
    // 0x803761A0: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    // 0x803761A4: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x803761A8: jal         0x803717A0
    // 0x803761AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803761AC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x803761B0: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x803761B4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x803761B8: beq         $v0, $zero, L_803761DC
    if (ctx->r2 == 0) {
        // 0x803761BC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803761DC;
    }
    // 0x803761BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803761C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803761C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803761C8: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x803761CC: jal         0x80376010
    // 0x803761D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_ovl8_80376010(rdram, ctx);
        goto after_1;
    // 0x803761D0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x803761D4: b           L_803761E0
    // 0x803761D8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_803761E0;
    // 0x803761D8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_803761DC:
    // 0x803761DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803761E0:
    // 0x803761E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803761E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803761E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803761EC: jr          $ra
    // 0x803761F0: nop

    return;
    // 0x803761F0: nop

;}
RECOMP_FUNC void ftCommonAttack100LoopKirbyUpdateEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F1BC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014F1C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014F1C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014F1C8: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8014F1CC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8014F1D0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8014F1D4: bnel        $t6, $at, L_8014F298
    if (ctx->r14 != ctx->r1) {
        // 0x8014F1D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8014F298;
    }
    goto skip_0;
    // 0x8014F1D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8014F1DC: lw          $v0, 0x184($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X184);
    // 0x8014F1E0: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8014F1E4: addiu       $t8, $t8, 0x1220
    ctx->r24 = ADD32(ctx->r24, 0X1220);
    // 0x8014F1E8: beq         $v0, $zero, L_8014F294
    if (ctx->r2 == 0) {
        // 0x8014F1EC: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_8014F294;
    }
    // 0x8014F1EC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8014F1F0: lw          $t7, 0x1074($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1074);
    // 0x8014F1F4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8014F1F8: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x8014F1FC: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x8014F200: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x8014F204: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x8014F208: lwc1        $f4, -0x18($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, -0X18);
    // 0x8014F20C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x8014F210: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8014F214: lw          $t1, 0x184($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X184);
    // 0x8014F218: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8014F21C: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x8014F220: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8014F224: addu        $t3, $v1, $t2
    ctx->r11 = ADD32(ctx->r3, ctx->r10);
    // 0x8014F228: lwc1        $f6, -0x14($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, -0X14);
    // 0x8014F22C: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8014F230: lw          $t4, 0x184($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X184);
    // 0x8014F234: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8014F238: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8014F23C: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8014F240: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x8014F244: lwc1        $f8, -0x10($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, -0X10);
    // 0x8014F248: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x8014F24C: lw          $a0, 0x8E8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8E8);
    // 0x8014F250: jal         0x800EDF24
    // 0x8014F254: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8014F254: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014F258: lw          $t7, 0x184($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X184);
    // 0x8014F25C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8014F260: lw          $a1, 0x44($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X44);
    // 0x8014F264: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8014F268: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8014F26C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8014F270: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x8014F274: lwc1        $f10, -0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, -0X4);
    // 0x8014F278: lw          $a3, -0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, -0X8);
    // 0x8014F27C: lw          $a2, -0xC($v0)
    ctx->r6 = MEM_W(ctx->r2, -0XC);
    // 0x8014F280: addiu       $v0, $v0, -0x18
    ctx->r2 = ADD32(ctx->r2, -0X18);
    // 0x8014F284: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8014F288: jal         0x80101D34
    // 0x8014F28C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    efManagerKirbyVulcanJabMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8014F28C: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x8014F290: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
L_8014F294:
    // 0x8014F294: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8014F298:
    // 0x8014F298: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014F29C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8014F2A0: jr          $ra
    // 0x8014F2A4: nop

    return;
    // 0x8014F2A4: nop

;}
RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800368A4: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x800368A8: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x800368AC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800368B0: addiu       $a3, $a0, 0x4
    ctx->r7 = ADD32(ctx->r4, 0X4);
    // 0x800368B4: addiu       $t1, $a3, 0x2
    ctx->r9 = ADD32(ctx->r7, 0X2);
    // 0x800368B8: addu        $t8, $zero, $v0
    ctx->r24 = ADD32(0, ctx->r2);
    // 0x800368BC: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800368C0: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800368C4: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x800368C8: addiu       $t2, $a3, 0x4
    ctx->r10 = ADD32(ctx->r7, 0X4);
    // 0x800368CC: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800368D0: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x800368D4: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x800368D8: lhu         $v0, 0x2($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X2);
    // 0x800368DC: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    // 0x800368E0: addiu       $t3, $a3, 0x6
    ctx->r11 = ADD32(ctx->r7, 0X6);
    // 0x800368E4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800368E8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x800368EC: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x800368F0: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x800368F4: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x800368F8: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800368FC: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
L_80036900:
    // 0x80036900: lhu         $v0, 0x0($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X0);
    // 0x80036904: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80036908: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8003690C: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x80036910: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80036914: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80036918: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x8003691C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80036920: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80036924: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80036928: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x8003692C: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80036930: lhu         $v0, -0x8($t1)
    ctx->r2 = MEM_HU(ctx->r9, -0X8);
    // 0x80036934: addiu       $t2, $t2, 0x8
    ctx->r10 = ADD32(ctx->r10, 0X8);
    // 0x80036938: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x8003693C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80036940: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80036944: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x80036948: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x8003694C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80036950: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80036954: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80036958: lhu         $v0, -0x8($t2)
    ctx->r2 = MEM_HU(ctx->r10, -0X8);
    // 0x8003695C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80036960: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80036964: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x80036968: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x8003696C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80036970: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80036974: lhu         $t7, 0x0($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X0);
    // 0x80036978: lhu         $v0, -0x8($t3)
    ctx->r2 = MEM_HU(ctx->r11, -0X8);
    // 0x8003697C: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80036980: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80036984: lhu         $t9, 0x0($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X0);
    // 0x80036988: nor         $t5, $v0, $zero
    ctx->r13 = ~(ctx->r2 | 0);
    // 0x8003698C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x80036990: bne         $v1, $a0, L_80036900
    if (ctx->r3 != ctx->r4) {
        // 0x80036994: sh          $t6, 0x0($a2)
        MEM_H(0X0, ctx->r6) = ctx->r14;
            goto L_80036900;
    }
    // 0x80036994: sh          $t6, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r14;
    // 0x80036998: jr          $ra
    // 0x8003699C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8003699C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ftMarioSpecialLwProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156630: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80156634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156638: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015663C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80156640: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80156644: lui         $a1, 0x4188
    ctx->r5 = S32(0X4188 << 16);
    // 0x80156648: jal         0x801565E4
    // 0x8015664C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMarioSpecialLwUpdateFriction(rdram, ctx);
        goto after_0;
    // 0x8015664C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80156650: lui         $a2, 0x3CCC
    ctx->r6 = S32(0X3CCC << 16);
    // 0x80156654: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80156658: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8015665C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80156660: jal         0x800D89E0
    // 0x80156664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftPhysicsApplyClampGroundVelStickRange(rdram, ctx);
        goto after_1;
    // 0x80156664: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80156668: jal         0x800D87D0
    // 0x8015666C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_2;
    // 0x8015666C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80156670: lw          $t7, 0x188($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X188);
    // 0x80156674: beql        $t7, $zero, L_801566B4
    if (ctx->r15 == 0) {
        // 0x80156678: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801566B4;
    }
    goto skip_0;
    // 0x80156678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8015667C: lhu         $t8, 0x1BE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X1BE);
    // 0x80156680: lhu         $t9, 0x1B6($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X1B6);
    // 0x80156684: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80156688: and         $t0, $t8, $t9
    ctx->r8 = ctx->r24 & ctx->r25;
    // 0x8015668C: beql        $t0, $zero, L_801566B4
    if (ctx->r8 == 0) {
        // 0x80156690: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801566B4;
    }
    goto skip_1;
    // 0x80156690: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80156694: lwc1        $f4, 0x4C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80156698: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8015669C: nop

    // 0x801566A0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801566A4: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x801566A8: jal         0x80156808
    // 0x801566AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMarioSpecialLwSwitchStatusAir(rdram, ctx);
        goto after_3;
    // 0x801566AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x801566B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801566B4:
    // 0x801566B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801566B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801566BC: jr          $ra
    // 0x801566C0: nop

    return;
    // 0x801566C0: nop

;}
RECOMP_FUNC void grYosterUpdateCloudAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108890: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80108894: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80108898: addiu       $a1, $a1, 0x13F0
    ctx->r5 = ADD32(ctx->r5, 0X13F0);
    // 0x8010889C: sll         $t6, $a0, 5
    ctx->r14 = S32(ctx->r4 << 5);
    // 0x801088A0: addu        $t0, $a1, $t6
    ctx->r8 = ADD32(ctx->r5, ctx->r14);
    // 0x801088A4: lb          $v0, 0x1D($t0)
    ctx->r2 = MEM_B(ctx->r8, 0X1D);
    // 0x801088A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801088AC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801088B0: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x801088B4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x801088B8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x801088BC: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x801088C0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801088C4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801088C8: beq         $v0, $at, L_80108938
    if (ctx->r2 == ctx->r1) {
        // 0x801088CC: sdc1        $f20, 0x10($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
            goto L_80108938;
    }
    // 0x801088CC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801088D0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801088D4: addiu       $t9, $t9, -0x14E0
    ctx->r25 = ADD32(ctx->r25, -0X14E0);
    // 0x801088D8: sll         $t7, $a0, 5
    ctx->r15 = S32(ctx->r4 << 5);
    // 0x801088DC: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x801088E0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801088E4: lw          $s3, 0x0($a1)
    ctx->r19 = MEM_W(ctx->r5, 0X0);
    // 0x801088E8: addu        $s4, $t8, $t9
    ctx->r20 = ADD32(ctx->r24, ctx->r25);
    // 0x801088EC: addu        $s1, $a1, $t7
    ctx->r17 = ADD32(ctx->r5, ctx->r15);
    // 0x801088F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801088F4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x801088F8: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
L_801088FC:
    // 0x801088FC: lw          $s2, 0x8($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X8);
    // 0x80108900: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80108904: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80108908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010890C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80108910: jal         0x800C88AC
    // 0x80108914: addu        $a2, $t1, $s3
    ctx->r6 = ADD32(ctx->r9, ctx->r19);
    lbCommonAddTreeDObjsAnimAll(rdram, ctx);
        goto after_0;
    // 0x80108914: addu        $a2, $t1, $s3
    ctx->r6 = ADD32(ctx->r9, ctx->r19);
    after_0:
    // 0x80108918: jal         0x8000CCBC
    // 0x8010891C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8010891C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80108920: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80108924: bne         $s0, $s5, L_801088FC
    if (ctx->r16 != ctx->r21) {
        // 0x80108928: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801088FC;
    }
    // 0x80108928: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8010892C: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x80108930: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x80108934: sb          $t2, 0x1D($t3)
    MEM_B(0X1D, ctx->r11) = ctx->r10;
L_80108938:
    // 0x80108938: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010893C: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80108940: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80108944: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80108948: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8010894C: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80108950: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80108954: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80108958: jr          $ra
    // 0x8010895C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8010895C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftNessSpecialLwHoldProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801555E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801555E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801555EC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801555F0: jal         0x800DDE84
    // 0x801555F4: addiu       $a1, $a1, 0x5680
    ctx->r5 = ADD32(ctx->r5, 0X5680);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x801555F4: addiu       $a1, $a1, 0x5680
    ctx->r5 = ADD32(ctx->r5, 0X5680);
    after_0:
    // 0x801555F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801555FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155600: jr          $ra
    // 0x80155604: nop

    return;
    // 0x80155604: nop

;}
RECOMP_FUNC void func_ovl8_8037588C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037588C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x80375890: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x80375894: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x80375898: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8037589C: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x803758A0: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x803758A4: jr          $ra
    // 0x803758A8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    return;
    // 0x803758A8: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void ftCommonDokanEndUpdateModelYaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801425E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801425E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801425EC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801425F0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801425F4: lwc1        $f4, 0x78($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801425F8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801425FC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80142600: nop

    // 0x80142604: bc1fl       L_80142654
    if (!c1cs) {
        // 0x80142608: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80142654;
    }
    goto skip_0;
    // 0x80142608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014260C: lw          $a1, 0xB40($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XB40);
    // 0x80142610: beql        $a1, $zero, L_80142654
    if (ctx->r5 == 0) {
        // 0x80142614: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80142654;
    }
    goto skip_1;
    // 0x80142614: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80142618: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x8014261C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x80142620: sw          $t6, 0xB40($v0)
    MEM_W(0XB40, ctx->r2) = ctx->r14;
    // 0x80142624: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80142628: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014262C: lwc1        $f8, -0x3ED4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3ED4);
    // 0x80142630: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80142634: lw          $v1, 0x8E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8E8);
    // 0x80142638: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8014263C: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80142640: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80142644: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    // 0x80142648: jal         0x800EB528
    // 0x8014264C: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_0;
    // 0x8014264C: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    after_0:
    // 0x80142650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80142654:
    // 0x80142654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80142658: jr          $ra
    // 0x8014265C: nop

    return;
    // 0x8014265C: nop

;}
RECOMP_FUNC void itLizardonFallUnusedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017F49C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017F4A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017F4A4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017F4A8: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8017F4AC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8017F4B0: addiu       $a3, $a3, -0x71C
    ctx->r7 = ADD32(ctx->r7, -0X71C);
    // 0x8017F4B4: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8017F4B8: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8017F4BC: jal         0x80173C68
    // 0x8017F4C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itMapCheckLanding(rdram, ctx);
        goto after_0;
    // 0x8017F4C0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017F4C4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017F4C8: lhu         $t6, 0x8E($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X8E);
    // 0x8017F4CC: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x8017F4D0: beql        $t7, $zero, L_8017F4E8
    if (ctx->r15 == 0) {
        // 0x8017F4D4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8017F4E8;
    }
    goto skip_0;
    // 0x8017F4D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017F4D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017F4DC: nop

    // 0x8017F4E0: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x8017F4E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017F4E8:
    // 0x8017F4E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017F4EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017F4F0: jr          $ra
    // 0x8017F4F4: nop

    return;
    // 0x8017F4F4: nop

;}
RECOMP_FUNC void itPippiCommonSelectMonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183210: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80183214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80183218: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x8018321C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80183220: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80183224: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80183228: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8018322C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80183230: jal         0x80018994
    // 0x80183234: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80183234: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80183238: addiu       $v1, $v0, 0x20
    ctx->r3 = ADD32(ctx->r2, 0X20);
    // 0x8018323C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80183240: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80183244: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80183248: beq         $v0, $at, L_80183258
    if (ctx->r2 == ctx->r1) {
        // 0x8018324C: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80183258;
    }
    // 0x8018324C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80183250: addiu       $at, $zero, 0x26
    ctx->r1 = ADD32(0, 0X26);
    // 0x80183254: bne         $v1, $at, L_80183298
    if (ctx->r3 != ctx->r1) {
        // 0x80183258: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80183298;
    }
L_80183258:
    // 0x80183258: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018325C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80183260: jal         0x80018994
    // 0x80183264: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80183264: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    after_1:
    // 0x80183268: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8018326C: bne         $v0, $zero, L_80183290
    if (ctx->r2 != 0) {
        // 0x80183270: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_80183290;
    }
    // 0x80183270: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80183274: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80183278: lwc1        $f4, -0x3120($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3120);
    // 0x8018327C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80183280: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80183284: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    // 0x80183288: b           L_80183298
    // 0x8018328C: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
        goto L_80183298;
    // 0x8018328C: sw          $t8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r24;
L_80183290:
    // 0x80183290: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80183294: sw          $t9, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r25;
L_80183298:
    // 0x80183298: addiu       $at, $zero, 0x2B
    ctx->r1 = ADD32(0, 0X2B);
    // 0x8018329C: beq         $a3, $at, L_801832B8
    if (ctx->r7 == ctx->r1) {
        // 0x801832A0: addiu       $v0, $zero, 0x29
        ctx->r2 = ADD32(0, 0X29);
            goto L_801832B8;
    }
    // 0x801832A0: addiu       $v0, $zero, 0x29
    ctx->r2 = ADD32(0, 0X29);
    // 0x801832A4: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x801832A8: beq         $a3, $at, L_801832B8
    if (ctx->r7 == ctx->r1) {
        // 0x801832AC: addiu       $at, $zero, 0x27
        ctx->r1 = ADD32(0, 0X27);
            goto L_801832B8;
    }
    // 0x801832AC: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x801832B0: bne         $a3, $at, L_801832BC
    if (ctx->r7 != ctx->r1) {
        // 0x801832B4: nop
    
            goto L_801832BC;
    }
    // 0x801832B4: nop

L_801832B8:
    // 0x801832B8: sw          $zero, 0x10C($t0)
    MEM_W(0X10C, ctx->r8) = 0;
L_801832BC:
    // 0x801832BC: bne         $a3, $v0, L_801832C8
    if (ctx->r7 != ctx->r2) {
        // 0x801832C0: addiu       $t1, $zero, 0x28
        ctx->r9 = ADD32(0, 0X28);
            goto L_801832C8;
    }
    // 0x801832C0: addiu       $t1, $zero, 0x28
    ctx->r9 = ADD32(0, 0X28);
    // 0x801832C4: sh          $t1, 0x33E($t0)
    MEM_H(0X33E, ctx->r8) = ctx->r9;
L_801832C8:
    // 0x801832C8: beq         $a3, $v0, L_801832D8
    if (ctx->r7 == ctx->r2) {
        // 0x801832CC: addiu       $at, $zero, 0x28
        ctx->r1 = ADD32(0, 0X28);
            goto L_801832D8;
    }
    // 0x801832CC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801832D0: bnel        $a3, $at, L_80183308
    if (ctx->r7 != ctx->r1) {
        // 0x801832D4: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_80183308;
    }
    goto skip_0;
    // 0x801832D4: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    skip_0:
L_801832D8:
    // 0x801832D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801832DC: lui         $t2, 0x8018
    ctx->r10 = S32(0X8018 << 16);
    // 0x801832E0: addiu       $t2, $t2, 0x34A0
    ctx->r10 = ADD32(ctx->r10, 0X34A0);
    // 0x801832E4: sw          $t2, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r10;
    // 0x801832E8: lw          $a2, 0x28($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X28);
    // 0x801832EC: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x801832F0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801832F4: jal         0x8000A14C
    // 0x801832F8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    gcMoveGObjDLHead(rdram, ctx);
        goto after_2;
    // 0x801832F8: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_2:
    // 0x801832FC: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80183300: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80183304: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
L_80183308:
    // 0x80183308: bne         $a3, $at, L_80183314
    if (ctx->r7 != ctx->r1) {
        // 0x8018330C: addiu       $t3, $zero, 0x1E0
        ctx->r11 = ADD32(0, 0X1E0);
            goto L_80183314;
    }
    // 0x8018330C: addiu       $t3, $zero, 0x1E0
    ctx->r11 = ADD32(0, 0X1E0);
    // 0x80183310: sh          $t3, 0x33E($t0)
    MEM_H(0X33E, ctx->r8) = ctx->r11;
L_80183314:
    // 0x80183314: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80183318: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018331C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80183320: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80183324: addu        $t9, $t9, $t5
    ctx->r25 = ADD32(ctx->r25, ctx->r13);
    // 0x80183328: lw          $t9, -0x4C90($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4C90);
    // 0x8018332C: jalr        $t9
    // 0x80183330: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80183330: nop

    after_3:
    // 0x80183334: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183338: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018333C: jr          $ra
    // 0x80183340: nop

    return;
    // 0x80183340: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingUpdateCostume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801355E0: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x801355E4: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x801355E8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801355EC: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x801355F0: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x801355F4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801355F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801355FC: addiu       $t8, $t8, -0x7AA8
    ctx->r24 = ADD32(ctx->r24, -0X7AA8);
    // 0x80135600: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80135604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80135608: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013560C: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80135610: jal         0x800EC0EC
    // 0x80135614: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80135614: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    after_0:
    // 0x80135618: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8013561C: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x80135620: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80135624: jal         0x80133350
    // 0x80135628: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    mnPlayers1PTrainingCheckCostumeUsed(rdram, ctx);
        goto after_1;
    // 0x80135628: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_1:
    // 0x8013562C: beq         $v0, $zero, L_80135644
    if (ctx->r2 == 0) {
        // 0x80135630: lw          $a1, 0x24($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X24);
            goto L_80135644;
    }
    // 0x80135630: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80135634: jal         0x800269C0
    // 0x80135638: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80135638: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_2:
    // 0x8013563C: b           L_80135664
    // 0x80135640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80135664;
    // 0x80135640: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80135644:
    // 0x80135644: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80135648: jal         0x800E9248
    // 0x8013564C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_3;
    // 0x8013564C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80135650: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80135654: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    // 0x80135658: jal         0x800269C0
    // 0x8013565C: sw          $t9, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r25;
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x8013565C: sw          $t9, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r25;
    after_4:
    // 0x80135660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80135664:
    // 0x80135664: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80135668: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013566C: jr          $ra
    // 0x80135670: nop

    return;
    // 0x80135670: nop

;}
RECOMP_FUNC void itFushigibanaWeaponRazorProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801848BC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801848C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801848C4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801848C8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801848CC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x801848D0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801848D4: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x801848D8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x801848DC: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x801848E0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x801848E4: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x801848E8: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x801848EC: jal         0x80019438
    // 0x801848F0: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x801848F0: nop

    after_0:
    // 0x801848F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801848F8: lwc1        $f12, 0x24($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X24);
    // 0x801848FC: jal         0x8001863C
    // 0x80184900: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x80184900: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    after_1:
    // 0x80184904: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80184908: lwc1        $f10, -0x30CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X30CC);
    // 0x8018490C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80184910: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80184914: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80184918: lw          $t7, 0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X74);
    // 0x8018491C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80184920: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80184924: swc1        $f16, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f16.u32l;
    // 0x80184928: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x8018492C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80184930: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80184934: swc1        $f18, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f18.u32l;
    // 0x80184938: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8018493C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80184940: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80184944: nop

    // 0x80184948: bc1fl       L_8018495C
    if (!c1cs) {
        // 0x8018494C: sw          $t0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r8;
            goto L_8018495C;
    }
    goto skip_0;
    // 0x8018494C: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    skip_0:
    // 0x80184950: b           L_8018495C
    // 0x80184954: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
        goto L_8018495C;
    // 0x80184954: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x80184958: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_8018495C:
    // 0x8018495C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80184960: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80184964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80184968: jr          $ra
    // 0x8018496C: nop

    return;
    // 0x8018496C: nop

;}
RECOMP_FUNC void func_ovl8_80386588(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038658C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80386590: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80386594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80386598: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8038659C: lui         $a0, 0x4B79
    ctx->r4 = S32(0X4B79 << 16);
    // 0x803865A0: ori         $a0, $a0, 0x5064
    ctx->r4 = ctx->r4 | 0X5064;
    // 0x803865A4: jal         0x80381B70
    // 0x803865A8: addiu       $a1, $a1, 0x6994
    ctx->r5 = ADD32(ctx->r5, 0X6994);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_0;
    // 0x803865A8: addiu       $a1, $a1, 0x6994
    ctx->r5 = ADD32(ctx->r5, 0X6994);
    after_0:
    // 0x803865AC: lui         $a0, 0x8038
    ctx->r4 = S32(0X8038 << 16);
    // 0x803865B0: addiu       $a0, $a0, 0x7F40
    ctx->r4 = ADD32(ctx->r4, 0X7F40);
    // 0x803865B4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x803865B8: jal         0x803865D0
    // 0x803865BC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    func_ovl8_803865D0(rdram, ctx);
        goto after_1;
    // 0x803865BC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x803865C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803865C4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803865C8: jr          $ra
    // 0x803865CC: nop

    return;
    // 0x803865CC: nop

;}
RECOMP_FUNC void gmRumbleGetEventPriorityRelink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115458: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x8011545C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80115460: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80115464: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x80115468: beq         $v0, $zero, L_80115524
    if (ctx->r2 == 0) {
        // 0x8011546C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80115524;
    }
    // 0x8011546C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80115470: addiu       $t0, $t0, -0xDD4
    ctx->r8 = ADD32(ctx->r8, -0XDD4);
    // 0x80115474: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
L_80115478:
    // 0x80115478: lw          $t6, 0x10($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X10);
    // 0x8011547C: beq         $t6, $zero, L_80115510
    if (ctx->r14 == 0) {
        // 0x80115480: nop
    
            goto L_80115510;
    }
    // 0x80115480: nop

    // 0x80115484: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x80115488: addu        $t7, $t0, $a3
    ctx->r15 = ADD32(ctx->r8, ctx->r7);
    // 0x8011548C: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80115490: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x80115494: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x80115498: slt         $at, $t8, $t2
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8011549C: bnel        $at, $zero, L_8011551C
    if (ctx->r1 != 0) {
        // 0x801154A0: lw          $a2, 0x4($a2)
        ctx->r6 = MEM_W(ctx->r6, 0X4);
            goto L_8011551C;
    }
    goto skip_0;
    // 0x801154A0: lw          $a2, 0x4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4);
    skip_0:
    // 0x801154A4: bne         $a2, $v0, L_801154CC
    if (ctx->r6 != ctx->r2) {
        // 0x801154A8: nop
    
            goto L_801154CC;
    }
    // 0x801154A8: nop

    // 0x801154AC: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x801154B0: lw          $t4, 0x8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X8);
    // 0x801154B4: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x801154B8: sw          $v1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r3;
    // 0x801154BC: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x801154C0: sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // 0x801154C4: jr          $ra
    // 0x801154C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    return;
    // 0x801154C8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_801154CC:
    // 0x801154CC: beq         $a2, $v1, L_80115508
    if (ctx->r6 == ctx->r3) {
        // 0x801154D0: nop
    
            goto L_80115508;
    }
    // 0x801154D0: nop

    // 0x801154D4: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x801154D8: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x801154DC: sw          $t5, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r13;
    // 0x801154E0: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x801154E4: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x801154E8: sw          $t7, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r15;
    // 0x801154EC: lw          $t1, 0x8($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X8);
    // 0x801154F0: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x801154F4: sw          $v1, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r3;
    // 0x801154F8: sw          $a2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r6;
    // 0x801154FC: sw          $v1, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r3;
    // 0x80115500: jr          $ra
    // 0x80115504: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    return;
    // 0x80115504: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80115508:
    // 0x80115508: jr          $ra
    // 0x8011550C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    return;
    // 0x8011550C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_80115510:
    // 0x80115510: jr          $ra
    // 0x80115514: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x80115514: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80115518: lw          $a2, 0x4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X4);
L_8011551C:
    // 0x8011551C: bnel        $a2, $zero, L_80115478
    if (ctx->r6 != 0) {
        // 0x80115520: lw          $a1, 0x0($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X0);
            goto L_80115478;
    }
    goto skip_1;
    // 0x80115520: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    skip_1:
L_80115524:
    // 0x80115524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80115528: jr          $ra
    // 0x8011552C: nop

    return;
    // 0x8011552C: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueRoomFadeOutProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321A8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801321AC: addiu       $v0, $v0, 0x432C
    ctx->r2 = ADD32(ctx->r2, 0X432C);
    // 0x801321B0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801321B4: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x801321B8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801321BC: slti        $at, $v1, 0xFF
    ctx->r1 = SIGNED(ctx->r3) < 0XFF ? 1 : 0;
    // 0x801321C0: beq         $at, $zero, L_801321E0
    if (ctx->r1 == 0) {
        // 0x801321C4: addiu       $t4, $t4, 0x65B0
        ctx->r12 = ADD32(ctx->r12, 0X65B0);
            goto L_801321E0;
    }
    // 0x801321C4: addiu       $t4, $t4, 0x65B0
    ctx->r12 = ADD32(ctx->r12, 0X65B0);
    // 0x801321C8: addiu       $t6, $v1, 0x5
    ctx->r14 = ADD32(ctx->r3, 0X5);
    // 0x801321CC: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x801321D0: bne         $at, $zero, L_801321E0
    if (ctx->r1 != 0) {
        // 0x801321D4: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_801321E0;
    }
    // 0x801321D4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801321D8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x801321DC: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_801321E0:
    // 0x801321E0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x801321E4: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x801321E8: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x801321EC: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x801321F0: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x801321F4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x801321F8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x801321FC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132200: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80132204: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80132208: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8013220C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80132210: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80132214: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80132218: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8013221C: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80132220: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80132224: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80132228: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8013222C: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80132230: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80132234: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80132238: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8013223C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132240: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x80132244: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x80132248: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x8013224C: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80132250: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80132254: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80132258: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8013225C: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x80132260: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80132264: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x80132268: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8013226C: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80132270: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x80132274: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x80132278: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8013227C: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80132280: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80132284: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80132288: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8013228C: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80132290: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x80132294: ori         $t8, $t8, 0x8028
    ctx->r24 = ctx->r24 | 0X8028;
    // 0x80132298: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8013229C: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x801322A0: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x801322A4: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x801322A8: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x801322AC: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x801322B0: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x801322B4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x801322B8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x801322BC: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x801322C0: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x801322C4: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x801322C8: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x801322CC: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x801322D0: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x801322D4: jr          $ra
    // 0x801322D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x801322D8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void ftCommonTaruCannProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143E10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80143E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80143E18: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80143E1C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80143E20: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80143E24: lw          $v1, 0xB1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB1C);
    // 0x80143E28: beq         $v1, $zero, L_80143E70
    if (ctx->r3 == 0) {
        // 0x80143E2C: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80143E70;
    }
    // 0x80143E2C: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80143E30: sw          $t6, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r14;
    // 0x80143E34: bne         $t6, $at, L_80143E58
    if (ctx->r14 != ctx->r1) {
        // 0x80143E38: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80143E58;
    }
    // 0x80143E38: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80143E3C: addiu       $a0, $zero, 0x119
    ctx->r4 = ADD32(0, 0X119);
    // 0x80143E40: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80143E44: jal         0x800269C0
    // 0x80143E48: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80143E48: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_0:
    // 0x80143E4C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80143E50: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80143E54: lw          $v1, 0xB1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB1C);
L_80143E58:
    // 0x80143E58: bnel        $v1, $zero, L_80143E74
    if (ctx->r3 != 0) {
        // 0x80143E5C: lw          $t7, 0xB18($v0)
        ctx->r15 = MEM_W(ctx->r2, 0XB18);
            goto L_80143E74;
    }
    goto skip_0;
    // 0x80143E5C: lw          $t7, 0xB18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB18);
    skip_0:
    // 0x80143E60: jal         0x80144038
    // 0x80143E64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftCommonTaruCannShootFighter(rdram, ctx);
        goto after_1;
    // 0x80143E64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80143E68: b           L_80143EA4
    // 0x80143E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80143EA4;
    // 0x80143E6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143E70:
    // 0x80143E70: lw          $t7, 0xB18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB18);
L_80143E74:
    // 0x80143E74: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80143E78: slti        $at, $t8, 0xB4
    ctx->r1 = SIGNED(ctx->r24) < 0XB4 ? 1 : 0;
    // 0x80143E7C: bne         $at, $zero, L_80143EA0
    if (ctx->r1 != 0) {
        // 0x80143E80: sw          $t8, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r24;
            goto L_80143EA0;
    }
    // 0x80143E80: sw          $t8, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r24;
    // 0x80143E84: lw          $t0, 0xB1C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XB1C);
    // 0x80143E88: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x80143E8C: bnel        $t0, $zero, L_80143EA4
    if (ctx->r8 != 0) {
        // 0x80143E90: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80143EA4;
    }
    goto skip_1;
    // 0x80143E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80143E94: sw          $t1, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r9;
    // 0x80143E98: jal         0x80109D20
    // 0x80143E9C: lw          $a0, 0xB20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XB20);
    grJungleTaruCannAddAnimShoot(rdram, ctx);
        goto after_2;
    // 0x80143E9C: lw          $a0, 0xB20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XB20);
    after_2:
L_80143EA0:
    // 0x80143EA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80143EA4:
    // 0x80143EA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80143EA8: jr          $ra
    // 0x80143EAC: nop

    return;
    // 0x80143EAC: nop

;}
RECOMP_FUNC void gcLinkGObjAfter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800079D4: beq         $a1, $zero, L_800079EC
    if (ctx->r5 == 0) {
        // 0x800079D8: sw          $a1, 0x8($a0)
        MEM_W(0X8, ctx->r4) = ctx->r5;
            goto L_800079EC;
    }
    // 0x800079D8: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x800079DC: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800079E0: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800079E4: b           L_80007A0C
    // 0x800079E8: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
        goto L_80007A0C;
    // 0x800079E8: sw          $a0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r4;
L_800079EC:
    // 0x800079EC: lbu         $t7, 0xC($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0XC);
    // 0x800079F0: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800079F4: addiu       $t9, $t9, 0x66F0
    ctx->r25 = ADD32(ctx->r25, 0X66F0);
    // 0x800079F8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800079FC: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80007A00: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80007A04: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80007A08: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
L_80007A0C:
    // 0x80007A0C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80007A10: beql        $v0, $zero, L_80007A24
    if (ctx->r2 == 0) {
        // 0x80007A14: lbu         $t1, 0xC($a0)
        ctx->r9 = MEM_BU(ctx->r4, 0XC);
            goto L_80007A24;
    }
    goto skip_0;
    // 0x80007A14: lbu         $t1, 0xC($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XC);
    skip_0:
    // 0x80007A18: jr          $ra
    // 0x80007A1C: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    return;
    // 0x80007A1C: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x80007A20: lbu         $t1, 0xC($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XC);
L_80007A24:
    // 0x80007A24: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80007A28: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80007A2C: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x80007A30: sw          $a0, 0x6778($at)
    MEM_W(0X6778, ctx->r1) = ctx->r4;
    // 0x80007A34: jr          $ra
    // 0x80007A38: nop

    return;
    // 0x80007A38: nop

;}
RECOMP_FUNC void func_ovl8_80377B40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80377B40: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80377B44: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80377B48: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80377B4C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80377B50: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80377B54: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80377B58: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80377B5C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80377B60: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80377B64: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80377B68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80377B6C: sh          $zero, 0x82($sp)
    MEM_H(0X82, ctx->r29) = 0;
    // 0x80377B70: sh          $zero, 0x80($sp)
    MEM_H(0X80, ctx->r29) = 0;
    // 0x80377B74: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x80377B78: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80377B7C: addiu       $fp, $sp, 0x80
    ctx->r30 = ADD32(ctx->r29, 0X80);
    // 0x80377B80: sh          $t6, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r14;
    // 0x80377B84: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x80377B88: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80377B8C: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80377B90: addiu       $a2, $sp, 0x90
    ctx->r6 = ADD32(ctx->r29, 0X90);
    // 0x80377B94: jal         0x8037A67C
    // 0x80377B98: sh          $t7, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r15;
    func_ovl8_8037A67C(rdram, ctx);
        goto after_0;
    // 0x80377B98: sh          $t7, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r15;
    after_0:
    // 0x80377B9C: jal         0x8037AA5C
    // 0x80377BA0: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    func_ovl8_8037AA5C(rdram, ctx);
        goto after_1;
    // 0x80377BA0: addiu       $a0, $sp, 0x90
    ctx->r4 = ADD32(ctx->r29, 0X90);
    after_1:
    // 0x80377BA4: bnel        $v0, $zero, L_80377ED0
    if (ctx->r2 != 0) {
        // 0x80377BA8: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80377ED0;
    }
    goto skip_0;
    // 0x80377BA8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x80377BAC: lw          $v0, 0x34($s7)
    ctx->r2 = MEM_W(ctx->r23, 0X34);
    // 0x80377BB0: lh          $t8, 0x90($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X90);
    // 0x80377BB4: lh          $t0, 0x92($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X92);
    // 0x80377BB8: lh          $s2, 0x0($v0)
    ctx->r18 = MEM_H(ctx->r2, 0X0);
    // 0x80377BBC: lh          $s5, 0xC($v0)
    ctx->r21 = MEM_H(ctx->r2, 0XC);
    // 0x80377BC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80377BC4: div         $zero, $t8, $s2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r18)));
    // 0x80377BC8: mflo        $t9
    ctx->r25 = lo;
    // 0x80377BCC: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x80377BD0: bne         $s2, $zero, L_80377BDC
    if (ctx->r18 != 0) {
        // 0x80377BD4: nop
    
            goto L_80377BDC;
    }
    // 0x80377BD4: nop

    // 0x80377BD8: break       7
    do_break(2151119832);
L_80377BDC:
    // 0x80377BDC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80377BE0: bne         $s2, $at, L_80377BF4
    if (ctx->r18 != ctx->r1) {
        // 0x80377BE4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80377BF4;
    }
    // 0x80377BE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80377BE8: bne         $t8, $at, L_80377BF4
    if (ctx->r24 != ctx->r1) {
        // 0x80377BEC: nop
    
            goto L_80377BF4;
    }
    // 0x80377BEC: nop

    // 0x80377BF0: break       6
    do_break(2151119856);
L_80377BF4:
    // 0x80377BF4: div         $zero, $t0, $s5
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r21)));
    // 0x80377BF8: mflo        $t1
    ctx->r9 = lo;
    // 0x80377BFC: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80377C00: lh          $a0, 0x4($s7)
    ctx->r4 = MEM_H(ctx->r23, 0X4);
    // 0x80377C04: bne         $s5, $zero, L_80377C10
    if (ctx->r21 != 0) {
        // 0x80377C08: nop
    
            goto L_80377C10;
    }
    // 0x80377C08: nop

    // 0x80377C0C: break       7
    do_break(2151119884);
L_80377C10:
    // 0x80377C10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80377C14: bne         $s5, $at, L_80377C28
    if (ctx->r21 != ctx->r1) {
        // 0x80377C18: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80377C28;
    }
    // 0x80377C18: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80377C1C: bne         $t0, $at, L_80377C28
    if (ctx->r8 != ctx->r1) {
        // 0x80377C20: nop
    
            goto L_80377C28;
    }
    // 0x80377C20: nop

    // 0x80377C24: break       6
    do_break(2151119908);
L_80377C28:
    // 0x80377C28: div         $zero, $a0, $s2
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r18)));
    // 0x80377C2C: mfhi        $t2
    ctx->r10 = hi;
    // 0x80377C30: addiu       $s6, $sp, 0x88
    ctx->r22 = ADD32(ctx->r29, 0X88);
    // 0x80377C34: bne         $s2, $zero, L_80377C40
    if (ctx->r18 != 0) {
        // 0x80377C38: nop
    
            goto L_80377C40;
    }
    // 0x80377C38: nop

    // 0x80377C3C: break       7
    do_break(2151119932);
L_80377C40:
    // 0x80377C40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80377C44: bne         $s2, $at, L_80377C58
    if (ctx->r18 != ctx->r1) {
        // 0x80377C48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80377C58;
    }
    // 0x80377C48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80377C4C: bne         $a0, $at, L_80377C58
    if (ctx->r4 != ctx->r1) {
        // 0x80377C50: nop
    
            goto L_80377C58;
    }
    // 0x80377C50: nop

    // 0x80377C54: break       6
    do_break(2151119956);
L_80377C58:
    // 0x80377C58: beq         $t2, $zero, L_80377C68
    if (ctx->r10 == 0) {
        // 0x80377C5C: nop
    
            goto L_80377C68;
    }
    // 0x80377C5C: nop

    // 0x80377C60: b           L_80377C68
    // 0x80377C64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80377C68;
    // 0x80377C64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80377C68:
    // 0x80377C68: div         $zero, $a0, $s2
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r18)));
    // 0x80377C6C: lhu         $v0, 0x94($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X94);
    // 0x80377C70: mflo        $t3
    ctx->r11 = lo;
    // 0x80377C74: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x80377C78: bne         $s2, $zero, L_80377C84
    if (ctx->r18 != 0) {
        // 0x80377C7C: nop
    
            goto L_80377C84;
    }
    // 0x80377C7C: nop

    // 0x80377C80: break       7
    do_break(2151120000);
L_80377C84:
    // 0x80377C84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80377C88: bne         $s2, $at, L_80377C9C
    if (ctx->r18 != ctx->r1) {
        // 0x80377C8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80377C9C;
    }
    // 0x80377C8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80377C90: bne         $a0, $at, L_80377C9C
    if (ctx->r4 != ctx->r1) {
        // 0x80377C94: nop
    
            goto L_80377C9C;
    }
    // 0x80377C94: nop

    // 0x80377C98: break       6
    do_break(2151120024);
L_80377C9C:
    // 0x80377C9C: div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // 0x80377CA0: mfhi        $t5
    ctx->r13 = hi;
    // 0x80377CA4: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x80377CA8: bne         $s2, $zero, L_80377CB4
    if (ctx->r18 != 0) {
        // 0x80377CAC: nop
    
            goto L_80377CB4;
    }
    // 0x80377CAC: nop

    // 0x80377CB0: break       7
    do_break(2151120048);
L_80377CB4:
    // 0x80377CB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80377CB8: bne         $s2, $at, L_80377CCC
    if (ctx->r18 != ctx->r1) {
        // 0x80377CBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80377CCC;
    }
    // 0x80377CBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80377CC0: bne         $v0, $at, L_80377CCC
    if (ctx->r2 != ctx->r1) {
        // 0x80377CC4: nop
    
            goto L_80377CCC;
    }
    // 0x80377CC4: nop

    // 0x80377CC8: break       6
    do_break(2151120072);
L_80377CCC:
    // 0x80377CCC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80377CD0: beq         $t5, $zero, L_80377CE0
    if (ctx->r13 == 0) {
        // 0x80377CD4: nop
    
            goto L_80377CE0;
    }
    // 0x80377CD4: nop

    // 0x80377CD8: b           L_80377CE0
    // 0x80377CDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80377CE0;
    // 0x80377CDC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80377CE0:
    // 0x80377CE0: div         $zero, $v0, $s2
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r18)));
    // 0x80377CE4: lhu         $a1, 0x96($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X96);
    // 0x80377CE8: mflo        $t6
    ctx->r14 = lo;
    // 0x80377CEC: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x80377CF0: bne         $s2, $zero, L_80377CFC
    if (ctx->r18 != 0) {
        // 0x80377CF4: nop
    
            goto L_80377CFC;
    }
    // 0x80377CF4: nop

    // 0x80377CF8: break       7
    do_break(2151120120);
L_80377CFC:
    // 0x80377CFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80377D00: bne         $s2, $at, L_80377D14
    if (ctx->r18 != ctx->r1) {
        // 0x80377D04: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80377D14;
    }
    // 0x80377D04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80377D08: bne         $v0, $at, L_80377D14
    if (ctx->r2 != ctx->r1) {
        // 0x80377D0C: nop
    
            goto L_80377D14;
    }
    // 0x80377D0C: nop

    // 0x80377D10: break       6
    do_break(2151120144);
L_80377D14:
    // 0x80377D14: div         $zero, $a1, $s5
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r21)));
    // 0x80377D18: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80377D1C: mfhi        $t9
    ctx->r25 = hi;
    // 0x80377D20: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80377D24: bne         $s5, $zero, L_80377D30
    if (ctx->r21 != 0) {
        // 0x80377D28: nop
    
            goto L_80377D30;
    }
    // 0x80377D28: nop

    // 0x80377D2C: break       7
    do_break(2151120172);
L_80377D30:
    // 0x80377D30: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80377D34: bne         $s5, $at, L_80377D48
    if (ctx->r21 != ctx->r1) {
        // 0x80377D38: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80377D48;
    }
    // 0x80377D38: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80377D3C: bne         $a1, $at, L_80377D48
    if (ctx->r5 != ctx->r1) {
        // 0x80377D40: nop
    
            goto L_80377D48;
    }
    // 0x80377D40: nop

    // 0x80377D44: break       6
    do_break(2151120196);
L_80377D48:
    // 0x80377D48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80377D4C: beq         $t9, $zero, L_80377D5C
    if (ctx->r25 == 0) {
        // 0x80377D50: nop
    
            goto L_80377D5C;
    }
    // 0x80377D50: nop

    // 0x80377D54: b           L_80377D5C
    // 0x80377D58: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80377D5C;
    // 0x80377D58: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80377D5C:
    // 0x80377D5C: div         $zero, $a1, $s5
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r21)));
    // 0x80377D60: mflo        $t0
    ctx->r8 = lo;
    // 0x80377D64: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    // 0x80377D68: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80377D6C: bne         $s5, $zero, L_80377D78
    if (ctx->r21 != 0) {
        // 0x80377D70: nop
    
            goto L_80377D78;
    }
    // 0x80377D70: nop

    // 0x80377D74: break       7
    do_break(2151120244);
L_80377D78:
    // 0x80377D78: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80377D7C: bne         $s5, $at, L_80377D90
    if (ctx->r21 != ctx->r1) {
        // 0x80377D80: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80377D90;
    }
    // 0x80377D80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80377D84: bne         $a1, $at, L_80377D90
    if (ctx->r5 != ctx->r1) {
        // 0x80377D88: nop
    
            goto L_80377D90;
    }
    // 0x80377D88: nop

    // 0x80377D8C: break       6
    do_break(2151120268);
L_80377D90:
    // 0x80377D90: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x80377D94: blez        $a0, L_80377ECC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80377D98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80377ECC;
    }
    // 0x80377D98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80377D9C: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
L_80377DA0:
    // 0x80377DA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80377DA4: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x80377DA8: blezl       $t1, L_80377EBC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80377DAC: lw          $t9, 0x70($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X70);
            goto L_80377EBC;
    }
    goto skip_1;
    // 0x80377DAC: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    skip_1:
    // 0x80377DB0: multu       $t2, $s2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377DB4: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80377DB8: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80377DBC: addu        $s3, $t3, $v0
    ctx->r19 = ADD32(ctx->r11, ctx->r2);
    // 0x80377DC0: mflo        $s1
    ctx->r17 = lo;
    // 0x80377DC4: nop

    // 0x80377DC8: nop

    // 0x80377DCC: multu       $s3, $s5
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377DD0: mflo        $s4
    ctx->r20 = lo;
    // 0x80377DD4: nop

    // 0x80377DD8: nop

    // 0x80377DDC: sh          $s1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r17;
L_80377DE0:
    // 0x80377DE0: sh          $s4, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r20;
    // 0x80377DE4: sh          $s2, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r18;
    // 0x80377DE8: sh          $s5, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r21;
    // 0x80377DEC: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80377DF0: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x80377DF4: jal         0x8037A67C
    // 0x80377DF8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    func_ovl8_8037A67C(rdram, ctx);
        goto after_2;
    // 0x80377DF8: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_2:
    // 0x80377DFC: beq         $v0, $zero, L_80377EA0
    if (ctx->r2 == 0) {
        // 0x80377E00: lh          $t4, 0x80($sp)
        ctx->r12 = MEM_H(ctx->r29, 0X80);
            goto L_80377EA0;
    }
    // 0x80377E00: lh          $t4, 0x80($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X80);
    // 0x80377E04: div         $zero, $t4, $s2
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r18))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r18)));
    // 0x80377E08: mfhi        $t5
    ctx->r13 = hi;
    // 0x80377E0C: lh          $t6, 0x82($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X82);
    // 0x80377E10: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80377E14: bne         $s2, $zero, L_80377E20
    if (ctx->r18 != 0) {
        // 0x80377E18: nop
    
            goto L_80377E20;
    }
    // 0x80377E18: nop

    // 0x80377E1C: break       7
    do_break(2151120412);
L_80377E20:
    // 0x80377E20: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80377E24: bne         $s2, $at, L_80377E38
    if (ctx->r18 != ctx->r1) {
        // 0x80377E28: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80377E38;
    }
    // 0x80377E28: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80377E2C: bne         $t4, $at, L_80377E38
    if (ctx->r12 != ctx->r1) {
        // 0x80377E30: nop
    
            goto L_80377E38;
    }
    // 0x80377E30: nop

    // 0x80377E34: break       6
    do_break(2151120436);
L_80377E38:
    // 0x80377E38: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x80377E3C: mfhi        $t7
    ctx->r15 = hi;
    // 0x80377E40: sh          $t5, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r13;
    // 0x80377E44: sh          $t7, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r15;
    // 0x80377E48: multu       $s3, $t9
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80377E4C: lw          $t8, 0x34($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X34);
    // 0x80377E50: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80377E54: sll         $t3, $s0, 4
    ctx->r11 = S32(ctx->r16 << 4);
    // 0x80377E58: bne         $s5, $zero, L_80377E64
    if (ctx->r21 != 0) {
        // 0x80377E5C: nop
    
            goto L_80377E64;
    }
    // 0x80377E5C: nop

    // 0x80377E60: break       7
    do_break(2151120480);
L_80377E64:
    // 0x80377E64: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80377E68: bne         $s5, $at, L_80377E7C
    if (ctx->r21 != ctx->r1) {
        // 0x80377E6C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80377E7C;
    }
    // 0x80377E6C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80377E70: bne         $t6, $at, L_80377E7C
    if (ctx->r14 != ctx->r1) {
        // 0x80377E74: nop
    
            goto L_80377E7C;
    }
    // 0x80377E74: nop

    // 0x80377E78: break       6
    do_break(2151120504);
L_80377E7C:
    // 0x80377E7C: mflo        $t0
    ctx->r8 = lo;
    // 0x80377E80: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80377E84: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80377E88: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80377E8C: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x80377E90: addu        $a0, $t4, $t6
    ctx->r4 = ADD32(ctx->r12, ctx->r14);
    // 0x80377E94: lbu         $a1, 0x31($s7)
    ctx->r5 = MEM_BU(ctx->r23, 0X31);
    // 0x80377E98: jal         0x803773CC
    // 0x80377E9C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    func_ovl8_803773CC(rdram, ctx);
        goto after_3;
    // 0x80377E9C: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_3:
L_80377EA0:
    // 0x80377EA0: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x80377EA4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80377EA8: addu        $s1, $s1, $s2
    ctx->r17 = ADD32(ctx->r17, ctx->r18);
    // 0x80377EAC: bnel        $s0, $t7, L_80377DE0
    if (ctx->r16 != ctx->r15) {
        // 0x80377EB0: sh          $s1, 0x88($sp)
        MEM_H(0X88, ctx->r29) = ctx->r17;
            goto L_80377DE0;
    }
    goto skip_2;
    // 0x80377EB0: sh          $s1, 0x88($sp)
    MEM_H(0X88, ctx->r29) = ctx->r17;
    skip_2:
    // 0x80377EB4: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80377EB8: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
L_80377EBC:
    // 0x80377EBC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80377EC0: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80377EC4: bnel        $at, $zero, L_80377DA0
    if (ctx->r1 != 0) {
        // 0x80377EC8: lw          $t1, 0x74($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X74);
            goto L_80377DA0;
    }
    goto skip_3;
    // 0x80377EC8: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    skip_3:
L_80377ECC:
    // 0x80377ECC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80377ED0:
    // 0x80377ED0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80377ED4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80377ED8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80377EDC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80377EE0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80377EE4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80377EE8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80377EEC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80377EF0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80377EF4: jr          $ra
    // 0x80377EF8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80377EF8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void ftAnimEndSetFall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D94E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D94EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D94F0: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D94F4: jal         0x800D9480
    // 0x800D94F8: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x800D94F8: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    after_0:
    // 0x800D94FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D9500: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D9504: jr          $ra
    // 0x800D9508: nop

    return;
    // 0x800D9508: nop

;}
RECOMP_FUNC void grPupupuMakeMapGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801064C8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801064CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801064D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801064D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801064D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801064DC: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x801064E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801064E4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801064E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801064EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801064F0: jal         0x80009968
    // 0x801064F4: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801064F4: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    after_0:
    // 0x801064F8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801064FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80106500: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80106504: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80106508: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x8010650C: lbu         $a2, 0x37($sp)
    ctx->r6 = MEM_BU(ctx->r29, 0X37);
    // 0x80106510: jal         0x80009DF4
    // 0x80106514: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80106514: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80106518: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010651C: lw          $t7, 0x13F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X13F0);
    // 0x80106520: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80106524: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8010652C: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x80106530: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80106534: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80106538: jal         0x8000F590
    // 0x8010653C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_2;
    // 0x8010653C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80106540: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x80106544: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80106548: beq         $v0, $zero, L_80106560
    if (ctx->r2 == 0) {
        // 0x8010654C: nop
    
            goto L_80106560;
    }
    // 0x8010654C: nop

    // 0x80106550: lw          $t9, 0x13F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X13F0);
    // 0x80106554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80106558: jal         0x8000F8F4
    // 0x8010655C: addu        $a1, $t9, $v0
    ctx->r5 = ADD32(ctx->r25, ctx->r2);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x8010655C: addu        $a1, $t9, $v0
    ctx->r5 = ADD32(ctx->r25, ctx->r2);
    after_3:
L_80106560:
    // 0x80106560: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80106564: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80106568: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010656C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80106570: jal         0x80008188
    // 0x80106574: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80106574: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
    // 0x80106578: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8010657C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80106580: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80106584: jr          $ra
    // 0x80106588: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80106588: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itKamexAppearProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801808D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801808DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801808E0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801808E4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x801808E8: jal         0x80172558
    // 0x801808EC: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x801808EC: lui         $a2, 0x4220
    ctx->r6 = S32(0X4220 << 16);
    after_0:
    // 0x801808F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801808F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801808F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801808FC: jr          $ra
    // 0x80180900: nop

    return;
    // 0x80180900: nop

;}

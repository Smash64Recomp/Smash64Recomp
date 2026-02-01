#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void SC1PGameBossWallpaper2ProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801915B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801915BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801915C0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801915C4: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801915C8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801915CC: beq         $v0, $zero, L_801915F0
    if (ctx->r2 == 0) {
        // 0x801915D0: lui         $t9, 0xE200
        ctx->r25 = S32(0XE200 << 16);
            goto L_801915F0;
    }
    // 0x801915D0: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x801915D4: lw          $v1, 0x80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X80);
L_801915D8:
    // 0x801915D8: beql        $v1, $zero, L_801915E8
    if (ctx->r3 == 0) {
        // 0x801915DC: lw          $v0, 0x10($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X10);
            goto L_801915E8;
    }
    goto skip_0;
    // 0x801915DC: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
    skip_0:
    // 0x801915E0: sb          $a1, 0x5B($v1)
    MEM_B(0X5B, ctx->r3) = ctx->r5;
    // 0x801915E4: lw          $v0, 0x10($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X10);
L_801915E8:
    // 0x801915E8: bnel        $v0, $zero, L_801915D8
    if (ctx->r2 != 0) {
        // 0x801915EC: lw          $v1, 0x80($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X80);
            goto L_801915D8;
    }
    goto skip_1;
    // 0x801915EC: lw          $v1, 0x80($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X80);
    skip_1:
L_801915F0:
    // 0x801915F0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801915F4: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801915F8: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x801915FC: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x80191600: ori         $t1, $t1, 0x41C8
    ctx->r9 = ctx->r9 | 0X41C8;
    // 0x80191604: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80191608: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8019160C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191610: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80191614: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80191618: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x8019161C: andi        $t4, $a1, 0xFF
    ctx->r12 = ctx->r5 & 0XFF;
    // 0x80191620: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80191624: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80191628: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8019162C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80191630: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80191634: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x80191638: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x8019163C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80191640: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80191644: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80191648: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8019164C: jal         0x80014768
    // 0x80191650: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    gcDrawDObjTreeDLLinksForGObj(rdram, ctx);
        goto after_0;
    // 0x80191650: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    after_0:
    // 0x80191654: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80191658: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8019165C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80191660: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80191664: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80191668: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8019166C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80191670: ori         $t8, $t8, 0x49D8
    ctx->r24 = ctx->r24 | 0X49D8;
    // 0x80191674: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80191678: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8019167C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80191680: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80191684: lui         $t1, 0xE700
    ctx->r9 = S32(0XE700 << 16);
    // 0x80191688: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8019168C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80191690: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80191694: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80191698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8019169C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801916A0: jr          $ra
    // 0x801916A4: nop

    return;
    // 0x801916A4: nop

;}
RECOMP_FUNC void lbBackupClearAllData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4C48: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800D4C4C: addiu       $t7, $t7, 0x3994
    ctx->r15 = ADD32(ctx->r15, 0X3994);
    // 0x800D4C50: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800D4C54: addiu       $t6, $t6, 0x44E0
    ctx->r14 = ADD32(ctx->r14, 0X44E0);
    // 0x800D4C58: addiu       $t0, $t7, 0x5E8
    ctx->r8 = ADD32(ctx->r15, 0X5E8);
L_800D4C5C:
    // 0x800D4C5C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800D4C60: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x800D4C64: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x800D4C68: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x800D4C6C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x800D4C70: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x800D4C74: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x800D4C78: bne         $t7, $t0, L_800D4C5C
    if (ctx->r15 != ctx->r8) {
        // 0x800D4C7C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_800D4C5C;
    }
    // 0x800D4C7C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x800D4C80: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x800D4C84: jr          $ra
    // 0x800D4C88: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    return;
    // 0x800D4C88: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
;}
RECOMP_FUNC void ftHammerCheckGotoHammerWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F39AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F39B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F39B4: jal         0x8013E258
    // 0x800F39B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonWaitCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x800F39B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800F39BC: beql        $v0, $zero, L_800F39D8
    if (ctx->r2 == 0) {
        // 0x800F39C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F39D8;
    }
    goto skip_0;
    // 0x800F39C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800F39C4: jal         0x800F3938
    // 0x800F39C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftHammerSetStatusHammerWait(rdram, ctx);
        goto after_1;
    // 0x800F39C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800F39CC: b           L_800F39D8
    // 0x800F39D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F39D8;
    // 0x800F39D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F39D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F39D8:
    // 0x800F39D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F39DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F39E0: jr          $ra
    // 0x800F39E4: nop

    return;
    // 0x800F39E4: nop

;}
RECOMP_FUNC void func_ovl8_8037DAA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DAA0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8037DAA4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8037DAA8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8037DAAC: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8037DAB0: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x8037DAB4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8037DAB8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8037DABC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8037DAC0: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037DAC4: addiu       $a0, $a0, -0x468
    ctx->r4 = ADD32(ctx->r4, -0X468);
    // 0x8037DAC8: jal         0x80377134
    // 0x8037DACC: lbu         $a1, 0x31($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X31);
    func_ovl8_80377134(rdram, ctx);
        goto after_0;
    // 0x8037DACC: lbu         $a1, 0x31($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X31);
    after_0:
    // 0x8037DAD0: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x8037DAD4: addiu       $s1, $s1, -0xFB8
    ctx->r17 = ADD32(ctx->r17, -0XFB8);
    // 0x8037DAD8: lhu         $v1, 0x0($s1)
    ctx->r3 = MEM_HU(ctx->r17, 0X0);
    // 0x8037DADC: andi        $t7, $v1, 0xFF00
    ctx->r15 = ctx->r3 & 0XFF00;
    // 0x8037DAE0: beq         $t7, $zero, L_8037DBD4
    if (ctx->r15 == 0) {
        // 0x8037DAE4: addu        $t8, $v1, $s0
        ctx->r24 = ADD32(ctx->r3, ctx->r16);
            goto L_8037DBD4;
    }
    // 0x8037DAE4: addu        $t8, $v1, $s0
    ctx->r24 = ADD32(ctx->r3, ctx->r16);
    // 0x8037DAE8: andi        $v0, $t8, 0xFFFF
    ctx->r2 = ctx->r24 & 0XFFFF;
    // 0x8037DAEC: sra         $a0, $v0, 8
    ctx->r4 = S32(SIGNED(ctx->r2) >> 8);
    // 0x8037DAF0: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x8037DAF4: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
    // 0x8037DAF8: jal         0x8037DA08
    // 0x8037DAFC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    func_ovl8_8037DA08(rdram, ctx);
        goto after_1;
    // 0x8037DAFC: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    after_1:
    // 0x8037DB00: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x8037DB04: addiu       $s0, $s0, -0xFE0
    ctx->r16 = ADD32(ctx->r16, -0XFE0);
    // 0x8037DB08: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8037DB0C: lhu         $t0, 0x4($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X4);
    // 0x8037DB10: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8037DB14: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037DB18: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037DB1C: addu        $a2, $t9, $v0
    ctx->r6 = ADD32(ctx->r25, ctx->r2);
    // 0x8037DB20: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037DB24: lw          $t9, -0xFC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XFC0);
    // 0x8037DB28: addiu       $a3, $a3, -0xFB0
    ctx->r7 = ADD32(ctx->r7, -0XFB0);
    // 0x8037DB2C: mflo        $a0
    ctx->r4 = lo;
    // 0x8037DB30: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8037DB34: jalr        $t9
    // 0x8037DB38: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8037DB38: nop

    after_2:
    // 0x8037DB3C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037DB40: lwc1        $f4, -0xFC8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0XFC8);
    // 0x8037DB44: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037DB48: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x8037DB4C: addiu       $t2, $t2, -0xD70
    ctx->r10 = ADD32(ctx->r10, -0XD70);
    // 0x8037DB50: addiu       $t1, $t1, -0xFB0
    ctx->r9 = ADD32(ctx->r9, -0XFB0);
    // 0x8037DB54: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x8037DB58: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x8037DB5C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8037DB60: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8037DB64: lhu         $a2, 0x4($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4);
    // 0x8037DB68: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8037DB6C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8037DB70: jal         0x8037DFF8
    // 0x8037DB74: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    func_ovl8_8037DFF8(rdram, ctx);
        goto after_3;
    // 0x8037DB74: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8037DB78: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8037DB7C: lw          $t4, -0x470($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X470);
    // 0x8037DB80: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x8037DB84: addiu       $t3, $t3, -0x1000
    ctx->r11 = ADD32(ctx->r11, -0X1000);
    // 0x8037DB88: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8037DB8C: addiu       $a1, $a1, -0xD70
    ctx->r5 = ADD32(ctx->r5, -0XD70);
    // 0x8037DB90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8037DB94: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8037DB98: lhu         $a2, 0x2($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X2);
    // 0x8037DB9C: lhu         $a3, 0x4($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X4);
    // 0x8037DBA0: jal         0x803798A0
    // 0x8037DBA4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    func_ovl8_803798A0(rdram, ctx);
        goto after_4;
    // 0x8037DBA4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    after_4:
    // 0x8037DBA8: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037DBAC: addiu       $v0, $v0, -0x1000
    ctx->r2 = ADD32(ctx->r2, -0X1000);
    // 0x8037DBB0: lh          $t5, 0x0($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X0);
    // 0x8037DBB4: lhu         $t6, 0x2($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X2);
    // 0x8037DBB8: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037DBBC: lhu         $t8, -0xFBC($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0XFBC);
    // 0x8037DBC0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8037DBC4: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
    // 0x8037DBC8: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8037DBCC: b           L_8037DD4C
    // 0x8037DBD0: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
        goto L_8037DD4C;
    // 0x8037DBD0: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
L_8037DBD4:
    // 0x8037DBD4: andi        $t9, $s0, 0x80
    ctx->r25 = ctx->r16 & 0X80;
    // 0x8037DBD8: beq         $t9, $zero, L_8037DBEC
    if (ctx->r25 == 0) {
        // 0x8037DBDC: or          $v0, $s0, $zero
        ctx->r2 = ctx->r16 | 0;
            goto L_8037DBEC;
    }
    // 0x8037DBDC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8037DBE0: sll         $t2, $s0, 8
    ctx->r10 = S32(ctx->r16 << 8);
    // 0x8037DBE4: b           L_8037DD4C
    // 0x8037DBE8: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
        goto L_8037DD4C;
    // 0x8037DBE8: sh          $t2, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r10;
L_8037DBEC:
    // 0x8037DBEC: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x8037DBF0: bne         $at, $zero, L_8037DBFC
    if (ctx->r1 != 0) {
        // 0x8037DBF4: slti        $at, $v0, 0x7F
        ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
            goto L_8037DBFC;
    }
    // 0x8037DBF4: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x8037DBF8: bne         $at, $zero, L_8037DC0C
    if (ctx->r1 != 0) {
        // 0x8037DBFC: slti        $at, $v0, 0xA0
        ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
            goto L_8037DC0C;
    }
L_8037DBFC:
    // 0x8037DBFC: slti        $at, $v0, 0xA0
    ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
    // 0x8037DC00: bne         $at, $zero, L_8037DD4C
    if (ctx->r1 != 0) {
        // 0x8037DC04: slti        $at, $v0, 0xE0
        ctx->r1 = SIGNED(ctx->r2) < 0XE0 ? 1 : 0;
            goto L_8037DD4C;
    }
    // 0x8037DC04: slti        $at, $v0, 0xE0
    ctx->r1 = SIGNED(ctx->r2) < 0XE0 ? 1 : 0;
    // 0x8037DC08: beq         $at, $zero, L_8037DD4C
    if (ctx->r1 == 0) {
        // 0x8037DC0C: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_8037DD4C;
    }
L_8037DC0C:
    // 0x8037DC0C: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x8037DC10: bne         $at, $zero, L_8037DC20
    if (ctx->r1 != 0) {
        // 0x8037DC14: lui         $t4, 0x8039
        ctx->r12 = S32(0X8039 << 16);
            goto L_8037DC20;
    }
    // 0x8037DC14: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8037DC18: b           L_8037DC24
    // 0x8037DC1C: addiu       $s1, $v0, -0x41
    ctx->r17 = ADD32(ctx->r2, -0X41);
        goto L_8037DC24;
    // 0x8037DC1C: addiu       $s1, $v0, -0x41
    ctx->r17 = ADD32(ctx->r2, -0X41);
L_8037DC20:
    // 0x8037DC20: addiu       $s1, $v0, -0x20
    ctx->r17 = ADD32(ctx->r2, -0X20);
L_8037DC24:
    // 0x8037DC24: lhu         $t4, -0xFD0($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0XFD0);
    // 0x8037DC28: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x8037DC2C: addiu       $s0, $s0, -0xFF8
    ctx->r16 = ADD32(ctx->r16, -0XFF8);
    // 0x8037DC30: multu       $t4, $s1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037DC34: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8037DC38: lhu         $t6, 0x4($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X4);
    // 0x8037DC3C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037DC40: lw          $t9, -0xFC4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XFC4);
    // 0x8037DC44: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x8037DC48: lui         $a3, 0x8039
    ctx->r7 = S32(0X8039 << 16);
    // 0x8037DC4C: addiu       $a3, $a3, -0xFB0
    ctx->r7 = ADD32(ctx->r7, -0XFB0);
    // 0x8037DC50: mflo        $t5
    ctx->r13 = lo;
    // 0x8037DC54: addu        $a2, $t3, $t5
    ctx->r6 = ADD32(ctx->r11, ctx->r13);
    // 0x8037DC58: nop

    // 0x8037DC5C: multu       $a1, $t6
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037DC60: mflo        $a0
    ctx->r4 = lo;
    // 0x8037DC64: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8037DC68: jalr        $t9
    // 0x8037DC6C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8037DC6C: nop

    after_5:
    // 0x8037DC70: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8037DC74: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x8037DC78: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037DC7C: addu        $v0, $t7, $v1
    ctx->r2 = ADD32(ctx->r15, ctx->r3);
    // 0x8037DC80: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x8037DC84: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    // 0x8037DC88: lwc1        $f6, -0xFCC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0XFCC);
    // 0x8037DC8C: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037DC90: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037DC94: addiu       $t1, $t1, -0xD70
    ctx->r9 = ADD32(ctx->r9, -0XD70);
    // 0x8037DC98: addiu       $t0, $t0, -0xFB0
    ctx->r8 = ADD32(ctx->r8, -0XFB0);
    // 0x8037DC9C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8037DCA0: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8037DCA4: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8037DCA8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8037DCAC: lhu         $a1, 0x2($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X2);
    // 0x8037DCB0: lhu         $a2, 0x4($s0)
    ctx->r6 = MEM_HU(ctx->r16, 0X4);
    // 0x8037DCB4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8037DCB8: jal         0x8037DFF8
    // 0x8037DCBC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    func_ovl8_8037DFF8(rdram, ctx);
        goto after_6;
    // 0x8037DCBC: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x8037DCC0: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x8037DCC4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8037DCC8: lhu         $t3, 0x2($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X2);
    // 0x8037DCCC: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037DCD0: addu        $v0, $t2, $t4
    ctx->r2 = ADD32(ctx->r10, ctx->r12);
    // 0x8037DCD4: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8037DCD8: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8037DCDC: lw          $t8, -0x470($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X470);
    // 0x8037DCE0: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037DCE4: addiu       $t7, $t7, -0x1000
    ctx->r15 = ADD32(ctx->r15, -0X1000);
    // 0x8037DCE8: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8037DCEC: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x8037DCF0: addiu       $a1, $a1, -0xD70
    ctx->r5 = ADD32(ctx->r5, -0XD70);
    // 0x8037DCF4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8037DCF8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8037DCFC: lhu         $a3, 0x4($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X4);
    // 0x8037DD00: subu        $a2, $t6, $t9
    ctx->r6 = SUB32(ctx->r14, ctx->r25);
    // 0x8037DD04: jal         0x803798A0
    // 0x8037DD08: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    func_ovl8_803798A0(rdram, ctx);
        goto after_7;
    // 0x8037DD08: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_7:
    // 0x8037DD0C: lw          $t0, 0x8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X8);
    // 0x8037DD10: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8037DD14: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x8037DD18: lh          $t2, -0x1000($t2)
    ctx->r10 = MEM_H(ctx->r10, -0X1000);
    // 0x8037DD1C: lhu         $t4, 0x2($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X2);
    // 0x8037DD20: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8037DD24: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8037DD28: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8037DD2C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037DD30: lhu         $t8, -0xFBC($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0XFBC);
    // 0x8037DD34: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x8037DD38: subu        $t6, $t3, $t5
    ctx->r14 = SUB32(ctx->r11, ctx->r13);
    // 0x8037DD3C: subu        $t7, $t6, $t9
    ctx->r15 = SUB32(ctx->r14, ctx->r25);
    // 0x8037DD40: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037DD44: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8037DD48: sh          $t0, -0x1000($at)
    MEM_H(-0X1000, ctx->r1) = ctx->r8;
L_8037DD4C:
    // 0x8037DD4C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8037DD50: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8037DD54: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8037DD58: jr          $ra
    // 0x8037DD5C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8037DD5C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void func_ovl3_80167618(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167618: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016761C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80167620: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80167624: jal         0x80167520
    // 0x80167628: addiu       $a1, $a1, -0x4B50
    ctx->r5 = ADD32(ctx->r5, -0X4B50);
    wpDisplayMain(rdram, ctx);
        goto after_0;
    // 0x80167628: addiu       $a1, $a1, -0x4B50
    ctx->r5 = ADD32(ctx->r5, -0X4B50);
    after_0:
    // 0x8016762C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80167630: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80167634: jr          $ra
    // 0x80167638: nop

    return;
    // 0x80167638: nop

;}
RECOMP_FUNC void ftBossYubideppou3ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A3C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A3C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A3C8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015A3CC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8015A3D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015A3D4: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015A3D8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8015A3DC: lwc1        $f6, 0xC($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8015A3E0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8015A3E4: nop

    // 0x8015A3E8: bc1fl       L_8015A430
    if (!c1cs) {
        // 0x8015A3EC: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8015A430;
    }
    goto skip_0;
    // 0x8015A3EC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_0:
    // 0x8015A3F0: lwc1        $f8, 0x78($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015A3F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8015A3F8: nop

    // 0x8015A3FC: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8015A400: nop

    // 0x8015A404: bc1fl       L_8015A430
    if (!c1cs) {
        // 0x8015A408: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8015A430;
    }
    goto skip_1;
    // 0x8015A408: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_1:
    // 0x8015A40C: lh          $t7, 0xB1A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XB1A);
    // 0x8015A410: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8015A414: beql        $t7, $at, L_8015A430
    if (ctx->r15 == ctx->r1) {
        // 0x8015A418: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_8015A430;
    }
    goto skip_2;
    // 0x8015A418: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_2:
    // 0x8015A41C: jal         0x8015A538
    // 0x8015A420: nop

    ftBossYubideppou3SetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A420: nop

    after_0:
    // 0x8015A424: b           L_8015A450
    // 0x8015A428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015A450;
    // 0x8015A428: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015A42C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_8015A430:
    // 0x8015A430: lwc1        $f18, 0x78($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015A434: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x8015A438: nop

    // 0x8015A43C: bc1fl       L_8015A450
    if (!c1cs) {
        // 0x8015A440: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015A450;
    }
    goto skip_3;
    // 0x8015A440: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8015A444: jal         0x80159040
    // 0x8015A448: nop

    ftBossWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015A448: nop

    after_1:
    // 0x8015A44C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015A450:
    // 0x8015A450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A454: jr          $ra
    // 0x8015A458: nop

    return;
    // 0x8015A458: nop

;}
RECOMP_FUNC void syVectorDiff3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001902C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019030: lwc1        $f6, 0x0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80019034: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80019038: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001903C: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80019040: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80019044: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019048: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8001904C: swc1        $f18, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f18.u32l;
    // 0x80019050: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80019054: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019058: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001905C: jr          $ra
    // 0x80019060: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80019060: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void efManagerItemSpawnSwirlMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801044B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801044B8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801044BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801044C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801044C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801044C8: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x801044CC: jal         0x800CE9E8
    // 0x801044D0: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x801044D0: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_0:
    // 0x801044D4: beq         $v0, $zero, L_8010453C
    if (ctx->r2 == 0) {
        // 0x801044D8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8010453C;
    }
    // 0x801044D8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801044DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801044E0: jal         0x800CE1DC
    // 0x801044E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x801044E4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x801044E8: beq         $v0, $zero, L_80104530
    if (ctx->r2 == 0) {
        // 0x801044EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80104530;
    }
    // 0x801044EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801044F0: jal         0x800CEA14
    // 0x801044F4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x801044F4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_2:
    // 0x801044F8: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801044FC: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80104500: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80104504: bnel        $t6, $zero, L_80104518
    if (ctx->r14 != 0) {
        // 0x80104508: lw          $t9, 0x0($t7)
        ctx->r25 = MEM_W(ctx->r15, 0X0);
            goto L_80104518;
    }
    goto skip_0;
    // 0x80104508: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    skip_0:
    // 0x8010450C: b           L_80104540
    // 0x80104510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80104540;
    // 0x80104510: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80104514: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
L_80104518:
    // 0x80104518: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8010451C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80104520: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x80104524: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80104528: b           L_8010453C
    // 0x8010452C: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
        goto L_8010453C;
    // 0x8010452C: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_80104530:
    // 0x80104530: jal         0x800CEA40
    // 0x80104534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80104534: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80104538: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8010453C:
    // 0x8010453C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80104540:
    // 0x80104540: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80104544: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80104548: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010454C: jr          $ra
    // 0x80104550: nop

    return;
    // 0x80104550: nop

;}
RECOMP_FUNC void ftSamusSpecialNLoopProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D640: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015D644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D648: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8015D64C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8015D650: lhu         $v0, 0x1BE($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X1BE);
    // 0x8015D654: lhu         $t6, 0x1B6($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0X1B6);
    // 0x8015D658: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x8015D65C: bne         $t7, $zero, L_8015D678
    if (ctx->r15 != 0) {
        // 0x8015D660: nop
    
            goto L_8015D678;
    }
    // 0x8015D660: nop

    // 0x8015D664: lhu         $t8, 0x1B4($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X1B4);
    // 0x8015D668: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8015D66C: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x8015D670: beql        $t9, $zero, L_8015D68C
    if (ctx->r25 == 0) {
        // 0x8015D674: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8015D68C;
    }
    goto skip_0;
    // 0x8015D674: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    skip_0:
L_8015D678:
    // 0x8015D678: jal         0x8015DA60
    // 0x8015D67C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftSamusSpecialNEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015D67C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8015D680: b           L_8015D6F4
    // 0x8015D684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015D6F4;
    // 0x8015D684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D688: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
L_8015D68C:
    // 0x8015D68C: jal         0x801492F8
    // 0x8015D690: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftCommonEscapeGetStatus(rdram, ctx);
        goto after_1;
    // 0x8015D690: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8015D694: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8015D698: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8015D69C: beq         $v0, $at, L_8015D6C8
    if (ctx->r2 == ctx->r1) {
        // 0x8015D6A0: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8015D6C8;
    }
    // 0x8015D6A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8015D6A4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8015D6A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8015D6AC: jal         0x8015D300
    // 0x8015D6B0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    ftSamusSpecialNDestroyChargeShot(rdram, ctx);
        goto after_2;
    // 0x8015D6B0: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x8015D6B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015D6B8: jal         0x80149294
    // 0x8015D6BC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftCommonEscapeSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015D6BC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8015D6C0: b           L_8015D6F4
    // 0x8015D6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015D6F4;
    // 0x8015D6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015D6C8:
    // 0x8015D6C8: lhu         $t0, 0x1BE($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X1BE);
    // 0x8015D6CC: lhu         $t1, 0x1B8($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X1B8);
    // 0x8015D6D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8015D6D4: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8015D6D8: beql        $t2, $zero, L_8015D6F4
    if (ctx->r10 == 0) {
        // 0x8015D6DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015D6F4;
    }
    goto skip_1;
    // 0x8015D6DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8015D6E0: jal         0x8015D300
    // 0x8015D6E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftSamusSpecialNDestroyChargeShot(rdram, ctx);
        goto after_4;
    // 0x8015D6E4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x8015D6E8: jal         0x8013E1C8
    // 0x8015D6EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_5;
    // 0x8015D6EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_5:
    // 0x8015D6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015D6F4:
    // 0x8015D6F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015D6F8: jr          $ra
    // 0x8015D6FC: nop

    return;
    // 0x8015D6FC: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F3F8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015F3FC: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x8015F400: jr          $ra
    // 0x8015F404: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    return;
    // 0x8015F404: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
;}
RECOMP_FUNC void scStaffrollCrosshairThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801343AC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801343B0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801343B4: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x801343B8: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x801343BC: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x801343C0: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x801343C4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x801343C8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x801343CC: sdc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X38, ctx->r29);
    // 0x801343D0: sdc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X30, ctx->r29);
    // 0x801343D4: sdc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X28, ctx->r29);
    // 0x801343D8: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x801343DC: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x801343E0: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x801343E4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801343E8: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x801343EC: lwc1        $f4, -0x5848($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5848);
    // 0x801343F0: mtc1        $zero, $f30
    ctx->f30.u32l = 0;
    // 0x801343F4: lui         $at, 0x4128
    ctx->r1 = S32(0X4128 << 16);
    // 0x801343F8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801343FC: addiu       $s1, $zero, 0x13
    ctx->r17 = ADD32(0, 0X13);
    // 0x80134400: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
    // 0x80134404: swc1        $f30, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f30.u32l;
L_80134408:
    // 0x80134408: lwc1        $f6, 0x5C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8013440C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80134410: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80134414: jal         0x8000B1E8
    // 0x80134418: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x80134418: swc1        $f8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f8.u32l;
    after_0:
    // 0x8013441C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80134420: bne         $s1, $zero, L_80134408
    if (ctx->r17 != 0) {
        // 0x80134424: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_80134408;
    }
    // 0x80134424: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80134428: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8013442C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134430: sw          $t6, -0x5740($at)
    MEM_W(-0X5740, ctx->r1) = ctx->r14;
    // 0x80134434: lui         $at, 0x4407
    ctx->r1 = S32(0X4407 << 16);
    // 0x80134438: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x8013443C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80134440: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80134444: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80134448: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8013444C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80134450: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80134454: lui         $at, 0x3E00
    ctx->r1 = S32(0X3E00 << 16);
    // 0x80134458: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x8013445C: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80134460: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80134464: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80134468: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8013446C: addiu       $s1, $s1, 0x5228
    ctx->r17 = ADD32(ctx->r17, 0X5228);
    // 0x80134470: addiu       $s2, $s2, -0x56FC
    ctx->r18 = ADD32(ctx->r18, -0X56FC);
    // 0x80134474: addiu       $s4, $s4, -0x572C
    ctx->r20 = ADD32(ctx->r20, -0X572C);
    // 0x80134478: addiu       $s5, $s5, -0x5728
    ctx->r21 = ADD32(ctx->r21, -0X5728);
    // 0x8013447C: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x80134480: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
L_80134484:
    // 0x80134484: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80134488: lwc1        $f14, 0x5C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8013448C: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134490: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
    // 0x80134494: mflo        $t8
    ctx->r24 = lo;
    // 0x80134498: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x8013449C: lb          $v1, 0x8($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X8);
    // 0x801344A0: lb          $a0, 0x9($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X9);
    // 0x801344A4: bgez        $v1, L_801344B4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x801344A8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801344B4;
    }
    // 0x801344A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801344AC: b           L_801344B4
    // 0x801344B0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_801344B4;
    // 0x801344B0: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_801344B4:
    // 0x801344B4: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x801344B8: bne         $at, $zero, L_801344D8
    if (ctx->r1 != 0) {
        // 0x801344BC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801344D8;
    }
    // 0x801344BC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801344C0: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x801344C4: nop

    // 0x801344C8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801344CC: mul.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x801344D0: b           L_801344E0
    // 0x801344D4: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
        goto L_801344E0;
    // 0x801344D4: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
L_801344D8:
    // 0x801344D8: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
    // 0x801344DC: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
L_801344E0:
    // 0x801344E0: bgez        $a0, L_801344F0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801344E4: swc1        $f18, 0x58($s0)
        MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
            goto L_801344F0;
    }
    // 0x801344E4: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x801344E8: b           L_801344F0
    // 0x801344EC: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
        goto L_801344F0;
    // 0x801344EC: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_801344F0:
    // 0x801344F0: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x801344F4: bnel        $at, $zero, L_80134518
    if (ctx->r1 != 0) {
        // 0x801344F8: mov.s       $f0, $f30
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
            goto L_80134518;
    }
    goto skip_0;
    // 0x801344F8: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
    skip_0:
    // 0x801344FC: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80134500: nop

    // 0x80134504: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80134508: mul.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8013450C: b           L_8013451C
    // 0x80134510: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
        goto L_8013451C;
    // 0x80134510: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80134514: mov.s       $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    ctx->f0.fl = ctx->f30.fl;
L_80134518:
    // 0x80134518: lwc1        $f2, 0x58($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X58);
L_8013451C:
    // 0x8013451C: lwc1        $f8, 0x5C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80134520: c.lt.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl < ctx->f22.fl;
    // 0x80134524: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x80134528: bc1f        L_80134538
    if (!c1cs) {
        // 0x8013452C: swc1        $f10, 0x5C($s0)
        MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
            goto L_80134538;
    }
    // 0x8013452C: swc1        $f10, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f10.u32l;
    // 0x80134530: b           L_80134558
    // 0x80134534: swc1        $f22, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f22.u32l;
        goto L_80134558;
    // 0x80134534: swc1        $f22, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f22.u32l;
L_80134538:
    // 0x80134538: c.lt.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl < ctx->f2.fl;
    // 0x8013453C: nop

    // 0x80134540: bc1fl       L_80134554
    if (!c1cs) {
        // 0x80134544: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80134554;
    }
    goto skip_1;
    // 0x80134544: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_1:
    // 0x80134548: b           L_80134554
    // 0x8013454C: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
        goto L_80134554;
    // 0x8013454C: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
    // 0x80134550: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80134554:
    // 0x80134554: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
L_80134558:
    // 0x80134558: lwc1        $f2, 0x5C($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x8013455C: c.lt.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl < ctx->f24.fl;
    // 0x80134560: nop

    // 0x80134564: bc1fl       L_80134578
    if (!c1cs) {
        // 0x80134568: c.lt.s      $f26, $f2
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl < ctx->f2.fl;
            goto L_80134578;
    }
    goto skip_2;
    // 0x80134568: c.lt.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl < ctx->f2.fl;
    skip_2:
    // 0x8013456C: b           L_80134594
    // 0x80134570: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
        goto L_80134594;
    // 0x80134570: swc1        $f24, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f24.u32l;
    // 0x80134574: c.lt.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl < ctx->f2.fl;
L_80134578:
    // 0x80134578: nop

    // 0x8013457C: bc1fl       L_80134590
    if (!c1cs) {
        // 0x80134580: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80134590;
    }
    goto skip_3;
    // 0x80134580: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_3:
    // 0x80134584: b           L_80134590
    // 0x80134588: mov.s       $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    ctx->f0.fl = ctx->f26.fl;
        goto L_80134590;
    // 0x80134588: mov.s       $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    ctx->f0.fl = ctx->f26.fl;
    // 0x8013458C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80134590:
    // 0x80134590: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
L_80134594:
    // 0x80134594: lwc1        $f16, 0x58($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80134598: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013459C: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x801345A0: swc1        $f18, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->f18.u32l;
    // 0x801345A4: lwc1        $f4, 0x5C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x801345A8: sub.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f14.fl;
    // 0x801345AC: jal         0x8000B1E8
    // 0x801345B0: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x801345B0: swc1        $f6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->f6.u32l;
    after_1:
    // 0x801345B4: b           L_80134484
    // 0x801345B8: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
        goto L_80134484;
    // 0x801345B8: lbu         $t7, 0x0($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X0);
    // 0x801345BC: nop

    // 0x801345C0: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801345C4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801345C8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801345CC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801345D0: ldc1        $f26, 0x28($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X28);
    // 0x801345D4: ldc1        $f28, 0x30($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X30);
    // 0x801345D8: ldc1        $f30, 0x38($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X38);
    // 0x801345DC: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x801345E0: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x801345E4: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x801345E8: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x801345EC: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x801345F0: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x801345F4: jr          $ra
    // 0x801345F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801345F8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_ovl8_80374E2C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374E2C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80374E30: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80374E34: addiu       $t7, $t7, -0x6AB0
    ctx->r15 = ADD32(ctx->r15, -0X6AB0);
    // 0x80374E38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80374E3C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x80374E40: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
    // 0x80374E44: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
L_80374E48:
    // 0x80374E48: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80374E4C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80374E50: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80374E54: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80374E58: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80374E5C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80374E60: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80374E64: bne         $t7, $t0, L_80374E48
    if (ctx->r15 != ctx->r8) {
        // 0x80374E68: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80374E48;
    }
    // 0x80374E68: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80374E6C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80374E70: addiu       $a0, $zero, 0x130
    ctx->r4 = ADD32(0, 0X130);
    // 0x80374E74: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80374E78: lh          $t1, 0x0($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X0);
    // 0x80374E7C: sh          $t1, 0x24($sp)
    MEM_H(0X24, ctx->r29) = ctx->r9;
    // 0x80374E80: lh          $t2, 0x2($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X2);
    // 0x80374E84: jal         0x803717A0
    // 0x80374E88: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80374E88: sh          $t2, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r10;
    after_0:
    // 0x80374E8C: beq         $v0, $zero, L_80374EB8
    if (ctx->r2 == 0) {
        // 0x80374E90: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80374EB8;
    }
    // 0x80374E90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80374E94: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    // 0x80374E98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80374E9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80374EA0: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    // 0x80374EA4: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80374EA8: jal         0x80380048
    // 0x80374EAC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    func_ovl8_80380048(rdram, ctx);
        goto after_1;
    // 0x80374EAC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_1:
    // 0x80374EB0: b           L_80374EBC
    // 0x80374EB4: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
        goto L_80374EBC;
    // 0x80374EB4: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
L_80374EB8:
    // 0x80374EB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80374EBC:
    // 0x80374EBC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80374EC0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80374EC4: jal         0x80380414
    // 0x80374EC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_ovl8_80380414(rdram, ctx);
        goto after_2;
    // 0x80374EC8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x80374ECC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80374ED0: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80374ED4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80374ED8: beql        $a2, $zero, L_80374F08
    if (ctx->r6 == 0) {
        // 0x80374EDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80374F08;
    }
    goto skip_0;
    // 0x80374EDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80374EE0: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    // 0x80374EE4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80374EE8: lh          $t4, 0x8($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X8);
    // 0x80374EEC: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80374EF0: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x80374EF4: addu        $a0, $t4, $v1
    ctx->r4 = ADD32(ctx->r12, ctx->r3);
    // 0x80374EF8: jalr        $t9
    // 0x80374EFC: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80374EFC: nop

    after_3:
    // 0x80374F00: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    // 0x80374F04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80374F08:
    // 0x80374F08: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80374F0C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80374F10: jr          $ra
    // 0x80374F14: nop

    return;
    // 0x80374F14: nop

;}
RECOMP_FUNC void mvOpeningKirbyMakeMotionWindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D62C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8018D630: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D634: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8018D638: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8018D63C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D640: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D644: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D648: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D64C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D650: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D654: jal         0x80104BDC
    // 0x8018D658: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_0;
    // 0x8018D658: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018D65C: jal         0x80105600
    // 0x8018D660: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_1;
    // 0x8018D660: nop

    after_1:
    // 0x8018D664: jal         0x800FC7A4
    // 0x8018D668: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_2;
    // 0x8018D668: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_2:
    // 0x8018D66C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D670: beq         $v0, $at, L_8018D698
    if (ctx->r2 == ctx->r1) {
        // 0x8018D674: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8018D698;
    }
    // 0x8018D674: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8018D678: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D67C: addiu       $s0, $s0, -0x1E10
    ctx->r16 = ADD32(ctx->r16, -0X1E10);
L_8018D680:
    // 0x8018D680: jal         0x80023624
    // 0x8018D684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x8018D684: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018D688: jal         0x800A3040
    // 0x8018D68C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x8018D68C: nop

    after_4:
    // 0x8018D690: b           L_8018D680
    // 0x8018D694: nop

        goto L_8018D680;
    // 0x8018D694: nop

L_8018D698:
    // 0x8018D698: jal         0x800FC814
    // 0x8018D69C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_5;
    // 0x8018D69C: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_5:
    // 0x8018D6A0: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x8018D6A4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D6A8: jal         0x800FC894
    // 0x8018D6AC: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_6;
    // 0x8018D6AC: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    after_6:
    // 0x8018D6B0: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8018D6B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018D6B8: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018D6BC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D6C0: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x8018D6C4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8018D6C8: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8018D6CC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8018D6D0: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8018D6D4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018D6D8: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018D6DC: jal         0x8018D41C
    // 0x8018D6E0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    mvOpeningKirbyMakeMotionCamera(rdram, ctx);
        goto after_7;
    // 0x8018D6E0: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_7:
    // 0x8018D6E4: jal         0x801156E4
    // 0x8018D6E8: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_8;
    // 0x8018D6E8: nop

    after_8:
    // 0x8018D6EC: jal         0x801653E0
    // 0x8018D6F0: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_9;
    // 0x8018D6F0: nop

    after_9:
    // 0x8018D6F4: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8018D6F8: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018D6FC: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018D700: addiu       $s6, $s6, 0x6DD0
    ctx->r22 = ADD32(ctx->r22, 0X6DD0);
    // 0x8018D704: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D708: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018D70C: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8018D710: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8018D714: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
L_8018D718:
    // 0x8018D718: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
    // 0x8018D71C: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8018D720: addiu       $t2, $s6, 0x3C
    ctx->r10 = ADD32(ctx->r22, 0X3C);
L_8018D724:
    // 0x8018D724: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D728: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8018D72C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018D730: sw          $t9, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r25;
    // 0x8018D734: lw          $t8, -0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X8);
    // 0x8018D738: sw          $t8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r24;
    // 0x8018D73C: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x8018D740: bne         $t0, $t2, L_8018D724
    if (ctx->r8 != ctx->r10) {
        // 0x8018D744: sw          $t9, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r25;
            goto L_8018D724;
    }
    // 0x8018D744: sw          $t9, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r25;
    // 0x8018D748: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D74C: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8018D750: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x8018D754: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8018D758: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8018D75C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8018D760: addiu       $t6, $t6, 0x5228
    ctx->r14 = ADD32(ctx->r14, 0X5228);
    // 0x8018D764: addu        $s0, $t3, $s2
    ctx->r16 = ADD32(ctx->r11, ctx->r18);
    // 0x8018D768: lbu         $t4, 0x22($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D76C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8018D770: addu        $s3, $t5, $t6
    ctx->r19 = ADD32(ctx->r13, ctx->r14);
    // 0x8018D774: beql        $s7, $t4, L_8018D838
    if (ctx->r23 == ctx->r12) {
        // 0x8018D778: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D838;
    }
    goto skip_0;
    // 0x8018D778: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8018D77C: jal         0x800D786C
    // 0x8018D780: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x8018D780: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_10:
    // 0x8018D784: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018D788: lwc1        $f10, 0x90($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018D78C: lwc1        $f16, 0x94($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018D790: addu        $s0, $v0, $s2
    ctx->r16 = ADD32(ctx->r2, ctx->r18);
    // 0x8018D794: lbu         $t7, 0x23($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D798: lwc1        $f18, 0x98($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8018D79C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D7A0: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8018D7A4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x8018D7A8: swc1        $f16, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f16.u32l;
    // 0x8018D7AC: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8018D7B0: swc1        $f18, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f18.u32l;
    // 0x8018D7B4: lbu         $t0, 0x24($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X24);
    // 0x8018D7B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D7BC: sb          $s1, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r17;
    // 0x8018D7C0: sb          $t1, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r9;
    // 0x8018D7C4: sb          $t0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r8;
    // 0x8018D7C8: lbu         $t8, 0x26($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X26);
    // 0x8018D7CC: sb          $t8, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r24;
    // 0x8018D7D0: lbu         $t9, 0x21($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X21);
    // 0x8018D7D4: sb          $t9, 0x69($sp)
    MEM_B(0X69, ctx->r29) = ctx->r25;
    // 0x8018D7D8: lbu         $t3, 0x20($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20);
    // 0x8018D7DC: sb          $t3, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r11;
    // 0x8018D7E0: lbu         $t4, 0x7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X7);
    // 0x8018D7E4: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8018D7E8: sb          $t4, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r12;
    // 0x8018D7EC: lbu         $t5, 0x22($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D7F0: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8018D7F4: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x8018D7F8: jal         0x800D78B4
    // 0x8018D7FC: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_11;
    // 0x8018D7FC: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_11:
    // 0x8018D800: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8018D804: jal         0x800D7F3C
    // 0x8018D808: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_12;
    // 0x8018D808: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x8018D80C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D810: sw          $v0, -0x1DD0($at)
    MEM_W(-0X1DD0, ctx->r1) = ctx->r2;
    // 0x8018D814: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D818: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D81C: jal         0x800E7C4C
    // 0x8018D820: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_13;
    // 0x8018D820: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8018D824: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D828: addiu       $a1, $a1, -0x1F18
    ctx->r5 = ADD32(ctx->r5, -0X1F18);
    // 0x8018D82C: jal         0x800E9B30
    // 0x8018D830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetKey(rdram, ctx);
        goto after_14;
    // 0x8018D830: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8018D834: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D838:
    // 0x8018D838: bne         $s1, $fp, L_8018D718
    if (ctx->r17 != ctx->r30) {
        // 0x8018D83C: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018D718;
    }
    // 0x8018D83C: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018D840: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D844: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D848: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D84C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018D850: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018D854: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018D858: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D85C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018D860: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8018D864: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8018D868: jr          $ra
    // 0x8018D86C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8018D86C: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void itStarRodMakeStar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178594: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80178598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017859C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801785A0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801785A4: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x801785A8: lw          $t7, 0x84C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84C);
    // 0x801785AC: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x801785B0: jal         0x80178474
    // 0x801785B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itStarRodWeaponStarMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x801785B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x801785B8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801785BC: lhu         $t8, 0x33E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X33E);
    // 0x801785C0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x801785C4: sh          $t9, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r25;
    // 0x801785C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801785CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801785D0: jr          $ra
    // 0x801785D4: nop

    return;
    // 0x801785D4: nop

;}
RECOMP_FUNC void lbCommonPrepSObjDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC818: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x800CC81C: sw          $s6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r22;
    // 0x800CC820: addiu       $s6, $a1, 0x10
    ctx->r22 = ADD32(ctx->r5, 0X10);
    // 0x800CC824: sw          $ra, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r31;
    // 0x800CC828: sw          $fp, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r30;
    // 0x800CC82C: sw          $s7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r23;
    // 0x800CC830: sw          $s5, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r21;
    // 0x800CC834: sw          $s4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r20;
    // 0x800CC838: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
    // 0x800CC83C: sw          $s2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r18;
    // 0x800CC840: sw          $s1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r17;
    // 0x800CC844: sw          $s0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r16;
    // 0x800CC848: sdc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X50, ctx->r29);
    // 0x800CC84C: sdc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X48, ctx->r29);
    // 0x800CC850: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x800CC854: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x800CC858: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CC85C: sw          $s6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r22;
    // 0x800CC860: lwc1        $f0, 0x5EC4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5EC4);
    // 0x800CC864: lwc1        $f4, 0x18($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X18);
    // 0x800CC868: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800CC86C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800CC870: nop

    // 0x800CC874: bc1tl       L_800CCE70
    if (c1cs) {
        // 0x800CC878: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_800CCE70;
    }
    goto skip_0;
    // 0x800CC878: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_0:
    // 0x800CC87C: lwc1        $f20, 0xC($s6)
    ctx->f20.u32l = MEM_W(ctx->r22, 0XC);
    // 0x800CC880: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800CC884: nop

    // 0x800CC888: bc1tl       L_800CCE70
    if (c1cs) {
        // 0x800CC88C: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_800CCE70;
    }
    goto skip_1;
    // 0x800CC88C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_1:
    // 0x800CC890: lw          $s2, 0x34($s6)
    ctx->r18 = MEM_W(ctx->r22, 0X34);
    // 0x800CC894: lui         $t2, 0x800D
    ctx->r10 = S32(0X800D << 16);
    // 0x800CC898: beql        $s2, $zero, L_800CCE70
    if (ctx->r18 == 0) {
        // 0x800CC89C: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_800CCE70;
    }
    goto skip_2;
    // 0x800CC89C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_2:
    // 0x800CC8A0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CC8A4: lwc1        $f18, 0x58($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X58);
    // 0x800CC8A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CC8AC: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800CC8B0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x800CC8B4: nop

    // 0x800CC8B8: bc1fl       L_800CC8DC
    if (!c1cs) {
        // 0x800CC8BC: trunc.w.s   $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
            goto L_800CC8DC;
    }
    goto skip_3;
    // 0x800CC8BC: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
    skip_3:
    // 0x800CC8C0: lwc1        $f22, 0x5EC8($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5EC8);
    // 0x800CC8C4: sub.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f22.fl;
    // 0x800CC8C8: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CC8CC: mfc1        $fp, $f8
    ctx->r30 = (int32_t)ctx->f8.u32l;
    // 0x800CC8D0: b           L_800CC8F0
    // 0x800CC8D4: lwc1        $f16, 0x5C($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X5C);
        goto L_800CC8F0;
    // 0x800CC8D4: lwc1        $f16, 0x5C($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X5C);
    // 0x800CC8D8: trunc.w.s   $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.u32l = TRUNC_W_S(ctx->f18.fl);
L_800CC8DC:
    // 0x800CC8DC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CC8E0: lwc1        $f22, 0x5ECC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X5ECC);
    // 0x800CC8E4: mfc1        $fp, $f10
    ctx->r30 = (int32_t)ctx->f10.u32l;
    // 0x800CC8E8: nop

    // 0x800CC8EC: lwc1        $f16, 0x5C($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X5C);
L_800CC8F0:
    // 0x800CC8F0: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x800CC8F4: nop

    // 0x800CC8F8: bc1fl       L_800CC918
    if (!c1cs) {
        // 0x800CC8FC: trunc.w.s   $f8, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
            goto L_800CC918;
    }
    goto skip_4;
    // 0x800CC8FC: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    skip_4:
    // 0x800CC900: sub.s       $f4, $f16, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f22.fl;
    // 0x800CC904: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CC908: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800CC90C: b           L_800CC920
    // 0x800CC910: nop

        goto L_800CC920;
    // 0x800CC910: nop

    // 0x800CC914: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
L_800CC918:
    // 0x800CC918: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800CC91C: nop

L_800CC920:
    // 0x800CC920: lw          $t2, 0x62BC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X62BC);
    // 0x800CC924: slt         $at, $fp, $t2
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800CC928: beql        $at, $zero, L_800CCE70
    if (ctx->r1 == 0) {
        // 0x800CC92C: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_800CCE70;
    }
    goto skip_5;
    // 0x800CC92C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_5:
    // 0x800CC930: lw          $t3, 0x62C0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X62C0);
    // 0x800CC934: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800CC938: beql        $at, $zero, L_800CCE70
    if (ctx->r1 == 0) {
        // 0x800CC93C: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_800CCE70;
    }
    goto skip_6;
    // 0x800CC93C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_6:
    // 0x800CC940: lbu         $t4, 0x65($s7)
    ctx->r12 = MEM_BU(ctx->r23, 0X65);
    // 0x800CC944: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x800CC948: bnel        $a1, $t4, L_800CC95C
    if (ctx->r5 != ctx->r12) {
        // 0x800CC94C: lhu         $v0, 0x68($s7)
        ctx->r2 = MEM_HU(ctx->r23, 0X68);
            goto L_800CC95C;
    }
    goto skip_7;
    // 0x800CC94C: lhu         $v0, 0x68($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X68);
    skip_7:
    // 0x800CC950: b           L_800CC95C
    // 0x800CC954: lh          $v0, 0x4($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X4);
        goto L_800CC95C;
    // 0x800CC954: lh          $v0, 0x4($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X4);
    // 0x800CC958: lhu         $v0, 0x68($s7)
    ctx->r2 = MEM_HU(ctx->r23, 0X68);
L_800CC95C:
    // 0x800CC95C: lbu         $t5, 0x64($s7)
    ctx->r13 = MEM_BU(ctx->r23, 0X64);
    // 0x800CC960: bnel        $a1, $t5, L_800CC978
    if (ctx->r5 != ctx->r13) {
        // 0x800CC964: lhu         $t7, 0x6A($s7)
        ctx->r15 = MEM_HU(ctx->r23, 0X6A);
            goto L_800CC978;
    }
    goto skip_8;
    // 0x800CC964: lhu         $t7, 0x6A($s7)
    ctx->r15 = MEM_HU(ctx->r23, 0X6A);
    skip_8:
    // 0x800CC968: lh          $t6, 0x2C($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X2C);
    // 0x800CC96C: b           L_800CC97C
    // 0x800CC970: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
        goto L_800CC97C;
    // 0x800CC970: sw          $t6, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r14;
    // 0x800CC974: lhu         $t7, 0x6A($s7)
    ctx->r15 = MEM_HU(ctx->r23, 0X6A);
L_800CC978:
    // 0x800CC978: sw          $t7, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r15;
L_800CC97C:
    // 0x800CC97C: lhu         $t8, 0x14($s6)
    ctx->r24 = MEM_HU(ctx->r22, 0X14);
    // 0x800CC980: andi        $t9, $t8, 0x20
    ctx->r25 = ctx->r24 & 0X20;
    // 0x800CC984: beql        $t9, $zero, L_800CCA98
    if (ctx->r25 == 0) {
        // 0x800CC988: mtc1        $v0, $f10
        ctx->f10.u32l = ctx->r2;
            goto L_800CCA98;
    }
    goto skip_9;
    // 0x800CC988: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    skip_9:
    // 0x800CC98C: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800CC990: lui         $t3, 0x800D
    ctx->r11 = S32(0X800D << 16);
    // 0x800CC994: lw          $t3, 0x62C4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X62C4);
    // 0x800CC998: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CC99C: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x800CC9A0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800CC9A4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CC9A8: mfc1        $s3, $f8
    ctx->r19 = (int32_t)ctx->f8.u32l;
    // 0x800CC9AC: nop

    // 0x800CC9B0: slt         $at, $s3, $t3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800CC9B4: bnel        $at, $zero, L_800CCE70
    if (ctx->r1 != 0) {
        // 0x800CC9B8: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_800CCE70;
    }
    goto skip_10;
    // 0x800CC9B8: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_10:
    // 0x800CC9BC: lh          $v0, 0x28($s6)
    ctx->r2 = MEM_H(ctx->r22, 0X28);
    // 0x800CC9C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CC9C4: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x800CC9C8: bne         $v0, $at, L_800CCA14
    if (ctx->r2 != ctx->r1) {
        // 0x800CC9CC: or          $a1, $s7, $zero
        ctx->r5 = ctx->r23 | 0;
            goto L_800CCA14;
    }
    // 0x800CC9CC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800CC9D0: lw          $t4, 0xC8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XC8);
    // 0x800CC9D4: addiu       $t6, $zero, 0x1000
    ctx->r14 = ADD32(0, 0X1000);
    // 0x800CC9D8: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x800CC9DC: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x800CC9E0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x800CC9E4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800CC9E8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x800CC9EC: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CC9F0: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800CC9F4: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800CC9F8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800CC9FC: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x800CCA00: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800CCA04: jal         0x800CB7D4
    // 0x800CCA08: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    lbCommonDrawSObjBitmap(rdram, ctx);
        goto after_0;
    // 0x800CCA08: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_0:
    // 0x800CCA0C: b           L_800CCE70
    // 0x800CCA10: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_800CCE70;
    // 0x800CCA10: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_800CCA14:
    // 0x800CCA14: blez        $v0, L_800CCE6C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CCA18: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800CCE6C;
    }
    // 0x800CCA18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CCA1C: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x800CCA20: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
L_800CCA24:
    // 0x800CCA24: addiu       $t9, $zero, 0x1000
    ctx->r25 = ADD32(0, 0X1000);
    // 0x800CCA28: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x800CCA2C: addu        $s1, $s0, $t8
    ctx->r17 = ADD32(ctx->r16, ctx->r24);
    // 0x800CCA30: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800CCA34: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800CCA38: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x800CCA3C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x800CCA40: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800CCA44: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CCA48: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800CCA4C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800CCA50: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CCA54: sw          $s3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r19;
    // 0x800CCA58: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800CCA5C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x800CCA60: jal         0x800CB7D4
    // 0x800CCA64: sw          $v1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r3;
    lbCommonDrawSObjBitmap(rdram, ctx);
        goto after_1;
    // 0x800CCA64: sw          $v1, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r3;
    after_1:
    // 0x800CCA68: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x800CCA6C: lw          $v1, 0xB0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XB0);
    // 0x800CCA70: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x800CCA74: lh          $t4, 0x28($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X28);
    // 0x800CCA78: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CCA7C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800CCA80: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800CCA84: bnel        $at, $zero, L_800CCA24
    if (ctx->r1 != 0) {
        // 0x800CCA88: lw          $t8, 0xC8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XC8);
            goto L_800CCA24;
    }
    goto skip_11;
    // 0x800CCA88: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    skip_11:
    // 0x800CCA8C: b           L_800CCE70
    // 0x800CCA90: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_800CCE70;
    // 0x800CCA90: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    // 0x800CCA94: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
L_800CCA98:
    // 0x800CCA98: lwc1        $f2, 0x8($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X8);
    // 0x800CCA9C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CCAA0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CCAA4: lw          $t6, 0x62C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X62C4);
    // 0x800CCAA8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CCAAC: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800CCAB0: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x800CCAB4: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CCAB8: mfc1        $s5, $f4
    ctx->r21 = (int32_t)ctx->f4.u32l;
    // 0x800CCABC: nop

    // 0x800CCAC0: slt         $at, $s5, $t6
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800CCAC4: bnel        $at, $zero, L_800CCE70
    if (ctx->r1 != 0) {
        // 0x800CCAC8: lw          $ra, 0x7C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X7C);
            goto L_800CCE70;
    }
    goto skip_12;
    // 0x800CCAC8: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
    skip_12:
    // 0x800CCACC: mtc1        $fp, $f6
    ctx->f6.u32l = ctx->r30;
    // 0x800CCAD0: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800CCAD4: lh          $t7, 0x28($s6)
    ctx->r15 = MEM_H(ctx->r22, 0X28);
    // 0x800CCAD8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CCADC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CCAE0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x800CCAE4: lw          $t8, 0xC8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC8);
    // 0x800CCAE8: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CCAEC: sub.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800CCAF0: bne         $t7, $at, L_800CCBF0
    if (ctx->r15 != ctx->r1) {
        // 0x800CCAF4: sub.s       $f14, $f16, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
            goto L_800CCBF0;
    }
    // 0x800CCAF4: sub.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800CCAF8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800CCAFC: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800CCB00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800CCB04: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CCB08: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CCB0C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800CCB10: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800CCB14: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800CCB18: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800CCB1C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CCB20: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800CCB24: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CCB28: lwc1        $f6, 0x5ED0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5ED0);
    // 0x800CCB2C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800CCB30: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CCB34: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800CCB38: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800CCB3C: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800CCB40: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800CCB44: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x800CCB48: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800CCB4C: div.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800CCB50: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CCB54: mfc1        $s0, $f10
    ctx->r16 = (int32_t)ctx->f10.u32l;
    // 0x800CCB58: nop

    // 0x800CCB5C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800CCB60: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800CCB64: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CCB68: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x800CCB6C: nop

    // 0x800CCB70: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800CCB74: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800CCB78: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CCB7C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800CCB80: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x800CCB84: div.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800CCB88: div.s       $f10, $f8, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f24.fl);
    // 0x800CCB8C: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800CCB90: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CCB94: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CCB98: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x800CCB9C: mfc1        $s3, $f10
    ctx->r19 = (int32_t)ctx->f10.u32l;
    // 0x800CCBA0: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800CCBA4: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800CCBA8: mtc1        $s3, $f4
    ctx->f4.u32l = ctx->r19;
    // 0x800CCBAC: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800CCBB0: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800CCBB4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CCBB8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CCBBC: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800CCBC0: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x800CCBC4: div.s       $f4, $f10, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f24.fl);
    // 0x800CCBC8: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CCBCC: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800CCBD0: nop

    // 0x800CCBD4: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800CCBD8: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800CCBDC: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800CCBE0: jal         0x800CB7D4
    // 0x800CCBE4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    lbCommonDrawSObjBitmap(rdram, ctx);
        goto after_2;
    // 0x800CCBE4: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    after_2:
    // 0x800CCBE8: b           L_800CCE70
    // 0x800CCBEC: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
        goto L_800CCE70;
    // 0x800CCBEC: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_800CCBF0:
    // 0x800CCBF0: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x800CCBF4: lh          $t6, 0x2E($s6)
    ctx->r14 = MEM_H(ctx->r22, 0X2E);
    // 0x800CCBF8: lui         $at, 0x4480
    ctx->r1 = S32(0X4480 << 16);
    // 0x800CCBFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800CCC00: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800CCC04: lw          $t7, 0xC8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC8);
    // 0x800CCC08: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CCC0C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CCC10: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800CCC14: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x800CCC18: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x800CCC1C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800CCC20: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CCC24: mul.s       $f24, $f10, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CCC28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CCC2C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800CCC30: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800CCC34: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800CCC38: mul.s       $f22, $f6, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CCC3C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CCC40: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800CCC44: div.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800CCC48: add.s       $f20, $f16, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800CCC4C: trunc.w.s   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_S(ctx->f20.fl);
    // 0x800CCC50: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x800CCC54: nop

    // 0x800CCC58: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800CCC5C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CCC60: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CCC64: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x800CCC68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CCC6C: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800CCC70: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800CCC74: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800CCC78: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CCC7C: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800CCC80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CCC84: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800CCC88: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CCC8C: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800CCC90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CCC94: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800CCC98: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800CCC9C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CCCA0: mfc1        $s4, $f8
    ctx->r20 = (int32_t)ctx->f8.u32l;
    // 0x800CCCA4: nop

    // 0x800CCCA8: negu        $s4, $s4
    ctx->r20 = SUB32(0, ctx->r20);
    // 0x800CCCAC: sll         $s4, $s4, 16
    ctx->r20 = S32(ctx->r20 << 16);
    // 0x800CCCB0: sra         $s4, $s4, 16
    ctx->r20 = S32(SIGNED(ctx->r20) >> 16);
    // 0x800CCCB4: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800CCCB8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CCCBC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CCCC0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CCCC4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x800CCCC8: mfc1        $s3, $f8
    ctx->r19 = (int32_t)ctx->f8.u32l;
    // 0x800CCCCC: nop

    // 0x800CCCD0: mtc1        $s3, $f10
    ctx->f10.u32l = ctx->r19;
    // 0x800CCCD4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CCCD8: cvt.s.w     $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    ctx->f26.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CCCDC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800CCCE0: mul.s       $f4, $f26, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f14.fl);
    // 0x800CCCE4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800CCCE8: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800CCCEC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CCCF0: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x800CCCF4: nop

    // 0x800CCCF8: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x800CCCFC: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800CCD00: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800CCD04: jal         0x800CB7D4
    // 0x800CCD08: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    lbCommonDrawSObjBitmap(rdram, ctx);
        goto after_3;
    // 0x800CCD08: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_3:
    // 0x800CCD0C: lh          $t9, 0x28($s6)
    ctx->r25 = MEM_H(ctx->r22, 0X28);
    // 0x800CCD10: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x800CCD14: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800CCD18: addiu       $t2, $t9, -0x1
    ctx->r10 = ADD32(ctx->r25, -0X1);
    // 0x800CCD1C: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800CCD20: bnel        $at, $zero, L_800CCDD4
    if (ctx->r1 != 0) {
        // 0x800CCD24: mtc1        $s0, $f6
        ctx->f6.u32l = ctx->r16;
            goto L_800CCDD4;
    }
    goto skip_13;
    // 0x800CCD24: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    skip_13:
    // 0x800CCD28: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
L_800CCD2C:
    // 0x800CCD2C: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x800CCD30: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800CCD34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CCD38: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800CCD3C: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800CCD40: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CCD44: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800CCD48: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800CCD4C: sub.s       $f4, $f20, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f10.fl;
    // 0x800CCD50: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x800CCD54: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800CCD58: add.s       $f10, $f20, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x800CCD5C: mul.s       $f6, $f26, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x800CCD60: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800CCD64: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CCD68: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    // 0x800CCD6C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CCD70: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CCD74: mfc1        $s0, $f4
    ctx->r16 = (int32_t)ctx->f4.u32l;
    // 0x800CCD78: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x800CCD7C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800CCD80: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800CCD84: bgez        $t0, L_800CCD90
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800CCD88: addu        $at, $t0, $zero
        ctx->r1 = ADD32(ctx->r8, 0);
            goto L_800CCD90;
    }
    // 0x800CCD88: addu        $at, $t0, $zero
    ctx->r1 = ADD32(ctx->r8, 0);
    // 0x800CCD8C: addiu       $at, $t0, 0x1F
    ctx->r1 = ADD32(ctx->r8, 0X1F);
L_800CCD90:
    // 0x800CCD90: sra         $t0, $at, 5
    ctx->r8 = S32(SIGNED(ctx->r1) >> 5);
    // 0x800CCD94: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800CCD98: sll         $t5, $t0, 16
    ctx->r13 = S32(ctx->r8 << 16);
    // 0x800CCD9C: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800CCDA0: jal         0x800CB7D4
    // 0x800CCDA4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    lbCommonDrawSObjBitmap(rdram, ctx);
        goto after_4;
    // 0x800CCDA4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_4:
    // 0x800CCDA8: lw          $t7, 0xDC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XDC);
    // 0x800CCDAC: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x800CCDB0: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x800CCDB4: lh          $t8, 0x28($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X28);
    // 0x800CCDB8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CCDBC: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x800CCDC0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800CCDC4: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800CCDC8: bnel        $at, $zero, L_800CCD2C
    if (ctx->r1 != 0) {
        // 0x800CCDCC: mtc1        $s0, $f8
        ctx->f8.u32l = ctx->r16;
            goto L_800CCD2C;
    }
    goto skip_14;
    // 0x800CCDCC: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    skip_14:
    // 0x800CCDD0: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
L_800CCDD4:
    // 0x800CCDD4: lh          $t3, 0xC($s2)
    ctx->r11 = MEM_H(ctx->r18, 0XC);
    // 0x800CCDD8: or          $t1, $s0, $zero
    ctx->r9 = ctx->r16 | 0;
    // 0x800CCDDC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CCDE0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800CCDE4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CCDE8: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800CCDEC: sw          $s4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r20;
    // 0x800CCDF0: sw          $s5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r21;
    // 0x800CCDF4: sub.s       $f10, $f20, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f20.fl - ctx->f8.fl;
    // 0x800CCDF8: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800CCDFC: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x800CCE00: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x800CCE04: mul.s       $f4, $f26, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f26.fl, ctx->f10.fl);
    // 0x800CCE08: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800CCE0C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800CCE10: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    // 0x800CCE14: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CCE18: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CCE1C: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800CCE20: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800CCE24: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800CCE28: addiu       $t0, $t0, 0x10
    ctx->r8 = ADD32(ctx->r8, 0X10);
    // 0x800CCE2C: bgez        $t0, L_800CCE38
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800CCE30: addu        $at, $t0, $zero
        ctx->r1 = ADD32(ctx->r8, 0);
            goto L_800CCE38;
    }
    // 0x800CCE30: addu        $at, $t0, $zero
    ctx->r1 = ADD32(ctx->r8, 0);
    // 0x800CCE34: addiu       $at, $t0, 0x1F
    ctx->r1 = ADD32(ctx->r8, 0X1F);
L_800CCE38:
    // 0x800CCE38: sra         $t0, $at, 5
    ctx->r8 = S32(SIGNED(ctx->r1) >> 5);
    // 0x800CCE3C: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800CCE40: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CCE44: lwc1        $f10, 0x5ED4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5ED4);
    // 0x800CCE48: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
    // 0x800CCE4C: sll         $t5, $t0, 16
    ctx->r13 = S32(ctx->r8 << 16);
    // 0x800CCE50: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CCE54: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800CCE58: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x800CCE5C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CCE60: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800CCE64: jal         0x800CB7D4
    // 0x800CCE68: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    lbCommonDrawSObjBitmap(rdram, ctx);
        goto after_5;
    // 0x800CCE68: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    after_5:
L_800CCE6C:
    // 0x800CCE6C: lw          $ra, 0x7C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X7C);
L_800CCE70:
    // 0x800CCE70: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x800CCE74: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x800CCE78: ldc1        $f24, 0x48($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X48);
    // 0x800CCE7C: ldc1        $f26, 0x50($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X50);
    // 0x800CCE80: lw          $s0, 0x58($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X58);
    // 0x800CCE84: lw          $s1, 0x5C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X5C);
    // 0x800CCE88: lw          $s2, 0x60($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X60);
    // 0x800CCE8C: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x800CCE90: lw          $s4, 0x68($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X68);
    // 0x800CCE94: lw          $s5, 0x6C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X6C);
    // 0x800CCE98: lw          $s6, 0x70($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X70);
    // 0x800CCE9C: lw          $s7, 0x74($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X74);
    // 0x800CCEA0: lw          $fp, 0x78($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X78);
    // 0x800CCEA4: jr          $ra
    // 0x800CCEA8: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x800CCEA8: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void gmRumbleCheckSetEventID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801153B8: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x801153BC: beql        $v0, $zero, L_80115450
    if (ctx->r2 == 0) {
        // 0x801153C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80115450;
    }
    goto skip_0;
    // 0x801153C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801153C4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_801153C8:
    // 0x801153C8: beq         $v1, $zero, L_80115438
    if (ctx->r3 == 0) {
        // 0x801153CC: nop
    
            goto L_80115438;
    }
    // 0x801153CC: nop

    // 0x801153D0: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x801153D4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x801153D8: beql        $t6, $zero, L_80115444
    if (ctx->r14 == 0) {
        // 0x801153DC: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80115444;
    }
    goto skip_1;
    // 0x801153DC: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x801153E0: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x801153E4: bnel        $a1, $t7, L_80115444
    if (ctx->r5 != ctx->r15) {
        // 0x801153E8: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80115444;
    }
    goto skip_2;
    // 0x801153E8: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_2:
    // 0x801153EC: beql        $a2, $zero, L_80115418
    if (ctx->r6 == 0) {
        // 0x801153F0: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_80115418;
    }
    goto skip_3;
    // 0x801153F0: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    skip_3:
    // 0x801153F4: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x801153F8: blez        $v1, L_80115440
    if (SIGNED(ctx->r3) <= 0) {
        // 0x801153FC: slt         $at, $v1, $a2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_80115440;
    }
    // 0x801153FC: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80115400: beql        $at, $zero, L_80115444
    if (ctx->r1 == 0) {
        // 0x80115404: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80115444;
    }
    goto skip_4;
    // 0x80115404: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_4:
    // 0x80115408: sw          $a2, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r6;
    // 0x8011540C: jr          $ra
    // 0x80115410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80115410: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80115414: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
L_80115418:
    // 0x80115418: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8011541C: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x80115420: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x80115424: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80115428: lw          $t0, -0xE00($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XE00);
    // 0x8011542C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80115430: jr          $ra
    // 0x80115434: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    return;
    // 0x80115434: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
L_80115438:
    // 0x80115438: jr          $ra
    // 0x8011543C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8011543C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80115440:
    // 0x80115440: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_80115444:
    // 0x80115444: bnel        $v0, $zero, L_801153C8
    if (ctx->r2 != 0) {
        // 0x80115448: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_801153C8;
    }
    goto skip_5;
    // 0x80115448: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    skip_5:
    // 0x8011544C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80115450:
    // 0x80115450: jr          $ra
    // 0x80115454: nop

    return;
    // 0x80115454: nop

;}
RECOMP_FUNC void ftCommonShieldBreakFlyCommonSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149510: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80149514: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80149518: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014951C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80149520: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80149524: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80149528: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8014952C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80149530: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80149534: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80149538: jal         0x800EDF24
    // 0x8014953C: lw          $a0, 0x8F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8F4);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8014953C: lw          $a0, 0x8F4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8F4);
    after_0:
    // 0x80149540: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80149544: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80149548: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x8014954C: bne         $t7, $at, L_80149578
    if (ctx->r15 != ctx->r1) {
        // 0x80149550: nop
    
            goto L_80149578;
    }
    // 0x80149550: nop

    // 0x80149554: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    // 0x80149558: jal         0x80103A88
    // 0x8014955C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerYoshiEggExplodeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8014955C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80149560: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80149564: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    // 0x80149568: jal         0x801041A0
    // 0x8014956C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerEggBreakMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8014956C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x80149570: b           L_80149584
    // 0x80149574: lw          $a1, 0x7D4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7D4);
        goto L_80149584;
    // 0x80149574: lw          $a1, 0x7D4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7D4);
L_80149578:
    // 0x80149578: jal         0x80101790
    // 0x8014957C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    efManagerShieldBreakMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8014957C: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80149580: lw          $a1, 0x7D4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X7D4);
L_80149584:
    // 0x80149584: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80149588: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014958C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80149590: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80149594: jal         0x800EAA2C
    // 0x80149598: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_4;
    // 0x80149598: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8014959C: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x801495A0: lw          $t0, 0x50E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X50E8);
    // 0x801495A4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x801495A8: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x801495AC: bne         $t1, $at, L_801495EC
    if (ctx->r9 != ctx->r1) {
        // 0x801495B0: nop
    
            goto L_801495EC;
    }
    // 0x801495B0: nop

    // 0x801495B4: lw          $t2, 0x7C8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C8);
    // 0x801495B8: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x801495BC: beq         $t2, $zero, L_801495EC
    if (ctx->r10 == 0) {
        // 0x801495C0: nop
    
            goto L_801495EC;
    }
    // 0x801495C0: nop

    // 0x801495C4: lw          $v0, 0x7D4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7D4);
    // 0x801495C8: lbu         $t3, 0x4AE3($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4AE3);
    // 0x801495CC: bne         $t3, $v0, L_801495EC
    if (ctx->r11 != ctx->r2) {
        // 0x801495D0: nop
    
            goto L_801495EC;
    }
    // 0x801495D0: nop

    // 0x801495D4: lbu         $t4, 0xD($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XD);
    // 0x801495D8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801495DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801495E0: beq         $t4, $v0, L_801495EC
    if (ctx->r12 == ctx->r2) {
        // 0x801495E4: nop
    
            goto L_801495EC;
    }
    // 0x801495E4: nop

    // 0x801495E8: sb          $t5, 0x36AB($at)
    MEM_B(0X36AB, ctx->r1) = ctx->r13;
L_801495EC:
    // 0x801495EC: jal         0x80149488
    // 0x801495F0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    ftCommonShieldBreakFlySetStatus(rdram, ctx);
        goto after_5;
    // 0x801495F0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_5:
    // 0x801495F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801495F8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801495FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80149600: jr          $ra
    // 0x80149604: nop

    return;
    // 0x80149604: nop

;}
RECOMP_FUNC void mnVSModeMakeSubtitle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132FD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132FDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132FE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132FE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132FE8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132FEC: jal         0x80009968
    // 0x80132FF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132FF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132FF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132FF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132FFC: sw          $v0, 0x4960($at)
    MEM_W(0X4960, ctx->r1) = ctx->r2;
    // 0x80133000: jr          $ra
    // 0x80133004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80133004: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80020E64(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020E64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020E68: sltiu       $at, $a0, 0x7801
    ctx->r1 = ctx->r4 < 0X7801 ? 1 : 0;
    // 0x80020E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020E70: bne         $at, $zero, L_80020E80
    if (ctx->r1 != 0) {
        // 0x80020E74: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80020E80;
    }
    // 0x80020E74: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80020E78: b           L_80020E88
    // 0x80020E7C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
        goto L_80020E88;
    // 0x80020E7C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
L_80020E80:
    // 0x80020E80: srl         $a0, $a1, 8
    ctx->r4 = S32(U32(ctx->r5) >> 8);
    // 0x80020E84: andi        $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 & 0XFF;
L_80020E88:
    // 0x80020E88: jal         0x80026070
    // 0x80020E8C: nop

    func_80026070_26C70(rdram, ctx);
        goto after_0;
    // 0x80020E8C: nop

    after_0:
    // 0x80020E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020E98: jr          $ra
    // 0x80020E9C: nop

    return;
    // 0x80020E9C: nop

;}
RECOMP_FUNC void gmCameraOrthoLookAtFuncMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E00C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010E010: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010E014: lw          $t6, 0x38($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X38);
    // 0x8010E018: lw          $t8, 0x3C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3C);
    // 0x8010E01C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8010E020: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x8010E024: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x8010E028: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8010E02C: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x8010E030: bgez        $t6, L_8010E040
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8010E034: sra         $t7, $t6, 1
        ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8010E040;
    }
    // 0x8010E034: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8010E038: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8010E03C: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_8010E040:
    // 0x8010E040: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8010E044: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8010E048: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010E04C: bgez        $t8, L_8010E05C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8010E050: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_8010E05C;
    }
    // 0x8010E050: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8010E054: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x8010E058: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_8010E05C:
    // 0x8010E05C: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8010E060: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8010E064: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8010E068: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010E06C: lui         $at, 0x4648
    ctx->r1 = S32(0X4648 << 16);
    // 0x8010E070: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8010E074: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010E078: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010E07C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8010E080: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x8010E084: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8010E088: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8010E08C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010E090: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8010E094: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    // 0x8010E098: swc1        $f18, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f18.u32l;
    // 0x8010E09C: jal         0x8001B050
    // 0x8010E0A0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    syMatrixOrthoF(rdram, ctx);
        goto after_0;
    // 0x8010E0A0: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8010E0A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010E0A8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010E0AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010E0B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8010E0B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010E0B8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8010E0BC: lui         $a3, 0x447A
    ctx->r7 = S32(0X447A << 16);
    // 0x8010E0C0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8010E0C4: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8010E0C8: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x8010E0CC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x8010E0D0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8010E0D4: jal         0x8001A0F0
    // 0x8010E0D8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    syMatrixLookAtF(rdram, ctx);
        goto after_1;
    // 0x8010E0D8: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8010E0DC: addiu       $a1, $sp, 0x78
    ctx->r5 = ADD32(ctx->r29, 0X78);
    // 0x8010E0E0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8010E0E4: jal         0x80034980
    // 0x8010E0E8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    guMtxCatF(rdram, ctx);
        goto after_2;
    // 0x8010E0E8: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_2:
    // 0x8010E0EC: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x8010E0F0: jal         0x80019C70
    // 0x8010E0F4: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    syMatrixF2L(rdram, ctx);
        goto after_3;
    // 0x8010E0F4: lw          $a1, 0xB8($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB8);
    after_3:
    // 0x8010E0F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8010E0FC: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x8010E100: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010E104: jr          $ra
    // 0x8010E108: nop

    return;
    // 0x8010E108: nop

;}
RECOMP_FUNC void ftCommonLightGetProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145ED8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80145EDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145EE0: jal         0x800DDDA8
    // 0x80145EE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80145EE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80145EE8: bnel        $v0, $zero, L_80145F04
    if (ctx->r2 != 0) {
        // 0x80145EEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80145F04;
    }
    goto skip_0;
    // 0x80145EEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80145EF0: jal         0x80145BE4
    // 0x80145EF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonLightGetProcDamage(rdram, ctx);
        goto after_1;
    // 0x80145EF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80145EF8: jal         0x8013F9E0
    // 0x80145EFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonFallSetStatus(rdram, ctx);
        goto after_2;
    // 0x80145EFC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80145F00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145F04:
    // 0x80145F04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80145F08: jr          $ra
    // 0x80145F0C: nop

    return;
    // 0x80145F0C: nop

;}
RECOMP_FUNC void efDisplayCLDProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCCC0: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800FCCC4: addiu       $t0, $t0, 0x65B0
    ctx->r8 = ADD32(ctx->r8, 0X65B0);
    // 0x800FCCC8: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x800FCCCC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800FCCD0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800FCCD4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800FCCD8: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x800FCCDC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800FCCE0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800FCCE4: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x800FCCE8: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x800FCCEC: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x800FCCF0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800FCCF4: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800FCCF8: ori         $t1, $t1, 0x4340
    ctx->r9 = ctx->r9 | 0X4340;
    // 0x800FCCFC: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x800FCD00: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800FCD04: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800FCD08: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x800FCD0C: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x800FCD10: ori         $t3, $t3, 0x1E01
    ctx->r11 = ctx->r11 | 0X1E01;
    // 0x800FCD14: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800FCD18: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x800FCD1C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800FCD20: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800FCD24: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800FCD28: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x800FCD2C: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x800FCD30: lui         $t6, 0xF900
    ctx->r14 = S32(0XF900 << 16);
    // 0x800FCD34: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800FCD38: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
    // 0x800FCD3C: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800FCD40: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800FCD44: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x800FCD48: lui         $t9, 0xD9FF
    ctx->r25 = S32(0XD9FF << 16);
    // 0x800FCD4C: ori         $t9, $t9, 0xFFFE
    ctx->r25 = ctx->r25 | 0XFFFE;
    // 0x800FCD50: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800FCD54: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x800FCD58: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800FCD5C: jr          $ra
    // 0x800FCD60: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x800FCD60: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
;}
RECOMP_FUNC void ftParamSetTimedHitStatusIntangible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA94C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA950: lw          $t6, 0x5A8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5A8);
    // 0x800EA954: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800EA958: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800EA95C: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800EA960: beq         $at, $zero, L_800EA96C
    if (ctx->r1 == 0) {
        // 0x800EA964: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800EA96C;
    }
    // 0x800EA964: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800EA968: sw          $a1, 0x5A8($a0)
    MEM_W(0X5A8, ctx->r4) = ctx->r5;
L_800EA96C:
    // 0x800EA96C: sw          $t7, 0x5AC($a3)
    MEM_W(0X5AC, ctx->r7) = ctx->r15;
    // 0x800EA970: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x800EA974: jal         0x800E9814
    // 0x800EA978: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x800EA978: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_0:
    // 0x800EA97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA984: jr          $ra
    // 0x800EA988: nop

    return;
    // 0x800EA988: nop

;}
RECOMP_FUNC void dbUiNodeTypeRegisterHandlers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381DC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80381DCC: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80381DD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80381DD4: addiu       $a1, $a1, 0x6164
    ctx->r5 = ADD32(ctx->r5, 0X6164);
    // 0x80381DD8: lui         $a0, 0x4657
    ctx->r4 = S32(0X4657 << 16);
    // 0x80381DDC: ori         $a0, $a0, 0x494E
    ctx->r4 = ctx->r4 | 0X494E;
    // 0x80381DE0: jal         0x80381B70
    // 0x80381DE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_0;
    // 0x80381DE4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80381DE8: lui         $a0, 0x4648
    ctx->r4 = S32(0X4648 << 16);
    // 0x80381DEC: ori         $a0, $a0, 0x574E
    ctx->r4 = ctx->r4 | 0X574E;
    // 0x80381DF0: jal         0x80381B70
    // 0x80381DF4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_1;
    // 0x80381DF4: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80381DF8: lui         $a0, 0x4646
    ctx->r4 = S32(0X4646 << 16);
    // 0x80381DFC: ori         $a0, $a0, 0x574E
    ctx->r4 = ctx->r4 | 0X574E;
    // 0x80381E00: jal         0x80381B70
    // 0x80381E04: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_2;
    // 0x80381E04: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80381E08: lui         $a0, 0x4646
    ctx->r4 = S32(0X4646 << 16);
    // 0x80381E0C: ori         $a0, $a0, 0x4857
    ctx->r4 = ctx->r4 | 0X4857;
    // 0x80381E10: jal         0x80381B70
    // 0x80381E14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_3;
    // 0x80381E14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x80381E18: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x80381E1C: addiu       $a1, $a1, 0x6848
    ctx->r5 = ADD32(ctx->r5, 0X6848);
    // 0x80381E20: lui         $a0, 0x4257
    ctx->r4 = S32(0X4257 << 16);
    // 0x80381E24: ori         $a0, $a0, 0x494E
    ctx->r4 = ctx->r4 | 0X494E;
    // 0x80381E28: jal         0x80381B70
    // 0x80381E2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_4;
    // 0x80381E2C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_4:
    // 0x80381E30: lui         $a0, 0x4248
    ctx->r4 = S32(0X4248 << 16);
    // 0x80381E34: ori         $a0, $a0, 0x574E
    ctx->r4 = ctx->r4 | 0X574E;
    // 0x80381E38: jal         0x80381B70
    // 0x80381E3C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_5;
    // 0x80381E3C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_5:
    // 0x80381E40: lui         $a0, 0x4246
    ctx->r4 = S32(0X4246 << 16);
    // 0x80381E44: ori         $a0, $a0, 0x574E
    ctx->r4 = ctx->r4 | 0X574E;
    // 0x80381E48: jal         0x80381B70
    // 0x80381E4C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_6;
    // 0x80381E4C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_6:
    // 0x80381E50: lui         $a0, 0x4246
    ctx->r4 = S32(0X4246 << 16);
    // 0x80381E54: ori         $a0, $a0, 0x4857
    ctx->r4 = ctx->r4 | 0X4857;
    // 0x80381E58: jal         0x80381B70
    // 0x80381E5C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_7;
    // 0x80381E5C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_7:
    // 0x80381E60: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80381E64: addiu       $a1, $a1, -0x39A0
    ctx->r5 = ADD32(ctx->r5, -0X39A0);
    // 0x80381E68: lui         $a0, 0x5342
    ctx->r4 = S32(0X5342 << 16);
    // 0x80381E6C: ori         $a0, $a0, 0x544E
    ctx->r4 = ctx->r4 | 0X544E;
    // 0x80381E70: jal         0x80381B70
    // 0x80381E74: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_8;
    // 0x80381E74: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_8:
    // 0x80381E78: lui         $a0, 0x5354
    ctx->r4 = S32(0X5354 << 16);
    // 0x80381E7C: ori         $a0, $a0, 0x4742
    ctx->r4 = ctx->r4 | 0X4742;
    // 0x80381E80: jal         0x80381B70
    // 0x80381E84: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_9;
    // 0x80381E84: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_9:
    // 0x80381E88: lui         $a0, 0x534F
    ctx->r4 = S32(0X534F << 16);
    // 0x80381E8C: ori         $a0, $a0, 0x5042
    ctx->r4 = ctx->r4 | 0X5042;
    // 0x80381E90: jal         0x80381B70
    // 0x80381E94: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_10;
    // 0x80381E94: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_10:
    // 0x80381E98: lui         $a0, 0x5354
    ctx->r4 = S32(0X5354 << 16);
    // 0x80381E9C: ori         $a0, $a0, 0x4342
    ctx->r4 = ctx->r4 | 0X4342;
    // 0x80381EA0: jal         0x80381B70
    // 0x80381EA4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_11;
    // 0x80381EA4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_11:
    // 0x80381EA8: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80381EAC: addiu       $a1, $a1, -0x17D0
    ctx->r5 = ADD32(ctx->r5, -0X17D0);
    // 0x80381EB0: lui         $a0, 0x5354
    ctx->r4 = S32(0X5354 << 16);
    // 0x80381EB4: ori         $a0, $a0, 0x424E
    ctx->r4 = ctx->r4 | 0X424E;
    // 0x80381EB8: jal         0x80381B70
    // 0x80381EBC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_12;
    // 0x80381EBC: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_12:
    // 0x80381EC0: lui         $a0, 0x5354
    ctx->r4 = S32(0X5354 << 16);
    // 0x80381EC4: ori         $a0, $a0, 0x5442
    ctx->r4 = ctx->r4 | 0X5442;
    // 0x80381EC8: jal         0x80381B70
    // 0x80381ECC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_13;
    // 0x80381ECC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_13:
    // 0x80381ED0: lui         $a0, 0x5354
    ctx->r4 = S32(0X5354 << 16);
    // 0x80381ED4: ori         $a0, $a0, 0x4F42
    ctx->r4 = ctx->r4 | 0X4F42;
    // 0x80381ED8: jal         0x80381B70
    // 0x80381EDC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_14;
    // 0x80381EDC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_14:
    // 0x80381EE0: lui         $a0, 0x5354
    ctx->r4 = S32(0X5354 << 16);
    // 0x80381EE4: ori         $a0, $a0, 0x5443
    ctx->r4 = ctx->r4 | 0X5443;
    // 0x80381EE8: jal         0x80381B70
    // 0x80381EEC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_15;
    // 0x80381EEC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_15:
    // 0x80381EF0: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80381EF4: addiu       $a1, $a1, -0x35A0
    ctx->r5 = ADD32(ctx->r5, -0X35A0);
    // 0x80381EF8: lui         $a0, 0x4242
    ctx->r4 = S32(0X4242 << 16);
    // 0x80381EFC: ori         $a0, $a0, 0x544E
    ctx->r4 = ctx->r4 | 0X544E;
    // 0x80381F00: jal         0x80381B70
    // 0x80381F04: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_16;
    // 0x80381F04: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_16:
    // 0x80381F08: lui         $a0, 0x4254
    ctx->r4 = S32(0X4254 << 16);
    // 0x80381F0C: ori         $a0, $a0, 0x4742
    ctx->r4 = ctx->r4 | 0X4742;
    // 0x80381F10: jal         0x80381B70
    // 0x80381F14: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_17;
    // 0x80381F14: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_17:
    // 0x80381F18: lui         $a0, 0x424F
    ctx->r4 = S32(0X424F << 16);
    // 0x80381F1C: ori         $a0, $a0, 0x5042
    ctx->r4 = ctx->r4 | 0X5042;
    // 0x80381F20: jal         0x80381B70
    // 0x80381F24: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_18;
    // 0x80381F24: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_18:
    // 0x80381F28: lui         $a0, 0x424F
    ctx->r4 = S32(0X424F << 16);
    // 0x80381F2C: ori         $a0, $a0, 0x5054
    ctx->r4 = ctx->r4 | 0X5054;
    // 0x80381F30: jal         0x80381B70
    // 0x80381F34: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_19;
    // 0x80381F34: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_19:
    // 0x80381F38: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80381F3C: addiu       $a1, $a1, -0x1200
    ctx->r5 = ADD32(ctx->r5, -0X1200);
    // 0x80381F40: lui         $a0, 0x4254
    ctx->r4 = S32(0X4254 << 16);
    // 0x80381F44: ori         $a0, $a0, 0x5842
    ctx->r4 = ctx->r4 | 0X5842;
    // 0x80381F48: jal         0x80381B70
    // 0x80381F4C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_20;
    // 0x80381F4C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_20:
    // 0x80381F50: lui         $a0, 0x4254
    ctx->r4 = S32(0X4254 << 16);
    // 0x80381F54: ori         $a0, $a0, 0x5442
    ctx->r4 = ctx->r4 | 0X5442;
    // 0x80381F58: jal         0x80381B70
    // 0x80381F5C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_21;
    // 0x80381F5C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_21:
    // 0x80381F60: lui         $a0, 0x4254
    ctx->r4 = S32(0X4254 << 16);
    // 0x80381F64: ori         $a0, $a0, 0x4F42
    ctx->r4 = ctx->r4 | 0X4F42;
    // 0x80381F68: jal         0x80381B70
    // 0x80381F6C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_22;
    // 0x80381F6C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_22:
    // 0x80381F70: lui         $a0, 0x4254
    ctx->r4 = S32(0X4254 << 16);
    // 0x80381F74: ori         $a0, $a0, 0x5443
    ctx->r4 = ctx->r4 | 0X5443;
    // 0x80381F78: jal         0x80381B70
    // 0x80381F7C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_23;
    // 0x80381F7C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_23:
    // 0x80381F80: lui         $a0, 0x504F
    ctx->r4 = S32(0X504F << 16);
    // 0x80381F84: ori         $a0, $a0, 0x504D
    ctx->r4 = ctx->r4 | 0X504D;
    // 0x80381F88: jal         0x80381B70
    // 0x80381F8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_24;
    // 0x80381F8C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_24:
    // 0x80381F90: lui         $a0, 0x5350
    ctx->r4 = S32(0X5350 << 16);
    // 0x80381F94: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80381F98: addiu       $a1, $a1, 0x2710
    ctx->r5 = ADD32(ctx->r5, 0X2710);
    // 0x80381F9C: jal         0x80381B70
    // 0x80381FA0: ori         $a0, $a0, 0x4F50
    ctx->r4 = ctx->r4 | 0X4F50;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_25;
    // 0x80381FA0: ori         $a0, $a0, 0x4F50
    ctx->r4 = ctx->r4 | 0X4F50;
    after_25:
    // 0x80381FA4: lui         $a0, 0x4250
    ctx->r4 = S32(0X4250 << 16);
    // 0x80381FA8: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80381FAC: addiu       $a1, $a1, 0x2AE0
    ctx->r5 = ADD32(ctx->r5, 0X2AE0);
    // 0x80381FB0: jal         0x80381B70
    // 0x80381FB4: ori         $a0, $a0, 0x4F50
    ctx->r4 = ctx->r4 | 0X4F50;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_26;
    // 0x80381FB4: ori         $a0, $a0, 0x4F50
    ctx->r4 = ctx->r4 | 0X4F50;
    after_26:
    // 0x80381FB8: lui         $a0, 0x5356
    ctx->r4 = S32(0X5356 << 16);
    // 0x80381FBC: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80381FC0: addiu       $a1, $a1, -0x440
    ctx->r5 = ADD32(ctx->r5, -0X440);
    // 0x80381FC4: jal         0x80381B70
    // 0x80381FC8: ori         $a0, $a0, 0x4C4D
    ctx->r4 = ctx->r4 | 0X4C4D;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_27;
    // 0x80381FC8: ori         $a0, $a0, 0x4C4D
    ctx->r4 = ctx->r4 | 0X4C4D;
    after_27:
    // 0x80381FCC: lui         $a0, 0x4256
    ctx->r4 = S32(0X4256 << 16);
    // 0x80381FD0: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80381FD4: addiu       $a1, $a1, 0xEC0
    ctx->r5 = ADD32(ctx->r5, 0XEC0);
    // 0x80381FD8: jal         0x80381B70
    // 0x80381FDC: ori         $a0, $a0, 0x4C4D
    ctx->r4 = ctx->r4 | 0X4C4D;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_28;
    // 0x80381FDC: ori         $a0, $a0, 0x4C4D
    ctx->r4 = ctx->r4 | 0X4C4D;
    after_28:
    // 0x80381FE0: lui         $a0, 0x4243
    ctx->r4 = S32(0X4243 << 16);
    // 0x80381FE4: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80381FE8: addiu       $a1, $a1, 0x2490
    ctx->r5 = ADD32(ctx->r5, 0X2490);
    // 0x80381FEC: jal         0x80381B70
    // 0x80381FF0: ori         $a0, $a0, 0x4150
    ctx->r4 = ctx->r4 | 0X4150;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_29;
    // 0x80381FF0: ori         $a0, $a0, 0x4150
    ctx->r4 = ctx->r4 | 0X4150;
    after_29:
    // 0x80381FF4: lui         $a0, 0x5343
    ctx->r4 = S32(0X5343 << 16);
    // 0x80381FF8: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80381FFC: addiu       $a1, $a1, 0x5640
    ctx->r5 = ADD32(ctx->r5, 0X5640);
    // 0x80382000: jal         0x80381B70
    // 0x80382004: ori         $a0, $a0, 0x4150
    ctx->r4 = ctx->r4 | 0X4150;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_30;
    // 0x80382004: ori         $a0, $a0, 0x4150
    ctx->r4 = ctx->r4 | 0X4150;
    after_30:
    // 0x80382008: lui         $a0, 0x4341
    ctx->r4 = S32(0X4341 << 16);
    // 0x8038200C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80382010: addiu       $a1, $a1, 0x2D90
    ctx->r5 = ADD32(ctx->r5, 0X2D90);
    // 0x80382014: jal         0x80381B70
    // 0x80382018: ori         $a0, $a0, 0x4D20
    ctx->r4 = ctx->r4 | 0X4D20;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_31;
    // 0x80382018: ori         $a0, $a0, 0x4D20
    ctx->r4 = ctx->r4 | 0X4D20;
    after_31:
    // 0x8038201C: lui         $a0, 0x534C
    ctx->r4 = S32(0X534C << 16);
    // 0x80382020: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80382024: addiu       $a1, $a1, 0x40C0
    ctx->r5 = ADD32(ctx->r5, 0X40C0);
    // 0x80382028: jal         0x80381B70
    // 0x8038202C: ori         $a0, $a0, 0x4544
    ctx->r4 = ctx->r4 | 0X4544;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_32;
    // 0x8038202C: ori         $a0, $a0, 0x4544
    ctx->r4 = ctx->r4 | 0X4544;
    after_32:
    // 0x80382030: lui         $a0, 0x424C
    ctx->r4 = S32(0X424C << 16);
    // 0x80382034: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80382038: addiu       $a1, $a1, 0x4460
    ctx->r5 = ADD32(ctx->r5, 0X4460);
    // 0x8038203C: jal         0x80381B70
    // 0x80382040: ori         $a0, $a0, 0x4544
    ctx->r4 = ctx->r4 | 0X4544;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_33;
    // 0x80382040: ori         $a0, $a0, 0x4544
    ctx->r4 = ctx->r4 | 0X4544;
    after_33:
    // 0x80382044: lui         $a0, 0x534C
    ctx->r4 = S32(0X534C << 16);
    // 0x80382048: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x8038204C: addiu       $a1, $a1, 0x5180
    ctx->r5 = ADD32(ctx->r5, 0X5180);
    // 0x80382050: jal         0x80381B70
    // 0x80382054: ori         $a0, $a0, 0x5354
    ctx->r4 = ctx->r4 | 0X5354;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_34;
    // 0x80382054: ori         $a0, $a0, 0x5354
    ctx->r4 = ctx->r4 | 0X5354;
    after_34:
    // 0x80382058: lui         $a0, 0x424C
    ctx->r4 = S32(0X424C << 16);
    // 0x8038205C: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80382060: addiu       $a1, $a1, 0x5460
    ctx->r5 = ADD32(ctx->r5, 0X5460);
    // 0x80382064: jal         0x80381B70
    // 0x80382068: ori         $a0, $a0, 0x5354
    ctx->r4 = ctx->r4 | 0X5354;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_35;
    // 0x80382068: ori         $a0, $a0, 0x5354
    ctx->r4 = ctx->r4 | 0X5354;
    after_35:
    // 0x8038206C: lui         $a0, 0x5342
    ctx->r4 = S32(0X5342 << 16);
    // 0x80382070: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80382074: addiu       $a1, $a1, 0x5A50
    ctx->r5 = ADD32(ctx->r5, 0X5A50);
    // 0x80382078: jal         0x80381B70
    // 0x8038207C: ori         $a0, $a0, 0x5050
    ctx->r4 = ctx->r4 | 0X5050;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_36;
    // 0x8038207C: ori         $a0, $a0, 0x5050
    ctx->r4 = ctx->r4 | 0X5050;
    after_36:
    // 0x80382080: lui         $a0, 0x5342
    ctx->r4 = S32(0X5342 << 16);
    // 0x80382084: lui         $a1, 0x8038
    ctx->r5 = S32(0X8038 << 16);
    // 0x80382088: addiu       $a1, $a1, 0x79A0
    ctx->r5 = ADD32(ctx->r5, 0X79A0);
    // 0x8038208C: jal         0x80381B70
    // 0x80382090: ori         $a0, $a0, 0x4950
    ctx->r4 = ctx->r4 | 0X4950;
    dbUiNodeTypeRegisterHandler(rdram, ctx);
        goto after_37;
    // 0x80382090: ori         $a0, $a0, 0x4950
    ctx->r4 = ctx->r4 | 0X4950;
    after_37:
    // 0x80382094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80382098: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8038209C: jr          $ra
    // 0x803820A0: nop

    return;
    // 0x803820A0: nop

;}
RECOMP_FUNC void lbCommonCheckAdjustSim2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7C98: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7C9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C7CA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C7CA4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C7CA8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C7CAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C7CB0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C7CB4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800C7CB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800C7CBC: jal         0x800C7C0C
    // 0x800C7CC0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    lbCommonSim2D(rdram, ctx);
        goto after_0;
    // 0x800C7CC0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C7CC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C7CC8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7CCC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800C7CD0: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x800C7CD4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800C7CD8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800C7CDC: bc1fl       L_800C7DA0
    if (!c1cs) {
        // 0x800C7CE0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C7DA0;
    }
    goto skip_0;
    // 0x800C7CE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800C7CE4: lwc1        $f8, 0x5E70($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E70);
    // 0x800C7CE8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800C7CEC: swc1        $f2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f2.u32l;
    // 0x800C7CF0: jal         0x80035CD0
    // 0x800C7CF4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800C7CF4: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x800C7CF8: lwc1        $f2, 0x24($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800C7CFC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7D00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C7D04: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800C7D08: nop

    // 0x800C7D0C: bc1fl       L_800C7DA0
    if (!c1cs) {
        // 0x800C7D10: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800C7DA0;
    }
    goto skip_1;
    // 0x800C7D10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800C7D14: lwc1        $f10, 0x0($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C7D18: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800C7D1C: lwc1        $f4, 0x4($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800C7D20: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800C7D24: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C7D28: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800C7D2C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C7D30: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800C7D34: sub.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800C7D38: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x800C7D3C: nop

    // 0x800C7D40: bc1fl       L_800C7D5C
    if (!c1cs) {
        // 0x800C7D44: mtc1        $at, $f12
        ctx->f12.u32l = ctx->r1;
            goto L_800C7D5C;
    }
    goto skip_2;
    // 0x800C7D44: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    skip_2:
    // 0x800C7D48: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x800C7D4C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800C7D50: b           L_800C7D64
    // 0x800C7D54: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
        goto L_800C7D64;
    // 0x800C7D54: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x800C7D58: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
L_800C7D5C:
    // 0x800C7D5C: nop

    // 0x800C7D60: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
L_800C7D64:
    // 0x800C7D64: jal         0x800C7A84
    // 0x800C7D68: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    lbCommonMag2D(rdram, ctx);
        goto after_2;
    // 0x800C7D68: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_2:
    // 0x800C7D6C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800C7D70: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7D74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C7D78: mul.s       $f2, $f0, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800C7D7C: lwc1        $f16, 0x4($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800C7D80: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x800C7D84: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800C7D88: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
    // 0x800C7D8C: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800C7D90: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800C7D94: b           L_800C7DA0
    // 0x800C7D98: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
        goto L_800C7DA0;
    // 0x800C7D98: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x800C7D9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C7DA0:
    // 0x800C7DA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7DA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C7DA8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7DAC: jr          $ra
    // 0x800C7DB0: nop

    return;
    // 0x800C7DB0: nop

;}
RECOMP_FUNC void mnDataMakeVSRecord(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E90: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131E94: lw          $t6, 0x3088($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3088);
    // 0x80131E98: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131E9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131EA0: beq         $t6, $zero, L_80131EBC
    if (ctx->r14 == 0) {
        // 0x80131EA4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80131EBC;
    }
    // 0x80131EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131EA8: addiu       $t7, $zero, 0x65
    ctx->r15 = ADD32(0, 0X65);
    // 0x80131EAC: addiu       $t8, $zero, 0x59
    ctx->r24 = ADD32(0, 0X59);
    // 0x80131EB0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80131EB4: b           L_80131ECC
    // 0x80131EB8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_80131ECC;
    // 0x80131EB8: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_80131EBC:
    // 0x80131EBC: addiu       $t9, $zero, 0x51
    ctx->r25 = ADD32(0, 0X51);
    // 0x80131EC0: addiu       $t0, $zero, 0x7E
    ctx->r8 = ADD32(0, 0X7E);
    // 0x80131EC4: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80131EC8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_80131ECC:
    // 0x80131ECC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131ED0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131ED4: jal         0x80009968
    // 0x80131ED8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131ED8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131EDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131EE0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131EE4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80131EE8: sw          $v0, 0x3064($at)
    MEM_W(0X3064, ctx->r1) = ctx->r2;
    // 0x80131EEC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80131EF0: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80131EF4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131EF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EFC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131F00: jal         0x80009DF4
    // 0x80131F04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131F04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131F08: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80131F0C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80131F10: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131F14: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80131F18: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80131F1C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    // 0x80131F20: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80131F24: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80131F28: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80131F2C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80131F30: jal         0x80131C24
    // 0x80131F34: nop

    mnDataMakeOptionTab(rdram, ctx);
        goto after_2;
    // 0x80131F34: nop

    after_2:
    // 0x80131F38: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131F3C: lw          $a1, 0x3078($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3078);
    // 0x80131F40: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131F44: xori        $a1, $a1, 0x1
    ctx->r5 = ctx->r5 ^ 0X1;
    // 0x80131F48: jal         0x80131B4C
    // 0x80131F4C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnDataSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80131F4C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x80131F50: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131F54: lw          $t4, 0x3164($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3164);
    // 0x80131F58: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80131F5C: addiu       $t5, $t5, 0x1900
    ctx->r13 = ADD32(ctx->r13, 0X1900);
    // 0x80131F60: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80131F64: jal         0x800CCFDC
    // 0x80131F68: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131F68: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_4:
    // 0x80131F6C: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80131F70: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131F74: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131F78: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131F7C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131F80: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80131F84: addiu       $t1, $t0, 0x1B
    ctx->r9 = ADD32(ctx->r8, 0X1B);
    // 0x80131F88: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80131F8C: nop

    // 0x80131F90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80131F94: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    // 0x80131F98: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80131F9C: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80131FA0: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80131FA4: addiu       $t3, $t2, 0x4
    ctx->r11 = ADD32(ctx->r10, 0X4);
    // 0x80131FA8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80131FAC: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80131FB0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80131FB4: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80131FB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131FBC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80131FC0: jr          $ra
    // 0x80131FC4: nop

    return;
    // 0x80131FC4: nop

;}
RECOMP_FUNC void efManagerLinkSpinAttackMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103378: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010337C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80103380: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103384: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103388: addiu       $a0, $a0, -0x19D4
    ctx->r4 = ADD32(ctx->r4, -0X19D4);
    // 0x8010338C: jal         0x800FDAFC
    // 0x80103390: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80103390: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80103394: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80103398: bne         $v0, $zero, L_801033A8
    if (ctx->r2 != 0) {
        // 0x8010339C: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_801033A8;
    }
    // 0x8010339C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x801033A0: b           L_80103408
    // 0x801033A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103408;
    // 0x801033A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801033A8:
    // 0x801033A8: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x801033AC: lui         $t6, 0x800F
    ctx->r14 = S32(0X800F << 16);
    // 0x801033B0: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x801033B4: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x801033B8: lw          $v1, 0x84($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X84);
    // 0x801033BC: addiu       $t6, $t6, -0x6374
    ctx->r14 = ADD32(ctx->r14, -0X6374);
    // 0x801033C0: addiu       $t7, $t7, -0x633C
    ctx->r15 = ADD32(ctx->r15, -0X633C);
    // 0x801033C4: sw          $t6, 0xA04($v1)
    MEM_W(0XA04, ctx->r3) = ctx->r14;
    // 0x801033C8: sw          $t7, 0xA08($v1)
    MEM_W(0XA08, ctx->r3) = ctx->r15;
    // 0x801033CC: lw          $a1, 0x74($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X74);
    // 0x801033D0: lw          $t8, 0x8E8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8E8);
    // 0x801033D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801033D8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x801033DC: sw          $t8, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->r24;
    // 0x801033E0: lw          $t9, 0x84($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X84);
    // 0x801033E4: lw          $t0, 0x44($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X44);
    // 0x801033E8: bne         $t0, $at, L_801033FC
    if (ctx->r8 != ctx->r1) {
        // 0x801033EC: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801033FC;
    }
    // 0x801033EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801033F0: lwc1        $f4, 0xA14($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XA14);
    // 0x801033F4: b           L_80103408
    // 0x801033F8: swc1        $f4, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f4.u32l;
        goto L_80103408;
    // 0x801033F8: swc1        $f4, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f4.u32l;
L_801033FC:
    // 0x801033FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80103400: lwc1        $f6, 0xA18($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XA18);
    // 0x80103404: swc1        $f6, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->f6.u32l;
L_80103408:
    // 0x80103408: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010340C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103410: jr          $ra
    // 0x80103414: nop

    return;
    // 0x80103414: nop

;}
RECOMP_FUNC void ftCommonGetSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145FD8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80145FDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80145FE0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80145FE4: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x80145FE8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80145FEC: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x80145FF0: lbu         $t6, 0x2CE($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2CE);
    // 0x80145FF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80145FF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80145FFC: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80146000: bne         $t7, $zero, L_80146010
    if (ctx->r15 != 0) {
        // 0x80146004: nop
    
            goto L_80146010;
    }
    // 0x80146004: nop

    // 0x80146008: b           L_80146010
    // 0x8014600C: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
        goto L_80146010;
    // 0x8014600C: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
L_80146010:
    // 0x80146010: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80146014: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80146018: jal         0x800E6F24
    // 0x8014601C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014601C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80146020: jal         0x800E0830
    // 0x80146024: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80146024: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80146028: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8014602C: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80146030: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80146034: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x80146038: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8014603C: addiu       $t9, $t9, 0x5D28
    ctx->r25 = ADD32(ctx->r25, 0X5D28);
    // 0x80146040: bne         $t8, $at, L_80146050
    if (ctx->r24 != ctx->r1) {
        // 0x80146044: addiu       $t0, $t0, 0x5BE4
        ctx->r8 = ADD32(ctx->r8, 0X5BE4);
            goto L_80146050;
    }
    // 0x80146044: addiu       $t0, $t0, 0x5BE4
    ctx->r8 = ADD32(ctx->r8, 0X5BE4);
    // 0x80146048: b           L_80146054
    // 0x8014604C: sw          $t9, 0x9EC($v1)
    MEM_W(0X9EC, ctx->r3) = ctx->r25;
        goto L_80146054;
    // 0x8014604C: sw          $t9, 0x9EC($v1)
    MEM_W(0X9EC, ctx->r3) = ctx->r25;
L_80146050:
    // 0x80146050: sw          $t0, 0x9EC($v1)
    MEM_W(0X9EC, ctx->r3) = ctx->r8;
L_80146054:
    // 0x80146054: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80146058: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014605C: jr          $ra
    // 0x80146060: nop

    return;
    // 0x80146060: nop

;}
RECOMP_FUNC void syMatrixModLookAtF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001A3F0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001A3F4: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8001A3F8: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001A3FC: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001A400: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x8001A404: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001A408: lwc1        $f8, 0x74($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8001A40C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8001A410: sub.s       $f22, $f4, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A414: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8001A418: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001A41C: sub.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001A420: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001A424: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001A428: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8001A42C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8001A430: mul.s       $f10, $f24, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x8001A434: sub.s       $f26, $f4, $f6
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f26.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A438: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001A43C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001A440: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001A444: mul.s       $f6, $f26, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x8001A448: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001A44C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8001A450: swc1        $f26, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f26.u32l;
    // 0x8001A454: swc1        $f24, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f24.u32l;
    // 0x8001A458: swc1        $f22, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f22.u32l;
    // 0x8001A45C: jal         0x80033510
    // 0x8001A460: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001A460: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8001A464: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8001A468: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001A46C: lwc1        $f22, 0x50($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001A470: lwc1        $f24, 0x54($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001A474: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001A478: lwc1        $f26, 0x58($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001A47C: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8001A480: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001A484: lwc1        $f20, 0x80($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001A488: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8001A48C: nop

    // 0x8001A490: mul.s       $f24, $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x8001A494: nop

    // 0x8001A498: mul.s       $f26, $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f2.fl);
    // 0x8001A49C: swc1        $f22, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f22.u32l;
    // 0x8001A4A0: swc1        $f24, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f24.u32l;
    // 0x8001A4A4: mul.s       $f10, $f16, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f26.fl);
    // 0x8001A4A8: swc1        $f26, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f26.u32l;
    // 0x8001A4AC: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x8001A4B0: nop

    // 0x8001A4B4: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8001A4B8: nop

    // 0x8001A4BC: mul.s       $f8, $f20, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f26.fl);
    // 0x8001A4C0: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8001A4C4: mul.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f24.fl);
    // 0x8001A4C8: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x8001A4CC: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8001A4D0: mul.s       $f6, $f16, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x8001A4D4: swc1        $f10, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f10.u32l;
    // 0x8001A4D8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001A4DC: mul.s       $f4, $f10, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f10.fl);
    // 0x8001A4E0: nop

    // 0x8001A4E4: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001A4E8: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x8001A4EC: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8001A4F0: mul.s       $f6, $f8, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f8.fl);
    // 0x8001A4F4: jal         0x80033510
    // 0x8001A4F8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8001A4F8: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_1:
    // 0x8001A4FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001A504: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001A508: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8001A50C: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001A510: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x8001A514: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8001A518: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x8001A51C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001A520: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001A524: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001A528: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x8001A52C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x8001A530: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x8001A534: jal         0x80019438
    // 0x8001A538: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    syVectorRotateAbout3D(rdram, ctx);
        goto after_2;
    // 0x8001A538: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x8001A53C: lwc1        $f24, 0x54($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001A540: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001A544: lwc1        $f26, 0x58($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001A548: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8001A54C: mul.s       $f4, $f24, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f24.fl, ctx->f6.fl);
    // 0x8001A550: lwc1        $f22, 0x50($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001A554: mul.s       $f10, $f26, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x8001A558: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8001A55C: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001A560: mul.s       $f10, $f26, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f4.fl);
    // 0x8001A564: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001A568: mul.s       $f6, $f22, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f6.fl);
    // 0x8001A56C: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8001A570: mul.s       $f10, $f22, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f8.fl);
    // 0x8001A574: nop

    // 0x8001A578: mul.s       $f6, $f24, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f4.fl);
    // 0x8001A57C: swc1        $f16, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f16.u32l;
    // 0x8001A580: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001A584: nop

    // 0x8001A588: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x8001A58C: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8001A590: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8001A594: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001A598: swc1        $f18, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f18.u32l;
    // 0x8001A59C: jal         0x80033510
    // 0x8001A5A0: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8001A5A0: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_3:
    // 0x8001A5A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001A5A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001A5AC: lwc1        $f4, 0x44($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001A5B0: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001A5B4: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8001A5B8: lwc1        $f14, 0x68($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001A5BC: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x8001A5C0: lwc1        $f18, 0x88($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8001A5C4: lwc1        $f22, 0x6C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001A5C8: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    // 0x8001A5CC: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8001A5D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001A5D4: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x8001A5D8: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001A5DC: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x8001A5E0: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8001A5E4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8001A5E8: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8001A5EC: nop

    // 0x8001A5F0: mul.s       $f16, $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8001A5F4: nop

    // 0x8001A5F8: mul.s       $f18, $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x8001A5FC: nop

    // 0x8001A600: mul.s       $f4, $f12, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8001A604: nop

    // 0x8001A608: mul.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8001A60C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001A610: swc1        $f20, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f20.u32l;
    // 0x8001A614: swc1        $f16, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f16.u32l;
    // 0x8001A618: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8001A61C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001A620: mul.s       $f4, $f22, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x8001A624: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001A628: mul.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x8001A62C: nop

    // 0x8001A630: mul.s       $f4, $f14, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x8001A634: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8001A638: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
    // 0x8001A63C: mul.s       $f10, $f22, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x8001A640: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8001A644: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8001A648: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x8001A64C: swc1        $f4, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f4.u32l;
    // 0x8001A650: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001A654: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8001A658: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001A65C: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
    // 0x8001A660: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001A664: swc1        $f8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f8.u32l;
    // 0x8001A668: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001A66C: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001A670: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8001A674: nop

    // 0x8001A678: mul.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f10.fl);
    // 0x8001A67C: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001A680: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8001A684: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8001A688: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    // 0x8001A68C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001A690: mul.s       $f6, $f22, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f10.fl);
    // 0x8001A694: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001A698: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001A69C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001A6A0: swc1        $f4, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f4.u32l;
    // 0x8001A6A4: swc1        $f10, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->f10.u32l;
    // 0x8001A6A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001A6AC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8001A6B0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8001A6B4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8001A6B8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8001A6BC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001A6C0: jr          $ra
    // 0x8001A6C4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8001A6C4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void itTaruBombRollProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018511C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80185120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185124: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80185128: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8018512C: jal         0x8017356C
    // 0x80185130: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestLRWallCheckFloor(rdram, ctx);
        goto after_0;
    // 0x80185130: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80185134: bne         $v0, $zero, L_80185154
    if (ctx->r2 != 0) {
        // 0x80185138: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80185154;
    }
    // 0x80185138: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8018513C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80185140: addiu       $a1, $a1, -0x4A2C
    ctx->r5 = ADD32(ctx->r5, -0X4A2C);
    // 0x80185144: jal         0x80172EC8
    // 0x80185148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80185148: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8018514C: b           L_8018517C
    // 0x80185150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018517C;
    // 0x80185150: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80185154:
    // 0x80185154: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80185158: lhu         $t8, 0x8E($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8E);
    // 0x8018515C: andi        $t9, $t8, 0x21
    ctx->r25 = ctx->r24 & 0X21;
    // 0x80185160: beql        $t9, $zero, L_8018517C
    if (ctx->r25 == 0) {
        // 0x80185164: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8018517C;
    }
    goto skip_0;
    // 0x80185164: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80185168: jal         0x80184DC4
    // 0x8018516C: nop

    itTaruBombCommonProcHit(rdram, ctx);
        goto after_2;
    // 0x8018516C: nop

    after_2:
    // 0x80185170: b           L_80185180
    // 0x80185174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80185180;
    // 0x80185174: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185178: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018517C:
    // 0x8018517C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80185180:
    // 0x80185180: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80185184: jr          $ra
    // 0x80185188: nop

    return;
    // 0x80185188: nop

;}
RECOMP_FUNC void ftCommonCliffCommon2UpdateCollData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145490: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80145494: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80145498: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8014549C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801454A0: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x801454A4: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x801454A8: lw          $t7, 0xB18($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XB18);
    // 0x801454AC: lw          $t6, 0x9C8($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X9C8);
    // 0x801454B0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801454B4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801454B8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x801454BC: lw          $t0, 0x2B8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2B8);
    // 0x801454C0: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    // 0x801454C4: bnel        $t0, $zero, L_801454DC
    if (ctx->r8 != 0) {
        // 0x801454C8: lw          $t1, 0x44($a2)
        ctx->r9 = MEM_W(ctx->r6, 0X44);
            goto L_801454DC;
    }
    goto skip_0;
    // 0x801454C8: lw          $t1, 0x44($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X44);
    skip_0:
    // 0x801454CC: jal         0x800DEE98
    // 0x801454D0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801454D0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801454D4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801454D8: lw          $t1, 0x44($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X44);
L_801454DC:
    // 0x801454DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801454E0: addiu       $s0, $a2, 0x78
    ctx->r16 = ADD32(ctx->r6, 0X78);
    // 0x801454E4: bne         $t1, $at, L_80145514
    if (ctx->r9 != ctx->r1) {
        // 0x801454E8: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80145514;
    }
    // 0x801454E8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801454EC: addiu       $s0, $a2, 0x78
    ctx->r16 = ADD32(ctx->r6, 0X78);
    // 0x801454F0: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    // 0x801454F4: jal         0x800F4428
    // 0x801454F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_1;
    // 0x801454F8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x801454FC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80145500: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80145504: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80145508: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014550C: b           L_80145530
    // 0x80145510: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
        goto L_80145530;
    // 0x80145510: swc1        $f8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f8.u32l;
L_80145514:
    // 0x80145514: jal         0x800F4408
    // 0x80145518: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_2;
    // 0x80145518: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    after_2:
    // 0x8014551C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80145520: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80145524: lwc1        $f10, 0x0($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X0);
    // 0x80145528: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8014552C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
L_80145530:
    // 0x80145530: lw          $a0, 0xC8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XC8);
    // 0x80145534: addiu       $t2, $s0, 0x80
    ctx->r10 = ADD32(ctx->r16, 0X80);
    // 0x80145538: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8014553C: sw          $a0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r4;
    // 0x80145540: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80145544: addiu       $a2, $s0, 0x78
    ctx->r6 = ADD32(ctx->r16, 0X78);
    // 0x80145548: jal         0x800F3DD8
    // 0x8014554C: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_3;
    // 0x8014554C: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    after_3:
    // 0x80145550: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80145554: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x80145558: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014555C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80145560: swc1        $f8, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f8.u32l;
    // 0x80145564: swc1        $f10, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f10.u32l;
    // 0x80145568: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014556C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80145570: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80145574: jr          $ra
    // 0x80145578: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80145578: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itFFlowerFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175BE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175BEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80175BF0: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80175BF4: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x80175BF8: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80175BFC: jal         0x80173F78
    // 0x80175C00: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80175C00: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80175C04: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175C08: addiu       $a1, $a1, -0x636C
    ctx->r5 = ADD32(ctx->r5, -0X636C);
    // 0x80175C0C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80175C10: jal         0x80172EC8
    // 0x80175C14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80175C14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80175C18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175C1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175C20: jr          $ra
    // 0x80175C24: nop

    return;
    // 0x80175C24: nop

;}
RECOMP_FUNC void ftFoxSpecialLwTurnInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D01C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D020: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D024: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015D028: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8015D02C: lbu         $t7, 0x18C($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18C);
    // 0x8015D030: sw          $t9, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r25;
    // 0x8015D034: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8015D038: ori         $t8, $t7, 0x4
    ctx->r24 = ctx->r15 | 0X4;
    // 0x8015D03C: jal         0x8015CF50
    // 0x8015D040: sb          $t8, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r24;
    ftFoxSpecialLwTurnDecTurnFrames(rdram, ctx);
        goto after_0;
    // 0x8015D040: sb          $t8, 0x18C($v0)
    MEM_B(0X18C, ctx->r2) = ctx->r24;
    after_0:
    // 0x8015D044: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D048: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D04C: jr          $ra
    // 0x8015D050: nop

    return;
    // 0x8015D050: nop

;}
RECOMP_FUNC void func_ovl8_80374B10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374B18: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374B1C: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80374B20: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80374B24: lh          $t6, 0x40($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X40);
    // 0x80374B28: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80374B2C: jalr        $t9
    // 0x80374B30: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374B30: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374B3C: jr          $ra
    // 0x80374B40: nop

    return;
    // 0x80374B40: nop

;}
RECOMP_FUNC void ftCommonDokanStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014204C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80142050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142054: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80142058: jal         0x80141FF0
    // 0x8014205C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftCommonDokanStartUpdateModelYaw(rdram, ctx);
        goto after_0;
    // 0x8014205C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80142060: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80142064: addiu       $a1, $a1, 0x24BC
    ctx->r5 = ADD32(ctx->r5, 0X24BC);
    // 0x80142068: jal         0x800D9480
    // 0x8014206C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014206C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80142070: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80142074: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80142078: jr          $ra
    // 0x8014207C: nop

    return;
    // 0x8014207C: nop

;}
RECOMP_FUNC void ftKirbySpecialNCatchProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801627BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801627C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801627C4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801627C8: jal         0x800DDDDC
    // 0x801627CC: addiu       $a1, $a1, 0x2BF0
    ctx->r5 = ADD32(ctx->r5, 0X2BF0);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x801627CC: addiu       $a1, $a1, 0x2BF0
    ctx->r5 = ADD32(ctx->r5, 0X2BF0);
    after_0:
    // 0x801627D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801627D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801627D8: jr          $ra
    // 0x801627DC: nop

    return;
    // 0x801627DC: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialAirNEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801574F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801574F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801574FC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80157500: jal         0x800DE6E4
    // 0x80157504: addiu       $a1, $a1, 0x7518
    ctx->r5 = ADD32(ctx->r5, 0X7518);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80157504: addiu       $a1, $a1, 0x7518
    ctx->r5 = ADD32(ctx->r5, 0X7518);
    after_0:
    // 0x80157508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015750C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157510: jr          $ra
    // 0x80157514: nop

    return;
    // 0x80157514: nop

;}
RECOMP_FUNC void gmCameraUpdateAcidZoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C7D0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010C7D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C7D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C7DC: lwc1        $f0, 0x14C0($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X14C0);
    // 0x8010C7E0: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8010C7E4: lwc1        $f4, 0x48($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X48);
    // 0x8010C7E8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8010C7EC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010C7F0: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8010C7F4: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    // 0x8010C7F8: lwc1        $f18, 0x4($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8010C7FC: lwc1        $f16, 0x4C($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x8010C800: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8010C804: add.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x8010C808: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8010C80C: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x8010C810: lwc1        $f8, 0x50($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X50);
    // 0x8010C814: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x8010C818: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8010C81C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8010C820: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8010C824: add.s       $f16, $f8, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8010C828: jal         0x8010850C
    // 0x8010C82C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    grZebesAcidGetLevelInfo(rdram, ctx);
        goto after_0;
    // 0x8010C82C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x8010C830: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C834: lwc1        $f4, 0xC40($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XC40);
    // 0x8010C838: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8010C83C: lwc1        $f0, 0x24($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8010C840: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8010C844: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8010C848: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8010C84C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8010C850: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8010C854: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x8010C858: addiu       $a2, $a3, 0x3C
    ctx->r6 = ADD32(ctx->r7, 0X3C);
    // 0x8010C85C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8010C860: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8010C864: bc1f        L_8010C874
    if (!c1cs) {
        // 0x8010C868: nop
    
            goto L_8010C874;
    }
    // 0x8010C868: nop

    // 0x8010C86C: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8010C870: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
L_8010C874:
    // 0x8010C874: jal         0x8001902C
    // 0x8010C878: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    syVectorDiff3D(rdram, ctx);
        goto after_1;
    // 0x8010C878: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8010C87C: jal         0x80018F7C
    // 0x8010C880: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    syVectorMag3D(rdram, ctx);
        goto after_2;
    // 0x8010C880: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x8010C884: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C888: lwc1        $f18, 0xC44($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0XC44);
    // 0x8010C88C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8010C890: mul.s       $f16, $f0, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8010C894: jal         0x80018EE0
    // 0x8010C898: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_3;
    // 0x8010C898: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8010C89C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x8010C8A0: jal         0x800190B0
    // 0x8010C8A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    syVectorScale3D(rdram, ctx);
        goto after_4;
    // 0x8010C8A4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    after_4:
    // 0x8010C8A8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8010C8AC: jal         0x80018FBC
    // 0x8010C8B0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    syVectorAdd3D(rdram, ctx);
        goto after_5;
    // 0x8010C8B0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_5:
    // 0x8010C8B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C8B8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8010C8BC: jr          $ra
    // 0x8010C8C0: nop

    return;
    // 0x8010C8C0: nop

;}
RECOMP_FUNC void sc1PStageClearCheckGameClearBonus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801330F0: addiu       $t6, $a0, -0x16
    ctx->r14 = ADD32(ctx->r4, -0X16);
    // 0x801330F4: sltiu       $at, $t6, 0x5
    ctx->r1 = ctx->r14 < 0X5 ? 1 : 0;
    // 0x801330F8: beq         $at, $zero, L_80133120
    if (ctx->r1 == 0) {
        // 0x801330FC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80133120;
    }
    // 0x801330FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80133100: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80133104: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133108: addu        $at, $at, $t6
    gpr jr_addend_80133110 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8013310C: lw          $t6, 0x52A0($at)
    ctx->r14 = ADD32(ctx->r1, 0X52A0);
    // 0x80133110: jr          $t6
    // 0x80133114: nop

    switch (jr_addend_80133110 >> 2) {
        case 0: goto L_80133118; break;
        case 1: goto L_80133118; break;
        case 2: goto L_80133118; break;
        case 3: goto L_80133118; break;
        case 4: goto L_80133118; break;
        default: switch_error(__func__, 0x80133110, 0x801352A0);
    }
    // 0x80133114: nop

L_80133118:
    // 0x80133118: jr          $ra
    // 0x8013311C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013311C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133120:
    // 0x80133120: jr          $ra
    // 0x80133124: nop

    return;
    // 0x80133124: nop

;}
RECOMP_FUNC void mnTitleUpdateFireVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132218: jal         0x80018A30
    // 0x8013221C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_0;
    // 0x8013221C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_0:
    // 0x80132220: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80132224: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80132228: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8013222C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132230: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132234: addiu       $v1, $v1, 0x4484
    ctx->r3 = ADD32(ctx->r3, 0X4484);
    // 0x80132238: sw          $v0, 0x4494($at)
    MEM_W(0X4494, ctx->r1) = ctx->r2;
    // 0x8013223C: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x80132240: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132244: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132248: addiu       $a0, $a0, 0x4480
    ctx->r4 = ADD32(ctx->r4, 0X4480);
    // 0x8013224C: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x80132250: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80132254: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132258: addiu       $a1, $a1, 0x447C
    ctx->r5 = ADD32(ctx->r5, 0X447C);
    // 0x8013225C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132260: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80132264: swc1        $f2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f2.u32l;
    // 0x80132268: lbu         $t6, 0x4318($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4318);
    // 0x8013226C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80132270: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80132274: bgez        $t6, L_80132288
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80132278: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80132288;
    }
    // 0x80132278: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013227C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132280: nop

    // 0x80132284: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80132288:
    // 0x80132288: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8013228C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132290: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x80132294: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80132298: lbu         $t7, 0x4320($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4320);
    // 0x8013229C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801322A0: div.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x801322A4: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801322A8: nop

    // 0x801322AC: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801322B0: bgez        $t7, L_801322C8
    if (SIGNED(ctx->r15) >= 0) {
        // 0x801322B4: swc1        $f4, 0x4488($at)
        MEM_W(0X4488, ctx->r1) = ctx->f4.u32l;
            goto L_801322C8;
    }
    // 0x801322B4: swc1        $f4, 0x4488($at)
    MEM_W(0X4488, ctx->r1) = ctx->f4.u32l;
    // 0x801322B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801322BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801322C0: nop

    // 0x801322C4: add.s       $f10, $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f8.fl;
L_801322C8:
    // 0x801322C8: sub.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x801322CC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801322D0: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x801322D4: lbu         $t8, 0x4328($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X4328);
    // 0x801322D8: div.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f12.fl);
    // 0x801322DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801322E0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801322E4: nop

    // 0x801322E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801322EC: bgez        $t8, L_80132304
    if (SIGNED(ctx->r24) >= 0) {
        // 0x801322F0: swc1        $f18, 0x448C($at)
        MEM_W(0X448C, ctx->r1) = ctx->f18.u32l;
            goto L_80132304;
    }
    // 0x801322F0: swc1        $f18, 0x448C($at)
    MEM_W(0X448C, ctx->r1) = ctx->f18.u32l;
    // 0x801322F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x801322F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801322FC: nop

    // 0x80132300: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80132304:
    // 0x80132304: sub.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80132308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013230C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132310: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132314: div.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80132318: jr          $ra
    // 0x8013231C: swc1        $f16, 0x4490($at)
    MEM_W(0X4490, ctx->r1) = ctx->f16.u32l;
    return;
    // 0x8013231C: swc1        $f16, 0x4490($at)
    MEM_W(0X4490, ctx->r1) = ctx->f16.u32l;
;}
RECOMP_FUNC void mnPlayers1PBonusGetBestTaskCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133990: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133994: lw          $t6, 0x7714($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7714);
    // 0x80133998: sll         $t8, $a0, 5
    ctx->r24 = S32(ctx->r4 << 5);
    // 0x8013399C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801339A0: bne         $t6, $zero, L_801339BC
    if (ctx->r14 != 0) {
        // 0x801339A4: addu        $v0, $v0, $t8
        ctx->r2 = ADD32(ctx->r2, ctx->r24);
            goto L_801339BC;
    }
    // 0x801339A4: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x801339A8: sll         $t7, $a0, 5
    ctx->r15 = S32(ctx->r4 << 5);
    // 0x801339AC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801339B0: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x801339B4: jr          $ra
    // 0x801339B8: lbu         $v0, 0x4950($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4950);
    return;
    // 0x801339B8: lbu         $v0, 0x4950($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4950);
L_801339BC:
    // 0x801339BC: lbu         $v0, 0x4958($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4958);
    // 0x801339C0: jr          $ra
    // 0x801339C4: nop

    return;
    // 0x801339C4: nop

;}
RECOMP_FUNC void ftCommonPassProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80141D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141D68: jal         0x80150F08
    // 0x80141D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonSpecialAirCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x80141D6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80141D70: bnel        $v0, $zero, L_80141D94
    if (ctx->r2 != 0) {
        // 0x80141D74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80141D94;
    }
    goto skip_0;
    // 0x80141D74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80141D78: jal         0x80150B00
    // 0x80141D7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonAttackAirCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x80141D7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80141D80: bnel        $v0, $zero, L_80141D94
    if (ctx->r2 != 0) {
        // 0x80141D84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80141D94;
    }
    goto skip_1;
    // 0x80141D84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80141D88: jal         0x8014019C
    // 0x80141D8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonJumpAerialCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x80141D8C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80141D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80141D94:
    // 0x80141D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80141D98: jr          $ra
    // 0x80141D9C: nop

    return;
    // 0x80141D9C: nop

;}
RECOMP_FUNC void mpCollisionGetPlayerMapObjPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAF64: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800FAF68: lw          $t6, 0x1368($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1368);
    // 0x800FAF6C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800FAF70: lhu         $v0, 0x14($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X14);
    // 0x800FAF74: bne         $v0, $zero, L_800FAF94
    if (ctx->r2 != 0) {
        // 0x800FAF78: nop
    
            goto L_800FAF94;
    }
    // 0x800FAF78: nop

    // 0x800FAF7C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800FAF80: nop

    // 0x800FAF84: swc1        $f0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f0.u32l;
    // 0x800FAF88: swc1        $f0, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f0.u32l;
    // 0x800FAF8C: jr          $ra
    // 0x800FAF90: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    return;
    // 0x800FAF90: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
L_800FAF94:
    // 0x800FAF94: blez        $v0, L_800FB008
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800FAF98: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800FB008;
    }
    // 0x800FAF98: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800FAF9C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800FAFA0: lw          $a3, 0x1380($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X1380);
    // 0x800FAFA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FAFA8:
    // 0x800FAFA8: lhu         $t7, 0x0($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X0);
    // 0x800FAFAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800FAFB0: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800FAFB4: bnel        $a0, $t7, L_800FB000
    if (ctx->r4 != ctx->r15) {
        // 0x800FAFB8: addiu       $v0, $v0, 0x6
        ctx->r2 = ADD32(ctx->r2, 0X6);
            goto L_800FB000;
    }
    goto skip_0;
    // 0x800FAFB8: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    skip_0:
    // 0x800FAFBC: lh          $t8, 0x2($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X2);
    // 0x800FAFC0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800FAFC4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800FAFC8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800FAFCC: nop

    // 0x800FAFD0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800FAFD4: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x800FAFD8: lw          $t9, 0x1380($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X1380);
    // 0x800FAFDC: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800FAFE0: lh          $t1, 0x4($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X4);
    // 0x800FAFE4: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    // 0x800FAFE8: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800FAFEC: nop

    // 0x800FAFF0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800FAFF4: jr          $ra
    // 0x800FAFF8: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    return;
    // 0x800FAFF8: swc1        $f10, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f10.u32l;
    // 0x800FAFFC: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
L_800FB000:
    // 0x800FB000: bne         $at, $zero, L_800FAFA8
    if (ctx->r1 != 0) {
        // 0x800FB004: addiu       $a3, $a3, 0x6
        ctx->r7 = ADD32(ctx->r7, 0X6);
            goto L_800FAFA8;
    }
    // 0x800FB004: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
L_800FB008:
    // 0x800FB008: jr          $ra
    // 0x800FB00C: nop

    return;
    // 0x800FB00C: nop

;}
RECOMP_FUNC void itGShellHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178A90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178A94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178A98: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80178A9C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80178AA0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80178AA4: addiu       $a1, $a1, -0x5DCC
    ctx->r5 = ADD32(ctx->r5, -0X5DCC);
    // 0x80178AA8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80178AAC: jal         0x80172EC8
    // 0x80178AB0: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80178AB0: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    after_0:
    // 0x80178AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178AB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178ABC: jr          $ra
    // 0x80178AC0: nop

    return;
    // 0x80178AC0: nop

;}
RECOMP_FUNC void mnVSResultsMakeTKO(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801358F0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801358F4: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801358F8: lw          $t9, -0x5FB8($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5FB8);
    // 0x801358FC: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80135900: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80135904: addiu       $t0, $t0, 0x358
    ctx->r8 = ADD32(ctx->r8, 0X358);
    // 0x80135908: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013590C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80135910: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80135914: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80135918: addiu       $t6, $t6, -0x3100
    ctx->r14 = ADD32(ctx->r14, -0X3100);
    // 0x8013591C: addiu       $t7, $zero, 0x1F
    ctx->r15 = ADD32(0, 0X1F);
    // 0x80135920: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80135924: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135928: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013592C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80135930: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80135934: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80135938: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8013593C: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80135940: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80135944: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135948: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013594C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80135950: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80135954: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80135958: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013595C: jal         0x800CD050
    // 0x80135960: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80135960: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    after_0:
    // 0x80135964: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    // 0x80135968: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8013596C: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x80135970: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80135974: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135978: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x8013597C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80135980: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80135984: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x80135988: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x8013598C: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x80135990: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80135994: swc1        $f10, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f10.u32l;
    // 0x80135998: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013599C: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x801359A0: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x801359A4: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x801359A8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801359AC: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801359B0: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801359B4: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x801359B8: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x801359BC: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x801359C0: lw          $t0, 0x74($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X74);
    // 0x801359C4: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801359C8: sb          $zero, 0x28($t0)
    MEM_B(0X28, ctx->r8) = 0;
    // 0x801359CC: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x801359D0: sb          $zero, 0x29($t1)
    MEM_B(0X29, ctx->r9) = 0;
    // 0x801359D4: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x801359D8: sb          $zero, 0x2A($t2)
    MEM_B(0X2A, ctx->r10) = 0;
    // 0x801359DC: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x801359E0: sb          $a0, 0x28($t3)
    MEM_B(0X28, ctx->r11) = ctx->r4;
    // 0x801359E4: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x801359E8: sb          $a0, 0x29($t4)
    MEM_B(0X29, ctx->r12) = ctx->r4;
    // 0x801359EC: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x801359F0: sb          $a0, 0x2A($t5)
    MEM_B(0X2A, ctx->r13) = ctx->r4;
    // 0x801359F4: lw          $t6, -0x63F0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X63F0);
    // 0x801359F8: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x801359FC: beq         $t6, $at, L_80135A44
    if (ctx->r14 == ctx->r1) {
        // 0x80135A00: nop
    
            goto L_80135A44;
    }
    // 0x80135A00: nop

    // 0x80135A04: lw          $t7, -0x5FA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5FA4);
    // 0x80135A08: addiu       $t8, $t8, 0x710
    ctx->r24 = ADD32(ctx->r24, 0X710);
    // 0x80135A0C: jal         0x800CCFDC
    // 0x80135A10: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80135A10: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_1:
    // 0x80135A14: addiu       $t9, $s0, 0x3
    ctx->r25 = ADD32(ctx->r16, 0X3);
    // 0x80135A18: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80135A1C: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80135A20: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80135A24: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80135A28: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80135A2C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80135A30: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80135A34: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80135A38: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80135A3C: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    // 0x80135A40: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
L_80135A44:
    // 0x80135A44: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80135A48: lw          $t4, -0x6430($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6430);
    // 0x80135A4C: beq         $t4, $zero, L_80135A8C
    if (ctx->r12 == 0) {
        // 0x80135A50: nop
    
            goto L_80135A8C;
    }
    // 0x80135A50: nop

    // 0x80135A54: jal         0x801352FC
    // 0x80135A58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_2;
    // 0x80135A58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80135A5C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80135A60: jal         0x801358C4
    // 0x80135A64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsGetTKO(rdram, ctx);
        goto after_3;
    // 0x80135A64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x80135A68: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135A6C: jal         0x801353F4
    // 0x80135A70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_4;
    // 0x80135A70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80135A74: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80135A78: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80135A7C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80135A80: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135A84: jal         0x80134AC4
    // 0x80135A88: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_5;
    // 0x80135A88: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_5:
L_80135A8C:
    // 0x80135A8C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80135A90: lw          $t5, -0x642C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X642C);
    // 0x80135A94: beq         $t5, $zero, L_80135AD4
    if (ctx->r13 == 0) {
        // 0x80135A98: nop
    
            goto L_80135AD4;
    }
    // 0x80135A98: nop

    // 0x80135A9C: jal         0x801352FC
    // 0x80135AA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_6;
    // 0x80135AA0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80135AA4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80135AA8: jal         0x801358C4
    // 0x80135AAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsGetTKO(rdram, ctx);
        goto after_7;
    // 0x80135AAC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_7:
    // 0x80135AB0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135AB4: jal         0x801353F4
    // 0x80135AB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_8;
    // 0x80135AB8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x80135ABC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80135AC0: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80135AC4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80135AC8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135ACC: jal         0x80134AC4
    // 0x80135AD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_9;
    // 0x80135AD0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_9:
L_80135AD4:
    // 0x80135AD4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135AD8: lw          $t6, -0x6428($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6428);
    // 0x80135ADC: beq         $t6, $zero, L_80135B1C
    if (ctx->r14 == 0) {
        // 0x80135AE0: nop
    
            goto L_80135B1C;
    }
    // 0x80135AE0: nop

    // 0x80135AE4: jal         0x801352FC
    // 0x80135AE8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_10;
    // 0x80135AE8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x80135AEC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80135AF0: jal         0x801358C4
    // 0x80135AF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnVSResultsGetTKO(rdram, ctx);
        goto after_11;
    // 0x80135AF4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_11:
    // 0x80135AF8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135AFC: jal         0x801353F4
    // 0x80135B00: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_12;
    // 0x80135B00: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_12:
    // 0x80135B04: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80135B08: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80135B0C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80135B10: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135B14: jal         0x80134AC4
    // 0x80135B18: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_13;
    // 0x80135B18: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_13:
L_80135B1C:
    // 0x80135B1C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135B20: lw          $t7, -0x6424($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6424);
    // 0x80135B24: beql        $t7, $zero, L_80135B68
    if (ctx->r15 == 0) {
        // 0x80135B28: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_80135B68;
    }
    goto skip_0;
    // 0x80135B28: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80135B2C: jal         0x801352FC
    // 0x80135B30: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnVSResultsGetColumnX(rdram, ctx);
        goto after_14;
    // 0x80135B30: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_14:
    // 0x80135B34: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80135B38: jal         0x801358C4
    // 0x80135B3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnVSResultsGetTKO(rdram, ctx);
        goto after_15;
    // 0x80135B3C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_15:
    // 0x80135B40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135B44: jal         0x801353F4
    // 0x80135B48: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    mnVSResultsGetNumberColorID(rdram, ctx);
        goto after_16;
    // 0x80135B48: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_16:
    // 0x80135B4C: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80135B50: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80135B54: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x80135B58: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135B5C: jal         0x80134AC4
    // 0x80135B60: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    mnVSResultsMakeNumber(rdram, ctx);
        goto after_17;
    // 0x80135B60: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_17:
    // 0x80135B64: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_80135B68:
    // 0x80135B68: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x80135B6C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80135B70: jr          $ra
    // 0x80135B74: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80135B74: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftDonkeySpecialHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B800: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B804: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B808: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015B80C: jal         0x800DDDDC
    // 0x8015B810: addiu       $a1, $a1, -0x4768
    ctx->r5 = ADD32(ctx->r5, -0X4768);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015B810: addiu       $a1, $a1, -0x4768
    ctx->r5 = ADD32(ctx->r5, -0X4768);
    after_0:
    // 0x8015B814: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B818: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015B81C: jr          $ra
    // 0x8015B820: nop

    return;
    // 0x8015B820: nop

;}
RECOMP_FUNC void itHeartDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801747F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801747FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174800: lui         $a1, 0x3DCC
    ctx->r5 = S32(0X3DCC << 16);
    // 0x80174804: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80174808: addiu       $a3, $a3, 0x4780
    ctx->r7 = ADD32(ctx->r7, 0X4780);
    // 0x8017480C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80174810: jal         0x80173B24
    // 0x80174814: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80174814: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x80174818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017481C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174820: jr          $ra
    // 0x80174824: nop

    return;
    // 0x80174824: nop

;}
RECOMP_FUNC void func_ovl8_80385D54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385D54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80385D58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385D5C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80385D60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80385D64: jal         0x803817C0
    // 0x80385D68: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    func_ovl8_803817C0(rdram, ctx);
        goto after_0;
    // 0x80385D68: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    after_0:
    // 0x80385D6C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80385D70: jal         0x80373694
    // 0x80385D74: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_ovl8_80373694(rdram, ctx);
        goto after_1;
    // 0x80385D74: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80385D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80385D7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80385D80: jr          $ra
    // 0x80385D84: nop

    return;
    // 0x80385D84: nop

;}
RECOMP_FUNC void efManagerDestroyParticleGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDB3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FDB40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FDB44: beq         $a0, $zero, L_800FDB54
    if (ctx->r4 == 0) {
        // 0x800FDB48: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800FDB54;
    }
    // 0x800FDB48: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800FDB4C: jal         0x800CEA40
    // 0x800FDB50: nop

    lbParticleEjectStruct(rdram, ctx);
        goto after_0;
    // 0x800FDB50: nop

    after_0:
L_800FDB54:
    // 0x800FDB54: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800FDB58: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x800FDB5C: beq         $v0, $zero, L_800FDB6C
    if (ctx->r2 == 0) {
        // 0x800FDB60: nop
    
            goto L_800FDB6C;
    }
    // 0x800FDB60: nop

    // 0x800FDB64: jal         0x800FD4F8
    // 0x800FDB68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_1;
    // 0x800FDB68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
L_800FDB6C:
    // 0x800FDB6C: jal         0x80009A84
    // 0x800FDB70: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x800FDB70: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x800FDB74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FDB78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FDB7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FDB80: jr          $ra
    // 0x800FDB84: nop

    return;
    // 0x800FDB84: nop

;}
RECOMP_FUNC void ftCommonThrownReleaseFighterLoseGrip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014ADB0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8014ADB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014ADB8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8014ADBC: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8014ADC0: lw          $t7, 0x190($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X190);
    // 0x8014ADC4: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x8014ADC8: bgezl       $t9, L_8014ADDC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8014ADCC: lw          $v1, 0x844($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X844);
            goto L_8014ADDC;
    }
    goto skip_0;
    // 0x8014ADCC: lw          $v1, 0x844($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X844);
    skip_0:
    // 0x8014ADD0: b           L_8014ADDC
    // 0x8014ADD4: lw          $v1, 0x840($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X840);
        goto L_8014ADDC;
    // 0x8014ADD4: lw          $v1, 0x840($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X840);
    // 0x8014ADD8: lw          $v1, 0x844($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X844);
L_8014ADDC:
    // 0x8014ADDC: lw          $v0, 0x24($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X24);
    // 0x8014ADE0: lw          $t0, 0x84($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X84);
    // 0x8014ADE4: slti        $at, $v0, 0xB5
    ctx->r1 = SIGNED(ctx->r2) < 0XB5 ? 1 : 0;
    // 0x8014ADE8: bne         $at, $zero, L_8014AE64
    if (ctx->r1 != 0) {
        // 0x8014ADEC: slti        $at, $v0, 0xBD
        ctx->r1 = SIGNED(ctx->r2) < 0XBD ? 1 : 0;
            goto L_8014AE64;
    }
    // 0x8014ADEC: slti        $at, $v0, 0xBD
    ctx->r1 = SIGNED(ctx->r2) < 0XBD ? 1 : 0;
    // 0x8014ADF0: beql        $at, $zero, L_8014AE68
    if (ctx->r1 == 0) {
        // 0x8014ADF4: lw          $a1, 0x74($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X74);
            goto L_8014AE68;
    }
    goto skip_1;
    // 0x8014ADF4: lw          $a1, 0x74($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X74);
    skip_1:
    // 0x8014ADF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014ADFC: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8014AE00: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8014AE04: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8014AE08: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8014AE0C: lw          $a0, 0x8F8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8F8);
    // 0x8014AE10: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x8014AE14: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8014AE18: jal         0x800EDF24
    // 0x8014AE1C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8014AE1C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014AE20: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8014AE24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014AE28: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8014AE2C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8014AE30: addiu       $t3, $sp, 0x20
    ctx->r11 = ADD32(ctx->r29, 0X20);
    // 0x8014AE34: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8014AE38: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8014AE3C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8014AE40: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8014AE44: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8014AE48: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x8014AE4C: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x8014AE50: sw          $t5, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r13;
    // 0x8014AE54: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x8014AE58: sw          $t4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r12;
    // 0x8014AE5C: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8014AE60: sw          $t5, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r13;
L_8014AE64:
    // 0x8014AE64: lw          $a1, 0x74($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X74);
L_8014AE68:
    // 0x8014AE68: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8014AE6C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8014AE70: addiu       $a2, $t0, 0x78
    ctx->r6 = ADD32(ctx->r8, 0X78);
    // 0x8014AE74: jal         0x800DF014
    // 0x8014AE78: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCommonRunFighterCollisionDefault(rdram, ctx);
        goto after_1;
    // 0x8014AE78: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_1:
    // 0x8014AE7C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x8014AE80: lw          $t6, 0x14C($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X14C);
    // 0x8014AE84: bnel        $t6, $zero, L_8014AEC0
    if (ctx->r14 != 0) {
        // 0x8014AE88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014AEC0;
    }
    goto skip_2;
    // 0x8014AE88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8014AE8C: lw          $t7, 0xEC($a3)
    ctx->r15 = MEM_W(ctx->r7, 0XEC);
    // 0x8014AE90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8014AE94: beq         $t7, $at, L_8014AEB4
    if (ctx->r15 == ctx->r1) {
        // 0x8014AE98: nop
    
            goto L_8014AEB4;
    }
    // 0x8014AE98: nop

    // 0x8014AE9C: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8014AEA0: lwc1        $f16, 0xF0($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XF0);
    // 0x8014AEA4: c.eq.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl == ctx->f16.fl;
    // 0x8014AEA8: nop

    // 0x8014AEAC: bc1tl       L_8014AEC0
    if (c1cs) {
        // 0x8014AEB0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014AEC0;
    }
    goto skip_3;
    // 0x8014AEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
L_8014AEB4:
    // 0x8014AEB4: jal         0x800DEEC8
    // 0x8014AEB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_2;
    // 0x8014AEB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_2:
    // 0x8014AEBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014AEC0:
    // 0x8014AEC0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8014AEC4: jr          $ra
    // 0x8014AEC8: nop

    return;
    // 0x8014AEC8: nop

;}

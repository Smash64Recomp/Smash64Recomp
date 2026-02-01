#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftCommonCaptureApplyCatchKnockback(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E1D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014E1D4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8014E1D8: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8014E1DC: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8014E1E0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8014E1E4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014E1E8: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x8014E1EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014E1F0: lw          $v0, 0x840($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X840);
    // 0x8014E1F4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8014E1F8: lw          $a0, 0x2C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X2C);
    // 0x8014E1FC: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8014E200: lw          $a3, 0x8($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X8);
    // 0x8014E204: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8014E208: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x8014E20C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014E210: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8014E214: lw          $t0, 0x9C8($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014E218: lwc1        $f4, 0x68($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X68);
    // 0x8014E21C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x8014E220: lbu         $t1, 0x12($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X12);
    // 0x8014E224: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8014E228: lbu         $t2, 0x12($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X12);
    // 0x8014E22C: jal         0x800E9D78
    // 0x8014E230: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    ftParamGetCommonKnockback(rdram, ctx);
        goto after_0;
    // 0x8014E230: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_0:
    // 0x8014E234: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8014E238: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8014E23C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8014E240: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x8014E244: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8014E248: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8014E24C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8014E250: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x8014E254: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8014E258: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8014E25C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8014E260: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x8014E264: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8014E268: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8014E26C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014E270: jal         0x80140EE4
    // 0x8014E274: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    ftCommonDamageInitDamageVars(rdram, ctx);
        goto after_1;
    // 0x8014E274: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_1:
    // 0x8014E278: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014E27C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8014E280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014E284: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8014E288: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014E28C: jal         0x800EAA2C
    // 0x8014E290: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_2;
    // 0x8014E290: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x8014E294: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8014E298: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8014E29C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8014E2A0: jr          $ra
    // 0x8014E2A4: nop

    return;
    // 0x8014E2A4: nop

;}
RECOMP_FUNC void itLizardonWeaponFlameProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FAF8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017FAFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017FB00: jal         0x80167C04
    // 0x8017FB04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8017FB04: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017FB08: beq         $v0, $zero, L_8017FB28
    if (ctx->r2 == 0) {
        // 0x8017FB0C: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_8017FB28;
    }
    // 0x8017FB0C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8017FB10: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8017FB14: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8017FB18: jal         0x800FF648
    // 0x8017FB1C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8017FB1C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8017FB20: b           L_8017FB2C
    // 0x8017FB24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017FB2C;
    // 0x8017FB24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017FB28:
    // 0x8017FB28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017FB2C:
    // 0x8017FB2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017FB30: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017FB34: jr          $ra
    // 0x8017FB38: nop

    return;
    // 0x8017FB38: nop

;}
RECOMP_FUNC void mvOpeningYamabukiInitTotalTimeTics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801320D4: jr          $ra
    // 0x801320D8: sw          $zero, 0x248C($at)
    MEM_W(0X248C, ctx->r1) = 0;
    return;
    // 0x801320D8: sw          $zero, 0x248C($at)
    MEM_W(0X248C, ctx->r1) = 0;
;}
RECOMP_FUNC void syAudioInitOsc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001EBE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001EBE8: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8001EBEC: addiu       $t0, $t0, -0x2608
    ctx->r8 = ADD32(ctx->r8, -0X2608);
    // 0x8001EBF0: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8001EBF4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001EBF8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8001EBFC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8001EC00: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8001EC04: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8001EC08: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8001EC0C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001EC10: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001EC14: beq         $v1, $zero, L_8001EEA0
    if (ctx->r3 == 0) {
        // 0x8001EC18: sw          $zero, 0x28($sp)
        MEM_W(0X28, ctx->r29) = 0;
            goto L_8001EEA0;
    }
    // 0x8001EC18: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8001EC1C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8001EC20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001EC24: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
    // 0x8001EC28: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8001EC2C: sb          $a2, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r6;
    // 0x8001EC30: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x8001EC34: lbu         $t7, 0x47($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X47);
    // 0x8001EC38: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x8001EC3C: addiu       $t9, $zero, 0x103
    ctx->r25 = ADD32(0, 0X103);
    // 0x8001EC40: sll         $t8, $t7, 14
    ctx->r24 = S32(ctx->r15 << 14);
    // 0x8001EC44: beq         $a2, $at, L_8001ECA8
    if (ctx->r6 == ctx->r1) {
        // 0x8001EC48: sw          $t8, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r24;
            goto L_8001ECA8;
    }
    // 0x8001EC48: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8001EC4C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8001EC50: beq         $a2, $at, L_8001ECF0
    if (ctx->r6 == ctx->r1) {
        // 0x8001EC54: addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
            goto L_8001ECF0;
    }
    // 0x8001EC54: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8001EC58: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8001EC5C: beq         $a2, $at, L_8001ED2C
    if (ctx->r6 == ctx->r1) {
        // 0x8001EC60: addiu       $v0, $zero, 0x7F
        ctx->r2 = ADD32(0, 0X7F);
            goto L_8001ED2C;
    }
    // 0x8001EC60: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
    // 0x8001EC64: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8001EC68: beq         $a2, $at, L_8001ED70
    if (ctx->r6 == ctx->r1) {
        // 0x8001EC6C: lbu         $a0, 0x43($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X43);
            goto L_8001ED70;
    }
    // 0x8001EC6C: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x8001EC70: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001EC74: beq         $a2, $at, L_8001EDB8
    if (ctx->r6 == ctx->r1) {
        // 0x8001EC78: lbu         $a0, 0x43($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X43);
            goto L_8001EDB8;
    }
    // 0x8001EC78: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x8001EC7C: addiu       $at, $zero, 0x81
    ctx->r1 = ADD32(0, 0X81);
    // 0x8001EC80: beq         $a2, $at, L_8001EDE8
    if (ctx->r6 == ctx->r1) {
        // 0x8001EC84: lbu         $a0, 0x43($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X43);
            goto L_8001EDE8;
    }
    // 0x8001EC84: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x8001EC88: addiu       $at, $zero, 0x82
    ctx->r1 = ADD32(0, 0X82);
    // 0x8001EC8C: beq         $a2, $at, L_8001EE30
    if (ctx->r6 == ctx->r1) {
        // 0x8001EC90: lbu         $a0, 0x43($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X43);
            goto L_8001EE30;
    }
    // 0x8001EC90: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x8001EC94: addiu       $at, $zero, 0x83
    ctx->r1 = ADD32(0, 0X83);
    // 0x8001EC98: beq         $a2, $at, L_8001EE68
    if (ctx->r6 == ctx->r1) {
        // 0x8001EC9C: lbu         $a0, 0x43($sp)
        ctx->r4 = MEM_BU(ctx->r29, 0X43);
            goto L_8001EE68;
    }
    // 0x8001EC9C: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x8001ECA0: b           L_8001EEA4
    // 0x8001ECA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001EEA4;
    // 0x8001ECA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001ECA8:
    // 0x8001ECA8: sra         $t3, $a0, 1
    ctx->r11 = S32(SIGNED(ctx->r4) >> 1);
    // 0x8001ECAC: addiu       $t4, $zero, 0x7F
    ctx->r12 = ADD32(0, 0X7F);
    // 0x8001ECB0: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x8001ECB4: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8001ECB8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8001ECBC: subu        $t1, $t9, $a3
    ctx->r9 = SUB32(ctx->r25, ctx->r7);
    // 0x8001ECC0: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8001ECC4: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    // 0x8001ECC8: sb          $t3, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r11;
    // 0x8001ECCC: sb          $t5, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r13;
    // 0x8001ECD0: bgez        $t6, L_8001ECE8
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8001ECD4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8001ECE8;
    }
    // 0x8001ECD4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001ECD8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001ECDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8001ECE0: nop

    // 0x8001ECE4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8001ECE8:
    // 0x8001ECE8: b           L_8001EEA0
    // 0x8001ECEC: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_8001EEA0;
    // 0x8001ECEC: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_8001ECF0:
    // 0x8001ECF0: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x8001ECF4: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x8001ECF8: subu        $t9, $t7, $a3
    ctx->r25 = SUB32(ctx->r15, ctx->r7);
    // 0x8001ECFC: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x8001ED00: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x8001ED04: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001ED08: subu        $t2, $t1, $a0
    ctx->r10 = SUB32(ctx->r9, ctx->r4);
    // 0x8001ED0C: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
    // 0x8001ED10: sh          $t9, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r25;
    // 0x8001ED14: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    // 0x8001ED18: sb          $t2, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r10;
    // 0x8001ED1C: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x8001ED20: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x8001ED24: b           L_8001EEA0
    // 0x8001ED28: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
        goto L_8001EEA0;
    // 0x8001ED28: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_8001ED2C:
    // 0x8001ED2C: lbu         $a0, 0x43($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X43);
    // 0x8001ED30: andi        $t5, $v0, 0xFF
    ctx->r13 = ctx->r2 & 0XFF;
    // 0x8001ED34: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x8001ED38: addiu       $t4, $zero, 0x100
    ctx->r12 = ADD32(0, 0X100);
    // 0x8001ED3C: subu        $t3, $t4, $a3
    ctx->r11 = SUB32(ctx->r12, ctx->r7);
    // 0x8001ED40: sh          $t3, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r11;
    // 0x8001ED44: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8001ED48: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x8001ED4C: sb          $a0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r4;
    // 0x8001ED50: bgez        $t5, L_8001ED68
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8001ED54: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8001ED68;
    }
    // 0x8001ED54: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8001ED58: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001ED5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001ED60: nop

    // 0x8001ED64: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8001ED68:
    // 0x8001ED68: b           L_8001EEA0
    // 0x8001ED6C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
        goto L_8001EEA0;
    // 0x8001ED6C: swc1        $f18, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f18.u32l;
L_8001ED70:
    // 0x8001ED70: addiu       $t8, $zero, 0x7F
    ctx->r24 = ADD32(0, 0X7F);
    // 0x8001ED74: subu        $t9, $t8, $a0
    ctx->r25 = SUB32(ctx->r24, ctx->r4);
    // 0x8001ED78: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8001ED7C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8001ED80: addiu       $t6, $zero, 0x100
    ctx->r14 = ADD32(0, 0X100);
    // 0x8001ED84: subu        $t7, $t6, $a3
    ctx->r15 = SUB32(ctx->r14, ctx->r7);
    // 0x8001ED88: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
    // 0x8001ED8C: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8001ED90: sb          $a0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r4;
    // 0x8001ED94: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
    // 0x8001ED98: bgez        $t1, L_8001EDB0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8001ED9C: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8001EDB0;
    }
    // 0x8001ED9C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8001EDA0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8001EDA4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001EDA8: nop

    // 0x8001EDAC: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8001EDB0:
    // 0x8001EDB0: b           L_8001EEA0
    // 0x8001EDB4: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
        goto L_8001EEA0;
    // 0x8001EDB4: swc1        $f6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f6.u32l;
L_8001EDB8:
    // 0x8001EDB8: jal         0x8001EB98
    // 0x8001EDBC: sb          $a3, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r7;
    syAudioDepth2Cents(rdram, ctx);
        goto after_0;
    // 0x8001EDBC: sb          $a3, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r7;
    after_0:
    // 0x8001EDC0: lbu         $a3, 0x3F($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X3F);
    // 0x8001EDC4: addiu       $t2, $zero, 0x103
    ctx->r10 = ADD32(0, 0X103);
    // 0x8001EDC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001EDCC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001EDD0: subu        $t4, $t2, $a3
    ctx->r12 = SUB32(ctx->r10, ctx->r7);
    // 0x8001EDD4: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8001EDD8: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x8001EDDC: sh          $t4, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r12;
    // 0x8001EDE0: b           L_8001EEA0
    // 0x8001EDE4: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
        goto L_8001EEA0;
    // 0x8001EDE4: swc1        $f16, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f16.u32l;
L_8001EDE8:
    // 0x8001EDE8: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x8001EDEC: subu        $t6, $t3, $a3
    ctx->r14 = SUB32(ctx->r11, ctx->r7);
    // 0x8001EDF0: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x8001EDF4: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x8001EDF8: jal         0x8001EB98
    // 0x8001EDFC: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    syAudioDepth2Cents(rdram, ctx);
        goto after_1;
    // 0x8001EDFC: sb          $zero, 0x5($s0)
    MEM_B(0X5, ctx->r16) = 0;
    after_1:
    // 0x8001EE00: trunc.w.s   $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001EE04: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8001EE08: nop

    // 0x8001EE0C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8001EE10: jal         0x80036360
    // 0x8001EE14: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    alCents2Ratio(rdram, ctx);
        goto after_2;
    // 0x8001EE14: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x8001EE18: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x8001EE1C: jal         0x80036360
    // 0x8001EE20: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    alCents2Ratio(rdram, ctx);
        goto after_3;
    // 0x8001EE20: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x8001EE24: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x8001EE28: b           L_8001EEA0
    // 0x8001EE2C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_8001EEA0;
    // 0x8001EE2C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_8001EE30:
    // 0x8001EE30: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x8001EE34: subu        $t1, $t8, $a3
    ctx->r9 = SUB32(ctx->r24, ctx->r7);
    // 0x8001EE38: sh          $t1, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r9;
    // 0x8001EE3C: jal         0x8001EB98
    // 0x8001EE40: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    syAudioDepth2Cents(rdram, ctx);
        goto after_4;
    // 0x8001EE40: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    after_4:
    // 0x8001EE44: trunc.w.s   $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001EE48: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8001EE4C: nop

    // 0x8001EE50: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x8001EE54: sw          $t4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r12;
    // 0x8001EE58: jal         0x80036360
    // 0x8001EE5C: sw          $a0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r4;
    alCents2Ratio(rdram, ctx);
        goto after_5;
    // 0x8001EE5C: sw          $a0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r4;
    after_5:
    // 0x8001EE60: b           L_8001EEA0
    // 0x8001EE64: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
        goto L_8001EEA0;
    // 0x8001EE64: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_8001EE68:
    // 0x8001EE68: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x8001EE6C: subu        $t6, $t3, $a3
    ctx->r14 = SUB32(ctx->r11, ctx->r7);
    // 0x8001EE70: sh          $t6, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r14;
    // 0x8001EE74: jal         0x8001EB98
    // 0x8001EE78: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    syAudioDepth2Cents(rdram, ctx);
        goto after_6;
    // 0x8001EE78: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    after_6:
    // 0x8001EE7C: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x8001EE80: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8001EE84: nop

    // 0x8001EE88: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    // 0x8001EE8C: sll         $t8, $a1, 1
    ctx->r24 = S32(ctx->r5 << 1);
    // 0x8001EE90: sw          $a0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r4;
    // 0x8001EE94: jal         0x80036360
    // 0x8001EE98: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    alCents2Ratio(rdram, ctx);
        goto after_7;
    // 0x8001EE98: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    after_7:
    // 0x8001EE9C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_8001EEA0:
    // 0x8001EEA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001EEA4:
    // 0x8001EEA4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8001EEA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001EEAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001EEB0: jr          $ra
    // 0x8001EEB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001EEB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_80382C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382C24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80382C28: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80382C2C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80382C30: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382C34: beq         $a0, $zero, L_80382CC8
    if (ctx->r4 == 0) {
        // 0x80382C38: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80382CC8;
    }
    // 0x80382C38: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80382C3C: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80382C40: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80382C44: addiu       $t6, $t6, -0x3B20
    ctx->r14 = ADD32(ctx->r14, -0X3B20);
    // 0x80382C48: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80382C4C: addiu       $t7, $t7, -0x3A48
    ctx->r15 = ADD32(ctx->r15, -0X3A48);
    // 0x80382C50: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80382C54: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80382C58: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x80382C5C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80382C60: addiu       $t9, $t9, -0x38F0
    ctx->r25 = ADD32(ctx->r25, -0X38F0);
    // 0x80382C64: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80382C68: addiu       $t1, $t1, -0x38C8
    ctx->r9 = ADD32(ctx->r9, -0X38C8);
    // 0x80382C6C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80382C70: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x80382C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382C78: jal         0x8038120C
    // 0x80382C7C: sw          $t1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r9;
    func_ovl8_8038120C(rdram, ctx);
        goto after_0;
    // 0x80382C7C: sw          $t1, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r9;
    after_0:
    // 0x80382C80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80382C84: jal         0x8037F260
    // 0x80382C88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037F260(rdram, ctx);
        goto after_1;
    // 0x80382C88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80382C8C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80382C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382C94: beql        $t2, $zero, L_80382CB4
    if (ctx->r10 == 0) {
        // 0x80382C98: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80382CB4;
    }
    goto skip_0;
    // 0x80382C98: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80382C9C: jal         0x8037C30C
    // 0x80382CA0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_2;
    // 0x80382CA0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x80382CA4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80382CA8: jal         0x803718C4
    // 0x80382CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_3;
    // 0x80382CAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80382CB0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_80382CB4:
    // 0x80382CB4: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80382CB8: beql        $t4, $zero, L_80382CCC
    if (ctx->r12 == 0) {
        // 0x80382CBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80382CCC;
    }
    goto skip_1;
    // 0x80382CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80382CC0: jal         0x803717C0
    // 0x80382CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_4;
    // 0x80382CC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80382CC8:
    // 0x80382CC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80382CCC:
    // 0x80382CCC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80382CD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80382CD4: jr          $ra
    // 0x80382CD8: nop

    return;
    // 0x80382CD8: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152E48: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80152E4C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80152E50: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80152E54: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80152E58: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80152E5C: lb          $t7, 0x1C2($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1C2);
    // 0x80152E60: lb          $t8, 0x1C3($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1C3);
    // 0x80152E64: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80152E68: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80152E6C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80152E70: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80152E74: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80152E78: nop

    // 0x80152E7C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80152E80: jal         0x80033510
    // 0x80152E84: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80152E84: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80152E88: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80152E8C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80152E90: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80152E94: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80152E98: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x80152E9C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80152EA0: bc1fl       L_80152EB0
    if (!c1cs) {
        // 0x80152EA4: c.lt.s      $f2, $f16
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
            goto L_80152EB0;
    }
    goto skip_0;
    // 0x80152EA4: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    skip_0:
    // 0x80152EA8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80152EAC: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
L_80152EB0:
    // 0x80152EB0: nop

    // 0x80152EB4: bc1t        L_80152FC8
    if (c1cs) {
        // 0x80152EB8: nop
    
            goto L_80152FC8;
    }
    // 0x80152EB8: nop

    // 0x80152EBC: lw          $t9, 0xF4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XF4);
    // 0x80152EC0: andi        $t0, $t9, 0x4000
    ctx->r8 = ctx->r25 & 0X4000;
    // 0x80152EC4: bne         $t0, $zero, L_80152FC8
    if (ctx->r8 != 0) {
        // 0x80152EC8: nop
    
            goto L_80152FC8;
    }
    // 0x80152EC8: nop

    // 0x80152ECC: lb          $t1, 0x1C2($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1C2);
    // 0x80152ED0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80152ED4: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x80152ED8: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x80152EDC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80152EE0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80152EE4: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80152EE8: lb          $t2, 0x1C3($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X1C3);
    // 0x80152EEC: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    // 0x80152EF0: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x80152EF4: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80152EF8: nop

    // 0x80152EFC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80152F00: jal         0x800191FC
    // 0x80152F04: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_1;
    // 0x80152F04: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x80152F08: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80152F0C: lwc1        $f16, -0x3A94($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3A94);
    // 0x80152F10: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80152F14: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80152F18: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80152F1C: nop

    // 0x80152F20: bc1t        L_80152FC8
    if (c1cs) {
        // 0x80152F24: nop
    
            goto L_80152FC8;
    }
    // 0x80152F24: nop

    // 0x80152F28: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x80152F2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80152F30: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80152F34: nop

    // 0x80152F38: sw          $t4, 0xB24($s0)
    MEM_W(0XB24, ctx->r16) = ctx->r12;
    // 0x80152F3C: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80152F40: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80152F44: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80152F48: nop

    // 0x80152F4C: sw          $t6, 0xB28($s0)
    MEM_W(0XB28, ctx->r16) = ctx->r14;
    // 0x80152F50: jal         0x800E8044
    // 0x80152F54: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    ftParamSetStickLR(rdram, ctx);
        goto after_2;
    // 0x80152F54: swc1        $f2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80152F58: jal         0x80152E2C
    // 0x80152F5C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    ftPikachuSpecialHiInitStatusVarsZip(rdram, ctx);
        goto after_3;
    // 0x80152F5C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x80152F60: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80152F64: lwc1        $f2, 0x40($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80152F68: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80152F6C: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80152F70: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80152F74: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80152F78: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80152F7C: lw          $t7, 0xB1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB1C);
    // 0x80152F80: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80152F84: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80152F88: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80152F8C: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x80152F90: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80152F94: beq         $t7, $zero, L_80152FAC
    if (ctx->r15 == 0) {
        // 0x80152F98: swc1        $f4, 0x60($s0)
        MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
            goto L_80152FAC;
    }
    // 0x80152F98: swc1        $f4, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f4.u32l;
    // 0x80152F9C: lwc1        $f6, 0x60($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X60);
    // 0x80152FA0: lwc1        $f8, -0x3A90($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3A90);
    // 0x80152FA4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80152FA8: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
L_80152FAC:
    // 0x80152FAC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80152FB0: jal         0x800E6F24
    // 0x80152FB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_4;
    // 0x80152FB4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80152FB8: jal         0x800E0830
    // 0x80152FBC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_5;
    // 0x80152FBC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_5:
    // 0x80152FC0: b           L_80152FDC
    // 0x80152FC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80152FDC;
    // 0x80152FC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80152FC8:
    // 0x80152FC8: jal         0x800DEEC8
    // 0x80152FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_6;
    // 0x80152FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80152FD0: jal         0x80152FEC
    // 0x80152FD4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    ftPikachuSpecialAirHiSetStatus(rdram, ctx);
        goto after_7;
    // 0x80152FD4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_7:
    // 0x80152FD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80152FDC:
    // 0x80152FDC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80152FE0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80152FE4: jr          $ra
    // 0x80152FE8: nop

    return;
    // 0x80152FE8: nop

;}
RECOMP_FUNC void mnCharactersMakeEmblemCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133140: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133144: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80133148: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013314C: addiu       $t6, $t6, 0x7DBC
    ctx->r14 = ADD32(ctx->r14, 0X7DBC);
    // 0x80133150: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80133154: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133158: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8013315C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133160: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133164: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133168: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013316C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80133170: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80133174: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80133178: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013317C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133180: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133184: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133188: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013318C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133190: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133194: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133198: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013319C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801331A0: jal         0x8000B93C
    // 0x801331A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801331A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801331A8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801331AC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801331B0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801331B4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801331B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801331BC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801331C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801331C4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801331C8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801331CC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x801331D0: jal         0x80007080
    // 0x801331D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801331D4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801331D8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x801331DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801331E0: lui         $at, 0x44E1
    ctx->r1 = S32(0X44E1 << 16);
    // 0x801331E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801331E8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801331EC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801331F0: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x801331F4: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x801331F8: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x801331FC: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x80133200: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x80133204: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x80133208: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x8013320C: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x80133210: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x80133214: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133218: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8013321C: jr          $ra
    // 0x80133220: nop

    return;
    // 0x80133220: nop

;}
RECOMP_FUNC void MN1PContinueOptionSetHighlightColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801328D8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801328DC: addiu       $t6, $t6, 0x41D0
    ctx->r14 = ADD32(ctx->r14, 0X41D0);
    // 0x801328E0: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801328E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801328E8: addiu       $a2, $sp, 0xC
    ctx->r6 = ADD32(ctx->r29, 0XC);
    // 0x801328EC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x801328F0: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x801328F4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801328F8: addiu       $t9, $t9, 0x41D8
    ctx->r25 = ADD32(ctx->r25, 0X41D8);
    // 0x801328FC: sh          $t8, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r24;
    // 0x80132900: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80132904: addiu       $a3, $sp, 0x4
    ctx->r7 = ADD32(ctx->r29, 0X4);
    // 0x80132908: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8013290C: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80132910: lhu         $t1, 0x4($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X4);
    // 0x80132914: sh          $t1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r9;
    // 0x80132918: bne         $a1, $zero, L_80132928
    if (ctx->r5 != 0) {
        // 0x8013291C: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_80132928;
    }
    // 0x8013291C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132920: b           L_80132928
    // 0x80132924: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
        goto L_80132928;
    // 0x80132924: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80132928:
    // 0x80132928: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x8013292C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132930: sb          $t2, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r10;
    // 0x80132934: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x80132938: sb          $t3, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r11;
    // 0x8013293C: lbu         $t4, 0x2($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2);
    // 0x80132940: sb          $t4, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r12;
    // 0x80132944: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
    // 0x80132948: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x8013294C: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x80132950: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x80132954: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x80132958: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x8013295C: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x80132960: bne         $a1, $at, L_80132970
    if (ctx->r5 != ctx->r1) {
        // 0x80132964: lw          $v0, 0x8($t8)
        ctx->r2 = MEM_W(ctx->r24, 0X8);
            goto L_80132970;
    }
    // 0x80132964: lw          $v0, 0x8($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X8);
    // 0x80132968: b           L_80132974
    // 0x8013296C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
        goto L_80132974;
    // 0x8013296C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80132970:
    // 0x80132970: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_80132974:
    // 0x80132974: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80132978: sb          $t9, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r25;
    // 0x8013297C: lbu         $t0, 0x1($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X1);
    // 0x80132980: sb          $t0, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r8;
    // 0x80132984: lbu         $t1, 0x2($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X2);
    // 0x80132988: sb          $t1, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r9;
    // 0x8013298C: lbu         $t2, 0x3($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X3);
    // 0x80132990: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80132994: lbu         $t3, 0x4($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X4);
    // 0x80132998: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x8013299C: lbu         $t4, 0x5($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X5);
    // 0x801329A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801329A4: jr          $ra
    // 0x801329A8: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    return;
    // 0x801329A8: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
;}
RECOMP_FUNC void func_80027460_28060(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027460: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x80027464: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80027468: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8002746C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80027470: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80027474: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80027478: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8002747C: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x80027480: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x80027484: lhu         $v0, 0x28($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X28);
    // 0x80027488: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002748C: beq         $v0, $zero, L_80027A04
    if (ctx->r2 == 0) {
        // 0x80027490: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80027A04;
    }
    // 0x80027490: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80027494: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80027498: bne         $t7, $zero, L_80027A04
    if (ctx->r15 != 0) {
        // 0x8002749C: sh          $t6, 0x28($a0)
        MEM_H(0X28, ctx->r4) = ctx->r14;
            goto L_80027A04;
    }
    // 0x8002749C: sh          $t6, 0x28($a0)
    MEM_H(0X28, ctx->r4) = ctx->r14;
    // 0x800274A0: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800274A4: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x800274A8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800274AC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800274B0: lw          $s1, 0x20($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X20);
    // 0x800274B4: addiu       $s4, $s4, -0x1230
    ctx->r20 = ADD32(ctx->r20, -0X1230);
    // 0x800274B8: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
L_800274BC:
    // 0x800274BC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800274C0: andi        $v0, $v1, 0xF
    ctx->r2 = ctx->r3 & 0XF;
    // 0x800274C4: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x800274C8: andi        $t8, $a2, 0x8
    ctx->r24 = ctx->r6 & 0X8;
    // 0x800274CC: andi        $s3, $v0, 0xFFFF
    ctx->r19 = ctx->r2 & 0XFFFF;
    // 0x800274D0: beq         $t8, $zero, L_80027510
    if (ctx->r24 == 0) {
        // 0x800274D4: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80027510;
    }
    // 0x800274D4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800274D8: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x800274DC: andi        $s3, $a2, 0x7
    ctx->r19 = ctx->r6 & 0X7;
    // 0x800274E0: sll         $t9, $s3, 7
    ctx->r25 = S32(ctx->r19 << 7);
    // 0x800274E4: andi        $t2, $a0, 0x7F
    ctx->r10 = ctx->r4 & 0X7F;
    // 0x800274E8: addu        $s3, $t9, $t2
    ctx->r19 = ADD32(ctx->r25, ctx->r10);
    // 0x800274EC: andi        $t3, $a0, 0x80
    ctx->r11 = ctx->r4 & 0X80;
    // 0x800274F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800274F4: beq         $t3, $zero, L_80027510
    if (ctx->r11 == 0) {
        // 0x800274F8: andi        $s3, $s3, 0xFFFF
        ctx->r19 = ctx->r19 & 0XFFFF;
            goto L_80027510;
    }
    // 0x800274F8: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
    // 0x800274FC: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x80027500: sll         $t5, $s3, 8
    ctx->r13 = S32(ctx->r19 << 8);
    // 0x80027504: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80027508: addu        $s3, $t4, $t5
    ctx->r19 = ADD32(ctx->r12, ctx->r13);
    // 0x8002750C: andi        $s3, $s3, 0xFFFF
    ctx->r19 = ctx->r19 & 0XFFFF;
L_80027510:
    // 0x80027510: andi        $t6, $a1, 0xF0
    ctx->r14 = ctx->r5 & 0XF0;
    // 0x80027514: sltiu       $at, $t6, 0x91
    ctx->r1 = ctx->r14 < 0X91 ? 1 : 0;
    // 0x80027518: beq         $at, $zero, L_800279F4
    if (ctx->r1 == 0) {
        // 0x8002751C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_800279F4;
    }
    // 0x8002751C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80027520: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80027524: addu        $at, $at, $t6
    gpr jr_addend_8002752C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80027528: lw          $t6, -0x172C($at)
    ctx->r14 = ADD32(ctx->r1, -0X172C);
    // 0x8002752C: jr          $t6
    // 0x80027530: nop

    switch (jr_addend_8002752C >> 2) {
        case 0: goto L_80027534; break;
        case 1: goto L_800279F4; break;
        case 2: goto L_800279F4; break;
        case 3: goto L_800279F4; break;
        case 4: goto L_800279F4; break;
        case 5: goto L_800279F4; break;
        case 6: goto L_800279F4; break;
        case 7: goto L_800279F4; break;
        case 8: goto L_800279F4; break;
        case 9: goto L_800279F4; break;
        case 10: goto L_800279F4; break;
        case 11: goto L_800279F4; break;
        case 12: goto L_800279F4; break;
        case 13: goto L_800279F4; break;
        case 14: goto L_800279F4; break;
        case 15: goto L_800279F4; break;
        case 16: goto L_80027588; break;
        case 17: goto L_800279F4; break;
        case 18: goto L_800279F4; break;
        case 19: goto L_800279F4; break;
        case 20: goto L_800279F4; break;
        case 21: goto L_800279F4; break;
        case 22: goto L_800279F4; break;
        case 23: goto L_800279F4; break;
        case 24: goto L_800279F4; break;
        case 25: goto L_800279F4; break;
        case 26: goto L_800279F4; break;
        case 27: goto L_800279F4; break;
        case 28: goto L_800279F4; break;
        case 29: goto L_800279F4; break;
        case 30: goto L_800279F4; break;
        case 31: goto L_800279F4; break;
        case 32: goto L_800275DC; break;
        case 33: goto L_800279F4; break;
        case 34: goto L_800279F4; break;
        case 35: goto L_800279F4; break;
        case 36: goto L_800279F4; break;
        case 37: goto L_800279F4; break;
        case 38: goto L_800279F4; break;
        case 39: goto L_800279F4; break;
        case 40: goto L_800279F4; break;
        case 41: goto L_800279F4; break;
        case 42: goto L_800279F4; break;
        case 43: goto L_800279F4; break;
        case 44: goto L_800279F4; break;
        case 45: goto L_800279F4; break;
        case 46: goto L_800279F4; break;
        case 47: goto L_800279F4; break;
        case 48: goto L_80027664; break;
        case 49: goto L_800279F4; break;
        case 50: goto L_800279F4; break;
        case 51: goto L_800279F4; break;
        case 52: goto L_800279F4; break;
        case 53: goto L_800279F4; break;
        case 54: goto L_800279F4; break;
        case 55: goto L_800279F4; break;
        case 56: goto L_800279F4; break;
        case 57: goto L_800279F4; break;
        case 58: goto L_800279F4; break;
        case 59: goto L_800279F4; break;
        case 60: goto L_800279F4; break;
        case 61: goto L_800279F4; break;
        case 62: goto L_800279F4; break;
        case 63: goto L_800279F4; break;
        case 64: goto L_800276B8; break;
        case 65: goto L_800279F4; break;
        case 66: goto L_800279F4; break;
        case 67: goto L_800279F4; break;
        case 68: goto L_800279F4; break;
        case 69: goto L_800279F4; break;
        case 70: goto L_800279F4; break;
        case 71: goto L_800279F4; break;
        case 72: goto L_800279F4; break;
        case 73: goto L_800279F4; break;
        case 74: goto L_800279F4; break;
        case 75: goto L_800279F4; break;
        case 76: goto L_800279F4; break;
        case 77: goto L_800279F4; break;
        case 78: goto L_800279F4; break;
        case 79: goto L_800279F4; break;
        case 80: goto L_8002790C; break;
        case 81: goto L_800279F4; break;
        case 82: goto L_800279F4; break;
        case 83: goto L_800279F4; break;
        case 84: goto L_800279F4; break;
        case 85: goto L_800279F4; break;
        case 86: goto L_800279F4; break;
        case 87: goto L_800279F4; break;
        case 88: goto L_800279F4; break;
        case 89: goto L_800279F4; break;
        case 90: goto L_800279F4; break;
        case 91: goto L_800279F4; break;
        case 92: goto L_800279F4; break;
        case 93: goto L_800279F4; break;
        case 94: goto L_800279F4; break;
        case 95: goto L_800279F4; break;
        case 96: goto L_80027974; break;
        case 97: goto L_800279F4; break;
        case 98: goto L_800279F4; break;
        case 99: goto L_800279F4; break;
        case 100: goto L_800279F4; break;
        case 101: goto L_800279F4; break;
        case 102: goto L_800279F4; break;
        case 103: goto L_800279F4; break;
        case 104: goto L_800279F4; break;
        case 105: goto L_800279F4; break;
        case 106: goto L_800279F4; break;
        case 107: goto L_800279F4; break;
        case 108: goto L_800279F4; break;
        case 109: goto L_800279F4; break;
        case 110: goto L_800279F4; break;
        case 111: goto L_800279F4; break;
        case 112: goto L_800279D8; break;
        case 113: goto L_800279F4; break;
        case 114: goto L_800279F4; break;
        case 115: goto L_800279F4; break;
        case 116: goto L_800279F4; break;
        case 117: goto L_800279F4; break;
        case 118: goto L_800279F4; break;
        case 119: goto L_800279F4; break;
        case 120: goto L_800279F4; break;
        case 121: goto L_800279F4; break;
        case 122: goto L_800279F4; break;
        case 123: goto L_800279F4; break;
        case 124: goto L_800279F4; break;
        case 125: goto L_800279F4; break;
        case 126: goto L_800279F4; break;
        case 127: goto L_800279F4; break;
        case 128: goto L_800279E8; break;
        case 129: goto L_800279F4; break;
        case 130: goto L_800279F4; break;
        case 131: goto L_800279F4; break;
        case 132: goto L_800279F4; break;
        case 133: goto L_800279F4; break;
        case 134: goto L_800279F4; break;
        case 135: goto L_800279F4; break;
        case 136: goto L_800279F4; break;
        case 137: goto L_800279F4; break;
        case 138: goto L_800279F4; break;
        case 139: goto L_800279F4; break;
        case 140: goto L_800279F4; break;
        case 141: goto L_800279F4; break;
        case 142: goto L_800279F4; break;
        case 143: goto L_800279F4; break;
        case 144: goto L_800279F0; break;
        default: switch_error(__func__, 0x8002752C, 0x8003E8D4);
    }
    // 0x80027530: nop

L_80027534:
    // 0x80027534: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x80027538: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002753C: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x80027540: beq         $at, $zero, L_80027550
    if (ctx->r1 == 0) {
        // 0x80027544: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80027550;
    }
    // 0x80027544: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80027548: b           L_800279F4
    // 0x8002754C: sb          $a0, 0x32($s2)
    MEM_B(0X32, ctx->r18) = ctx->r4;
        goto L_800279F4;
    // 0x8002754C: sb          $a0, 0x32($s2)
    MEM_B(0X32, ctx->r18) = ctx->r4;
L_80027550:
    // 0x80027550: lbu         $t4, 0x32($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X32);
    // 0x80027554: addiu       $t3, $v0, -0xC0
    ctx->r11 = ADD32(ctx->r2, -0XC0);
    // 0x80027558: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x8002755C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80027560: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80027564: bgezl       $s0, L_80027574
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80027568: slti        $at, $s0, 0x80
        ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
            goto L_80027574;
    }
    goto skip_0;
    // 0x80027568: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    skip_0:
    // 0x8002756C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80027570: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
L_80027574:
    // 0x80027574: bne         $at, $zero, L_80027580
    if (ctx->r1 != 0) {
        // 0x80027578: nop
    
            goto L_80027580;
    }
    // 0x80027578: nop

    // 0x8002757C: addiu       $s0, $zero, 0x7F
    ctx->r16 = ADD32(0, 0X7F);
L_80027580:
    // 0x80027580: b           L_800279F4
    // 0x80027584: sb          $s0, 0x32($s2)
    MEM_B(0X32, ctx->r18) = ctx->r16;
        goto L_800279F4;
    // 0x80027584: sb          $s0, 0x32($s2)
    MEM_B(0X32, ctx->r18) = ctx->r16;
L_80027588:
    // 0x80027588: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x8002758C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80027590: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x80027594: beq         $at, $zero, L_800275A4
    if (ctx->r1 == 0) {
        // 0x80027598: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800275A4;
    }
    // 0x80027598: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8002759C: b           L_800279F4
    // 0x800275A0: sb          $a0, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r4;
        goto L_800279F4;
    // 0x800275A0: sb          $a0, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r4;
L_800275A4:
    // 0x800275A4: lbu         $t2, 0x34($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X34);
    // 0x800275A8: addiu       $t9, $v0, -0xC0
    ctx->r25 = ADD32(ctx->r2, -0XC0);
    // 0x800275AC: addu        $s0, $t9, $t2
    ctx->r16 = ADD32(ctx->r25, ctx->r10);
    // 0x800275B0: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x800275B4: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x800275B8: bgezl       $s0, L_800275C8
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800275BC: slti        $at, $s0, 0x80
        ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
            goto L_800275C8;
    }
    goto skip_1;
    // 0x800275BC: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    skip_1:
    // 0x800275C0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800275C4: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
L_800275C8:
    // 0x800275C8: bne         $at, $zero, L_800275D4
    if (ctx->r1 != 0) {
        // 0x800275CC: nop
    
            goto L_800275D4;
    }
    // 0x800275CC: nop

    // 0x800275D0: addiu       $s0, $zero, 0x7F
    ctx->r16 = ADD32(0, 0X7F);
L_800275D4:
    // 0x800275D4: b           L_800279F4
    // 0x800275D8: sb          $s0, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r16;
        goto L_800279F4;
    // 0x800275D8: sb          $s0, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r16;
L_800275DC:
    // 0x800275DC: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x800275E0: lbu         $t3, 0x1($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X1);
    // 0x800275E4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800275E8: sll         $a0, $a0, 8
    ctx->r4 = S32(ctx->r4 << 8);
    // 0x800275EC: or          $a0, $a0, $t3
    ctx->r4 = ctx->r4 | ctx->r11;
    // 0x800275F0: sll         $v1, $a0, 16
    ctx->r3 = S32(ctx->r4 << 16);
    // 0x800275F4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800275F8: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x800275FC: slti        $at, $v1, 0x4B1
    ctx->r1 = SIGNED(ctx->r3) < 0X4B1 ? 1 : 0;
    // 0x80027600: beq         $at, $zero, L_80027620
    if (ctx->r1 == 0) {
        // 0x80027604: sra         $s0, $s0, 16
        ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
            goto L_80027620;
    }
    // 0x80027604: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80027608: slti        $at, $v1, -0x4B0
    ctx->r1 = SIGNED(ctx->r3) < -0X4B0 ? 1 : 0;
    // 0x8002760C: beq         $at, $zero, L_80027618
    if (ctx->r1 == 0) {
        // 0x80027610: nop
    
            goto L_80027618;
    }
    // 0x80027610: nop

    // 0x80027614: addiu       $s0, $zero, -0x4B0
    ctx->r16 = ADD32(0, -0X4B0);
L_80027618:
    // 0x80027618: b           L_800279F4
    // 0x8002761C: sh          $s0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r16;
        goto L_800279F4;
    // 0x8002761C: sh          $s0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r16;
L_80027620:
    // 0x80027620: lh          $t4, 0x2C($s2)
    ctx->r12 = MEM_H(ctx->r18, 0X2C);
    // 0x80027624: addiu       $s0, $v1, -0x960
    ctx->r16 = ADD32(ctx->r3, -0X960);
    // 0x80027628: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8002762C: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80027630: addu        $s0, $s0, $t4
    ctx->r16 = ADD32(ctx->r16, ctx->r12);
    // 0x80027634: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80027638: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8002763C: slti        $at, $s0, -0x4B0
    ctx->r1 = SIGNED(ctx->r16) < -0X4B0 ? 1 : 0;
    // 0x80027640: beql        $at, $zero, L_80027650
    if (ctx->r1 == 0) {
        // 0x80027644: slti        $at, $s0, 0x4B1
        ctx->r1 = SIGNED(ctx->r16) < 0X4B1 ? 1 : 0;
            goto L_80027650;
    }
    goto skip_2;
    // 0x80027644: slti        $at, $s0, 0x4B1
    ctx->r1 = SIGNED(ctx->r16) < 0X4B1 ? 1 : 0;
    skip_2:
    // 0x80027648: addiu       $s0, $zero, -0x4B0
    ctx->r16 = ADD32(0, -0X4B0);
    // 0x8002764C: slti        $at, $s0, 0x4B1
    ctx->r1 = SIGNED(ctx->r16) < 0X4B1 ? 1 : 0;
L_80027650:
    // 0x80027650: bne         $at, $zero, L_8002765C
    if (ctx->r1 != 0) {
        // 0x80027654: nop
    
            goto L_8002765C;
    }
    // 0x80027654: nop

    // 0x80027658: addiu       $s0, $zero, 0x4B0
    ctx->r16 = ADD32(0, 0X4B0);
L_8002765C:
    // 0x8002765C: b           L_800279F4
    // 0x80027660: sh          $s0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r16;
        goto L_800279F4;
    // 0x80027660: sh          $s0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r16;
L_80027664:
    // 0x80027664: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x80027668: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002766C: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x80027670: beq         $at, $zero, L_80027680
    if (ctx->r1 == 0) {
        // 0x80027674: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_80027680;
    }
    // 0x80027674: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80027678: b           L_800279F4
    // 0x8002767C: sb          $a0, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r4;
        goto L_800279F4;
    // 0x8002767C: sb          $a0, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r4;
L_80027680:
    // 0x80027680: lbu         $t2, 0x36($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X36);
    // 0x80027684: addiu       $t9, $v0, -0xC0
    ctx->r25 = ADD32(ctx->r2, -0XC0);
    // 0x80027688: addu        $s0, $t9, $t2
    ctx->r16 = ADD32(ctx->r25, ctx->r10);
    // 0x8002768C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80027690: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80027694: bgezl       $s0, L_800276A4
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80027698: slti        $at, $s0, 0x80
        ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
            goto L_800276A4;
    }
    goto skip_3;
    // 0x80027698: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    skip_3:
    // 0x8002769C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800276A0: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
L_800276A4:
    // 0x800276A4: bne         $at, $zero, L_800276B0
    if (ctx->r1 != 0) {
        // 0x800276A8: nop
    
            goto L_800276B0;
    }
    // 0x800276A8: nop

    // 0x800276AC: addiu       $s0, $zero, 0x7F
    ctx->r16 = ADD32(0, 0X7F);
L_800276B0:
    // 0x800276B0: b           L_800279F4
    // 0x800276B4: sb          $s0, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r16;
        goto L_800279F4;
    // 0x800276B4: sb          $s0, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r16;
L_800276B8:
    // 0x800276B8: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x800276BC: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    // 0x800276C0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800276C4: andi        $t3, $a0, 0x80
    ctx->r11 = ctx->r4 & 0X80;
    // 0x800276C8: lhu         $v1, 0x2C($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X2C);
    // 0x800276CC: beq         $t3, $zero, L_800276F0
    if (ctx->r11 == 0) {
        // 0x800276D0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800276F0;
    }
    // 0x800276D0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800276D4: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x800276D8: andi        $t5, $v0, 0x7F
    ctx->r13 = ctx->r2 & 0X7F;
    // 0x800276DC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800276E0: addu        $a0, $t4, $t6
    ctx->r4 = ADD32(ctx->r12, ctx->r14);
    // 0x800276E4: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800276E8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800276EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800276F0:
    // 0x800276F0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800276F4: beq         $at, $zero, L_800279F4
    if (ctx->r1 == 0) {
        // 0x800276F8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800279F4;
    }
    // 0x800276F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800276FC: lw          $t7, 0x24($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X24);
    // 0x80027700: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x80027704: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80027708: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8002770C: lbu         $t9, 0x3($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3);
    // 0x80027710: lbu         $a3, 0x0($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X0);
    // 0x80027714: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x80027718: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8002771C: lbu         $t1, 0x2($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X2);
    // 0x80027720: bgez        $t9, L_80027734
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80027724: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80027734;
    }
    // 0x80027724: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80027728: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002772C: nop

    // 0x80027730: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80027734:
    // 0x80027734: swc1        $f6, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f6.u32l;
    // 0x80027738: lwc1        $f0, 0x4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X4);
    // 0x8002773C: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80027740: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80027744: lw          $v1, 0x44($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X44);
L_80027748:
    // 0x80027748: bnel        $v1, $zero, L_80027780
    if (ctx->r3 != 0) {
        // 0x8002774C: lbu         $a0, 0x4($v1)
        ctx->r4 = MEM_BU(ctx->r3, 0X4);
            goto L_80027780;
    }
    goto skip_4;
    // 0x8002774C: lbu         $a0, 0x4($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X4);
    skip_4:
    // 0x80027750: lw          $s0, 0x30($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X30);
    // 0x80027754: beq         $s0, $zero, L_800277E0
    if (ctx->r16 == 0) {
        // 0x80027758: nop
    
            goto L_800277E0;
    }
    // 0x80027758: nop

    // 0x8002775C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x80027760: sw          $t2, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->r10;
    // 0x80027764: beq         $a1, $zero, L_80027774
    if (ctx->r5 == 0) {
        // 0x80027768: sw          $zero, 0x0($s0)
        MEM_W(0X0, ctx->r16) = 0;
            goto L_80027774;
    }
    // 0x80027768: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8002776C: b           L_800277E0
    // 0x80027770: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
        goto L_800277E0;
    // 0x80027770: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
L_80027774:
    // 0x80027774: b           L_800277E0
    // 0x80027778: sw          $s0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r16;
        goto L_800277E0;
    // 0x80027778: sw          $s0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r16;
    // 0x8002777C: lbu         $a0, 0x4($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X4);
L_80027780:
    // 0x80027780: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80027784: bne         $a0, $a2, L_80027794
    if (ctx->r4 != ctx->r6) {
        // 0x80027788: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80027794;
    }
    // 0x80027788: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8002778C: b           L_800277E0
    // 0x80027790: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
        goto L_800277E0;
    // 0x80027790: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_80027794:
    // 0x80027794: beql        $at, $zero, L_800277D8
    if (ctx->r1 == 0) {
        // 0x80027798: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_800277D8;
    }
    goto skip_5;
    // 0x80027798: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    skip_5:
    // 0x8002779C: lw          $s0, 0x30($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X30);
    // 0x800277A0: beq         $s0, $zero, L_800277E0
    if (ctx->r16 == 0) {
        // 0x800277A4: nop
    
            goto L_800277E0;
    }
    // 0x800277A4: nop

    // 0x800277A8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800277AC: beq         $a1, $zero, L_800277C4
    if (ctx->r5 == 0) {
        // 0x800277B0: sw          $t3, 0x30($s4)
        MEM_W(0X30, ctx->r20) = ctx->r11;
            goto L_800277C4;
    }
    // 0x800277B0: sw          $t3, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->r11;
    // 0x800277B4: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800277B8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800277BC: b           L_800277E0
    // 0x800277C0: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
        goto L_800277E0;
    // 0x800277C0: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
L_800277C4:
    // 0x800277C4: lw          $t4, 0x44($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X44);
    // 0x800277C8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800277CC: b           L_800277E0
    // 0x800277D0: sw          $s0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r16;
        goto L_800277E0;
    // 0x800277D0: sw          $s0, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r16;
    // 0x800277D4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_800277D8:
    // 0x800277D8: b           L_80027748
    // 0x800277DC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
        goto L_80027748;
    // 0x800277DC: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
L_800277E0:
    // 0x800277E0: beq         $s0, $zero, L_800279F4
    if (ctx->r16 == 0) {
        // 0x800277E4: lwc1        $f10, 0x9C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
            goto L_800279F4;
    }
    // 0x800277E4: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800277E8: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800277EC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800277F0: sb          $a2, 0x4($s0)
    MEM_B(0X4, ctx->r16) = ctx->r6;
    // 0x800277F4: sb          $a3, 0x5($s0)
    MEM_B(0X5, ctx->r16) = ctx->r7;
    // 0x800277F8: sb          $t0, 0x6($s0)
    MEM_B(0X6, ctx->r16) = ctx->r8;
    // 0x800277FC: sb          $t1, 0x7($s0)
    MEM_B(0X7, ctx->r16) = ctx->r9;
    // 0x80027800: swc1        $f0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f0.u32l;
    // 0x80027804: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80027808: swc1        $f2, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f2.u32l;
    // 0x8002780C: swc1        $f12, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f12.u32l;
    // 0x80027810: beq         $a3, $at, L_80027834
    if (ctx->r7 == ctx->r1) {
        // 0x80027814: swc1        $f4, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
            goto L_80027834;
    }
    // 0x80027814: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80027818: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8002781C: beq         $a3, $at, L_80027878
    if (ctx->r7 == ctx->r1) {
        // 0x80027820: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80027878;
    }
    // 0x80027820: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80027824: beq         $a3, $at, L_800278C8
    if (ctx->r7 == ctx->r1) {
        // 0x80027828: nop
    
            goto L_800278C8;
    }
    // 0x80027828: nop

    // 0x8002782C: b           L_800279F4
    // 0x80027830: nop

        goto L_800279F4;
    // 0x80027830: nop

L_80027834:
    // 0x80027834: jal         0x800273F4
    // 0x80027838: nop

    randFloat2(rdram, ctx);
        goto after_0;
    // 0x80027838: nop

    after_0:
    // 0x8002783C: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027840: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027844: mul.s       $f6, $f0, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80027848: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x8002784C: jal         0x800273F4
    // 0x80027850: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    randFloat2(rdram, ctx);
        goto after_1;
    // 0x80027850: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    after_1:
    // 0x80027854: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027858: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8002785C: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
    // 0x80027860: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80027864: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80027868: nop

    // 0x8002786C: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x80027870: b           L_800279F4
    // 0x80027874: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
        goto L_800279F4;
    // 0x80027874: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
L_80027878:
    // 0x80027878: jal         0x800273F4
    // 0x8002787C: swc1        $f22, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f22.u32l;
    randFloat2(rdram, ctx);
        goto after_2;
    // 0x8002787C: swc1        $f22, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f22.u32l;
    after_2:
    // 0x80027880: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027884: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027888: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8002788C: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80027890: jal         0x800273F4
    // 0x80027894: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    randFloat2(rdram, ctx);
        goto after_3;
    // 0x80027894: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    after_3:
    // 0x80027898: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8002789C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800278A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800278A4: mul.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800278A8: add.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800278AC: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
    // 0x800278B0: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800278B4: mul.s       $f6, $f2, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800278B8: nop

    // 0x800278BC: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800278C0: b           L_800279F4
    // 0x800278C4: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
        goto L_800279F4;
    // 0x800278C4: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
L_800278C8:
    // 0x800278C8: jal         0x80027390
    // 0x800278CC: nop

    randFloat1(rdram, ctx);
        goto after_4;
    // 0x800278CC: nop

    after_4:
    // 0x800278D0: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800278D4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800278D8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800278DC: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800278E0: jal         0x80027390
    // 0x800278E4: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    randFloat1(rdram, ctx);
        goto after_5;
    // 0x800278E4: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    after_5:
    // 0x800278E8: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800278EC: mul.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800278F0: swc1        $f2, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f2.u32l;
    // 0x800278F4: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800278F8: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x800278FC: nop

    // 0x80027900: mul.s       $f8, $f4, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80027904: b           L_800279F4
    // 0x80027908: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
        goto L_800279F4;
    // 0x80027908: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
L_8002790C:
    // 0x8002790C: lw          $v1, 0x44($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X44);
    // 0x80027910: lbu         $a2, 0x0($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X0);
    // 0x80027914: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80027918: beq         $v1, $zero, L_800279F4
    if (ctx->r3 == 0) {
        // 0x8002791C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800279F4;
    }
    // 0x8002791C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80027920: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80027924: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
L_80027928:
    // 0x80027928: bnel        $t6, $v0, L_80027960
    if (ctx->r14 != ctx->r2) {
        // 0x8002792C: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_80027960;
    }
    goto skip_6;
    // 0x8002792C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    skip_6:
    // 0x80027930: bnel        $a1, $zero, L_80027948
    if (ctx->r5 != 0) {
        // 0x80027934: lw          $t8, 0x0($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X0);
            goto L_80027948;
    }
    goto skip_7;
    // 0x80027934: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    skip_7:
    // 0x80027938: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002793C: b           L_8002794C
    // 0x80027940: sw          $t7, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r15;
        goto L_8002794C;
    // 0x80027940: sw          $t7, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r15;
    // 0x80027944: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
L_80027948:
    // 0x80027948: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_8002794C:
    // 0x8002794C: lw          $t9, 0x30($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X30);
    // 0x80027950: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80027954: b           L_800279F4
    // 0x80027958: sw          $v1, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->r3;
        goto L_800279F4;
    // 0x80027958: sw          $v1, 0x30($s4)
    MEM_W(0X30, ctx->r20) = ctx->r3;
    // 0x8002795C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
L_80027960:
    // 0x80027960: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80027964: bnel        $v1, $zero, L_80027928
    if (ctx->r3 != 0) {
        // 0x80027968: lbu         $t6, 0x4($v1)
        ctx->r14 = MEM_BU(ctx->r3, 0X4);
            goto L_80027928;
    }
    goto skip_8;
    // 0x80027968: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    skip_8:
    // 0x8002796C: b           L_800279F4
    // 0x80027970: nop

        goto L_800279F4;
    // 0x80027970: nop

L_80027974:
    // 0x80027974: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    // 0x80027978: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002797C: lhu         $v1, 0x14($s4)
    ctx->r3 = MEM_HU(ctx->r20, 0X14);
    // 0x80027980: andi        $t2, $a0, 0x80
    ctx->r10 = ctx->r4 & 0X80;
    // 0x80027984: beq         $t2, $zero, L_800279A8
    if (ctx->r10 == 0) {
        // 0x80027988: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800279A8;
    }
    // 0x80027988: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8002798C: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x80027990: andi        $t5, $v0, 0x7F
    ctx->r13 = ctx->r2 & 0X7F;
    // 0x80027994: sll         $t4, $t5, 8
    ctx->r12 = S32(ctx->r13 << 8);
    // 0x80027998: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x8002799C: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x800279A0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800279A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800279A8:
    // 0x800279A8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800279AC: beq         $at, $zero, L_800279F4
    if (ctx->r1 == 0) {
        // 0x800279B0: nop
    
            goto L_800279F4;
    }
    // 0x800279B0: nop

    // 0x800279B4: lw          $t6, 0x18($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X18);
    // 0x800279B8: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800279BC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800279C0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800279C4: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800279C8: lw          $t2, 0x8($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X8);
    // 0x800279CC: sb          $t5, 0x2A($s2)
    MEM_B(0X2A, ctx->r18) = ctx->r13;
    // 0x800279D0: b           L_800279F4
    // 0x800279D4: sw          $t2, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r10;
        goto L_800279F4;
    // 0x800279D4: sw          $t2, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r10;
L_800279D8:
    // 0x800279D8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x800279DC: sb          $t3, 0x2A($s2)
    MEM_B(0X2A, ctx->r18) = ctx->r11;
    // 0x800279E0: b           L_800279F4
    // 0x800279E4: addiu       $s3, $zero, 0x2710
    ctx->r19 = ADD32(0, 0X2710);
        goto L_800279F4;
    // 0x800279E4: addiu       $s3, $zero, 0x2710
    ctx->r19 = ADD32(0, 0X2710);
L_800279E8:
    // 0x800279E8: b           L_800279F4
    // 0x800279EC: sw          $s1, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r17;
        goto L_800279F4;
    // 0x800279EC: sw          $s1, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r17;
L_800279F0:
    // 0x800279F0: lw          $s1, 0x24($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X24);
L_800279F4:
    // 0x800279F4: beql        $s3, $zero, L_800274BC
    if (ctx->r19 == 0) {
        // 0x800279F8: lbu         $v1, 0x0($s1)
        ctx->r3 = MEM_BU(ctx->r17, 0X0);
            goto L_800274BC;
    }
    goto skip_9;
    // 0x800279F8: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    skip_9:
    // 0x800279FC: sw          $s1, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r17;
    // 0x80027A00: sh          $s3, 0x28($s2)
    MEM_H(0X28, ctx->r18) = ctx->r19;
L_80027A04:
    // 0x80027A04: lw          $s0, 0x44($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X44);
    // 0x80027A08: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x80027A0C: addiu       $s4, $s4, -0x1230
    ctx->r20 = ADD32(ctx->r20, -0X1230);
    // 0x80027A10: beq         $s0, $zero, L_800280FC
    if (ctx->r16 == 0) {
        // 0x80027A14: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800280FC;
    }
    // 0x80027A14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80027A18: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80027A1C: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80027A20: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80027A24: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027A28: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80027A2C: addiu       $s3, $s3, -0x46B0
    ctx->r19 = ADD32(ctx->r19, -0X46B0);
    // 0x80027A30: addiu       $s1, $sp, 0xC0
    ctx->r17 = ADD32(ctx->r29, 0XC0);
    // 0x80027A34: lbu         $t4, 0x5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X5);
L_80027A38:
    // 0x80027A38: slti        $at, $t4, 0x4
    ctx->r1 = SIGNED(ctx->r12) < 0X4 ? 1 : 0;
    // 0x80027A3C: beql        $at, $zero, L_80027A74
    if (ctx->r1 == 0) {
        // 0x80027A40: lbu         $t6, 0x5($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X5);
            goto L_80027A74;
    }
    goto skip_10;
    // 0x80027A40: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
    skip_10:
    // 0x80027A44: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027A48: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027A4C: add.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80027A50: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80027A54: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027A58: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80027A5C: nop

    // 0x80027A60: bc1fl       L_80027A74
    if (!c1cs) {
        // 0x80027A64: lbu         $t6, 0x5($s0)
        ctx->r14 = MEM_BU(ctx->r16, 0X5);
            goto L_80027A74;
    }
    goto skip_11;
    // 0x80027A64: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
    skip_11:
    // 0x80027A68: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80027A6C: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x80027A70: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
L_80027A74:
    // 0x80027A74: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x80027A78: beq         $at, $zero, L_80027D84
    if (ctx->r1 == 0) {
        // 0x80027A7C: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_80027D84;
    }
    // 0x80027A7C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80027A80: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80027A84: addu        $at, $at, $t6
    gpr jr_addend_80027A8C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80027A88: lw          $t6, -0x14E8($at)
    ctx->r14 = ADD32(ctx->r1, -0X14E8);
    // 0x80027A8C: jr          $t6
    // 0x80027A90: nop

    switch (jr_addend_80027A8C >> 2) {
        case 0: goto L_80027A94; break;
        case 1: goto L_80027B28; break;
        case 2: goto L_80027B5C; break;
        case 3: goto L_80027B7C; break;
        case 4: goto L_80027BA0; break;
        case 5: goto L_80027C04; break;
        case 6: goto L_80027C94; break;
        case 7: goto L_80027CD8; break;
        case 8: goto L_80027D20; break;
        default: switch_error(__func__, 0x80027A8C, 0x8003EB18);
    }
    // 0x80027A90: nop

L_80027A94:
    // 0x80027A94: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027A98: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027A9C: lui         $at, 0x4580
    ctx->r1 = S32(0X4580 << 16);
    // 0x80027AA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80027AA4: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80027AA8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80027AAC: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80027AB0: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80027AB4: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80027AB8: nop

    // 0x80027ABC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80027AC0: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80027AC4: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x80027AC8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80027ACC: addu        $t2, $s3, $t9
    ctx->r10 = ADD32(ctx->r19, ctx->r25);
    // 0x80027AD0: lhu         $t5, 0x0($t2)
    ctx->r13 = MEM_HU(ctx->r10, 0X0);
    // 0x80027AD4: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80027AD8: bgez        $t5, L_80027AEC
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80027ADC: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80027AEC;
    }
    // 0x80027ADC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80027AE0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80027AE4: nop

    // 0x80027AE8: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_80027AEC:
    // 0x80027AEC: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80027AF0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80027AF4: andi        $t3, $v0, 0x800
    ctx->r11 = ctx->r2 & 0X800;
    // 0x80027AF8: beq         $t3, $zero, L_80027B08
    if (ctx->r11 == 0) {
        // 0x80027AFC: div.s       $f2, $f8, $f10
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
            goto L_80027B08;
    }
    // 0x80027AFC: div.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80027B00: b           L_80027B0C
    // 0x80027B04: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_80027B0C;
    // 0x80027B04: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
L_80027B08:
    // 0x80027B08: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80027B0C:
    // 0x80027B0C: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027B10: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027B14: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80027B18: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80027B1C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027B20: b           L_80027D88
    // 0x80027B24: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
        goto L_80027D88;
    // 0x80027B24: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
L_80027B28:
    // 0x80027B28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80027B2C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80027B30: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027B34: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027B38: div.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80027B3C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80027B40: nop

    // 0x80027B44: bc1f        L_80027B54
    if (!c1cs) {
        // 0x80027B48: nop
    
            goto L_80027B54;
    }
    // 0x80027B48: nop

    // 0x80027B4C: b           L_80027D88
    // 0x80027B50: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
        goto L_80027D88;
    // 0x80027B50: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
L_80027B54:
    // 0x80027B54: b           L_80027D88
    // 0x80027B58: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
        goto L_80027D88;
    // 0x80027B58: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
L_80027B5C:
    // 0x80027B5C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027B60: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027B64: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027B68: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80027B6C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027B70: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80027B74: b           L_80027D88
    // 0x80027B78: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
        goto L_80027D88;
    // 0x80027B78: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
L_80027B7C:
    // 0x80027B7C: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027B80: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027B84: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027B88: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x80027B8C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027B90: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80027B94: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80027B98: b           L_80027D88
    // 0x80027B9C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
        goto L_80027D88;
    // 0x80027B9C: add.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f10.fl;
L_80027BA0:
    // 0x80027BA0: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027BA4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80027BA8: add.s       $f18, $f8, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80027BAC: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x80027BB0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027BB4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80027BB8: nop

    // 0x80027BBC: bc1f        L_80027BFC
    if (!c1cs) {
        // 0x80027BC0: nop
    
            goto L_80027BFC;
    }
    // 0x80027BC0: nop

    // 0x80027BC4: jal         0x800273F4
    // 0x80027BC8: nop

    randFloat2(rdram, ctx);
        goto after_6;
    // 0x80027BC8: nop

    after_6:
    // 0x80027BCC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027BD0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027BD4: mul.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80027BD8: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80027BDC: jal         0x800273F4
    // 0x80027BE0: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    randFloat2(rdram, ctx);
        goto after_7;
    // 0x80027BE0: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    after_7:
    // 0x80027BE4: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027BE8: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80027BEC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027BF0: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80027BF4: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x80027BF8: swc1        $f10, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f10.u32l;
L_80027BFC:
    // 0x80027BFC: b           L_80027D88
    // 0x80027C00: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
        goto L_80027D88;
    // 0x80027C00: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
L_80027C04:
    // 0x80027C04: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027C08: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80027C0C: add.s       $f18, $f8, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80027C10: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x80027C14: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027C18: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80027C1C: nop

    // 0x80027C20: bc1fl       L_80027C74
    if (!c1cs) {
        // 0x80027C24: lwc1        $f0, 0x1C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
            goto L_80027C74;
    }
    goto skip_12;
    // 0x80027C24: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
    skip_12:
    // 0x80027C28: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80027C2C: jal         0x800273F4
    // 0x80027C30: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    randFloat2(rdram, ctx);
        goto after_8;
    // 0x80027C30: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_8:
    // 0x80027C34: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027C38: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027C3C: mul.s       $f10, $f0, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80027C40: add.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80027C44: jal         0x800273F4
    // 0x80027C48: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    randFloat2(rdram, ctx);
        goto after_9;
    // 0x80027C48: swc1        $f18, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f18.u32l;
    after_9:
    // 0x80027C4C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027C50: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80027C54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80027C58: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80027C5C: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x80027C60: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027C64: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80027C68: swc1        $f8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f8.u32l;
    // 0x80027C6C: lwc1        $f14, 0x18($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80027C70: lwc1        $f0, 0x1C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X1C);
L_80027C74:
    // 0x80027C74: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80027C78: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80027C7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027C80: sub.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80027C84: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80027C88: div.s       $f10, $f6, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f14.fl);
    // 0x80027C8C: b           L_80027D88
    // 0x80027C90: add.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f0.fl;
        goto L_80027D88;
    // 0x80027C90: add.s       $f12, $f10, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f0.fl;
L_80027C94:
    // 0x80027C94: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027C98: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027C9C: add.s       $f18, $f8, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80027CA0: swc1        $f18, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f18.u32l;
    // 0x80027CA4: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027CA8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80027CAC: nop

    // 0x80027CB0: bc1fl       L_80027CC4
    if (!c1cs) {
        // 0x80027CB4: lwc1        $f4, 0xC($s0)
        ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
            goto L_80027CC4;
    }
    goto skip_13;
    // 0x80027CB4: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    skip_13:
    // 0x80027CB8: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80027CBC: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027CC0: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
L_80027CC4:
    // 0x80027CC4: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027CC8: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80027CCC: div.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80027CD0: b           L_80027D88
    // 0x80027CD4: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
        goto L_80027D88;
    // 0x80027CD4: add.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f8.fl;
L_80027CD8:
    // 0x80027CD8: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027CDC: lwc1        $f0, 0x8($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027CE0: add.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f22.fl;
    // 0x80027CE4: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80027CE8: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027CEC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80027CF0: nop

    // 0x80027CF4: bc1fl       L_80027D08
    if (!c1cs) {
        // 0x80027CF8: sub.s       $f10, $f0, $f2
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_80027D08;
    }
    goto skip_14;
    // 0x80027CF8: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    skip_14:
    // 0x80027CFC: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80027D00: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027D04: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
L_80027D08:
    // 0x80027D08: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027D0C: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027D10: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80027D14: div.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80027D18: b           L_80027D88
    // 0x80027D1C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
        goto L_80027D88;
    // 0x80027D1C: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
L_80027D20:
    // 0x80027D20: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027D24: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x80027D28: add.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80027D2C: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
    // 0x80027D30: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80027D34: c.lt.s      $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f8.fl < ctx->f18.fl;
    // 0x80027D38: nop

    // 0x80027D3C: bc1f        L_80027D7C
    if (!c1cs) {
        // 0x80027D40: nop
    
            goto L_80027D7C;
    }
    // 0x80027D40: nop

    // 0x80027D44: jal         0x80027390
    // 0x80027D48: nop

    randFloat1(rdram, ctx);
        goto after_10;
    // 0x80027D48: nop

    after_10:
    // 0x80027D4C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80027D50: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80027D54: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80027D58: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80027D5C: jal         0x80027390
    // 0x80027D60: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    randFloat1(rdram, ctx);
        goto after_11;
    // 0x80027D60: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    after_11:
    // 0x80027D64: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80027D68: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80027D6C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80027D70: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80027D74: swc1        $f20, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f20.u32l;
    // 0x80027D78: swc1        $f4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f4.u32l;
L_80027D7C:
    // 0x80027D7C: b           L_80027D88
    // 0x80027D80: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
        goto L_80027D88;
    // 0x80027D80: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
L_80027D84:
    // 0x80027D84: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
L_80027D88:
    // 0x80027D88: lbu         $v0, 0x7($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X7);
    // 0x80027D8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80027D90: sra         $v1, $v0, 4
    ctx->r3 = S32(SIGNED(ctx->r2) >> 4);
    // 0x80027D94: beq         $v1, $at, L_80027DB0
    if (ctx->r3 == ctx->r1) {
        // 0x80027D98: andi        $t4, $v0, 0xF
        ctx->r12 = ctx->r2 & 0XF;
            goto L_80027DB0;
    }
    // 0x80027D98: andi        $t4, $v0, 0xF
    ctx->r12 = ctx->r2 & 0XF;
    // 0x80027D9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80027DA0: beq         $v1, $at, L_80027DC4
    if (ctx->r3 == ctx->r1) {
        // 0x80027DA4: andi        $t8, $v0, 0xF
        ctx->r24 = ctx->r2 & 0XF;
            goto L_80027DC4;
    }
    // 0x80027DA4: andi        $t8, $v0, 0xF
    ctx->r24 = ctx->r2 & 0XF;
    // 0x80027DA8: b           L_80027DDC
    // 0x80027DAC: lbu         $a0, 0x6($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X6);
        goto L_80027DDC;
    // 0x80027DAC: lbu         $a0, 0x6($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X6);
L_80027DB0:
    // 0x80027DB0: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80027DB4: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80027DB8: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x80027DBC: b           L_80027DD8
    // 0x80027DC0: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
        goto L_80027DD8;
    // 0x80027DC0: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_80027DC4:
    // 0x80027DC4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80027DC8: addu        $t2, $s1, $t9
    ctx->r10 = ADD32(ctx->r17, ctx->r25);
    // 0x80027DCC: lwc1        $f10, 0x0($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X0);
    // 0x80027DD0: mul.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x80027DD4: nop

L_80027DD8:
    // 0x80027DD8: lbu         $a0, 0x6($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X6);
L_80027DDC:
    // 0x80027DDC: addiu       $t5, $a0, -0xA
    ctx->r13 = ADD32(ctx->r4, -0XA);
    // 0x80027DE0: sltiu       $at, $t5, 0x6
    ctx->r1 = ctx->r13 < 0X6 ? 1 : 0;
    // 0x80027DE4: beq         $at, $zero, L_80028014
    if (ctx->r1 == 0) {
        // 0x80027DE8: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_80028014;
    }
    // 0x80027DE8: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80027DEC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80027DF0: addu        $at, $at, $t5
    gpr jr_addend_80027DF8 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80027DF4: lw          $t5, -0x14C4($at)
    ctx->r13 = ADD32(ctx->r1, -0X14C4);
    // 0x80027DF8: jr          $t5
    // 0x80027DFC: nop

    switch (jr_addend_80027DF8 >> 2) {
        case 0: goto L_80027E24; break;
        case 1: goto L_80027E00; break;
        case 2: goto L_80027EE8; break;
        case 3: goto L_80027ED4; break;
        case 4: goto L_80027F64; break;
        case 5: goto L_80027F40; break;
        default: switch_error(__func__, 0x80027DF8, 0x8003EB3C);
    }
    // 0x80027DFC: nop

L_80027E00:
    // 0x80027E00: lbu         $t3, 0x32($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X32);
    // 0x80027E04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80027E08: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x80027E0C: bgez        $t3, L_80027E20
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80027E10: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80027E20;
    }
    // 0x80027E10: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80027E14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027E18: nop

    // 0x80027E1C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80027E20:
    // 0x80027E20: add.s       $f12, $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f18.fl;
L_80027E24:
    // 0x80027E24: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x80027E28: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80027E2C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80027E30: bc1fl       L_80027E40
    if (!c1cs) {
        // 0x80027E34: c.lt.s      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
            goto L_80027E40;
    }
    goto skip_15;
    // 0x80027E34: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    skip_15:
    // 0x80027E38: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80027E3C: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
L_80027E40:
    // 0x80027E40: nop

    // 0x80027E44: bc1fl       L_80027E54
    if (!c1cs) {
        // 0x80027E48: cfc1        $t4, $FpcCsr
        ctx->r12 = get_cop1_cs();
            goto L_80027E54;
    }
    goto skip_16;
    // 0x80027E48: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    skip_16:
    // 0x80027E4C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x80027E50: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
L_80027E54:
    // 0x80027E54: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80027E58: nop

    // 0x80027E5C: cvt.w.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80027E60: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80027E64: nop

    // 0x80027E68: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80027E6C: beql        $t6, $zero, L_80027EBC
    if (ctx->r14 == 0) {
        // 0x80027E70: mfc1        $t6, $f6
        ctx->r14 = (int32_t)ctx->f6.u32l;
            goto L_80027EBC;
    }
    goto skip_17;
    // 0x80027E70: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    skip_17:
    // 0x80027E74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80027E78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80027E7C: sub.s       $f6, $f12, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80027E80: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80027E84: nop

    // 0x80027E88: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80027E8C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80027E90: nop

    // 0x80027E94: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x80027E98: bne         $t6, $zero, L_80027EB0
    if (ctx->r14 != 0) {
        // 0x80027E9C: nop
    
            goto L_80027EB0;
    }
    // 0x80027E9C: nop

    // 0x80027EA0: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x80027EA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80027EA8: b           L_80027EC8
    // 0x80027EAC: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_80027EC8;
    // 0x80027EAC: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_80027EB0:
    // 0x80027EB0: b           L_80027EC8
    // 0x80027EB4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_80027EC8;
    // 0x80027EB4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80027EB8: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
L_80027EBC:
    // 0x80027EBC: nop

    // 0x80027EC0: bltz        $t6, L_80027EB0
    if (SIGNED(ctx->r14) < 0) {
        // 0x80027EC4: nop
    
            goto L_80027EB0;
    }
    // 0x80027EC4: nop

L_80027EC8:
    // 0x80027EC8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80027ECC: b           L_800280F0
    // 0x80027ED0: sb          $t6, 0x32($s2)
    MEM_B(0X32, ctx->r18) = ctx->r14;
        goto L_800280F0;
    // 0x80027ED0: sb          $t6, 0x32($s2)
    MEM_B(0X32, ctx->r18) = ctx->r14;
L_80027ED4:
    // 0x80027ED4: lh          $t7, 0x2C($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X2C);
    // 0x80027ED8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80027EDC: nop

    // 0x80027EE0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80027EE4: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_80027EE8:
    // 0x80027EE8: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x80027EEC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027EF0: lui         $at, 0xC496
    ctx->r1 = S32(0XC496 << 16);
    // 0x80027EF4: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80027EF8: nop

    // 0x80027EFC: bc1fl       L_80027F10
    if (!c1cs) {
        // 0x80027F00: lui         $at, 0x4496
        ctx->r1 = S32(0X4496 << 16);
            goto L_80027F10;
    }
    goto skip_18;
    // 0x80027F00: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    skip_18:
    // 0x80027F04: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80027F08: nop

    // 0x80027F0C: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
L_80027F10:
    // 0x80027F10: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027F14: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x80027F18: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x80027F1C: nop

    // 0x80027F20: bc1fl       L_80027F34
    if (!c1cs) {
        // 0x80027F24: trunc.w.s   $f6, $f12
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
            goto L_80027F34;
    }
    goto skip_19;
    // 0x80027F24: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
    skip_19:
    // 0x80027F28: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80027F2C: nop

    // 0x80027F30: trunc.w.s   $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    ctx->f6.u32l = TRUNC_W_S(ctx->f12.fl);
L_80027F34:
    // 0x80027F34: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80027F38: b           L_800280F0
    // 0x80027F3C: sh          $t9, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r25;
        goto L_800280F0;
    // 0x80027F3C: sh          $t9, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r25;
L_80027F40:
    // 0x80027F40: lbu         $t2, 0x34($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X34);
    // 0x80027F44: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80027F48: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x80027F4C: bgez        $t2, L_80027F60
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80027F50: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80027F60;
    }
    // 0x80027F50: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80027F54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80027F58: nop

    // 0x80027F5C: add.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f4.fl;
L_80027F60:
    // 0x80027F60: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_80027F64:
    // 0x80027F64: c.lt.s      $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f12.fl < ctx->f20.fl;
    // 0x80027F68: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80027F6C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80027F70: bc1fl       L_80027F80
    if (!c1cs) {
        // 0x80027F74: c.lt.s      $f16, $f12
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
            goto L_80027F80;
    }
    goto skip_20;
    // 0x80027F74: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    skip_20:
    // 0x80027F78: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80027F7C: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
L_80027F80:
    // 0x80027F80: nop

    // 0x80027F84: bc1fl       L_80027F94
    if (!c1cs) {
        // 0x80027F88: cfc1        $t5, $FpcCsr
        ctx->r13 = get_cop1_cs();
            goto L_80027F94;
    }
    goto skip_21;
    // 0x80027F88: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    skip_21:
    // 0x80027F8C: mov.s       $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = ctx->f16.fl;
    // 0x80027F90: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
L_80027F94:
    // 0x80027F94: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80027F98: nop

    // 0x80027F9C: cvt.w.s     $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    ctx->f18.u32l = CVT_W_S(ctx->f12.fl);
    // 0x80027FA0: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80027FA4: nop

    // 0x80027FA8: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80027FAC: beql        $t3, $zero, L_80027FFC
    if (ctx->r11 == 0) {
        // 0x80027FB0: mfc1        $t3, $f18
        ctx->r11 = (int32_t)ctx->f18.u32l;
            goto L_80027FFC;
    }
    goto skip_22;
    // 0x80027FB0: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    skip_22:
    // 0x80027FB4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80027FB8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80027FBC: sub.s       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x80027FC0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80027FC4: nop

    // 0x80027FC8: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80027FCC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80027FD0: nop

    // 0x80027FD4: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80027FD8: bne         $t3, $zero, L_80027FF0
    if (ctx->r11 != 0) {
        // 0x80027FDC: nop
    
            goto L_80027FF0;
    }
    // 0x80027FDC: nop

    // 0x80027FE0: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80027FE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80027FE8: b           L_80028008
    // 0x80027FEC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80028008;
    // 0x80027FEC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80027FF0:
    // 0x80027FF0: b           L_80028008
    // 0x80027FF4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80028008;
    // 0x80027FF4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80027FF8: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
L_80027FFC:
    // 0x80027FFC: nop

    // 0x80028000: bltz        $t3, L_80027FF0
    if (SIGNED(ctx->r11) < 0) {
        // 0x80028004: nop
    
            goto L_80027FF0;
    }
    // 0x80028004: nop

L_80028008:
    // 0x80028008: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002800C: b           L_800280F0
    // 0x80028010: sb          $t3, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r11;
        goto L_800280F0;
    // 0x80028010: sb          $t3, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r11;
L_80028014:
    // 0x80028014: slti        $at, $a0, 0xA
    ctx->r1 = SIGNED(ctx->r4) < 0XA ? 1 : 0;
    // 0x80028018: beq         $at, $zero, L_8002802C
    if (ctx->r1 == 0) {
        // 0x8002801C: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_8002802C;
    }
    // 0x8002801C: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x80028020: addu        $t6, $s1, $t4
    ctx->r14 = ADD32(ctx->r17, ctx->r12);
    // 0x80028024: b           L_800280F0
    // 0x80028028: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
        goto L_800280F0;
    // 0x80028028: swc1        $f12, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f12.u32l;
L_8002802C:
    // 0x8002802C: slti        $at, $a0, 0x18
    ctx->r1 = SIGNED(ctx->r4) < 0X18 ? 1 : 0;
    // 0x80028030: beq         $at, $zero, L_80028044
    if (ctx->r1 == 0) {
        // 0x80028034: addiu       $a1, $a0, -0x18
        ctx->r5 = ADD32(ctx->r4, -0X18);
            goto L_80028044;
    }
    // 0x80028034: addiu       $a1, $a0, -0x18
    ctx->r5 = ADD32(ctx->r4, -0X18);
    // 0x80028038: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x8002803C: b           L_80028090
    // 0x80028040: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
        goto L_80028090;
    // 0x80028040: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
L_80028044:
    // 0x80028044: lw          $v1, 0x44($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X44);
    // 0x80028048: bgez        $a1, L_80028058
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8002804C: sra         $v0, $a1, 3
        ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
            goto L_80028058;
    }
    // 0x8002804C: sra         $v0, $a1, 3
    ctx->r2 = S32(SIGNED(ctx->r5) >> 3);
    // 0x80028050: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x80028054: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_80028058:
    // 0x80028058: bgez        $a1, L_8002806C
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8002805C: andi        $a1, $a1, 0x7
        ctx->r5 = ctx->r5 & 0X7;
            goto L_8002806C;
    }
    // 0x8002805C: andi        $a1, $a1, 0x7
    ctx->r5 = ctx->r5 & 0X7;
    // 0x80028060: beq         $a1, $zero, L_8002806C
    if (ctx->r5 == 0) {
        // 0x80028064: nop
    
            goto L_8002806C;
    }
    // 0x80028064: nop

    // 0x80028068: addiu       $a1, $a1, -0x8
    ctx->r5 = ADD32(ctx->r5, -0X8);
L_8002806C:
    // 0x8002806C: beq         $v1, $zero, L_8002808C
    if (ctx->r3 == 0) {
        // 0x80028070: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_8002808C;
    }
    // 0x80028070: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x80028074: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
L_80028078:
    // 0x80028078: beq         $v0, $t7, L_8002808C
    if (ctx->r2 == ctx->r15) {
        // 0x8002807C: nop
    
            goto L_8002808C;
    }
    // 0x8002807C: nop

    // 0x80028080: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80028084: bnel        $v1, $zero, L_80028078
    if (ctx->r3 != 0) {
        // 0x80028088: lbu         $t7, 0x4($v1)
        ctx->r15 = MEM_BU(ctx->r3, 0X4);
            goto L_80028078;
    }
    goto skip_23;
    // 0x80028088: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    skip_23:
L_8002808C:
    // 0x8002808C: beq         $v1, $zero, L_800280F0
    if (ctx->r3 == 0) {
        // 0x80028090: addiu       $t8, $a1, -0x10
        ctx->r24 = ADD32(ctx->r5, -0X10);
            goto L_800280F0;
    }
L_80028090:
    // 0x80028090: addiu       $t8, $a1, -0x10
    ctx->r24 = ADD32(ctx->r5, -0X10);
    // 0x80028094: sltiu       $at, $t8, 0x8
    ctx->r1 = ctx->r24 < 0X8 ? 1 : 0;
    // 0x80028098: beq         $at, $zero, L_800280F0
    if (ctx->r1 == 0) {
        // 0x8002809C: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_800280F0;
    }
    // 0x8002809C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800280A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800280A4: addu        $at, $at, $t8
    gpr jr_addend_800280AC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800280A8: lw          $t8, -0x14AC($at)
    ctx->r24 = ADD32(ctx->r1, -0X14AC);
    // 0x800280AC: jr          $t8
    // 0x800280B0: nop

    switch (jr_addend_800280AC >> 2) {
        case 0: goto L_800280BC; break;
        case 1: goto L_800280B4; break;
        case 2: goto L_800280CC; break;
        case 3: goto L_800280C4; break;
        case 4: goto L_800280DC; break;
        case 5: goto L_800280D4; break;
        case 6: goto L_800280EC; break;
        case 7: goto L_800280E4; break;
        default: switch_error(__func__, 0x800280AC, 0x8003EB54);
    }
    // 0x800280B0: nop

L_800280B4:
    // 0x800280B4: lwc1        $f6, 0x8($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800280B8: add.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f6.fl;
L_800280BC:
    // 0x800280BC: b           L_800280F0
    // 0x800280C0: swc1        $f12, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f12.u32l;
        goto L_800280F0;
    // 0x800280C0: swc1        $f12, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f12.u32l;
L_800280C4:
    // 0x800280C4: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800280C8: add.s       $f12, $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f10.fl;
L_800280CC:
    // 0x800280CC: b           L_800280F0
    // 0x800280D0: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
        goto L_800280F0;
    // 0x800280D0: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
L_800280D4:
    // 0x800280D4: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800280D8: add.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f4.fl;
L_800280DC:
    // 0x800280DC: b           L_800280F0
    // 0x800280E0: swc1        $f12, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f12.u32l;
        goto L_800280F0;
    // 0x800280E0: swc1        $f12, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f12.u32l;
L_800280E4:
    // 0x800280E4: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800280E8: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_800280EC:
    // 0x800280EC: swc1        $f12, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f12.u32l;
L_800280F0:
    // 0x800280F0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800280F4: bnel        $s0, $zero, L_80027A38
    if (ctx->r16 != 0) {
        // 0x800280F8: lbu         $t4, 0x5($s0)
        ctx->r12 = MEM_BU(ctx->r16, 0X5);
            goto L_80027A38;
    }
    goto skip_24;
    // 0x800280F8: lbu         $t4, 0x5($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X5);
    skip_24:
L_800280FC:
    // 0x800280FC: lbu         $v1, 0x2A($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X2A);
    // 0x80028100: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80028104: beql        $v1, $zero, L_8002814C
    if (ctx->r3 == 0) {
        // 0x80028108: lbu         $a1, 0x32($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X32);
            goto L_8002814C;
    }
    goto skip_25;
    // 0x80028108: lbu         $a1, 0x32($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X32);
    skip_25:
    // 0x8002810C: beq         $v1, $at, L_80028168
    if (ctx->r3 == ctx->r1) {
        // 0x80028110: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80028168;
    }
    // 0x80028110: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80028114: beq         $v1, $at, L_800282D4
    if (ctx->r3 == ctx->r1) {
        // 0x80028118: addiu       $a0, $s2, 0x4
        ctx->r4 = ADD32(ctx->r18, 0X4);
            goto L_800282D4;
    }
    // 0x80028118: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x8002811C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80028120: beq         $v1, $at, L_80028304
    if (ctx->r3 == ctx->r1) {
        // 0x80028124: addiu       $s3, $s2, 0x4
        ctx->r19 = ADD32(ctx->r18, 0X4);
            goto L_80028304;
    }
    // 0x80028124: addiu       $s3, $s2, 0x4
    ctx->r19 = ADD32(ctx->r18, 0X4);
    // 0x80028128: lbu         $a1, 0x32($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X32);
    // 0x8002812C: lbu         $a2, 0x34($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X34);
    // 0x80028130: lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2C);
    // 0x80028134: lbu         $v1, 0x36($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X36);
    // 0x80028138: lbu         $a3, 0x38($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X38);
    // 0x8002813C: lbu         $t0, 0x3A($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X3A);
    // 0x80028140: b           L_80028424
    // 0x80028144: lbu         $a0, 0x3C($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3C);
        goto L_80028424;
    // 0x80028144: lbu         $a0, 0x3C($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3C);
    // 0x80028148: lbu         $a1, 0x32($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X32);
L_8002814C:
    // 0x8002814C: lbu         $a2, 0x34($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X34);
    // 0x80028150: lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2C);
    // 0x80028154: lbu         $v1, 0x36($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X36);
    // 0x80028158: lbu         $a3, 0x38($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X38);
    // 0x8002815C: lbu         $t0, 0x3A($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X3A);
    // 0x80028160: b           L_80028424
    // 0x80028164: lbu         $a0, 0x3C($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3C);
        goto L_80028424;
    // 0x80028164: lbu         $a0, 0x3C($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3C);
L_80028168:
    // 0x80028168: lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2C);
    // 0x8002816C: lh          $t9, 0x2E($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X2E);
    // 0x80028170: beql        $t9, $v0, L_80028194
    if (ctx->r25 == ctx->r2) {
        // 0x80028174: lbu         $v0, 0x32($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X32);
            goto L_80028194;
    }
    goto skip_26;
    // 0x80028174: lbu         $v0, 0x32($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X32);
    skip_26:
    // 0x80028178: lh          $t2, 0x30($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X30);
    // 0x8002817C: jal         0x80036360
    // 0x80028180: addu        $a0, $v0, $t2
    ctx->r4 = ADD32(ctx->r2, ctx->r10);
    alCents2Ratio(rdram, ctx);
        goto after_12;
    // 0x80028180: addu        $a0, $v0, $t2
    ctx->r4 = ADD32(ctx->r2, ctx->r10);
    after_12:
    // 0x80028184: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80028188: jal         0x8002FAB0
    // 0x8002818C: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    n_alSynSetPitch(rdram, ctx);
        goto after_13;
    // 0x8002818C: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    after_13:
    // 0x80028190: lbu         $v0, 0x32($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X32);
L_80028194:
    // 0x80028194: lbu         $t5, 0x33($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X33);
    // 0x80028198: bnel        $t5, $v0, L_800281B4
    if (ctx->r13 != ctx->r2) {
        // 0x8002819C: lbu         $t6, 0x38($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X38);
            goto L_800281B4;
    }
    goto skip_27;
    // 0x8002819C: lbu         $t6, 0x38($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X38);
    skip_27:
    // 0x800281A0: lbu         $t3, 0x39($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X39);
    // 0x800281A4: lbu         $t4, 0x38($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X38);
    // 0x800281A8: beql        $t3, $t4, L_800281EC
    if (ctx->r11 == ctx->r12) {
        // 0x800281AC: lbu         $v0, 0x34($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X34);
            goto L_800281EC;
    }
    goto skip_28;
    // 0x800281AC: lbu         $v0, 0x34($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X34);
    skip_28:
    // 0x800281B0: lbu         $t6, 0x38($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X38);
L_800281B4:
    // 0x800281B4: lbu         $t8, 0x5A($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X5A);
    // 0x800281B8: addiu       $a0, $s2, 0x4
    ctx->r4 = ADD32(ctx->r18, 0X4);
    // 0x800281BC: multu       $v0, $t6
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800281C0: lw          $a2, 0x44($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X44);
    // 0x800281C4: mflo        $t7
    ctx->r15 = lo;
    // 0x800281C8: nop

    // 0x800281CC: nop

    // 0x800281D0: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800281D4: mflo        $a1
    ctx->r5 = lo;
    // 0x800281D8: sra         $a1, $a1, 7
    ctx->r5 = S32(SIGNED(ctx->r5) >> 7);
    // 0x800281DC: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x800281E0: jal         0x8002FF60
    // 0x800281E4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    n_alSynSetVol(rdram, ctx);
        goto after_14;
    // 0x800281E4: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_14:
    // 0x800281E8: lbu         $v0, 0x34($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X34);
L_800281EC:
    // 0x800281EC: lbu         $t9, 0x35($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X35);
    // 0x800281F0: bnel        $t9, $v0, L_8002820C
    if (ctx->r25 != ctx->r2) {
        // 0x800281F4: lbu         $t6, 0x3A($s2)
        ctx->r14 = MEM_BU(ctx->r18, 0X3A);
            goto L_8002820C;
    }
    goto skip_29;
    // 0x800281F4: lbu         $t6, 0x3A($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X3A);
    skip_29:
    // 0x800281F8: lbu         $t2, 0x3B($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X3B);
    // 0x800281FC: lbu         $t5, 0x3A($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X3A);
    // 0x80028200: beql        $t2, $t5, L_8002824C
    if (ctx->r10 == ctx->r13) {
        // 0x80028204: lbu         $v1, 0x36($s2)
        ctx->r3 = MEM_BU(ctx->r18, 0X36);
            goto L_8002824C;
    }
    goto skip_30;
    // 0x80028204: lbu         $v1, 0x36($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X36);
    skip_30:
    // 0x80028208: lbu         $t6, 0x3A($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X3A);
L_8002820C:
    // 0x8002820C: addiu       $s3, $s2, 0x4
    ctx->r19 = ADD32(ctx->r18, 0X4);
    // 0x80028210: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80028214: addu        $s0, $v0, $t6
    ctx->r16 = ADD32(ctx->r2, ctx->r14);
    // 0x80028218: addiu       $s0, $s0, -0x40
    ctx->r16 = ADD32(ctx->r16, -0X40);
    // 0x8002821C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80028220: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80028224: bgezl       $s0, L_80028234
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80028228: slti        $at, $s0, 0x80
        ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
            goto L_80028234;
    }
    goto skip_31;
    // 0x80028228: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    skip_31:
    // 0x8002822C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80028230: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
L_80028234:
    // 0x80028234: bne         $at, $zero, L_80028240
    if (ctx->r1 != 0) {
        // 0x80028238: nop
    
            goto L_80028240;
    }
    // 0x80028238: nop

    // 0x8002823C: addiu       $s0, $zero, 0x7F
    ctx->r16 = ADD32(0, 0X7F);
L_80028240:
    // 0x80028240: jal         0x8002DA20
    // 0x80028244: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    n_alSynSetPan(rdram, ctx);
        goto after_15;
    // 0x80028244: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_15:
    // 0x80028248: lbu         $v1, 0x36($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X36);
L_8002824C:
    // 0x8002824C: lbu         $t7, 0x37($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X37);
    // 0x80028250: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80028254: bnel        $t7, $v1, L_80028270
    if (ctx->r15 != ctx->r3) {
        // 0x80028258: lbu         $t9, 0x3C($s2)
        ctx->r25 = MEM_BU(ctx->r18, 0X3C);
            goto L_80028270;
    }
    goto skip_32;
    // 0x80028258: lbu         $t9, 0x3C($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X3C);
    skip_32:
    // 0x8002825C: lbu         $a0, 0x3C($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3C);
    // 0x80028260: lbu         $t8, 0x3D($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3D);
    // 0x80028264: beql        $t8, $a0, L_800282C0
    if (ctx->r24 == ctx->r4) {
        // 0x80028268: lbu         $a1, 0x32($s2)
        ctx->r5 = MEM_BU(ctx->r18, 0X32);
            goto L_800282C0;
    }
    goto skip_33;
    // 0x80028268: lbu         $a1, 0x32($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X32);
    skip_33:
    // 0x8002826C: lbu         $t9, 0x3C($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X3C);
L_80028270:
    // 0x80028270: addiu       $s3, $s2, 0x4
    ctx->r19 = ADD32(ctx->r18, 0X4);
    // 0x80028274: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80028278: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8002827C: multu       $v0, $t2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80028280: mflo        $s0
    ctx->r16 = lo;
    // 0x80028284: sra         $s0, $s0, 7
    ctx->r16 = S32(SIGNED(ctx->r16) >> 7);
    // 0x80028288: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x8002828C: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80028290: bgezl       $s0, L_800282A0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80028294: slti        $at, $s0, 0x80
        ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
            goto L_800282A0;
    }
    goto skip_34;
    // 0x80028294: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    skip_34:
    // 0x80028298: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002829C: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
L_800282A0:
    // 0x800282A0: bne         $at, $zero, L_800282AC
    if (ctx->r1 != 0) {
        // 0x800282A4: nop
    
            goto L_800282AC;
    }
    // 0x800282A4: nop

    // 0x800282A8: addiu       $s0, $zero, 0x7F
    ctx->r16 = ADD32(0, 0X7F);
L_800282AC:
    // 0x800282AC: jal         0x8002FCF4
    // 0x800282B0: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    n_alSynSetFXMix(rdram, ctx);
        goto after_16;
    // 0x800282B0: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_16:
    // 0x800282B4: lbu         $v1, 0x36($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X36);
    // 0x800282B8: lbu         $a0, 0x3C($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3C);
    // 0x800282BC: lbu         $a1, 0x32($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X32);
L_800282C0:
    // 0x800282C0: lbu         $a2, 0x34($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X34);
    // 0x800282C4: lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2C);
    // 0x800282C8: lbu         $a3, 0x38($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X38);
    // 0x800282CC: b           L_80028424
    // 0x800282D0: lbu         $t0, 0x3A($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X3A);
        goto L_80028424;
    // 0x800282D0: lbu         $t0, 0x3A($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X3A);
L_800282D4:
    // 0x800282D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800282D8: jal         0x8002FF60
    // 0x800282DC: lw          $a2, 0x44($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X44);
    n_alSynSetVol(rdram, ctx);
        goto after_17;
    // 0x800282DC: lw          $a2, 0x44($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X44);
    after_17:
    // 0x800282E0: sb          $zero, 0x2A($s2)
    MEM_B(0X2A, ctx->r18) = 0;
    // 0x800282E4: lbu         $a1, 0x32($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X32);
    // 0x800282E8: lbu         $a2, 0x34($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X34);
    // 0x800282EC: lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2C);
    // 0x800282F0: lbu         $v1, 0x36($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X36);
    // 0x800282F4: lbu         $a3, 0x38($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X38);
    // 0x800282F8: lbu         $t0, 0x3A($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X3A);
    // 0x800282FC: b           L_80028424
    // 0x80028300: lbu         $a0, 0x3C($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3C);
        goto L_80028424;
    // 0x80028300: lbu         $a0, 0x3C($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3C);
L_80028304:
    // 0x80028304: sh          $zero, 0x96($sp)
    MEM_H(0X96, ctx->r29) = 0;
    // 0x80028308: lbu         $t5, 0x2B($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X2B);
    // 0x8002830C: sb          $zero, 0x98($sp)
    MEM_B(0X98, ctx->r29) = 0;
    // 0x80028310: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80028314: andi        $t3, $t5, 0x7F
    ctx->r11 = ctx->r13 & 0X7F;
    // 0x80028318: sh          $t3, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r11;
    // 0x8002831C: jal         0x8002D8E0
    // 0x80028320: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    n_alSynAllocVoice(rdram, ctx);
        goto after_18;
    // 0x80028320: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_18:
    // 0x80028324: beql        $v0, $zero, L_80028408
    if (ctx->r2 == 0) {
        // 0x80028328: sb          $zero, 0x2A($s2)
        MEM_B(0X2A, ctx->r18) = 0;
            goto L_80028408;
    }
    goto skip_35;
    // 0x80028328: sb          $zero, 0x2A($s2)
    MEM_B(0X2A, ctx->r18) = 0;
    skip_35:
    // 0x8002832C: lbu         $t4, 0x34($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X34);
    // 0x80028330: lbu         $t6, 0x3A($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X3A);
    // 0x80028334: addu        $s0, $t4, $t6
    ctx->r16 = ADD32(ctx->r12, ctx->r14);
    // 0x80028338: addiu       $s0, $s0, -0x40
    ctx->r16 = ADD32(ctx->r16, -0X40);
    // 0x8002833C: sll         $s0, $s0, 16
    ctx->r16 = S32(ctx->r16 << 16);
    // 0x80028340: sra         $s0, $s0, 16
    ctx->r16 = S32(SIGNED(ctx->r16) >> 16);
    // 0x80028344: bgezl       $s0, L_80028354
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80028348: slti        $at, $s0, 0x80
        ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
            goto L_80028354;
    }
    goto skip_36;
    // 0x80028348: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
    skip_36:
    // 0x8002834C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80028350: slti        $at, $s0, 0x80
    ctx->r1 = SIGNED(ctx->r16) < 0X80 ? 1 : 0;
L_80028354:
    // 0x80028354: bnel        $at, $zero, L_80028364
    if (ctx->r1 != 0) {
        // 0x80028358: lbu         $t8, 0x3C($s2)
        ctx->r24 = MEM_BU(ctx->r18, 0X3C);
            goto L_80028364;
    }
    goto skip_37;
    // 0x80028358: lbu         $t8, 0x3C($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3C);
    skip_37:
    // 0x8002835C: addiu       $s0, $zero, 0x7F
    ctx->r16 = ADD32(0, 0X7F);
    // 0x80028360: lbu         $t8, 0x3C($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X3C);
L_80028364:
    // 0x80028364: lbu         $t7, 0x36($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X36);
    // 0x80028368: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8002836C: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80028370: mflo        $s1
    ctx->r17 = lo;
    // 0x80028374: sra         $s1, $s1, 7
    ctx->r17 = S32(SIGNED(ctx->r17) >> 7);
    // 0x80028378: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x8002837C: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80028380: bgezl       $s1, L_80028390
    if (SIGNED(ctx->r17) >= 0) {
        // 0x80028384: slti        $at, $s1, 0x80
        ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
            goto L_80028390;
    }
    goto skip_38;
    // 0x80028384: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
    skip_38:
    // 0x80028388: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8002838C: slti        $at, $s1, 0x80
    ctx->r1 = SIGNED(ctx->r17) < 0X80 ? 1 : 0;
L_80028390:
    // 0x80028390: bnel        $at, $zero, L_800283A0
    if (ctx->r1 != 0) {
        // 0x80028394: lh          $t2, 0x2C($s2)
        ctx->r10 = MEM_H(ctx->r18, 0X2C);
            goto L_800283A0;
    }
    goto skip_39;
    // 0x80028394: lh          $t2, 0x2C($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2C);
    skip_39:
    // 0x80028398: addiu       $s1, $zero, 0x7F
    ctx->r17 = ADD32(0, 0X7F);
    // 0x8002839C: lh          $t2, 0x2C($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2C);
L_800283A0:
    // 0x800283A0: lh          $t5, 0x30($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X30);
    // 0x800283A4: jal         0x80036360
    // 0x800283A8: addu        $a0, $t2, $t5
    ctx->r4 = ADD32(ctx->r10, ctx->r13);
    alCents2Ratio(rdram, ctx);
        goto after_19;
    // 0x800283A8: addu        $a0, $t2, $t5
    ctx->r4 = ADD32(ctx->r10, ctx->r13);
    after_19:
    // 0x800283AC: lbu         $t3, 0x32($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X32);
    // 0x800283B0: lbu         $t4, 0x38($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X38);
    // 0x800283B4: lbu         $t8, 0x5A($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X5A);
    // 0x800283B8: lw          $a1, 0x40($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X40);
    // 0x800283BC: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800283C0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800283C4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800283C8: sw          $s1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r17;
    // 0x800283CC: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    // 0x800283D0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800283D4: mflo        $t6
    ctx->r14 = lo;
    // 0x800283D8: nop

    // 0x800283DC: nop

    // 0x800283E0: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800283E4: mflo        $a3
    ctx->r7 = lo;
    // 0x800283E8: sra         $a3, $a3, 7
    ctx->r7 = S32(SIGNED(ctx->r7) >> 7);
    // 0x800283EC: sll         $a3, $a3, 16
    ctx->r7 = S32(ctx->r7 << 16);
    // 0x800283F0: jal         0x8002DB84
    // 0x800283F4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    n_alSynStartVoiceParams(rdram, ctx);
        goto after_20;
    // 0x800283F4: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    after_20:
    // 0x800283F8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800283FC: b           L_80028408
    // 0x80028400: sb          $t7, 0x2A($s2)
    MEM_B(0X2A, ctx->r18) = ctx->r15;
        goto L_80028408;
    // 0x80028400: sb          $t7, 0x2A($s2)
    MEM_B(0X2A, ctx->r18) = ctx->r15;
    // 0x80028404: sb          $zero, 0x2A($s2)
    MEM_B(0X2A, ctx->r18) = 0;
L_80028408:
    // 0x80028408: lbu         $a1, 0x32($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X32);
    // 0x8002840C: lbu         $a2, 0x34($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X34);
    // 0x80028410: lh          $v0, 0x2C($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X2C);
    // 0x80028414: lbu         $v1, 0x36($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X36);
    // 0x80028418: lbu         $a3, 0x38($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X38);
    // 0x8002841C: lbu         $t0, 0x3A($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X3A);
    // 0x80028420: lbu         $a0, 0x3C($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X3C);
L_80028424:
    // 0x80028424: sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // 0x80028428: sb          $a1, 0x33($s2)
    MEM_B(0X33, ctx->r18) = ctx->r5;
    // 0x8002842C: sb          $a2, 0x35($s2)
    MEM_B(0X35, ctx->r18) = ctx->r6;
    // 0x80028430: sb          $v1, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r3;
    // 0x80028434: sb          $a3, 0x39($s2)
    MEM_B(0X39, ctx->r18) = ctx->r7;
    // 0x80028438: sb          $t0, 0x3B($s2)
    MEM_B(0X3B, ctx->r18) = ctx->r8;
    // 0x8002843C: sb          $a0, 0x3D($s2)
    MEM_B(0X3D, ctx->r18) = ctx->r4;
    // 0x80028440: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80028444: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80028448: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8002844C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80028450: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80028454: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80028458: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8002845C: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x80028460: jr          $ra
    // 0x80028464: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x80028464: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_ovl8_80381710(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381710: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80381714: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80381718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8038171C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80381720: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80381724: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80381728: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8038172C: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x80381730: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x80381734: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80381738: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8038173C: nop

    // 0x80381740: bc1fl       L_80381798
    if (!c1cs) {
        // 0x80381744: lw          $v1, 0x30($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X30);
            goto L_80381798;
    }
    goto skip_0;
    // 0x80381744: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    skip_0:
    // 0x80381748: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8038174C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80381750: nop

    // 0x80381754: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80381758: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x8038175C: nop

    // 0x80381760: bc1fl       L_80381798
    if (!c1cs) {
        // 0x80381764: lw          $v1, 0x30($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X30);
            goto L_80381798;
    }
    goto skip_1;
    // 0x80381764: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    skip_1:
    // 0x80381768: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x8038176C: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
    // 0x80381770: sll         $t0, $a1, 2
    ctx->r8 = S32(ctx->r5 << 2);
    // 0x80381774: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80381778: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x8038177C: lh          $t8, 0x70($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X70);
    // 0x80381780: lw          $a1, -0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, -0X4);
    // 0x80381784: jalr        $t9
    // 0x80381788: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80381788: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    after_0:
    // 0x8038178C: b           L_803817B4
    // 0x80381790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_803817B4;
    // 0x80381790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80381794: lw          $v1, 0x30($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X30);
L_80381798:
    // 0x80381798: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x8038179C: addiu       $a1, $a1, -0x43D0
    ctx->r5 = ADD32(ctx->r5, -0X43D0);
    // 0x803817A0: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x803817A4: lh          $t2, 0x70($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X70);
    // 0x803817A8: jalr        $t9
    // 0x803817AC: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x803817AC: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    after_1:
    // 0x803817B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803817B4:
    // 0x803817B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803817B8: jr          $ra
    // 0x803817BC: nop

    return;
    // 0x803817BC: nop

;}
RECOMP_FUNC void mvOpeningYoshiPosedWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D874: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8018D878: addiu       $t3, $t3, 0x65B0
    ctx->r11 = ADD32(ctx->r11, 0X65B0);
    // 0x8018D87C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D880: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D884: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018D888: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D88C: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8018D890: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D894: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D898: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D89C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8018D8A0: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8018D8A4: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D8A8: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D8AC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D8B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018D8B4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8B8: lui         $t7, 0xFFBE
    ctx->r15 = S32(0XFFBE << 16);
    // 0x8018D8BC: ori         $t7, $t7, 0x5AFF
    ctx->r15 = ctx->r15 | 0X5AFF;
    // 0x8018D8C0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D8C4: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D8C8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018D8CC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D8D0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D8D4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8D8: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8018D8DC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8018D8E0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D8E4: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D8E8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8018D8EC: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8018D8F0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D8F4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D8F8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8FC: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8018D900: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8018D904: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D908: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D90C: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8018D910: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x8018D914: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D918: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018D91C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D920: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x8018D924: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x8018D928: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D92C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D930: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x8018D934: ori         $t7, $t7, 0x8258
    ctx->r15 = ctx->r15 | 0X8258;
    // 0x8018D938: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D93C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D940: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D944: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x8018D948: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x8018D94C: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D950: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D954: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D958: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D95C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D960: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D964: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D968: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D96C: jr          $ra
    // 0x8018D970: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    return;
    // 0x8018D970: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
;}
RECOMP_FUNC void ftParamSetAnimLocks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EB6EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800EB6F0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800EB6F4: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800EB6F8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800EB6FC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800EB700: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800EB704: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800EB708: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800EB70C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800EB710: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800EB714: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EB718: lw          $v1, 0x9C8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X9C8);
    // 0x800EB71C: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800EB720: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x800EB724: lw          $v0, 0x2A0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X2A0);
    // 0x800EB728: lw          $s3, 0x0($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X0);
    // 0x800EB72C: lw          $s4, 0x4($v0)
    ctx->r20 = MEM_W(ctx->r2, 0X4);
    // 0x800EB730: bnel        $s3, $zero, L_800EB740
    if (ctx->r19 != 0) {
        // 0x800EB734: slti        $at, $s2, 0x24
        ctx->r1 = SIGNED(ctx->r18) < 0X24 ? 1 : 0;
            goto L_800EB740;
    }
    goto skip_0;
    // 0x800EB734: slti        $at, $s2, 0x24
    ctx->r1 = SIGNED(ctx->r18) < 0X24 ? 1 : 0;
    skip_0:
    // 0x800EB738: beq         $s4, $zero, L_800EB7C4
    if (ctx->r20 == 0) {
        // 0x800EB73C: slti        $at, $s2, 0x24
        ctx->r1 = SIGNED(ctx->r18) < 0X24 ? 1 : 0;
            goto L_800EB7C4;
    }
L_800EB73C:
    // 0x800EB73C: slti        $at, $s2, 0x24
    ctx->r1 = SIGNED(ctx->r18) < 0X24 ? 1 : 0;
L_800EB740:
    // 0x800EB740: lui         $s5, 0x8000
    ctx->r21 = S32(0X8000 << 16);
    // 0x800EB744: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x800EB748: beq         $at, $zero, L_800EB758
    if (ctx->r1 == 0) {
        // 0x800EB74C: addiu       $s7, $zero, 0x1
        ctx->r23 = ADD32(0, 0X1);
            goto L_800EB758;
    }
    // 0x800EB74C: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x800EB750: b           L_800EB75C
    // 0x800EB754: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
        goto L_800EB75C;
    // 0x800EB754: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_800EB758:
    // 0x800EB758: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_800EB75C:
    // 0x800EB75C: and         $t6, $v0, $s5
    ctx->r14 = ctx->r2 & ctx->r21;
    // 0x800EB760: beq         $t6, $zero, L_800EB79C
    if (ctx->r14 == 0) {
        // 0x800EB764: sll         $t7, $s2, 2
        ctx->r15 = S32(ctx->r18 << 2);
            goto L_800EB79C;
    }
    // 0x800EB764: sll         $t7, $s2, 2
    ctx->r15 = S32(ctx->r18 << 2);
    // 0x800EB768: addu        $s1, $fp, $t7
    ctx->r17 = ADD32(ctx->r30, ctx->r15);
    // 0x800EB76C: lw          $a0, 0x8E8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8E8);
    // 0x800EB770: beql        $a0, $zero, L_800EB7A0
    if (ctx->r4 == 0) {
        // 0x800EB774: slti        $at, $s2, 0x24
        ctx->r1 = SIGNED(ctx->r18) < 0X24 ? 1 : 0;
            goto L_800EB7A0;
    }
    goto skip_1;
    // 0x800EB774: slti        $at, $s2, 0x24
    ctx->r1 = SIGNED(ctx->r18) < 0X24 ? 1 : 0;
    skip_1:
    // 0x800EB778: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800EB77C: beq         $s0, $zero, L_800EB79C
    if (ctx->r16 == 0) {
        // 0x800EB780: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_800EB79C;
    }
    // 0x800EB780: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800EB784: jal         0x800ECDE4
    // 0x800EB788: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    gmCollisionTransformMatrixAll(rdram, ctx);
        goto after_0;
    // 0x800EB788: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_0:
    // 0x800EB78C: sw          $s6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r22;
    // 0x800EB790: lw          $t8, 0x8E8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8E8);
    // 0x800EB794: lw          $t9, 0x58($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X58);
    // 0x800EB798: sb          $s7, 0x5($t9)
    MEM_B(0X5, ctx->r25) = ctx->r23;
L_800EB79C:
    // 0x800EB79C: slti        $at, $s2, 0x24
    ctx->r1 = SIGNED(ctx->r18) < 0X24 ? 1 : 0;
L_800EB7A0:
    // 0x800EB7A0: beql        $at, $zero, L_800EB7B4
    if (ctx->r1 == 0) {
        // 0x800EB7A4: sll         $s4, $s4, 1
        ctx->r20 = S32(ctx->r20 << 1);
            goto L_800EB7B4;
    }
    goto skip_2;
    // 0x800EB7A4: sll         $s4, $s4, 1
    ctx->r20 = S32(ctx->r20 << 1);
    skip_2:
    // 0x800EB7A8: b           L_800EB7B4
    // 0x800EB7AC: sll         $s3, $s3, 1
    ctx->r19 = S32(ctx->r19 << 1);
        goto L_800EB7B4;
    // 0x800EB7AC: sll         $s3, $s3, 1
    ctx->r19 = S32(ctx->r19 << 1);
    // 0x800EB7B0: sll         $s4, $s4, 1
    ctx->r20 = S32(ctx->r20 << 1);
L_800EB7B4:
    // 0x800EB7B4: bne         $s3, $zero, L_800EB73C
    if (ctx->r19 != 0) {
        // 0x800EB7B8: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800EB73C;
    }
    // 0x800EB7B8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800EB7BC: bnel        $s4, $zero, L_800EB740
    if (ctx->r20 != 0) {
        // 0x800EB7C0: slti        $at, $s2, 0x24
        ctx->r1 = SIGNED(ctx->r18) < 0X24 ? 1 : 0;
            goto L_800EB740;
    }
    goto skip_3;
    // 0x800EB7C0: slti        $at, $s2, 0x24
    ctx->r1 = SIGNED(ctx->r18) < 0X24 ? 1 : 0;
    skip_3:
L_800EB7C4:
    // 0x800EB7C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800EB7C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EB7CC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800EB7D0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800EB7D4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800EB7D8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800EB7DC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800EB7E0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800EB7E4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800EB7E8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800EB7EC: jr          $ra
    // 0x800EB7F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800EB7F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnVSOptionsStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134668: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8013466C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134670: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134674: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80134678: addiu       $a0, $a0, 0x4810
    ctx->r4 = ADD32(ctx->r4, 0X4810);
    // 0x8013467C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134680: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80134684: jal         0x80007024
    // 0x80134688: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80134688: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8013468C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80134690: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134694: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134698: addiu       $t9, $t9, 0x49E0
    ctx->r25 = ADD32(ctx->r25, 0X49E0);
    // 0x8013469C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x801346A0: addiu       $a0, $a0, 0x482C
    ctx->r4 = ADD32(ctx->r4, 0X482C);
    // 0x801346A4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x801346A8: jal         0x8000683C
    // 0x801346AC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x801346AC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x801346B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801346B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801346B8: jr          $ra
    // 0x801346BC: nop

    return;
    // 0x801346BC: nop

;}
RECOMP_FUNC void mnTitleTransitionsFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132448: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013244C: addiu       $v0, $v0, 0x445C
    ctx->r2 = ADD32(ctx->r2, 0X445C);
    // 0x80132450: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80132454: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132458: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013245C: addiu       $v1, $t6, 0x1
    ctx->r3 = ADD32(ctx->r14, 0X1);
    // 0x80132460: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80132464: lw          $t8, 0x4498($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4498);
    // 0x80132468: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013246C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132470: bne         $t8, $v1, L_80132488
    if (ctx->r24 != ctx->r3) {
        // 0x80132474: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80132488;
    }
    // 0x80132474: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132478: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8013247C: addiu       $a0, $a0, 0x4AD0
    ctx->r4 = ADD32(ctx->r4, 0X4AD0);
    // 0x80132480: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132484: sb          $t9, 0x44($a0)
    MEM_B(0X44, ctx->r4) = ctx->r25;
L_80132488:
    // 0x80132488: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8013248C: slti        $at, $v1, 0xD7
    ctx->r1 = SIGNED(ctx->r3) < 0XD7 ? 1 : 0;
    // 0x80132490: bne         $at, $zero, L_801324CC
    if (ctx->r1 != 0) {
        // 0x80132494: addiu       $a0, $a0, 0x4AD0
        ctx->r4 = ADD32(ctx->r4, 0X4AD0);
            goto L_801324CC;
    }
    // 0x80132494: addiu       $a0, $a0, 0x4AD0
    ctx->r4 = ADD32(ctx->r4, 0X4AD0);
    // 0x80132498: addiu       $at, $zero, 0xDC
    ctx->r1 = ADD32(0, 0XDC);
    // 0x8013249C: beq         $v1, $at, L_80132544
    if (ctx->r3 == ctx->r1) {
        // 0x801324A0: addiu       $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_80132544;
    }
    // 0x801324A0: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x801324A4: beq         $v1, $at, L_801325C4
    if (ctx->r3 == ctx->r1) {
        // 0x801324A8: addiu       $at, $zero, 0x118
        ctx->r1 = ADD32(0, 0X118);
            goto L_801325C4;
    }
    // 0x801324A8: addiu       $at, $zero, 0x118
    ctx->r1 = ADD32(0, 0X118);
    // 0x801324AC: beq         $v1, $at, L_80132554
    if (ctx->r3 == ctx->r1) {
        // 0x801324B0: addiu       $at, $zero, 0x28A
        ctx->r1 = ADD32(0, 0X28A);
            goto L_80132554;
    }
    // 0x801324B0: addiu       $at, $zero, 0x28A
    ctx->r1 = ADD32(0, 0X28A);
    // 0x801324B4: beq         $v1, $at, L_80132594
    if (ctx->r3 == ctx->r1) {
        // 0x801324B8: addiu       $at, $zero, 0x4A6
        ctx->r1 = ADD32(0, 0X4A6);
            goto L_80132594;
    }
    // 0x801324B8: addiu       $at, $zero, 0x4A6
    ctx->r1 = ADD32(0, 0X4A6);
    // 0x801324BC: beql        $v1, $at, L_801325B4
    if (ctx->r3 == ctx->r1) {
        // 0x801324C0: lbu         $t2, 0x3F($a0)
        ctx->r10 = MEM_BU(ctx->r4, 0X3F);
            goto L_801325B4;
    }
    goto skip_0;
    // 0x801324C0: lbu         $t2, 0x3F($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X3F);
    skip_0:
    // 0x801324C4: b           L_801325C8
    // 0x801324C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801325C8;
    // 0x801324C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801324CC:
    // 0x801324CC: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x801324D0: beq         $v0, $at, L_80132564
    if (ctx->r2 == ctx->r1) {
        // 0x801324D4: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_80132564;
    }
    // 0x801324D4: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x801324D8: beq         $v0, $at, L_80132564
    if (ctx->r2 == ctx->r1) {
        // 0x801324DC: addiu       $at, $zero, 0x6F
        ctx->r1 = ADD32(0, 0X6F);
            goto L_80132564;
    }
    // 0x801324DC: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x801324E0: beq         $v0, $at, L_8013250C
    if (ctx->r2 == ctx->r1) {
        // 0x801324E4: addiu       $at, $zero, 0xAA
        ctx->r1 = ADD32(0, 0XAA);
            goto L_8013250C;
    }
    // 0x801324E4: addiu       $at, $zero, 0xAA
    ctx->r1 = ADD32(0, 0XAA);
    // 0x801324E8: beq         $v0, $at, L_8013251C
    if (ctx->r2 == ctx->r1) {
        // 0x801324EC: addiu       $at, $zero, 0xC8
        ctx->r1 = ADD32(0, 0XC8);
            goto L_8013251C;
    }
    // 0x801324EC: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x801324F0: beq         $v0, $at, L_80132574
    if (ctx->r2 == ctx->r1) {
        // 0x801324F4: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80132574;
    }
    // 0x801324F4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801324F8: addiu       $at, $zero, 0xD6
    ctx->r1 = ADD32(0, 0XD6);
    // 0x801324FC: beql        $v0, $at, L_801325C8
    if (ctx->r2 == ctx->r1) {
        // 0x80132500: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801325C8;
    }
    goto skip_1;
    // 0x80132500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80132504: b           L_801325C8
    // 0x80132508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801325C8;
    // 0x80132508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013250C:
    // 0x8013250C: jal         0x80132320
    // 0x80132510: nop

    mnTitleTransitionFromFireLogo(rdram, ctx);
        goto after_0;
    // 0x80132510: nop

    after_0:
    // 0x80132514: b           L_801325C8
    // 0x80132518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801325C8;
    // 0x80132518: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013251C:
    // 0x8013251C: jal         0x80131E68
    // 0x80132520: nop

    mnTitleSetEndLogoPosition(rdram, ctx);
        goto after_1;
    // 0x80132520: nop

    after_1:
    // 0x80132524: jal         0x801323AC
    // 0x80132528: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    mnTitleShowGObjLinkID(rdram, ctx);
        goto after_2;
    // 0x80132528: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_2:
    // 0x8013252C: jal         0x801323DC
    // 0x80132530: nop

    mnTitleAdvanceLayout(rdram, ctx);
        goto after_3;
    // 0x80132530: nop

    after_3:
    // 0x80132534: jal         0x80132414
    // 0x80132538: nop

    mnTitleSetAllowProceedWait(rdram, ctx);
        goto after_4;
    // 0x80132538: nop

    after_4:
    // 0x8013253C: b           L_801325C8
    // 0x80132540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801325C8;
    // 0x80132540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132544:
    // 0x80132544: jal         0x80131EE4
    // 0x80132548: nop

    mnTitleSetEndLayout(rdram, ctx);
        goto after_5;
    // 0x80132548: nop

    after_5:
    // 0x8013254C: b           L_801325C8
    // 0x80132550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801325C8;
    // 0x80132550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132554:
    // 0x80132554: jal         0x801323AC
    // 0x80132558: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    mnTitleShowGObjLinkID(rdram, ctx);
        goto after_6;
    // 0x80132558: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_6:
    // 0x8013255C: b           L_801325C8
    // 0x80132560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801325C8;
    // 0x80132560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132564:
    // 0x80132564: jal         0x800269C0
    // 0x80132568: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    func_800269C0_275C0(rdram, ctx);
        goto after_7;
    // 0x80132568: addiu       $a0, $zero, 0x98
    ctx->r4 = ADD32(0, 0X98);
    after_7:
    // 0x8013256C: b           L_801325C8
    // 0x80132570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801325C8;
    // 0x80132570: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132574:
    // 0x80132574: lw          $t0, 0x4450($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4450);
    // 0x80132578: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013257C: bnel        $t0, $at, L_801325C8
    if (ctx->r8 != ctx->r1) {
        // 0x80132580: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801325C8;
    }
    goto skip_2;
    // 0x80132580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80132584: jal         0x800269C0
    // 0x80132588: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x80132588: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    after_8:
    // 0x8013258C: b           L_801325C8
    // 0x80132590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801325C8;
    // 0x80132590: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132594:
    // 0x80132594: lbu         $t1, 0x3F($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X3F);
    // 0x80132598: bnel        $t1, $zero, L_801325C8
    if (ctx->r9 != 0) {
        // 0x8013259C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801325C8;
    }
    goto skip_3;
    // 0x8013259C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x801325A0: jal         0x80131FD0
    // 0x801325A4: nop

    mnTitleProceedDemoNext(rdram, ctx);
        goto after_9;
    // 0x801325A4: nop

    after_9:
    // 0x801325A8: b           L_801325C8
    // 0x801325AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801325C8;
    // 0x801325AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801325B0: lbu         $t2, 0x3F($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X3F);
L_801325B4:
    // 0x801325B4: beql        $t2, $zero, L_801325C8
    if (ctx->r10 == 0) {
        // 0x801325B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801325C8;
    }
    goto skip_4;
    // 0x801325B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x801325BC: jal         0x80131FD0
    // 0x801325C0: nop

    mnTitleProceedDemoNext(rdram, ctx);
        goto after_10;
    // 0x801325C0: nop

    after_10:
L_801325C4:
    // 0x801325C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801325C8:
    // 0x801325C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801325CC: jr          $ra
    // 0x801325D0: nop

    return;
    // 0x801325D0: nop

;}
RECOMP_FUNC void mvOpeningJungleFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D5E4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018D5E8: addiu       $v0, $v0, -0x25B8
    ctx->r2 = ADD32(ctx->r2, -0X25B8);
    // 0x8018D5EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018D5F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D5F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D5F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018D5FC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018D600: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018D604: jal         0x8039076C
    // 0x8018D608: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x8018D608: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x8018D60C: beq         $v0, $zero, L_8018D62C
    if (ctx->r2 == 0) {
        // 0x8018D610: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018D62C;
    }
    // 0x8018D610: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018D614: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D618: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018D61C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8018D620: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8018D624: jal         0x80005C74
    // 0x8018D628: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8018D628: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_1:
L_8018D62C:
    // 0x8018D62C: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D630: lw          $t0, -0x25B8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X25B8);
    // 0x8018D634: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D638: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x8018D63C: bne         $t0, $at, L_8018D658
    if (ctx->r8 != ctx->r1) {
        // 0x8018D640: addiu       $v0, $v0, 0x4AD0
        ctx->r2 = ADD32(ctx->r2, 0X4AD0);
            goto L_8018D658;
    }
    // 0x8018D640: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018D644: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x8018D648: addiu       $t2, $zero, 0x27
    ctx->r10 = ADD32(0, 0X27);
    // 0x8018D64C: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x8018D650: jal         0x80005C74
    // 0x8018D654: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_2;
    // 0x8018D654: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
    after_2:
L_8018D658:
    // 0x8018D658: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D65C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D660: jr          $ra
    // 0x8018D664: nop

    return;
    // 0x8018D664: nop

;}
RECOMP_FUNC void syMainSetImemStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000480: lui         $t6, 0xA400
    ctx->r14 = S32(0XA400 << 16);
    // 0x80000484: lw          $t7, 0x1000($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1000);
    // 0x80000488: addiu       $at, $zero, 0x17D7
    ctx->r1 = ADD32(0, 0X17D7);
    // 0x8000048C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80000490: bne         $t7, $at, L_800004A0
    if (ctx->r15 != ctx->r1) {
        // 0x80000494: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_800004A0;
    }
    // 0x80000494: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80000498: jr          $ra
    // 0x8000049C: sb          $t8, 0x4D40($at)
    MEM_B(0X4D40, ctx->r1) = ctx->r24;
    return;
    // 0x8000049C: sb          $t8, 0x4D40($at)
    MEM_B(0X4D40, ctx->r1) = ctx->r24;
L_800004A0:
    // 0x800004A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800004A4: sb          $zero, 0x4D40($at)
    MEM_B(0X4D40, ctx->r1) = 0;
    // 0x800004A8: jr          $ra
    // 0x800004AC: nop

    return;
    // 0x800004AC: nop

;}
RECOMP_FUNC void func_ovl8_8037F80C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F80C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8037F810: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8037F814: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8037F818: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8037F81C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8037F820: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8037F824: lwl         $t7, 0x8($a1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r5, 0X8);
    // 0x8037F828: lwr         $t7, 0xB($a1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r5, 0XB);
    // 0x8037F82C: addiu       $s2, $sp, 0x5C
    ctx->r18 = ADD32(ctx->r29, 0X5C);
    // 0x8037F830: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8037F834: swl         $t7, 0x0($s2)
    do_swl(rdram, 0X0, ctx->r18, ctx->r15);
    // 0x8037F838: swr         $t7, 0x3($s2)
    do_swr(rdram, 0X3, ctx->r18, ctx->r15);
    // 0x8037F83C: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x8037F840: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8037F844: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x8037F848: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x8037F84C: lh          $t8, 0x50($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X50);
    // 0x8037F850: jalr        $t9
    // 0x8037F854: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037F854: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    after_0:
    // 0x8037F858: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x8037F85C: lwl         $t2, 0x0($s2)
    ctx->r10 = do_lwl(rdram, ctx->r10, ctx->r18, 0X0);
    // 0x8037F860: lwr         $t2, 0x3($s2)
    ctx->r10 = do_lwr(rdram, ctx->r10, ctx->r18, 0X3);
    // 0x8037F864: lh          $t0, 0xA0($s0)
    ctx->r8 = MEM_H(ctx->r16, 0XA0);
    // 0x8037F868: swl         $t2, 0x4($sp)
    do_swl(rdram, 0X4, ctx->r29, ctx->r10);
    // 0x8037F86C: swr         $t2, 0x7($sp)
    do_swr(rdram, 0X7, ctx->r29, ctx->r10);
    // 0x8037F870: lw          $t9, 0xA4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XA4);
    // 0x8037F874: lw          $a1, 0x4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4);
    // 0x8037F878: addu        $a0, $t0, $s1
    ctx->r4 = ADD32(ctx->r8, ctx->r17);
    // 0x8037F87C: jalr        $t9
    // 0x8037F880: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8037F880: nop

    after_1:
    // 0x8037F884: bne         $v0, $zero, L_8037F894
    if (ctx->r2 != 0) {
        // 0x8037F888: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8037F894;
    }
    // 0x8037F888: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8037F88C: b           L_8037FBA4
    // 0x8037F890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037FBA4;
    // 0x8037F890: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037F894:
    // 0x8037F894: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x8037F898: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x8037F89C: lh          $t3, 0xD0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0XD0);
    // 0x8037F8A0: sw          $v1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r3;
    // 0x8037F8A4: lw          $t9, 0xD4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XD4);
    // 0x8037F8A8: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    // 0x8037F8AC: jalr        $t9
    // 0x8037F8B0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8037F8B0: nop

    after_2:
    // 0x8037F8B4: lh          $t4, 0x5C($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X5C);
    // 0x8037F8B8: lh          $t5, 0x50($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X50);
    // 0x8037F8BC: lh          $t7, 0x5E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5E);
    // 0x8037F8C0: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x8037F8C4: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8037F8C8: sh          $t6, 0x58($sp)
    MEM_H(0X58, ctx->r29) = ctx->r14;
    // 0x8037F8CC: subu        $t0, $t7, $t8
    ctx->r8 = SUB32(ctx->r15, ctx->r24);
    // 0x8037F8D0: sh          $t0, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r8;
    // 0x8037F8D4: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8037F8D8: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8037F8DC: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8037F8E0: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x8037F8E4: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8037F8E8: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8037F8EC: lw          $t9, 0xB4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB4);
    // 0x8037F8F0: lh          $t1, 0xB0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0XB0);
    // 0x8037F8F4: jalr        $t9
    // 0x8037F8F8: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x8037F8F8: addu        $a0, $t1, $v0
    ctx->r4 = ADD32(ctx->r9, ctx->r2);
    after_3:
    // 0x8037F8FC: lw          $v1, 0x4C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X4C);
    // 0x8037F900: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037F904: bnel        $v1, $at, L_8037FAC4
    if (ctx->r3 != ctx->r1) {
        // 0x8037F908: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8037FAC4;
    }
    goto skip_0;
    // 0x8037F908: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8037F90C: beq         $s1, $zero, L_8037F918
    if (ctx->r17 == 0) {
        // 0x8037F910: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8037F918;
    }
    // 0x8037F910: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8037F914: lw          $s0, 0x38($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X38);
L_8037F918:
    // 0x8037F918: jal         0x80377244
    // 0x8037F91C: nop

    func_ovl8_80377244(rdram, ctx);
        goto after_4;
    // 0x8037F91C: nop

    after_4:
    // 0x8037F920: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    // 0x8037F924: and         $t3, $v0, $t2
    ctx->r11 = ctx->r2 & ctx->r10;
    // 0x8037F928: beql        $t3, $zero, L_8037FBA4
    if (ctx->r11 == 0) {
        // 0x8037F92C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8037FBA4;
    }
    goto skip_1;
    // 0x8037F92C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_1:
    // 0x8037F930: lw          $t4, 0x3C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X3C);
L_8037F934:
    // 0x8037F934: lhu         $v0, 0x4A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X4A);
    // 0x8037F938: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x8037F93C: bne         $t4, $zero, L_8037F988
    if (ctx->r12 != 0) {
        // 0x8037F940: lh          $t5, 0x5E($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X5E);
            goto L_8037F988;
    }
    // 0x8037F940: lh          $t5, 0x5E($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X5E);
    // 0x8037F944: lh          $t5, 0x5C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X5C);
    // 0x8037F948: lh          $t6, 0x58($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X58);
    // 0x8037F94C: lh          $t8, 0x44($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X44);
    // 0x8037F950: lhu         $t1, 0x48($sp)
    ctx->r9 = MEM_HU(ctx->r29, 0X48);
    // 0x8037F954: lh          $t9, 0x40($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X40);
    // 0x8037F958: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8037F95C: subu        $t0, $t7, $t8
    ctx->r8 = SUB32(ctx->r15, ctx->r24);
    // 0x8037F960: subu        $t2, $t1, $t9
    ctx->r10 = SUB32(ctx->r9, ctx->r25);
    // 0x8037F964: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8037F968: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8037F96C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8037F970: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8037F974: lwc1        $f8, 0x4($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8037F978: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8037F97C: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8037F980: b           L_8037F9C0
    // 0x8037F984: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
        goto L_8037F9C0;
    // 0x8037F984: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
L_8037F988:
    // 0x8037F988: lh          $t7, 0x5A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5A);
    // 0x8037F98C: lh          $t0, 0x40($s1)
    ctx->r8 = MEM_H(ctx->r17, 0X40);
    // 0x8037F990: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x8037F994: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8037F998: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8037F99C: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x8037F9A0: mtc1        $t1, $f18
    ctx->f18.u32l = ctx->r9;
    // 0x8037F9A4: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8037F9A8: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8037F9AC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8037F9B0: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8037F9B4: div.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8037F9B8: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8037F9BC: add.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f16.fl;
L_8037F9C0:
    // 0x8037F9C0: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x8037F9C4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8037F9C8: lh          $t9, 0x40($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X40);
    // 0x8037F9CC: addu        $a0, $t9, $s1
    ctx->r4 = ADD32(ctx->r25, ctx->r17);
    // 0x8037F9D0: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x8037F9D4: jalr        $t9
    // 0x8037F9D8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8037F9D8: nop

    after_5:
    // 0x8037F9DC: jal         0x8037726C
    // 0x8037F9E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_ovl8_8037726C(rdram, ctx);
        goto after_6;
    // 0x8037F9E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x8037F9E4: lw          $v0, 0x38($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X38);
    // 0x8037F9E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8037F9EC: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x8037F9F0: lw          $t9, 0x54($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X54);
    // 0x8037F9F4: lh          $t2, 0x50($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X50);
    // 0x8037F9F8: jalr        $t9
    // 0x8037F9FC: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x8037F9FC: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    after_7:
    // 0x8037FA00: lh          $v1, 0x5C($sp)
    ctx->r3 = MEM_H(ctx->r29, 0X5C);
    // 0x8037FA04: lh          $a0, 0x5E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X5E);
    // 0x8037FA08: lhu         $v0, 0x48($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X48);
    // 0x8037FA0C: bgez        $v1, L_8037FA18
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8037FA10: nop
    
            goto L_8037FA18;
    }
    // 0x8037FA10: nop

    // 0x8037FA14: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037FA18:
    // 0x8037FA18: bgez        $a0, L_8037FA24
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8037FA1C: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8037FA24;
    }
    // 0x8037FA1C: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8037FA20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8037FA24:
    // 0x8037FA24: bne         $at, $zero, L_8037FA3C
    if (ctx->r1 != 0) {
        // 0x8037FA28: sh          $v1, 0x5C($sp)
        MEM_H(0X5C, ctx->r29) = ctx->r3;
            goto L_8037FA3C;
    }
    // 0x8037FA28: sh          $v1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r3;
    // 0x8037FA2C: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8037FA30: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x8037FA34: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8037FA38: sh          $v1, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r3;
L_8037FA3C:
    // 0x8037FA3C: lhu         $v0, 0x4A($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X4A);
    // 0x8037FA40: sh          $a0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r4;
    // 0x8037FA44: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8037FA48: bne         $at, $zero, L_8037FA5C
    if (ctx->r1 != 0) {
        // 0x8037FA4C: addiu       $a0, $v0, -0x1
        ctx->r4 = ADD32(ctx->r2, -0X1);
            goto L_8037FA5C;
    }
    // 0x8037FA4C: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x8037FA50: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x8037FA54: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8037FA58: sh          $a0, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r4;
L_8037FA5C:
    // 0x8037FA5C: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x8037FA60: beql        $v0, $zero, L_8037FA7C
    if (ctx->r2 == 0) {
        // 0x8037FA64: lw          $s0, 0x30($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X30);
            goto L_8037FA7C;
    }
    goto skip_2;
    // 0x8037FA64: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    skip_2:
    // 0x8037FA68: jalr        $v0
    // 0x8037FA6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_8;
    // 0x8037FA6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x8037FA70: b           L_8037FA8C
    // 0x8037FA74: nop

        goto L_8037FA8C;
    // 0x8037FA74: nop

    // 0x8037FA78: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
L_8037FA7C:
    // 0x8037FA7C: lw          $t9, 0x9C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X9C);
    // 0x8037FA80: lh          $t3, 0x98($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X98);
    // 0x8037FA84: jalr        $t9
    // 0x8037FA88: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x8037FA88: addu        $a0, $t3, $s1
    ctx->r4 = ADD32(ctx->r11, ctx->r17);
    after_9:
L_8037FA8C:
    // 0x8037FA8C: jal         0x8000B1E8
    // 0x8037FA90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_10;
    // 0x8037FA90: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x8037FA94: beq         $s1, $zero, L_8037FAA0
    if (ctx->r17 == 0) {
        // 0x8037FA98: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8037FAA0;
    }
    // 0x8037FA98: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x8037FA9C: lw          $s0, 0x38($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X38);
L_8037FAA0:
    // 0x8037FAA0: jal         0x80377244
    // 0x8037FAA4: nop

    func_ovl8_80377244(rdram, ctx);
        goto after_11;
    // 0x8037FAA4: nop

    after_11:
    // 0x8037FAA8: lw          $t4, 0x30($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X30);
    // 0x8037FAAC: and         $t5, $v0, $t4
    ctx->r13 = ctx->r2 & ctx->r12;
    // 0x8037FAB0: bnel        $t5, $zero, L_8037F934
    if (ctx->r13 != 0) {
        // 0x8037FAB4: lw          $t4, 0x3C($s1)
        ctx->r12 = MEM_W(ctx->r17, 0X3C);
            goto L_8037F934;
    }
    goto skip_3;
    // 0x8037FAB4: lw          $t4, 0x3C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X3C);
    skip_3:
    // 0x8037FAB8: b           L_8037FBA4
    // 0x8037FABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037FBA4;
    // 0x8037FABC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037FAC0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8037FAC4:
    // 0x8037FAC4: bnel        $v1, $at, L_8037FBA4
    if (ctx->r3 != ctx->r1) {
        // 0x8037FAC8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8037FBA4;
    }
    goto skip_4;
    // 0x8037FAC8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_4:
    // 0x8037FACC: lw          $t6, 0x3C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X3C);
    // 0x8037FAD0: lh          $t3, 0x5E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X5E);
    // 0x8037FAD4: lh          $t9, 0x46($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X46);
    // 0x8037FAD8: bne         $t6, $zero, L_8037FB24
    if (ctx->r14 != 0) {
        // 0x8037FADC: lhu         $t4, 0x4A($sp)
        ctx->r12 = MEM_HU(ctx->r29, 0X4A);
            goto L_8037FB24;
    }
    // 0x8037FADC: lhu         $t4, 0x4A($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X4A);
    // 0x8037FAE0: lh          $t7, 0x5C($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X5C);
    // 0x8037FAE4: lh          $t8, 0x44($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X44);
    // 0x8037FAE8: lhu         $t0, 0x48($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X48);
    // 0x8037FAEC: lh          $t1, 0x40($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X40);
    // 0x8037FAF0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8037FAF4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8037FAF8: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8037FAFC: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8037FB00: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8037FB04: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8037FB08: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8037FB0C: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8037FB10: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8037FB14: div.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8037FB18: mul.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8037FB1C: b           L_8037FB58
    // 0x8037FB20: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
        goto L_8037FB58;
    // 0x8037FB20: add.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f6.fl;
L_8037FB24:
    // 0x8037FB24: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8037FB28: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8037FB2C: lh          $t5, 0x40($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X40);
    // 0x8037FB30: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8037FB34: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x8037FB38: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8037FB3C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8037FB40: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8037FB44: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x8037FB48: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8037FB4C: div.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8037FB50: mul.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x8037FB54: add.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f4.fl;
L_8037FB58:
    // 0x8037FB58: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    // 0x8037FB5C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8037FB60: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x8037FB64: lh          $t7, 0x40($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X40);
    // 0x8037FB68: jalr        $t9
    // 0x8037FB6C: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_12;
    // 0x8037FB6C: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    after_12:
    // 0x8037FB70: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x8037FB74: beql        $v0, $zero, L_8037FB90
    if (ctx->r2 == 0) {
        // 0x8037FB78: lw          $s0, 0x30($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X30);
            goto L_8037FB90;
    }
    goto skip_5;
    // 0x8037FB78: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
    skip_5:
    // 0x8037FB7C: jalr        $v0
    // 0x8037FB80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_13;
    // 0x8037FB80: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8037FB84: b           L_8037FBA4
    // 0x8037FB88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037FBA4;
    // 0x8037FB88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8037FB8C: lw          $s0, 0x30($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X30);
L_8037FB90:
    // 0x8037FB90: lw          $t9, 0x9C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X9C);
    // 0x8037FB94: lh          $t8, 0x98($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X98);
    // 0x8037FB98: jalr        $t9
    // 0x8037FB9C: addu        $a0, $t8, $s1
    ctx->r4 = ADD32(ctx->r24, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x8037FB9C: addu        $a0, $t8, $s1
    ctx->r4 = ADD32(ctx->r24, ctx->r17);
    after_14:
    // 0x8037FBA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037FBA4:
    // 0x8037FBA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8037FBA8: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8037FBAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037FBB0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8037FBB4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8037FBB8: jr          $ra
    // 0x8037FBBC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8037FBBC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftPhysicsClampAirVelXMax(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8EB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8EBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8EC0: lw          $t6, 0x9C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C8);
    // 0x800D8EC4: jal         0x800D8E78
    // 0x800D8EC8: lw          $a1, 0x50($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X50);
    ftPhysicsClampAirVelX(rdram, ctx);
        goto after_0;
    // 0x800D8EC8: lw          $a1, 0x50($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X50);
    after_0:
    // 0x800D8ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8ED0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8ED4: jr          $ra
    // 0x800D8ED8: nop

    return;
    // 0x800D8ED8: nop

;}
RECOMP_FUNC void func_ovl59_80131D30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D30: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80131D34: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80131D38: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80131D3C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80131D40: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x80131D44: sw          $a2, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r6;
    // 0x80131D48: sw          $a3, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r7;
    // 0x80131D4C: lwc1        $f4, 0x30($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80131D50: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x80131D54: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x80131D58: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x80131D5C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x80131D60: lwc1        $f6, 0x34($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X34);
    // 0x80131D64: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80131D68: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x80131D6C: lwc1        $f8, 0x38($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80131D70: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x80131D74: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80131D78: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x80131D7C: lwc1        $f16, 0x44($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80131D80: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80131D84: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80131D88: jal         0x8001C524
    // 0x80131D8C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    syMatrixTraRotRpyRScaF(rdram, ctx);
        goto after_0;
    // 0x80131D8C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_0:
    // 0x80131D90: addiu       $s0, $sp, 0x38
    ctx->r16 = ADD32(ctx->r29, 0X38);
    // 0x80131D94: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80131D98: addiu       $a1, $a1, -0x55E8
    ctx->r5 = ADD32(ctx->r5, -0X55E8);
    // 0x80131D9C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80131DA0: jal         0x80034980
    // 0x80131DA4: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    guMtxCatF(rdram, ctx);
        goto after_1;
    // 0x80131DA4: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    after_1:
    // 0x80131DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131DAC: lw          $a1, 0xBC($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XBC);
    // 0x80131DB0: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x80131DB4: jal         0x80131BB0
    // 0x80131DB8: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    func_ovl59_80131BB0(rdram, ctx);
        goto after_2;
    // 0x80131DB8: lw          $a3, 0xC4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XC4);
    after_2:
    // 0x80131DBC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80131DC0: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80131DC4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x80131DC8: jr          $ra
    // 0x80131DCC: nop

    return;
    // 0x80131DCC: nop

;}
RECOMP_FUNC void func_ovl8_80372554(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80372558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037255C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80372560: beq         $a0, $zero, L_803725CC
    if (ctx->r4 == 0) {
        // 0x80372564: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_803725CC;
    }
    // 0x80372564: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80372568: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8037256C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80372570: addiu       $t6, $t6, -0x7360
    ctx->r14 = ADD32(ctx->r14, -0X7360);
    // 0x80372574: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80372578: addiu       $t7, $t7, -0x72F8
    ctx->r15 = ADD32(ctx->r15, -0X72F8);
    // 0x8037257C: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    // 0x80372580: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80372584: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80372588: jal         0x803720D4
    // 0x8037258C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803720D4(rdram, ctx);
        goto after_0;
    // 0x8037258C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80372590: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x80372594: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80372598: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037259C: beql        $t9, $zero, L_803725B8
    if (ctx->r25 == 0) {
        // 0x803725A0: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_803725B8;
    }
    goto skip_0;
    // 0x803725A0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x803725A4: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    // 0x803725A8: jal         0x803718C4
    // 0x803725AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_ovl8_803718C4(rdram, ctx);
        goto after_1;
    // 0x803725AC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_1:
    // 0x803725B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x803725B4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
L_803725B8:
    // 0x803725B8: andi        $t1, $t0, 0x1
    ctx->r9 = ctx->r8 & 0X1;
    // 0x803725BC: beql        $t1, $zero, L_803725D0
    if (ctx->r9 == 0) {
        // 0x803725C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803725D0;
    }
    goto skip_1;
    // 0x803725C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x803725C4: jal         0x803717C0
    // 0x803725C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_2;
    // 0x803725C8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
L_803725CC:
    // 0x803725CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803725D0:
    // 0x803725D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803725D4: jr          $ra
    // 0x803725D8: nop

    return;
    // 0x803725D8: nop

;}
RECOMP_FUNC void mnVSResultsMakeWallpaperTintCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135028: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013502C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135030: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80135034: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80135038: addiu       $t7, $zero, 0x37
    ctx->r15 = ADD32(0, 0X37);
    // 0x8013503C: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x80135040: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80135044: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80135048: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013504C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135050: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80135054: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80135058: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013505C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135060: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135064: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135068: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013506C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80135070: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80135074: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80135078: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013507C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135080: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80135084: jal         0x8000B93C
    // 0x80135088: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80135088: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013508C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135090: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135094: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135098: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013509C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801350A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801350A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801350A8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801350AC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801350B0: jal         0x80007080
    // 0x801350B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801350B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801350B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801350BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801350C0: jr          $ra
    // 0x801350C4: nop

    return;
    // 0x801350C4: nop

;}
RECOMP_FUNC void lbRelocGetInternBufferFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDCAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CDCB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CDCB4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CDCB8: jal         0x800CD620
    // 0x800CDCBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    lbRelocFindStatusBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CDCBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CDCC0: beq         $v0, $zero, L_800CDCD0
    if (ctx->r2 == 0) {
        // 0x800CDCC4: lui         $s0, 0x800D
        ctx->r16 = S32(0X800D << 16);
            goto L_800CDCD0;
    }
    // 0x800CDCC4: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800CDCC8: b           L_800CDD4C
    // 0x800CDCCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800CDD4C;
    // 0x800CDCCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CDCD0:
    // 0x800CDCD0: lw          $s0, 0x62F0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X62F0);
    // 0x800CDCD4: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800CDCD8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CDCDC: addiu       $s0, $s0, 0xF
    ctx->r16 = ADD32(ctx->r16, 0XF);
    // 0x800CDCE0: jal         0x800CD814
    // 0x800CDCE4: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
    lbRelocReadDmaTableEntry(rdram, ctx);
        goto after_1;
    // 0x800CDCE4: and         $s0, $s0, $at
    ctx->r16 = ctx->r16 & ctx->r1;
    after_1:
    // 0x800CDCE8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CDCEC: lw          $t6, 0x6334($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6334);
    // 0x800CDCF0: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CDCF4: addiu       $v1, $v1, 0x62E0
    ctx->r3 = ADD32(ctx->r3, 0X62E0);
    // 0x800CDCF8: lhu         $a2, 0xA($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0XA);
    // 0x800CDCFC: lw          $t7, 0x14($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14);
    // 0x800CDD00: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CDD04: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800CDD08: addu        $v0, $s0, $a2
    ctx->r2 = ADD32(ctx->r16, ctx->r6);
    // 0x800CDD0C: sltu        $at, $t7, $v0
    ctx->r1 = ctx->r15 < ctx->r2 ? 1 : 0;
    // 0x800CDD10: beq         $at, $zero, L_800CDD38
    if (ctx->r1 == 0) {
        // 0x800CDD14: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800CDD38;
    }
    // 0x800CDD14: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800CDD18: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800CDD1C: addiu       $s0, $s0, 0x5F88
    ctx->r16 = ADD32(ctx->r16, 0X5F88);
L_800CDD20:
    // 0x800CDD20: jal         0x80023624
    // 0x800CDD24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800CDD24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800CDD28: jal         0x800A3040
    // 0x800CDD2C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800CDD2C: nop

    after_3:
    // 0x800CDD30: b           L_800CDD20
    // 0x800CDD34: nop

        goto L_800CDD20;
    // 0x800CDD34: nop

L_800CDD38:
    // 0x800CDD38: sw          $v0, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r2;
    // 0x800CDD3C: jal         0x800CD854
    // 0x800CDD40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    lbRelocLoadAndRelocFile(rdram, ctx);
        goto after_4;
    // 0x800CDD40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x800CDD44: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CDD48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800CDD4C:
    // 0x800CDD4C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CDD50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CDD54: jr          $ra
    // 0x800CDD58: nop

    return;
    // 0x800CDD58: nop

;}
RECOMP_FUNC void sc1PStageClearGetScoreDigitSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D70: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131D74: addiu       $t6, $t6, 0x5114
    ctx->r14 = ADD32(ctx->r14, 0X5114);
    // 0x80131D78: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131D7C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80131D80: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x80131D84: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80131D88: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80131D8C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131D90: addiu       $a3, $sp, 0x4
    ctx->r7 = ADD32(ctx->r29, 0X4);
    // 0x80131D94: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80131D98: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80131D9C: addiu       $t9, $t9, 0x5120
    ctx->r25 = ADD32(ctx->r25, 0X5120);
    // 0x80131DA0: addiu       $t3, $t9, 0x78
    ctx->r11 = ADD32(ctx->r25, 0X78);
    // 0x80131DA4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x80131DA8: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
L_80131DAC:
    // 0x80131DAC: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80131DB0: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131DB4: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80131DB8: sw          $t1, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r9;
    // 0x80131DBC: lw          $t0, -0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, -0X8);
    // 0x80131DC0: sw          $t0, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r8;
    // 0x80131DC4: lw          $t1, -0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, -0X4);
    // 0x80131DC8: bne         $t9, $t3, L_80131DAC
    if (ctx->r25 != ctx->r11) {
        // 0x80131DCC: sw          $t1, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r9;
            goto L_80131DAC;
    }
    // 0x80131DCC: sw          $t1, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r9;
    // 0x80131DD0: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80131DD4: addu        $t8, $a2, $v1
    ctx->r24 = ADD32(ctx->r6, ctx->r3);
    // 0x80131DD8: lw          $t3, 0x0($t8)
    ctx->r11 = MEM_W(ctx->r24, 0X0);
    // 0x80131DDC: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x80131DE0: subu        $t4, $t4, $a1
    ctx->r12 = SUB32(ctx->r12, ctx->r5);
    // 0x80131DE4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80131DE8: addu        $t5, $a3, $t4
    ctx->r13 = ADD32(ctx->r7, ctx->r12);
    // 0x80131DEC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131DF0: sll         $t9, $t3, 2
    ctx->r25 = S32(ctx->r11 << 2);
    // 0x80131DF4: addu        $t2, $t2, $t9
    ctx->r10 = ADD32(ctx->r10, ctx->r25);
    // 0x80131DF8: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x80131DFC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80131E00: lw          $t2, 0x5588($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X5588);
    // 0x80131E04: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80131E08: jr          $ra
    // 0x80131E0C: addu        $v0, $t7, $t2
    ctx->r2 = ADD32(ctx->r15, ctx->r10);
    return;
    // 0x80131E0C: addu        $v0, $t7, $t2
    ctx->r2 = ADD32(ctx->r15, ctx->r10);
;}
RECOMP_FUNC void mnMapsMakePreviewCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A88: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80133A8C: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80133A90: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80133A94: addiu       $t6, $t6, 0x7DBC
    ctx->r14 = ADD32(ctx->r14, 0X7DBC);
    // 0x80133A98: addiu       $t7, $zero, 0x41
    ctx->r15 = ADD32(0, 0X41);
    // 0x80133A9C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133AA0: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80133AA4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133AA8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133AAC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133AB0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80133AB4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133AB8: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80133ABC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133AC0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133AC4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133AC8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133ACC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133AD0: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80133AD4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133AD8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133ADC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133AE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133AE4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133AE8: jal         0x8000B93C
    // 0x80133AEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133AEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133AF0: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x80133AF4: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x80133AF8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133AFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133B00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133B04: sw          $s0, 0x4C14($at)
    MEM_W(0X4C14, ctx->r1) = ctx->r16;
    // 0x80133B08: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133B0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133B10: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133B14: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133B18: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133B1C: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80133B20: jal         0x80007080
    // 0x80133B24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133B24: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133B28: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80133B2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133B30: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133B34: swc1        $f6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f6.u32l;
    // 0x80133B38: jal         0x80132430
    // 0x80133B3C: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_2;
    // 0x80133B3C: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_2:
    // 0x80133B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133B44: jal         0x8013390C
    // 0x80133B48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    mnMapsSetPreviewCameraPosition(rdram, ctx);
        goto after_3;
    // 0x80133B48: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80133B4C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133B50: addiu       $a1, $a1, 0x39C4
    ctx->r5 = ADD32(ctx->r5, 0X39C4);
    // 0x80133B54: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80133B58: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133B5C: jal         0x80008188
    // 0x80133B60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80133B60: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80133B64: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80133B68: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80133B6C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80133B70: jr          $ra
    // 0x80133B74: nop

    return;
    // 0x80133B74: nop

;}
RECOMP_FUNC void itBombHeiWalkProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801776A0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801776A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801776A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801776AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801776B0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801776B4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801776B8: lw          $t6, 0x2D4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X2D4);
    // 0x801776BC: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x801776C0: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x801776C4: jal         0x8017761C
    // 0x801776C8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    itBombHeiWalkUpdateEffect(rdram, ctx);
        goto after_0;
    // 0x801776C8: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    after_0:
    // 0x801776CC: jal         0x800FC67C
    // 0x801776D0: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_1;
    // 0x801776D0: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    after_1:
    // 0x801776D4: beql        $v0, $zero, L_80177790
    if (ctx->r2 == 0) {
        // 0x801776D8: lhu         $v1, 0x33E($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X33E);
            goto L_80177790;
    }
    goto skip_0;
    // 0x801776D8: lhu         $v1, 0x33E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X33E);
    skip_0:
    // 0x801776DC: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x801776E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801776E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x801776E8: bne         $t8, $at, L_80177744
    if (ctx->r24 != ctx->r1) {
        // 0x801776EC: nop
    
            goto L_80177744;
    }
    // 0x801776EC: nop

    // 0x801776F0: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    // 0x801776F4: jal         0x800F4428
    // 0x801776F8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_2;
    // 0x801776F8: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x801776FC: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80177700: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80177704: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80177708: lh          $t1, 0x30($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X30);
    // 0x8017770C: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x80177710: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80177714: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80177718: nop

    // 0x8017771C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80177720: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80177724: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x80177728: nop

    // 0x8017772C: bc1fl       L_80177790
    if (!c1cs) {
        // 0x80177730: lhu         $v1, 0x33E($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X33E);
            goto L_80177790;
    }
    goto skip_1;
    // 0x80177730: lhu         $v1, 0x33E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X33E);
    skip_1:
    // 0x80177734: jal         0x80177104
    // 0x80177738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itBombHeiCommonSetWalkLR(rdram, ctx);
        goto after_3;
    // 0x80177738: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x8017773C: b           L_80177790
    // 0x80177740: lhu         $v1, 0x33E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X33E);
        goto L_80177790;
    // 0x80177740: lhu         $v1, 0x33E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X33E);
L_80177744:
    // 0x80177744: jal         0x800F4408
    // 0x80177748: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_4;
    // 0x80177748: lw          $a0, 0xAC($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XAC);
    after_4:
    // 0x8017774C: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x80177750: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x80177754: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80177758: lh          $t4, 0x30($t3)
    ctx->r12 = MEM_H(ctx->r11, 0X30);
    // 0x8017775C: lwc1        $f18, 0x1C($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x80177760: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80177764: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80177768: nop

    // 0x8017776C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80177770: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80177774: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x80177778: nop

    // 0x8017777C: bc1fl       L_80177790
    if (!c1cs) {
        // 0x80177780: lhu         $v1, 0x33E($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X33E);
            goto L_80177790;
    }
    goto skip_2;
    // 0x80177780: lhu         $v1, 0x33E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X33E);
    skip_2:
    // 0x80177784: jal         0x80177104
    // 0x80177788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    itBombHeiCommonSetWalkLR(rdram, ctx);
        goto after_5;
    // 0x80177788: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8017778C: lhu         $v1, 0x33E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X33E);
L_80177790:
    // 0x80177790: addiu       $at, $zero, 0x1E0
    ctx->r1 = ADD32(0, 0X1E0);
    // 0x80177794: bnel        $v1, $at, L_801777BC
    if (ctx->r3 != ctx->r1) {
        // 0x80177798: addiu       $t5, $v1, 0x1
        ctx->r13 = ADD32(ctx->r3, 0X1);
            goto L_801777BC;
    }
    goto skip_3;
    // 0x80177798: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
    skip_3:
    // 0x8017779C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801777A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801777A4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x801777A8: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x801777AC: jal         0x80177D60
    // 0x801777B0: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    itBombHeiExplodeWaitSetStatus(rdram, ctx);
        goto after_6;
    // 0x801777B0: swc1        $f0, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f0.u32l;
    after_6:
    // 0x801777B4: lhu         $v1, 0x33E($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X33E);
    // 0x801777B8: addiu       $t5, $v1, 0x1
    ctx->r13 = ADD32(ctx->r3, 0X1);
L_801777BC:
    // 0x801777BC: sh          $t5, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r13;
    // 0x801777C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801777C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801777C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801777CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801777D0: jr          $ra
    // 0x801777D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x801777D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mnVSResultsSetRoyalPlace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136D28: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80136D2C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80136D30: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80136D34: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80136D38: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80136D3C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80136D40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80136D44: addiu       $v1, $v1, -0x6430
    ctx->r3 = ADD32(ctx->r3, -0X6430);
    // 0x80136D48: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80136D4C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_80136D50:
    // 0x80136D50: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80136D54: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x80136D58: subu        $t7, $t7, $s3
    ctx->r15 = SUB32(ctx->r15, ctx->r19);
    // 0x80136D5C: beq         $t6, $zero, L_80136DB0
    if (ctx->r14 == 0) {
        // 0x80136D60: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80136DB0;
    }
    // 0x80136D60: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80136D64: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    // 0x80136D68: subu        $t9, $t9, $s1
    ctx->r25 = SUB32(ctx->r25, ctx->r17);
    // 0x80136D6C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80136D70: addu        $t9, $t9, $s1
    ctx->r25 = ADD32(ctx->r25, ctx->r17);
    // 0x80136D74: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80136D78: addiu       $t2, $t2, 0x4EF8
    ctx->r10 = ADD32(ctx->r10, 0X4EF8);
    // 0x80136D7C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80136D80: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80136D84: addiu       $t8, $sp, 0x50
    ctx->r24 = ADD32(ctx->r29, 0X50);
    // 0x80136D88: addu        $s0, $t7, $t8
    ctx->r16 = ADD32(ctx->r15, ctx->r24);
    // 0x80136D8C: addu        $s2, $t9, $t2
    ctx->r18 = ADD32(ctx->r25, ctx->r10);
    // 0x80136D90: jal         0x80136C08
    // 0x80136D94: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    mnVSResultsGetPointsDirect(rdram, ctx);
        goto after_0;
    // 0x80136D94: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x80136D98: lbu         $t3, 0x2D($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X2D);
    // 0x80136D9C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x80136DA0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80136DA4: sw          $s1, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r17;
    // 0x80136DA8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80136DAC: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
L_80136DB0:
    // 0x80136DB0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80136DB4: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x80136DB8: bne         $at, $zero, L_80136D50
    if (ctx->r1 != 0) {
        // 0x80136DBC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80136D50;
    }
    // 0x80136DBC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80136DC0: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80136DC4: jal         0x80136C2C
    // 0x80136DC8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mnVSResultsOrderResults(rdram, ctx);
        goto after_1;
    // 0x80136DC8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_1:
    // 0x80136DCC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80136DD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80136DD4: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80136DD8: blez        $s3, L_80136F9C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x80136DDC: lw          $a2, 0x54($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X54);
            goto L_80136F9C;
    }
    // 0x80136DDC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x80136DE0: andi        $v1, $s3, 0x3
    ctx->r3 = ctx->r19 & 0X3;
    // 0x80136DE4: beq         $v1, $zero, L_80136E60
    if (ctx->r3 == 0) {
        // 0x80136DE8: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_80136E60;
    }
    // 0x80136DE8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80136DEC: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x80136DF0: subu        $t4, $t4, $zero
    ctx->r12 = SUB32(ctx->r12, 0);
    // 0x80136DF4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80136DF8: addiu       $t5, $sp, 0x50
    ctx->r13 = ADD32(ctx->r29, 0X50);
    // 0x80136DFC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80136E00: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80136E04: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
    // 0x80136E08: addiu       $t0, $t0, -0x6450
    ctx->r8 = ADD32(ctx->r8, -0X6450);
    // 0x80136E0C: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
L_80136E10:
    // 0x80136E10: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80136E14: bnel        $a1, $v1, L_80136E38
    if (ctx->r5 != ctx->r3) {
        // 0x80136E18: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80136E38;
    }
    goto skip_0;
    // 0x80136E18: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_0:
    // 0x80136E1C: lbu         $t6, 0x10($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X10);
    // 0x80136E20: beql        $t6, $zero, L_80136E44
    if (ctx->r14 == 0) {
        // 0x80136E24: lw          $t8, 0x8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X8);
            goto L_80136E44;
    }
    goto skip_1;
    // 0x80136E24: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    skip_1:
    // 0x80136E28: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80136E2C: beql        $a2, $t7, L_80136E44
    if (ctx->r6 == ctx->r15) {
        // 0x80136E30: lw          $t8, 0x8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X8);
            goto L_80136E44;
    }
    goto skip_2;
    // 0x80136E30: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    skip_2:
    // 0x80136E34: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80136E38:
    // 0x80136E38: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80136E3C: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80136E40: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
L_80136E44:
    // 0x80136E44: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80136E48: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x80136E4C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80136E50: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x80136E54: bne         $t1, $s1, L_80136E10
    if (ctx->r9 != ctx->r17) {
        // 0x80136E58: sw          $a0, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r4;
            goto L_80136E10;
    }
    // 0x80136E58: sw          $a0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r4;
    // 0x80136E5C: beq         $s1, $s3, L_80136F9C
    if (ctx->r17 == ctx->r19) {
        // 0x80136E60: sll         $t3, $s1, 2
        ctx->r11 = S32(ctx->r17 << 2);
            goto L_80136F9C;
    }
L_80136E60:
    // 0x80136E60: sll         $t3, $s1, 2
    ctx->r11 = S32(ctx->r17 << 2);
    // 0x80136E64: sll         $t5, $s3, 2
    ctx->r13 = S32(ctx->r19 << 2);
    // 0x80136E68: subu        $t5, $t5, $s3
    ctx->r13 = SUB32(ctx->r13, ctx->r19);
    // 0x80136E6C: subu        $t3, $t3, $s1
    ctx->r11 = SUB32(ctx->r11, ctx->r17);
    // 0x80136E70: addiu       $t4, $sp, 0x50
    ctx->r12 = ADD32(ctx->r29, 0X50);
    // 0x80136E74: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80136E78: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80136E7C: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80136E80: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80136E84: addiu       $t0, $t0, -0x6450
    ctx->r8 = ADD32(ctx->r8, -0X6450);
    // 0x80136E88: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
    // 0x80136E8C: addu        $t1, $t5, $t4
    ctx->r9 = ADD32(ctx->r13, ctx->r12);
    // 0x80136E90: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
L_80136E94:
    // 0x80136E94: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80136E98: bnel        $a1, $v1, L_80136EBC
    if (ctx->r5 != ctx->r3) {
        // 0x80136E9C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80136EBC;
    }
    goto skip_3;
    // 0x80136E9C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_3:
    // 0x80136EA0: lbu         $t6, 0x10($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X10);
    // 0x80136EA4: beql        $t6, $zero, L_80136EC8
    if (ctx->r14 == 0) {
        // 0x80136EA8: lw          $t8, 0x8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X8);
            goto L_80136EC8;
    }
    goto skip_4;
    // 0x80136EA8: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    skip_4:
    // 0x80136EAC: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80136EB0: beql        $a2, $t7, L_80136EC8
    if (ctx->r6 == ctx->r15) {
        // 0x80136EB4: lw          $t8, 0x8($v0)
        ctx->r24 = MEM_W(ctx->r2, 0X8);
            goto L_80136EC8;
    }
    goto skip_5;
    // 0x80136EB4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    skip_5:
    // 0x80136EB8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80136EBC:
    // 0x80136EBC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80136EC0: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80136EC4: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
L_80136EC8:
    // 0x80136EC8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80136ECC: addu        $t2, $t0, $t9
    ctx->r10 = ADD32(ctx->r8, ctx->r25);
    // 0x80136ED0: sw          $a0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r4;
    // 0x80136ED4: lw          $v1, 0xC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XC);
    // 0x80136ED8: bnel        $a1, $v1, L_80136EFC
    if (ctx->r5 != ctx->r3) {
        // 0x80136EDC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80136EFC;
    }
    goto skip_6;
    // 0x80136EDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_6:
    // 0x80136EE0: lbu         $t3, 0x10($a3)
    ctx->r11 = MEM_BU(ctx->r7, 0X10);
    // 0x80136EE4: beql        $t3, $zero, L_80136F08
    if (ctx->r11 == 0) {
        // 0x80136EE8: lw          $t4, 0x14($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X14);
            goto L_80136F08;
    }
    goto skip_7;
    // 0x80136EE8: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    skip_7:
    // 0x80136EEC: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x80136EF0: beql        $a2, $t5, L_80136F08
    if (ctx->r6 == ctx->r13) {
        // 0x80136EF4: lw          $t4, 0x14($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X14);
            goto L_80136F08;
    }
    goto skip_8;
    // 0x80136EF4: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
    skip_8:
    // 0x80136EF8: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80136EFC:
    // 0x80136EFC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80136F00: lw          $a2, 0x10($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X10);
    // 0x80136F04: lw          $t4, 0x14($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X14);
L_80136F08:
    // 0x80136F08: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80136F0C: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x80136F10: sw          $a0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r4;
    // 0x80136F14: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x80136F18: bnel        $a1, $v1, L_80136F3C
    if (ctx->r5 != ctx->r3) {
        // 0x80136F1C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80136F3C;
    }
    goto skip_9;
    // 0x80136F1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_9:
    // 0x80136F20: lbu         $t8, 0x10($a3)
    ctx->r24 = MEM_BU(ctx->r7, 0X10);
    // 0x80136F24: beql        $t8, $zero, L_80136F48
    if (ctx->r24 == 0) {
        // 0x80136F28: lw          $t2, 0x20($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X20);
            goto L_80136F48;
    }
    goto skip_10;
    // 0x80136F28: lw          $t2, 0x20($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X20);
    skip_10:
    // 0x80136F2C: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x80136F30: beql        $a2, $t9, L_80136F48
    if (ctx->r6 == ctx->r25) {
        // 0x80136F34: lw          $t2, 0x20($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X20);
            goto L_80136F48;
    }
    goto skip_11;
    // 0x80136F34: lw          $t2, 0x20($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X20);
    skip_11:
    // 0x80136F38: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80136F3C:
    // 0x80136F3C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80136F40: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x80136F44: lw          $t2, 0x20($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X20);
L_80136F48:
    // 0x80136F48: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80136F4C: addu        $t5, $t0, $t3
    ctx->r13 = ADD32(ctx->r8, ctx->r11);
    // 0x80136F50: sw          $a0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r4;
    // 0x80136F54: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x80136F58: bnel        $a1, $v1, L_80136F7C
    if (ctx->r5 != ctx->r3) {
        // 0x80136F5C: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80136F7C;
    }
    goto skip_12;
    // 0x80136F5C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    skip_12:
    // 0x80136F60: lbu         $t4, 0x10($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X10);
    // 0x80136F64: beql        $t4, $zero, L_80136F88
    if (ctx->r12 == 0) {
        // 0x80136F68: lw          $t7, 0x2C($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X2C);
            goto L_80136F88;
    }
    goto skip_13;
    // 0x80136F68: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    skip_13:
    // 0x80136F6C: lw          $t6, 0x28($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X28);
    // 0x80136F70: beql        $a2, $t6, L_80136F88
    if (ctx->r6 == ctx->r14) {
        // 0x80136F74: lw          $t7, 0x2C($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X2C);
            goto L_80136F88;
    }
    goto skip_14;
    // 0x80136F74: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
    skip_14:
    // 0x80136F78: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_80136F7C:
    // 0x80136F7C: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80136F80: lw          $a2, 0x28($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X28);
    // 0x80136F84: lw          $t7, 0x2C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C);
L_80136F88:
    // 0x80136F88: addiu       $v0, $v0, 0x30
    ctx->r2 = ADD32(ctx->r2, 0X30);
    // 0x80136F8C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80136F90: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x80136F94: bne         $v0, $t1, L_80136E94
    if (ctx->r2 != ctx->r9) {
        // 0x80136F98: sw          $a0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->r4;
            goto L_80136E94;
    }
    // 0x80136F98: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
L_80136F9C:
    // 0x80136F9C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80136FA0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80136FA4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80136FA8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80136FAC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80136FB0: jr          $ra
    // 0x80136FB4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80136FB4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void __CSPHandleMetaMsg(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800291AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800291B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800291B4: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x800291B8: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800291BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800291C0: bne         $t6, $at, L_80029398
    if (ctx->r14 != ctx->r1) {
        // 0x800291C4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80029398;
    }
    // 0x800291C4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800291C8: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x800291CC: addiu       $at, $zero, 0x51
    ctx->r1 = ADD32(0, 0X51);
    // 0x800291D0: addiu       $v0, $a1, 0x4
    ctx->r2 = ADD32(ctx->r5, 0X4);
    // 0x800291D4: bnel        $t7, $at, L_8002939C
    if (ctx->r15 != ctx->r1) {
        // 0x800291D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002939C;
    }
    goto skip_0;
    // 0x800291D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800291DC: lbu         $t6, 0x8($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X8);
    // 0x800291E0: lbu         $t8, 0x7($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X7);
    // 0x800291E4: lw          $s7, 0x2C($s6)
    ctx->r23 = MEM_W(ctx->r22, 0X2C);
    // 0x800291E8: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800291EC: lbu         $t6, 0x9($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X9);
    // 0x800291F0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800291F4: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x800291F8: or          $v1, $t8, $t6
    ctx->r3 = ctx->r24 | ctx->r14;
    // 0x800291FC: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x80029200: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80029204: jal         0x80029170
    // 0x80029208: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    __setUsptFromTempo(rdram, ctx);
        goto after_0;
    // 0x80029208: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x8002920C: lw          $s1, 0x58($s6)
    ctx->r17 = MEM_W(ctx->r22, 0X58);
    // 0x80029210: beq         $s1, $zero, L_80029298
    if (ctx->r17 == 0) {
        // 0x80029214: nop
    
            goto L_80029298;
    }
    // 0x80029214: nop

    // 0x80029218: addiu       $s4, $zero, 0x15
    ctx->r20 = ADD32(0, 0X15);
L_8002921C:
    // 0x8002921C: lh          $t7, 0xC($s1)
    ctx->r15 = MEM_H(ctx->r17, 0XC);
    // 0x80029220: lw          $t9, 0x8($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X8);
    // 0x80029224: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x80029228: bne         $s4, $t7, L_80029290
    if (ctx->r20 != ctx->r15) {
        // 0x8002922C: addu        $s3, $s3, $t9
        ctx->r19 = ADD32(ctx->r19, ctx->r25);
            goto L_80029290;
    }
    // 0x8002922C: addu        $s3, $s3, $t9
    ctx->r19 = ADD32(ctx->r19, ctx->r25);
    // 0x80029230: jal         0x80028C84
    // 0x80029234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    alUnlink(rdram, ctx);
        goto after_1;
    // 0x80029234: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80029238: beql        $s0, $zero, L_80029268
    if (ctx->r16 == 0) {
        // 0x8002923C: sw          $zero, 0x0($s1)
        MEM_W(0X0, ctx->r17) = 0;
            goto L_80029268;
    }
    goto skip_1;
    // 0x8002923C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    skip_1:
    // 0x80029240: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80029244: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    // 0x80029248: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8002924C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80029250: beq         $v0, $zero, L_8002925C
    if (ctx->r2 == 0) {
        // 0x80029254: nop
    
            goto L_8002925C;
    }
    // 0x80029254: nop

    // 0x80029258: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
L_8002925C:
    // 0x8002925C: b           L_80029270
    // 0x80029260: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
        goto L_80029270;
    // 0x80029260: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // 0x80029264: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80029268:
    // 0x80029268: sw          $zero, 0x4($s1)
    MEM_W(0X4, ctx->r17) = 0;
    // 0x8002926C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80029270:
    // 0x80029270: beq         $s2, $zero, L_8002928C
    if (ctx->r18 == 0) {
        // 0x80029274: or          $v1, $s3, $zero
        ctx->r3 = ctx->r19 | 0;
            goto L_8002928C;
    }
    // 0x80029274: or          $v1, $s3, $zero
    ctx->r3 = ctx->r19 | 0;
    // 0x80029278: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    // 0x8002927C: lw          $t6, 0x8($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X8);
    // 0x80029280: subu        $s3, $s3, $v0
    ctx->r19 = SUB32(ctx->r19, ctx->r2);
    // 0x80029284: addu        $t9, $t6, $v0
    ctx->r25 = ADD32(ctx->r14, ctx->r2);
    // 0x80029288: sw          $t9, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r25;
L_8002928C:
    // 0x8002928C: sw          $v1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r3;
L_80029290:
    // 0x80029290: bne         $s2, $zero, L_8002921C
    if (ctx->r18 != 0) {
        // 0x80029294: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_8002921C;
    }
    // 0x80029294: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80029298:
    // 0x80029298: beq         $s0, $zero, L_80029398
    if (ctx->r16 == 0) {
        // 0x8002929C: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80029398;
    }
    // 0x8002929C: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800292A0: addiu       $s3, $s6, 0x50
    ctx->r19 = ADD32(ctx->r22, 0X50);
    // 0x800292A4: addiu       $s4, $s3, 0x8
    ctx->r20 = ADD32(ctx->r19, 0X8);
    // 0x800292A8: addiu       $s5, $zero, -0x8
    ctx->r21 = ADD32(0, -0X8);
L_800292AC:
    // 0x800292AC: lw          $t7, 0x8($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X8);
    // 0x800292B0: lw          $t8, 0x2C($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X2C);
    // 0x800292B4: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x800292B8: div         $zero, $t7, $s7
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r23)));
    // 0x800292BC: mflo        $v0
    ctx->r2 = lo;
    // 0x800292C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800292C4: bne         $s7, $zero, L_800292D0
    if (ctx->r23 != 0) {
        // 0x800292C8: nop
    
            goto L_800292D0;
    }
    // 0x800292C8: nop

    // 0x800292CC: break       7
    do_break(2147652300);
L_800292D0:
    // 0x800292D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800292D4: bne         $s7, $at, L_800292E8
    if (ctx->r23 != ctx->r1) {
        // 0x800292D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800292E8;
    }
    // 0x800292D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800292DC: bne         $t7, $at, L_800292E8
    if (ctx->r15 != ctx->r1) {
        // 0x800292E0: nop
    
            goto L_800292E8;
    }
    // 0x800292E0: nop

    // 0x800292E4: break       6
    do_break(2147652324);
L_800292E8:
    // 0x800292E8: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800292EC: or          $s0, $s4, $zero
    ctx->r16 = ctx->r20 | 0;
    // 0x800292F0: mflo        $t6
    ctx->r14 = lo;
    // 0x800292F4: sw          $t6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r14;
    // 0x800292F8: jal         0x80030350
    // 0x800292FC: nop

    osSetIntMask_recomp(rdram, ctx);
        goto after_2;
    // 0x800292FC: nop

    after_2:
    // 0x80029300: beq         $s3, $s5, L_80029388
    if (ctx->r19 == ctx->r21) {
        // 0x80029304: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80029388;
    }
    // 0x80029304: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80029308: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
L_8002930C:
    // 0x8002930C: bnel        $a0, $zero, L_80029338
    if (ctx->r4 != 0) {
        // 0x80029310: lw          $v0, 0x8($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X8);
            goto L_80029338;
    }
    goto skip_2;
    // 0x80029310: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
    skip_2:
    // 0x80029314: sw          $a0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r4;
    // 0x80029318: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    // 0x8002931C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80029320: beq         $a0, $zero, L_8002932C
    if (ctx->r4 == 0) {
        // 0x80029324: nop
    
            goto L_8002932C;
    }
    // 0x80029324: nop

    // 0x80029328: sw          $s1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r17;
L_8002932C:
    // 0x8002932C: b           L_80029388
    // 0x80029330: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
        goto L_80029388;
    // 0x80029330: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
    // 0x80029334: lw          $v0, 0x8($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X8);
L_80029338:
    // 0x80029338: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x8002933C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80029340: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029344: beq         $at, $zero, L_80029378
    if (ctx->r1 == 0) {
        // 0x80029348: subu        $t8, $v0, $v1
        ctx->r24 = SUB32(ctx->r2, ctx->r3);
            goto L_80029378;
    }
    // 0x80029348: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x8002934C: subu        $t9, $v1, $v0
    ctx->r25 = SUB32(ctx->r3, ctx->r2);
    // 0x80029350: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x80029354: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80029358: sw          $s0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r16;
    // 0x8002935C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80029360: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80029364: beq         $a0, $zero, L_80029370
    if (ctx->r4 == 0) {
        // 0x80029368: nop
    
            goto L_80029370;
    }
    // 0x80029368: nop

    // 0x8002936C: sw          $s1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r17;
L_80029370:
    // 0x80029370: b           L_80029388
    // 0x80029374: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
        goto L_80029388;
    // 0x80029374: sw          $s1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r17;
L_80029378:
    // 0x80029378: sw          $t8, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r24;
    // 0x8002937C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80029380: bnel        $s0, $zero, L_8002930C
    if (ctx->r16 != 0) {
        // 0x80029384: lw          $a0, 0x0($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X0);
            goto L_8002930C;
    }
    goto skip_3;
    // 0x80029384: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_80029388:
    // 0x80029388: jal         0x80030350
    // 0x8002938C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_3;
    // 0x8002938C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80029390: bne         $s2, $zero, L_800292AC
    if (ctx->r18 != 0) {
        // 0x80029394: or          $s1, $s2, $zero
        ctx->r17 = ctx->r18 | 0;
            goto L_800292AC;
    }
    // 0x80029394: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
L_80029398:
    // 0x80029398: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002939C:
    // 0x8002939C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800293A0: jr          $ra
    // 0x800293A4: nop

    return;
    // 0x800293A4: nop

;}
RECOMP_FUNC void mnTitleFuncUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134098: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013409C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801340A0: jal         0x8000A5E4
    // 0x801340A4: nop

    gcRunAll(rdram, ctx);
        goto after_0;
    // 0x801340A4: nop

    after_0:
    // 0x801340A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801340AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801340B0: jr          $ra
    // 0x801340B4: nop

    return;
    // 0x801340B4: nop

;}
RECOMP_FUNC void ftNessSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153AC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80153AC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80153AC8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80153ACC: jal         0x800DDE84
    // 0x80153AD0: addiu       $a1, $a1, 0x3B5C
    ctx->r5 = ADD32(ctx->r5, 0X3B5C);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80153AD0: addiu       $a1, $a1, 0x3B5C
    ctx->r5 = ADD32(ctx->r5, 0X3B5C);
    after_0:
    // 0x80153AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80153AD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80153ADC: jr          $ra
    // 0x80153AE0: nop

    return;
    // 0x80153AE0: nop

;}
RECOMP_FUNC void grPupupuFlowersFrontWindStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801060B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801060B4: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x801060B8: lbu         $t6, 0x28($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X28);
    // 0x801060BC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801060C0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x801060C4: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x801060C8: bne         $t8, $zero, L_801060D8
    if (ctx->r24 != 0) {
        // 0x801060CC: sb          $t7, 0x28($v0)
        MEM_B(0X28, ctx->r2) = ctx->r15;
            goto L_801060D8;
    }
    // 0x801060CC: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x801060D0: sb          $zero, 0x30($v0)
    MEM_B(0X30, ctx->r2) = 0;
    // 0x801060D4: sb          $t9, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r25;
L_801060D8:
    // 0x801060D8: jr          $ra
    // 0x801060DC: nop

    return;
    // 0x801060DC: nop

;}
RECOMP_FUNC void wpBossBulletProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DD04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016DD08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016DD0C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016DD10: jal         0x801005C8
    // 0x8016DD14: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016DD14: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016DD18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016DD1C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016DD20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016DD24: jr          $ra
    // 0x8016DD28: nop

    return;
    // 0x8016DD28: nop

;}
RECOMP_FUNC void itFushigibanaWeaponRazorMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801849EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801849F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801849F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801849F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801849FC: addiu       $a1, $a1, -0x4A9C
    ctx->r5 = ADD32(ctx->r5, -0X4A9C);
    // 0x80184A00: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80184A04: jal         0x801655C8
    // 0x80184A08: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80184A08: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_0:
    // 0x80184A0C: bne         $v0, $zero, L_80184A1C
    if (ctx->r2 != 0) {
        // 0x80184A10: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80184A1C;
    }
    // 0x80184A10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80184A14: b           L_80184A60
    // 0x80184A18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80184A60;
    // 0x80184A18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80184A1C:
    // 0x80184A1C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80184A20: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x80184A24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80184A28: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80184A2C: sw          $t6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r14;
    // 0x80184A30: swc1        $f4, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f4.u32l;
    // 0x80184A34: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80184A38: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x80184A3C: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
    // 0x80184A40: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80184A44: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80184A48: sw          $t9, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r25;
    // 0x80184A4C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80184A50: sw          $t8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r24;
    // 0x80184A54: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80184A58: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
    // 0x80184A5C: sw          $t0, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r8;
L_80184A60:
    // 0x80184A60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80184A64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80184A68: jr          $ra
    // 0x80184A6C: nop

    return;
    // 0x80184A6C: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157314: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80157318: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015731C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80157320: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80157324: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80157328: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8015732C: lw          $t7, 0x17C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X17C);
    // 0x80157330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80157334: beql        $t7, $zero, L_8015749C
    if (ctx->r15 == 0) {
        // 0x80157338: lw          $t5, 0x40($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X40);
            goto L_8015749C;
    }
    goto skip_0;
    // 0x80157338: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x8015733C: jal         0x80156EBC
    // 0x80157340: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    ftKirbyCopySamusSpecialNGetChargeShotPosition(rdram, ctx);
        goto after_0;
    // 0x80157340: sw          $zero, 0x17C($s0)
    MEM_W(0X17C, ctx->r16) = 0;
    after_0:
    // 0x80157344: lw          $v0, 0xB20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB20);
    // 0x80157348: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8015734C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80157350: beq         $v0, $zero, L_801573C0
    if (ctx->r2 == 0) {
        // 0x80157354: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_801573C0;
    }
    // 0x80157354: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80157358: lw          $t8, 0x84($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X84);
    // 0x8015735C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80157360: jal         0x800E81E4
    // 0x80157364: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    ftParamStopLoopSFX(rdram, ctx);
        goto after_1;
    // 0x80157364: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    after_1:
    // 0x80157368: lw          $t9, 0xB20($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XB20);
    // 0x8015736C: addiu       $t1, $sp, 0x30
    ctx->r9 = ADD32(ctx->r29, 0X30);
    // 0x80157370: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80157374: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x80157378: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8015737C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80157380: sw          $t3, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r11;
    // 0x80157384: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80157388: addiu       $a2, $s0, 0x78
    ctx->r6 = ADD32(ctx->r16, 0X78);
    // 0x8015738C: sw          $t2, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->r10;
    // 0x80157390: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80157394: sw          $t3, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->r11;
    // 0x80157398: sw          $t4, 0x2A0($v0)
    MEM_W(0X2A0, ctx->r2) = ctx->r12;
    // 0x8015739C: lw          $t5, 0xAE0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XAE0);
    // 0x801573A0: sw          $t5, 0x2A4($v0)
    MEM_W(0X2A4, ctx->r2) = ctx->r13;
    // 0x801573A4: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x801573A8: jal         0x800DF09C
    // 0x801573AC: lw          $a0, 0xB20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB20);
    mpCommonRunWeaponCollisionDefault(rdram, ctx);
        goto after_2;
    // 0x801573AC: lw          $a0, 0xB20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB20);
    after_2:
    // 0x801573B0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801573B4: sw          $zero, 0x2A8($t6)
    MEM_W(0X2A8, ctx->r14) = 0;
    // 0x801573B8: b           L_801573C8
    // 0x801573BC: sw          $zero, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = 0;
        goto L_801573C8;
    // 0x801573BC: sw          $zero, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = 0;
L_801573C0:
    // 0x801573C0: jal         0x80168DDC
    // 0x801573C4: lw          $a2, 0xAE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XAE0);
    wpSamusChargeShotMakeWeapon(rdram, ctx);
        goto after_3;
    // 0x801573C4: lw          $a2, 0xAE0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XAE0);
    after_3:
L_801573C8:
    // 0x801573C8: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x801573CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801573D0: bnel        $t7, $at, L_80157468
    if (ctx->r15 != ctx->r1) {
        // 0x801573D4: lw          $t3, 0xAE0($s0)
        ctx->r11 = MEM_W(ctx->r16, 0XAE0);
            goto L_80157468;
    }
    goto skip_1;
    // 0x801573D4: lw          $t3, 0xAE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XAE0);
    skip_1:
    // 0x801573D8: lw          $t8, 0xAE0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XAE0);
    // 0x801573DC: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x801573E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801573E4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x801573E8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x801573EC: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x801573F0: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x801573F4: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801573F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801573FC: lw          $v0, 0xAE4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XAE4);
    // 0x80157400: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80157404: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80157408: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8015740C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80157410: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80157414: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80157418: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8015741C: nop

    // 0x80157420: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80157424: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80157428: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8015742C: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80157430: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80157434: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80157438: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x8015743C: add.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80157440: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80157444: nop

    // 0x80157448: bc1fl       L_8015745C
    if (!c1cs) {
        // 0x8015744C: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_8015745C;
    }
    goto skip_2;
    // 0x8015744C: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x80157450: swc1        $f2, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f2.u32l;
    // 0x80157454: lw          $v0, 0xAE4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XAE4);
    // 0x80157458: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
L_8015745C:
    // 0x8015745C: b           L_80157490
    // 0x80157460: sw          $t2, 0xAE4($s0)
    MEM_W(0XAE4, ctx->r16) = ctx->r10;
        goto L_80157490;
    // 0x80157460: sw          $t2, 0xAE4($s0)
    MEM_W(0XAE4, ctx->r16) = ctx->r10;
    // 0x80157464: lw          $t3, 0xAE0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0XAE0);
L_80157468:
    // 0x80157468: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8015746C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80157470: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80157474: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x80157478: nop

    // 0x8015747C: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80157480: add.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80157484: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80157488: neg.s       $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = -ctx->f4.fl;
    // 0x8015748C: swc1        $f10, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f10.u32l;
L_80157490:
    // 0x80157490: sw          $zero, 0xAE0($s0)
    MEM_W(0XAE0, ctx->r16) = 0;
    // 0x80157494: sw          $zero, 0x9EC($s0)
    MEM_W(0X9EC, ctx->r16) = 0;
    // 0x80157498: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
L_8015749C:
    // 0x8015749C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801574A0: lwc1        $f8, 0x78($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X78);
    // 0x801574A4: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x801574A8: nop

    // 0x801574AC: bc1fl       L_801574C0
    if (!c1cs) {
        // 0x801574B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801574C0;
    }
    goto skip_3;
    // 0x801574B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x801574B4: jal         0x800DEE54
    // 0x801574B8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_4;
    // 0x801574B8: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_4:
    // 0x801574BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801574C0:
    // 0x801574C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801574C4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801574C8: jr          $ra
    // 0x801574CC: nop

    return;
    // 0x801574CC: nop

;}
RECOMP_FUNC void itFFlowerThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175CC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175CC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175CCC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175CD0: addiu       $a1, $a1, -0x636C
    ctx->r5 = ADD32(ctx->r5, -0X636C);
    // 0x80175CD4: jal         0x80172EC8
    // 0x80175CD8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80175CD8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x80175CDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175CE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175CE4: jr          $ra
    // 0x80175CE8: nop

    return;
    // 0x80175CE8: nop

;}
RECOMP_FUNC void efManagerCaptainFalconPunchMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101F84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101F88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80101F8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101F90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101F94: jal         0x800FDB1C
    // 0x80101F98: addiu       $a0, $a0, -0x1D14
    ctx->r4 = ADD32(ctx->r4, -0X1D14);
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x80101F98: addiu       $a0, $a0, -0x1D14
    ctx->r4 = ADD32(ctx->r4, -0X1D14);
    after_0:
    // 0x80101F9C: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80101FA0: bne         $v0, $zero, L_80101FB0
    if (ctx->r2 != 0) {
        // 0x80101FA4: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80101FB0;
    }
    // 0x80101FA4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80101FA8: b           L_80102008
    // 0x80101FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102008;
    // 0x80101FAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101FB0:
    // 0x80101FB0: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80101FB4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80101FB8: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80101FBC: lw          $a0, 0x84($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X84);
    // 0x80101FC0: lw          $a2, 0x74($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X74);
    // 0x80101FC4: lw          $a1, 0x8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X8);
    // 0x80101FC8: beq         $a1, $at, L_80101FD8
    if (ctx->r5 == ctx->r1) {
        // 0x80101FCC: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_80101FD8;
    }
    // 0x80101FCC: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80101FD0: bnel        $a1, $at, L_80101FE4
    if (ctx->r5 != ctx->r1) {
        // 0x80101FD4: lw          $v1, 0x960($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X960);
            goto L_80101FE4;
    }
    goto skip_0;
    // 0x80101FD4: lw          $v1, 0x960($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X960);
    skip_0:
L_80101FD8:
    // 0x80101FD8: b           L_80101FE4
    // 0x80101FDC: lw          $v1, 0x928($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X928);
        goto L_80101FE4;
    // 0x80101FDC: lw          $v1, 0x928($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X928);
    // 0x80101FE0: lw          $v1, 0x960($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X960);
L_80101FE4:
    // 0x80101FE4: sw          $v1, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->r3;
    // 0x80101FE8: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x80101FEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80101FF0: lwc1        $f8, 0x9F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X9F0);
    // 0x80101FF4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80101FF8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80101FFC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80102000: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80102004: swc1        $f10, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->f10.u32l;
L_80102008:
    // 0x80102008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010200C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102010: jr          $ra
    // 0x80102014: nop

    return;
    // 0x80102014: nop

;}
RECOMP_FUNC void ftMainUpdateDamageStatItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E39B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E39B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E39B8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800E39BC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800E39C0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800E39C4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800E39C8: jal         0x801727F4
    // 0x800E39CC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    itMainGetDamageOutput(rdram, ctx);
        goto after_0;
    // 0x800E39CC: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E39D0: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x800E39D4: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800E39D8: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x800E39DC: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x800E39E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E39E4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800E39E8: bgez        $t8, L_800E39F8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E39EC: nop
    
            goto L_800E39F8;
    }
    // 0x800E39EC: nop

    // 0x800E39F0: b           L_800E39F8
    // 0x800E39F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
        goto L_800E39F8;
    // 0x800E39F4: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_800E39F8:
    // 0x800E39F8: jal         0x8016F930
    // 0x800E39FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itProcessSetHitInteractStats(rdram, ctx);
        goto after_1;
    // 0x800E39FC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800E3A00: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    // 0x800E3A04: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E3A08: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800E3A0C: bne         $t9, $at, L_800E3AB8
    if (ctx->r25 != ctx->r1) {
        // 0x800E3A10: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_800E3AB8;
    }
    // 0x800E3A10: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3A14: lw          $a2, 0xC($s0)
    ctx->r6 = MEM_W(ctx->r16, 0XC);
    // 0x800E3A18: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800E3A1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E3A20: beq         $a2, $at, L_800E3A3C
    if (ctx->r6 == ctx->r1) {
        // 0x800E3A24: addiu       $a1, $zero, 0x258
        ctx->r5 = ADD32(0, 0X258);
            goto L_800E3A3C;
    }
    // 0x800E3A24: addiu       $a1, $zero, 0x258
    ctx->r5 = ADD32(0, 0X258);
    // 0x800E3A28: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x800E3A2C: beq         $a2, $at, L_800E3AA8
    if (ctx->r6 == ctx->r1) {
        // 0x800E3A30: lw          $a0, 0x4C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X4C);
            goto L_800E3AA8;
    }
    // 0x800E3A30: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3A34: b           L_800E3C9C
    // 0x800E3A38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800E3C9C;
    // 0x800E3A38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E3A3C:
    // 0x800E3A3C: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
    // 0x800E3A40: sw          $v0, 0x264($s0)
    MEM_W(0X264, ctx->r16) = ctx->r2;
    // 0x800E3A44: jal         0x800EA8B0
    // 0x800E3A48: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    ftParamSetStarHitStatusInvincible(rdram, ctx);
        goto after_2;
    // 0x800E3A48: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    after_2:
    // 0x800E3A4C: jal         0x800E7AFC
    // 0x800E3A50: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    ftParamTryPlayItemMusic(rdram, ctx);
        goto after_3;
    // 0x800E3A50: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_3:
    // 0x800E3A54: jal         0x800269C0
    // 0x800E3A58: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x800E3A58: addiu       $a0, $zero, 0x36
    ctx->r4 = ADD32(0, 0X36);
    after_4:
    // 0x800E3A5C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x800E3A60: lw          $t1, 0x50E8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X50E8);
    // 0x800E3A64: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E3A68: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3A6C: lbu         $t2, 0x0($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X0);
    // 0x800E3A70: bne         $t2, $at, L_800E3C98
    if (ctx->r10 != ctx->r1) {
        // 0x800E3A74: lui         $t3, 0x800A
        ctx->r11 = S32(0X800A << 16);
            goto L_800E3C98;
    }
    // 0x800E3A74: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800E3A78: lbu         $t3, 0x4AE3($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4AE3);
    // 0x800E3A7C: lbu         $t5, 0xD($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0XD);
    // 0x800E3A80: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x800E3A84: addiu       $v1, $v1, 0x36AA
    ctx->r3 = ADD32(ctx->r3, 0X36AA);
    // 0x800E3A88: bnel        $t3, $t5, L_800E3C9C
    if (ctx->r11 != ctx->r13) {
        // 0x800E3A8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800E3C9C;
    }
    goto skip_0;
    // 0x800E3A8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800E3A90: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800E3A94: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x800E3A98: beq         $at, $zero, L_800E3C98
    if (ctx->r1 == 0) {
        // 0x800E3A9C: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_800E3C98;
    }
    // 0x800E3A9C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800E3AA0: b           L_800E3C98
    // 0x800E3AA4: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
        goto L_800E3C98;
    // 0x800E3AA4: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_800E3AA8:
    // 0x800E3AA8: jal         0x800EA3D4
    // 0x800E3AAC: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    ftParamSetHealDamage(rdram, ctx);
        goto after_5;
    // 0x800E3AAC: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    after_5:
    // 0x800E3AB0: b           L_800E3C9C
    // 0x800E3AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800E3C9C;
    // 0x800E3AB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E3AB8:
    // 0x800E3AB8: jal         0x800EA40C
    // 0x800E3ABC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    ftParamGetCapturedDamage(rdram, ctx);
        goto after_6;
    // 0x800E3ABC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    after_6:
    // 0x800E3AC0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800E3AC4: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800E3AC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E3ACC: lw          $t7, 0x4C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X4C);
    // 0x800E3AD0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800E3AD4: bgezl       $t9, L_800E3AF8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800E3AD8: lw          $t2, 0x264($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X264);
            goto L_800E3AF8;
    }
    goto skip_1;
    // 0x800E3AD8: lw          $t2, 0x264($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X264);
    skip_1:
    // 0x800E3ADC: lw          $t1, 0x26C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X26C);
    // 0x800E3AE0: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E3AE4: beql        $at, $zero, L_800E3B0C
    if (ctx->r1 == 0) {
        // 0x800E3AE8: lwc1        $f0, 0x2C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_800E3B0C;
    }
    goto skip_2;
    // 0x800E3AE8: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    skip_2:
    // 0x800E3AEC: b           L_800E3B08
    // 0x800E3AF0: sw          $v0, 0x26C($s0)
    MEM_W(0X26C, ctx->r16) = ctx->r2;
        goto L_800E3B08;
    // 0x800E3AF0: sw          $v0, 0x26C($s0)
    MEM_W(0X26C, ctx->r16) = ctx->r2;
    // 0x800E3AF4: lw          $t2, 0x264($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X264);
L_800E3AF8:
    // 0x800E3AF8: slt         $at, $t2, $v0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E3AFC: beql        $at, $zero, L_800E3B0C
    if (ctx->r1 == 0) {
        // 0x800E3B00: lwc1        $f0, 0x2C($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
            goto L_800E3B0C;
    }
    goto skip_3;
    // 0x800E3B00: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
    skip_3:
    // 0x800E3B04: sw          $v0, 0x264($s0)
    MEM_W(0X264, ctx->r16) = ctx->r2;
L_800E3B08:
    // 0x800E3B08: lwc1        $f0, 0x2C($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X2C);
L_800E3B0C:
    // 0x800E3B0C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800E3B10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800E3B14: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800E3B18: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x800E3B1C: lw          $t5, 0x54($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X54);
    // 0x800E3B20: bc1fl       L_800E3B34
    if (!c1cs) {
        // 0x800E3B24: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800E3B34;
    }
    goto skip_4;
    // 0x800E3B24: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_4:
    // 0x800E3B28: b           L_800E3B34
    // 0x800E3B2C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_800E3B34;
    // 0x800E3B2C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800E3B30: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800E3B34:
    // 0x800E3B34: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800E3B38: nop

    // 0x800E3B3C: bc1fl       L_800E3B7C
    if (!c1cs) {
        // 0x800E3B40: mtc1        $zero, $f16
        ctx->f16.u32l = 0;
            goto L_800E3B7C;
    }
    goto skip_5;
    // 0x800E3B40: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    skip_5:
    // 0x800E3B44: lw          $t3, 0x74($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X74);
    // 0x800E3B48: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x800E3B4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800E3B50: lwc1        $f8, 0x1C($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800E3B54: lwc1        $f10, 0x1C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800E3B58: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800E3B5C: nop

    // 0x800E3B60: bc1f        L_800E3B70
    if (!c1cs) {
        // 0x800E3B64: nop
    
            goto L_800E3B70;
    }
    // 0x800E3B64: nop

    // 0x800E3B68: b           L_800E3B70
    // 0x800E3B6C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
        goto L_800E3B70;
    // 0x800E3B6C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800E3B70:
    // 0x800E3B70: b           L_800E3B9C
    // 0x800E3B74: sw          $a2, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r6;
        goto L_800E3B9C;
    // 0x800E3B74: sw          $a2, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r6;
    // 0x800E3B78: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
L_800E3B7C:
    // 0x800E3B7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E3B80: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800E3B84: nop

    // 0x800E3B88: bc1f        L_800E3B98
    if (!c1cs) {
        // 0x800E3B8C: nop
    
            goto L_800E3B98;
    }
    // 0x800E3B8C: nop

    // 0x800E3B90: b           L_800E3B98
    // 0x800E3B94: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800E3B98;
    // 0x800E3B94: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800E3B98:
    // 0x800E3B98: sw          $v0, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r2;
L_800E3B9C:
    // 0x800E3B9C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3BA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E3BA4: lw          $t7, 0x5AC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5AC);
    // 0x800E3BA8: bne         $v0, $t7, L_800E3C90
    if (ctx->r2 != ctx->r15) {
        // 0x800E3BAC: nop
    
            goto L_800E3C90;
    }
    // 0x800E3BAC: nop

    // 0x800E3BB0: lw          $t8, 0x5B4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X5B4);
    // 0x800E3BB4: bne         $v0, $t8, L_800E3C90
    if (ctx->r2 != ctx->r24) {
        // 0x800E3BB8: nop
    
            goto L_800E3C90;
    }
    // 0x800E3BB8: nop

    // 0x800E3BBC: lw          $t9, 0x5B8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X5B8);
    // 0x800E3BC0: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x800E3BC4: bne         $v0, $t9, L_800E3C90
    if (ctx->r2 != ctx->r25) {
        // 0x800E3BC8: nop
    
            goto L_800E3C90;
    }
    // 0x800E3BC8: nop

    // 0x800E3BCC: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800E3BD0: bne         $v0, $t2, L_800E3C90
    if (ctx->r2 != ctx->r10) {
        // 0x800E3BD4: nop
    
            goto L_800E3C90;
    }
    // 0x800E3BD4: nop

    // 0x800E3BD8: jal         0x800E2CC0
    // 0x800E3BDC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    ftMainCheckGetUpdateDamage(rdram, ctx);
        goto after_7;
    // 0x800E3BDC: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    after_7:
    // 0x800E3BE0: beq         $v0, $zero, L_800E3C90
    if (ctx->r2 == 0) {
        // 0x800E3BE4: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_800E3C90;
    }
    // 0x800E3BE4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800E3BE8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E3BEC: addiu       $a0, $a0, 0x11C0
    ctx->r4 = ADD32(ctx->r4, 0X11C0);
    // 0x800E3BF0: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800E3BF4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800E3BF8: addiu       $t3, $t3, 0x11C8
    ctx->r11 = ADD32(ctx->r11, 0X11C8);
    // 0x800E3BFC: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x800E3C00: beq         $at, $zero, L_800E3C54
    if (ctx->r1 == 0) {
        // 0x800E3C04: sll         $t4, $v1, 3
        ctx->r12 = S32(ctx->r3 << 3);
            goto L_800E3C54;
    }
    // 0x800E3C04: sll         $t4, $v1, 3
    ctx->r12 = S32(ctx->r3 << 3);
    // 0x800E3C08: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x800E3C0C: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800E3C10: addu        $v0, $t4, $t3
    ctx->r2 = ADD32(ctx->r12, ctx->r11);
    // 0x800E3C14: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800E3C18: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800E3C1C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x800E3C20: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800E3C24: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x800E3C28: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800E3C2C: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x800E3C30: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800E3C34: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x800E3C38: lbu         $t9, 0x15($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X15);
    // 0x800E3C3C: sb          $t9, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r25;
    // 0x800E3C40: lw          $t1, 0x18($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X18);
    // 0x800E3C44: sw          $t1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r9;
    // 0x800E3C48: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x800E3C4C: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x800E3C50: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
L_800E3C54:
    // 0x800E3C54: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3C58: lbu         $a0, 0x15($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X15);
    // 0x800E3C5C: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800E3C60: jal         0x800EA98C
    // 0x800E3C64: lbu         $a1, 0xD($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0XD);
    ftParamUpdatePlayerBattleStats(rdram, ctx);
        goto after_8;
    // 0x800E3C64: lbu         $a1, 0xD($t3)
    ctx->r5 = MEM_BU(ctx->r11, 0XD);
    after_8:
    // 0x800E3C68: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800E3C6C: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x800E3C70: lbu         $a0, 0x15($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X15);
    // 0x800E3C74: lw          $a2, 0x4C($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X4C);
    // 0x800E3C78: lhu         $a3, 0x4E($t0)
    ctx->r7 = MEM_HU(ctx->r8, 0X4E);
    // 0x800E3C7C: lbu         $a1, 0xD($t5)
    ctx->r5 = MEM_BU(ctx->r13, 0XD);
    // 0x800E3C80: sll         $a2, $a2, 7
    ctx->r6 = S32(ctx->r6 << 7);
    // 0x800E3C84: jal         0x800EA614
    // 0x800E3C88: srl         $a2, $a2, 26
    ctx->r6 = S32(U32(ctx->r6) >> 26);
    ftParamUpdateStaleQueue(rdram, ctx);
        goto after_9;
    // 0x800E3C88: srl         $a2, $a2, 26
    ctx->r6 = S32(U32(ctx->r6) >> 26);
    after_9:
    // 0x800E3C8C: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_800E3C90:
    // 0x800E3C90: jal         0x800269C0
    // 0x800E3C94: lhu         $a0, 0x4A($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X4A);
    func_800269C0_275C0(rdram, ctx);
        goto after_10;
    // 0x800E3C94: lhu         $a0, 0x4A($t0)
    ctx->r4 = MEM_HU(ctx->r8, 0X4A);
    after_10:
L_800E3C98:
    // 0x800E3C98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E3C9C:
    // 0x800E3C9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800E3CA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800E3CA4: jr          $ra
    // 0x800E3CA8: nop

    return;
    // 0x800E3CA8: nop

;}
RECOMP_FUNC void sc1PBonusStageUpdatePlatformCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D8DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D8E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D8E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018D8E8: lw          $a0, 0x10($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X10);
    // 0x8018D8EC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8018D8F0: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x8018D8F4: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x8018D8F8: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8018D8FC: jal         0x8000948C
    // 0x8018D900: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    gcEjectDObj(rdram, ctx);
        goto after_0;
    // 0x8018D900: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    after_0:
    // 0x8018D904: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8018D908: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018D90C: addiu       $t1, $t1, -0x101C
    ctx->r9 = ADD32(ctx->r9, -0X101C);
    // 0x8018D910: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8018D914: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x8018D918: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8018D91C: lw          $t3, 0x13F4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X13F4);
    // 0x8018D920: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8018D924: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8018D928: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8018D92C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018D930: addiu       $a3, $zero, 0x44
    ctx->r7 = ADD32(0, 0X44);
    // 0x8018D934: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018D938: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018D93C: jal         0x800C8B28
    // 0x8018D940: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonSetupTreeDObjs(rdram, ctx);
        goto after_1;
    // 0x8018D940: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_1:
    // 0x8018D944: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x8018D948: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8018D94C: lw          $t6, 0x13F4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13F4);
    // 0x8018D950: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x8018D954: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8018D958: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018D95C: lw          $a0, 0x10($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X10);
    // 0x8018D960: jal         0x800C8758
    // 0x8018D964: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonAddDObjAnimJointAll(rdram, ctx);
        goto after_2;
    // 0x8018D964: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x8018D968: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8018D96C: jal         0x800C92C8
    // 0x8018D970: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    lbCommonPlayTreeDObjsAnim(rdram, ctx);
        goto after_3;
    // 0x8018D970: lw          $a0, 0x10($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X10);
    after_3:
    // 0x8018D974: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8018D978: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8018D97C: lbu         $t8, 0x10($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X10);
    // 0x8018D980: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8018D984: jal         0x8018D890
    // 0x8018D988: sb          $t9, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r25;
    sc1PBonusStageUpdatePlatformInterface(rdram, ctx);
        goto after_4;
    // 0x8018D988: sb          $t9, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r25;
    after_4:
    // 0x8018D98C: jal         0x800269C0
    // 0x8018D990: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x8018D990: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    after_5:
    // 0x8018D994: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8018D998: lbu         $t0, 0x1400($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X1400);
    // 0x8018D99C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8018D9A0: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x8018D9A4: bnel        $t0, $zero, L_8018DA20
    if (ctx->r8 != 0) {
        // 0x8018D9A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018DA20;
    }
    goto skip_0;
    // 0x8018D9A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8018D9AC: lbu         $t1, 0x1($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1);
    // 0x8018D9B0: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x8018D9B4: beq         $t1, $at, L_8018DA0C
    if (ctx->r9 == ctx->r1) {
        // 0x8018D9B8: nop
    
            goto L_8018DA0C;
    }
    // 0x8018D9B8: nop

    // 0x8018D9BC: lbu         $t2, 0x39($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X39);
    // 0x8018D9C0: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8018D9C4: addiu       $t4, $t4, 0x44E0
    ctx->r12 = ADD32(ctx->r12, 0X44E0);
    // 0x8018D9C8: sll         $t3, $t2, 5
    ctx->r11 = S32(ctx->r10 << 5);
    // 0x8018D9CC: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x8018D9D0: lbu         $t5, 0x478($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X478);
    // 0x8018D9D4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018D9D8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D9DC: bne         $t5, $at, L_8018DA0C
    if (ctx->r13 != ctx->r1) {
        // 0x8018D9E0: nop
    
            goto L_8018DA0C;
    }
    // 0x8018D9E0: nop

    // 0x8018D9E4: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018D9E8: lw          $t8, 0x474($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X474);
    // 0x8018D9EC: lw          $t7, 0x18($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X18);
    // 0x8018D9F0: sltu        $at, $t7, $t8
    ctx->r1 = ctx->r15 < ctx->r24 ? 1 : 0;
    // 0x8018D9F4: beq         $at, $zero, L_8018DA0C
    if (ctx->r1 == 0) {
        // 0x8018D9F8: nop
    
            goto L_8018DA0C;
    }
    // 0x8018D9F8: nop

    // 0x8018D9FC: jal         0x80114D58
    // 0x8018DA00: addiu       $a0, $zero, 0x1D0
    ctx->r4 = ADD32(0, 0X1D0);
    ifCommonAnnounceCompleteInitInterface(rdram, ctx);
        goto after_6;
    // 0x8018DA00: addiu       $a0, $zero, 0x1D0
    ctx->r4 = ADD32(0, 0X1D0);
    after_6:
    // 0x8018DA04: b           L_8018DA14
    // 0x8018DA08: nop

        goto L_8018DA14;
    // 0x8018DA08: nop

L_8018DA0C:
    // 0x8018DA0C: jal         0x80114D58
    // 0x8018DA10: addiu       $a0, $zero, 0x1CB
    ctx->r4 = ADD32(0, 0X1CB);
    ifCommonAnnounceCompleteInitInterface(rdram, ctx);
        goto after_7;
    // 0x8018DA10: addiu       $a0, $zero, 0x1CB
    ctx->r4 = ADD32(0, 0X1CB);
    after_7:
L_8018DA14:
    // 0x8018DA14: jal         0x80113804
    // 0x8018DA18: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    ifCommonBattleEndAddSoundQueueID(rdram, ctx);
        goto after_8;
    // 0x8018DA18: addiu       $a0, $zero, 0x115
    ctx->r4 = ADD32(0, 0X115);
    after_8:
    // 0x8018DA1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018DA20:
    // 0x8018DA20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018DA24: jr          $ra
    // 0x8018DA28: nop

    return;
    // 0x8018DA28: nop

;}
RECOMP_FUNC void ftCommonAttack12ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014E824: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014E828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014E82C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014E830: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8014E834: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8014E838: beq         $v1, $at, L_8014E874
    if (ctx->r3 == ctx->r1) {
        // 0x8014E83C: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_8014E874;
    }
    // 0x8014E83C: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8014E840: beql        $v1, $at, L_8014E878
    if (ctx->r3 == ctx->r1) {
        // 0x8014E844: lw          $t0, 0x180($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X180);
            goto L_8014E878;
    }
    goto skip_0;
    // 0x8014E844: lw          $t0, 0x180($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X180);
    skip_0:
    // 0x8014E848: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8014E84C: beql        $t6, $zero, L_8014E878
    if (ctx->r14 == 0) {
        // 0x8014E850: lw          $t0, 0x180($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X180);
            goto L_8014E878;
    }
    goto skip_1;
    // 0x8014E850: lw          $t0, 0x180($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X180);
    skip_1:
    // 0x8014E854: lw          $t7, 0x18C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18C);
    // 0x8014E858: sll         $t9, $t7, 11
    ctx->r25 = S32(ctx->r15 << 11);
    // 0x8014E85C: bgezl       $t9, L_8014E878
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8014E860: lw          $t0, 0x180($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X180);
            goto L_8014E878;
    }
    goto skip_2;
    // 0x8014E860: lw          $t0, 0x180($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X180);
    skip_2:
    // 0x8014E864: jal         0x8014F0F4
    // 0x8014E868: nop

    ftCommonAttack100StartSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014E868: nop

    after_0:
    // 0x8014E86C: b           L_8014E8A8
    // 0x8014E870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014E8A8;
    // 0x8014E870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E874:
    // 0x8014E874: lw          $t0, 0x180($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X180);
L_8014E878:
    // 0x8014E878: beq         $t0, $zero, L_8014E89C
    if (ctx->r8 == 0) {
        // 0x8014E87C: nop
    
            goto L_8014E89C;
    }
    // 0x8014E87C: nop

    // 0x8014E880: lw          $t1, 0xB18($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XB18);
    // 0x8014E884: beq         $t1, $zero, L_8014E89C
    if (ctx->r9 == 0) {
        // 0x8014E888: nop
    
            goto L_8014E89C;
    }
    // 0x8014E888: nop

    // 0x8014E88C: jal         0x8014EBB4
    // 0x8014E890: nop

    ftCommonAttack13SetStatus(rdram, ctx);
        goto after_1;
    // 0x8014E890: nop

    after_1:
    // 0x8014E894: b           L_8014E8A8
    // 0x8014E898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014E8A8;
    // 0x8014E898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E89C:
    // 0x8014E89C: jal         0x800D94C4
    // 0x8014E8A0: nop

    ftAnimEndSetWait(rdram, ctx);
        goto after_2;
    // 0x8014E8A0: nop

    after_2:
    // 0x8014E8A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014E8A8:
    // 0x8014E8A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014E8AC: jr          $ra
    // 0x8014E8B0: nop

    return;
    // 0x8014E8B0: nop

;}
RECOMP_FUNC void func_ovl6_8018D0C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C8: jr          $ra
    // 0x8018D0CC: nop

    return;
    // 0x8018D0CC: nop

;}
RECOMP_FUNC void func_ovl8_8037BD94(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BD94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037BD98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8037BD9C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037BDA0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8037BDA4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8037BDA8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8037BDAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8037BDB0:
    // 0x8037BDB0: jal         0x8037C4A4
    // 0x8037BDB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    func_ovl8_8037C4A4(rdram, ctx);
        goto after_0;
    // 0x8037BDB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8037BDB8: jal         0x8000B1E8
    // 0x8037BDBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x8037BDBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8037BDC0: b           L_8037BDB0
    // 0x8037BDC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8037BDB0;
    // 0x8037BDC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037BDC8: nop

    // 0x8037BDCC: nop

    // 0x8037BDD0: nop

    // 0x8037BDD4: nop

    // 0x8037BDD8: nop

    // 0x8037BDDC: nop

    // 0x8037BDE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037BDE4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8037BDE8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8037BDEC: jr          $ra
    // 0x8037BDF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8037BDF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnTitleAdvanceLayout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323DC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801323E0: addiu       $v1, $v1, 0x4450
    ctx->r3 = ADD32(ctx->r3, 0X4450);
    // 0x801323E4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801323E8: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x801323EC: addiu       $a0, $a0, 0x4AD0
    ctx->r4 = ADD32(ctx->r4, 0X4AD0);
    // 0x801323F0: bne         $v0, $zero, L_8013240C
    if (ctx->r2 != 0) {
        // 0x801323F4: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_8013240C;
    }
    // 0x801323F4: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x801323F8: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x801323FC: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80132400: bne         $t6, $at, L_8013240C
    if (ctx->r14 != ctx->r1) {
        // 0x80132404: nop
    
            goto L_8013240C;
    }
    // 0x80132404: nop

    // 0x80132408: sb          $zero, 0x3F($a0)
    MEM_B(0X3F, ctx->r4) = 0;
L_8013240C:
    // 0x8013240C: jr          $ra
    // 0x80132410: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    return;
    // 0x80132410: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
;}
RECOMP_FUNC void mnVSRecordSetSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E40: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80131E44: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131E48: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80131E4C: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131E50: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80131E54: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x80131E58: sb          $t0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r8;
    // 0x80131E5C: lw          $t1, 0x4($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X4);
    // 0x80131E60: sb          $t1, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r9;
    // 0x80131E64: lw          $t2, 0x8($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X8);
    // 0x80131E68: sb          $t2, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r10;
    // 0x80131E6C: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x80131E70: sb          $t3, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r11;
    // 0x80131E74: lw          $t4, 0x10($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X10);
    // 0x80131E78: sb          $t4, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r12;
    // 0x80131E7C: lw          $t5, 0x14($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X14);
    // 0x80131E80: jr          $ra
    // 0x80131E84: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
    return;
    // 0x80131E84: sb          $t5, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r13;
;}
RECOMP_FUNC void mnVSResultsGetColumnX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801352FC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80135300: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80135304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135308: addiu       $t7, $t7, -0x6988
    ctx->r15 = ADD32(ctx->r15, -0X6988);
    // 0x8013530C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80135310: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80135314: addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
    // 0x80135318: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x8013531C: addiu       $t1, $t1, -0x6980
    ctx->r9 = ADD32(ctx->r9, -0X6980);
    // 0x80135320: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80135324: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80135328: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8013532C: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x80135330: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80135334: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80135338: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8013533C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80135340: addiu       $t5, $t5, -0x6974
    ctx->r13 = ADD32(ctx->r13, -0X6974);
    // 0x80135344: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80135348: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8013534C: lw          $t6, 0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X4);
    // 0x80135350: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x80135354: addiu       $t4, $sp, 0x24
    ctx->r12 = ADD32(ctx->r29, 0X24);
    // 0x80135358: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x8013535C: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80135360: lw          $t7, 0x8($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X8);
    // 0x80135364: lw          $t6, 0xC($t5)
    ctx->r14 = MEM_W(ctx->r13, 0XC);
    // 0x80135368: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x8013536C: sw          $t6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r14;
    // 0x80135370: jal         0x8013205C
    // 0x80135374: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    mnVSResultsGetPresentCount(rdram, ctx);
        goto after_0;
    // 0x80135374: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x80135378: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013537C: beq         $v0, $at, L_801353A0
    if (ctx->r2 == ctx->r1) {
        // 0x80135380: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_801353A0;
    }
    // 0x80135380: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80135384: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80135388: beq         $v0, $at, L_801353B8
    if (ctx->r2 == ctx->r1) {
        // 0x8013538C: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_801353B8;
    }
    // 0x8013538C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80135390: beq         $v0, $at, L_801353D0
    if (ctx->r2 == ctx->r1) {
        // 0x80135394: nop
    
            goto L_801353D0;
    }
    // 0x80135394: nop

    // 0x80135398: b           L_801353D0
    // 0x8013539C: nop

        goto L_801353D0;
    // 0x8013539C: nop

L_801353A0:
    // 0x801353A0: jal         0x801320B8
    // 0x801353A4: nop

    mnVSResultsGetPresentLowerCount(rdram, ctx);
        goto after_1;
    // 0x801353A4: nop

    after_1:
    // 0x801353A8: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x801353AC: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x801353B0: b           L_801353E4
    // 0x801353B4: lwc1        $f0, 0x40($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X40);
        goto L_801353E4;
    // 0x801353B4: lwc1        $f0, 0x40($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X40);
L_801353B8:
    // 0x801353B8: jal         0x801320B8
    // 0x801353BC: nop

    mnVSResultsGetPresentLowerCount(rdram, ctx);
        goto after_2;
    // 0x801353BC: nop

    after_2:
    // 0x801353C0: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x801353C4: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x801353C8: b           L_801353E4
    // 0x801353CC: lwc1        $f0, 0x34($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X34);
        goto L_801353E4;
    // 0x801353CC: lwc1        $f0, 0x34($t1)
    ctx->f0.u32l = MEM_W(ctx->r9, 0X34);
L_801353D0:
    // 0x801353D0: jal         0x801320B8
    // 0x801353D4: nop

    mnVSResultsGetPresentLowerCount(rdram, ctx);
        goto after_3;
    // 0x801353D4: nop

    after_3:
    // 0x801353D8: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x801353DC: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x801353E0: lwc1        $f0, 0x24($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X24);
L_801353E4:
    // 0x801353E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801353E8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801353EC: jr          $ra
    // 0x801353F0: nop

    return;
    // 0x801353F0: nop

;}
RECOMP_FUNC void mnPlayersVSFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B20: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B28: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B2C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x80131B30: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80131B34: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B38: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B3C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131B40: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80131B44: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B48: jal         0x8039051C
    // 0x80131B4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    scSubsysFighterGetLightAngleX(rdram, ctx);
        goto after_0;
    // 0x80131B4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131B50: jal         0x80390528
    // 0x80131B54: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    scSubsysFighterGetLightAngleY(rdram, ctx);
        goto after_1;
    // 0x80131B54: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80131B58: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131B5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131B60: jal         0x800FCB70
    // 0x80131B64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_2;
    // 0x80131B64: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80131B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131B6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131B70: jr          $ra
    // 0x80131B74: nop

    return;
    // 0x80131B74: nop

;}
RECOMP_FUNC void wpNessPKThunderHeadProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B2A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016B2A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B2A8: jal         0x8016AD30
    // 0x8016B2AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKThunderHeadSetDestroyTrails(rdram, ctx);
        goto after_0;
    // 0x8016B2AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8016B2B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B2B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016B2B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016B2BC: jr          $ra
    // 0x8016B2C0: nop

    return;
    // 0x8016B2C0: nop

;}
RECOMP_FUNC void ftCommonTurnSetStatusCenter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E988: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E98C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E990: jal         0x8013E908
    // 0x8013E994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftCommonTurnSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013E994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8013E998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013E99C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013E9A0: jr          $ra
    // 0x8013E9A4: nop

    return;
    // 0x8013E9A4: nop

;}
RECOMP_FUNC void scVSBattleGetStartPlayerLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0E0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8018D0E4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8018D0E8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8018D0EC: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8018D0F0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018D0F4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8018D0F8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D0FC: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8018D100: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8018D104: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8018D108: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8018D10C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8018D110: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8018D114: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8018D118: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018D11C: jal         0x800FAF64
    // 0x8018D120: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    mpCollisionGetPlayerMapObjPosition(rdram, ctx);
        goto after_0;
    // 0x8018D120: addiu       $a1, $sp, 0x58
    ctx->r5 = ADD32(ctx->r29, 0X58);
    after_0:
    // 0x8018D124: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018D128: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018D12C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018D130: addiu       $s6, $sp, 0x64
    ctx->r22 = ADD32(ctx->r29, 0X64);
    // 0x8018D134: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
    // 0x8018D138: addiu       $s3, $zero, 0x4
    ctx->r19 = ADD32(0, 0X4);
    // 0x8018D13C: addiu       $s1, $zero, 0x74
    ctx->r17 = ADD32(0, 0X74);
L_8018D140:
    // 0x8018D140: beql        $s0, $s2, L_8018D1D4
    if (ctx->r16 == ctx->r18) {
        // 0x8018D144: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018D1D4;
    }
    goto skip_0;
    // 0x8018D144: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x8018D148: multu       $s0, $s1
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D14C: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018D150: mflo        $t6
    ctx->r14 = lo;
    // 0x8018D154: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x8018D158: lbu         $t7, 0x22($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X22);
    // 0x8018D15C: beql        $s4, $t7, L_8018D1D4
    if (ctx->r20 == ctx->r15) {
        // 0x8018D160: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018D1D4;
    }
    goto skip_1;
    // 0x8018D160: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x8018D164: multu       $s2, $s1
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D168: lbu         $t8, 0x25($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X25);
    // 0x8018D16C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D170: mflo        $t9
    ctx->r25 = lo;
    // 0x8018D174: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x8018D178: lbu         $t1, 0x25($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X25);
    // 0x8018D17C: beql        $t8, $t1, L_8018D1D4
    if (ctx->r24 == ctx->r9) {
        // 0x8018D180: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018D1D4;
    }
    goto skip_2;
    // 0x8018D180: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x8018D184: jal         0x800FAF64
    // 0x8018D188: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mpCollisionGetPlayerMapObjPosition(rdram, ctx);
        goto after_1;
    // 0x8018D188: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_1:
    // 0x8018D18C: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8018D190: lwc1        $f14, 0x58($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8018D194: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x8018D198: nop

    // 0x8018D19C: bc1fl       L_8018D1B4
    if (!c1cs) {
        // 0x8018D1A0: sub.s       $f0, $f12, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
            goto L_8018D1B4;
    }
    goto skip_3;
    // 0x8018D1A0: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    skip_3:
    // 0x8018D1A4: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x8018D1A8: b           L_8018D1B8
    // 0x8018D1AC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8018D1B8;
    // 0x8018D1AC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8018D1B0: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
L_8018D1B4:
    // 0x8018D1B4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8018D1B8:
    // 0x8018D1B8: c.lt.s      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.fl < ctx->f20.fl;
    // 0x8018D1BC: nop

    // 0x8018D1C0: bc1fl       L_8018D1D4
    if (!c1cs) {
        // 0x8018D1C4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8018D1D4;
    }
    goto skip_4;
    // 0x8018D1C4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x8018D1C8: mov.s       $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    ctx->f20.fl = ctx->f2.fl;
    // 0x8018D1CC: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x8018D1D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8018D1D4:
    // 0x8018D1D4: bne         $s0, $s3, L_8018D140
    if (ctx->r16 != ctx->r19) {
        // 0x8018D1D8: nop
    
            goto L_8018D140;
    }
    // 0x8018D1D8: nop

    // 0x8018D1DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018D1E0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8018D1E4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018D1E8: c.le.s      $f4, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f4.fl <= ctx->f22.fl;
    // 0x8018D1EC: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8018D1F0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D1F4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8018D1F8: bc1f        L_8018D208
    if (!c1cs) {
        // 0x8018D1FC: lw          $s3, 0x34($sp)
        ctx->r19 = MEM_W(ctx->r29, 0X34);
            goto L_8018D208;
    }
    // 0x8018D1FC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8018D200: b           L_8018D20C
    // 0x8018D204: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8018D20C;
    // 0x8018D204: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8018D208:
    // 0x8018D208: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8018D20C:
    // 0x8018D20C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018D210: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8018D214: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D218: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8018D21C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x8018D220: jr          $ra
    // 0x8018D224: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8018D224: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void itHeartMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174850: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80174854: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80174858: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8017485C: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80174860: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80174864: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80174868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017486C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174870: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80174874: addiu       $a1, $a1, -0x6830
    ctx->r5 = ADD32(ctx->r5, -0X6830);
    // 0x80174878: jal         0x8016E174
    // 0x8017487C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017487C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80174880: beq         $v0, $zero, L_80174918
    if (ctx->r2 == 0) {
        // 0x80174884: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80174918;
    }
    // 0x80174884: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80174888: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x8017488C: lw          $a3, 0x84($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X84);
    // 0x80174890: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    // 0x80174894: addiu       $t0, $a0, 0x1C
    ctx->r8 = ADD32(ctx->r4, 0X1C);
    // 0x80174898: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8017489C: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x801748A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801748A4: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x801748A8: lw          $t8, 0x4($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X4);
    // 0x801748AC: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x801748B0: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x801748B4: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x801748B8: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x801748BC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x801748C0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801748C4: jal         0x80008CC0
    // 0x801748C8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x801748C8: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    after_1:
    // 0x801748CC: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x801748D0: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x801748D4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801748D8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801748DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801748E0: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801748E4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801748E8: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801748EC: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801748F0: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x801748F4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x801748F8: swc1        $f4, 0x38($t4)
    MEM_W(0X38, ctx->r12) = ctx->f4.u32l;
    // 0x801748FC: lbu         $t6, 0x2D3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2D3);
    // 0x80174900: ori         $t7, $t6, 0x4
    ctx->r15 = ctx->r14 | 0X4;
    // 0x80174904: jal         0x80111EC0
    // 0x80174908: sb          $t7, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r15;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_2;
    // 0x80174908: sb          $t7, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r15;
    after_2:
    // 0x8017490C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80174910: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80174914: sw          $v0, 0x348($a3)
    MEM_W(0X348, ctx->r7) = ctx->r2;
L_80174918:
    // 0x80174918: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017491C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80174920: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80174924: jr          $ra
    // 0x80174928: nop

    return;
    // 0x80174928: nop

;}
RECOMP_FUNC void ftComputerCheckEvadeDistance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BC8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80132BCC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80132BD0: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80132BD4: lw          $s1, 0x66FC($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X66FC);
    // 0x80132BD8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80132BDC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80132BE0: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80132BE4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80132BE8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80132BEC: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80132BF0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80132BF4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80132BF8: beq         $s1, $zero, L_80132CE8
    if (ctx->r17 == 0) {
        // 0x80132BFC: sdc1        $f20, 0x18($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
            goto L_80132CE8;
    }
    // 0x80132BFC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80132C00: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80132C04: lwc1        $f24, -0x4470($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X4470);
    // 0x80132C08: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80132C0C: lwc1        $f22, -0x446C($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X446C);
    // 0x80132C10: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80132C14: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80132C18: addiu       $s4, $zero, 0xD
    ctx->r20 = ADD32(0, 0XD);
    // 0x80132C1C: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x80132C20: lw          $t6, 0x4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X4);
L_80132C24:
    // 0x80132C24: beql        $s1, $t6, L_80132CE0
    if (ctx->r17 == ctx->r14) {
        // 0x80132C28: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_80132CE0;
    }
    goto skip_0;
    // 0x80132C28: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_0:
    // 0x80132C2C: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
    // 0x80132C30: lbu         $t8, 0xC($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0XC);
    // 0x80132C34: lbu         $t7, 0xC($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XC);
    // 0x80132C38: beql        $t7, $t8, L_80132CE0
    if (ctx->r15 == ctx->r24) {
        // 0x80132C3C: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_80132CE0;
    }
    goto skip_1;
    // 0x80132C3C: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_1:
    // 0x80132C40: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80132C44: lw          $v0, 0x8E8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8E8);
    // 0x80132C48: lw          $v1, 0x8E8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X8E8);
    // 0x80132C4C: mul.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x80132C50: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80132C54: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80132C58: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80132C5C: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80132C60: add.s       $f18, $f8, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x80132C64: add.s       $f16, $f6, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80132C68: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80132C6C: sub.s       $f14, $f4, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x80132C70: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80132C74: nop

    // 0x80132C78: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80132C7C: jal         0x80033510
    // 0x80132C80: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80132C80: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_0:
    // 0x80132C84: lw          $t9, 0x5B4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X5B4);
    // 0x80132C88: bnel        $s3, $t9, L_80132CAC
    if (ctx->r19 != ctx->r25) {
        // 0x80132C8C: lw          $v0, 0x84C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84C);
            goto L_80132CAC;
    }
    goto skip_2;
    // 0x80132C8C: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    skip_2:
    // 0x80132C90: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x80132C94: nop

    // 0x80132C98: bc1fl       L_80132CAC
    if (!c1cs) {
        // 0x80132C9C: lw          $v0, 0x84C($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84C);
            goto L_80132CAC;
    }
    goto skip_3;
    // 0x80132C9C: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    skip_3:
    // 0x80132CA0: b           L_80132CEC
    // 0x80132CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80132CEC;
    // 0x80132CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80132CA8: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
L_80132CAC:
    // 0x80132CAC: beql        $v0, $zero, L_80132CE0
    if (ctx->r2 == 0) {
        // 0x80132CB0: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_80132CE0;
    }
    goto skip_4;
    // 0x80132CB0: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_4:
    // 0x80132CB4: lw          $t0, 0x84($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X84);
    // 0x80132CB8: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80132CBC: bnel        $s4, $t1, L_80132CE0
    if (ctx->r20 != ctx->r9) {
        // 0x80132CC0: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_80132CE0;
    }
    goto skip_5;
    // 0x80132CC0: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_5:
    // 0x80132CC4: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x80132CC8: nop

    // 0x80132CCC: bc1fl       L_80132CE0
    if (!c1cs) {
        // 0x80132CD0: lw          $s1, 0x4($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X4);
            goto L_80132CE0;
    }
    goto skip_6;
    // 0x80132CD0: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    skip_6:
    // 0x80132CD4: b           L_80132CEC
    // 0x80132CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80132CEC;
    // 0x80132CD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80132CDC: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
L_80132CE0:
    // 0x80132CE0: bnel        $s1, $zero, L_80132C24
    if (ctx->r17 != 0) {
        // 0x80132CE4: lw          $t6, 0x4($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X4);
            goto L_80132C24;
    }
    goto skip_7;
    // 0x80132CE4: lw          $t6, 0x4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X4);
    skip_7:
L_80132CE8:
    // 0x80132CE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132CEC:
    // 0x80132CEC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80132CF0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80132CF4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80132CF8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80132CFC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80132D00: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80132D04: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80132D08: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80132D0C: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80132D10: jr          $ra
    // 0x80132D14: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80132D14: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ftKirbySpecialAirNEatSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162C90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162C94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162C98: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162C9C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162CA0: jal         0x800DEE98
    // 0x80162CA4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80162CA4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162CA8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162CAC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80162CB0: addiu       $a1, $zero, 0x111
    ctx->r5 = ADD32(0, 0X111);
    // 0x80162CB4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162CB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162CBC: jal         0x800E6F24
    // 0x80162CC0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162CC0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162CC4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162CC8: jal         0x800E8098
    // 0x80162CCC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162CCC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162CD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162CD8: jr          $ra
    // 0x80162CDC: nop

    return;
    // 0x80162CDC: nop

;}

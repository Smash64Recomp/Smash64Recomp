#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void itTaruFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179CB8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179CBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179CC0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x80179CC4: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80179CC8: addiu       $a3, $a3, -0x6318
    ctx->r7 = ADD32(ctx->r7, -0X6318);
    // 0x80179CCC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x80179CD0: jal         0x80173B24
    // 0x80179CD4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80179CD4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x80179CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179CDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179CE0: jr          $ra
    // 0x80179CE4: nop

    return;
    // 0x80179CE4: nop

;}
RECOMP_FUNC void func_ovl8_80374FD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374FD0: lw          $t6, 0x20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X20);
    // 0x80374FD4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80374FD8: sw          $t8, 0x2C($t6)
    MEM_W(0X2C, ctx->r14) = ctx->r24;
    // 0x80374FDC: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80374FE0: sw          $t7, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r15;
    // 0x80374FE4: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80374FE8: sw          $t8, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->r24;
    // 0x80374FEC: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x80374FF0: sw          $t7, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->r15;
    // 0x80374FF4: lw          $t8, 0x10($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X10);
    // 0x80374FF8: sw          $t8, 0x3C($t6)
    MEM_W(0X3C, ctx->r14) = ctx->r24;
    // 0x80374FFC: lw          $t7, 0x14($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14);
    // 0x80375000: sw          $t7, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->r15;
    // 0x80375004: lw          $t8, 0x18($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X18);
    // 0x80375008: jr          $ra
    // 0x8037500C: sw          $t8, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r24;
    return;
    // 0x8037500C: sw          $t8, 0x44($t6)
    MEM_W(0X44, ctx->r14) = ctx->r24;
;}
RECOMP_FUNC void itMainSetFighterRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172984: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80172988: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017298C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80172990: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80172994: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80172998: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8017299C: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x801729A0: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x801729A4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801729A8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801729AC: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x801729B0: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x801729B4: lw          $s2, 0x84($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X84);
    // 0x801729B8: jal         0x800C9424
    // 0x801729BC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    lbCommonEjectTreeDObj(rdram, ctx);
        goto after_0;
    // 0x801729BC: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_0:
    // 0x801729C0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801729C4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x801729C8: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x801729CC: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x801729D0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801729D4: lbu         $t6, 0x2CE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2CE);
    // 0x801729D8: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x801729DC: bnel        $t7, $zero, L_801729F4
    if (ctx->r15 != 0) {
        // 0x801729E0: lw          $t9, 0x9C8($s2)
        ctx->r25 = MEM_W(ctx->r18, 0X9C8);
            goto L_801729F4;
    }
    goto skip_0;
    // 0x801729E0: lw          $t9, 0x9C8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X9C8);
    skip_0:
    // 0x801729E4: lw          $t8, 0x9C8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X9C8);
    // 0x801729E8: b           L_801729F8
    // 0x801729EC: lw          $v0, 0x334($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X334);
        goto L_801729F8;
    // 0x801729EC: lw          $v0, 0x334($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X334);
    // 0x801729F0: lw          $t9, 0x9C8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X9C8);
L_801729F4:
    // 0x801729F4: lw          $v0, 0x33C($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X33C);
L_801729F8:
    // 0x801729F8: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x801729FC: addu        $t1, $s2, $t0
    ctx->r9 = ADD32(ctx->r18, ctx->r8);
    // 0x80172A00: jal         0x800EDF24
    // 0x80172A04: lw          $a0, 0x8E8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8E8);
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_1;
    // 0x80172A04: lw          $a0, 0x8E8($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X8E8);
    after_1:
    // 0x80172A08: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80172A0C: lw          $t2, 0x74($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X74);
    // 0x80172A10: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80172A14: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80172A18: swc1        $f4, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f4.u32l;
    // 0x80172A1C: lw          $t3, 0x74($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X74);
    // 0x80172A20: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80172A24: addiu       $a2, $s2, 0x78
    ctx->r6 = ADD32(ctx->r18, 0X78);
    // 0x80172A28: swc1        $f6, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f6.u32l;
    // 0x80172A2C: lw          $t4, 0x74($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X74);
    // 0x80172A30: swc1        $f0, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f0.u32l;
    // 0x80172A34: jal         0x800DF058
    // 0x80172A38: lw          $a1, 0x78($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X78);
    mpCommonRunItemCollisionDefault(rdram, ctx);
        goto after_2;
    // 0x80172A38: lw          $a1, 0x78($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X78);
    after_2:
    // 0x80172A3C: sw          $zero, 0x84C($s2)
    MEM_W(0X84C, ctx->r18) = 0;
    // 0x80172A40: lbu         $t5, 0x2CE($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X2CE);
    // 0x80172A44: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x80172A48: andi        $t6, $t5, 0xFFBF
    ctx->r14 = ctx->r13 & 0XFFBF;
    // 0x80172A4C: sb          $t6, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r14;
    // 0x80172A50: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80172A54: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80172A58: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80172A5C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80172A60: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x80172A64: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80172A68: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x80172A6C: jal         0x800190B0
    // 0x80172A70: lw          $a1, 0x2C4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C4);
    syVectorScale3D(rdram, ctx);
        goto after_3;
    // 0x80172A70: lw          $a1, 0x2C4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X2C4);
    after_3:
    // 0x80172A74: lw          $t0, 0x2CC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2CC);
    // 0x80172A78: lbu         $t6, 0x2CE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2CE);
    // 0x80172A7C: sll         $t1, $t0, 20
    ctx->r9 = S32(ctx->r8 << 20);
    // 0x80172A80: srl         $t2, $t1, 29
    ctx->r10 = S32(U32(ctx->r9) >> 29);
    // 0x80172A84: lbu         $t0, 0x2CF($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X2CF);
    // 0x80172A88: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x80172A8C: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80172A90: andi        $t5, $t4, 0xE
    ctx->r13 = ctx->r12 & 0XE;
    // 0x80172A94: andi        $t7, $t6, 0xFFF1
    ctx->r15 = ctx->r14 & 0XFFF1;
    // 0x80172A98: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80172A9C: ori         $t1, $t0, 0x20
    ctx->r9 = ctx->r8 | 0X20;
    // 0x80172AA0: sb          $t8, 0x2CE($s0)
    MEM_B(0X2CE, ctx->r16) = ctx->r24;
    // 0x80172AA4: sb          $t1, 0x2CF($s0)
    MEM_B(0X2CF, ctx->r16) = ctx->r9;
    // 0x80172AA8: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80172AAC: addiu       $t2, $sp, 0x56
    ctx->r10 = ADD32(ctx->r29, 0X56);
    // 0x80172AB0: swc1        $f8, 0x114($s0)
    MEM_W(0X114, ctx->r16) = ctx->f8.u32l;
    // 0x80172AB4: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x80172AB8: sh          $t4, 0x15C($s0)
    MEM_H(0X15C, ctx->r16) = ctx->r12;
    // 0x80172ABC: lhu         $t6, 0x5A($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X5A);
    // 0x80172AC0: sh          $t6, 0x15E($s0)
    MEM_H(0X15E, ctx->r16) = ctx->r14;
    // 0x80172AC4: jal         0x800E8744
    // 0x80172AC8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    ftParamSetHammerParams(rdram, ctx);
        goto after_4;
    // 0x80172AC8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x80172ACC: jal         0x8017275C
    // 0x80172AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_5;
    // 0x80172AD0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80172AD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80172AD8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80172ADC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80172AE0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80172AE4: jr          $ra
    // 0x80172AE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80172AE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnVSItemSwitchSetItemToggles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132A48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132A4C: jal         0x80132988
    // 0x80132A50: nop

    mnVSItemSwitchCheckAllTogglesOff(rdram, ctx);
        goto after_0;
    // 0x80132A50: nop

    after_0:
    // 0x80132A54: beq         $v0, $zero, L_80132A68
    if (ctx->r2 == 0) {
        // 0x80132A58: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80132A68;
    }
    // 0x80132A58: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132A5C: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x80132A60: b           L_80132A84
    // 0x80132A64: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
        goto L_80132A84;
    // 0x80132A64: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
L_80132A68:
    // 0x80132A68: jal         0x801327B8
    // 0x80132A6C: nop

    mnVSItemSwitchSetItemSettings(rdram, ctx);
        goto after_1;
    // 0x80132A6C: nop

    after_1:
    // 0x80132A70: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132A74: addiu       $v0, $v0, 0x4D08
    ctx->r2 = ADD32(ctx->r2, 0X4D08);
    // 0x80132A78: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80132A7C: ori         $t7, $t6, 0xF
    ctx->r15 = ctx->r14 | 0XF;
    // 0x80132A80: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
L_80132A84:
    // 0x80132A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132A88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132A8C: jr          $ra
    // 0x80132A90: nop

    return;
    // 0x80132A90: nop

;}
RECOMP_FUNC void sc1PBonusStageSetPlayerInterfacePositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E5D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8018E5DC: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018E5E0: addiu       $v0, $v0, 0x1580
    ctx->r2 = ADD32(ctx->r2, 0X1580);
    // 0x8018E5E4: addiu       $t6, $t6, -0xFD4
    ctx->r14 = ADD32(ctx->r14, -0XFD4);
    // 0x8018E5E8: addiu       $t7, $zero, 0xD2
    ctx->r15 = ADD32(0, 0XD2);
    // 0x8018E5EC: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8018E5F0: jr          $ra
    // 0x8018E5F4: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    return;
    // 0x8018E5F4: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void grZebesAcidUpdateShake(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801082EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801082F0: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x801082F4: lhu         $t6, 0x14($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X14);
    // 0x801082F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801082FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108300: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80108304: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80108308: bne         $t8, $zero, L_80108324
    if (ctx->r24 != 0) {
        // 0x8010830C: sh          $t7, 0x14($v0)
        MEM_H(0X14, ctx->r2) = ctx->r15;
            goto L_80108324;
    }
    // 0x8010830C: sh          $t7, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r15;
    // 0x80108310: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80108314: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x80108318: sb          $t9, 0x16($v0)
    MEM_B(0X16, ctx->r2) = ctx->r25;
    // 0x8010831C: jal         0x80108020
    // 0x80108320: sh          $t0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r8;
    grZebesAcidSetLevelStep(rdram, ctx);
        goto after_0;
    // 0x80108320: sh          $t0, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r8;
    after_0:
L_80108324:
    // 0x80108324: jal         0x80108268
    // 0x80108328: nop

    grZebesAcidUpdateRumble(rdram, ctx);
        goto after_1;
    // 0x80108328: nop

    after_1:
    // 0x8010832C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80108334: jr          $ra
    // 0x80108338: nop

    return;
    // 0x80108338: nop

;}
RECOMP_FUNC void stringLength(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376FBC: bnel        $a0, $zero, L_80376FD0
    if (ctx->r4 != 0) {
        // 0x80376FC0: lbu         $t6, 0x0($a0)
        ctx->r14 = MEM_BU(ctx->r4, 0X0);
            goto L_80376FD0;
    }
    goto skip_0;
    // 0x80376FC0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    skip_0:
    // 0x80376FC4: jr          $ra
    // 0x80376FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80376FC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80376FCC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
L_80376FD0:
    // 0x80376FD0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80376FD4: beql        $t6, $zero, L_80376FF4
    if (ctx->r14 == 0) {
        // 0x80376FD8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80376FF4;
    }
    goto skip_1;
    // 0x80376FD8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x80376FDC: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
L_80376FE0:
    // 0x80376FE0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80376FE4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80376FE8: bnel        $t7, $zero, L_80376FE0
    if (ctx->r15 != 0) {
        // 0x80376FEC: lbu         $t7, 0x1($a0)
        ctx->r15 = MEM_BU(ctx->r4, 0X1);
            goto L_80376FE0;
    }
    goto skip_2;
    // 0x80376FEC: lbu         $t7, 0x1($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X1);
    skip_2:
    // 0x80376FF0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80376FF4:
    // 0x80376FF4: jr          $ra
    // 0x80376FF8: nop

    return;
    // 0x80376FF8: nop

;}
RECOMP_FUNC void itNBumperAttachedProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B9C8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017B9CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017B9D0: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x8017B9D4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017B9D8: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8017B9DC: swc1        $f0, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f0.u32l;
    // 0x8017B9E0: swc1        $f0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f0.u32l;
    // 0x8017B9E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B9E8: sh          $t6, 0x350($v1)
    MEM_H(0X350, ctx->r3) = ctx->r14;
    // 0x8017B9EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B9F0: lw          $t7, 0x80($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X80);
    // 0x8017B9F4: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x8017B9F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B9FC: swc1        $f4, 0x88($t7)
    MEM_W(0X88, ctx->r15) = ctx->f4.u32l;
    // 0x8017BA00: lw          $a2, 0x268($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X268);
    // 0x8017BA04: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8017BA08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017BA0C: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x8017BA10: negu        $t8, $a2
    ctx->r24 = SUB32(0, ctx->r6);
    // 0x8017BA14: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    // 0x8017BA18: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017BA1C: sh          $t9, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r25;
    // 0x8017BA20: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017BA24: jr          $ra
    // 0x8017BA28: swc1        $f16, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f16.u32l;
    return;
    // 0x8017BA28: swc1        $f16, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f16.u32l;
;}
RECOMP_FUNC void ftCommonJumpSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F880: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013F884: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013F888: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013F88C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8013F890: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013F894: lw          $t7, 0x9C8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C8);
    // 0x8013F898: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013F89C: jal         0x800DEEC8
    // 0x8013F8A0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8013F8A0: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    after_0:
    // 0x8013F8A4: lb          $t8, 0x1C2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1C2);
    // 0x8013F8A8: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x8013F8AC: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x8013F8B0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8013F8B4: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013F8B8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013F8BC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013F8C0: mflo        $t0
    ctx->r8 = lo;
    // 0x8013F8C4: slti        $at, $t0, -0x9
    ctx->r1 = SIGNED(ctx->r8) < -0X9 ? 1 : 0;
    // 0x8013F8C8: bne         $at, $zero, L_8013F8D8
    if (ctx->r1 != 0) {
        // 0x8013F8CC: nop
    
            goto L_8013F8D8;
    }
    // 0x8013F8CC: nop

    // 0x8013F8D0: b           L_8013F8D8
    // 0x8013F8D4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
        goto L_8013F8D8;
    // 0x8013F8D4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
L_8013F8D8:
    // 0x8013F8D8: jal         0x800E6F24
    // 0x8013F8DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013F8DC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8013F8E0: lw          $v0, 0xB20($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB20);
    // 0x8013F8E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013F8E8: beq         $v0, $at, L_8013F910
    if (ctx->r2 == ctx->r1) {
        // 0x8013F8EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8013F910;
    }
    // 0x8013F8EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013F8F0: bne         $v0, $at, L_8013F910
    if (ctx->r2 != ctx->r1) {
        // 0x8013F8F4: addiu       $a1, $sp, 0x30
        ctx->r5 = ADD32(ctx->r29, 0X30);
            goto L_8013F910;
    }
    // 0x8013F8F4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8013F8F8: lb          $a0, 0x1C2($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1C2);
    // 0x8013F8FC: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8013F900: jal         0x8013F6A0
    // 0x8013F904: lw          $a3, 0xB24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB24);
    ftCommonJumpGetJumpForceButton(rdram, ctx);
        goto after_2;
    // 0x8013F904: lw          $a3, 0xB24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0XB24);
    after_2:
    // 0x8013F908: b           L_8013F940
    // 0x8013F90C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
        goto L_8013F940;
    // 0x8013F90C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_8013F910:
    // 0x8013F910: lb          $t1, 0x1C2($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X1C2);
    // 0x8013F914: addiu       $t5, $zero, 0x35
    ctx->r13 = ADD32(0, 0X35);
    // 0x8013F918: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x8013F91C: lwc1        $f4, 0xB18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XB18);
    // 0x8013F920: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8013F924: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x8013F928: nop

    // 0x8013F92C: slti        $at, $t3, 0x35
    ctx->r1 = SIGNED(ctx->r11) < 0X35 ? 1 : 0;
    // 0x8013F930: beq         $at, $zero, L_8013F93C
    if (ctx->r1 == 0) {
        // 0x8013F934: sw          $t3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r11;
            goto L_8013F93C;
    }
    // 0x8013F934: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x8013F938: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
L_8013F93C:
    // 0x8013F93C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
L_8013F940:
    // 0x8013F940: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x8013F944: lbu         $t0, 0x192($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X192);
    // 0x8013F948: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8013F94C: lwc1        $f16, 0x3C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x8013F950: lwc1        $f4, 0x40($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X40);
    // 0x8013F954: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013F958: addiu       $t8, $zero, 0xFE
    ctx->r24 = ADD32(0, 0XFE);
    // 0x8013F95C: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x8013F960: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8013F964: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8013F968: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x8013F96C: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8013F970: lwc1        $f16, 0x38($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X38);
    // 0x8013F974: sb          $t8, 0x269($s0)
    MEM_B(0X269, ctx->r16) = ctx->r24;
    // 0x8013F978: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x8013F97C: sb          $t1, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r9;
    // 0x8013F980: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013F984: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8013F988: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x8013F98C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013F990: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013F994: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013F998: jr          $ra
    // 0x8013F99C: nop

    return;
    // 0x8013F99C: nop

;}
RECOMP_FUNC void mpProcessSetLandingFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DD59C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800DD5A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DD5A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DD5A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800DD5AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DD5B0: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    // 0x800DD5B4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800DD5B8: addiu       $v0, $s0, 0x80
    ctx->r2 = ADD32(ctx->r16, 0X80);
    // 0x800DD5BC: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800DD5C0: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800DD5C4: lwc1        $f8, 0x40($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X40);
    // 0x800DD5C8: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DD5CC: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    // 0x800DD5D0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DD5D4: swc1        $f10, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f10.u32l;
    // 0x800DD5D8: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x800DD5DC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800DD5E0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800DD5E4: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800DD5E8: jal         0x800F3DD8
    // 0x800DD5EC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_0;
    // 0x800DD5EC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_0:
    // 0x800DD5F0: beq         $v0, $zero, L_800DD60C
    if (ctx->r2 == 0) {
        // 0x800DD5F4: lw          $v1, 0x40($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X40);
            goto L_800DD60C;
    }
    // 0x800DD5F4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800DD5F8: lwc1        $f16, 0x4($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DD5FC: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800DD600: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DD604: b           L_800DD680
    // 0x800DD608: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
        goto L_800DD680;
    // 0x800DD608: swc1        $f4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f4.u32l;
L_800DD60C:
    // 0x800DD60C: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800DD610: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800DD614: jal         0x800F4428
    // 0x800DD618: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_1;
    // 0x800DD618: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_1:
    // 0x800DD61C: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800DD620: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800DD624: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800DD628: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800DD62C: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x800DD630: nop

    // 0x800DD634: bc1fl       L_800DD650
    if (!c1cs) {
        // 0x800DD638: lwc1        $f10, 0x38($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
            goto L_800DD650;
    }
    goto skip_0;
    // 0x800DD638: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    skip_0:
    // 0x800DD63C: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800DD640: jal         0x800F4408
    // 0x800DD644: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_2;
    // 0x800DD644: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_2:
    // 0x800DD648: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800DD64C: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
L_800DD650:
    // 0x800DD650: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800DD654: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800DD658: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DD65C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800DD660: swc1        $f18, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f18.u32l;
    // 0x800DD664: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800DD668: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800DD66C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800DD670: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x800DD674: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD678: jal         0x800F3DD8
    // 0x800DD67C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_3;
    // 0x800DD67C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
L_800DD680:
    // 0x800DD680: lhu         $t7, 0x5A($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DD684: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800DD688: ori         $t8, $t7, 0x800
    ctx->r24 = ctx->r15 | 0X800;
    // 0x800DD68C: sh          $t8, 0x5A($s0)
    MEM_H(0X5A, ctx->r16) = ctx->r24;
    // 0x800DD690: swc1        $f6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f6.u32l;
    // 0x800DD694: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DD698: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DD69C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800DD6A0: jr          $ra
    // 0x800DD6A4: nop

    return;
    // 0x800DD6A4: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeMenuLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EBB4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018EBB8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8018EBBC: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018EBC0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018EBC4: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x8018EBC8: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x8018EBCC: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x8018EBD0: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x8018EBD4: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8018EBD8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8018EBDC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8018EBE0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018EBE4: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018EBE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EBEC: jal         0x80009968
    // 0x8018EBF0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018EBF0: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    after_0:
    // 0x8018EBF4: lui         $s7, 0x8019
    ctx->r23 = S32(0X8019 << 16);
    // 0x8018EBF8: addiu       $s7, $s7, 0xB58
    ctx->r23 = ADD32(ctx->r23, 0XB58);
    // 0x8018EBFC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018EC00: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018EC04: sw          $v0, 0x50($s7)
    MEM_W(0X50, ctx->r23) = ctx->r2;
    // 0x8018EC08: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8018EC0C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018EC10: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018EC14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EC18: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018EC1C: jal         0x80009DF4
    // 0x8018EC20: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018EC20: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018EC24: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018EC28: addiu       $s5, $zero, 0x50
    ctx->r21 = ADD32(0, 0X50);
    // 0x8018EC2C: addiu       $s4, $zero, 0x201
    ctx->r20 = ADD32(0, 0X201);
    // 0x8018EC30: addiu       $s3, $zero, 0x6A
    ctx->r19 = ADD32(0, 0X6A);
    // 0x8018EC34: addiu       $s2, $zero, 0xA7
    ctx->r18 = ADD32(0, 0XA7);
    // 0x8018EC38: addiu       $s1, $zero, 0xF3
    ctx->r17 = ADD32(0, 0XF3);
L_8018EC3C:
    // 0x8018EC3C: lw          $t7, 0x2C($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X2C);
    // 0x8018EC40: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8018EC44: jal         0x8018DEDC
    // 0x8018EC48: addu        $a1, $s0, $t7
    ctx->r5 = ADD32(ctx->r16, ctx->r15);
    sc1PTrainingModeMakeStatDisplay(rdram, ctx);
        goto after_2;
    // 0x8018EC48: addu        $a1, $s0, $t7
    ctx->r5 = ADD32(ctx->r16, ctx->r15);
    after_2:
    // 0x8018EC4C: slti        $at, $s0, 0x30
    ctx->r1 = SIGNED(ctx->r16) < 0X30 ? 1 : 0;
    // 0x8018EC50: beq         $at, $zero, L_8018EC70
    if (ctx->r1 == 0) {
        // 0x8018EC54: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8018EC70;
    }
    // 0x8018EC54: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8018EC58: sb          $s1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r17;
    // 0x8018EC5C: sb          $s2, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r18;
    // 0x8018EC60: sb          $s3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r19;
    // 0x8018EC64: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x8018EC68: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x8018EC6C: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
L_8018EC70:
    // 0x8018EC70: bne         $s0, $s5, L_8018EC3C
    if (ctx->r16 != ctx->r21) {
        // 0x8018EC74: sh          $s4, 0x24($v0)
        MEM_H(0X24, ctx->r2) = ctx->r20;
            goto L_8018EC3C;
    }
    // 0x8018EC74: sh          $s4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r20;
    // 0x8018EC78: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018EC7C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8018EC80: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8018EC84: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8018EC88: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8018EC8C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x8018EC90: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x8018EC94: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x8018EC98: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8018EC9C: jr          $ra
    // 0x8018ECA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8018ECA0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void syVideoSetResWidth(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006E64: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006E68: sw          $a0, 0x6678($at)
    MEM_W(0X6678, ctx->r1) = ctx->r4;
    // 0x80006E6C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80006E70: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80006E74: jr          $ra
    // 0x80006E78: sw          $t6, 0x6684($at)
    MEM_W(0X6684, ctx->r1) = ctx->r14;
    return;
    // 0x80006E78: sw          $t6, 0x6684($at)
    MEM_W(0X6684, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mnVSModeMakeVSStartButton(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132154: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132158: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013215C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132160: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132164: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80132168: jal         0x80009968
    // 0x8013216C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013216C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132170: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132174: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132178: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8013217C: sw          $v0, 0x4930($at)
    MEM_W(0X4930, ctx->r1) = ctx->r2;
    // 0x80132180: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132184: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132188: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013218C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132190: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132194: jal         0x80009DF4
    // 0x80132198: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132198: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013219C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801321A0: lui         $a1, 0x42F0
    ctx->r5 = S32(0X42F0 << 16);
    // 0x801321A4: lui         $a2, 0x41F8
    ctx->r6 = S32(0X41F8 << 16);
    // 0x801321A8: jal         0x80132024
    // 0x801321AC: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    mnVSModeMakeButton(rdram, ctx);
        goto after_2;
    // 0x801321AC: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_2:
    // 0x801321B0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801321B4: lw          $t7, 0x4948($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4948);
    // 0x801321B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801321BC: bne         $t7, $zero, L_801321CC
    if (ctx->r15 != 0) {
        // 0x801321C0: nop
    
            goto L_801321CC;
    }
    // 0x801321C0: nop

    // 0x801321C4: b           L_801321CC
    // 0x801321C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_801321CC;
    // 0x801321C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_801321CC:
    // 0x801321CC: jal         0x80131F4C
    // 0x801321D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mnVSModeUpdateButton(rdram, ctx);
        goto after_3;
    // 0x801321D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x801321D4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801321D8: lw          $t8, 0x4A4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4A4C);
    // 0x801321DC: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x801321E0: addiu       $t9, $t9, 0x24C8
    ctx->r25 = ADD32(ctx->r25, 0X24C8);
    // 0x801321E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801321E8: jal         0x800CCFDC
    // 0x801321EC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801321EC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_4:
    // 0x801321F0: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x801321F4: lui         $at, 0x4319
    ctx->r1 = S32(0X4319 << 16);
    // 0x801321F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801321FC: lui         $at, 0x4210
    ctx->r1 = S32(0X4210 << 16);
    // 0x80132200: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132204: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132208: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013220C: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132210: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132214: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132218: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x8013221C: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132220: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132224: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132228: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013222C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132230: jr          $ra
    // 0x80132234: nop

    return;
    // 0x80132234: nop

;}
RECOMP_FUNC void ftNessSpecialLwEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801559F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801559F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801559FC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80155A00: jal         0x800DDE84
    // 0x80155A04: addiu       $a1, $a1, 0x5A7C
    ctx->r5 = ADD32(ctx->r5, 0X5A7C);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80155A04: addiu       $a1, $a1, 0x5A7C
    ctx->r5 = ADD32(ctx->r5, 0X5A7C);
    after_0:
    // 0x80155A08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80155A0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155A10: jr          $ra
    // 0x80155A14: nop

    return;
    // 0x80155A14: nop

;}
RECOMP_FUNC void wpNessPKReflectTrailProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016BB3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016BB40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016BB44: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016BB48: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016BB4C: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x8016BB50: jal         0x800FE068
    // 0x8016BB54: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016BB54: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016BB58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016BB5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016BB60: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016BB64: jr          $ra
    // 0x8016BB68: nop

    return;
    // 0x8016BB68: nop

;}
RECOMP_FUNC void itKamexFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180808: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018080C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180810: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80180814: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80180818: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x8018081C: jal         0x801737B8
    // 0x80180820: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80180820: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80180824: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80180828: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8018082C: lhu         $t8, 0x8E($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8E);
    // 0x80180830: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x80180834: beql        $t9, $zero, L_80180850
    if (ctx->r25 == 0) {
        // 0x80180838: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80180850;
    }
    goto skip_0;
    // 0x80180838: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018083C: jal         0x80180A58
    // 0x80180840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    itKamexAttackInitVars(rdram, ctx);
        goto after_1;
    // 0x80180840: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_1:
    // 0x80180844: jal         0x80180AF4
    // 0x80180848: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itKamexAttackSetStatus(rdram, ctx);
        goto after_2;
    // 0x80180848: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8018084C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80180850:
    // 0x80180850: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80180854: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80180858: jr          $ra
    // 0x8018085C: nop

    return;
    // 0x8018085C: nop

;}
RECOMP_FUNC void mvOpeningRoomGetDroppedFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801341B4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801341B8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801341BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801341C0: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801341C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801341C8: addiu       $t6, $t6, 0x4B90
    ctx->r14 = ADD32(ctx->r14, 0X4B90);
    // 0x801341CC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801341D0: addiu       $s0, $sp, 0x28
    ctx->r16 = ADD32(ctx->r29, 0X28);
    // 0x801341D4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x801341D8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801341DC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801341E0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x801341E4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801341E8: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x801341EC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801341F0: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x801341F4: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801341F8: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x801341FC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x80134200: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x80134204: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x80134208: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8013420C: lw          $t7, 0x1C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X1C);
    // 0x80134210: jal         0x80018A30
    // 0x80134214: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_0;
    // 0x80134214: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    after_0:
    // 0x80134218: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x8013421C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80134220: addu        $t0, $s0, $t9
    ctx->r8 = ADD32(ctx->r16, ctx->r25);
    // 0x80134224: addiu       $s1, $s1, 0x4CF8
    ctx->r17 = ADD32(ctx->r17, 0X4CF8);
    // 0x80134228: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8013422C: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x80134230: bnel        $v1, $t1, L_8013425C
    if (ctx->r3 != ctx->r9) {
        // 0x80134234: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013425C;
    }
    goto skip_0;
    // 0x80134234: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_80134238:
    // 0x80134238: jal         0x80018A30
    // 0x8013423C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_1;
    // 0x8013423C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x80134240: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80134244: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80134248: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8013424C: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x80134250: beq         $v1, $t4, L_80134238
    if (ctx->r3 == ctx->r12) {
        // 0x80134254: nop
    
            goto L_80134238;
    }
    // 0x80134254: nop

    // 0x80134258: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013425C:
    // 0x8013425C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80134260: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80134264: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80134268: jr          $ra
    // 0x8013426C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013426C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void lbCommonPlayTreeDObjsAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C92C8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C92CC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C92D0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C92D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C92D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C92DC: beq         $a0, $zero, L_800C9300
    if (ctx->r4 == 0) {
        // 0x800C92E0: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_800C9300;
    }
    // 0x800C92E0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
L_800C92E4:
    // 0x800C92E4: jal         0x8000CCBC
    // 0x800C92E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x800C92E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800C92EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C92F0: jal         0x800C86E8
    // 0x800C92F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    lbCommonGetTreeDObjNextFromRoot(rdram, ctx);
        goto after_1;
    // 0x800C92F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800C92F8: bne         $v0, $zero, L_800C92E4
    if (ctx->r2 != 0) {
        // 0x800C92FC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800C92E4;
    }
    // 0x800C92FC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800C9300:
    // 0x800C9300: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9304: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C9308: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C930C: jr          $ra
    // 0x800C9310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C9310: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnPlayers1PBonusReadyProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136698: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8013669C: lw          $t6, 0x76EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X76EC);
    // 0x801366A0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801366A4: addiu       $v1, $v1, 0x772C
    ctx->r3 = ADD32(ctx->r3, 0X772C);
    // 0x801366A8: beq         $t6, $zero, L_801366F4
    if (ctx->r14 == 0) {
        // 0x801366AC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_801366F4;
    }
    // 0x801366AC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801366B0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801366B4: addiu       $v1, $v1, 0x772C
    ctx->r3 = ADD32(ctx->r3, 0X772C);
    // 0x801366B8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801366BC: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x801366C0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801366C4: addiu       $v0, $t7, 0x1
    ctx->r2 = ADD32(ctx->r15, 0X1);
    // 0x801366C8: bne         $v0, $at, L_801366D8
    if (ctx->r2 != ctx->r1) {
        // 0x801366CC: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_801366D8;
    }
    // 0x801366CC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x801366D0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801366D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801366D8:
    // 0x801366D8: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x801366DC: beq         $at, $zero, L_801366EC
    if (ctx->r1 == 0) {
        // 0x801366E0: nop
    
            goto L_801366EC;
    }
    // 0x801366E0: nop

    // 0x801366E4: jr          $ra
    // 0x801366E8: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    return;
    // 0x801366E8: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
L_801366EC:
    // 0x801366EC: jr          $ra
    // 0x801366F0: sw          $t9, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r25;
    return;
    // 0x801366F0: sw          $t9, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r25;
L_801366F4:
    // 0x801366F4: sw          $t0, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r8;
    // 0x801366F8: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x801366FC: jr          $ra
    // 0x80136700: nop

    return;
    // 0x80136700: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNSetChargeShotPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156EFC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80156F00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156F04: lw          $t6, 0xB20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB20);
    // 0x80156F08: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x80156F0C: beql        $t6, $zero, L_80156F48
    if (ctx->r14 == 0) {
        // 0x80156F10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80156F48;
    }
    goto skip_0;
    // 0x80156F10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80156F14: jal         0x80156EBC
    // 0x80156F18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftKirbyCopySamusSpecialNGetChargeShotPosition(rdram, ctx);
        goto after_0;
    // 0x80156F18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80156F1C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80156F20: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x80156F24: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80156F28: lw          $t7, 0xB20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB20);
    // 0x80156F2C: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x80156F30: sw          $t1, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r9;
    // 0x80156F34: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80156F38: sw          $t0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r8;
    // 0x80156F3C: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80156F40: sw          $t1, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r9;
    // 0x80156F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80156F48:
    // 0x80156F48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80156F4C: jr          $ra
    // 0x80156F50: nop

    return;
    // 0x80156F50: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakePuckAdjust(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801379E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801379EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801379F0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801379F4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801379F8: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x801379FC: jal         0x80009968
    // 0x80137A00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80137A00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80137A04: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137A08: addiu       $a1, $a1, 0x799C
    ctx->r5 = ADD32(ctx->r5, 0X799C);
    // 0x80137A0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137A10: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80137A14: jal         0x80008188
    // 0x80137A18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80137A18: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x80137A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137A20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137A24: jr          $ra
    // 0x80137A28: nop

    return;
    // 0x80137A28: nop

;}
RECOMP_FUNC void sc1PIntroInitAllyTextParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E04: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x80132E08: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80132E0C: sb          $t0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r8;
    // 0x80132E10: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132E14: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x80132E18: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132E1C: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x80132E20: sb          $zero, 0x29($a0)
    MEM_B(0X29, ctx->r4) = 0;
    // 0x80132E24: jr          $ra
    // 0x80132E28: sb          $zero, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = 0;
    return;
    // 0x80132E28: sb          $zero, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = 0;
;}
RECOMP_FUNC void itBatThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174FA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174FAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174FB0: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80174FB4: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80174FB8: addiu       $a3, $a3, 0x4EC4
    ctx->r7 = ADD32(ctx->r7, 0X4EC4);
    // 0x80174FBC: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80174FC0: jal         0x80173B24
    // 0x80174FC4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80174FC4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80174FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174FCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174FD0: jr          $ra
    // 0x80174FD4: nop

    return;
    // 0x80174FD4: nop

;}
RECOMP_FUNC void mpCommonSetFighterFallOnEdgeBreak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDF44: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DDF48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDF4C: jal         0x800DDE50
    // 0x800DDF50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonCheckFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x800DDF50: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800DDF54: bnel        $v0, $zero, L_800DDF68
    if (ctx->r2 != 0) {
        // 0x800DDF58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800DDF68;
    }
    goto skip_0;
    // 0x800DDF58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800DDF5C: jal         0x8013F9E0
    // 0x800DDF60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonFallSetStatus(rdram, ctx);
        goto after_1;
    // 0x800DDF60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800DDF64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800DDF68:
    // 0x800DDF68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DDF6C: jr          $ra
    // 0x800DDF70: nop

    return;
    // 0x800DDF70: nop

;}
RECOMP_FUNC void func_ovl8_803755C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803755C4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x803755C8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x803755CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803755D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803755D4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x803755D8: beq         $a0, $zero, L_803755E4
    if (ctx->r4 == 0) {
        // 0x803755DC: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_803755E4;
    }
    // 0x803755DC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x803755E0: lw          $v0, 0x20($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X20);
L_803755E4:
    // 0x803755E4: lhu         $v1, 0x24($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X24);
    // 0x803755E8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x803755EC: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x803755F0: beq         $v1, $at, L_80375600
    if (ctx->r3 == ctx->r1) {
        // 0x803755F4: addiu       $s1, $zero, 0x3
        ctx->r17 = ADD32(0, 0X3);
            goto L_80375600;
    }
    // 0x803755F4: addiu       $s1, $zero, 0x3
    ctx->r17 = ADD32(0, 0X3);
    // 0x803755F8: b           L_80375600
    // 0x803755FC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
        goto L_80375600;
    // 0x803755FC: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_80375600:
    // 0x80375600: lw          $v0, 0x58($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X58);
    // 0x80375604: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80375608: lw          $t9, 0xA4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XA4);
    // 0x8037560C: lh          $t6, 0xA0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA0);
    // 0x80375610: jalr        $t9
    // 0x80375614: addu        $a0, $t6, $a2
    ctx->r4 = ADD32(ctx->r14, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80375614: addu        $a0, $t6, $a2
    ctx->r4 = ADD32(ctx->r14, ctx->r6);
    after_0:
    // 0x80375618: lhu         $t7, 0x4C($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X4C);
    // 0x8037561C: lhu         $t8, 0x4E($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X4E);
    // 0x80375620: beql        $t7, $zero, L_80375854
    if (ctx->r15 == 0) {
        // 0x80375624: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80375854;
    }
    goto skip_0;
    // 0x80375624: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80375628: beq         $t8, $zero, L_80375850
    if (ctx->r24 == 0) {
        // 0x8037562C: or          $a2, $s1, $zero
        ctx->r6 = ctx->r17 | 0;
            goto L_80375850;
    }
    // 0x8037562C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80375630: sh          $zero, 0x42($sp)
    MEM_H(0X42, ctx->r29) = 0;
    // 0x80375634: sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // 0x80375638: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8037563C: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    // 0x80375640: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x80375644: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x80375648: addu        $t2, $t7, $t1
    ctx->r10 = ADD32(ctx->r15, ctx->r9);
    // 0x8037564C: sh          $t2, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r10;
    // 0x80375650: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x80375654: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80375658: andi        $a0, $t2, 0xFFFF
    ctx->r4 = ctx->r10 & 0XFFFF;
    // 0x8037565C: sh          $t3, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r11;
    // 0x80375660: jal         0x8037ACAC
    // 0x80375664: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_1;
    // 0x80375664: andi        $a1, $t3, 0xFFFF
    ctx->r5 = ctx->r11 & 0XFFFF;
    after_1:
    // 0x80375668: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x8037566C: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80375670: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80375674: addiu       $a2, $a2, -0x6A80
    ctx->r6 = ADD32(ctx->r6, -0X6A80);
    // 0x80375678: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8037567C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80375680: jal         0x8037B46C
    // 0x80375684: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    func_ovl8_8037B46C(rdram, ctx);
        goto after_2;
    // 0x80375684: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    after_2:
    // 0x80375688: addiu       $t5, $sp, 0x40
    ctx->r13 = ADD32(ctx->r29, 0X40);
    // 0x8037568C: lwl         $t9, 0x0($t5)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r13, 0X0);
    // 0x80375690: lwr         $t9, 0x3($t5)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r13, 0X3);
    // 0x80375694: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80375698: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037569C: swl         $t9, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r25);
    // 0x803756A0: swr         $t9, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r25);
    // 0x803756A4: lwl         $t6, 0x4($t5)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r13, 0X4);
    // 0x803756A8: lwr         $t6, 0x7($t5)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r13, 0X7);
    // 0x803756AC: addiu       $a2, $a2, -0x6A68
    ctx->r6 = ADD32(ctx->r6, -0X6A68);
    // 0x803756B0: swl         $t6, 0x4($a1)
    do_swl(rdram, 0X4, ctx->r5, ctx->r14);
    // 0x803756B4: swr         $t6, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r14);
    // 0x803756B8: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x803756BC: lh          $t8, 0x38($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X38);
    // 0x803756C0: lhu         $t3, 0x3C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X3C);
    // 0x803756C4: addu        $t7, $t8, $t0
    ctx->r15 = ADD32(ctx->r24, ctx->r8);
    // 0x803756C8: addiu       $t1, $t7, -0x2
    ctx->r9 = ADD32(ctx->r15, -0X2);
    // 0x803756CC: sh          $t1, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r9;
    // 0x803756D0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x803756D4: sll         $t4, $t2, 1
    ctx->r12 = S32(ctx->r10 << 1);
    // 0x803756D8: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x803756DC: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x803756E0: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x803756E4: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x803756E8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x803756EC: jal         0x8037B46C
    // 0x803756F0: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    func_ovl8_8037B46C(rdram, ctx);
        goto after_3;
    // 0x803756F0: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    after_3:
    // 0x803756F4: sh          $zero, 0x42($sp)
    MEM_H(0X42, ctx->r29) = 0;
    // 0x803756F8: sh          $zero, 0x40($sp)
    MEM_H(0X40, ctx->r29) = 0;
    // 0x803756FC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80375700: lhu         $a1, 0x4E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X4E);
    // 0x80375704: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
    // 0x80375708: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8037570C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80375710: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x80375714: sh          $t9, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r25;
    // 0x80375718: andi        $a0, $t9, 0xFFFF
    ctx->r4 = ctx->r25 & 0XFFFF;
    // 0x8037571C: jal         0x8037ACAC
    // 0x80375720: sh          $a1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r5;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_4;
    // 0x80375720: sh          $a1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r5;
    after_4:
    // 0x80375724: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x80375728: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037572C: sw          $v0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r2;
    // 0x80375730: addiu       $a2, $a2, -0x6A2C
    ctx->r6 = ADD32(ctx->r6, -0X6A2C);
    // 0x80375734: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80375738: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x8037573C: jal         0x8037B46C
    // 0x80375740: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    func_ovl8_8037B46C(rdram, ctx);
        goto after_5;
    // 0x80375740: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    after_5:
    // 0x80375744: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80375748: lhu         $a1, 0x4E($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0X4E);
    // 0x8037574C: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x80375750: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80375754: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80375758: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x8037575C: sh          $t7, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r15;
    // 0x80375760: andi        $a0, $t7, 0xFFFF
    ctx->r4 = ctx->r15 & 0XFFFF;
    // 0x80375764: jal         0x8037ACAC
    // 0x80375768: sh          $a1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r5;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_6;
    // 0x80375768: sh          $a1, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r5;
    after_6:
    // 0x8037576C: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x80375770: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80375774: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80375778: addiu       $a2, $a2, -0x6A08
    ctx->r6 = ADD32(ctx->r6, -0X6A08);
    // 0x8037577C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80375780: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80375784: jal         0x8037B46C
    // 0x80375788: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    func_ovl8_8037B46C(rdram, ctx);
        goto after_7;
    // 0x80375788: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    after_7:
    // 0x8037578C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80375790: lhu         $t3, 0x4C($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X4C);
    // 0x80375794: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x80375798: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8037579C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x803757A0: sh          $t6, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r14;
    // 0x803757A4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x803757A8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x803757AC: andi        $a0, $t6, 0xFFFF
    ctx->r4 = ctx->r14 & 0XFFFF;
    // 0x803757B0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x803757B4: addiu       $a3, $zero, 0x18
    ctx->r7 = ADD32(0, 0X18);
    // 0x803757B8: sh          $t9, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r25;
    // 0x803757BC: jal         0x8037ACAC
    // 0x803757C0: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_8;
    // 0x803757C0: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
    after_8:
    // 0x803757C4: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x803757C8: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x803757CC: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x803757D0: addiu       $a2, $a2, -0x69E4
    ctx->r6 = ADD32(ctx->r6, -0X69E4);
    // 0x803757D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803757D8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x803757DC: jal         0x8037B46C
    // 0x803757E0: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    func_ovl8_8037B46C(rdram, ctx);
        goto after_9;
    // 0x803757E0: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    after_9:
    // 0x803757E4: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x803757E8: lwl         $t1, 0x0($t0)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r8, 0X0);
    // 0x803757EC: lwr         $t1, 0x3($t0)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r8, 0X3);
    // 0x803757F0: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x803757F4: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x803757F8: swl         $t1, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r9);
    // 0x803757FC: swr         $t1, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r9);
    // 0x80375800: lwl         $t7, 0x4($t0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r8, 0X4);
    // 0x80375804: lwr         $t7, 0x7($t0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r8, 0X7);
    // 0x80375808: addiu       $a2, $a2, -0x69CC
    ctx->r6 = ADD32(ctx->r6, -0X69CC);
    // 0x8037580C: swl         $t7, 0x4($a1)
    do_swl(rdram, 0X4, ctx->r5, ctx->r15);
    // 0x80375810: swr         $t7, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r15);
    // 0x80375814: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80375818: lh          $t2, 0x38($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X38);
    // 0x8037581C: lhu         $t9, 0x3C($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X3C);
    // 0x80375820: addu        $t3, $t2, $t4
    ctx->r11 = ADD32(ctx->r10, ctx->r12);
    // 0x80375824: addiu       $t5, $t3, -0x2
    ctx->r13 = ADD32(ctx->r11, -0X2);
    // 0x80375828: sh          $t5, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r13;
    // 0x8037582C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80375830: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80375834: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x80375838: addiu       $t7, $t0, 0x4
    ctx->r15 = ADD32(ctx->r8, 0X4);
    // 0x8037583C: sh          $t7, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r15;
    // 0x80375840: lw          $a3, 0x20($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X20);
    // 0x80375844: lw          $a0, 0x14($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X14);
    // 0x80375848: jal         0x8037B46C
    // 0x8037584C: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    func_ovl8_8037B46C(rdram, ctx);
        goto after_10;
    // 0x8037584C: addiu       $a3, $a3, 0x14
    ctx->r7 = ADD32(ctx->r7, 0X14);
    after_10:
L_80375850:
    // 0x80375850: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80375854:
    // 0x80375854: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80375858: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8037585C: jr          $ra
    // 0x80375860: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80375860: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void ftPikachuSpecialHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152A38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152A3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152A40: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152A44: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80152A48: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80152A4C: bgtz        $t7, L_80152A5C
    if (SIGNED(ctx->r15) > 0) {
        // 0x80152A50: sw          $t7, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r15;
            goto L_80152A5C;
    }
    // 0x80152A50: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x80152A54: jal         0x801535F4
    // 0x80152A58: nop

    ftPikachuSpecialHiEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x80152A58: nop

    after_0:
L_80152A5C:
    // 0x80152A5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152A60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152A64: jr          $ra
    // 0x80152A68: nop

    return;
    // 0x80152A68: nop

;}
RECOMP_FUNC void scSubsysControllerCheckNoInputAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80390B7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80390B80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80390B84: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80390B88: jal         0x80390A04
    // 0x80390B8C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80390B8C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_0:
    // 0x80390B90: beq         $v0, $zero, L_80390BC0
    if (ctx->r2 == 0) {
        // 0x80390B94: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80390BC0;
    }
    // 0x80390B94: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80390B98: jal         0x80390AC0
    // 0x80390B9C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x80390B9C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_1:
    // 0x80390BA0: beql        $v0, $zero, L_80390BC4
    if (ctx->r2 == 0) {
        // 0x80390BA4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80390BC4;
    }
    goto skip_0;
    // 0x80390BA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80390BA8: jal         0x80390804
    // 0x80390BAC: ori         $a0, $zero, 0xFF3F
    ctx->r4 = 0 | 0XFF3F;
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_2;
    // 0x80390BAC: ori         $a0, $zero, 0xFF3F
    ctx->r4 = 0 | 0XFF3F;
    after_2:
    // 0x80390BB0: bnel        $v0, $zero, L_80390BC4
    if (ctx->r2 != 0) {
        // 0x80390BB4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80390BC4;
    }
    goto skip_1;
    // 0x80390BB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80390BB8: b           L_80390BC4
    // 0x80390BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80390BC4;
    // 0x80390BBC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80390BC0:
    // 0x80390BC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80390BC4:
    // 0x80390BC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80390BC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80390BCC: jr          $ra
    // 0x80390BD0: nop

    return;
    // 0x80390BD0: nop

;}
RECOMP_FUNC void mnVSRecordMakeIndivPortraitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135784: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80135788: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013578C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80135790: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80135794: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80135798: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8013579C: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x801357A0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x801357A4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x801357A8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x801357AC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x801357B0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801357B4: addiu       $t7, $t7, 0x699C
    ctx->r15 = ADD32(ctx->r15, 0X699C);
    // 0x801357B8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801357BC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801357C0: addiu       $t6, $sp, 0x78
    ctx->r14 = ADD32(ctx->r29, 0X78);
    // 0x801357C4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801357C8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801357CC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801357D0: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801357D4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801357D8: addiu       $t1, $t1, 0x69AC
    ctx->r9 = ADD32(ctx->r9, 0X69AC);
    // 0x801357DC: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801357E0: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801357E4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801357E8: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801357EC: addiu       $t0, $sp, 0x58
    ctx->r8 = ADD32(ctx->r29, 0X58);
    // 0x801357F0: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801357F4: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801357F8: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801357FC: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80135800: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80135804: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80135808: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8013580C: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80135810: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80135814: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80135818: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x8013581C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x80135820: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x80135824: lw          $t2, 0x1C($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X1C);
    // 0x80135828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013582C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135830: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80135834: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    // 0x80135838: jal         0x80009968
    // 0x8013583C: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013583C: sw          $t2, 0x1C($t0)
    MEM_W(0X1C, ctx->r8) = ctx->r10;
    after_0:
    // 0x80135840: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80135844: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80135848: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x8013584C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80135850: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80135854: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80135858: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8013585C: jal         0x80009DF4
    // 0x80135860: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80135860: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x80135864: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80135868: addiu       $s2, $s2, 0x6D88
    ctx->r18 = ADD32(ctx->r18, 0X6D88);
    // 0x8013586C: addiu       $s1, $sp, 0x78
    ctx->r17 = ADD32(ctx->r29, 0X78);
    // 0x80135870: addiu       $s0, $sp, 0x58
    ctx->r16 = ADD32(ctx->r29, 0X58);
    // 0x80135874: addiu       $s7, $sp, 0x78
    ctx->r23 = ADD32(ctx->r29, 0X78);
    // 0x80135878: addiu       $s6, $zero, 0x92
    ctx->r22 = ADD32(0, 0X92);
    // 0x8013587C: addiu       $s5, $zero, 0x88
    ctx->r21 = ADD32(0, 0X88);
    // 0x80135880: addiu       $s4, $zero, 0x8A
    ctx->r20 = ADD32(0, 0X8A);
    // 0x80135884: addiu       $s3, $zero, -0x21
    ctx->r19 = ADD32(0, -0X21);
L_80135888:
    // 0x80135888: lw          $t5, 0x0($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X0);
    // 0x8013588C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80135890: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80135894: jal         0x800CCFDC
    // 0x80135898: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80135898: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x8013589C: lhu         $t7, 0x24($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X24);
    // 0x801358A0: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801358A4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x801358A8: and         $t9, $t7, $s3
    ctx->r25 = ctx->r15 & ctx->r19;
    // 0x801358AC: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801358B0: ori         $t0, $t9, 0x1
    ctx->r8 = ctx->r25 | 0X1;
    // 0x801358B4: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801358B8: lwc1        $f4, -0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, -0X8);
    // 0x801358BC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801358C0: lwc1        $f6, -0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, -0X4);
    // 0x801358C4: sb          $s4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r20;
    // 0x801358C8: sb          $s5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r21;
    // 0x801358CC: sb          $s6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r22;
    // 0x801358D0: bne         $s0, $s7, L_80135888
    if (ctx->r16 != ctx->r23) {
        // 0x801358D4: swc1        $f6, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
            goto L_80135888;
    }
    // 0x801358D4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801358D8: jal         0x801335FC
    // 0x801358DC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    mnVSRecordMakeColumnIcons(rdram, ctx);
        goto after_3;
    // 0x801358DC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_3:
    // 0x801358E0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801358E4: lw          $t1, 0x6CB8($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6CB8);
    // 0x801358E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801358EC: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x801358F0: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801358F4: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x801358F8: jal         0x80133C60
    // 0x801358FC: lw          $a1, 0x6C58($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6C58);
    mnVSRecordMakePortraitStats(rdram, ctx);
        goto after_4;
    // 0x801358FC: lw          $a1, 0x6C58($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6C58);
    after_4:
    // 0x80135900: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80135904: or          $v0, $fp, $zero
    ctx->r2 = ctx->r30 | 0;
    // 0x80135908: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8013590C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80135910: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80135914: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80135918: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8013591C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80135920: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80135924: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80135928: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8013592C: jr          $ra
    // 0x80135930: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80135930: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void itTaruRollProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A148: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017A14C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A150: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8017A154: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017A158: jal         0x8017356C
    // 0x8017A15C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestLRWallCheckFloor(rdram, ctx);
        goto after_0;
    // 0x8017A15C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017A160: bne         $v0, $zero, L_8017A180
    if (ctx->r2 != 0) {
        // 0x8017A164: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8017A180;
    }
    // 0x8017A164: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017A168: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017A16C: addiu       $a1, $a1, -0x5B7C
    ctx->r5 = ADD32(ctx->r5, -0X5B7C);
    // 0x8017A170: jal         0x80172EC8
    // 0x8017A174: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017A174: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8017A178: b           L_8017A1A8
    // 0x8017A17C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8017A1A8;
    // 0x8017A17C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017A180:
    // 0x8017A180: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A184: lhu         $t8, 0x8E($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X8E);
    // 0x8017A188: andi        $t9, $t8, 0x21
    ctx->r25 = ctx->r24 & 0X21;
    // 0x8017A18C: beql        $t9, $zero, L_8017A1A8
    if (ctx->r25 == 0) {
        // 0x8017A190: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8017A1A8;
    }
    goto skip_0;
    // 0x8017A190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8017A194: jal         0x80179C20
    // 0x8017A198: nop

    itTaruCommonProcHit(rdram, ctx);
        goto after_2;
    // 0x8017A198: nop

    after_2:
    // 0x8017A19C: b           L_8017A1AC
    // 0x8017A1A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8017A1AC;
    // 0x8017A1A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A1A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017A1A8:
    // 0x8017A1A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017A1AC:
    // 0x8017A1AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017A1B0: jr          $ra
    // 0x8017A1B4: nop

    return;
    // 0x8017A1B4: nop

;}
RECOMP_FUNC void mnBackupClearOptionConfirmProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F98: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80131F9C: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x80131FA0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80131FA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131FA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131FAC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131FB0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80131FB4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80131FB8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80131FBC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131FC0: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80131FC4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80131FC8: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80131FCC: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80131FD0: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80131FD4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80131FD8: lui         $t6, 0x30
    ctx->r14 = S32(0X30 << 16);
    // 0x80131FDC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80131FE0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80131FE4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80131FE8: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80131FEC: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80131FF0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80131FF4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80131FF8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131FFC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132000: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80132004: lui         $t6, 0xF700
    ctx->r14 = S32(0XF700 << 16);
    // 0x80132008: ori         $a0, $zero, 0xFFFF
    ctx->r4 = 0 | 0XFFFF;
    // 0x8013200C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132010: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80132014: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132018: jal         0x80006D70
    // 0x8013201C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    syVideoGetFillColor(rdram, ctx);
        goto after_0;
    // 0x8013201C: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80132020: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x80132024: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80132028: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    // 0x8013202C: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80132030: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80132034: lui         $t5, 0xE
    ctx->r13 = S32(0XE << 16);
    // 0x80132038: lui         $t8, 0xF641
    ctx->r24 = S32(0XF641 << 16);
    // 0x8013203C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80132040: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80132044: ori         $t5, $t5, 0x8100
    ctx->r13 = ctx->r13 | 0X8100;
    // 0x80132048: ori         $t8, $t8, 0x8100
    ctx->r24 = ctx->r24 | 0X8100;
    // 0x8013204C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132050: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80132054: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80132058: lui         $ra, 0xF641
    ctx->r31 = S32(0XF641 << 16);
    // 0x8013205C: lui         $t6, 0xE
    ctx->r14 = S32(0XE << 16);
    // 0x80132060: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80132064: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80132068: ori         $ra, $ra, 0x82B0
    ctx->r31 = ctx->r31 | 0X82B0;
    // 0x8013206C: ori         $t6, $t6, 0x82B0
    ctx->r14 = ctx->r14 | 0X82B0;
    // 0x80132070: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80132074: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x80132078: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8013207C: lui         $t8, 0xF60E
    ctx->r24 = S32(0XF60E << 16);
    // 0x80132080: ori         $t8, $t8, 0x82B0
    ctx->r24 = ctx->r24 | 0X82B0;
    // 0x80132084: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80132088: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8013208C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80132090: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132094: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80132098: lui         $t6, 0x41
    ctx->r14 = S32(0X41 << 16);
    // 0x8013209C: ori         $t6, $t6, 0x8100
    ctx->r14 = ctx->r14 | 0X8100;
    // 0x801320A0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801320A4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x801320A8: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x801320AC: sw          $ra, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r31;
    // 0x801320B0: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801320B4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801320B8: lui         $t6, 0xE200
    ctx->r14 = S32(0XE200 << 16);
    // 0x801320BC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x801320C0: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x801320C4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801320C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801320CC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801320D0: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x801320D4: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x801320D8: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x801320DC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x801320E0: ori         $t6, $t6, 0x1C
    ctx->r14 = ctx->r14 | 0X1C;
    // 0x801320E4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801320E8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x801320EC: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801320F0: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801320F4: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x801320F8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x801320FC: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80132100: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80132104: jal         0x800CCEAC
    // 0x80132108: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_1;
    // 0x80132108: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    after_1:
    // 0x8013210C: jal         0x800CCF00
    // 0x80132110: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_2;
    // 0x80132110: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80132114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132118: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013211C: jr          $ra
    // 0x80132120: nop

    return;
    // 0x80132120: nop

;}
RECOMP_FUNC void ftComputerGetOwnWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80131B04: lw          $v0, 0x6704($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6704);
    // 0x80131B08: beql        $v0, $zero, L_80131B3C
    if (ctx->r2 == 0) {
        // 0x80131B0C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80131B3C;
    }
    goto skip_0;
    // 0x80131B0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80131B10: lw          $a1, 0x4($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4);
    // 0x80131B14: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_80131B18:
    // 0x80131B18: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x80131B1C: bnel        $a1, $t6, L_80131B30
    if (ctx->r5 != ctx->r14) {
        // 0x80131B20: lw          $v0, 0x4($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X4);
            goto L_80131B30;
    }
    goto skip_1;
    // 0x80131B20: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x80131B24: jr          $ra
    // 0x80131B28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80131B28: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131B2C: lw          $v0, 0x4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4);
L_80131B30:
    // 0x80131B30: bnel        $v0, $zero, L_80131B18
    if (ctx->r2 != 0) {
        // 0x80131B34: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_80131B18;
    }
    goto skip_2;
    // 0x80131B34: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_2:
    // 0x80131B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131B3C:
    // 0x80131B3C: jr          $ra
    // 0x80131B40: nop

    return;
    // 0x80131B40: nop

;}
RECOMP_FUNC void n_alSynStartVoiceParams_Alt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DAA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002DAA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002DAA8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8002DAAC: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8002DAB0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8002DAB4: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8002DAB8: beql        $t6, $zero, L_8002DB78
    if (ctx->r14 == 0) {
        // 0x8002DABC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8002DB78;
    }
    goto skip_0;
    // 0x8002DABC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8002DAC0: jal         0x8002C618
    // 0x8002DAC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    __n_allocParam(rdram, ctx);
        goto after_0;
    // 0x8002DAC4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8002DAC8: lbu         $a1, 0x37($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X37);
    // 0x8002DACC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002DAD0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002DAD4: bgez        $a1, L_8002DAE4
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8002DAD8: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8002DAE4;
    }
    // 0x8002DAD8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x8002DADC: negu        $a1, $v1
    ctx->r5 = SUB32(0, ctx->r3);
    // 0x8002DAE0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
L_8002DAE4:
    // 0x8002DAE4: beq         $v0, $zero, L_8002DB74
    if (ctx->r2 == 0) {
        // 0x8002DAE8: lui         $t7, 0x8004
        ctx->r15 = S32(0X8004 << 16);
            goto L_8002DB74;
    }
    // 0x8002DAE8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8002DAEC: lw          $t7, -0x2CEC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2CEC);
    // 0x8002DAF0: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x8002DAF4: addiu       $t3, $zero, 0xD
    ctx->r11 = ADD32(0, 0XD);
    // 0x8002DAF8: lw          $t8, 0x28($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X28);
    // 0x8002DAFC: lw          $t1, 0x88($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X88);
    // 0x8002DB00: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8002DB04: sh          $t3, 0x8($a2)
    MEM_H(0X8, ctx->r6) = ctx->r11;
    // 0x8002DB08: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x8002DB0C: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x8002DB10: lh          $t4, 0x1A($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X1A);
    // 0x8002DB14: sh          $t4, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r12;
    // 0x8002DB18: lbu         $t5, 0x33($sp)
    ctx->r13 = MEM_BU(ctx->r29, 0X33);
    // 0x8002DB1C: sb          $t5, 0x12($a2)
    MEM_B(0X12, ctx->r6) = ctx->r13;
    // 0x8002DB20: lh          $t6, 0x2E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X2E);
    // 0x8002DB24: sb          $a1, 0x13($a2)
    MEM_B(0X13, ctx->r6) = ctx->r5;
    // 0x8002DB28: sh          $t6, 0x10($a2)
    MEM_H(0X10, ctx->r6) = ctx->r14;
    // 0x8002DB2C: lbu         $t7, 0x3F($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X3F);
    // 0x8002DB30: sb          $t7, 0x1C($a2)
    MEM_B(0X1C, ctx->r6) = ctx->r15;
    // 0x8002DB34: lbu         $t9, 0x43($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X43);
    // 0x8002DB38: sb          $t9, 0x1D($a2)
    MEM_B(0X1D, ctx->r6) = ctx->r25;
    // 0x8002DB3C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8002DB40: swc1        $f4, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->f4.u32l;
    // 0x8002DB44: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8002DB48: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8002DB4C: jal         0x8002C54C
    // 0x8002DB50: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    _n_timeToSamples(rdram, ctx);
        goto after_1;
    // 0x8002DB50: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    after_1:
    // 0x8002DB54: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DB58: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8002DB5C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002DB60: sw          $v0, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r2;
    // 0x8002DB64: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8002DB68: sw          $t8, 0x18($a2)
    MEM_W(0X18, ctx->r6) = ctx->r24;
    // 0x8002DB6C: jal         0x8002A230
    // 0x8002DB70: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    n_alEnvmixerParam(rdram, ctx);
        goto after_2;
    // 0x8002DB70: lw          $a0, 0x8($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X8);
    after_2:
L_8002DB74:
    // 0x8002DB74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8002DB78:
    // 0x8002DB78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8002DB7C: jr          $ra
    // 0x8002DB80: nop

    return;
    // 0x8002DB80: nop

;}
RECOMP_FUNC void ftLinkSpecialHiDecWeaponLifeCheckDestroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163BF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80163BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163BF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80163BFC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80163C00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80163C04: jal         0x80167FE8
    // 0x80163C08: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_0;
    // 0x80163C08: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80163C0C: beq         $v0, $zero, L_80163C1C
    if (ctx->r2 == 0) {
        // 0x80163C10: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80163C1C;
    }
    // 0x80163C10: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80163C14: jal         0x80163B40
    // 0x80163C18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    ftLinkSpecialHiDestroyWeapon(rdram, ctx);
        goto after_1;
    // 0x80163C18: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
L_80163C1C:
    // 0x80163C1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80163C20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80163C24: jr          $ra
    // 0x80163C28: nop

    return;
    // 0x80163C28: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137C64: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80137C68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80137C6C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80137C70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137C74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80137C78: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80137C7C: jal         0x80009968
    // 0x80137C80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80137C80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80137C84: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80137C88: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80137C8C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80137C90: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80137C94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80137C98: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80137C9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137CA0: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x80137CA4: jal         0x80009DF4
    // 0x80137CA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80137CA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80137CAC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137CB0: addiu       $a1, $a1, 0x7BE4
    ctx->r5 = ADD32(ctx->r5, 0X7BE4);
    // 0x80137CB4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80137CB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137CBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80137CC0: jal         0x80008188
    // 0x80137CC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80137CC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80137CC8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137CCC: lw          $t7, -0x6960($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6960);
    // 0x80137CD0: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80137CD4: addiu       $t8, $t8, -0xAD0
    ctx->r24 = ADD32(ctx->r24, -0XAD0);
    // 0x80137CD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137CDC: jal         0x800CCFDC
    // 0x80137CE0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80137CE0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80137CE4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80137CE8: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x80137CEC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80137CF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80137CF4: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80137CF8: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80137CFC: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80137D00: addiu       $t3, $zero, 0xF4
    ctx->r11 = ADD32(0, 0XF4);
    // 0x80137D04: addiu       $t4, $zero, 0x56
    ctx->r12 = ADD32(0, 0X56);
    // 0x80137D08: addiu       $t5, $zero, 0x7F
    ctx->r13 = ADD32(0, 0X7F);
    // 0x80137D0C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80137D10: addiu       $t7, $zero, 0x140
    ctx->r15 = ADD32(0, 0X140);
    // 0x80137D14: addiu       $t8, $zero, 0x11
    ctx->r24 = ADD32(0, 0X11);
    // 0x80137D18: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80137D1C: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80137D20: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80137D24: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80137D28: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80137D2C: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80137D30: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80137D34: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x80137D38: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80137D3C: sb          $t6, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r14;
    // 0x80137D40: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x80137D44: sh          $t7, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r15;
    // 0x80137D48: sh          $t8, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r24;
    // 0x80137D4C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80137D50: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80137D54: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80137D58: lw          $t9, -0x6960($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6960);
    // 0x80137D5C: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80137D60: addiu       $t0, $t0, -0xBB8
    ctx->r8 = ADD32(ctx->r8, -0XBB8);
    // 0x80137D64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137D68: jal         0x800CCFDC
    // 0x80137D6C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80137D6C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80137D70: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80137D74: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80137D78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80137D7C: lui         $at, 0x4298
    ctx->r1 = S32(0X4298 << 16);
    // 0x80137D80: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80137D84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80137D88: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80137D8C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80137D90: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80137D94: addiu       $t5, $zero, 0xCA
    ctx->r13 = ADD32(0, 0XCA);
    // 0x80137D98: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x80137D9C: addiu       $t7, $zero, 0x9D
    ctx->r15 = ADD32(0, 0X9D);
    // 0x80137DA0: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80137DA4: sb          $v1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r3;
    // 0x80137DA8: sb          $t5, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r13;
    // 0x80137DAC: sb          $t6, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r14;
    // 0x80137DB0: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80137DB4: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80137DB8: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x80137DBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137DC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80137DC4: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80137DC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80137DCC: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80137DD0: jal         0x80009968
    // 0x80137DD4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80137DD4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    after_5:
    // 0x80137DD8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80137DDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80137DE0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80137DE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137DE8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80137DEC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80137DF0: jal         0x80009DF4
    // 0x80137DF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x80137DF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x80137DF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137DFC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80137E00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80137E04: jal         0x80008188
    // 0x80137E08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80137E08: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80137E0C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80137E10: lw          $t9, -0x6960($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6960);
    // 0x80137E14: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80137E18: addiu       $t0, $t0, 0x14D8
    ctx->r8 = ADD32(ctx->r8, 0X14D8);
    // 0x80137E1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137E20: jal         0x800CCFDC
    // 0x80137E24: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_8;
    // 0x80137E24: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_8:
    // 0x80137E28: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80137E2C: lui         $at, 0x4305
    ctx->r1 = S32(0X4305 << 16);
    // 0x80137E30: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80137E34: lui         $at, 0x435B
    ctx->r1 = S32(0X435B << 16);
    // 0x80137E38: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80137E3C: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80137E40: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80137E44: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80137E48: addiu       $t5, $zero, 0xD6
    ctx->r13 = ADD32(0, 0XD6);
    // 0x80137E4C: addiu       $t6, $zero, 0xDD
    ctx->r14 = ADD32(0, 0XDD);
    // 0x80137E50: addiu       $t7, $zero, 0xC6
    ctx->r15 = ADD32(0, 0XC6);
    // 0x80137E54: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80137E58: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x80137E5C: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x80137E60: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x80137E64: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137E68: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80137E6C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80137E70: lw          $t8, -0x6960($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6960);
    // 0x80137E74: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80137E78: addiu       $t9, $t9, 0x1378
    ctx->r25 = ADD32(ctx->r25, 0X1378);
    // 0x80137E7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137E80: jal         0x800CCFDC
    // 0x80137E84: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x80137E84: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x80137E88: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80137E8C: lui         $at, 0x4322
    ctx->r1 = S32(0X4322 << 16);
    // 0x80137E90: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80137E94: lui         $at, 0x435B
    ctx->r1 = S32(0X435B << 16);
    // 0x80137E98: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80137E9C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80137EA0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80137EA4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80137EA8: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x80137EAC: addiu       $t5, $zero, 0x56
    ctx->r13 = ADD32(0, 0X56);
    // 0x80137EB0: addiu       $t6, $zero, 0x92
    ctx->r14 = ADD32(0, 0X92);
    // 0x80137EB4: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80137EB8: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x80137EBC: sb          $t5, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r13;
    // 0x80137EC0: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80137EC4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80137EC8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80137ECC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80137ED0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80137ED4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80137ED8: jr          $ra
    // 0x80137EDC: nop

    return;
    // 0x80137EDC: nop

;}
RECOMP_FUNC void func_ovl0_800C9F70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9F70: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800C9F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9F78: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800C9F7C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800C9F80: sw          $a2, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r6;
    // 0x800C9F84: lw          $a1, 0x84($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X84);
    // 0x800C9F88: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800C9F8C: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800C9F90: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x800C9F94: jal         0x800C9A38
    // 0x800C9F98: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    func_ovl0_800C9A38(rdram, ctx);
        goto after_0;
    // 0x800C9F98: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    after_0:
    // 0x800C9F9C: lw          $v0, 0x58($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X58);
    // 0x800C9FA0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C9FA4: addiu       $v1, $v1, -0x46D0
    ctx->r3 = ADD32(ctx->r3, -0X46D0);
    // 0x800C9FA8: lhu         $t7, 0x276($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X276);
    // 0x800C9FAC: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800C9FB0: beq         $t7, $zero, L_800CA008
    if (ctx->r15 == 0) {
        // 0x800C9FB4: nop
    
            goto L_800CA008;
    }
    // 0x800C9FB4: nop

    // 0x800C9FB8: lbu         $t8, 0x274($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X274);
    // 0x800C9FBC: lbu         $t1, 0x272($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X272);
    // 0x800C9FC0: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800C9FC4: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x800C9FC8: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x800C9FCC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800C9FD0: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800C9FD4: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x800C9FD8: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800C9FDC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800C9FE0: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800C9FE4: lbu         $t4, 0x274($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X274);
    // 0x800C9FE8: lbu         $t7, 0x272($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X272);
    // 0x800C9FEC: sll         $t5, $t4, 5
    ctx->r13 = S32(ctx->r12 << 5);
    // 0x800C9FF0: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x800C9FF4: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800C9FF8: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800C9FFC: lwc1        $f10, 0x4($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800CA000: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x800CA004: swc1        $f18, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f18.u32l;
L_800CA008:
    // 0x800CA008: jal         0x80019EA0
    // 0x800CA00C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x800CA00C: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x800CA010: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CA014: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800CA018: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CA01C: jr          $ra
    // 0x800CA020: nop

    return;
    // 0x800CA020: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157DAC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80157DB0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157DB4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80157DB8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80157DBC: addiu       $a1, $zero, 0xF6
    ctx->r5 = ADD32(0, 0XF6);
    // 0x80157DC0: lw          $t6, 0xAE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XAE8);
    // 0x80157DC4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80157DC8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80157DCC: bne         $t6, $at, L_80157DDC
    if (ctx->r14 != ctx->r1) {
        // 0x80157DD0: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80157DDC;
    }
    // 0x80157DD0: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80157DD4: b           L_80157DDC
    // 0x80157DD8: addiu       $a1, $zero, 0xF8
    ctx->r5 = ADD32(0, 0XF8);
        goto L_80157DDC;
    // 0x80157DD8: addiu       $a1, $zero, 0xF8
    ctx->r5 = ADD32(0, 0XF8);
L_80157DDC:
    // 0x80157DDC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80157DE0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80157DE4: jal         0x800E6F24
    // 0x80157DE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80157DE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80157DEC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80157DF0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80157DF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80157DF8: lw          $t8, 0xAE8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XAE8);
    // 0x80157DFC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80157E00: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80157E04: nop

    // 0x80157E08: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80157E0C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80157E10: jal         0x80157D98
    // 0x80157E14: swc1        $f10, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f10.u32l;
    ftKirbyCopyDonkeySpecialNGetStatusChargeLevelReset(rdram, ctx);
        goto after_1;
    // 0x80157E14: swc1        $f10, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f10.u32l;
    after_1:
    // 0x80157E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157E1C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80157E20: jr          $ra
    // 0x80157E24: nop

    return;
    // 0x80157E24: nop

;}
RECOMP_FUNC void mnPlayers1PBonusCheckTimeArrowRInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134574: jr          $ra
    // 0x80134578: nop

    return;
    // 0x80134578: nop

;}
RECOMP_FUNC void itSwordDroppedProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174D2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174D30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174D34: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80174D38: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80174D3C: addiu       $a3, $a3, 0x4BE4
    ctx->r7 = ADD32(ctx->r7, 0X4BE4);
    // 0x80174D40: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80174D44: jal         0x80173B24
    // 0x80174D48: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80174D48: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80174D4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174D50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174D54: jr          $ra
    // 0x80174D58: nop

    return;
    // 0x80174D58: nop

;}
RECOMP_FUNC void ftNessSpecialLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155470: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155474: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155478: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015547C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80155480: addiu       $a1, $zero, 0xED
    ctx->r5 = ADD32(0, 0XED);
    // 0x80155484: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80155488: jal         0x800E6F24
    // 0x8015548C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015548C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80155490: jal         0x800E0830
    // 0x80155494: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80155494: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80155498: jal         0x80155454
    // 0x8015549C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftNessSpecialLw_InitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015549C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801554A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801554A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801554A8: jr          $ra
    // 0x801554AC: nop

    return;
    // 0x801554AC: nop

;}
RECOMP_FUNC void mnVSResultsGetPlayerDistanceID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321AC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801321B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801321B4: jal         0x801320B8
    // 0x801321B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    mnVSResultsGetPresentLowerCount(rdram, ctx);
        goto after_0;
    // 0x801321B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801321BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801321C0: jal         0x80133684
    // 0x801321C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    mnVSResultsGetPlayerCountPlace(rdram, ctx);
        goto after_1;
    // 0x801321C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x801321C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801321CC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801321D0: bne         $v0, $at, L_80132338
    if (ctx->r2 != ctx->r1) {
        // 0x801321D4: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80132338;
    }
    // 0x801321D4: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801321D8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801321DC: jal         0x8013205C
    // 0x801321E0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    mnVSResultsGetPresentCount(rdram, ctx);
        goto after_2;
    // 0x801321E0: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x801321E4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801321E8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801321EC: beq         $v0, $a2, L_80132338
    if (ctx->r2 == ctx->r6) {
        // 0x801321F0: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80132338;
    }
    // 0x801321F0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801321F4: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x801321F8: bne         $v0, $a0, L_80132280
    if (ctx->r2 != ctx->r4) {
        // 0x801321FC: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_80132280;
    }
    // 0x801321FC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80132200: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80132204: addiu       $v0, $v0, -0x6450
    ctx->r2 = ADD32(ctx->r2, -0X6450);
    // 0x80132208: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8013220C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132210: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80132214: bne         $t8, $zero, L_80132254
    if (ctx->r24 != 0) {
        // 0x80132218: nop
    
            goto L_80132254;
    }
    // 0x80132218: nop

    // 0x8013221C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80132220: jal         0x801320B8
    // 0x80132224: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mnVSResultsGetPresentLowerCount(rdram, ctx);
        goto after_3;
    // 0x80132224: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80132228: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013222C: beq         $v0, $zero, L_80132244
    if (ctx->r2 == 0) {
        // 0x80132230: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_80132244;
    }
    // 0x80132230: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132234: beq         $v0, $a2, L_8013224C
    if (ctx->r2 == ctx->r6) {
        // 0x80132238: nop
    
            goto L_8013224C;
    }
    // 0x80132238: nop

    // 0x8013223C: b           L_8013233C
    // 0x80132240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013233C;
    // 0x80132240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132244:
    // 0x80132244: b           L_80132338
    // 0x80132248: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80132338;
    // 0x80132248: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8013224C:
    // 0x8013224C: b           L_80132338
    // 0x80132250: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80132338;
    // 0x80132250: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80132254:
    // 0x80132254: jal         0x801320B8
    // 0x80132258: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mnVSResultsGetPresentLowerCount(rdram, ctx);
        goto after_4;
    // 0x80132258: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_4:
    // 0x8013225C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132260: bne         $v0, $at, L_80132338
    if (ctx->r2 != ctx->r1) {
        // 0x80132264: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80132338;
    }
    // 0x80132264: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80132268: jal         0x80132100
    // 0x8013226C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mnVSResultsGetPlacePlayer(rdram, ctx);
        goto after_5;
    // 0x8013226C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80132270: jal         0x801320B8
    // 0x80132274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetPresentLowerCount(rdram, ctx);
        goto after_6;
    // 0x80132274: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80132278: b           L_80132338
    // 0x8013227C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80132338;
    // 0x8013227C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80132280:
    // 0x80132280: beq         $a1, $zero, L_801322AC
    if (ctx->r5 == 0) {
        // 0x80132284: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_801322AC;
    }
    // 0x80132284: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80132288: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013228C: beq         $a1, $at, L_801322D0
    if (ctx->r5 == ctx->r1) {
        // 0x80132290: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_801322D0;
    }
    // 0x80132290: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80132294: beq         $a1, $a2, L_801322F4
    if (ctx->r5 == ctx->r6) {
        // 0x80132298: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_801322F4;
    }
    // 0x80132298: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013229C: beq         $a1, $a0, L_80132318
    if (ctx->r5 == ctx->r4) {
        // 0x801322A0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80132318;
    }
    // 0x801322A0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801322A4: b           L_8013233C
    // 0x801322A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013233C;
    // 0x801322A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801322AC:
    // 0x801322AC: addiu       $v0, $v0, -0x6450
    ctx->r2 = ADD32(ctx->r2, -0X6450);
    // 0x801322B0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x801322B4: bnel        $t9, $zero, L_8013233C
    if (ctx->r25 != 0) {
        // 0x801322B8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013233C;
    }
    goto skip_0;
    // 0x801322B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801322BC: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x801322C0: beql        $t0, $zero, L_8013233C
    if (ctx->r8 == 0) {
        // 0x801322C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013233C;
    }
    goto skip_1;
    // 0x801322C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801322C8: b           L_80132338
    // 0x801322CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80132338;
    // 0x801322CC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801322D0:
    // 0x801322D0: addiu       $v0, $v0, -0x6450
    ctx->r2 = ADD32(ctx->r2, -0X6450);
    // 0x801322D4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x801322D8: bnel        $t1, $zero, L_8013233C
    if (ctx->r9 != 0) {
        // 0x801322DC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013233C;
    }
    goto skip_2;
    // 0x801322DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801322E0: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x801322E4: beql        $t2, $zero, L_8013233C
    if (ctx->r10 == 0) {
        // 0x801322E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013233C;
    }
    goto skip_3;
    // 0x801322E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x801322EC: b           L_80132338
    // 0x801322F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80132338;
    // 0x801322F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801322F4:
    // 0x801322F4: addiu       $v0, $v0, -0x6450
    ctx->r2 = ADD32(ctx->r2, -0X6450);
    // 0x801322F8: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x801322FC: bnel        $t3, $zero, L_8013233C
    if (ctx->r11 != 0) {
        // 0x80132300: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013233C;
    }
    goto skip_4;
    // 0x80132300: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80132304: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x80132308: beql        $t4, $zero, L_8013233C
    if (ctx->r12 == 0) {
        // 0x8013230C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013233C;
    }
    goto skip_5;
    // 0x8013230C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80132310: b           L_80132338
    // 0x80132314: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
        goto L_80132338;
    // 0x80132314: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
L_80132318:
    // 0x80132318: addiu       $v0, $v0, -0x6450
    ctx->r2 = ADD32(ctx->r2, -0X6450);
    // 0x8013231C: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x80132320: bnel        $t5, $zero, L_8013233C
    if (ctx->r13 != 0) {
        // 0x80132324: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013233C;
    }
    goto skip_6;
    // 0x80132324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_6:
    // 0x80132328: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8013232C: beql        $t6, $zero, L_8013233C
    if (ctx->r14 == 0) {
        // 0x80132330: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013233C;
    }
    goto skip_7;
    // 0x80132330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x80132334: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_80132338:
    // 0x80132338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013233C:
    // 0x8013233C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132340: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80132344: jr          $ra
    // 0x80132348: nop

    return;
    // 0x80132348: nop

;}
RECOMP_FUNC void mnSoundTestUpdateFunctions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320B4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801320B8: lw          $v0, 0x4364($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4364);
    // 0x801320BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801320C0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801320C4: beq         $v0, $at, L_801320F8
    if (ctx->r2 == ctx->r1) {
        // 0x801320C8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_801320F8;
    }
    // 0x801320C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801320CC: beq         $v0, $zero, L_801320E0
    if (ctx->r2 == 0) {
        // 0x801320D0: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_801320E0;
    }
    // 0x801320D0: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x801320D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801320D8: b           L_80132104
    // 0x801320DC: sw          $t6, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r14;
        goto L_80132104;
    // 0x801320DC: sw          $t6, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r14;
L_801320E0:
    // 0x801320E0: jal         0x80020A74
    // 0x801320E4: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_0;
    // 0x801320E4: nop

    after_0:
    // 0x801320E8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801320EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801320F0: b           L_80132104
    // 0x801320F4: sw          $t7, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r15;
        goto L_80132104;
    // 0x801320F4: sw          $t7, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r15;
L_801320F8:
    // 0x801320F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801320FC: jal         0x80020B38
    // 0x80132100: addiu       $a1, $zero, 0x7000
    ctx->r5 = ADD32(0, 0X7000);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_1;
    // 0x80132100: addiu       $a1, $zero, 0x7000
    ctx->r5 = ADD32(0, 0X7000);
    after_1:
L_80132104:
    // 0x80132104: jal         0x8039076C
    // 0x80132108: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x80132108: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    after_2:
    // 0x8013210C: beq         $v0, $zero, L_801321E0
    if (ctx->r2 == 0) {
        // 0x80132110: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_801321E0;
    }
    // 0x80132110: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132114: lw          $v0, 0x4308($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4308);
    // 0x80132118: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013211C: beq         $v0, $zero, L_8013213C
    if (ctx->r2 == 0) {
        // 0x80132120: nop
    
            goto L_8013213C;
    }
    // 0x80132120: nop

    // 0x80132124: beq         $v0, $at, L_80132188
    if (ctx->r2 == ctx->r1) {
        // 0x80132128: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80132188;
    }
    // 0x80132128: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013212C: beq         $v0, $at, L_801321B4
    if (ctx->r2 == ctx->r1) {
        // 0x80132130: nop
    
            goto L_801321B4;
    }
    // 0x80132130: nop

    // 0x80132134: b           L_80132238
    // 0x80132138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132238;
    // 0x80132138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013213C:
    // 0x8013213C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132140: addiu       $v0, $v0, 0x4364
    ctx->r2 = ADD32(ctx->r2, 0X4364);
    // 0x80132144: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80132148: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8013214C: blez        $t8, L_80132158
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80132150: nop
    
            goto L_80132158;
    }
    // 0x80132150: nop

    // 0x80132154: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80132158:
    // 0x80132158: jal         0x80020A74
    // 0x8013215C: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_3;
    // 0x8013215C: nop

    after_3:
    // 0x80132160: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132164: lw          $t0, 0x4348($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4348);
    // 0x80132168: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013216C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132170: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80132174: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x80132178: jal         0x80020AB4
    // 0x8013217C: lw          $a1, 0x39E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X39E0);
    syAudioPlayBGM(rdram, ctx);
        goto after_4;
    // 0x8013217C: lw          $a1, 0x39E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X39E0);
    after_4:
    // 0x80132180: b           L_80132238
    // 0x80132184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132238;
    // 0x80132184: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132188:
    // 0x80132188: jal         0x800266A0
    // 0x8013218C: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_5;
    // 0x8013218C: nop

    after_5:
    // 0x80132190: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132194: lw          $t2, 0x434C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X434C);
    // 0x80132198: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013219C: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x801321A0: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x801321A4: jal         0x800269C0
    // 0x801321A8: lhu         $a0, 0x3A96($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3A96);
    func_800269C0_275C0(rdram, ctx);
        goto after_6;
    // 0x801321A8: lhu         $a0, 0x3A96($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3A96);
    after_6:
    // 0x801321AC: b           L_80132238
    // 0x801321B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132238;
    // 0x801321B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801321B4:
    // 0x801321B4: jal         0x800266A0
    // 0x801321B8: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_7;
    // 0x801321B8: nop

    after_7:
    // 0x801321BC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801321C0: lw          $t4, 0x4350($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4350);
    // 0x801321C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801321C8: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801321CC: addu        $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x801321D0: jal         0x800269C0
    // 0x801321D4: lhu         $a0, 0x3D9E($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3D9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x801321D4: lhu         $a0, 0x3D9E($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X3D9E);
    after_8:
    // 0x801321D8: b           L_80132238
    // 0x801321DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132238;
    // 0x801321DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801321E0:
    // 0x801321E0: jal         0x8039076C
    // 0x801321E4: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_9;
    // 0x801321E4: addiu       $a0, $zero, 0x2000
    ctx->r4 = ADD32(0, 0X2000);
    after_9:
    // 0x801321E8: beq         $v0, $zero, L_80132208
    if (ctx->r2 == 0) {
        // 0x801321EC: nop
    
            goto L_80132208;
    }
    // 0x801321EC: nop

    // 0x801321F0: jal         0x80020A74
    // 0x801321F4: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_10;
    // 0x801321F4: nop

    after_10:
    // 0x801321F8: jal         0x800266A0
    // 0x801321FC: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_11;
    // 0x801321FC: nop

    after_11:
    // 0x80132200: b           L_80132238
    // 0x80132204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132238;
    // 0x80132204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132208:
    // 0x80132208: jal         0x8039076C
    // 0x8013220C: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_12;
    // 0x8013220C: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    after_12:
    // 0x80132210: beq         $v0, $zero, L_80132234
    if (ctx->r2 == 0) {
        // 0x80132214: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80132234;
    }
    // 0x80132214: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132218: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013221C: jal         0x80020BC0
    // 0x80132220: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    syAudioSetBGMVolumeFade(rdram, ctx);
        goto after_13;
    // 0x80132220: addiu       $a2, $zero, 0x78
    ctx->r6 = ADD32(0, 0X78);
    after_13:
    // 0x80132224: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x80132228: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013222C: jal         0x800266A0
    // 0x80132230: sw          $t6, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r14;
    func_800266A0_272A0(rdram, ctx);
        goto after_14;
    // 0x80132230: sw          $t6, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r14;
    after_14:
L_80132234:
    // 0x80132234: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132238:
    // 0x80132238: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013223C: jr          $ra
    // 0x80132240: nop

    return;
    // 0x80132240: nop

;}
RECOMP_FUNC void efManagerSetOffMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100BF0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80100BF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100BF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80100BFC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80100C00: jal         0x800FD4B8
    // 0x80100C04: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80100C04: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80100C08: bne         $v0, $zero, L_80100C18
    if (ctx->r2 != 0) {
        // 0x80100C0C: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80100C18;
    }
    // 0x80100C0C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80100C10: b           L_80100DD8
    // 0x80100C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100DD8;
    // 0x80100C14: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100C18:
    // 0x80100C18: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x80100C1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80100C20: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80100C24: jal         0x80009968
    // 0x80100C28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80100C28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80100C2C: bne         $v0, $zero, L_80100C44
    if (ctx->r2 != 0) {
        // 0x80100C30: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80100C44;
    }
    // 0x80100C30: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80100C34: jal         0x800FD4F8
    // 0x80100C38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x80100C38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80100C3C: b           L_80100DD8
    // 0x80100C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100DD8;
    // 0x80100C40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100C44:
    // 0x80100C44: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80100C48: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100C4C: addiu       $a1, $zero, 0x65
    ctx->r5 = ADD32(0, 0X65);
    // 0x80100C50: sw          $t6, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r14;
    // 0x80100C54: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x80100C58: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80100C5C: jal         0x800CE9E8
    // 0x80100C60: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x80100C60: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_3:
    // 0x80100C64: beq         $v0, $zero, L_80100DC8
    if (ctx->r2 == 0) {
        // 0x80100C68: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_80100DC8;
    }
    // 0x80100C68: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80100C6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80100C70: jal         0x800CE1DC
    // 0x80100C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x80100C74: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_4:
    // 0x80100C78: beq         $v0, $zero, L_80100DB4
    if (ctx->r2 == 0) {
        // 0x80100C7C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80100DB4;
    }
    // 0x80100C7C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80100C80: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80100C84: lui         $t8, 0x8010
    ctx->r24 = S32(0X8010 << 16);
    // 0x80100C88: addiu       $t8, $t8, -0x2478
    ctx->r24 = ADD32(ctx->r24, -0X2478);
    // 0x80100C8C: sw          $t8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r24;
    // 0x80100C90: sw          $t7, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r15;
    // 0x80100C94: jal         0x800CEA14
    // 0x80100C98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x80100C98: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
    // 0x80100C9C: lhu         $t9, 0x2A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X2A);
    // 0x80100CA0: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80100CA4: addiu       $a1, $a1, -0x2434
    ctx->r5 = ADD32(ctx->r5, -0X2434);
    // 0x80100CA8: bne         $t9, $zero, L_80100CB8
    if (ctx->r25 != 0) {
        // 0x80100CAC: lw          $a0, 0x34($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X34);
            goto L_80100CB8;
    }
    // 0x80100CAC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80100CB0: b           L_80100DD8
    // 0x80100CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100DD8;
    // 0x80100CB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100CB8:
    // 0x80100CB8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80100CBC: jal         0x80008188
    // 0x80100CC0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x80100CC0: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_6:
    // 0x80100CC4: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80100CC8: sw          $s0, 0x28($t0)
    MEM_W(0X28, ctx->r8) = ctx->r16;
    // 0x80100CCC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80100CD0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80100CD4: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x80100CD8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80100CDC: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x80100CE0: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80100CE4: jal         0x80018948
    // 0x80100CE8: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x80100CE8: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    after_7:
    // 0x80100CEC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80100CF0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80100CF4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80100CF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80100CFC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80100D00: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80100D04: jal         0x80018948
    // 0x80100D08: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_8;
    // 0x80100D08: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    after_8:
    // 0x80100D0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80100D10: lwc1        $f16, 0x9CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X9CC);
    // 0x80100D14: mul.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80100D18: jal         0x80035CD0
    // 0x80100D1C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x80100D1C: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_9:
    // 0x80100D20: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80100D24: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80100D28: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80100D2C: swc1        $f4, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->f4.u32l;
    // 0x80100D30: jal         0x800303F0
    // 0x80100D34: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    __sinf_recomp(rdram, ctx);
        goto after_10;
    // 0x80100D34: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    after_10:
    // 0x80100D38: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80100D3C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80100D40: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x80100D44: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80100D48: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80100D4C: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x80100D50: subu        $t7, $t6, $v0
    ctx->r15 = SUB32(ctx->r14, ctx->r2);
    // 0x80100D54: addiu       $t8, $v0, -0xA
    ctx->r24 = ADD32(ctx->r2, -0XA);
    // 0x80100D58: beq         $at, $zero, L_80100D84
    if (ctx->r1 == 0) {
        // 0x80100D5C: swc1        $f8, 0x1C($t5)
        MEM_W(0X1C, ctx->r13) = ctx->f8.u32l;
            goto L_80100D84;
    }
    // 0x80100D5C: swc1        $f8, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f8.u32l;
    // 0x80100D60: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80100D64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80100D68: lwc1        $f18, 0x9D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X9D0);
    // 0x80100D6C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80100D70: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80100D74: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80100D78: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80100D7C: b           L_80100DA4
    // 0x80100D80: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
        goto L_80100DA4;
    // 0x80100D80: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
L_80100D84:
    // 0x80100D84: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80100D88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80100D8C: lwc1        $f16, 0x9D4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X9D4);
    // 0x80100D90: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80100D94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80100D98: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80100D9C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80100DA0: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
L_80100DA4:
    // 0x80100DA4: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    // 0x80100DA8: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80100DAC: b           L_80100DD4
    // 0x80100DB0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
        goto L_80100DD4;
    // 0x80100DB0: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
L_80100DB4:
    // 0x80100DB4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80100DB8: jal         0x800FDB3C
    // 0x80100DBC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_11;
    // 0x80100DBC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_11:
    // 0x80100DC0: b           L_80100DD4
    // 0x80100DC4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_80100DD4;
    // 0x80100DC4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_80100DC8:
    // 0x80100DC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80100DCC: jal         0x800FDB3C
    // 0x80100DD0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_12;
    // 0x80100DD0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    after_12:
L_80100DD4:
    // 0x80100DD4: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
L_80100DD8:
    // 0x80100DD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80100DDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100DE0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80100DE4: jr          $ra
    // 0x80100DE8: nop

    return;
    // 0x80100DE8: nop

;}
RECOMP_FUNC void func_ovl8_80380F1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380F1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80380F20: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80380F24: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80380F28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80380F2C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80380F30: bne         $a0, $zero, L_80380F48
    if (ctx->r4 != 0) {
        // 0x80380F34: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_80380F48;
    }
    // 0x80380F34: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80380F38: jal         0x803717A0
    // 0x80380F3C: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80380F3C: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x80380F40: beq         $v0, $zero, L_80380FB0
    if (ctx->r2 == 0) {
        // 0x80380F44: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80380FB0;
    }
    // 0x80380F44: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80380F48:
    // 0x80380F48: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80380F4C: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80380F50: addiu       $a1, $s0, 0x4C
    ctx->r5 = ADD32(ctx->r16, 0X4C);
    // 0x80380F54: bnel        $t6, $zero, L_80380F78
    if (ctx->r14 != 0) {
        // 0x80380F58: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80380F78;
    }
    goto skip_0;
    // 0x80380F58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80380F5C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80380F60: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80380F64: jal         0x803717E0
    // 0x80380F68: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80380F68: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x80380F6C: jal         0x8037C2D0
    // 0x80380F70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80380F70: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80380F74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80380F78:
    // 0x80380F78: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80380F7C: jal         0x8037F300
    // 0x80380F80: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_8037F300(rdram, ctx);
        goto after_3;
    // 0x80380F80: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80380F84: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80380F88: addiu       $t7, $t7, -0x4630
    ctx->r15 = ADD32(ctx->r15, -0X4630);
    // 0x80380F8C: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80380F90: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80380F94: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80380F98: addiu       $t8, $t8, -0x4550
    ctx->r24 = ADD32(ctx->r24, -0X4550);
    // 0x80380F9C: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80380FA0: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80380FA4: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80380FA8: addiu       $t0, $t0, -0x43F8
    ctx->r8 = ADD32(ctx->r8, -0X43F8);
    // 0x80380FAC: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
L_80380FB0:
    // 0x80380FB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80380FB4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80380FB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80380FBC: jr          $ra
    // 0x80380FC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80380FC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftKirbySpecialNWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162634: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162638: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016263C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162640: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80162644: jal         0x801624C8
    // 0x80162648: addiu       $a1, $a1, 0x3224
    ctx->r5 = ADD32(ctx->r5, 0X3224);
    ftKirbySpecialNThrowCheckGotoThrow(rdram, ctx);
        goto after_0;
    // 0x80162648: addiu       $a1, $a1, 0x3224
    ctx->r5 = ADD32(ctx->r5, 0X3224);
    after_0:
    // 0x8016264C: bne         $v0, $zero, L_80162674
    if (ctx->r2 != 0) {
        // 0x80162650: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80162674;
    }
    // 0x80162650: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80162654: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162658: jal         0x80162534
    // 0x8016265C: addiu       $a1, $a1, 0x3314
    ctx->r5 = ADD32(ctx->r5, 0X3314);
    ftKirbySpecialNCopyCheckGotoCopy(rdram, ctx);
        goto after_1;
    // 0x8016265C: addiu       $a1, $a1, 0x3314
    ctx->r5 = ADD32(ctx->r5, 0X3314);
    after_1:
    // 0x80162660: bne         $v0, $zero, L_80162674
    if (ctx->r2 != 0) {
        // 0x80162664: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80162674;
    }
    // 0x80162664: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80162668: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8016266C: jal         0x801625B0
    // 0x80162670: addiu       $a1, $a1, 0x32C4
    ctx->r5 = ADD32(ctx->r5, 0X32C4);
    ftKirbySpecialNTurnCheckGotoTurn(rdram, ctx);
        goto after_2;
    // 0x80162670: addiu       $a1, $a1, 0x32C4
    ctx->r5 = ADD32(ctx->r5, 0X32C4);
    after_2:
L_80162674:
    // 0x80162674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80162678: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016267C: jr          $ra
    // 0x80162680: nop

    return;
    // 0x80162680: nop

;}
RECOMP_FUNC void itFushigibanaCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801845B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801845B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801845BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801845C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801845C4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801845C8: lw          $s1, 0x74($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X74);
    // 0x801845CC: lwc1        $f6, 0x350($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X350);
    // 0x801845D0: lwc1        $f4, 0x1C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x801845D4: lwc1        $f10, 0x20($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X20);
    // 0x801845D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801845DC: swc1        $f8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f8.u32l;
    // 0x801845E0: lwc1        $f16, 0x354($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X354);
    // 0x801845E4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801845E8: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
    // 0x801845EC: jal         0x80184440
    // 0x801845F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    itFushigibanaCommonUpdateMonsterEvent(rdram, ctx);
        goto after_0;
    // 0x801845F0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_0:
    // 0x801845F4: lw          $t7, 0x1C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X1C);
    // 0x801845F8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x801845FC: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80184600: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80184604: lw          $t6, 0x20($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X20);
    // 0x80184608: lui         $at, 0xC407
    ctx->r1 = S32(0XC407 << 16);
    // 0x8018460C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80184610: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x80184614: lw          $t7, 0x24($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X24);
    // 0x80184618: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018461C: sw          $t7, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r15;
    // 0x80184620: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80184624: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80184628: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    // 0x8018462C: lhu         $v0, 0x35C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X35C);
    // 0x80184630: beq         $v0, $at, L_80184674
    if (ctx->r2 == ctx->r1) {
        // 0x80184634: andi        $t8, $v0, 0x1
        ctx->r24 = ctx->r2 & 0X1;
            goto L_80184674;
    }
    // 0x80184634: andi        $t8, $v0, 0x1
    ctx->r24 = ctx->r2 & 0X1;
    // 0x80184638: beq         $t8, $zero, L_801846C0
    if (ctx->r24 == 0) {
        // 0x8018463C: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_801846C0;
    }
    // 0x8018463C: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80184640: lwc1        $f0, 0x7C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X7C);
    // 0x80184644: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80184648: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8018464C: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80184650: nop

    // 0x80184654: bc1fl       L_801846C4
    if (!c1cs) {
        // 0x80184658: lw          $t3, 0x80($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X80);
            goto L_801846C4;
    }
    goto skip_0;
    // 0x80184658: lw          $t3, 0x80($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X80);
    skip_0:
    // 0x8018465C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80184660: nop

    // 0x80184664: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x80184668: nop

    // 0x8018466C: bc1fl       L_801846C4
    if (!c1cs) {
        // 0x80184670: lw          $t3, 0x80($s1)
        ctx->r11 = MEM_W(ctx->r17, 0X80);
            goto L_801846C4;
    }
    goto skip_1;
    // 0x80184670: lw          $t3, 0x80($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X80);
    skip_1:
L_80184674:
    // 0x80184674: lw          $t0, 0x80($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X80);
    // 0x80184678: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018467C: sh          $t9, 0x80($t0)
    MEM_H(0X80, ctx->r8) = ctx->r25;
    // 0x80184680: lhu         $v0, 0x35E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X35E);
    // 0x80184684: bne         $v0, $zero, L_801846B0
    if (ctx->r2 != 0) {
        // 0x80184688: nop
    
            goto L_801846B0;
    }
    // 0x80184688: nop

    // 0x8018468C: jal         0x801849EC
    // 0x80184690: nop

    itFushigibanaWeaponRazorMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x80184690: nop

    after_1:
    // 0x80184694: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80184698: sh          $t1, 0x35E($s0)
    MEM_H(0X35E, ctx->r16) = ctx->r9;
    // 0x8018469C: jal         0x800269C0
    // 0x801846A0: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x801846A0: addiu       $a0, $zero, 0x8C
    ctx->r4 = ADD32(0, 0X8C);
    after_2:
    // 0x801846A4: jal         0x800FECBC
    // 0x801846A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    efManagerDustCollideMakeEffect(rdram, ctx);
        goto after_3;
    // 0x801846A8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_3:
    // 0x801846AC: lhu         $v0, 0x35E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X35E);
L_801846B0:
    // 0x801846B0: blez        $v0, L_801846C8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801846B4: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_801846C8;
    }
    // 0x801846B4: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x801846B8: b           L_801846C8
    // 0x801846BC: sh          $t2, 0x35E($s0)
    MEM_H(0X35E, ctx->r16) = ctx->r10;
        goto L_801846C8;
    // 0x801846BC: sh          $t2, 0x35E($s0)
    MEM_H(0X35E, ctx->r16) = ctx->r10;
L_801846C0:
    // 0x801846C0: lw          $t3, 0x80($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X80);
L_801846C4:
    // 0x801846C4: sh          $zero, 0x80($t3)
    MEM_H(0X80, ctx->r11) = 0;
L_801846C8:
    // 0x801846C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801846CC: lwc1        $f18, -0x30D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X30D0);
    // 0x801846D0: lwc1        $f4, 0x74($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X74);
    // 0x801846D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801846D8: c.eq.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl == ctx->f4.fl;
    // 0x801846DC: nop

    // 0x801846E0: bc1f        L_801846F8
    if (!c1cs) {
        // 0x801846E4: nop
    
            goto L_801846F8;
    }
    // 0x801846E4: nop

    // 0x801846E8: jal         0x8010B0B8
    // 0x801846EC: nop

    grYamabukiGateSetClosedWait(rdram, ctx);
        goto after_4;
    // 0x801846EC: nop

    after_4:
    // 0x801846F0: b           L_801846F8
    // 0x801846F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801846F8;
    // 0x801846F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801846F8:
    // 0x801846F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801846FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80184700: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80184704: jr          $ra
    // 0x80184708: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80184708: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnPlayersVSSetPlayerNot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A3AC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8013A3B0: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8013A3B4: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8013A3B8: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8013A3BC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013A3C0: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x8013A3C4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013A3C8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8013A3CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013A3D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013A3D4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8013A3D8: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8013A3DC: addiu       $t9, $zero, 0x1C
    ctx->r25 = ADD32(0, 0X1C);
    // 0x8013A3E0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8013A3E4: sw          $t8, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r24;
    // 0x8013A3E8: sw          $t9, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r25;
    // 0x8013A3EC: sw          $t0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r8;
    // 0x8013A3F0: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8013A3F4: jal         0x8013295C
    // 0x8013A3F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayersVSUpdatePlayerKindSelect(rdram, ctx);
        goto after_0;
    // 0x8013A3F8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8013A3FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013A400: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013A404: jr          $ra
    // 0x8013A408: nop

    return;
    // 0x8013A408: nop

;}
RECOMP_FUNC void mvEndingInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132774: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132778: lbu         $t6, 0x4AE3($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AE3);
    // 0x8013277C: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80132780: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132784: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80132788: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8013278C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80132790: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80132794: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80132798: addiu       $t8, $t8, 0x4B18
    ctx->r24 = ADD32(ctx->r24, 0X4B18);
    // 0x8013279C: sw          $zero, 0x2BCC($at)
    MEM_W(0X2BCC, ctx->r1) = 0;
    // 0x801327A0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x801327A4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801327A8: lbu         $t9, 0x23($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X23);
    // 0x801327AC: lbu         $t0, 0x26($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X26);
    // 0x801327B0: lbu         $t1, 0x27($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X27);
    // 0x801327B4: addiu       $v1, $v1, 0x2C08
    ctx->r3 = ADD32(ctx->r3, 0X2C08);
    // 0x801327B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801327BC: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x801327C0: jr          $ra
    // 0x801327C4: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    return;
    // 0x801327C4: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
;}
RECOMP_FUNC void lbCommonMakeSObjForGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCFDC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CCFE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CCFE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800CCFE8: lbu         $t6, 0x31($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X31);
    // 0x800CCFEC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800CCFF0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800CCFF4: bne         $t6, $at, L_800CD008
    if (ctx->r14 != ctx->r1) {
        // 0x800CCFF8: nop
    
            goto L_800CD008;
    }
    // 0x800CCFF8: nop

    // 0x800CCFFC: jal         0x800CB738
    // 0x800CD000: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    lbCommonDecodeSpriteBitmapsSiz4b(rdram, ctx);
        goto after_0;
    // 0x800CD000: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800CD004: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_800CD008:
    // 0x800CD008: jal         0x80009614
    // 0x800CD00C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcAddSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x800CD00C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800CD010: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800CD014: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800CD018: sb          $zero, 0x63($v0)
    MEM_B(0X63, ctx->r2) = 0;
    // 0x800CD01C: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x800CD020: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x800CD024: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x800CD028: sb          $zero, 0x67($v0)
    MEM_B(0X67, ctx->r2) = 0;
    // 0x800CD02C: sb          $zero, 0x66($v0)
    MEM_B(0X66, ctx->r2) = 0;
    // 0x800CD030: sb          $t9, 0x65($v0)
    MEM_B(0X65, ctx->r2) = ctx->r25;
    // 0x800CD034: sb          $t9, 0x64($v0)
    MEM_B(0X64, ctx->r2) = ctx->r25;
    // 0x800CD038: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x800CD03C: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x800CD040: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD044: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD048: jr          $ra
    // 0x800CD04C: nop

    return;
    // 0x800CD04C: nop

;}
RECOMP_FUNC void ftCommonCliffAttackSlow2SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145794: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80145798: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014579C: jal         0x80145490
    // 0x801457A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftCommonCliffCommon2UpdateCollData(rdram, ctx);
        goto after_0;
    // 0x801457A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801457A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801457A8: addiu       $a1, $zero, 0x5F
    ctx->r5 = ADD32(0, 0X5F);
    // 0x801457AC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801457B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801457B4: jal         0x800E6F24
    // 0x801457B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801457B8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801457BC: jal         0x8014557C
    // 0x801457C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonCliffCommon2InitStatusVars(rdram, ctx);
        goto after_2;
    // 0x801457C0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801457C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801457C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801457CC: jr          $ra
    // 0x801457D0: nop

    return;
    // 0x801457D0: nop

;}
RECOMP_FUNC void itTomatoFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174588: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017458C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174590: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80174594: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80174598: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x8017459C: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x801745A0: jal         0x80173F78
    // 0x801745A4: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x801745A4: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x801745A8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801745AC: addiu       $a1, $a1, -0x689C
    ctx->r5 = ADD32(ctx->r5, -0X689C);
    // 0x801745B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x801745B4: jal         0x80172EC8
    // 0x801745B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801745B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x801745BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801745C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801745C4: jr          $ra
    // 0x801745C8: nop

    return;
    // 0x801745C8: nop

;}

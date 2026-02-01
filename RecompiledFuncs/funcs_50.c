#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayers1PBonusUpdateCostume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801355E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801355E4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801355E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801355EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801355F0: jal         0x800EC0EC
    // 0x801355F4: lw          $a0, 0x7668($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7668);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x801355F4: lw          $a0, 0x7668($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7668);
    after_0:
    // 0x801355F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801355FC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80135600: lw          $a0, 0x7650($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X7650);
    // 0x80135604: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80135608: jal         0x800E9248
    // 0x8013560C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_1;
    // 0x8013560C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80135610: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80135614: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135618: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    // 0x8013561C: jal         0x800269C0
    // 0x80135620: sw          $t6, 0x766C($at)
    MEM_W(0X766C, ctx->r1) = ctx->r14;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80135620: sw          $t6, 0x766C($at)
    MEM_W(0X766C, ctx->r1) = ctx->r14;
    after_2:
    // 0x80135624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80135628: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013562C: jr          $ra
    // 0x80135630: nop

    return;
    // 0x80135630: nop

;}
RECOMP_FUNC void func_ovl8_80382870(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382870: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80382874: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80382878: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038287C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80382880: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80382884: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80382888: bne         $a0, $zero, L_803828A0
    if (ctx->r4 != 0) {
        // 0x8038288C: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_803828A0;
    }
    // 0x8038288C: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80382890: jal         0x803717A0
    // 0x80382894: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80382894: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_0:
    // 0x80382898: beq         $v0, $zero, L_80382948
    if (ctx->r2 == 0) {
        // 0x8038289C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80382948;
    }
    // 0x8038289C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803828A0:
    // 0x803828A0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x803828A4: addiu       $a0, $s0, 0xE4
    ctx->r4 = ADD32(ctx->r16, 0XE4);
    // 0x803828A8: addiu       $a1, $s0, 0xD8
    ctx->r5 = ADD32(ctx->r16, 0XD8);
    // 0x803828AC: bnel        $t6, $zero, L_803828D0
    if (ctx->r14 != 0) {
        // 0x803828B0: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_803828D0;
    }
    goto skip_0;
    // 0x803828B0: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x803828B4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x803828B8: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x803828BC: jal         0x803717E0
    // 0x803828C0: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803828C0: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_1:
    // 0x803828C4: jal         0x8037C2D0
    // 0x803828C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803828C8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x803828CC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_803828D0:
    // 0x803828D0: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x803828D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803828D8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x803828DC: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x803828E0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x803828E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x803828E8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x803828EC: jal         0x8037E97C
    // 0x803828F0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    func_ovl8_8037E97C(rdram, ctx);
        goto after_3;
    // 0x803828F0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    after_3:
    // 0x803828F4: addiu       $a0, $s0, 0xB8
    ctx->r4 = ADD32(ctx->r16, 0XB8);
    // 0x803828F8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x803828FC: jal         0x8038116C
    // 0x80382900: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    func_ovl8_8038116C(rdram, ctx);
        goto after_4;
    // 0x80382900: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_4:
    // 0x80382904: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80382908: addiu       $t9, $t9, -0x3E40
    ctx->r25 = ADD32(ctx->r25, -0X3E40);
    // 0x8038290C: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x80382910: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80382914: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x80382918: addiu       $t0, $t0, -0x3D60
    ctx->r8 = ADD32(ctx->r8, -0X3D60);
    // 0x8038291C: sw          $t0, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->r8;
    // 0x80382920: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80382924: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80382928: addiu       $t2, $t2, -0x3C08
    ctx->r10 = ADD32(ctx->r10, -0X3C08);
    // 0x8038292C: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80382930: lui         $t5, 0x8039
    ctx->r13 = S32(0X8039 << 16);
    // 0x80382934: sw          $t2, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r10;
    // 0x80382938: addiu       $t5, $t5, -0x3B78
    ctx->r13 = ADD32(ctx->r13, -0X3B78);
    // 0x8038293C: addiu       $t4, $t4, -0x3BE0
    ctx->r12 = ADD32(ctx->r12, -0X3BE0);
    // 0x80382940: sw          $t4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r12;
    // 0x80382944: sw          $t5, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->r13;
L_80382948:
    // 0x80382948: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8038294C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80382950: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80382954: jr          $ra
    // 0x80382958: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80382958: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void gcGetMObjSetNextAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007EDC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007EE0: addiu       $a2, $a2, 0x6A28
    ctx->r6 = ADD32(ctx->r6, 0X6A28);
    // 0x80007EE4: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80007EE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007EF0: bne         $v1, $zero, L_80007F14
    if (ctx->r3 != 0) {
        // 0x80007EF4: addiu       $a0, $zero, 0xA8
        ctx->r4 = ADD32(0, 0XA8);
            goto L_80007F14;
    }
    // 0x80007EF4: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    // 0x80007EF8: jal         0x80004980
    // 0x80007EFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80007EFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80007F00: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007F04: addiu       $a2, $a2, 0x6A28
    ctx->r6 = ADD32(ctx->r6, 0X6A28);
    // 0x80007F08: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80007F0C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80007F10: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_80007F14:
    // 0x80007F14: bne         $v1, $zero, L_80007F30
    if (ctx->r3 != 0) {
        // 0x80007F18: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_80007F30;
    }
    // 0x80007F18: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80007F1C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007F20: jal         0x80023624
    // 0x80007F24: addiu       $a0, $a0, -0x2638
    ctx->r4 = ADD32(ctx->r4, -0X2638);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80007F24: addiu       $a0, $a0, -0x2638
    ctx->r4 = ADD32(ctx->r4, -0X2638);
    after_1:
L_80007F28:
    // 0x80007F28: b           L_80007F28
    pause_self(rdram);
    // 0x80007F2C: nop

L_80007F30:
    // 0x80007F30: addiu       $a1, $a1, 0x6A2C
    ctx->r5 = ADD32(ctx->r5, 0X6A2C);
    // 0x80007F34: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80007F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007F3C: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007F40: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80007F44: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80007F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007F4C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80007F50: jr          $ra
    // 0x80007F54: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x80007F54: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void func_ovl8_80374CCC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374CCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374CD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374CD4: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374CD8: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x80374CDC: lh          $t6, 0xD0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XD0);
    // 0x80374CE0: jalr        $t9
    // 0x80374CE4: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374CE4: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374CEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374CF0: jr          $ra
    // 0x80374CF4: nop

    return;
    // 0x80374CF4: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeStock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013419C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801341A0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x801341A4: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801341A8: addiu       $s1, $s1, -0x7040
    ctx->r17 = ADD32(ctx->r17, -0X7040);
    // 0x801341AC: lw          $a2, 0x0($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X0);
    // 0x801341B0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801341B4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x801341B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801341BC: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x801341C0: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801341C4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801341C8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801341CC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801341D0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801341D4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x801341D8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x801341DC: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x801341E0: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x801341E4: beq         $a2, $zero, L_801341F4
    if (ctx->r6 == 0) {
        // 0x801341E8: sdc1        $f20, 0x20($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
            goto L_801341F4;
    }
    // 0x801341E8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x801341EC: jal         0x80009A84
    // 0x801341F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801341F0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
L_801341F4:
    // 0x801341F4: lui         $s3, 0x8000
    ctx->r19 = S32(0X8000 << 16);
    // 0x801341F8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x801341FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134200: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134204: jal         0x80009968
    // 0x80134208: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80134208: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    after_1:
    // 0x8013420C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80134210: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80134214: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80134218: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8013421C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134220: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80134224: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134228: addiu       $a2, $zero, 0x22
    ctx->r6 = ADD32(0, 0X22);
    // 0x8013422C: jal         0x80009DF4
    // 0x80134230: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80134230: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_2:
    // 0x80134234: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80134238: blez        $s0, L_80134310
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8013423C: sll         $s1, $s0, 2
        ctx->r17 = S32(ctx->r16 << 2);
            goto L_80134310;
    }
    // 0x8013423C: sll         $s1, $s0, 2
    ctx->r17 = S32(ctx->r16 << 2);
    // 0x80134240: lui         $at, 0x4332
    ctx->r1 = S32(0X4332 << 16);
    // 0x80134244: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80134248: lui         $at, 0x434F
    ctx->r1 = S32(0X434F << 16);
    // 0x8013424C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80134250: lui         $at, 0x4333
    ctx->r1 = S32(0X4333 << 16);
    // 0x80134254: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80134258: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x8013425C: lui         $s7, 0x8014
    ctx->r23 = S32(0X8014 << 16);
    // 0x80134260: lui         $s5, 0x0
    ctx->r21 = S32(0X0 << 16);
    // 0x80134264: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80134268: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8013426C: addiu       $s4, $s4, -0x6960
    ctx->r20 = ADD32(ctx->r20, -0X6960);
    // 0x80134270: addiu       $s5, $s5, 0x80
    ctx->r21 = ADD32(ctx->r21, 0X80);
    // 0x80134274: addiu       $s7, $s7, -0x7118
    ctx->r23 = ADD32(ctx->r23, -0X7118);
    // 0x80134278: addiu       $s1, $s1, -0xC
    ctx->r17 = ADD32(ctx->r17, -0XC);
    // 0x8013427C: addiu       $s6, $zero, -0x21
    ctx->r22 = ADD32(0, -0X21);
    // 0x80134280: addiu       $s3, $zero, 0x1C
    ctx->r19 = ADD32(0, 0X1C);
L_80134284:
    // 0x80134284: bnel        $fp, $s3, L_801342A8
    if (ctx->r30 != ctx->r19) {
        // 0x80134288: lw          $t8, 0x8($s7)
        ctx->r24 = MEM_W(ctx->r23, 0X8);
            goto L_801342A8;
    }
    goto skip_0;
    // 0x80134288: lw          $t8, 0x8($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X8);
    skip_0:
    // 0x8013428C: lw          $t7, 0x1C($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X1C);
    // 0x80134290: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80134294: jal         0x800CCFDC
    // 0x80134298: addu        $a1, $t7, $s5
    ctx->r5 = ADD32(ctx->r15, ctx->r21);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80134298: addu        $a1, $t7, $s5
    ctx->r5 = ADD32(ctx->r15, ctx->r21);
    after_3:
    // 0x8013429C: b           L_801342E4
    // 0x801342A0: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
        goto L_801342E4;
    // 0x801342A0: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x801342A4: lw          $t8, 0x8($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X8);
L_801342A8:
    // 0x801342A8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801342AC: lw          $s0, 0x84($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X84);
    // 0x801342B0: lw          $t9, 0x9C8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X9C8);
    // 0x801342B4: lw          $t0, 0x340($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X340);
    // 0x801342B8: jal         0x800CCFDC
    // 0x801342BC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801342BC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    after_4:
    // 0x801342C0: lw          $t1, 0x9C8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X9C8);
    // 0x801342C4: lbu         $t4, 0x10($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X10);
    // 0x801342C8: lw          $t2, 0x340($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X340);
    // 0x801342CC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x801342D0: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801342D4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x801342D8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801342DC: swc1        $f24, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f24.u32l;
    // 0x801342E0: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
L_801342E4:
    // 0x801342E4: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x801342E8: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801342EC: addiu       $s1, $s1, -0xC
    ctx->r17 = ADD32(ctx->r17, -0XC);
    // 0x801342F0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801342F4: and         $t0, $t8, $s6
    ctx->r8 = ctx->r24 & ctx->r22;
    // 0x801342F8: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801342FC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80134300: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80134304: add.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f22.fl;
    // 0x80134308: bgez        $s1, L_80134284
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8013430C: swc1        $f8, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
            goto L_80134284;
    }
    // 0x8013430C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
L_80134310:
    // 0x80134310: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80134314: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80134318: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8013431C: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80134320: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x80134324: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x80134328: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8013432C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x80134330: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x80134334: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x80134338: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8013433C: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x80134340: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x80134344: jr          $ra
    // 0x80134348: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80134348: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftNessSpecialLwHitSetAbsorbTrue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155934: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80155938: lbu         $t7, 0x18D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18D);
    // 0x8015593C: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80155940: jr          $ra
    // 0x80155944: sb          $t8, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r24;
    return;
    // 0x80155944: sb          $t8, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void ftSamusSpecialHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DE0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015DE10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015DE14: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015DE18: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015DE1C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015DE20: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x8015DE24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015DE28: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015DE2C: jal         0x800E6F24
    // 0x8015DE30: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015DE30: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015DE34: jal         0x800E0830
    // 0x8015DE38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015DE38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015DE3C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8015DE40: sw          $zero, 0x180($t7)
    MEM_W(0X180, ctx->r15) = 0;
    // 0x8015DE44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015DE48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015DE4C: jr          $ra
    // 0x8015DE50: nop

    return;
    // 0x8015DE50: nop

;}
RECOMP_FUNC void func_ovl8_80385460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385460: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80385464: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80385468: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8038546C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80385470: jal         0x803717A0
    // 0x80385474: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80385474: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x80385478: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8038547C: beq         $v0, $zero, L_803854AC
    if (ctx->r2 == 0) {
        // 0x80385480: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803854AC;
    }
    // 0x80385480: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80385484: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80385488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8038548C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80385490: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80385494: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80385498: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8038549C: jal         0x803854C4
    // 0x803854A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_803854C4(rdram, ctx);
        goto after_1;
    // 0x803854A0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x803854A4: b           L_803854B0
    // 0x803854A8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_803854B0;
    // 0x803854A8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_803854AC:
    // 0x803854AC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803854B0:
    // 0x803854B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803854B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803854B8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803854BC: jr          $ra
    // 0x803854C0: nop

    return;
    // 0x803854C0: nop

;}
RECOMP_FUNC void gcGetGObjProcess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007604: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007608: addiu       $a2, $a2, 0x66CC
    ctx->r6 = ADD32(ctx->r6, 0X66CC);
    // 0x8000760C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80007610: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007614: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007618: bne         $v1, $zero, L_8000763C
    if (ctx->r3 != 0) {
        // 0x8000761C: addiu       $a0, $zero, 0x24
        ctx->r4 = ADD32(0, 0X24);
            goto L_8000763C;
    }
    // 0x8000761C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80007620: jal         0x80004980
    // 0x80007624: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80007624: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x80007628: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8000762C: addiu       $a2, $a2, 0x66CC
    ctx->r6 = ADD32(ctx->r6, 0X66CC);
    // 0x80007630: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80007634: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80007638: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_8000763C:
    // 0x8000763C: bne         $v1, $zero, L_80007658
    if (ctx->r3 != 0) {
        // 0x80007640: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_80007658;
    }
    // 0x80007640: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80007644: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007648: jal         0x80023624
    // 0x8000764C: addiu       $a0, $a0, -0x268C
    ctx->r4 = ADD32(ctx->r4, -0X268C);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x8000764C: addiu       $a0, $a0, -0x268C
    ctx->r4 = ADD32(ctx->r4, -0X268C);
    after_1:
L_80007650:
    // 0x80007650: b           L_80007650
    pause_self(rdram);
    // 0x80007654: nop

L_80007658:
    // 0x80007658: addiu       $a1, $a1, 0x66E8
    ctx->r5 = ADD32(ctx->r5, 0X66E8);
    // 0x8000765C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80007660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007664: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007668: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8000766C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80007670: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007674: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80007678: jr          $ra
    // 0x8000767C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x8000767C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void ftComputerFollowObjectiveRush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A298: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013A29C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013A2A0: jal         0x8013295C
    // 0x8013A2A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    ftComputerCheckFindTarget(rdram, ctx);
        goto after_0;
    // 0x8013A2A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013A2A8: beq         $v0, $zero, L_8013A374
    if (ctx->r2 == 0) {
        // 0x8013A2AC: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8013A374;
    }
    // 0x8013A2AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8013A2B0: jal         0x80018948
    // 0x8013A2B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x8013A2B4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x8013A2B8: jal         0x80018948
    // 0x8013A2BC: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x8013A2BC: nop

    after_2:
    // 0x8013A2C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8013A2C4: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    // 0x8013A2C8: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x8013A2CC: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x8013A2D0: lwc1        $f12, 0x60($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X60);
    // 0x8013A2D4: lwc1        $f2, 0x1C($t6)
    ctx->f2.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x8013A2D8: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8013A2DC: nop

    // 0x8013A2E0: bc1fl       L_8013A2FC
    if (!c1cs) {
        // 0x8013A2E4: c.lt.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
            goto L_8013A2FC;
    }
    goto skip_0;
    // 0x8013A2E4: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    skip_0:
    // 0x8013A2E8: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x8013A2EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013A2F0: beql        $t7, $at, L_8013A304
    if (ctx->r15 == ctx->r1) {
        // 0x8013A2F4: lui         $at, 0x4396
        ctx->r1 = S32(0X4396 << 16);
            goto L_8013A304;
    }
    goto skip_1;
    // 0x8013A2F4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    skip_1:
    // 0x8013A2F8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
L_8013A2FC:
    // 0x8013A2FC: nop

    // 0x8013A300: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
L_8013A304:
    // 0x8013A304: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013A308: lui         $at, 0x4496
    ctx->r1 = S32(0X4496 << 16);
    // 0x8013A30C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013A310: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8013A314: lwc1        $f4, 0x68($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X68);
    // 0x8013A318: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8013A31C: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8013A320: nop

    // 0x8013A324: bc1f        L_8013A360
    if (!c1cs) {
        // 0x8013A328: nop
    
            goto L_8013A360;
    }
    // 0x8013A328: nop

    // 0x8013A32C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8013A330: jal         0x80132EC8
    // 0x8013A334: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    ftComputerCheckDetectTarget(rdram, ctx);
        goto after_3;
    // 0x8013A334: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_3:
    // 0x8013A338: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013A33C: beq         $v0, $zero, L_8013A34C
    if (ctx->r2 == 0) {
        // 0x8013A340: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8013A34C;
    }
    // 0x8013A340: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8013A344: b           L_8013A37C
    // 0x8013A348: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_8013A37C;
    // 0x8013A348: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_8013A34C:
    // 0x8013A34C: jal         0x80134E98
    // 0x8013A350: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_4;
    // 0x8013A350: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_4:
    // 0x8013A354: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013A358: b           L_8013A37C
    // 0x8013A35C: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_8013A37C;
    // 0x8013A35C: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_8013A360:
    // 0x8013A360: jal         0x80134E98
    // 0x8013A364: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_5;
    // 0x8013A364: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_5:
    // 0x8013A368: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8013A36C: b           L_8013A37C
    // 0x8013A370: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_8013A37C;
    // 0x8013A370: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_8013A374:
    // 0x8013A374: jal         0x8013877C
    // 0x8013A378: nop

    func_ovl3_8013877C(rdram, ctx);
        goto after_6;
    // 0x8013A378: nop

    after_6:
L_8013A37C:
    // 0x8013A37C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013A380: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8013A384: jr          $ra
    // 0x8013A388: nop

    return;
    // 0x8013A388: nop

;}
RECOMP_FUNC void gcGetGObjProcessThreadStackSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007884: bne         $a0, $zero, L_80007894
    if (ctx->r4 != 0) {
        // 0x80007888: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80007894;
    }
    // 0x80007888: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000788C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007890: lw          $a0, 0x6A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A60);
L_80007894:
    // 0x80007894: beq         $a0, $zero, L_800078B4
    if (ctx->r4 == 0) {
        // 0x80007898: nop
    
            goto L_800078B4;
    }
    // 0x80007898: nop

    // 0x8000789C: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x800078A0: bne         $t6, $zero, L_800078B4
    if (ctx->r14 != 0) {
        // 0x800078A4: nop
    
            goto L_800078B4;
    }
    // 0x800078A4: nop

    // 0x800078A8: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x800078AC: jr          $ra
    // 0x800078B0: lw          $v0, 0x1BC($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1BC);
    return;
    // 0x800078B0: lw          $v0, 0x1BC($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1BC);
L_800078B4:
    // 0x800078B4: jr          $ra
    // 0x800078B8: nop

    return;
    // 0x800078B8: nop

;}
RECOMP_FUNC void func_ovl8_80384654(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384654: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80384658: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8038465C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80384660: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80384664: beq         $a0, $zero, L_803846DC
    if (ctx->r4 == 0) {
        // 0x80384668: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_803846DC;
    }
    // 0x80384668: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8038466C: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x80384670: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80384674: addiu       $t6, $t6, -0x2F30
    ctx->r14 = ADD32(ctx->r14, -0X2F30);
    // 0x80384678: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8038467C: addiu       $t7, $t7, -0x2DE8
    ctx->r15 = ADD32(ctx->r15, -0X2DE8);
    // 0x80384680: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x80384684: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80384688: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x8038468C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80384690: addiu       $t9, $t9, -0x2C90
    ctx->r25 = ADD32(ctx->r25, -0X2C90);
    // 0x80384694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80384698: jal         0x80383510
    // 0x8038469C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_80383510(rdram, ctx);
        goto after_0;
    // 0x8038469C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x803846A0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x803846A4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803846A8: beql        $t1, $zero, L_803846C8
    if (ctx->r9 == 0) {
        // 0x803846AC: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_803846C8;
    }
    goto skip_0;
    // 0x803846AC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x803846B0: jal         0x8037C30C
    // 0x803846B4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x803846B4: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x803846B8: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x803846BC: jal         0x803718C4
    // 0x803846C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x803846C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x803846C4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_803846C8:
    // 0x803846C8: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x803846CC: beql        $t3, $zero, L_803846E0
    if (ctx->r11 == 0) {
        // 0x803846D0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_803846E0;
    }
    goto skip_1;
    // 0x803846D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x803846D4: jal         0x803717C0
    // 0x803846D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x803846D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_803846DC:
    // 0x803846DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_803846E0:
    // 0x803846E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803846E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803846E8: jr          $ra
    // 0x803846EC: nop

    return;
    // 0x803846EC: nop

;}
RECOMP_FUNC void ifCommonEntryAllMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112A80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80112A84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80112A88: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80112A8C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80112A90: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80112A94: jal         0x80009968
    // 0x80112A98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80112A98: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80112A9C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80112AA0: addiu       $a1, $a1, 0x2A34
    ctx->r5 = ADD32(ctx->r5, 0X2A34);
    // 0x80112AA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80112AA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80112AAC: jal         0x80008188
    // 0x80112AB0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80112AB0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x80112AB4: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80112AB8: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80112ABC: sb          $zero, 0x11($t6)
    MEM_B(0X11, ctx->r14) = 0;
    // 0x80112AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80112AC8: jr          $ra
    // 0x80112ACC: nop

    return;
    // 0x80112ACC: nop

;}
RECOMP_FUNC void gmCollisionCheckWeaponAttackItemAttackCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F019C: addiu       $t2, $zero, 0x60
    ctx->r10 = ADD32(0, 0X60);
    // 0x800F01A0: multu       $a1, $t2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F01A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800F01A8: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800F01AC: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800F01B0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800F01B4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800F01B8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800F01BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F01C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800F01C4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800F01C8: mflo        $t7
    ctx->r15 = lo;
    // 0x800F01CC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800F01D0: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    // 0x800F01D4: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F01D8: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800F01DC: addiu       $a0, $v0, 0x54
    ctx->r4 = ADD32(ctx->r2, 0X54);
    // 0x800F01E0: addiu       $a1, $v0, 0x60
    ctx->r5 = ADD32(ctx->r2, 0X60);
    // 0x800F01E4: mflo        $t9
    ctx->r25 = lo;
    // 0x800F01E8: addu        $v1, $s0, $t9
    ctx->r3 = ADD32(ctx->r16, ctx->r25);
    // 0x800F01EC: addiu       $t0, $v1, 0x58
    ctx->r8 = ADD32(ctx->r3, 0X58);
    // 0x800F01F0: addiu       $t1, $v1, 0x64
    ctx->r9 = ADD32(ctx->r3, 0X64);
    // 0x800F01F4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800F01F8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800F01FC: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800F0200: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800F0204: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800F0208: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800F020C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800F0210: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800F0214: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x800F0218: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800F021C: jal         0x800EF5D4
    // 0x800F0220: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    func_ovl2_800EF5D4(rdram, ctx);
        goto after_0;
    // 0x800F0220: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_0:
    // 0x800F0224: bne         $v0, $zero, L_800F0234
    if (ctx->r2 != 0) {
        // 0x800F0228: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_800F0234;
    }
    // 0x800F0228: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800F022C: b           L_800F02A8
    // 0x800F0230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F02A8;
    // 0x800F0230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0234:
    // 0x800F0234: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800F0238: addiu       $v0, $v1, 0x74
    ctx->r2 = ADD32(ctx->r3, 0X74);
    // 0x800F023C: addiu       $t4, $v1, 0xB4
    ctx->r12 = ADD32(ctx->r3, 0XB4);
    // 0x800F0240: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800F0244: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F0248: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800F024C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800F0250: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800F0254: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0258: jal         0x800EE050
    // 0x800F025C: addiu       $a3, $v1, 0x70
    ctx->r7 = ADD32(ctx->r3, 0X70);
    func_ovl2_800EE050(rdram, ctx);
        goto after_1;
    // 0x800F025C: addiu       $a3, $v1, 0x70
    ctx->r7 = ADD32(ctx->r3, 0X70);
    after_1:
    // 0x800F0260: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800F0264: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800F0268: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    // 0x800F026C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800F0270: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F0274: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800F0278: lw          $t5, 0x70($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X70);
    // 0x800F027C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800F0280: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800F0284: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800F0288: lwc1        $f6, 0x2C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800F028C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800F0290: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800F0294: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800F0298: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800F029C: lwc1        $f8, 0xB4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x800F02A0: jal         0x800EEEAC
    // 0x800F02A4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_ovl2_800EEEAC(rdram, ctx);
        goto after_2;
    // 0x800F02A4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_2:
L_800F02A8:
    // 0x800F02A8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F02AC: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800F02B0: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800F02B4: jr          $ra
    // 0x800F02B8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800F02B8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void mnPlayers1PBonusFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801369D0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801369D4: addiu       $v1, $v1, 0x7724
    ctx->r3 = ADD32(ctx->r3, 0X7724);
    // 0x801369D8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x801369DC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801369E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801369E4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801369E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801369EC: lw          $t8, 0x7728($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7728);
    // 0x801369F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801369F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801369F8: bne         $t8, $t7, L_80136A28
    if (ctx->r24 != ctx->r15) {
        // 0x801369FC: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80136A28;
    }
    // 0x801369FC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80136A00: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80136A04: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80136A08: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80136A0C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80136A10: jal         0x80136998
    // 0x80136A14: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    mnPlayers1PBonusSetSceneData(rdram, ctx);
        goto after_0;
    // 0x80136A14: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_0:
    // 0x80136A18: jal         0x80005C74
    // 0x80136A1C: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x80136A1C: nop

    after_1:
    // 0x80136A20: b           L_80136B08
    // 0x80136A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80136B08;
    // 0x80136A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136A28:
    // 0x80136A28: jal         0x80390B7C
    // 0x80136A2C: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_2;
    // 0x80136A2C: nop

    after_2:
    // 0x80136A30: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80136A34: bne         $v0, $zero, L_80136A4C
    if (ctx->r2 != 0) {
        // 0x80136A38: addiu       $v1, $v1, 0x7724
        ctx->r3 = ADD32(ctx->r3, 0X7724);
            goto L_80136A4C;
    }
    // 0x80136A38: addiu       $v1, $v1, 0x7724
    ctx->r3 = ADD32(ctx->r3, 0X7724);
    // 0x80136A3C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80136A40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136A44: addiu       $t3, $t2, 0x4650
    ctx->r11 = ADD32(ctx->r10, 0X4650);
    // 0x80136A48: sw          $t3, 0x7728($at)
    MEM_W(0X7728, ctx->r1) = ctx->r11;
L_80136A4C:
    // 0x80136A4C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80136A50: addiu       $v1, $v1, 0x76EC
    ctx->r3 = ADD32(ctx->r3, 0X76EC);
    // 0x80136A54: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80136A58: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80136A5C: beq         $v0, $zero, L_80136A78
    if (ctx->r2 == 0) {
        // 0x80136A60: nop
    
            goto L_80136A78;
    }
    // 0x80136A60: nop

    // 0x80136A64: lw          $t4, 0x76A0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X76A0);
    // 0x80136A68: bne         $t4, $zero, L_80136A78
    if (ctx->r12 != 0) {
        // 0x80136A6C: nop
    
            goto L_80136A78;
    }
    // 0x80136A6C: nop

    // 0x80136A70: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80136A74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136A78:
    // 0x80136A78: beq         $v0, $zero, L_80136B04
    if (ctx->r2 == 0) {
        // 0x80136A7C: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80136B04;
    }
    // 0x80136A7C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80136A80: addiu       $v0, $v0, 0x76E8
    ctx->r2 = ADD32(ctx->r2, 0X76E8);
    // 0x80136A84: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80136A88: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80136A8C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80136A90: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x80136A94: beq         $t6, $zero, L_80136AC4
    if (ctx->r14 == 0) {
        // 0x80136A98: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_80136AC4;
    }
    // 0x80136A98: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80136A9C: lw          $t8, 0x76F8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X76F8);
    // 0x80136AA0: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80136AA4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80136AA8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80136AAC: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80136AB0: addu        $t0, $t0, $t9
    ctx->r8 = ADD32(ctx->r8, ctx->r25);
    // 0x80136AB4: lhu         $t0, 0x522A($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X522A);
    // 0x80136AB8: andi        $t1, $t0, 0x1000
    ctx->r9 = ctx->r8 & 0X1000;
    // 0x80136ABC: beql        $t1, $zero, L_80136B08
    if (ctx->r9 == 0) {
        // 0x80136AC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136B08;
    }
    goto skip_0;
    // 0x80136AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_80136AC4:
    // 0x80136AC4: lw          $t2, 0x7714($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7714);
    // 0x80136AC8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80136ACC: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80136AD0: bne         $t2, $zero, L_80136AEC
    if (ctx->r10 != 0) {
        // 0x80136AD4: addiu       $t5, $zero, 0x35
        ctx->r13 = ADD32(0, 0X35);
            goto L_80136AEC;
    }
    // 0x80136AD4: addiu       $t5, $zero, 0x35
    ctx->r13 = ADD32(0, 0X35);
    // 0x80136AD8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80136ADC: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80136AE0: addiu       $t3, $zero, 0x13
    ctx->r11 = ADD32(0, 0X13);
    // 0x80136AE4: b           L_80136AF4
    // 0x80136AE8: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
        goto L_80136AF4;
    // 0x80136AE8: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
L_80136AEC:
    // 0x80136AEC: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80136AF0: sb          $t4, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r12;
L_80136AF4:
    // 0x80136AF4: jal         0x80136998
    // 0x80136AF8: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    mnPlayers1PBonusSetSceneData(rdram, ctx);
        goto after_3;
    // 0x80136AF8: sb          $t5, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r13;
    after_3:
    // 0x80136AFC: jal         0x80005C74
    // 0x80136B00: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_4;
    // 0x80136B00: nop

    after_4:
L_80136B04:
    // 0x80136B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136B08:
    // 0x80136B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136B0C: jr          $ra
    // 0x80136B10: nop

    return;
    // 0x80136B10: nop

;}
RECOMP_FUNC void itTomatoWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174554: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017455C: jal         0x80172E74
    // 0x80174560: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_0;
    // 0x80174560: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80174564: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80174568: addiu       $a1, $a1, -0x689C
    ctx->r5 = ADD32(ctx->r5, -0X689C);
    // 0x8017456C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80174570: jal         0x80172EC8
    // 0x80174574: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80174574: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80174578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017457C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174580: jr          $ra
    // 0x80174584: nop

    return;
    // 0x80174584: nop

;}
RECOMP_FUNC void mpCollisionCheckProjectFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F9348: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800F934C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F9350: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F9354: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x800F9358: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x800F935C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x800F9360: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x800F9364: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x800F9368: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x800F936C: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x800F9370: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x800F9374: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x800F9378: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x800F937C: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x800F9380: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x800F9384: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800F9388: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800F938C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800F9390: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800F9394: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800F9398: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800F939C: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800F93A0: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800F93A4: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x800F93A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F93AC: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800F93B0: lhu         $t0, 0x0($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X0);
    // 0x800F93B4: lwc1        $f26, 0x8EC($at)
    ctx->f26.u32l = MEM_W(ctx->r1, 0X8EC);
    // 0x800F93B8: blez        $t0, L_800F975C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x800F93BC: nop
    
            goto L_800F975C;
    }
    // 0x800F93BC: nop

    // 0x800F93C0: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x800F93C4: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_800F93C8:
    // 0x800F93C8: lw          $t7, 0x7C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X7C);
    // 0x800F93CC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F93D0: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800F93D4: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800F93D8: lhu         $t3, 0x4($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X4);
    // 0x800F93DC: addiu       $a0, $t7, 0x2
    ctx->r4 = ADD32(ctx->r15, 0X2);
    // 0x800F93E0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800F93E4: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x800F93E8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800F93EC: beq         $t3, $zero, L_800F973C
    if (ctx->r11 == 0) {
        // 0x800F93F0: lw          $v0, 0x0($t2)
        ctx->r2 = MEM_W(ctx->r10, 0X0);
            goto L_800F973C;
    }
    // 0x800F93F0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x800F93F4: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800F93F8: lw          $t4, 0x80($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X80);
    // 0x800F93FC: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F9400: beql        $at, $zero, L_800F9740
    if (ctx->r1 == 0) {
        // 0x800F9404: lw          $t4, 0x70($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X70);
            goto L_800F9740;
    }
    goto skip_0;
    // 0x800F9404: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
    skip_0:
    // 0x800F9408: lw          $t5, 0x70($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X70);
    // 0x800F940C: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x800F9410: lwc1        $f2, 0x4($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800F9414: bnel        $t5, $zero, L_800F9428
    if (ctx->r13 != 0) {
        // 0x800F9418: lwc1        $f4, 0x1C($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
            goto L_800F9428;
    }
    goto skip_1;
    // 0x800F9418: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    skip_1:
    // 0x800F941C: beql        $v1, $zero, L_800F943C
    if (ctx->r3 == 0) {
        // 0x800F9420: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800F943C;
    }
    goto skip_2;
    // 0x800F9420: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_2:
    // 0x800F9424: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
L_800F9428:
    // 0x800F9428: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F942C: sub.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800F9430: b           L_800F9440
    // 0x800F9434: sub.s       $f24, $f2, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f2.fl - ctx->f6.fl;
        goto L_800F9440;
    // 0x800F9434: sub.s       $f24, $f2, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800F9438: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_800F943C:
    // 0x800F943C: mov.s       $f24, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    ctx->f24.fl = ctx->f2.fl;
L_800F9440:
    // 0x800F9440: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F9444: lhu         $t6, 0x2($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2);
    // 0x800F9448: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800F944C: addu        $t9, $v0, $t6
    ctx->r25 = ADD32(ctx->r2, ctx->r14);
    // 0x800F9450: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800F9454: beq         $at, $zero, L_800F973C
    if (ctx->r1 == 0) {
        // 0x800F9458: sll         $s7, $v0, 2
        ctx->r23 = S32(ctx->r2 << 2);
            goto L_800F973C;
    }
    // 0x800F9458: sll         $s7, $v0, 2
    ctx->r23 = S32(ctx->r2 << 2);
    // 0x800F945C: addu        $s7, $s7, $v0
    ctx->r23 = ADD32(ctx->r23, ctx->r2);
    // 0x800F9460: sll         $s7, $s7, 1
    ctx->r23 = S32(ctx->r23 << 1);
L_800F9464:
    // 0x800F9464: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F9468: lw          $t8, 0x136C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X136C);
    // 0x800F946C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F9470: addu        $t1, $t8, $s7
    ctx->r9 = ADD32(ctx->r24, ctx->r23);
    // 0x800F9474: lh          $t2, 0x4($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X4);
    // 0x800F9478: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800F947C: nop

    // 0x800F9480: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F9484: c.le.s      $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f10.fl <= ctx->f24.fl;
    // 0x800F9488: nop

    // 0x800F948C: bc1fl       L_800F9714
    if (!c1cs) {
        // 0x800F9490: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F9714;
    }
    goto skip_3;
    // 0x800F9490: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_3:
    // 0x800F9494: lw          $t7, 0x1378($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1378);
    // 0x800F9498: sll         $t3, $s6, 2
    ctx->r11 = S32(ctx->r22 << 2);
    // 0x800F949C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800F94A0: addu        $a1, $t7, $t3
    ctx->r5 = ADD32(ctx->r15, ctx->r11);
    // 0x800F94A4: lhu         $v0, 0x0($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X0);
    // 0x800F94A8: lw          $a2, 0x1374($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1374);
    // 0x800F94AC: lhu         $a3, 0x2($a1)
    ctx->r7 = MEM_HU(ctx->r5, 0X2);
    // 0x800F94B0: sll         $s2, $v0, 1
    ctx->r18 = S32(ctx->r2 << 1);
    // 0x800F94B4: addu        $v1, $a2, $s2
    ctx->r3 = ADD32(ctx->r6, ctx->r18);
    // 0x800F94B8: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F94BC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800F94C0: lw          $t0, 0x1370($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1370);
    // 0x800F94C4: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F94C8: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800F94CC: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x800F94D0: sll         $t8, $a3, 1
    ctx->r24 = S32(ctx->r7 << 1);
    // 0x800F94D4: addu        $t9, $a2, $t6
    ctx->r25 = ADD32(ctx->r6, ctx->r14);
    // 0x800F94D8: addu        $t1, $t9, $t8
    ctx->r9 = ADD32(ctx->r25, ctx->r24);
    // 0x800F94DC: lhu         $t2, 0x0($t1)
    ctx->r10 = MEM_HU(ctx->r9, 0X0);
    // 0x800F94E0: mflo        $t5
    ctx->r13 = lo;
    // 0x800F94E4: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x800F94E8: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x800F94EC: multu       $t2, $s3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F94F0: mtc1        $s1, $f16
    ctx->f16.u32l = ctx->r17;
    // 0x800F94F4: nop

    // 0x800F94F8: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F94FC: mflo        $t7
    ctx->r15 = lo;
    // 0x800F9500: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800F9504: addu        $t3, $t0, $t7
    ctx->r11 = ADD32(ctx->r8, ctx->r15);
    // 0x800F9508: lh          $s0, 0x0($t3)
    ctx->r16 = MEM_H(ctx->r11, 0X0);
    // 0x800F950C: bc1fl       L_800F9534
    if (!c1cs) {
        // 0x800F9510: mtc1        $s0, $f6
        ctx->f6.u32l = ctx->r16;
            goto L_800F9534;
    }
    goto skip_4;
    // 0x800F9510: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
    skip_4:
    // 0x800F9514: mtc1        $s0, $f18
    ctx->f18.u32l = ctx->r16;
    // 0x800F9518: nop

    // 0x800F951C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800F9520: c.le.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl <= ctx->f4.fl;
    // 0x800F9524: nop

    // 0x800F9528: bc1tl       L_800F955C
    if (c1cs) {
        // 0x800F952C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800F955C;
    }
    goto skip_5;
    // 0x800F952C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
    // 0x800F9530: mtc1        $s0, $f6
    ctx->f6.u32l = ctx->r16;
L_800F9534:
    // 0x800F9534: nop

    // 0x800F9538: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F953C: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x800F9540: nop

    // 0x800F9544: bc1fl       L_800F9714
    if (!c1cs) {
        // 0x800F9548: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F9714;
    }
    goto skip_6;
    // 0x800F9548: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_6:
    // 0x800F954C: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F9550: nop

    // 0x800F9554: bc1f        L_800F9710
    if (!c1cs) {
        // 0x800F9558: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800F9710;
    }
    // 0x800F9558: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800F955C:
    // 0x800F955C: beql        $a3, $at, L_800F9618
    if (ctx->r7 == ctx->r1) {
        // 0x800F9560: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800F9618;
    }
    goto skip_7;
    // 0x800F9560: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_7:
    // 0x800F9564: blez        $a3, L_800F9614
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800F9568: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F9614;
    }
    // 0x800F9568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F956C:
    // 0x800F956C: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F9570: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x800F9574: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9578: mflo        $t5
    ctx->r13 = lo;
    // 0x800F957C: addu        $a0, $t0, $t5
    ctx->r4 = ADD32(ctx->r8, ctx->r13);
    // 0x800F9580: lh          $s1, 0x0($a0)
    ctx->r17 = MEM_H(ctx->r4, 0X0);
    // 0x800F9584: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9588: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x800F958C: nop

    // 0x800F9590: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F9594: mflo        $t9
    ctx->r25 = lo;
    // 0x800F9598: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800F959C: addu        $t8, $t0, $t9
    ctx->r24 = ADD32(ctx->r8, ctx->r25);
    // 0x800F95A0: lh          $s0, 0x0($t8)
    ctx->r16 = MEM_H(ctx->r24, 0X0);
    // 0x800F95A4: bc1fl       L_800F95CC
    if (!c1cs) {
        // 0x800F95A8: mtc1        $s0, $f4
        ctx->f4.u32l = ctx->r16;
            goto L_800F95CC;
    }
    goto skip_8;
    // 0x800F95A8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    skip_8:
    // 0x800F95AC: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x800F95B0: nop

    // 0x800F95B4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F95B8: c.le.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl <= ctx->f18.fl;
    // 0x800F95BC: nop

    // 0x800F95C0: bc1tl       L_800F9618
    if (c1cs) {
        // 0x800F95C4: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800F9618;
    }
    goto skip_9;
    // 0x800F95C4: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_9:
    // 0x800F95C8: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
L_800F95CC:
    // 0x800F95CC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F95D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F95D4: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x800F95D8: nop

    // 0x800F95DC: bc1fl       L_800F95F8
    if (!c1cs) {
        // 0x800F95E0: addiu       $s2, $s2, 0x2
        ctx->r18 = ADD32(ctx->r18, 0X2);
            goto L_800F95F8;
    }
    goto skip_10;
    // 0x800F95E0: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    skip_10:
    // 0x800F95E4: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F95E8: nop

    // 0x800F95EC: bc1tl       L_800F9618
    if (c1cs) {
        // 0x800F95F0: lhu         $t7, 0x2($v1)
        ctx->r15 = MEM_HU(ctx->r3, 0X2);
            goto L_800F9618;
    }
    goto skip_11;
    // 0x800F95F0: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
    skip_11:
    // 0x800F95F4: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
L_800F95F8:
    // 0x800F95F8: bne         $v0, $a3, L_800F956C
    if (ctx->r2 != ctx->r7) {
        // 0x800F95FC: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800F956C;
    }
    // 0x800F95FC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800F9600: lhu         $t1, 0x0($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X0);
    // 0x800F9604: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800F9608: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800F960C: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x800F9610: addu        $a0, $t0, $t2
    ctx->r4 = ADD32(ctx->r8, ctx->r10);
L_800F9614:
    // 0x800F9614: lhu         $t7, 0x2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2);
L_800F9618:
    // 0x800F9618: lh          $s4, 0x2($a0)
    ctx->r20 = MEM_H(ctx->r4, 0X2);
    // 0x800F961C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800F9620: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9624: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F9628: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800F962C: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800F9630: mflo        $t3
    ctx->r11 = lo;
    // 0x800F9634: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x800F9638: lh          $s5, 0x2($t4)
    ctx->r21 = MEM_H(ctx->r12, 0X2);
    // 0x800F963C: jal         0x800F39F0
    // 0x800F9640: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    mpCollisionGetLineDistanceFC(rdram, ctx);
        goto after_0;
    // 0x800F9640: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    after_0:
    // 0x800F9644: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x800F9648: sub.s       $f2, $f0, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f24.fl;
    // 0x800F964C: bc1f        L_800F9710
    if (!c1cs) {
        // 0x800F9650: mov.s       $f22, $f2
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
            goto L_800F9710;
    }
    // 0x800F9650: mov.s       $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    ctx->f22.fl = ctx->f2.fl;
    // 0x800F9654: c.lt.s      $f2, $f28
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f2.fl < ctx->f28.fl;
    // 0x800F9658: lw          $t5, 0x84($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X84);
    // 0x800F965C: bc1fl       L_800F9670
    if (!c1cs) {
        // 0x800F9660: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_800F9670;
    }
    goto skip_12;
    // 0x800F9660: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_12:
    // 0x800F9664: b           L_800F9670
    // 0x800F9668: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
        goto L_800F9670;
    // 0x800F9668: neg.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = -ctx->f2.fl;
    // 0x800F966C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800F9670:
    // 0x800F9670: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x800F9674: nop

    // 0x800F9678: bc1fl       L_800F9714
    if (!c1cs) {
        // 0x800F967C: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F9714;
    }
    goto skip_13;
    // 0x800F967C: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_13:
    // 0x800F9680: beq         $t5, $zero, L_800F968C
    if (ctx->r13 == 0) {
        // 0x800F9684: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_800F968C;
    }
    // 0x800F9684: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F9688: sw          $s6, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r22;
L_800F968C:
    // 0x800F968C: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x800F9690: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800F9694: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x800F9698: beq         $t6, $zero, L_800F96A4
    if (ctx->r14 == 0) {
        // 0x800F969C: or          $a3, $s0, $zero
        ctx->r7 = ctx->r16 | 0;
            goto L_800F96A4;
    }
    // 0x800F969C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800F96A0: swc1        $f2, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f2.u32l;
L_800F96A4:
    // 0x800F96A4: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800F96A8: beql        $t9, $zero, L_800F96DC
    if (ctx->r25 == 0) {
        // 0x800F96AC: lw          $t6, 0x90($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X90);
            goto L_800F96DC;
    }
    goto skip_14;
    // 0x800F96AC: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    skip_14:
    // 0x800F96B0: lw          $t1, 0x1374($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1374);
    // 0x800F96B4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F96B8: lw          $t8, 0x1370($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1370);
    // 0x800F96BC: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x800F96C0: lhu         $t7, 0x0($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0X0);
    // 0x800F96C4: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F96C8: mflo        $t3
    ctx->r11 = lo;
    // 0x800F96CC: addu        $t4, $t8, $t3
    ctx->r12 = ADD32(ctx->r24, ctx->r11);
    // 0x800F96D0: lhu         $t5, 0x4($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X4);
    // 0x800F96D4: sw          $t5, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r13;
    // 0x800F96D8: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
L_800F96DC:
    // 0x800F96DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800F96E0: beq         $t6, $zero, L_800F96F4
    if (ctx->r14 == 0) {
        // 0x800F96E4: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800F96F4;
    }
    // 0x800F96E4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800F96E8: sw          $s5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r21;
    // 0x800F96EC: jal         0x800F46D0
    // 0x800F96F0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    mpCollisionGetFCAngle(rdram, ctx);
        goto after_1;
    // 0x800F96F0: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    after_1:
L_800F96F4:
    // 0x800F96F4: c.lt.s      $f22, $f28
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f22.fl < ctx->f28.fl;
    // 0x800F96F8: nop

    // 0x800F96FC: bc1fl       L_800F9710
    if (!c1cs) {
        // 0x800F9700: mov.s       $f26, $f22
        CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
            goto L_800F9710;
    }
    goto skip_15;
    // 0x800F9700: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
    skip_15:
    // 0x800F9704: b           L_800F9710
    // 0x800F9708: neg.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = -ctx->f22.fl;
        goto L_800F9710;
    // 0x800F9708: neg.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f26.fl = -ctx->f22.fl;
    // 0x800F970C: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
L_800F9710:
    // 0x800F9710: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
L_800F9714:
    // 0x800F9714: lhu         $t7, 0x2($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X2);
    // 0x800F9718: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800F971C: addiu       $s7, $s7, 0xA
    ctx->r23 = ADD32(ctx->r23, 0XA);
    // 0x800F9720: addu        $t8, $t2, $t7
    ctx->r24 = ADD32(ctx->r10, ctx->r15);
    // 0x800F9724: slt         $at, $s6, $t8
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800F9728: bne         $at, $zero, L_800F9464
    if (ctx->r1 != 0) {
        // 0x800F972C: nop
    
            goto L_800F9464;
    }
    // 0x800F972C: nop

    // 0x800F9730: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800F9734: lw          $t3, 0x1368($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1368);
    // 0x800F9738: lhu         $t0, 0x0($t3)
    ctx->r8 = MEM_HU(ctx->r11, 0X0);
L_800F973C:
    // 0x800F973C: lw          $t4, 0x70($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X70);
L_800F9740:
    // 0x800F9740: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800F9744: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800F9748: slt         $at, $t5, $t0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800F974C: addiu       $t6, $t9, 0x12
    ctx->r14 = ADD32(ctx->r25, 0X12);
    // 0x800F9750: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x800F9754: bne         $at, $zero, L_800F93C8
    if (ctx->r1 != 0) {
        // 0x800F9758: sw          $t5, 0x70($sp)
        MEM_W(0X70, ctx->r29) = ctx->r13;
            goto L_800F93C8;
    }
    // 0x800F9758: sw          $t5, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r13;
L_800F975C:
    // 0x800F975C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F9760: lwc1        $f8, 0x8F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X8F0);
    // 0x800F9764: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800F9768: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800F976C: c.eq.s      $f26, $f8
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f26.fl == ctx->f8.fl;
    // 0x800F9770: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x800F9774: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800F9778: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x800F977C: bc1f        L_800F978C
    if (!c1cs) {
        // 0x800F9780: lw          $s0, 0x48($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X48);
            goto L_800F978C;
    }
    // 0x800F9780: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x800F9784: b           L_800F9790
    // 0x800F9788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F9790;
    // 0x800F9788: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F978C:
    // 0x800F978C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F9790:
    // 0x800F9790: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x800F9794: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x800F9798: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x800F979C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x800F97A0: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x800F97A4: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x800F97A8: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x800F97AC: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x800F97B0: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x800F97B4: jr          $ra
    // 0x800F97B8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800F97B8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void gcAddAnimAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BED8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000BEDC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000BEE0: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8000BEE4: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8000BEE8: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8000BEEC: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8000BEF0: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8000BEF4: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8000BEF8: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x8000BEFC: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8000BF00: lw          $s2, 0x74($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X74);
    // 0x8000BF04: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8000BF08: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x8000BF0C: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8000BF10: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x8000BF14: beq         $s2, $zero, L_8000BFBC
    if (ctx->r18 == 0) {
        // 0x8000BF18: swc1        $f20, 0x78($a0)
        MEM_W(0X78, ctx->r4) = ctx->f20.u32l;
            goto L_8000BFBC;
    }
    // 0x8000BF18: swc1        $f20, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f20.u32l;
    // 0x8000BF1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000BF20: lwc1        $f22, -0x2224($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X2224);
L_8000BF24:
    // 0x8000BF24: beq         $s3, $zero, L_8000BF5C
    if (ctx->r19 == 0) {
        // 0x8000BF28: nop
    
            goto L_8000BF5C;
    }
    // 0x8000BF28: nop

    // 0x8000BF2C: lw          $a1, 0x0($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X0);
    // 0x8000BF30: beql        $a1, $zero, L_8000BF54
    if (ctx->r5 == 0) {
        // 0x8000BF34: swc1        $f22, 0x74($s2)
        MEM_W(0X74, ctx->r18) = ctx->f22.u32l;
            goto L_8000BF54;
    }
    goto skip_0;
    // 0x8000BF34: swc1        $f22, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f22.u32l;
    skip_0:
    // 0x8000BF38: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8000BF3C: jal         0x8000BD1C
    // 0x8000BF40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8000BF40: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8000BF44: sb          $s5, 0x55($s2)
    MEM_B(0X55, ctx->r18) = ctx->r21;
    // 0x8000BF48: b           L_8000BF58
    // 0x8000BF4C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
        goto L_8000BF58;
    // 0x8000BF4C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000BF50: swc1        $f22, 0x74($s2)
    MEM_W(0X74, ctx->r18) = ctx->f22.u32l;
L_8000BF54:
    // 0x8000BF54: sb          $zero, 0x55($s2)
    MEM_B(0X55, ctx->r18) = 0;
L_8000BF58:
    // 0x8000BF58: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8000BF5C:
    // 0x8000BF5C: beq         $s4, $zero, L_8000BFAC
    if (ctx->r20 == 0) {
        // 0x8000BF60: nop
    
            goto L_8000BFAC;
    }
    // 0x8000BF60: nop

    // 0x8000BF64: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000BF68: beql        $v0, $zero, L_8000BFAC
    if (ctx->r2 == 0) {
        // 0x8000BF6C: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_8000BFAC;
    }
    goto skip_1;
    // 0x8000BF6C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_1:
    // 0x8000BF70: lw          $s0, 0x80($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X80);
    // 0x8000BF74: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000BF78: beql        $s0, $zero, L_8000BFAC
    if (ctx->r16 == 0) {
        // 0x8000BF7C: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_8000BFAC;
    }
    goto skip_2;
    // 0x8000BF7C: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_2:
    // 0x8000BF80: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
L_8000BF84:
    // 0x8000BF84: beql        $a1, $zero, L_8000BF9C
    if (ctx->r5 == 0) {
        // 0x8000BF88: lw          $s0, 0x0($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X0);
            goto L_8000BF9C;
    }
    goto skip_3;
    // 0x8000BF88: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x8000BF8C: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8000BF90: jal         0x8000BD54
    // 0x8000BF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8000BF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8000BF98: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
L_8000BF9C:
    // 0x8000BF9C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000BFA0: bnel        $s0, $zero, L_8000BF84
    if (ctx->r16 != 0) {
        // 0x8000BFA4: lw          $a1, 0x0($s1)
        ctx->r5 = MEM_W(ctx->r17, 0X0);
            goto L_8000BF84;
    }
    goto skip_4;
    // 0x8000BFA4: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    skip_4:
    // 0x8000BFA8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_8000BFAC:
    // 0x8000BFAC: jal         0x8000BAA0
    // 0x8000BFB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_2;
    // 0x8000BFB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8000BFB4: bne         $v0, $zero, L_8000BF24
    if (ctx->r2 != 0) {
        // 0x8000BFB8: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000BF24;
    }
    // 0x8000BFB8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8000BFBC:
    // 0x8000BFBC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000BFC0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8000BFC4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x8000BFC8: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8000BFCC: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8000BFD0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8000BFD4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8000BFD8: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8000BFDC: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8000BFE0: jr          $ra
    // 0x8000BFE4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8000BFE4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftPikachuSpecialLwProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015225C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152260: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x80152264: bnel        $v1, $zero, L_8015227C
    if (ctx->r3 != 0) {
        // 0x80152268: lw          $t8, 0xADC($v0)
        ctx->r24 = MEM_W(ctx->r2, 0XADC);
            goto L_8015227C;
    }
    goto skip_0;
    // 0x80152268: lw          $t8, 0xADC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XADC);
    skip_0:
    // 0x8015226C: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x80152270: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80152274: sw          $t7, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = ctx->r15;
    // 0x80152278: lw          $t8, 0xADC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XADC);
L_8015227C:
    // 0x8015227C: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80152280: bne         $t9, $zero, L_80152294
    if (ctx->r25 != 0) {
        // 0x80152284: nop
    
            goto L_80152294;
    }
    // 0x80152284: nop

    // 0x80152288: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x8015228C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80152290: sw          $t0, 0x29C($v0)
    MEM_W(0X29C, ctx->r2) = ctx->r8;
L_80152294:
    // 0x80152294: jr          $ra
    // 0x80152298: nop

    return;
    // 0x80152298: nop

;}
RECOMP_FUNC void itMSBombWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801764A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801764AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801764B0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801764B4: jal         0x801735A0
    // 0x801764B8: addiu       $a1, $a1, 0x6538
    ctx->r5 = ADD32(ctx->r5, 0X6538);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x801764B8: addiu       $a1, $a1, 0x6538
    ctx->r5 = ADD32(ctx->r5, 0X6538);
    after_0:
    // 0x801764BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801764C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801764C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801764C8: jr          $ra
    // 0x801764CC: nop

    return;
    // 0x801764CC: nop

;}
RECOMP_FUNC void func_ovl59_8013202C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013202C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132030: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132034: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80132038: lw          $s0, 0x66F8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66F8);
    // 0x8013203C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132040: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80132044: bne         $s0, $zero, L_801320D4
    if (ctx->r16 != 0) {
        // 0x80132048: lw          $v0, 0x84($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X84);
            goto L_801320D4;
    }
    // 0x80132048: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013204C: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x80132050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132054: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132058: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013205C: jal         0x80009968
    // 0x80132060: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132060: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_0:
    // 0x80132064: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132068: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8013206C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132070: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80132074: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80132078: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013207C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132080: jal         0x80009DF4
    // 0x80132084: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132084: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132088: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013208C: lw          $a1, -0x5718($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5718);
    // 0x80132090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132094: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132098: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x8013209C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801320A0: jal         0x8000F590
    // 0x801320A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    gcSetupCustomDObjs(rdram, ctx);
        goto after_2;
    // 0x801320A4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_2:
    // 0x801320A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801320AC: addiu       $a1, $a1, 0x1F34
    ctx->r5 = ADD32(ctx->r5, 0X1F34);
    // 0x801320B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801320B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801320B8: jal         0x80008188
    // 0x801320BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x801320BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x801320C0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x801320C4: sw          $t8, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r24;
    // 0x801320C8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x801320CC: b           L_801320E0
    // 0x801320D0: sw          $s0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r16;
        goto L_801320E0;
    // 0x801320D0: sw          $s0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r16;
L_801320D4:
    // 0x801320D4: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x801320D8: sw          $t0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r8;
    // 0x801320DC: sw          $s0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r16;
L_801320E0:
    // 0x801320E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801320E4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801320E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801320EC: jr          $ra
    // 0x801320F0: nop

    return;
    // 0x801320F0: nop

;}
RECOMP_FUNC void func_ovl8_80381090(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381090: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80381094: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80381098: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038109C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803810A0: beq         $a0, $zero, L_80381118
    if (ctx->r4 == 0) {
        // 0x803810A4: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80381118;
    }
    // 0x803810A4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803810A8: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x803810AC: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803810B0: addiu       $t6, $t6, -0x4630
    ctx->r14 = ADD32(ctx->r14, -0X4630);
    // 0x803810B4: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x803810B8: addiu       $t7, $t7, -0x4550
    ctx->r15 = ADD32(ctx->r15, -0X4550);
    // 0x803810BC: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x803810C0: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x803810C4: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x803810C8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803810CC: addiu       $t9, $t9, -0x43F8
    ctx->r25 = ADD32(ctx->r25, -0X43F8);
    // 0x803810D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803810D4: jal         0x8037F4F4
    // 0x803810D8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_8037F4F4(rdram, ctx);
        goto after_0;
    // 0x803810D8: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x803810DC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x803810E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803810E4: beql        $t1, $zero, L_80381104
    if (ctx->r9 == 0) {
        // 0x803810E8: lw          $t2, 0x24($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X24);
            goto L_80381104;
    }
    goto skip_0;
    // 0x803810E8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x803810EC: jal         0x8037C30C
    // 0x803810F0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_1;
    // 0x803810F0: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_1:
    // 0x803810F4: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x803810F8: jal         0x803718C4
    // 0x803810FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_2;
    // 0x803810FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80381100: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
L_80381104:
    // 0x80381104: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x80381108: beql        $t3, $zero, L_8038111C
    if (ctx->r11 == 0) {
        // 0x8038110C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8038111C;
    }
    goto skip_1;
    // 0x8038110C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80381110: jal         0x803717C0
    // 0x80381114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_3;
    // 0x80381114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80381118:
    // 0x80381118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8038111C:
    // 0x8038111C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80381120: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80381124: jr          $ra
    // 0x80381128: nop

    return;
    // 0x80381128: nop

;}
RECOMP_FUNC void mnPlayersVSPuckAdjustOverlap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139320: addiu       $t0, $zero, 0xBC
    ctx->r8 = ADD32(0, 0XBC);
    // 0x80139324: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80139328: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x8013932C: addiu       $v0, $v0, -0x4578
    ctx->r2 = ADD32(ctx->r2, -0X4578);
    // 0x80139330: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80139334: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80139338: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013933C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80139340: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80139344: mflo        $t6
    ctx->r14 = lo;
    // 0x80139348: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x8013934C: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x80139350: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80139354: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x80139358: lwc1        $f0, 0x58($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X58);
    // 0x8013935C: mflo        $t8
    ctx->r24 = lo;
    // 0x80139360: addu        $a3, $v0, $t8
    ctx->r7 = ADD32(ctx->r2, ctx->r24);
    // 0x80139364: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x80139368: lw          $t1, 0x74($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X74);
    // 0x8013936C: lwc1        $f2, 0x58($t1)
    ctx->f2.u32l = MEM_W(ctx->r9, 0X58);
    // 0x80139370: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x80139374: nop

    // 0x80139378: bc1fl       L_801393B8
    if (!c1cs) {
        // 0x8013937C: sub.s       $f18, $f2, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_801393B8;
    }
    goto skip_0;
    // 0x8013937C: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
    skip_0:
    // 0x80139380: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80139384: jal         0x80018994
    // 0x80139388: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x80139388: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x8013938C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80139390: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80139394: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80139398: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8013939C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801393A0: lwc1        $f4, 0x90($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X90);
    // 0x801393A4: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    // 0x801393A8: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x801393AC: b           L_801393D8
    // 0x801393B0: swc1        $f10, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f10.u32l;
        goto L_801393D8;
    // 0x801393B0: swc1        $f10, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f10.u32l;
    // 0x801393B4: sub.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl - ctx->f0.fl;
L_801393B8:
    // 0x801393B8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801393BC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801393C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801393C4: mul.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x801393C8: lwc1        $f10, 0x90($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X90);
    // 0x801393CC: div.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f4.fl);
    // 0x801393D0: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801393D4: swc1        $f16, 0x90($v1)
    MEM_W(0X90, ctx->r3) = ctx->f16.u32l;
L_801393D8:
    // 0x801393D8: lw          $t4, 0x4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4);
    // 0x801393DC: lw          $t3, 0x74($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X74);
    // 0x801393E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x801393E4: lw          $t5, 0x74($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X74);
    // 0x801393E8: lwc1        $f0, 0x5C($t3)
    ctx->f0.u32l = MEM_W(ctx->r11, 0X5C);
    // 0x801393EC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801393F0: lwc1        $f2, 0x5C($t5)
    ctx->f2.u32l = MEM_W(ctx->r13, 0X5C);
    // 0x801393F4: c.eq.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl == ctx->f2.fl;
    // 0x801393F8: nop

    // 0x801393FC: bc1fl       L_80139430
    if (!c1cs) {
        // 0x80139400: sub.s       $f16, $f2, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
            goto L_80139430;
    }
    goto skip_1;
    // 0x80139400: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    skip_1:
    // 0x80139404: jal         0x80018994
    // 0x80139408: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80139408: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x8013940C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80139410: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80139414: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80139418: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013941C: lwc1        $f18, 0x94($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X94);
    // 0x80139420: add.s       $f10, $f18, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80139424: b           L_80139450
    // 0x80139428: swc1        $f10, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f10.u32l;
        goto L_80139450;
    // 0x80139428: swc1        $f10, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f10.u32l;
    // 0x8013942C: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
L_80139430:
    // 0x80139430: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80139434: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80139438: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013943C: mul.s       $f6, $f8, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80139440: lwc1        $f10, 0x94($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X94);
    // 0x80139444: div.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80139448: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8013944C: swc1        $f8, 0x94($v1)
    MEM_W(0X94, ctx->r3) = ctx->f8.u32l;
L_80139450:
    // 0x80139450: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80139454: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80139458: jr          $ra
    // 0x8013945C: nop

    return;
    // 0x8013945C: nop

;}
RECOMP_FUNC void ftKirbySpecialNInitPassiveVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161EB4: lw          $v0, 0xADC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XADC);
    // 0x80161EB8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80161EBC: beq         $v0, $at, L_80161EF0
    if (ctx->r2 == ctx->r1) {
        // 0x80161EC0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80161EF0;
    }
    // 0x80161EC0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80161EC4: beq         $v0, $at, L_80161EE4
    if (ctx->r2 == ctx->r1) {
        // 0x80161EC8: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80161EE4;
    }
    // 0x80161EC8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80161ECC: beq         $v0, $at, L_80161EF8
    if (ctx->r2 == ctx->r1) {
        // 0x80161ED0: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_80161EF8;
    }
    // 0x80161ED0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80161ED4: beql        $v0, $at, L_80161F04
    if (ctx->r2 == ctx->r1) {
        // 0x80161ED8: sw          $zero, 0xAF0($a0)
        MEM_W(0XAF0, ctx->r4) = 0;
            goto L_80161F04;
    }
    goto skip_0;
    // 0x80161ED8: sw          $zero, 0xAF0($a0)
    MEM_W(0XAF0, ctx->r4) = 0;
    skip_0:
    // 0x80161EDC: jr          $ra
    // 0x80161EE0: nop

    return;
    // 0x80161EE0: nop

L_80161EE4:
    // 0x80161EE4: sw          $zero, 0xAE0($a0)
    MEM_W(0XAE0, ctx->r4) = 0;
    // 0x80161EE8: jr          $ra
    // 0x80161EEC: sw          $zero, 0xAE4($a0)
    MEM_W(0XAE4, ctx->r4) = 0;
    return;
    // 0x80161EEC: sw          $zero, 0xAE4($a0)
    MEM_W(0XAE4, ctx->r4) = 0;
L_80161EF0:
    // 0x80161EF0: jr          $ra
    // 0x80161EF4: sw          $zero, 0xAE8($a0)
    MEM_W(0XAE8, ctx->r4) = 0;
    return;
    // 0x80161EF4: sw          $zero, 0xAE8($a0)
    MEM_W(0XAE8, ctx->r4) = 0;
L_80161EF8:
    // 0x80161EF8: jr          $ra
    // 0x80161EFC: sw          $zero, 0xAEC($a0)
    MEM_W(0XAEC, ctx->r4) = 0;
    return;
    // 0x80161EFC: sw          $zero, 0xAEC($a0)
    MEM_W(0XAEC, ctx->r4) = 0;
    // 0x80161F00: sw          $zero, 0xAF0($a0)
    MEM_W(0XAF0, ctx->r4) = 0;
L_80161F04:
    // 0x80161F04: jr          $ra
    // 0x80161F08: nop

    return;
    // 0x80161F08: nop

;}
RECOMP_FUNC void gmCollisionCheckWeaponAttackItemDamageCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F079C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800F07A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800F07A4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800F07A8: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800F07AC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800F07B0: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x800F07B4: lw          $t7, 0x74($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X74);
    // 0x800F07B8: lwc1        $f6, 0x8($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800F07BC: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x800F07C0: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x800F07C4: or          $t6, $a3, $zero
    ctx->r14 = ctx->r7 | 0;
    // 0x800F07C8: or          $t8, $a2, $zero
    ctx->r24 = ctx->r6 | 0;
    // 0x800F07CC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F07D0: addiu       $t5, $t8, 0x14
    ctx->r13 = ADD32(ctx->r24, 0X14);
    // 0x800F07D4: addiu       $t4, $sp, 0x2C
    ctx->r12 = ADD32(ctx->r29, 0X2C);
    // 0x800F07D8: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800F07DC: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800F07E0: lw          $t9, 0x74($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X74);
    // 0x800F07E4: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800F07E8: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800F07EC: lwc1        $f10, 0x20($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X20);
    // 0x800F07F0: sll         $t3, $t3, 5
    ctx->r11 = S32(ctx->r11 << 5);
    // 0x800F07F4: addu        $v0, $a0, $t3
    ctx->r2 = ADD32(ctx->r4, ctx->r11);
    // 0x800F07F8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F07FC: addiu       $a0, $v0, 0x54
    ctx->r4 = ADD32(ctx->r2, 0X54);
    // 0x800F0800: addiu       $a1, $v0, 0x60
    ctx->r5 = ADD32(ctx->r2, 0X60);
    // 0x800F0804: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x800F0808: lw          $t0, 0x74($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X74);
    // 0x800F080C: lwc1        $f6, 0x10($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800F0810: lwc1        $f4, 0x24($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X24);
    // 0x800F0814: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0818: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x800F081C: lw          $a3, 0x0($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X0);
    // 0x800F0820: lw          $a2, 0x28($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X28);
    // 0x800F0824: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    // 0x800F0828: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800F082C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800F0830: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x800F0834: addiu       $t9, $t7, 0x40
    ctx->r25 = ADD32(ctx->r15, 0X40);
    // 0x800F0838: jal         0x800EE300
    // 0x800F083C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    gmCollisionTestRectangle(rdram, ctx);
        goto after_0;
    // 0x800F083C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    after_0:
    // 0x800F0840: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800F0844: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800F0848: jr          $ra
    // 0x800F084C: nop

    return;
    // 0x800F084C: nop

;}
RECOMP_FUNC void ifCommonPlayerDamageInitInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F3C0: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8010F3C4: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8010F3C8: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8010F3CC: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8010F3D0: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8010F3D4: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8010F3D8: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8010F3DC: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8010F3E0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8010F3E4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8010F3E8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8010F3EC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8010F3F0: jal         0x8010F334
    // 0x8010F3F4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    ifCommonPlayerDamageSetDigitAttr(rdram, ctx);
        goto after_0;
    // 0x8010F3F4: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    after_0:
    // 0x8010F3F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010F3FC: lwc1        $f22, 0xC64($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0XC64);
    // 0x8010F400: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010F404: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010F408: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8010F40C: addiu       $s0, $s0, 0x1598
    ctx->r16 = ADD32(ctx->r16, 0X1598);
    // 0x8010F410: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8010F414: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8010F418:
    // 0x8010F418: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8010F41C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8010F420: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8010F424: addu        $t7, $t6, $s5
    ctx->r15 = ADD32(ctx->r14, ctx->r21);
    // 0x8010F428: lbu         $t8, 0x22($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X22);
    // 0x8010F42C: bne         $t8, $at, L_8010F43C
    if (ctx->r24 != ctx->r1) {
        // 0x8010F430: nop
    
            goto L_8010F43C;
    }
    // 0x8010F430: nop

    // 0x8010F434: b           L_8010F720
    // 0x8010F438: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
        goto L_8010F720;
    // 0x8010F438: sw          $zero, 0x60($s0)
    MEM_W(0X60, ctx->r16) = 0;
L_8010F43C:
    // 0x8010F43C: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x8010F440: addiu       $t3, $t3, -0x11E8
    ctx->r11 = ADD32(ctx->r11, -0X11E8);
    // 0x8010F444: lui         $s2, 0x8011
    ctx->r18 = S32(0X8011 << 16);
    // 0x8010F448: lui         $s4, 0x0
    ctx->r20 = S32(0X0 << 16);
    // 0x8010F44C: addiu       $t9, $s0, 0x10
    ctx->r25 = ADD32(ctx->r16, 0X10);
    // 0x8010F450: addiu       $t0, $s0, 0x24
    ctx->r8 = ADD32(ctx->r16, 0X24);
    // 0x8010F454: addiu       $t1, $s0, 0x38
    ctx->r9 = ADD32(ctx->r16, 0X38);
    // 0x8010F458: addiu       $t2, $s0, 0x4C
    ctx->r10 = ADD32(ctx->r16, 0X4C);
    // 0x8010F45C: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8010F460: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x8010F464: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x8010F468: sw          $t9, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r25;
    // 0x8010F46C: addiu       $s4, $s4, 0x148
    ctx->r20 = ADD32(ctx->r20, 0X148);
    // 0x8010F470: addiu       $s2, $s2, -0x1104
    ctx->r18 = ADD32(ctx->r18, -0X1104);
    // 0x8010F474: sw          $t3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r11;
    // 0x8010F478: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8010F47C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010F480: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8010F484: jal         0x80009968
    // 0x8010F488: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8010F488: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8010F48C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8010F490: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8010F494: sw          $v0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r2;
    // 0x8010F498: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8010F49C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010F4A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8010F4A4: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8010F4A8: jal         0x80009DF4
    // 0x8010F4AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x8010F4AC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x8010F4B0: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8010F4B4: lw          $t5, 0x50E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X50E8);
    // 0x8010F4B8: addu        $t6, $t5, $s5
    ctx->r14 = ADD32(ctx->r13, ctx->r21);
    // 0x8010F4BC: lw          $t7, 0x78($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X78);
    // 0x8010F4C0: lw          $v0, 0x84($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X84);
    // 0x8010F4C4: lw          $t8, 0x9C8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X9C8);
    // 0x8010F4C8: lw          $v1, 0x340($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X340);
    // 0x8010F4CC: beql        $v1, $zero, L_8010F650
    if (ctx->r3 == 0) {
        // 0x8010F4D0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8010F650;
    }
    goto skip_0;
    // 0x8010F4D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
    // 0x8010F4D4: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x8010F4D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010F4DC: sll         $s2, $fp, 2
    ctx->r18 = S32(ctx->r30 << 2);
    // 0x8010F4E0: beq         $a1, $zero, L_8010F64C
    if (ctx->r5 == 0) {
        // 0x8010F4E4: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_8010F64C;
    }
    // 0x8010F4E4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8010F4E8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8010F4EC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8010F4F0: addiu       $t1, $t1, -0x1398
    ctx->r9 = ADD32(ctx->r9, -0X1398);
    // 0x8010F4F4: addiu       $t0, $t0, -0x1388
    ctx->r8 = ADD32(ctx->r8, -0X1388);
    // 0x8010F4F8: addiu       $t9, $t9, -0x13A8
    ctx->r25 = ADD32(ctx->r25, -0X13A8);
    // 0x8010F4FC: addu        $s6, $s2, $t9
    ctx->r22 = ADD32(ctx->r18, ctx->r25);
    // 0x8010F500: addu        $s3, $s2, $t0
    ctx->r19 = ADD32(ctx->r18, ctx->r8);
    // 0x8010F504: jal         0x800CCFDC
    // 0x8010F508: addu        $s7, $s2, $t1
    ctx->r23 = ADD32(ctx->r18, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8010F508: addu        $s7, $s2, $t1
    ctx->r23 = ADD32(ctx->r18, ctx->r9);
    after_3:
    // 0x8010F50C: lh          $t2, 0x14($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X14);
    // 0x8010F510: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8010F514: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8010F518: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8010F51C: addiu       $a2, $a2, 0x1580
    ctx->r6 = ADD32(ctx->r6, 0X1580);
    // 0x8010F520: lw          $t3, 0x8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8);
    // 0x8010F524: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010F528: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x8010F52C: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x8010F530: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8010F534: lh          $t9, 0x16($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X16);
    // 0x8010F538: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010F53C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010F540: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x8010F544: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8010F548: addiu       $a1, $a1, 0x1300
    ctx->r5 = ADD32(ctx->r5, 0X1300);
    // 0x8010F54C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8010F550: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8010F554: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x8010F558: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010F55C: sub.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8010F560: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8010F564: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8010F568: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8010F56C: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010F570: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8010F574: nop

    // 0x8010F578: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8010F57C: nop

    // 0x8010F580: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010F584: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8010F588: lwc1        $f18, 0x0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8010F58C: lhu         $t0, 0xC($a2)
    ctx->r8 = MEM_HU(ctx->r6, 0XC);
    // 0x8010F590: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x8010F594: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8010F598: nop

    // 0x8010F59C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8010F5A0: mul.s       $f16, $f4, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x8010F5A4: bgezl       $t0, L_8010F5BC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8010F5A8: lw          $t1, 0x0($s7)
        ctx->r9 = MEM_W(ctx->r23, 0X0);
            goto L_8010F5BC;
    }
    goto skip_1;
    // 0x8010F5A8: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
    skip_1:
    // 0x8010F5AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010F5B0: nop

    // 0x8010F5B4: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x8010F5B8: lw          $t1, 0x0($s7)
    ctx->r9 = MEM_W(ctx->r23, 0X0);
L_8010F5BC:
    // 0x8010F5BC: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8010F5C0: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8010F5C4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8010F5C8: nop

    // 0x8010F5CC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010F5D0: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x8010F5D4: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8010F5D8: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x8010F5DC: nop

    // 0x8010F5E0: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8010F5E4: nop

    // 0x8010F5E8: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010F5EC: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    // 0x8010F5F0: lwc1        $f0, 0x0($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X0);
    // 0x8010F5F4: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8010F5F8: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x8010F5FC: lw          $t4, 0x50E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50E8);
    // 0x8010F600: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8010F604: addu        $t5, $t4, $s5
    ctx->r13 = ADD32(ctx->r12, ctx->r21);
    // 0x8010F608: lbu         $a0, 0x28($t5)
    ctx->r4 = MEM_BU(ctx->r13, 0X28);
    // 0x8010F60C: addiu       $t5, $zero, 0x201
    ctx->r13 = ADD32(0, 0X201);
    // 0x8010F610: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8010F614: subu        $v1, $v1, $a0
    ctx->r3 = SUB32(ctx->r3, ctx->r4);
    // 0x8010F618: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8010F61C: lbu         $t8, 0x50($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X50);
    // 0x8010F620: sb          $t8, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r24;
    // 0x8010F624: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8010F628: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8010F62C: lbu         $t1, 0x51($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X51);
    // 0x8010F630: sb          $t1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r9;
    // 0x8010F634: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8010F638: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8010F63C: lbu         $t4, 0x52($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X52);
    // 0x8010F640: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x8010F644: b           L_8010F660
    // 0x8010F648: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
        goto L_8010F660;
    // 0x8010F648: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
L_8010F64C:
    // 0x8010F64C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8010F650:
    // 0x8010F650: jal         0x80009614
    // 0x8010F654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcAddSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8010F654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8010F658: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8010F65C: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
L_8010F660:
    // 0x8010F660: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010F664: lw          $t7, 0xD48($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD48);
    // 0x8010F668: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010F66C: jal         0x800CCFDC
    // 0x8010F670: addu        $a1, $t7, $s4
    ctx->r5 = ADD32(ctx->r15, ctx->r20);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8010F670: addu        $a1, $t7, $s4
    ctx->r5 = ADD32(ctx->r15, ctx->r20);
    after_5:
    // 0x8010F674: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8010F678: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8010F67C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010F680: sw          $t8, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r24;
    // 0x8010F684: lw          $t9, 0xD48($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD48);
    // 0x8010F688: jal         0x800CCFDC
    // 0x8010F68C: addu        $a1, $t9, $s4
    ctx->r5 = ADD32(ctx->r25, ctx->r20);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x8010F68C: addu        $a1, $t9, $s4
    ctx->r5 = ADD32(ctx->r25, ctx->r20);
    after_6:
    // 0x8010F690: lw          $t0, 0x68($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X68);
    // 0x8010F694: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8010F698: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010F69C: sw          $t0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r8;
    // 0x8010F6A0: lw          $t1, 0xD48($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD48);
    // 0x8010F6A4: jal         0x800CCFDC
    // 0x8010F6A8: addu        $a1, $t1, $s4
    ctx->r5 = ADD32(ctx->r9, ctx->r20);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x8010F6A8: addu        $a1, $t1, $s4
    ctx->r5 = ADD32(ctx->r9, ctx->r20);
    after_7:
    // 0x8010F6AC: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8010F6B0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8010F6B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010F6B8: sw          $t2, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r10;
    // 0x8010F6BC: lw          $t3, 0xD48($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD48);
    // 0x8010F6C0: jal         0x800CCFDC
    // 0x8010F6C4: addu        $a1, $t3, $s4
    ctx->r5 = ADD32(ctx->r11, ctx->r20);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_8;
    // 0x8010F6C4: addu        $a1, $t3, $s4
    ctx->r5 = ADD32(ctx->r11, ctx->r20);
    after_8:
    // 0x8010F6C8: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8010F6CC: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8010F6D0: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x8010F6D4: sw          $t4, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r12;
    // 0x8010F6D8: lw          $t5, 0x50E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X50E8);
    // 0x8010F6DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010F6E0: addu        $t6, $t5, $s5
    ctx->r14 = ADD32(ctx->r13, ctx->r21);
    // 0x8010F6E4: lw          $t7, 0x6C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X6C);
    // 0x8010F6E8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8010F6EC: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8010F6F0: swc1        $f22, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f22.u32l;
    // 0x8010F6F4: sb          $zero, 0x65($s0)
    MEM_B(0X65, ctx->r16) = 0;
    // 0x8010F6F8: sb          $t8, 0x68($s0)
    MEM_B(0X68, ctx->r16) = ctx->r24;
    // 0x8010F6FC: sb          $zero, 0x69($s0)
    MEM_B(0X69, ctx->r16) = 0;
    // 0x8010F700: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x8010F704: jal         0x8010EE18
    // 0x8010F708: sw          $fp, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->r30;
    ifCommonPlayerDamageProcUpdate(rdram, ctx);
        goto after_9;
    // 0x8010F708: sw          $fp, 0x84($s1)
    MEM_W(0X84, ctx->r17) = ctx->r30;
    after_9:
    // 0x8010F70C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8010F710: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8010F714: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010F718: jal         0x80008188
    // 0x8010F71C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjProcess(rdram, ctx);
        goto after_10;
    // 0x8010F71C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
L_8010F720:
    // 0x8010F720: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8010F724: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8010F728: addiu       $s5, $s5, 0x74
    ctx->r21 = ADD32(ctx->r21, 0X74);
    // 0x8010F72C: bne         $fp, $at, L_8010F418
    if (ctx->r30 != ctx->r1) {
        // 0x8010F730: addiu       $s0, $s0, 0x6C
        ctx->r16 = ADD32(ctx->r16, 0X6C);
            goto L_8010F418;
    }
    // 0x8010F730: addiu       $s0, $s0, 0x6C
    ctx->r16 = ADD32(ctx->r16, 0X6C);
    // 0x8010F734: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8010F738: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8010F73C: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8010F740: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8010F744: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8010F748: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8010F74C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8010F750: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8010F754: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8010F758: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8010F75C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8010F760: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8010F764: jr          $ra
    // 0x8010F768: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8010F768: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void itBombHeiMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177D9C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80177DA0: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x80177DA4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80177DA8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80177DAC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80177DB0: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80177DB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80177DB8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80177DBC: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x80177DC0: addiu       $a1, $a1, -0x6068
    ctx->r5 = ADD32(ctx->r5, -0X6068);
    // 0x80177DC4: jal         0x8016E174
    // 0x80177DC8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80177DC8: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80177DCC: beq         $v0, $zero, L_80177E6C
    if (ctx->r2 == 0) {
        // 0x80177DD0: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_80177E6C;
    }
    // 0x80177DD0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80177DD4: lw          $v0, 0x74($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X74);
    // 0x80177DD8: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80177DDC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80177DE0: addiu       $v1, $v0, 0x1C
    ctx->r3 = ADD32(ctx->r2, 0X1C);
    // 0x80177DE4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80177DE8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80177DEC: lw          $t7, 0x4($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X4);
    // 0x80177DF0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80177DF4: lw          $t8, 0x8($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X8);
    // 0x80177DF8: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x80177DFC: lw          $s0, 0x84($a3)
    ctx->r16 = MEM_W(ctx->r7, 0X84);
    // 0x80177E00: sh          $zero, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = 0;
    // 0x80177E04: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80177E08: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80177E0C: jal         0x8017279C
    // 0x80177E10: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x80177E10: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    after_1:
    // 0x80177E14: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80177E18: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x80177E1C: jal         0x80008CC0
    // 0x80177E20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80177E20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80177E24: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x80177E28: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80177E2C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80177E30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80177E34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80177E38: sw          $t2, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r10;
    // 0x80177E3C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80177E40: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x80177E44: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80177E48: sw          $t2, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r10;
    // 0x80177E4C: lbu         $t4, 0x2D3($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X2D3);
    // 0x80177E50: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x80177E54: sb          $t5, 0x2D3($s0)
    MEM_B(0X2D3, ctx->r16) = ctx->r13;
    // 0x80177E58: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x80177E5C: jal         0x80111EC0
    // 0x80177E60: swc1        $f4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f4.u32l;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_3;
    // 0x80177E60: swc1        $f4, 0x38($t6)
    MEM_W(0X38, ctx->r14) = ctx->f4.u32l;
    after_3:
    // 0x80177E64: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80177E68: sw          $v0, 0x348($s0)
    MEM_W(0X348, ctx->r16) = ctx->r2;
L_80177E6C:
    // 0x80177E6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80177E70: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80177E74: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80177E78: jr          $ra
    // 0x80177E7C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x80177E7C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
RECOMP_FUNC void mnScreenAdjustMakeGuide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131D50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131D54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131D5C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131D60: jal         0x80009968
    // 0x80131D64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131D64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131D68: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131D6C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131D70: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131D74: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131D78: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131D7C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131D80: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131D84: jal         0x80009DF4
    // 0x80131D88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131D88: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131D8C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131D90: lw          $t7, 0x2A38($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2A38);
    // 0x80131D94: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80131D98: addiu       $t8, $t8, -0x6760
    ctx->r24 = ADD32(ctx->r24, -0X6760);
    // 0x80131D9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131DA0: jal         0x800CCFDC
    // 0x80131DA4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131DA4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131DA8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131DAC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131DB0: nop

    // 0x80131DB4: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131DB8: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80131DBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131DC0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131DC4: jr          $ra
    // 0x80131DC8: nop

    return;
    // 0x80131DC8: nop

;}
RECOMP_FUNC void stringConcat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037709C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803770A0: beq         $a0, $zero, L_803770F8
    if (ctx->r4 == 0) {
        // 0x803770A4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_803770F8;
    }
    // 0x803770A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803770A8: beql        $a1, $zero, L_803770FC
    if (ctx->r5 == 0) {
        // 0x803770AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803770FC;
    }
    goto skip_0;
    // 0x803770AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x803770B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x803770B4: jal         0x80376FBC
    // 0x803770B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    stringLength(rdram, ctx);
        goto after_0;
    // 0x803770B8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x803770BC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x803770C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x803770C4: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x803770C8: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x803770CC: beq         $t6, $zero, L_803770F4
    if (ctx->r14 == 0) {
        // 0x803770D0: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_803770F4;
    }
    // 0x803770D0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_803770D4:
    // 0x803770D4: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x803770D8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x803770DC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x803770E0: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x803770E4: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x803770E8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x803770EC: bnel        $t8, $zero, L_803770D4
    if (ctx->r24 != 0) {
        // 0x803770F0: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_803770D4;
    }
    goto skip_1;
    // 0x803770F0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    skip_1:
L_803770F4:
    // 0x803770F4: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_803770F8:
    // 0x803770F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803770FC:
    // 0x803770FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377100: jr          $ra
    // 0x80377104: nop

    return;
    // 0x80377104: nop

;}
RECOMP_FUNC void sc1PGameBossAdvanceWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801924E0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801924E4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801924E8: lui         $s5, 0x8019
    ctx->r21 = S32(0X8019 << 16);
    // 0x801924EC: addiu       $s5, $s5, 0x38D8
    ctx->r21 = ADD32(ctx->r21, 0X38D8);
    // 0x801924F0: lw          $v0, 0x10($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X10);
    // 0x801924F4: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801924F8: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801924FC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80192500: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80192504: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80192508: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8019250C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80192510: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80192514: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80192518: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8019251C: blez        $t6, L_801925DC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80192520: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_801925DC;
    }
    // 0x80192520: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80192524: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80192528: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x8019252C: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
L_80192530:
    // 0x80192530: bnel        $s6, $t7, L_80192580
    if (ctx->r22 != ctx->r15) {
        // 0x80192534: lw          $t3, 0x2C($v0)
        ctx->r11 = MEM_W(ctx->r2, 0X2C);
            goto L_80192580;
    }
    goto skip_0;
    // 0x80192534: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
    skip_0:
    // 0x80192538: jal         0x80018994
    // 0x8019253C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8019253C: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    after_0:
    // 0x80192540: lw          $t8, 0x10($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X10);
    // 0x80192544: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80192548: jal         0x80018994
    // 0x8019254C: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x8019254C: lw          $a0, 0x8($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X8);
    after_1:
    // 0x80192550: lw          $t9, 0x10($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X10);
    // 0x80192554: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80192558: lw          $t0, 0x2C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X2C);
    // 0x8019255C: addu        $t1, $t0, $s2
    ctx->r9 = ADD32(ctx->r8, ctx->r18);
    // 0x80192560: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80192564: bnel        $s1, $t2, L_801925A8
    if (ctx->r17 != ctx->r10) {
        // 0x80192568: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_801925A8;
    }
    goto skip_1;
    // 0x80192568: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_1:
    // 0x8019256C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80192570: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x80192574: b           L_801925A4
    // 0x80192578: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_801925A4;
    // 0x80192578: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8019257C: lw          $t3, 0x2C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2C);
L_80192580:
    // 0x80192580: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80192584: or          $s4, $s3, $zero
    ctx->r20 = ctx->r19 | 0;
    // 0x80192588: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x8019258C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80192590: bnel        $s1, $t5, L_801925A8
    if (ctx->r17 != ctx->r13) {
        // 0x80192594: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_801925A8;
    }
    goto skip_2;
    // 0x80192594: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_2:
    // 0x80192598: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8019259C: addiu       $s2, $s2, 0x18
    ctx->r18 = ADD32(ctx->r18, 0X18);
    // 0x801925A0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_801925A4:
    // 0x801925A4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_801925A8:
    // 0x801925A8: jal         0x801922D4
    // 0x801925AC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    sc1PGameBossMakeWallpaperEffect(rdram, ctx);
        goto after_2;
    // 0x801925AC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_2:
    // 0x801925B0: beq         $v0, $zero, L_801925C0
    if (ctx->r2 == 0) {
        // 0x801925B4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801925C0;
    }
    // 0x801925B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801925B8: jal         0x8019223C
    // 0x801925BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    sc1PGameBossSetWallpaperTranslate(rdram, ctx);
        goto after_3;
    // 0x801925BC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
L_801925C0:
    // 0x801925C0: lw          $v0, 0x10($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X10);
    // 0x801925C4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801925C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801925CC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x801925D0: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801925D4: bnel        $at, $zero, L_80192530
    if (ctx->r1 != 0) {
        // 0x801925D8: lw          $t7, 0x20($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X20);
            goto L_80192530;
    }
    goto skip_3;
    // 0x801925D8: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    skip_3:
L_801925DC:
    // 0x801925DC: lw          $t7, 0x4($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X4);
    // 0x801925E0: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x801925E4: sw          $s6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r22;
    // 0x801925E8: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x801925EC: sw          $t8, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r24;
    // 0x801925F0: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x801925F4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801925F8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x801925FC: sw          $t9, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r25;
    // 0x80192600: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80192604: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80192608: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8019260C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80192610: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80192614: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80192618: jr          $ra
    // 0x8019261C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8019261C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftSamusSpecialNSetChargeShotPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D394: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015D398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D39C: lw          $t6, 0xB20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XB20);
    // 0x8015D3A0: addiu       $a1, $sp, 0x1C
    ctx->r5 = ADD32(ctx->r29, 0X1C);
    // 0x8015D3A4: beql        $t6, $zero, L_8015D3E0
    if (ctx->r14 == 0) {
        // 0x8015D3A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015D3E0;
    }
    goto skip_0;
    // 0x8015D3A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015D3AC: jal         0x8015D35C
    // 0x8015D3B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftSamusSpecialNGetChargeShotPosition(rdram, ctx);
        goto after_0;
    // 0x8015D3B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015D3B4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015D3B8: addiu       $t9, $sp, 0x1C
    ctx->r25 = ADD32(ctx->r29, 0X1C);
    // 0x8015D3BC: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8015D3C0: lw          $t7, 0xB20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB20);
    // 0x8015D3C4: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x8015D3C8: sw          $t1, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->r9;
    // 0x8015D3CC: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8015D3D0: sw          $t0, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->r8;
    // 0x8015D3D4: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8015D3D8: sw          $t1, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->r9;
    // 0x8015D3DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015D3E0:
    // 0x8015D3E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015D3E4: jr          $ra
    // 0x8015D3E8: nop

    return;
    // 0x8015D3E8: nop

;}
RECOMP_FUNC void ftCommonThrowSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A1E8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8014A1EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014A1F0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014A1F4: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x8014A1F8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014A1FC: lw          $t7, 0x840($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X840);
    // 0x8014A200: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8014A204: lw          $t9, 0x84($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X84);
    // 0x8014A208: bne         $a1, $zero, L_8014A22C
    if (ctx->r5 != 0) {
        // 0x8014A20C: sw          $t9, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r25;
            goto L_8014A22C;
    }
    // 0x8014A20C: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8014A210: lb          $t0, 0x1C2($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1C2);
    // 0x8014A214: lw          $t1, 0x44($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X44);
    // 0x8014A218: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014A21C: addiu       $t0, $zero, 0xAA
    ctx->r8 = ADD32(0, 0XAA);
    // 0x8014A220: mflo        $t2
    ctx->r10 = lo;
    // 0x8014A224: bltzl       $t2, L_8014A280
    if (SIGNED(ctx->r10) < 0) {
        // 0x8014A228: lw          $t3, 0x30($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X30);
            goto L_8014A280;
    }
    goto skip_0;
    // 0x8014A228: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    skip_0:
L_8014A22C:
    // 0x8014A22C: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8014A230: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8014A234: addiu       $t3, $zero, 0xE4
    ctx->r11 = ADD32(0, 0XE4);
    // 0x8014A238: beq         $v0, $at, L_8014A24C
    if (ctx->r2 == ctx->r1) {
        // 0x8014A23C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8014A24C;
    }
    // 0x8014A23C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A240: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8014A244: bne         $v0, $at, L_8014A25C
    if (ctx->r2 != ctx->r1) {
        // 0x8014A248: addiu       $t4, $zero, 0xA9
        ctx->r12 = ADD32(0, 0XA9);
            goto L_8014A25C;
    }
    // 0x8014A248: addiu       $t4, $zero, 0xA9
    ctx->r12 = ADD32(0, 0XA9);
L_8014A24C:
    // 0x8014A24C: jal         0x800DEEC8
    // 0x8014A250: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8014A250: sw          $t3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r11;
    after_0:
    // 0x8014A254: b           L_8014A264
    // 0x8014A258: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
        goto L_8014A264;
    // 0x8014A258: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_8014A25C:
    // 0x8014A25C: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x8014A260: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_8014A264:
    // 0x8014A264: lw          $t5, 0x9C8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014A268: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8014A26C: lw          $t6, 0x338($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X338);
    // 0x8014A270: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8014A274: b           L_8014A29C
    // 0x8014A278: addu        $v1, $t6, $t9
    ctx->r3 = ADD32(ctx->r14, ctx->r25);
        goto L_8014A29C;
    // 0x8014A278: addu        $v1, $t6, $t9
    ctx->r3 = ADD32(ctx->r14, ctx->r25);
    // 0x8014A27C: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
L_8014A280:
    // 0x8014A280: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8014A284: lw          $t1, 0x9C8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X9C8);
    // 0x8014A288: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8014A28C: lw          $t2, 0x338($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X338);
    // 0x8014A290: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8014A294: addu        $v1, $t2, $t5
    ctx->r3 = ADD32(ctx->r10, ctx->r13);
    // 0x8014A298: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_8014A29C:
    // 0x8014A29C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8014A2A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x8014A2A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014A2A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014A2AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014A2B0: jal         0x800E6F24
    // 0x8014A2B4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014A2B4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8014A2B8: jal         0x800E0830
    // 0x8014A2BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8014A2BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x8014A2C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014A2C4: jal         0x800E8098
    // 0x8014A2C8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_3;
    // 0x8014A2C8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_3:
    // 0x8014A2CC: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8014A2D0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8014A2D4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014A2D8: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x8014A2DC: beq         $v0, $at, L_8014A2F0
    if (ctx->r2 == ctx->r1) {
        // 0x8014A2E0: sw          $zero, 0x180($s0)
        MEM_W(0X180, ctx->r16) = 0;
            goto L_8014A2F0;
    }
    // 0x8014A2E0: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8014A2E4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x8014A2E8: bnel        $v0, $at, L_8014A314
    if (ctx->r2 != ctx->r1) {
        // 0x8014A2EC: lw          $a1, 0x0($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X0);
            goto L_8014A314;
    }
    goto skip_1;
    // 0x8014A2EC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    skip_1:
L_8014A2F0:
    // 0x8014A2F0: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8014A2F4: jal         0x80101E80
    // 0x8014A2F8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    efManagerSamusGrappleBeamGlowMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8014A2F8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_4:
    // 0x8014A2FC: beq         $v0, $zero, L_8014A310
    if (ctx->r2 == 0) {
        // 0x8014A300: lw          $v1, 0x2C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X2C);
            goto L_8014A310;
    }
    // 0x8014A300: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8014A304: lbu         $t8, 0x18F($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X18F);
    // 0x8014A308: ori         $t6, $t8, 0x10
    ctx->r14 = ctx->r24 | 0X10;
    // 0x8014A30C: sb          $t6, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r14;
L_8014A310:
    // 0x8014A310: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
L_8014A314:
    // 0x8014A314: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8014A318: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8014A31C: beq         $a1, $at, L_8014A338
    if (ctx->r5 == ctx->r1) {
        // 0x8014A320: nop
    
            goto L_8014A338;
    }
    // 0x8014A320: nop

    // 0x8014A324: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8014A328: jal         0x8014AC0C
    // 0x8014A32C: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    ftCommonThrownSetStatusQueue(rdram, ctx);
        goto after_5;
    // 0x8014A32C: lw          $a2, 0x4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4);
    after_5:
    // 0x8014A330: b           L_8014A344
    // 0x8014A334: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
        goto L_8014A344;
    // 0x8014A334: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_8014A338:
    // 0x8014A338: jal         0x8014ACB4
    // 0x8014A33C: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    ftCommonThrownSetStatusImmediate(rdram, ctx);
        goto after_6;
    // 0x8014A33C: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    after_6:
    // 0x8014A340: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
L_8014A344:
    // 0x8014A344: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8014A348: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8014A34C: beq         $v0, $at, L_8014A358
    if (ctx->r2 == ctx->r1) {
        // 0x8014A350: addiu       $at, $zero, 0x16
        ctx->r1 = ADD32(0, 0X16);
            goto L_8014A358;
    }
    // 0x8014A350: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x8014A354: bne         $v0, $at, L_8014A380
    if (ctx->r2 != ctx->r1) {
        // 0x8014A358: addiu       $at, $zero, 0xE4
        ctx->r1 = ADD32(0, 0XE4);
            goto L_8014A380;
    }
L_8014A358:
    // 0x8014A358: addiu       $at, $zero, 0xE4
    ctx->r1 = ADD32(0, 0XE4);
    // 0x8014A35C: bnel        $t9, $at, L_8014A384
    if (ctx->r25 != ctx->r1) {
        // 0x8014A360: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8014A384;
    }
    goto skip_2;
    // 0x8014A360: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8014A364: lbu         $t1, 0x192($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X192);
    // 0x8014A368: ori         $t3, $t1, 0x40
    ctx->r11 = ctx->r9 | 0X40;
    // 0x8014A36C: sb          $t3, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r11;
    // 0x8014A370: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x8014A374: lbu         $t5, 0x192($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X192);
    // 0x8014A378: ori         $t7, $t5, 0x40
    ctx->r15 = ctx->r13 | 0X40;
    // 0x8014A37C: sb          $t7, 0x192($t4)
    MEM_B(0X192, ctx->r12) = ctx->r15;
L_8014A380:
    // 0x8014A380: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8014A384:
    // 0x8014A384: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014A388: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8014A38C: jr          $ra
    // 0x8014A390: nop

    return;
    // 0x8014A390: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiCheckGotoSubZip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801531AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801531B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801531B4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801531B8: lb          $t6, 0x1C2($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C2);
    // 0x801531BC: lb          $t7, 0x1C3($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1C3);
    // 0x801531C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x801531C4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801531C8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x801531CC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801531D0: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801531D4: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801531D8: nop

    // 0x801531DC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801531E0: jal         0x80033510
    // 0x801531E4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x801531E4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x801531E8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x801531EC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801531F0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x801531F4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801531F8: nop

    // 0x801531FC: bc1fl       L_80153210
    if (!c1cs) {
        // 0x80153200: lw          $t8, 0xB1C($v0)
        ctx->r24 = MEM_W(ctx->r2, 0XB1C);
            goto L_80153210;
    }
    goto skip_0;
    // 0x80153200: lw          $t8, 0xB1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB1C);
    skip_0:
    // 0x80153204: b           L_801532A8
    // 0x80153208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801532A8;
    // 0x80153208: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8015320C: lw          $t8, 0xB1C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XB1C);
L_80153210:
    // 0x80153210: bnel        $t8, $zero, L_801532A8
    if (ctx->r24 != 0) {
        // 0x80153214: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801532A8;
    }
    goto skip_1;
    // 0x80153214: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80153218: lb          $t9, 0x1C2($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1C2);
    // 0x8015321C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80153220: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80153224: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80153228: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x8015322C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80153230: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80153234: lb          $t0, 0x1C3($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X1C3);
    // 0x80153238: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x8015323C: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80153240: nop

    // 0x80153244: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80153248: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x8015324C: lw          $t1, 0xB24($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XB24);
    // 0x80153250: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80153254: nop

    // 0x80153258: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8015325C: swc1        $f16, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f16.u32l;
    // 0x80153260: lw          $t2, 0xB28($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XB28);
    // 0x80153264: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80153268: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8015326C: nop

    // 0x80153270: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80153274: jal         0x800191FC
    // 0x80153278: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_1;
    // 0x80153278: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8015327C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80153280: lwc1        $f6, -0x3A84($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3A84);
    // 0x80153284: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80153288: nop

    // 0x8015328C: bc1f        L_8015329C
    if (!c1cs) {
        // 0x80153290: nop
    
            goto L_8015329C;
    }
    // 0x80153290: nop

    // 0x80153294: b           L_801532A8
    // 0x80153298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801532A8;
    // 0x80153298: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8015329C:
    // 0x8015329C: b           L_801532A8
    // 0x801532A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801532A8;
    // 0x801532A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801532A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801532A8:
    // 0x801532A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801532AC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801532B0: jr          $ra
    // 0x801532B4: nop

    return;
    // 0x801532B4: nop

;}
RECOMP_FUNC void lbBackupIsChecksumValid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D45A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D45A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D45AC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D45B0: jal         0x800D4520
    // 0x800D45B4: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    lbBackupCreateChecksum(rdram, ctx);
        goto after_0;
    // 0x800D45B4: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    after_0:
    // 0x800D45B8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D45BC: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
    // 0x800D45C0: lw          $t6, 0x5E8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X5E8);
    // 0x800D45C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D45C8: bnel        $v0, $t6, L_800D45EC
    if (ctx->r2 != ctx->r14) {
        // 0x800D45CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D45EC;
    }
    goto skip_0;
    // 0x800D45CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800D45D0: lhu         $t7, 0x5E4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X5E4);
    // 0x800D45D4: addiu       $at, $zero, 0x29A
    ctx->r1 = ADD32(0, 0X29A);
    // 0x800D45D8: bnel        $t7, $at, L_800D45EC
    if (ctx->r15 != ctx->r1) {
        // 0x800D45DC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D45EC;
    }
    goto skip_1;
    // 0x800D45DC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800D45E0: b           L_800D45EC
    // 0x800D45E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D45EC;
    // 0x800D45E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800D45E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D45EC:
    // 0x800D45EC: jr          $ra
    // 0x800D45F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800D45F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void mnDataStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EC0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132EC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132EC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132ECC: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80132ED0: addiu       $a0, $a0, 0x2FB0
    ctx->r4 = ADD32(ctx->r4, 0X2FB0);
    // 0x80132ED4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132ED8: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132EDC: jal         0x80007024
    // 0x80132EE0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132EE0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132EE4: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132EE8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132EEC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132EF0: addiu       $t9, $t9, 0x3170
    ctx->r25 = ADD32(ctx->r25, 0X3170);
    // 0x80132EF4: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80132EF8: addiu       $a0, $a0, 0x2FCC
    ctx->r4 = ADD32(ctx->r4, 0X2FCC);
    // 0x80132EFC: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132F00: jal         0x8000683C
    // 0x80132F04: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80132F04: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80132F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132F0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132F10: jr          $ra
    // 0x80132F14: nop

    return;
    // 0x80132F14: nop

;}
RECOMP_FUNC void grHyruleTwisterDecLifetimeCheckStop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A4F4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010A4F8: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x8010A4FC: lhu         $t6, 0x20($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X20);
    // 0x8010A500: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8010A504: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010A508: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8010A50C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8010A510: bne         $t8, $zero, L_8010A520
    if (ctx->r24 != 0) {
        // 0x8010A514: sh          $t7, 0x20($v1)
        MEM_H(0X20, ctx->r3) = ctx->r15;
            goto L_8010A520;
    }
    // 0x8010A514: sh          $t7, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r15;
    // 0x8010A518: jr          $ra
    // 0x8010A51C: sb          $t9, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r25;
    return;
    // 0x8010A51C: sb          $t9, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r25;
L_8010A520:
    // 0x8010A520: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8010A524: jr          $ra
    // 0x8010A528: nop

    return;
    // 0x8010A528: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialNProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801646F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801646F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801646F8: jal         0x80164688
    // 0x801646FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbyCopyLinkSpecialNMakeBoomerang(rdram, ctx);
        goto after_0;
    // 0x801646FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80164700: jal         0x800D94C4
    // 0x80164704: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetWait(rdram, ctx);
        goto after_1;
    // 0x80164704: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80164708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016470C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80164710: jr          $ra
    // 0x80164714: nop

    return;
    // 0x80164714: nop

;}
RECOMP_FUNC void lbParticleEjectStructAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEB50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CEB54: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CEB58: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CEB5C: lui         $s2, 0x800D
    ctx->r18 = S32(0X800D << 16);
    // 0x800CEB60: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800CEB64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CEB68: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CEB6C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CEB70: addiu       $s3, $s3, 0x6398
    ctx->r19 = ADD32(ctx->r19, 0X6398);
    // 0x800CEB74: addiu       $s2, $s2, 0x6358
    ctx->r18 = ADD32(ctx->r18, 0X6358);
    // 0x800CEB78: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_800CEB7C:
    // 0x800CEB7C: beql        $s0, $zero, L_800CEB9C
    if (ctx->r16 == 0) {
        // 0x800CEB80: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800CEB9C;
    }
    goto skip_0;
    // 0x800CEB80: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    skip_0:
L_800CEB84:
    // 0x800CEB84: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800CEB88: jal         0x800CEA40
    // 0x800CEB8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbParticleEjectStruct(rdram, ctx);
        goto after_0;
    // 0x800CEB8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800CEB90: bne         $s1, $zero, L_800CEB84
    if (ctx->r17 != 0) {
        // 0x800CEB94: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_800CEB84;
    }
    // 0x800CEB94: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800CEB98: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_800CEB9C:
    // 0x800CEB9C: bnel        $s2, $s3, L_800CEB7C
    if (ctx->r18 != ctx->r19) {
        // 0x800CEBA0: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_800CEB7C;
    }
    goto skip_1;
    // 0x800CEBA0: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_1:
    // 0x800CEBA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CEBA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CEBAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CEBB0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CEBB4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CEBB8: jr          $ra
    // 0x800CEBBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800CEBBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mvOpeningSectorCockpitProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013202C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132030: addiu       $t4, $t4, 0x2A3C
    ctx->r12 = ADD32(ctx->r12, 0X2A3C);
    // 0x80132034: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x80132038: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013203C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132040: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80132044: beq         $at, $zero, L_80132064
    if (ctx->r1 == 0) {
        // 0x80132048: lw          $t3, 0x74($a0)
        ctx->r11 = MEM_W(ctx->r4, 0X74);
            goto L_80132064;
    }
    // 0x80132048: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x8013204C: addiu       $t6, $v0, 0x9
    ctx->r14 = ADD32(ctx->r2, 0X9);
    // 0x80132050: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80132054: bne         $at, $zero, L_80132064
    if (ctx->r1 != 0) {
        // 0x80132058: sw          $t6, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r14;
            goto L_80132064;
    }
    // 0x80132058: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x8013205C: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80132060: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_80132064:
    // 0x80132064: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132068: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8013206C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132070: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80132074: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80132078: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013207C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132080: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132084: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80132088: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013208C: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80132090: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80132094: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132098: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013209C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801320A0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801320A4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801320A8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801320AC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801320B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801320B4: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801320B8: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x801320BC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x801320C0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801320C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801320C8: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801320CC: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801320D0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801320D4: lbu         $t8, 0x61($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X61);
    // 0x801320D8: lbu         $t5, 0x60($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X60);
    // 0x801320DC: lui         $t7, 0xFCFF
    ctx->r15 = S32(0XFCFF << 16);
    // 0x801320E0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x801320E4: lbu         $t8, 0x62($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X62);
    // 0x801320E8: sll         $t6, $t5, 24
    ctx->r14 = S32(ctx->r13 << 24);
    // 0x801320EC: or          $t5, $t6, $t9
    ctx->r13 = ctx->r14 | ctx->r25;
    // 0x801320F0: sll         $t6, $t8, 8
    ctx->r14 = S32(ctx->r24 << 8);
    // 0x801320F4: lbu         $t8, 0x63($t3)
    ctx->r24 = MEM_BU(ctx->r11, 0X63);
    // 0x801320F8: or          $t9, $t5, $t6
    ctx->r25 = ctx->r13 | ctx->r14;
    // 0x801320FC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80132100: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x80132104: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80132108: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013210C: lui         $t9, 0xFFFC
    ctx->r25 = S32(0XFFFC << 16);
    // 0x80132110: ori         $t9, $t9, 0xF67B
    ctx->r25 = ctx->r25 | 0XF67B;
    // 0x80132114: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132118: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013211C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132120: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132124: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132128: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x8013212C: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80132130: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132134: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132138: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8013213C: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x80132140: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80132144: jal         0x800CCF74
    // 0x80132148: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_0;
    // 0x80132148: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    after_0:
    // 0x8013214C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132154: jr          $ra
    // 0x80132158: nop

    return;
    // 0x80132158: nop

;}
RECOMP_FUNC void mnPlayersVSArrowThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801369E4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801369E8: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x801369EC: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x801369F0: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x801369F4: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x801369F8: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x801369FC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80136A00: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80136A04: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80136A08: lui         $at, 0x4349
    ctx->r1 = S32(0X4349 << 16);
    // 0x80136A0C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80136A10: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80136A14: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80136A18: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80136A1C: lui         $s6, 0x8014
    ctx->r22 = S32(0X8014 << 16);
    // 0x80136A20: lui         $fp, 0x8014
    ctx->r30 = S32(0X8014 << 16);
    // 0x80136A24: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80136A28: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80136A2C: lw          $s3, 0x84($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X84);
    // 0x80136A30: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80136A34: addiu       $fp, $fp, -0x4578
    ctx->r30 = ADD32(ctx->r30, -0X4578);
    // 0x80136A38: addiu       $s6, $s6, -0x3B60
    ctx->r22 = ADD32(ctx->r22, -0X3B60);
    // 0x80136A3C: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80136A40: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80136A44: addiu       $s7, $zero, -0x21
    ctx->r23 = ADD32(0, -0X21);
    // 0x80136A48: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
L_80136A4C:
    // 0x80136A4C: bne         $s2, $zero, L_80136A70
    if (ctx->r18 != 0) {
        // 0x80136A50: sll         $t7, $s3, 2
        ctx->r15 = S32(ctx->r19 << 2);
            goto L_80136A70;
    }
    // 0x80136A50: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x80136A54: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80136A58: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80136A5C: bnel        $s4, $t6, L_80136A70
    if (ctx->r20 != ctx->r14) {
        // 0x80136A60: sw          $s4, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r20;
            goto L_80136A70;
    }
    goto skip_0;
    // 0x80136A60: sw          $s4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r20;
    skip_0:
    // 0x80136A64: b           L_80136A70
    // 0x80136A68: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
        goto L_80136A70;
    // 0x80136A68: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x80136A6C: sw          $s4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r20;
L_80136A70:
    // 0x80136A70: subu        $t7, $t7, $s3
    ctx->r15 = SUB32(ctx->r15, ctx->r19);
    // 0x80136A74: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x80136A78: subu        $t7, $t7, $s3
    ctx->r15 = SUB32(ctx->r15, ctx->r19);
    // 0x80136A7C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80136A80: addu        $v0, $fp, $t7
    ctx->r2 = ADD32(ctx->r30, ctx->r15);
    // 0x80136A84: lw          $t8, 0x84($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X84);
    // 0x80136A88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80136A8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136A90: bnel        $t8, $zero, L_80136AA4
    if (ctx->r24 != 0) {
        // 0x80136A94: lw          $s1, 0x38($v0)
        ctx->r17 = MEM_W(ctx->r2, 0X38);
            goto L_80136AA4;
    }
    goto skip_1;
    // 0x80136A94: lw          $s1, 0x38($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X38);
    skip_1:
    // 0x80136A98: b           L_80136AA4
    // 0x80136A9C: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
        goto L_80136AA4;
    // 0x80136A9C: lw          $s1, 0x3C($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X3C);
    // 0x80136AA0: lw          $s1, 0x38($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X38);
L_80136AA4:
    // 0x80136AA4: bne         $s1, $s5, L_80136ACC
    if (ctx->r17 != ctx->r21) {
        // 0x80136AA8: nop
    
            goto L_80136ACC;
    }
    // 0x80136AA8: nop

    // 0x80136AAC: jal         0x80136998
    // 0x80136AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSGetArrowSObj(rdram, ctx);
        goto after_0;
    // 0x80136AB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80136AB4: beq         $v0, $zero, L_80136B2C
    if (ctx->r2 == 0) {
        // 0x80136AB8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80136B2C;
    }
    // 0x80136AB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136ABC: jal         0x800096EC
    // 0x80136AC0: nop

    gcEjectSObj(rdram, ctx);
        goto after_1;
    // 0x80136AC0: nop

    after_1:
    // 0x80136AC4: b           L_80136B30
    // 0x80136AC8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
        goto L_80136B30;
    // 0x80136AC8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_80136ACC:
    // 0x80136ACC: jal         0x80136998
    // 0x80136AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    mnPlayersVSGetArrowSObj(rdram, ctx);
        goto after_2;
    // 0x80136AD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80136AD4: bne         $v0, $zero, L_80136B2C
    if (ctx->r2 != 0) {
        // 0x80136AD8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80136B2C;
    }
    // 0x80136AD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136ADC: sll         $t1, $s3, 4
    ctx->r9 = S32(ctx->r19 << 4);
    // 0x80136AE0: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
    // 0x80136AE4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80136AE8: addu        $t1, $t1, $s3
    ctx->r9 = ADD32(ctx->r9, ctx->r19);
    // 0x80136AEC: addiu       $t2, $t1, 0x19
    ctx->r10 = ADD32(ctx->r9, 0X19);
    // 0x80136AF0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80136AF4: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x80136AF8: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80136AFC: addiu       $t0, $t0, -0x1318
    ctx->r8 = ADD32(ctx->r8, -0X1318);
    // 0x80136B00: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    // 0x80136B04: jal         0x800CCFDC
    // 0x80136B08: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80136B08: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    after_3:
    // 0x80136B0C: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x80136B10: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
    // 0x80136B14: swc1        $f22, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f22.u32l;
    // 0x80136B18: and         $t5, $t3, $s7
    ctx->r13 = ctx->r11 & ctx->r23;
    // 0x80136B1C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80136B20: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80136B24: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80136B28: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
L_80136B2C:
    // 0x80136B2C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
L_80136B30:
    // 0x80136B30: bne         $s1, $at, L_80136B5C
    if (ctx->r17 != ctx->r1) {
        // 0x80136B34: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80136B5C;
    }
    // 0x80136B34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136B38: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136B3C: jal         0x80136998
    // 0x80136B40: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mnPlayersVSGetArrowSObj(rdram, ctx);
        goto after_4;
    // 0x80136B40: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_4:
    // 0x80136B44: beq         $v0, $zero, L_80136BBC
    if (ctx->r2 == 0) {
        // 0x80136B48: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80136BBC;
    }
    // 0x80136B48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80136B4C: jal         0x800096EC
    // 0x80136B50: nop

    gcEjectSObj(rdram, ctx);
        goto after_5;
    // 0x80136B50: nop

    after_5:
    // 0x80136B54: b           L_80136BBC
    // 0x80136B58: nop

        goto L_80136BBC;
    // 0x80136B58: nop

L_80136B5C:
    // 0x80136B5C: jal         0x80136998
    // 0x80136B60: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    mnPlayersVSGetArrowSObj(rdram, ctx);
        goto after_6;
    // 0x80136B60: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_6:
    // 0x80136B64: bne         $v0, $zero, L_80136BBC
    if (ctx->r2 != 0) {
        // 0x80136B68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80136BBC;
    }
    // 0x80136B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80136B6C: sll         $t9, $s3, 4
    ctx->r25 = S32(ctx->r19 << 4);
    // 0x80136B70: addu        $t9, $t9, $s3
    ctx->r25 = ADD32(ctx->r25, ctx->r19);
    // 0x80136B74: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80136B78: addu        $t9, $t9, $s3
    ctx->r25 = ADD32(ctx->r25, ctx->r19);
    // 0x80136B7C: addiu       $t0, $t9, 0x4F
    ctx->r8 = ADD32(ctx->r25, 0X4F);
    // 0x80136B80: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x80136B84: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x80136B88: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80136B8C: addiu       $t8, $t8, -0x1238
    ctx->r24 = ADD32(ctx->r24, -0X1238);
    // 0x80136B90: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80136B94: jal         0x800CCFDC
    // 0x80136B98: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x80136B98: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    after_7:
    // 0x80136B9C: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80136BA0: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
    // 0x80136BA4: swc1        $f22, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f22.u32l;
    // 0x80136BA8: and         $t3, $t1, $s7
    ctx->r11 = ctx->r9 & ctx->r23;
    // 0x80136BAC: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80136BB0: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80136BB4: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80136BB8: sw          $s5, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r21;
L_80136BBC:
    // 0x80136BBC: jal         0x8000B1E8
    // 0x80136BC0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_8;
    // 0x80136BC0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_8:
    // 0x80136BC4: b           L_80136A4C
    // 0x80136BC8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
        goto L_80136A4C;
    // 0x80136BC8: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80136BCC: nop

    // 0x80136BD0: nop

    // 0x80136BD4: nop

    // 0x80136BD8: nop

    // 0x80136BDC: nop

    // 0x80136BE0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80136BE4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80136BE8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80136BEC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80136BF0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80136BF4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80136BF8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80136BFC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80136C00: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80136C04: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80136C08: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80136C0C: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80136C10: jr          $ra
    // 0x80136C14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80136C14: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void itSawamuraAttackSetFollowPlayerLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018285C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80182860: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80182864: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x80182868: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018286C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80182870: lw          $v1, 0x74($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X74);
    // 0x80182874: lw          $t0, 0x74($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X74);
    // 0x80182878: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8018287C: lw          $t8, 0x1C($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X1C);
    // 0x80182880: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80182884: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80182888: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8018288C: lw          $t7, 0x20($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X20);
    // 0x80182890: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80182894: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80182898: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8018289C: lw          $t8, 0x24($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X24);
    // 0x801828A0: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x801828A4: addiu       $a2, $t0, 0x1C
    ctx->r6 = ADD32(ctx->r8, 0X1C);
    // 0x801828A8: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x801828AC: lwc1        $f6, 0xB8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XB8);
    // 0x801828B0: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801828B4: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x801828B8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801828BC: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801828C0: jal         0x8001902C
    // 0x801828C4: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x801828C4: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x801828C8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801828CC: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x801828D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801828D4: swc1        $f0, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->f0.u32l;
    // 0x801828D8: swc1        $f0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f0.u32l;
    // 0x801828DC: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x801828E0: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    // 0x801828E4: jal         0x8001863C
    // 0x801828E8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x801828E8: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    after_1:
    // 0x801828EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801828F0: addiu       $a0, $s0, 0x2C
    ctx->r4 = ADD32(ctx->r16, 0X2C);
    // 0x801828F4: jal         0x800192D0
    // 0x801828F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syVectorRotate3D(rdram, ctx);
        goto after_2;
    // 0x801828F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x801828FC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80182900: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80182904: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80182908: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8018290C: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80182910: nop

    // 0x80182914: bc1fl       L_80182928
    if (!c1cs) {
        // 0x80182918: sw          $t1, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r9;
            goto L_80182928;
    }
    goto skip_0;
    // 0x80182918: sw          $t1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r9;
    skip_0:
    // 0x8018291C: b           L_80182928
    // 0x80182920: sw          $t9, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r25;
        goto L_80182928;
    // 0x80182920: sw          $t9, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r25;
    // 0x80182924: sw          $t1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r9;
L_80182928:
    // 0x80182928: lw          $t2, 0x24($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X24);
    // 0x8018292C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80182930: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80182934: bne         $t2, $at, L_80182944
    if (ctx->r10 != ctx->r1) {
        // 0x80182938: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80182944;
    }
    // 0x80182938: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018293C: lwc1        $f10, -0x3130($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3130);
    // 0x80182940: swc1        $f10, 0x34($t3)
    MEM_W(0X34, ctx->r11) = ctx->f10.u32l;
L_80182944:
    // 0x80182944: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80182948: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018294C: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80182950: jr          $ra
    // 0x80182954: nop

    return;
    // 0x80182954: nop

;}
RECOMP_FUNC void mnVSRecordMakeString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324C8: addiu       $sp, $sp, -0xF8
    ctx->r29 = ADD32(ctx->r29, -0XF8);
    // 0x801324CC: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801324D0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801324D4: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x801324D8: addiu       $t7, $t7, 0x66F8
    ctx->r15 = ADD32(ctx->r15, 0X66F8);
    // 0x801324DC: mtc1        $a3, $f22
    ctx->f22.u32l = ctx->r7;
    // 0x801324E0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801324E4: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x801324E8: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x801324EC: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x801324F0: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x801324F4: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x801324F8: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x801324FC: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80132500: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80132504: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80132508: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8013250C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80132510: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80132514: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80132518: sw          $a0, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->r4;
    // 0x8013251C: addiu       $t0, $t7, 0x6C
    ctx->r8 = ADD32(ctx->r15, 0X6C);
    // 0x80132520: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
L_80132524:
    // 0x80132524: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132528: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8013252C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132530: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132534: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132538: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8013253C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132540: bne         $t7, $t0, L_80132524
    if (ctx->r15 != ctx->r8) {
        // 0x80132544: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132524;
    }
    // 0x80132544: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132548: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013254C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132550: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80132554: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132558: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013255C: lbu         $t1, 0x0($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X0);
    // 0x80132560: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80132564: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80132568: beq         $t1, $zero, L_801326AC
    if (ctx->r9 == 0) {
        // 0x8013256C: andi        $a0, $t1, 0xFF
        ctx->r4 = ctx->r9 & 0XFF;
            goto L_801326AC;
    }
    // 0x8013256C: andi        $a0, $t1, 0xFF
    ctx->r4 = ctx->r9 & 0XFF;
    // 0x80132570: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132574: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80132578: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8013257C: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80132580: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80132584: addiu       $s6, $s6, 0x6D88
    ctx->r22 = ADD32(ctx->r22, 0X6D88);
    // 0x80132588: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8013258C: addiu       $fp, $zero, 0x2E
    ctx->r30 = ADD32(0, 0X2E);
    // 0x80132590: addiu       $s7, $zero, 0x27
    ctx->r23 = ADD32(0, 0X27);
    // 0x80132594: addiu       $s4, $zero, 0x20
    ctx->r20 = ADD32(0, 0X20);
    // 0x80132598: lw          $s2, 0x108($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X108);
L_8013259C:
    // 0x8013259C: slti        $at, $v1, 0x30
    ctx->r1 = SIGNED(ctx->r3) < 0X30 ? 1 : 0;
    // 0x801325A0: bne         $at, $zero, L_801325BC
    if (ctx->r1 != 0) {
        // 0x801325A4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801325BC;
    }
    // 0x801325A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801325A8: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
    // 0x801325AC: beq         $at, $zero, L_801325BC
    if (ctx->r1 == 0) {
        // 0x801325B0: nop
    
            goto L_801325BC;
    }
    // 0x801325B0: nop

    // 0x801325B4: b           L_801325BC
    // 0x801325B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801325BC;
    // 0x801325B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801325BC:
    // 0x801325BC: bne         $v0, $zero, L_801325CC
    if (ctx->r2 != 0) {
        // 0x801325C0: nop
    
            goto L_801325CC;
    }
    // 0x801325C0: nop

    // 0x801325C4: bne         $s4, $v1, L_801325F0
    if (ctx->r20 != ctx->r3) {
        // 0x801325C8: nop
    
            goto L_801325F0;
    }
    // 0x801325C8: nop

L_801325CC:
    // 0x801325CC: bne         $s4, $v1, L_801325DC
    if (ctx->r20 != ctx->r3) {
        // 0x801325D0: addiu       $t2, $v1, -0x30
        ctx->r10 = ADD32(ctx->r3, -0X30);
            goto L_801325DC;
    }
    // 0x801325D0: addiu       $t2, $v1, -0x30
    ctx->r10 = ADD32(ctx->r3, -0X30);
    // 0x801325D4: b           L_80132698
    // 0x801325D8: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
        goto L_80132698;
    // 0x801325D8: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
L_801325DC:
    // 0x801325DC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801325E0: nop

    // 0x801325E4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801325E8: b           L_80132698
    // 0x801325EC: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
        goto L_80132698;
    // 0x801325EC: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_801325F0:
    // 0x801325F0: jal         0x8013232C
    // 0x801325F4: nop

    mnVSRecordGetCharacterID(rdram, ctx);
        goto after_0;
    // 0x801325F4: nop

    after_0:
    // 0x801325F8: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x801325FC: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80132600: lw          $t4, 0x84($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X84);
    // 0x80132604: lw          $t5, 0xC($s6)
    ctx->r13 = MEM_W(ctx->r22, 0XC);
    // 0x80132608: lw          $a0, 0xF8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XF8);
    // 0x8013260C: jal         0x800CCFDC
    // 0x80132610: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132610: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_1:
    // 0x80132614: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132618: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
    // 0x8013261C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80132620: jal         0x801323A4
    // 0x80132624: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    mnVSRecordGetCharacterSpacing(rdram, ctx);
        goto after_2;
    // 0x80132624: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x80132628: lh          $t0, 0x14($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X14);
    // 0x8013262C: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x80132630: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x80132634: nop

    // 0x80132638: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013263C: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80132640: beq         $v0, $s7, L_80132658
    if (ctx->r2 == ctx->r23) {
        // 0x80132644: add.s       $f20, $f20, $f16
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
            goto L_80132658;
    }
    // 0x80132644: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
    // 0x80132648: beql        $v0, $fp, L_80132668
    if (ctx->r2 == ctx->r30) {
        // 0x8013264C: add.s       $f4, $f22, $f24
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f24.fl;
            goto L_80132668;
    }
    goto skip_0;
    // 0x8013264C: add.s       $f4, $f22, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f24.fl;
    skip_0:
    // 0x80132650: b           L_8013266C
    // 0x80132654: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
        goto L_8013266C;
    // 0x80132654: swc1        $f22, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f22.u32l;
L_80132658:
    // 0x80132658: sub.s       $f18, $f22, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x8013265C: b           L_8013266C
    // 0x80132660: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
        goto L_8013266C;
    // 0x80132660: swc1        $f18, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f18.u32l;
    // 0x80132664: add.s       $f4, $f22, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f24.fl;
L_80132668:
    // 0x80132668: swc1        $f4, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f4.u32l;
L_8013266C:
    // 0x8013266C: lhu         $t7, 0x24($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X24);
    // 0x80132670: andi        $t8, $t7, 0xFFDF
    ctx->r24 = ctx->r15 & 0XFFDF;
    // 0x80132674: sh          $t8, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r24;
    // 0x80132678: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8013267C: sh          $t9, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r25;
    // 0x80132680: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80132684: sb          $t1, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r9;
    // 0x80132688: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x8013268C: sb          $t2, 0x29($s0)
    MEM_B(0X29, ctx->r16) = ctx->r10;
    // 0x80132690: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x80132694: sb          $t3, 0x2A($s0)
    MEM_B(0X2A, ctx->r16) = ctx->r11;
L_80132698:
    // 0x80132698: lbu         $a0, 0x1($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X1);
    // 0x8013269C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801326A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x801326A4: bne         $a0, $zero, L_8013259C
    if (ctx->r4 != 0) {
        // 0x801326A8: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8013259C;
    }
    // 0x801326A8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_801326AC:
    // 0x801326AC: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x801326B0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x801326B4: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x801326B8: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801326BC: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801326C0: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x801326C4: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x801326C8: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x801326CC: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x801326D0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x801326D4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x801326D8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x801326DC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x801326E0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x801326E4: jr          $ra
    // 0x801326E8: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
    return;
    // 0x801326E8: addiu       $sp, $sp, 0xF8
    ctx->r29 = ADD32(ctx->r29, 0XF8);
;}
RECOMP_FUNC void func_ovl8_80384D58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384D58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80384D5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384D60: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80384D64: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80384D68: lh          $t6, 0x28($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X28);
    // 0x80384D6C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80384D70: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80384D74: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x80384D78: jalr        $t9
    // 0x80384D7C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80384D7C: nop

    after_0:
    // 0x80384D80: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80384D84: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80384D88: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80384D8C: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80384D90: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80384D94: sub.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f4.d - ctx->f6.d;
    // 0x80384D98: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80384D9C: trunc.w.d   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_D(ctx->f8.d);
    // 0x80384DA0: lw          $t9, 0xF4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF4);
    // 0x80384DA4: lh          $t7, 0xF0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XF0);
    // 0x80384DA8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80384DAC: jalr        $t9
    // 0x80384DB0: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80384DB0: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_1:
    // 0x80384DB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384DB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384DBC: jr          $ra
    // 0x80384DC0: nop

    return;
    // 0x80384DC0: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingResetPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137900: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80137904: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80137908: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8013790C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80137910: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80137914: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80137918: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8013791C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80137920: addiu       $t8, $zero, 0x1C
    ctx->r24 = ADD32(0, 0X1C);
    // 0x80137924: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x80137928: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x8013792C: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80137930: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x80137934: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80137938: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8013793C: sw          $zero, 0xA4($v0)
    MEM_W(0XA4, ctx->r2) = 0;
    // 0x80137940: sh          $zero, 0xA8($v0)
    MEM_H(0XA8, ctx->r2) = 0;
    // 0x80137944: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x80137948: sw          $t8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r24;
    // 0x8013794C: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x80137950: sw          $zero, 0x80($v0)
    MEM_W(0X80, ctx->r2) = 0;
    // 0x80137954: sw          $a0, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r4;
    // 0x80137958: jr          $ra
    // 0x8013795C: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
    return;
    // 0x8013795C: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
;}
RECOMP_FUNC void ftYoshiSpecialLwStartProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EFD4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015EFD8: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x8015EFDC: jr          $ra
    // 0x8015EFE0: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    return;
    // 0x8015EFE0: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
;}
RECOMP_FUNC void mnVSRecordMakeLabelsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135C6C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135C70: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135C74: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80135C78: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80135C7C: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80135C80: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80135C84: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80135C88: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80135C8C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80135C90: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135C94: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80135C98: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80135C9C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80135CA0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135CA4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135CA8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135CAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135CB0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80135CB4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80135CB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80135CBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80135CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135CC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80135CC8: jal         0x8000B93C
    // 0x80135CCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80135CCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80135CD0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135CD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135CD8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135CDC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135CE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135CE4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80135CE8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80135CEC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80135CF0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80135CF4: jal         0x80007080
    // 0x80135CF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80135CF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80135CFC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80135D00: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135D04: jr          $ra
    // 0x80135D08: nop

    return;
    // 0x80135D08: nop

;}
RECOMP_FUNC void mvOpeningNewcomersMakePurin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131C3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131C40: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131C44: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131C48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131C4C: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80131C50: jal         0x80009968
    // 0x80131C54: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131C54: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131C58: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131C5C: jal         0x80131B58
    // 0x80131C60: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    mvOpeningNewcomersCheckLocked(rdram, ctx);
        goto after_1;
    // 0x80131C60: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_1:
    // 0x80131C64: beq         $v0, $zero, L_80131C90
    if (ctx->r2 == 0) {
        // 0x80131C68: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80131C90;
    }
    // 0x80131C68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131C6C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131C70: lw          $t6, 0x2910($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2910);
    // 0x80131C74: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80131C78: addiu       $t7, $t7, 0x3A8
    ctx->r15 = ADD32(ctx->r15, 0X3A8);
    // 0x80131C7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131C80: jal         0x800092D0
    // 0x80131C84: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131C84: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x80131C88: b           L_80131CAC
    // 0x80131C8C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_80131CAC;
    // 0x80131C8C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80131C90:
    // 0x80131C90: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131C94: lw          $t8, 0x2910($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2910);
    // 0x80131C98: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80131C9C: addiu       $t9, $t9, 0x5C28
    ctx->r25 = ADD32(ctx->r25, 0X5C28);
    // 0x80131CA0: jal         0x800092D0
    // 0x80131CA4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddDObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131CA4: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x80131CA8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80131CAC:
    // 0x80131CAC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131CB0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131CB4: jal         0x80008CC0
    // 0x80131CB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x80131CB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80131CBC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131CC0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80131CC4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80131CC8: addiu       $a1, $a1, 0x3E8C
    ctx->r5 = ADD32(ctx->r5, 0X3E8C);
    // 0x80131CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131CD0: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131CD4: jal         0x80009DF4
    // 0x80131CD8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_5;
    // 0x80131CD8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80131CDC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131CE0: lw          $t1, 0x2910($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2910);
    // 0x80131CE4: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80131CE8: addiu       $t2, $t2, 0x5E44
    ctx->r10 = ADD32(ctx->r10, 0X5E44);
    // 0x80131CEC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131CF0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80131CF4: jal         0x8000BD1C
    // 0x80131CF8: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_6;
    // 0x80131CF8: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_6:
    // 0x80131CFC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131D00: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80131D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131D08: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131D0C: jal         0x80008188
    // 0x80131D10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x80131D10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80131D14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131D18: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80131D1C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80131D20: jr          $ra
    // 0x80131D24: nop

    return;
    // 0x80131D24: nop

;}
RECOMP_FUNC void func_ovl8_8037D384(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D384: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x8037D388: addiu       $v0, $v0, -0x1020
    ctx->r2 = ADD32(ctx->r2, -0X1020);
    // 0x8037D38C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8037D390: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
    // 0x8037D394: bne         $v1, $zero, L_8037D3A4
    if (ctx->r3 != 0) {
        // 0x8037D398: nop
    
            goto L_8037D3A4;
    }
    // 0x8037D398: nop

    // 0x8037D39C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8037D3A0: sltu        $v1, $zero, $v1
    ctx->r3 = 0 < ctx->r3 ? 1 : 0;
L_8037D3A4:
    // 0x8037D3A4: jr          $ra
    // 0x8037D3A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8037D3A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void itRShellSpinSearchFollowPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A534: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8017A538: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8017A53C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8017A540: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x8017A544: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8017A548: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x8017A54C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x8017A550: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8017A554: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x8017A558: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8017A55C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017A560: beq         $s0, $zero, L_8017A5E4
    if (ctx->r16 == 0) {
        // 0x8017A564: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8017A5E4;
    }
    // 0x8017A564: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8017A568: addiu       $s2, $v0, 0x1C
    ctx->r18 = ADD32(ctx->r2, 0X1C);
    // 0x8017A56C: lwc1        $f20, 0x48($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X48);
    // 0x8017A570: addiu       $s3, $sp, 0x3C
    ctx->r19 = ADD32(ctx->r29, 0X3C);
    // 0x8017A574: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
L_8017A578:
    // 0x8017A578: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8017A57C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8017A580: jal         0x8001902C
    // 0x8017A584: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x8017A584: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_0:
    // 0x8017A588: bne         $s1, $zero, L_8017A5A0
    if (ctx->r17 != 0) {
        // 0x8017A58C: lwc1        $f2, 0x3C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8017A5A0;
    }
    // 0x8017A58C: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8017A590: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8017A594: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8017A598: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8017A59C: add.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl + ctx->f6.fl;
L_8017A5A0:
    // 0x8017A5A0: lwc1        $f2, 0x3C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8017A5A4: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8017A5A8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8017A5AC: nop

    // 0x8017A5B0: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8017A5B4: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017A5B8: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x8017A5BC: nop

    // 0x8017A5C0: bc1f        L_8017A5D0
    if (!c1cs) {
        // 0x8017A5C4: nop
    
            goto L_8017A5D0;
    }
    // 0x8017A5C4: nop

    // 0x8017A5C8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8017A5CC: sw          $s0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r16;
L_8017A5D0:
    // 0x8017A5D0: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    // 0x8017A5D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8017A5D8: bnel        $s0, $zero, L_8017A578
    if (ctx->r16 != 0) {
        // 0x8017A5DC: lw          $a1, 0x74($s0)
        ctx->r5 = MEM_W(ctx->r16, 0X74);
            goto L_8017A578;
    }
    goto skip_0;
    // 0x8017A5DC: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    skip_0:
    // 0x8017A5E0: swc1        $f20, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f20.u32l;
L_8017A5E4:
    // 0x8017A5E4: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8017A5E8: jal         0x8017A3A0
    // 0x8017A5EC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    itRShellSpinUpdateFollowPlayer(rdram, ctx);
        goto after_1;
    // 0x8017A5EC: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_1:
    // 0x8017A5F0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8017A5F4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x8017A5F8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A5FC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8017A600: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x8017A604: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8017A608: jr          $ra
    // 0x8017A60C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8017A60C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void gcGetDObjSetNextAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F84: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007F88: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x80007F8C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80007F90: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007F94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007F98: bne         $v1, $zero, L_80007FC0
    if (ctx->r3 != 0) {
        // 0x80007F9C: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_80007FC0;
    }
    // 0x80007F9C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007FA0: lhu         $a0, 0x6A38($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X6A38);
    // 0x80007FA4: jal         0x80004980
    // 0x80007FA8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80007FA8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_0:
    // 0x80007FAC: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007FB0: addiu       $a2, $a2, 0x6A30
    ctx->r6 = ADD32(ctx->r6, 0X6A30);
    // 0x80007FB4: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80007FB8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80007FBC: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_80007FC0:
    // 0x80007FC0: bne         $v1, $zero, L_80007FDC
    if (ctx->r3 != 0) {
        // 0x80007FC4: lui         $a1, 0x8004
        ctx->r5 = S32(0X8004 << 16);
            goto L_80007FDC;
    }
    // 0x80007FC4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80007FC8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007FCC: jal         0x80023624
    // 0x80007FD0: addiu       $a0, $a0, -0x2620
    ctx->r4 = ADD32(ctx->r4, -0X2620);
    syDebugPrintf(rdram, ctx);
        goto after_1;
    // 0x80007FD0: addiu       $a0, $a0, -0x2620
    ctx->r4 = ADD32(ctx->r4, -0X2620);
    after_1:
L_80007FD4:
    // 0x80007FD4: b           L_80007FD4
    pause_self(rdram);
    // 0x80007FD8: nop

L_80007FDC:
    // 0x80007FDC: addiu       $a1, $a1, 0x6A34
    ctx->r5 = ADD32(ctx->r5, 0X6A34);
    // 0x80007FE0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80007FE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007FE8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007FEC: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80007FF0: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x80007FF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007FF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80007FFC: jr          $ra
    // 0x80008000: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x80008000: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
;}

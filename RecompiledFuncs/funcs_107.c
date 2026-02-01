#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSModeMakeVSOptionsButton(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EBC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132EC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132EC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132EC8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132ECC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80132ED0: jal         0x80009968
    // 0x80132ED4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132ED4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132ED8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132EDC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132EE0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132EE4: sw          $v0, 0x493C($at)
    MEM_W(0X493C, ctx->r1) = ctx->r2;
    // 0x80132EE8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132EEC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132EF0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132EF4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132EF8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132EFC: jal         0x80009DF4
    // 0x80132F00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132F00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132F04: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132F08: lui         $a1, 0x424C
    ctx->r5 = S32(0X424C << 16);
    // 0x80132F0C: lui         $a2, 0x4314
    ctx->r6 = S32(0X4314 << 16);
    // 0x80132F10: jal         0x80132024
    // 0x80132F14: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    mnVSModeMakeButton(rdram, ctx);
        goto after_2;
    // 0x80132F14: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_2:
    // 0x80132F18: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132F1C: lw          $t7, 0x4948($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4948);
    // 0x80132F20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80132F24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132F28: bne         $t7, $at, L_80132F38
    if (ctx->r15 != ctx->r1) {
        // 0x80132F2C: nop
    
            goto L_80132F38;
    }
    // 0x80132F2C: nop

    // 0x80132F30: b           L_80132F38
    // 0x80132F34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80132F38;
    // 0x80132F34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80132F38:
    // 0x80132F38: jal         0x80131F4C
    // 0x80132F3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mnVSModeUpdateButton(rdram, ctx);
        goto after_3;
    // 0x80132F3C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80132F40: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132F44: lw          $t8, 0x4A4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4A4C);
    // 0x80132F48: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80132F4C: addiu       $t9, $t9, 0x3828
    ctx->r25 = ADD32(ctx->r25, 0X3828);
    // 0x80132F50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132F54: jal         0x800CCFDC
    // 0x80132F58: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132F58: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_4:
    // 0x80132F5C: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132F60: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x80132F64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132F68: lui         $at, 0x4317
    ctx->r1 = S32(0X4317 << 16);
    // 0x80132F6C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132F70: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132F74: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132F78: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132F7C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132F80: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132F84: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132F88: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132F8C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132F90: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132F94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132F98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132F9C: jr          $ra
    // 0x80132FA0: nop

    return;
    // 0x80132FA0: nop

;}
RECOMP_FUNC void mnCharactersFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801329E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801329EC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801329F0: lw          $t8, 0x66CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X66CC);
    // 0x801329F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801329F8: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801329FC: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80132A00: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132A04: beq         $t8, $zero, L_80132B2C
    if (ctx->r24 == 0) {
        // 0x80132A08: sw          $t7, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r15;
            goto L_80132B2C;
    }
    // 0x80132A08: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80132A0C: addiu       $v1, $v1, 0x66C8
    ctx->r3 = ADD32(ctx->r3, 0X66C8);
    // 0x80132A10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132A14: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132A18: beq         $v0, $zero, L_80132A28
    if (ctx->r2 == 0) {
        // 0x80132A1C: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80132A28;
    }
    // 0x80132A1C: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x80132A20: b           L_80132BD8
    // 0x80132A24: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
        goto L_80132BD8;
    // 0x80132A24: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_80132A28:
    // 0x80132A28: jal         0x80131B58
    // 0x80132A2C: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x80132A2C: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    after_0:
    // 0x80132A30: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80132A34: jal         0x80132984
    // 0x80132A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    mnCharactersAdvanceTrack(rdram, ctx);
        goto after_1;
    // 0x80132A38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80132A3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132A40: jal         0x80131B58
    // 0x80132A44: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_2;
    // 0x80132A44: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    after_2:
    // 0x80132A48: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132A4C: lw          $t0, 0x66FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X66FC);
    // 0x80132A50: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132A54: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80132A58: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80132A5C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132A60: lw          $a3, 0x66D4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X66D4);
    // 0x80132A64: lw          $a2, 0x66C4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X66C4);
    // 0x80132A68: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80132A6C: jal         0x80132500
    // 0x80132A70: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    mnCharactersGetMotion(rdram, ctx);
        goto after_3;
    // 0x80132A70: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80132A74: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x80132A78: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x80132A7C: lw          $t3, 0x24($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X24);
    // 0x80132A80: bnel        $t3, $at, L_80132A94
    if (ctx->r11 != ctx->r1) {
        // 0x80132A84: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_80132A94;
    }
    goto skip_0;
    // 0x80132A84: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80132A88: jal         0x800E98B0
    // 0x80132A8C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    ftParamResetFighterColAnim(rdram, ctx);
        goto after_4;
    // 0x80132A8C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_4:
    // 0x80132A90: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_80132A94:
    // 0x80132A94: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80132A98: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80132A9C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132AA0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80132AA4: jal         0x800E6F24
    // 0x80132AA8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    ftMainSetStatus(rdram, ctx);
        goto after_5;
    // 0x80132AA8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_5:
    // 0x80132AAC: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80132AB0: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x80132AB4: ori         $at, $at, 0x31
    ctx->r1 = ctx->r1 | 0X31;
    // 0x80132AB8: bne         $t5, $at, L_80132AC8
    if (ctx->r13 != ctx->r1) {
        // 0x80132ABC: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_80132AC8;
    }
    // 0x80132ABC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80132AC0: jal         0x800E9AF4
    // 0x80132AC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    ftParamCheckSetSkeletonColAnimID(rdram, ctx);
        goto after_6;
    // 0x80132AC4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_6:
L_80132AC8:
    // 0x80132AC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132ACC: jal         0x80132E20
    // 0x80132AD0: lw          $a0, 0x66DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66DC);
    mnCharactersUpdateMotionName(rdram, ctx);
        goto after_7;
    // 0x80132AD0: lw          $a0, 0x66DC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66DC);
    after_7:
    // 0x80132AD4: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x80132AD8: addiu       $at, $zero, 0x29A
    ctx->r1 = ADD32(0, 0X29A);
    // 0x80132ADC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80132AE0: beq         $v0, $at, L_80132B18
    if (ctx->r2 == ctx->r1) {
        // 0x80132AE4: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80132B18;
    }
    // 0x80132AE4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132AE8: lui         $at, 0xA
    ctx->r1 = S32(0XA << 16);
    // 0x80132AEC: ori         $at, $at, 0x2C2A
    ctx->r1 = ctx->r1 | 0X2C2A;
    // 0x80132AF0: bne         $t6, $at, L_80132B04
    if (ctx->r14 != ctx->r1) {
        // 0x80132AF4: addiu       $t7, $v0, 0x14
        ctx->r15 = ADD32(ctx->r2, 0X14);
            goto L_80132B04;
    }
    // 0x80132AF4: addiu       $t7, $v0, 0x14
    ctx->r15 = ADD32(ctx->r2, 0X14);
    // 0x80132AF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132AFC: b           L_80132B0C
    // 0x80132B00: sw          $t7, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = ctx->r15;
        goto L_80132B0C;
    // 0x80132B00: sw          $t7, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = ctx->r15;
L_80132B04:
    // 0x80132B04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B08: sw          $v0, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = ctx->r2;
L_80132B0C:
    // 0x80132B0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B10: b           L_80132BD8
    // 0x80132B14: sw          $t8, 0x66CC($at)
    MEM_W(0X66CC, ctx->r1) = ctx->r24;
        goto L_80132BD8;
    // 0x80132B14: sw          $t8, 0x66CC($at)
    MEM_W(0X66CC, ctx->r1) = ctx->r24;
L_80132B18:
    // 0x80132B18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B1C: sw          $zero, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = 0;
    // 0x80132B20: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B24: b           L_80132BD8
    // 0x80132B28: sw          $zero, 0x66CC($at)
    MEM_W(0X66CC, ctx->r1) = 0;
        goto L_80132BD8;
    // 0x80132B28: sw          $zero, 0x66CC($at)
    MEM_W(0X66CC, ctx->r1) = 0;
L_80132B2C:
    // 0x80132B2C: jal         0x80132768
    // 0x80132B30: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    mnCharactersCheckFighterAnimEnd(rdram, ctx);
        goto after_8;
    // 0x80132B30: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    after_8:
    // 0x80132B34: beq         $v0, $zero, L_80132BD8
    if (ctx->r2 == 0) {
        // 0x80132B38: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80132BD8;
    }
    // 0x80132B38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132B3C: jal         0x80131B58
    // 0x80132B40: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_9;
    // 0x80132B40: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    after_9:
    // 0x80132B44: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132B48: lw          $t9, 0x66FC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X66FC);
    // 0x80132B4C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132B50: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80132B54: lw          $a3, 0x66D4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X66D4);
    // 0x80132B58: lw          $a2, 0x66C4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X66C4);
    // 0x80132B5C: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x80132B60: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80132B64: jal         0x80132500
    // 0x80132B68: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    mnCharactersGetMotion(rdram, ctx);
        goto after_10;
    // 0x80132B68: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_10:
    // 0x80132B6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132B70: jal         0x80131B58
    // 0x80132B74: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    mnCharactersGetFighterKind(rdram, ctx);
        goto after_11;
    // 0x80132B74: lw          $a0, 0x65F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X65F8);
    after_11:
    // 0x80132B78: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132B7C: lw          $t0, 0x66FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X66FC);
    // 0x80132B80: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132B84: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80132B88: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80132B8C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132B90: lw          $a3, 0x66D4($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X66D4);
    // 0x80132B94: lw          $a2, 0x66C4($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X66C4);
    // 0x80132B98: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x80132B9C: jal         0x80132500
    // 0x80132BA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    mnCharactersGetMotion(rdram, ctx);
        goto after_12;
    // 0x80132BA0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_12:
    // 0x80132BA4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80132BA8: lui         $at, 0xA
    ctx->r1 = S32(0XA << 16);
    // 0x80132BAC: ori         $at, $at, 0x2C2A
    ctx->r1 = ctx->r1 | 0X2C2A;
    // 0x80132BB0: bne         $t2, $at, L_80132BC8
    if (ctx->r10 != ctx->r1) {
        // 0x80132BB4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80132BC8;
    }
    // 0x80132BB4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80132BB8: addiu       $t3, $zero, 0x14
    ctx->r11 = ADD32(0, 0X14);
    // 0x80132BBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132BC0: b           L_80132BD0
    // 0x80132BC4: sw          $t3, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = ctx->r11;
        goto L_80132BD0;
    // 0x80132BC4: sw          $t3, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = ctx->r11;
L_80132BC8:
    // 0x80132BC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132BCC: sw          $zero, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = 0;
L_80132BD0:
    // 0x80132BD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132BD4: sw          $t4, 0x66CC($at)
    MEM_W(0X66CC, ctx->r1) = ctx->r12;
L_80132BD8:
    // 0x80132BD8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132BDC: lw          $t5, 0x66D0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X66D0);
    // 0x80132BE0: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80132BE4: beql        $t5, $zero, L_80132C34
    if (ctx->r13 == 0) {
        // 0x80132BE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80132C34;
    }
    goto skip_1;
    // 0x80132BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80132BEC: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80132BF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132BF4: lwc1        $f2, 0x65BC($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X65BC);
    // 0x80132BF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132BFC: lwc1        $f6, 0x65C0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X65C0);
    // 0x80132C00: lwc1        $f4, 0x34($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80132C04: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80132C08: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x80132C0C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80132C10: lw          $v0, 0x74($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X74);
    // 0x80132C14: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80132C18: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80132C1C: nop

    // 0x80132C20: bc1fl       L_80132C34
    if (!c1cs) {
        // 0x80132C24: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80132C34;
    }
    goto skip_2;
    // 0x80132C24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80132C28: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80132C2C: swc1        $f10, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f10.u32l;
    // 0x80132C30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80132C34:
    // 0x80132C34: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80132C38: jr          $ra
    // 0x80132C3C: nop

    return;
    // 0x80132C3C: nop

;}
RECOMP_FUNC void itMBallHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C848: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017C84C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017C850: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017C854: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017C858: swc1        $f4, 0x34($t6)
    MEM_W(0X34, ctx->r14) = ctx->f4.u32l;
    // 0x8017C85C: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8017C860: addiu       $a1, $a1, -0x573C
    ctx->r5 = ADD32(ctx->r5, -0X573C);
    // 0x8017C864: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8017C868: jal         0x80172EC8
    // 0x8017C86C: sw          $t7, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->r15;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017C86C: sw          $t7, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->r15;
    after_0:
    // 0x8017C870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017C874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C878: jr          $ra
    // 0x8017C87C: nop

    return;
    // 0x8017C87C: nop

;}
RECOMP_FUNC void func_ovl8_8037BDF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BDF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037BDF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037BDFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037BE00: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
L_8037BE04:
    // 0x8037BE04: jal         0x8037CFAC
    // 0x8037BE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_8037CFAC(rdram, ctx);
        goto after_0;
    // 0x8037BE08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8037BE0C: jal         0x8000B1E8
    // 0x8037BE10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x8037BE10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8037BE14: b           L_8037BE04
    // 0x8037BE18: nop

        goto L_8037BE04;
    // 0x8037BE18: nop

    // 0x8037BE1C: nop

    // 0x8037BE20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037BE24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037BE28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037BE2C: jr          $ra
    // 0x8037BE30: nop

    return;
    // 0x8037BE30: nop

;}
RECOMP_FUNC void ftCommonGuardGetJointTransform(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801485CC: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x801485D0: lwc1        $f4, 0x30($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X30);
    // 0x801485D4: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x801485D8: lwc1        $f18, 0x34($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X34);
    // 0x801485DC: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x801485E0: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x801485E4: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x801485E8: swc1        $f10, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f10.u32l;
    // 0x801485EC: lwc1        $f2, 0x18($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X18);
    // 0x801485F0: lwc1        $f10, 0x38($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X38);
    // 0x801485F4: sub.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x801485F8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x801485FC: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x80148600: swc1        $f8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f8.u32l;
    // 0x80148604: lwc1        $f14, 0x1C($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80148608: lwc1        $f8, 0x1C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x8014860C: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x80148610: mul.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f12.fl);
    // 0x80148614: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x80148618: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
    // 0x8014861C: lwc1        $f16, 0x8($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80148620: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80148624: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80148628: mul.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8014862C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80148630: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x80148634: lwc1        $f0, 0xC($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80148638: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8014863C: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80148640: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x80148644: add.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x80148648: swc1        $f18, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f18.u32l;
    // 0x8014864C: lwc1        $f2, 0x10($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80148650: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80148654: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80148658: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x8014865C: jr          $ra
    // 0x80148660: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
    return;
    // 0x80148660: swc1        $f10, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f10.u32l;
;}
RECOMP_FUNC void efManagerYoshiEggEscapeMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80103150: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80103154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80103158: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8010315C: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80103160: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103164: addiu       $a0, $a0, -0x19FC
    ctx->r4 = ADD32(ctx->r4, -0X19FC);
    // 0x80103168: jal         0x800FDB1C
    // 0x8010316C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x8010316C: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_0:
    // 0x80103170: bne         $v0, $zero, L_80103180
    if (ctx->r2 != 0) {
        // 0x80103174: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80103180;
    }
    // 0x80103174: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80103178: b           L_801031D0
    // 0x8010317C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801031D0;
    // 0x8010317C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80103180:
    // 0x80103180: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80103184: jal         0x800E90F8
    // 0x80103188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamHideModelPartAll(rdram, ctx);
        goto after_1;
    // 0x80103188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8010318C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80103190: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80103194: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80103198: lbu         $t9, 0x18F($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X18F);
    // 0x8010319C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801031A0: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x801031A4: sb          $t0, 0x18F($a2)
    MEM_B(0X18F, ctx->r6) = ctx->r8;
    // 0x801031A8: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801031AC: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x801031B0: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x801031B4: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801031B8: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x801031BC: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x801031C0: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x801031C4: lw          $t3, 0x84($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X84);
    // 0x801031C8: lw          $t4, 0x8FC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8FC);
    // 0x801031CC: sw          $t4, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r12;
L_801031D0:
    // 0x801031D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801031D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801031D8: jr          $ra
    // 0x801031DC: nop

    return;
    // 0x801031DC: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133014: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133018: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013301C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133020: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133024: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80133028: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8013302C: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80133030: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133034: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133038: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013303C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133040: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133044: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133048: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013304C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133050: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133054: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133058: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013305C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133060: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133064: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133068: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013306C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133070: jal         0x8000B93C
    // 0x80133074: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133074: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133078: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013307C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133080: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133084: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133088: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013308C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133090: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133094: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133098: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013309C: jal         0x80007080
    // 0x801330A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801330A0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801330A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801330A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801330AC: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x801330B0: jal         0x80009968
    // 0x801330B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x801330B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x801330B8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801330BC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801330C0: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x801330C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x801330C8: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801330CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801330D0: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x801330D4: jal         0x80009DF4
    // 0x801330D8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x801330D8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x801330DC: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x801330E0: lw          $t4, -0x7358($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7358);
    // 0x801330E4: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x801330E8: addiu       $t5, $t5, 0x440
    ctx->r13 = ADD32(ctx->r13, 0X440);
    // 0x801330EC: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x801330F0: jal         0x800CCFDC
    // 0x801330F4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801330F4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_4:
    // 0x801330F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801330FC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133100: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x80133104: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80133108: addiu       $t8, $zero, 0x12C
    ctx->r24 = ADD32(0, 0X12C);
    // 0x8013310C: addiu       $t9, $zero, 0xDC
    ctx->r25 = ADD32(0, 0XDC);
    // 0x80133110: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x80133114: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80133118: sb          $t6, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r14;
    // 0x8013311C: sb          $t7, 0x66($v0)
    MEM_B(0X66, ctx->r2) = ctx->r15;
    // 0x80133120: sh          $t8, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r24;
    // 0x80133124: sh          $t9, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r25;
    // 0x80133128: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x8013312C: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80133130: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133134: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80133138: jr          $ra
    // 0x8013313C: nop

    return;
    // 0x8013313C: nop

;}
RECOMP_FUNC void wpLinkBoomerangProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016D714: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016D718: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016D71C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8016D720: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8016D724: lbu         $t7, 0x2A2($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X2A2);
    // 0x8016D728: andi        $t8, $t7, 0x21
    ctx->r24 = ctx->r15 & 0X21;
    // 0x8016D72C: bnel        $t8, $zero, L_8016D76C
    if (ctx->r24 != 0) {
        // 0x8016D730: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016D76C;
    }
    goto skip_0;
    // 0x8016D730: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8016D734: lw          $t9, 0x234($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X234);
    // 0x8016D738: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8016D73C: lui         $a1, 0x40A0
    ctx->r5 = S32(0X40A0 << 16);
    // 0x8016D740: beql        $t9, $zero, L_8016D76C
    if (ctx->r25 == 0) {
        // 0x8016D744: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016D76C;
    }
    goto skip_1;
    // 0x8016D744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8016D748: jal         0x8016CEEC
    // 0x8016D74C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    wpLinkBoomerangSubVelSqrt(rdram, ctx);
        goto after_0;
    // 0x8016D74C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8016D750: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8016D754: jal         0x8016CF48
    // 0x8016D758: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    wpLinkBoomerangUpdateVelLR(rdram, ctx);
        goto after_1;
    // 0x8016D758: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x8016D75C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8016D760: jal         0x8016CDC8
    // 0x8016D764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpLinkBoomerangSetReturnVars(rdram, ctx);
        goto after_2;
    // 0x8016D764: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8016D768: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016D76C:
    // 0x8016D76C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016D770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016D774: jr          $ra
    // 0x8016D778: nop

    return;
    // 0x8016D778: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152B24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152B28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152B2C: jal         0x800D8B94
    // 0x80152B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPhysicsApplyGroundVelTransferAir(rdram, ctx);
        goto after_0;
    // 0x80152B30: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80152B34: jal         0x80152AA0
    // 0x80152B38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPikachuSpecialHiUpdateModelPitchScale(rdram, ctx);
        goto after_1;
    // 0x80152B38: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80152B3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152B40: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152B44: jr          $ra
    // 0x80152B48: nop

    return;
    // 0x80152B48: nop

;}
RECOMP_FUNC void ftCommonDownBounceSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144498: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014449C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801444A0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801444A4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801444A8: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801444AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801444B0: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x801444B4: bne         $t7, $at, L_801444C4
    if (ctx->r15 != ctx->r1) {
        // 0x801444B8: nop
    
            goto L_801444C4;
    }
    // 0x801444B8: nop

    // 0x801444BC: jal         0x800DEE98
    // 0x801444C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801444C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_801444C4:
    // 0x801444C4: jal         0x80144398
    // 0x801444C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonDownBounceCheckUpOrDown(rdram, ctx);
        goto after_1;
    // 0x801444C8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801444CC: beq         $v0, $zero, L_801444DC
    if (ctx->r2 == 0) {
        // 0x801444D0: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_801444DC;
    }
    // 0x801444D0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801444D4: b           L_801444E0
    // 0x801444D8: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
        goto L_801444E0;
    // 0x801444D8: addiu       $a1, $zero, 0x43
    ctx->r5 = ADD32(0, 0X43);
L_801444DC:
    // 0x801444DC: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
L_801444E0:
    // 0x801444E0: addiu       $t8, $zero, 0x100
    ctx->r24 = ADD32(0, 0X100);
    // 0x801444E4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801444E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801444EC: jal         0x800E6F24
    // 0x801444F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x801444F0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x801444F4: jal         0x80144428
    // 0x801444F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonDownBounceUpdateEffects(rdram, ctx);
        goto after_3;
    // 0x801444F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x801444FC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80144500: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80144504: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x80144508: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014450C: jal         0x800E9CE8
    // 0x80144510: swc1        $f4, 0x81C($s0)
    MEM_W(0X81C, ctx->r16) = ctx->f4.u32l;
    ftParamVelDamageTransferGround(rdram, ctx);
        goto after_4;
    // 0x80144510: swc1        $f4, 0x81C($s0)
    MEM_W(0X81C, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x80144514: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80144518: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014451C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80144520: jr          $ra
    // 0x80144524: nop

    return;
    // 0x80144524: nop

;}
RECOMP_FUNC void func_ovl8_8037DE1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037DE1C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8037DE20: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8037DE24: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8037DE28: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8037DE2C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8037DE30: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8037DE34: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8037DE38: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8037DE3C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8037DE40: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8037DE44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037DE48: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8037DE4C: lbu         $a3, 0x0($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X0);
    // 0x8037DE50: lui         $s0, 0x8039
    ctx->r16 = S32(0X8039 << 16);
    // 0x8037DE54: addiu       $s0, $s0, -0x1000
    ctx->r16 = ADD32(ctx->r16, -0X1000);
    // 0x8037DE58: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8037DE5C: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x8037DE60: beq         $a3, $zero, L_8037DF9C
    if (ctx->r7 == 0) {
        // 0x8037DE64: lh          $s6, 0x0($s0)
        ctx->r22 = MEM_H(ctx->r16, 0X0);
            goto L_8037DF9C;
    }
    // 0x8037DE64: lh          $s6, 0x0($s0)
    ctx->r22 = MEM_H(ctx->r16, 0X0);
    // 0x8037DE68: lui         $s5, 0x8039
    ctx->r21 = S32(0X8039 << 16);
    // 0x8037DE6C: lui         $s4, 0x8039
    ctx->r20 = S32(0X8039 << 16);
    // 0x8037DE70: lui         $s1, 0x8039
    ctx->r17 = S32(0X8039 << 16);
    // 0x8037DE74: addiu       $s1, $s1, -0xFF8
    ctx->r17 = ADD32(ctx->r17, -0XFF8);
    // 0x8037DE78: addiu       $s4, $s4, -0xFBA
    ctx->r20 = ADD32(ctx->r20, -0XFBA);
    // 0x8037DE7C: addiu       $s5, $s5, -0xFBC
    ctx->r21 = ADD32(ctx->r21, -0XFBC);
    // 0x8037DE80: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x8037DE84: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
L_8037DE88:
    // 0x8037DE88: bne         $fp, $a3, L_8037DEB0
    if (ctx->r30 != ctx->r7) {
        // 0x8037DE8C: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_8037DEB0;
    }
    // 0x8037DE8C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8037DE90: lh          $t6, 0x2($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X2);
    // 0x8037DE94: lhu         $t7, 0x4($s1)
    ctx->r15 = MEM_HU(ctx->r17, 0X4);
    // 0x8037DE98: lhu         $t9, 0x0($s4)
    ctx->r25 = MEM_HU(ctx->r20, 0X0);
    // 0x8037DE9C: sh          $s6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r22;
    // 0x8037DEA0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8037DEA4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8037DEA8: b           L_8037DF88
    // 0x8037DEAC: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
        goto L_8037DF88;
    // 0x8037DEAC: sh          $t0, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r8;
L_8037DEB0:
    // 0x8037DEB0: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037DEB4: lhu         $t1, -0xFB8($t1)
    ctx->r9 = MEM_HU(ctx->r9, -0XFB8);
    // 0x8037DEB8: andi        $t3, $v0, 0x80
    ctx->r11 = ctx->r2 & 0X80;
    // 0x8037DEBC: andi        $t2, $t1, 0xFF00
    ctx->r10 = ctx->r9 & 0XFF00;
    // 0x8037DEC0: bnel        $t2, $zero, L_8037DF80
    if (ctx->r10 != 0) {
        // 0x8037DEC4: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8037DF80;
    }
    goto skip_0;
    // 0x8037DEC4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_0:
    // 0x8037DEC8: beq         $t3, $zero, L_8037DEE4
    if (ctx->r11 == 0) {
        // 0x8037DECC: lh          $a0, 0x0($s0)
        ctx->r4 = MEM_H(ctx->r16, 0X0);
            goto L_8037DEE4;
    }
    // 0x8037DECC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8037DED0: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x8037DED4: lhu         $t4, -0xFDE($t4)
    ctx->r12 = MEM_HU(ctx->r12, -0XFDE);
    // 0x8037DED8: lhu         $t5, 0x0($s5)
    ctx->r13 = MEM_HU(ctx->r21, 0X0);
    // 0x8037DEDC: b           L_8037DF40
    // 0x8037DEE0: addu        $s3, $t4, $t5
    ctx->r19 = ADD32(ctx->r12, ctx->r13);
        goto L_8037DF40;
    // 0x8037DEE0: addu        $s3, $t4, $t5
    ctx->r19 = ADD32(ctx->r12, ctx->r13);
L_8037DEE4:
    // 0x8037DEE4: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x8037DEE8: bne         $at, $zero, L_8037DEF4
    if (ctx->r1 != 0) {
        // 0x8037DEEC: slti        $at, $v0, 0x7F
        ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
            goto L_8037DEF4;
    }
    // 0x8037DEEC: slti        $at, $v0, 0x7F
    ctx->r1 = SIGNED(ctx->r2) < 0X7F ? 1 : 0;
    // 0x8037DEF0: bne         $at, $zero, L_8037DF04
    if (ctx->r1 != 0) {
        // 0x8037DEF4: slti        $at, $v0, 0xA0
        ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
            goto L_8037DF04;
    }
L_8037DEF4:
    // 0x8037DEF4: slti        $at, $v0, 0xA0
    ctx->r1 = SIGNED(ctx->r2) < 0XA0 ? 1 : 0;
    // 0x8037DEF8: bne         $at, $zero, L_8037DF40
    if (ctx->r1 != 0) {
        // 0x8037DEFC: slti        $at, $v0, 0xE0
        ctx->r1 = SIGNED(ctx->r2) < 0XE0 ? 1 : 0;
            goto L_8037DF40;
    }
    // 0x8037DEFC: slti        $at, $v0, 0xE0
    ctx->r1 = SIGNED(ctx->r2) < 0XE0 ? 1 : 0;
    // 0x8037DF00: beq         $at, $zero, L_8037DF40
    if (ctx->r1 == 0) {
        // 0x8037DF04: slti        $at, $v0, 0xA1
        ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
            goto L_8037DF40;
    }
L_8037DF04:
    // 0x8037DF04: slti        $at, $v0, 0xA1
    ctx->r1 = SIGNED(ctx->r2) < 0XA1 ? 1 : 0;
    // 0x8037DF08: bne         $at, $zero, L_8037DF18
    if (ctx->r1 != 0) {
        // 0x8037DF0C: addiu       $v1, $v0, -0x20
        ctx->r3 = ADD32(ctx->r2, -0X20);
            goto L_8037DF18;
    }
    // 0x8037DF0C: addiu       $v1, $v0, -0x20
    ctx->r3 = ADD32(ctx->r2, -0X20);
    // 0x8037DF10: b           L_8037DF18
    // 0x8037DF14: addiu       $v1, $v0, -0x41
    ctx->r3 = ADD32(ctx->r2, -0X41);
        goto L_8037DF18;
    // 0x8037DF14: addiu       $v1, $v0, -0x41
    ctx->r3 = ADD32(ctx->r2, -0X41);
L_8037DF18:
    // 0x8037DF18: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x8037DF1C: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x8037DF20: lhu         $t8, 0x2($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X2);
    // 0x8037DF24: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8037DF28: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x8037DF2C: lbu         $t1, 0x1($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X1);
    // 0x8037DF30: lhu         $t3, 0x0($s5)
    ctx->r11 = MEM_HU(ctx->r21, 0X0);
    // 0x8037DF34: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8037DF38: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8037DF3C: addu        $s3, $t2, $t3
    ctx->r19 = ADD32(ctx->r10, ctx->r11);
L_8037DF40:
    // 0x8037DF40: lh          $t5, 0x0($s7)
    ctx->r13 = MEM_H(ctx->r23, 0X0);
    // 0x8037DF44: lhu         $t6, 0x4($s7)
    ctx->r14 = MEM_HU(ctx->r23, 0X4);
    // 0x8037DF48: addu        $t4, $a0, $s3
    ctx->r12 = ADD32(ctx->r4, ctx->r19);
    // 0x8037DF4C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8037DF50: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8037DF54: bnel        $at, $zero, L_8037DF80
    if (ctx->r1 != 0) {
        // 0x8037DF58: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_8037DF80;
    }
    goto skip_1;
    // 0x8037DF58: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    skip_1:
    // 0x8037DF5C: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x8037DF60: lhu         $t9, 0x4($s1)
    ctx->r25 = MEM_HU(ctx->r17, 0X4);
    // 0x8037DF64: lhu         $t1, 0x0($s4)
    ctx->r9 = MEM_HU(ctx->r20, 0X0);
    // 0x8037DF68: sh          $s6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r22;
    // 0x8037DF6C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8037DF70: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x8037DF74: sh          $t2, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r10;
    // 0x8037DF78: lbu         $a3, 0x0($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X0);
    // 0x8037DF7C: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8037DF80:
    // 0x8037DF80: jal         0x8037DAA0
    // 0x8037DF84: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_ovl8_8037DAA0(rdram, ctx);
        goto after_0;
    // 0x8037DF84: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_0:
L_8037DF88:
    // 0x8037DF88: lbu         $a3, 0x1($s2)
    ctx->r7 = MEM_BU(ctx->r18, 0X1);
    // 0x8037DF8C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8037DF90: bne         $a3, $zero, L_8037DE88
    if (ctx->r7 != 0) {
        // 0x8037DF94: nop
    
            goto L_8037DE88;
    }
    // 0x8037DF94: nop

    // 0x8037DF98: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
L_8037DF9C:
    // 0x8037DF9C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8037DFA0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037DFA4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8037DFA8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8037DFAC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8037DFB0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8037DFB4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8037DFB8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8037DFBC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8037DFC0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8037DFC4: jr          $ra
    // 0x8037DFC8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8037DFC8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mvOpeningDonkeyMakePosedFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DBF0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DBF4: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DBF8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DBFC: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DC00: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018DC04: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DC08: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8018DC0C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DC10: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DC14: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DC18: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DC1C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8018DC20: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8018DC24: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DC28: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DC2C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DC30: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DC34: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DC38: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DC3C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DC40: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DC44: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DC48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DC4C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DC50: jal         0x8000B93C
    // 0x8018DC54: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DC54: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DC58: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8018DC5C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DC60: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DC64: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DC68: lui         $a1, 0x4352
    ctx->r5 = S32(0X4352 << 16);
    // 0x8018DC6C: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8018DC70: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DC74: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DC78: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8018DC7C: jal         0x80007080
    // 0x8018DC80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DC80: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DC84: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DC88: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8018DC8C: lwc1        $f6, -0x1E4C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1E4C);
    // 0x8018DC90: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018DC94: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x8018DC98: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8018DC9C: lw          $t4, -0x1C1C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1C1C);
    // 0x8018DCA0: addiu       $t5, $t5, 0x30
    ctx->r13 = ADD32(ctx->r13, 0X30);
    // 0x8018DCA4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018DCA8: jal         0x8000FA3C
    // 0x8018DCAC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8018DCAC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x8018DCB0: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8018DCB4: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8018DCB8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8018DCBC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DCC0: jal         0x80008188
    // 0x8018DCC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018DCC4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018DCC8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DCCC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DCD0: jr          $ra
    // 0x8018DCD4: nop

    return;
    // 0x8018DCD4: nop

;}
RECOMP_FUNC void itKamexAttackSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180AF4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80180AF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180AFC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80180B00: addiu       $a1, $a1, -0x50EC
    ctx->r5 = ADD32(ctx->r5, -0X50EC);
    // 0x80180B04: jal         0x80172EC8
    // 0x80180B08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80180B08: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80180B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180B10: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80180B14: jr          $ra
    // 0x80180B18: nop

    return;
    // 0x80180B18: nop

;}
RECOMP_FUNC void itHitokageCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183F94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80183F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80183F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80183FA0: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80183FA4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80183FA8: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80183FAC: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80183FB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80183FB4: lwc1        $f0, 0x294($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X294);
    // 0x80183FB8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80183FBC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80183FC0: nop

    // 0x80183FC4: bc1fl       L_80184048
    if (!c1cs) {
        // 0x80183FC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80184048;
    }
    goto skip_0;
    // 0x80183FC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80183FCC: lw          $a0, 0x29C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X29C);
    // 0x80183FD0: lw          $a1, 0x108($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X108);
    // 0x80183FD4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80183FD8: jal         0x801409BC
    // 0x80183FDC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    ftCommonDamageGetKnockbackAngle(rdram, ctx);
        goto after_0;
    // 0x80183FDC: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x80183FE0: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80183FE4: jal         0x80035CD0
    // 0x80183FE8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80183FE8: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80183FEC: lw          $t7, 0x2A4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2A4);
    // 0x80183FF0: lwc1        $f6, 0x294($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X294);
    // 0x80183FF4: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x80183FF8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x80183FFC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80184000: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80184004: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80184008: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8018400C: jal         0x800303F0
    // 0x80184010: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80184010: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80184014: lwc1        $f4, 0x294($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X294);
    // 0x80184018: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x8018401C: sw          $zero, 0x248($s0)
    MEM_W(0X248, ctx->r16) = 0;
    // 0x80184020: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80184024: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80184028: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x8018402C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80184030: lwc1        $f10, -0x30E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X30E8);
    // 0x80184034: jal         0x8010B0AC
    // 0x80184038: swc1        $f10, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->f10.u32l;
    grYamabukiGateClearMonsterGObj(rdram, ctx);
        goto after_3;
    // 0x80184038: swc1        $f10, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->f10.u32l;
    after_3:
    // 0x8018403C: jal         0x80183DA0
    // 0x80184040: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    itHitokageDamagedSetStatus(rdram, ctx);
        goto after_4;
    // 0x80184040: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x80184044: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80184048:
    // 0x80184048: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018404C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80184050: jr          $ra
    // 0x80184054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80184054: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ftCommonShieldBreakDownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801496A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801496A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801496AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801496B0: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801496B4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801496B8: lw          $t7, 0x14C($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14C);
    // 0x801496BC: bne         $t7, $at, L_801496CC
    if (ctx->r15 != ctx->r1) {
        // 0x801496C0: nop
    
            goto L_801496CC;
    }
    // 0x801496C0: nop

    // 0x801496C4: jal         0x800DEE98
    // 0x801496C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801496C8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
L_801496CC:
    // 0x801496CC: jal         0x80144398
    // 0x801496D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonDownBounceCheckUpOrDown(rdram, ctx);
        goto after_1;
    // 0x801496D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801496D4: beq         $v0, $zero, L_801496E4
    if (ctx->r2 == 0) {
        // 0x801496D8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801496E4;
    }
    // 0x801496D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801496DC: b           L_801496E8
    // 0x801496E0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
        goto L_801496E8;
    // 0x801496E0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
L_801496E4:
    // 0x801496E4: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
L_801496E8:
    // 0x801496E8: addiu       $t8, $zero, 0xB2
    ctx->r24 = ADD32(0, 0XB2);
    // 0x801496EC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x801496F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801496F4: jal         0x800E6F24
    // 0x801496F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x801496F8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x801496FC: jal         0x80144428
    // 0x80149700: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonDownBounceUpdateEffects(rdram, ctx);
        goto after_3;
    // 0x80149700: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80149704: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80149708: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014970C: jr          $ra
    // 0x80149710: nop

    return;
    // 0x80149710: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingPuckProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135DD8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80135DDC: lw          $t6, -0x7774($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X7774);
    // 0x80135DE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80135DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135DE8: slti        $at, $t6, 0x1E
    ctx->r1 = SIGNED(ctx->r14) < 0X1E ? 1 : 0;
    // 0x80135DEC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80135DF0: beq         $at, $zero, L_80135E30
    if (ctx->r1 == 0) {
        // 0x80135DF4: lw          $a2, 0x84($a0)
        ctx->r6 = MEM_W(ctx->r4, 0X84);
            goto L_80135E30;
    }
    // 0x80135DF4: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x80135DF8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80135DFC: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80135E00: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80135E04: subu        $t8, $t8, $a2
    ctx->r24 = SUB32(ctx->r24, ctx->r6);
    // 0x80135E08: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80135E0C: addiu       $t9, $t9, -0x7AA8
    ctx->r25 = ADD32(ctx->r25, -0X7AA8);
    // 0x80135E10: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x80135E14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80135E18: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80135E1C: addiu       $a3, $a3, -0x7AA8
    ctx->r7 = ADD32(ctx->r7, -0X7AA8);
    // 0x80135E20: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    // 0x80135E24: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x80135E28: b           L_80135E98
    // 0x80135E2C: addiu       $t0, $zero, 0xB8
    ctx->r8 = ADD32(0, 0XB8);
        goto L_80135E98;
    // 0x80135E2C: addiu       $t0, $zero, 0xB8
    ctx->r8 = ADD32(0, 0XB8);
L_80135E30:
    // 0x80135E30: addiu       $t0, $zero, 0xB8
    ctx->r8 = ADD32(0, 0XB8);
    // 0x80135E34: multu       $a2, $t0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135E38: lui         $a3, 0x8014
    ctx->r7 = S32(0X8014 << 16);
    // 0x80135E3C: addiu       $a3, $a3, -0x7AA8
    ctx->r7 = ADD32(ctx->r7, -0X7AA8);
    // 0x80135E40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135E44: mflo        $t1
    ctx->r9 = lo;
    // 0x80135E48: addu        $v1, $a3, $t1
    ctx->r3 = ADD32(ctx->r7, ctx->r9);
    // 0x80135E4C: lw          $v0, 0x80($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X80);
    // 0x80135E50: beq         $v0, $at, L_80135E8C
    if (ctx->r2 == ctx->r1) {
        // 0x80135E54: nop
    
            goto L_80135E8C;
    }
    // 0x80135E54: nop

    // 0x80135E58: bne         $v0, $zero, L_80135E94
    if (ctx->r2 != 0) {
        // 0x80135E5C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_80135E94;
    }
    // 0x80135E5C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80135E60: lw          $t2, 0x50($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X50);
    // 0x80135E64: bne         $t2, $zero, L_80135E8C
    if (ctx->r10 != 0) {
        // 0x80135E68: nop
    
            goto L_80135E8C;
    }
    // 0x80135E68: nop

    // 0x80135E6C: lw          $t3, 0x54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X54);
    // 0x80135E70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135E74: beq         $t3, $at, L_80135E8C
    if (ctx->r11 == ctx->r1) {
        // 0x80135E78: nop
    
            goto L_80135E8C;
    }
    // 0x80135E78: nop

    // 0x80135E7C: lw          $t4, 0x58($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X58);
    // 0x80135E80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135E84: bnel        $t4, $at, L_80135E98
    if (ctx->r12 != ctx->r1) {
        // 0x80135E88: sw          $t5, 0x7C($a1)
        MEM_W(0X7C, ctx->r5) = ctx->r13;
            goto L_80135E98;
    }
    goto skip_0;
    // 0x80135E88: sw          $t5, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->r13;
    skip_0:
L_80135E8C:
    // 0x80135E8C: b           L_80135E98
    // 0x80135E90: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
        goto L_80135E98;
    // 0x80135E90: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
L_80135E94:
    // 0x80135E94: sw          $t5, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->r13;
L_80135E98:
    // 0x80135E98: lw          $t6, 0x80($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X80);
    // 0x80135E9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80135EA0: beql        $t6, $at, L_80135FDC
    if (ctx->r14 == ctx->r1) {
        // 0x80135EA4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80135FDC;
    }
    goto skip_1;
    // 0x80135EA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80135EA8: lw          $t7, 0x54($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X54);
    // 0x80135EAC: bnel        $t7, $zero, L_80135F38
    if (ctx->r15 != 0) {
        // 0x80135EB0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80135F38;
    }
    goto skip_2;
    // 0x80135EB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_2:
    // 0x80135EB4: lw          $a0, 0x78($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X78);
    // 0x80135EB8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80135EBC: beql        $a0, $at, L_80135F38
    if (ctx->r4 == ctx->r1) {
        // 0x80135EC0: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80135F38;
    }
    goto skip_3;
    // 0x80135EC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_3:
    // 0x80135EC4: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135EC8: mflo        $t8
    ctx->r24 = lo;
    // 0x80135ECC: addu        $v0, $a3, $t8
    ctx->r2 = ADD32(ctx->r7, ctx->r24);
    // 0x80135ED0: lw          $t9, 0x9C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X9C);
    // 0x80135ED4: bne         $t9, $zero, L_80135F2C
    if (ctx->r25 != 0) {
        // 0x80135ED8: nop
    
            goto L_80135F2C;
    }
    // 0x80135ED8: nop

    // 0x80135EDC: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80135EE0: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80135EE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135EE8: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x80135EEC: lw          $t3, 0x74($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X74);
    // 0x80135EF0: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x80135EF4: lwc1        $f4, 0x58($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X58);
    // 0x80135EF8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80135EFC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135F00: swc1        $f8, 0x58($t3)
    MEM_W(0X58, ctx->r11) = ctx->f8.u32l;
    // 0x80135F04: lw          $t4, 0x78($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X78);
    // 0x80135F08: lw          $t9, 0x74($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X74);
    // 0x80135F0C: multu       $t4, $t0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135F10: mflo        $t5
    ctx->r13 = lo;
    // 0x80135F14: addu        $t6, $a3, $t5
    ctx->r14 = ADD32(ctx->r7, ctx->r13);
    // 0x80135F18: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80135F1C: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x80135F20: lwc1        $f10, 0x5C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X5C);
    // 0x80135F24: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80135F28: swc1        $f18, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f18.u32l;
L_80135F2C:
    // 0x80135F2C: b           L_80135F48
    // 0x80135F30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
        goto L_80135F48;
    // 0x80135F30: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80135F34: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80135F38:
    // 0x80135F38: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80135F3C: jal         0x80135D84
    // 0x80135F40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    mnPlayers1PTrainingMovePuck(rdram, ctx);
        goto after_0;
    // 0x80135F40: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x80135F44: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_80135F48:
    // 0x80135F48: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80135F4C: jal         0x80134EE8
    // 0x80135F50: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mnPlayers1PTrainingGetPuckFighterKind(rdram, ctx);
        goto after_1;
    // 0x80135F50: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80135F54: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80135F58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135F5C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80135F60: lw          $t1, 0x80($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X80);
    // 0x80135F64: bnel        $t1, $at, L_80135FB0
    if (ctx->r9 != ctx->r1) {
        // 0x80135F68: lw          $t3, 0x54($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X54);
            goto L_80135FB0;
    }
    goto skip_4;
    // 0x80135F68: lw          $t3, 0x54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X54);
    skip_4:
    // 0x80135F6C: lw          $t2, 0x48($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X48);
    // 0x80135F70: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80135F74: beql        $v0, $t2, L_80135FB0
    if (ctx->r2 == ctx->r10) {
        // 0x80135F78: lw          $t3, 0x54($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X54);
            goto L_80135FB0;
    }
    goto skip_5;
    // 0x80135F78: lw          $t3, 0x54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X54);
    skip_5:
    // 0x80135F7C: bnel        $v0, $at, L_80135FB0
    if (ctx->r2 != ctx->r1) {
        // 0x80135F80: lw          $t3, 0x54($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X54);
            goto L_80135FB0;
    }
    goto skip_6;
    // 0x80135F80: lw          $t3, 0x54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X54);
    skip_6:
    // 0x80135F84: lw          $a0, 0x78($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X78);
    // 0x80135F88: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80135F8C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80135F90: beql        $a0, $at, L_80135FB0
    if (ctx->r4 == ctx->r1) {
        // 0x80135F94: lw          $t3, 0x54($v1)
        ctx->r11 = MEM_W(ctx->r3, 0X54);
            goto L_80135FB0;
    }
    goto skip_7;
    // 0x80135F94: lw          $t3, 0x54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X54);
    skip_7:
    // 0x80135F98: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80135F9C: jal         0x80131B58
    // 0x80135FA0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    mnPlayers1PTrainingSelectFighterPuck(rdram, ctx);
        goto after_2;
    // 0x80135FA0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80135FA4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80135FA8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80135FAC: lw          $t3, 0x54($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X54);
L_80135FB0:
    // 0x80135FB0: bnel        $t3, $zero, L_80135FDC
    if (ctx->r11 != 0) {
        // 0x80135FB4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80135FDC;
    }
    goto skip_8;
    // 0x80135FB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80135FB8: lw          $t4, 0x48($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X48);
    // 0x80135FBC: beql        $a2, $t4, L_80135FDC
    if (ctx->r6 == ctx->r12) {
        // 0x80135FC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80135FDC;
    }
    goto skip_9;
    // 0x80135FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x80135FC4: sw          $a2, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->r6;
    // 0x80135FC8: jal         0x80133E30
    // 0x80135FCC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnPlayers1PTrainingUpdateFighter(rdram, ctx);
        goto after_3;
    // 0x80135FCC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80135FD0: jal         0x80133EE0
    // 0x80135FD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnPlayers1PTrainingUpdateNameAndEmblem(rdram, ctx);
        goto after_4;
    // 0x80135FD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x80135FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80135FDC:
    // 0x80135FDC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80135FE0: jr          $ra
    // 0x80135FE4: nop

    return;
    // 0x80135FE4: nop

;}
RECOMP_FUNC void ftKirbySpecialHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801611A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801611AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801611B0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801611B4: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801611B8: addiu       $t6, $t6, 0x1194
    ctx->r14 = ADD32(ctx->r14, 0X1194);
    // 0x801611BC: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x801611C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801611C4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801611C8: addiu       $a1, $zero, 0x100
    ctx->r5 = ADD32(0, 0X100);
    // 0x801611CC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801611D0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801611D4: jal         0x800E6F24
    // 0x801611D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801611D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801611DC: jal         0x800E0830
    // 0x801611E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801611E0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801611E4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801611E8: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x801611EC: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x801611F0: addiu       $t7, $t7, -0x6374
    ctx->r15 = ADD32(ctx->r15, -0X6374);
    // 0x801611F4: addiu       $t8, $t8, -0x633C
    ctx->r24 = ADD32(ctx->r24, -0X633C);
    // 0x801611F8: sw          $t7, 0xA04($v0)
    MEM_W(0XA04, ctx->r2) = ctx->r15;
    // 0x801611FC: sw          $t8, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->r24;
    // 0x80161200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80161204: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80161208: jr          $ra
    // 0x8016120C: nop

    return;
    // 0x8016120C: nop

;}
RECOMP_FUNC void mpCollisionSetDObjNoID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC72C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC730: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC734: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FC738: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FC73C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC740: beq         $a0, $at, L_800FC754
    if (ctx->r4 == ctx->r1) {
        // 0x800FC744: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FC754;
    }
    // 0x800FC744: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC748: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FC74C: bne         $a0, $at, L_800FC778
    if (ctx->r4 != ctx->r1) {
        // 0x800FC750: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FC778;
    }
    // 0x800FC750: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FC754:
    // 0x800FC754: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC758: addiu       $s0, $s0, 0x720
    ctx->r16 = ADD32(ctx->r16, 0X720);
    // 0x800FC75C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FC760:
    // 0x800FC760: jal         0x80023624
    // 0x800FC764: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FC764: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FC768: jal         0x800A3040
    // 0x800FC76C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FC76C: nop

    after_1:
    // 0x800FC770: b           L_800FC760
    // 0x800FC774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FC760;
    // 0x800FC774: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FC778:
    // 0x800FC778: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FC77C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FC780: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FC784: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC788: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FC78C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800FC790: lbu         $v0, 0x0($t8)
    ctx->r2 = MEM_BU(ctx->r24, 0X0);
    // 0x800FC794: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC798: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC79C: jr          $ra
    // 0x800FC7A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FC7A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mvOpeningPikachuFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DDC0: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DDC4: addiu       $v0, $v0, -0x1DD8
    ctx->r2 = ADD32(ctx->r2, -0X1DD8);
    // 0x8018DDC8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DDCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DDD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DDD4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018DDD8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018DDDC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DDE0: jal         0x8039076C
    // 0x8018DDE4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x8018DDE4: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x8018DDE8: beq         $v0, $zero, L_8018DE08
    if (ctx->r2 == 0) {
        // 0x8018DDEC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018DE08;
    }
    // 0x8018DDEC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DDF0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DDF4: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DDF8: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DDFC: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8018DE00: jal         0x80005C74
    // 0x8018DE04: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8018DE04: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_1:
L_8018DE08:
    // 0x8018DE08: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE0C: lw          $v0, -0x1DD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1DD8);
    // 0x8018DE10: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018DE14: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DE18: bnel        $v0, $at, L_8018DE4C
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE1C: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_8018DE4C;
    }
    goto skip_0;
    // 0x8018DE1C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_0:
    // 0x8018DE20: jal         0x80009A84
    // 0x8018DE24: lw          $a0, -0x1DD4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DD4);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8018DE24: lw          $a0, -0x1DD4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1DD4);
    after_2:
    // 0x8018DE28: jal         0x8018D634
    // 0x8018DE2C: nop

    mvOpeningPikachuMakeMotionWindow(rdram, ctx);
        goto after_3;
    // 0x8018DE2C: nop

    after_3:
    // 0x8018DE30: jal         0x8018D964
    // 0x8018DE34: nop

    mvOpeningPikachuMakePosedWallpaper(rdram, ctx);
        goto after_4;
    // 0x8018DE34: nop

    after_4:
    // 0x8018DE38: jal         0x8018DA80
    // 0x8018DE3C: nop

    mvOpeningPikachuMakePosedFighter(rdram, ctx);
        goto after_5;
    // 0x8018DE3C: nop

    after_5:
    // 0x8018DE40: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE44: lw          $v0, -0x1DD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1DD8);
    // 0x8018DE48: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_8018DE4C:
    // 0x8018DE4C: bne         $v0, $at, L_8018DE6C
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE50: addiu       $t1, $zero, 0x26
        ctx->r9 = ADD32(0, 0X26);
            goto L_8018DE6C;
    }
    // 0x8018DE50: addiu       $t1, $zero, 0x26
    ctx->r9 = ADD32(0, 0X26);
    // 0x8018DE54: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE58: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DE5C: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DE60: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8018DE64: jal         0x80005C74
    // 0x8018DE68: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x8018DE68: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_6:
L_8018DE6C:
    // 0x8018DE6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DE70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DE74: jr          $ra
    // 0x8018DE78: nop

    return;
    // 0x8018DE78: nop

;}
RECOMP_FUNC void func_ovl29_80131F6C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F6C: jr          $ra
    // 0x80131F70: nop

    return;
    // 0x80131F70: nop

;}
RECOMP_FUNC void itEggThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801817F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801817FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181800: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80181804: jal         0x801737B8
    // 0x80181808: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80181808: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    after_0:
    // 0x8018180C: beql        $v0, $zero, L_80181844
    if (ctx->r2 == 0) {
        // 0x80181810: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80181844;
    }
    goto skip_0;
    // 0x80181810: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80181814: jal         0x801730D4
    // 0x80181818: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainMakeContainerItem(rdram, ctx);
        goto after_1;
    // 0x80181818: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8018181C: beq         $v0, $zero, L_80181838
    if (ctx->r2 == 0) {
        // 0x80181820: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80181838;
    }
    // 0x80181820: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80181824: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x80181828: jal         0x801041A0
    // 0x8018182C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerEggBreakMakeEffect(rdram, ctx);
        goto after_2;
    // 0x8018182C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_2:
    // 0x80181830: b           L_80181844
    // 0x80181834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80181844;
    // 0x80181834: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80181838:
    // 0x80181838: jal         0x80181B90
    // 0x8018183C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itEggExplodeMakeEffectGotoSetStatus(rdram, ctx);
        goto after_3;
    // 0x8018183C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80181840: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80181844:
    // 0x80181844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018184C: jr          $ra
    // 0x80181850: nop

    return;
    // 0x80181850: nop

;}
RECOMP_FUNC void ftKirbySpecialLwHoldProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016174C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80161750: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80161754: jal         0x801616F0
    // 0x80161758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftKirbySpecialLwHoldDecideNextStatus(rdram, ctx);
        goto after_0;
    // 0x80161758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8016175C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80161760: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80161764: jr          $ra
    // 0x80161768: nop

    return;
    // 0x80161768: nop

;}
RECOMP_FUNC void sc1PGameBossSetupBackgroundDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80192078: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8019207C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80192080: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80192084: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80192088: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8019208C: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80192090: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x80192094: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x80192098: andi        $fp, $a3, 0xFF
    ctx->r30 = ctx->r7 & 0XFF;
    // 0x8019209C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801920A0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x801920A4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x801920A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801920AC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801920B0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801920B4: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x801920B8: sw          $zero, 0x50($sp)
    MEM_W(0X50, ctx->r29) = 0;
    // 0x801920BC: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x801920C0: addiu       $v0, $sp, 0x58
    ctx->r2 = ADD32(ctx->r29, 0X58);
    // 0x801920C4: addiu       $v1, $sp, 0x98
    ctx->r3 = ADD32(ctx->r29, 0X98);
L_801920C8:
    // 0x801920C8: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801920CC: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x801920D0: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x801920D4: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801920D8: bne         $v0, $v1, L_801920C8
    if (ctx->r2 != ctx->r3) {
        // 0x801920DC: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_801920C8;
    }
    // 0x801920DC: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x801920E0: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x801920E4: addiu       $s6, $zero, 0x12
    ctx->r22 = ADD32(0, 0X12);
    // 0x801920E8: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x801920EC: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x801920F0: beql        $s6, $v0, L_80192210
    if (ctx->r22 == ctx->r2) {
        // 0x801920F4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80192210;
    }
    goto skip_0;
    // 0x801920F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_0:
L_801920F8:
    // 0x801920F8: beq         $v0, $zero, L_8019211C
    if (ctx->r2 == 0) {
        // 0x801920FC: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8019211C;
    }
    // 0x801920FC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80192100: addu        $s0, $s5, $t6
    ctx->r16 = ADD32(ctx->r21, ctx->r14);
    // 0x80192104: lw          $a0, -0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, -0X4);
    // 0x80192108: jal         0x800093F4
    // 0x8019210C: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x8019210C: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    after_0:
    // 0x80192110: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80192114: b           L_80192130
    // 0x80192118: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
        goto L_80192130;
    // 0x80192118: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8019211C:
    // 0x8019211C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80192120: jal         0x800092D0
    // 0x80192124: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80192124: lw          $a1, 0x4($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X4);
    after_1:
    // 0x80192128: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8019212C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_80192130:
    // 0x80192130: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80192134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80192138: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8019213C: andi        $v0, $v0, 0xF000
    ctx->r2 = ctx->r2 & 0XF000;
    // 0x80192140: beq         $v0, $zero, L_8019216C
    if (ctx->r2 == 0) {
        // 0x80192144: andi        $a1, $fp, 0xFF
        ctx->r5 = ctx->r30 & 0XFF;
            goto L_8019216C;
    }
    // 0x80192144: andi        $a1, $fp, 0xFF
    ctx->r5 = ctx->r30 & 0XFF;
    // 0x80192148: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8019214C: jal         0x80008CC0
    // 0x80192150: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80192150: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_2:
    // 0x80192154: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80192158: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x8019215C: jal         0x80008CC0
    // 0x80192160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x80192160: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80192164: b           L_80192178
    // 0x80192168: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
        goto L_80192178;
    // 0x80192168: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
L_8019216C:
    // 0x8019216C: jal         0x80008CC0
    // 0x80192170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x80192170: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80192174: lw          $t8, 0x8($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X8);
L_80192178:
    // 0x80192178: sw          $t8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r24;
    // 0x8019217C: lw          $t7, 0xC($s3)
    ctx->r15 = MEM_W(ctx->r19, 0XC);
    // 0x80192180: sw          $t7, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r15;
    // 0x80192184: lw          $t8, 0x10($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X10);
    // 0x80192188: sw          $t8, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r24;
    // 0x8019218C: lw          $t0, 0x14($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X14);
    // 0x80192190: sw          $t0, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r8;
    // 0x80192194: lw          $t9, 0x18($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X18);
    // 0x80192198: sw          $t9, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r25;
    // 0x8019219C: lw          $t0, 0x1C($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X1C);
    // 0x801921A0: sw          $t0, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r8;
    // 0x801921A4: lw          $t2, 0x20($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X20);
    // 0x801921A8: sw          $t2, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r10;
    // 0x801921AC: lw          $t1, 0x24($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X24);
    // 0x801921B0: sw          $t1, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->r9;
    // 0x801921B4: lw          $t2, 0x28($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X28);
    // 0x801921B8: beq         $s4, $zero, L_801921F8
    if (ctx->r20 == 0) {
        // 0x801921BC: sw          $t2, 0x48($s2)
        MEM_W(0X48, ctx->r18) = ctx->r10;
            goto L_801921F8;
    }
    // 0x801921BC: sw          $t2, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->r10;
    // 0x801921C0: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x801921C4: beql        $v0, $zero, L_801921F8
    if (ctx->r2 == 0) {
        // 0x801921C8: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_801921F8;
    }
    goto skip_1;
    // 0x801921C8: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    skip_1:
    // 0x801921CC: lw          $s1, 0x0($v0)
    ctx->r17 = MEM_W(ctx->r2, 0X0);
    // 0x801921D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801921D4: beq         $s1, $zero, L_801921F4
    if (ctx->r17 == 0) {
        // 0x801921D8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801921F4;
    }
    // 0x801921D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_801921DC:
    // 0x801921DC: jal         0x800090DC
    // 0x801921E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    gcAddMObjForDObj(rdram, ctx);
        goto after_5;
    // 0x801921E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x801921E4: lw          $s1, 0x4($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X4);
    // 0x801921E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x801921EC: bnel        $s1, $zero, L_801921DC
    if (ctx->r17 != 0) {
        // 0x801921F0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_801921DC;
    }
    goto skip_2;
    // 0x801921F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_2:
L_801921F4:
    // 0x801921F4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
L_801921F8:
    // 0x801921F8: lw          $v0, 0x2C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X2C);
    // 0x801921FC: addiu       $s3, $s3, 0x2C
    ctx->r19 = ADD32(ctx->r19, 0X2C);
    // 0x80192200: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x80192204: bne         $s6, $v0, L_801920F8
    if (ctx->r22 != ctx->r2) {
        // 0x80192208: nop
    
            goto L_801920F8;
    }
    // 0x80192208: nop

    // 0x8019220C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80192210:
    // 0x80192210: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80192214: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80192218: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8019221C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80192220: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80192224: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80192228: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8019222C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80192230: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80192234: jr          $ra
    // 0x80192238: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80192238: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void ftCommonReboundSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144A60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80144A64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80144A68: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80144A6C: addiu       $a1, $zero, 0x53
    ctx->r5 = ADD32(0, 0X53);
    // 0x80144A70: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80144A74: lw          $a3, 0xB18($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XB18);
    // 0x80144A78: jal         0x800E6F24
    // 0x80144A7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80144A7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x80144A80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80144A84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80144A88: jr          $ra
    // 0x80144A8C: nop

    return;
    // 0x80144A8C: nop

;}
RECOMP_FUNC void sc1PTrainingModeInitStatDisplayCharacterSprites(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E21C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018E220: addiu       $a1, $a1, 0xB58
    ctx->r5 = ADD32(ctx->r5, 0XB58);
    // 0x8018E224: lw          $t6, 0x28($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X28);
    // 0x8018E228: addiu       $a2, $zero, 0x6C
    ctx->r6 = ADD32(0, 0X6C);
    // 0x8018E22C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8018E230: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8018E234: addiu       $t0, $zero, 0x201
    ctx->r8 = ADD32(0, 0X201);
    // 0x8018E238: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x8018E23C: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    // 0x8018E240: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018E244: sb          $a3, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r7;
    // 0x8018E248: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018E24C: lw          $t7, 0x28($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X28);
    // 0x8018E250: addiu       $v0, $zero, 0x9C
    ctx->r2 = ADD32(0, 0X9C);
    // 0x8018E254: lw          $v1, 0x4($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X4);
    // 0x8018E258: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018E25C: sb          $a3, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r7;
    // 0x8018E260: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018E264: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    // 0x8018E268: lw          $t8, 0x28($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X28);
    // 0x8018E26C: lw          $v1, 0x8($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X8);
    // 0x8018E270: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018E274: sb          $a3, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r7;
    // 0x8018E278: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018E27C: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
L_8018E280:
    // 0x8018E280: lw          $t9, 0x28($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X28);
    // 0x8018E284: addu        $t1, $t9, $a0
    ctx->r9 = ADD32(ctx->r25, ctx->r4);
    // 0x8018E288: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8018E28C: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018E290: sb          $a3, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r7;
    // 0x8018E294: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018E298: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    // 0x8018E29C: lw          $t2, 0x28($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X28);
    // 0x8018E2A0: addu        $t3, $t2, $a0
    ctx->r11 = ADD32(ctx->r10, ctx->r4);
    // 0x8018E2A4: lw          $v1, 0x4($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X4);
    // 0x8018E2A8: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018E2AC: sb          $a3, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r7;
    // 0x8018E2B0: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018E2B4: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    // 0x8018E2B8: lw          $t4, 0x28($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X28);
    // 0x8018E2BC: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x8018E2C0: lw          $v1, 0x8($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X8);
    // 0x8018E2C4: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018E2C8: sb          $a3, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r7;
    // 0x8018E2CC: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018E2D0: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    // 0x8018E2D4: lw          $t6, 0x28($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X28);
    // 0x8018E2D8: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8018E2DC: lw          $v1, 0xC($t7)
    ctx->r3 = MEM_W(ctx->r15, 0XC);
    // 0x8018E2E0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8018E2E4: sb          $a2, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r6;
    // 0x8018E2E8: sb          $a3, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r7;
    // 0x8018E2EC: sb          $a2, 0x1A($v1)
    MEM_B(0X1A, ctx->r3) = ctx->r6;
    // 0x8018E2F0: bne         $a0, $v0, L_8018E280
    if (ctx->r4 != ctx->r2) {
        // 0x8018E2F4: sh          $t0, 0x14($v1)
        MEM_H(0X14, ctx->r3) = ctx->r8;
            goto L_8018E280;
    }
    // 0x8018E2F4: sh          $t0, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r8;
    // 0x8018E2F8: jr          $ra
    // 0x8018E2FC: nop

    return;
    // 0x8018E2FC: nop

;}
RECOMP_FUNC void ftCommonDownAttackCheckInterruptDownBounce(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144944: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014494C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80144950: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80144954: beql        $t6, $zero, L_8014498C
    if (ctx->r14 == 0) {
        // 0x80144958: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014498C;
    }
    goto skip_0;
    // 0x80144958: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014495C: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x80144960: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80144964: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80144968: bne         $t7, $at, L_80144978
    if (ctx->r15 != ctx->r1) {
        // 0x8014496C: nop
    
            goto L_80144978;
    }
    // 0x8014496C: nop

    // 0x80144970: b           L_80144978
    // 0x80144974: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
        goto L_80144978;
    // 0x80144974: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
L_80144978:
    // 0x80144978: jal         0x80144910
    // 0x8014497C: nop

    ftCommonDownAttackSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014497C: nop

    after_0:
    // 0x80144980: b           L_8014498C
    // 0x80144984: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014498C;
    // 0x80144984: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80144988: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014498C:
    // 0x8014498C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80144990: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80144994: jr          $ra
    // 0x80144998: nop

    return;
    // 0x80144998: nop

;}
RECOMP_FUNC void grWallpaperMakeStatic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801048F8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801048FC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80104900: lw          $t8, 0x1300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1300);
    // 0x80104904: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80104908: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8010490C: addiu       $t6, $t6, -0x3100
    ctx->r14 = ADD32(ctx->r14, -0X3100);
    // 0x80104910: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80104914: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80104918: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8010491C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80104920: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80104924: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80104928: lw          $t9, 0x48($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X48);
    // 0x8010492C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80104930: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80104934: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80104938: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8010493C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x80104940: addiu       $a0, $zero, 0x3F0
    ctx->r4 = ADD32(0, 0X3F0);
    // 0x80104944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80104948: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8010494C: jal         0x800CD050
    // 0x80104950: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_0;
    // 0x80104950: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
    after_0:
    // 0x80104954: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80104958: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010495C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80104960: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80104964: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104968: sw          $v0, 0x13D8($at)
    MEM_W(0X13D8, ctx->r1) = ctx->r2;
    // 0x8010496C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80104970: addiu       $t2, $zero, 0x220
    ctx->r10 = ADD32(0, 0X220);
    // 0x80104974: swc1        $f0, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f0.u32l;
    // 0x80104978: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x8010497C: sh          $t2, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r10;
    // 0x80104980: swc1        $f2, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f2.u32l;
    // 0x80104984: swc1        $f2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f2.u32l;
    // 0x80104988: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8010498C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80104990: jr          $ra
    // 0x80104994: nop

    return;
    // 0x80104994: nop

;}
RECOMP_FUNC void efManagerPikachuThunderJoltMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101C34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101C38: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80101C3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101C40: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101C44: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80101C48: jal         0x800FDAFC
    // 0x80101C4C: addiu       $a0, $a0, -0x1DB4
    ctx->r4 = ADD32(ctx->r4, -0X1DB4);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80101C4C: addiu       $a0, $a0, -0x1DB4
    ctx->r4 = ADD32(ctx->r4, -0X1DB4);
    after_0:
    // 0x80101C50: bne         $v0, $zero, L_80101C60
    if (ctx->r2 != 0) {
        // 0x80101C54: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80101C60;
    }
    // 0x80101C54: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80101C58: b           L_80101C90
    // 0x80101C5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80101C90;
    // 0x80101C5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101C60:
    // 0x80101C60: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80101C64: lw          $t6, 0x74($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X74);
    // 0x80101C68: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80101C6C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80101C70: sw          $t9, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r25;
    // 0x80101C74: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80101C78: sw          $t8, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r24;
    // 0x80101C7C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80101C80: sw          $t9, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->r25;
    // 0x80101C84: lw          $t0, 0x74($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X74);
    // 0x80101C88: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80101C8C: swc1        $f4, 0x38($t0)
    MEM_W(0X38, ctx->r8) = ctx->f4.u32l;
L_80101C90:
    // 0x80101C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101C98: jr          $ra
    // 0x80101C9C: nop

    return;
    // 0x80101C9C: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FC00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018FC04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018FC08: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018FC0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018FC10: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8018FC14: jal         0x80009968
    // 0x8018FC18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018FC18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018FC1C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FC20: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018FC24: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018FC28: sw          $v0, 0xBAC($at)
    MEM_W(0XBAC, ctx->r1) = ctx->r2;
    // 0x8018FC2C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018FC30: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018FC34: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018FC38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018FC3C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018FC40: jal         0x80009DF4
    // 0x8018FC44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018FC44: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018FC48: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018FC4C: lw          $t7, 0xB88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XB88);
    // 0x8018FC50: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018FC54: jal         0x800CCFDC
    // 0x8018FC58: lw          $a1, 0x78($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X78);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018FC58: lw          $a1, 0x78($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X78);
    after_2:
    // 0x8018FC5C: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x8018FC60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018FC64: jal         0x8018FBB0
    // 0x8018FC68: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    sc1PTrainingModeUpdateCursorPosition(rdram, ctx);
        goto after_3;
    // 0x8018FC68: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    after_3:
    // 0x8018FC6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018FC70: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018FC74: jr          $ra
    // 0x8018FC78: nop

    return;
    // 0x8018FC78: nop

;}
RECOMP_FUNC void dbCubeStopFGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131C54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131C58: jal         0x80020E28
    // 0x80131C5C: nop

    func_80020E28(rdram, ctx);
        goto after_0;
    // 0x80131C5C: nop

    after_0:
    // 0x80131C60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131C64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131C68: jr          $ra
    // 0x80131C6C: nop

    return;
    // 0x80131C6C: nop

;}
RECOMP_FUNC void ftCommonDamageFallProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143560: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80143564: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80143568: jal         0x80150F08
    // 0x8014356C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonSpecialAirCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014356C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80143570: bnel        $v0, $zero, L_801435A4
    if (ctx->r2 != 0) {
        // 0x80143574: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801435A4;
    }
    goto skip_0;
    // 0x80143574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80143578: jal         0x80150B00
    // 0x8014357C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonAttackAirCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8014357C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80143580: bnel        $v0, $zero, L_801435A4
    if (ctx->r2 != 0) {
        // 0x80143584: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801435A4;
    }
    goto skip_1;
    // 0x80143584: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80143588: jal         0x8014019C
    // 0x8014358C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonJumpAerialCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x8014358C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80143590: bnel        $v0, $zero, L_801435A4
    if (ctx->r2 != 0) {
        // 0x80143594: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801435A4;
    }
    goto skip_2;
    // 0x80143594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80143598: jal         0x80147CCC
    // 0x8014359C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonHammerFallCheckInterruptDamageFall(rdram, ctx);
        goto after_3;
    // 0x8014359C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x801435A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801435A4:
    // 0x801435A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801435A8: jr          $ra
    // 0x801435AC: nop

    return;
    // 0x801435AC: nop

;}
RECOMP_FUNC void mnVSResultsGetPlayerCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B78: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80131B7C: addiu       $v1, $v1, 0x4D08
    ctx->r3 = ADD32(ctx->r3, 0X4D08);
    // 0x80131B80: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x80131B84: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x80131B88: jr          $ra
    // 0x80131B8C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    return;
    // 0x80131B8C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
;}
RECOMP_FUNC void mnCharactersMakeWorksWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801332C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801332C8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801332CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801332D0: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801332D4: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x801332D8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801332DC: lui         $t9, 0x4000
    ctx->r25 = S32(0X4000 << 16);
    // 0x801332E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801332E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801332E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801332EC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801332F0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801332F4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801332F8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801332FC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133300: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133304: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133308: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013330C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133310: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133314: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133318: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013331C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133320: jal         0x8000B93C
    // 0x80133324: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133324: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133328: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013332C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133330: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133334: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133338: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013333C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133340: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133344: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133348: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013334C: jal         0x80007080
    // 0x80133350: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133350: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133354: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133358: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013335C: jr          $ra
    // 0x80133360: nop

    return;
    // 0x80133360: nop

;}
RECOMP_FUNC void itPippiCommonMoveDLProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801834A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801834A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801834A8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x801834AC: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x801834B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801834B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801834B8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801834BC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801834C0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801834C4: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801834C8: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801834CC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801834D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801834D4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x801834D8: jal         0x80171C10
    // 0x801834DC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    itDisplayCheckItemVisible(rdram, ctx);
        goto after_0;
    // 0x801834DC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x801834E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801834E4: beq         $v0, $zero, L_801835D0
    if (ctx->r2 == 0) {
        // 0x801834E8: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_801835D0;
    }
    // 0x801834E8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801834EC: lw          $v0, 0x374($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X374);
    // 0x801834F0: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x801834F4: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x801834F8: beq         $v0, $zero, L_80183514
    if (ctx->r2 == 0) {
        // 0x801834FC: lui         $t3, 0x50
        ctx->r11 = S32(0X50 << 16);
            goto L_80183514;
    }
    // 0x801834FC: lui         $t3, 0x50
    ctx->r11 = S32(0X50 << 16);
    // 0x80183500: lw          $t8, 0x2CC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2CC);
    // 0x80183504: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80183508: sll         $t0, $t8, 17
    ctx->r8 = S32(ctx->r24 << 17);
    // 0x8018350C: bgez        $t0, L_8018353C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80183510: nop
    
            goto L_8018353C;
    }
    // 0x80183510: nop

L_80183514:
    // 0x80183514: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80183518: ori         $t3, $t3, 0x41C8
    ctx->r11 = ctx->r11 | 0X41C8;
    // 0x8018351C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80183520: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80183524: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80183528: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8018352C: jal         0x80014038
    // 0x80183530: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_1;
    // 0x80183530: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_1:
    // 0x80183534: b           L_801835D4
    // 0x80183538: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801835D4;
    // 0x80183538: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8018353C:
    // 0x8018353C: bne         $v0, $at, L_80183580
    if (ctx->r2 != ctx->r1) {
        // 0x80183540: lui         $t5, 0xE200
        ctx->r13 = S32(0XE200 << 16);
            goto L_80183580;
    }
    // 0x80183540: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x80183544: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80183548: lui         $t6, 0x50
    ctx->r14 = S32(0X50 << 16);
    // 0x8018354C: ori         $t6, $t6, 0x41C8
    ctx->r14 = ctx->r14 | 0X41C8;
    // 0x80183550: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80183554: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80183558: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8018355C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80183560: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80183564: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80183568: jal         0x80014038
    // 0x8018356C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_2;
    // 0x8018356C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80183570: jal         0x801719AC
    // 0x80183574: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    itDisplayMapCollisions(rdram, ctx);
        goto after_3;
    // 0x80183574: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80183578: b           L_801835D4
    // 0x8018357C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801835D4;
    // 0x8018357C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80183580:
    // 0x80183580: lw          $t7, 0x248($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X248);
    // 0x80183584: bne         $t7, $zero, L_801835C8
    if (ctx->r15 != 0) {
        // 0x80183588: nop
    
            goto L_801835C8;
    }
    // 0x80183588: nop

    // 0x8018358C: lw          $t8, 0x10C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10C);
    // 0x80183590: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x80183594: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x80183598: bne         $t8, $zero, L_801835C8
    if (ctx->r24 != 0) {
        // 0x8018359C: lui         $t1, 0x50
        ctx->r9 = S32(0X50 << 16);
            goto L_801835C8;
    }
    // 0x8018359C: lui         $t1, 0x50
    ctx->r9 = S32(0X50 << 16);
    // 0x801835A0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801835A4: ori         $t1, $t1, 0x41C8
    ctx->r9 = ctx->r9 | 0X41C8;
    // 0x801835A8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801835AC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801835B0: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x801835B4: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801835B8: jal         0x80014038
    // 0x801835BC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_4;
    // 0x801835BC: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    after_4:
    // 0x801835C0: b           L_801835D4
    // 0x801835C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_801835D4;
    // 0x801835C4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801835C8:
    // 0x801835C8: jal         0x80171410
    // 0x801835CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayHitCollisions(rdram, ctx);
        goto after_5;
    // 0x801835CC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
L_801835D0:
    // 0x801835D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801835D4:
    // 0x801835D4: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x801835D8: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801835DC: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801835E0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801835E4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801835E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801835EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801835F0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801835F4: jr          $ra
    // 0x801835F8: nop

    return;
    // 0x801835F8: nop

;}
RECOMP_FUNC void itBombHeiDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801775E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801775EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801775F0: jal         0x80177208
    // 0x801775F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itBombHeiCommonSetHitStatusNormal(rdram, ctx);
        goto after_0;
    // 0x801775F4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801775F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801775FC: addiu       $a1, $a1, -0x6034
    ctx->r5 = ADD32(ctx->r5, -0X6034);
    // 0x80177600: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80177604: jal         0x80172EC8
    // 0x80177608: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80177608: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_1:
    // 0x8017760C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177610: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177614: jr          $ra
    // 0x80177618: nop

    return;
    // 0x80177618: nop

;}
RECOMP_FUNC void mpCollisionSetYakumonoPosID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC4A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FC4AC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FC4B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FC4B4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FC4B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FC4BC: beq         $a0, $at, L_800FC4D0
    if (ctx->r4 == ctx->r1) {
        // 0x800FC4C0: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FC4D0;
    }
    // 0x800FC4C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FC4C4: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FC4C8: bne         $a0, $at, L_800FC4F4
    if (ctx->r4 != ctx->r1) {
        // 0x800FC4CC: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FC4F4;
    }
    // 0x800FC4CC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FC4D0:
    // 0x800FC4D0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FC4D4: addiu       $s0, $s0, 0x69C
    ctx->r16 = ADD32(ctx->r16, 0X69C);
    // 0x800FC4D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FC4DC:
    // 0x800FC4DC: jal         0x80023624
    // 0x800FC4E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FC4E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FC4E4: jal         0x800A3040
    // 0x800FC4E8: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FC4E8: nop

    after_1:
    // 0x800FC4EC: b           L_800FC4DC
    // 0x800FC4F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FC4DC;
    // 0x800FC4F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FC4F4:
    // 0x800FC4F4: lw          $t6, 0x1304($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1304);
    // 0x800FC4F8: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FC4FC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800FC500: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800FC504: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800FC508: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FC50C: addiu       $a0, $a0, 0x137C
    ctx->r4 = ADD32(ctx->r4, 0X137C);
    // 0x800FC510: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800FC514: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800FC518: sll         $v1, $s1, 2
    ctx->r3 = S32(ctx->r17 << 2);
    // 0x800FC51C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800FC520: subu        $v1, $v1, $s1
    ctx->r3 = SUB32(ctx->r3, ctx->r17);
    // 0x800FC524: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800FC528: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x800FC52C: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x800FC530: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800FC534: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800FC538: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800FC53C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800FC540: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x800FC544: swc1        $f18, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->f18.u32l;
    // 0x800FC548: lwc1        $f4, 0x8($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800FC54C: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800FC550: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800FC554: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800FC558: addu        $t4, $t3, $v1
    ctx->r12 = ADD32(ctx->r11, ctx->r3);
    // 0x800FC55C: swc1        $f8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
    // 0x800FC560: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800FC564: swc1        $f10, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f10.u32l;
    // 0x800FC568: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800FC56C: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
    // 0x800FC570: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800FC574: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x800FC578: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FC57C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FC580: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FC584: jr          $ra
    // 0x800FC588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FC588: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void syMatrixTraF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B924: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001B928: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001B92C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8001B930: swc1        $f12, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f12.u32l;
    // 0x8001B934: swc1        $f14, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f14.u32l;
    // 0x8001B938: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8001B93C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001B940: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001B944: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8001B948: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8001B94C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8001B950: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001B954: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001B958: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8001B95C: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
L_8001B960:
    // 0x8001B960: bnel        $v0, $zero, L_8001B974
    if (ctx->r2 != 0) {
        // 0x8001B964: swc1        $f2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
            goto L_8001B974;
    }
    goto skip_0;
    // 0x8001B964: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
    skip_0:
    // 0x8001B968: b           L_8001B974
    // 0x8001B96C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
        goto L_8001B974;
    // 0x8001B96C: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x8001B970: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_8001B974:
    // 0x8001B974: bnel        $v0, $a1, L_8001B988
    if (ctx->r2 != ctx->r5) {
        // 0x8001B978: swc1        $f2, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
            goto L_8001B988;
    }
    goto skip_1;
    // 0x8001B978: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
    skip_1:
    // 0x8001B97C: b           L_8001B988
    // 0x8001B980: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
        goto L_8001B988;
    // 0x8001B980: swc1        $f0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f0.u32l;
    // 0x8001B984: swc1        $f2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f2.u32l;
L_8001B988:
    // 0x8001B988: bnel        $v0, $a2, L_8001B99C
    if (ctx->r2 != ctx->r6) {
        // 0x8001B98C: swc1        $f2, 0x8($v1)
        MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
            goto L_8001B99C;
    }
    goto skip_2;
    // 0x8001B98C: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
    skip_2:
    // 0x8001B990: b           L_8001B99C
    // 0x8001B994: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
        goto L_8001B99C;
    // 0x8001B994: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x8001B998: swc1        $f2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f2.u32l;
L_8001B99C:
    // 0x8001B99C: bnel        $v0, $a3, L_8001B9B0
    if (ctx->r2 != ctx->r7) {
        // 0x8001B9A0: swc1        $f2, 0xC($v1)
        MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
            goto L_8001B9B0;
    }
    goto skip_3;
    // 0x8001B9A0: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
    skip_3:
    // 0x8001B9A4: b           L_8001B9B0
    // 0x8001B9A8: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
        goto L_8001B9B0;
    // 0x8001B9A8: swc1        $f0, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f0.u32l;
    // 0x8001B9AC: swc1        $f2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f2.u32l;
L_8001B9B0:
    // 0x8001B9B0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001B9B4: bne         $v0, $a3, L_8001B960
    if (ctx->r2 != ctx->r7) {
        // 0x8001B9B8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8001B960;
    }
    // 0x8001B9B8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8001B9BC: jr          $ra
    // 0x8001B9C0: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8001B9C0: swc1        $f0, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void mnTitleSetEndLayout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131EE4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131EE8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80131EEC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80131EF0: lw          $s0, 0x6708($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6708);
    // 0x80131EF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131EF8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80131EFC: beq         $s0, $zero, L_80131F28
    if (ctx->r16 == 0) {
        // 0x80131F00: sdc1        $f20, 0x10($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
            goto L_80131F28;
    }
    // 0x80131F00: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80131F04: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x80131F08: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_80131F0C:
    // 0x80131F0C: bnel        $s1, $t6, L_80131F20
    if (ctx->r17 != ctx->r14) {
        // 0x80131F10: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80131F20;
    }
    goto skip_0;
    // 0x80131F10: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80131F14: jal         0x80132A58
    // 0x80131F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnTitleShowFire(rdram, ctx);
        goto after_0;
    // 0x80131F18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80131F1C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80131F20:
    // 0x80131F20: bnel        $s0, $zero, L_80131F0C
    if (ctx->r16 != 0) {
        // 0x80131F24: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_80131F0C;
    }
    goto skip_1;
    // 0x80131F24: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80131F28:
    // 0x80131F28: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80131F2C: lw          $s0, 0x6710($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6710);
    // 0x80131F30: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x80131F34: beq         $s0, $zero, L_80131F58
    if (ctx->r16 == 0) {
        // 0x80131F38: nop
    
            goto L_80131F58;
    }
    // 0x80131F38: nop

    // 0x80131F3C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
L_80131F40:
    // 0x80131F40: bnel        $v0, $t7, L_80131F50
    if (ctx->r2 != ctx->r15) {
        // 0x80131F44: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80131F50;
    }
    goto skip_2;
    // 0x80131F44: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x80131F48: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80131F4C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80131F50:
    // 0x80131F50: bnel        $s0, $zero, L_80131F40
    if (ctx->r16 != 0) {
        // 0x80131F54: lw          $t7, 0x0($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X0);
            goto L_80131F40;
    }
    goto skip_3;
    // 0x80131F54: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    skip_3:
L_80131F58:
    // 0x80131F58: jal         0x8000B39C
    // 0x80131F5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    gcEndProcessAll(rdram, ctx);
        goto after_1;
    // 0x80131F5C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80131F60: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x80131F64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80131F68: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131F6C: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x80131F70: sw          $zero, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = 0;
    // 0x80131F74: beql        $s0, $zero, L_80131FBC
    if (ctx->r16 == 0) {
        // 0x80131F78: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80131FBC;
    }
    goto skip_4;
    // 0x80131F78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80131F7C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80131F80: nop

    // 0x80131F84: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80131F88:
    // 0x80131F88: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80131F8C: jal         0x80132764
    // 0x80131F90: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    mnTitleSetPosition(rdram, ctx);
        goto after_2;
    // 0x80131F90: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_2:
    // 0x80131F94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F98: jal         0x8013282C
    // 0x80131F9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnTitleSetColors(rdram, ctx);
        goto after_3;
    // 0x80131F9C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x80131FA0: swc1        $f20, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f20.u32l;
    // 0x80131FA4: swc1        $f20, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->f20.u32l;
    // 0x80131FA8: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80131FAC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80131FB0: bnel        $s0, $zero, L_80131F88
    if (ctx->r16 != 0) {
        // 0x80131FB4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80131F88;
    }
    goto skip_5;
    // 0x80131FB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_5:
    // 0x80131FB8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80131FBC:
    // 0x80131FBC: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80131FC0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80131FC4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80131FC8: jr          $ra
    // 0x80131FCC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131FCC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayers1PGameContinueGameOverTextStepColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C58: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132C5C: addiu       $t7, $t7, 0x41E0
    ctx->r15 = ADD32(ctx->r15, 0X41E0);
    // 0x80132C60: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132C64: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132C68: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132C6C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132C70: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x80132C74: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132C78: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132C7C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80132C80: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132C84: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132C88: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80132C8C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132C90: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80132C94: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80132C98: addiu       $v1, $v1, 0x4344
    ctx->r3 = ADD32(ctx->r3, 0X4344);
    // 0x80132C9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132CA0: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80132CA4: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80132CA8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132CAC: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132CB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132CB4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80132CB8: nop

    // 0x80132CBC: bc1f        L_80133074
    if (!c1cs) {
        // 0x80132CC0: nop
    
            goto L_80133074;
    }
    // 0x80132CC0: nop

    // 0x80132CC4: lwc1        $f4, 0x42E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X42E4);
    // 0x80132CC8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80132CCC: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80132CD0: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132CD4: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x80132CD8: nop

    // 0x80132CDC: bc1f        L_80132CE8
    if (!c1cs) {
        // 0x80132CE0: nop
    
            goto L_80132CE8;
    }
    // 0x80132CE0: nop

    // 0x80132CE4: swc1        $f2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f2.u32l;
L_80132CE8:
    // 0x80132CE8: beq         $v0, $zero, L_80133074
    if (ctx->r2 == 0) {
        // 0x80132CEC: nop
    
            goto L_80133074;
    }
    // 0x80132CEC: nop

    // 0x80132CF0: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
L_80132CF4:
    // 0x80132CF4: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132CF8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132CFC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80132D00: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80132D04: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80132D08: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80132D0C: nop

    // 0x80132D10: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80132D14: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80132D18: nop

    // 0x80132D1C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80132D20: beql        $t1, $zero, L_80132D70
    if (ctx->r9 == 0) {
        // 0x80132D24: mfc1        $t1, $f4
        ctx->r9 = (int32_t)ctx->f4.u32l;
            goto L_80132D70;
    }
    goto skip_0;
    // 0x80132D24: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    skip_0:
    // 0x80132D28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132D2C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132D30: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80132D34: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80132D38: nop

    // 0x80132D3C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80132D40: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80132D44: nop

    // 0x80132D48: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80132D4C: bne         $t1, $zero, L_80132D64
    if (ctx->r9 != 0) {
        // 0x80132D50: nop
    
            goto L_80132D64;
    }
    // 0x80132D50: nop

    // 0x80132D54: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x80132D58: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132D5C: b           L_80132D7C
    // 0x80132D60: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80132D7C;
    // 0x80132D60: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80132D64:
    // 0x80132D64: b           L_80132D7C
    // 0x80132D68: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80132D7C;
    // 0x80132D68: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80132D6C: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
L_80132D70:
    // 0x80132D70: nop

    // 0x80132D74: bltz        $t1, L_80132D64
    if (SIGNED(ctx->r9) < 0) {
        // 0x80132D78: nop
    
            goto L_80132D64;
    }
    // 0x80132D78: nop

L_80132D7C:
    // 0x80132D7C: sb          $t1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r9;
    // 0x80132D80: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80132D84: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132D88: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80132D8C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132D90: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80132D94: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80132D98: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80132D9C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80132DA0: nop

    // 0x80132DA4: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80132DA8: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80132DAC: nop

    // 0x80132DB0: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80132DB4: beql        $t3, $zero, L_80132E04
    if (ctx->r11 == 0) {
        // 0x80132DB8: mfc1        $t3, $f16
        ctx->r11 = (int32_t)ctx->f16.u32l;
            goto L_80132E04;
    }
    goto skip_1;
    // 0x80132DB8: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    skip_1:
    // 0x80132DBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132DC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132DC4: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80132DC8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80132DCC: nop

    // 0x80132DD0: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80132DD4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80132DD8: nop

    // 0x80132DDC: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80132DE0: bne         $t3, $zero, L_80132DF8
    if (ctx->r11 != 0) {
        // 0x80132DE4: nop
    
            goto L_80132DF8;
    }
    // 0x80132DE4: nop

    // 0x80132DE8: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x80132DEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132DF0: b           L_80132E10
    // 0x80132DF4: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80132E10;
    // 0x80132DF4: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80132DF8:
    // 0x80132DF8: b           L_80132E10
    // 0x80132DFC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80132E10;
    // 0x80132DFC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80132E00: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
L_80132E04:
    // 0x80132E04: nop

    // 0x80132E08: bltz        $t3, L_80132DF8
    if (SIGNED(ctx->r11) < 0) {
        // 0x80132E0C: nop
    
            goto L_80132DF8;
    }
    // 0x80132E0C: nop

L_80132E10:
    // 0x80132E10: sb          $t3, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r11;
    // 0x80132E14: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80132E18: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132E1C: lwc1        $f18, 0xC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80132E20: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80132E24: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80132E28: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80132E2C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80132E30: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80132E34: nop

    // 0x80132E38: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80132E3C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80132E40: nop

    // 0x80132E44: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80132E48: beql        $t5, $zero, L_80132E98
    if (ctx->r13 == 0) {
        // 0x80132E4C: mfc1        $t5, $f8
        ctx->r13 = (int32_t)ctx->f8.u32l;
            goto L_80132E98;
    }
    goto skip_2;
    // 0x80132E4C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    skip_2:
    // 0x80132E50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132E54: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80132E58: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80132E5C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80132E60: nop

    // 0x80132E64: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80132E68: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80132E6C: nop

    // 0x80132E70: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x80132E74: bne         $t5, $zero, L_80132E8C
    if (ctx->r13 != 0) {
        // 0x80132E78: nop
    
            goto L_80132E8C;
    }
    // 0x80132E78: nop

    // 0x80132E7C: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x80132E80: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132E84: b           L_80132EA4
    // 0x80132E88: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_80132EA4;
    // 0x80132E88: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_80132E8C:
    // 0x80132E8C: b           L_80132EA4
    // 0x80132E90: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_80132EA4;
    // 0x80132E90: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80132E94: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
L_80132E98:
    // 0x80132E98: nop

    // 0x80132E9C: bltz        $t5, L_80132E8C
    if (SIGNED(ctx->r13) < 0) {
        // 0x80132EA0: nop
    
            goto L_80132E8C;
    }
    // 0x80132EA0: nop

L_80132EA4:
    // 0x80132EA4: sb          $t5, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r13;
    // 0x80132EA8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80132EAC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132EB0: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80132EB4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132EB8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80132EBC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80132EC0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80132EC4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80132EC8: nop

    // 0x80132ECC: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80132ED0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80132ED4: nop

    // 0x80132ED8: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80132EDC: beql        $t7, $zero, L_80132F2C
    if (ctx->r15 == 0) {
        // 0x80132EE0: mfc1        $t7, $f4
        ctx->r15 = (int32_t)ctx->f4.u32l;
            goto L_80132F2C;
    }
    goto skip_3;
    // 0x80132EE0: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    skip_3:
    // 0x80132EE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132EE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132EEC: sub.s       $f4, $f18, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80132EF0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80132EF4: nop

    // 0x80132EF8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80132EFC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80132F00: nop

    // 0x80132F04: andi        $t7, $t7, 0x78
    ctx->r15 = ctx->r15 & 0X78;
    // 0x80132F08: bne         $t7, $zero, L_80132F20
    if (ctx->r15 != 0) {
        // 0x80132F0C: nop
    
            goto L_80132F20;
    }
    // 0x80132F0C: nop

    // 0x80132F10: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80132F14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132F18: b           L_80132F38
    // 0x80132F1C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
        goto L_80132F38;
    // 0x80132F1C: or          $t7, $t7, $at
    ctx->r15 = ctx->r15 | ctx->r1;
L_80132F20:
    // 0x80132F20: b           L_80132F38
    // 0x80132F24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
        goto L_80132F38;
    // 0x80132F24: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80132F28: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
L_80132F2C:
    // 0x80132F2C: nop

    // 0x80132F30: bltz        $t7, L_80132F20
    if (SIGNED(ctx->r15) < 0) {
        // 0x80132F34: nop
    
            goto L_80132F20;
    }
    // 0x80132F34: nop

L_80132F38:
    // 0x80132F38: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80132F3C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80132F40: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132F44: lwc1        $f6, 0x14($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80132F48: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132F4C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80132F50: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80132F54: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80132F58: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80132F5C: nop

    // 0x80132F60: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80132F64: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80132F68: nop

    // 0x80132F6C: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80132F70: beql        $t9, $zero, L_80132FC0
    if (ctx->r25 == 0) {
        // 0x80132F74: mfc1        $t9, $f16
        ctx->r25 = (int32_t)ctx->f16.u32l;
            goto L_80132FC0;
    }
    goto skip_4;
    // 0x80132F74: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    skip_4:
    // 0x80132F78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132F7C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132F80: sub.s       $f16, $f10, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80132F84: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80132F88: nop

    // 0x80132F8C: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80132F90: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80132F94: nop

    // 0x80132F98: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x80132F9C: bne         $t9, $zero, L_80132FB4
    if (ctx->r25 != 0) {
        // 0x80132FA0: nop
    
            goto L_80132FB4;
    }
    // 0x80132FA0: nop

    // 0x80132FA4: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x80132FA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80132FAC: b           L_80132FCC
    // 0x80132FB0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_80132FCC;
    // 0x80132FB0: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_80132FB4:
    // 0x80132FB4: b           L_80132FCC
    // 0x80132FB8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_80132FCC;
    // 0x80132FB8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80132FBC: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
L_80132FC0:
    // 0x80132FC0: nop

    // 0x80132FC4: bltz        $t9, L_80132FB4
    if (SIGNED(ctx->r25) < 0) {
        // 0x80132FC8: nop
    
            goto L_80132FB4;
    }
    // 0x80132FC8: nop

L_80132FCC:
    // 0x80132FCC: sb          $t9, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r25;
    // 0x80132FD0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80132FD4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80132FD8: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80132FDC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132FE0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80132FE4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80132FE8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80132FEC: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80132FF0: nop

    // 0x80132FF4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80132FF8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80132FFC: nop

    // 0x80133000: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80133004: beql        $t1, $zero, L_80133054
    if (ctx->r9 == 0) {
        // 0x80133008: mfc1        $t1, $f8
        ctx->r9 = (int32_t)ctx->f8.u32l;
            goto L_80133054;
    }
    goto skip_5;
    // 0x80133008: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    skip_5:
    // 0x8013300C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133010: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133014: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80133018: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8013301C: nop

    // 0x80133020: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80133024: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80133028: nop

    // 0x8013302C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x80133030: bne         $t1, $zero, L_80133048
    if (ctx->r9 != 0) {
        // 0x80133034: nop
    
            goto L_80133048;
    }
    // 0x80133034: nop

    // 0x80133038: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8013303C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133040: b           L_80133060
    // 0x80133044: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_80133060;
    // 0x80133044: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_80133048:
    // 0x80133048: b           L_80133060
    // 0x8013304C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_80133060;
    // 0x8013304C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80133050: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
L_80133054:
    // 0x80133054: nop

    // 0x80133058: bltz        $t1, L_80133048
    if (SIGNED(ctx->r9) < 0) {
        // 0x8013305C: nop
    
            goto L_80133048;
    }
    // 0x8013305C: nop

L_80133060:
    // 0x80133060: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80133064: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x80133068: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8013306C: bnel        $v0, $zero, L_80132CF4
    if (ctx->r2 != 0) {
        // 0x80133070: lwc1        $f10, 0x4($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
            goto L_80132CF4;
    }
    goto skip_6;
    // 0x80133070: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    skip_6:
L_80133074:
    // 0x80133074: jr          $ra
    // 0x80133078: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80133078: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void lbBackupClear1PHighScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4914: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D4918: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D491C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D4920: addiu       $v0, $v0, 0x3B14
    ctx->r2 = ADD32(ctx->r2, 0X3B14);
    // 0x800D4924: addiu       $a0, $a0, 0x3994
    ctx->r4 = ADD32(ctx->r4, 0X3994);
    // 0x800D4928: addiu       $v1, $v1, 0x44E0
    ctx->r3 = ADD32(ctx->r3, 0X44E0);
L_800D492C:
    // 0x800D492C: lw          $t1, 0x47C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X47C);
    // 0x800D4930: lw          $t2, 0x480($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X480);
    // 0x800D4934: lw          $t3, 0x484($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X484);
    // 0x800D4938: lbu         $t4, 0x488($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X488);
    // 0x800D493C: lbu         $t5, 0x499($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X499);
    // 0x800D4940: lw          $t6, 0x45C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X45C);
    // 0x800D4944: lw          $t7, 0x460($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X460);
    // 0x800D4948: lw          $t8, 0x464($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X464);
    // 0x800D494C: lbu         $t9, 0x468($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X468);
    // 0x800D4950: lbu         $t0, 0x479($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X479);
    // 0x800D4954: sw          $t1, 0x47C($v1)
    MEM_W(0X47C, ctx->r3) = ctx->r9;
    // 0x800D4958: sw          $t2, 0x480($v1)
    MEM_W(0X480, ctx->r3) = ctx->r10;
    // 0x800D495C: sw          $t3, 0x484($v1)
    MEM_W(0X484, ctx->r3) = ctx->r11;
    // 0x800D4960: sb          $t4, 0x488($v1)
    MEM_B(0X488, ctx->r3) = ctx->r12;
    // 0x800D4964: sb          $t5, 0x499($v1)
    MEM_B(0X499, ctx->r3) = ctx->r13;
    // 0x800D4968: sw          $t6, 0x45C($v1)
    MEM_W(0X45C, ctx->r3) = ctx->r14;
    // 0x800D496C: sw          $t7, 0x460($v1)
    MEM_W(0X460, ctx->r3) = ctx->r15;
    // 0x800D4970: sw          $t8, 0x464($v1)
    MEM_W(0X464, ctx->r3) = ctx->r24;
    // 0x800D4974: sb          $t9, 0x468($v1)
    MEM_B(0X468, ctx->r3) = ctx->r25;
    // 0x800D4978: sb          $t0, 0x479($v1)
    MEM_B(0X479, ctx->r3) = ctx->r8;
    // 0x800D497C: lbu         $t0, 0x4B9($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X4B9);
    // 0x800D4980: lbu         $t9, 0x4A8($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4A8);
    // 0x800D4984: lw          $t8, 0x4A4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4A4);
    // 0x800D4988: lw          $t7, 0x4A0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4A0);
    // 0x800D498C: lw          $t6, 0x49C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X49C);
    // 0x800D4990: lbu         $t5, 0x4D9($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X4D9);
    // 0x800D4994: lbu         $t4, 0x4C8($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X4C8);
    // 0x800D4998: lw          $t3, 0x4C4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C4);
    // 0x800D499C: lw          $t2, 0x4C0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C0);
    // 0x800D49A0: lw          $t1, 0x4BC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4BC);
    // 0x800D49A4: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x800D49A8: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x800D49AC: sb          $t0, 0x439($v1)
    MEM_B(0X439, ctx->r3) = ctx->r8;
    // 0x800D49B0: sb          $t9, 0x428($v1)
    MEM_B(0X428, ctx->r3) = ctx->r25;
    // 0x800D49B4: sw          $t8, 0x424($v1)
    MEM_W(0X424, ctx->r3) = ctx->r24;
    // 0x800D49B8: sw          $t7, 0x420($v1)
    MEM_W(0X420, ctx->r3) = ctx->r15;
    // 0x800D49BC: sw          $t6, 0x41C($v1)
    MEM_W(0X41C, ctx->r3) = ctx->r14;
    // 0x800D49C0: sb          $t5, 0x459($v1)
    MEM_B(0X459, ctx->r3) = ctx->r13;
    // 0x800D49C4: sb          $t4, 0x448($v1)
    MEM_B(0X448, ctx->r3) = ctx->r12;
    // 0x800D49C8: sw          $t3, 0x444($v1)
    MEM_W(0X444, ctx->r3) = ctx->r11;
    // 0x800D49CC: sw          $t2, 0x440($v1)
    MEM_W(0X440, ctx->r3) = ctx->r10;
    // 0x800D49D0: bne         $a0, $v0, L_800D492C
    if (ctx->r4 != ctx->r2) {
        // 0x800D49D4: sw          $t1, 0x43C($v1)
        MEM_W(0X43C, ctx->r3) = ctx->r9;
            goto L_800D492C;
    }
    // 0x800D49D4: sw          $t1, 0x43C($v1)
    MEM_W(0X43C, ctx->r3) = ctx->r9;
    // 0x800D49D8: jr          $ra
    // 0x800D49DC: nop

    return;
    // 0x800D49DC: nop

;}
RECOMP_FUNC void gcFuncGObjAllEx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B08C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8000B090: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x8000B094: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x8000B098: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8000B09C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8000B0A0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000B0A4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000B0A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000B0AC: lui         $s6, 0x8004
    ctx->r22 = S32(0X8004 << 16);
    // 0x8000B0B0: lui         $s7, 0x8004
    ctx->r23 = S32(0X8004 << 16);
    // 0x8000B0B4: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000B0B8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8000B0BC: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000B0C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000B0C4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B0C8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000B0CC: addiu       $s7, $s7, 0x6774
    ctx->r23 = ADD32(ctx->r23, 0X6774);
    // 0x8000B0D0: addiu       $s6, $s6, 0x66F0
    ctx->r22 = ADD32(ctx->r22, 0X66F0);
    // 0x8000B0D4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8000B0D8: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
L_8000B0DC:
    // 0x8000B0DC: beql        $a0, $zero, L_8000B114
    if (ctx->r4 == 0) {
        // 0x8000B0E0: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_8000B114;
    }
    goto skip_0;
    // 0x8000B0E0: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
    skip_0:
L_8000B0E4:
    // 0x8000B0E4: lw          $s0, 0x4($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X4);
    // 0x8000B0E8: jalr        $s2
    // 0x8000B0EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r18)(rdram, ctx);
        goto after_0;
    // 0x8000B0EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8000B0F0: beq         $v0, $zero, L_8000B108
    if (ctx->r2 == 0) {
        // 0x8000B0F4: nop
    
            goto L_8000B108;
    }
    // 0x8000B0F4: nop

    // 0x8000B0F8: bne         $s3, $s4, L_8000B108
    if (ctx->r19 != ctx->r20) {
        // 0x8000B0FC: or          $s5, $v0, $zero
        ctx->r21 = ctx->r2 | 0;
            goto L_8000B108;
    }
    // 0x8000B0FC: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x8000B100: b           L_8000B124
    // 0x8000B104: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_8000B124;
    // 0x8000B104: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000B108:
    // 0x8000B108: bne         $s0, $zero, L_8000B0E4
    if (ctx->r16 != 0) {
        // 0x8000B10C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8000B0E4;
    }
    // 0x8000B10C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000B110: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_8000B114:
    // 0x8000B114: bnel        $s6, $s7, L_8000B0DC
    if (ctx->r22 != ctx->r23) {
        // 0x8000B118: lw          $a0, 0x0($s6)
        ctx->r4 = MEM_W(ctx->r22, 0X0);
            goto L_8000B0DC;
    }
    goto skip_1;
    // 0x8000B118: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    skip_1:
    // 0x8000B11C: or          $v0, $s5, $zero
    ctx->r2 = ctx->r21 | 0;
    // 0x8000B120: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_8000B124:
    // 0x8000B124: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000B128: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000B12C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B130: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000B134: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8000B138: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8000B13C: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B140: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x8000B144: jr          $ra
    // 0x8000B148: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8000B148: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void grInishieMakePowerBlock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801099D4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801099D8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801099DC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801099E0: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x801099E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801099E8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801099EC: jal         0x80009968
    // 0x801099F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801099F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801099F4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x801099F8: addiu       $a1, $a1, -0x6698
    ctx->r5 = ADD32(ctx->r5, -0X6698);
    // 0x801099FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80109A00: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80109A04: jal         0x80008188
    // 0x80109A08: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80109A08: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x80109A0C: jal         0x800FC7A4
    // 0x80109A10: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_2;
    // 0x80109A10: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    after_2:
    // 0x80109A14: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80109A18: addiu       $a2, $a2, 0x13F0
    ctx->r6 = ADD32(ctx->r6, 0X13F0);
    // 0x80109A1C: sb          $v0, 0x46($a2)
    MEM_B(0X46, ctx->r6) = ctx->r2;
    // 0x80109A20: beq         $v0, $zero, L_80109A34
    if (ctx->r2 == 0) {
        // 0x80109A24: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80109A34;
    }
    // 0x80109A24: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80109A28: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x80109A2C: bne         $at, $zero, L_80109A54
    if (ctx->r1 != 0) {
        // 0x80109A30: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80109A54;
    }
    // 0x80109A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80109A34:
    // 0x80109A34: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80109A38: addiu       $s0, $s0, 0xB10
    ctx->r16 = ADD32(ctx->r16, 0XB10);
L_80109A3C:
    // 0x80109A3C: jal         0x80023624
    // 0x80109A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x80109A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80109A44: jal         0x800A3040
    // 0x80109A48: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x80109A48: nop

    after_4:
    // 0x80109A4C: b           L_80109A3C
    // 0x80109A50: nop

        goto L_80109A3C;
    // 0x80109A50: nop

L_80109A54:
    // 0x80109A54: jal         0x80004980
    // 0x80109A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syTaskmanMalloc(rdram, ctx);
        goto after_5;
    // 0x80109A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80109A5C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80109A60: addiu       $a2, $a2, 0x13F0
    ctx->r6 = ADD32(ctx->r6, 0X13F0);
    // 0x80109A64: sw          $v0, 0x48($a2)
    MEM_W(0X48, ctx->r6) = ctx->r2;
    // 0x80109A68: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80109A6C: jal         0x800FC814
    // 0x80109A70: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_6;
    // 0x80109A70: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_6:
    // 0x80109A74: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80109A78: addiu       $a2, $a2, 0x13F0
    ctx->r6 = ADD32(ctx->r6, 0X13F0);
    // 0x80109A7C: blez        $s0, L_80109B14
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80109A80: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80109B14;
    }
    // 0x80109A80: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80109A84: andi        $a1, $s0, 0x3
    ctx->r5 = ctx->r16 & 0X3;
    // 0x80109A88: beq         $a1, $zero, L_80109ABC
    if (ctx->r5 == 0) {
        // 0x80109A8C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80109ABC;
    }
    // 0x80109A8C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80109A90: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x80109A94: addiu       $t7, $sp, 0x30
    ctx->r15 = ADD32(ctx->r29, 0X30);
    // 0x80109A98: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
L_80109A9C:
    // 0x80109A9C: lw          $t9, 0x48($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X48);
    // 0x80109AA0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80109AA4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80109AA8: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80109AAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80109AB0: bne         $a0, $v1, L_80109A9C
    if (ctx->r4 != ctx->r3) {
        // 0x80109AB4: sb          $t8, 0x0($t0)
        MEM_B(0X0, ctx->r8) = ctx->r24;
            goto L_80109A9C;
    }
    // 0x80109AB4: sb          $t8, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r24;
    // 0x80109AB8: beq         $v1, $s0, L_80109B14
    if (ctx->r3 == ctx->r16) {
        // 0x80109ABC: sll         $t1, $v1, 2
        ctx->r9 = S32(ctx->r3 << 2);
            goto L_80109B14;
    }
L_80109ABC:
    // 0x80109ABC: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x80109AC0: addiu       $t2, $sp, 0x30
    ctx->r10 = ADD32(ctx->r29, 0X30);
    // 0x80109AC4: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
L_80109AC8:
    // 0x80109AC8: lw          $t4, 0x48($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X48);
    // 0x80109ACC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x80109AD0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x80109AD4: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x80109AD8: sb          $t3, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r11;
    // 0x80109ADC: lw          $t7, 0x48($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X48);
    // 0x80109AE0: lw          $t6, -0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, -0XC);
    // 0x80109AE4: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x80109AE8: sb          $t6, 0x1($t9)
    MEM_B(0X1, ctx->r25) = ctx->r14;
    // 0x80109AEC: lw          $t0, 0x48($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X48);
    // 0x80109AF0: lw          $t8, -0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X8);
    // 0x80109AF4: addu        $t1, $t0, $v1
    ctx->r9 = ADD32(ctx->r8, ctx->r3);
    // 0x80109AF8: sb          $t8, 0x2($t1)
    MEM_B(0X2, ctx->r9) = ctx->r24;
    // 0x80109AFC: lw          $t4, 0x48($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X48);
    // 0x80109B00: lw          $t2, -0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, -0X4);
    // 0x80109B04: addu        $t3, $t4, $v1
    ctx->r11 = ADD32(ctx->r12, ctx->r3);
    // 0x80109B08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80109B0C: bne         $v1, $s0, L_80109AC8
    if (ctx->r3 != ctx->r16) {
        // 0x80109B10: sb          $t2, 0x3($t3)
        MEM_B(0X3, ctx->r11) = ctx->r10;
            goto L_80109AC8;
    }
    // 0x80109B10: sb          $t2, 0x3($t3)
    MEM_B(0X3, ctx->r11) = ctx->r10;
L_80109B14:
    // 0x80109B14: sb          $zero, 0x4C($a2)
    MEM_B(0X4C, ctx->r6) = 0;
    // 0x80109B18: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80109B1C: lw          $t5, 0x1300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1300);
    // 0x80109B20: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80109B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80109B28: addiu       $t7, $t7, 0x14
    ctx->r15 = ADD32(ctx->r15, 0X14);
    // 0x80109B2C: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80109B30: addiu       $t9, $t9, 0xBC
    ctx->r25 = ADD32(ctx->r25, 0XBC);
    // 0x80109B34: subu        $t6, $t5, $t7
    ctx->r14 = SUB32(ctx->r13, ctx->r15);
    // 0x80109B38: addu        $t0, $t6, $t9
    ctx->r8 = ADD32(ctx->r14, ctx->r25);
    // 0x80109B3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80109B40: sw          $t0, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r8;
    // 0x80109B44: jr          $ra
    // 0x80109B48: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80109B48: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void mnPlayersVSPuckAdjustProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801398B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801398BC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x801398C0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x801398C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801398C8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x801398CC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801398D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801398D4: addiu       $s1, $s1, -0x4578
    ctx->r17 = ADD32(ctx->r17, -0X4578);
    // 0x801398D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801398DC: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
L_801398E0:
    // 0x801398E0: lw          $t6, 0x5C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X5C);
    // 0x801398E4: beql        $t6, $zero, L_801398F8
    if (ctx->r14 == 0) {
        // 0x801398E8: lw          $t7, 0x58($s1)
        ctx->r15 = MEM_W(ctx->r17, 0X58);
            goto L_801398F8;
    }
    goto skip_0;
    // 0x801398E8: lw          $t7, 0x58($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X58);
    skip_0:
    // 0x801398EC: jal         0x801397CC
    // 0x801398F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSPuckAdjustRecall(rdram, ctx);
        goto after_0;
    // 0x801398F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801398F4: lw          $t7, 0x58($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X58);
L_801398F8:
    // 0x801398F8: beql        $t7, $zero, L_8013990C
    if (ctx->r15 == 0) {
        // 0x801398FC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8013990C;
    }
    goto skip_1;
    // 0x801398FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80139900: jal         0x8013961C
    // 0x80139904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSPuckAdjustPlaced(rdram, ctx);
        goto after_1;
    // 0x80139904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80139908: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8013990C:
    // 0x8013990C: bne         $s0, $s2, L_801398E0
    if (ctx->r16 != ctx->r18) {
        // 0x80139910: addiu       $s1, $s1, 0xBC
        ctx->r17 = ADD32(ctx->r17, 0XBC);
            goto L_801398E0;
    }
    // 0x80139910: addiu       $s1, $s1, 0xBC
    ctx->r17 = ADD32(ctx->r17, 0XBC);
    // 0x80139914: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80139918: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013991C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80139920: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80139924: jr          $ra
    // 0x80139928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80139928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itProcessProcSearchHitAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171080: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80171084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80171088: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017108C: lw          $t6, 0x2CC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2CC);
    // 0x80171090: sll         $t8, $t6, 17
    ctx->r24 = S32(ctx->r14 << 17);
    // 0x80171094: bltzl       $t8, L_801710B8
    if (SIGNED(ctx->r24) < 0) {
        // 0x80171098: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801710B8;
    }
    goto skip_0;
    // 0x80171098: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8017109C: jal         0x801705C4
    // 0x801710A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itProcessSearchHitFighter(rdram, ctx);
        goto after_0;
    // 0x801710A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801710A4: jal         0x8017088C
    // 0x801710A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itProcessSearchHitItem(rdram, ctx);
        goto after_1;
    // 0x801710A8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801710AC: jal         0x80170C84
    // 0x801710B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itProcessSearchHitWeapon(rdram, ctx);
        goto after_2;
    // 0x801710B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x801710B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801710B8:
    // 0x801710B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801710BC: jr          $ra
    // 0x801710C0: nop

    return;
    // 0x801710C0: nop

;}
RECOMP_FUNC void func_ovl29_801330C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801330C4: jr          $ra
    // 0x801330C8: nop

    return;
    // 0x801330C8: nop

;}
RECOMP_FUNC void wpNessPKThunderTrailProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016B554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B558: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016B55C: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016B560: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x8016B564: jal         0x800FE068
    // 0x8016B568: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016B568: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016B56C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B570: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016B574: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016B578: jr          $ra
    // 0x8016B57C: nop

    return;
    // 0x8016B57C: nop

;}
RECOMP_FUNC void ftKirbySpecialLwSetDropFallVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161468: lui         $at, 0xC30C
    ctx->r1 = S32(0XC30C << 16);
    // 0x8016146C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80161470: jr          $ra
    // 0x80161474: swc1        $f4, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x80161474: swc1        $f4, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void ftParamSetHitStatusAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8A24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8A28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8A2C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E8A30: jal         0x800E87A0
    // 0x800E8A34: sw          $a1, 0x5B8($v0)
    MEM_W(0X5B8, ctx->r2) = ctx->r5;
    ftParamSetHitStatusColAnim(rdram, ctx);
        goto after_0;
    // 0x800E8A34: sw          $a1, 0x5B8($v0)
    MEM_W(0X5B8, ctx->r2) = ctx->r5;
    after_0:
    // 0x800E8A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8A3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8A40: jr          $ra
    // 0x800E8A44: nop

    return;
    // 0x800E8A44: nop

;}
RECOMP_FUNC void sySchedulerSwapBuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800016D8: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800016DC: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800016E0: lbu         $t7, 0x5035($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5035);
    // 0x800016E4: lbu         $t6, 0x5034($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X5034);
    // 0x800016E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800016EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800016F0: beql        $t6, $t7, L_80001758
    if (ctx->r14 == ctx->r15) {
        // 0x800016F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001758;
    }
    goto skip_0;
    // 0x800016F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800016F8: jal         0x80032690
    // 0x800016FC: nop

    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x800016FC: nop

    after_0:
    // 0x80001700: jal         0x80039630
    // 0x80001704: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80001704: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_1:
    // 0x80001708: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x8000170C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80001710: bnel        $t8, $v0, L_80001758
    if (ctx->r24 != ctx->r2) {
        // 0x80001714: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001758;
    }
    goto skip_1;
    // 0x80001714: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80001718: lbu         $t9, 0x5035($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X5035);
    // 0x8000171C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80001720: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80001724: addu        $a0, $a0, $t0
    ctx->r4 = ADD32(ctx->r4, ctx->r8);
    // 0x80001728: jal         0x80034890
    // 0x8000172C: lw          $a0, 0x5028($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5028);
    osViSwapBuffer_recomp(rdram, ctx);
        goto after_2;
    // 0x8000172C: lw          $a0, 0x5028($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5028);
    after_2:
    // 0x80001730: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80001734: addiu       $v1, $v1, 0x5035
    ctx->r3 = ADD32(ctx->r3, 0X5035);
    // 0x80001738: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8000173C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80001740: bne         $v0, $at, L_80001750
    if (ctx->r2 != ctx->r1) {
        // 0x80001744: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_80001750;
    }
    // 0x80001744: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80001748: b           L_80001754
    // 0x8000174C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
        goto L_80001754;
    // 0x8000174C: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
L_80001750:
    // 0x80001750: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
L_80001754:
    // 0x80001754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001758:
    // 0x80001758: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000175C: jr          $ra
    // 0x80001760: nop

    return;
    // 0x80001760: nop

;}
RECOMP_FUNC void itLGunFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175558: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x8017555C: lui         $a2, 0x3DCC
    ctx->r6 = S32(0X3DCC << 16);
    // 0x80175560: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80175564: addiu       $a3, $a3, 0x5584
    ctx->r7 = ADD32(ctx->r7, 0X5584);
    // 0x80175568: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x8017556C: jal         0x80173B24
    // 0x80175570: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80175570: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80175574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175578: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017557C: jr          $ra
    // 0x80175580: nop

    return;
    // 0x80175580: nop

;}

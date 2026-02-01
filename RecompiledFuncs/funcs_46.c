#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void grHyruleTwisterUpdateSubside(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A8B4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010A8B8: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x8010A8BC: lhu         $t6, 0x20($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X20);
    // 0x8010A8C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A8C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A8C8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8010A8CC: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8010A8D0: bne         $t8, $zero, L_8010A90C
    if (ctx->r24 != 0) {
        // 0x8010A8D4: sh          $t7, 0x20($v1)
        MEM_H(0X20, ctx->r3) = ctx->r15;
            goto L_8010A90C;
    }
    // 0x8010A8D4: sh          $t7, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r15;
    // 0x8010A8D8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8010A8DC: sb          $t9, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r25;
    // 0x8010A8E0: jal         0x80018994
    // 0x8010A8E4: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8010A8E4: addiu       $a0, $zero, 0x4B0
    ctx->r4 = ADD32(0, 0X4B0);
    after_0:
    // 0x8010A8E8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010A8EC: addiu       $v1, $v1, 0x13F0
    ctx->r3 = ADD32(ctx->r3, 0X13F0);
    // 0x8010A8F0: lw          $a2, 0x8($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X8);
    // 0x8010A8F4: addiu       $t0, $v0, 0x640
    ctx->r8 = ADD32(ctx->r2, 0X640);
    // 0x8010A8F8: sh          $t0, 0x20($v1)
    MEM_H(0X20, ctx->r3) = ctx->r8;
    // 0x8010A8FC: beq         $a2, $zero, L_8010A90C
    if (ctx->r6 == 0) {
        // 0x8010A900: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8010A90C;
    }
    // 0x8010A900: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8010A904: jal         0x800D39D4
    // 0x8010A908: lhu         $a0, 0xB8($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XB8);
    lbParticleEjectStructID(rdram, ctx);
        goto after_1;
    // 0x8010A908: lhu         $a0, 0xB8($a2)
    ctx->r4 = MEM_HU(ctx->r6, 0XB8);
    after_1:
L_8010A90C:
    // 0x8010A90C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010A910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A914: jr          $ra
    // 0x8010A918: nop

    return;
    // 0x8010A918: nop

;}
RECOMP_FUNC void ftYoshiSpecialHiUpdateEggVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EA5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8015EA60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015EA64: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015EA68: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015EA6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8015EA70: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8015EA74: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
    // 0x8015EA78: bnel        $v0, $at, L_8015EAD0
    if (ctx->r2 != ctx->r1) {
        // 0x8015EA7C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8015EAD0;
    }
    goto skip_0;
    // 0x8015EA7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x8015EA80: lw          $v1, 0xB18($s0)
    ctx->r3 = MEM_W(ctx->r16, 0XB18);
    // 0x8015EA84: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x8015EA88: beql        $v1, $zero, L_8015EAC4
    if (ctx->r3 == 0) {
        // 0x8015EA8C: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8015EAC4;
    }
    goto skip_1;
    // 0x8015EA8C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_1:
    // 0x8015EA90: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x8015EA94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8015EA98: addiu       $a2, $s0, 0x78
    ctx->r6 = ADD32(ctx->r16, 0X78);
    // 0x8015EA9C: sb          $t6, 0x29D($v0)
    MEM_B(0X29D, ctx->r2) = ctx->r14;
    // 0x8015EAA0: lh          $t7, 0xB1C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0XB1C);
    // 0x8015EAA4: sh          $t7, 0x2A0($v0)
    MEM_H(0X2A0, ctx->r2) = ctx->r15;
    // 0x8015EAA8: lb          $t8, 0x1C2($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1C2);
    // 0x8015EAAC: sb          $t8, 0x29E($v0)
    MEM_B(0X29E, ctx->r2) = ctx->r24;
    // 0x8015EAB0: lw          $a1, 0x78($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X78);
    // 0x8015EAB4: jal         0x800DF09C
    // 0x8015EAB8: lw          $a0, 0xB18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB18);
    mpCommonRunWeaponCollisionDefault(rdram, ctx);
        goto after_0;
    // 0x8015EAB8: lw          $a0, 0xB18($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB18);
    after_0:
    // 0x8015EABC: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x8015EAC0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_8015EAC4:
    // 0x8015EAC4: b           L_8015EAF8
    // 0x8015EAC8: sw          $t9, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r25;
        goto L_8015EAF8;
    // 0x8015EAC8: sw          $t9, 0x180($s0)
    MEM_W(0X180, ctx->r16) = ctx->r25;
    // 0x8015EACC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8015EAD0:
    // 0x8015EAD0: bne         $v0, $at, L_8015EAF8
    if (ctx->r2 != ctx->r1) {
        // 0x8015EAD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8015EAF8;
    }
    // 0x8015EAD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015EAD8: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x8015EADC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8015EAE0: jal         0x8015E9B0
    // 0x8015EAE4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    ftYoshiSpecialHiGetEggPosition(rdram, ctx);
        goto after_1;
    // 0x8015EAE4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x8015EAE8: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8015EAEC: jal         0x8016C498
    // 0x8015EAF0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    wpYoshiEggThrowMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x8015EAF0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x8015EAF4: sw          $v0, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r2;
L_8015EAF8:
    // 0x8015EAF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015EAFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015EB00: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8015EB04: jr          $ra
    // 0x8015EB08: nop

    return;
    // 0x8015EB08: nop

;}
RECOMP_FUNC void ftCommonFireFlowerShootProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014772C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80147730: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147734: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80147738: jal         0x800DDE84
    // 0x8014773C: addiu       $a1, $a1, 0x77C8
    ctx->r5 = ADD32(ctx->r5, 0X77C8);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x8014773C: addiu       $a1, $a1, 0x77C8
    ctx->r5 = ADD32(ctx->r5, 0X77C8);
    after_0:
    // 0x80147740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80147744: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80147748: jr          $ra
    // 0x8014774C: nop

    return;
    // 0x8014774C: nop

;}
RECOMP_FUNC void mnPlayers1PGameFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134F40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134F44: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134F48: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80134F4C: addiu       $s0, $s0, -0x7118
    ctx->r16 = ADD32(ctx->r16, -0X7118);
    // 0x80134F50: lw          $t6, 0x58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X58);
    // 0x80134F54: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134F58: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134F5C: bnel        $t6, $at, L_80135010
    if (ctx->r14 != ctx->r1) {
        // 0x80134F60: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_80135010;
    }
    goto skip_0;
    // 0x80134F60: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x80134F64: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134F68: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134F6C: lwc1        $f4, -0x714C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X714C);
    // 0x80134F70: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80134F74: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134F78: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80134F7C: nop

    // 0x80134F80: bc1f        L_80134FB4
    if (!c1cs) {
        // 0x80134F84: nop
    
            goto L_80134FB4;
    }
    // 0x80134F84: nop

    // 0x80134F88: lw          $t7, 0x5C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X5C);
    // 0x80134F8C: bnel        $t7, $zero, L_80135050
    if (ctx->r15 != 0) {
        // 0x80134F90: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80135050;
    }
    goto skip_1;
    // 0x80134F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80134F94: jal         0x80134EE0
    // 0x80134F98: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    mnPlayers1PGameGetStatusSelected(rdram, ctx);
        goto after_0;
    // 0x80134F98: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_0:
    // 0x80134F9C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80134FA0: jal         0x803905CC
    // 0x80134FA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_1;
    // 0x80134FA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80134FA8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80134FAC: b           L_8013504C
    // 0x80134FB0: sw          $t8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r24;
        goto L_8013504C;
    // 0x80134FB0: sw          $t8, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r24;
L_80134FB4:
    // 0x80134FB4: lwc1        $f2, -0x7148($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7148);
    // 0x80134FB8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134FBC: lwc1        $f6, -0x7144($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7144);
    // 0x80134FC0: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80134FC4: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x80134FC8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80134FCC: lwc1        $f10, 0x34($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80134FD0: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x80134FD4: nop

    // 0x80134FD8: bc1fl       L_80135050
    if (!c1cs) {
        // 0x80134FDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80135050;
    }
    goto skip_2;
    // 0x80134FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80134FE0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80134FE4: nop

    // 0x80134FE8: swc1        $f16, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f16.u32l;
    // 0x80134FEC: jal         0x80134EE0
    // 0x80134FF0: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    mnPlayers1PGameGetStatusSelected(rdram, ctx);
        goto after_2;
    // 0x80134FF0: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    after_2:
    // 0x80134FF4: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x80134FF8: jal         0x803905CC
    // 0x80134FFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_3;
    // 0x80134FFC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80135000: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80135004: b           L_8013504C
    // 0x80135008: sw          $t9, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r25;
        goto L_8013504C;
    // 0x80135008: sw          $t9, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->r25;
    // 0x8013500C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
L_80135010:
    // 0x80135010: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80135014: lwc1        $f2, -0x7140($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X7140);
    // 0x80135018: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013501C: lwc1        $f4, -0x713C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X713C);
    // 0x80135020: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80135024: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80135028: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x8013502C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135030: lwc1        $f0, 0x34($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X34);
    // 0x80135034: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80135038: nop

    // 0x8013503C: bc1fl       L_80135050
    if (!c1cs) {
        // 0x80135040: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80135050;
    }
    goto skip_3;
    // 0x80135040: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80135044: sub.s       $f8, $f0, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x80135048: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
L_8013504C:
    // 0x8013504C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80135050:
    // 0x80135050: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80135054: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80135058: jr          $ra
    // 0x8013505C: nop

    return;
    // 0x8013505C: nop

;}
RECOMP_FUNC void syAudioSetStereo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020A18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80020A1C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80020A20: jr          $ra
    // 0x80020A24: sw          $t6, -0x34DC($at)
    MEM_W(-0X34DC, ctx->r1) = ctx->r14;
    return;
    // 0x80020A24: sw          $t6, -0x34DC($at)
    MEM_W(-0X34DC, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void syUtilsRandUShort(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018910: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80018914: lw          $a0, -0x46BC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X46BC);
    // 0x80018918: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x8001891C: ori         $at, $at, 0x43FD
    ctx->r1 = ctx->r1 | 0X43FD;
    // 0x80018920: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80018924: multu       $v1, $at
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80018928: lui         $at, 0x26
    ctx->r1 = S32(0X26 << 16);
    // 0x8001892C: ori         $at, $at, 0x9EC3
    ctx->r1 = ctx->r1 | 0X9EC3;
    // 0x80018930: mflo        $v1
    ctx->r3 = lo;
    // 0x80018934: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80018938: sra         $v0, $v1, 16
    ctx->r2 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8001893C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
    // 0x80018940: jr          $ra
    // 0x80018944: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    return;
    // 0x80018944: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
;}
RECOMP_FUNC void sc1PIntroMakeFigures(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321C0: addiu       $sp, $sp, -0x100
    ctx->r29 = ADD32(ctx->r29, -0X100);
    // 0x801321C4: sw          $s7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r23;
    // 0x801321C8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801321CC: addiu       $s7, $sp, 0xB8
    ctx->r23 = ADD32(ctx->r29, 0XB8);
    // 0x801321D0: sw          $s6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r22;
    // 0x801321D4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x801321D8: addiu       $t6, $t6, 0x4E78
    ctx->r14 = ADD32(ctx->r14, 0X4E78);
    // 0x801321DC: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x801321E0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x801321E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801321E8: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x801321EC: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x801321F0: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x801321F4: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x801321F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801321FC: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x80132200: or          $t9, $s7, $zero
    ctx->r25 = ctx->r23 | 0;
L_80132204:
    // 0x80132204: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132208: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013220C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132210: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132214: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132218: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8013221C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132220: bne         $t6, $t0, L_80132204
    if (ctx->r14 != ctx->r8) {
        // 0x80132224: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132204;
    }
    // 0x80132224: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132228: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x8013222C: addiu       $t2, $t2, 0x4EB4
    ctx->r10 = ADD32(ctx->r10, 0X4EB4);
    // 0x80132230: addiu       $t5, $t2, 0x6C
    ctx->r13 = ADD32(ctx->r10, 0X6C);
    // 0x80132234: addiu       $t1, $sp, 0x48
    ctx->r9 = ADD32(ctx->r29, 0X48);
L_80132238:
    // 0x80132238: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8013223C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80132240: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80132244: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80132248: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x8013224C: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80132250: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80132254: bne         $t2, $t5, L_80132238
    if (ctx->r10 != ctx->r13) {
        // 0x80132258: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80132238;
    }
    // 0x80132258: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x8013225C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132268: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8013226C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80132270: jal         0x80009968
    // 0x80132274: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132274: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    after_0:
    // 0x80132278: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013227C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132280: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80132284: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80132288: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013228C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132290: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132294: jal         0x80009DF4
    // 0x80132298: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132298: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8013229C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801322A0: addiu       $s2, $s2, 0x6058
    ctx->r18 = ADD32(ctx->r18, 0X6058);
    // 0x801322A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x801322A8: addiu       $s4, $zero, 0xE
    ctx->r20 = ADD32(0, 0XE);
    // 0x801322AC: addiu       $s3, $zero, -0x21
    ctx->r19 = ADD32(0, -0X21);
    // 0x801322B0: slt         $at, $s0, $s6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r22) ? 1 : 0;
L_801322B4:
    // 0x801322B4: bne         $at, $zero, L_8013231C
    if (ctx->r1 != 0) {
        // 0x801322B8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8013231C;
    }
    // 0x801322B8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x801322BC: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x801322C0: addu        $t9, $s7, $t6
    ctx->r25 = ADD32(ctx->r23, ctx->r14);
    // 0x801322C4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x801322C8: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x801322CC: sll         $t5, $s0, 3
    ctx->r13 = S32(ctx->r16 << 3);
    // 0x801322D0: addiu       $t2, $sp, 0x48
    ctx->r10 = ADD32(ctx->r29, 0X48);
    // 0x801322D4: addu        $s1, $t5, $t2
    ctx->r17 = ADD32(ctx->r13, ctx->r10);
    // 0x801322D8: jal         0x800CCFDC
    // 0x801322DC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801322DC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801322E0: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x801322E4: and         $t4, $t1, $s3
    ctx->r12 = ctx->r9 & ctx->r19;
    // 0x801322E8: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801322EC: ori         $t0, $t4, 0x1
    ctx->r8 = ctx->r12 | 0X1;
    // 0x801322F0: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801322F4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801322F8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801322FC: nop

    // 0x80132300: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132304: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80132308: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x8013230C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80132310: nop

    // 0x80132314: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132318: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_8013231C:
    // 0x8013231C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80132320: bnel        $s0, $s4, L_801322B4
    if (ctx->r16 != ctx->r20) {
        // 0x80132324: slt         $at, $s0, $s6
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r22) ? 1 : 0;
            goto L_801322B4;
    }
    goto skip_0;
    // 0x80132324: slt         $at, $s0, $s6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r22) ? 1 : 0;
    skip_0:
    // 0x80132328: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013232C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80132330: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80132334: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80132338: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x8013233C: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x80132340: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    // 0x80132344: lw          $s6, 0x34($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X34);
    // 0x80132348: lw          $s7, 0x38($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X38);
    // 0x8013234C: jr          $ra
    // 0x80132350: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
    return;
    // 0x80132350: addiu       $sp, $sp, 0x100
    ctx->r29 = ADD32(ctx->r29, 0X100);
;}
RECOMP_FUNC void mnPlayersVSMakeFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134C64: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80134C68: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80134C6C: lui         $t9, 0x4
    ctx->r25 = S32(0X4 << 16);
    // 0x80134C70: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80134C74: ori         $t9, $t9, 0x8600
    ctx->r25 = ctx->r25 | 0X8600;
    // 0x80134C78: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x80134C7C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80134C80: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80134C84: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80134C88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134C8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80134C90: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80134C94: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80134C98: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80134C9C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80134CA0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80134CA4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80134CA8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80134CAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134CB0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80134CB4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80134CB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80134CBC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80134CC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134CC4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80134CC8: jal         0x8000B93C
    // 0x80134CCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80134CCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134CD0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80134CD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134CD8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80134CDC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80134CE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134CE4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80134CE8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80134CEC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80134CF0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80134CF4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80134CF8: jal         0x80007080
    // 0x80134CFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80134CFC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80134D00: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x80134D04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80134D08: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134D0C: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80134D10: swc1        $f0, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f0.u32l;
    // 0x80134D14: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x80134D18: lwc1        $f6, -0x4588($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X4588);
    // 0x80134D1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80134D20: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80134D24: sw          $t4, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r12;
    // 0x80134D28: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x80134D2C: swc1        $f0, 0x4C($v1)
    MEM_W(0X4C, ctx->r3) = ctx->f0.u32l;
    // 0x80134D30: swc1        $f0, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->f0.u32l;
    // 0x80134D34: swc1        $f0, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f0.u32l;
    // 0x80134D38: swc1        $f0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f0.u32l;
    // 0x80134D3C: swc1        $f6, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f6.u32l;
    // 0x80134D40: swc1        $f8, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f8.u32l;
    // 0x80134D44: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80134D48: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80134D4C: jr          $ra
    // 0x80134D50: nop

    return;
    // 0x80134D50: nop

;}
RECOMP_FUNC void scVSBattleFuncUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D0C8: jal         0x8011485C
    // 0x8018D0CC: nop

    ifCommonBattleUpdateInterfaceAll(rdram, ctx);
        goto after_0;
    // 0x8018D0CC: nop

    after_0:
    // 0x8018D0D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D0D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D0D8: jr          $ra
    // 0x8018D0DC: nop

    return;
    // 0x8018D0DC: nop

;}
RECOMP_FUNC void func_ovl23_80132110(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132110: jr          $ra
    // 0x80132114: nop

    return;
    // 0x80132114: nop

;}
RECOMP_FUNC void itGShellWaitInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801787CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801787D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801787D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801787D8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801787DC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801787E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801787E4: jal         0x80173F54
    // 0x801787E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    itMapSetGround(rdram, ctx);
        goto after_0;
    // 0x801787E8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x801787EC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801787F0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801787F4: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x801787F8: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x801787FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80178800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80178804: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80178808: nop

    // 0x8017880C: bc1fl       L_80178820
    if (!c1cs) {
        // 0x80178810: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80178820;
    }
    goto skip_0;
    // 0x80178810: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80178814: b           L_80178820
    // 0x80178818: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80178820;
    // 0x80178818: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8017881C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80178820:
    // 0x80178820: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80178824: nop

    // 0x80178828: bc1fl       L_80178888
    if (!c1cs) {
        // 0x8017882C: lbu         $t0, 0x353($a1)
        ctx->r8 = MEM_BU(ctx->r5, 0X353);
            goto L_80178888;
    }
    goto skip_1;
    // 0x8017882C: lbu         $t0, 0x353($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X353);
    skip_1:
    // 0x80178830: jal         0x80172E74
    // 0x80178834: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_1;
    // 0x80178834: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x80178838: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8017883C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80178840: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80178844: lbu         $t7, 0x2CF($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X2CF);
    // 0x80178848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8017884C: sb          $zero, 0x353($a1)
    MEM_B(0X353, ctx->r5) = 0;
    // 0x80178850: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80178854: sb          $t8, 0x2CF($a1)
    MEM_B(0X2CF, ctx->r5) = ctx->r24;
    // 0x80178858: sw          $t9, 0x248($a1)
    MEM_W(0X248, ctx->r5) = ctx->r25;
    // 0x8017885C: sw          $zero, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = 0;
    // 0x80178860: jal         0x80178704
    // 0x80178864: swc1        $f8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f8.u32l;
    itGShellCommonClearAnim(rdram, ctx);
        goto after_2;
    // 0x80178864: swc1        $f8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f8.u32l;
    after_2:
    // 0x80178868: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017886C: addiu       $a1, $a1, -0x5DCC
    ctx->r5 = ADD32(ctx->r5, -0X5DCC);
    // 0x80178870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80178874: jal         0x80172EC8
    // 0x80178878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_3;
    // 0x80178878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8017887C: b           L_80178900
    // 0x80178880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80178900;
    // 0x80178880: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80178884: lbu         $t0, 0x353($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0X353);
L_80178888:
    // 0x80178888: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8017888C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80178890: beq         $t0, $zero, L_801788B4
    if (ctx->r8 == 0) {
        // 0x80178894: nop
    
            goto L_801788B4;
    }
    // 0x80178894: nop

    // 0x80178898: sw          $t1, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = ctx->r9;
    // 0x8017889C: jal         0x8016F280
    // 0x801788A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_4;
    // 0x801788A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801788A4: jal         0x80178EDC
    // 0x801788A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itGShellSpinSetStatus(rdram, ctx);
        goto after_5;
    // 0x801788A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801788AC: b           L_80178900
    // 0x801788B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80178900;
    // 0x801788B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801788B4:
    // 0x801788B4: jal         0x80172E74
    // 0x801788B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    itMainSetGroundAllowPickup(rdram, ctx);
        goto after_6;
    // 0x801788B8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_6:
    // 0x801788BC: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x801788C0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x801788C4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801788C8: lbu         $t3, 0x2CF($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X2CF);
    // 0x801788CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801788D0: sw          $t5, 0x248($a1)
    MEM_W(0X248, ctx->r5) = ctx->r13;
    // 0x801788D4: ori         $t4, $t3, 0x80
    ctx->r12 = ctx->r11 | 0X80;
    // 0x801788D8: sb          $t4, 0x2CF($a1)
    MEM_B(0X2CF, ctx->r5) = ctx->r12;
    // 0x801788DC: sw          $zero, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = 0;
    // 0x801788E0: jal         0x80178704
    // 0x801788E4: swc1        $f10, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f10.u32l;
    itGShellCommonClearAnim(rdram, ctx);
        goto after_7;
    // 0x801788E4: swc1        $f10, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f10.u32l;
    after_7:
    // 0x801788E8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801788EC: addiu       $a1, $a1, -0x5DCC
    ctx->r5 = ADD32(ctx->r5, -0X5DCC);
    // 0x801788F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801788F4: jal         0x80172EC8
    // 0x801788F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_8;
    // 0x801788F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x801788FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80178900:
    // 0x80178900: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80178904: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80178908: jr          $ra
    // 0x8017890C: nop

    return;
    // 0x8017890C: nop

;}
RECOMP_FUNC void itStarmieAttackInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181D8C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80181D90: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80181D94: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80181D98: lwc1        $f4, 0x364($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X364);
    // 0x80181D9C: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80181DA0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80181DA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80181DA8: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80181DAC: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    // 0x80181DB0: bc1fl       L_80181DC4
    if (!c1cs) {
        // 0x80181DB4: sw          $t7, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->r15;
            goto L_80181DC4;
    }
    goto skip_0;
    // 0x80181DB4: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
    skip_0:
    // 0x80181DB8: b           L_80181DC4
    // 0x80181DBC: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
        goto L_80181DC4;
    // 0x80181DBC: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x80181DC0: sw          $t7, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r15;
L_80181DC4:
    // 0x80181DC4: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x80181DC8: beql        $a1, $a0, L_80181DE8
    if (ctx->r5 == ctx->r4) {
        // 0x80181DCC: mtc1        $a0, $f18
        ctx->f18.u32l = ctx->r4;
            goto L_80181DE8;
    }
    goto skip_1;
    // 0x80181DCC: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
    skip_1:
    // 0x80181DD0: lwc1        $f8, 0x34($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80181DD4: lwc1        $f10, -0x3140($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3140);
    // 0x80181DD8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80181DDC: swc1        $f16, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f16.u32l;
    // 0x80181DE0: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x80181DE4: mtc1        $a0, $f18
    ctx->f18.u32l = ctx->r4;
L_80181DE8:
    // 0x80181DE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80181DEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80181DF0: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80181DF4: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x80181DF8: sh          $t8, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r24;
    // 0x80181DFC: sw          $zero, 0x354($v0)
    MEM_W(0X354, ctx->r2) = 0;
    // 0x80181E00: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80181E04: jr          $ra
    // 0x80181E08: swc1        $f8, 0x370($v0)
    MEM_W(0X370, ctx->r2) = ctx->f8.u32l;
    return;
    // 0x80181E08: swc1        $f8, 0x370($v0)
    MEM_W(0X370, ctx->r2) = ctx->f8.u32l;
;}
RECOMP_FUNC void func_ovl59_80131E70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E70: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x80131E74: lwc1        $f14, 0x10($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X10);
    // 0x80131E78: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80131E7C: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80131E80: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80131E84: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80131E88: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80131E8C: lwc1        $f8, 0x4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80131E90: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80131E94: swc1        $f10, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f10.u32l;
    // 0x80131E98: lwc1        $f16, 0x4($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80131E9C: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80131EA0: mul.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x80131EA4: nop

    // 0x80131EA8: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80131EAC: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80131EB0: jr          $ra
    // 0x80131EB4: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x80131EB4: swc1        $f8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void itLinkBombExplodeWaitUpdateScale(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801859C0: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801859C4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801859C8: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x801859CC: lhu         $a1, 0x356($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X356);
    // 0x801859D0: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801859D4: bnel        $a1, $zero, L_80185A78
    if (ctx->r5 != 0) {
        // 0x801859D8: addiu       $t1, $a1, -0x1
        ctx->r9 = ADD32(ctx->r5, -0X1);
            goto L_80185A78;
    }
    goto skip_0;
    // 0x801859D8: addiu       $t1, $a1, -0x1
    ctx->r9 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x801859DC: lw          $t6, -0x493C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X493C);
    // 0x801859E0: lhu         $a2, 0x354($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X354);
    // 0x801859E4: addiu       $t8, $t8, 0xA8
    ctx->r24 = ADD32(ctx->r24, 0XA8);
    // 0x801859E8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801859EC: slti        $at, $a2, 0x6
    ctx->r1 = SIGNED(ctx->r6) < 0X6 ? 1 : 0;
    // 0x801859F0: bne         $at, $zero, L_80185A04
    if (ctx->r1 != 0) {
        // 0x801859F4: addu        $a0, $t7, $t8
        ctx->r4 = ADD32(ctx->r15, ctx->r24);
            goto L_80185A04;
    }
    // 0x801859F4: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x801859F8: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x801859FC: b           L_80185A08
    // 0x80185A00: subu        $a1, $t9, $a2
    ctx->r5 = SUB32(ctx->r25, ctx->r6);
        goto L_80185A08;
    // 0x80185A00: subu        $a1, $t9, $a2
    ctx->r5 = SUB32(ctx->r25, ctx->r6);
L_80185A04:
    // 0x80185A04: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
L_80185A08:
    // 0x80185A08: lw          $t0, 0x2CC($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2CC);
    // 0x80185A0C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80185A10: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80185A14: sll         $t2, $t0, 17
    ctx->r10 = S32(ctx->r8 << 17);
    // 0x80185A18: bgez        $t2, L_80185A3C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80185A1C: addu        $t8, $a0, $t7
        ctx->r24 = ADD32(ctx->r4, ctx->r15);
            goto L_80185A3C;
    }
    // 0x80185A1C: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x80185A20: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x80185A24: lwc1        $f0, 0x0($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X0);
    // 0x80185A28: lw          $t5, 0x10($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X10);
    // 0x80185A2C: swc1        $f0, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f0.u32l;
    // 0x80185A30: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x80185A34: b           L_80185A48
    // 0x80185A38: swc1        $f0, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f0.u32l;
        goto L_80185A48;
    // 0x80185A38: swc1        $f0, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f0.u32l;
L_80185A3C:
    // 0x80185A3C: lwc1        $f0, 0x0($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80185A40: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x80185A44: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
L_80185A48:
    // 0x80185A48: lhu         $a2, 0x354($v1)
    ctx->r6 = MEM_HU(ctx->r3, 0X354);
    // 0x80185A4C: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80185A50: sh          $t9, 0x356($v1)
    MEM_H(0X356, ctx->r3) = ctx->r25;
    // 0x80185A54: slti        $at, $a2, 0xA
    ctx->r1 = SIGNED(ctx->r6) < 0XA ? 1 : 0;
    // 0x80185A58: bne         $at, $zero, L_80185A6C
    if (ctx->r1 != 0) {
        // 0x80185A5C: addiu       $t0, $a2, 0x1
        ctx->r8 = ADD32(ctx->r6, 0X1);
            goto L_80185A6C;
    }
    // 0x80185A5C: addiu       $t0, $a2, 0x1
    ctx->r8 = ADD32(ctx->r6, 0X1);
    // 0x80185A60: sh          $zero, 0x354($v1)
    MEM_H(0X354, ctx->r3) = 0;
    // 0x80185A64: b           L_80185A74
    // 0x80185A68: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
        goto L_80185A74;
    // 0x80185A68: andi        $a1, $t9, 0xFFFF
    ctx->r5 = ctx->r25 & 0XFFFF;
L_80185A6C:
    // 0x80185A6C: sh          $t0, 0x354($v1)
    MEM_H(0X354, ctx->r3) = ctx->r8;
    // 0x80185A70: lhu         $a1, 0x356($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X356);
L_80185A74:
    // 0x80185A74: addiu       $t1, $a1, -0x1
    ctx->r9 = ADD32(ctx->r5, -0X1);
L_80185A78:
    // 0x80185A78: jr          $ra
    // 0x80185A7C: sh          $t1, 0x356($v1)
    MEM_H(0X356, ctx->r3) = ctx->r9;
    return;
    // 0x80185A7C: sh          $t1, 0x356($v1)
    MEM_H(0X356, ctx->r3) = ctx->r9;
;}
RECOMP_FUNC void mnPlayersVSGetPowerOf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A1C: bne         $a1, $zero, L_80133A2C
    if (ctx->r5 != 0) {
        // 0x80133A20: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80133A2C;
    }
    // 0x80133A20: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80133A24: jr          $ra
    // 0x80133A28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80133A28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133A2C:
    // 0x80133A2C: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80133A30: bne         $at, $zero, L_80133AB0
    if (ctx->r1 != 0) {
        // 0x80133A34: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80133AB0;
    }
    // 0x80133A34: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80133A38: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x80133A3C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80133A40: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x80133A44: beq         $a3, $zero, L_80133A68
    if (ctx->r7 == 0) {
        // 0x80133A48: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_80133A68;
    }
    // 0x80133A48: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
L_80133A4C:
    // 0x80133A4C: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133A50: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80133A54: mflo        $v1
    ctx->r3 = lo;
    // 0x80133A58: bne         $a2, $v0, L_80133A4C
    if (ctx->r6 != ctx->r2) {
        // 0x80133A5C: nop
    
            goto L_80133A4C;
    }
    // 0x80133A5C: nop

    // 0x80133A60: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80133A64: beq         $v0, $a1, L_80133AB0
    if (ctx->r2 == ctx->r5) {
        // 0x80133A68: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80133AB0;
    }
L_80133A68:
    // 0x80133A68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80133A6C:
    // 0x80133A6C: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133A70: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80133A74: mflo        $v1
    ctx->r3 = lo;
    // 0x80133A78: nop

    // 0x80133A7C: nop

    // 0x80133A80: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133A84: mflo        $v1
    ctx->r3 = lo;
    // 0x80133A88: nop

    // 0x80133A8C: nop

    // 0x80133A90: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133A94: mflo        $v1
    ctx->r3 = lo;
    // 0x80133A98: nop

    // 0x80133A9C: nop

    // 0x80133AA0: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80133AA4: mflo        $v1
    ctx->r3 = lo;
    // 0x80133AA8: bne         $v0, $a1, L_80133A6C
    if (ctx->r2 != ctx->r5) {
        // 0x80133AAC: nop
    
            goto L_80133A6C;
    }
    // 0x80133AAC: nop

L_80133AB0:
    // 0x80133AB0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80133AB4: jr          $ra
    // 0x80133AB8: nop

    return;
    // 0x80133AB8: nop

;}
RECOMP_FUNC void ftCommonItemThrowUpdateModelYaw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801462A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801462A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801462A8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801462AC: lw          $a1, 0x188($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X188);
    // 0x801462B0: beq         $a1, $zero, L_801462C8
    if (ctx->r5 == 0) {
        // 0x801462B4: srl         $t6, $a1, 1
        ctx->r14 = S32(U32(ctx->r5) >> 1);
            goto L_801462C8;
    }
    // 0x801462B4: srl         $t6, $a1, 1
    ctx->r14 = S32(U32(ctx->r5) >> 1);
    // 0x801462B8: sw          $a1, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r5;
    // 0x801462BC: sw          $a1, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r5;
    // 0x801462C0: sw          $t6, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r14;
    // 0x801462C4: sw          $zero, 0x188($v0)
    MEM_W(0X188, ctx->r2) = 0;
L_801462C8:
    // 0x801462C8: lw          $v1, 0xB1C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB1C);
    // 0x801462CC: beql        $v1, $zero, L_80146340
    if (ctx->r3 == 0) {
        // 0x801462D0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80146340;
    }
    goto skip_0;
    // 0x801462D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801462D4: lw          $a0, 0xB20($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XB20);
    // 0x801462D8: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x801462DC: sw          $t7, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r15;
    // 0x801462E0: beq         $a0, $zero, L_801462FC
    if (ctx->r4 == 0) {
        // 0x801462E4: addiu       $t8, $a0, -0x1
        ctx->r24 = ADD32(ctx->r4, -0X1);
            goto L_801462FC;
    }
    // 0x801462E4: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x801462E8: bne         $t8, $zero, L_801462FC
    if (ctx->r24 != 0) {
        // 0x801462EC: sw          $t8, 0xB20($v0)
        MEM_W(0XB20, ctx->r2) = ctx->r24;
            goto L_801462FC;
    }
    // 0x801462EC: sw          $t8, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r24;
    // 0x801462F0: lw          $t0, 0x44($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X44);
    // 0x801462F4: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x801462F8: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
L_801462FC:
    // 0x801462FC: lw          $t2, 0xB18($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XB18);
    // 0x80146300: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80146304: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80146308: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8014630C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80146310: lwc1        $f10, -0x3E60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3E60);
    // 0x80146314: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80146318: lw          $v1, 0x8E8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8E8);
    // 0x8014631C: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x80146320: div.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80146324: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80146328: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8014632C: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80146330: swc1        $f6, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f6.u32l;
    // 0x80146334: jal         0x800EB528
    // 0x80146338: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_0;
    // 0x80146338: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    after_0:
    // 0x8014633C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80146340:
    // 0x80146340: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80146344: jr          $ra
    // 0x80146348: nop

    return;
    // 0x80146348: nop

;}
RECOMP_FUNC void mpProcessCheckFloorEdgeCollisionL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9A00: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D9A04: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800D9A08: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800D9A0C: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800D9A10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800D9A14: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x800D9A18: jal         0x800FAA24
    // 0x800D9A1C: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    mpCollisionGetEdgeUnderLLineID(rdram, ctx);
        goto after_0;
    // 0x800D9A1C: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    after_0:
    // 0x800D9A20: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800D9A24: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800D9A28: addiu       $v1, $s0, 0x38
    ctx->r3 = ADD32(ctx->r16, 0X38);
    // 0x800D9A2C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D9A30: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800D9A34: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800D9A38: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D9A3C: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800D9A40: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D9A44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D9A48: addiu       $a3, $s0, 0x60
    ctx->r7 = ADD32(ctx->r16, 0X60);
    // 0x800D9A4C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D9A50: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800D9A54: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9A58: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D9A5C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D9A60: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800D9A64: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D9A68: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D9A6C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D9A70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D9A74: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D9A78: jal         0x800F7F00
    // 0x800D9A7C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800D9A7C: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800D9A80: beq         $v0, $zero, L_800D9AA0
    if (ctx->r2 == 0) {
        // 0x800D9A84: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800D9AA0;
    }
    // 0x800D9A84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D9A88: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D9A8C: lw          $t7, 0x60($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X60);
    // 0x800D9A90: beql        $t6, $t7, L_800D9AA4
    if (ctx->r14 == ctx->r15) {
        // 0x800D9A94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D9AA4;
    }
    goto skip_0;
    // 0x800D9A94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800D9A98: b           L_800D9AA4
    // 0x800D9A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D9AA4;
    // 0x800D9A9C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D9AA0:
    // 0x800D9AA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D9AA4:
    // 0x800D9AA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800D9AA8: jr          $ra
    // 0x800D9AAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800D9AAC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void mvOpeningLinkMakeMotionCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D3EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D3F0: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D3F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018D3F8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8018D3FC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8018D400: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D404: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8018D408: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8018D40C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x8018D410: addiu       $t6, $t6, -0x1F90
    ctx->r14 = ADD32(ctx->r14, -0X1F90);
    // 0x8018D414: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D418: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D41C: addiu       $s0, $s0, -0x1E18
    ctx->r16 = ADD32(ctx->r16, -0X1E18);
    // 0x8018D420: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8018D424: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8018D428: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D42C: addiu       $t9, $t9, -0x1F74
    ctx->r25 = ADD32(ctx->r25, -0X1F74);
    // 0x8018D430: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x8018D434: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8018D438: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018D43C: addiu       $s1, $s1, -0x1DF8
    ctx->r17 = ADD32(ctx->r17, -0X1DF8);
    // 0x8018D440: sw          $t8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r24;
    // 0x8018D444: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8018D448: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D44C: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
    // 0x8018D450: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x8018D454: sw          $t8, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r24;
    // 0x8018D458: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x8018D45C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x8018D460: lw          $t8, 0x18($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X18);
    // 0x8018D464: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x8018D468: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x8018D46C: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8018D470: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x8018D474: sw          $t0, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r8;
    // 0x8018D478: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x8018D47C: sw          $t1, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r9;
    // 0x8018D480: lw          $t0, 0xC($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XC);
    // 0x8018D484: sw          $t0, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->r8;
    // 0x8018D488: lw          $t1, 0x10($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X10);
    // 0x8018D48C: sw          $t1, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r9;
    // 0x8018D490: lw          $t0, 0x14($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X14);
    // 0x8018D494: sw          $t0, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r8;
    // 0x8018D498: lw          $t1, 0x18($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X18);
    // 0x8018D49C: jal         0x8010DB2C
    // 0x8018D4A0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    gmCameraMakeMovieCamera(rdram, ctx);
        goto after_0;
    // 0x8018D4A0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    after_0:
    // 0x8018D4A4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D4A8: addiu       $v1, $v1, -0x1E28
    ctx->r3 = ADD32(ctx->r3, -0X1E28);
    // 0x8018D4AC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8018D4B0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018D4B4: lw          $s2, 0x74($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X74);
    // 0x8018D4B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018D4BC: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8018D4C0: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x8018D4C4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018D4C8: addiu       $a0, $s2, 0x8
    ctx->r4 = ADD32(ctx->r18, 0X8);
    // 0x8018D4CC: jal         0x80007080
    // 0x8018D4D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018D4D0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018D4D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D4D8: lwc1        $f6, -0x1E54($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1E54);
    // 0x8018D4DC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D4E0: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x8018D4E4: jal         0x8000B39C
    // 0x8018D4E8: lw          $a0, -0x1E28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E28);
    gcEndProcessAll(rdram, ctx);
        goto after_2;
    // 0x8018D4E8: lw          $a0, -0x1E28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E28);
    after_2:
    // 0x8018D4EC: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D4F0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D4F4: addiu       $a1, $a1, -0x2D0C
    ctx->r5 = ADD32(ctx->r5, -0X2D0C);
    // 0x8018D4F8: lw          $a0, -0x1E28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1E28);
    // 0x8018D4FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D500: jal         0x80008188
    // 0x8018D504: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018D504: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018D508: lwc1        $f0, 0x30($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8018D50C: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8018D510: lwc1        $f12, 0x38($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8018D514: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D518: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D51C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D520: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D524: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D528: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D52C: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D530: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x8018D534: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D538: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D53C: swc1        $f18, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f18.u32l;
    // 0x8018D540: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D544: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8018D548: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D54C: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D550: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8018D554: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8018D558: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D55C: lwc1        $f4, 0x8($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8018D560: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
    // 0x8018D564: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D568: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
    // 0x8018D56C: lwc1        $f8, 0xC($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8018D570: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D574: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8018D578: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
    // 0x8018D57C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D580: lwc1        $f4, 0x14($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8018D584: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
    // 0x8018D588: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8018D58C: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
    // 0x8018D590: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8018D594: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8018D598: swc1        $f10, 0xC($s1)
    MEM_W(0XC, ctx->r17) = ctx->f10.u32l;
    // 0x8018D59C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x8018D5A0: swc1        $f18, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->f18.u32l;
    // 0x8018D5A4: swc1        $f6, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f6.u32l;
    // 0x8018D5A8: swc1        $f8, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5AC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8018D5B0: swc1        $f10, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f10.u32l;
    // 0x8018D5B4: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8018D5B8: swc1        $f16, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f16.u32l;
    // 0x8018D5BC: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8018D5C0: swc1        $f18, 0x48($s2)
    MEM_W(0X48, ctx->r18) = ctx->f18.u32l;
    // 0x8018D5C4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8018D5C8: swc1        $f4, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->f4.u32l;
    // 0x8018D5CC: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8018D5D0: swc1        $f6, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->f6.u32l;
    // 0x8018D5D4: lwc1        $f8, 0x18($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8018D5D8: swc1        $f8, 0x54($s2)
    MEM_W(0X54, ctx->r18) = ctx->f8.u32l;
    // 0x8018D5DC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D5E0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8018D5E4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8018D5E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D5EC: jr          $ra
    // 0x8018D5F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018D5F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mvOpeningRoomMakeCloseUpOverlayCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D48: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132D4C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132D50: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132D54: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132D58: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80132D5C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132D60: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80132D64: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132D68: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132D6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132D70: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132D74: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132D78: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132D7C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132D80: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132D84: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132D88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132D8C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132D90: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132D94: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132D98: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132D9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132DA0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132DA4: jal         0x8000B93C
    // 0x80132DA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132DA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132DAC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132DB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132DB4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132DB8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132DBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132DC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132DC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132DC8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132DCC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132DD0: jal         0x80007080
    // 0x80132DD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132DD4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132DD8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132DDC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132DE0: jr          $ra
    // 0x80132DE4: nop

    return;
    // 0x80132DE4: nop

;}
RECOMP_FUNC void gcDrawDObjDLLinksForGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800143FC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80014400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80014404: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80014408: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001440C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80014410: swc1        $f4, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f4.u32l;
    // 0x80014414: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x80014418: jal         0x80014068
    // 0x8001441C: lw          $a1, 0x50($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X50);
    gcDrawDObjDLLinks(rdram, ctx);
        goto after_0;
    // 0x8001441C: lw          $a1, 0x50($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X50);
    after_0:
    // 0x80014420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80014424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80014428: jr          $ra
    // 0x8001442C: nop

    return;
    // 0x8001442C: nop

;}
RECOMP_FUNC void itSawamuraMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182B74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80182B78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80182B7C: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80182B80: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80182B84: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80182B88: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80182B8C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80182B90: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80182B94: addiu       $a1, $a1, -0x4DE0
    ctx->r5 = ADD32(ctx->r5, -0X4DE0);
    // 0x80182B98: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80182B9C: jal         0x8016E174
    // 0x80182BA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80182BA0: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80182BA4: beq         $v0, $zero, L_80182C6C
    if (ctx->r2 == 0) {
        // 0x80182BA8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80182C6C;
    }
    // 0x80182BA8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80182BAC: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80182BB0: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x80182BB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80182BB8: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80182BBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80182BC0: addiu       $t6, $zero, 0x16
    ctx->r14 = ADD32(0, 0X16);
    // 0x80182BC4: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x80182BC8: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x80182BCC: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x80182BD0: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x80182BD4: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80182BD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80182BDC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80182BE0: jal         0x80008CC0
    // 0x80182BE4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80182BE4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x80182BE8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80182BEC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80182BF0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80182BF4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80182BF8: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80182BFC: addiu       $t4, $t4, 0x1F40
    ctx->r12 = ADD32(ctx->r12, 0X1F40);
    // 0x80182C00: sw          $t9, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r25;
    // 0x80182C04: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80182C08: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x80182C0C: addiu       $t6, $t6, 0x3624
    ctx->r14 = ADD32(ctx->r14, 0X3624);
    // 0x80182C10: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x80182C14: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80182C18: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80182C1C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80182C20: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x80182C24: lw          $t0, 0x2D4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X2D4);
    // 0x80182C28: lh          $t1, 0x2E($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X2E);
    // 0x80182C2C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80182C30: nop

    // 0x80182C34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80182C38: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80182C3C: swc1        $f16, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f16.u32l;
    // 0x80182C40: lw          $t2, 0x2D4($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X2D4);
    // 0x80182C44: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80182C48: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80182C4C: jal         0x8000BD1C
    // 0x80182C50: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_2;
    // 0x80182C50: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x80182C54: jal         0x800269C0
    // 0x80182C58: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80182C58: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    after_3:
    // 0x80182C5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80182C60: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x80182C64: jal         0x8000A14C
    // 0x80182C68: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    gcMoveGObjDLHead(rdram, ctx);
        goto after_4;
    // 0x80182C68: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    after_4:
L_80182C6C:
    // 0x80182C6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80182C70: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80182C74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80182C78: jr          $ra
    // 0x80182C7C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80182C7C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sc1PBonusStageUpdateTargetCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D510: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8018D514: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8018D518: lbu         $t6, 0xC($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0XC);
    // 0x8018D51C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D524: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8018D528: jal         0x8018D4C4
    // 0x8018D52C: sb          $t7, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r15;
    sc1PBonusStageUpdateTargetInterface(rdram, ctx);
        goto after_0;
    // 0x8018D52C: sb          $t7, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r15;
    after_0:
    // 0x8018D530: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8018D534: lbu         $t8, 0x13FC($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X13FC);
    // 0x8018D538: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8018D53C: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x8018D540: bnel        $t8, $zero, L_8018D5BC
    if (ctx->r24 != 0) {
        // 0x8018D544: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D5BC;
    }
    goto skip_0;
    // 0x8018D544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018D548: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x8018D54C: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x8018D550: beq         $t9, $at, L_8018D5A8
    if (ctx->r25 == ctx->r1) {
        // 0x8018D554: nop
    
            goto L_8018D5A8;
    }
    // 0x8018D554: nop

    // 0x8018D558: lbu         $t0, 0x39($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X39);
    // 0x8018D55C: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x8018D560: addiu       $t2, $t2, 0x44E0
    ctx->r10 = ADD32(ctx->r10, 0X44E0);
    // 0x8018D564: sll         $t1, $t0, 5
    ctx->r9 = S32(ctx->r8 << 5);
    // 0x8018D568: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8018D56C: lbu         $t3, 0x470($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X470);
    // 0x8018D570: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018D574: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8018D578: bne         $t3, $at, L_8018D5A8
    if (ctx->r11 != ctx->r1) {
        // 0x8018D57C: nop
    
            goto L_8018D5A8;
    }
    // 0x8018D57C: nop

    // 0x8018D580: lw          $t4, 0x50E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50E8);
    // 0x8018D584: lw          $t6, 0x46C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X46C);
    // 0x8018D588: lw          $t5, 0x18($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X18);
    // 0x8018D58C: sltu        $at, $t5, $t6
    ctx->r1 = ctx->r13 < ctx->r14 ? 1 : 0;
    // 0x8018D590: beq         $at, $zero, L_8018D5A8
    if (ctx->r1 == 0) {
        // 0x8018D594: nop
    
            goto L_8018D5A8;
    }
    // 0x8018D594: nop

    // 0x8018D598: jal         0x80114D58
    // 0x8018D59C: addiu       $a0, $zero, 0x1D0
    ctx->r4 = ADD32(0, 0X1D0);
    ifCommonAnnounceCompleteInitInterface(rdram, ctx);
        goto after_1;
    // 0x8018D59C: addiu       $a0, $zero, 0x1D0
    ctx->r4 = ADD32(0, 0X1D0);
    after_1:
    // 0x8018D5A0: b           L_8018D5B0
    // 0x8018D5A4: nop

        goto L_8018D5B0;
    // 0x8018D5A4: nop

L_8018D5A8:
    // 0x8018D5A8: jal         0x80114D58
    // 0x8018D5AC: addiu       $a0, $zero, 0x1CB
    ctx->r4 = ADD32(0, 0X1CB);
    ifCommonAnnounceCompleteInitInterface(rdram, ctx);
        goto after_2;
    // 0x8018D5AC: addiu       $a0, $zero, 0x1CB
    ctx->r4 = ADD32(0, 0X1CB);
    after_2:
L_8018D5B0:
    // 0x8018D5B0: jal         0x80113804
    // 0x8018D5B4: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    ifCommonBattleEndAddSoundQueueID(rdram, ctx);
        goto after_3;
    // 0x8018D5B4: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    after_3:
    // 0x8018D5B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D5BC:
    // 0x8018D5BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D5C0: jr          $ra
    // 0x8018D5C4: nop

    return;
    // 0x8018D5C4: nop

;}
RECOMP_FUNC void alCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035740: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80035744: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80035748: blez        $a2, L_800357AC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8003574C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800357AC;
    }
    // 0x8003574C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80035750: andi        $a1, $a2, 0x3
    ctx->r5 = ctx->r6 & 0X3;
    // 0x80035754: beq         $a1, $zero, L_8003577C
    if (ctx->r5 == 0) {
        // 0x80035758: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8003577C;
    }
    // 0x80035758: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8003575C:
    // 0x8003575C: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80035760: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80035764: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80035768: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8003576C: bne         $a0, $a3, L_8003575C
    if (ctx->r4 != ctx->r7) {
        // 0x80035770: sb          $t6, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r14;
            goto L_8003575C;
    }
    // 0x80035770: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x80035774: beq         $a3, $a2, L_800357AC
    if (ctx->r7 == ctx->r6) {
        // 0x80035778: nop
    
            goto L_800357AC;
    }
    // 0x80035778: nop

L_8003577C:
    // 0x8003577C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x80035780: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80035784: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80035788: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x8003578C: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80035790: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80035794: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x80035798: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x8003579C: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x800357A0: lbu         $t0, -0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X1);
    // 0x800357A4: bne         $a3, $a2, L_8003577C
    if (ctx->r7 != ctx->r6) {
        // 0x800357A8: sb          $t0, -0x1($v1)
        MEM_B(-0X1, ctx->r3) = ctx->r8;
            goto L_8003577C;
    }
    // 0x800357A8: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
L_800357AC:
    // 0x800357AC: jr          $ra
    // 0x800357B0: nop

    return;
    // 0x800357B0: nop

;}
RECOMP_FUNC void mnTitleMakeLogoFire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133DDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133DE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133DE4: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80133DE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133DEC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80133DF0: jal         0x80009968
    // 0x80133DF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80133DF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133DF8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133DFC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80133E00: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80133E04: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133E08: addiu       $a1, $a1, 0x3CFC
    ctx->r5 = ADD32(ctx->r5, 0X3CFC);
    // 0x80133E0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133E10: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80133E14: jal         0x80009DF4
    // 0x80133E18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80133E18: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133E1C: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80133E20: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133E24: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133E28: lui         $a0, 0xB2
    ctx->r4 = S32(0XB2 << 16);
    // 0x80133E2C: lui         $a1, 0xB2
    ctx->r5 = S32(0XB2 << 16);
    // 0x80133E30: lui         $a2, 0xB2
    ctx->r6 = S32(0XB2 << 16);
    // 0x80133E34: lui         $a3, 0xB2
    ctx->r7 = S32(0XB2 << 16);
    // 0x80133E38: addiu       $a3, $a3, 0x77B0
    ctx->r7 = ADD32(ctx->r7, 0X77B0);
    // 0x80133E3C: addiu       $a2, $a2, 0x2D40
    ctx->r6 = ADD32(ctx->r6, 0X2D40);
    // 0x80133E40: addiu       $a1, $a1, 0x2D40
    ctx->r5 = ADD32(ctx->r5, 0X2D40);
    // 0x80133E44: addiu       $a0, $a0, 0x2C30
    ctx->r4 = ADD32(ctx->r4, 0X2C30);
    // 0x80133E48: sw          $t9, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->r25;
    // 0x80133E4C: jal         0x801159F8
    // 0x80133E50: sw          $t8, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r24;
    efParticleGetLoadBankID(rdram, ctx);
        goto after_2;
    // 0x80133E50: sw          $t8, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->r24;
    after_2:
    // 0x80133E54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133E58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E5C: sw          $v0, 0x444C($at)
    MEM_W(0X444C, ctx->r1) = ctx->r2;
    // 0x80133E60: jr          $ra
    // 0x80133E64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80133E64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_8037C5E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C5E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C5EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C5F0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037C5F4: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8037C5F8: jal         0x8000B16C
    // 0x8037C5FC: addiu       $a1, $zero, -0x1FD
    ctx->r5 = ADD32(0, -0X1FD);
    gcFindGObjByLinkAndID(rdram, ctx);
        goto after_0;
    // 0x8037C5FC: addiu       $a1, $zero, -0x1FD
    ctx->r5 = ADD32(0, -0X1FD);
    after_0:
    // 0x8037C600: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037C604: sw          $v0, -0x5E3C($at)
    MEM_W(-0X5E3C, ctx->r1) = ctx->r2;
    // 0x8037C608: addiu       $a0, $zero, 0x1F
    ctx->r4 = ADD32(0, 0X1F);
    // 0x8037C60C: jal         0x8000B16C
    // 0x8037C610: addiu       $a1, $zero, -0x1FC
    ctx->r5 = ADD32(0, -0X1FC);
    gcFindGObjByLinkAndID(rdram, ctx);
        goto after_1;
    // 0x8037C610: addiu       $a1, $zero, -0x1FC
    ctx->r5 = ADD32(0, -0X1FC);
    after_1:
    // 0x8037C614: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8037C618: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037C61C: addiu       $a0, $a0, -0x5E38
    ctx->r4 = ADD32(ctx->r4, -0X5E38);
    // 0x8037C620: bne         $t6, $zero, L_8037C634
    if (ctx->r14 != 0) {
        // 0x8037C624: sw          $v0, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r2;
            goto L_8037C634;
    }
    // 0x8037C624: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8037C628: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x8037C62C: b           L_8037C638
    // 0x8037C630: lw          $v1, -0x5E3C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E3C);
        goto L_8037C638;
    // 0x8037C630: lw          $v1, -0x5E3C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5E3C);
L_8037C634:
    // 0x8037C634: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
L_8037C638:
    // 0x8037C638: bne         $v1, $zero, L_8037C648
    if (ctx->r3 != 0) {
        // 0x8037C63C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037C648;
    }
    // 0x8037C63C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037C640: b           L_8037C64C
    // 0x8037C644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037C64C;
    // 0x8037C644: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037C648:
    // 0x8037C648: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
L_8037C64C:
    // 0x8037C64C: jr          $ra
    // 0x8037C650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8037C650: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void gmRumbleResumeProcessAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115834: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80115838: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8011583C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80115840: lw          $s0, 0x6724($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6724);
    // 0x80115844: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80115848: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011584C: beq         $s0, $zero, L_80115874
    if (ctx->r16 == 0) {
        // 0x80115850: addiu       $s1, $zero, 0x3F9
        ctx->r17 = ADD32(0, 0X3F9);
            goto L_80115874;
    }
    // 0x80115850: addiu       $s1, $zero, 0x3F9
    ctx->r17 = ADD32(0, 0X3F9);
    // 0x80115854: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_80115858:
    // 0x80115858: bnel        $s1, $t6, L_8011586C
    if (ctx->r17 != ctx->r14) {
        // 0x8011585C: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_8011586C;
    }
    goto skip_0;
    // 0x8011585C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80115860: jal         0x8000B2B8
    // 0x80115864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcResumeGObjProcessAll(rdram, ctx);
        goto after_0;
    // 0x80115864: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80115868: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_8011586C:
    // 0x8011586C: bnel        $s0, $zero, L_80115858
    if (ctx->r16 != 0) {
        // 0x80115870: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_80115858;
    }
    goto skip_1;
    // 0x80115870: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80115874:
    // 0x80115874: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80115878: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8011587C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80115880: jr          $ra
    // 0x80115884: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80115884: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnPlayersVSCheckPlayerKindSelectInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135AB8: sll         $v1, $a1, 4
    ctx->r3 = S32(ctx->r5 << 4);
    // 0x80135ABC: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80135AC0: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80135AC4: addu        $v1, $v1, $a1
    ctx->r3 = ADD32(ctx->r3, ctx->r5);
    // 0x80135AC8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135ACC: addiu       $t6, $v1, 0x3C
    ctx->r14 = ADD32(ctx->r3, 0X3C);
    // 0x80135AD0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80135AD4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80135AD8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135ADC: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135AE0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80135AE4: addiu       $t7, $v1, 0x58
    ctx->r15 = ADD32(ctx->r3, 0X58);
    // 0x80135AE8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135AEC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80135AF0: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135AF4: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x80135AF8: nop

    // 0x80135AFC: bc1f        L_80135B28
    if (!c1cs) {
        // 0x80135B00: nop
    
            goto L_80135B28;
    }
    // 0x80135B00: nop

    // 0x80135B04: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80135B08: nop

    // 0x80135B0C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80135B10: c.le.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl <= ctx->f18.fl;
    // 0x80135B14: nop

    // 0x80135B18: bc1f        L_80135B28
    if (!c1cs) {
        // 0x80135B1C: nop
    
            goto L_80135B28;
    }
    // 0x80135B1C: nop

    // 0x80135B20: b           L_80135B28
    // 0x80135B24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135B28;
    // 0x80135B24: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135B28:
    // 0x80135B28: beql        $v1, $zero, L_80135B90
    if (ctx->r3 == 0) {
        // 0x80135B2C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80135B90;
    }
    goto skip_0;
    // 0x80135B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80135B30: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80135B34: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135B38: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x80135B3C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135B40: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135B44: lui         $at, 0x4311
    ctx->r1 = S32(0X4311 << 16);
    // 0x80135B48: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135B4C: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x80135B50: nop

    // 0x80135B54: bc1f        L_80135B7C
    if (!c1cs) {
        // 0x80135B58: nop
    
            goto L_80135B7C;
    }
    // 0x80135B58: nop

    // 0x80135B5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135B60: nop

    // 0x80135B64: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80135B68: nop

    // 0x80135B6C: bc1f        L_80135B7C
    if (!c1cs) {
        // 0x80135B70: nop
    
            goto L_80135B7C;
    }
    // 0x80135B70: nop

    // 0x80135B74: b           L_80135B7C
    // 0x80135B78: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80135B7C;
    // 0x80135B78: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80135B7C:
    // 0x80135B7C: beql        $v1, $zero, L_80135B90
    if (ctx->r3 == 0) {
        // 0x80135B80: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80135B90;
    }
    goto skip_1;
    // 0x80135B80: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80135B84: jr          $ra
    // 0x80135B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80135B88: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80135B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80135B90:
    // 0x80135B90: jr          $ra
    // 0x80135B94: nop

    return;
    // 0x80135B94: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152B6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152B74: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80152B78: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80152B7C: jal         0x800DDDA8
    // 0x80152B80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80152B80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80152B84: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80152B88: bne         $v0, $zero, L_80152BCC
    if (ctx->r2 != 0) {
        // 0x80152B8C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80152BCC;
    }
    // 0x80152B8C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80152B90: lhu         $t6, 0xCE($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XCE);
    // 0x80152B94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80152B98: andi        $t7, $t6, 0x21
    ctx->r15 = ctx->r14 & 0X21;
    // 0x80152B9C: beq         $t7, $zero, L_80152BBC
    if (ctx->r15 == 0) {
        // 0x80152BA0: nop
    
            goto L_80152BBC;
    }
    // 0x80152BA0: nop

    // 0x80152BA4: jal         0x800DEEC8
    // 0x80152BA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_1;
    // 0x80152BA8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80152BAC: jal         0x80153654
    // 0x80152BB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPikachuSpecialAirHiEndSetStatus(rdram, ctx);
        goto after_2;
    // 0x80152BB0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80152BB4: b           L_80152BE8
    // 0x80152BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80152BE8;
    // 0x80152BB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80152BBC:
    // 0x80152BBC: jal         0x80152DD8
    // 0x80152BC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftPikachuSpecialHiSwitchStatusAir(rdram, ctx);
        goto after_3;
    // 0x80152BC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80152BC4: b           L_80152BE8
    // 0x80152BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80152BE8;
    // 0x80152BC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80152BCC:
    // 0x80152BCC: lhu         $t8, 0xCE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XCE);
    // 0x80152BD0: andi        $t9, $t8, 0x21
    ctx->r25 = ctx->r24 & 0X21;
    // 0x80152BD4: beql        $t9, $zero, L_80152BE8
    if (ctx->r25 == 0) {
        // 0x80152BD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80152BE8;
    }
    goto skip_0;
    // 0x80152BD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80152BDC: jal         0x801535F4
    // 0x80152BE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftPikachuSpecialHiEndSetStatus(rdram, ctx);
        goto after_4;
    // 0x80152BE0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80152BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80152BE8:
    // 0x80152BE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80152BEC: jr          $ra
    // 0x80152BF0: nop

    return;
    // 0x80152BF0: nop

;}
RECOMP_FUNC void itGShellCommonProcShield(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801790F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801790F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801790FC: jal         0x80172FE0
    // 0x80179100: nop

    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x80179100: nop

    after_0:
    // 0x80179104: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179108: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017910C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80179110: jr          $ra
    // 0x80179114: nop

    return;
    // 0x80179114: nop

;}
RECOMP_FUNC void func_ovl8_80385F04(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385F04: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80385F08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385F0C: sw          $a0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r4;
    // 0x80385F10: sw          $a1, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r5;
    // 0x80385F14: sw          $a2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r6;
    // 0x80385F18: sw          $a3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r7;
    // 0x80385F1C: addiu       $a1, $sp, 0x118
    ctx->r5 = ADD32(ctx->r29, 0X118);
    // 0x80385F20: jal         0x80386BE0
    // 0x80385F24: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_ovl8_80386BE0(rdram, ctx);
        goto after_0;
    // 0x80385F24: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x80385F28: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80385F2C: jal         0x80385F44
    // 0x80385F30: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    func_ovl8_80385F44(rdram, ctx);
        goto after_1;
    // 0x80385F30: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80385F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80385F38: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    // 0x80385F3C: jr          $ra
    // 0x80385F40: nop

    return;
    // 0x80385F40: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwLoopSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801522DC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801522E0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801522E4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801522E8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801522EC: jal         0x800DEEC8
    // 0x801522F0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801522F0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x801522F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801522F8: addiu       $t7, $zero, 0x4097
    ctx->r15 = ADD32(0, 0X4097);
    // 0x801522FC: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x80152300: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80152304: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80152308: jal         0x800E6F24
    // 0x8015230C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015230C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80152310: jal         0x800D8EB8
    // 0x80152314: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80152314: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80152318: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015231C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80152320: jr          $ra
    // 0x80152324: nop

    return;
    // 0x80152324: nop

;}
RECOMP_FUNC void sc1PStageClearFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134CC4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80134CC8: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80134CCC: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80134CD0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80134CD4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80134CD8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134CDC: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80134CE0: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80134CE4: addiu       $t8, $t8, 0x53D0
    ctx->r24 = ADD32(ctx->r24, 0X53D0);
    // 0x80134CE8: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x80134CEC: addiu       $t0, $t0, 0x5550
    ctx->r8 = ADD32(ctx->r8, 0X5550);
    // 0x80134CF0: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80134CF4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x80134CF8: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x80134CFC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80134D00: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80134D04: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x80134D08: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x80134D0C: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80134D10: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
    // 0x80134D14: jal         0x800CDF78
    // 0x80134D18: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80134D18: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x80134D1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134D20: addiu       $a0, $a0, 0x4EE0
    ctx->r4 = ADD32(ctx->r4, 0X4EE0);
    // 0x80134D24: jal         0x800CDEEC
    // 0x80134D28: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80134D28: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    after_1:
    // 0x80134D2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134D30: jal         0x80004980
    // 0x80134D34: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80134D34: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80134D38: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134D3C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80134D40: addiu       $a2, $a2, 0x5588
    ctx->r6 = ADD32(ctx->r6, 0X5588);
    // 0x80134D44: addiu       $a0, $a0, 0x4EE0
    ctx->r4 = ADD32(ctx->r4, 0X4EE0);
    // 0x80134D48: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80134D4C: jal         0x800CDE04
    // 0x80134D50: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80134D50: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80134D54: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134D58: addiu       $a1, $a1, 0x49F0
    ctx->r5 = ADD32(ctx->r5, 0X49F0);
    // 0x80134D5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134D60: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80134D64: jal         0x80009968
    // 0x80134D68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80134D68: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80134D6C: jal         0x80134AF4
    // 0x80134D70: nop

    sc1PStageClearCopyFramebufToWallpaper(rdram, ctx);
        goto after_5;
    // 0x80134D70: nop

    after_5:
    // 0x80134D74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134D78: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80134D7C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80134D80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80134D84: jal         0x8000B9FC
    // 0x80134D88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_6;
    // 0x80134D88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x80134D8C: jal         0x80133C88
    // 0x80134D90: nop

    sc1PStageClearInitVars(rdram, ctx);
        goto after_7;
    // 0x80134D90: nop

    after_7:
    // 0x80134D94: jal         0x80133B48
    // 0x80134D98: nop

    sc1PStageClearMakeTextCamera(rdram, ctx);
        goto after_8;
    // 0x80134D98: nop

    after_8:
    // 0x80134D9C: jal         0x80133BE8
    // 0x80134DA0: nop

    sc1PStageClearMakeWallpaperCamera(rdram, ctx);
        goto after_9;
    // 0x80134DA0: nop

    after_9:
    // 0x80134DA4: jal         0x80133AC0
    // 0x80134DA8: nop

    sc1PStageClearMakeWallpaper(rdram, ctx);
        goto after_10;
    // 0x80134DA8: nop

    after_10:
    // 0x80134DAC: jal         0x8013213C
    // 0x80134DB0: nop

    sc1PStageClearMakeTextSObjs(rdram, ctx);
        goto after_11;
    // 0x80134DB0: nop

    after_11:
    // 0x80134DB4: jal         0x801323F8
    // 0x80134DB8: nop

    sc1PStageClearMakeScoreSObjs(rdram, ctx);
        goto after_12;
    // 0x80134DB8: nop

    after_12:
    // 0x80134DBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134DC0: lw          $v0, 0x52EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52EC);
    // 0x80134DC4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80134DC8: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x80134DCC: beq         $v0, $at, L_80134E04
    if (ctx->r2 == ctx->r1) {
        // 0x80134DD0: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80134E04;
    }
    // 0x80134DD0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80134DD4: beq         $v0, $at, L_80134E04
    if (ctx->r2 == ctx->r1) {
        // 0x80134DD8: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80134E04;
    }
    // 0x80134DD8: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80134DDC: beq         $v0, $at, L_80134E38
    if (ctx->r2 == ctx->r1) {
        // 0x80134DE0: lui         $t3, 0x800A
        ctx->r11 = S32(0X800A << 16);
            goto L_80134E38;
    }
    // 0x80134DE0: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80134DE4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80134DE8: bne         $v0, $at, L_80134E6C
    if (ctx->r2 != ctx->r1) {
        // 0x80134DEC: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80134E6C;
    }
    // 0x80134DEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134DF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134DF4: jal         0x80020AB4
    // 0x80134DF8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    syAudioPlayBGM(rdram, ctx);
        goto after_13;
    // 0x80134DF8: addiu       $a1, $zero, 0x1D
    ctx->r5 = ADD32(0, 0X1D);
    after_13:
    // 0x80134DFC: b           L_80134E78
    // 0x80134E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80134E78;
    // 0x80134E00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134E04:
    // 0x80134E04: lbu         $t2, 0x4B08($t2)
    ctx->r10 = MEM_BU(ctx->r10, 0X4B08);
    // 0x80134E08: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80134E0C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80134E10: bne         $t2, $at, L_80134E28
    if (ctx->r10 != ctx->r1) {
        // 0x80134E14: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80134E28;
    }
    // 0x80134E14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134E18: jal         0x80020AB4
    // 0x80134E1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioPlayBGM(rdram, ctx);
        goto after_14;
    // 0x80134E1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80134E20: b           L_80134E78
    // 0x80134E24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80134E78;
    // 0x80134E24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134E28:
    // 0x80134E28: jal         0x80020AB4
    // 0x80134E2C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    syAudioPlayBGM(rdram, ctx);
        goto after_15;
    // 0x80134E2C: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_15:
    // 0x80134E30: b           L_80134E78
    // 0x80134E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80134E78;
    // 0x80134E34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134E38:
    // 0x80134E38: lw          $t3, 0x4AEC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4AEC);
    // 0x80134E3C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80134E40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134E44: beq         $t3, $zero, L_80134E5C
    if (ctx->r11 == 0) {
        // 0x80134E48: nop
    
            goto L_80134E5C;
    }
    // 0x80134E48: nop

    // 0x80134E4C: jal         0x80020AB4
    // 0x80134E50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioPlayBGM(rdram, ctx);
        goto after_16;
    // 0x80134E50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_16:
    // 0x80134E54: b           L_80134E78
    // 0x80134E58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80134E78;
    // 0x80134E58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134E5C:
    // 0x80134E5C: jal         0x80020AB4
    // 0x80134E60: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    syAudioPlayBGM(rdram, ctx);
        goto after_17;
    // 0x80134E60: addiu       $a1, $zero, 0x1E
    ctx->r5 = ADD32(0, 0X1E);
    after_17:
    // 0x80134E64: b           L_80134E78
    // 0x80134E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80134E78;
    // 0x80134E68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134E6C:
    // 0x80134E6C: jal         0x80020AB4
    // 0x80134E70: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    syAudioPlayBGM(rdram, ctx);
        goto after_18;
    // 0x80134E70: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_18:
    // 0x80134E74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134E78:
    // 0x80134E78: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80134E7C: jr          $ra
    // 0x80134E80: nop

    return;
    // 0x80134E80: nop

;}
RECOMP_FUNC void ftCommonThrowCheckInterruptCatchWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A394: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014A398: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014A39C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014A3A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8014A3A4: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x8014A3A8: beq         $t6, $zero, L_8014A3CC
    if (ctx->r14 == 0) {
        // 0x8014A3AC: nop
    
            goto L_8014A3CC;
    }
    // 0x8014A3AC: nop

    // 0x8014A3B0: lhu         $t7, 0x1B4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B4);
    // 0x8014A3B4: lhu         $t8, 0x1B6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1B6);
    // 0x8014A3B8: lhu         $t0, 0x1BE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X1BE);
    // 0x8014A3BC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8014A3C0: and         $t1, $t0, $t9
    ctx->r9 = ctx->r8 & ctx->r25;
    // 0x8014A3C4: beql        $t1, $zero, L_8014A3D8
    if (ctx->r9 == 0) {
        // 0x8014A3C8: lb          $v1, 0x1C4($v0)
        ctx->r3 = MEM_B(ctx->r2, 0X1C4);
            goto L_8014A3D8;
    }
    goto skip_0;
    // 0x8014A3C8: lb          $v1, 0x1C4($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1C4);
    skip_0:
L_8014A3CC:
    // 0x8014A3CC: b           L_8014A414
    // 0x8014A3D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8014A414;
    // 0x8014A3D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014A3D4: lb          $v1, 0x1C4($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1C4);
L_8014A3D8:
    // 0x8014A3D8: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x8014A3DC: beql        $at, $zero, L_8014A3F4
    if (ctx->r1 == 0) {
        // 0x8014A3E0: slti        $at, $v1, -0x13
        ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
            goto L_8014A3F4;
    }
    goto skip_1;
    // 0x8014A3E0: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
    skip_1:
    // 0x8014A3E4: lb          $t2, 0x1C2($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X1C2);
    // 0x8014A3E8: slti        $at, $t2, 0x14
    ctx->r1 = SIGNED(ctx->r10) < 0X14 ? 1 : 0;
    // 0x8014A3EC: beq         $at, $zero, L_8014A414
    if (ctx->r1 == 0) {
        // 0x8014A3F0: slti        $at, $v1, -0x13
        ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
            goto L_8014A414;
    }
    // 0x8014A3F0: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
L_8014A3F4:
    // 0x8014A3F4: bne         $at, $zero, L_8014A40C
    if (ctx->r1 != 0) {
        // 0x8014A3F8: nop
    
            goto L_8014A40C;
    }
    // 0x8014A3F8: nop

    // 0x8014A3FC: lb          $t3, 0x1C2($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X1C2);
    // 0x8014A400: slti        $at, $t3, -0x13
    ctx->r1 = SIGNED(ctx->r11) < -0X13 ? 1 : 0;
    // 0x8014A404: bne         $at, $zero, L_8014A414
    if (ctx->r1 != 0) {
        // 0x8014A408: nop
    
            goto L_8014A414;
    }
    // 0x8014A408: nop

L_8014A40C:
    // 0x8014A40C: b           L_8014A420
    // 0x8014A410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8014A420;
    // 0x8014A410: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014A414:
    // 0x8014A414: jal         0x8014A1E8
    // 0x8014A418: nop

    ftCommonThrowSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014A418: nop

    after_0:
    // 0x8014A41C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014A420:
    // 0x8014A420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014A424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014A428: jr          $ra
    // 0x8014A42C: nop

    return;
    // 0x8014A42C: nop

;}
RECOMP_FUNC void func_ovl8_803787C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803787C0: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x803787C4: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x803787C8: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x803787CC: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x803787D0: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x803787D4: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x803787D8: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x803787DC: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x803787E0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x803787E4: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x803787E8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803787EC: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x803787F0: lwl         $t8, 0x0($a3)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r7, 0X0);
    // 0x803787F4: lwr         $t8, 0x3($a3)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r7, 0X3);
    // 0x803787F8: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x803787FC: addiu       $s4, $sp, 0xC0
    ctx->r20 = ADD32(ctx->r29, 0XC0);
    // 0x80378800: swl         $t8, 0x0($t6)
    do_swl(rdram, 0X0, ctx->r14, ctx->r24);
    // 0x80378804: swr         $t8, 0x3($t6)
    do_swr(rdram, 0X3, ctx->r14, ctx->r24);
    // 0x80378808: lwl         $t0, 0x0($a2)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r6, 0X0);
    // 0x8037880C: lwr         $t0, 0x3($a2)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r6, 0X3);
    // 0x80378810: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80378814: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80378818: swl         $t0, 0x0($s4)
    do_swl(rdram, 0X0, ctx->r20, ctx->r8);
    // 0x8037881C: swr         $t0, 0x3($s4)
    do_swr(rdram, 0X3, ctx->r20, ctx->r8);
    // 0x80378820: lwl         $t9, 0x4($a2)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r6, 0X4);
    // 0x80378824: lwr         $t9, 0x7($a2)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r6, 0X7);
    // 0x80378828: addiu       $s3, $sp, 0xD0
    ctx->r19 = ADD32(ctx->r29, 0XD0);
    // 0x8037882C: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x80378830: swl         $t9, 0x4($s4)
    do_swl(rdram, 0X4, ctx->r20, ctx->r25);
    // 0x80378834: swr         $t9, 0x7($s4)
    do_swr(rdram, 0X7, ctx->r20, ctx->r25);
    // 0x80378838: sh          $zero, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = 0;
    // 0x8037883C: sh          $zero, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = 0;
    // 0x80378840: lh          $t1, 0x4($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X4);
    // 0x80378844: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80378848: sh          $t1, 0xD4($sp)
    MEM_H(0XD4, ctx->r29) = ctx->r9;
    // 0x8037884C: lh          $t2, 0x6($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X6);
    // 0x80378850: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80378854: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x80378858: sw          $s2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r18;
    // 0x8037885C: jal         0x8037A67C
    // 0x80378860: sh          $t2, 0xD6($sp)
    MEM_H(0XD6, ctx->r29) = ctx->r10;
    func_ovl8_8037A67C(rdram, ctx);
        goto after_0;
    // 0x80378860: sh          $t2, 0xD6($sp)
    MEM_H(0XD6, ctx->r29) = ctx->r10;
    after_0:
    // 0x80378864: lh          $t3, 0x6C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X6C);
    // 0x80378868: lh          $t4, 0xC0($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XC0);
    // 0x8037886C: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80378870: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x80378874: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80378878: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8037887C: lh          $t9, 0xC2($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XC2);
    // 0x80378880: sh          $t7, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r15;
    // 0x80378884: lh          $t1, 0x2($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X2);
    // 0x80378888: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8037888C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80378890: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80378894: jal         0x8037AA5C
    // 0x80378898: sh          $t2, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r10;
    func_ovl8_8037AA5C(rdram, ctx);
        goto after_1;
    // 0x80378898: sh          $t2, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r10;
    after_1:
    // 0x8037889C: bne         $v0, $zero, L_80379040
    if (ctx->r2 != 0) {
        // 0x803788A0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80379040;
    }
    // 0x803788A0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x803788A4: lw          $v0, 0xEC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XEC);
    // 0x803788A8: sh          $zero, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = 0;
    // 0x803788AC: sh          $zero, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = 0;
    // 0x803788B0: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x803788B4: lh          $t5, 0x6C($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X6C);
    // 0x803788B8: lh          $t6, 0x6E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6E);
    // 0x803788BC: sh          $t3, 0xD4($sp)
    MEM_H(0XD4, ctx->r29) = ctx->r11;
    // 0x803788C0: lh          $t4, 0x6($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X6);
    // 0x803788C4: lhu         $t7, 0xC4($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0XC4);
    // 0x803788C8: lhu         $t8, 0xC6($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0XC6);
    // 0x803788CC: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x803788D0: addiu       $a2, $sp, 0xE0
    ctx->r6 = ADD32(ctx->r29, 0XE0);
    // 0x803788D4: sh          $t5, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r13;
    // 0x803788D8: sh          $t6, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r14;
    // 0x803788DC: sh          $t4, 0xD6($sp)
    MEM_H(0XD6, ctx->r29) = ctx->r12;
    // 0x803788E0: sh          $t7, 0xCC($sp)
    MEM_H(0XCC, ctx->r29) = ctx->r15;
    // 0x803788E4: jal         0x8037A67C
    // 0x803788E8: sh          $t8, 0xCE($sp)
    MEM_H(0XCE, ctx->r29) = ctx->r24;
    func_ovl8_8037A67C(rdram, ctx);
        goto after_2;
    // 0x803788E8: sh          $t8, 0xCE($sp)
    MEM_H(0XCE, ctx->r29) = ctx->r24;
    after_2:
    // 0x803788EC: lh          $t9, 0x6C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X6C);
    // 0x803788F0: lh          $t0, 0xE0($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XE0);
    // 0x803788F4: lh          $t4, 0x6E($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X6E);
    // 0x803788F8: lh          $t5, 0xE2($sp)
    ctx->r13 = MEM_H(ctx->r29, 0XE2);
    // 0x803788FC: lh          $t2, 0xC8($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XC8);
    // 0x80378900: lh          $t7, 0xCA($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XCA);
    // 0x80378904: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80378908: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8037890C: subu        $t0, $t1, $t2
    ctx->r8 = SUB32(ctx->r9, ctx->r10);
    // 0x80378910: subu        $t5, $t6, $t7
    ctx->r13 = SUB32(ctx->r14, ctx->r15);
    // 0x80378914: sh          $t5, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r13;
    // 0x80378918: sh          $t0, 0x6C($sp)
    MEM_H(0X6C, ctx->r29) = ctx->r8;
    // 0x8037891C: lh          $t9, 0x0($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X0);
    // 0x80378920: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x80378924: subu        $t2, $t0, $t9
    ctx->r10 = SUB32(ctx->r8, ctx->r25);
    // 0x80378928: sh          $t2, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r10;
    // 0x8037892C: lh          $t4, 0x2($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X2);
    // 0x80378930: subu        $t7, $t5, $t4
    ctx->r15 = SUB32(ctx->r13, ctx->r12);
    // 0x80378934: jal         0x8037AA5C
    // 0x80378938: sh          $t7, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r15;
    func_ovl8_8037AA5C(rdram, ctx);
        goto after_3;
    // 0x80378938: sh          $t7, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r15;
    after_3:
    // 0x8037893C: bne         $v0, $zero, L_80379040
    if (ctx->r2 != 0) {
        // 0x80378940: addiu       $t0, $sp, 0xE0
        ctx->r8 = ADD32(ctx->r29, 0XE0);
            goto L_80379040;
    }
    // 0x80378940: addiu       $t0, $sp, 0xE0
    ctx->r8 = ADD32(ctx->r29, 0XE0);
    // 0x80378944: lwl         $t9, 0x0($t0)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r8, 0X0);
    // 0x80378948: lwr         $t9, 0x3($t0)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r8, 0X3);
    // 0x8037894C: addiu       $t3, $sp, 0xC8
    ctx->r11 = ADD32(ctx->r29, 0XC8);
    // 0x80378950: swl         $t9, 0x0($t3)
    do_swl(rdram, 0X0, ctx->r11, ctx->r25);
    // 0x80378954: swr         $t9, 0x3($t3)
    do_swr(rdram, 0X3, ctx->r11, ctx->r25);
    // 0x80378958: lwl         $t1, 0x4($t0)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r8, 0X4);
    // 0x8037895C: lwr         $t1, 0x7($t0)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r8, 0X7);
    // 0x80378960: swl         $t1, 0x4($t3)
    do_swl(rdram, 0X4, ctx->r11, ctx->r9);
    // 0x80378964: swr         $t1, 0x7($t3)
    do_swr(rdram, 0X7, ctx->r11, ctx->r9);
    // 0x80378968: lh          $t2, 0x6C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X6C);
    // 0x8037896C: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x80378970: lw          $t5, 0xEC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XEC);
    // 0x80378974: sh          $t2, 0xC8($sp)
    MEM_H(0XC8, ctx->r29) = ctx->r10;
    // 0x80378978: sh          $t8, 0xCA($sp)
    MEM_H(0XCA, ctx->r29) = ctx->r24;
    // 0x8037897C: lw          $v0, 0x34($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X34);
    // 0x80378980: lw          $t7, 0xE8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE8);
    // 0x80378984: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x80378988: div         $zero, $t2, $t6
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r14)));
    // 0x8037898C: sw          $t6, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r14;
    // 0x80378990: lh          $t4, 0xC($v0)
    ctx->r12 = MEM_H(ctx->r2, 0XC);
    // 0x80378994: mflo        $t0
    ctx->r8 = lo;
    // 0x80378998: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
    // 0x8037899C: sw          $t4, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r12;
    // 0x803789A0: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x803789A4: lw          $v1, 0x34($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X34);
    // 0x803789A8: lw          $t4, 0xA8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA8);
    // 0x803789AC: div         $zero, $t8, $t1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r9)));
    // 0x803789B0: lh          $s5, 0x0($v1)
    ctx->r21 = MEM_H(ctx->r3, 0X0);
    // 0x803789B4: lh          $s7, 0xC($v1)
    ctx->r23 = MEM_H(ctx->r3, 0XC);
    // 0x803789B8: mflo        $t9
    ctx->r25 = lo;
    // 0x803789BC: sw          $t0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r8;
    // 0x803789C0: sw          $t9, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r25;
    // 0x803789C4: lh          $a0, 0x4($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X4);
    // 0x803789C8: bne         $t3, $zero, L_803789D4
    if (ctx->r11 != 0) {
        // 0x803789CC: nop
    
            goto L_803789D4;
    }
    // 0x803789CC: nop

    // 0x803789D0: break       7
    do_break(2151123408);
L_803789D4:
    // 0x803789D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x803789D8: bne         $t3, $at, L_803789EC
    if (ctx->r11 != ctx->r1) {
        // 0x803789DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_803789EC;
    }
    // 0x803789DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x803789E0: bne         $t2, $at, L_803789EC
    if (ctx->r10 != ctx->r1) {
        // 0x803789E4: nop
    
            goto L_803789EC;
    }
    // 0x803789E4: nop

    // 0x803789E8: break       6
    do_break(2151123432);
L_803789EC:
    // 0x803789EC: div         $zero, $a0, $t3
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r11)));
    // 0x803789F0: bne         $t1, $zero, L_803789FC
    if (ctx->r9 != 0) {
        // 0x803789F4: nop
    
            goto L_803789FC;
    }
    // 0x803789F4: nop

    // 0x803789F8: break       7
    do_break(2151123448);
L_803789FC:
    // 0x803789FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378A00: bne         $t1, $at, L_80378A14
    if (ctx->r9 != ctx->r1) {
        // 0x80378A04: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378A14;
    }
    // 0x80378A04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378A08: bne         $t8, $at, L_80378A14
    if (ctx->r24 != ctx->r1) {
        // 0x80378A0C: nop
    
            goto L_80378A14;
    }
    // 0x80378A0C: nop

    // 0x80378A10: break       6
    do_break(2151123472);
L_80378A14:
    // 0x80378A14: mfhi        $t6
    ctx->r14 = hi;
    // 0x80378A18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80378A1C: bne         $t3, $zero, L_80378A28
    if (ctx->r11 != 0) {
        // 0x80378A20: nop
    
            goto L_80378A28;
    }
    // 0x80378A20: nop

    // 0x80378A24: break       7
    do_break(2151123492);
L_80378A28:
    // 0x80378A28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378A2C: bne         $t3, $at, L_80378A40
    if (ctx->r11 != ctx->r1) {
        // 0x80378A30: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378A40;
    }
    // 0x80378A30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378A34: bne         $a0, $at, L_80378A40
    if (ctx->r4 != ctx->r1) {
        // 0x80378A38: nop
    
            goto L_80378A40;
    }
    // 0x80378A38: nop

    // 0x80378A3C: break       6
    do_break(2151123516);
L_80378A40:
    // 0x80378A40: beq         $t6, $zero, L_80378A50
    if (ctx->r14 == 0) {
        // 0x80378A44: nop
    
            goto L_80378A50;
    }
    // 0x80378A44: nop

    // 0x80378A48: b           L_80378A50
    // 0x80378A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80378A50;
    // 0x80378A4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80378A50:
    // 0x80378A50: div         $zero, $a0, $t4
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r12))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r12)));
    // 0x80378A54: mflo        $t7
    ctx->r15 = lo;
    // 0x80378A58: lh          $t0, 0xC0($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XC0);
    // 0x80378A5C: lh          $t1, 0xC2($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XC2);
    // 0x80378A60: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x80378A64: div         $zero, $t0, $s5
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r21)));
    // 0x80378A68: mflo        $t8
    ctx->r24 = lo;
    // 0x80378A6C: addu        $t2, $t7, $v0
    ctx->r10 = ADD32(ctx->r15, ctx->r2);
    // 0x80378A70: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
    // 0x80378A74: div         $zero, $t1, $s7
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r23)));
    // 0x80378A78: mflo        $t9
    ctx->r25 = lo;
    // 0x80378A7C: sw          $t8, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r24;
    // 0x80378A80: sw          $t9, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r25;
    // 0x80378A84: lh          $v1, 0x4($t5)
    ctx->r3 = MEM_H(ctx->r13, 0X4);
    // 0x80378A88: bne         $t4, $zero, L_80378A94
    if (ctx->r12 != 0) {
        // 0x80378A8C: nop
    
            goto L_80378A94;
    }
    // 0x80378A8C: nop

    // 0x80378A90: break       7
    do_break(2151123600);
L_80378A94:
    // 0x80378A94: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378A98: bne         $t4, $at, L_80378AAC
    if (ctx->r12 != ctx->r1) {
        // 0x80378A9C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378AAC;
    }
    // 0x80378A9C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378AA0: bne         $a0, $at, L_80378AAC
    if (ctx->r4 != ctx->r1) {
        // 0x80378AA4: nop
    
            goto L_80378AAC;
    }
    // 0x80378AA4: nop

    // 0x80378AA8: break       6
    do_break(2151123624);
L_80378AAC:
    // 0x80378AAC: div         $zero, $v1, $s5
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r21)));
    // 0x80378AB0: bne         $s5, $zero, L_80378ABC
    if (ctx->r21 != 0) {
        // 0x80378AB4: nop
    
            goto L_80378ABC;
    }
    // 0x80378AB4: nop

    // 0x80378AB8: break       7
    do_break(2151123640);
L_80378ABC:
    // 0x80378ABC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378AC0: bne         $s5, $at, L_80378AD4
    if (ctx->r21 != ctx->r1) {
        // 0x80378AC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378AD4;
    }
    // 0x80378AC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378AC8: bne         $t0, $at, L_80378AD4
    if (ctx->r8 != ctx->r1) {
        // 0x80378ACC: nop
    
            goto L_80378AD4;
    }
    // 0x80378ACC: nop

    // 0x80378AD0: break       6
    do_break(2151123664);
L_80378AD4:
    // 0x80378AD4: mfhi        $t3
    ctx->r11 = hi;
    // 0x80378AD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80378ADC: bne         $s7, $zero, L_80378AE8
    if (ctx->r23 != 0) {
        // 0x80378AE0: nop
    
            goto L_80378AE8;
    }
    // 0x80378AE0: nop

    // 0x80378AE4: break       7
    do_break(2151123684);
L_80378AE8:
    // 0x80378AE8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378AEC: bne         $s7, $at, L_80378B00
    if (ctx->r23 != ctx->r1) {
        // 0x80378AF0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378B00;
    }
    // 0x80378AF0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378AF4: bne         $t1, $at, L_80378B00
    if (ctx->r9 != ctx->r1) {
        // 0x80378AF8: nop
    
            goto L_80378B00;
    }
    // 0x80378AF8: nop

    // 0x80378AFC: break       6
    do_break(2151123708);
L_80378B00:
    // 0x80378B00: bne         $s5, $zero, L_80378B0C
    if (ctx->r21 != 0) {
        // 0x80378B04: nop
    
            goto L_80378B0C;
    }
    // 0x80378B04: nop

    // 0x80378B08: break       7
    do_break(2151123720);
L_80378B0C:
    // 0x80378B0C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378B10: bne         $s5, $at, L_80378B24
    if (ctx->r21 != ctx->r1) {
        // 0x80378B14: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378B24;
    }
    // 0x80378B14: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378B18: bne         $v1, $at, L_80378B24
    if (ctx->r3 != ctx->r1) {
        // 0x80378B1C: nop
    
            goto L_80378B24;
    }
    // 0x80378B1C: nop

    // 0x80378B20: break       6
    do_break(2151123744);
L_80378B24:
    // 0x80378B24: beq         $t3, $zero, L_80378B34
    if (ctx->r11 == 0) {
        // 0x80378B28: nop
    
            goto L_80378B34;
    }
    // 0x80378B28: nop

    // 0x80378B2C: b           L_80378B34
    // 0x80378B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80378B34;
    // 0x80378B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80378B34:
    // 0x80378B34: div         $zero, $v1, $s5
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r21)));
    // 0x80378B38: lhu         $a0, 0xCC($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0XCC);
    // 0x80378B3C: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80378B40: mflo        $t6
    ctx->r14 = lo;
    // 0x80378B44: addu        $t4, $t6, $v0
    ctx->r12 = ADD32(ctx->r14, ctx->r2);
    // 0x80378B48: bne         $s5, $zero, L_80378B54
    if (ctx->r21 != 0) {
        // 0x80378B4C: nop
    
            goto L_80378B54;
    }
    // 0x80378B4C: nop

    // 0x80378B50: break       7
    do_break(2151123792);
L_80378B54:
    // 0x80378B54: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378B58: bne         $s5, $at, L_80378B6C
    if (ctx->r21 != ctx->r1) {
        // 0x80378B5C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378B6C;
    }
    // 0x80378B5C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378B60: bne         $v1, $at, L_80378B6C
    if (ctx->r3 != ctx->r1) {
        // 0x80378B64: nop
    
            goto L_80378B6C;
    }
    // 0x80378B64: nop

    // 0x80378B68: break       6
    do_break(2151123816);
L_80378B6C:
    // 0x80378B6C: div         $zero, $a0, $t7
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r15)));
    // 0x80378B70: mfhi        $t2
    ctx->r10 = hi;
    // 0x80378B74: sw          $t4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r12;
    // 0x80378B78: bne         $t7, $zero, L_80378B84
    if (ctx->r15 != 0) {
        // 0x80378B7C: nop
    
            goto L_80378B84;
    }
    // 0x80378B7C: nop

    // 0x80378B80: break       7
    do_break(2151123840);
L_80378B84:
    // 0x80378B84: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378B88: bne         $t7, $at, L_80378B9C
    if (ctx->r15 != ctx->r1) {
        // 0x80378B8C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378B9C;
    }
    // 0x80378B8C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378B90: bne         $a0, $at, L_80378B9C
    if (ctx->r4 != ctx->r1) {
        // 0x80378B94: nop
    
            goto L_80378B9C;
    }
    // 0x80378B94: nop

    // 0x80378B98: break       6
    do_break(2151123864);
L_80378B9C:
    // 0x80378B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80378BA0: beq         $t2, $zero, L_80378BB0
    if (ctx->r10 == 0) {
        // 0x80378BA4: lw          $t0, 0xA8($sp)
        ctx->r8 = MEM_W(ctx->r29, 0XA8);
            goto L_80378BB0;
    }
    // 0x80378BA4: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x80378BA8: b           L_80378BB0
    // 0x80378BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80378BB0;
    // 0x80378BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80378BB0:
    // 0x80378BB0: div         $zero, $a0, $t0
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r8))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r8)));
    // 0x80378BB4: lhu         $v1, 0xCE($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0XCE);
    // 0x80378BB8: lw          $t5, 0xA4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XA4);
    // 0x80378BBC: mflo        $t8
    ctx->r24 = lo;
    // 0x80378BC0: addu        $t1, $t8, $v0
    ctx->r9 = ADD32(ctx->r24, ctx->r2);
    // 0x80378BC4: bne         $t0, $zero, L_80378BD0
    if (ctx->r8 != 0) {
        // 0x80378BC8: nop
    
            goto L_80378BD0;
    }
    // 0x80378BC8: nop

    // 0x80378BCC: break       7
    do_break(2151123916);
L_80378BD0:
    // 0x80378BD0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378BD4: bne         $t0, $at, L_80378BE8
    if (ctx->r8 != ctx->r1) {
        // 0x80378BD8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378BE8;
    }
    // 0x80378BD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378BDC: bne         $a0, $at, L_80378BE8
    if (ctx->r4 != ctx->r1) {
        // 0x80378BE0: nop
    
            goto L_80378BE8;
    }
    // 0x80378BE0: nop

    // 0x80378BE4: break       6
    do_break(2151123940);
L_80378BE8:
    // 0x80378BE8: div         $zero, $v1, $t5
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r13)));
    // 0x80378BEC: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x80378BF0: mfhi        $t3
    ctx->r11 = hi;
    // 0x80378BF4: sw          $t9, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r25;
    // 0x80378BF8: bne         $t5, $zero, L_80378C04
    if (ctx->r13 != 0) {
        // 0x80378BFC: nop
    
            goto L_80378C04;
    }
    // 0x80378BFC: nop

    // 0x80378C00: break       7
    do_break(2151123968);
L_80378C04:
    // 0x80378C04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378C08: bne         $t5, $at, L_80378C1C
    if (ctx->r13 != ctx->r1) {
        // 0x80378C0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378C1C;
    }
    // 0x80378C0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378C10: bne         $v1, $at, L_80378C1C
    if (ctx->r3 != ctx->r1) {
        // 0x80378C14: nop
    
            goto L_80378C1C;
    }
    // 0x80378C14: nop

    // 0x80378C18: break       6
    do_break(2151123992);
L_80378C1C:
    // 0x80378C1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80378C20: beq         $t3, $zero, L_80378C30
    if (ctx->r11 == 0) {
        // 0x80378C24: lw          $t6, 0xA4($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA4);
            goto L_80378C30;
    }
    // 0x80378C24: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80378C28: b           L_80378C30
    // 0x80378C2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80378C30;
    // 0x80378C2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80378C30:
    // 0x80378C30: div         $zero, $v1, $t6
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r14))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r14)));
    // 0x80378C34: mflo        $t4
    ctx->r12 = lo;
    // 0x80378C38: addu        $t7, $t4, $v0
    ctx->r15 = ADD32(ctx->r12, ctx->r2);
    // 0x80378C3C: bne         $t6, $zero, L_80378C48
    if (ctx->r14 != 0) {
        // 0x80378C40: nop
    
            goto L_80378C48;
    }
    // 0x80378C40: nop

    // 0x80378C44: break       7
    do_break(2151124036);
L_80378C48:
    // 0x80378C48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378C4C: bne         $t6, $at, L_80378C60
    if (ctx->r14 != ctx->r1) {
        // 0x80378C50: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378C60;
    }
    // 0x80378C50: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378C54: bne         $v1, $at, L_80378C60
    if (ctx->r3 != ctx->r1) {
        // 0x80378C58: nop
    
            goto L_80378C60;
    }
    // 0x80378C58: nop

    // 0x80378C5C: break       6
    do_break(2151124060);
L_80378C60:
    // 0x80378C60: div         $zero, $a0, $s5
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r21)));
    // 0x80378C64: addiu       $t2, $t7, 0x1
    ctx->r10 = ADD32(ctx->r15, 0X1);
    // 0x80378C68: mfhi        $t0
    ctx->r8 = hi;
    // 0x80378C6C: sw          $t2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r10;
    // 0x80378C70: bne         $s5, $zero, L_80378C7C
    if (ctx->r21 != 0) {
        // 0x80378C74: nop
    
            goto L_80378C7C;
    }
    // 0x80378C74: nop

    // 0x80378C78: break       7
    do_break(2151124088);
L_80378C7C:
    // 0x80378C7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378C80: bne         $s5, $at, L_80378C94
    if (ctx->r21 != ctx->r1) {
        // 0x80378C84: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378C94;
    }
    // 0x80378C84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378C88: bne         $a0, $at, L_80378C94
    if (ctx->r4 != ctx->r1) {
        // 0x80378C8C: nop
    
            goto L_80378C94;
    }
    // 0x80378C8C: nop

    // 0x80378C90: break       6
    do_break(2151124112);
L_80378C94:
    // 0x80378C94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80378C98: beq         $t0, $zero, L_80378CA8
    if (ctx->r8 == 0) {
        // 0x80378C9C: addiu       $s2, $sp, 0xD8
        ctx->r18 = ADD32(ctx->r29, 0XD8);
            goto L_80378CA8;
    }
    // 0x80378C9C: addiu       $s2, $sp, 0xD8
    ctx->r18 = ADD32(ctx->r29, 0XD8);
    // 0x80378CA0: b           L_80378CA8
    // 0x80378CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80378CA8;
    // 0x80378CA4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80378CA8:
    // 0x80378CA8: div         $zero, $a0, $s5
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r21)));
    // 0x80378CAC: mflo        $t8
    ctx->r24 = lo;
    // 0x80378CB0: addu        $t1, $t8, $v0
    ctx->r9 = ADD32(ctx->r24, ctx->r2);
    // 0x80378CB4: bne         $s5, $zero, L_80378CC0
    if (ctx->r21 != 0) {
        // 0x80378CB8: nop
    
            goto L_80378CC0;
    }
    // 0x80378CB8: nop

    // 0x80378CBC: break       7
    do_break(2151124156);
L_80378CC0:
    // 0x80378CC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378CC4: bne         $s5, $at, L_80378CD8
    if (ctx->r21 != ctx->r1) {
        // 0x80378CC8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378CD8;
    }
    // 0x80378CC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378CCC: bne         $a0, $at, L_80378CD8
    if (ctx->r4 != ctx->r1) {
        // 0x80378CD0: nop
    
            goto L_80378CD8;
    }
    // 0x80378CD0: nop

    // 0x80378CD4: break       6
    do_break(2151124180);
L_80378CD8:
    // 0x80378CD8: div         $zero, $v1, $s7
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r23)));
    // 0x80378CDC: addiu       $t9, $t1, 0x1
    ctx->r25 = ADD32(ctx->r9, 0X1);
    // 0x80378CE0: mfhi        $t5
    ctx->r13 = hi;
    // 0x80378CE4: sw          $t9, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r25;
    // 0x80378CE8: bne         $s7, $zero, L_80378CF4
    if (ctx->r23 != 0) {
        // 0x80378CEC: nop
    
            goto L_80378CF4;
    }
    // 0x80378CEC: nop

    // 0x80378CF0: break       7
    do_break(2151124208);
L_80378CF4:
    // 0x80378CF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378CF8: bne         $s7, $at, L_80378D0C
    if (ctx->r23 != ctx->r1) {
        // 0x80378CFC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378D0C;
    }
    // 0x80378CFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378D00: bne         $v1, $at, L_80378D0C
    if (ctx->r3 != ctx->r1) {
        // 0x80378D04: nop
    
            goto L_80378D0C;
    }
    // 0x80378D04: nop

    // 0x80378D08: break       6
    do_break(2151124232);
L_80378D0C:
    // 0x80378D0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80378D10: beq         $t5, $zero, L_80378D20
    if (ctx->r13 == 0) {
        // 0x80378D14: nop
    
            goto L_80378D20;
    }
    // 0x80378D14: nop

    // 0x80378D18: b           L_80378D20
    // 0x80378D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80378D20;
    // 0x80378D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80378D20:
    // 0x80378D20: div         $zero, $v1, $s7
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r23)));
    // 0x80378D24: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x80378D28: mflo        $t3
    ctx->r11 = lo;
    // 0x80378D2C: addu        $t6, $t3, $v0
    ctx->r14 = ADD32(ctx->r11, ctx->r2);
    // 0x80378D30: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x80378D34: bne         $s7, $zero, L_80378D40
    if (ctx->r23 != 0) {
        // 0x80378D38: nop
    
            goto L_80378D40;
    }
    // 0x80378D38: nop

    // 0x80378D3C: break       7
    do_break(2151124284);
L_80378D40:
    // 0x80378D40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378D44: bne         $s7, $at, L_80378D58
    if (ctx->r23 != ctx->r1) {
        // 0x80378D48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378D58;
    }
    // 0x80378D48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378D4C: bne         $v1, $at, L_80378D58
    if (ctx->r3 != ctx->r1) {
        // 0x80378D50: nop
    
            goto L_80378D58;
    }
    // 0x80378D50: nop

    // 0x80378D54: break       6
    do_break(2151124308);
L_80378D58:
    // 0x80378D58: sw          $t4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r12;
    // 0x80378D5C: blez        $t7, L_80379040
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80378D60: sw          $zero, 0xB8($sp)
        MEM_W(0XB8, ctx->r29) = 0;
            goto L_80379040;
    }
    // 0x80378D60: sw          $zero, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = 0;
L_80378D64:
    // 0x80378D64: lw          $t2, 0xB4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB4);
    // 0x80378D68: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80378D6C: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x80378D70: blez        $t2, L_8037902C
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80378D74: lw          $t8, 0xA8($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XA8);
            goto L_8037902C;
    }
    // 0x80378D74: lw          $t8, 0xA8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA8);
    // 0x80378D78: multu       $t0, $t8
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378D7C: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80378D80: lw          $t5, 0xB8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB8);
    // 0x80378D84: lw          $t6, 0xA4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA4);
    // 0x80378D88: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x80378D8C: sw          $t3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r11;
    // 0x80378D90: mflo        $t1
    ctx->r9 = lo;
    // 0x80378D94: sw          $t1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r9;
    // 0x80378D98: nop

    // 0x80378D9C: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378DA0: mflo        $t4
    ctx->r12 = lo;
    // 0x80378DA4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x80378DA8: nop

L_80378DAC:
    // 0x80378DAC: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80378DB0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80378DB4: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x80378DB8: lw          $t0, 0xA8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA8);
    // 0x80378DBC: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x80378DC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80378DC4: sh          $t7, 0xE0($sp)
    MEM_H(0XE0, ctx->r29) = ctx->r15;
    // 0x80378DC8: sh          $t2, 0xE2($sp)
    MEM_H(0XE2, ctx->r29) = ctx->r10;
    // 0x80378DCC: sh          $t0, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = ctx->r8;
    // 0x80378DD0: blez        $t1, L_80379010
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80378DD4: sh          $t8, 0xE6($sp)
        MEM_H(0XE6, ctx->r29) = ctx->r24;
            goto L_80379010;
    }
    // 0x80378DD4: sh          $t8, 0xE6($sp)
    MEM_H(0XE6, ctx->r29) = ctx->r24;
    // 0x80378DD8: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
L_80378DDC:
    // 0x80378DDC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80378DE0: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80378DE4: blezl       $t9, L_80379004
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80378DE8: lw          $t3, 0x8C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X8C);
            goto L_80379004;
    }
    goto skip_0;
    // 0x80378DE8: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    skip_0:
    // 0x80378DEC: multu       $t5, $s5
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378DF0: lw          $t3, 0x78($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X78);
    // 0x80378DF4: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80378DF8: addu        $s4, $t3, $v0
    ctx->r20 = ADD32(ctx->r11, ctx->r2);
    // 0x80378DFC: mflo        $s1
    ctx->r17 = lo;
    // 0x80378E00: nop

    // 0x80378E04: nop

    // 0x80378E08: multu       $s4, $s7
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378E0C: mflo        $s6
    ctx->r22 = lo;
    // 0x80378E10: nop

    // 0x80378E14: nop

    // 0x80378E18: lh          $t6, 0x6C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6C);
L_80378E1C:
    // 0x80378E1C: lh          $t0, 0x6E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X6E);
    // 0x80378E20: lh          $t7, 0xC0($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XC0);
    // 0x80378E24: lh          $t1, 0xC2($sp)
    ctx->r9 = MEM_H(ctx->r29, 0XC2);
    // 0x80378E28: addu        $t4, $s1, $t6
    ctx->r12 = ADD32(ctx->r17, ctx->r14);
    // 0x80378E2C: addu        $t8, $s6, $t0
    ctx->r24 = ADD32(ctx->r22, ctx->r8);
    // 0x80378E30: subu        $t2, $t4, $t7
    ctx->r10 = SUB32(ctx->r12, ctx->r15);
    // 0x80378E34: subu        $t9, $t8, $t1
    ctx->r25 = SUB32(ctx->r24, ctx->r9);
    // 0x80378E38: sh          $t2, 0xD8($sp)
    MEM_H(0XD8, ctx->r29) = ctx->r10;
    // 0x80378E3C: sh          $t9, 0xDA($sp)
    MEM_H(0XDA, ctx->r29) = ctx->r25;
    // 0x80378E40: sh          $s5, 0xDC($sp)
    MEM_H(0XDC, ctx->r29) = ctx->r21;
    // 0x80378E44: sh          $s7, 0xDE($sp)
    MEM_H(0XDE, ctx->r29) = ctx->r23;
    // 0x80378E48: addiu       $a0, $sp, 0xE0
    ctx->r4 = ADD32(ctx->r29, 0XE0);
    // 0x80378E4C: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x80378E50: jal         0x8037A67C
    // 0x80378E54: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_ovl8_8037A67C(rdram, ctx);
        goto after_4;
    // 0x80378E54: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_4:
    // 0x80378E58: beq         $v0, $zero, L_80378FE8
    if (ctx->r2 == 0) {
        // 0x80378E5C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80378FE8;
    }
    // 0x80378E5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80378E60: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80378E64: jal         0x8037A67C
    // 0x80378E68: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    func_ovl8_8037A67C(rdram, ctx);
        goto after_5;
    // 0x80378E68: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_5:
    // 0x80378E6C: beq         $v0, $zero, L_80378FE8
    if (ctx->r2 == 0) {
        // 0x80378E70: lh          $t5, 0xD0($sp)
        ctx->r13 = MEM_H(ctx->r29, 0XD0);
            goto L_80378FE8;
    }
    // 0x80378E70: lh          $t5, 0xD0($sp)
    ctx->r13 = MEM_H(ctx->r29, 0XD0);
    // 0x80378E74: lh          $t3, 0x6C($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X6C);
    // 0x80378E78: lh          $t4, 0xC0($sp)
    ctx->r12 = MEM_H(ctx->r29, 0XC0);
    // 0x80378E7C: lh          $t0, 0xD2($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XD2);
    // 0x80378E80: subu        $t6, $t5, $t3
    ctx->r14 = SUB32(ctx->r13, ctx->r11);
    // 0x80378E84: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x80378E88: div         $zero, $t7, $s5
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r21)));
    // 0x80378E8C: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x80378E90: lh          $t9, 0xC2($sp)
    ctx->r25 = MEM_H(ctx->r29, 0XC2);
    // 0x80378E94: mfhi        $t2
    ctx->r10 = hi;
    // 0x80378E98: subu        $t1, $t0, $t8
    ctx->r9 = SUB32(ctx->r8, ctx->r24);
    // 0x80378E9C: addu        $t3, $t1, $t9
    ctx->r11 = ADD32(ctx->r9, ctx->r25);
    // 0x80378EA0: div         $zero, $t3, $s7
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r23))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r23)));
    // 0x80378EA4: sh          $t2, 0xD8($sp)
    MEM_H(0XD8, ctx->r29) = ctx->r10;
    // 0x80378EA8: mfhi        $t6
    ctx->r14 = hi;
    // 0x80378EAC: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x80378EB0: lw          $t1, 0xA4($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA4);
    // 0x80378EB4: bne         $s5, $zero, L_80378EC0
    if (ctx->r21 != 0) {
        // 0x80378EB8: nop
    
            goto L_80378EC0;
    }
    // 0x80378EB8: nop

    // 0x80378EBC: break       7
    do_break(2151124668);
L_80378EC0:
    // 0x80378EC0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378EC4: bne         $s5, $at, L_80378ED8
    if (ctx->r21 != ctx->r1) {
        // 0x80378EC8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378ED8;
    }
    // 0x80378EC8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378ECC: bne         $t7, $at, L_80378ED8
    if (ctx->r15 != ctx->r1) {
        // 0x80378ED0: nop
    
            goto L_80378ED8;
    }
    // 0x80378ED0: nop

    // 0x80378ED4: break       6
    do_break(2151124692);
L_80378ED8:
    // 0x80378ED8: div         $zero, $t5, $t2
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r10)));
    // 0x80378EDC: mfhi        $t8
    ctx->r24 = hi;
    // 0x80378EE0: lhu         $t4, 0xD4($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0XD4);
    // 0x80378EE4: bne         $s7, $zero, L_80378EF0
    if (ctx->r23 != 0) {
        // 0x80378EE8: nop
    
            goto L_80378EF0;
    }
    // 0x80378EE8: nop

    // 0x80378EEC: break       7
    do_break(2151124716);
L_80378EF0:
    // 0x80378EF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378EF4: bne         $s7, $at, L_80378F08
    if (ctx->r23 != ctx->r1) {
        // 0x80378EF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378F08;
    }
    // 0x80378EF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378EFC: bne         $t3, $at, L_80378F08
    if (ctx->r11 != ctx->r1) {
        // 0x80378F00: nop
    
            goto L_80378F08;
    }
    // 0x80378F00: nop

    // 0x80378F04: break       6
    do_break(2151124740);
L_80378F08:
    // 0x80378F08: div         $zero, $t0, $t1
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r9)));
    // 0x80378F0C: sh          $t4, 0xDC($sp)
    MEM_H(0XDC, ctx->r29) = ctx->r12;
    // 0x80378F10: mfhi        $t9
    ctx->r25 = hi;
    // 0x80378F14: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x80378F18: lhu         $t7, 0xD6($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0XD6);
    // 0x80378F1C: lw          $t3, 0xE8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE8);
    // 0x80378F20: multu       $s4, $t4
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378F24: sh          $t6, 0xDA($sp)
    MEM_H(0XDA, ctx->r29) = ctx->r14;
    // 0x80378F28: sh          $t8, 0xD0($sp)
    MEM_H(0XD0, ctx->r29) = ctx->r24;
    // 0x80378F2C: sh          $t9, 0xD2($sp)
    MEM_H(0XD2, ctx->r29) = ctx->r25;
    // 0x80378F30: sh          $t7, 0xDE($sp)
    MEM_H(0XDE, ctx->r29) = ctx->r15;
    // 0x80378F34: bne         $t2, $zero, L_80378F40
    if (ctx->r10 != 0) {
        // 0x80378F38: nop
    
            goto L_80378F40;
    }
    // 0x80378F38: nop

    // 0x80378F3C: break       7
    do_break(2151124796);
L_80378F40:
    // 0x80378F40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378F44: bne         $t2, $at, L_80378F58
    if (ctx->r10 != ctx->r1) {
        // 0x80378F48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378F58;
    }
    // 0x80378F48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378F4C: bne         $t5, $at, L_80378F58
    if (ctx->r13 != ctx->r1) {
        // 0x80378F50: nop
    
            goto L_80378F58;
    }
    // 0x80378F50: nop

    // 0x80378F54: break       6
    do_break(2151124820);
L_80378F58:
    // 0x80378F58: lw          $t6, 0x34($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X34);
    // 0x80378F5C: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x80378F60: mflo        $t7
    ctx->r15 = lo;
    // 0x80378F64: lw          $t4, 0xAC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XAC);
    // 0x80378F68: bne         $t1, $zero, L_80378F74
    if (ctx->r9 != 0) {
        // 0x80378F6C: nop
    
            goto L_80378F74;
    }
    // 0x80378F6C: nop

    // 0x80378F70: break       7
    do_break(2151124848);
L_80378F74:
    // 0x80378F74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80378F78: bne         $t1, $at, L_80378F8C
    if (ctx->r9 != ctx->r1) {
        // 0x80378F7C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80378F8C;
    }
    // 0x80378F7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80378F80: bne         $t0, $at, L_80378F8C
    if (ctx->r8 != ctx->r1) {
        // 0x80378F84: nop
    
            goto L_80378F8C;
    }
    // 0x80378F84: nop

    // 0x80378F88: break       6
    do_break(2151124872);
L_80378F8C:
    // 0x80378F8C: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80378F90: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80378F94: sll         $t5, $t7, 4
    ctx->r13 = S32(ctx->r15 << 4);
    // 0x80378F98: lw          $t7, 0xEC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XEC);
    // 0x80378F9C: sll         $t8, $s0, 4
    ctx->r24 = S32(ctx->r16 << 4);
    // 0x80378FA0: addu        $t2, $t6, $t5
    ctx->r10 = ADD32(ctx->r14, ctx->r13);
    // 0x80378FA4: addu        $t0, $t2, $t8
    ctx->r8 = ADD32(ctx->r10, ctx->r24);
    // 0x80378FA8: sll         $t9, $t1, 4
    ctx->r25 = S32(ctx->r9 << 4);
    // 0x80378FAC: lw          $t6, 0x34($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X34);
    // 0x80378FB0: addu        $a1, $t0, $t9
    ctx->r5 = ADD32(ctx->r8, ctx->r25);
    // 0x80378FB4: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x80378FB8: lw          $t0, 0xE8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE8);
    // 0x80378FBC: mflo        $v0
    ctx->r2 = lo;
    // 0x80378FC0: sll         $t5, $v0, 4
    ctx->r13 = S32(ctx->r2 << 4);
    // 0x80378FC4: sll         $t8, $fp, 4
    ctx->r24 = S32(ctx->r30 << 4);
    // 0x80378FC8: addu        $t2, $t6, $t5
    ctx->r10 = ADD32(ctx->r14, ctx->r13);
    // 0x80378FCC: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x80378FD0: sll         $v1, $v1, 4
    ctx->r3 = S32(ctx->r3 << 4);
    // 0x80378FD4: lbu         $a0, 0x31($t0)
    ctx->r4 = MEM_BU(ctx->r8, 0X31);
    // 0x80378FD8: addu        $a2, $t1, $v1
    ctx->r6 = ADD32(ctx->r9, ctx->r3);
    // 0x80378FDC: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x80378FE0: jal         0x803781A4
    // 0x80378FE4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    func_ovl8_803781A4(rdram, ctx);
        goto after_6;
    // 0x80378FE4: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_6:
L_80378FE8:
    // 0x80378FE8: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x80378FEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80378FF0: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
    // 0x80378FF4: bnel        $s0, $t9, L_80378E1C
    if (ctx->r16 != ctx->r25) {
        // 0x80378FF8: lh          $t6, 0x6C($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X6C);
            goto L_80378E1C;
    }
    goto skip_1;
    // 0x80378FF8: lh          $t6, 0x6C($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X6C);
    skip_1:
    // 0x80378FFC: lw          $v0, 0x94($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X94);
    // 0x80379000: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
L_80379004:
    // 0x80379004: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80379008: bnel        $v0, $t3, L_80378DDC
    if (ctx->r2 != ctx->r11) {
        // 0x8037900C: lw          $t9, 0x90($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X90);
            goto L_80378DDC;
    }
    goto skip_2;
    // 0x8037900C: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    skip_2:
L_80379010:
    // 0x80379010: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80379014: lw          $t7, 0xA8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA8);
    // 0x80379018: lw          $t5, 0xB4($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XB4);
    // 0x8037901C: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80379020: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x80379024: bne         $fp, $t5, L_80378DAC
    if (ctx->r30 != ctx->r13) {
        // 0x80379028: sw          $t6, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r14;
            goto L_80378DAC;
    }
    // 0x80379028: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
L_8037902C:
    // 0x8037902C: lw          $t2, 0xB8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB8);
    // 0x80379030: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x80379034: addiu       $t8, $t2, 0x1
    ctx->r24 = ADD32(ctx->r10, 0X1);
    // 0x80379038: bne         $t8, $t1, L_80378D64
    if (ctx->r24 != ctx->r9) {
        // 0x8037903C: sw          $t8, 0xB8($sp)
        MEM_W(0XB8, ctx->r29) = ctx->r24;
            goto L_80378D64;
    }
    // 0x8037903C: sw          $t8, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r24;
L_80379040:
    // 0x80379040: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80379044: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80379048: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8037904C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80379050: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80379054: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80379058: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8037905C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80379060: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80379064: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80379068: jr          $ra
    // 0x8037906C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x8037906C: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void gcGetAObjTrackAnimTimeMax(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E428: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8000E42C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8000E430: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8000E434: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8000E438: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x8000E43C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000E440: beq         $at, $zero, L_8000E478
    if (ctx->r1 == 0) {
        // 0x8000E444: sw          $a3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r7;
            goto L_8000E478;
    }
    // 0x8000E444: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8000E448: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000E44C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000E450: addu        $at, $at, $t6
    gpr jr_addend_8000E458 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000E454: lw          $t6, -0x2080($at)
    ctx->r14 = ADD32(ctx->r1, -0X2080);
    // 0x8000E458: jr          $t6
    // 0x8000E45C: nop

    switch (jr_addend_8000E458 >> 2) {
        case 0: goto L_8000E460; break;
        case 1: goto L_8000E460; break;
        case 2: goto L_8000E460; break;
        case 3: goto L_8000E478; break;
        case 4: goto L_8000E468; break;
        case 5: goto L_8000E468; break;
        case 6: goto L_8000E468; break;
        case 7: goto L_8000E470; break;
        case 8: goto L_8000E470; break;
        case 9: goto L_8000E470; break;
        default: switch_error(__func__, 0x8000E458, 0x8003DF80);
    }
    // 0x8000E45C: nop

L_8000E460:
    // 0x8000E460: b           L_8000E478
    // 0x8000E464: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
        goto L_8000E478;
    // 0x8000E464: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
L_8000E468:
    // 0x8000E468: b           L_8000E478
    // 0x8000E46C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
        goto L_8000E478;
    // 0x8000E46C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
L_8000E470:
    // 0x8000E470: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8000E474: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
L_8000E478:
    // 0x8000E478: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8000E47C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E480: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8000E484: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
    // 0x8000E488: nop

    // 0x8000E48C: bc1tl       L_8000E89C
    if (c1cs) {
        // 0x8000E490: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E89C;
    }
    goto skip_0;
    // 0x8000E490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8000E494: lwc1        $f0, 0x18($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8000E498: lwc1        $f10, 0x1C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8000E49C: lui         $at, 0xC0C0
    ctx->r1 = S32(0XC0C0 << 16);
    // 0x8000E4A0: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8000E4A4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000E4A8: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E4AC: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000E4B0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000E4B4: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8000E4B8: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8000E4BC: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8000E4C0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8000E4C4: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000E4C8: nop

    // 0x8000E4CC: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8000E4D0: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8000E4D4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E4D8: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E4DC: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x8000E4E0: nop

    // 0x8000E4E4: bc1f        L_8000E58C
    if (!c1cs) {
        // 0x8000E4E8: nop
    
            goto L_8000E58C;
    }
    // 0x8000E4E8: nop

    // 0x8000E4EC: sub.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8000E4F0: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8000E4F4: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8000E4F8: jal         0x80033510
    // 0x8000E4FC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8000E4FC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x8000E500: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000E504: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E508: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8000E50C: neg.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = -ctx->f18.fl;
    // 0x8000E510: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000E514: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8000E518: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E51C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000E520: div.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000E524: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8000E528: nop

    // 0x8000E52C: bc1fl       L_8000E53C
    if (!c1cs) {
        // 0x8000E530: swc1        $f14, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
            goto L_8000E53C;
    }
    goto skip_1;
    // 0x8000E530: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    skip_1:
    // 0x8000E534: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8000E538: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
L_8000E53C:
    // 0x8000E53C: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8000E540: jal         0x80033510
    // 0x8000E544: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8000E544: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8000E548: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000E54C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E550: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8000E554: sub.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8000E558: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8000E55C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E560: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000E564: div.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000E568: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000E56C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8000E570: nop

    // 0x8000E574: bc1fl       L_8000E584
    if (!c1cs) {
        // 0x8000E578: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8000E584;
    }
    goto skip_2;
    // 0x8000E578: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_2:
    // 0x8000E57C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8000E580: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8000E584:
    // 0x8000E584: b           L_8000E5CC
    // 0x8000E588: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
        goto L_8000E5CC;
    // 0x8000E588: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
L_8000E58C:
    // 0x8000E58C: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8000E590: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E594: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x8000E598: nop

    // 0x8000E59C: bc1fl       L_8000E5CC
    if (!c1cs) {
        // 0x8000E5A0: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8000E5CC;
    }
    goto skip_3;
    // 0x8000E5A0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    skip_3:
    // 0x8000E5A4: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8000E5A8: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8000E5AC: div.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000E5B0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E5B4: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8000E5B8: nop

    // 0x8000E5BC: bc1fl       L_8000E5CC
    if (!c1cs) {
        // 0x8000E5C0: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8000E5CC;
    }
    goto skip_4;
    // 0x8000E5C0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x8000E5C4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8000E5C8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
L_8000E5CC:
    // 0x8000E5CC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8000E5D0: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8000E5D4: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8000E5D8: nop

    // 0x8000E5DC: bc1fl       L_8000E674
    if (!c1cs) {
        // 0x8000E5E0: c.eq.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
            goto L_8000E674;
    }
    goto skip_5;
    // 0x8000E5E0: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    skip_5:
    // 0x8000E5E4: neg.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = -ctx->f18.fl;
    // 0x8000E5E8: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x8000E5EC: jal         0x80033510
    // 0x8000E5F0: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8000E5F0: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x8000E5F4: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000E5F8: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E5FC: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8000E600: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8000E604: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000E608: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E60C: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x8000E610: div.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000E614: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8000E618: nop

    // 0x8000E61C: bc1fl       L_8000E62C
    if (!c1cs) {
        // 0x8000E620: swc1        $f14, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
            goto L_8000E62C;
    }
    goto skip_6;
    // 0x8000E620: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    skip_6:
    // 0x8000E624: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8000E628: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
L_8000E62C:
    // 0x8000E62C: jal         0x80033510
    // 0x8000E630: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8000E630: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8000E634: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000E638: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E63C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8000E640: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8000E644: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8000E648: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E64C: div.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000E650: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8000E654: nop

    // 0x8000E658: bc1fl       L_8000E668
    if (!c1cs) {
        // 0x8000E65C: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8000E668;
    }
    goto skip_7;
    // 0x8000E65C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_7:
    // 0x8000E660: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8000E664: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8000E668:
    // 0x8000E668: b           L_8000E6A8
    // 0x8000E66C: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
        goto L_8000E6A8;
    // 0x8000E66C: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8000E670: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
L_8000E674:
    // 0x8000E674: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E678: bc1fl       L_8000E6A8
    if (!c1cs) {
        // 0x8000E67C: lwc1        $f0, 0x1C($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_8000E6A8;
    }
    goto skip_8;
    // 0x8000E67C: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    skip_8:
    // 0x8000E680: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8000E684: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8000E688: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E68C: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000E690: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8000E694: nop

    // 0x8000E698: bc1fl       L_8000E6A8
    if (!c1cs) {
        // 0x8000E69C: lwc1        $f0, 0x1C($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
            goto L_8000E6A8;
    }
    goto skip_9;
    // 0x8000E69C: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
    skip_9:
    // 0x8000E6A0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8000E6A4: lwc1        $f0, 0x1C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X1C);
L_8000E6A8:
    // 0x8000E6A8: lwc1        $f6, 0x18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X18);
    // 0x8000E6AC: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8000E6B0: add.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8000E6B4: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8000E6B8: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8000E6BC: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8000E6C0: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8000E6C4: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
    // 0x8000E6C8: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000E6CC: nop

    // 0x8000E6D0: mul.s       $f10, $f18, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8000E6D4: swc1        $f10, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f10.u32l;
    // 0x8000E6D8: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E6DC: lwc1        $f10, 0x24($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E6E0: c.lt.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl < ctx->f4.fl;
    // 0x8000E6E4: nop

    // 0x8000E6E8: bc1f        L_8000E78C
    if (!c1cs) {
        // 0x8000E6EC: nop
    
            goto L_8000E78C;
    }
    // 0x8000E6EC: nop

    // 0x8000E6F0: sub.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x8000E6F4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8000E6F8: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8000E6FC: jal         0x80033510
    // 0x8000E700: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x8000E700: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x8000E704: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000E708: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E70C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8000E710: neg.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = -ctx->f18.fl;
    // 0x8000E714: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000E718: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8000E71C: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E720: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000E724: div.s       $f2, $f8, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000E728: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8000E72C: nop

    // 0x8000E730: bc1fl       L_8000E740
    if (!c1cs) {
        // 0x8000E734: swc1        $f14, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
            goto L_8000E740;
    }
    goto skip_10;
    // 0x8000E734: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    skip_10:
    // 0x8000E738: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8000E73C: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
L_8000E740:
    // 0x8000E740: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x8000E744: jal         0x80033510
    // 0x8000E748: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x8000E748: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x8000E74C: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000E750: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E754: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8000E758: sub.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8000E75C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000E760: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E764: lwc1        $f18, 0x3C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000E768: div.s       $f2, $f4, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8000E76C: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8000E770: nop

    // 0x8000E774: bc1fl       L_8000E784
    if (!c1cs) {
        // 0x8000E778: mtc1        $zero, $f2
        ctx->f2.u32l = 0;
            goto L_8000E784;
    }
    goto skip_11;
    // 0x8000E778: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    skip_11:
    // 0x8000E77C: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8000E780: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_8000E784:
    // 0x8000E784: b           L_8000E7C8
    // 0x8000E788: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
        goto L_8000E7C8;
    // 0x8000E788: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
L_8000E78C:
    // 0x8000E78C: sub.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8000E790: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E794: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x8000E798: nop

    // 0x8000E79C: bc1fl       L_8000E7C8
    if (!c1cs) {
        // 0x8000E7A0: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8000E7C8;
    }
    goto skip_12;
    // 0x8000E7A0: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    skip_12:
    // 0x8000E7A4: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8000E7A8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E7AC: div.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000E7B0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8000E7B4: nop

    // 0x8000E7B8: bc1fl       L_8000E7C8
    if (!c1cs) {
        // 0x8000E7BC: lwc1        $f4, 0x24($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
            goto L_8000E7C8;
    }
    goto skip_13;
    // 0x8000E7BC: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    skip_13:
    // 0x8000E7C0: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8000E7C4: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
L_8000E7C8:
    // 0x8000E7C8: add.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8000E7CC: lwc1        $f16, 0x2C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E7D0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x8000E7D4: nop

    // 0x8000E7D8: bc1fl       L_8000E868
    if (!c1cs) {
        // 0x8000E7DC: c.eq.s      $f12, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
            goto L_8000E868;
    }
    goto skip_14;
    // 0x8000E7DC: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
    skip_14:
    // 0x8000E7E0: neg.s       $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = -ctx->f18.fl;
    // 0x8000E7E4: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
    // 0x8000E7E8: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8000E7EC: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x8000E7F0: jal         0x80033510
    // 0x8000E7F4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x8000E7F4: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x8000E7F8: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000E7FC: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E800: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8000E804: add.s       $f8, $f0, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x8000E808: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8000E80C: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E810: div.s       $f2, $f8, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000E814: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x8000E818: nop

    // 0x8000E81C: bc1fl       L_8000E82C
    if (!c1cs) {
        // 0x8000E820: swc1        $f14, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
            goto L_8000E82C;
    }
    goto skip_15;
    // 0x8000E820: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    skip_15:
    // 0x8000E824: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8000E828: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
L_8000E82C:
    // 0x8000E82C: jal         0x80033510
    // 0x8000E830: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x8000E830: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_7:
    // 0x8000E834: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000E838: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000E83C: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x8000E840: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8000E844: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E848: div.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8000E84C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x8000E850: nop

    // 0x8000E854: bc1fl       L_8000E89C
    if (!c1cs) {
        // 0x8000E858: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E89C;
    }
    goto skip_16;
    // 0x8000E858: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_16:
    // 0x8000E85C: b           L_8000E898
    // 0x8000E860: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
        goto L_8000E898;
    // 0x8000E860: swc1        $f2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f2.u32l;
    // 0x8000E864: c.eq.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl == ctx->f2.fl;
L_8000E868:
    // 0x8000E868: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000E86C: bc1fl       L_8000E89C
    if (!c1cs) {
        // 0x8000E870: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E89C;
    }
    goto skip_17;
    // 0x8000E870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_17:
    // 0x8000E874: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x8000E878: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8000E87C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8000E880: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000E884: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8000E888: nop

    // 0x8000E88C: bc1fl       L_8000E89C
    if (!c1cs) {
        // 0x8000E890: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8000E89C;
    }
    goto skip_18;
    // 0x8000E890: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x8000E894: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_8000E898:
    // 0x8000E898: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000E89C:
    // 0x8000E89C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8000E8A0: jr          $ra
    // 0x8000E8A4: nop

    return;
    // 0x8000E8A4: nop

;}
RECOMP_FUNC void ftSamusSpecialNEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D968: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D96C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D970: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015D974: jal         0x800DDE84
    // 0x8015D978: addiu       $a1, $a1, -0x25FC
    ctx->r5 = ADD32(ctx->r5, -0X25FC);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x8015D978: addiu       $a1, $a1, -0x25FC
    ctx->r5 = ADD32(ctx->r5, -0X25FC);
    after_0:
    // 0x8015D97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D980: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D984: jr          $ra
    // 0x8015D988: nop

    return;
    // 0x8015D988: nop

;}
RECOMP_FUNC void func_ovl7_8018FB40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018FB40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018FB44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018FB48: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018FB4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018FB50: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8018FB54: jal         0x80009968
    // 0x8018FB58: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018FB58: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018FB5C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018FB60: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018FB64: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018FB68: sw          $v0, 0xBD8($at)
    MEM_W(0XBD8, ctx->r1) = ctx->r2;
    // 0x8018FB6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018FB70: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018FB74: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018FB78: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018FB7C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018FB80: jal         0x80009DF4
    // 0x8018FB84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018FB84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018FB88: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018FB8C: lw          $a1, 0xB90($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XB90);
    // 0x8018FB90: jal         0x8018F7C8
    // 0x8018FB94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl7_8018F7C8(rdram, ctx);
        goto after_2;
    // 0x8018FB94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8018FB98: jal         0x8018FA54
    // 0x8018FB9C: nop

    func_ovl7_8018FA54(rdram, ctx);
        goto after_3;
    // 0x8018FB9C: nop

    after_3:
    // 0x8018FBA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018FBA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018FBA8: jr          $ra
    // 0x8018FBAC: nop

    return;
    // 0x8018FBAC: nop

;}
RECOMP_FUNC void mvOpeningYamabukiStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132344: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132348: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013234C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132350: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80132354: addiu       $a0, $a0, 0x23D8
    ctx->r4 = ADD32(ctx->r4, 0X23D8);
    // 0x80132358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013235C: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132360: jal         0x80007024
    // 0x80132364: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132364: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132368: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8013236C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132370: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132374: addiu       $t9, $t9, 0x2660
    ctx->r25 = ADD32(ctx->r25, 0X2660);
    // 0x80132378: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8013237C: addiu       $a0, $a0, 0x23F4
    ctx->r4 = ADD32(ctx->r4, 0X23F4);
    // 0x80132380: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132384: jal         0x8000683C
    // 0x80132388: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80132388: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8013238C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132390: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132394: jr          $ra
    // 0x80132398: nop

    return;
    // 0x80132398: nop

;}
RECOMP_FUNC void itHarisenFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017522C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175230: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80175234: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80175238: lbu         $t7, 0x2CE($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X2CE);
    // 0x8017523C: andi        $t8, $t7, 0xFF7F
    ctx->r24 = ctx->r15 & 0XFF7F;
    // 0x80175240: jal         0x80173F78
    // 0x80175244: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80175244: sb          $t8, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r24;
    after_0:
    // 0x80175248: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017524C: addiu       $a1, $a1, -0x6554
    ctx->r5 = ADD32(ctx->r5, -0X6554);
    // 0x80175250: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80175254: jal         0x80172EC8
    // 0x80175258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80175258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8017525C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175260: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175264: jr          $ra
    // 0x80175268: nop

    return;
    // 0x80175268: nop

;}
RECOMP_FUNC void itLizardonAttackMakeFlame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FD2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017FD30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017FD34: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017FD38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8017FD3C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017FD40: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8017FD44: jal         0x80035CD0
    // 0x8017FD48: lwc1        $f12, -0x318C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X318C);
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x8017FD48: lwc1        $f12, -0x318C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X318C);
    after_0:
    // 0x8017FD4C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8017FD50: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8017FD54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017FD58: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8017FD5C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017FD60: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8017FD64: lwc1        $f12, -0x3188($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3188);
    // 0x8017FD68: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8017FD6C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8017FD70: jal         0x800303F0
    // 0x8017FD74: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017FD74: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x8017FD78: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8017FD7C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017FD80: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017FD84: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8017FD88: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8017FD8C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8017FD90: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8017FD94: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    // 0x8017FD98: jal         0x8017FC38
    // 0x8017FD9C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    itLizardonWeaponFlameMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x8017FD9C: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x8017FDA0: jal         0x800269C0
    // 0x8017FDA4: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x8017FDA4: addiu       $a0, $zero, 0x88
    ctx->r4 = ADD32(0, 0X88);
    after_3:
    // 0x8017FDA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017FDAC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017FDB0: jr          $ra
    // 0x8017FDB4: nop

    return;
    // 0x8017FDB4: nop

;}
RECOMP_FUNC void func_ovl8_80372358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372358: jr          $ra
    // 0x8037235C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    return;
    // 0x8037235C: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
;}
RECOMP_FUNC void mnMapsMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801334AC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801334B0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801334B4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801334B8: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801334BC: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x801334C0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801334C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801334C8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801334CC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801334D0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801334D4: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801334D8: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801334DC: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801334E0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801334E4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801334E8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801334EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801334F0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801334F4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801334F8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801334FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80133500: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133504: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133508: jal         0x8000B93C
    // 0x8013350C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8013350C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133510: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133514: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133518: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013351C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133520: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133524: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133528: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013352C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133530: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80133534: jal         0x80007080
    // 0x80133538: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133538: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013353C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133540: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133544: jr          $ra
    // 0x80133548: nop

    return;
    // 0x80133548: nop

;}
RECOMP_FUNC void func_ovl8_80371E58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371E58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371E60: lw          $v0, 0x54($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X54);
    // 0x80371E64: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80371E68: beql        $v0, $zero, L_80371E80
    if (ctx->r2 == 0) {
        // 0x80371E6C: lw          $v0, 0x58($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X58);
            goto L_80371E80;
    }
    goto skip_0;
    // 0x80371E6C: lw          $v0, 0x58($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X58);
    skip_0:
    // 0x80371E70: jalr        $v0
    // 0x80371E74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_0;
    // 0x80371E74: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80371E78: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80371E7C: lw          $v0, 0x58($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X58);
L_80371E80:
    // 0x80371E80: lw          $t9, 0x134($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X134);
    // 0x80371E84: lh          $t6, 0x130($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X130);
    // 0x80371E88: jalr        $t9
    // 0x80371E8C: addu        $a0, $t6, $a1
    ctx->r4 = ADD32(ctx->r14, ctx->r5);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80371E8C: addu        $a0, $t6, $a1
    ctx->r4 = ADD32(ctx->r14, ctx->r5);
    after_1:
    // 0x80371E90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371E94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371E98: jr          $ra
    // 0x80371E9C: nop

    return;
    // 0x80371E9C: nop

;}
RECOMP_FUNC void unref_80000938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000938: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000093C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80000940: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80000944: lw          $a0, 0x4EDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4EDC);
    // 0x80000948: lw          $v1, 0x4EE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4EE4);
    // 0x8000094C: lw          $v0, 0x4ECC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ECC);
L_80000950:
    // 0x80000950: bne         $v0, $zero, L_80000950
    if (ctx->r2 != 0) {
        // 0x80000954: nop
    
            goto L_80000950;
    }
    // 0x80000954: nop

    // 0x80000958: bne         $v1, $zero, L_80000950
    if (ctx->r3 != 0) {
        // 0x8000095C: nop
    
            goto L_80000950;
    }
    // 0x8000095C: nop

    // 0x80000960: bne         $a0, $zero, L_80000950
    if (ctx->r4 != 0) {
        // 0x80000964: nop
    
            goto L_80000950;
    }
    // 0x80000964: nop

    // 0x80000968: jr          $ra
    // 0x8000096C: nop

    return;
    // 0x8000096C: nop

;}
RECOMP_FUNC void ftComputerCheckTryChargeSpecialN(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136A20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136A28: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x80136A2C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80136A30: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80136A34: beql        $v0, $v1, L_80136A60
    if (ctx->r2 == ctx->r3) {
        // 0x80136A38: lw          $v0, 0x24($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X24);
            goto L_80136A60;
    }
    goto skip_0;
    // 0x80136A38: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    skip_0:
    // 0x80136A3C: beq         $v0, $a1, L_80136B04
    if (ctx->r2 == ctx->r5) {
        // 0x80136A40: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80136B04;
    }
    // 0x80136A40: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80136A44: beq         $v0, $at, L_80136B4C
    if (ctx->r2 == ctx->r1) {
        // 0x80136A48: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_80136B4C;
    }
    // 0x80136A48: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x80136A4C: beql        $v0, $at, L_80136AC0
    if (ctx->r2 == ctx->r1) {
        // 0x80136A50: lw          $t7, 0x24($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X24);
            goto L_80136AC0;
    }
    goto skip_1;
    // 0x80136A50: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    skip_1:
    // 0x80136A54: b           L_80136BFC
    // 0x80136A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80136BFC;
    // 0x80136A58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80136A5C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
L_80136A60:
    // 0x80136A60: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80136A64: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136A68: addiu       $at, $zero, 0xDF
        ctx->r1 = ADD32(0, 0XDF);
            goto L_80136BF8;
    }
    // 0x80136A68: addiu       $at, $zero, 0xDF
    ctx->r1 = ADD32(0, 0XDF);
    // 0x80136A6C: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136A70: addiu       $at, $zero, 0xE0
        ctx->r1 = ADD32(0, 0XE0);
            goto L_80136BF8;
    }
    // 0x80136A70: addiu       $at, $zero, 0xE0
    ctx->r1 = ADD32(0, 0XE0);
    // 0x80136A74: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136A78: addiu       $at, $zero, 0xE1
        ctx->r1 = ADD32(0, 0XE1);
            goto L_80136BF8;
    }
    // 0x80136A78: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x80136A7C: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136A80: addiu       $at, $zero, 0xE8
        ctx->r1 = ADD32(0, 0XE8);
            goto L_80136BF8;
    }
    // 0x80136A80: addiu       $at, $zero, 0xE8
    ctx->r1 = ADD32(0, 0XE8);
    // 0x80136A84: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136A88: addiu       $at, $zero, 0xE9
        ctx->r1 = ADD32(0, 0XE9);
            goto L_80136BF8;
    }
    // 0x80136A88: addiu       $at, $zero, 0xE9
    ctx->r1 = ADD32(0, 0XE9);
    // 0x80136A8C: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136A90: addiu       $at, $zero, 0xEA
        ctx->r1 = ADD32(0, 0XEA);
            goto L_80136BF8;
    }
    // 0x80136A90: addiu       $at, $zero, 0xEA
    ctx->r1 = ADD32(0, 0XEA);
    // 0x80136A94: beql        $v0, $at, L_80136BFC
    if (ctx->r2 == ctx->r1) {
        // 0x80136A98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136BFC;
    }
    goto skip_2;
    // 0x80136A98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x80136A9C: lw          $t6, 0xADC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XADC);
    // 0x80136AA0: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x80136AA4: beql        $at, $zero, L_80136BFC
    if (ctx->r1 == 0) {
        // 0x80136AA8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136BFC;
    }
    goto skip_3;
    // 0x80136AA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x80136AAC: jal         0x80132564
    // 0x80136AB0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_0;
    // 0x80136AB0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_0:
    // 0x80136AB4: b           L_80136BFC
    // 0x80136AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136BFC;
    // 0x80136AB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80136ABC: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
L_80136AC0:
    // 0x80136AC0: addiu       $t8, $t7, -0xA
    ctx->r24 = ADD32(ctx->r15, -0XA);
    // 0x80136AC4: sltiu       $at, $t8, 0x1B
    ctx->r1 = ctx->r24 < 0X1B ? 1 : 0;
    // 0x80136AC8: beq         $at, $zero, L_80136BF8
    if (ctx->r1 == 0) {
        // 0x80136ACC: sll         $t8, $t8, 2
        ctx->r24 = S32(ctx->r24 << 2);
            goto L_80136BF8;
    }
    // 0x80136ACC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80136AD0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80136AD4: addu        $at, $at, $t8
    gpr jr_addend_80136ADC = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80136AD8: lw          $t8, -0x4210($at)
    ctx->r24 = ADD32(ctx->r1, -0X4210);
    // 0x80136ADC: jr          $t8
    // 0x80136AE0: nop

    switch (jr_addend_80136ADC >> 2) {
        case 0: goto L_80136AE4; break;
        case 1: goto L_80136AE4; break;
        case 2: goto L_80136AE4; break;
        case 3: goto L_80136AE4; break;
        case 4: goto L_80136BF8; break;
        case 5: goto L_80136AE4; break;
        case 6: goto L_80136AE4; break;
        case 7: goto L_80136AE4; break;
        case 8: goto L_80136BF8; break;
        case 9: goto L_80136BF8; break;
        case 10: goto L_80136BF8; break;
        case 11: goto L_80136BF8; break;
        case 12: goto L_80136BF8; break;
        case 13: goto L_80136BF8; break;
        case 14: goto L_80136BF8; break;
        case 15: goto L_80136BF8; break;
        case 16: goto L_80136BF8; break;
        case 17: goto L_80136BF8; break;
        case 18: goto L_80136AE4; break;
        case 19: goto L_80136AE4; break;
        case 20: goto L_80136AE4; break;
        case 21: goto L_80136AE4; break;
        case 22: goto L_80136BF8; break;
        case 23: goto L_80136BF8; break;
        case 24: goto L_80136BF8; break;
        case 25: goto L_80136AE4; break;
        case 26: goto L_80136AE4; break;
        default: switch_error(__func__, 0x80136ADC, 0x8018BDF0);
    }
    // 0x80136AE0: nop

L_80136AE4:
    // 0x80136AE4: lw          $t9, 0xADC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XADC);
    // 0x80136AE8: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x80136AEC: beql        $at, $zero, L_80136BFC
    if (ctx->r1 == 0) {
        // 0x80136AF0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136BFC;
    }
    goto skip_4;
    // 0x80136AF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x80136AF4: jal         0x80132564
    // 0x80136AF8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_1;
    // 0x80136AF8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_1:
    // 0x80136AFC: b           L_80136BFC
    // 0x80136B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136BFC;
    // 0x80136B00: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136B04:
    // 0x80136B04: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80136B08: addiu       $at, $zero, 0xDE
    ctx->r1 = ADD32(0, 0XDE);
    // 0x80136B0C: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136B10: addiu       $at, $zero, 0xE1
        ctx->r1 = ADD32(0, 0XE1);
            goto L_80136BF8;
    }
    // 0x80136B10: addiu       $at, $zero, 0xE1
    ctx->r1 = ADD32(0, 0XE1);
    // 0x80136B14: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136B18: addiu       $at, $zero, 0xDF
        ctx->r1 = ADD32(0, 0XDF);
            goto L_80136BF8;
    }
    // 0x80136B18: addiu       $at, $zero, 0xDF
    ctx->r1 = ADD32(0, 0XDF);
    // 0x80136B1C: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136B20: addiu       $at, $zero, 0xE2
        ctx->r1 = ADD32(0, 0XE2);
            goto L_80136BF8;
    }
    // 0x80136B20: addiu       $at, $zero, 0xE2
    ctx->r1 = ADD32(0, 0XE2);
    // 0x80136B24: beql        $v0, $at, L_80136BFC
    if (ctx->r2 == ctx->r1) {
        // 0x80136B28: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136BFC;
    }
    goto skip_5;
    // 0x80136B28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80136B2C: lw          $t0, 0xADC($a0)
    ctx->r8 = MEM_W(ctx->r4, 0XADC);
    // 0x80136B30: slti        $at, $t0, 0x7
    ctx->r1 = SIGNED(ctx->r8) < 0X7 ? 1 : 0;
    // 0x80136B34: beql        $at, $zero, L_80136BFC
    if (ctx->r1 == 0) {
        // 0x80136B38: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136BFC;
    }
    goto skip_6;
    // 0x80136B38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_6:
    // 0x80136B3C: jal         0x80132564
    // 0x80136B40: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_2;
    // 0x80136B40: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_2:
    // 0x80136B44: b           L_80136BFC
    // 0x80136B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136BFC;
    // 0x80136B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136B4C:
    // 0x80136B4C: lw          $v0, 0xADC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XADC);
    // 0x80136B50: beql        $v0, $v1, L_80136B6C
    if (ctx->r2 == ctx->r3) {
        // 0x80136B54: lw          $v0, 0x24($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X24);
            goto L_80136B6C;
    }
    goto skip_7;
    // 0x80136B54: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    skip_7:
    // 0x80136B58: beql        $v0, $a1, L_80136BB4
    if (ctx->r2 == ctx->r5) {
        // 0x80136B5C: lw          $v0, 0x24($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X24);
            goto L_80136BB4;
    }
    goto skip_8;
    // 0x80136B5C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    skip_8:
    // 0x80136B60: b           L_80136BFC
    // 0x80136B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80136BFC;
    // 0x80136B64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80136B68: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
L_80136B6C:
    // 0x80136B6C: addiu       $at, $zero, 0xF2
    ctx->r1 = ADD32(0, 0XF2);
    // 0x80136B70: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136B74: addiu       $at, $zero, 0xF3
        ctx->r1 = ADD32(0, 0XF3);
            goto L_80136BF8;
    }
    // 0x80136B74: addiu       $at, $zero, 0xF3
    ctx->r1 = ADD32(0, 0XF3);
    // 0x80136B78: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136B7C: addiu       $at, $zero, 0xF4
        ctx->r1 = ADD32(0, 0XF4);
            goto L_80136BF8;
    }
    // 0x80136B7C: addiu       $at, $zero, 0xF4
    ctx->r1 = ADD32(0, 0XF4);
    // 0x80136B80: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136B84: addiu       $at, $zero, 0xF5
        ctx->r1 = ADD32(0, 0XF5);
            goto L_80136BF8;
    }
    // 0x80136B84: addiu       $at, $zero, 0xF5
    ctx->r1 = ADD32(0, 0XF5);
    // 0x80136B88: beql        $v0, $at, L_80136BFC
    if (ctx->r2 == ctx->r1) {
        // 0x80136B8C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136BFC;
    }
    goto skip_9;
    // 0x80136B8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_9:
    // 0x80136B90: lw          $t1, 0xAE8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0XAE8);
    // 0x80136B94: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x80136B98: beql        $at, $zero, L_80136BFC
    if (ctx->r1 == 0) {
        // 0x80136B9C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136BFC;
    }
    goto skip_10;
    // 0x80136B9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_10:
    // 0x80136BA0: jal         0x80132564
    // 0x80136BA4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_3;
    // 0x80136BA4: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_3:
    // 0x80136BA8: b           L_80136BFC
    // 0x80136BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136BFC;
    // 0x80136BAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80136BB0: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
L_80136BB4:
    // 0x80136BB4: addiu       $at, $zero, 0xED
    ctx->r1 = ADD32(0, 0XED);
    // 0x80136BB8: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136BBC: addiu       $at, $zero, 0xF0
        ctx->r1 = ADD32(0, 0XF0);
            goto L_80136BF8;
    }
    // 0x80136BBC: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80136BC0: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136BC4: addiu       $at, $zero, 0xEE
        ctx->r1 = ADD32(0, 0XEE);
            goto L_80136BF8;
    }
    // 0x80136BC4: addiu       $at, $zero, 0xEE
    ctx->r1 = ADD32(0, 0XEE);
    // 0x80136BC8: beq         $v0, $at, L_80136BF8
    if (ctx->r2 == ctx->r1) {
        // 0x80136BCC: addiu       $at, $zero, 0xF1
        ctx->r1 = ADD32(0, 0XF1);
            goto L_80136BF8;
    }
    // 0x80136BCC: addiu       $at, $zero, 0xF1
    ctx->r1 = ADD32(0, 0XF1);
    // 0x80136BD0: beql        $v0, $at, L_80136BFC
    if (ctx->r2 == ctx->r1) {
        // 0x80136BD4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136BFC;
    }
    goto skip_11;
    // 0x80136BD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_11:
    // 0x80136BD8: lw          $t2, 0xAE0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XAE0);
    // 0x80136BDC: slti        $at, $t2, 0x7
    ctx->r1 = SIGNED(ctx->r10) < 0X7 ? 1 : 0;
    // 0x80136BE0: beql        $at, $zero, L_80136BFC
    if (ctx->r1 == 0) {
        // 0x80136BE4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136BFC;
    }
    goto skip_12;
    // 0x80136BE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_12:
    // 0x80136BE8: jal         0x80132564
    // 0x80136BEC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_4;
    // 0x80136BEC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_4:
    // 0x80136BF0: b           L_80136BFC
    // 0x80136BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80136BFC;
    // 0x80136BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136BF8:
    // 0x80136BF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136BFC:
    // 0x80136BFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136C00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136C04: jr          $ra
    // 0x80136C08: nop

    return;
    // 0x80136C08: nop

;}
RECOMP_FUNC void func_ovl8_80384E30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384E30: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80384E34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80384E38: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80384E3C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80384E40: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80384E44: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80384E48: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x80384E4C: jal         0x8037D95C
    // 0x80384E50: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_ovl8_8037D95C(rdram, ctx);
        goto after_0;
    // 0x80384E50: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x80384E54: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80384E58: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80384E5C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80384E60: addiu       $t7, $t6, 0x6
    ctx->r15 = ADD32(ctx->r14, 0X6);
    // 0x80384E64: sh          $t7, 0x2C($sp)
    MEM_H(0X2C, ctx->r29) = ctx->r15;
    // 0x80384E68: lh          $t8, 0x2($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X2);
    // 0x80384E6C: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    // 0x80384E70: addiu       $t9, $t8, 0x6
    ctx->r25 = ADD32(ctx->r24, 0X6);
    // 0x80384E74: jal         0x8037A5B8
    // 0x80384E78: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    func_ovl8_8037A5B8(rdram, ctx);
        goto after_1;
    // 0x80384E78: sh          $t9, 0x2E($sp)
    MEM_H(0X2E, ctx->r29) = ctx->r25;
    after_1:
    // 0x80384E7C: jal         0x8037D9B4
    // 0x80384E80: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_2;
    // 0x80384E80: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_2:
    // 0x80384E84: jal         0x8037D990
    // 0x80384E88: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_ovl8_8037D990(rdram, ctx);
        goto after_3;
    // 0x80384E88: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_3:
    // 0x80384E8C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80384E90: lw          $a0, 0x38($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X38);
    // 0x80384E94: jal         0x8037D9D0
    // 0x80384E98: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_4;
    // 0x80384E98: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_4:
    // 0x80384E9C: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x80384EA0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x80384EA4: lw          $t2, 0x40($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X40);
    // 0x80384EA8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x80384EAC: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x80384EB0: lw          $a0, -0x4($t3)
    ctx->r4 = MEM_W(ctx->r11, -0X4);
    // 0x80384EB4: jal         0x8037E7A8
    // 0x80384EB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_5;
    // 0x80384EB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_5:
    // 0x80384EBC: lhu         $t5, 0x4($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X4);
    // 0x80384EC0: lh          $t4, 0x0($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X0);
    // 0x80384EC4: lh          $a2, 0x2($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X2);
    // 0x80384EC8: bgez        $t5, L_80384ED8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x80384ECC: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_80384ED8;
    }
    // 0x80384ECC: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x80384ED0: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x80384ED4: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_80384ED8:
    // 0x80384ED8: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80384EDC: bgez        $v0, L_80384EEC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80384EE0: sra         $t8, $v0, 1
        ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80384EEC;
    }
    // 0x80384EE0: sra         $t8, $v0, 1
    ctx->r24 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80384EE4: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80384EE8: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_80384EEC:
    // 0x80384EEC: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x80384EF0: sll         $a0, $v1, 16
    ctx->r4 = S32(ctx->r3 << 16);
    // 0x80384EF4: sll         $a1, $a2, 16
    ctx->r5 = S32(ctx->r6 << 16);
    // 0x80384EF8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80384EFC: jal         0x8037DFCC
    // 0x80384F00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_6;
    // 0x80384F00: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    after_6:
    // 0x80384F04: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80384F08: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80384F0C: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80384F10: lw          $t0, 0x40($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X40);
    // 0x80384F14: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80384F18: jal         0x8037DD60
    // 0x80384F1C: lw          $a1, -0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, -0X4);
    func_ovl8_8037DD60(rdram, ctx);
        goto after_7;
    // 0x80384F1C: lw          $a1, -0x4($t2)
    ctx->r5 = MEM_W(ctx->r10, -0X4);
    after_7:
    // 0x80384F20: jal         0x8037D908
    // 0x80384F24: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    func_ovl8_8037D908(rdram, ctx);
        goto after_8;
    // 0x80384F24: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_8:
    // 0x80384F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80384F2C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80384F30: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80384F34: jr          $ra
    // 0x80384F38: nop

    return;
    // 0x80384F38: nop

;}
RECOMP_FUNC void grSectorArwingDecideZNear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106C28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80106C2C: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80106C30: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80106C34: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80106C38: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80106C3C: lwc1        $f0, 0x24($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X24);
    // 0x80106C40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80106C44: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80106C48: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80106C4C: nop

    // 0x80106C50: bc1fl       L_80106C64
    if (!c1cs) {
        // 0x80106C54: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80106C64;
    }
    goto skip_0;
    // 0x80106C54: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x80106C58: b           L_80106C64
    // 0x80106C5C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80106C64;
    // 0x80106C5C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80106C60: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80106C64:
    // 0x80106C64: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80106C68: nop

    // 0x80106C6C: bc1fl       L_80106C80
    if (!c1cs) {
        // 0x80106C70: sb          $zero, 0x56($v0)
        MEM_B(0X56, ctx->r2) = 0;
            goto L_80106C80;
    }
    goto skip_1;
    // 0x80106C70: sb          $zero, 0x56($v0)
    MEM_B(0X56, ctx->r2) = 0;
    skip_1:
    // 0x80106C74: jr          $ra
    // 0x80106C78: sb          $t7, 0x56($v0)
    MEM_B(0X56, ctx->r2) = ctx->r15;
    return;
    // 0x80106C78: sb          $t7, 0x56($v0)
    MEM_B(0X56, ctx->r2) = ctx->r15;
    // 0x80106C7C: sb          $zero, 0x56($v0)
    MEM_B(0X56, ctx->r2) = 0;
L_80106C80:
    // 0x80106C80: jr          $ra
    // 0x80106C84: nop

    return;
    // 0x80106C84: nop

;}
RECOMP_FUNC void func_ovl65_8018D38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D38C: jr          $ra
    // 0x8018D390: nop

    return;
    // 0x8018D390: nop

;}
RECOMP_FUNC void dbFallsFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D64C4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800D64C8: lhu         $t6, 0x5472($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X5472);
    // 0x800D64CC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D64D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D64D4: andi        $t7, $t6, 0x1000
    ctx->r15 = ctx->r14 & 0X1000;
    // 0x800D64D8: beq         $t7, $zero, L_800D6500
    if (ctx->r15 == 0) {
        // 0x800D64DC: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_800D6500;
    }
    // 0x800D64DC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800D64E0: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800D64E4: addiu       $t8, $zero, 0xD
    ctx->r24 = ADD32(0, 0XD);
    // 0x800D64E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800D64EC: addiu       $a3, $a3, 0x6738
    ctx->r7 = ADD32(ctx->r7, 0X6738);
    // 0x800D64F0: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800D64F4: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800D64F8: jal         0x80369D78
    // 0x800D64FC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    dbMenuMakeMenu(rdram, ctx);
        goto after_0;
    // 0x800D64FC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_0:
L_800D6500:
    // 0x800D6500: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800D6504: lw          $t9, 0x6720($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6720);
    // 0x800D6508: beql        $t9, $zero, L_800D6538
    if (ctx->r25 == 0) {
        // 0x800D650C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D6538;
    }
    goto skip_0;
    // 0x800D650C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800D6510: jal         0x80369EC0
    // 0x800D6514: nop

    dbMenuDestroyMenu(rdram, ctx);
        goto after_1;
    // 0x800D6514: nop

    after_1:
    // 0x800D6518: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D651C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x800D6520: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x800D6524: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800D6528: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x800D652C: jal         0x80005C74
    // 0x800D6530: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_2;
    // 0x800D6530: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_2:
    // 0x800D6534: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800D6538:
    // 0x800D6538: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D653C: jr          $ra
    // 0x800D6540: nop

    return;
    // 0x800D6540: nop

;}
RECOMP_FUNC void wpLinkBoomerangClampAngleForward(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016CFFC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D000: lwc1        $f2, -0x3470($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3470);
    // 0x8016D004: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8016D008: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D00C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8016D010: nop

    // 0x8016D014: bc1f        L_8016D038
    if (!c1cs) {
        // 0x8016D018: nop
    
            goto L_8016D038;
    }
    // 0x8016D018: nop

    // 0x8016D01C: lwc1        $f4, -0x346C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X346C);
    // 0x8016D020: c.le.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl <= ctx->f4.fl;
    // 0x8016D024: nop

    // 0x8016D028: bc1f        L_8016D038
    if (!c1cs) {
        // 0x8016D02C: nop
    
            goto L_8016D038;
    }
    // 0x8016D02C: nop

    // 0x8016D030: jr          $ra
    // 0x8016D034: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8016D034: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
L_8016D038:
    // 0x8016D038: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D03C: lwc1        $f2, -0x3468($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3468);
    // 0x8016D040: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D044: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8016D048: nop

    // 0x8016D04C: bc1f        L_8016D070
    if (!c1cs) {
        // 0x8016D050: nop
    
            goto L_8016D070;
    }
    // 0x8016D050: nop

    // 0x8016D054: lwc1        $f6, -0x3464($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3464);
    // 0x8016D058: c.le.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl <= ctx->f0.fl;
    // 0x8016D05C: nop

    // 0x8016D060: bc1f        L_8016D070
    if (!c1cs) {
        // 0x8016D064: nop
    
            goto L_8016D070;
    }
    // 0x8016D064: nop

    // 0x8016D068: jr          $ra
    // 0x8016D06C: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8016D06C: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
L_8016D070:
    // 0x8016D070: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D074: lwc1        $f2, -0x3460($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3460);
    // 0x8016D078: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D07C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8016D080: nop

    // 0x8016D084: bc1f        L_8016D0A8
    if (!c1cs) {
        // 0x8016D088: nop
    
            goto L_8016D0A8;
    }
    // 0x8016D088: nop

    // 0x8016D08C: lwc1        $f8, -0x345C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X345C);
    // 0x8016D090: c.le.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl <= ctx->f8.fl;
    // 0x8016D094: nop

    // 0x8016D098: bc1f        L_8016D0A8
    if (!c1cs) {
        // 0x8016D09C: nop
    
            goto L_8016D0A8;
    }
    // 0x8016D09C: nop

    // 0x8016D0A0: jr          $ra
    // 0x8016D0A4: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x8016D0A4: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
L_8016D0A8:
    // 0x8016D0A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D0AC: lwc1        $f2, -0x3458($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X3458);
    // 0x8016D0B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016D0B4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8016D0B8: nop

    // 0x8016D0BC: bc1f        L_8016D0DC
    if (!c1cs) {
        // 0x8016D0C0: nop
    
            goto L_8016D0DC;
    }
    // 0x8016D0C0: nop

    // 0x8016D0C4: lwc1        $f10, -0x3454($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3454);
    // 0x8016D0C8: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x8016D0CC: nop

    // 0x8016D0D0: bc1f        L_8016D0DC
    if (!c1cs) {
        // 0x8016D0D4: nop
    
            goto L_8016D0DC;
    }
    // 0x8016D0D4: nop

    // 0x8016D0D8: swc1        $f2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f2.u32l;
L_8016D0DC:
    // 0x8016D0DC: jr          $ra
    // 0x8016D0E0: nop

    return;
    // 0x8016D0E0: nop

;}

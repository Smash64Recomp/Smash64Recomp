#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void gmCollisionGetFighterAttackShieldPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0B78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0B80: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0B84: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800F0B88: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800F0B8C: jal         0x800F0850
    // 0x800F0B90: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    gmCollisionGetFighterAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0B90: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_0:
    // 0x800F0B94: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800F0B98: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800F0B9C: jal         0x800F09F0
    // 0x800F0BA0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    gmCollisionGetShieldPosition(rdram, ctx);
        goto after_1;
    // 0x800F0BA0: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_1:
    // 0x800F0BA4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0BA8: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0BAC: jal         0x800F0A48
    // 0x800F0BB0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_2;
    // 0x800F0BB0: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_2:
    // 0x800F0BB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0BB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0BBC: jr          $ra
    // 0x800F0BC0: nop

    return;
    // 0x800F0BC0: nop

;}
RECOMP_FUNC void efManagerDamageNormalHeavyMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDEAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800FDEB0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800FDEB4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800FDEB8: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800FDEBC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800FDEC0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FDEC4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800FDEC8: jal         0x800FD4B8
    // 0x800FDECC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FDECC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_0:
    // 0x800FDED0: bne         $v0, $zero, L_800FDEE0
    if (ctx->r2 != 0) {
        // 0x800FDED4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800FDEE0;
    }
    // 0x800FDED4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800FDED8: b           L_800FE050
    // 0x800FDEDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE050;
    // 0x800FDEDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FDEE0:
    // 0x800FDEE0: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FDEE4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FDEE8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FDEEC: jal         0x80009968
    // 0x800FDEF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FDEF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FDEF4: bne         $v0, $zero, L_800FDF0C
    if (ctx->r2 != 0) {
        // 0x800FDEF8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800FDF0C;
    }
    // 0x800FDEF8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800FDEFC: jal         0x800FD4F8
    // 0x800FDF00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FDF00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x800FDF04: b           L_800FE050
    // 0x800FDF08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE050;
    // 0x800FDF08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FDF0C:
    // 0x800FDF0C: sw          $s1, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->r17;
    // 0x800FDF10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FDF14: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FDF18: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    // 0x800FDF1C: jal         0x800CE9E8
    // 0x800FDF20: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FDF20: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    after_3:
    // 0x800FDF24: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800FDF28: beq         $v0, $zero, L_800FE040
    if (ctx->r2 == 0) {
        // 0x800FDF2C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FE040;
    }
    // 0x800FDF2C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FDF30: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FDF34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FDF38: jal         0x800CE1DC
    // 0x800FDF3C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x800FDF3C: sw          $a2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r6;
    after_4:
    // 0x800FDF40: beq         $v0, $zero, L_800FE02C
    if (ctx->r2 == 0) {
        // 0x800FDF44: lw          $a2, 0x34($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X34);
            goto L_800FE02C;
    }
    // 0x800FDF44: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x800FDF48: lui         $t6, 0x8010
    ctx->r14 = S32(0X8010 << 16);
    // 0x800FDF4C: addiu       $t6, $t6, -0x21C4
    ctx->r14 = ADD32(ctx->r14, -0X21C4);
    // 0x800FDF50: sw          $a2, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r6;
    // 0x800FDF54: sw          $t6, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r14;
    // 0x800FDF58: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800FDF5C: jal         0x800CEA14
    // 0x800FDF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x800FDF60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800FDF64: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800FDF68: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800FDF6C: lhu         $t7, 0x2A($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X2A);
    // 0x800FDF70: bnel        $t7, $zero, L_800FDF84
    if (ctx->r15 != 0) {
        // 0x800FDF74: sw          $v1, 0x28($s1)
        MEM_W(0X28, ctx->r17) = ctx->r3;
            goto L_800FDF84;
    }
    goto skip_0;
    // 0x800FDF74: sw          $v1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r3;
    skip_0:
    // 0x800FDF78: b           L_800FE050
    // 0x800FDF7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FE050;
    // 0x800FDF7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FDF80: sw          $v1, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r3;
L_800FDF84:
    // 0x800FDF84: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800FDF88: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800FDF8C: addu        $t3, $t3, $s2
    ctx->r11 = ADD32(ctx->r11, ctx->r18);
    // 0x800FDF90: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800FDF94: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x800FDF98: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800FDF9C: addu        $t4, $t4, $s2
    ctx->r12 = ADD32(ctx->r12, ctx->r18);
    // 0x800FDFA0: sw          $t8, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r24;
    // 0x800FDFA4: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800FDFA8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800FDFAC: addu        $t5, $t5, $s2
    ctx->r13 = ADD32(ctx->r13, ctx->r18);
    // 0x800FDFB0: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x800FDFB4: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800FDFB8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800FDFBC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800FDFC0: sw          $t1, 0x18($s1)
    MEM_W(0X18, ctx->r17) = ctx->r9;
    // 0x800FDFC4: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x800FDFC8: addu        $t7, $t7, $s2
    ctx->r15 = ADD32(ctx->r15, ctx->r18);
    // 0x800FDFCC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FDFD0: sw          $t0, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r8;
    // 0x800FDFD4: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x800FDFD8: sb          $s2, 0x24($s1)
    MEM_B(0X24, ctx->r17) = ctx->r18;
    // 0x800FDFDC: addu        $t8, $t8, $s2
    ctx->r24 = ADD32(ctx->r24, ctx->r18);
    // 0x800FDFE0: sw          $t1, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r9;
    // 0x800FDFE4: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x800FDFE8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800FDFEC: addu        $t9, $t9, $s2
    ctx->r25 = ADD32(ctx->r25, ctx->r18);
    // 0x800FDFF0: sw          $t2, 0x28($s1)
    MEM_W(0X28, ctx->r17) = ctx->r10;
    // 0x800FDFF4: lbu         $t3, -0x2168($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X2168);
    // 0x800FDFF8: sb          $t3, 0x48($s0)
    MEM_B(0X48, ctx->r16) = ctx->r11;
    // 0x800FDFFC: lbu         $t4, -0x2160($t4)
    ctx->r12 = MEM_BU(ctx->r12, -0X2160);
    // 0x800FE000: sb          $t4, 0x49($s0)
    MEM_B(0X49, ctx->r16) = ctx->r12;
    // 0x800FE004: lbu         $t5, -0x2158($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X2158);
    // 0x800FE008: sb          $t6, 0x4B($s0)
    MEM_B(0X4B, ctx->r16) = ctx->r14;
    // 0x800FE00C: sb          $t5, 0x4A($s0)
    MEM_B(0X4A, ctx->r16) = ctx->r13;
    // 0x800FE010: lbu         $t7, -0x2150($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2150);
    // 0x800FE014: sb          $t7, 0x50($s0)
    MEM_B(0X50, ctx->r16) = ctx->r15;
    // 0x800FE018: lbu         $t8, -0x2148($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X2148);
    // 0x800FE01C: sb          $t8, 0x51($s0)
    MEM_B(0X51, ctx->r16) = ctx->r24;
    // 0x800FE020: lbu         $t9, -0x2140($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2140);
    // 0x800FE024: b           L_800FE04C
    // 0x800FE028: sb          $t9, 0x52($s0)
    MEM_B(0X52, ctx->r16) = ctx->r25;
        goto L_800FE04C;
    // 0x800FE028: sb          $t9, 0x52($s0)
    MEM_B(0X52, ctx->r16) = ctx->r25;
L_800FE02C:
    // 0x800FE02C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FE030: jal         0x800FDB3C
    // 0x800FE034: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_6;
    // 0x800FE034: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_6:
    // 0x800FE038: b           L_800FE04C
    // 0x800FE03C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800FE04C;
    // 0x800FE03C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FE040:
    // 0x800FE040: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FE044: jal         0x800FDB3C
    // 0x800FE048: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_7;
    // 0x800FE048: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_7:
L_800FE04C:
    // 0x800FE04C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800FE050:
    // 0x800FE050: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800FE054: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FE058: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800FE05C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800FE060: jr          $ra
    // 0x800FE064: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800FE064: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void mnModeSelectFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A0C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132A10: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80132A14: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132A18: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132A1C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132A20: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80132A24: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80132A28: addiu       $t8, $t8, 0x2CA8
    ctx->r24 = ADD32(ctx->r24, 0X2CA8);
    // 0x80132A2C: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x80132A30: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80132A34: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x80132A38: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80132A3C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80132A40: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80132A44: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80132A48: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80132A4C: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80132A50: jal         0x800CDF78
    // 0x80132A54: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132A54: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x80132A58: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132A5C: addiu       $a0, $a0, 0x2B90
    ctx->r4 = ADD32(ctx->r4, 0X2B90);
    // 0x80132A60: jal         0x800CDEEC
    // 0x80132A64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80132A64: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80132A68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132A6C: jal         0x80004980
    // 0x80132A70: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132A70: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132A74: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132A78: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132A7C: addiu       $a2, $a2, 0x2D68
    ctx->r6 = ADD32(ctx->r6, 0X2D68);
    // 0x80132A80: addiu       $a0, $a0, 0x2B90
    ctx->r4 = ADD32(ctx->r4, 0X2B90);
    // 0x80132A84: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132A88: jal         0x800CDE04
    // 0x80132A8C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132A8C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132A90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132A94: addiu       $a1, $a1, 0x25E8
    ctx->r5 = ADD32(ctx->r5, 0X25E8);
    // 0x80132A98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132A9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132AA0: jal         0x80009968
    // 0x80132AA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132AA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132AA8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132AAC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132AB0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132AB4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80132AB8: jal         0x8000B9FC
    // 0x80132ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132ABC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80132AC0: jal         0x80132558
    // 0x80132AC4: nop

    mnModeSelectInitVars(rdram, ctx);
        goto after_6;
    // 0x80132AC4: nop

    after_6:
    // 0x80132AC8: jal         0x80132438
    // 0x80132ACC: nop

    mnModeSelectMakeDecalsCamera(rdram, ctx);
        goto after_7;
    // 0x80132ACC: nop

    after_7:
    // 0x80132AD0: jal         0x80132398
    // 0x80132AD4: nop

    mnModeSelectMakeLabelsCamera(rdram, ctx);
        goto after_8;
    // 0x80132AD4: nop

    after_8:
    // 0x80132AD8: jal         0x80132168
    // 0x80132ADC: nop

    mnModeSelectMakeDecals(rdram, ctx);
        goto after_9;
    // 0x80132ADC: nop

    after_9:
    // 0x80132AE0: jal         0x801324D8
    // 0x80132AE4: nop

    mnModeSelectMakeOptions(rdram, ctx);
        goto after_10;
    // 0x80132AE4: nop

    after_10:
    // 0x80132AE8: jal         0x80131FB0
    // 0x80132AEC: nop

    mnModeSelectMakeLabels(rdram, ctx);
        goto after_11;
    // 0x80132AEC: nop

    after_11:
    // 0x80132AF0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132AF4: lbu         $v0, 0x4AD1($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X4AD1);
    // 0x80132AF8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80132AFC: beq         $v0, $at, L_80132B24
    if (ctx->r2 == ctx->r1) {
        // 0x80132B00: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_80132B24;
    }
    // 0x80132B00: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80132B04: beq         $v0, $at, L_80132B24
    if (ctx->r2 == ctx->r1) {
        // 0x80132B08: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_80132B24;
    }
    // 0x80132B08: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80132B0C: beq         $v0, $at, L_80132B24
    if (ctx->r2 == ctx->r1) {
        // 0x80132B10: addiu       $at, $zero, 0x3A
        ctx->r1 = ADD32(0, 0X3A);
            goto L_80132B24;
    }
    // 0x80132B10: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x80132B14: beq         $v0, $at, L_80132B24
    if (ctx->r2 == ctx->r1) {
        // 0x80132B18: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80132B24;
    }
    // 0x80132B18: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132B1C: jal         0x80020AB4
    // 0x80132B20: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    syAudioPlayBGM(rdram, ctx);
        goto after_12;
    // 0x80132B20: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_12:
L_80132B24:
    // 0x80132B24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132B28: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80132B2C: jr          $ra
    // 0x80132B30: nop

    return;
    // 0x80132B30: nop

;}
RECOMP_FUNC void func_ovl8_80372790(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372790: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80372794: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80372798: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037279C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803727A0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803727A4: bne         $a0, $zero, L_803727BC
    if (ctx->r4 != 0) {
        // 0x803727A8: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_803727BC;
    }
    // 0x803727A8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x803727AC: jal         0x803717A0
    // 0x803727B0: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803727B0: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_0:
    // 0x803727B4: beq         $v0, $zero, L_80372830
    if (ctx->r2 == 0) {
        // 0x803727B8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80372830;
    }
    // 0x803727B8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803727BC:
    // 0x803727BC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x803727C0: addiu       $a0, $s0, 0x38
    ctx->r4 = ADD32(ctx->r16, 0X38);
    // 0x803727C4: addiu       $a1, $s0, 0x94
    ctx->r5 = ADD32(ctx->r16, 0X94);
    // 0x803727C8: bnel        $t6, $zero, L_803727EC
    if (ctx->r14 != 0) {
        // 0x803727CC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_803727EC;
    }
    goto skip_0;
    // 0x803727CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x803727D0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803727D4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x803727D8: jal         0x803717E0
    // 0x803727DC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803727DC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x803727E0: jal         0x8037C2D0
    // 0x803727E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803727E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x803727E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_803727EC:
    // 0x803727EC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x803727F0: jal         0x803751C0
    // 0x803727F4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_803751C0(rdram, ctx);
        goto after_3;
    // 0x803727F4: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x803727F8: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x803727FC: addiu       $t7, $t7, -0x71A0
    ctx->r15 = ADD32(ctx->r15, -0X71A0);
    // 0x80372800: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80372804: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80372808: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037280C: addiu       $t8, $t8, -0x70E8
    ctx->r24 = ADD32(ctx->r24, -0X70E8);
    // 0x80372810: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80372814: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80372818: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8037281C: addiu       $t0, $t0, -0x6F90
    ctx->r8 = ADD32(ctx->r8, -0X6F90);
    // 0x80372820: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80372824: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80372828: jal         0x80373308
    // 0x8037282C: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    func_ovl8_80373308(rdram, ctx);
        goto after_4;
    // 0x8037282C: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    after_4:
L_80372830:
    // 0x80372830: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80372834: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80372838: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037283C: jr          $ra
    // 0x80372840: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80372840: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void itManagerInitMonsterVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F218: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8016F21C: addiu       $v0, $v0, -0x2FA0
    ctx->r2 = ADD32(ctx->r2, -0X2FA0);
    // 0x8016F220: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8016F224: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8016F228: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
    // 0x8016F22C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x8016F230: jr          $ra
    // 0x8016F234: sb          $t8, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r24;
    return;
    // 0x8016F234: sb          $t8, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void ftCommonRebirthStandProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D2AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013D2B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013D2B4: jal         0x8013D1D4
    // 0x8013D2B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonRebirthCommonUpdateHaloWait(rdram, ctx);
        goto after_0;
    // 0x8013D2B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013D2BC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013D2C0: addiu       $a1, $a1, -0x2AE8
    ctx->r5 = ADD32(ctx->r5, -0X2AE8);
    // 0x8013D2C4: jal         0x800D9480
    // 0x8013D2C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013D2C8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013D2CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013D2D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013D2D4: jr          $ra
    // 0x8013D2D8: nop

    return;
    // 0x8013D2D8: nop

;}
RECOMP_FUNC void mnVSModeUpdateButton(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F4C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131F50: addiu       $t6, $t6, 0x4848
    ctx->r14 = ADD32(ctx->r14, 0X4848);
    // 0x80131F54: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131F58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131F5C: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x80131F60: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131F64: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x80131F68: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131F6C: addiu       $t9, $t9, 0x4850
    ctx->r25 = ADD32(ctx->r25, 0X4850);
    // 0x80131F70: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80131F74: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80131F78: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x80131F7C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131F80: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80131F84: lhu         $t1, 0x4($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X4);
    // 0x80131F88: addiu       $t2, $t2, 0x4858
    ctx->r10 = ADD32(ctx->r10, 0X4858);
    // 0x80131F8C: addiu       $a3, $sp, 0x10
    ctx->r7 = ADD32(ctx->r29, 0X10);
    // 0x80131F90: sh          $t1, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r9;
    // 0x80131F94: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131F98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131F9C: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80131FA0: lhu         $t4, 0x4($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X4);
    // 0x80131FA4: beq         $a1, $zero, L_80131FCC
    if (ctx->r5 == 0) {
        // 0x80131FA8: sh          $t4, 0x4($a3)
        MEM_H(0X4, ctx->r7) = ctx->r12;
            goto L_80131FCC;
    }
    // 0x80131FA8: sh          $t4, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r12;
    // 0x80131FAC: beq         $a1, $at, L_80131FC4
    if (ctx->r5 == ctx->r1) {
        // 0x80131FB0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80131FC4;
    }
    // 0x80131FB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80131FB4: beq         $a1, $at, L_80131FD4
    if (ctx->r5 == ctx->r1) {
        // 0x80131FB8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80131FD4;
    }
    // 0x80131FB8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131FBC: b           L_80131FD4
    // 0x80131FC0: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
        goto L_80131FD4;
    // 0x80131FC0: lw          $v0, 0xC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XC);
L_80131FC4:
    // 0x80131FC4: b           L_80131FD4
    // 0x80131FC8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
        goto L_80131FD4;
    // 0x80131FC8: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80131FCC:
    // 0x80131FCC: b           L_80131FD4
    // 0x80131FD0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
        goto L_80131FD4;
    // 0x80131FD0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80131FD4:
    // 0x80131FD4: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80131FD8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80131FDC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80131FE0:
    // 0x80131FE0: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80131FE4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80131FE8: sb          $t5, 0x60($v1)
    MEM_B(0X60, ctx->r3) = ctx->r13;
    // 0x80131FEC: lbu         $t6, 0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X1);
    // 0x80131FF0: sb          $t6, 0x61($v1)
    MEM_B(0X61, ctx->r3) = ctx->r14;
    // 0x80131FF4: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x80131FF8: sb          $t7, 0x62($v1)
    MEM_B(0X62, ctx->r3) = ctx->r15;
    // 0x80131FFC: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x80132000: sb          $t8, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r24;
    // 0x80132004: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x80132008: sb          $t9, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r25;
    // 0x8013200C: lbu         $t0, 0x5($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X5);
    // 0x80132010: sb          $t0, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r8;
    // 0x80132014: bne         $a1, $a0, L_80131FE0
    if (ctx->r5 != ctx->r4) {
        // 0x80132018: lw          $v1, 0x8($v1)
        ctx->r3 = MEM_W(ctx->r3, 0X8);
            goto L_80131FE0;
    }
    // 0x80132018: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x8013201C: jr          $ra
    // 0x80132020: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80132020: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void efManagerDustHeavyMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF278: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FF27C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FF280: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800FF284: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800FF288: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FF28C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FF290: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FF294: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FF298: jal         0x80009968
    // 0x800FF29C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800FF29C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x800FF2A0: bne         $v0, $zero, L_800FF2B0
    if (ctx->r2 != 0) {
        // 0x800FF2A4: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800FF2B0;
    }
    // 0x800FF2A4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800FF2A8: b           L_800FF370
    // 0x800FF2AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF370;
    // 0x800FF2AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FF2B0:
    // 0x800FF2B0: sw          $zero, 0x84($a2)
    MEM_W(0X84, ctx->r6) = 0;
    // 0x800FF2B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FF2B8: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FF2BC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x800FF2C0: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x800FF2C4: jal         0x800CE9E8
    // 0x800FF2C8: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_1;
    // 0x800FF2C8: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_1:
    // 0x800FF2CC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800FF2D0: beq         $v0, $zero, L_800FF360
    if (ctx->r2 == 0) {
        // 0x800FF2D4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FF360;
    }
    // 0x800FF2D4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FF2D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FF2DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FF2E0: jal         0x800CE1DC
    // 0x800FF2E4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_2;
    // 0x800FF2E4: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x800FF2E8: beq         $v0, $zero, L_800FF34C
    if (ctx->r2 == 0) {
        // 0x800FF2EC: lw          $a2, 0x24($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X24);
            goto L_800FF34C;
    }
    // 0x800FF2EC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x800FF2F0: sw          $a2, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r6;
    // 0x800FF2F4: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800FF2F8: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x800FF2FC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FF300: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800FF304: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FF308: lui         $t0, 0x8010
    ctx->r8 = S32(0X8010 << 16);
    // 0x800FF30C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800FF310: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800FF314: addiu       $t0, $t0, -0x2478
    ctx->r8 = ADD32(ctx->r8, -0X2478);
    // 0x800FF318: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800FF31C: lwc1        $f4, 0x8($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800FF320: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800FF324: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800FF328: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
    // 0x800FF32C: swc1        $f8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f8.u32l;
    // 0x800FF330: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800FF334: bne         $t9, $at, L_800FF344
    if (ctx->r25 != ctx->r1) {
        // 0x800FF338: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800FF344;
    }
    // 0x800FF338: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF33C: lwc1        $f10, 0x988($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X988);
    // 0x800FF340: swc1        $f10, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f10.u32l;
L_800FF344:
    // 0x800FF344: b           L_800FF36C
    // 0x800FF348: sw          $t0, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r8;
        goto L_800FF36C;
    // 0x800FF348: sw          $t0, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r8;
L_800FF34C:
    // 0x800FF34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800FF350: jal         0x800FDB3C
    // 0x800FF354: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_3;
    // 0x800FF354: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x800FF358: b           L_800FF36C
    // 0x800FF35C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800FF36C;
    // 0x800FF35C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800FF360:
    // 0x800FF360: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FF364: jal         0x800FDB3C
    // 0x800FF368: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_4;
    // 0x800FF368: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_4:
L_800FF36C:
    // 0x800FF36C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800FF370:
    // 0x800FF370: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FF374: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FF378: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FF37C: jr          $ra
    // 0x800FF380: nop

    return;
    // 0x800FF380: nop

;}
RECOMP_FUNC void ftNessSpecialHiEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154518: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015451C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80154520: jal         0x8015450C
    // 0x80154524: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftNessSpecialHiClearProcDamage(rdram, ctx);
        goto after_0;
    // 0x80154524: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80154528: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015452C: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x80154530: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80154534: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80154538: jal         0x800E6F24
    // 0x8015453C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015453C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80154540: jal         0x800E0830
    // 0x80154544: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80154544: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80154548: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015454C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80154550: jr          $ra
    // 0x80154554: nop

    return;
    // 0x80154554: nop

;}
RECOMP_FUNC void ifCommonPlayerArrowsLeftProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111554: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80111558: lbu         $t6, 0x158E($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X158E);
    // 0x8011155C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80111560: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80111564: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80111568: beql        $t7, $zero, L_8011157C
    if (ctx->r15 == 0) {
        // 0x8011156C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8011157C;
    }
    goto skip_0;
    // 0x8011156C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80111570: jal         0x80014038
    // 0x80111574: nop

    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x80111574: nop

    after_0:
    // 0x80111578: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8011157C:
    // 0x8011157C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80111580: jr          $ra
    // 0x80111584: nop

    return;
    // 0x80111584: nop

;}
RECOMP_FUNC void efManagerNessPsychicMagnetMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801025D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801025DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801025E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801025E4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801025E8: jal         0x800FDB1C
    // 0x801025EC: addiu       $a0, $a0, -0x1BE4
    ctx->r4 = ADD32(ctx->r4, -0X1BE4);
    efManagerMakeEffectForce(rdram, ctx);
        goto after_0;
    // 0x801025EC: addiu       $a0, $a0, -0x1BE4
    ctx->r4 = ADD32(ctx->r4, -0X1BE4);
    after_0:
    // 0x801025F0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801025F4: bne         $v0, $zero, L_80102604
    if (ctx->r2 != 0) {
        // 0x801025F8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80102604;
    }
    // 0x801025F8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801025FC: b           L_80102620
    // 0x80102600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102620;
    // 0x80102600: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102604:
    // 0x80102604: lw          $a0, 0x84($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X84);
    // 0x80102608: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8010260C: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x80102610: lw          $t6, 0x84($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X84);
    // 0x80102614: lw          $a1, 0x74($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X74);
    // 0x80102618: lw          $t7, 0x8E8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8E8);
    // 0x8010261C: sw          $t7, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->r15;
L_80102620:
    // 0x80102620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102628: jr          $ra
    // 0x8010262C: nop

    return;
    // 0x8010262C: nop

;}
RECOMP_FUNC void mvOpeningYosterInitTotalTimeTics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132030: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132034: jr          $ra
    // 0x80132038: sw          $zero, 0x2438($at)
    MEM_W(0X2438, ctx->r1) = 0;
    return;
    // 0x80132038: sw          $zero, 0x2438($at)
    MEM_W(0X2438, ctx->r1) = 0;
;}
RECOMP_FUNC void syDebugSetFuncPrint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023004: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80023008: jr          $ra
    // 0x8002300C: sw          $a0, -0x1C28($at)
    MEM_W(-0X1C28, ctx->r1) = ctx->r4;
    return;
    // 0x8002300C: sw          $a0, -0x1C28($at)
    MEM_W(-0X1C28, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void itEggDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801818E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801818EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801818F0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801818F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801818F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801818FC: lbu         $t7, 0x2CF($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2CF);
    // 0x80181900: addiu       $a1, $a1, -0x4F5C
    ctx->r5 = ADD32(ctx->r5, -0X4F5C);
    // 0x80181904: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80181908: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x8018190C: sb          $t8, 0x2CF($v0)
    MEM_B(0X2CF, ctx->r2) = ctx->r24;
    // 0x80181910: jal         0x80172EC8
    // 0x80181914: sw          $t9, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r25;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80181914: sw          $t9, 0x248($v0)
    MEM_W(0X248, ctx->r2) = ctx->r25;
    after_0:
    // 0x80181918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018191C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181920: jr          $ra
    // 0x80181924: nop

    return;
    // 0x80181924: nop

;}
RECOMP_FUNC void itLGunWeaponAmmoProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175914: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175918: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017591C: jal         0x80167C04
    // 0x80175920: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x80175920: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80175924: beq         $v0, $zero, L_80175944
    if (ctx->r2 == 0) {
        // 0x80175928: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_80175944;
    }
    // 0x80175928: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8017592C: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x80175930: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80175934: jal         0x800FF648
    // 0x80175938: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80175938: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8017593C: b           L_80175948
    // 0x80175940: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80175948;
    // 0x80175940: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80175944:
    // 0x80175944: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80175948:
    // 0x80175948: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017594C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175950: jr          $ra
    // 0x80175954: nop

    return;
    // 0x80175954: nop

;}
RECOMP_FUNC void scAutoDemoInitDemo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D990: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018D994: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D998: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D99C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D9A0: addiu       $v1, $v1, -0x1D10
    ctx->r3 = ADD32(ctx->r3, -0X1D10);
    // 0x8018D9A4: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x8018D9A8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D9AC: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018D9B0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018D9B4: addiu       $s2, $s2, 0x50E8
    ctx->r18 = ADD32(ctx->r18, 0X50E8);
    // 0x8018D9B8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018D9BC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D9C0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D9C4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D9C8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018D9CC: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018D9D0: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8018D9D4:
    // 0x8018D9D4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D9D8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018D9DC: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018D9E0: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018D9E4: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018D9E8: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018D9EC: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018D9F0: bne         $t6, $t0, L_8018D9D4
    if (ctx->r14 != ctx->r8) {
        // 0x8018D9F4: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018D9D4;
    }
    // 0x8018D9F4: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018D9F8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D9FC: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x8018DA00: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018DA04: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DA08: lbu         $t2, 0x40($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X40);
    // 0x8018DA0C: lbu         $t5, 0x40($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X40);
    // 0x8018DA10: sw          $v1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r3;
    // 0x8018DA14: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x8018DA18: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x8018DA1C: addiu       $t0, $t5, 0x1
    ctx->r8 = ADD32(ctx->r13, 0X1);
    // 0x8018DA20: lbu         $t3, -0x1E98($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X1E98);
    // 0x8018DA24: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x8018DA28: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x8018DA2C: sb          $t0, 0x40($v0)
    MEM_B(0X40, ctx->r2) = ctx->r8;
    // 0x8018DA30: bne         $at, $zero, L_8018DA3C
    if (ctx->r1 != 0) {
        // 0x8018DA34: sb          $t3, 0x1($v1)
        MEM_B(0X1, ctx->r3) = ctx->r11;
            goto L_8018DA3C;
    }
    // 0x8018DA34: sb          $t3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r11;
    // 0x8018DA38: sb          $zero, 0x40($v0)
    MEM_B(0X40, ctx->r2) = 0;
L_8018DA3C:
    // 0x8018DA3C: lbu         $t9, 0xE($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XE);
    // 0x8018DA40: lbu         $t1, 0xD($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0XD);
    // 0x8018DA44: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DA48: sllv        $t8, $t7, $t9
    ctx->r24 = S32(ctx->r15 << (ctx->r25 & 31));
    // 0x8018DA4C: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x8018DA50: or          $t4, $t8, $t3
    ctx->r12 = ctx->r24 | ctx->r11;
    // 0x8018DA54: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DA58: sh          $t4, -0x1B1C($at)
    MEM_H(-0X1B1C, ctx->r1) = ctx->r12;
    // 0x8018DA5C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018DA60: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018DA64: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
    // 0x8018DA68: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8018DA6C:
    // 0x8018DA6C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8018DA70: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018DA74: addu        $t0, $t5, $s0
    ctx->r8 = ADD32(ctx->r13, ctx->r16);
    // 0x8018DA78: jal         0x8018D8C0
    // 0x8018DA7C: sb          $s3, 0x22($t0)
    MEM_B(0X22, ctx->r8) = ctx->r19;
    scAutoDemoGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x8018DA7C: sb          $s3, 0x22($t0)
    MEM_B(0X22, ctx->r8) = ctx->r19;
    after_0:
    // 0x8018DA80: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8018DA84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018DA88: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x8018DA8C: sb          $v0, 0x23($t7)
    MEM_B(0X23, ctx->r15) = ctx->r2;
    // 0x8018DA90: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x8018DA94: addu        $t2, $t9, $s0
    ctx->r10 = ADD32(ctx->r25, ctx->r16);
    // 0x8018DA98: jal         0x8018D954
    // 0x8018DA9C: sb          $s4, 0x20($t2)
    MEM_B(0X20, ctx->r10) = ctx->r20;
    scAutoDemoGetPlayerDamage(rdram, ctx);
        goto after_1;
    // 0x8018DA9C: sb          $s4, 0x20($t2)
    MEM_B(0X20, ctx->r10) = ctx->r20;
    after_1:
    // 0x8018DAA0: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8018DAA4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018DAA8: slti        $at, $s1, 0x4
    ctx->r1 = SIGNED(ctx->r17) < 0X4 ? 1 : 0;
    // 0x8018DAAC: addu        $t8, $t1, $s0
    ctx->r24 = ADD32(ctx->r9, ctx->r16);
    // 0x8018DAB0: addiu       $s0, $s0, 0x74
    ctx->r16 = ADD32(ctx->r16, 0X74);
    // 0x8018DAB4: bne         $at, $zero, L_8018DA6C
    if (ctx->r1 != 0) {
        // 0x8018DAB8: sw          $v0, 0x6C($t8)
        MEM_W(0X6C, ctx->r24) = ctx->r2;
            goto L_8018DA6C;
    }
    // 0x8018DAB8: sw          $v0, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->r2;
    // 0x8018DABC: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x8018DAC0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8018DAC4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DAC8: sb          $zero, 0x4($t3)
    MEM_B(0X4, ctx->r11) = 0;
    // 0x8018DACC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8018DAD0: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018DAD4: addiu       $v1, $v1, -0x1B00
    ctx->r3 = ADD32(ctx->r3, -0X1B00);
    // 0x8018DAD8: addiu       $v0, $v0, -0x1B10
    ctx->r2 = ADD32(ctx->r2, -0X1B10);
    // 0x8018DADC: sb          $t4, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r12;
L_8018DAE0:
    // 0x8018DAE0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8018DAE4: sh          $zero, -0x6($v0)
    MEM_H(-0X6, ctx->r2) = 0;
    // 0x8018DAE8: sh          $zero, -0x4($v0)
    MEM_H(-0X4, ctx->r2) = 0;
    // 0x8018DAEC: sh          $zero, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = 0;
    // 0x8018DAF0: bne         $v0, $v1, L_8018DAE0
    if (ctx->r2 != ctx->r3) {
        // 0x8018DAF4: sh          $zero, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = 0;
            goto L_8018DAE0;
    }
    // 0x8018DAF4: sh          $zero, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = 0;
    // 0x8018DAF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018DAFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018DB00: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DB04: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018DB08: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018DB0C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018DB10: jr          $ra
    // 0x8018DB14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018DB14: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl8_8037C358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C35C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C360: lw          $a3, 0x4($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X4);
    // 0x8037C364: bnel        $a3, $zero, L_8037C378
    if (ctx->r7 != 0) {
        // 0x8037C368: lw          $v1, 0x4C($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X4C);
            goto L_8037C378;
    }
    goto skip_0;
    // 0x8037C368: lw          $v1, 0x4C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4C);
    skip_0:
    // 0x8037C36C: b           L_8037C39C
    // 0x8037C370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037C39C;
    // 0x8037C370: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037C374: lw          $v1, 0x4C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4C);
L_8037C378:
    // 0x8037C378: bnel        $v1, $zero, L_8037C38C
    if (ctx->r3 != 0) {
        // 0x8037C37C: lw          $v0, 0x18($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X18);
            goto L_8037C38C;
    }
    goto skip_1;
    // 0x8037C37C: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
    skip_1:
    // 0x8037C380: b           L_8037C39C
    // 0x8037C384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037C39C;
    // 0x8037C384: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037C388: lw          $v0, 0x18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X18);
L_8037C38C:
    // 0x8037C38C: lw          $t9, 0x94($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X94);
    // 0x8037C390: lh          $t6, 0x90($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X90);
    // 0x8037C394: jalr        $t9
    // 0x8037C398: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037C398: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
L_8037C39C:
    // 0x8037C39C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037C3A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037C3A4: jr          $ra
    // 0x8037C3A8: nop

    return;
    // 0x8037C3A8: nop

;}
RECOMP_FUNC void ftCommonDamageInitDamageVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140EE4: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80140EE8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80140EEC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80140EF0: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x80140EF4: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80140EF8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x80140EFC: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x80140F00: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80140F04: lw          $a0, 0x90($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X90);
    // 0x80140F08: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x80140F0C: jal         0x801409BC
    // 0x80140F10: lw          $a1, 0x14C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14C);
    ftCommonDamageGetKnockbackAngle(rdram, ctx);
        goto after_0;
    // 0x80140F10: lw          $a1, 0x14C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X14C);
    after_0:
    // 0x80140F14: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80140F18: jal         0x80035CD0
    // 0x80140F1C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x80140F1C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80140F20: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80140F24: lwc1        $f12, 0x74($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80140F28: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80140F2C: jal         0x800303F0
    // 0x80140F30: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80140F30: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x80140F34: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80140F38: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80140F3C: jal         0x800EA1B0
    // 0x80140F40: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    ftParamGetHitStun(rdram, ctx);
        goto after_3;
    // 0x80140F40: swc1        $f8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f8.u32l;
    after_3:
    // 0x80140F44: trunc.w.s   $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    ctx->f10.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x80140F48: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80140F4C: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x80140F50: nop

    // 0x80140F54: bne         $v0, $zero, L_80140F64
    if (ctx->r2 != 0) {
        // 0x80140F58: sw          $v0, 0xB18($s0)
        MEM_W(0XB18, ctx->r16) = ctx->r2;
            goto L_80140F64;
    }
    // 0x80140F58: sw          $v0, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r2;
    // 0x80140F5C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80140F60: sw          $t8, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r24;
L_80140F64:
    // 0x80140F64: jal         0x80140A94
    // 0x80140F68: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    ftCommonDamageGetDamageLevel(rdram, ctx);
        goto after_4;
    // 0x80140F68: swc1        $f12, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f12.u32l;
    after_4:
    // 0x80140F6C: lw          $t9, 0x84($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X84);
    // 0x80140F70: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80140F74: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80140F78: beq         $t9, $at, L_80140F84
    if (ctx->r25 == ctx->r1) {
        // 0x80140F7C: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_80140F84;
    }
    // 0x80140F7C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80140F80: sw          $t0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r8;
L_80140F84:
    // 0x80140F84: lw          $t2, 0x14C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14C);
    // 0x80140F88: lw          $t1, 0x94($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X94);
    // 0x80140F8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80140F90: bne         $t2, $at, L_80140FFC
    if (ctx->r10 != ctx->r1) {
        // 0x80140F94: sw          $t1, 0x44($s0)
        MEM_W(0X44, ctx->r16) = ctx->r9;
            goto L_80140FFC;
    }
    // 0x80140F94: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
    // 0x80140F98: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80140F9C: lw          $t5, 0x98($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X98);
    // 0x80140FA0: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80140FA4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80140FA8: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80140FAC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80140FB0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80140FB4: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80140FB8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80140FBC: lw          $t8, -0x7A30($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7A30);
    // 0x80140FC0: lwc1        $f16, 0x70($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80140FC4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80140FC8: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80140FCC: sw          $t8, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r24;
    // 0x80140FD0: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x80140FD4: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x80140FD8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80140FDC: nop

    // 0x80140FE0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80140FE4: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80140FE8: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x80140FEC: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80140FF0: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x80140FF4: b           L_80141214
    // 0x80140FF8: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
        goto L_80141214;
    // 0x80140FF8: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
L_80140FFC:
    // 0x80140FFC: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80141000: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80141004: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80141008: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x8014100C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80141010: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80141014: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80141018: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x8014101C: addiu       $a0, $s0, 0xF8
    ctx->r4 = ADD32(ctx->r16, 0XF8);
    // 0x80141020: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80141024: swc1        $f6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f6.u32l;
    // 0x80141028: swc1        $f8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f8.u32l;
    // 0x8014102C: mul.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80141030: jal         0x800191FC
    // 0x80141034: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_5;
    // 0x80141034: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    after_5:
    // 0x80141038: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014103C: lwc1        $f10, -0x3EFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3EFC);
    // 0x80141040: lw          $t1, 0x5C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X5C);
    // 0x80141044: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80141048: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8014104C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    // 0x80141050: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80141054: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80141058: bc1f        L_801410B0
    if (!c1cs) {
        // 0x8014105C: sll         $t2, $t1, 2
        ctx->r10 = S32(ctx->r9 << 2);
            goto L_801410B0;
    }
    // 0x8014105C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80141060: lw          $t3, 0x98($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X98);
    // 0x80141064: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x80141068: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8014106C: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x80141070: addu        $t4, $t2, $t5
    ctx->r12 = ADD32(ctx->r10, ctx->r13);
    // 0x80141074: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80141078: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x8014107C: lw          $v0, -0x7A60($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X7A60);
    // 0x80141080: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80141084: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80141088: jal         0x800DEEC8
    // 0x8014108C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_6;
    // 0x8014108C: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    after_6:
    // 0x80141090: lwc1        $f16, 0x48($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80141094: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80141098: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014109C: swc1        $f16, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f16.u32l;
    // 0x801410A0: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x801410A4: swc1        $f18, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f18.u32l;
    // 0x801410A8: b           L_80141214
    // 0x801410AC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
        goto L_80141214;
    // 0x801410AC: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_801410B0:
    // 0x801410B0: bne         $t6, $at, L_801411B0
    if (ctx->r14 != ctx->r1) {
        // 0x801410B4: lw          $t4, 0x5C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X5C);
            goto L_801411B0;
    }
    // 0x801410B4: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x801410B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801410BC: jal         0x800DEEC8
    // 0x801410C0: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_7;
    // 0x801410C0: swc1        $f12, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f12.u32l;
    after_7:
    // 0x801410C4: lw          $t7, 0x5C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5C);
    // 0x801410C8: lw          $t9, 0x98($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X98);
    // 0x801410CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801410D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801410D4: lwc1        $f12, 0x44($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X44);
    // 0x801410D8: lwc1        $f6, -0x3EF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3EF8);
    // 0x801410DC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x801410E0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x801410E4: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x801410E8: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x801410EC: lui         $t3, 0x8019
    ctx->r11 = S32(0X8019 << 16);
    // 0x801410F0: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x801410F4: addu        $t3, $t3, $t1
    ctx->r11 = ADD32(ctx->r11, ctx->r9);
    // 0x801410F8: lw          $t3, -0x7A60($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X7A60);
    // 0x801410FC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80141100: sw          $t3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r11;
    // 0x80141104: bc1f        L_80141190
    if (!c1cs) {
        // 0x80141108: sw          $t3, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->r11;
            goto L_80141190;
    }
    // 0x80141108: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x8014110C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80141110: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80141114: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80141118: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x8014111C: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80141120: lwc1        $f4, -0x3EF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3EF4);
    // 0x80141124: swc1        $f6, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f6.u32l;
    // 0x80141128: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x8014112C: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x80141130: mul.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80141134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80141138: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8014113C: swc1        $f18, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f18.u32l;
    // 0x80141140: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80141144: lw          $t2, 0x44($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X44);
    // 0x80141148: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8014114C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80141150: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80141154: jal         0x800EABDC
    // 0x80141158: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    ftParamMakeEffect(rdram, ctx);
        goto after_8;
    // 0x80141158: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    after_8:
    // 0x8014115C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80141160: lw          $t5, 0x44($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X44);
    // 0x80141164: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80141168: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8014116C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80141170: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80141174: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80141178: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8014117C: jal         0x800EABDC
    // 0x80141180: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    ftParamMakeEffect(rdram, ctx);
        goto after_9;
    // 0x80141180: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_9:
    // 0x80141184: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80141188: b           L_80141218
    // 0x8014118C: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
        goto L_80141218;
    // 0x8014118C: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
L_80141190:
    // 0x80141190: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x80141194: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80141198: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8014119C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801411A0: swc1        $f10, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f10.u32l;
    // 0x801411A4: swc1        $f16, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f16.u32l;
    // 0x801411A8: b           L_80141218
    // 0x801411AC: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
        goto L_80141218;
    // 0x801411AC: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
L_801411B0:
    // 0x801411B0: lw          $t7, 0x98($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X98);
    // 0x801411B4: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x801411B8: subu        $t6, $t6, $t4
    ctx->r14 = SUB32(ctx->r14, ctx->r12);
    // 0x801411BC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801411C0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x801411C4: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x801411C8: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x801411CC: addu        $t0, $t0, $t8
    ctx->r8 = ADD32(ctx->r8, ctx->r24);
    // 0x801411D0: lw          $t0, -0x7A60($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7A60);
    // 0x801411D4: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x801411D8: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x801411DC: lw          $t1, 0x44($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X44);
    // 0x801411E0: lwc1        $f6, 0xFC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XFC);
    // 0x801411E4: lwc1        $f10, 0xF8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XF8);
    // 0x801411E8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x801411EC: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x801411F0: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801411F4: mul.s       $f0, $f2, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x801411F8: nop

    // 0x801411FC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80141200: swc1        $f0, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->f0.u32l;
    // 0x80141204: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80141208: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014120C: swc1        $f8, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->f8.u32l;
    // 0x80141210: swc1        $f4, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f4.u32l;
L_80141214:
    // 0x80141214: swc1        $f0, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->f0.u32l;
L_80141218:
    // 0x80141218: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8014121C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80141220: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80141224: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80141228: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014122C: bnel        $t3, $at, L_801412CC
    if (ctx->r11 != ctx->r1) {
        // 0x80141230: lw          $t8, 0x84($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X84);
            goto L_801412CC;
    }
    goto skip_0;
    // 0x80141230: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    skip_0:
    // 0x80141234: lw          $t2, 0x14C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14C);
    // 0x80141238: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014123C: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x80141240: bne         $t2, $at, L_801412C8
    if (ctx->r10 != ctx->r1) {
        // 0x80141244: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801412C8;
    }
    // 0x80141244: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80141248: lwc1        $f18, -0x3EF0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3EF0);
    // 0x8014124C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80141250: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x80141254: nop

    // 0x80141258: bc1fl       L_8014128C
    if (!c1cs) {
        // 0x8014125C: lw          $t7, 0x2C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X2C);
            goto L_8014128C;
    }
    goto skip_1;
    // 0x8014125C: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    skip_1:
    // 0x80141260: lwc1        $f6, -0x3EEC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3EEC);
    // 0x80141264: addiu       $t5, $zero, 0x36
    ctx->r13 = ADD32(0, 0X36);
    // 0x80141268: addiu       $t4, $zero, 0x36
    ctx->r12 = ADD32(0, 0X36);
    // 0x8014126C: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80141270: nop

    // 0x80141274: bc1fl       L_8014128C
    if (!c1cs) {
        // 0x80141278: lw          $t7, 0x2C($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X2C);
            goto L_8014128C;
    }
    goto skip_2;
    // 0x80141278: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    skip_2:
    // 0x8014127C: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
    // 0x80141280: b           L_801412C8
    // 0x80141284: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
        goto L_801412C8;
    // 0x80141284: sw          $t4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r12;
    // 0x80141288: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
L_8014128C:
    // 0x8014128C: slti        $at, $t7, 0x64
    ctx->r1 = SIGNED(ctx->r15) < 0X64 ? 1 : 0;
    // 0x80141290: bnel        $at, $zero, L_801412CC
    if (ctx->r1 != 0) {
        // 0x80141294: lw          $t8, 0x84($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X84);
            goto L_801412CC;
    }
    goto skip_3;
    // 0x80141294: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    skip_3:
    // 0x80141298: jal         0x80018948
    // 0x8014129C: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_10;
    // 0x8014129C: nop

    after_10:
    // 0x801412A0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801412A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801412A8: addiu       $t6, $zero, 0x37
    ctx->r14 = ADD32(0, 0X37);
    // 0x801412AC: addiu       $t9, $zero, 0x37
    ctx->r25 = ADD32(0, 0X37);
    // 0x801412B0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x801412B4: nop

    // 0x801412B8: bc1fl       L_801412CC
    if (!c1cs) {
        // 0x801412BC: lw          $t8, 0x84($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X84);
            goto L_801412CC;
    }
    goto skip_4;
    // 0x801412BC: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    skip_4:
    // 0x801412C0: sw          $t6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r14;
    // 0x801412C4: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
L_801412C8:
    // 0x801412C8: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
L_801412CC:
    // 0x801412CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801412D0: lwc1        $f2, 0x74($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801412D4: beql        $t8, $at, L_801412E4
    if (ctx->r24 == ctx->r1) {
        // 0x801412D8: lw          $t0, 0x9C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X9C);
            goto L_801412E4;
    }
    goto skip_5;
    // 0x801412D8: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    skip_5:
    // 0x801412DC: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x801412E0: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
L_801412E4:
    // 0x801412E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801412E8: bnel        $t0, $at, L_80141330
    if (ctx->r8 != ctx->r1) {
        // 0x801412EC: lw          $t4, 0xA0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA0);
            goto L_80141330;
    }
    goto skip_6;
    // 0x801412EC: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    skip_6:
    // 0x801412F0: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x801412F4: slti        $at, $t1, 0x25
    ctx->r1 = SIGNED(ctx->r9) < 0X25 ? 1 : 0;
    // 0x801412F8: bne         $at, $zero, L_8014132C
    if (ctx->r1 != 0) {
        // 0x801412FC: slti        $at, $t1, 0x39
        ctx->r1 = SIGNED(ctx->r9) < 0X39 ? 1 : 0;
            goto L_8014132C;
    }
    // 0x801412FC: slti        $at, $t1, 0x39
    ctx->r1 = SIGNED(ctx->r9) < 0X39 ? 1 : 0;
    // 0x80141300: beql        $at, $zero, L_80141330
    if (ctx->r1 == 0) {
        // 0x80141304: lw          $t4, 0xA0($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XA0);
            goto L_80141330;
    }
    goto skip_7;
    // 0x80141304: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
    skip_7:
    // 0x80141308: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x8014130C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80141310: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x80141314: bne         $t3, $at, L_80141328
    if (ctx->r11 != ctx->r1) {
        // 0x80141318: addiu       $t5, $zero, 0x31
        ctx->r13 = ADD32(0, 0X31);
            goto L_80141328;
    }
    // 0x80141318: addiu       $t5, $zero, 0x31
    ctx->r13 = ADD32(0, 0X31);
    // 0x8014131C: addiu       $t2, $zero, 0x32
    ctx->r10 = ADD32(0, 0X32);
    // 0x80141320: b           L_8014132C
    // 0x80141324: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
        goto L_8014132C;
    // 0x80141324: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
L_80141328:
    // 0x80141328: sw          $t5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r13;
L_8014132C:
    // 0x8014132C: lw          $t4, 0xA0($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA0);
L_80141330:
    // 0x80141330: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80141334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80141338: sw          $t4, 0x808($s0)
    MEM_W(0X808, ctx->r16) = ctx->r12;
    // 0x8014133C: jal         0x80140B00
    // 0x80141340: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    ftCommonDamageSetPublic(rdram, ctx);
        goto after_11;
    // 0x80141340: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    after_11:
    // 0x80141344: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x80141348: beql        $t7, $zero, L_80141364
    if (ctx->r15 == 0) {
        // 0x8014134C: lwc1        $f12, 0x8C($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
            goto L_80141364;
    }
    goto skip_8;
    // 0x8014134C: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
    skip_8:
    // 0x80141350: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80141354: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x80141358: jal         0x80140BCC
    // 0x8014135C: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    ftCommonDamageCheckElementSetColAnim(rdram, ctx);
        goto after_12;
    // 0x8014135C: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    after_12:
    // 0x80141360: lwc1        $f12, 0x8C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X8C);
L_80141364:
    // 0x80141364: jal         0x80140C50
    // 0x80141368: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    ftCommonDamageCheckMakeScreenFlash(rdram, ctx);
        goto after_13;
    // 0x80141368: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    after_13:
    // 0x8014136C: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80141370: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80141374: bnel        $t6, $at, L_80141394
    if (ctx->r14 != ctx->r1) {
        // 0x80141378: addiu       $t8, $zero, 0x1000
        ctx->r24 = ADD32(0, 0X1000);
            goto L_80141394;
    }
    goto skip_9;
    // 0x80141378: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    skip_9:
    // 0x8014137C: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80141380: beql        $t9, $zero, L_80141394
    if (ctx->r25 == 0) {
        // 0x80141384: addiu       $t8, $zero, 0x1000
        ctx->r24 = ADD32(0, 0X1000);
            goto L_80141394;
    }
    goto skip_10;
    // 0x80141384: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
    skip_10:
    // 0x80141388: jal         0x80163648
    // 0x8014138C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    ftKirbySpecialNDamageCheckLoseCopy(rdram, ctx);
        goto after_14;
    // 0x8014138C: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_14:
    // 0x80141390: addiu       $t8, $zero, 0x1000
    ctx->r24 = ADD32(0, 0X1000);
L_80141394:
    // 0x80141394: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80141398: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x8014139C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x801413A0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801413A4: jal         0x800E6F24
    // 0x801413A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_15;
    // 0x801413A8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_15:
    // 0x801413AC: jal         0x800E0830
    // 0x801413B0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_16;
    // 0x801413B0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_16:
    // 0x801413B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801413B8: lwc1        $f16, -0x3EE8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3EE8);
    // 0x801413BC: lwc1        $f10, 0x8C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801413C0: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801413C4: addiu       $t5, $t5, 0x878
    ctx->r13 = ADD32(ctx->r13, 0X878);
    // 0x801413C8: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x801413CC: addiu       $t7, $zero, 0xFE
    ctx->r15 = ADD32(0, 0XFE);
    // 0x801413D0: bc1f        L_801413E0
    if (!c1cs) {
        // 0x801413D4: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_801413E0;
    }
    // 0x801413D4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801413D8: b           L_801413E4
    // 0x801413DC: sw          $t0, 0xB48($s0)
    MEM_W(0XB48, ctx->r16) = ctx->r8;
        goto L_801413E4;
    // 0x801413DC: sw          $t0, 0xB48($s0)
    MEM_W(0XB48, ctx->r16) = ctx->r8;
L_801413E0:
    // 0x801413E0: sw          $zero, 0xB48($s0)
    MEM_W(0XB48, ctx->r16) = 0;
L_801413E4:
    // 0x801413E4: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x801413E8: addiu       $at, $zero, 0x31
    ctx->r1 = ADD32(0, 0X31);
    // 0x801413EC: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801413F0: beq         $v0, $at, L_80141404
    if (ctx->r2 == ctx->r1) {
        // 0x801413F4: addiu       $t1, $t1, 0x5E4
        ctx->r9 = ADD32(ctx->r9, 0X5E4);
            goto L_80141404;
    }
    // 0x801413F4: addiu       $t1, $t1, 0x5E4
    ctx->r9 = ADD32(ctx->r9, 0X5E4);
    // 0x801413F8: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x801413FC: bne         $v0, $at, L_80141414
    if (ctx->r2 != ctx->r1) {
        // 0x80141400: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80141414;
    }
    // 0x80141400: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
L_80141404:
    // 0x80141404: sw          $t1, 0x9FC($s0)
    MEM_W(0X9FC, ctx->r16) = ctx->r9;
    // 0x80141408: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x8014140C: b           L_8014141C
    // 0x80141410: sw          $t3, 0xB44($s0)
    MEM_W(0XB44, ctx->r16) = ctx->r11;
        goto L_8014141C;
    // 0x80141410: sw          $t3, 0xB44($s0)
    MEM_W(0XB44, ctx->r16) = ctx->r11;
L_80141414:
    // 0x80141414: addiu       $t2, $t2, 0x5A0
    ctx->r10 = ADD32(ctx->r10, 0X5A0);
    // 0x80141418: sw          $t2, 0x9FC($s0)
    MEM_W(0X9FC, ctx->r16) = ctx->r10;
L_8014141C:
    // 0x8014141C: sw          $t5, 0xA00($s0)
    MEM_W(0XA00, ctx->r16) = ctx->r13;
    // 0x80141420: sb          $t7, 0x269($s0)
    MEM_B(0X269, ctx->r16) = ctx->r15;
    // 0x80141424: sb          $t7, 0x268($s0)
    MEM_B(0X268, ctx->r16) = ctx->r15;
    // 0x80141428: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8014142C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80141430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80141434: swc1        $f4, 0x7EC($s0)
    MEM_W(0X7EC, ctx->r16) = ctx->f4.u32l;
    // 0x80141438: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x8014143C: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x80141440: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80141444: beq         $t6, $at, L_80141454
    if (ctx->r14 == ctx->r1) {
        // 0x80141448: nop
    
            goto L_80141454;
    }
    // 0x80141448: nop

    // 0x8014144C: beql        $t9, $zero, L_80141460
    if (ctx->r25 == 0) {
        // 0x80141450: lw          $t8, 0x24($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X24);
            goto L_80141460;
    }
    goto skip_11;
    // 0x80141450: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    skip_11:
L_80141454:
    // 0x80141454: jal         0x800E806C
    // 0x80141458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_17;
    // 0x80141458: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_17:
    // 0x8014145C: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
L_80141460:
    // 0x80141460: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80141464: bne         $t8, $at, L_80141474
    if (ctx->r24 != ctx->r1) {
        // 0x80141468: nop
    
            goto L_80141474;
    }
    // 0x80141468: nop

    // 0x8014146C: jal         0x80140744
    // 0x80141470: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    ftCommonDamageFlyRollUpdateModelPitch(rdram, ctx);
        goto after_18;
    // 0x80141470: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    after_18:
L_80141474:
    // 0x80141474: jal         0x80140340
    // 0x80141478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageSetDustEffectInterval(rdram, ctx);
        goto after_19;
    // 0x80141478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8014147C: lw          $t0, 0xB1C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XB1C);
    // 0x80141480: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80141484: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80141488: beq         $t0, $zero, L_80141494
    if (ctx->r8 == 0) {
        // 0x8014148C: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80141494;
    }
    // 0x8014148C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80141490: sw          $t1, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r9;
L_80141494:
    // 0x80141494: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80141498: lw          $t2, 0xA8($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XA8);
    // 0x8014149C: c.le.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl <= ctx->f18.fl;
    // 0x801414A0: nop

    // 0x801414A4: bc1f        L_801414C0
    if (!c1cs) {
        // 0x801414A8: nop
    
            goto L_801414C0;
    }
    // 0x801414A8: nop

    // 0x801414AC: lw          $t3, 0x9C8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X9C8);
    // 0x801414B0: addiu       $at, $zero, 0x2B7
    ctx->r1 = ADD32(0, 0X2B7);
    // 0x801414B4: lhu         $a0, 0xBA($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0XBA);
    // 0x801414B8: bne         $a0, $at, L_801414D0
    if (ctx->r4 != ctx->r1) {
        // 0x801414BC: nop
    
            goto L_801414D0;
    }
    // 0x801414BC: nop

L_801414C0:
    // 0x801414C0: beql        $t2, $zero, L_801414DC
    if (ctx->r10 == 0) {
        // 0x801414C4: lbu         $t7, 0x18F($s0)
        ctx->r15 = MEM_BU(ctx->r16, 0X18F);
            goto L_801414DC;
    }
    goto skip_12;
    // 0x801414C4: lbu         $t7, 0x18F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18F);
    skip_12:
    // 0x801414C8: lw          $t5, 0x9C8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X9C8);
    // 0x801414CC: lhu         $a0, 0xBA($t5)
    ctx->r4 = MEM_HU(ctx->r13, 0XBA);
L_801414D0:
    // 0x801414D0: jal         0x800269C0
    // 0x801414D4: nop

    func_800269C0_275C0(rdram, ctx);
        goto after_20;
    // 0x801414D4: nop

    after_20:
    // 0x801414D8: lbu         $t7, 0x18F($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X18F);
L_801414DC:
    // 0x801414DC: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x801414E0: sw          $t9, 0x160($s0)
    MEM_W(0X160, ctx->r16) = ctx->r25;
    // 0x801414E4: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x801414E8: sb          $t6, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r14;
    // 0x801414EC: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x801414F0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801414F4: lwc1        $f8, 0x8C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801414F8: bne         $t8, $at, L_80141520
    if (ctx->r24 != ctx->r1) {
        // 0x801414FC: lui         $at, 0x4302
        ctx->r1 = S32(0X4302 << 16);
            goto L_80141520;
    }
    // 0x801414FC: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80141500: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80141504: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x80141508: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8014150C: nop

    // 0x80141510: bc1fl       L_80141524
    if (!c1cs) {
        // 0x80141514: sh          $zero, 0xB24($s0)
        MEM_H(0XB24, ctx->r16) = 0;
            goto L_80141524;
    }
    goto skip_13;
    // 0x80141514: sh          $zero, 0xB24($s0)
    MEM_H(0XB24, ctx->r16) = 0;
    skip_13:
    // 0x80141518: jal         0x800E7F7C
    // 0x8014151C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_21;
    // 0x8014151C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_21:
L_80141520:
    // 0x80141520: sh          $zero, 0xB24($s0)
    MEM_H(0XB24, ctx->r16) = 0;
L_80141524:
    // 0x80141524: jal         0x800E7ED4
    // 0x80141528: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    ftParamGetPlayerNumGObj(rdram, ctx);
        goto after_22;
    // 0x80141528: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    after_22:
    // 0x8014152C: beql        $v0, $zero, L_80141550
    if (ctx->r2 == 0) {
        // 0x80141530: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80141550;
    }
    goto skip_14;
    // 0x80141530: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_14:
    // 0x80141534: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80141538: lhu         $t0, 0x7B8($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X7B8);
    // 0x8014153C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80141540: sh          $t1, 0x7B8($v1)
    MEM_H(0X7B8, ctx->r3) = ctx->r9;
    // 0x80141544: lwc1        $f16, 0x8C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80141548: swc1        $f16, 0x7B4($v1)
    MEM_W(0X7B4, ctx->r3) = ctx->f16.u32l;
    // 0x8014154C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80141550:
    // 0x80141550: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80141554: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80141558: jr          $ra
    // 0x8014155C: nop

    return;
    // 0x8014155C: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157268: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015726C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80157270: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80157274: jal         0x80156EFC
    // 0x80157278: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftKirbyCopySamusSpecialNSetChargeShotPosition(rdram, ctx);
        goto after_0;
    // 0x80157278: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015727C: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80157280: addiu       $a1, $a1, 0x7610
    ctx->r5 = ADD32(ctx->r5, 0X7610);
    // 0x80157284: jal         0x800DDE84
    // 0x80157288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_1;
    // 0x80157288: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015728C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80157290: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80157294: jr          $ra
    // 0x80157298: nop

    return;
    // 0x80157298: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateComboDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E424: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E428: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018E42C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018E430: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018E434: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018E438: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018E43C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018E440: addiu       $t0, $t0, 0xB58
    ctx->r8 = ADD32(ctx->r8, 0XB58);
    // 0x8018E444: addiu       $t1, $t1, 0x7EC
    ctx->r9 = ADD32(ctx->r9, 0X7EC);
    // 0x8018E448: addiu       $a3, $a3, 0x7E8
    ctx->r7 = ADD32(ctx->r7, 0X7E8);
    // 0x8018E44C: addiu       $a2, $a2, 0x7EC
    ctx->r6 = ADD32(ctx->r6, 0X7EC);
    // 0x8018E450: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8018E454:
    // 0x8018E454: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x8018E458: lw          $t7, 0x28($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X28);
    // 0x8018E45C: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x8018E460: div         $zero, $a1, $a0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r4)));
    // 0x8018E464: mflo        $v1
    ctx->r3 = lo;
    // 0x8018E468: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8018E46C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8018E470: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018E474: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8018E478: bne         $a0, $zero, L_8018E484
    if (ctx->r4 != 0) {
        // 0x8018E47C: nop
    
            goto L_8018E484;
    }
    // 0x8018E47C: nop

    // 0x8018E480: break       7
    do_break(2149115008);
L_8018E484:
    // 0x8018E484: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018E488: bne         $a0, $at, L_8018E49C
    if (ctx->r4 != ctx->r1) {
        // 0x8018E48C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018E49C;
    }
    // 0x8018E48C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018E490: bne         $a1, $at, L_8018E49C
    if (ctx->r5 != ctx->r1) {
        // 0x8018E494: nop
    
            goto L_8018E49C;
    }
    // 0x8018E494: nop

    // 0x8018E498: break       6
    do_break(2149115032);
L_8018E49C:
    // 0x8018E49C: mflo        $t6
    ctx->r14 = lo;
    // 0x8018E4A0: subu        $a1, $a1, $t6
    ctx->r5 = SUB32(ctx->r5, ctx->r14);
    // 0x8018E4A4: addiu       $t6, $t2, 0x3C
    ctx->r14 = ADD32(ctx->r10, 0X3C);
L_8018E4A8:
    // 0x8018E4A8: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8018E4AC: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8018E4B0: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8018E4B4: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8018E4B8: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x8018E4BC: sw          $t3, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r11;
    // 0x8018E4C0: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x8018E4C4: bne         $t2, $t6, L_8018E4A8
    if (ctx->r10 != ctx->r14) {
        // 0x8018E4C8: sw          $t4, 0xC($t5)
        MEM_W(0XC, ctx->r13) = ctx->r12;
            goto L_8018E4A8;
    }
    // 0x8018E4C8: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x8018E4CC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8018E4D0: sw          $t4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r12;
    // 0x8018E4D4: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8018E4D8: sw          $t3, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r11;
    // 0x8018E4DC: lhu         $t7, 0x0($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X0);
    // 0x8018E4E0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8018E4E4: bgez        $t7, L_8018E4FC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8018E4E8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018E4FC;
    }
    // 0x8018E4E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E4EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E4F0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E4F4: nop

    // 0x8018E4F8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8018E4FC:
    // 0x8018E4FC: lh          $t8, 0x14($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X14);
    // 0x8018E500: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8018E504: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8018E508: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8018E50C: nop

    // 0x8018E510: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018E514: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8018E518: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8018E51C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018E520: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8018E524: nop

    // 0x8018E528: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018E52C: nop

    // 0x8018E530: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018E534: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x8018E538: bne         $a3, $t1, L_8018E454
    if (ctx->r7 != ctx->r9) {
        // 0x8018E53C: lw          $v0, 0x8($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X8);
            goto L_8018E454;
    }
    // 0x8018E53C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8018E540: jr          $ra
    // 0x8018E544: nop

    return;
    // 0x8018E544: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeCPDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E870: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018E874: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018E878: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018E87C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E880: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8018E884: jal         0x80009968
    // 0x8018E888: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018E888: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018E88C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E890: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018E894: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018E898: sw          $v0, 0xB9C($at)
    MEM_W(0XB9C, ctx->r1) = ctx->r2;
    // 0x8018E89C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8018E8A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018E8A4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018E8A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E8AC: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018E8B0: jal         0x80009DF4
    // 0x8018E8B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018E8B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018E8B8: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E8BC: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018E8C0: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x8018E8C4: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x8018E8C8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018E8CC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018E8D0: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018E8D4: jal         0x800CCFDC
    // 0x8018E8D8: lw          $a1, 0x7C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X7C);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018E8D8: lw          $a1, 0x7C($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X7C);
    after_2:
    // 0x8018E8DC: lui         $at, 0x433F
    ctx->r1 = S32(0X433F << 16);
    // 0x8018E8E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E8E4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018E8E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018E8EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E8F0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8018E8F4: jal         0x8018E300
    // 0x8018E8F8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    sc1PTrainingModeInitSpriteEnvColors(rdram, ctx);
        goto after_3;
    // 0x8018E8F8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x8018E8FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E900: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8018E904: jr          $ra
    // 0x8018E908: nop

    return;
    // 0x8018E908: nop

;}
RECOMP_FUNC void itTaruExplodeSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A2D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017A2DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A2E0: jal         0x8017A240
    // 0x8017A2E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itTaruExplodeInitVars(rdram, ctx);
        goto after_0;
    // 0x8017A2E4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017A2E8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017A2EC: addiu       $a1, $a1, -0x5B7C
    ctx->r5 = ADD32(ctx->r5, -0X5B7C);
    // 0x8017A2F0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017A2F4: jal         0x80172EC8
    // 0x8017A2F8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017A2F8: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_1:
    // 0x8017A2FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A300: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017A304: jr          $ra
    // 0x8017A308: nop

    return;
    // 0x8017A308: nop

;}
RECOMP_FUNC void ftNessSpecialLwStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801552A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801552A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801552A8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801552AC: jal         0x800D9480
    // 0x801552B0: addiu       $a1, $a1, 0x5750
    ctx->r5 = ADD32(ctx->r5, 0X5750);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801552B0: addiu       $a1, $a1, 0x5750
    ctx->r5 = ADD32(ctx->r5, 0X5750);
    after_0:
    // 0x801552B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801552B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801552BC: jr          $ra
    // 0x801552C0: nop

    return;
    // 0x801552C0: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingAnnounceFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801341B0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801341B4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801341B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801341BC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x801341C0: addiu       $t7, $t7, -0x7CF0
    ctx->r15 = ADD32(ctx->r15, -0X7CF0);
    // 0x801341C4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801341C8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801341CC: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x801341D0: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801341D4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801341D8: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801341DC: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801341E0: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x801341E4: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x801341E8: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801341EC: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801341F0: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x801341F4: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x801341F8: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x801341FC: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80134200: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80134204: addiu       $t1, $t1, -0x7AA8
    ctx->r9 = ADD32(ctx->r9, -0X7AA8);
    // 0x80134208: sll         $t0, $t0, 3
    ctx->r8 = S32(ctx->r8 << 3);
    // 0x8013420C: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
    // 0x80134210: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80134214: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x80134218: lw          $a2, 0xA4($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XA4);
    // 0x8013421C: beql        $a2, $zero, L_80134250
    if (ctx->r6 == 0) {
        // 0x80134220: addiu       $a0, $zero, 0x79
        ctx->r4 = ADD32(0, 0X79);
            goto L_80134250;
    }
    goto skip_0;
    // 0x80134220: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    skip_0:
    // 0x80134224: lhu         $v0, 0x26($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X26);
    // 0x80134228: beql        $v0, $zero, L_80134250
    if (ctx->r2 == 0) {
        // 0x8013422C: addiu       $a0, $zero, 0x79
        ctx->r4 = ADD32(0, 0X79);
            goto L_80134250;
    }
    goto skip_1;
    // 0x8013422C: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    skip_1:
    // 0x80134230: lhu         $t2, 0xA8($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0XA8);
    // 0x80134234: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80134238: bnel        $v0, $t2, L_80134250
    if (ctx->r2 != ctx->r10) {
        // 0x8013423C: addiu       $a0, $zero, 0x79
        ctx->r4 = ADD32(0, 0X79);
            goto L_80134250;
    }
    goto skip_2;
    // 0x8013423C: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
    skip_2:
    // 0x80134240: jal         0x80026738
    // 0x80134244: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x80134244: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x80134248: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8013424C: addiu       $a0, $zero, 0x79
    ctx->r4 = ADD32(0, 0X79);
L_80134250:
    // 0x80134250: jal         0x800269C0
    // 0x80134254: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80134254: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_1:
    // 0x80134258: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x8013425C: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80134260: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80134264: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80134268: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x8013426C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80134270: sll         $t4, $t4, 3
    ctx->r12 = S32(ctx->r12 << 3);
    // 0x80134274: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80134278: lw          $t5, -0x7A60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X7A60);
    // 0x8013427C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x80134280: addu        $a0, $sp, $t6
    ctx->r4 = ADD32(ctx->r29, ctx->r14);
    // 0x80134284: jal         0x800269C0
    // 0x80134288: lhu         $a0, 0x28($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X28);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80134288: lhu         $a0, 0x28($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X28);
    after_2:
    // 0x8013428C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80134290: beq         $v0, $zero, L_801342A0
    if (ctx->r2 == 0) {
        // 0x80134294: sw          $v0, 0xA4($v1)
        MEM_W(0XA4, ctx->r3) = ctx->r2;
            goto L_801342A0;
    }
    // 0x80134294: sw          $v0, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r2;
    // 0x80134298: lhu         $t8, 0x26($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X26);
    // 0x8013429C: sh          $t8, 0xA8($v1)
    MEM_H(0XA8, ctx->r3) = ctx->r24;
L_801342A0:
    // 0x801342A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801342A4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801342A8: jr          $ra
    // 0x801342AC: nop

    return;
    // 0x801342AC: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNCatchSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F4F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015F4F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F4F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015F4FC: jal         0x800DEEC8
    // 0x8015F500: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015F500: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015F504: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015F508: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x8015F50C: addiu       $a1, $zero, 0x12D
    ctx->r5 = ADD32(0, 0X12D);
    // 0x8015F510: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015F514: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015F518: jal         0x800E6F24
    // 0x8015F51C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015F51C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015F520: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F524: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015F528: jr          $ra
    // 0x8015F52C: nop

    return;
    // 0x8015F52C: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirNEndSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B4AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015B4B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B4B4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015B4B8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015B4BC: jal         0x800DEE98
    // 0x8015B4C0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015B4C0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015B4C4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8015B4C8: addiu       $at, $zero, 0xE3
    ctx->r1 = ADD32(0, 0XE3);
    // 0x8015B4CC: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8015B4D0: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8015B4D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015B4D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015B4DC: bne         $t7, $at, L_8015B4EC
    if (ctx->r15 != ctx->r1) {
        // 0x8015B4E0: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_8015B4EC;
    }
    // 0x8015B4E0: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8015B4E4: b           L_8015B4EC
    // 0x8015B4E8: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
        goto L_8015B4EC;
    // 0x8015B4E8: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
L_8015B4EC:
    // 0x8015B4EC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015B4F0: jal         0x800E6F24
    // 0x8015B4F4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015B4F4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8015B4F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B4FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015B500: jr          $ra
    // 0x8015B504: nop

    return;
    // 0x8015B504: nop

;}
RECOMP_FUNC void itTaruBombRollProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185030: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80185034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185038: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8018503C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80185040: lwc1        $f12, 0xBC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XBC);
    // 0x80185044: lwc1        $f14, 0xB8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XB8);
    // 0x80185048: jal         0x8001863C
    // 0x8018504C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8018504C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80185050: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80185054: lwc1        $f4, -0x30B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X30B0);
    // 0x80185058: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018505C: lwc1        $f10, -0x30AC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X30AC);
    // 0x80185060: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80185064: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80185068: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8018506C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80185070: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80185074: lwc1        $f18, 0x2C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80185078: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8018507C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80185080: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80185084: swc1        $f4, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f4.u32l;
    // 0x80185088: lwc1        $f6, 0x2C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8018508C: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80185090: nop

    // 0x80185094: bc1fl       L_801850A8
    if (!c1cs) {
        // 0x80185098: sw          $t8, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r24;
            goto L_801850A8;
    }
    goto skip_0;
    // 0x80185098: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    skip_0:
    // 0x8018509C: b           L_801850A8
    // 0x801850A0: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
        goto L_801850A8;
    // 0x801850A0: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
    // 0x801850A4: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_801850A8:
    // 0x801850A8: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x801850AC: lwc1        $f2, 0x30($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X30);
    // 0x801850B0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801850B4: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x801850B8: nop

    // 0x801850BC: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x801850C0: jal         0x80033510
    // 0x801850C4: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x801850C4: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_1:
    // 0x801850C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801850CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801850D0: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x801850D4: bne         $t9, $at, L_801850E4
    if (ctx->r25 != ctx->r1) {
        // 0x801850D8: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801850E4;
    }
    // 0x801850D8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801850DC: b           L_801850EC
    // 0x801850E0: lwc1        $f12, -0x30A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X30A8);
        goto L_801850EC;
    // 0x801850E0: lwc1        $f12, -0x30A8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X30A8);
L_801850E4:
    // 0x801850E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801850E8: lwc1        $f12, -0x30A4($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X30A4);
L_801850EC:
    // 0x801850EC: mul.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x801850F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801850F4: swc1        $f2, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->f2.u32l;
    // 0x801850F8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x801850FC: lw          $a0, 0x74($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X74);
    // 0x80185100: lwc1        $f16, 0x38($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X38);
    // 0x80185104: add.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x80185108: swc1        $f4, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f4.u32l;
    // 0x8018510C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80185114: jr          $ra
    // 0x80185118: nop

    return;
    // 0x80185118: nop

;}
RECOMP_FUNC void gcGetDObjDescAxisTrack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E0F4: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x8000E0F8: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x8000E0FC: beq         $at, $zero, L_8000E15C
    if (ctx->r1 == 0) {
        // 0x8000E100: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8000E15C;
    }
    // 0x8000E100: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000E104: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000E108: addu        $at, $at, $t6
    gpr jr_addend_8000E110 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000E10C: lw          $t6, -0x20B0($at)
    ctx->r14 = ADD32(ctx->r1, -0X20B0);
    // 0x8000E110: jr          $t6
    // 0x8000E114: nop

    switch (jr_addend_8000E110 >> 2) {
        case 0: goto L_8000E118; break;
        case 1: goto L_8000E120; break;
        case 2: goto L_8000E128; break;
        case 3: goto L_8000E15C; break;
        case 4: goto L_8000E130; break;
        case 5: goto L_8000E138; break;
        case 6: goto L_8000E140; break;
        case 7: goto L_8000E148; break;
        case 8: goto L_8000E150; break;
        case 9: goto L_8000E158; break;
        default: switch_error(__func__, 0x8000E110, 0x8003DF50);
    }
    // 0x8000E114: nop

L_8000E118:
    // 0x8000E118: jr          $ra
    // 0x8000E11C: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
    return;
    // 0x8000E11C: lwc1        $f0, 0x14($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X14);
L_8000E120:
    // 0x8000E120: jr          $ra
    // 0x8000E124: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
    return;
    // 0x8000E124: lwc1        $f0, 0x18($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X18);
L_8000E128:
    // 0x8000E128: jr          $ra
    // 0x8000E12C: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
    return;
    // 0x8000E12C: lwc1        $f0, 0x1C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X1C);
L_8000E130:
    // 0x8000E130: jr          $ra
    // 0x8000E134: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
    return;
    // 0x8000E134: lwc1        $f0, 0x8($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X8);
L_8000E138:
    // 0x8000E138: jr          $ra
    // 0x8000E13C: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
    return;
    // 0x8000E13C: lwc1        $f0, 0xC($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0XC);
L_8000E140:
    // 0x8000E140: jr          $ra
    // 0x8000E144: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
    return;
    // 0x8000E144: lwc1        $f0, 0x10($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X10);
L_8000E148:
    // 0x8000E148: jr          $ra
    // 0x8000E14C: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    return;
    // 0x8000E14C: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
L_8000E150:
    // 0x8000E150: jr          $ra
    // 0x8000E154: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
    return;
    // 0x8000E154: lwc1        $f0, 0x24($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X24);
L_8000E158:
    // 0x8000E158: lwc1        $f0, 0x28($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X28);
L_8000E15C:
    // 0x8000E15C: jr          $ra
    // 0x8000E160: nop

    return;
    // 0x8000E160: nop

;}
RECOMP_FUNC void gcRemoveAObjFromCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000907C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009084: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80009088: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000908C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009090: lw          $s0, 0x6C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X6C);
    // 0x80009094: beql        $s0, $zero, L_800090B4
    if (ctx->r16 == 0) {
        // 0x80009098: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_800090B4;
    }
    goto skip_0;
    // 0x80009098: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_0:
L_8000909C:
    // 0x8000909C: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x800090A0: jal         0x80007EB0
    // 0x800090A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcSetAObjPrevAlloc(rdram, ctx);
        goto after_0;
    // 0x800090A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800090A8: bne         $s1, $zero, L_8000909C
    if (ctx->r17 != 0) {
        // 0x800090AC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_8000909C;
    }
    // 0x800090AC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x800090B0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_800090B4:
    // 0x800090B4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800090B8: sw          $zero, 0x6C($t7)
    MEM_W(0X6C, ctx->r15) = 0;
    // 0x800090BC: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800090C0: lwc1        $f4, -0x2294($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2294);
    // 0x800090C4: swc1        $f4, 0x74($t8)
    MEM_W(0X74, ctx->r24) = ctx->f4.u32l;
    // 0x800090C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800090CC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800090D0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800090D4: jr          $ra
    // 0x800090D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800090D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void dbCubePlayFGM(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C2C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131C30: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131C34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80131C38: jal         0x80020D88
    // 0x80131C3C: lw          $a0, 0x2D30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2D30);
    syAudioPlayFGM(rdram, ctx);
        goto after_0;
    // 0x80131C3C: lw          $a0, 0x2D30($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2D30);
    after_0:
    // 0x80131C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131C48: jr          $ra
    // 0x80131C4C: nop

    return;
    // 0x80131C4C: nop

;}
RECOMP_FUNC void _bnkfPatchBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E708: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001E70C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001E710: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001E714: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001E718: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001E71C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001E720: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E724: lbu         $t6, 0x2($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2);
    // 0x8001E728: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8001E72C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001E730: bne         $t6, $zero, L_8001E7A0
    if (ctx->r14 != 0) {
        // 0x8001E734: or          $s4, $a2, $zero
        ctx->r20 = ctx->r6 | 0;
            goto L_8001E7A0;
    }
    // 0x8001E734: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8001E738: lw          $v0, 0x8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8);
    // 0x8001E73C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E740: sb          $t7, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r15;
    // 0x8001E744: beq         $v0, $zero, L_8001E758
    if (ctx->r2 == 0) {
        // 0x8001E748: addu        $t8, $v0, $a1
        ctx->r24 = ADD32(ctx->r2, ctx->r5);
            goto L_8001E758;
    }
    // 0x8001E748: addu        $t8, $v0, $a1
    ctx->r24 = ADD32(ctx->r2, ctx->r5);
    // 0x8001E74C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8001E750: jal         0x8001E7C0
    // 0x8001E754: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    syAudioBnkfPatchInst(rdram, ctx);
        goto after_0;
    // 0x8001E754: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_0:
L_8001E758:
    // 0x8001E758: lh          $t9, 0x0($s3)
    ctx->r25 = MEM_H(ctx->r19, 0X0);
    // 0x8001E75C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001E760: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
    // 0x8001E764: blezl       $t9, L_8001E7A4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001E768: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8001E7A4;
    }
    goto skip_0;
    // 0x8001E768: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8001E76C: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
L_8001E770:
    // 0x8001E770: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001E774: addu        $a0, $t0, $s2
    ctx->r4 = ADD32(ctx->r8, ctx->r18);
    // 0x8001E778: beq         $a0, $zero, L_8001E788
    if (ctx->r4 == 0) {
        // 0x8001E77C: sw          $a0, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r4;
            goto L_8001E788;
    }
    // 0x8001E77C: sw          $a0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r4;
    // 0x8001E780: jal         0x8001E7C0
    // 0x8001E784: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    syAudioBnkfPatchInst(rdram, ctx);
        goto after_1;
    // 0x8001E784: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    after_1:
L_8001E788:
    // 0x8001E788: lh          $t2, 0x0($s3)
    ctx->r10 = MEM_H(ctx->r19, 0X0);
    // 0x8001E78C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001E790: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001E794: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8001E798: bnel        $at, $zero, L_8001E770
    if (ctx->r1 != 0) {
        // 0x8001E79C: lw          $t0, 0xC($s0)
        ctx->r8 = MEM_W(ctx->r16, 0XC);
            goto L_8001E770;
    }
    goto skip_1;
    // 0x8001E79C: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    skip_1:
L_8001E7A0:
    // 0x8001E7A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8001E7A4:
    // 0x8001E7A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E7A8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E7AC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001E7B0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001E7B4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001E7B8: jr          $ra
    // 0x8001E7BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001E7BC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bnkfPatchInst(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E7C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8001E7C4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001E7C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001E7CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001E7D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001E7D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001E7D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001E7DC: lbu         $t6, 0x3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X3);
    // 0x8001E7E0: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x8001E7E4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001E7E8: bne         $t6, $zero, L_8001E838
    if (ctx->r14 != 0) {
        // 0x8001E7EC: or          $s4, $a2, $zero
        ctx->r20 = ctx->r6 | 0;
            goto L_8001E838;
    }
    // 0x8001E7EC: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x8001E7F0: lh          $t8, 0xE($a0)
    ctx->r24 = MEM_H(ctx->r4, 0XE);
    // 0x8001E7F4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E7F8: sb          $t7, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r15;
    // 0x8001E7FC: blez        $t8, L_8001E838
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001E800: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001E838;
    }
    // 0x8001E800: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001E804: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8001E808: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
L_8001E80C:
    // 0x8001E80C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001E810: or          $a2, $s4, $zero
    ctx->r6 = ctx->r20 | 0;
    // 0x8001E814: addu        $a0, $t9, $s2
    ctx->r4 = ADD32(ctx->r25, ctx->r18);
    // 0x8001E818: jal         0x8001E858
    // 0x8001E81C: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    syAudioBnkfPatchSound(rdram, ctx);
        goto after_0;
    // 0x8001E81C: sw          $a0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r4;
    after_0:
    // 0x8001E820: lh          $t1, 0xE($s3)
    ctx->r9 = MEM_H(ctx->r19, 0XE);
    // 0x8001E824: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001E828: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8001E82C: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001E830: bnel        $at, $zero, L_8001E80C
    if (ctx->r1 != 0) {
        // 0x8001E834: lw          $t9, 0x10($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X10);
            goto L_8001E80C;
    }
    goto skip_0;
    // 0x8001E834: lw          $t9, 0x10($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X10);
    skip_0:
L_8001E838:
    // 0x8001E838: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E83C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E840: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E844: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001E848: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001E84C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001E850: jr          $ra
    // 0x8001E854: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8001E854: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void _bnkfPatchSound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001E85C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001E860: lbu         $t6, 0xE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XE);
    // 0x8001E864: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E868: bnel        $t6, $zero, L_8001E8A4
    if (ctx->r14 != 0) {
        // 0x8001E86C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8001E8A4;
    }
    goto skip_0;
    // 0x8001E86C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8001E870: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8001E874: lw          $t0, 0x4($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4);
    // 0x8001E878: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    // 0x8001E87C: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x8001E880: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x8001E884: addu        $t3, $t2, $a1
    ctx->r11 = ADD32(ctx->r10, ctx->r5);
    // 0x8001E888: sb          $t7, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r15;
    // 0x8001E88C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001E890: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8001E894: sw          $t3, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r11;
    // 0x8001E898: jal         0x8001E8B0
    // 0x8001E89C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    syAudioBnkfPatchWaveTable(rdram, ctx);
        goto after_0;
    // 0x8001E89C: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    after_0:
    // 0x8001E8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8001E8A4:
    // 0x8001E8A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8001E8A8: jr          $ra
    // 0x8001E8AC: nop

    return;
    // 0x8001E8AC: nop

;}
RECOMP_FUNC void _bnkfPatchWaveTable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E8B0: lbu         $t6, 0x9($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X9);
    // 0x8001E8B4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001E8B8: bne         $t6, $zero, L_8001E914
    if (ctx->r14 != 0) {
        // 0x8001E8BC: nop
    
            goto L_8001E914;
    }
    // 0x8001E8BC: nop

    // 0x8001E8C0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8001E8C4: lbu         $v0, 0x8($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X8);
    // 0x8001E8C8: sb          $t7, 0x9($a0)
    MEM_B(0X9, ctx->r4) = ctx->r15;
    // 0x8001E8CC: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8001E8D0: bne         $v0, $zero, L_8001E8F8
    if (ctx->r2 != 0) {
        // 0x8001E8D4: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_8001E8F8;
    }
    // 0x8001E8D4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001E8D8: lw          $t0, 0x10($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10);
    // 0x8001E8DC: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8001E8E0: addu        $t1, $t0, $a1
    ctx->r9 = ADD32(ctx->r8, ctx->r5);
    // 0x8001E8E4: beq         $v0, $zero, L_8001E914
    if (ctx->r2 == 0) {
        // 0x8001E8E8: sw          $t1, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->r9;
            goto L_8001E914;
    }
    // 0x8001E8E8: sw          $t1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r9;
    // 0x8001E8EC: addu        $t2, $v0, $a1
    ctx->r10 = ADD32(ctx->r2, ctx->r5);
    // 0x8001E8F0: jr          $ra
    // 0x8001E8F4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
    return;
    // 0x8001E8F4: sw          $t2, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r10;
L_8001E8F8:
    // 0x8001E8F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001E8FC: bne         $v0, $at, L_8001E914
    if (ctx->r2 != ctx->r1) {
        // 0x8001E900: nop
    
            goto L_8001E914;
    }
    // 0x8001E900: nop

    // 0x8001E904: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x8001E908: beq         $v0, $zero, L_8001E914
    if (ctx->r2 == 0) {
        // 0x8001E90C: addu        $t3, $v0, $a1
        ctx->r11 = ADD32(ctx->r2, ctx->r5);
            goto L_8001E914;
    }
    // 0x8001E90C: addu        $t3, $v0, $a1
    ctx->r11 = ADD32(ctx->r2, ctx->r5);
    // 0x8001E910: sw          $t3, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r11;
L_8001E914:
    // 0x8001E914: jr          $ra
    // 0x8001E918: nop

    return;
    // 0x8001E918: nop

;}
RECOMP_FUNC void static_5_8002F70C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002F70C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x8002F710: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8002F714: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8002F718: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8002F71C: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x8002F720: beq         $t7, $zero, L_8002F750
    if (ctx->r15 == 0) {
        // 0x8002F724: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8002F750;
    }
    // 0x8002F724: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002F728: andi        $a1, $v0, 0x7F
    ctx->r5 = ctx->r2 & 0X7F;
L_8002F72C:
    // 0x8002F72C: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x8002F730: sll         $t9, $a1, 7
    ctx->r25 = S32(ctx->r5 << 7);
    // 0x8002F734: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x8002F738: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8002F73C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8002F740: andi        $t6, $v0, 0x7F
    ctx->r14 = ctx->r2 & 0X7F;
    // 0x8002F744: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x8002F748: bne         $t7, $zero, L_8002F72C
    if (ctx->r15 != 0) {
        // 0x8002F74C: addu        $a1, $t9, $t6
        ctx->r5 = ADD32(ctx->r25, ctx->r14);
            goto L_8002F72C;
    }
    // 0x8002F74C: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
L_8002F750:
    // 0x8002F750: jr          $ra
    // 0x8002F754: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x8002F754: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void static_5_800335F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800335F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800335F4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800335F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800335FC: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80033600: slti        $at, $t6, 0x26
    ctx->r1 = SIGNED(ctx->r14) < 0X26 ? 1 : 0;
    // 0x80033604: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x80033608: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8003360C: sw          $zero, 0x10($s0)
    MEM_W(0X10, ctx->r16) = 0;
    // 0x80033610: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    // 0x80033614: sw          $zero, 0x18($s0)
    MEM_W(0X18, ctx->r16) = 0;
    // 0x80033618: sw          $zero, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = 0;
    // 0x8003361C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
    // 0x80033620: bne         $at, $zero, L_8003364C
    if (ctx->r1 != 0) {
        // 0x80033624: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8003364C;
    }
    // 0x80033624: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80033628: addiu       $t7, $t6, -0x45
    ctx->r15 = ADD32(ctx->r14, -0X45);
    // 0x8003362C: sltiu       $at, $t7, 0x34
    ctx->r1 = ctx->r15 < 0X34 ? 1 : 0;
    // 0x80033630: beq         $at, $zero, L_80033C38
    if (ctx->r1 == 0) {
        // 0x80033634: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80033C38;
    }
    // 0x80033634: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80033638: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8003363C: addu        $at, $at, $t7
    gpr jr_addend_80033644 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80033640: lw          $t7, -0xDBC($at)
    ctx->r15 = ADD32(ctx->r1, -0XDBC);
    // 0x80033644: jr          $t7
    // 0x80033648: nop

    switch (jr_addend_80033644 >> 2) {
        case 0: goto L_80033958; break;
        case 1: goto L_80033C38; break;
        case 2: goto L_80033958; break;
        case 3: goto L_80033C38; break;
        case 4: goto L_80033C38; break;
        case 5: goto L_80033C38; break;
        case 6: goto L_80033C38; break;
        case 7: goto L_80033C38; break;
        case 8: goto L_80033C38; break;
        case 9: goto L_80033C38; break;
        case 10: goto L_80033C38; break;
        case 11: goto L_80033C38; break;
        case 12: goto L_80033C38; break;
        case 13: goto L_80033C38; break;
        case 14: goto L_80033C38; break;
        case 15: goto L_80033C38; break;
        case 16: goto L_80033C38; break;
        case 17: goto L_80033C38; break;
        case 18: goto L_80033C38; break;
        case 19: goto L_80033808; break;
        case 20: goto L_80033C38; break;
        case 21: goto L_80033C38; break;
        case 22: goto L_80033C38; break;
        case 23: goto L_80033C38; break;
        case 24: goto L_80033C38; break;
        case 25: goto L_80033C38; break;
        case 26: goto L_80033C38; break;
        case 27: goto L_80033C38; break;
        case 28: goto L_80033C38; break;
        case 29: goto L_80033C38; break;
        case 30: goto L_80033660; break;
        case 31: goto L_80033698; break;
        case 32: goto L_80033958; break;
        case 33: goto L_80033958; break;
        case 34: goto L_80033958; break;
        case 35: goto L_80033C38; break;
        case 36: goto L_80033698; break;
        case 37: goto L_80033C38; break;
        case 38: goto L_80033C38; break;
        case 39: goto L_80033C38; break;
        case 40: goto L_80033C38; break;
        case 41: goto L_80033ABC; break;
        case 42: goto L_80033808; break;
        case 43: goto L_80033B8C; break;
        case 44: goto L_80033C38; break;
        case 45: goto L_80033C38; break;
        case 46: goto L_80033BD4; break;
        case 47: goto L_80033C38; break;
        case 48: goto L_80033808; break;
        case 49: goto L_80033C38; break;
        case 50: goto L_80033C38; break;
        case 51: goto L_80033808; break;
        default: switch_error(__func__, 0x80033644, 0x8003F244);
    }
    // 0x80033648: nop

L_8003364C:
    // 0x8003364C: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80033650: beql        $v1, $at, L_80033C1C
    if (ctx->r3 == ctx->r1) {
        // 0x80033654: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80033C1C;
    }
    goto skip_0;
    // 0x80033654: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_0:
    // 0x80033658: b           L_80033C3C
    // 0x8003365C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
        goto L_80033C3C;
    // 0x8003365C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_80033660:
    // 0x80033660: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80033664: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033668: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x8003366C: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x80033670: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x80033674: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80033678: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003367C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80033680: addu        $t7, $a3, $t6
    ctx->r15 = ADD32(ctx->r7, ctx->r14);
    // 0x80033684: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x80033688: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x8003368C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80033690: b           L_80033C50
    // 0x80033694: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_80033C50;
    // 0x80033694: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_80033698:
    // 0x80033698: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8003369C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800336A0: bnel        $v0, $at, L_800336D8
    if (ctx->r2 != ctx->r1) {
        // 0x800336A4: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_800336D8;
    }
    goto skip_1;
    // 0x800336A4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_1:
    // 0x800336A8: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800336AC: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x800336B0: addiu       $t7, $t9, 0x3
    ctx->r15 = ADD32(ctx->r25, 0X3);
    // 0x800336B4: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800336B8: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x800336BC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800336C0: lw          $t7, -0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X4);
    // 0x800336C4: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x800336C8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800336CC: b           L_80033734
    // 0x800336D0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
        goto L_80033734;
    // 0x800336D0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800336D4: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_800336D8:
    // 0x800336D8: bnel        $v0, $at, L_80033710
    if (ctx->r2 != ctx->r1) {
        // 0x800336DC: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_80033710;
    }
    goto skip_2;
    // 0x800336DC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x800336E0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800336E4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800336E8: addiu       $t7, $t6, 0x7
    ctx->r15 = ADD32(ctx->r14, 0X7);
    // 0x800336EC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800336F0: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800336F4: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800336F8: lw          $t8, -0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, -0X8);
    // 0x800336FC: lw          $t9, -0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4);
    // 0x80033700: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80033704: b           L_80033734
    // 0x80033708: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_80033734;
    // 0x80033708: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x8003370C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_80033710:
    // 0x80033710: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033714: addiu       $t6, $t7, 0x3
    ctx->r14 = ADD32(ctx->r15, 0X3);
    // 0x80033718: and         $t8, $t6, $at
    ctx->r24 = ctx->r14 & ctx->r1;
    // 0x8003371C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80033720: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80033724: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x80033728: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x8003372C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80033730: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
L_80033734:
    // 0x80033734: lbu         $t7, 0x34($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X34);
    // 0x80033738: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x8003373C: bnel        $t7, $at, L_80033760
    if (ctx->r15 != ctx->r1) {
        // 0x80033740: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_80033760;
    }
    goto skip_3;
    // 0x80033740: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_3:
    // 0x80033744: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80033748: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x8003374C: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80033750: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x80033754: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80033758: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8003375C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_80033760:
    // 0x80033760: bgtzl       $t6, L_8003379C
    if (SIGNED(ctx->r14) > 0) {
        // 0x80033764: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_8003379C;
    }
    goto skip_4;
    // 0x80033764: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x80033768: bltzl       $t6, L_8003377C
    if (SIGNED(ctx->r14) < 0) {
        // 0x8003376C: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_8003377C;
    }
    goto skip_5;
    // 0x8003376C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x80033770: b           L_8003379C
    // 0x80033774: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
        goto L_8003379C;
    // 0x80033774: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80033778: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_8003377C:
    // 0x8003377C: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x80033780: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80033784: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x80033788: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x8003378C: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80033790: b           L_800337EC
    // 0x80033794: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
        goto L_800337EC;
    // 0x80033794: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x80033798: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_8003379C:
    // 0x8003379C: andi        $t8, $v0, 0x2
    ctx->r24 = ctx->r2 & 0X2;
    // 0x800337A0: beq         $t8, $zero, L_800337C8
    if (ctx->r24 == 0) {
        // 0x800337A4: andi        $t6, $v0, 0x1
        ctx->r14 = ctx->r2 & 0X1;
            goto L_800337C8;
    }
    // 0x800337A4: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800337A8: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x800337AC: addiu       $t6, $zero, 0x2B
    ctx->r14 = ADD32(0, 0X2B);
    // 0x800337B0: addu        $t9, $a3, $t7
    ctx->r25 = ADD32(ctx->r7, ctx->r15);
    // 0x800337B4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800337B8: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800337BC: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x800337C0: b           L_800337EC
    // 0x800337C4: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
        goto L_800337EC;
    // 0x800337C4: sw          $t7, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r15;
L_800337C8:
    // 0x800337C8: beql        $t6, $zero, L_800337F0
    if (ctx->r14 == 0) {
        // 0x800337CC: lw          $t9, 0xC($s0)
        ctx->r25 = MEM_W(ctx->r16, 0XC);
            goto L_800337F0;
    }
    goto skip_6;
    // 0x800337CC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    skip_6:
    // 0x800337D0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x800337D4: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800337D8: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x800337DC: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800337E0: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800337E4: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800337E8: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_800337EC:
    // 0x800337EC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
L_800337F0:
    // 0x800337F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800337F4: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x800337F8: jal         0x80038A40
    // 0x800337FC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_0;
    // 0x800337FC: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_0:
    // 0x80033800: b           L_80033C54
    // 0x80033804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80033C54;
    // 0x80033804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80033808:
    // 0x80033808: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x8003380C: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80033810: bnel        $v0, $at, L_80033848
    if (ctx->r2 != ctx->r1) {
        // 0x80033814: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80033848;
    }
    goto skip_7;
    // 0x80033814: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_7:
    // 0x80033818: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8003381C: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033820: addiu       $t8, $t6, 0x3
    ctx->r24 = ADD32(ctx->r14, 0X3);
    // 0x80033824: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80033828: addiu       $t7, $t9, 0x4
    ctx->r15 = ADD32(ctx->r25, 0X4);
    // 0x8003382C: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80033830: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80033834: sra         $t6, $t8, 31
    ctx->r14 = S32(SIGNED(ctx->r24) >> 31);
    // 0x80033838: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8003383C: b           L_800338A4
    // 0x80033840: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
        goto L_800338A4;
    // 0x80033840: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80033844: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_80033848:
    // 0x80033848: bnel        $v0, $at, L_80033880
    if (ctx->r2 != ctx->r1) {
        // 0x8003384C: lw          $t6, 0x0($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X0);
            goto L_80033880;
    }
    goto skip_8;
    // 0x8003384C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    skip_8:
    // 0x80033850: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80033854: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80033858: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x8003385C: and         $t6, $t8, $at
    ctx->r14 = ctx->r24 & ctx->r1;
    // 0x80033860: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80033864: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80033868: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8003386C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80033870: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80033874: b           L_800338A4
    // 0x80033878: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800338A4;
    // 0x80033878: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8003387C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
L_80033880:
    // 0x80033880: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033884: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x80033888: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x8003388C: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x80033890: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80033894: lw          $t7, -0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, -0X4);
    // 0x80033898: sra         $t8, $t7, 31
    ctx->r24 = S32(SIGNED(ctx->r15) >> 31);
    // 0x8003389C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800338A0: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
L_800338A4:
    // 0x800338A4: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x800338A8: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x800338AC: bne         $v0, $at, L_800338CC
    if (ctx->r2 != ctx->r1) {
        // 0x800338B0: nop
    
            goto L_800338CC;
    }
    // 0x800338B0: nop

    // 0x800338B4: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x800338B8: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x800338BC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800338C0: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x800338C4: b           L_800338E4
    // 0x800338C8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
        goto L_800338E4;
    // 0x800338C8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800338CC:
    // 0x800338CC: bnel        $v0, $zero, L_800338E8
    if (ctx->r2 != 0) {
        // 0x800338D0: lw          $t7, 0x30($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X30);
            goto L_800338E8;
    }
    goto skip_9;
    // 0x800338D0: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    skip_9:
    // 0x800338D4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x800338D8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x800338DC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800338E0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
L_800338E4:
    // 0x800338E4: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
L_800338E8:
    // 0x800338E8: andi        $t6, $t7, 0x8
    ctx->r14 = ctx->r15 & 0X8;
    // 0x800338EC: beql        $t6, $zero, L_80033940
    if (ctx->r14 == 0) {
        // 0x800338F0: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80033940;
    }
    goto skip_10;
    // 0x800338F0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_10:
    // 0x800338F4: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x800338F8: addiu       $t8, $zero, 0x30
    ctx->r24 = ADD32(0, 0X30);
    // 0x800338FC: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80033900: addu        $t7, $a3, $t9
    ctx->r15 = ADD32(ctx->r7, ctx->r25);
    // 0x80033904: sb          $t8, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r24;
    // 0x80033908: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x8003390C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80033910: beq         $v1, $at, L_80033924
    if (ctx->r3 == ctx->r1) {
        // 0x80033914: sw          $t9, 0xC($s0)
        MEM_W(0XC, ctx->r16) = ctx->r25;
            goto L_80033924;
    }
    // 0x80033914: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x80033918: addiu       $at, $zero, 0x58
    ctx->r1 = ADD32(0, 0X58);
    // 0x8003391C: bnel        $v1, $at, L_80033940
    if (ctx->r3 != ctx->r1) {
        // 0x80033920: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80033940;
    }
    goto skip_11;
    // 0x80033920: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_11:
L_80033924:
    // 0x80033924: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80033928: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x8003392C: sb          $a1, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r5;
    // 0x80033930: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80033934: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x80033938: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
    // 0x8003393C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_80033940:
    // 0x80033940: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033944: addu        $t7, $t8, $a3
    ctx->r15 = ADD32(ctx->r24, ctx->r7);
    // 0x80033948: jal         0x80038A40
    // 0x8003394C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    _Litob(rdram, ctx);
        goto after_1;
    // 0x8003394C: sw          $t7, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r15;
    after_1:
    // 0x80033950: b           L_80033C54
    // 0x80033954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80033C54;
    // 0x80033954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80033958:
    // 0x80033958: lbu         $t6, 0x34($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X34);
    // 0x8003395C: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    // 0x80033960: bnel        $t6, $at, L_800339C8
    if (ctx->r14 != ctx->r1) {
        // 0x80033964: lw          $v0, 0x0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X0);
            goto L_800339C8;
    }
    goto skip_12;
    // 0x80033964: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    skip_12:
    // 0x80033968: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8003396C: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80033970: beq         $t9, $zero, L_80033988
    if (ctx->r25 == 0) {
        // 0x80033974: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80033988;
    }
    // 0x80033974: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80033978: addiu       $t8, $v1, 0x7
    ctx->r24 = ADD32(ctx->r3, 0X7);
    // 0x8003397C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80033980: b           L_800339B8
    // 0x80033984: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
        goto L_800339B8;
    // 0x80033984: addiu       $v0, $t8, -0x16
    ctx->r2 = ADD32(ctx->r24, -0X16);
L_80033988:
    // 0x80033988: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x8003398C: beq         $t7, $zero, L_800339A4
    if (ctx->r15 == 0) {
        // 0x80033990: addiu       $t9, $v0, 0x7
        ctx->r25 = ADD32(ctx->r2, 0X7);
            goto L_800339A4;
    }
    // 0x80033990: addiu       $t9, $v0, 0x7
    ctx->r25 = ADD32(ctx->r2, 0X7);
    // 0x80033994: addiu       $t6, $v1, 0xA
    ctx->r14 = ADD32(ctx->r3, 0XA);
    // 0x80033998: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8003399C: b           L_800339B4
    // 0x800339A0: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
        goto L_800339B4;
    // 0x800339A0: addiu       $a0, $t6, -0x28
    ctx->r4 = ADD32(ctx->r14, -0X28);
L_800339A4:
    // 0x800339A4: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x800339A8: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x800339AC: addiu       $a0, $t8, 0x8
    ctx->r4 = ADD32(ctx->r24, 0X8);
    // 0x800339B0: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_800339B4:
    // 0x800339B4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_800339B8:
    // 0x800339B8: ldc1        $f4, -0x8($v0)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r2, -0X8);
    // 0x800339BC: b           L_80033A1C
    // 0x800339C0: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
        goto L_80033A1C;
    // 0x800339C0: sdc1        $f4, 0x0($s0)
    CHECK_FR(ctx, 4);
    SD(ctx->f4.u64, 0X0, ctx->r16);
    // 0x800339C4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
L_800339C8:
    // 0x800339C8: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x800339CC: beq         $t6, $zero, L_800339E4
    if (ctx->r14 == 0) {
        // 0x800339D0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800339E4;
    }
    // 0x800339D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800339D4: addiu       $t9, $v1, 0x7
    ctx->r25 = ADD32(ctx->r3, 0X7);
    // 0x800339D8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800339DC: b           L_80033A14
    // 0x800339E0: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
        goto L_80033A14;
    // 0x800339E0: addiu       $v0, $t9, -0x16
    ctx->r2 = ADD32(ctx->r25, -0X16);
L_800339E4:
    // 0x800339E4: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x800339E8: beq         $t8, $zero, L_80033A00
    if (ctx->r24 == 0) {
        // 0x800339EC: addiu       $t6, $v0, 0x7
        ctx->r14 = ADD32(ctx->r2, 0X7);
            goto L_80033A00;
    }
    // 0x800339EC: addiu       $t6, $v0, 0x7
    ctx->r14 = ADD32(ctx->r2, 0X7);
    // 0x800339F0: addiu       $t7, $v1, 0xA
    ctx->r15 = ADD32(ctx->r3, 0XA);
    // 0x800339F4: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800339F8: b           L_80033A10
    // 0x800339FC: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
        goto L_80033A10;
    // 0x800339FC: addiu       $a0, $t7, -0x28
    ctx->r4 = ADD32(ctx->r15, -0X28);
L_80033A00:
    // 0x80033A00: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80033A04: and         $t9, $t6, $at
    ctx->r25 = ctx->r14 & ctx->r1;
    // 0x80033A08: addiu       $a0, $t9, 0x8
    ctx->r4 = ADD32(ctx->r25, 0X8);
    // 0x80033A0C: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
L_80033A10:
    // 0x80033A10: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80033A14:
    // 0x80033A14: ldc1        $f6, -0x8($v0)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r2, -0X8);
    // 0x80033A18: sdc1        $f6, 0x0($s0)
    CHECK_FR(ctx, 6);
    SD(ctx->f6.u64, 0X0, ctx->r16);
L_80033A1C:
    // 0x80033A1C: lhu         $t7, 0x0($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X0);
    // 0x80033A20: andi        $t6, $t7, 0x8000
    ctx->r14 = ctx->r15 & 0X8000;
    // 0x80033A24: beql        $t6, $zero, L_80033A50
    if (ctx->r14 == 0) {
        // 0x80033A28: lw          $v0, 0x30($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X30);
            goto L_80033A50;
    }
    goto skip_13;
    // 0x80033A28: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    skip_13:
    // 0x80033A2C: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    // 0x80033A30: addiu       $t9, $zero, 0x2D
    ctx->r25 = ADD32(0, 0X2D);
    // 0x80033A34: addu        $t7, $a3, $t8
    ctx->r15 = ADD32(ctx->r7, ctx->r24);
    // 0x80033A38: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x80033A3C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80033A40: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x80033A44: b           L_80033AA0
    // 0x80033A48: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_80033AA0;
    // 0x80033A48: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x80033A4C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
L_80033A50:
    // 0x80033A50: andi        $t9, $v0, 0x2
    ctx->r25 = ctx->r2 & 0X2;
    // 0x80033A54: beq         $t9, $zero, L_80033A7C
    if (ctx->r25 == 0) {
        // 0x80033A58: andi        $t7, $v0, 0x1
        ctx->r15 = ctx->r2 & 0X1;
            goto L_80033A7C;
    }
    // 0x80033A58: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80033A5C: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x80033A60: addiu       $t7, $zero, 0x2B
    ctx->r15 = ADD32(0, 0X2B);
    // 0x80033A64: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x80033A68: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80033A6C: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80033A70: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x80033A74: b           L_80033AA0
    // 0x80033A78: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
        goto L_80033AA0;
    // 0x80033A78: sw          $t6, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r14;
L_80033A7C:
    // 0x80033A7C: beql        $t7, $zero, L_80033AA4
    if (ctx->r15 == 0) {
        // 0x80033A80: lw          $t8, 0xC($s0)
        ctx->r24 = MEM_W(ctx->r16, 0XC);
            goto L_80033AA4;
    }
    goto skip_14;
    // 0x80033A80: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
    skip_14:
    // 0x80033A84: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x80033A88: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x80033A8C: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80033A90: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x80033A94: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80033A98: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80033A9C: sw          $t9, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r25;
L_80033AA0:
    // 0x80033AA0: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_80033AA4:
    // 0x80033AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033AA8: addu        $t6, $t8, $a3
    ctx->r14 = ADD32(ctx->r24, ctx->r7);
    // 0x80033AAC: jal         0x80038360
    // 0x80033AB0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Ldtob(rdram, ctx);
        goto after_2;
    // 0x80033AB0: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_2:
    // 0x80033AB4: b           L_80033C54
    // 0x80033AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80033C54;
    // 0x80033AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80033ABC:
    // 0x80033ABC: lbu         $v0, 0x34($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X34);
    // 0x80033AC0: addiu       $at, $zero, 0x68
    ctx->r1 = ADD32(0, 0X68);
    // 0x80033AC4: bnel        $v0, $at, L_80033AF8
    if (ctx->r2 != ctx->r1) {
        // 0x80033AC8: addiu       $at, $zero, 0x6C
        ctx->r1 = ADD32(0, 0X6C);
            goto L_80033AF8;
    }
    goto skip_15;
    // 0x80033AC8: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    skip_15:
    // 0x80033ACC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80033AD0: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033AD4: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x80033AD8: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80033ADC: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x80033AE0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80033AE4: lw          $t9, -0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, -0X4);
    // 0x80033AE8: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80033AEC: b           L_80033C50
    // 0x80033AF0: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
        goto L_80033C50;
    // 0x80033AF0: sh          $t7, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r15;
    // 0x80033AF4: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
L_80033AF8:
    // 0x80033AF8: bnel        $v0, $at, L_80033B2C
    if (ctx->r2 != ctx->r1) {
        // 0x80033AFC: addiu       $at, $zero, 0x4C
        ctx->r1 = ADD32(0, 0X4C);
            goto L_80033B2C;
    }
    goto skip_16;
    // 0x80033AFC: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
    skip_16:
    // 0x80033B00: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80033B04: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033B08: addiu       $t6, $t8, 0x3
    ctx->r14 = ADD32(ctx->r24, 0X3);
    // 0x80033B0C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80033B10: addiu       $t9, $t7, 0x4
    ctx->r25 = ADD32(ctx->r15, 0X4);
    // 0x80033B14: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80033B18: lw          $t6, -0x4($t9)
    ctx->r14 = MEM_W(ctx->r25, -0X4);
    // 0x80033B1C: lw          $t8, 0x2C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X2C);
    // 0x80033B20: b           L_80033C50
    // 0x80033B24: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
        goto L_80033C50;
    // 0x80033B24: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80033B28: addiu       $at, $zero, 0x4C
    ctx->r1 = ADD32(0, 0X4C);
L_80033B2C:
    // 0x80033B2C: bnel        $v0, $at, L_80033B68
    if (ctx->r2 != ctx->r1) {
        // 0x80033B30: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_80033B68;
    }
    goto skip_17;
    // 0x80033B30: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_17:
    // 0x80033B34: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80033B38: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033B3C: addiu       $t9, $t7, 0x3
    ctx->r25 = ADD32(ctx->r15, 0X3);
    // 0x80033B40: and         $t8, $t9, $at
    ctx->r24 = ctx->r25 & ctx->r1;
    // 0x80033B44: addiu       $t6, $t8, 0x4
    ctx->r14 = ADD32(ctx->r24, 0X4);
    // 0x80033B48: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80033B4C: lw          $t6, -0x4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4);
    // 0x80033B50: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80033B54: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80033B58: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80033B5C: b           L_80033C50
    // 0x80033B60: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
        goto L_80033C50;
    // 0x80033B60: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80033B64: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_80033B68:
    // 0x80033B68: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033B6C: addiu       $t8, $t7, 0x3
    ctx->r24 = ADD32(ctx->r15, 0X3);
    // 0x80033B70: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x80033B74: addiu       $t6, $t9, 0x4
    ctx->r14 = ADD32(ctx->r25, 0X4);
    // 0x80033B78: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80033B7C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80033B80: lw          $t7, 0x2C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2C);
    // 0x80033B84: b           L_80033C50
    // 0x80033B88: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
        goto L_80033C50;
    // 0x80033B88: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
L_80033B8C:
    // 0x80033B8C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x80033B90: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033B94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033B98: addiu       $t6, $t9, 0x3
    ctx->r14 = ADD32(ctx->r25, 0X3);
    // 0x80033B9C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80033BA0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80033BA4: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80033BA8: lw          $t6, -0x4($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X4);
    // 0x80033BAC: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80033BB0: addiu       $a1, $zero, 0x78
    ctx->r5 = ADD32(0, 0X78);
    // 0x80033BB4: sra         $t8, $t6, 31
    ctx->r24 = S32(SIGNED(ctx->r14) >> 31);
    // 0x80033BB8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x80033BBC: addu        $t6, $t7, $a3
    ctx->r14 = ADD32(ctx->r15, ctx->r7);
    // 0x80033BC0: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80033BC4: jal         0x80038A40
    // 0x80033BC8: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    _Litob(rdram, ctx);
        goto after_3;
    // 0x80033BC8: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    after_3:
    // 0x80033BCC: b           L_80033C54
    // 0x80033BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80033C54;
    // 0x80033BD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80033BD4:
    // 0x80033BD4: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80033BD8: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80033BDC: addiu       $t9, $t8, 0x3
    ctx->r25 = ADD32(ctx->r24, 0X3);
    // 0x80033BE0: and         $t7, $t9, $at
    ctx->r15 = ctx->r25 & ctx->r1;
    // 0x80033BE4: addiu       $t6, $t7, 0x4
    ctx->r14 = ADD32(ctx->r15, 0X4);
    // 0x80033BE8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80033BEC: lw          $a0, -0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, -0X4);
    // 0x80033BF0: jal         0x8003440C
    // 0x80033BF4: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    strlen_recomp(rdram, ctx);
        goto after_4;
    // 0x80033BF4: sw          $a0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r4;
    after_4:
    // 0x80033BF8: lw          $v1, 0x24($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X24);
    // 0x80033BFC: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x80033C00: bltz        $v1, L_80033C50
    if (SIGNED(ctx->r3) < 0) {
        // 0x80033C04: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80033C50;
    }
    // 0x80033C04: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80033C08: beql        $at, $zero, L_80033C54
    if (ctx->r1 == 0) {
        // 0x80033C0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80033C54;
    }
    goto skip_18;
    // 0x80033C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_18:
    // 0x80033C10: b           L_80033C50
    // 0x80033C14: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
        goto L_80033C50;
    // 0x80033C14: sw          $v1, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r3;
    // 0x80033C18: lw          $t8, 0xC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XC);
L_80033C1C:
    // 0x80033C1C: addiu       $t6, $zero, 0x25
    ctx->r14 = ADD32(0, 0X25);
    // 0x80033C20: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80033C24: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80033C28: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80033C2C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80033C30: b           L_80033C50
    // 0x80033C34: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
        goto L_80033C50;
    // 0x80033C34: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_80033C38:
    // 0x80033C38: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
L_80033C3C:
    // 0x80033C3C: addu        $t9, $a3, $t6
    ctx->r25 = ADD32(ctx->r7, ctx->r14);
    // 0x80033C40: sb          $a1, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r5;
    // 0x80033C44: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80033C48: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80033C4C: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
L_80033C50:
    // 0x80033C50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80033C54:
    // 0x80033C54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033C58: jr          $ra
    // 0x80033C5C: nop

    return;
    // 0x80033C5C: nop

;}
RECOMP_FUNC void static_5_80037DF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037DF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80037DF4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80037DF8: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80037DFC: sra         $s2, $t6, 16
    ctx->r18 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80037E00: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80037E04: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80037E08: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80037E0C: andi        $t6, $s4, 0xFF
    ctx->r14 = ctx->r20 & 0XFF;
    // 0x80037E10: sw          $s4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r20;
    // 0x80037E14: or          $s4, $t6, $zero
    ctx->r20 = ctx->r14 | 0;
    // 0x80037E18: bgtz        $s3, L_80037E2C
    if (SIGNED(ctx->r19) > 0) {
        // 0x80037E1C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80037E2C;
    }
    // 0x80037E1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80037E20: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80037E24: addiu       $s1, $s1, -0xC20
    ctx->r17 = ADD32(ctx->r17, -0XC20);
    // 0x80037E28: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_80037E2C:
    // 0x80037E2C: addiu       $v0, $zero, 0x66
    ctx->r2 = ADD32(0, 0X66);
    // 0x80037E30: beq         $v0, $s4, L_80037E64
    if (ctx->r2 == ctx->r20) {
        // 0x80037E34: or          $v1, $s4, $zero
        ctx->r3 = ctx->r20 | 0;
            goto L_80037E64;
    }
    // 0x80037E34: or          $v1, $s4, $zero
    ctx->r3 = ctx->r20 | 0;
    // 0x80037E38: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x80037E3C: beq         $a0, $v1, L_80037E48
    if (ctx->r4 == ctx->r3) {
        // 0x80037E40: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_80037E48;
    }
    // 0x80037E40: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x80037E44: bne         $v1, $at, L_800380A0
    if (ctx->r3 != ctx->r1) {
        // 0x80037E48: slti        $at, $s2, -0x4
        ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
            goto L_800380A0;
    }
L_80037E48:
    // 0x80037E48: slti        $at, $s2, -0x4
    ctx->r1 = SIGNED(ctx->r18) < -0X4 ? 1 : 0;
    // 0x80037E4C: bne         $at, $zero, L_800380A0
    if (ctx->r1 != 0) {
        // 0x80037E50: nop
    
            goto L_800380A0;
    }
    // 0x80037E50: nop

    // 0x80037E54: lw          $t7, 0x24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X24);
    // 0x80037E58: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80037E5C: beq         $at, $zero, L_800380A0
    if (ctx->r1 == 0) {
        // 0x80037E60: nop
    
            goto L_800380A0;
    }
    // 0x80037E60: nop

L_80037E64:
    // 0x80037E64: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80037E68: sll         $t8, $s2, 16
    ctx->r24 = S32(ctx->r18 << 16);
    // 0x80037E6C: beq         $v0, $v1, L_80037EA8
    if (ctx->r2 == ctx->r3) {
        // 0x80037E70: sra         $s2, $t8, 16
        ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
            goto L_80037EA8;
    }
    // 0x80037E70: sra         $s2, $t8, 16
    ctx->r18 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80037E74: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80037E78: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80037E7C: andi        $t7, $t6, 0x8
    ctx->r15 = ctx->r14 & 0X8;
    // 0x80037E80: bne         $t7, $zero, L_80037E98
    if (ctx->r15 != 0) {
        // 0x80037E84: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80037E98;
    }
    // 0x80037E84: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80037E88: beql        $at, $zero, L_80037E9C
    if (ctx->r1 == 0) {
        // 0x80037E8C: subu        $t8, $v0, $s2
        ctx->r24 = SUB32(ctx->r2, ctx->r18);
            goto L_80037E9C;
    }
    goto skip_0;
    // 0x80037E8C: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
    skip_0:
    // 0x80037E90: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x80037E94: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_80037E98:
    // 0x80037E98: subu        $t8, $v0, $s2
    ctx->r24 = SUB32(ctx->r2, ctx->r18);
L_80037E9C:
    // 0x80037E9C: bgez        $t8, L_80037EA8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80037EA0: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_80037EA8;
    }
    // 0x80037EA0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x80037EA4: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_80037EA8:
    // 0x80037EA8: bgtz        $s2, L_80037F78
    if (SIGNED(ctx->r18) > 0) {
        // 0x80037EAC: slt         $at, $s3, $s2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
            goto L_80037F78;
    }
    // 0x80037EAC: slt         $at, $s3, $s2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80037EB0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80037EB4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80037EB8: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80037EBC: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x80037EC0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80037EC4: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80037EC8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80037ECC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80037ED0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80037ED4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x80037ED8: bgtz        $v0, L_80037EF0
    if (SIGNED(ctx->r2) > 0) {
        // 0x80037EDC: sw          $t8, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r24;
            goto L_80037EF0;
    }
    // 0x80037EDC: sw          $t8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r24;
    // 0x80037EE0: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80037EE4: andi        $t9, $t6, 0x8
    ctx->r25 = ctx->r14 & 0X8;
    // 0x80037EE8: beql        $t9, $zero, L_80037F18
    if (ctx->r25 == 0) {
        // 0x80037EEC: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80037F18;
    }
    goto skip_1;
    // 0x80037EEC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    skip_1:
L_80037EF0:
    // 0x80037EF0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80037EF4: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80037EF8: addiu       $t7, $zero, 0x2E
    ctx->r15 = ADD32(0, 0X2E);
    // 0x80037EFC: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x80037F00: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x80037F04: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80037F08: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80037F0C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x80037F10: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x80037F14: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_80037F18:
    // 0x80037F18: beql        $at, $zero, L_80037F34
    if (ctx->r1 == 0) {
        // 0x80037F1C: addu        $t8, $v0, $s2
        ctx->r24 = ADD32(ctx->r2, ctx->r18);
            goto L_80037F34;
    }
    goto skip_2;
    // 0x80037F1C: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
    skip_2:
    // 0x80037F20: negu        $s2, $v0
    ctx->r18 = SUB32(0, ctx->r2);
    // 0x80037F24: sll         $t7, $s2, 16
    ctx->r15 = S32(ctx->r18 << 16);
    // 0x80037F28: sra         $s2, $t7, 16
    ctx->r18 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80037F2C: negu        $v1, $s2
    ctx->r3 = SUB32(0, ctx->r18);
    // 0x80037F30: addu        $t8, $v0, $s2
    ctx->r24 = ADD32(ctx->r2, ctx->r18);
L_80037F34:
    // 0x80037F34: slt         $at, $t8, $s3
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80037F38: sw          $v1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r3;
    // 0x80037F3C: beq         $at, $zero, L_80037F50
    if (ctx->r1 == 0) {
        // 0x80037F40: sw          $t8, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r24;
            goto L_80037F50;
    }
    // 0x80037F40: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x80037F44: sll         $s3, $t8, 16
    ctx->r19 = S32(ctx->r24 << 16);
    // 0x80037F48: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80037F4C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_80037F50:
    // 0x80037F50: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80037F54: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80037F58: sw          $s3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r19;
    // 0x80037F5C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80037F60: jal         0x800343E0
    // 0x80037F64: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x80037F64: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_0:
    // 0x80037F68: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80037F6C: subu        $t6, $t8, $s3
    ctx->r14 = SUB32(ctx->r24, ctx->r19);
    // 0x80037F70: b           L_800382FC
    // 0x80037F74: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
        goto L_800382FC;
    // 0x80037F74: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
L_80037F78:
    // 0x80037F78: beq         $at, $zero, L_80037FF0
    if (ctx->r1 == 0) {
        // 0x80037F7C: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80037FF0;
    }
    // 0x80037F7C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80037F80: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80037F84: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80037F88: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80037F8C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80037F90: jal         0x800343E0
    // 0x80037F94: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x80037F94: addu        $a0, $t7, $t9
    ctx->r4 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x80037F98: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80037F9C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80037FA0: subu        $t7, $s2, $s3
    ctx->r15 = SUB32(ctx->r18, ctx->r19);
    // 0x80037FA4: addu        $t6, $t8, $s3
    ctx->r14 = ADD32(ctx->r24, ctx->r19);
    // 0x80037FA8: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x80037FAC: bgtz        $v0, L_80037FC4
    if (SIGNED(ctx->r2) > 0) {
        // 0x80037FB0: sw          $t7, 0x18($s0)
        MEM_W(0X18, ctx->r16) = ctx->r15;
            goto L_80037FC4;
    }
    // 0x80037FB0: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80037FB4: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x80037FB8: andi        $t8, $t9, 0x8
    ctx->r24 = ctx->r25 & 0X8;
    // 0x80037FBC: beq         $t8, $zero, L_80037FE8
    if (ctx->r24 == 0) {
        // 0x80037FC0: nop
    
            goto L_80037FE8;
    }
    // 0x80037FC0: nop

L_80037FC4:
    // 0x80037FC4: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80037FC8: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80037FCC: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x80037FD0: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80037FD4: sb          $t6, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r14;
    // 0x80037FD8: lw          $t7, 0x1C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X1C);
    // 0x80037FDC: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80037FE0: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80037FE4: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_80037FE8:
    // 0x80037FE8: b           L_800382FC
    // 0x80037FEC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
        goto L_800382FC;
    // 0x80037FEC: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
L_80037FF0:
    // 0x80037FF0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x80037FF4: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80037FF8: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80037FFC: jal         0x800343E0
    // 0x80038000: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_2;
    // 0x80038000: addu        $a0, $t6, $t8
    ctx->r4 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x80038004: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80038008: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8003800C: subu        $s3, $s3, $s2
    ctx->r19 = SUB32(ctx->r19, ctx->r18);
    // 0x80038010: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x80038014: addu        $t9, $t7, $s2
    ctx->r25 = ADD32(ctx->r15, ctx->r18);
    // 0x80038018: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
    // 0x8003801C: bgtz        $v0, L_80038034
    if (SIGNED(ctx->r2) > 0) {
        // 0x80038020: sra         $s3, $t6, 16
        ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
            goto L_80038034;
    }
    // 0x80038020: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80038024: lw          $t7, 0x30($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X30);
    // 0x80038028: andi        $t9, $t7, 0x8
    ctx->r25 = ctx->r15 & 0X8;
    // 0x8003802C: beql        $t9, $zero, L_8003805C
    if (ctx->r25 == 0) {
        // 0x80038030: slt         $at, $v0, $s3
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_8003805C;
    }
    goto skip_3;
    // 0x80038030: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    skip_3:
L_80038034:
    // 0x80038034: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80038038: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x8003803C: addiu       $t6, $zero, 0x2E
    ctx->r14 = ADD32(0, 0X2E);
    // 0x80038040: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80038044: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x80038048: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x8003804C: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80038050: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80038054: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x80038058: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
L_8003805C:
    // 0x8003805C: beq         $at, $zero, L_80038070
    if (ctx->r1 == 0) {
        // 0x80038060: addu        $a1, $s2, $s1
        ctx->r5 = ADD32(ctx->r18, ctx->r17);
            goto L_80038070;
    }
    // 0x80038060: addu        $a1, $s2, $s1
    ctx->r5 = ADD32(ctx->r18, ctx->r17);
    // 0x80038064: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80038068: sra         $t6, $s3, 16
    ctx->r14 = S32(SIGNED(ctx->r19) >> 16);
    // 0x8003806C: or          $s3, $t6, $zero
    ctx->r19 = ctx->r14 | 0;
L_80038070:
    // 0x80038070: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x80038074: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80038078: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x8003807C: jal         0x800343E0
    // 0x80038080: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80038080: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_3:
    // 0x80038084: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80038088: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x8003808C: addu        $t6, $t7, $s3
    ctx->r14 = ADD32(ctx->r15, ctx->r19);
    // 0x80038090: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x80038094: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x80038098: b           L_800382FC
    // 0x8003809C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
        goto L_800382FC;
    // 0x8003809C: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
L_800380A0:
    // 0x800380A0: beq         $a0, $v1, L_800380B0
    if (ctx->r4 == ctx->r3) {
        // 0x800380A4: addiu       $at, $zero, 0x47
        ctx->r1 = ADD32(0, 0X47);
            goto L_800380B0;
    }
    // 0x800380A4: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800380A8: bnel        $v1, $at, L_800380F0
    if (ctx->r3 != ctx->r1) {
        // 0x800380AC: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_800380F0;
    }
    goto skip_4;
    // 0x800380AC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_4:
L_800380B0:
    // 0x800380B0: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x800380B4: addiu       $s4, $zero, 0x45
    ctx->r20 = ADD32(0, 0X45);
    // 0x800380B8: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800380BC: beql        $at, $zero, L_800380D0
    if (ctx->r1 == 0) {
        // 0x800380C0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800380D0;
    }
    goto skip_5;
    // 0x800380C0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    skip_5:
    // 0x800380C4: sw          $s3, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r19;
    // 0x800380C8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800380CC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800380D0:
    // 0x800380D0: bgez        $t7, L_800380DC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800380D4: sw          $t7, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r15;
            goto L_800380DC;
    }
    // 0x800380D4: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x800380D8: sw          $zero, 0x24($s0)
    MEM_W(0X24, ctx->r16) = 0;
L_800380DC:
    // 0x800380DC: bne         $a0, $v1, L_800380EC
    if (ctx->r4 != ctx->r3) {
        // 0x800380E0: nop
    
            goto L_800380EC;
    }
    // 0x800380E0: nop

    // 0x800380E4: b           L_800380EC
    // 0x800380E8: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
        goto L_800380EC;
    // 0x800380E8: addiu       $s4, $zero, 0x65
    ctx->r20 = ADD32(0, 0X65);
L_800380EC:
    // 0x800380EC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_800380F0:
    // 0x800380F0: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800380F4: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x800380F8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800380FC: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80038100: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x80038104: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80038108: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8003810C: addiu       $t7, $t8, 0x1
    ctx->r15 = ADD32(ctx->r24, 0X1);
    // 0x80038110: bgtz        $v0, L_80038128
    if (SIGNED(ctx->r2) > 0) {
        // 0x80038114: sw          $t7, 0x14($s0)
        MEM_W(0X14, ctx->r16) = ctx->r15;
            goto L_80038128;
    }
    // 0x80038114: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x80038118: lw          $t9, 0x30($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X30);
    // 0x8003811C: andi        $t6, $t9, 0x8
    ctx->r14 = ctx->r25 & 0X8;
    // 0x80038120: beq         $t6, $zero, L_8003814C
    if (ctx->r14 == 0) {
        // 0x80038124: nop
    
            goto L_8003814C;
    }
    // 0x80038124: nop

L_80038128:
    // 0x80038128: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x8003812C: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80038130: addiu       $t8, $zero, 0x2E
    ctx->r24 = ADD32(0, 0X2E);
    // 0x80038134: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x80038138: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
    // 0x8003813C: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x80038140: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x80038144: addiu       $t9, $t7, 0x1
    ctx->r25 = ADD32(ctx->r15, 0X1);
    // 0x80038148: sw          $t9, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r25;
L_8003814C:
    // 0x8003814C: blezl       $v0, L_800381A8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80038150: lw          $t6, 0x8($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X8);
            goto L_800381A8;
    }
    goto skip_6;
    // 0x80038150: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    skip_6:
    // 0x80038154: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80038158: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x8003815C: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80038160: slt         $at, $v0, $s3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80038164: beq         $at, $zero, L_80038178
    if (ctx->r1 == 0) {
        // 0x80038168: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_80038178;
    }
    // 0x80038168: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003816C: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80038170: sra         $t7, $s3, 16
    ctx->r15 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80038174: or          $s3, $t7, $zero
    ctx->r19 = ctx->r15 | 0;
L_80038178:
    // 0x80038178: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    // 0x8003817C: lw          $t8, 0x14($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X14);
    // 0x80038180: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80038184: jal         0x800343E0
    // 0x80038188: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    memcpy_recomp(rdram, ctx);
        goto after_4;
    // 0x80038188: addu        $a0, $t9, $t8
    ctx->r4 = ADD32(ctx->r25, ctx->r24);
    after_4:
    // 0x8003818C: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80038190: lw          $t9, 0x24($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X24);
    // 0x80038194: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x80038198: subu        $t8, $t9, $s3
    ctx->r24 = SUB32(ctx->r25, ctx->r19);
    // 0x8003819C: sw          $t7, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r15;
    // 0x800381A0: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x800381A4: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
L_800381A8:
    // 0x800381A8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800381AC: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x800381B0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800381B4: bltz        $s2, L_800381CC
    if (SIGNED(ctx->r18) < 0) {
        // 0x800381B8: sb          $s4, -0x1($s1)
        MEM_B(-0X1, ctx->r17) = ctx->r20;
            goto L_800381CC;
    }
    // 0x800381B8: sb          $s4, -0x1($s1)
    MEM_B(-0X1, ctx->r17) = ctx->r20;
    // 0x800381BC: addiu       $t9, $zero, 0x2B
    ctx->r25 = ADD32(0, 0X2B);
    // 0x800381C0: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x800381C4: b           L_800381E8
    // 0x800381C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_800381E8;
    // 0x800381C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800381CC:
    // 0x800381CC: negu        $s2, $s2
    ctx->r18 = SUB32(0, ctx->r18);
    // 0x800381D0: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800381D4: addiu       $t8, $zero, 0x2D
    ctx->r24 = ADD32(0, 0X2D);
    // 0x800381D8: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800381DC: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800381E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800381E4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
L_800381E8:
    // 0x800381E8: slti        $at, $s2, 0x64
    ctx->r1 = SIGNED(ctx->r18) < 0X64 ? 1 : 0;
    // 0x800381EC: bnel        $at, $zero, L_80038298
    if (ctx->r1 != 0) {
        // 0x800381F0: addiu       $v0, $zero, 0xA
        ctx->r2 = ADD32(0, 0XA);
            goto L_80038298;
    }
    goto skip_7;
    // 0x800381F0: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    skip_7:
    // 0x800381F4: slti        $at, $s2, 0x3E8
    ctx->r1 = SIGNED(ctx->r18) < 0X3E8 ? 1 : 0;
    // 0x800381F8: bne         $at, $zero, L_80038248
    if (ctx->r1 != 0) {
        // 0x800381FC: addiu       $v0, $zero, 0x3E8
        ctx->r2 = ADD32(0, 0X3E8);
            goto L_80038248;
    }
    // 0x800381FC: addiu       $v0, $zero, 0x3E8
    ctx->r2 = ADD32(0, 0X3E8);
    // 0x80038200: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80038204: bne         $v0, $zero, L_80038210
    if (ctx->r2 != 0) {
        // 0x80038208: nop
    
            goto L_80038210;
    }
    // 0x80038208: nop

    // 0x8003820C: break       7
    do_break(2147713548);
L_80038210:
    // 0x80038210: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80038214: bne         $v0, $at, L_80038228
    if (ctx->r2 != ctx->r1) {
        // 0x80038218: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80038228;
    }
    // 0x80038218: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8003821C: bne         $s2, $at, L_80038228
    if (ctx->r18 != ctx->r1) {
        // 0x80038220: nop
    
            goto L_80038228;
    }
    // 0x80038220: nop

    // 0x80038224: break       6
    do_break(2147713572);
L_80038228:
    // 0x80038228: mfhi        $s2
    ctx->r18 = hi;
    // 0x8003822C: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x80038230: mflo        $t9
    ctx->r25 = lo;
    // 0x80038234: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80038238: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8003823C: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x80038240: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80038244: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80038248:
    // 0x80038248: addiu       $v0, $zero, 0x64
    ctx->r2 = ADD32(0, 0X64);
    // 0x8003824C: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80038250: bne         $v0, $zero, L_8003825C
    if (ctx->r2 != 0) {
        // 0x80038254: nop
    
            goto L_8003825C;
    }
    // 0x80038254: nop

    // 0x80038258: break       7
    do_break(2147713624);
L_8003825C:
    // 0x8003825C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80038260: bne         $v0, $at, L_80038274
    if (ctx->r2 != ctx->r1) {
        // 0x80038264: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80038274;
    }
    // 0x80038264: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80038268: bne         $s2, $at, L_80038274
    if (ctx->r18 != ctx->r1) {
        // 0x8003826C: nop
    
            goto L_80038274;
    }
    // 0x8003826C: nop

    // 0x80038270: break       6
    do_break(2147713648);
L_80038274:
    // 0x80038274: mfhi        $s2
    ctx->r18 = hi;
    // 0x80038278: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8003827C: mflo        $t9
    ctx->r25 = lo;
    // 0x80038280: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x80038284: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80038288: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x8003828C: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x80038290: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80038294: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
L_80038298:
    // 0x80038298: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x8003829C: bne         $v0, $zero, L_800382A8
    if (ctx->r2 != 0) {
        // 0x800382A0: nop
    
            goto L_800382A8;
    }
    // 0x800382A0: nop

    // 0x800382A4: break       7
    do_break(2147713700);
L_800382A8:
    // 0x800382A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800382AC: bne         $v0, $at, L_800382C0
    if (ctx->r2 != ctx->r1) {
        // 0x800382B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800382C0;
    }
    // 0x800382B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800382B4: bne         $s2, $at, L_800382C0
    if (ctx->r18 != ctx->r1) {
        // 0x800382B8: nop
    
            goto L_800382C0;
    }
    // 0x800382B8: nop

    // 0x800382BC: break       6
    do_break(2147713724);
L_800382C0:
    // 0x800382C0: mfhi        $s2
    ctx->r18 = hi;
    // 0x800382C4: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x800382C8: mflo        $t9
    ctx->r25 = lo;
    // 0x800382CC: addiu       $t8, $t9, 0x30
    ctx->r24 = ADD32(ctx->r25, 0X30);
    // 0x800382D0: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800382D4: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x800382D8: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
    // 0x800382DC: sb          $t9, 0x1($s1)
    MEM_B(0X1, ctx->r17) = ctx->r25;
    // 0x800382E0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800382E4: or          $s2, $t7, $zero
    ctx->r18 = ctx->r15 | 0;
    // 0x800382E8: lw          $t7, 0x14($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14);
    // 0x800382EC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800382F0: subu        $t6, $s1, $t8
    ctx->r14 = SUB32(ctx->r17, ctx->r24);
    // 0x800382F4: subu        $t9, $t6, $t7
    ctx->r25 = SUB32(ctx->r14, ctx->r15);
    // 0x800382F8: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
L_800382FC:
    // 0x800382FC: lw          $t8, 0x30($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X30);
    // 0x80038300: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80038304: andi        $t6, $t8, 0x14
    ctx->r14 = ctx->r24 & 0X14;
    // 0x80038308: bnel        $t6, $at, L_8003834C
    if (ctx->r14 != ctx->r1) {
        // 0x8003830C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003834C;
    }
    goto skip_8;
    // 0x8003830C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x80038310: lw          $t7, 0xC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XC);
    // 0x80038314: lw          $t9, 0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14);
    // 0x80038318: lw          $t6, 0x18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18);
    // 0x8003831C: lw          $v1, 0x28($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X28);
    // 0x80038320: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80038324: lw          $t9, 0x1C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X1C);
    // 0x80038328: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x8003832C: lw          $t6, 0x20($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X20);
    // 0x80038330: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x80038334: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x80038338: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8003833C: beq         $at, $zero, L_80038348
    if (ctx->r1 == 0) {
        // 0x80038340: subu        $t7, $v1, $v0
        ctx->r15 = SUB32(ctx->r3, ctx->r2);
            goto L_80038348;
    }
    // 0x80038340: subu        $t7, $v1, $v0
    ctx->r15 = SUB32(ctx->r3, ctx->r2);
    // 0x80038344: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
L_80038348:
    // 0x80038348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003834C:
    // 0x8003834C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038350: jr          $ra
    // 0x80038354: nop

    return;
    // 0x80038354: nop

    // 0x80038358: jr          $ra
    // 0x8003835C: nop

    return;
    // 0x8003835C: nop

;}

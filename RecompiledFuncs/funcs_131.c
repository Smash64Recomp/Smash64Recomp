#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void efManagerDamageCoinMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80100ACC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80100AD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80100AD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80100AD8: jal         0x800FD4B8
    // 0x80100ADC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80100ADC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x80100AE0: bne         $v0, $zero, L_80100AF0
    if (ctx->r2 != 0) {
        // 0x80100AE4: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80100AF0;
    }
    // 0x80100AE4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80100AE8: b           L_80100BDC
    // 0x80100AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100BDC;
    // 0x80100AEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100AF0:
    // 0x80100AF0: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x80100AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80100AF8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80100AFC: jal         0x80009968
    // 0x80100B00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80100B00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80100B04: bne         $v0, $zero, L_80100B1C
    if (ctx->r2 != 0) {
        // 0x80100B08: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80100B1C;
    }
    // 0x80100B08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80100B0C: jal         0x800FD4F8
    // 0x80100B10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x80100B10: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80100B14: b           L_80100BDC
    // 0x80100B18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100BDC;
    // 0x80100B18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80100B1C:
    // 0x80100B1C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80100B20: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80100B24: addiu       $a1, $zero, 0x60
    ctx->r5 = ADD32(0, 0X60);
    // 0x80100B28: sw          $t6, 0x84($a2)
    MEM_W(0X84, ctx->r6) = ctx->r14;
    // 0x80100B2C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    // 0x80100B30: jal         0x800CE9E8
    // 0x80100B34: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x80100B34: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    after_3:
    // 0x80100B38: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80100B3C: beq         $v0, $zero, L_80100BCC
    if (ctx->r2 == 0) {
        // 0x80100B40: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80100BCC;
    }
    // 0x80100B40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80100B44: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80100B48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80100B4C: jal         0x800CE1DC
    // 0x80100B50: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x80100B50: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_4:
    // 0x80100B54: beq         $v0, $zero, L_80100BB8
    if (ctx->r2 == 0) {
        // 0x80100B58: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_80100BB8;
    }
    // 0x80100B58: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x80100B5C: lui         $t7, 0x8010
    ctx->r15 = S32(0X8010 << 16);
    // 0x80100B60: addiu       $t7, $t7, 0xA58
    ctx->r15 = ADD32(ctx->r15, 0XA58);
    // 0x80100B64: sw          $a2, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r6;
    // 0x80100B68: sw          $t7, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r15;
    // 0x80100B6C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80100B70: jal         0x800CEA14
    // 0x80100B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x80100B74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80100B78: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80100B7C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80100B80: lhu         $t8, 0x2A($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X2A);
    // 0x80100B84: bnel        $t8, $zero, L_80100B98
    if (ctx->r24 != 0) {
        // 0x80100B88: sw          $v1, 0x28($t9)
        MEM_W(0X28, ctx->r25) = ctx->r3;
            goto L_80100B98;
    }
    goto skip_0;
    // 0x80100B88: sw          $v1, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r3;
    skip_0:
    // 0x80100B8C: b           L_80100BDC
    // 0x80100B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80100BDC;
    // 0x80100B90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80100B94: sw          $v1, 0x28($t9)
    MEM_W(0X28, ctx->r25) = ctx->r3;
L_80100B98:
    // 0x80100B98: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x80100B9C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80100BA0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x80100BA4: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x80100BA8: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x80100BAC: lw          $t2, 0x8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X8);
    // 0x80100BB0: b           L_80100BD8
    // 0x80100BB4: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
        goto L_80100BD8;
    // 0x80100BB4: sw          $t2, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r10;
L_80100BB8:
    // 0x80100BB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80100BBC: jal         0x800FDB3C
    // 0x80100BC0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_6;
    // 0x80100BC0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_6:
    // 0x80100BC4: b           L_80100BD8
    // 0x80100BC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_80100BD8;
    // 0x80100BC8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80100BCC:
    // 0x80100BCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80100BD0: jal         0x800FDB3C
    // 0x80100BD4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_7;
    // 0x80100BD4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_7:
L_80100BD8:
    // 0x80100BD8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_80100BDC:
    // 0x80100BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80100BE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80100BE4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80100BE8: jr          $ra
    // 0x80100BEC: nop

    return;
    // 0x80100BEC: nop

;}
RECOMP_FUNC void mnMessageMakeWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132028: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013202C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132030: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132034: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132038: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8013203C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132040: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132044: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132048: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013204C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132050: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132054: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132058: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013205C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132060: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132064: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132068: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013206C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132070: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132074: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132078: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013207C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132080: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132084: jal         0x8000B93C
    // 0x80132088: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132088: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013208C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132090: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132094: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132098: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013209C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801320A0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801320A4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801320A8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801320AC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801320B0: jal         0x80007080
    // 0x801320B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801320B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801320B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801320BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801320C0: jr          $ra
    // 0x801320C4: nop

    return;
    // 0x801320C4: nop

;}
RECOMP_FUNC void func_ovl2_80107B30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107B30: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80107B34: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80107B38: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    // 0x80107B3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107B40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80107B44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80107B48: lwc1        $f4, 0xAF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XAF4);
    // 0x80107B4C: lwc1        $f6, 0x74($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X74);
    // 0x80107B50: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80107B54: nop

    // 0x80107B58: bc1fl       L_80107B94
    if (!c1cs) {
        // 0x80107B5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80107B94;
    }
    goto skip_0;
    // 0x80107B5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80107B60: lw          $t6, 0x24($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X24);
    // 0x80107B64: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80107B68: addiu       $t9, $t9, 0x2EB4
    ctx->r25 = ADD32(ctx->r25, 0X2EB4);
    // 0x80107B6C: lbu         $t7, 0x54($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X54);
    // 0x80107B70: bnel        $t7, $zero, L_80107B94
    if (ctx->r15 != 0) {
        // 0x80107B74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80107B94;
    }
    goto skip_1;
    // 0x80107B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80107B78: lw          $t8, 0x3C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X3C);
    // 0x80107B7C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80107B80: jal         0x80106A40
    // 0x80107B84: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    grSectorArwingAddAnim(rdram, ctx);
        goto after_0;
    // 0x80107B84: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_0:
    // 0x80107B88: jal         0x800269C0
    // 0x80107B8C: addiu       $a0, $zero, 0x10B
    ctx->r4 = ADD32(0, 0X10B);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80107B8C: addiu       $a0, $zero, 0x10B
    ctx->r4 = ADD32(0, 0X10B);
    after_1:
    // 0x80107B90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80107B94:
    // 0x80107B94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107B98: jr          $ra
    // 0x80107B9C: nop

    return;
    // 0x80107B9C: nop

;}
RECOMP_FUNC void grPupupuWhispyLeavesMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105B18: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80105B1C: lw          $a0, 0x1404($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1404);
    // 0x80105B20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80105B24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105B28: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80105B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80105B30: jal         0x800CE9E8
    // 0x80105B34: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x80105B34: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_0:
    // 0x80105B38: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80105B3C: beq         $v0, $zero, L_80105BD4
    if (ctx->r2 == 0) {
        // 0x80105B40: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80105BD4;
    }
    // 0x80105B40: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80105B44: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80105B48: jal         0x800CE1DC
    // 0x80105B4C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x80105B4C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80105B50: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80105B54: bne         $v0, $zero, L_80105B6C
    if (ctx->r2 != 0) {
        // 0x80105B58: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80105B6C;
    }
    // 0x80105B58: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80105B5C: jal         0x800CEA40
    // 0x80105B60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    lbParticleEjectStruct(rdram, ctx);
        goto after_2;
    // 0x80105B60: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_2:
    // 0x80105B64: b           L_80105BD4
    // 0x80105B68: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
        goto L_80105BD4;
    // 0x80105B68: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
L_80105B6C:
    // 0x80105B6C: jal         0x800CEA14
    // 0x80105B70: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    LBParticleProcessStruct(rdram, ctx);
        goto after_3;
    // 0x80105B70: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_3:
    // 0x80105B74: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80105B78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80105B7C: addiu       $a0, $a0, 0x13F0
    ctx->r4 = ADD32(ctx->r4, 0X13F0);
    // 0x80105B80: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x80105B84: bnel        $t6, $zero, L_80105B98
    if (ctx->r14 != 0) {
        // 0x80105B88: lb          $t7, 0x2A($a0)
        ctx->r15 = MEM_B(ctx->r4, 0X2A);
            goto L_80105B98;
    }
    goto skip_0;
    // 0x80105B88: lb          $t7, 0x2A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X2A);
    skip_0:
    // 0x80105B8C: b           L_80105BD4
    // 0x80105B90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80105BD4;
    // 0x80105B90: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80105B94: lb          $t7, 0x2A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X2A);
L_80105B98:
    // 0x80105B98: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80105B9C: addiu       $v0, $v0, -0x1700
    ctx->r2 = ADD32(ctx->r2, -0X1700);
    // 0x80105BA0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80105BA4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x80105BA8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80105BAC: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x80105BB0: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80105BB4: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
    // 0x80105BB8: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x80105BBC: sw          $t1, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r9;
    // 0x80105BC0: lb          $t2, 0x2A($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X2A);
    // 0x80105BC4: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x80105BC8: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x80105BCC: lwc1        $f4, 0xC($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80105BD0: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
L_80105BD4:
    // 0x80105BD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105BD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80105BDC: sw          $v1, 0x1408($at)
    MEM_W(0X1408, ctx->r1) = ctx->r3;
    // 0x80105BE0: jr          $ra
    // 0x80105BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80105BE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void syVectorRotateAbout3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019438: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001943C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80019440: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80019444: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80019448: lwc1        $f0, 0x4($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X4);
    // 0x8001944C: lwc1        $f2, 0x8($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019450: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80019454: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80019458: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8001945C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80019460: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80019464: jal         0x80033510
    // 0x80019468: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80019468: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x8001946C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80019470: jal         0x800303F0
    // 0x80019474: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x80019474: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80019478: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x8001947C: jal         0x80035CD0
    // 0x80019480: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80019480: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_2:
    // 0x80019484: lwc1        $f14, 0x3C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80019488: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8001948C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80019490: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x80019494: c.eq.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl == ctx->f8.fl;
    // 0x80019498: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8001949C: bc1tl       L_800194F0
    if (c1cs) {
        // 0x800194A0: lwc1        $f2, 0x0($a0)
        ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
            goto L_800194F0;
    }
    goto skip_0;
    // 0x800194A0: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x800194A4: lwc1        $f4, 0x4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800194A8: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800194AC: div.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800194B0: div.s       $f22, $f10, $f14
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f22.fl = DIV_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800194B4: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x800194B8: lwc1        $f12, 0x4($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800194BC: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800194C0: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800194C4: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800194C8: mul.s       $f8, $f12, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x800194CC: swc1        $f22, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f22.u32l;
    // 0x800194D0: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800194D4: sub.s       $f20, $f8, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800194D8: mul.s       $f6, $f12, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800194DC: nop

    // 0x800194E0: mul.s       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x800194E4: b           L_800194F8
    // 0x800194E8: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
        goto L_800194F8;
    // 0x800194E8: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800194EC: lwc1        $f2, 0x0($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X0);
L_800194F0:
    // 0x800194F0: lwc1        $f20, 0x4($a0)
    ctx->f20.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800194F4: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
L_800194F8:
    // 0x800194F8: mul.s       $f4, $f2, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800194FC: lwc1        $f22, 0x0($a1)
    ctx->f22.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80019500: mul.s       $f10, $f18, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x80019504: sub.s       $f16, $f4, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80019508: mul.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8001950C: lwc1        $f10, 0x2C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80019510: mul.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f14.fl);
    // 0x80019514: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80019518: mul.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001951C: nop

    // 0x80019520: mul.s       $f6, $f20, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f10.fl);
    // 0x80019524: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80019528: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8001952C: nop

    // 0x80019530: mul.s       $f4, $f20, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80019534: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80019538: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x8001953C: nop

    // 0x80019540: mul.s       $f10, $f12, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f22.fl);
    // 0x80019544: add.s       $f20, $f8, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80019548: neg.s       $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = -ctx->f2.fl;
    // 0x8001954C: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80019550: mul.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x80019554: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80019558: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8001955C: mul.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x80019560: c.eq.s      $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f14.fl == ctx->f10.fl;
    // 0x80019564: nop

    // 0x80019568: bc1t        L_800195A0
    if (c1cs) {
        // 0x8001956C: add.s       $f12, $f4, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
            goto L_800195A0;
    }
    // 0x8001956C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80019570: mul.s       $f8, $f20, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80019574: neg.s       $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = -ctx->f20.fl;
    // 0x80019578: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x8001957C: mul.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f2.fl);
    // 0x80019580: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80019584: mul.s       $f8, $f10, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80019588: nop

    // 0x8001958C: mul.s       $f4, $f12, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80019590: swc1        $f6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f6.u32l;
    // 0x80019594: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80019598: b           L_800195AC
    // 0x8001959C: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
        goto L_800195AC;
    // 0x8001959C: swc1        $f6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f6.u32l;
L_800195A0:
    // 0x800195A0: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x800195A4: swc1        $f20, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f20.u32l;
    // 0x800195A8: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
L_800195AC:
    // 0x800195AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800195B0: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800195B4: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800195B8: jr          $ra
    // 0x800195BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800195BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void syMatrixTraRotRpyRSca(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001C588: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001C58C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001C590: lwc1        $f0, -0x1C40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C40);
    // 0x8001C594: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8001C598: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8001C59C: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8001C5A0: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001C5A4: lwc1        $f4, 0x60($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X60);
    // 0x8001C5A8: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8001C5AC: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001C5B0: addiu       $t4, $t4, -0x46B0
    ctx->r12 = ADD32(ctx->r12, -0X46B0);
    // 0x8001C5B4: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8001C5B8: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8001C5BC: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x8001C5C0: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8001C5C4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001C5C8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001C5CC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001C5D0: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8001C5D4: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x8001C5D8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8001C5DC: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8001C5E0: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x8001C5E4: andi        $t7, $a1, 0x7FF
    ctx->r15 = ctx->r5 & 0X7FF;
    // 0x8001C5E8: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001C5EC: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8001C5F0: andi        $t6, $a1, 0x800
    ctx->r14 = ctx->r5 & 0X800;
    // 0x8001C5F4: mfc1        $v1, $f18
    ctx->r3 = (int32_t)ctx->f18.u32l;
    // 0x8001C5F8: lhu         $t2, 0x0($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X0);
    // 0x8001C5FC: beq         $t6, $zero, L_8001C608
    if (ctx->r14 == 0) {
        // 0x8001C600: trunc.w.s   $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
            goto L_8001C608;
    }
    // 0x8001C600: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001C604: negu        $t2, $t2
    ctx->r10 = SUB32(0, ctx->r10);
L_8001C608:
    // 0x8001C608: addiu       $v0, $a1, 0x400
    ctx->r2 = ADD32(ctx->r5, 0X400);
    // 0x8001C60C: andi        $t7, $v0, 0x7FF
    ctx->r15 = ctx->r2 & 0X7FF;
    // 0x8001C610: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8001C614: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x8001C618: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x8001C61C: beq         $t6, $zero, L_8001C628
    if (ctx->r14 == 0) {
        // 0x8001C620: lhu         $t0, 0x0($t9)
        ctx->r8 = MEM_HU(ctx->r25, 0X0);
            goto L_8001C628;
    }
    // 0x8001C620: lhu         $t0, 0x0($t9)
    ctx->r8 = MEM_HU(ctx->r25, 0X0);
    // 0x8001C624: negu        $t0, $t0
    ctx->r8 = SUB32(0, ctx->r8);
L_8001C628:
    // 0x8001C628: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x8001C62C: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x8001C630: andi        $t8, $a1, 0x7FF
    ctx->r24 = ctx->r5 & 0X7FF;
    // 0x8001C634: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8001C638: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8001C63C: andi        $t7, $a1, 0x800
    ctx->r15 = ctx->r5 & 0X800;
    // 0x8001C640: beq         $t7, $zero, L_8001C64C
    if (ctx->r15 == 0) {
        // 0x8001C644: lhu         $t1, 0x0($t6)
        ctx->r9 = MEM_HU(ctx->r14, 0X0);
            goto L_8001C64C;
    }
    // 0x8001C644: lhu         $t1, 0x0($t6)
    ctx->r9 = MEM_HU(ctx->r14, 0X0);
    // 0x8001C648: negu        $t1, $t1
    ctx->r9 = SUB32(0, ctx->r9);
L_8001C64C:
    // 0x8001C64C: addiu       $v0, $a1, 0x400
    ctx->r2 = ADD32(ctx->r5, 0X400);
    // 0x8001C650: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x8001C654: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8001C658: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8001C65C: andi        $t7, $v0, 0x800
    ctx->r15 = ctx->r2 & 0X800;
    // 0x8001C660: beq         $t7, $zero, L_8001C66C
    if (ctx->r15 == 0) {
        // 0x8001C664: lhu         $a2, 0x0($t6)
        ctx->r6 = MEM_HU(ctx->r14, 0X0);
            goto L_8001C66C;
    }
    // 0x8001C664: lhu         $a2, 0x0($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X0);
    // 0x8001C668: negu        $a2, $a2
    ctx->r6 = SUB32(0, ctx->r6);
L_8001C66C:
    // 0x8001C66C: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8001C670: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001C674: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x8001C678: andi        $a3, $v0, 0xFFFF
    ctx->r7 = ctx->r2 & 0XFFFF;
    // 0x8001C67C: andi        $t9, $a3, 0x7FF
    ctx->r25 = ctx->r7 & 0X7FF;
    // 0x8001C680: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8001C684: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8001C688: andi        $t8, $a3, 0x800
    ctx->r24 = ctx->r7 & 0X800;
    // 0x8001C68C: beq         $t8, $zero, L_8001C698
    if (ctx->r24 == 0) {
        // 0x8001C690: lhu         $a1, 0x0($t7)
        ctx->r5 = MEM_HU(ctx->r15, 0X0);
            goto L_8001C698;
    }
    // 0x8001C690: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x8001C694: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
L_8001C698:
    // 0x8001C698: addiu       $v1, $a3, 0x400
    ctx->r3 = ADD32(ctx->r7, 0X400);
    // 0x8001C69C: andi        $t9, $v1, 0x7FF
    ctx->r25 = ctx->r3 & 0X7FF;
    // 0x8001C6A0: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8001C6A4: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8001C6A8: andi        $t8, $v1, 0x800
    ctx->r24 = ctx->r3 & 0X800;
    // 0x8001C6AC: beq         $t8, $zero, L_8001C6B8
    if (ctx->r24 == 0) {
        // 0x8001C6B0: lhu         $v0, 0x0($t7)
        ctx->r2 = MEM_HU(ctx->r15, 0X0);
            goto L_8001C6B8;
    }
    // 0x8001C6B0: lhu         $v0, 0x0($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X0);
    // 0x8001C6B4: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
L_8001C6B8:
    // 0x8001C6B8: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001C6BC: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8001C6C0: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C6C4: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x8001C6C8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8001C6CC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8001C6D0: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001C6D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8001C6D8: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x8001C6DC: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x8001C6E0: mflo        $t8
    ctx->r24 = lo;
    // 0x8001C6E4: sra         $t9, $t8, 14
    ctx->r25 = S32(SIGNED(ctx->r24) >> 14);
    // 0x8001C6E8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8001C6EC: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x8001C6F0: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8001C6F4: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001C6F8: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C6FC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8001C700: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8001C704: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8001C708: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C70C: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8001C710: sw          $t7, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r15;
    // 0x8001C714: multu       $a2, $a1
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C718: mflo        $t8
    ctx->r24 = lo;
    // 0x8001C71C: sra         $t9, $t8, 14
    ctx->r25 = S32(SIGNED(ctx->r24) >> 14);
    // 0x8001C720: nop

    // 0x8001C724: multu       $t9, $t3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C728: and         $t9, $t7, $v1
    ctx->r25 = ctx->r15 & ctx->r3;
    // 0x8001C72C: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C730: sra         $t8, $t6, 8
    ctx->r24 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8001C734: srl         $t6, $t8, 16
    ctx->r14 = S32(U32(ctx->r24) >> 16);
    // 0x8001C738: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8001C73C: sw          $t8, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r24;
    // 0x8001C740: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8001C744: lw          $t6, 0x4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4);
    // 0x8001C748: lw          $t8, 0x8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8);
    // 0x8001C74C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8001C750: negu        $t6, $t1
    ctx->r14 = SUB32(0, ctx->r9);
    // 0x8001C754: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C758: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8001C75C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8001C760: sw          $t8, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r24;
    // 0x8001C764: mflo        $t9
    ctx->r25 = lo;
    // 0x8001C768: sra         $t7, $t9, 7
    ctx->r15 = S32(SIGNED(ctx->r25) >> 7);
    // 0x8001C76C: sw          $t7, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r15;
    // 0x8001C770: multu       $t2, $t1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C774: and         $t8, $t7, $v1
    ctx->r24 = ctx->r15 & ctx->r3;
    // 0x8001C778: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8001C77C: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8001C780: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x8001C784: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    // 0x8001C788: mflo        $t3
    ctx->r11 = lo;
    // 0x8001C78C: sra         $t3, $t3, 15
    ctx->r11 = S32(SIGNED(ctx->r11) >> 15);
    // 0x8001C790: nop

    // 0x8001C794: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C798: mflo        $t7
    ctx->r15 = lo;
    // 0x8001C79C: sra         $t8, $t7, 14
    ctx->r24 = S32(SIGNED(ctx->r15) >> 14);
    // 0x8001C7A0: nop

    // 0x8001C7A4: multu       $t0, $a1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C7A8: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C7AC: sra         $t9, $t6, 14
    ctx->r25 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8001C7B0: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x8001C7B4: multu       $t7, $t5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C7B8: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C7BC: sra         $t8, $t6, 8
    ctx->r24 = S32(SIGNED(ctx->r14) >> 8);
    // 0x8001C7C0: sw          $t8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r24;
    // 0x8001C7C4: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C7C8: mflo        $t9
    ctx->r25 = lo;
    // 0x8001C7CC: sra         $t7, $t9, 14
    ctx->r15 = S32(SIGNED(ctx->r25) >> 14);
    // 0x8001C7D0: nop

    // 0x8001C7D4: multu       $t0, $v0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C7D8: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C7DC: sra         $t9, $t6, 14
    ctx->r25 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8001C7E0: addu        $t6, $t7, $t9
    ctx->r14 = ADD32(ctx->r15, ctx->r25);
    // 0x8001C7E4: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C7E8: and         $t6, $t8, $v1
    ctx->r14 = ctx->r24 & ctx->r3;
    // 0x8001C7EC: mflo        $t7
    ctx->r15 = lo;
    // 0x8001C7F0: sra         $t9, $t7, 8
    ctx->r25 = S32(SIGNED(ctx->r15) >> 8);
    // 0x8001C7F4: srl         $t7, $t9, 16
    ctx->r15 = S32(U32(ctx->r25) >> 16);
    // 0x8001C7F8: multu       $t2, $a2
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C7FC: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8001C800: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x8001C804: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x8001C808: lw          $t7, 0xC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC);
    // 0x8001C80C: lw          $t9, 0x8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8);
    // 0x8001C810: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8001C814: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x8001C818: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8001C81C: mflo        $t7
    ctx->r15 = lo;
    // 0x8001C820: sra         $t6, $t7, 14
    ctx->r14 = S32(SIGNED(ctx->r15) >> 14);
    // 0x8001C824: sw          $t9, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r25;
    // 0x8001C828: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C82C: mflo        $t8
    ctx->r24 = lo;
    // 0x8001C830: sra         $t9, $t8, 8
    ctx->r25 = S32(SIGNED(ctx->r24) >> 8);
    // 0x8001C834: sw          $t9, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r25;
    // 0x8001C838: multu       $t0, $t1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C83C: and         $t7, $t9, $v1
    ctx->r15 = ctx->r25 & ctx->r3;
    // 0x8001C840: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x8001C844: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8001C848: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8001C84C: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
    // 0x8001C850: mflo        $t3
    ctx->r11 = lo;
    // 0x8001C854: sra         $t3, $t3, 15
    ctx->r11 = S32(SIGNED(ctx->r11) >> 15);
    // 0x8001C858: nop

    // 0x8001C85C: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C860: mflo        $t9
    ctx->r25 = lo;
    // 0x8001C864: sra         $t7, $t9, 14
    ctx->r15 = S32(SIGNED(ctx->r25) >> 14);
    // 0x8001C868: nop

    // 0x8001C86C: multu       $t2, $a1
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C870: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C874: sra         $t8, $t6, 14
    ctx->r24 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8001C878: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001C87C: multu       $t9, $a3
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C880: mflo        $t4
    ctx->r12 = lo;
    // 0x8001C884: sra         $t4, $t4, 8
    ctx->r12 = S32(SIGNED(ctx->r12) >> 8);
    // 0x8001C888: nop

    // 0x8001C88C: multu       $t3, $a1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C890: mflo        $t6
    ctx->r14 = lo;
    // 0x8001C894: sra         $t7, $t6, 14
    ctx->r15 = S32(SIGNED(ctx->r14) >> 14);
    // 0x8001C898: nop

    // 0x8001C89C: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C8A0: mflo        $t8
    ctx->r24 = lo;
    // 0x8001C8A4: sra         $t9, $t8, 14
    ctx->r25 = S32(SIGNED(ctx->r24) >> 14);
    // 0x8001C8A8: subu        $t6, $t7, $t9
    ctx->r14 = SUB32(ctx->r15, ctx->r25);
    // 0x8001C8AC: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C8B0: and         $t8, $t4, $v1
    ctx->r24 = ctx->r12 & ctx->r3;
    // 0x8001C8B4: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x8001C8B8: mflo        $t5
    ctx->r13 = lo;
    // 0x8001C8BC: sra         $t5, $t5, 8
    ctx->r13 = S32(SIGNED(ctx->r13) >> 8);
    // 0x8001C8C0: srl         $t7, $t5, 16
    ctx->r15 = S32(U32(ctx->r13) >> 16);
    // 0x8001C8C4: multu       $t0, $a2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C8C8: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x8001C8CC: sw          $t9, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r25;
    // 0x8001C8D0: andi        $t8, $t5, 0xFFFF
    ctx->r24 = ctx->r13 & 0XFFFF;
    // 0x8001C8D4: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8001C8D8: sw          $t7, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r15;
    // 0x8001C8DC: mflo        $t9
    ctx->r25 = lo;
    // 0x8001C8E0: sra         $t6, $t9, 14
    ctx->r14 = S32(SIGNED(ctx->r25) >> 14);
    // 0x8001C8E4: nop

    // 0x8001C8E8: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001C8EC: mflo        $t8
    ctx->r24 = lo;
    // 0x8001C8F0: sra         $t7, $t8, 8
    ctx->r15 = S32(SIGNED(ctx->r24) >> 8);
    // 0x8001C8F4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8001C8F8: and         $t9, $t7, $v1
    ctx->r25 = ctx->r15 & ctx->r3;
    // 0x8001C8FC: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
    // 0x8001C900: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8001C904: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8001C908: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x8001C90C: sw          $t8, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r24;
    // 0x8001C910: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x8001C914: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8001C918: and         $t7, $t9, $v1
    ctx->r15 = ctx->r25 & ctx->r3;
    // 0x8001C91C: srl         $t6, $t8, 16
    ctx->r14 = S32(U32(ctx->r24) >> 16);
    // 0x8001C920: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8001C924: sw          $t8, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r24;
    // 0x8001C928: sw          $t9, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r25;
    // 0x8001C92C: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x8001C930: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8001C934: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x8001C938: andi        $t9, $t6, 0xFFFF
    ctx->r25 = ctx->r14 & 0XFFFF;
    // 0x8001C93C: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8001C940: sw          $t8, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r24;
    // 0x8001C944: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001C948: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8001C94C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x8001C950: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8001C954: nop

    // 0x8001C958: and         $t9, $t7, $v1
    ctx->r25 = ctx->r15 & ctx->r3;
    // 0x8001C95C: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x8001C960: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8001C964: sw          $t8, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r24;
    // 0x8001C968: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x8001C96C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8001C970: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8001C974: jr          $ra
    // 0x8001C978: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
    return;
    // 0x8001C978: sw          $t7, 0x3C($a0)
    MEM_W(0X3C, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void wpSamusChargeShotProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168BDC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80168BE0: lw          $v1, 0x2A8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2A8);
    // 0x80168BE4: beq         $v1, $zero, L_80168BF4
    if (ctx->r3 == 0) {
        // 0x80168BE8: nop
    
            goto L_80168BF4;
    }
    // 0x80168BE8: nop

    // 0x80168BEC: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x80168BF0: sw          $zero, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = 0;
L_80168BF4:
    // 0x80168BF4: jr          $ra
    // 0x80168BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80168BF8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
RECOMP_FUNC void syTaskmanStartTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000683C: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80006840: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80006844: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80006848: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8000684C: lw          $a1, 0x10($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X10);
    // 0x80006850: jal         0x80004950
    // 0x80006854: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    syTaskmanInitGeneralHeap(rdram, ctx);
        goto after_0;
    // 0x80006854: lw          $a0, 0xC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XC);
    after_0:
    // 0x80006858: lw          $a0, 0x40($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X40);
    // 0x8000685C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80006860: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80006864: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80006868: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x8000686C: jal         0x80004980
    // 0x80006870: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x80006870: sll         $a0, $a0, 6
    ctx->r4 = S32(ctx->r4 << 6);
    after_1:
    // 0x80006874: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80006878: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x8000687C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80006880: lw          $t7, 0x44($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X44);
    // 0x80006884: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80006888: lw          $v1, 0x44($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X44);
    // 0x8000688C: beql        $v1, $zero, L_800068BC
    if (ctx->r3 == 0) {
        // 0x80006890: sw          $zero, 0x30($sp)
        MEM_W(0X30, ctx->r29) = 0;
            goto L_800068BC;
    }
    goto skip_0;
    // 0x80006890: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    skip_0:
    // 0x80006894: lw          $t9, 0x48($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X48);
    // 0x80006898: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8000689C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800068A0: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800068A4: mflo        $a0
    ctx->r4 = lo;
    // 0x800068A8: jal         0x80004980
    // 0x800068AC: nop

    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x800068AC: nop

    after_2:
    // 0x800068B0: b           L_800068BC
    // 0x800068B4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
        goto L_800068BC;
    // 0x800068B4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800068B8: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
L_800068BC:
    // 0x800068BC: lw          $t0, 0x48($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X48);
    // 0x800068C0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800068C4: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    // 0x800068C8: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x800068CC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800068D0: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x800068D4: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x800068D8: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x800068DC: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x800068E0: jal         0x80004980
    // 0x800068E4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    syTaskmanMalloc(rdram, ctx);
        goto after_3;
    // 0x800068E4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_3:
    // 0x800068E8: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800068EC: lw          $t2, 0x50($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X50);
    // 0x800068F0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800068F4: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x800068F8: lw          $t4, 0x54($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X54);
    // 0x800068FC: lw          $t3, 0x58($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X58);
    // 0x80006900: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006904: mflo        $a0
    ctx->r4 = lo;
    // 0x80006908: jal         0x80004980
    // 0x8000690C: nop

    syTaskmanMalloc(rdram, ctx);
        goto after_4;
    // 0x8000690C: nop

    after_4:
    // 0x80006910: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80006914: lw          $t5, 0x54($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X54);
    // 0x80006918: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x8000691C: sw          $t5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r13;
    // 0x80006920: lw          $t6, 0x58($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X58);
    // 0x80006924: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x80006928: lw          $a0, 0x5C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X5C);
    // 0x8000692C: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80006930: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80006934: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x80006938: jal         0x80004980
    // 0x8000693C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    syTaskmanMalloc(rdram, ctx);
        goto after_5;
    // 0x8000693C: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    after_5:
    // 0x80006940: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80006944: lw          $t7, 0x5C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X5C);
    // 0x80006948: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x8000694C: jal         0x80010734
    // 0x80006950: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    gcSetMatrixFuncList(rdram, ctx);
        goto after_6;
    // 0x80006950: lw          $a0, 0x60($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X60);
    after_6:
    // 0x80006954: lw          $t8, 0x64($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X64);
    // 0x80006958: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8000695C: sw          $t8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r24;
    // 0x80006960: lw          $a0, 0x68($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X68);
    // 0x80006964: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80006968: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x8000696C: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x80006970: jal         0x80004980
    // 0x80006974: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    syTaskmanMalloc(rdram, ctx);
        goto after_7;
    // 0x80006974: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_7:
    // 0x80006978: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8000697C: lw          $t9, 0x68($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X68);
    // 0x80006980: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80006984: sw          $t9, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r25;
    // 0x80006988: lw          $a0, 0x6C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X6C);
    // 0x8000698C: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80006990: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x80006994: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x80006998: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8000699C: addu        $a0, $a0, $at
    ctx->r4 = ADD32(ctx->r4, ctx->r1);
    // 0x800069A0: jal         0x80004980
    // 0x800069A4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    syTaskmanMalloc(rdram, ctx);
        goto after_8;
    // 0x800069A4: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    after_8:
    // 0x800069A8: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800069AC: lw          $t0, 0x6C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X6C);
    // 0x800069B0: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800069B4: sw          $t0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r8;
    // 0x800069B8: lw          $t2, 0x70($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X70);
    // 0x800069BC: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x800069C0: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800069C4: mflo        $a0
    ctx->r4 = lo;
    // 0x800069C8: jal         0x80004980
    // 0x800069CC: nop

    syTaskmanMalloc(rdram, ctx);
        goto after_9;
    // 0x800069CC: nop

    after_9:
    // 0x800069D0: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x800069D4: lw          $t3, 0x70($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X70);
    // 0x800069D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800069DC: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x800069E0: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x800069E4: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x800069E8: lw          $t6, 0x78($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X78);
    // 0x800069EC: lw          $t5, 0x7C($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X7C);
    // 0x800069F0: multu       $t5, $t6
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800069F4: mflo        $a0
    ctx->r4 = lo;
    // 0x800069F8: jal         0x80004980
    // 0x800069FC: nop

    syTaskmanMalloc(rdram, ctx);
        goto after_10;
    // 0x800069FC: nop

    after_10:
    // 0x80006A00: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x80006A04: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80006A08: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80006A0C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x80006A10: lw          $t8, 0x7C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X7C);
    // 0x80006A14: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x80006A18: lw          $t0, 0x80($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X80);
    // 0x80006A1C: lw          $t9, 0x84($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X84);
    // 0x80006A20: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80006A24: mflo        $a0
    ctx->r4 = lo;
    // 0x80006A28: jal         0x80004980
    // 0x80006A2C: nop

    syTaskmanMalloc(rdram, ctx);
        goto after_11;
    // 0x80006A2C: nop

    after_11:
    // 0x80006A30: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x80006A34: lw          $t1, 0x80($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X80);
    // 0x80006A38: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80006A3C: sw          $t1, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r9;
    // 0x80006A40: lw          $t2, 0x84($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X84);
    // 0x80006A44: jal         0x8000A6E0
    // 0x80006A48: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    gcSetupObjman(rdram, ctx);
        goto after_12;
    // 0x80006A48: sw          $t2, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r10;
    after_12:
    // 0x80006A4C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006A50: addiu       $v0, $v0, 0x65F8
    ctx->r2 = ADD32(ctx->r2, 0X65F8);
    // 0x80006A54: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x80006A58: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x80006A5C: addiu       $t3, $t3, 0x6350
    ctx->r11 = ADD32(ctx->r11, 0X6350);
    // 0x80006A60: addiu       $t4, $t4, 0x63A0
    ctx->r12 = ADD32(ctx->r12, 0X63A0);
    // 0x80006A64: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x80006A68: sw          $t4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r12;
    // 0x80006A6C: lw          $a1, 0x88($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X88);
    // 0x80006A70: jal         0x80006548
    // 0x80006A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syTaskmanLoadScene(rdram, ctx);
        goto after_13;
    // 0x80006A74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80006A78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80006A7C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80006A80: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x80006A84: jr          $ra
    // 0x80006A88: nop

    return;
    // 0x80006A88: nop

;}
RECOMP_FUNC void ftBossDeadCenterProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015ADC0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015ADC4: lh          $t6, 0xB18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB18);
    // 0x8015ADC8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8015ADCC: sh          $t7, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r15;
    // 0x8015ADD0: lh          $t8, 0xB18($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XB18);
    // 0x8015ADD4: bne         $t8, $zero, L_8015ADE0
    if (ctx->r24 != 0) {
        // 0x8015ADD8: nop
    
            goto L_8015ADE0;
    }
    // 0x8015ADD8: nop

    // 0x8015ADDC: sw          $zero, 0x9E0($v0)
    MEM_W(0X9E0, ctx->r2) = 0;
L_8015ADE0:
    // 0x8015ADE0: jr          $ra
    // 0x8015ADE4: nop

    return;
    // 0x8015ADE4: nop

;}
RECOMP_FUNC void mnCharactersMoveFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133754: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133758: mtc1        $a1, $f14
    ctx->f14.u32l = ctx->r5;
    // 0x8013375C: lwc1        $f4, 0x65C8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X65C8);
    // 0x80133760: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80133764: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133768: mul.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f4.fl);
    // 0x8013376C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80133770: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80133774: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133778: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013377C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80133780: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80133784: div.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80133788: jal         0x800303F0
    // 0x8013378C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x8013378C: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_0:
    // 0x80133790: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133794: lwc1        $f10, 0x65CC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X65CC);
    // 0x80133798: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8013379C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801337A0: jal         0x80035CD0
    // 0x801337A4: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x801337A4: swc1        $f16, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f16.u32l;
    after_1:
    // 0x801337A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801337AC: lwc1        $f18, 0x65D0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X65D0);
    // 0x801337B0: lui         $at, 0x43B9
    ctx->r1 = S32(0X43B9 << 16);
    // 0x801337B4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801337B8: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801337BC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x801337C0: jal         0x8001863C
    // 0x801337C4: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    syUtilsArcTan2(rdram, ctx);
        goto after_2;
    // 0x801337C4: swc1        $f4, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f4.u32l;
    after_2:
    // 0x801337C8: add.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x801337CC: jal         0x800303F0
    // 0x801337D0: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_3;
    // 0x801337D0: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x801337D4: lui         $at, 0x43B9
    ctx->r1 = S32(0X43B9 << 16);
    // 0x801337D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801337DC: nop

    // 0x801337E0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x801337E4: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x801337E8: jal         0x80035CD0
    // 0x801337EC: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    __cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x801337EC: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_4:
    // 0x801337F0: lui         $at, 0x43B9
    ctx->r1 = S32(0X43B9 << 16);
    // 0x801337F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801337F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801337FC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80133800: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80133804: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80133808: jal         0x8001863C
    // 0x8013380C: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    syUtilsArcTan2(rdram, ctx);
        goto after_5;
    // 0x8013380C: swc1        $f16, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f16.u32l;
    after_5:
    // 0x80133810: add.s       $f12, $f0, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x80133814: jal         0x800303F0
    // 0x80133818: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_6;
    // 0x80133818: swc1        $f12, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f12.u32l;
    after_6:
    // 0x8013381C: swc1        $f0, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->f0.u32l;
    // 0x80133820: jal         0x80035CD0
    // 0x80133824: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    __cosf_recomp(rdram, ctx);
        goto after_7;
    // 0x80133824: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x80133828: swc1        $f0, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = ctx->f0.u32l;
    // 0x8013382C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133830: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80133834: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80133838: jr          $ra
    // 0x8013383C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013383C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itLGunWeaponAmmoMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175A60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80175A64: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80175A68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175A6C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80175A70: addiu       $a1, $a1, -0x63DC
    ctx->r5 = ADD32(ctx->r5, -0X63DC);
    // 0x80175A74: jal         0x801655C8
    // 0x80175A78: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x80175A78: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80175A7C: bne         $v0, $zero, L_80175A8C
    if (ctx->r2 != 0) {
        // 0x80175A80: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80175A8C;
    }
    // 0x80175A80: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80175A84: b           L_80175AC8
    // 0x80175A88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80175AC8;
    // 0x80175A88: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80175A8C:
    // 0x80175A8C: lw          $v0, 0x84($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84);
    // 0x80175A90: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80175A94: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80175A98: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80175A9C: lwc1        $f12, 0x24($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80175AA0: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80175AA4: nop

    // 0x80175AA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80175AAC: mul.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80175AB0: swc1        $f14, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f14.u32l;
    // 0x80175AB4: jal         0x8001863C
    // 0x80175AB8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x80175AB8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80175ABC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80175AC0: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80175AC4: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
L_80175AC8:
    // 0x80175AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175ACC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80175AD0: jr          $ra
    // 0x80175AD4: nop

    return;
    // 0x80175AD4: nop

;}
RECOMP_FUNC void ftNessSpecialLwHitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801557D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801557DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801557E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801557E4: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x801557E8: beql        $t6, $zero, L_801557FC
    if (ctx->r14 == 0) {
        // 0x801557EC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801557FC;
    }
    goto skip_0;
    // 0x801557EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801557F0: jal         0x80155750
    // 0x801557F4: nop

    ftNessSpecialLwHoldSetStatus(rdram, ctx);
        goto after_0;
    // 0x801557F4: nop

    after_0:
    // 0x801557F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801557FC:
    // 0x801557FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80155800: jr          $ra
    // 0x80155804: nop

    return;
    // 0x80155804: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakePortraitShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801324F0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801324F4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801324F8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x801324FC: addiu       $t7, $t7, 0x7204
    ctx->r15 = ADD32(ctx->r15, 0X7204);
    // 0x80132500: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80132504: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132508: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013250C: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80132510: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
L_80132514:
    // 0x80132514: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132518: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x8013251C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132520: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132524: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132528: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x8013252C: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132530: bne         $t7, $t0, L_80132514
    if (ctx->r15 != ctx->r8) {
        // 0x80132534: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132514;
    }
    // 0x80132534: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132538: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013253C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132540: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132544: jal         0x80009968
    // 0x80132548: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132548: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013254C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132550: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132554: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80132558: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8013255C: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132560: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80132564: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132568: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8013256C: jal         0x80009DF4
    // 0x80132570: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132570: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132574: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132578: addiu       $a1, $a1, 0x2150
    ctx->r5 = ADD32(ctx->r5, 0X2150);
    // 0x8013257C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80132580: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132584: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132588: jal         0x80008188
    // 0x8013258C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x8013258C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132590: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132594: lw          $t2, 0x7E08($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X7E08);
    // 0x80132598: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x8013259C: addiu       $t3, $t3, 0x24D0
    ctx->r11 = ADD32(ctx->r11, 0X24D0);
    // 0x801325A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801325A4: jal         0x800CCFDC
    // 0x801325A8: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801325A8: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x801325AC: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x801325B0: bne         $at, $zero, L_801325C0
    if (ctx->r1 != 0) {
        // 0x801325B4: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801325C0;
    }
    // 0x801325B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801325B8: b           L_801325C4
    // 0x801325BC: addiu       $v1, $s1, -0x6
    ctx->r3 = ADD32(ctx->r17, -0X6);
        goto L_801325C4;
    // 0x801325BC: addiu       $v1, $s1, -0x6
    ctx->r3 = ADD32(ctx->r17, -0X6);
L_801325C0:
    // 0x801325C0: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
L_801325C4:
    // 0x801325C4: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x801325C8: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x801325CC: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801325D0: subu        $t4, $t4, $v1
    ctx->r12 = SUB32(ctx->r12, ctx->r3);
    // 0x801325D4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x801325D8: addu        $t4, $t4, $v1
    ctx->r12 = ADD32(ctx->r12, ctx->r3);
    // 0x801325DC: addiu       $t5, $t4, 0x19
    ctx->r13 = ADD32(ctx->r12, 0X19);
    // 0x801325E0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801325E4: slti        $at, $s1, 0x6
    ctx->r1 = SIGNED(ctx->r17) < 0X6 ? 1 : 0;
    // 0x801325E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801325EC: bne         $at, $zero, L_801325FC
    if (ctx->r1 != 0) {
        // 0x801325F0: swc1        $f6, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
            goto L_801325FC;
    }
    // 0x801325F0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x801325F4: b           L_80132600
    // 0x801325F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80132600;
    // 0x801325F8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801325FC:
    // 0x801325FC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80132600:
    // 0x80132600: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x80132604: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132608: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8013260C: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132610: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80132614: subu        $t0, $t0, $v1
    ctx->r8 = SUB32(ctx->r8, ctx->r3);
    // 0x80132618: addiu       $t7, $t0, 0x24
    ctx->r15 = ADD32(ctx->r8, 0X24);
    // 0x8013261C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80132620: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80132624: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132628: jal         0x801321CC
    // 0x8013262C: swc1        $f10, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f10.u32l;
    mnPlayers1PBonusSetPortraitWallpaperPosition(rdram, ctx);
        goto after_4;
    // 0x8013262C: swc1        $f10, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f10.u32l;
    after_4:
    // 0x80132630: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    // 0x80132634: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132638: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013263C: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80132640: jal         0x80009968
    // 0x80132644: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80132644: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80132648: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013264C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132650: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132654: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132658: addiu       $a1, $a1, 0x2430
    ctx->r5 = ADD32(ctx->r5, 0X2430);
    // 0x8013265C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132660: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80132664: jal         0x80009DF4
    // 0x80132668: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x80132668: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x8013266C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132670: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80132674: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132678: jal         0x80008188
    // 0x8013267C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x8013267C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x80132680: jal         0x80132390
    // 0x80132684: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PBonusGetFighterKind(rdram, ctx);
        goto after_8;
    // 0x80132684: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x80132688: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8013268C: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80132690: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132694: lw          $t1, 0x7E08($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X7E08);
    // 0x80132698: lw          $t9, 0x38($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X38);
    // 0x8013269C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801326A0: jal         0x800CCFDC
    // 0x801326A4: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_9;
    // 0x801326A4: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_9:
    // 0x801326A8: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x801326AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801326B0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x801326B4: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x801326B8: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801326BC: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x801326C0: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801326C4: jal         0x801321CC
    // 0x801326C8: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    mnPlayers1PBonusSetPortraitWallpaperPosition(rdram, ctx);
        goto after_10;
    // 0x801326C8: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    after_10:
    // 0x801326CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801326D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801326D4: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x801326D8: jal         0x80009968
    // 0x801326DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_11;
    // 0x801326DC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_11:
    // 0x801326E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801326E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801326E8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801326EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801326F0: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801326F4: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x801326F8: jal         0x80009DF4
    // 0x801326FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_12;
    // 0x801326FC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_12:
    // 0x80132700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132704: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80132708: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013270C: jal         0x80008188
    // 0x80132710: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_13;
    // 0x80132710: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x80132714: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132718: lw          $t7, 0x7E08($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7E08);
    // 0x8013271C: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80132720: addiu       $t6, $t6, 0xF68
    ctx->r14 = ADD32(ctx->r14, 0XF68);
    // 0x80132724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132728: jal         0x800CCFDC
    // 0x8013272C: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_14;
    // 0x8013272C: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    after_14:
    // 0x80132730: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132734: addiu       $t3, $zero, 0x5B
    ctx->r11 = ADD32(0, 0X5B);
    // 0x80132738: addiu       $t4, $zero, 0x41
    ctx->r12 = ADD32(0, 0X41);
    // 0x8013273C: andi        $t1, $t8, 0xFFDF
    ctx->r9 = ctx->r24 & 0XFFDF;
    // 0x80132740: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132744: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132748: addiu       $t5, $zero, 0x33
    ctx->r13 = ADD32(0, 0X33);
    // 0x8013274C: addiu       $t0, $zero, 0xC4
    ctx->r8 = ADD32(0, 0XC4);
    // 0x80132750: addiu       $t7, $zero, 0xB9
    ctx->r15 = ADD32(0, 0XB9);
    // 0x80132754: addiu       $t6, $zero, 0xA9
    ctx->r14 = ADD32(0, 0XA9);
    // 0x80132758: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x8013275C: sb          $t3, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r11;
    // 0x80132760: sb          $t4, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r12;
    // 0x80132764: sb          $t5, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r13;
    // 0x80132768: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x8013276C: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80132770: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x80132774: sw          $s1, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r17;
    // 0x80132778: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013277C: jal         0x801321CC
    // 0x80132780: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PBonusSetPortraitWallpaperPosition(rdram, ctx);
        goto after_15;
    // 0x80132780: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_15:
    // 0x80132784: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132788: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8013278C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80132790: jr          $ra
    // 0x80132794: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80132794: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void ifCommonPlayerDamageSetDigitAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010F334: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010F338: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010F33C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010F340: addiu       $v0, $v0, 0xD40
    ctx->r2 = ADD32(ctx->r2, 0XD40);
    // 0x8010F344: addiu       $a1, $a1, -0x116C
    ctx->r5 = ADD32(ctx->r5, -0X116C);
    // 0x8010F348: addiu       $v1, $v1, -0x119C
    ctx->r3 = ADD32(ctx->r3, -0X119C);
    // 0x8010F34C: addiu       $a0, $zero, 0x201
    ctx->r4 = ADD32(0, 0X201);
L_8010F350:
    // 0x8010F350: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8010F354: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8010F358: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8010F35C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8010F360: sh          $a0, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r4;
    // 0x8010F364: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8010F368: lw          $t0, -0xC($v1)
    ctx->r8 = MEM_W(ctx->r3, -0XC);
    // 0x8010F36C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8010F370: sh          $a0, 0x14($t1)
    MEM_H(0X14, ctx->r9) = ctx->r4;
    // 0x8010F374: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x8010F378: lw          $t3, -0x8($v1)
    ctx->r11 = MEM_W(ctx->r3, -0X8);
    // 0x8010F37C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8010F380: sh          $a0, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r4;
    // 0x8010F384: lw          $t6, -0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, -0X4);
    // 0x8010F388: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x8010F38C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8010F390: bne         $v1, $a1, L_8010F350
    if (ctx->r3 != ctx->r5) {
        // 0x8010F394: sh          $a0, 0x14($t7)
        MEM_H(0X14, ctx->r15) = ctx->r4;
            goto L_8010F350;
    }
    // 0x8010F394: sh          $a0, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r4;
    // 0x8010F398: jr          $ra
    // 0x8010F39C: nop

    return;
    // 0x8010F39C: nop

;}
RECOMP_FUNC void lbCommonFighterPartsFuncMatrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C973C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800C9740: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C9744: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800C9748: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800C974C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800C9750: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800C9754: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C9758: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x800C975C: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x800C9760: lw          $v1, 0x190($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X190);
    // 0x800C9764: sll         $v1, $v1, 3
    ctx->r3 = S32(ctx->r3 << 3);
    // 0x800C9768: srl         $v1, $v1, 31
    ctx->r3 = S32(U32(ctx->r3) >> 31);
    // 0x800C976C: bnel        $v1, $zero, L_800C9858
    if (ctx->r3 != 0) {
        // 0x800C9770: lw          $t9, 0x0($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X0);
            goto L_800C9858;
    }
    goto skip_0;
    // 0x800C9770: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x800C9774: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800C9778: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C977C: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x800C9780: beql        $t8, $zero, L_800C979C
    if (ctx->r24 == 0) {
        // 0x800C9784: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_800C979C;
    }
    goto skip_1;
    // 0x800C9784: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_1:
    // 0x800C9788: jal         0x80019EA0
    // 0x800C978C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_0;
    // 0x800C978C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800C9790: b           L_800C993C
    // 0x800C9794: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800C993C;
    // 0x800C9794: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C9798: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_800C979C:
    // 0x800C979C: lwc1        $f0, 0x40($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800C97A0: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x800C97A4: nop

    // 0x800C97A8: bc1fl       L_800C97DC
    if (!c1cs) {
        // 0x800C97AC: lwc1        $f8, 0x30($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
            goto L_800C97DC;
    }
    goto skip_2;
    // 0x800C97AC: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    skip_2:
    // 0x800C97B0: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800C97B4: c.eq.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl == ctx->f4.fl;
    // 0x800C97B8: nop

    // 0x800C97BC: bc1fl       L_800C97DC
    if (!c1cs) {
        // 0x800C97C0: lwc1        $f8, 0x30($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
            goto L_800C97DC;
    }
    goto skip_3;
    // 0x800C97C0: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
    skip_3:
    // 0x800C97C4: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800C97C8: c.eq.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl == ctx->f6.fl;
    // 0x800C97CC: nop

    // 0x800C97D0: bc1tl       L_800C9824
    if (c1cs) {
        // 0x800C97D4: lwc1        $f6, 0x30($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
            goto L_800C9824;
    }
    goto skip_4;
    // 0x800C97D4: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    skip_4:
    // 0x800C97D8: lwc1        $f8, 0x30($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X30);
L_800C97DC:
    // 0x800C97DC: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800C97E0: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800C97E4: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800C97E8: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x800C97EC: lwc1        $f10, 0x34($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800C97F0: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800C97F4: swc1        $f10, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f10.u32l;
    // 0x800C97F8: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800C97FC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x800C9800: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x800C9804: lwc1        $f18, 0x44($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800C9808: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800C980C: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800C9810: jal         0x8001C588
    // 0x800C9814: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    syMatrixTraRotRpyRSca(rdram, ctx);
        goto after_1;
    // 0x800C9814: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x800C9818: b           L_800C993C
    // 0x800C981C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800C993C;
    // 0x800C981C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C9820: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
L_800C9824:
    // 0x800C9824: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800C9828: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800C982C: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800C9830: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800C9834: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800C9838: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800C983C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800C9840: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800C9844: jal         0x8001C21C
    // 0x800C9848: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    syMatrixTraRotRpyR(rdram, ctx);
        goto after_2;
    // 0x800C9848: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x800C984C: b           L_800C993C
    // 0x800C9850: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800C993C;
    // 0x800C9850: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C9854: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
L_800C9858:
    // 0x800C9858: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C985C: addiu       $v1, $v1, 0x62D0
    ctx->r3 = ADD32(ctx->r3, 0X62D0);
    // 0x800C9860: beq         $t9, $zero, L_800C9884
    if (ctx->r25 == 0) {
        // 0x800C9864: addiu       $a0, $v0, 0x10
        ctx->r4 = ADD32(ctx->r2, 0X10);
            goto L_800C9884;
    }
    // 0x800C9864: addiu       $a0, $v0, 0x10
    ctx->r4 = ADD32(ctx->r2, 0X10);
    // 0x800C9868: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800C986C: jal         0x80019EA0
    // 0x800C9870: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    syMatrixF2LFixedW(rdram, ctx);
        goto after_3;
    // 0x800C9870: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    after_3:
    // 0x800C9874: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C9878: addiu       $v1, $v1, 0x62D0
    ctx->r3 = ADD32(ctx->r3, 0X62D0);
    // 0x800C987C: b           L_800C9920
    // 0x800C9880: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
        goto L_800C9920;
    // 0x800C9880: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_800C9884:
    // 0x800C9884: lwc1        $f16, 0x40($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800C9888: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C988C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C9890: swc1        $f4, 0x90($v0)
    MEM_W(0X90, ctx->r2) = ctx->f4.u32l;
    // 0x800C9894: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800C9898: lwc1        $f6, 0x44($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X44);
    // 0x800C989C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800C98A0: swc1        $f10, 0x94($v0)
    MEM_W(0X94, ctx->r2) = ctx->f10.u32l;
    // 0x800C98A4: lwc1        $f18, 0x8($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800C98A8: lwc1        $f16, 0x48($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800C98AC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800C98B0: swc1        $f4, 0x98($v0)
    MEM_W(0X98, ctx->r2) = ctx->f4.u32l;
    // 0x800C98B4: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800C98B8: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x800C98BC: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x800C98C0: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x800C98C4: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800C98C8: lwc1        $f8, 0x34($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X34);
    // 0x800C98CC: lwc1        $f4, 0x8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800C98D0: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800C98D4: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x800C98D8: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800C98DC: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C98E0: swc1        $f4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f4.u32l;
    // 0x800C98E4: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
    // 0x800C98E8: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    // 0x800C98EC: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    // 0x800C98F0: lwc1        $f6, 0x90($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X90);
    // 0x800C98F4: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800C98F8: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    // 0x800C98FC: lwc1        $f8, 0x94($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X94);
    // 0x800C9900: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x800C9904: lwc1        $f10, 0x98($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X98);
    // 0x800C9908: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800C990C: jal         0x800C7DB4
    // 0x800C9910: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    lbCommonMatrixTraRotScaInv(rdram, ctx);
        goto after_4;
    // 0x800C9910: swc1        $f10, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f10.u32l;
    after_4:
    // 0x800C9914: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800C9918: addiu       $v1, $v1, 0x62D0
    ctx->r3 = ADD32(ctx->r3, 0X62D0);
    // 0x800C991C: lw          $v0, 0x48($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X48);
L_800C9920:
    // 0x800C9920: lw          $t1, 0x90($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X90);
    // 0x800C9924: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800C9928: lw          $t0, 0x94($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X94);
    // 0x800C992C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800C9930: lw          $t1, 0x98($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X98);
    // 0x800C9934: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x800C9938: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800C993C:
    // 0x800C993C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800C9940: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800C9944: jr          $ra
    // 0x800C9948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800C9948: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void func_ovl8_80373AC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373AC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80373AC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373ACC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80373AD0: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x80373AD4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80373AD8: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x80373ADC: lw          $t9, 0xB4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XB4);
    // 0x80373AE0: lh          $t6, 0xB0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XB0);
    // 0x80373AE4: jalr        $t9
    // 0x80373AE8: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80373AE8: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    after_0:
    // 0x80373AEC: lwl         $t7, 0x2C($sp)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r29, 0X2C);
    // 0x80373AF0: lwr         $t7, 0x2F($sp)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r29, 0X2F);
    // 0x80373AF4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80373AF8: swl         $t7, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r15);
    // 0x80373AFC: swr         $t7, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r15);
    // 0x80373B00: jal         0x80377168
    // 0x80373B04: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    func_ovl8_80377168(rdram, ctx);
        goto after_1;
    // 0x80373B04: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_1:
    // 0x80373B08: beq         $v0, $zero, L_80373B18
    if (ctx->r2 == 0) {
        // 0x80373B0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80373B18;
    }
    // 0x80373B0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80373B10: b           L_80373B1C
    // 0x80373B14: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80373B1C;
    // 0x80373B14: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80373B18:
    // 0x80373B18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80373B1C:
    // 0x80373B1C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80373B20: jr          $ra
    // 0x80373B24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80373B24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftPhysicsApplyGroundVelTransferAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8B94: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8B98: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8B9C: jal         0x800D87D0
    // 0x800D8BA0: nop

    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_0;
    // 0x800D8BA0: nop

    after_0:
    // 0x800D8BA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8BA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8BAC: jr          $ra
    // 0x800D8BB0: nop

    return;
    // 0x800D8BB0: nop

;}
RECOMP_FUNC void wpProcessSetHitInteractStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80166594: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80166598: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8016659C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_801665A0:
    // 0x801665A0: lw          $t6, 0x114($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X114);
    // 0x801665A4: bne         $a1, $t6, L_80166678
    if (ctx->r5 != ctx->r14) {
        // 0x801665A8: sltiu       $at, $a2, 0x7
        ctx->r1 = ctx->r6 < 0X7 ? 1 : 0;
            goto L_80166678;
    }
    // 0x801665A8: sltiu       $at, $a2, 0x7
    ctx->r1 = ctx->r6 < 0X7 ? 1 : 0;
    // 0x801665AC: beq         $at, $zero, L_80166688
    if (ctx->r1 == 0) {
        // 0x801665B0: sll         $t7, $a2, 2
        ctx->r15 = S32(ctx->r6 << 2);
            goto L_80166688;
    }
    // 0x801665B0: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x801665B4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801665B8: addu        $at, $at, $t7
    gpr jr_addend_801665C0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801665BC: lw          $t7, -0x35C8($at)
    ctx->r15 = ADD32(ctx->r1, -0X35C8);
    // 0x801665C0: jr          $t7
    // 0x801665C4: nop

    switch (jr_addend_801665C0 >> 2) {
        case 0: goto L_801665C8; break;
        case 1: goto L_801665D8; break;
        case 2: goto L_801665E8; break;
        case 3: goto L_80166638; break;
        case 4: goto L_80166658; break;
        case 5: goto L_80166628; break;
        case 6: goto L_80166608; break;
        default: switch_error(__func__, 0x801665C0, 0x8018CA38);
    }
    // 0x801665C4: nop

L_801665C8:
    // 0x801665C8: lbu         $t9, 0x118($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X118);
    // 0x801665CC: ori         $t1, $t9, 0x80
    ctx->r9 = ctx->r25 | 0X80;
    // 0x801665D0: b           L_80166688
    // 0x801665D4: sb          $t1, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r9;
        goto L_80166688;
    // 0x801665D4: sb          $t1, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r9;
L_801665D8:
    // 0x801665D8: lbu         $t3, 0x118($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X118);
    // 0x801665DC: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x801665E0: b           L_80166688
    // 0x801665E4: sb          $t4, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r12;
        goto L_80166688;
    // 0x801665E4: sb          $t4, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r12;
L_801665E8:
    // 0x801665E8: lbu         $t6, 0x118($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X118);
    // 0x801665EC: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x801665F0: sb          $t7, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r15;
    // 0x801665F4: lhu         $t8, 0x118($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X118);
    // 0x801665F8: andi        $t9, $t8, 0xFE07
    ctx->r25 = ctx->r24 & 0XFE07;
    // 0x801665FC: ori         $t1, $t9, 0x80
    ctx->r9 = ctx->r25 | 0X80;
    // 0x80166600: b           L_80166688
    // 0x80166604: sh          $t1, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r9;
        goto L_80166688;
    // 0x80166604: sh          $t1, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r9;
L_80166608:
    // 0x80166608: lbu         $t3, 0x118($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X118);
    // 0x8016660C: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80166610: sb          $t4, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r12;
    // 0x80166614: lhu         $t5, 0x118($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0X118);
    // 0x80166618: andi        $t6, $t5, 0xFE07
    ctx->r14 = ctx->r13 & 0XFE07;
    // 0x8016661C: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x80166620: b           L_80166688
    // 0x80166624: sh          $t7, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r15;
        goto L_80166688;
    // 0x80166624: sh          $t7, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r15;
L_80166628:
    // 0x80166628: lbu         $t9, 0x118($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X118);
    // 0x8016662C: ori         $t1, $t9, 0x10
    ctx->r9 = ctx->r25 | 0X10;
    // 0x80166630: b           L_80166688
    // 0x80166634: sb          $t1, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r9;
        goto L_80166688;
    // 0x80166634: sb          $t1, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r9;
L_80166638:
    // 0x80166638: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8016663C: lbu         $t6, 0x118($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X118);
    // 0x80166640: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80166644: andi        $t5, $t4, 0xE
    ctx->r13 = ctx->r12 & 0XE;
    // 0x80166648: andi        $t7, $t6, 0xFFF1
    ctx->r15 = ctx->r14 & 0XFFF1;
    // 0x8016664C: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x80166650: b           L_80166688
    // 0x80166654: sb          $t8, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r24;
        goto L_80166688;
    // 0x80166654: sb          $t8, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r24;
L_80166658:
    // 0x80166658: lbu         $t1, 0x118($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X118);
    // 0x8016665C: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80166660: sb          $t2, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r10;
    // 0x80166664: lhu         $t3, 0x118($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X118);
    // 0x80166668: andi        $t4, $t3, 0xFE07
    ctx->r12 = ctx->r11 & 0XFE07;
    // 0x8016666C: ori         $t6, $t4, 0x80
    ctx->r14 = ctx->r12 | 0X80;
    // 0x80166670: b           L_80166688
    // 0x80166674: sh          $t6, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r14;
        goto L_80166688;
    // 0x80166674: sh          $t6, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r14;
L_80166678:
    // 0x80166678: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8016667C: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x80166680: bne         $at, $zero, L_801665A0
    if (ctx->r1 != 0) {
        // 0x80166684: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_801665A0;
    }
    // 0x80166684: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_80166688:
    // 0x80166688: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8016668C: bne         $v1, $at, L_80166794
    if (ctx->r3 != ctx->r1) {
        // 0x80166690: or          $t0, $a0, $zero
        ctx->r8 = ctx->r4 | 0;
            goto L_80166794;
    }
    // 0x80166690: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x80166694: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80166698: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_8016669C:
    // 0x8016669C: lw          $t5, 0x114($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X114);
    // 0x801666A0: beql        $t5, $zero, L_801666BC
    if (ctx->r13 == 0) {
        // 0x801666A4: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_801666BC;
    }
    goto skip_0;
    // 0x801666A4: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    skip_0:
    // 0x801666A8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x801666AC: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x801666B0: bne         $at, $zero, L_8016669C
    if (ctx->r1 != 0) {
        // 0x801666B4: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8016669C;
    }
    // 0x801666B4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x801666B8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_801666BC:
    // 0x801666BC: bne         $v1, $at, L_801666C8
    if (ctx->r3 != ctx->r1) {
        // 0x801666C0: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_801666C8;
    }
    // 0x801666C0: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x801666C4: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_801666C8:
    // 0x801666C8: sltiu       $at, $a3, 0x7
    ctx->r1 = ctx->r7 < 0X7 ? 1 : 0;
    // 0x801666CC: beq         $at, $zero, L_80166794
    if (ctx->r1 == 0) {
        // 0x801666D0: sw          $a1, 0x114($t0)
        MEM_W(0X114, ctx->r8) = ctx->r5;
            goto L_80166794;
    }
    // 0x801666D0: sw          $a1, 0x114($t0)
    MEM_W(0X114, ctx->r8) = ctx->r5;
    // 0x801666D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801666D8: addu        $at, $at, $t7
    gpr jr_addend_801666E0 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801666DC: lw          $t7, -0x35AC($at)
    ctx->r15 = ADD32(ctx->r1, -0X35AC);
    // 0x801666E0: jr          $t7
    // 0x801666E4: nop

    switch (jr_addend_801666E0 >> 2) {
        case 0: goto L_801666E8; break;
        case 1: goto L_801666F8; break;
        case 2: goto L_80166708; break;
        case 3: goto L_80166758; break;
        case 4: goto L_80166778; break;
        case 5: goto L_80166748; break;
        case 6: goto L_80166728; break;
        default: switch_error(__func__, 0x801666E0, 0x8018CA54);
    }
    // 0x801666E4: nop

L_801666E8:
    // 0x801666E8: lbu         $t9, 0x118($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X118);
    // 0x801666EC: ori         $t1, $t9, 0x80
    ctx->r9 = ctx->r25 | 0X80;
    // 0x801666F0: jr          $ra
    // 0x801666F4: sb          $t1, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r9;
    return;
    // 0x801666F4: sb          $t1, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r9;
L_801666F8:
    // 0x801666F8: lbu         $t3, 0x118($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X118);
    // 0x801666FC: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x80166700: jr          $ra
    // 0x80166704: sb          $t4, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r12;
    return;
    // 0x80166704: sb          $t4, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r12;
L_80166708:
    // 0x80166708: lbu         $t5, 0x118($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X118);
    // 0x8016670C: ori         $t7, $t5, 0x40
    ctx->r15 = ctx->r13 | 0X40;
    // 0x80166710: sb          $t7, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r15;
    // 0x80166714: lhu         $t8, 0x118($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X118);
    // 0x80166718: andi        $t9, $t8, 0xFE07
    ctx->r25 = ctx->r24 & 0XFE07;
    // 0x8016671C: ori         $t1, $t9, 0x80
    ctx->r9 = ctx->r25 | 0X80;
    // 0x80166720: jr          $ra
    // 0x80166724: sh          $t1, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r9;
    return;
    // 0x80166724: sh          $t1, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r9;
L_80166728:
    // 0x80166728: lbu         $t3, 0x118($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X118);
    // 0x8016672C: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x80166730: sb          $t4, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r12;
    // 0x80166734: lhu         $t6, 0x118($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X118);
    // 0x80166738: andi        $t5, $t6, 0xFE07
    ctx->r13 = ctx->r14 & 0XFE07;
    // 0x8016673C: ori         $t7, $t5, 0x80
    ctx->r15 = ctx->r13 | 0X80;
    // 0x80166740: jr          $ra
    // 0x80166744: sh          $t7, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r15;
    return;
    // 0x80166744: sh          $t7, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r15;
L_80166748:
    // 0x80166748: lbu         $t9, 0x118($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X118);
    // 0x8016674C: ori         $t1, $t9, 0x10
    ctx->r9 = ctx->r25 | 0X10;
    // 0x80166750: jr          $ra
    // 0x80166754: sb          $t1, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r9;
    return;
    // 0x80166754: sb          $t1, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r9;
L_80166758:
    // 0x80166758: lw          $t3, 0xC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC);
    // 0x8016675C: lbu         $t5, 0x118($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0X118);
    // 0x80166760: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x80166764: andi        $t6, $t4, 0xE
    ctx->r14 = ctx->r12 & 0XE;
    // 0x80166768: andi        $t7, $t5, 0xFFF1
    ctx->r15 = ctx->r13 & 0XFFF1;
    // 0x8016676C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80166770: jr          $ra
    // 0x80166774: sb          $t8, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r24;
    return;
    // 0x80166774: sb          $t8, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r24;
L_80166778:
    // 0x80166778: lbu         $t1, 0x118($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X118);
    // 0x8016677C: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80166780: sb          $t2, 0x118($t0)
    MEM_B(0X118, ctx->r8) = ctx->r10;
    // 0x80166784: lhu         $t3, 0x118($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X118);
    // 0x80166788: andi        $t4, $t3, 0xFE07
    ctx->r12 = ctx->r11 & 0XFE07;
    // 0x8016678C: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x80166790: sh          $t5, 0x118($t0)
    MEM_H(0X118, ctx->r8) = ctx->r13;
L_80166794:
    // 0x80166794: jr          $ra
    // 0x80166798: nop

    return;
    // 0x80166798: nop

;}
RECOMP_FUNC void itMapCheckMapProcAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173E58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173E60: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80173E64: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80173E68: jal         0x801737B8
    // 0x80173E6C: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80173E6C: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    after_0:
    // 0x80173E70: beq         $v0, $zero, L_80173E88
    if (ctx->r2 == 0) {
        // 0x80173E74: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80173E88;
    }
    // 0x80173E74: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80173E78: beql        $v1, $zero, L_80173E8C
    if (ctx->r3 == 0) {
        // 0x80173E7C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80173E8C;
    }
    goto skip_0;
    // 0x80173E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80173E80: jalr        $v1
    // 0x80173E84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x80173E84: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80173E88:
    // 0x80173E88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80173E8C:
    // 0x80173E8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80173E90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80173E94: jr          $ra
    // 0x80173E98: nop

    return;
    // 0x80173E98: nop

;}
RECOMP_FUNC void func_ovl8_80378064(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80378064: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80378068: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037806C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80378070: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80378074: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80378078: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8037807C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80378080: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80378084: addiu       $a2, $a2, -0x60A4
    ctx->r6 = ADD32(ctx->r6, -0X60A4);
    // 0x80378088: jal         0x80376B60
    // 0x8037808C: lbu         $a0, 0x31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X31);
    func_ovl8_80376B60(rdram, ctx);
        goto after_0;
    // 0x8037808C: lbu         $a0, 0x31($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X31);
    after_0:
    // 0x80378090: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80378094: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80378098: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8037809C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x803780A0: jal         0x803780B8
    // 0x803780A4: sw          $t7, -0x60A0($at)
    MEM_W(-0X60A0, ctx->r1) = ctx->r15;
    func_ovl8_803780B8(rdram, ctx);
        goto after_1;
    // 0x803780A4: sw          $t7, -0x60A0($at)
    MEM_W(-0X60A0, ctx->r1) = ctx->r15;
    after_1:
    // 0x803780A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803780AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803780B0: jr          $ra
    // 0x803780B4: nop

    return;
    // 0x803780B4: nop

;}
RECOMP_FUNC void efParticleGObjSetSkipAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115910: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80115914: addiu       $v1, $v1, 0x1A10
    ctx->r3 = ADD32(ctx->r3, 0X1A10);
    // 0x80115918: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8011591C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80115920: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80115924: lw          $t6, 0x7C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X7C);
    // 0x80115928: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8011592C: sw          $t7, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r15;
    // 0x80115930: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80115934: lw          $t0, 0x1A14($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X1A14);
    // 0x80115938: lw          $t9, 0x7C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X7C);
    // 0x8011593C: jr          $ra
    // 0x80115940: sw          $t9, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = ctx->r25;
    return;
    // 0x80115940: sw          $t9, 0x7C($t0)
    MEM_W(0X7C, ctx->r8) = ctx->r25;
;}
RECOMP_FUNC void itGLuckyCommonProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C530: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017C534: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017C538: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017C53C: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8017C540: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017C544: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8017C548: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8017C54C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017C550: lwc1        $f0, 0x294($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X294);
    // 0x8017C554: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8017C558: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8017C55C: nop

    // 0x8017C560: bc1fl       L_8017C5E4
    if (!c1cs) {
        // 0x8017C564: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8017C5E4;
    }
    goto skip_0;
    // 0x8017C564: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8017C568: lw          $a0, 0x29C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X29C);
    // 0x8017C56C: lw          $a1, 0x108($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X108);
    // 0x8017C570: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017C574: jal         0x801409BC
    // 0x8017C578: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    ftCommonDamageGetKnockbackAngle(rdram, ctx);
        goto after_0;
    // 0x8017C578: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_0:
    // 0x8017C57C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8017C580: jal         0x80035CD0
    // 0x8017C584: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017C584: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x8017C588: lw          $t7, 0x2A4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X2A4);
    // 0x8017C58C: lwc1        $f6, 0x294($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X294);
    // 0x8017C590: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8017C594: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8017C598: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8017C59C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8017C5A0: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8017C5A4: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8017C5A8: jal         0x800303F0
    // 0x8017C5AC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x8017C5AC: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8017C5B0: lwc1        $f4, 0x294($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X294);
    // 0x8017C5B4: sw          $zero, 0x10C($s0)
    MEM_W(0X10C, ctx->r16) = 0;
    // 0x8017C5B8: sw          $zero, 0x248($s0)
    MEM_W(0X248, ctx->r16) = 0;
    // 0x8017C5BC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8017C5C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017C5C4: swc1        $f6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f6.u32l;
    // 0x8017C5C8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8017C5CC: lwc1        $f10, -0x3218($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3218);
    // 0x8017C5D0: jal         0x8010B0AC
    // 0x8017C5D4: swc1        $f10, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->f10.u32l;
    grYamabukiGateClearMonsterGObj(rdram, ctx);
        goto after_3;
    // 0x8017C5D4: swc1        $f10, 0x74($t9)
    MEM_W(0X74, ctx->r25) = ctx->f10.u32l;
    after_3:
    // 0x8017C5D8: jal         0x8017C240
    // 0x8017C5DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    itGLuckyDamagedSetStatus(rdram, ctx);
        goto after_4;
    // 0x8017C5DC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8017C5E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017C5E4:
    // 0x8017C5E4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8017C5E8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017C5EC: jr          $ra
    // 0x8017C5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8017C5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ftCommonAttackHi3SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FA50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014FA54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014FA58: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014FA5C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014FA60: addiu       $a1, $zero, 0xC7
    ctx->r5 = ADD32(0, 0XC7);
    // 0x8014FA64: lw          $t7, 0x9C4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C4);
    // 0x8014FA68: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x8014FA6C: lw          $t9, 0x81C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X81C);
    // 0x8014FA70: beq         $t9, $zero, L_8014FAF0
    if (ctx->r25 == 0) {
        // 0x8014FA74: nop
    
            goto L_8014FAF0;
    }
    // 0x8014FA74: nop

    // 0x8014FA78: lb          $t1, 0x1C2($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X1C2);
    // 0x8014FA7C: lw          $t2, 0x44($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X44);
    // 0x8014FA80: lb          $t0, 0x1C3($v0)
    ctx->r8 = MEM_B(ctx->r2, 0X1C3);
    // 0x8014FA84: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014FA88: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x8014FA8C: nop

    // 0x8014FA90: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014FA94: mflo        $t3
    ctx->r11 = lo;
    // 0x8014FA98: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8014FA9C: jal         0x8001863C
    // 0x8014FAA0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8014FAA0: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_0:
    // 0x8014FAA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014FAA8: lwc1        $f8, -0x3B40($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3B40);
    // 0x8014FAAC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014FAB0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8014FAB4: nop

    // 0x8014FAB8: bc1f        L_8014FAC8
    if (!c1cs) {
        // 0x8014FABC: nop
    
            goto L_8014FAC8;
    }
    // 0x8014FABC: nop

    // 0x8014FAC0: b           L_8014FAF0
    // 0x8014FAC4: addiu       $a1, $zero, 0xC6
    ctx->r5 = ADD32(0, 0XC6);
        goto L_8014FAF0;
    // 0x8014FAC4: addiu       $a1, $zero, 0xC6
    ctx->r5 = ADD32(0, 0XC6);
L_8014FAC8:
    // 0x8014FAC8: lwc1        $f10, -0x3B3C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3B3C);
    // 0x8014FACC: addiu       $v0, $zero, 0xC7
    ctx->r2 = ADD32(0, 0XC7);
    // 0x8014FAD0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8014FAD4: nop

    // 0x8014FAD8: bc1f        L_8014FAE8
    if (!c1cs) {
        // 0x8014FADC: nop
    
            goto L_8014FAE8;
    }
    // 0x8014FADC: nop

    // 0x8014FAE0: b           L_8014FAF0
    // 0x8014FAE4: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
        goto L_8014FAF0;
    // 0x8014FAE4: addiu       $a1, $zero, 0xC8
    ctx->r5 = ADD32(0, 0XC8);
L_8014FAE8:
    // 0x8014FAE8: b           L_8014FAF0
    // 0x8014FAEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8014FAF0;
    // 0x8014FAEC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8014FAF0:
    // 0x8014FAF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014FAF4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014FAF8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014FAFC: jal         0x800E6F24
    // 0x8014FB00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014FB00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8014FB04: jal         0x800E0830
    // 0x8014FB08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8014FB08: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8014FB0C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014FB10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014FB14: jr          $ra
    // 0x8014FB18: nop

    return;
    // 0x8014FB18: nop

;}
RECOMP_FUNC void mnVSResultsMakeWinnerText(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013423C: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x80134240: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134248: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8013424C: addiu       $t7, $t7, -0x6840
    ctx->r15 = ADD32(ctx->r15, -0X6840);
    // 0x80134250: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134254: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80134258: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x8013425C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80134260: addiu       $t1, $t1, -0x6838
    ctx->r9 = ADD32(ctx->r9, -0X6838);
    // 0x80134264: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80134268: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013426C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80134270: addiu       $t0, $sp, 0x64
    ctx->r8 = ADD32(ctx->r29, 0X64);
    // 0x80134274: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80134278: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8013427C: lhu         $t3, 0x8($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X8);
    // 0x80134280: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80134284: addiu       $t5, $t5, -0x6B4C
    ctx->r13 = ADD32(ctx->r13, -0X6B4C);
    // 0x80134288: addiu       $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // 0x8013428C: addiu       $t8, $t5, 0x30
    ctx->r24 = ADD32(ctx->r13, 0X30);
    // 0x80134290: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x80134294: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80134298: sh          $t3, 0x8($t0)
    MEM_H(0X8, ctx->r8) = ctx->r11;
L_8013429C:
    // 0x8013429C: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x801342A0: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x801342A4: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x801342A8: sw          $t7, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r15;
    // 0x801342AC: lw          $t6, -0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X8);
    // 0x801342B0: sw          $t6, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r14;
    // 0x801342B4: lw          $t7, -0x4($t5)
    ctx->r15 = MEM_W(ctx->r13, -0X4);
    // 0x801342B8: bne         $t5, $t8, L_8013429C
    if (ctx->r13 != ctx->r24) {
        // 0x801342BC: sw          $t7, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r15;
            goto L_8013429C;
    }
    // 0x801342BC: sw          $t7, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r15;
    // 0x801342C0: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801342C4: addiu       $t9, $t9, -0x6B1C
    ctx->r25 = ADD32(ctx->r25, -0X6B1C);
    // 0x801342C8: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801342CC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801342D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801342D4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801342D8: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x801342DC: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x801342E0: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x801342E4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x801342E8: lw          $t1, 0x8($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X8);
    // 0x801342EC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x801342F0: sw          $t1, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r9;
    // 0x801342F4: lbu         $v0, -0x63EC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X63EC);
    // 0x801342F8: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x801342FC: bne         $v0, $at, L_80134324
    if (ctx->r2 != ctx->r1) {
        // 0x80134300: sll         $t3, $t2, 2
        ctx->r11 = S32(ctx->r10 << 2);
            goto L_80134324;
    }
    // 0x80134300: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80134304: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80134308: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013430C: addu        $t8, $v1, $t3
    ctx->r24 = ADD32(ctx->r3, ctx->r11);
    // 0x80134310: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x80134314: jal         0x80133F6C
    // 0x80134318: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mnVSResultsMakeString(rdram, ctx);
        goto after_0;
    // 0x80134318: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8013431C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80134320: lbu         $v0, -0x63EC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X63EC);
L_80134324:
    // 0x80134324: bne         $v0, $zero, L_80134354
    if (ctx->r2 != 0) {
        // 0x80134328: addiu       $a0, $sp, 0x64
        ctx->r4 = ADD32(ctx->r29, 0X64);
            goto L_80134354;
    }
    // 0x80134328: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x8013432C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x80134330: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80134334: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134338: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8013433C: addu        $t6, $sp, $t4
    ctx->r14 = ADD32(ctx->r29, ctx->r12);
    // 0x80134340: lw          $a1, 0x34($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X34);
    // 0x80134344: lui         $a2, 0x4334
    ctx->r6 = S32(0X4334 << 16);
    // 0x80134348: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x8013434C: jal         0x80133F6C
    // 0x80134350: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    mnVSResultsMakeString(rdram, ctx);
        goto after_1;
    // 0x80134350: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
L_80134354:
    // 0x80134354: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80134358: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x8013435C: jr          $ra
    // 0x80134360: nop

    return;
    // 0x80134360: nop

;}
RECOMP_FUNC void itBoxDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017990C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179914: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80179918: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017991C: lwc1        $f4, -0x3290($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3290);
    // 0x80179920: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80179924: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80179928: addiu       $a1, $a1, -0x5C7C
    ctx->r5 = ADD32(ctx->r5, -0X5C7C);
    // 0x8017992C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80179930: jal         0x80172EC8
    // 0x80179934: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80179934: swc1        $f4, 0x34($t7)
    MEM_W(0X34, ctx->r15) = ctx->f4.u32l;
    after_0:
    // 0x80179938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017993C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179940: jr          $ra
    // 0x80179944: nop

    return;
    // 0x80179944: nop

;}
RECOMP_FUNC void ftParamGetBestHitStatusAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8AAC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E8AB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8AB4: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x800E8AB8: jal         0x800E8A48
    // 0x800E8ABC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftParamGetBestHitStatusPart(rdram, ctx);
        goto after_0;
    // 0x800E8ABC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800E8AC0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800E8AC4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E8AC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8ACC: lw          $a0, 0x5B4($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X5B4);
    // 0x800E8AD0: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800E8AD4: beql        $at, $zero, L_800E8AE4
    if (ctx->r1 == 0) {
        // 0x800E8AD8: lw          $v0, 0x5AC($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X5AC);
            goto L_800E8AE4;
    }
    goto skip_0;
    // 0x800E8AD8: lw          $v0, 0x5AC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5AC);
    skip_0:
    // 0x800E8ADC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800E8AE0: lw          $v0, 0x5AC($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X5AC);
L_800E8AE4:
    // 0x800E8AE4: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E8AE8: beql        $at, $zero, L_800E8AF8
    if (ctx->r1 == 0) {
        // 0x800E8AEC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800E8AF8;
    }
    goto skip_1;
    // 0x800E8AEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_1:
    // 0x800E8AF0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800E8AF4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800E8AF8:
    // 0x800E8AF8: jr          $ra
    // 0x800E8AFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800E8AFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnVSModeIsTime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B38: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132B3C: lw          $v0, 0x494C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X494C);
    // 0x80132B40: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132B44: beq         $v0, $zero, L_80132B54
    if (ctx->r2 == 0) {
        // 0x80132B48: nop
    
            goto L_80132B54;
    }
    // 0x80132B48: nop

    // 0x80132B4C: bnel        $v0, $at, L_80132B60
    if (ctx->r2 != ctx->r1) {
        // 0x80132B50: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80132B60;
    }
    goto skip_0;
    // 0x80132B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
L_80132B54:
    // 0x80132B54: jr          $ra
    // 0x80132B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80132B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80132B5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132B60:
    // 0x80132B60: jr          $ra
    // 0x80132B64: nop

    return;
    // 0x80132B64: nop

;}
RECOMP_FUNC void itMainRefreshAttackColl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017275C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80172760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80172764: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80172768: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8017276C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80172770: jal         0x801725F8
    // 0x80172774: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    itMainClearAttackRecord(rdram, ctx);
        goto after_0;
    // 0x80172774: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80172778: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8017277C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80172780: sw          $t7, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = ctx->r15;
    // 0x80172784: jal         0x8016F280
    // 0x80172788: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itProcessUpdateAttackPositions(rdram, ctx);
        goto after_1;
    // 0x80172788: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8017278C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80172790: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80172794: jr          $ra
    // 0x80172798: nop

    return;
    // 0x80172798: nop

;}
RECOMP_FUNC void gcSetupCustomDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F590: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8000F594: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8000F598: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8000F59C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000F5A0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000F5A4: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000F5A8: andi        $s6, $a3, 0xFF
    ctx->r22 = ctx->r7 & 0XFF;
    // 0x8000F5AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000F5B0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8000F5B4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8000F5B8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8000F5BC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8000F5C0: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8000F5C4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8000F5C8: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x8000F5CC: sw          $a3, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r7;
    // 0x8000F5D0: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x8000F5D4: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x8000F5D8: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x8000F5DC: addiu       $v1, $sp, 0x9C
    ctx->r3 = ADD32(ctx->r29, 0X9C);
L_8000F5E0:
    // 0x8000F5E0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8000F5E4: sw          $zero, -0xC($v0)
    MEM_W(-0XC, ctx->r2) = 0;
    // 0x8000F5E8: sw          $zero, -0x8($v0)
    MEM_W(-0X8, ctx->r2) = 0;
    // 0x8000F5EC: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8000F5F0: bne         $v0, $v1, L_8000F5E0
    if (ctx->r2 != ctx->r3) {
        // 0x8000F5F4: sw          $zero, -0x10($v0)
        MEM_W(-0X10, ctx->r2) = 0;
            goto L_8000F5E0;
    }
    // 0x8000F5F4: sw          $zero, -0x10($v0)
    MEM_W(-0X10, ctx->r2) = 0;
    // 0x8000F5F8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000F5FC: addiu       $fp, $zero, 0x12
    ctx->r30 = ADD32(0, 0X12);
    // 0x8000F600: addiu       $s7, $sp, 0x54
    ctx->r23 = ADD32(ctx->r29, 0X54);
    // 0x8000F604: beq         $fp, $v0, L_8000F6F0
    if (ctx->r30 == ctx->r2) {
        // 0x8000F608: lbu         $s5, 0xBF($sp)
        ctx->r21 = MEM_BU(ctx->r29, 0XBF);
            goto L_8000F6F0;
    }
    // 0x8000F608: lbu         $s5, 0xBF($sp)
    ctx->r21 = MEM_BU(ctx->r29, 0XBF);
    // 0x8000F60C: lbu         $s4, 0xBB($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XBB);
    // 0x8000F610: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
L_8000F614:
    // 0x8000F614: beq         $v1, $zero, L_8000F638
    if (ctx->r3 == 0) {
        // 0x8000F618: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_8000F638;
    }
    // 0x8000F618: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8000F61C: addu        $s2, $s7, $t6
    ctx->r18 = ADD32(ctx->r23, ctx->r14);
    // 0x8000F620: lw          $a0, -0x4($s2)
    ctx->r4 = MEM_W(ctx->r18, -0X4);
    // 0x8000F624: jal         0x800093F4
    // 0x8000F628: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    gcAddChildForDObj(rdram, ctx);
        goto after_0;
    // 0x8000F628: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_0:
    // 0x8000F62C: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x8000F630: b           L_8000F64C
    // 0x8000F634: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_8000F64C;
    // 0x8000F634: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8000F638:
    // 0x8000F638: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8000F63C: jal         0x800092D0
    // 0x8000F640: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x8000F640: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    after_1:
    // 0x8000F644: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8000F648: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8000F64C:
    // 0x8000F64C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8000F650: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000F654: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x8000F658: andi        $v0, $v0, 0xF000
    ctx->r2 = ctx->r2 & 0XF000;
    // 0x8000F65C: beq         $v0, $zero, L_8000F684
    if (ctx->r2 == 0) {
        // 0x8000F660: andi        $a2, $s4, 0xFF
        ctx->r6 = ctx->r20 & 0XFF;
            goto L_8000F684;
    }
    // 0x8000F660: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x8000F664: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000F668: andi        $a1, $s6, 0xFF
    ctx->r5 = ctx->r22 & 0XFF;
    // 0x8000F66C: andi        $a2, $s4, 0xFF
    ctx->r6 = ctx->r20 & 0XFF;
    // 0x8000F670: andi        $a3, $s5, 0xFF
    ctx->r7 = ctx->r21 & 0XFF;
    // 0x8000F674: jal         0x8000F364
    // 0x8000F678: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    gcDecideDObj3TransformsKind(rdram, ctx);
        goto after_2;
    // 0x8000F678: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    after_2:
    // 0x8000F67C: b           L_8000F690
    // 0x8000F680: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
        goto L_8000F690;
    // 0x8000F680: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
L_8000F684:
    // 0x8000F684: jal         0x8000F2FC
    // 0x8000F688: andi        $a3, $s5, 0xFF
    ctx->r7 = ctx->r21 & 0XFF;
    gcAddDObj3TransformsKind(rdram, ctx);
        goto after_3;
    // 0x8000F688: andi        $a3, $s5, 0xFF
    ctx->r7 = ctx->r21 & 0XFF;
    after_3:
    // 0x8000F68C: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
L_8000F690:
    // 0x8000F690: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    // 0x8000F694: lw          $t7, 0xC($s1)
    ctx->r15 = MEM_W(ctx->r17, 0XC);
    // 0x8000F698: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x8000F69C: lw          $t8, 0x10($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X10);
    // 0x8000F6A0: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
    // 0x8000F6A4: lw          $t0, 0x14($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X14);
    // 0x8000F6A8: sw          $t0, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r8;
    // 0x8000F6AC: lw          $t9, 0x18($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X18);
    // 0x8000F6B0: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x8000F6B4: lw          $t0, 0x1C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X1C);
    // 0x8000F6B8: sw          $t0, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r8;
    // 0x8000F6BC: lw          $t2, 0x20($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X20);
    // 0x8000F6C0: sw          $t2, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r10;
    // 0x8000F6C4: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x8000F6C8: sw          $t1, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r9;
    // 0x8000F6CC: lw          $t2, 0x28($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X28);
    // 0x8000F6D0: beq         $s3, $zero, L_8000F6E0
    if (ctx->r19 == 0) {
        // 0x8000F6D4: sw          $t2, 0x48($s0)
        MEM_W(0X48, ctx->r16) = ctx->r10;
            goto L_8000F6E0;
    }
    // 0x8000F6D4: sw          $t2, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r10;
    // 0x8000F6D8: sw          $s0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r16;
    // 0x8000F6DC: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8000F6E0:
    // 0x8000F6E0: lw          $v0, 0x2C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X2C);
    // 0x8000F6E4: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x8000F6E8: bnel        $fp, $v0, L_8000F614
    if (ctx->r30 != ctx->r2) {
        // 0x8000F6EC: andi        $v1, $v0, 0xFFF
        ctx->r3 = ctx->r2 & 0XFFF;
            goto L_8000F614;
    }
    goto skip_0;
    // 0x8000F6EC: andi        $v1, $v0, 0xFFF
    ctx->r3 = ctx->r2 & 0XFFF;
    skip_0:
L_8000F6F0:
    // 0x8000F6F0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000F6F4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8000F6F8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8000F6FC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8000F700: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8000F704: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8000F708: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8000F70C: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8000F710: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8000F714: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8000F718: jr          $ra
    // 0x8000F71C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8000F71C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void mpProcessCheckCeilEdgeCollisionL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9628: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800D962C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D9630: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800D9634: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D9638: lw          $a0, 0x8C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X8C);
    // 0x800D963C: sw          $a1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r5;
    // 0x800D9640: jal         0x800FAAE4
    // 0x800D9644: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    mpCollisionGetEdgeUpperRLineID(rdram, ctx);
        goto after_0;
    // 0x800D9644: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    after_0:
    // 0x800D9648: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x800D964C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800D9650: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x800D9654: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D9658: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    // 0x800D965C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x800D9660: swc1        $f4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f4.u32l;
    // 0x800D9664: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D9668: lwc1        $f8, 0x38($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X38);
    // 0x800D966C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D9670: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x800D9674: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D9678: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x800D967C: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x800D9680: lwc1        $f16, 0x0($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800D9684: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800D9688: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800D968C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800D9690: lwc1        $f6, 0x4($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800D9694: lwc1        $f8, 0x4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800D9698: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800D969C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800D96A0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D96A4: jal         0x800F7F00
    // 0x800D96A8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800D96A8: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    after_1:
    // 0x800D96AC: beq         $v0, $zero, L_800D96CC
    if (ctx->r2 == 0) {
        // 0x800D96B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800D96CC;
    }
    // 0x800D96B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D96B4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800D96B8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x800D96BC: beql        $t6, $t7, L_800D96D0
    if (ctx->r14 == ctx->r15) {
        // 0x800D96C0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D96D0;
    }
    goto skip_0;
    // 0x800D96C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x800D96C4: b           L_800D96D0
    // 0x800D96C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800D96D0;
    // 0x800D96C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D96CC:
    // 0x800D96CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D96D0:
    // 0x800D96D0: jr          $ra
    // 0x800D96D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800D96D4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void mnPlayers1PTrainingMakeNameAndEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325D4: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x801325D8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801325DC: addiu       $t7, $t7, -0x7EAC
    ctx->r15 = ADD32(ctx->r15, -0X7EAC);
    // 0x801325E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801325E4: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x801325E8: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x801325EC: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801325F0: addiu       $t0, $t7, 0x60
    ctx->r8 = ADD32(ctx->r15, 0X60);
    // 0x801325F4: addiu       $t6, $sp, 0x7C
    ctx->r14 = ADD32(ctx->r29, 0X7C);
L_801325F8:
    // 0x801325F8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801325FC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132600: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132604: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132608: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8013260C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132610: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132614: bne         $t7, $t0, L_801325F8
    if (ctx->r15 != ctx->r8) {
        // 0x80132618: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801325F8;
    }
    // 0x80132618: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8013261C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132620: addiu       $t2, $t2, -0x7E4C
    ctx->r10 = ADD32(ctx->r10, -0X7E4C);
    // 0x80132624: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x80132628: addiu       $t1, $sp, 0x4C
    ctx->r9 = ADD32(ctx->r29, 0X4C);
L_8013262C:
    // 0x8013262C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132630: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80132634: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80132638: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x8013263C: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80132640: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80132644: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80132648: bne         $t2, $t5, L_8013262C
    if (ctx->r10 != ctx->r13) {
        // 0x8013264C: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_8013262C;
    }
    // 0x8013264C: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80132650: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132654: addiu       $t7, $t7, -0x7E1C
    ctx->r15 = ADD32(ctx->r15, -0X7E1C);
    // 0x80132658: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x8013265C: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
L_80132660:
    // 0x80132660: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132664: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132668: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8013266C: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x80132670: lw          $t6, -0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, -0X8);
    // 0x80132674: sw          $t6, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r14;
    // 0x80132678: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x8013267C: bne         $t7, $t9, L_80132660
    if (ctx->r15 != ctx->r25) {
        // 0x80132680: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_80132660;
    }
    // 0x80132680: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x80132684: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80132688: beq         $a3, $at, L_801327B4
    if (ctx->r7 == ctx->r1) {
        // 0x8013268C: lw          $a0, 0xE0($sp)
        ctx->r4 = MEM_W(ctx->r29, 0XE0);
            goto L_801327B4;
    }
    // 0x8013268C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80132690: jal         0x8000B760
    // 0x80132694: sw          $a3, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r7;
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x80132694: sw          $a3, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r7;
    after_0:
    // 0x80132698: lw          $a3, 0xE8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XE8);
    // 0x8013269C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801326A0: lw          $t2, -0x735C($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X735C);
    // 0x801326A4: sll         $a2, $a3, 2
    ctx->r6 = S32(ctx->r7 << 2);
    // 0x801326A8: addu        $t5, $sp, $a2
    ctx->r13 = ADD32(ctx->r29, ctx->r6);
    // 0x801326AC: lw          $t5, 0x4C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4C);
    // 0x801326B0: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801326B4: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x801326B8: jal         0x800CCFDC
    // 0x801326BC: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x801326BC: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    after_1:
    // 0x801326C0: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x801326C4: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801326C8: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801326CC: andi        $t4, $t1, 0xFFDF
    ctx->r12 = ctx->r9 & 0XFFDF;
    // 0x801326D0: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x801326D4: ori         $t9, $t4, 0x1
    ctx->r25 = ctx->r12 | 0X1;
    // 0x801326D8: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x801326DC: lw          $t0, -0x776C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X776C);
    // 0x801326E0: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x801326E4: addiu       $v1, $zero, 0x44
    ctx->r3 = ADD32(0, 0X44);
    // 0x801326E8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801326EC: bne         $t7, $t0, L_80132720
    if (ctx->r15 != ctx->r8) {
        // 0x801326F0: addu        $t6, $sp, $a2
        ctx->r14 = ADD32(ctx->r29, ctx->r6);
            goto L_80132720;
    }
    // 0x801326F0: addu        $t6, $sp, $a2
    ctx->r14 = ADD32(ctx->r29, ctx->r6);
    // 0x801326F4: lui         $at, 0x427C
    ctx->r1 = S32(0X427C << 16);
    // 0x801326F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801326FC: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x80132700: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132704: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x80132708: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x8013270C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132710: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132714: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132718: b           L_80132744
    // 0x8013271C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
        goto L_80132744;
    // 0x8013271C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80132720:
    // 0x80132720: lui         $at, 0x4343
    ctx->r1 = S32(0X4343 << 16);
    // 0x80132724: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132728: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x8013272C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132730: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132734: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132738: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x8013273C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80132740: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80132744:
    // 0x80132744: lw          $t6, 0x1C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1C);
    // 0x80132748: lw          $t8, -0x7368($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7368);
    // 0x8013274C: lw          $a0, 0xE0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XE0);
    // 0x80132750: jal         0x800CCFDC
    // 0x80132754: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132754: addu        $a1, $t6, $t8
    ctx->r5 = ADD32(ctx->r14, ctx->r24);
    after_2:
    // 0x80132758: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x8013275C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80132760: lui         $at, 0x4341
    ctx->r1 = S32(0X4341 << 16);
    // 0x80132764: andi        $t1, $t5, 0xFFDF
    ctx->r9 = ctx->r13 & 0XFFDF;
    // 0x80132768: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013276C: ori         $t3, $t1, 0x1
    ctx->r11 = ctx->r9 | 0X1;
    // 0x80132770: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132774: lw          $t9, -0x776C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X776C);
    // 0x80132778: lw          $t4, 0xE4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XE4);
    // 0x8013277C: bnel        $t4, $t9, L_801327A4
    if (ctx->r12 != ctx->r25) {
        // 0x80132780: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_801327A4;
    }
    goto skip_0;
    // 0x80132780: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_0:
    // 0x80132784: lui         $at, 0x4274
    ctx->r1 = S32(0X4274 << 16);
    // 0x80132788: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013278C: lui         $at, 0x434A
    ctx->r1 = S32(0X434A << 16);
    // 0x80132790: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80132794: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80132798: b           L_801327B4
    // 0x8013279C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
        goto L_801327B4;
    // 0x8013279C: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x801327A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_801327A4:
    // 0x801327A4: lui         $at, 0x434A
    ctx->r1 = S32(0X434A << 16);
    // 0x801327A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801327AC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801327B0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_801327B4:
    // 0x801327B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801327B8: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x801327BC: jr          $ra
    // 0x801327C0: nop

    return;
    // 0x801327C0: nop

;}
RECOMP_FUNC void grSectorArwingWeaponLaser2DProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801072C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801072C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801072C8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801072CC: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x801072D0: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    // 0x801072D4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801072D8: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x801072DC: jal         0x801680EC
    // 0x801072E0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x801072E0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_0:
    // 0x801072E4: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x801072E8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x801072EC: lw          $t9, 0x20($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X20);
    // 0x801072F0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x801072F4: lw          $t8, 0x24($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X24);
    // 0x801072F8: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x801072FC: lw          $t9, 0x28($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X28);
    // 0x80107300: jal         0x80018EE0
    // 0x80107304: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    syVectorNorm3D(rdram, ctx);
        goto after_1;
    // 0x80107304: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    after_1:
    // 0x80107308: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8010730C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80107310: lw          $a1, 0x74($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X74);
    // 0x80107314: jal         0x8010719C
    // 0x80107318: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_ovl2_8010719C(rdram, ctx);
        goto after_2;
    // 0x80107318: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_2:
    // 0x8010731C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107320: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80107324: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80107328: jr          $ra
    // 0x8010732C: nop

    return;
    // 0x8010732C: nop

;}
RECOMP_FUNC void ftCommonGuardCommonProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148B84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80148B88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80148B8C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80148B90: jal         0x80146AE8
    // 0x80148B94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    ftCommonLightThrowCheckInterruptGuardOn(rdram, ctx);
        goto after_0;
    // 0x80148B94: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80148B98: bnel        $v0, $zero, L_80148BEC
    if (ctx->r2 != 0) {
        // 0x80148B9C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80148BEC;
    }
    goto skip_0;
    // 0x80148B9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80148BA0: jal         0x801493EC
    // 0x80148BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonEscapeCheckInterruptGuard(rdram, ctx);
        goto after_1;
    // 0x80148BA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80148BA8: bnel        $v0, $zero, L_80148BEC
    if (ctx->r2 != 0) {
        // 0x80148BAC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80148BEC;
    }
    goto skip_1;
    // 0x80148BAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80148BB0: jal         0x80149C60
    // 0x80148BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptGuard(rdram, ctx);
        goto after_2;
    // 0x80148BB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80148BB8: bnel        $v0, $zero, L_80148BEC
    if (ctx->r2 != 0) {
        // 0x80148BBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80148BEC;
    }
    goto skip_2;
    // 0x80148BBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80148BC0: jal         0x8013F604
    // 0x80148BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardKneeBendCheckInterruptGuard(rdram, ctx);
        goto after_3;
    // 0x80148BC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80148BC8: bnel        $v0, $zero, L_80148BEC
    if (ctx->r2 != 0) {
        // 0x80148BCC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80148BEC;
    }
    goto skip_3;
    // 0x80148BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x80148BD0: jal         0x80141F8C
    // 0x80148BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardPassCheckInterruptGuard(rdram, ctx);
        goto after_4;
    // 0x80148BD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80148BD8: bnel        $v0, $zero, L_80148BEC
    if (ctx->r2 != 0) {
        // 0x80148BDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80148BEC;
    }
    goto skip_4;
    // 0x80148BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x80148BE0: jal         0x80142258
    // 0x80148BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDokanStartCheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x80148BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80148BE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80148BEC:
    // 0x80148BEC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80148BF0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80148BF4: jr          $ra
    // 0x80148BF8: nop

    return;
    // 0x80148BF8: nop

;}
RECOMP_FUNC void gcAddDObjTransformTraRotSca(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F058: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000F05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F060: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000F064: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x8000F068: jal         0x80008CC0
    // 0x8000F06C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_0;
    // 0x8000F06C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8000F070: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000F074: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x8000F078: jal         0x80008CC0
    // 0x8000F07C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8000F07C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8000F080: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000F084: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000F088: jr          $ra
    // 0x8000F08C: nop

    return;
    // 0x8000F08C: nop

;}
RECOMP_FUNC void ftCommonJumpAerialMultiGetJumpInputType(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140150: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80140154: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140158: lb          $t6, 0x1C3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1C3);
    // 0x8014015C: slti        $at, $t6, 0x35
    ctx->r1 = SIGNED(ctx->r14) < 0X35 ? 1 : 0;
    // 0x80140160: bne         $at, $zero, L_80140170
    if (ctx->r1 != 0) {
        // 0x80140164: nop
    
            goto L_80140170;
    }
    // 0x80140164: nop

    // 0x80140168: b           L_8014018C
    // 0x8014016C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014018C;
    // 0x8014016C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80140170:
    // 0x80140170: jal         0x8014012C
    // 0x80140174: nop

    ftCommonJumpAerialMultiCheckJumpButtonHold(rdram, ctx);
        goto after_0;
    // 0x80140174: nop

    after_0:
    // 0x80140178: beql        $v0, $zero, L_8014018C
    if (ctx->r2 == 0) {
        // 0x8014017C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014018C;
    }
    goto skip_0;
    // 0x8014017C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80140180: b           L_8014018C
    // 0x80140184: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8014018C;
    // 0x80140184: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x80140188: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014018C:
    // 0x8014018C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80140190: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80140194: jr          $ra
    // 0x80140198: nop

    return;
    // 0x80140198: nop

;}
RECOMP_FUNC void mnPlayersVSMakeStockSetting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134094: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80134098: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013409C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801340A0: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x801340A4: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x801340A8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x801340AC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x801340B0: addiu       $t6, $t6, -0x48BC
    ctx->r14 = ADD32(ctx->r14, -0X48BC);
    // 0x801340B4: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801340B8: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x801340BC: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801340C0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801340C4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801340C8: addiu       $s2, $s2, -0x4288
    ctx->r18 = ADD32(ctx->r18, -0X4288);
    // 0x801340CC: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x801340D0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801340D4: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801340D8: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x801340DC: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801340E0: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x801340E4: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801340E8: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x801340EC: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801340F0: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x801340F4: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x801340F8: lw          $s0, 0x8($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X8);
    // 0x801340FC: beql        $s0, $zero, L_80134128
    if (ctx->r16 == 0) {
        // 0x80134100: lw          $t1, 0x58($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X58);
            goto L_80134128;
    }
    goto skip_0;
    // 0x80134100: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    skip_0:
L_80134104:
    // 0x80134104: jal         0x800096EC
    // 0x80134108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEjectSObj(rdram, ctx);
        goto after_0;
    // 0x80134108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8013410C: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x80134110: lw          $t0, 0x74($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X74);
    // 0x80134114: lw          $s0, 0x8($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X8);
    // 0x80134118: bne         $s0, $zero, L_80134104
    if (ctx->r16 != 0) {
        // 0x8013411C: nop
    
            goto L_80134104;
    }
    // 0x8013411C: nop

    // 0x80134120: addiu       $v0, $sp, 0x40
    ctx->r2 = ADD32(ctx->r29, 0X40);
    // 0x80134124: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
L_80134128:
    // 0x80134128: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8013412C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80134130: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x80134134: beq         $at, $zero, L_80134168
    if (ctx->r1 == 0) {
        // 0x80134138: lui         $a2, 0x4356
        ctx->r6 = S32(0X4356 << 16);
            goto L_80134168;
    }
    // 0x80134138: lui         $a2, 0x4356
    ctx->r6 = S32(0X4356 << 16);
    // 0x8013413C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80134140: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80134144: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80134148: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8013414C: lui         $a2, 0x4352
    ctx->r6 = S32(0X4352 << 16);
    // 0x80134150: lui         $a3, 0x41B8
    ctx->r7 = S32(0X41B8 << 16);
    // 0x80134154: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80134158: jal         0x80133BB0
    // 0x8013415C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    mnPlayersVSMakeGameRuleNumber(rdram, ctx);
        goto after_1;
    // 0x8013415C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_1:
    // 0x80134160: b           L_80134184
    // 0x80134164: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_80134184;
    // 0x80134164: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80134168:
    // 0x80134168: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8013416C: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80134170: lui         $a3, 0x41B8
    ctx->r7 = S32(0X41B8 << 16);
    // 0x80134174: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80134178: jal         0x80133BB0
    // 0x8013417C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    mnPlayersVSMakeGameRuleNumber(rdram, ctx);
        goto after_2;
    // 0x8013417C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
    // 0x80134180: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_80134184:
    // 0x80134184: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80134188: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8013418C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80134190: jr          $ra
    // 0x80134194: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80134194: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void grZebesMakeAcid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801080EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801080F0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801080F4: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x801080F8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x801080FC: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80108100: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80108104: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80108108: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x8010810C: lui         $v0, 0x0
    ctx->r2 = S32(0X0 << 16);
    // 0x80108110: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80108114: addiu       $v0, $v0, 0xB08
    ctx->r2 = ADD32(ctx->r2, 0XB08);
    // 0x80108118: addiu       $s2, $s2, 0x13F0
    ctx->r18 = ADD32(ctx->r18, 0X13F0);
    // 0x8010811C: subu        $s1, $t7, $v0
    ctx->r17 = SUB32(ctx->r15, ctx->r2);
    // 0x80108120: sw          $s1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r17;
    // 0x80108124: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80108128: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x8010812C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80108130: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80108134: jal         0x80009968
    // 0x80108138: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80108138: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010813C: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80108140: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80108144: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80108148: sw          $v0, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r2;
    // 0x8010814C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80108150: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80108154: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80108158: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x8010815C: jal         0x80009DF4
    // 0x80108160: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80108160: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80108164: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80108168: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010816C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80108170: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x80108174: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80108178: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8010817C: jal         0x8000F590
    // 0x80108180: addu        $a1, $t9, $s1
    ctx->r5 = ADD32(ctx->r25, ctx->r17);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_2;
    // 0x80108180: addu        $a1, $t9, $s1
    ctx->r5 = ADD32(ctx->r25, ctx->r17);
    after_2:
    // 0x80108184: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80108188: addiu       $t0, $t0, 0x8C0
    ctx->r8 = ADD32(ctx->r8, 0X8C0);
    // 0x8010818C: addu        $a1, $s1, $t0
    ctx->r5 = ADD32(ctx->r17, ctx->r8);
    // 0x80108190: jal         0x8000F8F4
    // 0x80108194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x80108194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80108198: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8010819C: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x801081A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801081A4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801081A8: jal         0x80008188
    // 0x801081AC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x801081AC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
    // 0x801081B0: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x801081B4: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x801081B8: addiu       $t2, $t2, 0xBD0
    ctx->r10 = ADD32(ctx->r10, 0XBD0);
    // 0x801081BC: addiu       $t1, $t1, 0xB90
    ctx->r9 = ADD32(ctx->r9, 0XB90);
    // 0x801081C0: addu        $a1, $s1, $t1
    ctx->r5 = ADD32(ctx->r17, ctx->r9);
    // 0x801081C4: addu        $a2, $s1, $t2
    ctx->r6 = ADD32(ctx->r17, ctx->r10);
    // 0x801081C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801081CC: jal         0x8000BED8
    // 0x801081D0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    gcAddAnimAll(rdram, ctx);
        goto after_5;
    // 0x801081D0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_5:
    // 0x801081D4: jal         0x8000DF34
    // 0x801081D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_6;
    // 0x801081D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801081DC: sb          $zero, 0x16($s2)
    MEM_B(0X16, ctx->r18) = 0;
    // 0x801081E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801081E4: lwc1        $f4, -0x14E4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X14E4);
    // 0x801081E8: sb          $zero, 0x17($s2)
    MEM_B(0X17, ctx->r18) = 0;
    // 0x801081EC: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801081F0: swc1        $f4, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f4.u32l;
    // 0x801081F4: lw          $t3, 0x1300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1300);
    // 0x801081F8: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801081FC: addiu       $t4, $t4, 0x14
    ctx->r12 = ADD32(ctx->r12, 0X14);
    // 0x80108200: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80108204: addiu       $t6, $t6, 0xBC
    ctx->r14 = ADD32(ctx->r14, 0XBC);
    // 0x80108208: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x8010820C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80108210: jal         0x80108088
    // 0x80108214: sw          $t7, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r15;
    grZebesAcidSetRandomWait(rdram, ctx);
        goto after_7;
    // 0x80108214: sw          $t7, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r15;
    after_7:
    // 0x80108218: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8010821C: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x80108220: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80108224: swc1        $f6, 0x20($t8)
    MEM_W(0X20, ctx->r24) = ctx->f6.u32l;
    // 0x80108228: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8010822C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80108230: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80108234: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80108238: jr          $ra
    // 0x8010823C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8010823C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gcDefaultFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B1C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000B1C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B1CC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000B1D0: jal         0x8000ADB0
    // 0x8000B1D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcParseGObjScript(rdram, ctx);
        goto after_0;
    // 0x8000B1D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000B1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B1DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000B1E0: jr          $ra
    // 0x8000B1E4: nop

    return;
    // 0x8000B1E4: nop

;}
RECOMP_FUNC void func_ovl65_8018F6DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F6DC: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018F6E0: lhu         $t6, 0x2FDC($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X2FDC);
    // 0x8018F6E4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8018F6E8: jr          $ra
    // 0x8018F6EC: sh          $t6, -0x1208($at)
    MEM_H(-0X1208, ctx->r1) = ctx->r14;
    return;
    // 0x8018F6EC: sh          $t6, -0x1208($at)
    MEM_H(-0X1208, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mnDataLabelsProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132164: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80132168: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8013216C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132170: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132174: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132178: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8013217C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132180: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132184: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x80132188: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x8013218C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132190: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132194: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80132198: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8013219C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801321A0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801321A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801321A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801321AC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801321B0: lui         $t7, 0xA078
    ctx->r15 = S32(0XA078 << 16);
    // 0x801321B4: ori         $t7, $t7, 0x14E6
    ctx->r15 = ctx->r15 | 0X14E6;
    // 0x801321B8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801321BC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801321C0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801321C4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801321C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801321CC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801321D0: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x801321D4: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x801321D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801321DC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801321E0: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801321E4: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x801321E8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801321EC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801321F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801321F4: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x801321F8: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801321FC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132200: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132204: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80132208: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x8013220C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80132210: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132214: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132218: lui         $t8, 0x38
    ctx->r24 = S32(0X38 << 16);
    // 0x8013221C: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80132220: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132224: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132228: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x8013222C: ori         $t8, $t8, 0x423C
    ctx->r24 = ctx->r24 | 0X423C;
    // 0x80132230: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132234: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132238: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013223C: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132240: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80132244: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132248: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8013224C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132250: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80132254: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132258: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x8013225C: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80132260: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132264: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132268: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8013226C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132270: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132274: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80132278: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x8013227C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132280: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132284: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132288: jal         0x800CCEAC
    // 0x8013228C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x8013228C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80132290: jal         0x800CCF00
    // 0x80132294: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80132294: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80132298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013229C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801322A0: jr          $ra
    // 0x801322A4: nop

    return;
    // 0x801322A4: nop

;}
RECOMP_FUNC void sc1PStageClearGetScoreDigitCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131CC8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131CCC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131CD0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80131CD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131CD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131CDC: blez        $a1, L_80131D54
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80131CE0: or          $s1, $a1, $zero
        ctx->r17 = ctx->r5 | 0;
            goto L_80131D54;
    }
    // 0x80131CE0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
L_80131CE4:
    // 0x80131CE4: addiu       $s0, $s1, -0x1
    ctx->r16 = ADD32(ctx->r17, -0X1);
    // 0x80131CE8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80131CEC: jal         0x80131B58
    // 0x80131CF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    sc1PStageClearGetPowerOf(rdram, ctx);
        goto after_0;
    // 0x80131CF0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_0:
    // 0x80131CF4: beq         $v0, $zero, L_80131D3C
    if (ctx->r2 == 0) {
        // 0x80131CF8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80131D3C;
    }
    // 0x80131CF8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80131CFC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x80131D00: jal         0x80131B58
    // 0x80131D04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    sc1PStageClearGetPowerOf(rdram, ctx);
        goto after_1;
    // 0x80131D04: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x80131D08: div         $zero, $s2, $v0
    lo = S32(S64(S32(ctx->r18)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r18)) % S64(S32(ctx->r2)));
    // 0x80131D0C: mflo        $v1
    ctx->r3 = lo;
    // 0x80131D10: bne         $v0, $zero, L_80131D1C
    if (ctx->r2 != 0) {
        // 0x80131D14: nop
    
            goto L_80131D1C;
    }
    // 0x80131D14: nop

    // 0x80131D18: break       7
    do_break(2148736280);
L_80131D1C:
    // 0x80131D1C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80131D20: bne         $v0, $at, L_80131D34
    if (ctx->r2 != ctx->r1) {
        // 0x80131D24: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80131D34;
    }
    // 0x80131D24: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80131D28: bne         $s2, $at, L_80131D34
    if (ctx->r18 != ctx->r1) {
        // 0x80131D2C: nop
    
            goto L_80131D34;
    }
    // 0x80131D2C: nop

    // 0x80131D30: break       6
    do_break(2148736304);
L_80131D34:
    // 0x80131D34: b           L_80131D3C
    // 0x80131D38: nop

        goto L_80131D3C;
    // 0x80131D38: nop

L_80131D3C:
    // 0x80131D3C: beq         $v1, $zero, L_80131D4C
    if (ctx->r3 == 0) {
        // 0x80131D40: nop
    
            goto L_80131D4C;
    }
    // 0x80131D40: nop

    // 0x80131D44: b           L_80131D58
    // 0x80131D48: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80131D58;
    // 0x80131D48: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
L_80131D4C:
    // 0x80131D4C: bne         $s0, $zero, L_80131CE4
    if (ctx->r16 != 0) {
        // 0x80131D50: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_80131CE4;
    }
    // 0x80131D50: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
L_80131D54:
    // 0x80131D54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80131D58:
    // 0x80131D58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80131D5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131D60: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131D64: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131D68: jr          $ra
    // 0x80131D6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80131D6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl8_803847A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803847A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803847A4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803847A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803847AC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803847B0: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x803847B4: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x803847B8: bne         $a0, $zero, L_803847D0
    if (ctx->r4 != 0) {
        // 0x803847BC: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_803847D0;
    }
    // 0x803847BC: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x803847C0: jal         0x803717A0
    // 0x803847C4: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803847C4: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_0:
    // 0x803847C8: beq         $v0, $zero, L_803848B8
    if (ctx->r2 == 0) {
        // 0x803847CC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803848B8;
    }
    // 0x803847CC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803847D0:
    // 0x803847D0: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x803847D4: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    // 0x803847D8: addiu       $a1, $s0, 0xA8
    ctx->r5 = ADD32(ctx->r16, 0XA8);
    // 0x803847DC: bnel        $t6, $zero, L_80384800
    if (ctx->r14 != 0) {
        // 0x803847E0: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_80384800;
    }
    goto skip_0;
    // 0x803847E0: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x803847E4: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x803847E8: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x803847EC: jal         0x803717E0
    // 0x803847F0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803847F0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x803847F4: jal         0x8037C2D0
    // 0x803847F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803847F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x803847FC: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_80384800:
    // 0x80384800: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80384804: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80384808: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x8038480C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80384810: jal         0x8037345C
    // 0x80384814: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_8037345C(rdram, ctx);
        goto after_3;
    // 0x80384814: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x80384818: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038481C: addiu       $t8, $t8, -0x2C60
    ctx->r24 = ADD32(ctx->r24, -0X2C60);
    // 0x80384820: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80384824: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80384828: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8038482C: addiu       $t9, $t9, -0x2B40
    ctx->r25 = ADD32(ctx->r25, -0X2B40);
    // 0x80384830: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x80384834: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80384838: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8038483C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80384840: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80384844: addiu       $t1, $t1, -0x29E8
    ctx->r9 = ADD32(ctx->r9, -0X29E8);
    // 0x80384848: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8038484C: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80384850: sh          $t3, 0x3C($s0)
    MEM_H(0X3C, ctx->r16) = ctx->r11;
    // 0x80384854: jal         0x8037E80C
    // 0x80384858: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    func_ovl8_8037E80C(rdram, ctx);
        goto after_4;
    // 0x80384858: swc1        $f4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f4.u32l;
    after_4:
    // 0x8038485C: sh          $v0, 0x44($s0)
    MEM_H(0X44, ctx->r16) = ctx->r2;
    // 0x80384860: beq         $s0, $zero, L_8038486C
    if (ctx->r16 == 0) {
        // 0x80384864: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8038486C;
    }
    // 0x80384864: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80384868: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
L_8038486C:
    // 0x8038486C: lhu         $t4, 0x8($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X8);
    // 0x80384870: lh          $t5, 0x44($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X44);
    // 0x80384874: sw          $zero, 0x48($s0)
    MEM_W(0X48, ctx->r16) = 0;
    // 0x80384878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8038487C: div         $zero, $t4, $t5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r13)));
    // 0x80384880: mflo        $t6
    ctx->r14 = lo;
    // 0x80384884: sh          $t6, 0x46($s0)
    MEM_H(0X46, ctx->r16) = ctx->r14;
    // 0x80384888: bne         $t5, $zero, L_80384894
    if (ctx->r13 != 0) {
        // 0x8038488C: nop
    
            goto L_80384894;
    }
    // 0x8038488C: nop

    // 0x80384890: break       7
    do_break(2151172240);
L_80384894:
    // 0x80384894: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80384898: bne         $t5, $at, L_803848AC
    if (ctx->r13 != ctx->r1) {
        // 0x8038489C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_803848AC;
    }
    // 0x8038489C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x803848A0: bne         $t4, $at, L_803848AC
    if (ctx->r12 != ctx->r1) {
        // 0x803848A4: nop
    
            goto L_803848AC;
    }
    // 0x803848A4: nop

    // 0x803848A8: break       6
    do_break(2151172264);
L_803848AC:
    // 0x803848AC: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x803848B0: jal         0x80384AE8
    // 0x803848B4: nop

    func_ovl8_80384AE8(rdram, ctx);
        goto after_5;
    // 0x803848B4: nop

    after_5:
L_803848B8:
    // 0x803848B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x803848BC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x803848C0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x803848C4: jr          $ra
    // 0x803848C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x803848C8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftPublicDefeatedAddID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801650F8: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x801650FC: addiu       $v1, $v1, -0x3020
    ctx->r3 = ADD32(ctx->r3, -0X3020);
    // 0x80165100: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80165104: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80165108: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8016510C: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x80165110: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80165114: sh          $a0, -0x3038($at)
    MEM_H(-0X3038, ctx->r1) = ctx->r4;
    // 0x80165118: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8016511C: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80165120: bne         $t7, $at, L_8016512C
    if (ctx->r15 != ctx->r1) {
        // 0x80165124: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_8016512C;
    }
    // 0x80165124: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80165128: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_8016512C:
    // 0x8016512C: jr          $ra
    // 0x80165130: nop

    return;
    // 0x80165130: nop

;}
RECOMP_FUNC void itTaruMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A1B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8017A1BC: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8017A1C0: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8017A1C4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8017A1C8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8017A1CC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017A1D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017A1D4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017A1D8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8017A1DC: addiu       $a1, $a1, -0x5BB0
    ctx->r5 = ADD32(ctx->r5, -0X5BB0);
    // 0x8017A1E0: jal         0x8016E174
    // 0x8017A1E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017A1E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017A1E8: beq         $v0, $zero, L_8017A22C
    if (ctx->r2 == 0) {
        // 0x8017A1EC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8017A22C;
    }
    // 0x8017A1EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8017A1F0: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x8017A1F4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017A1F8: lbu         $t8, 0x2CF($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2CF);
    // 0x8017A1FC: lbu         $t1, 0x2D3($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X2D3);
    // 0x8017A200: swc1        $f4, 0x350($a0)
    MEM_W(0X350, ctx->r4) = ctx->f4.u32l;
    // 0x8017A204: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x8017A208: ori         $t2, $t1, 0x4
    ctx->r10 = ctx->r9 | 0X4;
    // 0x8017A20C: sb          $t9, 0x2CF($a0)
    MEM_B(0X2CF, ctx->r4) = ctx->r25;
    // 0x8017A210: sb          $t2, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r10;
    // 0x8017A214: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8017A218: jal         0x80111EC0
    // 0x8017A21C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_1;
    // 0x8017A21C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8017A220: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017A224: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8017A228: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_8017A22C:
    // 0x8017A22C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A230: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8017A234: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8017A238: jr          $ra
    // 0x8017A23C: nop

    return;
    // 0x8017A23C: nop

;}
RECOMP_FUNC void func_ovl26_8013A468(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013A468: jr          $ra
    // 0x8013A46C: nop

    return;
    // 0x8013A46C: nop

;}
RECOMP_FUNC void ftBossDeadCenterSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015ADE8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015ADEC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015ADF0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015ADF4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015ADF8: addiu       $a1, $zero, 0xFA
    ctx->r5 = ADD32(0, 0XFA);
    // 0x8015ADFC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015AE00: jal         0x800E6F24
    // 0x8015AE04: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015AE04: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015AE08: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8015AE0C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015AE10: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015AE14: lw          $v0, 0x84($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X84);
    // 0x8015AE18: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
    // 0x8015AE1C: lwc1        $f12, -0x37A0($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X37A0);
    // 0x8015AE20: jal         0x800303F0
    // 0x8015AE24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8015AE24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x8015AE28: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8015AE2C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8015AE30: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015AE34: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015AE38: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8015AE3C: swc1        $f8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f8.u32l;
    // 0x8015AE40: jal         0x80035CD0
    // 0x8015AE44: lwc1        $f12, -0x379C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X379C);
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8015AE44: lwc1        $f12, -0x379C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X379C);
    after_2:
    // 0x8015AE48: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8015AE4C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8015AE50: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015AE54: addiu       $t7, $zero, 0xC8
    ctx->r15 = ADD32(0, 0XC8);
    // 0x8015AE58: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8015AE5C: sh          $t7, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r15;
    // 0x8015AE60: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8015AE64: swc1        $f18, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f18.u32l;
    // 0x8015AE68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015AE6C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015AE70: jr          $ra
    // 0x8015AE74: nop

    return;
    // 0x8015AE74: nop

;}
RECOMP_FUNC void func_ovl8_80375118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375118: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037511C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80375120: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80375124: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80375128: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8037512C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80375130: jal         0x80377108
    // 0x80375134: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    func_ovl8_80377108(rdram, ctx);
        goto after_0;
    // 0x80375134: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_0:
    // 0x80375138: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x8037513C: lw          $v1, 0x38($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X38);
    // 0x80375140: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80375144: beq         $a3, $zero, L_80375150
    if (ctx->r7 == 0) {
        // 0x80375148: lw          $a2, 0x4C($v1)
        ctx->r6 = MEM_W(ctx->r3, 0X4C);
            goto L_80375150;
    }
    // 0x80375148: lw          $a2, 0x4C($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X4C);
    // 0x8037514C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80375150:
    // 0x80375150: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80375154: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80375158: beq         $a3, $zero, L_80375164
    if (ctx->r7 == 0) {
        // 0x8037515C: sh          $t6, 0x28($sp)
        MEM_H(0X28, ctx->r29) = ctx->r14;
            goto L_80375164;
    }
    // 0x8037515C: sh          $t6, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r14;
    // 0x80375160: lw          $v0, 0x38($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X38);
L_80375164:
    // 0x80375164: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x80375168: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8037516C: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    // 0x80375170: lw          $v1, 0x20($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X20);
    // 0x80375174: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80375178: lh          $t8, 0x48($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X48);
    // 0x8037517C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x80375180: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x80375184: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    // 0x80375188: jalr        $t9
    // 0x8037518C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8037518C: nop

    after_1:
    // 0x80375190: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80375194: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80375198: lw          $v1, 0x38($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X38);
    // 0x8037519C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x803751A0: lw          $t9, 0x94($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X94);
    // 0x803751A4: lh          $t0, 0x90($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X90);
    // 0x803751A8: jalr        $t9
    // 0x803751AC: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x803751AC: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    after_2:
    // 0x803751B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803751B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x803751B8: jr          $ra
    // 0x803751BC: nop

    return;
    // 0x803751BC: nop

;}
RECOMP_FUNC void func_ovl63_8018DDBC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DDBC: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018DDC0: addiu       $a2, $a2, -0x1618
    ctx->r6 = ADD32(ctx->r6, -0X1618);
    // 0x8018DDC4: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x8018DDC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DDCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DDD0: lbu         $v1, 0xF($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XF);
    // 0x8018DDD4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DDD8: lw          $a0, -0x160C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X160C);
    // 0x8018DDDC: bne         $v1, $zero, L_8018DDF0
    if (ctx->r3 != 0) {
        // 0x8018DDE0: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_8018DDF0;
    }
    // 0x8018DDE0: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x8018DDE4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018DDE8: b           L_8018DE8C
    // 0x8018DDEC: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
        goto L_8018DE8C;
    // 0x8018DDEC: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
L_8018DDF0:
    // 0x8018DDF0: lhu         $t7, 0xC($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0XC);
    // 0x8018DDF4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018DDF8: addiu       $t1, $zero, -0x28
    ctx->r9 = ADD32(0, -0X28);
    // 0x8018DDFC: addiu       $t8, $t7, -0x96
    ctx->r24 = ADD32(ctx->r15, -0X96);
    // 0x8018DE00: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8018DE04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018DE08: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8018DE0C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018DE10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DE14: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8018DE18: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8018DE1C: lbu         $t0, 0xE($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0XE);
    // 0x8018DE20: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018DE24: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8018DE28: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x8018DE2C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8018DE30: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018DE34: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018DE38: bne         $v1, $at, L_8018DE50
    if (ctx->r3 != ctx->r1) {
        // 0x8018DE3C: swc1        $f10, 0x20($v0)
        MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
            goto L_8018DE50;
    }
    // 0x8018DE3C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8018DE40: lw          $t3, 0x74($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X74);
    // 0x8018DE44: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8018DE48: b           L_8018DE60
    // 0x8018DE4C: sb          $zero, 0x54($t4)
    MEM_B(0X54, ctx->r12) = 0;
        goto L_8018DE60;
    // 0x8018DE4C: sb          $zero, 0x54($t4)
    MEM_B(0X54, ctx->r12) = 0;
L_8018DE50:
    // 0x8018DE50: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8018DE54: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8018DE58: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x8018DE5C: sb          $t5, 0x54($t7)
    MEM_B(0X54, ctx->r15) = ctx->r13;
L_8018DE60:
    // 0x8018DE60: lw          $t9, -0x190C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X190C);
    // 0x8018DE64: lw          $t1, -0x1620($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X1620);
    // 0x8018DE68: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8018DE6C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018DE70: jal         0x8000BED8
    // 0x8018DE74: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    gcAddAnimAll(rdram, ctx);
        goto after_0;
    // 0x8018DE74: addu        $a2, $t9, $t1
    ctx->r6 = ADD32(ctx->r25, ctx->r9);
    after_0:
    // 0x8018DE78: jal         0x8000DF34
    // 0x8018DE7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x8018DE7C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8018DE80: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8018DE84: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DE88: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
L_8018DE8C:
    // 0x8018DE8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DE90: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DE94: sb          $v1, -0x15DF($at)
    MEM_B(-0X15DF, ctx->r1) = ctx->r3;
    // 0x8018DE98: jr          $ra
    // 0x8018DE9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8018DE9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void efManagerNessPKThunderTrailMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102848: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010284C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102850: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80102854: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80102858: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010285C: addiu       $a0, $a0, -0x1BBC
    ctx->r4 = ADD32(ctx->r4, -0X1BBC);
    // 0x80102860: jal         0x800FDAFC
    // 0x80102864: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80102864: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    after_0:
    // 0x80102868: bne         $v0, $zero, L_80102878
    if (ctx->r2 != 0) {
        // 0x8010286C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102878;
    }
    // 0x8010286C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102870: b           L_801028B0
    // 0x80102874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801028B0;
    // 0x80102874: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102878:
    // 0x80102878: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8010287C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80102880: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80102884: sw          $zero, 0x18($v0)
    MEM_W(0X18, ctx->r2) = 0;
    // 0x80102888: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x8010288C: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80102890: swc1        $f4, 0x24($t9)
    MEM_W(0X24, ctx->r25) = ctx->f4.u32l;
    // 0x80102894: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80102898: lw          $t1, 0xB24($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XB24);
    // 0x8010289C: lw          $v1, 0x84($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X84);
    // 0x801028A0: sw          $a0, 0x2B8($v1)
    MEM_W(0X2B8, ctx->r3) = ctx->r4;
    // 0x801028A4: jal         0x80102630
    // 0x801028A8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    efManagerNessPKThunderTrailProcUpdate(rdram, ctx);
        goto after_1;
    // 0x801028A8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x801028AC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_801028B0:
    // 0x801028B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801028B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801028B8: jr          $ra
    // 0x801028BC: nop

    return;
    // 0x801028BC: nop

;}
RECOMP_FUNC void mnVSOptionsGetPowerOf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B4C: bne         $a1, $zero, L_80131B5C
    if (ctx->r5 != 0) {
        // 0x80131B50: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80131B5C;
    }
    // 0x80131B50: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80131B54: jr          $ra
    // 0x80131B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B5C:
    // 0x80131B5C: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80131B60: bne         $at, $zero, L_80131BE0
    if (ctx->r1 != 0) {
        // 0x80131B64: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80131BE0;
    }
    // 0x80131B64: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80131B68: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x80131B6C: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80131B70: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x80131B74: beq         $a3, $zero, L_80131B98
    if (ctx->r7 == 0) {
        // 0x80131B78: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_80131B98;
    }
    // 0x80131B78: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
L_80131B7C:
    // 0x80131B7C: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B80: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80131B84: mflo        $v1
    ctx->r3 = lo;
    // 0x80131B88: bne         $a2, $v0, L_80131B7C
    if (ctx->r6 != ctx->r2) {
        // 0x80131B8C: nop
    
            goto L_80131B7C;
    }
    // 0x80131B8C: nop

    // 0x80131B90: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80131B94: beq         $v0, $a1, L_80131BE0
    if (ctx->r2 == ctx->r5) {
        // 0x80131B98: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80131BE0;
    }
L_80131B98:
    // 0x80131B98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80131B9C:
    // 0x80131B9C: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BA0: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80131BA4: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BA8: nop

    // 0x80131BAC: nop

    // 0x80131BB0: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BB4: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BB8: nop

    // 0x80131BBC: nop

    // 0x80131BC0: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BC4: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BC8: nop

    // 0x80131BCC: nop

    // 0x80131BD0: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BD4: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BD8: bne         $v0, $a1, L_80131B9C
    if (ctx->r2 != ctx->r5) {
        // 0x80131BDC: nop
    
            goto L_80131B9C;
    }
    // 0x80131BDC: nop

L_80131BE0:
    // 0x80131BE0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131BE4: jr          $ra
    // 0x80131BE8: nop

    return;
    // 0x80131BE8: nop

;}

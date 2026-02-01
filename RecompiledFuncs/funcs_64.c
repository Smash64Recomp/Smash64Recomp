#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnDataCheckSoundTestUnlocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80131B28: lbu         $t6, 0x4937($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4937);
    // 0x80131B2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131B30: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x80131B34: beq         $t7, $zero, L_80131B44
    if (ctx->r15 == 0) {
        // 0x80131B38: nop
    
            goto L_80131B44;
    }
    // 0x80131B38: nop

    // 0x80131B3C: jr          $ra
    // 0x80131B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B44:
    // 0x80131B44: jr          $ra
    // 0x80131B48: nop

    return;
    // 0x80131B48: nop

;}
RECOMP_FUNC void mnPlayers1PGameCheckFighterLocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801326C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801326CC: beq         $a0, $at, L_80132768
    if (ctx->r4 == ctx->r1) {
        // 0x801326D0: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80132768;
    }
    // 0x801326D0: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801326D4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801326D8: beq         $a0, $at, L_80132744
    if (ctx->r4 == ctx->r1) {
        // 0x801326DC: lui         $t0, 0x8014
        ctx->r8 = S32(0X8014 << 16);
            goto L_80132744;
    }
    // 0x801326DC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801326E0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801326E4: beq         $a0, $at, L_80132720
    if (ctx->r4 == ctx->r1) {
        // 0x801326E8: lui         $t8, 0x8014
        ctx->r24 = S32(0X8014 << 16);
            goto L_80132720;
    }
    // 0x801326E8: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801326EC: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801326F0: bne         $a0, $at, L_8013278C
    if (ctx->r4 != ctx->r1) {
        // 0x801326F4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013278C;
    }
    // 0x801326F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801326F8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801326FC: lhu         $t6, -0x7038($t6)
    ctx->r14 = MEM_HU(ctx->r14, -0X7038);
    // 0x80132700: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80132704: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x80132708: beq         $t7, $zero, L_80132718
    if (ctx->r15 == 0) {
        // 0x8013270C: nop
    
            goto L_80132718;
    }
    // 0x8013270C: nop

    // 0x80132710: jr          $ra
    // 0x80132714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132714: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132718:
    // 0x80132718: jr          $ra
    // 0x8013271C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013271C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132720:
    // 0x80132720: lhu         $t8, -0x7038($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X7038);
    // 0x80132724: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80132728: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x8013272C: beq         $t9, $zero, L_8013273C
    if (ctx->r25 == 0) {
        // 0x80132730: nop
    
            goto L_8013273C;
    }
    // 0x80132730: nop

    // 0x80132734: jr          $ra
    // 0x80132738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132738: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013273C:
    // 0x8013273C: jr          $ra
    // 0x80132740: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132740: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132744:
    // 0x80132744: lhu         $t0, -0x7038($t0)
    ctx->r8 = MEM_HU(ctx->r8, -0X7038);
    // 0x80132748: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8013274C: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80132750: beq         $t1, $zero, L_80132760
    if (ctx->r9 == 0) {
        // 0x80132754: nop
    
            goto L_80132760;
    }
    // 0x80132754: nop

    // 0x80132758: jr          $ra
    // 0x8013275C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013275C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132760:
    // 0x80132760: jr          $ra
    // 0x80132764: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132764: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132768:
    // 0x80132768: lhu         $t2, -0x7038($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X7038);
    // 0x8013276C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80132770: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80132774: beq         $t3, $zero, L_80132784
    if (ctx->r11 == 0) {
        // 0x80132778: nop
    
            goto L_80132784;
    }
    // 0x80132778: nop

    // 0x8013277C: jr          $ra
    // 0x80132780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132780: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132784:
    // 0x80132784: jr          $ra
    // 0x80132788: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132788: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013278C:
    // 0x8013278C: jr          $ra
    // 0x80132790: nop

    return;
    // 0x80132790: nop

;}
RECOMP_FUNC void func_ovl8_8038442C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038442C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80384430: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384434: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80384438: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8038443C: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x80384440: jalr        $t9
    // 0x80384444: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80384444: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80384448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038444C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384450: jr          $ra
    // 0x80384454: nop

    return;
    // 0x80384454: nop

;}
RECOMP_FUNC void unref_80009E7C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009E7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009E80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009E84: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80009E88: bne         $a0, $zero, L_80009E98
    if (ctx->r4 != 0) {
        // 0x80009E8C: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80009E98;
    }
    // 0x80009E8C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80009E90: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80009E94: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_80009E98:
    // 0x80009E98: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80009E9C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80009EA0: lbu         $a2, 0xD($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0XD);
    // 0x80009EA4: lw          $a3, 0x28($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X28);
    // 0x80009EA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009EAC: jal         0x80009D78
    // 0x80009EB0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    gcLinkGObjDLCommon(rdram, ctx);
        goto after_0;
    // 0x80009EB0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80009EB4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80009EB8: jal         0x80007B98
    // 0x80009EBC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    gcAppendGObjToDLLinkedList(rdram, ctx);
        goto after_1;
    // 0x80009EBC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_1:
    // 0x80009EC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009EC4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009EC8: jr          $ra
    // 0x80009ECC: nop

    return;
    // 0x80009ECC: nop

;}
RECOMP_FUNC void lbParticleEjectGenerator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D3884: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D3888: addiu       $a1, $a1, 0x639C
    ctx->r5 = ADD32(ctx->r5, 0X639C);
    // 0x800D388C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800D3890: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D3894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D3898: beq         $v0, $zero, L_800D3968
    if (ctx->r2 == 0) {
        // 0x800D389C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D3968;
    }
    // 0x800D389C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D38A0:
    // 0x800D38A0: bnel        $v0, $a0, L_800D395C
    if (ctx->r2 != ctx->r4) {
        // 0x800D38A4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800D395C;
    }
    goto skip_0;
    // 0x800D38A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    skip_0:
    // 0x800D38A8: lbu         $t6, 0x8($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X8);
    // 0x800D38AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D38B0: bne         $t6, $at, L_800D38D8
    if (ctx->r14 != ctx->r1) {
        // 0x800D38B4: nop
    
            goto L_800D38D8;
    }
    // 0x800D38B4: nop

    // 0x800D38B8: lhu         $t7, 0x54($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X54);
    // 0x800D38BC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800D38C0: beq         $t7, $zero, L_800D38D8
    if (ctx->r15 == 0) {
        // 0x800D38C4: nop
    
            goto L_800D38D8;
    }
    // 0x800D38C4: nop

    // 0x800D38C8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800D38CC: sh          $t8, 0xE($a0)
    MEM_H(0XE, ctx->r4) = ctx->r24;
    // 0x800D38D0: b           L_800D3968
    // 0x800D38D4: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
        goto L_800D3968;
    // 0x800D38D4: swc1        $f4, 0x40($a0)
    MEM_W(0X40, ctx->r4) = ctx->f4.u32l;
L_800D38D8:
    // 0x800D38D8: bnel        $v1, $zero, L_800D38F0
    if (ctx->r3 != 0) {
        // 0x800D38DC: lw          $t0, 0x0($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X0);
            goto L_800D38F0;
    }
    goto skip_1;
    // 0x800D38DC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x800D38E0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800D38E4: b           L_800D38F4
    // 0x800D38E8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
        goto L_800D38F4;
    // 0x800D38E8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800D38EC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
L_800D38F0:
    // 0x800D38F0: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_800D38F4:
    // 0x800D38F4: lw          $a1, 0x4C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4C);
    // 0x800D38F8: beq         $a1, $zero, L_800D392C
    if (ctx->r5 == 0) {
        // 0x800D38FC: nop
    
            goto L_800D392C;
    }
    // 0x800D38FC: nop

    // 0x800D3900: lhu         $t1, 0x2A($a1)
    ctx->r9 = MEM_HU(ctx->r5, 0X2A);
    // 0x800D3904: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800D3908: sh          $t2, 0x2A($a1)
    MEM_H(0X2A, ctx->r5) = ctx->r10;
    // 0x800D390C: lw          $a1, 0x4C($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X4C);
    // 0x800D3910: lhu         $t3, 0x2A($a1)
    ctx->r11 = MEM_HU(ctx->r5, 0X2A);
    // 0x800D3914: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800D3918: bne         $t3, $zero, L_800D392C
    if (ctx->r11 != 0) {
        // 0x800D391C: nop
    
            goto L_800D392C;
    }
    // 0x800D391C: nop

    // 0x800D3920: jal         0x800CE188
    // 0x800D3924: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    lbParticleEjectTransform(rdram, ctx);
        goto after_0;
    // 0x800D3924: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x800D3928: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
L_800D392C:
    // 0x800D392C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800D3930: addiu       $v1, $v1, 0x6398
    ctx->r3 = ADD32(ctx->r3, 0X6398);
    // 0x800D3934: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800D3938: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D393C: addiu       $a0, $a0, 0x644A
    ctx->r4 = ADD32(ctx->r4, 0X644A);
    // 0x800D3940: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800D3944: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
    // 0x800D3948: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800D394C: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800D3950: b           L_800D3968
    // 0x800D3954: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
        goto L_800D3968;
    // 0x800D3954: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800D3958: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800D395C:
    // 0x800D395C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800D3960: bne         $v0, $zero, L_800D38A0
    if (ctx->r2 != 0) {
        // 0x800D3964: nop
    
            goto L_800D38A0;
    }
    // 0x800D3964: nop

L_800D3968:
    // 0x800D3968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D396C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D3970: jr          $ra
    // 0x800D3974: nop

    return;
    // 0x800D3974: nop

;}
RECOMP_FUNC void mvOpeningKirbyMakePosedWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD14: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DD18: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DD1C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DD20: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DD24: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018DD28: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DD2C: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8018DD30: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DD34: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DD38: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DD3C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DD40: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DD44: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DD48: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DD4C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DD50: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DD54: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DD58: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DD5C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DD60: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DD64: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DD68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DD6C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DD70: jal         0x8000B93C
    // 0x8018DD74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DD74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DD78: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DD7C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DD80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DD84: lui         $a1, 0x4352
    ctx->r5 = S32(0X4352 << 16);
    // 0x8018DD88: lui         $a2, 0x4120
    ctx->r6 = S32(0X4120 << 16);
    // 0x8018DD8C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DD90: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DD94: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8018DD98: jal         0x80007080
    // 0x8018DD9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DD9C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DDA0: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8018DDA4: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8018DDA8: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x8018DDAC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DDB0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DDB4: jr          $ra
    // 0x8018DDB8: nop

    return;
    // 0x8018DDB8: nop

;}
RECOMP_FUNC void mpProcessCheckTestCeilCollisionAdjNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DCF58: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800DCF5C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DCF60: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800DCF64: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800DCF68: lhu         $t6, 0x5A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X5A);
    // 0x800DCF6C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800DCF70: lw          $v1, 0x48($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X48);
    // 0x800DCF74: andi        $t7, $t6, 0xFBFF
    ctx->r15 = ctx->r14 & 0XFBFF;
    // 0x800DCF78: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800DCF7C: sh          $t7, 0x5A($a0)
    MEM_H(0X5A, ctx->r4) = ctx->r15;
    // 0x800DCF80: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800DCF84: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800DCF88: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800DCF8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DCF90: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DCF94: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DCF98: lhu         $t8, 0x1398($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1398);
    // 0x800DCF9C: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800DCFA0: addiu       $a3, $s0, 0x8C
    ctx->r7 = ADD32(ctx->r16, 0X8C);
    // 0x800DCFA4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800DCFA8: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800DCFAC: addiu       $v1, $s0, 0x94
    ctx->r3 = ADD32(ctx->r16, 0X94);
    // 0x800DCFB0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DCFB4: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800DCFB8: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800DCFBC: lwc1        $f18, 0x4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DCFC0: addiu       $v0, $s0, 0x90
    ctx->r2 = ADD32(ctx->r16, 0X90);
    // 0x800DCFC4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DCFC8: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800DCFCC: lhu         $t9, 0x5C($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X5C);
    // 0x800DCFD0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DCFD4: beql        $t8, $t9, L_800DD014
    if (ctx->r24 == ctx->r25) {
        // 0x800DCFD8: sw          $v0, 0x10($sp)
        MEM_W(0X10, ctx->r29) = ctx->r2;
            goto L_800DD014;
    }
    goto skip_0;
    // 0x800DCFD8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    skip_0:
    // 0x800DCFDC: addiu       $v0, $s0, 0x90
    ctx->r2 = ADD32(ctx->r16, 0X90);
    // 0x800DCFE0: addiu       $v1, $s0, 0x94
    ctx->r3 = ADD32(ctx->r16, 0X94);
    // 0x800DCFE4: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800DCFE8: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800DCFEC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800DCFF0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800DCFF4: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DCFF8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DCFFC: addiu       $a2, $s0, 0x68
    ctx->r6 = ADD32(ctx->r16, 0X68);
    // 0x800DD000: jal         0x800F64D4
    // 0x800DD004: addiu       $a3, $s0, 0x8C
    ctx->r7 = ADD32(ctx->r16, 0X8C);
    mpCollisionCheckCeilLineCollisionDiff(rdram, ctx);
        goto after_0;
    // 0x800DD004: addiu       $a3, $s0, 0x8C
    ctx->r7 = ADD32(ctx->r16, 0X8C);
    after_0:
    // 0x800DD008: b           L_800DD024
    // 0x800DD00C: nop

        goto L_800DD024;
    // 0x800DD00C: nop

    // 0x800DD010: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
L_800DD014:
    // 0x800DD014: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800DD018: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800DD01C: jal         0x800F5E90
    // 0x800DD020: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mpCollisionCheckCeilLineCollisionSame(rdram, ctx);
        goto after_1;
    // 0x800DD020: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
L_800DD024:
    // 0x800DD024: beql        $v0, $zero, L_800DD044
    if (ctx->r2 == 0) {
        // 0x800DD028: lhu         $v0, 0x58($s0)
        ctx->r2 = MEM_HU(ctx->r16, 0X58);
            goto L_800DD044;
    }
    goto skip_1;
    // 0x800DD028: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
    skip_1:
    // 0x800DD02C: lhu         $t0, 0x56($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X56);
    // 0x800DD030: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DD034: ori         $t1, $t0, 0x400
    ctx->r9 = ctx->r8 | 0X400;
    // 0x800DD038: b           L_800DD14C
    // 0x800DD03C: sh          $t1, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r9;
        goto L_800DD14C;
    // 0x800DD03C: sh          $t1, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r9;
    // 0x800DD040: lhu         $v0, 0x58($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X58);
L_800DD044:
    // 0x800DD044: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x800DD048: beq         $t2, $zero, L_800DD0C8
    if (ctx->r10 == 0) {
        // 0x800DD04C: andi        $t6, $v0, 0x20
        ctx->r14 = ctx->r2 & 0X20;
            goto L_800DD0C8;
    }
    // 0x800DD04C: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x800DD050: jal         0x800FAC64
    // 0x800DD054: lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA0);
    mpCollisionGetEdgeRightULineID(rdram, ctx);
        goto after_2;
    // 0x800DD054: lw          $a0, 0xA0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XA0);
    after_2:
    // 0x800DD058: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DD05C: beq         $v0, $at, L_800DD148
    if (ctx->r2 == ctx->r1) {
        // 0x800DD060: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800DD148;
    }
    // 0x800DD060: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800DD064: jal         0x800FA8A4
    // 0x800DD068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_3;
    // 0x800DD068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800DD06C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DD070: bne         $v0, $at, L_800DD148
    if (ctx->r2 != ctx->r1) {
        // 0x800DD074: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800DD148;
    }
    // 0x800DD074: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DD078: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD07C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DD080: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800DD084: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800DD088: jal         0x800F3E04
    // 0x800DD08C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    mpCollisionGetFCCommonCeil(rdram, ctx);
        goto after_4;
    // 0x800DD08C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x800DD090: beq         $v0, $zero, L_800DD148
    if (ctx->r2 == 0) {
        // 0x800DD094: lwc1        $f8, 0x38($sp)
        ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
            goto L_800DD148;
    }
    // 0x800DD094: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800DD098: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800DD09C: nop

    // 0x800DD0A0: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800DD0A4: nop

    // 0x800DD0A8: bc1fl       L_800DD14C
    if (!c1cs) {
        // 0x800DD0AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DD14C;
    }
    goto skip_2;
    // 0x800DD0AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x800DD0B0: lhu         $t4, 0x56($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X56);
    // 0x800DD0B4: sw          $s1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r17;
    // 0x800DD0B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DD0BC: ori         $t5, $t4, 0x400
    ctx->r13 = ctx->r12 | 0X400;
    // 0x800DD0C0: b           L_800DD14C
    // 0x800DD0C4: sh          $t5, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r13;
        goto L_800DD14C;
    // 0x800DD0C4: sh          $t5, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r13;
L_800DD0C8:
    // 0x800DD0C8: beql        $t6, $zero, L_800DD14C
    if (ctx->r14 == 0) {
        // 0x800DD0CC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DD14C;
    }
    goto skip_3;
    // 0x800DD0CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_3:
    // 0x800DD0D0: jal         0x800FADE4
    // 0x800DD0D4: lw          $a0, 0xB4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB4);
    mpCollisionGetEdgeLeftULineID(rdram, ctx);
        goto after_5;
    // 0x800DD0D4: lw          $a0, 0xB4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0XB4);
    after_5:
    // 0x800DD0D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800DD0DC: beq         $v0, $at, L_800DD148
    if (ctx->r2 == ctx->r1) {
        // 0x800DD0E0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800DD148;
    }
    // 0x800DD0E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800DD0E4: jal         0x800FA8A4
    // 0x800DD0E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mpCollisionGetLineTypeID(rdram, ctx);
        goto after_6;
    // 0x800DD0E8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x800DD0EC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800DD0F0: bne         $v0, $at, L_800DD148
    if (ctx->r2 != ctx->r1) {
        // 0x800DD0F4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800DD148;
    }
    // 0x800DD0F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800DD0F8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800DD0FC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DD100: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x800DD104: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x800DD108: jal         0x800F3E04
    // 0x800DD10C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    mpCollisionGetFCCommonCeil(rdram, ctx);
        goto after_7;
    // 0x800DD10C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_7:
    // 0x800DD110: beq         $v0, $zero, L_800DD148
    if (ctx->r2 == 0) {
        // 0x800DD114: lwc1        $f16, 0x38($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
            goto L_800DD148;
    }
    // 0x800DD114: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800DD118: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800DD11C: nop

    // 0x800DD120: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DD124: nop

    // 0x800DD128: bc1fl       L_800DD14C
    if (!c1cs) {
        // 0x800DD12C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800DD14C;
    }
    goto skip_4;
    // 0x800DD12C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x800DD130: lhu         $t8, 0x56($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X56);
    // 0x800DD134: sw          $s1, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->r17;
    // 0x800DD138: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800DD13C: ori         $t9, $t8, 0x400
    ctx->r25 = ctx->r24 | 0X400;
    // 0x800DD140: b           L_800DD14C
    // 0x800DD144: sh          $t9, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r25;
        goto L_800DD14C;
    // 0x800DD144: sh          $t9, 0x56($s0)
    MEM_H(0X56, ctx->r16) = ctx->r25;
L_800DD148:
    // 0x800DD148: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800DD14C:
    // 0x800DD14C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800DD150: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800DD154: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800DD158: jr          $ra
    // 0x800DD15C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800DD15C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void sc1PStageClearUpdateGameClearScore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013407C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134084: jal         0x80133F28
    // 0x80134088: nop

    sc1PStageClearCheckNoTimer(rdram, ctx);
        goto after_0;
    // 0x80134088: nop

    after_0:
    // 0x8013408C: bne         $v0, $zero, L_80134154
    if (ctx->r2 != 0) {
        // 0x80134090: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80134154;
    }
    // 0x80134090: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134094: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134098: lw          $t6, 0x53A8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X53A8);
    // 0x8013409C: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
    // 0x801340A0: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x801340A4: bne         $v1, $t6, L_801340C0
    if (ctx->r3 != ctx->r14) {
        // 0x801340A8: nop
    
            goto L_801340C0;
    }
    // 0x801340A8: nop

    // 0x801340AC: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801340B0: jal         0x801324FC
    // 0x801340B4: nop

    sc1PStageClearMakeTimerTextSObjs(rdram, ctx);
        goto after_1;
    // 0x801340B4: nop

    after_1:
    // 0x801340B8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801340BC: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_801340C0:
    // 0x801340C0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801340C4: lw          $t7, 0x53AC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X53AC);
    // 0x801340C8: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x801340CC: bne         $v1, $t7, L_801340E8
    if (ctx->r3 != ctx->r15) {
        // 0x801340D0: nop
    
            goto L_801340E8;
    }
    // 0x801340D0: nop

    // 0x801340D4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801340D8: jal         0x8013263C
    // 0x801340DC: nop

    sc1PStageClearMakeTimerDigits(rdram, ctx);
        goto after_2;
    // 0x801340DC: nop

    after_2:
    // 0x801340E0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801340E4: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_801340E8:
    // 0x801340E8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801340EC: lw          $t8, 0x53B0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X53B0);
    // 0x801340F0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801340F4: bne         $v1, $t8, L_80134130
    if (ctx->r3 != ctx->r24) {
        // 0x801340F8: nop
    
            goto L_80134130;
    }
    // 0x801340F8: nop

    // 0x801340FC: jal         0x80009A84
    // 0x80134100: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x80134100: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    after_3:
    // 0x80134104: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x80134108: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8013410C: jal         0x801327D4
    // 0x80134110: nop

    sc1PStageClearGetAppendTotalTimeScore(rdram, ctx);
        goto after_4;
    // 0x80134110: nop

    after_4:
    // 0x80134114: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134118: lw          $t9, 0x52E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X52E8);
    // 0x8013411C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134120: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134124: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x80134128: sw          $t0, 0x52E8($at)
    MEM_W(0X52E8, ctx->r1) = ctx->r8;
    // 0x8013412C: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_80134130:
    // 0x80134130: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80134134: lw          $t1, 0x53B4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X53B4);
    // 0x80134138: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013413C: bne         $v1, $t1, L_80134154
    if (ctx->r3 != ctx->r9) {
        // 0x80134140: nop
    
            goto L_80134154;
    }
    // 0x80134140: nop

    // 0x80134144: jal         0x80009A84
    // 0x80134148: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x80134148: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    after_5:
    // 0x8013414C: jal         0x80133F00
    // 0x80134150: nop

    sc1PStageClearUpdateBonusScore(rdram, ctx);
        goto after_6;
    // 0x80134150: nop

    after_6:
L_80134154:
    // 0x80134154: jal         0x80133F28
    // 0x80134158: nop

    sc1PStageClearCheckNoTimer(rdram, ctx);
        goto after_7;
    // 0x80134158: nop

    after_7:
    // 0x8013415C: bne         $v0, $zero, L_80134174
    if (ctx->r2 != 0) {
        // 0x80134160: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80134174;
    }
    // 0x80134160: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134164: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x80134168: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013416C: b           L_80134184
    // 0x80134170: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
        goto L_80134184;
    // 0x80134170: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
L_80134174:
    // 0x80134174: lui         $at, 0x42BC
    ctx->r1 = S32(0X42BC << 16);
    // 0x80134178: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013417C: nop

    // 0x80134180: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
L_80134184:
    // 0x80134184: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80134188: lw          $t2, 0x53B8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X53B8);
    // 0x8013418C: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
    // 0x80134190: bne         $v1, $t2, L_801341A8
    if (ctx->r3 != ctx->r10) {
        // 0x80134194: nop
    
            goto L_801341A8;
    }
    // 0x80134194: nop

    // 0x80134198: jal         0x801328CC
    // 0x8013419C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    sc1PStageClearMakeDamageTextSObjs(rdram, ctx);
        goto after_8;
    // 0x8013419C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    after_8:
    // 0x801341A0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801341A4: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_801341A8:
    // 0x801341A8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801341AC: lw          $t3, 0x53BC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X53BC);
    // 0x801341B0: bne         $v1, $t3, L_801341C8
    if (ctx->r3 != ctx->r11) {
        // 0x801341B4: nop
    
            goto L_801341C8;
    }
    // 0x801341B4: nop

    // 0x801341B8: jal         0x80132A20
    // 0x801341BC: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    sc1PStageClearMakeDamageDigits(rdram, ctx);
        goto after_9;
    // 0x801341BC: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    after_9:
    // 0x801341C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801341C4: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_801341C8:
    // 0x801341C8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801341CC: lw          $t4, 0x53C0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X53C0);
    // 0x801341D0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801341D4: bne         $v1, $t4, L_80134208
    if (ctx->r3 != ctx->r12) {
        // 0x801341D8: nop
    
            goto L_80134208;
    }
    // 0x801341D8: nop

    // 0x801341DC: jal         0x80009A84
    // 0x801341E0: lw          $a0, 0x5304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5304);
    gcEjectGObj(rdram, ctx);
        goto after_10;
    // 0x801341E0: lw          $a0, 0x5304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5304);
    after_10:
    // 0x801341E4: jal         0x80132BB4
    // 0x801341E8: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    sc1PStageClearGetAppendTotalDamageScore(rdram, ctx);
        goto after_11;
    // 0x801341E8: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    after_11:
    // 0x801341EC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801341F0: lw          $t5, 0x52E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X52E8);
    // 0x801341F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801341F8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801341FC: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80134200: sw          $t6, 0x52E8($at)
    MEM_W(0X52E8, ctx->r1) = ctx->r14;
    // 0x80134204: lw          $v1, 0x52CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X52CC);
L_80134208:
    // 0x80134208: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013420C: lw          $t7, 0x53C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X53C4);
    // 0x80134210: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134214: bne         $v1, $t7, L_80134274
    if (ctx->r3 != ctx->r15) {
        // 0x80134218: nop
    
            goto L_80134274;
    }
    // 0x80134218: nop

    // 0x8013421C: jal         0x80009A84
    // 0x80134220: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    gcEjectGObj(rdram, ctx);
        goto after_12;
    // 0x80134220: lw          $a0, 0x5310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5310);
    after_12:
    // 0x80134224: jal         0x80133F00
    // 0x80134228: nop

    sc1PStageClearUpdateBonusScore(rdram, ctx);
        goto after_13;
    // 0x80134228: nop

    after_13:
    // 0x8013422C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80134230: lw          $t8, 0x52D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X52D8);
    // 0x80134234: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134238: addiu       $v0, $v0, 0x5348
    ctx->r2 = ADD32(ctx->r2, 0X5348);
    // 0x8013423C: beq         $t8, $zero, L_80134268
    if (ctx->r24 == 0) {
        // 0x80134240: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80134268;
    }
    // 0x80134240: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134244: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134248: lw          $t9, 0x52CC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X52CC);
    // 0x8013424C: addiu       $v1, $v1, 0x5344
    ctx->r3 = ADD32(ctx->r3, 0X5344);
    // 0x80134250: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134254: addiu       $t0, $t9, 0xA
    ctx->r8 = ADD32(ctx->r25, 0XA);
    // 0x80134258: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8013425C: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80134260: b           L_80134274
    // 0x80134264: sw          $t0, 0x5340($at)
    MEM_W(0X5340, ctx->r1) = ctx->r8;
        goto L_80134274;
    // 0x80134264: sw          $t0, 0x5340($at)
    MEM_W(0X5340, ctx->r1) = ctx->r8;
L_80134268:
    // 0x80134268: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013426C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134270: sw          $t3, 0x533C($at)
    MEM_W(0X533C, ctx->r1) = ctx->r11;
L_80134274:
    // 0x80134274: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134278: lw          $v0, 0x52D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52D8);
    // 0x8013427C: beq         $v0, $zero, L_80134320
    if (ctx->r2 == 0) {
        // 0x80134280: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80134320;
    }
    // 0x80134280: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134284: lw          $a0, 0x5314($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5314);
    // 0x80134288: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x8013428C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80134290: beq         $a0, $zero, L_80134320
    if (ctx->r4 == 0) {
        // 0x80134294: nop
    
            goto L_80134320;
    }
    // 0x80134294: nop

    // 0x80134298: lw          $t4, 0x52CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X52CC);
    // 0x8013429C: lw          $t5, 0x5340($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X5340);
    // 0x801342A0: bne         $t4, $t5, L_80134320
    if (ctx->r12 != ctx->r13) {
        // 0x801342A4: nop
    
            goto L_80134320;
    }
    // 0x801342A4: nop

    // 0x801342A8: jal         0x80009A84
    // 0x801342AC: nop

    gcEjectGObj(rdram, ctx);
        goto after_14;
    // 0x801342AC: nop

    after_14:
    // 0x801342B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801342B4: lw          $a0, 0x52F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52F8);
    // 0x801342B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342BC: sw          $zero, 0x5314($at)
    MEM_W(0X5314, ctx->r1) = 0;
    // 0x801342C0: beq         $a0, $zero, L_801342EC
    if (ctx->r4 == 0) {
        // 0x801342C4: nop
    
            goto L_801342EC;
    }
    // 0x801342C4: nop

    // 0x801342C8: jal         0x80009A84
    // 0x801342CC: nop

    gcEjectGObj(rdram, ctx);
        goto after_15;
    // 0x801342CC: nop

    after_15:
    // 0x801342D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801342D8: sw          $zero, 0x52F8($at)
    MEM_W(0X52F8, ctx->r1) = 0;
    // 0x801342DC: jal         0x80009A84
    // 0x801342E0: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    gcEjectGObj(rdram, ctx);
        goto after_16;
    // 0x801342E0: lw          $a0, 0x52FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X52FC);
    after_16:
    // 0x801342E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342E8: sw          $zero, 0x52FC($at)
    MEM_W(0X52FC, ctx->r1) = 0;
L_801342EC:
    // 0x801342EC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801342F0: jal         0x80009A84
    // 0x801342F4: lw          $a0, 0x5300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5300);
    gcEjectGObj(rdram, ctx);
        goto after_17;
    // 0x801342F4: lw          $a0, 0x5300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5300);
    after_17:
    // 0x801342F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134300: sw          $zero, 0x5300($at)
    MEM_W(0X5300, ctx->r1) = 0;
    // 0x80134304: jal         0x80009A84
    // 0x80134308: lw          $a0, 0x5304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5304);
    gcEjectGObj(rdram, ctx);
        goto after_18;
    // 0x80134308: lw          $a0, 0x5304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5304);
    after_18:
    // 0x8013430C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134310: jal         0x801338A0
    // 0x80134314: sw          $zero, 0x5304($at)
    MEM_W(0X5304, ctx->r1) = 0;
    sc1PStageClearMakeBonusTable(rdram, ctx);
        goto after_19;
    // 0x80134314: sw          $zero, 0x5304($at)
    MEM_W(0X5304, ctx->r1) = 0;
    after_19:
    // 0x80134318: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013431C: lw          $v0, 0x52D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X52D8);
L_80134320:
    // 0x80134320: beql        $v0, $zero, L_80134334
    if (ctx->r2 == 0) {
        // 0x80134324: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80134334;
    }
    goto skip_0;
    // 0x80134324: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80134328: jal         0x80133F50
    // 0x8013432C: nop

    sc1PStageUpdateBonusStatAll(rdram, ctx);
        goto after_20;
    // 0x8013432C: nop

    after_20:
    // 0x80134330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134334:
    // 0x80134334: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80134338: jr          $ra
    // 0x8013433C: nop

    return;
    // 0x8013433C: nop

;}
RECOMP_FUNC void func_ovl28_801332D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801332D4: jr          $ra
    // 0x801332D8: nop

    return;
    // 0x801332D8: nop

;}
RECOMP_FUNC void ifCommonAnnounceSetAttr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112024: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80112028: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8011202C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80112030: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80112034: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80112038: addu        $s2, $s2, $t6
    ctx->r18 = ADD32(ctx->r18, ctx->r14);
    // 0x8011203C: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80112040: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80112044: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80112048: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8011204C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80112050: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80112054: blez        $a3, L_801120B0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80112058: lw          $s2, 0xD40($s2)
        ctx->r18 = MEM_W(ctx->r18, 0XD40);
            goto L_801120B0;
    }
    // 0x80112058: lw          $s2, 0xD40($s2)
    ctx->r18 = MEM_W(ctx->r18, 0XD40);
    // 0x8011205C: sll         $t7, $a3, 3
    ctx->r15 = S32(ctx->r7 << 3);
    // 0x80112060: addu        $s3, $t7, $a2
    ctx->r19 = ADD32(ctx->r15, ctx->r6);
    // 0x80112064: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80112068: addiu       $s5, $zero, 0x201
    ctx->r21 = ADD32(0, 0X201);
L_8011206C:
    // 0x8011206C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x80112070: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80112074: jal         0x800CCFDC
    // 0x80112078: addu        $a1, $t8, $s2
    ctx->r5 = ADD32(ctx->r24, ctx->r18);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80112078: addu        $a1, $t8, $s2
    ctx->r5 = ADD32(ctx->r24, ctx->r18);
    after_0:
    // 0x8011207C: sh          $s5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r21;
    // 0x80112080: lh          $t9, 0x0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X0);
    // 0x80112084: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80112088: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8011208C: nop

    // 0x80112090: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80112094: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80112098: lh          $t0, -0x6($s0)
    ctx->r8 = MEM_H(ctx->r16, -0X6);
    // 0x8011209C: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x801120A0: nop

    // 0x801120A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801120A8: bne         $s0, $s3, L_8011206C
    if (ctx->r16 != ctx->r19) {
        // 0x801120AC: swc1        $f10, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
            goto L_8011206C;
    }
    // 0x801120AC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_801120B0:
    // 0x801120B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801120B4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801120B8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801120BC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801120C0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801120C4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x801120C8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x801120CC: jr          $ra
    // 0x801120D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801120D0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonSquatRvCheckInterruptSquatWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014351C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80143520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80143524: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80143528: lb          $t6, 0x1C3($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X1C3);
    // 0x8014352C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80143530: slti        $at, $t6, -0x31
    ctx->r1 = SIGNED(ctx->r14) < -0X31 ? 1 : 0;
    // 0x80143534: bne         $at, $zero, L_8014354C
    if (ctx->r1 != 0) {
        // 0x80143538: nop
    
            goto L_8014354C;
    }
    // 0x80143538: nop

    // 0x8014353C: jal         0x801434CC
    // 0x80143540: nop

    ftCommonSquatRvSetStatus(rdram, ctx);
        goto after_0;
    // 0x80143540: nop

    after_0:
    // 0x80143544: b           L_8014354C
    // 0x80143548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014354C;
    // 0x80143548: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014354C:
    // 0x8014354C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80143550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80143554: jr          $ra
    // 0x80143558: nop

    return;
    // 0x80143558: nop

;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialNGetAngle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160894: bgez        $a0, L_801608A4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80160898: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801608A4;
    }
    // 0x80160898: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8016089C: b           L_801608A4
    // 0x801608A0: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
        goto L_801608A4;
    // 0x801608A0: negu        $v0, $a0
    ctx->r2 = SUB32(0, ctx->r4);
L_801608A4:
    // 0x801608A4: slti        $at, $v0, 0x33
    ctx->r1 = SIGNED(ctx->r2) < 0X33 ? 1 : 0;
    // 0x801608A8: bnel        $at, $zero, L_801608B8
    if (ctx->r1 != 0) {
        // 0x801608AC: addiu       $v0, $v0, -0xA
        ctx->r2 = ADD32(ctx->r2, -0XA);
            goto L_801608B8;
    }
    goto skip_0;
    // 0x801608AC: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
    skip_0:
    // 0x801608B0: addiu       $v0, $zero, 0x32
    ctx->r2 = ADD32(0, 0X32);
    // 0x801608B4: addiu       $v0, $v0, -0xA
    ctx->r2 = ADD32(ctx->r2, -0XA);
L_801608B8:
    // 0x801608B8: bgez        $v0, L_801608C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x801608BC: nop
    
            goto L_801608C4;
    }
    // 0x801608BC: nop

    // 0x801608C0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801608C4:
    // 0x801608C4: bgezl       $a0, L_801608D4
    if (SIGNED(ctx->r4) >= 0) {
        // 0x801608C8: sll         $t6, $v0, 4
        ctx->r14 = S32(ctx->r2 << 4);
            goto L_801608D4;
    }
    goto skip_1;
    // 0x801608C8: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    skip_1:
    // 0x801608CC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x801608D0: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
L_801608D4:
    // 0x801608D4: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x801608D8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x801608DC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x801608E0: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x801608E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801608E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801608EC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801608F0: lwc1        $f16, -0x36E0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X36E0);
    // 0x801608F4: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801608F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801608FC: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80160900: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80160904: jr          $ra
    // 0x80160908: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    return;
    // 0x80160908: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
;}
RECOMP_FUNC void func_ovl8_80387BF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387BF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80387BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80387BF8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80387BFC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80387C00: jal         0x80381B04
    // 0x80387C04: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    func_ovl8_80381B04(rdram, ctx);
        goto after_0;
    // 0x80387C04: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    after_0:
    // 0x80387C08: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80387C0C: jal         0x80373694
    // 0x80387C10: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    func_ovl8_80373694(rdram, ctx);
        goto after_1;
    // 0x80387C10: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80387C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80387C18: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80387C1C: jr          $ra
    // 0x80387C20: nop

    return;
    // 0x80387C20: nop

;}
RECOMP_FUNC void func_ovl8_8038125C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038125C: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80381260: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80381264: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80381268: lw          $t9, -0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X4);
    // 0x8038126C: jr          $ra
    // 0x80381270: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    return;
    // 0x80381270: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
;}
RECOMP_FUNC void ftMainCheckGetUpdateDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2CC0: lw          $t6, 0x190($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X190);
    // 0x800E2CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E2CC8: sll         $t8, $t6, 10
    ctx->r24 = S32(ctx->r14 << 10);
    // 0x800E2CCC: bgezl       $t8, L_800E2D00
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800E2CD0: lw          $t5, 0x190($a0)
        ctx->r13 = MEM_W(ctx->r4, 0X190);
            goto L_800E2D00;
    }
    goto skip_0;
    // 0x800E2CD0: lw          $t5, 0x190($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X190);
    skip_0:
    // 0x800E2CD4: lw          $t9, 0x30($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X30);
    // 0x800E2CD8: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800E2CDC: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800E2CE0: bgtz        $t1, L_800E2CFC
    if (SIGNED(ctx->r9) > 0) {
        // 0x800E2CE4: sw          $t1, 0x30($a0)
        MEM_W(0X30, ctx->r4) = ctx->r9;
            goto L_800E2CFC;
    }
    // 0x800E2CE4: sw          $t1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r9;
    // 0x800E2CE8: lbu         $t2, 0x191($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X191);
    // 0x800E2CEC: negu        $t4, $t1
    ctx->r12 = SUB32(0, ctx->r9);
    // 0x800E2CF0: andi        $t3, $t2, 0xFFDF
    ctx->r11 = ctx->r10 & 0XFFDF;
    // 0x800E2CF4: sb          $t3, 0x191($a0)
    MEM_B(0X191, ctx->r4) = ctx->r11;
    // 0x800E2CF8: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
L_800E2CFC:
    // 0x800E2CFC: lw          $t5, 0x190($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X190);
L_800E2D00:
    // 0x800E2D00: sll         $t7, $t5, 10
    ctx->r15 = S32(ctx->r13 << 10);
    // 0x800E2D04: bltz        $t7, L_800E2D3C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800E2D08: nop
    
            goto L_800E2D3C;
    }
    // 0x800E2D08: nop

    // 0x800E2D0C: lw          $t8, 0x7F0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X7F0);
    // 0x800E2D10: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800E2D14: lw          $t1, 0x7DC($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X7DC);
    // 0x800E2D18: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800E2D1C: sw          $t0, 0x7F0($a0)
    MEM_W(0X7F0, ctx->r4) = ctx->r8;
    // 0x800E2D20: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800E2D24: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E2D28: beq         $at, $zero, L_800E2D34
    if (ctx->r1 == 0) {
        // 0x800E2D2C: nop
    
            goto L_800E2D34;
    }
    // 0x800E2D2C: nop

    // 0x800E2D30: sw          $v0, 0x7DC($a0)
    MEM_W(0X7DC, ctx->r4) = ctx->r2;
L_800E2D34:
    // 0x800E2D34: jr          $ra
    // 0x800E2D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E2D38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E2D3C:
    // 0x800E2D3C: jr          $ra
    // 0x800E2D40: nop

    return;
    // 0x800E2D40: nop

;}
RECOMP_FUNC void mnPlayersVSPuckProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138FA0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80138FA4: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80138FA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80138FAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80138FB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80138FB4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80138FB8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80138FBC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80138FC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80138FC4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80138FC8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80138FCC: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80138FD0: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80138FD4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80138FD8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80138FDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80138FE0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80138FE4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80138FE8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80138FEC: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80138FF0: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x80138FF4: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80138FF8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80138FFC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80139000: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80139004: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80139008: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013900C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80139010: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80139014: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80139018: lw          $a1, -0x424C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X424C);
    // 0x8013901C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80139020: sll         $t9, $a1, 24
    ctx->r25 = S32(ctx->r5 << 24);
    // 0x80139024: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80139028: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x8013902C: sll         $t6, $a1, 8
    ctx->r14 = S32(ctx->r5 << 8);
    // 0x80139030: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80139034: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x80139038: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8013903C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80139040: lui         $t5, 0x33FD
    ctx->r13 = S32(0X33FD << 16);
    // 0x80139044: lui         $t4, 0xFC12
    ctx->r12 = S32(0XFC12 << 16);
    // 0x80139048: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013904C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80139050: ori         $t4, $t4, 0xFE25
    ctx->r12 = ctx->r12 | 0XFE25;
    // 0x80139054: ori         $t5, $t5, 0xF2F9
    ctx->r13 = ctx->r13 | 0XF2F9;
    // 0x80139058: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8013905C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80139060: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80139064: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80139068: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x8013906C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80139070: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80139074: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80139078: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x8013907C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80139080: jal         0x800CCF74
    // 0x80139084: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_0;
    // 0x80139084: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    after_0:
    // 0x80139088: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013908C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80139090: jr          $ra
    // 0x80139094: nop

    return;
    // 0x80139094: nop

;}
RECOMP_FUNC void ftSamusSpecialAirLwProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DFBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015DFC0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015DFC4: jal         0x8015DF00
    // 0x8015DFC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftSamusSpecialLwMakeBomb(rdram, ctx);
        goto after_0;
    // 0x8015DFC8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015DFCC: jal         0x800D94E8
    // 0x8015DFD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndSetFall(rdram, ctx);
        goto after_1;
    // 0x8015DFD0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015DFD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015DFD8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015DFDC: jr          $ra
    // 0x8015DFE0: nop

    return;
    // 0x8015DFE0: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157E7C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80157E80: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80157E84: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80157E88: lw          $t6, 0xAE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XAE8);
    // 0x80157E8C: bnel        $t6, $at, L_80157EA0
    if (ctx->r14 != ctx->r1) {
        // 0x80157E90: sw          $zero, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = 0;
            goto L_80157EA0;
    }
    goto skip_0;
    // 0x80157E90: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    skip_0:
    // 0x80157E94: b           L_80157EA0
    // 0x80157E98: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
        goto L_80157EA0;
    // 0x80157E98: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x80157E9C: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
L_80157EA0:
    // 0x80157EA0: sw          $zero, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = 0;
    // 0x80157EA4: jr          $ra
    // 0x80157EA8: sw          $zero, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = 0;
    return;
    // 0x80157EA8: sw          $zero, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = 0;
;}
RECOMP_FUNC void ftCommonFuraFuraSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801498A4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801498A8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801498AC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801498B0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801498B4: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x801498B8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801498BC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801498C0: addiu       $a1, $zero, 0xA4
    ctx->r5 = ADD32(0, 0XA4);
    // 0x801498C4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801498C8: jal         0x800E6F24
    // 0x801498CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801498CC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801498D0: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x801498D4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801498D8: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x801498DC: bne         $t7, $at, L_801498F0
    if (ctx->r15 != ctx->r1) {
        // 0x801498E0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801498F0;
    }
    // 0x801498E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801498E4: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x801498E8: b           L_801498F4
    // 0x801498EC: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
        goto L_801498F4;
    // 0x801498EC: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
L_801498F0:
    // 0x801498F0: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
L_801498F4:
    // 0x801498F4: lw          $t0, 0x2C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X2C);
    // 0x801498F8: addiu       $t1, $zero, 0x190
    ctx->r9 = ADD32(0, 0X190);
    // 0x801498FC: subu        $a1, $t1, $t0
    ctx->r5 = SUB32(ctx->r9, ctx->r8);
    // 0x80149900: bgtz        $a1, L_8014990C
    if (SIGNED(ctx->r5) > 0) {
        // 0x80149904: nop
    
            goto L_8014990C;
    }
    // 0x80149904: nop

    // 0x80149908: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8014990C:
    // 0x8014990C: jal         0x8014E3EC
    // 0x80149910: addiu       $a1, $a1, 0x5A
    ctx->r5 = ADD32(ctx->r5, 0X5A);
    ftCommonCaptureTrappedInitBreakoutVars(rdram, ctx);
        goto after_1;
    // 0x80149910: addiu       $a1, $a1, 0x5A
    ctx->r5 = ADD32(ctx->r5, 0X5A);
    after_1:
    // 0x80149914: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80149918: addiu       $a1, $zero, 0x25
    ctx->r5 = ADD32(0, 0X25);
    // 0x8014991C: jal         0x800E9814
    // 0x80149920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_2;
    // 0x80149920: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80149924: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80149928: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8014992C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80149930: jr          $ra
    // 0x80149934: nop

    return;
    // 0x80149934: nop

;}
RECOMP_FUNC void ftYoshiSpecialNSetCatchParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E310: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E314: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E318: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8015E31C: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x8015E320: addiu       $a3, $a3, -0x37C4
    ctx->r7 = ADD32(ctx->r7, -0X37C4);
    // 0x8015E324: jal         0x800E80A4
    // 0x8015E328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetCatchParams(rdram, ctx);
        goto after_0;
    // 0x8015E328: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8015E32C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E330: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E334: jr          $ra
    // 0x8015E338: nop

    return;
    // 0x8015E338: nop

;}
RECOMP_FUNC void ftDonkeySpecialAirHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B9B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B9BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B9C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015B9C4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015B9C8: lwc1        $f4, -0x3788($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3788);
    // 0x8015B9CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8015B9D0: jal         0x8015B8E8
    // 0x8015B9D4: swc1        $f4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f4.u32l;
    ftDonkeySpecialHiSetStatusFlagGA(rdram, ctx);
        goto after_0;
    // 0x8015B9D4: swc1        $f4, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f4.u32l;
    after_0:
    // 0x8015B9D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B9DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015B9E0: jr          $ra
    // 0x8015B9E4: nop

    return;
    // 0x8015B9E4: nop

;}
RECOMP_FUNC void ftPhysicsSetGroundVelFriction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8978: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D897C: lwc1        $f0, 0x60($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D8980: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D8984: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800D8988: nop

    // 0x800D898C: bc1fl       L_800D89BC
    if (!c1cs) {
        // 0x800D8990: sub.s       $f8, $f0, $f12
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
            goto L_800D89BC;
    }
    goto skip_0;
    // 0x800D8990: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    skip_0:
    // 0x800D8994: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x800D8998: swc1        $f4, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f4.u32l;
    // 0x800D899C: lwc1        $f6, 0x60($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D89A0: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800D89A4: nop

    // 0x800D89A8: bc1f        L_800D89D8
    if (!c1cs) {
        // 0x800D89AC: nop
    
            goto L_800D89D8;
    }
    // 0x800D89AC: nop

    // 0x800D89B0: jr          $ra
    // 0x800D89B4: swc1        $f2, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f2.u32l;
    return;
    // 0x800D89B4: swc1        $f2, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f2.u32l;
    // 0x800D89B8: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
L_800D89BC:
    // 0x800D89BC: swc1        $f8, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f8.u32l;
    // 0x800D89C0: lwc1        $f10, 0x60($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X60);
    // 0x800D89C4: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800D89C8: nop

    // 0x800D89CC: bc1f        L_800D89D8
    if (!c1cs) {
        // 0x800D89D0: nop
    
            goto L_800D89D8;
    }
    // 0x800D89D0: nop

    // 0x800D89D4: swc1        $f2, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->f2.u32l;
L_800D89D8:
    // 0x800D89D8: jr          $ra
    // 0x800D89DC: nop

    return;
    // 0x800D89DC: nop

;}
RECOMP_FUNC void mnPlayers1PBonusPuckAdjustPortraitEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801361AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801361B0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801361B4: addiu       $a1, $a1, 0x7648
    ctx->r5 = ADD32(ctx->r5, 0X7648);
    // 0x801361B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801361BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801361C0: jal         0x801323E0
    // 0x801361C4: lw          $a0, 0x20($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X20);
    mnPlayers1PBonusGetPortrait(rdram, ctx);
        goto after_0;
    // 0x801361C4: lw          $a0, 0x20($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X20);
    after_0:
    // 0x801361C8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801361CC: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x801361D0: bne         $at, $zero, L_801361E0
    if (ctx->r1 != 0) {
        // 0x801361D4: addiu       $a1, $a1, 0x7648
        ctx->r5 = ADD32(ctx->r5, 0X7648);
            goto L_801361E0;
    }
    // 0x801361D4: addiu       $a1, $a1, 0x7648
    ctx->r5 = ADD32(ctx->r5, 0X7648);
    // 0x801361D8: b           L_801361E4
    // 0x801361DC: addiu       $v1, $v0, -0x6
    ctx->r3 = ADD32(ctx->r2, -0X6);
        goto L_801361E4;
    // 0x801361DC: addiu       $v1, $v0, -0x6
    ctx->r3 = ADD32(ctx->r2, -0X6);
L_801361E0:
    // 0x801361E0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_801361E4:
    // 0x801361E4: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x801361E8: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801361EC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801361F0: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x801361F4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801361F8: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x801361FC: addiu       $t7, $t6, 0x19
    ctx->r15 = ADD32(ctx->r14, 0X19);
    // 0x80136200: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80136204: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80136208: bne         $at, $zero, L_80136218
    if (ctx->r1 != 0) {
        // 0x8013620C: cvt.s.w     $f14, $f4
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80136218;
    }
    // 0x8013620C: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80136210: b           L_8013621C
    // 0x80136214: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8013621C;
    // 0x80136214: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80136218:
    // 0x80136218: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8013621C:
    // 0x8013621C: lw          $t8, 0x4($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X4);
    // 0x80136220: lwc1        $f8, 0x60($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X60);
    // 0x80136224: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80136228: lw          $v0, 0x74($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X74);
    // 0x8013622C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80136230: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x80136234: lwc1        $f6, 0x58($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80136238: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013623C: add.s       $f12, $f14, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f14.fl + ctx->f16.fl;
    // 0x80136240: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80136244: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80136248: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8013624C: lwc1        $f8, 0x64($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X64);
    // 0x80136250: lwc1        $f6, 0x5C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80136254: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80136258: add.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8013625C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80136260: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80136264: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80136268: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013626C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80136270: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80136274: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80136278: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013627C: addiu       $t0, $t9, 0x24
    ctx->r8 = ADD32(ctx->r25, 0X24);
    // 0x80136280: bc1f        L_8013629C
    if (!c1cs) {
        // 0x80136284: add.s       $f2, $f10, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_8013629C;
    }
    // 0x80136284: add.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80136288: sub.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x8013628C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80136290: nop

    // 0x80136294: div.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80136298: swc1        $f8, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f8.u32l;
L_8013629C:
    // 0x8013629C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801362A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801362A4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801362A8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801362AC: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801362B0: add.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x801362B4: sub.s       $f12, $f4, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f16.fl;
    // 0x801362B8: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x801362BC: nop

    // 0x801362C0: bc1fl       L_801362E4
    if (!c1cs) {
        // 0x801362C4: mtc1        $t0, $f6
        ctx->f6.u32l = ctx->r8;
            goto L_801362E4;
    }
    goto skip_0;
    // 0x801362C4: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    skip_0:
    // 0x801362C8: sub.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x801362CC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801362D0: nop

    // 0x801362D4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x801362D8: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x801362DC: swc1        $f4, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f4.u32l;
    // 0x801362E0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
L_801362E4:
    // 0x801362E4: nop

    // 0x801362E8: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801362EC: add.s       $f12, $f0, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x801362F0: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x801362F4: nop

    // 0x801362F8: bc1fl       L_80136314
    if (!c1cs) {
        // 0x801362FC: lui         $at, 0x422C
        ctx->r1 = S32(0X422C << 16);
            goto L_80136314;
    }
    goto skip_1;
    // 0x801362FC: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
    skip_1:
    // 0x80136300: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80136304: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136308: div.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f18.fl);
    // 0x8013630C: swc1        $f10, 0x76AC($at)
    MEM_W(0X76AC, ctx->r1) = ctx->f10.u32l;
    // 0x80136310: lui         $at, 0x422C
    ctx->r1 = S32(0X422C << 16);
L_80136314:
    // 0x80136314: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136318: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8013631C: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80136320: sub.s       $f12, $f6, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x80136324: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80136328: nop

    // 0x8013632C: bc1fl       L_80136350
    if (!c1cs) {
        // 0x80136330: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80136350;
    }
    goto skip_2;
    // 0x80136330: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80136334: sub.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80136338: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013633C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80136340: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80136344: div.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f18.fl);
    // 0x80136348: swc1        $f6, 0x76AC($at)
    MEM_W(0X76AC, ctx->r1) = ctx->f6.u32l;
    // 0x8013634C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80136350:
    // 0x80136350: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136354: jr          $ra
    // 0x80136358: nop

    return;
    // 0x80136358: nop

;}
RECOMP_FUNC void mnPlayersVSGetPrevTimeValue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013ABDC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013ABE0: addiu       $t7, $t7, -0x46A4
    ctx->r15 = ADD32(ctx->r15, -0X46A4);
    // 0x8013ABE4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013ABE8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013ABEC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013ABF0: addiu       $t6, $sp, 0xC
    ctx->r14 = ADD32(ctx->r29, 0XC);
    // 0x8013ABF4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013ABF8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013ABFC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8013AC00: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8013AC04: addiu       $v1, $sp, 0x28
    ctx->r3 = ADD32(ctx->r29, 0X28);
    // 0x8013AC08: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8013AC0C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8013AC10: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8013AC14: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8013AC18: addiu       $v0, $sp, 0xC
    ctx->r2 = ADD32(ctx->r29, 0XC);
    // 0x8013AC1C: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8013AC20: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x8013AC24: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x8013AC28: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8013AC2C: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x8013AC30: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x8013AC34: lw          $t0, 0xC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC);
    // 0x8013AC38: bne         $a0, $t0, L_8013AC48
    if (ctx->r4 != ctx->r8) {
        // 0x8013AC3C: nop
    
            goto L_8013AC48;
    }
    // 0x8013AC3C: nop

    // 0x8013AC40: b           L_8013AC74
    // 0x8013AC44: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
        goto L_8013AC74;
    // 0x8013AC44: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8013AC48:
    // 0x8013AC48: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
L_8013AC4C:
    // 0x8013AC4C: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x8013AC50: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8013AC54: beql        $at, $zero, L_8013AC68
    if (ctx->r1 == 0) {
        // 0x8013AC58: sltu        $at, $v1, $v0
        ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
            goto L_8013AC68;
    }
    goto skip_0;
    // 0x8013AC58: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    skip_0:
    // 0x8013AC5C: b           L_8013AC74
    // 0x8013AC60: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_8013AC74;
    // 0x8013AC60: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8013AC64: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
L_8013AC68:
    // 0x8013AC68: beql        $at, $zero, L_8013AC4C
    if (ctx->r1 == 0) {
        // 0x8013AC6C: lw          $a1, 0x0($v1)
        ctx->r5 = MEM_W(ctx->r3, 0X0);
            goto L_8013AC4C;
    }
    goto skip_1;
    // 0x8013AC6C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x8013AC70: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_8013AC74:
    // 0x8013AC74: jr          $ra
    // 0x8013AC78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013AC78: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonAttackS4CheckInterruptTurn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015030C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80150310: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150314: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80150318: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8015031C: lb          $v1, 0x1C2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1C2);
    // 0x80150320: lw          $t7, 0xB28($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XB28);
    // 0x80150324: lw          $t0, 0x9C8($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X9C8);
    // 0x80150328: multu       $v1, $t7
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8015032C: mflo        $t8
    ctx->r24 = lo;
    // 0x80150330: slti        $at, $t8, 0x38
    ctx->r1 = SIGNED(ctx->r24) < 0X38 ? 1 : 0;
    // 0x80150334: bnel        $at, $zero, L_80150460
    if (ctx->r1 != 0) {
        // 0x80150338: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80150460;
    }
    goto skip_0;
    // 0x80150338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8015033C: lhu         $t9, 0x1BE($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X1BE);
    // 0x80150340: lhu         $t1, 0x1B4($a2)
    ctx->r9 = MEM_HU(ctx->r6, 0X1B4);
    // 0x80150344: and         $t2, $t9, $t1
    ctx->r10 = ctx->r25 & ctx->r9;
    // 0x80150348: beql        $t2, $zero, L_80150460
    if (ctx->r10 == 0) {
        // 0x8015034C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80150460;
    }
    goto skip_1;
    // 0x8015034C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80150350: lw          $a0, 0x84C($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X84C);
    // 0x80150354: beql        $a0, $zero, L_80150438
    if (ctx->r4 == 0) {
        // 0x80150358: lw          $t8, 0x100($t0)
        ctx->r24 = MEM_W(ctx->r8, 0X100);
            goto L_80150438;
    }
    goto skip_2;
    // 0x80150358: lw          $t8, 0x100($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X100);
    skip_2:
    // 0x8015035C: lhu         $t3, 0x1BC($a2)
    ctx->r11 = MEM_HU(ctx->r6, 0X1BC);
    // 0x80150360: lhu         $t4, 0x1B8($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X1B8);
    // 0x80150364: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80150368: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x8015036C: bnel        $t5, $zero, L_801503B4
    if (ctx->r13 != 0) {
        // 0x80150370: lw          $t6, 0x44($a2)
        ctx->r14 = MEM_W(ctx->r6, 0X44);
            goto L_801503B4;
    }
    goto skip_3;
    // 0x80150370: lw          $t6, 0x44($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X44);
    skip_3:
    // 0x80150374: lw          $v0, 0x10($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X10);
    // 0x80150378: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8015037C: beq         $v0, $at, L_801503B0
    if (ctx->r2 == ctx->r1) {
        // 0x80150380: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801503B0;
    }
    // 0x80150380: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80150384: bnel        $v0, $at, L_801503E4
    if (ctx->r2 != ctx->r1) {
        // 0x80150388: lw          $a1, 0x10($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X10);
            goto L_801503E4;
    }
    goto skip_4;
    // 0x80150388: lw          $a1, 0x10($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X10);
    skip_4:
    // 0x8015038C: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    // 0x80150390: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80150394: jal         0x80172890
    // 0x80150398: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    itMainCheckShootNoAmmo(rdram, ctx);
        goto after_0;
    // 0x80150398: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x8015039C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x801503A0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x801503A4: beq         $v0, $zero, L_801503E0
    if (ctx->r2 == 0) {
        // 0x801503A8: lw          $t0, 0x20($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X20);
            goto L_801503E0;
    }
    // 0x801503A8: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x801503AC: lb          $v1, 0x1C2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1C2);
L_801503B0:
    // 0x801503B0: lw          $t6, 0x44($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X44);
L_801503B4:
    // 0x801503B4: addiu       $a1, $zero, 0x6F
    ctx->r5 = ADD32(0, 0X6F);
    // 0x801503B8: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801503BC: mflo        $t7
    ctx->r15 = lo;
    // 0x801503C0: bltz        $t7, L_801503D0
    if (SIGNED(ctx->r15) < 0) {
        // 0x801503C4: nop
    
            goto L_801503D0;
    }
    // 0x801503C4: nop

    // 0x801503C8: b           L_801503D0
    // 0x801503CC: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
        goto L_801503D0;
    // 0x801503CC: addiu       $a1, $zero, 0x6E
    ctx->r5 = ADD32(0, 0X6E);
L_801503D0:
    // 0x801503D0: jal         0x80146690
    // 0x801503D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x801503D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801503D8: b           L_80150460
    // 0x801503DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80150460;
    // 0x801503DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801503E0:
    // 0x801503E0: lw          $a1, 0x10($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X10);
L_801503E4:
    // 0x801503E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801503E8: beq         $a1, $at, L_80150400
    if (ctx->r5 == ctx->r1) {
        // 0x801503EC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80150400;
    }
    // 0x801503EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801503F0: beq         $a1, $at, L_8015041C
    if (ctx->r5 == ctx->r1) {
        // 0x801503F4: nop
    
            goto L_8015041C;
    }
    // 0x801503F4: nop

    // 0x801503F8: b           L_80150438
    // 0x801503FC: lw          $t8, 0x100($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X100);
        goto L_80150438;
    // 0x801503FC: lw          $t8, 0x100($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X100);
L_80150400:
    // 0x80150400: jal         0x800E8044
    // 0x80150404: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftParamSetStickLR(rdram, ctx);
        goto after_2;
    // 0x80150404: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80150408: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015040C: jal         0x80146E94
    // 0x80150410: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftCommonItemSwingSetStatus(rdram, ctx);
        goto after_3;
    // 0x80150410: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80150414: b           L_80150460
    // 0x80150418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80150460;
    // 0x80150418: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8015041C:
    // 0x8015041C: jal         0x800E8044
    // 0x80150420: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftParamSetStickLR(rdram, ctx);
        goto after_4;
    // 0x80150420: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80150424: jal         0x80147844
    // 0x80150428: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonItemShootSetStatus(rdram, ctx);
        goto after_5;
    // 0x80150428: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x8015042C: b           L_80150460
    // 0x80150430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80150460;
    // 0x80150430: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80150434: lw          $t8, 0x100($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X100);
L_80150438:
    // 0x80150438: sll         $t1, $t8, 6
    ctx->r9 = S32(ctx->r24 << 6);
    // 0x8015043C: bgezl       $t1, L_80150460
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80150440: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80150460;
    }
    goto skip_5;
    // 0x80150440: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x80150444: jal         0x800E8044
    // 0x80150448: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftParamSetStickLR(rdram, ctx);
        goto after_6;
    // 0x80150448: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x8015044C: jal         0x8014FFE0
    // 0x80150450: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonAttackS4SetStatus(rdram, ctx);
        goto after_7;
    // 0x80150450: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_7:
    // 0x80150454: b           L_80150460
    // 0x80150458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80150460;
    // 0x80150458: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8015045C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80150460:
    // 0x80150460: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80150464: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80150468: jr          $ra
    // 0x8015046C: nop

    return;
    // 0x8015046C: nop

;}
RECOMP_FUNC void syMatrixTraRotRpR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CF8C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8001CF90: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001CF94: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001CF98: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x8001CF9C: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8001CFA0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001CFA4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8001CFA8: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001CFAC: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001CFB0: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8001CFB4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001CFB8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x8001CFBC: jal         0x8001CF3C
    // 0x8001CFC0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    syMatrixTraRotRpRF(rdram, ctx);
        goto after_0;
    // 0x8001CFC0: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_0:
    // 0x8001CFC4: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x8001CFC8: jal         0x80019EA0
    // 0x8001CFCC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001CFCC: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_1:
    // 0x8001CFD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8001CFD4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8001CFD8: jr          $ra
    // 0x8001CFDC: nop

    return;
    // 0x8001CFDC: nop

;}
RECOMP_FUNC void itKabigonJumpProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017E384: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8017E388: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x8017E38C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8017E390: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017E394: lh          $t7, 0x74($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X74);
    // 0x8017E398: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8017E39C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017E3A0: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8017E3A4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017E3A8: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017E3AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017E3B0: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8017E3B4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8017E3B8: c.le.s      $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f16.fl <= ctx->f4.fl;
    // 0x8017E3BC: nop

    // 0x8017E3C0: bc1fl       L_8017E3FC
    if (!c1cs) {
        // 0x8017E3C4: lw          $a0, 0x350($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X350);
            goto L_8017E3FC;
    }
    goto skip_0;
    // 0x8017E3C4: lw          $a0, 0x350($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X350);
    skip_0:
    // 0x8017E3C8: lhu         $t8, 0x33E($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017E3CC: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017E3D0: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8017E3D4: andi        $t0, $t9, 0xFFFF
    ctx->r8 = ctx->r25 & 0XFFFF;
    // 0x8017E3D8: sh          $t9, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r25;
    // 0x8017E3DC: bne         $t0, $zero, L_8017E3F8
    if (ctx->r8 != 0) {
        // 0x8017E3E0: swc1        $f18, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->f18.u32l;
            goto L_8017E3F8;
    }
    // 0x8017E3E0: swc1        $f18, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f18.u32l;
    // 0x8017E3E4: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8017E3E8: jal         0x8017E350
    // 0x8017E3EC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    itKabigonFallSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017E3EC: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017E3F0: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x8017E3F4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_8017E3F8:
    // 0x8017E3F8: lw          $a0, 0x350($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X350);
L_8017E3FC:
    // 0x8017E3FC: bnel        $a0, $zero, L_8017E48C
    if (ctx->r4 != 0) {
        // 0x8017E400: addiu       $t5, $a0, -0x1
        ctx->r13 = ADD32(ctx->r4, -0X1);
            goto L_8017E48C;
    }
    goto skip_1;
    // 0x8017E400: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
    skip_1:
    // 0x8017E404: lw          $t3, 0x1C($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X1C);
    // 0x8017E408: addiu       $t1, $sp, 0x24
    ctx->r9 = ADD32(ctx->r29, 0X24);
    // 0x8017E40C: sw          $t3, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r11;
    // 0x8017E410: lw          $t2, 0x20($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X20);
    // 0x8017E414: sw          $t2, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r10;
    // 0x8017E418: lw          $t3, 0x24($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X24);
    // 0x8017E41C: sw          $t3, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r11;
    // 0x8017E420: jal         0x80018948
    // 0x8017E424: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x8017E424: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_1:
    // 0x8017E428: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8017E42C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017E430: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8017E434: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017E438: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8017E43C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8017E440: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8017E444: add.s       $f18, $f16, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x8017E448: jal         0x80018948
    // 0x8017E44C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_2;
    // 0x8017E44C: swc1        $f18, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x8017E450: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8017E454: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017E458: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8017E45C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017E460: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8017E464: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8017E468: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8017E46C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8017E470: add.s       $f18, $f4, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x8017E474: jal         0x800FF590
    // 0x8017E478: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    efManagerDustExpandLargeMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8017E478: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    after_3:
    // 0x8017E47C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8017E480: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x8017E484: sw          $a0, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->r4;
    // 0x8017E488: addiu       $t5, $a0, -0x1
    ctx->r13 = ADD32(ctx->r4, -0X1);
L_8017E48C:
    // 0x8017E48C: sw          $t5, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->r13;
    // 0x8017E490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017E494: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8017E498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017E49C: jr          $ra
    // 0x8017E4A0: nop

    return;
    // 0x8017E4A0: nop

;}
RECOMP_FUNC void func_ovl8_8037486C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037486C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374870: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374874: jal         0x80372C00
    // 0x80374878: nop

    func_ovl8_80372C00(rdram, ctx);
        goto after_0;
    // 0x80374878: nop

    after_0:
    // 0x8037487C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374880: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374884: jr          $ra
    // 0x80374888: nop

    return;
    // 0x80374888: nop

;}
RECOMP_FUNC void ftShadowMakeShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013BB88: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013BB8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013BB90: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8013BB94: addiu       $a0, $zero, 0x3FC
    ctx->r4 = ADD32(0, 0X3FC);
    // 0x8013BB98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013BB9C: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8013BBA0: jal         0x80009968
    // 0x8013BBA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013BBA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013BBA8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8013BBAC: addiu       $a0, $zero, 0x108
    ctx->r4 = ADD32(0, 0X108);
    // 0x8013BBB0: jal         0x80004980
    // 0x8013BBB4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x8013BBB4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_1:
    // 0x8013BBB8: bne         $v0, $zero, L_8013BBC8
    if (ctx->r2 != 0) {
        // 0x8013BBBC: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8013BBC8;
    }
    // 0x8013BBBC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8013BBC0: b           L_8013BC44
    // 0x8013BBC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8013BC44;
    // 0x8013BBC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013BBC8:
    // 0x8013BBC8: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8013BBCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013BBD0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8013BBD4: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x8013BBD8: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x8013BBDC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013BBE0: lbu         $t7, 0xD($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XD);
    // 0x8013BBE4: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x8013BBE8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8013BBEC: sw          $t7, 0x100($v0)
    MEM_W(0X100, ctx->r2) = ctx->r15;
L_8013BBF0:
    // 0x8013BBF0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8013BBF4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x8013BBF8: sh          $zero, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = 0;
    // 0x8013BBFC: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x8013BC00: sb          $zero, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = 0;
    // 0x8013BC04: sb          $zero, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = 0;
    // 0x8013BC08: sb          $a1, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r5;
    // 0x8013BC0C: sh          $zero, 0x76($v1)
    MEM_H(0X76, ctx->r3) = 0;
    // 0x8013BC10: sb          $zero, 0x7C($v1)
    MEM_B(0X7C, ctx->r3) = 0;
    // 0x8013BC14: sb          $zero, 0x7D($v1)
    MEM_B(0X7D, ctx->r3) = 0;
    // 0x8013BC18: sb          $zero, 0x7E($v1)
    MEM_B(0X7E, ctx->r3) = 0;
    // 0x8013BC1C: bne         $a0, $a2, L_8013BBF0
    if (ctx->r4 != ctx->r6) {
        // 0x8013BC20: sb          $a1, 0x7F($v1)
        MEM_B(0X7F, ctx->r3) = ctx->r5;
            goto L_8013BBF0;
    }
    // 0x8013BC20: sb          $a1, 0x7F($v1)
    MEM_B(0X7F, ctx->r3) = ctx->r5;
    // 0x8013BC24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013BC28: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8013BC2C: addiu       $a1, $a1, -0x51A0
    ctx->r5 = ADD32(ctx->r5, -0X51A0);
    // 0x8013BC30: sw          $t0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r8;
    // 0x8013BC34: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8013BC38: jal         0x80009DF4
    // 0x8013BC3C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x8013BC3C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    after_2:
    // 0x8013BC40: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
L_8013BC44:
    // 0x8013BC44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013BC48: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013BC4C: jr          $ra
    // 0x8013BC50: nop

    return;
    // 0x8013BC50: nop

;}
RECOMP_FUNC void ftFoxSpecialHiStartInitGravity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CAA4: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8015CAA8: jr          $ra
    // 0x8015CAAC: sw          $t6, 0xB1C($a0)
    MEM_W(0XB1C, ctx->r4) = ctx->r14;
    return;
    // 0x8015CAAC: sw          $t6, 0xB1C($a0)
    MEM_W(0XB1C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void mvOpeningFoxSetupFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018D0C4: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8018D0C8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8018D0CC: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018D0D0: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D0D8: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x8018D0DC: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x8018D0E0: addiu       $t8, $t8, -0x1DA8
    ctx->r24 = ADD32(ctx->r24, -0X1DA8);
    // 0x8018D0E4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x8018D0E8: addiu       $t0, $t0, -0x1C28
    ctx->r8 = ADD32(ctx->r8, -0X1C28);
    // 0x8018D0EC: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x8018D0F0: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x8018D0F4: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x8018D0F8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x8018D0FC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018D100: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8018D104: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8018D108: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x8018D10C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x8018D110: jal         0x800CDF78
    // 0x8018D114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8018D114: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    after_0:
    // 0x8018D118: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D11C: addiu       $a0, $a0, -0x1F20
    ctx->r4 = ADD32(ctx->r4, -0X1F20);
    // 0x8018D120: jal         0x800CDEEC
    // 0x8018D124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8018D124: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x8018D128: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D12C: jal         0x80004980
    // 0x8018D130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x8018D130: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8018D134: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D138: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018D13C: addiu       $a2, $a2, -0x1BF0
    ctx->r6 = ADD32(ctx->r6, -0X1BF0);
    // 0x8018D140: addiu       $a0, $a0, -0x1F20
    ctx->r4 = ADD32(ctx->r4, -0X1F20);
    // 0x8018D144: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8018D148: jal         0x800CDE04
    // 0x8018D14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x8018D14C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x8018D150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D154: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018D158: jr          $ra
    // 0x8018D15C: nop

    return;
    // 0x8018D15C: nop

;}
RECOMP_FUNC void func_ovl8_80382A20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382A20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80382A24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80382A28: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80382A2C: lh          $t7, 0x1E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1E);
    // 0x80382A30: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80382A34: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x80382A38: bnel        $t7, $zero, L_80382A50
    if (ctx->r15 != 0) {
        // 0x80382A3C: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80382A50;
    }
    goto skip_0;
    // 0x80382A3C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    skip_0:
    // 0x80382A40: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80382A44: nop

    // 0x80382A48: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80382A4C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80382A50:
    // 0x80382A50: jal         0x8037EBC8
    // 0x80382A54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    func_ovl8_8037EBC8(rdram, ctx);
        goto after_0;
    // 0x80382A54: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80382A58: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80382A5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80382A60: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x80382A64: nop

    // 0x80382A68: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80382A6C: swc1        $f16, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f16.u32l;
    // 0x80382A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80382A74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80382A78: jr          $ra
    // 0x80382A7C: nop

    return;
    // 0x80382A7C: nop

;}
RECOMP_FUNC void efManagerGetNextStructAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FD43C: bne         $a0, $zero, L_800FD464
    if (ctx->r4 != 0) {
        // 0x800FD440: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800FD464;
    }
    // 0x800FD440: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FD444: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FD448: addiu       $a0, $a0, 0x13C0
    ctx->r4 = ADD32(ctx->r4, 0X13C0);
    // 0x800FD44C: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800FD450: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x800FD454: beq         $at, $zero, L_800FD464
    if (ctx->r1 == 0) {
        // 0x800FD458: nop
    
            goto L_800FD464;
    }
    // 0x800FD458: nop

    // 0x800FD45C: jr          $ra
    // 0x800FD460: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800FD460: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FD464:
    // 0x800FD464: addiu       $a1, $a1, 0x13BC
    ctx->r5 = ADD32(ctx->r5, 0X13BC);
    // 0x800FD468: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x800FD46C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FD470: addiu       $a0, $a0, 0x13C0
    ctx->r4 = ADD32(ctx->r4, 0X13C0);
    // 0x800FD474: bnel        $v1, $zero, L_800FD488
    if (ctx->r3 != 0) {
        // 0x800FD478: lw          $t7, 0x0($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X0);
            goto L_800FD488;
    }
    goto skip_0;
    // 0x800FD478: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x800FD47C: jr          $ra
    // 0x800FD480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800FD480: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FD484: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
L_800FD488:
    // 0x800FD488: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800FD48C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800FD490: lbu         $t8, 0x10($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X10);
    // 0x800FD494: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800FD498: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x800FD49C: andi        $t9, $t8, 0xFF7F
    ctx->r25 = ctx->r24 & 0XFF7F;
    // 0x800FD4A0: sb          $t9, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r25;
    // 0x800FD4A4: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800FD4A8: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x800FD4AC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x800FD4B0: jr          $ra
    // 0x800FD4B4: nop

    return;
    // 0x800FD4B4: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D91C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D924: jal         0x8018D2F0
    // 0x8018D928: nop

    sc1PTrainingModeUpdateMenuInputs(rdram, ctx);
        goto after_0;
    // 0x8018D928: nop

    after_0:
    // 0x8018D92C: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D930: lw          $t6, 0xB58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XB58);
    // 0x8018D934: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D938: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018D93C: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x8018D940: lw          $t9, 0x7F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7F0);
    // 0x8018D944: jalr        $t9
    // 0x8018D948: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8018D948: nop

    after_1:
    // 0x8018D94C: bnel        $v0, $zero, L_8018D968
    if (ctx->r2 != 0) {
        // 0x8018D950: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D968;
    }
    goto skip_0;
    // 0x8018D950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018D954: jal         0x8018D898
    // 0x8018D958: nop

    sc1PTrainingModeUpdateMainOption(rdram, ctx);
        goto after_2;
    // 0x8018D958: nop

    after_2:
    // 0x8018D95C: jal         0x8018D1F0
    // 0x8018D960: nop

    sc1PTrainingModeCheckLeaveMenu(rdram, ctx);
        goto after_3;
    // 0x8018D960: nop

    after_3:
    // 0x8018D964: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D968:
    // 0x8018D968: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D96C: jr          $ra
    // 0x8018D970: nop

    return;
    // 0x8018D970: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeScene1Cameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801332BC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801332C0: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x801332C4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801332C8: addiu       $v0, $v0, 0x7EC0
    ctx->r2 = ADD32(ctx->r2, 0X7EC0);
    // 0x801332CC: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x801332D0: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801332D4: addiu       $t9, $zero, 0x40
    ctx->r25 = ADD32(0, 0X40);
    // 0x801332D8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x801332DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801332E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801332E4: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x801332E8: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x801332EC: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x801332F0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801332F4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801332F8: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x801332FC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80133300: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x80133304: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133308: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8013330C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133310: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133318: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8013331C: jal         0x8000B93C
    // 0x80133320: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133320: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133324: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133328: sw          $v0, 0x4CE8($at)
    MEM_W(0X4CE8, ctx->r1) = ctx->r2;
    // 0x8013332C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80133330: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x80133334: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80133338: jal         0x80008CF0
    // 0x8013333C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_1;
    // 0x8013333C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80133340: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80133344: addiu       $a1, $zero, 0xE
    ctx->r5 = ADD32(0, 0XE);
    // 0x80133348: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013334C: jal         0x80008CF0
    // 0x80133350: lw          $a0, 0x74($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X74);
    gcAddXObjForCamera(rdram, ctx);
        goto after_2;
    // 0x80133350: lw          $a0, 0x74($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X74);
    after_2:
    // 0x80133354: jal         0x80133210
    // 0x80133358: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    mvOpeningRoomInitScene1Cameras(rdram, ctx);
        goto after_3;
    // 0x80133358: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    after_3:
    // 0x8013335C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80133360: lui         $t7, 0x800
    ctx->r15 = S32(0X800 << 16);
    // 0x80133364: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80133368: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x8013336C: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x80133370: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80133374: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80133378: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013337C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133380: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80133384: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x80133388: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8013338C: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x80133390: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80133394: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80133398: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8013339C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801333A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801333A4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801333A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801333AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801333B0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801333B4: jal         0x8000B93C
    // 0x801333B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    gcMakeCameraGObj(rdram, ctx);
        goto after_4;
    // 0x801333B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_4:
    // 0x801333BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801333C0: sw          $v0, 0x4CEC($at)
    MEM_W(0X4CEC, ctx->r1) = ctx->r2;
    // 0x801333C4: jal         0x80133210
    // 0x801333C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mvOpeningRoomInitScene1Cameras(rdram, ctx);
        goto after_5;
    // 0x801333C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x801333CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801333D0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801333D4: jr          $ra
    // 0x801333D8: nop

    return;
    // 0x801333D8: nop

;}
RECOMP_FUNC void mvOpeningYoshiPosedFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D9C0: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D9C4: lw          $v1, -0x1DD8($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1DD8);
    // 0x8018D9C8: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018D9CC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9D0: beq         $v1, $at, L_8018D9F8
    if (ctx->r3 == ctx->r1) {
        // 0x8018D9D4: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8018D9F8;
    }
    // 0x8018D9D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8018D9D8: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x8018D9DC: beq         $v0, $at, L_8018DA0C
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9E0: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018DA0C;
    }
    // 0x8018D9E0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9E4: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x8018D9E8: beq         $v0, $at, L_8018DA20
    if (ctx->r2 == ctx->r1) {
        // 0x8018D9EC: lui         $a1, 0x8019
        ctx->r5 = S32(0X8019 << 16);
            goto L_8018DA20;
    }
    // 0x8018D9EC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D9F0: b           L_8018DA30
    // 0x8018D9F4: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
        goto L_8018DA30;
    // 0x8018D9F4: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
L_8018D9F8:
    // 0x8018D9F8: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x8018D9FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DA00: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
    // 0x8018DA04: b           L_8018DA30
    // 0x8018DA08: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
        goto L_8018DA30;
    // 0x8018DA08: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
L_8018DA0C:
    // 0x8018DA0C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x8018DA10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA14: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
    // 0x8018DA18: b           L_8018DA30
    // 0x8018DA1C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
        goto L_8018DA30;
    // 0x8018DA1C: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
L_8018DA20:
    // 0x8018DA20: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8018DA24: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DA28: addiu       $a1, $a1, -0x1DC0
    ctx->r5 = ADD32(ctx->r5, -0X1DC0);
    // 0x8018DA2C: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA30:
    // 0x8018DA30: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x8018DA34: bne         $at, $zero, L_8018DA54
    if (ctx->r1 != 0) {
        // 0x8018DA38: slti        $at, $v1, 0x2D
        ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
            goto L_8018DA54;
    }
    // 0x8018DA38: slti        $at, $v1, 0x2D
    ctx->r1 = SIGNED(ctx->r3) < 0X2D ? 1 : 0;
    // 0x8018DA3C: beq         $at, $zero, L_8018DA54
    if (ctx->r1 == 0) {
        // 0x8018DA40: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8018DA54;
    }
    // 0x8018DA40: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DA44: lwc1        $f16, -0x1DF0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X1DF0);
    // 0x8018DA48: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA4C: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA50: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_8018DA54:
    // 0x8018DA54: slti        $at, $v1, 0x2E
    ctx->r1 = SIGNED(ctx->r3) < 0X2E ? 1 : 0;
    // 0x8018DA58: bne         $at, $zero, L_8018DA78
    if (ctx->r1 != 0) {
        // 0x8018DA5C: slti        $at, $v1, 0x3C
        ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
            goto L_8018DA78;
    }
    // 0x8018DA5C: slti        $at, $v1, 0x3C
    ctx->r1 = SIGNED(ctx->r3) < 0X3C ? 1 : 0;
    // 0x8018DA60: beq         $at, $zero, L_8018DA78
    if (ctx->r1 == 0) {
        // 0x8018DA64: lui         $at, 0xBF80
        ctx->r1 = S32(0XBF80 << 16);
            goto L_8018DA78;
    }
    // 0x8018DA64: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x8018DA68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DA6C: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA70: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018DA74: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
L_8018DA78:
    // 0x8018DA78: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018DA7C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x8018DA80: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8018DA84: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8018DA88: jr          $ra
    // 0x8018DA8C: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
    return;
    // 0x8018DA8C: swc1        $f18, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f18.u32l;
;}
RECOMP_FUNC void gmCollisionGetDamageSlashRotation(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0FC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F0FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0FC8: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800F0FCC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F0FD0: bnel        $t6, $at, L_800F0FE8
    if (ctx->r14 != ctx->r1) {
        // 0x800F0FD4: lwc1        $f4, 0x44($a1)
        ctx->f4.u32l = MEM_W(ctx->r5, 0X44);
            goto L_800F0FE8;
    }
    goto skip_0;
    // 0x800F0FD4: lwc1        $f4, 0x44($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X44);
    skip_0:
    // 0x800F0FD8: lwc1        $f14, 0x48($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X48);
    // 0x800F0FDC: b           L_800F0FFC
    // 0x800F0FE0: lwc1        $f12, 0x4C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4C);
        goto L_800F0FFC;
    // 0x800F0FE0: lwc1        $f12, 0x4C($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800F0FE4: lwc1        $f4, 0x44($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X44);
L_800F0FE8:
    // 0x800F0FE8: lwc1        $f6, 0x50($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X50);
    // 0x800F0FEC: lwc1        $f8, 0x48($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X48);
    // 0x800F0FF0: lwc1        $f10, 0x54($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X54);
    // 0x800F0FF4: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F0FF8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
L_800F0FFC:
    // 0x800F0FFC: jal         0x8001863C
    // 0x800F1000: nop

    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x800F1000: nop

    after_0:
    // 0x800F1004: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F1008: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F100C: jr          $ra
    // 0x800F1010: nop

    return;
    // 0x800F1010: nop

;}
RECOMP_FUNC void _Ldtob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038360: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x80038364: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80038368: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8003836C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80038370: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80038374: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x80038378: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8003837C: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80038380: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80038384: sw          $a0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r4;
    // 0x80038388: sw          $a1, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r5;
    // 0x8003838C: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x80038390: addiu       $s5, $sp, 0xB0
    ctx->r21 = ADD32(ctx->r29, 0XB0);
    // 0x80038394: ldc1        $f20, 0x0($a0)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r4, 0X0);
    // 0x80038398: bgez        $v0, L_800383A8
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003839C: addiu       $t7, $zero, 0x6
        ctx->r15 = ADD32(0, 0X6);
            goto L_800383A8;
    }
    // 0x8003839C: addiu       $t7, $zero, 0x6
    ctx->r15 = ADD32(0, 0X6);
    // 0x800383A0: b           L_800383D4
    // 0x800383A4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
        goto L_800383D4;
    // 0x800383A4: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
L_800383A8:
    // 0x800383A8: bne         $v0, $zero, L_800383D4
    if (ctx->r2 != 0) {
        // 0x800383AC: lbu         $t8, 0xD7($sp)
        ctx->r24 = MEM_BU(ctx->r29, 0XD7);
            goto L_800383D4;
    }
    // 0x800383AC: lbu         $t8, 0xD7($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0XD7);
    // 0x800383B0: addiu       $at, $zero, 0x67
    ctx->r1 = ADD32(0, 0X67);
    // 0x800383B4: beq         $t8, $at, L_800383C8
    if (ctx->r24 == ctx->r1) {
        // 0x800383B8: sw          $t8, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r24;
            goto L_800383C8;
    }
    // 0x800383B8: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x800383BC: addiu       $at, $zero, 0x47
    ctx->r1 = ADD32(0, 0X47);
    // 0x800383C0: bnel        $t8, $at, L_800383D8
    if (ctx->r24 != ctx->r1) {
        // 0x800383C4: lw          $t6, 0xD0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XD0);
            goto L_800383D8;
    }
    goto skip_0;
    // 0x800383C4: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    skip_0:
L_800383C8:
    // 0x800383C8: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x800383CC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800383D0: sw          $t9, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->r25;
L_800383D4:
    // 0x800383D4: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
L_800383D8:
    // 0x800383D8: addiu       $at, $zero, 0x7FF
    ctx->r1 = ADD32(0, 0X7FF);
    // 0x800383DC: lhu         $a0, 0x0($t6)
    ctx->r4 = MEM_HU(ctx->r14, 0X0);
    // 0x800383E0: andi        $v1, $a0, 0x7FF0
    ctx->r3 = ctx->r4 & 0X7FF0;
    // 0x800383E4: sra         $t8, $v1, 4
    ctx->r24 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800383E8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800383EC: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800383F0: bne         $v1, $at, L_80038454
    if (ctx->r3 != ctx->r1) {
        // 0x800383F4: nop
    
            goto L_80038454;
    }
    // 0x800383F4: nop

    // 0x800383F8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x800383FC: lhu         $t8, 0x0($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X0);
    // 0x80038400: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80038404: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80038408: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8003840C: bnel        $t9, $zero, L_80038438
    if (ctx->r25 != 0) {
        // 0x80038410: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80038438;
    }
    goto skip_1;
    // 0x80038410: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_1:
    // 0x80038414: lhu         $t7, 0x2($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2);
    // 0x80038418: bnel        $t7, $zero, L_80038438
    if (ctx->r15 != 0) {
        // 0x8003841C: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80038438;
    }
    goto skip_2;
    // 0x8003841C: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_2:
    // 0x80038420: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x80038424: bnel        $t8, $zero, L_80038438
    if (ctx->r24 != 0) {
        // 0x80038428: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80038438;
    }
    goto skip_3;
    // 0x80038428: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    skip_3:
    // 0x8003842C: lhu         $t9, 0x6($t6)
    ctx->r25 = MEM_HU(ctx->r14, 0X6);
    // 0x80038430: beq         $t9, $zero, L_80038440
    if (ctx->r25 == 0) {
        // 0x80038434: sra         $t7, $v0, 16
        ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
            goto L_80038440;
    }
    // 0x80038434: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
L_80038438:
    // 0x80038438: b           L_8003848C
    // 0x8003843C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8003848C;
    // 0x8003843C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80038440:
    // 0x80038440: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80038444: sll         $v0, $v1, 16
    ctx->r2 = S32(ctx->r3 << 16);
    // 0x80038448: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x8003844C: b           L_8003848C
    // 0x80038450: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
        goto L_8003848C;
    // 0x80038450: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80038454:
    // 0x80038454: blez        $v1, L_80038478
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80038458: andi        $t8, $a0, 0x800F
        ctx->r24 = ctx->r4 & 0X800F;
            goto L_80038478;
    }
    // 0x80038458: andi        $t8, $a0, 0x800F
    ctx->r24 = ctx->r4 & 0X800F;
    // 0x8003845C: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x80038460: ori         $t6, $t8, 0x3FF0
    ctx->r14 = ctx->r24 | 0X3FF0;
    // 0x80038464: addiu       $t7, $v1, -0x3FE
    ctx->r15 = ADD32(ctx->r3, -0X3FE);
    // 0x80038468: sh          $t6, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r14;
    // 0x8003846C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80038470: b           L_8003848C
    // 0x80038474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8003848C;
    // 0x80038474: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80038478:
    // 0x80038478: bgez        $v1, L_80038488
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8003847C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80038488;
    }
    // 0x8003847C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80038480: b           L_8003848C
    // 0x80038484: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8003848C;
    // 0x80038484: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80038488:
    // 0x80038488: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_8003848C:
    // 0x8003848C: blez        $v0, L_800384D8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80038490: sll         $t8, $v0, 16
        ctx->r24 = S32(ctx->r2 << 16);
            goto L_800384D8;
    }
    // 0x80038490: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80038494: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80038498: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003849C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800384A0: bne         $t6, $at, L_800384B4
    if (ctx->r14 != ctx->r1) {
        // 0x800384A4: lw          $t9, 0xD0($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XD0);
            goto L_800384B4;
    }
    // 0x800384A4: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x800384A8: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800384AC: b           L_800384BC
    // 0x800384B0: addiu       $a1, $a1, -0xC28
    ctx->r5 = ADD32(ctx->r5, -0XC28);
        goto L_800384BC;
    // 0x800384B0: addiu       $a1, $a1, -0xC28
    ctx->r5 = ADD32(ctx->r5, -0XC28);
L_800384B4:
    // 0x800384B4: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800384B8: addiu       $a1, $a1, -0xC24
    ctx->r5 = ADD32(ctx->r5, -0XC24);
L_800384BC:
    // 0x800384BC: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800384C0: sw          $t7, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->r15;
    // 0x800384C4: lw          $a0, 0x8($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X8);
    // 0x800384C8: jal         0x800343E0
    // 0x800384CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    memcpy_recomp(rdram, ctx);
        goto after_0;
    // 0x800384CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x800384D0: b           L_80038888
    // 0x800384D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80038888;
    // 0x800384D4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800384D8:
    // 0x800384D8: sra         $t6, $t8, 16
    ctx->r14 = S32(SIGNED(ctx->r24) >> 16);
    // 0x800384DC: bne         $t6, $zero, L_800384EC
    if (ctx->r14 != 0) {
        // 0x800384E0: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800384EC;
    }
    // 0x800384E0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800384E4: b           L_80038870
    // 0x800384E8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
        goto L_80038870;
    // 0x800384E8: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
L_800384EC:
    // 0x800384EC: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    // 0x800384F0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800384F4: lbu         $t7, 0xD7($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0XD7);
    // 0x800384F8: lh          $t9, 0x9A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9A);
    // 0x800384FC: c.lt.d      $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f20.d < ctx->f2.d;
    // 0x80038500: addiu       $at, $zero, 0x7597
    ctx->r1 = ADD32(0, 0X7597);
    // 0x80038504: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80038508: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x8003850C: bc1f        L_80038518
    if (!c1cs) {
        // 0x80038510: sw          $t7, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r15;
            goto L_80038518;
    }
    // 0x80038510: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x80038514: neg.d       $f20, $f20
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.d); 
    ctx->f20.d = -ctx->f20.d;
L_80038518:
    // 0x80038518: multu       $t9, $at
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r1)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8003851C: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x80038520: ori         $at, $at, 0x86A0
    ctx->r1 = ctx->r1 | 0X86A0;
    // 0x80038524: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80038528: mflo        $t8
    ctx->r24 = lo;
    // 0x8003852C: nop

    // 0x80038530: nop

    // 0x80038534: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80038538: mflo        $t6
    ctx->r14 = lo;
    // 0x8003853C: addiu       $t7, $t6, -0x4
    ctx->r15 = ADD32(ctx->r14, -0X4);
    // 0x80038540: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80038544: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80038548: bgez        $t8, L_800385B0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8003854C: sh          $t7, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r15;
            goto L_800385B0;
    }
    // 0x8003854C: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80038550: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80038554: sra         $t8, $t9, 16
    ctx->r24 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80038558: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8003855C: subu        $a0, $t6, $t8
    ctx->r4 = SUB32(ctx->r14, ctx->r24);
    // 0x80038560: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80038564: and         $v0, $a0, $at
    ctx->r2 = ctx->r4 & ctx->r1;
    // 0x80038568: negu        $t9, $v0
    ctx->r25 = SUB32(0, ctx->r2);
    // 0x8003856C: blez        $v0, L_80038620
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80038570: sh          $t9, 0x9A($sp)
        MEM_H(0X9A, ctx->r29) = ctx->r25;
            goto L_80038620;
    }
    // 0x80038570: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x80038574: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80038578: addiu       $a0, $a0, -0xC70
    ctx->r4 = ADD32(ctx->r4, -0XC70);
L_8003857C:
    // 0x8003857C: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80038580: beq         $t6, $zero, L_8003859C
    if (ctx->r14 == 0) {
        // 0x80038584: sra         $t9, $v0, 1
        ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
            goto L_8003859C;
    }
    // 0x80038584: sra         $t9, $v0, 1
    ctx->r25 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80038588: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8003858C: addu        $t7, $a0, $t8
    ctx->r15 = ADD32(ctx->r4, ctx->r24);
    // 0x80038590: ldc1        $f4, 0x0($t7)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r15, 0X0);
    // 0x80038594: mul.d       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f20.d = MUL_D(ctx->f20.d, ctx->f4.d);
    // 0x80038598: nop

L_8003859C:
    // 0x8003859C: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800385A0: bgtz        $t9, L_8003857C
    if (SIGNED(ctx->r25) > 0) {
        // 0x800385A4: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8003857C;
    }
    // 0x800385A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800385A8: b           L_80038624
    // 0x800385AC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
        goto L_80038624;
    // 0x800385AC: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_800385B0:
    // 0x800385B0: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x800385B4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800385B8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800385BC: blez        $t6, L_80038620
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800385C0: andi        $t8, $t6, 0xFFFC
        ctx->r24 = ctx->r14 & 0XFFFC;
            goto L_80038620;
    }
    // 0x800385C0: andi        $t8, $t6, 0xFFFC
    ctx->r24 = ctx->r14 & 0XFFFC;
    // 0x800385C4: sll         $v0, $t8, 16
    ctx->r2 = S32(ctx->r24 << 16);
    // 0x800385C8: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800385CC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800385D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800385D4: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800385D8: sra         $t7, $v0, 16
    ctx->r15 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800385DC: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x800385E0: blez        $t6, L_8003861C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800385E4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8003861C;
    }
    // 0x800385E4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800385E8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800385EC: addiu       $a0, $a0, -0xC70
    ctx->r4 = ADD32(ctx->r4, -0XC70);
L_800385F0:
    // 0x800385F0: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x800385F4: beq         $t7, $zero, L_80038610
    if (ctx->r15 == 0) {
        // 0x800385F8: sra         $t6, $v0, 1
        ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80038610;
    }
    // 0x800385F8: sra         $t6, $v0, 1
    ctx->r14 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800385FC: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x80038600: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80038604: ldc1        $f6, 0x0($t9)
    CHECK_FR(ctx, 6);
    ctx->f6.u64 = LD(ctx->r25, 0X0);
    // 0x80038608: mul.d       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f0.d = MUL_D(ctx->f0.d, ctx->f6.d);
    // 0x8003860C: nop

L_80038610:
    // 0x80038610: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x80038614: bgtz        $t6, L_800385F0
    if (SIGNED(ctx->r14) > 0) {
        // 0x80038618: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800385F0;
    }
    // 0x80038618: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8003861C:
    // 0x8003861C: div.d       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f0.d); 
    ctx->f20.d = DIV_D(ctx->f20.d, ctx->f0.d);
L_80038620:
    // 0x80038620: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_80038624:
    // 0x80038624: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80038628: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x8003862C: bne         $t7, $at, L_80038640
    if (ctx->r15 != ctx->r1) {
        // 0x80038630: addiu       $t6, $zero, 0x30
        ctx->r14 = ADD32(0, 0X30);
            goto L_80038640;
    }
    // 0x80038630: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x80038634: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x80038638: b           L_80038640
    // 0x8003863C: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
        goto L_80038640;
    // 0x8003863C: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_80038640:
    // 0x80038640: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x80038644: addu        $s4, $a1, $t9
    ctx->r20 = ADD32(ctx->r5, ctx->r25);
    // 0x80038648: slti        $at, $s4, 0x14
    ctx->r1 = SIGNED(ctx->r20) < 0X14 ? 1 : 0;
    // 0x8003864C: bne         $at, $zero, L_80038658
    if (ctx->r1 != 0) {
        // 0x80038650: nop
    
            goto L_80038658;
    }
    // 0x80038650: nop

    // 0x80038654: addiu       $s4, $zero, 0x13
    ctx->r20 = ADD32(0, 0X13);
L_80038658:
    // 0x80038658: blez        $s4, L_80038728
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8003865C: sb          $t6, 0xB0($sp)
        MEM_B(0XB0, ctx->r29) = ctx->r14;
            goto L_80038728;
    }
    // 0x8003865C: sb          $t6, 0xB0($sp)
    MEM_B(0XB0, ctx->r29) = ctx->r14;
    // 0x80038660: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x80038664: addiu       $s3, $zero, 0x30
    ctx->r19 = ADD32(0, 0X30);
    // 0x80038668: addiu       $s2, $sp, 0x74
    ctx->r18 = ADD32(ctx->r29, 0X74);
    // 0x8003866C: bc1fl       L_8003872C
    if (!c1cs) {
        // 0x80038670: lh          $t8, 0x9A($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X9A);
            goto L_8003872C;
    }
    goto skip_4;
    // 0x80038670: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
    skip_4:
    // 0x80038674: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
L_80038678:
    // 0x80038678: addiu       $s4, $s4, -0x8
    ctx->r20 = ADD32(ctx->r20, -0X8);
    // 0x8003867C: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80038680: mfc1        $s1, $f8
    ctx->r17 = (int32_t)ctx->f8.u32l;
    // 0x80038684: blez        $s4, L_800386A8
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80038688: nop
    
            goto L_800386A8;
    }
    // 0x80038688: nop

    // 0x8003868C: mtc1        $s1, $f10
    ctx->f10.u32l = ctx->r17;
    // 0x80038690: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80038694: ldc1        $f8, -0xC18($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0XC18);
    // 0x80038698: cvt.d.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.d = CVT_D_W(ctx->f10.u32l);
    // 0x8003869C: sub.d       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f20.d - ctx->f4.d;
    // 0x800386A0: mul.d       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f20.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800386A4: nop

L_800386A8:
    // 0x800386A8: blez        $s1, L_800386F0
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800386AC: addiu       $s0, $zero, 0x8
        ctx->r16 = ADD32(0, 0X8);
            goto L_800386F0;
    }
    // 0x800386AC: addiu       $s0, $zero, 0x8
    ctx->r16 = ADD32(0, 0X8);
    // 0x800386B0: addiu       $s0, $zero, 0x7
    ctx->r16 = ADD32(0, 0X7);
    // 0x800386B4: bltz        $s0, L_800386F0
    if (SIGNED(ctx->r16) < 0) {
        // 0x800386B8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800386F0;
    }
    // 0x800386B8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800386BC:
    // 0x800386BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800386C0: jal         0x800389B0
    // 0x800386C4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    ldiv_recomp(rdram, ctx);
        goto after_1;
    // 0x800386C4: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_1:
    // 0x800386C8: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x800386CC: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x800386D0: addiu       $t9, $t8, 0x30
    ctx->r25 = ADD32(ctx->r24, 0X30);
    // 0x800386D4: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x800386D8: lw          $s1, 0x74($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X74);
    // 0x800386DC: blezl       $s1, L_800386F4
    if (SIGNED(ctx->r17) <= 0) {
        // 0x800386E0: mtc1        $zero, $f3
        ctx->f_odd[(3 - 1) * 2] = 0;
            goto L_800386F4;
    }
    goto skip_5;
    // 0x800386E0: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
    skip_5:
    // 0x800386E4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800386E8: bgezl       $s0, L_800386BC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800386EC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800386BC;
    }
    goto skip_6;
    // 0x800386EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_6:
L_800386F0:
    // 0x800386F0: mtc1        $zero, $f3
    ctx->f_odd[(3 - 1) * 2] = 0;
L_800386F4:
    // 0x800386F4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800386F8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800386FC: bltz        $s0, L_80038710
    if (SIGNED(ctx->r16) < 0) {
        // 0x80038700: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_80038710;
    }
L_80038700:
    // 0x80038700: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80038704: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
    // 0x80038708: bgez        $s0, L_80038700
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8003870C: sb          $s3, 0x0($s5)
        MEM_B(0X0, ctx->r21) = ctx->r19;
            goto L_80038700;
    }
    // 0x8003870C: sb          $s3, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r19;
L_80038710:
    // 0x80038710: blez        $s4, L_80038728
    if (SIGNED(ctx->r20) <= 0) {
        // 0x80038714: addiu       $s5, $s5, 0x8
        ctx->r21 = ADD32(ctx->r21, 0X8);
            goto L_80038728;
    }
    // 0x80038714: addiu       $s5, $s5, 0x8
    ctx->r21 = ADD32(ctx->r21, 0X8);
    // 0x80038718: c.lt.d      $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f2.d < ctx->f20.d;
    // 0x8003871C: nop

    // 0x80038720: bc1tl       L_80038678
    if (c1cs) {
        // 0x80038724: trunc.w.d   $f8, $f20
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
            goto L_80038678;
    }
    goto skip_7;
    // 0x80038724: trunc.w.d   $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    ctx->f8.u32l = TRUNC_W_D(ctx->f20.d);
    skip_7:
L_80038728:
    // 0x80038728: lh          $t8, 0x9A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X9A);
L_8003872C:
    // 0x8003872C: lbu         $t6, 0xB1($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0XB1);
    // 0x80038730: addiu       $t7, $sp, 0xB0
    ctx->r15 = ADD32(ctx->r29, 0XB0);
    // 0x80038734: addiu       $v0, $zero, 0x30
    ctx->r2 = ADD32(0, 0X30);
    // 0x80038738: subu        $s4, $s5, $t7
    ctx->r20 = SUB32(ctx->r21, ctx->r15);
    // 0x8003873C: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x80038740: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x80038744: sh          $t9, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r25;
    // 0x80038748: bne         $v0, $t6, L_80038770
    if (ctx->r2 != ctx->r14) {
        // 0x8003874C: addiu       $s5, $sp, 0xB1
        ctx->r21 = ADD32(ctx->r29, 0XB1);
            goto L_80038770;
    }
    // 0x8003874C: addiu       $s5, $sp, 0xB1
    ctx->r21 = ADD32(ctx->r29, 0XB1);
    // 0x80038750: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
L_80038754:
    // 0x80038754: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80038758: addiu       $s4, $s4, -0x1
    ctx->r20 = ADD32(ctx->r20, -0X1);
    // 0x8003875C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80038760: sh          $t8, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r24;
    // 0x80038764: lbu         $t9, 0x0($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X0);
    // 0x80038768: beql        $v0, $t9, L_80038754
    if (ctx->r2 == ctx->r25) {
        // 0x8003876C: lh          $t7, 0x9A($sp)
        ctx->r15 = MEM_H(ctx->r29, 0X9A);
            goto L_80038754;
    }
    goto skip_8;
    // 0x8003876C: lh          $t7, 0x9A($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X9A);
    skip_8:
L_80038770:
    // 0x80038770: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80038774: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80038778: lw          $t8, 0xD0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD0);
    // 0x8003877C: bne         $t6, $at, L_80038790
    if (ctx->r14 != ctx->r1) {
        // 0x80038780: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80038790;
    }
    // 0x80038780: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80038784: lh          $a1, 0x9A($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X9A);
    // 0x80038788: b           L_800387B0
    // 0x8003878C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
        goto L_800387B0;
    // 0x8003878C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_80038790:
    // 0x80038790: addiu       $at, $zero, 0x65
    ctx->r1 = ADD32(0, 0X65);
    // 0x80038794: beq         $t7, $at, L_800387A4
    if (ctx->r15 == ctx->r1) {
        // 0x80038798: addiu       $at, $zero, 0x45
        ctx->r1 = ADD32(0, 0X45);
            goto L_800387A4;
    }
    // 0x80038798: addiu       $at, $zero, 0x45
    ctx->r1 = ADD32(0, 0X45);
    // 0x8003879C: bne         $t7, $at, L_800387AC
    if (ctx->r15 != ctx->r1) {
        // 0x800387A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800387AC;
    }
    // 0x800387A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800387A4:
    // 0x800387A4: b           L_800387AC
    // 0x800387A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800387AC;
    // 0x800387A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800387AC:
    // 0x800387AC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_800387B0:
    // 0x800387B0: lw          $t9, 0x24($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X24);
    // 0x800387B4: addu        $s3, $a1, $t9
    ctx->r19 = ADD32(ctx->r5, ctx->r25);
    // 0x800387B8: sll         $t6, $s3, 16
    ctx->r14 = S32(ctx->r19 << 16);
    // 0x800387BC: sra         $s3, $t6, 16
    ctx->r19 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800387C0: slt         $at, $s4, $s3
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800387C4: beq         $at, $zero, L_800387D8
    if (ctx->r1 == 0) {
        // 0x800387C8: nop
    
            goto L_800387D8;
    }
    // 0x800387C8: nop

    // 0x800387CC: sll         $s3, $s4, 16
    ctx->r19 = S32(ctx->r20 << 16);
    // 0x800387D0: sra         $t8, $s3, 16
    ctx->r24 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800387D4: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_800387D8:
    // 0x800387D8: blez        $s3, L_80038870
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800387DC: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_80038870;
    }
    // 0x800387DC: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800387E0: beq         $at, $zero, L_80038800
    if (ctx->r1 == 0) {
        // 0x800387E4: addu        $v0, $s3, $s5
        ctx->r2 = ADD32(ctx->r19, ctx->r21);
            goto L_80038800;
    }
    // 0x800387E4: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
    // 0x800387E8: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800387EC: slti        $at, $t9, 0x35
    ctx->r1 = SIGNED(ctx->r25) < 0X35 ? 1 : 0;
    // 0x800387F0: bnel        $at, $zero, L_80038804
    if (ctx->r1 != 0) {
        // 0x800387F4: addiu       $a1, $zero, 0x30
        ctx->r5 = ADD32(0, 0X30);
            goto L_80038804;
    }
    goto skip_9;
    // 0x800387F4: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    skip_9:
    // 0x800387F8: b           L_80038808
    // 0x800387FC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
        goto L_80038808;
    // 0x800387FC: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
L_80038800:
    // 0x80038800: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
L_80038804:
    // 0x80038804: addu        $v0, $s3, $s5
    ctx->r2 = ADD32(ctx->r19, ctx->r21);
L_80038808:
    // 0x80038808: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x8003880C: addiu       $v1, $s3, -0x1
    ctx->r3 = ADD32(ctx->r19, -0X1);
    // 0x80038810: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80038814: bne         $a1, $t6, L_8003883C
    if (ctx->r5 != ctx->r14) {
        // 0x80038818: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_8003883C;
    }
    // 0x80038818: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x8003881C: addu        $v0, $v1, $s5
    ctx->r2 = ADD32(ctx->r3, ctx->r21);
L_80038820:
    // 0x80038820: lbu         $t9, -0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X1);
    // 0x80038824: addiu       $s3, $s3, -0x1
    ctx->r19 = ADD32(ctx->r19, -0X1);
    // 0x80038828: sll         $t7, $s3, 16
    ctx->r15 = S32(ctx->r19 << 16);
    // 0x8003882C: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80038830: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80038834: beq         $a0, $t9, L_80038820
    if (ctx->r4 == ctx->r25) {
        // 0x80038838: sra         $s3, $t7, 16
        ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
            goto L_80038820;
    }
    // 0x80038838: sra         $s3, $t7, 16
    ctx->r19 = S32(SIGNED(ctx->r15) >> 16);
L_8003883C:
    // 0x8003883C: bne         $a0, $at, L_80038850
    if (ctx->r4 != ctx->r1) {
        // 0x80038840: addu        $v0, $s5, $v1
        ctx->r2 = ADD32(ctx->r21, ctx->r3);
            goto L_80038850;
    }
    // 0x80038840: addu        $v0, $s5, $v1
    ctx->r2 = ADD32(ctx->r21, ctx->r3);
    // 0x80038844: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80038848: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8003884C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_80038850:
    // 0x80038850: bgez        $v1, L_80038870
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80038854: lh          $t6, 0x9A($sp)
        ctx->r14 = MEM_H(ctx->r29, 0X9A);
            goto L_80038870;
    }
    // 0x80038854: lh          $t6, 0x9A($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9A);
    // 0x80038858: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003885C: sll         $t8, $s3, 16
    ctx->r24 = S32(ctx->r19 << 16);
    // 0x80038860: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80038864: sh          $t7, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r15;
    // 0x80038868: sra         $s3, $t8, 16
    ctx->r19 = S32(SIGNED(ctx->r24) >> 16);
    // 0x8003886C: addiu       $s5, $s5, -0x1
    ctx->r21 = ADD32(ctx->r21, -0X1);
L_80038870:
    // 0x80038870: lw          $s0, 0xD0($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XD0);
    // 0x80038874: lbu         $s4, 0xD7($sp)
    ctx->r20 = MEM_BU(ctx->r29, 0XD7);
    // 0x80038878: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x8003887C: jal         0x80037DF0
    // 0x80038880: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    static_5_80037DF0(rdram, ctx);
        goto after_2;
    // 0x80038880: lh          $s2, 0x9A($sp)
    ctx->r18 = MEM_H(ctx->r29, 0X9A);
    after_2:
    // 0x80038884: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80038888:
    // 0x80038888: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8003888C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80038890: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80038894: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x80038898: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8003889C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800388A0: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800388A4: jr          $ra
    // 0x800388A8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    return;
    // 0x800388A8: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
;}
RECOMP_FUNC void grInishiePowerBlockProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109968: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010996C: lbu         $v0, 0x143C($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X143C);
    // 0x80109970: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109978: beq         $v0, $zero, L_8010999C
    if (ctx->r2 == 0) {
        // 0x8010997C: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8010999C;
    }
    // 0x8010997C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80109980: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80109984: beq         $v0, $at, L_801099AC
    if (ctx->r2 == ctx->r1) {
        // 0x80109988: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801099AC;
    }
    // 0x80109988: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010998C: beq         $v0, $at, L_801099BC
    if (ctx->r2 == ctx->r1) {
        // 0x80109990: nop
    
            goto L_801099BC;
    }
    // 0x80109990: nop

    // 0x80109994: b           L_801099C8
    // 0x80109998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801099C8;
    // 0x80109998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010999C:
    // 0x8010999C: jal         0x80109838
    // 0x801099A0: nop

    grInishiePowerBlockUpdateWait(rdram, ctx);
        goto after_0;
    // 0x801099A0: nop

    after_0:
    // 0x801099A4: b           L_801099C8
    // 0x801099A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801099C8;
    // 0x801099A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801099AC:
    // 0x801099AC: jal         0x80109888
    // 0x801099B0: nop

    grInishiePowerBlockUpdateMake(rdram, ctx);
        goto after_1;
    // 0x801099B0: nop

    after_1:
    // 0x801099B4: b           L_801099C8
    // 0x801099B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801099C8;
    // 0x801099B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801099BC:
    // 0x801099BC: jal         0x8010992C
    // 0x801099C0: nop

    grInishiePowerBlockUpdateDamage(rdram, ctx);
        goto after_2;
    // 0x801099C0: nop

    after_2:
    // 0x801099C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801099C8:
    // 0x801099C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801099CC: jr          $ra
    // 0x801099D0: nop

    return;
    // 0x801099D0: nop

;}
RECOMP_FUNC void mpProcessUpdateMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA034: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800DA038: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x800DA03C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x800DA040: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x800DA044: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x800DA048: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x800DA04C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x800DA050: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x800DA054: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800DA058: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800DA05C: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x800DA060: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x800DA064: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x800DA068: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800DA06C: lwc1        $f4, 0x8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800DA070: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800DA074: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA078: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800DA07C: or          $s6, $a3, $zero
    ctx->r22 = ctx->r7 | 0;
    // 0x800DA080: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800DA084: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800DA088: addiu       $s4, $s2, 0x8
    ctx->r20 = ADD32(ctx->r18, 0X8);
    // 0x800DA08C: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x800DA090: bc1fl       L_800DA0B0
    if (!c1cs) {
        // 0x800DA094: lwc1        $f8, 0x0($s4)
        ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
            goto L_800DA0B0;
    }
    goto skip_0;
    // 0x800DA094: lwc1        $f8, 0x0($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
    skip_0:
    // 0x800DA098: addiu       $s4, $a0, 0x8
    ctx->r20 = ADD32(ctx->r4, 0X8);
    // 0x800DA09C: lwc1        $f6, 0x0($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X0);
    // 0x800DA0A0: sub.s       $f14, $f0, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800DA0A4: b           L_800DA0B4
    // 0x800DA0A8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
        goto L_800DA0B4;
    // 0x800DA0A8: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
    // 0x800DA0AC: lwc1        $f8, 0x0($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X0);
L_800DA0B0:
    // 0x800DA0B0: sub.s       $f14, $f0, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f0.fl - ctx->f8.fl;
L_800DA0B4:
    // 0x800DA0B4: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA0B8: lwc1        $f2, 0x4($s4)
    ctx->f2.u32l = MEM_W(ctx->r20, 0X4);
    // 0x800DA0BC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800DA0C0: nop

    // 0x800DA0C4: bc1fl       L_800DA0DC
    if (!c1cs) {
        // 0x800DA0C8: sub.s       $f12, $f0, $f2
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
            goto L_800DA0DC;
    }
    goto skip_1;
    // 0x800DA0C8: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    skip_1:
    // 0x800DA0CC: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x800DA0D0: b           L_800DA0DC
    // 0x800DA0D4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
        goto L_800DA0DC;
    // 0x800DA0D4: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
    // 0x800DA0D8: sub.s       $f12, $f0, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f0.fl - ctx->f2.fl;
L_800DA0DC:
    // 0x800DA0DC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800DA0E0: nop

    // 0x800DA0E4: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800DA0E8: nop

    // 0x800DA0EC: bc1tl       L_800DA108
    if (c1cs) {
        // 0x800DA0F0: c.lt.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
            goto L_800DA108;
    }
    goto skip_2;
    // 0x800DA0F0: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    skip_2:
    // 0x800DA0F4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800DA0F8: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800DA0FC: bc1fl       L_800DA164
    if (!c1cs) {
        // 0x800DA100: lwc1        $f20, 0x14($s2)
        ctx->f20.u32l = MEM_W(ctx->r18, 0X14);
            goto L_800DA164;
    }
    goto skip_3;
    // 0x800DA100: lwc1        $f20, 0x14($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X14);
    skip_3:
    // 0x800DA104: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
L_800DA108:
    // 0x800DA108: nop

    // 0x800DA10C: bc1fl       L_800DA12C
    if (!c1cs) {
        // 0x800DA110: div.s       $f18, $f12, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
            goto L_800DA12C;
    }
    goto skip_4;
    // 0x800DA110: div.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
    skip_4:
    // 0x800DA114: div.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800DA118: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800DA11C: mfc1        $s3, $f16
    ctx->r19 = (int32_t)ctx->f16.u32l;
    // 0x800DA120: b           L_800DA13C
    // 0x800DA124: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_800DA13C;
    // 0x800DA124: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800DA128: div.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f12.fl, ctx->f0.fl);
L_800DA12C:
    // 0x800DA12C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800DA130: mfc1        $s3, $f4
    ctx->r19 = (int32_t)ctx->f4.u32l;
    // 0x800DA134: nop

    // 0x800DA138: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800DA13C:
    // 0x800DA13C: mtc1        $s3, $f6
    ctx->f6.u32l = ctx->r19;
    // 0x800DA140: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x800DA144: lwc1        $f10, 0x18($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X18);
    // 0x800DA148: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800DA14C: lwc1        $f16, 0x1C($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X1C);
    // 0x800DA150: div.s       $f20, $f8, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800DA154: div.s       $f22, $f10, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800DA158: b           L_800DA16C
    // 0x800DA15C: div.s       $f24, $f16, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
        goto L_800DA16C;
    // 0x800DA15C: div.s       $f24, $f16, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f24.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800DA160: lwc1        $f20, 0x14($s2)
    ctx->f20.u32l = MEM_W(ctx->r18, 0X14);
L_800DA164:
    // 0x800DA164: lwc1        $f22, 0x18($s2)
    ctx->f22.u32l = MEM_W(ctx->r18, 0X18);
    // 0x800DA168: lwc1        $f24, 0x1C($s2)
    ctx->f24.u32l = MEM_W(ctx->r18, 0X1C);
L_800DA16C:
    // 0x800DA16C: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800DA170: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800DA174: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800DA178: lw          $t8, 0x4($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X4);
    // 0x800DA17C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800DA180: lw          $t9, 0x8($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X8);
    // 0x800DA184: blez        $s3, L_800DA24C
    if (SIGNED(ctx->r19) <= 0) {
        // 0x800DA188: sw          $t9, 0x8($s0)
        MEM_W(0X8, ctx->r16) = ctx->r25;
            goto L_800DA24C;
    }
    // 0x800DA188: sw          $t9, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r25;
    // 0x800DA18C: lw          $t0, 0x64($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X64);
    // 0x800DA190: bne         $t0, $zero, L_800DA24C
    if (ctx->r8 != 0) {
        // 0x800DA194: nop
    
            goto L_800DA24C;
    }
    // 0x800DA194: nop

    // 0x800DA198: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
L_800DA19C:
    // 0x800DA19C: sw          $t2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r10;
    // 0x800DA1A0: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x800DA1A4: sw          $t1, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r9;
    // 0x800DA1A8: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x800DA1AC: bne         $s1, $zero, L_800DA1FC
    if (ctx->r17 != 0) {
        // 0x800DA1B0: sw          $t2, 0x8($s4)
        MEM_W(0X8, ctx->r20) = ctx->r10;
            goto L_800DA1FC;
    }
    // 0x800DA1B0: sw          $t2, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r10;
    // 0x800DA1B4: lwc1        $f18, 0x20($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800DA1B8: lwc1        $f4, 0x2C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800DA1BC: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA1C0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DA1C4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800DA1C8: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA1CC: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800DA1D0: lwc1        $f18, 0x30($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800DA1D4: lwc1        $f16, 0x24($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800DA1D8: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DA1DC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DA1E0: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DA1E4: swc1        $f6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f6.u32l;
    // 0x800DA1E8: lwc1        $f16, 0x34($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800DA1EC: lwc1        $f10, 0x28($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800DA1F0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DA1F4: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800DA1F8: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
L_800DA1FC:
    // 0x800DA1FC: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA200: lwc1        $f16, 0x4($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA204: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DA208: add.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800DA20C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DA210: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DA214: add.s       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800DA218: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800DA21C: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x800DA220: add.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f24.fl;
    // 0x800DA224: swc1        $f8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->f8.u32l;
    // 0x800DA228: jalr        $s7
    // 0x800DA22C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    LOOKUP_FUNC(ctx->r23)(rdram, ctx);
        goto after_0;
    // 0x800DA22C: swc1        $f4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f4.u32l;
    after_0:
    // 0x800DA230: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800DA234: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800DA238: beq         $at, $zero, L_800DA24C
    if (ctx->r1 == 0) {
        // 0x800DA23C: sw          $v0, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->r2;
            goto L_800DA24C;
    }
    // 0x800DA23C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800DA240: lw          $t3, 0x64($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X64);
    // 0x800DA244: beql        $t3, $zero, L_800DA19C
    if (ctx->r11 == 0) {
        // 0x800DA248: lw          $t2, 0x0($s0)
        ctx->r10 = MEM_W(ctx->r16, 0X0);
            goto L_800DA19C;
    }
    goto skip_5;
    // 0x800DA248: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    skip_5:
L_800DA24C:
    // 0x800DA24C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800DA250: lhu         $t4, 0x1398($t4)
    ctx->r12 = MEM_HU(ctx->r12, 0X1398);
    // 0x800DA254: sh          $t4, 0x5C($s2)
    MEM_H(0X5C, ctx->r18) = ctx->r12;
    // 0x800DA258: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x800DA25C: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x800DA260: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x800DA264: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x800DA268: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x800DA26C: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x800DA270: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x800DA274: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800DA278: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800DA27C: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x800DA280: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x800DA284: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x800DA288: lw          $v0, 0x50($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X50);
    // 0x800DA28C: jr          $ra
    // 0x800DA290: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x800DA290: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void sc1PIntroMakeNameAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132B14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132B18: jal         0x80132668
    // 0x80132B1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    sc1PIntroMakeName(rdram, ctx);
        goto after_0;
    // 0x80132B1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80132B20: jal         0x801324EC
    // 0x80132B24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    sc1PIntroMakeVSName(rdram, ctx);
        goto after_1;
    // 0x80132B24: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80132B28: jal         0x8013294C
    // 0x80132B2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    sc1PIntroSetNamePositions(rdram, ctx);
        goto after_2;
    // 0x80132B2C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80132B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132B38: jr          $ra
    // 0x80132B3C: nop

    return;
    // 0x80132B3C: nop

;}
RECOMP_FUNC void gcGetGObjSetNextAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800078FC: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80007900: lh          $v0, 0x6A12($v0)
    ctx->r2 = MEM_H(ctx->r2, 0X6A12);
    // 0x80007904: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007908: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000790C: beq         $v0, $at, L_80007924
    if (ctx->r2 == ctx->r1) {
        // 0x80007910: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80007924;
    }
    // 0x80007910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007914: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80007918: lw          $t6, 0x6A0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A0C);
    // 0x8000791C: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80007920: beq         $at, $zero, L_80007960
    if (ctx->r1 == 0) {
        // 0x80007924: lui         $a2, 0x8004
        ctx->r6 = S32(0X8004 << 16);
            goto L_80007960;
    }
L_80007924:
    // 0x80007924: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80007928: addiu       $a2, $a2, 0x67FC
    ctx->r6 = ADD32(ctx->r6, 0X67FC);
    // 0x8000792C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80007930: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007934: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80007938: bne         $v1, $zero, L_80007968
    if (ctx->r3 != 0) {
        // 0x8000793C: nop
    
            goto L_80007968;
    }
    // 0x8000793C: nop

    // 0x80007940: jal         0x80004980
    // 0x80007944: lhu         $a0, 0x6A10($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X6A10);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x80007944: lhu         $a0, 0x6A10($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X6A10);
    after_0:
    // 0x80007948: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x8000794C: addiu       $a2, $a2, 0x67FC
    ctx->r6 = ADD32(ctx->r6, 0X67FC);
    // 0x80007950: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
    // 0x80007954: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80007958: b           L_80007968
    // 0x8000795C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
        goto L_80007968;
    // 0x8000795C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_80007960:
    // 0x80007960: b           L_80007998
    // 0x80007964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80007998;
    // 0x80007964: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80007968:
    // 0x80007968: bnel        $v1, $zero, L_8000797C
    if (ctx->r3 != 0) {
        // 0x8000796C: lw          $t8, 0x4($v1)
        ctx->r24 = MEM_W(ctx->r3, 0X4);
            goto L_8000797C;
    }
    goto skip_0;
    // 0x8000796C: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    skip_0:
    // 0x80007970: b           L_80007998
    // 0x80007974: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80007998;
    // 0x80007974: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80007978: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
L_8000797C:
    // 0x8000797C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80007980: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80007984: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80007988: lw          $t9, 0x6A0C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A0C);
    // 0x8000798C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80007990: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80007994: sw          $t0, 0x6A0C($at)
    MEM_W(0X6A0C, ctx->r1) = ctx->r8;
L_80007998:
    // 0x80007998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000799C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800079A0: jr          $ra
    // 0x800079A4: nop

    return;
    // 0x800079A4: nop

;}
RECOMP_FUNC void efManagerShieldBreakMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101790: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101794: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80101798: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010179C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801017A0: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x801017A4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801017A8: jal         0x800D35DC
    // 0x801017AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    lbParticleMakeGenerator(rdram, ctx);
        goto after_0;
    // 0x801017AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x801017B0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801017B4: beq         $v0, $zero, L_801017D4
    if (ctx->r2 == 0) {
        // 0x801017B8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801017D4;
    }
    // 0x801017B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801017BC: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801017C0: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x801017C4: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801017C8: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x801017CC: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801017D0: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
L_801017D4:
    // 0x801017D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801017D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801017DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801017E0: jr          $ra
    // 0x801017E4: nop

    return;
    // 0x801017E4: nop

;}
RECOMP_FUNC void mnPlayers1PGameCheckFighterCrossed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132550: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80132554: jr          $ra
    // 0x80132558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132558: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void dbCubeStartRumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BD4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131BD8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131BDC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131BE0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80131BE4: lw          $a2, 0x2D44($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X2D44);
    // 0x80131BE8: lw          $a1, 0x2D40($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X2D40);
    // 0x80131BEC: jal         0x80115530
    // 0x80131BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gmRumbleSetPlayerRumbleParams(rdram, ctx);
        goto after_0;
    // 0x80131BF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80131BF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131BF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131BFC: jr          $ra
    // 0x80131C00: nop

    return;
    // 0x80131C00: nop

;}
RECOMP_FUNC void mvEndingMakeRoomBooks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C94: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131C9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131CA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131CA4: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131CA8: jal         0x80009968
    // 0x80131CAC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131CAC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131CB0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131CB4: lw          $t6, 0x2F70($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2F70);
    // 0x80131CB8: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80131CBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CC0: addiu       $t7, $t7, -0x5908
    ctx->r15 = ADD32(ctx->r15, -0X5908);
    // 0x80131CC4: sw          $v0, 0x2BE8($at)
    MEM_W(0X2BE8, ctx->r1) = ctx->r2;
    // 0x80131CC8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131CCC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131CD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131CD4: jal         0x8000F120
    // 0x80131CD8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131CD8: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131CDC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131CE0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131CE4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131CE8: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80131CEC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131CF0: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80131CF4: jal         0x80009DF4
    // 0x80131CF8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131CF8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131CFC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131D00: lw          $t9, 0x2F70($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X2F70);
    // 0x80131D04: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80131D08: addiu       $t0, $t0, -0x5850
    ctx->r8 = ADD32(ctx->r8, -0X5850);
    // 0x80131D0C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131D10: lui         $a2, 0x4396
    ctx->r6 = S32(0X4396 << 16);
    // 0x80131D14: jal         0x8000BD8C
    // 0x80131D18: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x80131D18: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80131D1C: jal         0x8000DF34
    // 0x80131D20: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    gcPlayAnimAll(rdram, ctx);
        goto after_4;
    // 0x80131D20: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80131D24: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131D28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131D2C: jr          $ra
    // 0x80131D30: nop

    return;
    // 0x80131D30: nop

;}
RECOMP_FUNC void ftLinkSpecialAirNEmptyProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016382C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80163830: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163834: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80163838: jal         0x800DE6E4
    // 0x8016383C: addiu       $a1, $a1, 0x397C
    ctx->r5 = ADD32(ctx->r5, 0X397C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8016383C: addiu       $a1, $a1, 0x397C
    ctx->r5 = ADD32(ctx->r5, 0X397C);
    after_0:
    // 0x80163840: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80163844: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80163848: jr          $ra
    // 0x8016384C: nop

    return;
    // 0x8016384C: nop

;}
RECOMP_FUNC void mvOpeningJungleMakeFighters(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D2DC: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8018D2E0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8018D2E4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D2E8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D2EC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D2F0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D2F4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D2F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D2FC: jal         0x80104BDC
    // 0x8018D300: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_0;
    // 0x8018D300: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018D304: jal         0x80105600
    // 0x8018D308: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_1;
    // 0x8018D308: nop

    after_1:
    // 0x8018D30C: jal         0x800FC7A4
    // 0x8018D310: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_2;
    // 0x8018D310: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    after_2:
    // 0x8018D314: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8018D318: beq         $v0, $s0, L_8018D340
    if (ctx->r2 == ctx->r16) {
        // 0x8018D31C: addiu       $a0, $zero, 0x16
        ctx->r4 = ADD32(0, 0X16);
            goto L_8018D340;
    }
    // 0x8018D31C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x8018D320: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D324: addiu       $s0, $s0, -0x2610
    ctx->r16 = ADD32(ctx->r16, -0X2610);
L_8018D328:
    // 0x8018D328: jal         0x80023624
    // 0x8018D32C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x8018D32C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018D330: jal         0x800A3040
    // 0x8018D334: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x8018D334: nop

    after_4:
    // 0x8018D338: b           L_8018D328
    // 0x8018D33C: nop

        goto L_8018D328;
    // 0x8018D33C: nop

L_8018D340:
    // 0x8018D340: jal         0x800FC814
    // 0x8018D344: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_5;
    // 0x8018D344: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    after_5:
    // 0x8018D348: addiu       $s1, $sp, 0x9C
    ctx->r17 = ADD32(ctx->r29, 0X9C);
    // 0x8018D34C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8018D350: jal         0x800FC894
    // 0x8018D354: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_6;
    // 0x8018D354: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    after_6:
    // 0x8018D358: jal         0x800FC7A4
    // 0x8018D35C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_7;
    // 0x8018D35C: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    after_7:
    // 0x8018D360: beq         $v0, $s0, L_8018D388
    if (ctx->r2 == ctx->r16) {
        // 0x8018D364: addiu       $a0, $zero, 0x17
        ctx->r4 = ADD32(0, 0X17);
            goto L_8018D388;
    }
    // 0x8018D364: addiu       $a0, $zero, 0x17
    ctx->r4 = ADD32(0, 0X17);
    // 0x8018D368: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D36C: addiu       $s0, $s0, -0x25F4
    ctx->r16 = ADD32(ctx->r16, -0X25F4);
L_8018D370:
    // 0x8018D370: jal         0x80023624
    // 0x8018D374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_8;
    // 0x8018D374: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8018D378: jal         0x800A3040
    // 0x8018D37C: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_9;
    // 0x8018D37C: nop

    after_9:
    // 0x8018D380: b           L_8018D370
    // 0x8018D384: nop

        goto L_8018D370;
    // 0x8018D384: nop

L_8018D388:
    // 0x8018D388: jal         0x800FC814
    // 0x8018D38C: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_10;
    // 0x8018D38C: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    after_10:
    // 0x8018D390: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x8018D394: jal         0x800FC894
    // 0x8018D398: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_11;
    // 0x8018D398: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_11:
    // 0x8018D39C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D3A0: lwc1        $f6, -0x25D0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X25D0);
    // 0x8018D3A4: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018D3A8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8018D3AC: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
    // 0x8018D3B0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8018D3B4: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8018D3B8: lw          $a1, 0x4($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X4);
    // 0x8018D3BC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8018D3C0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018D3C4: lw          $a2, 0x8($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8);
    // 0x8018D3C8: jal         0x8018D168
    // 0x8018D3CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    mvOpeningJungleMakeGroundViewport(rdram, ctx);
        goto after_12;
    // 0x8018D3CC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_12:
    // 0x8018D3D0: jal         0x801156E4
    // 0x8018D3D4: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_13;
    // 0x8018D3D4: nop

    after_13:
    // 0x8018D3D8: jal         0x801653E0
    // 0x8018D3DC: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_14;
    // 0x8018D3DC: nop

    after_14:
    // 0x8018D3E0: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018D3E4: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018D3E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D3EC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018D3F0: addiu       $s6, $sp, 0x4C
    ctx->r22 = ADD32(ctx->r29, 0X4C);
    // 0x8018D3F4: addiu       $s4, $zero, 0x2
    ctx->r20 = ADD32(0, 0X2);
L_8018D3F8:
    // 0x8018D3F8: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x8018D3FC: addiu       $t8, $t8, 0x6DD0
    ctx->r24 = ADD32(ctx->r24, 0X6DD0);
    // 0x8018D400: addiu       $t2, $t8, 0x3C
    ctx->r10 = ADD32(ctx->r24, 0X3C);
    // 0x8018D404: or          $t1, $s6, $zero
    ctx->r9 = ctx->r22 | 0;
L_8018D408:
    // 0x8018D408: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8018D40C: addiu       $t8, $t8, 0xC
    ctx->r24 = ADD32(ctx->r24, 0XC);
    // 0x8018D410: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018D414: sw          $t0, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r8;
    // 0x8018D418: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x8018D41C: sw          $t9, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r25;
    // 0x8018D420: lw          $t0, -0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, -0X4);
    // 0x8018D424: bne         $t8, $t2, L_8018D408
    if (ctx->r24 != ctx->r10) {
        // 0x8018D428: sw          $t0, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r8;
            goto L_8018D408;
    }
    // 0x8018D428: sw          $t0, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r8;
    // 0x8018D42C: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8018D430: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8018D434: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x8018D438: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
    // 0x8018D43C: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8018D440: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8018D444: addiu       $t6, $t6, 0x5228
    ctx->r14 = ADD32(ctx->r14, 0X5228);
    // 0x8018D448: addu        $s0, $t3, $s2
    ctx->r16 = ADD32(ctx->r11, ctx->r18);
    // 0x8018D44C: lbu         $t4, 0x22($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D450: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8018D454: addu        $s3, $t5, $t6
    ctx->r19 = ADD32(ctx->r13, ctx->r14);
    // 0x8018D458: beql        $s4, $t4, L_8018D5B0
    if (ctx->r20 == ctx->r12) {
        // 0x8018D45C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D5B0;
    }
    goto skip_0;
    // 0x8018D45C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8018D460: jal         0x800D786C
    // 0x8018D464: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_15;
    // 0x8018D464: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_15:
    // 0x8018D468: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018D46C: lwc1        $f10, 0x9C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8018D470: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018D474: addu        $s0, $v0, $s2
    ctx->r16 = ADD32(ctx->r2, ctx->r18);
    // 0x8018D478: lbu         $t7, 0x23($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D47C: addiu       $t1, $zero, 0xC8
    ctx->r9 = ADD32(0, 0XC8);
    // 0x8018D480: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018D484: sw          $t7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r15;
    // 0x8018D488: lbu         $t2, 0x23($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D48C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8018D490: addiu       $t0, $zero, 0x28
    ctx->r8 = ADD32(0, 0X28);
    // 0x8018D494: bne         $s4, $t2, L_8018D4BC
    if (ctx->r20 != ctx->r10) {
        // 0x8018D498: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8018D4BC;
    }
    // 0x8018D498: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018D49C: lwc1        $f16, 0xA0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8018D4A0: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8018D4A4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x8018D4A8: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x8018D4AC: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x8018D4B0: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x8018D4B4: b           L_8018D4D8
    // 0x8018D4B8: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
        goto L_8018D4D8;
    // 0x8018D4B8: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
L_8018D4BC:
    // 0x8018D4BC: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018D4C0: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8018D4C4: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8018D4C8: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x8018D4CC: sw          $t0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r8;
    // 0x8018D4D0: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8018D4D4: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
L_8018D4D8:
    // 0x8018D4D8: lbu         $t3, 0x24($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X24);
    // 0x8018D4DC: sb          $s1, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r17;
    // 0x8018D4E0: sb          $t4, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r12;
    // 0x8018D4E4: sb          $t3, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r11;
    // 0x8018D4E8: lbu         $t5, 0x26($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X26);
    // 0x8018D4EC: sb          $t5, 0x63($sp)
    MEM_B(0X63, ctx->r29) = ctx->r13;
    // 0x8018D4F0: lbu         $t6, 0x21($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X21);
    // 0x8018D4F4: sb          $t6, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r14;
    // 0x8018D4F8: lbu         $t7, 0x20($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X20);
    // 0x8018D4FC: sb          $t7, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r15;
    // 0x8018D500: lbu         $t2, 0x7($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X7);
    // 0x8018D504: sb          $t2, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r10;
    // 0x8018D508: lbu         $t8, 0x22($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D50C: sw          $s3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r19;
    // 0x8018D510: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x8018D514: jal         0x800D78B4
    // 0x8018D518: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_16;
    // 0x8018D518: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_16:
    // 0x8018D51C: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x8018D520: jal         0x800D7F3C
    // 0x8018D524: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_17;
    // 0x8018D524: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_17:
    // 0x8018D528: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D52C: sw          $v0, -0x25B0($at)
    MEM_W(-0X25B0, ctx->r1) = ctx->r2;
    // 0x8018D530: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x8018D534: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D538: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D53C: addu        $t9, $t1, $s2
    ctx->r25 = ADD32(ctx->r9, ctx->r18);
    // 0x8018D540: lbu         $t0, 0x23($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X23);
    // 0x8018D544: bnel        $s4, $t0, L_8018D560
    if (ctx->r20 != ctx->r8) {
        // 0x8018D548: lw          $v1, 0x84($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X84);
            goto L_8018D560;
    }
    goto skip_1;
    // 0x8018D548: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    skip_1:
    // 0x8018D54C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8018D550: addiu       $t3, $zero, 0x9
    ctx->r11 = ADD32(0, 0X9);
    // 0x8018D554: b           L_8018D568
    // 0x8018D558: sw          $t3, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = ctx->r11;
        goto L_8018D568;
    // 0x8018D558: sw          $t3, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = ctx->r11;
    // 0x8018D55C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
L_8018D560:
    // 0x8018D560: addiu       $t4, $zero, 0x6
    ctx->r12 = ADD32(0, 0X6);
    // 0x8018D564: sw          $t4, 0xADC($v1)
    MEM_W(0XADC, ctx->r3) = ctx->r12;
L_8018D568:
    // 0x8018D568: jal         0x800E7C4C
    // 0x8018D56C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_18;
    // 0x8018D56C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_18:
    // 0x8018D570: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8018D574: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D578: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D57C: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8018D580: lbu         $t7, 0x23($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X23);
    // 0x8018D584: bne         $s4, $t7, L_8018D5A4
    if (ctx->r20 != ctx->r15) {
        // 0x8018D588: nop
    
            goto L_8018D5A4;
    }
    // 0x8018D588: nop

    // 0x8018D58C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D590: addiu       $a1, $a1, -0x2758
    ctx->r5 = ADD32(ctx->r5, -0X2758);
    // 0x8018D594: jal         0x800E9B30
    // 0x8018D598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetKey(rdram, ctx);
        goto after_19;
    // 0x8018D598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8018D59C: b           L_8018D5B0
    // 0x8018D5A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_8018D5B0;
    // 0x8018D5A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D5A4:
    // 0x8018D5A4: jal         0x800E9B30
    // 0x8018D5A8: addiu       $a1, $a1, -0x2710
    ctx->r5 = ADD32(ctx->r5, -0X2710);
    ftParamSetKey(rdram, ctx);
        goto after_20;
    // 0x8018D5A8: addiu       $a1, $a1, -0x2710
    ctx->r5 = ADD32(ctx->r5, -0X2710);
    after_20:
    // 0x8018D5AC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D5B0:
    // 0x8018D5B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8018D5B4: bne         $s1, $at, L_8018D3F8
    if (ctx->r17 != ctx->r1) {
        // 0x8018D5B8: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018D3F8;
    }
    // 0x8018D5B8: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018D5BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8018D5C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D5C4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D5C8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018D5CC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018D5D0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018D5D4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D5D8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018D5DC: jr          $ra
    // 0x8018D5E0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8018D5E0: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void mvOpeningRoomCheckSetFramebuffer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134318: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8013431C: lw          $t6, 0x4F9C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4F9C);
    // 0x80134320: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134324: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134328: beq         $t6, $zero, L_80134338
    if (ctx->r14 == 0) {
        // 0x8013432C: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_80134338;
    }
    // 0x8013432C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80134330: b           L_801343F0
    // 0x80134334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801343F0;
    // 0x80134334: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134338:
    // 0x80134338: jal         0x80032690
    // 0x8013433C: nop

    osViGetNextFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x8013433C: nop

    after_0:
    // 0x80134340: jal         0x80039630
    // 0x80134344: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80134344: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80134348: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8013434C: lw          $v1, 0x4FA8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4FA8);
    // 0x80134350: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80134354: addiu       $a1, $a1, 0x2A00
    ctx->r5 = ADD32(ctx->r5, 0X2A00);
    // 0x80134358: bne         $a1, $v1, L_80134368
    if (ctx->r5 != ctx->r3) {
        // 0x8013435C: lui         $t7, 0x803B
        ctx->r15 = S32(0X803B << 16);
            goto L_80134368;
    }
    // 0x8013435C: lui         $t7, 0x803B
    ctx->r15 = S32(0X803B << 16);
    // 0x80134360: b           L_80134394
    // 0x80134364: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80134394;
    // 0x80134364: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80134368:
    // 0x80134368: addiu       $t7, $t7, 0x6900
    ctx->r15 = ADD32(ctx->r15, 0X6900);
    // 0x8013436C: bne         $t7, $v1, L_8013437C
    if (ctx->r15 != ctx->r3) {
        // 0x80134370: lui         $t8, 0x803E
        ctx->r24 = S32(0X803E << 16);
            goto L_8013437C;
    }
    // 0x80134370: lui         $t8, 0x803E
    ctx->r24 = S32(0X803E << 16);
    // 0x80134374: b           L_80134394
    // 0x80134378: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_80134394;
    // 0x80134378: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8013437C:
    // 0x8013437C: addiu       $t8, $t8, -0x5800
    ctx->r24 = ADD32(ctx->r24, -0X5800);
    // 0x80134380: bnel        $t8, $v1, L_80134394
    if (ctx->r24 != ctx->r3) {
        // 0x80134384: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80134394;
    }
    goto skip_0;
    // 0x80134384: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    skip_0:
    // 0x80134388: b           L_80134394
    // 0x8013438C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80134394;
    // 0x8013438C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80134390: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80134394:
    // 0x80134394: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x80134398: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8013439C: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x801343A0: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x801343A4: sll         $t9, $t9, 8
    ctx->r25 = S32(ctx->r25 << 8);
    // 0x801343A8: addu        $a0, $a1, $t9
    ctx->r4 = ADD32(ctx->r5, ctx->r25);
    // 0x801343AC: beq         $v0, $a0, L_801343EC
    if (ctx->r2 == ctx->r4) {
        // 0x801343B0: lw          $t0, 0x1C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X1C);
            goto L_801343EC;
    }
    // 0x801343B0: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x801343B4: beq         $t0, $a0, L_801343EC
    if (ctx->r8 == ctx->r4) {
        // 0x801343B8: sll         $t1, $v1, 3
        ctx->r9 = S32(ctx->r3 << 3);
            goto L_801343EC;
    }
    // 0x801343B8: sll         $t1, $v1, 3
    ctx->r9 = S32(ctx->r3 << 3);
    // 0x801343BC: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x801343C0: sll         $t1, $t1, 6
    ctx->r9 = S32(ctx->r9 << 6);
    // 0x801343C4: subu        $t1, $t1, $v1
    ctx->r9 = SUB32(ctx->r9, ctx->r3);
    // 0x801343C8: sll         $t1, $t1, 8
    ctx->r9 = S32(ctx->r9 << 8);
    // 0x801343CC: addu        $t2, $a1, $t1
    ctx->r10 = ADD32(ctx->r5, ctx->r9);
    // 0x801343D0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x801343D4: jal         0x80033490
    // 0x801343D8: sw          $t2, 0x4F9C($at)
    MEM_W(0X4F9C, ctx->r1) = ctx->r10;
    osGetCount_recomp(rdram, ctx);
        goto after_2;
    // 0x801343D8: sw          $t2, 0x4F9C($at)
    MEM_W(0X4F9C, ctx->r1) = ctx->r10;
    after_2:
    // 0x801343DC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x801343E0: sw          $v0, 0x4FAC($at)
    MEM_W(0X4FAC, ctx->r1) = ctx->r2;
    // 0x801343E4: b           L_801343F0
    // 0x801343E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801343F0;
    // 0x801343E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801343EC:
    // 0x801343EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801343F0:
    // 0x801343F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801343F4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801343F8: jr          $ra
    // 0x801343FC: nop

    return;
    // 0x801343FC: nop

;}
RECOMP_FUNC void itTaruHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179D60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179D64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179D68: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80179D6C: addiu       $a1, $a1, -0x5B7C
    ctx->r5 = ADD32(ctx->r5, -0X5B7C);
    // 0x80179D70: jal         0x80172EC8
    // 0x80179D74: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80179D74: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x80179D78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179D7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179D80: jr          $ra
    // 0x80179D84: nop

    return;
    // 0x80179D84: nop

;}

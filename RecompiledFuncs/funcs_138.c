#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mn1PModeMakeDecalsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132870: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132874: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132878: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8013287C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132880: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x80132884: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132888: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013288C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132890: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132894: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132898: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8013289C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801328A0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801328A4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801328A8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801328AC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801328B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801328B4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801328B8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801328BC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801328C0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801328C4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801328C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801328CC: jal         0x8000B93C
    // 0x801328D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801328D0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801328D4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801328D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801328DC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801328E0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801328E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801328E8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801328EC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801328F0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801328F4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801328F8: jal         0x80007080
    // 0x801328FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801328FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132900: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132904: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132908: jr          $ra
    // 0x8013290C: nop

    return;
    // 0x8013290C: nop

;}
RECOMP_FUNC void mnVSModePow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: bne         $a1, $zero, L_80131B34
    if (ctx->r5 != 0) {
        // 0x80131B28: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80131B34;
    }
    // 0x80131B28: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80131B2C: jr          $ra
    // 0x80131B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B34:
    // 0x80131B34: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80131B38: bne         $at, $zero, L_80131BB8
    if (ctx->r1 != 0) {
        // 0x80131B3C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80131BB8;
    }
    // 0x80131B3C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80131B40: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x80131B44: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80131B48: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x80131B4C: beq         $a3, $zero, L_80131B70
    if (ctx->r7 == 0) {
        // 0x80131B50: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_80131B70;
    }
    // 0x80131B50: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
L_80131B54:
    // 0x80131B54: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B58: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80131B5C: mflo        $v1
    ctx->r3 = lo;
    // 0x80131B60: bne         $a2, $v0, L_80131B54
    if (ctx->r6 != ctx->r2) {
        // 0x80131B64: nop
    
            goto L_80131B54;
    }
    // 0x80131B64: nop

    // 0x80131B68: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80131B6C: beq         $v0, $a1, L_80131BB8
    if (ctx->r2 == ctx->r5) {
        // 0x80131B70: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80131BB8;
    }
L_80131B70:
    // 0x80131B70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80131B74:
    // 0x80131B74: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B78: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80131B7C: mflo        $v1
    ctx->r3 = lo;
    // 0x80131B80: nop

    // 0x80131B84: nop

    // 0x80131B88: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B8C: mflo        $v1
    ctx->r3 = lo;
    // 0x80131B90: nop

    // 0x80131B94: nop

    // 0x80131B98: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B9C: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BA0: nop

    // 0x80131BA4: nop

    // 0x80131BA8: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BAC: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BB0: bne         $v0, $a1, L_80131B74
    if (ctx->r2 != ctx->r5) {
        // 0x80131BB4: nop
    
            goto L_80131B74;
    }
    // 0x80131BB4: nop

L_80131BB8:
    // 0x80131BB8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131BBC: jr          $ra
    // 0x80131BC0: nop

    return;
    // 0x80131BC0: nop

;}
RECOMP_FUNC void itEggFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018168C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181690: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80181694: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80181698: addiu       $a3, $a3, 0x16E0
    ctx->r7 = ADD32(ctx->r7, 0X16E0);
    // 0x8018169C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x801816A0: jal         0x80173B24
    // 0x801816A4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x801816A4: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x801816A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801816AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801816B0: jr          $ra
    // 0x801816B4: nop

    return;
    // 0x801816B4: nop

;}
RECOMP_FUNC void mnTitleTransitionFromFireLogo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132320: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80132324: addiu       $a2, $a2, 0x66F0
    ctx->r6 = ADD32(ctx->r6, 0X66F0);
    // 0x80132328: lw          $v0, 0x1C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X1C);
    // 0x8013232C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132330: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132334: beq         $v0, $zero, L_8013235C
    if (ctx->r2 == 0) {
        // 0x80132338: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8013235C;
    }
    // 0x80132338: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013233C: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
L_80132340:
    // 0x80132340: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80132344: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80132348: bne         $a0, $t6, L_80132354
    if (ctx->r4 != ctx->r14) {
        // 0x8013234C: nop
    
            goto L_80132354;
    }
    // 0x8013234C: nop

    // 0x80132350: sw          $a1, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r5;
L_80132354:
    // 0x80132354: bne         $v1, $zero, L_80132340
    if (ctx->r3 != 0) {
        // 0x80132358: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80132340;
    }
    // 0x80132358: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013235C:
    // 0x8013235C: lw          $a0, 0x10($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X10);
    // 0x80132360: beql        $a0, $zero, L_8013237C
    if (ctx->r4 == 0) {
        // 0x80132364: lw          $a0, 0x38($a2)
        ctx->r4 = MEM_W(ctx->r6, 0X38);
            goto L_8013237C;
    }
    goto skip_0;
    // 0x80132364: lw          $a0, 0x38($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X38);
    skip_0:
    // 0x80132368: jal         0x80009A84
    // 0x8013236C: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x8013236C: nop

    after_0:
    // 0x80132370: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80132374: addiu       $a2, $a2, 0x66F0
    ctx->r6 = ADD32(ctx->r6, 0X66F0);
    // 0x80132378: lw          $a0, 0x38($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X38);
L_8013237C:
    // 0x8013237C: beq         $a0, $zero, L_8013238C
    if (ctx->r4 == 0) {
        // 0x80132380: nop
    
            goto L_8013238C;
    }
    // 0x80132380: nop

    // 0x80132384: jal         0x80009A84
    // 0x80132388: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80132388: nop

    after_1:
L_8013238C:
    // 0x8013238C: jal         0x801323AC
    // 0x80132390: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    mnTitleShowGObjLinkID(rdram, ctx);
        goto after_2;
    // 0x80132390: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_2:
    // 0x80132394: jal         0x80132210
    // 0x80132398: nop

    mnTitleUpdateFireVars(rdram, ctx);
        goto after_3;
    // 0x80132398: nop

    after_3:
    // 0x8013239C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801323A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801323A4: jr          $ra
    // 0x801323A8: nop

    return;
    // 0x801323A8: nop

;}
RECOMP_FUNC void ftBossOkukoukiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A314: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015A318: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015A31C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015A320: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015A324: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x8015A328: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015A32C: jal         0x800E6F24
    // 0x8015A330: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A330: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015A334: jal         0x80158030
    // 0x8015A338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftBossCommonCheckPlayerInvertLR(rdram, ctx);
        goto after_1;
    // 0x8015A338: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015A33C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015A340: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015A344: jr          $ra
    // 0x8015A348: nop

    return;
    // 0x8015A348: nop

;}
RECOMP_FUNC void mnPlayersVSUpdateGameMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135334: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80135338: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013533C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135340: addiu       $t7, $t7, -0x4838
    ctx->r15 = ADD32(ctx->r15, -0X4838);
    // 0x80135344: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80135348: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013534C: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80135350: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80135354: addiu       $t1, $t1, -0x4830
    ctx->r9 = ADD32(ctx->r9, -0X4830);
    // 0x80135358: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8013535C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80135360: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80135364: addiu       $t0, $sp, 0x1C
    ctx->r8 = ADD32(ctx->r29, 0X1C);
    // 0x80135368: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8013536C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80135370: lhu         $t3, 0x4($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X4);
    // 0x80135374: addiu       $a2, $a2, -0x4258
    ctx->r6 = ADD32(ctx->r6, -0X4258);
    // 0x80135378: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x8013537C: sh          $t3, 0x4($t0)
    MEM_H(0X4, ctx->r8) = ctx->r11;
    // 0x80135380: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80135384: lw          $t4, -0x4250($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4250);
    // 0x80135388: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8013538C: bne         $v0, $t5, L_8013539C
    if (ctx->r2 != ctx->r13) {
        // 0x80135390: sw          $t4, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r12;
            goto L_8013539C;
    }
    // 0x80135390: sw          $t4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r12;
    // 0x80135394: b           L_801353A0
    // 0x80135398: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_801353A0;
    // 0x80135398: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8013539C:
    // 0x8013539C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_801353A0:
    // 0x801353A0: jal         0x800266A0
    // 0x801353A4: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_0;
    // 0x801353A4: nop

    after_0:
    // 0x801353A8: jal         0x800269C0
    // 0x801353AC: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x801353AC: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_1:
    // 0x801353B0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x801353B4: addiu       $a2, $a2, -0x4258
    ctx->r6 = ADD32(ctx->r6, -0X4258);
    // 0x801353B8: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801353BC: bne         $t6, $zero, L_801353D4
    if (ctx->r14 != 0) {
        // 0x801353C0: nop
    
            goto L_801353D4;
    }
    // 0x801353C0: nop

    // 0x801353C4: jal         0x800269C0
    // 0x801353C8: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x801353C8: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    after_2:
    // 0x801353CC: b           L_801353DC
    // 0x801353D0: nop

        goto L_801353DC;
    // 0x801353D0: nop

L_801353D4:
    // 0x801353D4: jal         0x800269C0
    // 0x801353D8: addiu       $a0, $zero, 0x20E
    ctx->r4 = ADD32(0, 0X20E);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x801353D8: addiu       $a0, $zero, 0x20E
    ctx->r4 = ADD32(0, 0X20E);
    after_3:
L_801353DC:
    // 0x801353DC: jal         0x8000B760
    // 0x801353E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    gcRemoveSObjAll(rdram, ctx);
        goto after_4;
    // 0x801353E0: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    after_4:
    // 0x801353E4: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x801353E8: addiu       $a2, $a2, -0x4258
    ctx->r6 = ADD32(ctx->r6, -0X4258);
    // 0x801353EC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x801353F0: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x801353F4: lw          $t0, -0x3B50($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3B50);
    // 0x801353F8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801353FC: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80135400: lw          $t9, 0x24($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X24);
    // 0x80135404: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x80135408: jal         0x800CCFDC
    // 0x8013540C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8013540C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_5:
    // 0x80135410: lhu         $t1, 0x24($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X24);
    // 0x80135414: lui         $at, 0x41D8
    ctx->r1 = S32(0X41D8 << 16);
    // 0x80135418: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013541C: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80135420: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135424: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80135428: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8013542C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80135430: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80135434: addiu       $a2, $a2, -0x4258
    ctx->r6 = ADD32(ctx->r6, -0X4258);
    // 0x80135438: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x8013543C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80135440: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80135444: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80135448: addiu       $v1, $zero, 0x3
    ctx->r3 = ADD32(0, 0X3);
    // 0x8013544C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80135450: multu       $t5, $v1
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135454: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135458: mflo        $t6
    ctx->r14 = lo;
    // 0x8013545C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80135460: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80135464: sb          $t8, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r24;
    // 0x80135468: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8013546C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80135470: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135474: mflo        $t0
    ctx->r8 = lo;
    // 0x80135478: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x8013547C: lbu         $t2, 0x1($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X1);
    // 0x80135480: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80135484: sb          $t2, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r10;
    // 0x80135488: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8013548C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80135490: multu       $t3, $v1
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80135494: mflo        $t4
    ctx->r12 = lo;
    // 0x80135498: addu        $t5, $a0, $t4
    ctx->r13 = ADD32(ctx->r4, ctx->r12);
    // 0x8013549C: lbu         $t6, 0x2($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X2);
    // 0x801354A0: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x801354A4: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x801354A8: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x801354AC: bne         $t7, $at, L_80135510
    if (ctx->r15 != ctx->r1) {
        // 0x801354B0: nop
    
            goto L_80135510;
    }
    // 0x801354B0: nop

    // 0x801354B4: lw          $t8, -0x4530($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X4530);
    // 0x801354B8: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // 0x801354BC: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801354C0: beq         $v0, $t8, L_801354CC
    if (ctx->r2 == ctx->r24) {
        // 0x801354C4: lui         $at, 0x8014
        ctx->r1 = S32(0X8014 << 16);
            goto L_801354CC;
    }
    // 0x801354C4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801354C8: sw          $t9, -0x4528($at)
    MEM_W(-0X4528, ctx->r1) = ctx->r25;
L_801354CC:
    // 0x801354CC: lw          $t0, -0x4474($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X4474);
    // 0x801354D0: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x801354D4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801354D8: beq         $v0, $t0, L_801354E4
    if (ctx->r2 == ctx->r8) {
        // 0x801354DC: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_801354E4;
    }
    // 0x801354DC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x801354E0: sw          $t1, -0x446C($at)
    MEM_W(-0X446C, ctx->r1) = ctx->r9;
L_801354E4:
    // 0x801354E4: lw          $t2, -0x43B8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X43B8);
    // 0x801354E8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801354EC: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x801354F0: beq         $v0, $t2, L_801354FC
    if (ctx->r2 == ctx->r10) {
        // 0x801354F4: nop
    
            goto L_801354FC;
    }
    // 0x801354F4: nop

    // 0x801354F8: sw          $t3, -0x43B0($at)
    MEM_W(-0X43B0, ctx->r1) = ctx->r11;
L_801354FC:
    // 0x801354FC: lw          $t4, -0x42FC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X42FC);
    // 0x80135500: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80135504: beq         $v0, $t4, L_80135510
    if (ctx->r2 == ctx->r12) {
        // 0x80135508: nop
    
            goto L_80135510;
    }
    // 0x80135508: nop

    // 0x8013550C: sw          $t5, -0x42F4($at)
    MEM_W(-0X42F4, ctx->r1) = ctx->r13;
L_80135510:
    // 0x80135510: jal         0x801350FC
    // 0x80135514: nop

    mnPlayersVSUpdateGateAll(rdram, ctx);
        goto after_6;
    // 0x80135514: nop

    after_6:
    // 0x80135518: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8013551C: addiu       $a2, $a2, -0x4258
    ctx->r6 = ADD32(ctx->r6, -0X4258);
    // 0x80135520: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80135524: bne         $t6, $zero, L_8013553C
    if (ctx->r14 != 0) {
        // 0x80135528: nop
    
            goto L_8013553C;
    }
    // 0x80135528: nop

    // 0x8013552C: jal         0x801328AC
    // 0x80135530: nop

    mnPlayersVSDestroyTeamSelectAll(rdram, ctx);
        goto after_7;
    // 0x80135530: nop

    after_7:
    // 0x80135534: b           L_80135548
    // 0x80135538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80135548;
    // 0x80135538: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013553C:
    // 0x8013553C: jal         0x80132904
    // 0x80135540: nop

    mnPlayersVSMakeTeamSelectAll(rdram, ctx);
        goto after_8;
    // 0x80135540: nop

    after_8:
    // 0x80135544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80135548:
    // 0x80135548: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8013554C: jr          $ra
    // 0x80135550: nop

    return;
    // 0x80135550: nop

;}
RECOMP_FUNC void ftCommonAttack1CheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014EC78: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014EC7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014EC80: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014EC84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014EC88: lhu         $t6, 0x1BE($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X1BE);
    // 0x8014EC8C: lhu         $t7, 0x1B4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1B4);
    // 0x8014EC90: lw          $a1, 0x9C8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X9C8);
    // 0x8014EC94: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8014EC98: beql        $t8, $zero, L_8014EE88
    if (ctx->r24 == 0) {
        // 0x8014EC9C: lwc1        $f0, 0x150($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
            goto L_8014EE88;
    }
    goto skip_0;
    // 0x8014EC9C: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
    skip_0:
    // 0x8014ECA0: lw          $v0, 0x84C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X84C);
    // 0x8014ECA4: beql        $v0, $zero, L_8014ED40
    if (ctx->r2 == 0) {
        // 0x8014ECA8: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_8014ED40;
    }
    goto skip_1;
    // 0x8014ECA8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_1:
    // 0x8014ECAC: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x8014ECB0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014ECB4: lw          $a0, 0x10($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X10);
    // 0x8014ECB8: bnel        $a0, $at, L_8014ECD8
    if (ctx->r4 != ctx->r1) {
        // 0x8014ECBC: lhu         $t0, 0x1BC($v1)
        ctx->r8 = MEM_HU(ctx->r3, 0X1BC);
            goto L_8014ECD8;
    }
    goto skip_2;
    // 0x8014ECBC: lhu         $t0, 0x1BC($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X1BC);
    skip_2:
    // 0x8014ECC0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014ECC4: jal         0x80146690
    // 0x8014ECC8: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014ECC8: addiu       $a1, $zero, 0x6A
    ctx->r5 = ADD32(0, 0X6A);
    after_0:
    // 0x8014ECCC: b           L_8014EEB0
    // 0x8014ECD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014EEB0;
    // 0x8014ECD0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014ECD4: lhu         $t0, 0x1BC($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X1BC);
L_8014ECD8:
    // 0x8014ECD8: lhu         $t1, 0x1B8($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X1B8);
    // 0x8014ECDC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8014ECE0: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x8014ECE4: beq         $t2, $zero, L_8014ED00
    if (ctx->r10 == 0) {
        // 0x8014ECE8: nop
    
            goto L_8014ED00;
    }
    // 0x8014ECE8: nop

    // 0x8014ECEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014ECF0: jal         0x80146690
    // 0x8014ECF4: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014ECF4: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    after_1:
    // 0x8014ECF8: b           L_8014EEB0
    // 0x8014ECFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014EEB0;
    // 0x8014ECFC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014ED00:
    // 0x8014ED00: beq         $a0, $at, L_8014ED18
    if (ctx->r4 == ctx->r1) {
        // 0x8014ED04: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8014ED18;
    }
    // 0x8014ED04: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014ED08: beq         $a0, $at, L_8014ED2C
    if (ctx->r4 == ctx->r1) {
        // 0x8014ED0C: nop
    
            goto L_8014ED2C;
    }
    // 0x8014ED0C: nop

    // 0x8014ED10: b           L_8014ED40
    // 0x8014ED14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_8014ED40;
    // 0x8014ED14: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8014ED18:
    // 0x8014ED18: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014ED1C: jal         0x80146E94
    // 0x8014ED20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftCommonItemSwingSetStatus(rdram, ctx);
        goto after_2;
    // 0x8014ED20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8014ED24: b           L_8014EEB0
    // 0x8014ED28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014EEB0;
    // 0x8014ED28: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8014ED2C:
    // 0x8014ED2C: jal         0x80147844
    // 0x8014ED30: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonItemShootSetStatus(rdram, ctx);
        goto after_3;
    // 0x8014ED30: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x8014ED34: b           L_8014EEB0
    // 0x8014ED38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014EEB0;
    // 0x8014ED38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014ED3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8014ED40:
    // 0x8014ED40: lwc1        $f6, 0x150($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X150);
    // 0x8014ED44: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8014ED48: nop

    // 0x8014ED4C: bc1tl       L_8014EE68
    if (c1cs) {
        // 0x8014ED50: lw          $t2, 0x100($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X100);
            goto L_8014EE68;
    }
    goto skip_3;
    // 0x8014ED50: lw          $t2, 0x100($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X100);
    skip_3:
    // 0x8014ED54: lw          $v0, 0x154($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X154);
    // 0x8014ED58: addiu       $at, $zero, 0xBE
    ctx->r1 = ADD32(0, 0XBE);
    // 0x8014ED5C: beq         $v0, $at, L_8014ED74
    if (ctx->r2 == ctx->r1) {
        // 0x8014ED60: addiu       $at, $zero, 0xBF
        ctx->r1 = ADD32(0, 0XBF);
            goto L_8014ED74;
    }
    // 0x8014ED60: addiu       $at, $zero, 0xBF
    ctx->r1 = ADD32(0, 0XBF);
    // 0x8014ED64: beql        $v0, $at, L_8014EDF8
    if (ctx->r2 == ctx->r1) {
        // 0x8014ED68: lw          $v0, 0x8($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X8);
            goto L_8014EDF8;
    }
    goto skip_4;
    // 0x8014ED68: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    skip_4:
    // 0x8014ED6C: b           L_8014EE88
    // 0x8014ED70: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
        goto L_8014EE88;
    // 0x8014ED70: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
L_8014ED74:
    // 0x8014ED74: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x8014ED78: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8014ED7C: beq         $v0, $at, L_8014ED8C
    if (ctx->r2 == ctx->r1) {
        // 0x8014ED80: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8014ED8C;
    }
    // 0x8014ED80: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x8014ED84: bnel        $v0, $at, L_8014EDC4
    if (ctx->r2 != ctx->r1) {
        // 0x8014ED88: lw          $t7, 0x100($a1)
        ctx->r15 = MEM_W(ctx->r5, 0X100);
            goto L_8014EDC4;
    }
    goto skip_5;
    // 0x8014ED88: lw          $t7, 0x100($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X100);
    skip_5:
L_8014ED8C:
    // 0x8014ED8C: lw          $t3, 0x100($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X100);
    // 0x8014ED90: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014ED94: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x8014ED98: beql        $t4, $zero, L_8014EE88
    if (ctx->r12 == 0) {
        // 0x8014ED9C: lwc1        $f0, 0x150($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
            goto L_8014EE88;
    }
    goto skip_6;
    // 0x8014ED9C: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
    skip_6:
    // 0x8014EDA0: jal         0x8014EA44
    // 0x8014EDA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftCommonAttack11SetStatus(rdram, ctx);
        goto after_4;
    // 0x8014EDA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_4:
    // 0x8014EDA8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014EDAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014EDB0: lw          $t5, 0x158($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X158);
    // 0x8014EDB4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8014EDB8: b           L_8014EEB0
    // 0x8014EDBC: sw          $t6, 0x158($v1)
    MEM_W(0X158, ctx->r3) = ctx->r14;
        goto L_8014EEB0;
    // 0x8014EDBC: sw          $t6, 0x158($v1)
    MEM_W(0X158, ctx->r3) = ctx->r14;
    // 0x8014EDC0: lw          $t7, 0x100($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X100);
L_8014EDC4:
    // 0x8014EDC4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8014EDC8: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x8014EDCC: bgezl       $t9, L_8014EE88
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8014EDD0: lwc1        $f0, 0x150($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
            goto L_8014EE88;
    }
    goto skip_7;
    // 0x8014EDD0: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
    skip_7:
    // 0x8014EDD4: jal         0x8014EAD8
    // 0x8014EDD8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftCommonAttack12SetStatus(rdram, ctx);
        goto after_5;
    // 0x8014EDD8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_5:
    // 0x8014EDDC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014EDE0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014EDE4: lw          $t0, 0x158($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X158);
    // 0x8014EDE8: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8014EDEC: b           L_8014EEB0
    // 0x8014EDF0: sw          $t1, 0x158($v1)
    MEM_W(0X158, ctx->r3) = ctx->r9;
        goto L_8014EEB0;
    // 0x8014EDF0: sw          $t1, 0x158($v1)
    MEM_W(0X158, ctx->r3) = ctx->r9;
    // 0x8014EDF4: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
L_8014EDF8:
    // 0x8014EDF8: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x8014EDFC: beq         $v0, $zero, L_8014EE54
    if (ctx->r2 == 0) {
        // 0x8014EE00: nop
    
            goto L_8014EE54;
    }
    // 0x8014EE00: nop

    // 0x8014EE04: beq         $v0, $at, L_8014EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8014EE08: addiu       $at, $zero, 0xE
        ctx->r1 = ADD32(0, 0XE);
            goto L_8014EE54;
    }
    // 0x8014EE08: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8014EE0C: beq         $v0, $at, L_8014EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8014EE10: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8014EE54;
    }
    // 0x8014EE10: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8014EE14: beq         $v0, $at, L_8014EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8014EE18: addiu       $at, $zero, 0x12
        ctx->r1 = ADD32(0, 0X12);
            goto L_8014EE54;
    }
    // 0x8014EE18: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8014EE1C: beq         $v0, $at, L_8014EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8014EE20: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_8014EE54;
    }
    // 0x8014EE20: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8014EE24: beq         $v0, $at, L_8014EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8014EE28: addiu       $at, $zero, 0x15
        ctx->r1 = ADD32(0, 0X15);
            goto L_8014EE54;
    }
    // 0x8014EE28: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x8014EE2C: beq         $v0, $at, L_8014EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8014EE30: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8014EE54;
    }
    // 0x8014EE30: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8014EE34: beq         $v0, $at, L_8014EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8014EE38: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_8014EE54;
    }
    // 0x8014EE38: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8014EE3C: beq         $v0, $at, L_8014EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8014EE40: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_8014EE54;
    }
    // 0x8014EE40: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8014EE44: beq         $v0, $at, L_8014EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8014EE48: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_8014EE54;
    }
    // 0x8014EE48: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8014EE4C: bnel        $v0, $at, L_8014EE88
    if (ctx->r2 != ctx->r1) {
        // 0x8014EE50: lwc1        $f0, 0x150($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
            goto L_8014EE88;
    }
    goto skip_8;
    // 0x8014EE50: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
    skip_8:
L_8014EE54:
    // 0x8014EE54: jal         0x8014EBB4
    // 0x8014EE58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonAttack13SetStatus(rdram, ctx);
        goto after_6;
    // 0x8014EE58: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x8014EE5C: b           L_8014EEB0
    // 0x8014EE60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014EEB0;
    // 0x8014EE60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014EE64: lw          $t2, 0x100($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X100);
L_8014EE68:
    // 0x8014EE68: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x8014EE6C: beql        $t3, $zero, L_8014EE88
    if (ctx->r11 == 0) {
        // 0x8014EE70: lwc1        $f0, 0x150($v1)
        ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
            goto L_8014EE88;
    }
    goto skip_9;
    // 0x8014EE70: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
    skip_9:
    // 0x8014EE74: jal         0x8014EA44
    // 0x8014EE78: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonAttack11SetStatus(rdram, ctx);
        goto after_7;
    // 0x8014EE78: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_7:
    // 0x8014EE7C: b           L_8014EEB0
    // 0x8014EE80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014EEB0;
    // 0x8014EE80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014EE84: lwc1        $f0, 0x150($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X150);
L_8014EE88:
    // 0x8014EE88: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8014EE8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8014EE90: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x8014EE94: nop

    // 0x8014EE98: bc1t        L_8014EEB0
    if (c1cs) {
        // 0x8014EE9C: nop
    
            goto L_8014EEB0;
    }
    // 0x8014EE9C: nop

    // 0x8014EEA0: lw          $t4, 0x74($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X74);
    // 0x8014EEA4: lwc1        $f10, 0x78($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0X78);
    // 0x8014EEA8: sub.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8014EEAC: swc1        $f16, 0x150($v1)
    MEM_W(0X150, ctx->r3) = ctx->f16.u32l;
L_8014EEB0:
    // 0x8014EEB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014EEB4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014EEB8: jr          $ra
    // 0x8014EEBC: nop

    return;
    // 0x8014EEBC: nop

;}
RECOMP_FUNC void wpMainVelSetLR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167F68: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80167F6C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80167F70: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80167F74: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80167F78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80167F7C: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80167F80: nop

    // 0x80167F84: bc1fl       L_80167F98
    if (!c1cs) {
        // 0x80167F88: sw          $t7, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r15;
            goto L_80167F98;
    }
    goto skip_0;
    // 0x80167F88: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    skip_0:
    // 0x80167F8C: jr          $ra
    // 0x80167F90: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    return;
    // 0x80167F90: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x80167F94: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
L_80167F98:
    // 0x80167F98: jr          $ra
    // 0x80167F9C: nop

    return;
    // 0x80167F9C: nop

;}
RECOMP_FUNC void func_ovl8_8037AA5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037AA5C: lhu         $t6, 0x4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X4);
    // 0x8037AA60: blez        $t6, L_8037AA78
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8037AA64: nop
    
            goto L_8037AA78;
    }
    // 0x8037AA64: nop

    // 0x8037AA68: lhu         $t7, 0x6($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X6);
    // 0x8037AA6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037AA70: bgtz        $t7, L_8037AA80
    if (SIGNED(ctx->r15) > 0) {
        // 0x8037AA74: nop
    
            goto L_8037AA80;
    }
    // 0x8037AA74: nop

L_8037AA78:
    // 0x8037AA78: jr          $ra
    // 0x8037AA7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8037AA7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037AA80:
    // 0x8037AA80: jr          $ra
    // 0x8037AA84: nop

    return;
    // 0x8037AA84: nop

;}
RECOMP_FUNC void func_ovl8_80382AE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80382AE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80382AE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80382AE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80382AEC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80382AF0: jal         0x803717A0
    // 0x80382AF4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80382AF4: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    after_0:
    // 0x80382AF8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80382AFC: beq         $v0, $zero, L_80382B2C
    if (ctx->r2 == 0) {
        // 0x80382B00: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80382B2C;
    }
    // 0x80382B00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80382B04: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x80382B08: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80382B0C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80382B10: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80382B14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80382B18: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80382B1C: jal         0x80382B44
    // 0x80382B20: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_80382B44(rdram, ctx);
        goto after_1;
    // 0x80382B20: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x80382B24: b           L_80382B30
    // 0x80382B28: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80382B30;
    // 0x80382B28: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80382B2C:
    // 0x80382B2C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80382B30:
    // 0x80382B30: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80382B34: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80382B38: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80382B3C: jr          $ra
    // 0x80382B40: nop

    return;
    // 0x80382B40: nop

;}
RECOMP_FUNC void ftCommonKneeBendCheckButtonTap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F450: lhu         $t6, 0x1BE($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X1BE);
    // 0x8013F454: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013F458: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x8013F45C: beq         $t7, $zero, L_8013F46C
    if (ctx->r15 == 0) {
        // 0x8013F460: nop
    
            goto L_8013F46C;
    }
    // 0x8013F460: nop

    // 0x8013F464: jr          $ra
    // 0x8013F468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8013F468: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013F46C:
    // 0x8013F46C: jr          $ra
    // 0x8013F470: nop

    return;
    // 0x8013F470: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137700: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137704: addiu       $v1, $v1, -0x7774
    ctx->r3 = ADD32(ctx->r3, -0X7774);
    // 0x80137708: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8013770C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137710: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137714: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80137718: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013771C: lw          $t8, -0x7770($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X7770);
    // 0x80137720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137724: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80137728: bne         $t8, $t7, L_80137758
    if (ctx->r24 != ctx->r15) {
        // 0x8013772C: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_80137758;
    }
    // 0x8013772C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80137730: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80137734: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80137738: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013773C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80137740: jal         0x801375D8
    // 0x80137744: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    mnPlayers1PTrainingSetSceneData(rdram, ctx);
        goto after_0;
    // 0x80137744: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_0:
    // 0x80137748: jal         0x80005C74
    // 0x8013774C: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8013774C: nop

    after_1:
    // 0x80137750: b           L_80137840
    // 0x80137754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80137840;
    // 0x80137754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137758:
    // 0x80137758: jal         0x80390B7C
    // 0x8013775C: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_2;
    // 0x8013775C: nop

    after_2:
    // 0x80137760: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137764: bne         $v0, $zero, L_8013777C
    if (ctx->r2 != 0) {
        // 0x80137768: addiu       $v1, $v1, -0x7774
        ctx->r3 = ADD32(ctx->r3, -0X7774);
            goto L_8013777C;
    }
    // 0x80137768: addiu       $v1, $v1, -0x7774
    ctx->r3 = ADD32(ctx->r3, -0X7774);
    // 0x8013776C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80137770: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137774: addiu       $t3, $t2, 0x4650
    ctx->r11 = ADD32(ctx->r10, 0X4650);
    // 0x80137778: sw          $t3, -0x7770($at)
    MEM_W(-0X7770, ctx->r1) = ctx->r11;
L_8013777C:
    // 0x8013777C: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80137780: lw          $t4, -0x779C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X779C);
    // 0x80137784: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137788: addiu       $v1, $v1, -0x77A0
    ctx->r3 = ADD32(ctx->r3, -0X77A0);
    // 0x8013778C: beq         $t4, $zero, L_801377D0
    if (ctx->r12 == 0) {
        // 0x80137790: nop
    
            goto L_801377D0;
    }
    // 0x80137790: nop

    // 0x80137794: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80137798: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8013779C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801377A0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x801377A4: bne         $t6, $zero, L_8013783C
    if (ctx->r14 != 0) {
        // 0x801377A8: sw          $t6, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r14;
            goto L_8013783C;
    }
    // 0x801377A8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801377AC: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x801377B0: addiu       $t9, $zero, 0x15
    ctx->r25 = ADD32(0, 0X15);
    // 0x801377B4: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x801377B8: jal         0x801375D8
    // 0x801377BC: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    mnPlayers1PTrainingSetSceneData(rdram, ctx);
        goto after_3;
    // 0x801377BC: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_3:
    // 0x801377C0: jal         0x80005C74
    // 0x801377C4: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_4;
    // 0x801377C4: nop

    after_4:
    // 0x801377C8: b           L_80137840
    // 0x801377CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80137840;
    // 0x801377CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801377D0:
    // 0x801377D0: jal         0x8039076C
    // 0x801377D4: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_5;
    // 0x801377D4: addiu       $a0, $zero, 0x1000
    ctx->r4 = ADD32(0, 0X1000);
    after_5:
    // 0x801377D8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801377DC: beq         $v0, $zero, L_8013783C
    if (ctx->r2 == 0) {
        // 0x801377E0: addiu       $v1, $v1, -0x7774
        ctx->r3 = ADD32(ctx->r3, -0X7774);
            goto L_8013783C;
    }
    // 0x801377E0: addiu       $v1, $v1, -0x7774
    ctx->r3 = ADD32(ctx->r3, -0X7774);
    // 0x801377E4: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x801377E8: slti        $at, $t0, 0x3D
    ctx->r1 = SIGNED(ctx->r8) < 0X3D ? 1 : 0;
    // 0x801377EC: bnel        $at, $zero, L_80137840
    if (ctx->r1 != 0) {
        // 0x801377F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80137840;
    }
    goto skip_0;
    // 0x801377F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801377F4: jal         0x80137274
    // 0x801377F8: nop

    mnPlayers1PTrainingCheckReady(rdram, ctx);
        goto after_6;
    // 0x801377F8: nop

    after_6:
    // 0x801377FC: beq         $v0, $zero, L_80137834
    if (ctx->r2 == 0) {
        // 0x80137800: nop
    
            goto L_80137834;
    }
    // 0x80137800: nop

    // 0x80137804: jal         0x800269C0
    // 0x80137808: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    func_800269C0_275C0(rdram, ctx);
        goto after_7;
    // 0x80137808: addiu       $a0, $zero, 0x26A
    ctx->r4 = ADD32(0, 0X26A);
    after_7:
    // 0x8013780C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80137810: addiu       $v1, $v1, -0x77A0
    ctx->r3 = ADD32(ctx->r3, -0X77A0);
    // 0x80137814: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x80137818: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x8013781C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80137820: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137824: jal         0x80137638
    // 0x80137828: sw          $t2, -0x779C($at)
    MEM_W(-0X779C, ctx->r1) = ctx->r10;
    mnPlayers1PTrainingPauseSlotProcesses(rdram, ctx);
        goto after_8;
    // 0x80137828: sw          $t2, -0x779C($at)
    MEM_W(-0X779C, ctx->r1) = ctx->r10;
    after_8:
    // 0x8013782C: b           L_80137840
    // 0x80137830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80137840;
    // 0x80137830: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137834:
    // 0x80137834: jal         0x800269C0
    // 0x80137838: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80137838: addiu       $a0, $zero, 0xA5
    ctx->r4 = ADD32(0, 0XA5);
    after_9:
L_8013783C:
    // 0x8013783C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80137840:
    // 0x80137840: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137844: jr          $ra
    // 0x80137848: nop

    return;
    // 0x80137848: nop

;}
RECOMP_FUNC void mvEndingMakeMainCameras(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132630: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132634: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x80132638: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8013263C: addiu       $v0, $v0, 0x7EC0
    ctx->r2 = ADD32(ctx->r2, 0X7EC0);
    // 0x80132640: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80132644: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132648: lui         $t9, 0x2000
    ctx->r25 = S32(0X2000 << 16);
    // 0x8013264C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80132650: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80132654: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132658: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x8013265C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80132660: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80132664: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80132668: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013266C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132670: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80132674: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80132678: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8013267C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132680: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132684: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132688: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013268C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132690: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132694: jal         0x8000B93C
    // 0x80132698: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132698: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013269C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801326A0: sw          $v0, 0x2BD0($at)
    MEM_W(0X2BD0, ctx->r1) = ctx->r2;
    // 0x801326A4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801326A8: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x801326AC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x801326B0: jal         0x80008CF0
    // 0x801326B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_1;
    // 0x801326B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801326B8: lw          $a0, 0x74($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X74);
    // 0x801326BC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x801326C0: jal         0x80008CF0
    // 0x801326C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_2;
    // 0x801326C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801326C8: jal         0x80132590
    // 0x801326CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mvEndingSetupOperatorCamera(rdram, ctx);
        goto after_3;
    // 0x801326CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801326D0: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x801326D4: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x801326D8: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x801326DC: lw          $t2, 0x80($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X80);
    // 0x801326E0: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x801326E4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x801326E8: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x801326EC: sw          $t3, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r11;
    // 0x801326F0: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x801326F4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801326F8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801326FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132700: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80132704: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80132708: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x8013270C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132710: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132714: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x80132718: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8013271C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80132720: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80132724: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80132728: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013272C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132730: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80132734: jal         0x8000B93C
    // 0x80132738: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    gcMakeCameraGObj(rdram, ctx);
        goto after_4;
    // 0x80132738: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_4:
    // 0x8013273C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132740: sw          $v0, 0x2BD4($at)
    MEM_W(0X2BD4, ctx->r1) = ctx->r2;
    // 0x80132744: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132748: jal         0x80132590
    // 0x8013274C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mvEndingSetupOperatorCamera(rdram, ctx);
        goto after_5;
    // 0x8013274C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x80132750: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80132754: lw          $t2, 0x80($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X80);
    // 0x80132758: ori         $t3, $t2, 0x4
    ctx->r11 = ctx->r10 | 0X4;
    // 0x8013275C: sw          $t3, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r11;
    // 0x80132760: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80132764: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80132768: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8013276C: jr          $ra
    // 0x80132770: nop

    return;
    // 0x80132770: nop

;}
RECOMP_FUNC void mpProcessCheckTestLWallCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DA294: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800DA298: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800DA29C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DA2A0: lw          $t6, 0x48($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X48);
    // 0x800DA2A4: sw          $t6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r14;
    // 0x800DA2A8: lw          $s0, 0x0($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X0);
    // 0x800DA2AC: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x800DA2B0: jal         0x800D9510
    // 0x800DA2B4: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    mpProcessResetMultiWallCount(rdram, ctx);
        goto after_0;
    // 0x800DA2B4: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x800DA2B8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x800DA2BC: jal         0x800FC67C
    // 0x800DA2C0: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_1;
    // 0x800DA2C0: lw          $a0, 0x74($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X74);
    after_1:
    // 0x800DA2C4: beql        $v0, $zero, L_800DA2E4
    if (ctx->r2 == 0) {
        // 0x800DA2C8: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_800DA2E4;
    }
    goto skip_0;
    // 0x800DA2C8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    skip_0:
    // 0x800DA2CC: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x800DA2D0: jal         0x800FAA24
    // 0x800DA2D4: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    mpCollisionGetEdgeUnderLLineID(rdram, ctx);
        goto after_2;
    // 0x800DA2D4: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    after_2:
    // 0x800DA2D8: b           L_800DA2E8
    // 0x800DA2DC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
        goto L_800DA2E8;
    // 0x800DA2DC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800DA2E0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800DA2E4:
    // 0x800DA2E4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
L_800DA2E8:
    // 0x800DA2E8: lw          $t1, 0x68($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X68);
    // 0x800DA2EC: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x800DA2F0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800DA2F4: addiu       $v1, $t1, 0x8
    ctx->r3 = ADD32(ctx->r9, 0X8);
    // 0x800DA2F8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800DA2FC: lwc1        $f6, 0xC($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800DA300: addiu       $v0, $t1, 0x38
    ctx->r2 = ADD32(ctx->r9, 0X38);
    // 0x800DA304: lhu         $t2, 0x1398($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X1398);
    // 0x800DA308: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DA30C: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800DA310: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DA314: lwc1        $f16, 0x4($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X4);
    // 0x800DA318: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DA31C: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x800DA320: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800DA324: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA328: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DA32C: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800DA330: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800DA334: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA338: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DA33C: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    // 0x800DA340: lhu         $t3, 0x5C($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X5C);
    // 0x800DA344: beq         $t2, $t3, L_800DA374
    if (ctx->r10 == ctx->r11) {
        // 0x800DA348: addiu       $a0, $sp, 0x4C
        ctx->r4 = ADD32(ctx->r29, 0X4C);
            goto L_800DA374;
    }
    // 0x800DA348: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DA34C: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DA350: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA354: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DA358: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DA35C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DA360: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800DA364: jal         0x800F8974
    // 0x800DA368: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpCollisionCheckLWallLineCollisionDiff(rdram, ctx);
        goto after_3;
    // 0x800DA368: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_3:
    // 0x800DA36C: b           L_800DA39C
    // 0x800DA370: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
        goto L_800DA39C;
    // 0x800DA370: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_800DA374:
    // 0x800DA374: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DA378: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DA37C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA380: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DA384: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DA388: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DA38C: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800DA390: jal         0x800F7F00
    // 0x800DA394: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_4;
    // 0x800DA394: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_4:
    // 0x800DA398: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_800DA39C:
    // 0x800DA39C: beq         $v0, $zero, L_800DA3C4
    if (ctx->r2 == 0) {
        // 0x800DA3A0: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800DA3C4;
    }
    // 0x800DA3A0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DA3A4: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800DA3A8: beql        $a0, $t4, L_800DA3C8
    if (ctx->r4 == ctx->r12) {
        // 0x800DA3AC: lwc1        $f4, 0x0($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
            goto L_800DA3C8;
    }
    goto skip_1;
    // 0x800DA3AC: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    skip_1:
    // 0x800DA3B0: jal         0x800D951C
    // 0x800DA3B4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_5;
    // 0x800DA3B4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_5:
    // 0x800DA3B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800DA3BC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800DA3C0: sw          $t5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r13;
L_800DA3C4:
    // 0x800DA3C4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
L_800DA3C8:
    // 0x800DA3C8: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800DA3CC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800DA3D0: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800DA3D4: lwc1        $f6, 0x4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DA3D8: lwc1        $f8, 0x8($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X8);
    // 0x800DA3DC: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800DA3E0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800DA3E4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DA3E8: lhu         $t8, 0x1398($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X1398);
    // 0x800DA3EC: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DA3F0: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DA3F4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800DA3F8: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA3FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA400: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DA404: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800DA408: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA40C: lwc1        $f4, 0x8($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X8);
    // 0x800DA410: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DA414: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    // 0x800DA418: lhu         $t2, 0x5C($t9)
    ctx->r10 = MEM_HU(ctx->r25, 0X5C);
    // 0x800DA41C: beql        $t8, $t2, L_800DA450
    if (ctx->r24 == ctx->r10) {
        // 0x800DA420: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800DA450;
    }
    goto skip_2;
    // 0x800DA420: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_2:
    // 0x800DA424: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DA428: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DA42C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA430: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DA434: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DA438: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DA43C: jal         0x800F8974
    // 0x800DA440: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpCollisionCheckLWallLineCollisionDiff(rdram, ctx);
        goto after_6;
    // 0x800DA440: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_6:
    // 0x800DA444: b           L_800DA460
    // 0x800DA448: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
        goto L_800DA460;
    // 0x800DA448: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800DA44C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800DA450:
    // 0x800DA450: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DA454: jal         0x800F7F00
    // 0x800DA458: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_7;
    // 0x800DA458: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x800DA45C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_800DA460:
    // 0x800DA460: beq         $v0, $zero, L_800DA488
    if (ctx->r2 == 0) {
        // 0x800DA464: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800DA488;
    }
    // 0x800DA464: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DA468: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800DA46C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800DA470: beql        $a0, $t3, L_800DA48C
    if (ctx->r4 == ctx->r11) {
        // 0x800DA474: lwc1        $f8, 0x0($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
            goto L_800DA48C;
    }
    goto skip_3;
    // 0x800DA474: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    skip_3:
    // 0x800DA478: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    // 0x800DA47C: jal         0x800D951C
    // 0x800DA480: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_8;
    // 0x800DA480: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_8:
    // 0x800DA484: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
L_800DA488:
    // 0x800DA488: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
L_800DA48C:
    // 0x800DA48C: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x800DA490: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800DA494: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800DA498: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800DA49C: lwc1        $f16, 0x0($t5)
    ctx->f16.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800DA4A0: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x800DA4A4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DA4A8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DA4AC: lhu         $t7, 0x1398($t7)
    ctx->r15 = MEM_HU(ctx->r15, 0X1398);
    // 0x800DA4B0: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DA4B4: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DA4B8: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x800DA4BC: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA4C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA4C4: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DA4C8: swc1        $f4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f4.u32l;
    // 0x800DA4CC: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA4D0: lwc1        $f8, 0x0($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800DA4D4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DA4D8: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x800DA4DC: lhu         $t8, 0x5C($t9)
    ctx->r24 = MEM_HU(ctx->r25, 0X5C);
    // 0x800DA4E0: beql        $t7, $t8, L_800DA510
    if (ctx->r15 == ctx->r24) {
        // 0x800DA4E4: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_800DA510;
    }
    goto skip_4;
    // 0x800DA4E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_4:
    // 0x800DA4E8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DA4EC: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DA4F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA4F4: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DA4F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DA4FC: jal         0x800F8974
    // 0x800DA500: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckLWallLineCollisionDiff(rdram, ctx);
        goto after_9;
    // 0x800DA500: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_9:
    // 0x800DA504: b           L_800DA518
    // 0x800DA508: nop

        goto L_800DA518;
    // 0x800DA508: nop

    // 0x800DA50C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_800DA510:
    // 0x800DA510: jal         0x800F7F00
    // 0x800DA514: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_10;
    // 0x800DA514: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_10:
L_800DA518:
    // 0x800DA518: beq         $v0, $zero, L_800DA538
    if (ctx->r2 == 0) {
        // 0x800DA51C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800DA538;
    }
    // 0x800DA51C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DA520: lw          $t2, 0x34($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X34);
    // 0x800DA524: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800DA528: beql        $a0, $t2, L_800DA53C
    if (ctx->r4 == ctx->r10) {
        // 0x800DA52C: lwc1        $f16, 0x0($s0)
        ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
            goto L_800DA53C;
    }
    goto skip_5;
    // 0x800DA52C: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
    skip_5:
    // 0x800DA530: jal         0x800D951C
    // 0x800DA534: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_11;
    // 0x800DA534: sw          $t3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r11;
    after_11:
L_800DA538:
    // 0x800DA538: lwc1        $f16, 0x0($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X0);
L_800DA53C:
    // 0x800DA53C: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x800DA540: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DA544: swc1        $f16, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f16.u32l;
    // 0x800DA548: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA54C: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x800DA550: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DA554: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA558: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DA55C: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DA560: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
    // 0x800DA564: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA568: lwc1        $f10, 0xC($t4)
    ctx->f10.u32l = MEM_W(ctx->r12, 0XC);
    // 0x800DA56C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800DA570: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x800DA574: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA578: lwc1        $f4, 0x4($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X4);
    // 0x800DA57C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DA580: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DA584: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800DA588: jal         0x800F7F00
    // 0x800DA58C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_12;
    // 0x800DA58C: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_12:
    // 0x800DA590: beq         $v0, $zero, L_800DA5B0
    if (ctx->r2 == 0) {
        // 0x800DA594: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800DA5B0;
    }
    // 0x800DA594: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DA598: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800DA59C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DA5A0: beql        $a0, $t5, L_800DA5B4
    if (ctx->r4 == ctx->r13) {
        // 0x800DA5A4: lwc1        $f8, 0x0($s0)
        ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
            goto L_800DA5B4;
    }
    goto skip_6;
    // 0x800DA5A4: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    skip_6:
    // 0x800DA5A8: jal         0x800D951C
    // 0x800DA5AC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_13;
    // 0x800DA5AC: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_13:
L_800DA5B0:
    // 0x800DA5B0: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
L_800DA5B4:
    // 0x800DA5B4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800DA5B8: addiu       $a0, $sp, 0x4C
    ctx->r4 = ADD32(ctx->r29, 0X4C);
    // 0x800DA5BC: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x800DA5C0: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA5C4: lwc1        $f16, 0x0($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800DA5C8: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x800DA5CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DA5D0: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DA5D4: addiu       $a3, $sp, 0x38
    ctx->r7 = ADD32(ctx->r29, 0X38);
    // 0x800DA5D8: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x800DA5DC: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DA5E0: lwc1        $f6, 0xC($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0XC);
    // 0x800DA5E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800DA5E8: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800DA5EC: lwc1        $f10, 0x4($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DA5F0: lwc1        $f16, 0x4($t9)
    ctx->f16.u32l = MEM_W(ctx->r25, 0X4);
    // 0x800DA5F4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800DA5F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800DA5FC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800DA600: jal         0x800F7F00
    // 0x800DA604: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    mpCollisionCheckLWallLineCollisionSame(rdram, ctx);
        goto after_14;
    // 0x800DA604: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_14:
    // 0x800DA608: beq         $v0, $zero, L_800DA628
    if (ctx->r2 == 0) {
        // 0x800DA60C: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800DA628;
    }
    // 0x800DA60C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800DA610: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800DA614: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800DA618: beql        $a0, $t7, L_800DA62C
    if (ctx->r4 == ctx->r15) {
        // 0x800DA61C: lw          $t2, 0x3C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X3C);
            goto L_800DA62C;
    }
    goto skip_7;
    // 0x800DA61C: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    skip_7:
    // 0x800DA620: jal         0x800D951C
    // 0x800DA624: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    mpProcessSetMultiWallLineID(rdram, ctx);
        goto after_15;
    // 0x800DA624: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    after_15:
L_800DA628:
    // 0x800DA628: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
L_800DA62C:
    // 0x800DA62C: lw          $t3, 0x68($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X68);
    // 0x800DA630: beql        $t2, $zero, L_800DA648
    if (ctx->r10 == 0) {
        // 0x800DA634: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800DA648;
    }
    goto skip_8;
    // 0x800DA634: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_8:
    // 0x800DA638: lhu         $t4, 0x56($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X56);
    // 0x800DA63C: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x800DA640: sh          $t5, 0x56($t3)
    MEM_H(0X56, ctx->r11) = ctx->r13;
    // 0x800DA644: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800DA648:
    // 0x800DA648: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800DA64C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DA650: jr          $ra
    // 0x800DA654: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800DA654: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void wpYoshiEggThrowMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C498: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016C49C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C4A0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8016C4A4: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016C4A8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016C4AC: addiu       $a1, $a1, -0x6D20
    ctx->r5 = ADD32(ctx->r5, -0X6D20);
    // 0x8016C4B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8016C4B4: jal         0x801655C8
    // 0x8016C4B8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016C4B8: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8016C4BC: bne         $v0, $zero, L_8016C4CC
    if (ctx->r2 != 0) {
        // 0x8016C4C0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8016C4CC;
    }
    // 0x8016C4C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8016C4C4: b           L_8016C528
    // 0x8016C4C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016C528;
    // 0x8016C4C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016C4CC:
    // 0x8016C4CC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8016C4D0: lui         $t7, 0x8017
    ctx->r15 = S32(0X8017 << 16);
    // 0x8016C4D4: addiu       $t7, $t7, -0x3BBC
    ctx->r15 = ADD32(ctx->r15, -0X3BBC);
    // 0x8016C4D8: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x8016C4DC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8016C4E0: lbu         $t1, 0x26C($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X26C);
    // 0x8016C4E4: sb          $zero, 0x29D($v1)
    MEM_B(0X29D, ctx->r3) = 0;
    // 0x8016C4E8: lb          $t3, 0x29D($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X29D);
    // 0x8016C4EC: lui         $t8, 0x8017
    ctx->r24 = S32(0X8017 << 16);
    // 0x8016C4F0: addiu       $t8, $t8, -0x40B0
    ctx->r24 = ADD32(ctx->r24, -0X40B0);
    // 0x8016C4F4: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x8016C4F8: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x8016C4FC: sw          $t8, 0x298($v1)
    MEM_W(0X298, ctx->r3) = ctx->r24;
    // 0x8016C500: sw          $t9, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r25;
    // 0x8016C504: sw          $zero, 0x100($v1)
    MEM_W(0X100, ctx->r3) = 0;
    // 0x8016C508: sb          $t2, 0x26C($v1)
    MEM_B(0X26C, ctx->r3) = ctx->r10;
    // 0x8016C50C: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x8016C510: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x8016C514: sb          $t3, 0x29C($v1)
    MEM_B(0X29C, ctx->r3) = ctx->r11;
    // 0x8016C518: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C51C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8016C520: lw          $t5, 0x44($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X44);
    // 0x8016C524: sb          $t5, 0x29F($v1)
    MEM_B(0X29F, ctx->r3) = ctx->r13;
L_8016C528:
    // 0x8016C528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C52C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016C530: jr          $ra
    // 0x8016C534: nop

    return;
    // 0x8016C534: nop

;}
RECOMP_FUNC void sc1PIntroVSFighterProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133170: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80133174: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80133178: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8013317C: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80133180: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80133184: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80133188: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8013318C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80133190: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80133194: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80133198: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8013319C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x801331A0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801331A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801331A8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801331AC: lui         $t0, 0xE300
    ctx->r8 = S32(0XE300 << 16);
    // 0x801331B0: ori         $t0, $t0, 0xA01
    ctx->r8 = ctx->r8 | 0XA01;
    // 0x801331B4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801331B8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801331BC: lui         $t1, 0x10
    ctx->r9 = S32(0X10 << 16);
    // 0x801331C0: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x801331C4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801331C8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801331CC: lui         $t3, 0xE200
    ctx->r11 = S32(0XE200 << 16);
    // 0x801331D0: lui         $t4, 0xC19
    ctx->r12 = S32(0XC19 << 16);
    // 0x801331D4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x801331D8: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x801331DC: ori         $t4, $t4, 0x2078
    ctx->r12 = ctx->r12 | 0X2078;
    // 0x801331E0: ori         $t3, $t3, 0x1C
    ctx->r11 = ctx->r11 | 0X1C;
    // 0x801331E4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x801331E8: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x801331EC: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x801331F0: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x801331F4: addiu       $t7, $zero, -0x100
    ctx->r15 = ADD32(0, -0X100);
    // 0x801331F8: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x801331FC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80133200: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133204: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80133208: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013320C: lw          $t8, 0x5C28($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5C28);
    // 0x80133210: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80133214: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80133218: bne         $t8, $at, L_80133324
    if (ctx->r24 != ctx->r1) {
        // 0x8013321C: lw          $t9, 0x2C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X2C);
            goto L_80133324;
    }
    // 0x8013321C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80133220: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
    // 0x80133224: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133228: lw          $v1, 0x5CF8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5CF8);
    // 0x8013322C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80133230: addiu       $t0, $v0, -0x1C
    ctx->r8 = ADD32(ctx->r2, -0X1C);
    // 0x80133234: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80133238: beql        $at, $zero, L_8013328C
    if (ctx->r1 == 0) {
        // 0x8013323C: addiu       $t2, $v0, -0x8
        ctx->r10 = ADD32(ctx->r2, -0X8);
            goto L_8013328C;
    }
    goto skip_0;
    // 0x8013323C: addiu       $t2, $v0, -0x8
    ctx->r10 = ADD32(ctx->r2, -0X8);
    skip_0:
    // 0x80133240: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80133244: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80133248: ori         $a1, $a1, 0xE
    ctx->r5 = ctx->r5 | 0XE;
    // 0x8013324C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133250: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80133254: jal         0x800E6F24
    // 0x80133258: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80133258: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x8013325C: jal         0x8000DF34
    // 0x80133260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x80133260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80133264: jal         0x8000B39C
    // 0x80133268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEndProcessAll(rdram, ctx);
        goto after_2;
    // 0x80133268: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013326C: jal         0x800F293C
    // 0x80133270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDisplayMainProcDisplay(rdram, ctx);
        goto after_3;
    // 0x80133270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80133274: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80133278: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013327C: lw          $v1, 0x5CF8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5CF8);
    // 0x80133280: lw          $v0, 0x8($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X8);
    // 0x80133284: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x80133288: addiu       $t2, $v0, -0x8
    ctx->r10 = ADD32(ctx->r2, -0X8);
L_8013328C:
    // 0x8013328C: slt         $at, $t2, $v1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80133290: beq         $at, $zero, L_801332DC
    if (ctx->r1 == 0) {
        // 0x80133294: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801332DC;
    }
    // 0x80133294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133298: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8013329C: ori         $a1, $a1, 0xE
    ctx->r5 = ctx->r5 | 0XE;
    // 0x801332A0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x801332A4: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801332A8: jal         0x800E6F24
    // 0x801332AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_4;
    // 0x801332AC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x801332B0: jal         0x8000DF34
    // 0x801332B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x801332B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x801332B8: jal         0x8000B39C
    // 0x801332BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEndProcessAll(rdram, ctx);
        goto after_6;
    // 0x801332BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x801332C0: jal         0x800F293C
    // 0x801332C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDisplayMainProcDisplay(rdram, ctx);
        goto after_7;
    // 0x801332C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801332C8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x801332CC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801332D0: lw          $v1, 0x5CF8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X5CF8);
    // 0x801332D4: lw          $v0, 0x8($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X8);
    // 0x801332D8: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_801332DC:
    // 0x801332DC: addiu       $t4, $v0, 0xC
    ctx->r12 = ADD32(ctx->r2, 0XC);
    // 0x801332E0: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x801332E4: beq         $at, $zero, L_8013332C
    if (ctx->r1 == 0) {
        // 0x801332E8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8013332C;
    }
    // 0x801332E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801332EC: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x801332F0: ori         $a1, $a1, 0xE
    ctx->r5 = ctx->r5 | 0XE;
    // 0x801332F4: lui         $a2, 0x4000
    ctx->r6 = S32(0X4000 << 16);
    // 0x801332F8: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x801332FC: jal         0x800E6F24
    // 0x80133300: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_8;
    // 0x80133300: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_8:
    // 0x80133304: jal         0x8000DF34
    // 0x80133308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_9;
    // 0x80133308: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8013330C: jal         0x8000B39C
    // 0x80133310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEndProcessAll(rdram, ctx);
        goto after_10;
    // 0x80133310: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80133314: jal         0x800F293C
    // 0x80133318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDisplayMainProcDisplay(rdram, ctx);
        goto after_11;
    // 0x80133318: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8013331C: b           L_80133330
    // 0x80133320: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
        goto L_80133330;
    // 0x80133320: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80133324:
    // 0x80133324: jal         0x800F293C
    // 0x80133328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftDisplayMainProcDisplay(rdram, ctx);
        goto after_12;
    // 0x80133328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
L_8013332C:
    // 0x8013332C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
L_80133330:
    // 0x80133330: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80133334: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80133338: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8013333C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80133340: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133344: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133348: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8013334C: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80133350: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x80133354: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80133358: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8013335C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133360: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133364: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80133368: lui         $t1, 0x55
    ctx->r9 = S32(0X55 << 16);
    // 0x8013336C: ori         $t1, $t1, 0x2078
    ctx->r9 = ctx->r9 | 0X2078;
    // 0x80133370: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133374: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80133378: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x8013337C: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80133380: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x80133384: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133388: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8013338C: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80133390: jr          $ra
    // 0x80133394: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80133394: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itDogasDisappearSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182CA8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80182CAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182CB0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80182CB4: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x80182CB8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80182CBC: addiu       $a1, $a1, -0x4D0C
    ctx->r5 = ADD32(ctx->r5, -0X4D0C);
    // 0x80182CC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80182CC4: jal         0x80172EC8
    // 0x80182CC8: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80182CC8: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
    after_0:
    // 0x80182CCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182CD0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80182CD4: jr          $ra
    // 0x80182CD8: nop

    return;
    // 0x80182CD8: nop

;}
RECOMP_FUNC void itMapTestAllCollisionFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801737B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801737BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801737C0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801737C4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801737C8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x801737CC: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801737D0: addiu       $a1, $a1, 0x36B4
    ctx->r5 = ADD32(ctx->r5, 0X36B4);
    // 0x801737D4: jal         0x800DA034
    // 0x801737D8: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x801737D8: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    after_0:
    // 0x801737DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801737E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801737E4: jr          $ra
    // 0x801737E8: nop

    return;
    // 0x801737E8: nop

;}
RECOMP_FUNC void grHyruleMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AB20: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010AB24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AB28: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x8010AB2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010AB30: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010AB34: jal         0x80009968
    // 0x8010AB38: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8010AB38: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010AB3C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010AB40: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8010AB44: addiu       $a1, $a1, -0x56E4
    ctx->r5 = ADD32(ctx->r5, -0X56E4);
    // 0x8010AB48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010AB4C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010AB50: jal         0x80008188
    // 0x8010AB54: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8010AB54: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_1:
    // 0x8010AB58: jal         0x8010A9C8
    // 0x8010AB5C: nop

    grHyruleTwisterInitVars(rdram, ctx);
        goto after_2;
    // 0x8010AB5C: nop

    after_2:
    // 0x8010AB60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AB64: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8010AB68: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010AB6C: jr          $ra
    // 0x8010AB70: nop

    return;
    // 0x8010AB70: nop

;}
RECOMP_FUNC void ftPurinSpecialHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801515CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801515D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801515D4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801515D8: jal         0x800DDE84
    // 0x801515DC: addiu       $a1, $a1, 0x1654
    ctx->r5 = ADD32(ctx->r5, 0X1654);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x801515DC: addiu       $a1, $a1, 0x1654
    ctx->r5 = ADD32(ctx->r5, 0X1654);
    after_0:
    // 0x801515E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801515E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801515E8: jr          $ra
    // 0x801515EC: nop

    return;
    // 0x801515EC: nop

;}
RECOMP_FUNC void func_ovl8_80371978(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371978: jr          $ra
    // 0x8037197C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x8037197C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void sc1PIntroSetupFighterFiles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801349F8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801349FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80134A00: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134A04: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x80134A08: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80134A0C: addiu       $t6, $t6, 0x5B00
    ctx->r14 = ADD32(ctx->r14, 0X5B00);
    // 0x80134A10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80134A14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134A18: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80134A1C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80134A20: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80134A24: or          $t9, $s1, $zero
    ctx->r25 = ctx->r17 | 0;
L_80134A28:
    // 0x80134A28: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134A2C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80134A30: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80134A34: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80134A38: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80134A3C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80134A40: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80134A44: bne         $t6, $t0, L_80134A28
    if (ctx->r14 != ctx->r8) {
        // 0x80134A48: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80134A28;
    }
    // 0x80134A48: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80134A4C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134A50: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134A54: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80134A58: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80134A5C: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x80134A60: jal         0x800D786C
    // 0x80134A64: lw          $a0, 0x5CC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CC8);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_0;
    // 0x80134A64: lw          $a0, 0x5CC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CC8);
    after_0:
    // 0x80134A68: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80134A6C: beq         $s0, $at, L_80134AB8
    if (ctx->r16 == ctx->r1) {
        // 0x80134A70: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80134AB8;
    }
    // 0x80134A70: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134A74: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80134A78: beq         $s0, $at, L_80134A90
    if (ctx->r16 == ctx->r1) {
        // 0x80134A7C: addiu       $at, $zero, 0xC
        ctx->r1 = ADD32(0, 0XC);
            goto L_80134A90;
    }
    // 0x80134A7C: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80134A80: beq         $s0, $at, L_80134AD8
    if (ctx->r16 == ctx->r1) {
        // 0x80134A84: addiu       $s3, $zero, 0x1A
        ctx->r19 = ADD32(0, 0X1A);
            goto L_80134AD8;
    }
    // 0x80134A84: addiu       $s3, $zero, 0x1A
    ctx->r19 = ADD32(0, 0X1A);
    // 0x80134A88: b           L_80134B10
    // 0x80134A8C: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
        goto L_80134B10;
    // 0x80134A8C: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
L_80134A90:
    // 0x80134A90: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134A94: jal         0x800D786C
    // 0x80134A98: lw          $a0, 0x5CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CD8);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_1;
    // 0x80134A98: lw          $a0, 0x5CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CD8);
    after_1:
    // 0x80134A9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134AA0: jal         0x800D786C
    // 0x80134AA4: lw          $a0, 0x5CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CE8);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_2;
    // 0x80134AA4: lw          $a0, 0x5CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CE8);
    after_2:
    // 0x80134AA8: jal         0x800D786C
    // 0x80134AAC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_3;
    // 0x80134AAC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80134AB0: b           L_80134B20
    // 0x80134AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80134B20;
    // 0x80134AB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80134AB8:
    // 0x80134AB8: jal         0x800D786C
    // 0x80134ABC: lw          $a0, 0x5CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CD8);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_4;
    // 0x80134ABC: lw          $a0, 0x5CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CD8);
    after_4:
    // 0x80134AC0: jal         0x800D786C
    // 0x80134AC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_5;
    // 0x80134AC4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_5:
    // 0x80134AC8: jal         0x800D786C
    // 0x80134ACC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_6;
    // 0x80134ACC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_6:
    // 0x80134AD0: b           L_80134B20
    // 0x80134AD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80134B20;
    // 0x80134AD4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80134AD8:
    // 0x80134AD8: addiu       $s0, $zero, 0xE
    ctx->r16 = ADD32(0, 0XE);
    // 0x80134ADC: addiu       $s2, $zero, 0x18
    ctx->r18 = ADD32(0, 0X18);
    // 0x80134AE0: addiu       $s1, $zero, 0x12
    ctx->r17 = ADD32(0, 0X12);
L_80134AE4:
    // 0x80134AE4: beql        $s0, $s1, L_80134B00
    if (ctx->r16 == ctx->r17) {
        // 0x80134AE8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80134B00;
    }
    goto skip_0;
    // 0x80134AE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80134AEC: beql        $s0, $s2, L_80134B00
    if (ctx->r16 == ctx->r18) {
        // 0x80134AF0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80134B00;
    }
    goto skip_1;
    // 0x80134AF0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80134AF4: jal         0x800D786C
    // 0x80134AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_7;
    // 0x80134AF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80134AFC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80134B00:
    // 0x80134B00: bne         $s0, $s3, L_80134AE4
    if (ctx->r16 != ctx->r19) {
        // 0x80134B04: nop
    
            goto L_80134AE4;
    }
    // 0x80134B04: nop

    // 0x80134B08: b           L_80134B20
    // 0x80134B0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80134B20;
    // 0x80134B0C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80134B10:
    // 0x80134B10: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x80134B14: jal         0x800D786C
    // 0x80134B18: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_8;
    // 0x80134B18: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    after_8:
    // 0x80134B1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80134B20:
    // 0x80134B20: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80134B24: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80134B28: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80134B2C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80134B30: jr          $ra
    // 0x80134B34: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80134B34: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void sc1PTrainingModeMakeDamageDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E310: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018E314: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8018E318: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018E31C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018E320: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8018E324: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8018E328: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8018E32C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8018E330: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018E334: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018E338: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018E33C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E340: jal         0x80009968
    // 0x8018E344: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018E344: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
    // 0x8018E348: lui         $s4, 0x8019
    ctx->r20 = S32(0X8019 << 16);
    // 0x8018E34C: addiu       $s4, $s4, 0xB58
    ctx->r20 = ADD32(ctx->r20, 0XB58);
    // 0x8018E350: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018E354: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018E358: sw          $v0, 0x3C($s4)
    MEM_W(0X3C, ctx->r20) = ctx->r2;
    // 0x8018E35C: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8018E360: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018E364: addiu       $a1, $a1, -0x1EC8
    ctx->r5 = ADD32(ctx->r5, -0X1EC8);
    // 0x8018E368: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E36C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8018E370: jal         0x80009DF4
    // 0x8018E374: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018E374: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018E378: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018E37C: addiu       $a1, $a1, -0x1E08
    ctx->r5 = ADD32(ctx->r5, -0X1E08);
    // 0x8018E380: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018E384: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E388: jal         0x80008188
    // 0x8018E38C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x8018E38C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_2:
    // 0x8018E390: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8018E394: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018E398: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8018E39C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8018E3A0:
    // 0x8018E3A0: lw          $t7, 0x28($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X28);
    // 0x8018E3A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018E3A8: jal         0x800CCFDC
    // 0x8018E3AC: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8018E3AC: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_3:
    // 0x8018E3B0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8018E3B4: jal         0x8018E300
    // 0x8018E3B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sc1PTrainingModeInitSpriteEnvColors(rdram, ctx);
        goto after_4;
    // 0x8018E3B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x8018E3BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018E3C0: bne         $s0, $s2, L_8018E3A0
    if (ctx->r16 != ctx->r18) {
        // 0x8018E3C4: swc1        $f20, 0x5C($s1)
        MEM_W(0X5C, ctx->r17) = ctx->f20.u32l;
            goto L_8018E3A0;
    }
    // 0x8018E3C4: swc1        $f20, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f20.u32l;
    // 0x8018E3C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018E3CC: jal         0x8018E014
    // 0x8018E3D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sc1PTrainingModeUpdateDamageDisplay(rdram, ctx);
        goto after_5;
    // 0x8018E3D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8018E3D4: lw          $t8, 0x28($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X28);
    // 0x8018E3D8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8018E3DC: jal         0x800CCFDC
    // 0x8018E3E0: lw          $a1, 0x98($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X98);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x8018E3E0: lw          $a1, 0x98($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X98);
    after_6:
    // 0x8018E3E4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8018E3E8: jal         0x8018E300
    // 0x8018E3EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    sc1PTrainingModeInitSpriteEnvColors(rdram, ctx);
        goto after_7;
    // 0x8018E3EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x8018E3F0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018E3F4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018E3F8: swc1        $f20, 0x5C($s1)
    MEM_W(0X5C, ctx->r17) = ctx->f20.u32l;
    // 0x8018E3FC: swc1        $f4, 0x58($s1)
    MEM_W(0X58, ctx->r17) = ctx->f4.u32l;
    // 0x8018E400: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E404: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8018E408: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8018E40C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8018E410: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E414: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8018E418: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018E41C: jr          $ra
    // 0x8018E420: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8018E420: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftCommonDownWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144220: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144224: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144228: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014422C: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80144230: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80144234: bne         $t7, $zero, L_80144244
    if (ctx->r15 != 0) {
        // 0x80144238: sw          $t7, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r15;
            goto L_80144244;
    }
    // 0x80144238: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x8014423C: jal         0x80144580
    // 0x80144240: nop

    ftCommonDownStandSetStatus(rdram, ctx);
        goto after_0;
    // 0x80144240: nop

    after_0:
L_80144244:
    // 0x80144244: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80144248: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014424C: jr          $ra
    // 0x80144250: nop

    return;
    // 0x80144250: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152A6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152A70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152A74: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80152A78: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80152A7C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80152A80: bgtz        $t7, L_80152A90
    if (SIGNED(ctx->r15) > 0) {
        // 0x80152A84: sw          $t7, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r15;
            goto L_80152A90;
    }
    // 0x80152A84: sw          $t7, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r15;
    // 0x80152A88: jal         0x80153654
    // 0x80152A8C: nop

    ftPikachuSpecialAirHiEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x80152A8C: nop

    after_0:
L_80152A90:
    // 0x80152A90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152A94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152A98: jr          $ra
    // 0x80152A9C: nop

    return;
    // 0x80152A9C: nop

;}
RECOMP_FUNC void unref_8000A1C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A1C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000A1CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A1D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000A1D4: jal         0x80007CF4
    // 0x8000A1D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcRemoveGObjFromDLLinkedList(rdram, ctx);
        goto after_0;
    // 0x8000A1D8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000A1DC: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A1E0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8000A1E4: lbu         $t6, 0xD($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XD);
    // 0x8000A1E8: sb          $t6, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r14;
    // 0x8000A1EC: lw          $t7, 0x28($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X28);
    // 0x8000A1F0: jal         0x80007B98
    // 0x8000A1F4: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    gcAppendGObjToDLLinkedList(rdram, ctx);
        goto after_1;
    // 0x8000A1F4: sw          $t7, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->r15;
    after_1:
    // 0x8000A1F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A1FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000A200: jr          $ra
    // 0x8000A204: nop

    return;
    // 0x8000A204: nop

;}
RECOMP_FUNC void itLinkBombDroppedProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80186270: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80186274: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80186278: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8018627C: lhu         $v1, 0x352($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X352);
    // 0x80186280: beq         $v1, $zero, L_80186290
    if (ctx->r3 == 0) {
        // 0x80186284: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80186290;
    }
    // 0x80186284: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80186288: b           L_80186298
    // 0x8018628C: sh          $t6, 0x352($v0)
    MEM_H(0X352, ctx->r2) = ctx->r14;
        goto L_80186298;
    // 0x8018628C: sh          $t6, 0x352($v0)
    MEM_H(0X352, ctx->r2) = ctx->r14;
L_80186290:
    // 0x80186290: jal         0x80185CF0
    // 0x80186294: nop

    itLinkBombFallProcUpdate(rdram, ctx);
        goto after_0;
    // 0x80186294: nop

    after_0:
L_80186298:
    // 0x80186298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018629C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801862A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801862A4: jr          $ra
    // 0x801862A8: nop

    return;
    // 0x801862A8: nop

;}
RECOMP_FUNC void mnSoundTestInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133858: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8013385C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133860: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133864: addiu       $a1, $a1, 0x4330
    ctx->r5 = ADD32(ctx->r5, 0X4330);
    // 0x80133868: addiu       $a0, $a0, 0x4320
    ctx->r4 = ADD32(ctx->r4, 0X4320);
    // 0x8013386C: addiu       $v1, $v1, 0x4310
    ctx->r3 = ADD32(ctx->r3, 0X4310);
    // 0x80133870: addiu       $t6, $zero, 0x7D
    ctx->r14 = ADD32(0, 0X7D);
    // 0x80133874: addiu       $t7, $zero, 0x45
    ctx->r15 = ADD32(0, 0X45);
    // 0x80133878: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x8013387C: lui         $at, 0x41D4
    ctx->r1 = S32(0X41D4 << 16);
    // 0x80133880: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133884: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x80133888: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8013388C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80133890: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x80133894: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80133898: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8013389C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    // 0x801338A0: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x801338A4: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x801338A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338AC: sw          $zero, 0x4308($at)
    MEM_W(0X4308, ctx->r1) = 0;
    // 0x801338B0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338B4: sw          $zero, 0x433C($at)
    MEM_W(0X433C, ctx->r1) = 0;
    // 0x801338B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338BC: sw          $zero, 0x4340($at)
    MEM_W(0X4340, ctx->r1) = 0;
    // 0x801338C0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801338C4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x801338C8: addiu       $a3, $a3, 0x4358
    ctx->r7 = ADD32(ctx->r7, 0X4358);
    // 0x801338CC: addiu       $a2, $a2, 0x4348
    ctx->r6 = ADD32(ctx->r6, 0X4348);
    // 0x801338D0: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x801338D4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x801338D8: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x801338DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801338E0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801338E4: swc1        $f0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f0.u32l;
    // 0x801338E8: swc1        $f0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f0.u32l;
    // 0x801338EC: swc1        $f0, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f0.u32l;
    // 0x801338F0: jr          $ra
    // 0x801338F4: sw          $t9, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r25;
    return;
    // 0x801338F4: sw          $t9, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r25;
;}
RECOMP_FUNC void itManagerSetItemSpawnWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016EB0C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8016EB10: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8016EB14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016EB18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016EB1C: lbu         $v0, 0x1C($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X1C);
    // 0x8016EB20: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8016EB24: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8016EB28: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x8016EB2C: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x8016EB30: addu        $t8, $t8, $v0
    ctx->r24 = ADD32(ctx->r24, ctx->r2);
    // 0x8016EB34: lhu         $t8, -0x6BAC($t8)
    ctx->r24 = MEM_HU(ctx->r24, -0X6BAC);
    // 0x8016EB38: lhu         $t7, -0x6BA0($t7)
    ctx->r15 = MEM_HU(ctx->r15, -0X6BA0);
    // 0x8016EB3C: jal         0x80018994
    // 0x8016EB40: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x8016EB40: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    after_0:
    // 0x8016EB44: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8016EB48: lw          $t9, 0x50E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50E8);
    // 0x8016EB4C: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8016EB50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016EB54: lbu         $t0, 0x1C($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1C);
    // 0x8016EB58: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016EB5C: sll         $t1, $t0, 1
    ctx->r9 = S32(ctx->r8 << 1);
    // 0x8016EB60: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x8016EB64: lhu         $t2, -0x6BAC($t2)
    ctx->r10 = MEM_HU(ctx->r10, -0X6BAC);
    // 0x8016EB68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016EB6C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x8016EB70: jr          $ra
    // 0x8016EB74: sw          $t3, -0x2F60($at)
    MEM_W(-0X2F60, ctx->r1) = ctx->r11;
    return;
    // 0x8016EB74: sw          $t3, -0x2F60($at)
    MEM_W(-0X2F60, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void mvOpeningMarioMakePosedWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DCEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DCF0: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DCF4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DCF8: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DCFC: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018DD00: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DD04: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8018DD08: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DD0C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DD10: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DD14: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DD18: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DD1C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DD20: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DD24: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DD28: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DD2C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DD30: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DD34: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DD38: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DD3C: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DD40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DD44: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DD48: jal         0x8000B93C
    // 0x8018DD4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DD4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DD50: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DD54: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DD58: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DD5C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DD60: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DD64: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DD68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DD6C: lui         $a3, 0x42DC
    ctx->r7 = S32(0X42DC << 16);
    // 0x8018DD70: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DD74: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8018DD78: jal         0x80007080
    // 0x8018DD7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DD7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DD80: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8018DD84: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8018DD88: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x8018DD8C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DD90: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DD94: jr          $ra
    // 0x8018DD98: nop

    return;
    // 0x8018DD98: nop

;}
RECOMP_FUNC void func_ovl8_8037D3DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D3DC: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8037D3E0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037D3E4: addiu       $t6, $t6, -0x1020
    ctx->r14 = ADD32(ctx->r14, -0X1020);
    // 0x8037D3E8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8037D3EC: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8037D3F0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037D3F4: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8037D3F8: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8037D3FC: jr          $ra
    // 0x8037D400: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    return;
    // 0x8037D400: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
;}
RECOMP_FUNC void ftYoshiSpecialHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015ED3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015ED40: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015ED44: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015ED48: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015ED4C: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    // 0x8015ED50: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015ED54: jal         0x800E6F24
    // 0x8015ED58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015ED58: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015ED5C: jal         0x8015ED18
    // 0x8015ED60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftYoshiSpecialHiInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x8015ED60: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015ED64: jal         0x800E0830
    // 0x8015ED68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015ED68: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015ED6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015ED70: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015ED74: jr          $ra
    // 0x8015ED78: nop

    return;
    // 0x8015ED78: nop

;}
RECOMP_FUNC void ftYoshiSpecialNCatchProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E390: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E394: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E398: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E39C: jal         0x8015E33C
    // 0x8015E3A0: addiu       $a1, $a1, -0x1708
    ctx->r5 = ADD32(ctx->r5, -0X1708);
    ftYoshiSpecialNCatchUpdateProcStatus(rdram, ctx);
        goto after_0;
    // 0x8015E3A0: addiu       $a1, $a1, -0x1708
    ctx->r5 = ADD32(ctx->r5, -0X1708);
    after_0:
    // 0x8015E3A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E3A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E3AC: jr          $ra
    // 0x8015E3B0: nop

    return;
    // 0x8015E3B0: nop

;}
RECOMP_FUNC void gcDrawDObjDLLinks(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014068: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8001406C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80014070: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80014074: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80014078: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001407C: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80014080: beq         $a1, $zero, L_800143E8
    if (ctx->r5 == 0) {
        // 0x80014084: sw          $t6, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r14;
            goto L_800143E8;
    }
    // 0x80014084: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80014088: lbu         $t7, 0x54($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X54);
    // 0x8001408C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80014090: bnel        $t7, $zero, L_800143EC
    if (ctx->r15 != 0) {
        // 0x80014094: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800143EC;
    }
    goto skip_0;
    // 0x80014094: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80014098: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8001409C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x800140A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800140A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800140A8: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    // 0x800140AC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800140B0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800140B4: jal         0x80010D70
    // 0x800140B8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x800140B8: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    after_0:
    // 0x800140BC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800140C0: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800140C4: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x800140C8: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800140CC: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x800140D0: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x800140D4: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x800140D8: addu        $a2, $v1, $t6
    ctx->r6 = ADD32(ctx->r3, ctx->r14);
    // 0x800140DC: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
    // 0x800140E0: beq         $t7, $zero, L_800141AC
    if (ctx->r15 == 0) {
        // 0x800140E4: lw          $t0, 0x0($a2)
        ctx->r8 = MEM_W(ctx->r6, 0X0);
            goto L_800141AC;
    }
    // 0x800140E4: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800140E8: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800140EC: lw          $t8, 0x65E4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X65E4);
    // 0x800140F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800140F4: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800140F8: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800140FC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80014100: sw          $t1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r9;
    // 0x80014104: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80014108: jal         0x80012D90
    // 0x8001410C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x8001410C: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_1:
    // 0x80014110: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80014114: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80014118: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x8001411C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80014120: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x80014124: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80014128: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8001412C: addu        $a2, $v1, $t6
    ctx->r6 = ADD32(ctx->r3, ctx->r14);
    // 0x80014130: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80014134: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x80014138: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8001413C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80014140: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80014144: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80014148: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x8001414C: beq         $t4, $zero, L_8001419C
    if (ctx->r12 == 0) {
        // 0x80014150: sw          $t9, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r25;
            goto L_8001419C;
    }
    // 0x80014150: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80014154: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80014158: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001415C: beql        $t6, $at, L_80014174
    if (ctx->r14 == ctx->r1) {
        // 0x80014160: lw          $t8, 0x0($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X0);
            goto L_80014174;
    }
    goto skip_1;
    // 0x80014160: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x80014164: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80014168: beql        $t7, $zero, L_800141A0
    if (ctx->r15 == 0) {
        // 0x8001416C: lui         $t5, 0xD838
        ctx->r13 = S32(0XD838 << 16);
            goto L_800141A0;
    }
    goto skip_2;
    // 0x8001416C: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
    skip_2:
    // 0x80014170: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
L_80014174:
    // 0x80014174: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
    // 0x80014178: ori         $t5, $t5, 0x2
    ctx->r13 = ctx->r13 | 0X2;
    // 0x8001417C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80014180: addu        $a2, $v1, $t9
    ctx->r6 = ADD32(ctx->r3, ctx->r25);
    // 0x80014184: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80014188: addiu       $ra, $zero, 0x40
    ctx->r31 = ADD32(0, 0X40);
    // 0x8001418C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80014190: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80014194: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x80014198: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8001419C:
    // 0x8001419C: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
L_800141A0:
    // 0x800141A0: ori         $t5, $t5, 0x2
    ctx->r13 = ctx->r13 | 0X2;
    // 0x800141A4: b           L_800141BC
    // 0x800141A8: addiu       $ra, $zero, 0x40
    ctx->r31 = ADD32(0, 0X40);
        goto L_800141BC;
    // 0x800141A8: addiu       $ra, $zero, 0x40
    ctx->r31 = ADD32(0, 0X40);
L_800141AC:
    // 0x800141AC: lui         $t5, 0xD838
    ctx->r13 = S32(0XD838 << 16);
    // 0x800141B0: ori         $t5, $t5, 0x2
    ctx->r13 = ctx->r13 | 0X2;
    // 0x800141B4: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x800141B8: addiu       $ra, $zero, 0x40
    ctx->r31 = ADD32(0, 0X40);
L_800141BC:
    // 0x800141BC: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    // 0x800141C0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800141C4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800141C8: beq         $t3, $a1, L_800143D0
    if (ctx->r11 == ctx->r5) {
        // 0x800141CC: lui         $t2, 0xDB06
        ctx->r10 = S32(0XDB06 << 16);
            goto L_800143D0;
    }
    // 0x800141CC: lui         $t2, 0xDB06
    ctx->r10 = S32(0XDB06 << 16);
    // 0x800141D0: ori         $t2, $t2, 0x38
    ctx->r10 = ctx->r10 | 0X38;
    // 0x800141D4: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
L_800141D8:
    // 0x800141D8: beql        $t7, $zero, L_800143C4
    if (ctx->r15 == 0) {
        // 0x800141DC: lw          $a1, 0x8($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X8);
            goto L_800143C4;
    }
    goto skip_3;
    // 0x800141DC: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    skip_3:
    // 0x800141E0: beq         $t1, $t0, L_8001432C
    if (ctx->r9 == ctx->r8) {
        // 0x800141E4: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_8001432C;
    }
    // 0x800141E4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800141E8: subu        $a1, $t0, $t1
    ctx->r5 = SUB32(ctx->r8, ctx->r9);
    // 0x800141EC: andi        $a1, $a1, 0x1F
    ctx->r5 = ctx->r5 & 0X1F;
    // 0x800141F0: beq         $a1, $zero, L_80014240
    if (ctx->r5 == 0) {
        // 0x800141F4: addu        $a0, $a1, $t1
        ctx->r4 = ADD32(ctx->r5, ctx->r9);
            goto L_80014240;
    }
    // 0x800141F4: addu        $a0, $a1, $t1
    ctx->r4 = ADD32(ctx->r5, ctx->r9);
L_800141F8:
    // 0x800141F8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800141FC: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80014200: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80014204: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80014208: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001420C: lw          $t9, -0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X8);
    // 0x80014210: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80014214: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x80014218: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8001421C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80014220: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80014224: addu        $a2, $v1, $t7
    ctx->r6 = ADD32(ctx->r3, ctx->r15);
    // 0x80014228: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8001422C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80014230: bne         $a0, $v0, L_800141F8
    if (ctx->r4 != ctx->r2) {
        // 0x80014234: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_800141F8;
    }
    // 0x80014234: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80014238: beql        $v0, $t0, L_8001432C
    if (ctx->r2 == ctx->r8) {
        // 0x8001423C: lw          $a1, 0x0($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X0);
            goto L_8001432C;
    }
    goto skip_4;
    // 0x8001423C: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    skip_4:
L_80014240:
    // 0x80014240: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80014244: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x80014248: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8001424C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80014250: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80014254: lw          $t7, -0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X20);
    // 0x80014258: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x8001425C: lw          $t6, -0x1C($v0)
    ctx->r14 = MEM_W(ctx->r2, -0X1C);
    // 0x80014260: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x80014264: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80014268: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001426C: addu        $a2, $v1, $t9
    ctx->r6 = ADD32(ctx->r3, ctx->r25);
    // 0x80014270: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80014274: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x80014278: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8001427C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80014280: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80014284: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80014288: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001428C: lw          $t9, -0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X18);
    // 0x80014290: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80014294: lw          $t8, -0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X14);
    // 0x80014298: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8001429C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800142A0: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800142A4: addu        $a2, $v1, $t7
    ctx->r6 = ADD32(ctx->r3, ctx->r15);
    // 0x800142A8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800142AC: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800142B0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800142B4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800142B8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800142BC: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800142C0: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800142C4: lw          $t7, -0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, -0X10);
    // 0x800142C8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800142CC: lw          $t6, -0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, -0XC);
    // 0x800142D0: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
    // 0x800142D4: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800142D8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800142DC: addu        $a2, $v1, $t9
    ctx->r6 = ADD32(ctx->r3, ctx->r25);
    // 0x800142E0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800142E4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800142E8: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x800142EC: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800142F0: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800142F4: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x800142F8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800142FC: lw          $t9, -0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, -0X8);
    // 0x80014300: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80014304: lw          $t8, -0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, -0X4);
    // 0x80014308: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x8001430C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80014310: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80014314: addu        $a2, $v1, $t7
    ctx->r6 = ADD32(ctx->r3, ctx->r15);
    // 0x80014318: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8001431C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80014320: bne         $v0, $t0, L_80014240
    if (ctx->r2 != ctx->r8) {
        // 0x80014324: sw          $t9, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r25;
            goto L_80014240;
    }
    // 0x80014324: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80014328: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
L_8001432C:
    // 0x8001432C: lw          $t6, 0x80($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X80);
    // 0x80014330: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80014334: addu        $a2, $v1, $t7
    ctx->r6 = ADD32(ctx->r3, ctx->r15);
    // 0x80014338: beql        $t6, $zero, L_80014360
    if (ctx->r14 == 0) {
        // 0x8001433C: sll         $t6, $a1, 2
        ctx->r14 = S32(ctx->r5 << 2);
            goto L_80014360;
    }
    goto skip_5;
    // 0x8001433C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    skip_5:
    // 0x80014340: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80014344: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80014348: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8001434C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80014350: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80014354: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80014358: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x8001435C: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
L_80014360:
    // 0x80014360: addu        $a2, $v1, $t6
    ctx->r6 = ADD32(ctx->r3, ctx->r14);
    // 0x80014364: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80014368: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8001436C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80014370: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80014374: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80014378: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x8001437C: beq         $t4, $zero, L_800143C0
    if (ctx->r12 == 0) {
        // 0x80014380: sw          $t9, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r25;
            goto L_800143C0;
    }
    // 0x80014380: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80014384: lw          $t6, 0x14($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14);
    // 0x80014388: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001438C: beql        $t6, $at, L_800143A4
    if (ctx->r14 == ctx->r1) {
        // 0x80014390: lw          $t8, 0x0($a3)
        ctx->r24 = MEM_W(ctx->r7, 0X0);
            goto L_800143A4;
    }
    goto skip_6;
    // 0x80014390: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    skip_6:
    // 0x80014394: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80014398: beql        $t7, $zero, L_800143C4
    if (ctx->r15 == 0) {
        // 0x8001439C: lw          $a1, 0x8($a3)
        ctx->r5 = MEM_W(ctx->r7, 0X8);
            goto L_800143C4;
    }
    goto skip_7;
    // 0x8001439C: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
    skip_7:
    // 0x800143A0: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
L_800143A4:
    // 0x800143A4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800143A8: addu        $a2, $v1, $t9
    ctx->r6 = ADD32(ctx->r3, ctx->r25);
    // 0x800143AC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800143B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800143B4: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800143B8: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x800143BC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800143C0:
    // 0x800143C0: lw          $a1, 0x8($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X8);
L_800143C4:
    // 0x800143C4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x800143C8: bnel        $t3, $a1, L_800141D8
    if (ctx->r11 != ctx->r5) {
        // 0x800143CC: lw          $t7, 0x4($a3)
        ctx->r15 = MEM_W(ctx->r7, 0X4);
            goto L_800141D8;
    }
    goto skip_8;
    // 0x800143CC: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    skip_8:
L_800143D0:
    // 0x800143D0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x800143D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800143D8: beq         $t7, $at, L_800143E8
    if (ctx->r15 == ctx->r1) {
        // 0x800143DC: sll         $t8, $t7, 2
        ctx->r24 = S32(ctx->r15 << 2);
            goto L_800143E8;
    }
    // 0x800143DC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800143E0: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800143E4: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
L_800143E8:
    // 0x800143E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800143EC:
    // 0x800143EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800143F0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800143F4: jr          $ra
    // 0x800143F8: nop

    return;
    // 0x800143F8: nop

;}
RECOMP_FUNC void itMSBombThrownProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801765A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801765A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801765AC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x801765B0: lw          $t6, 0x74($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X74);
    // 0x801765B4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801765B8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x801765BC: lui         $a1, 0x3FC0
    ctx->r5 = S32(0X3FC0 << 16);
    // 0x801765C0: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x801765C4: jal         0x80172558
    // 0x801765C8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x801765C8: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x801765CC: jal         0x801713F4
    // 0x801765D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x801765D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801765D4: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x801765D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801765DC: lw          $t7, 0x10($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X10);
    // 0x801765E0: lwc1        $f4, 0x38($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X38);
    // 0x801765E4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801765E8: swc1        $f4, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f4.u32l;
    // 0x801765EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801765F0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801765F4: jr          $ra
    // 0x801765F8: nop

    return;
    // 0x801765F8: nop

;}
RECOMP_FUNC void func_ovl28_80132FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132FF4: jr          $ra
    // 0x80132FF8: nop

    return;
    // 0x80132FF8: nop

;}
RECOMP_FUNC void ftFoxSpecialAirHiHoldSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BF30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015BF34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BF38: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015BF3C: jal         0x800DEE98
    // 0x8015BF40: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015BF40: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x8015BF44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015BF48: addiu       $t7, $zero, 0x4002
    ctx->r15 = ADD32(0, 0X4002);
    // 0x8015BF4C: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x8015BF50: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015BF54: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015BF58: jal         0x800E6F24
    // 0x8015BF5C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015BF5C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015BF60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015BF64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015BF68: jr          $ra
    // 0x8015BF6C: nop

    return;
    // 0x8015BF6C: nop

;}
RECOMP_FUNC void func_ovl8_80371460(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371460: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    // 0x80371464: sw          $a2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r6;
    // 0x80371468: sw          $a1, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r5;
    // 0x8037146C: jr          $ra
    // 0x80371470: sw          $a0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r4;
    return;
    // 0x80371470: sw          $a0, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r4;
;}
RECOMP_FUNC void scExplainStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E5C0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E5C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E5C8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E5CC: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018E5D0: addiu       $a0, $a0, -0x18D4
    ctx->r4 = ADD32(ctx->r4, -0X18D4);
    // 0x8018E5D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E5D8: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018E5DC: jal         0x80007024
    // 0x8018E5E0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E5E0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018E5E4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E5E8: jal         0x800188E8
    // 0x8018E5EC: addiu       $a0, $a0, -0x18DC
    ctx->r4 = ADD32(ctx->r4, -0X18DC);
    syUtilsSetRandomSeedPtr(rdram, ctx);
        goto after_1;
    // 0x8018E5EC: addiu       $a0, $a0, -0x18DC
    ctx->r4 = ADD32(ctx->r4, -0X18DC);
    after_1:
    // 0x8018E5F0: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018E5F4: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E5F8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E5FC: addiu       $t9, $t9, -0x1400
    ctx->r25 = ADD32(ctx->r25, -0X1400);
    // 0x8018E600: addiu       $t8, $t8, 0x2A00
    ctx->r24 = ADD32(ctx->r24, 0X2A00);
    // 0x8018E604: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018E608: addiu       $a0, $a0, -0x18B8
    ctx->r4 = ADD32(ctx->r4, -0X18B8);
    // 0x8018E60C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018E610: addiu       $t1, $t1, -0x1E60
    ctx->r9 = ADD32(ctx->r9, -0X1E60);
    // 0x8018E614: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x8018E618: jal         0x800A2698
    // 0x8018E61C: sw          $t1, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r9;
    scManagerFuncUpdate(rdram, ctx);
        goto after_2;
    // 0x8018E61C: sw          $t1, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r9;
    after_2:
    // 0x8018E620: jal         0x801157EC
    // 0x8018E624: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_3;
    // 0x8018E624: nop

    after_3:
    // 0x8018E628: jal         0x800188E8
    // 0x8018E62C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syUtilsSetRandomSeedPtr(rdram, ctx);
        goto after_4;
    // 0x8018E62C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8018E630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E634: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E638: jr          $ra
    // 0x8018E63C: nop

    return;
    // 0x8018E63C: nop

;}
RECOMP_FUNC void mvOpeningSamusMakeMotionWindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D614: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x8018D618: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D61C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8018D620: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8018D624: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D628: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D62C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D630: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D634: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D638: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D63C: jal         0x80104BDC
    // 0x8018D640: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_0;
    // 0x8018D640: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018D644: jal         0x80105600
    // 0x8018D648: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_1;
    // 0x8018D648: nop

    after_1:
    // 0x8018D64C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8018D650: lw          $t6, 0x13E4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X13E4);
    // 0x8018D654: addiu       $s2, $zero, 0x25
    ctx->r18 = ADD32(0, 0X25);
    // 0x8018D658: addiu       $s1, $zero, 0x30
    ctx->r17 = ADD32(0, 0X30);
    // 0x8018D65C: lw          $s3, 0x74($t6)
    ctx->r19 = MEM_W(ctx->r14, 0X74);
    // 0x8018D660: beq         $s3, $zero, L_8018D6B8
    if (ctx->r19 == 0) {
        // 0x8018D664: or          $s0, $s3, $zero
        ctx->r16 = ctx->r19 | 0;
            goto L_8018D6B8;
    }
    // 0x8018D664: or          $s0, $s3, $zero
    ctx->r16 = ctx->r19 | 0;
L_8018D668:
    // 0x8018D668: lbu         $a0, 0x56($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X56);
    // 0x8018D66C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D670: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8018D674: blezl       $a0, L_8018D6A8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8018D678: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018D6A8;
    }
    goto skip_0;
    // 0x8018D678: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
L_8018D67C:
    // 0x8018D67C: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x8018D680: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8018D684: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x8018D688: bnel        $s1, $t7, L_8018D69C
    if (ctx->r17 != ctx->r15) {
        // 0x8018D68C: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8018D69C;
    }
    goto skip_1;
    // 0x8018D68C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    skip_1:
    // 0x8018D690: sb          $s2, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r18;
    // 0x8018D694: lbu         $a0, 0x56($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X56);
    // 0x8018D698: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_8018D69C:
    // 0x8018D69C: bne         $at, $zero, L_8018D67C
    if (ctx->r1 != 0) {
        // 0x8018D6A0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8018D67C;
    }
    // 0x8018D6A0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8018D6A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8018D6A8:
    // 0x8018D6A8: jal         0x800C86E8
    // 0x8018D6AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbCommonGetTreeDObjNextFromRoot(rdram, ctx);
        goto after_2;
    // 0x8018D6AC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_2:
    // 0x8018D6B0: bne         $v0, $zero, L_8018D668
    if (ctx->r2 != 0) {
        // 0x8018D6B4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8018D668;
    }
    // 0x8018D6B4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8018D6B8:
    // 0x8018D6B8: jal         0x800FC7A4
    // 0x8018D6BC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_3;
    // 0x8018D6BC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_3:
    // 0x8018D6C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D6C4: beq         $v0, $at, L_8018D6EC
    if (ctx->r2 == ctx->r1) {
        // 0x8018D6C8: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8018D6EC;
    }
    // 0x8018D6C8: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8018D6CC: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D6D0: addiu       $s0, $s0, -0x1DC0
    ctx->r16 = ADD32(ctx->r16, -0X1DC0);
L_8018D6D4:
    // 0x8018D6D4: jal         0x80023624
    // 0x8018D6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_4;
    // 0x8018D6D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8018D6DC: jal         0x800A3040
    // 0x8018D6E0: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_5;
    // 0x8018D6E0: nop

    after_5:
    // 0x8018D6E4: b           L_8018D6D4
    // 0x8018D6E8: nop

        goto L_8018D6D4;
    // 0x8018D6E8: nop

L_8018D6EC:
    // 0x8018D6EC: jal         0x800FC814
    // 0x8018D6F0: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_6;
    // 0x8018D6F0: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    after_6:
    // 0x8018D6F4: addiu       $s0, $sp, 0x9C
    ctx->r16 = ADD32(ctx->r29, 0X9C);
    // 0x8018D6F8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D6FC: jal         0x800FC894
    // 0x8018D700: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_7;
    // 0x8018D700: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    after_7:
    // 0x8018D704: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8018D708: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x8018D70C: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8018D710: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8018D714: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018D718: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018D71C: jal         0x8018D40C
    // 0x8018D720: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    mvOpeningSamusMakeMotionCamera(rdram, ctx);
        goto after_8;
    // 0x8018D720: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_8:
    // 0x8018D724: jal         0x801156E4
    // 0x8018D728: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_9;
    // 0x8018D728: nop

    after_9:
    // 0x8018D72C: jal         0x801653E0
    // 0x8018D730: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_10;
    // 0x8018D730: nop

    after_10:
    // 0x8018D734: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8018D738: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018D73C: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018D740: addiu       $s6, $s6, 0x6DD0
    ctx->r22 = ADD32(ctx->r22, 0X6DD0);
    // 0x8018D744: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D748: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018D74C: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8018D750: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8018D754: addiu       $s4, $sp, 0x4C
    ctx->r20 = ADD32(ctx->r29, 0X4C);
L_8018D758:
    // 0x8018D758: or          $t2, $s6, $zero
    ctx->r10 = ctx->r22 | 0;
    // 0x8018D75C: or          $t3, $s4, $zero
    ctx->r11 = ctx->r20 | 0;
    // 0x8018D760: addiu       $t4, $s6, 0x3C
    ctx->r12 = ADD32(ctx->r22, 0X3C);
L_8018D764:
    // 0x8018D764: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x8018D768: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8018D76C: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
    // 0x8018D770: sw          $t1, -0xC($t3)
    MEM_W(-0XC, ctx->r11) = ctx->r9;
    // 0x8018D774: lw          $t0, -0x8($t2)
    ctx->r8 = MEM_W(ctx->r10, -0X8);
    // 0x8018D778: sw          $t0, -0x8($t3)
    MEM_W(-0X8, ctx->r11) = ctx->r8;
    // 0x8018D77C: lw          $t1, -0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, -0X4);
    // 0x8018D780: bne         $t2, $t4, L_8018D764
    if (ctx->r10 != ctx->r12) {
        // 0x8018D784: sw          $t1, -0x4($t3)
        MEM_W(-0X4, ctx->r11) = ctx->r9;
            goto L_8018D764;
    }
    // 0x8018D784: sw          $t1, -0x4($t3)
    MEM_W(-0X4, ctx->r11) = ctx->r9;
    // 0x8018D788: lw          $t1, 0x0($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X0);
    // 0x8018D78C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8018D790: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x8018D794: sw          $t1, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r9;
    // 0x8018D798: lw          $t5, 0x0($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X0);
    // 0x8018D79C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8018D7A0: addiu       $t8, $t8, 0x5228
    ctx->r24 = ADD32(ctx->r24, 0X5228);
    // 0x8018D7A4: addu        $s0, $t5, $s2
    ctx->r16 = ADD32(ctx->r13, ctx->r18);
    // 0x8018D7A8: lbu         $t6, 0x22($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D7AC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8018D7B0: addu        $s3, $t7, $t8
    ctx->r19 = ADD32(ctx->r15, ctx->r24);
    // 0x8018D7B4: beql        $s7, $t6, L_8018D878
    if (ctx->r23 == ctx->r14) {
        // 0x8018D7B8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D878;
    }
    goto skip_2;
    // 0x8018D7B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_2:
    // 0x8018D7BC: jal         0x800D786C
    // 0x8018D7C0: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_11;
    // 0x8018D7C0: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_11:
    // 0x8018D7C4: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018D7C8: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8018D7CC: lwc1        $f6, 0xA0($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x8018D7D0: addu        $s0, $v0, $s2
    ctx->r16 = ADD32(ctx->r2, ctx->r18);
    // 0x8018D7D4: lbu         $t9, 0x23($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D7D8: lwc1        $f8, 0xA4($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8018D7DC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018D7E0: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x8018D7E4: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x8018D7E8: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8018D7EC: sw          $t9, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r25;
    // 0x8018D7F0: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x8018D7F4: lbu         $t2, 0x24($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X24);
    // 0x8018D7F8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D7FC: sb          $s1, 0x61($sp)
    MEM_B(0X61, ctx->r29) = ctx->r17;
    // 0x8018D800: sb          $t3, 0x62($sp)
    MEM_B(0X62, ctx->r29) = ctx->r11;
    // 0x8018D804: sb          $t2, 0x60($sp)
    MEM_B(0X60, ctx->r29) = ctx->r10;
    // 0x8018D808: lbu         $t0, 0x26($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X26);
    // 0x8018D80C: sb          $t0, 0x63($sp)
    MEM_B(0X63, ctx->r29) = ctx->r8;
    // 0x8018D810: lbu         $t1, 0x21($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X21);
    // 0x8018D814: sb          $t1, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r9;
    // 0x8018D818: lbu         $t5, 0x20($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X20);
    // 0x8018D81C: sb          $t5, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r13;
    // 0x8018D820: lbu         $t6, 0x7($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X7);
    // 0x8018D824: sw          $zero, 0x70($sp)
    MEM_W(0X70, ctx->r29) = 0;
    // 0x8018D828: sb          $t6, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r14;
    // 0x8018D82C: lbu         $t7, 0x22($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D830: sw          $s3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r19;
    // 0x8018D834: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x8018D838: jal         0x800D78B4
    // 0x8018D83C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_12;
    // 0x8018D83C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_12:
    // 0x8018D840: sw          $v0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r2;
    // 0x8018D844: jal         0x800D7F3C
    // 0x8018D848: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_13;
    // 0x8018D848: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
    // 0x8018D84C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D850: sw          $v0, -0x1D80($at)
    MEM_W(-0X1D80, ctx->r1) = ctx->r2;
    // 0x8018D854: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D858: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D85C: jal         0x800E7C4C
    // 0x8018D860: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_14;
    // 0x8018D860: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_14:
    // 0x8018D864: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D868: addiu       $a1, $a1, -0x1EA8
    ctx->r5 = ADD32(ctx->r5, -0X1EA8);
    // 0x8018D86C: jal         0x800E9B30
    // 0x8018D870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetKey(rdram, ctx);
        goto after_15;
    // 0x8018D870: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8018D874: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D878:
    // 0x8018D878: bne         $s1, $fp, L_8018D758
    if (ctx->r17 != ctx->r30) {
        // 0x8018D87C: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018D758;
    }
    // 0x8018D87C: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018D880: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D884: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D888: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D88C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018D890: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018D894: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018D898: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D89C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018D8A0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8018D8A4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8018D8A8: jr          $ra
    // 0x8018D8AC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x8018D8AC: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void ftDonkeySpecialAirNStartSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AFDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015AFE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015AFE4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015AFE8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015AFEC: jal         0x800DEE98
    // 0x8015AFF0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015AFF0: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015AFF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015AFF8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8015AFFC: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    // 0x8015B000: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015B004: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015B008: jal         0x800E6F24
    // 0x8015B00C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015B00C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015B010: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8015B014: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x8015B018: addiu       $t8, $t8, -0x50F0
    ctx->r24 = ADD32(ctx->r24, -0X50F0);
    // 0x8015B01C: sw          $t8, 0x9EC($t9)
    MEM_W(0X9EC, ctx->r25) = ctx->r24;
    // 0x8015B020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B024: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015B028: jr          $ra
    // 0x8015B02C: nop

    return;
    // 0x8015B02C: nop

;}
RECOMP_FUNC void itPippiCommonProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183344: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80183348: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018334C: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80183350: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x80183354: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80183358: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018335C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80183360: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80183364: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80183368: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x8018336C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80183370: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80183374: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80183378: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8018337C: jal         0x80171C10
    // 0x80183380: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    itDisplayCheckItemVisible(rdram, ctx);
        goto after_0;
    // 0x80183380: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80183384: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80183388: beq         $v0, $zero, L_80183474
    if (ctx->r2 == 0) {
        // 0x8018338C: lw          $a1, 0x28($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X28);
            goto L_80183474;
    }
    // 0x8018338C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80183390: lw          $v0, 0x374($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X374);
    // 0x80183394: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x80183398: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x8018339C: beq         $v0, $zero, L_801833B8
    if (ctx->r2 == 0) {
        // 0x801833A0: lui         $t3, 0x55
        ctx->r11 = S32(0X55 << 16);
            goto L_801833B8;
    }
    // 0x801833A0: lui         $t3, 0x55
    ctx->r11 = S32(0X55 << 16);
    // 0x801833A4: lw          $t8, 0x2CC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X2CC);
    // 0x801833A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801833AC: sll         $t0, $t8, 17
    ctx->r8 = S32(ctx->r24 << 17);
    // 0x801833B0: bgez        $t0, L_801833E0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x801833B4: nop
    
            goto L_801833E0;
    }
    // 0x801833B4: nop

L_801833B8:
    // 0x801833B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801833BC: ori         $t3, $t3, 0x3078
    ctx->r11 = ctx->r11 | 0X3078;
    // 0x801833C0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801833C4: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801833C8: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x801833CC: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x801833D0: jal         0x80014038
    // 0x801833D4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_1;
    // 0x801833D4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_1:
    // 0x801833D8: b           L_80183478
    // 0x801833DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80183478;
    // 0x801833DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_801833E0:
    // 0x801833E0: bne         $v0, $at, L_80183424
    if (ctx->r2 != ctx->r1) {
        // 0x801833E4: lui         $t5, 0xE200
        ctx->r13 = S32(0XE200 << 16);
            goto L_80183424;
    }
    // 0x801833E4: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x801833E8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801833EC: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x801833F0: ori         $t6, $t6, 0x3078
    ctx->r14 = ctx->r14 | 0X3078;
    // 0x801833F4: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x801833F8: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x801833FC: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x80183400: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80183404: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80183408: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8018340C: jal         0x80014038
    // 0x80183410: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_2;
    // 0x80183410: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80183414: jal         0x801719AC
    // 0x80183418: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    itDisplayMapCollisions(rdram, ctx);
        goto after_3;
    // 0x80183418: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x8018341C: b           L_80183478
    // 0x80183420: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80183478;
    // 0x80183420: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80183424:
    // 0x80183424: lw          $t7, 0x248($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X248);
    // 0x80183428: bne         $t7, $zero, L_8018346C
    if (ctx->r15 != 0) {
        // 0x8018342C: nop
    
            goto L_8018346C;
    }
    // 0x8018342C: nop

    // 0x80183430: lw          $t8, 0x10C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10C);
    // 0x80183434: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x80183438: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x8018343C: bne         $t8, $zero, L_8018346C
    if (ctx->r24 != 0) {
        // 0x80183440: lui         $t1, 0x55
        ctx->r9 = S32(0X55 << 16);
            goto L_8018346C;
    }
    // 0x80183440: lui         $t1, 0x55
    ctx->r9 = S32(0X55 << 16);
    // 0x80183444: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80183448: ori         $t1, $t1, 0x3078
    ctx->r9 = ctx->r9 | 0X3078;
    // 0x8018344C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80183450: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80183454: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80183458: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8018345C: jal         0x80014038
    // 0x80183460: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_4;
    // 0x80183460: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    after_4:
    // 0x80183464: b           L_80183478
    // 0x80183468: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80183478;
    // 0x80183468: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_8018346C:
    // 0x8018346C: jal         0x80171410
    // 0x80183470: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayHitCollisions(rdram, ctx);
        goto after_5;
    // 0x80183470: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
L_80183474:
    // 0x80183474: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80183478:
    // 0x80183478: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x8018347C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x80183480: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x80183484: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80183488: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8018348C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80183490: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80183494: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80183498: jr          $ra
    // 0x8018349C: nop

    return;
    // 0x8018349C: nop

;}
RECOMP_FUNC void mnCharactersAdvanceTrack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132984: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132988: addiu       $v0, $v0, 0x66FC
    ctx->r2 = ADD32(ctx->r2, 0X66FC);
    // 0x8013298C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80132990: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132994: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80132998: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8013299C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801329A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801329A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801329A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801329AC: lw          $a1, 0x66C4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X66C4);
    // 0x801329B0: jal         0x8013286C
    // 0x801329B4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    mnCharactersSetMotion(rdram, ctx);
        goto after_0;
    // 0x801329B4: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    after_0:
    // 0x801329B8: addiu       $t8, $sp, 0x1C
    ctx->r24 = ADD32(ctx->r29, 0X1C);
    // 0x801329BC: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x801329C0: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x801329C4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x801329C8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x801329CC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801329D0: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x801329D4: sw          $t0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r8;
    // 0x801329D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801329DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801329E0: jr          $ra
    // 0x801329E4: nop

    return;
    // 0x801329E4: nop

;}
RECOMP_FUNC void func_ovl8_80376848(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376848: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8037684C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80376850: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80376854: lw          $v1, 0x14($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X14);
    // 0x80376858: lui         $at, 0x4246
    ctx->r1 = S32(0X4246 << 16);
    // 0x8037685C: ori         $at, $at, 0x4857
    ctx->r1 = ctx->r1 | 0X4857;
    // 0x80376860: beq         $v1, $at, L_80376880
    if (ctx->r3 == ctx->r1) {
        // 0x80376864: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80376880;
    }
    // 0x80376864: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80376868: lui         $at, 0x4246
    ctx->r1 = S32(0X4246 << 16);
    // 0x8037686C: ori         $at, $at, 0x574E
    ctx->r1 = ctx->r1 | 0X574E;
    // 0x80376870: beql        $v1, $at, L_80376884
    if (ctx->r3 == ctx->r1) {
        // 0x80376874: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_80376884;
    }
    goto skip_0;
    // 0x80376874: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    skip_0:
    // 0x80376878: b           L_80376884
    // 0x8037687C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_80376884;
    // 0x8037687C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80376880:
    // 0x80376880: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80376884:
    // 0x80376884: addiu       $a0, $zero, 0xB8
    ctx->r4 = ADD32(0, 0XB8);
    // 0x80376888: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x8037688C: jal         0x803717A0
    // 0x80376890: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80376890: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80376894: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80376898: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8037689C: beq         $v0, $zero, L_803768C8
    if (ctx->r2 == 0) {
        // 0x803768A0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_803768C8;
    }
    // 0x803768A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803768A4: lw          $t6, 0x24($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X24);
    // 0x803768A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x803768AC: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x803768B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803768B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803768B8: jal         0x80376530
    // 0x803768BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_80376530(rdram, ctx);
        goto after_1;
    // 0x803768BC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x803768C0: b           L_803768CC
    // 0x803768C4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_803768CC;
    // 0x803768C4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_803768C8:
    // 0x803768C8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803768CC:
    // 0x803768CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803768D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803768D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x803768D8: jr          $ra
    // 0x803768DC: nop

    return;
    // 0x803768DC: nop

;}
RECOMP_FUNC void ftCommonCatchCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149CE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80149CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149CE8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80149CEC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80149CF0: lw          $t6, 0x9C8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X9C8);
    // 0x80149CF4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80149CF8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80149CFC: jal         0x80146A8C
    // 0x80149D00: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    ftCommonLightThrowCheckItemTypeThrow(rdram, ctx);
        goto after_0;
    // 0x80149D00: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    after_0:
    // 0x80149D04: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80149D08: beq         $v0, $zero, L_80149D20
    if (ctx->r2 == 0) {
        // 0x80149D0C: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80149D20;
    }
    // 0x80149D0C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80149D10: jal         0x801466EC
    // 0x80149D14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftCommonLightThrowDecideSetStatus(rdram, ctx);
        goto after_1;
    // 0x80149D14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80149D18: b           L_80149D70
    // 0x80149D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80149D70;
    // 0x80149D1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149D20:
    // 0x80149D20: lhu         $t7, 0x1BC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1BC);
    // 0x80149D24: lhu         $t8, 0x1B8($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X1B8);
    // 0x80149D28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80149D2C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80149D30: beq         $t9, $zero, L_80149D70
    if (ctx->r25 == 0) {
        // 0x80149D34: nop
    
            goto L_80149D70;
    }
    // 0x80149D34: nop

    // 0x80149D38: lhu         $t0, 0x1BE($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X1BE);
    // 0x80149D3C: lhu         $t1, 0x1B4($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X1B4);
    // 0x80149D40: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80149D44: and         $t2, $t0, $t1
    ctx->r10 = ctx->r8 & ctx->r9;
    // 0x80149D48: beq         $t2, $zero, L_80149D70
    if (ctx->r10 == 0) {
        // 0x80149D4C: nop
    
            goto L_80149D70;
    }
    // 0x80149D4C: nop

    // 0x80149D50: lw          $t4, 0x100($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X100);
    // 0x80149D54: sll         $t6, $t4, 20
    ctx->r14 = S32(ctx->r12 << 20);
    // 0x80149D58: bgez        $t6, L_80149D70
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80149D5C: nop
    
            goto L_80149D70;
    }
    // 0x80149D5C: nop

    // 0x80149D60: jal         0x80149BA8
    // 0x80149D64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    ftCommonCatchSetStatus(rdram, ctx);
        goto after_2;
    // 0x80149D64: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80149D68: b           L_80149D70
    // 0x80149D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80149D70;
    // 0x80149D6C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149D70:
    // 0x80149D70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149D74: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80149D78: jr          $ra
    // 0x80149D7C: nop

    return;
    // 0x80149D7C: nop

;}
RECOMP_FUNC void ftCommonLiftTurnProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801461A8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801461AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801461B0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801461B4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801461B8: jal         0x80146130
    // 0x801461BC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftCommonLiftTurnUpdateModelYaw(rdram, ctx);
        goto after_0;
    // 0x801461BC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x801461C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x801461C4: lw          $t7, 0xB18($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XB18);
    // 0x801461C8: bnel        $t7, $zero, L_801461DC
    if (ctx->r15 != 0) {
        // 0x801461CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801461DC;
    }
    goto skip_0;
    // 0x801461CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801461D0: jal         0x801460E8
    // 0x801461D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonLiftWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x801461D4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801461D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801461DC:
    // 0x801461DC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801461E0: jr          $ra
    // 0x801461E4: nop

    return;
    // 0x801461E4: nop

;}
RECOMP_FUNC void func_ovl8_80385408(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385408: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038540C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385410: jal         0x803725DC
    // 0x80385414: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    func_ovl8_803725DC(rdram, ctx);
        goto after_0;
    // 0x80385414: addiu       $a0, $a0, 0x4C
    ctx->r4 = ADD32(ctx->r4, 0X4C);
    after_0:
    // 0x80385418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038541C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80385420: jr          $ra
    // 0x80385424: nop

    return;
    // 0x80385424: nop

;}
RECOMP_FUNC void ftCommonDokanWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142424: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80142428: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014242C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80142430: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80142434: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80142438: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014243C: lw          $t7, 0xB38($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB38);
    // 0x80142440: lw          $a2, 0xB20($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XB20);
    // 0x80142444: lw          $a3, 0xB2C($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XB2C);
    // 0x80142448: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8014244C: lwc1        $f12, -0x3EDC($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3EDC);
    // 0x80142450: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80142454: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80142458: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8014245C: jal         0x8000CA28
    // 0x80142460: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    gcGetInterpValueCubic(rdram, ctx);
        goto after_0;
    // 0x80142460: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80142464: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80142468: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8014246C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80142470: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x80142474: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80142478: swc1        $f0, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f0.u32l;
    // 0x8014247C: lw          $t0, 0xB38($v0)
    ctx->r8 = MEM_W(ctx->r2, 0XB38);
    // 0x80142480: lw          $a3, 0xB30($v0)
    ctx->r7 = MEM_W(ctx->r2, 0XB30);
    // 0x80142484: lw          $a2, 0xB24($v0)
    ctx->r6 = MEM_W(ctx->r2, 0XB24);
    // 0x80142488: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x8014248C: lwc1        $f12, -0x3ED8($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3ED8);
    // 0x80142490: swc1        $f2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f2.u32l;
    // 0x80142494: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x80142498: jal         0x8000CA28
    // 0x8014249C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    gcGetInterpValueCubic(rdram, ctx);
        goto after_1;
    // 0x8014249C: cvt.s.w     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    ctx->f14.fl = CVT_S_W(ctx->f6.u32l);
    after_1:
    // 0x801424A0: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x801424A4: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x801424A8: swc1        $f0, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f0.u32l;
    // 0x801424AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801424B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801424B4: jr          $ra
    // 0x801424B8: nop

    return;
    // 0x801424B8: nop

;}
RECOMP_FUNC void ftLinkSpecialNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801639CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801639D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801639D4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801639D8: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801639DC: addiu       $t6, $t6, 0x3850
    ctx->r14 = ADD32(ctx->r14, 0X3850);
    // 0x801639E0: lw          $t7, 0xADC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XADC);
    // 0x801639E4: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x801639E8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801639EC: beq         $t7, $zero, L_80163A24
    if (ctx->r15 == 0) {
        // 0x801639F0: sw          $t6, 0xA0C($v0)
        MEM_W(0XA0C, ctx->r2) = ctx->r14;
            goto L_80163A24;
    }
    // 0x801639F0: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x801639F4: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x801639F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801639FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163A00: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80163A04: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80163A08: jal         0x800E6F24
    // 0x80163A0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80163A0C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80163A10: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80163A14: lbu         $t9, 0x192($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X192);
    // 0x80163A18: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x80163A1C: b           L_80163A34
    // 0x80163A20: sb          $t0, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r8;
        goto L_80163A34;
    // 0x80163A20: sb          $t0, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r8;
L_80163A24:
    // 0x80163A24: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163A28: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80163A2C: jal         0x800E6F24
    // 0x80163A30: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80163A30: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_1:
L_80163A34:
    // 0x80163A34: jal         0x800E0830
    // 0x80163A38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80163A38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80163A3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163A40: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80163A44: jr          $ra
    // 0x80163A48: nop

    return;
    // 0x80163A48: nop

;}
RECOMP_FUNC void grWallpaperResumeProcessAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104D30: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80104D34: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80104D38: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80104D3C: lw          $s0, 0x6724($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6724);
    // 0x80104D40: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80104D44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80104D48: beq         $s0, $zero, L_80104D70
    if (ctx->r16 == 0) {
        // 0x80104D4C: addiu       $s1, $zero, 0x3F0
        ctx->r17 = ADD32(0, 0X3F0);
            goto L_80104D70;
    }
    // 0x80104D4C: addiu       $s1, $zero, 0x3F0
    ctx->r17 = ADD32(0, 0X3F0);
    // 0x80104D50: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_80104D54:
    // 0x80104D54: bnel        $s1, $t6, L_80104D68
    if (ctx->r17 != ctx->r14) {
        // 0x80104D58: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80104D68;
    }
    goto skip_0;
    // 0x80104D58: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x80104D5C: jal         0x8000B2B8
    // 0x80104D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcResumeGObjProcessAll(rdram, ctx);
        goto after_0;
    // 0x80104D60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80104D64: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80104D68:
    // 0x80104D68: bnel        $s0, $zero, L_80104D54
    if (ctx->r16 != 0) {
        // 0x80104D6C: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_80104D54;
    }
    goto skip_1;
    // 0x80104D6C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_1:
L_80104D70:
    // 0x80104D70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80104D74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80104D78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80104D7C: jr          $ra
    // 0x80104D80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80104D80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}

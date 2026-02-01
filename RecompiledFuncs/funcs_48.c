#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mvOpeningYoshiMakePosedFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DC30: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DC34: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DC38: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DC3C: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DC40: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018DC44: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DC48: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8018DC4C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DC50: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DC54: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DC58: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DC5C: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8018DC60: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8018DC64: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DC68: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DC6C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DC70: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DC74: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DC78: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DC7C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DC80: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DC84: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DC88: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DC8C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DC90: jal         0x8000B93C
    // 0x8018DC94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DC94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DC98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8018DC9C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DCA0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DCA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DCA8: lui         $a1, 0x4120
    ctx->r5 = S32(0X4120 << 16);
    // 0x8018DCAC: lui         $a2, 0x4316
    ctx->r6 = S32(0X4316 << 16);
    // 0x8018DCB0: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DCB4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DCB8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8018DCBC: jal         0x80007080
    // 0x8018DCC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DCC0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DCC4: lui         $at, 0x4070
    ctx->r1 = S32(0X4070 << 16);
    // 0x8018DCC8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8018DCCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8018DCD0: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018DCD4: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x8018DCD8: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8018DCDC: lw          $t4, -0x1BBC($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1BBC);
    // 0x8018DCE0: addiu       $t5, $t5, 0xF0
    ctx->r13 = ADD32(ctx->r13, 0XF0);
    // 0x8018DCE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018DCE8: jal         0x8000FA3C
    // 0x8018DCEC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8018DCEC: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x8018DCF0: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8018DCF4: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8018DCF8: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8018DCFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DD00: jal         0x80008188
    // 0x8018DD04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018DD04: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018DD08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DD0C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DD10: jr          $ra
    // 0x8018DD14: nop

    return;
    // 0x8018DD14: nop

;}
RECOMP_FUNC void ftMainPlayAnimEventsForward(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0858: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E085C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E0860: jal         0x800E07D4
    // 0x800E0864: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftMainPlayAnim(rdram, ctx);
        goto after_0;
    // 0x800E0864: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E0868: jal         0x800E0478
    // 0x800E086C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftMainUpdateMotionEventsForward(rdram, ctx);
        goto after_1;
    // 0x800E086C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x800E0870: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E0874: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E0878: jr          $ra
    // 0x800E087C: nop

    return;
    // 0x800E087C: nop

;}
RECOMP_FUNC void grYamabukiGateAddAnimOffset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AE94: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010AE98: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8010AE9C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8010AEA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010AEA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010AEA8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8010AEAC: lw          $a0, 0xC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XC);
    // 0x8010AEB0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8010AEB4: jal         0x8000BD8C
    // 0x8010AEB8: addu        $a1, $t6, $a3
    ctx->r5 = ADD32(ctx->r14, ctx->r7);
    gcAddAnimJointAll(rdram, ctx);
        goto after_0;
    // 0x8010AEB8: addu        $a1, $t6, $a3
    ctx->r5 = ADD32(ctx->r14, ctx->r7);
    after_0:
    // 0x8010AEBC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010AEC0: jal         0x8000DF34
    // 0x8010AEC4: lw          $a0, 0x13FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13FC);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x8010AEC4: lw          $a0, 0x13FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13FC);
    after_1:
    // 0x8010AEC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010AECC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010AED0: jr          $ra
    // 0x8010AED4: nop

    return;
    // 0x8010AED4: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151C5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80151C60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151C64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80151C68: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80151C6C: jal         0x800DEE98
    // 0x80151C70: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80151C70: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151C74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80151C78: addiu       $t7, $zero, 0x96
    ctx->r15 = ADD32(0, 0X96);
    // 0x80151C7C: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    // 0x80151C80: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80151C84: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80151C88: jal         0x800E6F24
    // 0x80151C8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151C8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80151C90: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80151C94: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80151C98: addiu       $t8, $t8, 0x1B50
    ctx->r24 = ADD32(ctx->r24, 0X1B50);
    // 0x80151C9C: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x80151CA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151CA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80151CA8: jr          $ra
    // 0x80151CAC: nop

    return;
    // 0x80151CAC: nop

;}
RECOMP_FUNC void sc1PGameFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80190F8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80190F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80190F94: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80190F98: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x80190F9C: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80190FA0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80190FA4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80190FA8: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80190FAC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80190FB0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80190FB4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80190FB8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80190FBC: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x80190FC0: jal         0x800FCB70
    // 0x80190FC4: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x80190FC4: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x80190FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80190FCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80190FD0: jr          $ra
    // 0x80190FD4: nop

    return;
    // 0x80190FD4: nop

;}
RECOMP_FUNC void mpCollisionGetLineIDsTypeCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FC900: blez        $a1, L_800FC9C0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800FC904: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800FC9C0;
    }
    // 0x800FC904: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800FC908: andi        $t2, $a1, 0x3
    ctx->r10 = ctx->r5 & 0X3;
    // 0x800FC90C: beq         $t2, $zero, L_800FC954
    if (ctx->r10 == 0) {
        // 0x800FC910: or          $t1, $t2, $zero
        ctx->r9 = ctx->r10 | 0;
            goto L_800FC954;
    }
    // 0x800FC910: or          $t1, $t2, $zero
    ctx->r9 = ctx->r10 | 0;
    // 0x800FC914: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FC918: addiu       $t8, $t8, 0x1348
    ctx->r24 = ADD32(ctx->r24, 0X1348);
    // 0x800FC91C: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800FC920: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x800FC924: addu        $a3, $t7, $t8
    ctx->r7 = ADD32(ctx->r15, ctx->r24);
    // 0x800FC928: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x800FC92C: sll         $t0, $zero, 1
    ctx->r8 = S32(0 << 1);
L_800FC930:
    // 0x800FC930: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x800FC934: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800FC938: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800FC93C: addu        $t3, $t9, $t0
    ctx->r11 = ADD32(ctx->r25, ctx->r8);
    // 0x800FC940: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800FC944: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800FC948: bne         $t1, $v0, L_800FC930
    if (ctx->r9 != ctx->r2) {
        // 0x800FC94C: sw          $t4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r12;
            goto L_800FC930;
    }
    // 0x800FC94C: sw          $t4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r12;
    // 0x800FC950: beq         $v0, $a1, L_800FC9C0
    if (ctx->r2 == ctx->r5) {
        // 0x800FC954: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800FC9C0;
    }
L_800FC954:
    // 0x800FC954: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800FC958: addiu       $t7, $t7, 0x1348
    ctx->r15 = ADD32(ctx->r15, 0X1348);
    // 0x800FC95C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800FC960: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800FC964: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x800FC968: addu        $v1, $a2, $t5
    ctx->r3 = ADD32(ctx->r6, ctx->r13);
    // 0x800FC96C: sll         $t0, $v0, 1
    ctx->r8 = S32(ctx->r2 << 1);
    // 0x800FC970: sll         $t1, $a1, 1
    ctx->r9 = S32(ctx->r5 << 1);
L_800FC974:
    // 0x800FC974: lw          $t8, 0x4($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X4);
    // 0x800FC978: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800FC97C: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800FC980: lhu         $t3, 0x0($t9)
    ctx->r11 = MEM_HU(ctx->r25, 0X0);
    // 0x800FC984: sw          $t3, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r11;
    // 0x800FC988: lw          $t4, 0x4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4);
    // 0x800FC98C: addu        $t5, $t4, $t0
    ctx->r13 = ADD32(ctx->r12, ctx->r8);
    // 0x800FC990: lhu         $t6, 0x2($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X2);
    // 0x800FC994: sw          $t6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r14;
    // 0x800FC998: lw          $t7, 0x4($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4);
    // 0x800FC99C: addu        $t8, $t7, $t0
    ctx->r24 = ADD32(ctx->r15, ctx->r8);
    // 0x800FC9A0: lhu         $t9, 0x4($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X4);
    // 0x800FC9A4: sw          $t9, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r25;
    // 0x800FC9A8: lw          $t3, 0x4($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4);
    // 0x800FC9AC: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x800FC9B0: lhu         $t5, 0x6($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X6);
    // 0x800FC9B4: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x800FC9B8: bne         $t0, $t1, L_800FC974
    if (ctx->r8 != ctx->r9) {
        // 0x800FC9BC: sw          $t5, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r13;
            goto L_800FC974;
    }
    // 0x800FC9BC: sw          $t5, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r13;
L_800FC9C0:
    // 0x800FC9C0: jr          $ra
    // 0x800FC9C4: nop

    return;
    // 0x800FC9C4: nop

;}
RECOMP_FUNC void mnVSResultsGetKOs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135670: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80135674: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80135678: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x8013567C: lw          $v1, -0x6480($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6480);
    // 0x80135680: slti        $at, $v1, 0x3E8
    ctx->r1 = SIGNED(ctx->r3) < 0X3E8 ? 1 : 0;
    // 0x80135684: bne         $at, $zero, L_80135694
    if (ctx->r1 != 0) {
        // 0x80135688: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80135694;
    }
    // 0x80135688: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8013568C: jr          $ra
    // 0x80135690: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
    return;
    // 0x80135690: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
L_80135694:
    // 0x80135694: jr          $ra
    // 0x80135698: nop

    return;
    // 0x80135698: nop

;}
RECOMP_FUNC void gcAddAObjForMObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008F44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80008F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008F4C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80008F50: jal         0x80007E04
    // 0x80008F54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    gcGetAObjSetNextAlloc(rdram, ctx);
        goto after_0;
    // 0x80008F54: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80008F58: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x80008F5C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80008F60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80008F64: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80008F68: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80008F6C: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x80008F70: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80008F74: sb          $t6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r14;
    // 0x80008F78: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80008F7C: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x80008F80: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x80008F84: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80008F88: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x80008F8C: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x80008F90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80008F94: jal         0x80007E90
    // 0x80008F98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    gcAppendAObjToMObj(rdram, ctx);
        goto after_1;
    // 0x80008F98: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80008F9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008FA0: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80008FA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80008FA8: jr          $ra
    // 0x80008FAC: nop

    return;
    // 0x80008FAC: nop

;}
RECOMP_FUNC void ftDonkeySpecialLwStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B9F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015B9F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B9F8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015B9FC: jal         0x800D9480
    // 0x8015BA00: addiu       $a1, $a1, -0x455C
    ctx->r5 = ADD32(ctx->r5, -0X455C);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BA00: addiu       $a1, $a1, -0x455C
    ctx->r5 = ADD32(ctx->r5, -0X455C);
    after_0:
    // 0x8015BA04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015BA08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015BA0C: jr          $ra
    // 0x8015BA10: nop

    return;
    // 0x8015BA10: nop

;}
RECOMP_FUNC void ftCommonCaptureWaitKirbyUpdateBreakoutVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014BA98: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014BA9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014BAA0: lw          $v0, 0x24($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X24);
    // 0x8014BAA4: addiu       $at, $zero, 0x11C
    ctx->r1 = ADD32(0, 0X11C);
    // 0x8014BAA8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8014BAAC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8014BAB0: beq         $v0, $at, L_8014BAC4
    if (ctx->r2 == ctx->r1) {
        // 0x8014BAB4: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8014BAC4;
    }
    // 0x8014BAB4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8014BAB8: addiu       $at, $zero, 0x113
    ctx->r1 = ADD32(0, 0X113);
    // 0x8014BABC: bnel        $v0, $at, L_8014BC88
    if (ctx->r2 != ctx->r1) {
        // 0x8014BAC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014BC88;
    }
    goto skip_0;
    // 0x8014BAC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_8014BAC4:
    // 0x8014BAC4: lb          $v0, 0x1C3($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X1C3);
    // 0x8014BAC8: slti        $at, $v0, 0x35
    ctx->r1 = SIGNED(ctx->r2) < 0X35 ? 1 : 0;
    // 0x8014BACC: bnel        $at, $zero, L_8014BB30
    if (ctx->r1 != 0) {
        // 0x8014BAD0: slti        $at, $v0, -0x34
        ctx->r1 = SIGNED(ctx->r2) < -0X34 ? 1 : 0;
            goto L_8014BB30;
    }
    goto skip_1;
    // 0x8014BAD0: slti        $at, $v0, -0x34
    ctx->r1 = SIGNED(ctx->r2) < -0X34 ? 1 : 0;
    skip_1:
    // 0x8014BAD4: lbu         $t6, 0x269($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X269);
    // 0x8014BAD8: addiu       $t7, $zero, 0xFE
    ctx->r15 = ADD32(0, 0XFE);
    // 0x8014BADC: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x8014BAE0: beql        $at, $zero, L_8014BB30
    if (ctx->r1 == 0) {
        // 0x8014BAE4: slti        $at, $v0, -0x34
        ctx->r1 = SIGNED(ctx->r2) < -0X34 ? 1 : 0;
            goto L_8014BB30;
    }
    goto skip_2;
    // 0x8014BAE4: slti        $at, $v0, -0x34
    ctx->r1 = SIGNED(ctx->r2) < -0X34 ? 1 : 0;
    skip_2:
    // 0x8014BAE8: sb          $t7, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r15;
    // 0x8014BAEC: lw          $t8, 0x14C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14C);
    // 0x8014BAF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014BAF4: bnel        $t8, $zero, L_8014BBA8
    if (ctx->r24 != 0) {
        // 0x8014BAF8: lb          $v1, 0x1C2($a2)
        ctx->r3 = MEM_B(ctx->r6, 0X1C2);
            goto L_8014BBA8;
    }
    goto skip_3;
    // 0x8014BAF8: lb          $v1, 0x1C2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1C2);
    skip_3:
    // 0x8014BAFC: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x8014BB00: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8014BB04: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8014BB08: jal         0x80162D80
    // 0x8014BB0C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftKirbySpecialNWaitSwitchStatusAir(rdram, ctx);
        goto after_0;
    // 0x8014BB0C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x8014BB10: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8014BB14: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8014BB18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014BB1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014BB20: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8014BB24: b           L_8014BBA4
    // 0x8014BB28: swc1        $f4, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->f4.u32l;
        goto L_8014BBA4;
    // 0x8014BB28: swc1        $f4, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->f4.u32l;
    // 0x8014BB2C: slti        $at, $v0, -0x34
    ctx->r1 = SIGNED(ctx->r2) < -0X34 ? 1 : 0;
L_8014BB30:
    // 0x8014BB30: beql        $at, $zero, L_8014BBA8
    if (ctx->r1 == 0) {
        // 0x8014BB34: lb          $v1, 0x1C2($a2)
        ctx->r3 = MEM_B(ctx->r6, 0X1C2);
            goto L_8014BBA8;
    }
    goto skip_4;
    // 0x8014BB34: lb          $v1, 0x1C2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1C2);
    skip_4:
    // 0x8014BB38: lbu         $t9, 0x269($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X269);
    // 0x8014BB3C: slti        $at, $t9, 0x4
    ctx->r1 = SIGNED(ctx->r25) < 0X4 ? 1 : 0;
    // 0x8014BB40: beql        $at, $zero, L_8014BBA8
    if (ctx->r1 == 0) {
        // 0x8014BB44: lb          $v1, 0x1C2($a2)
        ctx->r3 = MEM_B(ctx->r6, 0X1C2);
            goto L_8014BBA8;
    }
    goto skip_5;
    // 0x8014BB44: lb          $v1, 0x1C2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1C2);
    skip_5:
    // 0x8014BB48: lw          $t1, 0xF4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0XF4);
    // 0x8014BB4C: addiu       $t3, $zero, 0xFE
    ctx->r11 = ADD32(0, 0XFE);
    // 0x8014BB50: andi        $t2, $t1, 0x4000
    ctx->r10 = ctx->r9 & 0X4000;
    // 0x8014BB54: beql        $t2, $zero, L_8014BBA8
    if (ctx->r10 == 0) {
        // 0x8014BB58: lb          $v1, 0x1C2($a2)
        ctx->r3 = MEM_B(ctx->r6, 0X1C2);
            goto L_8014BBA8;
    }
    goto skip_6;
    // 0x8014BB58: lb          $v1, 0x1C2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1C2);
    skip_6:
    // 0x8014BB5C: sb          $t3, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r11;
    // 0x8014BB60: lw          $t4, 0x14C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X14C);
    // 0x8014BB64: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014BB68: bnel        $t4, $zero, L_8014BBA8
    if (ctx->r12 != 0) {
        // 0x8014BB6C: lb          $v1, 0x1C2($a2)
        ctx->r3 = MEM_B(ctx->r6, 0X1C2);
            goto L_8014BBA8;
    }
    goto skip_7;
    // 0x8014BB6C: lb          $v1, 0x1C2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1C2);
    skip_7:
    // 0x8014BB70: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x8014BB74: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8014BB78: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8014BB7C: jal         0x80162D80
    // 0x8014BB80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftKirbySpecialNWaitSwitchStatusAir(rdram, ctx);
        goto after_1;
    // 0x8014BB80: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8014BB84: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x8014BB88: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x8014BB8C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014BB90: lw          $t5, 0xEC($a3)
    ctx->r13 = MEM_W(ctx->r7, 0XEC);
    // 0x8014BB94: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014BB98: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8014BB9C: sw          $t5, 0x144($a3)
    MEM_W(0X144, ctx->r7) = ctx->r13;
    // 0x8014BBA0: swc1        $f6, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->f6.u32l;
L_8014BBA4:
    // 0x8014BBA4: lb          $v1, 0x1C2($a2)
    ctx->r3 = MEM_B(ctx->r6, 0X1C2);
L_8014BBA8:
    // 0x8014BBA8: bgez        $v1, L_8014BBB8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8014BBAC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8014BBB8;
    }
    // 0x8014BBAC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8014BBB0: b           L_8014BBB8
    // 0x8014BBB4: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8014BBB8;
    // 0x8014BBB4: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8014BBB8:
    // 0x8014BBB8: slti        $at, $v0, 0x38
    ctx->r1 = SIGNED(ctx->r2) < 0X38 ? 1 : 0;
    // 0x8014BBBC: bne         $at, $zero, L_8014BC60
    if (ctx->r1 != 0) {
        // 0x8014BBC0: nop
    
            goto L_8014BC60;
    }
    // 0x8014BBC0: nop

    // 0x8014BBC4: lbu         $t6, 0x268($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X268);
    // 0x8014BBC8: addiu       $t7, $zero, 0xFE
    ctx->r15 = ADD32(0, 0XFE);
    // 0x8014BBCC: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x8014BBD0: beq         $at, $zero, L_8014BC60
    if (ctx->r1 == 0) {
        // 0x8014BBD4: nop
    
            goto L_8014BC60;
    }
    // 0x8014BBD4: nop

    // 0x8014BBD8: sb          $t7, 0x268($a2)
    MEM_B(0X268, ctx->r6) = ctx->r15;
    // 0x8014BBDC: lw          $t8, 0x14C($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X14C);
    // 0x8014BBE0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8014BBE4: bnel        $t8, $zero, L_8014BC34
    if (ctx->r24 != 0) {
        // 0x8014BBE8: lb          $t3, 0x1C2($a2)
        ctx->r11 = MEM_B(ctx->r6, 0X1C2);
            goto L_8014BC34;
    }
    goto skip_8;
    // 0x8014BBE8: lb          $t3, 0x1C2($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X1C2);
    skip_8:
    // 0x8014BBEC: lb          $t9, 0x1C2($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X1C2);
    // 0x8014BBF0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014BBF4: bgez        $t9, L_8014BC04
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8014BBF8: nop
    
            goto L_8014BC04;
    }
    // 0x8014BBF8: nop

    // 0x8014BBFC: b           L_8014BC04
    // 0x8014BC00: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8014BC04;
    // 0x8014BC00: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8014BC04:
    // 0x8014BC04: lw          $t1, 0x44($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X44);
    // 0x8014BC08: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8014BC0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8014BC10: multu       $v0, $t1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r9)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8014BC14: mflo        $t2
    ctx->r10 = lo;
    // 0x8014BC18: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x8014BC1C: nop

    // 0x8014BC20: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8014BC24: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8014BC28: b           L_8014BC60
    // 0x8014BC2C: swc1        $f18, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->f18.u32l;
        goto L_8014BC60;
    // 0x8014BC2C: swc1        $f18, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->f18.u32l;
    // 0x8014BC30: lb          $t3, 0x1C2($a2)
    ctx->r11 = MEM_B(ctx->r6, 0X1C2);
L_8014BC34:
    // 0x8014BC34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014BC38: bgez        $t3, L_8014BC48
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8014BC3C: nop
    
            goto L_8014BC48;
    }
    // 0x8014BC3C: nop

    // 0x8014BC40: b           L_8014BC48
    // 0x8014BC44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8014BC48;
    // 0x8014BC44: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8014BC48:
    // 0x8014BC48: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8014BC4C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8014BC50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014BC54: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014BC58: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8014BC5C: swc1        $f10, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->f10.u32l;
L_8014BC60:
    // 0x8014BC60: beql        $t0, $zero, L_8014BC88
    if (ctx->r8 == 0) {
        // 0x8014BC64: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014BC88;
    }
    goto skip_9;
    // 0x8014BC64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x8014BC68: lw          $a1, 0x9CC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X9CC);
    // 0x8014BC6C: beql        $a1, $zero, L_8014BC88
    if (ctx->r5 == 0) {
        // 0x8014BC70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014BC88;
    }
    goto skip_10;
    // 0x8014BC70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x8014BC74: lw          $t4, 0x8E8($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X8E8);
    // 0x8014BC78: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014BC7C: jal         0x800C87F4
    // 0x8014BC80: lw          $a0, 0x10($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X10);
    lbCommonAddFighterPartsFigatree(rdram, ctx);
        goto after_2;
    // 0x8014BC80: lw          $a0, 0x10($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X10);
    after_2:
    // 0x8014BC84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014BC88:
    // 0x8014BC88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014BC8C: jr          $ra
    // 0x8014BC90: nop

    return;
    // 0x8014BC90: nop

;}
RECOMP_FUNC void sc1PIntroMakeStageCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013376C: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x80133770: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133774: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80133778: addiu       $t7, $t7, 0x5180
    ctx->r15 = ADD32(ctx->r15, 0X5180);
    // 0x8013377C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80133780: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80133784: sw          $a0, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r4;
    // 0x80133788: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x8013378C: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
L_80133790:
    // 0x80133790: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133794: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80133798: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013379C: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x801337A0: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x801337A4: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801337A8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801337AC: bne         $t7, $t0, L_80133790
    if (ctx->r15 != ctx->r8) {
        // 0x801337B0: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80133790;
    }
    // 0x801337B0: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801337B4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801337B8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801337BC: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x801337C0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x801337C4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801337C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801337CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801337D0: jal         0x80030A54
    // 0x801337D4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x801337D4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    after_0:
    // 0x801337D8: lui         $t1, 0x8001
    ctx->r9 = S32(0X8001 << 16);
    // 0x801337DC: addiu       $t1, $t1, 0x7EC0
    ctx->r9 = ADD32(ctx->r9, 0X7EC0);
    // 0x801337E0: addiu       $t2, $zero, 0x28
    ctx->r10 = ADD32(0, 0X28);
    // 0x801337E4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801337E8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801337EC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801337F0: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
    // 0x801337F4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    // 0x801337F8: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x801337FC: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80133800: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80133804: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133808: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013380C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133810: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133814: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80133818: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8013381C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133820: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133824: jal         0x8000B93C
    // 0x80133828: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    gcMakeCameraGObj(rdram, ctx);
        goto after_1;
    // 0x80133828: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    after_1:
    // 0x8013382C: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x80133830: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x80133834: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80133838: jal         0x80008CF0
    // 0x8013383C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_2;
    // 0x8013383C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80133840: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x80133844: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80133848: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013384C: jal         0x80008CF0
    // 0x80133850: lw          $a0, 0x74($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X74);
    gcAddXObjForCamera(rdram, ctx);
        goto after_3;
    // 0x80133850: lw          $a0, 0x74($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X74);
    after_3:
    // 0x80133854: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133858: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013385C: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x80133860: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133864: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133868: lw          $s0, 0x74($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X74);
    // 0x8013386C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133870: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133874: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133878: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x8013387C: jal         0x80007080
    // 0x80133880: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_4;
    // 0x80133880: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x80133884: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x80133888: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013388C: lw          $t1, 0x6058($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6058);
    // 0x80133890: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80133894: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80133898: lw          $t9, 0x54($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X54);
    // 0x8013389C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801338A0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801338A4: jal         0x8000FA3C
    // 0x801338A8: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_5;
    // 0x801338A8: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    after_5:
    // 0x801338AC: jal         0x80010580
    // 0x801338B0: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    gcPlayCamAnim(rdram, ctx);
        goto after_6;
    // 0x801338B0: lw          $a0, 0xAC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XAC);
    after_6:
    // 0x801338B4: lw          $t2, 0xB0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XB0);
    // 0x801338B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801338BC: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x801338C0: bnel        $t2, $at, L_80133904
    if (ctx->r10 != ctx->r1) {
        // 0x801338C4: lui         $at, 0x4300
        ctx->r1 = S32(0X4300 << 16);
            goto L_80133904;
    }
    goto skip_0;
    // 0x801338C4: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    skip_0:
    // 0x801338C8: jal         0x801336CC
    // 0x801338CC: lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB0);
    sc1PIntroGetStageCObjDesc(rdram, ctx);
        goto after_7;
    // 0x801338CC: lw          $a1, 0xB0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XB0);
    after_7:
    // 0x801338D0: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x801338D4: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x801338D8: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801338DC: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x801338E0: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x801338E4: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x801338E8: lwc1        $f16, 0x98($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X98);
    // 0x801338EC: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x801338F0: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801338F4: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x801338F8: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x801338FC: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x80133900: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
L_80133904:
    // 0x80133904: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133908: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x8013390C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133910: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80133914: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80133918: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x8013391C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80133920: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80133924: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x80133928: jr          $ra
    // 0x8013392C: nop

    return;
    // 0x8013392C: nop

;}
RECOMP_FUNC void ftCommonEscapeCheckInterruptSpecialNDonkey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014935C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80149360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80149368: jal         0x801492F8
    // 0x8014936C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    ftCommonEscapeGetStatus(rdram, ctx);
        goto after_0;
    // 0x8014936C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80149370: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80149374: beq         $v0, $at, L_80149390
    if (ctx->r2 == ctx->r1) {
        // 0x80149378: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80149390;
    }
    // 0x80149378: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8014937C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80149380: jal         0x80149294
    // 0x80149384: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftCommonEscapeSetStatus(rdram, ctx);
        goto after_1;
    // 0x80149384: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80149388: b           L_80149394
    // 0x8014938C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80149394;
    // 0x8014938C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80149390:
    // 0x80149390: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80149394:
    // 0x80149394: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149398: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014939C: jr          $ra
    // 0x801493A0: nop

    return;
    // 0x801493A0: nop

;}
RECOMP_FUNC void mnPlayers1PBonusCheckTimeArrowLInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013457C: jr          $ra
    // 0x80134580: nop

    return;
    // 0x80134580: nop

;}
RECOMP_FUNC void mvOpeningCliffInitTotalTimeTics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132408: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013240C: jr          $ra
    // 0x80132410: sw          $zero, 0x27CC($at)
    MEM_W(0X27CC, ctx->r1) = 0;
    return;
    // 0x80132410: sw          $zero, 0x27CC($at)
    MEM_W(0X27CC, ctx->r1) = 0;
;}
RECOMP_FUNC void mnPlayersVSMakePlayerKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801334A8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x801334AC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801334B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801334B4: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x801334B8: addiu       $t7, $t7, -0x495C
    ctx->r15 = ADD32(ctx->r15, -0X495C);
    // 0x801334BC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801334C0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801334C4: addiu       $t6, $sp, 0x38
    ctx->r14 = ADD32(ctx->r29, 0X38);
    // 0x801334C8: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801334CC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801334D0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801334D4: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801334D8: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801334DC: addiu       $t1, $t1, -0x494C
    ctx->r9 = ADD32(ctx->r9, -0X494C);
    // 0x801334E0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x801334E4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801334E8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801334EC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801334F0: addiu       $t0, $sp, 0x28
    ctx->r8 = ADD32(ctx->r29, 0X28);
    // 0x801334F4: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x801334F8: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x801334FC: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80133500: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80133504: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133508: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013350C: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x80133510: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133514: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80133518: jal         0x80009968
    // 0x8013351C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013351C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    after_0:
    // 0x80133520: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80133524: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133528: addiu       $t6, $t6, -0x4578
    ctx->r14 = ADD32(ctx->r14, -0X4578);
    // 0x8013352C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80133530: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x80133534: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x80133538: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x8013353C: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x80133540: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80133544: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80133548: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8013354C: sw          $v0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->r2;
    // 0x80133550: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80133554: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80133558: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013355C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80133560: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133564: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80133568: jal         0x80009DF4
    // 0x8013356C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013356C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133570: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80133574: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133578: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x8013357C: lw          $t8, 0x84($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X84);
    // 0x80133580: lw          $v1, 0x50($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X50);
    // 0x80133584: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80133588: bne         $t8, $at, L_801335D4
    if (ctx->r24 != ctx->r1) {
        // 0x8013358C: sll         $v1, $v1, 2
        ctx->r3 = S32(ctx->r3 << 2);
            goto L_801335D4;
    }
    // 0x8013358C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80133590: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80133594: lw          $t9, -0x3B60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3B60);
    // 0x80133598: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x8013359C: addiu       $t0, $t0, 0xFF8
    ctx->r8 = ADD32(ctx->r8, 0XFF8);
    // 0x801335A0: jal         0x800CCFDC
    // 0x801335A4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801335A4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_2:
    // 0x801335A8: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x801335AC: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x801335B0: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801335B4: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x801335B8: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x801335BC: addiu       $t3, $t2, 0x1A
    ctx->r11 = ADD32(ctx->r10, 0X1A);
    // 0x801335C0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801335C4: nop

    // 0x801335C8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801335CC: b           L_80133620
    // 0x801335D0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
        goto L_80133620;
    // 0x801335D0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
L_801335D4:
    // 0x801335D4: addu        $t4, $sp, $v1
    ctx->r12 = ADD32(ctx->r29, ctx->r3);
    // 0x801335D8: lw          $t4, 0x38($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X38);
    // 0x801335DC: lw          $t5, -0x3B60($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X3B60);
    // 0x801335E0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x801335E4: jal         0x800CCFDC
    // 0x801335E8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801335E8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x801335EC: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x801335F0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801335F4: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x801335F8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x801335FC: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80133600: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80133604: addiu       $t9, $t8, 0x16
    ctx->r25 = ADD32(ctx->r24, 0X16);
    // 0x80133608: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8013360C: addu        $t6, $sp, $v1
    ctx->r14 = ADD32(ctx->r29, ctx->r3);
    // 0x80133610: lwc1        $f8, 0x28($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X28);
    // 0x80133614: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80133618: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8013361C: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
L_80133620:
    // 0x80133620: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80133624: lui         $at, 0x4303
    ctx->r1 = S32(0X4303 << 16);
    // 0x80133628: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013362C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80133630: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133634: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80133638: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x8013363C: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80133640: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80133644: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80133648: swc1        $f4, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f4.u32l;
    // 0x8013364C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80133650: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80133654: jr          $ra
    // 0x80133658: nop

    return;
    // 0x80133658: nop

;}
RECOMP_FUNC void sySchedulerGetTicCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000092C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000930: jr          $ra
    // 0x80000934: lw          $v0, 0x501C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X501C);
    return;
    // 0x80000934: lw          $v0, 0x501C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X501C);
;}
RECOMP_FUNC void itSpearAppearInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017FEB8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8017FEBC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017FEC0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017FEC4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017FEC8: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017FECC: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x8017FED0: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x8017FED4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8017FED8: sh          $zero, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = 0;
    // 0x8017FEDC: bne         $t6, $at, L_8017FF64
    if (ctx->r14 != ctx->r1) {
        // 0x8017FEE0: swc1        $f4, 0x30($v0)
        MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
            goto L_8017FF64;
    }
    // 0x8017FEE0: swc1        $f4, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f4.u32l;
    // 0x8017FEE4: lw          $t7, 0x2D4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017FEE8: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x8017FEEC: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x8017FEF0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8017FEF4: addiu       $t0, $t0, -0x20C8
    ctx->r8 = ADD32(ctx->r8, -0X20C8);
    // 0x8017FEF8: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8017FEFC: addiu       $t1, $t1, -0x2004
    ctx->r9 = ADD32(ctx->r9, -0X2004);
    // 0x8017FF00: subu        $t9, $t8, $t0
    ctx->r25 = SUB32(ctx->r24, ctx->r8);
    // 0x8017FF04: addu        $a1, $t9, $t1
    ctx->r5 = ADD32(ctx->r25, ctx->r9);
    // 0x8017FF08: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8017FF0C: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    // 0x8017FF10: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8017FF14: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8017FF18: jal         0x8000BD1C
    // 0x8017FF1C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x8017FF1C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    after_0:
    // 0x8017FF20: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8017FF24: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8017FF28: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x8017FF2C: lw          $t2, 0x2D4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2D4);
    // 0x8017FF30: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x8017FF34: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x8017FF38: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8017FF3C: addiu       $t5, $t5, -0x1ED4
    ctx->r13 = ADD32(ctx->r13, -0X1ED4);
    // 0x8017FF40: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8017FF44: subu        $t4, $t3, $t0
    ctx->r12 = SUB32(ctx->r11, ctx->r8);
    // 0x8017FF48: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x8017FF4C: jal         0x8000BD54
    // 0x8017FF50: lw          $a0, 0x80($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X80);
    gcAddMObjMatAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8017FF50: lw          $a0, 0x80($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X80);
    after_1:
    // 0x8017FF54: jal         0x8000DF34
    // 0x8017FF58: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    gcPlayAnimAll(rdram, ctx);
        goto after_2;
    // 0x8017FF58: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x8017FF5C: jal         0x800269C0
    // 0x8017FF60: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x8017FF60: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_3:
L_8017FF64:
    // 0x8017FF64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017FF68: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8017FF6C: jr          $ra
    // 0x8017FF70: nop

    return;
    // 0x8017FF70: nop

;}
RECOMP_FUNC void func_ovl8_80385B74(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385B74: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80385B78: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80385B7C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80385B80: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80385B84: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80385B88: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80385B8C: bne         $a0, $zero, L_80385BA4
    if (ctx->r4 != 0) {
        // 0x80385B90: sw          $a3, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r7;
            goto L_80385BA4;
    }
    // 0x80385B90: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80385B94: jal         0x803717A0
    // 0x80385B98: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80385B98: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_0:
    // 0x80385B9C: beq         $v0, $zero, L_80385C5C
    if (ctx->r2 == 0) {
        // 0x80385BA0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80385C5C;
    }
    // 0x80385BA0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80385BA4:
    // 0x80385BA4: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80385BA8: addiu       $a0, $s0, 0xD8
    ctx->r4 = ADD32(ctx->r16, 0XD8);
    // 0x80385BAC: addiu       $a1, $s0, 0x134
    ctx->r5 = ADD32(ctx->r16, 0X134);
    // 0x80385BB0: bnel        $t6, $zero, L_80385BD4
    if (ctx->r14 != 0) {
        // 0x80385BB4: lw          $a3, 0x44($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X44);
            goto L_80385BD4;
    }
    goto skip_0;
    // 0x80385BB4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x80385BB8: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80385BBC: sw          $a0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r4;
    // 0x80385BC0: jal         0x803717E0
    // 0x80385BC4: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80385BC4: sw          $a1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r5;
    after_1:
    // 0x80385BC8: jal         0x8037C2D0
    // 0x80385BCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x80385BCC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x80385BD0: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
L_80385BD4:
    // 0x80385BD4: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80385BD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80385BDC: lw          $v0, 0x24($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X24);
    // 0x80385BE0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80385BE4: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80385BE8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80385BEC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80385BF0: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x80385BF4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80385BF8: jal         0x8037C7D4
    // 0x80385BFC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    func_ovl8_8037C7D4(rdram, ctx);
        goto after_3;
    // 0x80385BFC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_3:
    // 0x80385C00: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80385C04: addiu       $a0, $s0, 0xB8
    ctx->r4 = ADD32(ctx->r16, 0XB8);
    // 0x80385C08: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80385C0C: lw          $t2, 0x24($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X24);
    // 0x80385C10: jal         0x8038116C
    // 0x80385C14: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    func_ovl8_8038116C(rdram, ctx);
        goto after_4;
    // 0x80385C14: lw          $a1, 0x8($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X8);
    after_4:
    // 0x80385C18: lui         $t3, 0x8039
    ctx->r11 = S32(0X8039 << 16);
    // 0x80385C1C: addiu       $t3, $t3, -0x2140
    ctx->r11 = ADD32(ctx->r11, -0X2140);
    // 0x80385C20: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
    // 0x80385C24: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80385C28: lui         $t4, 0x8039
    ctx->r12 = S32(0X8039 << 16);
    // 0x80385C2C: addiu       $t4, $t4, -0x2060
    ctx->r12 = ADD32(ctx->r12, -0X2060);
    // 0x80385C30: sw          $t4, 0x58($t5)
    MEM_W(0X58, ctx->r13) = ctx->r12;
    // 0x80385C34: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x80385C38: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80385C3C: addiu       $t6, $t6, -0x1F08
    ctx->r14 = ADD32(ctx->r14, -0X1F08);
    // 0x80385C40: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80385C44: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80385C48: sw          $t6, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r14;
    // 0x80385C4C: addiu       $t9, $t9, -0x1E78
    ctx->r25 = ADD32(ctx->r25, -0X1E78);
    // 0x80385C50: addiu       $t8, $t8, -0x1EE0
    ctx->r24 = ADD32(ctx->r24, -0X1EE0);
    // 0x80385C54: sw          $t8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r24;
    // 0x80385C58: sw          $t9, 0xD4($s0)
    MEM_W(0XD4, ctx->r16) = ctx->r25;
L_80385C5C:
    // 0x80385C5C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80385C60: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80385C64: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80385C68: jr          $ra
    // 0x80385C6C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80385C6C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void ftKirbySpecialNEatSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162BA0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162BA4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162BA8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162BAC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162BB0: jal         0x800DEEC8
    // 0x80162BB4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80162BB4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162BB8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162BBC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80162BC0: addiu       $a1, $zero, 0x11A
    ctx->r5 = ADD32(0, 0X11A);
    // 0x80162BC4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162BC8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162BCC: jal         0x800E6F24
    // 0x80162BD0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162BD0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162BD4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162BD8: jal         0x800E8098
    // 0x80162BDC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162BDC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162BE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162BE4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162BE8: jr          $ra
    // 0x80162BEC: nop

    return;
    // 0x80162BEC: nop

;}
RECOMP_FUNC void ftFoxSpecialLwCheckSetRelease(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CB80: lhu         $t6, 0x1BC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X1BC);
    // 0x8015CB84: lhu         $t7, 0x1B6($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1B6);
    // 0x8015CB88: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8015CB8C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8015CB90: bne         $t8, $zero, L_8015CB9C
    if (ctx->r24 != 0) {
        // 0x8015CB94: nop
    
            goto L_8015CB9C;
    }
    // 0x8015CB94: nop

    // 0x8015CB98: sw          $t9, 0xB20($a0)
    MEM_W(0XB20, ctx->r4) = ctx->r25;
L_8015CB9C:
    // 0x8015CB9C: jr          $ra
    // 0x8015CBA0: nop

    return;
    // 0x8015CBA0: nop

;}
RECOMP_FUNC void ftCommonKneeBendCheckInterruptRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F598: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013F59C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F5A0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013F5A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013F5A8: jal         0x800F3794
    // 0x8013F5AC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftHammerCheckHoldHammer(rdram, ctx);
        goto after_0;
    // 0x8013F5AC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013F5B0: beq         $v0, $zero, L_8013F5C8
    if (ctx->r2 == 0) {
        // 0x8013F5B4: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_8013F5C8;
    }
    // 0x8013F5B4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8013F5B8: jal         0x8014800C
    // 0x8013F5BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonHammerKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8013F5BC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8013F5C0: b           L_8013F5F8
    // 0x8013F5C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8013F5F8;
    // 0x8013F5C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013F5C8:
    // 0x8013F5C8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8013F5CC: jal         0x8013F53C
    // 0x8013F5D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    ftCommonKneeBendGetInputTypeRun(rdram, ctx);
        goto after_2;
    // 0x8013F5D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8013F5D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8013F5D8: beq         $v0, $zero, L_8013F5F0
    if (ctx->r2 == 0) {
        // 0x8013F5DC: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8013F5F0;
    }
    // 0x8013F5DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8013F5E0: jal         0x8013F408
    // 0x8013F5E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonKneeBendSetStatus(rdram, ctx);
        goto after_3;
    // 0x8013F5E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x8013F5E8: b           L_8013F5F4
    // 0x8013F5EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013F5F4;
    // 0x8013F5EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013F5F0:
    // 0x8013F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013F5F4:
    // 0x8013F5F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013F5F8:
    // 0x8013F5F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013F5FC: jr          $ra
    // 0x8013F600: nop

    return;
    // 0x8013F600: nop

;}
RECOMP_FUNC void wpNessPKReflectHeadProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B7AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016B7B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B7B4: jal         0x80167C04
    // 0x8016B7B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8016B7B8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016B7BC: beq         $v0, $zero, L_8016B7E8
    if (ctx->r2 == 0) {
        // 0x8016B7C0: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_8016B7E8;
    }
    // 0x8016B7C0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016B7C4: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8016B7C8: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016B7CC: jal         0x800FF648
    // 0x8016B7D0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016B7D0: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8016B7D4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8016B7D8: jal         0x8016B6A0
    // 0x8016B7DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKReflectHeadSetDestroyTrails(rdram, ctx);
        goto after_2;
    // 0x8016B7DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8016B7E0: b           L_8016B7EC
    // 0x8016B7E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016B7EC;
    // 0x8016B7E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016B7E8:
    // 0x8016B7E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016B7EC:
    // 0x8016B7EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B7F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016B7F4: jr          $ra
    // 0x8016B7F8: nop

    return;
    // 0x8016B7F8: nop

;}
RECOMP_FUNC void mnVSItemSwitchSetToggleSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B24: beq         $a1, $zero, L_80131B60
    if (ctx->r5 == 0) {
        // 0x80131B28: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_80131B60;
    }
    // 0x80131B28: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131B2C: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80131B30: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x80131B34: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80131B38: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x80131B3C: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80131B40: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80131B44: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    // 0x80131B48: sb          $v1, 0x28($t8)
    MEM_B(0X28, ctx->r24) = ctx->r3;
    // 0x80131B4C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80131B50: sb          $v1, 0x29($t9)
    MEM_B(0X29, ctx->r25) = ctx->r3;
    // 0x80131B54: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80131B58: jr          $ra
    // 0x80131B5C: sb          $v1, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r3;
    return;
    // 0x80131B5C: sb          $v1, 0x2A($t0)
    MEM_B(0X2A, ctx->r8) = ctx->r3;
L_80131B60:
    // 0x80131B60: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x80131B64: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80131B68: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131B6C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131B70: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131B74: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80131B78: sb          $t1, 0x28($t2)
    MEM_B(0X28, ctx->r10) = ctx->r9;
    // 0x80131B7C: lw          $t3, 0x8($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X8);
    // 0x80131B80: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x80131B84: sb          $zero, 0x29($t3)
    MEM_B(0X29, ctx->r11) = 0;
    // 0x80131B88: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x80131B8C: sb          $t4, 0x2A($t5)
    MEM_B(0X2A, ctx->r13) = ctx->r12;
    // 0x80131B90: jr          $ra
    // 0x80131B94: nop

    return;
    // 0x80131B94: nop

;}
RECOMP_FUNC void syControllerStopRumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004494: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80004498: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000449C: jal         0x800043C0
    // 0x800044A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    syControllerUpdateRumbleEvent(rdram, ctx);
        goto after_0;
    // 0x800044A0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x800044A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800044A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800044AC: jr          $ra
    // 0x800044B0: nop

    return;
    // 0x800044B0: nop

;}
RECOMP_FUNC void lbRelocGetForceExternBufferFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CDD5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CDD60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CDD64: jal         0x800CD698
    // 0x800CDD68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    lbRelocFindForceStatusBufferFile(rdram, ctx);
        goto after_0;
    // 0x800CDD68: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x800CDD6C: beq         $v0, $zero, L_800CDD7C
    if (ctx->r2 == 0) {
        // 0x800CDD70: lui         $t6, 0x800D
        ctx->r14 = S32(0X800D << 16);
            goto L_800CDD7C;
    }
    // 0x800CDD70: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CDD74: b           L_800CDDCC
    // 0x800CDD78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CDDCC;
    // 0x800CDD78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CDD7C:
    // 0x800CDD7C: lw          $t6, 0x6348($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6348);
    // 0x800CDD80: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x800CDD84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CDD88: addiu       $t7, $t6, 0xF
    ctx->r15 = ADD32(ctx->r14, 0XF);
    // 0x800CDD8C: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800CDD90: jal         0x800CD814
    // 0x800CDD94: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    lbRelocReadDmaTableEntry(rdram, ctx);
        goto after_1;
    // 0x800CDD94: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_1:
    // 0x800CDD98: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800CDD9C: lw          $t9, 0x6334($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6334);
    // 0x800CDDA0: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDDA4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CDDA8: lhu         $a2, 0xA($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0XA);
    // 0x800CDDAC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800CDDB0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800CDDB4: sll         $a2, $a2, 2
    ctx->r6 = S32(ctx->r6 << 2);
    // 0x800CDDB8: addu        $t0, $a1, $a2
    ctx->r8 = ADD32(ctx->r5, ctx->r6);
    // 0x800CDDBC: jal         0x800CD854
    // 0x800CDDC0: sw          $t0, 0x6348($at)
    MEM_W(0X6348, ctx->r1) = ctx->r8;
    lbRelocLoadAndRelocFile(rdram, ctx);
        goto after_2;
    // 0x800CDDC0: sw          $t0, 0x6348($at)
    MEM_W(0X6348, ctx->r1) = ctx->r8;
    after_2:
    // 0x800CDDC4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800CDDC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CDDCC:
    // 0x800CDDCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800CDDD0: jr          $ra
    // 0x800CDDD4: nop

    return;
    // 0x800CDDD4: nop

;}
RECOMP_FUNC void sc1PTrainingModeSetHScrollOptionSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F5CC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018F5D0: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018F5D4: lw          $t6, 0x58($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X58);
    // 0x8018F5D8: lw          $t8, 0x5C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5C);
    // 0x8018F5DC: lw          $t0, 0x60($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X60);
    // 0x8018F5E0: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8018F5E4: lw          $t2, 0x64($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X64);
    // 0x8018F5E8: sw          $t7, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r15;
    // 0x8018F5EC: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x8018F5F0: sw          $t9, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r25;
    // 0x8018F5F4: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x8018F5F8: sw          $t1, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r9;
    // 0x8018F5FC: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x8018F600: jr          $ra
    // 0x8018F604: sw          $t3, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r11;
    return;
    // 0x8018F604: sw          $t3, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r11;
;}
RECOMP_FUNC void func_ovl28_80133ED8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133ED8: jr          $ra
    // 0x80133EDC: nop

    return;
    // 0x80133EDC: nop

;}
RECOMP_FUNC void itEggCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181640: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80181644: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181648: jal         0x801730D4
    // 0x8018164C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itMainMakeContainerItem(rdram, ctx);
        goto after_0;
    // 0x8018164C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80181650: beq         $v0, $zero, L_8018166C
    if (ctx->r2 == 0) {
        // 0x80181654: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_8018166C;
    }
    // 0x80181654: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80181658: lw          $a0, 0x74($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X74);
    // 0x8018165C: jal         0x801041A0
    // 0x80181660: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerEggBreakMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80181660: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80181664: b           L_80181678
    // 0x80181668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80181678;
    // 0x80181668: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018166C:
    // 0x8018166C: jal         0x80181B90
    // 0x80181670: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itEggExplodeMakeEffectGotoSetStatus(rdram, ctx);
        goto after_2;
    // 0x80181670: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
    // 0x80181674: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80181678:
    // 0x80181678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018167C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181680: jr          $ra
    // 0x80181684: nop

    return;
    // 0x80181684: nop

;}
RECOMP_FUNC void ftCommonGuardOffSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148FF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80148FF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80148FF8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80148FFC: addiu       $t9, $zero, 0x34
    ctx->r25 = ADD32(0, 0X34);
    // 0x80149000: addiu       $a1, $zero, 0x9A
    ctx->r5 = ADD32(0, 0X9A);
    // 0x80149004: lw          $t6, 0x18C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18C);
    // 0x80149008: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014900C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80149010: sll         $t7, $t6, 26
    ctx->r15 = S32(ctx->r14 << 26);
    // 0x80149014: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x80149018: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    // 0x8014901C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80149020: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80149024: jal         0x800E6F24
    // 0x80149028: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80149028: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8014902C: jal         0x800E0830
    // 0x80149030: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80149030: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x80149034: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80149038: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8014903C: lbu         $t4, 0x18F($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X18F);
    // 0x80149040: sll         $t2, $t1, 5
    ctx->r10 = S32(ctx->r9 << 5);
    // 0x80149044: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x80149048: andi        $t5, $t4, 0xFFDF
    ctx->r13 = ctx->r12 & 0XFFDF;
    // 0x8014904C: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x80149050: sb          $t6, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r14;
    // 0x80149054: jal         0x80148714
    // 0x80149058: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftCommonGuardUpdateJoints(rdram, ctx);
        goto after_2;
    // 0x80149058: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x8014905C: jal         0x800269C0
    // 0x80149060: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80149060: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_3:
    // 0x80149064: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80149068: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014906C: jr          $ra
    // 0x80149070: nop

    return;
    // 0x80149070: nop

;}
RECOMP_FUNC void mnTitleProceedDemoNext(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131FD4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131FD8: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80131FDC: addiu       $s0, $s0, 0x4AD0
    ctx->r16 = ADD32(ctx->r16, 0X4AD0);
    // 0x80131FE0: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x80131FE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131FE8: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80131FEC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80131FF0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80131FF4: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80131FF8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131FFC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x80132000: jal         0x8000B9FC
    // 0x80132004: sb          $t6, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r14;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132004: sb          $t6, 0x2F($sp)
    MEM_B(0X2F, ctx->r29) = ctx->r14;
    after_0:
    // 0x80132008: jal         0x80131BC4
    // 0x8013200C: nop

    mnTitleSetDemoFighterKinds(rdram, ctx);
        goto after_1;
    // 0x8013200C: nop

    after_1:
    // 0x80132010: jal         0x800266A0
    // 0x80132014: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_2;
    // 0x80132014: nop

    after_2:
    // 0x80132018: lbu         $v0, 0x2F($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X2F);
    // 0x8013201C: lbu         $t8, 0x0($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X0);
    // 0x80132020: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132024: beq         $v0, $at, L_80132064
    if (ctx->r2 == ctx->r1) {
        // 0x80132028: sb          $t8, 0x1($s0)
        MEM_B(0X1, ctx->r16) = ctx->r24;
            goto L_80132064;
    }
    // 0x80132028: sb          $t8, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r24;
    // 0x8013202C: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80132030: beq         $v0, $at, L_8013204C
    if (ctx->r2 == ctx->r1) {
        // 0x80132034: addiu       $t0, $zero, 0x1A
        ctx->r8 = ADD32(0, 0X1A);
            goto L_8013204C;
    }
    // 0x80132034: addiu       $t0, $zero, 0x1A
    ctx->r8 = ADD32(0, 0X1A);
    // 0x80132038: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x8013203C: beq         $v0, $at, L_80132064
    if (ctx->r2 == ctx->r1) {
        // 0x80132040: addiu       $t9, $zero, 0x3C
        ctx->r25 = ADD32(0, 0X3C);
            goto L_80132064;
    }
    // 0x80132040: addiu       $t9, $zero, 0x3C
    ctx->r25 = ADD32(0, 0X3C);
    // 0x80132044: b           L_8013206C
    // 0x80132048: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
        goto L_8013206C;
    // 0x80132048: sb          $t9, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r25;
L_8013204C:
    // 0x8013204C: sb          $t0, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r8;
    // 0x80132050: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132054: jal         0x80020AB4
    // 0x80132058: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    syAudioPlayBGM(rdram, ctx);
        goto after_3;
    // 0x80132058: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_3:
    // 0x8013205C: b           L_80132070
    // 0x80132060: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80132070;
    // 0x80132060: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132064:
    // 0x80132064: addiu       $t1, $zero, 0x1B
    ctx->r9 = ADD32(0, 0X1B);
    // 0x80132068: sb          $t1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r9;
L_8013206C:
    // 0x8013206C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132070:
    // 0x80132070: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132074: sb          $t2, 0x3F($s0)
    MEM_B(0X3F, ctx->r16) = ctx->r10;
    // 0x80132078: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013207C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132080: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132084: sw          $t3, 0x4470($at)
    MEM_W(0X4470, ctx->r1) = ctx->r11;
    // 0x80132088: jr          $ra
    // 0x8013208C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013208C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayers1PGameMakeTimeSetting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133680: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80133684: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133688: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8013368C: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80133690: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80133694: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80133698: addiu       $t6, $t6, -0x757C
    ctx->r14 = ADD32(ctx->r14, -0X757C);
    // 0x8013369C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801336A0: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x801336A4: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801336A8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801336AC: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801336B0: addiu       $s2, $s2, -0x7090
    ctx->r18 = ADD32(ctx->r18, -0X7090);
    // 0x801336B4: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x801336B8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801336BC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x801336C0: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801336C4: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x801336C8: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x801336CC: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x801336D0: lw          $t8, 0x10($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X10);
    // 0x801336D4: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x801336D8: lw          $t7, 0x14($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X14);
    // 0x801336DC: sw          $t7, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r15;
    // 0x801336E0: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x801336E4: lw          $s0, 0x8($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X8);
    // 0x801336E8: beql        $s0, $zero, L_8013371C
    if (ctx->r16 == 0) {
        // 0x801336EC: addiu       $at, $zero, 0x64
        ctx->r1 = ADD32(0, 0X64);
            goto L_8013371C;
    }
    goto skip_0;
    // 0x801336EC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    skip_0:
    // 0x801336F0: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
L_801336F4:
    // 0x801336F4: jal         0x800096EC
    // 0x801336F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEjectSObj(rdram, ctx);
        goto after_0;
    // 0x801336F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801336FC: lw          $s1, 0x0($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X0);
    // 0x80133700: lw          $t0, 0x74($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X74);
    // 0x80133704: lw          $s0, 0x8($t0)
    ctx->r16 = MEM_W(ctx->r8, 0X8);
    // 0x80133708: bne         $s0, $zero, L_801336F4
    if (ctx->r16 != 0) {
        // 0x8013370C: nop
    
            goto L_801336F4;
    }
    // 0x8013370C: nop

    // 0x80133710: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x80133714: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80133718: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
L_8013371C:
    // 0x8013371C: bne         $a1, $at, L_8013379C
    if (ctx->r5 != ctx->r1) {
        // 0x80133720: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8013379C;
    }
    // 0x80133720: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80133724: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133728: lw          $t1, -0x6960($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6960);
    // 0x8013372C: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80133730: addiu       $t2, $t2, 0x3EF0
    ctx->r10 = ADD32(ctx->r10, 0X3EF0);
    // 0x80133734: jal         0x800CCFDC
    // 0x80133738: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80133738: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x8013373C: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80133740: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133744: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x80133748: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013374C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80133750: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80133754: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80133758: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8013375C: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80133760: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80133764: sb          $t3, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r11;
    // 0x80133768: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8013376C: sb          $t4, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r12;
    // 0x80133770: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x80133774: sb          $t5, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r13;
    // 0x80133778: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x8013377C: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80133780: lw          $t7, 0x58($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X58);
    // 0x80133784: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80133788: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x8013378C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80133790: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80133794: b           L_801337EC
    // 0x80133798: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
        goto L_801337EC;
    // 0x80133798: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
L_8013379C:
    // 0x8013379C: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x801337A0: beq         $at, $zero, L_801337D0
    if (ctx->r1 == 0) {
        // 0x801337A4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_801337D0;
    }
    // 0x801337A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801337A8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x801337AC: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x801337B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x801337B4: lui         $a2, 0x434D
    ctx->r6 = S32(0X434D << 16);
    // 0x801337B8: lui         $a3, 0x41B8
    ctx->r7 = S32(0X41B8 << 16);
    // 0x801337BC: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x801337C0: jal         0x801333D4
    // 0x801337C4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    mnPlayers1PGameMakeTimeNumber(rdram, ctx);
        goto after_2;
    // 0x801337C4: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_2:
    // 0x801337C8: b           L_801337F0
    // 0x801337CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801337F0;
    // 0x801337CC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801337D0:
    // 0x801337D0: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x801337D4: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x801337D8: lui         $a2, 0x4351
    ctx->r6 = S32(0X4351 << 16);
    // 0x801337DC: lui         $a3, 0x41B8
    ctx->r7 = S32(0X41B8 << 16);
    // 0x801337E0: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x801337E4: jal         0x801333D4
    // 0x801337E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    mnPlayers1PGameMakeTimeNumber(rdram, ctx);
        goto after_3;
    // 0x801337E8: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_3:
L_801337EC:
    // 0x801337EC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801337F0:
    // 0x801337F0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801337F4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x801337F8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x801337FC: jr          $ra
    // 0x80133800: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80133800: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void itLGunCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017568C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80175690: jal         0x80172FE0
    // 0x80175694: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x80175694: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    after_0:
    // 0x80175698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017569C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801756A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801756A4: jr          $ra
    // 0x801756A8: nop

    return;
    // 0x801756A8: nop

;}
RECOMP_FUNC void ftSamusSpecialNDestroyChargeShot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015D300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015D304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015D308: lw          $a1, 0xB20($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XB20);
    // 0x8015D30C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8015D310: beq         $a1, $zero, L_8015D328
    if (ctx->r5 == 0) {
        // 0x8015D314: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8015D328;
    }
    // 0x8015D314: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8015D318: jal         0x8016800C
    // 0x8015D31C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    wpMainDestroyWeapon(rdram, ctx);
        goto after_0;
    // 0x8015D31C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8015D320: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8015D324: sw          $zero, 0xB20($a2)
    MEM_W(0XB20, ctx->r6) = 0;
L_8015D328:
    // 0x8015D328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015D32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015D330: jr          $ra
    // 0x8015D334: nop

    return;
    // 0x8015D334: nop

;}
RECOMP_FUNC void itNBumperThrownProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B57C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B584: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017B588: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017B58C: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x8017B590: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017B594: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8017B598: swc1        $f0, 0x40($v1)
    MEM_W(0X40, ctx->r3) = ctx->f0.u32l;
    // 0x8017B59C: swc1        $f0, 0x44($v1)
    MEM_W(0X44, ctx->r3) = ctx->f0.u32l;
    // 0x8017B5A0: swc1        $f0, 0x48($v1)
    MEM_W(0X48, ctx->r3) = ctx->f0.u32l;
    // 0x8017B5A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017B5A8: sh          $t6, 0x350($v0)
    MEM_H(0X350, ctx->r2) = ctx->r14;
    // 0x8017B5AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017B5B0: lw          $t7, 0x80($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X80);
    // 0x8017B5B4: lui         $at, 0xC3C8
    ctx->r1 = S32(0XC3C8 << 16);
    // 0x8017B5B8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017B5BC: swc1        $f4, 0x88($t7)
    MEM_W(0X88, ctx->r15) = ctx->f4.u32l;
    // 0x8017B5C0: lw          $t8, 0x268($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X268);
    // 0x8017B5C4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8017B5C8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8017B5CC: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8017B5D0: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x8017B5D4: sh          $t9, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r25;
    // 0x8017B5D8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8017B5DC: swc1        $f18, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f18.u32l;
    // 0x8017B5E0: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017B5E4: jal         0x8017BEA0
    // 0x8017B5E8: swc1        $f16, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f16.u32l;
    itNBumperHitAirSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017B5E8: swc1        $f16, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f16.u32l;
    after_0:
    // 0x8017B5EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B5F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B5F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017B5F8: jr          $ra
    // 0x8017B5FC: nop

    return;
    // 0x8017B5FC: nop

;}
RECOMP_FUNC void ftCommonTaruCannSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143F30: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80143F34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80143F38: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80143F3C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80143F40: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80143F44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80143F48: jal         0x800E823C
    // 0x80143F4C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_0;
    // 0x80143F4C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80143F50: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    // 0x80143F54: beql        $v0, $zero, L_80143F94
    if (ctx->r2 == 0) {
        // 0x80143F58: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_80143F94;
    }
    goto skip_0;
    // 0x80143F58: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_0:
    // 0x80143F5C: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x80143F60: lbu         $t7, 0x2CE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2CE);
    // 0x80143F64: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80143F68: bnel        $t8, $zero, L_80143F94
    if (ctx->r24 != 0) {
        // 0x80143F6C: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_80143F94;
    }
    goto skip_1;
    // 0x80143F6C: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_1:
    // 0x80143F70: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80143F74: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80143F78: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80143F7C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80143F80: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80143F84: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80143F88: jal         0x80172AEC
    // 0x80143F8C: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_1;
    // 0x80143F8C: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    after_1:
    // 0x80143F90: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
L_80143F94:
    // 0x80143F94: beql        $a0, $zero, L_80143FB0
    if (ctx->r4 == 0) {
        // 0x80143F98: lw          $a0, 0x844($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X844);
            goto L_80143FB0;
    }
    goto skip_2;
    // 0x80143F98: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
    skip_2:
    // 0x80143F9C: jal         0x8014B330
    // 0x80143FA0: nop

    ftCommonThrownSetStatusDamageRelease(rdram, ctx);
        goto after_2;
    // 0x80143FA0: nop

    after_2:
    // 0x80143FA4: b           L_80143FC0
    // 0x80143FA8: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
        goto L_80143FC0;
    // 0x80143FA8: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    // 0x80143FAC: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
L_80143FB0:
    // 0x80143FB0: beql        $a0, $zero, L_80143FC4
    if (ctx->r4 == 0) {
        // 0x80143FB4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80143FC4;
    }
    goto skip_3;
    // 0x80143FB4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_3:
    // 0x80143FB8: jal         0x8014AECC
    // 0x80143FBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_3;
    // 0x80143FBC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_80143FC0:
    // 0x80143FC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80143FC4:
    // 0x80143FC4: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x80143FC8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80143FCC: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x80143FD0: jal         0x800E6F24
    // 0x80143FD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_4;
    // 0x80143FD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x80143FD8: jal         0x800E0830
    // 0x80143FDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_5;
    // 0x80143FDC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80143FE0: jal         0x800D9444
    // 0x80143FE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_6;
    // 0x80143FE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80143FE8: sw          $zero, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = 0;
    // 0x80143FEC: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x80143FF0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x80143FF4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80143FF8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80143FFC: jal         0x800E8A24
    // 0x80144000: sw          $t9, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r25;
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_7;
    // 0x80144000: sw          $t9, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r25;
    after_7:
    // 0x80144004: lbu         $t1, 0x18D($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X18D);
    // 0x80144008: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014400C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x80144010: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80144014: jal         0x800E8098
    // 0x80144018: sb          $t2, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r10;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_8;
    // 0x80144018: sb          $t2, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r10;
    after_8:
    // 0x8014401C: jal         0x800269C0
    // 0x80144020: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80144020: addiu       $a0, $zero, 0x11A
    ctx->r4 = ADD32(0, 0X11A);
    after_9:
    // 0x80144024: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80144028: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8014402C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80144030: jr          $ra
    // 0x80144034: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80144034: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void sc1PIntroMakeVSDecal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131ED4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131ED8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131EDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131EE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131EE4: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80131EE8: jal         0x80009968
    // 0x80131EEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131EEC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131EF0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131EF4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131EF8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131EFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131F00: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131F04: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131F08: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x80131F0C: jal         0x80009DF4
    // 0x80131F10: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131F10: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131F14: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131F18: lw          $t7, 0x6058($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6058);
    // 0x80131F1C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131F20: addiu       $t8, $t8, 0x1F10
    ctx->r24 = ADD32(ctx->r24, 0X1F10);
    // 0x80131F24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131F28: jal         0x800CCFDC
    // 0x80131F2C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131F2C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131F30: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131F34: lui         $at, 0x4307
    ctx->r1 = S32(0X4307 << 16);
    // 0x80131F38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131F3C: lui         $at, 0x42D0
    ctx->r1 = S32(0X42D0 << 16);
    // 0x80131F40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131F44: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131F48: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131F4C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131F50: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131F54: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131F58: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131F5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131F60: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131F64: jr          $ra
    // 0x80131F68: nop

    return;
    // 0x80131F68: nop

;}
RECOMP_FUNC void sc1PIntroGetFighterCObjDesc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133EE0: addiu       $sp, $sp, -0x7E0
    ctx->r29 = ADD32(ctx->r29, -0X7E0);
    // 0x80133EE4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133EE8: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80133EEC: addiu       $t6, $t6, 0x51F0
    ctx->r14 = ADD32(ctx->r14, 0X51F0);
    // 0x80133EF0: addiu       $t0, $t6, 0x7E0
    ctx->r8 = ADD32(ctx->r14, 0X7E0);
    // 0x80133EF4: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80133EF8:
    // 0x80133EF8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133EFC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133F00: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80133F04: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80133F08: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80133F0C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80133F10: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80133F14: bne         $t6, $t0, L_80133EF8
    if (ctx->r14 != ctx->r8) {
        // 0x80133F18: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80133EF8;
    }
    // 0x80133F18: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80133F1C: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x80133F20: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80133F24: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80133F28: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80133F2C: sll         $t3, $a2, 3
    ctx->r11 = S32(ctx->r6 << 3);
    // 0x80133F30: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x80133F34: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80133F38: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80133F3C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80133F40: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80133F44: lw          $t0, 0x0($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X0);
    // 0x80133F48: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80133F4C: sw          $t0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r8;
    // 0x80133F50: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x80133F54: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x80133F58: lw          $t0, 0x8($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X8);
    // 0x80133F5C: sw          $t0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r8;
    // 0x80133F60: lw          $t5, 0xC($t4)
    ctx->r13 = MEM_W(ctx->r12, 0XC);
    // 0x80133F64: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    // 0x80133F68: lw          $t0, 0x10($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X10);
    // 0x80133F6C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x80133F70: lw          $t5, 0x14($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X14);
    // 0x80133F74: sw          $t5, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r13;
    // 0x80133F78: lw          $t0, 0x18($t4)
    ctx->r8 = MEM_W(ctx->r12, 0X18);
    // 0x80133F7C: addiu       $sp, $sp, 0x7E0
    ctx->r29 = ADD32(ctx->r29, 0X7E0);
    // 0x80133F80: jr          $ra
    // 0x80133F84: sw          $t0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r8;
    return;
    // 0x80133F84: sw          $t0, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r8;
;}
RECOMP_FUNC void mvOpeningSamusFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE08: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE0C: addiu       $v0, $v0, -0x1D88
    ctx->r2 = ADD32(ctx->r2, -0X1D88);
    // 0x8018DE10: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8018DE14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DE18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DE1C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8018DE20: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8018DE24: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DE28: jal         0x8039076C
    // 0x8018DE2C: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x8018DE2C: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_0:
    // 0x8018DE30: beq         $v0, $zero, L_8018DE50
    if (ctx->r2 == 0) {
        // 0x8018DE34: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8018DE50;
    }
    // 0x8018DE34: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018DE38: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE3C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DE40: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DE44: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8018DE48: jal         0x80005C74
    // 0x8018DE4C: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x8018DE4C: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    after_1:
L_8018DE50:
    // 0x8018DE50: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE54: lw          $v0, -0x1D88($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1D88);
    // 0x8018DE58: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8018DE5C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DE60: bnel        $v0, $at, L_8018DE94
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE64: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_8018DE94;
    }
    goto skip_0;
    // 0x8018DE64: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_0:
    // 0x8018DE68: jal         0x80009A84
    // 0x8018DE6C: lw          $a0, -0x1D84($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1D84);
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x8018DE6C: lw          $a0, -0x1D84($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1D84);
    after_2:
    // 0x8018DE70: jal         0x8018D614
    // 0x8018DE74: nop

    mvOpeningSamusMakeMotionWindow(rdram, ctx);
        goto after_3;
    // 0x8018DE74: nop

    after_3:
    // 0x8018DE78: jal         0x8018D9AC
    // 0x8018DE7C: nop

    mvOpeningSamusMakePosedWallpaper(rdram, ctx);
        goto after_4;
    // 0x8018DE7C: nop

    after_4:
    // 0x8018DE80: jal         0x8018DAC8
    // 0x8018DE84: nop

    mvOpeningSamusMakePosedFighter(rdram, ctx);
        goto after_5;
    // 0x8018DE84: nop

    after_5:
    // 0x8018DE88: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018DE8C: lw          $v0, -0x1D88($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1D88);
    // 0x8018DE90: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_8018DE94:
    // 0x8018DE94: bne         $v0, $at, L_8018DEB4
    if (ctx->r2 != ctx->r1) {
        // 0x8018DE98: addiu       $t1, $zero, 0x23
        ctx->r9 = ADD32(0, 0X23);
            goto L_8018DEB4;
    }
    // 0x8018DE98: addiu       $t1, $zero, 0x23
    ctx->r9 = ADD32(0, 0X23);
    // 0x8018DE9C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DEA0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018DEA4: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x8018DEA8: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x8018DEAC: jal         0x80005C74
    // 0x8018DEB0: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_6;
    // 0x8018DEB0: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_6:
L_8018DEB4:
    // 0x8018DEB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018DEB8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018DEBC: jr          $ra
    // 0x8018DEC0: nop

    return;
    // 0x8018DEC0: nop

;}
RECOMP_FUNC void ftCommonLGunShootSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147258: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014725C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80147260: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80147264: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80147268: jal         0x800DEEC8
    // 0x8014726C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8014726C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80147270: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80147274: addiu       $a1, $zero, 0x8F
    ctx->r5 = ADD32(0, 0X8F);
    // 0x80147278: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014727C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80147280: jal         0x800E6F24
    // 0x80147284: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80147284: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80147288: jal         0x800D8EB8
    // 0x8014728C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x8014728C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x80147290: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80147294: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80147298: addiu       $t7, $t7, 0x6FD4
    ctx->r15 = ADD32(ctx->r15, 0X6FD4);
    // 0x8014729C: sw          $t7, 0x9D8($t8)
    MEM_W(0X9D8, ctx->r24) = ctx->r15;
    // 0x801472A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801472A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801472A8: jr          $ra
    // 0x801472AC: nop

    return;
    // 0x801472AC: nop

;}
RECOMP_FUNC void itTaruFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179BA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80179BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179BA8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80179BAC: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80179BB0: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x80179BB4: lui         $a2, 0x42B4
    ctx->r6 = S32(0X42B4 << 16);
    // 0x80179BB8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80179BBC: jal         0x80172558
    // 0x80179BC0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80179BC0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80179BC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80179BC8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80179BCC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80179BD0: lwc1        $f6, 0x350($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X350);
    // 0x80179BD4: lwc1        $f4, 0x38($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X38);
    // 0x80179BD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80179BDC: jal         0x801713F4
    // 0x80179BE0: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80179BE0: swc1        $f8, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->f8.u32l;
    after_1:
    // 0x80179BE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179BE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80179BEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80179BF0: jr          $ra
    // 0x80179BF4: nop

    return;
    // 0x80179BF4: nop

;}
RECOMP_FUNC void ftKirbyThrowFFallSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A4A8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014A4AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014A4B0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014A4B4: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8014A4B8: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x8014A4BC: lw          $v1, 0x840($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X840);
    // 0x8014A4C0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014A4C4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014A4C8: lw          $t0, 0x84($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X84);
    // 0x8014A4CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8014A4D0: jal         0x800E6F24
    // 0x8014A4D4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014A4D4: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    after_0:
    // 0x8014A4D8: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8014A4DC: lbu         $t7, 0x192($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X192);
    // 0x8014A4E0: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x8014A4E4: sb          $t8, 0x192($t0)
    MEM_B(0X192, ctx->r8) = ctx->r24;
    // 0x8014A4E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014A4EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014A4F0: jr          $ra
    // 0x8014A4F4: nop

    return;
    // 0x8014A4F4: nop

;}
RECOMP_FUNC void mnVSResultsGetWorstMan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138130: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80138134: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80138138: addiu       $v1, $v1, 0x4D08
    ctx->r3 = ADD32(ctx->r3, 0X4D08);
    // 0x8013813C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80138140: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80138144: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80138148:
    // 0x80138148: lbu         $t6, 0x22($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X22);
    // 0x8013814C: bnel        $t6, $zero, L_80138160
    if (ctx->r14 != 0) {
        // 0x80138150: sw          $zero, 0x0($a0)
        MEM_W(0X0, ctx->r4) = 0;
            goto L_80138160;
    }
    goto skip_0;
    // 0x80138150: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    skip_0:
    // 0x80138154: b           L_80138160
    // 0x80138158: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
        goto L_80138160;
    // 0x80138158: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x8013815C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_80138160:
    // 0x80138160: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80138164: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x80138168: bne         $at, $zero, L_80138148
    if (ctx->r1 != 0) {
        // 0x8013816C: addiu       $v1, $v1, 0x74
        ctx->r3 = ADD32(ctx->r3, 0X74);
            goto L_80138148;
    }
    // 0x8013816C: addiu       $v1, $v1, 0x74
    ctx->r3 = ADD32(ctx->r3, 0X74);
    // 0x80138170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80138174: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
L_80138178:
    // 0x80138178: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8013817C: beql        $t7, $zero, L_80138190
    if (ctx->r15 == 0) {
        // 0x80138180: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80138190;
    }
    goto skip_1;
    // 0x80138180: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_1:
    // 0x80138184: b           L_801381A0
    // 0x80138188: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_801381A0;
    // 0x80138188: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8013818C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80138190:
    // 0x80138190: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x80138194: bne         $at, $zero, L_80138178
    if (ctx->r1 != 0) {
        // 0x80138198: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80138178;
    }
    // 0x80138198: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8013819C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
L_801381A0:
    // 0x801381A0: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x801381A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801381A8: beq         $at, $zero, L_80138314
    if (ctx->r1 == 0) {
        // 0x801381AC: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80138314;
    }
    // 0x801381AC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x801381B0: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x801381B4: subu        $a3, $t2, $a1
    ctx->r7 = SUB32(ctx->r10, ctx->r5);
    // 0x801381B8: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x801381BC: beq         $a3, $zero, L_80138220
    if (ctx->r7 == 0) {
        // 0x801381C0: addu        $t1, $a3, $a1
        ctx->r9 = ADD32(ctx->r7, ctx->r5);
            goto L_80138220;
    }
    // 0x801381C0: addu        $t1, $a3, $a1
    ctx->r9 = ADD32(ctx->r7, ctx->r5);
    // 0x801381C4: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x801381C8: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x801381CC: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801381D0: addiu       $t3, $t3, -0x6460
    ctx->r11 = ADD32(ctx->r11, -0X6460);
    // 0x801381D4: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
L_801381D8:
    // 0x801381D8: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801381DC: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x801381E0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801381E4: beq         $t9, $zero, L_80138210
    if (ctx->r25 == 0) {
        // 0x801381E8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80138210;
    }
    // 0x801381E8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801381EC: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x801381F0: lw          $t0, 0x0($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X0);
    // 0x801381F4: lw          $a3, 0x0($t5)
    ctx->r7 = MEM_W(ctx->r13, 0X0);
    // 0x801381F8: bne         $a3, $t0, L_80138204
    if (ctx->r7 != ctx->r8) {
        // 0x801381FC: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80138204;
    }
    // 0x801381FC: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80138200: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80138204:
    // 0x80138204: beql        $at, $zero, L_80138214
    if (ctx->r1 == 0) {
        // 0x80138208: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80138214;
    }
    goto skip_2;
    // 0x80138208: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_2:
    // 0x8013820C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80138210:
    // 0x80138210: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80138214:
    // 0x80138214: bne         $t1, $v0, L_801381D8
    if (ctx->r9 != ctx->r2) {
        // 0x80138218: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801381D8;
    }
    // 0x80138218: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8013821C: beq         $v0, $t2, L_80138314
    if (ctx->r2 == ctx->r10) {
        // 0x80138220: lui         $t3, 0x8014
        ctx->r11 = S32(0X8014 << 16);
            goto L_80138314;
    }
L_80138220:
    // 0x80138220: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80138224: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80138228: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x8013822C: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x80138230: addiu       $t3, $t3, -0x6460
    ctx->r11 = ADD32(ctx->r11, -0X6460);
L_80138234:
    // 0x80138234: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80138238: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8013823C: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x80138240: beq         $t8, $zero, L_80138268
    if (ctx->r24 == 0) {
        // 0x80138244: addu        $t5, $t3, $v1
        ctx->r13 = ADD32(ctx->r11, ctx->r3);
            goto L_80138268;
    }
    // 0x80138244: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x80138248: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x8013824C: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x80138250: bne         $a3, $t0, L_8013825C
    if (ctx->r7 != ctx->r8) {
        // 0x80138254: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8013825C;
    }
    // 0x80138254: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80138258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8013825C:
    // 0x8013825C: beql        $at, $zero, L_8013826C
    if (ctx->r1 == 0) {
        // 0x80138260: lw          $t6, 0x4($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X4);
            goto L_8013826C;
    }
    goto skip_3;
    // 0x80138260: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    skip_3:
    // 0x80138264: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80138268:
    // 0x80138268: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
L_8013826C:
    // 0x8013826C: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x80138270: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80138274: beq         $t6, $zero, L_8013829C
    if (ctx->r14 == 0) {
        // 0x80138278: addu        $t9, $t3, $v1
        ctx->r25 = ADD32(ctx->r11, ctx->r3);
            goto L_8013829C;
    }
    // 0x80138278: addu        $t9, $t3, $v1
    ctx->r25 = ADD32(ctx->r11, ctx->r3);
    // 0x8013827C: lw          $a3, 0x0($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X0);
    // 0x80138280: lw          $t0, 0x4($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X4);
    // 0x80138284: bne         $a3, $t0, L_80138290
    if (ctx->r7 != ctx->r8) {
        // 0x80138288: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_80138290;
    }
    // 0x80138288: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8013828C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80138290:
    // 0x80138290: beql        $at, $zero, L_801382A0
    if (ctx->r1 == 0) {
        // 0x80138294: lw          $t4, 0x8($a0)
        ctx->r12 = MEM_W(ctx->r4, 0X8);
            goto L_801382A0;
    }
    goto skip_4;
    // 0x80138294: lw          $t4, 0x8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X8);
    skip_4:
    // 0x80138298: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
L_8013829C:
    // 0x8013829C: lw          $t4, 0x8($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X8);
L_801382A0:
    // 0x801382A0: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x801382A4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x801382A8: beq         $t4, $zero, L_801382D0
    if (ctx->r12 == 0) {
        // 0x801382AC: addu        $t7, $t3, $v1
        ctx->r15 = ADD32(ctx->r11, ctx->r3);
            goto L_801382D0;
    }
    // 0x801382AC: addu        $t7, $t3, $v1
    ctx->r15 = ADD32(ctx->r11, ctx->r3);
    // 0x801382B0: lw          $a3, 0x0($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X0);
    // 0x801382B4: lw          $t0, 0x8($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X8);
    // 0x801382B8: bne         $a3, $t0, L_801382C4
    if (ctx->r7 != ctx->r8) {
        // 0x801382BC: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_801382C4;
    }
    // 0x801382BC: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801382C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_801382C4:
    // 0x801382C4: beql        $at, $zero, L_801382D4
    if (ctx->r1 == 0) {
        // 0x801382C8: lw          $t8, 0xC($a0)
        ctx->r24 = MEM_W(ctx->r4, 0XC);
            goto L_801382D4;
    }
    goto skip_5;
    // 0x801382C8: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
    skip_5:
    // 0x801382CC: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
L_801382D0:
    // 0x801382D0: lw          $t8, 0xC($a0)
    ctx->r24 = MEM_W(ctx->r4, 0XC);
L_801382D4:
    // 0x801382D4: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x801382D8: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x801382DC: beq         $t8, $zero, L_80138308
    if (ctx->r24 == 0) {
        // 0x801382E0: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80138308;
    }
    // 0x801382E0: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x801382E4: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x801382E8: lw          $t0, 0xC($t5)
    ctx->r8 = MEM_W(ctx->r13, 0XC);
    // 0x801382EC: lw          $a3, 0x0($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X0);
    // 0x801382F0: bne         $a3, $t0, L_801382FC
    if (ctx->r7 != ctx->r8) {
        // 0x801382F4: slt         $at, $t0, $a3
        ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_801382FC;
    }
    // 0x801382F4: slt         $at, $t0, $a3
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801382F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_801382FC:
    // 0x801382FC: beql        $at, $zero, L_8013830C
    if (ctx->r1 == 0) {
        // 0x80138300: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8013830C;
    }
    goto skip_6;
    // 0x80138300: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_6:
    // 0x80138304: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
L_80138308:
    // 0x80138308: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8013830C:
    // 0x8013830C: bne         $v0, $t2, L_80138234
    if (ctx->r2 != ctx->r10) {
        // 0x80138310: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80138234;
    }
    // 0x80138310: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80138314:
    // 0x80138314: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x80138318: addiu       $t3, $t3, -0x6460
    ctx->r11 = ADD32(ctx->r11, -0X6460);
    // 0x8013831C: beq         $a2, $zero, L_8013853C
    if (ctx->r6 == 0) {
        // 0x80138320: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_8013853C;
    }
    // 0x80138320: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80138324: slti        $at, $a1, 0x4
    ctx->r1 = SIGNED(ctx->r5) < 0X4 ? 1 : 0;
    // 0x80138328: beq         $at, $zero, L_8013853C
    if (ctx->r1 == 0) {
        // 0x8013832C: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_8013853C;
    }
    // 0x8013832C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80138330: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80138334: subu        $a3, $t6, $a1
    ctx->r7 = SUB32(ctx->r14, ctx->r5);
    // 0x80138338: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x8013833C: beq         $a3, $zero, L_801383C4
    if (ctx->r7 == 0) {
        // 0x80138340: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_801383C4;
    }
    // 0x80138340: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
    // 0x80138344: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x80138348: addiu       $t7, $sp, 0x24
    ctx->r15 = ADD32(ctx->r29, 0X24);
    // 0x8013834C: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x80138350: addiu       $a3, $a3, 0x4D08
    ctx->r7 = ADD32(ctx->r7, 0X4D08);
    // 0x80138354: addu        $a0, $v1, $t7
    ctx->r4 = ADD32(ctx->r3, ctx->r15);
    // 0x80138358: addiu       $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
L_8013835C:
    // 0x8013835C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80138360: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80138364: addu        $t4, $t3, $t9
    ctx->r12 = ADD32(ctx->r11, ctx->r25);
    // 0x80138368: beq         $t8, $zero, L_801383B4
    if (ctx->r24 == 0) {
        // 0x8013836C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_801383B4;
    }
    // 0x8013836C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80138370: addu        $t6, $t3, $v1
    ctx->r14 = ADD32(ctx->r11, ctx->r3);
    // 0x80138374: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80138378: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x8013837C: bnel        $t5, $t7, L_801383B8
    if (ctx->r13 != ctx->r15) {
        // 0x80138380: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801383B8;
    }
    goto skip_7;
    // 0x80138380: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_7:
    // 0x80138384: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138388: mflo        $t8
    ctx->r24 = lo;
    // 0x8013838C: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x80138390: lbu         $t4, 0x21($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0X21);
    // 0x80138394: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138398: mflo        $t6
    ctx->r14 = lo;
    // 0x8013839C: addu        $t5, $a3, $t6
    ctx->r13 = ADD32(ctx->r7, ctx->r14);
    // 0x801383A0: lbu         $t7, 0x21($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X21);
    // 0x801383A4: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801383A8: beql        $at, $zero, L_801383B8
    if (ctx->r1 == 0) {
        // 0x801383AC: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_801383B8;
    }
    goto skip_8;
    // 0x801383AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_8:
    // 0x801383B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_801383B4:
    // 0x801383B4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_801383B8:
    // 0x801383B8: bne         $a2, $v0, L_8013835C
    if (ctx->r6 != ctx->r2) {
        // 0x801383BC: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8013835C;
    }
    // 0x801383BC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801383C0: beq         $v0, $t2, L_8013853C
    if (ctx->r2 == ctx->r10) {
        // 0x801383C4: lui         $a3, 0x800A
        ctx->r7 = S32(0X800A << 16);
            goto L_8013853C;
    }
L_801383C4:
    // 0x801383C4: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x801383C8: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x801383CC: addiu       $t8, $sp, 0x24
    ctx->r24 = ADD32(ctx->r29, 0X24);
    // 0x801383D0: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
    // 0x801383D4: addiu       $a3, $a3, 0x4D08
    ctx->r7 = ADD32(ctx->r7, 0X4D08);
    // 0x801383D8: addiu       $t0, $zero, 0x74
    ctx->r8 = ADD32(0, 0X74);
L_801383DC:
    // 0x801383DC: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801383E0: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801383E4: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x801383E8: beq         $t9, $zero, L_80138430
    if (ctx->r25 == 0) {
        // 0x801383EC: addu        $t7, $t3, $v1
        ctx->r15 = ADD32(ctx->r11, ctx->r3);
            goto L_80138430;
    }
    // 0x801383EC: addu        $t7, $t3, $v1
    ctx->r15 = ADD32(ctx->r11, ctx->r3);
    // 0x801383F0: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x801383F4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801383F8: bnel        $t4, $t8, L_80138434
    if (ctx->r12 != ctx->r24) {
        // 0x801383FC: lw          $t9, 0x4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X4);
            goto L_80138434;
    }
    goto skip_9;
    // 0x801383FC: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    skip_9:
    // 0x80138400: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138404: mflo        $t9
    ctx->r25 = lo;
    // 0x80138408: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x8013840C: lbu         $t5, 0x21($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X21);
    // 0x80138410: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138414: mflo        $t7
    ctx->r15 = lo;
    // 0x80138418: addu        $t4, $a3, $t7
    ctx->r12 = ADD32(ctx->r7, ctx->r15);
    // 0x8013841C: lbu         $t8, 0x21($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X21);
    // 0x80138420: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80138424: beql        $at, $zero, L_80138434
    if (ctx->r1 == 0) {
        // 0x80138428: lw          $t9, 0x4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X4);
            goto L_80138434;
    }
    goto skip_10;
    // 0x80138428: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    skip_10:
    // 0x8013842C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80138430:
    // 0x80138430: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
L_80138434:
    // 0x80138434: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80138438: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x8013843C: beq         $t9, $zero, L_80138484
    if (ctx->r25 == 0) {
        // 0x80138440: addu        $t5, $t3, $v1
        ctx->r13 = ADD32(ctx->r11, ctx->r3);
            goto L_80138484;
    }
    // 0x80138440: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x80138444: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80138448: lw          $t8, 0x4($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X4);
    // 0x8013844C: bnel        $t4, $t8, L_80138488
    if (ctx->r12 != ctx->r24) {
        // 0x80138450: lw          $t9, 0x8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X8);
            goto L_80138488;
    }
    goto skip_11;
    // 0x80138450: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    skip_11:
    // 0x80138454: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138458: mflo        $t9
    ctx->r25 = lo;
    // 0x8013845C: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x80138460: lbu         $t7, 0x95($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X95);
    // 0x80138464: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138468: mflo        $t5
    ctx->r13 = lo;
    // 0x8013846C: addu        $t4, $a3, $t5
    ctx->r12 = ADD32(ctx->r7, ctx->r13);
    // 0x80138470: lbu         $t8, 0x21($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X21);
    // 0x80138474: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80138478: beql        $at, $zero, L_80138488
    if (ctx->r1 == 0) {
        // 0x8013847C: lw          $t9, 0x8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X8);
            goto L_80138488;
    }
    goto skip_12;
    // 0x8013847C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    skip_12:
    // 0x80138480: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
L_80138484:
    // 0x80138484: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
L_80138488:
    // 0x80138488: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x8013848C: addu        $t5, $t3, $t6
    ctx->r13 = ADD32(ctx->r11, ctx->r14);
    // 0x80138490: beq         $t9, $zero, L_801384D8
    if (ctx->r25 == 0) {
        // 0x80138494: addu        $t7, $t3, $v1
        ctx->r15 = ADD32(ctx->r11, ctx->r3);
            goto L_801384D8;
    }
    // 0x80138494: addu        $t7, $t3, $v1
    ctx->r15 = ADD32(ctx->r11, ctx->r3);
    // 0x80138498: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8013849C: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x801384A0: bnel        $t4, $t8, L_801384DC
    if (ctx->r12 != ctx->r24) {
        // 0x801384A4: lw          $t9, 0xC($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XC);
            goto L_801384DC;
    }
    goto skip_13;
    // 0x801384A4: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    skip_13:
    // 0x801384A8: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801384AC: mflo        $t9
    ctx->r25 = lo;
    // 0x801384B0: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x801384B4: lbu         $t5, 0x109($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X109);
    // 0x801384B8: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801384BC: mflo        $t7
    ctx->r15 = lo;
    // 0x801384C0: addu        $t4, $a3, $t7
    ctx->r12 = ADD32(ctx->r7, ctx->r15);
    // 0x801384C4: lbu         $t8, 0x21($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X21);
    // 0x801384C8: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801384CC: beql        $at, $zero, L_801384DC
    if (ctx->r1 == 0) {
        // 0x801384D0: lw          $t9, 0xC($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XC);
            goto L_801384DC;
    }
    goto skip_14;
    // 0x801384D0: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    skip_14:
    // 0x801384D4: addiu       $a1, $v0, 0x2
    ctx->r5 = ADD32(ctx->r2, 0X2);
L_801384D8:
    // 0x801384D8: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
L_801384DC:
    // 0x801384DC: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x801384E0: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x801384E4: beq         $t9, $zero, L_80138530
    if (ctx->r25 == 0) {
        // 0x801384E8: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80138530;
    }
    // 0x801384E8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x801384EC: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x801384F0: lw          $t8, 0xC($t5)
    ctx->r24 = MEM_W(ctx->r13, 0XC);
    // 0x801384F4: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x801384F8: bnel        $t4, $t8, L_80138534
    if (ctx->r12 != ctx->r24) {
        // 0x801384FC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80138534;
    }
    goto skip_15;
    // 0x801384FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_15:
    // 0x80138500: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138504: mflo        $t9
    ctx->r25 = lo;
    // 0x80138508: addu        $t6, $a3, $t9
    ctx->r14 = ADD32(ctx->r7, ctx->r25);
    // 0x8013850C: lbu         $t7, 0x17D($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X17D);
    // 0x80138510: multu       $a1, $t0
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138514: mflo        $t5
    ctx->r13 = lo;
    // 0x80138518: addu        $t4, $a3, $t5
    ctx->r12 = ADD32(ctx->r7, ctx->r13);
    // 0x8013851C: lbu         $t8, 0x21($t4)
    ctx->r24 = MEM_BU(ctx->r12, 0X21);
    // 0x80138520: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80138524: beql        $at, $zero, L_80138534
    if (ctx->r1 == 0) {
        // 0x80138528: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80138534;
    }
    goto skip_16;
    // 0x80138528: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    skip_16:
    // 0x8013852C: addiu       $a1, $v0, 0x3
    ctx->r5 = ADD32(ctx->r2, 0X3);
L_80138530:
    // 0x80138530: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80138534:
    // 0x80138534: bne         $v0, $t2, L_801383DC
    if (ctx->r2 != ctx->r10) {
        // 0x80138538: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_801383DC;
    }
    // 0x80138538: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_8013853C:
    // 0x8013853C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80138540: jr          $ra
    // 0x80138544: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80138544: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_ovl8_803761F4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803761F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803761F8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803761FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80376200: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80376204: beq         $a0, $zero, L_80376298
    if (ctx->r4 == 0) {
        // 0x80376208: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80376298;
    }
    // 0x80376208: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037620C: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x80376210: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80376214: addiu       $t6, $t6, -0x6610
    ctx->r14 = ADD32(ctx->r14, -0X6610);
    // 0x80376218: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037621C: addiu       $t7, $t7, -0x6558
    ctx->r15 = ADD32(ctx->r15, -0X6558);
    // 0x80376220: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80376224: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80376228: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x8037622C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80376230: addiu       $t9, $t9, -0x6400
    ctx->r25 = ADD32(ctx->r25, -0X6400);
    // 0x80376234: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x80376238: addiu       $t1, $t1, -0x63D8
    ctx->r9 = ADD32(ctx->r9, -0X63D8);
    // 0x8037623C: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x80376240: addiu       $a0, $a0, 0x38
    ctx->r4 = ADD32(ctx->r4, 0X38);
    // 0x80376244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80376248: jal         0x803720D4
    // 0x8037624C: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    func_ovl8_803720D4(rdram, ctx);
        goto after_0;
    // 0x8037624C: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    after_0:
    // 0x80376250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80376254: jal         0x8037295C
    // 0x80376258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037295C(rdram, ctx);
        goto after_1;
    // 0x80376258: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8037625C: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80376260: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80376264: beql        $t2, $zero, L_80376284
    if (ctx->r10 == 0) {
        // 0x80376268: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80376284;
    }
    goto skip_0;
    // 0x80376268: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8037626C: jal         0x8037C30C
    // 0x80376270: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_2;
    // 0x80376270: lw          $a0, 0x1C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X1C);
    after_2:
    // 0x80376274: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x80376278: jal         0x803718C4
    // 0x8037627C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_3;
    // 0x8037627C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x80376280: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_80376284:
    // 0x80376284: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80376288: beql        $t4, $zero, L_8037629C
    if (ctx->r12 == 0) {
        // 0x8037628C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037629C;
    }
    goto skip_1;
    // 0x8037628C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80376290: jal         0x803717C0
    // 0x80376294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_4;
    // 0x80376294: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_80376298:
    // 0x80376298: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037629C:
    // 0x8037629C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803762A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803762A4: jr          $ra
    // 0x803762A8: nop

    return;
    // 0x803762A8: nop

;}
RECOMP_FUNC void sc1PIntroMakeBanners(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BA8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131BAC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131BB0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131BB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131BB8: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x80131BBC: jal         0x80009968
    // 0x80131BC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131BC0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131BC4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131BC8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131BCC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131BD0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131BD4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131BD8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131BDC: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80131BE0: jal         0x80009DF4
    // 0x80131BE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131BE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131BE8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131BEC: lw          $t7, 0x6058($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6058);
    // 0x80131BF0: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80131BF4: addiu       $t8, $t8, -0x3768
    ctx->r24 = ADD32(ctx->r24, -0X3768);
    // 0x80131BF8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131BFC: jal         0x800CCFDC
    // 0x80131C00: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131C00: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131C04: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131C08: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131C0C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131C10: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80131C14: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131C18: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80131C1C: lw          $t9, 0x6058($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6058);
    // 0x80131C20: addiu       $t0, $t0, -0x1300
    ctx->r8 = ADD32(ctx->r8, -0X1300);
    // 0x80131C24: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131C28: jal         0x800CCFDC
    // 0x80131C2C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131C2C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80131C30: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131C34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131C38: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x80131C3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131C40: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131C44: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131C48: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131C4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131C50: jr          $ra
    // 0x80131C54: nop

    return;
    // 0x80131C54: nop

;}
RECOMP_FUNC void gcPlayMObjMatAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000DA40: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000DA44: sdc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X20, ctx->r29);
    // 0x8000DA48: sdc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X18, ctx->r29);
    // 0x8000DA4C: sdc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X10, ctx->r29);
    // 0x8000DA50: sdc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X8, ctx->r29);
    // 0x8000DA54: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000DA58: lwc1        $f4, -0x2124($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2124);
    // 0x8000DA5C: lwc1        $f0, 0x98($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X98);
    // 0x8000DA60: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8000DA64: nop

    // 0x8000DA68: bc1tl       L_8000DF20
    if (c1cs) {
        // 0x8000DA6C: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8000DF20;
    }
    goto skip_0;
    // 0x8000DA6C: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_0:
    // 0x8000DA70: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x8000DA74: lwc1        $f26, 0x64($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000DA78: addiu       $t3, $zero, 0x100
    ctx->r11 = ADD32(0, 0X100);
    // 0x8000DA7C: beq         $v0, $zero, L_8000DEF8
    if (ctx->r2 == 0) {
        // 0x8000DA80: addiu       $t2, $sp, 0x44
        ctx->r10 = ADD32(ctx->r29, 0X44);
            goto L_8000DEF8;
    }
    // 0x8000DA80: addiu       $t2, $sp, 0x44
    ctx->r10 = ADD32(ctx->r29, 0X44);
    // 0x8000DA84: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8000DA88: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8000DA8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000DA90: lbu         $v1, 0x5($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5);
L_8000DA94:
    // 0x8000DA94: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000DA98: beql        $v1, $zero, L_8000DEE8
    if (ctx->r3 == 0) {
        // 0x8000DA9C: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_8000DEE8;
    }
    goto skip_1;
    // 0x8000DA9C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x8000DAA0: lwc1        $f6, -0x2120($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2120);
    // 0x8000DAA4: lwc1        $f8, 0x98($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X98);
    // 0x8000DAA8: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8000DAAC: nop

    // 0x8000DAB0: bc1tl       L_8000DAD0
    if (c1cs) {
        // 0x8000DAB4: lbu         $a1, 0x4($v0)
        ctx->r5 = MEM_BU(ctx->r2, 0X4);
            goto L_8000DAD0;
    }
    goto skip_2;
    // 0x8000DAB4: lbu         $a1, 0x4($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X4);
    skip_2:
    // 0x8000DAB8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000DABC: lwc1        $f4, 0x9C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X9C);
    // 0x8000DAC0: lbu         $v1, 0x5($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5);
    // 0x8000DAC4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8000DAC8: swc1        $f6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f6.u32l;
    // 0x8000DACC: lbu         $a1, 0x4($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X4);
L_8000DAD0:
    // 0x8000DAD0: slti        $at, $a1, 0x24
    ctx->r1 = SIGNED(ctx->r5) < 0X24 ? 1 : 0;
    // 0x8000DAD4: beq         $at, $zero, L_8000DD3C
    if (ctx->r1 == 0) {
        // 0x8000DAD8: addiu       $t6, $a1, -0xD
        ctx->r14 = ADD32(ctx->r5, -0XD);
            goto L_8000DD3C;
    }
    // 0x8000DAD8: addiu       $t6, $a1, -0xD
    ctx->r14 = ADD32(ctx->r5, -0XD);
    // 0x8000DADC: beql        $v1, $a3, L_8000DBAC
    if (ctx->r3 == ctx->r7) {
        // 0x8000DAE0: lwc1        $f8, 0xC($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
            goto L_8000DBAC;
    }
    goto skip_3;
    // 0x8000DAE0: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    skip_3:
    // 0x8000DAE4: beql        $v1, $t0, L_8000DB00
    if (ctx->r3 == ctx->r8) {
        // 0x8000DAE8: lwc1        $f8, 0xC($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
            goto L_8000DB00;
    }
    goto skip_4;
    // 0x8000DAE8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    skip_4:
    // 0x8000DAEC: beql        $v1, $t1, L_8000DB18
    if (ctx->r3 == ctx->r9) {
        // 0x8000DAF0: lwc1        $f2, 0x8($v0)
        ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
            goto L_8000DB18;
    }
    goto skip_5;
    // 0x8000DAF0: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
    skip_5:
    // 0x8000DAF4: b           L_8000DBD0
    // 0x8000DAF8: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
        goto L_8000DBD0;
    // 0x8000DAF8: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
    // 0x8000DAFC: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
L_8000DB00:
    // 0x8000DB00: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8000DB04: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000DB08: mul.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000DB0C: b           L_8000DBCC
    // 0x8000DB10: add.s       $f26, $f6, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f4.fl;
        goto L_8000DBCC;
    // 0x8000DB10: add.s       $f26, $f6, $f4
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f26.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000DB14: lwc1        $f2, 0x8($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X8);
L_8000DB18:
    // 0x8000DB18: lwc1        $f0, 0xC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000DB1C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8000DB20: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000DB24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000DB28: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000DB2C: mul.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000DB30: nop

    // 0x8000DB34: mul.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x8000DB38: nop

    // 0x8000DB3C: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x8000DB40: nop

    // 0x8000DB44: mul.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000DB48: add.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x8000DB4C: sub.s       $f24, $f14, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x8000DB50: mul.s       $f20, $f10, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8000DB54: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000DB58: mul.s       $f4, $f6, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8000DB5C: nop

    // 0x8000DB60: mul.s       $f22, $f4, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x8000DB64: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8000DB68: sub.s       $f8, $f20, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x8000DB6C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000DB70: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000DB74: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000DB78: sub.s       $f4, $f22, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f22.fl - ctx->f20.fl;
    // 0x8000DB7C: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000DB80: lwc1        $f4, 0x18($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X18);
    // 0x8000DB84: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x8000DB88: sub.s       $f8, $f24, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f24.fl - ctx->f18.fl;
    // 0x8000DB8C: add.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8000DB90: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8000DB94: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000DB98: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x8000DB9C: mul.s       $f10, $f6, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x8000DBA0: b           L_8000DBCC
    // 0x8000DBA4: add.s       $f26, $f4, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f4.fl + ctx->f10.fl;
        goto L_8000DBCC;
    // 0x8000DBA4: add.s       $f26, $f4, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f26.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8000DBA8: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
L_8000DBAC:
    // 0x8000DBAC: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000DBB0: c.le.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl <= ctx->f8.fl;
    // 0x8000DBB4: nop

    // 0x8000DBB8: bc1fl       L_8000DBCC
    if (!c1cs) {
        // 0x8000DBBC: lwc1        $f26, 0x10($v0)
        ctx->f26.u32l = MEM_W(ctx->r2, 0X10);
            goto L_8000DBCC;
    }
    goto skip_6;
    // 0x8000DBBC: lwc1        $f26, 0x10($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X10);
    skip_6:
    // 0x8000DBC0: b           L_8000DBCC
    // 0x8000DBC4: lwc1        $f26, 0x14($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X14);
        goto L_8000DBCC;
    // 0x8000DBC4: lwc1        $f26, 0x14($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8000DBC8: lwc1        $f26, 0x10($v0)
    ctx->f26.u32l = MEM_W(ctx->r2, 0X10);
L_8000DBCC:
    // 0x8000DBCC: sltiu       $at, $t6, 0xA
    ctx->r1 = ctx->r14 < 0XA ? 1 : 0;
L_8000DBD0:
    // 0x8000DBD0: beq         $at, $zero, L_8000DEE4
    if (ctx->r1 == 0) {
        // 0x8000DBD4: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8000DEE4;
    }
    // 0x8000DBD4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000DBD8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000DBDC: addu        $at, $at, $t6
    gpr jr_addend_8000DBE4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000DBE0: lw          $t6, -0x211C($at)
    ctx->r14 = ADD32(ctx->r1, -0X211C);
    // 0x8000DBE4: jr          $t6
    // 0x8000DBE8: nop

    switch (jr_addend_8000DBE4 >> 2) {
        case 0: goto L_8000DBEC; break;
        case 1: goto L_8000DC74; break;
        case 2: goto L_8000DC7C; break;
        case 3: goto L_8000DC84; break;
        case 4: goto L_8000DC8C; break;
        case 5: goto L_8000DC94; break;
        case 6: goto L_8000DD1C; break;
        case 7: goto L_8000DD24; break;
        case 8: goto L_8000DD2C; break;
        case 9: goto L_8000DD34; break;
        default: switch_error(__func__, 0x8000DBE4, 0x8003DEE4);
    }
    // 0x8000DBE8: nop

L_8000DBEC:
    // 0x8000DBEC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000DBF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000DBF4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000DBF8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000DBFC: cvt.w.s     $f4, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    ctx->f4.u32l = CVT_W_S(ctx->f26.fl);
    // 0x8000DC00: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000DC04: nop

    // 0x8000DC08: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8000DC0C: beql        $t8, $zero, L_8000DC5C
    if (ctx->r24 == 0) {
        // 0x8000DC10: mfc1        $t8, $f4
        ctx->r24 = (int32_t)ctx->f4.u32l;
            goto L_8000DC5C;
    }
    goto skip_7;
    // 0x8000DC10: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    skip_7:
    // 0x8000DC14: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000DC18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000DC1C: sub.s       $f4, $f26, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f26.fl - ctx->f4.fl;
    // 0x8000DC20: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000DC24: nop

    // 0x8000DC28: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000DC2C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000DC30: nop

    // 0x8000DC34: andi        $t8, $t8, 0x78
    ctx->r24 = ctx->r24 & 0X78;
    // 0x8000DC38: bne         $t8, $zero, L_8000DC50
    if (ctx->r24 != 0) {
        // 0x8000DC3C: nop
    
            goto L_8000DC50;
    }
    // 0x8000DC3C: nop

    // 0x8000DC40: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x8000DC44: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000DC48: b           L_8000DC68
    // 0x8000DC4C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
        goto L_8000DC68;
    // 0x8000DC4C: or          $t8, $t8, $at
    ctx->r24 = ctx->r24 | ctx->r1;
L_8000DC50:
    // 0x8000DC50: b           L_8000DC68
    // 0x8000DC54: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
        goto L_8000DC68;
    // 0x8000DC54: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8000DC58: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
L_8000DC5C:
    // 0x8000DC5C: nop

    // 0x8000DC60: bltz        $t8, L_8000DC50
    if (SIGNED(ctx->r24) < 0) {
        // 0x8000DC64: nop
    
            goto L_8000DC50;
    }
    // 0x8000DC64: nop

L_8000DC68:
    // 0x8000DC68: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000DC6C: b           L_8000DEE4
    // 0x8000DC70: sh          $t8, 0x80($a0)
    MEM_H(0X80, ctx->r4) = ctx->r24;
        goto L_8000DEE4;
    // 0x8000DC70: sh          $t8, 0x80($a0)
    MEM_H(0X80, ctx->r4) = ctx->r24;
L_8000DC74:
    // 0x8000DC74: b           L_8000DEE4
    // 0x8000DC78: swc1        $f26, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f26.u32l;
        goto L_8000DEE4;
    // 0x8000DC78: swc1        $f26, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f26.u32l;
L_8000DC7C:
    // 0x8000DC7C: b           L_8000DEE4
    // 0x8000DC80: swc1        $f26, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f26.u32l;
        goto L_8000DEE4;
    // 0x8000DC80: swc1        $f26, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f26.u32l;
L_8000DC84:
    // 0x8000DC84: b           L_8000DEE4
    // 0x8000DC88: swc1        $f26, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f26.u32l;
        goto L_8000DEE4;
    // 0x8000DC88: swc1        $f26, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f26.u32l;
L_8000DC8C:
    // 0x8000DC8C: b           L_8000DEE4
    // 0x8000DC90: swc1        $f26, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f26.u32l;
        goto L_8000DEE4;
    // 0x8000DC90: swc1        $f26, 0x28($a0)
    MEM_W(0X28, ctx->r4) = ctx->f26.u32l;
L_8000DC94:
    // 0x8000DC94: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000DC98: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000DC9C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8000DCA0: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000DCA4: cvt.w.s     $f10, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    ctx->f10.u32l = CVT_W_S(ctx->f26.fl);
    // 0x8000DCA8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8000DCAC: nop

    // 0x8000DCB0: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8000DCB4: beql        $t4, $zero, L_8000DD04
    if (ctx->r12 == 0) {
        // 0x8000DCB8: mfc1        $t4, $f10
        ctx->r12 = (int32_t)ctx->f10.u32l;
            goto L_8000DD04;
    }
    goto skip_8;
    // 0x8000DCB8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    skip_8:
    // 0x8000DCBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000DCC0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000DCC4: sub.s       $f10, $f26, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f26.fl - ctx->f10.fl;
    // 0x8000DCC8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8000DCCC: nop

    // 0x8000DCD0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000DCD4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8000DCD8: nop

    // 0x8000DCDC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x8000DCE0: bne         $t4, $zero, L_8000DCF8
    if (ctx->r12 != 0) {
        // 0x8000DCE4: nop
    
            goto L_8000DCF8;
    }
    // 0x8000DCE4: nop

    // 0x8000DCE8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8000DCEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000DCF0: b           L_8000DD10
    // 0x8000DCF4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_8000DD10;
    // 0x8000DCF4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_8000DCF8:
    // 0x8000DCF8: b           L_8000DD10
    // 0x8000DCFC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_8000DD10;
    // 0x8000DCFC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8000DD00: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
L_8000DD04:
    // 0x8000DD04: nop

    // 0x8000DD08: bltz        $t4, L_8000DCF8
    if (SIGNED(ctx->r12) < 0) {
        // 0x8000DD0C: nop
    
            goto L_8000DCF8;
    }
    // 0x8000DD0C: nop

L_8000DD10:
    // 0x8000DD10: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000DD14: b           L_8000DEE4
    // 0x8000DD18: sh          $t4, 0x82($a0)
    MEM_H(0X82, ctx->r4) = ctx->r12;
        goto L_8000DEE4;
    // 0x8000DD18: sh          $t4, 0x82($a0)
    MEM_H(0X82, ctx->r4) = ctx->r12;
L_8000DD1C:
    // 0x8000DD1C: b           L_8000DEE4
    // 0x8000DD20: swc1        $f26, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f26.u32l;
        goto L_8000DEE4;
    // 0x8000DD20: swc1        $f26, 0x44($a0)
    MEM_W(0X44, ctx->r4) = ctx->f26.u32l;
L_8000DD24:
    // 0x8000DD24: b           L_8000DEE4
    // 0x8000DD28: swc1        $f26, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f26.u32l;
        goto L_8000DEE4;
    // 0x8000DD28: swc1        $f26, 0x48($a0)
    MEM_W(0X48, ctx->r4) = ctx->f26.u32l;
L_8000DD2C:
    // 0x8000DD2C: b           L_8000DEE4
    // 0x8000DD30: swc1        $f26, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f26.u32l;
        goto L_8000DEE4;
    // 0x8000DD30: swc1        $f26, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->f26.u32l;
L_8000DD34:
    // 0x8000DD34: b           L_8000DEE4
    // 0x8000DD38: swc1        $f26, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f26.u32l;
        goto L_8000DEE4;
    // 0x8000DD38: swc1        $f26, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f26.u32l;
L_8000DD3C:
    // 0x8000DD3C: beql        $v1, $a3, L_8000DE5C
    if (ctx->r3 == ctx->r7) {
        // 0x8000DD40: lwc1        $f4, 0xC($v0)
        ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
            goto L_8000DE5C;
    }
    goto skip_9;
    // 0x8000DD40: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    skip_9:
    // 0x8000DD44: bnel        $v1, $t0, L_8000DE8C
    if (ctx->r3 != ctx->r8) {
        // 0x8000DD48: addiu       $t5, $a1, -0x25
        ctx->r13 = ADD32(ctx->r5, -0X25);
            goto L_8000DE8C;
    }
    goto skip_10;
    // 0x8000DD48: addiu       $t5, $a1, -0x25
    ctx->r13 = ADD32(ctx->r5, -0X25);
    skip_10:
    // 0x8000DD4C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000DD50: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000DD54: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x8000DD58: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000DD5C: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x8000DD60: nop

    // 0x8000DD64: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8000DD68: trunc.w.s   $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8000DD6C: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x8000DD70: nop

    // 0x8000DD74: bgez        $v1, L_8000DD80
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8000DD78: nop
    
            goto L_8000DD80;
    }
    // 0x8000DD78: nop

    // 0x8000DD7C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000DD80:
    // 0x8000DD80: slti        $at, $v1, 0x101
    ctx->r1 = SIGNED(ctx->r3) < 0X101 ? 1 : 0;
    // 0x8000DD84: bnel        $at, $zero, L_8000DD94
    if (ctx->r1 != 0) {
        // 0x8000DD88: sw          $zero, 0x34($sp)
        MEM_W(0X34, ctx->r29) = 0;
            goto L_8000DD94;
    }
    goto skip_11;
    // 0x8000DD88: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    skip_11:
    // 0x8000DD8C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x8000DD90: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
L_8000DD94:
    // 0x8000DD94: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8000DD98: lbu         $t6, 0x10($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10);
    // 0x8000DD9C: subu        $a2, $t3, $v1
    ctx->r6 = SUB32(ctx->r11, ctx->r3);
    // 0x8000DDA0: sb          $t6, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r14;
    // 0x8000DDA4: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x8000DDA8: sb          $t7, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r15;
    // 0x8000DDAC: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x8000DDB0: lbu         $t8, 0x14($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X14);
    // 0x8000DDB4: multu       $a2, $t4
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000DDB8: sb          $t8, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r24;
    // 0x8000DDBC: lbu         $t9, 0x15($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X15);
    // 0x8000DDC0: sb          $t9, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r25;
    // 0x8000DDC4: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8000DDC8: mflo        $t5
    ctx->r13 = lo;
    // 0x8000DDCC: nop

    // 0x8000DDD0: nop

    // 0x8000DDD4: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000DDD8: mflo        $t7
    ctx->r15 = lo;
    // 0x8000DDDC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8000DDE0: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x8000DDE4: lbu         $t9, 0x38($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X38);
    // 0x8000DDE8: lbu         $t4, 0x3A($sp)
    ctx->r12 = MEM_BU(ctx->r29, 0X3A);
    // 0x8000DDEC: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8000DDF0: sb          $t9, 0x44($sp)
    MEM_B(0X44, ctx->r29) = ctx->r25;
    // 0x8000DDF4: sb          $t4, 0x45($sp)
    MEM_B(0X45, ctx->r29) = ctx->r12;
    // 0x8000DDF8: lbu         $t6, 0x12($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X12);
    // 0x8000DDFC: sb          $t6, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r14;
    // 0x8000DE00: lbu         $t5, 0x13($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X13);
    // 0x8000DE04: sb          $t5, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r13;
    // 0x8000DE08: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x8000DE0C: lbu         $t7, 0x16($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X16);
    // 0x8000DE10: multu       $a2, $t9
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000DE14: sb          $t7, 0x35($sp)
    MEM_B(0X35, ctx->r29) = ctx->r15;
    // 0x8000DE18: lbu         $t8, 0x17($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X17);
    // 0x8000DE1C: sb          $t8, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r24;
    // 0x8000DE20: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x8000DE24: mflo        $t4
    ctx->r12 = lo;
    // 0x8000DE28: nop

    // 0x8000DE2C: nop

    // 0x8000DE30: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000DE34: mflo        $t5
    ctx->r13 = lo;
    // 0x8000DE38: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x8000DE3C: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x8000DE40: lbu         $t8, 0x38($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X38);
    // 0x8000DE44: lbu         $t9, 0x3A($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3A);
    // 0x8000DE48: sb          $t8, 0x46($sp)
    MEM_B(0X46, ctx->r29) = ctx->r24;
    // 0x8000DE4C: sb          $t9, 0x47($sp)
    MEM_B(0X47, ctx->r29) = ctx->r25;
    // 0x8000DE50: b           L_8000DE88
    // 0x8000DE54: lbu         $a1, 0x4($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X4);
        goto L_8000DE88;
    // 0x8000DE54: lbu         $a1, 0x4($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X4);
    // 0x8000DE58: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
L_8000DE5C:
    // 0x8000DE5C: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x8000DE60: addiu       $a2, $v0, 0x10
    ctx->r6 = ADD32(ctx->r2, 0X10);
    // 0x8000DE64: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x8000DE68: nop

    // 0x8000DE6C: bc1f        L_8000DE7C
    if (!c1cs) {
        // 0x8000DE70: nop
    
            goto L_8000DE7C;
    }
    // 0x8000DE70: nop

    // 0x8000DE74: b           L_8000DE7C
    // 0x8000DE78: addiu       $a2, $v0, 0x14
    ctx->r6 = ADD32(ctx->r2, 0X14);
        goto L_8000DE7C;
    // 0x8000DE78: addiu       $a2, $v0, 0x14
    ctx->r6 = ADD32(ctx->r2, 0X14);
L_8000DE7C:
    // 0x8000DE7C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8000DE80: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8000DE84: lbu         $a1, 0x4($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X4);
L_8000DE88:
    // 0x8000DE88: addiu       $t5, $a1, -0x25
    ctx->r13 = ADD32(ctx->r5, -0X25);
L_8000DE8C:
    // 0x8000DE8C: sltiu       $at, $t5, 0x5
    ctx->r1 = ctx->r13 < 0X5 ? 1 : 0;
    // 0x8000DE90: beq         $at, $zero, L_8000DEE4
    if (ctx->r1 == 0) {
        // 0x8000DE94: sll         $t5, $t5, 2
        ctx->r13 = S32(ctx->r13 << 2);
            goto L_8000DEE4;
    }
    // 0x8000DE94: sll         $t5, $t5, 2
    ctx->r13 = S32(ctx->r13 << 2);
    // 0x8000DE98: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000DE9C: addu        $at, $at, $t5
    gpr jr_addend_8000DEA4 = ctx->r13;
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x8000DEA0: lw          $t5, -0x20F4($at)
    ctx->r13 = ADD32(ctx->r1, -0X20F4);
    // 0x8000DEA4: jr          $t5
    // 0x8000DEA8: nop

    switch (jr_addend_8000DEA4 >> 2) {
        case 0: goto L_8000DEAC; break;
        case 1: goto L_8000DEB8; break;
        case 2: goto L_8000DEC4; break;
        case 3: goto L_8000DED0; break;
        case 4: goto L_8000DEDC; break;
        default: switch_error(__func__, 0x8000DEA4, 0x8003DF0C);
    }
    // 0x8000DEA8: nop

L_8000DEAC:
    // 0x8000DEAC: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8000DEB0: b           L_8000DEE4
    // 0x8000DEB4: sw          $t8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r24;
        goto L_8000DEE4;
    // 0x8000DEB4: sw          $t8, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r24;
L_8000DEB8:
    // 0x8000DEB8: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8000DEBC: b           L_8000DEE4
    // 0x8000DEC0: sw          $t6, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r14;
        goto L_8000DEE4;
    // 0x8000DEC0: sw          $t6, 0x60($a0)
    MEM_W(0X60, ctx->r4) = ctx->r14;
L_8000DEC4:
    // 0x8000DEC4: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8000DEC8: b           L_8000DEE4
    // 0x8000DECC: sw          $t5, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r13;
        goto L_8000DEE4;
    // 0x8000DECC: sw          $t5, 0x64($a0)
    MEM_W(0X64, ctx->r4) = ctx->r13;
L_8000DED0:
    // 0x8000DED0: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8000DED4: b           L_8000DEE4
    // 0x8000DED8: sw          $t8, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r24;
        goto L_8000DEE4;
    // 0x8000DED8: sw          $t8, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r24;
L_8000DEDC:
    // 0x8000DEDC: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8000DEE0: sw          $t6, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->r14;
L_8000DEE4:
    // 0x8000DEE4: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8000DEE8:
    // 0x8000DEE8: bnel        $v0, $zero, L_8000DA94
    if (ctx->r2 != 0) {
        // 0x8000DEEC: lbu         $v1, 0x5($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X5);
            goto L_8000DA94;
    }
    goto skip_12;
    // 0x8000DEEC: lbu         $v1, 0x5($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X5);
    skip_12:
    // 0x8000DEF0: swc1        $f26, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f26.u32l;
    // 0x8000DEF4: lwc1        $f0, 0x98($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X98);
L_8000DEF8:
    // 0x8000DEF8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000DEFC: lwc1        $f8, -0x20E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X20E0);
    // 0x8000DF00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000DF04: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x8000DF08: nop

    // 0x8000DF0C: bc1fl       L_8000DF20
    if (!c1cs) {
        // 0x8000DF10: ldc1        $f20, 0x8($sp)
        CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
            goto L_8000DF20;
    }
    goto skip_13;
    // 0x8000DF10: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
    skip_13:
    // 0x8000DF14: lwc1        $f6, -0x20DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X20DC);
    // 0x8000DF18: swc1        $f6, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f6.u32l;
    // 0x8000DF1C: ldc1        $f20, 0x8($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X8);
L_8000DF20:
    // 0x8000DF20: ldc1        $f22, 0x10($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X10);
    // 0x8000DF24: ldc1        $f24, 0x18($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X18);
    // 0x8000DF28: ldc1        $f26, 0x20($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X20);
    // 0x8000DF2C: jr          $ra
    // 0x8000DF30: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000DF30: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void func_ovl8_8037CE40(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CE40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037CE44: bne         $a0, $zero, L_8037CE5C
    if (ctx->r4 != 0) {
        // 0x8037CE48: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8037CE5C;
    }
    // 0x8037CE48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037CE4C: jal         0x803717A0
    // 0x8037CE50: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x8037CE50: addiu       $a0, $zero, 0x68
    ctx->r4 = ADD32(0, 0X68);
    after_0:
    // 0x8037CE54: beq         $v0, $zero, L_8037CE7C
    if (ctx->r2 == 0) {
        // 0x8037CE58: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037CE7C;
    }
    // 0x8037CE58: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8037CE5C:
    // 0x8037CE5C: jal         0x803717E0
    // 0x8037CE60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x8037CE60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_1:
    // 0x8037CE64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8037CE68: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037CE6C: addiu       $t6, $t6, -0x5900
    ctx->r14 = ADD32(ctx->r14, -0X5900);
    // 0x8037CE70: jal         0x8037CF4C
    // 0x8037CE74: sw          $t6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r14;
    func_ovl8_8037CF4C(rdram, ctx);
        goto after_2;
    // 0x8037CE74: sw          $t6, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r14;
    after_2:
    // 0x8037CE78: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_8037CE7C:
    // 0x8037CE7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037CE80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037CE84: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8037CE88: jr          $ra
    // 0x8037CE8C: nop

    return;
    // 0x8037CE8C: nop

;}
RECOMP_FUNC void lbCommonSetDObjTransformsForTreeDObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9314: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C9318: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C931C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C9320: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C9324: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800C9328: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800C932C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C9330: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C9334: beq         $a0, $zero, L_800C93B8
    if (ctx->r4 == 0) {
        // 0x800C9338: or          $s1, $a0, $zero
        ctx->r17 = ctx->r4 | 0;
            goto L_800C93B8;
    }
    // 0x800C9338: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C933C: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800C9340: addiu       $s2, $zero, 0x12
    ctx->r18 = ADD32(0, 0X12);
    // 0x800C9344: beql        $s2, $t6, L_800C93BC
    if (ctx->r18 == ctx->r14) {
        // 0x800C9348: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800C93BC;
    }
    goto skip_0;
    // 0x800C9348: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x800C934C: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
L_800C9350:
    // 0x800C9350: addiu       $s0, $s0, 0x2C
    ctx->r16 = ADD32(ctx->r16, 0X2C);
    // 0x800C9354: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C9358: sw          $t8, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->r24;
    // 0x800C935C: lw          $t7, -0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, -0X20);
    // 0x800C9360: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800C9364: sw          $t7, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->r15;
    // 0x800C9368: lw          $t8, -0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, -0X1C);
    // 0x800C936C: sw          $t8, 0x24($s1)
    MEM_W(0X24, ctx->r17) = ctx->r24;
    // 0x800C9370: lw          $t0, -0x18($s0)
    ctx->r8 = MEM_W(ctx->r16, -0X18);
    // 0x800C9374: sw          $t0, 0x30($s1)
    MEM_W(0X30, ctx->r17) = ctx->r8;
    // 0x800C9378: lw          $t9, -0x14($s0)
    ctx->r25 = MEM_W(ctx->r16, -0X14);
    // 0x800C937C: sw          $t9, 0x34($s1)
    MEM_W(0X34, ctx->r17) = ctx->r25;
    // 0x800C9380: lw          $t0, -0x10($s0)
    ctx->r8 = MEM_W(ctx->r16, -0X10);
    // 0x800C9384: sw          $t0, 0x38($s1)
    MEM_W(0X38, ctx->r17) = ctx->r8;
    // 0x800C9388: lw          $t2, -0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, -0XC);
    // 0x800C938C: sw          $t2, 0x40($s1)
    MEM_W(0X40, ctx->r17) = ctx->r10;
    // 0x800C9390: lw          $t1, -0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, -0X8);
    // 0x800C9394: sw          $t1, 0x44($s1)
    MEM_W(0X44, ctx->r17) = ctx->r9;
    // 0x800C9398: lw          $t2, -0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, -0X4);
    // 0x800C939C: jal         0x800C86E8
    // 0x800C93A0: sw          $t2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r10;
    lbCommonGetTreeDObjNextFromRoot(rdram, ctx);
        goto after_0;
    // 0x800C93A0: sw          $t2, 0x48($s1)
    MEM_W(0X48, ctx->r17) = ctx->r10;
    after_0:
    // 0x800C93A4: beq         $v0, $zero, L_800C93B8
    if (ctx->r2 == 0) {
        // 0x800C93A8: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800C93B8;
    }
    // 0x800C93A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800C93AC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800C93B0: bnel        $s2, $t3, L_800C9350
    if (ctx->r18 != ctx->r11) {
        // 0x800C93B4: lw          $t8, 0x8($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X8);
            goto L_800C9350;
    }
    goto skip_1;
    // 0x800C93B4: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    skip_1:
L_800C93B8:
    // 0x800C93B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800C93BC:
    // 0x800C93BC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C93C0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C93C4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C93C8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C93CC: jr          $ra
    // 0x800C93D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C93D0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnVSModeMakeRuleButton(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132A50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132A54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132A5C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80132A60: jal         0x80009968
    // 0x80132A64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132A64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132A68: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A6C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132A70: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132A74: sw          $v0, 0x4934($at)
    MEM_W(0X4934, ctx->r1) = ctx->r2;
    // 0x80132A78: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132A7C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132A80: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132A84: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132A88: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132A8C: jal         0x80009DF4
    // 0x80132A90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132A90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132A94: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132A98: lui         $a1, 0x42C2
    ctx->r5 = S32(0X42C2 << 16);
    // 0x80132A9C: lui         $a2, 0x428C
    ctx->r6 = S32(0X428C << 16);
    // 0x80132AA0: jal         0x80132024
    // 0x80132AA4: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    mnVSModeMakeButton(rdram, ctx);
        goto after_2;
    // 0x80132AA4: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_2:
    // 0x80132AA8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132AAC: lw          $t7, 0x4948($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4948);
    // 0x80132AB0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132AB4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132AB8: bne         $t7, $at, L_80132AC8
    if (ctx->r15 != ctx->r1) {
        // 0x80132ABC: nop
    
            goto L_80132AC8;
    }
    // 0x80132ABC: nop

    // 0x80132AC0: b           L_80132AC8
    // 0x80132AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80132AC8;
    // 0x80132AC4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80132AC8:
    // 0x80132AC8: jal         0x80131F4C
    // 0x80132ACC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mnVSModeUpdateButton(rdram, ctx);
        goto after_3;
    // 0x80132ACC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80132AD0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132AD4: lw          $t8, 0x4A4C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4A4C);
    // 0x80132AD8: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80132ADC: addiu       $t9, $t9, 0x2748
    ctx->r25 = ADD32(ctx->r25, 0X2748);
    // 0x80132AE0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132AE4: jal         0x800CCFDC
    // 0x80132AE8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132AE8: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_4:
    // 0x80132AEC: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132AF0: lui         $at, 0x42D8
    ctx->r1 = S32(0X42D8 << 16);
    // 0x80132AF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132AF8: lui         $at, 0x4296
    ctx->r1 = S32(0X4296 << 16);
    // 0x80132AFC: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132B00: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132B04: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132B08: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132B0C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132B10: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132B14: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132B18: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132B1C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132B20: jal         0x80132818
    // 0x80132B24: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    mnVSModeMakeRuleArrows(rdram, ctx);
        goto after_5;
    // 0x80132B24: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    after_5:
    // 0x80132B28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132B2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132B30: jr          $ra
    // 0x80132B34: nop

    return;
    // 0x80132B34: nop

;}
RECOMP_FUNC void mnVSResultsWallpaperTint2ProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801350C8: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x801350CC: addiu       $t4, $t4, -0x6438
    ctx->r12 = ADD32(ctx->r12, -0X6438);
    // 0x801350D0: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x801350D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801350D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801350DC: blez        $v0, L_801350FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801350E0: addiu       $t6, $v0, -0x5
        ctx->r14 = ADD32(ctx->r2, -0X5);
            goto L_801350FC;
    }
    // 0x801350E0: addiu       $t6, $v0, -0x5
    ctx->r14 = ADD32(ctx->r2, -0X5);
    // 0x801350E4: bgez        $t6, L_801350FC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801350E8: sw          $t6, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r14;
            goto L_801350FC;
    }
    // 0x801350E8: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x801350EC: jal         0x80009A84
    // 0x801350F0: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801350F0: nop

    after_0:
    // 0x801350F4: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x801350F8: addiu       $t4, $t4, -0x6438
    ctx->r12 = ADD32(ctx->r12, -0X6438);
L_801350FC:
    // 0x801350FC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80135100: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80135104: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80135108: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x8013510C: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80135110: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80135114: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80135118: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013511C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80135120: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80135124: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80135128: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x8013512C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80135130: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80135134: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80135138: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8013513C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80135140: lui         $ra, 0xE200
    ctx->r31 = S32(0XE200 << 16);
    // 0x80135144: ori         $ra, $ra, 0x1C
    ctx->r31 = ctx->r31 | 0X1C;
    // 0x80135148: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8013514C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80135150: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80135154: lw          $t9, 0x0($t4)
    ctx->r25 = MEM_W(ctx->r12, 0X0);
    // 0x80135158: lui         $t8, 0xFCFF
    ctx->r24 = S32(0XFCFF << 16);
    // 0x8013515C: ori         $t8, $t8, 0xFFFF
    ctx->r24 = ctx->r24 | 0XFFFF;
    // 0x80135160: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x80135164: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80135168: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013516C: lui         $t9, 0xFFFD
    ctx->r25 = S32(0XFFFD << 16);
    // 0x80135170: ori         $t9, $t9, 0xF6FB
    ctx->r25 = ctx->r25 | 0XF6FB;
    // 0x80135174: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80135178: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013517C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80135180: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80135184: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80135188: lui         $t7, 0x50
    ctx->r15 = S32(0X50 << 16);
    // 0x8013518C: ori         $t7, $t7, 0x41C8
    ctx->r15 = ctx->r15 | 0X41C8;
    // 0x80135190: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80135194: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80135198: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013519C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x801351A0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801351A4: lui         $t6, 0x2
    ctx->r14 = S32(0X2 << 16);
    // 0x801351A8: lui         $t9, 0xF64D
    ctx->r25 = S32(0XF64D << 16);
    // 0x801351AC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801351B0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801351B4: ori         $t9, $t9, 0x8398
    ctx->r25 = ctx->r25 | 0X8398;
    // 0x801351B8: ori         $t6, $t6, 0x8028
    ctx->r14 = ctx->r14 | 0X8028;
    // 0x801351BC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801351C0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801351C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801351C8: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x801351CC: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x801351D0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801351D4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801351D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801351DC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801351E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801351E4: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801351E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801351EC: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801351F0: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x801351F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801351F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801351FC: jr          $ra
    // 0x80135200: nop

    return;
    // 0x80135200: nop

;}
RECOMP_FUNC void func_ovl8_803714F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803714F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803714FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371500: addu        $a2, $a0, $a1
    ctx->r6 = ADD32(ctx->r4, ctx->r5);
    // 0x80371504: sw          $a0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r4;
    // 0x80371508: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8037150C: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x80371510: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x80371514: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x80371518: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8037151C: lw          $t9, -0x1198($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1198);
    // 0x80371520: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
    // 0x80371524: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80371528: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x8037152C: beq         $at, $zero, L_80371538
    if (ctx->r1 == 0) {
        // 0x80371530: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80371538;
    }
    // 0x80371530: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80371534: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
L_80371538:
    // 0x80371538: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8037153C: jal         0x80371474
    // 0x80371540: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    func_ovl8_80371474(rdram, ctx);
        goto after_0;
    // 0x80371540: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x80371544: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80371548: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x8037154C: sw          $a1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r5;
    // 0x80371550: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371554: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371558: jr          $ra
    // 0x8037155C: nop

    return;
    // 0x8037155C: nop

;}

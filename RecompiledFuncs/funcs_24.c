#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftCommonCliffClimbSlow2SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801455E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801455E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801455E8: jal         0x80145490
    // 0x801455EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftCommonCliffCommon2UpdateCollData(rdram, ctx);
        goto after_0;
    // 0x801455EC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801455F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801455F4: addiu       $a1, $zero, 0x5B
    ctx->r5 = ADD32(0, 0X5B);
    // 0x801455F8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801455FC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80145600: jal         0x800E6F24
    // 0x80145604: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80145604: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80145608: jal         0x8014557C
    // 0x8014560C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonCliffCommon2InitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8014560C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80145610: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80145614: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80145618: jr          $ra
    // 0x8014561C: nop

    return;
    // 0x8014561C: nop

;}
RECOMP_FUNC void wpNessPKReflectHeadMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B898: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8016B89C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8016B8A0: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8016B8A4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8016B8A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016B8AC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8016B8B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8016B8B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016B8B8: ori         $a3, $a3, 0x2
    ctx->r7 = ctx->r7 | 0X2;
    // 0x8016B8BC: jal         0x801655C8
    // 0x8016B8C0: addiu       $a1, $a1, -0x6DC8
    ctx->r5 = ADD32(ctx->r5, -0X6DC8);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x8016B8C0: addiu       $a1, $a1, -0x6DC8
    ctx->r5 = ADD32(ctx->r5, -0X6DC8);
    after_0:
    // 0x8016B8C4: bne         $v0, $zero, L_8016B8D4
    if (ctx->r2 != 0) {
        // 0x8016B8C8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8016B8D4;
    }
    // 0x8016B8C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8016B8CC: b           L_8016B9CC
    // 0x8016B8D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8016B9CC;
    // 0x8016B8D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016B8D4:
    // 0x8016B8D4: lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84);
    // 0x8016B8D8: lui         $t6, 0x8017
    ctx->r14 = S32(0X8017 << 16);
    // 0x8016B8DC: addiu       $t6, $t6, -0x478C
    ctx->r14 = ADD32(ctx->r14, -0X478C);
    // 0x8016B8E0: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8016B8E4: sw          $t6, 0x298($v1)
    MEM_W(0X298, ctx->r3) = ctx->r14;
    // 0x8016B8E8: sw          $t7, 0x268($v1)
    MEM_W(0X268, ctx->r3) = ctx->r15;
    // 0x8016B8EC: jal         0x801655A0
    // 0x8016B8F0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    wpManagerGetGroupID(rdram, ctx);
        goto after_1;
    // 0x8016B8F0: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_1:
    // 0x8016B8F4: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8016B8F8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8016B8FC: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x8016B900: sw          $v0, 0x264($v1)
    MEM_W(0X264, ctx->r3) = ctx->r2;
    // 0x8016B904: sw          $zero, 0x2A8($v1)
    MEM_W(0X2A8, ctx->r3) = 0;
    // 0x8016B908: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x8016B90C: sw          $zero, 0x2AC($v0)
    MEM_W(0X2AC, ctx->r2) = 0;
    // 0x8016B910: sw          $zero, 0x2B0($v0)
    MEM_W(0X2B0, ctx->r2) = 0;
    // 0x8016B914: sw          $zero, 0x2B4($v0)
    MEM_W(0X2B4, ctx->r2) = 0;
    // 0x8016B918: sw          $zero, 0x2A8($v0)
    MEM_W(0X2A8, ctx->r2) = 0;
    // 0x8016B91C: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x8016B920: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x8016B924: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x8016B928: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x8016B92C: lwc1        $f4, 0x1C($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8016B930: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8016B934: lwc1        $f6, 0x1C($t1)
    ctx->f6.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8016B938: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x8016B93C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8016B940: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    // 0x8016B944: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x8016B948: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8016B94C: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x8016B950: lwc1        $f4, 0x20($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X20);
    // 0x8016B954: lwc1        $f10, 0x20($t3)
    ctx->f10.u32l = MEM_W(ctx->r11, 0X20);
    // 0x8016B958: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8016B95C: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8016B960: swc1        $f6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f6.u32l;
    // 0x8016B964: lw          $t6, 0x8($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X8);
    // 0x8016B968: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8016B96C: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8016B970: lwc1        $f8, 0x24($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X24);
    // 0x8016B974: lwc1        $f10, 0x24($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X24);
    // 0x8016B978: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x8016B97C: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8016B980: jal         0x80018EE0
    // 0x8016B984: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_2;
    // 0x8016B984: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8016B988: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8016B98C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8016B990: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8016B994: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8016B998: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8016B99C: mul.s       $f18, $f2, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8016B9A0: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
    // 0x8016B9A4: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8016B9A8: lwc1        $f14, 0x20($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8016B9AC: swc1        $f10, 0x28($v1)
    MEM_W(0X28, ctx->r3) = ctx->f10.u32l;
    // 0x8016B9B0: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8016B9B4: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
    // 0x8016B9B8: jal         0x8001863C
    // 0x8016B9BC: lwc1        $f12, 0x24($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X24);
    syUtilsArcTan2(rdram, ctx);
        goto after_3;
    // 0x8016B9BC: lwc1        $f12, 0x24($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X24);
    after_3:
    // 0x8016B9C0: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x8016B9C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8016B9C8: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
L_8016B9CC:
    // 0x8016B9CC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016B9D0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8016B9D4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8016B9D8: jr          $ra
    // 0x8016B9DC: nop

    return;
    // 0x8016B9DC: nop

;}
RECOMP_FUNC void dbCubePlayCall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C70: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131C74: lw          $t6, 0x2D2C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2D2C);
    // 0x80131C78: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131C7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131C80: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80131C84: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80131C88: lw          $t8, 0x2D54($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2D54);
    // 0x80131C8C: jr          $ra
    // 0x80131C90: sw          $t8, 0x2D48($at)
    MEM_W(0X2D48, ctx->r1) = ctx->r24;
    return;
    // 0x80131C90: sw          $t8, 0x2D48($at)
    MEM_W(0X2D48, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F408: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015F40C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F410: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015F414: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015F418: jal         0x800DEE98
    // 0x8015F41C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015F41C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015F420: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015F424: addiu       $t7, $zero, 0x25
    ctx->r15 = ADD32(0, 0X25);
    // 0x8015F428: addiu       $a1, $zero, 0x129
    ctx->r5 = ADD32(0, 0X129);
    // 0x8015F42C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015F430: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015F434: jal         0x800E6F24
    // 0x8015F438: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015F438: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015F43C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F440: addiu       $a1, $a1, -0x954
    ctx->r5 = ADD32(ctx->r5, -0X954);
    // 0x8015F444: jal         0x8015F180
    // 0x8015F448: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftKirbyCopyYoshiSpecialNSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x8015F448: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015F44C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F450: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015F454: jr          $ra
    // 0x8015F458: nop

    return;
    // 0x8015F458: nop

;}
RECOMP_FUNC void itHammerThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176300: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176304: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80176308: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017630C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80176310: addiu       $a1, $a1, -0x625C
    ctx->r5 = ADD32(ctx->r5, -0X625C);
    // 0x80176314: jal         0x80172EC8
    // 0x80176318: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80176318: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_0:
    // 0x8017631C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80176320: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80176324: lwc1        $f4, -0x32F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X32F0);
    // 0x80176328: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x8017632C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80176330: jal         0x800E7B54
    // 0x80176334: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    ftParamTryUpdateItemMusic(rdram, ctx);
        goto after_1;
    // 0x80176334: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    after_1:
    // 0x80176338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017633C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80176340: jr          $ra
    // 0x80176344: nop

    return;
    // 0x80176344: nop

;}
RECOMP_FUNC void ftCommonRunBrakeProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F014: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F018: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F01C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013F020: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8013F024: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8013F028: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013F02C: lw          $v0, 0x9C8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9C8);
    // 0x8013F030: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8013F034: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8013F038: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8013F03C: jal         0x800D8978
    // 0x8013F040: nop

    ftPhysicsSetGroundVelFriction(rdram, ctx);
        goto after_0;
    // 0x8013F040: nop

    after_0:
    // 0x8013F044: jal         0x800D87D0
    // 0x8013F048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_1;
    // 0x8013F048: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013F04C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F054: jr          $ra
    // 0x8013F058: nop

    return;
    // 0x8013F058: nop

;}
RECOMP_FUNC void ftCaptainSpecialHiProcCatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160690: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80160694: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80160698: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8016069C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801606A0: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x801606A4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801606A8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801606AC: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x801606B0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801606B4: jal         0x800E6F24
    // 0x801606B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801606B8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801606BC: jal         0x800E0830
    // 0x801606C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801606C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801606C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801606C8: jal         0x800E8098
    // 0x801606CC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x801606CC: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x801606D0: jal         0x800D9444
    // 0x801606D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_3;
    // 0x801606D4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x801606D8: lw          $v0, 0x830($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X830);
    // 0x801606DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801606E0: sw          $v0, 0x840($s0)
    MEM_W(0X840, ctx->r16) = ctx->r2;
    // 0x801606E4: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x801606E8: lw          $t7, 0x14C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X14C);
    // 0x801606EC: bnel        $t7, $at, L_80160714
    if (ctx->r15 != ctx->r1) {
        // 0x801606F0: lbu         $t3, 0x192($s0)
        ctx->r11 = MEM_BU(ctx->r16, 0X192);
            goto L_80160714;
    }
    goto skip_0;
    // 0x801606F0: lbu         $t3, 0x192($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X192);
    skip_0:
    // 0x801606F4: lhu         $t8, 0xB18($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XB18);
    // 0x801606F8: lbu         $t0, 0x192($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X192);
    // 0x801606FC: ori         $t9, $t8, 0x4
    ctx->r25 = ctx->r24 | 0X4;
    // 0x80160700: andi        $t1, $t0, 0xFFEF
    ctx->r9 = ctx->r8 & 0XFFEF;
    // 0x80160704: sh          $t9, 0xB18($s0)
    MEM_H(0XB18, ctx->r16) = ctx->r25;
    // 0x80160708: b           L_8016071C
    // 0x8016070C: sb          $t1, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r9;
        goto L_8016071C;
    // 0x8016070C: sb          $t1, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r9;
    // 0x80160710: lbu         $t3, 0x192($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X192);
L_80160714:
    // 0x80160714: ori         $t4, $t3, 0x10
    ctx->r12 = ctx->r11 | 0X10;
    // 0x80160718: sb          $t4, 0x192($s0)
    MEM_B(0X192, ctx->r16) = ctx->r12;
L_8016071C:
    // 0x8016071C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80160720: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80160724: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80160728: jr          $ra
    // 0x8016072C: nop

    return;
    // 0x8016072C: nop

;}
RECOMP_FUNC void ftPublicPlayCliffReact(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164F70: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80164F74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164F78: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80164F7C: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x80164F80: lw          $t6, -0x3054($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3054);
    // 0x80164F84: lw          $t7, 0x18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X18);
    // 0x80164F88: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80164F8C: bnel        $t6, $t7, L_80164FA4
    if (ctx->r14 != ctx->r15) {
        // 0x80164F90: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_80164FA4;
    }
    goto skip_0;
    // 0x80164F90: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_0:
    // 0x80164F94: jal         0x80164C18
    // 0x80164F98: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    ftPublicTryInterruptCall(rdram, ctx);
        goto after_0;
    // 0x80164F98: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_0:
    // 0x80164F9C: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80164FA0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
L_80164FA4:
    // 0x80164FA4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80164FA8: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80164FAC: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80164FB0: nop

    // 0x80164FB4: bc1fl       L_80164FD0
    if (!c1cs) {
        // 0x80164FB8: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80164FD0;
    }
    goto skip_1;
    // 0x80164FB8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_1:
    // 0x80164FBC: jal         0x80164C44
    // 0x80164FC0: addiu       $a0, $zero, 0x267
    ctx->r4 = ADD32(0, 0X267);
    ftPublicPlayCommon(rdram, ctx);
        goto after_1;
    // 0x80164FC0: addiu       $a0, $zero, 0x267
    ctx->r4 = ADD32(0, 0X267);
    after_1:
    // 0x80164FC4: b           L_80165018
    // 0x80164FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80165018;
    // 0x80164FC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80164FCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80164FD0:
    // 0x80164FD0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80164FD4: c.le.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl <= ctx->f12.fl;
    // 0x80164FD8: nop

    // 0x80164FDC: bc1fl       L_80164FF8
    if (!c1cs) {
        // 0x80164FE0: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80164FF8;
    }
    goto skip_2;
    // 0x80164FE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_2:
    // 0x80164FE4: jal         0x80164C44
    // 0x80164FE8: addiu       $a0, $zero, 0x268
    ctx->r4 = ADD32(0, 0X268);
    ftPublicPlayCommon(rdram, ctx);
        goto after_2;
    // 0x80164FE8: addiu       $a0, $zero, 0x268
    ctx->r4 = ADD32(0, 0X268);
    after_2:
    // 0x80164FEC: b           L_80165018
    // 0x80164FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80165018;
    // 0x80164FF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80164FF4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80164FF8:
    // 0x80164FF8: nop

    // 0x80164FFC: c.le.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl <= ctx->f12.fl;
    // 0x80165000: nop

    // 0x80165004: bc1fl       L_80165018
    if (!c1cs) {
        // 0x80165008: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80165018;
    }
    goto skip_3;
    // 0x80165008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x8016500C: jal         0x80164C44
    // 0x80165010: addiu       $a0, $zero, 0x269
    ctx->r4 = ADD32(0, 0X269);
    ftPublicPlayCommon(rdram, ctx);
        goto after_3;
    // 0x80165010: addiu       $a0, $zero, 0x269
    ctx->r4 = ADD32(0, 0X269);
    after_3:
    // 0x80165014: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80165018:
    // 0x80165018: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016501C: jr          $ra
    // 0x80165020: nop

    return;
    // 0x80165020: nop

;}
RECOMP_FUNC void gcAddLinkedDL(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017AAC: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80017AB0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80017AB4: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80017AB8: addiu       $t7, $t7, 0x6A88
    ctx->r15 = ADD32(ctx->r15, 0X6A88);
    // 0x80017ABC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80017AC0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80017AC4: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x80017AC8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80017ACC: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x80017AD0: beq         $t8, $zero, L_80017AF8
    if (ctx->r24 == 0) {
        // 0x80017AD4: lui         $t9, 0x8004
        ctx->r25 = S32(0X8004 << 16);
            goto L_80017AF8;
    }
    // 0x80017AD4: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80017AD8: lw          $t9, 0x65B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X65B0);
    // 0x80017ADC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017AE0: lui         $a0, 0xDE00
    ctx->r4 = S32(0XDE00 << 16);
    // 0x80017AE4: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x80017AE8: sw          $t0, 0x65B0($at)
    MEM_W(0X65B0, ctx->r1) = ctx->r8;
    // 0x80017AEC: sw          $a0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r4;
    // 0x80017AF0: lw          $t1, 0x4($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X4);
    // 0x80017AF4: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
L_80017AF8:
    // 0x80017AF8: lw          $t2, 0x8($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X8);
    // 0x80017AFC: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80017B00: lui         $a0, 0xDE00
    ctx->r4 = S32(0XDE00 << 16);
    // 0x80017B04: beql        $t2, $zero, L_80017B2C
    if (ctx->r10 == 0) {
        // 0x80017B08: lw          $t6, 0xC($v1)
        ctx->r14 = MEM_W(ctx->r3, 0XC);
            goto L_80017B2C;
    }
    goto skip_0;
    // 0x80017B08: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
    skip_0:
    // 0x80017B0C: lw          $t3, 0x65B4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X65B4);
    // 0x80017B10: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017B14: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80017B18: sw          $t4, 0x65B4($at)
    MEM_W(0X65B4, ctx->r1) = ctx->r12;
    // 0x80017B1C: sw          $a0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r4;
    // 0x80017B20: lw          $t5, 0x8($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X8);
    // 0x80017B24: sw          $t5, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r13;
    // 0x80017B28: lw          $t6, 0xC($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XC);
L_80017B2C:
    // 0x80017B2C: beql        $t6, $zero, L_80017B54
    if (ctx->r14 == 0) {
        // 0x80017B30: lw          $t0, 0x10($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X10);
            goto L_80017B54;
    }
    goto skip_1;
    // 0x80017B30: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
    skip_1:
    // 0x80017B34: lw          $t7, 0x65B8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X65B8);
    // 0x80017B38: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017B3C: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80017B40: sw          $t8, 0x65B8($at)
    MEM_W(0X65B8, ctx->r1) = ctx->r24;
    // 0x80017B44: sw          $a0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r4;
    // 0x80017B48: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x80017B4C: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x80017B50: lw          $t0, 0x10($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X10);
L_80017B54:
    // 0x80017B54: beq         $t0, $zero, L_80017B78
    if (ctx->r8 == 0) {
        // 0x80017B58: nop
    
            goto L_80017B78;
    }
    // 0x80017B58: nop

    // 0x80017B5C: lw          $t1, 0x65BC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X65BC);
    // 0x80017B60: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80017B64: addiu       $t2, $t1, 0x8
    ctx->r10 = ADD32(ctx->r9, 0X8);
    // 0x80017B68: sw          $t2, 0x65BC($at)
    MEM_W(0X65BC, ctx->r1) = ctx->r10;
    // 0x80017B6C: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x80017B70: lw          $t3, 0x10($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X10);
    // 0x80017B74: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
L_80017B78:
    // 0x80017B78: jr          $ra
    // 0x80017B7C: nop

    return;
    // 0x80017B7C: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwHoldProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155594: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015559C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801555A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801555A4: jal         0x80155518
    // 0x801555A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftNessSpecialLw_UpdateReleaseLag(rdram, ctx);
        goto after_0;
    // 0x801555A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x801555AC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801555B0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801555B4: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x801555B8: bgtzl       $t6, L_801555D8
    if (SIGNED(ctx->r14) > 0) {
        // 0x801555BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801555D8;
    }
    goto skip_0;
    // 0x801555BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801555C0: lw          $t7, 0xB1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB1C);
    // 0x801555C4: beql        $t7, $zero, L_801555D8
    if (ctx->r15 == 0) {
        // 0x801555C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801555D8;
    }
    goto skip_1;
    // 0x801555C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801555CC: jal         0x80155B00
    // 0x801555D0: nop

    ftNessSpecialAirLwEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x801555D0: nop

    after_1:
    // 0x801555D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801555D8:
    // 0x801555D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801555DC: jr          $ra
    // 0x801555E0: nop

    return;
    // 0x801555E0: nop

;}
RECOMP_FUNC void func_ovl8_80374DB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374DB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374DB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374DBC: beq         $a1, $zero, L_80374DE4
    if (ctx->r5 == 0) {
        // 0x80374DC0: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80374DE4;
    }
    // 0x80374DC0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80374DC4: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80374DC8: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80374DCC: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80374DD0: lh          $t6, 0x10($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X10);
    // 0x80374DD4: jalr        $t9
    // 0x80374DD8: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374DD8: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x80374DDC: b           L_80374E00
    // 0x80374DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80374E00;
    // 0x80374DE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80374DE4:
    // 0x80374DE4: lw          $v1, 0x38($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X38);
    // 0x80374DE8: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80374DEC: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x80374DF0: lh          $t7, 0x18($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X18);
    // 0x80374DF4: jalr        $t9
    // 0x80374DF8: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80374DF8: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_1:
    // 0x80374DFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80374E00:
    // 0x80374E00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374E04: jr          $ra
    // 0x80374E08: nop

    return;
    // 0x80374E08: nop

;}
RECOMP_FUNC void ftCommonDeadResetSpecialStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C0B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013C0B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013C0B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013C0BC: lbu         $t7, 0x191($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X191);
    // 0x8013C0C0: lbu         $t0, 0x18E($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X18E);
    // 0x8013C0C4: sw          $zero, 0x5B0($v0)
    MEM_W(0X5B0, ctx->r2) = 0;
    // 0x8013C0C8: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x8013C0CC: ori         $t1, $t0, 0x80
    ctx->r9 = ctx->r8 | 0X80;
    // 0x8013C0D0: sb          $t8, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r24;
    // 0x8013C0D4: jal         0x800E7B54
    // 0x8013C0D8: sb          $t1, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r9;
    ftParamTryUpdateItemMusic(rdram, ctx);
        goto after_0;
    // 0x8013C0D8: sb          $t1, 0x18E($v0)
    MEM_B(0X18E, ctx->r2) = ctx->r9;
    after_0:
    // 0x8013C0DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013C0E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013C0E4: jr          $ra
    // 0x8013C0E8: nop

    return;
    // 0x8013C0E8: nop

;}
RECOMP_FUNC void lbCommonSetSpriteScissor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD1F0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CD1F4: sw          $a0, 0x62C4($at)
    MEM_W(0X62C4, ctx->r1) = ctx->r4;
    // 0x800CD1F8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CD1FC: sw          $a2, 0x62C8($at)
    MEM_W(0X62C8, ctx->r1) = ctx->r6;
    // 0x800CD200: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CD204: sw          $a1, 0x62BC($at)
    MEM_W(0X62BC, ctx->r1) = ctx->r5;
    // 0x800CD208: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CD20C: jr          $ra
    // 0x800CD210: sw          $a3, 0x62C0($at)
    MEM_W(0X62C0, ctx->r1) = ctx->r7;
    return;
    // 0x800CD210: sw          $a3, 0x62C0($at)
    MEM_W(0X62C0, ctx->r1) = ctx->r7;
;}
RECOMP_FUNC void mnPlayersVSCheckTimeArrowLInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013502C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80135030: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80135034: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80135038: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x8013503C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80135040: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80135044: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80135048: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8013504C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80135050: nop

    // 0x80135054: bc1t        L_80135074
    if (c1cs) {
        // 0x80135058: nop
    
            goto L_80135074;
    }
    // 0x80135058: nop

    // 0x8013505C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80135060: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80135064: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80135068: nop

    // 0x8013506C: bc1f        L_8013507C
    if (!c1cs) {
        // 0x80135070: nop
    
            goto L_8013507C;
    }
    // 0x80135070: nop

L_80135074:
    // 0x80135074: b           L_8013507C
    // 0x80135078: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8013507C;
    // 0x80135078: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8013507C:
    // 0x8013507C: beq         $v1, $zero, L_8013508C
    if (ctx->r3 == 0) {
        // 0x80135080: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8013508C;
    }
    // 0x80135080: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80135084: jr          $ra
    // 0x80135088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80135088: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013508C:
    // 0x8013508C: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80135090: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80135094: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x80135098: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013509C: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801350A0: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x801350A4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801350A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801350AC: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x801350B0: nop

    // 0x801350B4: bc1f        L_801350DC
    if (!c1cs) {
        // 0x801350B8: nop
    
            goto L_801350DC;
    }
    // 0x801350B8: nop

    // 0x801350BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801350C0: nop

    // 0x801350C4: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x801350C8: nop

    // 0x801350CC: bc1f        L_801350DC
    if (!c1cs) {
        // 0x801350D0: nop
    
            goto L_801350DC;
    }
    // 0x801350D0: nop

    // 0x801350D4: b           L_801350DC
    // 0x801350D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801350DC;
    // 0x801350D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801350DC:
    // 0x801350DC: beq         $v1, $zero, L_801350EC
    if (ctx->r3 == 0) {
        // 0x801350E0: nop
    
            goto L_801350EC;
    }
    // 0x801350E0: nop

    // 0x801350E4: jr          $ra
    // 0x801350E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801350E8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801350EC:
    // 0x801350EC: jr          $ra
    // 0x801350F0: nop

    return;
    // 0x801350F0: nop

;}
RECOMP_FUNC void n_alSynAddSeqPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D620: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002D624: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002D628: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8002D62C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8002D630: jal         0x80030350
    // 0x8002D634: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x8002D634: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8002D638: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8002D63C: addiu       $v1, $v1, -0x2CEC
    ctx->r3 = ADD32(ctx->r3, -0X2CEC);
    // 0x8002D640: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8002D644: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8002D648: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002D64C: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x8002D650: sw          $t7, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r15;
    // 0x8002D654: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8002D658: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002D65C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8002D660: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8002D664: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    // 0x8002D668: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8002D66C: lw          $t1, 0x4($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4);
    // 0x8002D670: bnel        $t1, $zero, L_8002D684
    if (ctx->r9 != 0) {
        // 0x8002D674: lw          $t2, 0x8($a0)
        ctx->r10 = MEM_W(ctx->r4, 0X8);
            goto L_8002D684;
    }
    goto skip_0;
    // 0x8002D674: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
    skip_0:
    // 0x8002D678: b           L_8002D690
    // 0x8002D67C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
        goto L_8002D690;
    // 0x8002D67C: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    // 0x8002D680: lw          $t2, 0x8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8);
L_8002D684:
    // 0x8002D684: bne         $t2, $zero, L_8002D690
    if (ctx->r10 != 0) {
        // 0x8002D688: nop
    
            goto L_8002D690;
    }
    // 0x8002D688: nop

    // 0x8002D68C: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
L_8002D690:
    // 0x8002D690: jal         0x80030350
    // 0x8002D694: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x8002D694: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x8002D698: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002D69C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002D6A0: jr          $ra
    // 0x8002D6A4: nop

    return;
    // 0x8002D6A4: nop

;}
RECOMP_FUNC void scExplainSetPhaseSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DC84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018DC88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DC8C: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8018DC90: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018DC94: jal         0x8018DC0C
    // 0x8018DC98: addiu       $a0, $a0, 0x1F60
    ctx->r4 = ADD32(ctx->r4, 0X1F60);
    scExplainMakeSObjOffset(rdram, ctx);
        goto after_0;
    // 0x8018DC98: addiu       $a0, $a0, 0x1F60
    ctx->r4 = ADD32(ctx->r4, 0X1F60);
    after_0:
    // 0x8018DC9C: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018DCA0: addiu       $s0, $s0, -0x1610
    ctx->r16 = ADD32(ctx->r16, -0X1610);
    // 0x8018DCA4: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x8018DCA8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8018DCAC: jal         0x8018DC0C
    // 0x8018DCB0: addiu       $a0, $a0, -0x2CC8
    ctx->r4 = ADD32(ctx->r4, -0X2CC8);
    scExplainMakeSObjOffset(rdram, ctx);
        goto after_1;
    // 0x8018DCB0: addiu       $a0, $a0, -0x2CC8
    ctx->r4 = ADD32(ctx->r4, -0X2CC8);
    after_1:
    // 0x8018DCB4: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x8018DCB8: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8018DCBC: jal         0x8018DC0C
    // 0x8018DCC0: addiu       $a0, $a0, -0x26B8
    ctx->r4 = ADD32(ctx->r4, -0X26B8);
    scExplainMakeSObjOffset(rdram, ctx);
        goto after_2;
    // 0x8018DCC0: addiu       $a0, $a0, -0x26B8
    ctx->r4 = ADD32(ctx->r4, -0X26B8);
    after_2:
    // 0x8018DCC4: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x8018DCC8: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8018DCCC: jal         0x8018DC0C
    // 0x8018DCD0: addiu       $a0, $a0, -0x20A8
    ctx->r4 = ADD32(ctx->r4, -0X20A8);
    scExplainMakeSObjOffset(rdram, ctx);
        goto after_3;
    // 0x8018DCD0: addiu       $a0, $a0, -0x20A8
    ctx->r4 = ADD32(ctx->r4, -0X20A8);
    after_3:
    // 0x8018DCD4: lui         $a0, 0x1
    ctx->r4 = S32(0X1 << 16);
    // 0x8018DCD8: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8018DCDC: jal         0x8018DC0C
    // 0x8018DCE0: addiu       $a0, $a0, -0x69D8
    ctx->r4 = ADD32(ctx->r4, -0X69D8);
    scExplainMakeSObjOffset(rdram, ctx);
        goto after_4;
    // 0x8018DCE0: addiu       $a0, $a0, -0x69D8
    ctx->r4 = ADD32(ctx->r4, -0X69D8);
    after_4:
    // 0x8018DCE4: lui         $a0, 0x2
    ctx->r4 = S32(0X2 << 16);
    // 0x8018DCE8: addiu       $a0, $a0, -0x1FE8
    ctx->r4 = ADD32(ctx->r4, -0X1FE8);
    // 0x8018DCEC: sw          $v0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r2;
    // 0x8018DCF0: jal         0x8018DC0C
    // 0x8018DCF4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    scExplainMakeSObjOffset(rdram, ctx);
        goto after_5;
    // 0x8018DCF4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_5:
    // 0x8018DCF8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018DCFC: jal         0x8018DC0C
    // 0x8018DD00: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    scExplainMakeSObjOffset(rdram, ctx);
        goto after_6;
    // 0x8018DD00: sw          $v0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r2;
    after_6:
    // 0x8018DD04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DD08: sw          $v0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r2;
    // 0x8018DD0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018DD10: jr          $ra
    // 0x8018DD14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018DD14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftMainClearGroundElementsAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1CF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800E1CF4: addiu       $a0, $a0, 0x119C
    ctx->r4 = ADD32(ctx->r4, 0X119C);
    // 0x800E1CF8: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x800E1CFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E1D00: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E1D04: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E1D08: sw          $zero, 0x1198($at)
    MEM_W(0X1198, ctx->r1) = 0;
    // 0x800E1D0C: addiu       $v0, $v0, 0x1190
    ctx->r2 = ADD32(ctx->r2, 0X1190);
    // 0x800E1D10: addiu       $v1, $v1, 0x1180
    ctx->r3 = ADD32(ctx->r3, 0X1180);
L_800E1D14:
    // 0x800E1D14: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E1D18: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x800E1D1C: bne         $at, $zero, L_800E1D14
    if (ctx->r1 != 0) {
        // 0x800E1D20: sw          $zero, -0x8($v1)
        MEM_W(-0X8, ctx->r3) = 0;
            goto L_800E1D14;
    }
    // 0x800E1D20: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800E1D24: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E1D28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E1D2C: addiu       $v0, $v0, 0x1198
    ctx->r2 = ADD32(ctx->r2, 0X1198);
    // 0x800E1D30: addiu       $v1, $v1, 0x1190
    ctx->r3 = ADD32(ctx->r3, 0X1190);
L_800E1D34:
    // 0x800E1D34: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E1D38: bne         $v1, $v0, L_800E1D34
    if (ctx->r3 != ctx->r2) {
        // 0x800E1D3C: sw          $zero, -0x8($v1)
        MEM_W(-0X8, ctx->r3) = 0;
            goto L_800E1D34;
    }
    // 0x800E1D3C: sw          $zero, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = 0;
    // 0x800E1D40: jr          $ra
    // 0x800E1D44: nop

    return;
    // 0x800E1D44: nop

;}
RECOMP_FUNC void func_ovl8_803772AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803772AC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x803772B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803772B4: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x803772B8: jal         0x80374A54
    // 0x803772BC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    func_ovl8_80374A54(rdram, ctx);
        goto after_0;
    // 0x803772BC: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x803772C0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x803772C4: lhu         $t7, 0x24($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X24);
    // 0x803772C8: lhu         $t0, 0x26($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X26);
    // 0x803772CC: lw          $v0, 0x18($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X18);
    // 0x803772D0: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x803772D4: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x803772D8: lh          $t6, 0x50($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X50);
    // 0x803772DC: addu        $a0, $t6, $a3
    ctx->r4 = ADD32(ctx->r14, ctx->r7);
    // 0x803772E0: bgez        $t7, L_803772F0
    if (SIGNED(ctx->r15) >= 0) {
        // 0x803772E4: sra         $t8, $t7, 1
        ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
            goto L_803772F0;
    }
    // 0x803772E4: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x803772E8: addiu       $at, $t7, 0x1
    ctx->r1 = ADD32(ctx->r15, 0X1);
    // 0x803772EC: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_803772F0:
    // 0x803772F0: subu        $a1, $t9, $t8
    ctx->r5 = SUB32(ctx->r25, ctx->r24);
    // 0x803772F4: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x803772F8: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x803772FC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80377300: bgez        $t0, L_80377310
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80377304: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80377310;
    }
    // 0x80377304: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80377308: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8037730C: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80377310:
    // 0x80377310: subu        $a2, $t2, $t1
    ctx->r6 = SUB32(ctx->r10, ctx->r9);
    // 0x80377314: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80377318: jalr        $t9
    // 0x8037731C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8037731C: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    after_1:
    // 0x80377320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377324: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80377328: jr          $ra
    // 0x8037732C: nop

    return;
    // 0x8037732C: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateMainOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D898: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018D89C: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018D8A0: lhu         $v1, 0xC8($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0XC8);
    // 0x8018D8A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D8A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D8AC: andi        $t6, $v1, 0xC00
    ctx->r14 = ctx->r3 & 0XC00;
    // 0x8018D8B0: beq         $t6, $zero, L_8018D90C
    if (ctx->r14 == 0) {
        // 0x8018D8B4: andi        $t7, $v1, 0x800
        ctx->r15 = ctx->r3 & 0X800;
            goto L_8018D90C;
    }
    // 0x8018D8B4: andi        $t7, $v1, 0x800
    ctx->r15 = ctx->r3 & 0X800;
    // 0x8018D8B8: beql        $t7, $zero, L_8018D8E0
    if (ctx->r15 == 0) {
        // 0x8018D8BC: lw          $t2, 0x0($v0)
        ctx->r10 = MEM_W(ctx->r2, 0X0);
            goto L_8018D8E0;
    }
    goto skip_0;
    // 0x8018D8BC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    skip_0:
    // 0x8018D8C0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8018D8C4: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8018D8C8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x8018D8CC: bgez        $t9, L_8018D8F4
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8018D8D0: sw          $t9, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r25;
            goto L_8018D8F4;
    }
    // 0x8018D8D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8018D8D4: b           L_8018D8F4
    // 0x8018D8D8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_8018D8F4;
    // 0x8018D8D8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8018D8DC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
L_8018D8E0:
    // 0x8018D8E0: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x8018D8E4: slti        $at, $t3, 0x6
    ctx->r1 = SIGNED(ctx->r11) < 0X6 ? 1 : 0;
    // 0x8018D8E8: bne         $at, $zero, L_8018D8F4
    if (ctx->r1 != 0) {
        // 0x8018D8EC: sw          $t3, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r11;
            goto L_8018D8F4;
    }
    // 0x8018D8EC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8018D8F0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8018D8F4:
    // 0x8018D8F4: jal         0x8018FBB0
    // 0x8018D8F8: nop

    sc1PTrainingModeUpdateCursorPosition(rdram, ctx);
        goto after_0;
    // 0x8018D8F8: nop

    after_0:
    // 0x8018D8FC: jal         0x8018D3DC
    // 0x8018D900: nop

    sc1PTrainingModeUpdateScroll(rdram, ctx);
        goto after_1;
    // 0x8018D900: nop

    after_1:
    // 0x8018D904: jal         0x800269C0
    // 0x8018D908: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8018D908: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_2:
L_8018D90C:
    // 0x8018D90C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D910: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D914: jr          $ra
    // 0x8018D918: nop

    return;
    // 0x8018D918: nop

;}
RECOMP_FUNC void ftKirbyCopyFoxSpecialNProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156D38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80156D3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156D40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80156D44: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80156D48: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x80156D4C: beql        $t6, $zero, L_80156DB8
    if (ctx->r14 == 0) {
        // 0x80156D50: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80156DB8;
    }
    goto skip_0;
    // 0x80156D50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80156D54: lhu         $t7, 0x1BE($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1BE);
    // 0x80156D58: lhu         $t8, 0x1B6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X1B6);
    // 0x80156D5C: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80156D60: beql        $t9, $zero, L_80156DB8
    if (ctx->r25 == 0) {
        // 0x80156D64: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80156DB8;
    }
    goto skip_1;
    // 0x80156D64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80156D68: lw          $t0, 0x14C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14C);
    // 0x80156D6C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80156D70: bne         $t0, $at, L_80156D88
    if (ctx->r8 != ctx->r1) {
        // 0x80156D74: nop
    
            goto L_80156D88;
    }
    // 0x80156D74: nop

    // 0x80156D78: jal         0x80156E18
    // 0x80156D7C: nop

    ftKirbyCopyFoxSpecialAirNSetStatus(rdram, ctx);
        goto after_0;
    // 0x80156D7C: nop

    after_0:
    // 0x80156D80: b           L_80156D94
    // 0x80156D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_80156D94;
    // 0x80156D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80156D88:
    // 0x80156D88: jal         0x80156DD8
    // 0x80156D8C: nop

    ftKirbyCopyFoxSpecialNSetStatus(rdram, ctx);
        goto after_1;
    // 0x80156D8C: nop

    after_1:
    // 0x80156D90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80156D94:
    // 0x80156D94: jal         0x800EA5E8
    // 0x80156D98: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    ftParamSetMotionID(rdram, ctx);
        goto after_2;
    // 0x80156D98: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    after_2:
    // 0x80156D9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80156DA0: jal         0x800EA778
    // 0x80156DA4: lhu         $a1, 0x28E($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X28E);
    ftParamSetStatUpdate(rdram, ctx);
        goto after_3;
    // 0x80156DA4: lhu         $a1, 0x28E($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X28E);
    after_3:
    // 0x80156DA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80156DAC: jal         0x800EA7B0
    // 0x80156DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamUpdate1PGameAttackStats(rdram, ctx);
        goto after_4;
    // 0x80156DB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80156DB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80156DB8:
    // 0x80156DB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80156DBC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80156DC0: jr          $ra
    // 0x80156DC4: nop

    return;
    // 0x80156DC4: nop

;}
RECOMP_FUNC void ftCommonOttottoProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801429F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801429F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801429FC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80142A00: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80142A04: jal         0x800DDDA8
    // 0x80142A08: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80142A08: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80142A0C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80142A10: bne         $v0, $zero, L_80142A28
    if (ctx->r2 != 0) {
        // 0x80142A14: lw          $a2, 0x30($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X30);
            goto L_80142A28;
    }
    // 0x80142A14: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80142A18: jal         0x8013F9E0
    // 0x80142A1C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonFallSetStatus(rdram, ctx);
        goto after_1;
    // 0x80142A1C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80142A20: b           L_80142AB8
    // 0x80142A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80142AB8;
    // 0x80142A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80142A28:
    // 0x80142A28: lw          $t6, 0x44($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X44);
    // 0x80142A2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80142A30: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x80142A34: bnel        $t6, $at, L_80142A58
    if (ctx->r14 != ctx->r1) {
        // 0x80142A38: lw          $a0, 0xEC($v1)
        ctx->r4 = MEM_W(ctx->r3, 0XEC);
            goto L_80142A58;
    }
    goto skip_0;
    // 0x80142A38: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    skip_0:
    // 0x80142A3C: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
    // 0x80142A40: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80142A44: jal         0x800F4408
    // 0x80142A48: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_2;
    // 0x80142A48: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    after_2:
    // 0x80142A4C: b           L_80142A64
    // 0x80142A50: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
        goto L_80142A64;
    // 0x80142A50: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80142A54: lw          $a0, 0xEC($v1)
    ctx->r4 = MEM_W(ctx->r3, 0XEC);
L_80142A58:
    // 0x80142A58: jal         0x800F4428
    // 0x80142A5C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_3;
    // 0x80142A5C: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    after_3:
    // 0x80142A60: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
L_80142A64:
    // 0x80142A64: lw          $t7, 0x74($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X74);
    // 0x80142A68: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80142A6C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80142A70: lwc1        $f0, 0x1C($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80142A74: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80142A78: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80142A7C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80142A80: nop

    // 0x80142A84: bc1fl       L_80142A9C
    if (!c1cs) {
        // 0x80142A88: sub.s       $f2, $f0, $f6
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
            goto L_80142A9C;
    }
    goto skip_1;
    // 0x80142A88: sub.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
    skip_1:
    // 0x80142A8C: sub.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x80142A90: b           L_80142A9C
    // 0x80142A94: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80142A9C;
    // 0x80142A94: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x80142A98: sub.s       $f2, $f0, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f6.fl;
L_80142A9C:
    // 0x80142A9C: c.lt.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl < ctx->f2.fl;
    // 0x80142AA0: nop

    // 0x80142AA4: bc1fl       L_80142AB8
    if (!c1cs) {
        // 0x80142AA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80142AB8;
    }
    goto skip_2;
    // 0x80142AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80142AAC: jal         0x8013E1C8
    // 0x80142AB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_4;
    // 0x80142AB0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_4:
    // 0x80142AB4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80142AB8:
    // 0x80142AB8: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80142ABC: jr          $ra
    // 0x80142AC0: nop

    return;
    // 0x80142AC0: nop

;}
RECOMP_FUNC void func_ovl8_80385D34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385D34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80385D38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385D3C: jal         0x80381308
    // 0x80385D40: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    func_ovl8_80381308(rdram, ctx);
        goto after_0;
    // 0x80385D40: addiu       $a0, $a0, 0xB8
    ctx->r4 = ADD32(ctx->r4, 0XB8);
    after_0:
    // 0x80385D44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80385D48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80385D4C: jr          $ra
    // 0x80385D50: nop

    return;
    // 0x80385D50: nop

;}
RECOMP_FUNC void stringToNumber(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386F90: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80386F94: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80386F98: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x80386F9C: bne         $at, $zero, L_80386FD8
    if (ctx->r1 != 0) {
        // 0x80386FA0: slti        $at, $v0, 0x3A
        ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
            goto L_80386FD8;
    }
    // 0x80386FA0: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x80386FA4: beq         $at, $zero, L_80386FD8
    if (ctx->r1 == 0) {
        // 0x80386FA8: addiu       $a1, $zero, 0xA
        ctx->r5 = ADD32(0, 0XA);
            goto L_80386FD8;
    }
    // 0x80386FA8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_80386FAC:
    // 0x80386FAC: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80386FB0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80386FB4: mflo        $t6
    ctx->r14 = lo;
    // 0x80386FB8: addu        $v1, $t6, $v0
    ctx->r3 = ADD32(ctx->r14, ctx->r2);
    // 0x80386FBC: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x80386FC0: addiu       $v1, $v1, -0x30
    ctx->r3 = ADD32(ctx->r3, -0X30);
    // 0x80386FC4: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x80386FC8: bne         $at, $zero, L_80386FD8
    if (ctx->r1 != 0) {
        // 0x80386FCC: slti        $at, $v0, 0x3A
        ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
            goto L_80386FD8;
    }
    // 0x80386FCC: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x80386FD0: bne         $at, $zero, L_80386FAC
    if (ctx->r1 != 0) {
        // 0x80386FD4: nop
    
            goto L_80386FAC;
    }
    // 0x80386FD4: nop

L_80386FD8:
    // 0x80386FD8: jr          $ra
    // 0x80386FDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80386FDC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mvOpeningPikachuStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E05C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E060: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E064: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E068: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018E06C: addiu       $a0, $a0, -0x1EC0
    ctx->r4 = ADD32(ctx->r4, -0X1EC0);
    // 0x8018E070: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E074: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018E078: jal         0x80007024
    // 0x8018E07C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E07C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018E080: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018E084: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E088: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E08C: addiu       $t9, $t9, -0x19C0
    ctx->r25 = ADD32(ctx->r25, -0X19C0);
    // 0x8018E090: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8018E094: addiu       $a0, $a0, -0x1EA4
    ctx->r4 = ADD32(ctx->r4, -0X1EA4);
    // 0x8018E098: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018E09C: jal         0x8000683C
    // 0x8018E0A0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8018E0A0: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8018E0A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E0A8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E0AC: jr          $ra
    // 0x8018E0B0: nop

    return;
    // 0x8018E0B0: nop

;}
RECOMP_FUNC void func_ovl8_80381A58(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381A58: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x80381A5C: sll         $v0, $a1, 3
    ctx->r2 = S32(ctx->r5 << 3);
    // 0x80381A60: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80381A64: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x80381A68: lw          $t9, -0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, -0X8);
    // 0x80381A6C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x80381A70: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x80381A74: lw          $t1, 0xC($t0)
    ctx->r9 = MEM_W(ctx->r8, 0XC);
    // 0x80381A78: addu        $t2, $t1, $v0
    ctx->r10 = ADD32(ctx->r9, ctx->r2);
    // 0x80381A7C: lw          $t3, -0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X4);
    // 0x80381A80: jr          $ra
    // 0x80381A84: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    return;
    // 0x80381A84: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
;}
RECOMP_FUNC void mvOpeningRoomMakeSunlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C84: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C88: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131C8C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131C90: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131C94: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131C98: jal         0x80009968
    // 0x80131C9C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131C9C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131CA0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131CA4: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80131CA8: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80131CAC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CB0: addiu       $t7, $t7, 0x4708
    ctx->r15 = ADD32(ctx->r15, 0X4708);
    // 0x80131CB4: sw          $v0, 0x4D10($at)
    MEM_W(0X4D10, ctx->r1) = ctx->r2;
    // 0x80131CB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131CBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131CC0: jal         0x800092D0
    // 0x80131CC4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80131CC4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131CC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131CCC: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80131CD0: jal         0x80008CC0
    // 0x80131CD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80131CD4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80131CD8: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80131CDC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131CE0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131CE4: addiu       $a1, $a1, 0x43FC
    ctx->r5 = ADD32(ctx->r5, 0X43FC);
    // 0x80131CE8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131CEC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131CF0: jal         0x80009DF4
    // 0x80131CF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80131CF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80131CF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131CFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131D00: jr          $ra
    // 0x80131D04: nop

    return;
    // 0x80131D04: nop

;}
RECOMP_FUNC void ftKirbySpecialNLoopProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162468: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016246C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80162470: jal         0x80162424
    // 0x80162474: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbySpecialNLoopCheckContinueLoop(rdram, ctx);
        goto after_0;
    // 0x80162474: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162478: bnel        $v0, $zero, L_8016248C
    if (ctx->r2 != 0) {
        // 0x8016247C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8016248C;
    }
    goto skip_0;
    // 0x8016247C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80162480: jal         0x80163364
    // 0x80162484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftKirbySpecialNEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162484: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80162488: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8016248C:
    // 0x8016248C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162490: jr          $ra
    // 0x80162494: nop

    return;
    // 0x80162494: nop

;}
RECOMP_FUNC void mnCongraStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013200C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132010: lui         $v1, 0x8032
    ctx->r3 = S32(0X8032 << 16);
    // 0x80132014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132018: ori         $v1, $v1, 0x5400
    ctx->r3 = ctx->r3 | 0X5400;
    // 0x8013201C: lui         $a1, 0x8040
    ctx->r5 = S32(0X8040 << 16);
    // 0x80132020: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
L_80132024:
    // 0x80132024: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80132028: sw          $v0, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r2;
    // 0x8013202C: sw          $v0, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r2;
    // 0x80132030: sw          $v0, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r2;
    // 0x80132034: bne         $v1, $a1, L_80132024
    if (ctx->r3 != ctx->r5) {
        // 0x80132038: sw          $v0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r2;
            goto L_80132024;
    }
    // 0x80132038: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
    // 0x8013203C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80132040: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80132044: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80132048: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8013204C: beq         $v0, $at, L_80132074
    if (ctx->r2 == ctx->r1) {
        // 0x80132050: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_80132074;
    }
    // 0x80132050: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80132054: beq         $v0, $at, L_80132064
    if (ctx->r2 == ctx->r1) {
        // 0x80132058: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132064;
    }
    // 0x80132058: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013205C: b           L_80132084
    // 0x80132060: sw          $zero, 0x22E0($at)
    MEM_W(0X22E0, ctx->r1) = 0;
        goto L_80132084;
    // 0x80132060: sw          $zero, 0x22E0($at)
    MEM_W(0X22E0, ctx->r1) = 0;
L_80132064:
    // 0x80132064: lbu         $t6, 0x14($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X14);
    // 0x80132068: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013206C: b           L_80132084
    // 0x80132070: sw          $t6, 0x22E0($at)
    MEM_W(0X22E0, ctx->r1) = ctx->r14;
        goto L_80132084;
    // 0x80132070: sw          $t6, 0x22E0($at)
    MEM_W(0X22E0, ctx->r1) = ctx->r14;
L_80132074:
    // 0x80132074: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80132078: lbu         $t7, 0x4D2B($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4D2B);
    // 0x8013207C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132080: sw          $t7, 0x22E0($at)
    MEM_W(0X22E0, ctx->r1) = ctx->r15;
L_80132084:
    // 0x80132084: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x80132088: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013208C: addiu       $t8, $t8, 0x5240
    ctx->r24 = ADD32(ctx->r24, 0X5240);
    // 0x80132090: addiu       $a0, $a0, 0x2208
    ctx->r4 = ADD32(ctx->r4, 0X2208);
    // 0x80132094: addiu       $t9, $t8, -0x1900
    ctx->r25 = ADD32(ctx->r24, -0X1900);
    // 0x80132098: jal         0x80007024
    // 0x8013209C: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8013209C: sw          $t9, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r25;
    after_0:
    // 0x801320A0: lui         $t0, 0x8032
    ctx->r8 = S32(0X8032 << 16);
    // 0x801320A4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801320A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801320AC: addiu       $t1, $t1, 0x2300
    ctx->r9 = ADD32(ctx->r9, 0X2300);
    // 0x801320B0: ori         $t0, $t0, 0x5400
    ctx->r8 = ctx->r8 | 0X5400;
    // 0x801320B4: addiu       $a0, $a0, 0x2224
    ctx->r4 = ADD32(ctx->r4, 0X2224);
    // 0x801320B8: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x801320BC: jal         0x8000683C
    // 0x801320C0: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x801320C0: sw          $t2, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r10;
    after_1:
    // 0x801320C4: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x801320C8: addiu       $v0, $v1, 0x2A00
    ctx->r2 = ADD32(ctx->r3, 0X2A00);
    // 0x801320CC: lui         $a1, 0x8040
    ctx->r5 = S32(0X8040 << 16);
    // 0x801320D0: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x801320D4: beq         $at, $zero, L_801320EC
    if (ctx->r1 == 0) {
        // 0x801320D8: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_801320EC;
    }
    // 0x801320D8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801320DC:
    // 0x801320DC: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x801320E0: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x801320E4: bne         $at, $zero, L_801320DC
    if (ctx->r1 != 0) {
        // 0x801320E8: sh          $v1, -0x2($v0)
        MEM_H(-0X2, ctx->r2) = ctx->r3;
            goto L_801320DC;
    }
    // 0x801320E8: sh          $v1, -0x2($v0)
    MEM_H(-0X2, ctx->r2) = ctx->r3;
L_801320EC:
    // 0x801320EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801320F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801320F4: jr          $ra
    // 0x801320F8: nop

    return;
    // 0x801320F8: nop

;}
RECOMP_FUNC void unref_80009ED0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009ED0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009ED4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80009ED8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80009EDC: bne         $a0, $zero, L_80009EEC
    if (ctx->r4 != 0) {
        // 0x80009EE0: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_80009EEC;
    }
    // 0x80009EE0: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80009EE4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80009EE8: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
L_80009EEC:
    // 0x80009EEC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x80009EF0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80009EF4: lbu         $a2, 0xD($t6)
    ctx->r6 = MEM_BU(ctx->r14, 0XD);
    // 0x80009EF8: lw          $a3, 0x28($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X28);
    // 0x80009EFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80009F00: jal         0x80009D78
    // 0x80009F04: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    gcLinkGObjDLCommon(rdram, ctx);
        goto after_0;
    // 0x80009F04: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x80009F08: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80009F0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80009F10: jal         0x80007B98
    // 0x80009F14: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    gcAppendGObjToDLLinkedList(rdram, ctx);
        goto after_1;
    // 0x80009F14: lw          $a1, 0x8($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X8);
    after_1:
    // 0x80009F18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009F1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009F20: jr          $ra
    // 0x80009F24: nop

    return;
    // 0x80009F24: nop

;}
RECOMP_FUNC void sc1PGameSetPlayerInterfacePositions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E598: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018E59C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018E5A0: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x8018E5A4: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
    // 0x8018E5A8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8018E5AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018E5B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018E5B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018E5B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018E5BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018E5C0: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x8018E5C4: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x8018E5C8: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018E5CC: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x8018E5D0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8018E5D4: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8018E5D8: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x8018E5DC: lw          $s0, 0x2AF8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X2AF8);
    // 0x8018E5E0: lbu         $s1, 0x4AE3($s1)
    ctx->r17 = MEM_BU(ctx->r17, 0X4AE3);
    // 0x8018E5E4: blez        $v0, L_8018E634
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8018E5E8: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8018E634;
    }
    // 0x8018E5E8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018E5EC: lui         $s4, 0x8019
    ctx->r20 = S32(0X8019 << 16);
    // 0x8018E5F0: addiu       $s4, $s4, 0x38B8
    ctx->r20 = ADD32(ctx->r20, 0X38B8);
    // 0x8018E5F4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_8018E5F8:
    // 0x8018E5F8: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8018E5FC: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x8018E600: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018E604: jal         0x8018D280
    // 0x8018E608: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    sc1PGameGetNextFreePlayerPort(rdram, ctx);
        goto after_0;
    // 0x8018E608: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    after_0:
    // 0x8018E60C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x8018E610: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8018E614: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8018E618: lbu         $t2, 0x4($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X4);
    // 0x8018E61C: lbu         $t3, 0x5($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X5);
    // 0x8018E620: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018E624: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8018E628: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8018E62C: bnel        $at, $zero, L_8018E5F8
    if (ctx->r1 != 0) {
        // 0x8018E630: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_8018E5F8;
    }
    goto skip_0;
    // 0x8018E630: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_0:
L_8018E634:
    // 0x8018E634: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8018E638: lui         $s4, 0x8019
    ctx->r20 = S32(0X8019 << 16);
    // 0x8018E63C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E640: addiu       $s4, $s4, 0x38B8
    ctx->r20 = ADD32(ctx->r20, 0X38B8);
    // 0x8018E644: addiu       $v0, $v0, 0x1580
    ctx->r2 = ADD32(ctx->r2, 0X1580);
    // 0x8018E648: sw          $s4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r20;
    // 0x8018E64C: addiu       $t5, $zero, 0xD2
    ctx->r13 = ADD32(0, 0XD2);
    // 0x8018E650: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018E654: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018E658: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E65C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018E660: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018E664: sh          $t5, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r13;
    // 0x8018E668: jr          $ra
    // 0x8018E66C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018E66C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl0_800CA194(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CA194: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x800CA198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CA19C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CA1A0: sw          $a1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r5;
    // 0x800CA1A4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    // 0x800CA1A8: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800CA1AC: addiu       $t1, $a0, 0x20
    ctx->r9 = ADD32(ctx->r4, 0X20);
    // 0x800CA1B0: lwc1        $f12, 0x38($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X38);
    // 0x800CA1B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CA1B8: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x800CA1BC: jal         0x800303F0
    // 0x800CA1C0: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    __sinf_recomp(rdram, ctx);
        goto after_0;
    // 0x800CA1C0: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_0:
    // 0x800CA1C4: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x800CA1C8: lwc1        $f12, 0x38($t8)
    ctx->f12.u32l = MEM_W(ctx->r24, 0X38);
    // 0x800CA1CC: jal         0x80035CD0
    // 0x800CA1D0: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x800CA1D0: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800CA1D4: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x800CA1D8: addiu       $v0, $v0, 0x6FA8
    ctx->r2 = ADD32(ctx->r2, 0X6FA8);
    // 0x800CA1DC: lwc1        $f14, 0x60($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800CA1E0: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CA1E4: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CA1E8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800CA1EC: mul.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f14.fl);
    // 0x800CA1F0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800CA1F4: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x800CA1F8: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA1FC: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CA200: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x800CA204: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800CA208: neg.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = -ctx->f14.fl;
    // 0x800CA20C: addiu       $a3, $s0, 0x14
    ctx->r7 = ADD32(ctx->r16, 0X14);
    // 0x800CA210: addiu       $t0, $t0, 0x14
    ctx->r8 = ADD32(ctx->r8, 0X14);
    // 0x800CA214: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CA218: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CA21C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800CA220: nop

    // 0x800CA224: mul.s       $f6, $f8, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x800CA228: nop

    // 0x800CA22C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CA230: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800CA234: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800CA238: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800CA23C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800CA240: and         $t3, $a0, $a2
    ctx->r11 = ctx->r4 & ctx->r6;
    // 0x800CA244: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800CA248: and         $t8, $t7, $a2
    ctx->r24 = ctx->r15 & ctx->r6;
    // 0x800CA24C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CA250: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800CA254: nop

    // 0x800CA258: sra         $t4, $a1, 16
    ctx->r12 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800CA25C: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800CA260: or          $t6, $t3, $t5
    ctx->r14 = ctx->r11 | ctx->r13;
    // 0x800CA264: andi        $t9, $a1, 0xFFFF
    ctx->r25 = ctx->r5 & 0XFFFF;
    // 0x800CA268: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800CA26C: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x800CA270: sw          $t2, -0x14($t0)
    MEM_W(-0X14, ctx->r8) = ctx->r10;
    // 0x800CA274: lwc1        $f10, 0x18($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CA278: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CA27C: mul.s       $f6, $f10, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800CA280: nop

    // 0x800CA284: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800CA288: lwc1        $f16, 0x1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CA28C: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800CA290: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CA294: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CA298: nop

    // 0x800CA29C: mul.s       $f6, $f16, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800CA2A0: nop

    // 0x800CA2A4: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800CA2A8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA2AC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800CA2B0: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800CA2B4: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800CA2B8: and         $t5, $a0, $a2
    ctx->r13 = ctx->r4 & ctx->r6;
    // 0x800CA2BC: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x800CA2C0: and         $t2, $t9, $a2
    ctx->r10 = ctx->r25 & ctx->r6;
    // 0x800CA2C4: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CA2C8: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x800CA2CC: nop

    // 0x800CA2D0: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800CA2D4: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CA2D8: or          $t8, $t5, $t7
    ctx->r24 = ctx->r13 | ctx->r15;
    // 0x800CA2DC: andi        $t4, $a1, 0xFFFF
    ctx->r12 = ctx->r5 & 0XFFFF;
    // 0x800CA2E0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800CA2E4: or          $t3, $t2, $t4
    ctx->r11 = ctx->r10 | ctx->r12;
    // 0x800CA2E8: sw          $t3, -0x10($t0)
    MEM_W(-0X10, ctx->r8) = ctx->r11;
    // 0x800CA2EC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800CA2F0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800CA2F4: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800CA2F8: nop

    // 0x800CA2FC: mul.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800CA300: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800CA304: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CA308: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800CA30C: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800CA310: nop

    // 0x800CA314: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CA318: nop

    // 0x800CA31C: mul.s       $f10, $f8, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800CA320: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800CA324: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800CA328: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800CA32C: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800CA330: and         $t7, $a0, $a2
    ctx->r15 = ctx->r4 & ctx->r6;
    // 0x800CA334: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x800CA338: and         $t3, $t4, $a2
    ctx->r11 = ctx->r12 & ctx->r6;
    // 0x800CA33C: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800CA340: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800CA344: nop

    // 0x800CA348: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800CA34C: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800CA350: or          $t2, $t7, $t9
    ctx->r10 = ctx->r15 | ctx->r25;
    // 0x800CA354: andi        $t6, $a1, 0xFFFF
    ctx->r14 = ctx->r5 & 0XFFFF;
    // 0x800CA358: sw          $t2, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r10;
    // 0x800CA35C: or          $t5, $t3, $t6
    ctx->r13 = ctx->r11 | ctx->r14;
    // 0x800CA360: sw          $t5, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r13;
    // 0x800CA364: lwc1        $f8, 0x18($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X18);
    // 0x800CA368: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800CA36C: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CA370: nop

    // 0x800CA374: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800CA378: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800CA37C: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800CA380: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800CA384: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800CA388: nop

    // 0x800CA38C: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800CA390: nop

    // 0x800CA394: mul.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800CA398: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800CA39C: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800CA3A0: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800CA3A4: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CA3A8: and         $t9, $a0, $a2
    ctx->r25 = ctx->r4 & ctx->r6;
    // 0x800CA3AC: sll         $t6, $a0, 16
    ctx->r14 = S32(ctx->r4 << 16);
    // 0x800CA3B0: and         $t5, $t6, $a2
    ctx->r13 = ctx->r14 & ctx->r6;
    // 0x800CA3B4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA3B8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800CA3BC: nop

    // 0x800CA3C0: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800CA3C4: andi        $t4, $t2, 0xFFFF
    ctx->r12 = ctx->r10 & 0XFFFF;
    // 0x800CA3C8: or          $t3, $t9, $t4
    ctx->r11 = ctx->r25 | ctx->r12;
    // 0x800CA3CC: andi        $t8, $a1, 0xFFFF
    ctx->r24 = ctx->r5 & 0XFFFF;
    // 0x800CA3D0: sw          $t3, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r11;
    // 0x800CA3D4: or          $t7, $t5, $t8
    ctx->r15 = ctx->r13 | ctx->r24;
    // 0x800CA3D8: sw          $t7, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r15;
    // 0x800CA3DC: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800CA3E0: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800CA3E4: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800CA3E8: nop

    // 0x800CA3EC: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CA3F0: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CA3F4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA3F8: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800CA3FC: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800CA400: and         $t4, $a0, $a2
    ctx->r12 = ctx->r4 & ctx->r6;
    // 0x800CA404: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x800CA408: sra         $t3, $a1, 16
    ctx->r11 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800CA40C: andi        $t6, $t3, 0xFFFF
    ctx->r14 = ctx->r11 & 0XFFFF;
    // 0x800CA410: or          $t5, $t4, $t6
    ctx->r13 = ctx->r12 | ctx->r14;
    // 0x800CA414: and         $t7, $t8, $a2
    ctx->r15 = ctx->r24 & ctx->r6;
    // 0x800CA418: andi        $t2, $a1, 0xFFFF
    ctx->r10 = ctx->r5 & 0XFFFF;
    // 0x800CA41C: sw          $t5, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r13;
    // 0x800CA420: or          $t9, $t7, $t2
    ctx->r25 = ctx->r15 | ctx->r10;
    // 0x800CA424: sw          $t9, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r25;
    // 0x800CA428: lwc1        $f16, 0x28($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800CA42C: lwc1        $f4, 0x2C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800CA430: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CA434: mul.s       $f6, $f16, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800CA438: nop

    // 0x800CA43C: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800CA440: trunc.w.s   $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800CA444: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CA448: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800CA44C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800CA450: and         $t6, $a0, $a2
    ctx->r14 = ctx->r4 & ctx->r6;
    // 0x800CA454: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x800CA458: sra         $t5, $a1, 16
    ctx->r13 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800CA45C: andi        $t8, $t5, 0xFFFF
    ctx->r24 = ctx->r13 & 0XFFFF;
    // 0x800CA460: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800CA464: and         $t9, $t2, $a2
    ctx->r25 = ctx->r10 & ctx->r6;
    // 0x800CA468: andi        $t3, $a1, 0xFFFF
    ctx->r11 = ctx->r5 & 0XFFFF;
    // 0x800CA46C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800CA470: or          $t4, $t9, $t3
    ctx->r12 = ctx->r25 | ctx->r11;
    // 0x800CA474: lui         $t5, 0xD500
    ctx->r13 = S32(0XD500 << 16);
    // 0x800CA478: sw          $t4, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r12;
    // 0x800CA47C: ori         $t5, $t5, 0x1
    ctx->r13 = ctx->r13 | 0X1;
    // 0x800CA480: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800CA484: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800CA488: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x800CA48C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x800CA490: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CA494: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800CA498: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800CA49C: ori         $t7, $t7, 0x4
    ctx->r15 = ctx->r15 | 0X4;
    // 0x800CA4A0: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x800CA4A4: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CA4A8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800CA4AC: lw          $t2, 0x4($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4);
    // 0x800CA4B0: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x800CA4B4: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800CA4B8: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800CA4BC: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x800CA4C0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CA4C4: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x800CA4C8: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
    // 0x800CA4CC: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x800CA4D0: ori         $t4, $t4, 0xC
    ctx->r12 = ctx->r12 | 0XC;
    // 0x800CA4D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CA4D8: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x800CA4DC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800CA4E0: lw          $t5, 0xC($s0)
    ctx->r13 = MEM_W(ctx->r16, 0XC);
    // 0x800CA4E4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x800CA4E8: ori         $t6, $t6, 0x10
    ctx->r14 = ctx->r14 | 0X10;
    // 0x800CA4EC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800CA4F0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800CA4F4: lw          $t8, 0x10($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X10);
    // 0x800CA4F8: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800CA4FC: ori         $t7, $t7, 0x14
    ctx->r15 = ctx->r15 | 0X14;
    // 0x800CA500: addiu       $a1, $a0, 0x8
    ctx->r5 = ADD32(ctx->r4, 0X8);
    // 0x800CA504: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x800CA508: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800CA50C: lw          $t2, 0x14($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X14);
    // 0x800CA510: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x800CA514: ori         $t9, $t9, 0x20
    ctx->r25 = ctx->r25 | 0X20;
    // 0x800CA518: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800CA51C: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x800CA520: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CA524: lw          $t3, 0x20($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X20);
    // 0x800CA528: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x800CA52C: ori         $t4, $t4, 0x24
    ctx->r12 = ctx->r12 | 0X24;
    // 0x800CA530: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x800CA534: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x800CA538: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800CA53C: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x800CA540: lui         $t6, 0xDB00
    ctx->r14 = S32(0XDB00 << 16);
    // 0x800CA544: ori         $t6, $t6, 0x28
    ctx->r14 = ctx->r14 | 0X28;
    // 0x800CA548: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800CA54C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800CA550: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800CA554: lw          $t8, 0x28($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X28);
    // 0x800CA558: lui         $t7, 0xDB00
    ctx->r15 = S32(0XDB00 << 16);
    // 0x800CA55C: ori         $t7, $t7, 0x2C
    ctx->r15 = ctx->r15 | 0X2C;
    // 0x800CA560: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x800CA564: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800CA568: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800CA56C: lw          $t2, 0x2C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X2C);
    // 0x800CA570: lui         $t9, 0xDB00
    ctx->r25 = S32(0XDB00 << 16);
    // 0x800CA574: ori         $t9, $t9, 0x30
    ctx->r25 = ctx->r25 | 0X30;
    // 0x800CA578: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800CA57C: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x800CA580: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800CA584: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x800CA588: lui         $t4, 0xDB00
    ctx->r12 = S32(0XDB00 << 16);
    // 0x800CA58C: ori         $t4, $t4, 0x34
    ctx->r12 = ctx->r12 | 0X34;
    // 0x800CA590: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x800CA594: sw          $t3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r11;
    // 0x800CA598: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800CA59C: lw          $t5, 0x34($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X34);
    // 0x800CA5A0: addiu       $v1, $a0, 0x8
    ctx->r3 = ADD32(ctx->r4, 0X8);
    // 0x800CA5A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800CA5A8: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
    // 0x800CA5AC: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800CA5B0: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x800CA5B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CA5B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CA5BC: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    // 0x800CA5C0: jr          $ra
    // 0x800CA5C4: nop

    return;
    // 0x800CA5C4: nop

;}
RECOMP_FUNC void ftLinkSpecialNEmptySwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016392C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80163930: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80163934: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80163938: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016393C: jal         0x800DEEC8
    // 0x80163940: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80163940: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80163944: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80163948: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x8016394C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163950: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80163954: jal         0x800E6F24
    // 0x80163958: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80163958: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8016395C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80163960: lbu         $t8, 0x192($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X192);
    // 0x80163964: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x80163968: sb          $t9, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r25;
    // 0x8016396C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163970: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80163974: jr          $ra
    // 0x80163978: nop

    return;
    // 0x80163978: nop

;}
RECOMP_FUNC void spClearAttribute(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80025EF0: lhu         $t6, 0x14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X14);
    // 0x80025EF4: nor         $t7, $a1, $zero
    ctx->r15 = ~(ctx->r5 | 0);
    // 0x80025EF8: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80025EFC: jr          $ra
    // 0x80025F00: sh          $t8, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r24;
    return;
    // 0x80025F00: sh          $t8, 0x14($a0)
    MEM_H(0X14, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void ftDonkeySpecialHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B974: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015B978: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015B97C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015B980: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x8015B984: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8015B988: jal         0x800DEEC8
    // 0x8015B98C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015B98C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x8015B990: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B994: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015B998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8015B99C: swc1        $f4, 0x4C($a2)
    MEM_W(0X4C, ctx->r6) = ctx->f4.u32l;
    // 0x8015B9A0: jal         0x8015B8E8
    // 0x8015B9A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftDonkeySpecialHiSetStatusFlagGA(rdram, ctx);
        goto after_1;
    // 0x8015B9A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015B9A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015B9AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015B9B0: jr          $ra
    // 0x8015B9B4: nop

    return;
    // 0x8015B9B4: nop

;}
RECOMP_FUNC void ftMainProcPhysicsMapDefault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2604: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E2608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E260C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E2610: lw          $t6, 0x844($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X844);
    // 0x800E2614: beql        $t6, $zero, L_800E2630
    if (ctx->r14 == 0) {
        // 0x800E2618: lw          $t0, 0x840($v0)
        ctx->r8 = MEM_W(ctx->r2, 0X840);
            goto L_800E2630;
    }
    goto skip_0;
    // 0x800E2618: lw          $t0, 0x840($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X840);
    skip_0:
    // 0x800E261C: lw          $t7, 0x190($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X190);
    // 0x800E2620: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x800E2624: bgezl       $t9, L_800E2654
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800E2628: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E2654;
    }
    goto skip_1;
    // 0x800E2628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800E262C: lw          $t0, 0x840($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X840);
L_800E2630:
    // 0x800E2630: beq         $t0, $zero, L_800E2648
    if (ctx->r8 == 0) {
        // 0x800E2634: nop
    
            goto L_800E2648;
    }
    // 0x800E2634: nop

    // 0x800E2638: lw          $t1, 0x190($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X190);
    // 0x800E263C: sll         $t3, $t1, 19
    ctx->r11 = S32(ctx->r9 << 19);
    // 0x800E2640: bltzl       $t3, L_800E2654
    if (SIGNED(ctx->r11) < 0) {
        // 0x800E2644: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800E2654;
    }
    goto skip_2;
    // 0x800E2644: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
L_800E2648:
    // 0x800E2648: jal         0x800E2048
    // 0x800E264C: nop

    ftMainProcPhysicsMap(rdram, ctx);
        goto after_0;
    // 0x800E264C: nop

    after_0:
    // 0x800E2650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800E2654:
    // 0x800E2654: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E2658: jr          $ra
    // 0x800E265C: nop

    return;
    // 0x800E265C: nop

;}
RECOMP_FUNC void func_ovl8_8037BE34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BE34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037BE38: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8037BE3C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037BE40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8037BE44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8037BE48: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8037BE4C: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
L_8037BE50:
    // 0x8037BE50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8037BE54: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x8037BE58: lh          $t6, 0x40($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X40);
    // 0x8037BE5C: jalr        $t9
    // 0x8037BE60: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037BE60: addu        $a0, $t6, $s0
    ctx->r4 = ADD32(ctx->r14, ctx->r16);
    after_0:
    // 0x8037BE64: jal         0x8000B1E8
    // 0x8037BE68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x8037BE68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8037BE6C: b           L_8037BE50
    // 0x8037BE70: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
        goto L_8037BE50;
    // 0x8037BE70: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x8037BE74: nop

    // 0x8037BE78: nop

    // 0x8037BE7C: nop

    // 0x8037BE80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037BE84: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8037BE88: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8037BE8C: jr          $ra
    // 0x8037BE90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8037BE90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftParamGetHitStun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA1B0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800EA1B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EA1B8: jr          $ra
    // 0x800EA1BC: div.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    return;
    // 0x800EA1BC: div.s       $f0, $f12, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
;}
RECOMP_FUNC void ftMainProcUpdateInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1260: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E1264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E1268: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E126C: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x800E1270: lw          $v0, 0x18C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18C);
    // 0x800E1274: sll         $v0, $v0, 30
    ctx->r2 = S32(ctx->r2 << 30);
    // 0x800E1278: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x800E127C: bne         $v0, $zero, L_800E129C
    if (ctx->r2 != 0) {
        // 0x800E1280: nop
    
            goto L_800E129C;
    }
    // 0x800E1280: nop

    // 0x800E1284: lw          $t7, 0x1C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X1C);
    // 0x800E1288: lw          $v0, 0x18C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X18C);
    // 0x800E128C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800E1290: sll         $v0, $v0, 30
    ctx->r2 = S32(ctx->r2 << 30);
    // 0x800E1294: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x800E1298: sw          $t8, 0x1C($a2)
    MEM_W(0X1C, ctx->r6) = ctx->r24;
L_800E129C:
    // 0x800E129C: bnel        $v0, $zero, L_800E1684
    if (ctx->r2 != 0) {
        // 0x800E12A0: lw          $v0, 0x160($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X160);
            goto L_800E1684;
    }
    goto skip_0;
    // 0x800E12A0: lw          $v0, 0x160($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X160);
    skip_0:
    // 0x800E12A4: lw          $v0, 0x20($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X20);
    // 0x800E12A8: lb          $t9, 0x1C2($a2)
    ctx->r25 = MEM_B(ctx->r6, 0X1C2);
    // 0x800E12AC: lb          $t2, 0x1C3($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X1C3);
    // 0x800E12B0: sb          $t9, 0x1C4($a2)
    MEM_B(0X1C4, ctx->r6) = ctx->r25;
    // 0x800E12B4: beq         $v0, $zero, L_800E12E8
    if (ctx->r2 == 0) {
        // 0x800E12B8: sb          $t2, 0x1C5($a2)
        MEM_B(0X1C5, ctx->r6) = ctx->r10;
            goto L_800E12E8;
    }
    // 0x800E12B8: sb          $t2, 0x1C5($a2)
    MEM_B(0X1C5, ctx->r6) = ctx->r10;
    // 0x800E12BC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E12C0: beq         $v0, $at, L_800E1380
    if (ctx->r2 == ctx->r1) {
        // 0x800E12C4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800E1380;
    }
    // 0x800E12C4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E12C8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800E12CC: beq         $v0, $at, L_800E1390
    if (ctx->r2 == ctx->r1) {
        // 0x800E12D0: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800E1390;
    }
    // 0x800E12D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E12D4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E12D8: beq         $v0, $at, L_800E1390
    if (ctx->r2 == ctx->r1) {
        // 0x800E12DC: nop
    
            goto L_800E1390;
    }
    // 0x800E12DC: nop

    // 0x800E12E0: b           L_800E1430
    // 0x800E12E4: addiu       $v0, $a2, 0x1BC
    ctx->r2 = ADD32(ctx->r6, 0X1BC);
        goto L_800E1430;
    // 0x800E12E4: addiu       $v0, $a2, 0x1BC
    ctx->r2 = ADD32(ctx->r6, 0X1BC);
L_800E12E8:
    // 0x800E12E8: lw          $a0, 0x1B0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X1B0);
    // 0x800E12EC: lhu         $a3, 0x0($a0)
    ctx->r7 = MEM_HU(ctx->r4, 0X0);
    // 0x800E12F0: andi        $t3, $a3, 0x10
    ctx->r11 = ctx->r7 & 0X10;
    // 0x800E12F4: beq         $t3, $zero, L_800E1308
    if (ctx->r11 == 0) {
        // 0x800E12F8: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800E1308;
    }
    // 0x800E12F8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800E12FC: ori         $a3, $a1, 0xA000
    ctx->r7 = ctx->r5 | 0XA000;
    // 0x800E1300: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x800E1304: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_800E1308:
    // 0x800E1308: lb          $t4, 0x8($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X8);
    // 0x800E130C: addiu       $v0, $a2, 0x1BC
    ctx->r2 = ADD32(ctx->r6, 0X1BC);
    // 0x800E1310: lhu         $t6, 0x0($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X0);
    // 0x800E1314: sb          $t4, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r12;
    // 0x800E1318: lb          $t5, 0x9($a0)
    ctx->r13 = MEM_B(ctx->r4, 0X9);
    // 0x800E131C: xor         $t7, $a1, $t6
    ctx->r15 = ctx->r5 ^ ctx->r14;
    // 0x800E1320: and         $v1, $t7, $a1
    ctx->r3 = ctx->r15 & ctx->r5;
    // 0x800E1324: sb          $t5, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r13;
    // 0x800E1328: lw          $t8, 0x40($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X40);
    // 0x800E132C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800E1330: beql        $t8, $zero, L_800E134C
    if (ctx->r24 == 0) {
        // 0x800E1334: sh          $v1, 0x2($v0)
        MEM_H(0X2, ctx->r2) = ctx->r3;
            goto L_800E134C;
    }
    goto skip_1;
    // 0x800E1334: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    skip_1:
    // 0x800E1338: lhu         $t9, 0x2($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X2);
    // 0x800E133C: or          $t2, $t9, $v1
    ctx->r10 = ctx->r25 | ctx->r3;
    // 0x800E1340: b           L_800E134C
    // 0x800E1344: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
        goto L_800E134C;
    // 0x800E1344: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x800E1348: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
L_800E134C:
    // 0x800E134C: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800E1350: lw          $t4, 0x40($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X40);
    // 0x800E1354: xor         $t3, $a1, $a0
    ctx->r11 = ctx->r5 ^ ctx->r4;
    // 0x800E1358: and         $v1, $t3, $a0
    ctx->r3 = ctx->r11 & ctx->r4;
    // 0x800E135C: beq         $t4, $zero, L_800E1374
    if (ctx->r12 == 0) {
        // 0x800E1360: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_800E1374;
    }
    // 0x800E1360: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800E1364: lhu         $t5, 0x4($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X4);
    // 0x800E1368: or          $t6, $t5, $v1
    ctx->r14 = ctx->r13 | ctx->r3;
    // 0x800E136C: b           L_800E1378
    // 0x800E1370: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
        goto L_800E1378;
    // 0x800E1370: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
L_800E1374:
    // 0x800E1374: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_800E1378:
    // 0x800E1378: b           L_800E1430
    // 0x800E137C: sh          $a3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r7;
        goto L_800E1430;
    // 0x800E137C: sh          $a3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r7;
L_800E1380:
    // 0x800E1380: jal         0x8013A834
    // 0x800E1384: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftComputerProcessAll(rdram, ctx);
        goto after_0;
    // 0x800E1384: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E1388: b           L_800E139C
    // 0x800E138C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
        goto L_800E139C;
    // 0x800E138C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800E1390:
    // 0x800E1390: jal         0x80115B10
    // 0x800E1394: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftKeyProcessKeyEvents(rdram, ctx);
        goto after_1;
    // 0x800E1394: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_1:
    // 0x800E1398: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800E139C:
    // 0x800E139C: lhu         $a3, 0x1C6($a2)
    ctx->r7 = MEM_HU(ctx->r6, 0X1C6);
    // 0x800E13A0: addiu       $a0, $a2, 0x1C6
    ctx->r4 = ADD32(ctx->r6, 0X1C6);
    // 0x800E13A4: andi        $t7, $a3, 0x10
    ctx->r15 = ctx->r7 & 0X10;
    // 0x800E13A8: beq         $t7, $zero, L_800E13BC
    if (ctx->r15 == 0) {
        // 0x800E13AC: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_800E13BC;
    }
    // 0x800E13AC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x800E13B0: ori         $a3, $a1, 0xA000
    ctx->r7 = ctx->r5 | 0XA000;
    // 0x800E13B4: andi        $a3, $a3, 0xFFFF
    ctx->r7 = ctx->r7 & 0XFFFF;
    // 0x800E13B8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
L_800E13BC:
    // 0x800E13BC: lb          $t8, 0x2($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X2);
    // 0x800E13C0: addiu       $v0, $a2, 0x1BC
    ctx->r2 = ADD32(ctx->r6, 0X1BC);
    // 0x800E13C4: lhu         $t2, 0x0($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X0);
    // 0x800E13C8: sb          $t8, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r24;
    // 0x800E13CC: lb          $t9, 0x3($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X3);
    // 0x800E13D0: xor         $t3, $a1, $t2
    ctx->r11 = ctx->r5 ^ ctx->r10;
    // 0x800E13D4: and         $v1, $t3, $a1
    ctx->r3 = ctx->r11 & ctx->r5;
    // 0x800E13D8: sb          $t9, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r25;
    // 0x800E13DC: lw          $t4, 0x40($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X40);
    // 0x800E13E0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800E13E4: beql        $t4, $zero, L_800E1400
    if (ctx->r12 == 0) {
        // 0x800E13E8: sh          $v1, 0x2($v0)
        MEM_H(0X2, ctx->r2) = ctx->r3;
            goto L_800E1400;
    }
    goto skip_2;
    // 0x800E13E8: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
    skip_2:
    // 0x800E13EC: lhu         $t5, 0x2($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X2);
    // 0x800E13F0: or          $t6, $t5, $v1
    ctx->r14 = ctx->r13 | ctx->r3;
    // 0x800E13F4: b           L_800E1400
    // 0x800E13F8: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
        goto L_800E1400;
    // 0x800E13F8: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x800E13FC: sh          $v1, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r3;
L_800E1400:
    // 0x800E1400: lhu         $a0, 0x0($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X0);
    // 0x800E1404: lw          $t8, 0x40($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X40);
    // 0x800E1408: xor         $t7, $a1, $a0
    ctx->r15 = ctx->r5 ^ ctx->r4;
    // 0x800E140C: and         $v1, $t7, $a0
    ctx->r3 = ctx->r15 & ctx->r4;
    // 0x800E1410: beq         $t8, $zero, L_800E1428
    if (ctx->r24 == 0) {
        // 0x800E1414: andi        $v1, $v1, 0xFFFF
        ctx->r3 = ctx->r3 & 0XFFFF;
            goto L_800E1428;
    }
    // 0x800E1414: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800E1418: lhu         $t9, 0x4($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X4);
    // 0x800E141C: or          $t2, $t9, $v1
    ctx->r10 = ctx->r25 | ctx->r3;
    // 0x800E1420: b           L_800E142C
    // 0x800E1424: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
        goto L_800E142C;
    // 0x800E1424: sh          $t2, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r10;
L_800E1428:
    // 0x800E1428: sh          $v1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r3;
L_800E142C:
    // 0x800E142C: sh          $a3, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r7;
L_800E1430:
    // 0x800E1430: lb          $v1, 0x6($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X6);
    // 0x800E1434: addiu       $t3, $zero, 0x50
    ctx->r11 = ADD32(0, 0X50);
    // 0x800E1438: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800E143C: slti        $at, $v1, 0x51
    ctx->r1 = SIGNED(ctx->r3) < 0X51 ? 1 : 0;
    // 0x800E1440: bnel        $at, $zero, L_800E1454
    if (ctx->r1 != 0) {
        // 0x800E1444: slti        $at, $v1, -0x50
        ctx->r1 = SIGNED(ctx->r3) < -0X50 ? 1 : 0;
            goto L_800E1454;
    }
    goto skip_3;
    // 0x800E1444: slti        $at, $v1, -0x50
    ctx->r1 = SIGNED(ctx->r3) < -0X50 ? 1 : 0;
    skip_3:
    // 0x800E1448: sb          $t3, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r11;
    // 0x800E144C: lb          $v1, 0x6($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X6);
    // 0x800E1450: slti        $at, $v1, -0x50
    ctx->r1 = SIGNED(ctx->r3) < -0X50 ? 1 : 0;
L_800E1454:
    // 0x800E1454: beq         $at, $zero, L_800E1460
    if (ctx->r1 == 0) {
        // 0x800E1458: addiu       $t4, $zero, -0x50
        ctx->r12 = ADD32(0, -0X50);
            goto L_800E1460;
    }
    // 0x800E1458: addiu       $t4, $zero, -0x50
    ctx->r12 = ADD32(0, -0X50);
    // 0x800E145C: sb          $t4, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r12;
L_800E1460:
    // 0x800E1460: lb          $v1, 0x7($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X7);
    // 0x800E1464: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x800E1468: addiu       $t6, $zero, -0x50
    ctx->r14 = ADD32(0, -0X50);
    // 0x800E146C: slti        $at, $v1, 0x51
    ctx->r1 = SIGNED(ctx->r3) < 0X51 ? 1 : 0;
    // 0x800E1470: bnel        $at, $zero, L_800E1484
    if (ctx->r1 != 0) {
        // 0x800E1474: slti        $at, $v1, -0x50
        ctx->r1 = SIGNED(ctx->r3) < -0X50 ? 1 : 0;
            goto L_800E1484;
    }
    goto skip_4;
    // 0x800E1474: slti        $at, $v1, -0x50
    ctx->r1 = SIGNED(ctx->r3) < -0X50 ? 1 : 0;
    skip_4:
    // 0x800E1478: sb          $t5, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r13;
    // 0x800E147C: lb          $v1, 0x7($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X7);
    // 0x800E1480: slti        $at, $v1, -0x50
    ctx->r1 = SIGNED(ctx->r3) < -0X50 ? 1 : 0;
L_800E1484:
    // 0x800E1484: beq         $at, $zero, L_800E1490
    if (ctx->r1 == 0) {
        // 0x800E1488: nop
    
            goto L_800E1490;
    }
    // 0x800E1488: nop

    // 0x800E148C: sb          $t6, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r14;
L_800E1490:
    // 0x800E1490: lbu         $t7, 0x4AC2($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4AC2);
    // 0x800E1494: lb          $v1, 0x6($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X6);
    // 0x800E1498: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x800E149C: beql        $t8, $zero, L_800E14F0
    if (ctx->r24 == 0) {
        // 0x800E14A0: slti        $at, $v1, 0x14
        ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
            goto L_800E14F0;
    }
    goto skip_5;
    // 0x800E14A0: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    skip_5:
    // 0x800E14A4: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800E14A8: lb          $t3, 0x7($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X7);
    // 0x800E14AC: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800E14B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E14B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800E14B8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800E14BC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800E14C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E14C4: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800E14C8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800E14CC: mfc1        $t2, $f10
    ctx->r10 = (int32_t)ctx->f10.u32l;
    // 0x800E14D0: nop

    // 0x800E14D4: sb          $t2, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r10;
    // 0x800E14D8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800E14DC: lb          $v1, 0x6($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X6);
    // 0x800E14E0: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x800E14E4: nop

    // 0x800E14E8: sb          $t5, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r13;
    // 0x800E14EC: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
L_800E14F0:
    // 0x800E14F0: bnel        $at, $zero, L_800E1540
    if (ctx->r1 != 0) {
        // 0x800E14F4: slti        $at, $v1, -0x13
        ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
            goto L_800E1540;
    }
    goto skip_6;
    // 0x800E14F4: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
    skip_6:
    // 0x800E14F8: lb          $t6, 0x8($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X8);
    // 0x800E14FC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800E1500: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x800E1504: bnel        $at, $zero, L_800E1530
    if (ctx->r1 != 0) {
        // 0x800E1508: sb          $t4, 0x26A($a2)
        MEM_B(0X26A, ctx->r6) = ctx->r12;
            goto L_800E1530;
    }
    goto skip_7;
    // 0x800E1508: sb          $t4, 0x26A($a2)
    MEM_B(0X26A, ctx->r6) = ctx->r12;
    skip_7:
    // 0x800E150C: lbu         $t7, 0x268($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X268);
    // 0x800E1510: lbu         $t9, 0x26A($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X26A);
    // 0x800E1514: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800E1518: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800E151C: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800E1520: sb          $t2, 0x26A($a2)
    MEM_B(0X26A, ctx->r6) = ctx->r10;
    // 0x800E1524: b           L_800E1594
    // 0x800E1528: sb          $t8, 0x268($a2)
    MEM_B(0X268, ctx->r6) = ctx->r24;
        goto L_800E1594;
    // 0x800E1528: sb          $t8, 0x268($a2)
    MEM_B(0X268, ctx->r6) = ctx->r24;
    // 0x800E152C: sb          $t4, 0x26A($a2)
    MEM_B(0X26A, ctx->r6) = ctx->r12;
L_800E1530:
    // 0x800E1530: sb          $t4, 0x268($a2)
    MEM_B(0X268, ctx->r6) = ctx->r12;
    // 0x800E1534: b           L_800E1594
    // 0x800E1538: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
        goto L_800E1594;
    // 0x800E1538: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800E153C: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
L_800E1540:
    // 0x800E1540: beq         $at, $zero, L_800E158C
    if (ctx->r1 == 0) {
        // 0x800E1544: addiu       $a0, $zero, 0xFE
        ctx->r4 = ADD32(0, 0XFE);
            goto L_800E158C;
    }
    // 0x800E1544: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800E1548: lb          $t5, 0x8($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X8);
    // 0x800E154C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800E1550: slti        $at, $t5, -0x13
    ctx->r1 = SIGNED(ctx->r13) < -0X13 ? 1 : 0;
    // 0x800E1554: beql        $at, $zero, L_800E1580
    if (ctx->r1 == 0) {
        // 0x800E1558: sb          $t3, 0x26A($a2)
        MEM_B(0X26A, ctx->r6) = ctx->r11;
            goto L_800E1580;
    }
    goto skip_8;
    // 0x800E1558: sb          $t3, 0x26A($a2)
    MEM_B(0X26A, ctx->r6) = ctx->r11;
    skip_8:
    // 0x800E155C: lbu         $t6, 0x268($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X268);
    // 0x800E1560: lbu         $t8, 0x26A($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X26A);
    // 0x800E1564: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800E1568: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800E156C: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800E1570: sb          $t9, 0x26A($a2)
    MEM_B(0X26A, ctx->r6) = ctx->r25;
    // 0x800E1574: b           L_800E1594
    // 0x800E1578: sb          $t7, 0x268($a2)
    MEM_B(0X268, ctx->r6) = ctx->r15;
        goto L_800E1594;
    // 0x800E1578: sb          $t7, 0x268($a2)
    MEM_B(0X268, ctx->r6) = ctx->r15;
    // 0x800E157C: sb          $t3, 0x26A($a2)
    MEM_B(0X26A, ctx->r6) = ctx->r11;
L_800E1580:
    // 0x800E1580: sb          $t3, 0x268($a2)
    MEM_B(0X268, ctx->r6) = ctx->r11;
    // 0x800E1584: b           L_800E1594
    // 0x800E1588: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
        goto L_800E1594;
    // 0x800E1588: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
L_800E158C:
    // 0x800E158C: sb          $a0, 0x26A($a2)
    MEM_B(0X26A, ctx->r6) = ctx->r4;
    // 0x800E1590: sb          $a0, 0x268($a2)
    MEM_B(0X268, ctx->r6) = ctx->r4;
L_800E1594:
    // 0x800E1594: lbu         $t5, 0x268($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X268);
    // 0x800E1598: slti        $at, $t5, 0xFF
    ctx->r1 = SIGNED(ctx->r13) < 0XFF ? 1 : 0;
    // 0x800E159C: bnel        $at, $zero, L_800E15AC
    if (ctx->r1 != 0) {
        // 0x800E15A0: lbu         $t6, 0x26A($a2)
        ctx->r14 = MEM_BU(ctx->r6, 0X26A);
            goto L_800E15AC;
    }
    goto skip_9;
    // 0x800E15A0: lbu         $t6, 0x26A($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X26A);
    skip_9:
    // 0x800E15A4: sb          $a0, 0x268($a2)
    MEM_B(0X268, ctx->r6) = ctx->r4;
    // 0x800E15A8: lbu         $t6, 0x26A($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X26A);
L_800E15AC:
    // 0x800E15AC: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x800E15B0: bnel        $at, $zero, L_800E15C0
    if (ctx->r1 != 0) {
        // 0x800E15B4: lb          $v1, 0x7($v0)
        ctx->r3 = MEM_B(ctx->r2, 0X7);
            goto L_800E15C0;
    }
    goto skip_10;
    // 0x800E15B4: lb          $v1, 0x7($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X7);
    skip_10:
    // 0x800E15B8: sb          $a0, 0x26A($a2)
    MEM_B(0X26A, ctx->r6) = ctx->r4;
    // 0x800E15BC: lb          $v1, 0x7($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X7);
L_800E15C0:
    // 0x800E15C0: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x800E15C4: bnel        $at, $zero, L_800E160C
    if (ctx->r1 != 0) {
        // 0x800E15C8: slti        $at, $v1, -0x13
        ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
            goto L_800E160C;
    }
    goto skip_11;
    // 0x800E15C8: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
    skip_11:
    // 0x800E15CC: lb          $t7, 0x9($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X9);
    // 0x800E15D0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800E15D4: slti        $at, $t7, 0x14
    ctx->r1 = SIGNED(ctx->r15) < 0X14 ? 1 : 0;
    // 0x800E15D8: bnel        $at, $zero, L_800E1600
    if (ctx->r1 != 0) {
        // 0x800E15DC: sb          $t5, 0x26B($a2)
        MEM_B(0X26B, ctx->r6) = ctx->r13;
            goto L_800E1600;
    }
    goto skip_12;
    // 0x800E15DC: sb          $t5, 0x26B($a2)
    MEM_B(0X26B, ctx->r6) = ctx->r13;
    skip_12:
    // 0x800E15E0: lbu         $t8, 0x269($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X269);
    // 0x800E15E4: lbu         $t2, 0x26B($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X26B);
    // 0x800E15E8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800E15EC: addiu       $t3, $t2, 0x1
    ctx->r11 = ADD32(ctx->r10, 0X1);
    // 0x800E15F0: sb          $t3, 0x26B($a2)
    MEM_B(0X26B, ctx->r6) = ctx->r11;
    // 0x800E15F4: b           L_800E1658
    // 0x800E15F8: sb          $t9, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r25;
        goto L_800E1658;
    // 0x800E15F8: sb          $t9, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r25;
    // 0x800E15FC: sb          $t5, 0x26B($a2)
    MEM_B(0X26B, ctx->r6) = ctx->r13;
L_800E1600:
    // 0x800E1600: b           L_800E1658
    // 0x800E1604: sb          $t5, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r13;
        goto L_800E1658;
    // 0x800E1604: sb          $t5, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r13;
    // 0x800E1608: slti        $at, $v1, -0x13
    ctx->r1 = SIGNED(ctx->r3) < -0X13 ? 1 : 0;
L_800E160C:
    // 0x800E160C: beql        $at, $zero, L_800E1654
    if (ctx->r1 == 0) {
        // 0x800E1610: sb          $a0, 0x26B($a2)
        MEM_B(0X26B, ctx->r6) = ctx->r4;
            goto L_800E1654;
    }
    goto skip_13;
    // 0x800E1610: sb          $a0, 0x26B($a2)
    MEM_B(0X26B, ctx->r6) = ctx->r4;
    skip_13:
    // 0x800E1614: lb          $t6, 0x9($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X9);
    // 0x800E1618: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800E161C: slti        $at, $t6, -0x13
    ctx->r1 = SIGNED(ctx->r14) < -0X13 ? 1 : 0;
    // 0x800E1620: beql        $at, $zero, L_800E1648
    if (ctx->r1 == 0) {
        // 0x800E1624: sb          $t4, 0x26B($a2)
        MEM_B(0X26B, ctx->r6) = ctx->r12;
            goto L_800E1648;
    }
    goto skip_14;
    // 0x800E1624: sb          $t4, 0x26B($a2)
    MEM_B(0X26B, ctx->r6) = ctx->r12;
    skip_14:
    // 0x800E1628: lbu         $t7, 0x269($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X269);
    // 0x800E162C: lbu         $t9, 0x26B($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X26B);
    // 0x800E1630: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800E1634: addiu       $t2, $t9, 0x1
    ctx->r10 = ADD32(ctx->r25, 0X1);
    // 0x800E1638: sb          $t2, 0x26B($a2)
    MEM_B(0X26B, ctx->r6) = ctx->r10;
    // 0x800E163C: b           L_800E1658
    // 0x800E1640: sb          $t8, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r24;
        goto L_800E1658;
    // 0x800E1640: sb          $t8, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r24;
    // 0x800E1644: sb          $t4, 0x26B($a2)
    MEM_B(0X26B, ctx->r6) = ctx->r12;
L_800E1648:
    // 0x800E1648: b           L_800E1658
    // 0x800E164C: sb          $t4, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r12;
        goto L_800E1658;
    // 0x800E164C: sb          $t4, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r12;
    // 0x800E1650: sb          $a0, 0x26B($a2)
    MEM_B(0X26B, ctx->r6) = ctx->r4;
L_800E1654:
    // 0x800E1654: sb          $a0, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r4;
L_800E1658:
    // 0x800E1658: lbu         $t6, 0x269($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X269);
    // 0x800E165C: slti        $at, $t6, 0xFF
    ctx->r1 = SIGNED(ctx->r14) < 0XFF ? 1 : 0;
    // 0x800E1660: bnel        $at, $zero, L_800E1670
    if (ctx->r1 != 0) {
        // 0x800E1664: lbu         $t7, 0x26B($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X26B);
            goto L_800E1670;
    }
    goto skip_15;
    // 0x800E1664: lbu         $t7, 0x26B($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X26B);
    skip_15:
    // 0x800E1668: sb          $a0, 0x269($a2)
    MEM_B(0X269, ctx->r6) = ctx->r4;
    // 0x800E166C: lbu         $t7, 0x26B($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X26B);
L_800E1670:
    // 0x800E1670: slti        $at, $t7, 0xFF
    ctx->r1 = SIGNED(ctx->r15) < 0XFF ? 1 : 0;
    // 0x800E1674: bnel        $at, $zero, L_800E1684
    if (ctx->r1 != 0) {
        // 0x800E1678: lw          $v0, 0x160($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X160);
            goto L_800E1684;
    }
    goto skip_16;
    // 0x800E1678: lw          $v0, 0x160($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X160);
    skip_16:
    // 0x800E167C: sb          $a0, 0x26B($a2)
    MEM_B(0X26B, ctx->r6) = ctx->r4;
    // 0x800E1680: lw          $v0, 0x160($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X160);
L_800E1684:
    // 0x800E1684: lui         $at, 0x1
    ctx->r1 = S32(0X1 << 16);
    // 0x800E1688: slt         $at, $v0, $at
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800E168C: beq         $at, $zero, L_800E1698
    if (ctx->r1 == 0) {
        // 0x800E1690: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_800E1698;
    }
    // 0x800E1690: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800E1694: sw          $t8, 0x160($a2)
    MEM_W(0X160, ctx->r6) = ctx->r24;
L_800E1698:
    // 0x800E1698: lhu         $t9, 0x1BE($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X1BE);
    // 0x800E169C: lhu         $t2, 0x1B8($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X1B8);
    // 0x800E16A0: and         $t3, $t9, $t2
    ctx->r11 = ctx->r25 & ctx->r10;
    // 0x800E16A4: beql        $t3, $zero, L_800E16B4
    if (ctx->r11 == 0) {
        // 0x800E16A8: lw          $v0, 0x40($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X40);
            goto L_800E16B4;
    }
    goto skip_17;
    // 0x800E16A8: lw          $v0, 0x40($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X40);
    skip_17:
    // 0x800E16AC: sw          $zero, 0x160($a2)
    MEM_W(0X160, ctx->r6) = 0;
    // 0x800E16B0: lw          $v0, 0x40($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X40);
L_800E16B4:
    // 0x800E16B4: beq         $v0, $zero, L_800E16E8
    if (ctx->r2 == 0) {
        // 0x800E16B8: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_800E16E8;
    }
    // 0x800E16B8: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x800E16BC: bne         $t4, $zero, L_800E16E8
    if (ctx->r12 != 0) {
        // 0x800E16C0: sw          $t4, 0x40($a2)
        MEM_W(0X40, ctx->r6) = ctx->r12;
            goto L_800E16E8;
    }
    // 0x800E16C0: sw          $t4, 0x40($a2)
    MEM_W(0X40, ctx->r6) = ctx->r12;
    // 0x800E16C4: lbu         $t6, 0x192($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X192);
    // 0x800E16C8: lw          $v0, 0xA08($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XA08);
    // 0x800E16CC: andi        $t7, $t6, 0xFFFD
    ctx->r15 = ctx->r14 & 0XFFFD;
    // 0x800E16D0: beq         $v0, $zero, L_800E16E8
    if (ctx->r2 == 0) {
        // 0x800E16D4: sb          $t7, 0x192($a2)
        MEM_B(0X192, ctx->r6) = ctx->r15;
            goto L_800E16E8;
    }
    // 0x800E16D4: sb          $t7, 0x192($a2)
    MEM_B(0X192, ctx->r6) = ctx->r15;
    // 0x800E16D8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E16DC: jalr        $v0
    // 0x800E16E0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x800E16E0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x800E16E4: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800E16E8:
    // 0x800E16E8: lbu         $t9, 0x191($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X191);
    // 0x800E16EC: lw          $t3, 0x40($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X40);
    // 0x800E16F0: ori         $t2, $t9, 0x80
    ctx->r10 = ctx->r25 | 0X80;
    // 0x800E16F4: bne         $t3, $zero, L_800E170C
    if (ctx->r11 != 0) {
        // 0x800E16F8: sb          $t2, 0x191($a2)
        MEM_B(0X191, ctx->r6) = ctx->r10;
            goto L_800E170C;
    }
    // 0x800E16F8: sb          $t2, 0x191($a2)
    MEM_B(0X191, ctx->r6) = ctx->r10;
    // 0x800E16FC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E1700: jal         0x800E0830
    // 0x800E1704: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_3;
    // 0x800E1704: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_3:
    // 0x800E1708: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
L_800E170C:
    // 0x800E170C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E1710: jal         0x800E11C8
    // 0x800E1714: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftMainRunUpdateColAnim(rdram, ctx);
        goto after_4;
    // 0x800E1714: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_4:
    // 0x800E1718: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E171C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800E1720: lw          $v0, 0x5A8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X5A8);
    // 0x800E1724: beq         $v0, $zero, L_800E1778
    if (ctx->r2 == 0) {
        // 0x800E1728: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_800E1778;
    }
    // 0x800E1728: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x800E172C: bne         $t4, $zero, L_800E1778
    if (ctx->r12 != 0) {
        // 0x800E1730: sw          $t4, 0x5A8($a2)
        MEM_W(0X5A8, ctx->r6) = ctx->r12;
            goto L_800E1778;
    }
    // 0x800E1730: sw          $t4, 0x5A8($a2)
    MEM_W(0X5A8, ctx->r6) = ctx->r12;
    // 0x800E1734: lw          $t6, 0x5A4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X5A4);
    // 0x800E1738: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800E173C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800E1740: beql        $t6, $zero, L_800E1754
    if (ctx->r14 == 0) {
        // 0x800E1744: sw          $t8, 0x5AC($a2)
        MEM_W(0X5AC, ctx->r6) = ctx->r24;
            goto L_800E1754;
    }
    goto skip_18;
    // 0x800E1744: sw          $t8, 0x5AC($a2)
    MEM_W(0X5AC, ctx->r6) = ctx->r24;
    skip_18:
    // 0x800E1748: b           L_800E1754
    // 0x800E174C: sw          $t7, 0x5AC($a2)
    MEM_W(0X5AC, ctx->r6) = ctx->r15;
        goto L_800E1754;
    // 0x800E174C: sw          $t7, 0x5AC($a2)
    MEM_W(0X5AC, ctx->r6) = ctx->r15;
    // 0x800E1750: sw          $t8, 0x5AC($a2)
    MEM_W(0X5AC, ctx->r6) = ctx->r24;
L_800E1754:
    // 0x800E1754: lw          $t9, 0xA64($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA64);
    // 0x800E1758: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800E175C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E1760: bnel        $t9, $at, L_800E177C
    if (ctx->r25 != ctx->r1) {
        // 0x800E1764: lw          $v0, 0x5A4($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X5A4);
            goto L_800E177C;
    }
    goto skip_19;
    // 0x800E1764: lw          $v0, 0x5A4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X5A4);
    skip_19:
    // 0x800E1768: jal         0x800E98D4
    // 0x800E176C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftParamResetStatUpdateColAnim(rdram, ctx);
        goto after_5;
    // 0x800E176C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_5:
    // 0x800E1770: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1774: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
L_800E1778:
    // 0x800E1778: lw          $v0, 0x5A4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X5A4);
L_800E177C:
    // 0x800E177C: beq         $v0, $zero, L_800E17C0
    if (ctx->r2 == 0) {
        // 0x800E1780: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_800E17C0;
    }
    // 0x800E1780: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x800E1784: bne         $t2, $zero, L_800E17C0
    if (ctx->r10 != 0) {
        // 0x800E1788: sw          $t2, 0x5A4($a2)
        MEM_W(0X5A4, ctx->r6) = ctx->r10;
            goto L_800E17C0;
    }
    // 0x800E1788: sw          $t2, 0x5A4($a2)
    MEM_W(0X5A4, ctx->r6) = ctx->r10;
    // 0x800E178C: lw          $t4, 0x5A8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X5A8);
    // 0x800E1790: bnel        $t4, $zero, L_800E17C4
    if (ctx->r12 != 0) {
        // 0x800E1794: lw          $v0, 0x5B0($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X5B0);
            goto L_800E17C4;
    }
    goto skip_20;
    // 0x800E1794: lw          $v0, 0x5B0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X5B0);
    skip_20:
    // 0x800E1798: lw          $t6, 0xA64($a2)
    ctx->r14 = MEM_W(ctx->r6, 0XA64);
    // 0x800E179C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800E17A0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800E17A4: bne         $t6, $at, L_800E17C0
    if (ctx->r14 != ctx->r1) {
        // 0x800E17A8: sw          $t5, 0x5AC($a2)
        MEM_W(0X5AC, ctx->r6) = ctx->r13;
            goto L_800E17C0;
    }
    // 0x800E17A8: sw          $t5, 0x5AC($a2)
    MEM_W(0X5AC, ctx->r6) = ctx->r13;
    // 0x800E17AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E17B0: jal         0x800E98D4
    // 0x800E17B4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftParamResetStatUpdateColAnim(rdram, ctx);
        goto after_6;
    // 0x800E17B4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_6:
    // 0x800E17B8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E17BC: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
L_800E17C0:
    // 0x800E17C0: lw          $v0, 0x5B0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X5B0);
L_800E17C4:
    // 0x800E17C4: beq         $v0, $zero, L_800E1820
    if (ctx->r2 == 0) {
        // 0x800E17C8: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800E1820;
    }
    // 0x800E17C8: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800E17CC: sw          $t7, 0x5B0($a2)
    MEM_W(0X5B0, ctx->r6) = ctx->r15;
    // 0x800E17D0: bne         $t7, $zero, L_800E1804
    if (ctx->r15 != 0) {
        // 0x800E17D4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800E1804;
    }
    // 0x800E17D4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800E17D8: lw          $t9, 0xA64($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA64);
    // 0x800E17DC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800E17E0: addiu       $at, $zero, 0x4A
    ctx->r1 = ADD32(0, 0X4A);
    // 0x800E17E4: bne         $t9, $at, L_800E1820
    if (ctx->r25 != ctx->r1) {
        // 0x800E17E8: sw          $t8, 0x5B4($a2)
        MEM_W(0X5B4, ctx->r6) = ctx->r24;
            goto L_800E1820;
    }
    // 0x800E17E8: sw          $t8, 0x5B4($a2)
    MEM_W(0X5B4, ctx->r6) = ctx->r24;
    // 0x800E17EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E17F0: jal         0x800E98D4
    // 0x800E17F4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftParamResetStatUpdateColAnim(rdram, ctx);
        goto after_7;
    // 0x800E17F4: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_7:
    // 0x800E17F8: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E17FC: b           L_800E1820
    // 0x800E1800: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
        goto L_800E1820;
    // 0x800E1800: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
L_800E1804:
    // 0x800E1804: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x800E1808: bnel        $v0, $at, L_800E1824
    if (ctx->r2 != ctx->r1) {
        // 0x800E180C: lw          $v1, 0x818($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X818);
            goto L_800E1824;
    }
    goto skip_21;
    // 0x800E180C: lw          $v1, 0x818($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X818);
    skip_21:
    // 0x800E1810: jal         0x800E7B54
    // 0x800E1814: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftParamTryUpdateItemMusic(rdram, ctx);
        goto after_8;
    // 0x800E1814: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_8:
    // 0x800E1818: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E181C: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
L_800E1820:
    // 0x800E1820: lw          $v1, 0x818($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X818);
L_800E1824:
    // 0x800E1824: beql        $v1, $zero, L_800E18C8
    if (ctx->r3 == 0) {
        // 0x800E1828: lw          $v0, 0x84C($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X84C);
            goto L_800E18C8;
    }
    goto skip_22;
    // 0x800E1828: lw          $v0, 0x84C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X84C);
    skip_22:
    // 0x800E182C: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
    // 0x800E1830: addiu       $t2, $v1, -0x1
    ctx->r10 = ADD32(ctx->r3, -0X1);
    // 0x800E1834: sw          $t2, 0x818($a2)
    MEM_W(0X818, ctx->r6) = ctx->r10;
    // 0x800E1838: beq         $v0, $zero, L_800E1888
    if (ctx->r2 == 0) {
        // 0x800E183C: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800E1888;
    }
    // 0x800E183C: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800E1840: sw          $t3, 0x2C($a2)
    MEM_W(0X2C, ctx->r6) = ctx->r11;
    // 0x800E1844: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800E1848: jal         0x800269C0
    // 0x800E184C: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x800E184C: addiu       $a0, $zero, 0x112
    ctx->r4 = ADD32(0, 0X112);
    after_9:
    // 0x800E1850: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1854: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x800E1858: lw          $t5, 0x50E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X50E8);
    // 0x800E185C: lbu         $t6, 0xD($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XD);
    // 0x800E1860: lw          $t4, 0x2C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X2C);
    // 0x800E1864: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800E1868: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x800E186C: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800E1870: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E1874: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800E1878: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E187C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800E1880: sw          $t4, 0x6C($t8)
    MEM_W(0X6C, ctx->r24) = ctx->r12;
    // 0x800E1884: lw          $v0, 0x2C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X2C);
L_800E1888:
    // 0x800E1888: bnel        $v0, $zero, L_800E1898
    if (ctx->r2 != 0) {
        // 0x800E188C: lw          $t9, 0x818($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X818);
            goto L_800E1898;
    }
    goto skip_23;
    // 0x800E188C: lw          $t9, 0x818($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X818);
    skip_23:
    // 0x800E1890: sw          $zero, 0x818($a2)
    MEM_W(0X818, ctx->r6) = 0;
    // 0x800E1894: lw          $t9, 0x818($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X818);
L_800E1898:
    // 0x800E1898: bnel        $t9, $zero, L_800E18C8
    if (ctx->r25 != 0) {
        // 0x800E189C: lw          $v0, 0x84C($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X84C);
            goto L_800E18C8;
    }
    goto skip_24;
    // 0x800E189C: lw          $v0, 0x84C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X84C);
    skip_24:
    // 0x800E18A0: lw          $t2, 0xA64($a2)
    ctx->r10 = MEM_W(ctx->r6, 0XA64);
    // 0x800E18A4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800E18A8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E18AC: bnel        $t2, $at, L_800E18C8
    if (ctx->r10 != ctx->r1) {
        // 0x800E18B0: lw          $v0, 0x84C($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X84C);
            goto L_800E18C8;
    }
    goto skip_25;
    // 0x800E18B0: lw          $v0, 0x84C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X84C);
    skip_25:
    // 0x800E18B4: jal         0x800E98D4
    // 0x800E18B8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftParamResetStatUpdateColAnim(rdram, ctx);
        goto after_10;
    // 0x800E18B8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_10:
    // 0x800E18BC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E18C0: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800E18C4: lw          $v0, 0x84C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X84C);
L_800E18C8:
    // 0x800E18C8: beql        $v0, $zero, L_800E190C
    if (ctx->r2 == 0) {
        // 0x800E18CC: lhu         $v0, 0x276($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X276);
            goto L_800E190C;
    }
    goto skip_26;
    // 0x800E18CC: lhu         $v0, 0x276($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X276);
    skip_26:
    // 0x800E18D0: lw          $t3, 0x24($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X24);
    // 0x800E18D4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800E18D8: beql        $t3, $at, L_800E190C
    if (ctx->r11 == ctx->r1) {
        // 0x800E18DC: lhu         $v0, 0x276($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X276);
            goto L_800E190C;
    }
    goto skip_27;
    // 0x800E18DC: lhu         $v0, 0x276($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X276);
    skip_27:
    // 0x800E18E0: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x800E18E4: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800E18E8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E18EC: lw          $t5, 0xC($t6)
    ctx->r13 = MEM_W(ctx->r14, 0XC);
    // 0x800E18F0: bnel        $t5, $at, L_800E190C
    if (ctx->r13 != ctx->r1) {
        // 0x800E18F4: lhu         $v0, 0x276($a2)
        ctx->r2 = MEM_HU(ctx->r6, 0X276);
            goto L_800E190C;
    }
    goto skip_28;
    // 0x800E18F4: lhu         $v0, 0x276($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X276);
    skip_28:
    // 0x800E18F8: jal         0x800F36E0
    // 0x800E18FC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    ftHammerUpdateStats(rdram, ctx);
        goto after_11;
    // 0x800E18FC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_11:
    // 0x800E1900: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1904: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800E1908: lhu         $v0, 0x276($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X276);
L_800E190C:
    // 0x800E190C: beq         $v0, $zero, L_800E1934
    if (ctx->r2 == 0) {
        // 0x800E1910: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800E1934;
    }
    // 0x800E1910: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800E1914: lbu         $t4, 0x272($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X272);
    // 0x800E1918: lbu         $t9, 0x273($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X273);
    // 0x800E191C: sh          $t7, 0x276($a2)
    MEM_H(0X276, ctx->r6) = ctx->r15;
    // 0x800E1920: addiu       $t8, $t4, 0x1
    ctx->r24 = ADD32(ctx->r12, 0X1);
    // 0x800E1924: andi        $t2, $t8, 0xFF
    ctx->r10 = ctx->r24 & 0XFF;
    // 0x800E1928: bne         $t9, $t2, L_800E1934
    if (ctx->r25 != ctx->r10) {
        // 0x800E192C: sb          $t8, 0x272($a2)
        MEM_B(0X272, ctx->r6) = ctx->r24;
            goto L_800E1934;
    }
    // 0x800E192C: sb          $t8, 0x272($a2)
    MEM_B(0X272, ctx->r6) = ctx->r24;
    // 0x800E1930: sb          $zero, 0x272($a2)
    MEM_B(0X272, ctx->r6) = 0;
L_800E1934:
    // 0x800E1934: lw          $v0, 0x9FC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X9FC);
    // 0x800E1938: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E193C: beql        $v0, $zero, L_800E1958
    if (ctx->r2 == 0) {
        // 0x800E1940: lw          $t3, 0x40($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X40);
            goto L_800E1958;
    }
    goto skip_29;
    // 0x800E1940: lw          $t3, 0x40($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X40);
    skip_29:
    // 0x800E1944: jalr        $v0
    // 0x800E1948: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_12;
    // 0x800E1948: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_12:
    // 0x800E194C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E1950: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800E1954: lw          $t3, 0x40($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X40);
L_800E1958:
    // 0x800E1958: bnel        $t3, $zero, L_800E1CD0
    if (ctx->r11 != 0) {
        // 0x800E195C: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_800E1CD0;
    }
    goto skip_30;
    // 0x800E195C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_30:
    // 0x800E1960: lw          $v0, 0x174($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X174);
    // 0x800E1964: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800E1968: bnel        $at, $zero, L_800E198C
    if (ctx->r1 != 0) {
        // 0x800E196C: lw          $v0, 0x9D4($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X9D4);
            goto L_800E198C;
    }
    goto skip_31;
    // 0x800E196C: lw          $v0, 0x9D4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X9D4);
    skip_31:
    // 0x800E1970: lw          $t6, 0x18C($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X18C);
    // 0x800E1974: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x800E1978: sll         $t7, $t6, 30
    ctx->r15 = S32(ctx->r14 << 30);
    // 0x800E197C: bltzl       $t7, L_800E198C
    if (SIGNED(ctx->r15) < 0) {
        // 0x800E1980: lw          $v0, 0x9D4($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X9D4);
            goto L_800E198C;
    }
    goto skip_32;
    // 0x800E1980: lw          $v0, 0x9D4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X9D4);
    skip_32:
    // 0x800E1984: sw          $t4, 0x174($a2)
    MEM_W(0X174, ctx->r6) = ctx->r12;
    // 0x800E1988: lw          $v0, 0x9D4($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X9D4);
L_800E198C:
    // 0x800E198C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E1990: beql        $v0, $zero, L_800E19AC
    if (ctx->r2 == 0) {
        // 0x800E1994: lw          $v0, 0x9DC($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X9DC);
            goto L_800E19AC;
    }
    goto skip_33;
    // 0x800E1994: lw          $v0, 0x9DC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X9DC);
    skip_33:
    // 0x800E1998: jalr        $v0
    // 0x800E199C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_13;
    // 0x800E199C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_13:
    // 0x800E19A0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E19A4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800E19A8: lw          $v0, 0x9DC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X9DC);
L_800E19AC:
    // 0x800E19AC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E19B0: beql        $v0, $zero, L_800E19CC
    if (ctx->r2 == 0) {
        // 0x800E19B4: lw          $t8, 0x18C($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X18C);
            goto L_800E19CC;
    }
    goto skip_34;
    // 0x800E19B4: lw          $t8, 0x18C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X18C);
    skip_34:
    // 0x800E19B8: jalr        $v0
    // 0x800E19BC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_14;
    // 0x800E19BC: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_14:
    // 0x800E19C0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x800E19C4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800E19C8: lw          $t8, 0x18C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X18C);
L_800E19CC:
    // 0x800E19CC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800E19D0: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800E19D4: bnel        $t9, $zero, L_800E1A30
    if (ctx->r25 != 0) {
        // 0x800E19D8: lw          $t3, 0x14C($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X14C);
            goto L_800E1A30;
    }
    goto skip_35;
    // 0x800E19D8: lw          $t3, 0x14C($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X14C);
    skip_35:
    // 0x800E19DC: lbu         $t3, 0xD($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XD);
    // 0x800E19E0: lui         $t2, 0x800A
    ctx->r10 = S32(0X800A << 16);
    // 0x800E19E4: lw          $t2, 0x50E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X50E8);
    // 0x800E19E8: sll         $t6, $t3, 3
    ctx->r14 = S32(ctx->r11 << 3);
    // 0x800E19EC: subu        $t6, $t6, $t3
    ctx->r14 = SUB32(ctx->r14, ctx->r11);
    // 0x800E19F0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E19F4: addu        $t6, $t6, $t3
    ctx->r14 = ADD32(ctx->r14, ctx->r11);
    // 0x800E19F8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800E19FC: addu        $t5, $t2, $t6
    ctx->r13 = ADD32(ctx->r10, ctx->r14);
    // 0x800E1A00: sw          $zero, 0x70($t5)
    MEM_W(0X70, ctx->r13) = 0;
    // 0x800E1A04: lbu         $t4, 0xD($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0XD);
    // 0x800E1A08: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800E1A0C: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x800E1A10: sll         $t8, $t4, 3
    ctx->r24 = S32(ctx->r12 << 3);
    // 0x800E1A14: subu        $t8, $t8, $t4
    ctx->r24 = SUB32(ctx->r24, ctx->r12);
    // 0x800E1A18: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E1A1C: addu        $t8, $t8, $t4
    ctx->r24 = ADD32(ctx->r24, ctx->r12);
    // 0x800E1A20: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x800E1A24: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800E1A28: sw          $zero, 0x74($t9)
    MEM_W(0X74, ctx->r25) = 0;
    // 0x800E1A2C: lw          $t3, 0x14C($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X14C);
L_800E1A30:
    // 0x800E1A30: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800E1A34: swc1        $f14, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->f14.u32l;
    // 0x800E1A38: bne         $t3, $zero, L_800E1CCC
    if (ctx->r11 != 0) {
        // 0x800E1A3C: swc1        $f14, 0x70($a2)
        MEM_W(0X70, ctx->r6) = ctx->f14.u32l;
            goto L_800E1CCC;
    }
    // 0x800E1A3C: swc1        $f14, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f14.u32l;
    // 0x800E1A40: lw          $t2, 0x18C($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X18C);
    // 0x800E1A44: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800E1A48: sll         $t5, $t2, 28
    ctx->r13 = S32(ctx->r10 << 28);
    // 0x800E1A4C: bltzl       $t5, L_800E1CD0
    if (SIGNED(ctx->r13) < 0) {
        // 0x800E1A50: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_800E1CD0;
    }
    goto skip_36;
    // 0x800E1A50: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_36:
    // 0x800E1A54: lw          $a1, 0x66FC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X66FC);
    // 0x800E1A58: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E1A5C: lui         $at, 0x40D8
    ctx->r1 = S32(0X40D8 << 16);
    // 0x800E1A60: beql        $a1, $zero, L_800E1C7C
    if (ctx->r5 == 0) {
        // 0x800E1A64: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_800E1C7C;
    }
    goto skip_37;
    // 0x800E1A64: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    skip_37:
    // 0x800E1A68: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800E1A6C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800E1A70: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E1A74: nop

L_800E1A78:
    // 0x800E1A78: beq         $t1, $a1, L_800E1C68
    if (ctx->r9 == ctx->r5) {
        // 0x800E1A7C: lw          $v0, 0x84($a1)
        ctx->r2 = MEM_W(ctx->r5, 0X84);
            goto L_800E1C68;
    }
    // 0x800E1A7C: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x800E1A80: lw          $t4, 0x844($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X844);
    // 0x800E1A84: bnel        $t4, $zero, L_800E1C6C
    if (ctx->r12 != 0) {
        // 0x800E1A88: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800E1C6C;
    }
    goto skip_38;
    // 0x800E1A88: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    skip_38:
    // 0x800E1A8C: lw          $t7, 0x14C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X14C);
    // 0x800E1A90: bnel        $t7, $zero, L_800E1C70
    if (ctx->r15 != 0) {
        // 0x800E1A94: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_800E1C70;
    }
    goto skip_39;
    // 0x800E1A94: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_39:
    // 0x800E1A98: lw          $t8, 0xEC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XEC);
    // 0x800E1A9C: lw          $t9, 0xEC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XEC);
    // 0x800E1AA0: bnel        $t8, $t9, L_800E1C70
    if (ctx->r24 != ctx->r25) {
        // 0x800E1AA4: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_800E1C70;
    }
    goto skip_40;
    // 0x800E1AA4: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_40:
    // 0x800E1AA8: lw          $t3, 0x44($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X44);
    // 0x800E1AAC: lw          $v1, 0x9C8($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X9C8);
    // 0x800E1AB0: lw          $t2, 0x74($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X74);
    // 0x800E1AB4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800E1AB8: lwc1        $f4, 0x84($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X84);
    // 0x800E1ABC: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x800E1AC0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E1AC4: lwc1        $f6, 0x1C($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x800E1AC8: lw          $a0, 0x9C8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X9C8);
    // 0x800E1ACC: lw          $t5, 0x74($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X74);
    // 0x800E1AD0: lwc1        $f12, 0x80($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X80);
    // 0x800E1AD4: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800E1AD8: lwc1        $f8, 0x84($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X84);
    // 0x800E1ADC: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800E1AE0: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800E1AE4: nop

    // 0x800E1AE8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E1AEC: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800E1AF0: lwc1        $f8, 0x1C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x800E1AF4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800E1AF8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800E1AFC: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800E1B00: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x800E1B04: nop

    // 0x800E1B08: bc1fl       L_800E1B1C
    if (!c1cs) {
        // 0x800E1B0C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800E1B1C;
    }
    goto skip_41;
    // 0x800E1B0C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_41:
    // 0x800E1B10: b           L_800E1B1C
    // 0x800E1B14: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_800E1B1C;
    // 0x800E1B14: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800E1B18: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800E1B1C:
    // 0x800E1B1C: lwc1        $f6, 0x80($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X80);
    // 0x800E1B20: add.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f6.fl;
    // 0x800E1B24: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800E1B28: nop

    // 0x800E1B2C: bc1fl       L_800E1C70
    if (!c1cs) {
        // 0x800E1B30: lw          $a1, 0x4($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X4);
            goto L_800E1C70;
    }
    goto skip_42;
    // 0x800E1B30: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    skip_42:
    // 0x800E1B34: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    // 0x800E1B38: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800E1B3C: bc1fl       L_800E1B74
    if (!c1cs) {
        // 0x800E1B40: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_800E1B74;
    }
    goto skip_43;
    // 0x800E1B40: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_43:
    // 0x800E1B44: beq         $a3, $zero, L_800E1B54
    if (ctx->r7 == 0) {
        // 0x800E1B48: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800E1B54;
    }
    // 0x800E1B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E1B4C: b           L_800E1B54
    // 0x800E1B50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800E1B54;
    // 0x800E1B50: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800E1B54:
    // 0x800E1B54: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800E1B58: lwc1        $f10, 0x70($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X70);
    // 0x800E1B5C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E1B60: mul.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800E1B64: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800E1B68: b           L_800E1BA0
    // 0x800E1B6C: swc1        $f8, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f8.u32l;
        goto L_800E1BA0;
    // 0x800E1B6C: swc1        $f8, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f8.u32l;
    // 0x800E1B70: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_800E1B74:
    // 0x800E1B74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E1B78: bc1f        L_800E1B88
    if (!c1cs) {
        // 0x800E1B7C: nop
    
            goto L_800E1B88;
    }
    // 0x800E1B7C: nop

    // 0x800E1B80: b           L_800E1B88
    // 0x800E1B84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800E1B88;
    // 0x800E1B84: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800E1B88:
    // 0x800E1B88: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800E1B8C: lwc1        $f6, 0x70($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X70);
    // 0x800E1B90: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E1B94: mul.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800E1B98: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800E1B9C: swc1        $f10, 0x70($a2)
    MEM_W(0X70, ctx->r6) = ctx->f10.u32l;
L_800E1BA0:
    // 0x800E1BA0: lw          $t4, 0x74($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X74);
    // 0x800E1BA4: lw          $t7, 0x74($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X74);
    // 0x800E1BA8: lwc1        $f4, 0x24($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X24);
    // 0x800E1BAC: lwc1        $f6, 0x24($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X24);
    // 0x800E1BB0: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800E1BB4: c.eq.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl == ctx->f14.fl;
    // 0x800E1BB8: nop

    // 0x800E1BBC: bc1fl       L_800E1C38
    if (!c1cs) {
        // 0x800E1BC0: c.lt.s      $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
            goto L_800E1C38;
    }
    goto skip_44;
    // 0x800E1BC0: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    skip_44:
    // 0x800E1BC4: c.eq.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl == ctx->f14.fl;
    // 0x800E1BC8: nop

    // 0x800E1BCC: bc1fl       L_800E1C04
    if (!c1cs) {
        // 0x800E1BD0: c.lt.s      $f0, $f14
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
            goto L_800E1C04;
    }
    goto skip_45;
    // 0x800E1BD0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    skip_45:
    // 0x800E1BD4: beq         $a3, $zero, L_800E1BE4
    if (ctx->r7 == 0) {
        // 0x800E1BD8: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800E1BE4;
    }
    // 0x800E1BD8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E1BDC: b           L_800E1BE4
    // 0x800E1BE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800E1BE4;
    // 0x800E1BE0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800E1BE4:
    // 0x800E1BE4: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800E1BE8: lwc1        $f8, 0x74($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X74);
    // 0x800E1BEC: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E1BF0: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800E1BF4: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800E1BF8: b           L_800E1C6C
    // 0x800E1BFC: swc1        $f10, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->f10.u32l;
        goto L_800E1C6C;
    // 0x800E1BFC: swc1        $f10, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->f10.u32l;
    // 0x800E1C00: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
L_800E1C04:
    // 0x800E1C04: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800E1C08: bc1f        L_800E1C18
    if (!c1cs) {
        // 0x800E1C0C: nop
    
            goto L_800E1C18;
    }
    // 0x800E1C0C: nop

    // 0x800E1C10: b           L_800E1C18
    // 0x800E1C14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E1C18;
    // 0x800E1C14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E1C18:
    // 0x800E1C18: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800E1C1C: lwc1        $f4, 0x74($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X74);
    // 0x800E1C20: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800E1C24: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800E1C28: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800E1C2C: b           L_800E1C6C
    // 0x800E1C30: swc1        $f8, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->f8.u32l;
        goto L_800E1C6C;
    // 0x800E1C30: swc1        $f8, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->f8.u32l;
    // 0x800E1C34: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
L_800E1C38:
    // 0x800E1C38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800E1C3C: bc1f        L_800E1C4C
    if (!c1cs) {
        // 0x800E1C40: nop
    
            goto L_800E1C4C;
    }
    // 0x800E1C40: nop

    // 0x800E1C44: b           L_800E1C4C
    // 0x800E1C48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800E1C4C;
    // 0x800E1C48: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800E1C4C:
    // 0x800E1C4C: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800E1C50: lwc1        $f6, 0x74($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X74);
    // 0x800E1C54: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E1C58: mul.s       $f8, $f16, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800E1C5C: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800E1C60: b           L_800E1C6C
    // 0x800E1C64: swc1        $f4, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->f4.u32l;
        goto L_800E1C6C;
    // 0x800E1C64: swc1        $f4, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->f4.u32l;
L_800E1C68:
    // 0x800E1C68: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800E1C6C:
    // 0x800E1C6C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
L_800E1C70:
    // 0x800E1C70: bne         $a1, $zero, L_800E1A78
    if (ctx->r5 != 0) {
        // 0x800E1C74: nop
    
            goto L_800E1A78;
    }
    // 0x800E1C74: nop

    // 0x800E1C78: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
L_800E1C7C:
    // 0x800E1C7C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E1C80: bnel        $t0, $zero, L_800E1CD0
    if (ctx->r8 != 0) {
        // 0x800E1C84: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_800E1CD0;
    }
    goto skip_46;
    // 0x800E1C84: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_46:
    // 0x800E1C88: lw          $t8, 0x74($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X74);
    // 0x800E1C8C: lwc1        $f0, 0x24($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X24);
    // 0x800E1C90: c.eq.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl == ctx->f0.fl;
    // 0x800E1C94: nop

    // 0x800E1C98: bc1tl       L_800E1CD0
    if (c1cs) {
        // 0x800E1C9C: mtc1        $zero, $f14
        ctx->f14.u32l = 0;
            goto L_800E1CD0;
    }
    goto skip_47;
    // 0x800E1C9C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    skip_47:
    // 0x800E1CA0: c.lt.s      $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f0.fl < ctx->f14.fl;
    // 0x800E1CA4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800E1CA8: bc1f        L_800E1CB8
    if (!c1cs) {
        // 0x800E1CAC: nop
    
            goto L_800E1CB8;
    }
    // 0x800E1CAC: nop

    // 0x800E1CB0: b           L_800E1CB8
    // 0x800E1CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800E1CB8;
    // 0x800E1CB4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E1CB8:
    // 0x800E1CB8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800E1CBC: nop

    // 0x800E1CC0: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800E1CC4: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800E1CC8: swc1        $f8, 0x74($a2)
    MEM_W(0X74, ctx->r6) = ctx->f8.u32l;
L_800E1CCC:
    // 0x800E1CCC: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
L_800E1CD0:
    // 0x800E1CD0: nop

    // 0x800E1CD4: swc1        $f14, 0xAC($a2)
    MEM_W(0XAC, ctx->r6) = ctx->f14.u32l;
    // 0x800E1CD8: swc1        $f14, 0xA8($a2)
    MEM_W(0XA8, ctx->r6) = ctx->f14.u32l;
    // 0x800E1CDC: swc1        $f14, 0xA4($a2)
    MEM_W(0XA4, ctx->r6) = ctx->f14.u32l;
    // 0x800E1CE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E1CE4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E1CE8: jr          $ra
    // 0x800E1CEC: nop

    return;
    // 0x800E1CEC: nop

;}
RECOMP_FUNC void ftDonkeySpecialHiSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015B898: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015B89C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015B8A0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015B8A4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015B8A8: jal         0x800DEEC8
    // 0x8015B8AC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015B8AC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015B8B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015B8B4: addiu       $t7, $zero, 0x4000
    ctx->r15 = ADD32(0, 0X4000);
    // 0x8015B8B8: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x8015B8BC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015B8C0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015B8C4: jal         0x800E6F24
    // 0x8015B8C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015B8C8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015B8CC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8015B8D0: jal         0x800D8E78
    // 0x8015B8D4: lui         $a1, 0x4218
    ctx->r5 = S32(0X4218 << 16);
    ftPhysicsClampAirVelX(rdram, ctx);
        goto after_2;
    // 0x8015B8D4: lui         $a1, 0x4218
    ctx->r5 = S32(0X4218 << 16);
    after_2:
    // 0x8015B8D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015B8DC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015B8E0: jr          $ra
    // 0x8015B8E4: nop

    return;
    // 0x8015B8E4: nop

;}
RECOMP_FUNC void mnPlayers1PGameStockThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133FA4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80133FA8: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80133FAC: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80133FB0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x80133FB4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80133FB8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80133FBC: lwc1        $f22, -0x7180($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X7180);
    // 0x80133FC0: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80133FC4: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80133FC8: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80133FCC: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80133FD0: lui         $at, 0x4332
    ctx->r1 = S32(0X4332 << 16);
    // 0x80133FD4: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80133FD8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80133FDC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80133FE0: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80133FE4: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80133FE8: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80133FEC: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80133FF0: lui         $s4, 0x8014
    ctx->r20 = S32(0X8014 << 16);
    // 0x80133FF4: lui         $s7, 0x1
    ctx->r23 = S32(0X1 << 16);
    // 0x80133FF8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80133FFC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80134000: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80134004: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80134008: addiu       $s7, $s7, -0x1238
    ctx->r23 = ADD32(ctx->r23, -0X1238);
    // 0x8013400C: addiu       $s4, $s4, -0x6960
    ctx->r20 = ADD32(ctx->r20, -0X6960);
    // 0x80134010: addiu       $s3, $s3, -0x7048
    ctx->r19 = ADD32(ctx->r19, -0X7048);
    // 0x80134014: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80134018: addiu       $s5, $zero, -0x21
    ctx->r21 = ADD32(0, -0X21);
    // 0x8013401C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x80134020: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80134024: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
L_80134028:
    // 0x80134028: bne         $s1, $zero, L_8013404C
    if (ctx->r17 != 0) {
        // 0x8013402C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8013404C;
    }
    // 0x8013402C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134030: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x80134034: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
    // 0x80134038: bnel        $s2, $t6, L_8013404C
    if (ctx->r18 != ctx->r14) {
        // 0x8013403C: sw          $s2, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r18;
            goto L_8013404C;
    }
    goto skip_0;
    // 0x8013403C: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
    skip_0:
    // 0x80134040: b           L_8013404C
    // 0x80134044: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
        goto L_8013404C;
    // 0x80134044: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x80134048: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
L_8013404C:
    // 0x8013404C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80134050: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134054: bne         $t7, $zero, L_8013407C
    if (ctx->r15 != 0) {
        // 0x80134058: nop
    
            goto L_8013407C;
    }
    // 0x80134058: nop

    // 0x8013405C: jal         0x80133B74
    // 0x80134060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameGetArrowSObj(rdram, ctx);
        goto after_0;
    // 0x80134060: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80134064: beq         $v0, $zero, L_801340C0
    if (ctx->r2 == 0) {
        // 0x80134068: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801340C0;
    }
    // 0x80134068: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013406C: jal         0x800096EC
    // 0x80134070: nop

    gcEjectSObj(rdram, ctx);
        goto after_1;
    // 0x80134070: nop

    after_1:
    // 0x80134074: b           L_801340C4
    // 0x80134078: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
        goto L_801340C4;
    // 0x80134078: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_8013407C:
    // 0x8013407C: jal         0x80133B74
    // 0x80134080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    mnPlayers1PGameGetArrowSObj(rdram, ctx);
        goto after_2;
    // 0x80134080: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80134084: bne         $v0, $zero, L_801340C0
    if (ctx->r2 != 0) {
        // 0x80134088: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_801340C0;
    }
    // 0x80134088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013408C: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80134090: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x80134094: addiu       $t9, $t9, -0x1318
    ctx->r25 = ADD32(ctx->r25, -0X1318);
    // 0x80134098: jal         0x800CCFDC
    // 0x8013409C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8013409C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x801340A0: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x801340A4: swc1        $f24, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f24.u32l;
    // 0x801340A8: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x801340AC: and         $t2, $t0, $s5
    ctx->r10 = ctx->r8 & ctx->r21;
    // 0x801340B0: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801340B4: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x801340B8: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x801340BC: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
L_801340C0:
    // 0x801340C0: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_801340C4:
    // 0x801340C4: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x801340C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801340CC: bne         $s6, $t4, L_801340F4
    if (ctx->r22 != ctx->r12) {
        // 0x801340D0: nop
    
            goto L_801340F4;
    }
    // 0x801340D0: nop

    // 0x801340D4: jal         0x80133B74
    // 0x801340D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PGameGetArrowSObj(rdram, ctx);
        goto after_4;
    // 0x801340D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801340DC: beq         $v0, $zero, L_80134134
    if (ctx->r2 == 0) {
        // 0x801340E0: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80134134;
    }
    // 0x801340E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801340E4: jal         0x800096EC
    // 0x801340E8: nop

    gcEjectSObj(rdram, ctx);
        goto after_5;
    // 0x801340E8: nop

    after_5:
    // 0x801340EC: b           L_80134134
    // 0x801340F0: nop

        goto L_80134134;
    // 0x801340F0: nop

L_801340F4:
    // 0x801340F4: jal         0x80133B74
    // 0x801340F8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    mnPlayers1PGameGetArrowSObj(rdram, ctx);
        goto after_6;
    // 0x801340F8: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_6:
    // 0x801340FC: bne         $v0, $zero, L_80134134
    if (ctx->r2 != 0) {
        // 0x80134100: nop
    
            goto L_80134134;
    }
    // 0x80134100: nop

    // 0x80134104: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80134108: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013410C: jal         0x800CCFDC
    // 0x80134110: addu        $a1, $t5, $s7
    ctx->r5 = ADD32(ctx->r13, ctx->r23);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x80134110: addu        $a1, $t5, $s7
    ctx->r5 = ADD32(ctx->r13, ctx->r23);
    after_7:
    // 0x80134114: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80134118: swc1        $f22, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f22.u32l;
    // 0x8013411C: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x80134120: and         $t8, $t6, $s5
    ctx->r24 = ctx->r14 & ctx->r21;
    // 0x80134124: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80134128: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8013412C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80134130: sw          $fp, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r30;
L_80134134:
    // 0x80134134: jal         0x8000B1E8
    // 0x80134138: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_8;
    // 0x80134138: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_8:
    // 0x8013413C: b           L_80134028
    // 0x80134140: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
        goto L_80134028;
    // 0x80134140: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80134144: nop

    // 0x80134148: nop

    // 0x8013414C: nop

    // 0x80134150: nop

    // 0x80134154: nop

    // 0x80134158: nop

    // 0x8013415C: nop

    // 0x80134160: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80134164: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80134168: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8013416C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80134170: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80134174: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80134178: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8013417C: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80134180: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80134184: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80134188: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8013418C: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80134190: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80134194: jr          $ra
    // 0x80134198: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80134198: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void mnModeSelectMakeLabels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131FB4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131FB8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131FBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FC4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131FC8: jal         0x80009968
    // 0x80131FCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131FCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FD0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131FD4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131FD8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131FDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131FE0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131FE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131FE8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131FEC: jal         0x80009DF4
    // 0x80131FF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131FF0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131FF4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131FF8: lw          $t7, 0x2D6C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2D6C);
    // 0x80131FFC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132000: addiu       $t8, $t8, 0x5570
    ctx->r24 = ADD32(ctx->r24, 0X5570);
    // 0x80132004: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132008: jal         0x800CCFDC
    // 0x8013200C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8013200C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132010: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132014: lui         $at, 0x4360
    ctx->r1 = S32(0X4360 << 16);
    // 0x80132018: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013201C: lui         $at, 0x4250
    ctx->r1 = S32(0X4250 << 16);
    // 0x80132020: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132024: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132028: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013202C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132030: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132034: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132038: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x8013203C: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132040: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132044: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132048: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013204C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132050: lw          $t4, 0x2D6C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2D6C);
    // 0x80132054: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80132058: addiu       $t5, $t5, 0x57E0
    ctx->r13 = ADD32(ctx->r13, 0X57E0);
    // 0x8013205C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132060: jal         0x800CCFDC
    // 0x80132064: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132064: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x80132068: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x8013206C: lui         $at, 0x4337
    ctx->r1 = S32(0X4337 << 16);
    // 0x80132070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132074: lui         $at, 0x42B2
    ctx->r1 = S32(0X42B2 << 16);
    // 0x80132078: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013207C: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132080: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132084: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132088: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8013208C: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132090: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x80132094: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132098: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013209C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801320A0: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801320A4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801320A8: lw          $t1, 0x2D6C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2D6C);
    // 0x801320AC: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x801320B0: addiu       $t2, $t2, -0x7B08
    ctx->r10 = ADD32(ctx->r10, -0X7B08);
    // 0x801320B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801320B8: jal         0x800CCFDC
    // 0x801320BC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801320BC: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x801320C0: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x801320C4: lui         $at, 0x430E
    ctx->r1 = S32(0X430E << 16);
    // 0x801320C8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801320CC: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x801320D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801320D4: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x801320D8: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801320DC: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x801320E0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x801320E4: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x801320E8: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x801320EC: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801320F0: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801320F4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801320F8: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x801320FC: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132100: lw          $t8, 0x2D6C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2D6C);
    // 0x80132104: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80132108: addiu       $t9, $t9, 0x5980
    ctx->r25 = ADD32(ctx->r25, 0X5980);
    // 0x8013210C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132110: jal         0x800CCFDC
    // 0x80132114: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80132114: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_5:
    // 0x80132118: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x8013211C: lui         $at, 0x42CC
    ctx->r1 = S32(0X42CC << 16);
    // 0x80132120: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132124: lui         $at, 0x4323
    ctx->r1 = S32(0X4323 << 16);
    // 0x80132128: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013212C: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132130: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132134: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132138: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8013213C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132140: sb          $t4, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r12;
    // 0x80132144: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132148: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013214C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132150: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132154: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132158: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013215C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132160: jr          $ra
    // 0x80132164: nop

    return;
    // 0x80132164: nop

;}
RECOMP_FUNC void mnTitleMakeLogo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132FD8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80132FDC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132FE0: lbu         $t6, 0x4AD1($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AD1);
    // 0x80132FE4: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80132FE8: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80132FEC: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80132FF0: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80132FF4: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80132FF8: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80132FFC: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80133000: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80133004: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80133008: sdc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X40, ctx->r29);
    // 0x8013300C: beq         $t6, $at, L_80133024
    if (ctx->r14 == ctx->r1) {
        // 0x80133010: sdc1        $f20, 0x38($sp)
        CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
            goto L_80133024;
    }
    // 0x80133010: sdc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X38, ctx->r29);
    // 0x80133014: jal         0x80132F3C
    // 0x80133018: nop

    mnTitleMakeLogoNoOpening(rdram, ctx);
        goto after_0;
    // 0x80133018: nop

    after_0:
    // 0x8013301C: b           L_801331D0
    // 0x80133020: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
        goto L_801331D0;
    // 0x80133020: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_80133024:
    // 0x80133024: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80133028: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013302C: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80133030: jal         0x80009968
    // 0x80133034: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80133034: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80133038: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8013303C: addiu       $s5, $s5, 0x45A0
    ctx->r21 = ADD32(ctx->r21, 0X45A0);
    // 0x80133040: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x80133044: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80133048: addiu       $t8, $t8, 0x6020
    ctx->r24 = ADD32(ctx->r24, 0X6020);
    // 0x8013304C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80133050: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133054: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133058: jal         0x8000F120
    // 0x8013305C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_2;
    // 0x8013305C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80133060: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80133064: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x80133068: lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // 0x8013306C: addiu       $t0, $t0, 0x51D0
    ctx->r8 = ADD32(ctx->r8, 0X51D0);
    // 0x80133070: mfc1        $a2, $f22
    ctx->r6 = (int32_t)ctx->f22.u32l;
    // 0x80133074: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x80133078: jal         0x8000BD8C
    // 0x8013307C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x8013307C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80133080: jal         0x8000DF34
    // 0x80133084: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_4;
    // 0x80133084: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_4:
    // 0x80133088: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8013308C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133090: addiu       $a2, $zero, 0x7
    ctx->r6 = ADD32(0, 0X7);
    // 0x80133094: jal         0x80009968
    // 0x80133098: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80133098: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x8013309C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801330A0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801330A4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x801330A8: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x801330AC: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801330B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801330B4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801330B8: jal         0x80009DF4
    // 0x801330BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_6;
    // 0x801330BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_6:
    // 0x801330C0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801330C4: addiu       $a1, $a1, 0x25D4
    ctx->r5 = ADD32(ctx->r5, 0X25D4);
    // 0x801330C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801330CC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801330D0: jal         0x80008188
    // 0x801330D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_7;
    // 0x801330D4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x801330D8: sw          $s6, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r22;
    // 0x801330DC: lw          $t2, 0x74($s6)
    ctx->r10 = MEM_W(ctx->r22, 0X74);
    // 0x801330E0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801330E4: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x801330E8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801330EC: addiu       $s4, $s4, 0x41EC
    ctx->r20 = ADD32(ctx->r20, 0X41EC);
    // 0x801330F0: addiu       $s0, $s0, 0x41E0
    ctx->r16 = ADD32(ctx->r16, 0X41E0);
    // 0x801330F4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x801330F8: lw          $s1, 0x10($t2)
    ctx->r17 = MEM_W(ctx->r10, 0X10);
L_801330FC:
    // 0x801330FC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80133100: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x80133104: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80133108: jal         0x800CCFDC
    // 0x8013310C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_8;
    // 0x8013310C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_8:
    // 0x80133110: sh          $s3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r19;
    // 0x80133114: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
    // 0x80133118: swc1        $f20, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f20.u32l;
    // 0x8013311C: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80133120: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80133124: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80133128: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8013312C: swc1        $f22, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f22.u32l;
    // 0x80133130: swc1        $f22, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f22.u32l;
    // 0x80133134: bne         $s0, $s4, L_801330FC
    if (ctx->r16 != ctx->r20) {
        // 0x80133138: lw          $s1, 0x8($s1)
        ctx->r17 = MEM_W(ctx->r17, 0X8);
            goto L_801330FC;
    }
    // 0x80133138: lw          $s1, 0x8($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X8);
    // 0x8013313C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133140: lw          $t8, 0x41EC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X41EC);
    // 0x80133144: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x80133148: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x8013314C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133150: addiu       $t1, $t1, 0x2D5C
    ctx->r9 = ADD32(ctx->r9, 0X2D5C);
    // 0x80133154: addiu       $t5, $t5, 0x2DFC
    ctx->r13 = ADD32(ctx->r13, 0X2DFC);
    // 0x80133158: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013315C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80133160: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80133164: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80133168: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013316C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80133170: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80133174: addiu       $a1, $a1, 0x2EDC
    ctx->r5 = ADD32(ctx->r5, 0X2EDC);
    // 0x80133178: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8013317C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133180: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x80133184: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x80133188: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013318C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80133190: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80133194: jal         0x800CD050
    // 0x80133198: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_9;
    // 0x80133198: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    after_9:
    // 0x8013319C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801331A0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801331A4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801331A8: sh          $s3, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r19;
    // 0x801331AC: sb          $t2, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r10;
    // 0x801331B0: sb          $zero, 0x29($v1)
    MEM_B(0X29, ctx->r3) = 0;
    // 0x801331B4: sb          $zero, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = 0;
    // 0x801331B8: swc1        $f22, 0x1C($s1)
    MEM_W(0X1C, ctx->r17) = ctx->f22.u32l;
    // 0x801331BC: swc1        $f22, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f22.u32l;
    // 0x801331C0: sw          $s6, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r22;
    // 0x801331C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801331C8: sw          $t3, 0x446C($at)
    MEM_W(0X446C, ctx->r1) = ctx->r11;
    // 0x801331CC: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
L_801331D0:
    // 0x801331D0: ldc1        $f20, 0x38($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X38);
    // 0x801331D4: ldc1        $f22, 0x40($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X40);
    // 0x801331D8: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x801331DC: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x801331E0: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x801331E4: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x801331E8: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x801331EC: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x801331F0: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x801331F4: jr          $ra
    // 0x801331F8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x801331F8: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void grYosterUpdateCloudSolid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108634: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80108638: addiu       $t8, $t8, 0x13F0
    ctx->r24 = ADD32(ctx->r24, 0X13F0);
    // 0x8010863C: sll         $t7, $a0, 5
    ctx->r15 = S32(ctx->r4 << 5);
    // 0x80108640: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80108644: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80108648: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010864C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80108650: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80108654: lw          $t0, 0x80($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X80);
    // 0x80108658: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010865C: lwc1        $f4, 0xB00($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XB00);
    // 0x80108660: lwc1        $f6, 0x98($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X98);
    // 0x80108664: or          $t6, $a0, $zero
    ctx->r14 = ctx->r4 | 0;
    // 0x80108668: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8010866C: nop

    // 0x80108670: bc1fl       L_801087D8
    if (!c1cs) {
        // 0x80108674: lwc1        $f16, 0x14($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
            goto L_801087D8;
    }
    goto skip_0;
    // 0x80108674: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    skip_0:
    // 0x80108678: lbu         $t1, 0x1E($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X1E);
    // 0x8010867C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80108680: addu        $a0, $a0, $t6
    ctx->r4 = ADD32(ctx->r4, ctx->r14);
    // 0x80108684: bnel        $t1, $zero, L_801086A8
    if (ctx->r9 != 0) {
        // 0x80108688: lb          $t3, 0x1F($v1)
        ctx->r11 = MEM_B(ctx->r3, 0X1F);
            goto L_801086A8;
    }
    goto skip_1;
    // 0x80108688: lb          $t3, 0x1F($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X1F);
    skip_1:
    // 0x8010868C: lbu         $a0, -0x14D8($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14D8);
    // 0x80108690: jal         0x800FC58C
    // 0x80108694: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCollisionSetYakumonoOnID(rdram, ctx);
        goto after_0;
    // 0x80108694: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80108698: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8010869C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801086A0: sb          $t2, 0x1E($v1)
    MEM_B(0X1E, ctx->r3) = ctx->r10;
    // 0x801086A4: lb          $t3, 0x1F($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X1F);
L_801086A8:
    // 0x801086A8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801086AC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801086B0: bne         $t3, $zero, L_8010872C
    if (ctx->r11 != 0) {
        // 0x801086B4: lw          $a0, 0x30($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X30);
            goto L_8010872C;
    }
    // 0x801086B4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x801086B8: lw          $t8, 0x4($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X4);
    // 0x801086BC: addiu       $t7, $zero, 0xB4
    ctx->r15 = ADD32(0, 0XB4);
    // 0x801086C0: sb          $t4, 0x1C($v1)
    MEM_B(0X1C, ctx->r3) = ctx->r12;
    // 0x801086C4: sb          $t5, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r13;
    // 0x801086C8: sb          $t7, 0x20($v1)
    MEM_B(0X20, ctx->r3) = ctx->r15;
    // 0x801086CC: lw          $t9, 0x74($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X74);
    // 0x801086D0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x801086D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801086D8: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x801086DC: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x801086E0: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x801086E4: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x801086E8: lw          $t1, 0x24($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X24);
    // 0x801086EC: sw          $t1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r9;
    // 0x801086F0: lwc1        $f10, 0xB04($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XB04);
    // 0x801086F4: lui         $at, 0xC3AF
    ctx->r1 = S32(0XC3AF << 16);
    // 0x801086F8: lwc1        $f8, 0x24($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X24);
    // 0x801086FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80108700: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80108704: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80108708: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8010870C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80108710: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80108714: jal         0x80108550
    // 0x80108718: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    grYosterCloudVaporMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80108718: swc1        $f6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x8010871C: jal         0x800269C0
    // 0x80108720: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80108720: addiu       $a0, $zero, 0x113
    ctx->r4 = ADD32(0, 0X113);
    after_2:
    // 0x80108724: b           L_801087D4
    // 0x80108728: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_801087D4;
    // 0x80108728: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_8010872C:
    // 0x8010872C: jal         0x801085A8
    // 0x80108730: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    grYosterCheckFighterCloudStand(rdram, ctx);
        goto after_3;
    // 0x80108730: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_3:
    // 0x80108734: beq         $v0, $zero, L_8010878C
    if (ctx->r2 == 0) {
        // 0x80108738: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8010878C;
    }
    // 0x80108738: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8010873C: lb          $t6, 0x1F($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1F);
    // 0x80108740: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80108744: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x80108748: bnel        $t6, $at, L_80108758
    if (ctx->r14 != ctx->r1) {
        // 0x8010874C: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_80108758;
    }
    goto skip_2;
    // 0x8010874C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    skip_2:
    // 0x80108750: sb          $t2, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r10;
    // 0x80108754: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
L_80108758:
    // 0x80108758: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8010875C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80108760: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80108764: lwc1        $f8, 0x18($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80108768: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010876C: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
    // 0x80108770: lwc1        $f18, 0x18($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80108774: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80108778: nop

    // 0x8010877C: bc1fl       L_801087C8
    if (!c1cs) {
        // 0x80108780: lb          $v0, 0x1F($v1)
        ctx->r2 = MEM_B(ctx->r3, 0X1F);
            goto L_801087C8;
    }
    goto skip_3;
    // 0x80108780: lb          $v0, 0x1F($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1F);
    skip_3:
    // 0x80108784: b           L_801087C4
    // 0x80108788: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
        goto L_801087C4;
    // 0x80108788: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
L_8010878C:
    // 0x8010878C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80108790: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80108794: lwc1        $f4, 0x18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X18);
    // 0x80108798: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010879C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x801087A0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801087A4: sb          $t3, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r11;
    // 0x801087A8: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    // 0x801087AC: lwc1        $f10, 0x18($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X18);
    // 0x801087B0: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x801087B4: nop

    // 0x801087B8: bc1fl       L_801087C8
    if (!c1cs) {
        // 0x801087BC: lb          $v0, 0x1F($v1)
        ctx->r2 = MEM_B(ctx->r3, 0X1F);
            goto L_801087C8;
    }
    goto skip_4;
    // 0x801087BC: lb          $v0, 0x1F($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1F);
    skip_4:
    // 0x801087C0: swc1        $f0, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f0.u32l;
L_801087C4:
    // 0x801087C4: lb          $v0, 0x1F($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1F);
L_801087C8:
    // 0x801087C8: blez        $v0, L_801087D4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801087CC: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_801087D4;
    }
    // 0x801087CC: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x801087D0: sb          $t4, 0x1F($v1)
    MEM_B(0X1F, ctx->r3) = ctx->r12;
L_801087D4:
    // 0x801087D4: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
L_801087D8:
    // 0x801087D8: lwc1        $f18, 0x18($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X18);
    // 0x801087DC: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x801087E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801087E4: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x801087E8: lw          $v0, 0x74($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X74);
    // 0x801087EC: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x801087F0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x801087F4: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    // 0x801087F8: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x801087FC: jal         0x800FC4A8
    // 0x80108800: lbu         $a0, -0x14D8($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14D8);
    mpCollisionSetYakumonoPosID(rdram, ctx);
        goto after_4;
    // 0x80108800: lbu         $a0, -0x14D8($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14D8);
    after_4:
    // 0x80108804: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108808: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8010880C: jr          $ra
    // 0x80108810: nop

    return;
    // 0x80108810: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirHiStartProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152818: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015281C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152820: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80152824: lui         $a1, 0x3F4C
    ctx->r5 = S32(0X3F4C << 16);
    // 0x80152828: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x8015282C: lw          $v0, 0x9C8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9C8);
    // 0x80152830: lw          $a2, 0x5C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X5C);
    // 0x80152834: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x80152838: jal         0x800D8D68
    // 0x8015283C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8015283C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80152840: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80152844: jal         0x800D8FA8
    // 0x80152848: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_1;
    // 0x80152848: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015284C: bne         $v0, $zero, L_8015285C
    if (ctx->r2 != 0) {
        // 0x80152850: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8015285C;
    }
    // 0x80152850: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80152854: jal         0x800D9074
    // 0x80152858: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_2;
    // 0x80152858: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    after_2:
L_8015285C:
    // 0x8015285C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152860: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80152864: jr          $ra
    // 0x80152868: nop

    return;
    // 0x80152868: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeRoom(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132648: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013264C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132650: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132658: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8013265C: jal         0x80009968
    // 0x80132660: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132660: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132664: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132668: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013266C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132670: sw          $v0, 0x4318($at)
    MEM_W(0X4318, ctx->r1) = ctx->r2;
    // 0x80132674: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132678: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013267C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132680: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132684: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80132688: jal         0x80009DF4
    // 0x8013268C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013268C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132690: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132694: lw          $t7, 0x4528($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4528);
    // 0x80132698: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8013269C: addiu       $t8, $t8, -0x1C28
    ctx->r24 = ADD32(ctx->r24, -0X1C28);
    // 0x801326A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801326A4: jal         0x800CCFDC
    // 0x801326A8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801326A8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801326AC: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x801326B0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801326B4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x801326B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801326BC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801326C0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801326C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801326C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801326CC: jr          $ra
    // 0x801326D0: nop

    return;
    // 0x801326D0: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingPuckProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801363C8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801363CC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801363D0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801363D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801363D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801363DC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801363E0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801363E4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801363E8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801363EC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801363F0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801363F4: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801363F8: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x801363FC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80136400: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80136404: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80136408: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8013640C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80136410: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80136414: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80136418: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x8013641C: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80136420: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80136424: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80136428: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013642C: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80136430: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80136434: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80136438: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013643C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80136440: lw          $a1, -0x778C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X778C);
    // 0x80136444: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x80136448: sll         $t9, $a1, 24
    ctx->r25 = S32(ctx->r5 << 24);
    // 0x8013644C: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80136450: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x80136454: sll         $t6, $a1, 8
    ctx->r14 = S32(ctx->r5 << 8);
    // 0x80136458: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x8013645C: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x80136460: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80136464: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80136468: lui         $t5, 0x33FD
    ctx->r13 = S32(0X33FD << 16);
    // 0x8013646C: lui         $t4, 0xFC12
    ctx->r12 = S32(0XFC12 << 16);
    // 0x80136470: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80136474: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80136478: ori         $t4, $t4, 0xFE25
    ctx->r12 = ctx->r12 | 0XFE25;
    // 0x8013647C: ori         $t5, $t5, 0xF2F9
    ctx->r13 = ctx->r13 | 0XF2F9;
    // 0x80136480: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80136484: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80136488: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013648C: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80136490: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80136494: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80136498: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013649C: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x801364A0: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x801364A4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801364A8: jal         0x800CCF74
    // 0x801364AC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_0;
    // 0x801364AC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    after_0:
    // 0x801364B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801364B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801364B8: jr          $ra
    // 0x801364BC: nop

    return;
    // 0x801364BC: nop

;}
RECOMP_FUNC void _n_timeToSamplesNoRound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C544: jr          $ra
    // 0x8002C548: nop

    return;
    // 0x8002C548: nop

;}
RECOMP_FUNC void ftKirbySpecialAirLwEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161C5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80161C60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161C64: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80161C68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80161C6C: addiu       $a1, $zero, 0x10C
    ctx->r5 = ADD32(0, 0X10C);
    // 0x80161C70: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161C74: jal         0x800E6F24
    // 0x80161C78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80161C78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80161C7C: jal         0x800E0830
    // 0x80161C80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80161C80: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80161C84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80161C88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80161C8C: jr          $ra
    // 0x80161C90: nop

    return;
    // 0x80161C90: nop

;}
RECOMP_FUNC void sc1PIntroMakeFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F90: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80133F94: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133F98: addiu       $t7, $t7, 0x59D0
    ctx->r15 = ADD32(ctx->r15, 0X59D0);
    // 0x80133F9C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80133FA0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80133FA4: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x80133FA8: sw          $a1, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r5;
    // 0x80133FAC: addiu       $v0, $sp, 0x5C
    ctx->r2 = ADD32(ctx->r29, 0X5C);
    // 0x80133FB0: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80133FB4: addiu       $t6, $sp, 0x8C
    ctx->r14 = ADD32(ctx->r29, 0X8C);
L_80133FB8:
    // 0x80133FB8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133FBC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80133FC0: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133FC4: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80133FC8: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80133FCC: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80133FD0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80133FD4: bne         $t7, $t0, L_80133FB8
    if (ctx->r15 != ctx->r8) {
        // 0x80133FD8: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80133FB8;
    }
    // 0x80133FD8: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80133FDC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133FE0: addiu       $t1, $t1, 0x5A00
    ctx->r9 = ADD32(ctx->r9, 0X5A00);
    // 0x80133FE4: addiu       $t5, $t1, 0x30
    ctx->r13 = ADD32(ctx->r9, 0X30);
    // 0x80133FE8: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_80133FEC:
    // 0x80133FEC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80133FF0: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80133FF4: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x80133FF8: sw          $t3, -0xC($t4)
    MEM_W(-0XC, ctx->r12) = ctx->r11;
    // 0x80133FFC: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x80134000: sw          $t2, -0x8($t4)
    MEM_W(-0X8, ctx->r12) = ctx->r10;
    // 0x80134004: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x80134008: bne         $t1, $t5, L_80133FEC
    if (ctx->r9 != ctx->r13) {
        // 0x8013400C: sw          $t3, -0x4($t4)
        MEM_W(-0X4, ctx->r12) = ctx->r11;
            goto L_80133FEC;
    }
    // 0x8013400C: sw          $t3, -0x4($t4)
    MEM_W(-0X4, ctx->r12) = ctx->r11;
    // 0x80134010: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x80134014: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x80134018: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013401C: sll         $t7, $t0, 3
    ctx->r15 = S32(ctx->r8 << 3);
    // 0x80134020: addu        $s0, $v0, $t7
    ctx->r16 = ADD32(ctx->r2, ctx->r15);
    // 0x80134024: lw          $a3, 0x0($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X0);
    // 0x80134028: jal         0x80030A54
    // 0x8013402C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    __ll_lshift_recomp(rdram, ctx);
        goto after_0;
    // 0x8013402C: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_0:
    // 0x80134030: lui         $t8, 0x8001
    ctx->r24 = S32(0X8001 << 16);
    // 0x80134034: addiu       $t8, $t8, 0x7EC0
    ctx->r24 = ADD32(ctx->r24, 0X7EC0);
    // 0x80134038: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8013403C: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80134040: ori         $t3, $v1, 0x8400
    ctx->r11 = ctx->r3 | 0X8400;
    // 0x80134044: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80134048: or          $t1, $t3, $at
    ctx->r9 = ctx->r11 | ctx->r1;
    // 0x8013404C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80134050: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80134054: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80134058: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8013405C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80134060: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80134064: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80134068: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8013406C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80134070: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80134074: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80134078: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013407C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134080: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80134084: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80134088: jal         0x8000B93C
    // 0x8013408C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    gcMakeCameraGObj(rdram, ctx);
        goto after_1;
    // 0x8013408C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_1:
    // 0x80134090: sw          $v0, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r2;
    // 0x80134094: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x80134098: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8013409C: jal         0x80008CF0
    // 0x801340A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_2;
    // 0x801340A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801340A4: lw          $t9, 0xDC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XDC);
    // 0x801340A8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x801340AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801340B0: jal         0x80008CF0
    // 0x801340B4: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    gcAddXObjForCamera(rdram, ctx);
        goto after_3;
    // 0x801340B4: lw          $a0, 0x74($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X74);
    after_3:
    // 0x801340B8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801340BC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801340C0: lw          $t4, 0xDC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XDC);
    // 0x801340C4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801340C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801340CC: lw          $s0, 0x74($t4)
    ctx->r16 = MEM_W(ctx->r12, 0X74);
    // 0x801340D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801340D4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801340D8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801340DC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801340E0: jal         0x80007080
    // 0x801340E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_4;
    // 0x801340E4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_4:
    // 0x801340E8: addiu       $a0, $sp, 0xBC
    ctx->r4 = ADD32(ctx->r29, 0XBC);
    // 0x801340EC: lw          $a1, 0xE0($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XE0);
    // 0x801340F0: jal         0x80133EE0
    // 0x801340F4: lw          $a2, 0xE4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE4);
    sc1PIntroGetFighterCObjDesc(rdram, ctx);
        goto after_5;
    // 0x801340F4: lw          $a2, 0xE4($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XE4);
    after_5:
    // 0x801340F8: lw          $t5, 0xE0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE0);
    // 0x801340FC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80134100: lw          $t0, 0x6058($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6058);
    // 0x80134104: sll         $t2, $t5, 2
    ctx->r10 = S32(ctx->r13 << 2);
    // 0x80134108: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x8013410C: lw          $t3, 0x8C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X8C);
    // 0x80134110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80134114: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80134118: jal         0x8000FA3C
    // 0x8013411C: addu        $a1, $t3, $t0
    ctx->r5 = ADD32(ctx->r11, ctx->r8);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_6;
    // 0x8013411C: addu        $a1, $t3, $t0
    ctx->r5 = ADD32(ctx->r11, ctx->r8);
    after_6:
    // 0x80134120: jal         0x80010580
    // 0x80134124: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    gcPlayCamAnim(rdram, ctx);
        goto after_7;
    // 0x80134124: lw          $a0, 0xDC($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XDC);
    after_7:
    // 0x80134128: lwc1        $f6, 0xBC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XBC);
    // 0x8013412C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80134130: lw          $t1, 0x80($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X80);
    // 0x80134134: swc1        $f6, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f6.u32l;
    // 0x80134138: lwc1        $f8, 0xC0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x8013413C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134140: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80134144: swc1        $f8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f8.u32l;
    // 0x80134148: lwc1        $f10, 0xC4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XC4);
    // 0x8013414C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80134150: ori         $t7, $t1, 0x1
    ctx->r15 = ctx->r9 | 0X1;
    // 0x80134154: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x80134158: lwc1        $f16, 0xC8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XC8);
    // 0x8013415C: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x80134160: lwc1        $f18, 0xCC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XCC);
    // 0x80134164: swc1        $f18, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f18.u32l;
    // 0x80134168: lwc1        $f4, 0xD0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XD0);
    // 0x8013416C: sw          $t7, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r15;
    // 0x80134170: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80134174: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80134178: swc1        $f4, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f4.u32l;
    // 0x8013417C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80134180: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80134184: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x80134188: jr          $ra
    // 0x8013418C: nop

    return;
    // 0x8013418C: nop

;}
RECOMP_FUNC void ftParamProcStopEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9C3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E9C40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9C44: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E9C48: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800E9C4C: addiu       $a1, $a1, -0x6418
    ctx->r5 = ADD32(ctx->r5, -0X6418);
    // 0x800E9C50: jal         0x800E9B64
    // 0x800E9C54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftParamRunProcEffect(rdram, ctx);
        goto after_0;
    // 0x800E9C54: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x800E9C58: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9C5C: lbu         $t6, 0x18F($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18F);
    // 0x800E9C60: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x800E9C64: sb          $t7, 0x18F($v0)
    MEM_B(0X18F, ctx->r2) = ctx->r15;
    // 0x800E9C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9C6C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E9C70: jr          $ra
    // 0x800E9C74: nop

    return;
    // 0x800E9C74: nop

;}

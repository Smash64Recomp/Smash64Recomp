#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftLinkSpecialHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163F30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80163F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163F38: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80163F3C: jal         0x800D9480
    // 0x80163F40: addiu       $a1, $a1, 0x42EC
    ctx->r5 = ADD32(ctx->r5, 0X42EC);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80163F40: addiu       $a1, $a1, 0x42EC
    ctx->r5 = ADD32(ctx->r5, 0X42EC);
    after_0:
    // 0x80163F44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80163F48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80163F4C: jr          $ra
    // 0x80163F50: nop

    return;
    // 0x80163F50: nop

;}
RECOMP_FUNC void func_ovl8_80371E24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371E24: jr          $ra
    // 0x80371E28: sw          $a1, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r5;
    return;
    // 0x80371E28: sw          $a1, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void mnPlayers1PBonusGetFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132390: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132394: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132398: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x8013239C: addiu       $t6, $t6, 0x71A4
    ctx->r14 = ADD32(ctx->r14, 0X71A4);
    // 0x801323A0: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x801323A4: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_801323A8:
    // 0x801323A8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801323AC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x801323B0: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x801323B4: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x801323B8: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x801323BC: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x801323C0: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x801323C4: bne         $t6, $t0, L_801323A8
    if (ctx->r14 != ctx->r8) {
        // 0x801323C8: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801323A8;
    }
    // 0x801323C8: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x801323CC: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x801323D0: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x801323D4: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x801323D8: jr          $ra
    // 0x801323DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801323DC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void grWallpaperMakeBonus3(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80104B88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80104B8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80104B90: addiu       $a0, $zero, 0x3F0
    ctx->r4 = ADD32(0, 0X3F0);
    // 0x80104B94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80104B98: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x80104B9C: jal         0x80009968
    // 0x80104BA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80104BA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80104BA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80104BA8: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x80104BAC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80104BB0: sw          $v0, 0x13D8($at)
    MEM_W(0X13D8, ctx->r1) = ctx->r2;
    // 0x80104BB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80104BB8: addiu       $a1, $a1, 0x4B58
    ctx->r5 = ADD32(ctx->r5, 0X4B58);
    // 0x80104BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80104BC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80104BC4: jal         0x80009DF4
    // 0x80104BC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80104BC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80104BCC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80104BD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80104BD4: jr          $ra
    // 0x80104BD8: nop

    return;
    // 0x80104BD8: nop

;}
RECOMP_FUNC void sc1PGameGetStartPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D3D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D3DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8018D3E0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8018D3E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D3E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8018D3EC: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8018D3F0: jal         0x800FC7A4
    // 0x8018D3F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_0;
    // 0x8018D3F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8018D3F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D3FC: beq         $v0, $at, L_8018D434
    if (ctx->r2 == ctx->r1) {
        // 0x8018D400: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8018D434;
    }
    // 0x8018D400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D404: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018D408: addiu       $s1, $s1, 0x2E10
    ctx->r17 = ADD32(ctx->r17, 0X2E10);
L_8018D40C:
    // 0x8018D40C: jal         0x800FC7A4
    // 0x8018D410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_1;
    // 0x8018D410: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8018D414: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D418: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D41C: jal         0x80023624
    // 0x8018D420: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x8018D420: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x8018D424: jal         0x800A3040
    // 0x8018D428: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x8018D428: nop

    after_3:
    // 0x8018D42C: b           L_8018D40C
    // 0x8018D430: nop

        goto L_8018D40C;
    // 0x8018D430: nop

L_8018D434:
    // 0x8018D434: jal         0x800FC814
    // 0x8018D438: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_4;
    // 0x8018D438: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x8018D43C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8018D440: jal         0x800FC894
    // 0x8018D444: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_5;
    // 0x8018D444: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x8018D448: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D44C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8018D450: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8018D454: jr          $ra
    // 0x8018D458: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018D458: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftBossYubideppou2ProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A6FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A700: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A704: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015A708: lh          $t6, 0xB18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB18);
    // 0x8015A70C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8015A710: sh          $t7, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r15;
    // 0x8015A714: lh          $t8, 0xB18($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XB18);
    // 0x8015A718: bne         $t8, $zero, L_8015A730
    if (ctx->r24 != 0) {
        // 0x8015A71C: nop
    
            goto L_8015A730;
    }
    // 0x8015A71C: nop

    // 0x8015A720: jal         0x8015A538
    // 0x8015A724: nop

    ftBossYubideppou3SetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A724: nop

    after_0:
    // 0x8015A728: b           L_8015A73C
    // 0x8015A72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015A73C;
    // 0x8015A72C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015A730:
    // 0x8015A730: jal         0x8015A600
    // 0x8015A734: nop

    ftBossYubideppou2UpdatePosition(rdram, ctx);
        goto after_1;
    // 0x8015A734: nop

    after_1:
    // 0x8015A738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015A73C:
    // 0x8015A73C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A740: jr          $ra
    // 0x8015A744: nop

    return;
    // 0x8015A744: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiInitMiscVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152960: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80152964: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152968: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015296C: jal         0x800E8A24
    // 0x80152970: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    ftParamSetHitStatusAll(rdram, ctx);
        goto after_0;
    // 0x80152970: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_0:
    // 0x80152974: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80152978: addiu       $a1, $zero, 0x39
    ctx->r5 = ADD32(0, 0X39);
    // 0x8015297C: jal         0x800E9814
    // 0x80152980: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_1;
    // 0x80152980: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80152984: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80152988: jal         0x8000BB04
    // 0x8015298C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    gcSetAnimSpeed(rdram, ctx);
        goto after_2;
    // 0x8015298C: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_2:
    // 0x80152990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152994: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152998: jr          $ra
    // 0x8015299C: nop

    return;
    // 0x8015299C: nop

;}
RECOMP_FUNC void itNBumperHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B678: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B67C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B680: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017B684: addiu       $a1, $a1, -0x593C
    ctx->r5 = ADD32(ctx->r5, -0X593C);
    // 0x8017B688: jal         0x80172EC8
    // 0x8017B68C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017B68C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_0:
    // 0x8017B690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B698: jr          $ra
    // 0x8017B69C: nop

    return;
    // 0x8017B69C: nop

;}
RECOMP_FUNC void syInterpGetCubicIntegralApprox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E240: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001E244: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x8001E248: swc1        $f14, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f14.u32l;
    // 0x8001E24C: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001E250: lwc1        $f6, 0x50($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001E254: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8001E258: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8001E25C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001E260: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8001E264: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8001E268: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8001E26C: div.s       $f24, $f8, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001E270: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8001E274: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8001E278: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8001E27C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8001E280: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8001E284: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8001E288: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x8001E28C: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8001E290: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001E294: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x8001E298: addiu       $s2, $zero, 0x9
    ctx->r18 = ADD32(0, 0X9);
    // 0x8001E29C: swc1        $f24, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f24.u32l;
    // 0x8001E2A0: add.s       $f20, $f6, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f6.fl + ctx->f24.fl;
L_8001E2A4:
    // 0x8001E2A4: andi        $t6, $s0, 0x1
    ctx->r14 = ctx->r16 & 0X1;
    // 0x8001E2A8: bne         $t6, $zero, L_8001E2C8
    if (ctx->r14 != 0) {
        // 0x8001E2AC: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_8001E2C8;
    }
    // 0x8001E2AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8001E2B0: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8001E2B4: jal         0x8001E1A8
    // 0x8001E2B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syInterpGetQuartSum(rdram, ctx);
        goto after_0;
    // 0x8001E2B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x8001E2BC: mul.s       $f16, $f26, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f26.fl, ctx->f0.fl);
    // 0x8001E2C0: b           L_8001E2D8
    // 0x8001E2C4: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
        goto L_8001E2D8;
    // 0x8001E2C4: add.s       $f22, $f22, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f16.fl;
L_8001E2C8:
    // 0x8001E2C8: jal         0x8001E1A8
    // 0x8001E2CC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    syInterpGetQuartSum(rdram, ctx);
        goto after_1;
    // 0x8001E2CC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_1:
    // 0x8001E2D0: add.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x8001E2D4: add.s       $f22, $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f18.fl;
L_8001E2D8:
    // 0x8001E2D8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E2DC: bne         $s0, $s2, L_8001E2A4
    if (ctx->r16 != ctx->r18) {
        // 0x8001E2E0: add.s       $f20, $f20, $f24
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
            goto L_8001E2A4;
    }
    // 0x8001E2E0: add.s       $f20, $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f24.fl;
    // 0x8001E2E4: lwc1        $f12, 0x50($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8001E2E8: jal         0x8001E1A8
    // 0x8001E2EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syInterpGetQuartSum(rdram, ctx);
        goto after_2;
    // 0x8001E2EC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8001E2F0: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8001E2F4: lwc1        $f12, 0x54($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8001E2F8: jal         0x8001E1A8
    // 0x8001E2FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syInterpGetQuartSum(rdram, ctx);
        goto after_3;
    // 0x8001E2FC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x8001E300: add.s       $f4, $f20, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x8001E304: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8001E308: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8001E30C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8001E310: add.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x8001E314: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8001E318: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8001E31C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8001E320: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8001E324: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8001E328: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8001E32C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8001E330: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8001E334: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8001E338: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8001E33C: jr          $ra
    // 0x8001E340: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    return;
    // 0x8001E340: div.s       $f0, $f6, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
;}
RECOMP_FUNC void ftPhysicsApplyGravityClampTVel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8D68: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800D8D6C: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800D8D70: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800D8D74: sub.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800D8D78: neg.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = -ctx->f14.fl;
    // 0x800D8D7C: swc1        $f6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f6.u32l;
    // 0x800D8D80: lwc1        $f8, 0x4C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x800D8D84: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800D8D88: nop

    // 0x800D8D8C: bc1f        L_800D8D98
    if (!c1cs) {
        // 0x800D8D90: nop
    
            goto L_800D8D98;
    }
    // 0x800D8D90: nop

    // 0x800D8D94: swc1        $f0, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f0.u32l;
L_800D8D98:
    // 0x800D8D98: jr          $ra
    // 0x800D8D9C: nop

    return;
    // 0x800D8D9C: nop

;}
RECOMP_FUNC void func_ovl8_80385E10(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385E10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80385E14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385E18: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80385E1C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80385E20: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80385E24: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80385E28: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80385E2C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80385E30: jal         0x803863A4
    // 0x80385E34: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    func_ovl8_803863A4(rdram, ctx);
        goto after_0;
    // 0x80385E34: addiu       $a0, $zero, 0x30
    ctx->r4 = ADD32(0, 0X30);
    after_0:
    // 0x80385E38: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80385E3C: addiu       $t7, $t7, -0x1A9C
    ctx->r15 = ADD32(ctx->r15, -0X1A9C);
    // 0x80385E40: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80385E44: addiu       $t6, $t6, -0x1DF8
    ctx->r14 = ADD32(ctx->r14, -0X1DF8);
    // 0x80385E48: addiu       $t0, $t7, 0x24
    ctx->r8 = ADD32(ctx->r15, 0X24);
L_80385E4C:
    // 0x80385E4C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80385E50: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80385E54: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80385E58: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80385E5C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80385E60: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80385E64: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80385E68: bne         $t7, $t0, L_80385E4C
    if (ctx->r15 != ctx->r8) {
        // 0x80385E6C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80385E4C;
    }
    // 0x80385E6C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80385E70: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80385E74: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80385E78: addiu       $a0, $a0, -0x1E20
    ctx->r4 = ADD32(ctx->r4, -0X1E20);
    // 0x80385E7C: jal         0x80381C80
    // 0x80385E80: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    func_ovl8_80381C80(rdram, ctx);
        goto after_1;
    // 0x80385E80: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    after_1:
    // 0x80385E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80385E88: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x80385E8C: sw          $v0, 0x3C0($at)
    MEM_W(0X3C0, ctx->r1) = ctx->r2;
    // 0x80385E90: jr          $ra
    // 0x80385E94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80385E94: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftParamPlayLoopSFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8190: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8194: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8198: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800E819C: lw          $t6, 0xA20($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XA20);
    // 0x800E81A0: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    // 0x800E81A4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800E81A8: bne         $t6, $zero, L_800E81D4
    if (ctx->r14 != 0) {
        // 0x800E81AC: andi        $a0, $a1, 0xFFFF
        ctx->r4 = ctx->r5 & 0XFFFF;
            goto L_800E81D4;
    }
    // 0x800E81AC: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    // 0x800E81B0: jal         0x800269C0
    // 0x800E81B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x800E81B4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E81B8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800E81BC: beq         $v0, $zero, L_800E81D0
    if (ctx->r2 == 0) {
        // 0x800E81C0: sw          $v0, 0xA20($a2)
        MEM_W(0XA20, ctx->r6) = ctx->r2;
            goto L_800E81D0;
    }
    // 0x800E81C0: sw          $v0, 0xA20($a2)
    MEM_W(0XA20, ctx->r6) = ctx->r2;
    // 0x800E81C4: lhu         $t8, 0x26($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X26);
    // 0x800E81C8: b           L_800E81D4
    // 0x800E81CC: sh          $t8, 0xA24($a2)
    MEM_H(0XA24, ctx->r6) = ctx->r24;
        goto L_800E81D4;
    // 0x800E81CC: sh          $t8, 0xA24($a2)
    MEM_H(0XA24, ctx->r6) = ctx->r24;
L_800E81D0:
    // 0x800E81D0: sh          $zero, 0xA24($a2)
    MEM_H(0XA24, ctx->r6) = 0;
L_800E81D4:
    // 0x800E81D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E81D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E81DC: jr          $ra
    // 0x800E81E0: nop

    return;
    // 0x800E81E0: nop

;}
RECOMP_FUNC void func_80020FA0_21BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020FA0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80020FA4: jr          $ra
    // 0x80020FA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80020FA8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void ftNessSpecialAirLwHitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015598C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155990: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155994: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80155998: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015599C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801559A0: addiu       $a1, $zero, 0xF3
    ctx->r5 = ADD32(0, 0XF3);
    // 0x801559A4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801559A8: jal         0x800E6F24
    // 0x801559AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801559AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x801559B0: jal         0x800E0830
    // 0x801559B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801559B4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801559B8: jal         0x80155934
    // 0x801559BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftNessSpecialLwHitSetAbsorbTrue(rdram, ctx);
        goto after_2;
    // 0x801559BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x801559C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801559C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801559C8: jr          $ra
    // 0x801559CC: nop

    return;
    // 0x801559CC: nop

;}
RECOMP_FUNC void mvOpeningMarioFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DFE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DFE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DFEC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018DFF0: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018DFF4: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018DFF8: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018DFFC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018E000: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018E004: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018E008: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E00C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018E010: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018E014: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018E018: jal         0x800FCB70
    // 0x8018E01C: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E01C: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E020: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E024: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E028: jr          $ra
    // 0x8018E02C: nop

    return;
    // 0x8018E02C: nop

;}
RECOMP_FUNC void ftBossYubideppou2UpdatePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A600: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8015A604: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015A608: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015A60C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015A610: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015A614: lwc1        $f8, -0x37E0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X37E0);
    // 0x8015A618: lw          $t6, 0x44($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X44);
    // 0x8015A61C: lw          $t8, 0xADC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XADC);
    // 0x8015A620: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8015A624: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x8015A628: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8015A62C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8015A630: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8015A634: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8015A638: lw          $t0, 0x74($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X74);
    // 0x8015A63C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x8015A640: lwc1        $f16, 0x1C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x8015A644: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015A648: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8015A64C: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8015A650: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x8015A654: lw          $t1, 0xADC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XADC);
    // 0x8015A658: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8015A65C: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x8015A660: lwc1        $f4, 0x20($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X20);
    // 0x8015A664: swc1        $f6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f6.u32l;
    // 0x8015A668: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x8015A66C: lw          $a2, 0x74($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X74);
    // 0x8015A670: jal         0x8001902C
    // 0x8015A674: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x8015A674: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_0:
    // 0x8015A678: jal         0x80018F7C
    // 0x8015A67C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    syVectorMag3D(rdram, ctx);
        goto after_1;
    // 0x8015A67C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x8015A680: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8015A684: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015A688: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8015A68C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8015A690: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8015A694: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8015A698: bc1f        L_8015A6B0
    if (!c1cs) {
        // 0x8015A69C: nop
    
            goto L_8015A6B0;
    }
    // 0x8015A69C: nop

    // 0x8015A6A0: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x8015A6A4: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8015A6A8: b           L_8015A6E8
    // 0x8015A6AC: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
        goto L_8015A6E8;
    // 0x8015A6AC: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
L_8015A6B0:
    // 0x8015A6B0: jal         0x80018EE0
    // 0x8015A6B4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_2;
    // 0x8015A6B4: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x8015A6B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015A6BC: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8015A6C0: lwc1        $f18, -0x37DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X37DC);
    // 0x8015A6C4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8015A6C8: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8015A6CC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8015A6D0: jal         0x800190B0
    // 0x8015A6D4: nop

    syVectorScale3D(rdram, ctx);
        goto after_3;
    // 0x8015A6D4: nop

    after_3:
    // 0x8015A6D8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8015A6DC: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x8015A6E0: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8015A6E4: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
L_8015A6E8:
    // 0x8015A6E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015A6EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015A6F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8015A6F4: jr          $ra
    // 0x8015A6F8: nop

    return;
    // 0x8015A6F8: nop

;}
RECOMP_FUNC void mpCollisionCheckCeilSurfaceTilt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F5A64: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800F5A68: lwc1        $f12, 0x7C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F5A6C: lwc1        $f14, 0x84($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800F5A70: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800F5A74: subu        $v0, $a3, $a1
    ctx->r2 = SUB32(ctx->r7, ctx->r5);
    // 0x800F5A78: sub.s       $f0, $f12, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800F5A7C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800F5A80: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800F5A84: bgez        $v0, L_800F5A98
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800F5A88: swc1        $f0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
            goto L_800F5A98;
    }
    // 0x800F5A88: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    // 0x800F5A8C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x800F5A90: b           L_800F5A9C
    // 0x800F5A94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
        goto L_800F5A9C;
    // 0x800F5A94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_800F5A98:
    // 0x800F5A98: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_800F5A9C:
    // 0x800F5A9C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800F5AA0: nop

    // 0x800F5AA4: bc1fl       L_800F5B00
    if (!c1cs) {
        // 0x800F5AA8: mtc1        $a0, $f6
        ctx->f6.u32l = ctx->r4;
            goto L_800F5B00;
    }
    goto skip_0;
    // 0x800F5AA8: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    skip_0:
    // 0x800F5AAC: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800F5AB0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5AB4: lwc1        $f10, 0x7D8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7D8);
    // 0x800F5AB8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F5ABC: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F5AC0: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x800F5AC4: nop

    // 0x800F5AC8: bc1t        L_800F5AF4
    if (c1cs) {
        // 0x800F5ACC: nop
    
            goto L_800F5AF4;
    }
    // 0x800F5ACC: nop

    // 0x800F5AD0: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800F5AD4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5AD8: lwc1        $f10, 0x7DC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7DC);
    // 0x800F5ADC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F5AE0: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F5AE4: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x800F5AE8: nop

    // 0x800F5AEC: bc1fl       L_800F5B50
    if (!c1cs) {
        // 0x800F5AF0: lwc1        $f16, 0x78($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
            goto L_800F5B50;
    }
    goto skip_1;
    // 0x800F5AF0: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    skip_1:
L_800F5AF4:
    // 0x800F5AF4: b           L_800F5E88
    // 0x800F5AF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5E88;
    // 0x800F5AF8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5AFC: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
L_800F5B00:
    // 0x800F5B00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5B04: lwc1        $f10, 0x7E0($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7E0);
    // 0x800F5B08: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F5B0C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F5B10: c.lt.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl < ctx->f12.fl;
    // 0x800F5B14: nop

    // 0x800F5B18: bc1t        L_800F5B44
    if (c1cs) {
        // 0x800F5B1C: nop
    
            goto L_800F5B44;
    }
    // 0x800F5B1C: nop

    // 0x800F5B20: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800F5B24: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5B28: lwc1        $f10, 0x7E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7E4);
    // 0x800F5B2C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F5B30: sub.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F5B34: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800F5B38: nop

    // 0x800F5B3C: bc1fl       L_800F5B50
    if (!c1cs) {
        // 0x800F5B40: lwc1        $f16, 0x78($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
            goto L_800F5B50;
    }
    goto skip_2;
    // 0x800F5B40: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    skip_2:
L_800F5B44:
    // 0x800F5B44: b           L_800F5E88
    // 0x800F5B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5E88;
    // 0x800F5B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5B4C: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
L_800F5B50:
    // 0x800F5B50: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800F5B54: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x800F5B58: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800F5B5C: sub.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800F5B60: subu        $v1, $a2, $t6
    ctx->r3 = SUB32(ctx->r6, ctx->r14);
    // 0x800F5B64: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x800F5B68: bgez        $v1, L_800F5B7C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800F5B6C: swc1        $f0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
            goto L_800F5B7C;
    }
    // 0x800F5B6C: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x800F5B70: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800F5B74: b           L_800F5B80
    // 0x800F5B78: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
        goto L_800F5B80;
    // 0x800F5B78: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_800F5B7C:
    // 0x800F5B7C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
L_800F5B80:
    // 0x800F5B80: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800F5B84: nop

    // 0x800F5B88: bc1fl       L_800F5BD4
    if (!c1cs) {
        // 0x800F5B8C: mtc1        $a3, $f4
        ctx->f4.u32l = ctx->r7;
            goto L_800F5BD4;
    }
    goto skip_3;
    // 0x800F5B8C: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    skip_3:
    // 0x800F5B90: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x800F5B94: nop

    // 0x800F5B98: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F5B9C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800F5BA0: nop

    // 0x800F5BA4: bc1t        L_800F5BC8
    if (c1cs) {
        // 0x800F5BA8: nop
    
            goto L_800F5BC8;
    }
    // 0x800F5BA8: nop

    // 0x800F5BAC: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x800F5BB0: nop

    // 0x800F5BB4: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F5BB8: c.lt.s      $f16, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f16.fl < ctx->f2.fl;
    // 0x800F5BBC: nop

    // 0x800F5BC0: bc1fl       L_800F5C14
    if (!c1cs) {
        // 0x800F5BC4: lw          $t7, 0x68($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X68);
            goto L_800F5C14;
    }
    goto skip_4;
    // 0x800F5BC4: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    skip_4:
L_800F5BC8:
    // 0x800F5BC8: b           L_800F5E88
    // 0x800F5BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5E88;
    // 0x800F5BCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5BD0: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
L_800F5BD4:
    // 0x800F5BD4: nop

    // 0x800F5BD8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F5BDC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800F5BE0: nop

    // 0x800F5BE4: bc1t        L_800F5C08
    if (c1cs) {
        // 0x800F5BE8: nop
    
            goto L_800F5C08;
    }
    // 0x800F5BE8: nop

    // 0x800F5BEC: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800F5BF0: nop

    // 0x800F5BF4: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F5BF8: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800F5BFC: nop

    // 0x800F5C00: bc1fl       L_800F5C14
    if (!c1cs) {
        // 0x800F5C04: lw          $t7, 0x68($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X68);
            goto L_800F5C14;
    }
    goto skip_5;
    // 0x800F5C04: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    skip_5:
L_800F5C08:
    // 0x800F5C08: b           L_800F5E88
    // 0x800F5C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5E88;
    // 0x800F5C0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5C10: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
L_800F5C14:
    // 0x800F5C14: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800F5C18: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800F5C1C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800F5C20: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F5C24: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800F5C28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5C2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5C30: cvt.s.w     $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    ctx->f14.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F5C34: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800F5C38: swc1        $f16, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f16.u32l;
    // 0x800F5C3C: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F5C40: swc1        $f14, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f14.u32l;
    // 0x800F5C44: sub.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800F5C48: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F5C4C: lwc1        $f8, 0x84($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800F5C50: div.s       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800F5C54: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800F5C58: swc1        $f12, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f12.u32l;
    // 0x800F5C5C: mul.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800F5C60: add.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f10.fl;
    // 0x800F5C64: lwc1        $f10, 0x7E8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7E8);
    // 0x800F5C68: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800F5C6C: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F5C70: c.le.s      $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f10.fl <= ctx->f6.fl;
    // 0x800F5C74: nop

    // 0x800F5C78: bc1f        L_800F5E88
    if (!c1cs) {
        // 0x800F5C7C: nop
    
            goto L_800F5E88;
    }
    // 0x800F5C7C: nop

    // 0x800F5C80: sub.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800F5C84: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F5C88: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5C8C: swc1        $f18, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f18.u32l;
    // 0x800F5C90: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800F5C94: lwc1        $f4, 0x10($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F5C98: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F5C9C: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800F5CA0: lwc1        $f10, 0x7EC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7EC);
    // 0x800F5CA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5CA8: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800F5CAC: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F5CB0: sub.s       $f14, $f6, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f12.fl;
    // 0x800F5CB4: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800F5CB8: c.lt.s      $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f10.fl < ctx->f14.fl;
    // 0x800F5CBC: nop

    // 0x800F5CC0: bc1fl       L_800F5D14
    if (!c1cs) {
        // 0x800F5CC4: sub.s       $f0, $f8, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
            goto L_800F5D14;
    }
    goto skip_6;
    // 0x800F5CC4: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
    skip_6:
    // 0x800F5CC8: lwc1        $f4, 0x7F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7F0);
    // 0x800F5CCC: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800F5CD0: nop

    // 0x800F5CD4: bc1f        L_800F5E88
    if (!c1cs) {
        // 0x800F5CD8: nop
    
            goto L_800F5E88;
    }
    // 0x800F5CD8: nop

    // 0x800F5CDC: c.le.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl <= ctx->f0.fl;
    // 0x800F5CE0: nop

    // 0x800F5CE4: bc1f        L_800F5E88
    if (!c1cs) {
        // 0x800F5CE8: nop
    
            goto L_800F5E88;
    }
    // 0x800F5CE8: nop

    // 0x800F5CEC: c.le.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl <= ctx->f16.fl;
    // 0x800F5CF0: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x800F5CF4: bc1f        L_800F5E88
    if (!c1cs) {
        // 0x800F5CF8: nop
    
            goto L_800F5E88;
    }
    // 0x800F5CF8: nop

    // 0x800F5CFC: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800F5D00: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x800F5D04: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5D08: b           L_800F5E88
    // 0x800F5D0C: swc1        $f12, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f12.u32l;
        goto L_800F5E88;
    // 0x800F5D0C: swc1        $f12, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f12.u32l;
    // 0x800F5D10: sub.s       $f0, $f8, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f6.fl;
L_800F5D14:
    // 0x800F5D14: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F5D18: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800F5D1C: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800F5D20: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800F5D24: sub.s       $f2, $f10, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800F5D28: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F5D2C: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800F5D30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F5D34: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x800F5D38: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800F5D3C: sub.s       $f18, $f6, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800F5D40: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F5D44: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800F5D48: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F5D4C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800F5D50: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800F5D54: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800F5D58: div.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800F5D5C: swc1        $f6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f6.u32l;
    // 0x800F5D60: c.lt.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl < ctx->f8.fl;
    // 0x800F5D64: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
    // 0x800F5D68: bc1fl       L_800F5DA4
    if (!c1cs) {
        // 0x800F5D6C: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_800F5DA4;
    }
    goto skip_7;
    // 0x800F5D6C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_7:
    // 0x800F5D70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5D74: lwc1        $f4, 0x7F4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X7F4);
    // 0x800F5D78: mov.s       $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = ctx->f6.fl;
    // 0x800F5D7C: c.lt.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl < ctx->f4.fl;
    // 0x800F5D80: nop

    // 0x800F5D84: bc1fl       L_800F5D98
    if (!c1cs) {
        // 0x800F5D88: mtc1        $zero, $f18
        ctx->f18.u32l = 0;
            goto L_800F5D98;
    }
    goto skip_8;
    // 0x800F5D88: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    skip_8:
    // 0x800F5D8C: b           L_800F5E88
    // 0x800F5D90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5E88;
    // 0x800F5D90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5D94: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
L_800F5D98:
    // 0x800F5D98: b           L_800F5DE0
    // 0x800F5D9C: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
        goto L_800F5DE0;
    // 0x800F5D9C: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F5DA0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_800F5DA4:
    // 0x800F5DA4: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800F5DA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5DAC: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800F5DB0: nop

    // 0x800F5DB4: bc1fl       L_800F5DE0
    if (!c1cs) {
        // 0x800F5DB8: lwc1        $f6, 0x4($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
            goto L_800F5DE0;
    }
    goto skip_9;
    // 0x800F5DB8: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    skip_9:
    // 0x800F5DBC: lwc1        $f8, 0x7F8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X7F8);
    // 0x800F5DC0: c.lt.s      $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f8.fl < ctx->f16.fl;
    // 0x800F5DC4: nop

    // 0x800F5DC8: bc1fl       L_800F5DDC
    if (!c1cs) {
        // 0x800F5DCC: mov.s       $f18, $f0
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
            goto L_800F5DDC;
    }
    goto skip_10;
    // 0x800F5DCC: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
    skip_10:
    // 0x800F5DD0: b           L_800F5E88
    // 0x800F5DD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5E88;
    // 0x800F5DD4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5DD8: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_800F5DDC:
    // 0x800F5DDC: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
L_800F5DE0:
    // 0x800F5DE0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800F5DE4: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F5DE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5DEC: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800F5DF0: lwc1        $f6, 0x38($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800F5DF4: mul.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800F5DF8: lwc1        $f6, 0x7FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X7FC);
    // 0x800F5DFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F5E00: sub.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800F5E04: div.s       $f2, $f8, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F5E08: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800F5E0C: nop

    // 0x800F5E10: bc1t        L_800F5E30
    if (c1cs) {
        // 0x800F5E14: nop
    
            goto L_800F5E30;
    }
    // 0x800F5E14: nop

    // 0x800F5E18: lwc1        $f10, 0x800($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X800);
    // 0x800F5E1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F5E20: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x800F5E24: nop

    // 0x800F5E28: bc1fl       L_800F5E3C
    if (!c1cs) {
        // 0x800F5E2C: mtc1        $at, $f4
        ctx->f4.u32l = ctx->r1;
            goto L_800F5E3C;
    }
    goto skip_11;
    // 0x800F5E2C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    skip_11:
L_800F5E30:
    // 0x800F5E30: b           L_800F5E88
    // 0x800F5E34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F5E88;
    // 0x800F5E34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F5E38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
L_800F5E3C:
    // 0x800F5E3C: lwc1        $f6, 0x4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4);
    // 0x800F5E40: lwc1        $f8, 0xC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800F5E44: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F5E48: lw          $t0, 0x88($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X88);
    // 0x800F5E4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800F5E50: mul.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x800F5E54: nop

    // 0x800F5E58: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800F5E5C: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800F5E60: swc1        $f6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f6.u32l;
    // 0x800F5E64: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800F5E68: lwc1        $f10, 0x10($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X10);
    // 0x800F5E6C: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800F5E70: mul.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800F5E74: nop

    // 0x800F5E78: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800F5E7C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800F5E80: b           L_800F5E88
    // 0x800F5E84: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
        goto L_800F5E88;
    // 0x800F5E84: swc1        $f8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f8.u32l;
L_800F5E88:
    // 0x800F5E88: jr          $ra
    // 0x800F5E8C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800F5E8C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void itFFlowerWeaponFlameProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175E84: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80175E88: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80175E8C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80175E90: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80175E94: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80175E98: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80175E9C: lw          $t7, 0x8($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X8);
    // 0x80175EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80175EA4: lw          $a1, 0x84($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X84);
    // 0x80175EA8: jal         0x801680EC
    // 0x80175EAC: sw          $t8, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r24;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x80175EAC: sw          $t8, 0x268($s0)
    MEM_W(0X268, ctx->r16) = ctx->r24;
    after_0:
    // 0x80175EB0: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x80175EB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80175EB8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80175EBC: lw          $v0, 0x74($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X74);
    // 0x80175EC0: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x80175EC4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80175EC8: lw          $a3, 0x20($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X20);
    // 0x80175ECC: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x80175ED0: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80175ED4: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80175ED8: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x80175EDC: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x80175EE0: swc1        $f4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f4.u32l;
    // 0x80175EE4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80175EE8: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80175EEC: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80175EF0: jal         0x800CE8C0
    // 0x80175EF4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_1;
    // 0x80175EF4: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x80175EF8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80175EFC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80175F00: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x80175F04: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x80175F08: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x80175F0C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x80175F10: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80175F14: lw          $a0, -0x2FBC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2FBC);
    // 0x80175F18: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80175F1C: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    // 0x80175F20: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80175F24: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80175F28: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    // 0x80175F2C: jal         0x800CE8C0
    // 0x80175F30: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    lbParticleMakePosVel(rdram, ctx);
        goto after_2;
    // 0x80175F30: swc1        $f10, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f10.u32l;
    after_2:
    // 0x80175F34: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80175F38: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80175F3C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80175F40: jr          $ra
    // 0x80175F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80175F44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void gcDecideDObj3TransformsKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000F364: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000F368: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8000F36C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    // 0x8000F370: addiu       $t6, $a1, -0x12
    ctx->r14 = ADD32(ctx->r5, -0X12);
    // 0x8000F374: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8000F378: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8000F37C: sltiu       $at, $t6, 0xF
    ctx->r1 = ctx->r14 < 0XF ? 1 : 0;
    // 0x8000F380: andi        $a3, $a3, 0xFF
    ctx->r7 = ctx->r7 & 0XFF;
    // 0x8000F384: andi        $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 & 0XFF;
    // 0x8000F388: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000F38C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8000F390: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8000F394: beq         $at, $zero, L_8000F408
    if (ctx->r1 == 0) {
        // 0x8000F398: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000F408;
    }
    // 0x8000F398: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000F39C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8000F3A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000F3A4: addu        $at, $at, $t6
    gpr jr_addend_8000F3AC = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8000F3A8: lw          $t6, -0x2024($at)
    ctx->r14 = ADD32(ctx->r1, -0X2024);
    // 0x8000F3AC: jr          $t6
    // 0x8000F3B0: nop

    switch (jr_addend_8000F3AC >> 2) {
        case 0: goto L_8000F3B4; break;
        case 1: goto L_8000F408; break;
        case 2: goto L_8000F408; break;
        case 3: goto L_8000F408; break;
        case 4: goto L_8000F408; break;
        case 5: goto L_8000F408; break;
        case 6: goto L_8000F408; break;
        case 7: goto L_8000F408; break;
        case 8: goto L_8000F3BC; break;
        case 9: goto L_8000F3C4; break;
        case 10: goto L_8000F3D0; break;
        case 11: goto L_8000F3E0; break;
        case 12: goto L_8000F3E8; break;
        case 13: goto L_8000F3F4; break;
        case 14: goto L_8000F404; break;
        default: switch_error(__func__, 0x8000F3AC, 0x8003DFDC);
    }
    // 0x8000F3B0: nop

L_8000F3B4:
    // 0x8000F3B4: b           L_8000F408
    // 0x8000F3B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8000F408;
    // 0x8000F3B8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8000F3BC:
    // 0x8000F3BC: b           L_8000F408
    // 0x8000F3C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8000F408;
    // 0x8000F3C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000F3C4:
    // 0x8000F3C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000F3C8: b           L_8000F408
    // 0x8000F3CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8000F408;
    // 0x8000F3CC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8000F3D0:
    // 0x8000F3D0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000F3D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8000F3D8: b           L_8000F408
    // 0x8000F3DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8000F408;
    // 0x8000F3DC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8000F3E0:
    // 0x8000F3E0: b           L_8000F408
    // 0x8000F3E4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8000F408;
    // 0x8000F3E4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_8000F3E8:
    // 0x8000F3E8: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8000F3EC: b           L_8000F408
    // 0x8000F3F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8000F408;
    // 0x8000F3F0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8000F3F4:
    // 0x8000F3F4: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8000F3F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000F3FC: b           L_8000F408
    // 0x8000F400: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_8000F408;
    // 0x8000F400: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_8000F404:
    // 0x8000F404: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8000F408:
    // 0x8000F408: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x8000F40C: beq         $a2, $at, L_8000F430
    if (ctx->r6 == ctx->r1) {
        // 0x8000F410: addiu       $a1, $zero, 0x12
        ctx->r5 = ADD32(0, 0X12);
            goto L_8000F430;
    }
    // 0x8000F410: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    // 0x8000F414: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x8000F418: beq         $a2, $at, L_8000F438
    if (ctx->r6 == ctx->r1) {
        // 0x8000F41C: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_8000F438;
    }
    // 0x8000F41C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8000F420: beql        $a2, $at, L_8000F444
    if (ctx->r6 == ctx->r1) {
        // 0x8000F424: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_8000F444;
    }
    goto skip_0;
    // 0x8000F424: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    skip_0:
    // 0x8000F428: b           L_8000F448
    // 0x8000F42C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
        goto L_8000F448;
    // 0x8000F42C: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_8000F430:
    // 0x8000F430: b           L_8000F444
    // 0x8000F434: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8000F444;
    // 0x8000F434: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000F438:
    // 0x8000F438: b           L_8000F444
    // 0x8000F43C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_8000F444;
    // 0x8000F43C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x8000F440: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8000F444:
    // 0x8000F444: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_8000F448:
    // 0x8000F448: bne         $a3, $at, L_8000F454
    if (ctx->r7 != ctx->r1) {
        // 0x8000F44C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000F454;
    }
    // 0x8000F44C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F450: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_8000F454:
    // 0x8000F454: beql        $t0, $zero, L_8000F47C
    if (ctx->r8 == 0) {
        // 0x8000F458: lw          $v0, 0x38($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X38);
            goto L_8000F47C;
    }
    goto skip_1;
    // 0x8000F458: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    skip_1:
    // 0x8000F45C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8000F460: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8000F464: jal         0x80008CC0
    // 0x8000F468: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_0;
    // 0x8000F468: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    after_0:
    // 0x8000F46C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F470: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8000F474: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x8000F478: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_8000F47C:
    // 0x8000F47C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F480: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x8000F484: beq         $t7, $zero, L_8000F4B8
    if (ctx->r15 == 0) {
        // 0x8000F488: andi        $t8, $v0, 0x2000
        ctx->r24 = ctx->r2 & 0X2000;
            goto L_8000F4B8;
    }
    // 0x8000F488: andi        $t8, $v0, 0x2000
    ctx->r24 = ctx->r2 & 0X2000;
    // 0x8000F48C: bne         $v1, $at, L_8000F4A8
    if (ctx->r3 != ctx->r1) {
        // 0x8000F490: addiu       $a1, $zero, 0x2D
        ctx->r5 = ADD32(0, 0X2D);
            goto L_8000F4A8;
    }
    // 0x8000F490: addiu       $a1, $zero, 0x2D
    ctx->r5 = ADD32(0, 0X2D);
    // 0x8000F494: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x8000F498: jal         0x80008CC0
    // 0x8000F49C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8000F49C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8000F4A0: b           L_8000F584
    // 0x8000F4A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F584;
    // 0x8000F4A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F4A8:
    // 0x8000F4A8: jal         0x80008CC0
    // 0x8000F4AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8000F4AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8000F4B0: b           L_8000F584
    // 0x8000F4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F584;
    // 0x8000F4B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F4B8:
    // 0x8000F4B8: beq         $t8, $zero, L_8000F4F0
    if (ctx->r24 == 0) {
        // 0x8000F4BC: andi        $t9, $v0, 0x1000
        ctx->r25 = ctx->r2 & 0X1000;
            goto L_8000F4F0;
    }
    // 0x8000F4BC: andi        $t9, $v0, 0x1000
    ctx->r25 = ctx->r2 & 0X1000;
    // 0x8000F4C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F4C4: bne         $v1, $at, L_8000F4E0
    if (ctx->r3 != ctx->r1) {
        // 0x8000F4C8: addiu       $a1, $zero, 0x2F
        ctx->r5 = ADD32(0, 0X2F);
            goto L_8000F4E0;
    }
    // 0x8000F4C8: addiu       $a1, $zero, 0x2F
    ctx->r5 = ADD32(0, 0X2F);
    // 0x8000F4CC: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x8000F4D0: jal         0x80008CC0
    // 0x8000F4D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_3;
    // 0x8000F4D4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x8000F4D8: b           L_8000F584
    // 0x8000F4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F584;
    // 0x8000F4DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F4E0:
    // 0x8000F4E0: jal         0x80008CC0
    // 0x8000F4E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x8000F4E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8000F4E8: b           L_8000F584
    // 0x8000F4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F584;
    // 0x8000F4EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F4F0:
    // 0x8000F4F0: beq         $t9, $zero, L_8000F524
    if (ctx->r25 == 0) {
        // 0x8000F4F4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000F524;
    }
    // 0x8000F4F4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F4F8: bne         $v1, $at, L_8000F514
    if (ctx->r3 != ctx->r1) {
        // 0x8000F4FC: addiu       $a1, $zero, 0x31
        ctx->r5 = ADD32(0, 0X31);
            goto L_8000F514;
    }
    // 0x8000F4FC: addiu       $a1, $zero, 0x31
    ctx->r5 = ADD32(0, 0X31);
    // 0x8000F500: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x8000F504: jal         0x80008CC0
    // 0x8000F508: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_5;
    // 0x8000F508: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x8000F50C: b           L_8000F584
    // 0x8000F510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F584;
    // 0x8000F510: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F514:
    // 0x8000F514: jal         0x80008CC0
    // 0x8000F518: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_6;
    // 0x8000F518: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8000F51C: b           L_8000F584
    // 0x8000F520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F584;
    // 0x8000F520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F524:
    // 0x8000F524: beq         $t1, $zero, L_8000F55C
    if (ctx->r9 == 0) {
        // 0x8000F528: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000F55C;
    }
    // 0x8000F528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F52C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000F530: bne         $v1, $at, L_8000F54C
    if (ctx->r3 != ctx->r1) {
        // 0x8000F534: addiu       $a1, $zero, 0x2B
        ctx->r5 = ADD32(0, 0X2B);
            goto L_8000F54C;
    }
    // 0x8000F534: addiu       $a1, $zero, 0x2B
    ctx->r5 = ADD32(0, 0X2B);
    // 0x8000F538: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x8000F53C: jal         0x80008CC0
    // 0x8000F540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_7;
    // 0x8000F540: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8000F544: b           L_8000F584
    // 0x8000F548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F584;
    // 0x8000F548: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F54C:
    // 0x8000F54C: jal         0x80008CC0
    // 0x8000F550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_8;
    // 0x8000F550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8000F554: b           L_8000F584
    // 0x8000F558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F584;
    // 0x8000F558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F55C:
    // 0x8000F55C: bne         $v1, $at, L_8000F578
    if (ctx->r3 != ctx->r1) {
        // 0x8000F560: addiu       $a1, $zero, 0x29
        ctx->r5 = ADD32(0, 0X29);
            goto L_8000F578;
    }
    // 0x8000F560: addiu       $a1, $zero, 0x29
    ctx->r5 = ADD32(0, 0X29);
    // 0x8000F564: addiu       $a1, $zero, 0x2A
    ctx->r5 = ADD32(0, 0X2A);
    // 0x8000F568: jal         0x80008CC0
    // 0x8000F56C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_9;
    // 0x8000F56C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
    // 0x8000F570: b           L_8000F584
    // 0x8000F574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8000F584;
    // 0x8000F574: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F578:
    // 0x8000F578: jal         0x80008CC0
    // 0x8000F57C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_10;
    // 0x8000F57C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_10:
    // 0x8000F580: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000F584:
    // 0x8000F584: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8000F588: jr          $ra
    // 0x8000F58C: nop

    return;
    // 0x8000F58C: nop

;}
RECOMP_FUNC void func_8000EC64_F864(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EC64: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8000EC68: sw          $s3, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r19;
    // 0x8000EC6C: lw          $s3, 0x88($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X88);
    // 0x8000EC70: sdc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X48, ctx->r29);
    // 0x8000EC74: mtc1        $a2, $f28
    ctx->f28.u32l = ctx->r6;
    // 0x8000EC78: sw          $s1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r17;
    // 0x8000EC7C: sw          $s0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r16;
    // 0x8000EC80: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x8000EC84: sw          $s2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r18;
    // 0x8000EC88: sdc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X40, ctx->r29);
    // 0x8000EC8C: sdc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X38, ctx->r29);
    // 0x8000EC90: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8000EC94: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8000EC98: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x8000EC9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000ECA0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000ECA4: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x8000ECA8: lw          $s2, 0x74($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X74);
    // 0x8000ECAC: bne         $s3, $at, L_8000ED9C
    if (ctx->r19 != ctx->r1) {
        // 0x8000ECB0: swc1        $f28, 0x78($a0)
        MEM_W(0X78, ctx->r4) = ctx->f28.u32l;
            goto L_8000ED9C;
    }
    // 0x8000ECB0: swc1        $f28, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f28.u32l;
    // 0x8000ECB4: lwc1        $f20, 0x8C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8000ECB8: lwc1        $f26, 0x9C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8000ECBC: lwc1        $f24, 0x98($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8000ECC0: swc1        $f20, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f20.u32l;
    // 0x8000ECC4: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8000ECC8: beq         $s2, $zero, L_8000ED3C
    if (ctx->r18 == 0) {
        // 0x8000ECCC: lwc1        $f22, 0x94($sp)
        ctx->f22.u32l = MEM_W(ctx->r29, 0X94);
            goto L_8000ED3C;
    }
    // 0x8000ECCC: lwc1        $f22, 0x94($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X94);
L_8000ECD0:
    // 0x8000ECD0: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8000ECD4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000ECD8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000ECDC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8000ECE0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8000ECE4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8000ECE8: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8000ECEC: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x8000ECF0: jal         0x8000E8A8
    // 0x8000ECF4: swc1        $f26, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f26.u32l;
    gcGetDObjTempAnimTimeMax(rdram, ctx);
        goto after_0;
    // 0x8000ECF4: swc1        $f26, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f26.u32l;
    after_0:
    // 0x8000ECF8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8000ECFC: nop

    // 0x8000ED00: bc1f        L_8000ED0C
    if (!c1cs) {
        // 0x8000ED04: nop
    
            goto L_8000ED0C;
    }
    // 0x8000ED04: nop

    // 0x8000ED08: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8000ED0C:
    // 0x8000ED0C: beq         $s0, $zero, L_8000ED18
    if (ctx->r16 == 0) {
        // 0x8000ED10: nop
    
            goto L_8000ED18;
    }
    // 0x8000ED10: nop

    // 0x8000ED14: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000ED18:
    // 0x8000ED18: beq         $s1, $zero, L_8000ED24
    if (ctx->r17 == 0) {
        // 0x8000ED1C: nop
    
            goto L_8000ED24;
    }
    // 0x8000ED1C: nop

    // 0x8000ED20: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
L_8000ED24:
    // 0x8000ED24: jal         0x8000BAA0
    // 0x8000ED28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_1;
    // 0x8000ED28: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8000ED2C: bne         $v0, $zero, L_8000ECD0
    if (ctx->r2 != 0) {
        // 0x8000ED30: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000ECD0;
    }
    // 0x8000ED30: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000ED34: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8000ED38: lw          $s2, 0x74($t7)
    ctx->r18 = MEM_W(ctx->r15, 0X74);
L_8000ED3C:
    // 0x8000ED3C: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000ED40: lwc1        $f0, 0x90($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8000ED44: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x8000ED48: nop

    // 0x8000ED4C: bc1fl       L_8000ED60
    if (!c1cs) {
        // 0x8000ED50: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_8000ED60;
    }
    goto skip_0;
    // 0x8000ED50: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_0:
    // 0x8000ED54: b           L_8000ED70
    // 0x8000ED58: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
        goto L_8000ED70;
    // 0x8000ED58: mov.s       $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = ctx->f4.fl;
    // 0x8000ED5C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_8000ED60:
    // 0x8000ED60: nop

    // 0x8000ED64: bc1f        L_8000ED70
    if (!c1cs) {
        // 0x8000ED68: nop
    
            goto L_8000ED70;
    }
    // 0x8000ED68: nop

    // 0x8000ED6C: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_8000ED70:
    // 0x8000ED70: beq         $s2, $zero, L_8000ED94
    if (ctx->r18 == 0) {
        // 0x8000ED74: nop
    
            goto L_8000ED94;
    }
    // 0x8000ED74: nop

L_8000ED78:
    // 0x8000ED78: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8000ED7C: jal         0x8000E044
    // 0x8000ED80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcSetDObjAnimLength(rdram, ctx);
        goto after_2;
    // 0x8000ED80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x8000ED84: jal         0x8000BAA0
    // 0x8000ED88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_3;
    // 0x8000ED88: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_3:
    // 0x8000ED8C: bne         $v0, $zero, L_8000ED78
    if (ctx->r2 != 0) {
        // 0x8000ED90: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000ED78;
    }
    // 0x8000ED90: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8000ED94:
    // 0x8000ED94: b           L_8000EE00
    // 0x8000ED98: swc1        $f20, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f20.u32l;
        goto L_8000EE00;
    // 0x8000ED98: swc1        $f20, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f20.u32l;
L_8000ED9C:
    // 0x8000ED9C: beq         $s2, $zero, L_8000EE00
    if (ctx->r18 == 0) {
        // 0x8000EDA0: lwc1        $f26, 0x9C($sp)
        ctx->f26.u32l = MEM_W(ctx->r29, 0X9C);
            goto L_8000EE00;
    }
    // 0x8000EDA0: lwc1        $f26, 0x9C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8000EDA4: lwc1        $f24, 0x98($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8000EDA8: lwc1        $f22, 0x94($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8000EDAC: lwc1        $f20, 0x8C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X8C);
L_8000EDB0:
    // 0x8000EDB0: mfc1        $a2, $f28
    ctx->r6 = (int32_t)ctx->f28.u32l;
    // 0x8000EDB4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000EDB8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000EDBC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8000EDC0: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x8000EDC4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8000EDC8: swc1        $f22, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f22.u32l;
    // 0x8000EDCC: swc1        $f24, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f24.u32l;
    // 0x8000EDD0: jal         0x8000E8A8
    // 0x8000EDD4: swc1        $f26, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f26.u32l;
    gcGetDObjTempAnimTimeMax(rdram, ctx);
        goto after_4;
    // 0x8000EDD4: swc1        $f26, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f26.u32l;
    after_4:
    // 0x8000EDD8: beq         $s0, $zero, L_8000EDE4
    if (ctx->r16 == 0) {
        // 0x8000EDDC: nop
    
            goto L_8000EDE4;
    }
    // 0x8000EDDC: nop

    // 0x8000EDE0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000EDE4:
    // 0x8000EDE4: beq         $s1, $zero, L_8000EDF0
    if (ctx->r17 == 0) {
        // 0x8000EDE8: nop
    
            goto L_8000EDF0;
    }
    // 0x8000EDE8: nop

    // 0x8000EDEC: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
L_8000EDF0:
    // 0x8000EDF0: jal         0x8000BAA0
    // 0x8000EDF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcGetTreeDObjNext(rdram, ctx);
        goto after_5;
    // 0x8000EDF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x8000EDF8: bne         $v0, $zero, L_8000EDB0
    if (ctx->r2 != 0) {
        // 0x8000EDFC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000EDB0;
    }
    // 0x8000EDFC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
L_8000EE00:
    // 0x8000EE00: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8000EE04: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8000EE08: lwc1        $f0, 0x8C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8000EE0C: swc1        $f6, 0x78($t8)
    MEM_W(0X78, ctx->r24) = ctx->f6.u32l;
    // 0x8000EE10: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x8000EE14: lw          $s3, 0x60($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X60);
    // 0x8000EE18: lw          $s2, 0x5C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X5C);
    // 0x8000EE1C: lw          $s1, 0x58($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X58);
    // 0x8000EE20: lw          $s0, 0x54($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X54);
    // 0x8000EE24: ldc1        $f28, 0x48($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X48);
    // 0x8000EE28: ldc1        $f26, 0x40($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X40);
    // 0x8000EE2C: ldc1        $f24, 0x38($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X38);
    // 0x8000EE30: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8000EE34: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8000EE38: jr          $ra
    // 0x8000EE3C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8000EE3C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void func_ovl8_8037C92C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C92C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037C930: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037C934: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037C938: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037C93C: beq         $a0, $zero, L_8037C9D0
    if (ctx->r4 == 0) {
        // 0x8037C940: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8037C9D0;
    }
    // 0x8037C940: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037C944: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8037C948: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037C94C: addiu       $t6, $t6, -0x5E30
    ctx->r14 = ADD32(ctx->r14, -0X5E30);
    // 0x8037C950: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037C954: addiu       $t7, $t7, -0x5D50
    ctx->r15 = ADD32(ctx->r15, -0X5D50);
    // 0x8037C958: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8037C95C: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x8037C960: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x8037C964: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037C968: addiu       $t9, $t9, -0x5BF8
    ctx->r25 = ADD32(ctx->r25, -0X5BF8);
    // 0x8037C96C: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037C970: addiu       $t1, $t1, -0x5BD0
    ctx->r9 = ADD32(ctx->r9, -0X5BD0);
    // 0x8037C974: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8037C978: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    // 0x8037C97C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037C980: jal         0x80372554
    // 0x8037C984: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    func_ovl8_80372554(rdram, ctx);
        goto after_0;
    // 0x8037C984: sw          $t1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r9;
    after_0:
    // 0x8037C988: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037C98C: jal         0x80373D88
    // 0x8037C990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_80373D88(rdram, ctx);
        goto after_1;
    // 0x8037C990: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8037C994: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8037C998: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037C99C: beql        $t2, $zero, L_8037C9BC
    if (ctx->r10 == 0) {
        // 0x8037C9A0: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_8037C9BC;
    }
    goto skip_0;
    // 0x8037C9A0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8037C9A4: jal         0x8037C30C
    // 0x8037C9A8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_2;
    // 0x8037C9A8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_2:
    // 0x8037C9AC: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8037C9B0: jal         0x803718C4
    // 0x8037C9B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_3;
    // 0x8037C9B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8037C9B8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_8037C9BC:
    // 0x8037C9BC: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8037C9C0: beql        $t4, $zero, L_8037C9D4
    if (ctx->r12 == 0) {
        // 0x8037C9C4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037C9D4;
    }
    goto skip_1;
    // 0x8037C9C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8037C9C8: jal         0x803717C0
    // 0x8037C9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_4;
    // 0x8037C9CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
L_8037C9D0:
    // 0x8037C9D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037C9D4:
    // 0x8037C9D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037C9D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037C9DC: jr          $ra
    // 0x8037C9E0: nop

    return;
    // 0x8037C9E0: nop

;}
RECOMP_FUNC void mvOpeningSectorMakeMainCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132400: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132404: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x80132408: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8013240C: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x80132410: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80132414: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132418: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8013241C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132420: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132424: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132428: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8013242C: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80132430: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x80132434: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80132438: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8013243C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132440: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132444: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132448: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013244C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132450: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132454: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132458: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013245C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132460: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132464: jal         0x8000B93C
    // 0x80132468: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132468: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013246C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132470: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132474: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80132478: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8013247C: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x80132480: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132484: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132488: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8013248C: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132490: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80132494: jal         0x80007080
    // 0x80132498: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132498: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8013249C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x801324A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801324A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801324A8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x801324AC: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x801324B0: lwc1        $f8, 0x2A00($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2A00);
    // 0x801324B4: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x801324B8: addiu       $t5, $t5, -0x660
    ctx->r13 = ADD32(ctx->r13, -0X660);
    // 0x801324BC: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x801324C0: lw          $t4, 0x2C00($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2C00);
    // 0x801324C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801324C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801324CC: jal         0x8000FA3C
    // 0x801324D0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x801324D0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x801324D4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801324D8: addiu       $a1, $a1, 0x23E0
    ctx->r5 = ADD32(ctx->r5, 0X23E0);
    // 0x801324DC: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x801324E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801324E4: jal         0x80008188
    // 0x801324E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x801324E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x801324EC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x801324F0: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x801324F4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801324F8: jr          $ra
    // 0x801324FC: nop

    return;
    // 0x801324FC: nop

;}
RECOMP_FUNC void ftCommonCatchCheckInterruptGuard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149C60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80149C64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149C68: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80149C6C: lhu         $t6, 0x1BE($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X1BE);
    // 0x80149C70: lhu         $t7, 0x1B4($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X1B4);
    // 0x80149C74: lw          $v0, 0x9C8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X9C8);
    // 0x80149C78: lw          $a1, 0xB3C($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XB3C);
    // 0x80149C7C: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x80149C80: beql        $t8, $zero, L_80149CD0
    if (ctx->r24 == 0) {
        // 0x80149C84: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80149CD0;
    }
    goto skip_0;
    // 0x80149C84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80149C88: lw          $t9, 0x100($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X100);
    // 0x80149C8C: sll         $t1, $t9, 20
    ctx->r9 = S32(ctx->r25 << 20);
    // 0x80149C90: bgezl       $t1, L_80149CD0
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80149C94: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80149CD0;
    }
    goto skip_1;
    // 0x80149C94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80149C98: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80149C9C: jal         0x80149BA8
    // 0x80149CA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftCommonCatchSetStatus(rdram, ctx);
        goto after_0;
    // 0x80149CA0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80149CA4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80149CA8: lw          $t2, 0x1C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1C);
    // 0x80149CAC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80149CB0: lbu         $t5, 0x192($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X192);
    // 0x80149CB4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80149CB8: andi        $t4, $t3, 0x4
    ctx->r12 = ctx->r11 & 0X4;
    // 0x80149CBC: andi        $t6, $t5, 0xFFFB
    ctx->r14 = ctx->r13 & 0XFFFB;
    // 0x80149CC0: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80149CC4: b           L_80149CD0
    // 0x80149CC8: sb          $t7, 0x192($v1)
    MEM_B(0X192, ctx->r3) = ctx->r15;
        goto L_80149CD0;
    // 0x80149CC8: sb          $t7, 0x192($v1)
    MEM_B(0X192, ctx->r3) = ctx->r15;
    // 0x80149CCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80149CD0:
    // 0x80149CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149CD4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80149CD8: jr          $ra
    // 0x80149CDC: nop

    return;
    // 0x80149CDC: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltGroundProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A374: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016A378: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016A37C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016A380: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016A384: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x8016A388: jal         0x800FE068
    // 0x8016A38C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8016A38C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x8016A390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016A394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016A398: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016A39C: jr          $ra
    // 0x8016A3A0: nop

    return;
    // 0x8016A3A0: nop

;}
RECOMP_FUNC void ftCommonEscapeCheckInterruptDash(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801493A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801493A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801493AC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801493B0: addiu       $a1, $zero, 0x9C
    ctx->r5 = ADD32(0, 0X9C);
    // 0x801493B4: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x801493B8: lhu         $t7, 0x1B8($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B8);
    // 0x801493BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801493C0: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x801493C4: beq         $t8, $zero, L_801493DC
    if (ctx->r24 == 0) {
        // 0x801493C8: nop
    
            goto L_801493DC;
    }
    // 0x801493C8: nop

    // 0x801493CC: jal         0x80149294
    // 0x801493D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftCommonEscapeSetStatus(rdram, ctx);
        goto after_0;
    // 0x801493D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801493D4: b           L_801493DC
    // 0x801493D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801493DC;
    // 0x801493D8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801493DC:
    // 0x801493DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801493E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801493E4: jr          $ra
    // 0x801493E8: nop

    return;
    // 0x801493E8: nop

;}
RECOMP_FUNC void mnPlayersVSRandFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138848: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013884C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80138850: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80138854: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
L_80138858:
    // 0x80138858: jal         0x80018A30
    // 0x8013885C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    syUtilsRandTimeUCharRange(rdram, ctx);
        goto after_0;
    // 0x8013885C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_0:
    // 0x80138860: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80138864: jal         0x80131ED8
    // 0x80138868: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayersVSCheckFighterCrossed(rdram, ctx);
        goto after_1;
    // 0x80138868: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8013886C: bne         $v0, $zero, L_80138858
    if (ctx->r2 != 0) {
        // 0x80138870: nop
    
            goto L_80138858;
    }
    // 0x80138870: nop

    // 0x80138874: jal         0x80132044
    // 0x80138878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSCheckFighterLocked(rdram, ctx);
        goto after_2;
    // 0x80138878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013887C: bne         $v0, $zero, L_80138858
    if (ctx->r2 != 0) {
        // 0x80138880: nop
    
            goto L_80138858;
    }
    // 0x80138880: nop

    // 0x80138884: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80138888: jal         0x80138798
    // 0x8013888C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayersVSCenterPuckInPortrait(rdram, ctx);
        goto after_3;
    // 0x8013888C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x80138890: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80138894: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80138898: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013889C: jr          $ra
    // 0x801388A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x801388A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_8037D7D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D7D4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8037D7D8: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037D7DC: addiu       $a2, $a2, -0xFE0
    ctx->r6 = ADD32(ctx->r6, -0XFE0);
    // 0x8037D7E0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8037D7E4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8037D7E8: lhu         $t8, 0x2($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X2);
    // 0x8037D7EC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8037D7F0: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8037D7F4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8037D7F8: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x8037D7FC: lbu         $v1, 0x8($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X8);
    // 0x8037D800: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8037D804: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8037D808: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037D80C: sw          $t6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r14;
    // 0x8037D810: lui         $t6, 0x8038
    ctx->r14 = S32(0X8038 << 16);
    // 0x8037D814: addiu       $t6, $t6, -0x2A54
    ctx->r14 = ADD32(ctx->r14, -0X2A54);
    // 0x8037D818: mflo        $v0
    ctx->r2 = lo;
    // 0x8037D81C: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x8037D820: andi        $t9, $a1, 0x7
    ctx->r25 = ctx->r5 & 0X7;
    // 0x8037D824: beq         $t9, $zero, L_8037D834
    if (ctx->r25 == 0) {
        // 0x8037D828: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8037D834;
    }
    // 0x8037D828: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D82C: b           L_8037D834
    // 0x8037D830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037D834;
    // 0x8037D830: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037D834:
    // 0x8037D834: lhu         $t2, 0x4($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X4);
    // 0x8037D838: bgez        $a1, L_8037D848
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8037D83C: sra         $t0, $a1, 3
        ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8037D848;
    }
    // 0x8037D83C: sra         $t0, $a1, 3
    ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8037D840: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x8037D844: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_8037D848:
    // 0x8037D848: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8037D84C: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037D850: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D854: mflo        $t3
    ctx->r11 = lo;
    // 0x8037D858: sh          $t3, -0xFCE($at)
    MEM_H(-0XFCE, ctx->r1) = ctx->r11;
    // 0x8037D85C: bne         $a0, $v1, L_8037D878
    if (ctx->r4 != ctx->r3) {
        // 0x8037D860: sllv        $t5, $t4, $v1
        ctx->r13 = S32(ctx->r12 << (ctx->r3 & 31));
            goto L_8037D878;
    }
    // 0x8037D860: sllv        $t5, $t4, $v1
    ctx->r13 = S32(ctx->r12 << (ctx->r3 & 31));
    // 0x8037D864: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037D868: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037D86C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D870: b           L_8037D888
    // 0x8037D874: swc1        $f4, -0xFC8($at)
    MEM_W(-0XFC8, ctx->r1) = ctx->f4.u32l;
        goto L_8037D888;
    // 0x8037D874: swc1        $f4, -0xFC8($at)
    MEM_W(-0XFC8, ctx->r1) = ctx->f4.u32l;
L_8037D878:
    // 0x8037D878: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8037D87C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D880: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8037D884: swc1        $f8, -0xFC8($at)
    MEM_W(-0XFC8, ctx->r1) = ctx->f8.u32l;
L_8037D888:
    // 0x8037D888: bne         $a0, $v1, L_8037D89C
    if (ctx->r4 != ctx->r3) {
        // 0x8037D88C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8037D89C;
    }
    // 0x8037D88C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037D890: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D894: jr          $ra
    // 0x8037D898: sw          $t6, -0xFC0($at)
    MEM_W(-0XFC0, ctx->r1) = ctx->r14;
    return;
    // 0x8037D898: sw          $t6, -0xFC0($at)
    MEM_W(-0XFC0, ctx->r1) = ctx->r14;
L_8037D89C:
    // 0x8037D89C: bne         $v1, $at, L_8037D8B8
    if (ctx->r3 != ctx->r1) {
        // 0x8037D8A0: lui         $t8, 0x8038
        ctx->r24 = S32(0X8038 << 16);
            goto L_8037D8B8;
    }
    // 0x8037D8A0: lui         $t8, 0x8038
    ctx->r24 = S32(0X8038 << 16);
    // 0x8037D8A4: lui         $t7, 0x8038
    ctx->r15 = S32(0X8038 << 16);
    // 0x8037D8A8: addiu       $t7, $t7, -0x2AE8
    ctx->r15 = ADD32(ctx->r15, -0X2AE8);
    // 0x8037D8AC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D8B0: jr          $ra
    // 0x8037D8B4: sw          $t7, -0xFC0($at)
    MEM_W(-0XFC0, ctx->r1) = ctx->r15;
    return;
    // 0x8037D8B4: sw          $t7, -0xFC0($at)
    MEM_W(-0XFC0, ctx->r1) = ctx->r15;
L_8037D8B8:
    // 0x8037D8B8: addiu       $t8, $t8, -0x2B90
    ctx->r24 = ADD32(ctx->r24, -0X2B90);
    // 0x8037D8BC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D8C0: sw          $t8, -0xFC0($at)
    MEM_W(-0XFC0, ctx->r1) = ctx->r24;
    // 0x8037D8C4: jr          $ra
    // 0x8037D8C8: nop

    return;
    // 0x8037D8C8: nop

;}
RECOMP_FUNC void ifCommonPlayerStockMultiMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FDD4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8010FDD8: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8010FDDC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8010FDE0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8010FDE4: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8010FDE8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010FDEC: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8010FDF0: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010FDF4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8010FDF8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8010FDFC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8010FE00: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8010FE04: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8010FE08: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8010FE0C: lw          $t0, 0x78($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X78);
    // 0x8010FE10: lw          $v1, 0x84($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X84);
    // 0x8010FE14: lw          $t1, 0x9C8($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X9C8);
    // 0x8010FE18: lw          $v0, 0x340($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X340);
    // 0x8010FE1C: beql        $v0, $zero, L_8010FF10
    if (ctx->r2 == 0) {
        // 0x8010FE20: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8010FF10;
    }
    goto skip_0;
    // 0x8010FE20: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x8010FE24: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8010FE28: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    // 0x8010FE2C: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8010FE30: beq         $t2, $zero, L_8010FF0C
    if (ctx->r10 == 0) {
        // 0x8010FE34: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8010FF0C;
    }
    // 0x8010FE34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010FE38: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8010FE3C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8010FE40: jal         0x80009968
    // 0x8010FE44: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8010FE44: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x8010FE48: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8010FE4C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x8010FE50: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010FE54: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8010FE58: addiu       $a1, $a1, -0x788
    ctx->r5 = ADD32(ctx->r5, -0X788);
    // 0x8010FE5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010FE60: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x8010FE64: jal         0x80009DF4
    // 0x8010FE68: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8010FE68: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x8010FE6C: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8010FE70: addiu       $s2, $s2, 0xD40
    ctx->r18 = ADD32(ctx->r18, 0XD40);
    // 0x8010FE74: lw          $t4, 0x10($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X10);
    // 0x8010FE78: lui         $s1, 0x0
    ctx->r17 = S32(0X0 << 16);
    // 0x8010FE7C: addiu       $s1, $s1, 0x68
    ctx->r17 = ADD32(ctx->r17, 0X68);
    // 0x8010FE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010FE84: jal         0x800CCFDC
    // 0x8010FE88: addu        $a1, $t4, $s1
    ctx->r5 = ADD32(ctx->r12, ctx->r17);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8010FE88: addu        $a1, $t4, $s1
    ctx->r5 = ADD32(ctx->r12, ctx->r17);
    after_2:
    // 0x8010FE8C: lw          $t5, 0x10($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X10);
    // 0x8010FE90: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010FE94: jal         0x800CCFDC
    // 0x8010FE98: addu        $a1, $t5, $s1
    ctx->r5 = ADD32(ctx->r13, ctx->r17);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8010FE98: addu        $a1, $t5, $s1
    ctx->r5 = ADD32(ctx->r13, ctx->r17);
    after_3:
    // 0x8010FE9C: lw          $t7, 0x10($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X10);
    // 0x8010FEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010FEA4: jal         0x800CCFDC
    // 0x8010FEA8: addu        $a1, $t7, $s1
    ctx->r5 = ADD32(ctx->r15, ctx->r17);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x8010FEA8: addu        $a1, $t7, $s1
    ctx->r5 = ADD32(ctx->r15, ctx->r17);
    after_4:
    // 0x8010FEAC: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x8010FEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010FEB4: jal         0x800CCFDC
    // 0x8010FEB8: addu        $a1, $t6, $s1
    ctx->r5 = ADD32(ctx->r14, ctx->r17);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x8010FEB8: addu        $a1, $t6, $s1
    ctx->r5 = ADD32(ctx->r14, ctx->r17);
    after_5:
    // 0x8010FEBC: lw          $t8, 0x10($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X10);
    // 0x8010FEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010FEC4: jal         0x800CCFDC
    // 0x8010FEC8: addu        $a1, $t8, $s1
    ctx->r5 = ADD32(ctx->r24, ctx->r17);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x8010FEC8: addu        $a1, $t8, $s1
    ctx->r5 = ADD32(ctx->r24, ctx->r17);
    after_6:
    // 0x8010FECC: lw          $t9, 0x10($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X10);
    // 0x8010FED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010FED4: jal         0x800CCFDC
    // 0x8010FED8: addu        $a1, $t9, $s1
    ctx->r5 = ADD32(ctx->r25, ctx->r17);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x8010FED8: addu        $a1, $t9, $s1
    ctx->r5 = ADD32(ctx->r25, ctx->r17);
    after_7:
    // 0x8010FEDC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8010FEE0: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8010FEE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010FEE8: addiu       $t0, $zero, 0x7F
    ctx->r8 = ADD32(0, 0X7F);
    // 0x8010FEEC: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8010FEF0: sb          $t0, 0x17CC($at)
    MEM_B(0X17CC, ctx->r1) = ctx->r8;
    // 0x8010FEF4: lw          $t2, 0x9C8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X9C8);
    // 0x8010FEF8: addiu       $t4, $zero, 0x201
    ctx->r12 = ADD32(0, 0X201);
    // 0x8010FEFC: lw          $t3, 0x340($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X340);
    // 0x8010FF00: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8010FF04: sh          $t4, 0x14($v1)
    MEM_H(0X14, ctx->r3) = ctx->r12;
    // 0x8010FF08: sw          $a0, 0x84($s0)
    MEM_W(0X84, ctx->r16) = ctx->r4;
L_8010FF0C:
    // 0x8010FF0C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8010FF10:
    // 0x8010FF10: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8010FF14: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8010FF18: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8010FF1C: jr          $ra
    // 0x8010FF20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8010FF20: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void lbBackupApplyOptions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D46F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D46F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D46FC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D4700: jal         0x80020A34
    // 0x800D4704: lbu         $a0, 0x4931($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4931);
    syAudioSetQuality(rdram, ctx);
        goto after_0;
    // 0x800D4704: lbu         $a0, 0x4931($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X4931);
    after_0:
    // 0x800D4708: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D470C: addiu       $v0, $v0, 0x44E0
    ctx->r2 = ADD32(ctx->r2, 0X44E0);
    // 0x800D4710: lh          $a0, 0x452($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X452);
    // 0x800D4714: lh          $a2, 0x454($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X454);
    // 0x800D4718: sll         $a1, $a0, 16
    ctx->r5 = S32(ctx->r4 << 16);
    // 0x800D471C: sll         $a3, $a2, 16
    ctx->r7 = S32(ctx->r6 << 16);
    // 0x800D4720: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x800D4724: jal         0x80006E94
    // 0x800D4728: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    syVideoSetCenterOffsets(rdram, ctx);
        goto after_1;
    // 0x800D4728: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_1:
    // 0x800D472C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D4730: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D4734: jr          $ra
    // 0x800D4738: nop

    return;
    // 0x800D4738: nop

;}
RECOMP_FUNC void sySchedulerExecuteTasksAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001E64: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80001E68: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80001E6C: lui         $fp, 0x8004
    ctx->r30 = S32(0X8004 << 16);
    // 0x80001E70: addiu       $fp, $fp, 0x4ECC
    ctx->r30 = ADD32(ctx->r30, 0X4ECC);
    // 0x80001E74: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x80001E78: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80001E7C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80001E80: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80001E84: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80001E88: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80001E8C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80001E90: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80001E94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001E98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001E9C: beq         $v0, $zero, L_80001EAC
    if (ctx->r2 == 0) {
        // 0x80001EA0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_80001EAC;
    }
    // 0x80001EA0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80001EA4: b           L_80001EB0
    // 0x80001EA8: lw          $s7, 0x4($v0)
    ctx->r23 = MEM_W(ctx->r2, 0X4);
        goto L_80001EB0;
    // 0x80001EA8: lw          $s7, 0x4($v0)
    ctx->r23 = MEM_W(ctx->r2, 0X4);
L_80001EAC:
    // 0x80001EAC: addiu       $s7, $zero, -0x1
    ctx->r23 = ADD32(0, -0X1);
L_80001EB0:
    // 0x80001EB0: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80001EB4: lw          $v0, 0x4ED0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4ED0);
    // 0x80001EB8: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80001EBC: addiu       $s3, $s3, 0x4ED4
    ctx->r19 = ADD32(ctx->r19, 0X4ED4);
    // 0x80001EC0: beq         $v0, $zero, L_80001ECC
    if (ctx->r2 == 0) {
        // 0x80001EC4: lui         $s0, 0x8004
        ctx->r16 = S32(0X8004 << 16);
            goto L_80001ECC;
    }
    // 0x80001EC4: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80001EC8: lw          $s7, 0x4($v0)
    ctx->r23 = MEM_W(ctx->r2, 0X4);
L_80001ECC:
    // 0x80001ECC: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80001ED0: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x80001ED4: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x80001ED8: beq         $a0, $zero, L_80001EE8
    if (ctx->r4 == 0) {
        // 0x80001EDC: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_80001EE8;
    }
    // 0x80001EDC: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80001EE0: b           L_80001EE8
    // 0x80001EE4: lw          $s4, 0x4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X4);
        goto L_80001EE8;
    // 0x80001EE4: lw          $s4, 0x4($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X4);
L_80001EE8:
    // 0x80001EE8: lw          $s0, 0x4EC4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4EC4);
L_80001EEC:
    // 0x80001EEC: beq         $s0, $zero, L_80001EFC
    if (ctx->r16 == 0) {
        // 0x80001EF0: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_80001EFC;
    }
    // 0x80001EF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x80001EF4: b           L_80001EFC
    // 0x80001EF8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
        goto L_80001EFC;
    // 0x80001EF8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_80001EFC:
    // 0x80001EFC: slt         $at, $s4, $v0
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80001F00: bne         $at, $zero, L_80001F14
    if (ctx->r1 != 0) {
        // 0x80001F04: or          $v1, $s5, $zero
        ctx->r3 = ctx->r21 | 0;
            goto L_80001F14;
    }
    // 0x80001F04: or          $v1, $s5, $zero
    ctx->r3 = ctx->r21 | 0;
    // 0x80001F08: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80001F0C: b           L_80001F18
    // 0x80001F10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_80001F18;
    // 0x80001F10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80001F14:
    // 0x80001F14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80001F18:
    // 0x80001F18: slt         $at, $s7, $a0
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80001F1C: bne         $at, $zero, L_80001F2C
    if (ctx->r1 != 0) {
        // 0x80001F20: nop
    
            goto L_80001F2C;
    }
    // 0x80001F20: nop

    // 0x80001F24: b           L_80001FBC
    // 0x80001F28: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
        goto L_80001FBC;
    // 0x80001F28: or          $s2, $s5, $zero
    ctx->r18 = ctx->r21 | 0;
L_80001F2C:
    // 0x80001F2C: beql        $v1, $zero, L_80001F48
    if (ctx->r3 == 0) {
        // 0x80001F30: lw          $a0, 0x0($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X0);
            goto L_80001F48;
    }
    goto skip_0;
    // 0x80001F30: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x80001F34: beql        $v1, $s5, L_80001F80
    if (ctx->r3 == ctx->r21) {
        // 0x80001F38: lw          $v0, 0x14($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X14);
            goto L_80001F80;
    }
    goto skip_1;
    // 0x80001F38: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
    skip_1:
    // 0x80001F3C: b           L_80001FBC
    // 0x80001F40: nop

        goto L_80001FBC;
    // 0x80001F40: nop

    // 0x80001F44: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
L_80001F48:
    // 0x80001F48: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80001F4C: jal         0x800306CC
    // 0x80001F50: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    osSpTaskLoad_recomp(rdram, ctx);
        goto after_0;
    // 0x80001F50: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_0:
    // 0x80001F54: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80001F58: jal         0x8003085C
    // 0x80001F5C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    osSpTaskStartGo_recomp(rdram, ctx);
        goto after_1;
    // 0x80001F5C: addiu       $a0, $a0, 0x28
    ctx->r4 = ADD32(ctx->r4, 0X28);
    after_1:
    // 0x80001F60: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80001F64: sw          $s6, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r22;
    // 0x80001F68: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x80001F6C: jal         0x80000DD4
    // 0x80001F70: sw          $a0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r4;
    sySchedulerRemovePausedQueue(rdram, ctx);
        goto after_2;
    // 0x80001F70: sw          $a0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r4;
    after_2:
    // 0x80001F74: b           L_80001FBC
    // 0x80001F78: nop

        goto L_80001FBC;
    // 0x80001F78: nop

    // 0x80001F7C: lw          $v0, 0x14($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X14);
L_80001F80:
    // 0x80001F80: beq         $v0, $zero, L_80001F98
    if (ctx->r2 == 0) {
        // 0x80001F84: nop
    
            goto L_80001F98;
    }
    // 0x80001F84: nop

    // 0x80001F88: jalr        $v0
    // 0x80001F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_3;
    // 0x80001F8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80001F90: beql        $v0, $zero, L_80001FBC
    if (ctx->r2 == 0) {
        // 0x80001F94: lw          $s0, 0xC($s0)
        ctx->r16 = MEM_W(ctx->r16, 0XC);
            goto L_80001FBC;
    }
    goto skip_2;
    // 0x80001F94: lw          $s0, 0xC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XC);
    skip_2:
L_80001F98:
    // 0x80001F98: jal         0x80001A00
    // 0x80001F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sySchedulerExecuteTask(rdram, ctx);
        goto after_4;
    // 0x80001F9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80001FA0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80001FA4: lw          $s1, 0xC($s0)
    ctx->r17 = MEM_W(ctx->r16, 0XC);
    // 0x80001FA8: jal         0x80000CF4
    // 0x80001FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sySchedulerRemoveMainQueue(rdram, ctx);
        goto after_5;
    // 0x80001FAC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80001FB0: b           L_80001FBC
    // 0x80001FB4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
        goto L_80001FBC;
    // 0x80001FB4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80001FB8: lw          $s0, 0xC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XC);
L_80001FBC:
    // 0x80001FBC: beq         $s2, $zero, L_80001EEC
    if (ctx->r18 == 0) {
        // 0x80001FC0: nop
    
            goto L_80001EEC;
    }
    // 0x80001FC0: nop

    // 0x80001FC4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80001FC8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001FCC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80001FD0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80001FD4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80001FD8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80001FDC: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80001FE0: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80001FE4: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80001FE8: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80001FEC: jr          $ra
    // 0x80001FF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80001FF0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void wpMainDecLifeCheckExpire(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167FE8: lw          $t6, 0x268($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X268);
    // 0x80167FEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80167FF0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80167FF4: bne         $t7, $zero, L_80168004
    if (ctx->r15 != 0) {
        // 0x80167FF8: sw          $t7, 0x268($a0)
        MEM_W(0X268, ctx->r4) = ctx->r15;
            goto L_80168004;
    }
    // 0x80167FF8: sw          $t7, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r15;
    // 0x80167FFC: jr          $ra
    // 0x80168000: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80168000: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80168004:
    // 0x80168004: jr          $ra
    // 0x80168008: nop

    return;
    // 0x80168008: nop

;}
RECOMP_FUNC void itDisplayOPAProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171C7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80171C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80171C84: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80171C88: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80171C8C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80171C90: jal         0x80171C10
    // 0x80171C94: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    itDisplayCheckItemVisible(rdram, ctx);
        goto after_0;
    // 0x80171C94: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80171C98: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80171C9C: beq         $v0, $zero, L_80171D28
    if (ctx->r2 == 0) {
        // 0x80171CA0: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_80171D28;
    }
    // 0x80171CA0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80171CA4: lw          $v0, 0x374($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X374);
    // 0x80171CA8: beq         $v0, $zero, L_80171CC4
    if (ctx->r2 == 0) {
        // 0x80171CAC: nop
    
            goto L_80171CC4;
    }
    // 0x80171CAC: nop

    // 0x80171CB0: lw          $t6, 0x2CC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2CC);
    // 0x80171CB4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80171CB8: sll         $t8, $t6, 17
    ctx->r24 = S32(ctx->r14 << 17);
    // 0x80171CBC: bgez        $t8, L_80171CD4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80171CC0: nop
    
            goto L_80171CD4;
    }
    // 0x80171CC0: nop

L_80171CC4:
    // 0x80171CC4: jal         0x80014038
    // 0x80171CC8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_1;
    // 0x80171CC8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80171CCC: b           L_80171D2C
    // 0x80171CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80171D2C;
    // 0x80171CD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171CD4:
    // 0x80171CD4: bnel        $v0, $at, L_80171CFC
    if (ctx->r2 != ctx->r1) {
        // 0x80171CD8: lw          $t9, 0x248($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X248);
            goto L_80171CFC;
    }
    goto skip_0;
    // 0x80171CD8: lw          $t9, 0x248($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X248);
    skip_0:
    // 0x80171CDC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80171CE0: jal         0x80014038
    // 0x80171CE4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_2;
    // 0x80171CE4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x80171CE8: jal         0x801719AC
    // 0x80171CEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itDisplayMapCollisions(rdram, ctx);
        goto after_3;
    // 0x80171CEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x80171CF0: b           L_80171D2C
    // 0x80171CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80171D2C;
    // 0x80171CF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80171CF8: lw          $t9, 0x248($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X248);
L_80171CFC:
    // 0x80171CFC: bne         $t9, $zero, L_80171D20
    if (ctx->r25 != 0) {
        // 0x80171D00: nop
    
            goto L_80171D20;
    }
    // 0x80171D00: nop

    // 0x80171D04: lw          $t0, 0x10C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10C);
    // 0x80171D08: bne         $t0, $zero, L_80171D20
    if (ctx->r8 != 0) {
        // 0x80171D0C: nop
    
            goto L_80171D20;
    }
    // 0x80171D0C: nop

    // 0x80171D10: jal         0x80014038
    // 0x80171D14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_4;
    // 0x80171D14: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x80171D18: b           L_80171D2C
    // 0x80171D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80171D2C;
    // 0x80171D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171D20:
    // 0x80171D20: jal         0x80171410
    // 0x80171D24: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayHitCollisions(rdram, ctx);
        goto after_5;
    // 0x80171D24: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
L_80171D28:
    // 0x80171D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80171D2C:
    // 0x80171D2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80171D30: jr          $ra
    // 0x80171D34: nop

    return;
    // 0x80171D34: nop

;}
RECOMP_FUNC void func_ovl60_80132794(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132794: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132798: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8013279C: lw          $t7, 0x37E4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X37E4);
    // 0x801327A0: lw          $t6, 0x37D8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X37D8);
    // 0x801327A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801327A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801327AC: bne         $t6, $t7, L_801327BC
    if (ctx->r14 != ctx->r15) {
        // 0x801327B0: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_801327BC;
    }
    // 0x801327B0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801327B4: jal         0x8013275C
    // 0x801327B8: nop

    func_ovl60_8013275C(rdram, ctx);
        goto after_0;
    // 0x801327B8: nop

    after_0:
L_801327BC:
    // 0x801327BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801327C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801327C4: jr          $ra
    // 0x801327C8: nop

    return;
    // 0x801327C8: nop

;}
RECOMP_FUNC void grPupupuWhispyUpdateBlow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80105D6C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80105D70: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80105D74: lhu         $t6, 0x22($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X22);
    // 0x80105D78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80105D7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80105D80: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80105D84: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80105D88: bne         $t8, $zero, L_80105DC0
    if (ctx->r24 != 0) {
        // 0x80105D8C: sh          $t7, 0x22($v0)
        MEM_H(0X22, ctx->r2) = ctx->r15;
            goto L_80105DC0;
    }
    // 0x80105D8C: sh          $t7, 0x22($v0)
    MEM_H(0X22, ctx->r2) = ctx->r15;
    // 0x80105D90: lw          $v1, 0x18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X18);
    // 0x80105D94: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80105D98: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80105D9C: addiu       $t2, $zero, 0x5
    ctx->r10 = ADD32(0, 0X5);
    // 0x80105DA0: sb          $t9, 0x2E($v0)
    MEM_B(0X2E, ctx->r2) = ctx->r25;
    // 0x80105DA4: sb          $t1, 0x2C($v0)
    MEM_B(0X2C, ctx->r2) = ctx->r9;
    // 0x80105DA8: sb          $t1, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r9;
    // 0x80105DAC: beq         $v1, $zero, L_80105DC0
    if (ctx->r3 == 0) {
        // 0x80105DB0: sb          $t2, 0x26($v0)
        MEM_B(0X26, ctx->r2) = ctx->r10;
            goto L_80105DC0;
    }
    // 0x80105DB0: sb          $t2, 0x26($v0)
    MEM_B(0X26, ctx->r2) = ctx->r10;
    // 0x80105DB4: lhu         $a0, 0xB8($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0XB8);
    // 0x80105DB8: jal         0x800D39D4
    // 0x80105DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    lbParticleEjectStructID(rdram, ctx);
        goto after_0;
    // 0x80105DBC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
L_80105DC0:
    // 0x80105DC0: jal         0x80105D20
    // 0x80105DC4: nop

    grPupupuWhispyUpdateWindRumble(rdram, ctx);
        goto after_1;
    // 0x80105DC4: nop

    after_1:
    // 0x80105DC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105DCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105DD0: jr          $ra
    // 0x80105DD4: nop

    return;
    // 0x80105DD4: nop

;}
RECOMP_FUNC void mnUnusedFightersStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6FB0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800D6FB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6FB8: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D6FBC: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x800D6FC0: addiu       $a0, $a0, 0x7058
    ctx->r4 = ADD32(ctx->r4, 0X7058);
    // 0x800D6FC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6FC8: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x800D6FCC: jal         0x80007024
    // 0x800D6FD0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x800D6FD0: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x800D6FD4: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x800D6FD8: lui         $t9, 0x800D
    ctx->r25 = S32(0X800D << 16);
    // 0x800D6FDC: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D6FE0: addiu       $t9, $t9, 0x7170
    ctx->r25 = ADD32(ctx->r25, 0X7170);
    // 0x800D6FE4: addiu       $t8, $t8, 0x2A00
    ctx->r24 = ADD32(ctx->r24, 0X2A00);
    // 0x800D6FE8: addiu       $a0, $a0, 0x7074
    ctx->r4 = ADD32(ctx->r4, 0X7074);
    // 0x800D6FEC: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x800D6FF0: jal         0x8000683C
    // 0x800D6FF4: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x800D6FF4: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x800D6FF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D6FFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D7000: jr          $ra
    // 0x800D7004: nop

    return;
    // 0x800D7004: nop

;}
RECOMP_FUNC void ftSamusSpecialLwProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E0E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E0EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E0F0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E0F4: jal         0x800DDE84
    // 0x8015E0F8: addiu       $a1, $a1, -0x1E24
    ctx->r5 = ADD32(ctx->r5, -0X1E24);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x8015E0F8: addiu       $a1, $a1, -0x1E24
    ctx->r5 = ADD32(ctx->r5, -0X1E24);
    after_0:
    // 0x8015E0FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E100: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E104: jr          $ra
    // 0x8015E108: nop

    return;
    // 0x8015E108: nop

;}
RECOMP_FUNC void ftBossWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159040: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80159044: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80159048: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015904C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80159050: addiu       $a1, $zero, 0xDD
    ctx->r5 = ADD32(0, 0XDD);
    // 0x80159054: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80159058: jal         0x800E6F24
    // 0x8015905C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015905C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80159060: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80159064: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x80159068: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015906C: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x80159070: lw          $t6, 0xEC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XEC);
    // 0x80159074: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x80159078: beql        $a2, $t6, L_801590A0
    if (ctx->r6 == ctx->r14) {
        // 0x8015907C: lw          $v1, 0xADC($v0)
        ctx->r3 = MEM_W(ctx->r2, 0XADC);
            goto L_801590A0;
    }
    goto skip_0;
    // 0x8015907C: lw          $v1, 0xADC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XADC);
    skip_0:
    // 0x80159080: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80159084: lwc1        $f8, 0xF0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x80159088: swc1        $f4, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f4.u32l;
    // 0x8015908C: lwc1        $f6, 0x4($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80159090: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80159094: b           L_80159140
    // 0x80159098: swc1        $f10, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f10.u32l;
        goto L_80159140;
    // 0x80159098: swc1        $f10, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f10.u32l;
    // 0x8015909C: lw          $v1, 0xADC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XADC);
L_801590A0:
    // 0x801590A0: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x801590A4: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x801590A8: lw          $t8, 0x84($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X84);
    // 0x801590AC: lw          $a0, 0xEC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XEC);
    // 0x801590B0: beql        $a0, $a2, L_801590C4
    if (ctx->r4 == ctx->r6) {
        // 0x801590B4: lw          $a0, 0x8($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X8);
            goto L_801590C4;
    }
    goto skip_1;
    // 0x801590B4: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    skip_1:
    // 0x801590B8: bne         $a0, $at, L_801590C4
    if (ctx->r4 != ctx->r1) {
        // 0x801590BC: nop
    
            goto L_801590C4;
    }
    // 0x801590BC: nop

    // 0x801590C0: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
L_801590C4:
    // 0x801590C4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801590C8: addiu       $v1, $v1, 0x1308
    ctx->r3 = ADD32(ctx->r3, 0X1308);
    // 0x801590CC: lwc1        $f16, 0x28($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X28);
    // 0x801590D0: lwc1        $f0, 0x0($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X0);
    // 0x801590D4: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x801590D8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x801590DC: nop

    // 0x801590E0: bc1fl       L_801590FC
    if (!c1cs) {
        // 0x801590E4: lwc1        $f18, 0x2C($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X2C);
            goto L_801590FC;
    }
    goto skip_2;
    // 0x801590E4: lwc1        $f18, 0x2C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2C);
    skip_2:
    // 0x801590E8: jal         0x800F4408
    // 0x801590EC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_1;
    // 0x801590EC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_1:
    // 0x801590F0: b           L_80159130
    // 0x801590F4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
        goto L_80159130;
    // 0x801590F4: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x801590F8: lwc1        $f18, 0x2C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2C);
L_801590FC:
    // 0x801590FC: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80159100: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80159104: nop

    // 0x80159108: bc1f        L_80159124
    if (!c1cs) {
        // 0x8015910C: nop
    
            goto L_80159124;
    }
    // 0x8015910C: nop

    // 0x80159110: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80159114: jal         0x800F4428
    // 0x80159118: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_2;
    // 0x80159118: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_2:
    // 0x8015911C: b           L_80159130
    // 0x80159120: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
        goto L_80159130;
    // 0x80159120: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_80159124:
    // 0x80159124: jal         0x8015839C
    // 0x80159128: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    ftBossCommonGetPositionCenter(rdram, ctx);
        goto after_3;
    // 0x80159128: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8015912C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
L_80159130:
    // 0x80159130: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80159134: swc1        $f4, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->f4.u32l;
    // 0x80159138: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8015913C: swc1        $f6, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f6.u32l;
L_80159140:
    // 0x80159140: lw          $t9, 0xADC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XADC);
    // 0x80159144: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80159148: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8015914C: lwc1        $f10, 0xC($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0XC);
    // 0x80159150: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80159154: c.eq.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl == ctx->f10.fl;
    // 0x80159158: nop

    // 0x8015915C: bc1fl       L_80159178
    if (!c1cs) {
        // 0x80159160: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_80159178;
    }
    goto skip_3;
    // 0x80159160: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_3:
    // 0x80159164: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80159168: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8015916C: b           L_80159180
    // 0x80159170: lwc1        $f16, 0xB1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB1C);
        goto L_80159180;
    // 0x80159170: lwc1        $f16, 0xB1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x80159174: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_80159178:
    // 0x80159178: nop

    // 0x8015917C: lwc1        $f16, 0xB1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB1C);
L_80159180:
    // 0x80159180: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80159184: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x80159188: swc1        $f4, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->f4.u32l;
    // 0x8015918C: swc1        $f18, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f18.u32l;
    // 0x80159190: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159194: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80159198: jr          $ra
    // 0x8015919C: nop

    return;
    // 0x8015919C: nop

;}
RECOMP_FUNC void itGShellSpinUpdateEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801785E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801785E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801785E8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801785EC: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x801785F0: lbu         $v1, 0x351($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X351);
    // 0x801785F4: bnel        $v1, $zero, L_8017865C
    if (ctx->r3 != 0) {
        // 0x801785F8: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_8017865C;
    }
    goto skip_0;
    // 0x801785F8: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    skip_0:
    // 0x801785FC: lw          $t7, 0x1C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X1C);
    // 0x80178600: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80178604: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80178608: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8017860C: lw          $t6, 0x20($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X20);
    // 0x80178610: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80178614: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80178618: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x8017861C: lw          $t8, 0x2D4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2D4);
    // 0x80178620: lwc1        $f4, 0x20($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80178624: lh          $t9, 0x2E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X2E);
    // 0x80178628: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8017862C: nop

    // 0x80178630: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80178634: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80178638: swc1        $f10, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f10.u32l;
    // 0x8017863C: lw          $a1, 0x24($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X24);
    // 0x80178640: jal         0x800FF048
    // 0x80178644: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    efManagerDustLightMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80178644: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80178648: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8017864C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80178650: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
    // 0x80178654: sb          $t0, 0x351($v0)
    MEM_B(0X351, ctx->r2) = ctx->r8;
    // 0x80178658: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_8017865C:
    // 0x8017865C: sb          $t1, 0x351($v0)
    MEM_B(0X351, ctx->r2) = ctx->r9;
    // 0x80178660: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178664: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80178668: jr          $ra
    // 0x8017866C: nop

    return;
    // 0x8017866C: nop

;}
RECOMP_FUNC void func_ovl8_80376EE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376EE0: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x80376EE4: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x80376EE8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80376EEC: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80376EF0: cvt.d.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.d = CVT_D_W(ctx->f18.u32l);
    // 0x80376EF4: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80376EF8: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80376EFC: bgez        $t6, L_80376F14
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80376F00: cvt.s.w     $f8, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80376F14;
    }
    // 0x80376F00: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80376F04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80376F08: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80376F0C: nop

    // 0x80376F10: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80376F14:
    // 0x80376F14: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x80376F18: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80376F1C: div.d       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = DIV_D(ctx->f16.d, ctx->f2.d);
    // 0x80376F20: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80376F24: trunc.w.d   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_D(ctx->f4.d);
    // 0x80376F28: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80376F2C: nop

    // 0x80376F30: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    // 0x80376F34: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x80376F38: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80376F3C: bgez        $t9, L_80376F50
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80376F40: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80376F50;
    }
    // 0x80376F40: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80376F44: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80376F48: nop

    // 0x80376F4C: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_80376F50:
    // 0x80376F50: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
    // 0x80376F54: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80376F58: div.d       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = DIV_D(ctx->f18.d, ctx->f2.d);
    // 0x80376F5C: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80376F60: trunc.w.d   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_D(ctx->f6.d);
    // 0x80376F64: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x80376F68: nop

    // 0x80376F6C: sb          $t1, 0x1($a1)
    MEM_B(0X1, ctx->r5) = ctx->r9;
    // 0x80376F70: lbu         $t2, 0x2($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X2);
    // 0x80376F74: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x80376F78: bgez        $t2, L_80376F8C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80376F7C: cvt.s.w     $f8, $f16
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80376F8C;
    }
    // 0x80376F7C: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80376F80: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80376F84: nop

    // 0x80376F88: add.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f18.fl;
L_80376F8C:
    // 0x80376F8C: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80376F90: div.d       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f2.d); 
    ctx->f6.d = DIV_D(ctx->f4.d, ctx->f2.d);
    // 0x80376F94: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80376F98: trunc.w.d   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_D(ctx->f10.d);
    // 0x80376F9C: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80376FA0: nop

    // 0x80376FA4: sb          $t4, 0x2($a1)
    MEM_B(0X2, ctx->r5) = ctx->r12;
    // 0x80376FA8: lbu         $t5, 0x3($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X3);
    // 0x80376FAC: jr          $ra
    // 0x80376FB0: sb          $t5, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r13;
    return;
    // 0x80376FB0: sb          $t5, 0x3($a1)
    MEM_B(0X3, ctx->r5) = ctx->r13;
;}
RECOMP_FUNC void sc1PIntroGetFighterAllocsNum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013456C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80134570: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134574: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80134578: addiu       $t6, $t6, 0x5A30
    ctx->r14 = ADD32(ctx->r14, 0X5A30);
    // 0x8013457C: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80134580: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80134584:
    // 0x80134584: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134588: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013458C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80134590: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80134594: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80134598: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8013459C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x801345A0: bne         $t6, $t0, L_80134584
    if (ctx->r14 != ctx->r8) {
        // 0x801345A4: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80134584;
    }
    // 0x801345A4: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x801345A8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x801345AC: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x801345B0: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x801345B4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x801345B8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x801345BC: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x801345C0: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x801345C4: jr          $ra
    // 0x801345C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x801345C8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void efParticleGetLoadBankID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801159F8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801159FC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80115A00: lw          $t6, 0x1A18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1A18);
    // 0x80115A04: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80115A08: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80115A0C: slti        $at, $t6, 0x8
    ctx->r1 = SIGNED(ctx->r14) < 0X8 ? 1 : 0;
    // 0x80115A10: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80115A14: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80115A18: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x80115A1C: bne         $at, $zero, L_80115A44
    if (ctx->r1 != 0) {
        // 0x80115A20: sw          $a3, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r7;
            goto L_80115A44;
    }
    // 0x80115A20: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x80115A24: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80115A28: addiu       $s0, $s0, 0xD10
    ctx->r16 = ADD32(ctx->r16, 0XD10);
L_80115A2C:
    // 0x80115A2C: jal         0x80023624
    // 0x80115A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80115A30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80115A34: jal         0x800A3040
    // 0x80115A38: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x80115A38: nop

    after_1:
    // 0x80115A3C: b           L_80115A2C
    // 0x80115A40: nop

        goto L_80115A2C;
    // 0x80115A40: nop

L_80115A44:
    // 0x80115A44: jal         0x801159B0
    // 0x80115A48: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    efParticleGetBankID(rdram, ctx);
        goto after_2;
    // 0x80115A48: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x80115A4C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80115A50: beq         $v0, $at, L_80115A60
    if (ctx->r2 == ctx->r1) {
        // 0x80115A54: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_80115A60;
    }
    // 0x80115A54: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80115A58: b           L_80115AF8
    // 0x80115A5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80115AF8;
    // 0x80115A5C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80115A60:
    // 0x80115A60: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x80115A64: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80115A68: lw          $s0, 0x1A18($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X1A18);
    // 0x80115A6C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80115A70: subu        $a0, $t7, $t8
    ctx->r4 = SUB32(ctx->r15, ctx->r24);
    // 0x80115A74: jal         0x80004980
    // 0x80115A78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    syTaskmanMalloc(rdram, ctx);
        goto after_3;
    // 0x80115A78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_3:
    // 0x80115A7C: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80115A80: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x80115A84: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80115A88: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80115A8C: subu        $a0, $t9, $t0
    ctx->r4 = SUB32(ctx->r25, ctx->r8);
    // 0x80115A90: jal         0x80004980
    // 0x80115A94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    syTaskmanMalloc(rdram, ctx);
        goto after_4;
    // 0x80115A94: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_4:
    // 0x80115A98: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80115A9C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80115AA0: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80115AA4: jal         0x80002CA0
    // 0x80115AA8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    syDmaReadRom(rdram, ctx);
        goto after_5;
    // 0x80115AA8: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x80115AAC: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80115AB0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80115AB4: jal         0x80002CA0
    // 0x80115AB8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    syDmaReadRom(rdram, ctx);
        goto after_6;
    // 0x80115AB8: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80115ABC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80115AC0: lw          $a0, 0x1A18($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1A18);
    // 0x80115AC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80115AC8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80115ACC: addiu       $t1, $a0, 0x1
    ctx->r9 = ADD32(ctx->r4, 0X1);
    // 0x80115AD0: sw          $t1, 0x1A18($at)
    MEM_W(0X1A18, ctx->r1) = ctx->r9;
    // 0x80115AD4: jal         0x800CE254
    // 0x80115AD8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    lbParticleSetupBankID(rdram, ctx);
        goto after_7;
    // 0x80115AD8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    after_7:
    // 0x80115ADC: lw          $t2, 0x40($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X40);
    // 0x80115AE0: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80115AE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80115AE8: addu        $at, $at, $t3
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x80115AEC: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80115AF0: sw          $t2, 0x1A20($at)
    MEM_W(0X1A20, ctx->r1) = ctx->r10;
    // 0x80115AF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80115AF8:
    // 0x80115AF8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80115AFC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80115B00: jr          $ra
    // 0x80115B04: nop

    return;
    // 0x80115B04: nop

;}
RECOMP_FUNC void gcParseCObjCamAnimJoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FA74: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8000FA78: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8000FA7C: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8000FA80: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8000FA84: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8000FA88: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8000FA8C: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8000FA90: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8000FA94: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8000FA98: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8000FA9C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8000FAA0: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8000FAA4: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000FAA8: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000FAAC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000FAB0: lwc1        $f4, -0x1FE4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X1FE4);
    // 0x8000FAB4: lwc1        $f2, 0x74($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X74);
    // 0x8000FAB8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000FABC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000FAC0: c.eq.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl == ctx->f2.fl;
    // 0x8000FAC4: addiu       $s0, $sp, 0x88
    ctx->r16 = ADD32(ctx->r29, 0X88);
    // 0x8000FAC8: addiu       $v0, $sp, 0xA8
    ctx->r2 = ADD32(ctx->r29, 0XA8);
    // 0x8000FACC: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x8000FAD0: bc1t        L_80010308
    if (c1cs) {
        // 0x8000FAD4: addiu       $fp, $zero, 0x1
        ctx->r30 = ADD32(0, 0X1);
            goto L_80010308;
    }
    // 0x8000FAD4: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8000FAD8: lwc1        $f6, -0x1FE0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1FE0);
    // 0x8000FADC: addiu       $s5, $sp, 0x80
    ctx->r21 = ADD32(ctx->r29, 0X80);
    // 0x8000FAE0: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x8000FAE4: c.eq.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl == ctx->f2.fl;
    // 0x8000FAE8: nop

    // 0x8000FAEC: bc1fl       L_8000FB0C
    if (!c1cs) {
        // 0x8000FAF0: lwc1        $f0, 0x78($s3)
        ctx->f0.u32l = MEM_W(ctx->r19, 0X78);
            goto L_8000FB0C;
    }
    goto skip_0;
    // 0x8000FAF0: lwc1        $f0, 0x78($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X78);
    skip_0:
    // 0x8000FAF4: lwc1        $f8, 0x7C($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x8000FAF8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000FAFC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8000FB00: b           L_8000FB44
    // 0x8000FB04: swc1        $f10, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f10.u32l;
        goto L_8000FB44;
    // 0x8000FB04: swc1        $f10, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->f10.u32l;
    // 0x8000FB08: lwc1        $f0, 0x78($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X78);
L_8000FB0C:
    // 0x8000FB0C: lwc1        $f18, 0x7C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X7C);
    // 0x8000FB10: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x8000FB14: sub.s       $f16, $f2, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x8000FB18: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000FB1C: add.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x8000FB20: swc1        $f16, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f16.u32l;
    // 0x8000FB24: swc1        $f4, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f4.u32l;
    // 0x8000FB28: lwc1        $f6, 0x7C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X7C);
    // 0x8000FB2C: swc1        $f6, 0x78($t6)
    MEM_W(0X78, ctx->r14) = ctx->f6.u32l;
    // 0x8000FB30: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000FB34: c.lt.s      $f22, $f8
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f22.fl < ctx->f8.fl;
    // 0x8000FB38: nop

    // 0x8000FB3C: bc1tl       L_8001030C
    if (c1cs) {
        // 0x8000FB40: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8001030C;
    }
    goto skip_1;
    // 0x8000FB40: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_1:
L_8000FB44:
    // 0x8000FB44: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x8000FB48: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
L_8000FB4C:
    // 0x8000FB4C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8000FB50: sw          $zero, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = 0;
    // 0x8000FB54: sw          $zero, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = 0;
    // 0x8000FB58: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x8000FB5C: bne         $s0, $v0, L_8000FB4C
    if (ctx->r16 != ctx->r2) {
        // 0x8000FB60: sw          $zero, -0x10($s0)
        MEM_W(-0X10, ctx->r16) = 0;
            goto L_8000FB4C;
    }
    // 0x8000FB60: sw          $zero, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = 0;
    // 0x8000FB64: lw          $v0, 0x6C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6C);
    // 0x8000FB68: beql        $v0, $zero, L_8000FBA0
    if (ctx->r2 == 0) {
        // 0x8000FB6C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000FBA0;
    }
    goto skip_2;
    // 0x8000FB6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_2:
    // 0x8000FB70: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
L_8000FB74:
    // 0x8000FB74: slti        $at, $v1, 0x19
    ctx->r1 = SIGNED(ctx->r3) < 0X19 ? 1 : 0;
    // 0x8000FB78: bne         $at, $zero, L_8000FB90
    if (ctx->r1 != 0) {
        // 0x8000FB7C: slti        $at, $v1, 0x23
        ctx->r1 = SIGNED(ctx->r3) < 0X23 ? 1 : 0;
            goto L_8000FB90;
    }
    // 0x8000FB7C: slti        $at, $v1, 0x23
    ctx->r1 = SIGNED(ctx->r3) < 0X23 ? 1 : 0;
    // 0x8000FB80: beq         $at, $zero, L_8000FB90
    if (ctx->r1 == 0) {
        // 0x8000FB84: sll         $t7, $v1, 2
        ctx->r15 = S32(ctx->r3 << 2);
            goto L_8000FB90;
    }
    // 0x8000FB84: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8000FB88: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8000FB8C: sw          $v0, -0x64($t8)
    MEM_W(-0X64, ctx->r24) = ctx->r2;
L_8000FB90:
    // 0x8000FB90: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000FB94: bnel        $v0, $zero, L_8000FB74
    if (ctx->r2 != 0) {
        // 0x8000FB98: lbu         $v1, 0x4($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X4);
            goto L_8000FB74;
    }
    goto skip_3;
    // 0x8000FB98: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    skip_3:
    // 0x8000FB9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8000FBA0:
    // 0x8000FBA0: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8000FBA4: addiu       $s5, $sp, 0x80
    ctx->r21 = ADD32(ctx->r29, 0X80);
    // 0x8000FBA8: lw          $v1, 0x70($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X70);
L_8000FBAC:
    // 0x8000FBAC: bnel        $v1, $zero, L_8000FC0C
    if (ctx->r3 != 0) {
        // 0x8000FBB0: lw          $v0, 0x0($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X0);
            goto L_8000FC0C;
    }
    goto skip_4;
    // 0x8000FBB0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    skip_4:
    // 0x8000FBB4: lw          $v0, 0x6C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6C);
    // 0x8000FBB8: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000FBBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000FBC0: beql        $v0, $zero, L_8000FBFC
    if (ctx->r2 == 0) {
        // 0x8000FBC4: swc1        $f2, 0x7C($s3)
        MEM_W(0X7C, ctx->r19) = ctx->f2.u32l;
            goto L_8000FBFC;
    }
    goto skip_5;
    // 0x8000FBC4: swc1        $f2, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f2.u32l;
    skip_5:
    // 0x8000FBC8: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
L_8000FBCC:
    // 0x8000FBCC: beql        $t9, $zero, L_8000FBF0
    if (ctx->r25 == 0) {
        // 0x8000FBD0: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_8000FBF0;
    }
    goto skip_6;
    // 0x8000FBD0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_6:
    // 0x8000FBD4: lwc1        $f16, 0x78($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8000FBD8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000FBDC: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8000FBE0: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8000FBE4: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8000FBE8: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000FBEC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8000FBF0:
    // 0x8000FBF0: bnel        $v0, $zero, L_8000FBCC
    if (ctx->r2 != 0) {
        // 0x8000FBF4: lbu         $t9, 0x5($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X5);
            goto L_8000FBCC;
    }
    goto skip_7;
    // 0x8000FBF4: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
    skip_7:
    // 0x8000FBF8: swc1        $f2, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f2.u32l;
L_8000FBFC:
    // 0x8000FBFC: lwc1        $f6, -0x1FDC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1FDC);
    // 0x8000FC00: b           L_80010308
    // 0x8000FC04: swc1        $f6, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f6.u32l;
        goto L_80010308;
    // 0x8000FC04: swc1        $f6, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f6.u32l;
    // 0x8000FC08: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
L_8000FC0C:
    // 0x8000FC0C: srl         $a0, $v0, 25
    ctx->r4 = S32(U32(ctx->r2) >> 25);
    // 0x8000FC10: sltiu       $at, $a0, 0x18
    ctx->r1 = ctx->r4 < 0X18 ? 1 : 0;
    // 0x8000FC14: beq         $at, $zero, L_800102F4
    if (ctx->r1 == 0) {
        // 0x8000FC18: or          $s7, $a0, $zero
        ctx->r23 = ctx->r4 | 0;
            goto L_800102F4;
    }
    // 0x8000FC18: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x8000FC1C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x8000FC20: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000FC24: addu        $at, $at, $t0
    gpr jr_addend_8000FC2C = ctx->r8;
    ctx->r1 = ADD32(ctx->r1, ctx->r8);
    // 0x8000FC28: lw          $t0, -0x1FD8($at)
    ctx->r8 = ADD32(ctx->r1, -0X1FD8);
    // 0x8000FC2C: jr          $t0
    // 0x8000FC30: nop

    switch (jr_addend_8000FC2C >> 2) {
        case 0: goto L_8001025C; break;
        case 1: goto L_80010124; break;
        case 2: goto L_8000FFD0; break;
        case 3: goto L_8000FD38; break;
        case 4: goto L_8000FD38; break;
        case 5: goto L_8000FE40; break;
        case 6: goto L_8000FE40; break;
        case 7: goto L_8000FF58; break;
        case 8: goto L_8000FC34; break;
        case 9: goto L_8000FC34; break;
        case 10: goto L_8001000C; break;
        case 11: goto L_8001000C; break;
        case 12: goto L_8001013C; break;
        case 13: goto L_800101C8; break;
        case 14: goto L_800100F8; break;
        case 15: goto L_800102F4; break;
        case 16: goto L_800102F4; break;
        case 17: goto L_800102F4; break;
        case 18: goto L_800102F4; break;
        case 19: goto L_800102F4; break;
        case 20: goto L_800102F4; break;
        case 21: goto L_800102F4; break;
        case 22: goto L_800102F4; break;
        case 23: goto L_800102B0; break;
        default: switch_error(__func__, 0x8000FC2C, 0x8003E028);
    }
    // 0x8000FC30: nop

L_8000FC34:
    // 0x8000FC34: andi        $t1, $v0, 0x7FFF
    ctx->r9 = ctx->r2 & 0X7FFF;
    // 0x8000FC38: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8000FC3C: sll         $s2, $v0, 7
    ctx->r18 = S32(ctx->r2 << 7);
    // 0x8000FC40: bgez        $t1, L_8000FC58
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8000FC44: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000FC58;
    }
    // 0x8000FC44: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000FC48: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000FC4C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000FC50: nop

    // 0x8000FC54: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
L_8000FC58:
    // 0x8000FC58: addiu       $t2, $v1, 0x4
    ctx->r10 = ADD32(ctx->r3, 0X4);
    // 0x8000FC5C: sw          $t2, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r10;
    // 0x8000FC60: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000FC64: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000FC68:
    // 0x8000FC68: beq         $s2, $zero, L_8000FD18
    if (ctx->r18 == 0) {
        // 0x8000FC6C: andi        $t3, $s2, 0x1
        ctx->r11 = ctx->r18 & 0X1;
            goto L_8000FD18;
    }
    // 0x8000FC6C: andi        $t3, $s2, 0x1
    ctx->r11 = ctx->r18 & 0X1;
    // 0x8000FC70: beq         $t3, $zero, L_8000FD0C
    if (ctx->r11 == 0) {
        // 0x8000FC74: sll         $t4, $s1, 2
        ctx->r12 = S32(ctx->r17 << 2);
            goto L_8000FD0C;
    }
    // 0x8000FC74: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8000FC78: addu        $s0, $s5, $t4
    ctx->r16 = ADD32(ctx->r21, ctx->r12);
    // 0x8000FC7C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000FC80: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000FC84: addiu       $a1, $s1, 0x19
    ctx->r5 = ADD32(ctx->r17, 0X19);
    // 0x8000FC88: bnel        $v1, $zero, L_8000FCA4
    if (ctx->r3 != 0) {
        // 0x8000FC8C: lwc1        $f10, 0x14($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000FCA4;
    }
    goto skip_8;
    // 0x8000FC8C: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    skip_8:
    // 0x8000FC90: jal         0x80009010
    // 0x8000FC94: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForCamera(rdram, ctx);
        goto after_0;
    // 0x8000FC94: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x8000FC98: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000FC9C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000FCA0: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
L_8000FCA4:
    // 0x8000FCA4: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000FCA8: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x8000FCAC: lw          $t5, 0x70($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X70);
    // 0x8000FCB0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8000FCB4: lwc1        $f18, 0x0($t5)
    ctx->f18.u32l = MEM_W(ctx->r13, 0X0);
    // 0x8000FCB8: swc1        $f18, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->f18.u32l;
    // 0x8000FCBC: lw          $t7, 0x70($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X70);
    // 0x8000FCC0: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x8000FCC4: sw          $t8, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r24;
    // 0x8000FCC8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000FCCC: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8000FCD0: swc1        $f4, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f4.u32l;
    // 0x8000FCD4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000FCD8: swc1        $f22, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f22.u32l;
    // 0x8000FCDC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8000FCE0: bc1t        L_8000FCF4
    if (c1cs) {
        // 0x8000FCE4: sb          $s6, 0x5($t0)
        MEM_B(0X5, ctx->r8) = ctx->r22;
            goto L_8000FCF4;
    }
    // 0x8000FCE4: sb          $s6, 0x5($t0)
    MEM_B(0X5, ctx->r8) = ctx->r22;
    // 0x8000FCE8: div.s       $f6, $f24, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8000FCEC: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8000FCF0: swc1        $f6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->f6.u32l;
L_8000FCF4:
    // 0x8000FCF4: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000FCF8: lwc1        $f10, 0x78($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8000FCFC: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000FD00: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8000FD04: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8000FD08: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
L_8000FD0C:
    // 0x8000FD0C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FD10: bne         $s1, $s4, L_8000FC68
    if (ctx->r17 != ctx->r20) {
        // 0x8000FD14: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000FC68;
    }
    // 0x8000FD14: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000FD18:
    // 0x8000FD18: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000FD1C: bne         $s7, $at, L_8000FD30
    if (ctx->r23 != ctx->r1) {
        // 0x8000FD20: nop
    
            goto L_8000FD30;
    }
    // 0x8000FD20: nop

    // 0x8000FD24: lwc1        $f4, 0x74($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000FD28: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8000FD2C: swc1        $f6, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f6.u32l;
L_8000FD30:
    // 0x8000FD30: b           L_800102F8
    // 0x8000FD34: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
        goto L_800102F8;
    // 0x8000FD34: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_8000FD38:
    // 0x8000FD38: andi        $t3, $v0, 0x7FFF
    ctx->r11 = ctx->r2 & 0X7FFF;
    // 0x8000FD3C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8000FD40: sll         $s2, $v0, 7
    ctx->r18 = S32(ctx->r2 << 7);
    // 0x8000FD44: bgez        $t3, L_8000FD5C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000FD48: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000FD5C;
    }
    // 0x8000FD48: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000FD4C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000FD50: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000FD54: nop

    // 0x8000FD58: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
L_8000FD5C:
    // 0x8000FD5C: addiu       $t4, $v1, 0x4
    ctx->r12 = ADD32(ctx->r3, 0X4);
    // 0x8000FD60: sw          $t4, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r12;
    // 0x8000FD64: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000FD68: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000FD6C:
    // 0x8000FD6C: beq         $s2, $zero, L_8000FE20
    if (ctx->r18 == 0) {
        // 0x8000FD70: andi        $t5, $s2, 0x1
        ctx->r13 = ctx->r18 & 0X1;
            goto L_8000FE20;
    }
    // 0x8000FD70: andi        $t5, $s2, 0x1
    ctx->r13 = ctx->r18 & 0X1;
    // 0x8000FD74: beq         $t5, $zero, L_8000FE14
    if (ctx->r13 == 0) {
        // 0x8000FD78: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_8000FE14;
    }
    // 0x8000FD78: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8000FD7C: addu        $s0, $s5, $t6
    ctx->r16 = ADD32(ctx->r21, ctx->r14);
    // 0x8000FD80: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000FD84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000FD88: addiu       $a1, $s1, 0x19
    ctx->r5 = ADD32(ctx->r17, 0X19);
    // 0x8000FD8C: bnel        $v1, $zero, L_8000FDA8
    if (ctx->r3 != 0) {
        // 0x8000FD90: lwc1        $f10, 0x14($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000FDA8;
    }
    goto skip_9;
    // 0x8000FD90: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    skip_9:
    // 0x8000FD94: jal         0x80009010
    // 0x8000FD98: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForCamera(rdram, ctx);
        goto after_1;
    // 0x8000FD98: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_1:
    // 0x8000FD9C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000FDA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000FDA4: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
L_8000FDA8:
    // 0x8000FDA8: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000FDAC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8000FDB0: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x8000FDB4: lw          $t7, 0x70($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X70);
    // 0x8000FDB8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000FDBC: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8000FDC0: swc1        $f18, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f18.u32l;
    // 0x8000FDC4: lw          $t9, 0x70($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X70);
    // 0x8000FDC8: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x8000FDCC: sw          $t0, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r8;
    // 0x8000FDD0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000FDD4: bc1t        L_8000FDF4
    if (c1cs) {
        // 0x8000FDD8: sb          $t1, 0x5($t2)
        MEM_B(0X5, ctx->r10) = ctx->r9;
            goto L_8000FDF4;
    }
    // 0x8000FDD8: sb          $t1, 0x5($t2)
    MEM_B(0X5, ctx->r10) = ctx->r9;
    // 0x8000FDDC: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000FDE0: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8000FDE4: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8000FDE8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000FDEC: div.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8000FDF0: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
L_8000FDF4:
    // 0x8000FDF4: lwc1        $f10, 0x74($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000FDF8: lwc1        $f4, 0x78($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8000FDFC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8000FE00: neg.s       $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = -ctx->f10.fl;
    // 0x8000FE04: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000FE08: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
    // 0x8000FE0C: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000FE10: swc1        $f22, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f22.u32l;
L_8000FE14:
    // 0x8000FE14: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FE18: bne         $s1, $s4, L_8000FD6C
    if (ctx->r17 != ctx->r20) {
        // 0x8000FE1C: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000FD6C;
    }
    // 0x8000FE1C: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000FE20:
    // 0x8000FE20: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000FE24: bne         $s7, $at, L_8000FE38
    if (ctx->r23 != ctx->r1) {
        // 0x8000FE28: nop
    
            goto L_8000FE38;
    }
    // 0x8000FE28: nop

    // 0x8000FE2C: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000FE30: add.s       $f16, $f8, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x8000FE34: swc1        $f16, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f16.u32l;
L_8000FE38:
    // 0x8000FE38: b           L_800102F8
    // 0x8000FE3C: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
        goto L_800102F8;
    // 0x8000FE3C: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_8000FE40:
    // 0x8000FE40: andi        $t5, $v0, 0x7FFF
    ctx->r13 = ctx->r2 & 0X7FFF;
    // 0x8000FE44: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8000FE48: sll         $s2, $v0, 7
    ctx->r18 = S32(ctx->r2 << 7);
    // 0x8000FE4C: bgez        $t5, L_8000FE64
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8000FE50: cvt.s.w     $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8000FE64;
    }
    // 0x8000FE50: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000FE54: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000FE58: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8000FE5C: nop

    // 0x8000FE60: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
L_8000FE64:
    // 0x8000FE64: addiu       $t6, $v1, 0x4
    ctx->r14 = ADD32(ctx->r3, 0X4);
    // 0x8000FE68: sw          $t6, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r14;
    // 0x8000FE6C: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000FE70: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000FE74:
    // 0x8000FE74: beq         $s2, $zero, L_8000FF38
    if (ctx->r18 == 0) {
        // 0x8000FE78: andi        $t7, $s2, 0x1
        ctx->r15 = ctx->r18 & 0X1;
            goto L_8000FF38;
    }
    // 0x8000FE78: andi        $t7, $s2, 0x1
    ctx->r15 = ctx->r18 & 0X1;
    // 0x8000FE7C: beq         $t7, $zero, L_8000FF2C
    if (ctx->r15 == 0) {
        // 0x8000FE80: sll         $t8, $s1, 2
        ctx->r24 = S32(ctx->r17 << 2);
            goto L_8000FF2C;
    }
    // 0x8000FE80: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8000FE84: addu        $s0, $s5, $t8
    ctx->r16 = ADD32(ctx->r21, ctx->r24);
    // 0x8000FE88: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000FE8C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000FE90: addiu       $a1, $s1, 0x19
    ctx->r5 = ADD32(ctx->r17, 0X19);
    // 0x8000FE94: bnel        $v1, $zero, L_8000FEB0
    if (ctx->r3 != 0) {
        // 0x8000FE98: lwc1        $f4, 0x14($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000FEB0;
    }
    goto skip_10;
    // 0x8000FE98: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
    skip_10:
    // 0x8000FE9C: jal         0x80009010
    // 0x8000FEA0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForCamera(rdram, ctx);
        goto after_2;
    // 0x8000FEA0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_2:
    // 0x8000FEA4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000FEA8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000FEAC: lwc1        $f4, 0x14($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X14);
L_8000FEB0:
    // 0x8000FEB0: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000FEB4: swc1        $f4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f4.u32l;
    // 0x8000FEB8: lw          $t9, 0x70($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X70);
    // 0x8000FEBC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8000FEC0: lwc1        $f6, 0x0($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X0);
    // 0x8000FEC4: swc1        $f6, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->f6.u32l;
    // 0x8000FEC8: lw          $t1, 0x70($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X70);
    // 0x8000FECC: addiu       $t2, $t1, 0x4
    ctx->r10 = ADD32(ctx->r9, 0X4);
    // 0x8000FED0: sw          $t2, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r10;
    // 0x8000FED4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000FED8: lwc1        $f8, 0x1C($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8000FEDC: swc1        $f8, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f8.u32l;
    // 0x8000FEE0: lw          $t3, 0x70($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X70);
    // 0x8000FEE4: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000FEE8: lwc1        $f16, 0x0($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8000FEEC: swc1        $f16, 0x1C($t4)
    MEM_W(0X1C, ctx->r12) = ctx->f16.u32l;
    // 0x8000FEF0: lw          $t5, 0x70($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X70);
    // 0x8000FEF4: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x8000FEF8: sw          $t6, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r14;
    // 0x8000FEFC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8000FF00: bc1t        L_8000FF14
    if (c1cs) {
        // 0x8000FF04: sb          $s6, 0x5($t7)
        MEM_B(0X5, ctx->r15) = ctx->r22;
            goto L_8000FF14;
    }
    // 0x8000FF04: sb          $s6, 0x5($t7)
    MEM_B(0X5, ctx->r15) = ctx->r22;
    // 0x8000FF08: div.s       $f10, $f24, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8000FF0C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000FF10: swc1        $f10, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->f10.u32l;
L_8000FF14:
    // 0x8000FF14: lwc1        $f18, 0x74($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000FF18: lwc1        $f6, 0x78($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X78);
    // 0x8000FF1C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000FF20: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8000FF24: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000FF28: swc1        $f8, 0xC($t9)
    MEM_W(0XC, ctx->r25) = ctx->f8.u32l;
L_8000FF2C:
    // 0x8000FF2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FF30: bne         $s1, $s4, L_8000FE74
    if (ctx->r17 != ctx->r20) {
        // 0x8000FF34: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000FE74;
    }
    // 0x8000FF34: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000FF38:
    // 0x8000FF38: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000FF3C: bne         $s7, $at, L_8000FF50
    if (ctx->r23 != ctx->r1) {
        // 0x8000FF40: nop
    
            goto L_8000FF50;
    }
    // 0x8000FF40: nop

    // 0x8000FF44: lwc1        $f16, 0x74($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000FF48: add.s       $f10, $f16, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x8000FF4C: swc1        $f10, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f10.u32l;
L_8000FF50:
    // 0x8000FF50: b           L_800102F8
    // 0x8000FF54: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
        goto L_800102F8;
    // 0x8000FF54: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_8000FF58:
    // 0x8000FF58: sll         $s2, $v0, 7
    ctx->r18 = S32(ctx->r2 << 7);
    // 0x8000FF5C: addiu       $t0, $v1, 0x4
    ctx->r8 = ADD32(ctx->r3, 0X4);
    // 0x8000FF60: sw          $t0, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r8;
    // 0x8000FF64: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000FF68: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000FF6C:
    // 0x8000FF6C: beq         $s2, $zero, L_8000FFC8
    if (ctx->r18 == 0) {
        // 0x8000FF70: andi        $t1, $s2, 0x1
        ctx->r9 = ctx->r18 & 0X1;
            goto L_8000FFC8;
    }
    // 0x8000FF70: andi        $t1, $s2, 0x1
    ctx->r9 = ctx->r18 & 0X1;
    // 0x8000FF74: beq         $t1, $zero, L_8000FFBC
    if (ctx->r9 == 0) {
        // 0x8000FF78: sll         $t2, $s1, 2
        ctx->r10 = S32(ctx->r17 << 2);
            goto L_8000FFBC;
    }
    // 0x8000FF78: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8000FF7C: addu        $s0, $s5, $t2
    ctx->r16 = ADD32(ctx->r21, ctx->r10);
    // 0x8000FF80: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000FF84: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000FF88: addiu       $a1, $s1, 0x19
    ctx->r5 = ADD32(ctx->r17, 0X19);
    // 0x8000FF8C: bnel        $v1, $zero, L_8000FFA8
    if (ctx->r3 != 0) {
        // 0x8000FF90: lw          $t3, 0x70($s3)
        ctx->r11 = MEM_W(ctx->r19, 0X70);
            goto L_8000FFA8;
    }
    goto skip_11;
    // 0x8000FF90: lw          $t3, 0x70($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X70);
    skip_11:
    // 0x8000FF94: jal         0x80009010
    // 0x8000FF98: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForCamera(rdram, ctx);
        goto after_3;
    // 0x8000FF98: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_3:
    // 0x8000FF9C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000FFA0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000FFA4: lw          $t3, 0x70($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X70);
L_8000FFA8:
    // 0x8000FFA8: lwc1        $f18, 0x0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8000FFAC: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x8000FFB0: lw          $t4, 0x70($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X70);
    // 0x8000FFB4: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x8000FFB8: sw          $t5, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r13;
L_8000FFBC:
    // 0x8000FFBC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000FFC0: bne         $s1, $s4, L_8000FF6C
    if (ctx->r17 != ctx->r20) {
        // 0x8000FFC4: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000FF6C;
    }
    // 0x8000FFC4: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000FFC8:
    // 0x8000FFC8: b           L_800102F8
    // 0x8000FFCC: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
        goto L_800102F8;
    // 0x8000FFCC: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_8000FFD0:
    // 0x8000FFD0: andi        $t6, $v0, 0x7FFF
    ctx->r14 = ctx->r2 & 0X7FFF;
    // 0x8000FFD4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8000FFD8: lwc1        $f4, 0x74($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X74);
    // 0x8000FFDC: bgez        $t6, L_8000FFF4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8000FFE0: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000FFF4;
    }
    // 0x8000FFE0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000FFE4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000FFE8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000FFEC: nop

    // 0x8000FFF0: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_8000FFF4:
    // 0x8000FFF4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x8000FFF8: addiu       $t7, $v1, 0x4
    ctx->r15 = ADD32(ctx->r3, 0X4);
    // 0x8000FFFC: sw          $t7, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r15;
    // 0x80010000: swc1        $f10, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f10.u32l;
    // 0x80010004: b           L_800102F8
    // 0x80010008: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
        goto L_800102F8;
    // 0x80010008: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_8001000C:
    // 0x8001000C: andi        $t8, $v0, 0x7FFF
    ctx->r24 = ctx->r2 & 0X7FFF;
    // 0x80010010: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80010014: sll         $s2, $v0, 7
    ctx->r18 = S32(ctx->r2 << 7);
    // 0x80010018: bgez        $t8, L_80010030
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8001001C: cvt.s.w     $f20, $f18
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80010030;
    }
    // 0x8001001C: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80010020: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80010024: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80010028: nop

    // 0x8001002C: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_80010030:
    // 0x80010030: addiu       $t9, $v1, 0x4
    ctx->r25 = ADD32(ctx->r3, 0X4);
    // 0x80010034: sw          $t9, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r25;
    // 0x80010038: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8001003C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80010040:
    // 0x80010040: beq         $s2, $zero, L_800100D8
    if (ctx->r18 == 0) {
        // 0x80010044: andi        $t0, $s2, 0x1
        ctx->r8 = ctx->r18 & 0X1;
            goto L_800100D8;
    }
    // 0x80010044: andi        $t0, $s2, 0x1
    ctx->r8 = ctx->r18 & 0X1;
    // 0x80010048: beq         $t0, $zero, L_800100CC
    if (ctx->r8 == 0) {
        // 0x8001004C: sll         $t1, $s1, 2
        ctx->r9 = S32(ctx->r17 << 2);
            goto L_800100CC;
    }
    // 0x8001004C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80010050: addu        $s0, $s5, $t1
    ctx->r16 = ADD32(ctx->r21, ctx->r9);
    // 0x80010054: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80010058: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001005C: addiu       $a1, $s1, 0x19
    ctx->r5 = ADD32(ctx->r17, 0X19);
    // 0x80010060: bnel        $v1, $zero, L_8001007C
    if (ctx->r3 != 0) {
        // 0x80010064: lwc1        $f16, 0x14($v1)
        ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8001007C;
    }
    goto skip_12;
    // 0x80010064: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    skip_12:
    // 0x80010068: jal         0x80009010
    // 0x8001006C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForCamera(rdram, ctx);
        goto after_4;
    // 0x8001006C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_4:
    // 0x80010070: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80010074: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80010078: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
L_8001007C:
    // 0x8001007C: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x80010080: lw          $t2, 0x70($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X70);
    // 0x80010084: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80010088: lwc1        $f4, 0x0($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X0);
    // 0x8001008C: swc1        $f4, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f4.u32l;
    // 0x80010090: lw          $t4, 0x70($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X70);
    // 0x80010094: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80010098: sw          $t5, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r13;
    // 0x8001009C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800100A0: sb          $fp, 0x5($t6)
    MEM_B(0X5, ctx->r14) = ctx->r30;
    // 0x800100A4: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800100A8: swc1        $f20, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->f20.u32l;
    // 0x800100AC: lwc1        $f8, 0x74($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X74);
    // 0x800100B0: lwc1        $f18, 0x78($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X78);
    // 0x800100B4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800100B8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x800100BC: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800100C0: swc1        $f6, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f6.u32l;
    // 0x800100C4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800100C8: swc1        $f22, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f22.u32l;
L_800100CC:
    // 0x800100CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800100D0: bne         $s1, $s4, L_80010040
    if (ctx->r17 != ctx->r20) {
        // 0x800100D4: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_80010040;
    }
    // 0x800100D4: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_800100D8:
    // 0x800100D8: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800100DC: bne         $s7, $at, L_800100F0
    if (ctx->r23 != ctx->r1) {
        // 0x800100E0: nop
    
            goto L_800100F0;
    }
    // 0x800100E0: nop

    // 0x800100E4: lwc1        $f16, 0x74($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X74);
    // 0x800100E8: add.s       $f4, $f16, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x800100EC: swc1        $f4, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f4.u32l;
L_800100F0:
    // 0x800100F0: b           L_800102F8
    // 0x800100F4: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
        goto L_800102F8;
    // 0x800100F4: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_800100F8:
    // 0x800100F8: lwc1        $f0, 0x74($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X74);
    // 0x800100FC: addiu       $t0, $v1, 0x4
    ctx->r8 = ADD32(ctx->r3, 0X4);
    // 0x80010100: sw          $t0, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r8;
    // 0x80010104: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80010108: lw          $t3, 0x4($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X4);
    // 0x8001010C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80010110: sw          $t2, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r10;
    // 0x80010114: swc1        $f0, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f0.u32l;
    // 0x80010118: swc1        $f0, 0x78($t3)
    MEM_W(0X78, ctx->r11) = ctx->f0.u32l;
    // 0x8001011C: b           L_800102F8
    // 0x80010120: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
        goto L_800102F8;
    // 0x80010120: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_80010124:
    // 0x80010124: addiu       $t4, $v1, 0x4
    ctx->r12 = ADD32(ctx->r3, 0X4);
    // 0x80010128: sw          $t4, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r12;
    // 0x8001012C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80010130: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
    // 0x80010134: b           L_800102F8
    // 0x80010138: sw          $t6, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r14;
        goto L_800102F8;
    // 0x80010138: sw          $t6, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r14;
L_8001013C:
    // 0x8001013C: andi        $t7, $v0, 0x7FFF
    ctx->r15 = ctx->r2 & 0X7FFF;
    // 0x80010140: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80010144: sll         $s2, $v0, 7
    ctx->r18 = S32(ctx->r2 << 7);
    // 0x80010148: bgez        $t7, L_80010160
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8001014C: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80010160;
    }
    // 0x8001014C: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80010150: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80010154: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80010158: nop

    // 0x8001015C: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
L_80010160:
    // 0x80010160: addiu       $t8, $v1, 0x4
    ctx->r24 = ADD32(ctx->r3, 0X4);
    // 0x80010164: sw          $t8, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r24;
    // 0x80010168: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8001016C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80010170:
    // 0x80010170: beq         $s2, $zero, L_800101C0
    if (ctx->r18 == 0) {
        // 0x80010174: andi        $t9, $s2, 0x1
        ctx->r25 = ctx->r18 & 0X1;
            goto L_800101C0;
    }
    // 0x80010174: andi        $t9, $s2, 0x1
    ctx->r25 = ctx->r18 & 0X1;
    // 0x80010178: beq         $t9, $zero, L_800101B4
    if (ctx->r25 == 0) {
        // 0x8001017C: sll         $t0, $s1, 2
        ctx->r8 = S32(ctx->r17 << 2);
            goto L_800101B4;
    }
    // 0x8001017C: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x80010180: addu        $s0, $s5, $t0
    ctx->r16 = ADD32(ctx->r21, ctx->r8);
    // 0x80010184: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80010188: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001018C: addiu       $a1, $s1, 0x19
    ctx->r5 = ADD32(ctx->r17, 0X19);
    // 0x80010190: bnel        $v1, $zero, L_800101AC
    if (ctx->r3 != 0) {
        // 0x80010194: lwc1        $f18, 0xC($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
            goto L_800101AC;
    }
    goto skip_13;
    // 0x80010194: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    skip_13:
    // 0x80010198: jal         0x80009010
    // 0x8001019C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForCamera(rdram, ctx);
        goto after_5;
    // 0x8001019C: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_5:
    // 0x800101A0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800101A4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800101A8: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
L_800101AC:
    // 0x800101AC: add.s       $f6, $f18, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x800101B0: swc1        $f6, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f6.u32l;
L_800101B4:
    // 0x800101B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800101B8: bne         $s1, $s4, L_80010170
    if (ctx->r17 != ctx->r20) {
        // 0x800101BC: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_80010170;
    }
    // 0x800101BC: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_800101C0:
    // 0x800101C0: b           L_800102F8
    // 0x800101C4: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
        goto L_800102F8;
    // 0x800101C4: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_800101C8:
    // 0x800101C8: sll         $s2, $v0, 7
    ctx->r18 = S32(ctx->r2 << 7);
    // 0x800101CC: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x800101D0: addiu       $t1, $v1, 0x4
    ctx->r9 = ADD32(ctx->r3, 0X4);
    // 0x800101D4: andi        $t2, $s2, 0x8
    ctx->r10 = ctx->r18 & 0X8;
    // 0x800101D8: beq         $t2, $zero, L_80010218
    if (ctx->r10 == 0) {
        // 0x800101DC: sw          $t1, 0x70($s3)
        MEM_W(0X70, ctx->r19) = ctx->r9;
            goto L_80010218;
    }
    // 0x800101DC: sw          $t1, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r9;
    // 0x800101E0: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x800101E4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800101E8: bnel        $t3, $zero, L_80010200
    if (ctx->r11 != 0) {
        // 0x800101EC: lw          $t4, 0x70($s3)
        ctx->r12 = MEM_W(ctx->r19, 0X70);
            goto L_80010200;
    }
    goto skip_14;
    // 0x800101EC: lw          $t4, 0x70($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X70);
    skip_14:
    // 0x800101F0: jal         0x80009010
    // 0x800101F4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    gcAddAObjForCamera(rdram, ctx);
        goto after_6;
    // 0x800101F4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    after_6:
    // 0x800101F8: sw          $v0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r2;
    // 0x800101FC: lw          $t4, 0x70($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X70);
L_80010200:
    // 0x80010200: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x80010204: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80010208: sw          $t5, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->r13;
    // 0x8001020C: lw          $t7, 0x70($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X70);
    // 0x80010210: addiu       $t8, $t7, 0x4
    ctx->r24 = ADD32(ctx->r15, 0X4);
    // 0x80010214: sw          $t8, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r24;
L_80010218:
    // 0x80010218: andi        $t9, $s2, 0x80
    ctx->r25 = ctx->r18 & 0X80;
    // 0x8001021C: beq         $t9, $zero, L_80010254
    if (ctx->r25 == 0) {
        // 0x80010220: lw          $t0, 0x9C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X9C);
            goto L_80010254;
    }
    // 0x80010220: lw          $t0, 0x9C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X9C);
    // 0x80010224: bne         $t0, $zero, L_80010238
    if (ctx->r8 != 0) {
        // 0x80010228: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80010238;
    }
    // 0x80010228: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8001022C: jal         0x80009010
    // 0x80010230: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    gcAddAObjForCamera(rdram, ctx);
        goto after_7;
    // 0x80010230: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_7:
    // 0x80010234: sw          $v0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r2;
L_80010238:
    // 0x80010238: lw          $t1, 0x70($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X70);
    // 0x8001023C: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80010240: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80010244: sw          $t2, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->r10;
    // 0x80010248: lw          $t4, 0x70($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X70);
    // 0x8001024C: addiu       $t5, $t4, 0x4
    ctx->r13 = ADD32(ctx->r12, 0X4);
    // 0x80010250: sw          $t5, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r13;
L_80010254:
    // 0x80010254: b           L_800102F8
    // 0x80010258: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
        goto L_800102F8;
    // 0x80010258: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_8001025C:
    // 0x8001025C: lw          $v0, 0x6C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X6C);
    // 0x80010260: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
    // 0x80010264: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80010268: beql        $v0, $zero, L_800102A4
    if (ctx->r2 == 0) {
        // 0x8001026C: swc1        $f2, 0x7C($s3)
        MEM_W(0X7C, ctx->r19) = ctx->f2.u32l;
            goto L_800102A4;
    }
    goto skip_15;
    // 0x8001026C: swc1        $f2, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f2.u32l;
    skip_15:
    // 0x80010270: lbu         $t6, 0x5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5);
L_80010274:
    // 0x80010274: beql        $t6, $zero, L_80010298
    if (ctx->r14 == 0) {
        // 0x80010278: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_80010298;
    }
    goto skip_16;
    // 0x80010278: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_16:
    // 0x8001027C: lwc1        $f4, 0x78($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X78);
    // 0x80010280: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80010284: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x80010288: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8001028C: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80010290: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
    // 0x80010294: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_80010298:
    // 0x80010298: bnel        $v0, $zero, L_80010274
    if (ctx->r2 != 0) {
        // 0x8001029C: lbu         $t6, 0x5($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X5);
            goto L_80010274;
    }
    goto skip_17;
    // 0x8001029C: lbu         $t6, 0x5($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X5);
    skip_17:
    // 0x800102A0: swc1        $f2, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->f2.u32l;
L_800102A4:
    // 0x800102A4: lwc1        $f18, -0x1F78($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X1F78);
    // 0x800102A8: b           L_80010308
    // 0x800102AC: swc1        $f18, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f18.u32l;
        goto L_80010308;
    // 0x800102AC: swc1        $f18, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f18.u32l;
L_800102B0:
    // 0x800102B0: andi        $t7, $v0, 0x7FFF
    ctx->r15 = ctx->r2 & 0X7FFF;
    // 0x800102B4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800102B8: lwc1        $f6, 0x74($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X74);
    // 0x800102BC: bgez        $t7, L_800102D4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800102C0: cvt.s.w     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800102D4;
    }
    // 0x800102C0: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800102C4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800102C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800102CC: nop

    // 0x800102D0: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_800102D4:
    // 0x800102D4: add.s       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800102D8: addiu       $t8, $v1, 0x4
    ctx->r24 = ADD32(ctx->r3, 0X4);
    // 0x800102DC: sw          $t8, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r24;
    // 0x800102E0: addiu       $t0, $t8, 0x8
    ctx->r8 = ADD32(ctx->r24, 0X8);
    // 0x800102E4: swc1        $f10, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->f10.u32l;
    // 0x800102E8: sw          $t0, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r8;
    // 0x800102EC: b           L_800102F8
    // 0x800102F0: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
        goto L_800102F8;
    // 0x800102F0: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_800102F4:
    // 0x800102F4: lwc1        $f2, 0x74($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X74);
L_800102F8:
    // 0x800102F8: c.le.s      $f2, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f2.fl <= ctx->f22.fl;
    // 0x800102FC: nop

    // 0x80010300: bc1tl       L_8000FBAC
    if (c1cs) {
        // 0x80010304: lw          $v1, 0x70($s3)
        ctx->r3 = MEM_W(ctx->r19, 0X70);
            goto L_8000FBAC;
    }
    goto skip_18;
    // 0x80010304: lw          $v1, 0x70($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X70);
    skip_18:
L_80010308:
    // 0x80010308: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8001030C:
    // 0x8001030C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80010310: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80010314: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80010318: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8001031C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80010320: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80010324: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80010328: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8001032C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80010330: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80010334: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80010338: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8001033C: jr          $ra
    // 0x80010340: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x80010340: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void lbRelocReadDmaTableEntry(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD814: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x800CD818: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800CD81C: lw          $t6, 0x62E0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X62E0);
    // 0x800CD820: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800CD824: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800CD828: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CD82C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800CD830: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CD834: lw          $a1, 0x6334($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6334);
    // 0x800CD838: addiu       $a2, $zero, 0x18
    ctx->r6 = ADD32(0, 0X18);
    // 0x800CD83C: jal         0x80002CA0
    // 0x800CD840: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    syDmaReadRom(rdram, ctx);
        goto after_0;
    // 0x800CD840: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x800CD844: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800CD848: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800CD84C: jr          $ra
    // 0x800CD850: nop

    return;
    // 0x800CD850: nop

;}
RECOMP_FUNC void mpCollisionGetEdgeUpperRLineID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FAAE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800FAAE8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800FAAEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FAAF0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800FAAF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FAAF8: beq         $a0, $at, L_800FAB0C
    if (ctx->r4 == ctx->r1) {
        // 0x800FAAFC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_800FAB0C;
    }
    // 0x800FAAFC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800FAB00: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800FAB04: bne         $a0, $at, L_800FAB30
    if (ctx->r4 != ctx->r1) {
        // 0x800FAB08: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800FAB30;
    }
    // 0x800FAB08: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800FAB0C:
    // 0x800FAB0C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAB10: addiu       $s0, $s0, 0x4F4
    ctx->r16 = ADD32(ctx->r16, 0X4F4);
    // 0x800FAB14: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAB18:
    // 0x800FAB18: jal         0x80023624
    // 0x800FAB1C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800FAB1C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800FAB20: jal         0x800A3040
    // 0x800FAB24: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800FAB24: nop

    after_1:
    // 0x800FAB28: b           L_800FAB18
    // 0x800FAB2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800FAB18;
    // 0x800FAB2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800FAB30:
    // 0x800FAB30: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800FAB34: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800FAB38: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800FAB3C: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800FAB40: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800FAB44: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800FAB48: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800FAB4C: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800FAB50: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800FAB54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800FAB58: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800FAB5C: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800FAB60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FAB64: lw          $t2, 0x84($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X84);
    // 0x800FAB68: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x800FAB6C: bnel        $at, $zero, L_800FAB98
    if (ctx->r1 != 0) {
        // 0x800FAB70: lh          $v0, 0x6($v1)
        ctx->r2 = MEM_H(ctx->r3, 0X6);
            goto L_800FAB98;
    }
    goto skip_0;
    // 0x800FAB70: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
    skip_0:
    // 0x800FAB74: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800FAB78: addiu       $s0, $s0, 0x514
    ctx->r16 = ADD32(ctx->r16, 0X514);
L_800FAB7C:
    // 0x800FAB7C: jal         0x80023624
    // 0x800FAB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800FAB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FAB84: jal         0x800A3040
    // 0x800FAB88: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800FAB88: nop

    after_3:
    // 0x800FAB8C: b           L_800FAB7C
    // 0x800FAB90: nop

        goto L_800FAB7C;
    // 0x800FAB90: nop

    // 0x800FAB94: lh          $v0, 0x6($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X6);
L_800FAB98:
    // 0x800FAB98: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800FAB9C: jr          $ra
    // 0x800FABA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800FABA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnPlayers1PBonusPuckAdjustPlaced(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013635C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136364: jal         0x801361AC
    // 0x80136368: nop

    mnPlayers1PBonusPuckAdjustPortraitEdge(rdram, ctx);
        goto after_0;
    // 0x80136368: nop

    after_0:
    // 0x8013636C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80136374: jr          $ra
    // 0x80136378: nop

    return;
    // 0x80136378: nop

;}
RECOMP_FUNC void mnVSRecordTableGridProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013328C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80133290: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133294: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80133298: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x8013329C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801332A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801332A4: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801332A8: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801332AC: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801332B0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801332B4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801332B8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801332BC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801332C0: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801332C4: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x801332C8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801332CC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801332D0: lui         $t0, 0x30
    ctx->r8 = S32(0X30 << 16);
    // 0x801332D4: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x801332D8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801332DC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801332E0: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x801332E4: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x801332E8: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x801332EC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x801332F0: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x801332F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801332F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801332FC: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x80133300: lui         $a0, 0x6262
    ctx->r4 = S32(0X6262 << 16);
    // 0x80133304: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80133308: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x8013330C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80133310: ori         $a0, $a0, 0x6AFF
    ctx->r4 = ctx->r4 | 0X6AFF;
    // 0x80133314: jal         0x80006D70
    // 0x80133318: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    syVideoGetFillColor(rdram, ctx);
        goto after_0;
    // 0x80133318: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8013331C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80133320: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133324: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133328: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x8013332C: lw          $v1, 0x6C18($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6C18);
    // 0x80133330: beq         $v1, $zero, L_80133354
    if (ctx->r3 == 0) {
        // 0x80133334: nop
    
            goto L_80133354;
    }
    // 0x80133334: nop

    // 0x80133338: beq         $v1, $at, L_80133364
    if (ctx->r3 == ctx->r1) {
        // 0x8013333C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80133364;
    }
    // 0x8013333C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133340: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133344: beq         $v1, $at, L_80133374
    if (ctx->r3 == ctx->r1) {
        // 0x80133348: nop
    
            goto L_80133374;
    }
    // 0x80133348: nop

    // 0x8013334C: b           L_80133380
    // 0x80133350: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80133380;
    // 0x80133350: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80133354:
    // 0x80133354: jal         0x80132D90
    // 0x80133358: nop

    mnVSRecordDrawBattleScoreGrid(rdram, ctx);
        goto after_1;
    // 0x80133358: nop

    after_1:
    // 0x8013335C: b           L_80133380
    // 0x80133360: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80133380;
    // 0x80133360: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80133364:
    // 0x80133364: jal         0x80132EE4
    // 0x80133368: lw          $a0, 0x6CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6CC0);
    mnVSRecordDrawRankingGrid(rdram, ctx);
        goto after_2;
    // 0x80133368: lw          $a0, 0x6CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6CC0);
    after_2:
    // 0x8013336C: b           L_80133380
    // 0x80133370: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
        goto L_80133380;
    // 0x80133370: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80133374:
    // 0x80133374: jal         0x801330FC
    // 0x80133378: nop

    mnVSRecordDrawIndivGrid(rdram, ctx);
        goto after_3;
    // 0x80133378: nop

    after_3:
    // 0x8013337C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
L_80133380:
    // 0x80133380: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80133384: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80133388: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8013338C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80133390: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133394: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133398: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8013339C: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x801333A0: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x801333A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801333A8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801333AC: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x801333B0: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801333B4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801333B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x801333BC: lui         $t1, 0xE300
    ctx->r9 = S32(0XE300 << 16);
    // 0x801333C0: ori         $t1, $t1, 0xA01
    ctx->r9 = ctx->r9 | 0XA01;
    // 0x801333C4: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x801333C8: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801333CC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801333D0: jal         0x800CCEAC
    // 0x801333D4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_4;
    // 0x801333D4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    after_4:
    // 0x801333D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801333DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801333E0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801333E4: jr          $ra
    // 0x801333E8: nop

    return;
    // 0x801333E8: nop

;}
RECOMP_FUNC void ftKirbyThrowFLandingProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014A4F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014A4FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014A500: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014A504: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x8014A508: bne         $t6, $zero, L_8014A520
    if (ctx->r14 != 0) {
        // 0x8014A50C: nop
    
            goto L_8014A520;
    }
    // 0x8014A50C: nop

    // 0x8014A510: jal         0x800D8BB4
    // 0x8014A514: nop

    ftPhysicsApplyGroundVelFriction(rdram, ctx);
        goto after_0;
    // 0x8014A514: nop

    after_0:
    // 0x8014A518: b           L_8014A52C
    // 0x8014A51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8014A52C;
    // 0x8014A51C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014A520:
    // 0x8014A520: jal         0x800D93E4
    // 0x8014A524: nop

    ftPhysicsApplyAirVelTransNAll(rdram, ctx);
        goto after_1;
    // 0x8014A524: nop

    after_1:
    // 0x8014A528: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014A52C:
    // 0x8014A52C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014A530: jr          $ra
    // 0x8014A534: nop

    return;
    // 0x8014A534: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNStartSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801629D8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801629DC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801629E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801629E4: jal         0x800DEE98
    // 0x801629E8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801629E8: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x801629EC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801629F0: addiu       $t7, $zero, 0x824
    ctx->r15 = ADD32(0, 0X824);
    // 0x801629F4: addiu       $a1, $zero, 0x10D
    ctx->r5 = ADD32(0, 0X10D);
    // 0x801629F8: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801629FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162A00: jal         0x800E6F24
    // 0x80162A04: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162A04: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162A08: jal         0x80161E94
    // 0x80162A0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbySpecialNGotoSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x80162A0C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80162A10: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162A14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80162A18: jr          $ra
    // 0x80162A1C: nop

    return;
    // 0x80162A1C: nop

;}
RECOMP_FUNC void itTaruRollProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017A004: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017A008: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017A00C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017A010: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017A014: lwc1        $f12, 0xBC($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0XBC);
    // 0x8017A018: lwc1        $f14, 0xB8($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XB8);
    // 0x8017A01C: jal         0x8001863C
    // 0x8017A020: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8017A020: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017A024: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017A028: lwc1        $f4, -0x3278($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3278);
    // 0x8017A02C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017A030: lwc1        $f10, -0x3274($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3274);
    // 0x8017A034: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x8017A038: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A03C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8017A040: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8017A044: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8017A048: lwc1        $f18, 0x2C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8017A04C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8017A050: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017A054: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x8017A058: swc1        $f4, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f4.u32l;
    // 0x8017A05C: lwc1        $f6, 0x2C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8017A060: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x8017A064: nop

    // 0x8017A068: bc1fl       L_8017A07C
    if (!c1cs) {
        // 0x8017A06C: sw          $t8, 0x24($v1)
        MEM_W(0X24, ctx->r3) = ctx->r24;
            goto L_8017A07C;
    }
    goto skip_0;
    // 0x8017A06C: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
    skip_0:
    // 0x8017A070: b           L_8017A07C
    // 0x8017A074: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
        goto L_8017A07C;
    // 0x8017A074: sw          $t7, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r15;
    // 0x8017A078: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_8017A07C:
    // 0x8017A07C: lwc1        $f0, 0x2C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x8017A080: lwc1        $f2, 0x30($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X30);
    // 0x8017A084: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8017A088: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8017A08C: nop

    // 0x8017A090: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8017A094: jal         0x80033510
    // 0x8017A098: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8017A098: add.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f18.fl;
    after_1:
    // 0x8017A09C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017A0A0: lwc1        $f16, -0x3270($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3270);
    // 0x8017A0A4: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017A0A8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8017A0AC: nop

    // 0x8017A0B0: bc1fl       L_8017A0FC
    if (!c1cs) {
        // 0x8017A0B4: lw          $t5, 0x24($v1)
        ctx->r13 = MEM_W(ctx->r3, 0X24);
            goto L_8017A0FC;
    }
    goto skip_1;
    // 0x8017A0B4: lw          $t5, 0x24($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X24);
    skip_1:
    // 0x8017A0B8: lw          $t9, 0x2C0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X2C0);
    // 0x8017A0BC: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8017A0C0: slti        $at, $t0, 0x3C
    ctx->r1 = SIGNED(ctx->r8) < 0X3C ? 1 : 0;
    // 0x8017A0C4: sw          $t0, 0x2C0($v1)
    MEM_W(0X2C0, ctx->r3) = ctx->r8;
    // 0x8017A0C8: beq         $at, $zero, L_8017A0F8
    if (ctx->r1 == 0) {
        // 0x8017A0CC: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_8017A0F8;
    }
    // 0x8017A0CC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x8017A0D0: bne         $t0, $zero, L_8017A0E0
    if (ctx->r8 != 0) {
        // 0x8017A0D4: andi        $t1, $v0, 0x1
        ctx->r9 = ctx->r2 & 0X1;
            goto L_8017A0E0;
    }
    // 0x8017A0D4: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x8017A0D8: b           L_8017A138
    // 0x8017A0DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017A138;
    // 0x8017A0DC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017A0E0:
    // 0x8017A0E0: beq         $t1, $zero, L_8017A0F8
    if (ctx->r9 == 0) {
        // 0x8017A0E4: lw          $t2, 0x20($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X20);
            goto L_8017A0F8;
    }
    // 0x8017A0E4: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x8017A0E8: lw          $a0, 0x74($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X74);
    // 0x8017A0EC: lbu         $t3, 0x54($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X54);
    // 0x8017A0F0: xori        $t4, $t3, 0x2
    ctx->r12 = ctx->r11 ^ 0X2;
    // 0x8017A0F4: sb          $t4, 0x54($a0)
    MEM_B(0X54, ctx->r4) = ctx->r12;
L_8017A0F8:
    // 0x8017A0F8: lw          $t5, 0x24($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X24);
L_8017A0FC:
    // 0x8017A0FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8017A100: bne         $t5, $at, L_8017A110
    if (ctx->r13 != ctx->r1) {
        // 0x8017A104: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8017A110;
    }
    // 0x8017A104: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017A108: b           L_8017A118
    // 0x8017A10C: lwc1        $f12, -0x326C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X326C);
        goto L_8017A118;
    // 0x8017A10C: lwc1        $f12, -0x326C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X326C);
L_8017A110:
    // 0x8017A110: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017A114: lwc1        $f12, -0x3268($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3268);
L_8017A118:
    // 0x8017A118: mul.s       $f2, $f12, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8017A11C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017A120: swc1        $f2, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->f2.u32l;
    // 0x8017A124: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x8017A128: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8017A12C: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x8017A130: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x8017A134: swc1        $f6, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f6.u32l;
L_8017A138:
    // 0x8017A138: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017A13C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017A140: jr          $ra
    // 0x8017A144: nop

    return;
    // 0x8017A144: nop

;}
RECOMP_FUNC void mnUnusedFightersFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6490: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800D6494: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800D6498: addiu       $t8, $t8, 0x7030
    ctx->r24 = ADD32(ctx->r24, 0X7030);
    // 0x800D649C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800D64A0: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800D64A4: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x800D64A8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800D64AC: jr          $ra
    // 0x800D64B0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x800D64B0: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}

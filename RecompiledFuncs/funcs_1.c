#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayers1PBonusGetForcePuckFighterKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134E50: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134E54: lw          $t6, 0x764C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X764C);
    // 0x80134E58: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134E5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134E60: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x80134E64: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80134E68: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80134E6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134E70: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80134E74: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80134E78: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x80134E7C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80134E80: addiu       $v1, $v1, 0xC
    ctx->r3 = ADD32(ctx->r3, 0XC);
    // 0x80134E84: slti        $at, $v1, 0x24
    ctx->r1 = SIGNED(ctx->r3) < 0X24 ? 1 : 0;
    // 0x80134E88: bne         $at, $zero, L_80134EA4
    if (ctx->r1 != 0) {
        // 0x80134E8C: addiu       $a1, $a1, 0xD
        ctx->r5 = ADD32(ctx->r5, 0XD);
            goto L_80134EA4;
    }
    // 0x80134E8C: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    // 0x80134E90: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80134E94: beq         $at, $zero, L_80134EA4
    if (ctx->r1 == 0) {
        // 0x80134E98: nop
    
            goto L_80134EA4;
    }
    // 0x80134E98: nop

    // 0x80134E9C: b           L_80134EA4
    // 0x80134EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134EA4;
    // 0x80134EA0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134EA4:
    // 0x80134EA4: beq         $v0, $zero, L_80134EEC
    if (ctx->r2 == 0) {
        // 0x80134EA8: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_80134EEC;
    }
    // 0x80134EA8: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x80134EAC: bne         $at, $zero, L_80134EC8
    if (ctx->r1 != 0) {
        // 0x80134EB0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134EC8;
    }
    // 0x80134EB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134EB4: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x80134EB8: beq         $at, $zero, L_80134EC8
    if (ctx->r1 == 0) {
        // 0x80134EBC: nop
    
            goto L_80134EC8;
    }
    // 0x80134EBC: nop

    // 0x80134EC0: b           L_80134EC8
    // 0x80134EC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134EC8;
    // 0x80134EC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134EC8:
    // 0x80134EC8: beq         $v0, $zero, L_80134EEC
    if (ctx->r2 == 0) {
        // 0x80134ECC: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_80134EEC;
    }
    // 0x80134ECC: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x80134ED0: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80134ED4: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80134ED8: mflo        $a0
    ctx->r4 = lo;
    // 0x80134EDC: jal         0x80132390
    // 0x80134EE0: nop

    mnPlayers1PBonusGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x80134EE0: nop

    after_0:
    // 0x80134EE4: b           L_80134F60
    // 0x80134EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80134F60;
    // 0x80134EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134EEC:
    // 0x80134EEC: slti        $at, $v1, 0x4F
    ctx->r1 = SIGNED(ctx->r3) < 0X4F ? 1 : 0;
    // 0x80134EF0: bne         $at, $zero, L_80134F0C
    if (ctx->r1 != 0) {
        // 0x80134EF4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134F0C;
    }
    // 0x80134EF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134EF8: slti        $at, $v1, 0x7A
    ctx->r1 = SIGNED(ctx->r3) < 0X7A ? 1 : 0;
    // 0x80134EFC: beq         $at, $zero, L_80134F0C
    if (ctx->r1 == 0) {
        // 0x80134F00: nop
    
            goto L_80134F0C;
    }
    // 0x80134F00: nop

    // 0x80134F04: b           L_80134F0C
    // 0x80134F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134F0C;
    // 0x80134F08: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134F0C:
    // 0x80134F0C: beq         $v0, $zero, L_80134F58
    if (ctx->r2 == 0) {
        // 0x80134F10: slti        $at, $a1, 0x19
        ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
            goto L_80134F58;
    }
    // 0x80134F10: slti        $at, $a1, 0x19
    ctx->r1 = SIGNED(ctx->r5) < 0X19 ? 1 : 0;
    // 0x80134F14: bne         $at, $zero, L_80134F30
    if (ctx->r1 != 0) {
        // 0x80134F18: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80134F30;
    }
    // 0x80134F18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80134F1C: slti        $at, $a1, 0x127
    ctx->r1 = SIGNED(ctx->r5) < 0X127 ? 1 : 0;
    // 0x80134F20: beq         $at, $zero, L_80134F30
    if (ctx->r1 == 0) {
        // 0x80134F24: nop
    
            goto L_80134F30;
    }
    // 0x80134F24: nop

    // 0x80134F28: b           L_80134F30
    // 0x80134F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80134F30;
    // 0x80134F2C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80134F30:
    // 0x80134F30: beq         $v0, $zero, L_80134F58
    if (ctx->r2 == 0) {
        // 0x80134F34: addiu       $a0, $a1, -0x19
        ctx->r4 = ADD32(ctx->r5, -0X19);
            goto L_80134F58;
    }
    // 0x80134F34: addiu       $a0, $a1, -0x19
    ctx->r4 = ADD32(ctx->r5, -0X19);
    // 0x80134F38: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80134F3C: div         $zero, $a0, $at
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r1)));
    // 0x80134F40: mflo        $a0
    ctx->r4 = lo;
    // 0x80134F44: addiu       $a0, $a0, 0x6
    ctx->r4 = ADD32(ctx->r4, 0X6);
    // 0x80134F48: jal         0x80132390
    // 0x80134F4C: nop

    mnPlayers1PBonusGetFighterKind(rdram, ctx);
        goto after_1;
    // 0x80134F4C: nop

    after_1:
    // 0x80134F50: b           L_80134F60
    // 0x80134F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80134F60;
    // 0x80134F54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134F58:
    // 0x80134F58: addiu       $v0, $zero, 0x1C
    ctx->r2 = ADD32(0, 0X1C);
    // 0x80134F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80134F60:
    // 0x80134F60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134F64: jr          $ra
    // 0x80134F68: nop

    return;
    // 0x80134F68: nop

;}
RECOMP_FUNC void itLGunWeaponAmmoProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801758BC: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801758C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801758C4: lwc1        $f2, -0x32F8($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X32F8);
    // 0x801758C8: lwc1        $f0, 0x40($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801758CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801758D0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x801758D4: nop

    // 0x801758D8: bc1f        L_8017590C
    if (!c1cs) {
        // 0x801758DC: nop
    
            goto L_8017590C;
    }
    // 0x801758DC: nop

    // 0x801758E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801758E4: nop

    // 0x801758E8: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x801758EC: swc1        $f6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f6.u32l;
    // 0x801758F0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801758F4: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x801758F8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x801758FC: nop

    // 0x80175900: bc1f        L_8017590C
    if (!c1cs) {
        // 0x80175904: nop
    
            goto L_8017590C;
    }
    // 0x80175904: nop

    // 0x80175908: swc1        $f2, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f2.u32l;
L_8017590C:
    // 0x8017590C: jr          $ra
    // 0x80175910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80175910: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeRoomFadeOutCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133524: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133528: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8013352C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133530: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133534: addiu       $t7, $zero, 0x28
    ctx->r15 = ADD32(0, 0X28);
    // 0x80133538: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013353C: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80133540: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133544: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133548: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013354C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133550: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133554: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133558: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013355C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133560: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133564: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133568: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013356C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133570: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133574: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133578: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013357C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133580: jal         0x8000B93C
    // 0x80133584: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133584: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133588: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013358C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133590: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133594: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133598: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013359C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801335A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801335A4: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801335A8: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801335AC: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x801335B0: jal         0x80007080
    // 0x801335B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801335B4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801335B8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x801335BC: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x801335C0: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x801335C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801335C8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801335CC: jr          $ra
    // 0x801335D0: nop

    return;
    // 0x801335D0: nop

;}
RECOMP_FUNC void ftDonkeyThrowAirFFProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DEF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014DEF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014DEF8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8014DEFC: jal         0x800DE6E4
    // 0x8014DF00: addiu       $a1, $a1, -0x21D0
    ctx->r5 = ADD32(ctx->r5, -0X21D0);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8014DF00: addiu       $a1, $a1, -0x21D0
    ctx->r5 = ADD32(ctx->r5, -0X21D0);
    after_0:
    // 0x8014DF04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014DF08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014DF0C: jr          $ra
    // 0x8014DF10: nop

    return;
    // 0x8014DF10: nop

;}
RECOMP_FUNC void mnVSRecordMakeColumnArrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132CC8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132CCC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132CD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132CD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132CD8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132CDC: jal         0x80009968
    // 0x80132CE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132CE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132CE4: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132CE8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132CEC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132CF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132CF4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132CF8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132CFC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132D00: jal         0x80009DF4
    // 0x80132D04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132D04: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132D08: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132D0C: addiu       $a1, $a1, 0x2C9C
    ctx->r5 = ADD32(ctx->r5, 0X2C9C);
    // 0x80132D10: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132D14: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132D18: jal         0x80008188
    // 0x80132D1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80132D1C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80132D20: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132D24: lw          $t7, 0x6D88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D88);
    // 0x80132D28: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132D2C: addiu       $t8, $t8, 0x17A8
    ctx->r24 = ADD32(ctx->r24, 0X17A8);
    // 0x80132D30: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132D34: jal         0x800CCFDC
    // 0x80132D38: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132D38: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80132D3C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132D40: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80132D44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132D48: lui         $at, 0x423C
    ctx->r1 = S32(0X423C << 16);
    // 0x80132D4C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132D50: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132D54: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132D58: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132D5C: addiu       $t3, $zero, 0xE3
    ctx->r11 = ADD32(0, 0XE3);
    // 0x80132D60: addiu       $t4, $zero, 0x7D
    ctx->r12 = ADD32(0, 0X7D);
    // 0x80132D64: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80132D68: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132D6C: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132D70: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80132D74: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x80132D78: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132D7C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132D80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132D84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132D88: jr          $ra
    // 0x80132D8C: nop

    return;
    // 0x80132D8C: nop

;}
RECOMP_FUNC void func_80005018(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005018: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000501C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80005020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80005024: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80005028: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000502C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80005030: addiu       $v0, $v0, 0x54E8
    ctx->r2 = ADD32(ctx->r2, 0X54E8);
    // 0x80005034: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80005038: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8000503C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80005040: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80005044: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80005048: beql        $t8, $zero, L_8000506C
    if (ctx->r24 == 0) {
        // 0x8000504C: sw          $zero, 0x14($s0)
        MEM_W(0X14, ctx->r16) = 0;
            goto L_8000506C;
    }
    goto skip_0;
    // 0x8000504C: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
    skip_0:
    // 0x80005050: lw          $t9, 0x666C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X666C);
    // 0x80005054: sw          $t9, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r25;
    // 0x80005058: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8000505C: sw          $t0, 0x68($a0)
    MEM_W(0X68, ctx->r4) = ctx->r8;
    // 0x80005060: b           L_80005070
    // 0x80005064: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_80005070;
    // 0x80005064: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80005068: sw          $zero, 0x14($s0)
    MEM_W(0X14, ctx->r16) = 0;
L_8000506C:
    // 0x8000506C: sw          $zero, 0x68($s0)
    MEM_W(0X68, ctx->r16) = 0;
L_80005070:
    // 0x80005070: sw          $a1, 0x6C($s0)
    MEM_W(0X6C, ctx->r16) = ctx->r5;
    // 0x80005074: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80005078: lw          $t1, 0x65D4($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X65D4);
    // 0x8000507C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80005080: beq         $a1, $zero, L_8000509C
    if (ctx->r5 == 0) {
        // 0x80005084: sw          $t1, 0x70($s0)
        MEM_W(0X70, ctx->r16) = ctx->r9;
            goto L_8000509C;
    }
    // 0x80005084: sw          $t1, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r9;
    // 0x80005088: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x8000508C: addiu       $t2, $t2, 0x5500
    ctx->r10 = ADD32(ctx->r10, 0X5500);
    // 0x80005090: sw          $t2, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r10;
    // 0x80005094: b           L_800050A0
    // 0x80005098: sw          $a3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r7;
        goto L_800050A0;
    // 0x80005098: sw          $a3, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r7;
L_8000509C:
    // 0x8000509C: sw          $zero, 0x20($s0)
    MEM_W(0X20, ctx->r16) = 0;
L_800050A0:
    // 0x800050A0: sw          $a0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r4;
    // 0x800050A4: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x800050A8: lw          $t3, 0x6630($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6630);
    // 0x800050AC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800050B0: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800050B4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800050B8: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x800050BC: addiu       $t6, $t6, 0x4C40
    ctx->r14 = ADD32(ctx->r14, 0X4C40);
    // 0x800050C0: addiu       $t7, $zero, 0x100
    ctx->r15 = ADD32(0, 0X100);
    // 0x800050C4: addiu       $t9, $t9, -0x4914
    ctx->r25 = ADD32(ctx->r25, -0X4914);
    // 0x800050C8: sll         $t8, $a2, 3
    ctx->r24 = S32(ctx->r6 << 3);
    // 0x800050CC: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x800050D0: sw          $t4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r12;
    // 0x800050D4: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x800050D8: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x800050DC: sw          $t7, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r15;
    // 0x800050E0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800050E4: sw          $t3, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r11;
    // 0x800050E8: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800050EC: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x800050F0: addiu       $t2, $zero, 0x800
    ctx->r10 = ADD32(0, 0X800);
    // 0x800050F4: bne         $v1, $zero, L_80005114
    if (ctx->r3 != 0) {
        // 0x800050F8: lui         $t3, 0x8004
        ctx->r11 = S32(0X8004 << 16);
            goto L_80005114;
    }
    // 0x800050F8: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x800050FC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80005100: addiu       $a0, $a0, -0x27E0
    ctx->r4 = ADD32(ctx->r4, -0X27E0);
    // 0x80005104: jal         0x80023624
    // 0x80005108: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80005108: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
L_8000510C:
    // 0x8000510C: b           L_8000510C
    pause_self(rdram);
    // 0x80005110: nop

L_80005114:
    // 0x80005114: sw          $v1, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r3;
    // 0x80005118: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x8000511C: addiu       $t3, $t3, 0x5538
    ctx->r11 = ADD32(ctx->r11, 0X5538);
    // 0x80005120: addiu       $t4, $t3, 0xF
    ctx->r12 = ADD32(ctx->r11, 0XF);
    // 0x80005124: srl         $t5, $t4, 4
    ctx->r13 = S32(U32(ctx->r12) >> 4);
    // 0x80005128: sll         $t6, $t5, 4
    ctx->r14 = S32(ctx->r13 << 4);
    // 0x8000512C: addiu       $t7, $zero, 0x400
    ctx->r15 = ADD32(0, 0X400);
    // 0x80005130: sltiu       $at, $a2, 0xA
    ctx->r1 = ctx->r6 < 0XA ? 1 : 0;
    // 0x80005134: sw          $t1, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r9;
    // 0x80005138: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
    // 0x8000513C: sw          $t6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r14;
    // 0x80005140: sw          $t7, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->r15;
    // 0x80005144: beq         $at, $zero, L_8000518C
    if (ctx->r1 == 0) {
        // 0x80005148: sw          $t0, 0x40($s0)
        MEM_W(0X40, ctx->r16) = ctx->r8;
            goto L_8000518C;
    }
    // 0x80005148: sw          $t0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r8;
    // 0x8000514C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80005150: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80005154: addu        $at, $at, $t8
    gpr jr_addend_8000515C = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80005158: lw          $t8, -0x2798($at)
    ctx->r24 = ADD32(ctx->r1, -0X2798);
    // 0x8000515C: jr          $t8
    // 0x80005160: nop

    switch (jr_addend_8000515C >> 2) {
        case 0: goto L_80005164; break;
        case 1: goto L_80005180; break;
        case 2: goto L_80005164; break;
        case 3: goto L_80005180; break;
        case 4: goto L_80005164; break;
        case 5: goto L_80005180; break;
        case 6: goto L_80005164; break;
        case 7: goto L_80005180; break;
        case 8: goto L_80005164; break;
        case 9: goto L_80005180; break;
        default: switch_error(__func__, 0x8000515C, 0x8003D868);
    }
    // 0x80005160: nop

L_80005164:
    // 0x80005164: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80005168: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x8000516C: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80005170: sw          $a0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r4;
    // 0x80005174: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80005178: b           L_8000518C
    // 0x8000517C: sw          $t0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r8;
        goto L_8000518C;
    // 0x8000517C: sw          $t0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r8;
L_80005180:
    // 0x80005180: sw          $zero, 0x50($s0)
    MEM_W(0X50, ctx->r16) = 0;
    // 0x80005184: sw          $zero, 0x54($s0)
    MEM_W(0X54, ctx->r16) = 0;
    // 0x80005188: sw          $zero, 0x74($s0)
    MEM_W(0X74, ctx->r16) = 0;
L_8000518C:
    // 0x8000518C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x80005190: addiu       $t2, $t2, 0x5940
    ctx->r10 = ADD32(ctx->r10, 0X5940);
    // 0x80005194: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80005198: addiu       $t3, $t2, 0xF
    ctx->r11 = ADD32(ctx->r10, 0XF);
    // 0x8000519C: srl         $t4, $t3, 4
    ctx->r12 = S32(U32(ctx->r11) >> 4);
    // 0x800051A0: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800051A4: addiu       $t6, $zero, 0xC00
    ctx->r14 = ADD32(0, 0XC00);
    // 0x800051A8: sw          $zero, 0x5C($s0)
    MEM_W(0X5C, ctx->r16) = 0;
    // 0x800051AC: sw          $t5, 0x60($s0)
    MEM_W(0X60, ctx->r16) = ctx->r13;
    // 0x800051B0: sw          $t6, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r14;
    // 0x800051B4: jal         0x80039160
    // 0x800051B8: sw          $t1, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r9;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_1;
    // 0x800051B8: sw          $t1, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r9;
    after_1:
    // 0x800051BC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800051C0: addiu       $a0, $a0, 0x4FF8
    ctx->r4 = ADD32(ctx->r4, 0X4FF8);
    // 0x800051C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800051C8: jal         0x80030000
    // 0x800051CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800051CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x800051D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800051D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800051D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800051DC: jr          $ra
    // 0x800051E0: nop

    return;
    // 0x800051E0: nop

;}
RECOMP_FUNC void func_ovl8_8037AA28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037AA28: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8037AA2C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x8037AA30: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x8037AA34: sh          $t7, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r15;
    // 0x8037AA38: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x8037AA3C: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8037AA40: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8037AA44: sh          $t0, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r8;
    // 0x8037AA48: lh          $t2, 0x2($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2);
    // 0x8037AA4C: lh          $t1, 0x6($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X6);
    // 0x8037AA50: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x8037AA54: jr          $ra
    // 0x8037AA58: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
    return;
    // 0x8037AA58: sh          $t3, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r11;
;}
RECOMP_FUNC void mvOpeningPikachuMakePosedWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D964: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018D968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018D96C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D970: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D974: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x8018D978: jal         0x80009968
    // 0x8018D97C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D97C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D980: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D984: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018D988: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D98C: addiu       $a1, $a1, -0x279C
    ctx->r5 = ADD32(ctx->r5, -0X279C);
    // 0x8018D990: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D994: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8018D998: jal         0x80009DF4
    // 0x8018D99C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D99C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018D9A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D9A4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018D9A8: jr          $ra
    // 0x8018D9AC: nop

    return;
    // 0x8018D9AC: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135060: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80135064: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80135068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013506C: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x80135070: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80135074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80135078: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8013507C: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80135080: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80135084: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
L_80135088:
    // 0x80135088: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8013508C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80135090: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80135094: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80135098: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8013509C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x801350A0: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x801350A4: bne         $t7, $t0, L_80135088
    if (ctx->r15 != ctx->r8) {
        // 0x801350A8: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80135088;
    }
    // 0x801350A8: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x801350AC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801350B0: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x801350B4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801350B8: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x801350BC: beql        $t1, $at, L_801351BC
    if (ctx->r9 == ctx->r1) {
        // 0x801350C0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801351BC;
    }
    goto skip_0;
    // 0x801350C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801350C4: beql        $s0, $zero, L_801350F0
    if (ctx->r16 == 0) {
        // 0x801350C8: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_801350F0;
    }
    goto skip_1;
    // 0x801350C8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x801350CC: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x801350D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801350D4: lwc1        $f4, 0x34($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X34);
    // 0x801350D8: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x801350DC: jal         0x800D78E8
    // 0x801350E0: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    ftManagerDestroyFighter(rdram, ctx);
        goto after_0;
    // 0x801350E0: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x801350E4: b           L_801350F8
    // 0x801350E8: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
        goto L_801350F8;
    // 0x801350E8: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x801350EC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_801350F0:
    // 0x801350F0: nop

    // 0x801350F4: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
L_801350F8:
    // 0x801350F8: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x801350FC: lw          $t3, 0x70($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X70);
    // 0x80135100: lw          $t5, -0x703C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X703C);
    // 0x80135104: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x80135108: andi        $t4, $a3, 0xFF
    ctx->r12 = ctx->r7 & 0XFF;
    // 0x8013510C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80135110: sw          $t4, -0x70F4($at)
    MEM_W(-0X70F4, ctx->r1) = ctx->r12;
    // 0x80135114: sb          $a3, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r7;
    // 0x80135118: sb          $zero, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = 0;
    // 0x8013511C: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80135120: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x80135124: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x80135128: jal         0x800D7F3C
    // 0x8013512C: sb          $t0, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r8;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x8013512C: sb          $t0, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r8;
    after_1:
    // 0x80135130: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80135134: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80135138: sw          $v0, -0x7110($at)
    MEM_W(-0X7110, ctx->r1) = ctx->r2;
    // 0x8013513C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80135140: addiu       $a1, $a1, 0x4F40
    ctx->r5 = ADD32(ctx->r5, 0X4F40);
    // 0x80135144: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80135148: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013514C: jal         0x80008188
    // 0x80135150: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80135150: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80135154: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80135158: lwc1        $f8, -0x7138($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X7138);
    // 0x8013515C: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80135160: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80135164: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80135168: swc1        $f8, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f8.u32l;
    // 0x8013516C: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80135170: lwc1        $f10, -0x7134($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7134);
    // 0x80135174: addiu       $t2, $t2, 0xD90
    ctx->r10 = ADD32(ctx->r10, 0XD90);
    // 0x80135178: swc1        $f10, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f10.u32l;
    // 0x8013517C: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x80135180: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80135184: swc1        $f16, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f16.u32l;
    // 0x80135188: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8013518C: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80135190: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80135194: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80135198: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8013519C: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
    // 0x801351A0: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x801351A4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801351A8: swc1        $f4, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f4.u32l;
    // 0x801351AC: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x801351B0: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801351B4: swc1        $f6, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f6.u32l;
    // 0x801351B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801351BC:
    // 0x801351BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801351C0: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x801351C4: jr          $ra
    // 0x801351C8: nop

    return;
    // 0x801351C8: nop

;}
RECOMP_FUNC void func_ovl28_80131FC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FC8: jr          $ra
    // 0x80131FCC: nop

    return;
    // 0x80131FCC: nop

;}
RECOMP_FUNC void ifCommonPlayerArrowsMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111684: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80111688: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8011168C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80111690: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80111694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80111698: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8011169C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x801116A0: jal         0x80009968
    // 0x801116A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801116A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801116A8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801116AC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801116B0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801116B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801116B8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801116BC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x801116C0: jal         0x80009DF4
    // 0x801116C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801116C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801116C8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801116CC: lw          $t7, 0xD40($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD40);
    // 0x801116D0: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801116D4: addiu       $t8, $t8, 0x188
    ctx->r24 = ADD32(ctx->r24, 0X188);
    // 0x801116D8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801116DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801116E0: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    // 0x801116E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801116E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x801116EC: jal         0x8000F590
    // 0x801116F0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_2;
    // 0x801116F0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801116F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801116F8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801116FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80111700: jal         0x80008188
    // 0x80111704: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80111704: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x80111708: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8011170C: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80111710: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80111714: jr          $ra
    // 0x80111718: nop

    return;
    // 0x80111718: nop

;}
RECOMP_FUNC void gmRumbleAddLinkAfter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115090: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80115094: lw          $v1, 0x4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X4);
    // 0x80115098: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8011509C: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x801150A0: beq         $v1, $zero, L_801150E8
    if (ctx->r3 == 0) {
        // 0x801150A4: sw          $zero, 0x10($t7)
        MEM_W(0X10, ctx->r15) = 0;
            goto L_801150E8;
    }
    // 0x801150A4: sw          $zero, 0x10($t7)
    MEM_W(0X10, ctx->r15) = 0;
    // 0x801150A8: lw          $a2, 0x8($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X8);
    // 0x801150AC: lw          $t8, 0x4($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4);
    // 0x801150B0: bnel        $t8, $zero, L_801150C8
    if (ctx->r24 != 0) {
        // 0x801150B4: sw          $v1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r3;
            goto L_801150C8;
    }
    goto skip_0;
    // 0x801150B4: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
    skip_0:
    // 0x801150B8: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x801150BC: b           L_801150D0
    // 0x801150C0: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
        goto L_801150D0;
    // 0x801150C0: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x801150C4: sw          $v1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r3;
L_801150C8:
    // 0x801150C8: lw          $t0, 0x8($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X8);
    // 0x801150CC: sw          $t0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r8;
L_801150D0:
    // 0x801150D0: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x801150D4: sw          $t1, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r9;
    // 0x801150D8: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x801150DC: sw          $v0, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r2;
    // 0x801150E0: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    // 0x801150E4: sw          $a1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r5;
L_801150E8:
    // 0x801150E8: jr          $ra
    // 0x801150EC: nop

    return;
    // 0x801150EC: nop

;}
RECOMP_FUNC void ftCommonDownBounceCheckUpOrDown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144398: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014439C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801443A0: lwc1        $f4, -0x3EB0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3EB0);
    // 0x801443A4: lw          $t6, 0x8F8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8F8);
    // 0x801443A8: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x801443AC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x801443B0: lwc1        $f0, 0x30($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X30);
    // 0x801443B4: div.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801443B8: trunc.w.s   $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    ctx->f6.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x801443BC: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x801443C0: nop

    // 0x801443C4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801443C8: nop

    // 0x801443CC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801443D0: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x801443D4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801443D8: nop

    // 0x801443DC: bc1t        L_80144418
    if (c1cs) {
        // 0x801443E0: nop
    
            goto L_80144418;
    }
    // 0x801443E0: nop

    // 0x801443E4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x801443E8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x801443EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801443F0: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x801443F4: nop

    // 0x801443F8: bc1f        L_80144420
    if (!c1cs) {
        // 0x801443FC: nop
    
            goto L_80144420;
    }
    // 0x801443FC: nop

    // 0x80144400: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80144404: nop

    // 0x80144408: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x8014440C: nop

    // 0x80144410: bc1f        L_80144420
    if (!c1cs) {
        // 0x80144414: nop
    
            goto L_80144420;
    }
    // 0x80144414: nop

L_80144418:
    // 0x80144418: jr          $ra
    // 0x8014441C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8014441C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80144420:
    // 0x80144420: jr          $ra
    // 0x80144424: nop

    return;
    // 0x80144424: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetPortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801327F0: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801327F4: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x801327F8: addiu       $t6, $t6, -0x774C
    ctx->r14 = ADD32(ctx->r14, -0X774C);
    // 0x801327FC: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80132800: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80132804:
    // 0x80132804: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132808: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013280C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132810: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132814: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132818: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8013281C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132820: bne         $t6, $t0, L_80132804
    if (ctx->r14 != ctx->r8) {
        // 0x80132824: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132804;
    }
    // 0x80132824: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132828: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8013282C: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80132830: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80132834: jr          $ra
    // 0x80132838: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80132838: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftKirbySpecialNThrowSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163224: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80163228: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016322C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80163230: addiu       $t7, $zero, 0xA4
    ctx->r15 = ADD32(0, 0XA4);
    // 0x80163234: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80163238: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016323C: addiu       $a1, $zero, 0x112
    ctx->r5 = ADD32(0, 0X112);
    // 0x80163240: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163244: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163248: jal         0x800E6F24
    // 0x8016324C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8016324C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80163250: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80163254: jal         0x800E8098
    // 0x80163258: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x80163258: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x8016325C: jal         0x800E0830
    // 0x80163260: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80163260: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80163264: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80163268: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016326C: jr          $ra
    // 0x80163270: nop

    return;
    // 0x80163270: nop

;}
RECOMP_FUNC void func_8002AE1C_2BA1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AE1C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8002AE20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002AE24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8002AE28: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x8002AE2C: lw          $t6, 0x24($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X24);
    // 0x8002AE30: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8002AE34: or          $t1, $a0, $zero
    ctx->r9 = ctx->r4 | 0;
    // 0x8002AE38: beq         $t6, $zero, L_8002AFE8
    if (ctx->r14 == 0) {
        // 0x8002AE3C: or          $t3, $a3, $zero
        ctx->r11 = ctx->r7 | 0;
            goto L_8002AFE8;
    }
    // 0x8002AE3C: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8002AE40: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x8002AE44: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8002AE48: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8002AE4C: addiu       $a1, $zero, 0xB8
    ctx->r5 = ADD32(0, 0XB8);
    // 0x8002AE50: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8002AE54: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
    // 0x8002AE58: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x8002AE5C: jal         0x8002AD90
    // 0x8002AE60: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    func_8002AD90_2B990(rdram, ctx);
        goto after_0;
    // 0x8002AE60: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    after_0:
    // 0x8002AE64: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x8002AE68: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8002AE6C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8002AE70: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8002AE74: addiu       $t7, $zero, 0xB8
    ctx->r15 = ADD32(0, 0XB8);
    // 0x8002AE78: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002AE7C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002AE80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8002AE84: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8002AE88: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8002AE8C: addiu       $a2, $zero, 0x2E0
    ctx->r6 = ADD32(0, 0X2E0);
    // 0x8002AE90: div.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8002AE94: mul.s       $f16, $f10, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x8002AE98: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8002AE9C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8002AEA0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8002AEA4: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x8002AEA8: nop

    // 0x8002AEAC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8002AEB0: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8002AEB4: div.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f14.fl);
    // 0x8002AEB8: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8002AEBC: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8002AEC0: swc1        $f2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f2.u32l;
    // 0x8002AEC4: lw          $v0, 0x24($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X24);
    // 0x8002AEC8: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8002AECC: add.s       $f12, $f16, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x8002AED0: trunc.w.s   $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = TRUNC_W_S(ctx->f12.fl);
    // 0x8002AED4: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8002AED8: nop

    // 0x8002AEDC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8002AEE0: nop

    // 0x8002AEE4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8002AEE8: sub.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f18.fl;
    // 0x8002AEEC: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x8002AEF0: lw          $t4, 0x18($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X18);
    // 0x8002AEF4: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x8002AEF8: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8002AEFC: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002AF00: subu        $t5, $t9, $t4
    ctx->r13 = SUB32(ctx->r25, ctx->r12);
    // 0x8002AF04: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x8002AF08: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8002AF0C: addu        $t0, $t8, $t7
    ctx->r8 = ADD32(ctx->r24, ctx->r15);
    // 0x8002AF10: andi        $t2, $t0, 0x7
    ctx->r10 = ctx->r8 & 0X7;
    // 0x8002AF14: sra         $t2, $t2, 1
    ctx->r10 = S32(SIGNED(ctx->r10) >> 1);
    // 0x8002AF18: sll         $t9, $t2, 1
    ctx->r25 = S32(ctx->r10 << 1);
    // 0x8002AF1C: subu        $a1, $t0, $t9
    ctx->r5 = SUB32(ctx->r8, ctx->r25);
    // 0x8002AF20: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8002AF24: addu        $a3, $v1, $t2
    ctx->r7 = ADD32(ctx->r3, ctx->r10);
    // 0x8002AF28: jal         0x8002AC48
    // 0x8002AF2C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    func_8002AC48_2B848(rdram, ctx);
        goto after_1;
    // 0x8002AF2C: sw          $v1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r3;
    after_1:
    // 0x8002AF30: lw          $t4, 0x24($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X24);
    // 0x8002AF34: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x8002AF38: lw          $a0, 0x14($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X14);
    // 0x8002AF3C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8002AF40: jal         0x80032150
    // 0x8002AF44: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x8002AF44: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    after_2:
    // 0x8002AF48: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x8002AF4C: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8002AF50: and         $t5, $v0, $at
    ctx->r13 = ctx->r2 & ctx->r1;
    // 0x8002AF54: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x8002AF58: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x8002AF5C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x8002AF60: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x8002AF64: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8002AF68: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8002AF6C: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x8002AF70: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8002AF74: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x8002AF78: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8002AF7C: lw          $t5, 0x24($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X24);
    // 0x8002AF80: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x8002AF84: lw          $t8, 0x24($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X24);
    // 0x8002AF88: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x8002AF8C: addiu       $t6, $t5, 0x2E0
    ctx->r14 = ADD32(ctx->r13, 0X2E0);
    // 0x8002AF90: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x8002AF94: trunc.w.s   $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8002AF98: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x8002AF9C: nop

    // 0x8002AFA0: andi        $t9, $t7, 0xFFFF
    ctx->r25 = ctx->r15 & 0XFFFF;
    // 0x8002AFA4: sll         $t7, $t8, 30
    ctx->r15 = S32(ctx->r24 << 30);
    // 0x8002AFA8: sll         $t4, $t9, 14
    ctx->r12 = S32(ctx->r25 << 14);
    // 0x8002AFAC: or          $t9, $t7, $t4
    ctx->r25 = ctx->r15 | ctx->r12;
    // 0x8002AFB0: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8002AFB4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8002AFB8: or          $t4, $t9, $t7
    ctx->r12 = ctx->r25 | ctx->r15;
    // 0x8002AFBC: sra         $t9, $t5, 8
    ctx->r25 = S32(SIGNED(ctx->r13) >> 8);
    // 0x8002AFC0: andi        $t7, $t9, 0x3
    ctx->r15 = ctx->r25 & 0X3;
    // 0x8002AFC4: or          $t5, $t4, $t7
    ctx->r13 = ctx->r12 | ctx->r15;
    // 0x8002AFC8: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x8002AFCC: lw          $t6, 0x24($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X24);
    // 0x8002AFD0: sw          $zero, 0x24($t6)
    MEM_W(0X24, ctx->r14) = 0;
    // 0x8002AFD4: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    // 0x8002AFD8: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8002AFDC: addiu       $t4, $t9, -0xB8
    ctx->r12 = ADD32(ctx->r25, -0XB8);
    // 0x8002AFE0: b           L_8002B014
    // 0x8002AFE4: sw          $t4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r12;
        goto L_8002B014;
    // 0x8002AFE4: sw          $t4, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r12;
L_8002AFE8:
    // 0x8002AFE8: lw          $t5, 0x4($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X4);
    // 0x8002AFEC: lw          $t7, 0x18($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X18);
    // 0x8002AFF0: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8002AFF4: negu        $t6, $t5
    ctx->r14 = SUB32(0, ctx->r13);
    // 0x8002AFF8: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x8002AFFC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x8002B000: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x8002B004: addiu       $a3, $zero, 0xB8
    ctx->r7 = ADD32(0, 0XB8);
    // 0x8002B008: jal         0x8002AC48
    // 0x8002B00C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    func_8002AC48_2B848(rdram, ctx);
        goto after_3;
    // 0x8002B00C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x8002B010: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_8002B014:
    // 0x8002B014: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002B018: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8002B01C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8002B020: jr          $ra
    // 0x8002B024: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    return;
    // 0x8002B024: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
;}
RECOMP_FUNC void itLinkBombWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185F10: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80185F14: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185F18: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80185F1C: jal         0x801735A0
    // 0x80185F20: addiu       $a1, $a1, 0x5FD8
    ctx->r5 = ADD32(ctx->r5, 0X5FD8);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80185F20: addiu       $a1, $a1, 0x5FD8
    ctx->r5 = ADD32(ctx->r5, 0X5FD8);
    after_0:
    // 0x80185F24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185F28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80185F2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80185F30: jr          $ra
    // 0x80185F34: nop

    return;
    // 0x80185F34: nop

;}
RECOMP_FUNC void func_ovl8_80372224(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372224: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80372228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037222C: lw          $v0, 0xC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XC);
    // 0x80372230: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x80372234: lh          $t6, 0x18($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X18);
    // 0x80372238: jalr        $t9
    // 0x8037223C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037223C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80372240: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80372244: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80372248: jr          $ra
    // 0x8037224C: nop

    return;
    // 0x8037224C: nop

;}
RECOMP_FUNC void func_ovl8_8037FE28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037FE28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037FE2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8037FE30: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8037FE34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037FE38: beq         $a0, $zero, L_8037FEE0
    if (ctx->r4 == 0) {
        // 0x8037FE3C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8037FEE0;
    }
    // 0x8037FE3C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8037FE40: lw          $t8, 0x38($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X38);
    // 0x8037FE44: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037FE48: addiu       $t6, $t6, -0x4E60
    ctx->r14 = ADD32(ctx->r14, -0X4E60);
    // 0x8037FE4C: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8037FE50: addiu       $t7, $t7, -0x4D78
    ctx->r15 = ADD32(ctx->r15, -0X4D78);
    // 0x8037FE54: sw          $t6, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r14;
    // 0x8037FE58: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x8037FE5C: lw          $t0, 0x34($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X34);
    // 0x8037FE60: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037FE64: addiu       $t9, $t9, -0x4C20
    ctx->r25 = ADD32(ctx->r25, -0X4C20);
    // 0x8037FE68: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8037FE6C: addiu       $t1, $t1, -0x4BF8
    ctx->r9 = ADD32(ctx->r9, -0X4BF8);
    // 0x8037FE70: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    // 0x8037FE74: sw          $t1, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->r9;
    // 0x8037FE78: lw          $a0, 0xBC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XBC);
    // 0x8037FE7C: beql        $a0, $zero, L_8037FE90
    if (ctx->r4 == 0) {
        // 0x8037FE80: addiu       $a0, $s0, 0x4C
        ctx->r4 = ADD32(ctx->r16, 0X4C);
            goto L_8037FE90;
    }
    goto skip_0;
    // 0x8037FE80: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
    skip_0:
    // 0x8037FE84: jal         0x8037B3E4
    // 0x8037FE88: nop

    func_ovl8_8037B3E4(rdram, ctx);
        goto after_0;
    // 0x8037FE88: nop

    after_0:
    // 0x8037FE8C: addiu       $a0, $s0, 0x4C
    ctx->r4 = ADD32(ctx->r16, 0X4C);
L_8037FE90:
    // 0x8037FE90: jal         0x80372554
    // 0x8037FE94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_80372554(rdram, ctx);
        goto after_1;
    // 0x8037FE94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8037FE98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8037FE9C: jal         0x8037F4F4
    // 0x8037FEA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_8037F4F4(rdram, ctx);
        goto after_2;
    // 0x8037FEA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8037FEA4: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x8037FEA8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037FEAC: beql        $t2, $zero, L_8037FECC
    if (ctx->r10 == 0) {
        // 0x8037FEB0: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_8037FECC;
    }
    goto skip_1;
    // 0x8037FEB0: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x8037FEB4: jal         0x8037C30C
    // 0x8037FEB8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_3;
    // 0x8037FEB8: lw          $a0, 0x34($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X34);
    after_3:
    // 0x8037FEBC: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x8037FEC0: jal         0x803718C4
    // 0x8037FEC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_4;
    // 0x8037FEC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8037FEC8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_8037FECC:
    // 0x8037FECC: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x8037FED0: beql        $t4, $zero, L_8037FEE4
    if (ctx->r12 == 0) {
        // 0x8037FED4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8037FEE4;
    }
    goto skip_2;
    // 0x8037FED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8037FED8: jal         0x803717C0
    // 0x8037FEDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_5;
    // 0x8037FEDC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
L_8037FEE0:
    // 0x8037FEE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8037FEE4:
    // 0x8037FEE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037FEE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8037FEEC: jr          $ra
    // 0x8037FEF0: nop

    return;
    // 0x8037FEF0: nop

;}
RECOMP_FUNC void func_ovl8_80375D84(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375D84: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80375D88: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80375D8C: lui         $a1, 0x8039
    ctx->r5 = S32(0X8039 << 16);
    // 0x80375D90: addiu       $a1, $a1, -0x1048
    ctx->r5 = ADD32(ctx->r5, -0X1048);
    // 0x80375D94: addiu       $a0, $a0, -0x1050
    ctx->r4 = ADD32(ctx->r4, -0X1050);
    // 0x80375D98: lh          $v0, 0x0($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X0);
    // 0x80375D9C: lh          $v1, 0x0($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X0);
    // 0x80375DA0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80375DA4: beql        $at, $zero, L_80375DB8
    if (ctx->r1 == 0) {
        // 0x80375DA8: lh          $v1, 0x4($a1)
        ctx->r3 = MEM_H(ctx->r5, 0X4);
            goto L_80375DB8;
    }
    goto skip_0;
    // 0x80375DA8: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
    skip_0:
    // 0x80375DAC: b           L_80375DC8
    // 0x80375DB0: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
        goto L_80375DC8;
    // 0x80375DB0: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
    // 0x80375DB4: lh          $v1, 0x4($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X4);
L_80375DB8:
    // 0x80375DB8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80375DBC: beql        $at, $zero, L_80375DCC
    if (ctx->r1 == 0) {
        // 0x80375DC0: lh          $v0, 0x2($a0)
        ctx->r2 = MEM_H(ctx->r4, 0X2);
            goto L_80375DCC;
    }
    goto skip_1;
    // 0x80375DC0: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
    skip_1:
    // 0x80375DC4: sh          $v1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r3;
L_80375DC8:
    // 0x80375DC8: lh          $v0, 0x2($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2);
L_80375DCC:
    // 0x80375DCC: lh          $v1, 0x2($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X2);
    // 0x80375DD0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80375DD4: beql        $at, $zero, L_80375DE8
    if (ctx->r1 == 0) {
        // 0x80375DD8: lh          $v1, 0x6($a1)
        ctx->r3 = MEM_H(ctx->r5, 0X6);
            goto L_80375DE8;
    }
    goto skip_2;
    // 0x80375DD8: lh          $v1, 0x6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X6);
    skip_2:
    // 0x80375DDC: jr          $ra
    // 0x80375DE0: sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
    return;
    // 0x80375DE0: sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
    // 0x80375DE4: lh          $v1, 0x6($a1)
    ctx->r3 = MEM_H(ctx->r5, 0X6);
L_80375DE8:
    // 0x80375DE8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80375DEC: beq         $at, $zero, L_80375DF8
    if (ctx->r1 == 0) {
        // 0x80375DF0: nop
    
            goto L_80375DF8;
    }
    // 0x80375DF0: nop

    // 0x80375DF4: sh          $v1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r3;
L_80375DF8:
    // 0x80375DF8: jr          $ra
    // 0x80375DFC: nop

    return;
    // 0x80375DFC: nop

;}
RECOMP_FUNC void sc1PManagerGetShuffledKirbyCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6554: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800D6558: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800D655C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800D6560: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800D6564: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800D6568:
    // 0x800D6568: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800D656C: sllv        $t7, $t6, $v1
    ctx->r15 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x800D6570: and         $t8, $v0, $t7
    ctx->r24 = ctx->r2 & ctx->r15;
    // 0x800D6574: beq         $t8, $zero, L_800D6580
    if (ctx->r24 == 0) {
        // 0x800D6578: nop
    
            goto L_800D6580;
    }
    // 0x800D6578: nop

    // 0x800D657C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
L_800D6580:
    // 0x800D6580: bnel        $a1, $zero, L_800D6568
    if (ctx->r5 != 0) {
        // 0x800D6584: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D6568;
    }
    goto skip_0;
    // 0x800D6584: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    skip_0:
    // 0x800D6588: jr          $ra
    // 0x800D658C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D658C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void efManagerFlashSmallMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010168C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80101690: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80101694: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101698: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x8010169C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801016A0: jal         0x800CE870
    // 0x801016A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    lbParticleMakeCommon(rdram, ctx);
        goto after_0;
    // 0x801016A4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x801016A8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801016AC: beq         $v0, $zero, L_801016CC
    if (ctx->r2 == 0) {
        // 0x801016B0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801016CC;
    }
    // 0x801016B0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801016B4: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801016B8: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x801016BC: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801016C0: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
    // 0x801016C4: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801016C8: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
L_801016CC:
    // 0x801016CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801016D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801016D4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801016D8: jr          $ra
    // 0x801016DC: nop

    return;
    // 0x801016DC: nop

;}
RECOMP_FUNC void mvOpeningCliffMakeMainCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013214C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80132150: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x80132154: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80132158: addiu       $v0, $v0, 0x7EC0
    ctx->r2 = ADD32(ctx->r2, 0X7EC0);
    // 0x8013215C: addiu       $t6, $zero, 0x50
    ctx->r14 = ADD32(0, 0X50);
    // 0x80132160: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132164: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x80132168: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8013216C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80132170: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132174: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80132178: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x8013217C: sw          $t1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r9;
    // 0x80132180: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80132184: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80132188: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8013218C: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132190: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80132194: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80132198: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x8013219C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801321A0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801321A4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801321A8: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801321AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801321B0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801321B4: jal         0x8000B93C
    // 0x801321B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801321B8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801321BC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801321C0: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x801321C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801321C8: jal         0x80008CF0
    // 0x801321CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_1;
    // 0x801321CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801321D0: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
    // 0x801321D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801321D8: jal         0x80008CF0
    // 0x801321DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_2;
    // 0x801321DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801321E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801321E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801321E8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801321EC: lw          $s0, 0x74($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X74);
    // 0x801321F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801321F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801321F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801321FC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132200: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80132204: jal         0x80007080
    // 0x80132208: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_3;
    // 0x80132208: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_3:
    // 0x8013220C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80132210: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132214: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80132218: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013221C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132220: swc1        $f6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f6.u32l;
    // 0x80132224: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
    // 0x80132228: lw          $t2, 0x2998($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2998);
    // 0x8013222C: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x80132230: addiu       $v0, $v0, -0x76F0
    ctx->r2 = ADD32(ctx->r2, -0X76F0);
    // 0x80132234: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80132238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013223C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132240: jal         0x8000FA3C
    // 0x80132244: addu        $a1, $t2, $v0
    ctx->r5 = ADD32(ctx->r10, ctx->r2);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_4;
    // 0x80132244: addu        $a1, $t2, $v0
    ctx->r5 = ADD32(ctx->r10, ctx->r2);
    after_4:
    // 0x80132248: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013224C: addiu       $a1, $a1, 0x212C
    ctx->r5 = ADD32(ctx->r5, 0X212C);
    // 0x80132250: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80132254: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80132258: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013225C: jal         0x80008188
    // 0x80132260: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80132260: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80132264: lw          $t3, 0x54($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X54);
    // 0x80132268: addiu       $t4, $zero, 0x46
    ctx->r12 = ADD32(0, 0X46);
    // 0x8013226C: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x80132270: lui         $t7, 0x1000
    ctx->r15 = S32(0X1000 << 16);
    // 0x80132274: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80132278: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8013227C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132280: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x80132284: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x80132288: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    // 0x8013228C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80132290: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80132294: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80132298: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013229C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801322A0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801322A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x801322A8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801322AC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801322B0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801322B4: jal         0x8000B93C
    // 0x801322B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    gcMakeCameraGObj(rdram, ctx);
        goto after_6;
    // 0x801322B8: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_6:
    // 0x801322BC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x801322C0: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x801322C4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x801322C8: jal         0x80008CF0
    // 0x801322CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_7;
    // 0x801322CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x801322D0: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
    // 0x801322D4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x801322D8: jal         0x80008CF0
    // 0x801322DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForCamera(rdram, ctx);
        goto after_8;
    // 0x801322DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x801322E0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801322E4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801322E8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801322EC: lw          $s0, 0x74($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X74);
    // 0x801322F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801322F4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801322F8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801322FC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132300: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80132304: jal         0x80007080
    // 0x80132308: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_9;
    // 0x80132308: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_9:
    // 0x8013230C: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80132310: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80132314: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80132318: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8013231C: swc1        $f16, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->f16.u32l;
    // 0x80132320: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132324: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x80132328: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8013232C: lw          $t0, 0x2998($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2998);
    // 0x80132330: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132334: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132338: jal         0x8000FA3C
    // 0x8013233C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_10;
    // 0x8013233C: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_10:
    // 0x80132340: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80132344: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80132348: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013234C: jal         0x80008188
    // 0x80132350: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_11;
    // 0x80132350: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x80132354: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80132358: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8013235C: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80132360: jr          $ra
    // 0x80132364: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80132364: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftFoxSpecialHiUpdateModelPitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015C054: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015C058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015C05C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015C060: lwc1        $f12, 0x48($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8015C064: lwc1        $f14, 0x4C($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X4C);
    // 0x8015C068: jal         0x8001863C
    // 0x8015C06C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    syUtilsArcTan2(rdram, ctx);
        goto after_0;
    // 0x8015C06C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015C070: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8015C074: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015C078: lwc1        $f10, -0x3780($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3780);
    // 0x8015C07C: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x8015C080: lw          $t7, 0x8F8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8F8);
    // 0x8015C084: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8015C088: nop

    // 0x8015C08C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8015C090: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8015C094: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8015C098: swc1        $f16, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f16.u32l;
    // 0x8015C09C: jal         0x800EB528
    // 0x8015C0A0: lw          $a0, 0x8F8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8F8);
    ftParamsUpdateFighterPartsTransformAll(rdram, ctx);
        goto after_1;
    // 0x8015C0A0: lw          $a0, 0x8F8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8F8);
    after_1:
    // 0x8015C0A4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015C0A8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015C0AC: jr          $ra
    // 0x8015C0B0: nop

    return;
    // 0x8015C0B0: nop

;}
RECOMP_FUNC void scStaffrollMakeCrosshairGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801345FC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80134600: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134604: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x80134608: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013460C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80134610: jal         0x80009968
    // 0x80134614: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80134614: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80134618: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013461C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80134620: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80134624: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134628: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013462C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134630: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80134634: jal         0x80009DF4
    // 0x80134638: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80134638: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013463C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134640: addiu       $a1, $a1, 0x43AC
    ctx->r5 = ADD32(ctx->r5, 0X43AC);
    // 0x80134644: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80134648: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013464C: jal         0x80008188
    // 0x80134650: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80134650: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80134654: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134658: lw          $t7, -0x55F0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X55F0);
    // 0x8013465C: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80134660: addiu       $t8, $t8, 0x6D58
    ctx->r24 = ADD32(ctx->r24, 0X6D58);
    // 0x80134664: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80134668: jal         0x800CCFDC
    // 0x8013466C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x8013466C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x80134670: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80134674: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80134678: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013467C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134680: sw          $t9, -0x5734($at)
    MEM_W(-0X5734, ctx->r1) = ctx->r25;
    // 0x80134684: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80134688: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8013468C: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x80134690: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x80134694: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80134698: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013469C: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x801346A0: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x801346A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801346A8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801346AC: jr          $ra
    // 0x801346B0: nop

    return;
    // 0x801346B0: nop

;}
RECOMP_FUNC void ftParamSetTimedHitStatusInvincible(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA8EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800EA8F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800EA8F4: lw          $t6, 0x5A4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5A4);
    // 0x800EA8F8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800EA8FC: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800EA900: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800EA904: beq         $at, $zero, L_800EA910
    if (ctx->r1 == 0) {
        // 0x800EA908: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800EA910;
    }
    // 0x800EA908: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800EA90C: sw          $a1, 0x5A4($a0)
    MEM_W(0X5A4, ctx->r4) = ctx->r5;
L_800EA910:
    // 0x800EA910: lw          $t7, 0x5A8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X5A8);
    // 0x800EA914: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800EA918: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800EA91C: beql        $t7, $zero, L_800EA930
    if (ctx->r15 == 0) {
        // 0x800EA920: sw          $t9, 0x5AC($a3)
        MEM_W(0X5AC, ctx->r7) = ctx->r25;
            goto L_800EA930;
    }
    goto skip_0;
    // 0x800EA920: sw          $t9, 0x5AC($a3)
    MEM_W(0X5AC, ctx->r7) = ctx->r25;
    skip_0:
    // 0x800EA924: b           L_800EA930
    // 0x800EA928: sw          $t8, 0x5AC($a3)
    MEM_W(0X5AC, ctx->r7) = ctx->r24;
        goto L_800EA930;
    // 0x800EA928: sw          $t8, 0x5AC($a3)
    MEM_W(0X5AC, ctx->r7) = ctx->r24;
    // 0x800EA92C: sw          $t9, 0x5AC($a3)
    MEM_W(0X5AC, ctx->r7) = ctx->r25;
L_800EA930:
    // 0x800EA930: jal         0x800E9814
    // 0x800EA934: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x800EA934: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    after_0:
    // 0x800EA938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800EA93C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA940: jr          $ra
    // 0x800EA944: nop

    return;
    // 0x800EA944: nop

;}
RECOMP_FUNC void mpCommonCheckFighterCliff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE7D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE7DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE7E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DE7E4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DE7E8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DE7EC: addiu       $a1, $a1, -0x1BA4
    ctx->r5 = ADD32(ctx->r5, -0X1BA4);
    // 0x800DE7F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800DE7F4: jal         0x800DA034
    // 0x800DE7F8: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DE7F8: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DE7FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE800: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE804: jr          $ra
    // 0x800DE808: nop

    return;
    // 0x800DE808: nop

;}
RECOMP_FUNC void sc1PIntroFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x4E18
    ctx->r24 = ADD32(ctx->r24, 0X4E18);
    // 0x80131B0C: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B10: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B14: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80131B18: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B1C: jr          $ra
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void ftParamSetHitStatusPartAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E880C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8810: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E8814: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800E8818: lw          $a2, 0x84($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X84);
    // 0x800E881C: addiu       $a0, $zero, 0x1E4
    ctx->r4 = ADD32(0, 0X1E4);
    // 0x800E8820: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E8824: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_800E8828:
    // 0x800E8828: lw          $t7, 0x5BC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5BC);
    // 0x800E882C: addiu       $v1, $v1, 0x2C
    ctx->r3 = ADD32(ctx->r3, 0X2C);
    // 0x800E8830: beq         $t7, $zero, L_800E883C
    if (ctx->r15 == 0) {
        // 0x800E8834: nop
    
            goto L_800E883C;
    }
    // 0x800E8834: nop

    // 0x800E8838: sw          $a1, 0x5BC($v0)
    MEM_W(0X5BC, ctx->r2) = ctx->r5;
L_800E883C:
    // 0x800E883C: bne         $v1, $a0, L_800E8828
    if (ctx->r3 != ctx->r4) {
        // 0x800E8840: addiu       $v0, $v0, 0x2C
        ctx->r2 = ADD32(ctx->r2, 0X2C);
            goto L_800E8828;
    }
    // 0x800E8840: addiu       $v0, $v0, 0x2C
    ctx->r2 = ADD32(ctx->r2, 0X2C);
    // 0x800E8844: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E8848: bnel        $a1, $at, L_800E8864
    if (ctx->r5 != ctx->r1) {
        // 0x800E884C: lbu         $t1, 0x18C($a2)
        ctx->r9 = MEM_BU(ctx->r6, 0X18C);
            goto L_800E8864;
    }
    goto skip_0;
    // 0x800E884C: lbu         $t1, 0x18C($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X18C);
    skip_0:
    // 0x800E8850: lbu         $t8, 0x18C($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X18C);
    // 0x800E8854: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x800E8858: b           L_800E886C
    // 0x800E885C: sb          $t9, 0x18C($a2)
    MEM_B(0X18C, ctx->r6) = ctx->r25;
        goto L_800E886C;
    // 0x800E885C: sb          $t9, 0x18C($a2)
    MEM_B(0X18C, ctx->r6) = ctx->r25;
    // 0x800E8860: lbu         $t1, 0x18C($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X18C);
L_800E8864:
    // 0x800E8864: ori         $t2, $t1, 0x40
    ctx->r10 = ctx->r9 | 0X40;
    // 0x800E8868: sb          $t2, 0x18C($a2)
    MEM_B(0X18C, ctx->r6) = ctx->r10;
L_800E886C:
    // 0x800E886C: jal         0x800E87A0
    // 0x800E8870: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftParamSetHitStatusColAnim(rdram, ctx);
        goto after_0;
    // 0x800E8870: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_0:
    // 0x800E8874: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8878: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E887C: jr          $ra
    // 0x800E8880: nop

    return;
    // 0x800E8880: nop

;}
RECOMP_FUNC void wpYoshiStarProcReflector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016C7B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8016C7B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016C7B8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8016C7BC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016C7C0: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x8016C7C4: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8016C7C8: lw          $a1, 0x84($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X84);
    // 0x8016C7CC: sw          $t7, 0x268($a0)
    MEM_W(0X268, ctx->r4) = ctx->r15;
    // 0x8016C7D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8016C7D4: jal         0x801680EC
    // 0x8016C7D8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    wpMainReflectorSetLR(rdram, ctx);
        goto after_0;
    // 0x8016C7D8: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016C7DC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C7E0: lwc1        $f12, 0x24($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0X24);
    // 0x8016C7E4: jal         0x8001863C
    // 0x8016C7E8: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8016C7E8: lwc1        $f14, 0x20($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X20);
    after_1:
    // 0x8016C7EC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8016C7F0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8016C7F4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8016C7F8: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x8016C7FC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8016C800: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8016C804: swc1        $f0, 0x38($t8)
    MEM_W(0X38, ctx->r24) = ctx->f0.u32l;
    // 0x8016C808: lw          $t9, 0x74($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X74);
    // 0x8016C80C: swc1        $f2, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f2.u32l;
    // 0x8016C810: lw          $t0, 0x74($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X74);
    // 0x8016C814: swc1        $f2, 0x44($t0)
    MEM_W(0X44, ctx->r8) = ctx->f2.u32l;
    // 0x8016C818: lw          $t1, 0x18($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X18);
    // 0x8016C81C: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8016C820: sw          $t2, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r10;
    // 0x8016C824: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016C828: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8016C82C: jr          $ra
    // 0x8016C830: nop

    return;
    // 0x8016C830: nop

;}
RECOMP_FUNC void ftPikachuSpecialLwHitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801524A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801524A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801524AC: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801524B0: jal         0x800DDE84
    // 0x801524B4: addiu       $a1, $a1, 0x252C
    ctx->r5 = ADD32(ctx->r5, 0X252C);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x801524B4: addiu       $a1, $a1, 0x252C
    ctx->r5 = ADD32(ctx->r5, 0X252C);
    after_0:
    // 0x801524B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801524BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801524C0: jr          $ra
    // 0x801524C4: nop

    return;
    // 0x801524C4: nop

;}
RECOMP_FUNC void scStaffrollFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801334E4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801334E8: lw          $t6, -0x56F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X56F8);
    // 0x801334EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801334F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801334F4: beq         $t6, $zero, L_80133514
    if (ctx->r14 == 0) {
        // 0x801334F8: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80133514;
    }
    // 0x801334F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801334FC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80133500: lw          $v0, -0x5740($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5740);
    // 0x80133504: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133508: beq         $v0, $at, L_80133608
    if (ctx->r2 == ctx->r1) {
        // 0x8013350C: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80133608;
    }
    // 0x8013350C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80133510: beq         $v0, $at, L_80133608
    if (ctx->r2 == ctx->r1) {
        // 0x80133514: lui         $t7, 0x8014
        ctx->r15 = S32(0X8014 << 16);
            goto L_80133608;
    }
L_80133514:
    // 0x80133514: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133518: lbu         $t7, -0x56FC($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X56FC);
    // 0x8013351C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80133520: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80133524: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80133528: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8013352C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x80133530: lw          $t0, -0x5740($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5740);
    // 0x80133534: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80133538: lhu         $t9, 0x522A($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X522A);
    // 0x8013353C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133540: bne         $t0, $at, L_80133580
    if (ctx->r8 != ctx->r1) {
        // 0x80133544: sh          $t9, 0x1A($sp)
        MEM_H(0X1A, ctx->r29) = ctx->r25;
            goto L_80133580;
    }
    // 0x80133544: sh          $t9, 0x1A($sp)
    MEM_H(0X1A, ctx->r29) = ctx->r25;
    // 0x80133548: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8013354C: addiu       $v1, $v1, -0x5700
    ctx->r3 = ADD32(ctx->r3, -0X5700);
    // 0x80133550: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133554: slti        $at, $v0, 0x78
    ctx->r1 = SIGNED(ctx->r2) < 0X78 ? 1 : 0;
    // 0x80133558: beq         $at, $zero, L_80133568
    if (ctx->r1 == 0) {
        // 0x8013355C: addiu       $t1, $v0, 0x1
        ctx->r9 = ADD32(ctx->r2, 0X1);
            goto L_80133568;
    }
    // 0x8013355C: addiu       $t1, $v0, 0x1
    ctx->r9 = ADD32(ctx->r2, 0X1);
    // 0x80133560: b           L_80133580
    // 0x80133564: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_80133580;
    // 0x80133564: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_80133568:
    // 0x80133568: jal         0x801346B4
    // 0x8013356C: nop

    scStaffrollMakeTextBoxBracketSObjs(rdram, ctx);
        goto after_0;
    // 0x8013356C: nop

    after_0:
    // 0x80133570: jal         0x801347F4
    // 0x80133574: nop

    scStaffrollMakeTextBoxGObj(rdram, ctx);
        goto after_1;
    // 0x80133574: nop

    after_1:
    // 0x80133578: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x8013357C: sw          $zero, -0x5740($at)
    MEM_W(-0X5740, ctx->r1) = 0;
L_80133580:
    // 0x80133580: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80133584: lw          $v1, -0x5730($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5730);
    // 0x80133588: bne         $v1, $zero, L_801335A4
    if (ctx->r3 != 0) {
        // 0x8013358C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_801335A4;
    }
    // 0x8013358C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80133590: jal         0x8013341C
    // 0x80133594: nop

    scStaffrollGetPauseStatusHighlight(rdram, ctx);
        goto after_2;
    // 0x80133594: nop

    after_2:
    // 0x80133598: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x8013359C: lw          $v1, -0x5730($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5730);
    // 0x801335A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_801335A4:
    // 0x801335A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801335A8: bnel        $v1, $at, L_801335C0
    if (ctx->r3 != ctx->r1) {
        // 0x801335AC: lhu         $t2, 0x1A($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X1A);
            goto L_801335C0;
    }
    goto skip_0;
    // 0x801335AC: lhu         $t2, 0x1A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1A);
    skip_0:
    // 0x801335B0: jal         0x80131B00
    // 0x801335B4: nop

    scStaffrollGetPauseStatusResume(rdram, ctx);
        goto after_3;
    // 0x801335B4: nop

    after_3:
    // 0x801335B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801335BC: lhu         $t2, 0x1A($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X1A);
L_801335C0:
    // 0x801335C0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801335C4: sw          $a0, -0x5730($at)
    MEM_W(-0X5730, ctx->r1) = ctx->r4;
    // 0x801335C8: andi        $t3, $t2, 0x1000
    ctx->r11 = ctx->r10 & 0X1000;
    // 0x801335CC: beq         $t3, $zero, L_80133608
    if (ctx->r11 == 0) {
        // 0x801335D0: lui         $v0, 0x8014
        ctx->r2 = S32(0X8014 << 16);
            goto L_80133608;
    }
    // 0x801335D0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801335D4: addiu       $v0, $v0, -0x5744
    ctx->r2 = ADD32(ctx->r2, -0X5744);
    // 0x801335D8: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801335DC: lwc1        $f0, -0x5850($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5850);
    // 0x801335E0: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x801335E4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801335E8: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x801335EC: nop

    // 0x801335F0: bc1fl       L_80133608
    if (!c1cs) {
        // 0x801335F4: swc1        $f0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
            goto L_80133608;
    }
    goto skip_1;
    // 0x801335F4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    skip_1:
    // 0x801335F8: lwc1        $f6, -0x584C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X584C);
    // 0x801335FC: b           L_80133608
    // 0x80133600: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
        goto L_80133608;
    // 0x80133600: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80133604: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
L_80133608:
    // 0x80133608: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013360C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80133610: jr          $ra
    // 0x80133614: nop

    return;
    // 0x80133614: nop

;}
RECOMP_FUNC void ftKirbySpecialLwStartProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801618C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801618C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801618CC: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x801618D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801618D4: jal         0x800DDDA8
    // 0x801618D8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x801618D8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801618DC: bnel        $v0, $zero, L_80161914
    if (ctx->r2 != 0) {
        // 0x801618E0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80161914;
    }
    goto skip_0;
    // 0x801618E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801618E4: jal         0x800DEEC8
    // 0x801618E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_1;
    // 0x801618E8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x801618EC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801618F0: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x801618F4: addiu       $a1, $zero, 0x108
    ctx->r5 = ADD32(0, 0X108);
    // 0x801618F8: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801618FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80161900: jal         0x800E6F24
    // 0x80161904: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80161904: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80161908: jal         0x80161468
    // 0x8016190C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftKirbySpecialLwSetDropFallVel(rdram, ctx);
        goto after_3;
    // 0x8016190C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80161910: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80161914:
    // 0x80161914: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80161918: jr          $ra
    // 0x8016191C: nop

    return;
    // 0x8016191C: nop

;}
RECOMP_FUNC void itRShellMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B1D8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8017B1DC: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8017B1E0: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x8017B1E4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8017B1E8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8017B1EC: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x8017B1F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8017B1F4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017B1F8: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8017B1FC: addiu       $a1, $a1, -0x5A90
    ctx->r5 = ADD32(ctx->r5, -0X5A90);
    // 0x8017B200: jal         0x8016E174
    // 0x8017B204: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x8017B204: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8017B208: beq         $v0, $zero, L_8017B2E4
    if (ctx->r2 == 0) {
        // 0x8017B20C: sw          $v0, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r2;
            goto L_8017B2E4;
    }
    // 0x8017B20C: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x8017B210: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x8017B214: addiu       $t8, $sp, 0x28
    ctx->r24 = ADD32(ctx->r29, 0X28);
    // 0x8017B218: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017B21C: addiu       $v0, $a0, 0x1C
    ctx->r2 = ADD32(ctx->r4, 0X1C);
    // 0x8017B220: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8017B224: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x8017B228: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8017B22C: sw          $t0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r8;
    // 0x8017B230: lw          $t9, 0x4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4);
    // 0x8017B234: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x8017B238: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8017B23C: sw          $t0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r8;
    // 0x8017B240: lwc1        $f4, -0x3254($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3254);
    // 0x8017B244: swc1        $f4, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->f4.u32l;
    // 0x8017B248: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8017B24C: jal         0x80008CC0
    // 0x8017B250: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x8017B250: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    after_1:
    // 0x8017B254: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x8017B258: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x8017B25C: jal         0x80008CC0
    // 0x8017B260: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x8017B260: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8017B264: addiu       $t2, $sp, 0x28
    ctx->r10 = ADD32(ctx->r29, 0X28);
    // 0x8017B268: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8017B26C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8017B270: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8017B274: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8017B278: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x8017B27C: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8017B280: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017B284: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8017B288: sw          $t3, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r11;
    // 0x8017B28C: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x8017B290: sw          $t4, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r12;
    // 0x8017B294: lw          $t5, 0x80($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X80);
    // 0x8017B298: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8017B29C: swc1        $f6, 0x88($t5)
    MEM_W(0X88, ctx->r13) = ctx->f6.u32l;
    // 0x8017B2A0: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8017B2A4: lw          $a0, 0x84($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X84);
    // 0x8017B2A8: lbu         $t8, 0x158($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X158);
    // 0x8017B2AC: lbu         $t3, 0x2D3($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X2D3);
    // 0x8017B2B0: sb          $t0, 0x352($a0)
    MEM_B(0X352, ctx->r4) = ctx->r8;
    // 0x8017B2B4: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8017B2B8: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8017B2BC: sb          $t9, 0x158($a0)
    MEM_B(0X158, ctx->r4) = ctx->r25;
    // 0x8017B2C0: sb          $zero, 0x354($a0)
    MEM_B(0X354, ctx->r4) = 0;
    // 0x8017B2C4: sb          $zero, 0x353($a0)
    MEM_B(0X353, ctx->r4) = 0;
    // 0x8017B2C8: sb          $t1, 0x350($a0)
    MEM_B(0X350, ctx->r4) = ctx->r9;
    // 0x8017B2CC: swc1        $f8, 0x358($a0)
    MEM_W(0X358, ctx->r4) = ctx->f8.u32l;
    // 0x8017B2D0: sb          $t4, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r12;
    // 0x8017B2D4: jal         0x80111EC0
    // 0x8017B2D8: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_3;
    // 0x8017B2D8: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_3:
    // 0x8017B2DC: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8017B2E0: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_8017B2E4:
    // 0x8017B2E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8017B2E8: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8017B2EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8017B2F0: jr          $ra
    // 0x8017B2F4: nop

    return;
    // 0x8017B2F4: nop

;}
RECOMP_FUNC void ftKirbyCopyFoxSpecialNInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156DC8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156DCC: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80156DD0: jr          $ra
    // 0x80156DD4: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    return;
    // 0x80156DD4: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
;}
RECOMP_FUNC void itMSBombThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80176644: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80176648: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017664C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80176650: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80176654: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80176658: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x8017665C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80176660: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80176664: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80176668: addiu       $a1, $a1, -0x617C
    ctx->r5 = ADD32(ctx->r5, -0X617C);
    // 0x8017666C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80176670: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x80176674: swc1        $f0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->f0.u32l;
    // 0x80176678: swc1        $f4, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->f4.u32l;
    // 0x8017667C: jal         0x80172EC8
    // 0x80176680: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80176680: swc1        $f6, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->f6.u32l;
    after_0:
    // 0x80176684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80176688: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017668C: jr          $ra
    // 0x80176690: nop

    return;
    // 0x80176690: nop

;}
RECOMP_FUNC void ftCommonDamageUpdateDustEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140454: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80140458: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8014045C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80140460: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80140464: lw          $v0, 0xB1C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0XB1C);
    // 0x80140468: beq         $v0, $zero, L_801404A4
    if (ctx->r2 == 0) {
        // 0x8014046C: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_801404A4;
    }
    // 0x8014046C: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80140470: bne         $t6, $zero, L_801404A4
    if (ctx->r14 != 0) {
        // 0x80140474: sw          $t6, 0xB1C($s0)
        MEM_W(0XB1C, ctx->r16) = ctx->r14;
            goto L_801404A4;
    }
    // 0x80140474: sw          $t6, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r14;
    // 0x80140478: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014047C: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x80140480: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80140484: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80140488: addiu       $a1, $zero, 0x11
    ctx->r5 = ADD32(0, 0X11);
    // 0x8014048C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80140490: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80140494: jal         0x800EABDC
    // 0x80140498: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    ftParamMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80140498: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_0:
    // 0x8014049C: jal         0x80140340
    // 0x801404A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDamageSetDustEffectInterval(rdram, ctx);
        goto after_1;
    // 0x801404A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_801404A4:
    // 0x801404A4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x801404A8: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x801404AC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801404B0: jr          $ra
    // 0x801404B4: nop

    return;
    // 0x801404B4: nop

;}
RECOMP_FUNC void mnVSOptionsMakeHandicapOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132AC8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132ACC: lw          $t6, 0x4904($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4904);
    // 0x80132AD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132AD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132AD8: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80132ADC: beq         $t6, $zero, L_80132AEC
    if (ctx->r14 == 0) {
        // 0x80132AE0: sw          $s0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r16;
            goto L_80132AEC;
    }
    // 0x80132AE0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80132AE4: b           L_80132AF0
    // 0x80132AE8: addiu       $s1, $zero, 0x3D
    ctx->r17 = ADD32(0, 0X3D);
        goto L_80132AF0;
    // 0x80132AE8: addiu       $s1, $zero, 0x3D
    ctx->r17 = ADD32(0, 0X3D);
L_80132AEC:
    // 0x80132AEC: addiu       $s1, $zero, 0x41
    ctx->r17 = ADD32(0, 0X41);
L_80132AF0:
    // 0x80132AF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132AF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132AF8: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80132AFC: jal         0x80009968
    // 0x80132B00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132B00: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132B04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B08: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132B0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80132B10: sw          $v0, 0x48C0($at)
    MEM_W(0X48C0, ctx->r1) = ctx->r2;
    // 0x80132B14: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132B18: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80132B1C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132B20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132B24: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132B28: jal         0x80009DF4
    // 0x80132B2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132B2C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132B30: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132B34: lw          $t8, 0x49DC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X49DC);
    // 0x80132B38: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80132B3C: addiu       $t9, $t9, 0x33D8
    ctx->r25 = ADD32(ctx->r25, 0X33D8);
    // 0x80132B40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132B44: jal         0x800CCFDC
    // 0x80132B48: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132B48: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80132B4C: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x80132B50: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80132B54: lui         $at, 0x42E4
    ctx->r1 = S32(0X42E4 << 16);
    // 0x80132B58: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80132B5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132B60: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80132B64: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132B68: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80132B6C: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80132B70: swc1        $f8, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f8.u32l;
    // 0x80132B74: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132B78: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132B7C: lw          $a1, 0x48E0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E0);
    // 0x80132B80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132B84: jal         0x80131F74
    // 0x80132B88: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnVSOptionsSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80132B88: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x80132B8C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132B90: lw          $t4, 0x49DC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X49DC);
    // 0x80132B94: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80132B98: addiu       $t5, $t5, 0x3690
    ctx->r13 = ADD32(ctx->r13, 0X3690);
    // 0x80132B9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132BA0: jal         0x800CCFDC
    // 0x80132BA4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132BA4: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_4:
    // 0x80132BA8: addiu       $t1, $s1, 0x1
    ctx->r9 = ADD32(ctx->r17, 0X1);
    // 0x80132BAC: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80132BB0: addiu       $t0, $s1, 0x2
    ctx->r8 = ADD32(ctx->r17, 0X2);
    // 0x80132BB4: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x80132BB8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132BBC: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132BC0: lui         $at, 0x42F2
    ctx->r1 = S32(0X42F2 << 16);
    // 0x80132BC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132BC8: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80132BCC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80132BD0: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132BD4: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80132BD8: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80132BDC: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132BE0: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132BE4: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x80132BE8: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132BEC: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132BF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132BF4: lui         $a1, 0x433F
    ctx->r5 = S32(0X433F << 16);
    // 0x80132BF8: jal         0x801322B8
    // 0x80132BFC: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    mnVSOptionsMakeHandicapToggle(rdram, ctx);
        goto after_5;
    // 0x80132BFC: swc1        $f10, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f10.u32l;
    after_5:
    // 0x80132C00: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132C04: lw          $a1, 0x48E4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E4);
    // 0x80132C08: jal         0x80132184
    // 0x80132C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSOptionsSetHandicapSpriteColors(rdram, ctx);
        goto after_6;
    // 0x80132C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x80132C10: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132C14: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80132C18: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80132C1C: jr          $ra
    // 0x80132C20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80132C20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonThrownUpdateDamageStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014B2AC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014B2B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014B2B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8014B2B8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8014B2BC: lw          $v0, 0x844($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X844);
    // 0x8014B2C0: lw          $s0, 0x84($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X84);
    // 0x8014B2C4: lw          $v1, 0x848($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X848);
    // 0x8014B2C8: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    // 0x8014B2CC: lw          $a2, 0x288($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X288);
    // 0x8014B2D0: lhu         $a3, 0x28C($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X28C);
    // 0x8014B2D4: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x8014B2D8: jal         0x800EA54C
    // 0x8014B2DC: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    ftParamGetStaledDamage(rdram, ctx);
        goto after_0;
    // 0x8014B2DC: lw          $a1, 0x4($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X4);
    after_0:
    // 0x8014B2E0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8014B2E4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8014B2E8: jal         0x800EA248
    // 0x8014B2EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamUpdateDamage(rdram, ctx);
        goto after_1;
    // 0x8014B2EC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x8014B2F0: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8014B2F4: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    // 0x8014B2F8: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8014B2FC: jal         0x800EA98C
    // 0x8014B300: lbu         $a1, 0xD($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0XD);
    ftParamUpdatePlayerBattleStats(rdram, ctx);
        goto after_2;
    // 0x8014B300: lbu         $a1, 0xD($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0XD);
    after_2:
    // 0x8014B304: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8014B308: lbu         $a0, 0xD($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XD);
    // 0x8014B30C: lw          $a2, 0x288($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X288);
    // 0x8014B310: lhu         $a3, 0x28C($s0)
    ctx->r7 = MEM_HU(ctx->r16, 0X28C);
    // 0x8014B314: jal         0x800EA614
    // 0x8014B318: lbu         $a1, 0xD($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0XD);
    ftParamUpdateStaleQueue(rdram, ctx);
        goto after_3;
    // 0x8014B318: lbu         $a1, 0xD($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0XD);
    after_3:
    // 0x8014B31C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014B320: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8014B324: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8014B328: jr          $ra
    // 0x8014B32C: nop

    return;
    // 0x8014B32C: nop

;}
RECOMP_FUNC void mnPlayersVSSetPortraitWallpaperPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F54: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80131F58: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131F5C: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80131F60: addiu       $t6, $t6, -0x4BB0
    ctx->r14 = ADD32(ctx->r14, -0X4BB0);
    // 0x80131F64: addiu       $t0, $t6, 0x60
    ctx->r8 = ADD32(ctx->r14, 0X60);
    // 0x80131F68: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80131F6C:
    // 0x80131F6C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131F70: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131F74: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131F78: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131F7C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131F80: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131F84: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131F88: bne         $t6, $t0, L_80131F6C
    if (ctx->r14 != ctx->r8) {
        // 0x80131F8C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131F6C;
    }
    // 0x80131F8C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131F90: sll         $t1, $a1, 3
    ctx->r9 = S32(ctx->r5 << 3);
    // 0x80131F94: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x80131F98: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80131F9C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80131FA0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80131FA4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80131FA8: jr          $ra
    // 0x80131FAC: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80131FAC: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void func_ovl8_80387C24(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80387C24: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80387C28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80387C2C: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80387C30: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80387C34: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80387C38: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80387C3C: nop

    // 0x80387C40: bc1tl       L_80387C84
    if (c1cs) {
        // 0x80387C44: lw          $v0, 0xB4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XB4);
            goto L_80387C84;
    }
    goto skip_0;
    // 0x80387C44: lw          $v0, 0xB4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB4);
    skip_0:
    // 0x80387C48: lw          $t6, 0xD0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XD0);
    // 0x80387C4C: bnel        $t6, $zero, L_80387C64
    if (ctx->r14 != 0) {
        // 0x80387C50: lw          $v0, 0xB0($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XB0);
            goto L_80387C64;
    }
    goto skip_1;
    // 0x80387C50: lw          $v0, 0xB0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB0);
    skip_1:
    // 0x80387C54: lh          $t7, 0x1E($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X1E);
    // 0x80387C58: beql        $t7, $zero, L_80387C84
    if (ctx->r15 == 0) {
        // 0x80387C5C: lw          $v0, 0xB4($a1)
        ctx->r2 = MEM_W(ctx->r5, 0XB4);
            goto L_80387C84;
    }
    goto skip_2;
    // 0x80387C5C: lw          $v0, 0xB4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB4);
    skip_2:
    // 0x80387C60: lw          $v0, 0xB0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB0);
L_80387C64:
    // 0x80387C64: beql        $v0, $zero, L_80387C78
    if (ctx->r2 == 0) {
        // 0x80387C68: lw          $v1, 0xB4($a1)
        ctx->r3 = MEM_W(ctx->r5, 0XB4);
            goto L_80387C78;
    }
    goto skip_3;
    // 0x80387C68: lw          $v1, 0xB4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XB4);
    skip_3:
    // 0x80387C6C: b           L_80387C88
    // 0x80387C70: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
        goto L_80387C88;
    // 0x80387C70: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
    // 0x80387C74: lw          $v1, 0xB4($a1)
    ctx->r3 = MEM_W(ctx->r5, 0XB4);
L_80387C78:
    // 0x80387C78: b           L_80387C84
    // 0x80387C7C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80387C84;
    // 0x80387C7C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80387C80: lw          $v0, 0xB4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0XB4);
L_80387C84:
    // 0x80387C84: sw          $v0, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->r2;
L_80387C88:
    // 0x80387C88: jal         0x803725DC
    // 0x80387C8C: addiu       $a0, $a1, 0x40
    ctx->r4 = ADD32(ctx->r5, 0X40);
    func_ovl8_803725DC(rdram, ctx);
        goto after_0;
    // 0x80387C8C: addiu       $a0, $a1, 0x40
    ctx->r4 = ADD32(ctx->r5, 0X40);
    after_0:
    // 0x80387C90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80387C94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80387C98: jr          $ra
    // 0x80387C9C: nop

    return;
    // 0x80387C9C: nop

;}
RECOMP_FUNC void mvOpeningCliffWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D8C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131D90: lw          $a1, 0x27CC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X27CC);
    // 0x80131D94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80131D98: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131D9C: beq         $a1, $at, L_80131DD0
    if (ctx->r5 == ctx->r1) {
        // 0x80131DA0: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80131DD0;
    }
    // 0x80131DA0: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80131DA4: addiu       $at, $zero, 0x50
    ctx->r1 = ADD32(0, 0X50);
    // 0x80131DA8: beq         $v1, $at, L_80131DE8
    if (ctx->r3 == ctx->r1) {
        // 0x80131DAC: addiu       $at, $zero, 0x5A
        ctx->r1 = ADD32(0, 0X5A);
            goto L_80131DE8;
    }
    // 0x80131DAC: addiu       $at, $zero, 0x5A
    ctx->r1 = ADD32(0, 0X5A);
    // 0x80131DB0: beq         $v1, $at, L_80131E00
    if (ctx->r3 == ctx->r1) {
        // 0x80131DB4: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_80131E00;
    }
    // 0x80131DB4: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80131DB8: beq         $v1, $at, L_80131E18
    if (ctx->r3 == ctx->r1) {
        // 0x80131DBC: addiu       $at, $zero, 0xB4
        ctx->r1 = ADD32(0, 0XB4);
            goto L_80131E18;
    }
    // 0x80131DBC: addiu       $at, $zero, 0xB4
    ctx->r1 = ADD32(0, 0XB4);
    // 0x80131DC0: beq         $v1, $at, L_80131E30
    if (ctx->r3 == ctx->r1) {
        // 0x80131DC4: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_80131E30;
    }
    // 0x80131DC4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131DC8: b           L_80131E40
    // 0x80131DCC: addiu       $v1, $v1, 0x27D8
    ctx->r3 = ADD32(ctx->r3, 0X27D8);
        goto L_80131E40;
    // 0x80131DCC: addiu       $v1, $v1, 0x27D8
    ctx->r3 = ADD32(ctx->r3, 0X27D8);
L_80131DD0:
    // 0x80131DD0: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80131DD4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131DD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131DDC: addiu       $v1, $v1, 0x27D8
    ctx->r3 = ADD32(ctx->r3, 0X27D8);
    // 0x80131DE0: b           L_80131E40
    // 0x80131DE4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
        goto L_80131E40;
    // 0x80131DE4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
L_80131DE8:
    // 0x80131DE8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80131DEC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131DF0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131DF4: addiu       $v1, $v1, 0x27D8
    ctx->r3 = ADD32(ctx->r3, 0X27D8);
    // 0x80131DF8: b           L_80131E40
    // 0x80131DFC: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
        goto L_80131E40;
    // 0x80131DFC: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_80131E00:
    // 0x80131E00: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80131E04: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131E08: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131E0C: addiu       $v1, $v1, 0x27D8
    ctx->r3 = ADD32(ctx->r3, 0X27D8);
    // 0x80131E10: b           L_80131E40
    // 0x80131E14: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
        goto L_80131E40;
    // 0x80131E14: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
L_80131E18:
    // 0x80131E18: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80131E1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131E20: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131E24: addiu       $v1, $v1, 0x27D8
    ctx->r3 = ADD32(ctx->r3, 0X27D8);
    // 0x80131E28: b           L_80131E40
    // 0x80131E2C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
        goto L_80131E40;
    // 0x80131E2C: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
L_80131E30:
    // 0x80131E30: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80131E34: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131E38: addiu       $v1, $v1, 0x27D8
    ctx->r3 = ADD32(ctx->r3, 0X27D8);
    // 0x80131E3C: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
L_80131E40:
    // 0x80131E40: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80131E44: bne         $at, $zero, L_80131E64
    if (ctx->r1 != 0) {
        // 0x80131E48: slti        $at, $a1, 0x50
        ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
            goto L_80131E64;
    }
    // 0x80131E48: slti        $at, $a1, 0x50
    ctx->r1 = SIGNED(ctx->r5) < 0X50 ? 1 : 0;
    // 0x80131E4C: beq         $at, $zero, L_80131E64
    if (ctx->r1 == 0) {
        // 0x80131E50: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80131E64;
    }
    // 0x80131E50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E54: lwc1        $f4, 0x27B0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X27B0);
    // 0x80131E58: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131E5C: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80131E60: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_80131E64:
    // 0x80131E64: slti        $at, $a1, 0x51
    ctx->r1 = SIGNED(ctx->r5) < 0X51 ? 1 : 0;
    // 0x80131E68: bne         $at, $zero, L_80131E88
    if (ctx->r1 != 0) {
        // 0x80131E6C: slti        $at, $a1, 0x5A
        ctx->r1 = SIGNED(ctx->r5) < 0X5A ? 1 : 0;
            goto L_80131E88;
    }
    // 0x80131E6C: slti        $at, $a1, 0x5A
    ctx->r1 = SIGNED(ctx->r5) < 0X5A ? 1 : 0;
    // 0x80131E70: beq         $at, $zero, L_80131E88
    if (ctx->r1 == 0) {
        // 0x80131E74: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80131E88;
    }
    // 0x80131E74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E78: lwc1        $f10, 0x27B4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X27B4);
    // 0x80131E7C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131E80: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131E84: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
L_80131E88:
    // 0x80131E88: slti        $at, $a1, 0x5B
    ctx->r1 = SIGNED(ctx->r5) < 0X5B ? 1 : 0;
    // 0x80131E8C: bne         $at, $zero, L_80131EAC
    if (ctx->r1 != 0) {
        // 0x80131E90: slti        $at, $a1, 0x78
        ctx->r1 = SIGNED(ctx->r5) < 0X78 ? 1 : 0;
            goto L_80131EAC;
    }
    // 0x80131E90: slti        $at, $a1, 0x78
    ctx->r1 = SIGNED(ctx->r5) < 0X78 ? 1 : 0;
    // 0x80131E94: beq         $at, $zero, L_80131EAC
    if (ctx->r1 == 0) {
        // 0x80131E98: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80131EAC;
    }
    // 0x80131E98: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E9C: lwc1        $f4, 0x27B8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X27B8);
    // 0x80131EA0: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131EA4: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80131EA8: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
L_80131EAC:
    // 0x80131EAC: slti        $at, $a1, 0x79
    ctx->r1 = SIGNED(ctx->r5) < 0X79 ? 1 : 0;
    // 0x80131EB0: bne         $at, $zero, L_80131ED0
    if (ctx->r1 != 0) {
        // 0x80131EB4: slti        $at, $a1, 0xB4
        ctx->r1 = SIGNED(ctx->r5) < 0XB4 ? 1 : 0;
            goto L_80131ED0;
    }
    // 0x80131EB4: slti        $at, $a1, 0xB4
    ctx->r1 = SIGNED(ctx->r5) < 0XB4 ? 1 : 0;
    // 0x80131EB8: beq         $at, $zero, L_80131ED0
    if (ctx->r1 == 0) {
        // 0x80131EBC: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80131ED0;
    }
    // 0x80131EBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131EC0: lwc1        $f10, 0x27BC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X27BC);
    // 0x80131EC4: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131EC8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80131ECC: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
L_80131ED0:
    // 0x80131ED0: lwc1        $f18, 0x58($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131ED4: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131ED8: lui         $at, 0xC3A0
    ctx->r1 = S32(0XC3A0 << 16);
    // 0x80131EDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131EE0: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80131EE4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x80131EE8: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x80131EEC: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131EF0: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80131EF4: nop

    // 0x80131EF8: bc1fl       L_80131F18
    if (!c1cs) {
        // 0x80131EFC: lui         $at, 0x43A0
        ctx->r1 = S32(0X43A0 << 16);
            goto L_80131F18;
    }
    goto skip_0;
    // 0x80131EFC: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    skip_0:
    // 0x80131F00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131F04: nop

    // 0x80131F08: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80131F0C: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80131F10: lwc1        $f0, 0x58($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X58);
    // 0x80131F14: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
L_80131F18:
    // 0x80131F18: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80131F1C: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x80131F20: add.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x80131F24: jr          $ra
    // 0x80131F28: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    return;
    // 0x80131F28: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
;}
RECOMP_FUNC void func_ovl8_803722F0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803722F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803722F4: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x803722F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803722FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80372300: addiu       $t6, $t6, -0x7368
    ctx->r14 = ADD32(ctx->r14, -0X7368);
    // 0x80372304: lwl         $t8, 0x0($t6)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r14, 0X0);
    // 0x80372308: lwr         $t8, 0x3($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X3);
    // 0x8037230C: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80372310: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80372314: swl         $t8, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r24);
    // 0x80372318: swr         $t8, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r24);
    // 0x8037231C: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x80372320: lw          $v0, 0xC($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XC);
    // 0x80372324: lh          $t0, 0x28($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X28);
    // 0x80372328: addu        $a0, $t0, $t9
    ctx->r4 = ADD32(ctx->r8, ctx->r25);
    // 0x8037232C: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80372330: jalr        $t9
    // 0x80372334: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80372334: nop

    after_0:
    // 0x80372338: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037233C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80372340: jr          $ra
    // 0x80372344: nop

    return;
    // 0x80372344: nop

;}
RECOMP_FUNC void ftCommonCliffSlowProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144F64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144F68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144F6C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80144F70: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80144F74: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80144F78: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80144F7C: nop

    // 0x80144F80: bc1fl       L_80144FDC
    if (!c1cs) {
        // 0x80144F84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80144FDC;
    }
    goto skip_0;
    // 0x80144F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80144F88: lw          $v0, 0xB18($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XB18);
    // 0x80144F8C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80144F90: beq         $v0, $at, L_80144FB0
    if (ctx->r2 == ctx->r1) {
        // 0x80144F94: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80144FB0;
    }
    // 0x80144F94: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80144F98: beq         $v0, $at, L_80144FC0
    if (ctx->r2 == ctx->r1) {
        // 0x80144F9C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80144FC0;
    }
    // 0x80144F9C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80144FA0: beq         $v0, $at, L_80144FD0
    if (ctx->r2 == ctx->r1) {
        // 0x80144FA4: nop
    
            goto L_80144FD0;
    }
    // 0x80144FA4: nop

    // 0x80144FA8: b           L_80144FDC
    // 0x80144FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80144FDC;
    // 0x80144FAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144FB0:
    // 0x80144FB0: jal         0x80145240
    // 0x80144FB4: nop

    ftCommonCliffClimbSlow1SetStatus(rdram, ctx);
        goto after_0;
    // 0x80144FB4: nop

    after_0:
    // 0x80144FB8: b           L_80144FDC
    // 0x80144FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80144FDC;
    // 0x80144FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144FC0:
    // 0x80144FC0: jal         0x80145704
    // 0x80144FC4: nop

    ftCommonCliffAttackSlow1SetStatus(rdram, ctx);
        goto after_1;
    // 0x80144FC4: nop

    after_1:
    // 0x80144FC8: b           L_80144FDC
    // 0x80144FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80144FDC;
    // 0x80144FCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144FD0:
    // 0x80144FD0: jal         0x801458BC
    // 0x80144FD4: nop

    ftCommonCliffEscapeSlow1SetStatus(rdram, ctx);
        goto after_2;
    // 0x80144FD4: nop

    after_2:
    // 0x80144FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80144FDC:
    // 0x80144FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80144FE0: jr          $ra
    // 0x80144FE4: nop

    return;
    // 0x80144FE4: nop

;}
RECOMP_FUNC void itMapCheckMapReboundProcAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173D24: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80173D28: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80173D2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80173D30: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80173D34: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80173D38: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x80173D3C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80173D40: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80173D44: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    // 0x80173D48: jal         0x801737B8
    // 0x80173D4C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80173D4C: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
    after_0:
    // 0x80173D50: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80173D54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80173D58: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x80173D5C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80173D60: jal         0x801737EC
    // 0x80173D64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itMapCheckCollideAllRebound(rdram, ctx);
        goto after_1;
    // 0x80173D64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x80173D68: beql        $v0, $zero, L_80173D7C
    if (ctx->r2 == 0) {
        // 0x80173D6C: lw          $v1, 0x34($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X34);
            goto L_80173D7C;
    }
    goto skip_0;
    // 0x80173D6C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    skip_0:
    // 0x80173D70: jal         0x80172508
    // 0x80173D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainSetSpinVelLR(rdram, ctx);
        goto after_2;
    // 0x80173D74: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80173D78: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
L_80173D7C:
    // 0x80173D7C: addiu       $v0, $v1, 0x38
    ctx->r2 = ADD32(ctx->r3, 0X38);
    // 0x80173D80: lhu         $t7, 0x56($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X56);
    // 0x80173D84: addiu       $a1, $v0, 0x80
    ctx->r5 = ADD32(ctx->r2, 0X80);
    // 0x80173D88: addiu       $a0, $v1, 0x2C
    ctx->r4 = ADD32(ctx->r3, 0X2C);
    // 0x80173D8C: andi        $t8, $t7, 0x800
    ctx->r24 = ctx->r15 & 0X800;
    // 0x80173D90: beql        $t8, $zero, L_80173DB8
    if (ctx->r24 == 0) {
        // 0x80173D94: lw          $t9, 0x2C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X2C);
            goto L_80173DB8;
    }
    goto skip_1;
    // 0x80173D94: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    skip_1:
    // 0x80173D98: jal         0x800C7B08
    // 0x80173D9C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    lbCommonReflect2D(rdram, ctx);
        goto after_3;
    // 0x80173D9C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_3:
    // 0x80173DA0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80173DA4: jal         0x800C7AE0
    // 0x80173DA8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    lbCommonScale2D(rdram, ctx);
        goto after_4;
    // 0x80173DA8: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x80173DAC: jal         0x80172508
    // 0x80173DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainSetSpinVelLR(rdram, ctx);
        goto after_5;
    // 0x80173DB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80173DB4: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
L_80173DB8:
    // 0x80173DB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80173DBC: beq         $t9, $zero, L_80173DE0
    if (ctx->r25 == 0) {
        // 0x80173DC0: nop
    
            goto L_80173DE0;
    }
    // 0x80173DC0: nop

    // 0x80173DC4: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x80173DC8: beq         $v0, $zero, L_80173DD8
    if (ctx->r2 == 0) {
        // 0x80173DCC: nop
    
            goto L_80173DD8;
    }
    // 0x80173DCC: nop

    // 0x80173DD0: jalr        $v0
    // 0x80173DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_6;
    // 0x80173DD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80173DD8:
    // 0x80173DD8: b           L_80173DE0
    // 0x80173DDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80173DE0;
    // 0x80173DDC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80173DE0:
    // 0x80173DE0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80173DE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80173DE8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80173DEC: jr          $ra
    // 0x80173DF0: nop

    return;
    // 0x80173DF0: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltAirProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016953C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80169540: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80169544: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80169548: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x8016954C: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x80169550: jal         0x800FE068
    // 0x80169554: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80169554: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x80169558: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016955C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80169560: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80169564: jr          $ra
    // 0x80169568: nop

    return;
    // 0x80169568: nop

;}
RECOMP_FUNC void wpDisplayMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80167524: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80167528: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016752C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80167530: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80167534: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80167538: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016753C: lw          $v1, 0x2BC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2BC);
    // 0x80167540: bne         $v1, $at, L_80167578
    if (ctx->r3 != ctx->r1) {
        // 0x80167544: nop
    
            goto L_80167578;
    }
    // 0x80167544: nop

    // 0x80167548: jal         0x80167454
    // 0x8016754C: nop

    wpDisplayDrawNormal(rdram, ctx);
        goto after_0;
    // 0x8016754C: nop

    after_0:
    // 0x80167550: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80167554: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80167558: jalr        $t9
    // 0x8016755C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8016755C: nop

    after_1:
    // 0x80167560: jal         0x801674B8
    // 0x80167564: nop

    wpDisplayDrawZBuffer(rdram, ctx);
        goto after_2;
    // 0x80167564: nop

    after_2:
    // 0x80167568: jal         0x801671F0
    // 0x8016756C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpDisplayMapCollisions(rdram, ctx);
        goto after_3;
    // 0x8016756C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80167570: b           L_801675C0
    // 0x80167574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801675C0;
    // 0x80167574: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80167578:
    // 0x80167578: beq         $v1, $zero, L_8016758C
    if (ctx->r3 == 0) {
        // 0x8016757C: nop
    
            goto L_8016758C;
    }
    // 0x8016757C: nop

    // 0x80167580: lw          $t6, 0x100($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X100);
    // 0x80167584: bne         $t6, $zero, L_801675B4
    if (ctx->r14 != 0) {
        // 0x80167588: nop
    
            goto L_801675B4;
    }
    // 0x80167588: nop

L_8016758C:
    // 0x8016758C: jal         0x80167454
    // 0x80167590: nop

    wpDisplayDrawNormal(rdram, ctx);
        goto after_4;
    // 0x80167590: nop

    after_4:
    // 0x80167594: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80167598: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016759C: jalr        $t9
    // 0x801675A0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x801675A0: nop

    after_5:
    // 0x801675A4: jal         0x801674B8
    // 0x801675A8: nop

    wpDisplayDrawZBuffer(rdram, ctx);
        goto after_6;
    // 0x801675A8: nop

    after_6:
    // 0x801675AC: b           L_801675C0
    // 0x801675B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801675C0;
    // 0x801675B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801675B4:
    // 0x801675B4: jal         0x80166E80
    // 0x801675B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpDisplayHitCollisions(rdram, ctx);
        goto after_7;
    // 0x801675B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801675BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801675C0:
    // 0x801675C0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801675C4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801675C8: jr          $ra
    // 0x801675CC: nop

    return;
    // 0x801675CC: nop

;}
RECOMP_FUNC void gmCollisionTestRectangle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EE300: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800EE304: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x800EE308: lw          $s0, 0xC4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XC4);
    // 0x800EE30C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800EE310: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x800EE314: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x800EE318: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x800EE31C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x800EE320: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800EE324: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800EE328: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800EE32C: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800EE330: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800EE334: lw          $a2, 0xC0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XC0);
    // 0x800EE338: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800EE33C: div.s       $f10, $f12, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = DIV_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800EE340: lwc1        $f18, 0x0($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EE344: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800EE348: swc1        $f16, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f16.u32l;
    // 0x800EE34C: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800EE350: lwc1        $f8, 0x4($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EE354: div.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800EE358: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800EE35C: swc1        $f18, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f18.u32l;
    // 0x800EE360: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800EE364: lwc1        $f10, 0x8($a2)
    ctx->f10.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EE368: div.s       $f6, $f12, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    // 0x800EE36C: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800EE370: bne         $a3, $at, L_800EE458
    if (ctx->r7 != ctx->r1) {
        // 0x800EE374: swc1        $f8, 0xA4($sp)
        MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
            goto L_800EE458;
    }
    // 0x800EE374: swc1        $f8, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f8.u32l;
    // 0x800EE378: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x800EE37C: lw          $s0, 0xB8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB8);
    // 0x800EE380: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    // 0x800EE384: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x800EE388: lw          $t2, 0x4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4);
    // 0x800EE38C: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x800EE390: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x800EE394: beq         $s0, $zero, L_800EE3A4
    if (ctx->r16 == 0) {
        // 0x800EE398: sw          $t3, 0x8($a1)
        MEM_W(0X8, ctx->r5) = ctx->r11;
            goto L_800EE3A4;
    }
    // 0x800EE398: sw          $t3, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r11;
    // 0x800EE39C: jal         0x800ED3C0
    // 0x800EE3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_0;
    // 0x800EE3A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_800EE3A4:
    // 0x800EE3A4: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x800EE3A8: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x800EE3AC: lwc1        $f10, 0x94($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800EE3B0: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EE3B4: sub.s       $f16, $f4, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800EE3B8: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800EE3BC: swc1        $f16, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f16.u32l;
    // 0x800EE3C0: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EE3C4: sub.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800EE3C8: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800EE3CC: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
    // 0x800EE3D0: lwc1        $f18, 0x8($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EE3D4: sub.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800EE3D8: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800EE3DC: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    // 0x800EE3E0: c.le.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl <= ctx->f16.fl;
    // 0x800EE3E4: nop

    // 0x800EE3E8: bc1f        L_800EE450
    if (!c1cs) {
        // 0x800EE3EC: nop
    
            goto L_800EE450;
    }
    // 0x800EE3EC: nop

    // 0x800EE3F0: c.le.s      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.fl <= ctx->f6.fl;
    // 0x800EE3F4: lwc1        $f2, 0xA0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800EE3F8: bc1f        L_800EE450
    if (!c1cs) {
        // 0x800EE3FC: nop
    
            goto L_800EE450;
    }
    // 0x800EE3FC: nop

    // 0x800EE400: neg.s       $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = -ctx->f2.fl;
    // 0x800EE404: c.le.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl <= ctx->f8.fl;
    // 0x800EE408: nop

    // 0x800EE40C: bc1f        L_800EE450
    if (!c1cs) {
        // 0x800EE410: nop
    
            goto L_800EE450;
    }
    // 0x800EE410: nop

    // 0x800EE414: c.le.s      $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f8.fl <= ctx->f2.fl;
    // 0x800EE418: lwc1        $f0, 0xA4($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x800EE41C: bc1f        L_800EE450
    if (!c1cs) {
        // 0x800EE420: nop
    
            goto L_800EE450;
    }
    // 0x800EE420: nop

    // 0x800EE424: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800EE428: c.le.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl <= ctx->f10.fl;
    // 0x800EE42C: nop

    // 0x800EE430: bc1f        L_800EE450
    if (!c1cs) {
        // 0x800EE434: nop
    
            goto L_800EE450;
    }
    // 0x800EE434: nop

    // 0x800EE438: c.le.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl <= ctx->f0.fl;
    // 0x800EE43C: nop

    // 0x800EE440: bc1f        L_800EE450
    if (!c1cs) {
        // 0x800EE444: nop
    
            goto L_800EE450;
    }
    // 0x800EE444: nop

    // 0x800EE448: b           L_800EE724
    // 0x800EE44C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800EE724;
    // 0x800EE44C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800EE450:
    // 0x800EE450: b           L_800EE724
    // 0x800EE454: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EE724;
    // 0x800EE454: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EE458:
    // 0x800EE458: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800EE45C: lw          $s0, 0xB8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XB8);
    // 0x800EE460: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x800EE464: sw          $t5, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r13;
    // 0x800EE468: lw          $t4, 0x4($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4);
    // 0x800EE46C: addiu       $s4, $sp, 0x6C
    ctx->r20 = ADD32(ctx->r29, 0X6C);
    // 0x800EE470: sw          $t4, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r12;
    // 0x800EE474: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x800EE478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EE47C: sw          $t5, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r13;
    // 0x800EE480: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800EE484: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800EE488: lw          $t6, 0x4($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X4);
    // 0x800EE48C: sw          $t6, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r14;
    // 0x800EE490: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800EE494: beq         $s0, $zero, L_800EE4B0
    if (ctx->r16 == 0) {
        // 0x800EE498: sw          $t7, 0x8($s4)
        MEM_W(0X8, ctx->r20) = ctx->r15;
            goto L_800EE4B0;
    }
    // 0x800EE498: sw          $t7, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r15;
    // 0x800EE49C: jal         0x800ED3C0
    // 0x800EE4A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_1;
    // 0x800EE4A0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800EE4A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800EE4A8: jal         0x800ED3C0
    // 0x800EE4AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_2;
    // 0x800EE4AC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
L_800EE4B0:
    // 0x800EE4B0: lw          $v0, 0xBC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XBC);
    // 0x800EE4B4: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EE4B8: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800EE4BC: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EE4C0: addiu       $s3, $sp, 0x9C
    ctx->r19 = ADD32(ctx->r29, 0X9C);
    // 0x800EE4C4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800EE4C8: sub.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800EE4CC: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800EE4D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800EE4D4: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
    // 0x800EE4D8: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EE4DC: sub.s       $f4, $f18, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800EE4E0: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800EE4E4: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
    // 0x800EE4E8: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EE4EC: sub.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x800EE4F0: swc1        $f18, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f18.u32l;
    // 0x800EE4F4: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800EE4F8: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800EE4FC: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800EE500: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x800EE504: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800EE508: swc1        $f8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f8.u32l;
    // 0x800EE50C: sub.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800EE510: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800EE514: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800EE518: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800EE51C: sub.s       $f22, $f10, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f22.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x800EE520: sub.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800EE524: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800EE528: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x800EE52C: sub.s       $f24, $f6, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800EE530: jal         0x800EE24C
    // 0x800EE534: sub.s       $f20, $f16, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f8.fl;
    func_ovl2_800EE24C(rdram, ctx);
        goto after_3;
    // 0x800EE534: sub.s       $f20, $f16, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f16.fl - ctx->f8.fl;
    after_3:
    // 0x800EE538: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EE53C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800EE540: jal         0x800EE24C
    // 0x800EE544: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_ovl2_800EE24C(rdram, ctx);
        goto after_4;
    // 0x800EE544: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x800EE548: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800EE54C: addiu       $s1, $sp, 0x84
    ctx->r17 = ADD32(ctx->r29, 0X84);
L_800EE550:
    // 0x800EE550: bne         $s0, $zero, L_800EE560
    if (ctx->r16 != 0) {
        // 0x800EE554: and         $t8, $s0, $v1
        ctx->r24 = ctx->r16 & ctx->r3;
            goto L_800EE560;
    }
    // 0x800EE554: and         $t8, $s0, $v1
    ctx->r24 = ctx->r16 & ctx->r3;
    // 0x800EE558: beql        $v1, $zero, L_800EE6F8
    if (ctx->r3 == 0) {
        // 0x800EE55C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800EE6F8;
    }
    goto skip_0;
    // 0x800EE55C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
L_800EE560:
    // 0x800EE560: beq         $t8, $zero, L_800EE570
    if (ctx->r24 == 0) {
        // 0x800EE564: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800EE570;
    }
    // 0x800EE564: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800EE568: b           L_800EE724
    // 0x800EE56C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EE724;
    // 0x800EE56C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EE570:
    // 0x800EE570: beq         $s0, $zero, L_800EE580
    if (ctx->r16 == 0) {
        // 0x800EE574: lwc1        $f2, 0x9C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
            goto L_800EE580;
    }
    // 0x800EE574: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800EE578: b           L_800EE580
    // 0x800EE57C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800EE580;
    // 0x800EE57C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800EE580:
    // 0x800EE580: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x800EE584: beq         $t9, $zero, L_800EE5C8
    if (ctx->r25 == 0) {
        // 0x800EE588: andi        $t0, $v0, 0x2
        ctx->r8 = ctx->r2 & 0X2;
            goto L_800EE5C8;
    }
    // 0x800EE588: andi        $t0, $v0, 0x2
    ctx->r8 = ctx->r2 & 0X2;
    // 0x800EE58C: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EE590: neg.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = -ctx->f2.fl;
    // 0x800EE594: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800EE598: sub.s       $f8, $f12, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x800EE59C: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800EE5A0: swc1        $f12, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f12.u32l;
    // 0x800EE5A4: div.s       $f0, $f8, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800EE5A8: mul.s       $f10, $f0, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800EE5AC: nop

    // 0x800EE5B0: mul.s       $f6, $f0, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800EE5B4: add.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800EE5B8: add.s       $f16, $f6, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800EE5BC: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x800EE5C0: b           L_800EE690
    // 0x800EE5C4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
        goto L_800EE690;
    // 0x800EE5C4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
L_800EE5C8:
    // 0x800EE5C8: beq         $t0, $zero, L_800EE60C
    if (ctx->r8 == 0) {
        // 0x800EE5CC: andi        $t1, $v0, 0x4
        ctx->r9 = ctx->r2 & 0X4;
            goto L_800EE60C;
    }
    // 0x800EE5CC: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x800EE5D0: lwc1        $f12, 0x9C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800EE5D4: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EE5D8: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800EE5DC: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800EE5E0: sub.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f8.fl;
    // 0x800EE5E4: swc1        $f12, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f12.u32l;
    // 0x800EE5E8: div.s       $f0, $f10, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800EE5EC: mul.s       $f4, $f0, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f22.fl);
    // 0x800EE5F0: nop

    // 0x800EE5F4: mul.s       $f18, $f0, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800EE5F8: add.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800EE5FC: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800EE600: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x800EE604: b           L_800EE690
    // 0x800EE608: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
        goto L_800EE690;
    // 0x800EE608: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
L_800EE60C:
    // 0x800EE60C: beq         $t1, $zero, L_800EE654
    if (ctx->r9 == 0) {
        // 0x800EE610: andi        $t2, $v0, 0x8
        ctx->r10 = ctx->r2 & 0X8;
            goto L_800EE654;
    }
    // 0x800EE610: andi        $t2, $v0, 0x8
    ctx->r10 = ctx->r2 & 0X8;
    // 0x800EE614: lwc1        $f2, 0xA0($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800EE618: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800EE61C: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EE620: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
    // 0x800EE624: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800EE628: sub.s       $f4, $f14, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x800EE62C: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x800EE630: div.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800EE634: mul.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800EE638: nop

    // 0x800EE63C: mul.s       $f16, $f0, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800EE640: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800EE644: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800EE648: swc1        $f12, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f12.u32l;
    // 0x800EE64C: b           L_800EE690
    // 0x800EE650: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
        goto L_800EE690;
    // 0x800EE650: swc1        $f10, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f10.u32l;
L_800EE654:
    // 0x800EE654: beq         $t2, $zero, L_800EE690
    if (ctx->r10 == 0) {
        // 0x800EE658: lwc1        $f14, 0xA0($sp)
        ctx->f14.u32l = MEM_W(ctx->r29, 0XA0);
            goto L_800EE690;
    }
    // 0x800EE658: lwc1        $f14, 0xA0($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x800EE65C: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800EE660: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800EE664: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800EE668: sub.s       $f6, $f14, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800EE66C: swc1        $f14, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f14.u32l;
    // 0x800EE670: div.s       $f0, $f6, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800EE674: mul.s       $f18, $f0, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800EE678: nop

    // 0x800EE67C: mul.s       $f8, $f0, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f24.fl);
    // 0x800EE680: add.s       $f12, $f18, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800EE684: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800EE688: swc1        $f12, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f12.u32l;
    // 0x800EE68C: swc1        $f4, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f4.u32l;
L_800EE690:
    // 0x800EE690: bne         $v0, $s0, L_800EE6CC
    if (ctx->r2 != ctx->r16) {
        // 0x800EE694: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800EE6CC;
    }
    // 0x800EE694: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800EE698: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x800EE69C: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x800EE6A0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800EE6A4: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800EE6A8: lw          $t4, 0x8($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X8);
    // 0x800EE6AC: sw          $t3, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r11;
    // 0x800EE6B0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800EE6B4: sw          $t4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r12;
    // 0x800EE6B8: jal         0x800EE24C
    // 0x800EE6BC: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    func_ovl2_800EE24C(rdram, ctx);
        goto after_5;
    // 0x800EE6BC: sw          $v1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r3;
    after_5:
    // 0x800EE6C0: lw          $v1, 0x64($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X64);
    // 0x800EE6C4: b           L_800EE550
    // 0x800EE6C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
        goto L_800EE550;
    // 0x800EE6C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800EE6CC:
    // 0x800EE6CC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800EE6D0: lw          $t5, 0x4($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X4);
    // 0x800EE6D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800EE6D8: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800EE6DC: lw          $t6, 0x8($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X8);
    // 0x800EE6E0: sw          $t5, 0x4($s4)
    MEM_W(0X4, ctx->r20) = ctx->r13;
    // 0x800EE6E4: jal         0x800EE24C
    // 0x800EE6E8: sw          $t6, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r14;
    func_ovl2_800EE24C(rdram, ctx);
        goto after_6;
    // 0x800EE6E8: sw          $t6, 0x8($s4)
    MEM_W(0X8, ctx->r20) = ctx->r14;
    after_6:
    // 0x800EE6EC: b           L_800EE550
    // 0x800EE6F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800EE550;
    // 0x800EE6F0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800EE6F4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800EE6F8:
    // 0x800EE6F8: jal         0x800EE2C0
    // 0x800EE6FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_ovl2_800EE2C0(rdram, ctx);
        goto after_7;
    // 0x800EE6FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x800EE700: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800EE704: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800EE708: jal         0x800EE2C0
    // 0x800EE70C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_ovl2_800EE2C0(rdram, ctx);
        goto after_8;
    // 0x800EE70C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_8:
    // 0x800EE710: and         $t7, $s0, $v0
    ctx->r15 = ctx->r16 & ctx->r2;
    // 0x800EE714: beq         $t7, $zero, L_800EE724
    if (ctx->r15 == 0) {
        // 0x800EE718: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800EE724;
    }
    // 0x800EE718: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EE71C: b           L_800EE724
    // 0x800EE720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EE724;
    // 0x800EE720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EE724:
    // 0x800EE724: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800EE728: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800EE72C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800EE730: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800EE734: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800EE738: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800EE73C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800EE740: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800EE744: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800EE748: jr          $ra
    // 0x800EE74C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800EE74C: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void itMainSearchRandomWeight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
L_8017301C:
    // 0x8017301C: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x80173020: bne         $a3, $t6, L_80173030
    if (ctx->r7 != ctx->r14) {
        // 0x80173024: addu        $v1, $a2, $a3
        ctx->r3 = ADD32(ctx->r6, ctx->r7);
            goto L_80173030;
    }
    // 0x80173024: addu        $v1, $a2, $a3
    ctx->r3 = ADD32(ctx->r6, ctx->r7);
    // 0x80173028: jr          $ra
    // 0x8017302C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x8017302C: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80173030:
    // 0x80173030: lw          $t7, 0x14($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X14);
    // 0x80173034: bgez        $v1, L_80173040
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80173038: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_80173040;
    }
    // 0x80173038: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x8017303C: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
L_80173040:
    // 0x80173040: sra         $v1, $at, 1
    ctx->r3 = S32(SIGNED(ctx->r1) >> 1);
    // 0x80173044: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x80173048: addu        $t0, $t7, $t8
    ctx->r8 = ADD32(ctx->r15, ctx->r24);
    // 0x8017304C: lhu         $t9, 0x0($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X0);
    // 0x80173050: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80173054: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80173058: beql        $at, $zero, L_8017306C
    if (ctx->r1 == 0) {
        // 0x8017305C: lhu         $t1, 0x2($t0)
        ctx->r9 = MEM_HU(ctx->r8, 0X2);
            goto L_8017306C;
    }
    goto skip_0;
    // 0x8017305C: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
    skip_0:
    // 0x80173060: b           L_8017301C
    // 0x80173064: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
        goto L_8017301C;
    // 0x80173064: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80173068: lhu         $t1, 0x2($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2);
L_8017306C:
    // 0x8017306C: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80173070: beq         $at, $zero, L_80173080
    if (ctx->r1 == 0) {
        // 0x80173074: nop
    
            goto L_80173080;
    }
    // 0x80173074: nop

    // 0x80173078: jr          $ra
    // 0x8017307C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8017307C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80173080:
    // 0x80173080: b           L_8017301C
    // 0x80173084: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_8017301C;
    // 0x80173084: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x80173088: jr          $ra
    // 0x8017308C: nop

    return;
    // 0x8017308C: nop

;}
RECOMP_FUNC void mn1PModeStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133020: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80133024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133028: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013302C: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80133030: addiu       $a0, $a0, 0x30F0
    ctx->r4 = ADD32(ctx->r4, 0X30F0);
    // 0x80133034: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133038: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8013303C: jal         0x80007024
    // 0x80133040: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80133040: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80133044: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80133048: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013304C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133050: addiu       $t9, $t9, 0x32A0
    ctx->r25 = ADD32(ctx->r25, 0X32A0);
    // 0x80133054: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80133058: addiu       $a0, $a0, 0x310C
    ctx->r4 = ADD32(ctx->r4, 0X310C);
    // 0x8013305C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80133060: jal         0x8000683C
    // 0x80133064: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80133064: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80133068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013306C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80133070: jr          $ra
    // 0x80133074: nop

    return;
    // 0x80133074: nop

;}

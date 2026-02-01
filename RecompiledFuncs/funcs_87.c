#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void efManagerDamageSpawnOrbsRandgcMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FFB38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800FFB3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FFB40: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800FFB44: jal         0x80018994
    // 0x800FFB48: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x800FFB48: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_0:
    // 0x800FFB4C: beq         $v0, $zero, L_800FFB5C
    if (ctx->r2 == 0) {
        // 0x800FFB50: nop
    
            goto L_800FFB5C;
    }
    // 0x800FFB50: nop

    // 0x800FFB54: b           L_800FFB64
    // 0x800FFB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FFB64;
    // 0x800FFB58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FFB5C:
    // 0x800FFB5C: jal         0x800FFAB8
    // 0x800FFB60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    efManagerDamageSpawnOrbsMakeEffect(rdram, ctx);
        goto after_1;
    // 0x800FFB60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_800FFB64:
    // 0x800FFB64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FFB68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800FFB6C: jr          $ra
    // 0x800FFB70: nop

    return;
    // 0x800FFB70: nop

;}
RECOMP_FUNC void lbRelocAddStatusBufferFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD71C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800CD720: addiu       $v1, $v1, 0x62E0
    ctx->r3 = ADD32(ctx->r3, 0X62E0);
    // 0x800CD724: lw          $a2, 0x18($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X18);
    // 0x800CD728: lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C);
    // 0x800CD72C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CD730: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CD734: sltu        $at, $a2, $t6
    ctx->r1 = ctx->r6 < ctx->r14 ? 1 : 0;
    // 0x800CD738: bne         $at, $zero, L_800CD760
    if (ctx->r1 != 0) {
        // 0x800CD73C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800CD760;
    }
    // 0x800CD73C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800CD740: lui         $s0, 0x800D
    ctx->r16 = S32(0X800D << 16);
    // 0x800CD744: addiu       $s0, $s0, 0x5EE0
    ctx->r16 = ADD32(ctx->r16, 0X5EE0);
L_800CD748:
    // 0x800CD748: jal         0x80023624
    // 0x800CD74C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800CD74C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800CD750: jal         0x800A3040
    // 0x800CD754: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800CD754: nop

    after_1:
    // 0x800CD758: b           L_800CD748
    // 0x800CD75C: nop

        goto L_800CD748;
    // 0x800CD75C: nop

L_800CD760:
    // 0x800CD760: lw          $t7, 0x20($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X20);
    // 0x800CD764: sll         $v0, $a2, 3
    ctx->r2 = S32(ctx->r6 << 3);
    // 0x800CD768: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800CD76C: sw          $a0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r4;
    // 0x800CD770: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x800CD774: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800CD778: sw          $a1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r5;
    // 0x800CD77C: lw          $t1, 0x18($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X18);
    // 0x800CD780: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CD784: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800CD788: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800CD78C: sw          $t2, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r10;
    // 0x800CD790: jr          $ra
    // 0x800CD794: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800CD794: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftSamusSpecialAirLwSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E274: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015E278: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015E27C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015E280: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015E284: addiu       $a1, $zero, 0xE6
    ctx->r5 = ADD32(0, 0XE6);
    // 0x8015E288: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015E28C: lw          $t6, 0x9C8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X9C8);
    // 0x8015E290: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8015E294: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015E298: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015E29C: jal         0x800E6F24
    // 0x8015E2A0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015E2A0: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015E2A4: jal         0x800E0830
    // 0x8015E2A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015E2A8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x8015E2AC: jal         0x8015E218
    // 0x8015E2B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftSamusSpecialLwInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x8015E2B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8015E2B4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8015E2B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015E2BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015E2C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015E2C4: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
    // 0x8015E2C8: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8015E2CC: lwc1        $f8, -0x3714($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3714);
    // 0x8015E2D0: lwc1        $f6, 0x50($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X50);
    // 0x8015E2D4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8015E2D8: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8015E2DC: jal         0x800D8E78
    // 0x8015E2E0: nop

    ftPhysicsClampAirVelX(rdram, ctx);
        goto after_3;
    // 0x8015E2E0: nop

    after_3:
    // 0x8015E2E4: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8015E2E8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8015E2EC: lw          $t9, 0x64($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X64);
    // 0x8015E2F0: sw          $t0, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = ctx->r8;
    // 0x8015E2F4: sb          $t9, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r25;
    // 0x8015E2F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015E2FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015E300: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015E304: jr          $ra
    // 0x8015E308: nop

    return;
    // 0x8015E308: nop

;}
RECOMP_FUNC void wpNessPKThunderHeadProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016B198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016B19C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016B1A0: jal         0x80167C04
    // 0x8016B1A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8016B1A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016B1A8: beq         $v0, $zero, L_8016B1D4
    if (ctx->r2 == 0) {
        // 0x8016B1AC: lw          $t6, 0x18($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X18);
            goto L_8016B1D4;
    }
    // 0x8016B1AC: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016B1B0: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8016B1B4: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x8016B1B8: jal         0x800FF648
    // 0x8016B1BC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8016B1BC: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x8016B1C0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8016B1C4: jal         0x8016AD30
    // 0x8016B1C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpNessPKThunderHeadSetDestroyTrails(rdram, ctx);
        goto after_2;
    // 0x8016B1C8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x8016B1CC: b           L_8016B1D8
    // 0x8016B1D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016B1D8;
    // 0x8016B1D0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8016B1D4:
    // 0x8016B1D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016B1D8:
    // 0x8016B1D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016B1DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016B1E0: jr          $ra
    // 0x8016B1E4: nop

    return;
    // 0x8016B1E4: nop

;}
RECOMP_FUNC void scSubsysFighterSetLightParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803904E0: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803904E4: swc1        $f12, 0x29D8($at)
    MEM_W(0X29D8, ctx->r1) = ctx->f12.u32l;
    // 0x803904E8: lui         $v0, 0x8039
    ctx->r2 = S32(0X8039 << 16);
    // 0x803904EC: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x803904F0: addiu       $v0, $v0, 0x29E0
    ctx->r2 = ADD32(ctx->r2, 0X29E0);
    // 0x803904F4: swc1        $f14, 0x29DC($at)
    MEM_W(0X29DC, ctx->r1) = ctx->f14.u32l;
    // 0x803904F8: lbu         $t6, 0x13($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X13);
    // 0x803904FC: lbu         $t7, 0x17($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X17);
    // 0x80390500: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80390504: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80390508: sb          $a2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r6;
    // 0x8039050C: sb          $a3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r7;
    // 0x80390510: sb          $t6, 0x2($v0)
    MEM_B(0X2, ctx->r2) = ctx->r14;
    // 0x80390514: jr          $ra
    // 0x80390518: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
    return;
    // 0x80390518: sb          $t7, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void mnVSModeMain(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133B8C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133B90: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133B94: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133B98: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80133B9C: addiu       $t7, $t7, 0x4870
    ctx->r15 = ADD32(ctx->r15, 0X4870);
    // 0x80133BA0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133BA4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80133BA8: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x80133BAC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133BB0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133BB4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80133BB8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133BBC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133BC0: addiu       $v1, $v1, 0x4980
    ctx->r3 = ADD32(ctx->r3, 0X4980);
    // 0x80133BC4: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80133BC8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133BCC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80133BD0: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133BD4: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80133BD8: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x80133BDC: bne         $at, $zero, L_801345B4
    if (ctx->r1 != 0) {
        // 0x80133BE0: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_801345B4;
    }
    // 0x80133BE0: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80133BE4: lw          $t2, 0x4984($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4984);
    // 0x80133BE8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133BEC: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80133BF0: bne         $t2, $t1, L_80133C18
    if (ctx->r10 != ctx->r9) {
        // 0x80133BF4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80133C18;
    }
    // 0x80133BF4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80133BF8: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80133BFC: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x80133C00: jal         0x801337B8
    // 0x80133C04: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    mnVSModeSaveSettings(rdram, ctx);
        goto after_0;
    // 0x80133C04: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    after_0:
    // 0x80133C08: jal         0x80005C74
    // 0x80133C0C: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x80133C0C: nop

    after_1:
    // 0x80133C10: b           L_801345B8
    // 0x80133C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801345B8;
    // 0x80133C14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133C18:
    // 0x80133C18: jal         0x80390B7C
    // 0x80133C1C: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_2;
    // 0x80133C1C: nop

    after_2:
    // 0x80133C20: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133C24: bne         $v0, $zero, L_80133C3C
    if (ctx->r2 != 0) {
        // 0x80133C28: addiu       $v1, $v1, 0x4980
        ctx->r3 = ADD32(ctx->r3, 0X4980);
            goto L_80133C3C;
    }
    // 0x80133C28: addiu       $v1, $v1, 0x4980
    ctx->r3 = ADD32(ctx->r3, 0X4980);
    // 0x80133C2C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80133C30: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C34: addiu       $t6, $t5, 0x4650
    ctx->r14 = ADD32(ctx->r13, 0X4650);
    // 0x80133C38: sw          $t6, 0x4984($at)
    MEM_W(0X4984, ctx->r1) = ctx->r14;
L_80133C3C:
    // 0x80133C3C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133C40: lw          $t7, 0x4974($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4974);
    // 0x80133C44: beq         $t7, $zero, L_80133C54
    if (ctx->r15 == 0) {
        // 0x80133C48: nop
    
            goto L_80133C54;
    }
    // 0x80133C48: nop

    // 0x80133C4C: jal         0x80005C74
    // 0x80133C50: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x80133C50: nop

    after_3:
L_80133C54:
    // 0x80133C54: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133C58: addiu       $v1, $v1, 0x497C
    ctx->r3 = ADD32(ctx->r3, 0X497C);
    // 0x80133C5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133C60: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133C64: beq         $v0, $zero, L_80133C70
    if (ctx->r2 == 0) {
        // 0x80133C68: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80133C70;
    }
    // 0x80133C68: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80133C6C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80133C70:
    // 0x80133C70: jal         0x80390A04
    // 0x80133C74: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_4;
    // 0x80133C74: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_4:
    // 0x80133C78: beq         $v0, $zero, L_80133CBC
    if (ctx->r2 == 0) {
        // 0x80133C7C: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80133CBC;
    }
    // 0x80133C7C: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133C80: jal         0x80390AC0
    // 0x80133C84: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_5;
    // 0x80133C84: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_5:
    // 0x80133C88: beq         $v0, $zero, L_80133CBC
    if (ctx->r2 == 0) {
        // 0x80133C8C: nop
    
            goto L_80133CBC;
    }
    // 0x80133C8C: nop

    // 0x80133C90: jal         0x80390804
    // 0x80133C94: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_6;
    // 0x80133C94: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    after_6:
    // 0x80133C98: bne         $v0, $zero, L_80133CBC
    if (ctx->r2 != 0) {
        // 0x80133C9C: nop
    
            goto L_80133CBC;
    }
    // 0x80133C9C: nop

    // 0x80133CA0: jal         0x80390804
    // 0x80133CA4: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_7;
    // 0x80133CA4: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    after_7:
    // 0x80133CA8: bne         $v0, $zero, L_80133CBC
    if (ctx->r2 != 0) {
        // 0x80133CAC: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80133CBC;
    }
    // 0x80133CAC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CB0: sw          $zero, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = 0;
    // 0x80133CB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CB8: sw          $zero, 0x4978($at)
    MEM_W(0X4978, ctx->r1) = 0;
L_80133CBC:
    // 0x80133CBC: jal         0x8039076C
    // 0x80133CC0: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_8;
    // 0x80133CC0: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_8:
    // 0x80133CC4: beq         $v0, $zero, L_80133D7C
    if (ctx->r2 == 0) {
        // 0x80133CC8: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80133D7C;
    }
    // 0x80133CC8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133CCC: lw          $v0, 0x4948($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4948);
    // 0x80133CD0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80133CD4: beq         $v0, $zero, L_80133CEC
    if (ctx->r2 == 0) {
        // 0x80133CD8: nop
    
            goto L_80133CEC;
    }
    // 0x80133CD8: nop

    // 0x80133CDC: beq         $v0, $at, L_80133D34
    if (ctx->r2 == ctx->r1) {
        // 0x80133CE0: nop
    
            goto L_80133D34;
    }
    // 0x80133CE0: nop

    // 0x80133CE4: b           L_80133D7C
    // 0x80133CE8: nop

        goto L_80133D7C;
    // 0x80133CE8: nop

L_80133CEC:
    // 0x80133CEC: jal         0x800269C0
    // 0x80133CF0: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80133CF0: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_9:
    // 0x80133CF4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133CF8: lw          $a0, 0x4930($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4930);
    // 0x80133CFC: jal         0x80131F4C
    // 0x80133D00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    mnVSModeUpdateButton(rdram, ctx);
        goto after_10;
    // 0x80133D00: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_10:
    // 0x80133D04: jal         0x801337B8
    // 0x80133D08: nop

    mnVSModeSaveSettings(rdram, ctx);
        goto after_11;
    // 0x80133D08: nop

    after_11:
    // 0x80133D0C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133D10: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133D14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D18: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80133D1C: sw          $t9, 0x4974($at)
    MEM_W(0X4974, ctx->r1) = ctx->r25;
    // 0x80133D20: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80133D24: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x80133D28: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80133D2C: b           L_801345B4
    // 0x80133D30: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
        goto L_801345B4;
    // 0x80133D30: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
L_80133D34:
    // 0x80133D34: jal         0x800269C0
    // 0x80133D38: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_12;
    // 0x80133D38: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_12:
    // 0x80133D3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133D40: lw          $a0, 0x493C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X493C);
    // 0x80133D44: jal         0x80131F4C
    // 0x80133D48: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    mnVSModeUpdateButton(rdram, ctx);
        goto after_13;
    // 0x80133D48: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_13:
    // 0x80133D4C: jal         0x801337B8
    // 0x80133D50: nop

    mnVSModeSaveSettings(rdram, ctx);
        goto after_14;
    // 0x80133D50: nop

    after_14:
    // 0x80133D54: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133D58: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133D5C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D60: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80133D64: sw          $t2, 0x4974($at)
    MEM_W(0X4974, ctx->r1) = ctx->r10;
    // 0x80133D68: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80133D6C: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80133D70: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x80133D74: b           L_801345B4
    // 0x80133D78: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
        goto L_801345B4;
    // 0x80133D78: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
L_80133D7C:
    // 0x80133D7C: jal         0x8039076C
    // 0x80133D80: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_15;
    // 0x80133D80: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_15:
    // 0x80133D84: beq         $v0, $zero, L_80133DB0
    if (ctx->r2 == 0) {
        // 0x80133D88: nop
    
            goto L_80133DB0;
    }
    // 0x80133D88: nop

    // 0x80133D8C: jal         0x801337B8
    // 0x80133D90: nop

    mnVSModeSaveSettings(rdram, ctx);
        goto after_16;
    // 0x80133D90: nop

    after_16:
    // 0x80133D94: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133D98: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80133D9C: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x80133DA0: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x80133DA4: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x80133DA8: jal         0x80005C74
    // 0x80133DAC: sb          $t5, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r13;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_17;
    // 0x80133DAC: sb          $t5, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r13;
    after_17:
L_80133DB0:
    // 0x80133DB0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133DB4: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
    // 0x80133DB8: bne         $v0, $zero, L_80133DD8
    if (ctx->r2 != 0) {
        // 0x80133DBC: nop
    
            goto L_80133DD8;
    }
    // 0x80133DBC: nop

    // 0x80133DC0: jal         0x80390804
    // 0x80133DC4: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_18;
    // 0x80133DC4: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_18:
    // 0x80133DC8: bne         $v0, $zero, L_80133DF0
    if (ctx->r2 != 0) {
        // 0x80133DCC: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80133DF0;
    }
    // 0x80133DCC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80133DD0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133DD4: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
L_80133DD8:
    // 0x80133DD8: bne         $v0, $zero, L_80133F20
    if (ctx->r2 != 0) {
        // 0x80133DDC: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80133F20;
    }
    // 0x80133DDC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80133DE0: jal         0x80390950
    // 0x80133DE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_19;
    // 0x80133DE4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x80133DE8: beq         $v0, $zero, L_80133F20
    if (ctx->r2 == 0) {
        // 0x80133DEC: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80133F20;
    }
    // 0x80133DEC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80133DF0:
    // 0x80133DF0: jal         0x800269C0
    // 0x80133DF4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_20;
    // 0x80133DF4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_20:
    // 0x80133DF8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80133DFC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133E00: addiu       $v1, $v1, 0x497C
    ctx->r3 = ADD32(ctx->r3, 0X497C);
    // 0x80133E04: beq         $t7, $zero, L_80133E14
    if (ctx->r15 == 0) {
        // 0x80133E08: addiu       $t8, $zero, 0xC
        ctx->r24 = ADD32(0, 0XC);
            goto L_80133E14;
    }
    // 0x80133E08: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80133E0C: b           L_80133E3C
    // 0x80133E10: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_80133E3C;
    // 0x80133E10: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80133E14:
    // 0x80133E14: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80133E18: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x80133E1C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133E20: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x80133E24: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80133E28: mflo        $t2
    ctx->r10 = lo;
    // 0x80133E2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E30: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133E34: addiu       $v1, $v1, 0x497C
    ctx->r3 = ADD32(ctx->r3, 0X497C);
    // 0x80133E38: sw          $t2, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r10;
L_80133E3C:
    // 0x80133E3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133E40: lw          $v0, 0x4948($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4948);
    // 0x80133E44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133E48: bne         $v0, $at, L_80133E5C
    if (ctx->r2 != ctx->r1) {
        // 0x80133E4C: sll         $t5, $v0, 2
        ctx->r13 = S32(ctx->r2 << 2);
            goto L_80133E5C;
    }
    // 0x80133E4C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80133E50: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80133E54: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x80133E58: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80133E5C:
    // 0x80133E5C: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x80133E60: lw          $t6, 0x2C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2C);
    // 0x80133E64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133E68: jal         0x80131F4C
    // 0x80133E6C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    mnVSModeUpdateButton(rdram, ctx);
        goto after_21;
    // 0x80133E6C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_21:
    // 0x80133E70: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133E74: addiu       $v1, $v1, 0x4948
    ctx->r3 = ADD32(ctx->r3, 0X4948);
    // 0x80133E78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133E7C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80133E80: bne         $v0, $zero, L_80133E90
    if (ctx->r2 != 0) {
        // 0x80133E84: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80133E90;
    }
    // 0x80133E84: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80133E88: b           L_80133E94
    // 0x80133E8C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
        goto L_80133E94;
    // 0x80133E8C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80133E90:
    // 0x80133E90: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80133E94:
    // 0x80133E94: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80133E98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80133E9C: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80133EA0: addu        $t1, $sp, $t9
    ctx->r9 = ADD32(ctx->r29, ctx->r25);
    // 0x80133EA4: lw          $t1, 0x2C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X2C);
    // 0x80133EA8: jal         0x80131F4C
    // 0x80133EAC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    mnVSModeUpdateButton(rdram, ctx);
        goto after_22;
    // 0x80133EAC: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_22:
    // 0x80133EB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133EB4: jal         0x80009A84
    // 0x80133EB8: lw          $a0, 0x4960($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4960);
    gcEjectGObj(rdram, ctx);
        goto after_23;
    // 0x80133EB8: lw          $a0, 0x4960($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4960);
    after_23:
    // 0x80133EBC: jal         0x80132FD8
    // 0x80133EC0: nop

    mnVSModeMakeSubtitle(rdram, ctx);
        goto after_24;
    // 0x80133EC0: nop

    after_24:
    // 0x80133EC4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133EC8: lw          $v0, 0x4948($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4948);
    // 0x80133ECC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133ED0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133ED4: sw          $t2, 0x4978($at)
    MEM_W(0X4978, ctx->r1) = ctx->r10;
    // 0x80133ED8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133EDC: bne         $v0, $at, L_80133F00
    if (ctx->r2 != ctx->r1) {
        // 0x80133EE0: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_80133F00;
    }
    // 0x80133EE0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80133EE4: lw          $t3, 0x4964($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4964);
    // 0x80133EE8: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x80133EEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133EF0: sw          $zero, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = 0;
    // 0x80133EF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133EF8: lw          $v0, 0x4948($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4948);
    // 0x80133EFC: sw          $t4, 0x4970($at)
    MEM_W(0X4970, ctx->r1) = ctx->r12;
L_80133F00:
    // 0x80133F00: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133F04: bne         $v0, $at, L_80133F20
    if (ctx->r2 != ctx->r1) {
        // 0x80133F08: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_80133F20;
    }
    // 0x80133F08: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133F0C: lw          $t5, 0x4968($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4968);
    // 0x80133F10: addiu       $t6, $zero, 0x1E
    ctx->r14 = ADD32(0, 0X1E);
    // 0x80133F14: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133F18: sw          $zero, 0x7C($t5)
    MEM_W(0X7C, ctx->r13) = 0;
    // 0x80133F1C: sw          $t6, 0x496C($at)
    MEM_W(0X496C, ctx->r1) = ctx->r14;
L_80133F20:
    // 0x80133F20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133F24: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
    // 0x80133F28: bne         $v0, $zero, L_80133F48
    if (ctx->r2 != 0) {
        // 0x80133F2C: nop
    
            goto L_80133F48;
    }
    // 0x80133F2C: nop

    // 0x80133F30: jal         0x80390804
    // 0x80133F34: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_25;
    // 0x80133F34: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_25:
    // 0x80133F38: bne         $v0, $zero, L_80133F60
    if (ctx->r2 != 0) {
        // 0x80133F3C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80133F60;
    }
    // 0x80133F3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80133F40: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133F44: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
L_80133F48:
    // 0x80133F48: bne         $v0, $zero, L_80134094
    if (ctx->r2 != 0) {
        // 0x80133F4C: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80134094;
    }
    // 0x80133F4C: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133F50: jal         0x80390950
    // 0x80133F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_26;
    // 0x80133F54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x80133F58: beq         $v0, $zero, L_80134094
    if (ctx->r2 == 0) {
        // 0x80133F5C: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80134094;
    }
    // 0x80133F5C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80133F60:
    // 0x80133F60: jal         0x800269C0
    // 0x80133F64: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_27;
    // 0x80133F64: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_27:
    // 0x80133F68: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80133F6C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133F70: addiu       $v1, $v1, 0x497C
    ctx->r3 = ADD32(ctx->r3, 0X497C);
    // 0x80133F74: beq         $t7, $zero, L_80133F84
    if (ctx->r15 == 0) {
        // 0x80133F78: addiu       $t8, $zero, 0xC
        ctx->r24 = ADD32(0, 0XC);
            goto L_80133F84;
    }
    // 0x80133F78: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x80133F7C: b           L_80133FA8
    // 0x80133F80: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_80133FA8;
    // 0x80133F80: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80133F84:
    // 0x80133F84: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80133F88: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133F8C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133F90: addiu       $t9, $t0, 0xA0
    ctx->r25 = ADD32(ctx->r8, 0XA0);
    // 0x80133F94: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80133F98: mflo        $t1
    ctx->r9 = lo;
    // 0x80133F9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133FA0: sw          $t1, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r9;
    // 0x80133FA4: addiu       $v1, $v1, 0x497C
    ctx->r3 = ADD32(ctx->r3, 0X497C);
L_80133FA8:
    // 0x80133FA8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133FAC: lw          $v0, 0x4948($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4948);
    // 0x80133FB0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133FB4: bne         $v0, $at, L_80133FC8
    if (ctx->r2 != ctx->r1) {
        // 0x80133FB8: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_80133FC8;
    }
    // 0x80133FB8: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80133FBC: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80133FC0: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80133FC4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80133FC8:
    // 0x80133FC8: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x80133FCC: lw          $t5, 0x2C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2C);
    // 0x80133FD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133FD4: jal         0x80131F4C
    // 0x80133FD8: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    mnVSModeUpdateButton(rdram, ctx);
        goto after_28;
    // 0x80133FD8: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_28:
    // 0x80133FDC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133FE0: lw          $v0, 0x4948($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4948);
    // 0x80133FE4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80133FE8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133FEC: bne         $v0, $at, L_80134000
    if (ctx->r2 != ctx->r1) {
        // 0x80133FF0: addiu       $t6, $v0, 0x1
        ctx->r14 = ADD32(ctx->r2, 0X1);
            goto L_80134000;
    }
    // 0x80133FF0: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80133FF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133FF8: b           L_80134008
    // 0x80133FFC: sw          $zero, 0x4948($at)
    MEM_W(0X4948, ctx->r1) = 0;
        goto L_80134008;
    // 0x80133FFC: sw          $zero, 0x4948($at)
    MEM_W(0X4948, ctx->r1) = 0;
L_80134000:
    // 0x80134000: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134004: sw          $t6, 0x4948($at)
    MEM_W(0X4948, ctx->r1) = ctx->r14;
L_80134008:
    // 0x80134008: lw          $t7, 0x4948($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4948);
    // 0x8013400C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80134010: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80134014: addu        $t0, $sp, $t8
    ctx->r8 = ADD32(ctx->r29, ctx->r24);
    // 0x80134018: lw          $t0, 0x2C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2C);
    // 0x8013401C: jal         0x80131F4C
    // 0x80134020: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    mnVSModeUpdateButton(rdram, ctx);
        goto after_29;
    // 0x80134020: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    after_29:
    // 0x80134024: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134028: jal         0x80009A84
    // 0x8013402C: lw          $a0, 0x4960($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4960);
    gcEjectGObj(rdram, ctx);
        goto after_30;
    // 0x8013402C: lw          $a0, 0x4960($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4960);
    after_30:
    // 0x80134030: jal         0x80132FD8
    // 0x80134034: nop

    mnVSModeMakeSubtitle(rdram, ctx);
        goto after_31;
    // 0x80134034: nop

    after_31:
    // 0x80134038: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013403C: lw          $v0, 0x4948($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4948);
    // 0x80134040: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80134044: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134048: sw          $t9, 0x4978($at)
    MEM_W(0X4978, ctx->r1) = ctx->r25;
    // 0x8013404C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134050: bne         $v0, $at, L_80134074
    if (ctx->r2 != ctx->r1) {
        // 0x80134054: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_80134074;
    }
    // 0x80134054: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80134058: lw          $t1, 0x4964($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4964);
    // 0x8013405C: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80134060: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134064: sw          $zero, 0x7C($t1)
    MEM_W(0X7C, ctx->r9) = 0;
    // 0x80134068: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013406C: lw          $v0, 0x4948($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4948);
    // 0x80134070: sw          $t2, 0x4970($at)
    MEM_W(0X4970, ctx->r1) = ctx->r10;
L_80134074:
    // 0x80134074: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80134078: bne         $v0, $at, L_80134094
    if (ctx->r2 != ctx->r1) {
        // 0x8013407C: lui         $t3, 0x8013
        ctx->r11 = S32(0X8013 << 16);
            goto L_80134094;
    }
    // 0x8013407C: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80134080: lw          $t3, 0x4968($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4968);
    // 0x80134084: addiu       $t4, $zero, 0x1E
    ctx->r12 = ADD32(0, 0X1E);
    // 0x80134088: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013408C: sw          $zero, 0x7C($t3)
    MEM_W(0X7C, ctx->r11) = 0;
    // 0x80134090: sw          $t4, 0x496C($at)
    MEM_W(0X496C, ctx->r1) = ctx->r12;
L_80134094:
    // 0x80134094: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134098: lw          $v0, 0x4948($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4948);
    // 0x8013409C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801340A0: beq         $v0, $at, L_801340B8
    if (ctx->r2 == ctx->r1) {
        // 0x801340A4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801340B8;
    }
    // 0x801340A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801340A8: beq         $v0, $at, L_801342E0
    if (ctx->r2 == ctx->r1) {
        // 0x801340AC: nop
    
            goto L_801342E0;
    }
    // 0x801340AC: nop

    // 0x801340B0: b           L_801345B8
    // 0x801340B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801345B8;
    // 0x801340B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801340B8:
    // 0x801340B8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801340BC: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
    // 0x801340C0: bne         $v0, $zero, L_801340E0
    if (ctx->r2 != 0) {
        // 0x801340C4: nop
    
            goto L_801340E0;
    }
    // 0x801340C4: nop

    // 0x801340C8: jal         0x80390804
    // 0x801340CC: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_32;
    // 0x801340CC: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_32:
    // 0x801340D0: bne         $v0, $zero, L_801340F8
    if (ctx->r2 != 0) {
        // 0x801340D4: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_801340F8;
    }
    // 0x801340D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801340D8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801340DC: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
L_801340E0:
    // 0x801340E0: bne         $v0, $zero, L_801341C4
    if (ctx->r2 != 0) {
        // 0x801340E4: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_801341C4;
    }
    // 0x801340E4: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x801340E8: jal         0x8039089C
    // 0x801340EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_33;
    // 0x801340EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x801340F0: beq         $v0, $zero, L_801341C4
    if (ctx->r2 == 0) {
        // 0x801340F4: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_801341C4;
    }
    // 0x801340F4: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_801340F8:
    // 0x801340F8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801340FC: lw          $t5, 0x494C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X494C);
    // 0x80134100: blez        $t5, L_801341C4
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80134104: nop
    
            goto L_801341C4;
    }
    // 0x80134104: nop

    // 0x80134108: jal         0x800269C0
    // 0x8013410C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_34;
    // 0x8013410C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_34:
    // 0x80134110: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134114: addiu       $v1, $v1, 0x494C
    ctx->r3 = ADD32(ctx->r3, 0X494C);
    // 0x80134118: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8013411C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134120: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80134124: bne         $t7, $at, L_80134134
    if (ctx->r15 != ctx->r1) {
        // 0x80134128: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80134134;
    }
    // 0x80134128: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013412C: jal         0x80133A8C
    // 0x80134130: nop

    mnVSModeSetCostumesAndShades(rdram, ctx);
        goto after_35;
    // 0x80134130: nop

    after_35:
L_80134134:
    // 0x80134134: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134138: jal         0x80009A84
    // 0x8013413C: lw          $a0, 0x4938($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4938);
    gcEjectGObj(rdram, ctx);
        goto after_36;
    // 0x8013413C: lw          $a0, 0x4938($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4938);
    after_36:
    // 0x80134140: jal         0x80132D04
    // 0x80134144: nop

    mnVSModeMakeTimeStockButton(rdram, ctx);
        goto after_37;
    // 0x80134144: nop

    after_37:
    // 0x80134148: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013414C: jal         0x80009A84
    // 0x80134150: lw          $a0, 0x4958($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4958);
    gcEjectGObj(rdram, ctx);
        goto after_38;
    // 0x80134150: lw          $a0, 0x4958($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4958);
    after_38:
    // 0x80134154: jal         0x80132238
    // 0x80134158: nop

    mnVSModeMakeRuleValue(rdram, ctx);
        goto after_39;
    // 0x80134158: nop

    after_39:
    // 0x8013415C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134160: jal         0x80009A84
    // 0x80134164: lw          $a0, 0x495C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X495C);
    gcEjectGObj(rdram, ctx);
        goto after_40;
    // 0x80134164: lw          $a0, 0x495C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X495C);
    after_40:
    // 0x80134168: jal         0x80132BA0
    // 0x8013416C: nop

    mnVSModeMakeTimeStockValue(rdram, ctx);
        goto after_41;
    // 0x8013416C: nop

    after_41:
    // 0x80134170: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80134174: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80134178: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013417C: beq         $t0, $zero, L_80134194
    if (ctx->r8 == 0) {
        // 0x80134180: addiu       $t2, $t1, 0xA0
        ctx->r10 = ADD32(ctx->r9, 0XA0);
            goto L_80134194;
    }
    // 0x80134180: addiu       $t2, $t1, 0xA0
    ctx->r10 = ADD32(ctx->r9, 0XA0);
    // 0x80134184: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80134188: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013418C: b           L_801341A8
    // 0x80134190: sw          $t9, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r25;
        goto L_801341A8;
    // 0x80134190: sw          $t9, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r25;
L_80134194:
    // 0x80134194: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80134198: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x8013419C: mflo        $t3
    ctx->r11 = lo;
    // 0x801341A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801341A4: sw          $t3, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r11;
L_801341A8:
    // 0x801341A8: jal         0x80009A84
    // 0x801341AC: lw          $a0, 0x4960($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4960);
    gcEjectGObj(rdram, ctx);
        goto after_42;
    // 0x801341AC: lw          $a0, 0x4960($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4960);
    after_42:
    // 0x801341B0: jal         0x80132FD8
    // 0x801341B4: nop

    mnVSModeMakeSubtitle(rdram, ctx);
        goto after_43;
    // 0x801341B4: nop

    after_43:
    // 0x801341B8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x801341BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801341C0: sw          $t4, 0x4978($at)
    MEM_W(0X4978, ctx->r1) = ctx->r12;
L_801341C4:
    // 0x801341C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801341C8: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
    // 0x801341CC: bne         $v0, $zero, L_801341EC
    if (ctx->r2 != 0) {
        // 0x801341D0: nop
    
            goto L_801341EC;
    }
    // 0x801341D0: nop

    // 0x801341D4: jal         0x80390804
    // 0x801341D8: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_44;
    // 0x801341D8: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_44:
    // 0x801341DC: bne         $v0, $zero, L_80134204
    if (ctx->r2 != 0) {
        // 0x801341E0: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80134204;
    }
    // 0x801341E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801341E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801341E8: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
L_801341EC:
    // 0x801341EC: bne         $v0, $zero, L_801345B4
    if (ctx->r2 != 0) {
        // 0x801341F0: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_801345B4;
    }
    // 0x801341F0: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801341F4: jal         0x8039089C
    // 0x801341F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_45;
    // 0x801341F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_45:
    // 0x801341FC: beq         $v0, $zero, L_801345B4
    if (ctx->r2 == 0) {
        // 0x80134200: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_801345B4;
    }
    // 0x80134200: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80134204:
    // 0x80134204: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80134208: lw          $t5, 0x494C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X494C);
    // 0x8013420C: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x80134210: beql        $at, $zero, L_801345B8
    if (ctx->r1 == 0) {
        // 0x80134214: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801345B8;
    }
    goto skip_0;
    // 0x80134214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80134218: jal         0x800269C0
    // 0x8013421C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_46;
    // 0x8013421C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_46:
    // 0x80134220: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134224: lw          $t6, 0x494C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X494C);
    // 0x80134228: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013422C: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80134230: sw          $t7, 0x494C($at)
    MEM_W(0X494C, ctx->r1) = ctx->r15;
    // 0x80134234: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80134238: bne         $t7, $at, L_80134248
    if (ctx->r15 != ctx->r1) {
        // 0x8013423C: nop
    
            goto L_80134248;
    }
    // 0x8013423C: nop

    // 0x80134240: jal         0x80133A8C
    // 0x80134244: nop

    mnVSModeSetCostumesAndShades(rdram, ctx);
        goto after_47;
    // 0x80134244: nop

    after_47:
L_80134248:
    // 0x80134248: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013424C: jal         0x80009A84
    // 0x80134250: lw          $a0, 0x4938($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4938);
    gcEjectGObj(rdram, ctx);
        goto after_48;
    // 0x80134250: lw          $a0, 0x4938($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4938);
    after_48:
    // 0x80134254: jal         0x80132D04
    // 0x80134258: nop

    mnVSModeMakeTimeStockButton(rdram, ctx);
        goto after_49;
    // 0x80134258: nop

    after_49:
    // 0x8013425C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134260: jal         0x80009A84
    // 0x80134264: lw          $a0, 0x4958($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4958);
    gcEjectGObj(rdram, ctx);
        goto after_50;
    // 0x80134264: lw          $a0, 0x4958($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4958);
    after_50:
    // 0x80134268: jal         0x80132238
    // 0x8013426C: nop

    mnVSModeMakeRuleValue(rdram, ctx);
        goto after_51;
    // 0x8013426C: nop

    after_51:
    // 0x80134270: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134274: jal         0x80009A84
    // 0x80134278: lw          $a0, 0x495C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X495C);
    gcEjectGObj(rdram, ctx);
        goto after_52;
    // 0x80134278: lw          $a0, 0x495C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X495C);
    after_52:
    // 0x8013427C: jal         0x80132BA0
    // 0x80134280: nop

    mnVSModeMakeTimeStockValue(rdram, ctx);
        goto after_53;
    // 0x80134280: nop

    after_53:
    // 0x80134284: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80134288: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8013428C: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x80134290: beq         $t8, $zero, L_801342A8
    if (ctx->r24 == 0) {
        // 0x80134294: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801342A8;
    }
    // 0x80134294: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134298: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8013429C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342A0: b           L_801342C0
    // 0x801342A4: sw          $t0, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r8;
        goto L_801342C0;
    // 0x801342A4: sw          $t0, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r8;
L_801342A8:
    // 0x801342A8: subu        $t2, $t1, $t9
    ctx->r10 = SUB32(ctx->r9, ctx->r25);
    // 0x801342AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801342B0: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x801342B4: mflo        $t3
    ctx->r11 = lo;
    // 0x801342B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342BC: sw          $t3, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r11;
L_801342C0:
    // 0x801342C0: jal         0x80009A84
    // 0x801342C4: lw          $a0, 0x4960($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4960);
    gcEjectGObj(rdram, ctx);
        goto after_54;
    // 0x801342C4: lw          $a0, 0x4960($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4960);
    after_54:
    // 0x801342C8: jal         0x80132FD8
    // 0x801342CC: nop

    mnVSModeMakeSubtitle(rdram, ctx);
        goto after_55;
    // 0x801342CC: nop

    after_55:
    // 0x801342D0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x801342D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342D8: b           L_801345B4
    // 0x801342DC: sw          $t4, 0x4978($at)
    MEM_W(0X4978, ctx->r1) = ctx->r12;
        goto L_801345B4;
    // 0x801342DC: sw          $t4, 0x4978($at)
    MEM_W(0X4978, ctx->r1) = ctx->r12;
L_801342E0:
    // 0x801342E0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801342E4: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
    // 0x801342E8: bne         $v0, $zero, L_80134308
    if (ctx->r2 != 0) {
        // 0x801342EC: nop
    
            goto L_80134308;
    }
    // 0x801342EC: nop

    // 0x801342F0: jal         0x80390804
    // 0x801342F4: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_56;
    // 0x801342F4: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_56:
    // 0x801342F8: bne         $v0, $zero, L_80134320
    if (ctx->r2 != 0) {
        // 0x801342FC: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80134320;
    }
    // 0x801342FC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80134300: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134304: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
L_80134308:
    // 0x80134308: bne         $v0, $zero, L_80134448
    if (ctx->r2 != 0) {
        // 0x8013430C: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80134448;
    }
    // 0x8013430C: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80134310: jal         0x8039089C
    // 0x80134314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_57;
    // 0x80134314: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_57:
    // 0x80134318: beq         $v0, $zero, L_80134448
    if (ctx->r2 == 0) {
        // 0x8013431C: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_80134448;
    }
    // 0x8013431C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80134320:
    // 0x80134320: jal         0x800269C0
    // 0x80134324: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_58;
    // 0x80134324: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_58:
    // 0x80134328: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x8013432C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134330: addiu       $v0, $v0, 0x497C
    ctx->r2 = ADD32(ctx->r2, 0X497C);
    // 0x80134334: beq         $t5, $zero, L_80134344
    if (ctx->r13 == 0) {
        // 0x80134338: addiu       $t6, $zero, 0xC
        ctx->r14 = ADD32(0, 0XC);
            goto L_80134344;
    }
    // 0x80134338: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x8013433C: b           L_80134368
    // 0x80134340: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
        goto L_80134368;
    // 0x80134340: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80134344:
    // 0x80134344: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80134348: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x8013434C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134350: addiu       $t8, $t7, 0xA0
    ctx->r24 = ADD32(ctx->r15, 0XA0);
    // 0x80134354: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80134358: mflo        $t0
    ctx->r8 = lo;
    // 0x8013435C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134360: sw          $t0, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r8;
    // 0x80134364: addiu       $v0, $v0, 0x497C
    ctx->r2 = ADD32(ctx->r2, 0X497C);
L_80134368:
    // 0x80134368: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013436C: lw          $t1, 0x4978($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4978);
    // 0x80134370: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80134374: beq         $t1, $at, L_80134388
    if (ctx->r9 == ctx->r1) {
        // 0x80134378: nop
    
            goto L_80134388;
    }
    // 0x80134378: nop

    // 0x8013437C: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80134380: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x80134384: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80134388:
    // 0x80134388: jal         0x80132B38
    // 0x8013438C: nop

    mnVSModeIsTime(rdram, ctx);
        goto after_59;
    // 0x8013438C: nop

    after_59:
    // 0x80134390: beq         $v0, $zero, L_801343E8
    if (ctx->r2 == 0) {
        // 0x80134394: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_801343E8;
    }
    // 0x80134394: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134398: addiu       $v1, $v1, 0x4950
    ctx->r3 = ADD32(ctx->r3, 0X4950);
    // 0x8013439C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801343A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801343A4: addiu       $t3, $zero, 0x64
    ctx->r11 = ADD32(0, 0X64);
    // 0x801343A8: bne         $v0, $at, L_801343B8
    if (ctx->r2 != ctx->r1) {
        // 0x801343AC: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_801343B8;
    }
    // 0x801343AC: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x801343B0: b           L_801343BC
    // 0x801343B4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_801343BC;
    // 0x801343B4: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_801343B8:
    // 0x801343B8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_801343BC:
    // 0x801343BC: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x801343C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801343C4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801343C8: bne         $t5, $at, L_801343E0
    if (ctx->r13 != ctx->r1) {
        // 0x801343CC: nop
    
            goto L_801343E0;
    }
    // 0x801343CC: nop

    // 0x801343D0: lw          $t6, 0x497C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X497C);
    // 0x801343D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801343D8: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x801343DC: sw          $t7, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r15;
L_801343E0:
    // 0x801343E0: b           L_80134428
    // 0x801343E4: nop

        goto L_80134428;
    // 0x801343E4: nop

L_801343E8:
    // 0x801343E8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801343EC: addiu       $a1, $a1, 0x4954
    ctx->r5 = ADD32(ctx->r5, 0X4954);
    // 0x801343F0: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x801343F4: bne         $v0, $zero, L_80134404
    if (ctx->r2 != 0) {
        // 0x801343F8: addiu       $t8, $zero, 0x62
        ctx->r24 = ADD32(0, 0X62);
            goto L_80134404;
    }
    // 0x801343F8: addiu       $t8, $zero, 0x62
    ctx->r24 = ADD32(0, 0X62);
    // 0x801343FC: b           L_8013440C
    // 0x80134400: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
        goto L_8013440C;
    // 0x80134400: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
L_80134404:
    // 0x80134404: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80134408: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
L_8013440C:
    // 0x8013440C: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80134410: bne         $t1, $zero, L_80134428
    if (ctx->r9 != 0) {
        // 0x80134414: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_80134428;
    }
    // 0x80134414: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80134418: lw          $t9, 0x497C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X497C);
    // 0x8013441C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134420: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80134424: sw          $t2, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r10;
L_80134428:
    // 0x80134428: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013442C: jal         0x80009A84
    // 0x80134430: lw          $a0, 0x495C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X495C);
    gcEjectGObj(rdram, ctx);
        goto after_60;
    // 0x80134430: lw          $a0, 0x495C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X495C);
    after_60:
    // 0x80134434: jal         0x80132BA0
    // 0x80134438: nop

    mnVSModeMakeTimeStockValue(rdram, ctx);
        goto after_61;
    // 0x80134438: nop

    after_61:
    // 0x8013443C: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80134440: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134444: sw          $t3, 0x4978($at)
    MEM_W(0X4978, ctx->r1) = ctx->r11;
L_80134448:
    // 0x80134448: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013444C: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
    // 0x80134450: bne         $v0, $zero, L_80134470
    if (ctx->r2 != 0) {
        // 0x80134454: nop
    
            goto L_80134470;
    }
    // 0x80134454: nop

    // 0x80134458: jal         0x80390804
    // 0x8013445C: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_62;
    // 0x8013445C: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_62:
    // 0x80134460: bne         $v0, $zero, L_80134488
    if (ctx->r2 != 0) {
        // 0x80134464: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80134488;
    }
    // 0x80134464: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80134468: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013446C: lw          $v0, 0x497C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X497C);
L_80134470:
    // 0x80134470: bne         $v0, $zero, L_801345B4
    if (ctx->r2 != 0) {
        // 0x80134474: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_801345B4;
    }
    // 0x80134474: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80134478: jal         0x8039089C
    // 0x8013447C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_63;
    // 0x8013447C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_63:
    // 0x80134480: beq         $v0, $zero, L_801345B4
    if (ctx->r2 == 0) {
        // 0x80134484: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_801345B4;
    }
    // 0x80134484: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_80134488:
    // 0x80134488: jal         0x800269C0
    // 0x8013448C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_64;
    // 0x8013448C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_64:
    // 0x80134490: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80134494: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80134498: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x8013449C: beq         $t4, $zero, L_801344B4
    if (ctx->r12 == 0) {
        // 0x801344A0: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_801344B4;
    }
    // 0x801344A0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801344A4: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x801344A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801344AC: b           L_801344CC
    // 0x801344B0: sw          $t5, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r13;
        goto L_801344CC;
    // 0x801344B0: sw          $t5, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r13;
L_801344B4:
    // 0x801344B4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x801344B8: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x801344BC: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x801344C0: mflo        $t0
    ctx->r8 = lo;
    // 0x801344C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801344C8: sw          $t0, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r8;
L_801344CC:
    // 0x801344CC: lw          $t1, 0x4978($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4978);
    // 0x801344D0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801344D4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801344D8: beq         $t1, $at, L_801344F0
    if (ctx->r9 == ctx->r1) {
        // 0x801344DC: nop
    
            goto L_801344F0;
    }
    // 0x801344DC: nop

    // 0x801344E0: lw          $t9, 0x497C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X497C);
    // 0x801344E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801344E8: sll         $t2, $t9, 1
    ctx->r10 = S32(ctx->r25 << 1);
    // 0x801344EC: sw          $t2, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r10;
L_801344F0:
    // 0x801344F0: jal         0x80132B38
    // 0x801344F4: nop

    mnVSModeIsTime(rdram, ctx);
        goto after_65;
    // 0x801344F4: nop

    after_65:
    // 0x801344F8: beq         $v0, $zero, L_80134550
    if (ctx->r2 == 0) {
        // 0x801344FC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80134550;
    }
    // 0x801344FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134500: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134504: addiu       $v1, $v1, 0x4950
    ctx->r3 = ADD32(ctx->r3, 0X4950);
    // 0x80134508: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013450C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80134510: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80134514: bne         $v0, $at, L_80134524
    if (ctx->r2 != ctx->r1) {
        // 0x80134518: addiu       $t4, $v0, 0x1
        ctx->r12 = ADD32(ctx->r2, 0X1);
            goto L_80134524;
    }
    // 0x80134518: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x8013451C: b           L_80134528
    // 0x80134520: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_80134528;
    // 0x80134520: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80134524:
    // 0x80134524: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80134528:
    // 0x80134528: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x8013452C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80134530: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80134534: bne         $t5, $at, L_80134598
    if (ctx->r13 != ctx->r1) {
        // 0x80134538: nop
    
            goto L_80134598;
    }
    // 0x80134538: nop

    // 0x8013453C: lw          $t7, 0x497C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X497C);
    // 0x80134540: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134544: addiu       $t6, $t7, 0x8
    ctx->r14 = ADD32(ctx->r15, 0X8);
    // 0x80134548: b           L_80134598
    // 0x8013454C: sw          $t6, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r14;
        goto L_80134598;
    // 0x8013454C: sw          $t6, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r14;
L_80134550:
    // 0x80134550: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134554: addiu       $v1, $v1, 0x4954
    ctx->r3 = ADD32(ctx->r3, 0X4954);
    // 0x80134558: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013455C: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x80134560: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80134564: bne         $v0, $at, L_80134574
    if (ctx->r2 != ctx->r1) {
        // 0x80134568: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80134574;
    }
    // 0x80134568: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8013456C: b           L_80134578
    // 0x80134570: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_80134578;
    // 0x80134570: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80134574:
    // 0x80134574: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80134578:
    // 0x80134578: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8013457C: addiu       $at, $zero, 0x62
    ctx->r1 = ADD32(0, 0X62);
    // 0x80134580: bne         $t0, $at, L_80134598
    if (ctx->r8 != ctx->r1) {
        // 0x80134584: nop
    
            goto L_80134598;
    }
    // 0x80134584: nop

    // 0x80134588: lw          $t1, 0x497C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X497C);
    // 0x8013458C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134590: addiu       $t9, $t1, 0x8
    ctx->r25 = ADD32(ctx->r9, 0X8);
    // 0x80134594: sw          $t9, 0x497C($at)
    MEM_W(0X497C, ctx->r1) = ctx->r25;
L_80134598:
    // 0x80134598: jal         0x80009A84
    // 0x8013459C: lw          $a0, 0x495C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X495C);
    gcEjectGObj(rdram, ctx);
        goto after_66;
    // 0x8013459C: lw          $a0, 0x495C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X495C);
    after_66:
    // 0x801345A0: jal         0x80132BA0
    // 0x801345A4: nop

    mnVSModeMakeTimeStockValue(rdram, ctx);
        goto after_67;
    // 0x801345A4: nop

    after_67:
    // 0x801345A8: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x801345AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801345B0: sw          $t2, 0x4978($at)
    MEM_W(0X4978, ctx->r1) = ctx->r10;
L_801345B4:
    // 0x801345B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801345B8:
    // 0x801345B8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801345BC: jr          $ra
    // 0x801345C0: nop

    return;
    // 0x801345C0: nop

;}
RECOMP_FUNC void mnVSOptionsTintProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013334C: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80133350: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80133354: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013335C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133360: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80133364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80133368: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013336C: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80133370: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80133374: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133378: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013337C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80133380: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80133384: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80133388: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8013338C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133390: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80133394: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133398: lui         $t7, 0xD00
    ctx->r15 = S32(0XD00 << 16);
    // 0x8013339C: ori         $t7, $t7, 0x99
    ctx->r15 = ctx->r15 | 0X99;
    // 0x801333A0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801333A4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801333A8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801333AC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801333B0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801333B4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801333B8: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x801333BC: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x801333C0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801333C4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801333C8: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801333CC: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x801333D0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801333D4: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801333D8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801333DC: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x801333E0: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x801333E4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801333E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801333EC: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x801333F0: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x801333F4: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x801333F8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x801333FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133400: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80133404: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x80133408: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013340C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133410: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x80133414: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x80133418: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013341C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80133420: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133424: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x80133428: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x8013342C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80133430: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80133434: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80133438: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8013343C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133440: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80133444: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80133448: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8013344C: jal         0x800CCEAC
    // 0x80133450: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80133450: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    after_0:
    // 0x80133454: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133458: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013345C: jr          $ra
    // 0x80133460: nop

    return;
    // 0x80133460: nop

;}
RECOMP_FUNC void func_ovl8_80383BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383BC4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80383BC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80383BCC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80383BD0: lw          $t6, 0x48($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X48);
    // 0x80383BD4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80383BD8: bnel        $t6, $zero, L_80383D3C
    if (ctx->r14 != 0) {
        // 0x80383BDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80383D3C;
    }
    goto skip_0;
    // 0x80383BDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80383BE0: lw          $a2, 0x38($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X38);
    // 0x80383BE4: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x80383BE8: lw          $t9, 0xBC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XBC);
    // 0x80383BEC: lh          $t7, 0xB8($v1)
    ctx->r15 = MEM_H(ctx->r3, 0XB8);
    // 0x80383BF0: jalr        $t9
    // 0x80383BF4: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383BF4: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_0:
    // 0x80383BF8: beq         $v0, $zero, L_80383D38
    if (ctx->r2 == 0) {
        // 0x80383BFC: sw          $v0, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r2;
            goto L_80383D38;
    }
    // 0x80383BFC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x80383C00: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x80383C04: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x80383C08: beql        $t8, $zero, L_80383D28
    if (ctx->r24 == 0) {
        // 0x80383C0C: lw          $v1, 0x30($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X30);
            goto L_80383D28;
    }
    goto skip_1;
    // 0x80383C0C: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    skip_1:
    // 0x80383C10: jal         0x8037D95C
    // 0x80383C14: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    func_ovl8_8037D95C(rdram, ctx);
        goto after_1;
    // 0x80383C14: sw          $zero, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = 0;
    after_1:
    // 0x80383C18: jal         0x8037E7A8
    // 0x80383C1C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_2;
    // 0x80383C1C: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    after_2:
    // 0x80383C20: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x80383C24: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80383C28: lw          $v1, 0x58($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X58);
    // 0x80383C2C: lw          $t9, 0xAC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XAC);
    // 0x80383C30: lh          $t0, 0xA8($v1)
    ctx->r8 = MEM_H(ctx->r3, 0XA8);
    // 0x80383C34: jalr        $t9
    // 0x80383C38: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80383C38: addu        $a0, $t0, $a2
    ctx->r4 = ADD32(ctx->r8, ctx->r6);
    after_3:
    // 0x80383C3C: lw          $a3, 0x38($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X38);
    // 0x80383C40: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80383C44: addiu       $a2, $a2, -0x3328
    ctx->r6 = ADD32(ctx->r6, -0X3328);
    // 0x80383C48: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80383C4C: addiu       $a1, $sp, 0x50
    ctx->r5 = ADD32(ctx->r29, 0X50);
    // 0x80383C50: jal         0x8037B46C
    // 0x80383C54: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    func_ovl8_8037B46C(rdram, ctx);
        goto after_4;
    // 0x80383C54: addiu       $a3, $a3, 0x18
    ctx->r7 = ADD32(ctx->r7, 0X18);
    after_4:
    // 0x80383C58: jal         0x8037D990
    // 0x80383C5C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_ovl8_8037D990(rdram, ctx);
        goto after_5;
    // 0x80383C5C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_5:
    // 0x80383C60: lw          $a0, 0x38($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X38);
    // 0x80383C64: jal         0x8037D9D0
    // 0x80383C68: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    func_ovl8_8037D9D0(rdram, ctx);
        goto after_6;
    // 0x80383C68: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_6:
    // 0x80383C6C: lh          $t1, 0x50($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X50);
    // 0x80383C70: lh          $t3, 0x52($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X52);
    // 0x80383C74: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80383C78: addiu       $t2, $t1, 0x6
    ctx->r10 = ADD32(ctx->r9, 0X6);
    // 0x80383C7C: addiu       $t4, $t3, 0x6
    ctx->r12 = ADD32(ctx->r11, 0X6);
    // 0x80383C80: sh          $t4, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r12;
    // 0x80383C84: sh          $t2, 0x44($sp)
    MEM_H(0X44, ctx->r29) = ctx->r10;
    // 0x80383C88: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x80383C8C: jal         0x8037A5B8
    // 0x80383C90: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    func_ovl8_8037A5B8(rdram, ctx);
        goto after_7;
    // 0x80383C90: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    after_7:
    // 0x80383C94: jal         0x8037D9B4
    // 0x80383C98: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_8;
    // 0x80383C98: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_8:
    // 0x80383C9C: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
    // 0x80383CA0: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x80383CA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80383CA8: lw          $t9, 0x12C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X12C);
    // 0x80383CAC: lh          $t5, 0x128($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X128);
    // 0x80383CB0: jalr        $t9
    // 0x80383CB4: addu        $a0, $t5, $s0
    ctx->r4 = ADD32(ctx->r13, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_9;
    // 0x80383CB4: addu        $a0, $t5, $s0
    ctx->r4 = ADD32(ctx->r13, ctx->r16);
    after_9:
    // 0x80383CB8: jal         0x8037E80C
    // 0x80383CBC: nop

    func_ovl8_8037E80C(rdram, ctx);
        goto after_10;
    // 0x80383CBC: nop

    after_10:
    // 0x80383CC0: lhu         $t0, 0x56($sp)
    ctx->r8 = MEM_HU(ctx->r29, 0X56);
    // 0x80383CC4: lh          $t8, 0x52($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X52);
    // 0x80383CC8: lh          $t6, 0x50($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X50);
    // 0x80383CCC: lh          $t7, 0x48($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X48);
    // 0x80383CD0: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x80383CD4: sll         $a0, $a0, 16
    ctx->r4 = S32(ctx->r4 << 16);
    // 0x80383CD8: sra         $a0, $a0, 16
    ctx->r4 = S32(SIGNED(ctx->r4) >> 16);
    // 0x80383CDC: bgez        $t0, L_80383CEC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80383CE0: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_80383CEC;
    }
    // 0x80383CE0: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x80383CE4: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x80383CE8: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_80383CEC:
    // 0x80383CEC: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80383CF0: bgez        $v0, L_80383D00
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80383CF4: sra         $t3, $v0, 1
        ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80383D00;
    }
    // 0x80383CF4: sra         $t3, $v0, 1
    ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80383CF8: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x80383CFC: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_80383D00:
    // 0x80383D00: subu        $a1, $t2, $t3
    ctx->r5 = SUB32(ctx->r10, ctx->r11);
    // 0x80383D04: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80383D08: jal         0x8037DFCC
    // 0x80383D0C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_11;
    // 0x80383D0C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    after_11:
    // 0x80383D10: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    // 0x80383D14: jal         0x8037DD60
    // 0x80383D18: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    func_ovl8_8037DD60(rdram, ctx);
        goto after_12;
    // 0x80383D18: lw          $a1, 0x3C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X3C);
    after_12:
    // 0x80383D1C: jal         0x8037D908
    // 0x80383D20: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    func_ovl8_8037D908(rdram, ctx);
        goto after_13;
    // 0x80383D20: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_13:
    // 0x80383D24: lw          $v1, 0x30($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X30);
L_80383D28:
    // 0x80383D28: lw          $t9, 0x134($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X134);
    // 0x80383D2C: lh          $t4, 0x130($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X130);
    // 0x80383D30: jalr        $t9
    // 0x80383D34: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_14;
    // 0x80383D34: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    after_14:
L_80383D38:
    // 0x80383D38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80383D3C:
    // 0x80383D3C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80383D40: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80383D44: jr          $ra
    // 0x80383D48: nop

    return;
    // 0x80383D48: nop

;}
RECOMP_FUNC void func_ovl8_80374D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374D00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374D04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374D08: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374D0C: lw          $t9, 0x8C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8C);
    // 0x80374D10: lh          $t6, 0x88($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X88);
    // 0x80374D14: jalr        $t9
    // 0x80374D18: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374D18: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374D20: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374D24: jr          $ra
    // 0x80374D28: nop

    return;
    // 0x80374D28: nop

;}
RECOMP_FUNC void func_ovl8_80374624(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374624: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80374628: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037462C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80374630: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80374634: jal         0x803717A0
    // 0x80374638: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80374638: addiu       $a0, $zero, 0xCC
    ctx->r4 = ADD32(0, 0XCC);
    after_0:
    // 0x8037463C: beq         $v0, $zero, L_80374668
    if (ctx->r2 == 0) {
        // 0x80374640: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80374668;
    }
    // 0x80374640: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80374644: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80374648: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8037464C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80374650: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80374654: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80374658: jal         0x8037FCD8
    // 0x8037465C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_8037FCD8(rdram, ctx);
        goto after_1;
    // 0x8037465C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x80374660: b           L_8037466C
    // 0x80374664: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_8037466C;
    // 0x80374664: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80374668:
    // 0x80374668: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8037466C:
    // 0x8037466C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80374670: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80374674: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80374678: jr          $ra
    // 0x8037467C: nop

    return;
    // 0x8037467C: nop

;}
RECOMP_FUNC void ftCommonGuardKneeBendCheckInterruptGuard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F604: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013F608: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F60C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013F610: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8013F614: jal         0x8013F474
    // 0x8013F618: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftCommonKneeBendGetInputTypeCommon(rdram, ctx);
        goto after_0;
    // 0x8013F618: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013F61C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8013F620: beq         $v0, $zero, L_8013F64C
    if (ctx->r2 == 0) {
        // 0x8013F624: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8013F64C;
    }
    // 0x8013F624: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8013F628: lhu         $t7, 0x1BC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1BC);
    // 0x8013F62C: lhu         $t8, 0x1B8($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X1B8);
    // 0x8013F630: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8013F634: beql        $t9, $zero, L_8013F650
    if (ctx->r25 == 0) {
        // 0x8013F638: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013F650;
    }
    goto skip_0;
    // 0x8013F638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8013F63C: jal         0x8013F42C
    // 0x8013F640: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonGuardKneeBendSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013F640: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8013F644: b           L_8013F650
    // 0x8013F648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013F650;
    // 0x8013F648: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013F64C:
    // 0x8013F64C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013F650:
    // 0x8013F650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013F654: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013F658: jr          $ra
    // 0x8013F65C: nop

    return;
    // 0x8013F65C: nop

;}
RECOMP_FUNC void func_ovl8_80385A50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385A50: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80385A54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80385A58: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80385A5C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80385A60: jal         0x803717A0
    // 0x80385A64: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80385A64: addiu       $a0, $zero, 0x140
    ctx->r4 = ADD32(0, 0X140);
    after_0:
    // 0x80385A68: beq         $v0, $zero, L_80385A94
    if (ctx->r2 == 0) {
        // 0x80385A6C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80385A94;
    }
    // 0x80385A6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80385A70: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80385A74: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80385A78: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80385A7C: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80385A80: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80385A84: jal         0x80385B74
    // 0x80385A88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    func_ovl8_80385B74(rdram, ctx);
        goto after_1;
    // 0x80385A88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_1:
    // 0x80385A8C: b           L_80385A98
    // 0x80385A90: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80385A98;
    // 0x80385A90: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80385A94:
    // 0x80385A94: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80385A98:
    // 0x80385A98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80385A9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80385AA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80385AA4: jr          $ra
    // 0x80385AA8: nop

    return;
    // 0x80385AA8: nop

;}
RECOMP_FUNC void ftMainEjectHiddenPartID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E6E00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E6E04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E6E08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E6E0C: lw          $t7, 0x9C8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X9C8);
    // 0x800E6E10: sll         $t9, $a1, 4
    ctx->r25 = S32(ctx->r5 << 4);
    // 0x800E6E14: lw          $t8, 0x2D0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X2D0);
    // 0x800E6E18: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x800E6E1C: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x800E6E20: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800E6E24: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x800E6E28: lw          $a2, 0x8E8($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X8E8);
    // 0x800E6E2C: lw          $a0, 0x84($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X84);
    // 0x800E6E30: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800E6E34: jal         0x800D767C
    // 0x800E6E38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    ftManagerSetPrevPartsAlloc(rdram, ctx);
        goto after_0;
    // 0x800E6E38: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E6E3C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800E6E40: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800E6E44: lw          $a1, 0x10($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X10);
    // 0x800E6E48: lw          $a0, 0x14($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X14);
    // 0x800E6E4C: beql        $a1, $zero, L_800E6EBC
    if (ctx->r5 == 0) {
        // 0x800E6E50: lw          $v0, 0xC($a2)
        ctx->r2 = MEM_W(ctx->r6, 0XC);
            goto L_800E6EBC;
    }
    goto skip_0;
    // 0x800E6E50: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    skip_0:
    // 0x800E6E54: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x800E6E58: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x800E6E5C: bnel        $v0, $zero, L_800E6E70
    if (ctx->r2 != 0) {
        // 0x800E6E60: sw          $v1, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r3;
            goto L_800E6E70;
    }
    goto skip_1;
    // 0x800E6E60: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    skip_1:
    // 0x800E6E64: b           L_800E6E78
    // 0x800E6E68: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
        goto L_800E6E78;
    // 0x800E6E68: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
    // 0x800E6E6C: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
L_800E6E70:
    // 0x800E6E70: lw          $t3, 0xC($a2)
    ctx->r11 = MEM_W(ctx->r6, 0XC);
    // 0x800E6E74: sw          $t3, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r11;
L_800E6E78:
    // 0x800E6E78: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x800E6E7C: sw          $a0, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r4;
    // 0x800E6E80: beql        $v0, $zero, L_800E6EA0
    if (ctx->r2 == 0) {
        // 0x800E6E84: lw          $t4, 0x8($a2)
        ctx->r12 = MEM_W(ctx->r6, 0X8);
            goto L_800E6EA0;
    }
    goto skip_2;
    // 0x800E6E84: lw          $t4, 0x8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8);
    skip_2:
    // 0x800E6E88: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800E6E8C:
    // 0x800E6E8C: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x800E6E90: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800E6E94: bnel        $v0, $zero, L_800E6E8C
    if (ctx->r2 != 0) {
        // 0x800E6E98: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800E6E8C;
    }
    goto skip_3;
    // 0x800E6E98: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    skip_3:
    // 0x800E6E9C: lw          $t4, 0x8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8);
L_800E6EA0:
    // 0x800E6EA0: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x800E6EA4: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x800E6EA8: beql        $v0, $zero, L_800E6EF0
    if (ctx->r2 == 0) {
        // 0x800E6EAC: lw          $t0, 0x0($a3)
        ctx->r8 = MEM_W(ctx->r7, 0X0);
            goto L_800E6EF0;
    }
    goto skip_4;
    // 0x800E6EAC: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    skip_4:
    // 0x800E6EB0: b           L_800E6EEC
    // 0x800E6EB4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
        goto L_800E6EEC;
    // 0x800E6EB4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x800E6EB8: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
L_800E6EBC:
    // 0x800E6EBC: bnel        $v0, $zero, L_800E6ED4
    if (ctx->r2 != 0) {
        // 0x800E6EC0: lw          $t7, 0x8($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X8);
            goto L_800E6ED4;
    }
    goto skip_5;
    // 0x800E6EC0: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
    skip_5:
    // 0x800E6EC4: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800E6EC8: b           L_800E6ED8
    // 0x800E6ECC: sw          $t5, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r13;
        goto L_800E6ED8;
    // 0x800E6ECC: sw          $t5, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r13;
    // 0x800E6ED0: lw          $t7, 0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X8);
L_800E6ED4:
    // 0x800E6ED4: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
L_800E6ED8:
    // 0x800E6ED8: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    // 0x800E6EDC: beql        $v0, $zero, L_800E6EF0
    if (ctx->r2 == 0) {
        // 0x800E6EE0: lw          $t0, 0x0($a3)
        ctx->r8 = MEM_W(ctx->r7, 0X0);
            goto L_800E6EF0;
    }
    goto skip_6;
    // 0x800E6EE0: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    skip_6:
    // 0x800E6EE4: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x800E6EE8: sw          $t8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r24;
L_800E6EEC:
    // 0x800E6EEC: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
L_800E6EF0:
    // 0x800E6EF0: lw          $t9, 0x20($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X20);
    // 0x800E6EF4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800E6EF8: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x800E6EFC: addu        $t1, $t9, $t6
    ctx->r9 = ADD32(ctx->r25, ctx->r14);
    // 0x800E6F00: sw          $zero, 0x8E8($t1)
    MEM_W(0X8E8, ctx->r9) = 0;
    // 0x800E6F04: sw          $zero, 0x8($a2)
    MEM_W(0X8, ctx->r6) = 0;
    // 0x800E6F08: sw          $zero, 0xC($a2)
    MEM_W(0XC, ctx->r6) = 0;
    // 0x800E6F0C: jal         0x8000948C
    // 0x800E6F10: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    gcEjectDObj(rdram, ctx);
        goto after_1;
    // 0x800E6F10: sw          $zero, 0x10($a2)
    MEM_W(0X10, ctx->r6) = 0;
    after_1:
    // 0x800E6F14: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E6F18: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E6F1C: jr          $ra
    // 0x800E6F20: nop

    return;
    // 0x800E6F20: nop

;}
RECOMP_FUNC void ftDonkeyThrowFKneeBendProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D850: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014D854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D858: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014D85C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8014D860: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014D864: lwc1        $f4, 0xB1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x8014D868: lw          $t6, 0xB20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB20);
    // 0x8014D86C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8014D870: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014D874: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x8014D878: bne         $t6, $at, L_8014D8B4
    if (ctx->r14 != ctx->r1) {
        // 0x8014D87C: swc1        $f8, 0xB1C($v0)
        MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
            goto L_8014D8B4;
    }
    // 0x8014D87C: swc1        $f8, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->f8.u32l;
    // 0x8014D880: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8014D884: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8014D888: lwc1        $f16, 0xB1C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XB1C);
    // 0x8014D88C: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x8014D890: nop

    // 0x8014D894: bc1fl       L_8014D8B8
    if (!c1cs) {
        // 0x8014D898: lwc1        $f18, 0xB1C($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
            goto L_8014D8B8;
    }
    goto skip_0;
    // 0x8014D898: lwc1        $f18, 0xB1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
    skip_0:
    // 0x8014D89C: lhu         $t7, 0x1C0($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1C0);
    // 0x8014D8A0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8014D8A4: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8014D8A8: beql        $t8, $zero, L_8014D8B8
    if (ctx->r24 == 0) {
        // 0x8014D8AC: lwc1        $f18, 0xB1C($v0)
        ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
            goto L_8014D8B8;
    }
    goto skip_1;
    // 0x8014D8AC: lwc1        $f18, 0xB1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
    skip_1:
    // 0x8014D8B0: sw          $t9, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = ctx->r25;
L_8014D8B4:
    // 0x8014D8B4: lwc1        $f18, 0xB1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XB1C);
L_8014D8B8:
    // 0x8014D8B8: lwc1        $f4, 0x34($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X34);
    // 0x8014D8BC: c.le.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl <= ctx->f18.fl;
    // 0x8014D8C0: nop

    // 0x8014D8C4: bc1fl       L_8014D8D8
    if (!c1cs) {
        // 0x8014D8C8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014D8D8;
    }
    goto skip_2;
    // 0x8014D8C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x8014D8CC: jal         0x8014DAF8
    // 0x8014D8D0: nop

    ftDonkeyThrowFJumpSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014D8D0: nop

    after_0:
    // 0x8014D8D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014D8D8:
    // 0x8014D8D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014D8DC: jr          $ra
    // 0x8014D8E0: nop

    return;
    // 0x8014D8E0: nop

;}
RECOMP_FUNC void mpCommonRunDefaultCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEEF4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800DEEF8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800DEEFC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800DEF00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800DEF04: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800DEF08: jal         0x800DB838
    // 0x800DEF0C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    mpProcessCheckTestLWallCollisionAdjNew(rdram, ctx);
        goto after_0;
    // 0x800DEF0C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x800DEF10: beq         $v0, $zero, L_800DEF20
    if (ctx->r2 == 0) {
        // 0x800DEF14: nop
    
            goto L_800DEF20;
    }
    // 0x800DEF14: nop

    // 0x800DEF18: jal         0x800DBF58
    // 0x800DEF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunLWallCollisionAdjNew(rdram, ctx);
        goto after_1;
    // 0x800DEF1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_800DEF20:
    // 0x800DEF20: jal         0x800DC3C8
    // 0x800DEF24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestRWallCollisionAdjNew(rdram, ctx);
        goto after_2;
    // 0x800DEF24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800DEF28: beq         $v0, $zero, L_800DEF38
    if (ctx->r2 == 0) {
        // 0x800DEF2C: nop
    
            goto L_800DEF38;
    }
    // 0x800DEF2C: nop

    // 0x800DEF30: jal         0x800DCAE8
    // 0x800DEF34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunRWallCollisionAdjNew(rdram, ctx);
        goto after_3;
    // 0x800DEF34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_800DEF38:
    // 0x800DEF38: jal         0x800DCF58
    // 0x800DEF3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestCeilCollisionAdjNew(rdram, ctx);
        goto after_4;
    // 0x800DEF3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x800DEF40: beq         $v0, $zero, L_800DEF68
    if (ctx->r2 == 0) {
        // 0x800DEF44: nop
    
            goto L_800DEF68;
    }
    // 0x800DEF44: nop

    // 0x800DEF48: jal         0x800DD160
    // 0x800DEF4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunCeilCollisionAdjNew(rdram, ctx);
        goto after_5;
    // 0x800DEF4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x800DEF50: lhu         $t6, 0x5A($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DEF54: andi        $t7, $t6, 0x400
    ctx->r15 = ctx->r14 & 0X400;
    // 0x800DEF58: beq         $t7, $zero, L_800DEF68
    if (ctx->r15 == 0) {
        // 0x800DEF5C: nop
    
            goto L_800DEF68;
    }
    // 0x800DEF5C: nop

    // 0x800DEF60: jal         0x800D99B8
    // 0x800DEF64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunCeilEdgeAdjust(rdram, ctx);
        goto after_6;
    // 0x800DEF64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_800DEF68:
    // 0x800DEF68: jal         0x800DD578
    // 0x800DEF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorCollisionAdjNewNULL(rdram, ctx);
        goto after_7;
    // 0x800DEF6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800DEF70: beq         $v0, $zero, L_800DEFA0
    if (ctx->r2 == 0) {
        // 0x800DEF74: nop
    
            goto L_800DEFA0;
    }
    // 0x800DEF74: nop

    // 0x800DEF78: jal         0x800DD6A8
    // 0x800DEF7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetCollideFloor(rdram, ctx);
        goto after_8;
    // 0x800DEF7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x800DEF80: lhu         $t8, 0x5A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X5A);
    // 0x800DEF84: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x800DEF88: beql        $t9, $zero, L_800DEFAC
    if (ctx->r25 == 0) {
        // 0x800DEF8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800DEFAC;
    }
    goto skip_0;
    // 0x800DEF8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x800DEF90: jal         0x800D9F84
    // 0x800DEF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_9;
    // 0x800DEF94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800DEF98: b           L_800DEFAC
    // 0x800DEF9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800DEFAC;
    // 0x800DEF9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DEFA0:
    // 0x800DEFA0: jal         0x800D9FCC
    // 0x800DEFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetCollProjectFloorID(rdram, ctx);
        goto after_10;
    // 0x800DEFA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x800DEFA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800DEFAC:
    // 0x800DEFAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800DEFB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800DEFB4: jr          $ra
    // 0x800DEFB8: nop

    return;
    // 0x800DEFB8: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateCPOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D478: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D47C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D480: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D484: addiu       $a0, $a0, 0xB6C
    ctx->r4 = ADD32(ctx->r4, 0XB6C);
    // 0x8018D488: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D48C: jal         0x8018D40C
    // 0x8018D490: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    sc1PTrainingModeCheckUpdateOptionID(rdram, ctx);
        goto after_0;
    // 0x8018D490: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_0:
    // 0x8018D494: beql        $v0, $zero, L_8018D4C0
    if (ctx->r2 == 0) {
        // 0x8018D498: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018D4C0;
    }
    goto skip_0;
    // 0x8018D498: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8018D49C: jal         0x801901F4
    // 0x8018D4A0: nop

    sc1PTrainingModeUpdateDummyBehavior(rdram, ctx);
        goto after_1;
    // 0x8018D4A0: nop

    after_1:
    // 0x8018D4A4: jal         0x8018E810
    // 0x8018D4A8: nop

    sc1PTrainingModeUpdateCPDisplaySprite(rdram, ctx);
        goto after_2;
    // 0x8018D4A8: nop

    after_2:
    // 0x8018D4AC: jal         0x8018EEE8
    // 0x8018D4B0: nop

    sc1PTrainingModeUpdateCPOptionSprite(rdram, ctx);
        goto after_3;
    // 0x8018D4B0: nop

    after_3:
    // 0x8018D4B4: jal         0x8018D3DC
    // 0x8018D4B8: nop

    sc1PTrainingModeUpdateScroll(rdram, ctx);
        goto after_4;
    // 0x8018D4B8: nop

    after_4:
    // 0x8018D4BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018D4C0:
    // 0x8018D4C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D4C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D4C8: jr          $ra
    // 0x8018D4CC: nop

    return;
    // 0x8018D4CC: nop

;}
RECOMP_FUNC void func_ovl8_8037203C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037203C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80372040: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80372044: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80372048: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037204C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80372050: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80372054: bne         $a0, $zero, L_8037206C
    if (ctx->r4 != 0) {
        // 0x80372058: sw          $a3, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r7;
            goto L_8037206C;
    }
    // 0x80372058: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8037205C: jal         0x803717A0
    // 0x80372060: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80372060: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    after_0:
    // 0x80372064: beq         $v0, $zero, L_803720C0
    if (ctx->r2 == 0) {
        // 0x80372068: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803720C0;
    }
    // 0x80372068: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037206C:
    // 0x8037206C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80372070: addiu       $a0, $s0, 0x14
    ctx->r4 = ADD32(ctx->r16, 0X14);
    // 0x80372074: bnel        $t6, $zero, L_80372088
    if (ctx->r14 != 0) {
        // 0x80372078: lw          $t7, 0x24($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X24);
            goto L_80372088;
    }
    goto skip_0;
    // 0x80372078: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8037207C: jal         0x803717E0
    // 0x80372080: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80372080: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80372084: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
L_80372088:
    // 0x80372088: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8037208C: addiu       $t8, $t8, -0x7520
    ctx->r24 = ADD32(ctx->r24, -0X7520);
    // 0x80372090: sw          $t8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r24;
    // 0x80372094: sw          $t7, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r15;
    // 0x80372098: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8037209C: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803720A0: addiu       $t9, $t9, -0x74C0
    ctx->r25 = ADD32(ctx->r25, -0X74C0);
    // 0x803720A4: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x803720A8: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x803720AC: jal         0x80371ECC
    // 0x803720B0: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    func_ovl8_80371ECC(rdram, ctx);
        goto after_2;
    // 0x803720B0: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    after_2:
    // 0x803720B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803720B8: jal         0x80372420
    // 0x803720BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_80372420(rdram, ctx);
        goto after_3;
    // 0x803720BC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_3:
L_803720C0:
    // 0x803720C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803720C4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x803720C8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803720CC: jr          $ra
    // 0x803720D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x803720D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftKirbySpecialNWaitSetStatusFromEat(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163274: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80163278: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016327C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80163280: addiu       $t7, $zero, 0xA0
    ctx->r15 = ADD32(0, 0XA0);
    // 0x80163284: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80163288: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016328C: addiu       $a1, $zero, 0x113
    ctx->r5 = ADD32(0, 0X113);
    // 0x80163290: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80163294: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80163298: jal         0x800E6F24
    // 0x8016329C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8016329C: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801632A0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801632A4: jal         0x800E8098
    // 0x801632A8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_1;
    // 0x801632A8: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_1:
    // 0x801632AC: jal         0x800E0830
    // 0x801632B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801632B0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801632B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801632B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801632BC: jr          $ra
    // 0x801632C0: nop

    return;
    // 0x801632C0: nop

;}
RECOMP_FUNC void func_ovl8_80372B98(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372B98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80372B9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80372BA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80372BA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80372BA8: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
    // 0x80372BAC: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x80372BB0: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80372BB4: lw          $t9, 0x84($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84);
    // 0x80372BB8: lh          $t7, 0x80($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X80);
    // 0x80372BBC: jalr        $t9
    // 0x80372BC0: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80372BC0: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_0:
    // 0x80372BC4: bne         $v0, $zero, L_80372BD4
    if (ctx->r2 != 0) {
        // 0x80372BC8: lw          $t8, 0x18($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X18);
            goto L_80372BD4;
    }
    // 0x80372BC8: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80372BCC: b           L_80372BF0
    // 0x80372BD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80372BF0;
    // 0x80372BD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80372BD4:
    // 0x80372BD4: lw          $v1, 0x20($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X20);
    // 0x80372BD8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80372BDC: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80372BE0: lw          $t9, 0x94($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X94);
    // 0x80372BE4: lh          $t0, 0x90($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X90);
    // 0x80372BE8: jalr        $t9
    // 0x80372BEC: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80372BEC: addu        $a0, $t0, $v1
    ctx->r4 = ADD32(ctx->r8, ctx->r3);
    after_1:
L_80372BF0:
    // 0x80372BF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80372BF4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80372BF8: jr          $ra
    // 0x80372BFC: nop

    return;
    // 0x80372BFC: nop

;}
RECOMP_FUNC void mnVSOptionsSetOptionSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F74: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131F78: addiu       $t6, $t6, 0x4758
    ctx->r14 = ADD32(ctx->r14, 0X4758);
    // 0x80131F7C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131F80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131F84: addiu       $a2, $sp, 0x10
    ctx->r6 = ADD32(ctx->r29, 0X10);
    // 0x80131F88: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80131F8C: lhu         $t8, 0x4($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X4);
    // 0x80131F90: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131F94: addiu       $t9, $t9, 0x4760
    ctx->r25 = ADD32(ctx->r25, 0X4760);
    // 0x80131F98: sh          $t8, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r24;
    // 0x80131F9C: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x80131FA0: addiu       $a3, $sp, 0x8
    ctx->r7 = ADD32(ctx->r29, 0X8);
    // 0x80131FA4: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80131FA8: lhu         $t1, 0x4($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X4);
    // 0x80131FAC: sh          $t1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r9;
    // 0x80131FB0: beq         $a1, $zero, L_80131FC0
    if (ctx->r5 == 0) {
        // 0x80131FB4: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_80131FC0;
    }
    // 0x80131FB4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131FB8: b           L_80131FC4
    // 0x80131FBC: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
        goto L_80131FC4;
    // 0x80131FBC: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_80131FC0:
    // 0x80131FC0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80131FC4:
    // 0x80131FC4: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80131FC8: sb          $t2, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r10;
    // 0x80131FCC: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x80131FD0: sb          $t3, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r11;
    // 0x80131FD4: lbu         $t4, 0x2($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2);
    // 0x80131FD8: sb          $t4, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r12;
    // 0x80131FDC: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
    // 0x80131FE0: sb          $t5, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r13;
    // 0x80131FE4: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x80131FE8: sb          $t6, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r14;
    // 0x80131FEC: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x80131FF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131FF4: jr          $ra
    // 0x80131FF8: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
    return;
    // 0x80131FF8: sb          $t7, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void func_ovl8_80375BA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80375BA0: lhu         $t6, 0x14($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X14);
    // 0x80375BA4: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x80375BA8: lhu         $t7, 0x16($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X16);
    // 0x80375BAC: jr          $ra
    // 0x80375BB0: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
    return;
    // 0x80375BB0: sh          $t7, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r15;
;}
RECOMP_FUNC void ftLinkSpecialHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164284: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80164288: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016428C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80164290: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80164294: addiu       $t6, $t6, 0x426C
    ctx->r14 = ADD32(ctx->r14, 0X426C);
    // 0x80164298: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x8016429C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801642A0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801642A4: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x801642A8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801642AC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801642B0: jal         0x800E6F24
    // 0x801642B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801642B4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801642B8: jal         0x800E0830
    // 0x801642BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801642BC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801642C0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801642C4: lui         $t7, 0x8016
    ctx->r15 = S32(0X8016 << 16);
    // 0x801642C8: lui         $t8, 0x8016
    ctx->r24 = S32(0X8016 << 16);
    // 0x801642CC: addiu       $t7, $t7, 0x3EFC
    ctx->r15 = ADD32(ctx->r15, 0X3EFC);
    // 0x801642D0: addiu       $t8, $t8, 0x3D00
    ctx->r24 = ADD32(ctx->r24, 0X3D00);
    // 0x801642D4: sw          $t7, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r15;
    // 0x801642D8: sw          $t8, 0x9FC($v0)
    MEM_W(0X9FC, ctx->r2) = ctx->r24;
    // 0x801642DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801642E0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801642E4: jr          $ra
    // 0x801642E8: nop

    return;
    // 0x801642E8: nop

;}
RECOMP_FUNC void itFushigibanaWeaponRazorProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184874: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80184878: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018487C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80184880: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x80184884: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x80184888: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x8018488C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    // 0x80184890: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80184894: nop

    // 0x80184898: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018489C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x801848A0: jal         0x800FE6E4
    // 0x801848A4: nop

    efManagerDamageSlashMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801848A4: nop

    after_0:
    // 0x801848A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801848AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801848B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801848B4: jr          $ra
    // 0x801848B8: nop

    return;
    // 0x801848B8: nop

;}
RECOMP_FUNC void mnMapsMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FA4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131FA8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131FAC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FB4: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131FB8: jal         0x80009968
    // 0x80131FBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131FBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FC0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131FC4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131FC8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131FCC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131FD0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131FD4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131FD8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131FDC: jal         0x80009DF4
    // 0x80131FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131FE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131FE4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131FE8: lw          $t7, 0x4E14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4E14);
    // 0x80131FEC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131FF0: addiu       $t8, $t8, 0x440
    ctx->r24 = ADD32(ctx->r24, 0X440);
    // 0x80131FF4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131FF8: jal         0x800CCFDC
    // 0x80131FFC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131FFC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132000: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132004: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132008: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8013200C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80132010: addiu       $t1, $zero, 0x12C
    ctx->r9 = ADD32(0, 0X12C);
    // 0x80132014: addiu       $t2, $zero, 0xDC
    ctx->r10 = ADD32(0, 0XDC);
    // 0x80132018: sb          $zero, 0x65($v0)
    MEM_B(0X65, ctx->r2) = 0;
    // 0x8013201C: sb          $zero, 0x64($v0)
    MEM_B(0X64, ctx->r2) = 0;
    // 0x80132020: sb          $t9, 0x67($v0)
    MEM_B(0X67, ctx->r2) = ctx->r25;
    // 0x80132024: sb          $t0, 0x66($v0)
    MEM_B(0X66, ctx->r2) = ctx->r8;
    // 0x80132028: sh          $t1, 0x68($v0)
    MEM_H(0X68, ctx->r2) = ctx->r9;
    // 0x8013202C: sh          $t2, 0x6A($v0)
    MEM_H(0X6A, ctx->r2) = ctx->r10;
    // 0x80132030: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132034: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80132038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013203C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132040: jr          $ra
    // 0x80132044: nop

    return;
    // 0x80132044: nop

;}
RECOMP_FUNC void func_ovl8_80380704(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80380704: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80380708: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8038070C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80380710: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80380714: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x80380718: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8038071C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80380720: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80380724: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80380728: jal         0x8037726C
    // 0x8038072C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_ovl8_8037726C(rdram, ctx);
        goto after_0;
    // 0x8038072C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x80380730: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x80380734: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80380738: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x8038073C: lw          $t9, 0x84($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X84);
    // 0x80380740: lh          $t6, 0x80($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X80);
    // 0x80380744: jalr        $t9
    // 0x80380748: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80380748: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    after_1:
    // 0x8038074C: beq         $v0, $zero, L_803807D0
    if (ctx->r2 == 0) {
        // 0x80380750: addiu       $s4, $zero, 0xC
        ctx->r20 = ADD32(0, 0XC);
            goto L_803807D0;
    }
    // 0x80380750: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x80380754: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x80380758: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8038075C: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x80380760: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x80380764: lh          $t7, 0x40($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X40);
    // 0x80380768: jalr        $t9
    // 0x8038076C: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x8038076C: addu        $a0, $t7, $v0
    ctx->r4 = ADD32(ctx->r15, ctx->r2);
    after_2:
    // 0x80380770: lh          $t8, 0x3E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X3E);
    // 0x80380774: addiu       $s4, $zero, 0xC
    ctx->r20 = ADD32(0, 0XC);
    // 0x80380778: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x8038077C: div         $zero, $t8, $s4
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r20)));
    // 0x80380780: mflo        $t0
    ctx->r8 = lo;
    // 0x80380784: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80380788: sw          $t1, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->r9;
    // 0x8038078C: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x80380790: bne         $s4, $zero, L_8038079C
    if (ctx->r20 != 0) {
        // 0x80380794: nop
    
            goto L_8038079C;
    }
    // 0x80380794: nop

    // 0x80380798: break       7
    do_break(2151155608);
L_8038079C:
    // 0x8038079C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x803807A0: bne         $s4, $at, L_803807B4
    if (ctx->r20 != ctx->r1) {
        // 0x803807A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_803807B4;
    }
    // 0x803807A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x803807A8: bne         $t8, $at, L_803807B4
    if (ctx->r24 != ctx->r1) {
        // 0x803807AC: nop
    
            goto L_803807B4;
    }
    // 0x803807AC: nop

    // 0x803807B0: break       6
    do_break(2151155632);
L_803807B4:
    // 0x803807B4: lw          $t9, 0x11C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X11C);
    // 0x803807B8: lh          $t2, 0x118($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X118);
    // 0x803807BC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x803807C0: jalr        $t9
    // 0x803807C4: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x803807C4: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    after_3:
    // 0x803807C8: b           L_803807D8
    // 0x803807CC: lw          $s3, 0xAC($s1)
    ctx->r19 = MEM_W(ctx->r17, 0XAC);
        goto L_803807D8;
    // 0x803807CC: lw          $s3, 0xAC($s1)
    ctx->r19 = MEM_W(ctx->r17, 0XAC);
L_803807D0:
    // 0x803807D0: sw          $zero, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = 0;
    // 0x803807D4: lw          $s3, 0xAC($s1)
    ctx->r19 = MEM_W(ctx->r17, 0XAC);
L_803807D8:
    // 0x803807D8: beq         $s1, $zero, L_803807E4
    if (ctx->r17 == 0) {
        // 0x803807DC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_803807E4;
    }
    // 0x803807DC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x803807E0: lw          $s0, 0x20($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X20);
L_803807E4:
    // 0x803807E4: jal         0x80377244
    // 0x803807E8: nop

    func_ovl8_80377244(rdram, ctx);
        goto after_4;
    // 0x803807E8: nop

    after_4:
    // 0x803807EC: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x803807F0: and         $t4, $v0, $t3
    ctx->r12 = ctx->r2 & ctx->r11;
    // 0x803807F4: beql        $t4, $zero, L_80380900
    if (ctx->r12 == 0) {
        // 0x803807F8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80380900;
    }
    goto skip_0;
    // 0x803807F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_803807FC:
    // 0x803807FC: jal         0x8037726C
    // 0x80380800: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_ovl8_8037726C(rdram, ctx);
        goto after_5;
    // 0x80380800: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x80380804: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x80380808: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8038080C: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x80380810: lw          $t9, 0x84($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X84);
    // 0x80380814: lh          $t5, 0x80($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X80);
    // 0x80380818: jalr        $t9
    // 0x8038081C: addu        $a0, $t5, $v0
    ctx->r4 = ADD32(ctx->r13, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_6;
    // 0x8038081C: addu        $a0, $t5, $v0
    ctx->r4 = ADD32(ctx->r13, ctx->r2);
    after_6:
    // 0x80380820: beql        $v0, $zero, L_803808A4
    if (ctx->r2 == 0) {
        // 0x80380824: sw          $zero, 0xAC($s1)
        MEM_W(0XAC, ctx->r17) = 0;
            goto L_803808A4;
    }
    goto skip_1;
    // 0x80380824: sw          $zero, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = 0;
    skip_1:
    // 0x80380828: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x8038082C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80380830: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x80380834: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    // 0x80380838: lh          $t6, 0x40($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X40);
    // 0x8038083C: jalr        $t9
    // 0x80380840: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_7;
    // 0x80380840: addu        $a0, $t6, $v0
    ctx->r4 = ADD32(ctx->r14, ctx->r2);
    after_7:
    // 0x80380844: lh          $t7, 0x3E($sp)
    ctx->r15 = MEM_H(ctx->r29, 0X3E);
    // 0x80380848: div         $zero, $t7, $s4
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r20)));
    // 0x8038084C: mflo        $t8
    ctx->r24 = lo;
    // 0x80380850: addiu       $t0, $t8, 0x1
    ctx->r8 = ADD32(ctx->r24, 0X1);
    // 0x80380854: bne         $s4, $zero, L_80380860
    if (ctx->r20 != 0) {
        // 0x80380858: nop
    
            goto L_80380860;
    }
    // 0x80380858: nop

    // 0x8038085C: break       7
    do_break(2151155804);
L_80380860:
    // 0x80380860: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80380864: bne         $s4, $at, L_80380878
    if (ctx->r20 != ctx->r1) {
        // 0x80380868: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80380878;
    }
    // 0x80380868: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8038086C: bne         $t7, $at, L_80380878
    if (ctx->r15 != ctx->r1) {
        // 0x80380870: nop
    
            goto L_80380878;
    }
    // 0x80380870: nop

    // 0x80380874: break       6
    do_break(2151155828);
L_80380878:
    // 0x80380878: sw          $t0, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = ctx->r8;
    // 0x8038087C: blez        $t0, L_80380894
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80380880: or          $v0, $t0, $zero
        ctx->r2 = ctx->r8 | 0;
            goto L_80380894;
    }
    // 0x80380880: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80380884: lw          $t1, 0xB0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0XB0);
    // 0x80380888: slt         $at, $t1, $t0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8038088C: beq         $at, $zero, L_803808A8
    if (ctx->r1 == 0) {
        // 0x80380890: nop
    
            goto L_803808A8;
    }
    // 0x80380890: nop

L_80380894:
    // 0x80380894: sw          $zero, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = 0;
    // 0x80380898: b           L_803808A8
    // 0x8038089C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_803808A8;
    // 0x8038089C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x803808A0: sw          $zero, 0xAC($s1)
    MEM_W(0XAC, ctx->r17) = 0;
L_803808A4:
    // 0x803808A4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_803808A8:
    // 0x803808A8: beq         $s3, $v0, L_803808D0
    if (ctx->r19 == ctx->r2) {
        // 0x803808AC: nop
    
            goto L_803808D0;
    }
    // 0x803808AC: nop

    // 0x803808B0: lw          $v0, 0x20($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X20);
    // 0x803808B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x803808B8: lw          $s0, 0x58($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X58);
    // 0x803808BC: lw          $t9, 0x11C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X11C);
    // 0x803808C0: lh          $t2, 0x118($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X118);
    // 0x803808C4: jalr        $t9
    // 0x803808C8: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_8;
    // 0x803808C8: addu        $a0, $t2, $v0
    ctx->r4 = ADD32(ctx->r10, ctx->r2);
    after_8:
    // 0x803808CC: lw          $s3, 0xAC($s1)
    ctx->r19 = MEM_W(ctx->r17, 0XAC);
L_803808D0:
    // 0x803808D0: jal         0x8000B1E8
    // 0x803808D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_9;
    // 0x803808D4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x803808D8: beq         $s1, $zero, L_803808E4
    if (ctx->r17 == 0) {
        // 0x803808DC: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_803808E4;
    }
    // 0x803808DC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x803808E0: lw          $s0, 0x20($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X20);
L_803808E4:
    // 0x803808E4: jal         0x80377244
    // 0x803808E8: nop

    func_ovl8_80377244(rdram, ctx);
        goto after_10;
    // 0x803808E8: nop

    after_10:
    // 0x803808EC: lw          $t3, 0x30($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X30);
    // 0x803808F0: and         $t4, $v0, $t3
    ctx->r12 = ctx->r2 & ctx->r11;
    // 0x803808F4: bne         $t4, $zero, L_803807FC
    if (ctx->r12 != 0) {
        // 0x803808F8: nop
    
            goto L_803807FC;
    }
    // 0x803808F8: nop

    // 0x803808FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80380900:
    // 0x80380900: lw          $v0, 0xAC($s1)
    ctx->r2 = MEM_W(ctx->r17, 0XAC);
    // 0x80380904: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80380908: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8038090C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80380910: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80380914: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80380918: jr          $ra
    // 0x8038091C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8038091C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gcRemoveSObjAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B760: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B764: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000B768: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000B76C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8000B770: bne         $a0, $zero, L_8000B780
    if (ctx->r4 != 0) {
        // 0x8000B774: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8000B780;
    }
    // 0x8000B774: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000B778: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8000B77C: lw          $s1, 0x6A54($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X6A54);
L_8000B780:
    // 0x8000B780: lw          $s0, 0x74($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X74);
    // 0x8000B784: beql        $s0, $zero, L_8000B7A4
    if (ctx->r16 == 0) {
        // 0x8000B788: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8000B7A4;
    }
    goto skip_0;
    // 0x8000B788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8000B78C:
    // 0x8000B78C: jal         0x800096EC
    // 0x8000B790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEjectSObj(rdram, ctx);
        goto after_0;
    // 0x8000B790: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8000B794: lw          $s0, 0x74($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X74);
    // 0x8000B798: bne         $s0, $zero, L_8000B78C
    if (ctx->r16 != 0) {
        // 0x8000B79C: nop
    
            goto L_8000B78C;
    }
    // 0x8000B79C: nop

    // 0x8000B7A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8000B7A4:
    // 0x8000B7A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000B7A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000B7AC: jr          $ra
    // 0x8000B7B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000B7B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itMainGetWeightedItemKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173090: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173094: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173098: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8017309C: jal         0x80018994
    // 0x801730A0: lhu         $a0, 0x10($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X10);
    syUtilsRandIntRange(rdram, ctx);
        goto after_0;
    // 0x801730A0: lhu         $a0, 0x10($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X10);
    after_0:
    // 0x801730A4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801730A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801730AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801730B0: jal         0x8017301C
    // 0x801730B4: lbu         $a3, 0x8($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X8);
    itMainSearchRandomWeight(rdram, ctx);
        goto after_1;
    // 0x801730B4: lbu         $a3, 0x8($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X8);
    after_1:
    // 0x801730B8: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x801730BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801730C0: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x801730C4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x801730C8: lbu         $v0, 0x0($t9)
    ctx->r2 = MEM_BU(ctx->r25, 0X0);
    // 0x801730CC: jr          $ra
    // 0x801730D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x801730D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_ovl8_80384968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384968: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8038496C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80384970: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80384974: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80384978: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8038497C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80384980: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80384984: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80384988: beql        $t6, $zero, L_80384AD0
    if (ctx->r14 == 0) {
        // 0x8038498C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80384AD0;
    }
    goto skip_0;
    // 0x8038498C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80384990: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80384994: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80384998: lw          $t9, 0xBC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XBC);
    // 0x8038499C: lh          $t7, 0xB8($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XB8);
    // 0x803849A0: jalr        $t9
    // 0x803849A4: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803849A4: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_0:
    // 0x803849A8: beq         $v0, $zero, L_80384ACC
    if (ctx->r2 == 0) {
        // 0x803849AC: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80384ACC;
    }
    // 0x803849AC: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x803849B0: lw          $v1, 0x38($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X38);
    // 0x803849B4: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x803849B8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x803849BC: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x803849C0: lw          $t9, 0xAC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XAC);
    // 0x803849C4: lh          $t8, 0xA8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XA8);
    // 0x803849C8: jalr        $t9
    // 0x803849CC: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x803849CC: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    after_1:
    // 0x803849D0: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x803849D4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x803849D8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x803849DC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x803849E0: jal         0x80377AEC
    // 0x803849E4: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    func_ovl8_80377AEC(rdram, ctx);
        goto after_2;
    // 0x803849E4: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    after_2:
    // 0x803849E8: lh          $t0, 0x46($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X46);
    // 0x803849EC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x803849F0: addiu       $s2, $sp, 0x3C
    ctx->r18 = ADD32(ctx->r29, 0X3C);
    // 0x803849F4: blezl       $t0, L_80384AD0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x803849F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80384AD0;
    }
    goto skip_1;
    // 0x803849F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x803849FC: lh          $t2, 0x3C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X3C);
L_80384A00:
    // 0x80384A00: lh          $t1, 0x3E($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X3E);
    // 0x80384A04: lh          $t4, 0x34($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X34);
    // 0x80384A08: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80384A0C: slt         $at, $t1, $t3
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80384A10: bnel        $at, $zero, L_80384AD0
    if (ctx->r1 != 0) {
        // 0x80384A14: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80384AD0;
    }
    goto skip_2;
    // 0x80384A14: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x80384A18: sh          $t4, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r12;
    // 0x80384A1C: lh          $t6, 0x44($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X44);
    // 0x80384A20: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80384A24: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80384A28: multu       $s1, $t6
    result = U64(U32(ctx->r17)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80384A2C: mflo        $t7
    ctx->r15 = lo;
    // 0x80384A30: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x80384A34: beq         $s0, $zero, L_80384A40
    if (ctx->r16 == 0) {
        // 0x80384A38: sh          $t8, 0x3E($sp)
        MEM_H(0X3E, ctx->r29) = ctx->r24;
            goto L_80384A40;
    }
    // 0x80384A38: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    // 0x80384A3C: lw          $v0, 0x38($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X38);
L_80384A40:
    // 0x80384A40: lhu         $t9, 0x6($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X6);
    // 0x80384A44: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80384A48: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80384A4C: sh          $t9, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r25;
    // 0x80384A50: lh          $t0, 0x44($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X44);
    // 0x80384A54: sh          $t0, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r8;
    // 0x80384A58: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80384A5C: lh          $t1, 0x3C($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X3C);
    // 0x80384A60: lw          $t9, 0x10C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10C);
    // 0x80384A64: lh          $t2, 0x108($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X108);
    // 0x80384A68: addu        $a3, $s1, $t1
    ctx->r7 = ADD32(ctx->r17, ctx->r9);
    // 0x80384A6C: jalr        $t9
    // 0x80384A70: addu        $a0, $t2, $s0
    ctx->r4 = ADD32(ctx->r10, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80384A70: addu        $a0, $t2, $s0
    ctx->r4 = ADD32(ctx->r10, ctx->r16);
    after_3:
    // 0x80384A74: lh          $t3, 0x3C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X3C);
    // 0x80384A78: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80384A7C: addu        $a3, $s1, $t3
    ctx->r7 = ADD32(ctx->r17, ctx->r11);
    // 0x80384A80: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80384A84: nop

    // 0x80384A88: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80384A8C: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x80384A90: nop

    // 0x80384A94: bc1fl       L_80384ABC
    if (!c1cs) {
        // 0x80384A98: lh          $t6, 0x46($s0)
        ctx->r14 = MEM_H(ctx->r16, 0X46);
            goto L_80384ABC;
    }
    goto skip_3;
    // 0x80384A98: lh          $t6, 0x46($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X46);
    skip_3:
    // 0x80384A9C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80384AA0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80384AA4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x80384AA8: lw          $t9, 0x114($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X114);
    // 0x80384AAC: lh          $t4, 0x110($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X110);
    // 0x80384AB0: jalr        $t9
    // 0x80384AB4: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80384AB4: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    after_4:
    // 0x80384AB8: lh          $t6, 0x46($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X46);
L_80384ABC:
    // 0x80384ABC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80384AC0: slt         $at, $s1, $t6
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80384AC4: bnel        $at, $zero, L_80384A00
    if (ctx->r1 != 0) {
        // 0x80384AC8: lh          $t2, 0x3C($s0)
        ctx->r10 = MEM_H(ctx->r16, 0X3C);
            goto L_80384A00;
    }
    goto skip_4;
    // 0x80384AC8: lh          $t2, 0x3C($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X3C);
    skip_4:
L_80384ACC:
    // 0x80384ACC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80384AD0:
    // 0x80384AD0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80384AD4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80384AD8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80384ADC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80384AE0: jr          $ra
    // 0x80384AE4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80384AE4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mvOpeningRoomMakeBossShadow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801329F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801329F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801329F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801329FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132A00: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132A04: jal         0x80009968
    // 0x80132A08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132A08: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132A0C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132A10: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80132A14: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80132A18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A1C: addiu       $t7, $t7, -0x870
    ctx->r15 = ADD32(ctx->r15, -0X870);
    // 0x80132A20: sw          $v0, 0x4D30($at)
    MEM_W(0X4D30, ctx->r1) = ctx->r2;
    // 0x80132A24: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132A28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132A2C: jal         0x800092D0
    // 0x80132A30: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132A30: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80132A34: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80132A38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132A3C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80132A40: jal         0x80008CC0
    // 0x80132A44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80132A44: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80132A48: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132A4C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80132A50: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80132A54: addiu       $a1, $a1, 0x3E8C
    ctx->r5 = ADD32(ctx->r5, 0X3E8C);
    // 0x80132A58: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132A5C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80132A60: jal         0x80009DF4
    // 0x80132A64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80132A64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80132A68: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132A6C: lw          $t9, 0x50B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B0);
    // 0x80132A70: lui         $t0, 0x2
    ctx->r8 = S32(0X2 << 16);
    // 0x80132A74: addiu       $t0, $t0, -0x6DC
    ctx->r8 = ADD32(ctx->r8, -0X6DC);
    // 0x80132A78: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80132A7C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80132A80: jal         0x8000BD1C
    // 0x80132A84: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_4;
    // 0x80132A84: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x80132A88: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132A8C: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80132A90: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132A94: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132A98: jal         0x80008188
    // 0x80132A9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80132A9C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80132AA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132AA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132AA8: jr          $ra
    // 0x80132AAC: nop

    return;
    // 0x80132AAC: nop

;}
RECOMP_FUNC void sc1PBonusStageStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EACC: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018EAD0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018EAD4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018EAD8: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018EADC: addiu       $a0, $a0, -0xF80
    ctx->r4 = ADD32(ctx->r4, -0XF80);
    // 0x8018EAE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018EAE4: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018EAE8: jal         0x80007024
    // 0x8018EAEC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018EAEC: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018EAF0: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018EAF4: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018EAF8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018EAFC: addiu       $t9, $t9, -0x8F0
    ctx->r25 = ADD32(ctx->r25, -0X8F0);
    // 0x8018EB00: addiu       $t8, $t8, 0x2A00
    ctx->r24 = ADD32(ctx->r24, 0X2A00);
    // 0x8018EB04: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018EB08: addiu       $a0, $a0, -0xF64
    ctx->r4 = ADD32(ctx->r4, -0XF64);
    // 0x8018EB0C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018EB10: addiu       $t1, $t1, -0x1A08
    ctx->r9 = ADD32(ctx->r9, -0X1A08);
    // 0x8018EB14: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    // 0x8018EB18: jal         0x8000683C
    // 0x8018EB1C: sw          $t1, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r9;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8018EB1C: sw          $t1, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r9;
    after_1:
    // 0x8018EB20: jal         0x80020A74
    // 0x8018EB24: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_2;
    // 0x8018EB24: nop

    after_2:
    // 0x8018EB28: jal         0x80020D58
    // 0x8018EB2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_3;
    // 0x8018EB2C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8018EB30: beql        $v0, $zero, L_8018EB4C
    if (ctx->r2 == 0) {
        // 0x8018EB34: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8018EB4C;
    }
    goto skip_0;
    // 0x8018EB34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
L_8018EB38:
    // 0x8018EB38: jal         0x80020D58
    // 0x8018EB3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_4;
    // 0x8018EB3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8018EB40: bne         $v0, $zero, L_8018EB38
    if (ctx->r2 != 0) {
        // 0x8018EB44: nop
    
            goto L_8018EB38;
    }
    // 0x8018EB44: nop

    // 0x8018EB48: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8018EB4C:
    // 0x8018EB4C: jal         0x80020B38
    // 0x8018EB50: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_5;
    // 0x8018EB50: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_5:
    // 0x8018EB54: jal         0x800266A0
    // 0x8018EB58: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_6;
    // 0x8018EB58: nop

    after_6:
    // 0x8018EB5C: jal         0x801157EC
    // 0x8018EB60: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_7;
    // 0x8018EB60: nop

    after_7:
    // 0x8018EB64: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018EB68: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x8018EB6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018EB70: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8018EB74: lbu         $t2, 0x11($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X11);
    // 0x8018EB78: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
    // 0x8018EB7C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8018EB80: beql        $t2, $at, L_8018ED5C
    if (ctx->r10 == ctx->r1) {
        // 0x8018EB84: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8018ED5C;
    }
    goto skip_1;
    // 0x8018EB84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8018EB88: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8018EB8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018EB90: slti        $at, $t3, 0x1D
    ctx->r1 = SIGNED(ctx->r11) < 0X1D ? 1 : 0;
    // 0x8018EB94: beq         $at, $zero, L_8018EBA8
    if (ctx->r1 == 0) {
        // 0x8018EB98: nop
    
            goto L_8018EBA8;
    }
    // 0x8018EB98: nop

    // 0x8018EB9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018EBA0: b           L_8018EBAC
    // 0x8018EBA4: lbu         $a0, 0x13FC($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X13FC);
        goto L_8018EBAC;
    // 0x8018EBA4: lbu         $a0, 0x13FC($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X13FC);
L_8018EBA8:
    // 0x8018EBA8: lbu         $a0, 0x1400($a0)
    ctx->r4 = MEM_BU(ctx->r4, 0X1400);
L_8018EBAC:
    // 0x8018EBAC: subu        $v0, $a2, $a0
    ctx->r2 = SUB32(ctx->r6, ctx->r4);
    // 0x8018EBB0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8018EBB4: sb          $v0, 0x4B08($at)
    MEM_B(0X4B08, ctx->r1) = ctx->r2;
    // 0x8018EBB8: lbu         $t4, 0x1($a3)
    ctx->r12 = MEM_BU(ctx->r7, 0X1);
    // 0x8018EBBC: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x8018EBC0: bnel        $t4, $at, L_8018EBF4
    if (ctx->r12 != ctx->r1) {
        // 0x8018EBC4: lbu         $a1, 0x39($a3)
        ctx->r5 = MEM_BU(ctx->r7, 0X39);
            goto L_8018EBF4;
    }
    goto skip_2;
    // 0x8018EBC4: lbu         $a1, 0x39($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X39);
    skip_2:
    // 0x8018EBC8: jal         0x8018E8D0
    // 0x8018EBCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    sc1PBonusStageSetBonusStats(rdram, ctx);
        goto after_8;
    // 0x8018EBCC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_8:
    // 0x8018EBD0: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8018EBD4: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
    // 0x8018EBD8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8018EBDC: jal         0x8018E95C
    // 0x8018EBE0: lbu         $a1, 0x14($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X14);
    sc1PBonusStageWriteBackup(rdram, ctx);
        goto after_9;
    // 0x8018EBE0: lbu         $a1, 0x14($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X14);
    after_9:
    // 0x8018EBE4: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8018EBE8: b           L_8018ED50
    // 0x8018EBEC: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
        goto L_8018ED50;
    // 0x8018EBEC: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
    // 0x8018EBF0: lbu         $a1, 0x39($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X39);
L_8018EBF4:
    // 0x8018EBF4: jal         0x8018E95C
    // 0x8018EBF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    sc1PBonusStageWriteBackup(rdram, ctx);
        goto after_10;
    // 0x8018EBF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_10:
    // 0x8018EBFC: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8018EC00: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
    // 0x8018EC04: lbu         $t5, 0x1($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X1);
    // 0x8018EC08: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8018EC0C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8018EC10: bne         $t5, $at, L_8018ED1C
    if (ctx->r13 != ctx->r1) {
        // 0x8018EC14: addiu       $a2, $zero, 0xA
        ctx->r6 = ADD32(0, 0XA);
            goto L_8018ED1C;
    }
    // 0x8018EC14: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    // 0x8018EC18: addiu       $t6, $zero, 0x13
    ctx->r14 = ADD32(0, 0X13);
    // 0x8018EC1C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018EC20: bne         $v0, $at, L_8018ED50
    if (ctx->r2 != ctx->r1) {
        // 0x8018EC24: sb          $t6, 0x0($a3)
        MEM_B(0X0, ctx->r7) = ctx->r14;
            goto L_8018ED50;
    }
    // 0x8018EC24: sb          $t6, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r14;
    // 0x8018EC28: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8018EC2C: lbu         $t7, 0x4937($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4937);
    // 0x8018EC30: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018EC34: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018EC38: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x8018EC3C: bne         $t8, $zero, L_8018ECF4
    if (ctx->r24 != 0) {
        // 0x8018EC40: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_8018ECF4;
    }
    // 0x8018EC40: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x8018EC44: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    // 0x8018EC48: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
L_8018EC4C:
    // 0x8018EC4C: lbu         $t9, 0x470($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X470);
    // 0x8018EC50: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8018EC54: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x8018EC58: bne         $a2, $t9, L_8018EC68
    if (ctx->r6 != ctx->r25) {
        // 0x8018EC5C: sllv        $t1, $t0, $v1
        ctx->r9 = S32(ctx->r8 << (ctx->r3 & 31));
            goto L_8018EC68;
    }
    // 0x8018EC5C: sllv        $t1, $t0, $v1
    ctx->r9 = S32(ctx->r8 << (ctx->r3 & 31));
    // 0x8018EC60: or          $v0, $v0, $t1
    ctx->r2 = ctx->r2 | ctx->r9;
    // 0x8018EC64: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8018EC68:
    // 0x8018EC68: lbu         $t2, 0x490($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X490);
    // 0x8018EC6C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018EC70: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8018EC74: bne         $a2, $t2, L_8018EC84
    if (ctx->r6 != ctx->r10) {
        // 0x8018EC78: addiu       $t7, $v1, 0x2
        ctx->r15 = ADD32(ctx->r3, 0X2);
            goto L_8018EC84;
    }
    // 0x8018EC78: addiu       $t7, $v1, 0x2
    ctx->r15 = ADD32(ctx->r3, 0X2);
    // 0x8018EC7C: or          $v0, $v0, $t5
    ctx->r2 = ctx->r2 | ctx->r13;
    // 0x8018EC80: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8018EC84:
    // 0x8018EC84: lbu         $t6, 0x4B0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4B0);
    // 0x8018EC88: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018EC8C: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x8018EC90: bne         $a2, $t6, L_8018ECA0
    if (ctx->r6 != ctx->r14) {
        // 0x8018EC94: addiu       $t1, $v1, 0x3
        ctx->r9 = ADD32(ctx->r3, 0X3);
            goto L_8018ECA0;
    }
    // 0x8018EC94: addiu       $t1, $v1, 0x3
    ctx->r9 = ADD32(ctx->r3, 0X3);
    // 0x8018EC98: or          $v0, $v0, $t9
    ctx->r2 = ctx->r2 | ctx->r25;
    // 0x8018EC9C: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8018ECA0:
    // 0x8018ECA0: lbu         $t0, 0x4D0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X4D0);
    // 0x8018ECA4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018ECA8: sllv        $t4, $t2, $t1
    ctx->r12 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x8018ECAC: bne         $a2, $t0, L_8018ECBC
    if (ctx->r6 != ctx->r8) {
        // 0x8018ECB0: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8018ECBC;
    }
    // 0x8018ECB0: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8018ECB4: or          $v0, $v0, $t4
    ctx->r2 = ctx->r2 | ctx->r12;
    // 0x8018ECB8: andi        $v0, $v0, 0xFFFF
    ctx->r2 = ctx->r2 & 0XFFFF;
L_8018ECBC:
    // 0x8018ECBC: bne         $v1, $a1, L_8018EC4C
    if (ctx->r3 != ctx->r5) {
        // 0x8018ECC0: addiu       $a0, $a0, 0x80
        ctx->r4 = ADD32(ctx->r4, 0X80);
            goto L_8018EC4C;
    }
    // 0x8018ECC0: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x8018ECC4: andi        $t3, $v0, 0x36F
    ctx->r11 = ctx->r2 & 0X36F;
    // 0x8018ECC8: addiu       $at, $zero, 0x36F
    ctx->r1 = ADD32(0, 0X36F);
    // 0x8018ECCC: bne         $t3, $at, L_8018ECF4
    if (ctx->r11 != ctx->r1) {
        // 0x8018ECD0: addiu       $t8, $zero, 0xE
        ctx->r24 = ADD32(0, 0XE);
            goto L_8018ECF4;
    }
    // 0x8018ECD0: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x8018ECD4: lbu         $t5, 0x39($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X39);
    // 0x8018ECD8: lbu         $t6, 0x3A($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X3A);
    // 0x8018ECDC: addiu       $t7, $zero, 0x34
    ctx->r15 = ADD32(0, 0X34);
    // 0x8018ECE0: sb          $t8, 0x17($a3)
    MEM_B(0X17, ctx->r7) = ctx->r24;
    // 0x8018ECE4: sb          $t7, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r15;
    // 0x8018ECE8: sb          $t5, 0x14($a3)
    MEM_B(0X14, ctx->r7) = ctx->r13;
    // 0x8018ECEC: b           L_8018ED50
    // 0x8018ECF0: sb          $t6, 0x15($a3)
    MEM_B(0X15, ctx->r7) = ctx->r14;
        goto L_8018ED50;
    // 0x8018ECF0: sb          $t6, 0x15($a3)
    MEM_B(0X15, ctx->r7) = ctx->r14;
L_8018ECF4:
    // 0x8018ECF4: jal         0x800D6630
    // 0x8018ECF8: nop

    sc1PManagerCheckUnlockSoundTest(rdram, ctx);
        goto after_11;
    // 0x8018ECF8: nop

    after_11:
    // 0x8018ECFC: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8018ED00: beq         $v0, $zero, L_8018ED50
    if (ctx->r2 == 0) {
        // 0x8018ED04: addiu       $a3, $a3, 0x4AD0
        ctx->r7 = ADD32(ctx->r7, 0X4AD0);
            goto L_8018ED50;
    }
    // 0x8018ED04: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
    // 0x8018ED08: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8018ED0C: addiu       $t0, $zero, 0xC
    ctx->r8 = ADD32(0, 0XC);
    // 0x8018ED10: sb          $t9, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r25;
    // 0x8018ED14: b           L_8018ED50
    // 0x8018ED18: sb          $t0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r8;
        goto L_8018ED50;
    // 0x8018ED18: sb          $t0, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r8;
L_8018ED1C:
    // 0x8018ED1C: addiu       $t2, $zero, 0x14
    ctx->r10 = ADD32(0, 0X14);
    // 0x8018ED20: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8018ED24: bne         $v0, $at, L_8018ED50
    if (ctx->r2 != ctx->r1) {
        // 0x8018ED28: sb          $t2, 0x0($a3)
        MEM_B(0X0, ctx->r7) = ctx->r10;
            goto L_8018ED50;
    }
    // 0x8018ED28: sb          $t2, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r10;
    // 0x8018ED2C: jal         0x800D6630
    // 0x8018ED30: nop

    sc1PManagerCheckUnlockSoundTest(rdram, ctx);
        goto after_12;
    // 0x8018ED30: nop

    after_12:
    // 0x8018ED34: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x8018ED38: beq         $v0, $zero, L_8018ED50
    if (ctx->r2 == 0) {
        // 0x8018ED3C: addiu       $a3, $a3, 0x4AD0
        ctx->r7 = ADD32(ctx->r7, 0X4AD0);
            goto L_8018ED50;
    }
    // 0x8018ED3C: addiu       $a3, $a3, 0x4AD0
    ctx->r7 = ADD32(ctx->r7, 0X4AD0);
    // 0x8018ED40: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x8018ED44: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8018ED48: sb          $t1, 0x2($a3)
    MEM_B(0X2, ctx->r7) = ctx->r9;
    // 0x8018ED4C: sb          $t4, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r12;
L_8018ED50:
    // 0x8018ED50: addiu       $t3, $zero, 0x35
    ctx->r11 = ADD32(0, 0X35);
    // 0x8018ED54: sb          $t3, 0x1($a3)
    MEM_B(0X1, ctx->r7) = ctx->r11;
    // 0x8018ED58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8018ED5C:
    // 0x8018ED5C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8018ED60: jr          $ra
    // 0x8018ED64: nop

    return;
    // 0x8018ED64: nop

;}
RECOMP_FUNC void func_800210C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800210C0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800210C4: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x800210C8: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x800210CC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800210D0: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x800210D4: bltz        $a2, L_80021724
    if (SIGNED(ctx->r6) < 0) {
        // 0x800210D8: sw          $a3, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r7;
            goto L_80021724;
    }
    // 0x800210D8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    // 0x800210DC: slti        $at, $a2, 0x11
    ctx->r1 = SIGNED(ctx->r6) < 0X11 ? 1 : 0;
    // 0x800210E0: beq         $at, $zero, L_80021724
    if (ctx->r1 == 0) {
        // 0x800210E4: sll         $t6, $a2, 5
        ctx->r14 = S32(ctx->r6 << 5);
            goto L_80021724;
    }
    // 0x800210E4: sll         $t6, $a2, 5
    ctx->r14 = S32(ctx->r6 << 5);
    // 0x800210E8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800210EC: addiu       $t7, $t7, -0x33D0
    ctx->r15 = ADD32(ctx->r15, -0X33D0);
    // 0x800210F0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800210F4: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800210F8: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x800210FC: addiu       $t0, $t0, 0x65B0
    ctx->r8 = ADD32(ctx->r8, 0X65B0);
    // 0x80021100: bne         $t8, $zero, L_80021128
    if (ctx->r24 != 0) {
        // 0x80021104: lw          $v0, 0x0($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X0);
            goto L_80021128;
    }
    // 0x80021104: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x80021108: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x8002110C: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80021110: addiu       $t1, $t1, 0x6678
    ctx->r9 = ADD32(ctx->r9, 0X6678);
    // 0x80021114: addiu       $t4, $t4, 0x667C
    ctx->r12 = ADD32(ctx->r12, 0X667C);
    // 0x80021118: addiu       $t5, $zero, 0xF0
    ctx->r13 = ADD32(0, 0XF0);
    // 0x8002111C: lui         $t3, 0xF600
    ctx->r11 = S32(0XF600 << 16);
    // 0x80021120: b           L_800212B0
    // 0x80021124: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
        goto L_800212B0;
    // 0x80021124: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
L_80021128:
    // 0x80021128: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8002112C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80021130: lw          $t9, -0x3448($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3448);
    // 0x80021134: addiu       $t1, $t1, 0x6678
    ctx->r9 = ADD32(ctx->r9, 0X6678);
    // 0x80021138: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8002113C: addu        $t6, $t9, $s0
    ctx->r14 = ADD32(ctx->r25, ctx->r16);
    // 0x80021140: addiu       $t2, $zero, 0x140
    ctx->r10 = ADD32(0, 0X140);
    // 0x80021144: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021148: lui         $t3, 0xF600
    ctx->r11 = S32(0XF600 << 16);
    // 0x8002114C: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80021150: addiu       $t4, $t4, 0x667C
    ctx->r12 = ADD32(ctx->r12, 0X667C);
    // 0x80021154: addiu       $t5, $zero, 0xF0
    ctx->r13 = ADD32(0, 0XF0);
    // 0x80021158: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x8002115C: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x80021160: mflo        $t8
    ctx->r24 = lo;
    // 0x80021164: nop

    // 0x80021168: nop

    // 0x8002116C: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x80021170: mflo        $t9
    ctx->r25 = lo;
    // 0x80021174: andi        $t6, $t9, 0x3FF
    ctx->r14 = ctx->r25 & 0X3FF;
    // 0x80021178: bne         $t2, $zero, L_80021184
    if (ctx->r10 != 0) {
        // 0x8002117C: nop
    
            goto L_80021184;
    }
    // 0x8002117C: nop

    // 0x80021180: break       7
    do_break(2147619200);
L_80021184:
    // 0x80021184: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021188: bne         $t2, $at, L_8002119C
    if (ctx->r10 != ctx->r1) {
        // 0x8002118C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002119C;
    }
    // 0x8002118C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021190: bne         $t8, $at, L_8002119C
    if (ctx->r24 != ctx->r1) {
        // 0x80021194: nop
    
            goto L_8002119C;
    }
    // 0x80021194: nop

    // 0x80021198: break       6
    do_break(2147619224);
L_8002119C:
    // 0x8002119C: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x800211A0: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800211A4: lw          $t9, -0x3444($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3444);
    // 0x800211A8: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x800211AC: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800211B0: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x800211B4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800211B8: mflo        $t9
    ctx->r25 = lo;
    // 0x800211BC: nop

    // 0x800211C0: nop

    // 0x800211C4: div         $zero, $t9, $t5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r13)));
    // 0x800211C8: mflo        $t6
    ctx->r14 = lo;
    // 0x800211CC: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800211D0: bne         $t5, $zero, L_800211DC
    if (ctx->r13 != 0) {
        // 0x800211D4: nop
    
            goto L_800211DC;
    }
    // 0x800211D4: nop

    // 0x800211D8: break       7
    do_break(2147619288);
L_800211DC:
    // 0x800211DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800211E0: bne         $t5, $at, L_800211F4
    if (ctx->r13 != ctx->r1) {
        // 0x800211E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800211F4;
    }
    // 0x800211E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800211E8: bne         $t9, $at, L_800211F4
    if (ctx->r25 != ctx->r1) {
        // 0x800211EC: nop
    
            goto L_800211F4;
    }
    // 0x800211EC: nop

    // 0x800211F0: break       6
    do_break(2147619312);
L_800211F4:
    // 0x800211F4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800211F8: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800211FC: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80021200: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80021204: lw          $t7, -0x3450($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X3450);
    // 0x80021208: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x8002120C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80021210: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021214: mflo        $t6
    ctx->r14 = lo;
    // 0x80021218: nop

    // 0x8002121C: nop

    // 0x80021220: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x80021224: bne         $t2, $zero, L_80021230
    if (ctx->r10 != 0) {
        // 0x80021228: nop
    
            goto L_80021230;
    }
    // 0x80021228: nop

    // 0x8002122C: break       7
    do_break(2147619372);
L_80021230:
    // 0x80021230: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021234: bne         $t2, $at, L_80021248
    if (ctx->r10 != ctx->r1) {
        // 0x80021238: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021248;
    }
    // 0x80021238: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002123C: bne         $t6, $at, L_80021248
    if (ctx->r14 != ctx->r1) {
        // 0x80021240: nop
    
            goto L_80021248;
    }
    // 0x80021240: nop

    // 0x80021244: break       6
    do_break(2147619396);
L_80021248:
    // 0x80021248: mflo        $t7
    ctx->r15 = lo;
    // 0x8002124C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80021250: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80021254: lw          $t6, -0x344C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X344C);
    // 0x80021258: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8002125C: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80021260: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80021264: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021268: mflo        $t6
    ctx->r14 = lo;
    // 0x8002126C: nop

    // 0x80021270: nop

    // 0x80021274: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x80021278: mflo        $t7
    ctx->r15 = lo;
    // 0x8002127C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80021280: bne         $t5, $zero, L_8002128C
    if (ctx->r13 != 0) {
        // 0x80021284: nop
    
            goto L_8002128C;
    }
    // 0x80021284: nop

    // 0x80021288: break       7
    do_break(2147619464);
L_8002128C:
    // 0x8002128C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021290: bne         $t5, $at, L_800212A4
    if (ctx->r13 != ctx->r1) {
        // 0x80021294: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800212A4;
    }
    // 0x80021294: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021298: bne         $t6, $at, L_800212A4
    if (ctx->r14 != ctx->r1) {
        // 0x8002129C: nop
    
            goto L_800212A4;
    }
    // 0x8002129C: nop

    // 0x800212A0: break       6
    do_break(2147619488);
L_800212A4:
    // 0x800212A4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800212A8: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800212AC: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
L_800212B0:
    // 0x800212B0: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
    // 0x800212B4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800212B8: addiu       $v1, $v1, -0x3440
    ctx->r3 = ADD32(ctx->r3, -0X3440);
    // 0x800212BC: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800212C0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800212C4:
    // 0x800212C4: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800212C8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800212CC: beql        $t8, $zero, L_80021434
    if (ctx->r24 == 0) {
        // 0x800212D0: lw          $t8, 0x4($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X4);
            goto L_80021434;
    }
    goto skip_0;
    // 0x800212D0: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    skip_0:
    // 0x800212D4: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800212D8: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800212DC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800212E0: addu        $t6, $t9, $s0
    ctx->r14 = ADD32(ctx->r25, ctx->r16);
    // 0x800212E4: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800212E8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800212EC: mflo        $t8
    ctx->r24 = lo;
    // 0x800212F0: nop

    // 0x800212F4: nop

    // 0x800212F8: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800212FC: mflo        $t9
    ctx->r25 = lo;
    // 0x80021300: andi        $t6, $t9, 0x3FF
    ctx->r14 = ctx->r25 & 0X3FF;
    // 0x80021304: bne         $t2, $zero, L_80021310
    if (ctx->r10 != 0) {
        // 0x80021308: nop
    
            goto L_80021310;
    }
    // 0x80021308: nop

    // 0x8002130C: break       7
    do_break(2147619596);
L_80021310:
    // 0x80021310: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021314: bne         $t2, $at, L_80021328
    if (ctx->r10 != ctx->r1) {
        // 0x80021318: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021328;
    }
    // 0x80021318: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002131C: bne         $t8, $at, L_80021328
    if (ctx->r24 != ctx->r1) {
        // 0x80021320: nop
    
            goto L_80021328;
    }
    // 0x80021320: nop

    // 0x80021324: break       6
    do_break(2147619620);
L_80021328:
    // 0x80021328: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x8002132C: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x80021330: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x80021334: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x80021338: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x8002133C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021340: mflo        $t9
    ctx->r25 = lo;
    // 0x80021344: nop

    // 0x80021348: nop

    // 0x8002134C: div         $zero, $t9, $t5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r13)));
    // 0x80021350: mflo        $t6
    ctx->r14 = lo;
    // 0x80021354: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x80021358: bne         $t5, $zero, L_80021364
    if (ctx->r13 != 0) {
        // 0x8002135C: nop
    
            goto L_80021364;
    }
    // 0x8002135C: nop

    // 0x80021360: break       7
    do_break(2147619680);
L_80021364:
    // 0x80021364: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021368: bne         $t5, $at, L_8002137C
    if (ctx->r13 != ctx->r1) {
        // 0x8002136C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002137C;
    }
    // 0x8002136C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021370: bne         $t9, $at, L_8002137C
    if (ctx->r25 != ctx->r1) {
        // 0x80021374: nop
    
            goto L_8002137C;
    }
    // 0x80021374: nop

    // 0x80021378: break       6
    do_break(2147619704);
L_8002137C:
    // 0x8002137C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80021380: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80021384: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80021388: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8002138C: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80021390: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80021394: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021398: mflo        $t6
    ctx->r14 = lo;
    // 0x8002139C: nop

    // 0x800213A0: nop

    // 0x800213A4: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x800213A8: mflo        $t7
    ctx->r15 = lo;
    // 0x800213AC: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x800213B0: bne         $t2, $zero, L_800213BC
    if (ctx->r10 != 0) {
        // 0x800213B4: nop
    
            goto L_800213BC;
    }
    // 0x800213B4: nop

    // 0x800213B8: break       7
    do_break(2147619768);
L_800213BC:
    // 0x800213BC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800213C0: bne         $t2, $at, L_800213D4
    if (ctx->r10 != ctx->r1) {
        // 0x800213C4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800213D4;
    }
    // 0x800213C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800213C8: bne         $t6, $at, L_800213D4
    if (ctx->r14 != ctx->r1) {
        // 0x800213CC: nop
    
            goto L_800213D4;
    }
    // 0x800213CC: nop

    // 0x800213D0: break       6
    do_break(2147619792);
L_800213D4:
    // 0x800213D4: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x800213D8: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x800213DC: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800213E0: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x800213E4: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800213E8: mflo        $t6
    ctx->r14 = lo;
    // 0x800213EC: nop

    // 0x800213F0: nop

    // 0x800213F4: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x800213F8: mflo        $t7
    ctx->r15 = lo;
    // 0x800213FC: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80021400: bne         $t5, $zero, L_8002140C
    if (ctx->r13 != 0) {
        // 0x80021404: nop
    
            goto L_8002140C;
    }
    // 0x80021404: nop

    // 0x80021408: break       7
    do_break(2147619848);
L_8002140C:
    // 0x8002140C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021410: bne         $t5, $at, L_80021424
    if (ctx->r13 != ctx->r1) {
        // 0x80021414: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021424;
    }
    // 0x80021414: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021418: bne         $t6, $at, L_80021424
    if (ctx->r14 != ctx->r1) {
        // 0x8002141C: nop
    
            goto L_80021424;
    }
    // 0x8002141C: nop

    // 0x80021420: break       6
    do_break(2147619872);
L_80021424:
    // 0x80021424: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80021428: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8002142C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x80021430: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
L_80021434:
    // 0x80021434: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80021438: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8002143C: beq         $t8, $zero, L_800215A0
    if (ctx->r24 == 0) {
        // 0x80021440: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800215A0;
    }
    // 0x80021440: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80021444: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x80021448: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8002144C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80021450: addu        $t6, $t9, $s0
    ctx->r14 = ADD32(ctx->r25, ctx->r16);
    // 0x80021454: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021458: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x8002145C: mflo        $t8
    ctx->r24 = lo;
    // 0x80021460: nop

    // 0x80021464: nop

    // 0x80021468: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x8002146C: mflo        $t9
    ctx->r25 = lo;
    // 0x80021470: andi        $t6, $t9, 0x3FF
    ctx->r14 = ctx->r25 & 0X3FF;
    // 0x80021474: bne         $t2, $zero, L_80021480
    if (ctx->r10 != 0) {
        // 0x80021478: nop
    
            goto L_80021480;
    }
    // 0x80021478: nop

    // 0x8002147C: break       7
    do_break(2147619964);
L_80021480:
    // 0x80021480: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021484: bne         $t2, $at, L_80021498
    if (ctx->r10 != ctx->r1) {
        // 0x80021488: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021498;
    }
    // 0x80021488: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002148C: bne         $t8, $at, L_80021498
    if (ctx->r24 != ctx->r1) {
        // 0x80021490: nop
    
            goto L_80021498;
    }
    // 0x80021490: nop

    // 0x80021494: break       6
    do_break(2147619988);
L_80021498:
    // 0x80021498: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x8002149C: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x800214A0: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x800214A4: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x800214A8: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x800214AC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800214B0: mflo        $t9
    ctx->r25 = lo;
    // 0x800214B4: nop

    // 0x800214B8: nop

    // 0x800214BC: div         $zero, $t9, $t5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r13)));
    // 0x800214C0: mflo        $t6
    ctx->r14 = lo;
    // 0x800214C4: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x800214C8: bne         $t5, $zero, L_800214D4
    if (ctx->r13 != 0) {
        // 0x800214CC: nop
    
            goto L_800214D4;
    }
    // 0x800214CC: nop

    // 0x800214D0: break       7
    do_break(2147620048);
L_800214D4:
    // 0x800214D4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800214D8: bne         $t5, $at, L_800214EC
    if (ctx->r13 != ctx->r1) {
        // 0x800214DC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800214EC;
    }
    // 0x800214DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800214E0: bne         $t9, $at, L_800214EC
    if (ctx->r25 != ctx->r1) {
        // 0x800214E4: nop
    
            goto L_800214EC;
    }
    // 0x800214E4: nop

    // 0x800214E8: break       6
    do_break(2147620072);
L_800214EC:
    // 0x800214EC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800214F0: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800214F4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800214F8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800214FC: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80021500: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x80021504: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021508: mflo        $t6
    ctx->r14 = lo;
    // 0x8002150C: nop

    // 0x80021510: nop

    // 0x80021514: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x80021518: mflo        $t7
    ctx->r15 = lo;
    // 0x8002151C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80021520: bne         $t2, $zero, L_8002152C
    if (ctx->r10 != 0) {
        // 0x80021524: nop
    
            goto L_8002152C;
    }
    // 0x80021524: nop

    // 0x80021528: break       7
    do_break(2147620136);
L_8002152C:
    // 0x8002152C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021530: bne         $t2, $at, L_80021544
    if (ctx->r10 != ctx->r1) {
        // 0x80021534: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021544;
    }
    // 0x80021534: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021538: bne         $t6, $at, L_80021544
    if (ctx->r14 != ctx->r1) {
        // 0x8002153C: nop
    
            goto L_80021544;
    }
    // 0x8002153C: nop

    // 0x80021540: break       6
    do_break(2147620160);
L_80021544:
    // 0x80021544: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80021548: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x8002154C: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80021550: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x80021554: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021558: mflo        $t6
    ctx->r14 = lo;
    // 0x8002155C: nop

    // 0x80021560: nop

    // 0x80021564: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x80021568: mflo        $t7
    ctx->r15 = lo;
    // 0x8002156C: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80021570: bne         $t5, $zero, L_8002157C
    if (ctx->r13 != 0) {
        // 0x80021574: nop
    
            goto L_8002157C;
    }
    // 0x80021574: nop

    // 0x80021578: break       7
    do_break(2147620216);
L_8002157C:
    // 0x8002157C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021580: bne         $t5, $at, L_80021594
    if (ctx->r13 != ctx->r1) {
        // 0x80021584: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021594;
    }
    // 0x80021584: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021588: bne         $t6, $at, L_80021594
    if (ctx->r14 != ctx->r1) {
        // 0x8002158C: nop
    
            goto L_80021594;
    }
    // 0x8002158C: nop

    // 0x80021590: break       6
    do_break(2147620240);
L_80021594:
    // 0x80021594: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80021598: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8002159C: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
L_800215A0:
    // 0x800215A0: bne         $a2, $a1, L_800212C4
    if (ctx->r6 != ctx->r5) {
        // 0x800215A4: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800212C4;
    }
    // 0x800215A4: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800215A8: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800215AC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x800215B0: sw          $v1, -0x2600($at)
    MEM_W(-0X2600, ctx->r1) = ctx->r3;
    // 0x800215B4: beql        $t8, $zero, L_80021724
    if (ctx->r24 == 0) {
        // 0x800215B8: sw          $v0, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r2;
            goto L_80021724;
    }
    goto skip_1;
    // 0x800215B8: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    skip_1:
    // 0x800215BC: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800215C0: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800215C4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800215C8: addu        $t6, $t9, $s0
    ctx->r14 = ADD32(ctx->r25, ctx->r16);
    // 0x800215CC: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800215D0: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800215D4: mflo        $t8
    ctx->r24 = lo;
    // 0x800215D8: nop

    // 0x800215DC: nop

    // 0x800215E0: div         $zero, $t8, $t2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r10)));
    // 0x800215E4: mflo        $t9
    ctx->r25 = lo;
    // 0x800215E8: andi        $t6, $t9, 0x3FF
    ctx->r14 = ctx->r25 & 0X3FF;
    // 0x800215EC: bne         $t2, $zero, L_800215F8
    if (ctx->r10 != 0) {
        // 0x800215F0: nop
    
            goto L_800215F8;
    }
    // 0x800215F0: nop

    // 0x800215F4: break       7
    do_break(2147620340);
L_800215F8:
    // 0x800215F8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800215FC: bne         $t2, $at, L_80021610
    if (ctx->r10 != ctx->r1) {
        // 0x80021600: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021610;
    }
    // 0x80021600: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021604: bne         $t8, $at, L_80021610
    if (ctx->r24 != ctx->r1) {
        // 0x80021608: nop
    
            goto L_80021610;
    }
    // 0x80021608: nop

    // 0x8002160C: break       6
    do_break(2147620364);
L_80021610:
    // 0x80021610: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80021614: lw          $t9, 0xC($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XC);
    // 0x80021618: or          $t8, $t7, $t3
    ctx->r24 = ctx->r15 | ctx->r11;
    // 0x8002161C: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x80021620: addu        $t6, $s1, $t9
    ctx->r14 = ADD32(ctx->r17, ctx->r25);
    // 0x80021624: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021628: mflo        $t9
    ctx->r25 = lo;
    // 0x8002162C: nop

    // 0x80021630: nop

    // 0x80021634: div         $zero, $t9, $t5
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r13)));
    // 0x80021638: mflo        $t6
    ctx->r14 = lo;
    // 0x8002163C: andi        $t7, $t6, 0x3FF
    ctx->r15 = ctx->r14 & 0X3FF;
    // 0x80021640: bne         $t5, $zero, L_8002164C
    if (ctx->r13 != 0) {
        // 0x80021644: nop
    
            goto L_8002164C;
    }
    // 0x80021644: nop

    // 0x80021648: break       7
    do_break(2147620424);
L_8002164C:
    // 0x8002164C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80021650: bne         $t5, $at, L_80021664
    if (ctx->r13 != ctx->r1) {
        // 0x80021654: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021664;
    }
    // 0x80021654: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80021658: bne         $t9, $at, L_80021664
    if (ctx->r25 != ctx->r1) {
        // 0x8002165C: nop
    
            goto L_80021664;
    }
    // 0x8002165C: nop

    // 0x80021660: break       6
    do_break(2147620448);
L_80021664:
    // 0x80021664: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80021668: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8002166C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80021670: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80021674: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x80021678: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8002167C: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80021680: mflo        $t6
    ctx->r14 = lo;
    // 0x80021684: nop

    // 0x80021688: nop

    // 0x8002168C: div         $zero, $t6, $t2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r10)));
    // 0x80021690: mflo        $t7
    ctx->r15 = lo;
    // 0x80021694: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x80021698: bne         $t2, $zero, L_800216A4
    if (ctx->r10 != 0) {
        // 0x8002169C: nop
    
            goto L_800216A4;
    }
    // 0x8002169C: nop

    // 0x800216A0: break       7
    do_break(2147620512);
L_800216A4:
    // 0x800216A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800216A8: bne         $t2, $at, L_800216BC
    if (ctx->r10 != ctx->r1) {
        // 0x800216AC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800216BC;
    }
    // 0x800216AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800216B0: bne         $t6, $at, L_800216BC
    if (ctx->r14 != ctx->r1) {
        // 0x800216B4: nop
    
            goto L_800216BC;
    }
    // 0x800216B4: nop

    // 0x800216B8: break       6
    do_break(2147620536);
L_800216BC:
    // 0x800216BC: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x800216C0: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x800216C4: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x800216C8: addu        $t7, $s1, $t6
    ctx->r15 = ADD32(ctx->r17, ctx->r14);
    // 0x800216CC: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800216D0: mflo        $t6
    ctx->r14 = lo;
    // 0x800216D4: nop

    // 0x800216D8: nop

    // 0x800216DC: div         $zero, $t6, $t5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r13))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r13)));
    // 0x800216E0: bne         $t5, $zero, L_800216EC
    if (ctx->r13 != 0) {
        // 0x800216E4: nop
    
            goto L_800216EC;
    }
    // 0x800216E4: nop

    // 0x800216E8: break       7
    do_break(2147620584);
L_800216EC:
    // 0x800216EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800216F0: bne         $t5, $at, L_80021704
    if (ctx->r13 != ctx->r1) {
        // 0x800216F4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80021704;
    }
    // 0x800216F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800216F8: bne         $t6, $at, L_80021704
    if (ctx->r14 != ctx->r1) {
        // 0x800216FC: nop
    
            goto L_80021704;
    }
    // 0x800216FC: nop

    // 0x80021700: break       6
    do_break(2147620608);
L_80021704:
    // 0x80021704: mflo        $t7
    ctx->r15 = lo;
    // 0x80021708: andi        $t8, $t7, 0x3FF
    ctx->r24 = ctx->r15 & 0X3FF;
    // 0x8002170C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80021710: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80021714: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80021718: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8002171C: sw          $v1, -0x2600($at)
    MEM_W(-0X2600, ctx->r1) = ctx->r3;
    // 0x80021720: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
L_80021724:
    // 0x80021724: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x80021728: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8002172C: jr          $ra
    // 0x80021730: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x80021730: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void mnCongraFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FE8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131FEC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131FF0: addiu       $t8, $t8, 0x21E0
    ctx->r24 = ADD32(ctx->r24, 0X21E0);
    // 0x80131FF4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131FF8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131FFC: lui         $t7, 0xDE00
    ctx->r15 = S32(0XDE00 << 16);
    // 0x80132000: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132004: jr          $ra
    // 0x80132008: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80132008: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void ftKirbyCopyMarioSpecialNProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801569B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801569B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801569B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x801569BC: jal         0x800D9480
    // 0x801569C0: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801569C0: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    after_0:
    // 0x801569C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801569C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801569CC: jr          $ra
    // 0x801569D0: nop

    return;
    // 0x801569D0: nop

;}
RECOMP_FUNC void itPorygonCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80183C84: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80183C88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80183C8C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80183C90: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80183C94: lwc1        $f6, 0x350($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X350);
    // 0x80183C98: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80183C9C: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80183CA0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80183CA4: swc1        $f8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f8.u32l;
    // 0x80183CA8: lwc1        $f16, 0x354($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X354);
    // 0x80183CAC: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80183CB0: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
    // 0x80183CB4: jal         0x80183B10
    // 0x80183CB8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    itPorygonCommonUpdateMonsterEvent(rdram, ctx);
        goto after_0;
    // 0x80183CB8: sw          $v1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r3;
    after_0:
    // 0x80183CBC: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x80183CC0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80183CC4: lwc1        $f4, -0x3100($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3100);
    // 0x80183CC8: lwc1        $f6, 0x74($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X74);
    // 0x80183CCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80183CD0: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80183CD4: nop

    // 0x80183CD8: bc1f        L_80183CF0
    if (!c1cs) {
        // 0x80183CDC: nop
    
            goto L_80183CF0;
    }
    // 0x80183CDC: nop

    // 0x80183CE0: jal         0x8010B0B8
    // 0x80183CE4: nop

    grYamabukiGateSetClosedWait(rdram, ctx);
        goto after_1;
    // 0x80183CE4: nop

    after_1:
    // 0x80183CE8: b           L_80183CF0
    // 0x80183CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80183CF0;
    // 0x80183CEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80183CF0:
    // 0x80183CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80183CF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80183CF8: jr          $ra
    // 0x80183CFC: nop

    return;
    // 0x80183CFC: nop

;}
RECOMP_FUNC void grHyruleTwisterUpdateMove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A610: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8010A614: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8010A618: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x8010A61C: addiu       $s0, $s0, 0x13F0
    ctx->r16 = ADD32(ctx->r16, 0X13F0);
    // 0x8010A620: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8010A624: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8010A628: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8010A62C: lw          $s1, 0x74($t6)
    ctx->r17 = MEM_W(ctx->r14, 0X74);
    // 0x8010A630: jal         0x8010A4F4
    // 0x8010A634: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    grHyruleTwisterDecLifetimeCheckStop(rdram, ctx);
        goto after_0;
    // 0x8010A634: addiu       $s1, $s1, 0x1C
    ctx->r17 = ADD32(ctx->r17, 0X1C);
    after_0:
    // 0x8010A638: bnel        $v0, $zero, L_8010A7BC
    if (ctx->r2 != 0) {
        // 0x8010A63C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8010A7BC;
    }
    goto skip_0;
    // 0x8010A63C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x8010A640: lhu         $v0, 0x24($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X24);
    // 0x8010A644: beq         $v0, $zero, L_8010A690
    if (ctx->r2 == 0) {
        // 0x8010A648: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_8010A690;
    }
    // 0x8010A648: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x8010A64C: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8010A650: bne         $t8, $zero, L_8010A6F0
    if (ctx->r24 != 0) {
        // 0x8010A654: sh          $t7, 0x24($s0)
        MEM_H(0X24, ctx->r16) = ctx->r15;
            goto L_8010A6F0;
    }
    // 0x8010A654: sh          $t7, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r15;
    // 0x8010A658: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8010A65C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8010A660: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8010A664: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x8010A668: nop

    // 0x8010A66C: bc1fl       L_8010A688
    if (!c1cs) {
        // 0x8010A670: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_8010A688;
    }
    goto skip_1;
    // 0x8010A670: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_1:
    // 0x8010A674: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8010A678: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010A67C: b           L_8010A6F0
    // 0x8010A680: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
        goto L_8010A6F0;
    // 0x8010A680: swc1        $f8, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f8.u32l;
    // 0x8010A684: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_8010A688:
    // 0x8010A688: b           L_8010A6F0
    // 0x8010A68C: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
        goto L_8010A6F0;
    // 0x8010A68C: swc1        $f10, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f10.u32l;
L_8010A690:
    // 0x8010A690: lhu         $t9, 0x22($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X22);
    // 0x8010A694: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8010A698: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x8010A69C: bne         $t1, $zero, L_8010A6F0
    if (ctx->r9 != 0) {
        // 0x8010A6A0: sh          $t0, 0x22($s0)
        MEM_H(0X22, ctx->r16) = ctx->r8;
            goto L_8010A6F0;
    }
    // 0x8010A6A0: sh          $t0, 0x22($s0)
    MEM_H(0X22, ctx->r16) = ctx->r8;
    // 0x8010A6A4: jal         0x8010A52C
    // 0x8010A6A8: nop

    grHyruleTwisterGetLR(rdram, ctx);
        goto after_1;
    // 0x8010A6A8: nop

    after_1:
    // 0x8010A6AC: beq         $v0, $zero, L_8010A6F0
    if (ctx->r2 == 0) {
        // 0x8010A6B0: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_8010A6F0;
    }
    // 0x8010A6B0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x8010A6B4: jal         0x80018994
    // 0x8010A6B8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x8010A6B8: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x8010A6BC: bnel        $v0, $zero, L_8010A6F4
    if (ctx->r2 != 0) {
        // 0x8010A6C0: lwc1        $f8, 0x0($s1)
        ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
            goto L_8010A6F4;
    }
    goto skip_2;
    // 0x8010A6C0: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x8010A6C4: jal         0x80018994
    // 0x8010A6C8: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x8010A6C8: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_3:
    // 0x8010A6CC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x8010A6D0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x8010A6D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010A6D8: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8010A6DC: addiu       $t2, $v0, 0x12C
    ctx->r10 = ADD32(ctx->r2, 0X12C);
    // 0x8010A6E0: sh          $t2, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r10;
    // 0x8010A6E4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010A6E8: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8010A6EC: swc1        $f6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f6.u32l;
L_8010A6F0:
    // 0x8010A6F0: lwc1        $f8, 0x0($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X0);
L_8010A6F4:
    // 0x8010A6F4: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8010A6F8: lwc1        $f2, 0x10($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8010A6FC: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8010A700: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8010A704: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x8010A708: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8010A70C: addiu       $a2, $sp, 0x38
    ctx->r6 = ADD32(ctx->r29, 0X38);
    // 0x8010A710: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8010A714: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8010A718: bc1tl       L_8010A738
    if (c1cs) {
        // 0x8010A71C: c.lt.s      $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
            goto L_8010A738;
    }
    goto skip_3;
    // 0x8010A71C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    skip_3:
    // 0x8010A720: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8010A724: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8010A728: nop

    // 0x8010A72C: bc1fl       L_8010A780
    if (!c1cs) {
        // 0x8010A730: swc1        $f0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
            goto L_8010A780;
    }
    goto skip_4;
    // 0x8010A730: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
    skip_4:
    // 0x8010A734: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
L_8010A738:
    // 0x8010A738: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8010A73C: bc1fl       L_8010A760
    if (!c1cs) {
        // 0x8010A740: lwc1        $f6, 0xC($s0)
        ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
            goto L_8010A760;
    }
    goto skip_5;
    // 0x8010A740: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    skip_5:
    // 0x8010A744: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8010A748: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8010A74C: nop

    // 0x8010A750: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x8010A754: b           L_8010A770
    // 0x8010A758: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
        goto L_8010A770;
    // 0x8010A758: swc1        $f4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f4.u32l;
    // 0x8010A75C: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
L_8010A760:
    // 0x8010A760: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010A764: nop

    // 0x8010A768: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8010A76C: swc1        $f10, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f10.u32l;
L_8010A770:
    // 0x8010A770: sb          $t4, 0x28($s0)
    MEM_B(0X28, ctx->r16) = ctx->r12;
    // 0x8010A774: b           L_8010A780
    // 0x8010A778: sh          $t5, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r13;
        goto L_8010A780;
    // 0x8010A778: sh          $t5, 0x24($s0)
    MEM_H(0X24, ctx->r16) = ctx->r13;
    // 0x8010A77C: swc1        $f0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->f0.u32l;
L_8010A780:
    // 0x8010A780: lhu         $a0, 0x26($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X26);
    // 0x8010A784: jal         0x800F3DD8
    // 0x8010A788: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    mpCollisionGetFCCommonFloor(rdram, ctx);
        goto after_4;
    // 0x8010A788: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_4:
    // 0x8010A78C: lwc1        $f16, 0x4($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X4);
    // 0x8010A790: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8010A794: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8010A798: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8010A79C: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x8010A7A0: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8010A7A4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8010A7A8: lw          $t7, 0x4($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X4);
    // 0x8010A7AC: sw          $t7, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r15;
    // 0x8010A7B0: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x8010A7B4: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8010A7B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8010A7BC:
    // 0x8010A7BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8010A7C0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8010A7C4: jr          $ra
    // 0x8010A7C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8010A7C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftCommonDashProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EA90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013EA94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013EA98: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013EA9C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8013EAA0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013EAA4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8013EAA8: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    // 0x8013EAAC: beql        $t6, $zero, L_8013EB40
    if (ctx->r14 == 0) {
        // 0x8013EAB0: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8013EB40;
    }
    goto skip_0;
    // 0x8013EAB0: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_0:
    // 0x8013EAB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013EAB8: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8013EABC: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8013EAC0: nop

    // 0x8013EAC4: bc1fl       L_8013EB40
    if (!c1cs) {
        // 0x8013EAC8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8013EB40;
    }
    goto skip_1;
    // 0x8013EAC8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_1:
    // 0x8013EACC: jal         0x80151098
    // 0x8013EAD0: nop

    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8013EAD0: nop

    after_0:
    // 0x8013EAD4: bnel        $v0, $zero, L_8013EC48
    if (ctx->r2 != 0) {
        // 0x8013EAD8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EC48;
    }
    goto skip_2;
    // 0x8013EAD8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8013EADC: jal         0x80149CE0
    // 0x8013EAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8013EAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8013EAE4: bnel        $v0, $zero, L_8013EC48
    if (ctx->r2 != 0) {
        // 0x8013EAE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EC48;
    }
    goto skip_3;
    // 0x8013EAE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8013EAEC: jal         0x801501E0
    // 0x8013EAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS4CheckInterruptDash(rdram, ctx);
        goto after_2;
    // 0x8013EAF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013EAF4: bne         $v0, $zero, L_8013EC44
    if (ctx->r2 != 0) {
        // 0x8013EAF8: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_8013EC44;
    }
    // 0x8013EAF8: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x8013EAFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8013EB00: lwc1        $f10, 0x78($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8013EB04: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8013EB08: nop

    // 0x8013EB0C: bc1f        L_8013EB24
    if (!c1cs) {
        // 0x8013EB10: nop
    
            goto L_8013EB24;
    }
    // 0x8013EB10: nop

    // 0x8013EB14: jal         0x801493A4
    // 0x8013EB18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonEscapeCheckInterruptDash(rdram, ctx);
        goto after_3;
    // 0x8013EB18: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013EB1C: bnel        $v0, $zero, L_8013EC48
    if (ctx->r2 != 0) {
        // 0x8013EB20: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EC48;
    }
    goto skip_4;
    // 0x8013EB20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
L_8013EB24:
    // 0x8013EB24: jal         0x80148D0C
    // 0x8013EB28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x8013EB28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8013EB2C: beq         $v0, $zero, L_8013EC1C
    if (ctx->r2 == 0) {
        // 0x8013EB30: nop
    
            goto L_8013EC1C;
    }
    // 0x8013EB30: nop

    // 0x8013EB34: b           L_8013EC48
    // 0x8013EB38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013EC48;
    // 0x8013EB38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013EB3C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8013EB40:
    // 0x8013EB40: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8013EB44: lwc1        $f18, 0x78($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8013EB48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013EB4C: c.le.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl <= ctx->f16.fl;
    // 0x8013EB50: nop

    // 0x8013EB54: bc1f        L_8013EBEC
    if (!c1cs) {
        // 0x8013EB58: nop
    
            goto L_8013EBEC;
    }
    // 0x8013EB58: nop

    // 0x8013EB5C: jal         0x80151098
    // 0x8013EB60: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x8013EB60: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_5:
    // 0x8013EB64: bne         $v0, $zero, L_8013EC44
    if (ctx->r2 != 0) {
        // 0x8013EB68: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8013EC44;
    }
    // 0x8013EB68: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8013EB6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013EB70: jal         0x80149D80
    // 0x8013EB74: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftCommonCatchCheckInterruptDashRun(rdram, ctx);
        goto after_6;
    // 0x8013EB74: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_6:
    // 0x8013EB78: bne         $v0, $zero, L_8013EC44
    if (ctx->r2 != 0) {
        // 0x8013EB7C: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8013EC44;
    }
    // 0x8013EB7C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8013EB80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013EB84: jal         0x8014F69C
    // 0x8013EB88: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    ftCommonAttackDashCheckInterruptCommon(rdram, ctx);
        goto after_7;
    // 0x8013EB88: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_7:
    // 0x8013EB8C: bne         $v0, $zero, L_8013EC44
    if (ctx->r2 != 0) {
        // 0x8013EB90: lw          $v1, 0x24($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X24);
            goto L_8013EC44;
    }
    // 0x8013EB90: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8013EB94: lb          $t7, 0x1C2($v1)
    ctx->r15 = MEM_B(ctx->r3, 0X1C2);
    // 0x8013EB98: lw          $t8, 0x44($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X44);
    // 0x8013EB9C: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013EBA0: mflo        $t9
    ctx->r25 = lo;
    // 0x8013EBA4: bgezl       $t9, L_8013EBBC
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8013EBA8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8013EBBC;
    }
    goto skip_5;
    // 0x8013EBA8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    skip_5:
    // 0x8013EBAC: jal         0x8013ED64
    // 0x8013EBB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDashCheckInterruptCommon(rdram, ctx);
        goto after_8;
    // 0x8013EBB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8013EBB4: bne         $v0, $zero, L_8013EC44
    if (ctx->r2 != 0) {
        // 0x8013EBB8: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_8013EC44;
    }
    // 0x8013EBB8: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_8013EBBC:
    // 0x8013EBBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013EBC0: lwc1        $f6, 0x78($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X78);
    // 0x8013EBC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013EBC8: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8013EBCC: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8013EBD0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8013EBD4: jal         0x80148D2C
    // 0x8013EBD8: nop

    ftCommonGuardOnCheckInterruptDashRun(rdram, ctx);
        goto after_9;
    // 0x8013EBD8: nop

    after_9:
    // 0x8013EBDC: beq         $v0, $zero, L_8013EC1C
    if (ctx->r2 == 0) {
        // 0x8013EBE0: nop
    
            goto L_8013EC1C;
    }
    // 0x8013EBE0: nop

    // 0x8013EBE4: b           L_8013EC48
    // 0x8013EBE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8013EC48;
    // 0x8013EBE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013EBEC:
    // 0x8013EBEC: jal         0x80149CE0
    // 0x8013EBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_10;
    // 0x8013EBF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8013EBF4: bnel        $v0, $zero, L_8013EC48
    if (ctx->r2 != 0) {
        // 0x8013EBF8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EC48;
    }
    goto skip_6;
    // 0x8013EBF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8013EBFC: jal         0x8013ED64
    // 0x8013EC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDashCheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x8013EC00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8013EC04: bnel        $v0, $zero, L_8013EC48
    if (ctx->r2 != 0) {
        // 0x8013EC08: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EC48;
    }
    goto skip_7;
    // 0x8013EC08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8013EC0C: jal         0x80148D0C
    // 0x8013EC10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_12;
    // 0x8013EC10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8013EC14: bnel        $v0, $zero, L_8013EC48
    if (ctx->r2 != 0) {
        // 0x8013EC18: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EC48;
    }
    goto skip_8;
    // 0x8013EC18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
L_8013EC1C:
    // 0x8013EC1C: jal         0x8014E764
    // 0x8013EC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_13;
    // 0x8013EC20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8013EC24: bnel        $v0, $zero, L_8013EC48
    if (ctx->r2 != 0) {
        // 0x8013EC28: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EC48;
    }
    goto skip_9;
    // 0x8013EC28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x8013EC2C: jal         0x8013F598
    // 0x8013EC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonKneeBendCheckInterruptRun(rdram, ctx);
        goto after_14;
    // 0x8013EC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8013EC34: bnel        $v0, $zero, L_8013EC48
    if (ctx->r2 != 0) {
        // 0x8013EC38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EC48;
    }
    goto skip_10;
    // 0x8013EC38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x8013EC3C: jal         0x8013EF2C
    // 0x8013EC40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonRunCheckInterruptDash(rdram, ctx);
        goto after_15;
    // 0x8013EC40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_8013EC44:
    // 0x8013EC44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013EC48:
    // 0x8013EC48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013EC4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013EC50: jr          $ra
    // 0x8013EC54: nop

    return;
    // 0x8013EC54: nop

;}
RECOMP_FUNC void ftKirbySpecialNThrowProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162804: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162808: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016280C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162810: jal         0x800DDE84
    // 0x80162814: addiu       $a1, $a1, 0x2CE0
    ctx->r5 = ADD32(ctx->r5, 0X2CE0);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80162814: addiu       $a1, $a1, 0x2CE0
    ctx->r5 = ADD32(ctx->r5, 0X2CE0);
    after_0:
    // 0x80162818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016281C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162820: jr          $ra
    // 0x80162824: nop

    return;
    // 0x80162824: nop

;}
RECOMP_FUNC void ftNessSpecialHiStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153FF0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80153FF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80153FF8: jal         0x80153FCC
    // 0x80153FFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftNessSpecialHiInitStatusVars(rdram, ctx);
        goto after_0;
    // 0x80153FFC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80154000: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80154004: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x80154008: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015400C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80154010: jal         0x800E6F24
    // 0x80154014: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80154014: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x80154018: jal         0x800E0830
    // 0x8015401C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015401C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80154020: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80154024: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80154028: jr          $ra
    // 0x8015402C: nop

    return;
    // 0x8015402C: nop

;}
RECOMP_FUNC void syAudioGetSettingsUpdated(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002103C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80021040: jr          $ra
    // 0x80021044: lw          $v0, -0x34E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34E4);
    return;
    // 0x80021044: lw          $v0, -0x34E4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X34E4);
;}
RECOMP_FUNC void func_ovl8_803833A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803833A0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803833A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803833A8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803833AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803833B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803833B4: bne         $a0, $zero, L_803833CC
    if (ctx->r4 != 0) {
        // 0x803833B8: sw          $a2, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r6;
            goto L_803833CC;
    }
    // 0x803833B8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x803833BC: jal         0x803717A0
    // 0x803833C0: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803833C0: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x803833C4: beq         $v0, $zero, L_8038343C
    if (ctx->r2 == 0) {
        // 0x803833C8: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8038343C;
    }
    // 0x803833C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_803833CC:
    // 0x803833CC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x803833D0: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x803833D4: addiu       $a1, $s0, 0xB4
    ctx->r5 = ADD32(ctx->r16, 0XB4);
    // 0x803833D8: bnel        $t6, $zero, L_803833FC
    if (ctx->r14 != 0) {
        // 0x803833DC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_803833FC;
    }
    goto skip_0;
    // 0x803833DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x803833E0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803833E4: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x803833E8: jal         0x803717E0
    // 0x803833EC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803833EC: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_1:
    // 0x803833F0: jal         0x8037C2D0
    // 0x803833F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803833F4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x803833F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_803833FC:
    // 0x803833FC: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80383400: jal         0x803733AC
    // 0x80383404: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    func_ovl8_803733AC(rdram, ctx);
        goto after_3;
    // 0x80383404: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x80383408: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8038340C: addiu       $t7, $t7, -0x35F0
    ctx->r15 = ADD32(ctx->r15, -0X35F0);
    // 0x80383410: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80383414: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80383418: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038341C: addiu       $t8, $t8, -0x34A8
    ctx->r24 = ADD32(ctx->r24, -0X34A8);
    // 0x80383420: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80383424: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80383428: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8038342C: addiu       $t0, $t0, -0x3350
    ctx->r8 = ADD32(ctx->r8, -0X3350);
    // 0x80383430: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80383434: jal         0x80383B58
    // 0x80383438: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    func_ovl8_80383B58(rdram, ctx);
        goto after_4;
    // 0x80383438: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    after_4:
L_8038343C:
    // 0x8038343C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80383440: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80383444: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80383448: jr          $ra
    // 0x8038344C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8038344C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftBossWalkWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159A30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159A34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159A38: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80159A3C: jal         0x800D9480
    // 0x80159A40: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159A40: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    after_0:
    // 0x80159A44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159A48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80159A4C: jr          $ra
    // 0x80159A50: nop

    return;
    // 0x80159A50: nop

;}
RECOMP_FUNC void gmCameraGetClampDimensionsMax(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010C200: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C204: lwc1        $f4, 0x14F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X14F0);
    // 0x8010C208: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010C20C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010C210: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C214: lwc1        $f10, 0xBF8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XBF8);
    // 0x8010C218: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010C21C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010C220: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8010C224: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8010C228: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010C22C: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x8010C230: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    // 0x8010C234: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8010C238: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8010C23C: jal         0x800C793C
    // 0x8010C240: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    lbCommonTan(rdram, ctx);
        goto after_0;
    // 0x8010C240: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_0:
    // 0x8010C244: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010C248: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C24C: lwc1        $f4, 0x14F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X14F0);
    // 0x8010C250: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x8010C254: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8010C258: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8010C25C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C260: lwc1        $f10, 0xBFC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0XBFC);
    // 0x8010C264: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8010C268: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8010C26C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8010C270: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8010C274: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    // 0x8010C278: jal         0x800C793C
    // 0x8010C27C: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    lbCommonTan(rdram, ctx);
        goto after_1;
    // 0x8010C27C: div.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    after_1:
    // 0x8010C280: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010C284: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x8010C288: lw          $t6, 0x38($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X38);
    // 0x8010C28C: lw          $t7, 0x3C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X3C);
    // 0x8010C290: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8010C294: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010C298: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8010C29C: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8010C2A0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010C2A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C2A8: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x8010C2AC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8010C2B0: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8010C2B4: div.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8010C2B8: div.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f18.fl);
    // 0x8010C2BC: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x8010C2C0: nop

    // 0x8010C2C4: bc1fl       L_8010C2D8
    if (!c1cs) {
        // 0x8010C2C8: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_8010C2D8;
    }
    goto skip_0;
    // 0x8010C2C8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    skip_0:
    // 0x8010C2CC: b           L_8010C2D8
    // 0x8010C2D0: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_8010C2D8;
    // 0x8010C2D0: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x8010C2D4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8010C2D8:
    // 0x8010C2D8: lwc1        $f2, 0xC00($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XC00);
    // 0x8010C2DC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010C2E0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8010C2E4: nop

    // 0x8010C2E8: bc1f        L_8010C2F4
    if (!c1cs) {
        // 0x8010C2EC: nop
    
            goto L_8010C2F4;
    }
    // 0x8010C2EC: nop

    // 0x8010C2F0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8010C2F4:
    // 0x8010C2F4: lwc1        $f2, 0xC04($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0XC04);
    // 0x8010C2F8: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8010C2FC: nop

    // 0x8010C300: bc1fl       L_8010C310
    if (!c1cs) {
        // 0x8010C304: swc1        $f0, 0x0($t8)
        MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
            goto L_8010C310;
    }
    goto skip_1;
    // 0x8010C304: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    skip_1:
    // 0x8010C308: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8010C30C: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
L_8010C310:
    // 0x8010C310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010C314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010C318: jr          $ra
    // 0x8010C31C: nop

    return;
    // 0x8010C31C: nop

;}
RECOMP_FUNC void ftCommonYoshiEggMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014C958: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014C95C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014C960: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014C964: lw          $t6, 0xB18($v1)
    ctx->r14 = MEM_W(ctx->r3, 0XB18);
    // 0x8014C968: bnel        $t6, $zero, L_8014C994
    if (ctx->r14 != 0) {
        // 0x8014C96C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014C994;
    }
    goto skip_0;
    // 0x8014C96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014C970: jal         0x80103060
    // 0x8014C974: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerYoshiEggLayMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8014C974: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014C978: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014C97C: beq         $v0, $zero, L_8014C990
    if (ctx->r2 == 0) {
        // 0x8014C980: sw          $v0, 0xB18($v1)
        MEM_W(0XB18, ctx->r3) = ctx->r2;
            goto L_8014C990;
    }
    // 0x8014C980: sw          $v0, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->r2;
    // 0x8014C984: lbu         $t8, 0x18F($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18F);
    // 0x8014C988: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8014C98C: sb          $t9, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r25;
L_8014C990:
    // 0x8014C990: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014C994:
    // 0x8014C994: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014C998: jr          $ra
    // 0x8014C99C: nop

    return;
    // 0x8014C99C: nop

;}
RECOMP_FUNC void ftKirbySpecialAirHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161270: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80161274: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161278: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016127C: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x80161280: addiu       $t6, $t6, 0x1194
    ctx->r14 = ADD32(ctx->r14, 0X1194);
    // 0x80161284: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x80161288: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8016128C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80161290: addiu       $a1, $zero, 0x102
    ctx->r5 = ADD32(0, 0X102);
    // 0x80161294: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80161298: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8016129C: jal         0x800E6F24
    // 0x801612A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801612A0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801612A4: jal         0x800E0830
    // 0x801612A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x801612A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x801612AC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801612B0: lui         $t7, 0x800F
    ctx->r15 = S32(0X800F << 16);
    // 0x801612B4: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x801612B8: addiu       $t7, $t7, -0x6374
    ctx->r15 = ADD32(ctx->r15, -0X6374);
    // 0x801612BC: addiu       $t8, $t8, -0x633C
    ctx->r24 = ADD32(ctx->r24, -0X633C);
    // 0x801612C0: sw          $t7, 0xA04($v0)
    MEM_W(0XA04, ctx->r2) = ctx->r15;
    // 0x801612C4: sw          $t8, 0xA08($v0)
    MEM_W(0XA08, ctx->r2) = ctx->r24;
    // 0x801612C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801612CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801612D0: jr          $ra
    // 0x801612D4: nop

    return;
    // 0x801612D4: nop

;}
RECOMP_FUNC void mpProcessRunRWallCollision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DAE6C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800DAE70: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800DAE74: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800DAE78: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800DAE7C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800DAE80: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800DAE84: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800DAE88: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800DAE8C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800DAE90: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800DAE94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800DAE98: sw          $a0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r4;
    // 0x800DAE9C: jal         0x800D957C
    // 0x800DAEA0: lw          $s6, 0x0($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X0);
    mpProcessSetLastWallCollideLeft(rdram, ctx);
        goto after_0;
    // 0x800DAEA0: lw          $s6, 0x0($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X0);
    after_0:
    // 0x800DAEA4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800DAEA8: lw          $t7, 0xDE0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XDE0);
    // 0x800DAEAC: lw          $s0, 0xA8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XA8);
    // 0x800DAEB0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x800DAEB4: blez        $t7, L_800DB258
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800DAEB8: addiu       $s0, $s0, 0x38
        ctx->r16 = ADD32(ctx->r16, 0X38);
            goto L_800DB258;
    }
    // 0x800DAEB8: addiu       $s0, $s0, 0x38
    ctx->r16 = ADD32(ctx->r16, 0X38);
    // 0x800DAEBC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800DAEC0: addiu       $v0, $v0, 0xDE8
    ctx->r2 = ADD32(ctx->r2, 0XDE8);
    // 0x800DAEC4: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800DAEC8: addiu       $s7, $s7, 0xDFC
    ctx->r23 = ADD32(ctx->r23, 0XDFC);
    // 0x800DAECC: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800DAED0: addiu       $fp, $sp, 0x6C
    ctx->r30 = ADD32(ctx->r29, 0X6C);
    // 0x800DAED4: addiu       $s5, $sp, 0x7C
    ctx->r21 = ADD32(ctx->r29, 0X7C);
    // 0x800DAED8: addiu       $s4, $sp, 0x88
    ctx->r20 = ADD32(ctx->r29, 0X88);
L_800DAEDC:
    // 0x800DAEDC: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800DAEE0: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DAEE4: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x800DAEE8: jal         0x800F4690
    // 0x800DAEEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mpCollisionGetRWallEdgeU(rdram, ctx);
        goto after_1;
    // 0x800DAEEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x800DAEF0: lwc1        $f6, 0x4($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DAEF4: lwc1        $f8, 0x8($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DAEF8: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800DAEFC: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DAF00: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DAF04: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DAF08: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800DAF0C: nop

    // 0x800DAF10: bc1f        L_800DAF60
    if (!c1cs) {
        // 0x800DAF14: nop
    
            goto L_800DAF60;
    }
    // 0x800DAF14: nop

    // 0x800DAF18: lwc1        $f16, 0x0($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DAF1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DAF20: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DAF24: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DAF28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DAF2C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DAF30: bc1fl       L_800DB234
    if (!c1cs) {
        // 0x800DAF34: lw          $v0, 0x78($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X78);
            goto L_800DB234;
    }
    goto skip_0;
    // 0x800DAF34: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    skip_0:
    // 0x800DAF38: jal         0x800F41C0
    // 0x800DAF3C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_2;
    // 0x800DAF3C: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_2:
    // 0x800DAF40: beq         $v0, $zero, L_800DB230
    if (ctx->r2 == 0) {
        // 0x800DAF44: lwc1        $f12, 0x94($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
            goto L_800DB230;
    }
    // 0x800DAF44: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DAF48: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DAF4C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DAF50: jal         0x800D95A4
    // 0x800DAF54: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_3;
    // 0x800DAF54: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_3:
    // 0x800DAF58: b           L_800DB234
    // 0x800DAF5C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
        goto L_800DB234;
    // 0x800DAF5C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
L_800DAF60:
    // 0x800DAF60: jal         0x800F46B0
    // 0x800DAF64: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    mpCollisionGetRWallEdgeD(rdram, ctx);
        goto after_4;
    // 0x800DAF64: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    after_4:
    // 0x800DAF68: lwc1        $f6, 0x4($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DAF6C: lwc1        $f8, 0x0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DAF70: lwc1        $f10, 0x98($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X98);
    // 0x800DAF74: lwc1        $f18, 0x94($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DAF78: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800DAF7C: c.lt.s      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.fl < ctx->f10.fl;
    // 0x800DAF80: nop

    // 0x800DAF84: bc1fl       L_800DAFD8
    if (!c1cs) {
        // 0x800DAF88: lwc1        $f6, 0x0($s6)
        ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DAFD8;
    }
    goto skip_1;
    // 0x800DAF88: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
    skip_1:
    // 0x800DAF8C: lwc1        $f16, 0x0($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DAF90: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DAF94: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DAF98: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800DAF9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DAFA0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DAFA4: bc1fl       L_800DB234
    if (!c1cs) {
        // 0x800DAFA8: lw          $v0, 0x78($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X78);
            goto L_800DB234;
    }
    goto skip_2;
    // 0x800DAFA8: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    skip_2:
    // 0x800DAFAC: jal         0x800F41C0
    // 0x800DAFB0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_5;
    // 0x800DAFB0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_5:
    // 0x800DAFB4: beq         $v0, $zero, L_800DB230
    if (ctx->r2 == 0) {
        // 0x800DAFB8: lwc1        $f12, 0x94($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
            goto L_800DB230;
    }
    // 0x800DAFB8: lwc1        $f12, 0x94($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800DAFBC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DAFC0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DAFC4: jal         0x800D95A4
    // 0x800DAFC8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_6;
    // 0x800DAFC8: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_6:
    // 0x800DAFCC: b           L_800DB234
    // 0x800DAFD0: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
        goto L_800DB234;
    // 0x800DAFD0: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800DAFD4: lwc1        $f6, 0x0($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X0);
L_800DAFD8:
    // 0x800DAFD8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DAFDC: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DAFE0: swc1        $f6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f6.u32l;
    // 0x800DAFE4: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DAFE8: lwc1        $f8, 0x4($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DAFEC: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DAFF0: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DAFF4: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DAFF8: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DAFFC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800DB000: jal         0x800F41C0
    // 0x800DB004: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_7;
    // 0x800DB004: swc1        $f10, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f10.u32l;
    after_7:
    // 0x800DB008: beq         $v0, $zero, L_800DB03C
    if (ctx->r2 == 0) {
        // 0x800DB00C: lwc1        $f18, 0x64($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DB03C;
    }
    // 0x800DB00C: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DB010: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DB014: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DB018: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DB01C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DB020: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DB024: c.lt.s      $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f6.fl < ctx->f12.fl;
    // 0x800DB028: nop

    // 0x800DB02C: bc1fl       L_800DB040
    if (!c1cs) {
        // 0x800DB030: lwc1        $f8, 0x0($s6)
        ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DB040;
    }
    goto skip_3;
    // 0x800DB030: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    skip_3:
    // 0x800DB034: jal         0x800D95A4
    // 0x800DB038: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_8;
    // 0x800DB038: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_8:
L_800DB03C:
    // 0x800DB03C: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
L_800DB040:
    // 0x800DB040: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DB044: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DB048: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DB04C: sub.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800DB050: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DB054: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DB058: swc1        $f10, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f10.u32l;
    // 0x800DB05C: lwc1        $f18, 0x4($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DB060: lwc1        $f16, 0x4($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DB064: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DB068: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800DB06C: jal         0x800F41C0
    // 0x800DB070: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_9;
    // 0x800DB070: swc1        $f6, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f6.u32l;
    after_9:
    // 0x800DB074: beq         $v0, $zero, L_800DB0A8
    if (ctx->r2 == 0) {
        // 0x800DB078: lwc1        $f4, 0x64($sp)
        ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DB0A8;
    }
    // 0x800DB078: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DB07C: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DB080: lwc1        $f10, 0x0($s7)
    ctx->f10.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DB084: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DB088: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800DB08C: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DB090: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x800DB094: nop

    // 0x800DB098: bc1fl       L_800DB0AC
    if (!c1cs) {
        // 0x800DB09C: lwc1        $f16, 0x0($s6)
        ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
            goto L_800DB0AC;
    }
    goto skip_4;
    // 0x800DB09C: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
    skip_4:
    // 0x800DB0A0: jal         0x800D95A4
    // 0x800DB0A4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_10;
    // 0x800DB0A4: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_10:
L_800DB0A8:
    // 0x800DB0A8: lwc1        $f16, 0x0($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0X0);
L_800DB0AC:
    // 0x800DB0AC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DB0B0: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x800DB0B4: swc1        $f16, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f16.u32l;
    // 0x800DB0B8: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DB0BC: lwc1        $f18, 0x4($s6)
    ctx->f18.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DB0C0: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    // 0x800DB0C4: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x800DB0C8: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800DB0CC: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DB0D0: jal         0x800F41C0
    // 0x800DB0D4: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_11;
    // 0x800DB0D4: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
    after_11:
    // 0x800DB0D8: beq         $v0, $zero, L_800DB10C
    if (ctx->r2 == 0) {
        // 0x800DB0DC: lwc1        $f10, 0x64($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DB10C;
    }
    // 0x800DB0DC: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DB0E0: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DB0E4: lwc1        $f16, 0x0($s7)
    ctx->f16.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DB0E8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DB0EC: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800DB0F0: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DB0F4: c.lt.s      $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f16.fl < ctx->f12.fl;
    // 0x800DB0F8: nop

    // 0x800DB0FC: bc1f        L_800DB10C
    if (!c1cs) {
        // 0x800DB100: nop
    
            goto L_800DB10C;
    }
    // 0x800DB100: nop

    // 0x800DB104: jal         0x800D95A4
    // 0x800DB108: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_12;
    // 0x800DB108: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_12:
L_800DB10C:
    // 0x800DB10C: jal         0x800FA518
    // 0x800DB110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mpCollisionGetVertexCountLineID(rdram, ctx);
        goto after_13;
    // 0x800DB110: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_13:
    // 0x800DB114: blez        $v0, L_800DB230
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800DB118: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_800DB230;
    }
    // 0x800DB118: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x800DB11C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800DB120:
    // 0x800DB120: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800DB124: jal         0x800FA5E8
    // 0x800DB128: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    mpCollisionGetVertexPositionID(rdram, ctx);
        goto after_14;
    // 0x800DB128: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_14:
    // 0x800DB12C: lwc1        $f2, 0x4($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X4);
    // 0x800DB130: lwc1        $f12, 0x8($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800DB134: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800DB138: add.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800DB13C: c.le.s      $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f14.fl <= ctx->f18.fl;
    // 0x800DB140: nop

    // 0x800DB144: bc1fl       L_800DB18C
    if (!c1cs) {
        // 0x800DB148: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_800DB18C;
    }
    goto skip_5;
    // 0x800DB148: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_5:
    // 0x800DB14C: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    // 0x800DB150: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800DB154: c.le.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl <= ctx->f6.fl;
    // 0x800DB158: nop

    // 0x800DB15C: bc1fl       L_800DB18C
    if (!c1cs) {
        // 0x800DB160: lwc1        $f0, 0x4($s0)
        ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
            goto L_800DB18C;
    }
    goto skip_6;
    // 0x800DB160: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
    skip_6:
    // 0x800DB164: sub.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x800DB168: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DB16C: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800DB170: sub.s       $f16, $f0, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800DB174: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800DB178: div.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800DB17C: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800DB180: b           L_800DB1DC
    // 0x800DB184: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
        goto L_800DB1DC;
    // 0x800DB184: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
    // 0x800DB188: lwc1        $f0, 0x4($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X4);
L_800DB18C:
    // 0x800DB18C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800DB190: add.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800DB194: c.le.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl <= ctx->f4.fl;
    // 0x800DB198: nop

    // 0x800DB19C: bc1fl       L_800DB224
    if (!c1cs) {
        // 0x800DB1A0: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DB224;
    }
    goto skip_7;
    // 0x800DB1A0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_7:
    // 0x800DB1A4: lwc1        $f12, 0x0($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800DB1A8: add.s       $f14, $f2, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x800DB1AC: c.le.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl <= ctx->f14.fl;
    // 0x800DB1B0: nop

    // 0x800DB1B4: bc1fl       L_800DB224
    if (!c1cs) {
        // 0x800DB1B8: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DB224;
    }
    goto skip_8;
    // 0x800DB1B8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_8:
    // 0x800DB1BC: sub.s       $f16, $f14, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f14.fl - ctx->f4.fl;
    // 0x800DB1C0: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800DB1C4: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800DB1C8: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800DB1CC: mul.s       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800DB1D0: div.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800DB1D4: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800DB1D8: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
L_800DB1DC:
    // 0x800DB1DC: lwc1        $f6, 0x0($s7)
    ctx->f6.u32l = MEM_W(ctx->r23, 0X0);
    // 0x800DB1E0: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DB1E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800DB1E8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x800DB1EC: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x800DB1F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800DB1F4: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800DB1F8: bc1fl       L_800DB224
    if (!c1cs) {
        // 0x800DB1FC: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800DB224;
    }
    goto skip_9;
    // 0x800DB1FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_9:
    // 0x800DB200: jal         0x800F41C0
    // 0x800DB204: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    mpCollisionGetLRCommonRWall(rdram, ctx);
        goto after_15;
    // 0x800DB204: sw          $s4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r20;
    after_15:
    // 0x800DB208: beq         $v0, $zero, L_800DB220
    if (ctx->r2 == 0) {
        // 0x800DB20C: lwc1        $f12, 0x64($sp)
        ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
            goto L_800DB220;
    }
    // 0x800DB20C: lwc1        $f12, 0x64($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DB210: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800DB214: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800DB218: jal         0x800D95A4
    // 0x800DB21C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    mpProcessSetLastWallCollideStats(rdram, ctx);
        goto after_16;
    // 0x800DB21C: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_16:
L_800DB220:
    // 0x800DB220: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800DB224:
    // 0x800DB224: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x800DB228: bnel        $at, $zero, L_800DB120
    if (ctx->r1 != 0) {
        // 0x800DB22C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800DB120;
    }
    goto skip_10;
    // 0x800DB22C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_10:
L_800DB230:
    // 0x800DB230: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
L_800DB234:
    // 0x800DB234: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800DB238: lw          $t0, 0xDE0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XDE0);
    // 0x800DB23C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800DB240: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800DB244: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800DB248: addiu       $t9, $t8, 0x4
    ctx->r25 = ADD32(ctx->r24, 0X4);
    // 0x800DB24C: sw          $t9, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r25;
    // 0x800DB250: bne         $at, $zero, L_800DAEDC
    if (ctx->r1 != 0) {
        // 0x800DB254: sw          $v0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r2;
            goto L_800DAEDC;
    }
    // 0x800DB254: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
L_800DB258:
    // 0x800DB258: lw          $t1, 0xA8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XA8);
    // 0x800DB25C: addiu       $a0, $sp, 0x64
    ctx->r4 = ADD32(ctx->r29, 0X64);
    // 0x800DB260: addiu       $a1, $t1, 0xB4
    ctx->r5 = ADD32(ctx->r9, 0XB4);
    // 0x800DB264: addiu       $a2, $t1, 0xB8
    ctx->r6 = ADD32(ctx->r9, 0XB8);
    // 0x800DB268: jal         0x800D95E0
    // 0x800DB26C: addiu       $a3, $t1, 0xBC
    ctx->r7 = ADD32(ctx->r9, 0XBC);
    mpProcessGetLastWallCollideStats(rdram, ctx);
        goto after_17;
    // 0x800DB26C: addiu       $a3, $t1, 0xBC
    ctx->r7 = ADD32(ctx->r9, 0XBC);
    after_17:
    // 0x800DB270: lwc1        $f8, 0x0($s6)
    ctx->f8.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800DB274: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x800DB278: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800DB27C: nop

    // 0x800DB280: bc1fl       L_800DB290
    if (!c1cs) {
        // 0x800DB284: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800DB290;
    }
    goto skip_11;
    // 0x800DB284: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_11:
    // 0x800DB288: swc1        $f10, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->f10.u32l;
    // 0x800DB28C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800DB290:
    // 0x800DB290: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800DB294: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800DB298: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800DB29C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800DB2A0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800DB2A4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800DB2A8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800DB2AC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800DB2B0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800DB2B4: jr          $ra
    // 0x800DB2B8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800DB2B8: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void mnPlayers1PTrainingUpdateFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133E30: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80133E34: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80133E38: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80133E3C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80133E40: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133E44: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x80133E48: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80133E4C: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80133E50: lw          $a1, 0x8($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X8);
    // 0x80133E54: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80133E58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133E5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80133E60: beq         $a1, $zero, L_80133E90
    if (ctx->r5 == 0) {
        // 0x80133E64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80133E90;
    }
    // 0x80133E64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80133E68: lw          $t8, 0x48($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X48);
    // 0x80133E6C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80133E70: bne         $t8, $at, L_80133E90
    if (ctx->r24 != ctx->r1) {
        // 0x80133E74: nop
    
            goto L_80133E90;
    }
    // 0x80133E74: nop

    // 0x80133E78: lw          $t9, 0x54($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X54);
    // 0x80133E7C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133E80: bne         $t9, $zero, L_80133E90
    if (ctx->r25 != 0) {
        // 0x80133E84: nop
    
            goto L_80133E90;
    }
    // 0x80133E84: nop

    // 0x80133E88: sw          $t0, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->r8;
    // 0x80133E8C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80133E90:
    // 0x80133E90: bne         $v0, $zero, L_80133EC8
    if (ctx->r2 != 0) {
        // 0x80133E94: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80133EC8;
    }
    // 0x80133E94: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80133E98: lw          $a0, 0x48($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X48);
    // 0x80133E9C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80133EA0: jal         0x801335F0
    // 0x80133EA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    mnPlayers1PTrainingGetFreeCostume(rdram, ctx);
        goto after_0;
    // 0x80133EA4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80133EA8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80133EAC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80133EB0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80133EB4: lw          $a0, 0x8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8);
    // 0x80133EB8: jal         0x801337BC
    // 0x80133EBC: lw          $a2, 0x48($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X48);
    mnPlayers1PTrainingMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80133EBC: lw          $a2, 0x48($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X48);
    after_1:
    // 0x80133EC0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80133EC4: sw          $zero, 0x88($v1)
    MEM_W(0X88, ctx->r3) = 0;
L_80133EC8:
    // 0x80133EC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133ECC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80133ED0: jr          $ra
    // 0x80133ED4: nop

    return;
    // 0x80133ED4: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeTissues(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132130: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132138: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013213C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132140: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132144: jal         0x80009968
    // 0x80132148: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132148: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013214C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132150: lw          $t6, 0x50B0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50B0);
    // 0x80132154: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80132158: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013215C: addiu       $t7, $t7, -0x3970
    ctx->r15 = ADD32(ctx->r15, -0X3970);
    // 0x80132160: sw          $v0, 0x4D2C($at)
    MEM_W(0X4D2C, ctx->r1) = ctx->r2;
    // 0x80132164: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132168: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013216C: jal         0x800092D0
    // 0x80132170: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132170: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80132174: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80132178: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013217C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x80132180: jal         0x80008CC0
    // 0x80132184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80132184: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80132188: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8013218C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80132190: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80132194: addiu       $a1, $a1, 0x3E68
    ctx->r5 = ADD32(ctx->r5, 0X3E68);
    // 0x80132198: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8013219C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801321A0: jal         0x80009DF4
    // 0x801321A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x801321A4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x801321A8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801321AC: lw          $t9, 0x50B0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X50B0);
    // 0x801321B0: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x801321B4: addiu       $t0, $t0, -0x377C
    ctx->r8 = ADD32(ctx->r8, -0X377C);
    // 0x801321B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801321BC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801321C0: jal         0x8000BD1C
    // 0x801321C4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_4;
    // 0x801321C4: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
    // 0x801321C8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801321CC: addiu       $a1, $a1, 0x20FC
    ctx->r5 = ADD32(ctx->r5, 0X20FC);
    // 0x801321D0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801321D4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801321D8: jal         0x80008188
    // 0x801321DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x801321DC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x801321E0: jal         0x8000DF34
    // 0x801321E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    gcPlayAnimAll(rdram, ctx);
        goto after_6;
    // 0x801321E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x801321E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801321EC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801321F0: jr          $ra
    // 0x801321F4: nop

    return;
    // 0x801321F4: nop

;}
RECOMP_FUNC void sc1PGameBossDefeatInterfaceProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F5EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018F5F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F5F4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018F5F8: addiu       $a1, $a1, -0xA8C
    ctx->r5 = ADD32(ctx->r5, -0XA8C);
    // 0x8018F5FC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018F600: jal         0x8000AEF0
    // 0x8018F604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcFuncGObjByLink(rdram, ctx);
        goto after_0;
    // 0x8018F604: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8018F608: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018F60C: addiu       $a1, $a1, -0xA54
    ctx->r5 = ADD32(ctx->r5, -0XA54);
    // 0x8018F610: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018F614: jal         0x8000AEF0
    // 0x8018F618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcFuncGObjByLink(rdram, ctx);
        goto after_1;
    // 0x8018F618: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8018F61C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018F620: addiu       $a1, $a1, -0xA34
    ctx->r5 = ADD32(ctx->r5, -0XA34);
    // 0x8018F624: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018F628: jal         0x8000AEF0
    // 0x8018F62C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcFuncGObjByLink(rdram, ctx);
        goto after_2;
    // 0x8018F62C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x8018F630: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x8018F634: addiu       $a0, $a0, 0x3638
    ctx->r4 = ADD32(ctx->r4, 0X3638);
    // 0x8018F638: jal         0x8000AF58
    // 0x8018F63C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    gcFuncGObjAll(rdram, ctx);
        goto after_3;
    // 0x8018F63C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x8018F640: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x8018F644: addiu       $a1, $a1, 0x366C
    ctx->r5 = ADD32(ctx->r5, 0X366C);
    // 0x8018F648: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8018F64C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018F650: jal         0x8000AEF0
    // 0x8018F654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcFuncGObjByLink(rdram, ctx);
        goto after_4;
    // 0x8018F654: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x8018F658: jal         0x80115834
    // 0x8018F65C: nop

    gmRumbleResumeProcessAll(rdram, ctx);
        goto after_5;
    // 0x8018F65C: nop

    after_5:
    // 0x8018F660: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8018F664: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F668: jal         0x8000AEF0
    // 0x8018F66C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcFuncGObjByLink(rdram, ctx);
        goto after_6;
    // 0x8018F66C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8018F670: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8018F674: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F678: jal         0x8000AEF0
    // 0x8018F67C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcFuncGObjByLink(rdram, ctx);
        goto after_7;
    // 0x8018F67C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8018F680: jal         0x801910B0
    // 0x8018F684: nop

    func_ovl65_801910B0(rdram, ctx);
        goto after_8;
    // 0x8018F684: nop

    after_8:
    // 0x8018F688: jal         0x800266A0
    // 0x8018F68C: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_9;
    // 0x8018F68C: nop

    after_9:
    // 0x8018F690: jal         0x80020A74
    // 0x8018F694: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_10;
    // 0x8018F694: nop

    after_10:
    // 0x8018F698: jal         0x8011379C
    // 0x8018F69C: nop

    ifCommonBattleEndPlaySoundQueue(rdram, ctx);
        goto after_11;
    // 0x8018F69C: nop

    after_11:
    // 0x8018F6A0: jal         0x800269C0
    // 0x8018F6A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    func_800269C0_275C0(rdram, ctx);
        goto after_12;
    // 0x8018F6A4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x8018F6A8: jal         0x800269C0
    // 0x8018F6AC: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    func_800269C0_275C0(rdram, ctx);
        goto after_13;
    // 0x8018F6AC: addiu       $a0, $zero, 0x1EC
    ctx->r4 = ADD32(0, 0X1EC);
    after_13:
    // 0x8018F6B0: jal         0x800269C0
    // 0x8018F6B4: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    func_800269C0_275C0(rdram, ctx);
        goto after_14;
    // 0x8018F6B4: addiu       $a0, $zero, 0xAC
    ctx->r4 = ADD32(0, 0XAC);
    after_14:
    // 0x8018F6B8: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018F6BC: addiu       $v0, $v0, -0x1230
    ctx->r2 = ADD32(ctx->r2, -0X1230);
    // 0x8018F6C0: lhu         $t6, 0x28($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X28);
    // 0x8018F6C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018F6C8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018F6CC: sh          $t6, 0x2FDC($at)
    MEM_H(0X2FDC, ctx->r1) = ctx->r14;
    // 0x8018F6D0: sh          $zero, 0x28($v0)
    MEM_H(0X28, ctx->r2) = 0;
    // 0x8018F6D4: jr          $ra
    // 0x8018F6D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8018F6D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mvOpeningLinkMakePosedWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DCD0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DCD4: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DCD8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DCDC: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DCE0: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018DCE4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DCE8: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8018DCEC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DCF0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DCF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DCF8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DCFC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DD00: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DD04: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DD08: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DD0C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DD10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DD14: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DD18: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DD1C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DD20: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DD24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DD28: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DD2C: jal         0x8000B93C
    // 0x8018DD30: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DD30: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DD34: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DD38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DD3C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DD40: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8018DD44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DD48: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DD4C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DD50: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DD54: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DD58: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8018DD5C: jal         0x80007080
    // 0x8018DD60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DD60: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DD64: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8018DD68: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8018DD6C: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x8018DD70: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DD74: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DD78: jr          $ra
    // 0x8018DD7C: nop

    return;
    // 0x8018DD7C: nop

;}
RECOMP_FUNC void func_ovl0_800D4C90(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4C8C: jr          $ra
    // 0x800D4C90: nop

    return;
    // 0x800D4C90: nop

;}

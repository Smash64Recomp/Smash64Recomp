#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mpCollisionGetFCCommonFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3DD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F3DDC: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800F3DE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F3DE4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800F3DE8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800F3DEC: jal         0x800F3A78
    // 0x800F3DF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mpCollisionGetFCCommon(rdram, ctx);
        goto after_0;
    // 0x800F3DF0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800F3DF4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F3DF8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F3DFC: jr          $ra
    // 0x800F3E00: nop

    return;
    // 0x800F3E00: nop

;}
RECOMP_FUNC void func_ovl8_8037726C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037726C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80377270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80377274: jal         0x80375BB4
    // 0x80377278: nop

    func_ovl8_80375BB4(rdram, ctx);
        goto after_0;
    // 0x80377278: nop

    after_0:
    // 0x8037727C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80377280: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80377284: jr          $ra
    // 0x80377288: nop

    return;
    // 0x80377288: nop

;}
RECOMP_FUNC void func_ovl8_8037495C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037495C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374960: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374964: jal         0x80372E98
    // 0x80374968: nop

    func_ovl8_80372E98(rdram, ctx);
        goto after_0;
    // 0x80374968: nop

    after_0:
    // 0x8037496C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374974: jr          $ra
    // 0x80374978: nop

    return;
    // 0x80374978: nop

;}
RECOMP_FUNC void ftCommonGuardPassCheckInterruptGuard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141F8C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80141F90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80141F94: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80141F98: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80141F9C: jal         0x80141E60
    // 0x80141FA0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftCommonPassCheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x80141FA0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80141FA4: beq         $v0, $zero, L_80141FD0
    if (ctx->r2 == 0) {
        // 0x80141FA8: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80141FD0;
    }
    // 0x80141FA8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80141FAC: lhu         $t7, 0x1BC($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1BC);
    // 0x80141FB0: lhu         $t8, 0x1B8($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X1B8);
    // 0x80141FB4: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80141FB8: beql        $t9, $zero, L_80141FD4
    if (ctx->r25 == 0) {
        // 0x80141FBC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80141FD4;
    }
    goto skip_0;
    // 0x80141FBC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80141FC0: jal         0x80141E38
    // 0x80141FC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftCommonGuardPassSetStatus(rdram, ctx);
        goto after_1;
    // 0x80141FC4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80141FC8: b           L_80141FD4
    // 0x80141FCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80141FD4;
    // 0x80141FCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80141FD0:
    // 0x80141FD0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80141FD4:
    // 0x80141FD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80141FD8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80141FDC: jr          $ra
    // 0x80141FE0: nop

    return;
    // 0x80141FE0: nop

;}
RECOMP_FUNC void sc1PBonusStageFuncUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D0D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D0D8: jal         0x8011485C
    // 0x8018D0DC: nop

    ifCommonBattleUpdateInterfaceAll(rdram, ctx);
        goto after_0;
    // 0x8018D0DC: nop

    after_0:
    // 0x8018D0E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D0E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D0E8: jr          $ra
    // 0x8018D0EC: nop

    return;
    // 0x8018D0EC: nop

;}
RECOMP_FUNC void itRShellSpinInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017AFEC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017AFF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017AFF4: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8017AFF8: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8017AFFC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8017B000: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x8017B004: lhu         $t8, 0x2D2($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0X2D2);
    // 0x8017B008: lbu         $t6, 0x2CE($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X2CE);
    // 0x8017B00C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8017B010: andi        $t9, $t8, 0xF
    ctx->r25 = ctx->r24 & 0XF;
    // 0x8017B014: ori         $t0, $t9, 0x5780
    ctx->r8 = ctx->r25 | 0X5780;
    // 0x8017B018: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x8017B01C: sb          $t7, 0x2CE($a1)
    MEM_B(0X2CE, ctx->r5) = ctx->r15;
    // 0x8017B020: bc1f        L_8017B030
    if (!c1cs) {
        // 0x8017B024: sh          $t0, 0x2D2($a1)
        MEM_H(0X2D2, ctx->r5) = ctx->r8;
            goto L_8017B030;
    }
    // 0x8017B024: sh          $t0, 0x2D2($a1)
    MEM_H(0X2D2, ctx->r5) = ctx->r8;
    // 0x8017B028: swc1        $f2, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f2.u32l;
    // 0x8017B02C: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
L_8017B030:
    // 0x8017B030: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x8017B034: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8017B038: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8017B03C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8017B040: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8017B044: addiu       $t4, $zero, 0x1E0
    ctx->r12 = ADD32(0, 0X1E0);
    // 0x8017B048: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8017B04C: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x8017B050: bc1f        L_8017B060
    if (!c1cs) {
        // 0x8017B054: addiu       $t7, $zero, 0x8
        ctx->r15 = ADD32(0, 0X8);
            goto L_8017B060;
    }
    // 0x8017B054: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8017B058: swc1        $f2, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f2.u32l;
    // 0x8017B05C: lwc1        $f0, 0x2C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X2C);
L_8017B060:
    // 0x8017B060: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8017B064: nop

    // 0x8017B068: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8017B06C: swc1        $f2, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f2.u32l;
    // 0x8017B070: bc1fl       L_8017B084
    if (!c1cs) {
        // 0x8017B074: sw          $t2, 0x24($a1)
        MEM_W(0X24, ctx->r5) = ctx->r10;
            goto L_8017B084;
    }
    goto skip_0;
    // 0x8017B074: sw          $t2, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r10;
    skip_0:
    // 0x8017B078: b           L_8017B084
    // 0x8017B07C: sw          $t1, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r9;
        goto L_8017B084;
    // 0x8017B07C: sw          $t1, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r9;
    // 0x8017B080: sw          $t2, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r10;
L_8017B084:
    // 0x8017B084: lbu         $t3, 0x354($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X354);
    // 0x8017B088: bnel        $t3, $zero, L_8017B0A0
    if (ctx->r11 != 0) {
        // 0x8017B08C: sb          $t7, 0x351($a1)
        MEM_B(0X351, ctx->r5) = ctx->r15;
            goto L_8017B0A0;
    }
    goto skip_1;
    // 0x8017B08C: sb          $t7, 0x351($a1)
    MEM_B(0X351, ctx->r5) = ctx->r15;
    skip_1:
    // 0x8017B090: sw          $t4, 0x2C0($a1)
    MEM_W(0X2C0, ctx->r5) = ctx->r12;
    // 0x8017B094: sb          $t5, 0x354($a1)
    MEM_B(0X354, ctx->r5) = ctx->r13;
    // 0x8017B098: sb          $t6, 0x355($a1)
    MEM_B(0X355, ctx->r5) = ctx->r14;
    // 0x8017B09C: sb          $t7, 0x351($a1)
    MEM_B(0X351, ctx->r5) = ctx->r15;
L_8017B0A0:
    // 0x8017B0A0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8017B0A4: jal         0x8017A6A0
    // 0x8017B0A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    itRShellSpinAddAnim(rdram, ctx);
        goto after_0;
    // 0x8017B0A8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017B0AC: jal         0x800269C0
    // 0x8017B0B0: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8017B0B0: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_1:
    // 0x8017B0B4: jal         0x8017279C
    // 0x8017B0B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itMainClearOwnerStats(rdram, ctx);
        goto after_2;
    // 0x8017B0B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8017B0BC: jal         0x80173F54
    // 0x8017B0C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    itMapSetGround(rdram, ctx);
        goto after_3;
    // 0x8017B0C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8017B0C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B0C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017B0CC: jr          $ra
    // 0x8017B0D0: nop

    return;
    // 0x8017B0D0: nop

;}
RECOMP_FUNC void func_ovl1_803903E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803903E0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x803903E4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x803903E8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x803903EC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x803903F0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x803903F4: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x803903F8: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x803903FC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80390400: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80390404: lw          $s5, 0x84($a0)
    ctx->r21 = MEM_W(ctx->r4, 0X84);
    // 0x80390408: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x8039040C: addiu       $s6, $zero, 0x94
    ctx->r22 = ADD32(0, 0X94);
    // 0x80390410: lw          $t6, 0xAC($s5)
    ctx->r14 = MEM_W(ctx->r21, 0XAC);
    // 0x80390414: lbu         $t8, 0x8($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X8);
    // 0x80390418: addiu       $s4, $s5, 0x10
    ctx->r20 = ADD32(ctx->r21, 0X10);
    // 0x8039041C: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80390420: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80390424: addu        $v0, $t7, $t9
    ctx->r2 = ADD32(ctx->r15, ctx->r25);
    // 0x80390428: lw          $s1, -0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, -0XC);
    // 0x8039042C: lw          $s2, -0x8($v0)
    ctx->r18 = MEM_W(ctx->r2, -0X8);
    // 0x80390430: sb          $a1, 0x9($s5)
    MEM_B(0X9, ctx->r21) = ctx->r5;
L_80390434:
    // 0x80390434: lw          $s0, 0x18($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X18);
    // 0x80390438: beq         $s0, $zero, L_80390498
    if (ctx->r16 == 0) {
        // 0x8039043C: nop
    
            goto L_80390498;
    }
    // 0x8039043C: nop

    // 0x80390440: jal         0x800091F4
    // 0x80390444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcRemoveMObjAll(rdram, ctx);
        goto after_0;
    // 0x80390444: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80390448: beq         $s1, $zero, L_80390458
    if (ctx->r17 == 0) {
        // 0x8039044C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80390458;
    }
    // 0x8039044C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80390450: b           L_80390458
    // 0x80390454: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
        goto L_80390458;
    // 0x80390454: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
L_80390458:
    // 0x80390458: beq         $s2, $zero, L_80390468
    if (ctx->r18 == 0) {
        // 0x8039045C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80390468;
    }
    // 0x8039045C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80390460: b           L_80390468
    // 0x80390464: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
        goto L_80390468;
    // 0x80390464: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
L_80390468:
    // 0x80390468: lbu         $t0, 0x9($s5)
    ctx->r8 = MEM_BU(ctx->r21, 0X9);
    // 0x8039046C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80390470: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80390474: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80390478: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8039047C: bgez        $t0, L_80390490
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80390480: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80390490;
    }
    // 0x80390480: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80390484: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80390488: nop

    // 0x8039048C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80390490:
    // 0x80390490: jal         0x800C8CB8
    // 0x80390494: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_1;
    // 0x80390494: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_1:
L_80390498:
    // 0x80390498: beq         $s1, $zero, L_803904A4
    if (ctx->r17 == 0) {
        // 0x8039049C: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_803904A4;
    }
    // 0x8039049C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x803904A0: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_803904A4:
    // 0x803904A4: beq         $s2, $zero, L_803904B0
    if (ctx->r18 == 0) {
        // 0x803904A8: nop
    
            goto L_803904B0;
    }
    // 0x803904A8: nop

    // 0x803904AC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_803904B0:
    // 0x803904B0: bne         $s3, $s6, L_80390434
    if (ctx->r19 != ctx->r22) {
        // 0x803904B4: addiu       $s4, $s4, 0x4
        ctx->r20 = ADD32(ctx->r20, 0X4);
            goto L_80390434;
    }
    // 0x803904B4: addiu       $s4, $s4, 0x4
    ctx->r20 = ADD32(ctx->r20, 0X4);
    // 0x803904B8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x803904BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x803904C0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x803904C4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x803904C8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x803904CC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x803904D0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x803904D4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x803904D8: jr          $ra
    // 0x803904DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x803904DC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void itNessPKFireFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185614: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80185618: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018561C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80185620: jal         0x80185374
    // 0x80185624: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itNessPKFireCommonUpdateAllCheckDestroy(rdram, ctx);
        goto after_0;
    // 0x80185624: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80185628: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018562C: bne         $v0, $at, L_8018563C
    if (ctx->r2 != ctx->r1) {
        // 0x80185630: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8018563C;
    }
    // 0x80185630: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80185634: b           L_80185650
    // 0x80185638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80185650;
    // 0x80185638: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018563C:
    // 0x8018563C: lui         $a1, 0x3EE6
    ctx->r5 = S32(0X3EE6 << 16);
    // 0x80185640: ori         $a1, $a1, 0x6666
    ctx->r5 = ctx->r5 | 0X6666;
    // 0x80185644: jal         0x80172558
    // 0x80185648: lui         $a2, 0x425C
    ctx->r6 = S32(0X425C << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_1;
    // 0x80185648: lui         $a2, 0x425C
    ctx->r6 = S32(0X425C << 16);
    after_1:
    // 0x8018564C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80185650:
    // 0x80185650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185654: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80185658: jr          $ra
    // 0x8018565C: nop

    return;
    // 0x8018565C: nop

;}
RECOMP_FUNC void syUtilsSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018878: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8001887C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80018880: jal         0x80035CD0
    // 0x80018884: nop

    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x80018884: nop

    after_0:
    // 0x80018888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001888C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80018890: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80018894: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80018898: jr          $ra
    // 0x8001889C: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    return;
    // 0x8001889C: div.s       $f0, $f4, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
;}
RECOMP_FUNC void ftParamProcPauseEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9C8C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9C90: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9C94: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800E9C98: jal         0x800E9B64
    // 0x800E9C9C: addiu       $a1, $a1, -0x6388
    ctx->r5 = ADD32(ctx->r5, -0X6388);
    ftParamRunProcEffect(rdram, ctx);
        goto after_0;
    // 0x800E9C9C: addiu       $a1, $a1, -0x6388
    ctx->r5 = ADD32(ctx->r5, -0X6388);
    after_0:
    // 0x800E9CA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9CA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E9CA8: jr          $ra
    // 0x800E9CAC: nop

    return;
    // 0x800E9CAC: nop

;}
RECOMP_FUNC void func_ovl3_8013877C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013877C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80138780: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80138784: lhu         $t6, 0x1E4($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X1E4);
    // 0x80138788: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8013878C: addiu       $v1, $a2, 0x1CC
    ctx->r3 = ADD32(ctx->r6, 0X1CC);
    // 0x80138790: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80138794: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80138798: slti        $at, $t8, 0x1E
    ctx->r1 = SIGNED(ctx->r24) < 0X1E ? 1 : 0;
    // 0x8013879C: bne         $at, $zero, L_801389AC
    if (ctx->r1 != 0) {
        // 0x801387A0: sh          $t7, 0x1E4($a0)
        MEM_H(0X1E4, ctx->r4) = ctx->r15;
            goto L_801389AC;
    }
    // 0x801387A0: sh          $t7, 0x1E4($a0)
    MEM_H(0X1E4, ctx->r4) = ctx->r15;
    // 0x801387A4: addiu       $v1, $a0, 0x1CC
    ctx->r3 = ADD32(ctx->r4, 0X1CC);
    // 0x801387A8: lhu         $t9, 0x18($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X18);
    // 0x801387AC: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x801387B0: bnel        $t9, $at, L_80138828
    if (ctx->r25 != ctx->r1) {
        // 0x801387B4: lw          $v0, 0x88($v1)
        ctx->r2 = MEM_W(ctx->r3, 0X88);
            goto L_80138828;
    }
    goto skip_0;
    // 0x801387B4: lw          $v0, 0x88($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X88);
    skip_0:
    // 0x801387B8: lw          $v0, 0xEC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XEC);
    // 0x801387BC: bltzl       $v0, L_80138818
    if (SIGNED(ctx->r2) < 0) {
        // 0x801387C0: lwc1        $f8, 0x70($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X70);
            goto L_80138818;
    }
    goto skip_1;
    // 0x801387C0: lwc1        $f8, 0x70($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X70);
    skip_1:
    // 0x801387C4: sw          $v0, 0x88($v1)
    MEM_W(0X88, ctx->r3) = ctx->r2;
    // 0x801387C8: lw          $t0, 0x8E8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8E8);
    // 0x801387CC: lwc1        $f0, 0x1C($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X1C);
    // 0x801387D0: swc1        $f0, 0x70($v1)
    MEM_W(0X70, ctx->r3) = ctx->f0.u32l;
    // 0x801387D4: swc1        $f0, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->f0.u32l;
    // 0x801387D8: lw          $t1, 0x14C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14C);
    // 0x801387DC: bnel        $t1, $zero, L_801387FC
    if (ctx->r9 != 0) {
        // 0x801387E0: lw          $t3, 0x8E8($a2)
        ctx->r11 = MEM_W(ctx->r6, 0X8E8);
            goto L_801387FC;
    }
    goto skip_2;
    // 0x801387E0: lw          $t3, 0x8E8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8E8);
    skip_2:
    // 0x801387E4: lw          $t2, 0x8E8($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X8E8);
    // 0x801387E8: lwc1        $f0, 0x20($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X20);
    // 0x801387EC: swc1        $f0, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f0.u32l;
    // 0x801387F0: b           L_80138824
    // 0x801387F4: swc1        $f0, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f0.u32l;
        goto L_80138824;
    // 0x801387F4: swc1        $f0, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f0.u32l;
    // 0x801387F8: lw          $t3, 0x8E8($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X8E8);
L_801387FC:
    // 0x801387FC: lwc1        $f6, 0xF0($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0XF0);
    // 0x80138800: lwc1        $f4, 0x20($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X20);
    // 0x80138804: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80138808: swc1        $f0, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->f0.u32l;
    // 0x8013880C: b           L_80138824
    // 0x80138810: swc1        $f0, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f0.u32l;
        goto L_80138824;
    // 0x80138810: swc1        $f0, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f0.u32l;
    // 0x80138814: lwc1        $f8, 0x70($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X70);
L_80138818:
    // 0x80138818: lwc1        $f10, 0x74($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8013881C: swc1        $f8, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->f8.u32l;
    // 0x80138820: swc1        $f10, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f10.u32l;
L_80138824:
    // 0x80138824: lw          $v0, 0x88($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X88);
L_80138828:
    // 0x80138828: bltz        $v0, L_8013884C
    if (SIGNED(ctx->r2) < 0) {
        // 0x8013882C: sw          $v0, 0x5C($v1)
        MEM_W(0X5C, ctx->r3) = ctx->r2;
            goto L_8013884C;
    }
    // 0x8013882C: sw          $v0, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->r2;
    // 0x80138830: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80138834: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80138838: jal         0x800FC67C
    // 0x8013883C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x8013883C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    after_0:
    // 0x80138840: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80138844: bne         $v0, $zero, L_80138870
    if (ctx->r2 != 0) {
        // 0x80138848: lw          $a2, 0x58($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X58);
            goto L_80138870;
    }
    // 0x80138848: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
L_8013884C:
    // 0x8013884C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80138850: jal         0x8013295C
    // 0x80138854: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    ftComputerCheckFindTarget(rdram, ctx);
        goto after_1;
    // 0x80138854: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    after_1:
    // 0x80138858: beq         $v0, $zero, L_80138A98
    if (ctx->r2 == 0) {
        // 0x8013885C: lw          $a2, 0x58($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X58);
            goto L_80138A98;
    }
    // 0x8013885C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80138860: jal         0x80134E98
    // 0x80138864: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_2;
    // 0x80138864: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80138868: b           L_80138A9C
    // 0x8013886C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138A9C;
    // 0x8013886C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138870:
    // 0x80138870: lw          $t4, 0x8E8($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X8E8);
    // 0x80138874: lwc1        $f2, 0x78($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X78);
    // 0x80138878: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8013887C: lwc1        $f12, 0x1C($t4)
    ctx->f12.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x80138880: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80138884: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80138888: nop

    // 0x8013888C: bc1fl       L_801388A4
    if (!c1cs) {
        // 0x80138890: sub.s       $f0, $f2, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
            goto L_801388A4;
    }
    goto skip_3;
    // 0x80138890: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    skip_3:
    // 0x80138894: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80138898: b           L_801388A4
    // 0x8013889C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
        goto L_801388A4;
    // 0x8013889C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x801388A0: sub.s       $f0, $f2, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f12.fl;
L_801388A4:
    // 0x801388A4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801388A8: nop

    // 0x801388AC: bc1fl       L_80138970
    if (!c1cs) {
        // 0x801388B0: lbu         $t5, 0x4A($v1)
        ctx->r13 = MEM_BU(ctx->r3, 0X4A);
            goto L_80138970;
    }
    goto skip_4;
    // 0x801388B0: lbu         $t5, 0x4A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X4A);
    skip_4:
    // 0x801388B4: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x801388B8: jal         0x80018948
    // 0x801388BC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_3;
    // 0x801388BC: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    after_3:
    // 0x801388C0: cvt.d.s     $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.d = CVT_D_S(ctx->f0.fl);
    // 0x801388C4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x801388C8: add.d       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f2.d); 
    ctx->f18.d = ctx->f2.d + ctx->f2.d;
    // 0x801388CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x801388D0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801388D4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801388D8: ldc1        $f8, -0x40F8($at)
    CHECK_FR(ctx, 8);
    ctx->f8.u64 = LD(ctx->r1, -0X40F8);
    // 0x801388DC: sub.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f18.d - ctx->f4.d;
    // 0x801388E0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x801388E4: addiu       $a1, $sp, 0x48
    ctx->r5 = ADD32(ctx->r29, 0X48);
    // 0x801388E8: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x801388EC: lwc1        $f16, 0x70($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X70);
    // 0x801388F0: lw          $a0, 0x88($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X88);
    // 0x801388F4: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x801388F8: add.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = ctx->f10.d + ctx->f18.d;
    // 0x801388FC: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80138900: jal         0x800F4428
    // 0x80138904: swc1        $f6, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->f6.u32l;
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_4;
    // 0x80138904: swc1        $f6, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->f6.u32l;
    after_4:
    // 0x80138908: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8013890C: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80138910: jal         0x800F4408
    // 0x80138914: lw          $a0, 0x88($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X88);
    mpCollisionGetFloorEdgeR(rdram, ctx);
        goto after_5;
    // 0x80138914: lw          $a0, 0x88($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X88);
    after_5:
    // 0x80138918: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8013891C: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80138920: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80138924: lwc1        $f2, 0x78($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X78);
    // 0x80138928: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x8013892C: nop

    // 0x80138930: bc1fl       L_8013894C
    if (!c1cs) {
        // 0x80138934: lwc1        $f10, 0x3C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
            goto L_8013894C;
    }
    goto skip_5;
    // 0x80138934: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    skip_5:
    // 0x80138938: swc1        $f8, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->f8.u32l;
    // 0x8013893C: lwc1        $f16, 0x4C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80138940: lwc1        $f2, 0x78($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X78);
    // 0x80138944: swc1        $f16, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f16.u32l;
    // 0x80138948: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
L_8013894C:
    // 0x8013894C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80138950: nop

    // 0x80138954: bc1fl       L_80138970
    if (!c1cs) {
        // 0x80138958: lbu         $t5, 0x4A($v1)
        ctx->r13 = MEM_BU(ctx->r3, 0X4A);
            goto L_80138970;
    }
    goto skip_6;
    // 0x80138958: lbu         $t5, 0x4A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X4A);
    skip_6:
    // 0x8013895C: swc1        $f10, 0x78($v1)
    MEM_W(0X78, ctx->r3) = ctx->f10.u32l;
    // 0x80138960: lwc1        $f18, 0x40($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80138964: lwc1        $f2, 0x78($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X78);
    // 0x80138968: swc1        $f18, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->f18.u32l;
    // 0x8013896C: lbu         $t5, 0x4A($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X4A);
L_80138970:
    // 0x80138970: lwc1        $f4, 0x7C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X7C);
    // 0x80138974: swc1        $f2, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f2.u32l;
    // 0x80138978: andi        $t6, $t5, 0xFFBF
    ctx->r14 = ctx->r13 & 0XFFBF;
    // 0x8013897C: sb          $t6, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r14;
    // 0x80138980: swc1        $f4, 0x64($v1)
    MEM_W(0X64, ctx->r3) = ctx->f4.u32l;
    // 0x80138984: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80138988: jal         0x80134E98
    // 0x8013898C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_6;
    // 0x8013898C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_6:
    // 0x80138990: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80138994: lhu         $t7, 0x18($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X18);
    // 0x80138998: slti        $at, $t7, 0x97
    ctx->r1 = SIGNED(ctx->r15) < 0X97 ? 1 : 0;
    // 0x8013899C: bnel        $at, $zero, L_80138A9C
    if (ctx->r1 != 0) {
        // 0x801389A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80138A9C;
    }
    goto skip_7;
    // 0x801389A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_7:
    // 0x801389A4: b           L_80138A98
    // 0x801389A8: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
        goto L_80138A98;
    // 0x801389A8: sh          $zero, 0x18($v1)
    MEM_H(0X18, ctx->r3) = 0;
L_801389AC:
    // 0x801389AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801389B0: sb          $t8, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r24;
    // 0x801389B4: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x801389B8: lw          $t9, -0x7CC0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X7CC0);
    // 0x801389BC: lhu         $t4, 0x18($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X18);
    // 0x801389C0: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x801389C4: lbu         $t0, 0x13($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0X13);
    // 0x801389C8: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x801389CC: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x801389D0: addiu       $t3, $t2, 0x12
    ctx->r11 = ADD32(ctx->r10, 0X12);
    // 0x801389D4: bnel        $t3, $t4, L_80138A9C
    if (ctx->r11 != ctx->r12) {
        // 0x801389D8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80138A9C;
    }
    goto skip_8;
    // 0x801389D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_8:
    // 0x801389DC: lw          $t5, 0x14C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X14C);
    // 0x801389E0: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x801389E4: bnel        $t5, $zero, L_80138A9C
    if (ctx->r13 != 0) {
        // 0x801389E8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80138A9C;
    }
    goto skip_9;
    // 0x801389E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_9:
    // 0x801389EC: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x801389F0: jal         0x80136A20
    // 0x801389F4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    ftComputerCheckTryChargeSpecialN(rdram, ctx);
        goto after_7;
    // 0x801389F4: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    after_7:
    // 0x801389F8: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x801389FC: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80138A00: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80138A04: lw          $a0, 0x8($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X8);
    // 0x80138A08: beq         $a0, $at, L_80138A20
    if (ctx->r4 == ctx->r1) {
        // 0x80138A0C: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80138A20;
    }
    // 0x80138A0C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80138A10: beq         $a0, $at, L_80138A6C
    if (ctx->r4 == ctx->r1) {
        // 0x80138A14: nop
    
            goto L_80138A6C;
    }
    // 0x80138A14: nop

    // 0x80138A18: b           L_80138A9C
    // 0x80138A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138A9C;
    // 0x80138A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138A20:
    // 0x80138A20: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80138A24: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80138A28: jal         0x8013295C
    // 0x80138A2C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    ftComputerCheckFindTarget(rdram, ctx);
        goto after_8;
    // 0x80138A2C: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    after_8:
    // 0x80138A30: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80138A34: beq         $v0, $zero, L_80138A98
    if (ctx->r2 == 0) {
        // 0x80138A38: lw          $a2, 0x58($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X58);
            goto L_80138A98;
    }
    // 0x80138A38: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80138A3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80138A40: lwc1        $f8, -0x40F0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X40F0);
    // 0x80138A44: lwc1        $f6, 0x68($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X68);
    // 0x80138A48: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80138A4C: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80138A50: nop

    // 0x80138A54: bc1fl       L_80138A9C
    if (!c1cs) {
        // 0x80138A58: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80138A9C;
    }
    goto skip_10;
    // 0x80138A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_10:
    // 0x80138A5C: jal         0x80132564
    // 0x80138A60: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_9;
    // 0x80138A60: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    after_9:
    // 0x80138A64: b           L_80138A9C
    // 0x80138A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80138A9C;
    // 0x80138A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138A6C:
    // 0x80138A6C: jal         0x80018948
    // 0x80138A70: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    syUtilsRandFloat(rdram, ctx);
        goto after_10;
    // 0x80138A70: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    after_10:
    // 0x80138A74: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80138A78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80138A7C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80138A80: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80138A84: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80138A88: bc1fl       L_80138A9C
    if (!c1cs) {
        // 0x80138A8C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80138A9C;
    }
    goto skip_11;
    // 0x80138A8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_11:
    // 0x80138A90: jal         0x80132564
    // 0x80138A94: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    ftComputerSetCommandWaitShort(rdram, ctx);
        goto after_11;
    // 0x80138A94: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    after_11:
L_80138A98:
    // 0x80138A98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138A9C:
    // 0x80138A9C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80138AA0: jr          $ra
    // 0x80138AA4: nop

    return;
    // 0x80138AA4: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNGetStatusChargeLevelReset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157D98: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80157D9C: lw          $t6, 0xAE8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XAE8);
    // 0x80157DA0: sw          $zero, 0xAE8($v0)
    MEM_W(0XAE8, ctx->r2) = 0;
    // 0x80157DA4: jr          $ra
    // 0x80157DA8: sw          $t6, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r14;
    return;
    // 0x80157DA8: sw          $t6, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r14;
;}
RECOMP_FUNC void sc1PIntroGetVSFighterPositionZ(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013312C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80133130: bnel        $a0, $at, L_80133160
    if (ctx->r4 != ctx->r1) {
        // 0x80133134: lui         $at, 0xC3FA
        ctx->r1 = S32(0XC3FA << 16);
            goto L_80133160;
    }
    goto skip_0;
    // 0x80133134: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
    skip_0:
    // 0x80133138: bne         $a1, $zero, L_80133150
    if (ctx->r5 != 0) {
        // 0x8013313C: lui         $at, 0xC448
        ctx->r1 = S32(0XC448 << 16);
            goto L_80133150;
    }
    // 0x8013313C: lui         $at, 0xC448
    ctx->r1 = S32(0XC448 << 16);
    // 0x80133140: lui         $at, 0xC416
    ctx->r1 = S32(0XC416 << 16);
    // 0x80133144: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133148: jr          $ra
    // 0x8013314C: nop

    return;
    // 0x8013314C: nop

L_80133150:
    // 0x80133150: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133154: jr          $ra
    // 0x80133158: nop

    return;
    // 0x80133158: nop

    // 0x8013315C: lui         $at, 0xC3FA
    ctx->r1 = S32(0XC3FA << 16);
L_80133160:
    // 0x80133160: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133164: nop

    // 0x80133168: jr          $ra
    // 0x8013316C: nop

    return;
    // 0x8013316C: nop

;}
RECOMP_FUNC void ftCommonJumpProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F660: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F664: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F668: jal         0x80150F08
    // 0x8013F66C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonSpecialAirCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8013F66C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013F670: bnel        $v0, $zero, L_8013F694
    if (ctx->r2 != 0) {
        // 0x8013F674: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013F694;
    }
    goto skip_0;
    // 0x8013F674: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013F678: jal         0x80150B00
    // 0x8013F67C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonAttackAirCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8013F67C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013F680: bnel        $v0, $zero, L_8013F694
    if (ctx->r2 != 0) {
        // 0x8013F684: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013F694;
    }
    goto skip_1;
    // 0x8013F684: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013F688: jal         0x8014019C
    // 0x8013F68C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonJumpAerialCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x8013F68C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8013F690: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013F694:
    // 0x8013F694: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F698: jr          $ra
    // 0x8013F69C: nop

    return;
    // 0x8013F69C: nop

;}
RECOMP_FUNC void ftBossTsutsuku2ProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159F40: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80159F44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80159F48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80159F4C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80159F50: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80159F54: lh          $t6, 0xB18($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XB18);
    // 0x80159F58: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80159F5C: sh          $t7, 0xB18($s0)
    MEM_H(0XB18, ctx->r16) = ctx->r15;
    // 0x80159F60: lh          $t8, 0xB18($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XB18);
    // 0x80159F64: bnel        $t8, $zero, L_80159F80
    if (ctx->r24 != 0) {
        // 0x80159F68: lw          $t9, 0x44($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X44);
            goto L_80159F80;
    }
    goto skip_0;
    // 0x80159F68: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
    skip_0:
    // 0x80159F6C: jal         0x80159F14
    // 0x80159F70: nop

    ftBossTsutsuku3SetStatus(rdram, ctx);
        goto after_0;
    // 0x80159F70: nop

    after_0:
    // 0x80159F74: b           L_8015A060
    // 0x80159F78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8015A060;
    // 0x80159F78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80159F7C: lw          $t9, 0x44($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X44);
L_80159F80:
    // 0x80159F80: lw          $t1, 0xADC($s0)
    ctx->r9 = MEM_W(ctx->r16, 0XADC);
    // 0x80159F84: lui         $at, 0x4461
    ctx->r1 = S32(0X4461 << 16);
    // 0x80159F88: negu        $t0, $t9
    ctx->r8 = SUB32(0, ctx->r25);
    // 0x80159F8C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80159F90: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80159F94: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x80159F98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80159F9C: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x80159FA0: lw          $t3, 0x74($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X74);
    // 0x80159FA4: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x80159FA8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80159FAC: lwc1        $f16, 0x1C($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x80159FB0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80159FB4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80159FB8: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x80159FBC: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80159FC0: swc1        $f18, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f18.u32l;
    // 0x80159FC4: lw          $t4, 0xADC($s0)
    ctx->r12 = MEM_W(ctx->r16, 0XADC);
    // 0x80159FC8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80159FCC: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x80159FD0: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80159FD4: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    // 0x80159FD8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80159FDC: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80159FE0: lw          $a2, 0x74($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X74);
    // 0x80159FE4: jal         0x8001902C
    // 0x80159FE8: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    syVectorDiff3D(rdram, ctx);
        goto after_1;
    // 0x80159FE8: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_1:
    // 0x80159FEC: jal         0x80018F7C
    // 0x80159FF0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    syVectorMag3D(rdram, ctx);
        goto after_2;
    // 0x80159FF0: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x80159FF4: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80159FF8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80159FFC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8015A000: lwc1        $f18, 0x24($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8015A004: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x8015A008: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8015A00C: bc1f        L_8015A024
    if (!c1cs) {
        // 0x8015A010: nop
    
            goto L_8015A024;
    }
    // 0x8015A010: nop

    // 0x8015A014: swc1        $f18, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f18.u32l;
    // 0x8015A018: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8015A01C: b           L_8015A05C
    // 0x8015A020: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
        goto L_8015A05C;
    // 0x8015A020: swc1        $f4, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f4.u32l;
L_8015A024:
    // 0x8015A024: jal         0x80018EE0
    // 0x8015A028: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_3;
    // 0x8015A028: swc1        $f2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f2.u32l;
    after_3:
    // 0x8015A02C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015A030: lwc1        $f2, 0x20($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8015A034: lwc1        $f6, -0x37F0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X37F0);
    // 0x8015A038: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8015A03C: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8015A040: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x8015A044: jal         0x800190B0
    // 0x8015A048: nop

    syVectorScale3D(rdram, ctx);
        goto after_4;
    // 0x8015A048: nop

    after_4:
    // 0x8015A04C: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8015A050: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
    // 0x8015A054: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8015A058: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
L_8015A05C:
    // 0x8015A05C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015A060:
    // 0x8015A060: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015A064: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8015A068: jr          $ra
    // 0x8015A06C: nop

    return;
    // 0x8015A06C: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNLoopProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016249C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801624A0: jal         0x80162424
    // 0x801624A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftKirbySpecialNLoopCheckContinueLoop(rdram, ctx);
        goto after_0;
    // 0x801624A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801624A8: bnel        $v0, $zero, L_801624BC
    if (ctx->r2 != 0) {
        // 0x801624AC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801624BC;
    }
    goto skip_0;
    // 0x801624AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801624B0: jal         0x801635B0
    // 0x801624B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftKirbySpecialAirNEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x801624B4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801624B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801624BC:
    // 0x801624BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801624C0: jr          $ra
    // 0x801624C4: nop

    return;
    // 0x801624C4: nop

;}
RECOMP_FUNC void n_alSavePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C6BC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C6C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C6C4: jal         0x8002C648
    // 0x8002C6C8: nop

    n_alMainBusPull(rdram, ctx);
        goto after_0;
    // 0x8002C6C8: nop

    after_0:
    // 0x8002C6CC: lui         $t6, 0xD00
    ctx->r14 = S32(0XD00 << 16);
    // 0x8002C6D0: lui         $t7, 0x62E
    ctx->r15 = S32(0X62E << 16);
    // 0x8002C6D4: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8002C6D8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8002C6DC: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002C6E0: lw          $t8, -0x2CEC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2CEC);
    // 0x8002C6E4: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002C6E8: lw          $t9, 0x54($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X54);
    // 0x8002C6EC: sw          $t9, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r25;
    // 0x8002C6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C6F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C6F8: jr          $ra
    // 0x8002C6FC: nop

    return;
    // 0x8002C6FC: nop

;}
RECOMP_FUNC void stringCopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376FFC: beq         $a0, $zero, L_8037703C
    if (ctx->r4 == 0) {
        // 0x80377000: nop
    
            goto L_8037703C;
    }
    // 0x80377000: nop

    // 0x80377004: beq         $a1, $zero, L_8037703C
    if (ctx->r5 == 0) {
        // 0x80377008: nop
    
            goto L_8037703C;
    }
    // 0x80377008: nop

    // 0x8037700C: lbu         $t6, 0x0($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X0);
    // 0x80377010: beq         $t6, $zero, L_80377038
    if (ctx->r14 == 0) {
        // 0x80377014: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80377038;
    }
    // 0x80377014: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_80377018:
    // 0x80377018: lbu         $t7, 0x0($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X0);
    // 0x8037701C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80377020: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80377024: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80377028: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x8037702C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80377030: bnel        $t8, $zero, L_80377018
    if (ctx->r24 != 0) {
        // 0x80377034: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_80377018;
    }
    goto skip_0;
    // 0x80377034: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    skip_0:
L_80377038:
    // 0x80377038: sb          $zero, 0x0($a0)
    MEM_B(0X0, ctx->r4) = 0;
L_8037703C:
    // 0x8037703C: jr          $ra
    // 0x80377040: nop

    return;
    // 0x80377040: nop

;}
RECOMP_FUNC void ftDisplayMainProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F293C: addiu       $sp, $sp, -0x148
    ctx->r29 = ADD32(ctx->r29, -0X148);
    // 0x800F2940: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800F2944: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800F2948: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800F294C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800F2950: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800F2954: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800F2958: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800F295C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800F2960: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800F2964: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800F2968: lw          $fp, 0x84($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X84);
    // 0x800F296C: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800F2970: addiu       $s3, $s3, 0x12F0
    ctx->r19 = ADD32(ctx->r19, 0X12F0);
    // 0x800F2974: lw          $t6, 0x9C8($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X9C8);
    // 0x800F2978: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800F297C: sb          $t7, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r15;
    // 0x800F2980: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F2984: sb          $zero, 0x12F1($at)
    MEM_B(0X12F1, ctx->r1) = 0;
    // 0x800F2988: sw          $t6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r14;
    // 0x800F298C: lhu         $t8, 0x18C($fp)
    ctx->r24 = MEM_HU(ctx->r30, 0X18C);
    // 0x800F2990: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x800F2994: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x800F2998: beql        $t9, $zero, L_800F29C0
    if (ctx->r25 == 0) {
        // 0x800F299C: lw          $v0, 0x20($fp)
        ctx->r2 = MEM_W(ctx->r30, 0X20);
            goto L_800F29C0;
    }
    goto skip_0;
    // 0x800F299C: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    skip_0:
    // 0x800F29A0: lw          $t3, 0xB4C($fp)
    ctx->r11 = MEM_W(ctx->r30, 0XB4C);
    // 0x800F29A4: bnel        $t3, $zero, L_800F29C0
    if (ctx->r11 != 0) {
        // 0x800F29A8: lw          $v0, 0x20($fp)
        ctx->r2 = MEM_W(ctx->r30, 0X20);
            goto L_800F29C0;
    }
    goto skip_1;
    // 0x800F29A8: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    skip_1:
    // 0x800F29AC: lbu         $t4, 0x18D($fp)
    ctx->r12 = MEM_BU(ctx->r30, 0X18D);
    // 0x800F29B0: andi        $t5, $t4, 0xFFFB
    ctx->r13 = ctx->r12 & 0XFFFB;
    // 0x800F29B4: b           L_800F36A8
    // 0x800F29B8: sb          $t5, 0x18D($fp)
    MEM_B(0X18D, ctx->r30) = ctx->r13;
        goto L_800F36A8;
    // 0x800F29B8: sb          $t5, 0x18D($fp)
    MEM_B(0X18D, ctx->r30) = ctx->r13;
    // 0x800F29BC: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
L_800F29C0:
    // 0x800F29C0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F29C4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800F29C8: beq         $v0, $zero, L_800F29E0
    if (ctx->r2 == 0) {
        // 0x800F29CC: nop
    
            goto L_800F29E0;
    }
    // 0x800F29CC: nop

    // 0x800F29D0: beq         $v0, $at, L_800F29E0
    if (ctx->r2 == ctx->r1) {
        // 0x800F29D4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800F29E0;
    }
    // 0x800F29D4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800F29D8: bnel        $v0, $at, L_800F2BD4
    if (ctx->r2 != ctx->r1) {
        // 0x800F29DC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800F2BD4;
    }
    goto skip_2;
    // 0x800F29DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_2:
L_800F29E0:
    // 0x800F29E0: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x800F29E4: addiu       $at, $zero, 0x3EA
    ctx->r1 = ADD32(0, 0X3EA);
    // 0x800F29E8: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800F29EC: bnel        $t7, $at, L_800F2BA8
    if (ctx->r15 != ctx->r1) {
        // 0x800F29F0: lw          $v0, 0x18C($fp)
        ctx->r2 = MEM_W(ctx->r30, 0X18C);
            goto L_800F2BA8;
    }
    goto skip_3;
    // 0x800F29F0: lw          $v0, 0x18C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18C);
    skip_3:
    // 0x800F29F4: lw          $v0, 0x24($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X24);
    // 0x800F29F8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F29FC: beq         $v0, $at, L_800F2A0C
    if (ctx->r2 == ctx->r1) {
        // 0x800F2A00: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800F2A0C;
    }
    // 0x800F2A00: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F2A04: bnel        $v0, $at, L_800F2A20
    if (ctx->r2 != ctx->r1) {
        // 0x800F2A08: lw          $t3, 0x8E8($fp)
        ctx->r11 = MEM_W(ctx->r30, 0X8E8);
            goto L_800F2A20;
    }
    goto skip_4;
    // 0x800F2A08: lw          $t3, 0x8E8($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X8E8);
    skip_4:
L_800F2A0C:
    // 0x800F2A0C: lbu         $t8, 0x18D($fp)
    ctx->r24 = MEM_BU(ctx->r30, 0X18D);
    // 0x800F2A10: andi        $t9, $t8, 0xFFFB
    ctx->r25 = ctx->r24 & 0XFFFB;
    // 0x800F2A14: b           L_800F2BD0
    // 0x800F2A18: sb          $t9, 0x18D($fp)
    MEM_B(0X18D, ctx->r30) = ctx->r25;
        goto L_800F2BD0;
    // 0x800F2A18: sb          $t9, 0x18D($fp)
    MEM_B(0X18D, ctx->r30) = ctx->r25;
    // 0x800F2A1C: lw          $t3, 0x8E8($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X8E8);
L_800F2A20:
    // 0x800F2A20: addiu       $s1, $sp, 0x128
    ctx->r17 = ADD32(ctx->r29, 0X128);
    // 0x800F2A24: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800F2A28: lw          $t5, 0x1C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X1C);
    // 0x800F2A2C: addiu       $s2, $s2, 0x1460
    ctx->r18 = ADD32(ctx->r18, 0X1460);
    // 0x800F2A30: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800F2A34: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800F2A38: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x800F2A3C: addiu       $s0, $sp, 0x110
    ctx->r16 = ADD32(ctx->r29, 0X110);
    // 0x800F2A40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F2A44: sw          $t4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r12;
    // 0x800F2A48: lw          $t5, 0x24($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X24);
    // 0x800F2A4C: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800F2A50: sw          $t5, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r13;
    // 0x800F2A54: lw          $t6, 0x9C8($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X9C8);
    // 0x800F2A58: lwc1        $f4, 0x12C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800F2A5C: lwc1        $f6, 0x8C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X8C);
    // 0x800F2A60: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F2A64: swc1        $f8, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f8.u32l;
    // 0x800F2A68: lw          $a1, 0x74($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X74);
    // 0x800F2A6C: jal         0x8001902C
    // 0x800F2A70: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    syVectorDiff3D(rdram, ctx);
        goto after_0;
    // 0x800F2A70: addiu       $a1, $a1, 0x48
    ctx->r5 = ADD32(ctx->r5, 0X48);
    after_0:
    // 0x800F2A74: jal         0x80018F7C
    // 0x800F2A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syVectorMag3D(rdram, ctx);
        goto after_1;
    // 0x800F2A78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x800F2A7C: lw          $t8, 0x9C8($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X9C8);
    // 0x800F2A80: lwc1        $f10, 0x8C($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0X8C);
    // 0x800F2A84: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800F2A88: nop

    // 0x800F2A8C: bc1fl       L_800F2ABC
    if (!c1cs) {
        // 0x800F2A90: lw          $t3, 0x0($s2)
        ctx->r11 = MEM_W(ctx->r18, 0X0);
            goto L_800F2ABC;
    }
    goto skip_5;
    // 0x800F2A90: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    skip_5:
    // 0x800F2A94: jal         0x80018EE0
    // 0x800F2A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syVectorNorm3D(rdram, ctx);
        goto after_2;
    // 0x800F2A98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800F2A9C: lw          $t9, 0x9C8($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X9C8);
    // 0x800F2AA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800F2AA4: jal         0x800190B0
    // 0x800F2AA8: lw          $a1, 0x8C($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8C);
    syVectorScale3D(rdram, ctx);
        goto after_3;
    // 0x800F2AA8: lw          $a1, 0x8C($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8C);
    after_3:
    // 0x800F2AAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800F2AB0: jal         0x80018FBC
    // 0x800F2AB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    syVectorAdd3D(rdram, ctx);
        goto after_4;
    // 0x800F2AB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800F2AB8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
L_800F2ABC:
    // 0x800F2ABC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F2AC0: addiu       $s0, $s0, 0x1470
    ctx->r16 = ADD32(ctx->r16, 0X1470);
    // 0x800F2AC4: addiu       $t4, $sp, 0x120
    ctx->r12 = ADD32(ctx->r29, 0X120);
    // 0x800F2AC8: lw          $a0, 0x74($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X74);
    // 0x800F2ACC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800F2AD0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F2AD4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800F2AD8: jal         0x800EB924
    // 0x800F2ADC: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    func_ovl2_800EB924(rdram, ctx);
        goto after_5;
    // 0x800F2ADC: addiu       $a3, $sp, 0x124
    ctx->r7 = ADD32(ctx->r29, 0X124);
    after_5:
    // 0x800F2AE0: lwc1        $f12, 0x124($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800F2AE4: jal         0x8010E5F4
    // 0x800F2AE8: lwc1        $f14, 0x120($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X120);
    gmCameraCheckTargetInBounds(rdram, ctx);
        goto after_6;
    // 0x800F2AE8: lwc1        $f14, 0x120($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X120);
    after_6:
    // 0x800F2AEC: bnel        $v0, $zero, L_800F2B98
    if (ctx->r2 != 0) {
        // 0x800F2AF0: lbu         $t5, 0x18D($fp)
        ctx->r13 = MEM_BU(ctx->r30, 0X18D);
            goto L_800F2B98;
    }
    goto skip_6;
    // 0x800F2AF0: lbu         $t5, 0x18D($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0X18D);
    skip_6:
    // 0x800F2AF4: lw          $t5, 0x8E8($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X8E8);
    // 0x800F2AF8: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x800F2AFC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F2B00: lw          $t7, 0x1C($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X1C);
    // 0x800F2B04: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800F2B08: addiu       $t9, $fp, 0x1AC
    ctx->r25 = ADD32(ctx->r30, 0X1AC);
    // 0x800F2B0C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800F2B10: lw          $t6, 0x20($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X20);
    // 0x800F2B14: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800F2B18: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x800F2B1C: sw          $t6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r14;
    // 0x800F2B20: lw          $t7, 0x24($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X24);
    // 0x800F2B24: addiu       $a3, $fp, 0x1A8
    ctx->r7 = ADD32(ctx->r30, 0X1A8);
    // 0x800F2B28: sw          $t7, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->r15;
    // 0x800F2B2C: lwc1        $f16, 0x12C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800F2B30: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800F2B34: swc1        $f4, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f4.u32l;
    // 0x800F2B38: lw          $a0, 0x74($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X74);
    // 0x800F2B3C: jal         0x800EB924
    // 0x800F2B40: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_ovl2_800EB924(rdram, ctx);
        goto after_7;
    // 0x800F2B40: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_7:
    // 0x800F2B44: lbu         $t4, 0x18D($fp)
    ctx->r12 = MEM_BU(ctx->r30, 0X18D);
    // 0x800F2B48: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800F2B4C: addiu       $v1, $v1, 0x1580
    ctx->r3 = ADD32(ctx->r3, 0X1580);
    // 0x800F2B50: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x800F2B54: sb          $t5, 0x18D($fp)
    MEM_B(0X18D, ctx->r30) = ctx->r13;
    // 0x800F2B58: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800F2B5C: beql        $t6, $zero, L_800F36AC
    if (ctx->r14 == 0) {
        // 0x800F2B60: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800F36AC;
    }
    goto skip_7;
    // 0x800F2B60: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_7:
    // 0x800F2B64: lw          $v0, 0x18C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18C);
    // 0x800F2B68: sll         $t8, $v0, 18
    ctx->r24 = S32(ctx->r2 << 18);
    // 0x800F2B6C: bltz        $t8, L_800F36A8
    if (SIGNED(ctx->r24) < 0) {
        // 0x800F2B70: sll         $t3, $v0, 17
        ctx->r11 = S32(ctx->r2 << 17);
            goto L_800F36A8;
    }
    // 0x800F2B70: sll         $t3, $v0, 17
    ctx->r11 = S32(ctx->r2 << 17);
    // 0x800F2B74: bltz        $t3, L_800F36A8
    if (SIGNED(ctx->r11) < 0) {
        // 0x800F2B78: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800F36A8;
    }
    // 0x800F2B78: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800F2B7C: sb          $t4, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r12;
    // 0x800F2B80: lwc1        $f12, 0x124($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X124);
    // 0x800F2B84: jal         0x801119AC
    // 0x800F2B88: lwc1        $f14, 0x120($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X120);
    ifCommonPlayerArrowsUpdateFlags(rdram, ctx);
        goto after_8;
    // 0x800F2B88: lwc1        $f14, 0x120($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X120);
    after_8:
    // 0x800F2B8C: b           L_800F36AC
    // 0x800F2B90: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_800F36AC;
    // 0x800F2B90: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800F2B94: lbu         $t5, 0x18D($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0X18D);
L_800F2B98:
    // 0x800F2B98: andi        $t6, $t5, 0xFFFB
    ctx->r14 = ctx->r13 & 0XFFFB;
    // 0x800F2B9C: b           L_800F2BD0
    // 0x800F2BA0: sb          $t6, 0x18D($fp)
    MEM_B(0X18D, ctx->r30) = ctx->r14;
        goto L_800F2BD0;
    // 0x800F2BA0: sb          $t6, 0x18D($fp)
    MEM_B(0X18D, ctx->r30) = ctx->r14;
    // 0x800F2BA4: lw          $v0, 0x18C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18C);
L_800F2BA8:
    // 0x800F2BA8: sll         $t8, $v0, 18
    ctx->r24 = S32(ctx->r2 << 18);
    // 0x800F2BAC: bltz        $t8, L_800F36A8
    if (SIGNED(ctx->r24) < 0) {
        // 0x800F2BB0: sll         $t3, $v0, 17
        ctx->r11 = S32(ctx->r2 << 17);
            goto L_800F36A8;
    }
    // 0x800F2BB0: sll         $t3, $v0, 17
    ctx->r11 = S32(ctx->r2 << 17);
    // 0x800F2BB4: bltz        $t3, L_800F36A8
    if (SIGNED(ctx->r11) < 0) {
        // 0x800F2BB8: sll         $t5, $v0, 13
        ctx->r13 = S32(ctx->r2 << 13);
            goto L_800F36A8;
    }
    // 0x800F2BB8: sll         $t5, $v0, 13
    ctx->r13 = S32(ctx->r2 << 13);
    // 0x800F2BBC: bgez        $t5, L_800F36A8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800F2BC0: lui         $s4, 0x8004
        ctx->r20 = S32(0X8004 << 16);
            goto L_800F36A8;
    }
    // 0x800F2BC0: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x800F2BC4: addiu       $a0, $s4, 0x65B0
    ctx->r4 = ADD32(ctx->r20, 0X65B0);
    // 0x800F2BC8: jal         0x80110DD4
    // 0x800F2BCC: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    ifCommonPlayerMagnifyUpdateViewport(rdram, ctx);
        goto after_9;
    // 0x800F2BCC: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    after_9:
L_800F2BD0:
    // 0x800F2BD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800F2BD4:
    // 0x800F2BD4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800F2BD8: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800F2BDC: addiu       $v0, $v0, 0x62D0
    ctx->r2 = ADD32(ctx->r2, 0X62D0);
    // 0x800F2BE0: swc1        $f6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f6.u32l;
    // 0x800F2BE4: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F2BE8: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x800F2BEC: addiu       $s4, $s4, 0x65B0
    ctx->r20 = ADD32(ctx->r20, 0X65B0);
    // 0x800F2BF0: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x800F2BF4: lwc1        $f10, 0x4($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X4);
    // 0x800F2BF8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F2BFC: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800F2C00: lw          $v1, 0xB4C($fp)
    ctx->r3 = MEM_W(ctx->r30, 0XB4C);
    // 0x800F2C04: beql        $v1, $zero, L_800F2C18
    if (ctx->r3 == 0) {
        // 0x800F2C08: lw          $s0, 0x0($s4)
        ctx->r16 = MEM_W(ctx->r20, 0X0);
            goto L_800F2C18;
    }
    goto skip_8;
    // 0x800F2C08: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    skip_8:
    // 0x800F2C0C: bne         $v1, $at, L_800F330C
    if (ctx->r3 != ctx->r1) {
        // 0x800F2C10: lui         $t7, 0x8004
        ctx->r15 = S32(0X8004 << 16);
            goto L_800F330C;
    }
    // 0x800F2C10: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800F2C14: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
L_800F2C18:
    // 0x800F2C18: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x800F2C1C: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800F2C20: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800F2C24: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800F2C28: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800F2C2C: lw          $t8, 0xA88($fp)
    ctx->r24 = MEM_W(ctx->r30, 0XA88);
    // 0x800F2C30: sll         $t3, $t8, 1
    ctx->r11 = S32(ctx->r24 << 1);
    // 0x800F2C34: bgezl       $t3, L_800F2CBC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800F2C38: lw          $s0, 0x0($s4)
        ctx->r16 = MEM_W(ctx->r20, 0X0);
            goto L_800F2CBC;
    }
    goto skip_9;
    // 0x800F2C38: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    skip_9:
    // 0x800F2C3C: lw          $t4, 0x20($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X20);
    // 0x800F2C40: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F2C44: beql        $t4, $at, L_800F2C80
    if (ctx->r12 == ctx->r1) {
        // 0x800F2C48: lw          $t6, 0x74($s6)
        ctx->r14 = MEM_W(ctx->r22, 0X74);
            goto L_800F2C80;
    }
    goto skip_10;
    // 0x800F2C48: lw          $t6, 0x74($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X74);
    skip_10:
    // 0x800F2C4C: lw          $t5, 0x44($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X44);
    // 0x800F2C50: lwc1        $f4, 0xA74($fp)
    ctx->f4.u32l = MEM_W(ctx->r30, 0XA74);
    // 0x800F2C54: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800F2C58: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800F2C5C: lw          $a2, 0xA78($fp)
    ctx->r6 = MEM_W(ctx->r30, 0XA78);
    // 0x800F2C60: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F2C64: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800F2C68: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800F2C6C: jal         0x800FCB70
    // 0x800F2C70: nop

    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_10;
    // 0x800F2C70: nop

    after_10:
    // 0x800F2C74: b           L_800F2CBC
    // 0x800F2C78: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
        goto L_800F2CBC;
    // 0x800F2C78: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2C7C: lw          $t6, 0x74($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X74);
L_800F2C80:
    // 0x800F2C80: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F2C84: lwc1        $f10, 0x268($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X268);
    // 0x800F2C88: lwc1        $f8, 0x34($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0X34);
    // 0x800F2C8C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800F2C90: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800F2C94: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800F2C98: lwc1        $f6, 0xA74($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0XA74);
    // 0x800F2C9C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800F2CA0: lw          $a2, 0xA78($fp)
    ctx->r6 = MEM_W(ctx->r30, 0XA78);
    // 0x800F2CA4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800F2CA8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F2CAC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800F2CB0: jal         0x800FCB70
    // 0x800F2CB4: nop

    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_11;
    // 0x800F2CB4: nop

    after_11:
    // 0x800F2CB8: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
L_800F2CBC:
    // 0x800F2CBC: lui         $s2, 0xE300
    ctx->r18 = S32(0XE300 << 16);
    // 0x800F2CC0: ori         $s2, $s2, 0xA01
    ctx->r18 = ctx->r18 | 0XA01;
    // 0x800F2CC4: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800F2CC8: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800F2CCC: lui         $t8, 0x10
    ctx->r24 = S32(0X10 << 16);
    // 0x800F2CD0: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800F2CD4: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x800F2CD8: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2CDC: lui         $t3, 0xD9FF
    ctx->r11 = S32(0XD9FF << 16);
    // 0x800F2CE0: lui         $t4, 0x22
    ctx->r12 = S32(0X22 << 16);
    // 0x800F2CE4: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800F2CE8: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800F2CEC: ori         $t4, $t4, 0x405
    ctx->r12 = ctx->r12 | 0X405;
    // 0x800F2CF0: ori         $t3, $t3, 0xFFFF
    ctx->r11 = ctx->r11 | 0XFFFF;
    // 0x800F2CF4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800F2CF8: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800F2CFC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2D00: lui         $s7, 0xE200
    ctx->r23 = S32(0XE200 << 16);
    // 0x800F2D04: lui         $t6, 0xC411
    ctx->r14 = S32(0XC411 << 16);
    // 0x800F2D08: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800F2D0C: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800F2D10: ori         $s7, $s7, 0x1C
    ctx->r23 = ctx->r23 | 0X1C;
    // 0x800F2D14: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x800F2D18: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800F2D1C: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x800F2D20: lw          $t7, 0xA88($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XA88);
    // 0x800F2D24: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x800F2D28: bgezl       $t9, L_800F2D80
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800F2D2C: lw          $t4, 0x190($fp)
        ctx->r12 = MEM_W(ctx->r30, 0X190);
            goto L_800F2D80;
    }
    goto skip_11;
    // 0x800F2D2C: lw          $t4, 0x190($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X190);
    skip_11:
    // 0x800F2D30: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2D34: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800F2D38: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800F2D3C: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800F2D40: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800F2D44: lbu         $t6, 0xA7C($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0XA7C);
    // 0x800F2D48: lbu         $t9, 0xA7D($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0XA7D);
    // 0x800F2D4C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x800F2D50: lbu         $t6, 0xA7E($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0XA7E);
    // 0x800F2D54: sll         $t3, $t9, 16
    ctx->r11 = S32(ctx->r25 << 16);
    // 0x800F2D58: or          $t4, $t7, $t3
    ctx->r12 = ctx->r15 | ctx->r11;
    // 0x800F2D5C: lbu         $t3, 0xA7F($fp)
    ctx->r11 = MEM_BU(ctx->r30, 0XA7F);
    // 0x800F2D60: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800F2D64: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x800F2D68: or          $t5, $t9, $t3
    ctx->r13 = ctx->r25 | ctx->r11;
    // 0x800F2D6C: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800F2D70: lbu         $t6, 0xA7F($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0XA7F);
    // 0x800F2D74: b           L_800F2E04
    // 0x800F2D78: sb          $t6, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r14;
        goto L_800F2E04;
    // 0x800F2D78: sb          $t6, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r14;
    // 0x800F2D7C: lw          $t4, 0x190($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X190);
L_800F2D80:
    // 0x800F2D80: sll         $t7, $t4, 20
    ctx->r15 = S32(ctx->r12 << 20);
    // 0x800F2D84: bgezl       $t7, L_800F2DDC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800F2D88: lw          $t3, 0x20($fp)
        ctx->r11 = MEM_W(ctx->r30, 0X20);
            goto L_800F2DDC;
    }
    goto skip_12;
    // 0x800F2D88: lw          $t3, 0x20($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X20);
    skip_12:
    // 0x800F2D8C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2D90: lui         $t3, 0xFB00
    ctx->r11 = S32(0XFB00 << 16);
    // 0x800F2D94: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800F2D98: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800F2D9C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800F2DA0: lbu         $t6, 0xA8C($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0XA8C);
    // 0x800F2DA4: lbu         $t7, 0xA8D($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0XA8D);
    // 0x800F2DA8: sll         $t4, $t6, 24
    ctx->r12 = S32(ctx->r14 << 24);
    // 0x800F2DAC: lbu         $t6, 0xA8E($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0XA8E);
    // 0x800F2DB0: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x800F2DB4: or          $t3, $t4, $t9
    ctx->r11 = ctx->r12 | ctx->r25;
    // 0x800F2DB8: lbu         $t9, 0xA8F($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0XA8F);
    // 0x800F2DBC: sll         $t8, $t6, 8
    ctx->r24 = S32(ctx->r14 << 8);
    // 0x800F2DC0: or          $t7, $t3, $t8
    ctx->r15 = ctx->r11 | ctx->r24;
    // 0x800F2DC4: or          $t5, $t7, $t9
    ctx->r13 = ctx->r15 | ctx->r25;
    // 0x800F2DC8: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800F2DCC: lbu         $t6, 0xA8F($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0XA8F);
    // 0x800F2DD0: b           L_800F2E04
    // 0x800F2DD4: sb          $t6, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r14;
        goto L_800F2E04;
    // 0x800F2DD4: sb          $t6, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r14;
    // 0x800F2DD8: lw          $t3, 0x20($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X20);
L_800F2DDC:
    // 0x800F2DDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F2DE0: beq         $t3, $at, L_800F2DF8
    if (ctx->r11 == ctx->r1) {
        // 0x800F2DE4: nop
    
            goto L_800F2DF8;
    }
    // 0x800F2DE4: nop

    // 0x800F2DE8: jal         0x800FC9C8
    // 0x800F2DEC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mpCollisionSetLightColorGetAlpha(rdram, ctx);
        goto after_12;
    // 0x800F2DEC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x800F2DF0: b           L_800F2E04
    // 0x800F2DF4: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
        goto L_800F2E04;
    // 0x800F2DF4: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_800F2DF8:
    // 0x800F2DF8: jal         0x80390534
    // 0x800F2DFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    scSubsysFighterDrawLightColorGetAlpha(rdram, ctx);
        goto after_13;
    // 0x800F2DFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_13:
    // 0x800F2E00: sb          $v0, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r2;
L_800F2E04:
    // 0x800F2E04: lw          $t8, 0xA88($fp)
    ctx->r24 = MEM_W(ctx->r30, 0XA88);
    // 0x800F2E08: srl         $t4, $t8, 31
    ctx->r12 = S32(U32(ctx->r24) >> 31);
    // 0x800F2E0C: beq         $t4, $zero, L_800F2E2C
    if (ctx->r12 == 0) {
        // 0x800F2E10: nop
    
            goto L_800F2E2C;
    }
    // 0x800F2E10: nop

    // 0x800F2E14: jal         0x800F17E8
    // 0x800F2E18: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    ftDisplayMainCalcFogColor(rdram, ctx);
        goto after_14;
    // 0x800F2E18: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_14:
    // 0x800F2E1C: jal         0x800F1B24
    // 0x800F2E20: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    ftDisplayMainSetFogColor(rdram, ctx);
        goto after_15;
    // 0x800F2E20: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_15:
    // 0x800F2E24: b           L_800F2E38
    // 0x800F2E28: lhu         $t7, 0x276($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X276);
        goto L_800F2E38;
    // 0x800F2E28: lhu         $t7, 0x276($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X276);
L_800F2E2C:
    // 0x800F2E2C: jal         0x800F1B7C
    // 0x800F2E30: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    ftDisplayMainDecideFogColor(rdram, ctx);
        goto after_16;
    // 0x800F2E30: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_16:
    // 0x800F2E34: lhu         $t7, 0x276($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X276);
L_800F2E38:
    // 0x800F2E38: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x800F2E3C: addiu       $s5, $s5, 0x65D8
    ctx->r21 = ADD32(ctx->r21, 0X65D8);
    // 0x800F2E40: beq         $t7, $zero, L_800F2E9C
    if (ctx->r15 == 0) {
        // 0x800F2E44: addiu       $a3, $zero, 0x0
        ctx->r7 = ADD32(0, 0X0);
            goto L_800F2E9C;
    }
    // 0x800F2E44: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800F2E48: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800F2E4C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F2E50: addiu       $t7, $t7, -0x46D0
    ctx->r15 = ADD32(ctx->r15, -0X46D0);
    // 0x800F2E54: addiu       $t9, $a0, 0x40
    ctx->r25 = ADD32(ctx->r4, 0X40);
    // 0x800F2E58: sw          $t9, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r25;
    // 0x800F2E5C: lbu         $t3, 0x272($fp)
    ctx->r11 = MEM_BU(ctx->r30, 0X272);
    // 0x800F2E60: lbu         $t5, 0x274($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0X274);
    // 0x800F2E64: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F2E68: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x800F2E6C: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800F2E70: addu        $t4, $t6, $t8
    ctx->r12 = ADD32(ctx->r14, ctx->r24);
    // 0x800F2E74: addu        $v0, $t4, $t7
    ctx->r2 = ADD32(ctx->r12, ctx->r15);
    // 0x800F2E78: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x800F2E7C: jal         0x8001B9C4
    // 0x800F2E80: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    syMatrixTra(rdram, ctx);
        goto after_17;
    // 0x800F2E80: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    after_17:
    // 0x800F2E84: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2E88: lui         $t5, 0xDA38
    ctx->r13 = S32(0XDA38 << 16);
    // 0x800F2E8C: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800F2E90: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800F2E94: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F2E98: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_800F2E9C:
    // 0x800F2E9C: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    // 0x800F2EA0: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x800F2EA4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F2EA8: beq         $v0, $at, L_800F2ED0
    if (ctx->r2 == ctx->r1) {
        // 0x800F2EAC: addiu       $s5, $s5, 0x65D8
        ctx->r21 = ADD32(ctx->r21, 0X65D8);
            goto L_800F2ED0;
    }
    // 0x800F2EAC: addiu       $s5, $s5, 0x65D8
    ctx->r21 = ADD32(ctx->r21, 0X65D8);
    // 0x800F2EB0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800F2EB4: beq         $v0, $at, L_800F2ED0
    if (ctx->r2 == ctx->r1) {
        // 0x800F2EB8: lui         $t3, 0x8004
        ctx->r11 = S32(0X8004 << 16);
            goto L_800F2ED0;
    }
    // 0x800F2EB8: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x800F2EBC: lw          $t3, 0x6A58($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6A58);
    // 0x800F2EC0: addiu       $at, $zero, 0x3EA
    ctx->r1 = ADD32(0, 0X3EA);
    // 0x800F2EC4: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x800F2EC8: bnel        $t6, $at, L_800F2EE4
    if (ctx->r14 != ctx->r1) {
        // 0x800F2ECC: lw          $t4, 0x8E8($fp)
        ctx->r12 = MEM_W(ctx->r30, 0X8E8);
            goto L_800F2EE4;
    }
    goto skip_13;
    // 0x800F2ECC: lw          $t4, 0x8E8($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X8E8);
    skip_13:
L_800F2ED0:
    // 0x800F2ED0: jal         0x800F24A0
    // 0x800F2ED4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    ftDisplayMainDrawAll(rdram, ctx);
        goto after_18;
    // 0x800F2ED4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_18:
    // 0x800F2ED8: b           L_800F2F0C
    // 0x800F2EDC: lhu         $t6, 0x276($fp)
    ctx->r14 = MEM_HU(ctx->r30, 0X276);
        goto L_800F2F0C;
    // 0x800F2EDC: lhu         $t6, 0x276($fp)
    ctx->r14 = MEM_HU(ctx->r30, 0X276);
    // 0x800F2EE0: lw          $t4, 0x8E8($fp)
    ctx->r12 = MEM_W(ctx->r30, 0X8E8);
L_800F2EE4:
    // 0x800F2EE4: addiu       $t8, $zero, 0x1A
    ctx->r24 = ADD32(0, 0X1A);
    // 0x800F2EE8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800F2EEC: lw          $t7, 0x58($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X58);
    // 0x800F2EF0: jal         0x800F24A0
    // 0x800F2EF4: sb          $t8, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r24;
    ftDisplayMainDrawAll(rdram, ctx);
        goto after_19;
    // 0x800F2EF4: sb          $t8, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r24;
    after_19:
    // 0x800F2EF8: lw          $t5, 0x8E8($fp)
    ctx->r13 = MEM_W(ctx->r30, 0X8E8);
    // 0x800F2EFC: addiu       $t9, $zero, 0x4B
    ctx->r25 = ADD32(0, 0X4B);
    // 0x800F2F00: lw          $t3, 0x58($t5)
    ctx->r11 = MEM_W(ctx->r13, 0X58);
    // 0x800F2F04: sb          $t9, 0x4($t3)
    MEM_B(0X4, ctx->r11) = ctx->r25;
    // 0x800F2F08: lhu         $t6, 0x276($fp)
    ctx->r14 = MEM_HU(ctx->r30, 0X276);
L_800F2F0C:
    // 0x800F2F0C: lui         $t8, 0xD838
    ctx->r24 = S32(0XD838 << 16);
    // 0x800F2F10: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800F2F14: beq         $t6, $zero, L_800F2F38
    if (ctx->r14 == 0) {
        // 0x800F2F18: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800F2F38;
    }
    // 0x800F2F18: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F2F1C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2F20: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x800F2F24: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x800F2F28: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800F2F2C: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800F2F30: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800F2F34: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800F2F38:
    // 0x800F2F38: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2F3C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800F2F40: lui         $t4, 0x55
    ctx->r12 = S32(0X55 << 16);
    // 0x800F2F44: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800F2F48: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800F2F4C: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800F2F50: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800F2F54: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2F58: ori         $t4, $t4, 0x2078
    ctx->r12 = ctx->r12 | 0X2078;
    // 0x800F2F5C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F2F60: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800F2F64: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800F2F68: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800F2F6C: sw          $s2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r18;
    // 0x800F2F70: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2F74: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800F2F78: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800F2F7C: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800F2F80: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800F2F84: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x800F2F88: lw          $t8, 0x20($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X20);
    // 0x800F2F8C: beq         $t8, $at, L_800F2FA8
    if (ctx->r24 == ctx->r1) {
        // 0x800F2F90: nop
    
            goto L_800F2FA8;
    }
    // 0x800F2F90: nop

    // 0x800F2F94: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    // 0x800F2F98: jal         0x800FCB70
    // 0x800F2F9C: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_20;
    // 0x800F2F9C: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    after_20:
    // 0x800F2FA0: b           L_800F2FCC
    // 0x800F2FA4: lw          $t7, 0xB4C($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XB4C);
        goto L_800F2FCC;
    // 0x800F2FA4: lw          $t7, 0xB4C($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XB4C);
L_800F2FA8:
    // 0x800F2FA8: jal         0x8039051C
    // 0x800F2FAC: nop

    scSubsysFighterGetLightAngleX(rdram, ctx);
        goto after_21;
    // 0x800F2FAC: nop

    after_21:
    // 0x800F2FB0: jal         0x80390528
    // 0x800F2FB4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    scSubsysFighterGetLightAngleY(rdram, ctx);
        goto after_22;
    // 0x800F2FB4: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    after_22:
    // 0x800F2FB8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F2FBC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800F2FC0: jal         0x800FCB70
    // 0x800F2FC4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_23;
    // 0x800F2FC4: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    after_23:
    // 0x800F2FC8: lw          $t7, 0xB4C($fp)
    ctx->r15 = MEM_W(ctx->r30, 0XB4C);
L_800F2FCC:
    // 0x800F2FCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F2FD0: bnel        $t7, $at, L_800F364C
    if (ctx->r15 != ctx->r1) {
        // 0x800F2FD4: lw          $v0, 0x20($fp)
        ctx->r2 = MEM_W(ctx->r30, 0X20);
            goto L_800F364C;
    }
    goto skip_14;
    // 0x800F2FD4: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
    skip_14:
    // 0x800F2FD8: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F2FDC: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800F2FE0: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800F2FE4: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800F2FE8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800F2FEC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800F2FF0: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800F2FF4: lw          $t6, 0x140($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X140);
    // 0x800F2FF8: addiu       $t3, $a0, 0x40
    ctx->r11 = ADD32(ctx->r4, 0X40);
    // 0x800F2FFC: sw          $t3, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r11;
    // 0x800F3000: lw          $v0, 0x74($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X74);
    // 0x800F3004: lwc1        $f16, 0xA4($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0XA4);
    // 0x800F3008: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F300C: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F3010: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x800F3014: lw          $a3, 0x24($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X24);
    // 0x800F3018: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F301C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x800F3020: jal         0x8001B9C4
    // 0x800F3024: nop

    syMatrixTra(rdram, ctx);
        goto after_24;
    // 0x800F3024: nop

    after_24:
    // 0x800F3028: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F302C: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x800F3030: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800F3034: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800F3038: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800F303C: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F3040: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800F3044: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800F3048: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x800F304C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F3050: addiu       $t7, $a0, 0x40
    ctx->r15 = ADD32(ctx->r4, 0X40);
    // 0x800F3054: sw          $t7, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r15;
    // 0x800F3058: lwc1        $f8, 0xA0($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0XA0);
    // 0x800F305C: lwc1        $f4, 0xA8($t5)
    ctx->f4.u32l = MEM_W(ctx->r13, 0XA8);
    // 0x800F3060: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800F3064: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800F3068: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F306C: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800F3070: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800F3074: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800F3078: jal         0x8001B780
    // 0x800F307C: nop

    syMatrixSca(rdram, ctx);
        goto after_25;
    // 0x800F307C: nop

    after_25:
    // 0x800F3080: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3084: lui         $t3, 0xDA38
    ctx->r11 = S32(0XDA38 << 16);
    // 0x800F3088: ori         $t3, $t3, 0x1
    ctx->r11 = ctx->r11 | 0X1;
    // 0x800F308C: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800F3090: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800F3094: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F3098: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800F309C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F30A0: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800F30A4: lui         $s7, 0xDE00
    ctx->r23 = S32(0XDE00 << 16);
    // 0x800F30A8: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800F30AC: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800F30B0: addiu       $t4, $t4, -0x3C28
    ctx->r12 = ADD32(ctx->r12, -0X3C28);
    // 0x800F30B4: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800F30B8: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x800F30BC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F30C0: lui         $t7, 0xD838
    ctx->r15 = S32(0XD838 << 16);
    // 0x800F30C4: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800F30C8: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800F30CC: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800F30D0: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800F30D4: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800F30D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800F30DC: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800F30E0: lw          $t3, 0x140($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X140);
    // 0x800F30E4: addiu       $t9, $a0, 0x40
    ctx->r25 = ADD32(ctx->r4, 0X40);
    // 0x800F30E8: sw          $t9, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r25;
    // 0x800F30EC: lw          $v0, 0x74($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X74);
    // 0x800F30F0: lwc1        $f18, 0xA0($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0XA0);
    // 0x800F30F4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F30F8: lwc1        $f16, 0x20($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F30FC: lw          $a1, 0x1C($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X1C);
    // 0x800F3100: lw          $a3, 0x24($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X24);
    // 0x800F3104: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800F3108: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800F310C: jal         0x8001B9C4
    // 0x800F3110: nop

    syMatrixTra(rdram, ctx);
        goto after_26;
    // 0x800F3110: nop

    after_26:
    // 0x800F3114: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3118: lui         $t4, 0xDA38
    ctx->r12 = S32(0XDA38 << 16);
    // 0x800F311C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800F3120: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800F3124: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800F3128: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F312C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800F3130: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800F3134: lw          $t7, 0x140($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X140);
    // 0x800F3138: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F313C: addiu       $t8, $a0, 0x40
    ctx->r24 = ADD32(ctx->r4, 0X40);
    // 0x800F3140: sw          $t8, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r24;
    // 0x800F3144: lwc1        $f16, 0xA0($t7)
    ctx->f16.u32l = MEM_W(ctx->r15, 0XA0);
    // 0x800F3148: lwc1        $f10, 0x9C($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X9C);
    // 0x800F314C: lwc1        $f6, 0xA8($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0XA8);
    // 0x800F3150: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x800F3154: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800F3158: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F315C: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800F3160: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800F3164: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x800F3168: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800F316C: jal         0x8001B780
    // 0x800F3170: nop

    syMatrixSca(rdram, ctx);
        goto after_27;
    // 0x800F3170: nop

    after_27:
    // 0x800F3174: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3178: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800F317C: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x800F3180: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800F3184: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800F3188: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F318C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800F3190: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3194: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F3198: addiu       $t6, $t6, -0x3BA8
    ctx->r14 = ADD32(ctx->r14, -0X3BA8);
    // 0x800F319C: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800F31A0: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800F31A4: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800F31A8: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x800F31AC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F31B0: lui         $t8, 0xD838
    ctx->r24 = S32(0XD838 << 16);
    // 0x800F31B4: ori         $t8, $t8, 0x2
    ctx->r24 = ctx->r24 | 0X2;
    // 0x800F31B8: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800F31BC: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800F31C0: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x800F31C4: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800F31C8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800F31CC: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800F31D0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F31D4: lui         $t3, 0xE700
    ctx->r11 = S32(0XE700 << 16);
    // 0x800F31D8: addiu       $t5, $a0, 0x40
    ctx->r13 = ADD32(ctx->r4, 0X40);
    // 0x800F31DC: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800F31E0: sw          $t5, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r13;
    // 0x800F31E4: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800F31E8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800F31EC: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800F31F0: lw          $t6, 0x44($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X44);
    // 0x800F31F4: lwc1        $f6, 0xC4($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0XC4);
    // 0x800F31F8: lw          $v0, 0x74($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X74);
    // 0x800F31FC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800F3200: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F3204: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800F3208: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F320C: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F3210: lw          $a3, 0x24($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X24);
    // 0x800F3214: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800F3218: lwc1        $f6, 0xC8($fp)
    ctx->f6.u32l = MEM_W(ctx->r30, 0XC8);
    // 0x800F321C: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800F3220: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800F3224: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800F3228: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800F322C: jal         0x8001B9C4
    // 0x800F3230: nop

    syMatrixTra(rdram, ctx);
        goto after_28;
    // 0x800F3230: nop

    after_28:
    // 0x800F3234: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3238: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800F323C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800F3240: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800F3244: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800F3248: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x800F324C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x800F3250: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F3254: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800F3258: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800F325C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F3260: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800F3264: addiu       $t7, $a0, 0x40
    ctx->r15 = ADD32(ctx->r4, 0X40);
    // 0x800F3268: sw          $t7, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r15;
    // 0x800F326C: jal         0x8001B780
    // 0x800F3270: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    syMatrixSca(rdram, ctx);
        goto after_29;
    // 0x800F3270: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    after_29:
    // 0x800F3274: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3278: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800F327C: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x800F3280: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800F3284: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800F3288: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F328C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800F3290: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3294: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800F3298: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800F329C: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800F32A0: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800F32A4: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x800F32A8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800F32AC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F32B0: lui         $t5, 0xD000
    ctx->r13 = S32(0XD000 << 16);
    // 0x800F32B4: ori         $t5, $t5, 0xD0FF
    ctx->r13 = ctx->r13 | 0XD0FF;
    // 0x800F32B8: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800F32BC: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800F32C0: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800F32C4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800F32C8: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800F32CC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F32D0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800F32D4: addiu       $t3, $t3, -0x3FA8
    ctx->r11 = ADD32(ctx->r11, -0X3FA8);
    // 0x800F32D8: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800F32DC: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800F32E0: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800F32E4: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x800F32E8: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F32EC: lui         $t4, 0xD838
    ctx->r12 = S32(0XD838 << 16);
    // 0x800F32F0: ori         $t4, $t4, 0x2
    ctx->r12 = ctx->r12 | 0X2;
    // 0x800F32F4: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800F32F8: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800F32FC: addiu       $t8, $zero, 0x40
    ctx->r24 = ADD32(0, 0X40);
    // 0x800F3300: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800F3304: b           L_800F3648
    // 0x800F3308: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
        goto L_800F3648;
    // 0x800F3308: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_800F330C:
    // 0x800F330C: lw          $t7, 0x6A58($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A58);
    // 0x800F3310: addiu       $at, $zero, 0x3EA
    ctx->r1 = ADD32(0, 0X3EA);
    // 0x800F3314: lw          $t5, 0x0($t7)
    ctx->r13 = MEM_W(ctx->r15, 0X0);
    // 0x800F3318: bnel        $t5, $at, L_800F3334
    if (ctx->r13 != ctx->r1) {
        // 0x800F331C: lw          $t3, 0x8E8($fp)
        ctx->r11 = MEM_W(ctx->r30, 0X8E8);
            goto L_800F3334;
    }
    goto skip_15;
    // 0x800F331C: lw          $t3, 0x8E8($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X8E8);
    skip_15:
    // 0x800F3320: jal         0x800F2584
    // 0x800F3324: lw          $a0, 0x74($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X74);
    ftDisplayMainDrawParts(rdram, ctx);
        goto after_30;
    // 0x800F3324: lw          $a0, 0x74($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X74);
    after_30:
    // 0x800F3328: b           L_800F3358
    // 0x800F332C: nop

        goto L_800F3358;
    // 0x800F332C: nop

    // 0x800F3330: lw          $t3, 0x8E8($fp)
    ctx->r11 = MEM_W(ctx->r30, 0X8E8);
L_800F3334:
    // 0x800F3334: addiu       $t9, $zero, 0x1A
    ctx->r25 = ADD32(0, 0X1A);
    // 0x800F3338: lw          $t6, 0x58($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X58);
    // 0x800F333C: sb          $t9, 0x4($t6)
    MEM_B(0X4, ctx->r14) = ctx->r25;
    // 0x800F3340: jal         0x800F2584
    // 0x800F3344: lw          $a0, 0x74($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X74);
    ftDisplayMainDrawParts(rdram, ctx);
        goto after_31;
    // 0x800F3344: lw          $a0, 0x74($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X74);
    after_31:
    // 0x800F3348: lw          $t8, 0x8E8($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X8E8);
    // 0x800F334C: addiu       $t4, $zero, 0x4B
    ctx->r12 = ADD32(0, 0X4B);
    // 0x800F3350: lw          $t7, 0x58($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X58);
    // 0x800F3354: sb          $t4, 0x4($t7)
    MEM_B(0X4, ctx->r15) = ctx->r12;
L_800F3358:
    // 0x800F3358: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x800F335C: addiu       $s5, $s5, 0x65D8
    ctx->r21 = ADD32(ctx->r21, 0X65D8);
    // 0x800F3360: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800F3364: or          $s6, $fp, $zero
    ctx->r22 = ctx->r30 | 0;
    // 0x800F3368: lui         $s7, 0xDE00
    ctx->r23 = S32(0XDE00 << 16);
L_800F336C:
    // 0x800F336C: lw          $t5, 0x294($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X294);
    // 0x800F3370: addiu       $s2, $s6, 0x294
    ctx->r18 = ADD32(ctx->r22, 0X294);
    // 0x800F3374: beql        $t5, $zero, L_800F3634
    if (ctx->r13 == 0) {
        // 0x800F3378: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800F3634;
    }
    goto skip_16;
    // 0x800F3378: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_16:
    // 0x800F337C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800F3380: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F3384: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800F3388: beql        $t3, $at, L_800F3634
    if (ctx->r11 == ctx->r1) {
        // 0x800F338C: lw          $t3, 0x58($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X58);
            goto L_800F3634;
    }
    goto skip_17;
    // 0x800F338C: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
    skip_17:
    // 0x800F3390: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3394: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F3398: addiu       $t8, $t8, -0x3CF0
    ctx->r24 = ADD32(ctx->r24, -0X3CF0);
    // 0x800F339C: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800F33A0: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800F33A4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800F33A8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800F33AC: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x800F33B0: lw          $t4, 0xB4C($fp)
    ctx->r12 = MEM_W(ctx->r30, 0XB4C);
    // 0x800F33B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800F33B8: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800F33BC: bne         $t4, $at, L_800F3418
    if (ctx->r12 != ctx->r1) {
        // 0x800F33C0: lui         $t9, 0xFA00
        ctx->r25 = S32(0XFA00 << 16);
            goto L_800F3418;
    }
    // 0x800F33C0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800F33C4: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F33C8: lui         $t3, 0xB000
    ctx->r11 = S32(0XB000 << 16);
    // 0x800F33CC: ori         $t3, $t3, 0xFF
    ctx->r11 = ctx->r11 | 0XFF;
    // 0x800F33D0: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x800F33D4: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800F33D8: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800F33DC: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x800F33E0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F33E4: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800F33E8: addiu       $t5, $zero, 0xE0
    ctx->r13 = ADD32(0, 0XE0);
    // 0x800F33EC: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800F33F0: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800F33F4: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x800F33F8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800F33FC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3400: lui         $t7, 0xF900
    ctx->r15 = S32(0XF900 << 16);
    // 0x800F3404: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800F3408: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800F340C: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800F3410: b           L_800F3468
    // 0x800F3414: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_800F3468;
    // 0x800F3414: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_800F3418:
    // 0x800F3418: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F341C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800F3420: lui         $t7, 0xB000
    ctx->r15 = S32(0XB000 << 16);
    // 0x800F3424: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800F3428: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800F342C: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x800F3430: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800F3434: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3438: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x800F343C: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800F3440: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x800F3444: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800F3448: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x800F344C: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x800F3450: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3454: lui         $t3, 0xF900
    ctx->r11 = S32(0XF900 << 16);
    // 0x800F3458: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x800F345C: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800F3460: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x800F3464: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_800F3468:
    // 0x800F3468: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800F346C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F3470: bnel        $t9, $at, L_800F3548
    if (ctx->r25 != ctx->r1) {
        // 0x800F3474: lw          $a0, 0xC($s5)
        ctx->r4 = MEM_W(ctx->r21, 0XC);
            goto L_800F3548;
    }
    goto skip_18;
    // 0x800F3474: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    skip_18:
    // 0x800F3478: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800F347C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F3480: addiu       $t8, $t8, -0x3ED8
    ctx->r24 = ADD32(ctx->r24, -0X3ED8);
    // 0x800F3484: addiu       $t6, $a0, 0x40
    ctx->r14 = ADD32(ctx->r4, 0X40);
    // 0x800F3488: sw          $t6, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r14;
    // 0x800F348C: lw          $a3, 0x58($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X58);
    // 0x800F3490: lw          $a2, 0x54($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X54);
    // 0x800F3494: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x800F3498: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800F349C: jal         0x8001B9C4
    // 0x800F34A0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    syMatrixTra(rdram, ctx);
        goto after_32;
    // 0x800F34A0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    after_32:
    // 0x800F34A4: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F34A8: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x800F34AC: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800F34B0: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800F34B4: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800F34B8: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F34BC: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800F34C0: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800F34C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800F34C8: addiu       $t5, $a0, 0x40
    ctx->r13 = ADD32(ctx->r4, 0X40);
    // 0x800F34CC: sw          $t5, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r13;
    // 0x800F34D0: lwc1        $f18, 0x24($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800F34D4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F34D8: div.s       $f0, $f18, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800F34DC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800F34E0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F34E4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800F34E8: jal         0x8001B780
    // 0x800F34EC: nop

    syMatrixSca(rdram, ctx);
        goto after_33;
    // 0x800F34EC: nop

    after_33:
    // 0x800F34F0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F34F4: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x800F34F8: ori         $t9, $t9, 0x1
    ctx->r25 = ctx->r25 | 0X1;
    // 0x800F34FC: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800F3500: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800F3504: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F3508: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x800F350C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3510: lui         $t7, 0xD838
    ctx->r15 = S32(0XD838 << 16);
    // 0x800F3514: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800F3518: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800F351C: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800F3520: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x800F3524: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x800F3528: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800F352C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800F3530: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3534: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800F3538: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800F353C: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800F3540: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800F3544: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
L_800F3548:
    // 0x800F3548: addiu       $t3, $a0, 0x40
    ctx->r11 = ADD32(ctx->r4, 0X40);
    // 0x800F354C: sw          $t3, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r11;
    // 0x800F3550: lw          $a3, 0x4C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X4C);
    // 0x800F3554: lw          $a2, 0x48($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X48);
    // 0x800F3558: lw          $a1, 0x44($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X44);
    // 0x800F355C: jal         0x8001B9C4
    // 0x800F3560: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    syMatrixTra(rdram, ctx);
        goto after_34;
    // 0x800F3560: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    after_34:
    // 0x800F3564: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3568: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x800F356C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x800F3570: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x800F3574: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800F3578: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F357C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x800F3580: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x800F3584: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800F3588: addiu       $t8, $a0, 0x40
    ctx->r24 = ADD32(ctx->r4, 0X40);
    // 0x800F358C: sw          $t8, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r24;
    // 0x800F3590: lwc1        $f4, 0x24($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800F3594: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800F3598: div.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800F359C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800F35A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x800F35A4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800F35A8: jal         0x8001B780
    // 0x800F35AC: nop

    syMatrixSca(rdram, ctx);
        goto after_35;
    // 0x800F35AC: nop

    after_35:
    // 0x800F35B0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F35B4: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x800F35B8: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x800F35BC: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800F35C0: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800F35C4: sw          $s3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r19;
    // 0x800F35C8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800F35CC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800F35D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800F35D4: bnel        $t5, $at, L_800F35FC
    if (ctx->r13 != ctx->r1) {
        // 0x800F35D8: lw          $s0, 0x0($s4)
        ctx->r16 = MEM_W(ctx->r20, 0X0);
            goto L_800F35FC;
    }
    goto skip_19;
    // 0x800F35D8: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    skip_19:
    // 0x800F35DC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F35E0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800F35E4: addiu       $t9, $t9, -0x3EA0
    ctx->r25 = ADD32(ctx->r25, -0X3EA0);
    // 0x800F35E8: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x800F35EC: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800F35F0: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x800F35F4: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x800F35F8: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
L_800F35FC:
    // 0x800F35FC: lui         $t7, 0xD838
    ctx->r15 = S32(0XD838 << 16);
    // 0x800F3600: ori         $t7, $t7, 0x2
    ctx->r15 = ctx->r15 | 0X2;
    // 0x800F3604: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x800F3608: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800F360C: sw          $s7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r23;
    // 0x800F3610: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800F3614: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800F3618: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x800F361C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800F3620: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x800F3624: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800F3628: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x800F362C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800F3630: lw          $t3, 0x58($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X58);
L_800F3634:
    // 0x800F3634: addiu       $at, $zero, 0x310
    ctx->r1 = ADD32(0, 0X310);
    // 0x800F3638: addiu       $s6, $s6, 0xC4
    ctx->r22 = ADD32(ctx->r22, 0XC4);
    // 0x800F363C: addiu       $t9, $t3, 0xC4
    ctx->r25 = ADD32(ctx->r11, 0XC4);
    // 0x800F3640: bne         $t9, $at, L_800F336C
    if (ctx->r25 != ctx->r1) {
        // 0x800F3644: sw          $t9, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r25;
            goto L_800F336C;
    }
    // 0x800F3644: sw          $t9, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r25;
L_800F3648:
    // 0x800F3648: lw          $v0, 0x20($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X20);
L_800F364C:
    // 0x800F364C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F3650: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800F3654: beq         $v0, $zero, L_800F366C
    if (ctx->r2 == 0) {
        // 0x800F3658: nop
    
            goto L_800F366C;
    }
    // 0x800F3658: nop

    // 0x800F365C: beq         $v0, $at, L_800F366C
    if (ctx->r2 == ctx->r1) {
        // 0x800F3660: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800F366C;
    }
    // 0x800F3660: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800F3664: bnel        $v0, $at, L_800F36AC
    if (ctx->r2 != ctx->r1) {
        // 0x800F3668: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800F36AC;
    }
    goto skip_20;
    // 0x800F3668: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_20:
L_800F366C:
    // 0x800F366C: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x800F3670: addiu       $at, $zero, 0x3EA
    ctx->r1 = ADD32(0, 0X3EA);
    // 0x800F3674: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800F3678: beql        $t8, $at, L_800F36AC
    if (ctx->r24 == ctx->r1) {
        // 0x800F367C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800F36AC;
    }
    goto skip_21;
    // 0x800F367C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_21:
    // 0x800F3680: lw          $v0, 0x18C($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X18C);
    // 0x800F3684: sll         $t7, $v0, 18
    ctx->r15 = S32(ctx->r2 << 18);
    // 0x800F3688: bltz        $t7, L_800F36A8
    if (SIGNED(ctx->r15) < 0) {
        // 0x800F368C: sll         $t3, $v0, 17
        ctx->r11 = S32(ctx->r2 << 17);
            goto L_800F36A8;
    }
    // 0x800F368C: sll         $t3, $v0, 17
    ctx->r11 = S32(ctx->r2 << 17);
    // 0x800F3690: bltz        $t3, L_800F36A8
    if (SIGNED(ctx->r11) < 0) {
        // 0x800F3694: sll         $t6, $v0, 13
        ctx->r14 = S32(ctx->r2 << 13);
            goto L_800F36A8;
    }
    // 0x800F3694: sll         $t6, $v0, 13
    ctx->r14 = S32(ctx->r2 << 13);
    // 0x800F3698: bgezl       $t6, L_800F36AC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800F369C: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800F36AC;
    }
    goto skip_22;
    // 0x800F369C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    skip_22:
    // 0x800F36A0: jal         0x801111A0
    // 0x800F36A4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    ifCommonPlayerMagnifyProcDisplay(rdram, ctx);
        goto after_36;
    // 0x800F36A4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_36:
L_800F36A8:
    // 0x800F36A8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800F36AC:
    // 0x800F36AC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800F36B0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800F36B4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800F36B8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800F36BC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800F36C0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800F36C4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800F36C8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800F36CC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800F36D0: jr          $ra
    // 0x800F36D4: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
    return;
    // 0x800F36D4: addiu       $sp, $sp, 0x148
    ctx->r29 = ADD32(ctx->r29, 0X148);
;}
RECOMP_FUNC void wpProcessUpdateAttackRecords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801661E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801661E4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801661E8: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x801661EC: lw          $t6, 0x100($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X100);
    // 0x801661F0: addiu       $a1, $v0, 0x100
    ctx->r5 = ADD32(ctx->r2, 0X100);
    // 0x801661F4: beq         $t6, $zero, L_801662B4
    if (ctx->r14 == 0) {
        // 0x801661F8: nop
    
            goto L_801662B4;
    }
    // 0x801661F8: nop

L_801661FC:
    // 0x801661FC: lw          $t7, 0x114($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X114);
    // 0x80166200: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80166204: addiu       $v1, $a1, 0x114
    ctx->r3 = ADD32(ctx->r5, 0X114);
    // 0x80166208: beq         $t7, $zero, L_801662AC
    if (ctx->r15 == 0) {
        // 0x8016620C: nop
    
            goto L_801662AC;
    }
    // 0x8016620C: nop

    // 0x80166210: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80166214: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
    // 0x80166218: srl         $v0, $v0, 26
    ctx->r2 = S32(U32(ctx->r2) >> 26);
    // 0x8016621C: beq         $v0, $zero, L_801662AC
    if (ctx->r2 == 0) {
        // 0x80166220: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_801662AC;
    }
    // 0x80166220: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80166224: lhu         $t1, 0x4($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X4);
    // 0x80166228: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8016622C: andi        $t0, $t9, 0x1F8
    ctx->r8 = ctx->r25 & 0X1F8;
    // 0x80166230: andi        $t2, $t1, 0xFE07
    ctx->r10 = ctx->r9 & 0XFE07;
    // 0x80166234: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x80166238: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x8016623C: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x80166240: sll         $t5, $t4, 7
    ctx->r13 = S32(ctx->r12 << 7);
    // 0x80166244: srl         $t6, $t5, 26
    ctx->r14 = S32(U32(ctx->r13) >> 26);
    // 0x80166248: bne         $t6, $zero, L_801662AC
    if (ctx->r14 != 0) {
        // 0x8016624C: nop
    
            goto L_801662AC;
    }
    // 0x8016624C: nop

    // 0x80166250: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x80166254: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80166258: andi        $t0, $t7, 0xFFEF
    ctx->r8 = ctx->r15 & 0XFFEF;
    // 0x8016625C: sb          $t0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r8;
    // 0x80166260: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x80166264: andi        $t2, $t0, 0xDF
    ctx->r10 = ctx->r8 & 0XDF;
    // 0x80166268: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x8016626C: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80166270: sll         $t9, $v0, 5
    ctx->r25 = S32(ctx->r2 << 5);
    // 0x80166274: andi        $t1, $t9, 0x20
    ctx->r9 = ctx->r25 & 0X20;
    // 0x80166278: or          $t6, $t1, $t2
    ctx->r14 = ctx->r9 | ctx->r10;
    // 0x8016627C: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x80166280: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x80166284: andi        $t7, $t6, 0xBF
    ctx->r15 = ctx->r14 & 0XBF;
    // 0x80166288: or          $t1, $t5, $t7
    ctx->r9 = ctx->r13 | ctx->r15;
    // 0x8016628C: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x80166290: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
    // 0x80166294: sll         $t0, $v0, 7
    ctx->r8 = S32(ctx->r2 << 7);
    // 0x80166298: or          $t6, $t0, $t2
    ctx->r14 = ctx->r8 | ctx->r10;
    // 0x8016629C: sb          $t1, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r9;
    // 0x801662A0: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
    // 0x801662A4: ori         $t5, $t6, 0xE
    ctx->r13 = ctx->r14 | 0XE;
    // 0x801662A8: sb          $t5, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r13;
L_801662AC:
    // 0x801662AC: bne         $a0, $a2, L_801661FC
    if (ctx->r4 != ctx->r6) {
        // 0x801662B0: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_801661FC;
    }
    // 0x801662B0: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_801662B4:
    // 0x801662B4: jr          $ra
    // 0x801662B8: nop

    return;
    // 0x801662B8: nop

;}
RECOMP_FUNC void itMBallOpenAirProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CDAC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017CDB0: lwc1        $f0, -0x3204($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3204);
    // 0x8017CDB4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017CDB8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017CDBC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8017CDC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8017CDC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017CDC8: jal         0x80173B24
    // 0x8017CDCC: addiu       $a3, $a3, -0x3378
    ctx->r7 = ADD32(ctx->r7, -0X3378);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x8017CDCC: addiu       $a3, $a3, -0x3378
    ctx->r7 = ADD32(ctx->r7, -0X3378);
    after_0:
    // 0x8017CDD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CDD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CDD8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017CDDC: jr          $ra
    // 0x8017CDE0: nop

    return;
    // 0x8017CDE0: nop

;}
RECOMP_FUNC void ftNessSpecialHiHoldSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801542A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801542AC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801542B0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801542B4: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x801542B8: jal         0x800DEEC8
    // 0x801542BC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801542BC: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x801542C0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801542C4: addiu       $t7, $zero, 0x4897
    ctx->r15 = ADD32(0, 0X4897);
    // 0x801542C8: addiu       $a1, $zero, 0xE9
    ctx->r5 = ADD32(0, 0XE9);
    // 0x801542CC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801542D0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801542D4: jal         0x800E6F24
    // 0x801542D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801542D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801542DC: jal         0x800D8EB8
    // 0x801542E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x801542E0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x801542E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801542E8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801542EC: jr          $ra
    // 0x801542F0: nop

    return;
    // 0x801542F0: nop

;}
RECOMP_FUNC void mvOpeningFighterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801322A4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801322A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801322AC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801322B0: jal         0x803905F4
    // 0x801322B4: lw          $a0, 0x4CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF4);
    scSubsysFighterOpeningProcUpdate(rdram, ctx);
        goto after_0;
    // 0x801322B4: lw          $a0, 0x4CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4CF4);
    after_0:
    // 0x801322B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801322BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801322C0: jr          $ra
    // 0x801322C4: nop

    return;
    // 0x801322C4: nop

;}
RECOMP_FUNC void sySchedulerPrepTask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800024EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800024F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800024F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800024F8: jal         0x80000C64
    // 0x800024FC: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    sySchedulerAddMainQueue(rdram, ctx);
        goto after_0;
    // 0x800024FC: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    after_0:
    // 0x80002500: jal         0x80001E64
    // 0x80002504: nop

    sySchedulerExecuteTasksAll(rdram, ctx);
        goto after_1;
    // 0x80002504: nop

    after_1:
    // 0x80002508: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000250C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002510: jr          $ra
    // 0x80002514: nop

    return;
    // 0x80002514: nop

;}
RECOMP_FUNC void ftCommonAttack11ProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014EA04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014EA08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014EA0C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8014EA10: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8014EA14: jal         0x800EA5E8
    // 0x8014EA18: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftParamSetMotionID(rdram, ctx);
        goto after_0;
    // 0x8014EA18: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014EA1C: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8014EA20: jal         0x800EA778
    // 0x8014EA24: lhu         $a1, 0x28E($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X28E);
    ftParamSetStatUpdate(rdram, ctx);
        goto after_1;
    // 0x8014EA24: lhu         $a1, 0x28E($a0)
    ctx->r5 = MEM_HU(ctx->r4, 0X28E);
    after_1:
    // 0x8014EA28: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8014EA2C: jal         0x800EA7B0
    // 0x8014EA30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamUpdate1PGameAttackStats(rdram, ctx);
        goto after_2;
    // 0x8014EA30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8014EA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014EA38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014EA3C: jr          $ra
    // 0x8014EA40: nop

    return;
    // 0x8014EA40: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakePortraitFlashCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013305C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133060: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133064: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133068: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013306C: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x80133070: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80133074: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80133078: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013307C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133080: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133084: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133088: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013308C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80133090: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133094: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133098: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013309C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801330A0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801330A4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801330A8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801330AC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801330B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801330B4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801330B8: jal         0x8000B93C
    // 0x801330BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801330BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801330C0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801330C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801330C8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801330CC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801330D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801330D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801330D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801330DC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801330E0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801330E4: jal         0x80007080
    // 0x801330E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801330E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801330EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801330F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801330F4: jr          $ra
    // 0x801330F8: nop

    return;
    // 0x801330F8: nop

;}
RECOMP_FUNC void ifCommonPlayerMagnifyMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111440: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80111444: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80111448: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x8011144C: lw          $s1, 0x66FC($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X66FC);
    // 0x80111450: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80111454: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80111458: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8011145C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80111460: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80111464: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80111468: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8011146C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80111470: beq         $s1, $zero, L_8011151C
    if (ctx->r17 == 0) {
        // 0x80111474: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8011151C;
    }
    // 0x80111474: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80111478: lui         $s4, 0x0
    ctx->r20 = S32(0X0 << 16);
    // 0x8011147C: lui         $s7, 0x800A
    ctx->r23 = S32(0X800A << 16);
    // 0x80111480: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x80111484: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80111488: addiu       $s3, $s3, 0x1748
    ctx->r19 = ADD32(ctx->r19, 0X1748);
    // 0x8011148C: addiu       $s6, $s6, 0xD40
    ctx->r22 = ADD32(ctx->r22, 0XD40);
    // 0x80111490: addiu       $s7, $s7, 0x50E8
    ctx->r23 = ADD32(ctx->r23, 0X50E8);
    // 0x80111494: addiu       $s4, $s4, 0x30
    ctx->r20 = ADD32(ctx->r20, 0X30);
    // 0x80111498: addiu       $fp, $zero, 0x74
    ctx->r30 = ADD32(0, 0X74);
    // 0x8011149C: lui         $s5, 0x8000
    ctx->r21 = S32(0X8000 << 16);
    // 0x801114A0: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
L_801114A4:
    // 0x801114A4: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x801114A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801114AC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    // 0x801114B0: jal         0x80009968
    // 0x801114B4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801114B4: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_0:
    // 0x801114B8: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x801114BC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x801114C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801114C4: jal         0x800092D0
    // 0x801114C8: addu        $a1, $t6, $s4
    ctx->r5 = ADD32(ctx->r14, ctx->r20);
    gcAddDObjForGObj(rdram, ctx);
        goto after_1;
    // 0x801114C8: addu        $a1, $t6, $s4
    ctx->r5 = ADD32(ctx->r14, ctx->r20);
    after_1:
    // 0x801114CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801114D0: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x801114D4: jal         0x80008CC0
    // 0x801114D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x801114D8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x801114DC: lbu         $t7, 0xD($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0XD);
    // 0x801114E0: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x801114E4: addu        $t9, $s3, $t8
    ctx->r25 = ADD32(ctx->r19, ctx->r24);
    // 0x801114E8: sw          $s2, 0x18($t9)
    MEM_W(0X18, ctx->r25) = ctx->r18;
    // 0x801114EC: lbu         $v1, 0xD($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XD);
    // 0x801114F0: lw          $t0, 0x0($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X0);
    // 0x801114F4: multu       $v1, $fp
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r30)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801114F8: sll         $t4, $v1, 5
    ctx->r12 = S32(ctx->r3 << 5);
    // 0x801114FC: addu        $t5, $s3, $t4
    ctx->r13 = ADD32(ctx->r19, ctx->r12);
    // 0x80111500: mflo        $t1
    ctx->r9 = lo;
    // 0x80111504: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80111508: lbu         $t3, 0x28($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X28);
    // 0x8011150C: sb          $t3, 0x1C($t5)
    MEM_B(0X1C, ctx->r13) = ctx->r11;
    // 0x80111510: lw          $s1, 0x4($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X4);
    // 0x80111514: bnel        $s1, $zero, L_801114A4
    if (ctx->r17 != 0) {
        // 0x80111518: lw          $s0, 0x84($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X84);
            goto L_801114A4;
    }
    goto skip_0;
    // 0x80111518: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
    skip_0:
L_8011151C:
    // 0x8011151C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80111520: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80111524: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80111528: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8011152C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80111530: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80111534: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80111538: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8011153C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80111540: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80111544: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80111548: sb          $zero, 0x1580($at)
    MEM_B(0X1580, ctx->r1) = 0;
    // 0x8011154C: jr          $ra
    // 0x80111550: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80111550: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void efManagerCatchSwirlMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80101500: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80101504: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80101508: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010150C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80101510: jal         0x800FDAFC
    // 0x80101514: addiu       $a0, $a0, -0x1E7C
    ctx->r4 = ADD32(ctx->r4, -0X1E7C);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80101514: addiu       $a0, $a0, -0x1E7C
    ctx->r4 = ADD32(ctx->r4, -0X1E7C);
    after_0:
    // 0x80101518: bne         $v0, $zero, L_80101528
    if (ctx->r2 != 0) {
        // 0x8010151C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80101528;
    }
    // 0x8010151C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80101520: b           L_8010154C
    // 0x80101524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8010154C;
    // 0x80101524: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80101528:
    // 0x80101528: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8010152C: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80101530: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80101534: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80101538: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x8010153C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80101540: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x80101544: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80101548: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_8010154C:
    // 0x8010154C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80101550: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80101554: jr          $ra
    // 0x80101558: nop

    return;
    // 0x80101558: nop

;}
RECOMP_FUNC void func_ovl3_80173E9C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173E9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173EA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173EA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80173EA8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80173EAC: jal         0x801737B8
    // 0x80173EB0: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80173EB0: addiu       $a1, $zero, 0xC21
    ctx->r5 = ADD32(0, 0XC21);
    after_0:
    // 0x80173EB4: beq         $v0, $zero, L_80173ED4
    if (ctx->r2 == 0) {
        // 0x80173EB8: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_80173ED4;
    }
    // 0x80173EB8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80173EBC: beq         $v1, $zero, L_80173ECC
    if (ctx->r3 == 0) {
        // 0x80173EC0: nop
    
            goto L_80173ECC;
    }
    // 0x80173EC0: nop

    // 0x80173EC4: jalr        $v1
    // 0x80173EC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x80173EC8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80173ECC:
    // 0x80173ECC: b           L_80173ED8
    // 0x80173ED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80173ED8;
    // 0x80173ED0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80173ED4:
    // 0x80173ED4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80173ED8:
    // 0x80173ED8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80173EDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80173EE0: jr          $ra
    // 0x80173EE4: nop

    return;
    // 0x80173EE4: nop

;}
RECOMP_FUNC void grSectorArwingWeaponLaser3DMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801076E8: addiu       $sp, $sp, -0xD0
    ctx->r29 = ADD32(ctx->r29, -0XD0);
    // 0x801076EC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801076F0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x801076F4: lw          $s0, 0x13F8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X13F8);
    // 0x801076F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801076FC: addiu       $a1, $sp, 0x94
    ctx->r5 = ADD32(ctx->r29, 0X94);
    // 0x80107700: addiu       $a2, $sp, 0x88
    ctx->r6 = ADD32(ctx->r29, 0X88);
    // 0x80107704: addiu       $a3, $sp, 0x7C
    ctx->r7 = ADD32(ctx->r29, 0X7C);
    // 0x80107708: jal         0x80106730
    // 0x8010770C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl2_80106730(rdram, ctx);
        goto after_0;
    // 0x8010770C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80107710: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80107714: lwc1        $f4, 0x88($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X88);
    // 0x80107718: lwc1        $f6, 0x8C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8010771C: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80107720: swc1        $f2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f2.u32l;
    // 0x80107724: lwc1        $f16, 0x80($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X80);
    // 0x80107728: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x8010772C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80107730: swc1        $f6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f6.u32l;
    // 0x80107734: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x80107738: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8010773C: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80107740: lwc1        $f4, 0x94($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80107744: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80107748: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8010774C: swc1        $f16, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f16.u32l;
    // 0x80107750: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80107754: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80107758: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8010775C: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80107760: swc1        $f18, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f18.u32l;
    // 0x80107764: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    // 0x80107768: swc1        $f6, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f6.u32l;
    // 0x8010776C: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x80107770: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80107774: lwc1        $f16, 0x1430($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X1430);
    // 0x80107778: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8010777C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80107780: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80107784: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80107788: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8010778C: lwc1        $f16, 0xAEC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0XAEC);
    // 0x80107790: swc1        $f18, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f18.u32l;
    // 0x80107794: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80107798: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8010779C: addiu       $a1, $sp, 0xAC
    ctx->r5 = ADD32(ctx->r29, 0XAC);
    // 0x801077A0: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    // 0x801077A4: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801077A8: swc1        $f2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->f2.u32l;
    // 0x801077AC: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x801077B0: swc1        $f10, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f10.u32l;
    // 0x801077B4: swc1        $f16, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f16.u32l;
    // 0x801077B8: jal         0x800ED3C0
    // 0x801077BC: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_1;
    // 0x801077BC: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x801077C0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801077C4: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x801077C8: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    // 0x801077CC: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    // 0x801077D0: jal         0x80018994
    // 0x801077D4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x801077D4: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    after_2:
    // 0x801077D8: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x801077DC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801077E0: lw          $a0, 0x66FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X66FC);
    // 0x801077E4: blez        $v0, L_801077FC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x801077E8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_801077FC;
    }
    // 0x801077E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_801077EC:
    // 0x801077EC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x801077F0: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x801077F4: bne         $at, $zero, L_801077EC
    if (ctx->r1 != 0) {
        // 0x801077F8: lw          $a0, 0x4($a0)
        ctx->r4 = MEM_W(ctx->r4, 0X4);
            goto L_801077EC;
    }
    // 0x801077F8: lw          $a0, 0x4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4);
L_801077FC:
    // 0x801077FC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80107800: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80107804: lw          $v1, 0xEC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XEC);
    // 0x80107808: beq         $v1, $at, L_80107818
    if (ctx->r3 == ctx->r1) {
        // 0x8010780C: addiu       $at, $zero, -0x2
        ctx->r1 = ADD32(0, -0X2);
            goto L_80107818;
    }
    // 0x8010780C: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x80107810: bnel        $v1, $at, L_80107834
    if (ctx->r3 != ctx->r1) {
        // 0x80107814: lw          $t9, 0x8E8($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X8E8);
            goto L_80107834;
    }
    goto skip_0;
    // 0x80107814: lw          $t9, 0x8E8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8E8);
    skip_0:
L_80107818:
    // 0x80107818: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010781C: nop

    // 0x80107820: swc1        $f0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f0.u32l;
    // 0x80107824: swc1        $f0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f0.u32l;
    // 0x80107828: b           L_80107860
    // 0x8010782C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
        goto L_80107860;
    // 0x8010782C: swc1        $f0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->f0.u32l;
    // 0x80107830: lw          $t9, 0x8E8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8E8);
L_80107834:
    // 0x80107834: addiu       $t8, $sp, 0xA0
    ctx->r24 = ADD32(ctx->r29, 0XA0);
    // 0x80107838: lw          $t1, 0x1C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X1C);
    // 0x8010783C: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x80107840: lw          $t0, 0x20($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X20);
    // 0x80107844: sw          $t0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r8;
    // 0x80107848: lw          $t1, 0x24($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X24);
    // 0x8010784C: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x80107850: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80107854: lwc1        $f4, 0xF0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x80107858: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8010785C: swc1        $f6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->f6.u32l;
L_80107860:
    // 0x80107860: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80107864: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x80107868: lwc1        $f18, 0xA4($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x8010786C: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x80107870: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80107874: lwc1        $f10, 0xB4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80107878: lwc1        $f8, 0xA8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8010787C: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80107880: swc1        $f16, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f16.u32l;
    // 0x80107884: addiu       $s0, $sp, 0x70
    ctx->r16 = ADD32(ctx->r29, 0X70);
    // 0x80107888: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8010788C: swc1        $f6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f6.u32l;
    // 0x80107890: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80107894: jal         0x80018EE0
    // 0x80107898: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    syVectorNorm3D(rdram, ctx);
        goto after_3;
    // 0x80107898: swc1        $f16, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f16.u32l;
    after_3:
    // 0x8010789C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801078A0: addiu       $a1, $a1, -0x15DC
    ctx->r5 = ADD32(ctx->r5, -0X15DC);
    // 0x801078A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801078A8: addiu       $a2, $sp, 0xAC
    ctx->r6 = ADD32(ctx->r29, 0XAC);
    // 0x801078AC: jal         0x801655C8
    // 0x801078B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    wpManagerMakeWeapon(rdram, ctx);
        goto after_4;
    // 0x801078B0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x801078B4: beq         $v0, $zero, L_801078FC
    if (ctx->r2 == 0) {
        // 0x801078B8: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801078FC;
    }
    // 0x801078B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801078BC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801078C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801078C4: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x801078C8: lw          $v0, 0x84($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X84);
    // 0x801078CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801078D0: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x801078D4: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x801078D8: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x801078DC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801078E0: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x801078E4: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x801078E8: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801078EC: swc1        $f16, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f16.u32l;
    // 0x801078F0: lw          $a1, 0x74($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X74);
    // 0x801078F4: jal         0x8010719C
    // 0x801078F8: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    func_ovl2_8010719C(rdram, ctx);
        goto after_5;
    // 0x801078F8: addiu       $a1, $a1, 0x30
    ctx->r5 = ADD32(ctx->r5, 0X30);
    after_5:
L_801078FC:
    // 0x801078FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80107900: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80107904: addiu       $sp, $sp, 0xD0
    ctx->r29 = ADD32(ctx->r29, 0XD0);
    // 0x80107908: jr          $ra
    // 0x8010790C: nop

    return;
    // 0x8010790C: nop

;}
RECOMP_FUNC void ftPikachuSpecialHiStartSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801528F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801528F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801528FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80152900: jal         0x800DEEC8
    // 0x80152904: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80152904: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80152908: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015290C: addiu       $t7, $zero, 0x92
    ctx->r15 = ADD32(0, 0X92);
    // 0x80152910: addiu       $a1, $zero, 0xEB
    ctx->r5 = ADD32(0, 0XEB);
    // 0x80152914: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80152918: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015291C: jal         0x800E6F24
    // 0x80152920: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80152920: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    after_1:
    // 0x80152924: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80152928: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015292C: jr          $ra
    // 0x80152930: nop

    return;
    // 0x80152930: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingUpdateCursorGrabPriorities(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801348F0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801348F4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801348F8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801348FC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80134900: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80134904: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80134908: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8013490C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80134910: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80134914: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80134918: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8013491C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134920: addiu       $t6, $t6, -0x7CB0
    ctx->r14 = ADD32(ctx->r14, -0X7CB0);
    // 0x80134924: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80134928: addiu       $s5, $sp, 0x50
    ctx->r21 = ADD32(ctx->r29, 0X50);
    // 0x8013492C: addiu       $s4, $zero, 0xB8
    ctx->r20 = ADD32(0, 0XB8);
    // 0x80134930: sw          $t8, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r24;
    // 0x80134934: multu       $a0, $s4
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134938: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8013493C: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80134940: addiu       $s3, $s3, -0x7AA8
    ctx->r19 = ADD32(ctx->r19, -0X7AA8);
    // 0x80134944: sw          $t7, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r15;
    // 0x80134948: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x8013494C: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80134950: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x80134954: sw          $t8, 0x8($s5)
    MEM_W(0X8, ctx->r21) = ctx->r24;
    // 0x80134958: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8013495C: mflo        $t9
    ctx->r25 = lo;
    // 0x80134960: addu        $t0, $s3, $t9
    ctx->r8 = ADD32(ctx->r19, ctx->r25);
    // 0x80134964: sw          $t7, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r15;
    // 0x80134968: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8013496C: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x80134970: jal         0x8000A0D0
    // 0x80134974: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x80134974: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x80134978: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013497C: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x80134980: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80134984: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80134988: mflo        $t1
    ctx->r9 = lo;
    // 0x8013498C: addu        $t2, $s3, $t1
    ctx->r10 = ADD32(ctx->r19, ctx->r9);
    // 0x80134990: jal         0x8000A0D0
    // 0x80134994: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    gcMoveGObjDL(rdram, ctx);
        goto after_1;
    // 0x80134994: lw          $a0, 0x4($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X4);
    after_1:
    // 0x80134998: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8013499C: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x801349A0: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x801349A4: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_801349A8:
    // 0x801349A8: beql        $s0, $fp, L_80134A14
    if (ctx->r16 == ctx->r30) {
        // 0x801349AC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80134A14;
    }
    goto skip_0;
    // 0x801349AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x801349B0: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801349B4: sll         $t4, $s2, 2
    ctx->r12 = S32(ctx->r18 << 2);
    // 0x801349B8: addu        $t5, $s5, $t4
    ctx->r13 = ADD32(ctx->r21, ctx->r12);
    // 0x801349BC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801349C0: mflo        $t3
    ctx->r11 = lo;
    // 0x801349C4: addu        $s1, $s3, $t3
    ctx->r17 = ADD32(ctx->r19, ctx->r11);
    // 0x801349C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x801349CC: beql        $a0, $zero, L_801349E0
    if (ctx->r4 == 0) {
        // 0x801349D0: lw          $v0, 0x7C($s1)
        ctx->r2 = MEM_W(ctx->r17, 0X7C);
            goto L_801349E0;
    }
    goto skip_1;
    // 0x801349D0: lw          $v0, 0x7C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X7C);
    skip_1:
    // 0x801349D4: jal         0x8000A0D0
    // 0x801349D8: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    gcMoveGObjDL(rdram, ctx);
        goto after_2;
    // 0x801349D8: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    after_2:
    // 0x801349DC: lw          $v0, 0x7C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X7C);
L_801349E0:
    // 0x801349E0: beql        $s6, $v0, L_80134A14
    if (ctx->r22 == ctx->r2) {
        // 0x801349E4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80134A14;
    }
    goto skip_2;
    // 0x801349E4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_2:
    // 0x801349E8: multu       $v0, $s4
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801349EC: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x801349F0: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x801349F4: lw          $a2, 0x0($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X0);
    // 0x801349F8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x801349FC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80134A00: mflo        $t6
    ctx->r14 = lo;
    // 0x80134A04: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x80134A08: jal         0x8000A0D0
    // 0x80134A0C: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x80134A0C: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    after_3:
    // 0x80134A10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80134A14:
    // 0x80134A14: bne         $s0, $s7, L_801349A8
    if (ctx->r16 != ctx->r23) {
        // 0x80134A18: addiu       $s2, $s2, -0x1
        ctx->r18 = ADD32(ctx->r18, -0X1);
            goto L_801349A8;
    }
    // 0x80134A18: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x80134A1C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80134A20: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134A24: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80134A28: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80134A2C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80134A30: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80134A34: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80134A38: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80134A3C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80134A40: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80134A44: jr          $ra
    // 0x80134A48: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80134A48: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void ftParamResetStatUpdateColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E98D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800E98D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E98DC: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x800E98E0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800E98E4: jal         0x800E98B0
    // 0x800E98E8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamResetFighterColAnim(rdram, ctx);
        goto after_0;
    // 0x800E98E8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800E98EC: jal         0x800E8A48
    // 0x800E98F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftParamGetBestHitStatusPart(rdram, ctx);
        goto after_1;
    // 0x800E98F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x800E98F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E98F8: beq         $v0, $at, L_800E9914
    if (ctx->r2 == ctx->r1) {
        // 0x800E98FC: lw          $a3, 0x1C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X1C);
            goto L_800E9914;
    }
    // 0x800E98FC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800E9900: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E9904: beq         $v0, $at, L_800E9930
    if (ctx->r2 == ctx->r1) {
        // 0x800E9908: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800E9930;
    }
    // 0x800E9908: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E990C: b           L_800E9948
    // 0x800E9910: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
        goto L_800E9948;
    // 0x800E9910: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
L_800E9914:
    // 0x800E9914: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E9918: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800E991C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E9920: jal         0x800E9814
    // 0x800E9924: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_2;
    // 0x800E9924: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x800E9928: b           L_800E9944
    // 0x800E992C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_800E9944;
    // 0x800E992C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800E9930:
    // 0x800E9930: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800E9934: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E9938: jal         0x800E9814
    // 0x800E993C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_3;
    // 0x800E993C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_3:
    // 0x800E9940: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800E9944:
    // 0x800E9944: lw          $t6, 0x8($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X8);
L_800E9948:
    // 0x800E9948: addiu       $t7, $t6, -0x2
    ctx->r15 = ADD32(ctx->r14, -0X2);
    // 0x800E994C: sltiu       $at, $t7, 0x19
    ctx->r1 = ctx->r15 < 0X19 ? 1 : 0;
    // 0x800E9950: beq         $at, $zero, L_800E9A60
    if (ctx->r1 == 0) {
        // 0x800E9954: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800E9A60;
    }
    // 0x800E9954: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E9958: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E995C: addu        $at, $at, $t7
    gpr jr_addend_800E9964 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800E9960: lw          $t7, -0x154($at)
    ctx->r15 = ADD32(ctx->r1, -0X154);
    // 0x800E9964: jr          $t7
    // 0x800E9968: nop

    switch (jr_addend_800E9964 >> 2) {
        case 0: goto L_800E996C; break;
        case 1: goto L_800E9994; break;
        case 2: goto L_800E9A60; break;
        case 3: goto L_800E9A60; break;
        case 4: goto L_800E9A60; break;
        case 5: goto L_800E9A60; break;
        case 6: goto L_800E99BC; break;
        case 7: goto L_800E9A60; break;
        case 8: goto L_800E9A60; break;
        case 9: goto L_800E9A40; break;
        case 10: goto L_800E9A60; break;
        case 11: goto L_800E9A60; break;
        case 12: goto L_800E9A60; break;
        case 13: goto L_800E9A60; break;
        case 14: goto L_800E996C; break;
        case 15: goto L_800E9994; break;
        case 16: goto L_800E9A60; break;
        case 17: goto L_800E9A60; break;
        case 18: goto L_800E9A60; break;
        case 19: goto L_800E9A60; break;
        case 20: goto L_800E9A60; break;
        case 21: goto L_800E9A60; break;
        case 22: goto L_800E9A60; break;
        case 23: goto L_800E9A40; break;
        case 24: goto L_800E996C; break;
        default: switch_error(__func__, 0x800E9964, 0x8012FEAC);
    }
    // 0x800E9968: nop

L_800E996C:
    // 0x800E996C: lw          $t8, 0xADC($a3)
    ctx->r24 = MEM_W(ctx->r7, 0XADC);
    // 0x800E9970: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800E9974: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E9978: bne         $t8, $at, L_800E9A60
    if (ctx->r24 != ctx->r1) {
        // 0x800E997C: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_800E9A60;
    }
    // 0x800E997C: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800E9980: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E9984: jal         0x800E9814
    // 0x800E9988: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_4;
    // 0x800E9988: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_4:
    // 0x800E998C: b           L_800E9A60
    // 0x800E9990: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_800E9A60;
    // 0x800E9990: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800E9994:
    // 0x800E9994: lw          $t9, 0xADC($a3)
    ctx->r25 = MEM_W(ctx->r7, 0XADC);
    // 0x800E9998: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E999C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E99A0: bne         $t9, $at, L_800E9A60
    if (ctx->r25 != ctx->r1) {
        // 0x800E99A4: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_800E9A60;
    }
    // 0x800E99A4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800E99A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E99AC: jal         0x800E9814
    // 0x800E99B0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_5;
    // 0x800E99B0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_5:
    // 0x800E99B4: b           L_800E9A60
    // 0x800E99B8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_800E9A60;
    // 0x800E99B8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800E99BC:
    // 0x800E99BC: lw          $v1, 0xADC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XADC);
    // 0x800E99C0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E99C4: beq         $v1, $at, L_800E99D4
    if (ctx->r3 == ctx->r1) {
        // 0x800E99C8: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_800E99D4;
    }
    // 0x800E99C8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800E99CC: bnel        $v1, $at, L_800E9A00
    if (ctx->r3 != ctx->r1) {
        // 0x800E99D0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800E9A00;
    }
    goto skip_0;
    // 0x800E99D0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
L_800E99D4:
    // 0x800E99D4: lw          $t0, 0xAE0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0XAE0);
    // 0x800E99D8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800E99DC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E99E0: bne         $t0, $at, L_800E99FC
    if (ctx->r8 != ctx->r1) {
        // 0x800E99E4: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_800E99FC;
    }
    // 0x800E99E4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800E99E8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E99EC: jal         0x800E9814
    // 0x800E99F0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_6;
    // 0x800E99F0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_6:
    // 0x800E99F4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800E99F8: lw          $v1, 0xADC($a3)
    ctx->r3 = MEM_W(ctx->r7, 0XADC);
L_800E99FC:
    // 0x800E99FC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800E9A00:
    // 0x800E9A00: beq         $v1, $at, L_800E9A18
    if (ctx->r3 == ctx->r1) {
        // 0x800E9A04: addiu       $at, $zero, 0x10
        ctx->r1 = ADD32(0, 0X10);
            goto L_800E9A18;
    }
    // 0x800E9A04: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800E9A08: beq         $v1, $at, L_800E9A18
    if (ctx->r3 == ctx->r1) {
        // 0x800E9A0C: addiu       $at, $zero, 0x1A
        ctx->r1 = ADD32(0, 0X1A);
            goto L_800E9A18;
    }
    // 0x800E9A0C: addiu       $at, $zero, 0x1A
    ctx->r1 = ADD32(0, 0X1A);
    // 0x800E9A10: bnel        $v1, $at, L_800E9A64
    if (ctx->r3 != ctx->r1) {
        // 0x800E9A14: lw          $t4, 0x818($a3)
        ctx->r12 = MEM_W(ctx->r7, 0X818);
            goto L_800E9A64;
    }
    goto skip_1;
    // 0x800E9A14: lw          $t4, 0x818($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X818);
    skip_1:
L_800E9A18:
    // 0x800E9A18: lw          $t1, 0xAE8($a3)
    ctx->r9 = MEM_W(ctx->r7, 0XAE8);
    // 0x800E9A1C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800E9A20: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E9A24: bne         $t1, $at, L_800E9A60
    if (ctx->r9 != ctx->r1) {
        // 0x800E9A28: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_800E9A60;
    }
    // 0x800E9A28: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800E9A2C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E9A30: jal         0x800E9814
    // 0x800E9A34: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_7;
    // 0x800E9A34: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_7:
    // 0x800E9A38: b           L_800E9A60
    // 0x800E9A3C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
        goto L_800E9A60;
    // 0x800E9A3C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800E9A40:
    // 0x800E9A40: lb          $t3, 0x18D($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X18D);
    // 0x800E9A44: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E9A48: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x800E9A4C: bgez        $t3, L_800E9A60
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800E9A50: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800E9A60;
    }
    // 0x800E9A50: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E9A54: jal         0x800E9814
    // 0x800E9A58: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_8;
    // 0x800E9A58: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_8:
    // 0x800E9A5C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800E9A60:
    // 0x800E9A60: lw          $t4, 0x818($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X818);
L_800E9A64:
    // 0x800E9A64: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E9A68: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800E9A6C: beq         $t4, $zero, L_800E9A80
    if (ctx->r12 == 0) {
        // 0x800E9A70: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800E9A80;
    }
    // 0x800E9A70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E9A74: jal         0x800E9814
    // 0x800E9A78: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_9;
    // 0x800E9A78: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_9:
    // 0x800E9A7C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800E9A80:
    // 0x800E9A80: lw          $t5, 0x5B0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X5B0);
    // 0x800E9A84: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E9A88: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x800E9A8C: beq         $t5, $zero, L_800E9AA0
    if (ctx->r13 == 0) {
        // 0x800E9A90: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800E9AA0;
    }
    // 0x800E9A90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E9A94: jal         0x800E9814
    // 0x800E9A98: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_10;
    // 0x800E9A98: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_10:
    // 0x800E9A9C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_800E9AA0:
    // 0x800E9AA0: lw          $t6, 0x5A4($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X5A4);
    // 0x800E9AA4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E9AA8: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800E9AAC: bne         $t6, $zero, L_800E9AC0
    if (ctx->r14 != 0) {
        // 0x800E9AB0: nop
    
            goto L_800E9AC0;
    }
    // 0x800E9AB0: nop

    // 0x800E9AB4: lw          $t7, 0x5A8($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X5A8);
    // 0x800E9AB8: beq         $t7, $zero, L_800E9AC8
    if (ctx->r15 == 0) {
        // 0x800E9ABC: nop
    
            goto L_800E9AC8;
    }
    // 0x800E9ABC: nop

L_800E9AC0:
    // 0x800E9AC0: jal         0x800E9814
    // 0x800E9AC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_11;
    // 0x800E9AC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
L_800E9AC8:
    // 0x800E9AC8: jal         0x800F37CC
    // 0x800E9ACC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftHammerCheckStatusHammerAll(rdram, ctx);
        goto after_12;
    // 0x800E9ACC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_12:
    // 0x800E9AD0: beq         $v0, $zero, L_800E9AE4
    if (ctx->r2 == 0) {
        // 0x800E9AD4: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_800E9AE4;
    }
    // 0x800E9AD4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800E9AD8: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
    // 0x800E9ADC: jal         0x800E9814
    // 0x800E9AE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_13;
    // 0x800E9AE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
L_800E9AE4:
    // 0x800E9AE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E9AE8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800E9AEC: jr          $ra
    // 0x800E9AF0: nop

    return;
    // 0x800E9AF0: nop

;}
RECOMP_FUNC void ftCommonSleepCheckIgnorePauseMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013D580: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8013D584: lw          $v1, 0x50E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50E8);
    // 0x8013D588: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8013D58C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013D590: lbu         $t6, 0x3($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X3);
    // 0x8013D594: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x8013D598: beql        $t7, $zero, L_8013D6C8
    if (ctx->r15 == 0) {
        // 0x8013D59C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013D6C8;
    }
    goto skip_0;
    // 0x8013D59C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8013D5A0: lbu         $t8, 0x2($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2);
    // 0x8013D5A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013D5A8: bnel        $t8, $at, L_8013D6C8
    if (ctx->r24 != ctx->r1) {
        // 0x8013D5AC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013D6C8;
    }
    goto skip_1;
    // 0x8013D5AC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8013D5B0: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x8013D5B4: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x8013D5B8: bnel        $t2, $t9, L_8013D6C8
    if (ctx->r10 != ctx->r25) {
        // 0x8013D5BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013D6C8;
    }
    goto skip_2;
    // 0x8013D5BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_2:
    // 0x8013D5C0: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x8013D5C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013D5C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013D5CC: bne         $t6, $zero, L_8013D6C4
    if (ctx->r14 != 0) {
        // 0x8013D5D0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8013D6C4;
    }
    // 0x8013D5D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8013D5D4: addiu       $t5, $sp, 0x1C
    ctx->r13 = ADD32(ctx->r29, 0X1C);
    // 0x8013D5D8: addiu       $t4, $zero, 0x74
    ctx->r12 = ADD32(0, 0X74);
    // 0x8013D5DC: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8013D5E0: lbu         $a3, 0xD($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0XD);
L_8013D5E4:
    // 0x8013D5E4: beql        $a2, $a3, L_8013D648
    if (ctx->r6 == ctx->r7) {
        // 0x8013D5E8: addiu       $t9, $a2, 0x1
        ctx->r25 = ADD32(ctx->r6, 0X1);
            goto L_8013D648;
    }
    goto skip_3;
    // 0x8013D5E8: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
    skip_3:
    // 0x8013D5EC: multu       $a2, $t4
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013D5F0: mflo        $t7
    ctx->r15 = lo;
    // 0x8013D5F4: addu        $t0, $v1, $t7
    ctx->r8 = ADD32(ctx->r3, ctx->r15);
    // 0x8013D5F8: lbu         $t8, 0x22($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X22);
    // 0x8013D5FC: beql        $t3, $t8, L_8013D648
    if (ctx->r11 == ctx->r24) {
        // 0x8013D600: addiu       $t9, $a2, 0x1
        ctx->r25 = ADD32(ctx->r6, 0X1);
            goto L_8013D648;
    }
    goto skip_4;
    // 0x8013D600: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
    skip_4:
    // 0x8013D604: lbu         $t9, 0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0XC);
    // 0x8013D608: lbu         $t6, 0x25($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X25);
    // 0x8013D60C: bnel        $t9, $t6, L_8013D648
    if (ctx->r25 != ctx->r14) {
        // 0x8013D610: addiu       $t9, $a2, 0x1
        ctx->r25 = ADD32(ctx->r6, 0X1);
            goto L_8013D648;
    }
    goto skip_5;
    // 0x8013D610: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
    skip_5:
    // 0x8013D614: lb          $t1, 0x2B($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X2B);
    // 0x8013D618: blez        $t1, L_8013D644
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8013D61C: slt         $at, $a1, $t1
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8013D644;
    }
    // 0x8013D61C: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8013D620: beql        $at, $zero, L_8013D634
    if (ctx->r1 == 0) {
        // 0x8013D624: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_8013D634;
    }
    goto skip_6;
    // 0x8013D624: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    skip_6:
    // 0x8013D628: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013D62C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8013D630: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
L_8013D634:
    // 0x8013D634: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8013D638: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x8013D63C: lbu         $a3, 0xD($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0XD);
    // 0x8013D640: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8013D644:
    // 0x8013D644: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
L_8013D648:
    // 0x8013D648: beql        $t9, $a3, L_8013D6AC
    if (ctx->r25 == ctx->r7) {
        // 0x8013D64C: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8013D6AC;
    }
    goto skip_7;
    // 0x8013D64C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_7:
    // 0x8013D650: multu       $a2, $t4
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013D654: mflo        $t6
    ctx->r14 = lo;
    // 0x8013D658: addu        $t0, $v1, $t6
    ctx->r8 = ADD32(ctx->r3, ctx->r14);
    // 0x8013D65C: lbu         $t7, 0x96($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X96);
    // 0x8013D660: beql        $t3, $t7, L_8013D6AC
    if (ctx->r11 == ctx->r15) {
        // 0x8013D664: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8013D6AC;
    }
    goto skip_8;
    // 0x8013D664: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_8:
    // 0x8013D668: lbu         $t8, 0xC($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0XC);
    // 0x8013D66C: lbu         $t9, 0x99($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X99);
    // 0x8013D670: bnel        $t8, $t9, L_8013D6AC
    if (ctx->r24 != ctx->r25) {
        // 0x8013D674: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_8013D6AC;
    }
    goto skip_9;
    // 0x8013D674: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    skip_9:
    // 0x8013D678: lb          $a3, 0x9F($t0)
    ctx->r7 = MEM_B(ctx->r8, 0X9F);
    // 0x8013D67C: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x8013D680: blez        $a3, L_8013D6A8
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8013D684: slt         $at, $a1, $a3
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8013D6A8;
    }
    // 0x8013D684: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8013D688: beql        $at, $zero, L_8013D69C
    if (ctx->r1 == 0) {
        // 0x8013D68C: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_8013D69C;
    }
    goto skip_10;
    // 0x8013D68C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    skip_10:
    // 0x8013D690: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013D694: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8013D698: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
L_8013D69C:
    // 0x8013D69C: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8013D6A0: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8013D6A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8013D6A8:
    // 0x8013D6A8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
L_8013D6AC:
    // 0x8013D6AC: bnel        $a2, $t2, L_8013D5E4
    if (ctx->r6 != ctx->r10) {
        // 0x8013D6B0: lbu         $a3, 0xD($v0)
        ctx->r7 = MEM_BU(ctx->r2, 0XD);
            goto L_8013D5E4;
    }
    goto skip_11;
    // 0x8013D6B0: lbu         $a3, 0xD($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0XD);
    skip_11:
    // 0x8013D6B4: beql        $a0, $zero, L_8013D6C8
    if (ctx->r4 == 0) {
        // 0x8013D6B8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8013D6C8;
    }
    goto skip_12;
    // 0x8013D6B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_12:
    // 0x8013D6BC: b           L_8013D6C8
    // 0x8013D6C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8013D6C8;
    // 0x8013D6C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8013D6C4:
    // 0x8013D6C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013D6C8:
    // 0x8013D6C8: jr          $ra
    // 0x8013D6CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8013D6CC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sc1PIntroInitVSFighters(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133AC8: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80133ACC: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80133AD0: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133AD4: addiu       $s1, $sp, 0x50
    ctx->r17 = ADD32(ctx->r29, 0X50);
    // 0x80133AD8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80133ADC: addiu       $t6, $t6, 0x51B8
    ctx->r14 = ADD32(ctx->r14, 0X51B8);
    // 0x80133AE0: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80133AE4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133AE8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80133AEC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80133AF0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80133AF4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80133AF8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80133AFC: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80133B00: or          $t9, $s1, $zero
    ctx->r25 = ctx->r17 | 0;
L_80133B04:
    // 0x80133B04: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133B08: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133B0C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80133B10: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80133B14: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80133B18: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80133B1C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80133B20: bne         $t6, $t0, L_80133B04
    if (ctx->r14 != ctx->r8) {
        // 0x80133B24: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80133B04;
    }
    // 0x80133B24: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80133B28: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133B2C: sltiu       $at, $s5, 0xE
    ctx->r1 = ctx->r21 < 0XE ? 1 : 0;
    // 0x80133B30: sll         $t1, $s5, 2
    ctx->r9 = S32(ctx->r21 << 2);
    // 0x80133B34: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80133B38: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80133B3C: beq         $at, $zero, L_80133EB8
    if (ctx->r1 == 0) {
        // 0x80133B40: sw          $t7, 0x4($t9)
        MEM_W(0X4, ctx->r25) = ctx->r15;
            goto L_80133EB8;
    }
    // 0x80133B40: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x80133B44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133B48: addu        $at, $at, $t1
    gpr jr_addend_80133B50 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80133B4C: lw          $t1, 0x5BE0($at)
    ctx->r9 = ADD32(ctx->r1, 0X5BE0);
    // 0x80133B50: jr          $t1
    // 0x80133B54: nop

    switch (jr_addend_80133B50 >> 2) {
        case 0: goto L_80133D0C; break;
        case 1: goto L_80133B58; break;
        case 2: goto L_80133D0C; break;
        case 3: goto L_80133EB8; break;
        case 4: goto L_80133DEC; break;
        case 5: goto L_80133D0C; break;
        case 6: goto L_80133DB8; break;
        case 7: goto L_80133EB8; break;
        case 8: goto L_80133C18; break;
        case 9: goto L_80133D0C; break;
        case 10: goto L_80133D0C; break;
        case 11: goto L_80133EB8; break;
        case 12: goto L_80133CA4; break;
        case 13: goto L_80133D0C; break;
        default: switch_error(__func__, 0x80133B50, 0x80135BE0);
    }
    // 0x80133B54: nop

L_80133B58:
    // 0x80133B58: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133B5C: jal         0x8013376C
    // 0x80133B60: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    sc1PIntroMakeStageCamera(rdram, ctx);
        goto after_0;
    // 0x80133B60: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_0:
    // 0x80133B64: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80133B68: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80133B6C: addiu       $s4, $s4, 0x5CC8
    ctx->r20 = ADD32(ctx->r20, 0X5CC8);
    // 0x80133B70: addiu       $s1, $s1, 0x5C3C
    ctx->r17 = ADD32(ctx->r17, 0X5C3C);
    // 0x80133B74: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80133B78: addiu       $s6, $zero, 0x12
    ctx->r22 = ADD32(0, 0X12);
    // 0x80133B7C: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_80133B80:
    // 0x80133B80: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80133B84: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80133B88: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80133B8C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80133B90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80133B94: jal         0x80133398
    // 0x80133B98: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    sc1PIntroMakeVSFighter(rdram, ctx);
        goto after_1;
    // 0x80133B98: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x80133B9C: div         $zero, $s0, $s3
    lo = S32(S64(S32(ctx->r16)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r16)) % S64(S32(ctx->r19)));
    // 0x80133BA0: lw          $t3, 0x4($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X4);
    // 0x80133BA4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80133BA8: bne         $s3, $zero, L_80133BB4
    if (ctx->r19 != 0) {
        // 0x80133BAC: nop
    
            goto L_80133BB4;
    }
    // 0x80133BAC: nop

    // 0x80133BB0: break       7
    do_break(2148744112);
L_80133BB4:
    // 0x80133BB4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80133BB8: bne         $s3, $at, L_80133BCC
    if (ctx->r19 != ctx->r1) {
        // 0x80133BBC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80133BCC;
    }
    // 0x80133BBC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133BC0: bne         $s0, $at, L_80133BCC
    if (ctx->r16 != ctx->r1) {
        // 0x80133BC4: nop
    
            goto L_80133BCC;
    }
    // 0x80133BC4: nop

    // 0x80133BC8: break       6
    do_break(2148744136);
L_80133BCC:
    // 0x80133BCC: mfhi        $a1
    ctx->r5 = hi;
    // 0x80133BD0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80133BD4: bne         $t3, $a1, L_80133BFC
    if (ctx->r11 != ctx->r5) {
        // 0x80133BD8: nop
    
            goto L_80133BFC;
    }
    // 0x80133BD8: nop

    // 0x80133BDC: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80133BE0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80133BE4: bne         $s3, $t4, L_80133BFC
    if (ctx->r19 != ctx->r12) {
        // 0x80133BE8: nop
    
            goto L_80133BFC;
    }
    // 0x80133BE8: nop

    // 0x80133BEC: jal         0x800E9248
    // 0x80133BF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_2;
    // 0x80133BF0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80133BF4: b           L_80133C08
    // 0x80133BF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_80133C08;
    // 0x80133BF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80133BFC:
    // 0x80133BFC: jal         0x800E9248
    // 0x80133C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_3;
    // 0x80133C00: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_3:
    // 0x80133C04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80133C08:
    // 0x80133C08: bne         $s0, $s6, L_80133B80
    if (ctx->r16 != ctx->r22) {
        // 0x80133C0C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80133B80;
    }
    // 0x80133C0C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80133C10: b           L_80133EBC
    // 0x80133C14: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80133EBC;
    // 0x80133C14: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80133C18:
    // 0x80133C18: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133C1C: jal         0x8013376C
    // 0x80133C20: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    sc1PIntroMakeStageCamera(rdram, ctx);
        goto after_4;
    // 0x80133C20: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_4:
    // 0x80133C24: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80133C28: addiu       $s1, $s1, 0x5C3C
    ctx->r17 = ADD32(ctx->r17, 0X5C3C);
    // 0x80133C2C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80133C30: addiu       $s3, $zero, 0x8
    ctx->r19 = ADD32(0, 0X8);
L_80133C34:
    // 0x80133C34: addiu       $t5, $zero, 0x20
    ctx->r13 = ADD32(0, 0X20);
    // 0x80133C38: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80133C3C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80133C40: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80133C44: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80133C48: jal         0x80133398
    // 0x80133C4C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    sc1PIntroMakeVSFighter(rdram, ctx);
        goto after_5;
    // 0x80133C4C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_5:
    // 0x80133C50: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80133C54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133C58: jal         0x80133080
    // 0x80133C5C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    sc1PIntroSetKirbyTeamModelPartIDs(rdram, ctx);
        goto after_6;
    // 0x80133C5C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_6:
    // 0x80133C60: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133C64: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80133C68: jal         0x80133930
    // 0x80133C6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sSC1PIntroCheckCostumeUsed(rdram, ctx);
        goto after_7;
    // 0x80133C6C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x80133C70: beq         $v0, $zero, L_80133C90
    if (ctx->r2 == 0) {
        // 0x80133C74: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80133C90;
    }
    // 0x80133C74: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133C78: jal         0x800EC0EC
    // 0x80133C7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_8;
    // 0x80133C7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80133C80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80133C84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133C88: jal         0x800E9248
    // 0x80133C8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_9;
    // 0x80133C8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_9:
L_80133C90:
    // 0x80133C90: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80133C94: bne         $s0, $s3, L_80133C34
    if (ctx->r16 != ctx->r19) {
        // 0x80133C98: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80133C34;
    }
    // 0x80133C98: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80133C9C: b           L_80133EBC
    // 0x80133CA0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80133EBC;
    // 0x80133CA0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80133CA4:
    // 0x80133CA4: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133CA8: jal         0x8013376C
    // 0x80133CAC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    sc1PIntroMakeStageCamera(rdram, ctx);
        goto after_10;
    // 0x80133CAC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_10:
    // 0x80133CB0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80133CB4: addiu       $s2, $s2, 0x5C38
    ctx->r18 = ADD32(ctx->r18, 0X5C38);
    // 0x80133CB8: addiu       $s0, $zero, 0xE
    ctx->r16 = ADD32(0, 0XE);
    // 0x80133CBC: addiu       $s6, $zero, 0x12
    ctx->r22 = ADD32(0, 0X12);
    // 0x80133CC0: addiu       $s3, $zero, 0x1A
    ctx->r19 = ADD32(0, 0X1A);
    // 0x80133CC4: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
L_80133CC8:
    // 0x80133CC8: beql        $s0, $s6, L_80133CFC
    if (ctx->r16 == ctx->r22) {
        // 0x80133CCC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80133CFC;
    }
    goto skip_0;
    // 0x80133CCC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80133CD0: beq         $s0, $s1, L_80133CF8
    if (ctx->r16 == ctx->r17) {
        // 0x80133CD4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80133CF8;
    }
    // 0x80133CD4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80133CD8: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x80133CDC: addu        $a3, $s2, $t0
    ctx->r7 = ADD32(ctx->r18, ctx->r8);
    // 0x80133CE0: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80133CE4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133CE8: addiu       $a3, $a3, -0x34
    ctx->r7 = ADD32(ctx->r7, -0X34);
    // 0x80133CEC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80133CF0: jal         0x80133398
    // 0x80133CF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sc1PIntroMakeVSFighter(rdram, ctx);
        goto after_11;
    // 0x80133CF4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_11:
L_80133CF8:
    // 0x80133CF8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80133CFC:
    // 0x80133CFC: bne         $s0, $s3, L_80133CC8
    if (ctx->r16 != ctx->r19) {
        // 0x80133D00: nop
    
            goto L_80133CC8;
    }
    // 0x80133D00: nop

    // 0x80133D04: b           L_80133EBC
    // 0x80133D08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80133EBC;
    // 0x80133D08: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80133D0C:
    // 0x80133D0C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133D10: jal         0x8013376C
    // 0x80133D14: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    sc1PIntroMakeStageCamera(rdram, ctx);
        goto after_12;
    // 0x80133D14: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_12:
    // 0x80133D18: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x80133D1C: addu        $s0, $s1, $t9
    ctx->r16 = ADD32(ctx->r17, ctx->r25);
    // 0x80133D20: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80133D24: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80133D28: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80133D2C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80133D30: addiu       $a3, $a3, 0x5C3C
    ctx->r7 = ADD32(ctx->r7, 0X5C3C);
    // 0x80133D34: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80133D38: jal         0x80133398
    // 0x80133D3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sc1PIntroMakeVSFighter(rdram, ctx);
        goto after_13;
    // 0x80133D3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_13:
    // 0x80133D40: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80133D44: addiu       $s4, $s4, 0x5CC8
    ctx->r20 = ADD32(ctx->r20, 0X5CC8);
    // 0x80133D48: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80133D4C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80133D50: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80133D54: bnel        $a0, $t8, L_80133EBC
    if (ctx->r4 != ctx->r24) {
        // 0x80133D58: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_80133EBC;
    }
    goto skip_1;
    // 0x80133D58: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    skip_1:
    // 0x80133D5C: jal         0x800EC0EC
    // 0x80133D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_14;
    // 0x80133D60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80133D64: lw          $t1, 0x4($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4);
    // 0x80133D68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133D6C: bne         $v0, $t1, L_80133D98
    if (ctx->r2 != ctx->r9) {
        // 0x80133D70: nop
    
            goto L_80133D98;
    }
    // 0x80133D70: nop

    // 0x80133D74: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80133D78: jal         0x800EC0EC
    // 0x80133D7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_15;
    // 0x80133D7C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80133D80: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80133D84: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133D88: jal         0x800E9248
    // 0x80133D8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_16;
    // 0x80133D8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
    // 0x80133D90: b           L_80133EBC
    // 0x80133D94: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80133EBC;
    // 0x80133D94: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80133D98:
    // 0x80133D98: jal         0x800EC0EC
    // 0x80133D9C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_17;
    // 0x80133D9C: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    after_17:
    // 0x80133DA0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80133DA4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133DA8: jal         0x800E9248
    // 0x80133DAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_18;
    // 0x80133DAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_18:
    // 0x80133DB0: b           L_80133EBC
    // 0x80133DB4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80133EBC;
    // 0x80133DB4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80133DB8:
    // 0x80133DB8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133DBC: jal         0x8013376C
    // 0x80133DC0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    sc1PIntroMakeStageCamera(rdram, ctx);
        goto after_19;
    // 0x80133DC0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_19:
    // 0x80133DC4: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80133DC8: addiu       $t2, $zero, 0x20
    ctx->r10 = ADD32(0, 0X20);
    // 0x80133DCC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80133DD0: addiu       $a3, $a3, 0x5C44
    ctx->r7 = ADD32(ctx->r7, 0X5C44);
    // 0x80133DD4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80133DD8: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80133DDC: jal         0x80133398
    // 0x80133DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sc1PIntroMakeVSFighter(rdram, ctx);
        goto after_20;
    // 0x80133DE0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_20:
    // 0x80133DE4: b           L_80133EBC
    // 0x80133DE8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_80133EBC;
    // 0x80133DE8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80133DEC:
    // 0x80133DEC: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133DF0: jal         0x8013376C
    // 0x80133DF4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    sc1PIntroMakeStageCamera(rdram, ctx);
        goto after_21;
    // 0x80133DF4: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_21:
    // 0x80133DF8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80133DFC: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x80133E00: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80133E04: addiu       $a3, $a3, 0x5C40
    ctx->r7 = ADD32(ctx->r7, 0X5C40);
    // 0x80133E08: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133E0C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80133E10: jal         0x80133398
    // 0x80133E14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sc1PIntroMakeVSFighter(rdram, ctx);
        goto after_22;
    // 0x80133E14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_22:
    // 0x80133E18: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80133E1C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133E20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133E24: jal         0x80133930
    // 0x80133E28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sSC1PIntroCheckCostumeUsed(rdram, ctx);
        goto after_23;
    // 0x80133E28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_23:
    // 0x80133E2C: beq         $v0, $zero, L_80133E4C
    if (ctx->r2 == 0) {
        // 0x80133E30: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80133E4C;
    }
    // 0x80133E30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133E34: jal         0x800EC0EC
    // 0x80133E38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_24;
    // 0x80133E38: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_24:
    // 0x80133E3C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80133E40: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133E44: jal         0x800E9248
    // 0x80133E48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_25;
    // 0x80133E48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_25:
L_80133E4C:
    // 0x80133E4C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133E50: jal         0x8013376C
    // 0x80133E54: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    sc1PIntroMakeStageCamera(rdram, ctx);
        goto after_26;
    // 0x80133E54: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_26:
    // 0x80133E58: lw          $t4, 0x80($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X80);
    // 0x80133E5C: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80133E60: addiu       $t0, $zero, 0x21
    ctx->r8 = ADD32(0, 0X21);
    // 0x80133E64: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80133E68: sw          $t5, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r13;
    // 0x80133E6C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80133E70: addiu       $a3, $a3, 0x5C44
    ctx->r7 = ADD32(ctx->r7, 0X5C44);
    // 0x80133E74: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80133E78: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80133E7C: jal         0x80133398
    // 0x80133E80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sc1PIntroMakeVSFighter(rdram, ctx);
        goto after_27;
    // 0x80133E80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_27:
    // 0x80133E84: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80133E88: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80133E8C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80133E90: jal         0x80133930
    // 0x80133E94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    sSC1PIntroCheckCostumeUsed(rdram, ctx);
        goto after_28;
    // 0x80133E94: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_28:
    // 0x80133E98: beq         $v0, $zero, L_80133EB8
    if (ctx->r2 == 0) {
        // 0x80133E9C: addiu       $a0, $zero, 0x4
        ctx->r4 = ADD32(0, 0X4);
            goto L_80133EB8;
    }
    // 0x80133E9C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80133EA0: jal         0x800EC0EC
    // 0x80133EA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_29;
    // 0x80133EA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_29:
    // 0x80133EA8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80133EAC: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133EB0: jal         0x800E9248
    // 0x80133EB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_30;
    // 0x80133EB4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_30:
L_80133EB8:
    // 0x80133EB8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_80133EBC:
    // 0x80133EBC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80133EC0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80133EC4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80133EC8: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80133ECC: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80133ED0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80133ED4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x80133ED8: jr          $ra
    // 0x80133EDC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80133EDC: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void itBoxExplodeMakeEffectGotoSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179B08: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179B0C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179B10: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80179B14: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80179B18: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80179B1C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80179B20: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    // 0x80179B24: swc1        $f0, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f0.u32l;
    // 0x80179B28: swc1        $f0, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f0.u32l;
    // 0x80179B2C: swc1        $f0, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f0.u32l;
    // 0x80179B30: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x80179B34: jal         0x801005C8
    // 0x80179B38: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80179B38: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    after_0:
    // 0x80179B3C: beq         $v0, $zero, L_80179B68
    if (ctx->r2 == 0) {
        // 0x80179B40: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_80179B68;
    }
    // 0x80179B40: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80179B44: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80179B48: lwc1        $f4, -0x3288($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3288);
    // 0x80179B4C: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
    // 0x80179B50: swc1        $f4, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f4.u32l;
    // 0x80179B54: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x80179B58: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80179B5C: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x80179B60: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    // 0x80179B64: swc1        $f0, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f0.u32l;
L_80179B68:
    // 0x80179B68: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80179B6C: jal         0x801008F4
    // 0x80179B70: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80179B70: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x80179B74: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80179B78: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80179B7C: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80179B80: jal         0x80179AD4
    // 0x80179B84: sb          $t8, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r24;
    itBoxExplodeSetStatus(rdram, ctx);
        goto after_2;
    // 0x80179B84: sb          $t8, 0x54($t9)
    MEM_B(0X54, ctx->r25) = ctx->r24;
    after_2:
    // 0x80179B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179B8C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179B90: jr          $ra
    // 0x80179B94: nop

    return;
    // 0x80179B94: nop

;}
RECOMP_FUNC void mvOpeningSamusPosedWallpaperProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D8B0: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x8018D8B4: addiu       $t3, $t3, 0x65B0
    ctx->r11 = ADD32(ctx->r11, 0X65B0);
    // 0x8018D8B8: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D8C0: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x8018D8C4: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018D8C8: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8018D8CC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D8D0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D8D4: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8D8: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8018D8DC: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x8018D8E0: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D8E4: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D8E8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D8EC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8018D8F0: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D8F4: addiu       $t7, $zero, 0x50FF
    ctx->r15 = ADD32(0, 0X50FF);
    // 0x8018D8F8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x8018D8FC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D900: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D904: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D908: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D90C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D910: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x8018D914: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x8018D918: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D91C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D920: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x8018D924: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x8018D928: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D92C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8018D930: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D934: lui         $t5, 0xE200
    ctx->r13 = S32(0XE200 << 16);
    // 0x8018D938: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x8018D93C: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x8018D940: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8018D944: ori         $t5, $t5, 0x1C
    ctx->r13 = ctx->r13 | 0X1C;
    // 0x8018D948: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x8018D94C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018D950: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8018D954: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D958: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x8018D95C: lui         $t6, 0xF61B
    ctx->r14 = S32(0XF61B << 16);
    // 0x8018D960: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D964: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D968: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x8018D96C: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x8018D970: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8018D974: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8018D978: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D97C: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x8018D980: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x8018D984: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x8018D988: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8018D98C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8018D990: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x8018D994: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8018D998: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8018D99C: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8018D9A0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8018D9A4: jr          $ra
    // 0x8018D9A8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    return;
    // 0x8018D9A8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
;}
RECOMP_FUNC void ftParamUpdate1PGameAttackStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA7B0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800EA7B4: sw          $a1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r5;
    // 0x800EA7B8: lhu         $t6, 0x16($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X16);
    // 0x800EA7BC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800EA7C0: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800EA7C4: sh          $t6, 0xC($sp)
    MEM_H(0XC, ctx->r29) = ctx->r14;
    // 0x800EA7C8: lw          $t7, 0x20($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X20);
    // 0x800EA7CC: beq         $t7, $at, L_800EA8A8
    if (ctx->r15 == ctx->r1) {
        // 0x800EA7D0: nop
    
            goto L_800EA8A8;
    }
    // 0x800EA7D0: nop

    // 0x800EA7D4: lw          $t8, 0x50E8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X50E8);
    // 0x800EA7D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800EA7DC: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x800EA7E0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800EA7E4: bne         $t9, $at, L_800EA8A8
    if (ctx->r25 != ctx->r1) {
        // 0x800EA7E8: nop
    
            goto L_800EA8A8;
    }
    // 0x800EA7E8: nop

    // 0x800EA7EC: lbu         $t0, 0x4AE3($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X4AE3);
    // 0x800EA7F0: lbu         $t1, 0xD($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0XD);
    // 0x800EA7F4: bne         $t0, $t1, L_800EA8A8
    if (ctx->r8 != ctx->r9) {
        // 0x800EA7F8: nop
    
            goto L_800EA8A8;
    }
    // 0x800EA7F8: nop

    // 0x800EA7FC: lw          $v0, 0x28C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28C);
    // 0x800EA800: andi        $t3, $t6, 0x3FF
    ctx->r11 = ctx->r14 & 0X3FF;
    // 0x800EA804: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800EA808: beq         $v0, $zero, L_800EA8A8
    if (ctx->r2 == 0) {
        // 0x800EA80C: nop
    
            goto L_800EA8A8;
    }
    // 0x800EA80C: nop

    // 0x800EA810: beq         $t3, $v0, L_800EA8A8
    if (ctx->r11 == ctx->r2) {
        // 0x800EA814: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_800EA8A8;
    }
    // 0x800EA814: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800EA818: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x800EA81C: addiu       $t5, $t5, 0x36B0
    ctx->r13 = ADD32(ctx->r13, 0X36B0);
    // 0x800EA820: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x800EA824: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800EA828: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x800EA82C: addiu       $t2, $t2, 0x3798
    ctx->r10 = ADD32(ctx->r10, 0X3798);
    // 0x800EA830: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800EA834: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800EA838: lw          $t8, 0x28C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X28C);
    // 0x800EA83C: sll         $t9, $t8, 19
    ctx->r25 = S32(ctx->r24 << 19);
    // 0x800EA840: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x800EA844: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800EA848: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    // 0x800EA84C: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x800EA850: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x800EA854: addiu       $t9, $t9, 0x37A0
    ctx->r25 = ADD32(ctx->r25, 0X37A0);
    // 0x800EA858: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800EA85C: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x800EA860: lw          $t5, 0x28C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X28C);
    // 0x800EA864: sll         $t6, $t5, 20
    ctx->r14 = S32(ctx->r13 << 20);
    // 0x800EA868: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x800EA86C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800EA870: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
    // 0x800EA874: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800EA878: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x800EA87C: addiu       $t6, $t6, 0x37A8
    ctx->r14 = ADD32(ctx->r14, 0X37A8);
    // 0x800EA880: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800EA884: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x800EA888: lw          $t2, 0x28C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X28C);
    // 0x800EA88C: sll         $t3, $t2, 21
    ctx->r11 = S32(ctx->r10 << 21);
    // 0x800EA890: srl         $t4, $t3, 31
    ctx->r12 = S32(U32(ctx->r11) >> 31);
    // 0x800EA894: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800EA898: addu        $a3, $t5, $t6
    ctx->r7 = ADD32(ctx->r13, ctx->r14);
    // 0x800EA89C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800EA8A0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800EA8A4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_800EA8A8:
    // 0x800EA8A8: jr          $ra
    // 0x800EA8AC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800EA8AC: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void itFFlowerWeaponFlameProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175E4C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175E50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175E54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80175E58: jal         0x800269C0
    // 0x80175E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80175E5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80175E60: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80175E64: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x80175E68: jal         0x80100480
    // 0x80175E6C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80175E6C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80175E70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175E74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175E78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80175E7C: jr          $ra
    // 0x80175E80: nop

    return;
    // 0x80175E80: nop

;}
RECOMP_FUNC void itDogasAttackUpdateSmog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182CDC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80182CE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182CE4: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80182CE8: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80182CEC: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80182CF0: lw          $t6, 0x35C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X35C);
    // 0x80182CF4: bgtzl       $t6, L_80182E10
    if (SIGNED(ctx->r14) > 0) {
        // 0x80182CF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80182E10;
    }
    goto skip_0;
    // 0x80182CF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80182CFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80182D00: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80182D04: addiu       $t7, $sp, 0x2C
    ctx->r15 = ADD32(ctx->r29, 0X2C);
    // 0x80182D08: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80182D0C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80182D10: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x80182D14: lw          $t9, 0x1C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X1C);
    // 0x80182D18: sw          $t9, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r25;
    // 0x80182D1C: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x80182D20: sw          $t8, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r24;
    // 0x80182D24: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x80182D28: sw          $t9, 0x8($t7)
    MEM_W(0X8, ctx->r15) = ctx->r25;
    // 0x80182D2C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80182D30: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80182D34: jal         0x80018948
    // 0x80182D38: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x80182D38: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_0:
    // 0x80182D3C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80182D40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80182D44: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x80182D48: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80182D4C: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80182D50: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80182D54: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80182D58: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80182D5C: jal         0x80018948
    // 0x80182D60: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x80182D60: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80182D64: lui         $at, 0x4448
    ctx->r1 = S32(0X4448 << 16);
    // 0x80182D68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80182D6C: lui         $at, 0x43C8
    ctx->r1 = S32(0X43C8 << 16);
    // 0x80182D70: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80182D74: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80182D78: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80182D7C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x80182D80: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80182D84: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80182D88: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80182D8C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x80182D90: sub.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80182D94: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80182D98: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x80182D9C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80182DA0: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80182DA4: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80182DA8: c.lt.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl < ctx->f8.fl;
    // 0x80182DAC: nop

    // 0x80182DB0: bc1fl       L_80182DC4
    if (!c1cs) {
        // 0x80182DB4: lwc1        $f18, 0x30($sp)
        ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
            goto L_80182DC4;
    }
    goto skip_1;
    // 0x80182DB4: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x80182DB8: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80182DBC: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
    // 0x80182DC0: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
L_80182DC4:
    // 0x80182DC4: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80182DC8: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80182DCC: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80182DD0: nop

    // 0x80182DD4: bc1f        L_80182DE4
    if (!c1cs) {
        // 0x80182DD8: nop
    
            goto L_80182DE4;
    }
    // 0x80182DD8: nop

    // 0x80182DDC: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80182DE0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
L_80182DE4:
    // 0x80182DE4: jal         0x80183144
    // 0x80182DE8: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    itDogasWeaponSmogMakeWeapon(rdram, ctx);
        goto after_2;
    // 0x80182DE8: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80182DEC: jal         0x800269C0
    // 0x80182DF0: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80182DF0: addiu       $a0, $zero, 0x83
    ctx->r4 = ADD32(0, 0X83);
    after_3:
    // 0x80182DF4: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80182DF8: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80182DFC: lhu         $t1, 0x33E($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X33E);
    // 0x80182E00: sw          $t0, 0x35C($v1)
    MEM_W(0X35C, ctx->r3) = ctx->r8;
    // 0x80182E04: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x80182E08: sh          $t2, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r10;
    // 0x80182E0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80182E10:
    // 0x80182E10: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80182E14: jr          $ra
    // 0x80182E18: nop

    return;
    // 0x80182E18: nop

;}
RECOMP_FUNC void itMLuckyCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181480: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80181484: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181488: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8018148C: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x80181490: jal         0x801737B8
    // 0x80181494: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80181494: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80181498: beq         $v0, $zero, L_801814AC
    if (ctx->r2 == 0) {
        // 0x8018149C: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_801814AC;
    }
    // 0x8018149C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x801814A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801814A4: nop

    // 0x801814A8: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_801814AC:
    // 0x801814AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801814B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801814B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801814B8: jr          $ra
    // 0x801814BC: nop

    return;
    // 0x801814BC: nop

;}
RECOMP_FUNC void gmCollisionCheckAttackInFighterRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EF2D0: lwc1        $f12, 0x8($a2)
    ctx->f12.u32l = MEM_W(ctx->r6, 0X8);
    // 0x800EF2D4: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800EF2D8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800EF2DC: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800EF2E0: neg.s       $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = -ctx->f12.fl;
    // 0x800EF2E4: lwc1        $f8, 0x4($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800EF2E8: sub.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x800EF2EC: lwc1        $f10, 0x4($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800EF2F0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800EF2F4: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800EF2F8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800EF2FC: nop

    // 0x800EF300: bc1t        L_800EF354
    if (c1cs) {
        // 0x800EF304: nop
    
            goto L_800EF354;
    }
    // 0x800EF304: nop

    // 0x800EF308: add.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800EF30C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800EF310: nop

    // 0x800EF314: bc1t        L_800EF354
    if (c1cs) {
        // 0x800EF318: nop
    
            goto L_800EF354;
    }
    // 0x800EF318: nop

    // 0x800EF31C: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x800EF320: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x800EF324: sub.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800EF328: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x800EF32C: nop

    // 0x800EF330: bc1t        L_800EF354
    if (c1cs) {
        // 0x800EF334: nop
    
            goto L_800EF354;
    }
    // 0x800EF334: nop

    // 0x800EF338: lwc1        $f16, 0x0($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X0);
    // 0x800EF33C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800EF340: add.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f14.fl;
    // 0x800EF344: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800EF348: nop

    // 0x800EF34C: bc1f        L_800EF35C
    if (!c1cs) {
        // 0x800EF350: nop
    
            goto L_800EF35C;
    }
    // 0x800EF350: nop

L_800EF354:
    // 0x800EF354: jr          $ra
    // 0x800EF358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800EF358: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EF35C:
    // 0x800EF35C: jr          $ra
    // 0x800EF360: nop

    return;
    // 0x800EF360: nop

;}
RECOMP_FUNC void mvOpeningLinkSetupFiles(uint8_t* rdram, recomp_context* ctx) {
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
    // 0x8018D0E0: addiu       $t8, $t8, -0x1DD8
    ctx->r24 = ADD32(ctx->r24, -0X1DD8);
    // 0x8018D0E4: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x8018D0E8: addiu       $t0, $t0, -0x1C58
    ctx->r8 = ADD32(ctx->r8, -0X1C58);
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
    // 0x8018D11C: addiu       $a0, $a0, -0x1F50
    ctx->r4 = ADD32(ctx->r4, -0X1F50);
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
    // 0x8018D13C: addiu       $a2, $a2, -0x1C20
    ctx->r6 = ADD32(ctx->r6, -0X1C20);
    // 0x8018D140: addiu       $a0, $a0, -0x1F50
    ctx->r4 = ADD32(ctx->r4, -0X1F50);
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
RECOMP_FUNC void mnMapsFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134304: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80134308: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8013430C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80134310: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80134314: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80134318: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013431C: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80134320: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80134324: addiu       $t8, $t8, 0x4C30
    ctx->r24 = ADD32(ctx->r24, 0X4C30);
    // 0x80134328: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8013432C: addiu       $t0, $t0, 0x4D20
    ctx->r8 = ADD32(ctx->r8, 0X4D20);
    // 0x80134330: addiu       $t1, $zero, 0x1E
    ctx->r9 = ADD32(0, 0X1E);
    // 0x80134334: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80134338: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8013433C: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80134340: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80134344: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80134348: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8013434C: sw          $t0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r8;
    // 0x80134350: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80134354: jal         0x800CDF78
    // 0x80134358: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80134358: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    after_0:
    // 0x8013435C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134360: addiu       $a0, $a0, 0x44D0
    ctx->r4 = ADD32(ctx->r4, 0X44D0);
    // 0x80134364: jal         0x800CDEEC
    // 0x80134368: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80134368: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_1:
    // 0x8013436C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134370: jal         0x80004980
    // 0x80134374: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80134374: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80134378: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013437C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80134380: addiu       $a2, $a2, 0x4E10
    ctx->r6 = ADD32(ctx->r6, 0X4E10);
    // 0x80134384: addiu       $a0, $a0, 0x44D0
    ctx->r4 = ADD32(ctx->r4, 0X44D0);
    // 0x80134388: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8013438C: jal         0x800CDE04
    // 0x80134390: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80134390: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80134394: jal         0x80131B00
    // 0x80134398: nop

    mnMapsAllocModelHeaps(rdram, ctx);
        goto after_4;
    // 0x80134398: nop

    after_4:
    // 0x8013439C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801343A0: addiu       $a1, $a1, 0x3D80
    ctx->r5 = ADD32(ctx->r5, 0X3D80);
    // 0x801343A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801343A8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801343AC: jal         0x80009968
    // 0x801343B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x801343B0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x801343B4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801343B8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x801343BC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801343C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801343C4: jal         0x8000B9FC
    // 0x801343C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_6;
    // 0x801343C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_6:
    // 0x801343CC: jal         0x80133C6C
    // 0x801343D0: nop

    mnMapsInitVars(rdram, ctx);
        goto after_7;
    // 0x801343D0: nop

    after_7:
    // 0x801343D4: jal         0x801334AC
    // 0x801343D8: nop

    mnMapsMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x801343D8: nop

    after_8:
    // 0x801343DC: jal         0x8013368C
    // 0x801343E0: nop

    mnMapsMakeLabelsViewport(rdram, ctx);
        goto after_9;
    // 0x801343E0: nop

    after_9:
    // 0x801343E4: jal         0x8013372C
    // 0x801343E8: nop

    mnMapsMakeIconsCamera(rdram, ctx);
        goto after_10;
    // 0x801343E8: nop

    after_10:
    // 0x801343EC: jal         0x801337CC
    // 0x801343F0: nop

    mnMapsMakeNameAndEmblemCamera(rdram, ctx);
        goto after_11;
    // 0x801343F0: nop

    after_11:
    // 0x801343F4: jal         0x8013386C
    // 0x801343F8: nop

    mnMapsMakeCursorCamera(rdram, ctx);
        goto after_12;
    // 0x801343F8: nop

    after_12:
    // 0x801343FC: jal         0x80133A88
    // 0x80134400: nop

    mnMapsMakePreviewCamera(rdram, ctx);
        goto after_13;
    // 0x80134400: nop

    after_13:
    // 0x80134404: jal         0x8013354C
    // 0x80134408: nop

    mnMapsMakePlaqueCamera(rdram, ctx);
        goto after_14;
    // 0x80134408: nop

    after_14:
    // 0x8013440C: jal         0x801335EC
    // 0x80134410: nop

    mnMapsMakePreviewWallpaperCamera(rdram, ctx);
        goto after_15;
    // 0x80134410: nop

    after_15:
    // 0x80134414: jal         0x80131FA4
    // 0x80134418: nop

    mnMapsMakeWallpaper(rdram, ctx);
        goto after_16;
    // 0x80134418: nop

    after_16:
    // 0x8013441C: jal         0x80132048
    // 0x80134420: nop

    mnMapsMakePlaque(rdram, ctx);
        goto after_17;
    // 0x80134420: nop

    after_17:
    // 0x80134424: jal         0x80132288
    // 0x80134428: nop

    mnMapsMakeLabels(rdram, ctx);
        goto after_18;
    // 0x80134428: nop

    after_18:
    // 0x8013442C: jal         0x80132528
    // 0x80134430: nop

    mnMapsMakeIcons(rdram, ctx);
        goto after_19;
    // 0x80134430: nop

    after_19:
    // 0x80134434: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134438: jal         0x801329AC
    // 0x8013443C: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsMakeNameAndEmblem(rdram, ctx);
        goto after_20;
    // 0x8013443C: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_20:
    // 0x80134440: jal         0x80132ADC
    // 0x80134444: nop

    mnMapsMakeCursor(rdram, ctx);
        goto after_21;
    // 0x80134444: nop

    after_21:
    // 0x80134448: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013444C: jal         0x80132430
    // 0x80134450: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    mnMapsGetGroundKind(rdram, ctx);
        goto after_22;
    // 0x80134450: lw          $a0, 0x4BD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4BD8);
    after_22:
    // 0x80134454: jal         0x801333B4
    // 0x80134458: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnMapsMakePreview(rdram, ctx);
        goto after_23;
    // 0x80134458: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x8013445C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80134460: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80134464: jr          $ra
    // 0x80134468: nop

    return;
    // 0x80134468: nop

;}
RECOMP_FUNC void mpCommonCheckFighterOnCliffEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DDE1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DDE20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DDE24: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DDE28: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DDE2C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DDE30: addiu       $a1, $a1, -0x23B0
    ctx->r5 = ADD32(ctx->r5, -0X23B0);
    // 0x800DDE34: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800DDE38: jal         0x800DA034
    // 0x800DDE3C: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DDE3C: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DDE40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DDE44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DDE48: jr          $ra
    // 0x800DDE4C: nop

    return;
    // 0x800DDE4C: nop

;}
RECOMP_FUNC void func_ovl8_8037A9C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A9C0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8037A9C4: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8037A9C8: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x8037A9CC: lh          $t2, 0x6($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X6);
    // 0x8037A9D0: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8037A9D4: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x8037A9D8: addu        $t1, $t0, $a2
    ctx->r9 = ADD32(ctx->r8, ctx->r6);
    // 0x8037A9DC: addu        $t3, $t2, $a2
    ctx->r11 = ADD32(ctx->r10, ctx->r6);
    // 0x8037A9E0: sh          $t9, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r25;
    // 0x8037A9E4: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8037A9E8: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x8037A9EC: jr          $ra
    // 0x8037A9F0: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
    return;
    // 0x8037A9F0: sh          $t1, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r9;
;}
RECOMP_FUNC void ftPikachuSpecialAirLwEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152764: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80152768: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015276C: jal         0x80152718
    // 0x80152770: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftPikachuSpecialLwClearProcDamage(rdram, ctx);
        goto after_0;
    // 0x80152770: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80152774: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80152778: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x8015277C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80152780: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80152784: jal         0x800E6F24
    // 0x80152788: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80152788: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8015278C: jal         0x800E0830
    // 0x80152790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80152790: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80152794: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80152798: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015279C: jr          $ra
    // 0x801527A0: nop

    return;
    // 0x801527A0: nop

;}
RECOMP_FUNC void scExplainTryMakeFireFlower(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DF80: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018DF84: lw          $t6, -0x15E4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X15E4);
    // 0x8018DF88: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018DF8C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x8018DF90: bne         $t6, $at, L_8018DFE8
    if (ctx->r14 != ctx->r1) {
        // 0x8018DF94: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_8018DFE8;
    }
    // 0x8018DF94: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DF98: lui         $at, 0xC4AF
    ctx->r1 = S32(0XC4AF << 16);
    // 0x8018DF9C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DFA0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DFA4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DFA8: lwc1        $f6, -0x181C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X181C);
    // 0x8018DFAC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DFB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018DFB4: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8018DFB8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8018DFBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018DFC0: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x8018DFC4: addiu       $a2, $sp, 0x2C
    ctx->r6 = ADD32(ctx->r29, 0X2C);
    // 0x8018DFC8: addiu       $a3, $sp, 0x20
    ctx->r7 = ADD32(ctx->r29, 0X20);
    // 0x8018DFCC: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x8018DFD0: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x8018DFD4: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8018DFD8: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018DFDC: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x8018DFE0: jal         0x8016EA78
    // 0x8018DFE4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_0;
    // 0x8018DFE4: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_0:
L_8018DFE8:
    // 0x8018DFE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DFEC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8018DFF0: jr          $ra
    // 0x8018DFF4: nop

    return;
    // 0x8018DFF4: nop

;}
RECOMP_FUNC void ftCaptainSpecialAirHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801607B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801607B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801607BC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801607C0: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x801607C4: addiu       $t6, $t6, 0x5FC
    ctx->r14 = ADD32(ctx->r14, 0X5FC);
    // 0x801607C8: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x801607CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801607D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801607D4: addiu       $a1, $zero, 0xEE
    ctx->r5 = ADD32(0, 0XEE);
    // 0x801607D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801607DC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801607E0: jal         0x800E6F24
    // 0x801607E4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801607E4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801607E8: jal         0x80160280
    // 0x801607EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftCaptainSpecialHiSetCatchParams(rdram, ctx);
        goto after_1;
    // 0x801607EC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x801607F0: jal         0x800E0830
    // 0x801607F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x801607F4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x801607F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801607FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80160800: jr          $ra
    // 0x80160804: nop

    return;
    // 0x80160804: nop

;}
RECOMP_FUNC void func_ovl8_8037C174(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C174: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037C178: lw          $a0, -0x1034($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1034);
    // 0x8037C17C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037C180: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037C184: bne         $a0, $zero, L_8037C194
    if (ctx->r4 != 0) {
        // 0x8037C188: nop
    
            goto L_8037C194;
    }
    // 0x8037C188: nop

    // 0x8037C18C: b           L_8037C19C
    // 0x8037C190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037C19C;
    // 0x8037C190: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037C194:
    // 0x8037C194: jal         0x80375D4C
    // 0x8037C198: nop

    func_ovl8_80375D4C(rdram, ctx);
        goto after_0;
    // 0x8037C198: nop

    after_0:
L_8037C19C:
    // 0x8037C19C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037C1A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037C1A4: jr          $ra
    // 0x8037C1A8: nop

    return;
    // 0x8037C1A8: nop

;}

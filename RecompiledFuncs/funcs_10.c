#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void grZebesAcidGetLevelInfo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010850C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80108510: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80108514: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80108518: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010851C: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80108520: lbu         $t6, 0x16($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X16);
    // 0x80108524: bnel        $t6, $at, L_8010853C
    if (ctx->r14 != ctx->r1) {
        // 0x80108528: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_8010853C;
    }
    goto skip_0;
    // 0x80108528: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_0:
    // 0x8010852C: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80108530: jr          $ra
    // 0x80108534: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    return;
    // 0x80108534: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80108538: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_8010853C:
    // 0x8010853C: nop

    // 0x80108540: swc1        $f8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f8.u32l;
    // 0x80108544: jr          $ra
    // 0x80108548: nop

    return;
    // 0x80108548: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801559D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801559D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801559D8: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801559DC: jal         0x800D9480
    // 0x801559E0: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801559E0: addiu       $a1, $a1, -0x620
    ctx->r5 = ADD32(ctx->r5, -0X620);
    after_0:
    // 0x801559E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801559E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801559EC: jr          $ra
    // 0x801559F0: nop

    return;
    // 0x801559F0: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialNLoopSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80157B5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80157B60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80157B64: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80157B68: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80157B6C: jal         0x800DEEC8
    // 0x80157B70: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80157B70: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80157B74: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80157B78: addiu       $t7, $zero, 0x4002
    ctx->r15 = ADD32(0, 0X4002);
    // 0x80157B7C: addiu       $a1, $zero, 0xF5
    ctx->r5 = ADD32(0, 0XF5);
    // 0x80157B80: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80157B84: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80157B88: jal         0x800E6F24
    // 0x80157B8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80157B8C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80157B90: jal         0x80157AD4
    // 0x80157B94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftKirbyCopyDonkeySpecialNLoopSetProcDamageAnimSpeed(rdram, ctx);
        goto after_2;
    // 0x80157B94: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x80157B98: jal         0x800D8EB8
    // 0x80157B9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_3;
    // 0x80157B9C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80157BA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80157BA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80157BA8: jr          $ra
    // 0x80157BAC: nop

    return;
    // 0x80157BAC: nop

;}
RECOMP_FUNC void itDisplayColAnimXLUProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017224C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80172250: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80172254: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80172258: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8017225C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x80172260: jal         0x80171C10
    // 0x80172264: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    itDisplayCheckItemVisible(rdram, ctx);
        goto after_0;
    // 0x80172264: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80172268: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8017226C: beq         $v0, $zero, L_801722F8
    if (ctx->r2 == 0) {
        // 0x80172270: lw          $a1, 0x20($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X20);
            goto L_801722F8;
    }
    // 0x80172270: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x80172274: lw          $v0, 0x374($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X374);
    // 0x80172278: beq         $v0, $zero, L_80172294
    if (ctx->r2 == 0) {
        // 0x8017227C: nop
    
            goto L_80172294;
    }
    // 0x8017227C: nop

    // 0x80172280: lw          $t6, 0x2CC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2CC);
    // 0x80172284: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80172288: sll         $t8, $t6, 17
    ctx->r24 = S32(ctx->r14 << 17);
    // 0x8017228C: bgez        $t8, L_801722A4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80172290: nop
    
            goto L_801722A4;
    }
    // 0x80172290: nop

L_80172294:
    // 0x80172294: jal         0x80172008
    // 0x80172298: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayColAnimXLU(rdram, ctx);
        goto after_1;
    // 0x80172298: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x8017229C: b           L_801722FC
    // 0x801722A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801722FC;
    // 0x801722A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801722A4:
    // 0x801722A4: bnel        $v0, $at, L_801722CC
    if (ctx->r2 != ctx->r1) {
        // 0x801722A8: lw          $t9, 0x248($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X248);
            goto L_801722CC;
    }
    goto skip_0;
    // 0x801722A8: lw          $t9, 0x248($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X248);
    skip_0:
    // 0x801722AC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801722B0: jal         0x80172008
    // 0x801722B4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    itDisplayColAnimXLU(rdram, ctx);
        goto after_2;
    // 0x801722B4: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    after_2:
    // 0x801722B8: jal         0x801719AC
    // 0x801722BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    itDisplayMapCollisions(rdram, ctx);
        goto after_3;
    // 0x801722BC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
    // 0x801722C0: b           L_801722FC
    // 0x801722C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801722FC;
    // 0x801722C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801722C8: lw          $t9, 0x248($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X248);
L_801722CC:
    // 0x801722CC: bne         $t9, $zero, L_801722F0
    if (ctx->r25 != 0) {
        // 0x801722D0: nop
    
            goto L_801722F0;
    }
    // 0x801722D0: nop

    // 0x801722D4: lw          $t0, 0x10C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X10C);
    // 0x801722D8: bne         $t0, $zero, L_801722F0
    if (ctx->r8 != 0) {
        // 0x801722DC: nop
    
            goto L_801722F0;
    }
    // 0x801722DC: nop

    // 0x801722E0: jal         0x80172008
    // 0x801722E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayColAnimXLU(rdram, ctx);
        goto after_4;
    // 0x801722E4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_4:
    // 0x801722E8: b           L_801722FC
    // 0x801722EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801722FC;
    // 0x801722EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801722F0:
    // 0x801722F0: jal         0x80171410
    // 0x801722F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itDisplayHitCollisions(rdram, ctx);
        goto after_5;
    // 0x801722F4: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_5:
L_801722F8:
    // 0x801722F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801722FC:
    // 0x801722FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80172300: jr          $ra
    // 0x80172304: nop

    return;
    // 0x80172304: nop

;}
RECOMP_FUNC void mnOptionFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132E4C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80132E50: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132E54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132E58: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80132E5C: addiu       $t7, $t7, 0x36EC
    ctx->r15 = ADD32(ctx->r15, 0X36EC);
    // 0x80132E60: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132E64: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
    // 0x80132E68: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80132E6C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80132E70: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132E74: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132E78: addiu       $v1, $v1, 0x37E4
    ctx->r3 = ADD32(ctx->r3, 0X37E4);
    // 0x80132E7C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80132E80: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132E84: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80132E88: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132E8C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80132E90: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x80132E94: bne         $at, $zero, L_8013345C
    if (ctx->r1 != 0) {
        // 0x80132E98: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_8013345C;
    }
    // 0x80132E98: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80132E9C: lw          $t2, 0x37E8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X37E8);
    // 0x80132EA0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132EA4: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132EA8: bne         $t2, $t1, L_80132ED0
    if (ctx->r10 != ctx->r9) {
        // 0x80132EAC: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80132ED0;
    }
    // 0x80132EAC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80132EB0: lbu         $t3, 0x0($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X0);
    // 0x80132EB4: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
    // 0x80132EB8: jal         0x80132E10
    // 0x80132EBC: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    mnOptionWriteBackup(rdram, ctx);
        goto after_0;
    // 0x80132EBC: sb          $t3, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r11;
    after_0:
    // 0x80132EC0: jal         0x80005C74
    // 0x80132EC4: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x80132EC4: nop

    after_1:
    // 0x80132EC8: b           L_80133460
    // 0x80132ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80133460;
    // 0x80132ECC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132ED0:
    // 0x80132ED0: jal         0x80390B7C
    // 0x80132ED4: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_2;
    // 0x80132ED4: nop

    after_2:
    // 0x80132ED8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132EDC: bne         $v0, $zero, L_80132EF4
    if (ctx->r2 != 0) {
        // 0x80132EE0: addiu       $v1, $v1, 0x37E4
        ctx->r3 = ADD32(ctx->r3, 0X37E4);
            goto L_80132EF4;
    }
    // 0x80132EE0: addiu       $v1, $v1, 0x37E4
    ctx->r3 = ADD32(ctx->r3, 0X37E4);
    // 0x80132EE4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80132EE8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132EEC: addiu       $t6, $t5, 0x4650
    ctx->r14 = ADD32(ctx->r13, 0X4650);
    // 0x80132EF0: sw          $t6, 0x37E8($at)
    MEM_W(0X37E8, ctx->r1) = ctx->r14;
L_80132EF4:
    // 0x80132EF4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132EF8: lw          $t7, 0x37DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X37DC);
    // 0x80132EFC: beq         $t7, $zero, L_80132F0C
    if (ctx->r15 == 0) {
        // 0x80132F00: nop
    
            goto L_80132F0C;
    }
    // 0x80132F00: nop

    // 0x80132F04: jal         0x80005C74
    // 0x80132F08: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x80132F08: nop

    after_3:
L_80132F0C:
    // 0x80132F0C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132F10: addiu       $v1, $v1, 0x37E0
    ctx->r3 = ADD32(ctx->r3, 0X37E0);
    // 0x80132F14: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132F18: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132F1C: beq         $v0, $zero, L_80132F28
    if (ctx->r2 == 0) {
        // 0x80132F20: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80132F28;
    }
    // 0x80132F20: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80132F24: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80132F28:
    // 0x80132F28: jal         0x80390A04
    // 0x80132F2C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_4;
    // 0x80132F2C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_4:
    // 0x80132F30: beq         $v0, $zero, L_80132F6C
    if (ctx->r2 == 0) {
        // 0x80132F34: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80132F6C;
    }
    // 0x80132F34: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132F38: jal         0x80390AC0
    // 0x80132F3C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_5;
    // 0x80132F3C: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_5:
    // 0x80132F40: beq         $v0, $zero, L_80132F6C
    if (ctx->r2 == 0) {
        // 0x80132F44: nop
    
            goto L_80132F6C;
    }
    // 0x80132F44: nop

    // 0x80132F48: jal         0x80390804
    // 0x80132F4C: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_6;
    // 0x80132F4C: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_6:
    // 0x80132F50: bne         $v0, $zero, L_80132F6C
    if (ctx->r2 != 0) {
        // 0x80132F54: nop
    
            goto L_80132F6C;
    }
    // 0x80132F54: nop

    // 0x80132F58: jal         0x80390804
    // 0x80132F5C: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_7;
    // 0x80132F5C: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_7:
    // 0x80132F60: bne         $v0, $zero, L_80132F6C
    if (ctx->r2 != 0) {
        // 0x80132F64: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132F6C;
    }
    // 0x80132F64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132F68: sw          $zero, 0x37E0($at)
    MEM_W(0X37E0, ctx->r1) = 0;
L_80132F6C:
    // 0x80132F6C: jal         0x8039076C
    // 0x80132F70: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_8;
    // 0x80132F70: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_8:
    // 0x80132F74: beq         $v0, $zero, L_8013304C
    if (ctx->r2 == 0) {
        // 0x80132F78: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_8013304C;
    }
    // 0x80132F78: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132F7C: lw          $v0, 0x37B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X37B8);
    // 0x80132F80: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132F84: beq         $v0, $at, L_80132F9C
    if (ctx->r2 == ctx->r1) {
        // 0x80132F88: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80132F9C;
    }
    // 0x80132F88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80132F8C: beq         $v0, $at, L_80132FF4
    if (ctx->r2 == ctx->r1) {
        // 0x80132F90: nop
    
            goto L_80132FF4;
    }
    // 0x80132F90: nop

    // 0x80132F94: b           L_8013304C
    // 0x80132F98: nop

        goto L_8013304C;
    // 0x80132F98: nop

L_80132F9C:
    // 0x80132F9C: jal         0x80132E10
    // 0x80132FA0: nop

    mnOptionWriteBackup(rdram, ctx);
        goto after_9;
    // 0x80132FA0: nop

    after_9:
    // 0x80132FA4: jal         0x800269C0
    // 0x80132FA8: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_10;
    // 0x80132FA8: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_10:
    // 0x80132FAC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132FB0: lw          $t9, 0x37B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X37B8);
    // 0x80132FB4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80132FB8: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80132FBC: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x80132FC0: lw          $t1, 0x24($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X24);
    // 0x80132FC4: jal         0x80131B24
    // 0x80132FC8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    mnOptionSetOptionSpriteColors(rdram, ctx);
        goto after_11;
    // 0x80132FC8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_11:
    // 0x80132FCC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80132FD0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80132FD4: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x80132FD8: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x80132FDC: sb          $t3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r11;
    // 0x80132FE0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80132FE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132FE8: sb          $t2, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r10;
    // 0x80132FEC: b           L_8013345C
    // 0x80132FF0: sw          $t4, 0x37DC($at)
    MEM_W(0X37DC, ctx->r1) = ctx->r12;
        goto L_8013345C;
    // 0x80132FF0: sw          $t4, 0x37DC($at)
    MEM_W(0X37DC, ctx->r1) = ctx->r12;
L_80132FF4:
    // 0x80132FF4: jal         0x80132E10
    // 0x80132FF8: nop

    mnOptionWriteBackup(rdram, ctx);
        goto after_12;
    // 0x80132FF8: nop

    after_12:
    // 0x80132FFC: jal         0x800269C0
    // 0x80133000: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_13;
    // 0x80133000: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_13:
    // 0x80133004: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133008: lw          $t5, 0x37B8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X37B8);
    // 0x8013300C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80133010: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80133014: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x80133018: lw          $t7, 0x24($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X24);
    // 0x8013301C: jal         0x80131B24
    // 0x80133020: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    mnOptionSetOptionSpriteColors(rdram, ctx);
        goto after_14;
    // 0x80133020: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_14:
    // 0x80133024: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133028: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8013302C: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x80133030: addiu       $t9, $zero, 0x2F
    ctx->r25 = ADD32(0, 0X2F);
    // 0x80133034: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80133038: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8013303C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133040: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
    // 0x80133044: b           L_8013345C
    // 0x80133048: sw          $t0, 0x37DC($at)
    MEM_W(0X37DC, ctx->r1) = ctx->r8;
        goto L_8013345C;
    // 0x80133048: sw          $t0, 0x37DC($at)
    MEM_W(0X37DC, ctx->r1) = ctx->r8;
L_8013304C:
    // 0x8013304C: jal         0x8039076C
    // 0x80133050: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_15;
    // 0x80133050: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_15:
    // 0x80133054: beq         $v0, $zero, L_80133080
    if (ctx->r2 == 0) {
        // 0x80133058: nop
    
            goto L_80133080;
    }
    // 0x80133058: nop

    // 0x8013305C: jal         0x80132E10
    // 0x80133060: nop

    mnOptionWriteBackup(rdram, ctx);
        goto after_16;
    // 0x80133060: nop

    after_16:
    // 0x80133064: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133068: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8013306C: lbu         $t1, 0x0($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X0);
    // 0x80133070: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x80133074: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
    // 0x80133078: jal         0x80005C74
    // 0x8013307C: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_17;
    // 0x8013307C: sb          $t1, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r9;
    after_17:
L_80133080:
    // 0x80133080: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133084: lw          $v0, 0x37E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X37E0);
    // 0x80133088: bne         $v0, $zero, L_801330A8
    if (ctx->r2 != 0) {
        // 0x8013308C: nop
    
            goto L_801330A8;
    }
    // 0x8013308C: nop

    // 0x80133090: jal         0x80390804
    // 0x80133094: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_18;
    // 0x80133094: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_18:
    // 0x80133098: bne         $v0, $zero, L_801330C0
    if (ctx->r2 != 0) {
        // 0x8013309C: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_801330C0;
    }
    // 0x8013309C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801330A0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801330A4: lw          $v0, 0x37E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X37E0);
L_801330A8:
    // 0x801330A8: bne         $v0, $zero, L_80133174
    if (ctx->r2 != 0) {
        // 0x801330AC: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80133174;
    }
    // 0x801330AC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x801330B0: jal         0x80390950
    // 0x801330B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_19;
    // 0x801330B4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_19:
    // 0x801330B8: beq         $v0, $zero, L_80133174
    if (ctx->r2 == 0) {
        // 0x801330BC: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_80133174;
    }
    // 0x801330BC: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_801330C0:
    // 0x801330C0: jal         0x800269C0
    // 0x801330C4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_20;
    // 0x801330C4: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_20:
    // 0x801330C8: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x801330CC: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    // 0x801330D0: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x801330D4: beq         $t3, $zero, L_801330EC
    if (ctx->r11 == 0) {
        // 0x801330D8: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_801330EC;
    }
    // 0x801330D8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801330DC: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x801330E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801330E4: b           L_80133104
    // 0x801330E8: sw          $t4, 0x37E0($at)
    MEM_W(0X37E0, ctx->r1) = ctx->r12;
        goto L_80133104;
    // 0x801330E8: sw          $t4, 0x37E0($at)
    MEM_W(0X37E0, ctx->r1) = ctx->r12;
L_801330EC:
    // 0x801330EC: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x801330F0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801330F4: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x801330F8: mflo        $t8
    ctx->r24 = lo;
    // 0x801330FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133100: sw          $t8, 0x37E0($at)
    MEM_W(0X37E0, ctx->r1) = ctx->r24;
L_80133104:
    // 0x80133104: lw          $t9, 0x37B8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X37B8);
    // 0x80133108: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013310C: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80133110: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x80133114: lw          $t1, 0x24($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X24);
    // 0x80133118: jal         0x80131B24
    // 0x8013311C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    mnOptionSetOptionSpriteColors(rdram, ctx);
        goto after_21;
    // 0x8013311C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_21:
    // 0x80133120: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133124: addiu       $v1, $v1, 0x37B8
    ctx->r3 = ADD32(ctx->r3, 0X37B8);
    // 0x80133128: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013312C: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80133130: bne         $v0, $zero, L_80133140
    if (ctx->r2 != 0) {
        // 0x80133134: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_80133140;
    }
    // 0x80133134: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80133138: b           L_80133144
    // 0x8013313C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
        goto L_80133144;
    // 0x8013313C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80133140:
    // 0x80133140: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80133144:
    // 0x80133144: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x80133148: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013314C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80133150: addu        $t5, $sp, $t6
    ctx->r13 = ADD32(ctx->r29, ctx->r14);
    // 0x80133154: lw          $t5, 0x24($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X24);
    // 0x80133158: jal         0x80131B24
    // 0x8013315C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    mnOptionSetOptionSpriteColors(rdram, ctx);
        goto after_22;
    // 0x8013315C: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    after_22:
    // 0x80133160: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133164: jal         0x80009A84
    // 0x80133168: lw          $a0, 0x37D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37D0);
    gcEjectGObj(rdram, ctx);
        goto after_23;
    // 0x80133168: lw          $a0, 0x37D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37D0);
    after_23:
    // 0x8013316C: jal         0x801321A8
    // 0x80133170: nop

    mnOptionMakeMenuGObj(rdram, ctx);
        goto after_24;
    // 0x80133170: nop

    after_24:
L_80133174:
    // 0x80133174: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133178: lw          $v0, 0x37E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X37E0);
    // 0x8013317C: bne         $v0, $zero, L_8013319C
    if (ctx->r2 != 0) {
        // 0x80133180: nop
    
            goto L_8013319C;
    }
    // 0x80133180: nop

    // 0x80133184: jal         0x80390804
    // 0x80133188: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_25;
    // 0x80133188: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_25:
    // 0x8013318C: bne         $v0, $zero, L_801331B4
    if (ctx->r2 != 0) {
        // 0x80133190: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_801331B4;
    }
    // 0x80133190: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80133194: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133198: lw          $v0, 0x37E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X37E0);
L_8013319C:
    // 0x8013319C: bne         $v0, $zero, L_80133284
    if (ctx->r2 != 0) {
        // 0x801331A0: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80133284;
    }
    // 0x801331A0: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x801331A4: jal         0x80390950
    // 0x801331A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_26;
    // 0x801331A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_26:
    // 0x801331AC: beq         $v0, $zero, L_80133284
    if (ctx->r2 == 0) {
        // 0x801331B0: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_80133284;
    }
    // 0x801331B0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_801331B4:
    // 0x801331B4: jal         0x800269C0
    // 0x801331B8: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_27;
    // 0x801331B8: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_27:
    // 0x801331BC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801331C0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801331C4: addiu       $v1, $v1, 0x37E0
    ctx->r3 = ADD32(ctx->r3, 0X37E0);
    // 0x801331C8: beq         $t7, $zero, L_801331D8
    if (ctx->r15 == 0) {
        // 0x801331CC: addiu       $t8, $zero, 0xC
        ctx->r24 = ADD32(0, 0XC);
            goto L_801331D8;
    }
    // 0x801331CC: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x801331D0: b           L_801331FC
    // 0x801331D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_801331FC;
    // 0x801331D4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_801331D8:
    // 0x801331D8: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x801331DC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801331E0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801331E4: addiu       $t0, $t9, 0xA0
    ctx->r8 = ADD32(ctx->r25, 0XA0);
    // 0x801331E8: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x801331EC: mflo        $t1
    ctx->r9 = lo;
    // 0x801331F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801331F4: sw          $t1, 0x37E0($at)
    MEM_W(0X37E0, ctx->r1) = ctx->r9;
    // 0x801331F8: addiu       $v1, $v1, 0x37E0
    ctx->r3 = ADD32(ctx->r3, 0X37E0);
L_801331FC:
    // 0x801331FC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133200: lw          $v0, 0x37B8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X37B8);
    // 0x80133204: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133208: bne         $v0, $at, L_8013321C
    if (ctx->r2 != ctx->r1) {
        // 0x8013320C: sll         $t4, $v0, 2
        ctx->r12 = S32(ctx->r2 << 2);
            goto L_8013321C;
    }
    // 0x8013320C: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80133210: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x80133214: addiu       $t3, $t2, 0x8
    ctx->r11 = ADD32(ctx->r10, 0X8);
    // 0x80133218: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_8013321C:
    // 0x8013321C: addu        $t6, $sp, $t4
    ctx->r14 = ADD32(ctx->r29, ctx->r12);
    // 0x80133220: lw          $t6, 0x24($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X24);
    // 0x80133224: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133228: jal         0x80131B24
    // 0x8013322C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    mnOptionSetOptionSpriteColors(rdram, ctx);
        goto after_28;
    // 0x8013322C: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_28:
    // 0x80133230: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133234: addiu       $v1, $v1, 0x37B8
    ctx->r3 = ADD32(ctx->r3, 0X37B8);
    // 0x80133238: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013323C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133240: bne         $v0, $at, L_80133250
    if (ctx->r2 != ctx->r1) {
        // 0x80133244: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_80133250;
    }
    // 0x80133244: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80133248: b           L_80133254
    // 0x8013324C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_80133254;
    // 0x8013324C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80133250:
    // 0x80133250: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_80133254:
    // 0x80133254: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80133258: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013325C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80133260: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80133264: lw          $t9, 0x24($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X24);
    // 0x80133268: jal         0x80131B24
    // 0x8013326C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    mnOptionSetOptionSpriteColors(rdram, ctx);
        goto after_29;
    // 0x8013326C: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_29:
    // 0x80133270: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133274: jal         0x80009A84
    // 0x80133278: lw          $a0, 0x37D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37D0);
    gcEjectGObj(rdram, ctx);
        goto after_30;
    // 0x80133278: lw          $a0, 0x37D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37D0);
    after_30:
    // 0x8013327C: jal         0x801321A8
    // 0x80133280: nop

    mnOptionMakeMenuGObj(rdram, ctx);
        goto after_31;
    // 0x80133280: nop

    after_31:
L_80133284:
    // 0x80133284: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133288: lw          $t0, 0x37B8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X37B8);
    // 0x8013328C: bnel        $t0, $zero, L_80133460
    if (ctx->r8 != 0) {
        // 0x80133290: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80133460;
    }
    goto skip_0;
    // 0x80133290: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80133294: jal         0x8039076C
    // 0x80133298: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_32;
    // 0x80133298: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_32:
    // 0x8013329C: bne         $v0, $zero, L_801332C4
    if (ctx->r2 != 0) {
        // 0x801332A0: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_801332C4;
    }
    // 0x801332A0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801332A4: lw          $t1, 0x37E0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X37E0);
    // 0x801332A8: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x801332AC: bne         $t1, $zero, L_8013333C
    if (ctx->r9 != 0) {
        // 0x801332B0: nop
    
            goto L_8013333C;
    }
    // 0x801332B0: nop

    // 0x801332B4: jal         0x8039089C
    // 0x801332B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_33;
    // 0x801332B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_33:
    // 0x801332BC: beq         $v0, $zero, L_8013333C
    if (ctx->r2 == 0) {
        // 0x801332C0: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_8013333C;
    }
    // 0x801332C0: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_801332C4:
    // 0x801332C4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801332C8: lw          $t2, 0x37BC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X37BC);
    // 0x801332CC: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x801332D0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801332D4: bne         $t2, $zero, L_8013333C
    if (ctx->r10 != 0) {
        // 0x801332D8: addiu       $t4, $t3, 0xA0
        ctx->r12 = ADD32(ctx->r11, 0XA0);
            goto L_8013333C;
    }
    // 0x801332D8: addiu       $t4, $t3, 0xA0
    ctx->r12 = ADD32(ctx->r11, 0XA0);
    // 0x801332DC: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x801332E0: mflo        $t6
    ctx->r14 = lo;
    // 0x801332E4: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x801332E8: jal         0x800269C0
    // 0x801332EC: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_34;
    // 0x801332EC: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_34:
    // 0x801332F0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801332F4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801332F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801332FC: sw          $t5, 0x37BC($at)
    MEM_W(0X37BC, ctx->r1) = ctx->r13;
    // 0x80133300: jal         0x80009A84
    // 0x80133304: lw          $a0, 0x37C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37C8);
    gcEjectGObj(rdram, ctx);
        goto after_35;
    // 0x80133304: lw          $a0, 0x37C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37C8);
    after_35:
    // 0x80133308: jal         0x80131D98
    // 0x8013330C: nop

    mnOptionMakeSoundToggle(rdram, ctx);
        goto after_36;
    // 0x8013330C: nop

    after_36:
    // 0x80133310: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x80133314: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133318: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013331C: lw          $a0, 0x37D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37D0);
    // 0x80133320: jal         0x80009A84
    // 0x80133324: sw          $t7, 0x37E0($at)
    MEM_W(0X37E0, ctx->r1) = ctx->r15;
    gcEjectGObj(rdram, ctx);
        goto after_37;
    // 0x80133324: sw          $t7, 0x37E0($at)
    MEM_W(0X37E0, ctx->r1) = ctx->r15;
    after_37:
    // 0x80133328: jal         0x801321A8
    // 0x8013332C: nop

    mnOptionMakeMenuGObj(rdram, ctx);
        goto after_38;
    // 0x8013332C: nop

    after_38:
    // 0x80133330: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133334: jal         0x80020A34
    // 0x80133338: lw          $a0, 0x37BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37BC);
    syAudioSetQuality(rdram, ctx);
        goto after_39;
    // 0x80133338: lw          $a0, 0x37BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37BC);
    after_39:
L_8013333C:
    // 0x8013333C: jal         0x8039076C
    // 0x80133340: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_40;
    // 0x80133340: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_40:
    // 0x80133344: bne         $v0, $zero, L_8013336C
    if (ctx->r2 != 0) {
        // 0x80133348: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_8013336C;
    }
    // 0x80133348: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013334C: lw          $t8, 0x37E0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X37E0);
    // 0x80133350: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80133354: bne         $t8, $zero, L_801333E8
    if (ctx->r24 != 0) {
        // 0x80133358: nop
    
            goto L_801333E8;
    }
    // 0x80133358: nop

    // 0x8013335C: jal         0x8039089C
    // 0x80133360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_41;
    // 0x80133360: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_41:
    // 0x80133364: beq         $v0, $zero, L_801333E8
    if (ctx->r2 == 0) {
        // 0x80133368: sw          $v0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r2;
            goto L_801333E8;
    }
    // 0x80133368: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
L_8013336C:
    // 0x8013336C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133370: lw          $t9, 0x37BC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X37BC);
    // 0x80133374: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133378: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8013337C: bne         $t9, $at, L_801333E8
    if (ctx->r25 != ctx->r1) {
        // 0x80133380: addiu       $t1, $zero, 0xA0
        ctx->r9 = ADD32(0, 0XA0);
            goto L_801333E8;
    }
    // 0x80133380: addiu       $t1, $zero, 0xA0
    ctx->r9 = ADD32(0, 0XA0);
    // 0x80133384: subu        $t2, $t1, $t0
    ctx->r10 = SUB32(ctx->r9, ctx->r8);
    // 0x80133388: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013338C: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80133390: mflo        $t3
    ctx->r11 = lo;
    // 0x80133394: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x80133398: jal         0x800269C0
    // 0x8013339C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_42;
    // 0x8013339C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_42:
    // 0x801333A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801333A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801333A8: sw          $zero, 0x37BC($at)
    MEM_W(0X37BC, ctx->r1) = 0;
    // 0x801333AC: jal         0x80009A84
    // 0x801333B0: lw          $a0, 0x37C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37C8);
    gcEjectGObj(rdram, ctx);
        goto after_43;
    // 0x801333B0: lw          $a0, 0x37C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37C8);
    after_43:
    // 0x801333B4: jal         0x80131D98
    // 0x801333B8: nop

    mnOptionMakeSoundToggle(rdram, ctx);
        goto after_44;
    // 0x801333B8: nop

    after_44:
    // 0x801333BC: lw          $t4, 0x18($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X18);
    // 0x801333C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801333C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801333C8: lw          $a0, 0x37D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37D0);
    // 0x801333CC: jal         0x80009A84
    // 0x801333D0: sw          $t4, 0x37E0($at)
    MEM_W(0X37E0, ctx->r1) = ctx->r12;
    gcEjectGObj(rdram, ctx);
        goto after_45;
    // 0x801333D0: sw          $t4, 0x37E0($at)
    MEM_W(0X37E0, ctx->r1) = ctx->r12;
    after_45:
    // 0x801333D4: jal         0x801321A8
    // 0x801333D8: nop

    mnOptionMakeMenuGObj(rdram, ctx);
        goto after_46;
    // 0x801333D8: nop

    after_46:
    // 0x801333DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801333E0: jal         0x80020A34
    // 0x801333E4: lw          $a0, 0x37BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37BC);
    syAudioSetQuality(rdram, ctx);
        goto after_47;
    // 0x801333E4: lw          $a0, 0x37BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37BC);
    after_47:
L_801333E8:
    // 0x801333E8: jal         0x8039076C
    // 0x801333EC: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_48;
    // 0x801333EC: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    after_48:
    // 0x801333F0: beql        $v0, $zero, L_80133460
    if (ctx->r2 == 0) {
        // 0x801333F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80133460;
    }
    goto skip_1;
    // 0x801333F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801333F8: jal         0x800269C0
    // 0x801333FC: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_49;
    // 0x801333FC: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_49:
    // 0x80133400: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133404: lw          $t6, 0x37BC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X37BC);
    // 0x80133408: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013340C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80133410: bne         $t6, $at, L_80133424
    if (ctx->r14 != ctx->r1) {
        // 0x80133414: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80133424;
    }
    // 0x80133414: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133418: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013341C: b           L_8013342C
    // 0x80133420: sw          $zero, 0x37BC($at)
    MEM_W(0X37BC, ctx->r1) = 0;
        goto L_8013342C;
    // 0x80133420: sw          $zero, 0x37BC($at)
    MEM_W(0X37BC, ctx->r1) = 0;
L_80133424:
    // 0x80133424: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133428: sw          $t5, 0x37BC($at)
    MEM_W(0X37BC, ctx->r1) = ctx->r13;
L_8013342C:
    // 0x8013342C: jal         0x80009A84
    // 0x80133430: lw          $a0, 0x37C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37C8);
    gcEjectGObj(rdram, ctx);
        goto after_50;
    // 0x80133430: lw          $a0, 0x37C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37C8);
    after_50:
    // 0x80133434: jal         0x80131D98
    // 0x80133438: nop

    mnOptionMakeSoundToggle(rdram, ctx);
        goto after_51;
    // 0x80133438: nop

    after_51:
    // 0x8013343C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133440: jal         0x80009A84
    // 0x80133444: lw          $a0, 0x37D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37D0);
    gcEjectGObj(rdram, ctx);
        goto after_52;
    // 0x80133444: lw          $a0, 0x37D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37D0);
    after_52:
    // 0x80133448: jal         0x801321A8
    // 0x8013344C: nop

    mnOptionMakeMenuGObj(rdram, ctx);
        goto after_53;
    // 0x8013344C: nop

    after_53:
    // 0x80133450: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133454: jal         0x80020A34
    // 0x80133458: lw          $a0, 0x37BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37BC);
    syAudioSetQuality(rdram, ctx);
        goto after_54;
    // 0x80133458: lw          $a0, 0x37BC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X37BC);
    after_54:
L_8013345C:
    // 0x8013345C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133460:
    // 0x80133460: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80133464: jr          $ra
    // 0x80133468: nop

    return;
    // 0x80133468: nop

;}
RECOMP_FUNC void func_8001663C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001663C: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80016640: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80016644: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x80016648: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8001664C: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80016650: beq         $a2, $zero, L_80016664
    if (ctx->r6 == 0) {
        // 0x80016654: lw          $v1, 0x0($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X0);
            goto L_80016664;
    }
    // 0x80016654: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80016658: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8001665C: bnel        $a2, $at, L_800166A0
    if (ctx->r6 != ctx->r1) {
        // 0x80016660: lui         $t9, 0xDC08
        ctx->r25 = S32(0XDC08 << 16);
            goto L_800166A0;
    }
    goto skip_0;
    // 0x80016660: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    skip_0:
L_80016664:
    // 0x80016664: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80016668: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8001666C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80016670: lw          $t9, 0x80($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X80);
    // 0x80016674: andi        $t6, $t9, 0x20
    ctx->r14 = ctx->r25 & 0X20;
    // 0x80016678: beql        $t6, $zero, L_800166A0
    if (ctx->r14 == 0) {
        // 0x8001667C: lui         $t9, 0xDC08
        ctx->r25 = S32(0XDC08 << 16);
            goto L_800166A0;
    }
    goto skip_1;
    // 0x8001667C: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    skip_1:
    // 0x80016680: jal         0x80005344
    // 0x80016684: lhu         $a1, 0x6626($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6626);
    syTaskmanAppendGfxUcodeLoad(rdram, ctx);
        goto after_0;
    // 0x80016684: lhu         $a1, 0x6626($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X6626);
    after_0:
    // 0x80016688: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8001668C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80016690: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80016694: sh          $t7, 0x6628($at)
    MEM_H(0X6628, ctx->r1) = ctx->r15;
    // 0x80016698: lw          $v1, 0x0($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X0);
    // 0x8001669C: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
L_800166A0:
    // 0x800166A0: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x800166A4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800166A8: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800166AC: lw          $v0, 0x8C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X8C);
    // 0x800166B0: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x800166B4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800166B8: addiu       $v0, $v0, 0x8
    ctx->r2 = ADD32(ctx->r2, 0X8);
    // 0x800166BC: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x800166C0: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    // 0x800166C4: lh          $a2, 0x0($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X0);
    // 0x800166C8: lh          $a3, 0xA($v0)
    ctx->r7 = MEM_H(ctx->r2, 0XA);
    // 0x800166CC: lh          $t0, 0x2($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X2);
    // 0x800166D0: lw          $t5, 0x6678($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6678);
    // 0x800166D4: lw          $t6, -0x46C8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X46C8);
    // 0x800166D8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800166DC: bgez        $a1, L_800166E8
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800166E0: addu        $at, $a1, $zero
        ctx->r1 = ADD32(ctx->r5, 0);
            goto L_800166E8;
    }
    // 0x800166E0: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x800166E4: addiu       $at, $a1, 0x3
    ctx->r1 = ADD32(ctx->r5, 0X3);
L_800166E8:
    // 0x800166E8: sra         $a1, $at, 2
    ctx->r5 = S32(SIGNED(ctx->r1) >> 2);
    // 0x800166EC: bgez        $a2, L_800166F8
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800166F0: addu        $at, $a2, $zero
        ctx->r1 = ADD32(ctx->r6, 0);
            goto L_800166F8;
    }
    // 0x800166F0: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x800166F4: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
L_800166F8:
    // 0x800166F8: sra         $a2, $at, 2
    ctx->r6 = S32(SIGNED(ctx->r1) >> 2);
    // 0x800166FC: subu        $t3, $a1, $a2
    ctx->r11 = SUB32(ctx->r5, ctx->r6);
    // 0x80016700: bgez        $a3, L_8001670C
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80016704: addu        $at, $a3, $zero
        ctx->r1 = ADD32(ctx->r7, 0);
            goto L_8001670C;
    }
    // 0x80016704: addu        $at, $a3, $zero
    ctx->r1 = ADD32(ctx->r7, 0);
    // 0x80016708: addiu       $at, $a3, 0x3
    ctx->r1 = ADD32(ctx->r7, 0X3);
L_8001670C:
    // 0x8001670C: sra         $a3, $at, 2
    ctx->r7 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80016710: bgez        $t0, L_8001671C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80016714: addu        $at, $t0, $zero
        ctx->r1 = ADD32(ctx->r8, 0);
            goto L_8001671C;
    }
    // 0x80016714: addu        $at, $t0, $zero
    ctx->r1 = ADD32(ctx->r8, 0);
    // 0x80016718: addiu       $at, $t0, 0x3
    ctx->r1 = ADD32(ctx->r8, 0X3);
L_8001671C:
    // 0x8001671C: sra         $t0, $at, 2
    ctx->r8 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80016720: addiu       $at, $zero, 0x140
    ctx->r1 = ADD32(0, 0X140);
    // 0x80016724: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x80016728: mflo        $ra
    ctx->r31 = lo;
    // 0x8001672C: subu        $t4, $a3, $t0
    ctx->r12 = SUB32(ctx->r7, ctx->r8);
    // 0x80016730: addu        $t1, $a2, $a1
    ctx->r9 = ADD32(ctx->r6, ctx->r5);
    // 0x80016734: multu       $ra, $t6
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016738: addu        $t2, $t0, $a3
    ctx->r10 = ADD32(ctx->r8, ctx->r7);
    // 0x8001673C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80016740: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80016744: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80016748: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8001674C: mflo        $t7
    ctx->r15 = lo;
    // 0x80016750: slt         $at, $t3, $t7
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80016754: beq         $at, $zero, L_80016760
    if (ctx->r1 == 0) {
        // 0x80016758: sw          $t7, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r15;
            goto L_80016760;
    }
    // 0x80016758: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8001675C: or          $t3, $t7, $zero
    ctx->r11 = ctx->r15 | 0;
L_80016760:
    // 0x80016760: lw          $v0, 0x667C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X667C);
    // 0x80016764: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x80016768: lw          $t9, -0x46D0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X46D0);
    // 0x8001676C: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80016770: mflo        $a0
    ctx->r4 = lo;
    // 0x80016774: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80016778: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x8001677C: multu       $a0, $t9
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80016780: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x80016784: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80016788: mflo        $a1
    ctx->r5 = lo;
    // 0x8001678C: slt         $at, $t4, $a1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80016790: beq         $at, $zero, L_8001679C
    if (ctx->r1 == 0) {
        // 0x80016794: nop
    
            goto L_8001679C;
    }
    // 0x80016794: nop

    // 0x80016798: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_8001679C:
    // 0x8001679C: lw          $t6, -0x46C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X46C4);
    // 0x800167A0: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800167A4: multu       $ra, $t6
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800167A8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800167AC: mflo        $t7
    ctx->r15 = lo;
    // 0x800167B0: subu        $a1, $t5, $t7
    ctx->r5 = SUB32(ctx->r13, ctx->r15);
    // 0x800167B4: slt         $at, $a1, $t1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800167B8: beq         $at, $zero, L_800167C4
    if (ctx->r1 == 0) {
        // 0x800167BC: nop
    
            goto L_800167C4;
    }
    // 0x800167BC: nop

    // 0x800167C0: or          $t1, $a1, $zero
    ctx->r9 = ctx->r5 | 0;
L_800167C4:
    // 0x800167C4: lw          $t8, -0x46CC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X46CC);
    // 0x800167C8: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x800167CC: addiu       $t5, $t5, 0x6678
    ctx->r13 = ADD32(ctx->r13, 0X6678);
    // 0x800167D0: multu       $a0, $t8
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800167D4: mflo        $t9
    ctx->r25 = lo;
    // 0x800167D8: subu        $a1, $v0, $t9
    ctx->r5 = SUB32(ctx->r2, ctx->r25);
    // 0x800167DC: slt         $at, $a1, $t2
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800167E0: beql        $at, $zero, L_800167F0
    if (ctx->r1 == 0) {
        // 0x800167E4: lui         $at, 0x4080
        ctx->r1 = S32(0X4080 << 16);
            goto L_800167F0;
    }
    goto skip_2;
    // 0x800167E4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    skip_2:
    // 0x800167E8: or          $t2, $a1, $zero
    ctx->r10 = ctx->r5 | 0;
    // 0x800167EC: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
L_800167F0:
    // 0x800167F0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800167F4: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x800167F8: lw          $ra, 0x8C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X8C);
    // 0x800167FC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80016800: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016804: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016808: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001680C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80016810: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80016814: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x80016818: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8001681C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80016820: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80016824: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80016828: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8001682C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x80016830: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80016834: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80016838: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8001683C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80016840: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80016844: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80016848: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8001684C: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x80016850: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80016854: lui         $at, 0xFF10
    ctx->r1 = S32(0XFF10 << 16);
    // 0x80016858: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8001685C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80016860: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80016864: nop

    // 0x80016868: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8001686C: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x80016870: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80016874: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80016878: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8001687C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80016880: lw          $t6, 0x80($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X80);
    // 0x80016884: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016888: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8001688C: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80016890: beq         $t7, $zero, L_80016950
    if (ctx->r15 == 0) {
        // 0x80016894: lui         $t8, 0xE300
        ctx->r24 = S32(0XE300 << 16);
            goto L_80016950;
    }
    // 0x80016894: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80016898: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001689C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800168A0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800168A4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800168A8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800168AC: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x800168B0: lui         $t6, 0x30
    ctx->r14 = S32(0X30 << 16);
    // 0x800168B4: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800168B8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800168BC: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800168C0: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800168C4: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800168C8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800168CC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800168D0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x800168D4: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x800168D8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x800168DC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800168E0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800168E4: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800168E8: lw          $t7, 0x6670($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6670);
    // 0x800168EC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800168F0: lui         $t8, 0xFFFC
    ctx->r24 = S32(0XFFFC << 16);
    // 0x800168F4: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x800168F8: ori         $t8, $t8, 0xFFFC
    ctx->r24 = ctx->r24 | 0XFFFC;
    // 0x800168FC: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
    // 0x80016900: andi        $t6, $t1, 0x3FF
    ctx->r14 = ctx->r9 & 0X3FF;
    // 0x80016904: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80016908: lui         $t9, 0xF700
    ctx->r25 = S32(0XF700 << 16);
    // 0x8001690C: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80016910: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80016914: andi        $t8, $t2, 0x3FF
    ctx->r24 = ctx->r10 & 0X3FF;
    // 0x80016918: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x8001691C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80016920: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80016924: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80016928: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8001692C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016930: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80016934: andi        $t6, $t4, 0x3FF
    ctx->r14 = ctx->r12 & 0X3FF;
    // 0x80016938: andi        $t8, $t3, 0x3FF
    ctx->r24 = ctx->r11 & 0X3FF;
    // 0x8001693C: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x80016940: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80016944: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80016948: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001694C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80016950:
    // 0x80016950: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016954: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80016958: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8001695C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80016960: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80016964: lw          $t9, 0x6674($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6674);
    // 0x80016968: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x8001696C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016970: andi        $t7, $t9, 0x3
    ctx->r15 = ctx->r25 & 0X3;
    // 0x80016974: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x80016978: sll         $t8, $t7, 19
    ctx->r24 = S32(ctx->r15 << 19);
    // 0x8001697C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80016980: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x80016984: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80016988: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001698C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80016990: lui         $t7, 0xF00
    ctx->r15 = S32(0XF00 << 16);
    // 0x80016994: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x80016998: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8001699C: lw          $t6, 0x80($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X80);
    // 0x800169A0: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x800169A4: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x800169A8: andi        $t8, $t6, 0x2
    ctx->r24 = ctx->r14 & 0X2;
    // 0x800169AC: beq         $t8, $zero, L_80016A5C
    if (ctx->r24 == 0) {
        // 0x800169B0: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_80016A5C;
    }
    // 0x800169B0: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800169B4: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x800169B8: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x800169BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800169C0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800169C4: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x800169C8: lui         $t7, 0x30
    ctx->r15 = S32(0X30 << 16);
    // 0x800169CC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800169D0: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800169D4: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x800169D8: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x800169DC: lui         $t6, 0xF700
    ctx->r14 = S32(0XF700 << 16);
    // 0x800169E0: andi        $t8, $t1, 0x3FF
    ctx->r24 = ctx->r9 & 0X3FF;
    // 0x800169E4: sll         $t9, $t8, 14
    ctx->r25 = S32(ctx->r24 << 14);
    // 0x800169E8: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800169EC: andi        $t6, $t2, 0x3FF
    ctx->r14 = ctx->r10 & 0X3FF;
    // 0x800169F0: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800169F4: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800169F8: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800169FC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80016A00: lw          $a0, 0x84($ra)
    ctx->r4 = MEM_W(ctx->r31, 0X84);
    // 0x80016A04: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
    // 0x80016A08: andi        $t8, $t4, 0x3FF
    ctx->r24 = ctx->r12 & 0X3FF;
    // 0x80016A0C: andi        $t6, $t3, 0x3FF
    ctx->r14 = ctx->r11 & 0X3FF;
    // 0x80016A10: sll         $t7, $t6, 14
    ctx->r15 = S32(ctx->r14 << 14);
    // 0x80016A14: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80016A18: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x80016A1C: addiu       $v1, $a2, 0x8
    ctx->r3 = ADD32(ctx->r6, 0X8);
    // 0x80016A20: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    // 0x80016A24: sw          $t6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r14;
    // 0x80016A28: jal         0x80006D70
    // 0x80016A2C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    syVideoGetFillColor(rdram, ctx);
        goto after_1;
    // 0x80016A2C: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    after_1:
    // 0x80016A30: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80016A34: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x80016A38: lui         $t0, 0xE200
    ctx->r8 = S32(0XE200 << 16);
    // 0x80016A3C: sw          $v0, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r2;
    // 0x80016A40: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80016A44: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80016A48: ori         $t0, $t0, 0x1C
    ctx->r8 = ctx->r8 | 0X1C;
    // 0x80016A4C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80016A50: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80016A54: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016A58: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
L_80016A5C:
    // 0x80016A5C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016A60: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016A64: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80016A68: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80016A6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80016A70: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80016A74: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80016A78: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80016A7C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80016A80: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80016A84: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x80016A88: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016A8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80016A90: beq         $t8, $zero, L_80016AA0
    if (ctx->r24 == 0) {
        // 0x80016A94: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80016AA0;
    }
    // 0x80016A94: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016A98: bne         $t8, $at, L_80016AB8
    if (ctx->r24 != ctx->r1) {
        // 0x80016A9C: lui         $t9, 0x50
        ctx->r25 = S32(0X50 << 16);
            goto L_80016AB8;
    }
    // 0x80016A9C: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
L_80016AA0:
    // 0x80016AA0: lui         $t7, 0x55
    ctx->r15 = S32(0X55 << 16);
    // 0x80016AA4: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x80016AA8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80016AAC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80016AB0: b           L_80016ACC
    // 0x80016AB4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
        goto L_80016ACC;
    // 0x80016AB4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
L_80016AB8:
    // 0x80016AB8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80016ABC: ori         $t9, $t9, 0x49D8
    ctx->r25 = ctx->r25 | 0X49D8;
    // 0x80016AC0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80016AC4: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x80016AC8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
L_80016ACC:
    // 0x80016ACC: lw          $t6, 0x88($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X88);
    // 0x80016AD0: sw          $v1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r3;
    // 0x80016AD4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80016AD8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x80016ADC: jr          $ra
    // 0x80016AE0: nop

    return;
    // 0x80016AE0: nop

;}
RECOMP_FUNC void ftCommonLGunShootAirProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801471E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801471E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801471EC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x801471F0: jal         0x800DE6E4
    // 0x801471F4: addiu       $a1, $a1, 0x7208
    ctx->r5 = ADD32(ctx->r5, 0X7208);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801471F4: addiu       $a1, $a1, 0x7208
    ctx->r5 = ADD32(ctx->r5, 0X7208);
    after_0:
    // 0x801471F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801471FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80147200: jr          $ra
    // 0x80147204: nop

    return;
    // 0x80147204: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164788: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016478C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164790: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80164794: jal         0x800DE6E4
    // 0x80164798: addiu       $a1, $a1, 0x4860
    ctx->r5 = ADD32(ctx->r5, 0X4860);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80164798: addiu       $a1, $a1, 0x4860
    ctx->r5 = ADD32(ctx->r5, 0X4860);
    after_0:
    // 0x8016479C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801647A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801647A4: jr          $ra
    // 0x801647A8: nop

    return;
    // 0x801647A8: nop

;}
RECOMP_FUNC void func_ovl8_8037F784(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037F784: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8037F788: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037F78C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8037F790: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x8037F794: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8037F798: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8037F79C: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8037F7A0: lh          $t6, 0xB0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XB0);
    // 0x8037F7A4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8037F7A8: lw          $t9, 0xB4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XB4);
    // 0x8037F7AC: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    // 0x8037F7B0: jalr        $t9
    // 0x8037F7B4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037F7B4: nop

    after_0:
    // 0x8037F7B8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8037F7BC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8037F7C0: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x8037F7C4: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x8037F7C8: lh          $t7, 0xD0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XD0);
    // 0x8037F7CC: jalr        $t9
    // 0x8037F7D0: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x8037F7D0: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_1:
    // 0x8037F7D4: lwl         $t8, 0x34($sp)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r29, 0X34);
    // 0x8037F7D8: lwr         $t8, 0x37($sp)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r29, 0X37);
    // 0x8037F7DC: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8037F7E0: swl         $t8, 0x0($sp)
    do_swl(rdram, 0X0, ctx->r29, ctx->r24);
    // 0x8037F7E4: swr         $t8, 0x3($sp)
    do_swr(rdram, 0X3, ctx->r29, ctx->r24);
    // 0x8037F7E8: jal         0x80377168
    // 0x8037F7EC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    func_ovl8_80377168(rdram, ctx);
        goto after_2;
    // 0x8037F7EC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    after_2:
    // 0x8037F7F0: bne         $v0, $zero, L_8037F800
    if (ctx->r2 != 0) {
        // 0x8037F7F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037F800;
    }
    // 0x8037F7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037F7F8: b           L_8037F804
    // 0x8037F7FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8037F804;
    // 0x8037F7FC: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_8037F800:
    // 0x8037F800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037F804:
    // 0x8037F804: jr          $ra
    // 0x8037F808: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8037F808: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayers1PTrainingCheckFighterCrossed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D84: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80131D88: jr          $ra
    // 0x80131D8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80131D8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void ftKirbyCopyFoxSpecialNProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156CB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80156CB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156CB8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156CBC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80156CC0: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x80156CC4: lw          $t6, 0x17C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X17C);
    // 0x80156CC8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80156CCC: beql        $t6, $zero, L_80156D0C
    if (ctx->r14 == 0) {
        // 0x80156CD0: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80156D0C;
    }
    goto skip_0;
    // 0x80156CD0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_0:
    // 0x80156CD4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80156CD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80156CDC: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80156CE0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80156CE4: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80156CE8: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x80156CEC: lw          $a0, 0x92C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X92C);
    // 0x80156CF0: jal         0x800EDF24
    // 0x80156CF4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x80156CF4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    after_0:
    // 0x80156CF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80156CFC: jal         0x80168A74
    // 0x80156D00: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    wpFoxBlasterMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x80156D00: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x80156D04: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80156D08: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80156D0C:
    // 0x80156D0C: lwc1        $f8, 0x78($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X78);
    // 0x80156D10: c.le.s      $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f8.fl <= ctx->f6.fl;
    // 0x80156D14: nop

    // 0x80156D18: bc1fl       L_80156D2C
    if (!c1cs) {
        // 0x80156D1C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80156D2C;
    }
    goto skip_1;
    // 0x80156D1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80156D20: jal         0x800DEE54
    // 0x80156D24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    mpCommonSetFighterWaitOrFall(rdram, ctx);
        goto after_2;
    // 0x80156D24: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x80156D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80156D2C:
    // 0x80156D2C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80156D30: jr          $ra
    // 0x80156D34: nop

    return;
    // 0x80156D34: nop

;}
RECOMP_FUNC void mnVSItemSwitchSetItemSettings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801327B8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801327BC: lw          $t6, 0x3420($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3420);
    // 0x801327C0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x801327C4: addiu       $a1, $a1, 0x4D08
    ctx->r5 = ADD32(ctx->r5, 0X4D08);
    // 0x801327C8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801327CC: sb          $t6, 0x1C($a1)
    MEM_B(0X1C, ctx->r5) = ctx->r14;
    // 0x801327D0: lw          $t7, 0x3424($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3424);
    // 0x801327D4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801327D8: addiu       $v1, $v1, 0x3428
    ctx->r3 = ADD32(ctx->r3, 0X3428);
    // 0x801327DC: beq         $t7, $zero, L_80132824
    if (ctx->r15 == 0) {
        // 0x801327E0: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80132824;
    }
    // 0x801327E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801327E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801327E8: lw          $v0, 0x3214($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3214);
    // 0x801327EC: lw          $t8, 0xC($a1)
    ctx->r24 = MEM_W(ctx->r5, 0XC);
    // 0x801327F0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801327F4: sllv        $t2, $t9, $v0
    ctx->r10 = S32(ctx->r25 << (ctx->r2 & 31));
    // 0x801327F8: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x801327FC: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80132800: or          $t3, $t8, $t2
    ctx->r11 = ctx->r24 | ctx->r10;
    // 0x80132804: bne         $a2, $v0, L_8013281C
    if (ctx->r6 != ctx->r2) {
        // 0x80132808: sw          $t3, 0x4D14($at)
        MEM_W(0X4D14, ctx->r1) = ctx->r11;
            goto L_8013281C;
    }
    // 0x80132808: sw          $t3, 0x4D14($at)
    MEM_W(0X4D14, ctx->r1) = ctx->r11;
    // 0x8013280C: lw          $t4, 0xC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XC);
    // 0x80132810: lui         $a3, 0x4
    ctx->r7 = S32(0X4 << 16);
    // 0x80132814: or          $t5, $t4, $a3
    ctx->r13 = ctx->r12 | ctx->r7;
    // 0x80132818: sw          $t5, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r13;
L_8013281C:
    // 0x8013281C: b           L_80132868
    // 0x80132820: lui         $t0, 0xFFFB
    ctx->r8 = S32(0XFFFB << 16);
        goto L_80132868;
    // 0x80132820: lui         $t0, 0xFFFB
    ctx->r8 = S32(0XFFFB << 16);
L_80132824:
    // 0x80132824: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132828: lw          $v0, 0x3214($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3214);
    // 0x8013282C: lw          $t6, 0xC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0XC);
    // 0x80132830: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132834: sllv        $t9, $t7, $v0
    ctx->r25 = S32(ctx->r15 << (ctx->r2 & 31));
    // 0x80132838: nor         $t8, $t9, $zero
    ctx->r24 = ~(ctx->r25 | 0);
    // 0x8013283C: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132840: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80132844: and         $t2, $t6, $t8
    ctx->r10 = ctx->r14 & ctx->r24;
    // 0x80132848: bne         $a2, $v0, L_80132864
    if (ctx->r6 != ctx->r2) {
        // 0x8013284C: sw          $t2, 0x4D14($at)
        MEM_W(0X4D14, ctx->r1) = ctx->r10;
            goto L_80132864;
    }
    // 0x8013284C: sw          $t2, 0x4D14($at)
    MEM_W(0X4D14, ctx->r1) = ctx->r10;
    // 0x80132850: lw          $t3, 0xC($a1)
    ctx->r11 = MEM_W(ctx->r5, 0XC);
    // 0x80132854: lui         $t0, 0xFFFB
    ctx->r8 = S32(0XFFFB << 16);
    // 0x80132858: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x8013285C: and         $t4, $t3, $t0
    ctx->r12 = ctx->r11 & ctx->r8;
    // 0x80132860: sw          $t4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r12;
L_80132864:
    // 0x80132864: lui         $t0, 0xFFFB
    ctx->r8 = S32(0XFFFB << 16);
L_80132868:
    // 0x80132868: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013286C: addiu       $t1, $t1, 0x3250
    ctx->r9 = ADD32(ctx->r9, 0X3250);
    // 0x80132870: ori         $t0, $t0, 0xFFFF
    ctx->r8 = ctx->r8 | 0XFFFF;
    // 0x80132874: lui         $a3, 0x4
    ctx->r7 = S32(0X4 << 16);
    // 0x80132878: addiu       $a0, $a0, 0x3218
    ctx->r4 = ADD32(ctx->r4, 0X3218);
L_8013287C:
    // 0x8013287C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80132880: beql        $t5, $zero, L_801328B4
    if (ctx->r13 == 0) {
        // 0x80132884: lw          $v0, 0x0($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X0);
            goto L_801328B4;
    }
    goto skip_0;
    // 0x80132884: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    skip_0:
    // 0x80132888: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8013288C: lw          $t7, 0xC($a1)
    ctx->r15 = MEM_W(ctx->r5, 0XC);
    // 0x80132890: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132894: sllv        $t6, $t9, $v0
    ctx->r14 = S32(ctx->r25 << (ctx->r2 & 31));
    // 0x80132898: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8013289C: bne         $a2, $v0, L_801328D8
    if (ctx->r6 != ctx->r2) {
        // 0x801328A0: sw          $t8, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->r24;
            goto L_801328D8;
    }
    // 0x801328A0: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
    // 0x801328A4: or          $t3, $t8, $a3
    ctx->r11 = ctx->r24 | ctx->r7;
    // 0x801328A8: b           L_801328D8
    // 0x801328AC: sw          $t3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r11;
        goto L_801328D8;
    // 0x801328AC: sw          $t3, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r11;
    // 0x801328B0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
L_801328B4:
    // 0x801328B4: lw          $t4, 0xC($a1)
    ctx->r12 = MEM_W(ctx->r5, 0XC);
    // 0x801328B8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801328BC: sllv        $t9, $t5, $v0
    ctx->r25 = S32(ctx->r13 << (ctx->r2 & 31));
    // 0x801328C0: nor         $t7, $t9, $zero
    ctx->r15 = ~(ctx->r25 | 0);
    // 0x801328C4: and         $t6, $t4, $t7
    ctx->r14 = ctx->r12 & ctx->r15;
    // 0x801328C8: bne         $a2, $v0, L_801328D8
    if (ctx->r6 != ctx->r2) {
        // 0x801328CC: sw          $t6, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->r14;
            goto L_801328D8;
    }
    // 0x801328CC: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
    // 0x801328D0: and         $t2, $t6, $t0
    ctx->r10 = ctx->r14 & ctx->r8;
    // 0x801328D4: sw          $t2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r10;
L_801328D8:
    // 0x801328D8: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x801328DC: beql        $t3, $zero, L_80132910
    if (ctx->r11 == 0) {
        // 0x801328E0: lw          $v0, 0x4($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X4);
            goto L_80132910;
    }
    goto skip_1;
    // 0x801328E0: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    skip_1:
    // 0x801328E4: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
    // 0x801328E8: lw          $t5, 0xC($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XC);
    // 0x801328EC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801328F0: sllv        $t4, $t9, $v0
    ctx->r12 = S32(ctx->r25 << (ctx->r2 & 31));
    // 0x801328F4: or          $t7, $t5, $t4
    ctx->r15 = ctx->r13 | ctx->r12;
    // 0x801328F8: bne         $a2, $v0, L_80132934
    if (ctx->r6 != ctx->r2) {
        // 0x801328FC: sw          $t7, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->r15;
            goto L_80132934;
    }
    // 0x801328FC: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x80132900: or          $t8, $t7, $a3
    ctx->r24 = ctx->r15 | ctx->r7;
    // 0x80132904: b           L_80132934
    // 0x80132908: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
        goto L_80132934;
    // 0x80132908: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
    // 0x8013290C: lw          $v0, 0x4($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4);
L_80132910:
    // 0x80132910: lw          $t2, 0xC($a1)
    ctx->r10 = MEM_W(ctx->r5, 0XC);
    // 0x80132914: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80132918: sllv        $t9, $t3, $v0
    ctx->r25 = S32(ctx->r11 << (ctx->r2 & 31));
    // 0x8013291C: nor         $t5, $t9, $zero
    ctx->r13 = ~(ctx->r25 | 0);
    // 0x80132920: and         $t4, $t2, $t5
    ctx->r12 = ctx->r10 & ctx->r13;
    // 0x80132924: bne         $a2, $v0, L_80132934
    if (ctx->r6 != ctx->r2) {
        // 0x80132928: sw          $t4, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->r12;
            goto L_80132934;
    }
    // 0x80132928: sw          $t4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r12;
    // 0x8013292C: and         $t6, $t4, $t0
    ctx->r14 = ctx->r12 & ctx->r8;
    // 0x80132930: sw          $t6, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r14;
L_80132934:
    // 0x80132934: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x80132938: bne         $a0, $t1, L_8013287C
    if (ctx->r4 != ctx->r9) {
        // 0x8013293C: addiu       $v1, $v1, 0x8
        ctx->r3 = ADD32(ctx->r3, 0X8);
            goto L_8013287C;
    }
    // 0x8013293C: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80132940: jr          $ra
    // 0x80132944: nop

    return;
    // 0x80132944: nop

;}
RECOMP_FUNC void itPippiWeaponSwarmRenderSwarm(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180400: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80180404: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x80180408: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8018040C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80180410: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180414: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80180418: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8018041C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80180420: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80180424: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80180428: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8018042C: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x80180430: lui         $t0, 0x50
    ctx->r8 = S32(0X50 << 16);
    // 0x80180434: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80180438: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8018043C: ori         $t0, $t0, 0x41C8
    ctx->r8 = ctx->r8 | 0X41C8;
    // 0x80180440: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80180444: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80180448: jal         0x80014038
    // 0x8018044C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x8018044C: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    after_0:
    // 0x80180450: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80180454: addiu       $a2, $a2, 0x65B0
    ctx->r6 = ADD32(ctx->r6, 0X65B0);
    // 0x80180458: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8018045C: lui         $t2, 0xE700
    ctx->r10 = S32(0XE700 << 16);
    // 0x80180460: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80180464: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80180468: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018046C: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x80180470: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180474: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80180478: jr          $ra
    // 0x8018047C: nop

    return;
    // 0x8018047C: nop

;}
RECOMP_FUNC void ftMarioSpecialAirNSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155F4C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80155F50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155F54: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80155F58: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80155F5C: jal         0x800DEE98
    // 0x80155F60: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80155F60: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80155F64: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80155F68: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80155F6C: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x80155F70: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80155F74: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80155F78: jal         0x800E6F24
    // 0x80155F7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80155F7C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80155F80: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80155F84: lui         $t8, 0x8015
    ctx->r24 = S32(0X8015 << 16);
    // 0x80155F88: addiu       $t8, $t8, 0x5E64
    ctx->r24 = ADD32(ctx->r24, 0X5E64);
    // 0x80155F8C: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x80155F90: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155F94: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80155F98: jr          $ra
    // 0x80155F9C: nop

    return;
    // 0x80155F9C: nop

;}
RECOMP_FUNC void func_ovl8_80373118(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037311C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373120: jal         0x80371DD0
    // 0x80373124: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    func_ovl8_80371DD0(rdram, ctx);
        goto after_0;
    // 0x80373124: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    after_0:
    // 0x80373128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037312C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80373130: jr          $ra
    // 0x80373134: nop

    return;
    // 0x80373134: nop

;}
RECOMP_FUNC void func_ovl8_80386488(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386488: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038648C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80386490: sw          $a0, 0x3C8($at)
    MEM_W(0X3C8, ctx->r1) = ctx->r4;
    // 0x80386494: jr          $ra
    // 0x80386498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80386498: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void syVectorNormCross3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80019980: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80019984: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80019988: lwc1        $f4, 0x4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8001998C: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x80019990: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x80019994: lwc1        $f10, 0x8($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X8);
    // 0x80019998: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001999C: nop

    // 0x800199A0: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800199A4: sub.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800199A8: swc1        $f4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f4.u32l;
    // 0x800199AC: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800199B0: lwc1        $f6, 0x8($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800199B4: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800199B8: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800199BC: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800199C0: nop

    // 0x800199C4: mul.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x800199C8: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800199CC: swc1        $f6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->f6.u32l;
    // 0x800199D0: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800199D4: lwc1        $f10, 0x0($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800199D8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800199DC: lwc1        $f16, 0x4($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800199E0: mul.s       $f18, $f10, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800199E4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800199E8: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800199EC: sub.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800199F0: swc1        $f10, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f10.u32l;
    // 0x800199F4: jal         0x80018EE0
    // 0x800199F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    syVectorNorm3D(rdram, ctx);
        goto after_0;
    // 0x800199F8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800199FC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80019A00: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80019A04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80019A08: c.eq.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl == ctx->f8.fl;
    // 0x80019A0C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80019A10: bc1t        L_80019A20
    if (c1cs) {
        // 0x80019A14: nop
    
            goto L_80019A20;
    }
    // 0x80019A14: nop

    // 0x80019A18: b           L_80019A20
    // 0x80019A1C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
        goto L_80019A20;
    // 0x80019A1C: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80019A20:
    // 0x80019A20: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80019A24: jr          $ra
    // 0x80019A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80019A28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftPurinSpecialHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151550: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151554: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151558: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015155C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80151560: lw          $t6, 0x180($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X180);
    // 0x80151564: bnel        $t6, $at, L_80151598
    if (ctx->r14 != ctx->r1) {
        // 0x80151568: lw          $t0, 0x24($v1)
        ctx->r8 = MEM_W(ctx->r3, 0X24);
            goto L_80151598;
    }
    goto skip_0;
    // 0x80151568: lw          $t0, 0x24($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X24);
    skip_0:
    // 0x8015156C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80151570: jal         0x801020F4
    // 0x80151574: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    efManagerPurinSingMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80151574: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151578: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015157C: beq         $v0, $zero, L_80151590
    if (ctx->r2 == 0) {
        // 0x80151580: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80151590;
    }
    // 0x80151580: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80151584: lbu         $t8, 0x18F($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X18F);
    // 0x80151588: ori         $t9, $t8, 0x10
    ctx->r25 = ctx->r24 | 0X10;
    // 0x8015158C: sb          $t9, 0x18F($v1)
    MEM_B(0X18F, ctx->r3) = ctx->r25;
L_80151590:
    // 0x80151590: sw          $zero, 0x180($v1)
    MEM_W(0X180, ctx->r3) = 0;
    // 0x80151594: lw          $t0, 0x24($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X24);
L_80151598:
    // 0x80151598: addiu       $at, $zero, 0xE8
    ctx->r1 = ADD32(0, 0XE8);
    // 0x8015159C: bne         $t0, $at, L_801515B4
    if (ctx->r8 != ctx->r1) {
        // 0x801515A0: nop
    
            goto L_801515B4;
    }
    // 0x801515A0: nop

    // 0x801515A4: jal         0x800D94C4
    // 0x801515A8: nop

    ftAnimEndSetWait(rdram, ctx);
        goto after_1;
    // 0x801515A8: nop

    after_1:
    // 0x801515AC: b           L_801515C0
    // 0x801515B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801515C0;
    // 0x801515B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801515B4:
    // 0x801515B4: jal         0x800D94E8
    // 0x801515B8: nop

    ftAnimEndSetFall(rdram, ctx);
        goto after_2;
    // 0x801515B8: nop

    after_2:
    // 0x801515BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801515C0:
    // 0x801515C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801515C4: jr          $ra
    // 0x801515C8: nop

    return;
    // 0x801515C8: nop

;}
RECOMP_FUNC void ftCommonYoshiEggSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014CF20: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014CF24: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014CF28: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8014CF2C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8014CF30: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014CF34: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8014CF38: lw          $t6, 0x14C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X14C);
    // 0x8014CF3C: bne         $t6, $zero, L_8014CF4C
    if (ctx->r14 != 0) {
        // 0x8014CF40: nop
    
            goto L_8014CF4C;
    }
    // 0x8014CF40: nop

    // 0x8014CF44: jal         0x800DEEC8
    // 0x8014CF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8014CF48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_8014CF4C:
    // 0x8014CF4C: lui         $t7, 0x8015
    ctx->r15 = S32(0X8015 << 16);
    // 0x8014CF50: addiu       $t7, $t7, -0x30F4
    ctx->r15 = ADD32(ctx->r15, -0X30F4);
    // 0x8014CF54: sw          $t7, 0xA0C($s0)
    MEM_W(0XA0C, ctx->r16) = ctx->r15;
    // 0x8014CF58: jal         0x800DEEC8
    // 0x8014CF5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_1;
    // 0x8014CF5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8014CF60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8014CF64: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014CF68: addiu       $a1, $zero, 0xB2
    ctx->r5 = ADD32(0, 0XB2);
    // 0x8014CF6C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8014CF70: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8014CF74: jal         0x800E6F24
    // 0x8014CF78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x8014CF78: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8014CF7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014CF80: jal         0x800E8098
    // 0x8014CF84: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_3;
    // 0x8014CF84: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_3:
    // 0x8014CF88: lbu         $t9, 0x18D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18D);
    // 0x8014CF8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014CF90: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x8014CF94: jal         0x8014CDFC
    // 0x8014CF98: sb          $t1, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r9;
    ftCommonYoshiEggSetDamageCollCollisions(rdram, ctx);
        goto after_4;
    // 0x8014CF98: sb          $t1, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r9;
    after_4:
    // 0x8014CF9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014CFA0: jal         0x8014E3EC
    // 0x8014CFA4: addiu       $a1, $zero, 0x2EE
    ctx->r5 = ADD32(0, 0X2EE);
    ftCommonCaptureTrappedInitBreakoutVars(rdram, ctx);
        goto after_5;
    // 0x8014CFA4: addiu       $a1, $zero, 0x2EE
    ctx->r5 = ADD32(0, 0X2EE);
    after_5:
    // 0x8014CFA8: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
    // 0x8014CFAC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8014CFB0: jal         0x80161CA0
    // 0x8014CFB4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    ftKirbySpecialNApplyCaptureDamage(rdram, ctx);
        goto after_6;
    // 0x8014CFB4: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    after_6:
    // 0x8014CFB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014CFBC: jal         0x800E7F7C
    // 0x8014CFC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamSetPlayerTagWait(rdram, ctx);
        goto after_7;
    // 0x8014CFC0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_7:
    // 0x8014CFC4: lw          $v0, 0x844($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X844);
    // 0x8014CFC8: lw          $t2, 0x74($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X74);
    // 0x8014CFCC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8014CFD0: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x8014CFD4: lw          $t0, 0x84($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X84);
    // 0x8014CFD8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014CFDC: lw          $t5, 0x1C($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X1C);
    // 0x8014CFE0: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x8014CFE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8014CFE8: sw          $t5, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->r13;
    // 0x8014CFEC: lw          $t4, 0x20($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X20);
    // 0x8014CFF0: sw          $t4, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->r12;
    // 0x8014CFF4: lw          $t5, 0x24($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X24);
    // 0x8014CFF8: sw          $t5, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->r13;
    // 0x8014CFFC: lw          $t6, 0x44($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X44);
    // 0x8014D000: lw          $v1, 0x74($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X74);
    // 0x8014D004: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8014D008: lwc1        $f16, 0x1C($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8014D00C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014D010: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8014D014: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014D018: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x8014D01C: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x8014D020: lw          $v1, 0x74($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X74);
    // 0x8014D024: lwc1        $f4, 0x20($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X20);
    // 0x8014D028: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8014D02C: swc1        $f8, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f8.u32l;
    // 0x8014D030: lw          $v0, 0x844($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X844);
    // 0x8014D034: lw          $a1, 0x74($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X74);
    // 0x8014D038: lw          $a2, 0x84($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X84);
    // 0x8014D03C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x8014D040: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    // 0x8014D044: jal         0x800DF014
    // 0x8014D048: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    mpCommonRunFighterCollisionDefault(rdram, ctx);
        goto after_8;
    // 0x8014D048: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    after_8:
    // 0x8014D04C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8014D050: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x8014D054: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8014D058: lw          $t7, 0x44($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X44);
    // 0x8014D05C: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x8014D060: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8014D064: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8014D068: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x8014D06C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8014D070: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8014D074: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8014D078: lui         $t9, 0x8015
    ctx->r25 = S32(0X8015 << 16);
    // 0x8014D07C: addiu       $t9, $t9, -0x3284
    ctx->r25 = ADD32(ctx->r25, -0X3284);
    // 0x8014D080: sw          $zero, 0x844($s0)
    MEM_W(0X844, ctx->r16) = 0;
    // 0x8014D084: sw          $t9, 0x9F0($s0)
    MEM_W(0X9F0, ctx->r16) = ctx->r25;
    // 0x8014D088: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x8014D08C: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8014D090: swc1        $f8, 0x81C($s0)
    MEM_W(0X81C, ctx->r16) = ctx->f8.u32l;
    // 0x8014D094: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8014D098: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8014D09C: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x8014D0A0: lw          $t1, 0x44($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X44);
    // 0x8014D0A4: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x8014D0A8: sb          $zero, 0xB21($s0)
    MEM_B(0XB21, ctx->r16) = 0;
    // 0x8014D0AC: sb          $t1, 0xB20($s0)
    MEM_B(0XB20, ctx->r16) = ctx->r9;
    // 0x8014D0B0: lhu         $t2, 0x28E($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X28E);
    // 0x8014D0B4: lw          $a3, 0x8($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X8);
    // 0x8014D0B8: lbu         $a1, 0xD($t0)
    ctx->r5 = MEM_BU(ctx->r8, 0XD);
    // 0x8014D0BC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8014D0C0: lhu         $t3, 0x290($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X290);
    // 0x8014D0C4: jal         0x800EAA2C
    // 0x8014D0C8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    ftParamUpdate1PGameDamageStats(rdram, ctx);
        goto after_9;
    // 0x8014D0C8: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    after_9:
    // 0x8014D0CC: jal         0x8014C958
    // 0x8014D0D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonYoshiEggMakeEffect(rdram, ctx);
        goto after_10;
    // 0x8014D0D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x8014D0D4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014D0D8: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8014D0DC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8014D0E0: jr          $ra
    // 0x8014D0E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8014D0E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void grSectorArwingWeaponLaser2DProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80107074: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80107078: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010707C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80107080: lw          $a0, 0x74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X74);
    // 0x80107084: lw          $a1, 0x104($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X104);
    // 0x80107088: jal         0x800FE068
    // 0x8010708C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerImpactShockMakeEffect(rdram, ctx);
        goto after_0;
    // 0x8010708C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_0:
    // 0x80107090: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80107094: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80107098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8010709C: jr          $ra
    // 0x801070A0: nop

    return;
    // 0x801070A0: nop

;}
RECOMP_FUNC void unref_8000046C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000046C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80000470: jr          $ra
    // 0x80000474: addiu       $v0, $v0, 0xE90
    ctx->r2 = ADD32(ctx->r2, 0XE90);
    return;
    // 0x80000474: addiu       $v0, $v0, 0xE90
    ctx->r2 = ADD32(ctx->r2, 0XE90);
;}
RECOMP_FUNC void ftBossOkutsubushiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015AAB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015AAB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015AAB8: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015AABC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015AAC0: nop

    // 0x8015AAC4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015AAC8: nop

    // 0x8015AACC: bc1fl       L_8015AAFC
    if (!c1cs) {
        // 0x8015AAD0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015AAFC;
    }
    goto skip_0;
    // 0x8015AAD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015AAD4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015AAD8: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8015AADC: sw          $t6, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r14;
    // 0x8015AAE0: jal         0x8010CF20
    // 0x8015AAE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gmCameraSetStatusDefault(rdram, ctx);
        goto after_0;
    // 0x8015AAE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015AAE8: jal         0x80159040
    // 0x8015AAEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftBossWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015AAEC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015AAF0: jal         0x80158620
    // 0x8015AAF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftBossCommonSetDisableFogColor(rdram, ctx);
        goto after_2;
    // 0x8015AAF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8015AAF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015AAFC:
    // 0x8015AAFC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015AB00: jr          $ra
    // 0x8015AB04: nop

    return;
    // 0x8015AB04: nop

;}
RECOMP_FUNC void gcCaptureCameraGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017B80: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80017B84: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80017B88: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80017B8C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80017B90: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80017B94: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80017B98: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80017B9C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80017BA0: lw          $t7, 0x34($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X34);
    // 0x80017BA4: lw          $t6, 0x30($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X30);
    // 0x80017BA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80017BAC: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x80017BB0: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
    // 0x80017BB4: lw          $t9, 0x44($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X44);
    // 0x80017BB8: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80017BBC: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80017BC0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80017BC4: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x80017BC8: bne         $t6, $zero, L_80017BD4
    if (ctx->r14 != 0) {
        // 0x80017BCC: sw          $t8, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r24;
            goto L_80017BD4;
    }
    // 0x80017BCC: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80017BD0: beq         $t7, $zero, L_80017CA4
    if (ctx->r15 == 0) {
        // 0x80017BD4: lui         $s4, 0x8004
        ctx->r20 = S32(0X8004 << 16);
            goto L_80017CA4;
    }
L_80017BD4:
    // 0x80017BD4: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80017BD8: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80017BDC: addiu       $s3, $s3, -0x4918
    ctx->r19 = ADD32(ctx->r19, -0X4918);
    // 0x80017BE0: addiu       $s4, $s4, 0x6A88
    ctx->r20 = ADD32(ctx->r20, 0X6A88);
    // 0x80017BE4: addiu       $s5, $zero, 0x14
    ctx->r21 = ADD32(0, 0X14);
L_80017BE8:
    // 0x80017BE8: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
L_80017BEC:
    // 0x80017BEC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80017BF0: andi        $t5, $t3, 0x1
    ctx->r13 = ctx->r11 & 0X1;
    // 0x80017BF4: beq         $t5, $zero, L_80017C54
    if (ctx->r13 == 0) {
        // 0x80017BF8: andi        $t9, $t7, 0x1
        ctx->r25 = ctx->r15 & 0X1;
            goto L_80017C54;
    }
    // 0x80017BF8: andi        $t9, $t7, 0x1
    ctx->r25 = ctx->r15 & 0X1;
    // 0x80017BFC: beq         $t9, $zero, L_80017C48
    if (ctx->r25 == 0) {
        // 0x80017C00: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80017C48;
    }
    // 0x80017C00: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017C04: multu       $s0, $s5
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80017C08: lbu         $t0, 0x3($s3)
    ctx->r8 = MEM_BU(ctx->r19, 0X3);
    // 0x80017C0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80017C10: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80017C14: mflo        $t1
    ctx->r9 = lo;
    // 0x80017C18: addu        $t2, $s4, $t1
    ctx->r10 = ADD32(ctx->r20, ctx->r9);
    // 0x80017C1C: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x80017C20: bne         $t0, $t3, L_80017C38
    if (ctx->r8 != ctx->r11) {
        // 0x80017C24: nop
    
            goto L_80017C38;
    }
    // 0x80017C24: nop

    // 0x80017C28: jal         0x80017AAC
    // 0x80017C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcAddLinkedDL(rdram, ctx);
        goto after_0;
    // 0x80017C2C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80017C30: b           L_80017C58
    // 0x80017C34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_80017C58;
    // 0x80017C34: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80017C38:
    // 0x80017C38: jal         0x80017978
    // 0x80017C3C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    gcCaptureDoubleBufferGObjs(rdram, ctx);
        goto after_1;
    // 0x80017C3C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_1:
    // 0x80017C40: b           L_80017C58
    // 0x80017C44: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
        goto L_80017C58;
    // 0x80017C44: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80017C48:
    // 0x80017C48: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80017C4C: jal         0x80017868
    // 0x80017C50: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    gcCaptureTaggedGObjs(rdram, ctx);
        goto after_2;
    // 0x80017C50: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    after_2:
L_80017C54:
    // 0x80017C54: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_80017C58:
    // 0x80017C58: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x80017C5C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80017C60: jal         0x800309B0
    // 0x80017C64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    __ull_rshift_recomp(rdram, ctx);
        goto after_3;
    // 0x80017C64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x80017C68: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x80017C6C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80017C70: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80017C74: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80017C78: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80017C7C: jal         0x800309B0
    // 0x80017C80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    __ull_rshift_recomp(rdram, ctx);
        goto after_4;
    // 0x80017C80: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80017C84: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x80017C88: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x80017C8C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80017C90: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x80017C94: bne         $t4, $zero, L_80017BE8
    if (ctx->r12 != 0) {
        // 0x80017C98: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80017BE8;
    }
    // 0x80017C98: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80017C9C: bnel        $t5, $zero, L_80017BEC
    if (ctx->r13 != 0) {
        // 0x80017CA0: lw          $t3, 0x3C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X3C);
            goto L_80017BEC;
    }
    goto skip_0;
    // 0x80017CA0: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    skip_0:
L_80017CA4:
    // 0x80017CA4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80017CA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80017CAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80017CB0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80017CB4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80017CB8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80017CBC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80017CC0: jr          $ra
    // 0x80017CC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80017CC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void itFushigibanaMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018470C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80184710: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80184714: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80184718: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8018471C: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80184720: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80184724: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80184728: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018472C: addiu       $a1, $a1, -0x4AD0
    ctx->r5 = ADD32(ctx->r5, -0X4AD0);
    // 0x80184730: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80184734: jal         0x8016E174
    // 0x80184738: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80184738: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8018473C: beq         $v0, $zero, L_8018480C
    if (ctx->r2 == 0) {
        // 0x80184740: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_8018480C;
    }
    // 0x80184740: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x80184744: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x80184748: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x8018474C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80184750: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80184754: lbu         $t8, 0x340($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X340);
    // 0x80184758: sh          $zero, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = 0;
    // 0x8018475C: sh          $zero, 0x35E($v1)
    MEM_H(0X35E, ctx->r3) = 0;
    // 0x80184760: andi        $t9, $t8, 0xFF0F
    ctx->r25 = ctx->r24 & 0XFF0F;
    // 0x80184764: sb          $t9, 0x340($v1)
    MEM_B(0X340, ctx->r3) = ctx->r25;
    // 0x80184768: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x8018476C: lbu         $t5, 0x2D3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X2D3);
    // 0x80184770: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80184774: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x80184778: sw          $t3, 0x350($v1)
    MEM_W(0X350, ctx->r3) = ctx->r11;
    // 0x8018477C: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80184780: sw          $t2, 0x354($v1)
    MEM_W(0X354, ctx->r3) = ctx->r10;
    // 0x80184784: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80184788: sb          $t6, 0x2D3($v1)
    MEM_B(0X2D3, ctx->r3) = ctx->r14;
    // 0x8018478C: sw          $t3, 0x358($v1)
    MEM_W(0X358, ctx->r3) = ctx->r11;
    // 0x80184790: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80184794: jal         0x80018994
    // 0x80184798: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x80184798: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_1:
    // 0x8018479C: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801847A0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x801847A4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801847A8: addiu       $t0, $t0, -0x14A0
    ctx->r8 = ADD32(ctx->r8, -0X14A0);
    // 0x801847AC: sh          $v0, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = ctx->r2;
    // 0x801847B0: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x801847B4: andi        $a2, $v0, 0xFFFF
    ctx->r6 = ctx->r2 & 0XFFFF;
    // 0x801847B8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x801847BC: beq         $a0, $a2, L_801847CC
    if (ctx->r4 == ctx->r6) {
        // 0x801847C0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801847CC;
    }
    // 0x801847C0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801847C4: and         $t7, $a1, $a0
    ctx->r15 = ctx->r5 & ctx->r4;
    // 0x801847C8: beq         $t7, $zero, L_801847E0
    if (ctx->r15 == 0) {
        // 0x801847CC: addiu       $t9, $a2, 0x1
        ctx->r25 = ADD32(ctx->r6, 0X1);
            goto L_801847E0;
    }
L_801847CC:
    // 0x801847CC: addiu       $t9, $a2, 0x1
    ctx->r25 = ADD32(ctx->r6, 0X1);
    // 0x801847D0: andi        $t1, $t9, 0x3
    ctx->r9 = ctx->r25 & 0X3;
    // 0x801847D4: sh          $t9, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = ctx->r25;
    // 0x801847D8: sh          $t1, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = ctx->r9;
    // 0x801847DC: andi        $a1, $t1, 0xFFFF
    ctx->r5 = ctx->r9 & 0XFFFF;
L_801847E0:
    // 0x801847E0: bne         $a1, $at, L_801847FC
    if (ctx->r5 != ctx->r1) {
        // 0x801847E4: addiu       $a0, $zero, 0x228
        ctx->r4 = ADD32(0, 0X228);
            goto L_801847FC;
    }
    // 0x801847E4: addiu       $a0, $zero, 0x228
    ctx->r4 = ADD32(0, 0X228);
    // 0x801847E8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x801847EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801847F0: lw          $t4, 0x80($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X80);
    // 0x801847F4: sh          $t2, 0x80($t4)
    MEM_H(0X80, ctx->r12) = ctx->r10;
    // 0x801847F8: lhu         $a1, 0x35C($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X35C);
L_801847FC:
    // 0x801847FC: sw          $a1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r5;
    // 0x80184800: jal         0x800269C0
    // 0x80184804: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80184804: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80184808: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
L_8018480C:
    // 0x8018480C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80184810: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80184814: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x80184818: jr          $ra
    // 0x8018481C: nop

    return;
    // 0x8018481C: nop

;}
RECOMP_FUNC void ifCommonPlayerArrowsAddAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801115BC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801115C0: lw          $t6, 0xD40($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XD40);
    // 0x801115C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801115C8: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x801115CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801115D0: addiu       $t7, $t7, 0x270
    ctx->r15 = ADD32(ctx->r15, 0X270);
    // 0x801115D4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801115D8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801115DC: jal         0x8000BD8C
    // 0x801115E0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddAnimJointAll(rdram, ctx);
        goto after_0;
    // 0x801115E0: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x801115E4: jal         0x8000DF34
    // 0x801115E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x801115E8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801115EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801115F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801115F4: jr          $ra
    // 0x801115F8: nop

    return;
    // 0x801115F8: nop

;}
RECOMP_FUNC void ftBossDrillProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A0C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A0C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A0C8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015A0CC: jal         0x800D9480
    // 0x8015A0D0: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A0D0: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    after_0:
    // 0x8015A0D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015A0D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A0DC: jr          $ra
    // 0x8015A0E0: nop

    return;
    // 0x8015A0E0: nop

;}
RECOMP_FUNC void grInishiePowerBlockCheckGetDamageKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109B8C: lw          $v0, 0x84($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X84);
    // 0x80109B90: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x80109B94: bnel        $t6, $zero, L_80109BCC
    if (ctx->r14 != 0) {
        // 0x80109B98: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80109BCC;
    }
    goto skip_0;
    // 0x80109B98: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80109B9C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80109BA0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80109BA4: lw          $t7, 0x2A8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2A8);
    // 0x80109BA8: beql        $a1, $t7, L_80109BCC
    if (ctx->r5 == ctx->r15) {
        // 0x80109BAC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80109BCC;
    }
    goto skip_1;
    // 0x80109BAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80109BB0: lw          $t8, 0x1430($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1430);
    // 0x80109BB4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80109BB8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80109BBC: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80109BC0: jr          $ra
    // 0x80109BC4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    return;
    // 0x80109BC4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80109BC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80109BCC:
    // 0x80109BCC: jr          $ra
    // 0x80109BD0: nop

    return;
    // 0x80109BD0: nop

;}
RECOMP_FUNC void ftCommonDamageGotoDamageStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80141560: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80141564: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80141568: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014156C: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x80141570: lbu         $t6, 0x190($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X190);
    // 0x80141574: andi        $t7, $t6, 0x1
    ctx->r15 = ctx->r14 & 0X1;
    // 0x80141578: beql        $t7, $zero, L_80141588
    if (ctx->r15 == 0) {
        // 0x8014157C: lw          $v1, 0x7F8($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X7F8);
            goto L_80141588;
    }
    goto skip_0;
    // 0x8014157C: lw          $v1, 0x7F8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7F8);
    skip_0:
    // 0x80141580: sw          $t8, 0x15C($v0)
    MEM_W(0X15C, ctx->r2) = ctx->r24;
    // 0x80141584: lw          $v1, 0x7F8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X7F8);
L_80141588:
    // 0x80141588: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8014158C: bnel        $v1, $at, L_801415A8
    if (ctx->r3 != ctx->r1) {
        // 0x80141590: lw          $t9, 0x7F4($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X7F4);
            goto L_801415A8;
    }
    goto skip_1;
    // 0x80141590: lw          $t9, 0x7F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X7F4);
    skip_1:
    // 0x80141594: jal         0x801499A4
    // 0x80141598: nop

    ftCommonFuraSleepSetStatus(rdram, ctx);
        goto after_0;
    // 0x80141598: nop

    after_0:
    // 0x8014159C: b           L_801415EC
    // 0x801415A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_801415EC;
    // 0x801415A0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x801415A4: lw          $t9, 0x7F4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X7F4);
L_801415A8:
    // 0x801415A8: lw          $a2, 0x7F0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X7F0);
    // 0x801415AC: lw          $a3, 0x7E0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X7E0);
    // 0x801415B0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801415B4: lw          $t0, 0x7FC($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X7FC);
    // 0x801415B8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801415BC: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x801415C0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x801415C4: lw          $t1, 0x800($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X800);
    // 0x801415C8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x801415CC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x801415D0: lw          $t2, 0x808($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X808);
    // 0x801415D4: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x801415D8: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    // 0x801415DC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801415E0: jal         0x80140EE4
    // 0x801415E4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    ftCommonDamageInitDamageVars(rdram, ctx);
        goto after_1;
    // 0x801415E4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    after_1:
    // 0x801415E8: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_801415EC:
    // 0x801415EC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x801415F0: jr          $ra
    // 0x801415F4: nop

    return;
    // 0x801415F4: nop

;}
RECOMP_FUNC void mnOptionMakeBackupClear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013209C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801320A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801320A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801320A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801320AC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x801320B0: jal         0x80009968
    // 0x801320B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x801320B4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801320B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801320BC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801320C0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801320C4: sw          $v0, 0x37A8($at)
    MEM_W(0X37A8, ctx->r1) = ctx->r2;
    // 0x801320C8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801320CC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801320D0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801320D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801320D8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801320DC: jal         0x80009DF4
    // 0x801320E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801320E0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801320E4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801320E8: lui         $a1, 0x428A
    ctx->r5 = S32(0X428A << 16);
    // 0x801320EC: lui         $a2, 0x4308
    ctx->r6 = S32(0X4308 << 16);
    // 0x801320F0: jal         0x80131BFC
    // 0x801320F4: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    mnOptionMakeOptionTabs(rdram, ctx);
        goto after_2;
    // 0x801320F4: addiu       $a3, $zero, 0x11
    ctx->r7 = ADD32(0, 0X11);
    after_2:
    // 0x801320F8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801320FC: lw          $a1, 0x37B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X37B8);
    // 0x80132100: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132104: xori        $a1, $a1, 0x2
    ctx->r5 = ctx->r5 ^ 0X2;
    // 0x80132108: jal         0x80131B24
    // 0x8013210C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mnOptionSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x8013210C: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x80132110: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132114: lw          $t7, 0x38B4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38B4);
    // 0x80132118: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x8013211C: addiu       $t8, $t8, -0x7880
    ctx->r24 = ADD32(ctx->r24, -0X7880);
    // 0x80132120: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132124: jal         0x800CCFDC
    // 0x80132128: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132128: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x8013212C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132130: lui         $at, 0x42AC
    ctx->r1 = S32(0X42AC << 16);
    // 0x80132134: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132138: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8013213C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132140: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132144: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132148: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013214C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132150: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132154: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132158: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013215C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132160: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132164: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132168: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013216C: jr          $ra
    // 0x80132170: nop

    return;
    // 0x80132170: nop

;}
RECOMP_FUNC void ftPhysicsStopVelAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9444: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800D9448: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800D944C: swc1        $f0, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->f0.u32l;
    // 0x800D9450: swc1        $f0, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->f0.u32l;
    // 0x800D9454: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x800D9458: swc1        $f0, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f0.u32l;
    // 0x800D945C: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x800D9460: swc1        $f0, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f0.u32l;
    // 0x800D9464: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x800D9468: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x800D946C: swc1        $f0, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f0.u32l;
    // 0x800D9470: jr          $ra
    // 0x800D9474: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
    return;
    // 0x800D9474: swc1        $f0, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f0.u32l;
;}
RECOMP_FUNC void scSubsysControllerGetPlayerTapButtons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8039076C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80390770: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80390774: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80390778: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8039077C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80390780: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80390784: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80390788: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8039078C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80390790: addiu       $s2, $s2, 0x5228
    ctx->r18 = ADD32(ctx->r18, 0X5228);
    // 0x80390794: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80390798: addiu       $s3, $zero, 0xA
    ctx->r19 = ADD32(0, 0XA);
    // 0x8039079C: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
L_803907A0:
    // 0x803907A0: jal         0x80390700
    // 0x803907A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    scSubsysControllerCheckConnected(rdram, ctx);
        goto after_0;
    // 0x803907A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x803907A8: beql        $v0, $zero, L_803907D8
    if (ctx->r2 == 0) {
        // 0x803907AC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_803907D8;
    }
    goto skip_0;
    // 0x803907AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x803907B0: multu       $s0, $s3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x803907B4: mflo        $t6
    ctx->r14 = lo;
    // 0x803907B8: addu        $t7, $s2, $t6
    ctx->r15 = ADD32(ctx->r18, ctx->r14);
    // 0x803907BC: lhu         $t8, 0x2($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X2);
    // 0x803907C0: and         $t9, $t8, $s1
    ctx->r25 = ctx->r24 & ctx->r17;
    // 0x803907C4: beql        $t9, $zero, L_803907D8
    if (ctx->r25 == 0) {
        // 0x803907C8: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_803907D8;
    }
    goto skip_1;
    // 0x803907C8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x803907CC: b           L_803907E4
    // 0x803907D0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
        goto L_803907E4;
    // 0x803907D0: addiu       $v0, $s0, 0x1
    ctx->r2 = ADD32(ctx->r16, 0X1);
    // 0x803907D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_803907D8:
    // 0x803907D8: bne         $s0, $s4, L_803907A0
    if (ctx->r16 != ctx->r20) {
        // 0x803907DC: nop
    
            goto L_803907A0;
    }
    // 0x803907DC: nop

    // 0x803907E0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_803907E4:
    // 0x803907E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x803907E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x803907EC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x803907F0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x803907F4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x803907F8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x803907FC: jr          $ra
    // 0x80390800: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80390800: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itNyarsAttackSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EFC4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017EFC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017EFCC: jal         0x8017EFA0
    // 0x8017EFD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itNyarsAttackInitVars(rdram, ctx);
        goto after_0;
    // 0x8017EFD0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017EFD4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017EFD8: addiu       $a1, $a1, -0x532C
    ctx->r5 = ADD32(ctx->r5, -0X532C);
    // 0x8017EFDC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8017EFE0: jal         0x80172EC8
    // 0x8017EFE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017EFE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x8017EFE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017EFEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017EFF0: jr          $ra
    // 0x8017EFF4: nop

    return;
    // 0x8017EFF4: nop

;}
RECOMP_FUNC void gmCollisionGetFighterPartsWorldPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EDF24: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800EDF28: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800EDF2C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800EDF30: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800EDF34: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800EDF38: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800EDF3C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800EDF40: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800EDF44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800EDF48: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800EDF4C: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x800EDF50: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800EDF54: lw          $v0, 0x190($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X190);
    // 0x800EDF58: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800EDF5C: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x800EDF60: bnel        $v0, $zero, L_800EDFD8
    if (ctx->r2 != 0) {
        // 0x800EDF64: lw          $s0, 0x84($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X84);
            goto L_800EDFD8;
    }
    goto skip_0;
    // 0x800EDF64: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
    skip_0:
    // 0x800EDF68: beq         $a0, $s2, L_800EDFF8
    if (ctx->r4 == ctx->r18) {
        // 0x800EDF6C: addiu       $s3, $zero, 0x1
        ctx->r19 = ADD32(0, 0X1);
            goto L_800EDFF8;
    }
    // 0x800EDF6C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x800EDF70: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
L_800EDF74:
    // 0x800EDF74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800EDF78: lbu         $t8, 0x5($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X5);
    // 0x800EDF7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800EDF80: beql        $t8, $zero, L_800EDFA0
    if (ctx->r24 == 0) {
        // 0x800EDF84: lw          $t9, 0x0($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X0);
            goto L_800EDFA0;
    }
    goto skip_1;
    // 0x800EDF84: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    skip_1:
    // 0x800EDF88: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    // 0x800EDF8C: jal         0x800ED3C0
    // 0x800EDF90: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_0;
    // 0x800EDF90: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x800EDF94: b           L_800EDFFC
    // 0x800EDF98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800EDFFC;
    // 0x800EDF98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800EDF9C: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
L_800EDFA0:
    // 0x800EDFA0: bnel        $t9, $zero, L_800EDFB8
    if (ctx->r25 != 0) {
        // 0x800EDFA4: addiu       $a0, $s0, 0x10
        ctx->r4 = ADD32(ctx->r16, 0X10);
            goto L_800EDFB8;
    }
    goto skip_2;
    // 0x800EDFA4: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
    skip_2:
    // 0x800EDFA8: jal         0x800ECDE4
    // 0x800EDFAC: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    gmCollisionTransformMatrixAll(rdram, ctx);
        goto after_1;
    // 0x800EDFAC: addiu       $a2, $s0, 0x10
    ctx->r6 = ADD32(ctx->r16, 0X10);
    after_1:
    // 0x800EDFB0: sw          $s3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r19;
    // 0x800EDFB4: addiu       $a0, $s0, 0x10
    ctx->r4 = ADD32(ctx->r16, 0X10);
L_800EDFB8:
    // 0x800EDFB8: jal         0x800ED3C0
    // 0x800EDFBC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_2;
    // 0x800EDFBC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_2:
    // 0x800EDFC0: lw          $s1, 0x14($s1)
    ctx->r17 = MEM_W(ctx->r17, 0X14);
    // 0x800EDFC4: bnel        $s1, $s2, L_800EDF74
    if (ctx->r17 != ctx->r18) {
        // 0x800EDFC8: lw          $s0, 0x84($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X84);
            goto L_800EDF74;
    }
    goto skip_3;
    // 0x800EDFC8: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
    skip_3:
    // 0x800EDFCC: b           L_800EDFFC
    // 0x800EDFD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_800EDFFC;
    // 0x800EDFD0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800EDFD4: lw          $s0, 0x84($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X84);
L_800EDFD8:
    // 0x800EDFD8: lbu         $t0, 0x5($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X5);
    // 0x800EDFDC: bnel        $t0, $zero, L_800EDFF0
    if (ctx->r8 != 0) {
        // 0x800EDFE0: addiu       $a0, $s0, 0x50
        ctx->r4 = ADD32(ctx->r16, 0X50);
            goto L_800EDFF0;
    }
    goto skip_4;
    // 0x800EDFE0: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
    skip_4:
    // 0x800EDFE4: jal         0x800EDBA4
    // 0x800EDFE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_ovl2_800EDBA4(rdram, ctx);
        goto after_3;
    // 0x800EDFE8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800EDFEC: addiu       $a0, $s0, 0x50
    ctx->r4 = ADD32(ctx->r16, 0X50);
L_800EDFF0:
    // 0x800EDFF0: jal         0x800ED3C0
    // 0x800EDFF4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_4;
    // 0x800EDFF4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_4:
L_800EDFF8:
    // 0x800EDFF8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800EDFFC:
    // 0x800EDFFC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800EE000: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800EE004: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800EE008: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800EE00C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800EE010: jr          $ra
    // 0x800EE014: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800EE014: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftParamUpdate1PGameDamageStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EAA2C: lhu         $t6, 0x810($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X810);
    // 0x800EAA30: sw          $a1, 0x80C($a0)
    MEM_W(0X80C, ctx->r4) = ctx->r5;
    // 0x800EAA34: sw          $a2, 0x820($a0)
    MEM_W(0X820, ctx->r4) = ctx->r6;
    // 0x800EAA38: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800EAA3C: sw          $a3, 0x824($a0)
    MEM_W(0X824, ctx->r4) = ctx->r7;
    // 0x800EAA40: sh          $t7, 0x810($a0)
    MEM_H(0X810, ctx->r4) = ctx->r15;
    // 0x800EAA44: lhu         $t8, 0x16($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X16);
    // 0x800EAA48: addiu       $t0, $sp, 0x12
    ctx->r8 = ADD32(ctx->r29, 0X12);
    // 0x800EAA4C: beql        $t8, $zero, L_800EAA64
    if (ctx->r24 == 0) {
        // 0x800EAA50: lhu         $t2, 0x0($t0)
        ctx->r10 = MEM_HU(ctx->r8, 0X0);
            goto L_800EAA64;
    }
    goto skip_0;
    // 0x800EAA50: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
    skip_0:
    // 0x800EAA54: lhu         $t9, 0x82A($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X82A);
    // 0x800EAA58: beq         $t8, $t9, L_800EAB38
    if (ctx->r24 == ctx->r25) {
        // 0x800EAA5C: nop
    
            goto L_800EAB38;
    }
    // 0x800EAA5C: nop

    // 0x800EAA60: lhu         $t2, 0x0($t0)
    ctx->r10 = MEM_HU(ctx->r8, 0X0);
L_800EAA64:
    // 0x800EAA64: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x800EAA68: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800EAA6C: sh          $t2, 0x828($a0)
    MEM_H(0X828, ctx->r4) = ctx->r10;
    // 0x800EAA70: lhu         $t3, 0x16($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X16);
    // 0x800EAA74: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800EAA78: sh          $t3, 0x82A($a0)
    MEM_H(0X82A, ctx->r4) = ctx->r11;
    // 0x800EAA7C: lw          $t4, 0x50E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50E8);
    // 0x800EAA80: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800EAA84: bne         $t5, $at, L_800EAB38
    if (ctx->r13 != ctx->r1) {
        // 0x800EAA88: nop
    
            goto L_800EAB38;
    }
    // 0x800EAA88: nop

    // 0x800EAA8C: lbu         $t6, 0x4AE3($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AE3);
    // 0x800EAA90: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800EAA94: andi        $v0, $v0, 0x3FF
    ctx->r2 = ctx->r2 & 0X3FF;
    // 0x800EAA98: bne         $a1, $t6, L_800EAB38
    if (ctx->r5 != ctx->r14) {
        // 0x800EAA9C: nop
    
            goto L_800EAB38;
    }
    // 0x800EAA9C: nop

    // 0x800EAAA0: beq         $v0, $zero, L_800EAB38
    if (ctx->r2 == 0) {
        // 0x800EAAA4: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_800EAB38;
    }
    // 0x800EAAA4: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800EAAA8: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x800EAAAC: addiu       $t8, $t8, 0x37B0
    ctx->r24 = ADD32(ctx->r24, 0X37B0);
    // 0x800EAAB0: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800EAAB4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800EAAB8: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x800EAABC: addiu       $t5, $t5, 0x3898
    ctx->r13 = ADD32(ctx->r13, 0X3898);
    // 0x800EAAC0: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800EAAC4: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x800EAAC8: lw          $t1, 0x828($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X828);
    // 0x800EAACC: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800EAAD0: srl         $t3, $t2, 31
    ctx->r11 = S32(U32(ctx->r10) >> 31);
    // 0x800EAAD4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800EAAD8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800EAADC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800EAAE0: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x800EAAE4: addiu       $t2, $t2, 0x38A0
    ctx->r10 = ADD32(ctx->r10, 0X38A0);
    // 0x800EAAE8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800EAAEC: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800EAAF0: lw          $t8, 0x828($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X828);
    // 0x800EAAF4: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800EAAF8: srl         $t0, $t9, 31
    ctx->r8 = S32(U32(ctx->r25) >> 31);
    // 0x800EAAFC: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x800EAB00: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    // 0x800EAB04: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800EAB08: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x800EAB0C: addiu       $t9, $t9, 0x38A8
    ctx->r25 = ADD32(ctx->r25, 0X38A8);
    // 0x800EAB10: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800EAB14: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800EAB18: lw          $t5, 0x828($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X828);
    // 0x800EAB1C: sll         $t6, $t5, 5
    ctx->r14 = S32(ctx->r13 << 5);
    // 0x800EAB20: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x800EAB24: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800EAB28: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x800EAB2C: lw          $t0, 0x0($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X0);
    // 0x800EAB30: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800EAB34: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
L_800EAB38:
    // 0x800EAB38: jr          $ra
    // 0x800EAB3C: nop

    return;
    // 0x800EAB3C: nop

;}
RECOMP_FUNC void itBombHeiHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801774FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177500: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177504: jal         0x80177218
    // 0x80177508: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itBombHeiCommonSetHitStatusNone(rdram, ctx);
        goto after_0;
    // 0x80177508: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8017750C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80177510: addiu       $a1, $a1, -0x6034
    ctx->r5 = ADD32(ctx->r5, -0X6034);
    // 0x80177514: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80177518: jal         0x80172EC8
    // 0x8017751C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8017751C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80177520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177528: jr          $ra
    // 0x8017752C: nop

    return;
    // 0x8017752C: nop

;}
RECOMP_FUNC void ifCommonSuddenDeathMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112B74: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80112B78: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80112B7C: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80112B80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80112B84: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80112B88: jal         0x80009968
    // 0x80112B8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80112B8C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80112B90: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80112B94: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80112B98: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80112B9C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80112BA0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80112BA4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80112BA8: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80112BAC: jal         0x80009DF4
    // 0x80112BB0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80112BB0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80112BB4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80112BB8: addiu       $a1, $a1, 0x2AD0
    ctx->r5 = ADD32(ctx->r5, 0X2AD0);
    // 0x80112BBC: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80112BC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80112BC4: jal         0x80008188
    // 0x80112BC8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80112BC8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_2:
    // 0x80112BCC: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80112BD0: addiu       $a2, $a2, -0x1284
    ctx->r6 = ADD32(ctx->r6, -0X1284);
    // 0x80112BD4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80112BD8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80112BDC: jal         0x80112024
    // 0x80112BE0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    ifCommonAnnounceSetAttr(rdram, ctx);
        goto after_3;
    // 0x80112BE0: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
    after_3:
    // 0x80112BE4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80112BE8: addiu       $a1, $a1, -0x1224
    ctx->r5 = ADD32(ctx->r5, -0X1224);
    // 0x80112BEC: jal         0x80112B24
    // 0x80112BF0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ifCommonAnnounceSetColors(rdram, ctx);
        goto after_4;
    // 0x80112BF0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80112BF4: jal         0x800269C0
    // 0x80112BF8: addiu       $a0, $zero, 0x202
    ctx->r4 = ADD32(0, 0X202);
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80112BF8: addiu       $a0, $zero, 0x202
    ctx->r4 = ADD32(0, 0X202);
    after_5:
    // 0x80112BFC: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80112C00: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80112C04: sb          $zero, 0x11($t7)
    MEM_B(0X11, ctx->r15) = 0;
    // 0x80112C08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80112C0C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80112C10: jr          $ra
    // 0x80112C14: nop

    return;
    // 0x80112C14: nop

;}
RECOMP_FUNC void ftCommonOttottoWaitSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142AC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80142AC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80142ACC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80142AD0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80142AD4: addiu       $a1, $zero, 0x23
    ctx->r5 = ADD32(0, 0X23);
    // 0x80142AD8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80142ADC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80142AE0: jal         0x800E6F24
    // 0x80142AE4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80142AE4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x80142AE8: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x80142AEC: lbu         $t7, 0x192($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X192);
    // 0x80142AF0: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x80142AF4: sb          $t8, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r24;
    // 0x80142AF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80142AFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80142B00: jr          $ra
    // 0x80142B04: nop

    return;
    // 0x80142B04: nop

;}
RECOMP_FUNC void func_ovl8_803806C0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803806C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803806C4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x803806C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x803806CC: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x803806D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803806D4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x803806D8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x803806DC: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x803806E0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x803806E4: lw          $a0, 0xB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XB4);
    // 0x803806E8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x803806EC: jal         0x8037FF40
    // 0x803806F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_8037FF40(rdram, ctx);
        goto after_0;
    // 0x803806F0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_0:
    // 0x803806F4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x803806F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x803806FC: jr          $ra
    // 0x80380700: nop

    return;
    // 0x80380700: nop

;}
RECOMP_FUNC void gcGetGObjProcessThreadStack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000784C: bne         $a0, $zero, L_8000785C
    if (ctx->r4 != 0) {
        // 0x80007850: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000785C;
    }
    // 0x80007850: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80007854: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80007858: lw          $a0, 0x6A60($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A60);
L_8000785C:
    // 0x8000785C: beq         $a0, $zero, L_8000787C
    if (ctx->r4 == 0) {
        // 0x80007860: nop
    
            goto L_8000787C;
    }
    // 0x80007860: nop

    // 0x80007864: lbu         $t6, 0x14($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X14);
    // 0x80007868: bne         $t6, $zero, L_8000787C
    if (ctx->r14 != 0) {
        // 0x8000786C: nop
    
            goto L_8000787C;
    }
    // 0x8000786C: nop

    // 0x80007870: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x80007874: jr          $ra
    // 0x80007878: lw          $v0, 0x1B8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1B8);
    return;
    // 0x80007878: lw          $v0, 0x1B8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X1B8);
L_8000787C:
    // 0x8000787C: jr          $ra
    // 0x80007880: nop

    return;
    // 0x80007880: nop

;}
RECOMP_FUNC void func_ovl8_803838E0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803838E0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803838E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803838E8: lh          $v0, 0x42($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X42);
    // 0x803838EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x803838F0: beql        $v0, $zero, L_803839C4
    if (ctx->r2 == 0) {
        // 0x803838F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_803839C4;
    }
    goto skip_0;
    // 0x803838F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x803838F8: lw          $v1, 0x30($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X30);
    // 0x803838FC: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x80383900: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80383904: lh          $t6, 0xF0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XF0);
    // 0x80383908: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8038390C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80383910: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x80383914: lw          $t9, 0xF4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0XF4);
    // 0x80383918: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x8038391C: jalr        $t9
    // 0x80383920: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80383920: nop

    after_0:
    // 0x80383924: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80383928: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x8038392C: beq         $v0, $zero, L_8038393C
    if (ctx->r2 == 0) {
        // 0x80383930: lw          $t1, 0x1C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X1C);
            goto L_8038393C;
    }
    // 0x80383930: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80383934: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80383938: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
L_8038393C:
    // 0x8038393C: lh          $a2, 0x44($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X44);
    // 0x80383940: lh          $v0, 0x42($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X42);
    // 0x80383944: subu        $t7, $a2, $v0
    ctx->r15 = SUB32(ctx->r6, ctx->r2);
    // 0x80383948: blez        $t7, L_80383978
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8038394C: sw          $t7, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r15;
            goto L_80383978;
    }
    // 0x8038394C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80383950: lw          $v1, 0x3C($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X3C);
    // 0x80383954: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80383958: sw          $a3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r7;
    // 0x8038395C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x80383960: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
    // 0x80383964: jal         0x8037B760
    // 0x80383968: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    func_ovl8_8037B760(rdram, ctx);
        goto after_1;
    // 0x80383968: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    after_1:
    // 0x8038396C: lw          $a3, 0x28($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X28);
    // 0x80383970: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80383974: lh          $a2, 0x44($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X44);
L_80383978:
    // 0x80383978: subu        $t2, $a2, $t1
    ctx->r10 = SUB32(ctx->r6, ctx->r9);
    // 0x8038397C: sh          $t2, 0x44($a3)
    MEM_H(0X44, ctx->r7) = ctx->r10;
    // 0x80383980: lh          $t4, 0x44($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X44);
    // 0x80383984: lw          $t3, 0x3C($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X3C);
    // 0x80383988: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8038398C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80383990: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x80383994: sb          $zero, 0x0($t5)
    MEM_B(0X0, ctx->r13) = 0;
    // 0x80383998: lh          $t6, 0x42($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X42);
    // 0x8038399C: lw          $v0, 0x38($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X38);
    // 0x803839A0: sw          $t7, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r15;
    // 0x803839A4: subu        $t9, $t6, $t1
    ctx->r25 = SUB32(ctx->r14, ctx->r9);
    // 0x803839A8: sh          $t9, 0x42($a3)
    MEM_H(0X42, ctx->r7) = ctx->r25;
    // 0x803839AC: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x803839B0: lw          $t9, 0x11C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X11C);
    // 0x803839B4: lh          $t8, 0x118($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X118);
    // 0x803839B8: jalr        $t9
    // 0x803839BC: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x803839BC: addu        $a0, $t8, $v0
    ctx->r4 = ADD32(ctx->r24, ctx->r2);
    after_2:
    // 0x803839C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_803839C4:
    // 0x803839C4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x803839C8: jr          $ra
    // 0x803839CC: nop

    return;
    // 0x803839CC: nop

;}
RECOMP_FUNC void ftCommonWaitProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E070: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013E074: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013E078: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013E07C: jal         0x80151098
    // 0x8013E080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8013E080: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8013E084: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E088: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_0;
    // 0x8013E088: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013E08C: jal         0x80151160
    // 0x8013E090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialHiCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8013E090: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8013E094: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E098: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_1;
    // 0x8013E098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8013E09C: jal         0x801511E0
    // 0x8013E0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSpecialLwCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x8013E0A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013E0A4: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E0A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_2;
    // 0x8013E0A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8013E0AC: jal         0x80149CE0
    // 0x8013E0B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptCommon(rdram, ctx);
        goto after_3;
    // 0x8013E0B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013E0B4: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E0B8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_3;
    // 0x8013E0B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8013E0BC: jal         0x80150470
    // 0x8013E0C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS4CheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x8013E0C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8013E0C4: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E0C8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_4;
    // 0x8013E0C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8013E0CC: jal         0x8015070C
    // 0x8013E0D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi4CheckInterruptCommon(rdram, ctx);
        goto after_5;
    // 0x8013E0D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8013E0D4: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E0D8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_5;
    // 0x8013E0D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8013E0DC: jal         0x80150884
    // 0x8013E0E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw4CheckInterruptCommon(rdram, ctx);
        goto after_6;
    // 0x8013E0E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8013E0E4: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E0E8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_6;
    // 0x8013E0E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_6:
    // 0x8013E0EC: jal         0x8014F8C0
    // 0x8013E0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackS3CheckInterruptCommon(rdram, ctx);
        goto after_7;
    // 0x8013E0F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8013E0F4: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E0F8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_7;
    // 0x8013E0F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x8013E0FC: jal         0x8014FB1C
    // 0x8013E100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackHi3CheckInterruptCommon(rdram, ctx);
        goto after_8;
    // 0x8013E100: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8013E104: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E108: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_8;
    // 0x8013E108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_8:
    // 0x8013E10C: jal         0x8014FD70
    // 0x8013E110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackLw3CheckInterruptCommon(rdram, ctx);
        goto after_9;
    // 0x8013E110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8013E114: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E118: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_9;
    // 0x8013E118: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x8013E11C: jal         0x8014EC78
    // 0x8013E120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttack1CheckInterruptCommon(rdram, ctx);
        goto after_10;
    // 0x8013E120: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x8013E124: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E128: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_10;
    // 0x8013E128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x8013E12C: jal         0x80148D0C
    // 0x8013E130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardOnCheckInterruptCommon(rdram, ctx);
        goto after_11;
    // 0x8013E130: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x8013E134: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E138: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_11;
    // 0x8013E138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_11:
    // 0x8013E13C: jal         0x8014E764
    // 0x8013E140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_12;
    // 0x8013E140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x8013E144: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E148: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_12;
    // 0x8013E148: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_12:
    // 0x8013E14C: jal         0x8013F4D0
    // 0x8013E150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonKneeBendCheckInterruptCommon(rdram, ctx);
        goto after_13;
    // 0x8013E150: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x8013E154: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E158: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_13;
    // 0x8013E158: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_13:
    // 0x8013E15C: jal         0x8013ED64
    // 0x8013E160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDashCheckInterruptCommon(rdram, ctx);
        goto after_14;
    // 0x8013E160: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8013E164: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E168: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_14;
    // 0x8013E168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_14:
    // 0x8013E16C: jal         0x80141EA4
    // 0x8013E170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonPassCheckInterruptCommon(rdram, ctx);
        goto after_15;
    // 0x8013E170: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x8013E174: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E178: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_15;
    // 0x8013E178: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_15:
    // 0x8013E17C: jal         0x80142258
    // 0x8013E180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDokanStartCheckInterruptCommon(rdram, ctx);
        goto after_16;
    // 0x8013E180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_16:
    // 0x8013E184: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E188: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_16;
    // 0x8013E188: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_16:
    // 0x8013E18C: jal         0x8014310C
    // 0x8013E190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonSquatCheckInterruptCommon(rdram, ctx);
        goto after_17;
    // 0x8013E190: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_17:
    // 0x8013E194: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E198: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_17;
    // 0x8013E198: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_17:
    // 0x8013E19C: jal         0x8013EA04
    // 0x8013E1A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonTurnCheckInterruptCommon(rdram, ctx);
        goto after_18;
    // 0x8013E1A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_18:
    // 0x8013E1A4: bnel        $v0, $zero, L_8013E1B8
    if (ctx->r2 != 0) {
        // 0x8013E1A8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013E1B8;
    }
    goto skip_18;
    // 0x8013E1A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_18:
    // 0x8013E1AC: jal         0x8013E648
    // 0x8013E1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonWalkCheckInterruptCommon(rdram, ctx);
        goto after_19;
    // 0x8013E1B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_19:
    // 0x8013E1B4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013E1B8:
    // 0x8013E1B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013E1BC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013E1C0: jr          $ra
    // 0x8013E1C4: nop

    return;
    // 0x8013E1C4: nop

;}
RECOMP_FUNC void mvOpeningPortraitsBlockRow1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E30: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80131E34: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x80131E38: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131E3C: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80131E40: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131E44: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131E48: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131E4C: ori         $t8, $t8, 0x8104
    ctx->r24 = ctx->r24 | 0X8104;
    // 0x80131E50: ori         $t7, $t7, 0x81E0
    ctx->r15 = ctx->r15 | 0X81E0;
    // 0x80131E54: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131E58: jr          $ra
    // 0x80131E5C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    return;
    // 0x80131E5C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void ftMarioSpecialHiProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156240: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80156244: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80156248: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015624C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80156250: lw          $t6, 0xB18($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XB18);
    // 0x80156254: lw          $v0, 0x9C8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X9C8);
    // 0x80156258: bnel        $t6, $zero, L_80156294
    if (ctx->r14 != 0) {
        // 0x8015625C: lw          $t8, 0x180($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X180);
            goto L_80156294;
    }
    goto skip_0;
    // 0x8015625C: lw          $t8, 0x180($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X180);
    skip_0:
    // 0x80156260: lw          $t7, 0x14C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X14C);
    // 0x80156264: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80156268: bne         $t7, $at, L_80156280
    if (ctx->r15 != ctx->r1) {
        // 0x8015626C: nop
    
            goto L_80156280;
    }
    // 0x8015626C: nop

    // 0x80156270: jal         0x800D93E4
    // 0x80156274: nop

    ftPhysicsApplyAirVelTransNAll(rdram, ctx);
        goto after_0;
    // 0x80156274: nop

    after_0:
    // 0x80156278: b           L_80156310
    // 0x8015627C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80156310;
    // 0x8015627C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80156280:
    // 0x80156280: jal         0x800D8C14
    // 0x80156284: nop

    ftPhysicsApplyGroundVelTransN(rdram, ctx);
        goto after_1;
    // 0x80156284: nop

    after_1:
    // 0x80156288: b           L_80156310
    // 0x8015628C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80156310;
    // 0x8015628C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80156290: lw          $t8, 0x180($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X180);
L_80156294:
    // 0x80156294: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    // 0x80156298: beql        $t8, $zero, L_801562E4
    if (ctx->r24 == 0) {
        // 0x8015629C: lw          $a2, 0x5C($v0)
        ctx->r6 = MEM_W(ctx->r2, 0X5C);
            goto L_801562E4;
    }
    goto skip_1;
    // 0x8015629C: lw          $a2, 0x5C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X5C);
    skip_1:
    // 0x801562A0: jal         0x800D93E4
    // 0x801562A4: nop

    ftPhysicsApplyAirVelTransNAll(rdram, ctx);
        goto after_2;
    // 0x801562A4: nop

    after_2:
    // 0x801562A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801562AC: lwc1        $f0, -0x3970($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3970);
    // 0x801562B0: lwc1        $f4, 0x48($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801562B4: lwc1        $f8, 0x4C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x801562B8: lwc1        $f16, 0x50($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X50);
    // 0x801562BC: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x801562C0: nop

    // 0x801562C4: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x801562C8: nop

    // 0x801562CC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x801562D0: swc1        $f6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f6.u32l;
    // 0x801562D4: swc1        $f10, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f10.u32l;
    // 0x801562D8: b           L_8015630C
    // 0x801562DC: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
        goto L_8015630C;
    // 0x801562DC: swc1        $f18, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f18.u32l;
    // 0x801562E0: lw          $a2, 0x5C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X5C);
L_801562E4:
    // 0x801562E4: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801562E8: jal         0x800D8D68
    // 0x801562EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsApplyGravityClampTVel(rdram, ctx);
        goto after_3;
    // 0x801562EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801562F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801562F4: jal         0x800D8FA8
    // 0x801562F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_4;
    // 0x801562F8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_4:
    // 0x801562FC: bne         $v0, $zero, L_8015630C
    if (ctx->r2 != 0) {
        // 0x80156300: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8015630C;
    }
    // 0x80156300: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80156304: jal         0x800D9074
    // 0x80156308: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_5;
    // 0x80156308: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_5:
L_8015630C:
    // 0x8015630C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80156310:
    // 0x80156310: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80156314: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80156318: jr          $ra
    // 0x8015631C: nop

    return;
    // 0x8015631C: nop

;}
RECOMP_FUNC void ftNessSpecialHiEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154438: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015443C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80154440: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80154444: jal         0x800DDE84
    // 0x80154448: addiu       $a1, $a1, 0x44C0
    ctx->r5 = ADD32(ctx->r5, 0X44C0);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80154448: addiu       $a1, $a1, 0x44C0
    ctx->r5 = ADD32(ctx->r5, 0X44C0);
    after_0:
    // 0x8015444C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80154450: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80154454: jr          $ra
    // 0x80154458: nop

    return;
    // 0x80154458: nop

;}
RECOMP_FUNC void syVectorInv3D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800190E4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800190E8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800190EC: nop

    // 0x800190F0: c.eq.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl == ctx->f4.fl;
    // 0x800190F4: nop

    // 0x800190F8: bc1t        L_80019124
    if (c1cs) {
        // 0x800190FC: nop
    
            goto L_80019124;
    }
    // 0x800190FC: nop

    // 0x80019100: lwc1        $f6, 0x0($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80019104: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x80019108: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8001910C: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x80019110: div.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80019114: swc1        $f8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f8.u32l;
    // 0x80019118: div.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f12.fl);
    // 0x8001911C: swc1        $f16, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f16.u32l;
    // 0x80019120: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
L_80019124:
    // 0x80019124: jr          $ra
    // 0x80019128: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80019128: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void ftCommonAttackHi4CheckInputSuccess(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80150628: lb          $t6, 0x1C3($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1C3);
    // 0x8015062C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80150630: slti        $at, $t6, 0x35
    ctx->r1 = SIGNED(ctx->r14) < 0X35 ? 1 : 0;
    // 0x80150634: bne         $at, $zero, L_80150658
    if (ctx->r1 != 0) {
        // 0x80150638: nop
    
            goto L_80150658;
    }
    // 0x80150638: nop

    // 0x8015063C: lhu         $t7, 0x1BE($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1BE);
    // 0x80150640: lhu         $t8, 0x1B4($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X1B4);
    // 0x80150644: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80150648: beq         $t9, $zero, L_80150658
    if (ctx->r25 == 0) {
        // 0x8015064C: nop
    
            goto L_80150658;
    }
    // 0x8015064C: nop

    // 0x80150650: jr          $ra
    // 0x80150654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80150654: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80150658:
    // 0x80150658: jr          $ra
    // 0x8015065C: nop

    return;
    // 0x8015065C: nop

;}
RECOMP_FUNC void lbBackupCreateChecksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4520: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D4524: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800D4528: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D452C: addiu       $a2, $zero, 0x5E8
    ctx->r6 = ADD32(0, 0X5E8);
    // 0x800D4530: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
L_800D4534:
    // 0x800D4534: addiu       $t7, $a1, 0x1
    ctx->r15 = ADD32(ctx->r5, 0X1);
    // 0x800D4538: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x800D453C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D4540: addiu       $t0, $a1, 0x2
    ctx->r8 = ADD32(ctx->r5, 0X2);
    // 0x800D4544: lbu         $t2, 0x2($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X2);
    // 0x800D4548: addiu       $t3, $a1, 0x3
    ctx->r11 = ADD32(ctx->r5, 0X3);
    // 0x800D454C: lbu         $t5, 0x3($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X3);
    // 0x800D4550: addiu       $a0, $a1, 0x4
    ctx->r4 = ADD32(ctx->r5, 0X4);
    // 0x800D4554: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800D4558: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D455C: mflo        $t8
    ctx->r24 = lo;
    // 0x800D4560: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x800D4564: nop

    // 0x800D4568: multu       $t9, $t0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D456C: mflo        $t1
    ctx->r9 = lo;
    // 0x800D4570: addu        $v1, $v1, $t1
    ctx->r3 = ADD32(ctx->r3, ctx->r9);
    // 0x800D4574: nop

    // 0x800D4578: multu       $t2, $t3
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D457C: mflo        $t4
    ctx->r12 = lo;
    // 0x800D4580: addu        $v1, $v1, $t4
    ctx->r3 = ADD32(ctx->r3, ctx->r12);
    // 0x800D4584: nop

    // 0x800D4588: multu       $t5, $a0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D458C: mflo        $t6
    ctx->r14 = lo;
    // 0x800D4590: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x800D4594: bnel        $a0, $a2, L_800D4534
    if (ctx->r4 != ctx->r6) {
        // 0x800D4598: lbu         $t6, 0x0($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X0);
            goto L_800D4534;
    }
    goto skip_0;
    // 0x800D4598: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    skip_0:
    // 0x800D459C: jr          $ra
    // 0x800D45A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800D45A0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void ftBossOkupunch2ProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A890: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A898: jal         0x800D938C
    // 0x8015A89C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPhysicsSetAirVelTransN(rdram, ctx);
        goto after_0;
    // 0x8015A89C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015A8A0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8015A8A4: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8015A8A8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8015A8AC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015A8B0: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8015A8B4: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8015A8B8: lw          $t6, 0xADC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XADC);
    // 0x8015A8BC: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8015A8C0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8015A8C4: lw          $t8, 0x74($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X74);
    // 0x8015A8C8: lwc1        $f4, 0x1C($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X1C);
    // 0x8015A8CC: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8015A8D0: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x8015A8D4: nop

    // 0x8015A8D8: bc1fl       L_8015A8EC
    if (!c1cs) {
        // 0x8015A8DC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8015A8EC;
    }
    goto skip_0;
    // 0x8015A8DC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x8015A8E0: b           L_8015A8EC
    // 0x8015A8E4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8015A8EC;
    // 0x8015A8E4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x8015A8E8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8015A8EC:
    // 0x8015A8EC: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x8015A8F0: nop

    // 0x8015A8F4: bc1fl       L_8015A930
    if (!c1cs) {
        // 0x8015A8F8: lwc1        $f16, 0x48($v0)
        ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
            goto L_8015A930;
    }
    goto skip_1;
    // 0x8015A8F8: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
    skip_1:
    // 0x8015A8FC: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8015A900: lui         $at, 0xC220
    ctx->r1 = S32(0XC220 << 16);
    // 0x8015A904: bc1fl       L_8015A918
    if (!c1cs) {
        // 0x8015A908: mtc1        $at, $f0
        ctx->f0.u32l = ctx->r1;
            goto L_8015A918;
    }
    goto skip_2;
    // 0x8015A908: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    skip_2:
    // 0x8015A90C: b           L_8015A91C
    // 0x8015A910: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
        goto L_8015A91C;
    // 0x8015A910: mov.s       $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    ctx->f0.fl = ctx->f14.fl;
    // 0x8015A914: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
L_8015A918:
    // 0x8015A918: nop

L_8015A91C:
    // 0x8015A91C: lwc1        $f8, 0x48($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48);
    // 0x8015A920: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8015A924: b           L_8015A938
    // 0x8015A928: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
        goto L_8015A938;
    // 0x8015A928: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x8015A92C: lwc1        $f16, 0x48($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X48);
L_8015A930:
    // 0x8015A930: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x8015A934: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
L_8015A938:
    // 0x8015A938: jal         0x80158528
    // 0x8015A93C: nop

    ftBossCommonUpdateFogColor(rdram, ctx);
        goto after_1;
    // 0x8015A93C: nop

    after_1:
    // 0x8015A940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015A944: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A948: jr          $ra
    // 0x8015A94C: nop

    return;
    // 0x8015A94C: nop

;}
RECOMP_FUNC void gcAddGObjScript(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AD38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000AD3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AD40: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8000AD44: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8000AD48: jal         0x8000ACD0
    // 0x8000AD4C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    gcSetupGObjScript(rdram, ctx);
        goto after_0;
    // 0x8000AD4C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    after_0:
    // 0x8000AD50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000AD54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000AD58: jr          $ra
    // 0x8000AD5C: nop

    return;
    // 0x8000AD5C: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateDamageDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E014: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x8018E018: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018E01C: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018E020: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018E024: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018E028: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018E02C: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018E030: addiu       $t0, $t0, 0xB58
    ctx->r8 = ADD32(ctx->r8, 0XB58);
    // 0x8018E034: addiu       $t1, $t1, 0x7E2
    ctx->r9 = ADD32(ctx->r9, 0X7E2);
    // 0x8018E038: addiu       $a3, $a3, 0x7DC
    ctx->r7 = ADD32(ctx->r7, 0X7DC);
    // 0x8018E03C: addiu       $a2, $a2, 0x7E4
    ctx->r6 = ADD32(ctx->r6, 0X7E4);
    // 0x8018E040: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8018E044:
    // 0x8018E044: lbu         $a0, 0x0($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X0);
    // 0x8018E048: lw          $t7, 0x28($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X28);
    // 0x8018E04C: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x8018E050: div         $zero, $a1, $a0
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r4)));
    // 0x8018E054: mflo        $v1
    ctx->r3 = lo;
    // 0x8018E058: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8018E05C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8018E060: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018E064: lw          $t2, 0x0($t9)
    ctx->r10 = MEM_W(ctx->r25, 0X0);
    // 0x8018E068: bne         $a0, $zero, L_8018E074
    if (ctx->r4 != 0) {
        // 0x8018E06C: nop
    
            goto L_8018E074;
    }
    // 0x8018E06C: nop

    // 0x8018E070: break       7
    do_break(2149113968);
L_8018E074:
    // 0x8018E074: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018E078: bne         $a0, $at, L_8018E08C
    if (ctx->r4 != ctx->r1) {
        // 0x8018E07C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8018E08C;
    }
    // 0x8018E07C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8018E080: bne         $a1, $at, L_8018E08C
    if (ctx->r5 != ctx->r1) {
        // 0x8018E084: nop
    
            goto L_8018E08C;
    }
    // 0x8018E084: nop

    // 0x8018E088: break       6
    do_break(2149113992);
L_8018E08C:
    // 0x8018E08C: mflo        $t6
    ctx->r14 = lo;
    // 0x8018E090: subu        $a1, $a1, $t6
    ctx->r5 = SUB32(ctx->r5, ctx->r14);
    // 0x8018E094: addiu       $t6, $t2, 0x3C
    ctx->r14 = ADD32(ctx->r10, 0X3C);
L_8018E098:
    // 0x8018E098: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8018E09C: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8018E0A0: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x8018E0A4: sw          $t4, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r12;
    // 0x8018E0A8: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x8018E0AC: sw          $t3, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r11;
    // 0x8018E0B0: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x8018E0B4: bne         $t2, $t6, L_8018E098
    if (ctx->r10 != ctx->r14) {
        // 0x8018E0B8: sw          $t4, 0xC($t5)
        MEM_W(0XC, ctx->r13) = ctx->r12;
            goto L_8018E098;
    }
    // 0x8018E0B8: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x8018E0BC: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8018E0C0: sw          $t4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r12;
    // 0x8018E0C4: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x8018E0C8: sw          $t3, 0x14($t5)
    MEM_W(0X14, ctx->r13) = ctx->r11;
    // 0x8018E0CC: lhu         $t7, 0x0($a3)
    ctx->r15 = MEM_HU(ctx->r7, 0X0);
    // 0x8018E0D0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8018E0D4: bgez        $t7, L_8018E0EC
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8018E0D8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8018E0EC;
    }
    // 0x8018E0D8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018E0DC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8018E0E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8018E0E4: nop

    // 0x8018E0E8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8018E0EC:
    // 0x8018E0EC: lh          $t8, 0x14($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X14);
    // 0x8018E0F0: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8018E0F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8018E0F8: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8018E0FC: nop

    // 0x8018E100: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018E104: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8018E108: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x8018E10C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8018E110: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x8018E114: nop

    // 0x8018E118: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8018E11C: nop

    // 0x8018E120: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8018E124: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x8018E128: bne         $a3, $t1, L_8018E044
    if (ctx->r7 != ctx->r9) {
        // 0x8018E12C: lw          $v0, 0x8($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X8);
            goto L_8018E044;
    }
    // 0x8018E12C: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x8018E130: jr          $ra
    // 0x8018E134: nop

    return;
    // 0x8018E134: nop

;}

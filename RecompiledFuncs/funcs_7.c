#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftComputerProcEvade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137C7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80137C80: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137C84: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80137C88: jal         0x80136D0C
    // 0x80137C8C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    ftComputerGetObjectiveStatus(rdram, ctx);
        goto after_0;
    // 0x80137C8C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80137C90: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80137C94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137C98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80137C9C: lbu         $t7, 0x216($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X216);
    // 0x80137CA0: addiu       $v1, $v1, 0x1CC
    ctx->r3 = ADD32(ctx->r3, 0X1CC);
    // 0x80137CA4: andi        $t8, $t7, 0xFFBF
    ctx->r24 = ctx->r15 & 0XFFBF;
    // 0x80137CA8: beq         $v0, $zero, L_80137CB8
    if (ctx->r2 == 0) {
        // 0x80137CAC: sb          $t8, 0x4A($v1)
        MEM_B(0X4A, ctx->r3) = ctx->r24;
            goto L_80137CB8;
    }
    // 0x80137CAC: sb          $t8, 0x4A($v1)
    MEM_B(0X4A, ctx->r3) = ctx->r24;
    // 0x80137CB0: bne         $v0, $at, L_80137CC0
    if (ctx->r2 != ctx->r1) {
        // 0x80137CB4: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_80137CC0;
    }
    // 0x80137CB4: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
L_80137CB8:
    // 0x80137CB8: b           L_80137CC8
    // 0x80137CBC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80137CC8;
    // 0x80137CBC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80137CC0:
    // 0x80137CC0: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x80137CC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80137CC8:
    // 0x80137CC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137CCC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80137CD0: jr          $ra
    // 0x80137CD4: nop

    return;
    // 0x80137CD4: nop

;}
RECOMP_FUNC void itKamexCommonProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180B6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80180B70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180B74: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80180B78: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    // 0x80180B7C: jal         0x801737B8
    // 0x80180B80: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80180B80: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80180B84: beq         $v0, $zero, L_80180B98
    if (ctx->r2 == 0) {
        // 0x80180B88: lw          $t7, 0x1C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1C);
            goto L_80180B98;
    }
    // 0x80180B88: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80180B8C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80180B90: nop

    // 0x80180B94: swc1        $f4, 0x30($t7)
    MEM_W(0X30, ctx->r15) = ctx->f4.u32l;
L_80180B98:
    // 0x80180B98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180B9C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80180BA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80180BA4: jr          $ra
    // 0x80180BA8: nop

    return;
    // 0x80180BA8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakePuckCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135E48: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135E4C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135E50: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80135E54: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80135E58: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80135E5C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80135E60: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x80135E64: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80135E68: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80135E6C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135E70: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80135E74: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80135E78: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80135E7C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135E80: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135E84: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80135E88: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80135E8C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80135E90: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80135E94: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80135E98: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80135E9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80135EA0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80135EA4: jal         0x8000B93C
    // 0x80135EA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80135EA8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80135EAC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80135EB0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80135EB4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80135EB8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80135EBC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80135EC0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80135EC4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80135EC8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80135ECC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80135ED0: jal         0x80007080
    // 0x80135ED4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80135ED4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80135ED8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80135EDC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80135EE0: jr          $ra
    // 0x80135EE4: nop

    return;
    // 0x80135EE4: nop

;}
RECOMP_FUNC void sc1PBonusStageBonus2ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA2C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018DA30: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8018DA34: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8018DA38: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x8018DA3C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018DA40: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8018DA44: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8018DA48: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8018DA4C: beq         $s0, $zero, L_8018DAC4
    if (ctx->r16 == 0) {
        // 0x8018DA50: sw          $a0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r4;
            goto L_8018DAC4;
    }
    // 0x8018DA50: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8018DA54: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x8018DA58: lui         $s2, 0xFFFF
    ctx->r18 = S32(0XFFFF << 16);
    // 0x8018DA5C: ori         $s2, $s2, 0xFF
    ctx->r18 = ctx->r18 | 0XFF;
    // 0x8018DA60: addiu       $s3, $s3, 0x1304
    ctx->r19 = ADD32(ctx->r19, 0X1304);
    // 0x8018DA64: addiu       $s1, $zero, 0xE
    ctx->r17 = ADD32(0, 0XE);
    // 0x8018DA68: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
L_8018DA6C:
    // 0x8018DA6C: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x8018DA70: bnel        $t6, $zero, L_8018DABC
    if (ctx->r14 != 0) {
        // 0x8018DA74: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_8018DABC;
    }
    goto skip_0;
    // 0x8018DA74: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x8018DA78: lw          $t7, 0xF4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XF4);
    // 0x8018DA7C: and         $t8, $t7, $s2
    ctx->r24 = ctx->r15 & ctx->r18;
    // 0x8018DA80: bnel        $s1, $t8, L_8018DABC
    if (ctx->r17 != ctx->r24) {
        // 0x8018DA84: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_8018DABC;
    }
    goto skip_1;
    // 0x8018DA84: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x8018DA88: jal         0x800FC72C
    // 0x8018DA8C: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
    mpCollisionSetDObjNoID(rdram, ctx);
        goto after_0;
    // 0x8018DA8C: lw          $a0, 0xEC($v0)
    ctx->r4 = MEM_W(ctx->r2, 0XEC);
    after_0:
    // 0x8018DA90: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8018DA94: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8018DA98: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x8018DA9C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8018DAA0: lw          $t2, 0x10($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X10);
    // 0x8018DAA4: lw          $t3, 0x84($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X84);
    // 0x8018DAA8: beql        $t3, $zero, L_8018DABC
    if (ctx->r11 == 0) {
        // 0x8018DAAC: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_8018DABC;
    }
    goto skip_2;
    // 0x8018DAAC: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_2:
    // 0x8018DAB0: jal         0x8018D8DC
    // 0x8018DAB4: nop

    sc1PBonusStageUpdatePlatformCount(rdram, ctx);
        goto after_1;
    // 0x8018DAB4: nop

    after_1:
    // 0x8018DAB8: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_8018DABC:
    // 0x8018DABC: bnel        $s0, $zero, L_8018DA6C
    if (ctx->r16 != 0) {
        // 0x8018DAC0: lw          $v0, 0x84($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X84);
            goto L_8018DA6C;
    }
    goto skip_3;
    // 0x8018DAC0: lw          $v0, 0x84($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84);
    skip_3:
L_8018DAC4:
    // 0x8018DAC4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018DAC8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8018DACC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8018DAD0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DAD4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8018DAD8: jr          $ra
    // 0x8018DADC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018DADC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_80000970(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000970: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80000974: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000978: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8000097C: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x80000980: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80000984: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x80000988: jal         0x80034480
    // 0x8000098C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x8000098C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80000990: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80000994: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000998: addiu       $t7, $sp, 0x1C
    ctx->r15 = ADD32(ctx->r29, 0X1C);
    // 0x8000099C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800009A0: addiu       $a0, $a0, 0x4FF8
    ctx->r4 = ADD32(ctx->r4, 0X4FF8);
    // 0x800009A4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800009A8: sw          $zero, 0x14($a1)
    MEM_W(0X14, ctx->r5) = 0;
    // 0x800009AC: sw          $t6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r14;
    // 0x800009B0: jal         0x80030000
    // 0x800009B4: sw          $t7, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r15;
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800009B4: sw          $t7, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r15;
    after_1:
    // 0x800009B8: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x800009BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800009C0: jal         0x80030210
    // 0x800009C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800009C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800009C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800009CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800009D0: jr          $ra
    // 0x800009D4: nop

    return;
    // 0x800009D4: nop

;}
RECOMP_FUNC void mvOpeningPikachuMakeName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D194: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8018D198: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D19C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8018D1A0: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8018D1A4: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8018D1A8: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8018D1AC: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8018D1B0: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8018D1B4: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x8018D1B8: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8018D1BC: addiu       $t7, $t7, -0x1EFC
    ctx->r15 = ADD32(ctx->r15, -0X1EFC);
    // 0x8018D1C0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8018D1C4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8018D1C8: addiu       $t6, $sp, 0x78
    ctx->r14 = ADD32(ctx->r29, 0X78);
    // 0x8018D1CC: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x8018D1D0: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8018D1D4: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8018D1D8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x8018D1DC: lui         $t1, 0x8019
    ctx->r9 = S32(0X8019 << 16);
    // 0x8018D1E0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8018D1E4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x8018D1E8: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x8018D1EC: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x8018D1F0: addiu       $t1, $t1, -0x1EDC
    ctx->r9 = ADD32(ctx->r9, -0X1EDC);
    // 0x8018D1F4: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x8018D1F8: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    // 0x8018D1FC: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x8018D200: lw          $t9, 0x18($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X18);
    // 0x8018D204: addiu       $t0, $sp, 0x5C
    ctx->r8 = ADD32(ctx->r29, 0X5C);
    // 0x8018D208: sw          $t8, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->r24;
    // 0x8018D20C: sw          $t9, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->r25;
    // 0x8018D210: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018D214: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018D218: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018D21C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8018D220: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x8018D224: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x8018D228: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8018D22C: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8018D230: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x8018D234: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x8018D238: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x8018D23C: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x8018D240: lw          $t3, 0x18($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X18);
    // 0x8018D244: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018D248: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D24C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D250: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x8018D254: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x8018D258: jal         0x80009968
    // 0x8018D25C: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D25C: sw          $t3, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r11;
    after_0:
    // 0x8018D260: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D264: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8018D268: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8018D26C: sw          $v0, -0x1DD4($at)
    MEM_W(-0X1DD4, ctx->r1) = ctx->r2;
    // 0x8018D270: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018D274: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8018D278: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8018D27C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D280: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8018D284: jal         0x80009DF4
    // 0x8018D288: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D288: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x8018D28C: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x8018D290: addiu       $s0, $sp, 0x78
    ctx->r16 = ADD32(ctx->r29, 0X78);
    // 0x8018D294: addiu       $s1, $sp, 0x5C
    ctx->r17 = ADD32(ctx->r29, 0X5C);
    // 0x8018D298: beq         $t5, $zero, L_8018D30C
    if (ctx->r13 == 0) {
        // 0x8018D29C: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8018D30C;
    }
    // 0x8018D29C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x8018D2A0: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018D2A4: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8018D2A8: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8018D2AC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8018D2B0: addiu       $s2, $s2, -0x1BC0
    ctx->r18 = ADD32(ctx->r18, -0X1BC0);
    // 0x8018D2B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8018D2B8: addiu       $s3, $zero, -0x21
    ctx->r19 = ADD32(0, -0X21);
    // 0x8018D2BC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
L_8018D2C0:
    // 0x8018D2C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8018D2C4: jal         0x800CCFDC
    // 0x8018D2C8: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8018D2C8: addu        $a1, $v0, $t7
    ctx->r5 = ADD32(ctx->r2, ctx->r15);
    after_2:
    // 0x8018D2CC: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8018D2D0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D2D4: and         $t0, $t8, $s3
    ctx->r8 = ctx->r24 & ctx->r19;
    // 0x8018D2D8: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x8018D2DC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x8018D2E0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8018D2E4: lwc1        $f4, 0x0($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X0);
    // 0x8018D2E8: swc1        $f22, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f22.u32l;
    // 0x8018D2EC: add.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8018D2F0: jal         0x8018D160
    // 0x8018D2F4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    mvOpeningPikachuInitName(rdram, ctx);
        goto after_3;
    // 0x8018D2F4: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    after_3:
    // 0x8018D2F8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x8018D2FC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8018D300: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8018D304: bnel        $v0, $zero, L_8018D2C0
    if (ctx->r2 != 0) {
        // 0x8018D308: lw          $t7, 0x0($s2)
        ctx->r15 = MEM_W(ctx->r18, 0X0);
            goto L_8018D2C0;
    }
    goto skip_0;
    // 0x8018D308: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    skip_0:
L_8018D30C:
    // 0x8018D30C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8018D310: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8018D314: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x8018D318: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8018D31C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8018D320: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8018D324: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D328: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8018D32C: jr          $ra
    // 0x8018D330: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8018D330: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void ftCommonPassiveStandCheckInterruptDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144760: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80144764: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80144768: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8014476C: lw          $t6, 0x160($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X160);
    // 0x80144770: slti        $at, $t6, 0x14
    ctx->r1 = SIGNED(ctx->r14) < 0X14 ? 1 : 0;
    // 0x80144774: beql        $at, $zero, L_801447D0
    if (ctx->r1 == 0) {
        // 0x80144778: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801447D0;
    }
    goto skip_0;
    // 0x80144778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014477C: lb          $v0, 0x1C2($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X1C2);
    // 0x80144780: bgez        $v0, L_80144790
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80144784: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80144790;
    }
    // 0x80144784: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80144788: b           L_80144790
    // 0x8014478C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
        goto L_80144790;
    // 0x8014478C: negu        $v1, $v0
    ctx->r3 = SUB32(0, ctx->r2);
L_80144790:
    // 0x80144790: slti        $at, $v1, 0x14
    ctx->r1 = SIGNED(ctx->r3) < 0X14 ? 1 : 0;
    // 0x80144794: bnel        $at, $zero, L_801447D0
    if (ctx->r1 != 0) {
        // 0x80144798: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801447D0;
    }
    goto skip_1;
    // 0x80144798: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014479C: lw          $t7, 0x44($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X44);
    // 0x801447A0: addiu       $a1, $zero, 0x4A
    ctx->r5 = ADD32(0, 0X4A);
    // 0x801447A4: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801447A8: mflo        $t8
    ctx->r24 = lo;
    // 0x801447AC: bltz        $t8, L_801447BC
    if (SIGNED(ctx->r24) < 0) {
        // 0x801447B0: nop
    
            goto L_801447BC;
    }
    // 0x801447B0: nop

    // 0x801447B4: b           L_801447BC
    // 0x801447B8: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
        goto L_801447BC;
    // 0x801447B8: addiu       $a1, $zero, 0x49
    ctx->r5 = ADD32(0, 0X49);
L_801447BC:
    // 0x801447BC: jal         0x80144700
    // 0x801447C0: nop

    ftCommonPassiveStandSetStatus(rdram, ctx);
        goto after_0;
    // 0x801447C0: nop

    after_0:
    // 0x801447C4: b           L_801447D0
    // 0x801447C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801447D0;
    // 0x801447C8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801447CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801447D0:
    // 0x801447D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801447D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801447D8: jr          $ra
    // 0x801447DC: nop

    return;
    // 0x801447DC: nop

;}
RECOMP_FUNC void mnVSResultsMakeLabel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801366F0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801366F4: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801366F8: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x801366FC: addiu       $t7, $t7, -0x6924
    ctx->r15 = ADD32(ctx->r15, -0X6924);
    // 0x80136700: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80136704: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80136708: addiu       $t6, $sp, 0x54
    ctx->r14 = ADD32(ctx->r29, 0X54);
    // 0x8013670C: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80136710: addiu       $t1, $t1, -0x691C
    ctx->r9 = ADD32(ctx->r9, -0X691C);
    // 0x80136714: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80136718: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x8013671C: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80136720: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x80136724: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80136728: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x8013672C: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80136730: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80136734: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80136738: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x8013673C: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80136740: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80136744: jal         0x801365B4
    // 0x80136748: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    mnVSResultsCheckTeamBattle(rdram, ctx);
        goto after_0;
    // 0x80136748: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    after_0:
    // 0x8013674C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80136750: addiu       $t4, $t4, 0x65C0
    ctx->r12 = ADD32(ctx->r12, 0X65C0);
    // 0x80136754: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80136758: addiu       $t5, $zero, 0x1F
    ctx->r13 = ADD32(0, 0X1F);
    // 0x8013675C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80136760: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80136764: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x80136768: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x8013676C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80136770: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80136774: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80136778: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x8013677C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80136780: lw          $t2, -0x63F0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X63F0);
    // 0x80136784: lw          $t9, -0x5FB0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5FB0);
    // 0x80136788: lw          $t8, 0x54($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X54);
    // 0x8013678C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80136790: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80136794: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80136798: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013679C: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x801367A0: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x801367A4: lw          $t4, 0x40($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X40);
    // 0x801367A8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x801367AC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x801367B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801367B4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801367B8: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x801367BC: jal         0x800CD050
    // 0x801367C0: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_1;
    // 0x801367C0: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_1:
    // 0x801367C4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x801367C8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801367CC: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x801367D0: lui         $at, 0x41E8
    ctx->r1 = S32(0X41E8 << 16);
    // 0x801367D4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801367D8: swc1        $f4, 0x58($t6)
    MEM_W(0X58, ctx->r14) = ctx->f4.u32l;
    // 0x801367DC: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x801367E0: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x801367E4: swc1        $f6, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f6.u32l;
    // 0x801367E8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801367EC: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x801367F0: andi        $t9, $t8, 0xFFDF
    ctx->r25 = ctx->r24 & 0XFFDF;
    // 0x801367F4: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x801367F8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801367FC: lhu         $t0, 0x24($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X24);
    // 0x80136800: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x80136804: sh          $t1, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r9;
    // 0x80136808: lw          $t2, 0x74($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X74);
    // 0x8013680C: sb          $a0, 0x28($t2)
    MEM_B(0X28, ctx->r10) = ctx->r4;
    // 0x80136810: lw          $t3, 0x74($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X74);
    // 0x80136814: sb          $a0, 0x29($t3)
    MEM_B(0X29, ctx->r11) = ctx->r4;
    // 0x80136818: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x8013681C: sb          $a0, 0x2A($t4)
    MEM_B(0X2A, ctx->r12) = ctx->r4;
    // 0x80136820: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80136824: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80136828: jr          $ra
    // 0x8013682C: nop

    return;
    // 0x8013682C: nop

;}
RECOMP_FUNC void ftCommonAttack12CheckGoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014EF50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014EF54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014EF58: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014EF5C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8014EF60: lwc1        $f0, 0x150($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X150);
    // 0x8014EF64: lw          $v1, 0x9C8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X9C8);
    // 0x8014EF68: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8014EF6C: nop

    // 0x8014EF70: bc1tl       L_8014EFD0
    if (c1cs) {
        // 0x8014EF74: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014EFD0;
    }
    goto skip_0;
    // 0x8014EF74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014EF78: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8014EF7C: lhu         $t7, 0x1BE($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1BE);
    // 0x8014EF80: lhu         $t8, 0x1B4($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1B4);
    // 0x8014EF84: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8014EF88: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8014EF8C: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x8014EF90: beq         $t9, $zero, L_8014EFCC
    if (ctx->r25 == 0) {
        // 0x8014EF94: swc1        $f8, 0x150($v0)
        MEM_W(0X150, ctx->r2) = ctx->f8.u32l;
            goto L_8014EFCC;
    }
    // 0x8014EF94: swc1        $f8, 0x150($v0)
    MEM_W(0X150, ctx->r2) = ctx->f8.u32l;
    // 0x8014EF98: lw          $t0, 0x100($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X100);
    // 0x8014EF9C: sll         $t2, $t0, 1
    ctx->r10 = S32(ctx->r8 << 1);
    // 0x8014EFA0: bgezl       $t2, L_8014EFD0
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8014EFA4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014EFD0;
    }
    goto skip_1;
    // 0x8014EFA4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x8014EFA8: lw          $t3, 0x180($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X180);
    // 0x8014EFAC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8014EFB0: beql        $t3, $zero, L_8014EFCC
    if (ctx->r11 == 0) {
        // 0x8014EFB4: sw          $t4, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r12;
            goto L_8014EFCC;
    }
    goto skip_2;
    // 0x8014EFB4: sw          $t4, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r12;
    skip_2:
    // 0x8014EFB8: jal         0x8014EAD8
    // 0x8014EFBC: nop

    ftCommonAttack12SetStatus(rdram, ctx);
        goto after_0;
    // 0x8014EFBC: nop

    after_0:
    // 0x8014EFC0: b           L_8014EFD0
    // 0x8014EFC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014EFD0;
    // 0x8014EFC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014EFC8: sw          $t4, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r12;
L_8014EFCC:
    // 0x8014EFCC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014EFD0:
    // 0x8014EFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014EFD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014EFD8: jr          $ra
    // 0x8014EFDC: nop

    return;
    // 0x8014EFDC: nop

;}
RECOMP_FUNC void func_ovl8_80374BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374BA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374BA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374BAC: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80374BB0: lw          $t9, 0x3C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X3C);
    // 0x80374BB4: lh          $t6, 0x38($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X38);
    // 0x80374BB8: jalr        $t9
    // 0x80374BBC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374BBC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80374BC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80374BC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374BC8: jr          $ra
    // 0x80374BCC: nop

    return;
    // 0x80374BCC: nop

;}
RECOMP_FUNC void ftCommonAttackDashCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F69C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8014F6A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014F6A4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014F6A8: lhu         $t6, 0x1BE($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X1BE);
    // 0x8014F6AC: lhu         $t7, 0x1B4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B4);
    // 0x8014F6B0: lw          $a1, 0x9C8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X9C8);
    // 0x8014F6B4: and         $t8, $t6, $t7
    ctx->r24 = ctx->r14 & ctx->r15;
    // 0x8014F6B8: beql        $t8, $zero, L_8014F744
    if (ctx->r24 == 0) {
        // 0x8014F6BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014F744;
    }
    goto skip_0;
    // 0x8014F6BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8014F6C0: lw          $v1, 0x84C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84C);
    // 0x8014F6C4: beql        $v1, $zero, L_8014F724
    if (ctx->r3 == 0) {
        // 0x8014F6C8: lw          $t3, 0x100($a1)
        ctx->r11 = MEM_W(ctx->r5, 0X100);
            goto L_8014F724;
    }
    goto skip_1;
    // 0x8014F6C8: lw          $t3, 0x100($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X100);
    skip_1:
    // 0x8014F6CC: lhu         $t9, 0x1BC($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X1BC);
    // 0x8014F6D0: lhu         $t0, 0x1B8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X1B8);
    // 0x8014F6D4: and         $t1, $t9, $t0
    ctx->r9 = ctx->r25 & ctx->r8;
    // 0x8014F6D8: bne         $t1, $zero, L_8014F6F4
    if (ctx->r9 != 0) {
        // 0x8014F6DC: nop
    
            goto L_8014F6F4;
    }
    // 0x8014F6DC: nop

    // 0x8014F6E0: lw          $t2, 0x84($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X84);
    // 0x8014F6E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8014F6E8: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x8014F6EC: bnel        $v0, $at, L_8014F708
    if (ctx->r2 != ctx->r1) {
        // 0x8014F6F0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8014F708;
    }
    goto skip_2;
    // 0x8014F6F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_2:
L_8014F6F4:
    // 0x8014F6F4: jal         0x80146690
    // 0x8014F6F8: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    ftCommonItemThrowSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014F6F8: addiu       $a1, $zero, 0x69
    ctx->r5 = ADD32(0, 0X69);
    after_0:
    // 0x8014F6FC: b           L_8014F744
    // 0x8014F700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014F744;
    // 0x8014F700: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014F704: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8014F708:
    // 0x8014F708: bnel        $v0, $at, L_8014F724
    if (ctx->r2 != ctx->r1) {
        // 0x8014F70C: lw          $t3, 0x100($a1)
        ctx->r11 = MEM_W(ctx->r5, 0X100);
            goto L_8014F724;
    }
    goto skip_3;
    // 0x8014F70C: lw          $t3, 0x100($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X100);
    skip_3:
    // 0x8014F710: jal         0x80146E94
    // 0x8014F714: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    ftCommonItemSwingSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014F714: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x8014F718: b           L_8014F744
    // 0x8014F71C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014F744;
    // 0x8014F71C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014F720: lw          $t3, 0x100($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X100);
L_8014F724:
    // 0x8014F724: sll         $t5, $t3, 2
    ctx->r13 = S32(ctx->r11 << 2);
    // 0x8014F728: bgezl       $t5, L_8014F744
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8014F72C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8014F744;
    }
    goto skip_4;
    // 0x8014F72C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x8014F730: jal         0x8014F670
    // 0x8014F734: nop

    ftCommonAttackDashSetStatus(rdram, ctx);
        goto after_2;
    // 0x8014F734: nop

    after_2:
    // 0x8014F738: b           L_8014F744
    // 0x8014F73C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8014F744;
    // 0x8014F73C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8014F740: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8014F744:
    // 0x8014F744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014F748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014F74C: jr          $ra
    // 0x8014F750: nop

    return;
    // 0x8014F750: nop

;}
RECOMP_FUNC void sc1PGameBossSetIgnorePlayerMapBounds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F5CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018F5D0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8018F5D4: lbu         $t7, 0x18D($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X18D);
    // 0x8018F5D8: ori         $t8, $t7, 0x2
    ctx->r24 = ctx->r15 | 0X2;
    // 0x8018F5DC: jr          $ra
    // 0x8018F5E0: sb          $t8, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r24;
    return;
    // 0x8018F5E0: sb          $t8, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r24;
;}
RECOMP_FUNC void alCSPSetSeq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FA70: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002FA74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FA78: addiu       $t6, $zero, 0xD
    ctx->r14 = ADD32(0, 0XD);
    // 0x8002FA7C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002FA80: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x8002FA84: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8002FA88: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8002FA8C: jal         0x80028D70
    // 0x8002FA90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x8002FA90: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8002FA94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FA98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002FA9C: jr          $ra
    // 0x8002FAA0: nop

    return;
    // 0x8002FAA0: nop

;}
RECOMP_FUNC void func_ovl29_80133F4C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F4C: jr          $ra
    // 0x80133F50: nop

    return;
    // 0x80133F50: nop

;}
RECOMP_FUNC void ftNessSpecialLwHoldSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155680: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80155684: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80155688: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015568C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80155690: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80155694: jal         0x800DEEC8
    // 0x80155698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80155698: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8015569C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801556A0: addiu       $t7, $zero, 0x97
    ctx->r15 = ADD32(0, 0X97);
    // 0x801556A4: addiu       $a1, $zero, 0xF2
    ctx->r5 = ADD32(0, 0XF2);
    // 0x801556A8: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801556AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801556B0: jal         0x800E6F24
    // 0x801556B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801556B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801556B8: jal         0x800D8EB8
    // 0x801556BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x801556BC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801556C0: lbu         $t9, 0x18D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18D);
    // 0x801556C4: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x801556C8: sb          $t0, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r8;
    // 0x801556CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801556D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801556D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801556D8: jr          $ra
    // 0x801556DC: nop

    return;
    // 0x801556DC: nop

;}
RECOMP_FUNC void ftPublicDecideCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164DE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80164DE8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80164DEC: mtc1        $a2, $f20
    ctx->f20.u32l = ctx->r6;
    // 0x80164DF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80164DF4: beq         $a3, $zero, L_80164E10
    if (ctx->r7 == 0) {
        // 0x80164DF8: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80164E10;
    }
    // 0x80164DF8: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80164DFC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80164E00: jal         0x80164D08
    // 0x80164E04: nop

    ftPublicDecideCall(rdram, ctx);
        goto after_0;
    // 0x80164E04: nop

    after_0:
    // 0x80164E08: b           L_80164F04
    // 0x80164E0C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_80164F04;
    // 0x80164E0C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80164E10:
    // 0x80164E10: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80164E14: lw          $t7, -0x306C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X306C);
    // 0x80164E18: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x80164E1C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80164E20: bnel        $t6, $t7, L_80164E70
    if (ctx->r14 != ctx->r15) {
        // 0x80164E24: lui         $at, 0x4320
        ctx->r1 = S32(0X4320 << 16);
            goto L_80164E70;
    }
    goto skip_0;
    // 0x80164E24: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    skip_0:
    // 0x80164E28: lw          $t8, -0x3070($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3070);
    // 0x80164E2C: slti        $at, $t8, 0x3C
    ctx->r1 = SIGNED(ctx->r24) < 0X3C ? 1 : 0;
    // 0x80164E30: beq         $at, $zero, L_80164E6C
    if (ctx->r1 == 0) {
        // 0x80164E34: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80164E6C;
    }
    // 0x80164E34: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164E38: lwc1        $f0, -0x3068($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3068);
    // 0x80164E3C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x80164E40: nop

    // 0x80164E44: bc1fl       L_80164E58
    if (!c1cs) {
        // 0x80164E48: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80164E58;
    }
    goto skip_1;
    // 0x80164E48: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x80164E4C: b           L_80164E58
    // 0x80164E50: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
        goto L_80164E58;
    // 0x80164E50: mov.s       $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    ctx->f2.fl = ctx->f20.fl;
    // 0x80164E54: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80164E58:
    // 0x80164E58: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x80164E5C: jal         0x80164D08
    // 0x80164E60: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    ftPublicDecideCall(rdram, ctx);
        goto after_1;
    // 0x80164E60: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80164E64: b           L_80164F04
    // 0x80164E68: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_80164F04;
    // 0x80164E68: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80164E6C:
    // 0x80164E6C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
L_80164E70:
    // 0x80164E70: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80164E74: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80164E78: c.le.s      $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f4.fl <= ctx->f20.fl;
    // 0x80164E7C: nop

    // 0x80164E80: bc1fl       L_80164EA4
    if (!c1cs) {
        // 0x80164E84: mtc1        $at, $f6
        ctx->f6.u32l = ctx->r1;
            goto L_80164EA4;
    }
    goto skip_2;
    // 0x80164E84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    skip_2:
    // 0x80164E88: jal         0x80164C18
    // 0x80164E8C: nop

    ftPublicTryInterruptCall(rdram, ctx);
        goto after_2;
    // 0x80164E8C: nop

    after_2:
    // 0x80164E90: jal         0x80164C44
    // 0x80164E94: addiu       $a0, $zero, 0x26E
    ctx->r4 = ADD32(0, 0X26E);
    ftPublicPlayCommon(rdram, ctx);
        goto after_3;
    // 0x80164E94: addiu       $a0, $zero, 0x26E
    ctx->r4 = ADD32(0, 0X26E);
    after_3:
    // 0x80164E98: b           L_80164F04
    // 0x80164E9C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_80164F04;
    // 0x80164E9C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80164EA0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
L_80164EA4:
    // 0x80164EA4: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80164EA8: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x80164EAC: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x80164EB0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80164EB4: bc1fl       L_80164EE4
    if (!c1cs) {
        // 0x80164EB8: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_80164EE4;
    }
    goto skip_3;
    // 0x80164EB8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_3:
    // 0x80164EBC: lw          $t0, -0x3054($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X3054);
    // 0x80164EC0: bne         $t9, $t0, L_80164ED0
    if (ctx->r25 != ctx->r8) {
        // 0x80164EC4: nop
    
            goto L_80164ED0;
    }
    // 0x80164EC4: nop

    // 0x80164EC8: jal         0x80164C18
    // 0x80164ECC: nop

    ftPublicTryInterruptCall(rdram, ctx);
        goto after_4;
    // 0x80164ECC: nop

    after_4:
L_80164ED0:
    // 0x80164ED0: jal         0x80164C44
    // 0x80164ED4: addiu       $a0, $zero, 0x26F
    ctx->r4 = ADD32(0, 0X26F);
    ftPublicPlayCommon(rdram, ctx);
        goto after_5;
    // 0x80164ED4: addiu       $a0, $zero, 0x26F
    ctx->r4 = ADD32(0, 0X26F);
    after_5:
    // 0x80164ED8: b           L_80164F04
    // 0x80164EDC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_80164F04;
    // 0x80164EDC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80164EE0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_80164EE4:
    // 0x80164EE4: nop

    // 0x80164EE8: c.le.s      $f8, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f8.fl <= ctx->f20.fl;
    // 0x80164EEC: nop

    // 0x80164EF0: bc1fl       L_80164F04
    if (!c1cs) {
        // 0x80164EF4: lw          $t1, 0x24($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X24);
            goto L_80164F04;
    }
    goto skip_4;
    // 0x80164EF4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x80164EF8: jal         0x80164C44
    // 0x80164EFC: addiu       $a0, $zero, 0x271
    ctx->r4 = ADD32(0, 0X271);
    ftPublicPlayCommon(rdram, ctx);
        goto after_6;
    // 0x80164EFC: addiu       $a0, $zero, 0x271
    ctx->r4 = ADD32(0, 0X271);
    after_6:
    // 0x80164F00: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80164F04:
    // 0x80164F04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164F08: sw          $zero, -0x3070($at)
    MEM_W(-0X3070, ctx->r1) = 0;
    // 0x80164F0C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164F10: sw          $t1, -0x306C($at)
    MEM_W(-0X306C, ctx->r1) = ctx->r9;
    // 0x80164F14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80164F18: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164F1C: swc1        $f20, -0x3068($at)
    MEM_W(-0X3068, ctx->r1) = ctx->f20.u32l;
    // 0x80164F20: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80164F24: jr          $ra
    // 0x80164F28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80164F28: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnPlayers1PGameMakeTotalBonusCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134D08: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80134D0C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134D10: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80134D14: addiu       $t7, $t7, -0x74A8
    ctx->r15 = ADD32(ctx->r15, -0X74A8);
    // 0x80134D18: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134D1C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80134D20: addiu       $t6, $sp, 0x30
    ctx->r14 = ADD32(ctx->r29, 0X30);
    // 0x80134D24: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80134D28: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80134D2C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80134D30: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80134D34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134D38: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80134D3C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80134D40: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80134D44: lw          $t8, 0x14($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X14);
    // 0x80134D48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134D4C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80134D50: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80134D54: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80134D58: jal         0x80009968
    // 0x80134D5C: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80134D5C: sw          $t8, 0x14($t6)
    MEM_W(0X14, ctx->r14) = ctx->r24;
    after_0:
    // 0x80134D60: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80134D64: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80134D68: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80134D6C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80134D70: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80134D74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80134D78: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80134D7C: jal         0x80009DF4
    // 0x80134D80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80134D80: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80134D84: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80134D88: lw          $t1, -0x694C($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X694C);
    // 0x80134D8C: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80134D90: addiu       $t2, $t2, 0x368
    ctx->r10 = ADD32(ctx->r10, 0X368);
    // 0x80134D94: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80134D98: jal         0x800CCFDC
    // 0x80134D9C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80134D9C: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_2:
    // 0x80134DA0: lhu         $t3, 0x24($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0X24);
    // 0x80134DA4: lui         $at, 0x4381
    ctx->r1 = S32(0X4381 << 16);
    // 0x80134DA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134DAC: lui         $at, 0x4351
    ctx->r1 = S32(0X4351 << 16);
    // 0x80134DB0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80134DB4: andi        $t5, $t3, 0xFFDF
    ctx->r13 = ctx->r11 & 0XFFDF;
    // 0x80134DB8: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80134DBC: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x80134DC0: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80134DC4: addiu       $t8, $zero, 0x6F
    ctx->r24 = ADD32(0, 0X6F);
    // 0x80134DC8: addiu       $t9, $zero, 0xCD
    ctx->r25 = ADD32(0, 0XCD);
    // 0x80134DCC: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80134DD0: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80134DD4: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x80134DD8: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x80134DDC: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80134DE0: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80134DE4: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80134DE8: lw          $t0, -0x694C($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X694C);
    // 0x80134DEC: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80134DF0: addiu       $t1, $t1, 0x2C8
    ctx->r9 = ADD32(ctx->r9, 0X2C8);
    // 0x80134DF4: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80134DF8: jal         0x800CCFDC
    // 0x80134DFC: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80134DFC: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_3:
    // 0x80134E00: lhu         $t2, 0x24($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0X24);
    // 0x80134E04: lui         $at, 0x438F
    ctx->r1 = S32(0X438F << 16);
    // 0x80134E08: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80134E0C: lui         $at, 0x4351
    ctx->r1 = S32(0X4351 << 16);
    // 0x80134E10: andi        $t4, $t2, 0xFFDF
    ctx->r12 = ctx->r10 & 0XFFDF;
    // 0x80134E14: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80134E18: sh          $t4, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r12;
    // 0x80134E1C: ori         $t5, $t4, 0x1
    ctx->r13 = ctx->r12 | 0X1;
    // 0x80134E20: addiu       $t6, $zero, 0x40
    ctx->r14 = ADD32(0, 0X40);
    // 0x80134E24: addiu       $t7, $zero, 0x6F
    ctx->r15 = ADD32(0, 0X6F);
    // 0x80134E28: addiu       $t8, $zero, 0xCD
    ctx->r24 = ADD32(0, 0XCD);
    // 0x80134E2C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x80134E30: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x80134E34: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x80134E38: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x80134E3C: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80134E40: jal         0x80134CB8
    // 0x80134E44: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    mnPlayers1PGameGetTotalBonusCount(rdram, ctx);
        goto after_4;
    // 0x80134E44: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    after_4:
    // 0x80134E48: lui         $a2, 0x438E
    ctx->r6 = S32(0X438E << 16);
    // 0x80134E4C: addiu       $t9, $sp, 0x30
    ctx->r25 = ADD32(ctx->r29, 0X30);
    // 0x80134E50: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x80134E54: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80134E58: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80134E5C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x80134E60: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80134E64: ori         $a2, $a2, 0x8000
    ctx->r6 = ctx->r6 | 0X8000;
    // 0x80134E68: lw          $a0, 0x54($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X54);
    // 0x80134E6C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80134E70: jal         0x80131CEC
    // 0x80134E74: lui         $a3, 0x4350
    ctx->r7 = S32(0X4350 << 16);
    mnPlayers1PGameMakeNumber(rdram, ctx);
        goto after_5;
    // 0x80134E74: lui         $a3, 0x4350
    ctx->r7 = S32(0X4350 << 16);
    after_5:
    // 0x80134E78: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80134E7C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x80134E80: jr          $ra
    // 0x80134E84: nop

    return;
    // 0x80134E84: nop

;}
RECOMP_FUNC void ifCommonPlayerMagnifyUpdateViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80110DD4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80110DD8: addiu       $t2, $t2, 0x1580
    ctx->r10 = ADD32(ctx->r10, 0X1580);
    // 0x80110DDC: lbu         $t6, 0x0($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X0);
    // 0x80110DE0: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80110DE4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80110DE8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80110DEC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80110DF0: beq         $t6, $zero, L_8011118C
    if (ctx->r14 == 0) {
        // 0x80110DF4: sw          $s0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r16;
            goto L_8011118C;
    }
    // 0x80110DF4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80110DF8: lbu         $t7, 0xD($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XD);
    // 0x80110DFC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80110E00: addiu       $t9, $t9, 0x1748
    ctx->r25 = ADD32(ctx->r25, 0X1748);
    // 0x80110E04: sll         $t8, $t7, 5
    ctx->r24 = S32(ctx->r15 << 5);
    // 0x80110E08: addu        $s0, $t8, $t9
    ctx->r16 = ADD32(ctx->r24, ctx->r25);
    // 0x80110E0C: lwc1        $f12, 0x1A8($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X1A8);
    // 0x80110E10: lwc1        $f14, 0x1AC($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X1AC);
    // 0x80110E14: jal         0x801105CC
    // 0x80110E18: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    ifCommonPlayerMagnifyGetPosition(rdram, ctx);
        goto after_0;
    // 0x80110E18: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x80110E1C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80110E20: addiu       $t0, $t0, 0x14B0
    ctx->r8 = ADD32(ctx->r8, 0X14B0);
    // 0x80110E24: lw          $t6, 0x30($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X30);
    // 0x80110E28: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80110E2C: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80110E30: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80110E34: lw          $t7, 0x34($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X34);
    // 0x80110E38: lui         $t9, 0xDA38
    ctx->r25 = S32(0XDA38 << 16);
    // 0x80110E3C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80110E40: lwc1        $f6, 0x4($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80110E44: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80110E48: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80110E4C: ori         $t9, $t9, 0x7
    ctx->r25 = ctx->r25 | 0X7;
    // 0x80110E50: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80110E54: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80110E58: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x80110E5C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80110E60: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80110E64: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x80110E68: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80110E6C: addiu       $t2, $t2, 0x1580
    ctx->r10 = ADD32(ctx->r10, 0X1580);
    // 0x80110E70: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x80110E74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80110E78: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80110E7C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80110E80: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80110E84: lbu         $t6, 0x1($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X1);
    // 0x80110E88: add.s       $f12, $f4, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80110E8C: beq         $t6, $at, L_80110F80
    if (ctx->r14 == ctx->r1) {
        // 0x80110E90: sub.s       $f14, $f18, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
            goto L_80110F80;
    }
    // 0x80110E90: sub.s       $f14, $f18, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80110E94: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80110E98: lw          $t7, 0x1460($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1460);
    // 0x80110E9C: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80110EA0: lui         $t9, 0xDC08
    ctx->r25 = S32(0XDC08 << 16);
    // 0x80110EA4: lw          $a1, 0x74($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X74);
    // 0x80110EA8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80110EAC: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80110EB0: ori         $t9, $t9, 0x8
    ctx->r25 = ctx->r25 | 0X8;
    // 0x80110EB4: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80110EB8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80110EBC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80110EC0: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80110EC4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80110EC8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80110ECC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80110ED0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80110ED4: lw          $t8, 0x20($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X20);
    // 0x80110ED8: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80110EDC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80110EE0: nop

    // 0x80110EE4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80110EE8: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80110EEC: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80110EF0: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x80110EF4: nop

    // 0x80110EF8: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80110EFC: lw          $t6, 0x24($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X24);
    // 0x80110F00: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80110F04: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80110F08: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80110F0C: nop

    // 0x80110F10: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80110F14: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80110F18: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x80110F1C: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80110F20: nop

    // 0x80110F24: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x80110F28: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80110F2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80110F30: lw          $t8, 0x28($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X28);
    // 0x80110F34: lw          $t9, 0x2C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X2C);
    // 0x80110F38: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80110F3C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80110F40: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80110F44: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80110F48: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80110F4C: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80110F50: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80110F54: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80110F58: nop

    // 0x80110F5C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80110F60: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80110F64: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80110F68: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x80110F6C: nop

    // 0x80110F70: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80110F74: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80110F78: b           L_80110F84
    // 0x80110F7C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_80110F84;
    // 0x80110F7C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_80110F80:
    // 0x80110F80: sb          $t7, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r15;
L_80110F84:
    // 0x80110F84: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80110F88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80110F8C: lwc1        $f10, 0x4($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80110F90: lbu         $a1, 0x1C($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C);
    // 0x80110F94: swc1        $f14, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f14.u32l;
    // 0x80110F98: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80110F9C: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80110FA0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80110FA4: sub.s       $f18, $f12, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x80110FA8: sub.s       $f6, $f14, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x80110FAC: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x80110FB0: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x80110FB4: jal         0x801107F0
    // 0x80110FB8: nop

    ifCommonPlayerMagnifyUpdateRender(rdram, ctx);
        goto after_1;
    // 0x80110FB8: nop

    after_1:
    // 0x80110FBC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80110FC0: addiu       $t2, $t2, 0x1580
    ctx->r10 = ADD32(ctx->r10, 0X1580);
    // 0x80110FC4: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x80110FC8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80110FCC: lwc1        $f8, 0x4($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X4);
    // 0x80110FD0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80110FD4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80110FD8: mul.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80110FDC: lwc1        $f12, 0x68($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80110FE0: lwc1        $f14, 0x64($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80110FE4: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x80110FE8: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x80110FEC: sw          $a0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r4;
    // 0x80110FF0: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x80110FF4: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80110FF8: sub.s       $f12, $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f12.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80110FFC: sub.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f2.fl;
    // 0x80111000: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80111004: add.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x80111008: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8011100C: add.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f14.fl;
    // 0x80111010: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x80111014: jal         0x80007080
    // 0x80111018: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_2;
    // 0x80111018: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_2:
    // 0x8011101C: lw          $t1, 0x6C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X6C);
    // 0x80111020: lui         $t8, 0xDC08
    ctx->r24 = S32(0XDC08 << 16);
    // 0x80111024: ori         $t8, $t8, 0x8
    ctx->r24 = ctx->r24 | 0X8;
    // 0x80111028: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x8011102C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80111030: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80111034: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80111038: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8011103C: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80111040: lh          $v1, 0x10($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X10);
    // 0x80111044: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    // 0x80111048: lh          $a1, 0x12($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X12);
    // 0x8011104C: lh          $a2, 0xA($s0)
    ctx->r6 = MEM_H(ctx->r16, 0XA);
    // 0x80111050: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80111054: addiu       $t0, $t0, 0x14B0
    ctx->r8 = ADD32(ctx->r8, 0X14B0);
    // 0x80111058: lw          $a3, 0x20($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X20);
    // 0x8011105C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80111060: bgez        $v1, L_8011106C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80111064: addu        $at, $v1, $zero
        ctx->r1 = ADD32(ctx->r3, 0);
            goto L_8011106C;
    }
    // 0x80111064: addu        $at, $v1, $zero
    ctx->r1 = ADD32(ctx->r3, 0);
    // 0x80111068: addiu       $at, $v1, 0x3
    ctx->r1 = ADD32(ctx->r3, 0X3);
L_8011106C:
    // 0x8011106C: sra         $v1, $at, 2
    ctx->r3 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80111070: bgez        $a0, L_8011107C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80111074: addu        $at, $a0, $zero
        ctx->r1 = ADD32(ctx->r4, 0);
            goto L_8011107C;
    }
    // 0x80111074: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x80111078: addiu       $at, $a0, 0x3
    ctx->r1 = ADD32(ctx->r4, 0X3);
L_8011107C:
    // 0x8011107C: sra         $a0, $at, 2
    ctx->r4 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80111080: subu        $t2, $v1, $a0
    ctx->r10 = SUB32(ctx->r3, ctx->r4);
    // 0x80111084: bgez        $a1, L_80111090
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80111088: addu        $at, $a1, $zero
        ctx->r1 = ADD32(ctx->r5, 0);
            goto L_80111090;
    }
    // 0x80111088: addu        $at, $a1, $zero
    ctx->r1 = ADD32(ctx->r5, 0);
    // 0x8011108C: addiu       $at, $a1, 0x3
    ctx->r1 = ADD32(ctx->r5, 0X3);
L_80111090:
    // 0x80111090: sra         $a1, $at, 2
    ctx->r5 = S32(SIGNED(ctx->r1) >> 2);
    // 0x80111094: bgez        $a2, L_801110A0
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80111098: addu        $at, $a2, $zero
        ctx->r1 = ADD32(ctx->r6, 0);
            goto L_801110A0;
    }
    // 0x80111098: addu        $at, $a2, $zero
    ctx->r1 = ADD32(ctx->r6, 0);
    // 0x8011109C: addiu       $at, $a2, 0x3
    ctx->r1 = ADD32(ctx->r6, 0X3);
L_801110A0:
    // 0x801110A0: sra         $a2, $at, 2
    ctx->r6 = S32(SIGNED(ctx->r1) >> 2);
    // 0x801110A4: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x801110A8: subu        $t3, $a1, $a2
    ctx->r11 = SUB32(ctx->r5, ctx->r6);
    // 0x801110AC: addu        $t4, $a0, $v1
    ctx->r12 = ADD32(ctx->r4, ctx->r3);
    // 0x801110B0: beq         $at, $zero, L_801110BC
    if (ctx->r1 == 0) {
        // 0x801110B4: addu        $t5, $a2, $a1
        ctx->r13 = ADD32(ctx->r6, ctx->r5);
            goto L_801110BC;
    }
    // 0x801110B4: addu        $t5, $a2, $a1
    ctx->r13 = ADD32(ctx->r6, ctx->r5);
    // 0x801110B8: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
L_801110BC:
    // 0x801110BC: lw          $v0, 0x28($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X28);
    // 0x801110C0: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x801110C4: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x801110C8: beq         $at, $zero, L_801110D4
    if (ctx->r1 == 0) {
        // 0x801110CC: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_801110D4;
    }
    // 0x801110CC: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801110D0: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_801110D4:
    // 0x801110D4: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x801110D8: mul.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x801110DC: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x801110E0: beql        $at, $zero, L_801110F4
    if (ctx->r1 == 0) {
        // 0x801110E4: lw          $v0, 0x2C($t0)
        ctx->r2 = MEM_W(ctx->r8, 0X2C);
            goto L_801110F4;
    }
    goto skip_0;
    // 0x801110E4: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
    skip_0:
    // 0x801110E8: b           L_80111104
    // 0x801110EC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
        goto L_80111104;
    // 0x801110EC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x801110F0: lw          $v0, 0x2C($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X2C);
L_801110F4:
    // 0x801110F4: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x801110F8: beql        $at, $zero, L_80111108
    if (ctx->r1 == 0) {
        // 0x801110FC: mtc1        $t3, $f6
        ctx->f6.u32l = ctx->r11;
            goto L_80111108;
    }
    goto skip_1;
    // 0x801110FC: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    skip_1:
    // 0x80111100: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
L_80111104:
    // 0x80111104: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
L_80111108:
    // 0x80111108: trunc.w.s   $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x8011110C: lui         $at, 0xED00
    ctx->r1 = S32(0XED00 << 16);
    // 0x80111110: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80111114: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80111118: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8011111C: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80111120: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80111124: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80111128: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8011112C: mul.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x80111130: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80111134: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80111138: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x8011113C: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x80111140: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80111144: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x80111148: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8011114C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80111150: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x80111154: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80111158: trunc.w.s   $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x8011115C: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x80111160: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80111164: nop

    // 0x80111168: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8011116C: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80111170: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x80111174: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x80111178: nop

    // 0x8011117C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80111180: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80111184: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80111188: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
L_8011118C:
    // 0x8011118C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80111190: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80111194: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80111198: jr          $ra
    // 0x8011119C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8011119C: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void gmCameraInishieFuncCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010CB48: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8010CB4C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010CB50: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8010CB54: lw          $s0, 0x74($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X74);
    // 0x8010CB58: addiu       $a0, $sp, 0x30
    ctx->r4 = ADD32(ctx->r29, 0X30);
    // 0x8010CB5C: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    // 0x8010CB60: jal         0x8010BC54
    // 0x8010CB64: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    gmCameraUpdateInterests(rdram, ctx);
        goto after_0;
    // 0x8010CB64: addiu       $a2, $sp, 0x28
    ctx->r6 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x8010CB68: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x8010CB6C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8010CB70: jal         0x8010C70C
    // 0x8010CB74: nop

    gmCameraAdjustFOV(rdram, ctx);
        goto after_1;
    // 0x8010CB74: nop

    after_1:
    // 0x8010CB78: lwc1        $f12, 0x2C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8010CB7C: lwc1        $f14, 0x28($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8010CB80: jal         0x8010C200
    // 0x8010CB84: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    gmCameraGetClampDimensionsMax(rdram, ctx);
        goto after_2;
    // 0x8010CB84: addiu       $a2, $sp, 0x48
    ctx->r6 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x8010CB88: jal         0x8010C670
    // 0x8010CB8C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    func_ovl2_8010C670(rdram, ctx);
        goto after_3;
    // 0x8010CB8C: lwc1        $f12, 0x48($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X48);
    after_3:
    // 0x8010CB90: jal         0x8010C4D0
    // 0x8010CB94: nop

    func_ovl2_8010C4D0(rdram, ctx);
        goto after_4;
    // 0x8010CB94: nop

    after_4:
    // 0x8010CB98: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8010CB9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010CBA0: jal         0x8010C55C
    // 0x8010CBA4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    gmCameraPan(rdram, ctx);
        goto after_5;
    // 0x8010CBA4: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x8010CBA8: addiu       $a0, $s0, 0x48
    ctx->r4 = ADD32(ctx->r16, 0X48);
    // 0x8010CBAC: jal         0x8010C4A4
    // 0x8010CBB0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    gmCameraUpdateInishieFocus(rdram, ctx);
        goto after_6;
    // 0x8010CBB0: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x8010CBB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8010CBB8: jal         0x8010C5C0
    // 0x8010CBBC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    func_ovl2_8010C5C0(rdram, ctx);
        goto after_7;
    // 0x8010CBBC: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_7:
    // 0x8010CBC0: jal         0x8010C6B8
    // 0x8010CBC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCameraApplyVel(rdram, ctx);
        goto after_8;
    // 0x8010CBC4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8010CBC8: jal         0x8010C6FC
    // 0x8010CBCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gmCameraApplyFOV(rdram, ctx);
        goto after_9;
    // 0x8010CBCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x8010CBD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010CBD4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010CBD8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x8010CBDC: jr          $ra
    // 0x8010CBE0: nop

    return;
    // 0x8010CBE0: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151D64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80151D68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80151D6C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80151D70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80151D74: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x80151D78: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80151D7C: jal         0x800E6F24
    // 0x80151D80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80151D80: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80151D84: jal         0x800E0830
    // 0x80151D88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80151D88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80151D8C: jal         0x80151D0C
    // 0x80151D90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftPikachuSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80151D90: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80151D94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80151D98: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80151D9C: jr          $ra
    // 0x80151DA0: nop

    return;
    // 0x80151DA0: nop

;}
RECOMP_FUNC void mvOpeningDonkeyInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE3C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DE40: jr          $ra
    // 0x8018DE44: sw          $zero, -0x1E38($at)
    MEM_W(-0X1E38, ctx->r1) = 0;
    return;
    // 0x8018DE44: sw          $zero, -0x1E38($at)
    MEM_W(-0X1E38, ctx->r1) = 0;
;}
RECOMP_FUNC void scVSBattleStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E190: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018E194: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E198: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018E19C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E1A0: addiu       $t6, $t6, 0x4D08
    ctx->r14 = ADD32(ctx->r14, 0X4D08);
    // 0x8018E1A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E1A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018E1AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8018E1B0: sb          $t7, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r15;
    // 0x8018E1B4: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8018E1B8: lbu         $t9, 0x4ADF($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4ADF);
    // 0x8018E1BC: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8018E1C0: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8018E1C4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E1C8: sb          $t9, 0x1($t0)
    MEM_B(0X1, ctx->r8) = ctx->r25;
    // 0x8018E1CC: lbu         $t1, 0x4AC2($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X4AC2);
    // 0x8018E1D0: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8018E1D4: addiu       $a0, $a0, -0x1C28
    ctx->r4 = ADD32(ctx->r4, -0X1C28);
    // 0x8018E1D8: andi        $t2, $t1, 0x8
    ctx->r10 = ctx->r9 & 0X8;
    // 0x8018E1DC: beq         $t2, $zero, L_8018E1EC
    if (ctx->r10 == 0) {
        // 0x8018E1E0: addiu       $t4, $t4, 0x5240
        ctx->r12 = ADD32(ctx->r12, 0X5240);
            goto L_8018E1EC;
    }
    // 0x8018E1E0: addiu       $t4, $t4, 0x5240
    ctx->r12 = ADD32(ctx->r12, 0X5240);
    // 0x8018E1E4: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8018E1E8: sb          $zero, 0x1($t3)
    MEM_B(0X1, ctx->r11) = 0;
L_8018E1EC:
    // 0x8018E1EC: addiu       $t5, $t4, -0x1900
    ctx->r13 = ADD32(ctx->r12, -0X1900);
    // 0x8018E1F0: jal         0x80007024
    // 0x8018E1F4: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E1F4: sw          $t5, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r13;
    after_0:
    // 0x8018E1F8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8018E1FC: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018E200: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E204: addiu       $t7, $t7, -0x1820
    ctx->r15 = ADD32(ctx->r15, -0X1820);
    // 0x8018E208: addiu       $t6, $t6, 0x2A00
    ctx->r14 = ADD32(ctx->r14, 0X2A00);
    // 0x8018E20C: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E210: addiu       $a0, $a0, -0x1C0C
    ctx->r4 = ADD32(ctx->r4, -0X1C0C);
    // 0x8018E214: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8018E218: addiu       $t9, $t9, -0x2DD8
    ctx->r25 = ADD32(ctx->r25, -0X2DD8);
    // 0x8018E21C: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x8018E220: jal         0x800A2698
    // 0x8018E224: sw          $t9, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r25;
    scManagerFuncUpdate(rdram, ctx);
        goto after_1;
    // 0x8018E224: sw          $t9, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r25;
    after_1:
    // 0x8018E228: jal         0x80020A74
    // 0x8018E22C: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_2;
    // 0x8018E22C: nop

    after_2:
    // 0x8018E230: jal         0x80020D58
    // 0x8018E234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_3;
    // 0x8018E234: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_3:
    // 0x8018E238: beql        $v0, $zero, L_8018E254
    if (ctx->r2 == 0) {
        // 0x8018E23C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8018E254;
    }
    goto skip_0;
    // 0x8018E23C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_0:
L_8018E240:
    // 0x8018E240: jal         0x80020D58
    // 0x8018E244: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_4;
    // 0x8018E244: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x8018E248: bne         $v0, $zero, L_8018E240
    if (ctx->r2 != 0) {
        // 0x8018E24C: nop
    
            goto L_8018E240;
    }
    // 0x8018E24C: nop

    // 0x8018E250: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8018E254:
    // 0x8018E254: jal         0x80020B38
    // 0x8018E258: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_5;
    // 0x8018E258: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_5:
    // 0x8018E25C: jal         0x800266A0
    // 0x8018E260: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_6;
    // 0x8018E260: nop

    after_6:
    // 0x8018E264: jal         0x801157EC
    // 0x8018E268: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_7;
    // 0x8018E268: nop

    after_7:
    // 0x8018E26C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018E270: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018E274: lbu         $t0, 0x12($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X12);
    // 0x8018E278: bne         $t0, $zero, L_8018E304
    if (ctx->r8 != 0) {
        // 0x8018E27C: nop
    
            goto L_8018E304;
    }
    // 0x8018E27C: nop

    // 0x8018E280: jal         0x8018D5E0
    // 0x8018E284: nop

    scVSBattleSetScoreCheckSuddenDeath(rdram, ctx);
        goto after_8;
    // 0x8018E284: nop

    after_8:
    // 0x8018E288: beq         $v0, $zero, L_8018E304
    if (ctx->r2 == 0) {
        // 0x8018E28C: lui         $a0, 0x8019
        ctx->r4 = S32(0X8019 << 16);
            goto L_8018E304;
    }
    // 0x8018E28C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E290: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018E294: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x8018E298: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018E29C: addiu       $t1, $t1, 0x4EF8
    ctx->r9 = ADD32(ctx->r9, 0X4EF8);
    // 0x8018E2A0: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x8018E2A4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018E2A8: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018E2AC: addiu       $a0, $a0, -0x1C0C
    ctx->r4 = ADD32(ctx->r4, -0X1C0C);
    // 0x8018E2B0: sb          $t2, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r10;
    // 0x8018E2B4: addiu       $t4, $t4, -0x21E0
    ctx->r12 = ADD32(ctx->r12, -0X21E0);
    // 0x8018E2B8: jal         0x800A2698
    // 0x8018E2BC: sw          $t4, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r12;
    scManagerFuncUpdate(rdram, ctx);
        goto after_9;
    // 0x8018E2BC: sw          $t4, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->r12;
    after_9:
    // 0x8018E2C0: jal         0x80020A74
    // 0x8018E2C4: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_10;
    // 0x8018E2C4: nop

    after_10:
    // 0x8018E2C8: jal         0x80020D58
    // 0x8018E2CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_11;
    // 0x8018E2CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x8018E2D0: beql        $v0, $zero, L_8018E2EC
    if (ctx->r2 == 0) {
        // 0x8018E2D4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8018E2EC;
    }
    goto skip_1;
    // 0x8018E2D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
L_8018E2D8:
    // 0x8018E2D8: jal         0x80020D58
    // 0x8018E2DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syAudioCheckBGMPlaying(rdram, ctx);
        goto after_12;
    // 0x8018E2DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x8018E2E0: bne         $v0, $zero, L_8018E2D8
    if (ctx->r2 != 0) {
        // 0x8018E2E4: nop
    
            goto L_8018E2D8;
    }
    // 0x8018E2E4: nop

    // 0x8018E2E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8018E2EC:
    // 0x8018E2EC: jal         0x80020B38
    // 0x8018E2F0: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    syAudioSetBGMVolume(rdram, ctx);
        goto after_13;
    // 0x8018E2F0: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
    after_13:
    // 0x8018E2F4: jal         0x800266A0
    // 0x8018E2F8: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_14;
    // 0x8018E2F8: nop

    after_14:
    // 0x8018E2FC: jal         0x801157EC
    // 0x8018E300: nop

    gmRumbleInitPlayers(rdram, ctx);
        goto after_15;
    // 0x8018E300: nop

    after_15:
L_8018E304:
    // 0x8018E304: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018E308: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E30C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018E310: lbu         $t5, 0x0($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X0);
    // 0x8018E314: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x8018E318: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x8018E31C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E320: jr          $ra
    // 0x8018E324: sb          $t5, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r13;
    return;
    // 0x8018E324: sb          $t5, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void mpCommonSetFighterAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DEEC8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800DEECC: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
    // 0x800DEED0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800DEED4: sw          $t6, 0x14C($a0)
    MEM_W(0X14C, ctx->r4) = ctx->r14;
    // 0x800DEED8: swc1        $f4, 0x24($t7)
    MEM_W(0X24, ctx->r15) = ctx->f4.u32l;
    // 0x800DEEDC: lw          $t8, 0x8E8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8E8);
    // 0x800DEEE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800DEEE4: lwc1        $f6, 0x24($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X24);
    // 0x800DEEE8: sb          $t9, 0x148($a0)
    MEM_B(0X148, ctx->r4) = ctx->r25;
    // 0x800DEEEC: jr          $ra
    // 0x800DEEF0: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x800DEEF0: swc1        $f6, 0x50($a0)
    MEM_W(0X50, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void wpPikachuThunderHeadProcDead(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016A7E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016A7EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016A7F0: jal         0x8016A640
    // 0x8016A7F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wpPikachuThunderHeadSetDestroy(rdram, ctx);
        goto after_0;
    // 0x8016A7F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8016A7F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016A7FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016A800: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016A804: jr          $ra
    // 0x8016A808: nop

    return;
    // 0x8016A808: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeSpotlight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137B04: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80137B08: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80137B0C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80137B10: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137B14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80137B18: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80137B1C: jal         0x80009968
    // 0x80137B20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80137B20: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80137B24: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80137B28: lw          $t6, -0x6938($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6938);
    // 0x80137B2C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80137B30: addiu       $t7, $t7, 0x568
    ctx->r15 = ADD32(ctx->r15, 0X568);
    // 0x80137B34: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80137B38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137B3C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80137B40: jal         0x8000F120
    // 0x80137B44: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80137B44: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80137B48: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80137B4C: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80137B50: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80137B54: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80137B58: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137B5C: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x80137B60: jal         0x80009DF4
    // 0x80137B64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80137B64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80137B68: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80137B6C: lw          $t9, -0x6938($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6938);
    // 0x80137B70: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80137B74: addiu       $t0, $t0, 0x408
    ctx->r8 = ADD32(ctx->r8, 0X408);
    // 0x80137B78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137B7C: jal         0x8000F8F4
    // 0x80137B80: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x80137B80: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x80137B84: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137B88: addiu       $a1, $a1, 0x7A2C
    ctx->r5 = ADD32(ctx->r5, 0X7A2C);
    // 0x80137B8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80137B90: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80137B94: jal         0x80008188
    // 0x80137B98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x80137B98: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x80137B9C: jal         0x8000DF34
    // 0x80137BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80137BA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80137BA4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137BA8: lwc1        $f4, -0x712C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X712C);
    // 0x80137BAC: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80137BB0: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137BB4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80137BB8: swc1        $f4, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f4.u32l;
    // 0x80137BBC: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80137BC0: lwc1        $f6, -0x7128($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7128);
    // 0x80137BC4: swc1        $f6, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f6.u32l;
    // 0x80137BC8: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80137BCC: swc1        $f8, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f8.u32l;
    // 0x80137BD0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80137BD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80137BD8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80137BDC: jr          $ra
    // 0x80137BE0: nop

    return;
    // 0x80137BE0: nop

;}
RECOMP_FUNC void ftLinkSpecialLwProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164484: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80164488: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8016448C: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80164490: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80164494: jal         0x800DDDA8
    // 0x80164498: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80164498: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8016449C: bnel        $v0, $zero, L_801644C8
    if (ctx->r2 != 0) {
        // 0x801644A0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801644C8;
    }
    goto skip_0;
    // 0x801644A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801644A4: jal         0x800DEEC8
    // 0x801644A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_1;
    // 0x801644A8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x801644AC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801644B0: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x801644B4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801644B8: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801644BC: jal         0x800E6F24
    // 0x801644C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x801644C0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x801644C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801644C8:
    // 0x801644C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801644CC: jr          $ra
    // 0x801644D0: nop

    return;
    // 0x801644D0: nop

;}
RECOMP_FUNC void func_ovl32_8013547C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013547C: jr          $ra
    // 0x80135480: nop

    return;
    // 0x80135480: nop

;}
RECOMP_FUNC void ftYoshiSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E4A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E4A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E4AC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E4B0: jal         0x800DDDDC
    // 0x8015E4B4: addiu       $a1, $a1, -0x1A14
    ctx->r5 = ADD32(ctx->r5, -0X1A14);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015E4B4: addiu       $a1, $a1, -0x1A14
    ctx->r5 = ADD32(ctx->r5, -0X1A14);
    after_0:
    // 0x8015E4B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E4BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E4C0: jr          $ra
    // 0x8015E4C4: nop

    return;
    // 0x8015E4C4: nop

;}
RECOMP_FUNC void mvOpeningRoomMakeCloseUpEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132738: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013273C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80132740: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80132744: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80132748: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8013274C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132750: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132754: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132758: jal         0x80009968
    // 0x8013275C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013275C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132760: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80132764: addiu       $s1, $s1, 0x50B0
    ctx->r17 = ADD32(ctx->r17, 0X50B0);
    // 0x80132768: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8013276C: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80132770: addiu       $t7, $t7, -0x20D8
    ctx->r15 = ADD32(ctx->r15, -0X20D8);
    // 0x80132774: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132778: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013277C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132780: jal         0x8000F120
    // 0x80132784: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80132784: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80132788: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8013278C: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x80132790: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80132794: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80132798: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8013279C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801327A0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x801327A4: jal         0x80009DF4
    // 0x801327A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x801327A8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x801327AC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x801327B0: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x801327B4: lui         $t3, 0x2
    ctx->r11 = S32(0X2 << 16);
    // 0x801327B8: addiu       $t3, $t3, -0x2360
    ctx->r11 = ADD32(ctx->r11, -0X2360);
    // 0x801327BC: swc1        $f20, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->f20.u32l;
    // 0x801327C0: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x801327C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801327C8: swc1        $f20, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f20.u32l;
    // 0x801327CC: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x801327D0: swc1        $f20, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->f20.u32l;
    // 0x801327D4: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x801327D8: jal         0x8000F8F4
    // 0x801327DC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x801327DC: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_3:
    // 0x801327E0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801327E4: lui         $t5, 0x2
    ctx->r13 = S32(0X2 << 16);
    // 0x801327E8: addiu       $t5, $t5, -0x2028
    ctx->r13 = ADD32(ctx->r13, -0X2028);
    // 0x801327EC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801327F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801327F4: jal         0x8000BE28
    // 0x801327F8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x801327F8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_4:
    // 0x801327FC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132800: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80132804: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80132808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013280C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132810: jal         0x80008188
    // 0x80132814: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80132814: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x80132818: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8013281C: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80132820: addiu       $t7, $t7, -0x1FF0
    ctx->r15 = ADD32(ctx->r15, -0X1FF0);
    // 0x80132824: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80132828: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013282C: jal         0x8000BD8C
    // 0x80132830: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddAnimJointAll(rdram, ctx);
        goto after_6;
    // 0x80132830: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_6:
    // 0x80132834: jal         0x8000DF34
    // 0x80132838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_7;
    // 0x80132838: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8013283C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132840: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132844: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80132848: jal         0x80009968
    // 0x8013284C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_8;
    // 0x8013284C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_8:
    // 0x80132850: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80132854: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x80132858: addiu       $t9, $t9, -0xD90
    ctx->r25 = ADD32(ctx->r25, -0XD90);
    // 0x8013285C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132860: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132864: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132868: jal         0x8000F120
    // 0x8013286C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_9;
    // 0x8013286C: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_9:
    // 0x80132870: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132874: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80132878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013287C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80132880: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80132884: jal         0x80009DF4
    // 0x80132888: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_10;
    // 0x80132888: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_10:
    // 0x8013288C: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80132890: lui         $t5, 0x2
    ctx->r13 = S32(0X2 << 16);
    // 0x80132894: addiu       $t5, $t5, -0xF08
    ctx->r13 = ADD32(ctx->r13, -0XF08);
    // 0x80132898: swc1        $f20, 0x1C($t1)
    MEM_W(0X1C, ctx->r9) = ctx->f20.u32l;
    // 0x8013289C: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x801328A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801328A4: swc1        $f20, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f20.u32l;
    // 0x801328A8: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x801328AC: swc1        $f20, 0x24($t3)
    MEM_W(0X24, ctx->r11) = ctx->f20.u32l;
    // 0x801328B0: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x801328B4: jal         0x8000F8F4
    // 0x801328B8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddMObjAll(rdram, ctx);
        goto after_11;
    // 0x801328B8: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_11:
    // 0x801328BC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x801328C0: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x801328C4: addiu       $t7, $t7, -0xD0C
    ctx->r15 = ADD32(ctx->r15, -0XD0C);
    // 0x801328C8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801328CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801328D0: jal         0x8000BE28
    // 0x801328D4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_12;
    // 0x801328D4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_12:
    // 0x801328D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801328DC: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x801328E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801328E4: jal         0x80008188
    // 0x801328E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_13;
    // 0x801328E8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_13:
    // 0x801328EC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x801328F0: lui         $t9, 0x2
    ctx->r25 = S32(0X2 << 16);
    // 0x801328F4: addiu       $t9, $t9, -0xCD0
    ctx->r25 = ADD32(ctx->r25, -0XCD0);
    // 0x801328F8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801328FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132900: jal         0x8000BD8C
    // 0x80132904: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    gcAddAnimJointAll(rdram, ctx);
        goto after_14;
    // 0x80132904: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_14:
    // 0x80132908: jal         0x8000DF34
    // 0x8013290C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_15;
    // 0x8013290C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
    // 0x80132910: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80132914: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80132918: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8013291C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80132920: jr          $ra
    // 0x80132924: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80132924: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnBackupClearFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132D34: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80132D38: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80132D3C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132D40: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132D44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132D48: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80132D4C: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80132D50: addiu       $t8, $t8, 0x30F0
    ctx->r24 = ADD32(ctx->r24, 0X30F0);
    // 0x80132D54: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x80132D58: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80132D5C: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80132D60: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x80132D64: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132D68: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x80132D6C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x80132D70: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80132D74: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80132D78: jal         0x800CDF78
    // 0x80132D7C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132D7C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x80132D80: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132D84: addiu       $a0, $a0, 0x2E80
    ctx->r4 = ADD32(ctx->r4, 0X2E80);
    // 0x80132D88: jal         0x800CDEEC
    // 0x80132D8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x80132D8C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_1:
    // 0x80132D90: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132D94: jal         0x80004980
    // 0x80132D98: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132D98: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80132D9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132DA0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132DA4: addiu       $a2, $a2, 0x31B0
    ctx->r6 = ADD32(ctx->r6, 0X31B0);
    // 0x80132DA8: addiu       $a0, $a0, 0x2E80
    ctx->r4 = ADD32(ctx->r4, 0X2E80);
    // 0x80132DAC: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80132DB0: jal         0x800CDE04
    // 0x80132DB4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x80132DB4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80132DB8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132DBC: addiu       $a1, $a1, 0x2B9C
    ctx->r5 = ADD32(ctx->r5, 0X2B9C);
    // 0x80132DC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132DC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132DC8: jal         0x80009968
    // 0x80132DCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80132DCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80132DD0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80132DD4: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80132DD8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132DDC: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80132DE0: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80132DE4: jal         0x8000B9FC
    // 0x80132DE8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x80132DE8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_5:
    // 0x80132DEC: jal         0x801324D0
    // 0x80132DF0: nop

    mnBackupClearInitVars(rdram, ctx);
        goto after_6;
    // 0x80132DF0: nop

    after_6:
    // 0x80132DF4: jal         0x80132430
    // 0x80132DF8: nop

    mnBackupClearMakeMainCamera(rdram, ctx);
        goto after_7;
    // 0x80132DF8: nop

    after_7:
    // 0x80132DFC: jal         0x80131BC8
    // 0x80132E00: nop

    mnBackupClearMakeHeaderSObjs(rdram, ctx);
        goto after_8;
    // 0x80132E00: nop

    after_8:
    // 0x80132E04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132E08: jal         0x80131B24
    // 0x80132E0C: lw          $a0, 0x30C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C0);
    mnBackupClearMakeUnused(rdram, ctx);
        goto after_9;
    // 0x80132E0C: lw          $a0, 0x30C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C0);
    after_9:
    // 0x80132E10: jal         0x80131D44
    // 0x80132E14: nop

    mnBackupClearSetOptionSpriteColors(rdram, ctx);
        goto after_10;
    // 0x80132E14: nop

    after_10:
    // 0x80132E18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132E1C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80132E20: jr          $ra
    // 0x80132E24: nop

    return;
    // 0x80132E24: nop

;}
RECOMP_FUNC void ftNessSpecialHiInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153FCC: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80153FD0: addiu       $v1, $zero, 0x1E
    ctx->r3 = ADD32(0, 0X1E);
    // 0x80153FD4: addiu       $t6, $zero, 0x19
    ctx->r14 = ADD32(0, 0X19);
    // 0x80153FD8: sw          $v1, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r3;
    // 0x80153FDC: sw          $v1, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r3;
    // 0x80153FE0: sw          $t6, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r14;
    // 0x80153FE4: sw          $zero, 0xADC($v0)
    MEM_W(0XADC, ctx->r2) = 0;
    // 0x80153FE8: jr          $ra
    // 0x80153FEC: sw          $zero, 0xAE0($v0)
    MEM_W(0XAE0, ctx->r2) = 0;
    return;
    // 0x80153FEC: sw          $zero, 0xAE0($v0)
    MEM_W(0XAE0, ctx->r2) = 0;
;}
RECOMP_FUNC void grBonus3MakeBumpers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B508: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8010B50C: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x8010B510: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8010B514: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010B518: lw          $v0, 0x13F0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X13F0);
    // 0x8010B51C: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x8010B520: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8010B524: addiu       $t6, $t6, 0x0
    ctx->r14 = ADD32(ctx->r14, 0X0);
    // 0x8010B528: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8010B52C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8010B530: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8010B534: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8010B538: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8010B53C: swc1        $f20, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f20.u32l;
    // 0x8010B540: swc1        $f20, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f20.u32l;
    // 0x8010B544: swc1        $f20, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f20.u32l;
    // 0x8010B548: addu        $s1, $v0, $t6
    ctx->r17 = ADD32(ctx->r2, ctx->r14);
    // 0x8010B54C: lw          $t8, 0x2C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X2C);
    // 0x8010B550: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8010B554: addiu       $t7, $t7, 0x110
    ctx->r15 = ADD32(ctx->r15, 0X110);
    // 0x8010B558: addiu       $s3, $zero, 0x12
    ctx->r19 = ADD32(0, 0X12);
    // 0x8010B55C: addu        $s2, $v0, $t7
    ctx->r18 = ADD32(ctx->r2, ctx->r15);
    // 0x8010B560: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8010B564: beq         $s3, $t8, L_8010B5CC
    if (ctx->r19 == ctx->r24) {
        // 0x8010B568: addiu       $s1, $s1, 0x2C
        ctx->r17 = ADD32(ctx->r17, 0X2C);
            goto L_8010B5CC;
    }
    // 0x8010B568: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x8010B56C: addiu       $s4, $sp, 0x4C
    ctx->r20 = ADD32(ctx->r29, 0X4C);
    // 0x8010B570: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
L_8010B574:
    // 0x8010B574: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8010B578: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010B57C: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x8010B580: addiu       $a2, $s1, 0x8
    ctx->r6 = ADD32(ctx->r17, 0X8);
    // 0x8010B584: jal         0x8016EA78
    // 0x8010B588: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_0;
    // 0x8010B588: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_0:
    // 0x8010B58C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8010B590: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8010B594: beql        $a1, $zero, L_8010B5BC
    if (ctx->r5 == 0) {
        // 0x8010B598: lw          $t0, 0x2C($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X2C);
            goto L_8010B5BC;
    }
    goto skip_0;
    // 0x8010B598: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    skip_0:
    // 0x8010B59C: beql        $v0, $zero, L_8010B5BC
    if (ctx->r2 == 0) {
        // 0x8010B5A0: lw          $t0, 0x2C($s1)
        ctx->r8 = MEM_W(ctx->r17, 0X2C);
            goto L_8010B5BC;
    }
    goto skip_1;
    // 0x8010B5A0: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    skip_1:
    // 0x8010B5A4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x8010B5A8: jal         0x8000BD1C
    // 0x8010B5AC: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_1;
    // 0x8010B5AC: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    after_1:
    // 0x8010B5B0: jal         0x8000DF34
    // 0x8010B5B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_2;
    // 0x8010B5B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8010B5B8: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
L_8010B5BC:
    // 0x8010B5BC: addiu       $s1, $s1, 0x2C
    ctx->r17 = ADD32(ctx->r17, 0X2C);
    // 0x8010B5C0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x8010B5C4: bnel        $s3, $t0, L_8010B574
    if (ctx->r19 != ctx->r8) {
        // 0x8010B5C8: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_8010B574;
    }
    goto skip_2;
    // 0x8010B5C8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    skip_2:
L_8010B5CC:
    // 0x8010B5CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8010B5D0: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x8010B5D4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8010B5D8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8010B5DC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8010B5E0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8010B5E4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8010B5E8: jr          $ra
    // 0x8010B5EC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8010B5EC: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void mnOptionLabelsProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132248: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8013224C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80132250: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132254: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013225C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132260: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80132264: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80132268: lui         $ra, 0xE700
    ctx->r31 = S32(0XE700 << 16);
    // 0x8013226C: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80132270: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132274: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132278: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x8013227C: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80132280: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80132284: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132288: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013228C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80132290: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132294: lui         $t7, 0xA078
    ctx->r15 = S32(0XA078 << 16);
    // 0x80132298: ori         $t7, $t7, 0x14E6
    ctx->r15 = ctx->r15 | 0X14E6;
    // 0x8013229C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x801322A0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x801322A4: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801322A8: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x801322AC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x801322B0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801322B4: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x801322B8: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x801322BC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801322C0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801322C4: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x801322C8: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x801322CC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x801322D0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801322D4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801322D8: lui         $t9, 0x50
    ctx->r25 = S32(0X50 << 16);
    // 0x801322DC: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x801322E0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x801322E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801322E8: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x801322EC: ori         $t9, $t9, 0x41C8
    ctx->r25 = ctx->r25 | 0X41C8;
    // 0x801322F0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x801322F4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x801322F8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801322FC: lui         $t8, 0x38
    ctx->r24 = S32(0X38 << 16);
    // 0x80132300: lui         $t7, 0xF64D
    ctx->r15 = S32(0XF64D << 16);
    // 0x80132304: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132308: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013230C: ori         $t7, $t7, 0x8398
    ctx->r15 = ctx->r15 | 0X8398;
    // 0x80132310: ori         $t8, $t8, 0x423C
    ctx->r24 = ctx->r24 | 0X423C;
    // 0x80132314: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132318: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8013231C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132320: lui         $t7, 0xE200
    ctx->r15 = S32(0XE200 << 16);
    // 0x80132324: lui         $t8, 0x55
    ctx->r24 = S32(0X55 << 16);
    // 0x80132328: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8013232C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132330: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80132334: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80132338: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8013233C: ori         $t8, $t8, 0x2078
    ctx->r24 = ctx->r24 | 0X2078;
    // 0x80132340: ori         $t7, $t7, 0x1C
    ctx->r15 = ctx->r15 | 0X1C;
    // 0x80132344: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80132348: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8013234C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80132350: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80132354: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132358: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x8013235C: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80132360: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80132364: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80132368: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8013236C: jal         0x800CCEAC
    // 0x80132370: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80132370: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_0:
    // 0x80132374: jal         0x800CCF00
    // 0x80132378: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x80132378: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013237C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132380: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132384: jr          $ra
    // 0x80132388: nop

    return;
    // 0x80132388: nop

;}
RECOMP_FUNC void itMapProcLRWallCheckFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173480: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80173484: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80173488: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8017348C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80173490: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80173494: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80173498: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8017349C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801734A0: jal         0x800DA294
    // 0x801734A4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpProcessCheckTestLWallCollision(rdram, ctx);
        goto after_0;
    // 0x801734A4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801734A8: beq         $v0, $zero, L_801734C0
    if (ctx->r2 == 0) {
        // 0x801734AC: nop
    
            goto L_801734C0;
    }
    // 0x801734AC: nop

    // 0x801734B0: jal         0x800DA658
    // 0x801734B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunLWallCollision(rdram, ctx);
        goto after_1;
    // 0x801734B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801734B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801734BC: sw          $t7, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r15;
L_801734C0:
    // 0x801734C0: jal         0x800DAAA8
    // 0x801734C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestRWallCollision(rdram, ctx);
        goto after_2;
    // 0x801734C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801734C8: beq         $v0, $zero, L_801734E0
    if (ctx->r2 == 0) {
        // 0x801734CC: nop
    
            goto L_801734E0;
    }
    // 0x801734CC: nop

    // 0x801734D0: jal         0x800DAE6C
    // 0x801734D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunRWallCollision(rdram, ctx);
        goto after_3;
    // 0x801734D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801734D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801734DC: sw          $t8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r24;
L_801734E0:
    // 0x801734E0: jal         0x800DB2BC
    // 0x801734E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestFloorCollisionNew(rdram, ctx);
        goto after_4;
    // 0x801734E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801734E8: beq         $v0, $zero, L_80173514
    if (ctx->r2 == 0) {
        // 0x801734EC: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80173514;
    }
    // 0x801734EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801734F0: lhu         $t9, 0x5A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X5A);
    // 0x801734F4: andi        $t0, $t9, 0x800
    ctx->r8 = ctx->r25 & 0X800;
    // 0x801734F8: beql        $t0, $zero, L_8017351C
    if (ctx->r8 == 0) {
        // 0x801734FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8017351C;
    }
    goto skip_0;
    // 0x801734FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80173500: jal         0x800D9F84
    // 0x80173504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_5;
    // 0x80173504: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80173508: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8017350C: b           L_80173518
    // 0x80173510: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
        goto L_80173518;
    // 0x80173510: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_80173514:
    // 0x80173514: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
L_80173518:
    // 0x80173518: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8017351C:
    // 0x8017351C: jal         0x800DB474
    // 0x80173520: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    mpProcessCheckTestFloorCollision(rdram, ctx);
        goto after_6;
    // 0x80173520: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80173524: beql        $v0, $zero, L_8017355C
    if (ctx->r2 == 0) {
        // 0x80173528: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8017355C;
    }
    goto skip_1;
    // 0x80173528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8017352C: jal         0x800DD59C
    // 0x80173530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetLandingFloor(rdram, ctx);
        goto after_7;
    // 0x80173530: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80173534: lhu         $t3, 0x5A($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X5A);
    // 0x80173538: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8017353C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80173540: andi        $t4, $t3, 0x800
    ctx->r12 = ctx->r11 & 0X800;
    // 0x80173544: beql        $t4, $zero, L_80173558
    if (ctx->r12 == 0) {
        // 0x80173548: sw          $zero, 0x64($s0)
        MEM_W(0X64, ctx->r16) = 0;
            goto L_80173558;
    }
    goto skip_2;
    // 0x80173548: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    skip_2:
    // 0x8017354C: jal         0x800D9F84
    // 0x80173550: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_8;
    // 0x80173550: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_8:
    // 0x80173554: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
L_80173558:
    // 0x80173558: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8017355C:
    // 0x8017355C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80173560: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80173564: jr          $ra
    // 0x80173568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80173568: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void gmCollisionGetFighterAttackItemDamagePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0AF8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0AFC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0B00: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0B04: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800F0B08: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800F0B0C: jal         0x800F0850
    // 0x800F0B10: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    gmCollisionGetFighterAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0B10: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800F0B14: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0B18: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800F0B1C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0B20: lw          $t6, 0x74($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X74);
    // 0x800F0B24: lwc1        $f6, 0x8($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800F0B28: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0B2C: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800F0B30: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800F0B34: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0B38: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800F0B3C: lw          $t7, 0x74($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X74);
    // 0x800F0B40: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800F0B44: lwc1        $f10, 0x20($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800F0B48: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F0B4C: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800F0B50: lw          $t8, 0x74($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X74);
    // 0x800F0B54: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800F0B58: lwc1        $f4, 0x24($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X24);
    // 0x800F0B5C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0B60: jal         0x800F0A48
    // 0x800F0B64: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_1;
    // 0x800F0B64: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800F0B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0B6C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0B70: jr          $ra
    // 0x800F0B74: nop

    return;
    // 0x800F0B74: nop

;}
RECOMP_FUNC void mvOpeningSectorFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013264C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80132650: addiu       $v1, $v1, 0x2A18
    ctx->r3 = ADD32(ctx->r3, 0X2A18);
    // 0x80132654: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80132658: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013265C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132660: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80132664: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x80132668: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8013266C: bne         $at, $zero, L_80132728
    if (ctx->r1 != 0) {
        // 0x80132670: sw          $t7, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r15;
            goto L_80132728;
    }
    // 0x80132670: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80132674: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132678: addiu       $a2, $a2, 0x2A40
    ctx->r6 = ADD32(ctx->r6, 0X2A40);
    // 0x8013267C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80132680: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80132684: beq         $v0, $zero, L_80132690
    if (ctx->r2 == 0) {
        // 0x80132688: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_80132690;
    }
    // 0x80132688: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8013268C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80132690:
    // 0x80132690: jal         0x80390A04
    // 0x80132694: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_0;
    // 0x80132694: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_0:
    // 0x80132698: beq         $v0, $zero, L_801326B4
    if (ctx->r2 == 0) {
        // 0x8013269C: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_801326B4;
    }
    // 0x8013269C: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x801326A0: jal         0x80390AC0
    // 0x801326A4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_1;
    // 0x801326A4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x801326A8: beq         $v0, $zero, L_801326B4
    if (ctx->r2 == 0) {
        // 0x801326AC: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801326B4;
    }
    // 0x801326AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801326B0: sw          $zero, 0x2A40($at)
    MEM_W(0X2A40, ctx->r1) = 0;
L_801326B4:
    // 0x801326B4: jal         0x8039076C
    // 0x801326B8: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_2;
    // 0x801326B8: ori         $a0, $zero, 0xD000
    ctx->r4 = 0 | 0XD000;
    after_2:
    // 0x801326BC: beq         $v0, $zero, L_801326DC
    if (ctx->r2 == 0) {
        // 0x801326C0: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_801326DC;
    }
    // 0x801326C0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801326C4: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x801326C8: lbu         $t0, 0x0($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X0);
    // 0x801326CC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801326D0: sb          $t1, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r9;
    // 0x801326D4: jal         0x80005C74
    // 0x801326D8: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x801326D8: sb          $t0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r8;
    after_3:
L_801326DC:
    // 0x801326DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801326E0: lw          $v0, 0x2A18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2A18);
    // 0x801326E4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x801326E8: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x801326EC: bne         $v0, $at, L_8013270C
    if (ctx->r2 != ctx->r1) {
        // 0x801326F0: addiu       $v1, $v1, 0x4AD0
        ctx->r3 = ADD32(ctx->r3, 0X4AD0);
            goto L_8013270C;
    }
    // 0x801326F0: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x801326F4: jal         0x801321E0
    // 0x801326F8: nop

    mvOpeningSectorMakeCockpit(rdram, ctx);
        goto after_4;
    // 0x801326F8: nop

    after_4:
    // 0x801326FC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80132700: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132704: lw          $v0, 0x2A18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2A18);
    // 0x80132708: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
L_8013270C:
    // 0x8013270C: addiu       $at, $zero, 0xA0
    ctx->r1 = ADD32(0, 0XA0);
    // 0x80132710: bne         $v0, $at, L_80132728
    if (ctx->r2 != ctx->r1) {
        // 0x80132714: addiu       $t3, $zero, 0x29
        ctx->r11 = ADD32(0, 0X29);
            goto L_80132728;
    }
    // 0x80132714: addiu       $t3, $zero, 0x29
    ctx->r11 = ADD32(0, 0X29);
    // 0x80132718: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x8013271C: sb          $t3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r11;
    // 0x80132720: jal         0x80005C74
    // 0x80132724: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_5;
    // 0x80132724: sb          $t2, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r10;
    after_5:
L_80132728:
    // 0x80132728: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013272C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132730: jr          $ra
    // 0x80132734: nop

    return;
    // 0x80132734: nop

;}
RECOMP_FUNC void mnVSResultsGetSpot(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133810: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80133814: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133818: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013381C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80133820: addiu       $t7, $t7, -0x6E78
    ctx->r15 = ADD32(ctx->r15, -0X6E78);
    // 0x80133824: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133828: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8013382C: addiu       $t6, $sp, 0x40
    ctx->r14 = ADD32(ctx->r29, 0X40);
    // 0x80133830: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133834: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133838: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8013383C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133840: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80133844: addiu       $t1, $t1, -0x6E68
    ctx->r9 = ADD32(ctx->r9, -0X6E68);
    // 0x80133848: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8013384C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133850: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80133854: addiu       $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
    // 0x80133858: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8013385C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80133860: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80133864: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80133868: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x8013386C: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80133870: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80133874: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80133878: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    // 0x8013387C: jal         0x80133718
    // 0x80133880: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    mnVSResultsGetPlayerCountAhead(rdram, ctx);
        goto after_0;
    // 0x80133880: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x80133884: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x80133888: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x8013388C: addiu       $t6, $t6, -0x6450
    ctx->r14 = ADD32(ctx->r14, -0X6450);
    // 0x80133890: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80133894: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    // 0x80133898: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8013389C: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x801338A0: jal         0x80133684
    // 0x801338A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    mnVSResultsGetPlayerCountPlace(rdram, ctx);
        goto after_1;
    // 0x801338A4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_1:
    // 0x801338A8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801338AC: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x801338B0: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801338B4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x801338B8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x801338BC: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x801338C0: addu        $t8, $sp, $t7
    ctx->r24 = ADD32(ctx->r29, ctx->r15);
    // 0x801338C4: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x801338C8: lw          $t8, 0x2C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2C);
    // 0x801338CC: addu        $t4, $t0, $t3
    ctx->r12 = ADD32(ctx->r8, ctx->r11);
    // 0x801338D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801338D4: addu        $t5, $sp, $t4
    ctx->r13 = ADD32(ctx->r29, ctx->r12);
    // 0x801338D8: lw          $t5, 0x40($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X40);
    // 0x801338DC: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x801338E0: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x801338E4: jr          $ra
    // 0x801338E8: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
    return;
    // 0x801338E8: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
;}
RECOMP_FUNC void mvOpeningYosterFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132108: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8013210C: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80132110: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132114: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80132118: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x8013211C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80132120: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80132124: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80132128: addiu       $t8, $t8, 0x2440
    ctx->r24 = ADD32(ctx->r24, 0X2440);
    // 0x8013212C: addiu       $t9, $zero, 0x30
    ctx->r25 = ADD32(0, 0X30);
    // 0x80132130: addiu       $t0, $t0, 0x25C0
    ctx->r8 = ADD32(ctx->r8, 0X25C0);
    // 0x80132134: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80132138: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8013213C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80132140: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132144: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    // 0x80132148: sw          $t7, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r15;
    // 0x8013214C: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x80132150: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80132154: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x80132158: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x8013215C: sw          $t0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r8;
    // 0x80132160: sw          $t1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r9;
    // 0x80132164: jal         0x800CDF78
    // 0x80132168: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x80132168: addiu       $a0, $sp, 0x3C
    ctx->r4 = ADD32(ctx->r29, 0X3C);
    after_0:
    // 0x8013216C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80132170: addiu       $s0, $s0, 0x2330
    ctx->r16 = ADD32(ctx->r16, 0X2330);
    // 0x80132174: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132178: jal         0x800CDEEC
    // 0x8013217C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x8013217C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x80132180: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132184: jal         0x80004980
    // 0x80132188: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80132188: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x8013218C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80132190: addiu       $a2, $a2, 0x25F8
    ctx->r6 = ADD32(ctx->r6, 0X25F8);
    // 0x80132194: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132198: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8013219C: jal         0x800CDE04
    // 0x801321A0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x801321A0: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x801321A4: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x801321A8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801321AC: addiu       $a1, $a1, 0x203C
    ctx->r5 = ADD32(ctx->r5, 0X203C);
    // 0x801321B0: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801321B4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801321B8: jal         0x80009968
    // 0x801321BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x801321BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x801321C0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801321C4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801321C8: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801321CC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801321D0: jal         0x8000B9FC
    // 0x801321D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x801321D4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x801321D8: jal         0x80115890
    // 0x801321DC: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x801321DC: nop

    after_6:
    // 0x801321E0: jal         0x80132030
    // 0x801321E4: nop

    mvOpeningYosterInitTotalTimeTics(rdram, ctx);
        goto after_7;
    // 0x801321E4: nop

    after_7:
    // 0x801321E8: jal         0x800FD300
    // 0x801321EC: nop

    efManagerInitEffects(rdram, ctx);
        goto after_8;
    // 0x801321EC: nop

    after_8:
    // 0x801321F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801321F4: jal         0x800D7194
    // 0x801321F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x801321F8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_9:
    // 0x801321FC: jal         0x800D786C
    // 0x80132200: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x80132200: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_10:
    // 0x80132204: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80132208: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x8013220C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80132210: addiu       $s1, $s1, 0xD9C
    ctx->r17 = ADD32(ctx->r17, 0XD9C);
    // 0x80132214: addiu       $s2, $s2, 0x2438
    ctx->r18 = ADD32(ctx->r18, 0X2438);
    // 0x80132218: addiu       $s0, $s0, 0x2428
    ctx->r16 = ADD32(ctx->r16, 0X2428);
L_8013221C:
    // 0x8013221C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80132220: jal         0x80004980
    // 0x80132224: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_11;
    // 0x80132224: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_11:
    // 0x80132228: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8013222C: bne         $s0, $s2, L_8013221C
    if (ctx->r16 != ctx->r18) {
        // 0x80132230: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_8013221C;
    }
    // 0x80132230: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80132234: jal         0x80131E84
    // 0x80132238: nop

    mvOpeningYosterMakeMainCamera(rdram, ctx);
        goto after_12;
    // 0x80132238: nop

    after_12:
    // 0x8013223C: jal         0x80131F90
    // 0x80132240: nop

    mvOpeningYosterMakeWallpaperCamera(rdram, ctx);
        goto after_13;
    // 0x80132240: nop

    after_13:
    // 0x80132244: jal         0x80131D38
    // 0x80132248: nop

    mvOpeningYosterMakeWallpaper(rdram, ctx);
        goto after_14;
    // 0x80132248: nop

    after_14:
    // 0x8013224C: jal         0x80131B58
    // 0x80132250: nop

    mvOpeningYosterMakeNest(rdram, ctx);
        goto after_15;
    // 0x80132250: nop

    after_15:
    // 0x80132254: jal         0x80131DB8
    // 0x80132258: nop

    mvOpeningYosterMakeGround(rdram, ctx);
        goto after_16;
    // 0x80132258: nop

    after_16:
    // 0x8013225C: jal         0x80131BEC
    // 0x80132260: nop

    mvOpeningYosterMakeFighters(rdram, ctx);
        goto after_17;
    // 0x80132260: nop

    after_17:
    // 0x80132264: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x80132268: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8013226C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80132270: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132274: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80132278: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8013227C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80132280: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80132284: jal         0x803904E0
    // 0x80132288: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_18;
    // 0x80132288: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_18:
    // 0x8013228C: jal         0x8000092C
    // 0x80132290: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_19;
    // 0x80132290: nop

    after_19:
    // 0x80132294: sltiu       $at, $v0, 0xC9E
    ctx->r1 = ctx->r2 < 0XC9E ? 1 : 0;
    // 0x80132298: beql        $at, $zero, L_801322B8
    if (ctx->r1 == 0) {
        // 0x8013229C: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801322B8;
    }
    goto skip_0;
    // 0x8013229C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
L_801322A0:
    // 0x801322A0: jal         0x8000092C
    // 0x801322A4: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x801322A4: nop

    after_20:
    // 0x801322A8: sltiu       $at, $v0, 0xC9E
    ctx->r1 = ctx->r2 < 0XC9E ? 1 : 0;
    // 0x801322AC: bne         $at, $zero, L_801322A0
    if (ctx->r1 != 0) {
        // 0x801322B0: nop
    
            goto L_801322A0;
    }
    // 0x801322B0: nop

    // 0x801322B4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801322B8:
    // 0x801322B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801322BC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x801322C0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x801322C4: jr          $ra
    // 0x801322C8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x801322C8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void grYosterCloudVaporMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80108550: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80108554: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80108558: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010855C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80108560: lw          $a0, 0x1454($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1454);
    // 0x80108564: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80108568: jal         0x800D35DC
    // 0x8010856C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleMakeGenerator(rdram, ctx);
        goto after_0;
    // 0x8010856C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80108570: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80108574: beq         $v0, $zero, L_80108594
    if (ctx->r2 == 0) {
        // 0x80108578: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80108594;
    }
    // 0x80108578: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010857C: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x80108580: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x80108584: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x80108588: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x8010858C: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x80108590: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
L_80108594:
    // 0x80108594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80108598: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010859C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801085A0: jr          $ra
    // 0x801085A4: nop

    return;
    // 0x801085A4: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingMakePortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323D8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x801323DC: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801323E0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801323E4: addiu       $t7, $t7, -0x7EDC
    ctx->r15 = ADD32(ctx->r15, -0X7EDC);
    // 0x801323E8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801323EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801323F0: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x801323F4: addiu       $t6, $sp, 0x34
    ctx->r14 = ADD32(ctx->r29, 0X34);
L_801323F8:
    // 0x801323F8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801323FC: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132400: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132404: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132408: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x8013240C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132410: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132414: bne         $t7, $t0, L_801323F8
    if (ctx->r15 != ctx->r8) {
        // 0x80132418: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_801323F8;
    }
    // 0x80132418: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x8013241C: jal         0x80131FD0
    // 0x80132420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingGetFighterKind(rdram, ctx);
        goto after_0;
    // 0x80132420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80132424: jal         0x80131EFC
    // 0x80132428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PTrainingCheckFighterLocked(rdram, ctx);
        goto after_1;
    // 0x80132428: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8013242C: beq         $v0, $zero, L_80132444
    if (ctx->r2 == 0) {
        // 0x80132430: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80132444;
    }
    // 0x80132430: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132434: jal         0x80132130
    // 0x80132438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingMakePortraitShadow(rdram, ctx);
        goto after_2;
    // 0x80132438: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013243C: b           L_80132584
    // 0x80132440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80132584;
    // 0x80132440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132444:
    // 0x80132444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132448: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x8013244C: jal         0x80009968
    // 0x80132450: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_3;
    // 0x80132450: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80132454: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132458: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013245C: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80132460: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80132464: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x80132468: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8013246C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132470: addiu       $a2, $zero, 0x24
    ctx->r6 = ADD32(0, 0X24);
    // 0x80132474: jal         0x80009DF4
    // 0x80132478: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_4;
    // 0x80132478: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x8013247C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x80132480: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132484: addiu       $a1, $a1, 0x1D90
    ctx->r5 = ADD32(ctx->r5, 0X1D90);
    // 0x80132488: sw          $s0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r16;
    // 0x8013248C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80132490: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132494: jal         0x80008188
    // 0x80132498: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_5;
    // 0x80132498: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_5:
    // 0x8013249C: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801324A0: lw          $t2, -0x7350($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7350);
    // 0x801324A4: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x801324A8: addiu       $t3, $t3, 0x24D0
    ctx->r11 = ADD32(ctx->r11, 0X24D0);
    // 0x801324AC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x801324B0: jal         0x800CCFDC
    // 0x801324B4: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_6;
    // 0x801324B4: addu        $a1, $t2, $t3
    ctx->r5 = ADD32(ctx->r10, ctx->r11);
    after_6:
    // 0x801324B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801324BC: jal         0x80131E0C
    // 0x801324C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PTrainingSetPortraitWallpaperPosition(rdram, ctx);
        goto after_7;
    // 0x801324C0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x801324C4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801324C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801324CC: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x801324D0: jal         0x80009968
    // 0x801324D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_8;
    // 0x801324D4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_8:
    // 0x801324D8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x801324DC: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x801324E0: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x801324E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801324E8: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x801324EC: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x801324F0: jal         0x80009DF4
    // 0x801324F4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_9;
    // 0x801324F4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_9:
    // 0x801324F8: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x801324FC: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80132500: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132504: jal         0x80008188
    // 0x80132508: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_10;
    // 0x80132508: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x8013250C: jal         0x80131FD0
    // 0x80132510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PTrainingGetFighterKind(rdram, ctx);
        goto after_11;
    // 0x80132510: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_11:
    // 0x80132514: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x80132518: addu        $t0, $sp, $t5
    ctx->r8 = ADD32(ctx->r29, ctx->r13);
    // 0x8013251C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132520: lw          $t7, -0x7350($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X7350);
    // 0x80132524: lw          $t0, 0x34($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X34);
    // 0x80132528: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8013252C: jal         0x800CCFDC
    // 0x80132530: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_12;
    // 0x80132530: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    after_12:
    // 0x80132534: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80132538: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x8013253C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132540: andi        $t9, $t6, 0xFFDF
    ctx->r25 = ctx->r14 & 0XFFDF;
    // 0x80132544: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132548: ori         $t1, $t9, 0x1
    ctx->r9 = ctx->r25 | 0X1;
    // 0x8013254C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132550: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80132554: jal         0x80131FD0
    // 0x80132558: sw          $s0, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r16;
    mnPlayers1PTrainingGetFighterKind(rdram, ctx);
        goto after_13;
    // 0x80132558: sw          $s0, 0x84($t2)
    MEM_W(0X84, ctx->r10) = ctx->r16;
    after_13:
    // 0x8013255C: jal         0x80131D84
    // 0x80132560: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PTrainingCheckFighterCrossed(rdram, ctx);
        goto after_14;
    // 0x80132560: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_14:
    // 0x80132564: beq         $v0, $zero, L_80132574
    if (ctx->r2 == 0) {
        // 0x80132568: lw          $a0, 0x6C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X6C);
            goto L_80132574;
    }
    // 0x80132568: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x8013256C: jal         0x80131E68
    // 0x80132570: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PTrainingPortraitAddCross(rdram, ctx);
        goto after_15;
    // 0x80132570: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_15:
L_80132574:
    // 0x80132574: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80132578: jal         0x80131E0C
    // 0x8013257C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnPlayers1PTrainingSetPortraitWallpaperPosition(rdram, ctx);
        goto after_16;
    // 0x8013257C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_16:
    // 0x80132580: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80132584:
    // 0x80132584: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132588: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    // 0x8013258C: jr          $ra
    // 0x80132590: nop

    return;
    // 0x80132590: nop

;}
RECOMP_FUNC void itSpearMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180218: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8018021C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80180220: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x80180224: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80180228: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x8018022C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80180230: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80180234: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80180238: addiu       $a1, $a1, -0x5200
    ctx->r5 = ADD32(ctx->r5, -0X5200);
    // 0x8018023C: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x80180240: jal         0x8016E174
    // 0x80180244: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80180244: sw          $s0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r16;
    after_0:
    // 0x80180248: beq         $v0, $zero, L_80180340
    if (ctx->r2 == 0) {
        // 0x8018024C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80180340;
    }
    // 0x8018024C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80180250: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80180254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80180258: jal         0x8017279C
    // 0x8018025C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x8018025C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80180260: lw          $a3, 0x74($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X74);
    // 0x80180264: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80180268: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018026C: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x80180270: jal         0x80008CC0
    // 0x80180274: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80180274: sw          $a3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r7;
    after_2:
    // 0x80180278: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x8018027C: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80180280: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80180284: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80180288: sw          $t8, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r24;
    // 0x8018028C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80180290: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80180294: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80180298: jal         0x80018994
    // 0x8018029C: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x8018029C: sw          $t8, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r24;
    after_3:
    // 0x801802A0: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x801802A4: bne         $v0, $zero, L_801802C8
    if (ctx->r2 != 0) {
        // 0x801802A8: lw          $a3, 0x30($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X30);
            goto L_801802C8;
    }
    // 0x801802A8: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801802AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801802B0: lwc1        $f4, -0x3180($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3180);
    // 0x801802B4: lw          $t9, 0x10($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X10);
    // 0x801802B8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801802BC: swc1        $f4, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f4.u32l;
    // 0x801802C0: b           L_801802D0
    // 0x801802C4: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
        goto L_801802D0;
    // 0x801802C4: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
L_801802C8:
    // 0x801802C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801802CC: sw          $t1, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r9;
L_801802D0:
    // 0x801802D0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801802D4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x801802D8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801802DC: lw          $t4, 0x2D4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X2D4);
    // 0x801802E0: addiu       $t2, $zero, 0x16
    ctx->r10 = ADD32(0, 0X16);
    // 0x801802E4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x801802E8: sh          $t2, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r10;
    // 0x801802EC: sb          $t3, 0x154($v1)
    MEM_B(0X154, ctx->r3) = ctx->r11;
    // 0x801802F0: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x801802F4: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x801802F8: swc1        $f6, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f6.u32l;
    // 0x801802FC: lh          $t5, 0x2E($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X2E);
    // 0x80180300: lwc1        $f8, 0x20($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80180304: lui         $t8, 0x1
    ctx->r24 = S32(0X1 << 16);
    // 0x80180308: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8018030C: addiu       $t8, $t8, -0x20C8
    ctx->r24 = ADD32(ctx->r24, -0X20C8);
    // 0x80180310: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x80180314: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80180318: addiu       $t0, $t0, 0x3624
    ctx->r8 = ADD32(ctx->r8, 0X3624);
    // 0x8018031C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80180320: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x80180324: sub.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80180328: swc1        $f18, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f18.u32l;
    // 0x8018032C: lw          $t6, 0x2D4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X2D4);
    // 0x80180330: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80180334: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x80180338: jal         0x8000BD1C
    // 0x8018033C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_4;
    // 0x8018033C: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_4:
L_80180340:
    // 0x80180340: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80180344: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80180348: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018034C: jr          $ra
    // 0x80180350: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80180350: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void sc1PBonusStageInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D0F0: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D0F4: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8018D0F8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D0FC: addiu       $a1, $a1, 0x4AD0
    ctx->r5 = ADD32(ctx->r5, 0X4AD0);
    // 0x8018D100: addiu       $v1, $v1, -0xE50
    ctx->r3 = ADD32(ctx->r3, -0XE50);
    // 0x8018D104: lui         $a2, 0x800A
    ctx->r6 = S32(0X800A << 16);
    // 0x8018D108: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018D10C: addiu       $a2, $a2, 0x50E8
    ctx->r6 = ADD32(ctx->r6, 0X50E8);
    // 0x8018D110: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8018D114: addiu       $t0, $zero, 0x34
    ctx->r8 = ADD32(0, 0X34);
    // 0x8018D118: sb          $zero, 0x12($a1)
    MEM_B(0X12, ctx->r5) = 0;
    // 0x8018D11C: addiu       $t2, $t6, 0x1EC
    ctx->r10 = ADD32(ctx->r14, 0X1EC);
    // 0x8018D120: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8018D124:
    // 0x8018D124: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D128: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018D12C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018D130: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018D134: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018D138: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018D13C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018D140: bne         $t6, $t2, L_8018D124
    if (ctx->r14 != ctx->r10) {
        // 0x8018D144: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018D124;
    }
    // 0x8018D144: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018D148: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D14C: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x8018D150: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8018D154: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018D158: lbu         $t2, 0x1D($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X1D);
    // 0x8018D15C: lbu         $t3, 0x1($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X1);
    // 0x8018D160: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8018D164: andi        $t6, $t2, 0xFF7F
    ctx->r14 = ctx->r10 & 0XFF7F;
    // 0x8018D168: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8018D16C: sb          $a3, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r7;
    // 0x8018D170: sb          $t4, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r12;
    // 0x8018D174: sb          $t6, 0x1D($v1)
    MEM_B(0X1D, ctx->r3) = ctx->r14;
    // 0x8018D178: sb          $t9, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r25;
    // 0x8018D17C: bne         $t0, $t3, L_8018D1F0
    if (ctx->r8 != ctx->r11) {
        // 0x8018D180: sb          $zero, 0x5($v1)
        MEM_B(0X5, ctx->r3) = 0;
            goto L_8018D1F0;
    }
    // 0x8018D180: sb          $zero, 0x5($v1)
    MEM_B(0X5, ctx->r3) = 0;
    // 0x8018D184: lbu         $v0, 0x14($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X14);
    // 0x8018D188: addiu       $t4, $zero, 0x64
    ctx->r12 = ADD32(0, 0X64);
    // 0x8018D18C: sb          $t4, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r12;
    // 0x8018D190: lbu         $t2, 0x17($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X17);
    // 0x8018D194: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8018D198: bnel        $t2, $at, L_8018D1CC
    if (ctx->r10 != ctx->r1) {
        // 0x8018D19C: lbu         $t3, 0x16($a1)
        ctx->r11 = MEM_BU(ctx->r5, 0X16);
            goto L_8018D1CC;
    }
    goto skip_0;
    // 0x8018D19C: lbu         $t3, 0x16($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X16);
    skip_0:
    // 0x8018D1A0: lbu         $t6, 0x16($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X16);
    // 0x8018D1A4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8018D1A8: beql        $t6, $at, L_8018D1BC
    if (ctx->r14 == ctx->r1) {
        // 0x8018D1AC: lw          $t8, 0x0($a2)
        ctx->r24 = MEM_W(ctx->r6, 0X0);
            goto L_8018D1BC;
    }
    goto skip_1;
    // 0x8018D1AC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    skip_1:
    // 0x8018D1B0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8018D1B4: sb          $a3, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r7;
    // 0x8018D1B8: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
L_8018D1BC:
    // 0x8018D1BC: addiu       $t7, $v0, 0x11
    ctx->r15 = ADD32(ctx->r2, 0X11);
    // 0x8018D1C0: b           L_8018D22C
    // 0x8018D1C4: sb          $t7, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r15;
        goto L_8018D22C;
    // 0x8018D1C4: sb          $t7, 0x1($t8)
    MEM_B(0X1, ctx->r24) = ctx->r15;
    // 0x8018D1C8: lbu         $t3, 0x16($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X16);
L_8018D1CC:
    // 0x8018D1CC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x8018D1D0: beql        $t3, $at, L_8018D1E4
    if (ctx->r11 == ctx->r1) {
        // 0x8018D1D4: lw          $t2, 0x0($a2)
        ctx->r10 = MEM_W(ctx->r6, 0X0);
            goto L_8018D1E4;
    }
    goto skip_2;
    // 0x8018D1D4: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    skip_2:
    // 0x8018D1D8: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x8018D1DC: sb          $a3, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r7;
    // 0x8018D1E0: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
L_8018D1E4:
    // 0x8018D1E4: addiu       $t5, $v0, 0x1D
    ctx->r13 = ADD32(ctx->r2, 0X1D);
    // 0x8018D1E8: b           L_8018D22C
    // 0x8018D1EC: sb          $t5, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r13;
        goto L_8018D22C;
    // 0x8018D1EC: sb          $t5, 0x1($t2)
    MEM_B(0X1, ctx->r10) = ctx->r13;
L_8018D1F0:
    // 0x8018D1F0: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x8018D1F4: lbu         $v0, 0x39($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X39);
    // 0x8018D1F8: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8018D1FC: sb          $t6, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r14;
    // 0x8018D200: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x8018D204: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x8018D208: bnel        $t7, $at, L_8018D224
    if (ctx->r15 != ctx->r1) {
        // 0x8018D20C: lw          $t5, 0x0($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X0);
            goto L_8018D224;
    }
    goto skip_3;
    // 0x8018D20C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    skip_3:
    // 0x8018D210: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x8018D214: addiu       $t8, $v0, 0x11
    ctx->r24 = ADD32(ctx->r2, 0X11);
    // 0x8018D218: b           L_8018D22C
    // 0x8018D21C: sb          $t8, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r24;
        goto L_8018D22C;
    // 0x8018D21C: sb          $t8, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r24;
    // 0x8018D220: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
L_8018D224:
    // 0x8018D224: addiu       $t4, $v0, 0x1D
    ctx->r12 = ADD32(ctx->r2, 0X1D);
    // 0x8018D228: sb          $t4, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r12;
L_8018D22C:
    // 0x8018D22C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018D230: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_8018D234:
    // 0x8018D234: lbu         $t2, 0x13($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X13);
    // 0x8018D238: bnel        $v1, $t2, L_8018D29C
    if (ctx->r3 != ctx->r10) {
        // 0x8018D23C: lw          $t5, 0x0($a2)
        ctx->r13 = MEM_W(ctx->r6, 0X0);
            goto L_8018D29C;
    }
    goto skip_4;
    // 0x8018D23C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    skip_4:
    // 0x8018D240: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8018D244: addu        $t9, $t6, $a0
    ctx->r25 = ADD32(ctx->r14, ctx->r4);
    // 0x8018D248: sb          $zero, 0x22($t9)
    MEM_B(0X22, ctx->r25) = 0;
    // 0x8018D24C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8018D250: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8018D254: sb          $v0, 0x23($t8)
    MEM_B(0X23, ctx->r24) = ctx->r2;
    // 0x8018D258: lbu         $t3, 0x1($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X1);
    // 0x8018D25C: bnel        $t0, $t3, L_8018D27C
    if (ctx->r8 != ctx->r11) {
        // 0x8018D260: lw          $t9, 0x0($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X0);
            goto L_8018D27C;
    }
    goto skip_5;
    // 0x8018D260: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    skip_5:
    // 0x8018D264: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8018D268: lbu         $t4, 0x15($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X15);
    // 0x8018D26C: addu        $t2, $t5, $a0
    ctx->r10 = ADD32(ctx->r13, ctx->r4);
    // 0x8018D270: b           L_8018D288
    // 0x8018D274: sb          $t4, 0x26($t2)
    MEM_B(0X26, ctx->r10) = ctx->r12;
        goto L_8018D288;
    // 0x8018D274: sb          $t4, 0x26($t2)
    MEM_B(0X26, ctx->r10) = ctx->r12;
    // 0x8018D278: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
L_8018D27C:
    // 0x8018D27C: lbu         $t6, 0x3A($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3A);
    // 0x8018D280: addu        $t7, $t9, $a0
    ctx->r15 = ADD32(ctx->r25, ctx->r4);
    // 0x8018D284: sb          $t6, 0x26($t7)
    MEM_B(0X26, ctx->r15) = ctx->r14;
L_8018D288:
    // 0x8018D288: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8018D28C: addu        $t3, $t8, $a0
    ctx->r11 = ADD32(ctx->r24, ctx->r4);
    // 0x8018D290: b           L_8018D2A4
    // 0x8018D294: sb          $v1, 0x28($t3)
    MEM_B(0X28, ctx->r11) = ctx->r3;
        goto L_8018D2A4;
    // 0x8018D294: sb          $v1, 0x28($t3)
    MEM_B(0X28, ctx->r11) = ctx->r3;
    // 0x8018D298: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
L_8018D29C:
    // 0x8018D29C: addu        $t4, $t5, $a0
    ctx->r12 = ADD32(ctx->r13, ctx->r4);
    // 0x8018D2A0: sb          $a3, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r7;
L_8018D2A4:
    // 0x8018D2A4: lbu         $t9, 0x13($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X13);
    // 0x8018D2A8: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8018D2AC: bnel        $t2, $t9, L_8018D314
    if (ctx->r10 != ctx->r25) {
        // 0x8018D2B0: lw          $t4, 0x0($a2)
        ctx->r12 = MEM_W(ctx->r6, 0X0);
            goto L_8018D314;
    }
    goto skip_6;
    // 0x8018D2B0: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    skip_6:
    // 0x8018D2B4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x8018D2B8: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8018D2BC: sb          $zero, 0x96($t7)
    MEM_B(0X96, ctx->r15) = 0;
    // 0x8018D2C0: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x8018D2C4: addu        $t3, $t8, $a0
    ctx->r11 = ADD32(ctx->r24, ctx->r4);
    // 0x8018D2C8: sb          $v0, 0x97($t3)
    MEM_B(0X97, ctx->r11) = ctx->r2;
    // 0x8018D2CC: lbu         $t5, 0x1($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X1);
    // 0x8018D2D0: bnel        $t0, $t5, L_8018D2F0
    if (ctx->r8 != ctx->r13) {
        // 0x8018D2D4: lw          $t7, 0x0($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X0);
            goto L_8018D2F0;
    }
    goto skip_7;
    // 0x8018D2D4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    skip_7:
    // 0x8018D2D8: lw          $t2, 0x0($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X0);
    // 0x8018D2DC: lbu         $t4, 0x15($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X15);
    // 0x8018D2E0: addu        $t9, $t2, $a0
    ctx->r25 = ADD32(ctx->r10, ctx->r4);
    // 0x8018D2E4: b           L_8018D2FC
    // 0x8018D2E8: sb          $t4, 0x9A($t9)
    MEM_B(0X9A, ctx->r25) = ctx->r12;
        goto L_8018D2FC;
    // 0x8018D2E8: sb          $t4, 0x9A($t9)
    MEM_B(0X9A, ctx->r25) = ctx->r12;
    // 0x8018D2EC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
L_8018D2F0:
    // 0x8018D2F0: lbu         $t6, 0x3A($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X3A);
    // 0x8018D2F4: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x8018D2F8: sb          $t6, 0x9A($t8)
    MEM_B(0X9A, ctx->r24) = ctx->r14;
L_8018D2FC:
    // 0x8018D2FC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x8018D300: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x8018D304: addu        $t2, $t5, $a0
    ctx->r10 = ADD32(ctx->r13, ctx->r4);
    // 0x8018D308: b           L_8018D31C
    // 0x8018D30C: sb          $t3, 0x9C($t2)
    MEM_B(0X9C, ctx->r10) = ctx->r11;
        goto L_8018D31C;
    // 0x8018D30C: sb          $t3, 0x9C($t2)
    MEM_B(0X9C, ctx->r10) = ctx->r11;
    // 0x8018D310: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
L_8018D314:
    // 0x8018D314: addu        $t9, $t4, $a0
    ctx->r25 = ADD32(ctx->r12, ctx->r4);
    // 0x8018D318: sb          $a3, 0x96($t9)
    MEM_B(0X96, ctx->r25) = ctx->r7;
L_8018D31C:
    // 0x8018D31C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8018D320: bne         $v1, $t1, L_8018D234
    if (ctx->r3 != ctx->r9) {
        // 0x8018D324: addiu       $a0, $a0, 0xE8
        ctx->r4 = ADD32(ctx->r4, 0XE8);
            goto L_8018D234;
    }
    // 0x8018D324: addiu       $a0, $a0, 0xE8
    ctx->r4 = ADD32(ctx->r4, 0XE8);
    // 0x8018D328: jr          $ra
    // 0x8018D32C: nop

    return;
    // 0x8018D32C: nop

;}
RECOMP_FUNC void ftKirbySpecialNTurnProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801621CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801621D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801621D4: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801621D8: jal         0x800D9480
    // 0x801621DC: addiu       $a1, $a1, 0x2FA8
    ctx->r5 = ADD32(ctx->r5, 0X2FA8);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801621DC: addiu       $a1, $a1, 0x2FA8
    ctx->r5 = ADD32(ctx->r5, 0X2FA8);
    after_0:
    // 0x801621E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801621E4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801621E8: jr          $ra
    // 0x801621EC: nop

    return;
    // 0x801621EC: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueUnused0x80133990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133990: jr          $ra
    // 0x80133994: nop

    return;
    // 0x80133994: nop

;}
RECOMP_FUNC void dbBattleSetDemoFighterKinds(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E38: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131E3C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80131E40: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80131E44: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x80131E48: lhu         $s1, 0x4938($s1)
    ctx->r17 = MEM_HU(ctx->r17, 0X4938);
    // 0x80131E4C: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80131E50: addiu       $s0, $s0, 0x4AD0
    ctx->r16 = ADD32(ctx->r16, 0X4AD0);
    // 0x80131E54: lhu         $t6, 0xA($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0XA);
    // 0x80131E58: ori         $s1, $s1, 0x36F
    ctx->r17 = ctx->r17 | 0X36F;
    // 0x80131E5C: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x80131E60: bne         $t6, $s1, L_80131E6C
    if (ctx->r14 != ctx->r17) {
        // 0x80131E64: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_80131E6C;
    }
    // 0x80131E64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131E68: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
L_80131E6C:
    // 0x80131E6C: jal         0x80131D74
    // 0x80131E70: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    dbBattleGetFighterKindsNum(rdram, ctx);
        goto after_0;
    // 0x80131E70: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_0:
    // 0x80131E74: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131E78: jal         0x80131D74
    // 0x80131E7C: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    dbBattleGetFighterKindsNum(rdram, ctx);
        goto after_1;
    // 0x80131E7C: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    after_1:
    // 0x80131E80: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x80131E84: jal         0x80018994
    // 0x80131E88: subu        $a0, $t7, $v0
    ctx->r4 = SUB32(ctx->r15, ctx->r2);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x80131E88: subu        $a0, $t7, $v0
    ctx->r4 = SUB32(ctx->r15, ctx->r2);
    after_2:
    // 0x80131E8C: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80131E90: lhu         $a1, 0xA($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XA);
    // 0x80131E94: jal         0x80131DEC
    // 0x80131E98: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    dbBattleGetShuffledFighterKind(rdram, ctx);
        goto after_3;
    // 0x80131E98: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_3:
    // 0x80131E9C: lhu         $v1, 0xA($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0XA);
    // 0x80131EA0: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x80131EA4: bnel        $v1, $zero, L_80131EB4
    if (ctx->r3 != 0) {
        // 0x80131EA8: lbu         $t9, 0xD($s0)
        ctx->r25 = MEM_BU(ctx->r16, 0XD);
            goto L_80131EB4;
    }
    goto skip_0;
    // 0x80131EA8: lbu         $t9, 0xD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XD);
    skip_0:
    // 0x80131EAC: sb          $v0, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r2;
    // 0x80131EB0: lbu         $t9, 0xD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XD);
L_80131EB4:
    // 0x80131EB4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80131EB8: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80131EBC: sllv        $t1, $t0, $t9
    ctx->r9 = S32(ctx->r8 << (ctx->r25 & 31));
    // 0x80131EC0: or          $t2, $v1, $t1
    ctx->r10 = ctx->r3 | ctx->r9;
    // 0x80131EC4: jal         0x80131D74
    // 0x80131EC8: sh          $t2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r10;
    dbBattleGetFighterKindsNum(rdram, ctx);
        goto after_4;
    // 0x80131EC8: sh          $t2, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r10;
    after_4:
    // 0x80131ECC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131ED0: jal         0x80131D74
    // 0x80131ED4: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    dbBattleGetFighterKindsNum(rdram, ctx);
        goto after_5;
    // 0x80131ED4: lhu         $a0, 0xA($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0XA);
    after_5:
    // 0x80131ED8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80131EDC: subu        $a0, $t3, $v0
    ctx->r4 = SUB32(ctx->r11, ctx->r2);
    // 0x80131EE0: bne         $a0, $zero, L_80131EF4
    if (ctx->r4 != 0) {
        // 0x80131EE4: nop
    
            goto L_80131EF4;
    }
    // 0x80131EE4: nop

    // 0x80131EE8: lbu         $t4, 0xC($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XC);
    // 0x80131EEC: b           L_80131F28
    // 0x80131EF0: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
        goto L_80131F28;
    // 0x80131EF0: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
L_80131EF4:
    // 0x80131EF4: jal         0x80018994
    // 0x80131EF8: nop

    syUtilsRandIntRange(rdram, ctx);
        goto after_6;
    // 0x80131EF8: nop

    after_6:
    // 0x80131EFC: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x80131F00: lhu         $a1, 0xA($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0XA);
    // 0x80131F04: jal         0x80131DEC
    // 0x80131F08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    dbBattleGetShuffledFighterKind(rdram, ctx);
        goto after_7;
    // 0x80131F08: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_7:
    // 0x80131F0C: lhu         $t5, 0xA($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0XA);
    // 0x80131F10: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x80131F14: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80131F18: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x80131F1C: or          $t0, $t5, $t8
    ctx->r8 = ctx->r13 | ctx->r24;
    // 0x80131F20: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x80131F24: sh          $t0, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r8;
L_80131F28:
    // 0x80131F28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131F2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80131F30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80131F34: jr          $ra
    // 0x80131F38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131F38: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itMainSetFighterThrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80172B78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80172B7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80172B80: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80172B84: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80172B88: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80172B8C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80172B90: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80172B94: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80172B98: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80172B9C: lw          $v0, 0x8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8);
    // 0x80172BA0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80172BA4: lw          $t7, 0x84($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X84);
    // 0x80172BA8: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    // 0x80172BAC: lbu         $t8, 0x2CE($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2CE);
    // 0x80172BB0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80172BB4: andi        $t9, $t8, 0x1
    ctx->r25 = ctx->r24 & 0X1;
    // 0x80172BB8: bne         $t9, $at, L_80172BE0
    if (ctx->r25 != ctx->r1) {
        // 0x80172BBC: nop
    
            goto L_80172BE0;
    }
    // 0x80172BBC: nop

    // 0x80172BC0: beq         $a3, $zero, L_80172BFC
    if (ctx->r7 == 0) {
        // 0x80172BC4: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_80172BFC;
    }
    // 0x80172BC4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80172BC8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80172BCC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80172BD0: jal         0x800E806C
    // 0x80172BD4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    ftParamMakeRumble(rdram, ctx);
        goto after_0;
    // 0x80172BD4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80172BD8: b           L_80172BFC
    // 0x80172BDC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
        goto L_80172BFC;
    // 0x80172BDC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_80172BE0:
    // 0x80172BE0: beq         $t1, $zero, L_80172BF0
    if (ctx->r9 == 0) {
        // 0x80172BE4: addiu       $a1, $zero, 0x6
        ctx->r5 = ADD32(0, 0X6);
            goto L_80172BF0;
    }
    // 0x80172BE4: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80172BE8: b           L_80172BF0
    // 0x80172BEC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
        goto L_80172BF0;
    // 0x80172BEC: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
L_80172BF0:
    // 0x80172BF0: jal         0x800E806C
    // 0x80172BF4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    ftParamMakeRumble(rdram, ctx);
        goto after_1;
    // 0x80172BF4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80172BF8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
L_80172BFC:
    // 0x80172BFC: lw          $t2, 0xC($v1)
    ctx->r10 = MEM_W(ctx->r3, 0XC);
    // 0x80172C00: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80172C04: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80172C08: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80172C0C: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x80172C10: lw          $v0, -0x6A88($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6A88);
    // 0x80172C14: beql        $v0, $zero, L_80172C2C
    if (ctx->r2 == 0) {
        // 0x80172C18: lw          $t4, 0x24($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X24);
            goto L_80172C2C;
    }
    goto skip_0;
    // 0x80172C18: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80172C1C: jalr        $v0
    // 0x80172C20: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x80172C20: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x80172C24: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80172C28: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
L_80172C2C:
    // 0x80172C2C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80172C30: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80172C34: lhu         $t5, 0x290($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X290);
    // 0x80172C38: lhu         $a3, 0x28E($t4)
    ctx->r7 = MEM_HU(ctx->r12, 0X28E);
    // 0x80172C3C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80172C40: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x80172C44: jal         0x80172984
    // 0x80172C48: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    itMainSetFighterRelease(rdram, ctx);
        goto after_3;
    // 0x80172C48: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_3:
    // 0x80172C4C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80172C50: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80172C54: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x80172C58: jal         0x8010066C
    // 0x80172C5C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteScaleMakeEffect(rdram, ctx);
        goto after_4;
    // 0x80172C5C: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_4:
    // 0x80172C60: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80172C64: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80172C68: beql        $t7, $zero, L_80172C7C
    if (ctx->r15 == 0) {
        // 0x80172C6C: lhu         $a1, 0x2CA($v1)
        ctx->r5 = MEM_HU(ctx->r3, 0X2CA);
            goto L_80172C7C;
    }
    goto skip_1;
    // 0x80172C6C: lhu         $a1, 0x2CA($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2CA);
    skip_1:
    // 0x80172C70: b           L_80172C7C
    // 0x80172C74: lhu         $a1, 0x2CC($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2CC);
        goto L_80172C7C;
    // 0x80172C74: lhu         $a1, 0x2CC($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2CC);
    // 0x80172C78: lhu         $a1, 0x2CA($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X2CA);
L_80172C7C:
    // 0x80172C7C: jal         0x800269C0
    // 0x80172C80: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80172C80: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    after_5:
    // 0x80172C84: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80172C88: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80172C8C: jal         0x8017245C
    // 0x80172C90: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    itMainSetThrownSpin(rdram, ctx);
        goto after_6;
    // 0x80172C90: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    after_6:
    // 0x80172C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80172C98: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80172C9C: jr          $ra
    // 0x80172CA0: nop

    return;
    // 0x80172CA0: nop

;}
RECOMP_FUNC void sc1PTrainingModeMakeMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EE10: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018EE14: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018EE18: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018EE1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018EE20: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x8018EE24: jal         0x80009968
    // 0x8018EE28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018EE28: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018EE2C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018EE30: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018EE34: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018EE38: addiu       $a1, $a1, -0x12D4
    ctx->r5 = ADD32(ctx->r5, -0X12D4);
    // 0x8018EE3C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018EE40: addiu       $a2, $zero, 0x16
    ctx->r6 = ADD32(0, 0X16);
    // 0x8018EE44: jal         0x80009DF4
    // 0x8018EE48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018EE48: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018EE4C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018EE50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018EE54: jr          $ra
    // 0x8018EE58: nop

    return;
    // 0x8018EE58: nop

;}
RECOMP_FUNC void mnCongraFuncDraw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F60: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131F64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131F68: jal         0x8000A340
    // 0x80131F6C: nop

    gcDrawAll(rdram, ctx);
        goto after_0;
    // 0x80131F6C: nop

    after_0:
    // 0x80131F70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80131F74: addiu       $v0, $v0, 0x22F0
    ctx->r2 = ADD32(ctx->r2, 0X22F0);
    // 0x80131F78: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80131F7C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    // 0x80131F80: beq         $t6, $zero, L_80131FA0
    if (ctx->r14 == 0) {
        // 0x80131F84: nop
    
            goto L_80131FA0;
    }
    // 0x80131F84: nop

    // 0x80131F88: jal         0x80006E18
    // 0x80131F8C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    syVideoSetFlags(rdram, ctx);
        goto after_1;
    // 0x80131F8C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    after_1:
    // 0x80131F90: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131F94: addiu       $v1, $v1, 0x22E8
    ctx->r3 = ADD32(ctx->r3, 0X22E8);
    // 0x80131F98: addiu       $t7, $zero, 0x5
    ctx->r15 = ADD32(0, 0X5);
    // 0x80131F9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80131FA0:
    // 0x80131FA0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80131FA4: addiu       $v1, $v1, 0x22E8
    ctx->r3 = ADD32(ctx->r3, 0X22E8);
    // 0x80131FA8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131FAC: beq         $v0, $zero, L_80131FD8
    if (ctx->r2 == 0) {
        // 0x80131FB0: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_80131FD8;
    }
    // 0x80131FB0: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x80131FB4: bne         $t8, $zero, L_80131FD8
    if (ctx->r24 != 0) {
        // 0x80131FB8: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80131FD8;
    }
    // 0x80131FB8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131FBC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80131FC0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80131FC4: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80131FC8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80131FCC: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
    // 0x80131FD0: jal         0x80005C74
    // 0x80131FD4: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_2;
    // 0x80131FD4: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_2:
L_80131FD8:
    // 0x80131FD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131FDC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131FE0: jr          $ra
    // 0x80131FE4: nop

    return;
    // 0x80131FE4: nop

;}
RECOMP_FUNC void mnPlayers1PBonusSetCursorGrab(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134CC4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134CC8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80134CCC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80134CD0: addiu       $s0, $s0, 0x7648
    ctx->r16 = ADD32(ctx->r16, 0X7648);
    // 0x80134CD4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134CD8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80134CDC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80134CE0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80134CE4: sw          $a0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r4;
    // 0x80134CE8: sw          $zero, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = 0;
    // 0x80134CEC: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x80134CF0: sw          $a0, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r4;
    // 0x80134CF4: jal         0x8013476C
    // 0x80134CF8: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    mnPlayers1PBonusUpdateFighter(rdram, ctx);
        goto after_0;
    // 0x80134CF8: sw          $zero, 0x58($s0)
    MEM_W(0X58, ctx->r16) = 0;
    after_0:
    // 0x80134CFC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80134D00: jal         0x80134BB0
    // 0x80134D04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mnPlayers1PBonusUpdateCursorGrabPriorities(rdram, ctx);
        goto after_1;
    // 0x80134D04: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x80134D08: jal         0x80134C80
    // 0x80134D0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PBonusSetCursorPuckOffset(rdram, ctx);
        goto after_2;
    // 0x80134D0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80134D10: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80134D14: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80134D18: jal         0x80134364
    // 0x80134D1C: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    mnPlayers1PBonusUpdateCursor(rdram, ctx);
        goto after_3;
    // 0x80134D1C: lw          $a2, 0x28($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X28);
    after_3:
    // 0x80134D20: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80134D24: sw          $t7, 0x70($s0)
    MEM_W(0X70, ctx->r16) = ctx->r15;
    // 0x80134D28: jal         0x800269C0
    // 0x80134D2C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    func_800269C0_275C0(rdram, ctx);
        goto after_4;
    // 0x80134D2C: addiu       $a0, $zero, 0x7F
    ctx->r4 = ADD32(0, 0X7F);
    after_4:
    // 0x80134D30: jal         0x80134858
    // 0x80134D34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PBonusDestroyPortraitFlash(rdram, ctx);
        goto after_5;
    // 0x80134D34: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80134D38: jal         0x801347F8
    // 0x80134D3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mnPlayers1PBonusUpdateNameAndEmblem(rdram, ctx);
        goto after_6;
    // 0x80134D3C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80134D40: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80134D44: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80134D48: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80134D4C: jr          $ra
    // 0x80134D50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80134D50: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl29_80135BA4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135BA4: jr          $ra
    // 0x80135BA8: nop

    return;
    // 0x80135BA8: nop

;}

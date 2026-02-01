#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mvOpeningPikachuInitName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D160: lhu         $t6, 0x24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X24);
    // 0x8018D164: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8018D168: sb          $v0, 0x60($a0)
    MEM_B(0X60, ctx->r4) = ctx->r2;
    // 0x8018D16C: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x8018D170: sh          $t8, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r24;
    // 0x8018D174: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8018D178: sh          $t9, 0x24($a0)
    MEM_H(0X24, ctx->r4) = ctx->r25;
    // 0x8018D17C: sb          $v0, 0x61($a0)
    MEM_B(0X61, ctx->r4) = ctx->r2;
    // 0x8018D180: sb          $v0, 0x62($a0)
    MEM_B(0X62, ctx->r4) = ctx->r2;
    // 0x8018D184: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x8018D188: sb          $v0, 0x29($a0)
    MEM_B(0X29, ctx->r4) = ctx->r2;
    // 0x8018D18C: jr          $ra
    // 0x8018D190: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    return;
    // 0x8018D190: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
;}
RECOMP_FUNC void grPupupuFlowersBackUpdateAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106044: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80106048: lbu         $v0, 0x141B($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X141B);
    // 0x8010604C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80106050: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80106054: beq         $v0, $at, L_80106078
    if (ctx->r2 == ctx->r1) {
        // 0x80106058: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80106078;
    }
    // 0x80106058: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010605C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80106060: beq         $v0, $at, L_80106088
    if (ctx->r2 == ctx->r1) {
        // 0x80106064: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80106088;
    }
    // 0x80106064: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80106068: beq         $v0, $at, L_80106098
    if (ctx->r2 == ctx->r1) {
        // 0x8010606C: nop
    
            goto L_80106098;
    }
    // 0x8010606C: nop

    // 0x80106070: b           L_801060A4
    // 0x80106074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801060A4;
    // 0x80106074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106078:
    // 0x80106078: jal         0x80105F94
    // 0x8010607C: nop

    grPupupuFlowersBackWindStart(rdram, ctx);
        goto after_0;
    // 0x8010607C: nop

    after_0:
    // 0x80106080: b           L_801060A4
    // 0x80106084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801060A4;
    // 0x80106084: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106088:
    // 0x80106088: jal         0x80105FC4
    // 0x8010608C: nop

    grPupupuFlowersBackLoopStart(rdram, ctx);
        goto after_1;
    // 0x8010608C: nop

    after_1:
    // 0x80106090: b           L_801060A4
    // 0x80106094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801060A4;
    // 0x80106094: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80106098:
    // 0x80106098: jal         0x80106008
    // 0x8010609C: nop

    grPupupuFlowersBackLoopEnd(rdram, ctx);
        goto after_2;
    // 0x8010609C: nop

    after_2:
    // 0x801060A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801060A4:
    // 0x801060A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801060A8: jr          $ra
    // 0x801060AC: nop

    return;
    // 0x801060AC: nop

;}
RECOMP_FUNC void itBoxCommonCheckSpawnItems(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179424: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80179428: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8017942C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80179430: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80179434: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x80179438: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8017943C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80179440: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80179444: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80179448: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8017944C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80179450: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80179454: jal         0x800269C0
    // 0x80179458: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80179458: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_0:
    // 0x8017945C: lw          $a0, 0x74($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X74);
    // 0x80179460: jal         0x801791F4
    // 0x80179464: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    itBoxContainerSmashMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80179464: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80179468: lui         $fp, 0x8019
    ctx->r30 = S32(0X8019 << 16);
    // 0x8017946C: addiu       $fp, $fp, -0x2FB8
    ctx->r30 = ADD32(ctx->r30, -0X2FB8);
    // 0x80179470: lhu         $t6, 0x10($fp)
    ctx->r14 = MEM_HU(ctx->r30, 0X10);
    // 0x80179474: beql        $t6, $zero, L_8017960C
    if (ctx->r14 == 0) {
        // 0x80179478: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8017960C;
    }
    goto skip_0;
    // 0x80179478: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8017947C: jal         0x80173090
    // 0x80179480: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    itMainGetWeightedItemKind(rdram, ctx);
        goto after_2;
    // 0x80179480: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_2:
    // 0x80179484: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80179488: beq         $at, $zero, L_80179608
    if (ctx->r1 == 0) {
        // 0x8017948C: or          $s6, $v0, $zero
        ctx->r22 = ctx->r2 | 0;
            goto L_80179608;
    }
    // 0x8017948C: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x80179490: jal         0x80018994
    // 0x80179494: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x80179494: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x80179498: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8017949C: beq         $at, $zero, L_801794B0
    if (ctx->r1 == 0) {
        // 0x801794A0: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_801794B0;
    }
    // 0x801794A0: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x801794A4: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x801794A8: b           L_801794D4
    // 0x801794AC: addiu       $s2, $s2, -0x5CE0
    ctx->r18 = ADD32(ctx->r18, -0X5CE0);
        goto L_801794D4;
    // 0x801794AC: addiu       $s2, $s2, -0x5CE0
    ctx->r18 = ADD32(ctx->r18, -0X5CE0);
L_801794B0:
    // 0x801794B0: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x801794B4: beq         $at, $zero, L_801794CC
    if (ctx->r1 == 0) {
        // 0x801794B8: addiu       $s5, $zero, 0x3
        ctx->r21 = ADD32(0, 0X3);
            goto L_801794CC;
    }
    // 0x801794B8: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x801794BC: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x801794C0: addiu       $s5, $zero, 0x2
    ctx->r21 = ADD32(0, 0X2);
    // 0x801794C4: b           L_801794D4
    // 0x801794C8: addiu       $s2, $s2, -0x5CD8
    ctx->r18 = ADD32(ctx->r18, -0X5CD8);
        goto L_801794D4;
    // 0x801794C8: addiu       $s2, $s2, -0x5CD8
    ctx->r18 = ADD32(ctx->r18, -0X5CD8);
L_801794CC:
    // 0x801794CC: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x801794D0: addiu       $s2, $s2, -0x5CC8
    ctx->r18 = ADD32(ctx->r18, -0X5CC8);
L_801794D4:
    // 0x801794D4: jal         0x80018994
    // 0x801794D8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    syUtilsRandIntRange(rdram, ctx);
        goto after_4;
    // 0x801794D8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_4:
    // 0x801794DC: bnel        $v0, $zero, L_8017954C
    if (ctx->r2 != 0) {
        // 0x801794E0: lbu         $v0, 0x8($fp)
        ctx->r2 = MEM_BU(ctx->r30, 0X8);
            goto L_8017954C;
    }
    goto skip_1;
    // 0x801794E0: lbu         $v0, 0x8($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X8);
    skip_1:
    // 0x801794E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801794E8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x801794EC: blez        $s5, L_801795F8
    if (SIGNED(ctx->r21) <= 0) {
        // 0x801794F0: swc1        $f4, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
            goto L_801795F8;
    }
    // 0x801794F0: swc1        $f4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f4.u32l;
    // 0x801794F4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    // 0x801794F8: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x801794FC: ori         $s2, $s2, 0x3
    ctx->r18 = ctx->r18 | 0X3;
    // 0x80179500: sll         $s4, $s5, 3
    ctx->r20 = S32(ctx->r21 << 3);
    // 0x80179504: addiu       $s7, $sp, 0x6C
    ctx->r23 = ADD32(ctx->r29, 0X6C);
L_80179508:
    // 0x80179508: lwc1        $f6, 0x0($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X0);
    // 0x8017950C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80179510: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80179514: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x80179518: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x8017951C: or          $a3, $s7, $zero
    ctx->r7 = ctx->r23 | 0;
    // 0x80179520: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x80179524: lw          $a2, 0x74($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X74);
    // 0x80179528: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8017952C: jal         0x8016EA78
    // 0x80179530: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_5;
    // 0x80179530: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_5:
    // 0x80179534: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80179538: bne         $s1, $s4, L_80179508
    if (ctx->r17 != ctx->r20) {
        // 0x8017953C: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_80179508;
    }
    // 0x8017953C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x80179540: b           L_801795F8
    // 0x80179544: nop

        goto L_801795F8;
    // 0x80179544: nop

    // 0x80179548: lbu         $v0, 0x8($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X8);
L_8017954C:
    // 0x8017954C: lhu         $t7, 0x10($fp)
    ctx->r15 = MEM_HU(ctx->r30, 0X10);
    // 0x80179550: lw          $t8, 0x14($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X14);
    // 0x80179554: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80179558: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8017955C: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80179560: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80179564: lhu         $t1, 0x0($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X0);
    // 0x80179568: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8017956C: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80179570: sb          $t2, 0x8($fp)
    MEM_B(0X8, ctx->r30) = ctx->r10;
    // 0x80179574: sh          $t1, 0x10($fp)
    MEM_H(0X10, ctx->r30) = ctx->r9;
    // 0x80179578: blez        $s5, L_801795E4
    if (SIGNED(ctx->r21) <= 0) {
        // 0x8017957C: swc1        $f10, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
            goto L_801795E4;
    }
    // 0x8017957C: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x80179580: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x80179584: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x80179588: ori         $s2, $s2, 0x3
    ctx->r18 = ctx->r18 | 0X3;
    // 0x8017958C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80179590: sll         $s7, $s5, 3
    ctx->r23 = S32(ctx->r21 << 3);
    // 0x80179594: addiu       $s4, $sp, 0x54
    ctx->r20 = ADD32(ctx->r29, 0X54);
L_80179598:
    // 0x80179598: beql        $s0, $zero, L_801795B0
    if (ctx->r16 == 0) {
        // 0x8017959C: lwc1        $f16, 0x0($s1)
        ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
            goto L_801795B0;
    }
    goto skip_2;
    // 0x8017959C: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x801795A0: jal         0x80173090
    // 0x801795A4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    itMainGetWeightedItemKind(rdram, ctx);
        goto after_6;
    // 0x801795A4: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    after_6:
    // 0x801795A8: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x801795AC: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
L_801795B0:
    // 0x801795B0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x801795B4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x801795B8: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x801795BC: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x801795C0: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    // 0x801795C4: swc1        $f18, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f18.u32l;
    // 0x801795C8: lw          $a2, 0x74($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X74);
    // 0x801795CC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x801795D0: jal         0x8016EA78
    // 0x801795D4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_7;
    // 0x801795D4: addiu       $a2, $a2, 0x1C
    ctx->r6 = ADD32(ctx->r6, 0X1C);
    after_7:
    // 0x801795D8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x801795DC: bne         $s0, $s7, L_80179598
    if (ctx->r16 != ctx->r23) {
        // 0x801795E0: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80179598;
    }
    // 0x801795E0: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_801795E4:
    // 0x801795E4: lbu         $t3, 0x8($fp)
    ctx->r11 = MEM_BU(ctx->r30, 0X8);
    // 0x801795E8: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    // 0x801795EC: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x801795F0: sb          $t4, 0x8($fp)
    MEM_B(0X8, ctx->r30) = ctx->r12;
    // 0x801795F4: sh          $t5, 0x10($fp)
    MEM_H(0X10, ctx->r30) = ctx->r13;
L_801795F8:
    // 0x801795F8: jal         0x800269C0
    // 0x801795FC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x801795FC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_8:
    // 0x80179600: b           L_8017960C
    // 0x80179604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017960C;
    // 0x80179604: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80179608:
    // 0x80179608: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017960C:
    // 0x8017960C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80179610: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80179614: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80179618: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8017961C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80179620: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80179624: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80179628: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8017962C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x80179630: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x80179634: jr          $ra
    // 0x80179638: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80179638: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void gmCameraPlayerArrowsProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010E254: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8010E258: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010E25C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8010E260: jal         0x80017830
    // 0x8010E264: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSetCameraMatrixMode(rdram, ctx);
        goto after_0;
    // 0x8010E264: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8010E268: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010E26C: lbu         $t6, 0x158E($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X158E);
    // 0x8010E270: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x8010E274: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8010E278: beql        $t6, $zero, L_8010E2C8
    if (ctx->r14 == 0) {
        // 0x8010E27C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8010E2C8;
    }
    goto skip_0;
    // 0x8010E27C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8010E280: lw          $a1, 0x74($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X74);
    // 0x8010E284: addiu       $a0, $a0, 0x65B0
    ctx->r4 = ADD32(ctx->r4, 0X65B0);
    // 0x8010E288: jal         0x80016EDC
    // 0x8010E28C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    gcPrepCameraMatrix(rdram, ctx);
        goto after_1;
    // 0x8010E28C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x8010E290: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8010E294: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8010E298: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010E29C: lw          $t8, 0x80($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X80);
    // 0x8010E2A0: andi        $t9, $t8, 0x8
    ctx->r25 = ctx->r24 & 0X8;
    // 0x8010E2A4: beq         $t9, $zero, L_8010E2B4
    if (ctx->r25 == 0) {
        // 0x8010E2A8: nop
    
            goto L_8010E2B4;
    }
    // 0x8010E2A8: nop

    // 0x8010E2AC: b           L_8010E2B4
    // 0x8010E2B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8010E2B4;
    // 0x8010E2B0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8010E2B4:
    // 0x8010E2B4: jal         0x80017B80
    // 0x8010E2B8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    gcCaptureCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8010E2B8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    after_2:
    // 0x8010E2BC: jal         0x80017CC8
    // 0x8010E2C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    func_80017CC8(rdram, ctx);
        goto after_3;
    // 0x8010E2C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_3:
    // 0x8010E2C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010E2C8:
    // 0x8010E2C8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8010E2CC: jr          $ra
    // 0x8010E2D0: nop

    return;
    // 0x8010E2D0: nop

;}
RECOMP_FUNC void grInishieScaleProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801093EC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801093F0: lbu         $v0, 0x1422($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1422);
    // 0x801093F4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801093F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801093FC: beq         $v0, $zero, L_80109428
    if (ctx->r2 == 0) {
        // 0x80109400: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80109428;
    }
    // 0x80109400: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80109404: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80109408: beq         $v0, $at, L_80109438
    if (ctx->r2 == ctx->r1) {
        // 0x8010940C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80109438;
    }
    // 0x8010940C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80109410: beq         $v0, $at, L_80109448
    if (ctx->r2 == ctx->r1) {
        // 0x80109414: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80109448;
    }
    // 0x80109414: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80109418: beq         $v0, $at, L_80109458
    if (ctx->r2 == ctx->r1) {
        // 0x8010941C: nop
    
            goto L_80109458;
    }
    // 0x8010941C: nop

    // 0x80109420: b           L_80109460
    // 0x80109424: nop

        goto L_80109460;
    // 0x80109424: nop

L_80109428:
    // 0x80109428: jal         0x80108E50
    // 0x8010942C: nop

    grInishieScaleUpdateWait(rdram, ctx);
        goto after_0;
    // 0x8010942C: nop

    after_0:
    // 0x80109430: b           L_80109460
    // 0x80109434: nop

        goto L_80109460;
    // 0x80109434: nop

L_80109438:
    // 0x80109438: jal         0x80109118
    // 0x8010943C: nop

    grInishieScaleUpdateFall(rdram, ctx);
        goto after_1;
    // 0x8010943C: nop

    after_1:
    // 0x80109440: b           L_80109460
    // 0x80109444: nop

        goto L_80109460;
    // 0x80109444: nop

L_80109448:
    // 0x80109448: jal         0x80109220
    // 0x8010944C: nop

    grInishieScaleUpdateStep(rdram, ctx);
        goto after_2;
    // 0x8010944C: nop

    after_2:
    // 0x80109450: b           L_80109460
    // 0x80109454: nop

        goto L_80109460;
    // 0x80109454: nop

L_80109458:
    // 0x80109458: jal         0x8010929C
    // 0x8010945C: nop

    grInishieScaleUpdateRetract(rdram, ctx);
        goto after_3;
    // 0x8010945C: nop

    after_3:
L_80109460:
    // 0x80109460: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80109464: lw          $a1, 0x13F8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X13F8);
    // 0x80109468: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010946C: lbu         $a0, -0x14CC($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CC);
    // 0x80109470: jal         0x800FC4A8
    // 0x80109474: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionSetYakumonoPosID(rdram, ctx);
        goto after_4;
    // 0x80109474: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_4:
    // 0x80109478: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8010947C: lw          $a1, 0x1408($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1408);
    // 0x80109480: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80109484: lbu         $a0, -0x14CB($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X14CB);
    // 0x80109488: jal         0x800FC4A8
    // 0x8010948C: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    mpCollisionSetYakumonoPosID(rdram, ctx);
        goto after_5;
    // 0x8010948C: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_5:
    // 0x80109490: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109494: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109498: jr          $ra
    // 0x8010949C: nop

    return;
    // 0x8010949C: nop

;}
RECOMP_FUNC void itTaruDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179F74: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179F78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179F7C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80179F80: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80179F84: addiu       $a1, $a1, -0x5B7C
    ctx->r5 = ADD32(ctx->r5, -0X5B7C);
    // 0x80179F88: jal         0x80172EC8
    // 0x80179F8C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80179F8C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x80179F90: jal         0x80179EF0
    // 0x80179F94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itTaruThrownInitVars(rdram, ctx);
        goto after_1;
    // 0x80179F94: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80179F98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179F9C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179FA0: jr          $ra
    // 0x80179FA4: nop

    return;
    // 0x80179FA4: nop

;}
RECOMP_FUNC void func_ovl8_8037D99C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D99C: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D9A0: jr          $ra
    // 0x8037D9A4: sw          $a0, -0x464($at)
    MEM_W(-0X464, ctx->r1) = ctx->r4;
    return;
    // 0x8037D9A4: sw          $a0, -0x464($at)
    MEM_W(-0X464, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void itBoxFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179718: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017971C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179720: lui         $a1, 0x3E4C
    ctx->r5 = S32(0X3E4C << 16);
    // 0x80179724: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x80179728: addiu       $a3, $a3, -0x68B8
    ctx->r7 = ADD32(ctx->r7, -0X68B8);
    // 0x8017972C: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    // 0x80179730: jal         0x80173B24
    // 0x80179734: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80179734: lui         $a2, 0x3F00
    ctx->r6 = S32(0X3F00 << 16);
    after_0:
    // 0x80179738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017973C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179740: jr          $ra
    // 0x80179744: nop

    return;
    // 0x80179744: nop

;}
RECOMP_FUNC void gmCollisionCheckWeaponAttackFighterAttackCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EFD70: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800EFD74: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800EFD78: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800EFD7C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800EFD80: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800EFD84: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800EFD88: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800EFD8C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800EFD90: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    // 0x800EFD94: addiu       $v1, $s0, 0x44
    ctx->r3 = ADD32(ctx->r16, 0X44);
    // 0x800EFD98: addiu       $t0, $s0, 0x50
    ctx->r8 = ADD32(ctx->r16, 0X50);
    // 0x800EFD9C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800EFDA0: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800EFDA4: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800EFDA8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800EFDAC: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800EFDB0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800EFDB4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800EFDB8: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800EFDBC: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800EFDC0: addiu       $a0, $v0, 0x54
    ctx->r4 = ADD32(ctx->r2, 0X54);
    // 0x800EFDC4: addiu       $a1, $v0, 0x60
    ctx->r5 = ADD32(ctx->r2, 0X60);
    // 0x800EFDC8: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800EFDCC: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x800EFDD0: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800EFDD4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800EFDD8: jal         0x800EF5D4
    // 0x800EFDDC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_ovl2_800EF5D4(rdram, ctx);
        goto after_0;
    // 0x800EFDDC: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x800EFDE0: bne         $v0, $zero, L_800EFDF0
    if (ctx->r2 != 0) {
        // 0x800EFDE4: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_800EFDF0;
    }
    // 0x800EFDE4: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800EFDE8: b           L_800EFE58
    // 0x800EFDEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800EFE58;
    // 0x800EFDEC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800EFDF0:
    // 0x800EFDF0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800EFDF4: addiu       $v0, $s0, 0x80
    ctx->r2 = ADD32(ctx->r16, 0X80);
    // 0x800EFDF8: addiu       $t9, $s0, 0xC0
    ctx->r25 = ADD32(ctx->r16, 0XC0);
    // 0x800EFDFC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800EFE00: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800EFE04: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800EFE08: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800EFE0C: jal         0x800EE050
    // 0x800EFE10: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    func_ovl2_800EE050(rdram, ctx);
        goto after_1;
    // 0x800EFE10: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    after_1:
    // 0x800EFE14: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800EFE18: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    // 0x800EFE1C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800EFE20: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800EFE24: lw          $t1, 0x7C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C);
    // 0x800EFE28: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800EFE2C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800EFE30: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800EFE34: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800EFE38: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800EFE3C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800EFE40: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800EFE44: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800EFE48: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800EFE4C: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800EFE50: jal         0x800EEEAC
    // 0x800EFE54: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_ovl2_800EEEAC(rdram, ctx);
        goto after_2;
    // 0x800EFE54: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_2:
L_800EFE58:
    // 0x800EFE58: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800EFE5C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800EFE60: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800EFE64: jr          $ra
    // 0x800EFE68: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800EFE68: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void itHammerThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801762A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801762AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801762B0: lui         $a2, 0x3E4C
    ctx->r6 = S32(0X3E4C << 16);
    // 0x801762B4: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x801762B8: addiu       $a3, $a3, 0x61C4
    ctx->r7 = ADD32(ctx->r7, 0X61C4);
    // 0x801762BC: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    // 0x801762C0: jal         0x80173B24
    // 0x801762C4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x801762C4: lui         $a1, 0x3F00
    ctx->r5 = S32(0X3F00 << 16);
    after_0:
    // 0x801762C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801762CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801762D0: jr          $ra
    // 0x801762D4: nop

    return;
    // 0x801762D4: nop

;}
RECOMP_FUNC void unref_80021958(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80021958: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002195C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80021960: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80021964: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80021968: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8002196C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80021970: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80021974: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80021978: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002197C: blez        $a3, L_80021A14
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80021980: sw          $s2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r18;
            goto L_80021A14;
    }
    // 0x80021980: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80021984: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80021988: lw          $t6, 0x6678($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6678);
    // 0x8002198C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
    // 0x80021990: subu        $t7, $t6, $a0
    ctx->r15 = SUB32(ctx->r14, ctx->r4);
    // 0x80021994: div         $zero, $t7, $v0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r2)));
    // 0x80021998: bne         $v0, $zero, L_800219A4
    if (ctx->r2 != 0) {
        // 0x8002199C: nop
    
            goto L_800219A4;
    }
    // 0x8002199C: nop

    // 0x800219A0: break       7
    do_break(2147621280);
L_800219A4:
    // 0x800219A4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800219A8: bne         $v0, $at, L_800219BC
    if (ctx->r2 != ctx->r1) {
        // 0x800219AC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800219BC;
    }
    // 0x800219AC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800219B0: bne         $t7, $at, L_800219BC
    if (ctx->r15 != ctx->r1) {
        // 0x800219B4: nop
    
            goto L_800219BC;
    }
    // 0x800219B4: nop

    // 0x800219B8: break       6
    do_break(2147621304);
L_800219BC:
    // 0x800219BC: mflo        $t8
    ctx->r24 = lo;
    // 0x800219C0: slt         $at, $a3, $t8
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800219C4: beql        $at, $zero, L_80021A18
    if (ctx->r1 == 0) {
        // 0x800219C8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80021A18;
    }
    goto skip_0;
    // 0x800219C8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_0:
    // 0x800219CC: multu       $a3, $v0
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800219D0: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x800219D4: mflo        $s2
    ctx->r18 = lo;
    // 0x800219D8: addu        $s1, $s1, $s2
    ctx->r17 = ADD32(ctx->r17, ctx->r18);
    // 0x800219DC: blez        $a3, L_80021A14
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800219E0: addiu       $s1, $s1, -0x7
        ctx->r17 = ADD32(ctx->r17, -0X7);
            goto L_80021A14;
    }
    // 0x800219E0: addiu       $s1, $s1, -0x7
    ctx->r17 = ADD32(ctx->r17, -0X7);
L_800219E4:
    // 0x800219E4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800219E8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800219EC: andi        $a2, $s0, 0xF
    ctx->r6 = ctx->r16 & 0XF;
    // 0x800219F0: jal         0x800210C0
    // 0x800219F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    func_800210C0(rdram, ctx);
        goto after_0;
    // 0x800219F4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800219F8: beq         $s3, $zero, L_80021A04
    if (ctx->r19 == 0) {
        // 0x800219FC: sra         $s0, $s0, 4
        ctx->r16 = S32(SIGNED(ctx->r16) >> 4);
            goto L_80021A04;
    }
    // 0x800219FC: sra         $s0, $s0, 4
    ctx->r16 = S32(SIGNED(ctx->r16) >> 4);
    // 0x80021A00: beq         $s0, $zero, L_80021A14
    if (ctx->r16 == 0) {
        // 0x80021A04: addiu       $s2, $s2, -0x7
        ctx->r18 = ADD32(ctx->r18, -0X7);
            goto L_80021A14;
    }
L_80021A04:
    // 0x80021A04: addiu       $s2, $s2, -0x7
    ctx->r18 = ADD32(ctx->r18, -0X7);
    // 0x80021A08: slti        $at, $s2, 0x7
    ctx->r1 = SIGNED(ctx->r18) < 0X7 ? 1 : 0;
    // 0x80021A0C: beq         $at, $zero, L_800219E4
    if (ctx->r1 == 0) {
        // 0x80021A10: addiu       $s1, $s1, -0x7
        ctx->r17 = ADD32(ctx->r17, -0X7);
            goto L_800219E4;
    }
    // 0x80021A10: addiu       $s1, $s1, -0x7
    ctx->r17 = ADD32(ctx->r17, -0X7);
L_80021A14:
    // 0x80021A14: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80021A18:
    // 0x80021A18: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80021A1C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80021A20: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80021A24: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80021A28: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80021A2C: jr          $ra
    // 0x80021A30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80021A30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayers1PGameMakeCursorCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137268: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013726C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80137270: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80137274: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80137278: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x8013727C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80137280: lui         $t9, 0x4000
    ctx->r25 = S32(0X4000 << 16);
    // 0x80137284: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80137288: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013728C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80137290: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80137294: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80137298: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013729C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801372A0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801372A4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801372A8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801372AC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801372B0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801372B4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801372B8: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801372BC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801372C0: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801372C4: jal         0x8000B93C
    // 0x801372C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801372C8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801372CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801372D0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801372D4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801372D8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801372DC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801372E0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801372E4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801372E8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801372EC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801372F0: jal         0x80007080
    // 0x801372F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801372F4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801372F8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801372FC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80137300: jr          $ra
    // 0x80137304: nop

    return;
    // 0x80137304: nop

;}
RECOMP_FUNC void ftParamGetCapturedDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800EA40C: lw          $t6, 0x844($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X844);
    // 0x800EA410: beql        $t6, $zero, L_800EA448
    if (ctx->r14 == 0) {
        // 0x800EA414: mtc1        $a1, $f6
        ctx->f6.u32l = ctx->r5;
            goto L_800EA448;
    }
    goto skip_0;
    // 0x800EA414: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    skip_0:
    // 0x800EA418: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x800EA41C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800EA420: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800EA424: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EA428: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA42C: lwc1        $f16, -0xA8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XA8);
    // 0x800EA430: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800EA434: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800EA438: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800EA43C: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x800EA440: nop

    // 0x800EA444: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
L_800EA448:
    // 0x800EA448: lwc1        $f10, 0x81C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X81C);
    // 0x800EA44C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA450: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800EA454: lwc1        $f18, -0xA4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XA4);
    // 0x800EA458: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800EA45C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800EA460: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800EA464: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800EA468: jr          $ra
    // 0x800EA46C: nop

    return;
    // 0x800EA46C: nop

;}
RECOMP_FUNC void mnVSResultsGetPlayerCountPlace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133684: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133688: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x8013368C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80133690: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80133694: beq         $t6, $zero, L_801336B0
    if (ctx->r14 == 0) {
        // 0x80133698: lui         $t0, 0x8014
        ctx->r8 = S32(0X8014 << 16);
            goto L_801336B0;
    }
    // 0x80133698: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013369C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801336A0: lw          $t7, -0x6450($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6450);
    // 0x801336A4: bne         $a0, $t7, L_801336B0
    if (ctx->r4 != ctx->r15) {
        // 0x801336A8: nop
    
            goto L_801336B0;
    }
    // 0x801336A8: nop

    // 0x801336AC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801336B0:
    // 0x801336B0: lw          $t8, -0x642C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X642C);
    // 0x801336B4: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x801336B8: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801336BC: beq         $t8, $zero, L_801336D4
    if (ctx->r24 == 0) {
        // 0x801336C0: lui         $t1, 0x8014
        ctx->r9 = S32(0X8014 << 16);
            goto L_801336D4;
    }
    // 0x801336C0: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x801336C4: lw          $t9, -0x644C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X644C);
    // 0x801336C8: bne         $a0, $t9, L_801336D4
    if (ctx->r4 != ctx->r25) {
        // 0x801336CC: nop
    
            goto L_801336D4;
    }
    // 0x801336CC: nop

    // 0x801336D0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801336D4:
    // 0x801336D4: lw          $t0, -0x6428($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6428);
    // 0x801336D8: lui         $t3, 0x8014
    ctx->r11 = S32(0X8014 << 16);
    // 0x801336DC: beq         $t0, $zero, L_801336F4
    if (ctx->r8 == 0) {
        // 0x801336E0: nop
    
            goto L_801336F4;
    }
    // 0x801336E0: nop

    // 0x801336E4: lw          $t1, -0x6448($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X6448);
    // 0x801336E8: bne         $a0, $t1, L_801336F4
    if (ctx->r4 != ctx->r9) {
        // 0x801336EC: nop
    
            goto L_801336F4;
    }
    // 0x801336EC: nop

    // 0x801336F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_801336F4:
    // 0x801336F4: lw          $t2, -0x6424($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6424);
    // 0x801336F8: beq         $t2, $zero, L_80133710
    if (ctx->r10 == 0) {
        // 0x801336FC: nop
    
            goto L_80133710;
    }
    // 0x801336FC: nop

    // 0x80133700: lw          $t3, -0x6444($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X6444);
    // 0x80133704: bne         $a0, $t3, L_80133710
    if (ctx->r4 != ctx->r11) {
        // 0x80133708: nop
    
            goto L_80133710;
    }
    // 0x80133708: nop

    // 0x8013370C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80133710:
    // 0x80133710: jr          $ra
    // 0x80133714: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80133714: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mnPlayers1PGameCheckStockArrowLInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801369C0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801369C4: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x801369C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801369CC: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801369D0: lui         $at, 0x433E
    ctx->r1 = S32(0X433E << 16);
    // 0x801369D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801369D8: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x801369DC: lui         $at, 0x4354
    ctx->r1 = S32(0X4354 << 16);
    // 0x801369E0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x801369E4: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x801369E8: nop

    // 0x801369EC: bc1f        L_80136A14
    if (!c1cs) {
        // 0x801369F0: nop
    
            goto L_80136A14;
    }
    // 0x801369F0: nop

    // 0x801369F4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801369F8: nop

    // 0x801369FC: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x80136A00: nop

    // 0x80136A04: bc1f        L_80136A14
    if (!c1cs) {
        // 0x80136A08: nop
    
            goto L_80136A14;
    }
    // 0x80136A08: nop

    // 0x80136A0C: b           L_80136A14
    // 0x80136A10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80136A14;
    // 0x80136A10: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80136A14:
    // 0x80136A14: beq         $v1, $zero, L_80136A78
    if (ctx->r3 == 0) {
        // 0x80136A18: lui         $at, 0x4040
        ctx->r1 = S32(0X4040 << 16);
            goto L_80136A78;
    }
    // 0x80136A18: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80136A1C: lwc1        $f16, 0x5C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80136A20: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80136A24: lui         $at, 0x432F
    ctx->r1 = S32(0X432F << 16);
    // 0x80136A28: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80136A2C: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80136A30: lui         $at, 0x4342
    ctx->r1 = S32(0X4342 << 16);
    // 0x80136A34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80136A38: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x80136A3C: nop

    // 0x80136A40: bc1f        L_80136A68
    if (!c1cs) {
        // 0x80136A44: nop
    
            goto L_80136A68;
    }
    // 0x80136A44: nop

    // 0x80136A48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136A4C: nop

    // 0x80136A50: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x80136A54: nop

    // 0x80136A58: bc1f        L_80136A68
    if (!c1cs) {
        // 0x80136A5C: nop
    
            goto L_80136A68;
    }
    // 0x80136A5C: nop

    // 0x80136A60: b           L_80136A68
    // 0x80136A64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80136A68;
    // 0x80136A64: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80136A68:
    // 0x80136A68: beql        $v1, $zero, L_80136A7C
    if (ctx->r3 == 0) {
        // 0x80136A6C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80136A7C;
    }
    goto skip_0;
    // 0x80136A6C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80136A70: jr          $ra
    // 0x80136A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80136A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80136A78:
    // 0x80136A78: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80136A7C:
    // 0x80136A7C: jr          $ra
    // 0x80136A80: nop

    return;
    // 0x80136A80: nop

;}
RECOMP_FUNC void itMBallOpenAirSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017CDE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017CDE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017CDEC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017CDF0: addiu       $a1, $a1, -0x573C
    ctx->r5 = ADD32(ctx->r5, -0X573C);
    // 0x8017CDF4: jal         0x80172EC8
    // 0x8017CDF8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017CDF8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_0:
    // 0x8017CDFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017CE00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017CE04: jr          $ra
    // 0x8017CE08: nop

    return;
    // 0x8017CE08: nop

;}
RECOMP_FUNC void func_ovl8_803716D8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803716D8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803716DC: sltiu       $at, $a0, 0x8
    ctx->r1 = ctx->r4 < 0X8 ? 1 : 0;
    // 0x803716E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803716E4: beq         $at, $zero, L_803716F0
    if (ctx->r1 == 0) {
        // 0x803716E8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_803716F0;
    }
    // 0x803716E8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x803716EC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
L_803716F0:
    // 0x803716F0: addiu       $a1, $a2, 0xF
    ctx->r5 = ADD32(ctx->r6, 0XF);
    // 0x803716F4: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x803716F8: and         $a1, $a1, $at
    ctx->r5 = ctx->r5 & ctx->r1;
    // 0x803716FC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80371700: jal         0x803714B4
    // 0x80371704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_ovl8_803714B4(rdram, ctx);
        goto after_0;
    // 0x80371704: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80371708: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8037170C: bne         $v0, $zero, L_8037171C
    if (ctx->r2 != 0) {
        // 0x80371710: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8037171C;
    }
    // 0x80371710: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80371714: b           L_80371754
    // 0x80371718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80371754;
    // 0x80371718: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037171C:
    // 0x8037171C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x80371720: subu        $t7, $t6, $a1
    ctx->r15 = SUB32(ctx->r14, ctx->r5);
    // 0x80371724: sltiu       $at, $t7, 0x15
    ctx->r1 = ctx->r15 < 0X15 ? 1 : 0;
    // 0x80371728: bne         $at, $zero, L_8037173C
    if (ctx->r1 != 0) {
        // 0x8037172C: nop
    
            goto L_8037173C;
    }
    // 0x8037172C: nop

    // 0x80371730: jal         0x803714F8
    // 0x80371734: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_ovl8_803714F8(rdram, ctx);
        goto after_1;
    // 0x80371734: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x80371738: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
L_8037173C:
    // 0x8037173C: jal         0x803714A0
    // 0x80371740: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    func_ovl8_803714A0(rdram, ctx);
        goto after_2;
    // 0x80371740: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_2:
    // 0x80371744: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80371748: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8037174C: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x80371750: addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
L_80371754:
    // 0x80371754: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371758: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8037175C: jr          $ra
    // 0x80371760: nop

    return;
    // 0x80371760: nop

;}
RECOMP_FUNC void wpBossBulletProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016DCB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8016DCB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016DCB8: jal         0x80167C04
    // 0x8016DCBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x8016DCBC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8016DCC0: beql        $v0, $zero, L_8016DCF4
    if (ctx->r2 == 0) {
        // 0x8016DCC4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8016DCF4;
    }
    goto skip_0;
    // 0x8016DCC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x8016DCC8: jal         0x8016DC2C
    // 0x8016DCCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpBossBulletExplodeInitVars(rdram, ctx);
        goto after_1;
    // 0x8016DCCC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8016DCD0: jal         0x800269C0
    // 0x8016DCD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x8016DCD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x8016DCD8: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8016DCDC: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x8016DCE0: jal         0x801005C8
    // 0x8016DCE4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_3;
    // 0x8016DCE4: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_3:
    // 0x8016DCE8: b           L_8016DCF4
    // 0x8016DCEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8016DCF4;
    // 0x8016DCEC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8016DCF0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8016DCF4:
    // 0x8016DCF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016DCF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016DCFC: jr          $ra
    // 0x8016DD00: nop

    return;
    // 0x8016DD00: nop

;}
RECOMP_FUNC void itIwarkAttackProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D820: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8017D824: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x8017D828: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017D82C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D830: lh          $t7, 0x74($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X74);
    // 0x8017D834: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8017D838: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8017D83C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8017D840: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017D844: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017D848: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8017D84C: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8017D850: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8017D854: c.le.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl <= ctx->f10.fl;
    // 0x8017D858: nop

    // 0x8017D85C: bc1fl       L_8017D908
    if (!c1cs) {
        // 0x8017D860: lhu         $a0, 0x33E($v1)
        ctx->r4 = MEM_HU(ctx->r3, 0X33E);
            goto L_8017D908;
    }
    goto skip_0;
    // 0x8017D860: lhu         $a0, 0x33E($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X33E);
    skip_0:
    // 0x8017D864: swc1        $f0, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f0.u32l;
    // 0x8017D868: lhu         $t8, 0x350($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X350);
    // 0x8017D86C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8017D870: beq         $t8, $zero, L_8017D890
    if (ctx->r24 == 0) {
        // 0x8017D874: swc1        $f16, 0x30($v1)
        MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
            goto L_8017D890;
    }
    // 0x8017D874: swc1        $f16, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f16.u32l;
    // 0x8017D878: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8017D87C: jal         0x8017D740
    // 0x8017D880: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itIwarkAttackUpdateRock(rdram, ctx);
        goto after_0;
    // 0x8017D880: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017D884: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8017D888: b           L_8017D8A8
    // 0x8017D88C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
        goto L_8017D8A8;
    // 0x8017D88C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
L_8017D890:
    // 0x8017D890: lhu         $t9, 0x358($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X358);
    // 0x8017D894: lhu         $t0, 0x35E($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X35E);
    // 0x8017D898: bnel        $t9, $t0, L_8017D8AC
    if (ctx->r25 != ctx->r8) {
        // 0x8017D89C: lhu         $t1, 0x35C($v1)
        ctx->r9 = MEM_HU(ctx->r3, 0X35C);
            goto L_8017D8AC;
    }
    goto skip_1;
    // 0x8017D89C: lhu         $t1, 0x35C($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X35C);
    skip_1:
    // 0x8017D8A0: b           L_8017D938
    // 0x8017D8A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8017D938;
    // 0x8017D8A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8017D8A8:
    // 0x8017D8A8: lhu         $t1, 0x35C($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X35C);
L_8017D8AC:
    // 0x8017D8AC: bnel        $t1, $zero, L_8017D8E4
    if (ctx->r9 != 0) {
        // 0x8017D8B0: lhu         $t4, 0x35A($v1)
        ctx->r12 = MEM_HU(ctx->r3, 0X35A);
            goto L_8017D8E4;
    }
    goto skip_2;
    // 0x8017D8B0: lhu         $t4, 0x35A($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X35A);
    skip_2:
    // 0x8017D8B4: lhu         $t2, 0x35A($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X35A);
    // 0x8017D8B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8017D8BC: beql        $t2, $zero, L_8017D8E4
    if (ctx->r10 == 0) {
        // 0x8017D8C0: lhu         $t4, 0x35A($v1)
        ctx->r12 = MEM_HU(ctx->r3, 0X35A);
            goto L_8017D8E4;
    }
    goto skip_3;
    // 0x8017D8C0: lhu         $t4, 0x35A($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X35A);
    skip_3:
    // 0x8017D8C4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8017D8C8: jal         0x801008F4
    // 0x8017D8CC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x8017D8CC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8017D8D0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D8D4: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8017D8D8: addiu       $t3, $zero, 0x12
    ctx->r11 = ADD32(0, 0X12);
    // 0x8017D8DC: sh          $t3, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = ctx->r11;
    // 0x8017D8E0: lhu         $t4, 0x35A($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X35A);
L_8017D8E4:
    // 0x8017D8E4: beql        $t4, $zero, L_8017D8FC
    if (ctx->r12 == 0) {
        // 0x8017D8E8: lw          $t7, 0x354($v1)
        ctx->r15 = MEM_W(ctx->r3, 0X354);
            goto L_8017D8FC;
    }
    goto skip_4;
    // 0x8017D8E8: lw          $t7, 0x354($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X354);
    skip_4:
    // 0x8017D8EC: lhu         $t5, 0x35C($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X35C);
    // 0x8017D8F0: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8017D8F4: sh          $t6, 0x35C($v1)
    MEM_H(0X35C, ctx->r3) = ctx->r14;
    // 0x8017D8F8: lw          $t7, 0x354($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X354);
L_8017D8FC:
    // 0x8017D8FC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x8017D900: sw          $t8, 0x354($v1)
    MEM_W(0X354, ctx->r3) = ctx->r24;
    // 0x8017D904: lhu         $a0, 0x33E($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X33E);
L_8017D908:
    // 0x8017D908: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8017D90C: bne         $a0, $at, L_8017D92C
    if (ctx->r4 != ctx->r1) {
        // 0x8017D910: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_8017D92C;
    }
    // 0x8017D910: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017D914: lwc1        $f4, -0x31D0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X31D0);
    // 0x8017D918: lwc1        $f18, 0x34($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X34);
    // 0x8017D91C: andi        $a0, $zero, 0xFFFF
    ctx->r4 = 0 & 0XFFFF;
    // 0x8017D920: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8017D924: swc1        $f6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f6.u32l;
    // 0x8017D928: sh          $zero, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = 0;
L_8017D92C:
    // 0x8017D92C: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x8017D930: sh          $t9, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r25;
    // 0x8017D934: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8017D938:
    // 0x8017D938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017D93C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017D940: jr          $ra
    // 0x8017D944: nop

    return;
    // 0x8017D944: nop

;}
RECOMP_FUNC void ftKirbyCopyCaptainSpecialAirNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80160AF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80160AF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80160AF8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80160AFC: jal         0x800DE6E4
    // 0x80160B00: addiu       $a1, $a1, 0xA40
    ctx->r5 = ADD32(ctx->r5, 0XA40);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80160B00: addiu       $a1, $a1, 0xA40
    ctx->r5 = ADD32(ctx->r5, 0XA40);
    after_0:
    // 0x80160B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80160B08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80160B0C: jr          $ra
    // 0x80160B10: nop

    return;
    // 0x80160B10: nop

;}
RECOMP_FUNC void gcSetGObjThreadPrevAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000745C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80007460: addiu       $v0, $v0, 0x66B0
    ctx->r2 = ADD32(ctx->r2, 0X66B0);
    // 0x80007464: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80007468: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8000746C: addiu       $v1, $v1, 0x66B4
    ctx->r3 = ADD32(ctx->r3, 0X66B4);
    // 0x80007470: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80007474: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007478: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8000747C: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80007480: jr          $ra
    // 0x80007484: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x80007484: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void gmCameraGetPlayerNumZoomRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BB58: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x8010BB5C: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x8010BB60: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8010BB64: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010BB68: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8010BB6C: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8010BB70: lwc1        $f2, -0x1430($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X1430);
    // 0x8010BB74: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8010BB78: bne         $t8, $at, L_8010BB90
    if (ctx->r24 != ctx->r1) {
        // 0x8010BB7C: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_8010BB90;
    }
    // 0x8010BB7C: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8010BB80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8010BB84: nop

    // 0x8010BB88: mul.s       $f2, $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x8010BB8C: nop

L_8010BB90:
    // 0x8010BB90: jr          $ra
    // 0x8010BB94: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x8010BB94: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void ftNessSpecialHiJibakuProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801549FC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80154A00: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80154A04: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80154A08: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80154A0C: jal         0x800DDDA8
    // 0x80154A10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80154A10: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80154A14: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80154A18: bne         $v0, $zero, L_80154A5C
    if (ctx->r2 != 0) {
        // 0x80154A1C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_80154A5C;
    }
    // 0x80154A1C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80154A20: lhu         $t6, 0xCE($a1)
    ctx->r14 = MEM_HU(ctx->r5, 0XCE);
    // 0x80154A24: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80154A28: andi        $t7, $t6, 0x21
    ctx->r15 = ctx->r14 & 0X21;
    // 0x80154A2C: beq         $t7, $zero, L_80154A4C
    if (ctx->r15 == 0) {
        // 0x80154A30: nop
    
            goto L_80154A4C;
    }
    // 0x80154A30: nop

    // 0x80154A34: jal         0x800DEEC8
    // 0x80154A38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_1;
    // 0x80154A38: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80154A3C: jal         0x80154558
    // 0x80154A40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftNessSpecialAirHiEndSetStatus(rdram, ctx);
        goto after_2;
    // 0x80154A40: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80154A44: b           L_80154A80
    // 0x80154A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80154A80;
    // 0x80154A48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80154A4C:
    // 0x80154A4C: jal         0x80154D1C
    // 0x80154A50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftNessSpecialHiJibakuSwitchStatusAir(rdram, ctx);
        goto after_3;
    // 0x80154A50: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_3:
    // 0x80154A54: b           L_80154A80
    // 0x80154A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80154A80;
    // 0x80154A58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80154A5C:
    // 0x80154A5C: lhu         $t8, 0xCE($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XCE);
    // 0x80154A60: andi        $t9, $t8, 0x421
    ctx->r25 = ctx->r24 & 0X421;
    // 0x80154A64: beql        $t9, $zero, L_80154A80
    if (ctx->r25 == 0) {
        // 0x80154A68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80154A80;
    }
    goto skip_0;
    // 0x80154A68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80154A6C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80154A70: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80154A74: jal         0x80144498
    // 0x80154A78: swc1        $f4, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f4.u32l;
    ftCommonDownBounceSetStatus(rdram, ctx);
        goto after_4;
    // 0x80154A78: swc1        $f4, 0x60($a1)
    MEM_W(0X60, ctx->r5) = ctx->f4.u32l;
    after_4:
    // 0x80154A7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80154A80:
    // 0x80154A80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80154A84: jr          $ra
    // 0x80154A88: nop

    return;
    // 0x80154A88: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingDestroyHandicapLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801342B8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801342BC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801342C0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801342C4: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x801342C8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801342CC: addiu       $t7, $t7, -0x7AA8
    ctx->r15 = ADD32(ctx->r15, -0X7AA8);
    // 0x801342D0: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x801342D4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x801342D8: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    // 0x801342DC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801342E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801342E4: beq         $a1, $zero, L_801342F8
    if (ctx->r5 == 0) {
        // 0x801342E8: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_801342F8;
    }
    // 0x801342E8: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801342EC: jal         0x80009A84
    // 0x801342F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x801342F0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x801342F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_801342F8:
    // 0x801342F8: lw          $a0, 0x24($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X24);
    // 0x801342FC: beql        $a0, $zero, L_80134314
    if (ctx->r4 == 0) {
        // 0x80134300: lw          $a0, 0x28($v0)
        ctx->r4 = MEM_W(ctx->r2, 0X28);
            goto L_80134314;
    }
    goto skip_0;
    // 0x80134300: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
    skip_0:
    // 0x80134304: jal         0x80009A84
    // 0x80134308: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80134308: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8013430C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80134310: lw          $a0, 0x28($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X28);
L_80134314:
    // 0x80134314: beql        $a0, $zero, L_8013432C
    if (ctx->r4 == 0) {
        // 0x80134318: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013432C;
    }
    goto skip_1;
    // 0x80134318: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013431C: jal         0x80009A84
    // 0x80134320: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    gcEjectGObj(rdram, ctx);
        goto after_2;
    // 0x80134320: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80134324: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80134328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013432C:
    // 0x8013432C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80134330: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x80134334: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x80134338: jr          $ra
    // 0x8013433C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8013433C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void syDebugFramebufferWriteGlyph(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800224C0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800224C4: div         $zero, $a2, $at
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r1)));
    // 0x800224C8: mflo        $t7
    ctx->r15 = lo;
    // 0x800224CC: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x800224D0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800224D4: multu       $t7, $t3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800224D8: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x800224DC: addiu       $t5, $t5, -0x3104
    ctx->r13 = ADD32(ctx->r13, -0X3104);
    // 0x800224E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800224E4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800224E8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800224EC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800224F0: mflo        $t8
    ctx->r24 = lo;
    // 0x800224F4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800224F8: addu        $a3, $t9, $t5
    ctx->r7 = ADD32(ctx->r25, ctx->r13);
    // 0x800224FC: jal         0x80039630
    // 0x80022500: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    osViGetCurrentFramebuffer_recomp(rdram, ctx);
        goto after_0;
    // 0x80022500: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80022504: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80022508: addiu       $t4, $t4, 0x6678
    ctx->r12 = ADD32(ctx->r12, 0X6678);
    // 0x8002250C: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80022510: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80022514: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80022518: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8002251C: multu       $t6, $t7
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80022520: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80022524: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80022528: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8002252C: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x80022530: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80022534: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x80022538: mflo        $t8
    ctx->r24 = lo;
    // 0x8002253C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80022540: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x80022544: addu        $t5, $v0, $t9
    ctx->r13 = ADD32(ctx->r2, ctx->r25);
    // 0x80022548: addu        $v1, $t5, $t7
    ctx->r3 = ADD32(ctx->r13, ctx->r15);
    // 0x8002254C: div         $zero, $t8, $at
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r1)));
    // 0x80022550: mfhi        $t9
    ctx->r25 = hi;
    // 0x80022554: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x80022558: subu        $t6, $t6, $t9
    ctx->r14 = SUB32(ctx->r14, ctx->r25);
    // 0x8002255C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80022560: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x80022564: srlv        $t1, $t5, $t6
    ctx->r9 = S32(U32(ctx->r13) >> (ctx->r14 & 31));
    // 0x80022568: srl         $t2, $t1, 1
    ctx->r10 = S32(U32(ctx->r9) >> 1);
L_8002256C:
    // 0x8002256C: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80022570: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80022574: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80022578: and         $t7, $t1, $a0
    ctx->r15 = ctx->r9 & ctx->r4;
    // 0x8002257C: beq         $t7, $zero, L_8002258C
    if (ctx->r15 == 0) {
        // 0x80022580: and         $t8, $t2, $a0
        ctx->r24 = ctx->r10 & ctx->r4;
            goto L_8002258C;
    }
    // 0x80022580: and         $t8, $t2, $a0
    ctx->r24 = ctx->r10 & ctx->r4;
    // 0x80022584: b           L_80022590
    // 0x80022588: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
        goto L_80022590;
    // 0x80022588: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
L_8002258C:
    // 0x8002258C: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_80022590:
    // 0x80022590: beq         $t8, $zero, L_800225A0
    if (ctx->r24 == 0) {
        // 0x80022594: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800225A0;
    }
    // 0x80022594: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80022598: b           L_800225A4
    // 0x8002259C: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
        goto L_800225A4;
    // 0x8002259C: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
L_800225A0:
    // 0x800225A0: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_800225A4:
    // 0x800225A4: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x800225A8: and         $t9, $v0, $a0
    ctx->r25 = ctx->r2 & ctx->r4;
    // 0x800225AC: beq         $t9, $zero, L_800225BC
    if (ctx->r25 == 0) {
        // 0x800225B0: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800225BC;
    }
    // 0x800225B0: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800225B4: b           L_800225C0
    // 0x800225B8: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
        goto L_800225C0;
    // 0x800225B8: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
L_800225BC:
    // 0x800225BC: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_800225C0:
    // 0x800225C0: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x800225C4: and         $t5, $v0, $a0
    ctx->r13 = ctx->r2 & ctx->r4;
    // 0x800225C8: beq         $t5, $zero, L_800225D8
    if (ctx->r13 == 0) {
        // 0x800225CC: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800225D8;
    }
    // 0x800225CC: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800225D0: b           L_800225DC
    // 0x800225D4: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
        goto L_800225DC;
    // 0x800225D4: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
L_800225D8:
    // 0x800225D8: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_800225DC:
    // 0x800225DC: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x800225E0: and         $t6, $v0, $a0
    ctx->r14 = ctx->r2 & ctx->r4;
    // 0x800225E4: beq         $t6, $zero, L_800225F4
    if (ctx->r14 == 0) {
        // 0x800225E8: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800225F4;
    }
    // 0x800225E8: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800225EC: b           L_800225F8
    // 0x800225F0: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
        goto L_800225F8;
    // 0x800225F0: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
L_800225F4:
    // 0x800225F4: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_800225F8:
    // 0x800225F8: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x800225FC: and         $t7, $v0, $a0
    ctx->r15 = ctx->r2 & ctx->r4;
    // 0x80022600: beq         $t7, $zero, L_80022610
    if (ctx->r15 == 0) {
        // 0x80022604: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_80022610;
    }
    // 0x80022604: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80022608: b           L_80022614
    // 0x8002260C: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
        goto L_80022614;
    // 0x8002260C: sh          $a1, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r5;
L_80022610:
    // 0x80022610: sh          $a2, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r6;
L_80022614:
    // 0x80022614: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x80022618: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x8002261C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80022620: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80022624: addu        $v1, $v1, $t9
    ctx->r3 = ADD32(ctx->r3, ctx->r25);
    // 0x80022628: bne         $t0, $t3, L_8002256C
    if (ctx->r8 != ctx->r11) {
        // 0x8002262C: addiu       $v1, $v1, -0xC
        ctx->r3 = ADD32(ctx->r3, -0XC);
            goto L_8002256C;
    }
    // 0x8002262C: addiu       $v1, $v1, -0xC
    ctx->r3 = ADD32(ctx->r3, -0XC);
    // 0x80022630: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80022634: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80022638: jr          $ra
    // 0x8002263C: nop

    return;
    // 0x8002263C: nop

;}
RECOMP_FUNC void mnVSRecordGetCharacterSpacing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323A4: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x801323A8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x801323AC: addiu       $t7, $t6, -0x27
    ctx->r15 = ADD32(ctx->r14, -0X27);
    // 0x801323B0: sltiu       $at, $t7, 0x33
    ctx->r1 = ctx->r15 < 0X33 ? 1 : 0;
    // 0x801323B4: beq         $at, $zero, L_80132498
    if (ctx->r1 == 0) {
        // 0x801323B8: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80132498;
    }
    // 0x801323B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x801323BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801323C0: addu        $at, $at, $t7
    gpr jr_addend_801323C8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x801323C4: lw          $t7, 0x6AB0($at)
    ctx->r15 = ADD32(ctx->r1, 0X6AB0);
    // 0x801323C8: jr          $t7
    // 0x801323CC: nop

    switch (jr_addend_801323C8 >> 2) {
        case 0: goto L_80132478; break;
        case 1: goto L_80132498; break;
        case 2: goto L_80132498; break;
        case 3: goto L_80132498; break;
        case 4: goto L_80132498; break;
        case 5: goto L_80132498; break;
        case 6: goto L_80132498; break;
        case 7: goto L_80132488; break;
        case 8: goto L_80132498; break;
        case 9: goto L_80132498; break;
        case 10: goto L_80132498; break;
        case 11: goto L_80132498; break;
        case 12: goto L_80132498; break;
        case 13: goto L_80132498; break;
        case 14: goto L_80132498; break;
        case 15: goto L_80132498; break;
        case 16: goto L_80132498; break;
        case 17: goto L_80132498; break;
        case 18: goto L_80132498; break;
        case 19: goto L_80132498; break;
        case 20: goto L_80132498; break;
        case 21: goto L_80132498; break;
        case 22: goto L_80132498; break;
        case 23: goto L_80132498; break;
        case 24: goto L_80132498; break;
        case 25: goto L_80132498; break;
        case 26: goto L_801323D0; break;
        case 27: goto L_80132498; break;
        case 28: goto L_80132498; break;
        case 29: goto L_80132498; break;
        case 30: goto L_80132498; break;
        case 31: goto L_80132414; break;
        case 32: goto L_80132498; break;
        case 33: goto L_80132498; break;
        case 34: goto L_80132498; break;
        case 35: goto L_80132498; break;
        case 36: goto L_80132498; break;
        case 37: goto L_80132498; break;
        case 38: goto L_80132498; break;
        case 39: goto L_80132498; break;
        case 40: goto L_80132498; break;
        case 41: goto L_80132414; break;
        case 42: goto L_80132448; break;
        case 43: goto L_80132498; break;
        case 44: goto L_80132498; break;
        case 45: goto L_80132448; break;
        case 46: goto L_80132498; break;
        case 47: goto L_80132414; break;
        case 48: goto L_80132498; break;
        case 49: goto L_80132498; break;
        case 50: goto L_80132414; break;
        default: switch_error(__func__, 0x801323C8, 0x80136AB0);
    }
    // 0x801323CC: nop

L_801323D0:
    // 0x801323D0: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x801323D4: addiu       $t9, $t8, -0x46
    ctx->r25 = ADD32(ctx->r24, -0X46);
    // 0x801323D8: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x801323DC: beq         $at, $zero, L_80132404
    if (ctx->r1 == 0) {
        // 0x801323E0: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80132404;
    }
    // 0x801323E0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x801323E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801323E8: addu        $at, $at, $t9
    gpr jr_addend_801323F0 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x801323EC: lw          $t9, 0x6B7C($at)
    ctx->r25 = ADD32(ctx->r1, 0X6B7C);
    // 0x801323F0: jr          $t9
    // 0x801323F4: nop

    switch (jr_addend_801323F0 >> 2) {
        case 0: goto L_801323F8; break;
        case 1: goto L_80132404; break;
        case 2: goto L_80132404; break;
        case 3: goto L_80132404; break;
        case 4: goto L_80132404; break;
        case 5: goto L_80132404; break;
        case 6: goto L_80132404; break;
        case 7: goto L_80132404; break;
        case 8: goto L_80132404; break;
        case 9: goto L_80132404; break;
        case 10: goto L_801323F8; break;
        case 11: goto L_80132404; break;
        case 12: goto L_80132404; break;
        case 13: goto L_80132404; break;
        case 14: goto L_801323F8; break;
        case 15: goto L_80132404; break;
        case 16: goto L_801323F8; break;
        case 17: goto L_80132404; break;
        case 18: goto L_80132404; break;
        case 19: goto L_801323F8; break;
        default: switch_error(__func__, 0x801323F0, 0x80136B7C);
    }
    // 0x801323F4: nop

L_801323F8:
    // 0x801323F8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801323FC: jr          $ra
    // 0x80132400: nop

    return;
    // 0x80132400: nop

L_80132404:
    // 0x80132404: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132408: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8013240C: jr          $ra
    // 0x80132410: nop

    return;
    // 0x80132410: nop

L_80132414:
    // 0x80132414: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x80132418: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x8013241C: beq         $v1, $at, L_8013242C
    if (ctx->r3 == ctx->r1) {
        // 0x80132420: addiu       $at, $zero, 0x54
        ctx->r1 = ADD32(0, 0X54);
            goto L_8013242C;
    }
    // 0x80132420: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x80132424: bnel        $v1, $at, L_8013243C
    if (ctx->r3 != ctx->r1) {
        // 0x80132428: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8013243C;
    }
    goto skip_0;
    // 0x80132428: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
L_8013242C:
    // 0x8013242C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80132430: jr          $ra
    // 0x80132434: nop

    return;
    // 0x80132434: nop

    // 0x80132438: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8013243C:
    // 0x8013243C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132440: jr          $ra
    // 0x80132444: nop

    return;
    // 0x80132444: nop

L_80132448:
    // 0x80132448: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x8013244C: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80132450: beq         $v1, $at, L_8013245C
    if (ctx->r3 == ctx->r1) {
        // 0x80132454: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_8013245C;
    }
    // 0x80132454: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80132458: bne         $v1, $at, L_8013246C
    if (ctx->r3 != ctx->r1) {
        // 0x8013245C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8013246C;
    }
L_8013245C:
    // 0x8013245C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132460: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132464: jr          $ra
    // 0x80132468: nop

    return;
    // 0x80132468: nop

L_8013246C:
    // 0x8013246C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80132470: jr          $ra
    // 0x80132474: nop

    return;
    // 0x80132474: nop

L_80132478:
    // 0x80132478: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013247C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132480: jr          $ra
    // 0x80132484: nop

    return;
    // 0x80132484: nop

L_80132488:
    // 0x80132488: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8013248C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132490: jr          $ra
    // 0x80132494: nop

    return;
    // 0x80132494: nop

L_80132498:
    // 0x80132498: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x8013249C: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x801324A0: bnel        $t0, $at, L_801324B8
    if (ctx->r8 != ctx->r1) {
        // 0x801324A4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_801324B8;
    }
    goto skip_1;
    // 0x801324A4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x801324A8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801324AC: jr          $ra
    // 0x801324B0: nop

    return;
    // 0x801324B0: nop

    // 0x801324B4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_801324B8:
    // 0x801324B8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801324BC: nop

    // 0x801324C0: jr          $ra
    // 0x801324C4: nop

    return;
    // 0x801324C4: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirLwLoopProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EE4C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015EE50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015EE54: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015EE58: lw          $a1, 0x9C8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X9C8);
    // 0x8015EE5C: jal         0x800D8FA8
    // 0x8015EE60: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_0;
    // 0x8015EE60: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015EE64: bne         $v0, $zero, L_8015EE74
    if (ctx->r2 != 0) {
        // 0x8015EE68: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_8015EE74;
    }
    // 0x8015EE68: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8015EE6C: jal         0x800D9074
    // 0x8015EE70: lw          $a1, 0x9C8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X9C8);
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_1;
    // 0x8015EE70: lw          $a1, 0x9C8($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X9C8);
    after_1:
L_8015EE74:
    // 0x8015EE74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015EE78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015EE7C: jr          $ra
    // 0x8015EE80: nop

    return;
    // 0x8015EE80: nop

;}
RECOMP_FUNC void alCSPSetBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FBD0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002FBD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FBD8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x8002FBDC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8002FBE0: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x8002FBE4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x8002FBE8: addiu       $a0, $a0, 0x50
    ctx->r4 = ADD32(ctx->r4, 0X50);
    // 0x8002FBEC: jal         0x80028D70
    // 0x8002FBF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x8002FBF0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8002FBF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FBF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8002FBFC: jr          $ra
    // 0x8002FC00: nop

    return;
    // 0x8002FC00: nop

;}
RECOMP_FUNC void func_ovl8_803846F8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803846F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803846FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384700: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80384704: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80384708: lh          $t6, 0xD0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XD0);
    // 0x8038470C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80384710: lw          $t9, 0xD4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XD4);
    // 0x80384714: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x80384718: jalr        $t9
    // 0x8038471C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8038471C: nop

    after_0:
    // 0x80384720: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80384724: lw          $v0, 0x30($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X30);
    // 0x80384728: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x8038472C: lh          $t7, 0x10($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X10);
    // 0x80384730: jalr        $t9
    // 0x80384734: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80384734: addu        $a0, $t7, $a2
    ctx->r4 = ADD32(ctx->r15, ctx->r6);
    after_1:
    // 0x80384738: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8038473C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80384740: jr          $ra
    // 0x80384744: nop

    return;
    // 0x80384744: nop

;}
RECOMP_FUNC void mvOpeningLinkFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DE48: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DE4C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018DE50: addiu       $a0, $a0, -0x1C18
    ctx->r4 = ADD32(ctx->r4, -0X1C18);
    // 0x8018DE54: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018DE58: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018DE5C: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018DE60: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018DE64: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DE68: addiu       $v1, $zero, 0x4
    ctx->r3 = ADD32(0, 0X4);
    // 0x8018DE6C: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018DE70: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_8018DE74:
    // 0x8018DE74: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DE78: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DE7C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DE80: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DE84: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DE88: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DE8C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DE90: bne         $t6, $t0, L_8018DE74
    if (ctx->r14 != ctx->r8) {
        // 0x8018DE94: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DE74;
    }
    // 0x8018DE94: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DE98: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DE9C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DEA0: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8018DEA4: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DEA8: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x8018DEAC: sb          $v1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r3;
    // 0x8018DEB0: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
    // 0x8018DEB4: sb          $t3, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r11;
    // 0x8018DEB8: sb          $t5, 0x23($a0)
    MEM_B(0X23, ctx->r4) = ctx->r13;
    // 0x8018DEBC: jal         0x8018D0C0
    // 0x8018DEC0: sb          $v1, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r3;
    mvOpeningLinkSetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018DEC0: sb          $v1, 0x22($a0)
    MEM_B(0X22, ctx->r4) = ctx->r3;
    after_0:
    // 0x8018DEC4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DEC8: addiu       $a1, $a1, -0x2280
    ctx->r5 = ADD32(ctx->r5, -0X2280);
    // 0x8018DECC: addiu       $a0, $zero, 0x3F7
    ctx->r4 = ADD32(0, 0X3F7);
    // 0x8018DED0: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    // 0x8018DED4: jal         0x80009968
    // 0x8018DED8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8018DED8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018DEDC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8018DEE0: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018DEE4: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018DEE8: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x8018DEEC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018DEF0: jal         0x8000B9FC
    // 0x8018DEF4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018DEF4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    after_2:
    // 0x8018DEF8: jal         0x8018DE3C
    // 0x8018DEFC: nop

    mvOpeningLinkInitVars(rdram, ctx);
        goto after_3;
    // 0x8018DEFC: nop

    after_3:
    // 0x8018DF00: jal         0x80115890
    // 0x8018DF04: nop

    efParticleInitAll(rdram, ctx);
        goto after_4;
    // 0x8018DF04: nop

    after_4:
    // 0x8018DF08: jal         0x800EC130
    // 0x8018DF0C: nop

    ftParamInitGame(rdram, ctx);
        goto after_5;
    // 0x8018DF0C: nop

    after_5:
    // 0x8018DF10: jal         0x800FC284
    // 0x8018DF14: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_6;
    // 0x8018DF14: nop

    after_6:
    // 0x8018DF18: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018DF1C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018DF20: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018DF24: jal         0x8010E598
    // 0x8018DF28: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_7;
    // 0x8018DF28: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_7:
    // 0x8018DF2C: jal         0x8010DB54
    // 0x8018DF30: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_8;
    // 0x8018DF30: nop

    after_8:
    // 0x8018DF34: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018DF38: jal         0x800D7194
    // 0x8018DF3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftManagerAllocFighter(rdram, ctx);
        goto after_9;
    // 0x8018DF3C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_9:
    // 0x8018DF40: jal         0x801654B0
    // 0x8018DF44: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_10;
    // 0x8018DF44: nop

    after_10:
    // 0x8018DF48: jal         0x8016DEA0
    // 0x8018DF4C: nop

    itManagerInitItems(rdram, ctx);
        goto after_11;
    // 0x8018DF4C: nop

    after_11:
    // 0x8018DF50: jal         0x800FD300
    // 0x8018DF54: nop

    efManagerInitEffects(rdram, ctx);
        goto after_12;
    // 0x8018DF54: nop

    after_12:
    // 0x8018DF58: jal         0x800D786C
    // 0x8018DF5C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_13;
    // 0x8018DF5C: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_13:
    // 0x8018DF60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8018DF64: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x8018DF68: jal         0x80004980
    // 0x8018DF6C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_14;
    // 0x8018DF6C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_14:
    // 0x8018DF70: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DF74: jal         0x8018DB40
    // 0x8018DF78: sw          $v0, -0x1E24($at)
    MEM_W(-0X1E24, ctx->r1) = ctx->r2;
    mvOpeningLinkMakeNameCamera(rdram, ctx);
        goto after_15;
    // 0x8018DF78: sw          $v0, -0x1E24($at)
    MEM_W(-0X1E24, ctx->r1) = ctx->r2;
    after_15:
    // 0x8018DF7C: jal         0x8018DCD0
    // 0x8018DF80: nop

    mvOpeningLinkMakePosedWallpaperCamera(rdram, ctx);
        goto after_16;
    // 0x8018DF80: nop

    after_16:
    // 0x8018DF84: jal         0x8018DBE0
    // 0x8018DF88: nop

    mvOpeningLinkMakePosedFighterCamera(rdram, ctx);
        goto after_17;
    // 0x8018DF88: nop

    after_17:
    // 0x8018DF8C: jal         0x8018D194
    // 0x8018DF90: nop

    mvOpeningLinkMakeName(rdram, ctx);
        goto after_18;
    // 0x8018DF90: nop

    after_18:
    // 0x8018DF94: jal         0x8000092C
    // 0x8018DF98: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_19;
    // 0x8018DF98: nop

    after_19:
    // 0x8018DF9C: sltiu       $at, $v0, 0x69F
    ctx->r1 = ctx->r2 < 0X69F ? 1 : 0;
    // 0x8018DFA0: beql        $at, $zero, L_8018DFC0
    if (ctx->r1 == 0) {
        // 0x8018DFA4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8018DFC0;
    }
    goto skip_0;
    // 0x8018DFA4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
L_8018DFA8:
    // 0x8018DFA8: jal         0x8000092C
    // 0x8018DFAC: nop

    sySchedulerGetTicCount(rdram, ctx);
        goto after_20;
    // 0x8018DFAC: nop

    after_20:
    // 0x8018DFB0: sltiu       $at, $v0, 0x69F
    ctx->r1 = ctx->r2 < 0X69F ? 1 : 0;
    // 0x8018DFB4: bne         $at, $zero, L_8018DFA8
    if (ctx->r1 != 0) {
        // 0x8018DFB8: nop
    
            goto L_8018DFA8;
    }
    // 0x8018DFB8: nop

    // 0x8018DFBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8018DFC0:
    // 0x8018DFC0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018DFC4: jr          $ra
    // 0x8018DFC8: nop

    return;
    // 0x8018DFC8: nop

;}
RECOMP_FUNC void ftNessSpecialHiJibakuSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154D1C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80154D20: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80154D24: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80154D28: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80154D2C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80154D30: jal         0x800DEEC8
    // 0x80154D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80154D34: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80154D38: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80154D3C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80154D40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80154D44: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80154D48: addiu       $a1, $zero, 0xEC
    ctx->r5 = ADD32(0, 0XEC);
    // 0x80154D4C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80154D50: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x80154D54: addiu       $t7, $zero, 0x93
    ctx->r15 = ADD32(0, 0X93);
    // 0x80154D58: bc1fl       L_80154D6C
    if (!c1cs) {
        // 0x80154D5C: mfc1        $a2, $f0
        ctx->r6 = (int32_t)ctx->f0.u32l;
            goto L_80154D6C;
    }
    goto skip_0;
    // 0x80154D5C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    skip_0:
    // 0x80154D60: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80154D64: nop

    // 0x80154D68: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
L_80154D6C:
    // 0x80154D6C: jal         0x800E6F24
    // 0x80154D70: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80154D70: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_1:
    // 0x80154D74: lw          $t8, 0x44($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X44);
    // 0x80154D78: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80154D7C: lwc1        $f12, 0x4C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80154D80: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80154D84: nop

    // 0x80154D88: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80154D8C: mul.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80154D90: jal         0x8001863C
    // 0x80154D94: nop

    syUtilsArcTan2(rdram, ctx);
        goto after_2;
    // 0x80154D94: nop

    after_2:
    // 0x80154D98: lw          $t9, 0x9C8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X9C8);
    // 0x80154D9C: swc1        $f0, 0xB2C($s0)
    MEM_W(0XB2C, ctx->r16) = ctx->f0.u32l;
    // 0x80154DA0: lw          $t0, 0x64($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X64);
    // 0x80154DA4: sb          $t0, 0x148($s0)
    MEM_B(0X148, ctx->r16) = ctx->r8;
    // 0x80154DA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80154DAC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80154DB0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80154DB4: jr          $ra
    // 0x80154DB8: nop

    return;
    // 0x80154DB8: nop

;}
RECOMP_FUNC void func_ovl8_80371930(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371930: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371938: lw          $v0, 0x58($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X58);
    // 0x8037193C: sw          $zero, 0x20($a0)
    MEM_W(0X20, ctx->r4) = 0;
    // 0x80371940: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80371944: lh          $t6, 0x28($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X28);
    // 0x80371948: jalr        $t9
    // 0x8037194C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037194C: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80371950: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371954: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371958: jr          $ra
    // 0x8037195C: nop

    return;
    // 0x8037195C: nop

;}
RECOMP_FUNC void func_ovl8_8038599C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038599C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x803859A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803859A4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x803859A8: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x803859AC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x803859B0: lh          $t6, 0x48($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X48);
    // 0x803859B4: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x803859B8: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    // 0x803859BC: jalr        $t9
    // 0x803859C0: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803859C0: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_0:
    // 0x803859C4: beq         $v0, $zero, L_80385A08
    if (ctx->r2 == 0) {
        // 0x803859C8: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_80385A08;
    }
    // 0x803859C8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x803859CC: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x803859D0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x803859D4: lh          $t7, 0x20($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X20);
    // 0x803859D8: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x803859DC: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    // 0x803859E0: jalr        $t9
    // 0x803859E4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x803859E4: addiu       $a0, $a0, 0x40
    ctx->r4 = ADD32(ctx->r4, 0X40);
    after_1:
    // 0x803859E8: lw          $a2, 0x38($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X38);
    // 0x803859EC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x803859F0: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x803859F4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x803859F8: jal         0x80377AEC
    // 0x803859FC: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    func_ovl8_80377AEC(rdram, ctx);
        goto after_2;
    // 0x803859FC: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    after_2:
    // 0x80385A00: jal         0x80382354
    // 0x80385A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_ovl8_80382354(rdram, ctx);
        goto after_3;
    // 0x80385A04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80385A08:
    // 0x80385A08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80385A0C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80385A10: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80385A14: jr          $ra
    // 0x80385A18: nop

    return;
    // 0x80385A18: nop

;}
RECOMP_FUNC void ftCommonItemSwingSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146E94: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80146E98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80146E9C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80146EA0: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x80146EA4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80146EA8: lw          $t6, 0x84C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X84C);
    // 0x80146EAC: lw          $v1, 0x84($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X84);
    // 0x80146EB0: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80146EB4: beq         $v0, $at, L_80146EE4
    if (ctx->r2 == ctx->r1) {
        // 0x80146EB8: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_80146EE4;
    }
    // 0x80146EB8: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80146EBC: beq         $v0, $at, L_80146EEC
    if (ctx->r2 == ctx->r1) {
        // 0x80146EC0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80146EEC;
    }
    // 0x80146EC0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80146EC4: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80146EC8: beq         $v0, $at, L_80146EF4
    if (ctx->r2 == ctx->r1) {
        // 0x80146ECC: addiu       $t8, $zero, 0x2
        ctx->r24 = ADD32(0, 0X2);
            goto L_80146EF4;
    }
    // 0x80146ECC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80146ED0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80146ED4: beq         $v0, $at, L_80146EFC
    if (ctx->r2 == ctx->r1) {
        // 0x80146ED8: addiu       $t9, $zero, 0x3
        ctx->r25 = ADD32(0, 0X3);
            goto L_80146EFC;
    }
    // 0x80146ED8: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80146EDC: b           L_80146F04
    // 0x80146EE0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
        goto L_80146F04;
    // 0x80146EE0: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80146EE4:
    // 0x80146EE4: b           L_80146F00
    // 0x80146EE8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
        goto L_80146F00;
    // 0x80146EE8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
L_80146EEC:
    // 0x80146EEC: b           L_80146F00
    // 0x80146EF0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
        goto L_80146F00;
    // 0x80146EF0: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
L_80146EF4:
    // 0x80146EF4: b           L_80146F00
    // 0x80146EF8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
        goto L_80146F00;
    // 0x80146EF8: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
L_80146EFC:
    // 0x80146EFC: sw          $t9, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r25;
L_80146F00:
    // 0x80146F00: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
L_80146F04:
    // 0x80146F04: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x80146F08: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80146F0C: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80146F10: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80146F14: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x80146F18: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x80146F1C: lw          $a1, -0x79E8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X79E8);
    // 0x80146F20: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80146F24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80146F28: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80146F2C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80146F30: lw          $t7, -0x37C0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X37C0);
    // 0x80146F34: srl         $t8, $t7, 22
    ctx->r24 = S32(U32(ctx->r15) >> 22);
    // 0x80146F38: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80146F3C: bgez        $t8, L_80146F50
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80146F40: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80146F50;
    }
    // 0x80146F40: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80146F44: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80146F48: nop

    // 0x80146F4C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80146F50:
    // 0x80146F50: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80146F54: lwc1        $f10, -0x3E40($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3E40);
    // 0x80146F58: sw          $zero, 0x17C($t0)
    MEM_W(0X17C, ctx->r8) = 0;
    // 0x80146F5C: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    // 0x80146F60: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80146F64: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80146F68: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80146F6C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80146F70: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80146F74: jal         0x800E6F24
    // 0x80146F78: nop

    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80146F78: nop

    after_0:
    // 0x80146F7C: jal         0x800E0830
    // 0x80146F80: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80146F80: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80146F84: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80146F88: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80146F8C: addiu       $t9, $t9, 0x6C40
    ctx->r25 = ADD32(ctx->r25, 0X6C40);
    // 0x80146F90: sw          $t9, 0x9F8($t0)
    MEM_W(0X9F8, ctx->r8) = ctx->r25;
    // 0x80146F94: sw          $zero, 0xB18($t0)
    MEM_W(0XB18, ctx->r8) = 0;
    // 0x80146F98: sw          $zero, 0x180($t0)
    MEM_W(0X180, ctx->r8) = 0;
    // 0x80146F9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80146FA0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80146FA4: jr          $ra
    // 0x80146FA8: nop

    return;
    // 0x80146FA8: nop

;}
RECOMP_FUNC void ftKirbySpecialNThrowSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162CE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162CE4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162CE8: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162CEC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162CF0: jal         0x800DEEC8
    // 0x80162CF4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x80162CF4: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162CF8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162CFC: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162D00: addiu       $a1, $zero, 0x11B
    ctx->r5 = ADD32(0, 0X11B);
    // 0x80162D04: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162D08: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162D0C: jal         0x800E6F24
    // 0x80162D10: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162D10: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162D14: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162D18: jal         0x800E8098
    // 0x80162D1C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162D1C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162D20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162D24: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162D28: jr          $ra
    // 0x80162D2C: nop

    return;
    // 0x80162D2C: nop

;}
RECOMP_FUNC void mvOpeningPikachuMakePosedWallpaperCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DD10: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DD14: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DD18: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DD1C: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DD20: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x8018DD24: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DD28: lui         $t9, 0x1000
    ctx->r25 = S32(0X1000 << 16);
    // 0x8018DD2C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DD30: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DD34: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DD38: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DD3C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DD40: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DD44: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DD48: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DD4C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DD50: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DD54: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DD58: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DD5C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DD60: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DD64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DD68: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DD6C: jal         0x8000B93C
    // 0x8018DD70: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DD70: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DD74: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DD78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DD7C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DD80: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DD84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DD88: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DD8C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DD90: lui         $a3, 0x42DC
    ctx->r7 = S32(0X42DC << 16);
    // 0x8018DD94: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DD98: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8018DD9C: jal         0x80007080
    // 0x8018DDA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DDA0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DDA4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8018DDA8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8018DDAC: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x8018DDB0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DDB4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DDB8: jr          $ra
    // 0x8018DDBC: nop

    return;
    // 0x8018DDBC: nop

;}
RECOMP_FUNC void ftComputerFollowObjectiveEvade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013834C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80138350: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80138354: jal         0x801366F0
    // 0x80138358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftComputerCheckSetEvadeTarget(rdram, ctx);
        goto after_0;
    // 0x80138358: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013835C: beql        $v0, $zero, L_80138370
    if (ctx->r2 == 0) {
        // 0x80138360: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80138370;
    }
    goto skip_0;
    // 0x80138360: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80138364: jal         0x80134E98
    // 0x80138368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftComputerFollowObjectiveWalk(rdram, ctx);
        goto after_1;
    // 0x80138368: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013836C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80138370:
    // 0x80138370: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80138374: jr          $ra
    // 0x80138378: nop

    return;
    // 0x80138378: nop

;}
RECOMP_FUNC void dbCubeAudioThreadUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131D00: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80131D04: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80131D08: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80131D0C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80131D10: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80131D14: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131D18: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x80131D1C: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80131D20: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80131D24: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x80131D28: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x80131D2C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80131D30: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80131D34: addiu       $s4, $s4, 0x2D34
    ctx->r20 = ADD32(ctx->r20, 0X2D34);
    // 0x80131D38: addiu       $s3, $s3, 0x2D48
    ctx->r19 = ADD32(ctx->r19, 0X2D48);
    // 0x80131D3C: addiu       $s2, $s2, 0x2D50
    ctx->r18 = ADD32(ctx->r18, 0X2D50);
    // 0x80131D40: addiu       $s1, $s1, 0x2D3C
    ctx->r17 = ADD32(ctx->r17, 0X2D3C);
    // 0x80131D44: addiu       $s0, $s0, 0x2D4C
    ctx->r16 = ADD32(ctx->r16, 0X2D4C);
    // 0x80131D48: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
L_80131D4C:
    // 0x80131D4C: beql        $t6, $zero, L_80131D74
    if (ctx->r14 == 0) {
        // 0x80131D50: lw          $v1, 0x0($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X0);
            goto L_80131D74;
    }
    goto skip_0;
    // 0x80131D50: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    skip_0:
    // 0x80131D54: jal         0x80021048
    // 0x80131D58: nop

    syAudioGetRestarting(rdram, ctx);
        goto after_0;
    // 0x80131D58: nop

    after_0:
    // 0x80131D5C: bne         $v0, $zero, L_80131D70
    if (ctx->r2 != 0) {
        // 0x80131D60: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80131D70;
    }
    // 0x80131D60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131D64: jal         0x80020AB4
    // 0x80131D68: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    syAudioPlayBGM(rdram, ctx);
        goto after_1;
    // 0x80131D68: lw          $a1, 0x0($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X0);
    after_1:
    // 0x80131D6C: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
L_80131D70:
    // 0x80131D70: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
L_80131D74:
    // 0x80131D74: beql        $v1, $zero, L_80131D98
    if (ctx->r3 == 0) {
        // 0x80131D78: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_80131D98;
    }
    goto skip_1;
    // 0x80131D78: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x80131D7C: lhu         $v0, 0x26($v1)
    ctx->r2 = MEM_HU(ctx->r3, 0X26);
    // 0x80131D80: beql        $v0, $zero, L_80131D98
    if (ctx->r2 == 0) {
        // 0x80131D84: lw          $v0, 0x0($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X0);
            goto L_80131D98;
    }
    goto skip_2;
    // 0x80131D84: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    skip_2:
    // 0x80131D88: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80131D8C: beq         $t7, $v0, L_80131DBC
    if (ctx->r15 == ctx->r2) {
        // 0x80131D90: nop
    
            goto L_80131DBC;
    }
    // 0x80131D90: nop

    // 0x80131D94: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
L_80131D98:
    // 0x80131D98: beq         $v0, $zero, L_80131DBC
    if (ctx->r2 == 0) {
        // 0x80131D9C: nop
    
            goto L_80131DBC;
    }
    // 0x80131D9C: nop

    // 0x80131DA0: jal         0x800269C0
    // 0x80131DA4: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80131DA4: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_2:
    // 0x80131DA8: beq         $v0, $zero, L_80131DBC
    if (ctx->r2 == 0) {
        // 0x80131DAC: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80131DBC;
    }
    // 0x80131DAC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80131DB0: lhu         $t8, 0x26($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X26);
    // 0x80131DB4: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x80131DB8: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
L_80131DBC:
    // 0x80131DBC: jal         0x8000B1E8
    // 0x80131DC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_3;
    // 0x80131DC0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x80131DC4: b           L_80131D4C
    // 0x80131DC8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
        goto L_80131D4C;
    // 0x80131DC8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x80131DCC: nop

    // 0x80131DD0: nop

    // 0x80131DD4: nop

    // 0x80131DD8: nop

    // 0x80131DDC: nop

    // 0x80131DE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80131DE4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131DE8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80131DEC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80131DF0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80131DF4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80131DF8: jr          $ra
    // 0x80131DFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80131DFC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mvOpeningSamusMakePosedFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DAC8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018DACC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018DAD0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018DAD4: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x8018DAD8: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x8018DADC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DAE0: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8018DAE4: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
L_8018DAE8:
    // 0x8018DAE8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAEC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DAF0: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DAF4: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DAF8: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DAFC: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DB00: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DB04: bne         $t6, $t0, L_8018DAE8
    if (ctx->r14 != ctx->r8) {
        // 0x8018DB08: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DAE8;
    }
    // 0x8018DB08: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DB0C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DB10: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x8018DB14: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018DB18: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DB1C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DB20: jal         0x800EC0EC
    // 0x8018DB24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8018DB24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8018DB28: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DB2C: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018DB30: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8018DB34: lw          $t2, -0x1D74($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1D74);
    // 0x8018DB38: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DB3C: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8018DB40: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB44: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018DB48: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8018DB4C: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8018DB50: jal         0x800D7F3C
    // 0x8018DB54: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x8018DB54: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DB58: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8018DB5C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DB60: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x8018DB64: jal         0x803905CC
    // 0x8018DB68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x8018DB68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8018DB6C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB70: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8018DB74: jal         0x8000A0D0
    // 0x8018DB78: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x8018DB78: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x8018DB7C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DB80: addiu       $a1, $a1, -0x2608
    ctx->r5 = ADD32(ctx->r5, -0X2608);
    // 0x8018DB84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB88: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DB8C: jal         0x80008188
    // 0x8018DB90: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8018DB90: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8018DB94: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DB98: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DB9C: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8018DBA0: swc1        $f0, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f0.u32l;
    // 0x8018DBA4: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8018DBA8: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x8018DBAC: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8018DBB0: swc1        $f0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f0.u32l;
    // 0x8018DBB4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DBB8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018DBBC: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018DBC0: jr          $ra
    // 0x8018DBC4: nop

    return;
    // 0x8018DBC4: nop

;}
RECOMP_FUNC void scStaffrollMakeStaffRoleTextSObjs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BB8: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132BBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132BC0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80132BC4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80132BC8: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80132BCC: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x80132BD0: lw          $v1, 0x84($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X84);
    // 0x80132BD4: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80132BD8: addiu       $t8, $t8, -0x6498
    ctx->r24 = ADD32(ctx->r24, -0X6498);
    // 0x80132BDC: lw          $t6, 0x4($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X4);
    // 0x80132BE0: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80132BE4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132BE8: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80132BEC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80132BF0: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80132BF4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80132BF8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80132BFC: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x80132C00: blez        $t0, L_80132E5C
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80132C04: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80132E5C;
    }
    // 0x80132C04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132C08: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x80132C0C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132C10: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80132C14: addiu       $t1, $t1, 0x6BA0
    ctx->r9 = ADD32(ctx->r9, 0X6BA0);
    // 0x80132C18: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80132C1C: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80132C20: addiu       $s1, $s1, -0x5CB8
    ctx->r17 = ADD32(ctx->r17, -0X5CB8);
    // 0x80132C24: addu        $v1, $t9, $t1
    ctx->r3 = ADD32(ctx->r25, ctx->r9);
    // 0x80132C28: addiu       $a3, $zero, -0x21
    ctx->r7 = ADD32(0, -0X21);
L_80132C2C:
    // 0x80132C2C: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x80132C30: addiu       $at, $zero, -0x37
    ctx->r1 = ADD32(0, -0X37);
    // 0x80132C34: beq         $a3, $s0, L_80132E2C
    if (ctx->r7 == ctx->r16) {
        // 0x80132C38: nop
    
            goto L_80132E2C;
    }
    // 0x80132C38: nop

    // 0x80132C3C: beq         $s0, $at, L_80132E2C
    if (ctx->r16 == ctx->r1) {
        // 0x80132C40: lw          $a0, 0x50($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X50);
            goto L_80132E2C;
    }
    // 0x80132C40: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x80132C44: sll         $t2, $s0, 3
    ctx->r10 = S32(ctx->r16 << 3);
    // 0x80132C48: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80132C4C: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80132C50: lui         $t5, 0x8014
    ctx->r13 = S32(0X8014 << 16);
    // 0x80132C54: lw          $t5, -0x55F0($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X55F0);
    // 0x80132C58: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80132C5C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    // 0x80132C60: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80132C64: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80132C68: sw          $a2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r6;
    // 0x80132C6C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80132C70: jal         0x800CCFDC
    // 0x80132C74: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132C74: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_0:
    // 0x80132C78: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80132C7C: lwc1        $f0, 0x38($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80132C80: lw          $a2, 0x44($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X44);
    // 0x80132C84: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80132C88: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80132C8C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132C90: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80132C94: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80132C98: addiu       $t7, $zero, 0xB7
    ctx->r15 = ADD32(0, 0XB7);
    // 0x80132C9C: addiu       $t8, $zero, 0xBC
    ctx->r24 = ADD32(0, 0XBC);
    // 0x80132CA0: addiu       $t9, $zero, 0xEC
    ctx->r25 = ADD32(0, 0XEC);
    // 0x80132CA4: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80132CA8: sb          $t7, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r15;
    // 0x80132CAC: sb          $t8, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r24;
    // 0x80132CB0: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x80132CB4: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132CB8: swc1        $f12, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f12.u32l;
    // 0x80132CBC: swc1        $f12, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f12.u32l;
    // 0x80132CC0: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x80132CC4: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80132CC8: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x80132CCC: slti        $at, $s0, 0x1A
    ctx->r1 = SIGNED(ctx->r16) < 0X1A ? 1 : 0;
    // 0x80132CD0: bne         $at, $zero, L_80132DA8
    if (ctx->r1 != 0) {
        // 0x80132CD4: addiu       $a3, $zero, -0x21
        ctx->r7 = ADD32(0, -0X21);
            goto L_80132DA8;
    }
    // 0x80132CD4: addiu       $a3, $zero, -0x21
    ctx->r7 = ADD32(0, -0X21);
    // 0x80132CD8: addiu       $at, $zero, 0x1B
    ctx->r1 = ADD32(0, 0X1B);
    // 0x80132CDC: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132CE0: mov.s       $f20, $f14
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
            goto L_80132D9C;
    }
    // 0x80132CE0: mov.s       $f20, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    ctx->f20.fl = ctx->f14.fl;
    // 0x80132CE4: addiu       $at, $zero, 0x1D
    ctx->r1 = ADD32(0, 0X1D);
    // 0x80132CE8: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132CEC: addiu       $at, $zero, 0x1F
        ctx->r1 = ADD32(0, 0X1F);
            goto L_80132D9C;
    }
    // 0x80132CEC: addiu       $at, $zero, 0x1F
    ctx->r1 = ADD32(0, 0X1F);
    // 0x80132CF0: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132CF4: addiu       $at, $zero, 0x21
        ctx->r1 = ADD32(0, 0X21);
            goto L_80132D9C;
    }
    // 0x80132CF4: addiu       $at, $zero, 0x21
    ctx->r1 = ADD32(0, 0X21);
    // 0x80132CF8: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132CFC: addiu       $at, $zero, 0x22
        ctx->r1 = ADD32(0, 0X22);
            goto L_80132D9C;
    }
    // 0x80132CFC: addiu       $at, $zero, 0x22
    ctx->r1 = ADD32(0, 0X22);
    // 0x80132D00: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D04: addiu       $at, $zero, 0x23
        ctx->r1 = ADD32(0, 0X23);
            goto L_80132D9C;
    }
    // 0x80132D04: addiu       $at, $zero, 0x23
    ctx->r1 = ADD32(0, 0X23);
    // 0x80132D08: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D0C: addiu       $at, $zero, 0x24
        ctx->r1 = ADD32(0, 0X24);
            goto L_80132D9C;
    }
    // 0x80132D0C: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80132D10: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D14: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_80132D9C;
    }
    // 0x80132D14: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80132D18: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D1C: addiu       $at, $zero, 0x2D
        ctx->r1 = ADD32(0, 0X2D);
            goto L_80132D9C;
    }
    // 0x80132D1C: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80132D20: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D24: addiu       $at, $zero, 0x34
        ctx->r1 = ADD32(0, 0X34);
            goto L_80132D9C;
    }
    // 0x80132D24: addiu       $at, $zero, 0x34
    ctx->r1 = ADD32(0, 0X34);
    // 0x80132D28: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D2C: addiu       $at, $zero, 0x35
        ctx->r1 = ADD32(0, 0X35);
            goto L_80132D9C;
    }
    // 0x80132D2C: addiu       $at, $zero, 0x35
    ctx->r1 = ADD32(0, 0X35);
    // 0x80132D30: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D34: addiu       $at, $zero, 0x36
        ctx->r1 = ADD32(0, 0X36);
            goto L_80132D9C;
    }
    // 0x80132D34: addiu       $at, $zero, 0x36
    ctx->r1 = ADD32(0, 0X36);
    // 0x80132D38: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D3C: addiu       $at, $zero, 0x37
        ctx->r1 = ADD32(0, 0X37);
            goto L_80132D9C;
    }
    // 0x80132D3C: addiu       $at, $zero, 0x37
    ctx->r1 = ADD32(0, 0X37);
    // 0x80132D40: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D44: addiu       $at, $zero, 0x38
        ctx->r1 = ADD32(0, 0X38);
            goto L_80132D9C;
    }
    // 0x80132D44: addiu       $at, $zero, 0x38
    ctx->r1 = ADD32(0, 0X38);
    // 0x80132D48: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D4C: addiu       $at, $zero, 0x39
        ctx->r1 = ADD32(0, 0X39);
            goto L_80132D9C;
    }
    // 0x80132D4C: addiu       $at, $zero, 0x39
    ctx->r1 = ADD32(0, 0X39);
    // 0x80132D50: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D54: addiu       $at, $zero, 0x3A
        ctx->r1 = ADD32(0, 0X3A);
            goto L_80132D9C;
    }
    // 0x80132D54: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x80132D58: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D5C: addiu       $at, $zero, 0x3B
        ctx->r1 = ADD32(0, 0X3B);
            goto L_80132D9C;
    }
    // 0x80132D5C: addiu       $at, $zero, 0x3B
    ctx->r1 = ADD32(0, 0X3B);
    // 0x80132D60: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D64: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_80132D9C;
    }
    // 0x80132D64: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    // 0x80132D68: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D6C: addiu       $at, $zero, 0x3D
        ctx->r1 = ADD32(0, 0X3D);
            goto L_80132D9C;
    }
    // 0x80132D6C: addiu       $at, $zero, 0x3D
    ctx->r1 = ADD32(0, 0X3D);
    // 0x80132D70: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D74: addiu       $at, $zero, 0x3E
        ctx->r1 = ADD32(0, 0X3E);
            goto L_80132D9C;
    }
    // 0x80132D74: addiu       $at, $zero, 0x3E
    ctx->r1 = ADD32(0, 0X3E);
    // 0x80132D78: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D7C: addiu       $at, $zero, 0x42
        ctx->r1 = ADD32(0, 0X42);
            goto L_80132D9C;
    }
    // 0x80132D7C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x80132D80: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D84: addiu       $at, $zero, 0x46
        ctx->r1 = ADD32(0, 0X46);
            goto L_80132D9C;
    }
    // 0x80132D84: addiu       $at, $zero, 0x46
    ctx->r1 = ADD32(0, 0X46);
    // 0x80132D88: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D8C: addiu       $at, $zero, 0x49
        ctx->r1 = ADD32(0, 0X49);
            goto L_80132D9C;
    }
    // 0x80132D8C: addiu       $at, $zero, 0x49
    ctx->r1 = ADD32(0, 0X49);
    // 0x80132D90: beq         $s0, $at, L_80132D9C
    if (ctx->r16 == ctx->r1) {
        // 0x80132D94: addiu       $at, $zero, 0x43
        ctx->r1 = ADD32(0, 0X43);
            goto L_80132D9C;
    }
    // 0x80132D94: addiu       $at, $zero, 0x43
    ctx->r1 = ADD32(0, 0X43);
    // 0x80132D98: bne         $s0, $at, L_80132DA8
    if (ctx->r16 != ctx->r1) {
        // 0x80132D9C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80132DA8;
    }
L_80132D9C:
    // 0x80132D9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80132DA0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80132DA4: nop

L_80132DA8:
    // 0x80132DA8: addiu       $at, $zero, 0x3F
    ctx->r1 = ADD32(0, 0X3F);
    // 0x80132DAC: bne         $s0, $at, L_80132DC0
    if (ctx->r16 != ctx->r1) {
        // 0x80132DB0: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80132DC0;
    }
    // 0x80132DB0: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80132DB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132DB8: nop

    // 0x80132DBC: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
L_80132DC0:
    // 0x80132DC0: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x80132DC4: bne         $s0, $at, L_80132DD8
    if (ctx->r16 != ctx->r1) {
        // 0x80132DC8: lui         $at, 0x4000
        ctx->r1 = S32(0X4000 << 16);
            goto L_80132DD8;
    }
    // 0x80132DC8: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80132DCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132DD0: nop

    // 0x80132DD4: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_80132DD8:
    // 0x80132DD8: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x80132DDC: bne         $s0, $at, L_80132DF0
    if (ctx->r16 != ctx->r1) {
        // 0x80132DE0: lui         $at, 0x40E0
        ctx->r1 = S32(0X40E0 << 16);
            goto L_80132DF0;
    }
    // 0x80132DE0: lui         $at, 0x40E0
    ctx->r1 = S32(0X40E0 << 16);
    // 0x80132DE4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132DE8: nop

    // 0x80132DEC: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
L_80132DF0:
    // 0x80132DF0: add.s       $f10, $f2, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f2.fl + ctx->f20.fl;
    // 0x80132DF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80132DF8: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80132DFC: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80132E00: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80132E04: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80132E08: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80132E0C: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x80132E10: bgez        $t4, L_80132E24
    if (SIGNED(ctx->r12) >= 0) {
        // 0x80132E14: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80132E24;
    }
    // 0x80132E14: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80132E18: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132E1C: nop

    // 0x80132E20: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80132E24:
    // 0x80132E24: b           L_80132E50
    // 0x80132E28: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
        goto L_80132E50;
    // 0x80132E28: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_80132E2C:
    // 0x80132E2C: bne         $a3, $s0, L_80132E3C
    if (ctx->r7 != ctx->r16) {
        // 0x80132E30: lui         $at, 0x43AF
        ctx->r1 = S32(0X43AF << 16);
            goto L_80132E3C;
    }
    // 0x80132E30: lui         $at, 0x43AF
    ctx->r1 = S32(0X43AF << 16);
    // 0x80132E34: b           L_80132E50
    // 0x80132E38: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
        goto L_80132E50;
    // 0x80132E38: add.s       $f0, $f0, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f14.fl;
L_80132E3C:
    // 0x80132E3C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132E40: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80132E44: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132E48: nop

    // 0x80132E4C: add.s       $f2, $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f2.fl + ctx->f6.fl;
L_80132E50:
    // 0x80132E50: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80132E54: bne         $a2, $t0, L_80132C2C
    if (ctx->r6 != ctx->r8) {
        // 0x80132E58: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80132C2C;
    }
    // 0x80132E58: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80132E5C:
    // 0x80132E5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132E60: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80132E64: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80132E68: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80132E6C: jr          $ra
    // 0x80132E70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80132E70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void mnPlayersVSUpdateHandicapLevel(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137004: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80137008: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013700C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80137010: jal         0x801368C4
    // 0x80137014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    mnPlayersVSHideFighterName(rdram, ctx);
        goto after_0;
    // 0x80137014: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80137018: jal         0x80136910
    // 0x8013701C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSDestroyHandicapLevel(rdram, ctx);
        goto after_1;
    // 0x8013701C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80137020: jal         0x80136C8C
    // 0x80137024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSMakeHandicapLevel(rdram, ctx);
        goto after_2;
    // 0x80137024: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80137028: jal         0x80137120
    // 0x8013702C: nop

    mnPlayersVSCheckHandicapAuto(rdram, ctx);
        goto after_3;
    // 0x8013702C: nop

    after_3:
    // 0x80137030: beq         $v0, $zero, L_8013705C
    if (ctx->r2 == 0) {
        // 0x80137034: sll         $t6, $s0, 2
        ctx->r14 = S32(ctx->r16 << 2);
            goto L_8013705C;
    }
    // 0x80137034: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x80137038: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x8013703C: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80137040: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x80137044: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80137048: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013704C: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80137050: lw          $t7, -0x44F4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X44F4);
    // 0x80137054: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80137058: bne         $t7, $at, L_801370DC
    if (ctx->r15 != ctx->r1) {
        // 0x8013705C: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_801370DC;
    }
L_8013705C:
    // 0x8013705C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80137060: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x80137064: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80137068: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8013706C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80137070: addiu       $t9, $t9, -0x4578
    ctx->r25 = ADD32(ctx->r25, -0X4578);
    // 0x80137074: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80137078: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8013707C: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x80137080: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80137088: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x8013708C: jal         0x80009968
    // 0x80137090: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80137090: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80137094: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80137098: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x8013709C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801370A0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x801370A4: sw          $v0, 0x24($t1)
    MEM_W(0X24, ctx->r9) = ctx->r2;
    // 0x801370A8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801370AC: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801370B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801370B4: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    // 0x801370B8: jal         0x80009DF4
    // 0x801370BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_5;
    // 0x801370BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x801370C0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x801370C4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801370C8: addiu       $a1, $a1, 0x69E4
    ctx->r5 = ADD32(ctx->r5, 0X69E4);
    // 0x801370CC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801370D0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801370D4: jal         0x80008188
    // 0x801370D8: sw          $s0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r16;
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x801370D8: sw          $s0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r16;
    after_6:
L_801370DC:
    // 0x801370DC: jal         0x80136E90
    // 0x801370E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSMakeHandicapLevelValue(rdram, ctx);
        goto after_7;
    // 0x801370E0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801370E4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801370E8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801370EC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801370F0: jr          $ra
    // 0x801370F4: nop

    return;
    // 0x801370F4: nop

;}
RECOMP_FUNC void mnPlayers1PGameGetPowerOf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: bne         $a1, $zero, L_80131B68
    if (ctx->r5 != 0) {
        // 0x80131B5C: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80131B68;
    }
    // 0x80131B5C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80131B60: jr          $ra
    // 0x80131B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B64: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B68:
    // 0x80131B68: slti        $at, $a1, 0x2
    ctx->r1 = SIGNED(ctx->r5) < 0X2 ? 1 : 0;
    // 0x80131B6C: bne         $at, $zero, L_80131BEC
    if (ctx->r1 != 0) {
        // 0x80131B70: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80131BEC;
    }
    // 0x80131B70: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80131B74: addiu       $a3, $a1, -0x1
    ctx->r7 = ADD32(ctx->r5, -0X1);
    // 0x80131B78: andi        $a3, $a3, 0x3
    ctx->r7 = ctx->r7 & 0X3;
    // 0x80131B7C: negu        $a3, $a3
    ctx->r7 = SUB32(0, ctx->r7);
    // 0x80131B80: beq         $a3, $zero, L_80131BA4
    if (ctx->r7 == 0) {
        // 0x80131B84: addu        $a2, $a3, $a1
        ctx->r6 = ADD32(ctx->r7, ctx->r5);
            goto L_80131BA4;
    }
    // 0x80131B84: addu        $a2, $a3, $a1
    ctx->r6 = ADD32(ctx->r7, ctx->r5);
L_80131B88:
    // 0x80131B88: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131B8C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80131B90: mflo        $v1
    ctx->r3 = lo;
    // 0x80131B94: bne         $a2, $v0, L_80131B88
    if (ctx->r6 != ctx->r2) {
        // 0x80131B98: nop
    
            goto L_80131B88;
    }
    // 0x80131B98: nop

    // 0x80131B9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80131BA0: beq         $v0, $a1, L_80131BEC
    if (ctx->r2 == ctx->r5) {
        // 0x80131BA4: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_80131BEC;
    }
L_80131BA4:
    // 0x80131BA4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80131BA8:
    // 0x80131BA8: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BAC: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x80131BB0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BB4: nop

    // 0x80131BB8: nop

    // 0x80131BBC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BC0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BC4: nop

    // 0x80131BC8: nop

    // 0x80131BCC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BD0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BD4: nop

    // 0x80131BD8: nop

    // 0x80131BDC: multu       $v1, $a0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80131BE0: mflo        $v1
    ctx->r3 = lo;
    // 0x80131BE4: bne         $v0, $a1, L_80131BA8
    if (ctx->r2 != ctx->r5) {
        // 0x80131BE8: nop
    
            goto L_80131BA8;
    }
    // 0x80131BE8: nop

L_80131BEC:
    // 0x80131BEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131BF0: jr          $ra
    // 0x80131BF4: nop

    return;
    // 0x80131BF4: nop

;}
RECOMP_FUNC void mvOpeningClashInitTotalTimeTics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132550: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132554: jr          $ra
    // 0x80132558: sw          $zero, 0x2A08($at)
    MEM_W(0X2A08, ctx->r1) = 0;
    return;
    // 0x80132558: sw          $zero, 0x2A08($at)
    MEM_W(0X2A08, ctx->r1) = 0;
;}
RECOMP_FUNC void func_ovl8_8037D908(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D908: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037D90C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8037D910: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x8037D914: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x8037D918: addiu       $t6, $t6, -0x470
    ctx->r14 = ADD32(ctx->r14, -0X470);
    // 0x8037D91C: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x8037D920: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x8037D924: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x8037D928: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x8037D92C: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x8037D930: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8037D934: sw          $t7, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r15;
    // 0x8037D938: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8037D93C: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x8037D940: addiu       $a0, $a0, -0x468
    ctx->r4 = ADD32(ctx->r4, -0X468);
    // 0x8037D944: jal         0x8037D9B4
    // 0x8037D948: sw          $t8, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r24;
    func_ovl8_8037D9B4(rdram, ctx);
        goto after_0;
    // 0x8037D948: sw          $t8, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r24;
    after_0:
    // 0x8037D94C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037D950: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8037D954: jr          $ra
    // 0x8037D958: nop

    return;
    // 0x8037D958: nop

;}
RECOMP_FUNC void itVisualsUpdateColAnim(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801713B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801713B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801713B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801713BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801713C0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x801713C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801713C8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x801713CC: jal         0x800E0880
    // 0x801713D0: addiu       $a0, $v0, 0x2D8
    ctx->r4 = ADD32(ctx->r2, 0X2D8);
    ftMainUpdateColAnim(rdram, ctx);
        goto after_0;
    // 0x801713D0: addiu       $a0, $v0, 0x2D8
    ctx->r4 = ADD32(ctx->r2, 0X2D8);
    after_0:
    // 0x801713D4: beq         $v0, $zero, L_801713E4
    if (ctx->r2 == 0) {
        // 0x801713D8: lw          $a1, 0x18($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X18);
            goto L_801713E4;
    }
    // 0x801713D8: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x801713DC: jal         0x80172FBC
    // 0x801713E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    itMainClearColAnim(rdram, ctx);
        goto after_1;
    // 0x801713E0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
L_801713E4:
    // 0x801713E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801713E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801713EC: jr          $ra
    // 0x801713F0: nop

    return;
    // 0x801713F0: nop

;}
RECOMP_FUNC void sc1PGameWaitStageTeamUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E824: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8018E828: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8018E82C: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8018E830: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8018E834: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8018E838: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8018E83C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8018E840: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8018E844: jal         0x8000B1E8
    // 0x8018E848: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x8018E848: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_0:
    // 0x8018E84C: jal         0x80112668
    // 0x8018E850: nop

    ifCommonCountdownMakeInterface(rdram, ctx);
        goto after_1;
    // 0x8018E850: nop

    after_1:
    // 0x8018E854: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x8018E858: addiu       $s4, $s4, 0x50E8
    ctx->r20 = ADD32(ctx->r20, 0X50E8);
    // 0x8018E85C: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x8018E860: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018E864: addiu       $s5, $s5, 0x4AD0
    ctx->r21 = ADD32(ctx->r21, 0X4AD0);
    // 0x8018E868: lbu         $t6, 0x4($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X4);
    // 0x8018E86C: lbu         $t7, 0x5($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X5);
    // 0x8018E870: lbu         $s0, 0x13($s5)
    ctx->r16 = MEM_BU(ctx->r21, 0X13);
    // 0x8018E874: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018E878: addu        $s3, $t6, $t7
    ctx->r19 = ADD32(ctx->r14, ctx->r15);
    // 0x8018E87C: blez        $s3, L_8018E8D4
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8018E880: addiu       $s2, $zero, 0x74
        ctx->r18 = ADD32(0, 0X74);
            goto L_8018E8D4;
    }
    // 0x8018E880: addiu       $s2, $zero, 0x74
    ctx->r18 = ADD32(0, 0X74);
L_8018E884:
    // 0x8018E884: multu       $s0, $s2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018E888: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8018E88C: lbu         $t1, 0x13($s5)
    ctx->r9 = MEM_BU(ctx->r21, 0X13);
    // 0x8018E890: mflo        $t9
    ctx->r25 = lo;
    // 0x8018E894: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8018E898: bne         $s0, $t1, L_8018E8B0
    if (ctx->r16 != ctx->r9) {
        // 0x8018E89C: lw          $a0, 0x78($t0)
        ctx->r4 = MEM_W(ctx->r8, 0X78);
            goto L_8018E8B0;
    }
    // 0x8018E89C: lw          $a0, 0x78($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X78);
    // 0x8018E8A0: jal         0x8013DBE0
    // 0x8018E8A4: nop

    ftCommonAppearSetStatus(rdram, ctx);
        goto after_2;
    // 0x8018E8A4: nop

    after_2:
    // 0x8018E8A8: b           L_8018E8B8
    // 0x8018E8AC: nop

        goto L_8018E8B8;
    // 0x8018E8AC: nop

L_8018E8B0:
    // 0x8018E8B0: jal         0x8013DDE0
    // 0x8018E8B4: nop

    ftCommonAppearSetPosition(rdram, ctx);
        goto after_3;
    // 0x8018E8B4: nop

    after_3:
L_8018E8B8:
    // 0x8018E8B8: jal         0x8000B1E8
    // 0x8018E8BC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_4;
    // 0x8018E8BC: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    after_4:
    // 0x8018E8C0: jal         0x8018D280
    // 0x8018E8C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    sc1PGameGetNextFreePlayerPort(rdram, ctx);
        goto after_5;
    // 0x8018E8C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8018E8C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018E8CC: bne         $s1, $s3, L_8018E884
    if (ctx->r17 != ctx->r19) {
        // 0x8018E8D0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8018E884;
    }
    // 0x8018E8D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8018E8D4:
    // 0x8018E8D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E8D8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8018E8DC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8018E8E0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E8E4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8018E8E8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8018E8EC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8018E8F0: jr          $ra
    // 0x8018E8F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8018E8F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void itLinkBombMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801865A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x801865A4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x801865A8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x801865AC: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x801865B0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801865B4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801865B8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801865BC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x801865C0: addiu       $a1, $a1, -0x4940
    ctx->r5 = ADD32(ctx->r5, -0X4940);
    // 0x801865C4: jal         0x8016E174
    // 0x801865C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x801865C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_0:
    // 0x801865CC: beq         $v0, $zero, L_80186648
    if (ctx->r2 == 0) {
        // 0x801865D0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80186648;
    }
    // 0x801865D0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801865D4: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x801865D8: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x801865DC: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x801865E0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801865E4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x801865E8: jal         0x80008CC0
    // 0x801865EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x801865EC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_1:
    // 0x801865F0: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x801865F4: addiu       $a1, $zero, 0x2E
    ctx->r5 = ADD32(0, 0X2E);
    // 0x801865F8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801865FC: jal         0x80008CC0
    // 0x80186600: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x80186600: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    after_2:
    // 0x80186604: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80186608: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018660C: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x80186610: lbu         $t9, 0x158($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X158);
    // 0x80186614: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x80186618: sh          $zero, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = 0;
    // 0x8018661C: ori         $t0, $t9, 0x10
    ctx->r8 = ctx->r25 | 0X10;
    // 0x80186620: sw          $t6, 0x2C0($v1)
    MEM_W(0X2C0, ctx->r3) = ctx->r14;
    // 0x80186624: sh          $zero, 0x354($v1)
    MEM_H(0X354, ctx->r3) = 0;
    // 0x80186628: sh          $t7, 0x356($v1)
    MEM_H(0X356, ctx->r3) = ctx->r15;
    // 0x8018662C: sb          $t0, 0x158($v1)
    MEM_B(0X158, ctx->r3) = ctx->r8;
    // 0x80186630: swc1        $f0, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->f0.u32l;
    // 0x80186634: swc1        $f0, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f0.u32l;
    // 0x80186638: swc1        $f0, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f0.u32l;
    // 0x8018663C: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80186640: jal         0x80172CA4
    // 0x80186644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainSetFighterHold(rdram, ctx);
        goto after_3;
    // 0x80186644: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80186648:
    // 0x80186648: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018664C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80186650: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80186654: jr          $ra
    // 0x80186658: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80186658: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_80005240(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005240: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80005244: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80005248: bne         $a0, $zero, L_80005290
    if (ctx->r4 != 0) {
        // 0x8000524C: sw          $a1, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r5;
            goto L_80005290;
    }
    // 0x8000524C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80005250: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80005254: lw          $t6, 0x6620($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6620);
    // 0x80005258: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000525C: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80005260: bne         $v0, $t6, L_8000529C
    if (ctx->r2 != ctx->r14) {
        // 0x80005264: lhu         $a2, 0x6624($a2)
        ctx->r6 = MEM_HU(ctx->r6, 0X6624);
            goto L_8000529C;
    }
    // 0x80005264: lhu         $a2, 0x6624($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X6624);
    // 0x80005268: beq         $a2, $zero, L_80005280
    if (ctx->r6 == 0) {
        // 0x8000526C: nop
    
            goto L_80005280;
    }
    // 0x8000526C: nop

    // 0x80005270: beq         $a2, $v0, L_80005288
    if (ctx->r6 == ctx->r2) {
        // 0x80005274: nop
    
            goto L_80005288;
    }
    // 0x80005274: nop

    // 0x80005278: b           L_800052A0
    // 0x8000527C: sltiu       $at, $a2, 0xA
    ctx->r1 = ctx->r6 < 0XA ? 1 : 0;
        goto L_800052A0;
    // 0x8000527C: sltiu       $at, $a2, 0xA
    ctx->r1 = ctx->r6 < 0XA ? 1 : 0;
L_80005280:
    // 0x80005280: b           L_8000529C
    // 0x80005284: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
        goto L_8000529C;
    // 0x80005284: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
L_80005288:
    // 0x80005288: b           L_8000529C
    // 0x8000528C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
        goto L_8000529C;
    // 0x8000528C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_80005290:
    // 0x80005290: jal         0x800051E4
    // 0x80005294: nop

    syTaskmanGetUcodeID(rdram, ctx);
        goto after_0;
    // 0x80005294: nop

    after_0:
    // 0x80005298: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8000529C:
    // 0x8000529C: sltiu       $at, $a2, 0xA
    ctx->r1 = ctx->r6 < 0XA ? 1 : 0;
L_800052A0:
    // 0x800052A0: beq         $at, $zero, L_80005334
    if (ctx->r1 == 0) {
        // 0x800052A4: sll         $t7, $a2, 2
        ctx->r15 = S32(ctx->r6 << 2);
            goto L_80005334;
    }
    // 0x800052A4: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800052A8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800052AC: addu        $at, $at, $t7
    gpr jr_addend_800052B4 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800052B0: lw          $t7, -0x274C($at)
    ctx->r15 = ADD32(ctx->r1, -0X274C);
    // 0x800052B4: jr          $t7
    // 0x800052B8: nop

    switch (jr_addend_800052B4 >> 2) {
        case 0: goto L_800052F4; break;
        case 1: goto L_800052BC; break;
        case 2: goto L_800052F4; break;
        case 3: goto L_800052BC; break;
        case 4: goto L_800052F4; break;
        case 5: goto L_800052BC; break;
        case 6: goto L_800052F4; break;
        case 7: goto L_800052BC; break;
        case 8: goto L_800052F4; break;
        case 9: goto L_800052BC; break;
        default: switch_error(__func__, 0x800052B4, 0x8003D8B4);
    }
    // 0x800052B8: nop

L_800052BC:
    // 0x800052BC: jal         0x80004D2C
    // 0x800052C0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80004D2C(rdram, ctx);
        goto after_1;
    // 0x800052C0: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x800052C4: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800052C8: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x800052CC: lw          $a3, 0x6630($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6630);
    // 0x800052D0: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x800052D4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800052D8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800052DC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800052E0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x800052E4: jal         0x80005018
    // 0x800052E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_80005018(rdram, ctx);
        goto after_2;
    // 0x800052E8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_2:
    // 0x800052EC: b           L_80005338
    // 0x800052F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80005338;
    // 0x800052F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800052F4:
    // 0x800052F4: jal         0x80004D2C
    // 0x800052F8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_80004D2C(rdram, ctx);
        goto after_3;
    // 0x800052F8: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_3:
    // 0x800052FC: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80005300: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80005304: lw          $t1, 0x661C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X661C);
    // 0x80005308: lw          $t0, 0x6618($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6618);
    // 0x8000530C: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80005310: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80005314: lw          $a3, 0x6630($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6630);
    // 0x80005318: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8000531C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80005320: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80005324: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80005328: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8000532C: jal         0x80005018
    // 0x80005330: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    func_80005018(rdram, ctx);
        goto after_4;
    // 0x80005330: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_4:
L_80005334:
    // 0x80005334: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80005338:
    // 0x80005338: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8000533C: jr          $ra
    // 0x80005340: nop

    return;
    // 0x80005340: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetBestTime(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133410: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133414: lw          $t6, 0x7714($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7714);
    // 0x80133418: sll         $t8, $a0, 5
    ctx->r24 = S32(ctx->r4 << 5);
    // 0x8013341C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133420: bne         $t6, $zero, L_8013345C
    if (ctx->r14 != 0) {
        // 0x80133424: addu        $v1, $v1, $t8
        ctx->r3 = ADD32(ctx->r3, ctx->r24);
            goto L_8013345C;
    }
    // 0x80133424: addu        $v1, $v1, $t8
    ctx->r3 = ADD32(ctx->r3, ctx->r24);
    // 0x80133428: sll         $t7, $a0, 5
    ctx->r15 = S32(ctx->r4 << 5);
    // 0x8013342C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133430: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x80133434: lw          $v1, 0x494C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X494C);
    // 0x80133438: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x8013343C: ori         $at, $at, 0x4BC0
    ctx->r1 = ctx->r1 | 0X4BC0;
    // 0x80133440: sltu        $at, $v1, $at
    ctx->r1 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x80133444: bne         $at, $zero, L_80133454
    if (ctx->r1 != 0) {
        // 0x80133448: lui         $v0, 0x3
        ctx->r2 = S32(0X3 << 16);
            goto L_80133454;
    }
    // 0x80133448: lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // 0x8013344C: jr          $ra
    // 0x80133450: ori         $v0, $v0, 0x4BBF
    ctx->r2 = ctx->r2 | 0X4BBF;
    return;
    // 0x80133450: ori         $v0, $v0, 0x4BBF
    ctx->r2 = ctx->r2 | 0X4BBF;
L_80133454:
    // 0x80133454: jr          $ra
    // 0x80133458: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80133458: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013345C:
    // 0x8013345C: lw          $v1, 0x4954($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4954);
    // 0x80133460: lui         $at, 0x3
    ctx->r1 = S32(0X3 << 16);
    // 0x80133464: ori         $at, $at, 0x4BC0
    ctx->r1 = ctx->r1 | 0X4BC0;
    // 0x80133468: sltu        $at, $v1, $at
    ctx->r1 = ctx->r3 < ctx->r1 ? 1 : 0;
    // 0x8013346C: bne         $at, $zero, L_80133480
    if (ctx->r1 != 0) {
        // 0x80133470: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80133480;
    }
    // 0x80133470: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80133474: lui         $v0, 0x3
    ctx->r2 = S32(0X3 << 16);
    // 0x80133478: jr          $ra
    // 0x8013347C: ori         $v0, $v0, 0x4BBF
    ctx->r2 = ctx->r2 | 0X4BBF;
    return;
    // 0x8013347C: ori         $v0, $v0, 0x4BBF
    ctx->r2 = ctx->r2 | 0X4BBF;
L_80133480:
    // 0x80133480: jr          $ra
    // 0x80133484: nop

    return;
    // 0x80133484: nop

;}
RECOMP_FUNC void itHarisenWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175198: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017519C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801751A0: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x801751A4: jal         0x801735A0
    // 0x801751A8: addiu       $a1, $a1, 0x5228
    ctx->r5 = ADD32(ctx->r5, 0X5228);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x801751A8: addiu       $a1, $a1, 0x5228
    ctx->r5 = ADD32(ctx->r5, 0X5228);
    after_0:
    // 0x801751AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801751B0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801751B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801751B8: jr          $ra
    // 0x801751BC: nop

    return;
    // 0x801751BC: nop

;}

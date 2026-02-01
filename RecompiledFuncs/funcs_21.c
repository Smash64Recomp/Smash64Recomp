#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSRecordMakeColumnIcons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801335FC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80133600: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80133604: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133608: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x8013360C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80133610: addiu       $t6, $t6, 0x67DC
    ctx->r14 = ADD32(ctx->r14, 0X67DC);
    // 0x80133614: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80133618: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8013361C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80133620: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80133624: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80133628: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8013362C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133630: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x80133634: or          $t9, $s6, $zero
    ctx->r25 = ctx->r22 | 0;
L_80133638:
    // 0x80133638: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013363C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133640: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80133644: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80133648: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8013364C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80133650: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80133654: bne         $t6, $t0, L_80133638
    if (ctx->r14 != ctx->r8) {
        // 0x80133658: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80133638;
    }
    // 0x80133658: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8013365C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133660: lw          $v0, 0x6C18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C18);
    // 0x80133664: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80133668: addiu       $s5, $zero, 0xC
    ctx->r21 = ADD32(0, 0XC);
    // 0x8013366C: beq         $v0, $zero, L_80133688
    if (ctx->r2 == 0) {
        // 0x80133670: addiu       $s4, $zero, -0x21
        ctx->r20 = ADD32(0, -0X21);
            goto L_80133688;
    }
    // 0x80133670: addiu       $s4, $zero, -0x21
    ctx->r20 = ADD32(0, -0X21);
    // 0x80133674: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133678: beq         $v0, $at, L_80133698
    if (ctx->r2 == ctx->r1) {
        // 0x8013367C: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_80133698;
    }
    // 0x8013367C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133680: b           L_801336A0
    // 0x80133684: nop

        goto L_801336A0;
    // 0x80133684: nop

L_80133688:
    // 0x80133688: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013368C: addiu       $t1, $t1, 0x6C28
    ctx->r9 = ADD32(ctx->r9, 0X6C28);
    // 0x80133690: b           L_801336A0
    // 0x80133694: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
        goto L_801336A0;
    // 0x80133694: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
L_80133698:
    // 0x80133698: addiu       $t2, $t2, 0x6C88
    ctx->r10 = ADD32(ctx->r10, 0X6C88);
    // 0x8013369C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
L_801336A0:
    // 0x801336A0: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x801336A4: addiu       $s3, $s3, 0x6D88
    ctx->r19 = ADD32(ctx->r19, 0X6D88);
    // 0x801336A8: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
L_801336AC:
    // 0x801336AC: jal         0x801326EC
    // 0x801336B0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    mnVSRecordCheckHaveFighterKind(rdram, ctx);
        goto after_0;
    // 0x801336B0: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    after_0:
    // 0x801336B4: beq         $v0, $zero, L_801336F8
    if (ctx->r2 == 0) {
        // 0x801336B8: nop
    
            goto L_801336F8;
    }
    // 0x801336B8: nop

    // 0x801336BC: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x801336C0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x801336C4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801336C8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x801336CC: addu        $t5, $s6, $t4
    ctx->r13 = ADD32(ctx->r22, ctx->r12);
    // 0x801336D0: lw          $t0, 0x0($t5)
    ctx->r8 = MEM_W(ctx->r13, 0X0);
    // 0x801336D4: jal         0x800CCFDC
    // 0x801336D8: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x801336D8: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    after_1:
    // 0x801336DC: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801336E0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801336E4: and         $t8, $t9, $s4
    ctx->r24 = ctx->r25 & ctx->r20;
    // 0x801336E8: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x801336EC: ori         $t1, $t8, 0x1
    ctx->r9 = ctx->r24 | 0X1;
    // 0x801336F0: b           L_80133704
    // 0x801336F4: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
        goto L_80133704;
    // 0x801336F4: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
L_801336F8:
    // 0x801336F8: jal         0x801335A0
    // 0x801336FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mnVSRecordMakeLockedIcon(rdram, ctx);
        goto after_2;
    // 0x801336FC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80133700: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80133704:
    // 0x80133704: jal         0x80133438
    // 0x80133708: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mnVSRecordSetIconPositionForColumn(rdram, ctx);
        goto after_3;
    // 0x80133708: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_3:
    // 0x8013370C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80133710: bne         $s0, $s5, L_801336AC
    if (ctx->r16 != ctx->r21) {
        // 0x80133714: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_801336AC;
    }
    // 0x80133714: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80133718: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8013371C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80133720: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80133724: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80133728: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8013372C: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80133730: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80133734: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80133738: jr          $ra
    // 0x8013373C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8013373C: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void wpPikachuThunderJoltAirProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801693EC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801693F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801693F4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801693F8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801693FC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80169400: jal         0x80167B58
    // 0x80169404: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    wpMapTestAllCheckFloor(rdram, ctx);
        goto after_0;
    // 0x80169404: lw          $s1, 0x84($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80169408: beq         $v0, $zero, L_80169428
    if (ctx->r2 == 0) {
        // 0x8016940C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80169428;
    }
    // 0x8016940C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80169410: lw          $a1, 0x74($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X74);
    // 0x80169414: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80169418: jal         0x8016A42C
    // 0x8016941C: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    wpPikachuThunderJoltGroundMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x8016941C: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_1:
    // 0x80169420: b           L_80169528
    // 0x80169424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80169528;
    // 0x80169424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80169428:
    // 0x80169428: lhu         $v0, 0x82($s1)
    ctx->r2 = MEM_HU(ctx->r17, 0X82);
    // 0x8016942C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80169430: andi        $t6, $v0, 0x1
    ctx->r14 = ctx->r2 & 0X1;
    // 0x80169434: beq         $t6, $zero, L_801694AC
    if (ctx->r14 == 0) {
        // 0x80169438: andi        $t7, $v0, 0x20
        ctx->r15 = ctx->r2 & 0X20;
            goto L_801694AC;
    }
    // 0x80169438: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x8016943C: jal         0x800F4650
    // 0x80169440: lw          $a0, 0xCC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XCC);
    mpCollisionGetLWallEdgeU(rdram, ctx);
        goto after_2;
    // 0x80169440: lw          $a0, 0xCC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XCC);
    after_2:
    // 0x80169444: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80169448: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8016944C: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80169450: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80169454: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80169458: nop

    // 0x8016945C: bc1f        L_80169468
    if (!c1cs) {
        // 0x80169460: nop
    
            goto L_80169468;
    }
    // 0x80169460: nop

    // 0x80169464: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
L_80169468:
    // 0x80169468: jal         0x800F4670
    // 0x8016946C: lw          $a0, 0xCC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XCC);
    mpCollisionGetLWallEdgeD(rdram, ctx);
        goto after_3;
    // 0x8016946C: lw          $a0, 0xCC($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XCC);
    after_3:
    // 0x80169470: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x80169474: lwc1        $f10, 0x34($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80169478: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016947C: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80169480: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80169484: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80169488: nop

    // 0x8016948C: bc1f        L_8016949C
    if (!c1cs) {
        // 0x80169490: nop
    
            goto L_8016949C;
    }
    // 0x80169490: nop

    // 0x80169494: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x80169498: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
L_8016949C:
    // 0x8016949C: jal         0x8016A42C
    // 0x801694A0: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    wpPikachuThunderJoltGroundMakeWeapon(rdram, ctx);
        goto after_4;
    // 0x801694A0: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    after_4:
    // 0x801694A4: b           L_80169528
    // 0x801694A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80169528;
    // 0x801694A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801694AC:
    // 0x801694AC: beq         $t7, $zero, L_80169528
    if (ctx->r15 == 0) {
        // 0x801694B0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80169528;
    }
    // 0x801694B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801694B4: lw          $a0, 0xE0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XE0);
    // 0x801694B8: jal         0x800F4690
    // 0x801694BC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    mpCollisionGetRWallEdgeU(rdram, ctx);
        goto after_5;
    // 0x801694BC: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    after_5:
    // 0x801694C0: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x801694C4: lwc1        $f16, 0x34($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801694C8: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x801694CC: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801694D0: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x801694D4: nop

    // 0x801694D8: bc1f        L_801694E4
    if (!c1cs) {
        // 0x801694DC: nop
    
            goto L_801694E4;
    }
    // 0x801694DC: nop

    // 0x801694E0: swc1        $f16, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f16.u32l;
L_801694E4:
    // 0x801694E4: jal         0x800F46B0
    // 0x801694E8: lw          $a0, 0xE0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XE0);
    mpCollisionGetRWallEdgeD(rdram, ctx);
        goto after_6;
    // 0x801694E8: lw          $a0, 0xE0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0XE0);
    after_6:
    // 0x801694EC: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x801694F0: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x801694F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801694F8: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801694FC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80169500: c.lt.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl < ctx->f4.fl;
    // 0x80169504: nop

    // 0x80169508: bc1f        L_80169518
    if (!c1cs) {
        // 0x8016950C: nop
    
            goto L_80169518;
    }
    // 0x8016950C: nop

    // 0x80169510: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x80169514: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
L_80169518:
    // 0x80169518: jal         0x8016A42C
    // 0x8016951C: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    wpPikachuThunderJoltGroundMakeWeapon(rdram, ctx);
        goto after_7;
    // 0x8016951C: addiu       $a1, $v0, 0x1C
    ctx->r5 = ADD32(ctx->r2, 0X1C);
    after_7:
    // 0x80169520: b           L_80169528
    // 0x80169524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80169528;
    // 0x80169524: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80169528:
    // 0x80169528: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016952C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80169530: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80169534: jr          $ra
    // 0x80169538: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80169538: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_ovl8_803717A0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803717A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803717A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803717A8: jal         0x803716D8
    // 0x803717AC: nop

    func_ovl8_803716D8(rdram, ctx);
        goto after_0;
    // 0x803717AC: nop

    after_0:
    // 0x803717B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803717B4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803717B8: jr          $ra
    // 0x803717BC: nop

    return;
    // 0x803717BC: nop

;}
RECOMP_FUNC void mnCharactersMakeEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131F28: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80131F2C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131F30: addiu       $t7, $t7, 0x62E0
    ctx->r15 = ADD32(ctx->r15, 0X62E0);
    // 0x80131F34: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80131F38: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80131F3C: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x80131F40: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80131F44: addiu       $t6, $sp, 0x8C
    ctx->r14 = ADD32(ctx->r29, 0X8C);
L_80131F48:
    // 0x80131F48: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131F4C: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131F50: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131F54: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80131F58: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80131F5C: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80131F60: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80131F64: bne         $t7, $t0, L_80131F48
    if (ctx->r15 != ctx->r8) {
        // 0x80131F68: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80131F48;
    }
    // 0x80131F68: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80131F6C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131F70: addiu       $t2, $t2, 0x6310
    ctx->r10 = ADD32(ctx->r10, 0X6310);
    // 0x80131F74: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x80131F78: addiu       $t1, $sp, 0x5C
    ctx->r9 = ADD32(ctx->r29, 0X5C);
L_80131F7C:
    // 0x80131F7C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80131F80: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80131F84: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80131F88: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80131F8C: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80131F90: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80131F94: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80131F98: bne         $t2, $t5, L_80131F7C
    if (ctx->r10 != ctx->r13) {
        // 0x80131F9C: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80131F7C;
    }
    // 0x80131F9C: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80131FA0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131FA4: addiu       $t7, $t7, 0x6340
    ctx->r15 = ADD32(ctx->r15, 0X6340);
    // 0x80131FA8: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80131FAC: addiu       $t0, $sp, 0x2C
    ctx->r8 = ADD32(ctx->r29, 0X2C);
L_80131FB0:
    // 0x80131FB0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80131FB4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131FB8: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80131FBC: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x80131FC0: lw          $t6, -0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, -0X8);
    // 0x80131FC4: sw          $t6, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r14;
    // 0x80131FC8: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80131FCC: bne         $t7, $t9, L_80131FB0
    if (ctx->r15 != ctx->r25) {
        // 0x80131FD0: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_80131FB0;
    }
    // 0x80131FD0: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x80131FD4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FDC: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x80131FE0: jal         0x80009968
    // 0x80131FE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131FE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FE8: lw          $v1, 0xC0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC0);
    // 0x80131FEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131FF0: sw          $v0, 0x65FC($at)
    MEM_W(0X65FC, ctx->r1) = ctx->r2;
    // 0x80131FF4: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80131FF8: addu        $t5, $sp, $v1
    ctx->r13 = ADD32(ctx->r29, ctx->r3);
    // 0x80131FFC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132000: lw          $t2, 0x6A84($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6A84);
    // 0x80132004: lw          $t5, 0x8C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X8C);
    // 0x80132008: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8013200C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80132010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132018: jal         0x8000F120
    // 0x8013201C: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x8013201C: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    after_1:
    // 0x80132020: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132024: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x80132028: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8013202C: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80132030: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132034: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80132038: jal         0x80009DF4
    // 0x8013203C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x8013203C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80132040: lw          $t3, 0x28($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X28);
    // 0x80132044: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132048: lw          $t9, 0x6A84($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6A84);
    // 0x8013204C: addu        $t4, $sp, $t3
    ctx->r12 = ADD32(ctx->r29, ctx->r11);
    // 0x80132050: lw          $t4, 0x5C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X5C);
    // 0x80132054: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132058: jal         0x8000F8F4
    // 0x8013205C: addu        $a1, $t4, $t9
    ctx->r5 = ADD32(ctx->r12, ctx->r25);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x8013205C: addu        $a1, $t4, $t9
    ctx->r5 = ADD32(ctx->r12, ctx->r25);
    after_3:
    // 0x80132060: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80132064: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132068: lw          $t6, 0x6A84($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A84);
    // 0x8013206C: addu        $t0, $sp, $t7
    ctx->r8 = ADD32(ctx->r29, ctx->r15);
    // 0x80132070: lw          $t0, 0x2C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2C);
    // 0x80132074: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132078: lui         $a2, 0x4080
    ctx->r6 = S32(0X4080 << 16);
    // 0x8013207C: jal         0x8000BE28
    // 0x80132080: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    gcAddMatAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x80132080: addu        $a1, $t0, $t6
    ctx->r5 = ADD32(ctx->r8, ctx->r14);
    after_4:
    // 0x80132084: jal         0x8000DF34
    // 0x80132088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80132088: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8013208C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132090: lwc1        $f0, 0x65B8($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X65B8);
    // 0x80132094: lui         $at, 0xC3AF
    ctx->r1 = S32(0XC3AF << 16);
    // 0x80132098: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013209C: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x801320A0: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801320A4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801320A8: swc1        $f4, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f4.u32l;
    // 0x801320AC: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x801320B0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x801320B4: swc1        $f6, 0x20($t5)
    MEM_W(0X20, ctx->r13) = ctx->f6.u32l;
    // 0x801320B8: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x801320BC: swc1        $f8, 0x24($t2)
    MEM_W(0X24, ctx->r10) = ctx->f8.u32l;
    // 0x801320C0: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x801320C4: swc1        $f0, 0x40($t1)
    MEM_W(0X40, ctx->r9) = ctx->f0.u32l;
    // 0x801320C8: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x801320CC: swc1        $f0, 0x44($t3)
    MEM_W(0X44, ctx->r11) = ctx->f0.u32l;
    // 0x801320D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x801320D4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801320D8: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    // 0x801320DC: jr          $ra
    // 0x801320E0: nop

    return;
    // 0x801320E0: nop

;}
RECOMP_FUNC void mvOpeningPikachuMakeNameCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DB80: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8018DB84: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x8018DB88: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DB8C: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8018DB90: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8018DB94: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DB98: lui         $t9, 0x800
    ctx->r25 = S32(0X800 << 16);
    // 0x8018DB9C: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DBA0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DBA4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DBA8: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8018DBAC: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8018DBB0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DBB4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DBB8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DBBC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DBC0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DBC4: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8018DBC8: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DBCC: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DBD0: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DBD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DBD8: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DBDC: jal         0x8000B93C
    // 0x8018DBE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DBE0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DBE4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DBE8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DBEC: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DBF0: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DBF4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DBF8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DBFC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DC00: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8018DC04: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DC08: jal         0x80007080
    // 0x8018DC0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DC0C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DC10: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DC14: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8018DC18: jr          $ra
    // 0x8018DC1C: nop

    return;
    // 0x8018DC1C: nop

;}
RECOMP_FUNC void mnVSModeAnimateRuleArrows(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013265C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80132660: sdc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X20, ctx->r29);
    // 0x80132664: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x80132668: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8013266C: sdc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X18, ctx->r29);
    // 0x80132670: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x80132674: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80132678: sw          $s5, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r21;
    // 0x8013267C: sw          $s3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r19;
    // 0x80132680: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x80132684: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80132688: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8013268C: sw          $s7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r23;
    // 0x80132690: sw          $s6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r22;
    // 0x80132694: sw          $s4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r20;
    // 0x80132698: sw          $s2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r18;
    // 0x8013269C: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x801326A0: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801326A4: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x801326A8: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x801326AC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801326B0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801326B4: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x801326B8: addiu       $s5, $s5, 0x4948
    ctx->r21 = ADD32(ctx->r21, 0X4948);
    // 0x801326BC: addiu       $s3, $s3, 0x494C
    ctx->r19 = ADD32(ctx->r19, 0X494C);
    // 0x801326C0: addiu       $s1, $s1, 0x4970
    ctx->r17 = ADD32(ctx->r17, 0X4970);
    // 0x801326C4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x801326C8: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x801326CC: addiu       $s6, $zero, 0x1E
    ctx->r22 = ADD32(0, 0X1E);
    // 0x801326D0: addiu       $s7, $zero, 0x3
    ctx->r23 = ADD32(0, 0X3);
    // 0x801326D4: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
L_801326D8:
    // 0x801326D8: bnel        $s4, $t6, L_801327C0
    if (ctx->r20 != ctx->r14) {
        // 0x801326DC: sw          $s2, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r18;
            goto L_801327C0;
    }
    goto skip_0;
    // 0x801326DC: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
    skip_0:
    // 0x801326E0: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x801326E4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801326E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801326EC: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x801326F0: bne         $t8, $zero, L_80132714
    if (ctx->r24 != 0) {
        // 0x801326F4: sw          $t8, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r24;
            goto L_80132714;
    }
    // 0x801326F4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x801326F8: lw          $t0, 0x7C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X7C);
    // 0x801326FC: bnel        $s2, $t0, L_80132710
    if (ctx->r18 != ctx->r8) {
        // 0x80132700: sw          $s2, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r18;
            goto L_80132710;
    }
    goto skip_1;
    // 0x80132700: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
    skip_1:
    // 0x80132704: b           L_80132710
    // 0x80132708: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
        goto L_80132710;
    // 0x80132708: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x8013270C: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
L_80132710:
    // 0x80132710: sw          $s6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r22;
L_80132714:
    // 0x80132714: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x80132718: bne         $t1, $zero, L_80132740
    if (ctx->r9 != 0) {
        // 0x8013271C: nop
    
            goto L_80132740;
    }
    // 0x8013271C: nop

    // 0x80132720: jal         0x80132524
    // 0x80132724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSModeGetArrowSObj(rdram, ctx);
        goto after_0;
    // 0x80132724: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80132728: beq         $v0, $zero, L_80132760
    if (ctx->r2 == 0) {
        // 0x8013272C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80132760;
    }
    // 0x8013272C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132730: jal         0x800096EC
    // 0x80132734: nop

    gcEjectSObj(rdram, ctx);
        goto after_1;
    // 0x80132734: nop

    after_1:
    // 0x80132738: b           L_80132764
    // 0x8013273C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
        goto L_80132764;
    // 0x8013273C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
L_80132740:
    // 0x80132740: jal         0x80132524
    // 0x80132744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    mnVSModeGetArrowSObj(rdram, ctx);
        goto after_2;
    // 0x80132744: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80132748: bnel        $v0, $zero, L_80132764
    if (ctx->r2 != 0) {
        // 0x8013274C: lw          $t2, 0x0($s3)
        ctx->r10 = MEM_W(ctx->r19, 0X0);
            goto L_80132764;
    }
    goto skip_2;
    // 0x8013274C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    skip_2:
    // 0x80132750: mfc1        $a1, $f24
    ctx->r5 = (int32_t)ctx->f24.u32l;
    // 0x80132754: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80132758: jal         0x80132570
    // 0x8013275C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSModeMakeLeftArrow(rdram, ctx);
        goto after_3;
    // 0x8013275C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80132760:
    // 0x80132760: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
L_80132764:
    // 0x80132764: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80132768: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013276C: bne         $s7, $t2, L_80132794
    if (ctx->r23 != ctx->r10) {
        // 0x80132770: nop
    
            goto L_80132794;
    }
    // 0x80132770: nop

    // 0x80132774: jal         0x80132524
    // 0x80132778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSModeGetArrowSObj(rdram, ctx);
        goto after_4;
    // 0x80132778: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8013277C: beq         $v0, $zero, L_801327C0
    if (ctx->r2 == 0) {
        // 0x80132780: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_801327C0;
    }
    // 0x80132780: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132784: jal         0x800096EC
    // 0x80132788: nop

    gcEjectSObj(rdram, ctx);
        goto after_5;
    // 0x80132788: nop

    after_5:
    // 0x8013278C: b           L_801327C0
    // 0x80132790: nop

        goto L_801327C0;
    // 0x80132790: nop

L_80132794:
    // 0x80132794: jal         0x80132524
    // 0x80132798: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    mnVSModeGetArrowSObj(rdram, ctx);
        goto after_6;
    // 0x80132798: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_6:
    // 0x8013279C: bne         $v0, $zero, L_801327C0
    if (ctx->r2 != 0) {
        // 0x801327A0: nop
    
            goto L_801327C0;
    }
    // 0x801327A0: nop

    // 0x801327A4: mfc1        $a1, $f22
    ctx->r5 = (int32_t)ctx->f22.u32l;
    // 0x801327A8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x801327AC: jal         0x801325E4
    // 0x801327B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnVSModeMakeRightArrow(rdram, ctx);
        goto after_7;
    // 0x801327B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x801327B4: b           L_801327C0
    // 0x801327B8: nop

        goto L_801327C0;
    // 0x801327B8: nop

    // 0x801327BC: sw          $s2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r18;
L_801327C0:
    // 0x801327C0: jal         0x8000B1E8
    // 0x801327C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_8;
    // 0x801327C4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x801327C8: b           L_801326D8
    // 0x801327CC: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
        goto L_801326D8;
    // 0x801327CC: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x801327D0: nop

    // 0x801327D4: nop

    // 0x801327D8: nop

    // 0x801327DC: nop

    // 0x801327E0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x801327E4: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x801327E8: ldc1        $f22, 0x18($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X18);
    // 0x801327EC: ldc1        $f24, 0x20($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X20);
    // 0x801327F0: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x801327F4: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x801327F8: lw          $s2, 0x34($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X34);
    // 0x801327FC: lw          $s3, 0x38($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X38);
    // 0x80132800: lw          $s4, 0x3C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X3C);
    // 0x80132804: lw          $s5, 0x40($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X40);
    // 0x80132808: lw          $s6, 0x44($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X44);
    // 0x8013280C: lw          $s7, 0x48($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X48);
    // 0x80132810: jr          $ra
    // 0x80132814: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80132814: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_ovl8_803867E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803867E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x803867EC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x803867F0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x803867F4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x803867F8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x803867FC: jal         0x803717A0
    // 0x80386800: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80386800: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    after_0:
    // 0x80386804: beq         $v0, $zero, L_803868A8
    if (ctx->r2 == 0) {
        // 0x80386808: sw          $v0, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r2;
            goto L_803868A8;
    }
    // 0x80386808: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8038680C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80386810: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80386814: bne         $v0, $zero, L_8038682C
    if (ctx->r2 != 0) {
        // 0x80386818: sw          $zero, 0x30($sp)
        MEM_W(0X30, ctx->r29) = 0;
            goto L_8038682C;
    }
    // 0x80386818: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8038681C: jal         0x803717A0
    // 0x80386820: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    func_ovl8_803717A0(rdram, ctx);
        goto after_1;
    // 0x80386820: addiu       $a0, $zero, 0x118
    ctx->r4 = ADD32(0, 0X118);
    after_1:
    // 0x80386824: beq         $v0, $zero, L_803868A0
    if (ctx->r2 == 0) {
        // 0x80386828: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803868A0;
    }
    // 0x80386828: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8038682C:
    // 0x8038682C: addiu       $a0, $s0, 0xB0
    ctx->r4 = ADD32(ctx->r16, 0XB0);
    // 0x80386830: addiu       $a1, $s0, 0x10C
    ctx->r5 = ADD32(ctx->r16, 0X10C);
    // 0x80386834: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x80386838: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8038683C: jal         0x803717E0
    // 0x80386840: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    func_ovl8_803717E0(rdram, ctx);
        goto after_2;
    // 0x80386840: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_2:
    // 0x80386844: jal         0x8037C2D0
    // 0x80386848: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_3;
    // 0x80386848: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_3:
    // 0x8038684C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80386850: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80386854: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80386858: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8038685C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80386860: jal         0x80376010
    // 0x80386864: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    func_ovl8_80376010(rdram, ctx);
        goto after_4;
    // 0x80386864: lw          $a3, 0x4C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X4C);
    after_4:
    // 0x80386868: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x8038686C: addiu       $t7, $t7, -0x1A60
    ctx->r15 = ADD32(ctx->r15, -0X1A60);
    // 0x80386870: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80386874: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80386878: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8038687C: addiu       $t8, $t8, -0x19A0
    ctx->r24 = ADD32(ctx->r24, -0X19A0);
    // 0x80386880: sw          $t8, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r24;
    // 0x80386884: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80386888: lui         $t0, 0x8039
    ctx->r8 = S32(0X8039 << 16);
    // 0x8038688C: addiu       $t0, $t0, -0x1848
    ctx->r8 = ADD32(ctx->r8, -0X1848);
    // 0x80386890: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80386894: addiu       $t2, $t2, -0x1820
    ctx->r10 = ADD32(ctx->r10, -0X1820);
    // 0x80386898: sw          $t0, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r8;
    // 0x8038689C: sw          $t2, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r10;
L_803868A0:
    // 0x803868A0: b           L_803868AC
    // 0x803868A4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
        goto L_803868AC;
    // 0x803868A4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
L_803868A8:
    // 0x803868A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803868AC:
    // 0x803868AC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x803868B0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x803868B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x803868B8: jr          $ra
    // 0x803868BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x803868BC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void func_ovl8_803718FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803718FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371900: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371904: lw          $v0, 0x58($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X58);
    // 0x80371908: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8037190C: sw          $t6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r14;
    // 0x80371910: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x80371914: lh          $t7, 0x20($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X20);
    // 0x80371918: jalr        $t9
    // 0x8037191C: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037191C: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    after_0:
    // 0x80371920: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80371924: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80371928: jr          $ra
    // 0x8037192C: nop

    return;
    // 0x8037192C: nop

;}
RECOMP_FUNC void itNBumperWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017B520: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017B524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017B528: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x8017B52C: jal         0x801735A0
    // 0x8017B530: addiu       $a1, $a1, -0x49CC
    ctx->r5 = ADD32(ctx->r5, -0X49CC);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x8017B530: addiu       $a1, $a1, -0x49CC
    ctx->r5 = ADD32(ctx->r5, -0X49CC);
    after_0:
    // 0x8017B534: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017B538: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017B53C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017B540: jr          $ra
    // 0x8017B544: nop

    return;
    // 0x8017B544: nop

;}
RECOMP_FUNC void mnVSResultsMakeWallpaperTint2Camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013525C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80135260: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80135264: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80135268: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013526C: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x80135270: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x80135274: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x80135278: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013527C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80135280: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80135284: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80135288: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013528C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80135290: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80135294: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80135298: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8013529C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801352A0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801352A4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801352A8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801352AC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801352B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801352B4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x801352B8: jal         0x8000B93C
    // 0x801352BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801352BC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801352C0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801352C4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801352C8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801352CC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801352D0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801352D4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801352D8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801352DC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801352E0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801352E4: jal         0x80007080
    // 0x801352E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801352E8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801352EC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801352F0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801352F4: jr          $ra
    // 0x801352F8: nop

    return;
    // 0x801352F8: nop

;}
RECOMP_FUNC void lbParticleUpdateStruct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CEF4C: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x800CEF50: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CEF54: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CEF58: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CEF5C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CEF60: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CEF64: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x800CEF68: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    // 0x800CEF6C: lhu         $t6, 0x6($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X6);
    // 0x800CEF70: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800CEF74: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x800CEF78: beql        $t7, $zero, L_800CEF8C
    if (ctx->r15 == 0) {
        // 0x800CEF7C: lhu         $v0, 0xC($s2)
        ctx->r2 = MEM_HU(ctx->r18, 0XC);
            goto L_800CEF8C;
    }
    goto skip_0;
    // 0x800CEF7C: lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XC);
    skip_0:
    // 0x800CEF80: b           L_800D0C58
    // 0x800CEF84: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
        goto L_800D0C58;
    // 0x800CEF84: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800CEF88: lhu         $v0, 0xC($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XC);
L_800CEF8C:
    // 0x800CEF8C: beql        $v0, $zero, L_800D0458
    if (ctx->r2 == 0) {
        // 0x800CEF90: lhu         $v0, 0xE($s2)
        ctx->r2 = MEM_HU(ctx->r18, 0XE);
            goto L_800D0458;
    }
    goto skip_1;
    // 0x800CEF90: lhu         $v0, 0xE($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XE);
    skip_1:
    // 0x800CEF94: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x800CEF98: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800CEF9C: bne         $t9, $zero, L_800D0454
    if (ctx->r25 != 0) {
        // 0x800CEFA0: sh          $t8, 0xC($s2)
        MEM_H(0XC, ctx->r18) = ctx->r24;
            goto L_800D0454;
    }
    // 0x800CEFA0: sh          $t8, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r24;
    // 0x800CEFA4: lw          $t0, 0x14($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X14);
    // 0x800CEFA8: lhu         $t1, 0x18($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X18);
    // 0x800CEFAC: addiu       $s3, $sp, 0x80
    ctx->r19 = ADD32(ctx->r29, 0X80);
    // 0x800CEFB0: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    // 0x800CEFB4: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
L_800CEFB8:
    // 0x800CEFB8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CEFBC: slti        $at, $a0, 0x80
    ctx->r1 = SIGNED(ctx->r4) < 0X80 ? 1 : 0;
    // 0x800CEFC0: bne         $at, $zero, L_800D03E8
    if (ctx->r1 != 0) {
        // 0x800CEFC4: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_800D03E8;
    }
    // 0x800CEFC4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800CEFC8: andi        $v0, $s0, 0xF8
    ctx->r2 = ctx->r16 & 0XF8;
    // 0x800CEFCC: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x800CEFD0: slti        $at, $t2, 0x99
    ctx->r1 = SIGNED(ctx->r10) < 0X99 ? 1 : 0;
    // 0x800CEFD4: sh          $zero, 0x94($sp)
    MEM_H(0X94, ctx->r29) = 0;
    // 0x800CEFD8: bne         $at, $zero, L_800CF004
    if (ctx->r1 != 0) {
        // 0x800CEFDC: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_800CF004;
    }
    // 0x800CEFDC: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800CEFE0: andi        $v0, $s0, 0xF0
    ctx->r2 = ctx->r16 & 0XF0;
    // 0x800CEFE4: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x800CEFE8: addiu       $at, $zero, 0xC0
    ctx->r1 = ADD32(0, 0XC0);
    // 0x800CEFEC: beq         $a1, $at, L_800CF004
    if (ctx->r5 == ctx->r1) {
        // 0x800CEFF0: andi        $v1, $v0, 0xFF
        ctx->r3 = ctx->r2 & 0XFF;
            goto L_800CF004;
    }
    // 0x800CEFF0: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x800CEFF4: addiu       $at, $zero, 0xD0
    ctx->r1 = ADD32(0, 0XD0);
    // 0x800CEFF8: beql        $a1, $at, L_800CF008
    if (ctx->r5 == ctx->r1) {
        // 0x800CEFFC: slti        $at, $v1, 0xD1
        ctx->r1 = SIGNED(ctx->r3) < 0XD1 ? 1 : 0;
            goto L_800CF008;
    }
    goto skip_2;
    // 0x800CEFFC: slti        $at, $v1, 0xD1
    ctx->r1 = SIGNED(ctx->r3) < 0XD1 ? 1 : 0;
    skip_2:
    // 0x800CF000: andi        $v1, $a0, 0xFF
    ctx->r3 = ctx->r4 & 0XFF;
L_800CF004:
    // 0x800CF004: slti        $at, $v1, 0xD1
    ctx->r1 = SIGNED(ctx->r3) < 0XD1 ? 1 : 0;
L_800CF008:
    // 0x800CF008: bne         $at, $zero, L_800CF038
    if (ctx->r1 != 0) {
        // 0x800CF00C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800CF038;
    }
    // 0x800CF00C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800CF010: addiu       $t3, $v0, -0xFA
    ctx->r11 = ADD32(ctx->r2, -0XFA);
    // 0x800CF014: sltiu       $at, $t3, 0x6
    ctx->r1 = ctx->r11 < 0X6 ? 1 : 0;
    // 0x800CF018: beql        $at, $zero, L_800D0438
    if (ctx->r1 == 0) {
        // 0x800CF01C: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_3;
    // 0x800CF01C: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_3:
    // 0x800CF020: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800CF024: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CF028: addu        $at, $at, $t3
    gpr jr_addend_800CF030 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x800CF02C: lw          $t3, 0x5FC4($at)
    ctx->r11 = ADD32(ctx->r1, 0X5FC4);
    // 0x800CF030: jr          $t3
    // 0x800CF034: nop

    switch (jr_addend_800CF030 >> 2) {
        case 0: goto L_800D0374; break;
        case 1: goto L_800D0390; break;
        case 2: goto L_800D03B4; break;
        case 3: goto L_800D03C4; break;
        case 4: goto L_800D03D4; break;
        case 5: goto L_800D03D4; break;
        default: switch_error(__func__, 0x800CF030, 0x800D5FC4);
    }
    // 0x800CF034: nop

L_800CF038:
    // 0x800CF038: addiu       $t4, $v0, -0x80
    ctx->r12 = ADD32(ctx->r2, -0X80);
    // 0x800CF03C: sltiu       $at, $t4, 0x51
    ctx->r1 = ctx->r12 < 0X51 ? 1 : 0;
    // 0x800CF040: beq         $at, $zero, L_800D0434
    if (ctx->r1 == 0) {
        // 0x800CF044: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_800D0434;
    }
    // 0x800CF044: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x800CF048: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CF04C: addu        $at, $at, $t4
    gpr jr_addend_800CF054 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x800CF050: lw          $t4, 0x5FDC($at)
    ctx->r12 = ADD32(ctx->r1, 0X5FDC);
    // 0x800CF054: jr          $t4
    // 0x800CF058: nop

    switch (jr_addend_800CF054 >> 2) {
        case 0: goto L_800CF05C; break;
        case 1: goto L_800D0434; break;
        case 2: goto L_800D0434; break;
        case 3: goto L_800D0434; break;
        case 4: goto L_800D0434; break;
        case 5: goto L_800D0434; break;
        case 6: goto L_800D0434; break;
        case 7: goto L_800D0434; break;
        case 8: goto L_800CF0B4; break;
        case 9: goto L_800D0434; break;
        case 10: goto L_800D0434; break;
        case 11: goto L_800D0434; break;
        case 12: goto L_800D0434; break;
        case 13: goto L_800D0434; break;
        case 14: goto L_800D0434; break;
        case 15: goto L_800D0434; break;
        case 16: goto L_800CF13C; break;
        case 17: goto L_800D0434; break;
        case 18: goto L_800D0434; break;
        case 19: goto L_800D0434; break;
        case 20: goto L_800D0434; break;
        case 21: goto L_800D0434; break;
        case 22: goto L_800D0434; break;
        case 23: goto L_800D0434; break;
        case 24: goto L_800CF194; break;
        case 25: goto L_800D0434; break;
        case 26: goto L_800D0434; break;
        case 27: goto L_800D0434; break;
        case 28: goto L_800D0434; break;
        case 29: goto L_800D0434; break;
        case 30: goto L_800D0434; break;
        case 31: goto L_800D0434; break;
        case 32: goto L_800CF21C; break;
        case 33: goto L_800CF25C; break;
        case 34: goto L_800CF26C; break;
        case 35: goto L_800CF2B8; break;
        case 36: goto L_800CF308; break;
        case 37: goto L_800CF38C; break;
        case 38: goto L_800CF3F4; break;
        case 39: goto L_800CF44C; break;
        case 40: goto L_800CF494; break;
        case 41: goto L_800CF510; break;
        case 42: goto L_800CF534; break;
        case 43: goto L_800CF5F4; break;
        case 44: goto L_800CF638; break;
        case 45: goto L_800CF698; break;
        case 46: goto L_800CF6A8; break;
        case 47: goto L_800CF6BC; break;
        case 48: goto L_800CF6DC; break;
        case 49: goto L_800CF6FC; break;
        case 50: goto L_800CF70C; break;
        case 51: goto L_800CF71C; break;
        case 52: goto L_800CF730; break;
        case 53: goto L_800CF740; break;
        case 54: goto L_800CF750; break;
        case 55: goto L_800CF764; break;
        case 56: goto L_800CF78C; break;
        case 57: goto L_800CF7C4; break;
        case 58: goto L_800CF860; break;
        case 59: goto L_800CFC28; break;
        case 60: goto L_800CFFF0; break;
        case 61: goto L_800D00F0; break;
        case 62: goto L_800D018C; break;
        case 63: goto L_800D01E8; break;
        case 64: goto L_800D020C; break;
        case 65: goto L_800D0434; break;
        case 66: goto L_800D0434; break;
        case 67: goto L_800D0434; break;
        case 68: goto L_800D0434; break;
        case 69: goto L_800D0434; break;
        case 70: goto L_800D0434; break;
        case 71: goto L_800D0434; break;
        case 72: goto L_800D0434; break;
        case 73: goto L_800D0434; break;
        case 74: goto L_800D0434; break;
        case 75: goto L_800D0434; break;
        case 76: goto L_800D0434; break;
        case 77: goto L_800D0434; break;
        case 78: goto L_800D0434; break;
        case 79: goto L_800D0434; break;
        case 80: goto L_800D02C0; break;
        default: switch_error(__func__, 0x800CF054, 0x800D5FDC);
    }
    // 0x800CF058: nop

L_800CF05C:
    // 0x800CF05C: andi        $t5, $s0, 0x1
    ctx->r13 = ctx->r16 & 0X1;
    // 0x800CF060: beql        $t5, $zero, L_800CF07C
    if (ctx->r13 == 0) {
        // 0x800CF064: andi        $t6, $s0, 0x2
        ctx->r14 = ctx->r16 & 0X2;
            goto L_800CF07C;
    }
    goto skip_4;
    // 0x800CF064: andi        $t6, $s0, 0x2
    ctx->r14 = ctx->r16 & 0X2;
    skip_4:
    // 0x800CF068: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF06C: jal         0x800CEBC0
    // 0x800CF070: addiu       $a1, $s2, 0x20
    ctx->r5 = ADD32(ctx->r18, 0X20);
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_0;
    // 0x800CF070: addiu       $a1, $s2, 0x20
    ctx->r5 = ADD32(ctx->r18, 0X20);
    after_0:
    // 0x800CF074: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF078: andi        $t6, $s0, 0x2
    ctx->r14 = ctx->r16 & 0X2;
L_800CF07C:
    // 0x800CF07C: beql        $t6, $zero, L_800CF098
    if (ctx->r14 == 0) {
        // 0x800CF080: andi        $t7, $s0, 0x4
        ctx->r15 = ctx->r16 & 0X4;
            goto L_800CF098;
    }
    goto skip_5;
    // 0x800CF080: andi        $t7, $s0, 0x4
    ctx->r15 = ctx->r16 & 0X4;
    skip_5:
    // 0x800CF084: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF088: jal         0x800CEBC0
    // 0x800CF08C: addiu       $a1, $s2, 0x24
    ctx->r5 = ADD32(ctx->r18, 0X24);
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_1;
    // 0x800CF08C: addiu       $a1, $s2, 0x24
    ctx->r5 = ADD32(ctx->r18, 0X24);
    after_1:
    // 0x800CF090: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF094: andi        $t7, $s0, 0x4
    ctx->r15 = ctx->r16 & 0X4;
L_800CF098:
    // 0x800CF098: beql        $t7, $zero, L_800D0438
    if (ctx->r15 == 0) {
        // 0x800CF09C: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_6;
    // 0x800CF09C: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_6:
    // 0x800CF0A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF0A4: jal         0x800CEBC0
    // 0x800CF0A8: addiu       $a1, $s2, 0x28
    ctx->r5 = ADD32(ctx->r18, 0X28);
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_2;
    // 0x800CF0A8: addiu       $a1, $s2, 0x28
    ctx->r5 = ADD32(ctx->r18, 0X28);
    after_2:
    // 0x800CF0AC: b           L_800D0434
    // 0x800CF0B0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800D0434;
    // 0x800CF0B0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800CF0B4:
    // 0x800CF0B4: andi        $t8, $s0, 0x1
    ctx->r24 = ctx->r16 & 0X1;
    // 0x800CF0B8: beql        $t8, $zero, L_800CF0E4
    if (ctx->r24 == 0) {
        // 0x800CF0BC: andi        $t9, $s0, 0x2
        ctx->r25 = ctx->r16 & 0X2;
            goto L_800CF0E4;
    }
    goto skip_7;
    // 0x800CF0BC: andi        $t9, $s0, 0x2
    ctx->r25 = ctx->r16 & 0X2;
    skip_7:
    // 0x800CF0C0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF0C4: jal         0x800CEBC0
    // 0x800CF0C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_3;
    // 0x800CF0C8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_3:
    // 0x800CF0CC: lwc1        $f4, 0x20($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800CF0D0: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF0D4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF0D8: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800CF0DC: swc1        $f8, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f8.u32l;
    // 0x800CF0E0: andi        $t9, $s0, 0x2
    ctx->r25 = ctx->r16 & 0X2;
L_800CF0E4:
    // 0x800CF0E4: beql        $t9, $zero, L_800CF110
    if (ctx->r25 == 0) {
        // 0x800CF0E8: andi        $t0, $s0, 0x4
        ctx->r8 = ctx->r16 & 0X4;
            goto L_800CF110;
    }
    goto skip_8;
    // 0x800CF0E8: andi        $t0, $s0, 0x4
    ctx->r8 = ctx->r16 & 0X4;
    skip_8:
    // 0x800CF0EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF0F0: jal         0x800CEBC0
    // 0x800CF0F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_4;
    // 0x800CF0F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x800CF0F8: lwc1        $f10, 0x24($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800CF0FC: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF100: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF104: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CF108: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x800CF10C: andi        $t0, $s0, 0x4
    ctx->r8 = ctx->r16 & 0X4;
L_800CF110:
    // 0x800CF110: beql        $t0, $zero, L_800D0438
    if (ctx->r8 == 0) {
        // 0x800CF114: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_9;
    // 0x800CF114: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_9:
    // 0x800CF118: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF11C: jal         0x800CEBC0
    // 0x800CF120: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_5;
    // 0x800CF120: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x800CF124: lwc1        $f8, 0x28($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800CF128: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF12C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF130: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800CF134: b           L_800D0434
    // 0x800CF138: swc1        $f4, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f4.u32l;
        goto L_800D0434;
    // 0x800CF138: swc1        $f4, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f4.u32l;
L_800CF13C:
    // 0x800CF13C: andi        $t1, $s0, 0x1
    ctx->r9 = ctx->r16 & 0X1;
    // 0x800CF140: beql        $t1, $zero, L_800CF15C
    if (ctx->r9 == 0) {
        // 0x800CF144: andi        $t2, $s0, 0x2
        ctx->r10 = ctx->r16 & 0X2;
            goto L_800CF15C;
    }
    goto skip_10;
    // 0x800CF144: andi        $t2, $s0, 0x2
    ctx->r10 = ctx->r16 & 0X2;
    skip_10:
    // 0x800CF148: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF14C: jal         0x800CEBC0
    // 0x800CF150: addiu       $a1, $s2, 0x2C
    ctx->r5 = ADD32(ctx->r18, 0X2C);
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_6;
    // 0x800CF150: addiu       $a1, $s2, 0x2C
    ctx->r5 = ADD32(ctx->r18, 0X2C);
    after_6:
    // 0x800CF154: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF158: andi        $t2, $s0, 0x2
    ctx->r10 = ctx->r16 & 0X2;
L_800CF15C:
    // 0x800CF15C: beql        $t2, $zero, L_800CF178
    if (ctx->r10 == 0) {
        // 0x800CF160: andi        $t3, $s0, 0x4
        ctx->r11 = ctx->r16 & 0X4;
            goto L_800CF178;
    }
    goto skip_11;
    // 0x800CF160: andi        $t3, $s0, 0x4
    ctx->r11 = ctx->r16 & 0X4;
    skip_11:
    // 0x800CF164: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF168: jal         0x800CEBC0
    // 0x800CF16C: addiu       $a1, $s2, 0x30
    ctx->r5 = ADD32(ctx->r18, 0X30);
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_7;
    // 0x800CF16C: addiu       $a1, $s2, 0x30
    ctx->r5 = ADD32(ctx->r18, 0X30);
    after_7:
    // 0x800CF170: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF174: andi        $t3, $s0, 0x4
    ctx->r11 = ctx->r16 & 0X4;
L_800CF178:
    // 0x800CF178: beql        $t3, $zero, L_800D0438
    if (ctx->r11 == 0) {
        // 0x800CF17C: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_12;
    // 0x800CF17C: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_12:
    // 0x800CF180: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF184: jal         0x800CEBC0
    // 0x800CF188: addiu       $a1, $s2, 0x34
    ctx->r5 = ADD32(ctx->r18, 0X34);
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_8;
    // 0x800CF188: addiu       $a1, $s2, 0x34
    ctx->r5 = ADD32(ctx->r18, 0X34);
    after_8:
    // 0x800CF18C: b           L_800D0434
    // 0x800CF190: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
        goto L_800D0434;
    // 0x800CF190: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800CF194:
    // 0x800CF194: andi        $t4, $s0, 0x1
    ctx->r12 = ctx->r16 & 0X1;
    // 0x800CF198: beql        $t4, $zero, L_800CF1C4
    if (ctx->r12 == 0) {
        // 0x800CF19C: andi        $t5, $s0, 0x2
        ctx->r13 = ctx->r16 & 0X2;
            goto L_800CF1C4;
    }
    goto skip_13;
    // 0x800CF19C: andi        $t5, $s0, 0x2
    ctx->r13 = ctx->r16 & 0X2;
    skip_13:
    // 0x800CF1A0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF1A4: jal         0x800CEBC0
    // 0x800CF1A8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_9;
    // 0x800CF1A8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_9:
    // 0x800CF1AC: lwc1        $f6, 0x2C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800CF1B0: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF1B4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF1B8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CF1BC: swc1        $f10, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f10.u32l;
    // 0x800CF1C0: andi        $t5, $s0, 0x2
    ctx->r13 = ctx->r16 & 0X2;
L_800CF1C4:
    // 0x800CF1C4: beql        $t5, $zero, L_800CF1F0
    if (ctx->r13 == 0) {
        // 0x800CF1C8: andi        $t6, $s0, 0x4
        ctx->r14 = ctx->r16 & 0X4;
            goto L_800CF1F0;
    }
    goto skip_14;
    // 0x800CF1C8: andi        $t6, $s0, 0x4
    ctx->r14 = ctx->r16 & 0X4;
    skip_14:
    // 0x800CF1CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF1D0: jal         0x800CEBC0
    // 0x800CF1D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_10;
    // 0x800CF1D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_10:
    // 0x800CF1D8: lwc1        $f4, 0x30($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800CF1DC: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF1E0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF1E4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800CF1E8: swc1        $f8, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f8.u32l;
    // 0x800CF1EC: andi        $t6, $s0, 0x4
    ctx->r14 = ctx->r16 & 0X4;
L_800CF1F0:
    // 0x800CF1F0: beql        $t6, $zero, L_800D0438
    if (ctx->r14 == 0) {
        // 0x800CF1F4: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_15;
    // 0x800CF1F4: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_15:
    // 0x800CF1F8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF1FC: jal         0x800CEBC0
    // 0x800CF200: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_11;
    // 0x800CF200: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_11:
    // 0x800CF204: lwc1        $f10, 0x34($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800CF208: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF20C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF210: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800CF214: b           L_800D0434
    // 0x800CF218: swc1        $f6, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f6.u32l;
        goto L_800D0434;
    // 0x800CF218: swc1        $f6, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f6.u32l;
L_800CF21C:
    // 0x800CF21C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF220: addiu       $a1, $s2, 0xE
    ctx->r5 = ADD32(ctx->r18, 0XE);
    // 0x800CF224: jal         0x800CEBF8
    // 0x800CF228: addiu       $s0, $s2, 0x44
    ctx->r16 = ADD32(ctx->r18, 0X44);
    lbParticleReadUShort(rdram, ctx);
        goto after_12;
    // 0x800CF228: addiu       $s0, $s2, 0x44
    ctx->r16 = ADD32(ctx->r18, 0X44);
    after_12:
    // 0x800CF22C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CF230: jal         0x800CEBC0
    // 0x800CF234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_13;
    // 0x800CF234: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_13:
    // 0x800CF238: lhu         $t7, 0xE($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0XE);
    // 0x800CF23C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CF240: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF244: bnel        $t7, $at, L_800D0438
    if (ctx->r15 != ctx->r1) {
        // 0x800CF248: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_16;
    // 0x800CF248: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_16:
    // 0x800CF24C: lwc1        $f8, 0x44($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X44);
    // 0x800CF250: sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
    // 0x800CF254: b           L_800D0434
    // 0x800CF258: swc1        $f8, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f8.u32l;
        goto L_800D0434;
    // 0x800CF258: swc1        $f8, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f8.u32l;
L_800CF25C:
    // 0x800CF25C: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF260: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CF264: b           L_800D0434
    // 0x800CF268: sh          $t8, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r24;
        goto L_800D0434;
    // 0x800CF268: sh          $t8, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r24;
L_800CF26C:
    // 0x800CF26C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF270: jal         0x800CEBC0
    // 0x800CF274: addiu       $a1, $s2, 0x38
    ctx->r5 = ADD32(ctx->r18, 0X38);
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_14;
    // 0x800CF274: addiu       $a1, $s2, 0x38
    ctx->r5 = ADD32(ctx->r18, 0X38);
    after_14:
    // 0x800CF278: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800CF27C: lwc1        $f4, 0x38($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X38);
    // 0x800CF280: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF284: c.eq.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl == ctx->f4.fl;
    // 0x800CF288: nop

    // 0x800CF28C: bc1fl       L_800CF2AC
    if (!c1cs) {
        // 0x800CF290: lhu         $t1, 0x6($s2)
        ctx->r9 = MEM_HU(ctx->r18, 0X6);
            goto L_800CF2AC;
    }
    goto skip_17;
    // 0x800CF290: lhu         $t1, 0x6($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X6);
    skip_17:
    // 0x800CF294: lhu         $t9, 0x6($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF298: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800CF29C: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800CF2A0: b           L_800D0434
    // 0x800CF2A4: sh          $t0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r8;
        goto L_800D0434;
    // 0x800CF2A4: sh          $t0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r8;
    // 0x800CF2A8: lhu         $t1, 0x6($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X6);
L_800CF2AC:
    // 0x800CF2AC: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x800CF2B0: b           L_800D0434
    // 0x800CF2B4: sh          $t2, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r10;
        goto L_800D0434;
    // 0x800CF2B4: sh          $t2, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r10;
L_800CF2B8:
    // 0x800CF2B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF2BC: jal         0x800CEBC0
    // 0x800CF2C0: addiu       $a1, $s2, 0x3C
    ctx->r5 = ADD32(ctx->r18, 0X3C);
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_15;
    // 0x800CF2C0: addiu       $a1, $s2, 0x3C
    ctx->r5 = ADD32(ctx->r18, 0X3C);
    after_15:
    // 0x800CF2C4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800CF2C8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CF2CC: lwc1        $f8, 0x3C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x800CF2D0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF2D4: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800CF2D8: nop

    // 0x800CF2DC: bc1fl       L_800CF2FC
    if (!c1cs) {
        // 0x800CF2E0: lhu         $t5, 0x6($s2)
        ctx->r13 = MEM_HU(ctx->r18, 0X6);
            goto L_800CF2FC;
    }
    goto skip_18;
    // 0x800CF2E0: lhu         $t5, 0x6($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X6);
    skip_18:
    // 0x800CF2E4: lhu         $t3, 0x6($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF2E8: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800CF2EC: andi        $t4, $t3, 0xFFFD
    ctx->r12 = ctx->r11 & 0XFFFD;
    // 0x800CF2F0: b           L_800D0434
    // 0x800CF2F4: sh          $t4, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r12;
        goto L_800D0434;
    // 0x800CF2F4: sh          $t4, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r12;
    // 0x800CF2F8: lhu         $t5, 0x6($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X6);
L_800CF2FC:
    // 0x800CF2FC: ori         $t6, $t5, 0x2
    ctx->r14 = ctx->r13 | 0X2;
    // 0x800CF300: b           L_800D0434
    // 0x800CF304: sh          $t6, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r14;
        goto L_800D0434;
    // 0x800CF304: sh          $t6, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r14;
L_800CF308:
    // 0x800CF308: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF30C: lbu         $t7, 0x1($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1);
    // 0x800CF310: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800CF314: sll         $s0, $s0, 8
    ctx->r16 = S32(ctx->r16 << 8);
    // 0x800CF318: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    // 0x800CF31C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800CF320: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CF324: jal         0x800CE6B8
    // 0x800CF328: lbu         $a1, 0x8($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X8);
    lbParticleMakeChildScriptID(rdram, ctx);
        goto after_16;
    // 0x800CF328: lbu         $a1, 0x8($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X8);
    after_16:
    // 0x800CF32C: beq         $v0, $zero, L_800D0434
    if (ctx->r2 == 0) {
        // 0x800CF330: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D0434;
    }
    // 0x800CF330: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CF334: lwc1        $f10, 0x20($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800CF338: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x800CF33C: lwc1        $f4, 0x24($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800CF340: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x800CF344: lwc1        $f6, 0x28($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800CF348: swc1        $f6, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f6.u32l;
    // 0x800CF34C: lhu         $t8, 0x4($s2)
    ctx->r24 = MEM_HU(ctx->r18, 0X4);
    // 0x800CF350: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x800CF354: lw          $t9, 0x58($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X58);
    // 0x800CF358: sw          $t9, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r25;
    // 0x800CF35C: lw          $t0, 0x5C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X5C);
    // 0x800CF360: beq         $t0, $zero, L_800CF374
    if (ctx->r8 == 0) {
        // 0x800CF364: sw          $t0, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->r8;
            goto L_800CF374;
    }
    // 0x800CF364: sw          $t0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r8;
    // 0x800CF368: lhu         $t1, 0x2A($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X2A);
    // 0x800CF36C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800CF370: sh          $t2, 0x2A($t0)
    MEM_H(0X2A, ctx->r8) = ctx->r10;
L_800CF374:
    // 0x800CF374: lbu         $a2, 0x8($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X8);
    // 0x800CF378: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800CF37C: jal         0x800CEF4C
    // 0x800CF380: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    lbParticleUpdateStruct(rdram, ctx);
        goto after_17;
    // 0x800CF380: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    after_17:
    // 0x800CF384: b           L_800D0438
    // 0x800CF388: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
        goto L_800D0438;
    // 0x800CF388: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
L_800CF38C:
    // 0x800CF38C: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF390: lbu         $t3, 0x1($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X1);
    // 0x800CF394: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800CF398: sll         $s0, $s0, 8
    ctx->r16 = S32(ctx->r16 << 8);
    // 0x800CF39C: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x800CF3A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800CF3A4: jal         0x800D35DC
    // 0x800CF3A8: lbu         $a0, 0x8($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X8);
    lbParticleMakeGenerator(rdram, ctx);
        goto after_18;
    // 0x800CF3A8: lbu         $a0, 0x8($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X8);
    after_18:
    // 0x800CF3AC: beql        $v0, $zero, L_800D0438
    if (ctx->r2 == 0) {
        // 0x800CF3B0: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_19;
    // 0x800CF3B0: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_19:
    // 0x800CF3B4: lwc1        $f8, 0x20($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800CF3B8: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x800CF3BC: lwc1        $f10, 0x24($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800CF3C0: swc1        $f10, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f10.u32l;
    // 0x800CF3C4: lwc1        $f4, 0x28($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800CF3C8: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x800CF3CC: lhu         $t4, 0x4($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X4);
    // 0x800CF3D0: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
    // 0x800CF3D4: lw          $t5, 0x5C($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X5C);
    // 0x800CF3D8: sw          $t5, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r13;
    // 0x800CF3DC: beq         $t5, $zero, L_800D0434
    if (ctx->r13 == 0) {
        // 0x800CF3E0: or          $v1, $t5, $zero
        ctx->r3 = ctx->r13 | 0;
            goto L_800D0434;
    }
    // 0x800CF3E0: or          $v1, $t5, $zero
    ctx->r3 = ctx->r13 | 0;
    // 0x800CF3E4: lhu         $t6, 0x2A($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2A);
    // 0x800CF3E8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800CF3EC: b           L_800D0434
    // 0x800CF3F0: sh          $t7, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r15;
        goto L_800D0434;
    // 0x800CF3F0: sh          $t7, 0x2A($v1)
    MEM_H(0X2A, ctx->r3) = ctx->r15;
L_800CF3F4:
    // 0x800CF3F4: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800CF3F8: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF3FC: lbu         $t9, 0x3($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X3);
    // 0x800CF400: lbu         $t8, 0x1($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X1);
    // 0x800CF404: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800CF408: sll         $s0, $s0, 8
    ctx->r16 = S32(ctx->r16 << 8);
    // 0x800CF40C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x800CF410: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800CF414: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x800CF418: jal         0x80018948
    // 0x800CF41C: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    syUtilsRandFloat(rdram, ctx);
        goto after_19;
    // 0x800CF41C: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    after_19:
    // 0x800CF420: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x800CF424: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800CF428: nop

    // 0x800CF42C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CF430: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800CF434: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CF438: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800CF43C: nop

    // 0x800CF440: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800CF444: b           L_800D0434
    // 0x800CF448: sh          $t2, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r10;
        goto L_800D0434;
    // 0x800CF448: sh          $t2, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r10;
L_800CF44C:
    // 0x800CF44C: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF450: jal         0x80018948
    // 0x800CF454: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    syUtilsRandFloat(rdram, ctx);
        goto after_20;
    // 0x800CF454: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    after_20:
    // 0x800CF458: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800CF45C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CF460: nop

    // 0x800CF464: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800CF468: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CF46C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800CF470: nop

    // 0x800CF474: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800CF478: bnel        $at, $zero, L_800D0438
    if (ctx->r1 != 0) {
        // 0x800CF47C: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_20;
    // 0x800CF47C: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_20:
    // 0x800CF480: lw          $t6, 0x14($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X14);
    // 0x800CF484: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800CF488: sh          $t5, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r13;
    // 0x800CF48C: b           L_800D0448
    // 0x800CF490: subu        $v0, $s1, $t6
    ctx->r2 = SUB32(ctx->r17, ctx->r14);
        goto L_800D0448;
    // 0x800CF490: subu        $v0, $s1, $t6
    ctx->r2 = SUB32(ctx->r17, ctx->r14);
L_800CF494:
    // 0x800CF494: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF498: jal         0x800CEBC0
    // 0x800CF49C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_21;
    // 0x800CF49C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_21:
    // 0x800CF4A0: jal         0x80018948
    // 0x800CF4A4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    syUtilsRandFloat(rdram, ctx);
        goto after_22;
    // 0x800CF4A4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_22:
    // 0x800CF4A8: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF4AC: lwc1        $f4, 0x20($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800CF4B0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF4B4: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CF4B8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800CF4BC: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800CF4C0: jal         0x800CEBC0
    // 0x800CF4C4: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_23;
    // 0x800CF4C4: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
    after_23:
    // 0x800CF4C8: jal         0x80018948
    // 0x800CF4CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    syUtilsRandFloat(rdram, ctx);
        goto after_24;
    // 0x800CF4CC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_24:
    // 0x800CF4D0: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF4D4: lwc1        $f6, 0x24($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800CF4D8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF4DC: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CF4E0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800CF4E4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CF4E8: jal         0x800CEBC0
    // 0x800CF4EC: swc1        $f10, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f10.u32l;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_25;
    // 0x800CF4EC: swc1        $f10, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f10.u32l;
    after_25:
    // 0x800CF4F0: jal         0x80018948
    // 0x800CF4F4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    syUtilsRandFloat(rdram, ctx);
        goto after_26;
    // 0x800CF4F4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_26:
    // 0x800CF4F8: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF4FC: lwc1        $f4, 0x28($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800CF500: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800CF504: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800CF508: b           L_800D0434
    // 0x800CF50C: swc1        $f10, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f10.u32l;
        goto L_800D0434;
    // 0x800CF50C: swc1        $f10, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f10.u32l;
L_800CF510:
    // 0x800CF510: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF514: jal         0x800CEBC0
    // 0x800CF518: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_27;
    // 0x800CF518: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_27:
    // 0x800CF51C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF520: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CF524: jal         0x800CEC34
    // 0x800CF528: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    lbParticleRotateVel(rdram, ctx);
        goto after_28;
    // 0x800CF528: lw          $a1, 0x80($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X80);
    after_28:
    // 0x800CF52C: b           L_800D0438
    // 0x800CF530: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
        goto L_800D0438;
    // 0x800CF530: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
L_800CF534:
    // 0x800CF534: lbu         $v0, 0x2($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X2);
    // 0x800CF538: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF53C: lbu         $t8, 0x3($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X3);
    // 0x800CF540: lbu         $t7, 0x1($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X1);
    // 0x800CF544: sll         $v0, $v0, 8
    ctx->r2 = S32(ctx->r2 << 8);
    // 0x800CF548: sll         $s0, $s0, 8
    ctx->r16 = S32(ctx->r16 << 8);
    // 0x800CF54C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x800CF550: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800CF554: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x800CF558: jal         0x80018948
    // 0x800CF55C: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    syUtilsRandFloat(rdram, ctx);
        goto after_29;
    // 0x800CF55C: addu        $s0, $s0, $t7
    ctx->r16 = ADD32(ctx->r16, ctx->r15);
    after_29:
    // 0x800CF560: lw          $v0, 0x88($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X88);
    // 0x800CF564: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CF568: lbu         $a1, 0x8($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X8);
    // 0x800CF56C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800CF570: nop

    // 0x800CF574: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800CF578: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CF57C: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CF580: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800CF584: nop

    // 0x800CF588: addu        $s0, $s0, $t0
    ctx->r16 = ADD32(ctx->r16, ctx->r8);
    // 0x800CF58C: jal         0x800CE6B8
    // 0x800CF590: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    lbParticleMakeChildScriptID(rdram, ctx);
        goto after_30;
    // 0x800CF590: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_30:
    // 0x800CF594: beq         $v0, $zero, L_800D0434
    if (ctx->r2 == 0) {
        // 0x800CF598: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D0434;
    }
    // 0x800CF598: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CF59C: lwc1        $f6, 0x20($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800CF5A0: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x800CF5A4: lwc1        $f4, 0x24($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800CF5A8: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x800CF5AC: lwc1        $f8, 0x28($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800CF5B0: swc1        $f8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f8.u32l;
    // 0x800CF5B4: lhu         $t1, 0x4($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X4);
    // 0x800CF5B8: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    // 0x800CF5BC: lw          $t2, 0x58($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X58);
    // 0x800CF5C0: sw          $t2, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r10;
    // 0x800CF5C4: lw          $t3, 0x5C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X5C);
    // 0x800CF5C8: beq         $t3, $zero, L_800CF5DC
    if (ctx->r11 == 0) {
        // 0x800CF5CC: sw          $t3, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->r11;
            goto L_800CF5DC;
    }
    // 0x800CF5CC: sw          $t3, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r11;
    // 0x800CF5D0: lhu         $t4, 0x2A($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X2A);
    // 0x800CF5D4: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800CF5D8: sh          $t5, 0x2A($t3)
    MEM_H(0X2A, ctx->r11) = ctx->r13;
L_800CF5DC:
    // 0x800CF5DC: lbu         $a2, 0x8($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X8);
    // 0x800CF5E0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800CF5E4: jal         0x800CEF4C
    // 0x800CF5E8: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    lbParticleUpdateStruct(rdram, ctx);
        goto after_31;
    // 0x800CF5E8: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    after_31:
    // 0x800CF5EC: b           L_800D0438
    // 0x800CF5F0: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
        goto L_800D0438;
    // 0x800CF5F0: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
L_800CF5F4:
    // 0x800CF5F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF5F8: jal         0x800CEBC0
    // 0x800CF5FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_32;
    // 0x800CF5FC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_32:
    // 0x800CF600: lwc1        $f10, 0x2C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800CF604: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF608: lwc1        $f8, 0x30($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800CF60C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF610: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800CF614: swc1        $f4, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f4.u32l;
    // 0x800CF618: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF61C: lwc1        $f4, 0x34($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800CF620: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800CF624: swc1        $f6, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f6.u32l;
    // 0x800CF628: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF62C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800CF630: b           L_800D0434
    // 0x800CF634: swc1        $f10, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f10.u32l;
        goto L_800D0434;
    // 0x800CF634: swc1        $f10, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f10.u32l;
L_800CF638:
    // 0x800CF638: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800CF63C: addiu       $a1, $s2, 0xE
    ctx->r5 = ADD32(ctx->r18, 0XE);
    // 0x800CF640: jal         0x800CEBF8
    // 0x800CF644: addiu       $s0, $s2, 0x44
    ctx->r16 = ADD32(ctx->r18, 0X44);
    lbParticleReadUShort(rdram, ctx);
        goto after_33;
    // 0x800CF644: addiu       $s0, $s2, 0x44
    ctx->r16 = ADD32(ctx->r18, 0X44);
    after_33:
    // 0x800CF648: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CF64C: jal         0x800CEBC0
    // 0x800CF650: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_34;
    // 0x800CF650: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_34:
    // 0x800CF654: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CF658: jal         0x800CEBC0
    // 0x800CF65C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_35;
    // 0x800CF65C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_35:
    // 0x800CF660: jal         0x80018948
    // 0x800CF664: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    syUtilsRandFloat(rdram, ctx);
        goto after_36;
    // 0x800CF664: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_36:
    // 0x800CF668: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF66C: lwc1        $f6, 0x44($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X44);
    // 0x800CF670: lhu         $t6, 0xE($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0XE);
    // 0x800CF674: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CF678: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800CF67C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800CF680: bne         $t6, $at, L_800D0434
    if (ctx->r14 != ctx->r1) {
        // 0x800CF684: swc1        $f10, 0x44($s2)
        MEM_W(0X44, ctx->r18) = ctx->f10.u32l;
            goto L_800D0434;
    }
    // 0x800CF684: swc1        $f10, 0x44($s2)
    MEM_W(0X44, ctx->r18) = ctx->f10.u32l;
    // 0x800CF688: lwc1        $f4, 0x44($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X44);
    // 0x800CF68C: sh          $zero, 0xE($s2)
    MEM_H(0XE, ctx->r18) = 0;
    // 0x800CF690: b           L_800D0434
    // 0x800CF694: swc1        $f4, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f4.u32l;
        goto L_800D0434;
    // 0x800CF694: swc1        $f4, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f4.u32l;
L_800CF698:
    // 0x800CF698: lhu         $t7, 0x6($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF69C: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x800CF6A0: b           L_800D0434
    // 0x800CF6A4: sh          $t8, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r24;
        goto L_800D0434;
    // 0x800CF6A4: sh          $t8, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r24;
L_800CF6A8:
    // 0x800CF6A8: lhu         $t9, 0x6($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF6AC: addiu       $at, $zero, -0x61
    ctx->r1 = ADD32(0, -0X61);
    // 0x800CF6B0: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800CF6B4: b           L_800D0434
    // 0x800CF6B8: sh          $t0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r8;
        goto L_800D0434;
    // 0x800CF6B8: sh          $t0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r8;
L_800CF6BC:
    // 0x800CF6BC: lhu         $t1, 0x6($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF6C0: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x800CF6C4: andi        $t2, $t1, 0xFFBF
    ctx->r10 = ctx->r9 & 0XFFBF;
    // 0x800CF6C8: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x800CF6CC: sh          $t2, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r10;
    // 0x800CF6D0: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x800CF6D4: b           L_800D0434
    // 0x800CF6D8: sh          $t4, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r12;
        goto L_800D0434;
    // 0x800CF6D8: sh          $t4, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r12;
L_800CF6DC:
    // 0x800CF6DC: lhu         $t5, 0x6($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF6E0: addiu       $at, $zero, -0x21
    ctx->r1 = ADD32(0, -0X21);
    // 0x800CF6E4: and         $t6, $t5, $at
    ctx->r14 = ctx->r13 & ctx->r1;
    // 0x800CF6E8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800CF6EC: sh          $t6, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r14;
    // 0x800CF6F0: ori         $t8, $t7, 0x40
    ctx->r24 = ctx->r15 | 0X40;
    // 0x800CF6F4: b           L_800D0434
    // 0x800CF6F8: sh          $t8, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r24;
        goto L_800D0434;
    // 0x800CF6F8: sh          $t8, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r24;
L_800CF6FC:
    // 0x800CF6FC: lhu         $t9, 0x6($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF700: ori         $t0, $t9, 0x60
    ctx->r8 = ctx->r25 | 0X60;
    // 0x800CF704: b           L_800D0434
    // 0x800CF708: sh          $t0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r8;
        goto L_800D0434;
    // 0x800CF708: sh          $t0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r8;
L_800CF70C:
    // 0x800CF70C: lhu         $t1, 0x6($s2)
    ctx->r9 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF710: ori         $t2, $t1, 0x200
    ctx->r10 = ctx->r9 | 0X200;
    // 0x800CF714: b           L_800D0434
    // 0x800CF718: sh          $t2, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r10;
        goto L_800D0434;
    // 0x800CF718: sh          $t2, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r10;
L_800CF71C:
    // 0x800CF71C: lhu         $t3, 0x6($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF720: addiu       $at, $zero, -0x401
    ctx->r1 = ADD32(0, -0X401);
    // 0x800CF724: andi        $t4, $t3, 0xFBFF
    ctx->r12 = ctx->r11 & 0XFBFF;
    // 0x800CF728: b           L_800D0434
    // 0x800CF72C: sh          $t4, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r12;
        goto L_800D0434;
    // 0x800CF72C: sh          $t4, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r12;
L_800CF730:
    // 0x800CF730: lhu         $t5, 0x6($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF734: ori         $t6, $t5, 0x400
    ctx->r14 = ctx->r13 | 0X400;
    // 0x800CF738: b           L_800D0434
    // 0x800CF73C: sh          $t6, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r14;
        goto L_800D0434;
    // 0x800CF73C: sh          $t6, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r14;
L_800CF740:
    // 0x800CF740: lhu         $t7, 0x6($s2)
    ctx->r15 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF744: ori         $t8, $t7, 0x100
    ctx->r24 = ctx->r15 | 0X100;
    // 0x800CF748: b           L_800D0434
    // 0x800CF74C: sh          $t8, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r24;
        goto L_800D0434;
    // 0x800CF74C: sh          $t8, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r24;
L_800CF750:
    // 0x800CF750: lhu         $t9, 0x6($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X6);
    // 0x800CF754: addiu       $at, $zero, -0x101
    ctx->r1 = ADD32(0, -0X101);
    // 0x800CF758: and         $t0, $t9, $at
    ctx->r8 = ctx->r25 & ctx->r1;
    // 0x800CF75C: b           L_800D0434
    // 0x800CF760: sh          $t0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r8;
        goto L_800D0434;
    // 0x800CF760: sh          $t0, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r8;
L_800CF764:
    // 0x800CF764: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF768: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF76C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CF770: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800CF774: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x800CF778: lw          $a1, 0x639C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X639C);
    // 0x800CF77C: jal         0x800CEDBC
    // 0x800CF780: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    lbParticleSetDistVelDObj(rdram, ctx);
        goto after_37;
    // 0x800CF780: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_37:
    // 0x800CF784: b           L_800D0438
    // 0x800CF788: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
        goto L_800D0438;
    // 0x800CF788: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
L_800CF78C:
    // 0x800CF78C: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF790: addiu       $a0, $s1, 0x1
    ctx->r4 = ADD32(ctx->r17, 0X1);
    // 0x800CF794: jal         0x800CEBC0
    // 0x800CF798: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_38;
    // 0x800CF798: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_38:
    // 0x800CF79C: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800CF7A0: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CF7A4: addu        $a1, $a1, $t2
    ctx->r5 = ADD32(ctx->r5, ctx->r10);
    // 0x800CF7A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800CF7AC: lw          $a1, 0x639C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X639C);
    // 0x800CF7B0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CF7B4: jal         0x800CEEB8
    // 0x800CF7B8: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    lbParticleAddDistVelMagDObj(rdram, ctx);
        goto after_39;
    // 0x800CF7B8: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    after_39:
    // 0x800CF7BC: b           L_800D0438
    // 0x800CF7C0: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
        goto L_800D0438;
    // 0x800CF7C0: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
L_800CF7C4:
    // 0x800CF7C4: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF7C8: lbu         $t3, 0x1($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X1);
    // 0x800CF7CC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800CF7D0: sll         $s0, $s0, 8
    ctx->r16 = S32(ctx->r16 << 8);
    // 0x800CF7D4: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x800CF7D8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800CF7DC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CF7E0: jal         0x800CE6B8
    // 0x800CF7E4: lbu         $a1, 0x8($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X8);
    lbParticleMakeChildScriptID(rdram, ctx);
        goto after_40;
    // 0x800CF7E4: lbu         $a1, 0x8($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X8);
    after_40:
    // 0x800CF7E8: beq         $v0, $zero, L_800D0434
    if (ctx->r2 == 0) {
        // 0x800CF7EC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800D0434;
    }
    // 0x800CF7EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800CF7F0: lwc1        $f6, 0x20($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800CF7F4: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x800CF7F8: lwc1        $f8, 0x24($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800CF7FC: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x800CF800: lwc1        $f10, 0x28($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800CF804: swc1        $f10, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->f10.u32l;
    // 0x800CF808: lwc1        $f4, 0x2C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800CF80C: swc1        $f4, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->f4.u32l;
    // 0x800CF810: lwc1        $f6, 0x30($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800CF814: swc1        $f6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->f6.u32l;
    // 0x800CF818: lwc1        $f8, 0x34($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800CF81C: swc1        $f8, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->f8.u32l;
    // 0x800CF820: lhu         $t4, 0x4($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X4);
    // 0x800CF824: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
    // 0x800CF828: lw          $t5, 0x58($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X58);
    // 0x800CF82C: sw          $t5, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r13;
    // 0x800CF830: lw          $t6, 0x5C($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X5C);
    // 0x800CF834: beq         $t6, $zero, L_800CF848
    if (ctx->r14 == 0) {
        // 0x800CF838: sw          $t6, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->r14;
            goto L_800CF848;
    }
    // 0x800CF838: sw          $t6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r14;
    // 0x800CF83C: lhu         $t7, 0x2A($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X2A);
    // 0x800CF840: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800CF844: sh          $t8, 0x2A($t6)
    MEM_H(0X2A, ctx->r14) = ctx->r24;
L_800CF848:
    // 0x800CF848: lbu         $a2, 0x8($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X8);
    // 0x800CF84C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800CF850: jal         0x800CEF4C
    // 0x800CF854: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    lbParticleUpdateStruct(rdram, ctx);
        goto after_41;
    // 0x800CF854: sra         $a2, $a2, 3
    ctx->r6 = S32(SIGNED(ctx->r6) >> 3);
    after_41:
    // 0x800CF858: b           L_800D0438
    // 0x800CF85C: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
        goto L_800D0438;
    // 0x800CF85C: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
L_800CF860:
    // 0x800CF860: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF864: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CF868: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CF86C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800CF870: bgez        $t9, L_800CF884
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800CF874: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800CF884;
    }
    // 0x800CF874: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CF878: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CF87C: nop

    // 0x800CF880: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800CF884:
    // 0x800CF884: jal         0x80018948
    // 0x800CF888: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_42;
    // 0x800CF888: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_42:
    // 0x800CF88C: lbu         $t0, 0x4C($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X4C);
    // 0x800CF890: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF894: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CF898: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800CF89C: nop

    // 0x800CF8A0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CF8A4: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CF8A8: bgezl       $t0, L_800CF8C0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800CF8AC: add.s       $f6, $f10, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
            goto L_800CF8C0;
    }
    goto skip_21;
    // 0x800CF8AC: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    skip_21:
    // 0x800CF8B0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CF8B4: nop

    // 0x800CF8B8: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CF8BC: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
L_800CF8C0:
    // 0x800CF8C0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800CF8C4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800CF8C8: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800CF8CC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800CF8D0: nop

    // 0x800CF8D4: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800CF8D8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800CF8DC: nop

    // 0x800CF8E0: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800CF8E4: beql        $t2, $zero, L_800CF934
    if (ctx->r10 == 0) {
        // 0x800CF8E8: mfc1        $t2, $f4
        ctx->r10 = (int32_t)ctx->f4.u32l;
            goto L_800CF934;
    }
    goto skip_22;
    // 0x800CF8E8: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    skip_22:
    // 0x800CF8EC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CF8F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x800CF8F4: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800CF8F8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800CF8FC: nop

    // 0x800CF900: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800CF904: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800CF908: nop

    // 0x800CF90C: andi        $t2, $t2, 0x78
    ctx->r10 = ctx->r10 & 0X78;
    // 0x800CF910: bne         $t2, $zero, L_800CF928
    if (ctx->r10 != 0) {
        // 0x800CF914: nop
    
            goto L_800CF928;
    }
    // 0x800CF914: nop

    // 0x800CF918: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
    // 0x800CF91C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CF920: b           L_800CF940
    // 0x800CF924: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
        goto L_800CF940;
    // 0x800CF924: or          $t2, $t2, $at
    ctx->r10 = ctx->r10 | ctx->r1;
L_800CF928:
    // 0x800CF928: b           L_800CF940
    // 0x800CF92C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
        goto L_800CF940;
    // 0x800CF92C: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800CF930: mfc1        $t2, $f4
    ctx->r10 = (int32_t)ctx->f4.u32l;
L_800CF934:
    // 0x800CF934: nop

    // 0x800CF938: bltz        $t2, L_800CF928
    if (SIGNED(ctx->r10) < 0) {
        // 0x800CF93C: nop
    
            goto L_800CF928;
    }
    // 0x800CF93C: nop

L_800CF940:
    // 0x800CF940: sb          $t2, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r10;
    // 0x800CF944: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x800CF948: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800CF94C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CF950: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800CF954: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CF958: bgez        $t3, L_800CF96C
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800CF95C: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800CF96C;
    }
    // 0x800CF95C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CF960: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CF964: nop

    // 0x800CF968: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800CF96C:
    // 0x800CF96C: jal         0x80018948
    // 0x800CF970: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_43;
    // 0x800CF970: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_43:
    // 0x800CF974: lbu         $t4, 0x4D($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X4D);
    // 0x800CF978: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CF97C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CF980: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800CF984: nop

    // 0x800CF988: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CF98C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CF990: bgezl       $t4, L_800CF9A8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800CF994: add.s       $f6, $f10, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_800CF9A8;
    }
    goto skip_23;
    // 0x800CF994: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    skip_23:
    // 0x800CF998: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CF99C: nop

    // 0x800CF9A0: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CF9A4: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
L_800CF9A8:
    // 0x800CF9A8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CF9AC: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800CF9B0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800CF9B4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800CF9B8: nop

    // 0x800CF9BC: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800CF9C0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800CF9C4: nop

    // 0x800CF9C8: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800CF9CC: beql        $t6, $zero, L_800CFA1C
    if (ctx->r14 == 0) {
        // 0x800CF9D0: mfc1        $t6, $f8
        ctx->r14 = (int32_t)ctx->f8.u32l;
            goto L_800CFA1C;
    }
    goto skip_24;
    // 0x800CF9D0: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    skip_24:
    // 0x800CF9D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CF9D8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800CF9DC: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800CF9E0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800CF9E4: nop

    // 0x800CF9E8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800CF9EC: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800CF9F0: nop

    // 0x800CF9F4: andi        $t6, $t6, 0x78
    ctx->r14 = ctx->r14 & 0X78;
    // 0x800CF9F8: bne         $t6, $zero, L_800CFA10
    if (ctx->r14 != 0) {
        // 0x800CF9FC: nop
    
            goto L_800CFA10;
    }
    // 0x800CF9FC: nop

    // 0x800CFA00: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x800CFA04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CFA08: b           L_800CFA28
    // 0x800CFA0C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
        goto L_800CFA28;
    // 0x800CFA0C: or          $t6, $t6, $at
    ctx->r14 = ctx->r14 | ctx->r1;
L_800CFA10:
    // 0x800CFA10: b           L_800CFA28
    // 0x800CFA14: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
        goto L_800CFA28;
    // 0x800CFA14: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800CFA18: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
L_800CFA1C:
    // 0x800CFA1C: nop

    // 0x800CFA20: bltz        $t6, L_800CFA10
    if (SIGNED(ctx->r14) < 0) {
        // 0x800CFA24: nop
    
            goto L_800CFA10;
    }
    // 0x800CFA24: nop

L_800CFA28:
    // 0x800CFA28: sb          $t6, 0x4D($s2)
    MEM_B(0X4D, ctx->r18) = ctx->r14;
    // 0x800CFA2C: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x800CFA30: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800CFA34: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFA38: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800CFA3C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFA40: bgez        $t7, L_800CFA54
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CFA44: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800CFA54;
    }
    // 0x800CFA44: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CFA48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFA4C: nop

    // 0x800CFA50: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800CFA54:
    // 0x800CFA54: jal         0x80018948
    // 0x800CFA58: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_44;
    // 0x800CFA58: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_44:
    // 0x800CFA5C: lbu         $t8, 0x4E($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X4E);
    // 0x800CFA60: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CFA64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFA68: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800CFA6C: nop

    // 0x800CFA70: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CFA74: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CFA78: bgezl       $t8, L_800CFA90
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800CFA7C: add.s       $f6, $f10, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
            goto L_800CFA90;
    }
    goto skip_25;
    // 0x800CFA7C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    skip_25:
    // 0x800CFA80: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFA84: nop

    // 0x800CFA88: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CFA8C: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
L_800CFA90:
    // 0x800CFA90: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CFA94: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800CFA98: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800CFA9C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800CFAA0: nop

    // 0x800CFAA4: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800CFAA8: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800CFAAC: nop

    // 0x800CFAB0: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800CFAB4: beql        $t0, $zero, L_800CFB04
    if (ctx->r8 == 0) {
        // 0x800CFAB8: mfc1        $t0, $f4
        ctx->r8 = (int32_t)ctx->f4.u32l;
            goto L_800CFB04;
    }
    goto skip_26;
    // 0x800CFAB8: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    skip_26:
    // 0x800CFABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CFAC0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CFAC4: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800CFAC8: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800CFACC: nop

    // 0x800CFAD0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800CFAD4: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800CFAD8: nop

    // 0x800CFADC: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x800CFAE0: bne         $t0, $zero, L_800CFAF8
    if (ctx->r8 != 0) {
        // 0x800CFAE4: nop
    
            goto L_800CFAF8;
    }
    // 0x800CFAE4: nop

    // 0x800CFAE8: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
    // 0x800CFAEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CFAF0: b           L_800CFB10
    // 0x800CFAF4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800CFB10;
    // 0x800CFAF4: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_800CFAF8:
    // 0x800CFAF8: b           L_800CFB10
    // 0x800CFAFC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800CFB10;
    // 0x800CFAFC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800CFB00: mfc1        $t0, $f4
    ctx->r8 = (int32_t)ctx->f4.u32l;
L_800CFB04:
    // 0x800CFB04: nop

    // 0x800CFB08: bltz        $t0, L_800CFAF8
    if (SIGNED(ctx->r8) < 0) {
        // 0x800CFB0C: nop
    
            goto L_800CFAF8;
    }
    // 0x800CFB0C: nop

L_800CFB10:
    // 0x800CFB10: sb          $t0, 0x4E($s2)
    MEM_B(0X4E, ctx->r18) = ctx->r8;
    // 0x800CFB14: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x800CFB18: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800CFB1C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFB20: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x800CFB24: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFB28: bgez        $t1, L_800CFB3C
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800CFB2C: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800CFB3C;
    }
    // 0x800CFB2C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CFB30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFB34: nop

    // 0x800CFB38: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800CFB3C:
    // 0x800CFB3C: jal         0x80018948
    // 0x800CFB40: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_45;
    // 0x800CFB40: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_45:
    // 0x800CFB44: lbu         $t2, 0x4F($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X4F);
    // 0x800CFB48: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CFB4C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFB50: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800CFB54: nop

    // 0x800CFB58: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CFB5C: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CFB60: bgezl       $t2, L_800CFB78
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800CFB64: add.s       $f6, $f10, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_800CFB78;
    }
    goto skip_27;
    // 0x800CFB64: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    skip_27:
    // 0x800CFB68: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFB6C: nop

    // 0x800CFB70: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CFB74: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
L_800CFB78:
    // 0x800CFB78: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800CFB7C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800CFB80: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800CFB84: nop

    // 0x800CFB88: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800CFB8C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800CFB90: nop

    // 0x800CFB94: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x800CFB98: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800CFB9C: beql        $t4, $zero, L_800CFBF4
    if (ctx->r12 == 0) {
        // 0x800CFBA0: mfc1        $t4, $f8
        ctx->r12 = (int32_t)ctx->f8.u32l;
            goto L_800CFBF4;
    }
    goto skip_28;
    // 0x800CFBA0: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    skip_28:
    // 0x800CFBA4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800CFBA8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CFBAC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800CFBB0: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800CFBB4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800CFBB8: nop

    // 0x800CFBBC: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800CFBC0: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800CFBC4: nop

    // 0x800CFBC8: andi        $at, $t4, 0x4
    ctx->r1 = ctx->r12 & 0X4;
    // 0x800CFBCC: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800CFBD0: bne         $t4, $zero, L_800CFBE8
    if (ctx->r12 != 0) {
        // 0x800CFBD4: nop
    
            goto L_800CFBE8;
    }
    // 0x800CFBD4: nop

    // 0x800CFBD8: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
    // 0x800CFBDC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CFBE0: b           L_800CFC00
    // 0x800CFBE4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800CFC00;
    // 0x800CFBE4: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800CFBE8:
    // 0x800CFBE8: b           L_800CFC00
    // 0x800CFBEC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800CFC00;
    // 0x800CFBEC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800CFBF0: mfc1        $t4, $f8
    ctx->r12 = (int32_t)ctx->f8.u32l;
L_800CFBF4:
    // 0x800CFBF4: nop

    // 0x800CFBF8: bltz        $t4, L_800CFBE8
    if (SIGNED(ctx->r12) < 0) {
        // 0x800CFBFC: nop
    
            goto L_800CFBE8;
    }
    // 0x800CFBFC: nop

L_800CFC00:
    // 0x800CFC00: lhu         $t5, 0x10($s2)
    ctx->r13 = MEM_HU(ctx->r18, 0X10);
    // 0x800CFC04: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800CFC08: sb          $t4, 0x4F($s2)
    MEM_B(0X4F, ctx->r18) = ctx->r12;
    // 0x800CFC0C: bnel        $t5, $zero, L_800D0438
    if (ctx->r13 != 0) {
        // 0x800CFC10: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_29;
    // 0x800CFC10: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_29:
    // 0x800CFC14: lwl         $t7, 0x4C($s2)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r18, 0X4C);
    // 0x800CFC18: lwr         $t7, 0x4F($s2)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r18, 0X4F);
    // 0x800CFC1C: swl         $t7, 0x48($s2)
    do_swl(rdram, 0X48, ctx->r18, ctx->r15);
    // 0x800CFC20: b           L_800D0434
    // 0x800CFC24: swr         $t7, 0x4B($s2)
    do_swr(rdram, 0X4B, ctx->r18, ctx->r15);
        goto L_800D0434;
    // 0x800CFC24: swr         $t7, 0x4B($s2)
    do_swr(rdram, 0X4B, ctx->r18, ctx->r15);
L_800CFC28:
    // 0x800CFC28: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x800CFC2C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFC30: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFC34: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800CFC38: bgez        $t8, L_800CFC4C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800CFC3C: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800CFC4C;
    }
    // 0x800CFC3C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CFC40: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFC44: nop

    // 0x800CFC48: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800CFC4C:
    // 0x800CFC4C: jal         0x80018948
    // 0x800CFC50: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_46;
    // 0x800CFC50: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_46:
    // 0x800CFC54: lbu         $t9, 0x54($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X54);
    // 0x800CFC58: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CFC5C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFC60: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800CFC64: nop

    // 0x800CFC68: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CFC6C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CFC70: bgezl       $t9, L_800CFC88
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800CFC74: add.s       $f6, $f10, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
            goto L_800CFC88;
    }
    goto skip_30;
    // 0x800CFC74: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    skip_30:
    // 0x800CFC78: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFC7C: nop

    // 0x800CFC80: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CFC84: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
L_800CFC88:
    // 0x800CFC88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CFC8C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800CFC90: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800CFC94: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800CFC98: nop

    // 0x800CFC9C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800CFCA0: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800CFCA4: nop

    // 0x800CFCA8: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800CFCAC: beql        $t1, $zero, L_800CFCFC
    if (ctx->r9 == 0) {
        // 0x800CFCB0: mfc1        $t1, $f4
        ctx->r9 = (int32_t)ctx->f4.u32l;
            goto L_800CFCFC;
    }
    goto skip_31;
    // 0x800CFCB0: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    skip_31:
    // 0x800CFCB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CFCB8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800CFCBC: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800CFCC0: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800CFCC4: nop

    // 0x800CFCC8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800CFCCC: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800CFCD0: nop

    // 0x800CFCD4: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800CFCD8: bne         $t1, $zero, L_800CFCF0
    if (ctx->r9 != 0) {
        // 0x800CFCDC: nop
    
            goto L_800CFCF0;
    }
    // 0x800CFCDC: nop

    // 0x800CFCE0: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800CFCE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CFCE8: b           L_800CFD08
    // 0x800CFCEC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800CFD08;
    // 0x800CFCEC: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800CFCF0:
    // 0x800CFCF0: b           L_800CFD08
    // 0x800CFCF4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800CFD08;
    // 0x800CFCF4: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800CFCF8: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
L_800CFCFC:
    // 0x800CFCFC: nop

    // 0x800CFD00: bltz        $t1, L_800CFCF0
    if (SIGNED(ctx->r9) < 0) {
        // 0x800CFD04: nop
    
            goto L_800CFCF0;
    }
    // 0x800CFD04: nop

L_800CFD08:
    // 0x800CFD08: sb          $t1, 0x54($s2)
    MEM_B(0X54, ctx->r18) = ctx->r9;
    // 0x800CFD0C: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x800CFD10: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800CFD14: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFD18: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800CFD1C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFD20: bgez        $t2, L_800CFD34
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800CFD24: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800CFD34;
    }
    // 0x800CFD24: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CFD28: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFD2C: nop

    // 0x800CFD30: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800CFD34:
    // 0x800CFD34: jal         0x80018948
    // 0x800CFD38: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_47;
    // 0x800CFD38: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_47:
    // 0x800CFD3C: lbu         $t3, 0x55($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X55);
    // 0x800CFD40: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CFD44: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFD48: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800CFD4C: nop

    // 0x800CFD50: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CFD54: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CFD58: bgezl       $t3, L_800CFD70
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800CFD5C: add.s       $f6, $f10, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_800CFD70;
    }
    goto skip_32;
    // 0x800CFD5C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    skip_32:
    // 0x800CFD60: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFD64: nop

    // 0x800CFD68: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CFD6C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
L_800CFD70:
    // 0x800CFD70: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800CFD74: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800CFD78: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800CFD7C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800CFD80: nop

    // 0x800CFD84: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800CFD88: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800CFD8C: nop

    // 0x800CFD90: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800CFD94: beql        $t5, $zero, L_800CFDE4
    if (ctx->r13 == 0) {
        // 0x800CFD98: mfc1        $t5, $f8
        ctx->r13 = (int32_t)ctx->f8.u32l;
            goto L_800CFDE4;
    }
    goto skip_33;
    // 0x800CFD98: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    skip_33:
    // 0x800CFD9C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CFDA0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800CFDA4: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800CFDA8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800CFDAC: nop

    // 0x800CFDB0: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800CFDB4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800CFDB8: nop

    // 0x800CFDBC: andi        $t5, $t5, 0x78
    ctx->r13 = ctx->r13 & 0X78;
    // 0x800CFDC0: bne         $t5, $zero, L_800CFDD8
    if (ctx->r13 != 0) {
        // 0x800CFDC4: nop
    
            goto L_800CFDD8;
    }
    // 0x800CFDC4: nop

    // 0x800CFDC8: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
    // 0x800CFDCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CFDD0: b           L_800CFDF0
    // 0x800CFDD4: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
        goto L_800CFDF0;
    // 0x800CFDD4: or          $t5, $t5, $at
    ctx->r13 = ctx->r13 | ctx->r1;
L_800CFDD8:
    // 0x800CFDD8: b           L_800CFDF0
    // 0x800CFDDC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
        goto L_800CFDF0;
    // 0x800CFDDC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800CFDE0: mfc1        $t5, $f8
    ctx->r13 = (int32_t)ctx->f8.u32l;
L_800CFDE4:
    // 0x800CFDE4: nop

    // 0x800CFDE8: bltz        $t5, L_800CFDD8
    if (SIGNED(ctx->r13) < 0) {
        // 0x800CFDEC: nop
    
            goto L_800CFDD8;
    }
    // 0x800CFDEC: nop

L_800CFDF0:
    // 0x800CFDF0: sb          $t5, 0x55($s2)
    MEM_B(0X55, ctx->r18) = ctx->r13;
    // 0x800CFDF4: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x800CFDF8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800CFDFC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFE00: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800CFE04: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFE08: bgez        $t6, L_800CFE1C
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800CFE0C: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800CFE1C;
    }
    // 0x800CFE0C: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CFE10: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFE14: nop

    // 0x800CFE18: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800CFE1C:
    // 0x800CFE1C: jal         0x80018948
    // 0x800CFE20: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_48;
    // 0x800CFE20: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_48:
    // 0x800CFE24: lbu         $t7, 0x56($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X56);
    // 0x800CFE28: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CFE2C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFE30: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800CFE34: nop

    // 0x800CFE38: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800CFE3C: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800CFE40: bgezl       $t7, L_800CFE58
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800CFE44: add.s       $f6, $f10, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
            goto L_800CFE58;
    }
    goto skip_34;
    // 0x800CFE44: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    skip_34:
    // 0x800CFE48: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFE4C: nop

    // 0x800CFE50: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CFE54: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
L_800CFE58:
    // 0x800CFE58: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800CFE5C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800CFE60: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800CFE64: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800CFE68: nop

    // 0x800CFE6C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800CFE70: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800CFE74: nop

    // 0x800CFE78: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800CFE7C: beql        $t9, $zero, L_800CFECC
    if (ctx->r25 == 0) {
        // 0x800CFE80: mfc1        $t9, $f4
        ctx->r25 = (int32_t)ctx->f4.u32l;
            goto L_800CFECC;
    }
    goto skip_35;
    // 0x800CFE80: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    skip_35:
    // 0x800CFE84: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CFE88: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800CFE8C: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800CFE90: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800CFE94: nop

    // 0x800CFE98: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800CFE9C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800CFEA0: nop

    // 0x800CFEA4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800CFEA8: bne         $t9, $zero, L_800CFEC0
    if (ctx->r25 != 0) {
        // 0x800CFEAC: nop
    
            goto L_800CFEC0;
    }
    // 0x800CFEAC: nop

    // 0x800CFEB0: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800CFEB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CFEB8: b           L_800CFED8
    // 0x800CFEBC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800CFED8;
    // 0x800CFEBC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800CFEC0:
    // 0x800CFEC0: b           L_800CFED8
    // 0x800CFEC4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800CFED8;
    // 0x800CFEC4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800CFEC8: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
L_800CFECC:
    // 0x800CFECC: nop

    // 0x800CFED0: bltz        $t9, L_800CFEC0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800CFED4: nop
    
            goto L_800CFEC0;
    }
    // 0x800CFED4: nop

L_800CFED8:
    // 0x800CFED8: sb          $t9, 0x56($s2)
    MEM_B(0X56, ctx->r18) = ctx->r25;
    // 0x800CFEDC: lbu         $t0, 0x0($s1)
    ctx->r8 = MEM_BU(ctx->r17, 0X0);
    // 0x800CFEE0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800CFEE4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFEE8: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800CFEEC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFEF0: bgez        $t0, L_800CFF04
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800CFEF4: cvt.s.w     $f8, $f10
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800CFF04;
    }
    // 0x800CFEF4: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800CFEF8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFEFC: nop

    // 0x800CFF00: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800CFF04:
    // 0x800CFF04: jal         0x80018948
    // 0x800CFF08: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_49;
    // 0x800CFF08: swc1        $f8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f8.u32l;
    after_49:
    // 0x800CFF0C: lbu         $t1, 0x57($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X57);
    // 0x800CFF10: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CFF14: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800CFF18: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800CFF1C: nop

    // 0x800CFF20: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800CFF24: mul.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800CFF28: bgezl       $t1, L_800CFF40
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800CFF2C: add.s       $f6, $f10, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
            goto L_800CFF40;
    }
    goto skip_36;
    // 0x800CFF2C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    skip_36:
    // 0x800CFF30: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800CFF34: nop

    // 0x800CFF38: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800CFF3C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
L_800CFF40:
    // 0x800CFF40: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800CFF44: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800CFF48: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800CFF4C: nop

    // 0x800CFF50: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800CFF54: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800CFF58: nop

    // 0x800CFF5C: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800CFF60: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800CFF64: beql        $t3, $zero, L_800CFFBC
    if (ctx->r11 == 0) {
        // 0x800CFF68: mfc1        $t3, $f8
        ctx->r11 = (int32_t)ctx->f8.u32l;
            goto L_800CFFBC;
    }
    goto skip_37;
    // 0x800CFF68: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    skip_37:
    // 0x800CFF6C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800CFF70: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800CFF74: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800CFF78: sub.s       $f8, $f6, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800CFF7C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800CFF80: nop

    // 0x800CFF84: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800CFF88: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800CFF8C: nop

    // 0x800CFF90: andi        $at, $t3, 0x4
    ctx->r1 = ctx->r11 & 0X4;
    // 0x800CFF94: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x800CFF98: bne         $t3, $zero, L_800CFFB0
    if (ctx->r11 != 0) {
        // 0x800CFF9C: nop
    
            goto L_800CFFB0;
    }
    // 0x800CFF9C: nop

    // 0x800CFFA0: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x800CFFA4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800CFFA8: b           L_800CFFC8
    // 0x800CFFAC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_800CFFC8;
    // 0x800CFFAC: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_800CFFB0:
    // 0x800CFFB0: b           L_800CFFC8
    // 0x800CFFB4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_800CFFC8;
    // 0x800CFFB4: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800CFFB8: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
L_800CFFBC:
    // 0x800CFFBC: nop

    // 0x800CFFC0: bltz        $t3, L_800CFFB0
    if (SIGNED(ctx->r11) < 0) {
        // 0x800CFFC4: nop
    
            goto L_800CFFB0;
    }
    // 0x800CFFC4: nop

L_800CFFC8:
    // 0x800CFFC8: lhu         $t4, 0x12($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X12);
    // 0x800CFFCC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800CFFD0: sb          $t3, 0x57($s2)
    MEM_B(0X57, ctx->r18) = ctx->r11;
    // 0x800CFFD4: bnel        $t4, $zero, L_800D0438
    if (ctx->r12 != 0) {
        // 0x800CFFD8: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_38;
    // 0x800CFFD8: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_38:
    // 0x800CFFDC: lwl         $t6, 0x54($s2)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r18, 0X54);
    // 0x800CFFE0: lwr         $t6, 0x57($s2)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r18, 0X57);
    // 0x800CFFE4: swl         $t6, 0x50($s2)
    do_swl(rdram, 0X50, ctx->r18, ctx->r14);
    // 0x800CFFE8: b           L_800D0434
    // 0x800CFFEC: swr         $t6, 0x53($s2)
    do_swr(rdram, 0X53, ctx->r18, ctx->r14);
        goto L_800D0434;
    // 0x800CFFEC: swr         $t6, 0x53($s2)
    do_swr(rdram, 0X53, ctx->r18, ctx->r14);
L_800CFFF0:
    // 0x800CFFF0: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x800CFFF4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFFF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800CFFFC: sb          $t7, 0xB($s2)
    MEM_B(0XB, ctx->r18) = ctx->r15;
    // 0x800D0000: lbu         $t8, -0x1($s1)
    ctx->r24 = MEM_BU(ctx->r17, -0X1);
    // 0x800D0004: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D0008: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800D000C: bgez        $t8, L_800D0020
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D0010: cvt.s.w     $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800D0020;
    }
    // 0x800D0010: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D0014: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D0018: nop

    // 0x800D001C: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800D0020:
    // 0x800D0020: jal         0x80018948
    // 0x800D0024: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_50;
    // 0x800D0024: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    after_50:
    // 0x800D0028: lbu         $t9, 0xB($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0XB);
    // 0x800D002C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D0030: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D0034: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800D0038: nop

    // 0x800D003C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D0040: mul.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800D0044: bgezl       $t9, L_800D005C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800D0048: add.s       $f6, $f10, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
            goto L_800D005C;
    }
    goto skip_39;
    // 0x800D0048: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    skip_39:
    // 0x800D004C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D0050: nop

    // 0x800D0054: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D0058: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
L_800D005C:
    // 0x800D005C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D0060: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800D0064: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800D0068: nop

    // 0x800D006C: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800D0070: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800D0074: nop

    // 0x800D0078: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800D007C: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800D0080: beql        $t1, $zero, L_800D00D8
    if (ctx->r9 == 0) {
        // 0x800D0084: mfc1        $t1, $f4
        ctx->r9 = (int32_t)ctx->f4.u32l;
            goto L_800D00D8;
    }
    goto skip_40;
    // 0x800D0084: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    skip_40:
    // 0x800D0088: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800D008C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D0090: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D0094: sub.s       $f4, $f6, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800D0098: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800D009C: nop

    // 0x800D00A0: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800D00A4: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800D00A8: nop

    // 0x800D00AC: andi        $at, $t1, 0x4
    ctx->r1 = ctx->r9 & 0X4;
    // 0x800D00B0: andi        $t1, $t1, 0x78
    ctx->r9 = ctx->r9 & 0X78;
    // 0x800D00B4: bne         $t1, $zero, L_800D00CC
    if (ctx->r9 != 0) {
        // 0x800D00B8: nop
    
            goto L_800D00CC;
    }
    // 0x800D00B8: nop

    // 0x800D00BC: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x800D00C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D00C4: b           L_800D00E4
    // 0x800D00C8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
        goto L_800D00E4;
    // 0x800D00C8: or          $t1, $t1, $at
    ctx->r9 = ctx->r9 | ctx->r1;
L_800D00CC:
    // 0x800D00CC: b           L_800D00E4
    // 0x800D00D0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
        goto L_800D00E4;
    // 0x800D00D0: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x800D00D4: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
L_800D00D8:
    // 0x800D00D8: nop

    // 0x800D00DC: bltz        $t1, L_800D00CC
    if (SIGNED(ctx->r9) < 0) {
        // 0x800D00E0: nop
    
            goto L_800D00CC;
    }
    // 0x800D00E0: nop

L_800D00E4:
    // 0x800D00E4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800D00E8: b           L_800D0434
    // 0x800D00EC: sb          $t1, 0xB($s2)
    MEM_B(0XB, ctx->r18) = ctx->r9;
        goto L_800D0434;
    // 0x800D00EC: sb          $t1, 0xB($s2)
    MEM_B(0XB, ctx->r18) = ctx->r9;
L_800D00F0:
    // 0x800D00F0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D00F4: jal         0x800CEBC0
    // 0x800D00F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_51;
    // 0x800D00F8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_51:
    // 0x800D00FC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D0100: jal         0x800CEBC0
    // 0x800D0104: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_52;
    // 0x800D0104: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    after_52:
    // 0x800D0108: jal         0x80018948
    // 0x800D010C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    syUtilsRandFloat(rdram, ctx);
        goto after_53;
    // 0x800D010C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    after_53:
    // 0x800D0110: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800D0114: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D0118: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800D011C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800D0120: swc1        $f4, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f4.u32l;
    // 0x800D0124: lwc1        $f2, 0x2C($s2)
    ctx->f2.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800D0128: lwc1        $f14, 0x30($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800D012C: lwc1        $f16, 0x34($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800D0130: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800D0134: nop

    // 0x800D0138: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800D013C: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800D0140: mul.s       $f4, $f16, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800D0144: jal         0x80033510
    // 0x800D0148: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_54;
    // 0x800D0148: add.s       $f12, $f6, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f4.fl;
    after_54:
    // 0x800D014C: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D0150: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x800D0154: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800D0158: swc1        $f10, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f10.u32l;
    // 0x800D015C: lwc1        $f6, 0x2C($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800D0160: lwc1        $f8, 0x30($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800D0164: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D0168: swc1        $f4, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f4.u32l;
    // 0x800D016C: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D0170: lwc1        $f4, 0x34($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800D0174: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800D0178: swc1        $f10, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f10.u32l;
    // 0x800D017C: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D0180: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800D0184: b           L_800D0434
    // 0x800D0188: swc1        $f6, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f6.u32l;
        goto L_800D0434;
    // 0x800D0188: swc1        $f6, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f6.u32l;
L_800D018C:
    // 0x800D018C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D0190: jal         0x800CEBC0
    // 0x800D0194: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_55;
    // 0x800D0194: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_55:
    // 0x800D0198: lwc1        $f10, 0x2C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800D019C: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D01A0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D01A4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800D01A8: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800D01AC: jal         0x800CEBC0
    // 0x800D01B0: swc1        $f8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f8.u32l;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_56;
    // 0x800D01B0: swc1        $f8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f8.u32l;
    after_56:
    // 0x800D01B4: lwc1        $f6, 0x30($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800D01B8: lwc1        $f10, 0x80($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D01BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800D01C0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800D01C4: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D01C8: jal         0x800CEBC0
    // 0x800D01CC: swc1        $f4, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f4.u32l;
    lbParticleReadFloatBigEnd(rdram, ctx);
        goto after_57;
    // 0x800D01CC: swc1        $f4, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f4.u32l;
    after_57:
    // 0x800D01D0: lwc1        $f8, 0x34($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800D01D4: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800D01D8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D01DC: mul.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800D01E0: b           L_800D0434
    // 0x800D01E4: swc1        $f10, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f10.u32l;
        goto L_800D0434;
    // 0x800D01E4: swc1        $f10, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f10.u32l;
L_800D01E8:
    // 0x800D01E8: lbu         $s0, 0x0($s1)
    ctx->r16 = MEM_BU(ctx->r17, 0X0);
    // 0x800D01EC: lhu         $t2, 0x6($s2)
    ctx->r10 = MEM_HU(ctx->r18, 0X6);
    // 0x800D01F0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D01F4: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x800D01F8: sll         $t4, $s0, 12
    ctx->r12 = S32(ctx->r16 << 12);
    // 0x800D01FC: ori         $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 | 0X8000;
    // 0x800D0200: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800D0204: b           L_800D0434
    // 0x800D0208: sh          $t5, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r13;
        goto L_800D0434;
    // 0x800D0208: sh          $t5, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r13;
L_800D020C:
    // 0x800D020C: addiu       $v1, $s2, 0x48
    ctx->r3 = ADD32(ctx->r18, 0X48);
    // 0x800D0210: addiu       $a2, $s2, 0x4C
    ctx->r6 = ADD32(ctx->r18, 0X4C);
    // 0x800D0214: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D0218: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800D021C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D0220: jal         0x800CEBF8
    // 0x800D0224: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    lbParticleReadUShort(rdram, ctx);
        goto after_58;
    // 0x800D0224: addiu       $a1, $s2, 0x10
    ctx->r5 = ADD32(ctx->r18, 0X10);
    after_58:
    // 0x800D0228: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800D022C: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800D0230: andi        $t8, $s0, 0x1
    ctx->r24 = ctx->r16 & 0X1;
    // 0x800D0234: lwl         $t7, 0x0($v1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r3, 0X0);
    // 0x800D0238: lwr         $t7, 0x3($v1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r3, 0X3);
    // 0x800D023C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D0240: andi        $t0, $s0, 0x2
    ctx->r8 = ctx->r16 & 0X2;
    // 0x800D0244: swl         $t7, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r15);
    // 0x800D0248: beq         $t8, $zero, L_800D025C
    if (ctx->r24 == 0) {
        // 0x800D024C: swr         $t7, 0x3($a2)
        do_swr(rdram, 0X3, ctx->r6, ctx->r15);
            goto L_800D025C;
    }
    // 0x800D024C: swr         $t7, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r15);
    // 0x800D0250: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800D0254: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x800D0258: sb          $t9, 0x4C($s2)
    MEM_B(0X4C, ctx->r18) = ctx->r25;
L_800D025C:
    // 0x800D025C: beq         $t0, $zero, L_800D0270
    if (ctx->r8 == 0) {
        // 0x800D0260: andi        $t2, $s0, 0x4
        ctx->r10 = ctx->r16 & 0X4;
            goto L_800D0270;
    }
    // 0x800D0260: andi        $t2, $s0, 0x4
    ctx->r10 = ctx->r16 & 0X4;
    // 0x800D0264: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x800D0268: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D026C: sb          $t1, 0x4D($s2)
    MEM_B(0X4D, ctx->r18) = ctx->r9;
L_800D0270:
    // 0x800D0270: beq         $t2, $zero, L_800D0284
    if (ctx->r10 == 0) {
        // 0x800D0274: andi        $t4, $s0, 0x8
        ctx->r12 = ctx->r16 & 0X8;
            goto L_800D0284;
    }
    // 0x800D0274: andi        $t4, $s0, 0x8
    ctx->r12 = ctx->r16 & 0X8;
    // 0x800D0278: lbu         $t3, 0x0($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X0);
    // 0x800D027C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D0280: sb          $t3, 0x4E($s2)
    MEM_B(0X4E, ctx->r18) = ctx->r11;
L_800D0284:
    // 0x800D0284: beql        $t4, $zero, L_800D029C
    if (ctx->r12 == 0) {
        // 0x800D0288: lhu         $t6, 0x10($s2)
        ctx->r14 = MEM_HU(ctx->r18, 0X10);
            goto L_800D029C;
    }
    goto skip_41;
    // 0x800D0288: lhu         $t6, 0x10($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X10);
    skip_41:
    // 0x800D028C: lbu         $t5, 0x0($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X0);
    // 0x800D0290: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D0294: sb          $t5, 0x4F($s2)
    MEM_B(0X4F, ctx->r18) = ctx->r13;
    // 0x800D0298: lhu         $t6, 0x10($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X10);
L_800D029C:
    // 0x800D029C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D02A0: bnel        $t6, $at, L_800D0438
    if (ctx->r14 != ctx->r1) {
        // 0x800D02A4: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_42;
    // 0x800D02A4: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_42:
    // 0x800D02A8: lwl         $t8, 0x0($a2)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r6, 0X0);
    // 0x800D02AC: lwr         $t8, 0x3($a2)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r6, 0X3);
    // 0x800D02B0: swl         $t8, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r24);
    // 0x800D02B4: swr         $t8, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r24);
    // 0x800D02B8: b           L_800D0434
    // 0x800D02BC: sh          $zero, 0x10($s2)
    MEM_H(0X10, ctx->r18) = 0;
        goto L_800D0434;
    // 0x800D02BC: sh          $zero, 0x10($s2)
    MEM_H(0X10, ctx->r18) = 0;
L_800D02C0:
    // 0x800D02C0: addiu       $v1, $s2, 0x50
    ctx->r3 = ADD32(ctx->r18, 0X50);
    // 0x800D02C4: addiu       $a2, $s2, 0x54
    ctx->r6 = ADD32(ctx->r18, 0X54);
    // 0x800D02C8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800D02CC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800D02D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800D02D4: jal         0x800CEBF8
    // 0x800D02D8: addiu       $a1, $s2, 0x12
    ctx->r5 = ADD32(ctx->r18, 0X12);
    lbParticleReadUShort(rdram, ctx);
        goto after_59;
    // 0x800D02D8: addiu       $a1, $s2, 0x12
    ctx->r5 = ADD32(ctx->r18, 0X12);
    after_59:
    // 0x800D02DC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800D02E0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x800D02E4: andi        $t1, $s0, 0x1
    ctx->r9 = ctx->r16 & 0X1;
    // 0x800D02E8: lwl         $t0, 0x0($v1)
    ctx->r8 = do_lwl(rdram, ctx->r8, ctx->r3, 0X0);
    // 0x800D02EC: lwr         $t0, 0x3($v1)
    ctx->r8 = do_lwr(rdram, ctx->r8, ctx->r3, 0X3);
    // 0x800D02F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800D02F4: andi        $t3, $s0, 0x2
    ctx->r11 = ctx->r16 & 0X2;
    // 0x800D02F8: swl         $t0, 0x0($a2)
    do_swl(rdram, 0X0, ctx->r6, ctx->r8);
    // 0x800D02FC: beq         $t1, $zero, L_800D0310
    if (ctx->r9 == 0) {
        // 0x800D0300: swr         $t0, 0x3($a2)
        do_swr(rdram, 0X3, ctx->r6, ctx->r8);
            goto L_800D0310;
    }
    // 0x800D0300: swr         $t0, 0x3($a2)
    do_swr(rdram, 0X3, ctx->r6, ctx->r8);
    // 0x800D0304: lbu         $t2, 0x0($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X0);
    // 0x800D0308: addiu       $s1, $v0, 0x1
    ctx->r17 = ADD32(ctx->r2, 0X1);
    // 0x800D030C: sb          $t2, 0x54($s2)
    MEM_B(0X54, ctx->r18) = ctx->r10;
L_800D0310:
    // 0x800D0310: beq         $t3, $zero, L_800D0324
    if (ctx->r11 == 0) {
        // 0x800D0314: andi        $t5, $s0, 0x4
        ctx->r13 = ctx->r16 & 0X4;
            goto L_800D0324;
    }
    // 0x800D0314: andi        $t5, $s0, 0x4
    ctx->r13 = ctx->r16 & 0X4;
    // 0x800D0318: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x800D031C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D0320: sb          $t4, 0x55($s2)
    MEM_B(0X55, ctx->r18) = ctx->r12;
L_800D0324:
    // 0x800D0324: beq         $t5, $zero, L_800D0338
    if (ctx->r13 == 0) {
        // 0x800D0328: andi        $t7, $s0, 0x8
        ctx->r15 = ctx->r16 & 0X8;
            goto L_800D0338;
    }
    // 0x800D0328: andi        $t7, $s0, 0x8
    ctx->r15 = ctx->r16 & 0X8;
    // 0x800D032C: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x800D0330: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D0334: sb          $t6, 0x56($s2)
    MEM_B(0X56, ctx->r18) = ctx->r14;
L_800D0338:
    // 0x800D0338: beql        $t7, $zero, L_800D0350
    if (ctx->r15 == 0) {
        // 0x800D033C: lhu         $t9, 0x12($s2)
        ctx->r25 = MEM_HU(ctx->r18, 0X12);
            goto L_800D0350;
    }
    goto skip_43;
    // 0x800D033C: lhu         $t9, 0x12($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X12);
    skip_43:
    // 0x800D0340: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x800D0344: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D0348: sb          $t8, 0x57($s2)
    MEM_B(0X57, ctx->r18) = ctx->r24;
    // 0x800D034C: lhu         $t9, 0x12($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X12);
L_800D0350:
    // 0x800D0350: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800D0354: bnel        $t9, $at, L_800D0438
    if (ctx->r25 != ctx->r1) {
        // 0x800D0358: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_44;
    // 0x800D0358: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_44:
    // 0x800D035C: lwl         $t1, 0x0($a2)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r6, 0X0);
    // 0x800D0360: lwr         $t1, 0x3($a2)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r6, 0X3);
    // 0x800D0364: swl         $t1, 0x0($v1)
    do_swl(rdram, 0X0, ctx->r3, ctx->r9);
    // 0x800D0368: swr         $t1, 0x3($v1)
    do_swr(rdram, 0X3, ctx->r3, ctx->r9);
    // 0x800D036C: b           L_800D0434
    // 0x800D0370: sh          $zero, 0x12($s2)
    MEM_H(0X12, ctx->r18) = 0;
        goto L_800D0434;
    // 0x800D0370: sh          $zero, 0x12($s2)
    MEM_H(0X12, ctx->r18) = 0;
L_800D0374:
    // 0x800D0374: lw          $t3, 0x14($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X14);
    // 0x800D0378: lbu         $t2, 0x0($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X0);
    // 0x800D037C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D0380: subu        $t4, $s1, $t3
    ctx->r12 = SUB32(ctx->r17, ctx->r11);
    // 0x800D0384: sh          $t4, 0x1C($s2)
    MEM_H(0X1C, ctx->r18) = ctx->r12;
    // 0x800D0388: b           L_800D0434
    // 0x800D038C: sb          $t2, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r10;
        goto L_800D0434;
    // 0x800D038C: sb          $t2, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r10;
L_800D0390:
    // 0x800D0390: lbu         $t5, 0x9($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X9);
    // 0x800D0394: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800D0398: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x800D039C: beq         $t7, $zero, L_800D0434
    if (ctx->r15 == 0) {
        // 0x800D03A0: sb          $t6, 0x9($s2)
        MEM_B(0X9, ctx->r18) = ctx->r14;
            goto L_800D0434;
    }
    // 0x800D03A0: sb          $t6, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r14;
    // 0x800D03A4: lw          $t8, 0x14($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X14);
    // 0x800D03A8: lhu         $t9, 0x1C($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X1C);
    // 0x800D03AC: b           L_800D0434
    // 0x800D03B0: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
        goto L_800D0434;
    // 0x800D03B0: addu        $s1, $t8, $t9
    ctx->r17 = ADD32(ctx->r24, ctx->r25);
L_800D03B4:
    // 0x800D03B4: lw          $t0, 0x14($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X14);
    // 0x800D03B8: subu        $t1, $s1, $t0
    ctx->r9 = SUB32(ctx->r17, ctx->r8);
    // 0x800D03BC: b           L_800D0434
    // 0x800D03C0: sh          $t1, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r9;
        goto L_800D0434;
    // 0x800D03C0: sh          $t1, 0x1A($s2)
    MEM_H(0X1A, ctx->r18) = ctx->r9;
L_800D03C4:
    // 0x800D03C4: lw          $t2, 0x14($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X14);
    // 0x800D03C8: lhu         $t3, 0x1A($s2)
    ctx->r11 = MEM_HU(ctx->r18, 0X1A);
    // 0x800D03CC: b           L_800D0434
    // 0x800D03D0: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
        goto L_800D0434;
    // 0x800D03D0: addu        $s1, $t2, $t3
    ctx->r17 = ADD32(ctx->r10, ctx->r11);
L_800D03D4:
    // 0x800D03D4: lw          $t5, 0x14($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X14);
    // 0x800D03D8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D03DC: sh          $t4, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r12;
    // 0x800D03E0: b           L_800D0448
    // 0x800D03E4: subu        $v0, $s1, $t5
    ctx->r2 = SUB32(ctx->r17, ctx->r13);
        goto L_800D0448;
    // 0x800D03E4: subu        $v0, $s1, $t5
    ctx->r2 = SUB32(ctx->r17, ctx->r13);
L_800D03E8:
    // 0x800D03E8: andi        $v0, $s0, 0x1F
    ctx->r2 = ctx->r16 & 0X1F;
    // 0x800D03EC: andi        $t6, $s0, 0x20
    ctx->r14 = ctx->r16 & 0X20;
    // 0x800D03F0: beq         $t6, $zero, L_800D0410
    if (ctx->r14 == 0) {
        // 0x800D03F4: sh          $v0, 0x94($sp)
        MEM_H(0X94, ctx->r29) = ctx->r2;
            goto L_800D0410;
    }
    // 0x800D03F4: sh          $v0, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r2;
    // 0x800D03F8: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x800D03FC: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x800D0400: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800D0404: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x800D0408: sh          $t0, 0x94($sp)
    MEM_H(0X94, ctx->r29) = ctx->r8;
    // 0x800D040C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_800D0410:
    // 0x800D0410: andi        $v0, $s0, 0xC0
    ctx->r2 = ctx->r16 & 0XC0;
    // 0x800D0414: beql        $v0, $zero, L_800D0438
    if (ctx->r2 == 0) {
        // 0x800D0418: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_45;
    // 0x800D0418: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_45:
    // 0x800D041C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800D0420: bnel        $v0, $at, L_800D0438
    if (ctx->r2 != ctx->r1) {
        // 0x800D0424: lhu         $t2, 0x94($sp)
        ctx->r10 = MEM_HU(ctx->r29, 0X94);
            goto L_800D0438;
    }
    goto skip_46;
    // 0x800D0424: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
    skip_46:
    // 0x800D0428: lbu         $t1, 0x0($s1)
    ctx->r9 = MEM_BU(ctx->r17, 0X0);
    // 0x800D042C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800D0430: sb          $t1, 0xB($s2)
    MEM_B(0XB, ctx->r18) = ctx->r9;
L_800D0434:
    // 0x800D0434: lhu         $t2, 0x94($sp)
    ctx->r10 = MEM_HU(ctx->r29, 0X94);
L_800D0438:
    // 0x800D0438: beql        $t2, $zero, L_800CEFB8
    if (ctx->r10 == 0) {
        // 0x800D043C: lbu         $a0, 0x0($s1)
        ctx->r4 = MEM_BU(ctx->r17, 0X0);
            goto L_800CEFB8;
    }
    goto skip_47;
    // 0x800D043C: lbu         $a0, 0x0($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X0);
    skip_47:
    // 0x800D0440: lw          $t3, 0x14($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X14);
    // 0x800D0444: subu        $v0, $s1, $t3
    ctx->r2 = SUB32(ctx->r17, ctx->r11);
L_800D0448:
    // 0x800D0448: sh          $v0, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r2;
    // 0x800D044C: lhu         $t4, 0x94($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X94);
    // 0x800D0450: sh          $t4, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r12;
L_800D0454:
    // 0x800D0454: lhu         $v0, 0xE($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0XE);
L_800D0458:
    // 0x800D0458: beql        $v0, $zero, L_800D04A0
    if (ctx->r2 == 0) {
        // 0x800D045C: lhu         $a3, 0x10($s2)
        ctx->r7 = MEM_HU(ctx->r18, 0X10);
            goto L_800D04A0;
    }
    goto skip_48;
    // 0x800D045C: lhu         $a3, 0x10($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X10);
    skip_48:
    // 0x800D0460: lwc1        $f0, 0x40($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X40);
    // 0x800D0464: lwc1        $f4, 0x44($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X44);
    // 0x800D0468: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800D046C: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800D0470: bgez        $v0, L_800D0488
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800D0474: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800D0488;
    }
    // 0x800D0474: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D0478: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D047C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D0480: nop

    // 0x800D0484: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_800D0488:
    // 0x800D0488: div.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D048C: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800D0490: sh          $t5, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r13;
    // 0x800D0494: add.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800D0498: swc1        $f4, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->f4.u32l;
    // 0x800D049C: lhu         $a3, 0x10($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X10);
L_800D04A0:
    // 0x800D04A0: beql        $a3, $zero, L_800D0574
    if (ctx->r7 == 0) {
        // 0x800D04A4: lhu         $a3, 0x12($s2)
        ctx->r7 = MEM_HU(ctx->r18, 0X12);
            goto L_800D0574;
    }
    goto skip_49;
    // 0x800D04A4: lhu         $a3, 0x12($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X12);
    skip_49:
    // 0x800D04A8: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800D04AC: div         $zero, $t6, $a3
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r7)));
    // 0x800D04B0: lbu         $v1, 0x48($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X48);
    // 0x800D04B4: lbu         $t7, 0x4C($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X4C);
    // 0x800D04B8: mflo        $v0
    ctx->r2 = lo;
    // 0x800D04BC: lbu         $a0, 0x49($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X49);
    // 0x800D04C0: subu        $t9, $t7, $v1
    ctx->r25 = SUB32(ctx->r15, ctx->r3);
    // 0x800D04C4: multu       $t9, $v0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D04C8: lbu         $t4, 0x4D($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X4D);
    // 0x800D04CC: sll         $t8, $v1, 16
    ctx->r24 = S32(ctx->r3 << 16);
    // 0x800D04D0: lbu         $a1, 0x4A($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X4A);
    // 0x800D04D4: subu        $t5, $t4, $a0
    ctx->r13 = SUB32(ctx->r12, ctx->r4);
    // 0x800D04D8: bne         $a3, $zero, L_800D04E4
    if (ctx->r7 != 0) {
        // 0x800D04DC: nop
    
            goto L_800D04E4;
    }
    // 0x800D04DC: nop

    // 0x800D04E0: break       7
    do_break(2148336864);
L_800D04E4:
    // 0x800D04E4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D04E8: bne         $a3, $at, L_800D04FC
    if (ctx->r7 != ctx->r1) {
        // 0x800D04EC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D04FC;
    }
    // 0x800D04EC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D04F0: bne         $t6, $at, L_800D04FC
    if (ctx->r14 != ctx->r1) {
        // 0x800D04F4: nop
    
            goto L_800D04FC;
    }
    // 0x800D04F4: nop

    // 0x800D04F8: break       6
    do_break(2148336888);
L_800D04FC:
    // 0x800D04FC: mflo        $t0
    ctx->r8 = lo;
    // 0x800D0500: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800D0504: lbu         $t0, 0x4E($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X4E);
    // 0x800D0508: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D050C: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800D0510: subu        $t1, $t0, $a1
    ctx->r9 = SUB32(ctx->r8, ctx->r5);
    // 0x800D0514: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x800D0518: lbu         $a2, 0x4B($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X4B);
    // 0x800D051C: sb          $t2, 0x48($s2)
    MEM_B(0X48, ctx->r18) = ctx->r10;
    // 0x800D0520: sll         $t8, $a1, 16
    ctx->r24 = S32(ctx->r5 << 16);
    // 0x800D0524: mflo        $t6
    ctx->r14 = lo;
    // 0x800D0528: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x800D052C: lbu         $t6, 0x4F($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X4F);
    // 0x800D0530: multu       $t1, $v0
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0534: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800D0538: subu        $t7, $t6, $a2
    ctx->r15 = SUB32(ctx->r14, ctx->r6);
    // 0x800D053C: sb          $t9, 0x49($s2)
    MEM_B(0X49, ctx->r18) = ctx->r25;
    // 0x800D0540: sll         $t3, $a2, 16
    ctx->r11 = S32(ctx->r6 << 16);
    // 0x800D0544: mflo        $t2
    ctx->r10 = lo;
    // 0x800D0548: addu        $t4, $t8, $t2
    ctx->r12 = ADD32(ctx->r24, ctx->r10);
    // 0x800D054C: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800D0550: multu       $t7, $v0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0554: addiu       $t8, $a3, -0x1
    ctx->r24 = ADD32(ctx->r7, -0X1);
    // 0x800D0558: sb          $t5, 0x4A($s2)
    MEM_B(0X4A, ctx->r18) = ctx->r13;
    // 0x800D055C: sh          $t8, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r24;
    // 0x800D0560: mflo        $t9
    ctx->r25 = lo;
    // 0x800D0564: addu        $t0, $t3, $t9
    ctx->r8 = ADD32(ctx->r11, ctx->r25);
    // 0x800D0568: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800D056C: sb          $t1, 0x4B($s2)
    MEM_B(0X4B, ctx->r18) = ctx->r9;
    // 0x800D0570: lhu         $a3, 0x12($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X12);
L_800D0574:
    // 0x800D0574: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x800D0578: beql        $a3, $zero, L_800D0648
    if (ctx->r7 == 0) {
        // 0x800D057C: lhu         $t9, 0x1E($s2)
        ctx->r25 = MEM_HU(ctx->r18, 0X1E);
            goto L_800D0648;
    }
    goto skip_50;
    // 0x800D057C: lhu         $t9, 0x1E($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X1E);
    skip_50:
    // 0x800D0580: div         $zero, $t2, $a3
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r7)));
    // 0x800D0584: lbu         $v1, 0x50($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X50);
    // 0x800D0588: lbu         $t5, 0x54($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X54);
    // 0x800D058C: mflo        $v0
    ctx->r2 = lo;
    // 0x800D0590: lbu         $a0, 0x51($s2)
    ctx->r4 = MEM_BU(ctx->r18, 0X51);
    // 0x800D0594: subu        $t6, $t5, $v1
    ctx->r14 = SUB32(ctx->r13, ctx->r3);
    // 0x800D0598: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D059C: lbu         $t1, 0x55($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X55);
    // 0x800D05A0: sll         $t4, $v1, 16
    ctx->r12 = S32(ctx->r3 << 16);
    // 0x800D05A4: lbu         $a1, 0x52($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X52);
    // 0x800D05A8: subu        $t8, $t1, $a0
    ctx->r24 = SUB32(ctx->r9, ctx->r4);
    // 0x800D05AC: bne         $a3, $zero, L_800D05B8
    if (ctx->r7 != 0) {
        // 0x800D05B0: nop
    
            goto L_800D05B8;
    }
    // 0x800D05B0: nop

    // 0x800D05B4: break       7
    do_break(2148337076);
L_800D05B8:
    // 0x800D05B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D05BC: bne         $a3, $at, L_800D05D0
    if (ctx->r7 != ctx->r1) {
        // 0x800D05C0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800D05D0;
    }
    // 0x800D05C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800D05C4: bne         $t2, $at, L_800D05D0
    if (ctx->r10 != ctx->r1) {
        // 0x800D05C8: nop
    
            goto L_800D05D0;
    }
    // 0x800D05C8: nop

    // 0x800D05CC: break       6
    do_break(2148337100);
L_800D05D0:
    // 0x800D05D0: mflo        $t7
    ctx->r15 = lo;
    // 0x800D05D4: addu        $t3, $t4, $t7
    ctx->r11 = ADD32(ctx->r12, ctx->r15);
    // 0x800D05D8: lbu         $t7, 0x56($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X56);
    // 0x800D05DC: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D05E0: sra         $t9, $t3, 16
    ctx->r25 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800D05E4: subu        $t3, $t7, $a1
    ctx->r11 = SUB32(ctx->r15, ctx->r5);
    // 0x800D05E8: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x800D05EC: lbu         $a2, 0x53($s2)
    ctx->r6 = MEM_BU(ctx->r18, 0X53);
    // 0x800D05F0: sb          $t9, 0x50($s2)
    MEM_B(0X50, ctx->r18) = ctx->r25;
    // 0x800D05F4: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x800D05F8: mflo        $t2
    ctx->r10 = lo;
    // 0x800D05FC: addu        $t5, $t0, $t2
    ctx->r13 = ADD32(ctx->r8, ctx->r10);
    // 0x800D0600: lbu         $t2, 0x57($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X57);
    // 0x800D0604: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0608: sra         $t6, $t5, 16
    ctx->r14 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800D060C: subu        $t5, $t2, $a2
    ctx->r13 = SUB32(ctx->r10, ctx->r6);
    // 0x800D0610: sb          $t6, 0x51($s2)
    MEM_B(0X51, ctx->r18) = ctx->r14;
    // 0x800D0614: sll         $t0, $a2, 16
    ctx->r8 = S32(ctx->r6 << 16);
    // 0x800D0618: mflo        $t9
    ctx->r25 = lo;
    // 0x800D061C: addu        $t1, $t4, $t9
    ctx->r9 = ADD32(ctx->r12, ctx->r25);
    // 0x800D0620: sra         $t8, $t1, 16
    ctx->r24 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800D0624: multu       $t5, $v0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D0628: addiu       $t4, $a3, -0x1
    ctx->r12 = ADD32(ctx->r7, -0X1);
    // 0x800D062C: sb          $t8, 0x52($s2)
    MEM_B(0X52, ctx->r18) = ctx->r24;
    // 0x800D0630: sh          $t4, 0x12($s2)
    MEM_H(0X12, ctx->r18) = ctx->r12;
    // 0x800D0634: mflo        $t6
    ctx->r14 = lo;
    // 0x800D0638: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x800D063C: sra         $t3, $t7, 16
    ctx->r11 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800D0640: sb          $t3, 0x53($s2)
    MEM_B(0X53, ctx->r18) = ctx->r11;
    // 0x800D0644: lhu         $t9, 0x1E($s2)
    ctx->r25 = MEM_HU(ctx->r18, 0X1E);
L_800D0648:
    // 0x800D0648: addiu       $t1, $t9, -0x1
    ctx->r9 = ADD32(ctx->r25, -0X1);
    // 0x800D064C: andi        $t8, $t1, 0xFFFF
    ctx->r24 = ctx->r9 & 0XFFFF;
    // 0x800D0650: bne         $t8, $zero, L_800D074C
    if (ctx->r24 != 0) {
        // 0x800D0654: sh          $t1, 0x1E($s2)
        MEM_H(0X1E, ctx->r18) = ctx->r9;
            goto L_800D074C;
    }
    // 0x800D0654: sh          $t1, 0x1E($s2)
    MEM_H(0X1E, ctx->r18) = ctx->r9;
    // 0x800D0658: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x800D065C: lw          $t0, 0xB0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XB0);
    // 0x800D0660: lw          $t3, 0xAC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XAC);
    // 0x800D0664: bne         $t2, $zero, L_800D0680
    if (ctx->r10 != 0) {
        // 0x800D0668: sll         $t6, $t0, 2
        ctx->r14 = S32(ctx->r8 << 2);
            goto L_800D0680;
    }
    // 0x800D0668: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x800D066C: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800D0670: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D0674: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800D0678: b           L_800D0688
    // 0x800D067C: sw          $t5, 0x6358($at)
    MEM_W(0X6358, ctx->r1) = ctx->r13;
        goto L_800D0688;
    // 0x800D067C: sw          $t5, 0x6358($at)
    MEM_W(0X6358, ctx->r1) = ctx->r13;
L_800D0680:
    // 0x800D0680: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800D0684: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
L_800D0688:
    // 0x800D0688: lw          $v0, 0x58($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X58);
    // 0x800D068C: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x800D0690: beql        $v0, $zero, L_800D06C8
    if (ctx->r2 == 0) {
        // 0x800D0694: lw          $a0, 0x5C($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X5C);
            goto L_800D06C8;
    }
    goto skip_51;
    // 0x800D0694: lw          $a0, 0x5C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X5C);
    skip_51:
    // 0x800D0698: lhu         $t4, 0x6($s2)
    ctx->r12 = MEM_HU(ctx->r18, 0X6);
    // 0x800D069C: andi        $t9, $t4, 0x4
    ctx->r25 = ctx->r12 & 0X4;
    // 0x800D06A0: beql        $t9, $zero, L_800D06C8
    if (ctx->r25 == 0) {
        // 0x800D06A4: lw          $a0, 0x5C($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X5C);
            goto L_800D06C8;
    }
    goto skip_52;
    // 0x800D06A4: lw          $a0, 0x5C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X5C);
    skip_52:
    // 0x800D06A8: lbu         $t1, 0x8($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X8);
    // 0x800D06AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800D06B0: bnel        $t1, $at, L_800D06C8
    if (ctx->r9 != ctx->r1) {
        // 0x800D06B4: lw          $a0, 0x5C($s2)
        ctx->r4 = MEM_W(ctx->r18, 0X5C);
            goto L_800D06C8;
    }
    goto skip_53;
    // 0x800D06B4: lw          $a0, 0x5C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X5C);
    skip_53:
    // 0x800D06B8: lhu         $t8, 0x54($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X54);
    // 0x800D06BC: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x800D06C0: sh          $t2, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r10;
    // 0x800D06C4: lw          $a0, 0x5C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X5C);
L_800D06C8:
    // 0x800D06C8: beq         $a0, $zero, L_800D071C
    if (ctx->r4 == 0) {
        // 0x800D06CC: nop
    
            goto L_800D071C;
    }
    // 0x800D06CC: nop

    // 0x800D06D0: lhu         $t0, 0x2A($a0)
    ctx->r8 = MEM_HU(ctx->r4, 0X2A);
    // 0x800D06D4: addiu       $t5, $t0, -0x1
    ctx->r13 = ADD32(ctx->r8, -0X1);
    // 0x800D06D8: sh          $t5, 0x2A($a0)
    MEM_H(0X2A, ctx->r4) = ctx->r13;
    // 0x800D06DC: lw          $a0, 0x5C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X5C);
    // 0x800D06E0: lhu         $t6, 0x2A($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X2A);
    // 0x800D06E4: bne         $t6, $zero, L_800D071C
    if (ctx->r14 != 0) {
        // 0x800D06E8: nop
    
            goto L_800D071C;
    }
    // 0x800D06E8: nop

    // 0x800D06EC: jal         0x800CE188
    // 0x800D06F0: nop

    lbParticleEjectTransform(rdram, ctx);
        goto after_60;
    // 0x800D06F0: nop

    after_60:
    // 0x800D06F4: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x800D06F8: lw          $t3, 0xB0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XB0);
    // 0x800D06FC: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800D0700: bne         $t7, $zero, L_800D071C
    if (ctx->r15 != 0) {
        // 0x800D0704: sll         $t4, $t3, 2
        ctx->r12 = S32(ctx->r11 << 2);
            goto L_800D071C;
    }
    // 0x800D0704: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800D0708: addu        $v0, $v0, $t4
    ctx->r2 = ADD32(ctx->r2, ctx->r12);
    // 0x800D070C: lw          $v0, 0x6358($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6358);
    // 0x800D0710: beq         $s0, $v0, L_800D071C
    if (ctx->r16 == ctx->r2) {
        // 0x800D0714: nop
    
            goto L_800D071C;
    }
    // 0x800D0714: nop

    // 0x800D0718: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800D071C:
    // 0x800D071C: lui         $v1, 0x800D
    ctx->r3 = S32(0X800D << 16);
    // 0x800D0720: addiu       $v1, $v1, 0x6350
    ctx->r3 = ADD32(ctx->r3, 0X6350);
    // 0x800D0724: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800D0728: lui         $a0, 0x800D
    ctx->r4 = S32(0X800D << 16);
    // 0x800D072C: addiu       $a0, $a0, 0x6448
    ctx->r4 = ADD32(ctx->r4, 0X6448);
    // 0x800D0730: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800D0734: lhu         $t1, 0x0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X0);
    // 0x800D0738: sw          $s2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r18;
    // 0x800D073C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800D0740: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x800D0744: b           L_800D0C58
    // 0x800D0748: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
        goto L_800D0C58;
    // 0x800D0748: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
L_800D074C:
    // 0x800D074C: lhu         $v0, 0x6($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X6);
    // 0x800D0750: andi        $t2, $v0, 0x4
    ctx->r10 = ctx->r2 & 0X4;
    // 0x800D0754: beq         $t2, $zero, L_800D0B80
    if (ctx->r10 == 0) {
        // 0x800D0758: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800D0B80;
    }
    // 0x800D0758: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D075C: lwc1        $f10, 0x6120($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6120);
    // 0x800D0760: lwc1        $f8, 0x38($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X38);
    // 0x800D0764: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x800D0768: addiu       $a1, $a1, -0x46B0
    ctx->r5 = ADD32(ctx->r5, -0X46B0);
    // 0x800D076C: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D0770: lw          $a2, 0x58($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X58);
    // 0x800D0774: trunc.w.s   $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D0778: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x800D077C: nop

    // 0x800D0780: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800D0784: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800D0788: andi        $t5, $v0, 0x7FF
    ctx->r13 = ctx->r2 & 0X7FF;
    // 0x800D078C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x800D0790: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x800D0794: lhu         $t3, 0x0($t7)
    ctx->r11 = MEM_HU(ctx->r15, 0X0);
    // 0x800D0798: andi        $t4, $v0, 0x800
    ctx->r12 = ctx->r2 & 0X800;
    // 0x800D079C: addiu       $v1, $v0, 0x400
    ctx->r3 = ADD32(ctx->r2, 0X400);
    // 0x800D07A0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800D07A4: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800D07A8: bgez        $t3, L_800D07C0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800D07AC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800D07C0;
    }
    // 0x800D07AC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D07B0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D07B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D07B8: nop

    // 0x800D07BC: add.s       $f10, $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f6.fl;
L_800D07C0:
    // 0x800D07C0: beq         $t4, $zero, L_800D07D4
    if (ctx->r12 == 0) {
        // 0x800D07C4: swc1        $f10, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
            goto L_800D07D4;
    }
    // 0x800D07C4: swc1        $f10, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f10.u32l;
    // 0x800D07C8: lwc1        $f4, 0x5C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D07CC: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800D07D0: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
L_800D07D4:
    // 0x800D07D4: andi        $t9, $v0, 0x7FF
    ctx->r25 = ctx->r2 & 0X7FF;
    // 0x800D07D8: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x800D07DC: addu        $t8, $a1, $t1
    ctx->r24 = ADD32(ctx->r5, ctx->r9);
    // 0x800D07E0: lhu         $t2, 0x0($t8)
    ctx->r10 = MEM_HU(ctx->r24, 0X0);
    // 0x800D07E4: andi        $t0, $v0, 0x800
    ctx->r8 = ctx->r2 & 0X800;
    // 0x800D07E8: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x800D07EC: bgez        $t2, L_800D0804
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800D07F0: cvt.s.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800D0804;
    }
    // 0x800D07F0: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D07F4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D07F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D07FC: nop

    // 0x800D0800: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_800D0804:
    // 0x800D0804: beq         $t0, $zero, L_800D0810
    if (ctx->r8 == 0) {
        // 0x800D0808: lui         $at, 0x800D
        ctx->r1 = S32(0X800D << 16);
            goto L_800D0810;
    }
    // 0x800D0808: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D080C: neg.s       $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = -ctx->f16.fl;
L_800D0810:
    // 0x800D0810: lwc1        $f4, 0x3C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x800D0814: lwc1        $f8, 0x6124($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6124);
    // 0x800D0818: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800D081C: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D0820: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800D0824: nop

    // 0x800D0828: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800D082C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800D0830: andi        $t6, $v0, 0x7FF
    ctx->r14 = ctx->r2 & 0X7FF;
    // 0x800D0834: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800D0838: addu        $t3, $a1, $t7
    ctx->r11 = ADD32(ctx->r5, ctx->r15);
    // 0x800D083C: lhu         $t4, 0x0($t3)
    ctx->r12 = MEM_HU(ctx->r11, 0X0);
    // 0x800D0840: andi        $t9, $v0, 0x800
    ctx->r25 = ctx->r2 & 0X800;
    // 0x800D0844: addiu       $v1, $v0, 0x400
    ctx->r3 = ADD32(ctx->r2, 0X400);
    // 0x800D0848: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800D084C: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800D0850: bgez        $t4, L_800D0868
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800D0854: cvt.s.w     $f8, $f4
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800D0868;
    }
    // 0x800D0854: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D0858: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D085C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D0860: nop

    // 0x800D0864: add.s       $f8, $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f6.fl;
L_800D0868:
    // 0x800D0868: beq         $t9, $zero, L_800D087C
    if (ctx->r25 == 0) {
        // 0x800D086C: swc1        $f8, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
            goto L_800D087C;
    }
    // 0x800D086C: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x800D0870: lwc1        $f10, 0x58($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D0874: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800D0878: swc1        $f4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f4.u32l;
L_800D087C:
    // 0x800D087C: andi        $t1, $v0, 0x7FF
    ctx->r9 = ctx->r2 & 0X7FF;
    // 0x800D0880: sll         $t8, $t1, 1
    ctx->r24 = S32(ctx->r9 << 1);
    // 0x800D0884: addu        $t2, $a1, $t8
    ctx->r10 = ADD32(ctx->r5, ctx->r24);
    // 0x800D0888: lhu         $t0, 0x0($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0X0);
    // 0x800D088C: andi        $t5, $v0, 0x800
    ctx->r13 = ctx->r2 & 0X800;
    // 0x800D0890: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D0894: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
    // 0x800D0898: bgez        $t0, L_800D08B0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800D089C: cvt.s.w     $f12, $f6
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800D08B0;
    }
    // 0x800D089C: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D08A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D08A4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800D08A8: nop

    // 0x800D08AC: add.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f12.fl + ctx->f8.fl;
L_800D08B0:
    // 0x800D08B0: beq         $t5, $zero, L_800D08BC
    if (ctx->r13 == 0) {
        // 0x800D08B4: lui         $at, 0x3800
        ctx->r1 = S32(0X3800 << 16);
            goto L_800D08BC;
    }
    // 0x800D08B4: lui         $at, 0x3800
    ctx->r1 = S32(0X3800 << 16);
    // 0x800D08B8: neg.s       $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = -ctx->f12.fl;
L_800D08BC:
    // 0x800D08BC: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x800D08C0: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D08C4: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800D08C8: mul.s       $f4, $f10, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f14.fl);
    // 0x800D08CC: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D08D0: mul.s       $f16, $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f14.fl);
    // 0x800D08D4: nop

    // 0x800D08D8: mul.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f14.fl);
    // 0x800D08DC: swc1        $f4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f4.u32l;
    // 0x800D08E0: mul.s       $f12, $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f14.fl);
    // 0x800D08E4: swc1        $f8, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f8.u32l;
    // 0x800D08E8: lwc1        $f10, 0x34($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800D08EC: lwc1        $f4, 0x50($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X50);
    // 0x800D08F0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D08F4: swc1        $f6, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f6.u32l;
    // 0x800D08F8: lwc1        $f0, 0x38($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X38);
    // 0x800D08FC: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800D0900: nop

    // 0x800D0904: bc1f        L_800D0918
    if (!c1cs) {
        // 0x800D0908: nop
    
            goto L_800D0918;
    }
    // 0x800D0908: nop

    // 0x800D090C: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x800D0910: b           L_800D091C
    // 0x800D0914: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
        goto L_800D091C;
    // 0x800D0914: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
L_800D0918:
    // 0x800D0918: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
L_800D091C:
    // 0x800D091C: lwc1        $f0, 0x3C($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0X3C);
    // 0x800D0920: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800D0924: nop

    // 0x800D0928: bc1fl       L_800D093C
    if (!c1cs) {
        // 0x800D092C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800D093C;
    }
    goto skip_54;
    // 0x800D092C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_54:
    // 0x800D0930: b           L_800D093C
    // 0x800D0934: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_800D093C;
    // 0x800D0934: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x800D0938: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800D093C:
    // 0x800D093C: lwc1        $f10, 0x6128($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6128);
    // 0x800D0940: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D0944: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x800D0948: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800D094C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x800D0950: nop

    // 0x800D0954: andi        $v0, $v0, 0xFFF
    ctx->r2 = ctx->r2 & 0XFFF;
    // 0x800D0958: andi        $v1, $v0, 0xFFFF
    ctx->r3 = ctx->r2 & 0XFFFF;
    // 0x800D095C: andi        $t7, $v1, 0x7FF
    ctx->r15 = ctx->r3 & 0X7FF;
    // 0x800D0960: sll         $t3, $t7, 1
    ctx->r11 = S32(ctx->r15 << 1);
    // 0x800D0964: addu        $t4, $a1, $t3
    ctx->r12 = ADD32(ctx->r5, ctx->r11);
    // 0x800D0968: lhu         $t9, 0x0($t4)
    ctx->r25 = MEM_HU(ctx->r12, 0X0);
    // 0x800D096C: addiu       $a0, $v1, 0x400
    ctx->r4 = ADD32(ctx->r3, 0X400);
    // 0x800D0970: andi        $v0, $a0, 0xFFFF
    ctx->r2 = ctx->r4 & 0XFFFF;
    // 0x800D0974: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800D0978: andi        $t1, $v1, 0x800
    ctx->r9 = ctx->r3 & 0X800;
    // 0x800D097C: bgez        $t9, L_800D0990
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800D0980: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800D0990;
    }
    // 0x800D0980: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D0984: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D0988: nop

    // 0x800D098C: add.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f10.fl;
L_800D0990:
    // 0x800D0990: beq         $t1, $zero, L_800D099C
    if (ctx->r9 == 0) {
        // 0x800D0994: andi        $t8, $v0, 0x7FF
        ctx->r24 = ctx->r2 & 0X7FF;
            goto L_800D099C;
    }
    // 0x800D0994: andi        $t8, $v0, 0x7FF
    ctx->r24 = ctx->r2 & 0X7FF;
    // 0x800D0998: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_800D099C:
    // 0x800D099C: sll         $t2, $t8, 1
    ctx->r10 = S32(ctx->r24 << 1);
    // 0x800D09A0: addu        $t0, $a1, $t2
    ctx->r8 = ADD32(ctx->r5, ctx->r10);
    // 0x800D09A4: lhu         $t5, 0x0($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0X0);
    // 0x800D09A8: andi        $t6, $v0, 0x800
    ctx->r14 = ctx->r2 & 0X800;
    // 0x800D09AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D09B0: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800D09B4: bgez        $t5, L_800D09C8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800D09B8: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800D09C8;
    }
    // 0x800D09B8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800D09BC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800D09C0: nop

    // 0x800D09C4: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_800D09C8:
    // 0x800D09C8: beq         $t6, $zero, L_800D09D8
    if (ctx->r14 == 0) {
        // 0x800D09CC: swc1        $f16, 0x54($sp)
        MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
            goto L_800D09D8;
    }
    // 0x800D09CC: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x800D09D0: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800D09D4: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
L_800D09D8:
    // 0x800D09D8: div.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800D09DC: lwc1        $f16, 0x34($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800D09E0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D09E4: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800D09E8: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x800D09EC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800D09F0: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800D09F4: lwc1        $f10, 0x30($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800D09F8: mul.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D09FC: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800D0A00: lwc1        $f4, 0x2C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800D0A04: lwc1        $f6, 0x2C($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x800D0A08: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800D0A0C: swc1        $f10, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f10.u32l;
    // 0x800D0A10: lwc1        $f4, 0x612C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X612C);
    // 0x800D0A14: lwc1        $f8, 0x2C($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800D0A18: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D0A1C: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800D0A20: trunc.w.s   $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800D0A24: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800D0A28: nop

    // 0x800D0A2C: andi        $v1, $v1, 0xFFF
    ctx->r3 = ctx->r3 & 0XFFF;
    // 0x800D0A30: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800D0A34: andi        $t3, $v0, 0x7FF
    ctx->r11 = ctx->r2 & 0X7FF;
    // 0x800D0A38: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800D0A3C: addu        $t9, $a1, $t4
    ctx->r25 = ADD32(ctx->r5, ctx->r12);
    // 0x800D0A40: lhu         $t1, 0x0($t9)
    ctx->r9 = MEM_HU(ctx->r25, 0X0);
    // 0x800D0A44: andi        $t8, $v0, 0x800
    ctx->r24 = ctx->r2 & 0X800;
    // 0x800D0A48: addiu       $v1, $v0, 0x400
    ctx->r3 = ADD32(ctx->r2, 0X400);
    // 0x800D0A4C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800D0A50: andi        $v0, $v1, 0xFFFF
    ctx->r2 = ctx->r3 & 0XFFFF;
    // 0x800D0A54: bgez        $t1, L_800D0A68
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800D0A58: cvt.s.w     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800D0A68;
    }
    // 0x800D0A58: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D0A5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D0A60: nop

    // 0x800D0A64: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_800D0A68:
    // 0x800D0A68: beq         $t8, $zero, L_800D0A74
    if (ctx->r24 == 0) {
        // 0x800D0A6C: andi        $t2, $v0, 0x7FF
        ctx->r10 = ctx->r2 & 0X7FF;
            goto L_800D0A74;
    }
    // 0x800D0A6C: andi        $t2, $v0, 0x7FF
    ctx->r10 = ctx->r2 & 0X7FF;
    // 0x800D0A70: neg.s       $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = -ctx->f18.fl;
L_800D0A74:
    // 0x800D0A74: sll         $t0, $t2, 1
    ctx->r8 = S32(ctx->r10 << 1);
    // 0x800D0A78: addu        $t5, $a1, $t0
    ctx->r13 = ADD32(ctx->r5, ctx->r8);
    // 0x800D0A7C: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800D0A80: andi        $t7, $v0, 0x800
    ctx->r15 = ctx->r2 & 0X800;
    // 0x800D0A84: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800D0A88: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800D0A8C: bgez        $t6, L_800D0AA0
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800D0A90: cvt.s.w     $f0, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800D0AA0;
    }
    // 0x800D0A90: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D0A94: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800D0A98: nop

    // 0x800D0A9C: add.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f10.fl;
L_800D0AA0:
    // 0x800D0AA0: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800D0AA4: beq         $t7, $zero, L_800D0AB8
    if (ctx->r15 == 0) {
        // 0x800D0AA8: swc1        $f12, 0x50($sp)
        MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
            goto L_800D0AB8;
    }
    // 0x800D0AA8: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x800D0AAC: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x800D0AB0: swc1        $f12, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f12.u32l;
    // 0x800D0AB4: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
L_800D0AB8:
    // 0x800D0AB8: lui         $at, 0x3800
    ctx->r1 = S32(0X3800 << 16);
    // 0x800D0ABC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800D0AC0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D0AC4: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800D0AC8: mul.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800D0ACC: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800D0AD0: mul.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D0AD4: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800D0AD8: lwc1        $f6, 0x58($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D0ADC: mul.s       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x800D0AE0: neg.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = -ctx->f2.fl;
    // 0x800D0AE4: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x800D0AE8: lwc1        $f6, 0x14($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800D0AEC: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800D0AF0: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800D0AF4: swc1        $f4, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f4.u32l;
    // 0x800D0AF8: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800D0AFC: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D0B00: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D0B04: mul.s       $f12, $f10, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800D0B08: nop

    // 0x800D0B0C: mul.s       $f6, $f14, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800D0B10: nop

    // 0x800D0B14: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D0B18: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D0B1C: mul.s       $f4, $f12, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x800D0B20: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D0B24: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800D0B28: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800D0B2C: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800D0B30: lwc1        $f4, 0x18($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X18);
    // 0x800D0B34: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800D0B38: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800D0B3C: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
    // 0x800D0B40: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800D0B44: lwc1        $f4, 0x58($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800D0B48: mul.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x800D0B4C: nop

    // 0x800D0B50: mul.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800D0B54: lwc1        $f10, 0x5C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800D0B58: mul.s       $f4, $f12, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f10.fl);
    // 0x800D0B5C: sub.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800D0B60: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800D0B64: lwc1        $f4, 0x50($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800D0B68: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800D0B6C: lwc1        $f4, 0x1C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X1C);
    // 0x800D0B70: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800D0B74: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800D0B78: b           L_800D0C04
    // 0x800D0B7C: swc1        $f10, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f10.u32l;
        goto L_800D0C04;
    // 0x800D0B7C: swc1        $f10, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f10.u32l;
L_800D0B80:
    // 0x800D0B80: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x800D0B84: beql        $t3, $zero, L_800D0BA4
    if (ctx->r11 == 0) {
        // 0x800D0B88: andi        $t4, $v0, 0x2
        ctx->r12 = ctx->r2 & 0X2;
            goto L_800D0BA4;
    }
    goto skip_55;
    // 0x800D0B88: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    skip_55:
    // 0x800D0B8C: lwc1        $f8, 0x30($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800D0B90: lwc1        $f6, 0x38($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X38);
    // 0x800D0B94: lhu         $v0, 0x6($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X6);
    // 0x800D0B98: sub.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800D0B9C: swc1        $f4, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f4.u32l;
    // 0x800D0BA0: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
L_800D0BA4:
    // 0x800D0BA4: beql        $t4, $zero, L_800D0BD8
    if (ctx->r12 == 0) {
        // 0x800D0BA8: lwc1        $f6, 0x20($s2)
        ctx->f6.u32l = MEM_W(ctx->r18, 0X20);
            goto L_800D0BD8;
    }
    goto skip_56;
    // 0x800D0BA8: lwc1        $f6, 0x20($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X20);
    skip_56:
    // 0x800D0BAC: lwc1        $f0, 0x3C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X3C);
    // 0x800D0BB0: lwc1        $f10, 0x2C($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800D0BB4: lwc1        $f6, 0x30($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800D0BB8: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D0BBC: lwc1        $f10, 0x34($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800D0BC0: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800D0BC4: swc1        $f8, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->f8.u32l;
    // 0x800D0BC8: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800D0BCC: swc1        $f4, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->f4.u32l;
    // 0x800D0BD0: swc1        $f8, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f8.u32l;
    // 0x800D0BD4: lwc1        $f6, 0x20($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X20);
L_800D0BD8:
    // 0x800D0BD8: lwc1        $f4, 0x2C($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X2C);
    // 0x800D0BDC: lwc1        $f8, 0x24($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800D0BE0: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800D0BE4: lwc1        $f6, 0x30($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X30);
    // 0x800D0BE8: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800D0BEC: swc1        $f10, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f10.u32l;
    // 0x800D0BF0: lwc1        $f10, 0x28($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800D0BF4: lwc1        $f8, 0x34($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X34);
    // 0x800D0BF8: swc1        $f4, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f4.u32l;
    // 0x800D0BFC: add.s       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800D0C00: swc1        $f6, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->f6.u32l;
L_800D0C04:
    // 0x800D0C04: lhu         $v0, 0x6($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X6);
    // 0x800D0C08: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x800D0C0C: beq         $t9, $zero, L_800D0C54
    if (ctx->r25 == 0) {
        // 0x800D0C10: andi        $s0, $v0, 0x7000
        ctx->r16 = ctx->r2 & 0X7000;
            goto L_800D0C54;
    }
    // 0x800D0C10: andi        $s0, $v0, 0x7000
    ctx->r16 = ctx->r2 & 0X7000;
    // 0x800D0C14: sra         $s0, $s0, 12
    ctx->r16 = S32(SIGNED(ctx->r16) >> 12);
    // 0x800D0C18: lui         $t8, 0x800D
    ctx->r24 = S32(0X800D << 16);
    // 0x800D0C1C: addiu       $t8, $t8, 0x63A0
    ctx->r24 = ADD32(ctx->r24, 0X63A0);
    // 0x800D0C20: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800D0C24: addu        $v1, $t1, $t8
    ctx->r3 = ADD32(ctx->r9, ctx->r24);
    // 0x800D0C28: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800D0C2C: beql        $a0, $zero, L_800D0C58
    if (ctx->r4 == 0) {
        // 0x800D0C30: lw          $v0, 0x0($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X0);
            goto L_800D0C58;
    }
    goto skip_57;
    // 0x800D0C30: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    skip_57:
    // 0x800D0C34: lwc1        $f4, 0x20($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800D0C38: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x800D0C3C: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800D0C40: lwc1        $f10, 0x24($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X24);
    // 0x800D0C44: swc1        $f10, 0x20($t2)
    MEM_W(0X20, ctx->r10) = ctx->f10.u32l;
    // 0x800D0C48: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x800D0C4C: lwc1        $f8, 0x28($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X28);
    // 0x800D0C50: swc1        $f8, 0x24($t0)
    MEM_W(0X24, ctx->r8) = ctx->f8.u32l;
L_800D0C54:
    // 0x800D0C54: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
L_800D0C58:
    // 0x800D0C58: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800D0C5C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D0C60: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D0C64: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800D0C68: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800D0C6C: jr          $ra
    // 0x800D0C70: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x800D0C70: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void itBatWaitProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80174E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80174E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80174E70: lui         $a1, 0x8017
    ctx->r5 = S32(0X8017 << 16);
    // 0x80174E74: jal         0x801735A0
    // 0x80174E78: addiu       $a1, $a1, 0x4EF8
    ctx->r5 = ADD32(ctx->r5, 0X4EF8);
    itMapCheckLRWallProcNoFloor(rdram, ctx);
        goto after_0;
    // 0x80174E78: addiu       $a1, $a1, 0x4EF8
    ctx->r5 = ADD32(ctx->r5, 0X4EF8);
    after_0:
    // 0x80174E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80174E80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80174E84: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80174E88: jr          $ra
    // 0x80174E8C: nop

    return;
    // 0x80174E8C: nop

;}
RECOMP_FUNC void func_80001FF4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001FF4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80001FF8: addiu       $v1, $v1, 0x4EE4
    ctx->r3 = ADD32(ctx->r3, 0X4EE4);
    // 0x80001FFC: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80002000: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80002004: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002008: bne         $t6, $zero, L_8000204C
    if (ctx->r14 != 0) {
        // 0x8000200C: lui         $a0, 0x8004
        ctx->r4 = S32(0X8004 << 16);
            goto L_8000204C;
    }
    // 0x8000200C: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80002010: lw          $a0, 0x4EDC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4EDC);
    // 0x80002014: beql        $a0, $zero, L_80002050
    if (ctx->r4 == 0) {
        // 0x80002018: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80002050;
    }
    goto skip_0;
    // 0x80002018: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8000201C: jal         0x80000E5C
    // 0x80002020: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    func_80000E5C(rdram, ctx);
        goto after_0;
    // 0x80002020: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    after_0:
    // 0x80002024: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80002028: addiu       $v1, $v1, 0x4EE4
    ctx->r3 = ADD32(ctx->r3, 0X4EE4);
    // 0x8000202C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80002030: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80002034: sw          $t7, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r15;
    // 0x80002038: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000203C: lw          $a3, 0x78($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X78);
    // 0x80002040: lw          $a0, 0x50($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X50);
    // 0x80002044: jal         0x80038D30
    // 0x80002048: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    osDpSetNextBuffer_recomp(rdram, ctx);
        goto after_1;
    // 0x80002048: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_1:
L_8000204C:
    // 0x8000204C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80002050:
    // 0x80002050: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002054: jr          $ra
    // 0x80002058: nop

    return;
    // 0x80002058: nop

;}
RECOMP_FUNC void ftBossMoveSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801592B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801592B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801592BC: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x801592C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801592C4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801592C8: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801592CC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801592D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801592D4: addiu       $a1, $zero, 0xDE
    ctx->r5 = ADD32(0, 0XDE);
    // 0x801592D8: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801592DC: jal         0x800E6F24
    // 0x801592E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801592E0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801592E4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801592E8: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x801592EC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801592F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801592F4: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
    // 0x801592F8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x801592FC: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x80159300: sw          $t8, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r24;
    // 0x80159304: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x80159308: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x8015930C: negu        $t1, $v1
    ctx->r9 = SUB32(0, ctx->r3);
    // 0x80159310: sw          $t7, 0xB20($v0)
    MEM_W(0XB20, ctx->r2) = ctx->r15;
    // 0x80159314: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x80159318: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8015931C: sw          $t8, 0xB24($v0)
    MEM_W(0XB24, ctx->r2) = ctx->r24;
    // 0x80159320: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x80159324: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x80159328: lwc1        $f6, 0x1C($t9)
    ctx->f6.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x8015932C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80159330: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80159334: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80159338: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x8015933C: nop

    // 0x80159340: bc1fl       L_8015936C
    if (!c1cs) {
        // 0x80159344: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015936C;
    }
    goto skip_0;
    // 0x80159344: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80159348: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8015934C: sw          $t1, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r9;
    // 0x80159350: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80159354: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80159358: lwc1        $f8, -0x383C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X383C);
    // 0x8015935C: lw          $t2, 0x8E8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8E8);
    // 0x80159360: mul.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80159364: swc1        $f16, 0x34($t2)
    MEM_W(0X34, ctx->r10) = ctx->f16.u32l;
    // 0x80159368: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015936C:
    // 0x8015936C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80159370: jr          $ra
    // 0x80159374: nop

    return;
    // 0x80159374: nop

;}
RECOMP_FUNC void ftCommonDamageSetDustEffectInterval(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80140340: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80140344: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80140348: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x8014034C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80140350: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80140354: bne         $t6, $at, L_80140370
    if (ctx->r14 != ctx->r1) {
        // 0x80140358: addiu       $a0, $a0, 0x54
        ctx->r4 = ADD32(ctx->r4, 0X54);
            goto L_80140370;
    }
    // 0x80140358: addiu       $a0, $a0, 0x54
    ctx->r4 = ADD32(ctx->r4, 0X54);
    // 0x8014035C: jal         0x80018F7C
    // 0x80140360: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    syVectorMag3D(rdram, ctx);
        goto after_0;
    // 0x80140360: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80140364: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80140368: b           L_8014039C
    // 0x8014036C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
        goto L_8014039C;
    // 0x8014036C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80140370:
    // 0x80140370: lwc1        $f0, 0x6C($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X6C);
    // 0x80140374: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80140378: nop

    // 0x8014037C: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80140380: nop

    // 0x80140384: bc1fl       L_80140398
    if (!c1cs) {
        // 0x80140388: mov.s       $f12, $f0
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
            goto L_80140398;
    }
    goto skip_0;
    // 0x80140388: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    skip_0:
    // 0x8014038C: b           L_80140398
    // 0x80140390: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
        goto L_80140398;
    // 0x80140390: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80140394: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
L_80140398:
    // 0x80140398: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_8014039C:
    // 0x8014039C: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x801403A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801403A4: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x801403A8: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x801403AC: nop

    // 0x801403B0: bc1fl       L_801403C4
    if (!c1cs) {
        // 0x801403B4: mtc1        $at, $f8
        ctx->f8.u32l = ctx->r1;
            goto L_801403C4;
    }
    goto skip_1;
    // 0x801403B4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    skip_1:
    // 0x801403B8: b           L_80140440
    // 0x801403BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80140440;
    // 0x801403BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801403C0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
L_801403C4:
    // 0x801403C4: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x801403C8: c.lt.s      $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f2.fl < ctx->f8.fl;
    // 0x801403CC: nop

    // 0x801403D0: bc1fl       L_801403E4
    if (!c1cs) {
        // 0x801403D4: mtc1        $at, $f10
        ctx->f10.u32l = ctx->r1;
            goto L_801403E4;
    }
    goto skip_2;
    // 0x801403D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    skip_2:
    // 0x801403D8: b           L_80140440
    // 0x801403DC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
        goto L_80140440;
    // 0x801403DC: addiu       $v0, $zero, 0x8
    ctx->r2 = ADD32(0, 0X8);
    // 0x801403E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
L_801403E4:
    // 0x801403E4: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x801403E8: c.lt.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl < ctx->f10.fl;
    // 0x801403EC: nop

    // 0x801403F0: bc1fl       L_80140404
    if (!c1cs) {
        // 0x801403F4: mtc1        $at, $f16
        ctx->f16.u32l = ctx->r1;
            goto L_80140404;
    }
    goto skip_3;
    // 0x801403F4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    skip_3:
    // 0x801403F8: b           L_80140440
    // 0x801403FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80140440;
    // 0x801403FC: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80140400: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
L_80140404:
    // 0x80140404: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x80140408: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x8014040C: nop

    // 0x80140410: bc1fl       L_80140424
    if (!c1cs) {
        // 0x80140414: mtc1        $at, $f18
        ctx->f18.u32l = ctx->r1;
            goto L_80140424;
    }
    goto skip_4;
    // 0x80140414: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    skip_4:
    // 0x80140418: b           L_80140440
    // 0x8014041C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80140440;
    // 0x8014041C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80140420: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
L_80140424:
    // 0x80140424: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80140428: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x8014042C: nop

    // 0x80140430: bc1f        L_80140440
    if (!c1cs) {
        // 0x80140434: nop
    
            goto L_80140440;
    }
    // 0x80140434: nop

    // 0x80140438: b           L_80140440
    // 0x8014043C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80140440;
    // 0x8014043C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80140440:
    // 0x80140440: sw          $v0, 0xB1C($a1)
    MEM_W(0XB1C, ctx->r5) = ctx->r2;
    // 0x80140444: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80140448: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8014044C: jr          $ra
    // 0x80140450: nop

    return;
    // 0x80140450: nop

;}
RECOMP_FUNC void gcEjectGObjStack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007588: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8000758C: lw          $v0, 0x66C4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X66C4);
    // 0x80007590: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007594: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007598: beq         $v0, $zero, L_800075BC
    if (ctx->r2 == 0) {
        // 0x8000759C: nop
    
            goto L_800075BC;
    }
    // 0x8000759C: nop

    // 0x800075A0: lw          $v1, 0x4($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X4);
    // 0x800075A4: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
L_800075A8:
    // 0x800075A8: beq         $v1, $t6, L_800075BC
    if (ctx->r3 == ctx->r14) {
        // 0x800075AC: nop
    
            goto L_800075BC;
    }
    // 0x800075AC: nop

    // 0x800075B0: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x800075B4: bnel        $v0, $zero, L_800075A8
    if (ctx->r2 != 0) {
        // 0x800075B8: lw          $t6, 0x8($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X8);
            goto L_800075A8;
    }
    goto skip_0;
    // 0x800075B8: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    skip_0:
L_800075BC:
    // 0x800075BC: bnel        $v0, $zero, L_800075DC
    if (ctx->r2 != 0) {
        // 0x800075C0: lw          $t7, 0x4($v0)
        ctx->r15 = MEM_W(ctx->r2, 0X4);
            goto L_800075DC;
    }
    goto skip_1;
    // 0x800075C0: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x800075C4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800075C8: jal         0x80023624
    // 0x800075CC: addiu       $a0, $a0, -0x26B0
    ctx->r4 = ADD32(ctx->r4, -0X26B0);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800075CC: addiu       $a0, $a0, -0x26B0
    ctx->r4 = ADD32(ctx->r4, -0X26B0);
    after_0:
L_800075D0:
    // 0x800075D0: b           L_800075D0
    pause_self(rdram);
    // 0x800075D4: nop

    // 0x800075D8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
L_800075DC:
    // 0x800075DC: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x800075E0: addiu       $v1, $v1, 0x66B8
    ctx->r3 = ADD32(ctx->r3, 0X66B8);
    // 0x800075E4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800075E8: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x800075EC: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800075F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800075F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800075F8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800075FC: jr          $ra
    // 0x80007600: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    return;
    // 0x80007600: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
;}
RECOMP_FUNC void sc1PGameBossMakeCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191120: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80191124: lui         $v0, 0x8001
    ctx->r2 = S32(0X8001 << 16);
    // 0x80191128: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8019112C: addiu       $v0, $v0, 0x7EC0
    ctx->r2 = ADD32(ctx->r2, 0X7EC0);
    // 0x80191130: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80191134: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80191138: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x8019113C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80191140: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80191144: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80191148: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8019114C: sw          $s1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r17;
    // 0x80191150: sw          $s0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r16;
    // 0x80191154: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80191158: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8019115C: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x80191160: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80191164: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80191168: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8019116C: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x80191170: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x80191174: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80191178: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8019117C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80191180: addiu       $a0, $zero, 0x3EF
    ctx->r4 = ADD32(0, 0X3EF);
    // 0x80191184: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80191188: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8019118C: jal         0x8000B93C
    // 0x80191190: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80191190: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80191194: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80191198: addiu       $s1, $s1, 0x14B0
    ctx->r17 = ADD32(ctx->r17, 0X14B0);
    // 0x8019119C: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x801911A0: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x801911A4: lw          $t5, 0x28($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X28);
    // 0x801911A8: lw          $t6, 0x2C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2C);
    // 0x801911AC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x801911B0: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x801911B4: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x801911B8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x801911BC: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801911C0: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x801911C4: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801911C8: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801911CC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801911D0: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801911D4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801911D8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801911DC: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x801911E0: jal         0x80007080
    // 0x801911E4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801911E4: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x801911E8: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x801911EC: lw          $t9, 0x20($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X20);
    // 0x801911F0: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    // 0x801911F4: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x801911F8: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x801911FC: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80191200: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x80191204: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80191208: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8019120C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80191210: lw          $t3, 0x80($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X80);
    // 0x80191214: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80191218: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8019121C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80191220: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x80191224: sw          $t4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r12;
    // 0x80191228: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x8019122C: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80191230: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x80191234: div.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80191238: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x8019123C: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80191240: swc1        $f16, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f16.u32l;
    // 0x80191244: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80191248: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8019124C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80191250: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80191254: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x80191258: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8019125C: addiu       $t6, $zero, 0x3C
    ctx->r14 = ADD32(0, 0X3C);
    // 0x80191260: addiu       $a0, $zero, 0x3EF
    ctx->r4 = ADD32(0, 0X3EF);
    // 0x80191264: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80191268: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8019126C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80191270: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x80191274: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x80191278: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8019127C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80191280: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80191284: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80191288: sw          $t0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r8;
    // 0x8019128C: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x80191290: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80191294: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80191298: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8019129C: jal         0x8000B93C
    // 0x801912A0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    gcMakeCameraGObj(rdram, ctx);
        goto after_2;
    // 0x801912A0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x801912A4: lw          $t3, 0x20($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X20);
    // 0x801912A8: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x801912AC: lw          $t5, 0x28($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X28);
    // 0x801912B0: lw          $t6, 0x2C($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X2C);
    // 0x801912B4: mtc1        $t3, $f18
    ctx->f18.u32l = ctx->r11;
    // 0x801912B8: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x801912BC: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x801912C0: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x801912C4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801912C8: lw          $s0, 0x74($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X74);
    // 0x801912CC: addiu       $a0, $s0, 0x8
    ctx->r4 = ADD32(ctx->r16, 0X8);
    // 0x801912D0: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801912D4: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x801912D8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801912DC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801912E0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801912E4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x801912E8: jal         0x80007080
    // 0x801912EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_3;
    // 0x801912EC: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    after_3:
    // 0x801912F0: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x801912F4: lw          $t9, 0x20($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X20);
    // 0x801912F8: lw          $t0, 0x2C($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X2C);
    // 0x801912FC: lw          $t1, 0x24($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X24);
    // 0x80191300: subu        $t7, $t8, $t9
    ctx->r15 = SUB32(ctx->r24, ctx->r25);
    // 0x80191304: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80191308: subu        $t2, $t0, $t1
    ctx->r10 = SUB32(ctx->r8, ctx->r9);
    // 0x8019130C: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x80191310: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80191314: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80191318: lw          $t3, 0x80($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X80);
    // 0x8019131C: lui         $at, 0x44FA
    ctx->r1 = S32(0X44FA << 16);
    // 0x80191320: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80191324: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80191328: ori         $t4, $t3, 0x4
    ctx->r12 = ctx->r11 | 0X4;
    // 0x8019132C: sw          $t4, 0x80($s0)
    MEM_W(0X80, ctx->r16) = ctx->r12;
    // 0x80191330: swc1        $f0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->f0.u32l;
    // 0x80191334: swc1        $f0, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f0.u32l;
    // 0x80191338: swc1        $f0, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f0.u32l;
    // 0x8019133C: div.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80191340: swc1        $f0, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f0.u32l;
    // 0x80191344: swc1        $f0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->f0.u32l;
    // 0x80191348: swc1        $f10, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f10.u32l;
    // 0x8019134C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80191350: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80191354: lw          $s1, 0x40($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X40);
    // 0x80191358: lw          $s0, 0x3C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X3C);
    // 0x8019135C: jr          $ra
    // 0x80191360: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80191360: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void sc1PIntroMakeStageInfo(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B40: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132B44: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132B48: jal         0x80131F6C
    // 0x80132B4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    sc1PIntroCheckNotBonusStage(rdram, ctx);
        goto after_0;
    // 0x80132B4C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80132B50: beq         $v0, $zero, L_80132B68
    if (ctx->r2 == 0) {
        // 0x80132B54: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80132B68;
    }
    // 0x80132B54: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80132B58: jal         0x80132B10
    // 0x80132B5C: nop

    sc1PIntroMakeNameAll(rdram, ctx);
        goto after_1;
    // 0x80132B5C: nop

    after_1:
    // 0x80132B60: b           L_80132B74
    // 0x80132B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132B74;
    // 0x80132B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132B68:
    // 0x80132B68: jal         0x80132354
    // 0x80132B6C: nop

    sc1PIntroMakeBonusTasks(rdram, ctx);
        goto after_2;
    // 0x80132B6C: nop

    after_2:
    // 0x80132B70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132B74:
    // 0x80132B74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132B78: jr          $ra
    // 0x80132B7C: nop

    return;
    // 0x80132B7C: nop

;}
RECOMP_FUNC void mn1PModeMakeSubtitle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013223C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132240: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132244: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132248: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013224C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132250: jal         0x80009968
    // 0x80132254: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132254: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132258: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013225C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132260: sw          $v0, 0x31BC($at)
    MEM_W(0X31BC, ctx->r1) = ctx->r2;
    // 0x80132264: jr          $ra
    // 0x80132268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80132268: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftPhysicsApplyFastFall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8DA0: lwc1        $f4, 0x60($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X60);
    // 0x800D8DA4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x800D8DA8: jr          $ra
    // 0x800D8DAC: swc1        $f6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x800D8DAC: swc1        $f6, 0x4C($a0)
    MEM_W(0X4C, ctx->r4) = ctx->f6.u32l;
;}
RECOMP_FUNC void ftYoshiSpecialHiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015EB38: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015EB3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015EB40: jal         0x8015EB0C
    // 0x8015EB44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftYoshiSpecialHiUpdateEggThrowForce(rdram, ctx);
        goto after_0;
    // 0x8015EB44: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015EB48: jal         0x8015EA5C
    // 0x8015EB4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftYoshiSpecialHiUpdateEggVars(rdram, ctx);
        goto after_1;
    // 0x8015EB4C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015EB50: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8015EB54: addiu       $a1, $a1, -0x1E38
    ctx->r5 = ADD32(ctx->r5, -0X1E38);
    // 0x8015EB58: jal         0x800D9480
    // 0x8015EB5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015EB5C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8015EB60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015EB64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015EB68: jr          $ra
    // 0x8015EB6C: nop

    return;
    // 0x8015EB6C: nop

;}
RECOMP_FUNC void gcDrawDObjDLHead0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80013E68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80013E6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80013E70: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80013E74: jal         0x80013D90
    // 0x80013E78: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    gcDrawDObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80013E78: addiu       $a1, $a1, 0x65B0
    ctx->r5 = ADD32(ctx->r5, 0X65B0);
    after_0:
    // 0x80013E7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80013E80: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80013E84: jr          $ra
    // 0x80013E88: nop

    return;
    // 0x80013E88: nop

;}
RECOMP_FUNC void syControllerInitRumble(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800044B4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800044B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800044BC: jal         0x800043C0
    // 0x800044C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syControllerUpdateRumbleEvent(rdram, ctx);
        goto after_0;
    // 0x800044C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800044C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800044C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800044CC: jr          $ra
    // 0x800044D0: nop

    return;
    // 0x800044D0: nop

;}
RECOMP_FUNC void SC1PGameBossWallpaper3ProcUpdate0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191AEC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80191AF0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191AF4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80191AF8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80191AFC: lw          $t7, 0x84($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X84);
    // 0x80191B00: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80191B04: bgez        $v1, L_80191B1C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80191B08: sw          $v1, 0x84($a0)
        MEM_W(0X84, ctx->r4) = ctx->r3;
            goto L_80191B1C;
    }
    // 0x80191B08: sw          $v1, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r3;
    // 0x80191B0C: jal         0x80009A84
    // 0x80191B10: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80191B10: nop

    after_0:
    // 0x80191B14: b           L_80191B38
    // 0x80191B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80191B38;
    // 0x80191B18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80191B1C:
    // 0x80191B1C: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80191B20: bne         $at, $zero, L_80191B2C
    if (ctx->r1 != 0) {
        // 0x80191B24: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_80191B2C;
    }
    // 0x80191B24: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x80191B28: sw          $t9, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r25;
L_80191B2C:
    // 0x80191B2C: jal         0x8000DF34
    // 0x80191B30: nop

    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x80191B30: nop

    after_1:
    // 0x80191B34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80191B38:
    // 0x80191B38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80191B3C: jr          $ra
    // 0x80191B40: nop

    return;
    // 0x80191B40: nop

;}
RECOMP_FUNC void func_ovl8_8037BEC8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037BEC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8037BECC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8037BED0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037BED4: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8037BED8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8037BEDC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8037BEE0: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
L_8037BEE4:
    // 0x8037BEE4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8037BEE8: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x8037BEEC: lw          $t9, 0x74($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X74);
    // 0x8037BEF0: lh          $t6, 0x70($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X70);
    // 0x8037BEF4: jalr        $t9
    // 0x8037BEF8: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8037BEF8: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x8037BEFC: jal         0x8000B1E8
    // 0x8037BF00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_1;
    // 0x8037BF00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x8037BF04: b           L_8037BEE4
    // 0x8037BF08: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
        goto L_8037BEE4;
    // 0x8037BF08: lw          $v1, 0x10($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X10);
    // 0x8037BF0C: nop

    // 0x8037BF10: nop

    // 0x8037BF14: nop

    // 0x8037BF18: nop

    // 0x8037BF1C: nop

    // 0x8037BF20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037BF24: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8037BF28: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8037BF2C: jr          $ra
    // 0x8037BF30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8037BF30: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void syMatrixRotRpR(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001CEFC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001CF00: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001CF04: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001CF08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8001CF0C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8001CF10: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001CF14: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001CF18: jal         0x8001CE30
    // 0x8001CF1C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    syMatrixRotRpRF(rdram, ctx);
        goto after_0;
    // 0x8001CF1C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8001CF20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x8001CF24: jal         0x80019EA0
    // 0x8001CF28: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x8001CF28: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x8001CF2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8001CF30: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x8001CF34: jr          $ra
    // 0x8001CF38: nop

    return;
    // 0x8001CF38: nop

;}
RECOMP_FUNC void mvOpeningLinkMakeMotionWindow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D5F4: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x8018D5F8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D5FC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8018D600: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8018D604: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D608: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D60C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D610: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D614: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D618: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D61C: jal         0x80104BDC
    // 0x8018D620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_0;
    // 0x8018D620: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8018D624: jal         0x80105600
    // 0x8018D628: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_1;
    // 0x8018D628: nop

    after_1:
    // 0x8018D62C: jal         0x800FC7A4
    // 0x8018D630: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    mpCollisionGetMapObjCountKind(rdram, ctx);
        goto after_2;
    // 0x8018D630: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    after_2:
    // 0x8018D634: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018D638: beq         $v0, $at, L_8018D660
    if (ctx->r2 == ctx->r1) {
        // 0x8018D63C: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8018D660;
    }
    // 0x8018D63C: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8018D640: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018D644: addiu       $s0, $s0, -0x1E70
    ctx->r16 = ADD32(ctx->r16, -0X1E70);
L_8018D648:
    // 0x8018D648: jal         0x80023624
    // 0x8018D64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_3;
    // 0x8018D64C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018D650: jal         0x800A3040
    // 0x8018D654: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_4;
    // 0x8018D654: nop

    after_4:
    // 0x8018D658: b           L_8018D648
    // 0x8018D65C: nop

        goto L_8018D648;
    // 0x8018D65C: nop

L_8018D660:
    // 0x8018D660: jal         0x800FC814
    // 0x8018D664: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_5;
    // 0x8018D664: addiu       $a1, $sp, 0x9C
    ctx->r5 = ADD32(ctx->r29, 0X9C);
    after_5:
    // 0x8018D668: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x8018D66C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D670: jal         0x800FC894
    // 0x8018D674: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_6;
    // 0x8018D674: lw          $a0, 0x9C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X9C);
    after_6:
    // 0x8018D678: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8018D67C: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x8018D680: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x8018D684: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x8018D688: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8018D68C: lw          $a2, 0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X8);
    // 0x8018D690: jal         0x8018D3EC
    // 0x8018D694: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    mvOpeningLinkMakeMotionCamera(rdram, ctx);
        goto after_7;
    // 0x8018D694: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_7:
    // 0x8018D698: jal         0x801156E4
    // 0x8018D69C: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_8;
    // 0x8018D69C: nop

    after_8:
    // 0x8018D6A0: jal         0x801653E0
    // 0x8018D6A4: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_9;
    // 0x8018D6A4: nop

    after_9:
    // 0x8018D6A8: lui         $s6, 0x8011
    ctx->r22 = S32(0X8011 << 16);
    // 0x8018D6AC: lui         $s5, 0x800A
    ctx->r21 = S32(0X800A << 16);
    // 0x8018D6B0: addiu       $s5, $s5, 0x50E8
    ctx->r21 = ADD32(ctx->r21, 0X50E8);
    // 0x8018D6B4: addiu       $s6, $s6, 0x6DD0
    ctx->r22 = ADD32(ctx->r22, 0X6DD0);
    // 0x8018D6B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D6BC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018D6C0: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x8018D6C4: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8018D6C8: addiu       $s4, $sp, 0x50
    ctx->r20 = ADD32(ctx->r29, 0X50);
L_8018D6CC:
    // 0x8018D6CC: or          $t0, $s6, $zero
    ctx->r8 = ctx->r22 | 0;
    // 0x8018D6D0: or          $t1, $s4, $zero
    ctx->r9 = ctx->r20 | 0;
    // 0x8018D6D4: addiu       $t2, $s6, 0x3C
    ctx->r10 = ADD32(ctx->r22, 0X3C);
L_8018D6D8:
    // 0x8018D6D8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D6DC: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8018D6E0: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018D6E4: sw          $t9, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r25;
    // 0x8018D6E8: lw          $t8, -0x8($t0)
    ctx->r24 = MEM_W(ctx->r8, -0X8);
    // 0x8018D6EC: sw          $t8, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r24;
    // 0x8018D6F0: lw          $t9, -0x4($t0)
    ctx->r25 = MEM_W(ctx->r8, -0X4);
    // 0x8018D6F4: bne         $t0, $t2, L_8018D6D8
    if (ctx->r8 != ctx->r10) {
        // 0x8018D6F8: sw          $t9, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r25;
            goto L_8018D6D8;
    }
    // 0x8018D6F8: sw          $t9, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r25;
    // 0x8018D6FC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x8018D700: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8018D704: addu        $t5, $t5, $s1
    ctx->r13 = ADD32(ctx->r13, ctx->r17);
    // 0x8018D708: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8018D70C: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x8018D710: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8018D714: addiu       $t6, $t6, 0x5228
    ctx->r14 = ADD32(ctx->r14, 0X5228);
    // 0x8018D718: addu        $s0, $t3, $s2
    ctx->r16 = ADD32(ctx->r11, ctx->r18);
    // 0x8018D71C: lbu         $t4, 0x22($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D720: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8018D724: addu        $s3, $t5, $t6
    ctx->r19 = ADD32(ctx->r13, ctx->r14);
    // 0x8018D728: beql        $s7, $t4, L_8018D7EC
    if (ctx->r23 == ctx->r12) {
        // 0x8018D72C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_8018D7EC;
    }
    goto skip_0;
    // 0x8018D72C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    skip_0:
    // 0x8018D730: jal         0x800D786C
    // 0x8018D734: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_10;
    // 0x8018D734: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_10:
    // 0x8018D738: lw          $v0, 0x0($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X0);
    // 0x8018D73C: lwc1        $f4, 0x90($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8018D740: lwc1        $f6, 0x94($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8018D744: addu        $s0, $v0, $s2
    ctx->r16 = ADD32(ctx->r2, ctx->r18);
    // 0x8018D748: lbu         $t7, 0x23($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D74C: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x8018D750: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D754: sw          $t2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r10;
    // 0x8018D758: swc1        $f4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f4.u32l;
    // 0x8018D75C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x8018D760: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
    // 0x8018D764: swc1        $f8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f8.u32l;
    // 0x8018D768: lbu         $t0, 0x24($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X24);
    // 0x8018D76C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D770: sb          $s1, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r17;
    // 0x8018D774: sb          $t1, 0x66($sp)
    MEM_B(0X66, ctx->r29) = ctx->r9;
    // 0x8018D778: sb          $t0, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r8;
    // 0x8018D77C: lbu         $t8, 0x26($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X26);
    // 0x8018D780: sb          $t8, 0x67($sp)
    MEM_B(0X67, ctx->r29) = ctx->r24;
    // 0x8018D784: lbu         $t9, 0x21($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X21);
    // 0x8018D788: sb          $t9, 0x69($sp)
    MEM_B(0X69, ctx->r29) = ctx->r25;
    // 0x8018D78C: lbu         $t3, 0x20($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X20);
    // 0x8018D790: sb          $t3, 0x6A($sp)
    MEM_B(0X6A, ctx->r29) = ctx->r11;
    // 0x8018D794: lbu         $t4, 0x7($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X7);
    // 0x8018D798: sw          $zero, 0x74($sp)
    MEM_W(0X74, ctx->r29) = 0;
    // 0x8018D79C: sb          $t4, 0x6B($sp)
    MEM_B(0X6B, ctx->r29) = ctx->r12;
    // 0x8018D7A0: lbu         $t5, 0x22($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D7A4: sw          $s3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r19;
    // 0x8018D7A8: sw          $t5, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r13;
    // 0x8018D7AC: jal         0x800D78B4
    // 0x8018D7B0: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_11;
    // 0x8018D7B0: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_11:
    // 0x8018D7B4: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x8018D7B8: jal         0x800D7F3C
    // 0x8018D7BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_12;
    // 0x8018D7BC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x8018D7C0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D7C4: sw          $v0, -0x1E30($at)
    MEM_W(-0X1E30, ctx->r1) = ctx->r2;
    // 0x8018D7C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D7CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D7D0: jal         0x800E7C4C
    // 0x8018D7D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_13;
    // 0x8018D7D4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_13:
    // 0x8018D7D8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D7DC: addiu       $a1, $a1, -0x1F58
    ctx->r5 = ADD32(ctx->r5, -0X1F58);
    // 0x8018D7E0: jal         0x800E9B30
    // 0x8018D7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetKey(rdram, ctx);
        goto after_14;
    // 0x8018D7E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_14:
    // 0x8018D7E8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_8018D7EC:
    // 0x8018D7EC: bne         $s1, $fp, L_8018D6CC
    if (ctx->r17 != ctx->r30) {
        // 0x8018D7F0: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018D6CC;
    }
    // 0x8018D7F0: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018D7F4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D7F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018D7FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018D800: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018D804: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018D808: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018D80C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018D810: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018D814: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8018D818: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8018D81C: jr          $ra
    // 0x8018D820: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    return;
    // 0x8018D820: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
;}
RECOMP_FUNC void gcParseMObjMatAnimJoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CF6C: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8000CF70: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8000CF74: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8000CF78: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8000CF7C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8000CF80: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8000CF84: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8000CF88: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8000CF8C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8000CF90: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8000CF94: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8000CF98: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8000CF9C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8000CFA0: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8000CFA4: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000CFA8: lwc1        $f4, -0x2190($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2190);
    // 0x8000CFAC: lwc1        $f0, 0x98($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X98);
    // 0x8000CFB0: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8000CFB4: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000CFB8: c.eq.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl == ctx->f0.fl;
    // 0x8000CFBC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000CFC0: addiu       $s0, $sp, 0x90
    ctx->r16 = ADD32(ctx->r29, 0X90);
    // 0x8000CFC4: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
    // 0x8000CFC8: bc1t        L_8000DA04
    if (c1cs) {
        // 0x8000CFCC: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_8000DA04;
    }
    // 0x8000CFCC: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8000CFD0: lwc1        $f6, -0x218C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X218C);
    // 0x8000CFD4: addiu       $t7, $sp, 0x7C
    ctx->r15 = ADD32(ctx->r29, 0X7C);
    // 0x8000CFD8: addiu       $s5, $sp, 0x90
    ctx->r21 = ADD32(ctx->r29, 0X90);
    // 0x8000CFDC: c.eq.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl == ctx->f0.fl;
    // 0x8000CFE0: addiu       $fp, $zero, 0x5
    ctx->r30 = ADD32(0, 0X5);
    // 0x8000CFE4: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x8000CFE8: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x8000CFEC: bc1f        L_8000D008
    if (!c1cs) {
        // 0x8000CFF0: addiu       $s4, $zero, 0xA
        ctx->r20 = ADD32(0, 0XA);
            goto L_8000D008;
    }
    // 0x8000CFF0: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x8000CFF4: lwc1        $f8, 0xA0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0XA0);
    // 0x8000CFF8: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000CFFC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8000D000: b           L_8000D038
    // 0x8000D004: swc1        $f10, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f10.u32l;
        goto L_8000D038;
    // 0x8000D004: swc1        $f10, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f10.u32l;
L_8000D008:
    // 0x8000D008: lwc1        $f2, 0x9C($s3)
    ctx->f2.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x8000D00C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000D010: lwc1        $f18, 0xA0($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0XA0);
    // 0x8000D014: sub.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8000D018: add.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8000D01C: swc1        $f16, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f16.u32l;
    // 0x8000D020: lwc1        $f6, 0x98($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D024: swc1        $f4, 0xA0($s3)
    MEM_W(0XA0, ctx->r19) = ctx->f4.u32l;
    // 0x8000D028: c.lt.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl < ctx->f6.fl;
    // 0x8000D02C: nop

    // 0x8000D030: bc1tl       L_8000DA08
    if (c1cs) {
        // 0x8000D034: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8000DA08;
    }
    goto skip_0;
    // 0x8000D034: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    skip_0:
L_8000D038:
    // 0x8000D038: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000D03C: sltu        $at, $s0, $v0
    ctx->r1 = ctx->r16 < ctx->r2 ? 1 : 0;
    // 0x8000D040: bne         $at, $zero, L_8000D038
    if (ctx->r1 != 0) {
        // 0x8000D044: sw          $zero, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = 0;
            goto L_8000D038;
    }
    // 0x8000D044: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x8000D048: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8000D04C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x8000D050: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000D054: sw          $zero, 0x8($s0)
    MEM_W(0X8, ctx->r16) = 0;
    // 0x8000D058: sw          $zero, 0xC($s0)
    MEM_W(0XC, ctx->r16) = 0;
    // 0x8000D05C: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8000D060: lw          $v0, 0x90($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X90);
    // 0x8000D064: beql        $v0, $zero, L_8000D0BC
    if (ctx->r2 == 0) {
        // 0x8000D068: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000D0BC;
    }
    goto skip_1;
    // 0x8000D068: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x8000D06C: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
L_8000D070:
    // 0x8000D070: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x8000D074: bne         $at, $zero, L_8000D090
    if (ctx->r1 != 0) {
        // 0x8000D078: slti        $at, $v1, 0x17
        ctx->r1 = SIGNED(ctx->r3) < 0X17 ? 1 : 0;
            goto L_8000D090;
    }
    // 0x8000D078: slti        $at, $v1, 0x17
    ctx->r1 = SIGNED(ctx->r3) < 0X17 ? 1 : 0;
    // 0x8000D07C: beq         $at, $zero, L_8000D090
    if (ctx->r1 == 0) {
        // 0x8000D080: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_8000D090;
    }
    // 0x8000D080: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x8000D084: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x8000D088: sw          $v0, -0x34($t9)
    MEM_W(-0X34, ctx->r25) = ctx->r2;
    // 0x8000D08C: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
L_8000D090:
    // 0x8000D090: slti        $at, $v1, 0x25
    ctx->r1 = SIGNED(ctx->r3) < 0X25 ? 1 : 0;
    // 0x8000D094: bne         $at, $zero, L_8000D0AC
    if (ctx->r1 != 0) {
        // 0x8000D098: slti        $at, $v1, 0x2A
        ctx->r1 = SIGNED(ctx->r3) < 0X2A ? 1 : 0;
            goto L_8000D0AC;
    }
    // 0x8000D098: slti        $at, $v1, 0x2A
    ctx->r1 = SIGNED(ctx->r3) < 0X2A ? 1 : 0;
    // 0x8000D09C: beq         $at, $zero, L_8000D0AC
    if (ctx->r1 == 0) {
        // 0x8000D0A0: sll         $t0, $v1, 2
        ctx->r8 = S32(ctx->r3 << 2);
            goto L_8000D0AC;
    }
    // 0x8000D0A0: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x8000D0A4: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x8000D0A8: sw          $v0, -0x18($t1)
    MEM_W(-0X18, ctx->r9) = ctx->r2;
L_8000D0AC:
    // 0x8000D0AC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000D0B0: bnel        $v0, $zero, L_8000D070
    if (ctx->r2 != 0) {
        // 0x8000D0B4: lbu         $v1, 0x4($v0)
        ctx->r3 = MEM_BU(ctx->r2, 0X4);
            goto L_8000D070;
    }
    goto skip_2;
    // 0x8000D0B4: lbu         $v1, 0x4($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4);
    skip_2:
    // 0x8000D0B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_8000D0BC:
    // 0x8000D0BC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x8000D0C0: addiu       $s5, $sp, 0x90
    ctx->r21 = ADD32(ctx->r29, 0X90);
    // 0x8000D0C4: lw          $v0, 0x94($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X94);
L_8000D0C8:
    // 0x8000D0C8: bnel        $v0, $zero, L_8000D128
    if (ctx->r2 != 0) {
        // 0x8000D0CC: lw          $v1, 0x0($v0)
        ctx->r3 = MEM_W(ctx->r2, 0X0);
            goto L_8000D128;
    }
    goto skip_3;
    // 0x8000D0CC: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    skip_3:
    // 0x8000D0D0: lw          $v0, 0x90($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X90);
    // 0x8000D0D4: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D0D8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000D0DC: beql        $v0, $zero, L_8000D118
    if (ctx->r2 == 0) {
        // 0x8000D0E0: swc1        $f0, 0xA0($s3)
        MEM_W(0XA0, ctx->r19) = ctx->f0.u32l;
            goto L_8000D118;
    }
    goto skip_4;
    // 0x8000D0E0: swc1        $f0, 0xA0($s3)
    MEM_W(0XA0, ctx->r19) = ctx->f0.u32l;
    skip_4:
    // 0x8000D0E4: lbu         $t2, 0x5($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X5);
L_8000D0E8:
    // 0x8000D0E8: beql        $t2, $zero, L_8000D10C
    if (ctx->r10 == 0) {
        // 0x8000D0EC: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_8000D10C;
    }
    goto skip_5;
    // 0x8000D0EC: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_5:
    // 0x8000D0F0: lwc1        $f10, 0x9C($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x8000D0F4: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000D0F8: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x8000D0FC: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8000D100: swc1        $f18, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f18.u32l;
    // 0x8000D104: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D108: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8000D10C:
    // 0x8000D10C: bnel        $v0, $zero, L_8000D0E8
    if (ctx->r2 != 0) {
        // 0x8000D110: lbu         $t2, 0x5($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0X5);
            goto L_8000D0E8;
    }
    goto skip_6;
    // 0x8000D110: lbu         $t2, 0x5($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X5);
    skip_6:
    // 0x8000D114: swc1        $f0, 0xA0($s3)
    MEM_W(0XA0, ctx->r19) = ctx->f0.u32l;
L_8000D118:
    // 0x8000D118: lwc1        $f4, -0x2188($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2188);
    // 0x8000D11C: b           L_8000DA04
    // 0x8000D120: swc1        $f4, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f4.u32l;
        goto L_8000DA04;
    // 0x8000D120: swc1        $f4, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f4.u32l;
    // 0x8000D124: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
L_8000D128:
    // 0x8000D128: srl         $a0, $v1, 25
    ctx->r4 = S32(U32(ctx->r3) >> 25);
    // 0x8000D12C: sltiu       $at, $a0, 0x17
    ctx->r1 = ctx->r4 < 0X17 ? 1 : 0;
    // 0x8000D130: beq         $at, $zero, L_8000D9F0
    if (ctx->r1 == 0) {
        // 0x8000D134: sw          $a0, 0x58($sp)
        MEM_W(0X58, ctx->r29) = ctx->r4;
            goto L_8000D9F0;
    }
    // 0x8000D134: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8000D138: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8000D13C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000D140: addu        $at, $at, $t3
    gpr jr_addend_8000D148 = ctx->r11;
    ctx->r1 = ADD32(ctx->r1, ctx->r11);
    // 0x8000D144: lw          $t3, -0x2184($at)
    ctx->r11 = ADD32(ctx->r1, -0X2184);
    // 0x8000D148: jr          $t3
    // 0x8000D14C: nop

    switch (jr_addend_8000D148 >> 2) {
        case 0: goto L_8000D6E8; break;
        case 1: goto L_8000D644; break;
        case 2: goto L_8000D4F4; break;
        case 3: goto L_8000D258; break;
        case 4: goto L_8000D258; break;
        case 5: goto L_8000D360; break;
        case 6: goto L_8000D360; break;
        case 7: goto L_8000D47C; break;
        case 8: goto L_8000D150; break;
        case 9: goto L_8000D150; break;
        case 10: goto L_8000D530; break;
        case 11: goto L_8000D530; break;
        case 12: goto L_8000D65C; break;
        case 13: goto L_8000D9F0; break;
        case 14: goto L_8000D624; break;
        case 15: goto L_8000D9F0; break;
        case 16: goto L_8000D9F0; break;
        case 17: goto L_8000D9F0; break;
        case 18: goto L_8000D73C; break;
        case 19: goto L_8000D73C; break;
        case 20: goto L_8000D82C; break;
        case 21: goto L_8000D82C; break;
        case 22: goto L_8000D924; break;
        default: switch_error(__func__, 0x8000D148, 0x8003DE7C);
    }
    // 0x8000D14C: nop

L_8000D150:
    // 0x8000D150: andi        $t4, $v1, 0x7FFF
    ctx->r12 = ctx->r3 & 0X7FFF;
    // 0x8000D154: mtc1        $t4, $f6
    ctx->f6.u32l = ctx->r12;
    // 0x8000D158: sll         $s2, $v1, 7
    ctx->r18 = S32(ctx->r3 << 7);
    // 0x8000D15C: bgez        $t4, L_8000D174
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8000D160: cvt.s.w     $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000D174;
    }
    // 0x8000D160: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000D164: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000D168: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000D16C: nop

    // 0x8000D170: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
L_8000D174:
    // 0x8000D174: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x8000D178: sw          $t5, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r13;
    // 0x8000D17C: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000D180: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000D184:
    // 0x8000D184: beq         $s2, $zero, L_8000D234
    if (ctx->r18 == 0) {
        // 0x8000D188: andi        $t6, $s2, 0x1
        ctx->r14 = ctx->r18 & 0X1;
            goto L_8000D234;
    }
    // 0x8000D188: andi        $t6, $s2, 0x1
    ctx->r14 = ctx->r18 & 0X1;
    // 0x8000D18C: beq         $t6, $zero, L_8000D228
    if (ctx->r14 == 0) {
        // 0x8000D190: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_8000D228;
    }
    // 0x8000D190: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8000D194: addu        $s0, $s5, $t7
    ctx->r16 = ADD32(ctx->r21, ctx->r15);
    // 0x8000D198: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D19C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D1A0: addiu       $a1, $s1, 0xD
    ctx->r5 = ADD32(ctx->r17, 0XD);
    // 0x8000D1A4: bnel        $v1, $zero, L_8000D1C0
    if (ctx->r3 != 0) {
        // 0x8000D1A8: lwc1        $f8, 0x14($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000D1C0;
    }
    goto skip_7;
    // 0x8000D1A8: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    skip_7:
    // 0x8000D1AC: jal         0x80008F44
    // 0x8000D1B0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForMObj(rdram, ctx);
        goto after_0;
    // 0x8000D1B0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x8000D1B4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D1B8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000D1BC: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
L_8000D1C0:
    // 0x8000D1C0: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000D1C4: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
    // 0x8000D1C8: lw          $t8, 0x94($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X94);
    // 0x8000D1CC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000D1D0: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8000D1D4: swc1        $f16, 0x14($t9)
    MEM_W(0X14, ctx->r25) = ctx->f16.u32l;
    // 0x8000D1D8: lw          $t0, 0x94($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X94);
    // 0x8000D1DC: addiu       $t1, $t0, 0x4
    ctx->r9 = ADD32(ctx->r8, 0X4);
    // 0x8000D1E0: sw          $t1, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r9;
    // 0x8000D1E4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D1E8: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8000D1EC: swc1        $f18, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f18.u32l;
    // 0x8000D1F0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000D1F4: swc1        $f22, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f22.u32l;
    // 0x8000D1F8: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8000D1FC: bc1t        L_8000D210
    if (c1cs) {
        // 0x8000D200: sb          $s6, 0x5($t3)
        MEM_B(0X5, ctx->r11) = ctx->r22;
            goto L_8000D210;
    }
    // 0x8000D200: sb          $s6, 0x5($t3)
    MEM_B(0X5, ctx->r11) = ctx->r22;
    // 0x8000D204: div.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8000D208: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000D20C: swc1        $f4, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f4.u32l;
L_8000D210:
    // 0x8000D210: lwc1        $f6, 0x98($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D214: lwc1        $f8, 0x9C($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x8000D218: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000D21C: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x8000D220: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8000D224: swc1        $f16, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f16.u32l;
L_8000D228:
    // 0x8000D228: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D22C: bne         $s1, $s4, L_8000D184
    if (ctx->r17 != ctx->r20) {
        // 0x8000D230: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000D184;
    }
    // 0x8000D230: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000D234:
    // 0x8000D234: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8000D238: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D23C: bne         $t6, $at, L_8000D250
    if (ctx->r14 != ctx->r1) {
        // 0x8000D240: nop
    
            goto L_8000D250;
    }
    // 0x8000D240: nop

    // 0x8000D244: lwc1        $f18, 0x98($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D248: add.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8000D24C: swc1        $f4, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f4.u32l;
L_8000D250:
    // 0x8000D250: b           L_8000D9F4
    // 0x8000D254: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
        goto L_8000D9F4;
    // 0x8000D254: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D258:
    // 0x8000D258: andi        $t7, $v1, 0x7FFF
    ctx->r15 = ctx->r3 & 0X7FFF;
    // 0x8000D25C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8000D260: sll         $s2, $v1, 7
    ctx->r18 = S32(ctx->r3 << 7);
    // 0x8000D264: bgez        $t7, L_8000D27C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x8000D268: cvt.s.w     $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000D27C;
    }
    // 0x8000D268: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000D26C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000D270: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000D274: nop

    // 0x8000D278: add.s       $f20, $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f10.fl;
L_8000D27C:
    // 0x8000D27C: addiu       $t8, $v0, 0x4
    ctx->r24 = ADD32(ctx->r2, 0X4);
    // 0x8000D280: sw          $t8, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r24;
    // 0x8000D284: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000D288: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000D28C:
    // 0x8000D28C: beq         $s2, $zero, L_8000D33C
    if (ctx->r18 == 0) {
        // 0x8000D290: andi        $t9, $s2, 0x1
        ctx->r25 = ctx->r18 & 0X1;
            goto L_8000D33C;
    }
    // 0x8000D290: andi        $t9, $s2, 0x1
    ctx->r25 = ctx->r18 & 0X1;
    // 0x8000D294: beq         $t9, $zero, L_8000D330
    if (ctx->r25 == 0) {
        // 0x8000D298: sll         $t0, $s1, 2
        ctx->r8 = S32(ctx->r17 << 2);
            goto L_8000D330;
    }
    // 0x8000D298: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8000D29C: addu        $s0, $s5, $t0
    ctx->r16 = ADD32(ctx->r21, ctx->r8);
    // 0x8000D2A0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D2A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D2A8: addiu       $a1, $s1, 0xD
    ctx->r5 = ADD32(ctx->r17, 0XD);
    // 0x8000D2AC: bnel        $v1, $zero, L_8000D2C8
    if (ctx->r3 != 0) {
        // 0x8000D2B0: lwc1        $f8, 0x14($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000D2C8;
    }
    goto skip_8;
    // 0x8000D2B0: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    skip_8:
    // 0x8000D2B4: jal         0x80008F44
    // 0x8000D2B8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForMObj(rdram, ctx);
        goto after_1;
    // 0x8000D2B8: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_1:
    // 0x8000D2BC: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D2C0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000D2C4: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
L_8000D2C8:
    // 0x8000D2C8: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000D2CC: swc1        $f8, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f8.u32l;
    // 0x8000D2D0: lw          $t1, 0x94($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X94);
    // 0x8000D2D4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000D2D8: lwc1        $f16, 0x0($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X0);
    // 0x8000D2DC: swc1        $f16, 0x14($t2)
    MEM_W(0X14, ctx->r10) = ctx->f16.u32l;
    // 0x8000D2E0: lw          $t3, 0x94($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X94);
    // 0x8000D2E4: addiu       $t4, $t3, 0x4
    ctx->r12 = ADD32(ctx->r11, 0X4);
    // 0x8000D2E8: sw          $t4, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r12;
    // 0x8000D2EC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000D2F0: bc1t        L_8000D310
    if (c1cs) {
        // 0x8000D2F4: sb          $s7, 0x5($t5)
        MEM_B(0X5, ctx->r13) = ctx->r23;
            goto L_8000D310;
    }
    // 0x8000D2F4: sb          $s7, 0x5($t5)
    MEM_B(0X5, ctx->r13) = ctx->r23;
    // 0x8000D2F8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D2FC: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8000D300: lwc1        $f4, 0x10($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8000D304: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000D308: div.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8000D30C: swc1        $f10, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f10.u32l;
L_8000D310:
    // 0x8000D310: lwc1        $f8, 0x98($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D314: lwc1        $f18, 0x9C($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x8000D318: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8000D31C: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8000D320: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8000D324: swc1        $f4, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f4.u32l;
    // 0x8000D328: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8000D32C: swc1        $f22, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f22.u32l;
L_8000D330:
    // 0x8000D330: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D334: bne         $s1, $s4, L_8000D28C
    if (ctx->r17 != ctx->r20) {
        // 0x8000D338: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000D28C;
    }
    // 0x8000D338: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000D33C:
    // 0x8000D33C: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8000D340: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8000D344: bne         $t8, $at, L_8000D358
    if (ctx->r24 != ctx->r1) {
        // 0x8000D348: nop
    
            goto L_8000D358;
    }
    // 0x8000D348: nop

    // 0x8000D34C: lwc1        $f6, 0x98($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D350: add.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8000D354: swc1        $f10, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f10.u32l;
L_8000D358:
    // 0x8000D358: b           L_8000D9F4
    // 0x8000D35C: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
        goto L_8000D9F4;
    // 0x8000D35C: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D360:
    // 0x8000D360: andi        $t9, $v1, 0x7FFF
    ctx->r25 = ctx->r3 & 0X7FFF;
    // 0x8000D364: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x8000D368: sll         $s2, $v1, 7
    ctx->r18 = S32(ctx->r3 << 7);
    // 0x8000D36C: bgez        $t9, L_8000D384
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8000D370: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000D384;
    }
    // 0x8000D370: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000D374: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000D378: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000D37C: nop

    // 0x8000D380: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
L_8000D384:
    // 0x8000D384: addiu       $t0, $v0, 0x4
    ctx->r8 = ADD32(ctx->r2, 0X4);
    // 0x8000D388: sw          $t0, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r8;
    // 0x8000D38C: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000D390: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000D394:
    // 0x8000D394: beq         $s2, $zero, L_8000D458
    if (ctx->r18 == 0) {
        // 0x8000D398: andi        $t1, $s2, 0x1
        ctx->r9 = ctx->r18 & 0X1;
            goto L_8000D458;
    }
    // 0x8000D398: andi        $t1, $s2, 0x1
    ctx->r9 = ctx->r18 & 0X1;
    // 0x8000D39C: beq         $t1, $zero, L_8000D44C
    if (ctx->r9 == 0) {
        // 0x8000D3A0: sll         $t2, $s1, 2
        ctx->r10 = S32(ctx->r17 << 2);
            goto L_8000D44C;
    }
    // 0x8000D3A0: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8000D3A4: addu        $s0, $s5, $t2
    ctx->r16 = ADD32(ctx->r21, ctx->r10);
    // 0x8000D3A8: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D3AC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D3B0: addiu       $a1, $s1, 0xD
    ctx->r5 = ADD32(ctx->r17, 0XD);
    // 0x8000D3B4: bnel        $v1, $zero, L_8000D3D0
    if (ctx->r3 != 0) {
        // 0x8000D3B8: lwc1        $f18, 0x14($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000D3D0;
    }
    goto skip_9;
    // 0x8000D3B8: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    skip_9:
    // 0x8000D3BC: jal         0x80008F44
    // 0x8000D3C0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForMObj(rdram, ctx);
        goto after_2;
    // 0x8000D3C0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_2:
    // 0x8000D3C4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D3C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000D3CC: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
L_8000D3D0:
    // 0x8000D3D0: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000D3D4: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
    // 0x8000D3D8: lw          $t3, 0x94($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X94);
    // 0x8000D3DC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000D3E0: lwc1        $f4, 0x0($t3)
    ctx->f4.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8000D3E4: swc1        $f4, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f4.u32l;
    // 0x8000D3E8: lw          $t5, 0x94($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X94);
    // 0x8000D3EC: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x8000D3F0: sw          $t6, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r14;
    // 0x8000D3F4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D3F8: lwc1        $f6, 0x1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x8000D3FC: swc1        $f6, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f6.u32l;
    // 0x8000D400: lw          $t7, 0x94($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X94);
    // 0x8000D404: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000D408: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8000D40C: swc1        $f10, 0x1C($t8)
    MEM_W(0X1C, ctx->r24) = ctx->f10.u32l;
    // 0x8000D410: lw          $t9, 0x94($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X94);
    // 0x8000D414: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x8000D418: sw          $t0, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r8;
    // 0x8000D41C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8000D420: bc1t        L_8000D434
    if (c1cs) {
        // 0x8000D424: sb          $s6, 0x5($t1)
        MEM_B(0X5, ctx->r9) = ctx->r22;
            goto L_8000D434;
    }
    // 0x8000D424: sb          $s6, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r22;
    // 0x8000D428: div.s       $f8, $f24, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8000D42C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000D430: swc1        $f8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f8.u32l;
L_8000D434:
    // 0x8000D434: lwc1        $f16, 0x98($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D438: lwc1        $f4, 0x9C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x8000D43C: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8000D440: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x8000D444: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8000D448: swc1        $f6, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f6.u32l;
L_8000D44C:
    // 0x8000D44C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D450: bne         $s1, $s4, L_8000D394
    if (ctx->r17 != ctx->r20) {
        // 0x8000D454: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000D394;
    }
    // 0x8000D454: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000D458:
    // 0x8000D458: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8000D45C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000D460: bne         $t4, $at, L_8000D474
    if (ctx->r12 != ctx->r1) {
        // 0x8000D464: nop
    
            goto L_8000D474;
    }
    // 0x8000D464: nop

    // 0x8000D468: lwc1        $f10, 0x98($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D46C: add.s       $f8, $f10, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8000D470: swc1        $f8, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f8.u32l;
L_8000D474:
    // 0x8000D474: b           L_8000D9F4
    // 0x8000D478: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
        goto L_8000D9F4;
    // 0x8000D478: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D47C:
    // 0x8000D47C: sll         $s2, $v1, 7
    ctx->r18 = S32(ctx->r3 << 7);
    // 0x8000D480: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x8000D484: sw          $t5, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r13;
    // 0x8000D488: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000D48C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000D490:
    // 0x8000D490: beq         $s2, $zero, L_8000D4EC
    if (ctx->r18 == 0) {
        // 0x8000D494: andi        $t6, $s2, 0x1
        ctx->r14 = ctx->r18 & 0X1;
            goto L_8000D4EC;
    }
    // 0x8000D494: andi        $t6, $s2, 0x1
    ctx->r14 = ctx->r18 & 0X1;
    // 0x8000D498: beq         $t6, $zero, L_8000D4E0
    if (ctx->r14 == 0) {
        // 0x8000D49C: sll         $t7, $s1, 2
        ctx->r15 = S32(ctx->r17 << 2);
            goto L_8000D4E0;
    }
    // 0x8000D49C: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x8000D4A0: addu        $s0, $s5, $t7
    ctx->r16 = ADD32(ctx->r21, ctx->r15);
    // 0x8000D4A4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D4A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D4AC: addiu       $a1, $s1, 0xD
    ctx->r5 = ADD32(ctx->r17, 0XD);
    // 0x8000D4B0: bnel        $v1, $zero, L_8000D4CC
    if (ctx->r3 != 0) {
        // 0x8000D4B4: lw          $t8, 0x94($s3)
        ctx->r24 = MEM_W(ctx->r19, 0X94);
            goto L_8000D4CC;
    }
    goto skip_10;
    // 0x8000D4B4: lw          $t8, 0x94($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X94);
    skip_10:
    // 0x8000D4B8: jal         0x80008F44
    // 0x8000D4BC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForMObj(rdram, ctx);
        goto after_3;
    // 0x8000D4BC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_3:
    // 0x8000D4C0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D4C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000D4C8: lw          $t8, 0x94($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X94);
L_8000D4CC:
    // 0x8000D4CC: lwc1        $f16, 0x0($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X0);
    // 0x8000D4D0: swc1        $f16, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f16.u32l;
    // 0x8000D4D4: lw          $t9, 0x94($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X94);
    // 0x8000D4D8: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x8000D4DC: sw          $t0, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r8;
L_8000D4E0:
    // 0x8000D4E0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D4E4: bne         $s1, $s4, L_8000D490
    if (ctx->r17 != ctx->r20) {
        // 0x8000D4E8: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000D490;
    }
    // 0x8000D4E8: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000D4EC:
    // 0x8000D4EC: b           L_8000D9F4
    // 0x8000D4F0: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
        goto L_8000D9F4;
    // 0x8000D4F0: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D4F4:
    // 0x8000D4F4: andi        $t1, $v1, 0x7FFF
    ctx->r9 = ctx->r3 & 0X7FFF;
    // 0x8000D4F8: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x8000D4FC: lwc1        $f18, 0x98($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D500: bgez        $t1, L_8000D518
    if (SIGNED(ctx->r9) >= 0) {
        // 0x8000D504: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8000D518;
    }
    // 0x8000D504: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000D508: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000D50C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000D510: nop

    // 0x8000D514: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_8000D518:
    // 0x8000D518: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8000D51C: addiu       $t2, $v0, 0x4
    ctx->r10 = ADD32(ctx->r2, 0X4);
    // 0x8000D520: sw          $t2, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r10;
    // 0x8000D524: swc1        $f8, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f8.u32l;
    // 0x8000D528: b           L_8000D9F4
    // 0x8000D52C: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
        goto L_8000D9F4;
    // 0x8000D52C: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D530:
    // 0x8000D530: andi        $t3, $v1, 0x7FFF
    ctx->r11 = ctx->r3 & 0X7FFF;
    // 0x8000D534: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x8000D538: sll         $s2, $v1, 7
    ctx->r18 = S32(ctx->r3 << 7);
    // 0x8000D53C: bgez        $t3, L_8000D554
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000D540: cvt.s.w     $f20, $f16
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8000D554;
    }
    // 0x8000D540: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000D544: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000D548: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000D54C: nop

    // 0x8000D550: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
L_8000D554:
    // 0x8000D554: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    // 0x8000D558: sw          $t4, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r12;
    // 0x8000D55C: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000D560: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000D564:
    // 0x8000D564: beq         $s2, $zero, L_8000D600
    if (ctx->r18 == 0) {
        // 0x8000D568: andi        $t5, $s2, 0x1
        ctx->r13 = ctx->r18 & 0X1;
            goto L_8000D600;
    }
    // 0x8000D568: andi        $t5, $s2, 0x1
    ctx->r13 = ctx->r18 & 0X1;
    // 0x8000D56C: beq         $t5, $zero, L_8000D5F4
    if (ctx->r13 == 0) {
        // 0x8000D570: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_8000D5F4;
    }
    // 0x8000D570: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8000D574: addu        $s0, $s5, $t6
    ctx->r16 = ADD32(ctx->r21, ctx->r14);
    // 0x8000D578: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D57C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D580: addiu       $a1, $s1, 0xD
    ctx->r5 = ADD32(ctx->r17, 0XD);
    // 0x8000D584: bnel        $v1, $zero, L_8000D5A0
    if (ctx->r3 != 0) {
        // 0x8000D588: lwc1        $f10, 0x14($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000D5A0;
    }
    goto skip_11;
    // 0x8000D588: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    skip_11:
    // 0x8000D58C: jal         0x80008F44
    // 0x8000D590: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForMObj(rdram, ctx);
        goto after_4;
    // 0x8000D590: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_4:
    // 0x8000D594: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D598: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000D59C: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
L_8000D5A0:
    // 0x8000D5A0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000D5A4: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x8000D5A8: lw          $t7, 0x94($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X94);
    // 0x8000D5AC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000D5B0: lwc1        $f18, 0x0($t7)
    ctx->f18.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8000D5B4: swc1        $f18, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f18.u32l;
    // 0x8000D5B8: lw          $t9, 0x94($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X94);
    // 0x8000D5BC: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x8000D5C0: sw          $t0, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r8;
    // 0x8000D5C4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000D5C8: sb          $t1, 0x5($t2)
    MEM_B(0X5, ctx->r10) = ctx->r9;
    // 0x8000D5CC: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8000D5D0: swc1        $f20, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f20.u32l;
    // 0x8000D5D4: lwc1        $f6, 0x98($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D5D8: lwc1        $f16, 0x9C($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x8000D5DC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000D5E0: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x8000D5E4: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x8000D5E8: swc1        $f4, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f4.u32l;
    // 0x8000D5EC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000D5F0: swc1        $f22, 0x1C($t5)
    MEM_W(0X1C, ctx->r13) = ctx->f22.u32l;
L_8000D5F4:
    // 0x8000D5F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D5F8: bne         $s1, $s4, L_8000D564
    if (ctx->r17 != ctx->r20) {
        // 0x8000D5FC: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000D564;
    }
    // 0x8000D5FC: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000D600:
    // 0x8000D600: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8000D604: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8000D608: bne         $t6, $at, L_8000D61C
    if (ctx->r14 != ctx->r1) {
        // 0x8000D60C: nop
    
            goto L_8000D61C;
    }
    // 0x8000D60C: nop

    // 0x8000D610: lwc1        $f10, 0x98($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D614: add.s       $f18, $f10, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f20.fl;
    // 0x8000D618: swc1        $f18, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f18.u32l;
L_8000D61C:
    // 0x8000D61C: b           L_8000D9F4
    // 0x8000D620: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
        goto L_8000D9F4;
    // 0x8000D620: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D624:
    // 0x8000D624: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D628: addiu       $t7, $v0, 0x4
    ctx->r15 = ADD32(ctx->r2, 0X4);
    // 0x8000D62C: sw          $t7, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r15;
    // 0x8000D630: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8000D634: neg.s       $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = -ctx->f0.fl;
    // 0x8000D638: swc1        $f6, 0xA0($s3)
    MEM_W(0XA0, ctx->r19) = ctx->f6.u32l;
    // 0x8000D63C: b           L_8000D9F4
    // 0x8000D640: sw          $t9, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r25;
        goto L_8000D9F4;
    // 0x8000D640: sw          $t9, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r25;
L_8000D644:
    // 0x8000D644: addiu       $t0, $v0, 0x4
    ctx->r8 = ADD32(ctx->r2, 0X4);
    // 0x8000D648: sw          $t0, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r8;
    // 0x8000D64C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8000D650: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D654: b           L_8000D9F4
    // 0x8000D658: sw          $t2, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r10;
        goto L_8000D9F4;
    // 0x8000D658: sw          $t2, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r10;
L_8000D65C:
    // 0x8000D65C: andi        $t3, $v1, 0x7FFF
    ctx->r11 = ctx->r3 & 0X7FFF;
    // 0x8000D660: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8000D664: sll         $s2, $v1, 7
    ctx->r18 = S32(ctx->r3 << 7);
    // 0x8000D668: bgez        $t3, L_8000D680
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000D66C: cvt.s.w     $f20, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000D680;
    }
    // 0x8000D66C: cvt.s.w     $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    ctx->f20.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000D670: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000D674: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8000D678: nop

    // 0x8000D67C: add.s       $f20, $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f16.fl;
L_8000D680:
    // 0x8000D680: addiu       $t4, $v0, 0x4
    ctx->r12 = ADD32(ctx->r2, 0X4);
    // 0x8000D684: sw          $t4, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r12;
    // 0x8000D688: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000D68C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000D690:
    // 0x8000D690: beq         $s2, $zero, L_8000D6E0
    if (ctx->r18 == 0) {
        // 0x8000D694: andi        $t5, $s2, 0x1
        ctx->r13 = ctx->r18 & 0X1;
            goto L_8000D6E0;
    }
    // 0x8000D694: andi        $t5, $s2, 0x1
    ctx->r13 = ctx->r18 & 0X1;
    // 0x8000D698: beq         $t5, $zero, L_8000D6D4
    if (ctx->r13 == 0) {
        // 0x8000D69C: sll         $t6, $s1, 2
        ctx->r14 = S32(ctx->r17 << 2);
            goto L_8000D6D4;
    }
    // 0x8000D69C: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x8000D6A0: addu        $s0, $s5, $t6
    ctx->r16 = ADD32(ctx->r21, ctx->r14);
    // 0x8000D6A4: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D6A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D6AC: addiu       $a1, $s1, 0xD
    ctx->r5 = ADD32(ctx->r17, 0XD);
    // 0x8000D6B0: bnel        $v1, $zero, L_8000D6CC
    if (ctx->r3 != 0) {
        // 0x8000D6B4: lwc1        $f4, 0xC($v1)
        ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
            goto L_8000D6CC;
    }
    goto skip_12;
    // 0x8000D6B4: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    skip_12:
    // 0x8000D6B8: jal         0x80008F44
    // 0x8000D6BC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForMObj(rdram, ctx);
        goto after_5;
    // 0x8000D6BC: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_5:
    // 0x8000D6C0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D6C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000D6C8: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
L_8000D6CC:
    // 0x8000D6CC: add.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x8000D6D0: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
L_8000D6D4:
    // 0x8000D6D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D6D8: bne         $s1, $s4, L_8000D690
    if (ctx->r17 != ctx->r20) {
        // 0x8000D6DC: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000D690;
    }
    // 0x8000D6DC: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000D6E0:
    // 0x8000D6E0: b           L_8000D9F4
    // 0x8000D6E4: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
        goto L_8000D9F4;
    // 0x8000D6E4: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D6E8:
    // 0x8000D6E8: lw          $v0, 0x90($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X90);
    // 0x8000D6EC: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D6F0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000D6F4: beql        $v0, $zero, L_8000D730
    if (ctx->r2 == 0) {
        // 0x8000D6F8: swc1        $f0, 0xA0($s3)
        MEM_W(0XA0, ctx->r19) = ctx->f0.u32l;
            goto L_8000D730;
    }
    goto skip_13;
    // 0x8000D6F8: swc1        $f0, 0xA0($s3)
    MEM_W(0XA0, ctx->r19) = ctx->f0.u32l;
    skip_13:
    // 0x8000D6FC: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
L_8000D700:
    // 0x8000D700: beql        $t7, $zero, L_8000D724
    if (ctx->r15 == 0) {
        // 0x8000D704: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_8000D724;
    }
    goto skip_14;
    // 0x8000D704: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_14:
    // 0x8000D708: lwc1        $f6, 0x9C($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x8000D70C: lwc1        $f18, 0xC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000D710: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x8000D714: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8000D718: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x8000D71C: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D720: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8000D724:
    // 0x8000D724: bnel        $v0, $zero, L_8000D700
    if (ctx->r2 != 0) {
        // 0x8000D728: lbu         $t7, 0x5($v0)
        ctx->r15 = MEM_BU(ctx->r2, 0X5);
            goto L_8000D700;
    }
    goto skip_15;
    // 0x8000D728: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    skip_15:
    // 0x8000D72C: swc1        $f0, 0xA0($s3)
    MEM_W(0XA0, ctx->r19) = ctx->f0.u32l;
L_8000D730:
    // 0x8000D730: lwc1        $f4, -0x2128($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2128);
    // 0x8000D734: b           L_8000DA04
    // 0x8000D738: swc1        $f4, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f4.u32l;
        goto L_8000DA04;
    // 0x8000D738: swc1        $f4, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f4.u32l;
L_8000D73C:
    // 0x8000D73C: andi        $t8, $v1, 0x7FFF
    ctx->r24 = ctx->r3 & 0X7FFF;
    // 0x8000D740: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8000D744: sll         $s2, $v1, 7
    ctx->r18 = S32(ctx->r3 << 7);
    // 0x8000D748: bgez        $t8, L_8000D760
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000D74C: cvt.s.w     $f20, $f10
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
            goto L_8000D760;
    }
    // 0x8000D74C: cvt.s.w     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    ctx->f20.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8000D750: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000D754: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8000D758: nop

    // 0x8000D75C: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_8000D760:
    // 0x8000D760: addiu       $t9, $v0, 0x4
    ctx->r25 = ADD32(ctx->r2, 0X4);
    // 0x8000D764: sw          $t9, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r25;
    // 0x8000D768: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000D76C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000D770:
    // 0x8000D770: beq         $s2, $zero, L_8000D808
    if (ctx->r18 == 0) {
        // 0x8000D774: andi        $t0, $s2, 0x1
        ctx->r8 = ctx->r18 & 0X1;
            goto L_8000D808;
    }
    // 0x8000D774: andi        $t0, $s2, 0x1
    ctx->r8 = ctx->r18 & 0X1;
    // 0x8000D778: beq         $t0, $zero, L_8000D7FC
    if (ctx->r8 == 0) {
        // 0x8000D77C: sll         $t1, $s1, 2
        ctx->r9 = S32(ctx->r17 << 2);
            goto L_8000D7FC;
    }
    // 0x8000D77C: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x8000D780: addiu       $t2, $sp, 0x7C
    ctx->r10 = ADD32(ctx->r29, 0X7C);
    // 0x8000D784: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x8000D788: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D78C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D790: addiu       $a1, $s1, 0x25
    ctx->r5 = ADD32(ctx->r17, 0X25);
    // 0x8000D794: bnel        $v1, $zero, L_8000D7B0
    if (ctx->r3 != 0) {
        // 0x8000D798: lwc1        $f18, 0x14($v1)
        ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000D7B0;
    }
    goto skip_16;
    // 0x8000D798: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    skip_16:
    // 0x8000D79C: jal         0x80008F44
    // 0x8000D7A0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForMObj(rdram, ctx);
        goto after_6;
    // 0x8000D7A0: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_6:
    // 0x8000D7A4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D7A8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000D7AC: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
L_8000D7B0:
    // 0x8000D7B0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000D7B4: swc1        $f18, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f18.u32l;
    // 0x8000D7B8: lw          $t3, 0x94($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X94);
    // 0x8000D7BC: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8000D7C0: lwc1        $f8, 0x0($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X0);
    // 0x8000D7C4: swc1        $f8, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->f8.u32l;
    // 0x8000D7C8: lw          $t5, 0x94($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X94);
    // 0x8000D7CC: addiu       $t6, $t5, 0x4
    ctx->r14 = ADD32(ctx->r13, 0X4);
    // 0x8000D7D0: sw          $t6, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r14;
    // 0x8000D7D4: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000D7D8: sb          $t7, 0x5($t8)
    MEM_B(0X5, ctx->r24) = ctx->r15;
    // 0x8000D7DC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000D7E0: swc1        $f20, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->f20.u32l;
    // 0x8000D7E4: lwc1        $f16, 0x98($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D7E8: lwc1        $f10, 0x9C($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x8000D7EC: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x8000D7F0: neg.s       $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = -ctx->f16.fl;
    // 0x8000D7F4: sub.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x8000D7F8: swc1        $f6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->f6.u32l;
L_8000D7FC:
    // 0x8000D7FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D800: bne         $s1, $fp, L_8000D770
    if (ctx->r17 != ctx->r30) {
        // 0x8000D804: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000D770;
    }
    // 0x8000D804: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000D808:
    // 0x8000D808: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8000D80C: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x8000D810: bne         $t1, $at, L_8000D824
    if (ctx->r9 != ctx->r1) {
        // 0x8000D814: nop
    
            goto L_8000D824;
    }
    // 0x8000D814: nop

    // 0x8000D818: lwc1        $f18, 0x98($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D81C: add.s       $f8, $f18, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f20.fl;
    // 0x8000D820: swc1        $f8, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f8.u32l;
L_8000D824:
    // 0x8000D824: b           L_8000D9F4
    // 0x8000D828: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
        goto L_8000D9F4;
    // 0x8000D828: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D82C:
    // 0x8000D82C: andi        $t2, $v1, 0x7FFF
    ctx->r10 = ctx->r3 & 0X7FFF;
    // 0x8000D830: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x8000D834: sll         $s2, $v1, 7
    ctx->r18 = S32(ctx->r3 << 7);
    // 0x8000D838: bgez        $t2, L_8000D850
    if (SIGNED(ctx->r10) >= 0) {
        // 0x8000D83C: cvt.s.w     $f20, $f16
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8000D850;
    }
    // 0x8000D83C: cvt.s.w     $f20, $f16
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    ctx->f20.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000D840: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000D844: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000D848: nop

    // 0x8000D84C: add.s       $f20, $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f4.fl;
L_8000D850:
    // 0x8000D850: addiu       $t3, $v0, 0x4
    ctx->r11 = ADD32(ctx->r2, 0X4);
    // 0x8000D854: sw          $t3, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r11;
    // 0x8000D858: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000D85C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000D860:
    // 0x8000D860: beq         $s2, $zero, L_8000D900
    if (ctx->r18 == 0) {
        // 0x8000D864: andi        $t4, $s2, 0x1
        ctx->r12 = ctx->r18 & 0X1;
            goto L_8000D900;
    }
    // 0x8000D864: andi        $t4, $s2, 0x1
    ctx->r12 = ctx->r18 & 0X1;
    // 0x8000D868: beq         $t4, $zero, L_8000D8F4
    if (ctx->r12 == 0) {
        // 0x8000D86C: sll         $t5, $s1, 2
        ctx->r13 = S32(ctx->r17 << 2);
            goto L_8000D8F4;
    }
    // 0x8000D86C: sll         $t5, $s1, 2
    ctx->r13 = S32(ctx->r17 << 2);
    // 0x8000D870: addiu       $t6, $sp, 0x7C
    ctx->r14 = ADD32(ctx->r29, 0X7C);
    // 0x8000D874: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
    // 0x8000D878: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8000D87C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000D880: addiu       $a1, $s1, 0x25
    ctx->r5 = ADD32(ctx->r17, 0X25);
    // 0x8000D884: bnel        $v1, $zero, L_8000D8A0
    if (ctx->r3 != 0) {
        // 0x8000D888: lwc1        $f10, 0x14($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
            goto L_8000D8A0;
    }
    goto skip_17;
    // 0x8000D888: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    skip_17:
    // 0x8000D88C: jal         0x80008F44
    // 0x8000D890: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    gcAddAObjForMObj(rdram, ctx);
        goto after_7;
    // 0x8000D890: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_7:
    // 0x8000D894: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8000D898: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000D89C: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
L_8000D8A0:
    // 0x8000D8A0: c.eq.s      $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f20.fl == ctx->f22.fl;
    // 0x8000D8A4: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x8000D8A8: lw          $t7, 0x94($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X94);
    // 0x8000D8AC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000D8B0: lwc1        $f6, 0x0($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X0);
    // 0x8000D8B4: swc1        $f6, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f6.u32l;
    // 0x8000D8B8: lw          $t9, 0x94($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X94);
    // 0x8000D8BC: addiu       $t0, $t9, 0x4
    ctx->r8 = ADD32(ctx->r25, 0X4);
    // 0x8000D8C0: sw          $t0, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r8;
    // 0x8000D8C4: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8000D8C8: bc1t        L_8000D8DC
    if (c1cs) {
        // 0x8000D8CC: sb          $s7, 0x5($t1)
        MEM_B(0X5, ctx->r9) = ctx->r23;
            goto L_8000D8DC;
    }
    // 0x8000D8CC: sb          $s7, 0x5($t1)
    MEM_B(0X5, ctx->r9) = ctx->r23;
    // 0x8000D8D0: div.s       $f18, $f24, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x8000D8D4: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000D8D8: swc1        $f18, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->f18.u32l;
L_8000D8DC:
    // 0x8000D8DC: lwc1        $f8, 0x98($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D8E0: lwc1        $f4, 0x9C($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0X9C);
    // 0x8000D8E4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8000D8E8: neg.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = -ctx->f8.fl;
    // 0x8000D8EC: sub.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8000D8F0: swc1        $f10, 0xC($t3)
    MEM_W(0XC, ctx->r11) = ctx->f10.u32l;
L_8000D8F4:
    // 0x8000D8F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000D8F8: bne         $s1, $fp, L_8000D860
    if (ctx->r17 != ctx->r30) {
        // 0x8000D8FC: srl         $s2, $s2, 1
        ctx->r18 = S32(U32(ctx->r18) >> 1);
            goto L_8000D860;
    }
    // 0x8000D8FC: srl         $s2, $s2, 1
    ctx->r18 = S32(U32(ctx->r18) >> 1);
L_8000D900:
    // 0x8000D900: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x8000D904: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x8000D908: bne         $t4, $at, L_8000D91C
    if (ctx->r12 != ctx->r1) {
        // 0x8000D90C: nop
    
            goto L_8000D91C;
    }
    // 0x8000D90C: nop

    // 0x8000D910: lwc1        $f6, 0x98($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X98);
    // 0x8000D914: add.s       $f18, $f6, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x8000D918: swc1        $f18, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f18.u32l;
L_8000D91C:
    // 0x8000D91C: b           L_8000D9F4
    // 0x8000D920: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
        goto L_8000D9F4;
    // 0x8000D920: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D924:
    // 0x8000D924: andi        $t5, $v1, 0x7FFF
    ctx->r13 = ctx->r3 & 0X7FFF;
    // 0x8000D928: mtc1        $t5, $f8
    ctx->f8.u32l = ctx->r13;
    // 0x8000D92C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000D930: bgez        $t5, L_8000D944
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8000D934: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_8000D944;
    }
    // 0x8000D934: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000D938: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8000D93C: nop

    // 0x8000D940: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8000D944:
    // 0x8000D944: swc1        $f16, 0x98($s3)
    MEM_W(0X98, ctx->r19) = ctx->f16.u32l;
    // 0x8000D948: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x8000D94C: addiu       $t6, $v0, 0x4
    ctx->r14 = ADD32(ctx->r2, 0X4);
    // 0x8000D950: sw          $t6, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r14;
    // 0x8000D954: sll         $s2, $s2, 7
    ctx->r18 = S32(ctx->r18 << 7);
    // 0x8000D958: srl         $s2, $s2, 22
    ctx->r18 = S32(U32(ctx->r18) >> 22);
    // 0x8000D95C: andi        $t7, $s2, 0x1
    ctx->r15 = ctx->r18 & 0X1;
    // 0x8000D960: beq         $t7, $zero, L_8000D978
    if (ctx->r15 == 0) {
        // 0x8000D964: andi        $t0, $s2, 0x2
        ctx->r8 = ctx->r18 & 0X2;
            goto L_8000D978;
    }
    // 0x8000D964: andi        $t0, $s2, 0x2
    ctx->r8 = ctx->r18 & 0X2;
    // 0x8000D968: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8000D96C: addiu       $t9, $t6, 0x4
    ctx->r25 = ADD32(ctx->r14, 0X4);
    // 0x8000D970: sw          $t9, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r25;
    // 0x8000D974: sw          $t8, 0x54($s3)
    MEM_W(0X54, ctx->r19) = ctx->r24;
L_8000D978:
    // 0x8000D978: beq         $t0, $zero, L_8000D994
    if (ctx->r8 == 0) {
        // 0x8000D97C: andi        $t3, $s2, 0x4
        ctx->r11 = ctx->r18 & 0X4;
            goto L_8000D994;
    }
    // 0x8000D97C: andi        $t3, $s2, 0x4
    ctx->r11 = ctx->r18 & 0X4;
    // 0x8000D980: lw          $v0, 0x94($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X94);
    // 0x8000D984: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8000D988: addiu       $t2, $v0, 0x4
    ctx->r10 = ADD32(ctx->r2, 0X4);
    // 0x8000D98C: sw          $t2, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r10;
    // 0x8000D990: sw          $t1, 0x74($s3)
    MEM_W(0X74, ctx->r19) = ctx->r9;
L_8000D994:
    // 0x8000D994: beq         $t3, $zero, L_8000D9B0
    if (ctx->r11 == 0) {
        // 0x8000D998: andi        $t6, $s2, 0x8
        ctx->r14 = ctx->r18 & 0X8;
            goto L_8000D9B0;
    }
    // 0x8000D998: andi        $t6, $s2, 0x8
    ctx->r14 = ctx->r18 & 0X8;
    // 0x8000D99C: lw          $v0, 0x94($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X94);
    // 0x8000D9A0: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8000D9A4: addiu       $t5, $v0, 0x4
    ctx->r13 = ADD32(ctx->r2, 0X4);
    // 0x8000D9A8: sw          $t5, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r13;
    // 0x8000D9AC: sw          $t4, 0x70($s3)
    MEM_W(0X70, ctx->r19) = ctx->r12;
L_8000D9B0:
    // 0x8000D9B0: beq         $t6, $zero, L_8000D9CC
    if (ctx->r14 == 0) {
        // 0x8000D9B4: andi        $t9, $s2, 0x10
        ctx->r25 = ctx->r18 & 0X10;
            goto L_8000D9CC;
    }
    // 0x8000D9B4: andi        $t9, $s2, 0x10
    ctx->r25 = ctx->r18 & 0X10;
    // 0x8000D9B8: lw          $v0, 0x94($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X94);
    // 0x8000D9BC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8000D9C0: addiu       $t8, $v0, 0x4
    ctx->r24 = ADD32(ctx->r2, 0X4);
    // 0x8000D9C4: sw          $t8, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r24;
    // 0x8000D9C8: sw          $t7, 0x7C($s3)
    MEM_W(0X7C, ctx->r19) = ctx->r15;
L_8000D9CC:
    // 0x8000D9CC: beq         $t9, $zero, L_8000D9E8
    if (ctx->r25 == 0) {
        // 0x8000D9D0: nop
    
            goto L_8000D9E8;
    }
    // 0x8000D9D0: nop

    // 0x8000D9D4: lw          $v0, 0x94($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X94);
    // 0x8000D9D8: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x8000D9DC: addiu       $t1, $v0, 0x4
    ctx->r9 = ADD32(ctx->r2, 0X4);
    // 0x8000D9E0: sw          $t1, 0x94($s3)
    MEM_W(0X94, ctx->r19) = ctx->r9;
    // 0x8000D9E4: sw          $t0, 0x78($s3)
    MEM_W(0X78, ctx->r19) = ctx->r8;
L_8000D9E8:
    // 0x8000D9E8: b           L_8000D9F4
    // 0x8000D9EC: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
        goto L_8000D9F4;
    // 0x8000D9EC: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D9F0:
    // 0x8000D9F0: lwc1        $f0, 0x98($s3)
    ctx->f0.u32l = MEM_W(ctx->r19, 0X98);
L_8000D9F4:
    // 0x8000D9F4: c.le.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl <= ctx->f22.fl;
    // 0x8000D9F8: nop

    // 0x8000D9FC: bc1tl       L_8000D0C8
    if (c1cs) {
        // 0x8000DA00: lw          $v0, 0x94($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X94);
            goto L_8000D0C8;
    }
    goto skip_18;
    // 0x8000DA00: lw          $v0, 0x94($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X94);
    skip_18:
L_8000DA04:
    // 0x8000DA04: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8000DA08:
    // 0x8000DA08: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8000DA0C: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8000DA10: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8000DA14: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8000DA18: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8000DA1C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8000DA20: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8000DA24: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8000DA28: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8000DA2C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8000DA30: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8000DA34: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8000DA38: jr          $ra
    // 0x8000DA3C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8000DA3C: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void ifCommonCountdownMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112668: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8011266C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80112670: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80112674: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80112678: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8011267C: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80112680: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80112684: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x80112688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8011268C: jal         0x80009968
    // 0x80112690: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80112690: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    after_0:
    // 0x80112694: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80112698: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8011269C: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x801126A0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801126A4: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801126A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801126AC: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x801126B0: jal         0x80009DF4
    // 0x801126B4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801126B4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_1:
    // 0x801126B8: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x801126BC: addiu       $a1, $a1, 0x22F4
    ctx->r5 = ADD32(ctx->r5, 0X22F4);
    // 0x801126C0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801126C4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x801126C8: jal         0x80008188
    // 0x801126CC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x801126CC: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_2:
    // 0x801126D0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801126D4: lw          $t7, 0xD44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XD44);
    // 0x801126D8: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x801126DC: addiu       $t8, $t8, 0x990
    ctx->r24 = ADD32(ctx->r24, 0X990);
    // 0x801126E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x801126E4: jal         0x800CCFDC
    // 0x801126E8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x801126E8: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_3:
    // 0x801126EC: lui         $at, 0x42CE
    ctx->r1 = S32(0X42CE << 16);
    // 0x801126F0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801126F4: lui         $at, 0xC264
    ctx->r1 = S32(0XC264 << 16);
    // 0x801126F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801126FC: addiu       $t9, $zero, 0x201
    ctx->r25 = ADD32(0, 0X201);
    // 0x80112700: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80112704: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80112708: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8011270C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80112710: lw          $t0, 0xD44($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XD44);
    // 0x80112714: lui         $t1, 0x2
    ctx->r9 = S32(0X2 << 16);
    // 0x80112718: addiu       $t1, $t1, 0x1760
    ctx->r9 = ADD32(ctx->r9, 0X1760);
    // 0x8011271C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80112720: jal         0x800CCFDC
    // 0x80112724: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80112724: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_4:
    // 0x80112728: lui         $at, 0x42DE
    ctx->r1 = S32(0X42DE << 16);
    // 0x8011272C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80112730: lui         $at, 0xC1B8
    ctx->r1 = S32(0XC1B8 << 16);
    // 0x80112734: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80112738: addiu       $t2, $zero, 0x201
    ctx->r10 = ADD32(0, 0X201);
    // 0x8011273C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80112740: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80112744: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x80112748: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8011274C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80112750: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80112754:
    // 0x80112754: jal         0x80112234
    // 0x80112758: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    ifCommonTrafficMakeSObj(rdram, ctx);
        goto after_5;
    // 0x80112758: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_5:
    // 0x8011275C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80112760: bnel        $s0, $s1, L_80112754
    if (ctx->r16 != ctx->r17) {
        // 0x80112764: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80112754;
    }
    goto skip_0;
    // 0x80112764: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_0:
    // 0x80112768: sw          $v0, 0x84($s2)
    MEM_W(0X84, ctx->r18) = ctx->r2;
    // 0x8011276C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80112770: jal         0x80112234
    // 0x80112774: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    ifCommonTrafficMakeSObj(rdram, ctx);
        goto after_6;
    // 0x80112774: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_6:
    // 0x80112778: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x8011277C: lw          $t3, 0xD44($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XD44);
    // 0x80112780: lui         $t4, 0x2
    ctx->r12 = S32(0X2 << 16);
    // 0x80112784: addiu       $t4, $t4, 0x1878
    ctx->r12 = ADD32(ctx->r12, 0X1878);
    // 0x80112788: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8011278C: jal         0x800CCFDC
    // 0x80112790: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_7;
    // 0x80112790: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_7:
    // 0x80112794: lui         $at, 0x4336
    ctx->r1 = S32(0X4336 << 16);
    // 0x80112798: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8011279C: lui         $at, 0xC130
    ctx->r1 = S32(0XC130 << 16);
    // 0x801127A0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801127A4: addiu       $t5, $zero, 0x201
    ctx->r13 = ADD32(0, 0X201);
    // 0x801127A8: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801127AC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801127B0: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x801127B4: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x801127B8: lbu         $t6, -0x1334($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X1334);
    // 0x801127BC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801127C0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801127C4: sb          $t6, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r14;
    // 0x801127C8: lbu         $t7, -0x1330($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X1330);
    // 0x801127CC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801127D0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801127D4: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x801127D8: lbu         $t8, -0x132C($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X132C);
    // 0x801127DC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801127E0: sb          $t8, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r24;
    // 0x801127E4: lbu         $t9, -0x1328($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X1328);
    // 0x801127E8: sb          $t9, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r25;
    // 0x801127EC: lbu         $t0, -0x1324($t0)
    ctx->r8 = MEM_BU(ctx->r8, -0X1324);
    // 0x801127F0: sb          $t0, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r8;
    // 0x801127F4: lbu         $t1, -0x1320($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X1320);
    // 0x801127F8: sb          $t1, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r9;
    // 0x801127FC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80112800: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80112804: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80112808: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8011280C: jr          $ra
    // 0x80112810: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80112810: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void func_ovl7_8018F7C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018F7C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018F7CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018F7D0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8018F7D4: jal         0x800CCFDC
    // 0x8018F7D8: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x8018F7D8: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    after_0:
    // 0x8018F7DC: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8018F7E0: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8018F7E4: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8018F7E8: nop

    // 0x8018F7EC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018F7F0: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    // 0x8018F7F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018F7F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018F7FC: jr          $ra
    // 0x8018F800: nop

    return;
    // 0x8018F800: nop

;}
RECOMP_FUNC void mnPlayersVSPortraitProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321B8: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x801321BC: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x801321C0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801321C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801321C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801321CC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x801321D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x801321D4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801321D8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x801321DC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801321E0: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x801321E4: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801321E8: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x801321EC: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x801321F0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x801321F4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x801321F8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x801321FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132200: lui         $t4, 0x3030
    ctx->r12 = S32(0X3030 << 16);
    // 0x80132204: ori         $t4, $t4, 0x30FF
    ctx->r12 = ctx->r12 | 0X30FF;
    // 0x80132208: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8013220C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80132210: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80132214: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80132218: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8013221C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132220: lui         $t7, 0x11FC
    ctx->r15 = S32(0X11FC << 16);
    // 0x80132224: lui         $t6, 0xFC71
    ctx->r14 = S32(0XFC71 << 16);
    // 0x80132228: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8013222C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80132230: ori         $t6, $t6, 0xFEE3
    ctx->r14 = ctx->r14 | 0XFEE3;
    // 0x80132234: ori         $t7, $t7, 0xF279
    ctx->r15 = ctx->r15 | 0XF279;
    // 0x80132238: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8013223C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80132240: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80132244: lui         $t2, 0x50
    ctx->r10 = S32(0X50 << 16);
    // 0x80132248: lui         $t9, 0xE200
    ctx->r25 = S32(0XE200 << 16);
    // 0x8013224C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80132250: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80132254: ori         $t9, $t9, 0x1C
    ctx->r25 = ctx->r25 | 0X1C;
    // 0x80132258: ori         $t2, $t2, 0x41C8
    ctx->r10 = ctx->r10 | 0X41C8;
    // 0x8013225C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x80132260: jal         0x800CCF74
    // 0x80132264: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    lbCommonDrawSObjNoAttr(rdram, ctx);
        goto after_0;
    // 0x80132264: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x80132268: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013226C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132270: jr          $ra
    // 0x80132274: nop

    return;
    // 0x80132274: nop

;}
RECOMP_FUNC void ftCommonDownBounceUpdateEffects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80144428: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8014442C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80144430: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80144434: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80144438: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x8014443C: lw          $t6, 0x44($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X44);
    // 0x80144440: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80144444: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x80144448: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8014444C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80144450: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80144454: jal         0x800EABDC
    // 0x80144458: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    ftParamMakeEffect(rdram, ctx);
        goto after_0;
    // 0x80144458: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    after_0:
    // 0x8014445C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80144460: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80144464: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80144468: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8014446C: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80144470: jal         0x800269C0
    // 0x80144474: lhu         $a0, -0x3690($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3690);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80144474: lhu         $a0, -0x3690($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X3690);
    after_1:
    // 0x80144478: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8014447C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80144480: jal         0x800E806C
    // 0x80144484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamMakeRumble(rdram, ctx);
        goto after_2;
    // 0x80144484: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_2:
    // 0x80144488: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8014448C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80144490: jr          $ra
    // 0x80144494: nop

    return;
    // 0x80144494: nop

;}
RECOMP_FUNC void gcEjectDObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000948C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80009490: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80009494: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80009498: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000949C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800094A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800094A4: lw          $s0, 0x10($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X10);
    // 0x800094A8: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800094AC: beql        $s0, $zero, L_800094CC
    if (ctx->r16 == 0) {
        // 0x800094B0: lw          $v0, 0x14($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X14);
            goto L_800094CC;
    }
    goto skip_0;
    // 0x800094B0: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
    skip_0:
L_800094B4:
    // 0x800094B4: jal         0x8000948C
    // 0x800094B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcEjectDObj(rdram, ctx);
        goto after_0;
    // 0x800094B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800094BC: lw          $s0, 0x10($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X10);
    // 0x800094C0: bne         $s0, $zero, L_800094B4
    if (ctx->r16 != 0) {
        // 0x800094C4: nop
    
            goto L_800094B4;
    }
    // 0x800094C4: nop

    // 0x800094C8: lw          $v0, 0x14($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X14);
L_800094CC:
    // 0x800094CC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800094D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800094D4: bne         $v0, $at, L_8000950C
    if (ctx->r2 != ctx->r1) {
        // 0x800094D8: or          $s1, $s3, $zero
        ctx->r17 = ctx->r19 | 0;
            goto L_8000950C;
    }
    // 0x800094D8: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x800094DC: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x800094E0: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x800094E4: bnel        $s3, $t6, L_80009524
    if (ctx->r19 != ctx->r14) {
        // 0x800094E8: lw          $v0, 0xC($s3)
        ctx->r2 = MEM_W(ctx->r19, 0XC);
            goto L_80009524;
    }
    goto skip_1;
    // 0x800094E8: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
    skip_1:
    // 0x800094EC: lw          $t7, 0x8($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X8);
    // 0x800094F0: sw          $t7, 0x74($v0)
    MEM_W(0X74, ctx->r2) = ctx->r15;
    // 0x800094F4: lw          $v0, 0x4($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X4);
    // 0x800094F8: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x800094FC: bnel        $t8, $zero, L_80009524
    if (ctx->r24 != 0) {
        // 0x80009500: lw          $v0, 0xC($s3)
        ctx->r2 = MEM_W(ctx->r19, 0XC);
            goto L_80009524;
    }
    goto skip_2;
    // 0x80009500: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
    skip_2:
    // 0x80009504: b           L_80009520
    // 0x80009508: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
        goto L_80009520;
    // 0x80009508: sb          $zero, 0xF($v0)
    MEM_B(0XF, ctx->r2) = 0;
L_8000950C:
    // 0x8000950C: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x80009510: bnel        $s3, $t9, L_80009524
    if (ctx->r19 != ctx->r25) {
        // 0x80009514: lw          $v0, 0xC($s3)
        ctx->r2 = MEM_W(ctx->r19, 0XC);
            goto L_80009524;
    }
    goto skip_3;
    // 0x80009514: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
    skip_3:
    // 0x80009518: lw          $t0, 0x8($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X8);
    // 0x8000951C: sw          $t0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r8;
L_80009520:
    // 0x80009520: lw          $v0, 0xC($s3)
    ctx->r2 = MEM_W(ctx->r19, 0XC);
L_80009524:
    // 0x80009524: addiu       $s2, $zero, 0x14
    ctx->r18 = ADD32(0, 0X14);
    // 0x80009528: beql        $v0, $zero, L_8000953C
    if (ctx->r2 == 0) {
        // 0x8000952C: lw          $v0, 0x8($s3)
        ctx->r2 = MEM_W(ctx->r19, 0X8);
            goto L_8000953C;
    }
    goto skip_4;
    // 0x8000952C: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
    skip_4:
    // 0x80009530: lw          $t1, 0x8($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X8);
    // 0x80009534: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x80009538: lw          $v0, 0x8($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X8);
L_8000953C:
    // 0x8000953C: beq         $v0, $zero, L_8000954C
    if (ctx->r2 == 0) {
        // 0x80009540: nop
    
            goto L_8000954C;
    }
    // 0x80009540: nop

    // 0x80009544: lw          $t2, 0xC($s3)
    ctx->r10 = MEM_W(ctx->r19, 0XC);
    // 0x80009548: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
L_8000954C:
    // 0x8000954C: lw          $a0, 0x58($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X58);
    // 0x80009550: beql        $a0, $zero, L_80009564
    if (ctx->r4 == 0) {
        // 0x80009554: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80009564;
    }
    goto skip_5;
    // 0x80009554: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    skip_5:
    // 0x80009558: jal         0x80007DD8
    // 0x8000955C: nop

    gcSetXObjPrevAlloc(rdram, ctx);
        goto after_1;
    // 0x8000955C: nop

    after_1:
    // 0x80009560: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_80009564:
    // 0x80009564: bne         $s0, $s2, L_8000954C
    if (ctx->r16 != ctx->r18) {
        // 0x80009568: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000954C;
    }
    // 0x80009568: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000956C: lw          $a0, 0x4C($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X4C);
    // 0x80009570: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80009574: beql        $a0, $zero, L_80009594
    if (ctx->r4 == 0) {
        // 0x80009578: lw          $s1, 0x6C($s3)
        ctx->r17 = MEM_W(ctx->r19, 0X6C);
            goto L_80009594;
    }
    goto skip_6;
    // 0x80009578: lw          $s1, 0x6C($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X6C);
    skip_6:
    // 0x8000957C: lw          $v0, 0x6A1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A1C);
    // 0x80009580: beql        $v0, $zero, L_80009594
    if (ctx->r2 == 0) {
        // 0x80009584: lw          $s1, 0x6C($s3)
        ctx->r17 = MEM_W(ctx->r19, 0X6C);
            goto L_80009594;
    }
    goto skip_7;
    // 0x80009584: lw          $s1, 0x6C($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X6C);
    skip_7:
    // 0x80009588: jalr        $v0
    // 0x8000958C: nop

    LOOKUP_FUNC(ctx->r2)(rdram, ctx);
        goto after_2;
    // 0x8000958C: nop

    after_2:
    // 0x80009590: lw          $s1, 0x6C($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X6C);
L_80009594:
    // 0x80009594: beql        $s1, $zero, L_800095B4
    if (ctx->r17 == 0) {
        // 0x80009598: lw          $s2, 0x80($s3)
        ctx->r18 = MEM_W(ctx->r19, 0X80);
            goto L_800095B4;
    }
    goto skip_8;
    // 0x80009598: lw          $s2, 0x80($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X80);
    skip_8:
L_8000959C:
    // 0x8000959C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800095A0: jal         0x80007EB0
    // 0x800095A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcSetAObjPrevAlloc(rdram, ctx);
        goto after_3;
    // 0x800095A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x800095A8: bne         $s0, $zero, L_8000959C
    if (ctx->r16 != 0) {
        // 0x800095AC: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_8000959C;
    }
    // 0x800095AC: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800095B0: lw          $s2, 0x80($s3)
    ctx->r18 = MEM_W(ctx->r19, 0X80);
L_800095B4:
    // 0x800095B4: beq         $s2, $zero, L_800095F0
    if (ctx->r18 == 0) {
        // 0x800095B8: nop
    
            goto L_800095F0;
    }
    // 0x800095B8: nop

L_800095BC:
    // 0x800095BC: lw          $s1, 0x90($s2)
    ctx->r17 = MEM_W(ctx->r18, 0X90);
    // 0x800095C0: beql        $s1, $zero, L_800095E0
    if (ctx->r17 == 0) {
        // 0x800095C4: lw          $s0, 0x0($s2)
        ctx->r16 = MEM_W(ctx->r18, 0X0);
            goto L_800095E0;
    }
    goto skip_9;
    // 0x800095C4: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    skip_9:
L_800095C8:
    // 0x800095C8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x800095CC: jal         0x80007EB0
    // 0x800095D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcSetAObjPrevAlloc(rdram, ctx);
        goto after_4;
    // 0x800095D0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x800095D4: bne         $s0, $zero, L_800095C8
    if (ctx->r16 != 0) {
        // 0x800095D8: or          $s1, $s0, $zero
        ctx->r17 = ctx->r16 | 0;
            goto L_800095C8;
    }
    // 0x800095D8: or          $s1, $s0, $zero
    ctx->r17 = ctx->r16 | 0;
    // 0x800095DC: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
L_800095E0:
    // 0x800095E0: jal         0x80007F58
    // 0x800095E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    gcSetMObjPrevAlloc(rdram, ctx);
        goto after_5;
    // 0x800095E4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_5:
    // 0x800095E8: bne         $s0, $zero, L_800095BC
    if (ctx->r16 != 0) {
        // 0x800095EC: or          $s2, $s0, $zero
        ctx->r18 = ctx->r16 | 0;
            goto L_800095BC;
    }
    // 0x800095EC: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
L_800095F0:
    // 0x800095F0: jal         0x80008004
    // 0x800095F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    gcSetDObjPrevAlloc(rdram, ctx);
        goto after_6;
    // 0x800095F4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x800095F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800095FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80009600: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80009604: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80009608: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000960C: jr          $ra
    // 0x80009610: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80009610: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftParamVelDamageTransferGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9CE8: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x800E9CEC: bne         $t6, $zero, L_800E9D70
    if (ctx->r14 != 0) {
        // 0x800E9CF0: nop
    
            goto L_800E9D70;
    }
    // 0x800E9CF0: nop

    // 0x800E9CF4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800E9CF8: lwc1        $f6, 0x6C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800E9CFC: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x800E9D00: addiu       $v0, $a0, 0xF8
    ctx->r2 = ADD32(ctx->r4, 0XF8);
    // 0x800E9D04: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800E9D08: nop

    // 0x800E9D0C: bc1f        L_800E9D70
    if (!c1cs) {
        // 0x800E9D10: nop
    
            goto L_800E9D70;
    }
    // 0x800E9D10: nop

    // 0x800E9D14: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800E9D18: lwc1        $f0, 0x54($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X54);
    // 0x800E9D1C: lui         $at, 0xC37A
    ctx->r1 = S32(0XC37A << 16);
    // 0x800E9D20: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800E9D24: swc1        $f0, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f0.u32l;
    // 0x800E9D28: bc1fl       L_800E9D38
    if (!c1cs) {
        // 0x800E9D2C: mtc1        $at, $f2
        ctx->f2.u32l = ctx->r1;
            goto L_800E9D38;
    }
    goto skip_0;
    // 0x800E9D2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    skip_0:
    // 0x800E9D30: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x800E9D34: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
L_800E9D38:
    // 0x800E9D38: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800E9D3C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800E9D40: nop

    // 0x800E9D44: bc1fl       L_800E9D58
    if (!c1cs) {
        // 0x800E9D48: lwc1        $f8, 0x4($v0)
        ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
            goto L_800E9D58;
    }
    goto skip_1;
    // 0x800E9D48: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
    skip_1:
    // 0x800E9D4C: swc1        $f2, 0x6C($a0)
    MEM_W(0X6C, ctx->r4) = ctx->f2.u32l;
    // 0x800E9D50: lwc1        $f0, 0x6C($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X6C);
    // 0x800E9D54: lwc1        $f8, 0x4($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X4);
L_800E9D58:
    // 0x800E9D58: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800E9D5C: swc1        $f10, 0x54($a0)
    MEM_W(0X54, ctx->r4) = ctx->f10.u32l;
    // 0x800E9D60: lwc1        $f16, 0x0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800E9D64: neg.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = -ctx->f16.fl;
    // 0x800E9D68: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800E9D6C: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
L_800E9D70:
    // 0x800E9D70: jr          $ra
    // 0x800E9D74: nop

    return;
    // 0x800E9D74: nop

;}
RECOMP_FUNC void mnModeSelectMakeData(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E8C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131E90: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131E94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E9C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80131EA0: jal         0x80009968
    // 0x80131EA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131EA4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131EA8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131EAC: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131EB0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131EB4: sw          $v0, 0x2C98($at)
    MEM_W(0X2C98, ctx->r1) = ctx->r2;
    // 0x80131EB8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131EBC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131EC0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131EC4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EC8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131ECC: jal         0x80009DF4
    // 0x80131ED0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131ED0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131ED4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131ED8: lw          $t7, 0x2C88($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2C88);
    // 0x80131EDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80131EE0: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131EE4: bne         $t7, $at, L_80131F50
    if (ctx->r15 != ctx->r1) {
        // 0x80131EE8: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_80131F50;
    }
    // 0x80131EE8: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80131EEC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131EF0: lw          $t8, 0x2D6C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2D6C);
    // 0x80131EF4: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80131EF8: addiu       $t9, $t9, 0x30B0
    ctx->r25 = ADD32(ctx->r25, 0X30B0);
    // 0x80131EFC: jal         0x800CCFDC
    // 0x80131F00: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131F00: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_2:
    // 0x80131F04: lhu         $t0, 0x24($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X24);
    // 0x80131F08: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x80131F0C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131F10: lui         $at, 0x430A
    ctx->r1 = S32(0X430A << 16);
    // 0x80131F14: andi        $t2, $t0, 0xFFDF
    ctx->r10 = ctx->r8 & 0XFFDF;
    // 0x80131F18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131F1C: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80131F20: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131F24: ori         $t3, $t2, 0x1
    ctx->r11 = ctx->r10 | 0X1;
    // 0x80131F28: sh          $t3, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r11;
    // 0x80131F2C: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131F30: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131F34: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131F38: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x80131F3C: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x80131F40: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x80131F44: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131F48: b           L_80131FA0
    // 0x80131F4C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
        goto L_80131FA0;
    // 0x80131F4C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80131F50:
    // 0x80131F50: lw          $t4, 0x2D6C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2D6C);
    // 0x80131F54: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80131F58: addiu       $t5, $t5, 0x6DC8
    ctx->r13 = ADD32(ctx->r13, 0X6DC8);
    // 0x80131F5C: jal         0x800CCFDC
    // 0x80131F60: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80131F60: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_3:
    // 0x80131F64: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80131F68: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x80131F6C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131F70: lui         $at, 0x430A
    ctx->r1 = S32(0X430A << 16);
    // 0x80131F74: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80131F78: addiu       $v1, $zero, 0x96
    ctx->r3 = ADD32(0, 0X96);
    // 0x80131F7C: andi        $t8, $t6, 0xFFDF
    ctx->r24 = ctx->r14 & 0XFFDF;
    // 0x80131F80: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80131F84: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80131F88: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80131F8C: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80131F90: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80131F94: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80131F98: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x80131F9C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80131FA0:
    // 0x80131FA0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131FA4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131FA8: jr          $ra
    // 0x80131FAC: nop

    return;
    // 0x80131FAC: nop

;}
RECOMP_FUNC void ftNessSpecialNProcAccessory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153950: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80153954: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80153958: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x8015395C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80153960: lw          $t7, 0x17C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X17C);
    // 0x80153964: beql        $t7, $zero, L_80153AB4
    if (ctx->r15 == 0) {
        // 0x80153968: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80153AB4;
    }
    goto skip_0;
    // 0x80153968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015396C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80153970: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80153974: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80153978: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8015397C: swc1        $f0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f0.u32l;
    // 0x80153980: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80153984: lw          $a0, 0x8E8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8E8);
    // 0x80153988: jal         0x800EDF24
    // 0x8015398C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x8015398C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    after_0:
    // 0x80153990: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80153994: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80153998: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015399C: lw          $t8, 0x44($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X44);
    // 0x801539A0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x801539A4: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801539A8: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x801539AC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801539B0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x801539B4: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x801539B8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x801539BC: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x801539C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801539C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801539C8: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x801539CC: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x801539D0: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x801539D4: swc1        $f18, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f18.u32l;
    // 0x801539D8: lw          $t9, 0x14C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14C);
    // 0x801539DC: bne         $t9, $at, L_80153A40
    if (ctx->r25 != ctx->r1) {
        // 0x801539E0: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_80153A40;
    }
    // 0x801539E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801539E4: lwc1        $f12, -0x3A60($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3A60);
    // 0x801539E8: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x801539EC: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x801539F0: jal         0x80035CD0
    // 0x801539F4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_1;
    // 0x801539F4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x801539F8: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x801539FC: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x80153A00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80153A04: lw          $t0, 0x44($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X44);
    // 0x80153A08: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80153A0C: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80153A10: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x80153A14: lwc1        $f12, -0x3A5C($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3A5C);
    // 0x80153A18: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80153A1C: mul.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80153A20: jal         0x800303F0
    // 0x80153A24: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_2;
    // 0x80153A24: swc1        $f4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f4.u32l;
    after_2:
    // 0x80153A28: lui         $at, 0x42BE
    ctx->r1 = S32(0X42BE << 16);
    // 0x80153A2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80153A30: nop

    // 0x80153A34: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80153A38: b           L_80153A9C
    // 0x80153A3C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
        goto L_80153A9C;
    // 0x80153A3C: swc1        $f16, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f16.u32l;
L_80153A40:
    // 0x80153A40: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80153A44: lwc1        $f12, -0x3A58($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3A58);
    // 0x80153A48: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80153A4C: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80153A50: jal         0x80035CD0
    // 0x80153A54: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_3;
    // 0x80153A54: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    after_3:
    // 0x80153A58: lw          $v0, 0x34($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X34);
    // 0x80153A5C: lui         $at, 0x4292
    ctx->r1 = S32(0X4292 << 16);
    // 0x80153A60: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80153A64: lw          $t1, 0x44($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X44);
    // 0x80153A68: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80153A6C: mul.s       $f10, $f0, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80153A70: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80153A74: lwc1        $f12, -0x3A54($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X3A54);
    // 0x80153A78: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80153A7C: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x80153A80: jal         0x800303F0
    // 0x80153A84: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_4;
    // 0x80153A84: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    after_4:
    // 0x80153A88: lui         $at, 0x4292
    ctx->r1 = S32(0X4292 << 16);
    // 0x80153A8C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80153A90: nop

    // 0x80153A94: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80153A98: swc1        $f18, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f18.u32l;
L_80153A9C:
    // 0x80153A9C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80153AA0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x80153AA4: addiu       $a2, $sp, 0x1C
    ctx->r6 = ADD32(ctx->r29, 0X1C);
    // 0x80153AA8: jal         0x8016AC78
    // 0x80153AAC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    wpNessPKFireMakeWeapon(rdram, ctx);
        goto after_5;
    // 0x80153AAC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    after_5:
    // 0x80153AB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80153AB4:
    // 0x80153AB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80153AB8: jr          $ra
    // 0x80153ABC: nop

    return;
    // 0x80153ABC: nop

;}
RECOMP_FUNC void grMainSetupMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801056C0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801056C4: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x801056C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801056CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801056D0: lbu         $v1, 0x1($t6)
    ctx->r3 = MEM_BU(ctx->r14, 0X1);
    // 0x801056D4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801056D8: slti        $at, $v1, 0x9
    ctx->r1 = SIGNED(ctx->r3) < 0X9 ? 1 : 0;
    // 0x801056DC: beq         $at, $zero, L_80105700
    if (ctx->r1 == 0) {
        // 0x801056E0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80105700;
    }
    // 0x801056E0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801056E4: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x801056E8: addu        $t9, $t9, $t7
    ctx->r25 = ADD32(ctx->r25, ctx->r15);
    // 0x801056EC: lw          $t9, -0x17C0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X17C0);
    // 0x801056F0: jalr        $t9
    // 0x801056F4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x801056F4: nop

    after_0:
    // 0x801056F8: b           L_80105750
    // 0x801056FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80105750;
    // 0x801056FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80105700:
    // 0x80105700: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80105704: bnel        $v0, $at, L_80105720
    if (ctx->r2 != ctx->r1) {
        // 0x80105708: slti        $at, $v0, 0x1D
        ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
            goto L_80105720;
    }
    goto skip_0;
    // 0x80105708: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    skip_0:
    // 0x8010570C: jal         0x8010B7C8
    // 0x80105710: nop

    grBonus3MakeGround(rdram, ctx);
        goto after_1;
    // 0x80105710: nop

    after_1:
    // 0x80105714: b           L_80105750
    // 0x80105718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80105750;
    // 0x80105718: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8010571C: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
L_80105720:
    // 0x80105720: bnel        $at, $zero, L_8010573C
    if (ctx->r1 != 0) {
        // 0x80105724: slti        $at, $v0, 0x11
        ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
            goto L_8010573C;
    }
    goto skip_1;
    // 0x80105724: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    skip_1:
    // 0x80105728: jal         0x8018DC38
    // 0x8010572C: nop

    sc1PBonusStageInitBonus2(rdram, ctx);
        goto after_2;
    // 0x8010572C: nop

    after_2:
    // 0x80105730: b           L_80105750
    // 0x80105734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80105750;
    // 0x80105734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80105738: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
L_8010573C:
    // 0x8010573C: bnel        $at, $zero, L_80105750
    if (ctx->r1 != 0) {
        // 0x80105740: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80105750;
    }
    goto skip_2;
    // 0x80105740: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80105744: jal         0x8018D5C8
    // 0x80105748: nop

    sc1PBonusStageMakeBonus1Ground(rdram, ctx);
        goto after_3;
    // 0x80105748: nop

    after_3:
    // 0x8010574C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80105750:
    // 0x80105750: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80105754: jr          $ra
    // 0x80105758: nop

    return;
    // 0x80105758: nop

;}
RECOMP_FUNC void ftPhysicsApplyGroundVelTransN(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D8C14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D8C18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D8C1C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800D8C20: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x800D8C24: lw          $v1, 0x8EC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8EC);
    // 0x800D8C28: lwc1        $f6, 0x1A4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1A4);
    // 0x800D8C2C: lwc1        $f10, 0x48($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X48);
    // 0x800D8C30: lwc1        $f4, 0x24($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X24);
    // 0x800D8C34: lw          $a1, 0x44($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X44);
    // 0x800D8C38: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D8C3C: negu        $t7, $a1
    ctx->r15 = SUB32(0, ctx->r5);
    // 0x800D8C40: lwc1        $f4, 0x19C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X19C);
    // 0x800D8C44: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D8C48: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800D8C4C: nop

    // 0x800D8C50: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D8C54: swc1        $f16, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f16.u32l;
    // 0x800D8C58: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x800D8C5C: lw          $t8, 0x74($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X74);
    // 0x800D8C60: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800D8C64: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800D8C68: lwc1        $f18, 0x40($t8)
    ctx->f18.u32l = MEM_W(ctx->r24, 0X40);
    // 0x800D8C6C: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D8C70: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800D8C74: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800D8C78: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800D8C7C: swc1        $f4, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f4.u32l;
    // 0x800D8C80: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x800D8C84: lwc1        $f10, 0x34($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, 0X34);
    // 0x800D8C88: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800D8C8C: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x800D8C90: nop

    // 0x800D8C94: bc1f        L_800D8CB4
    if (!c1cs) {
        // 0x800D8C98: nop
    
            goto L_800D8CB4;
    }
    // 0x800D8C98: nop

    // 0x800D8C9C: lwc1        $f4, 0x60($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X60);
    // 0x800D8CA0: lwc1        $f6, 0x68($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X68);
    // 0x800D8CA4: neg.s       $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = -ctx->f4.fl;
    // 0x800D8CA8: neg.s       $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = -ctx->f6.fl;
    // 0x800D8CAC: swc1        $f8, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f8.u32l;
    // 0x800D8CB0: swc1        $f10, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->f10.u32l;
L_800D8CB4:
    // 0x800D8CB4: jal         0x800D87D0
    // 0x800D8CB8: nop

    ftPhysicsSetGroundVelTransferAir(rdram, ctx);
        goto after_0;
    // 0x800D8CB8: nop

    after_0:
    // 0x800D8CBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D8CC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D8CC4: jr          $ra
    // 0x800D8CC8: nop

    return;
    // 0x800D8CC8: nop

;}
RECOMP_FUNC void ftMainUpdateMotionEventsForward(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E0478: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E047C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800E0480: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800E0484: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800E0488: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800E048C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800E0490: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800E0494: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800E0498: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800E049C: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x800E04A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E04A4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800E04A8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E04AC: lwc1        $f20, -0x3A8($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X3A8);
    // 0x800E04B0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800E04B4: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
L_800E04B8:
    // 0x800E04B8: lw          $t6, 0x86C($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X86C);
    // 0x800E04BC: addiu       $s0, $s3, 0x868
    ctx->r16 = ADD32(ctx->r19, 0X868);
    // 0x800E04C0: beql        $t6, $zero, L_800E05C0
    if (ctx->r14 == 0) {
        // 0x800E04C4: addiu       $s4, $s4, 0x20
        ctx->r20 = ADD32(ctx->r20, 0X20);
            goto L_800E05C0;
    }
    goto skip_0;
    // 0x800E04C4: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    skip_0:
    // 0x800E04C8: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E04CC: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800E04D0: nop

    // 0x800E04D4: bc1tl       L_800E04F0
    if (c1cs) {
        // 0x800E04D8: lw          $v0, 0x4($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X4);
            goto L_800E04F0;
    }
    goto skip_1;
    // 0x800E04D8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x800E04DC: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x800E04E0: lwc1        $f4, 0x78($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X78);
    // 0x800E04E4: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800E04E8: swc1        $f6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f6.u32l;
L_800E04EC:
    // 0x800E04EC: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
L_800E04F0:
    // 0x800E04F0: beql        $v0, $zero, L_800E05C0
    if (ctx->r2 == 0) {
        // 0x800E04F4: addiu       $s4, $s4, 0x20
        ctx->r20 = ADD32(ctx->r20, 0X20);
            goto L_800E05C0;
    }
    goto skip_2;
    // 0x800E04F4: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    skip_2:
    // 0x800E04F8: lwc1        $f0, 0x0($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X0);
    // 0x800E04FC: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800E0500: nop

    // 0x800E0504: bc1fl       L_800E053C
    if (!c1cs) {
        // 0x800E0508: c.lt.s      $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
            goto L_800E053C;
    }
    goto skip_3;
    // 0x800E0508: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    skip_3:
    // 0x800E050C: lw          $t8, 0x74($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X74);
    // 0x800E0510: lwc1        $f0, 0x78($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X78);
    // 0x800E0514: lwc1        $f8, 0x78($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X78);
    // 0x800E0518: c.le.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl <= ctx->f0.fl;
    // 0x800E051C: nop

    // 0x800E0520: bc1tl       L_800E05C0
    if (c1cs) {
        // 0x800E0524: addiu       $s4, $s4, 0x20
        ctx->r20 = ADD32(ctx->r20, 0X20);
            goto L_800E05C0;
    }
    goto skip_4;
    // 0x800E0524: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    skip_4:
    // 0x800E0528: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x800E052C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E0530: b           L_800E0548
    // 0x800E0534: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
        goto L_800E0548;
    // 0x800E0534: swc1        $f10, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f10.u32l;
    // 0x800E0538: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
L_800E053C:
    // 0x800E053C: nop

    // 0x800E0540: bc1tl       L_800E05C0
    if (c1cs) {
        // 0x800E0544: addiu       $s4, $s4, 0x20
        ctx->r20 = ADD32(ctx->r20, 0X20);
            goto L_800E05C0;
    }
    goto skip_5;
    // 0x800E0544: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
    skip_5:
L_800E0548:
    // 0x800E0548: lw          $a3, 0x0($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X0);
    // 0x800E054C: srl         $a3, $a3, 26
    ctx->r7 = S32(U32(ctx->r7) >> 26);
    // 0x800E0550: addiu       $t9, $a3, -0x3
    ctx->r25 = ADD32(ctx->r7, -0X3);
    // 0x800E0554: sltiu       $at, $t9, 0x31
    ctx->r1 = ctx->r25 < 0X31 ? 1 : 0;
    // 0x800E0558: beq         $at, $zero, L_800E05A4
    if (ctx->r1 == 0) {
        // 0x800E055C: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_800E05A4;
    }
    // 0x800E055C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800E0560: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E0564: addu        $at, $at, $t9
    gpr jr_addend_800E056C = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x800E0568: lw          $t9, -0x3A4($at)
    ctx->r25 = ADD32(ctx->r1, -0X3A4);
    // 0x800E056C: jr          $t9
    // 0x800E0570: nop

    switch (jr_addend_800E056C >> 2) {
        case 0: goto L_800E058C; break;
        case 1: goto L_800E058C; break;
        case 2: goto L_800E0574; break;
        case 3: goto L_800E0574; break;
        case 4: goto L_800E0598; break;
        case 5: goto L_800E0574; break;
        case 6: goto L_800E0574; break;
        case 7: goto L_800E0574; break;
        case 8: goto L_800E0574; break;
        case 9: goto L_800E05A4; break;
        case 10: goto L_800E05A4; break;
        case 11: goto L_800E0574; break;
        case 12: goto L_800E0574; break;
        case 13: goto L_800E0574; break;
        case 14: goto L_800E0574; break;
        case 15: goto L_800E0574; break;
        case 16: goto L_800E0574; break;
        case 17: goto L_800E0574; break;
        case 18: goto L_800E0574; break;
        case 19: goto L_800E0574; break;
        case 20: goto L_800E0574; break;
        case 21: goto L_800E05A4; break;
        case 22: goto L_800E0574; break;
        case 23: goto L_800E0574; break;
        case 24: goto L_800E05A4; break;
        case 25: goto L_800E05A4; break;
        case 26: goto L_800E05A4; break;
        case 27: goto L_800E05A4; break;
        case 28: goto L_800E05A4; break;
        case 29: goto L_800E05A4; break;
        case 30: goto L_800E05A4; break;
        case 31: goto L_800E05A4; break;
        case 32: goto L_800E05A4; break;
        case 33: goto L_800E05A4; break;
        case 34: goto L_800E05A4; break;
        case 35: goto L_800E0580; break;
        case 36: goto L_800E0580; break;
        case 37: goto L_800E05A4; break;
        case 38: goto L_800E05A4; break;
        case 39: goto L_800E05A4; break;
        case 40: goto L_800E05A4; break;
        case 41: goto L_800E0574; break;
        case 42: goto L_800E0574; break;
        case 43: goto L_800E05A4; break;
        case 44: goto L_800E05A4; break;
        case 45: goto L_800E05A4; break;
        case 46: goto L_800E0574; break;
        case 47: goto L_800E0574; break;
        case 48: goto L_800E0574; break;
        default: switch_error(__func__, 0x800E056C, 0x8012FC5C);
    }
    // 0x800E0570: nop

L_800E0574:
    // 0x800E0574: addiu       $t0, $v0, 0x4
    ctx->r8 = ADD32(ctx->r2, 0X4);
    // 0x800E0578: b           L_800E04EC
    // 0x800E057C: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
        goto L_800E04EC;
    // 0x800E057C: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
L_800E0580:
    // 0x800E0580: addiu       $t1, $v0, 0x10
    ctx->r9 = ADD32(ctx->r2, 0X10);
    // 0x800E0584: b           L_800E04EC
    // 0x800E0588: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
        goto L_800E04EC;
    // 0x800E0588: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
L_800E058C:
    // 0x800E058C: addiu       $t2, $v0, 0x14
    ctx->r10 = ADD32(ctx->r2, 0X14);
    // 0x800E0590: b           L_800E04EC
    // 0x800E0594: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
        goto L_800E04EC;
    // 0x800E0594: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
L_800E0598:
    // 0x800E0598: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800E059C: b           L_800E04EC
    // 0x800E05A0: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
        goto L_800E04EC;
    // 0x800E05A0: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
L_800E05A4:
    // 0x800E05A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E05A8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E05AC: jal         0x800DF0F0
    // 0x800E05B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    ftMainParseMotionEvent(rdram, ctx);
        goto after_0;
    // 0x800E05B0: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_0:
    // 0x800E05B4: b           L_800E04F0
    // 0x800E05B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
        goto L_800E04F0;
    // 0x800E05B8: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800E05BC: addiu       $s4, $s4, 0x20
    ctx->r20 = ADD32(ctx->r20, 0X20);
L_800E05C0:
    // 0x800E05C0: slti        $at, $s4, 0x40
    ctx->r1 = SIGNED(ctx->r20) < 0X40 ? 1 : 0;
    // 0x800E05C4: bne         $at, $zero, L_800E04B8
    if (ctx->r1 != 0) {
        // 0x800E05C8: addiu       $s3, $s3, 0x20
        ctx->r19 = ADD32(ctx->r19, 0X20);
            goto L_800E04B8;
    }
    // 0x800E05C8: addiu       $s3, $s3, 0x20
    ctx->r19 = ADD32(ctx->r19, 0X20);
    // 0x800E05CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E05D0: addiu       $s0, $s2, 0x868
    ctx->r16 = ADD32(ctx->r18, 0X868);
    // 0x800E05D4: addiu       $v1, $s2, 0x8A8
    ctx->r3 = ADD32(ctx->r18, 0X8A8);
    // 0x800E05D8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
L_800E05DC:
    // 0x800E05DC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800E05E0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800E05E4: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x800E05E8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800E05EC: lw          $t4, -0x1C($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X1C);
    // 0x800E05F0: addiu       $v1, $v1, 0x20
    ctx->r3 = ADD32(ctx->r3, 0X20);
    // 0x800E05F4: sw          $t4, -0x1C($v1)
    MEM_W(-0X1C, ctx->r3) = ctx->r12;
    // 0x800E05F8: lw          $t5, -0x18($s0)
    ctx->r13 = MEM_W(ctx->r16, -0X18);
    // 0x800E05FC: sw          $t5, -0x18($v1)
    MEM_W(-0X18, ctx->r3) = ctx->r13;
    // 0x800E0600: lw          $t4, -0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X14);
    // 0x800E0604: sw          $t4, -0x14($v1)
    MEM_W(-0X14, ctx->r3) = ctx->r12;
    // 0x800E0608: lw          $t5, -0x10($s0)
    ctx->r13 = MEM_W(ctx->r16, -0X10);
    // 0x800E060C: sw          $t5, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->r13;
    // 0x800E0610: lw          $t4, -0xC($s0)
    ctx->r12 = MEM_W(ctx->r16, -0XC);
    // 0x800E0614: sw          $t4, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r12;
    // 0x800E0618: lw          $t5, -0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, -0X8);
    // 0x800E061C: sw          $t5, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->r13;
    // 0x800E0620: lw          $t4, -0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X4);
    // 0x800E0624: bne         $v0, $a0, L_800E05DC
    if (ctx->r2 != ctx->r4) {
        // 0x800E0628: sw          $t4, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r12;
            goto L_800E05DC;
    }
    // 0x800E0628: sw          $t4, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r12;
    // 0x800E062C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800E0630: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800E0634: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800E0638: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800E063C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800E0640: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800E0644: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800E0648: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800E064C: jr          $ra
    // 0x800E0650: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800E0650: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void sc1PTrainingModeUpdateSpeedOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D684: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D688: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D68C: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D690: addiu       $a0, $a0, 0xB70
    ctx->r4 = ADD32(ctx->r4, 0XB70);
    // 0x8018D694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D698: jal         0x8018D40C
    // 0x8018D69C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    sc1PTrainingModeCheckUpdateOptionID(rdram, ctx);
        goto after_0;
    // 0x8018D69C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x8018D6A0: beq         $v0, $zero, L_8018D6C8
    if (ctx->r2 == 0) {
        // 0x8018D6A4: lui         $v0, 0x8019
        ctx->r2 = S32(0X8019 << 16);
            goto L_8018D6C8;
    }
    // 0x8018D6A4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018D6A8: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018D6AC: sb          $zero, 0xD4($v0)
    MEM_B(0XD4, ctx->r2) = 0;
    // 0x8018D6B0: jal         0x8018E714
    // 0x8018D6B4: sb          $zero, 0xD3($v0)
    MEM_B(0XD3, ctx->r2) = 0;
    sc1PTrainingModeUpdateSpeedDisplaySprite(rdram, ctx);
        goto after_1;
    // 0x8018D6B4: sb          $zero, 0xD3($v0)
    MEM_B(0XD3, ctx->r2) = 0;
    after_1:
    // 0x8018D6B8: jal         0x8018F2C4
    // 0x8018D6BC: nop

    sc1PTrainingModeUpdateSpeedOptionSprite(rdram, ctx);
        goto after_2;
    // 0x8018D6BC: nop

    after_2:
    // 0x8018D6C0: jal         0x8018D3DC
    // 0x8018D6C4: nop

    sc1PTrainingModeUpdateScroll(rdram, ctx);
        goto after_3;
    // 0x8018D6C4: nop

    after_3:
L_8018D6C8:
    // 0x8018D6C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D6CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D6D0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D6D4: jr          $ra
    // 0x8018D6D8: nop

    return;
    // 0x8018D6D8: nop

;}
RECOMP_FUNC void lbCommonMag2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A84: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C7A88: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7A8C: lwc1        $f0, 0x0($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800C7A90: lwc1        $f2, 0x4($a0)
    ctx->f2.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800C7A94: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C7A98: nop

    // 0x800C7A9C: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C7AA0: jal         0x80033510
    // 0x800C7AA4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800C7AA4: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_0:
    // 0x800C7AA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7AAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C7AB0: jr          $ra
    // 0x800C7AB4: nop

    return;
    // 0x800C7AB4: nop

;}
RECOMP_FUNC void scExplainSpecialMoveRGBProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DACC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DAD0: addiu       $a1, $a1, -0x1618
    ctx->r5 = ADD32(ctx->r5, -0X1618);
    // 0x8018DAD4: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8018DAD8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DADC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018DAE0: lbu         $v0, 0x27($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X27);
    // 0x8018DAE4: lw          $a0, -0x1604($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1604);
    // 0x8018DAE8: bnel        $v0, $at, L_8018DB38
    if (ctx->r2 != ctx->r1) {
        // 0x8018DAEC: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8018DB38;
    }
    goto skip_0;
    // 0x8018DAEC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    skip_0:
    // 0x8018DAF0: lhu         $t6, 0xC($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XC);
    // 0x8018DAF4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8018DAF8: addiu       $t0, $zero, -0x28
    ctx->r8 = ADD32(0, -0X28);
    // 0x8018DAFC: addiu       $t7, $t6, -0x96
    ctx->r15 = ADD32(ctx->r14, -0X96);
    // 0x8018DB00: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8018DB04: nop

    // 0x8018DB08: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018DB0C: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8018DB10: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8018DB14: lbu         $t9, 0xE($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0XE);
    // 0x8018DB18: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x8018DB1C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x8018DB20: nop

    // 0x8018DB24: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8018DB28: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x8018DB2C: jr          $ra
    // 0x8018DB30: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    return;
    // 0x8018DB30: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x8018DB34: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8018DB38:
    // 0x8018DB38: sw          $t2, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r10;
    // 0x8018DB3C: jr          $ra
    // 0x8018DB40: nop

    return;
    // 0x8018DB40: nop

;}
RECOMP_FUNC void func_ovl8_80385EE4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80385EE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80385EE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80385EEC: jal         0x8038649C
    // 0x80385EF0: nop

    func_ovl8_8038649C(rdram, ctx);
        goto after_0;
    // 0x80385EF0: nop

    after_0:
    // 0x80385EF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80385EF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80385EFC: jr          $ra
    // 0x80385F00: nop

    return;
    // 0x80385F00: nop

;}
RECOMP_FUNC void ftLinkSpecialHiEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80163F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80163F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80163F5C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80163F60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80163F64: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80163F68: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80163F6C: nop

    // 0x80163F70: bc1fl       L_80163FA4
    if (!c1cs) {
        // 0x80163F74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80163FA4;
    }
    goto skip_0;
    // 0x80163F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80163F78: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80163F7C: lw          $v0, 0xB18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0XB18);
    // 0x80163F80: beq         $v0, $zero, L_80163F98
    if (ctx->r2 == 0) {
        // 0x80163F84: nop
    
            goto L_80163F98;
    }
    // 0x80163F84: nop

    // 0x80163F88: lw          $a1, 0x84($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X84);
    // 0x80163F8C: jal         0x80163B40
    // 0x80163F90: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    ftLinkSpecialHiDestroyWeapon(rdram, ctx);
        goto after_0;
    // 0x80163F90: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x80163F94: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80163F98:
    // 0x80163F98: jal         0x8013E1C8
    // 0x80163F9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x80163F9C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
    // 0x80163FA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80163FA4:
    // 0x80163FA4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80163FA8: jr          $ra
    // 0x80163FAC: nop

    return;
    // 0x80163FAC: nop

;}
RECOMP_FUNC void ftCaptainSpecialAirLwProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FFE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015FFE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015FFE8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015FFEC: jal         0x800DE6E4
    // 0x8015FFF0: addiu       $a1, $a1, 0xEC
    ctx->r5 = ADD32(ctx->r5, 0XEC);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015FFF0: addiu       $a1, $a1, 0xEC
    ctx->r5 = ADD32(ctx->r5, 0XEC);
    after_0:
    // 0x8015FFF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015FFF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015FFFC: jr          $ra
    // 0x80160000: nop

    return;
    // 0x80160000: nop

;}
RECOMP_FUNC void mnVSItemSwitchInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132948: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013294C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132950: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132954: jal         0x80132650
    // 0x80132958: sw          $zero, 0x33D8($at)
    MEM_W(0X33D8, ctx->r1) = 0;
    mnVSItemSwitchGetItemSettings(rdram, ctx);
        goto after_0;
    // 0x80132958: sw          $zero, 0x33D8($at)
    MEM_W(0X33D8, ctx->r1) = 0;
    after_0:
    // 0x8013295C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132960: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132964: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132968: sw          $zero, 0x3464($at)
    MEM_W(0X3464, ctx->r1) = 0;
    // 0x8013296C: addiu       $v0, $v0, 0x3468
    ctx->r2 = ADD32(ctx->r2, 0X3468);
    // 0x80132970: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80132974: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132978: addiu       $t7, $zero, 0x4650
    ctx->r15 = ADD32(0, 0X4650);
    // 0x8013297C: sw          $t7, 0x346C($at)
    MEM_W(0X346C, ctx->r1) = ctx->r15;
    // 0x80132980: jr          $ra
    // 0x80132984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80132984: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void grPupupuFlowersBackLoopEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80106008: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010600C: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x80106010: lbu         $t6, 0x27($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X27);
    // 0x80106014: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80106018: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x8010601C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80106020: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x80106024: bne         $t8, $zero, L_8010603C
    if (ctx->r24 != 0) {
        // 0x80106028: sb          $t7, 0x27($v0)
        MEM_B(0X27, ctx->r2) = ctx->r15;
            goto L_8010603C;
    }
    // 0x80106028: sb          $t7, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r15;
    // 0x8010602C: addiu       $t1, $zero, 0xF
    ctx->r9 = ADD32(0, 0XF);
    // 0x80106030: sb          $t9, 0x2F($v0)
    MEM_B(0X2F, ctx->r2) = ctx->r25;
    // 0x80106034: sb          $t0, 0x2B($v0)
    MEM_B(0X2B, ctx->r2) = ctx->r8;
    // 0x80106038: sb          $t1, 0x27($v0)
    MEM_B(0X27, ctx->r2) = ctx->r9;
L_8010603C:
    // 0x8010603C: jr          $ra
    // 0x80106040: nop

    return;
    // 0x80106040: nop

;}
RECOMP_FUNC void mnPlayers1PGameMakeLabelsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801346B8: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801346BC: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801346C0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801346C4: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801346C8: addiu       $t7, $zero, 0x46
    ctx->r15 = ADD32(0, 0X46);
    // 0x801346CC: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x801346D0: addiu       $t9, $zero, 0x0
    ctx->r25 = ADD32(0, 0X0);
    // 0x801346D4: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801346D8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801346DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801346E0: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801346E4: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801346E8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801346EC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801346F0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801346F4: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801346F8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801346FC: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80134700: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80134704: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80134708: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013470C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134710: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80134714: jal         0x8000B93C
    // 0x80134718: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80134718: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013471C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80134720: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80134724: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80134728: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013472C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134730: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80134734: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80134738: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013473C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80134740: jal         0x80007080
    // 0x80134744: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80134744: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80134748: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8013474C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80134750: jr          $ra
    // 0x80134754: nop

    return;
    // 0x80134754: nop

;}
RECOMP_FUNC void mvOpeningCliffHillsProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80131B5C: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80131B60: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131B64: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80131B68: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B6C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80131B70: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80131B74: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80131B78: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80131B7C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131B80: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131B84: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x80131B88: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x80131B8C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80131B90: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80131B94: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131B98: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80131B9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BA0: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x80131BA4: lui         $t2, 0x55
    ctx->r10 = S32(0X55 << 16);
    // 0x80131BA8: addiu       $t0, $v0, 0x8
    ctx->r8 = ADD32(ctx->r2, 0X8);
    // 0x80131BAC: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x80131BB0: ori         $t2, $t2, 0x2048
    ctx->r10 = ctx->r10 | 0X2048;
    // 0x80131BB4: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x80131BB8: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x80131BBC: jal         0x80014038
    // 0x80131BC0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    gcDrawDObjTreeForGObj(rdram, ctx);
        goto after_0;
    // 0x80131BC0: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    after_0:
    // 0x80131BC4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80131BC8: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80131BCC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BD0: lui         $t4, 0xE700
    ctx->r12 = S32(0XE700 << 16);
    // 0x80131BD4: lui         $t6, 0xE300
    ctx->r14 = S32(0XE300 << 16);
    // 0x80131BD8: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x80131BDC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x80131BE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131BE4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80131BE8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131BEC: ori         $t6, $t6, 0xA01
    ctx->r14 = ctx->r14 | 0XA01;
    // 0x80131BF0: lui         $t8, 0xE200
    ctx->r24 = S32(0XE200 << 16);
    // 0x80131BF4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80131BF8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x80131BFC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80131C00: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80131C04: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80131C08: lui         $t9, 0x55
    ctx->r25 = S32(0X55 << 16);
    // 0x80131C0C: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x80131C10: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80131C14: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131C18: ori         $t8, $t8, 0x1C
    ctx->r24 = ctx->r24 | 0X1C;
    // 0x80131C1C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80131C20: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80131C24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131C28: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80131C2C: jr          $ra
    // 0x80131C30: nop

    return;
    // 0x80131C30: nop

;}
RECOMP_FUNC void func_ovl8_80386BE0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80386BE0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80386BE4: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80386BE8: addiu       $s2, $a1, 0x4
    ctx->r18 = ADD32(ctx->r5, 0X4);
    // 0x80386BEC: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80386BF0: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x80386BF4: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x80386BF8: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80386BFC: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80386C00: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80386C04: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80386C08: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x80386C0C: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x80386C10: andi        $t6, $s2, 0x7
    ctx->r14 = ctx->r18 & 0X7;
    // 0x80386C14: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80386C18: beq         $t6, $zero, L_80386C28
    if (ctx->r14 == 0) {
        // 0x80386C1C: lw          $s0, 0x0($a1)
        ctx->r16 = MEM_W(ctx->r5, 0X0);
            goto L_80386C28;
    }
    // 0x80386C1C: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x80386C20: b           L_80386C2C
    // 0x80386C24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80386C2C;
    // 0x80386C24: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80386C28:
    // 0x80386C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80386C2C:
    // 0x80386C2C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x80386C30: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80386C34: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x80386C38: beq         $v1, $zero, L_80386F5C
    if (ctx->r3 == 0) {
        // 0x80386C3C: andi        $t7, $v1, 0x80
        ctx->r15 = ctx->r3 & 0X80;
            goto L_80386F5C;
    }
    // 0x80386C3C: andi        $t7, $v1, 0x80
    ctx->r15 = ctx->r3 & 0X80;
L_80386C40:
    // 0x80386C40: beq         $t7, $zero, L_80386C7C
    if (ctx->r15 == 0) {
        // 0x80386C44: addiu       $at, $zero, 0x25
        ctx->r1 = ADD32(0, 0X25);
            goto L_80386C7C;
    }
    // 0x80386C44: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80386C48: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80386C4C: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x80386C50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386C54: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80386C58: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80386C5C: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x80386C60: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80386C64: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80386C68: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80386C6C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80386C70: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386C74: b           L_80386F50
    // 0x80386C78: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
        goto L_80386F50;
    // 0x80386C78: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
L_80386C7C:
    // 0x80386C7C: beq         $v1, $at, L_80386CA0
    if (ctx->r3 == ctx->r1) {
        // 0x80386C80: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_80386CA0;
    }
    // 0x80386C80: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80386C84: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80386C88: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80386C8C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80386C90: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80386C94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386C98: b           L_80386F50
    // 0x80386C9C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
        goto L_80386F50;
    // 0x80386C9C: sb          $t1, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r9;
L_80386CA0:
    // 0x80386CA0: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80386CA4: addiu       $at, $zero, 0x2D
    ctx->r1 = ADD32(0, 0X2D);
    // 0x80386CA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386CAC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x80386CB0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x80386CB4: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x80386CB8: addiu       $s4, $zero, 0x4
    ctx->r20 = ADD32(0, 0X4);
    // 0x80386CBC: bne         $a0, $at, L_80386CD4
    if (ctx->r4 != ctx->r1) {
        // 0x80386CC0: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80386CD4;
    }
    // 0x80386CC0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80386CC4: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80386CC8: or          $s6, $fp, $zero
    ctx->r22 = ctx->r30 | 0;
    // 0x80386CCC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386CD0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80386CD4:
    // 0x80386CD4: addiu       $at, $zero, 0x30
    ctx->r1 = ADD32(0, 0X30);
    // 0x80386CD8: bnel        $v1, $at, L_80386CF4
    if (ctx->r3 != ctx->r1) {
        // 0x80386CDC: slti        $at, $v1, 0x31
        ctx->r1 = SIGNED(ctx->r3) < 0X31 ? 1 : 0;
            goto L_80386CF4;
    }
    goto skip_0;
    // 0x80386CDC: slti        $at, $v1, 0x31
    ctx->r1 = SIGNED(ctx->r3) < 0X31 ? 1 : 0;
    skip_0:
    // 0x80386CE0: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80386CE4: or          $s7, $fp, $zero
    ctx->r23 = ctx->r30 | 0;
    // 0x80386CE8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386CEC: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80386CF0: slti        $at, $v1, 0x31
    ctx->r1 = SIGNED(ctx->r3) < 0X31 ? 1 : 0;
L_80386CF4:
    // 0x80386CF4: bne         $at, $zero, L_80386D54
    if (ctx->r1 != 0) {
        // 0x80386CF8: slti        $at, $v1, 0x3A
        ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
            goto L_80386D54;
    }
    // 0x80386CF8: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
    // 0x80386CFC: beql        $at, $zero, L_80386D58
    if (ctx->r1 == 0) {
        // 0x80386D00: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80386D58;
    }
    goto skip_1;
    // 0x80386D00: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_1:
    // 0x80386D04: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80386D08: jal         0x80386F90
    // 0x80386D0C: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    stringToNumber(rdram, ctx);
        goto after_0;
    // 0x80386D0C: sw          $t0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r8;
    after_0:
    // 0x80386D10: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80386D14: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x80386D18: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80386D1C: slti        $at, $a0, 0x30
    ctx->r1 = SIGNED(ctx->r4) < 0X30 ? 1 : 0;
    // 0x80386D20: bne         $at, $zero, L_80386D54
    if (ctx->r1 != 0) {
        // 0x80386D24: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80386D54;
    }
    // 0x80386D24: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80386D28: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
    // 0x80386D2C: beql        $at, $zero, L_80386D58
    if (ctx->r1 == 0) {
        // 0x80386D30: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80386D58;
    }
    goto skip_2;
    // 0x80386D30: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    skip_2:
    // 0x80386D34: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
L_80386D38:
    // 0x80386D38: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386D3C: slti        $at, $a0, 0x30
    ctx->r1 = SIGNED(ctx->r4) < 0X30 ? 1 : 0;
    // 0x80386D40: bne         $at, $zero, L_80386D54
    if (ctx->r1 != 0) {
        // 0x80386D44: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80386D54;
    }
    // 0x80386D44: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80386D48: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
    // 0x80386D4C: bnel        $at, $zero, L_80386D38
    if (ctx->r1 != 0) {
        // 0x80386D50: lbu         $a0, 0x1($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X1);
            goto L_80386D38;
    }
    goto skip_3;
    // 0x80386D50: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    skip_3:
L_80386D54:
    // 0x80386D54: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
L_80386D58:
    // 0x80386D58: bnel        $v1, $at, L_80386DCC
    if (ctx->r3 != ctx->r1) {
        // 0x80386D5C: addiu       $at, $zero, 0x69
        ctx->r1 = ADD32(0, 0X69);
            goto L_80386DCC;
    }
    goto skip_4;
    // 0x80386D5C: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    skip_4:
    // 0x80386D60: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80386D64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386D68: slti        $at, $a0, 0x30
    ctx->r1 = SIGNED(ctx->r4) < 0X30 ? 1 : 0;
    // 0x80386D6C: bne         $at, $zero, L_80386DC8
    if (ctx->r1 != 0) {
        // 0x80386D70: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80386DC8;
    }
    // 0x80386D70: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80386D74: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
    // 0x80386D78: beql        $at, $zero, L_80386DCC
    if (ctx->r1 == 0) {
        // 0x80386D7C: addiu       $at, $zero, 0x69
        ctx->r1 = ADD32(0, 0X69);
            goto L_80386DCC;
    }
    goto skip_5;
    // 0x80386D7C: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    skip_5:
    // 0x80386D80: jal         0x80386F90
    // 0x80386D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    stringToNumber(rdram, ctx);
        goto after_1;
    // 0x80386D84: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80386D88: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x80386D8C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80386D90: slti        $at, $a0, 0x30
    ctx->r1 = SIGNED(ctx->r4) < 0X30 ? 1 : 0;
    // 0x80386D94: bne         $at, $zero, L_80386DC8
    if (ctx->r1 != 0) {
        // 0x80386D98: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80386DC8;
    }
    // 0x80386D98: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80386D9C: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
    // 0x80386DA0: beql        $at, $zero, L_80386DCC
    if (ctx->r1 == 0) {
        // 0x80386DA4: addiu       $at, $zero, 0x69
        ctx->r1 = ADD32(0, 0X69);
            goto L_80386DCC;
    }
    goto skip_6;
    // 0x80386DA4: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    skip_6:
    // 0x80386DA8: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
L_80386DAC:
    // 0x80386DAC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386DB0: slti        $at, $a0, 0x30
    ctx->r1 = SIGNED(ctx->r4) < 0X30 ? 1 : 0;
    // 0x80386DB4: bne         $at, $zero, L_80386DC8
    if (ctx->r1 != 0) {
        // 0x80386DB8: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_80386DC8;
    }
    // 0x80386DB8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80386DBC: slti        $at, $v1, 0x3A
    ctx->r1 = SIGNED(ctx->r3) < 0X3A ? 1 : 0;
    // 0x80386DC0: bnel        $at, $zero, L_80386DAC
    if (ctx->r1 != 0) {
        // 0x80386DC4: lbu         $a0, 0x1($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X1);
            goto L_80386DAC;
    }
    goto skip_7;
    // 0x80386DC4: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    skip_7:
L_80386DC8:
    // 0x80386DC8: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
L_80386DCC:
    // 0x80386DCC: beq         $v1, $at, L_80386DE8
    if (ctx->r3 == ctx->r1) {
        // 0x80386DD0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80386DE8;
    }
    // 0x80386DD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80386DD4: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x80386DD8: beql        $v1, $at, L_80386DFC
    if (ctx->r3 == ctx->r1) {
        // 0x80386DDC: lbu         $a0, 0x1($s0)
        ctx->r4 = MEM_BU(ctx->r16, 0X1);
            goto L_80386DFC;
    }
    goto skip_8;
    // 0x80386DDC: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    skip_8:
    // 0x80386DE0: b           L_80386E0C
    // 0x80386DE4: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
        goto L_80386E0C;
    // 0x80386DE4: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
L_80386DE8:
    // 0x80386DE8: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
    // 0x80386DEC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386DF0: b           L_80386E08
    // 0x80386DF4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
        goto L_80386E08;
    // 0x80386DF4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80386DF8: lbu         $a0, 0x1($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X1);
L_80386DFC:
    // 0x80386DFC: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x80386E00: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80386E04: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_80386E08:
    // 0x80386E08: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
L_80386E0C:
    // 0x80386E0C: beq         $v0, $at, L_80386E3C
    if (ctx->r2 == ctx->r1) {
        // 0x80386E10: addiu       $at, $zero, 0x73
        ctx->r1 = ADD32(0, 0X73);
            goto L_80386E3C;
    }
    // 0x80386E10: addiu       $at, $zero, 0x73
    ctx->r1 = ADD32(0, 0X73);
    // 0x80386E14: beq         $v0, $at, L_80386E58
    if (ctx->r2 == ctx->r1) {
        // 0x80386E18: or          $a2, $s6, $zero
        ctx->r6 = ctx->r22 | 0;
            goto L_80386E58;
    }
    // 0x80386E18: or          $a2, $s6, $zero
    ctx->r6 = ctx->r22 | 0;
    // 0x80386E1C: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80386E20: beq         $v0, $at, L_80386E7C
    if (ctx->r2 == ctx->r1) {
        // 0x80386E24: addiu       $at, $zero, 0x66
        ctx->r1 = ADD32(0, 0X66);
            goto L_80386E7C;
    }
    // 0x80386E24: addiu       $at, $zero, 0x66
    ctx->r1 = ADD32(0, 0X66);
    // 0x80386E28: beq         $v0, $at, L_80386F00
    if (ctx->r2 == ctx->r1) {
        // 0x80386E2C: or          $v0, $s1, $zero
        ctx->r2 = ctx->r17 | 0;
            goto L_80386F00;
    }
    // 0x80386E2C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80386E30: sb          $a0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r4;
    // 0x80386E34: b           L_80386F4C
    // 0x80386E38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
        goto L_80386F4C;
    // 0x80386E38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80386E3C:
    // 0x80386E3C: lbu         $t2, 0x0($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X0);
    // 0x80386E40: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80386E44: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80386E48: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80386E4C: subu        $s3, $fp, $s3
    ctx->r19 = SUB32(ctx->r30, ctx->r19);
    // 0x80386E50: b           L_80386F4C
    // 0x80386E54: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
        goto L_80386F4C;
    // 0x80386E54: sb          $t2, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r10;
L_80386E58:
    // 0x80386E58: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80386E5C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80386E60: subu        $s3, $fp, $s3
    ctx->r19 = SUB32(ctx->r30, ctx->r19);
    // 0x80386E64: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80386E68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80386E6C: jal         0x80386FE0
    // 0x80386E70: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    func_ovl8_80386FE0(rdram, ctx);
        goto after_2;
    // 0x80386E70: or          $a3, $s5, $zero
    ctx->r7 = ctx->r21 | 0;
    after_2:
    // 0x80386E74: b           L_80386F4C
    // 0x80386E78: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
        goto L_80386F4C;
    // 0x80386E78: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_80386E7C:
    // 0x80386E7C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80386E80: beq         $s4, $at, L_80386E9C
    if (ctx->r20 == ctx->r1) {
        // 0x80386E84: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80386E9C;
    }
    // 0x80386E84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80386E88: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80386E8C: beq         $s4, $at, L_80386EB4
    if (ctx->r20 == ctx->r1) {
        // 0x80386E90: nop
    
            goto L_80386EB4;
    }
    // 0x80386E90: nop

    // 0x80386E94: b           L_80386ED8
    // 0x80386E98: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
        goto L_80386ED8;
    // 0x80386E98: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
L_80386E9C:
    // 0x80386E9C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80386EA0: subu        $s3, $fp, $s3
    ctx->r19 = SUB32(ctx->r30, ctx->r19);
    // 0x80386EA4: sra         $t4, $t3, 31
    ctx->r12 = S32(SIGNED(ctx->r11) >> 31);
    // 0x80386EA8: sw          $t4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r12;
    // 0x80386EAC: b           L_80386ED4
    // 0x80386EB0: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
        goto L_80386ED4;
    // 0x80386EB0: sw          $t3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r11;
L_80386EB4:
    // 0x80386EB4: beql        $s3, $zero, L_80386EC8
    if (ctx->r19 == 0) {
        // 0x80386EB8: lw          $t6, 0x0($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X0);
            goto L_80386EC8;
    }
    goto skip_9;
    // 0x80386EB8: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    skip_9:
    // 0x80386EBC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80386EC0: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80386EC4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
L_80386EC8:
    // 0x80386EC8: lw          $t7, 0x4($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X4);
    // 0x80386ECC: sw          $t6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r14;
    // 0x80386ED0: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
L_80386ED4:
    // 0x80386ED4: addu        $s2, $s2, $s4
    ctx->r18 = ADD32(ctx->r18, ctx->r20);
L_80386ED8:
    // 0x80386ED8: lw          $a2, 0x70($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X70);
    // 0x80386EDC: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x80386EE0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80386EE4: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80386EE8: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80386EEC: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80386EF0: jal         0x80387154
    // 0x80386EF4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    func_ovl8_80387154(rdram, ctx);
        goto after_3;
    // 0x80386EF4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_3:
    // 0x80386EF8: b           L_80386F4C
    // 0x80386EFC: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
        goto L_80386F4C;
    // 0x80386EFC: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_80386F00:
    // 0x80386F00: beq         $s3, $zero, L_80386F10
    if (ctx->r19 == 0) {
        // 0x80386F04: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80386F10;
    }
    // 0x80386F04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80386F08: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80386F0C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80386F10:
    // 0x80386F10: ldc1        $f4, 0x0($s2)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r18, 0X0);
    // 0x80386F14: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x80386F18: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x80386F1C: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80386F20: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80386F24: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x80386F28: sw          $s7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r23;
    // 0x80386F2C: swc1        $f6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f6.u32l;
    // 0x80386F30: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80386F34: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x80386F38: sw          $fp, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r30;
    // 0x80386F3C: sw          $a3, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r7;
    // 0x80386F40: jal         0x80387154
    // 0x80386F44: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    func_ovl8_80387154(rdram, ctx);
        goto after_4;
    // 0x80386F44: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    after_4:
    // 0x80386F48: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
L_80386F4C:
    // 0x80386F4C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80386F50:
    // 0x80386F50: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x80386F54: bnel        $v1, $zero, L_80386C40
    if (ctx->r3 != 0) {
        // 0x80386F58: andi        $t7, $v1, 0x80
        ctx->r15 = ctx->r3 & 0X80;
            goto L_80386C40;
    }
    goto skip_10;
    // 0x80386F58: andi        $t7, $v1, 0x80
    ctx->r15 = ctx->r3 & 0X80;
    skip_10:
L_80386F5C:
    // 0x80386F5C: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x80386F60: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80386F64: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x80386F68: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x80386F6C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80386F70: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80386F74: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x80386F78: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80386F7C: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80386F80: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80386F84: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x80386F88: jr          $ra
    // 0x80386F8C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80386F8C: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}

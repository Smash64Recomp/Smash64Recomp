#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnPlayers1PBonusCheckFighterLocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801322C0: beq         $a0, $at, L_8013235C
    if (ctx->r4 == ctx->r1) {
        // 0x801322C4: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_8013235C;
    }
    // 0x801322C4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801322C8: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801322CC: beq         $a0, $at, L_80132338
    if (ctx->r4 == ctx->r1) {
        // 0x801322D0: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80132338;
    }
    // 0x801322D0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801322D4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801322D8: beq         $a0, $at, L_80132314
    if (ctx->r4 == ctx->r1) {
        // 0x801322DC: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80132314;
    }
    // 0x801322DC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801322E0: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x801322E4: bne         $a0, $at, L_80132380
    if (ctx->r4 != ctx->r1) {
        // 0x801322E8: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80132380;
    }
    // 0x801322E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801322EC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801322F0: lhu         $t6, 0x7720($t6)
    ctx->r14 = MEM_HU(ctx->r14, 0X7720);
    // 0x801322F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x801322F8: andi        $t7, $t6, 0x800
    ctx->r15 = ctx->r14 & 0X800;
    // 0x801322FC: beq         $t7, $zero, L_8013230C
    if (ctx->r15 == 0) {
        // 0x80132300: nop
    
            goto L_8013230C;
    }
    // 0x80132300: nop

    // 0x80132304: jr          $ra
    // 0x80132308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013230C:
    // 0x8013230C: jr          $ra
    // 0x80132310: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132310: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132314:
    // 0x80132314: lhu         $t8, 0x7720($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X7720);
    // 0x80132318: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8013231C: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x80132320: beq         $t9, $zero, L_80132330
    if (ctx->r25 == 0) {
        // 0x80132324: nop
    
            goto L_80132330;
    }
    // 0x80132324: nop

    // 0x80132328: jr          $ra
    // 0x8013232C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8013232C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132330:
    // 0x80132330: jr          $ra
    // 0x80132334: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132334: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132338:
    // 0x80132338: lhu         $t0, 0x7720($t0)
    ctx->r8 = MEM_HU(ctx->r8, 0X7720);
    // 0x8013233C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80132340: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x80132344: beq         $t1, $zero, L_80132354
    if (ctx->r9 == 0) {
        // 0x80132348: nop
    
            goto L_80132354;
    }
    // 0x80132348: nop

    // 0x8013234C: jr          $ra
    // 0x80132350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132350: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132354:
    // 0x80132354: jr          $ra
    // 0x80132358: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80132358: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013235C:
    // 0x8013235C: lhu         $t2, 0x7720($t2)
    ctx->r10 = MEM_HU(ctx->r10, 0X7720);
    // 0x80132360: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80132364: andi        $t3, $t2, 0x10
    ctx->r11 = ctx->r10 & 0X10;
    // 0x80132368: beq         $t3, $zero, L_80132378
    if (ctx->r11 == 0) {
        // 0x8013236C: nop
    
            goto L_80132378;
    }
    // 0x8013236C: nop

    // 0x80132370: jr          $ra
    // 0x80132374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80132374: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80132378:
    // 0x80132378: jr          $ra
    // 0x8013237C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8013237C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132380:
    // 0x80132380: jr          $ra
    // 0x80132384: nop

    return;
    // 0x80132384: nop

;}
RECOMP_FUNC void mnPlayers1PGameUpdateCursorNoRecall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136540: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80136544: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80136548: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8013654C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80136550: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80136554: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80136558: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8013655C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80136560: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80136564: lui         $at, 0x42F8
    ctx->r1 = S32(0X42F8 << 16);
    // 0x80136568: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013656C: lwc1        $f0, 0x5C($t6)
    ctx->f0.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x80136570: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x80136574: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80136578: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8013657C: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80136580: addiu       $s2, $s2, -0x7118
    ctx->r18 = ADD32(ctx->r18, -0X7118);
    // 0x80136584: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x80136588: bc1tl       L_801365AC
    if (c1cs) {
        // 0x8013658C: lw          $v0, 0x28($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X28);
            goto L_801365AC;
    }
    goto skip_0;
    // 0x8013658C: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
    skip_0:
    // 0x80136590: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80136594: nop

    // 0x80136598: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8013659C: nop

    // 0x801365A0: bc1f        L_801365D4
    if (!c1cs) {
        // 0x801365A4: nop
    
            goto L_801365D4;
    }
    // 0x801365A4: nop

    // 0x801365A8: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
L_801365AC:
    // 0x801365AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801365B0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x801365B4: beq         $v0, $zero, L_801365CC
    if (ctx->r2 == 0) {
        // 0x801365B8: nop
    
            goto L_801365CC;
    }
    // 0x801365B8: nop

    // 0x801365BC: jal         0x801352BC
    // 0x801365C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    mnPlayers1PGameUpdateCursor(rdram, ctx);
        goto after_0;
    // 0x801365C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x801365C4: sw          $zero, 0x28($s2)
    MEM_W(0X28, ctx->r18) = 0;
    // 0x801365C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801365CC:
    // 0x801365CC: b           L_8013663C
    // 0x801365D0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_8013663C;
    // 0x801365D0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_801365D4:
    // 0x801365D4: lui         $s2, 0x8014
    ctx->r18 = S32(0X8014 << 16);
    // 0x801365D8: addiu       $s2, $s2, -0x7118
    ctx->r18 = ADD32(ctx->r18, -0X7118);
    // 0x801365DC: lw          $t7, 0x54($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X54);
    // 0x801365E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x801365E4: bnel        $t7, $at, L_8013661C
    if (ctx->r15 != ctx->r1) {
        // 0x801365E8: lw          $v0, 0x28($s2)
        ctx->r2 = MEM_W(ctx->r18, 0X28);
            goto L_8013661C;
    }
    goto skip_1;
    // 0x801365E8: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
    skip_1:
    // 0x801365EC: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
    // 0x801365F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801365F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x801365F8: beq         $v0, $at, L_80136610
    if (ctx->r2 == ctx->r1) {
        // 0x801365FC: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_80136610;
    }
    // 0x801365FC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80136600: jal         0x801352BC
    // 0x80136604: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayers1PGameUpdateCursor(rdram, ctx);
        goto after_1;
    // 0x80136604: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x80136608: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8013660C: sw          $v0, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r2;
L_80136610:
    // 0x80136610: b           L_8013663C
    // 0x80136614: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
        goto L_8013663C;
    // 0x80136614: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80136618: lw          $v0, 0x28($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X28);
L_8013661C:
    // 0x8013661C: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x80136620: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80136624: beq         $s3, $v0, L_8013663C
    if (ctx->r19 == ctx->r2) {
        // 0x80136628: or          $a1, $s5, $zero
        ctx->r5 = ctx->r21 | 0;
            goto L_8013663C;
    }
    // 0x80136628: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8013662C: jal         0x801352BC
    // 0x80136630: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    mnPlayers1PGameUpdateCursor(rdram, ctx);
        goto after_2;
    // 0x80136630: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    after_2:
    // 0x80136634: sw          $s3, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r19;
    // 0x80136638: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
L_8013663C:
    // 0x8013663C: bnel        $v0, $zero, L_801366A4
    if (ctx->r2 != 0) {
        // 0x80136640: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801366A4;
    }
    goto skip_2;
    // 0x80136640: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_2:
    // 0x80136644: lw          $t9, 0x2C($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X2C);
    // 0x80136648: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8013664C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80136650: beql        $t9, $zero, L_801366A4
    if (ctx->r25 == 0) {
        // 0x80136654: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_801366A4;
    }
    goto skip_3;
    // 0x80136654: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_3:
    // 0x80136658: lw          $t0, 0x2C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X2C);
L_8013665C:
    // 0x8013665C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80136660: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80136664: bnel        $s3, $t0, L_80136698
    if (ctx->r19 != ctx->r8) {
        // 0x80136668: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80136698;
    }
    goto skip_4;
    // 0x80136668: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x8013666C: jal         0x80135724
    // 0x80136670: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    mnPlayers1PGameCheckPuckInRange(rdram, ctx);
        goto after_3;
    // 0x80136670: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_3:
    // 0x80136674: beq         $v0, $zero, L_80136694
    if (ctx->r2 == 0) {
        // 0x80136678: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80136694;
    }
    // 0x80136678: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8013667C: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x80136680: jal         0x801352BC
    // 0x80136684: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    mnPlayers1PGameUpdateCursor(rdram, ctx);
        goto after_4;
    // 0x80136684: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_4:
    // 0x80136688: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x8013668C: b           L_801366A0
    // 0x80136690: sw          $t1, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r9;
        goto L_801366A0;
    // 0x80136690: sw          $t1, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r9;
L_80136694:
    // 0x80136694: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80136698:
    // 0x80136698: bnel        $s0, $s1, L_8013665C
    if (ctx->r16 != ctx->r17) {
        // 0x8013669C: lw          $t0, 0x2C($s2)
        ctx->r8 = MEM_W(ctx->r18, 0X2C);
            goto L_8013665C;
    }
    goto skip_5;
    // 0x8013669C: lw          $t0, 0x2C($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X2C);
    skip_5:
L_801366A0:
    // 0x801366A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_801366A4:
    // 0x801366A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x801366A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x801366AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x801366B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x801366B4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x801366B8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x801366BC: jr          $ra
    // 0x801366C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801366C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void syMallocReset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006CE0: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80006CE4: jr          $ra
    // 0x80006CE8: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
    return;
    // 0x80006CE8: sw          $t6, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void ftBossYubideppou2SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A748: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015A74C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015A750: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015A754: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015A758: addiu       $a1, $zero, 0xF3
    ctx->r5 = ADD32(0, 0XF3);
    // 0x8015A75C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015A760: jal         0x800E6F24
    // 0x8015A764: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A764: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015A768: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8015A76C: addiu       $a0, $zero, 0x78
    ctx->r4 = ADD32(0, 0X78);
    // 0x8015A770: lw          $t7, 0x84($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X84);
    // 0x8015A774: jal         0x80018994
    // 0x8015A778: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x8015A778: sw          $t7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r15;
    after_1:
    // 0x8015A77C: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8015A780: addiu       $t8, $v0, 0x3C
    ctx->r24 = ADD32(ctx->r2, 0X3C);
    // 0x8015A784: sh          $t8, 0xB18($t9)
    MEM_H(0XB18, ctx->r25) = ctx->r24;
    // 0x8015A788: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015A78C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015A790: jr          $ra
    // 0x8015A794: nop

    return;
    // 0x8015A794: nop

;}
RECOMP_FUNC void func_ovl65_801910B0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801910B0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801910B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801910B8: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x801910BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801910C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801910C4: jal         0x8000B2B8
    // 0x801910C8: lw          $a0, 0x38D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38D0);
    gcResumeGObjProcessAll(rdram, ctx);
        goto after_0;
    // 0x801910C8: lw          $a0, 0x38D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X38D0);
    after_0:
    // 0x801910CC: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x801910D0: lw          $s0, 0x6724($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X6724);
    // 0x801910D4: addiu       $s1, $zero, 0x3FF
    ctx->r17 = ADD32(0, 0X3FF);
    // 0x801910D8: beql        $s0, $zero, L_80191104
    if (ctx->r16 == 0) {
        // 0x801910DC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80191104;
    }
    goto skip_0;
    // 0x801910DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801910E0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
L_801910E4:
    // 0x801910E4: bnel        $s1, $t6, L_801910F8
    if (ctx->r17 != ctx->r14) {
        // 0x801910E8: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_801910F8;
    }
    goto skip_1;
    // 0x801910E8: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x801910EC: jal         0x8000B2B8
    // 0x801910F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcResumeGObjProcessAll(rdram, ctx);
        goto after_1;
    // 0x801910F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801910F4: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_801910F8:
    // 0x801910F8: bnel        $s0, $zero, L_801910E4
    if (ctx->r16 != 0) {
        // 0x801910FC: lw          $t6, 0x0($s0)
        ctx->r14 = MEM_W(ctx->r16, 0X0);
            goto L_801910E4;
    }
    goto skip_2;
    // 0x801910FC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    skip_2:
    // 0x80191100: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80191104:
    // 0x80191104: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80191108: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8019110C: jr          $ra
    // 0x80191110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80191110: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ftMainCheckAddGroundObstacle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1D48: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E1D4C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E1D50: addiu       $v0, $v0, 0x1190
    ctx->r2 = ADD32(ctx->r2, 0X1190);
    // 0x800E1D54: addiu       $v1, $v1, 0x1180
    ctx->r3 = ADD32(ctx->r3, 0X1180);
    // 0x800E1D58: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_800E1D5C:
    // 0x800E1D5C: bne         $t6, $zero, L_800E1D84
    if (ctx->r14 != 0) {
        // 0x800E1D60: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_800E1D84;
    }
    // 0x800E1D60: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800E1D64: addiu       $a2, $a2, 0x1198
    ctx->r6 = ADD32(ctx->r6, 0X1198);
    // 0x800E1D68: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800E1D6C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800E1D70: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x800E1D74: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800E1D78: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800E1D7C: jr          $ra
    // 0x800E1D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E1D80: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E1D84:
    // 0x800E1D84: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E1D88: bnel        $v1, $v0, L_800E1D5C
    if (ctx->r3 != ctx->r2) {
        // 0x800E1D8C: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_800E1D5C;
    }
    goto skip_0;
    // 0x800E1D8C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x800E1D90: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E1D94: jr          $ra
    // 0x800E1D98: nop

    return;
    // 0x800E1D98: nop

;}
RECOMP_FUNC void efManagerDustHeavyDoubleMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FF3F4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FF3F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FF3FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800FF400: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800FF404: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800FF408: jal         0x800FD4B8
    // 0x800FF40C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FF40C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x800FF410: bne         $v0, $zero, L_800FF420
    if (ctx->r2 != 0) {
        // 0x800FF414: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800FF420;
    }
    // 0x800FF414: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800FF418: b           L_800FF57C
    // 0x800FF41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF57C;
    // 0x800FF41C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FF420:
    // 0x800FF420: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FF424: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FF428: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FF42C: jal         0x80009968
    // 0x800FF430: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FF430: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FF434: bne         $v0, $zero, L_800FF44C
    if (ctx->r2 != 0) {
        // 0x800FF438: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_800FF44C;
    }
    // 0x800FF438: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800FF43C: jal         0x800FD4F8
    // 0x800FF440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FF440: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800FF444: b           L_800FF57C
    // 0x800FF448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FF57C;
    // 0x800FF448: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FF44C:
    // 0x800FF44C: sw          $s0, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r16;
    // 0x800FF450: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF454: lwc1        $f6, 0x98C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X98C);
    // 0x800FF458: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800FF45C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FF460: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x800FF464: nop

    // 0x800FF468: bc1f        L_800FF48C
    if (!c1cs) {
        // 0x800FF46C: nop
    
            goto L_800FF48C;
    }
    // 0x800FF46C: nop

    // 0x800FF470: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FF474: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FF478: addiu       $a1, $zero, 0x59
    ctx->r5 = ADD32(0, 0X59);
    // 0x800FF47C: jal         0x800CE9E8
    // 0x800FF480: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FF480: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_3:
    // 0x800FF484: b           L_800FF4A0
    // 0x800FF488: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_800FF4A0;
    // 0x800FF488: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_800FF48C:
    // 0x800FF48C: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FF490: addiu       $a1, $zero, 0x58
    ctx->r5 = ADD32(0, 0X58);
    // 0x800FF494: jal         0x800CE9E8
    // 0x800FF498: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_4;
    // 0x800FF498: ori         $a0, $a0, 0x8
    ctx->r4 = ctx->r4 | 0X8;
    after_4:
    // 0x800FF49C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_800FF4A0:
    // 0x800FF4A0: beq         $v0, $zero, L_800FF570
    if (ctx->r2 == 0) {
        // 0x800FF4A4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800FF570;
    }
    // 0x800FF4A4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FF4A8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800FF4AC: jal         0x800CE1DC
    // 0x800FF4B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_5;
    // 0x800FF4B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x800FF4B4: beq         $v0, $zero, L_800FF560
    if (ctx->r2 == 0) {
        // 0x800FF4B8: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800FF560;
    }
    // 0x800FF4B8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800FF4BC: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FF4C0: addiu       $a1, $a1, -0xC7C
    ctx->r5 = ADD32(ctx->r5, -0XC7C);
    // 0x800FF4C4: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800FF4C8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FF4CC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800FF4D0: jal         0x80008188
    // 0x800FF4D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800FF4D4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_6:
    // 0x800FF4D8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FF4DC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800FF4E0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800FF4E4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800FF4E8: sw          $t6, 0xBC($v1)
    MEM_W(0XBC, ctx->r3) = ctx->r14;
    // 0x800FF4EC: sw          $v1, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r3;
    // 0x800FF4F0: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800FF4F4: lui         $at, 0x42FC
    ctx->r1 = S32(0X42FC << 16);
    // 0x800FF4F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FF4FC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800FF500: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800FF504: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800FF508: lui         $t1, 0x8010
    ctx->r9 = S32(0X8010 << 16);
    // 0x800FF50C: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800FF510: lwc1        $f8, 0x8($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X8);
    // 0x800FF514: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800FF518: addiu       $t1, $t1, -0x2478
    ctx->r9 = ADD32(ctx->r9, -0X2478);
    // 0x800FF51C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FF520: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x800FF524: swc1        $f16, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f16.u32l;
    // 0x800FF528: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800FF52C: sw          $t0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r8;
    // 0x800FF530: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800FF534: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
    // 0x800FF538: lw          $t0, 0x8($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X8);
    // 0x800FF53C: sw          $zero, 0x28($s0)
    MEM_W(0X28, ctx->r16) = 0;
    // 0x800FF540: sw          $a1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r5;
    // 0x800FF544: bne         $a1, $at, L_800FF558
    if (ctx->r5 != ctx->r1) {
        // 0x800FF548: sw          $t0, 0x20($s0)
        MEM_W(0X20, ctx->r16) = ctx->r8;
            goto L_800FF558;
    }
    // 0x800FF548: sw          $t0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r8;
    // 0x800FF54C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FF550: lwc1        $f18, 0x990($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X990);
    // 0x800FF554: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
L_800FF558:
    // 0x800FF558: b           L_800FF578
    // 0x800FF55C: sw          $t1, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r9;
        goto L_800FF578;
    // 0x800FF55C: sw          $t1, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r9;
L_800FF560:
    // 0x800FF560: jal         0x800FDB3C
    // 0x800FF564: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_7;
    // 0x800FF564: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_7:
    // 0x800FF568: b           L_800FF578
    // 0x800FF56C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_800FF578;
    // 0x800FF56C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_800FF570:
    // 0x800FF570: jal         0x800FDB3C
    // 0x800FF574: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_8;
    // 0x800FF574: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_8:
L_800FF578:
    // 0x800FF578: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_800FF57C:
    // 0x800FF57C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FF580: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800FF584: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800FF588: jr          $ra
    // 0x800FF58C: nop

    return;
    // 0x800FF58C: nop

;}
RECOMP_FUNC void ftCommonHeavyThrowCheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80146BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146BE8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80146BEC: lw          $t6, 0x84C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84C);
    // 0x80146BF0: beql        $t6, $zero, L_80146C28
    if (ctx->r14 == 0) {
        // 0x80146BF4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80146C28;
    }
    goto skip_0;
    // 0x80146BF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80146BF8: lhu         $t7, 0x1B4($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X1B4);
    // 0x80146BFC: lhu         $t8, 0x1B6($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1B6);
    // 0x80146C00: lhu         $t0, 0x1BE($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X1BE);
    // 0x80146C04: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80146C08: and         $t1, $t0, $t9
    ctx->r9 = ctx->r8 & ctx->r25;
    // 0x80146C0C: beql        $t1, $zero, L_80146C28
    if (ctx->r9 == 0) {
        // 0x80146C10: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80146C28;
    }
    goto skip_1;
    // 0x80146C10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x80146C14: jal         0x80146930
    // 0x80146C18: nop

    ftCommonHeavyThrowDecideSetStatus(rdram, ctx);
        goto after_0;
    // 0x80146C18: nop

    after_0:
    // 0x80146C1C: b           L_80146C28
    // 0x80146C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80146C28;
    // 0x80146C20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80146C24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80146C28:
    // 0x80146C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80146C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80146C30: jr          $ra
    // 0x80146C34: nop

    return;
    // 0x80146C34: nop

;}
RECOMP_FUNC void mvOpeningNewcomersStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801325E0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x801325E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801325E8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801325EC: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x801325F0: addiu       $a0, $a0, 0x2678
    ctx->r4 = ADD32(ctx->r4, 0X2678);
    // 0x801325F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801325F8: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x801325FC: jal         0x80007024
    // 0x80132600: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132600: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132604: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132608: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x8013260C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132610: addiu       $t9, $t9, 0x2920
    ctx->r25 = ADD32(ctx->r25, 0X2920);
    // 0x80132614: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80132618: addiu       $a0, $a0, 0x2694
    ctx->r4 = ADD32(ctx->r4, 0X2694);
    // 0x8013261C: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132620: jal         0x8000683C
    // 0x80132624: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80132624: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80132628: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013262C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132630: jr          $ra
    // 0x80132634: nop

    return;
    // 0x80132634: nop

;}
RECOMP_FUNC void mvOpeningNewcomersFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131B08: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B0C: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x80131B10: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x80131B14: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80131B18: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80131B1C: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x80131B20: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80131B24: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80131B28: jal         0x8039051C
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    scSubsysFighterGetLightAngleX(rdram, ctx);
        goto after_0;
    // 0x80131B2C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131B30: jal         0x80390528
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    scSubsysFighterGetLightAngleY(rdram, ctx);
        goto after_1;
    // 0x80131B34: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x80131B38: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80131B3C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80131B40: jal         0x800FCB70
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_2;
    // 0x80131B44: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x80131B48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131B4C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131B50: jr          $ra
    // 0x80131B54: nop

    return;
    // 0x80131B54: nop

;}
RECOMP_FUNC void syDmaWriteSram(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002DE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80002DE4: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
    // 0x80002DE8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80002DEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80002DF0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002DF4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x80002DF8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80002DFC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80002E00: jal         0x80002A90
    // 0x80002E04: addiu       $a0, $a0, 0x5048
    ctx->r4 = ADD32(ctx->r4, 0X5048);
    syDmaCopy(rdram, ctx);
        goto after_0;
    // 0x80002E04: addiu       $a0, $a0, 0x5048
    ctx->r4 = ADD32(ctx->r4, 0X5048);
    after_0:
    // 0x80002E08: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80002E0C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80002E10: jr          $ra
    // 0x80002E14: nop

    return;
    // 0x80002E14: nop

;}
RECOMP_FUNC void grPupupuWhispySetWindPush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010595C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80105960: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80105964: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x80105968: lw          $s0, 0x66FC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X66FC);
    // 0x8010596C: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80105970: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x80105974: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80105978: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x8010597C: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80105980: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80105984: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80105988: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8010598C: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80105990: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80105994: beq         $s0, $zero, L_80105AC0
    if (ctx->r16 == 0) {
        // 0x80105998: lb          $s1, 0x141A($s1)
        ctx->r17 = MEM_B(ctx->r17, 0X141A);
            goto L_80105AC0;
    }
    // 0x80105998: lb          $s1, 0x141A($s1)
    ctx->r17 = MEM_B(ctx->r17, 0X141A);
    // 0x8010599C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801059A0: lwc1        $f30, 0xA94($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0XA94);
    // 0x801059A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801059A8: lwc1        $f28, 0xA98($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0XA98);
    // 0x801059AC: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x801059B0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801059B4: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801059B8: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x801059BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801059C0: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x801059C4: lwc1        $f20, 0xA9C($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0XA9C);
    // 0x801059C8: addiu       $s2, $sp, 0x60
    ctx->r18 = ADD32(ctx->r29, 0X60);
    // 0x801059CC: lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84);
L_801059D0:
    // 0x801059D0: lw          $v0, 0x8E8($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X8E8);
    // 0x801059D4: lwc1        $f2, 0x20($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801059D8: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x801059DC: c.le.s      $f2, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f2.fl <= ctx->f24.fl;
    // 0x801059E0: nop

    // 0x801059E4: bc1fl       L_80105AB8
    if (!c1cs) {
        // 0x801059E8: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80105AB8;
    }
    goto skip_0;
    // 0x801059E8: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_0:
    // 0x801059EC: c.le.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl <= ctx->f2.fl;
    // 0x801059F0: nop

    // 0x801059F4: bc1fl       L_80105AB8
    if (!c1cs) {
        // 0x801059F8: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80105AB8;
    }
    goto skip_1;
    // 0x801059F8: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_1:
    // 0x801059FC: bne         $s1, $zero, L_80105A24
    if (ctx->r17 != 0) {
        // 0x80105A00: nop
    
            goto L_80105A24;
    }
    // 0x80105A00: nop

    // 0x80105A04: c.le.s      $f28, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f28.fl <= ctx->f0.fl;
    // 0x80105A08: nop

    // 0x80105A0C: bc1f        L_80105A24
    if (!c1cs) {
        // 0x80105A10: nop
    
            goto L_80105A24;
    }
    // 0x80105A10: nop

    // 0x80105A14: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x80105A18: nop

    // 0x80105A1C: bc1tl       L_80105A50
    if (c1cs) {
        // 0x80105A20: c.lt.s      $f0, $f20
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
            goto L_80105A50;
    }
    goto skip_2;
    // 0x80105A20: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    skip_2:
L_80105A24:
    // 0x80105A24: beql        $s1, $zero, L_80105AB8
    if (ctx->r17 == 0) {
        // 0x80105A28: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80105AB8;
    }
    goto skip_3;
    // 0x80105A28: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_3:
    // 0x80105A2C: c.le.s      $f0, $f30
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    c1cs = ctx->f0.fl <= ctx->f30.fl;
    // 0x80105A30: nop

    // 0x80105A34: bc1fl       L_80105AB8
    if (!c1cs) {
        // 0x80105A38: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80105AB8;
    }
    goto skip_4;
    // 0x80105A38: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_4:
    // 0x80105A3C: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x80105A40: nop

    // 0x80105A44: bc1fl       L_80105AB8
    if (!c1cs) {
        // 0x80105A48: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80105AB8;
    }
    goto skip_5;
    // 0x80105A48: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_5:
    // 0x80105A4C: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
L_80105A50:
    // 0x80105A50: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80105A54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80105A58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80105A5C: bc1f        L_80105A70
    if (!c1cs) {
        // 0x80105A60: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80105A70;
    }
    // 0x80105A60: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80105A64: sub.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x80105A68: b           L_80105A74
    // 0x80105A6C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
        goto L_80105A74;
    // 0x80105A6C: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80105A70:
    // 0x80105A70: sub.s       $f2, $f0, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f20.fl;
L_80105A74:
    // 0x80105A74: lwc1        $f6, 0xAA0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XAA0);
    // 0x80105A78: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x80105A7C: sub.s       $f0, $f4, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x80105A80: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    // 0x80105A84: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
    // 0x80105A88: bc1fl       L_80105AB8
    if (!c1cs) {
        // 0x80105A8C: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80105AB8;
    }
    goto skip_6;
    // 0x80105A8C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_6:
    // 0x80105A90: swc1        $f22, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f22.u32l;
    // 0x80105A94: bne         $s1, $zero, L_80105AA8
    if (ctx->r17 != 0) {
        // 0x80105A98: swc1        $f22, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->f22.u32l;
            goto L_80105AA8;
    }
    // 0x80105A98: swc1        $f22, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f22.u32l;
    // 0x80105A9C: neg.s       $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = -ctx->f0.fl;
    // 0x80105AA0: b           L_80105AAC
    // 0x80105AA4: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
        goto L_80105AAC;
    // 0x80105AA4: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
L_80105AA8:
    // 0x80105AA8: swc1        $f0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->f0.u32l;
L_80105AAC:
    // 0x80105AAC: jal         0x800E86B4
    // 0x80105AB0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftParamSetVelPush(rdram, ctx);
        goto after_0;
    // 0x80105AB0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x80105AB4: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80105AB8:
    // 0x80105AB8: bnel        $s0, $zero, L_801059D0
    if (ctx->r16 != 0) {
        // 0x80105ABC: lw          $v1, 0x84($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X84);
            goto L_801059D0;
    }
    goto skip_7;
    // 0x80105ABC: lw          $v1, 0x84($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X84);
    skip_7:
L_80105AC0:
    // 0x80105AC0: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x80105AC4: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80105AC8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80105ACC: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80105AD0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80105AD4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80105AD8: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80105ADC: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80105AE0: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80105AE4: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80105AE8: jr          $ra
    // 0x80105AEC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80105AEC: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void ifCommonPlayerStockSingleMakeInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010FFA8: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8010FFAC: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8010FFB0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8010FFB4: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8010FFB8: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010FFBC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8010FFC0: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8010FFC4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8010FFC8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010FFCC: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8010FFD0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8010FFD4: lw          $t1, 0x78($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X78);
    // 0x8010FFD8: lw          $t0, 0x84($t1)
    ctx->r8 = MEM_W(ctx->r9, 0X84);
    // 0x8010FFDC: lw          $t2, 0x9C8($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X9C8);
    // 0x8010FFE0: lw          $v0, 0x340($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X340);
    // 0x8010FFE4: beql        $v0, $zero, L_8011012C
    if (ctx->r2 == 0) {
        // 0x8010FFE8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8011012C;
    }
    goto skip_0;
    // 0x8010FFE8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8010FFEC: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8010FFF0: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8010FFF4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010FFF8: beq         $t3, $zero, L_80110128
    if (ctx->r11 == 0) {
        // 0x8010FFFC: addiu       $a2, $zero, 0xB
        ctx->r6 = ADD32(0, 0XB);
            goto L_80110128;
    }
    // 0x8010FFFC: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80110000: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80110004: jal         0x80009968
    // 0x80110008: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80110008: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_0:
    // 0x8011000C: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x80110010: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80110014: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80110018: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x8011001C: addu        $at, $at, $v1
    ctx->r1 = ADD32(ctx->r1, ctx->r3);
    // 0x80110020: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80110024: sw          $v0, 0x17D0($at)
    MEM_W(0X17D0, ctx->r1) = ctx->r2;
    // 0x80110028: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x8011002C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80110030: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x80110034: addiu       $a1, $a1, -0xDC
    ctx->r5 = ADD32(ctx->r5, -0XDC);
    // 0x80110038: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8011003C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80110040: jal         0x80009DF4
    // 0x80110044: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80110044: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80110048: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8011004C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80110050: lw          $t5, 0x9C8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X9C8);
    // 0x80110054: lw          $t7, 0x340($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X340);
    // 0x80110058: jal         0x800CCFDC
    // 0x8011005C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x8011005C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    after_2:
    // 0x80110060: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80110064: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80110068: addiu       $t6, $zero, 0x201
    ctx->r14 = ADD32(0, 0X201);
    // 0x8011006C: sh          $t6, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r14;
    // 0x80110070: lw          $t8, 0x9C8($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X9C8);
    // 0x80110074: lbu         $t2, 0x10($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X10);
    // 0x80110078: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8011007C: lw          $t9, 0x340($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X340);
    // 0x80110080: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80110084: addiu       $a0, $a0, 0x1580
    ctx->r4 = ADD32(ctx->r4, 0X1580);
    // 0x80110088: lw          $t1, 0x4($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X4);
    // 0x8011008C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80110090: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80110094: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x80110098: lh          $t1, 0x14($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X14);
    // 0x8011009C: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x801100A0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801100A4: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x801100A8: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    // 0x801100AC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x801100B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801100B4: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x801100B8: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x801100BC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801100C0: lh          $t8, 0x16($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X16);
    // 0x801100C4: lw          $t7, -0x1378($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1378);
    // 0x801100C8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801100CC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x801100D0: addu        $t2, $t7, $t9
    ctx->r10 = ADD32(ctx->r15, ctx->r25);
    // 0x801100D4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x801100D8: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801100DC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801100E0: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x801100E4: nop

    // 0x801100E8: subu        $t5, $t2, $t4
    ctx->r13 = SUB32(ctx->r10, ctx->r12);
    // 0x801100EC: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x801100F0: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x801100F4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801100F8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x801100FC: swc1        $f18, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f18.u32l;
    // 0x80110100: lhu         $t6, 0xC($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XC);
    // 0x80110104: subu        $t1, $t6, $t9
    ctx->r9 = SUB32(ctx->r14, ctx->r25);
    // 0x80110108: addiu       $t3, $t1, -0x14
    ctx->r11 = ADD32(ctx->r9, -0X14);
    // 0x8011010C: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80110110: nop

    // 0x80110114: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80110118: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x8011011C: lw          $t4, 0x28($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X28);
    // 0x80110120: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x80110124: sw          $t2, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->r10;
L_80110128:
    // 0x80110128: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8011012C:
    // 0x8011012C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80110130: jr          $ra
    // 0x80110134: nop

    return;
    // 0x80110134: nop

;}
RECOMP_FUNC void sc1PIntroInitFighters(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134190: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80134194: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80134198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013419C: beq         $a0, $at, L_80134298
    if (ctx->r4 == ctx->r1) {
        // 0x801341A0: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_80134298;
    }
    // 0x801341A0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801341A4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x801341A8: bne         $a0, $at, L_80134338
    if (ctx->r4 != ctx->r1) {
        // 0x801341AC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80134338;
    }
    // 0x801341AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801341B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801341B4: lw          $a0, 0x5CE8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CE8);
    // 0x801341B8: jal         0x80133F90
    // 0x801341BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    sc1PIntroMakeFighterCamera(rdram, ctx);
        goto after_0;
    // 0x801341BC: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    after_0:
    // 0x801341C0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801341C4: addiu       $t7, $t7, 0x5CE8
    ctx->r15 = ADD32(ctx->r15, 0X5CE8);
    // 0x801341C8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801341CC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801341D0: addiu       $t0, $t0, 0x5C40
    ctx->r8 = ADD32(ctx->r8, 0X5C40);
    // 0x801341D4: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x801341D8: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    // 0x801341DC: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801341E0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x801341E4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801341E8: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    // 0x801341EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x801341F0: jal         0x80132C98
    // 0x801341F4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    sc1PIntroMakeFighter(rdram, ctx);
        goto after_1;
    // 0x801341F4: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_1:
    // 0x801341F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801341FC: lw          $a0, 0x5CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CD8);
    // 0x80134200: jal         0x80133F90
    // 0x80134204: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sc1PIntroMakeFighterCamera(rdram, ctx);
        goto after_2;
    // 0x80134204: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_2:
    // 0x80134208: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x8013420C: addiu       $t1, $t1, 0x5CD8
    ctx->r9 = ADD32(ctx->r9, 0X5CD8);
    // 0x80134210: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80134214: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80134218: addiu       $t4, $t4, 0x5C3C
    ctx->r12 = ADD32(ctx->r12, 0X5C3C);
    // 0x8013421C: sw          $t3, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r11;
    // 0x80134220: lw          $a1, 0x4($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X4);
    // 0x80134224: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80134228: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8013422C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80134230: lw          $a2, 0x8($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X8);
    // 0x80134234: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80134238: jal         0x80132C98
    // 0x8013423C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    sc1PIntroMakeFighter(rdram, ctx);
        goto after_3;
    // 0x8013423C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_3:
    // 0x80134240: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134244: lw          $a0, 0x5CC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CC8);
    // 0x80134248: jal         0x80133F90
    // 0x8013424C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    sc1PIntroMakeFighterCamera(rdram, ctx);
        goto after_4;
    // 0x8013424C: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x80134250: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80134254: addiu       $t5, $t5, 0x5CC8
    ctx->r13 = ADD32(ctx->r13, 0X5CC8);
    // 0x80134258: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8013425C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80134260: addiu       $t8, $t8, 0x5C38
    ctx->r24 = ADD32(ctx->r24, 0X5C38);
    // 0x80134264: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x80134268: lw          $a1, 0x4($t5)
    ctx->r5 = MEM_W(ctx->r13, 0X4);
    // 0x8013426C: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80134270: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80134274: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80134278: lw          $a2, 0x8($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X8);
    // 0x8013427C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80134280: jal         0x80132C98
    // 0x80134284: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    sc1PIntroMakeFighter(rdram, ctx);
        goto after_5;
    // 0x80134284: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_5:
    // 0x80134288: jal         0x80132E2C
    // 0x8013428C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    sc1PIntroMakeAllyText(rdram, ctx);
        goto after_6;
    // 0x8013428C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_6:
    // 0x80134290: b           L_80134380
    // 0x80134294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80134380;
    // 0x80134294: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134298:
    // 0x80134298: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013429C: lw          $a0, 0x5CD8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CD8);
    // 0x801342A0: jal         0x80133F90
    // 0x801342A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    sc1PIntroMakeFighterCamera(rdram, ctx);
        goto after_7;
    // 0x801342A4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_7:
    // 0x801342A8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801342AC: addiu       $t9, $t9, 0x5CD8
    ctx->r25 = ADD32(ctx->r25, 0X5CD8);
    // 0x801342B0: lw          $t1, 0x0($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X0);
    // 0x801342B4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x801342B8: addiu       $t2, $t2, 0x5C3C
    ctx->r10 = ADD32(ctx->r10, 0X5C3C);
    // 0x801342BC: sw          $t1, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r9;
    // 0x801342C0: lw          $a1, 0x4($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X4);
    // 0x801342C4: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x801342C8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x801342CC: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x801342D0: lw          $a2, 0x8($t9)
    ctx->r6 = MEM_W(ctx->r25, 0X8);
    // 0x801342D4: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x801342D8: jal         0x80132C98
    // 0x801342DC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    sc1PIntroMakeFighter(rdram, ctx);
        goto after_8;
    // 0x801342DC: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_8:
    // 0x801342E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801342E4: lw          $a0, 0x5CC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CC8);
    // 0x801342E8: jal         0x80133F90
    // 0x801342EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    sc1PIntroMakeFighterCamera(rdram, ctx);
        goto after_9;
    // 0x801342EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x801342F0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801342F4: addiu       $t3, $t3, 0x5CC8
    ctx->r11 = ADD32(ctx->r11, 0X5CC8);
    // 0x801342F8: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    // 0x801342FC: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80134300: addiu       $t6, $t6, 0x5C38
    ctx->r14 = ADD32(ctx->r14, 0X5C38);
    // 0x80134304: sw          $t5, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r13;
    // 0x80134308: lw          $a1, 0x4($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X4);
    // 0x8013430C: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80134310: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80134314: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80134318: lw          $a2, 0x8($t3)
    ctx->r6 = MEM_W(ctx->r11, 0X8);
    // 0x8013431C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134320: jal         0x80132C98
    // 0x80134324: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    sc1PIntroMakeFighter(rdram, ctx);
        goto after_10;
    // 0x80134324: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_10:
    // 0x80134328: jal         0x80132E2C
    // 0x8013432C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    sc1PIntroMakeAllyText(rdram, ctx);
        goto after_11;
    // 0x8013432C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_11:
    // 0x80134330: b           L_80134380
    // 0x80134334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80134380;
    // 0x80134334: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134338:
    // 0x80134338: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013433C: jal         0x80133F90
    // 0x80134340: lw          $a0, 0x5CC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CC8);
    sc1PIntroMakeFighterCamera(rdram, ctx);
        goto after_12;
    // 0x80134340: lw          $a0, 0x5CC8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5CC8);
    after_12:
    // 0x80134344: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80134348: addiu       $t7, $t7, 0x5CC8
    ctx->r15 = ADD32(ctx->r15, 0X5CC8);
    // 0x8013434C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134350: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80134354: addiu       $t0, $t0, 0x5C38
    ctx->r8 = ADD32(ctx->r8, 0X5C38);
    // 0x80134358: sw          $t9, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r25;
    // 0x8013435C: lw          $a1, 0x4($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X4);
    // 0x80134360: lw          $a0, 0x0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X0);
    // 0x80134364: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80134368: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8013436C: lw          $a2, 0x8($t7)
    ctx->r6 = MEM_W(ctx->r15, 0X8);
    // 0x80134370: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80134374: jal         0x80132C98
    // 0x80134378: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    sc1PIntroMakeFighter(rdram, ctx);
        goto after_13;
    // 0x80134378: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    after_13:
    // 0x8013437C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134380:
    // 0x80134380: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80134384: jr          $ra
    // 0x80134388: nop

    return;
    // 0x80134388: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingUpdateCursorPlacementPriorities(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134A4C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80134A50: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134A54: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80134A58: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80134A5C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80134A60: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80134A64: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80134A68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80134A6C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80134A70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134A74: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x80134A78: addiu       $t7, $t7, -0x7CA0
    ctx->r15 = ADD32(ctx->r15, -0X7CA0);
    // 0x80134A7C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134A80: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80134A84: addiu       $t6, $sp, 0x70
    ctx->r14 = ADD32(ctx->r29, 0X70);
    // 0x80134A88: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80134A8C: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80134A90: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80134A94: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80134A98: lui         $t1, 0x8014
    ctx->r9 = S32(0X8014 << 16);
    // 0x80134A9C: addiu       $t1, $t1, -0x7C90
    ctx->r9 = ADD32(ctx->r9, -0X7C90);
    // 0x80134AA0: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80134AA4: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80134AA8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80134AAC: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80134AB0: addiu       $t0, $sp, 0x60
    ctx->r8 = ADD32(ctx->r29, 0X60);
    // 0x80134AB4: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80134AB8: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80134ABC: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80134AC0: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80134AC4: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x80134AC8: lui         $s1, 0x8014
    ctx->r17 = S32(0X8014 << 16);
    // 0x80134ACC: addiu       $s1, $s1, -0x7AA8
    ctx->r17 = ADD32(ctx->r17, -0X7AA8);
    // 0x80134AD0: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80134AD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80134AD8: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x80134ADC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80134AE0: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80134AE4: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
L_80134AE8:
    // 0x80134AE8: lw          $t4, 0x7C($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X7C);
    // 0x80134AEC: bnel        $v1, $t4, L_80134B00
    if (ctx->r3 != ctx->r12) {
        // 0x80134AF0: sw          $a1, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r5;
            goto L_80134B00;
    }
    goto skip_0;
    // 0x80134AF0: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    skip_0:
    // 0x80134AF4: b           L_80134B00
    // 0x80134AF8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_80134B00;
    // 0x80134AF8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80134AFC: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_80134B00:
    // 0x80134B00: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80134B04: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x80134B08: bne         $at, $zero, L_80134AE8
    if (ctx->r1 != 0) {
        // 0x80134B0C: addiu       $s1, $s1, 0xB8
        ctx->r17 = ADD32(ctx->r17, 0XB8);
            goto L_80134AE8;
    }
    // 0x80134B0C: addiu       $s1, $s1, 0xB8
    ctx->r17 = ADD32(ctx->r17, 0XB8);
    // 0x80134B10: lui         $s3, 0x8014
    ctx->r19 = S32(0X8014 << 16);
    // 0x80134B14: addiu       $s3, $s3, -0x7AA8
    ctx->r19 = ADD32(ctx->r19, -0X7AA8);
    // 0x80134B18: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80134B1C: addiu       $s2, $sp, 0x6C
    ctx->r18 = ADD32(ctx->r29, 0X6C);
    // 0x80134B20: addiu       $s5, $sp, 0x48
    ctx->r21 = ADD32(ctx->r29, 0X48);
    // 0x80134B24: addiu       $s4, $zero, 0xB8
    ctx->r20 = ADD32(0, 0XB8);
L_80134B28:
    // 0x80134B28: beq         $s0, $s6, L_80134B8C
    if (ctx->r16 == ctx->r22) {
        // 0x80134B2C: sll         $t5, $s0, 2
        ctx->r13 = S32(ctx->r16 << 2);
            goto L_80134B8C;
    }
    // 0x80134B2C: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80134B30: addu        $t6, $s5, $t5
    ctx->r14 = ADD32(ctx->r21, ctx->r13);
    // 0x80134B34: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80134B38: beql        $t7, $zero, L_80134B90
    if (ctx->r15 == 0) {
        // 0x80134B3C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80134B90;
    }
    goto skip_1;
    // 0x80134B3C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_1:
    // 0x80134B40: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134B44: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80134B48: mflo        $t8
    ctx->r24 = lo;
    // 0x80134B4C: addu        $s1, $s3, $t8
    ctx->r17 = ADD32(ctx->r19, ctx->r24);
    // 0x80134B50: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x80134B54: beql        $a0, $zero, L_80134B68
    if (ctx->r4 == 0) {
        // 0x80134B58: lw          $t9, 0x7C($s1)
        ctx->r25 = MEM_W(ctx->r17, 0X7C);
            goto L_80134B68;
    }
    goto skip_2;
    // 0x80134B58: lw          $t9, 0x7C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X7C);
    skip_2:
    // 0x80134B5C: jal         0x8000A0D0
    // 0x80134B60: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    gcMoveGObjDL(rdram, ctx);
        goto after_0;
    // 0x80134B60: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    after_0:
    // 0x80134B64: lw          $t9, 0x7C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X7C);
L_80134B68:
    // 0x80134B68: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80134B6C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80134B70: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134B74: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80134B78: mflo        $t0
    ctx->r8 = lo;
    // 0x80134B7C: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x80134B80: jal         0x8000A0D0
    // 0x80134B84: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    gcMoveGObjDL(rdram, ctx);
        goto after_1;
    // 0x80134B84: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    after_1:
    // 0x80134B88: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
L_80134B8C:
    // 0x80134B8C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80134B90:
    // 0x80134B90: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80134B94: bne         $at, $zero, L_80134B28
    if (ctx->r1 != 0) {
        // 0x80134B98: nop
    
            goto L_80134B28;
    }
    // 0x80134B98: nop

    // 0x80134B9C: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x80134BA0: beql        $s6, $s1, L_80134BC8
    if (ctx->r22 == ctx->r17) {
        // 0x80134BA4: lw          $t4, 0x84($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X84);
            goto L_80134BC8;
    }
    goto skip_3;
    // 0x80134BA4: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
    skip_3:
    // 0x80134BA8: multu       $s6, $s4
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134BAC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80134BB0: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80134BB4: mflo        $t2
    ctx->r10 = lo;
    // 0x80134BB8: addu        $t3, $s3, $t2
    ctx->r11 = ADD32(ctx->r19, ctx->r10);
    // 0x80134BBC: jal         0x8000A0D0
    // 0x80134BC0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    gcMoveGObjDL(rdram, ctx);
        goto after_2;
    // 0x80134BC0: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    after_2:
    // 0x80134BC4: lw          $t4, 0x84($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X84);
L_80134BC8:
    // 0x80134BC8: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80134BCC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    // 0x80134BD0: multu       $t4, $s4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134BD4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80134BD8: mflo        $t5
    ctx->r13 = lo;
    // 0x80134BDC: addu        $t6, $s3, $t5
    ctx->r14 = ADD32(ctx->r19, ctx->r13);
    // 0x80134BE0: jal         0x8000A0D0
    // 0x80134BE4: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x80134BE4: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    after_3:
    // 0x80134BE8: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x80134BEC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80134BF0:
    // 0x80134BF0: beq         $s0, $s6, L_80134C30
    if (ctx->r16 == ctx->r22) {
        // 0x80134BF4: sll         $t7, $s0, 2
        ctx->r15 = S32(ctx->r16 << 2);
            goto L_80134C30;
    }
    // 0x80134BF4: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x80134BF8: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x80134BFC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80134C00: bnel        $t9, $zero, L_80134C34
    if (ctx->r25 != 0) {
        // 0x80134C04: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80134C34;
    }
    goto skip_4;
    // 0x80134C04: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_4:
    // 0x80134C08: multu       $s0, $s4
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134C0C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80134C10: mflo        $t0
    ctx->r8 = lo;
    // 0x80134C14: addu        $t1, $s3, $t0
    ctx->r9 = ADD32(ctx->r19, ctx->r8);
    // 0x80134C18: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80134C1C: beql        $a0, $zero, L_80134C30
    if (ctx->r4 == 0) {
        // 0x80134C20: addiu       $s2, $s2, -0x4
        ctx->r18 = ADD32(ctx->r18, -0X4);
            goto L_80134C30;
    }
    goto skip_5;
    // 0x80134C20: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    skip_5:
    // 0x80134C24: jal         0x8000A0D0
    // 0x80134C28: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    gcMoveGObjDL(rdram, ctx);
        goto after_4;
    // 0x80134C28: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    after_4:
    // 0x80134C2C: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
L_80134C30:
    // 0x80134C30: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80134C34:
    // 0x80134C34: bne         $s0, $s1, L_80134BF0
    if (ctx->r16 != ctx->r17) {
        // 0x80134C38: nop
    
            goto L_80134BF0;
    }
    // 0x80134C38: nop

    // 0x80134C3C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80134C40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134C44: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80134C48: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80134C4C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80134C50: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80134C54: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80134C58: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80134C5C: jr          $ra
    // 0x80134C60: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80134C60: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void ftCommonDokanStartProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80142080: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80142084: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80142088: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014208C: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80142090: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x80142094: lw          $t6, 0xB18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XB18);
    // 0x80142098: addiu       $a0, $zero, 0xB
    ctx->r4 = ADD32(0, 0XB);
    // 0x8014209C: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x801420A0: bne         $t6, $at, L_801420B0
    if (ctx->r14 != ctx->r1) {
        // 0x801420A4: addiu       $v1, $v1, 0x1C
        ctx->r3 = ADD32(ctx->r3, 0X1C);
            goto L_801420B0;
    }
    // 0x801420A4: addiu       $v1, $v1, 0x1C
    ctx->r3 = ADD32(ctx->r3, 0X1C);
    // 0x801420A8: b           L_801420B0
    // 0x801420AC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
        goto L_801420B0;
    // 0x801420AC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
L_801420B0:
    // 0x801420B0: jal         0x800FC814
    // 0x801420B4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_0;
    // 0x801420B4: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x801420B8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801420BC: jal         0x800FC894
    // 0x801420C0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_1;
    // 0x801420C0: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x801420C4: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801420C8: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801420CC: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x801420D0: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801420D4: lwc1        $f18, 0x28($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X28);
    // 0x801420D8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801420DC: nop

    // 0x801420E0: bc1fl       L_8014211C
    if (!c1cs) {
        // 0x801420E4: c.lt.s      $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
            goto L_8014211C;
    }
    goto skip_0;
    // 0x801420E4: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    skip_0:
    // 0x801420E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801420EC: nop

    // 0x801420F0: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x801420F4: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x801420F8: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801420FC: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80142100: c.le.s      $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f16.fl <= ctx->f10.fl;
    // 0x80142104: nop

    // 0x80142108: bc1fl       L_80142158
    if (!c1cs) {
        // 0x8014210C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80142158;
    }
    goto skip_1;
    // 0x8014210C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80142110: b           L_80142154
    // 0x80142114: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
        goto L_80142154;
    // 0x80142114: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80142118: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
L_8014211C:
    // 0x8014211C: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80142120: bc1fl       L_80142158
    if (!c1cs) {
        // 0x80142124: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80142158;
    }
    goto skip_2;
    // 0x80142124: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80142128: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8014212C: nop

    // 0x80142130: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80142134: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80142138: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x8014213C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80142140: c.le.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl <= ctx->f8.fl;
    // 0x80142144: nop

    // 0x80142148: bc1fl       L_80142158
    if (!c1cs) {
        // 0x8014214C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80142158;
    }
    goto skip_3;
    // 0x8014214C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80142150: swc1        $f16, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f16.u32l;
L_80142154:
    // 0x80142154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80142158:
    // 0x80142158: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8014215C: jr          $ra
    // 0x80142160: nop

    return;
    // 0x80142160: nop

;}
RECOMP_FUNC void gmCameraSetDeadUpStarPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BB08: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x8010BB0C: addiu       $v1, $v1, 0x1300
    ctx->r3 = ADD32(ctx->r3, 0X1300);
    // 0x8010BB10: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8010BB14: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8010BB18: lh          $t6, 0x6C($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X6C);
    // 0x8010BB1C: lh          $t7, 0x74($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X74);
    // 0x8010BB20: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8010BB24: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8010BB28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8010BB2C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8010BB30: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8010BB34: div.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x8010BB38: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x8010BB3C: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8010BB40: lh          $t9, 0x6C($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X6C);
    // 0x8010BB44: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8010BB48: nop

    // 0x8010BB4C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8010BB50: jr          $ra
    // 0x8010BB54: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
    return;
    // 0x8010BB54: swc1        $f8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f8.u32l;
;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeContinue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132824: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132828: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013282C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132830: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132834: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80132838: jal         0x80009968
    // 0x8013283C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8013283C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132840: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132844: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132848: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8013284C: sw          $v0, 0x4304($at)
    MEM_W(0X4304, ctx->r1) = ctx->r2;
    // 0x80132850: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132854: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132858: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013285C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132860: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80132864: jal         0x80009DF4
    // 0x80132868: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132868: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013286C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132870: lw          $t7, 0x4528($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4528);
    // 0x80132874: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132878: addiu       $t8, $t8, 0x18F0
    ctx->r24 = ADD32(ctx->r24, 0X18F0);
    // 0x8013287C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132880: jal         0x800CCFDC
    // 0x80132884: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132884: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132888: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x8013288C: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80132890: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132894: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x80132898: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x8013289C: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801328A0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801328A4: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801328A8: sb          $zero, 0x60($v0)
    MEM_B(0X60, ctx->r2) = 0;
    // 0x801328AC: sb          $zero, 0x61($v0)
    MEM_B(0X61, ctx->r2) = 0;
    // 0x801328B0: sb          $zero, 0x62($v0)
    MEM_B(0X62, ctx->r2) = 0;
    // 0x801328B4: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x801328B8: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x801328BC: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x801328C0: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x801328C4: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x801328C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801328CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801328D0: jr          $ra
    // 0x801328D4: nop

    return;
    // 0x801328D4: nop

;}
RECOMP_FUNC void ftAnimEndSetWait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D94C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D94C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D94CC: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x800D94D0: jal         0x800D9480
    // 0x800D94D4: addiu       $a1, $a1, -0x1E38
    ctx->r5 = ADD32(ctx->r5, -0X1E38);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x800D94D4: addiu       $a1, $a1, -0x1E38
    ctx->r5 = ADD32(ctx->r5, -0X1E38);
    after_0:
    // 0x800D94D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D94DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D94E0: jr          $ra
    // 0x800D94E4: nop

    return;
    // 0x800D94E4: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801574D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801574D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801574D8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801574DC: jal         0x800DDE84
    // 0x801574E0: addiu       $a1, $a1, 0x756C
    ctx->r5 = ADD32(ctx->r5, 0X756C);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x801574E0: addiu       $a1, $a1, 0x756C
    ctx->r5 = ADD32(ctx->r5, 0X756C);
    after_0:
    // 0x801574E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801574E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801574EC: jr          $ra
    // 0x801574F0: nop

    return;
    // 0x801574F0: nop

;}
RECOMP_FUNC void ftCommonTurnProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013E690: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013E694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013E698: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8013E69C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8013E6A0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8013E6A4: lw          $t6, 0x180($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X180);
    // 0x8013E6A8: beql        $t6, $zero, L_8013E6D8
    if (ctx->r14 == 0) {
        // 0x8013E6AC: lwc1        $f10, 0x78($a0)
        ctx->f10.u32l = MEM_W(ctx->r4, 0X78);
            goto L_8013E6D8;
    }
    goto skip_0;
    // 0x8013E6AC: lwc1        $f10, 0x78($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X78);
    skip_0:
    // 0x8013E6B0: lwc1        $f4, 0x60($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X60);
    // 0x8013E6B4: lw          $t7, 0x44($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X44);
    // 0x8013E6B8: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8013E6BC: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8013E6C0: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x8013E6C4: sw          $v1, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r3;
    // 0x8013E6C8: sw          $v1, 0xB1C($v0)
    MEM_W(0XB1C, ctx->r2) = ctx->r3;
    // 0x8013E6CC: sw          $t8, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->r24;
    // 0x8013E6D0: swc1        $f6, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f6.u32l;
    // 0x8013E6D4: lwc1        $f10, 0x78($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X78);
L_8013E6D8:
    // 0x8013E6D8: c.le.s      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.fl <= ctx->f8.fl;
    // 0x8013E6DC: nop

    // 0x8013E6E0: bc1fl       L_8013E6F4
    if (!c1cs) {
        // 0x8013E6E4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013E6F4;
    }
    goto skip_1;
    // 0x8013E6E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013E6E8: jal         0x8013E1C8
    // 0x8013E6EC: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_0;
    // 0x8013E6EC: nop

    after_0:
    // 0x8013E6F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013E6F4:
    // 0x8013E6F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013E6F8: jr          $ra
    // 0x8013E6FC: nop

    return;
    // 0x8013E6FC: nop

;}
RECOMP_FUNC void mnBackupClearUpdateOptionTabColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131CE4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131CE8: addiu       $t6, $t6, 0x2F38
    ctx->r14 = ADD32(ctx->r14, 0X2F38);
    // 0x80131CEC: lwr         $t8, 0x2($t6)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r14, 0X2);
    // 0x80131CF0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x80131CF4: addiu       $a2, $sp, 0xC
    ctx->r6 = ADD32(ctx->r29, 0XC);
    // 0x80131CF8: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80131CFC: addiu       $t9, $t9, 0x2F3C
    ctx->r25 = ADD32(ctx->r25, 0X2F3C);
    // 0x80131D00: swr         $t8, 0x2($a2)
    do_swr(rdram, 0X2, ctx->r6, ctx->r24);
    // 0x80131D04: lwr         $t1, 0x2($t9)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r25, 0X2);
    // 0x80131D08: addiu       $a3, $sp, 0x8
    ctx->r7 = ADD32(ctx->r29, 0X8);
    // 0x80131D0C: swr         $t1, 0x2($a3)
    do_swr(rdram, 0X2, ctx->r7, ctx->r9);
    // 0x80131D10: beq         $a1, $zero, L_80131D20
    if (ctx->r5 == 0) {
        // 0x80131D14: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_80131D20;
    }
    // 0x80131D14: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80131D18: b           L_80131D24
    // 0x80131D1C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
        goto L_80131D24;
    // 0x80131D1C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_80131D20:
    // 0x80131D20: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_80131D24:
    // 0x80131D24: lbu         $t2, 0x0($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X0);
    // 0x80131D28: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80131D2C: lbu         $t3, 0x1($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X1);
    // 0x80131D30: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80131D34: lbu         $t4, 0x2($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X2);
    // 0x80131D38: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x80131D3C: jr          $ra
    // 0x80131D40: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    return;
    // 0x80131D40: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
;}
RECOMP_FUNC void mnPlayers1PTrainingSetGateLUT(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C24: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132C28: addiu       $t6, $t6, -0x7DEC
    ctx->r14 = ADD32(ctx->r14, -0X7DEC);
    // 0x80132C2C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132C30: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132C34: addiu       $a2, $sp, 0x4
    ctx->r6 = ADD32(ctx->r29, 0X4);
    // 0x80132C38: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80132C3C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80132C40: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80132C44: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132C48: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x80132C4C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80132C50: sw          $t8, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r24;
    // 0x80132C54: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80132C58: sw          $t7, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r15;
    // 0x80132C5C: lw          $v1, -0x776C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X776C);
    // 0x80132C60: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x80132C64: bne         $a1, $v1, L_80132C84
    if (ctx->r5 != ctx->r3) {
        // 0x80132C68: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80132C84;
    }
    // 0x80132C68: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80132C6C: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x80132C70: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80132C74: lw          $t2, -0x7368($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X7368);
    // 0x80132C78: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80132C7C: b           L_80132C9C
    // 0x80132C80: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
        goto L_80132C9C;
    // 0x80132C80: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_80132C84:
    // 0x80132C84: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80132C88: lw          $t4, -0x7364($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X7364);
    // 0x80132C8C: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x80132C90: addiu       $t5, $t5, 0x3238
    ctx->r13 = ADD32(ctx->r13, 0X3238);
    // 0x80132C94: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80132C98: sw          $t6, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r14;
L_80132C9C:
    // 0x80132C9C: jr          $ra
    // 0x80132CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80132CA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void ftDisplayMainDrawAfterImage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F1020: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x800F1024: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800F1028: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800F102C: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800F1030: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800F1034: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800F1038: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800F103C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800F1040: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800F1044: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800F1048: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800F104C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x800F1050: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x800F1054: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x800F1058: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x800F105C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x800F1060: lbu         $v0, 0xA9C($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0XA9C);
    // 0x800F1064: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800F1068: lbu         $v1, 0xA9E($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0XA9E);
    // 0x800F106C: beq         $v0, $zero, L_800F1098
    if (ctx->r2 == 0) {
        // 0x800F1070: lui         $s5, 0x8004
        ctx->r21 = S32(0X8004 << 16);
            goto L_800F1098;
    }
    // 0x800F1070: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x800F1074: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F1078: beq         $v0, $at, L_800F10E8
    if (ctx->r2 == ctx->r1) {
        // 0x800F107C: addiu       $t9, $zero, 0xFF
        ctx->r25 = ADD32(0, 0XFF);
            goto L_800F10E8;
    }
    // 0x800F107C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800F1080: lwc1        $f28, 0xE8($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x800F1084: lwc1        $f22, 0xEC($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800F1088: lwc1        $f20, 0xF0($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800F108C: lw          $fp, 0xE0($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XE0);
    // 0x800F1090: b           L_800F1130
    // 0x800F1094: lw          $s7, 0xE4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XE4);
        goto L_800F1130;
    // 0x800F1094: lw          $s7, 0xE4($sp)
    ctx->r23 = MEM_W(ctx->r29, 0XE4);
L_800F1098:
    // 0x800F1098: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800F109C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800F10A0: lui         $at, 0x437A
    ctx->r1 = S32(0X437A << 16);
    // 0x800F10A4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800F10A8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F10AC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F10B0: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800F10B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F10B8: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800F10BC: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800F10C0: addiu       $t7, $t7, -0x3B70
    ctx->r15 = ADD32(ctx->r15, -0X3B70);
    // 0x800F10C4: addiu       $t8, $t8, -0x3B50
    ctx->r24 = ADD32(ctx->r24, -0X3B50);
    // 0x800F10C8: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x800F10CC: sw          $t6, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r14;
    // 0x800F10D0: lwc1        $f28, 0x260($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X260);
    // 0x800F10D4: addiu       $s7, $s7, -0x3B38
    ctx->r23 = ADD32(ctx->r23, -0X3B38);
    // 0x800F10D8: addiu       $fp, $fp, -0x3B34
    ctx->r30 = ADD32(ctx->r30, -0X3B34);
    // 0x800F10DC: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x800F10E0: b           L_800F1130
    // 0x800F10E4: sw          $t8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r24;
        goto L_800F1130;
    // 0x800F10E4: sw          $t8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r24;
L_800F10E8:
    // 0x800F10E8: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x800F10EC: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800F10F0: lui         $at, 0x4411
    ctx->r1 = S32(0X4411 << 16);
    // 0x800F10F4: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800F10F8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F10FC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F1100: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F1104: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800F1108: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800F110C: addiu       $t6, $t6, -0x3B70
    ctx->r14 = ADD32(ctx->r14, -0X3B70);
    // 0x800F1110: addiu       $t7, $t7, -0x3B50
    ctx->r15 = ADD32(ctx->r15, -0X3B50);
    // 0x800F1114: sw          $zero, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = 0;
    // 0x800F1118: sw          $t9, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r25;
    // 0x800F111C: lwc1        $f28, 0x264($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X264);
    // 0x800F1120: addiu       $s7, $s7, -0x3B30
    ctx->r23 = ADD32(ctx->r23, -0X3B30);
    // 0x800F1124: addiu       $fp, $fp, -0x3B2C
    ctx->r30 = ADD32(ctx->r30, -0X3B2C);
    // 0x800F1128: sw          $t6, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r14;
    // 0x800F112C: sw          $t7, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r15;
L_800F1130:
    // 0x800F1130: addiu       $s5, $s5, 0x65D8
    ctx->r21 = ADD32(ctx->r21, 0X65D8);
    // 0x800F1134: lw          $s0, 0xC($s5)
    ctx->r16 = MEM_W(ctx->r21, 0XC);
    // 0x800F1138: lw          $t8, 0xF4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF4);
    // 0x800F113C: beq         $v1, $zero, L_800F114C
    if (ctx->r3 == 0) {
        // 0x800F1140: sw          $s0, 0x104($sp)
        MEM_W(0X104, ctx->r29) = ctx->r16;
            goto L_800F114C;
    }
    // 0x800F1140: sw          $s0, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r16;
    // 0x800F1144: b           L_800F1150
    // 0x800F1148: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
        goto L_800F1150;
    // 0x800F1148: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_800F114C:
    // 0x800F114C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800F1150:
    // 0x800F1150: lb          $a0, 0xA9D($s2)
    ctx->r4 = MEM_B(ctx->r18, 0XA9D);
    // 0x800F1154: lw          $t9, 0xF8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XF8);
    // 0x800F1158: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800F115C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800F1160: bltz        $a0, L_800F16A0
    if (SIGNED(ctx->r4) < 0) {
        // 0x800F1164: subu        $t6, $t8, $t9
        ctx->r14 = SUB32(ctx->r24, ctx->r25);
            goto L_800F16A0;
    }
    // 0x800F1164: subu        $t6, $t8, $t9
    ctx->r14 = SUB32(ctx->r24, ctx->r25);
    // 0x800F1168: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800F116C: sw          $t6, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r14;
    // 0x800F1170: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
L_800F1174:
    // 0x800F1174: lb          $t8, 0xA9D($s2)
    ctx->r24 = MEM_B(ctx->r18, 0XA9D);
    // 0x800F1178: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x800F117C: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800F1180: div         $zero, $t7, $t9
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r25))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r25)));
    // 0x800F1184: mflo        $t6
    ctx->r14 = lo;
    // 0x800F1188: bne         $t9, $zero, L_800F1194
    if (ctx->r25 != 0) {
        // 0x800F118C: nop
    
            goto L_800F1194;
    }
    // 0x800F118C: nop

    // 0x800F1190: break       7
    do_break(2148471184);
L_800F1194:
    // 0x800F1194: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F1198: bne         $t9, $at, L_800F11AC
    if (ctx->r25 != ctx->r1) {
        // 0x800F119C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F11AC;
    }
    // 0x800F119C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F11A0: bne         $t7, $at, L_800F11AC
    if (ctx->r15 != ctx->r1) {
        // 0x800F11A4: nop
    
            goto L_800F11AC;
    }
    // 0x800F11A4: nop

    // 0x800F11A8: break       6
    do_break(2148471208);
L_800F11AC:
    // 0x800F11AC: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F11B0: lw          $t7, 0xF8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XF8);
    // 0x800F11B4: mflo        $t8
    ctx->r24 = lo;
    // 0x800F11B8: addu        $s6, $t8, $t7
    ctx->r22 = ADD32(ctx->r24, ctx->r15);
    // 0x800F11BC: nop

    // 0x800F11C0: multu       $v1, $a3
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F11C4: mflo        $t9
    ctx->r25 = lo;
    // 0x800F11C8: addu        $v0, $s2, $t9
    ctx->r2 = ADD32(ctx->r18, ctx->r25);
    // 0x800F11CC: lh          $t6, 0xAA0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XAA0);
    // 0x800F11D0: lwc1        $f8, 0xAA8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XAA8);
    // 0x800F11D4: addiu       $t0, $v0, 0xAA0
    ctx->r8 = ADD32(ctx->r2, 0XAA0);
    // 0x800F11D8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800F11DC: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800F11E0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F11E4: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800F11E8: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800F11EC: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800F11F0: nop

    // 0x800F11F4: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
    // 0x800F11F8: lh          $t9, 0xAA2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XAA2);
    // 0x800F11FC: lwc1        $f6, 0xAAC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XAAC);
    // 0x800F1200: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800F1204: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800F1208: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F120C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F1210: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800F1214: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800F1218: nop

    // 0x800F121C: sh          $t8, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r24;
    // 0x800F1220: lh          $t7, 0xAA4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XAA4);
    // 0x800F1224: lwc1        $f8, 0xAB0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XAB0);
    // 0x800F1228: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x800F122C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800F1230: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800F1234: lh          $t8, 0xA($s0)
    ctx->r24 = MEM_H(ctx->r16, 0XA);
    // 0x800F1238: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x800F123C: sh          $t8, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r24;
    // 0x800F1240: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F1244: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800F1248: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800F124C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800F1250: nop

    // 0x800F1254: sh          $t6, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r14;
    // 0x800F1258: lbu         $t7, 0x0($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0X0);
    // 0x800F125C: sb          $t7, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r15;
    // 0x800F1260: lbu         $t9, 0x1($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X1);
    // 0x800F1264: sb          $t9, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r25;
    // 0x800F1268: lbu         $t6, 0x2($s7)
    ctx->r14 = MEM_BU(ctx->r23, 0X2);
    // 0x800F126C: sb          $s6, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r22;
    // 0x800F1270: sb          $t6, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r14;
    // 0x800F1274: lw          $t8, 0xC($s5)
    ctx->r24 = MEM_W(ctx->r21, 0XC);
    // 0x800F1278: addiu       $t7, $t8, 0x10
    ctx->r15 = ADD32(ctx->r24, 0X10);
    // 0x800F127C: sw          $t7, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r15;
    // 0x800F1280: lh          $t9, 0x0($t0)
    ctx->r25 = MEM_H(ctx->r8, 0X0);
    // 0x800F1284: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x800F1288: or          $s0, $t7, $zero
    ctx->r16 = ctx->r15 | 0;
    // 0x800F128C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800F1290: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800F1294: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F1298: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F129C: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800F12A0: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800F12A4: nop

    // 0x800F12A8: sh          $t8, 0x0($t7)
    MEM_H(0X0, ctx->r15) = ctx->r24;
    // 0x800F12AC: lh          $t7, 0x2($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X2);
    // 0x800F12B0: lwc1        $f8, 0xC($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0XC);
    // 0x800F12B4: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800F12B8: mul.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f22.fl);
    // 0x800F12BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F12C0: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800F12C4: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800F12C8: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800F12CC: nop

    // 0x800F12D0: sh          $t6, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r14;
    // 0x800F12D4: lh          $t8, 0x4($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X4);
    // 0x800F12D8: lwc1        $f6, 0x10($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X10);
    // 0x800F12DC: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x800F12E0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800F12E4: mul.s       $f10, $f6, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800F12E8: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x800F12EC: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x800F12F0: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x800F12F4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F12F8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800F12FC: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800F1300: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800F1304: nop

    // 0x800F1308: sh          $t9, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r25;
    // 0x800F130C: lbu         $t8, 0x0($fp)
    ctx->r24 = MEM_BU(ctx->r30, 0X0);
    // 0x800F1310: sb          $t8, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r24;
    // 0x800F1314: lbu         $t7, 0x1($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1);
    // 0x800F1318: sb          $t7, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r15;
    // 0x800F131C: lbu         $t9, 0x2($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0X2);
    // 0x800F1320: sb          $s6, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r22;
    // 0x800F1324: sb          $t9, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r25;
    // 0x800F1328: lw          $t6, 0xC($s5)
    ctx->r14 = MEM_W(ctx->r21, 0XC);
    // 0x800F132C: sw          $s2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r18;
    // 0x800F1330: sw          $a0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r4;
    // 0x800F1334: addiu       $t8, $t6, 0x10
    ctx->r24 = ADD32(ctx->r14, 0X10);
    // 0x800F1338: sw          $t8, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r24;
    // 0x800F133C: beq         $a0, $zero, L_800F1688
    if (ctx->r4 == 0) {
        // 0x800F1340: or          $s0, $t8, $zero
        ctx->r16 = ctx->r24 | 0;
            goto L_800F1688;
    }
    // 0x800F1340: or          $s0, $t8, $zero
    ctx->r16 = ctx->r24 | 0;
    // 0x800F1344: beq         $v1, $zero, L_800F135C
    if (ctx->r3 == 0) {
        // 0x800F1348: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_800F135C;
    }
    // 0x800F1348: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x800F134C: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800F1350: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
    // 0x800F1354: b           L_800F1364
    // 0x800F1358: sw          $a0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r4;
        goto L_800F1364;
    // 0x800F1358: sw          $a0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r4;
L_800F135C:
    // 0x800F135C: sw          $t9, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r25;
    // 0x800F1360: sw          $a0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->r4;
L_800F1364:
    // 0x800F1364: lw          $t6, 0x10C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10C);
    // 0x800F1368: addiu       $a0, $t0, 0x8
    ctx->r4 = ADD32(ctx->r8, 0X8);
    // 0x800F136C: sw          $a0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r4;
    // 0x800F1370: multu       $t6, $a3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F1374: addiu       $a2, $sp, 0xC8
    ctx->r6 = ADD32(ctx->r29, 0XC8);
    // 0x800F1378: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800F137C: sw          $s2, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r18;
    // 0x800F1380: mflo        $t8
    ctx->r24 = lo;
    // 0x800F1384: addu        $s1, $s2, $t8
    ctx->r17 = ADD32(ctx->r18, ctx->r24);
    // 0x800F1388: jal         0x80019980
    // 0x800F138C: addiu       $a1, $s1, 0xAA8
    ctx->r5 = ADD32(ctx->r17, 0XAA8);
    syVectorNormCross3D(rdram, ctx);
        goto after_0;
    // 0x800F138C: addiu       $a1, $s1, 0xAA8
    ctx->r5 = ADD32(ctx->r17, 0XAA8);
    after_0:
    // 0x800F1390: beq         $v0, $zero, L_800F1688
    if (ctx->r2 == 0) {
        // 0x800F1394: lw          $t0, 0x7C($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X7C);
            goto L_800F1688;
    }
    // 0x800F1394: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800F1398: addiu       $v0, $s1, 0xAA0
    ctx->r2 = ADD32(ctx->r17, 0XAA0);
    // 0x800F139C: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800F13A0: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x800F13A4: lw          $a0, 0x6C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X6C);
    // 0x800F13A8: jal         0x800191FC
    // 0x800F13AC: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    syVectorAngleDiff3D(rdram, ctx);
        goto after_1;
    // 0x800F13AC: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_1:
    // 0x800F13B0: div.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f28.fl);
    // 0x800F13B4: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x800F13B8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800F13BC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800F13C0: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800F13C4: nop

    // 0x800F13C8: beq         $a1, $zero, L_800F1688
    if (ctx->r5 == 0) {
        // 0x800F13CC: addiu       $a0, $a1, 0x1
        ctx->r4 = ADD32(ctx->r5, 0X1);
            goto L_800F1688;
    }
    // 0x800F13CC: addiu       $a0, $a1, 0x1
    ctx->r4 = ADD32(ctx->r5, 0X1);
    // 0x800F13D0: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800F13D4: lh          $s1, 0x0($t0)
    ctx->r17 = MEM_H(ctx->r8, 0X0);
    // 0x800F13D8: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x800F13DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F13E0: lh          $s2, 0x2($t0)
    ctx->r18 = MEM_H(ctx->r8, 0X2);
    // 0x800F13E4: subu        $t6, $t9, $s1
    ctx->r14 = SUB32(ctx->r25, ctx->r17);
    // 0x800F13E8: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800F13EC: lh          $s3, 0x4($t0)
    ctx->r19 = MEM_H(ctx->r8, 0X4);
    // 0x800F13F0: addiu       $v1, $a0, -0x1
    ctx->r3 = ADD32(ctx->r4, -0X1);
    // 0x800F13F4: div.s       $f2, $f26, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f26.fl, ctx->f10.fl);
    // 0x800F13F8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800F13FC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F1400: mul.s       $f24, $f0, $f2
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f24.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x800F1404: nop

    // 0x800F1408: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800F140C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800F1410: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x800F1414: nop

    // 0x800F1418: sh          $t7, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r15;
    // 0x800F141C: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800F1420: subu        $t6, $t9, $s2
    ctx->r14 = SUB32(ctx->r25, ctx->r18);
    // 0x800F1424: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800F1428: nop

    // 0x800F142C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F1430: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800F1434: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800F1438: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800F143C: nop

    // 0x800F1440: sh          $t7, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r15;
    // 0x800F1444: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800F1448: subu        $t6, $t9, $s3
    ctx->r14 = SUB32(ctx->r25, ctx->r19);
    // 0x800F144C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800F1450: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x800F1454: addiu       $t9, $sp, 0xAC
    ctx->r25 = ADD32(ctx->r29, 0XAC);
    // 0x800F1458: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F145C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800F1460: trunc.w.s   $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800F1464: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800F1468: nop

    // 0x800F146C: sh          $t7, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r15;
    // 0x800F1470: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800F1474: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800F1478: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x800F147C: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
    // 0x800F1480: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x800F1484: sw          $t7, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r15;
    // 0x800F1488: lw          $t6, 0x118($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X118);
    // 0x800F148C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x800F1490: lb          $t8, 0xA9D($t6)
    ctx->r24 = MEM_B(ctx->r14, 0XA9D);
    // 0x800F1494: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x800F1498: div         $zero, $t9, $t7
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r15))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r15)));
    // 0x800F149C: lw          $t8, 0x114($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X114);
    // 0x800F14A0: mflo        $t6
    ctx->r14 = lo;
    // 0x800F14A4: bne         $t7, $zero, L_800F14B0
    if (ctx->r15 != 0) {
        // 0x800F14A8: nop
    
            goto L_800F14B0;
    }
    // 0x800F14A8: nop

    // 0x800F14AC: break       7
    do_break(2148471980);
L_800F14B0:
    // 0x800F14B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F14B4: bne         $t7, $at, L_800F14C8
    if (ctx->r15 != ctx->r1) {
        // 0x800F14B8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800F14C8;
    }
    // 0x800F14B8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800F14BC: bne         $t9, $at, L_800F14C8
    if (ctx->r25 != ctx->r1) {
        // 0x800F14C0: nop
    
            goto L_800F14C8;
    }
    // 0x800F14C0: nop

    // 0x800F14C4: break       6
    do_break(2148472004);
L_800F14C8:
    // 0x800F14C8: addiu       $t9, $t8, -0x1
    ctx->r25 = ADD32(ctx->r24, -0X1);
    // 0x800F14CC: multu       $t6, $t9
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F14D0: lw          $t8, 0xF8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XF8);
    // 0x800F14D4: mflo        $t7
    ctx->r15 = lo;
    // 0x800F14D8: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x800F14DC: subu        $t9, $t6, $s6
    ctx->r25 = SUB32(ctx->r14, ctx->r22);
    // 0x800F14E0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800F14E4: nop

    // 0x800F14E8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F14EC: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800F14F0: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x800F14F4: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x800F14F8: blez        $v1, L_800F1688
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800F14FC: nop
    
            goto L_800F1688;
    }
    // 0x800F14FC: nop

L_800F1500:
    // 0x800F1500: lh          $t8, 0xA0($sp)
    ctx->r24 = MEM_H(ctx->r29, 0XA0);
    // 0x800F1504: lh          $t6, 0x9E($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X9E);
    // 0x800F1508: lh          $t9, 0x9C($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X9C);
    // 0x800F150C: addu        $s1, $s1, $t8
    ctx->r17 = ADD32(ctx->r17, ctx->r24);
    // 0x800F1510: addu        $s2, $s2, $t6
    ctx->r18 = ADD32(ctx->r18, ctx->r14);
    // 0x800F1514: addu        $s3, $s3, $t9
    ctx->r19 = ADD32(ctx->r19, ctx->r25);
    // 0x800F1518: sll         $s1, $s1, 16
    ctx->r17 = S32(ctx->r17 << 16);
    // 0x800F151C: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800F1520: sll         $s3, $s3, 16
    ctx->r19 = S32(ctx->r19 << 16);
    // 0x800F1524: mfc1        $a2, $f24
    ctx->r6 = (int32_t)ctx->f24.u32l;
    // 0x800F1528: sra         $s1, $s1, 16
    ctx->r17 = S32(SIGNED(ctx->r17) >> 16);
    // 0x800F152C: sra         $s2, $s2, 16
    ctx->r18 = S32(SIGNED(ctx->r18) >> 16);
    // 0x800F1530: sra         $s3, $s3, 16
    ctx->r19 = S32(SIGNED(ctx->r19) >> 16);
    // 0x800F1534: addiu       $a0, $sp, 0xAC
    ctx->r4 = ADD32(ctx->r29, 0XAC);
    // 0x800F1538: addiu       $a1, $sp, 0xC8
    ctx->r5 = ADD32(ctx->r29, 0XC8);
    // 0x800F153C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x800F1540: jal         0x80019438
    // 0x800F1544: sw          $a3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r7;
    syVectorRotateAbout3D(rdram, ctx);
        goto after_2;
    // 0x800F1544: sw          $a3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r7;
    after_2:
    // 0x800F1548: lwc1        $f10, 0xAC($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F154C: mtc1        $s1, $f8
    ctx->f8.u32l = ctx->r17;
    // 0x800F1550: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x800F1554: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800F1558: lw          $a3, 0xB8($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XB8);
    // 0x800F155C: mtc1        $s2, $f6
    ctx->f6.u32l = ctx->r18;
    // 0x800F1560: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800F1564: addu        $s6, $s6, $a3
    ctx->r22 = ADD32(ctx->r22, ctx->r7);
    // 0x800F1568: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F156C: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F1570: add.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f0.fl + ctx->f16.fl;
    // 0x800F1574: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800F1578: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x800F157C: mtc1        $s3, $f4
    ctx->f4.u32l = ctx->r19;
    // 0x800F1580: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x800F1584: lwc1        $f8, 0xB0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F1588: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F158C: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800F1590: add.s       $f16, $f2, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x800F1594: trunc.w.s   $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x800F1598: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x800F159C: nop

    // 0x800F15A0: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x800F15A4: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F15A8: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x800F15AC: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x800F15B0: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800F15B4: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x800F15B8: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x800F15BC: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x800F15C0: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800F15C4: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800F15C8: nop

    // 0x800F15CC: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x800F15D0: lbu         $t9, 0x0($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X0);
    // 0x800F15D4: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
    // 0x800F15D8: lbu         $t7, 0x1($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0X1);
    // 0x800F15DC: sb          $t7, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r15;
    // 0x800F15E0: lbu         $t8, 0x2($s7)
    ctx->r24 = MEM_BU(ctx->r23, 0X2);
    // 0x800F15E4: sb          $s6, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r22;
    // 0x800F15E8: sb          $t8, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r24;
    // 0x800F15EC: lwc1        $f18, 0xAC($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800F15F0: lw          $t6, 0xC($s5)
    ctx->r14 = MEM_W(ctx->r21, 0XC);
    // 0x800F15F4: mul.s       $f4, $f18, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x800F15F8: addiu       $s0, $t6, 0x10
    ctx->r16 = ADD32(ctx->r14, 0X10);
    // 0x800F15FC: sw          $s0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r16;
    // 0x800F1600: add.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800F1604: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x800F1608: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800F160C: nop

    // 0x800F1610: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
    // 0x800F1614: lwc1        $f10, 0xB0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x800F1618: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800F161C: add.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f16.fl;
    // 0x800F1620: trunc.w.s   $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = TRUNC_W_S(ctx->f18.fl);
    // 0x800F1624: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800F1628: nop

    // 0x800F162C: sh          $t9, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r25;
    // 0x800F1630: lwc1        $f6, 0xB4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x800F1634: sh          $zero, 0xA($s0)
    MEM_H(0XA, ctx->r16) = 0;
    // 0x800F1638: lh          $t6, 0xA($s0)
    ctx->r14 = MEM_H(ctx->r16, 0XA);
    // 0x800F163C: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800F1640: sh          $zero, 0x6($s0)
    MEM_H(0X6, ctx->r16) = 0;
    // 0x800F1644: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x800F1648: add.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f8.fl;
    // 0x800F164C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800F1650: mfc1        $t8, $f16
    ctx->r24 = (int32_t)ctx->f16.u32l;
    // 0x800F1654: nop

    // 0x800F1658: sh          $t8, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r24;
    // 0x800F165C: lbu         $t9, 0x0($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0X0);
    // 0x800F1660: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
    // 0x800F1664: lbu         $t7, 0x1($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X1);
    // 0x800F1668: sb          $t7, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r15;
    // 0x800F166C: lbu         $t8, 0x2($fp)
    ctx->r24 = MEM_BU(ctx->r30, 0X2);
    // 0x800F1670: sb          $s6, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r22;
    // 0x800F1674: sb          $t8, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r24;
    // 0x800F1678: lw          $t6, 0xC($s5)
    ctx->r14 = MEM_W(ctx->r21, 0XC);
    // 0x800F167C: addiu       $s0, $t6, 0x10
    ctx->r16 = ADD32(ctx->r14, 0X10);
    // 0x800F1680: bne         $s4, $v1, L_800F1500
    if (ctx->r20 != ctx->r3) {
        // 0x800F1684: sw          $s0, 0xC($s5)
        MEM_W(0XC, ctx->r21) = ctx->r16;
            goto L_800F1500;
    }
    // 0x800F1684: sw          $s0, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r16;
L_800F1688:
    // 0x800F1688: lw          $a0, 0x114($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X114);
    // 0x800F168C: lw          $v1, 0x10C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X10C);
    // 0x800F1690: addiu       $a3, $zero, 0x14
    ctx->r7 = ADD32(0, 0X14);
    // 0x800F1694: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800F1698: bgez        $a0, L_800F1174
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800F169C: lw          $s2, 0x118($sp)
        ctx->r18 = MEM_W(ctx->r29, 0X118);
            goto L_800F1174;
    }
    // 0x800F169C: lw          $s2, 0x118($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X118);
L_800F16A0:
    // 0x800F16A0: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800F16A4: addiu       $t2, $t2, 0x65B0
    ctx->r10 = ADD32(ctx->r10, 0X65B0);
    // 0x800F16A8: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x800F16AC: lw          $t7, 0x104($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X104);
    // 0x800F16B0: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x800F16B4: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x800F16B8: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x800F16BC: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800F16C0: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
    // 0x800F16C4: subu        $v0, $s0, $t7
    ctx->r2 = SUB32(ctx->r16, ctx->r15);
    // 0x800F16C8: srl         $v0, $v0, 4
    ctx->r2 = S32(U32(ctx->r2) >> 4);
    // 0x800F16CC: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x800F16D0: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x800F16D4: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x800F16D8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x800F16DC: addiu       $t9, $a2, 0x8
    ctx->r25 = ADD32(ctx->r6, 0X8);
    // 0x800F16E0: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x800F16E4: andi        $t9, $v0, 0x7F
    ctx->r25 = ctx->r2 & 0X7F;
    // 0x800F16E8: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800F16EC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x800F16F0: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x800F16F4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800F16F8: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800F16FC: lw          $t9, 0x104($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X104);
    // 0x800F1700: addiu       $t6, $v0, -0x2
    ctx->r14 = ADD32(ctx->r2, -0X2);
    // 0x800F1704: blez        $t6, L_800F178C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800F1708: sw          $t9, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r25;
            goto L_800F178C;
    }
    // 0x800F1708: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800F170C: addiu       $v0, $v0, -0x2
    ctx->r2 = ADD32(ctx->r2, -0X2);
    // 0x800F1710: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x800F1714: addiu       $t4, $t4, 0x6
    ctx->r12 = ADD32(ctx->r12, 0X6);
    // 0x800F1718: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800F171C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800F1720: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800F1724: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x800F1728: lui         $t3, 0x600
    ctx->r11 = S32(0X600 << 16);
L_800F172C:
    // 0x800F172C: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x800F1730: andi        $v1, $t0, 0xFF
    ctx->r3 = ctx->r8 & 0XFF;
    // 0x800F1734: andi        $t8, $a3, 0xFF
    ctx->r24 = ctx->r7 & 0XFF;
    // 0x800F1738: addiu       $t7, $a2, 0x8
    ctx->r15 = ADD32(ctx->r6, 0X8);
    // 0x800F173C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x800F1740: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800F1744: sll         $t6, $v1, 8
    ctx->r14 = S32(ctx->r3 << 8);
    // 0x800F1748: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800F174C: andi        $a0, $t1, 0xFF
    ctx->r4 = ctx->r9 & 0XFF;
    // 0x800F1750: or          $t8, $t7, $a0
    ctx->r24 = ctx->r15 | ctx->r4;
    // 0x800F1754: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x800F1758: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800F175C: sll         $t8, $t7, 8
    ctx->r24 = S32(ctx->r15 << 8);
    // 0x800F1760: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x800F1764: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800F1768: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800F176C: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800F1770: slt         $at, $a1, $t4
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800F1774: or          $t7, $t9, $a0
    ctx->r15 = ctx->r25 | ctx->r4;
    // 0x800F1778: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800F177C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800F1780: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800F1784: bne         $at, $zero, L_800F172C
    if (ctx->r1 != 0) {
        // 0x800F1788: sw          $t7, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r15;
            goto L_800F172C;
    }
    // 0x800F1788: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
L_800F178C:
    // 0x800F178C: lw          $a2, 0x4($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X4);
    // 0x800F1790: addiu       $t6, $a2, 0x8
    ctx->r14 = ADD32(ctx->r6, 0X8);
    // 0x800F1794: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x800F1798: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800F179C: lw          $t8, 0xD8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD8);
    // 0x800F17A0: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x800F17A4: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800F17A8: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800F17AC: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800F17B0: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800F17B4: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800F17B8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800F17BC: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800F17C0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800F17C4: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800F17C8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800F17CC: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x800F17D0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x800F17D4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x800F17D8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x800F17DC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x800F17E0: jr          $ra
    // 0x800F17E4: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x800F17E4: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void ftBossGootsubusuEndProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159DB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159DB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80159DB8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80159DBC: jal         0x800D9480
    // 0x80159DC0: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80159DC0: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    after_0:
    // 0x80159DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80159DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80159DCC: jr          $ra
    // 0x80159DD0: nop

    return;
    // 0x80159DD0: nop

;}
RECOMP_FUNC void gmCollisionCheckWeaponAttacksCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F007C: addiu       $t2, $zero, 0x60
    ctx->r10 = ADD32(0, 0X60);
    // 0x800F0080: multu       $a1, $t2
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F0084: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800F0088: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800F008C: lw          $t8, 0x5C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5C);
    // 0x800F0090: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800F0094: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800F0098: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800F009C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F00A0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800F00A4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800F00A8: mflo        $t7
    ctx->r15 = lo;
    // 0x800F00AC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800F00B0: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    // 0x800F00B4: multu       $t8, $t2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F00B8: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800F00BC: addiu       $a0, $v0, 0x54
    ctx->r4 = ADD32(ctx->r2, 0X54);
    // 0x800F00C0: addiu       $a1, $v0, 0x60
    ctx->r5 = ADD32(ctx->r2, 0X60);
    // 0x800F00C4: mflo        $t9
    ctx->r25 = lo;
    // 0x800F00C8: addu        $v1, $s0, $t9
    ctx->r3 = ADD32(ctx->r16, ctx->r25);
    // 0x800F00CC: addiu       $t0, $v1, 0x54
    ctx->r8 = ADD32(ctx->r3, 0X54);
    // 0x800F00D0: addiu       $t1, $v1, 0x60
    ctx->r9 = ADD32(ctx->r3, 0X60);
    // 0x800F00D4: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800F00D8: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800F00DC: lwc1        $f4, 0x28($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800F00E0: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800F00E4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800F00E8: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x800F00EC: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800F00F0: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800F00F4: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x800F00F8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800F00FC: jal         0x800EF5D4
    // 0x800F0100: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    func_ovl2_800EF5D4(rdram, ctx);
        goto after_0;
    // 0x800F0100: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    after_0:
    // 0x800F0104: bne         $v0, $zero, L_800F0114
    if (ctx->r2 != 0) {
        // 0x800F0108: lw          $v1, 0x44($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X44);
            goto L_800F0114;
    }
    // 0x800F0108: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800F010C: b           L_800F0188
    // 0x800F0110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F0188;
    // 0x800F0110: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F0114:
    // 0x800F0114: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800F0118: addiu       $v0, $v1, 0x70
    ctx->r2 = ADD32(ctx->r3, 0X70);
    // 0x800F011C: addiu       $t4, $v1, 0xB0
    ctx->r12 = ADD32(ctx->r3, 0XB0);
    // 0x800F0120: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800F0124: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F0128: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800F012C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800F0130: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800F0134: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0138: jal         0x800EE050
    // 0x800F013C: addiu       $a3, $v1, 0x6C
    ctx->r7 = ADD32(ctx->r3, 0X6C);
    func_ovl2_800EE050(rdram, ctx);
        goto after_1;
    // 0x800F013C: addiu       $a3, $v1, 0x6C
    ctx->r7 = ADD32(ctx->r3, 0X6C);
    after_1:
    // 0x800F0140: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800F0144: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x800F0148: lw          $a2, 0x28($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X28);
    // 0x800F014C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800F0150: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F0154: lw          $t6, 0x40($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X40);
    // 0x800F0158: lw          $t5, 0x6C($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X6C);
    // 0x800F015C: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800F0160: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x800F0164: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800F0168: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x800F016C: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800F0170: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800F0174: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800F0178: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    // 0x800F017C: lwc1        $f8, 0xB0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x800F0180: jal         0x800EEEAC
    // 0x800F0184: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_ovl2_800EEEAC(rdram, ctx);
        goto after_2;
    // 0x800F0184: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_2:
L_800F0188:
    // 0x800F0188: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F018C: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800F0190: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800F0194: jr          $ra
    // 0x800F0198: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800F0198: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void syDebugFramebufferPrintf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022664: addiu       $sp, $sp, -0x140
    ctx->r29 = ADD32(ctx->r29, -0X140);
    // 0x80022668: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002266C: sw          $a3, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r7;
    // 0x80022670: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80022674: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80022678: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8002267C: or          $a3, $sp, $zero
    ctx->r7 = ctx->r29 | 0;
    // 0x80022680: addiu       $s3, $sp, 0x34
    ctx->r19 = ADD32(ctx->r29, 0X34);
    // 0x80022684: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x80022688: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002268C: addiu       $a3, $a3, 0x14F
    ctx->r7 = ADD32(ctx->r7, 0X14F);
    // 0x80022690: lui         $a0, 0x8002
    ctx->r4 = S32(0X8002 << 16);
    // 0x80022694: addiu       $at, $zero, -0x4
    ctx->r1 = ADD32(0, -0X4);
    // 0x80022698: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8002269C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800226A0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800226A4: sw          $a2, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r6;
    // 0x800226A8: and         $a3, $a3, $at
    ctx->r7 = ctx->r7 & ctx->r1;
    // 0x800226AC: addiu       $a0, $a0, 0x2640
    ctx->r4 = ADD32(ctx->r4, 0X2640);
    // 0x800226B0: jal         0x80033C60
    // 0x800226B4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    _Printf(rdram, ctx);
        goto after_0;
    // 0x800226B4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800226B8: blez        $v0, L_80022708
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800226BC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80022708;
    }
    // 0x800226BC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800226C0: blez        $v0, L_80022708
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800226C4: or          $s1, $s3, $zero
        ctx->r17 = ctx->r19 | 0;
            goto L_80022708;
    }
    // 0x800226C4: or          $s1, $s3, $zero
    ctx->r17 = ctx->r19 | 0;
    // 0x800226C8: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x800226CC: addiu       $s3, $s3, -0x3184
    ctx->r19 = ADD32(ctx->r19, -0X3184);
    // 0x800226D0: addiu       $s4, $zero, 0xFF
    ctx->r20 = ADD32(0, 0XFF);
L_800226D4:
    // 0x800226D4: lbu         $t6, 0x0($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X0);
    // 0x800226D8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800226DC: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x800226E0: addu        $t8, $s3, $t7
    ctx->r24 = ADD32(ctx->r19, ctx->r15);
    // 0x800226E4: lbu         $a2, 0x0($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X0);
    // 0x800226E8: beql        $a2, $s4, L_800226FC
    if (ctx->r6 == ctx->r20) {
        // 0x800226EC: addiu       $s0, $s0, -0x1
        ctx->r16 = ADD32(ctx->r16, -0X1);
            goto L_800226FC;
    }
    goto skip_0;
    // 0x800226EC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    skip_0:
    // 0x800226F0: jal         0x800224C0
    // 0x800226F4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    syDebugFramebufferWriteGlyph(rdram, ctx);
        goto after_1;
    // 0x800226F4: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    after_1:
    // 0x800226F8: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
L_800226FC:
    // 0x800226FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80022700: bne         $s0, $zero, L_800226D4
    if (ctx->r16 != 0) {
        // 0x80022704: addiu       $s2, $s2, 0x6
        ctx->r18 = ADD32(ctx->r18, 0X6);
            goto L_800226D4;
    }
    // 0x80022704: addiu       $s2, $s2, 0x6
    ctx->r18 = ADD32(ctx->r18, 0X6);
L_80022708:
    // 0x80022708: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002270C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80022710: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80022714: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80022718: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002271C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80022720: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80022724: jr          $ra
    // 0x80022728: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
    return;
    // 0x80022728: addiu       $sp, $sp, 0x140
    ctx->r29 = ADD32(ctx->r29, 0X140);
;}
RECOMP_FUNC void ftPikachuSpecialAirLwStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80151EA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80151EA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80151EAC: jal         0x80151E44
    // 0x80151EB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftPikachuSpecialLwStartUpdateThunder(rdram, ctx);
        goto after_0;
    // 0x80151EB0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80151EB4: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80151EB8: addiu       $a1, $a1, 0x23B0
    ctx->r5 = ADD32(ctx->r5, 0X23B0);
    // 0x80151EBC: jal         0x800D9480
    // 0x80151EC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_1;
    // 0x80151EC0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80151EC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151EC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80151ECC: jr          $ra
    // 0x80151ED0: nop

    return;
    // 0x80151ED0: nop

;}
RECOMP_FUNC void ftCommonFireFlowerShootAirSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147774: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80147778: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014777C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80147780: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80147784: jal         0x800DEE98
    // 0x80147788: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80147788: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014778C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80147790: addiu       $a1, $zero, 0x90
    ctx->r5 = ADD32(0, 0X90);
    // 0x80147794: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x80147798: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8014779C: lw          $a3, 0x78($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X78);
    // 0x801477A0: jal         0x800E6F24
    // 0x801477A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801477A4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801477A8: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x801477AC: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801477B0: addiu       $t8, $t8, 0x7434
    ctx->r24 = ADD32(ctx->r24, 0X7434);
    // 0x801477B4: sw          $t8, 0x9D8($t9)
    MEM_W(0X9D8, ctx->r25) = ctx->r24;
    // 0x801477B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801477BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801477C0: jr          $ra
    // 0x801477C4: nop

    return;
    // 0x801477C4: nop

;}
RECOMP_FUNC void func_ovl31_80135FE8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135FE8: jr          $ra
    // 0x80135FEC: nop

    return;
    // 0x80135FEC: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNReleaseProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F3A4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F3A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F3AC: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F3B0: jal         0x800DDDDC
    // 0x8015F3B4: addiu       $a1, $a1, -0xA90
    ctx->r5 = ADD32(ctx->r5, -0XA90);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015F3B4: addiu       $a1, $a1, -0xA90
    ctx->r5 = ADD32(ctx->r5, -0XA90);
    after_0:
    // 0x8015F3B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F3BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F3C0: jr          $ra
    // 0x8015F3C4: nop

    return;
    // 0x8015F3C4: nop

;}
RECOMP_FUNC void ftPhysicsGetAirVelTransN(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D9260: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800D9264: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D9268: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800D926C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800D9270: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x800D9274: lw          $t6, 0x44($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X44);
    // 0x800D9278: lw          $v0, 0x8EC($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8EC);
    // 0x800D927C: lwc1        $f6, 0x1A4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1A4);
    // 0x800D9280: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800D9284: lwc1        $f4, 0x24($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X24);
    // 0x800D9288: lw          $v1, 0x8E8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8E8);
    // 0x800D928C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800D9290: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800D9294: lwc1        $f4, 0x48($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X48);
    // 0x800D9298: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800D929C: nop

    // 0x800D92A0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800D92A4: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x800D92A8: lwc1        $f8, 0x1A0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X1A0);
    // 0x800D92AC: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800D92B0: lwc1        $f18, 0x44($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X44);
    // 0x800D92B4: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800D92B8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800D92BC: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x800D92C0: lwc1        $f12, 0x38($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800D92C4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800D92C8: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800D92CC: jal         0x80035CD0
    // 0x800D92D0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    __cosf_recomp(rdram, ctx);
        goto after_0;
    // 0x800D92D0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_0:
    // 0x800D92D4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800D92D8: lwc1        $f12, 0x38($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800D92DC: jal         0x800303F0
    // 0x800D92E0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x800D92E0: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800D92E4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x800D92E8: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x800D92EC: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800D92F0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800D92F4: beq         $a1, $zero, L_800D9318
    if (ctx->r5 == 0) {
        // 0x800D92F8: lwc1        $f2, 0x1C($sp)
        ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_800D9318;
    }
    // 0x800D92F8: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800D92FC: lwc1        $f6, 0x24($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800D9300: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D9304: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800D9308: nop

    // 0x800D930C: mul.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800D9310: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x800D9314: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
L_800D9318:
    // 0x800D9318: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800D931C: lwc1        $f4, 0x24($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800D9320: lwc1        $f8, 0x20($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800D9324: beql        $a1, $zero, L_800D9344
    if (ctx->r5 == 0) {
        // 0x800D9328: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_800D9344;
    }
    goto skip_0;
    // 0x800D9328: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    skip_0:
    // 0x800D932C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800D9330: nop

    // 0x800D9334: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800D9338: add.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800D933C: swc1        $f16, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f16.u32l;
    // 0x800D9340: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_800D9344:
    // 0x800D9344: beql        $a1, $zero, L_800D9380
    if (ctx->r5 == 0) {
        // 0x800D9348: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D9380;
    }
    goto skip_1;
    // 0x800D9348: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800D934C: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x800D9350: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800D9354: lwc1        $f4, 0x19C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X19C);
    // 0x800D9358: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800D935C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800D9360: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800D9364: lwc1        $f18, 0x40($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X40);
    // 0x800D9368: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800D936C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800D9370: nop

    // 0x800D9374: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800D9378: swc1        $f4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f4.u32l;
    // 0x800D937C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D9380:
    // 0x800D9380: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800D9384: jr          $ra
    // 0x800D9388: nop

    return;
    // 0x800D9388: nop

;}
RECOMP_FUNC void n_alSynAllocFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FE30: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8002FE34: lw          $t6, -0x2CEC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CEC);
    // 0x8002FE38: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8002FE3C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002FE40: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8002FE44: lw          $t7, 0x40($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X40);
    // 0x8002FE48: sll         $a3, $a0, 16
    ctx->r7 = S32(ctx->r4 << 16);
    // 0x8002FE4C: sra         $a3, $a3, 16
    ctx->r7 = S32(SIGNED(ctx->r7) >> 16);
    // 0x8002FE50: sll         $v1, $a3, 2
    ctx->r3 = S32(ctx->r7 << 2);
    // 0x8002FE54: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    // 0x8002FE58: addiu       $a0, $a0, 0x24
    ctx->r4 = ADD32(ctx->r4, 0X24);
    // 0x8002FE5C: jal         0x8002D218
    // 0x8002FE60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    n_alFxNew(rdram, ctx);
        goto after_0;
    // 0x8002FE60: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8002FE64: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002FE68: lw          $t8, -0x2CEC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2CEC);
    // 0x8002FE6C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8002FE70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002FE74: lw          $t9, 0x40($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X40);
    // 0x8002FE78: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8002FE7C: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x8002FE80: jr          $ra
    // 0x8002FE84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8002FE84: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl56_80132F78(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132F78: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80132F7C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80132F80: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x80132F84: addiu       $s2, $s2, 0x53A4
    ctx->r18 = ADD32(ctx->r18, 0X53A4);
    // 0x80132F88: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80132F8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132F90: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80132F94: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80132F98: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80132F9C: blez        $t6, L_80132FDC
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80132FA0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80132FDC;
    }
    // 0x80132FA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80132FA4: lui         $at, 0x42BA
    ctx->r1 = S32(0X42BA << 16);
    // 0x80132FA8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80132FAC: addiu       $s1, $zero, 0x82
    ctx->r17 = ADD32(0, 0X82);
    // 0x80132FB0: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
L_80132FB4:
    // 0x80132FB4: mov.s       $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    ctx->f14.fl = ctx->f20.fl;
    // 0x80132FB8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x80132FBC: jal         0x80132E40
    // 0x80132FC0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    func_ovl56_80132E40(rdram, ctx);
        goto after_0;
    // 0x80132FC0: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80132FC4: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80132FC8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80132FCC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80132FD0: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80132FD4: bnel        $at, $zero, L_80132FB4
    if (ctx->r1 != 0) {
        // 0x80132FD8: mtc1        $s1, $f4
        ctx->f4.u32l = ctx->r17;
            goto L_80132FB4;
    }
    goto skip_0;
    // 0x80132FD8: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    skip_0:
L_80132FDC:
    // 0x80132FDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80132FE0: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80132FE4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132FE8: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80132FEC: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80132FF0: jr          $ra
    // 0x80132FF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80132FF4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayersVSPuckProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801388F8: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801388FC: lw          $t6, -0x4234($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4234);
    // 0x80138900: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80138904: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80138908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013890C: slti        $at, $t6, 0x1E
    ctx->r1 = SIGNED(ctx->r14) < 0X1E ? 1 : 0;
    // 0x80138910: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80138914: beq         $at, $zero, L_80138954
    if (ctx->r1 == 0) {
        // 0x80138918: lw          $s0, 0x84($a0)
        ctx->r16 = MEM_W(ctx->r4, 0X84);
            goto L_80138954;
    }
    // 0x80138918: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8013891C: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80138920: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x80138924: sll         $t8, $t8, 4
    ctx->r24 = S32(ctx->r24 << 4);
    // 0x80138928: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8013892C: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80138930: addiu       $t9, $t9, -0x4578
    ctx->r25 = ADD32(ctx->r25, -0X4578);
    // 0x80138934: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80138938: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8013893C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80138940: addiu       $a2, $a2, -0x4578
    ctx->r6 = ADD32(ctx->r6, -0X4578);
    // 0x80138944: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    // 0x80138948: addu        $a3, $t8, $t9
    ctx->r7 = ADD32(ctx->r24, ctx->r25);
    // 0x8013894C: b           L_801389BC
    // 0x80138950: addiu       $t0, $zero, 0xBC
    ctx->r8 = ADD32(0, 0XBC);
        goto L_801389BC;
    // 0x80138950: addiu       $t0, $zero, 0xBC
    ctx->r8 = ADD32(0, 0XBC);
L_80138954:
    // 0x80138954: addiu       $t0, $zero, 0xBC
    ctx->r8 = ADD32(0, 0XBC);
    // 0x80138958: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8013895C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80138960: addiu       $a2, $a2, -0x4578
    ctx->r6 = ADD32(ctx->r6, -0X4578);
    // 0x80138964: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80138968: mflo        $t1
    ctx->r9 = lo;
    // 0x8013896C: addu        $a3, $a2, $t1
    ctx->r7 = ADD32(ctx->r6, ctx->r9);
    // 0x80138970: lw          $v1, 0x84($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X84);
    // 0x80138974: beq         $v1, $at, L_801389B0
    if (ctx->r3 == ctx->r1) {
        // 0x80138978: nop
    
            goto L_801389B0;
    }
    // 0x80138978: nop

    // 0x8013897C: bne         $v1, $zero, L_801389B8
    if (ctx->r3 != 0) {
        // 0x80138980: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_801389B8;
    }
    // 0x80138980: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80138984: lw          $t2, 0x54($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X54);
    // 0x80138988: bne         $t2, $zero, L_801389B0
    if (ctx->r10 != 0) {
        // 0x8013898C: nop
    
            goto L_801389B0;
    }
    // 0x8013898C: nop

    // 0x80138990: lw          $t3, 0x58($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X58);
    // 0x80138994: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80138998: beq         $t3, $at, L_801389B0
    if (ctx->r11 == ctx->r1) {
        // 0x8013899C: nop
    
            goto L_801389B0;
    }
    // 0x8013899C: nop

    // 0x801389A0: lw          $t4, 0x5C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X5C);
    // 0x801389A4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801389A8: bnel        $t4, $at, L_801389BC
    if (ctx->r12 != ctx->r1) {
        // 0x801389AC: sw          $t5, 0x7C($a1)
        MEM_W(0X7C, ctx->r5) = ctx->r13;
            goto L_801389BC;
    }
    goto skip_0;
    // 0x801389AC: sw          $t5, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->r13;
    skip_0:
L_801389B0:
    // 0x801389B0: b           L_801389BC
    // 0x801389B4: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
        goto L_801389BC;
    // 0x801389B4: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
L_801389B8:
    // 0x801389B8: sw          $t5, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = ctx->r13;
L_801389BC:
    // 0x801389BC: lw          $t6, 0x58($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X58);
    // 0x801389C0: bnel        $t6, $zero, L_80138A50
    if (ctx->r14 != 0) {
        // 0x801389C4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80138A50;
    }
    goto skip_1;
    // 0x801389C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_1:
    // 0x801389C8: lw          $a0, 0x7C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X7C);
    // 0x801389CC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x801389D0: beql        $a0, $at, L_80138A50
    if (ctx->r4 == ctx->r1) {
        // 0x801389D4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80138A50;
    }
    goto skip_2;
    // 0x801389D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_2:
    // 0x801389D8: multu       $a0, $t0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801389DC: mflo        $t7
    ctx->r15 = lo;
    // 0x801389E0: addu        $v0, $a2, $t7
    ctx->r2 = ADD32(ctx->r6, ctx->r15);
    // 0x801389E4: lw          $t8, 0xA0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XA0);
    // 0x801389E8: bnel        $t8, $zero, L_80138A60
    if (ctx->r24 != 0) {
        // 0x801389EC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80138A60;
    }
    goto skip_3;
    // 0x801389EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_3:
    // 0x801389F0: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x801389F4: beql        $v1, $zero, L_80138A60
    if (ctx->r3 == 0) {
        // 0x801389F8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80138A60;
    }
    goto skip_4;
    // 0x801389F8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_4:
    // 0x801389FC: lw          $t9, 0x74($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X74);
    // 0x80138A00: lui         $at, 0x4130
    ctx->r1 = S32(0X4130 << 16);
    // 0x80138A04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80138A08: lwc1        $f4, 0x58($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X58);
    // 0x80138A0C: lw          $t1, 0x74($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X74);
    // 0x80138A10: lui         $at, 0xC160
    ctx->r1 = S32(0XC160 << 16);
    // 0x80138A14: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80138A18: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80138A1C: swc1        $f8, 0x58($t1)
    MEM_W(0X58, ctx->r9) = ctx->f8.u32l;
    // 0x80138A20: lw          $t2, 0x7C($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X7C);
    // 0x80138A24: lw          $t7, 0x74($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X74);
    // 0x80138A28: multu       $t2, $t0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80138A2C: mflo        $t3
    ctx->r11 = lo;
    // 0x80138A30: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x80138A34: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x80138A38: lw          $t6, 0x74($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X74);
    // 0x80138A3C: lwc1        $f10, 0x5C($t6)
    ctx->f10.u32l = MEM_W(ctx->r14, 0X5C);
    // 0x80138A40: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80138A44: b           L_80138A5C
    // 0x80138A48: swc1        $f18, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f18.u32l;
        goto L_80138A5C;
    // 0x80138A48: swc1        $f18, 0x5C($t7)
    MEM_W(0X5C, ctx->r15) = ctx->f18.u32l;
    // 0x80138A4C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80138A50:
    // 0x80138A50: jal         0x801388A4
    // 0x80138A54: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    mnPlayersVSMovePuck(rdram, ctx);
        goto after_0;
    // 0x80138A54: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x80138A58: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
L_80138A5C:
    // 0x80138A5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80138A60:
    // 0x80138A60: jal         0x8013782C
    // 0x80138A64: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    mnPlayersVSGetPuckFighterKind(rdram, ctx);
        goto after_1;
    // 0x80138A64: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_1:
    // 0x80138A68: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80138A6C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80138A70: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x80138A74: lw          $v1, 0x84($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X84);
    // 0x80138A78: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80138A7C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80138A80: bne         $v1, $at, L_80138AE0
    if (ctx->r3 != ctx->r1) {
        // 0x80138A84: addu        $t9, $t9, $t8
        ctx->r25 = ADD32(ctx->r25, ctx->r24);
            goto L_80138AE0;
    }
    // 0x80138A84: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80138A88: lw          $t9, -0x4270($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4270);
    // 0x80138A8C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80138A90: beq         $t9, $at, L_80138B58
    if (ctx->r25 == ctx->r1) {
        // 0x80138A94: addiu       $at, $zero, 0x1C
        ctx->r1 = ADD32(0, 0X1C);
            goto L_80138B58;
    }
    // 0x80138A94: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80138A98: beq         $v0, $at, L_80138B58
    if (ctx->r2 == ctx->r1) {
        // 0x80138A9C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80138B58;
    }
    // 0x80138A9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80138AA0: sw          $zero, 0x84($a3)
    MEM_W(0X84, ctx->r7) = 0;
    // 0x80138AA4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80138AA8: jal         0x80135C84
    // 0x80138AAC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    mnPlayersVSUpdatePlayerKind(rdram, ctx);
        goto after_2;
    // 0x80138AAC: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80138AB0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80138AB4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80138AB8: lw          $a0, 0xC($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XC);
    // 0x80138ABC: jal         0x8013295C
    // 0x80138AC0: lw          $a2, 0x84($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X84);
    mnPlayersVSUpdatePlayerKindSelect(rdram, ctx);
        goto after_3;
    // 0x80138AC0: lw          $a2, 0x84($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X84);
    after_3:
    // 0x80138AC4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80138AC8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80138ACC: jal         0x80136038
    // 0x80138AD0: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    mnPlayersVSUpdatePuckDisplay(rdram, ctx);
        goto after_4;
    // 0x80138AD0: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    after_4:
    // 0x80138AD4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80138AD8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80138ADC: lw          $v1, 0x84($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X84);
L_80138AE0:
    // 0x80138AE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80138AE4: bnel        $v1, $at, L_80138B30
    if (ctx->r3 != ctx->r1) {
        // 0x80138AE8: lw          $t2, 0x58($a3)
        ctx->r10 = MEM_W(ctx->r7, 0X58);
            goto L_80138B30;
    }
    goto skip_5;
    // 0x80138AE8: lw          $t2, 0x58($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X58);
    skip_5:
    // 0x80138AEC: lw          $t1, 0x48($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X48);
    // 0x80138AF0: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80138AF4: beql        $t0, $t1, L_80138B30
    if (ctx->r8 == ctx->r9) {
        // 0x80138AF8: lw          $t2, 0x58($a3)
        ctx->r10 = MEM_W(ctx->r7, 0X58);
            goto L_80138B30;
    }
    goto skip_6;
    // 0x80138AF8: lw          $t2, 0x58($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X58);
    skip_6:
    // 0x80138AFC: bnel        $t0, $at, L_80138B30
    if (ctx->r8 != ctx->r1) {
        // 0x80138B00: lw          $t2, 0x58($a3)
        ctx->r10 = MEM_W(ctx->r7, 0X58);
            goto L_80138B30;
    }
    goto skip_7;
    // 0x80138B00: lw          $t2, 0x58($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X58);
    skip_7:
    // 0x80138B04: lw          $a0, 0x7C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X7C);
    // 0x80138B08: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80138B0C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80138B10: beql        $a0, $at, L_80138B30
    if (ctx->r4 == ctx->r1) {
        // 0x80138B14: lw          $t2, 0x58($a3)
        ctx->r10 = MEM_W(ctx->r7, 0X58);
            goto L_80138B30;
    }
    goto skip_8;
    // 0x80138B14: lw          $t2, 0x58($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X58);
    skip_8:
    // 0x80138B18: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80138B1C: jal         0x80131C74
    // 0x80138B20: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    mnPlayersVSSelectFighterPuck(rdram, ctx);
        goto after_5;
    // 0x80138B20: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_5:
    // 0x80138B24: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80138B28: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80138B2C: lw          $t2, 0x58($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X58);
L_80138B30:
    // 0x80138B30: bnel        $t2, $zero, L_80138B5C
    if (ctx->r10 != 0) {
        // 0x80138B34: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80138B5C;
    }
    goto skip_9;
    // 0x80138B34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_9:
    // 0x80138B38: lw          $t3, 0x48($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X48);
    // 0x80138B3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80138B40: beql        $t0, $t3, L_80138B5C
    if (ctx->r8 == ctx->r11) {
        // 0x80138B44: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80138B5C;
    }
    goto skip_10;
    // 0x80138B44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_10:
    // 0x80138B48: jal         0x80136128
    // 0x80138B4C: sw          $t0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r8;
    mnPlayersVSUpdateFighter(rdram, ctx);
        goto after_6;
    // 0x80138B4C: sw          $t0, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r8;
    after_6:
    // 0x80138B50: jal         0x80136300
    // 0x80138B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayersVSUpdateNameAndEmblem(rdram, ctx);
        goto after_7;
    // 0x80138B54: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_80138B58:
    // 0x80138B58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80138B5C:
    // 0x80138B5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80138B60: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80138B64: jr          $ra
    // 0x80138B68: nop

    return;
    // 0x80138B68: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialNDestroyBoomerang(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164650: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80164654: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164658: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016465C: lw          $a1, 0xAF8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0XAF8);
    // 0x80164660: beq         $a1, $zero, L_80164678
    if (ctx->r5 == 0) {
        // 0x80164664: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80164678;
    }
    // 0x80164664: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80164668: jal         0x8016800C
    // 0x8016466C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    wpMainDestroyWeapon(rdram, ctx);
        goto after_0;
    // 0x8016466C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80164670: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80164674: sw          $zero, 0xAF8($v0)
    MEM_W(0XAF8, ctx->r2) = 0;
L_80164678:
    // 0x80164678: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016467C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80164680: jr          $ra
    // 0x80164684: nop

    return;
    // 0x80164684: nop

;}
RECOMP_FUNC void ftBossOkupunch2ProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A840: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A844: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A848: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8015A84C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015A850: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015A854: nop

    // 0x8015A858: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015A85C: nop

    // 0x8015A860: bc1fl       L_8015A884
    if (!c1cs) {
        // 0x8015A864: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015A884;
    }
    goto skip_0;
    // 0x8015A864: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015A868: jal         0x8010CF20
    // 0x8015A86C: nop

    gmCameraSetStatusDefault(rdram, ctx);
        goto after_0;
    // 0x8015A86C: nop

    after_0:
    // 0x8015A870: jal         0x8015AA34
    // 0x8015A874: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftBossOkupunch3SetStatus(rdram, ctx);
        goto after_1;
    // 0x8015A874: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8015A878: jal         0x80158620
    // 0x8015A87C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftBossCommonSetDisableFogColor(rdram, ctx);
        goto after_2;
    // 0x8015A87C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8015A880: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015A884:
    // 0x8015A884: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A888: jr          $ra
    // 0x8015A88C: nop

    return;
    // 0x8015A88C: nop

;}
RECOMP_FUNC void itStarRodMakeItem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178134: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80178138: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x8017813C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80178140: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80178144: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80178148: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8017814C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80178150: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80178154: lw          $a3, 0x30($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X30);
    // 0x80178158: addiu       $a1, $a1, -0x5F10
    ctx->r5 = ADD32(ctx->r5, -0X5F10);
    // 0x8017815C: jal         0x8016E174
    // 0x80178160: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    itManagerMakeItem(rdram, ctx);
        goto after_0;
    // 0x80178160: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x80178164: beq         $v0, $zero, L_8017819C
    if (ctx->r2 == 0) {
        // 0x80178168: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8017819C;
    }
    // 0x80178168: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8017816C: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x80178170: addiu       $t7, $zero, 0x14
    ctx->r15 = ADD32(0, 0X14);
    // 0x80178174: lbu         $t9, 0x2D3($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2D3);
    // 0x80178178: sh          $t7, 0x33E($a0)
    MEM_H(0X33E, ctx->r4) = ctx->r15;
    // 0x8017817C: ori         $t0, $t9, 0x4
    ctx->r8 = ctx->r25 | 0X4;
    // 0x80178180: sb          $t0, 0x2D3($a0)
    MEM_B(0X2D3, ctx->r4) = ctx->r8;
    // 0x80178184: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80178188: jal         0x80111EC0
    // 0x8017818C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ifCommonItemArrowMakeInterface(rdram, ctx);
        goto after_1;
    // 0x8017818C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x80178190: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80178194: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x80178198: sw          $v0, 0x348($a0)
    MEM_W(0X348, ctx->r4) = ctx->r2;
L_8017819C:
    // 0x8017819C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801781A0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801781A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801781A8: jr          $ra
    // 0x801781AC: nop

    return;
    // 0x801781AC: nop

;}
RECOMP_FUNC void gcMakeGObjBefore(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009A34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009A3C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80009A40: or          $t6, $a2, $zero
    ctx->r14 = ctx->r6 | 0;
    // 0x80009A44: lw          $a3, 0x10($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X10);
    // 0x80009A48: jal         0x800098A4
    // 0x80009A4C: lbu         $a2, 0xC($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XC);
    gcInitGObjCommon(rdram, ctx);
        goto after_0;
    // 0x80009A4C: lbu         $a2, 0xC($a2)
    ctx->r6 = MEM_BU(ctx->r6, 0XC);
    after_0:
    // 0x80009A50: bne         $v0, $zero, L_80009A60
    if (ctx->r2 != 0) {
        // 0x80009A54: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80009A60;
    }
    // 0x80009A54: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80009A58: b           L_80009A74
    // 0x80009A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80009A74;
    // 0x80009A5C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009A60:
    // 0x80009A60: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80009A64: lw          $a1, 0x8($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X8);
    // 0x80009A68: jal         0x800079D4
    // 0x80009A6C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    gcLinkGObjAfter(rdram, ctx);
        goto after_1;
    // 0x80009A6C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80009A70: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_80009A74:
    // 0x80009A74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80009A78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009A7C: jr          $ra
    // 0x80009A80: nop

    return;
    // 0x80009A80: nop

;}
RECOMP_FUNC void mvOpeningLinkStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E018: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E01C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E020: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E024: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x8018E028: addiu       $a0, $a0, -0x1F24
    ctx->r4 = ADD32(ctx->r4, -0X1F24);
    // 0x8018E02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E030: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x8018E034: jal         0x80007024
    // 0x8018E038: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x8018E038: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x8018E03C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x8018E040: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018E044: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E048: addiu       $t9, $t9, -0x1A20
    ctx->r25 = ADD32(ctx->r25, -0X1A20);
    // 0x8018E04C: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x8018E050: addiu       $a0, $a0, -0x1F08
    ctx->r4 = ADD32(ctx->r4, -0X1F08);
    // 0x8018E054: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x8018E058: jal         0x8000683C
    // 0x8018E05C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x8018E05C: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x8018E060: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E064: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E068: jr          $ra
    // 0x8018E06C: nop

    return;
    // 0x8018E06C: nop

;}
RECOMP_FUNC void itGLuckyCommonUpdateEggSpawn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C280: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8017C284: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8017C288: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017C28C: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8017C290: lw          $a1, 0x74($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X74);
    // 0x8017C294: lhu         $t6, 0x33E($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X33E);
    // 0x8017C298: bnel        $t6, $zero, L_8017C3D4
    if (ctx->r14 != 0) {
        // 0x8017C29C: lhu         $t1, 0x35C($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X35C);
            goto L_8017C3D4;
    }
    goto skip_0;
    // 0x8017C29C: lhu         $t1, 0x35C($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X35C);
    skip_0:
    // 0x8017C2A0: lhu         $v0, 0x35C($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X35C);
    // 0x8017C2A4: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x8017C2A8: beql        $v0, $zero, L_8017C3D4
    if (ctx->r2 == 0) {
        // 0x8017C2AC: lhu         $t1, 0x35C($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X35C);
            goto L_8017C3D4;
    }
    goto skip_1;
    // 0x8017C2AC: lhu         $t1, 0x35C($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X35C);
    skip_1:
    // 0x8017C2B0: lw          $v1, 0x50E8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X50E8);
    // 0x8017C2B4: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8017C2B8: lw          $t7, 0xC($v1)
    ctx->r15 = MEM_W(ctx->r3, 0XC);
    // 0x8017C2BC: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x8017C2C0: beql        $t8, $zero, L_8017C3C8
    if (ctx->r24 == 0) {
        // 0x8017C2C4: addiu       $t9, $zero, 0xA
        ctx->r25 = ADD32(0, 0XA);
            goto L_8017C3C8;
    }
    goto skip_2;
    // 0x8017C2C4: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    skip_2:
    // 0x8017C2C8: lbu         $t9, 0x1C($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1C);
    // 0x8017C2CC: beql        $t9, $zero, L_8017C3C8
    if (ctx->r25 == 0) {
        // 0x8017C2D0: addiu       $t9, $zero, 0xA
        ctx->r25 = ADD32(0, 0XA);
            goto L_8017C3C8;
    }
    goto skip_3;
    // 0x8017C2D0: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    skip_3:
    // 0x8017C2D4: lw          $t2, 0x1C($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X1C);
    // 0x8017C2D8: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x8017C2DC: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x8017C2E0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8017C2E4: lw          $t1, 0x20($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X20);
    // 0x8017C2E8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017C2EC: sw          $t1, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r9;
    // 0x8017C2F0: lw          $t2, 0x24($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X24);
    // 0x8017C2F4: sw          $t2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r10;
    // 0x8017C2F8: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8017C2FC: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8017C300: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8017C304: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x8017C308: add.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x8017C30C: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x8017C310: jal         0x80018948
    // 0x8017C314: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x8017C314: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    after_0:
    // 0x8017C318: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017C31C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8017C320: nop

    // 0x8017C324: mul.s       $f16, $f0, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x8017C328: add.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x8017C32C: neg.s       $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = -ctx->f18.fl;
    // 0x8017C330: jal         0x80018948
    // 0x8017C334: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_1;
    // 0x8017C334: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8017C338: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8017C33C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017C340: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8017C344: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8017C348: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8017C34C: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8017C350: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8017C354: ori         $t3, $t3, 0x3
    ctx->r11 = ctx->r11 | 0X3;
    // 0x8017C358: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8017C35C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8017C360: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8017C364: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8017C368: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x8017C36C: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x8017C370: swc1        $f18, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f18.u32l;
    // 0x8017C374: jal         0x8016EA78
    // 0x8017C378: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_2;
    // 0x8017C378: swc1        $f16, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8017C37C: beql        $v0, $zero, L_8017C3D4
    if (ctx->r2 == 0) {
        // 0x8017C380: lhu         $t1, 0x35C($s0)
        ctx->r9 = MEM_HU(ctx->r16, 0X35C);
            goto L_8017C3D4;
    }
    goto skip_4;
    // 0x8017C380: lhu         $t1, 0x35C($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X35C);
    skip_4:
    // 0x8017C384: lw          $t4, 0x84($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X84);
    // 0x8017C388: addiu       $a0, $zero, 0xCA
    ctx->r4 = ADD32(0, 0XCA);
    // 0x8017C38C: jal         0x800269C0
    // 0x8017C390: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x8017C390: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    after_3:
    // 0x8017C394: lhu         $t6, 0x35C($s0)
    ctx->r14 = MEM_HU(ctx->r16, 0X35C);
    // 0x8017C398: addiu       $t5, $zero, 0xA
    ctx->r13 = ADD32(0, 0XA);
    // 0x8017C39C: sh          $t5, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r13;
    // 0x8017C3A0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8017C3A4: sh          $t7, 0x35C($s0)
    MEM_H(0X35C, ctx->r16) = ctx->r15;
    // 0x8017C3A8: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8017C3AC: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    // 0x8017C3B0: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x8017C3B4: jal         0x800FF048
    // 0x8017C3B8: lw          $a1, 0x24($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X24);
    efManagerDustLightMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8017C3B8: lw          $a1, 0x24($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X24);
    after_4:
    // 0x8017C3BC: b           L_8017C3D4
    // 0x8017C3C0: lhu         $t1, 0x35C($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X35C);
        goto L_8017C3D4;
    // 0x8017C3C0: lhu         $t1, 0x35C($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X35C);
    // 0x8017C3C4: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
L_8017C3C8:
    // 0x8017C3C8: sh          $t9, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r25;
    // 0x8017C3CC: sh          $t0, 0x35C($s0)
    MEM_H(0X35C, ctx->r16) = ctx->r8;
    // 0x8017C3D0: lhu         $t1, 0x35C($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0X35C);
L_8017C3D4:
    // 0x8017C3D4: beql        $t1, $zero, L_8017C3F0
    if (ctx->r9 == 0) {
        // 0x8017C3D8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8017C3F0;
    }
    goto skip_5;
    // 0x8017C3D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x8017C3DC: lhu         $v0, 0x33E($s0)
    ctx->r2 = MEM_HU(ctx->r16, 0X33E);
    // 0x8017C3E0: blez        $v0, L_8017C3EC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8017C3E4: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8017C3EC;
    }
    // 0x8017C3E4: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8017C3E8: sh          $t2, 0x33E($s0)
    MEM_H(0X33E, ctx->r16) = ctx->r10;
L_8017C3EC:
    // 0x8017C3EC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8017C3F0:
    // 0x8017C3F0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8017C3F4: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x8017C3F8: jr          $ra
    // 0x8017C3FC: nop

    return;
    // 0x8017C3FC: nop

;}
RECOMP_FUNC void ftKirbyCopyPikachuSpecialAirNSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80153908: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015390C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80153910: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80153914: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80153918: addiu       $a1, $zero, 0xFD
    ctx->r5 = ADD32(0, 0XFD);
    // 0x8015391C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80153920: jal         0x800E6F24
    // 0x80153924: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80153924: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80153928: jal         0x800E0830
    // 0x8015392C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015392C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80153930: jal         0x801538B0
    // 0x80153934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbyCopyPikachuSpecialNInitStatusVars(rdram, ctx);
        goto after_2;
    // 0x80153934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80153938: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015393C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80153940: jr          $ra
    // 0x80153944: nop

    return;
    // 0x80153944: nop

;}
RECOMP_FUNC void mnPlayers1PGameFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138334: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80138338: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x8013833C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80138340: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80138344: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80138348: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013834C: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80138350: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80138354: addiu       $t8, $t8, -0x6D20
    ctx->r24 = ADD32(ctx->r24, -0X6D20);
    // 0x80138358: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x8013835C: addiu       $t0, $t0, -0x6D58
    ctx->r8 = ADD32(ctx->r8, -0X6D58);
    // 0x80138360: addiu       $t1, $zero, 0x7
    ctx->r9 = ADD32(0, 0X7);
    // 0x80138364: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80138368: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x8013836C: sw          $t7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r15;
    // 0x80138370: sw          $zero, 0x48($sp)
    MEM_W(0X48, ctx->r29) = 0;
    // 0x80138374: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80138378: sw          $t8, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r24;
    // 0x8013837C: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x80138380: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    // 0x80138384: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    // 0x80138388: jal         0x800CDF78
    // 0x8013838C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x8013838C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80138390: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80138394: addiu       $s0, $s0, -0x79D0
    ctx->r16 = ADD32(ctx->r16, -0X79D0);
    // 0x80138398: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013839C: jal         0x800CDEEC
    // 0x801383A0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x801383A0: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    after_1:
    // 0x801383A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801383A8: jal         0x80004980
    // 0x801383AC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x801383AC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x801383B0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x801383B4: addiu       $a2, $a2, -0x6960
    ctx->r6 = ADD32(ctx->r6, -0X6960);
    // 0x801383B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801383BC: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x801383C0: jal         0x800CDE04
    // 0x801383C4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x801383C4: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x801383C8: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x801383CC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801383D0: addiu       $a1, $a1, 0x7FCC
    ctx->r5 = ADD32(ctx->r5, 0X7FCC);
    // 0x801383D4: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x801383D8: addiu       $a0, $zero, 0x400
    ctx->r4 = ADD32(0, 0X400);
    // 0x801383DC: jal         0x80009968
    // 0x801383E0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x801383E0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    after_4:
    // 0x801383E4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x801383E8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x801383EC: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x801383F0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x801383F4: jal         0x8000B9FC
    // 0x801383F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x801383F8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x801383FC: jal         0x80115890
    // 0x80138400: nop

    efParticleInitAll(rdram, ctx);
        goto after_6;
    // 0x80138400: nop

    after_6:
    // 0x80138404: jal         0x800FD300
    // 0x80138408: nop

    efManagerInitEffects(rdram, ctx);
        goto after_7;
    // 0x80138408: nop

    after_7:
    // 0x8013840C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80138410: jal         0x800D7194
    // 0x80138414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftManagerAllocFighter(rdram, ctx);
        goto after_8;
    // 0x80138414: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80138418: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8013841C:
    // 0x8013841C: jal         0x800D786C
    // 0x80138420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_9;
    // 0x80138420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80138424: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80138428: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8013842C: bne         $s0, $at, L_8013841C
    if (ctx->r16 != ctx->r1) {
        // 0x80138430: nop
    
            goto L_8013841C;
    }
    // 0x80138430: nop

    // 0x80138434: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80138438: lw          $a0, 0xD9C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD9C);
    // 0x8013843C: jal         0x80004980
    // 0x80138440: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_10;
    // 0x80138440: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_10:
    // 0x80138444: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80138448: jal         0x801381D8
    // 0x8013844C: sw          $v0, -0x703C($at)
    MEM_W(-0X703C, ctx->r1) = ctx->r2;
    mnPlayers1PGameInitVars(rdram, ctx);
        goto after_11;
    // 0x8013844C: sw          $v0, -0x703C($at)
    MEM_W(-0X703C, ctx->r1) = ctx->r2;
    after_11:
    // 0x80138450: jal         0x80132F1C
    // 0x80138454: nop

    mnPlayers1PGameMakePortraitCamera(rdram, ctx);
        goto after_12;
    // 0x80138454: nop

    after_12:
    // 0x80138458: jal         0x80137268
    // 0x8013845C: nop

    mnPlayers1PGameMakeCursorCamera(rdram, ctx);
        goto after_13;
    // 0x8013845C: nop

    after_13:
    // 0x80138460: jal         0x80137308
    // 0x80138464: nop

    mnPlayers1PGameMakePuckCamera(rdram, ctx);
        goto after_14;
    // 0x80138464: nop

    after_14:
    // 0x80138468: jal         0x801330FC
    // 0x8013846C: nop

    mnPlayers1PGameMakePlayerKindCamera(rdram, ctx);
        goto after_15;
    // 0x8013846C: nop

    after_15:
    // 0x80138470: jal         0x801351CC
    // 0x80138474: nop

    mnPlayers1PGameMakeFighterCamera(rdram, ctx);
        goto after_16;
    // 0x80138474: nop

    after_16:
    // 0x80138478: jal         0x80132FBC
    // 0x8013847C: nop

    mnPlayers1PGameMakePortraitWallpaperCamera(rdram, ctx);
        goto after_17;
    // 0x8013847C: nop

    after_17:
    // 0x80138480: jal         0x8013305C
    // 0x80138484: nop

    mnPlayers1PGameMakePortraitFlashCamera(rdram, ctx);
        goto after_18;
    // 0x80138484: nop

    after_18:
    // 0x80138488: jal         0x80133990
    // 0x8013848C: nop

    mnPlayers1PGameMakeWallpaperCamera(rdram, ctx);
        goto after_19;
    // 0x8013848C: nop

    after_19:
    // 0x80138490: jal         0x801346B8
    // 0x80138494: nop

    mnPlayers1PGameMakeLabelsCamera(rdram, ctx);
        goto after_20;
    // 0x80138494: nop

    after_20:
    // 0x80138498: jal         0x801373A8
    // 0x8013849C: nop

    mnPlayers1PGameMakeReadyCamera(rdram, ctx);
        goto after_21;
    // 0x8013849C: nop

    after_21:
    // 0x801384A0: jal         0x801338EC
    // 0x801384A4: nop

    mnPlayers1PGameMakeWallpaper(rdram, ctx);
        goto after_22;
    // 0x801384A4: nop

    after_22:
    // 0x801384A8: jal         0x80132D60
    // 0x801384AC: nop

    mnPlayers1PGameMakePortraitAll(rdram, ctx);
        goto after_23;
    // 0x801384AC: nop

    after_23:
    // 0x801384B0: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801384B4: jal         0x801382C8
    // 0x801384B8: lw          $a0, -0x7058($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7058);
    mnPlayers1PGameInitSlot(rdram, ctx);
        goto after_24;
    // 0x801384B8: lw          $a0, -0x7058($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7058);
    after_24:
    // 0x801384BC: jal         0x801343C8
    // 0x801384C0: nop

    mnPlayers1PGameMakeLabels(rdram, ctx);
        goto after_25;
    // 0x801384C0: nop

    after_25:
    // 0x801384C4: jal         0x80134E88
    // 0x801384C8: nop

    mnPlayers1PGameMakeTotalRecord(rdram, ctx);
        goto after_26;
    // 0x801384C8: nop

    after_26:
    // 0x801384CC: jal         0x80133F30
    // 0x801384D0: nop

    mnPlayers1PGameMakeLevelOption(rdram, ctx);
        goto after_27;
    // 0x801384D0: nop

    after_27:
    // 0x801384D4: jal         0x8013434C
    // 0x801384D8: nop

    mnPlayers1PGameMakeStockOption(rdram, ctx);
        goto after_28;
    // 0x801384D8: nop

    after_28:
    // 0x801384DC: jal         0x801379E8
    // 0x801384E0: nop

    mnPlayers1PGameMakePuckAdjust(rdram, ctx);
        goto after_29;
    // 0x801384E0: nop

    after_29:
    // 0x801384E4: jal         0x80137B04
    // 0x801384E8: nop

    mnPlayers1PGameMakeSpotlight(rdram, ctx);
        goto after_30;
    // 0x801384E8: nop

    after_30:
    // 0x801384EC: jal         0x80137C64
    // 0x801384F0: nop

    mnPlayers1PGameMakeReady(rdram, ctx);
        goto after_31;
    // 0x801384F0: nop

    after_31:
    // 0x801384F4: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x801384F8: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x801384FC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x80138500: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80138504: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x80138508: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8013850C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80138510: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x80138514: jal         0x803904E0
    // 0x80138518: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    scSubsysFighterSetLightParams(rdram, ctx);
        goto after_32;
    // 0x80138518: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    after_32:
    // 0x8013851C: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x80138520: lbu         $t4, 0x4AD1($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4AD1);
    // 0x80138524: addiu       $at, $zero, 0x15
    ctx->r1 = ADD32(0, 0X15);
    // 0x80138528: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013852C: beq         $t4, $at, L_8013853C
    if (ctx->r12 == ctx->r1) {
        // 0x80138530: nop
    
            goto L_8013853C;
    }
    // 0x80138530: nop

    // 0x80138534: jal         0x80020AB4
    // 0x80138538: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    syAudioPlayBGM(rdram, ctx);
        goto after_33;
    // 0x80138538: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_33:
L_8013853C:
    // 0x8013853C: jal         0x800269C0
    // 0x80138540: addiu       $a0, $zero, 0x1DF
    ctx->r4 = ADD32(0, 0X1DF);
    func_800269C0_275C0(rdram, ctx);
        goto after_34;
    // 0x80138540: addiu       $a0, $zero, 0x1DF
    ctx->r4 = ADD32(0, 0X1DF);
    after_34:
    // 0x80138544: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80138548: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013854C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80138550: jr          $ra
    // 0x80138554: nop

    return;
    // 0x80138554: nop

;}
RECOMP_FUNC void dbMenuDrawCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80369680: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80369684: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x80369688: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8036968C: addu        $a1, $a1, $a2
    ctx->r5 = ADD32(ctx->r5, ctx->r6);
    // 0x80369690: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80369694: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80369698: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8036969C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x803696A0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x803696A4: jal         0x8037DFCC
    // 0x803696A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_ovl8_8037DFCC(rdram, ctx);
        goto after_0;
    // 0x803696A8: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_0:
    // 0x803696AC: jal         0x803749BC
    // 0x803696B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    func_ovl8_803749BC(rdram, ctx);
        goto after_1;
    // 0x803696B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x803696B4: lui         $a1, 0x8037
    ctx->r5 = S32(0X8037 << 16);
    // 0x803696B8: addiu       $a1, $a1, -0x5C50
    ctx->r5 = ADD32(ctx->r5, -0X5C50);
    // 0x803696BC: jal         0x80369310
    // 0x803696C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    dbMenuDrawString(rdram, ctx);
        goto after_2;
    // 0x803696C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x803696C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803696C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803696CC: jr          $ra
    // 0x803696D0: nop

    return;
    // 0x803696D0: nop

;}
RECOMP_FUNC void wpPikachuThunderJoltGroundProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801696A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801696A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801696A8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x801696AC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x801696B0: lui         $at, 0x40F0
    ctx->r1 = S32(0X40F0 << 16);
    // 0x801696B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801696B8: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x801696BC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x801696C0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801696C4: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x801696C8: nop

    // 0x801696CC: bc1f        L_801696EC
    if (!c1cs) {
        // 0x801696D0: nop
    
            goto L_801696EC;
    }
    // 0x801696D0: nop

    // 0x801696D4: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801696D8: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    // 0x801696DC: jal         0x80101C34
    // 0x801696E0: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    efManagerPikachuThunderJoltMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801696E0: lw          $a1, 0x38($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X38);
    after_0:
    // 0x801696E4: jal         0x80169654
    // 0x801696E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    wpPikachuThunderJoltGroundAddAnim(rdram, ctx);
        goto after_1;
    // 0x801696E8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
L_801696EC:
    // 0x801696EC: jal         0x80167FE8
    // 0x801696F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    wpMainDecLifeCheckExpire(rdram, ctx);
        goto after_2;
    // 0x801696F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801696F4: beql        $v0, $zero, L_80169718
    if (ctx->r2 == 0) {
        // 0x801696F8: lw          $t6, 0x74($s1)
        ctx->r14 = MEM_W(ctx->r17, 0X74);
            goto L_80169718;
    }
    goto skip_0;
    // 0x801696F8: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
    skip_0:
    // 0x801696FC: lw          $a0, 0x74($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X74);
    // 0x80169700: lui         $a1, 0x3F80
    ctx->r5 = S32(0X3F80 << 16);
    // 0x80169704: jal         0x800FF648
    // 0x80169708: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    efManagerDustExpandSmallMakeEffect(rdram, ctx);
        goto after_3;
    // 0x80169708: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_3:
    // 0x8016970C: b           L_80169808
    // 0x80169710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80169808;
    // 0x80169710: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80169714: lw          $t6, 0x74($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X74);
L_80169718:
    // 0x80169718: jal         0x80035CD0
    // 0x8016971C: lwc1        $f12, 0x38($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X38);
    __cosf_recomp(rdram, ctx);
        goto after_4;
    // 0x8016971C: lwc1        $f12, 0x38($t6)
    ctx->f12.u32l = MEM_W(ctx->r14, 0X38);
    after_4:
    // 0x80169720: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80169724: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80169728: nop

    // 0x8016972C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80169730: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x80169734: lw          $t7, 0x74($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X74);
    // 0x80169738: jal         0x800303F0
    // 0x8016973C: lwc1        $f12, 0x38($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X38);
    __sinf_recomp(rdram, ctx);
        goto after_5;
    // 0x8016973C: lwc1        $f12, 0x38($t7)
    ctx->f12.u32l = MEM_W(ctx->r15, 0X38);
    after_5:
    // 0x80169740: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x80169744: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80169748: lw          $v0, 0x29C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X29C);
    // 0x8016974C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x80169750: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80169754: beq         $v0, $zero, L_80169774
    if (ctx->r2 == 0) {
        // 0x80169758: swc1        $f18, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
            goto L_80169774;
    }
    // 0x80169758: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x8016975C: beq         $v0, $v1, L_80169794
    if (ctx->r2 == ctx->r3) {
        // 0x80169760: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80169794;
    }
    // 0x80169760: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80169764: beql        $v0, $at, L_80169798
    if (ctx->r2 == ctx->r1) {
        // 0x80169768: lw          $v0, 0x18($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X18);
            goto L_80169798;
    }
    goto skip_1;
    // 0x80169768: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    skip_1:
    // 0x8016976C: b           L_80169808
    // 0x80169770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80169808;
    // 0x80169770: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80169774:
    // 0x80169774: lw          $t8, 0x18($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X18);
    // 0x80169778: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8016977C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80169780: nop

    // 0x80169784: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80169788: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8016978C: b           L_80169804
    // 0x80169790: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
        goto L_80169804;
    // 0x80169790: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
L_80169794:
    // 0x80169794: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
L_80169798:
    // 0x80169798: bnel        $v1, $v0, L_801697D0
    if (ctx->r3 != ctx->r2) {
        // 0x8016979C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801697D0;
    }
    goto skip_2;
    // 0x8016979C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_2:
    // 0x801697A0: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801697A4: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801697A8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801697AC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801697B0: nop

    // 0x801697B4: bc1fl       L_801697D0
    if (!c1cs) {
        // 0x801697B8: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_801697D0;
    }
    goto skip_3;
    // 0x801697B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    skip_3:
    // 0x801697BC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801697C0: lw          $v0, 0x18($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X18);
    // 0x801697C4: mul.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x801697C8: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x801697CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_801697D0:
    // 0x801697D0: bnel        $v0, $at, L_80169808
    if (ctx->r2 != ctx->r1) {
        // 0x801697D4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80169808;
    }
    goto skip_4;
    // 0x801697D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_4:
    // 0x801697D8: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x801697DC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801697E0: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x801697E4: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x801697E8: nop

    // 0x801697EC: bc1fl       L_80169808
    if (!c1cs) {
        // 0x801697F0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80169808;
    }
    goto skip_5;
    // 0x801697F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_5:
    // 0x801697F4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801697F8: nop

    // 0x801697FC: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80169800: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_80169804:
    // 0x80169804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80169808:
    // 0x80169808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8016980C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80169810: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80169814: jr          $ra
    // 0x80169818: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80169818: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_8037C3AC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037C3AC: jr          $ra
    // 0x8037C3B0: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
    return;
    // 0x8037C3B0: sw          $a1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r5;
;}
RECOMP_FUNC void ftYoshiSpecialAirNCatchProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E510: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015E514: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015E518: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015E51C: jal         0x800DE6E4
    // 0x8015E520: addiu       $a1, $a1, -0x19C0
    ctx->r5 = ADD32(ctx->r5, -0X19C0);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x8015E520: addiu       $a1, $a1, -0x19C0
    ctx->r5 = ADD32(ctx->r5, -0X19C0);
    after_0:
    // 0x8015E524: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015E528: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015E52C: jr          $ra
    // 0x8015E530: nop

    return;
    // 0x8015E530: nop

;}
RECOMP_FUNC void func_ovl8_803749EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803749EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x803749F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803749F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x803749F8: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x803749FC: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x80374A00: lh          $t7, 0x28($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X28);
    // 0x80374A04: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80374A08: lw          $t9, 0x2C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C);
    // 0x80374A0C: addu        $a0, $t7, $a0
    ctx->r4 = ADD32(ctx->r15, ctx->r4);
    // 0x80374A10: jalr        $t9
    // 0x80374A14: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374A14: nop

    after_0:
    // 0x80374A18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80374A1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80374A20: jr          $ra
    // 0x80374A24: nop

    return;
    // 0x80374A24: nop

;}
RECOMP_FUNC void mvOpeningYamabukiMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BD4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80131BD8: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80131BDC: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x80131BE0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131BE4: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x80131BE8: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
L_80131BEC:
    // 0x80131BEC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131BF0: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80131BF4: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131BF8: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80131BFC: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80131C00: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80131C04: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80131C08: bne         $t7, $t0, L_80131BEC
    if (ctx->r15 != ctx->r8) {
        // 0x80131C0C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80131BEC;
    }
    // 0x80131C0C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80131C10: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80131C14: addiu       $t1, $zero, 0x9
    ctx->r9 = ADD32(0, 0X9);
    // 0x80131C18: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x80131C1C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80131C20: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x80131C24: jal         0x800EC0EC
    // 0x80131C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80131C28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80131C2C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131C30: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80131C34: lw          $t2, 0x2488($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2488);
    // 0x80131C38: sb          $v0, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r2;
    // 0x80131C3C: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80131C40: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80131C44: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80131C48: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80131C4C: jal         0x800D7F3C
    // 0x80131C50: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80131C50: sw          $t2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r10;
    after_1:
    // 0x80131C54: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131C58: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80131C5C: sw          $v0, 0x2494($at)
    MEM_W(0X2494, ctx->r1) = ctx->r2;
    // 0x80131C60: ori         $a1, $a1, 0xF
    ctx->r5 = ctx->r5 | 0XF;
    // 0x80131C64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131C68: jal         0x803905CC
    // 0x80131C6C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x80131C6C: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    after_2:
    // 0x80131C70: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x80131C74: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131C78: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131C7C: lw          $t3, 0x74($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X74);
    // 0x80131C80: swc1        $f0, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f0.u32l;
    // 0x80131C84: lw          $t4, 0x74($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X74);
    // 0x80131C88: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x80131C8C: lw          $t5, 0x74($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X74);
    // 0x80131C90: swc1        $f0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f0.u32l;
    // 0x80131C94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80131C98: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80131C9C: jr          $ra
    // 0x80131CA0: nop

    return;
    // 0x80131CA0: nop

;}
RECOMP_FUNC void mnVSRecordMakeStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135934: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80135938: beq         $a0, $zero, L_8013595C
    if (ctx->r4 == 0) {
        // 0x8013593C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8013595C;
    }
    // 0x8013593C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135940: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80135944: beq         $a0, $at, L_80135984
    if (ctx->r4 == ctx->r1) {
        // 0x80135948: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80135984;
    }
    // 0x80135948: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013594C: beq         $a0, $at, L_801359B8
    if (ctx->r4 == ctx->r1) {
        // 0x80135950: nop
    
            goto L_801359B8;
    }
    // 0x80135950: nop

    // 0x80135954: b           L_801359E0
    // 0x80135958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801359E0;
    // 0x80135958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013595C:
    // 0x8013595C: jal         0x80133FE8
    // 0x80135960: nop

    mnVSRecordSortData(rdram, ctx);
        goto after_0;
    // 0x80135960: nop

    after_0:
    // 0x80135964: jal         0x80134610
    // 0x80135968: nop

    mnVSRecordMakeBattleScoreTableHeaders(rdram, ctx);
        goto after_1;
    // 0x80135968: nop

    after_1:
    // 0x8013596C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80135970: jal         0x801343E0
    // 0x80135974: sw          $v0, 0x6C20($at)
    MEM_W(0X6C20, ctx->r1) = ctx->r2;
    mnVSRecordMakeBattleScoreTableValues(rdram, ctx);
        goto after_2;
    // 0x80135974: sw          $v0, 0x6C20($at)
    MEM_W(0X6C20, ctx->r1) = ctx->r2;
    after_2:
    // 0x80135978: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013597C: b           L_801359DC
    // 0x80135980: sw          $v0, 0x6C24($at)
    MEM_W(0X6C24, ctx->r1) = ctx->r2;
        goto L_801359DC;
    // 0x80135980: sw          $v0, 0x6C24($at)
    MEM_W(0X6C24, ctx->r1) = ctx->r2;
L_80135984:
    // 0x80135984: jal         0x80133FE8
    // 0x80135988: nop

    mnVSRecordSortData(rdram, ctx);
        goto after_3;
    // 0x80135988: nop

    after_3:
    // 0x8013598C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80135990: jal         0x80135108
    // 0x80135994: lw          $a0, 0x6CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6CC0);
    mnVSRecordMakeRankingTableHeaders(rdram, ctx);
        goto after_4;
    // 0x80135994: lw          $a0, 0x6CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6CC0);
    after_4:
    // 0x80135998: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013599C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801359A0: sw          $v0, 0x6C20($at)
    MEM_W(0X6C20, ctx->r1) = ctx->r2;
    // 0x801359A4: jal         0x80134AA8
    // 0x801359A8: lw          $a0, 0x6CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6CC0);
    mnVSRecordMakeRankingTableValues(rdram, ctx);
        goto after_5;
    // 0x801359A8: lw          $a0, 0x6CC0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6CC0);
    after_5:
    // 0x801359AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801359B0: b           L_801359DC
    // 0x801359B4: sw          $v0, 0x6C24($at)
    MEM_W(0X6C24, ctx->r1) = ctx->r2;
        goto L_801359DC;
    // 0x801359B4: sw          $v0, 0x6C24($at)
    MEM_W(0X6C24, ctx->r1) = ctx->r2;
L_801359B8:
    // 0x801359B8: jal         0x80133FE8
    // 0x801359BC: nop

    mnVSRecordSortData(rdram, ctx);
        goto after_6;
    // 0x801359BC: nop

    after_6:
    // 0x801359C0: jal         0x80135784
    // 0x801359C4: nop

    mnVSRecordMakeIndivPortraitAll(rdram, ctx);
        goto after_7;
    // 0x801359C4: nop

    after_7:
    // 0x801359C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801359CC: jal         0x80135484
    // 0x801359D0: sw          $v0, 0x6C20($at)
    MEM_W(0X6C20, ctx->r1) = ctx->r2;
    mnVSRecordMakeIndivTableValues(rdram, ctx);
        goto after_8;
    // 0x801359D0: sw          $v0, 0x6C20($at)
    MEM_W(0X6C20, ctx->r1) = ctx->r2;
    after_8:
    // 0x801359D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801359D8: sw          $v0, 0x6C24($at)
    MEM_W(0X6C24, ctx->r1) = ctx->r2;
L_801359DC:
    // 0x801359DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801359E0:
    // 0x801359E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801359E4: jr          $ra
    // 0x801359E8: nop

    return;
    // 0x801359E8: nop

;}

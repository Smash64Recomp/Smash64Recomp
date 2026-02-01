#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lbCommonDecodeSpriteBitmapsSiz4b(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CB738: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800CB73C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CB740: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CB744: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CB748: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800CB74C: lh          $v0, 0x28($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X28);
    // 0x800CB750: lw          $v1, 0x34($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X34);
    // 0x800CB754: blez        $v0, L_800CB7B8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CB758: sll         $s1, $v0, 4
        ctx->r17 = S32(ctx->r2 << 4);
            goto L_800CB7B8;
    }
    // 0x800CB758: sll         $s1, $v0, 4
    ctx->r17 = S32(ctx->r2 << 4);
    // 0x800CB75C: addu        $s0, $v1, $s1
    ctx->r16 = ADD32(ctx->r3, ctx->r17);
L_800CB760:
    // 0x800CB760: lh          $t8, -0xE($s0)
    ctx->r24 = MEM_H(ctx->r16, -0XE);
    // 0x800CB764: lh          $t7, -0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, -0X4);
    // 0x800CB768: lw          $a2, -0x8($s0)
    ctx->r6 = MEM_W(ctx->r16, -0X8);
    // 0x800CB76C: bgez        $t8, L_800CB77C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800CB770: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_800CB77C;
    }
    // 0x800CB770: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800CB774: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x800CB778: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800CB77C:
    // 0x800CB77C: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800CB780: mflo        $v0
    ctx->r2 = lo;
    // 0x800CB784: addu        $a1, $a2, $v0
    ctx->r5 = ADD32(ctx->r6, ctx->r2);
    // 0x800CB788: bgez        $v0, L_800CB798
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800CB78C: sra         $t0, $v0, 1
        ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
            goto L_800CB798;
    }
    // 0x800CB78C: sra         $t0, $v0, 1
    ctx->r8 = S32(SIGNED(ctx->r2) >> 1);
    // 0x800CB790: addiu       $at, $v0, 0x1
    ctx->r1 = ADD32(ctx->r2, 0X1);
    // 0x800CB794: sra         $t0, $at, 1
    ctx->r8 = S32(SIGNED(ctx->r1) >> 1);
L_800CB798:
    // 0x800CB798: addu        $a0, $a2, $t0
    ctx->r4 = ADD32(ctx->r6, ctx->r8);
    // 0x800CB79C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800CB7A0: jal         0x800CB674
    // 0x800CB7A4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    lbCommonDecodeBitmapSiz4b(rdram, ctx);
        goto after_0;
    // 0x800CB7A4: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_0:
    // 0x800CB7A8: addiu       $s1, $s1, -0x10
    ctx->r17 = ADD32(ctx->r17, -0X10);
    // 0x800CB7AC: slti        $at, $s1, 0x10
    ctx->r1 = SIGNED(ctx->r17) < 0X10 ? 1 : 0;
    // 0x800CB7B0: beq         $at, $zero, L_800CB760
    if (ctx->r1 == 0) {
        // 0x800CB7B4: addiu       $s0, $s0, -0x10
        ctx->r16 = ADD32(ctx->r16, -0X10);
            goto L_800CB760;
    }
    // 0x800CB7B4: addiu       $s0, $s0, -0x10
    ctx->r16 = ADD32(ctx->r16, -0X10);
L_800CB7B8:
    // 0x800CB7B8: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800CB7BC: sb          $zero, 0x31($t1)
    MEM_B(0X31, ctx->r9) = 0;
    // 0x800CB7C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CB7C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CB7C8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CB7CC: jr          $ra
    // 0x800CB7D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800CB7D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mnVSResultsLabelProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801365C0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801365C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801365C8: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x801365CC: addiu       $s0, $s0, 0x65B0
    ctx->r16 = ADD32(ctx->r16, 0X65B0);
    // 0x801365D0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801365D4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801365D8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801365DC: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x801365E0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801365E4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x801365E8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x801365EC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801365F0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801365F4: lui         $t9, 0xE300
    ctx->r25 = S32(0XE300 << 16);
    // 0x801365F8: ori         $t9, $t9, 0xA01
    ctx->r25 = ctx->r25 | 0XA01;
    // 0x801365FC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80136600: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80136604: lui         $t0, 0x30
    ctx->r8 = S32(0X30 << 16);
    // 0x80136608: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x8013660C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80136610: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80136614: lui         $t2, 0xE200
    ctx->r10 = S32(0XE200 << 16);
    // 0x80136618: ori         $t2, $t2, 0x1C
    ctx->r10 = ctx->r10 | 0X1C;
    // 0x8013661C: addiu       $t1, $v1, 0x8
    ctx->r9 = ADD32(ctx->r3, 0X8);
    // 0x80136620: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80136624: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80136628: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8013662C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80136630: lui         $t4, 0xF700
    ctx->r12 = S32(0XF700 << 16);
    // 0x80136634: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80136638: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x8013663C: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80136640: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x80136644: jal         0x80006D70
    // 0x80136648: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    syVideoGetFillColor(rdram, ctx);
        goto after_0;
    // 0x80136648: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_0:
    // 0x8013664C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80136650: lui         $t6, 0xF646
    ctx->r14 = S32(0XF646 << 16);
    // 0x80136654: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80136658: sw          $v0, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r2;
    // 0x8013665C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80136660: ori         $t7, $t7, 0xA8
    ctx->r15 = ctx->r15 | 0XA8;
    // 0x80136664: ori         $t6, $t6, 0x80B0
    ctx->r14 = ctx->r14 | 0X80B0;
    // 0x80136668: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8013666C: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80136670: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80136674: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80136678: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8013667C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80136680: lui         $t1, 0xE200
    ctx->r9 = S32(0XE200 << 16);
    // 0x80136684: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x80136688: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8013668C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80136690: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80136694: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x80136698: lui         $t2, 0x55
    ctx->r10 = S32(0X55 << 16);
    // 0x8013669C: ori         $t2, $t2, 0x2078
    ctx->r10 = ctx->r10 | 0X2078;
    // 0x801366A0: addiu       $t0, $v1, 0x8
    ctx->r8 = ADD32(ctx->r3, 0X8);
    // 0x801366A4: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801366A8: ori         $t1, $t1, 0x1C
    ctx->r9 = ctx->r9 | 0X1C;
    // 0x801366AC: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x801366B0: jal         0x800CCEAC
    // 0x801366B4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_1;
    // 0x801366B4: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    after_1:
    // 0x801366B8: jal         0x800CCF00
    // 0x801366BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_2;
    // 0x801366BC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_2:
    // 0x801366C0: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x801366C4: lui         $t4, 0xE300
    ctx->r12 = S32(0XE300 << 16);
    // 0x801366C8: ori         $t4, $t4, 0xA01
    ctx->r12 = ctx->r12 | 0XA01;
    // 0x801366CC: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x801366D0: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801366D4: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x801366D8: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    // 0x801366DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801366E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801366E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801366E8: jr          $ra
    // 0x801366EC: nop

    return;
    // 0x801366EC: nop

;}
RECOMP_FUNC void ftCommonAttackS4SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014FFE0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014FFE4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8014FFE8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8014FFEC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014FFF0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8014FFF4: lw          $t7, 0x9C4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X9C4);
    // 0x8014FFF8: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    // 0x8014FFFC: lw          $t8, 0x858($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X858);
    // 0x80150000: beql        $t8, $zero, L_801500A8
    if (ctx->r24 == 0) {
        // 0x80150004: lw          $t9, 0x84C($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X84C);
            goto L_801500A8;
    }
    goto skip_0;
    // 0x80150004: lw          $t9, 0x84C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84C);
    skip_0:
    // 0x80150008: jal         0x800E8000
    // 0x8015000C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_0;
    // 0x8015000C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80150010: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80150014: lwc1        $f4, -0x3B20($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3B20);
    // 0x80150018: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015001C: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80150020: nop

    // 0x80150024: bc1f        L_80150034
    if (!c1cs) {
        // 0x80150028: nop
    
            goto L_80150034;
    }
    // 0x80150028: nop

    // 0x8015002C: b           L_80150108
    // 0x80150030: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
        goto L_80150108;
    // 0x80150030: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
L_80150034:
    // 0x80150034: lwc1        $f6, -0x3B1C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3B1C);
    // 0x80150038: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015003C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80150040: nop

    // 0x80150044: bc1f        L_80150054
    if (!c1cs) {
        // 0x80150048: nop
    
            goto L_80150054;
    }
    // 0x80150048: nop

    // 0x8015004C: b           L_80150108
    // 0x80150050: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
        goto L_80150108;
    // 0x80150050: addiu       $a1, $zero, 0xCB
    ctx->r5 = ADD32(0, 0XCB);
L_80150054:
    // 0x80150054: lwc1        $f8, -0x3B18($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X3B18);
    // 0x80150058: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015005C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80150060: nop

    // 0x80150064: bc1f        L_80150074
    if (!c1cs) {
        // 0x80150068: nop
    
            goto L_80150074;
    }
    // 0x80150068: nop

    // 0x8015006C: b           L_80150098
    // 0x80150070: addiu       $v1, $zero, 0xCE
    ctx->r3 = ADD32(0, 0XCE);
        goto L_80150098;
    // 0x80150070: addiu       $v1, $zero, 0xCE
    ctx->r3 = ADD32(0, 0XCE);
L_80150074:
    // 0x80150074: lwc1        $f10, -0x3B14($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X3B14);
    // 0x80150078: addiu       $v0, $zero, 0xCC
    ctx->r2 = ADD32(0, 0XCC);
    // 0x8015007C: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80150080: nop

    // 0x80150084: bc1f        L_80150094
    if (!c1cs) {
        // 0x80150088: nop
    
            goto L_80150094;
    }
    // 0x80150088: nop

    // 0x8015008C: b           L_80150094
    // 0x80150090: addiu       $v0, $zero, 0xCD
    ctx->r2 = ADD32(0, 0XCD);
        goto L_80150094;
    // 0x80150090: addiu       $v0, $zero, 0xCD
    ctx->r2 = ADD32(0, 0XCD);
L_80150094:
    // 0x80150094: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80150098:
    // 0x80150098: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8015009C: b           L_80150108
    // 0x801500A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80150108;
    // 0x801500A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801500A4: lw          $t9, 0x84C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X84C);
L_801500A8:
    // 0x801500A8: addiu       $a1, $zero, 0xCC
    ctx->r5 = ADD32(0, 0XCC);
    // 0x801500AC: beq         $t9, $zero, L_80150108
    if (ctx->r25 == 0) {
        // 0x801500B0: nop
    
            goto L_80150108;
    }
    // 0x801500B0: nop

    // 0x801500B4: jal         0x800E8000
    // 0x801500B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamGetStickAngleRads(rdram, ctx);
        goto after_1;
    // 0x801500B8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801500BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801500C0: lwc1        $f16, -0x3B10($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X3B10);
    // 0x801500C4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801500C8: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x801500CC: nop

    // 0x801500D0: bc1f        L_801500E0
    if (!c1cs) {
        // 0x801500D4: nop
    
            goto L_801500E0;
    }
    // 0x801500D4: nop

    // 0x801500D8: b           L_80150108
    // 0x801500DC: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
        goto L_80150108;
    // 0x801500DC: addiu       $a1, $zero, 0xCA
    ctx->r5 = ADD32(0, 0XCA);
L_801500E0:
    // 0x801500E0: lwc1        $f18, -0x3B0C($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3B0C);
    // 0x801500E4: addiu       $v0, $zero, 0xCC
    ctx->r2 = ADD32(0, 0XCC);
    // 0x801500E8: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x801500EC: nop

    // 0x801500F0: bc1f        L_80150100
    if (!c1cs) {
        // 0x801500F4: nop
    
            goto L_80150100;
    }
    // 0x801500F4: nop

    // 0x801500F8: b           L_80150108
    // 0x801500FC: addiu       $a1, $zero, 0xCE
    ctx->r5 = ADD32(0, 0XCE);
        goto L_80150108;
    // 0x801500FC: addiu       $a1, $zero, 0xCE
    ctx->r5 = ADD32(0, 0XCE);
L_80150100:
    // 0x80150100: b           L_80150108
    // 0x80150104: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_80150108;
    // 0x80150104: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
L_80150108:
    // 0x80150108: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x8015010C: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80150110: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80150114: beq         $v0, $at, L_80150140
    if (ctx->r2 == ctx->r1) {
        // 0x80150118: lui         $a3, 0x3F80
        ctx->r7 = S32(0X3F80 << 16);
            goto L_80150140;
    }
    // 0x80150118: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015011C: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80150120: beq         $v0, $at, L_8015014C
    if (ctx->r2 == ctx->r1) {
        // 0x80150124: addiu       $at, $zero, 0x17
        ctx->r1 = ADD32(0, 0X17);
            goto L_8015014C;
    }
    // 0x80150124: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80150128: beq         $v0, $at, L_80150140
    if (ctx->r2 == ctx->r1) {
        // 0x8015012C: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_80150140;
    }
    // 0x8015012C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80150130: beql        $v0, $at, L_80150150
    if (ctx->r2 == ctx->r1) {
        // 0x80150134: sw          $zero, 0x180($s0)
        MEM_W(0X180, ctx->r16) = 0;
            goto L_80150150;
    }
    goto skip_1;
    // 0x80150134: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    skip_1:
    // 0x80150138: b           L_80150154
    // 0x8015013C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
        goto L_80150154;
    // 0x8015013C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80150140:
    // 0x80150140: sw          $zero, 0x184($s0)
    MEM_W(0X184, ctx->r16) = 0;
    // 0x80150144: b           L_80150150
    // 0x80150148: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
        goto L_80150150;
    // 0x80150148: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
L_8015014C:
    // 0x8015014C: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
L_80150150:
    // 0x80150150: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
L_80150154:
    // 0x80150154: jal         0x800E6F24
    // 0x80150158: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80150158: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_2:
    // 0x8015015C: jal         0x800E0830
    // 0x80150160: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_3;
    // 0x80150160: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_3:
    // 0x80150164: lw          $v0, 0x8($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X8);
    // 0x80150168: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x8015016C: lui         $t0, 0x800F
    ctx->r8 = S32(0X800F << 16);
    // 0x80150170: beq         $v0, $at, L_801501A0
    if (ctx->r2 == ctx->r1) {
        // 0x80150174: addiu       $t0, $t0, -0x6374
        ctx->r8 = ADD32(ctx->r8, -0X6374);
            goto L_801501A0;
    }
    // 0x80150174: addiu       $t0, $t0, -0x6374
    ctx->r8 = ADD32(ctx->r8, -0X6374);
    // 0x80150178: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8015017C: beq         $v0, $at, L_801501B8
    if (ctx->r2 == ctx->r1) {
        // 0x80150180: lui         $t2, 0x8013
        ctx->r10 = S32(0X8013 << 16);
            goto L_801501B8;
    }
    // 0x80150180: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80150184: addiu       $at, $zero, 0x17
    ctx->r1 = ADD32(0, 0X17);
    // 0x80150188: beq         $v0, $at, L_801501A0
    if (ctx->r2 == ctx->r1) {
        // 0x8015018C: addiu       $at, $zero, 0x19
        ctx->r1 = ADD32(0, 0X19);
            goto L_801501A0;
    }
    // 0x8015018C: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x80150190: beq         $v0, $at, L_801501B8
    if (ctx->r2 == ctx->r1) {
        // 0x80150194: nop
    
            goto L_801501B8;
    }
    // 0x80150194: nop

    // 0x80150198: b           L_801501D0
    // 0x8015019C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_801501D0;
    // 0x8015019C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801501A0:
    // 0x801501A0: lui         $t1, 0x800F
    ctx->r9 = S32(0X800F << 16);
    // 0x801501A4: addiu       $t1, $t1, -0x633C
    ctx->r9 = ADD32(ctx->r9, -0X633C);
    // 0x801501A8: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x801501AC: sw          $t0, 0xA04($s0)
    MEM_W(0XA04, ctx->r16) = ctx->r8;
    // 0x801501B0: b           L_801501CC
    // 0x801501B4: sw          $t1, 0xA08($s0)
    MEM_W(0XA08, ctx->r16) = ctx->r9;
        goto L_801501CC;
    // 0x801501B4: sw          $t1, 0xA08($s0)
    MEM_W(0XA08, ctx->r16) = ctx->r9;
L_801501B8:
    // 0x801501B8: lw          $t2, 0x1134($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X1134);
    // 0x801501BC: lui         $t3, 0x0
    ctx->r11 = S32(0X0 << 16);
    // 0x801501C0: addiu       $t3, $t3, 0x1114
    ctx->r11 = ADD32(ctx->r11, 0X1114);
    // 0x801501C4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x801501C8: sw          $t4, 0x850($s0)
    MEM_W(0X850, ctx->r16) = ctx->r12;
L_801501CC:
    // 0x801501CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_801501D0:
    // 0x801501D0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x801501D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801501D8: jr          $ra
    // 0x801501DC: nop

    return;
    // 0x801501DC: nop

;}
RECOMP_FUNC void ftSamusSpecialAirLwSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015E130: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015E134: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015E138: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015E13C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015E140: jal         0x800DEE98
    // 0x8015E144: sw          $zero, 0x188($a0)
    MEM_W(0X188, ctx->r4) = 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8015E144: sw          $zero, 0x188($a0)
    MEM_W(0X188, ctx->r4) = 0;
    after_0:
    // 0x8015E148: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015E14C: addiu       $a1, $zero, 0xE5
    ctx->r5 = ADD32(0, 0XE5);
    // 0x8015E150: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015E154: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015E158: jal         0x800E6F24
    // 0x8015E15C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015E15C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8015E160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015E164: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015E168: jr          $ra
    // 0x8015E16C: nop

    return;
    // 0x8015E16C: nop

;}
RECOMP_FUNC void mvEndingMakeRoomFadeInCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801321A4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801321A8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801321AC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801321B0: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801321B4: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x801321B8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801321BC: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x801321C0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801321C4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801321C8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801321CC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801321D0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801321D4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801321D8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801321DC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801321E0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801321E4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801321E8: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801321EC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801321F0: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801321F4: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x801321F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801321FC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80132200: jal         0x8000B93C
    // 0x80132204: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132204: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132208: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013220C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132210: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132214: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132218: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013221C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132220: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132224: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132228: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013222C: jal         0x80007080
    // 0x80132230: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132230: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132234: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132238: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x8013223C: jr          $ra
    // 0x80132240: nop

    return;
    // 0x80132240: nop

;}
RECOMP_FUNC void mvOpeningLinkFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DFCC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018DFD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018DFD4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018DFD8: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018DFDC: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018DFE0: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018DFE4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018DFE8: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018DFEC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018DFF0: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018DFF4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018DFF8: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018DFFC: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018E000: jal         0x800FCB70
    // 0x8018E004: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E004: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E008: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E00C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E010: jr          $ra
    // 0x8018E014: nop

    return;
    // 0x8018E014: nop

;}
RECOMP_FUNC void func_ovl8_80376FB4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80376FB4: jr          $ra
    // 0x80376FB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    return;
    // 0x80376FB8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
;}
RECOMP_FUNC void efManagerLinkEntryWaveMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80102AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80102AE8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80102AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80102AF0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80102AF4: jal         0x800FDAFC
    // 0x80102AF8: addiu       $a0, $a0, -0x1B1C
    ctx->r4 = ADD32(ctx->r4, -0X1B1C);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80102AF8: addiu       $a0, $a0, -0x1B1C
    ctx->r4 = ADD32(ctx->r4, -0X1B1C);
    after_0:
    // 0x80102AFC: bne         $v0, $zero, L_80102B0C
    if (ctx->r2 != 0) {
        // 0x80102B00: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102B0C;
    }
    // 0x80102B00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80102B04: b           L_80102B30
    // 0x80102B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80102B30;
    // 0x80102B08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80102B0C:
    // 0x80102B0C: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80102B10: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80102B14: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80102B18: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80102B1C: sw          $t8, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r24;
    // 0x80102B20: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80102B24: sw          $t7, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r15;
    // 0x80102B28: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80102B2C: sw          $t8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r24;
L_80102B30:
    // 0x80102B30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80102B34: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80102B38: jr          $ra
    // 0x80102B3C: nop

    return;
    // 0x80102B3C: nop

;}
RECOMP_FUNC void mnPlayers1PBonusGetTotalCSec(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133648: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013364C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80133650: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80133654: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80133658: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013365C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80133660: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80133664: addiu       $s2, $zero, 0xC
    ctx->r18 = ADD32(0, 0XC);
L_80133668:
    // 0x80133668: jal         0x801322BC
    // 0x8013366C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusCheckFighterLocked(rdram, ctx);
        goto after_0;
    // 0x8013366C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80133670: bnel        $v0, $zero, L_80133690
    if (ctx->r2 != 0) {
        // 0x80133674: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_80133690;
    }
    goto skip_0;
    // 0x80133674: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    skip_0:
    // 0x80133678: jal         0x80133410
    // 0x8013367C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mnPlayers1PBonusGetBestTime(rdram, ctx);
        goto after_1;
    // 0x8013367C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80133680: jal         0x801334C0
    // 0x80133684: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnPlayers1PBonusGetCSec(rdram, ctx);
        goto after_2;
    // 0x80133684: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x80133688: addu        $s1, $s1, $v0
    ctx->r17 = ADD32(ctx->r17, ctx->r2);
    // 0x8013368C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_80133690:
    // 0x80133690: bne         $s0, $s2, L_80133668
    if (ctx->r16 != ctx->r18) {
        // 0x80133694: nop
    
            goto L_80133668;
    }
    // 0x80133694: nop

    // 0x80133698: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013369C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x801336A0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x801336A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801336A8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x801336AC: jr          $ra
    // 0x801336B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801336B0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void ftCommonCliffClimbCommon2ProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801453F0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801453F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801453F8: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x801453FC: lw          $t6, 0x14C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14C);
    // 0x80145400: bne         $t6, $zero, L_80145418
    if (ctx->r14 != 0) {
        // 0x80145404: nop
    
            goto L_80145418;
    }
    // 0x80145404: nop

    // 0x80145408: jal         0x800DDEC4
    // 0x8014540C: nop

    mpCommonSetFighterFallOnGroundBreak(rdram, ctx);
        goto after_0;
    // 0x8014540C: nop

    after_0:
    // 0x80145410: b           L_80145434
    // 0x80145414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80145434;
    // 0x80145414: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145418:
    // 0x80145418: jal         0x800DE6B0
    // 0x8014541C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_1;
    // 0x8014541C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80145420: beq         $v0, $zero, L_80145430
    if (ctx->r2 == 0) {
        // 0x80145424: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_80145430;
    }
    // 0x80145424: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80145428: jal         0x800DEE98
    // 0x8014542C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_2;
    // 0x8014542C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
L_80145430:
    // 0x80145430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145434:
    // 0x80145434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80145438: jr          $ra
    // 0x8014543C: nop

    return;
    // 0x8014543C: nop

;}
RECOMP_FUNC void ftKirbyCopyLinkSpecialNGetSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164A40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80164A44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80164A48: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80164A4C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80164A50: addiu       $a1, $zero, 0x120
    ctx->r5 = ADD32(0, 0X120);
    // 0x80164A54: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x80164A58: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80164A5C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80164A60: bnel        $t6, $at, L_80164A8C
    if (ctx->r14 != ctx->r1) {
        // 0x80164A64: sw          $zero, 0x10($sp)
        MEM_W(0X10, ctx->r29) = 0;
            goto L_80164A8C;
    }
    goto skip_0;
    // 0x80164A64: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    skip_0:
    // 0x80164A68: addiu       $a1, $zero, 0x123
    ctx->r5 = ADD32(0, 0X123);
    // 0x80164A6C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80164A70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80164A74: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80164A78: jal         0x800E6F24
    // 0x80164A7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80164A7C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80164A80: b           L_80164A94
    // 0x80164A84: nop

        goto L_80164A94;
    // 0x80164A84: nop

    // 0x80164A88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
L_80164A8C:
    // 0x80164A8C: jal         0x800E6F24
    // 0x80164A90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80164A90: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
L_80164A94:
    // 0x80164A94: jal         0x800E0830
    // 0x80164A98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x80164A98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x80164A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80164AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80164AA4: jr          $ra
    // 0x80164AA8: nop

    return;
    // 0x80164AA8: nop

;}
RECOMP_FUNC void func_ovl8_80371E0C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371E0C: jr          $ra
    // 0x80371E10: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    return;
    // 0x80371E10: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
;}
RECOMP_FUNC void mvEndingStartScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132A78: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80132A7C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132A80: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132A84: addiu       $t6, $t6, 0x5240
    ctx->r14 = ADD32(ctx->r14, 0X5240);
    // 0x80132A88: addiu       $a0, $a0, 0x2B08
    ctx->r4 = ADD32(ctx->r4, 0X2B08);
    // 0x80132A8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132A90: addiu       $t7, $t6, -0x1900
    ctx->r15 = ADD32(ctx->r14, -0X1900);
    // 0x80132A94: jal         0x80007024
    // 0x80132A98: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    syVideoInit(rdram, ctx);
        goto after_0;
    // 0x80132A98: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    after_0:
    // 0x80132A9C: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x80132AA0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80132AA4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132AA8: addiu       $t9, $t9, 0x2F80
    ctx->r25 = ADD32(ctx->r25, 0X2F80);
    // 0x80132AAC: addiu       $t8, $t8, 0x3E0
    ctx->r24 = ADD32(ctx->r24, 0X3E0);
    // 0x80132AB0: addiu       $a0, $a0, 0x2B24
    ctx->r4 = ADD32(ctx->r4, 0X2B24);
    // 0x80132AB4: subu        $t0, $t8, $t9
    ctx->r8 = SUB32(ctx->r24, ctx->r25);
    // 0x80132AB8: jal         0x8000683C
    // 0x80132ABC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    syTaskmanStartTask(rdram, ctx);
        goto after_1;
    // 0x80132ABC: sw          $t0, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r8;
    after_1:
    // 0x80132AC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132AC4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132AC8: jr          $ra
    // 0x80132ACC: nop

    return;
    // 0x80132ACC: nop

;}
RECOMP_FUNC void mnVSItemSwitchMakeDecal(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FDC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131FE0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131FE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131FE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131FEC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80131FF0: jal         0x80009968
    // 0x80131FF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131FF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131FF8: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131FFC: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132000: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132004: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132008: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x8013200C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132010: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80132014: jal         0x80009DF4
    // 0x80132018: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132018: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013201C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132020: lw          $t7, 0x3530($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3530);
    // 0x80132024: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80132028: addiu       $t8, $t8, 0x3430
    ctx->r24 = ADD32(ctx->r24, 0X3430);
    // 0x8013202C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132030: jal         0x800CCFDC
    // 0x80132034: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132034: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80132038: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x8013203C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132040: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132044: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132048: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013204C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132050: addiu       $t3, $zero, 0x48
    ctx->r11 = ADD32(0, 0X48);
    // 0x80132054: addiu       $t4, $zero, 0x2A
    ctx->r12 = ADD32(0, 0X2A);
    // 0x80132058: addiu       $t5, $zero, 0x23
    ctx->r13 = ADD32(0, 0X23);
    // 0x8013205C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132060: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132064: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80132068: sb          $t5, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r13;
    // 0x8013206C: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80132070: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80132074: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132078: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013207C: jr          $ra
    // 0x80132080: nop

    return;
    // 0x80132080: nop

;}
RECOMP_FUNC void itMLuckyCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181430: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80181434: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181438: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8018143C: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80181440: bnel        $a1, $zero, L_80181468
    if (ctx->r5 != 0) {
        // 0x80181444: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_80181468;
    }
    goto skip_0;
    // 0x80181444: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x80181448: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8018144C: nop

    // 0x80181450: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x80181454: jal         0x801811AC
    // 0x80181458: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itMLuckyAppearSetStatus(rdram, ctx);
        goto after_0;
    // 0x80181458: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8018145C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80181460: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x80181464: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_80181468:
    // 0x80181468: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x8018146C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181470: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80181474: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80181478: jr          $ra
    // 0x8018147C: nop

    return;
    // 0x8018147C: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133998: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8013399C: addiu       $a2, $a2, 0x42FC
    ctx->r6 = ADD32(ctx->r6, 0X42FC);
    // 0x801339A0: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x801339A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801339A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801339AC: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x801339B0: slti        $at, $t7, 0xA
    ctx->r1 = SIGNED(ctx->r15) < 0XA ? 1 : 0;
    // 0x801339B4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801339B8: bne         $at, $zero, L_80133F48
    if (ctx->r1 != 0) {
        // 0x801339BC: sw          $t7, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r15;
            goto L_80133F48;
    }
    // 0x801339BC: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x801339C0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x801339C4: lw          $t8, 0x435C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X435C);
    // 0x801339C8: bne         $t8, $t7, L_801339F4
    if (ctx->r24 != ctx->r15) {
        // 0x801339CC: lui         $v0, 0x800A
        ctx->r2 = S32(0X800A << 16);
            goto L_801339F4;
    }
    // 0x801339CC: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x801339D0: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x801339D4: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x801339D8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801339DC: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
    // 0x801339E0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801339E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801339E8: sb          $t9, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r25;
    // 0x801339EC: jal         0x80005C74
    // 0x801339F0: sw          $t1, 0x4360($at)
    MEM_W(0X4360, ctx->r1) = ctx->r9;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_0;
    // 0x801339F0: sw          $t1, 0x4360($at)
    MEM_W(0X4360, ctx->r1) = ctx->r9;
    after_0:
L_801339F4:
    // 0x801339F4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801339F8: addiu       $v1, $v1, 0x4354
    ctx->r3 = ADD32(ctx->r3, 0X4354);
    // 0x801339FC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133A00: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80133A04: beq         $v0, $zero, L_80133A10
    if (ctx->r2 == 0) {
        // 0x80133A08: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_80133A10;
    }
    // 0x80133A08: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x80133A0C: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80133A10:
    // 0x80133A10: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133A14: addiu       $v1, $v1, 0x436C
    ctx->r3 = ADD32(ctx->r3, 0X436C);
    // 0x80133A18: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133A1C: beq         $v0, $zero, L_80133A28
    if (ctx->r2 == 0) {
        // 0x80133A20: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_80133A28;
    }
    // 0x80133A20: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80133A24: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80133A28:
    // 0x80133A28: jal         0x80390A04
    // 0x80133A2C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_1;
    // 0x80133A2C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_1:
    // 0x80133A30: beq         $v0, $zero, L_80133A4C
    if (ctx->r2 == 0) {
        // 0x80133A34: addiu       $a0, $zero, -0xF
        ctx->r4 = ADD32(0, -0XF);
            goto L_80133A4C;
    }
    // 0x80133A34: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80133A38: jal         0x80390AC0
    // 0x80133A3C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_2;
    // 0x80133A3C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_2:
    // 0x80133A40: beq         $v0, $zero, L_80133A4C
    if (ctx->r2 == 0) {
        // 0x80133A44: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80133A4C;
    }
    // 0x80133A44: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133A48: sw          $zero, 0x436C($at)
    MEM_W(0X436C, ctx->r1) = 0;
L_80133A4C:
    // 0x80133A4C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80133A50: lw          $t4, 0x42FC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X42FC);
    // 0x80133A54: addiu       $at, $zero, 0x960
    ctx->r1 = ADD32(0, 0X960);
    // 0x80133A58: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133A5C: bne         $t4, $at, L_80133B04
    if (ctx->r12 != ctx->r1) {
        // 0x80133A60: nop
    
            goto L_80133B04;
    }
    // 0x80133A60: nop

    // 0x80133A64: lw          $t5, 0x433C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X433C);
    // 0x80133A68: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133A6C: bne         $t5, $zero, L_80133B04
    if (ctx->r13 != 0) {
        // 0x80133A70: nop
    
            goto L_80133B04;
    }
    // 0x80133A70: nop

    // 0x80133A74: jal         0x80009A84
    // 0x80133A78: lw          $a0, 0x4308($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4308);
    gcEjectGObj(rdram, ctx);
        goto after_3;
    // 0x80133A78: lw          $a0, 0x4308($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4308);
    after_3:
    // 0x80133A7C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133A80: jal         0x80009A84
    // 0x80133A84: lw          $a0, 0x430C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X430C);
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x80133A84: lw          $a0, 0x430C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X430C);
    after_4:
    // 0x80133A88: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133A8C: jal         0x80009A84
    // 0x80133A90: lw          $a0, 0x4304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4304);
    gcEjectGObj(rdram, ctx);
        goto after_5;
    // 0x80133A90: lw          $a0, 0x4304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4304);
    after_5:
    // 0x80133A94: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133A98: jal         0x80009A84
    // 0x80133A9C: lw          $a0, 0x4314($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4314);
    gcEjectGObj(rdram, ctx);
        goto after_6;
    // 0x80133A9C: lw          $a0, 0x4314($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4314);
    after_6:
    // 0x80133AA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133AA4: jal         0x80009A84
    // 0x80133AA8: lw          $a0, 0x4310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4310);
    gcEjectGObj(rdram, ctx);
        goto after_7;
    // 0x80133AA8: lw          $a0, 0x4310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4310);
    after_7:
    // 0x80133AAC: jal         0x801322DC
    // 0x80133AB0: nop

    mnPlayers1PGameContinueMakeRoomFadeOut(rdram, ctx);
        goto after_8;
    // 0x80133AB0: nop

    after_8:
    // 0x80133AB4: jal         0x8013307C
    // 0x80133AB8: nop

    mnPlayers1PGameContinueMakeGameOverText(rdram, ctx);
        goto after_9;
    // 0x80133AB8: nop

    after_9:
    // 0x80133ABC: jal         0x80133368
    // 0x80133AC0: nop

    mnPlayers1PGameContinueMakeGameOver(rdram, ctx);
        goto after_10;
    // 0x80133AC0: nop

    after_10:
    // 0x80133AC4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133AC8: lw          $v1, 0x42FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X42FC);
    // 0x80133ACC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80133AD0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133AD4: sw          $t6, 0x433C($at)
    MEM_W(0X433C, ctx->r1) = ctx->r14;
    // 0x80133AD8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133ADC: addiu       $t7, $v1, 0x5A
    ctx->r15 = ADD32(ctx->r3, 0X5A);
    // 0x80133AE0: sw          $t7, 0x4358($at)
    MEM_W(0X4358, ctx->r1) = ctx->r15;
    // 0x80133AE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133AE8: addiu       $t8, $v1, 0x708
    ctx->r24 = ADD32(ctx->r3, 0X708);
    // 0x80133AEC: sw          $t8, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r24;
    // 0x80133AF0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133AF4: jal         0x80020AB4
    // 0x80133AF8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    syAudioPlayBGM(rdram, ctx);
        goto after_11;
    // 0x80133AF8: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_11:
    // 0x80133AFC: jal         0x800269C0
    // 0x80133B00: addiu       $a0, $zero, 0x1E7
    ctx->r4 = ADD32(0, 0X1E7);
    func_800269C0_275C0(rdram, ctx);
        goto after_12;
    // 0x80133B00: addiu       $a0, $zero, 0x1E7
    ctx->r4 = ADD32(0, 0X1E7);
    after_12:
L_80133B04:
    // 0x80133B04: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133B08: lw          $t9, 0x433C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X433C);
    // 0x80133B0C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133B10: bne         $t9, $zero, L_80133E30
    if (ctx->r25 != 0) {
        // 0x80133B14: nop
    
            goto L_80133E30;
    }
    // 0x80133B14: nop

    // 0x80133B18: lw          $t0, 0x42FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X42FC);
    // 0x80133B1C: slti        $at, $t0, 0x97
    ctx->r1 = SIGNED(ctx->r8) < 0X97 ? 1 : 0;
    // 0x80133B20: bne         $at, $zero, L_80133D38
    if (ctx->r1 != 0) {
        // 0x80133B24: nop
    
            goto L_80133D38;
    }
    // 0x80133B24: nop

    // 0x80133B28: jal         0x8039076C
    // 0x80133B2C: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_13;
    // 0x80133B2C: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_13:
    // 0x80133B30: beq         $v0, $zero, L_80133D38
    if (ctx->r2 == 0) {
        // 0x80133B34: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80133D38;
    }
    // 0x80133B34: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133B38: lw          $v0, 0x4338($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4338);
    // 0x80133B3C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133B40: beq         $v0, $zero, L_80133B58
    if (ctx->r2 == 0) {
        // 0x80133B44: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80133B58;
    }
    // 0x80133B44: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133B48: beq         $v0, $at, L_80133CA8
    if (ctx->r2 == ctx->r1) {
        // 0x80133B4C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80133CA8;
    }
    // 0x80133B4C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133B50: b           L_80133D38
    // 0x80133B54: nop

        goto L_80133D38;
    // 0x80133B54: nop

L_80133B58:
    // 0x80133B58: jal         0x80009A84
    // 0x80133B5C: lw          $a0, 0x4308($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4308);
    gcEjectGObj(rdram, ctx);
        goto after_14;
    // 0x80133B5C: lw          $a0, 0x4308($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4308);
    after_14:
    // 0x80133B60: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133B64: jal         0x80009A84
    // 0x80133B68: lw          $a0, 0x430C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X430C);
    gcEjectGObj(rdram, ctx);
        goto after_15;
    // 0x80133B68: lw          $a0, 0x430C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X430C);
    after_15:
    // 0x80133B6C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133B70: jal         0x80009A84
    // 0x80133B74: lw          $a0, 0x4304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4304);
    gcEjectGObj(rdram, ctx);
        goto after_16;
    // 0x80133B74: lw          $a0, 0x4304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4304);
    after_16:
    // 0x80133B78: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133B7C: jal         0x80009A84
    // 0x80133B80: lw          $a0, 0x4314($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4314);
    gcEjectGObj(rdram, ctx);
        goto after_17;
    // 0x80133B80: lw          $a0, 0x4314($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4314);
    after_17:
    // 0x80133B84: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133B88: jal         0x80009A84
    // 0x80133B8C: lw          $a0, 0x4310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4310);
    gcEjectGObj(rdram, ctx);
        goto after_18;
    // 0x80133B8C: lw          $a0, 0x4310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4310);
    after_18:
    // 0x80133B90: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80133B94: lw          $t1, 0x4AF0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X4AF0);
    // 0x80133B98: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80133B9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133BA0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x80133BA4: bgez        $t1, L_80133BB8
    if (SIGNED(ctx->r9) >= 0) {
        // 0x80133BA8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80133BB8;
    }
    // 0x80133BA8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80133BAC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80133BB0: nop

    // 0x80133BB4: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80133BB8:
    // 0x80133BB8: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80133BBC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80133BC0: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133BC4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80133BC8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80133BCC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80133BD0: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80133BD4: nop

    // 0x80133BD8: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80133BDC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80133BE0: nop

    // 0x80133BE4: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80133BE8: beql        $t3, $zero, L_80133C38
    if (ctx->r11 == 0) {
        // 0x80133BEC: mfc1        $t3, $f18
        ctx->r11 = (int32_t)ctx->f18.u32l;
            goto L_80133C38;
    }
    goto skip_0;
    // 0x80133BEC: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    skip_0:
    // 0x80133BF0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80133BF4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133BF8: sub.s       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80133BFC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80133C00: nop

    // 0x80133C04: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80133C08: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80133C0C: nop

    // 0x80133C10: andi        $t3, $t3, 0x78
    ctx->r11 = ctx->r11 & 0X78;
    // 0x80133C14: bne         $t3, $zero, L_80133C2C
    if (ctx->r11 != 0) {
        // 0x80133C18: nop
    
            goto L_80133C2C;
    }
    // 0x80133C18: nop

    // 0x80133C1C: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x80133C20: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80133C24: b           L_80133C44
    // 0x80133C28: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
        goto L_80133C44;
    // 0x80133C28: or          $t3, $t3, $at
    ctx->r11 = ctx->r11 | ctx->r1;
L_80133C2C:
    // 0x80133C2C: b           L_80133C44
    // 0x80133C30: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
        goto L_80133C44;
    // 0x80133C30: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80133C34: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
L_80133C38:
    // 0x80133C38: nop

    // 0x80133C3C: bltz        $t3, L_80133C2C
    if (SIGNED(ctx->r11) < 0) {
        // 0x80133C40: nop
    
            goto L_80133C2C;
    }
    // 0x80133C40: nop

L_80133C44:
    // 0x80133C44: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80133C48: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80133C4C: sw          $t3, 0x4AF0($at)
    MEM_W(0X4AF0, ctx->r1) = ctx->r11;
    // 0x80133C50: jal         0x80009A84
    // 0x80133C54: lw          $a0, 0x4368($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4368);
    gcEjectGObj(rdram, ctx);
        goto after_19;
    // 0x80133C54: lw          $a0, 0x4368($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4368);
    after_19:
    // 0x80133C58: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x80133C5C: jal         0x80131F98
    // 0x80133C60: lw          $a0, 0x4AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4AF0);
    mnPlayers1PGameContinueMakeScoreDisplay(rdram, ctx);
        goto after_20;
    // 0x80133C60: lw          $a0, 0x4AF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4AF0);
    after_20:
    // 0x80133C64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133C68: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80133C6C: ori         $a1, $a1, 0xA
    ctx->r5 = ctx->r5 | 0XA;
    // 0x80133C70: jal         0x803905CC
    // 0x80133C74: lw          $a0, 0x4300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4300);
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_21;
    // 0x80133C74: lw          $a0, 0x4300($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4300);
    after_21:
    // 0x80133C78: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133C7C: lw          $t5, 0x42FC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X42FC);
    // 0x80133C80: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80133C84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C88: sw          $t4, 0x433C($at)
    MEM_W(0X433C, ctx->r1) = ctx->r12;
    // 0x80133C8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C90: addiu       $t6, $t5, 0xF0
    ctx->r14 = ADD32(ctx->r13, 0XF0);
    // 0x80133C94: sw          $t6, 0x435C($at)
    MEM_W(0X435C, ctx->r1) = ctx->r14;
    // 0x80133C98: jal         0x800269C0
    // 0x80133C9C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    func_800269C0_275C0(rdram, ctx);
        goto after_22;
    // 0x80133C9C: addiu       $a0, $zero, 0xA0
    ctx->r4 = ADD32(0, 0XA0);
    after_22:
    // 0x80133CA0: b           L_80133D38
    // 0x80133CA4: nop

        goto L_80133D38;
    // 0x80133CA4: nop

L_80133CA8:
    // 0x80133CA8: jal         0x80009A84
    // 0x80133CAC: lw          $a0, 0x4308($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4308);
    gcEjectGObj(rdram, ctx);
        goto after_23;
    // 0x80133CAC: lw          $a0, 0x4308($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4308);
    after_23:
    // 0x80133CB0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133CB4: jal         0x80009A84
    // 0x80133CB8: lw          $a0, 0x430C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X430C);
    gcEjectGObj(rdram, ctx);
        goto after_24;
    // 0x80133CB8: lw          $a0, 0x430C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X430C);
    after_24:
    // 0x80133CBC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133CC0: jal         0x80009A84
    // 0x80133CC4: lw          $a0, 0x4304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4304);
    gcEjectGObj(rdram, ctx);
        goto after_25;
    // 0x80133CC4: lw          $a0, 0x4304($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4304);
    after_25:
    // 0x80133CC8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133CCC: jal         0x80009A84
    // 0x80133CD0: lw          $a0, 0x4314($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4314);
    gcEjectGObj(rdram, ctx);
        goto after_26;
    // 0x80133CD0: lw          $a0, 0x4314($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4314);
    after_26:
    // 0x80133CD4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133CD8: jal         0x80009A84
    // 0x80133CDC: lw          $a0, 0x4310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4310);
    gcEjectGObj(rdram, ctx);
        goto after_27;
    // 0x80133CDC: lw          $a0, 0x4310($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4310);
    after_27:
    // 0x80133CE0: jal         0x801322DC
    // 0x80133CE4: nop

    mnPlayers1PGameContinueMakeRoomFadeOut(rdram, ctx);
        goto after_28;
    // 0x80133CE4: nop

    after_28:
    // 0x80133CE8: jal         0x8013307C
    // 0x80133CEC: nop

    mnPlayers1PGameContinueMakeGameOverText(rdram, ctx);
        goto after_29;
    // 0x80133CEC: nop

    after_29:
    // 0x80133CF0: jal         0x80133368
    // 0x80133CF4: nop

    mnPlayers1PGameContinueMakeGameOver(rdram, ctx);
        goto after_30;
    // 0x80133CF4: nop

    after_30:
    // 0x80133CF8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133CFC: lw          $v1, 0x42FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X42FC);
    // 0x80133D00: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80133D04: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D08: sw          $t7, 0x433C($at)
    MEM_W(0X433C, ctx->r1) = ctx->r15;
    // 0x80133D0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D10: addiu       $t8, $v1, 0x5A
    ctx->r24 = ADD32(ctx->r3, 0X5A);
    // 0x80133D14: sw          $t8, 0x4358($at)
    MEM_W(0X4358, ctx->r1) = ctx->r24;
    // 0x80133D18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D1C: addiu       $t9, $v1, 0x708
    ctx->r25 = ADD32(ctx->r3, 0X708);
    // 0x80133D20: sw          $t9, 0x4364($at)
    MEM_W(0X4364, ctx->r1) = ctx->r25;
    // 0x80133D24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133D28: jal         0x80020AB4
    // 0x80133D2C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    syAudioPlayBGM(rdram, ctx);
        goto after_31;
    // 0x80133D2C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_31:
    // 0x80133D30: jal         0x800269C0
    // 0x80133D34: addiu       $a0, $zero, 0x1E7
    ctx->r4 = ADD32(0, 0X1E7);
    func_800269C0_275C0(rdram, ctx);
        goto after_32;
    // 0x80133D34: addiu       $a0, $zero, 0x1E7
    ctx->r4 = ADD32(0, 0X1E7);
    after_32:
L_80133D38:
    // 0x80133D38: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133D3C: lw          $t0, 0x42FC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X42FC);
    // 0x80133D40: slti        $at, $t0, 0x79
    ctx->r1 = SIGNED(ctx->r8) < 0X79 ? 1 : 0;
    // 0x80133D44: bne         $at, $zero, L_80133E30
    if (ctx->r1 != 0) {
        // 0x80133D48: nop
    
            goto L_80133E30;
    }
    // 0x80133D48: nop

    // 0x80133D4C: jal         0x8039076C
    // 0x80133D50: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_33;
    // 0x80133D50: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_33:
    // 0x80133D54: bne         $v0, $zero, L_80133D7C
    if (ctx->r2 != 0) {
        // 0x80133D58: lui         $t1, 0x8013
        ctx->r9 = S32(0X8013 << 16);
            goto L_80133D7C;
    }
    // 0x80133D58: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133D5C: lw          $t1, 0x436C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X436C);
    // 0x80133D60: addiu       $a0, $zero, -0xF
    ctx->r4 = ADD32(0, -0XF);
    // 0x80133D64: bne         $t1, $zero, L_80133DBC
    if (ctx->r9 != 0) {
        // 0x80133D68: nop
    
            goto L_80133DBC;
    }
    // 0x80133D68: nop

    // 0x80133D6C: jal         0x8039089C
    // 0x80133D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_34;
    // 0x80133D70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_34:
    // 0x80133D74: beq         $v0, $zero, L_80133DBC
    if (ctx->r2 == 0) {
        // 0x80133D78: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_80133DBC;
    }
    // 0x80133D78: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_80133D7C:
    // 0x80133D7C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133D80: lw          $t2, 0x4338($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4338);
    // 0x80133D84: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133D88: bne         $t2, $at, L_80133DBC
    if (ctx->r10 != ctx->r1) {
        // 0x80133D8C: nop
    
            goto L_80133DBC;
    }
    // 0x80133D8C: nop

    // 0x80133D90: jal         0x800269C0
    // 0x80133D94: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_35;
    // 0x80133D94: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_35:
    // 0x80133D98: lw          $t3, 0x18($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X18);
    // 0x80133D9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133DA0: sw          $zero, 0x4338($at)
    MEM_W(0X4338, ctx->r1) = 0;
    // 0x80133DA4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80133DA8: addiu       $t4, $t3, 0xA0
    ctx->r12 = ADD32(ctx->r11, 0XA0);
    // 0x80133DAC: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x80133DB0: mflo        $t5
    ctx->r13 = lo;
    // 0x80133DB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133DB8: sw          $t5, 0x436C($at)
    MEM_W(0X436C, ctx->r1) = ctx->r13;
L_80133DBC:
    // 0x80133DBC: jal         0x8039076C
    // 0x80133DC0: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_36;
    // 0x80133DC0: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_36:
    // 0x80133DC4: bne         $v0, $zero, L_80133DEC
    if (ctx->r2 != 0) {
        // 0x80133DC8: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_80133DEC;
    }
    // 0x80133DC8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133DCC: lw          $t6, 0x436C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X436C);
    // 0x80133DD0: addiu       $a0, $zero, 0xF
    ctx->r4 = ADD32(0, 0XF);
    // 0x80133DD4: bne         $t6, $zero, L_80133E30
    if (ctx->r14 != 0) {
        // 0x80133DD8: nop
    
            goto L_80133E30;
    }
    // 0x80133DD8: nop

    // 0x80133DDC: jal         0x8039089C
    // 0x80133DE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_37;
    // 0x80133DE0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x80133DE4: beq         $v0, $zero, L_80133E30
    if (ctx->r2 == 0) {
        // 0x80133DE8: sw          $v0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r2;
            goto L_80133E30;
    }
    // 0x80133DE8: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
L_80133DEC:
    // 0x80133DEC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133DF0: lw          $t7, 0x4338($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4338);
    // 0x80133DF4: bne         $t7, $zero, L_80133E30
    if (ctx->r15 != 0) {
        // 0x80133DF8: nop
    
            goto L_80133E30;
    }
    // 0x80133DF8: nop

    // 0x80133DFC: jal         0x800269C0
    // 0x80133E00: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_38;
    // 0x80133E00: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_38:
    // 0x80133E04: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80133E08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80133E0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E10: sw          $t8, 0x4338($at)
    MEM_W(0X4338, ctx->r1) = ctx->r24;
    // 0x80133E14: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x80133E18: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80133E1C: subu        $t1, $t0, $t9
    ctx->r9 = SUB32(ctx->r8, ctx->r25);
    // 0x80133E20: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80133E24: mflo        $t2
    ctx->r10 = lo;
    // 0x80133E28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E2C: sw          $t2, 0x436C($at)
    MEM_W(0X436C, ctx->r1) = ctx->r10;
L_80133E30:
    // 0x80133E30: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80133E34: lw          $t3, 0x433C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X433C);
    // 0x80133E38: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133E3C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80133E40: bne         $t3, $at, L_80133E90
    if (ctx->r11 != ctx->r1) {
        // 0x80133E44: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_80133E90;
    }
    // 0x80133E44: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133E48: lw          $t4, 0x4358($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X4358);
    // 0x80133E4C: lw          $t5, 0x42FC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X42FC);
    // 0x80133E50: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80133E54: beq         $at, $zero, L_80133E90
    if (ctx->r1 == 0) {
        // 0x80133E58: nop
    
            goto L_80133E90;
    }
    // 0x80133E58: nop

    // 0x80133E5C: jal         0x8039076C
    // 0x80133E60: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_39;
    // 0x80133E60: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_39:
    // 0x80133E64: beq         $v0, $zero, L_80133E90
    if (ctx->r2 == 0) {
        // 0x80133E68: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80133E90;
    }
    // 0x80133E68: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80133E6C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133E70: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80133E74: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80133E78: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80133E7C: jal         0x80133990
    // 0x80133E80: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    mnPlayers1PGameContinueUnused0x80133990(rdram, ctx);
        goto after_40;
    // 0x80133E80: sb          $t6, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r14;
    after_40:
    // 0x80133E84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E88: jal         0x80005C74
    // 0x80133E8C: sw          $zero, 0x4360($at)
    MEM_W(0X4360, ctx->r1) = 0;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_41;
    // 0x80133E8C: sw          $zero, 0x4360($at)
    MEM_W(0X4360, ctx->r1) = 0;
    after_41:
L_80133E90:
    // 0x80133E90: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133E94: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133E98: lw          $t8, 0x4364($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4364);
    // 0x80133E9C: lw          $v1, 0x42FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X42FC);
    // 0x80133EA0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80133EA4: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80133EA8: bne         $t8, $v1, L_80133ED4
    if (ctx->r24 != ctx->r3) {
        // 0x80133EAC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80133ED4;
    }
    // 0x80133EAC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80133EB0: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80133EB4: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80133EB8: jal         0x80133990
    // 0x80133EBC: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    mnPlayers1PGameContinueUnused0x80133990(rdram, ctx);
        goto after_42;
    // 0x80133EBC: sb          $t0, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r8;
    after_42:
    // 0x80133EC0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133EC4: jal         0x80005C74
    // 0x80133EC8: sw          $zero, 0x4360($at)
    MEM_W(0X4360, ctx->r1) = 0;
    syTaskmanSetLoadScene(rdram, ctx);
        goto after_43;
    // 0x80133EC8: sw          $zero, 0x4360($at)
    MEM_W(0X4360, ctx->r1) = 0;
    after_43:
    // 0x80133ECC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133ED0: lw          $v1, 0x42FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X42FC);
L_80133ED4:
    // 0x80133ED4: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80133ED8: bnel        $v1, $at, L_80133EFC
    if (ctx->r3 != ctx->r1) {
        // 0x80133EDC: addiu       $at, $zero, 0x3C
        ctx->r1 = ADD32(0, 0X3C);
            goto L_80133EFC;
    }
    goto skip_1;
    // 0x80133EDC: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
    skip_1:
    // 0x80133EE0: jal         0x801326D4
    // 0x80133EE4: nop

    mnPlayers1PGameContinueMakeSpotlight(rdram, ctx);
        goto after_44;
    // 0x80133EE4: nop

    after_44:
    // 0x80133EE8: jal         0x801325E8
    // 0x80133EEC: nop

    mnPlayers1PGameContinueMakeSpotlightFade(rdram, ctx);
        goto after_45;
    // 0x80133EEC: nop

    after_45:
    // 0x80133EF0: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133EF4: lw          $v1, 0x42FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X42FC);
    // 0x80133EF8: addiu       $at, $zero, 0x3C
    ctx->r1 = ADD32(0, 0X3C);
L_80133EFC:
    // 0x80133EFC: bnel        $v1, $at, L_80133F30
    if (ctx->r3 != ctx->r1) {
        // 0x80133F00: addiu       $at, $zero, 0x78
        ctx->r1 = ADD32(0, 0X78);
            goto L_80133F30;
    }
    goto skip_2;
    // 0x80133F00: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    skip_2:
    // 0x80133F04: jal         0x80132460
    // 0x80133F08: nop

    mnPlayers1PGameContinueMakeRoomFadeIn(rdram, ctx);
        goto after_46;
    // 0x80133F08: nop

    after_46:
    // 0x80133F0C: jal         0x80132648
    // 0x80133F10: nop

    mnPlayers1PGameContinueMakeRoom(rdram, ctx);
        goto after_47;
    // 0x80133F10: nop

    after_47:
    // 0x80133F14: jal         0x80132824
    // 0x80133F18: nop

    mnPlayers1PGameContinueMakeContinue(rdram, ctx);
        goto after_48;
    // 0x80133F18: nop

    after_48:
    // 0x80133F1C: jal         0x800269C0
    // 0x80133F20: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    func_800269C0_275C0(rdram, ctx);
        goto after_49;
    // 0x80133F20: addiu       $a0, $zero, 0x1E1
    ctx->r4 = ADD32(0, 0X1E1);
    after_49:
    // 0x80133F24: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133F28: lw          $v1, 0x42FC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X42FC);
    // 0x80133F2C: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
L_80133F30:
    // 0x80133F30: bnel        $v1, $at, L_80133F4C
    if (ctx->r3 != ctx->r1) {
        // 0x80133F34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80133F4C;
    }
    goto skip_3;
    // 0x80133F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80133F38: jal         0x801329D0
    // 0x80133F3C: nop

    mnPlayers1PGameContinueMakeOptions(rdram, ctx);
        goto after_50;
    // 0x80133F3C: nop

    after_50:
    // 0x80133F40: jal         0x80132B50
    // 0x80133F44: nop

    mnPlayers1PGameContinueMakeCursor(rdram, ctx);
        goto after_51;
    // 0x80133F44: nop

    after_51:
L_80133F48:
    // 0x80133F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133F4C:
    // 0x80133F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80133F50: jr          $ra
    // 0x80133F54: nop

    return;
    // 0x80133F54: nop

;}
RECOMP_FUNC void mnPlayers1PBonusBackTo1PMode(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80135740: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80135744: lw          $t6, 0x7714($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7714);
    // 0x80135748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013574C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80135750: bne         $t6, $zero, L_8013576C
    if (ctx->r14 != 0) {
        // 0x80135754: addiu       $t9, $zero, 0x8
        ctx->r25 = ADD32(0, 0X8);
            goto L_8013576C;
    }
    // 0x80135754: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x80135758: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8013575C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80135760: addiu       $t7, $zero, 0x13
    ctx->r15 = ADD32(0, 0X13);
    // 0x80135764: b           L_8013577C
    // 0x80135768: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
        goto L_8013577C;
    // 0x80135768: sb          $t7, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r15;
L_8013576C:
    // 0x8013576C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x80135770: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x80135774: addiu       $t8, $zero, 0x14
    ctx->r24 = ADD32(0, 0X14);
    // 0x80135778: sb          $t8, 0x1($v0)
    MEM_B(0X1, ctx->r2) = ctx->r24;
L_8013577C:
    // 0x8013577C: jal         0x80136998
    // 0x80135780: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    mnPlayers1PBonusSetSceneData(rdram, ctx);
        goto after_0;
    // 0x80135780: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    after_0:
    // 0x80135784: jal         0x80020A74
    // 0x80135788: nop

    syAudioStopBGMAll(rdram, ctx);
        goto after_1;
    // 0x80135788: nop

    after_1:
    // 0x8013578C: jal         0x800266A0
    // 0x80135790: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_2;
    // 0x80135790: nop

    after_2:
    // 0x80135794: jal         0x80005C74
    // 0x80135798: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_3;
    // 0x80135798: nop

    after_3:
    // 0x8013579C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801357A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801357A4: jr          $ra
    // 0x801357A8: nop

    return;
    // 0x801357A8: nop

;}
RECOMP_FUNC void ftDonkeySpecialLwLoopProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BA14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015BA18: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015BA1C: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x8015BA20: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8015BA24: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015BA28: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8015BA2C: nop

    // 0x8015BA30: bc1fl       L_8015BA70
    if (!c1cs) {
        // 0x8015BA34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015BA70;
    }
    goto skip_0;
    // 0x8015BA34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8015BA38: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x8015BA3C: lwc1        $f6, 0x78($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X78);
    // 0x8015BA40: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8015BA44: nop

    // 0x8015BA48: bc1fl       L_8015BA70
    if (!c1cs) {
        // 0x8015BA4C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8015BA70;
    }
    goto skip_1;
    // 0x8015BA4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8015BA50: lw          $t7, 0xB18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB18);
    // 0x8015BA54: beq         $t7, $zero, L_8015BA64
    if (ctx->r15 == 0) {
        // 0x8015BA58: nop
    
            goto L_8015BA64;
    }
    // 0x8015BA58: nop

    // 0x8015BA5C: b           L_8015BA6C
    // 0x8015BA60: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
        goto L_8015BA6C;
    // 0x8015BA60: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
L_8015BA64:
    // 0x8015BA64: jal         0x8015BAD0
    // 0x8015BA68: nop

    ftDonkeySpecialLwEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BA68: nop

    after_0:
L_8015BA6C:
    // 0x8015BA6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015BA70:
    // 0x8015BA70: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015BA74: jr          $ra
    // 0x8015BA78: nop

    return;
    // 0x8015BA78: nop

;}
RECOMP_FUNC void ftCommonLightGetProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145BE4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80145BE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145BEC: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80145BF0: lw          $a2, 0x84C($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X84C);
    // 0x80145BF4: beql        $a2, $zero, L_80145D1C
    if (ctx->r6 == 0) {
        // 0x80145BF8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80145D1C;
    }
    goto skip_0;
    // 0x80145BF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80145BFC: lw          $v1, 0x84($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X84);
    // 0x80145C00: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80145C04: lw          $t6, 0x10($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X10);
    // 0x80145C08: bnel        $t0, $t6, L_80145D1C
    if (ctx->r8 != ctx->r14) {
        // 0x80145C0C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80145D1C;
    }
    goto skip_1;
    // 0x80145C0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80145C10: lw          $v0, 0xC($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XC);
    // 0x80145C14: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80145C18: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80145C1C: beq         $v0, $at, L_80145C40
    if (ctx->r2 == ctx->r1) {
        // 0x80145C20: addiu       $a1, $zero, 0x64
        ctx->r5 = ADD32(0, 0X64);
            goto L_80145C40;
    }
    // 0x80145C20: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x80145C24: beq         $v0, $t0, L_80145CA4
    if (ctx->r2 == ctx->r8) {
        // 0x80145C28: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80145CA4;
    }
    // 0x80145C28: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80145C2C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80145C30: beq         $v0, $at, L_80145D0C
    if (ctx->r2 == ctx->r1) {
        // 0x80145C34: addiu       $t8, $zero, 0x2D0
        ctx->r24 = ADD32(0, 0X2D0);
            goto L_80145D0C;
    }
    // 0x80145C34: addiu       $t8, $zero, 0x2D0
    ctx->r24 = ADD32(0, 0X2D0);
    // 0x80145C38: b           L_80145D1C
    // 0x80145C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80145D1C;
    // 0x80145C3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145C40:
    // 0x80145C40: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80145C44: jal         0x800EA3D4
    // 0x80145C48: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamSetHealDamage(rdram, ctx);
        goto after_0;
    // 0x80145C48: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80145C4C: jal         0x801728D4
    // 0x80145C50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainDestroyItem(rdram, ctx);
        goto after_1;
    // 0x80145C50: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80145C54: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80145C58: lw          $t7, 0x50E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X50E8);
    // 0x80145C5C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80145C60: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80145C64: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x80145C68: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80145C6C: bnel        $t8, $at, L_80145D1C
    if (ctx->r24 != ctx->r1) {
        // 0x80145C70: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80145D1C;
    }
    goto skip_2;
    // 0x80145C70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80145C74: lbu         $t9, 0x4AE3($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4AE3);
    // 0x80145C78: lbu         $t1, 0xD($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0XD);
    // 0x80145C7C: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80145C80: addiu       $v1, $v1, 0x36A8
    ctx->r3 = ADD32(ctx->r3, 0X36A8);
    // 0x80145C84: bnel        $t9, $t1, L_80145D1C
    if (ctx->r25 != ctx->r9) {
        // 0x80145C88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80145D1C;
    }
    goto skip_3;
    // 0x80145C88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_3:
    // 0x80145C8C: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80145C90: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80145C94: beq         $at, $zero, L_80145D18
    if (ctx->r1 == 0) {
        // 0x80145C98: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80145D18;
    }
    // 0x80145C98: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80145C9C: b           L_80145D18
    // 0x80145CA0: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
        goto L_80145D18;
    // 0x80145CA0: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
L_80145CA4:
    // 0x80145CA4: addiu       $a1, $zero, 0x3E7
    ctx->r5 = ADD32(0, 0X3E7);
    // 0x80145CA8: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80145CAC: jal         0x800EA3D4
    // 0x80145CB0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    ftParamSetHealDamage(rdram, ctx);
        goto after_2;
    // 0x80145CB0: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80145CB4: jal         0x801728D4
    // 0x80145CB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainDestroyItem(rdram, ctx);
        goto after_3;
    // 0x80145CB8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80145CBC: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80145CC0: lw          $t3, 0x50E8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X50E8);
    // 0x80145CC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80145CC8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80145CCC: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x80145CD0: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x80145CD4: bnel        $t4, $at, L_80145D1C
    if (ctx->r12 != ctx->r1) {
        // 0x80145CD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80145D1C;
    }
    goto skip_4;
    // 0x80145CD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_4:
    // 0x80145CDC: lbu         $t5, 0x4AE3($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X4AE3);
    // 0x80145CE0: lbu         $t6, 0xD($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0XD);
    // 0x80145CE4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x80145CE8: addiu       $v1, $v1, 0x36A9
    ctx->r3 = ADD32(ctx->r3, 0X36A9);
    // 0x80145CEC: bnel        $t5, $t6, L_80145D1C
    if (ctx->r13 != ctx->r14) {
        // 0x80145CF0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80145D1C;
    }
    goto skip_5;
    // 0x80145CF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_5:
    // 0x80145CF4: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x80145CF8: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80145CFC: beq         $at, $zero, L_80145D18
    if (ctx->r1 == 0) {
        // 0x80145D00: addiu       $t7, $v0, 0x1
        ctx->r15 = ADD32(ctx->r2, 0X1);
            goto L_80145D18;
    }
    // 0x80145D00: addiu       $t7, $v0, 0x1
    ctx->r15 = ADD32(ctx->r2, 0X1);
    // 0x80145D04: b           L_80145D18
    // 0x80145D08: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
        goto L_80145D18;
    // 0x80145D08: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
L_80145D0C:
    // 0x80145D0C: sw          $t8, 0xB14($a3)
    MEM_W(0XB14, ctx->r7) = ctx->r24;
    // 0x80145D10: jal         0x800E7AFC
    // 0x80145D14: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    ftParamTryPlayItemMusic(rdram, ctx);
        goto after_4;
    // 0x80145D14: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    after_4:
L_80145D18:
    // 0x80145D18: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145D1C:
    // 0x80145D1C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80145D20: jr          $ra
    // 0x80145D24: nop

    return;
    // 0x80145D24: nop

;}
RECOMP_FUNC void grYamabukiGateMakeMonster(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010AD70: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8010AD74: addiu       $v0, $v0, 0x13F0
    ctx->r2 = ADD32(ctx->r2, 0X13F0);
    // 0x8010AD78: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8010AD7C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8010AD80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010AD84: sb          $t6, 0x1C($v0)
    MEM_B(0X1C, ctx->r2) = ctx->r14;
    // 0x8010AD88: sb          $zero, 0x1D($v0)
    MEM_B(0X1D, ctx->r2) = 0;
    // 0x8010AD8C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8010AD90: lhu         $a0, -0x149C($a0)
    ctx->r4 = MEM_HU(ctx->r4, -0X149C);
    // 0x8010AD94: jal         0x800FC814
    // 0x8010AD98: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    mpCollisionGetMapObjIDsKind(rdram, ctx);
        goto after_0;
    // 0x8010AD98: addiu       $a1, $sp, 0x2C
    ctx->r5 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8010AD9C: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8010ADA0: jal         0x800FC894
    // 0x8010ADA4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    mpCollisionGetMapObjPositionID(rdram, ctx);
        goto after_1;
    // 0x8010ADA4: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_1:
    // 0x8010ADA8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8010ADAC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8010ADB0: lw          $v0, -0x6BB0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6BB0);
    // 0x8010ADB4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8010ADB8: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8010ADBC: beq         $v0, $zero, L_8010ADD0
    if (ctx->r2 == 0) {
        // 0x8010ADC0: swc1        $f0, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
            goto L_8010ADD0;
    }
    // 0x8010ADC0: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8010ADC4: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x8010ADC8: bne         $at, $zero, L_8010AE0C
    if (ctx->r1 != 0) {
        // 0x8010ADCC: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_8010AE0C;
    }
    // 0x8010ADCC: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
L_8010ADD0:
    // 0x8010ADD0: jal         0x80018994
    // 0x8010ADD4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x8010ADD4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_2:
    // 0x8010ADD8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010ADDC: lbu         $t7, 0x1412($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X1412);
    // 0x8010ADE0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8010ADE4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8010ADE8: bne         $v0, $t7, L_8010AE00
    if (ctx->r2 != ctx->r15) {
        // 0x8010ADEC: nop
    
            goto L_8010AE00;
    }
    // 0x8010ADEC: nop

    // 0x8010ADF0: bne         $v0, $at, L_8010AE00
    if (ctx->r2 != ctx->r1) {
        // 0x8010ADF4: addiu       $v1, $v0, 0x1
        ctx->r3 = ADD32(ctx->r2, 0X1);
            goto L_8010AE00;
    }
    // 0x8010ADF4: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x8010ADF8: b           L_8010AE00
    // 0x8010ADFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_8010AE00;
    // 0x8010ADFC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8010AE00:
    // 0x8010AE00: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010AE04: b           L_8010AE0C
    // 0x8010AE08: sb          $v1, 0x1412($at)
    MEM_B(0X1412, ctx->r1) = ctx->r3;
        goto L_8010AE0C;
    // 0x8010AE08: sb          $v1, 0x1412($at)
    MEM_B(0X1412, ctx->r1) = ctx->r3;
L_8010AE0C:
    // 0x8010AE0C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8010AE10: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8010AE14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8010AE18: addiu       $a1, $v1, 0x1B
    ctx->r5 = ADD32(ctx->r3, 0X1B);
    // 0x8010AE1C: addiu       $a2, $sp, 0x3C
    ctx->r6 = ADD32(ctx->r29, 0X3C);
    // 0x8010AE20: jal         0x8016EA78
    // 0x8010AE24: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    itManagerMakeItemSetupCommon(rdram, ctx);
        goto after_3;
    // 0x8010AE24: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x8010AE28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010AE2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010AE30: sw          $v0, 0x13F8($at)
    MEM_W(0X13F8, ctx->r1) = ctx->r2;
    // 0x8010AE34: jr          $ra
    // 0x8010AE38: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8010AE38: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void ftDonkeyThrowAirFFSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014DE30: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014DE34: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014DE38: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8014DE3C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8014DE40: jal         0x800DEE98
    // 0x8014DE44: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x8014DE44: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8014DE48: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8014DE4C: addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // 0x8014DE50: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014DE54: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8014DE58: jal         0x800E6F24
    // 0x8014DE5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014DE5C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8014DE60: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8014DE64: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x8014DE68: jal         0x800E8098
    // 0x8014DE6C: sw          $zero, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = 0;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x8014DE6C: sw          $zero, 0xB18($a0)
    MEM_W(0XB18, ctx->r4) = 0;
    after_2:
    // 0x8014DE70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014DE74: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014DE78: jr          $ra
    // 0x8014DE7C: nop

    return;
    // 0x8014DE7C: nop

;}
RECOMP_FUNC void mnVSRecordResortArrowsProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132BA4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132BA8: lw          $v0, 0x6C18($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6C18);
    // 0x80132BAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132BB0: beq         $v0, $zero, L_80132BC0
    if (ctx->r2 == 0) {
        // 0x80132BB4: nop
    
            goto L_80132BC0;
    }
    // 0x80132BB4: nop

    // 0x80132BB8: bne         $v0, $at, L_80132BC8
    if (ctx->r2 != ctx->r1) {
        // 0x80132BBC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80132BC8;
    }
    // 0x80132BBC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
L_80132BC0:
    // 0x80132BC0: jr          $ra
    // 0x80132BC4: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    return;
    // 0x80132BC4: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
L_80132BC8:
    // 0x80132BC8: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
    // 0x80132BCC: jr          $ra
    // 0x80132BD0: nop

    return;
    // 0x80132BD0: nop

;}
RECOMP_FUNC void gcAddXObjForDObjVar(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000855C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80008560: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80008564: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80008568: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8000856C: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80008570: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80008574: lbu         $t3, 0x56($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X56);
    // 0x80008578: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000857C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80008580: bne         $t3, $at, L_8000859C
    if (ctx->r11 != ctx->r1) {
        // 0x80008584: or          $t5, $t3, $zero
        ctx->r13 = ctx->r11 | 0;
            goto L_8000859C;
    }
    // 0x80008584: or          $t5, $t3, $zero
    ctx->r13 = ctx->r11 | 0;
    // 0x80008588: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000858C: jal         0x80023624
    // 0x80008590: addiu       $a0, $a0, -0x2554
    ctx->r4 = ADD32(ctx->r4, -0X2554);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x80008590: addiu       $a0, $a0, -0x2554
    ctx->r4 = ADD32(ctx->r4, -0X2554);
    after_0:
L_80008594:
    // 0x80008594: b           L_80008594
    pause_self(rdram);
    // 0x80008598: nop

L_8000859C:
    // 0x8000859C: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800085A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800085A4: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800085A8: beq         $v0, $zero, L_8000862C
    if (ctx->r2 == 0) {
        // 0x800085AC: addiu       $v1, $v0, 0x4
        ctx->r3 = ADD32(ctx->r2, 0X4);
            goto L_8000862C;
    }
    // 0x800085AC: addiu       $v1, $v0, 0x4
    ctx->r3 = ADD32(ctx->r2, 0X4);
    // 0x800085B0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800085B4: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800085B8: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x800085BC: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800085C0: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800085C4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_800085C8:
    // 0x800085C8: lbu         $v0, 0x0($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X0);
    // 0x800085CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800085D0: beq         $v0, $zero, L_80008618
    if (ctx->r2 == 0) {
        // 0x800085D4: nop
    
            goto L_80008618;
    }
    // 0x800085D4: nop

    // 0x800085D8: beql        $v0, $a3, L_800085FC
    if (ctx->r2 == ctx->r7) {
        // 0x800085DC: or          $t2, $v1, $zero
        ctx->r10 = ctx->r3 | 0;
            goto L_800085FC;
    }
    goto skip_0;
    // 0x800085DC: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    skip_0:
    // 0x800085E0: beql        $v0, $t0, L_80008608
    if (ctx->r2 == ctx->r8) {
        // 0x800085E4: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_80008608;
    }
    goto skip_1;
    // 0x800085E4: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    skip_1:
    // 0x800085E8: beql        $v0, $a2, L_80008614
    if (ctx->r2 == ctx->r6) {
        // 0x800085EC: or          $t4, $v1, $zero
        ctx->r12 = ctx->r3 | 0;
            goto L_80008614;
    }
    goto skip_2;
    // 0x800085EC: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
    skip_2:
    // 0x800085F0: b           L_80008618
    // 0x800085F4: nop

        goto L_80008618;
    // 0x800085F4: nop

    // 0x800085F8: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
L_800085FC:
    // 0x800085FC: b           L_80008618
    // 0x80008600: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
        goto L_80008618;
    // 0x80008600: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x80008604: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
L_80008608:
    // 0x80008608: b           L_80008618
    // 0x8000860C: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
        goto L_80008618;
    // 0x8000860C: addiu       $v1, $v1, 0x14
    ctx->r3 = ADD32(ctx->r3, 0X14);
    // 0x80008610: or          $t4, $v1, $zero
    ctx->r12 = ctx->r3 | 0;
L_80008614:
    // 0x80008614: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80008618:
    // 0x80008618: bne         $a0, $a2, L_800085C8
    if (ctx->r4 != ctx->r6) {
        // 0x8000861C: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800085C8;
    }
    // 0x8000861C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80008620: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80008624: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x80008628: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
L_8000862C:
    // 0x8000862C: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80008630: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80008634: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x80008638: slt         $at, $t6, $t5
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000863C: beq         $at, $zero, L_8000866C
    if (ctx->r1 == 0) {
        // 0x80008640: lw          $t4, 0x20($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X20);
            goto L_8000866C;
    }
    // 0x80008640: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x80008644: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x80008648: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8000864C: addu        $v1, $t8, $s0
    ctx->r3 = ADD32(ctx->r24, ctx->r16);
    // 0x80008650: addu        $v0, $s0, $t7
    ctx->r2 = ADD32(ctx->r16, ctx->r15);
L_80008654:
    // 0x80008654: lw          $t9, 0x54($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X54);
    // 0x80008658: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
    // 0x8000865C: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80008660: bne         $at, $zero, L_80008654
    if (ctx->r1 != 0) {
        // 0x80008664: sw          $t9, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->r25;
            goto L_80008654;
    }
    // 0x80008664: sw          $t9, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r25;
    // 0x80008668: lbu         $t3, 0x56($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X56);
L_8000866C:
    // 0x8000866C: addiu       $t7, $t3, 0x1
    ctx->r15 = ADD32(ctx->r11, 0X1);
    // 0x80008670: sb          $t7, 0x56($s0)
    MEM_B(0X56, ctx->r16) = ctx->r15;
    // 0x80008674: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x80008678: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8000867C: jal         0x80007D5C
    // 0x80008680: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    gcGetXObjSetNextAlloc(rdram, ctx);
        goto after_1;
    // 0x80008680: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    after_1:
    // 0x80008684: lw          $t6, 0x3C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X3C);
    // 0x80008688: lbu         $v1, 0x37($sp)
    ctx->r3 = MEM_BU(ctx->r29, 0X37);
    // 0x8000868C: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x80008690: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80008694: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x80008698: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8000869C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x800086A0: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x800086A4: sw          $v0, 0x58($t9)
    MEM_W(0X58, ctx->r25) = ctx->r2;
    // 0x800086A8: sltiu       $at, $t7, 0x3F
    ctx->r1 = ctx->r15 < 0X3F ? 1 : 0;
    // 0x800086AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800086B0: beq         $at, $zero, L_80008CA0
    if (ctx->r1 == 0) {
        // 0x800086B4: sb          $v1, 0x4($v0)
        MEM_B(0X4, ctx->r2) = ctx->r3;
            goto L_80008CA0;
    }
    // 0x800086B4: sb          $v1, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r3;
    // 0x800086B8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800086BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800086C0: addu        $at, $at, $t7
    gpr jr_addend_800086C8 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800086C4: lw          $t7, -0x23DC($at)
    ctx->r15 = ADD32(ctx->r1, -0X23DC);
    // 0x800086C8: jr          $t7
    // 0x800086CC: nop

    switch (jr_addend_800086C8 >> 2) {
        case 0: goto L_80008CA0; break;
        case 1: goto L_80008CA0; break;
        case 2: goto L_80008CA0; break;
        case 3: goto L_80008CA0; break;
        case 4: goto L_80008CA0; break;
        case 5: goto L_80008CA0; break;
        case 6: goto L_80008CA0; break;
        case 7: goto L_80008CA0; break;
        case 8: goto L_80008CA0; break;
        case 9: goto L_80008CA0; break;
        case 10: goto L_80008CA0; break;
        case 11: goto L_80008CA0; break;
        case 12: goto L_80008CA0; break;
        case 13: goto L_80008CA0; break;
        case 14: goto L_80008CA0; break;
        case 15: goto L_80008CA0; break;
        case 16: goto L_80008CA0; break;
        case 17: goto L_800086D0; break;
        case 18: goto L_80008700; break;
        case 19: goto L_80008738; break;
        case 20: goto L_8000879C; break;
        case 21: goto L_800087D4; break;
        case 22: goto L_80008700; break;
        case 23: goto L_80008738; break;
        case 24: goto L_80008838; break;
        case 25: goto L_8000879C; break;
        case 26: goto L_800087D4; break;
        case 27: goto L_800088C8; break;
        case 28: goto L_8000879C; break;
        case 29: goto L_800087D4; break;
        case 30: goto L_800088C8; break;
        case 31: goto L_80008958; break;
        case 32: goto L_80008CA0; break;
        case 33: goto L_800086D0; break;
        case 34: goto L_80008CA0; break;
        case 35: goto L_800086D0; break;
        case 36: goto L_80008CA0; break;
        case 37: goto L_800086D0; break;
        case 38: goto L_80008CA0; break;
        case 39: goto L_800086D0; break;
        case 40: goto L_80008CA0; break;
        case 41: goto L_80008CA0; break;
        case 42: goto L_80008958; break;
        case 43: goto L_80008958; break;
        case 44: goto L_80008988; break;
        case 45: goto L_80008988; break;
        case 46: goto L_80008958; break;
        case 47: goto L_80008958; break;
        case 48: goto L_80008958; break;
        case 49: goto L_80008958; break;
        case 50: goto L_800087D4; break;
        case 51: goto L_800087D4; break;
        case 52: goto L_80008958; break;
        case 53: goto L_800088C8; break;
        case 54: goto L_800086D0; break;
        case 55: goto L_800089EC; break;
        case 56: goto L_80008A1C; break;
        case 57: goto L_80008A54; break;
        case 58: goto L_80008A8C; break;
        case 59: goto L_80008ABC; break;
        case 60: goto L_80008B20; break;
        case 61: goto L_80008BB0; break;
        case 62: goto L_80008C14; break;
        default: switch_error(__func__, 0x800086C8, 0x8003DC24);
    }
    // 0x800086CC: nop

L_800086D0:
    // 0x800086D0: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800086D4: addiu       $t6, $t6, -0x4724
    ctx->r14 = ADD32(ctx->r14, -0X4724);
    // 0x800086D8: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x800086DC: sw          $t9, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r25;
    // 0x800086E0: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x800086E4: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    // 0x800086E8: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x800086EC: sw          $t9, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r25;
    // 0x800086F0: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800086F4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800086F8: b           L_80008CA0
    // 0x800086FC: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
        goto L_80008CA0;
    // 0x800086FC: sw          $t8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r24;
L_80008700:
    // 0x80008700: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80008704: addiu       $t7, $t7, -0x4714
    ctx->r15 = ADD32(ctx->r15, -0X4714);
    // 0x80008708: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000870C: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
    // 0x80008710: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80008714: sw          $t6, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r14;
    // 0x80008718: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x8000871C: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x80008720: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x80008724: sw          $t6, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r14;
    // 0x80008728: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8000872C: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80008730: b           L_80008CA0
    // 0x80008734: sw          $t8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r24;
        goto L_80008CA0;
    // 0x80008734: sw          $t8, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r24;
L_80008738:
    // 0x80008738: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8000873C: addiu       $t9, $t9, -0x4724
    ctx->r25 = ADD32(ctx->r25, -0X4724);
    // 0x80008740: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80008744: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80008748: addiu       $t8, $t8, -0x4714
    ctx->r24 = ADD32(ctx->r24, -0X4714);
    // 0x8000874C: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x80008750: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x80008754: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x80008758: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8000875C: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x80008760: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x80008764: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x80008768: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8000876C: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x80008770: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80008774: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x80008778: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x8000877C: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80008780: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80008784: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x80008788: lw          $t7, 0x10($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X10);
    // 0x8000878C: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80008790: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80008794: b           L_80008CA0
    // 0x80008798: sw          $t7, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r15;
        goto L_80008CA0;
    // 0x80008798: sw          $t7, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r15;
L_8000879C:
    // 0x8000879C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800087A0: addiu       $t6, $t6, -0x4700
    ctx->r14 = ADD32(ctx->r14, -0X4700);
    // 0x800087A4: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x800087A8: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x800087AC: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x800087B0: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x800087B4: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x800087B8: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x800087BC: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x800087C0: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
    // 0x800087C4: lw          $t9, 0x10($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10);
    // 0x800087C8: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x800087CC: b           L_80008CA0
    // 0x800087D0: sw          $t9, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r25;
        goto L_80008CA0;
    // 0x800087D0: sw          $t9, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r25;
L_800087D4:
    // 0x800087D4: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x800087D8: addiu       $t7, $t7, -0x4724
    ctx->r15 = ADD32(ctx->r15, -0X4724);
    // 0x800087DC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800087E0: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800087E4: addiu       $t9, $t9, -0x4700
    ctx->r25 = ADD32(ctx->r25, -0X4700);
    // 0x800087E8: sw          $t8, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r24;
    // 0x800087EC: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x800087F0: sw          $t6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r14;
    // 0x800087F4: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800087F8: sw          $t8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r24;
    // 0x800087FC: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x80008800: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    // 0x80008804: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80008808: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x8000880C: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x80008810: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x80008814: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x80008818: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x8000881C: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x80008820: sw          $t7, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r15;
    // 0x80008824: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x80008828: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8000882C: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x80008830: b           L_80008CA0
    // 0x80008834: sw          $t6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r14;
        goto L_80008CA0;
    // 0x80008834: sw          $t6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r14;
L_80008838:
    // 0x80008838: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8000883C: addiu       $t8, $t8, -0x4724
    ctx->r24 = ADD32(ctx->r24, -0X4724);
    // 0x80008840: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80008844: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80008848: addiu       $t6, $t6, -0x4714
    ctx->r14 = ADD32(ctx->r14, -0X4714);
    // 0x8000884C: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x80008850: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80008854: sw          $t9, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r25;
    // 0x80008858: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x8000885C: sw          $t7, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r15;
    // 0x80008860: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80008864: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80008868: addiu       $t7, $t7, -0x46EC
    ctx->r15 = ADD32(ctx->r15, -0X46EC);
    // 0x8000886C: sw          $t9, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r25;
    // 0x80008870: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80008874: sw          $t9, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r25;
    // 0x80008878: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x8000887C: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x80008880: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x80008884: sw          $t9, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r25;
    // 0x80008888: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x8000888C: sw          $t8, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r24;
    // 0x80008890: lw          $t9, 0x10($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10);
    // 0x80008894: sw          $t9, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r25;
    // 0x80008898: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000889C: sw          $t8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r24;
    // 0x800088A0: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x800088A4: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    // 0x800088A8: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x800088AC: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x800088B0: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x800088B4: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x800088B8: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x800088BC: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x800088C0: b           L_80008CA0
    // 0x800088C4: sw          $t6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r14;
        goto L_80008CA0;
    // 0x800088C4: sw          $t6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r14;
L_800088C8:
    // 0x800088C8: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x800088CC: addiu       $t9, $t9, -0x4724
    ctx->r25 = ADD32(ctx->r25, -0X4724);
    // 0x800088D0: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800088D4: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x800088D8: addiu       $t8, $t8, -0x4700
    ctx->r24 = ADD32(ctx->r24, -0X4700);
    // 0x800088DC: sw          $t6, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r14;
    // 0x800088E0: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x800088E4: sw          $t7, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r15;
    // 0x800088E8: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x800088EC: sw          $t6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r14;
    // 0x800088F0: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x800088F4: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800088F8: addiu       $t6, $t6, -0x46EC
    ctx->r14 = ADD32(ctx->r14, -0X46EC);
    // 0x800088FC: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    // 0x80008900: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80008904: sw          $t7, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r15;
    // 0x80008908: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8000890C: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x80008910: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80008914: sw          $t7, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r15;
    // 0x80008918: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8000891C: sw          $t9, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r25;
    // 0x80008920: lw          $t7, 0x10($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X10);
    // 0x80008924: sw          $t7, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r15;
    // 0x80008928: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8000892C: sw          $t9, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r25;
    // 0x80008930: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80008934: sw          $t8, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r24;
    // 0x80008938: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x8000893C: sw          $t9, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r25;
    // 0x80008940: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80008944: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x80008948: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x8000894C: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80008950: b           L_80008CA0
    // 0x80008954: sw          $t8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r24;
        goto L_80008CA0;
    // 0x80008954: sw          $t8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r24;
L_80008958:
    // 0x80008958: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x8000895C: addiu       $t7, $t7, -0x46EC
    ctx->r15 = ADD32(ctx->r15, -0X46EC);
    // 0x80008960: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80008964: sw          $t8, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r24;
    // 0x80008968: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x8000896C: sw          $t6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r14;
    // 0x80008970: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80008974: sw          $t8, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r24;
    // 0x80008978: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x8000897C: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x80008980: b           L_80008CA0
    // 0x80008984: sw          $t6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r14;
        goto L_80008CA0;
    // 0x80008984: sw          $t6, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r14;
L_80008988:
    // 0x80008988: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x8000898C: addiu       $t9, $t9, -0x4714
    ctx->r25 = ADD32(ctx->r25, -0X4714);
    // 0x80008990: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80008994: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80008998: addiu       $t8, $t8, -0x46EC
    ctx->r24 = ADD32(ctx->r24, -0X46EC);
    // 0x8000899C: sw          $t6, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r14;
    // 0x800089A0: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x800089A4: sw          $t7, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r15;
    // 0x800089A8: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x800089AC: sw          $t6, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r14;
    // 0x800089B0: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x800089B4: sw          $t7, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r15;
    // 0x800089B8: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x800089BC: sw          $t6, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r14;
    // 0x800089C0: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x800089C4: sw          $t7, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r15;
    // 0x800089C8: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x800089CC: sw          $t9, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->r25;
    // 0x800089D0: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x800089D4: sw          $t7, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->r15;
    // 0x800089D8: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x800089DC: sw          $v0, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r2;
    // 0x800089E0: sw          $v0, 0x3C($s0)
    MEM_W(0X3C, ctx->r16) = ctx->r2;
    // 0x800089E4: b           L_80008CA0
    // 0x800089E8: sw          $t9, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r25;
        goto L_80008CA0;
    // 0x800089E8: sw          $t9, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->r25;
L_800089EC:
    // 0x800089EC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x800089F0: addiu       $t6, $t6, -0x4724
    ctx->r14 = ADD32(ctx->r14, -0X4724);
    // 0x800089F4: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x800089F8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800089FC: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80008A00: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80008A04: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x80008A08: sw          $t9, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r25;
    // 0x80008A0C: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80008A10: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x80008A14: b           L_80008CA0
    // 0x80008A18: sw          $t8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r24;
        goto L_80008CA0;
    // 0x80008A18: sw          $t8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r24;
L_80008A1C:
    // 0x80008A1C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80008A20: addiu       $t7, $t7, -0x4714
    ctx->r15 = ADD32(ctx->r15, -0X4714);
    // 0x80008A24: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80008A28: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80008A2C: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80008A30: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80008A34: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80008A38: sw          $t8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r24;
    // 0x80008A3C: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x80008A40: sw          $t6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r14;
    // 0x80008A44: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80008A48: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80008A4C: b           L_80008CA0
    // 0x80008A50: sw          $t8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r24;
        goto L_80008CA0;
    // 0x80008A50: sw          $t8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r24;
L_80008A54:
    // 0x80008A54: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80008A58: addiu       $t9, $t9, -0x4700
    ctx->r25 = ADD32(ctx->r25, -0X4700);
    // 0x80008A5C: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80008A60: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80008A64: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x80008A68: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x80008A6C: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x80008A70: sw          $t6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r14;
    // 0x80008A74: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x80008A78: sw          $t7, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r15;
    // 0x80008A7C: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x80008A80: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80008A84: b           L_80008CA0
    // 0x80008A88: sw          $t6, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r14;
        goto L_80008CA0;
    // 0x80008A88: sw          $t6, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r14;
L_80008A8C:
    // 0x80008A8C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80008A90: addiu       $t8, $t8, -0x46EC
    ctx->r24 = ADD32(ctx->r24, -0X46EC);
    // 0x80008A94: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80008A98: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x80008A9C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80008AA0: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x80008AA4: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80008AA8: sw          $t7, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r15;
    // 0x80008AAC: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80008AB0: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x80008AB4: b           L_80008CA0
    // 0x80008AB8: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
        goto L_80008CA0;
    // 0x80008AB8: sw          $t9, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r25;
L_80008ABC:
    // 0x80008ABC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80008AC0: addiu       $t6, $t6, -0x4724
    ctx->r14 = ADD32(ctx->r14, -0X4724);
    // 0x80008AC4: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80008AC8: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80008ACC: addiu       $t7, $t7, -0x4714
    ctx->r15 = ADD32(ctx->r15, -0X4714);
    // 0x80008AD0: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80008AD4: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80008AD8: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x80008ADC: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x80008AE0: sw          $t9, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r25;
    // 0x80008AE4: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80008AE8: sw          $t8, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r24;
    // 0x80008AEC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80008AF0: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80008AF4: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80008AF8: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x80008AFC: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80008B00: sw          $t8, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r24;
    // 0x80008B04: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x80008B08: sw          $t6, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r14;
    // 0x80008B0C: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80008B10: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80008B14: sw          $t8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r24;
    // 0x80008B18: b           L_80008CA0
    // 0x80008B1C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
        goto L_80008CA0;
    // 0x80008B1C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
L_80008B20:
    // 0x80008B20: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80008B24: addiu       $t9, $t9, -0x4724
    ctx->r25 = ADD32(ctx->r25, -0X4724);
    // 0x80008B28: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80008B2C: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80008B30: addiu       $t8, $t8, -0x4714
    ctx->r24 = ADD32(ctx->r24, -0X4714);
    // 0x80008B34: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80008B38: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x80008B3C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80008B40: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x80008B44: sw          $t6, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r14;
    // 0x80008B48: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x80008B4C: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80008B50: addiu       $t6, $t6, -0x46EC
    ctx->r14 = ADD32(ctx->r14, -0X46EC);
    // 0x80008B54: sw          $t7, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r15;
    // 0x80008B58: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80008B5C: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80008B60: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80008B64: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x80008B68: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80008B6C: sw          $t7, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r15;
    // 0x80008B70: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80008B74: sw          $t9, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r25;
    // 0x80008B78: lw          $t7, 0x10($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X10);
    // 0x80008B7C: sw          $t7, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r15;
    // 0x80008B80: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80008B84: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x80008B88: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80008B8C: sw          $t8, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r24;
    // 0x80008B90: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x80008B94: sw          $t9, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r25;
    // 0x80008B98: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80008B9C: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x80008BA0: sw          $t8, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r24;
    // 0x80008BA4: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80008BA8: b           L_80008CA0
    // 0x80008BAC: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
        goto L_80008CA0;
    // 0x80008BAC: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
L_80008BB0:
    // 0x80008BB0: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80008BB4: addiu       $t7, $t7, -0x4724
    ctx->r15 = ADD32(ctx->r15, -0X4724);
    // 0x80008BB8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80008BBC: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80008BC0: addiu       $t9, $t9, -0x4700
    ctx->r25 = ADD32(ctx->r25, -0X4700);
    // 0x80008BC4: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80008BC8: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80008BCC: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x80008BD0: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80008BD4: sw          $t8, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r24;
    // 0x80008BD8: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x80008BDC: sw          $t6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r14;
    // 0x80008BE0: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x80008BE4: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80008BE8: lw          $t7, 0x4($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X4);
    // 0x80008BEC: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x80008BF0: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x80008BF4: sw          $t6, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r14;
    // 0x80008BF8: lw          $t7, 0xC($t9)
    ctx->r15 = MEM_W(ctx->r25, 0XC);
    // 0x80008BFC: sw          $t7, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r15;
    // 0x80008C00: lw          $t6, 0x10($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X10);
    // 0x80008C04: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80008C08: sw          $t6, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r14;
    // 0x80008C0C: b           L_80008CA0
    // 0x80008C10: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
        goto L_80008CA0;
    // 0x80008C10: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
L_80008C14:
    // 0x80008C14: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80008C18: addiu       $t8, $t8, -0x4724
    ctx->r24 = ADD32(ctx->r24, -0X4724);
    // 0x80008C1C: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80008C20: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80008C24: addiu       $t6, $t6, -0x4700
    ctx->r14 = ADD32(ctx->r14, -0X4700);
    // 0x80008C28: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x80008C2C: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80008C30: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x80008C34: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80008C38: sw          $t7, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r15;
    // 0x80008C3C: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x80008C40: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80008C44: addiu       $t7, $t7, -0x46EC
    ctx->r15 = ADD32(ctx->r15, -0X46EC);
    // 0x80008C48: sw          $t9, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r25;
    // 0x80008C4C: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80008C50: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80008C54: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80008C58: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x80008C5C: lw          $t9, 0x8($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X8);
    // 0x80008C60: sw          $t9, 0x8($t1)
    MEM_W(0X8, ctx->r9) = ctx->r25;
    // 0x80008C64: lw          $t8, 0xC($t6)
    ctx->r24 = MEM_W(ctx->r14, 0XC);
    // 0x80008C68: sw          $t8, 0xC($t1)
    MEM_W(0XC, ctx->r9) = ctx->r24;
    // 0x80008C6C: lw          $t9, 0x10($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X10);
    // 0x80008C70: sw          $t9, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->r25;
    // 0x80008C74: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80008C78: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
    // 0x80008C7C: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80008C80: sw          $t6, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r14;
    // 0x80008C84: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80008C88: sw          $t8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r24;
    // 0x80008C8C: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x80008C90: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
    // 0x80008C94: sw          $t6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r14;
    // 0x80008C98: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x80008C9C: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
L_80008CA0:
    // 0x80008CA0: lbu         $t9, 0x3B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X3B);
    // 0x80008CA4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80008CA8: sb          $t9, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r25;
    // 0x80008CAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80008CB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80008CB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80008CB8: jr          $ra
    // 0x80008CBC: nop

    return;
    // 0x80008CBC: nop

;}
RECOMP_FUNC void mnCharactersMakeName(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320E4: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x801320E8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801320EC: addiu       $t7, $t7, 0x6370
    ctx->r15 = ADD32(ctx->r15, 0X6370);
    // 0x801320F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801320F4: sw          $a0, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r4;
    // 0x801320F8: addiu       $t0, $t7, 0x60
    ctx->r8 = ADD32(ctx->r15, 0X60);
    // 0x801320FC: addiu       $t6, $sp, 0x50
    ctx->r14 = ADD32(ctx->r29, 0X50);
L_80132100:
    // 0x80132100: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132104: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132108: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013210C: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132110: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132114: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132118: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8013211C: bne         $t7, $t0, L_80132100
    if (ctx->r15 != ctx->r8) {
        // 0x80132120: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132100;
    }
    // 0x80132120: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132124: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80132128: addiu       $t2, $t2, 0x63D0
    ctx->r10 = ADD32(ctx->r10, 0X63D0);
    // 0x8013212C: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x80132130: addiu       $t1, $sp, 0x20
    ctx->r9 = ADD32(ctx->r29, 0X20);
L_80132134:
    // 0x80132134: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132138: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8013213C: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80132140: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80132144: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80132148: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x8013214C: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80132150: bne         $t2, $t5, L_80132134
    if (ctx->r10 != ctx->r13) {
        // 0x80132154: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80132134;
    }
    // 0x80132154: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80132158: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013215C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132160: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80132164: jal         0x80009968
    // 0x80132168: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132168: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013216C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132170: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132174: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132178: sw          $v0, 0x6600($at)
    MEM_W(0X6600, ctx->r1) = ctx->r2;
    // 0x8013217C: sw          $v0, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r2;
    // 0x80132180: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80132184: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132188: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8013218C: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x80132190: jal         0x80009DF4
    // 0x80132194: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132194: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132198: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x8013219C: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x801321A0: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x801321A4: beq         $v0, $at, L_801321B8
    if (ctx->r2 == ctx->r1) {
        // 0x801321A8: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_801321B8;
    }
    // 0x801321A8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801321AC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801321B0: bne         $v0, $at, L_80132214
    if (ctx->r2 != ctx->r1) {
        // 0x801321B4: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80132214;
    }
    // 0x801321B4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
L_801321B8:
    // 0x801321B8: lw          $t7, 0x6A78($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A78);
    // 0x801321BC: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x801321C0: addiu       $t6, $t6, 0x28F0
    ctx->r14 = ADD32(ctx->r14, 0X28F0);
    // 0x801321C4: jal         0x800CCFDC
    // 0x801321C8: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801321C8: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    after_2:
    // 0x801321CC: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x801321D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801321D4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801321D8: lui         $at, 0x4230
    ctx->r1 = S32(0X4230 << 16);
    // 0x801321DC: andi        $t5, $t8, 0xFFDF
    ctx->r13 = ctx->r24 & 0XFFDF;
    // 0x801321E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801321E4: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801321E8: ori         $t2, $t5, 0x1
    ctx->r10 = ctx->r13 | 0X1;
    // 0x801321EC: addiu       $t1, $zero, 0x7D
    ctx->r9 = ADD32(0, 0X7D);
    // 0x801321F0: addiu       $t3, $zero, 0x45
    ctx->r11 = ADD32(0, 0X45);
    // 0x801321F4: addiu       $t4, $zero, 0x7
    ctx->r12 = ADD32(0, 0X7);
    // 0x801321F8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801321FC: sb          $t1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r9;
    // 0x80132200: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x80132204: sb          $t4, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r12;
    // 0x80132208: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x8013220C: b           L_80132270
    // 0x80132210: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
        goto L_80132270;
    // 0x80132210: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
L_80132214:
    // 0x80132214: lw          $t0, 0x6A78($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6A78);
    // 0x80132218: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x8013221C: addiu       $t7, $t7, 0x1230
    ctx->r15 = ADD32(ctx->r15, 0X1230);
    // 0x80132220: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x80132224: jal         0x800CCFDC
    // 0x80132228: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80132228: addu        $a1, $t0, $t7
    ctx->r5 = ADD32(ctx->r8, ctx->r15);
    after_3:
    // 0x8013222C: lhu         $t6, 0x24($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X24);
    // 0x80132230: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132234: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132238: lui         $at, 0x4234
    ctx->r1 = S32(0X4234 << 16);
    // 0x8013223C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132240: andi        $t9, $t6, 0xFFDF
    ctx->r25 = ctx->r14 & 0XFFDF;
    // 0x80132244: sh          $t9, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r25;
    // 0x80132248: ori         $t5, $t9, 0x1
    ctx->r13 = ctx->r25 | 0X1;
    // 0x8013224C: addiu       $t2, $zero, 0x7D
    ctx->r10 = ADD32(0, 0X7D);
    // 0x80132250: addiu       $t1, $zero, 0x45
    ctx->r9 = ADD32(0, 0X45);
    // 0x80132254: addiu       $t3, $zero, 0x7
    ctx->r11 = ADD32(0, 0X7);
    // 0x80132258: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x8013225C: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x80132260: sb          $t1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r9;
    // 0x80132264: sb          $t3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r11;
    // 0x80132268: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x8013226C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80132270:
    // 0x80132270: lw          $t4, 0xB8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XB8);
    // 0x80132274: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132278: lw          $t6, 0x6A78($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A78);
    // 0x8013227C: sll         $t0, $t4, 2
    ctx->r8 = S32(ctx->r12 << 2);
    // 0x80132280: addu        $t7, $sp, $t0
    ctx->r15 = ADD32(ctx->r29, ctx->r8);
    // 0x80132284: lw          $t7, 0x20($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X20);
    // 0x80132288: lw          $a0, 0xB4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XB4);
    // 0x8013228C: jal         0x800CCFDC
    // 0x80132290: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80132290: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    after_4:
    // 0x80132294: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80132298: addiu       $t4, $sp, 0x50
    ctx->r12 = ADD32(ctx->r29, 0X50);
    // 0x8013229C: addiu       $t0, $zero, 0x7D
    ctx->r8 = ADD32(0, 0X7D);
    // 0x801322A0: andi        $t5, $t8, 0xFFDF
    ctx->r13 = ctx->r24 & 0XFFDF;
    // 0x801322A4: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801322A8: ori         $t2, $t5, 0x1
    ctx->r10 = ctx->r13 | 0X1;
    // 0x801322AC: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801322B0: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x801322B4: addiu       $t7, $zero, 0x45
    ctx->r15 = ADD32(0, 0X45);
    // 0x801322B8: addiu       $t6, $zero, 0x7
    ctx->r14 = ADD32(0, 0X7);
    // 0x801322BC: sll         $t3, $t1, 3
    ctx->r11 = S32(ctx->r9 << 3);
    // 0x801322C0: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x801322C4: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x801322C8: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x801322CC: lwc1        $f18, 0x4($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X4);
    // 0x801322D0: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x801322D4: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x801322D8: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x801322DC: swc1        $f18, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f18.u32l;
    // 0x801322E0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801322E4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    // 0x801322E8: jr          $ra
    // 0x801322EC: nop

    return;
    // 0x801322EC: nop

;}
RECOMP_FUNC void unref_80018E1C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80018E1C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80018E20: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80018E24: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80018E28: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80018E2C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80018E30: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80018E34: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80018E38: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80018E3C: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80018E40: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80018E44: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x80018E48: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80018E4C: or          $s5, $a3, $zero
    ctx->r21 = ctx->r7 | 0;
    // 0x80018E50: beq         $t6, $zero, L_80018E90
    if (ctx->r14 == 0) {
        // 0x80018E54: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80018E90;
    }
    // 0x80018E54: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80018E58: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x80018E5C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80018E60:
    // 0x80018E60: jalr        $s2
    // 0x80018E64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    LOOKUP_FUNC(ctx->r18)(rdram, ctx);
        goto after_0;
    // 0x80018E64: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x80018E68: bnel        $v0, $zero, L_80018E7C
    if (ctx->r2 != 0) {
        // 0x80018E6C: lw          $t7, 0x0($s3)
        ctx->r15 = MEM_W(ctx->r19, 0X0);
            goto L_80018E7C;
    }
    goto skip_0;
    // 0x80018E6C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x80018E70: b           L_80018EB0
    // 0x80018E74: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
        goto L_80018EB0;
    // 0x80018E74: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80018E78: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
L_80018E7C:
    // 0x80018E7C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80018E80: addu        $s1, $s1, $s5
    ctx->r17 = ADD32(ctx->r17, ctx->r21);
    // 0x80018E84: sltu        $at, $s0, $t7
    ctx->r1 = ctx->r16 < ctx->r15 ? 1 : 0;
    // 0x80018E88: bnel        $at, $zero, L_80018E60
    if (ctx->r1 != 0) {
        // 0x80018E8C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_80018E60;
    }
    goto skip_1;
    // 0x80018E8C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    skip_1:
L_80018E90:
    // 0x80018E90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80018E94: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x80018E98: jal         0x800343E0
    // 0x80018E9C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    memcpy_recomp(rdram, ctx);
        goto after_1;
    // 0x80018E9C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_1:
    // 0x80018EA0: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x80018EA4: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80018EA8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x80018EAC: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
L_80018EB0:
    // 0x80018EB0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80018EB4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80018EB8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80018EBC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80018EC0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80018EC4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80018EC8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80018ECC: jr          $ra
    // 0x80018ED0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80018ED0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftNessSpecialLwHitSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801558D4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801558D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801558DC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x801558E0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801558E4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x801558E8: jal         0x800DEEC8
    // 0x801558EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x801558EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x801558F0: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801558F4: addiu       $t7, $zero, 0x897
    ctx->r15 = ADD32(0, 0X897);
    // 0x801558F8: addiu       $a1, $zero, 0xF3
    ctx->r5 = ADD32(0, 0XF3);
    // 0x801558FC: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80155900: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80155904: jal         0x800E6F24
    // 0x80155908: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80155908: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015590C: jal         0x800D8EB8
    // 0x80155910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsClampAirVelXMax(rdram, ctx);
        goto after_2;
    // 0x80155910: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80155914: lbu         $t9, 0x18D($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X18D);
    // 0x80155918: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x8015591C: sb          $t0, 0x18D($s0)
    MEM_B(0X18D, ctx->r16) = ctx->r8;
    // 0x80155920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80155924: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80155928: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015592C: jr          $ra
    // 0x80155930: nop

    return;
    // 0x80155930: nop

;}
RECOMP_FUNC void mnPlayers1PBonusSpotlightProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801364E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801364E4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801364E8: addiu       $v0, $sp, 0x0
    ctx->r2 = ADD32(ctx->r29, 0X0);
    // 0x801364EC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801364F0: addiu       $t6, $t6, 0x7500
    ctx->r14 = ADD32(ctx->r14, 0X7500);
    // 0x801364F4: addiu       $v1, $v1, 0x7648
    ctx->r3 = ADD32(ctx->r3, 0X7648);
    // 0x801364F8: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x801364FC: or          $t9, $v0, $zero
    ctx->r25 = ctx->r2 | 0;
L_80136500:
    // 0x80136500: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80136504: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80136508: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8013650C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80136510: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80136514: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80136518: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013651C: bne         $t6, $t0, L_80136500
    if (ctx->r14 != ctx->r8) {
        // 0x80136520: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80136500;
    }
    // 0x80136520: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80136524: lw          $t1, 0x58($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X58);
    // 0x80136528: bnel        $t1, $zero, L_801365AC
    if (ctx->r9 != 0) {
        // 0x8013652C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_801365AC;
    }
    goto skip_0;
    // 0x8013652C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_0:
    // 0x80136530: lw          $t2, 0x20($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X20);
    // 0x80136534: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80136538: beql        $t2, $at, L_801365AC
    if (ctx->r10 == ctx->r1) {
        // 0x8013653C: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_801365AC;
    }
    goto skip_1;
    // 0x8013653C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_1:
    // 0x80136540: lw          $t3, 0x7C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X7C);
    // 0x80136544: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80136548: bnel        $a1, $t3, L_8013655C
    if (ctx->r5 != ctx->r11) {
        // 0x8013654C: sw          $a1, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r5;
            goto L_8013655C;
    }
    goto skip_2;
    // 0x8013654C: sw          $a1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r5;
    skip_2:
    // 0x80136550: b           L_8013655C
    // 0x80136554: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_8013655C;
    // 0x80136554: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    // 0x80136558: sw          $a1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r5;
L_8013655C:
    // 0x8013655C: lw          $t4, 0x20($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X20);
    // 0x80136560: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80136564: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80136568: addu        $t0, $v0, $t5
    ctx->r8 = ADD32(ctx->r2, ctx->r13);
    // 0x8013656C: lwc1        $f4, 0x0($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80136570: swc1        $f4, 0x40($t6)
    MEM_W(0X40, ctx->r14) = ctx->f4.u32l;
    // 0x80136574: lw          $t9, 0x20($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X20);
    // 0x80136578: lw          $t1, 0x74($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X74);
    // 0x8013657C: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x80136580: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80136584: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x80136588: swc1        $f6, 0x44($t1)
    MEM_W(0X44, ctx->r9) = ctx->f6.u32l;
    // 0x8013658C: lw          $t2, 0x20($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X20);
    // 0x80136590: lw          $t5, 0x74($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X74);
    // 0x80136594: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x80136598: addu        $t4, $v0, $t3
    ctx->r12 = ADD32(ctx->r2, ctx->r11);
    // 0x8013659C: lwc1        $f8, 0x0($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0X0);
    // 0x801365A0: b           L_801365B0
    // 0x801365A4: swc1        $f8, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f8.u32l;
        goto L_801365B0;
    // 0x801365A4: swc1        $f8, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f8.u32l;
    // 0x801365A8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_801365AC:
    // 0x801365AC: sw          $a1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r5;
L_801365B0:
    // 0x801365B0: jr          $ra
    // 0x801365B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x801365B4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void gcAddGObjScriptByLink(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AD60: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000AD64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000AD68: beq         $a2, $zero, L_8000AD78
    if (ctx->r6 == 0) {
        // 0x8000AD6C: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_8000AD78;
    }
    // 0x8000AD6C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8000AD70: b           L_8000AD84
    // 0x8000AD74: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
        goto L_8000AD84;
    // 0x8000AD74: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
L_8000AD78:
    // 0x8000AD78: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8000AD7C: lw          $t6, 0x6A54($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A54);
    // 0x8000AD80: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
L_8000AD84:
    // 0x8000AD84: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8000AD88: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8000AD8C: addiu       $a1, $a1, -0x52C8
    ctx->r5 = ADD32(ctx->r5, -0X52C8);
    // 0x8000AD90: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x8000AD94: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000AD98: jal         0x8000AFE4
    // 0x8000AD9C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    gcFuncGObjByLinkEx(rdram, ctx);
        goto after_0;
    // 0x8000AD9C: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    after_0:
    // 0x8000ADA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000ADA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000ADA8: jr          $ra
    // 0x8000ADAC: nop

    return;
    // 0x8000ADAC: nop

;}
RECOMP_FUNC void ftLinkSpecialAirNEmptySwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016397C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80163980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80163984: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80163988: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8016398C: jal         0x800DEE98
    // 0x80163990: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80163990: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80163994: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80163998: addiu       $a1, $zero, 0xE7
    ctx->r5 = ADD32(0, 0XE7);
    // 0x8016399C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801639A0: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801639A4: jal         0x800E6F24
    // 0x801639A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801639A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x801639AC: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801639B0: lbu         $t8, 0x192($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X192);
    // 0x801639B4: ori         $t9, $t8, 0x80
    ctx->r25 = ctx->r24 | 0X80;
    // 0x801639B8: sb          $t9, 0x192($v0)
    MEM_B(0X192, ctx->r2) = ctx->r25;
    // 0x801639BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801639C0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801639C4: jr          $ra
    // 0x801639C8: nop

    return;
    // 0x801639C8: nop

;}
RECOMP_FUNC void ftMainSetHitRebound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E287C: lw          $v0, 0xC($a2)
    ctx->r2 = MEM_W(ctx->r6, 0XC);
    // 0x800E2880: lw          $t6, 0x7BC($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X7BC);
    // 0x800E2884: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E2888: beq         $at, $zero, L_800E2908
    if (ctx->r1 == 0) {
        // 0x800E288C: nop
    
            goto L_800E2908;
    }
    // 0x800E288C: nop

    // 0x800E2890: sw          $v0, 0x7BC($a1)
    MEM_W(0X7BC, ctx->r5) = ctx->r2;
    // 0x800E2894: lw          $t7, 0x3C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X3C);
    // 0x800E2898: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x800E289C: bgez        $t9, L_800E2908
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800E28A0: nop
    
            goto L_800E2908;
    }
    // 0x800E28A0: nop

    // 0x800E28A4: lw          $t0, 0x14C($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X14C);
    // 0x800E28A8: bne         $t0, $zero, L_800E2908
    if (ctx->r8 != 0) {
        // 0x800E28AC: nop
    
            goto L_800E2908;
    }
    // 0x800E28AC: nop

    // 0x800E28B0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800E28B4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E28B8: lwc1        $f8, -0x1CC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X1CC);
    // 0x800E28BC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E28C0: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800E28C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800E28C8: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800E28CC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800E28D0: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800E28D4: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800E28D8: swc1        $f18, 0x7C0($a1)
    MEM_W(0X7C0, ctx->r5) = ctx->f18.u32l;
    // 0x800E28DC: lw          $t3, 0x74($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X74);
    // 0x800E28E0: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x800E28E4: lwc1        $f6, 0x1C($t3)
    ctx->f6.u32l = MEM_W(ctx->r11, 0X1C);
    // 0x800E28E8: lwc1        $f4, 0x1C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x800E28EC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800E28F0: nop

    // 0x800E28F4: bc1fl       L_800E2908
    if (!c1cs) {
        // 0x800E28F8: sw          $t5, 0x7C4($a1)
        MEM_W(0X7C4, ctx->r5) = ctx->r13;
            goto L_800E2908;
    }
    goto skip_0;
    // 0x800E28F8: sw          $t5, 0x7C4($a1)
    MEM_W(0X7C4, ctx->r5) = ctx->r13;
    skip_0:
    // 0x800E28FC: jr          $ra
    // 0x800E2900: sw          $t4, 0x7C4($a1)
    MEM_W(0X7C4, ctx->r5) = ctx->r12;
    return;
    // 0x800E2900: sw          $t4, 0x7C4($a1)
    MEM_W(0X7C4, ctx->r5) = ctx->r12;
    // 0x800E2904: sw          $t5, 0x7C4($a1)
    MEM_W(0X7C4, ctx->r5) = ctx->r13;
L_800E2908:
    // 0x800E2908: jr          $ra
    // 0x800E290C: nop

    return;
    // 0x800E290C: nop

;}
RECOMP_FUNC void n_alSynDelete(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002FD80: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x8002FD84: addiu       $v0, $v0, -0x2CEC
    ctx->r2 = ADD32(ctx->r2, -0X2CEC);
    // 0x8002FD88: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002FD8C: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8002FD90: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8002FD94: sw          $zero, 0x4($t7)
    MEM_W(0X4, ctx->r15) = 0;
    // 0x8002FD98: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8002FD9C: sw          $zero, 0x8($t8)
    MEM_W(0X8, ctx->r24) = 0;
    // 0x8002FDA0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8002FDA4: jr          $ra
    // 0x8002FDA8: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
    return;
    // 0x8002FDA8: sw          $zero, 0xC($t9)
    MEM_W(0XC, ctx->r25) = 0;
;}
RECOMP_FUNC void sc1PChallengerMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E3C: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x80131E40: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80131E44: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80131E48: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x80131E4C: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x80131E50: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131E54: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x80131E58: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
L_80131E5C:
    // 0x80131E5C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131E60: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131E64: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131E68: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131E6C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131E70: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131E74: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131E78: bne         $t6, $t0, L_80131E5C
    if (ctx->r14 != ctx->r8) {
        // 0x80131E7C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131E5C;
    }
    // 0x80131E7C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131E80: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131E84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E88: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80131E8C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80131E90: jal         0x800EC0EC
    // 0x80131E94: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80131E94: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_0:
    // 0x80131E98: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80131E9C: lw          $t1, 0x248C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X248C);
    // 0x80131EA0: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x80131EA4: sb          $zero, 0x39($sp)
    MEM_B(0X39, ctx->r29) = 0;
    // 0x80131EA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131EAC: jal         0x800D7F3C
    // 0x80131EB0: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x80131EB0: sw          $t1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r9;
    after_1:
    // 0x80131EB4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131EB8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80131EBC: addiu       $a1, $a1, 0x1DF4
    ctx->r5 = ADD32(ctx->r5, 0X1DF4);
    // 0x80131EC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131EC4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80131EC8: jal         0x80008188
    // 0x80131ECC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_2;
    // 0x80131ECC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x80131ED0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131ED4: lwc1        $f4, 0x2468($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2468);
    // 0x80131ED8: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80131EDC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131EE0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80131EE4: swc1        $f4, 0x1C($t2)
    MEM_W(0X1C, ctx->r10) = ctx->f4.u32l;
    // 0x80131EE8: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80131EEC: lwc1        $f6, 0x246C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X246C);
    // 0x80131EF0: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80131EF4: addiu       $t6, $t6, 0xD90
    ctx->r14 = ADD32(ctx->r14, 0XD90);
    // 0x80131EF8: swc1        $f6, 0x20($t3)
    MEM_W(0X20, ctx->r11) = ctx->f6.u32l;
    // 0x80131EFC: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x80131F00: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80131F04: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80131F08: swc1        $f8, 0x24($t4)
    MEM_W(0X24, ctx->r12) = ctx->f8.u32l;
    // 0x80131F0C: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x80131F10: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80131F14: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131F18: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x80131F1C: addu        $v1, $t0, $t6
    ctx->r3 = ADD32(ctx->r8, ctx->r14);
    // 0x80131F20: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131F24: swc1        $f10, 0x40($t9)
    MEM_W(0X40, ctx->r25) = ctx->f10.u32l;
    // 0x80131F28: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80131F2C: lwc1        $f16, 0x0($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131F30: swc1        $f16, 0x44($t7)
    MEM_W(0X44, ctx->r15) = ctx->f16.u32l;
    // 0x80131F34: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x80131F38: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80131F3C: jal         0x800E9814
    // 0x80131F40: swc1        $f18, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f18.u32l;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_3;
    // 0x80131F40: swc1        $f18, 0x48($t8)
    MEM_W(0X48, ctx->r24) = ctx->f18.u32l;
    after_3:
    // 0x80131F44: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131F48: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80131F4C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80131F50: jr          $ra
    // 0x80131F54: nop

    return;
    // 0x80131F54: nop

;}
RECOMP_FUNC void func_ovl8_8037CA50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037CA50: sw          $zero, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = 0;
    // 0x8037CA54: jr          $ra
    // 0x8037CA58: sw          $zero, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = 0;
    return;
    // 0x8037CA58: sw          $zero, 0xB0($a0)
    MEM_W(0XB0, ctx->r4) = 0;
;}
RECOMP_FUNC void n_alMainBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8002C64C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8002C650: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x8002C654: ori         $t6, $t6, 0x4E0
    ctx->r14 = ctx->r14 | 0X4E0;
    // 0x8002C658: addiu       $t7, $zero, 0x2E0
    ctx->r15 = ADD32(0, 0X2E0);
    // 0x8002C65C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8002C660: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8002C664: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8002C668: lw          $t8, -0x2CEC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2CEC);
    // 0x8002C66C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8002C670: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x8002C674: lw          $t9, 0x4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X4);
    // 0x8002C678: jalr        $t9
    // 0x8002C67C: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x8002C67C: nop

    after_0:
    // 0x8002C680: lui         $v1, 0xC00
    ctx->r3 = S32(0XC00 << 16);
    // 0x8002C684: ori         $v1, $v1, 0x7FFF
    ctx->r3 = ctx->r3 | 0X7FFF;
    // 0x8002C688: lui         $t0, 0x7C0
    ctx->r8 = S32(0X7C0 << 16);
    // 0x8002C68C: lui         $t1, 0x930
    ctx->r9 = S32(0X930 << 16);
    // 0x8002C690: ori         $t0, $t0, 0x4E0
    ctx->r8 = ctx->r8 | 0X4E0;
    // 0x8002C694: ori         $t1, $t1, 0x650
    ctx->r9 = ctx->r9 | 0X650;
    // 0x8002C698: sw          $t0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r8;
    // 0x8002C69C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8002C6A0: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
    // 0x8002C6A4: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x8002C6A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8002C6AC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8002C6B0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8002C6B4: jr          $ra
    // 0x8002C6B8: nop

    return;
    // 0x8002C6B8: nop

;}
RECOMP_FUNC void func_ovl8_8037AA88(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037AA88: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x8037AA8C: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x8037AA90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8037AA94: subu        $v0, $a2, $a0
    ctx->r2 = SUB32(ctx->r6, ctx->r4);
    // 0x8037AA98: subu        $t6, $a3, $a1
    ctx->r14 = SUB32(ctx->r7, ctx->r5);
    // 0x8037AA9C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8037AAA0: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x8037AAA4: sw          $a0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r4;
    // 0x8037AAA8: bne         $v0, $zero, L_8037AAB8
    if (ctx->r2 != 0) {
        // 0x8037AAAC: sw          $a1, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->r5;
            goto L_8037AAB8;
    }
    // 0x8037AAAC: sw          $a1, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r5;
    // 0x8037AAB0: b           L_8037AAD4
    // 0x8037AAB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037AAD4;
    // 0x8037AAB4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037AAB8:
    // 0x8037AAB8: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8037AABC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8037AAC0: blez        $t7, L_8037AAD0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8037AAC4: nop
    
            goto L_8037AAD0;
    }
    // 0x8037AAC4: nop

    // 0x8037AAC8: b           L_8037AAD0
    // 0x8037AACC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8037AAD0;
    // 0x8037AACC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8037AAD0:
    // 0x8037AAD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8037AAD4:
    // 0x8037AAD4: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8037AAD8: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x8037AADC: bne         $v1, $zero, L_8037AAEC
    if (ctx->r3 != 0) {
        // 0x8037AAE0: nop
    
            goto L_8037AAEC;
    }
    // 0x8037AAE0: nop

    // 0x8037AAE4: b           L_8037AB04
    // 0x8037AAE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8037AB04;
    // 0x8037AAE8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8037AAEC:
    // 0x8037AAEC: blezl       $v1, L_8037AB00
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8037AAF0: addiu       $v1, $zero, -0x1
        ctx->r3 = ADD32(0, -0X1);
            goto L_8037AB00;
    }
    goto skip_0;
    // 0x8037AAF0: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    skip_0:
    // 0x8037AAF4: b           L_8037AB00
    // 0x8037AAF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_8037AB00;
    // 0x8037AAF8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8037AAFC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_8037AB00:
    // 0x8037AB00: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8037AB04:
    // 0x8037AB04: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8037AB08: sw          $v0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r2;
    // 0x8037AB0C: addiu       $t4, $s0, 0x24
    ctx->r12 = ADD32(ctx->r16, 0X24);
    // 0x8037AB10: bgez        $v1, L_8037AB20
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8037AB14: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8037AB20;
    }
    // 0x8037AB14: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037AB18: b           L_8037AB20
    // 0x8037AB1C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8037AB20;
    // 0x8037AB1C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8037AB20:
    // 0x8037AB20: lw          $v1, 0x4($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4);
    // 0x8037AB24: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8037AB28: addiu       $t5, $s0, 0x20
    ctx->r13 = ADD32(ctx->r16, 0X20);
    // 0x8037AB2C: bgez        $v1, L_8037AB3C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8037AB30: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8037AB3C;
    }
    // 0x8037AB30: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8037AB34: b           L_8037AB3C
    // 0x8037AB38: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
        goto L_8037AB3C;
    // 0x8037AB38: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
L_8037AB3C:
    // 0x8037AB3C: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8037AB40: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x8037AB44: addiu       $t6, $s0, 0x4
    ctx->r14 = ADD32(ctx->r16, 0X4);
    // 0x8037AB48: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8037AB4C: beq         $at, $zero, L_8037AB88
    if (ctx->r1 == 0) {
        // 0x8037AB50: addiu       $t7, $s0, 0x14
        ctx->r15 = ADD32(ctx->r16, 0X14);
            goto L_8037AB88;
    }
    // 0x8037AB50: addiu       $t7, $s0, 0x14
    ctx->r15 = ADD32(ctx->r16, 0X14);
    // 0x8037AB54: addiu       $t8, $s0, 0x20
    ctx->r24 = ADD32(ctx->r16, 0X20);
    // 0x8037AB58: addiu       $t9, $s0, 0x24
    ctx->r25 = ADD32(ctx->r16, 0X24);
    // 0x8037AB5C: addiu       $t0, $s0, 0x4
    ctx->r8 = ADD32(ctx->r16, 0X4);
    // 0x8037AB60: addiu       $t1, $s0, 0x10
    ctx->r9 = ADD32(ctx->r16, 0X10);
    // 0x8037AB64: addiu       $t2, $s0, 0x14
    ctx->r10 = ADD32(ctx->r16, 0X14);
    // 0x8037AB68: sw          $v1, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r3;
    // 0x8037AB6C: sw          $t8, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r24;
    // 0x8037AB70: sw          $t9, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r25;
    // 0x8037AB74: sw          $s0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r16;
    // 0x8037AB78: sw          $t0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r8;
    // 0x8037AB7C: sw          $t1, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r9;
    // 0x8037AB80: b           L_8037ABAC
    // 0x8037AB84: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
        goto L_8037ABAC;
    // 0x8037AB84: sw          $t2, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r10;
L_8037AB88:
    // 0x8037AB88: lw          $t3, 0x4($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4);
    // 0x8037AB8C: addiu       $t8, $s0, 0x10
    ctx->r24 = ADD32(ctx->r16, 0X10);
    // 0x8037AB90: sw          $t4, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r12;
    // 0x8037AB94: sw          $t5, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r13;
    // 0x8037AB98: sw          $t6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r14;
    // 0x8037AB9C: sw          $s0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r16;
    // 0x8037ABA0: sw          $t7, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r15;
    // 0x8037ABA4: sw          $t8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r24;
    // 0x8037ABA8: sw          $t3, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r11;
L_8037ABAC:
    // 0x8037ABAC: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8037ABB0: lw          $t2, 0x30($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X30);
    // 0x8037ABB4: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8037ABB8: sw          $t2, 0x38($s0)
    MEM_W(0X38, ctx->r16) = ctx->r10;
    // 0x8037ABBC: bgez        $t0, L_8037ABCC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8037ABC0: sra         $t1, $t0, 1
        ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
            goto L_8037ABCC;
    }
    // 0x8037ABC0: sra         $t1, $t0, 1
    ctx->r9 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8037ABC4: addiu       $at, $t0, 0x1
    ctx->r1 = ADD32(ctx->r8, 0X1);
    // 0x8037ABC8: sra         $t1, $at, 1
    ctx->r9 = S32(SIGNED(ctx->r1) >> 1);
L_8037ABCC:
    // 0x8037ABCC: sw          $t1, 0x34($s0)
    MEM_W(0X34, ctx->r16) = ctx->r9;
    // 0x8037ABD0: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x8037ABD4: jr          $ra
    // 0x8037ABD8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x8037ABD8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void ftLinkSpecialHiProcStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016426C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80164270: sw          $zero, 0x17C($v0)
    MEM_W(0X17C, ctx->r2) = 0;
    // 0x80164274: sw          $zero, 0x184($v0)
    MEM_W(0X184, ctx->r2) = 0;
    // 0x80164278: sw          $zero, 0x180($v0)
    MEM_W(0X180, ctx->r2) = 0;
    // 0x8016427C: jr          $ra
    // 0x80164280: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
    return;
    // 0x80164280: sw          $zero, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = 0;
;}
RECOMP_FUNC void ftMainCheckAddGroundHazard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E1DE8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800E1DEC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800E1DF0: addiu       $v0, $v0, 0x1198
    ctx->r2 = ADD32(ctx->r2, 0X1198);
    // 0x800E1DF4: addiu       $v1, $v1, 0x1190
    ctx->r3 = ADD32(ctx->r3, 0X1190);
    // 0x800E1DF8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
L_800E1DFC:
    // 0x800E1DFC: bne         $t6, $zero, L_800E1E24
    if (ctx->r14 != 0) {
        // 0x800E1E00: lui         $a2, 0x8013
        ctx->r6 = S32(0X8013 << 16);
            goto L_800E1E24;
    }
    // 0x800E1E00: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800E1E04: addiu       $a2, $a2, 0x119C
    ctx->r6 = ADD32(ctx->r6, 0X119C);
    // 0x800E1E08: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800E1E0C: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
    // 0x800E1E10: sw          $a1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r5;
    // 0x800E1E14: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800E1E18: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x800E1E1C: jr          $ra
    // 0x800E1E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800E1E20: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800E1E24:
    // 0x800E1E24: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800E1E28: bnel        $v1, $v0, L_800E1DFC
    if (ctx->r3 != ctx->r2) {
        // 0x800E1E2C: lw          $t6, 0x0($v1)
        ctx->r14 = MEM_W(ctx->r3, 0X0);
            goto L_800E1DFC;
    }
    goto skip_0;
    // 0x800E1E2C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    skip_0:
    // 0x800E1E30: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800E1E34: jr          $ra
    // 0x800E1E38: nop

    return;
    // 0x800E1E38: nop

;}
RECOMP_FUNC void mnPlayersVSInitPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013AC7C: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8013AC80: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8013AC84: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x8013AC88: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8013AC8C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x8013AC90: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x8013AC94: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013AC98: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x8013AC9C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x8013ACA0: subu        $t8, $t8, $a0
    ctx->r24 = SUB32(ctx->r24, ctx->r4);
    // 0x8013ACA4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013ACA8: addu        $t8, $t8, $a0
    ctx->r24 = ADD32(ctx->r24, ctx->r4);
    // 0x8013ACAC: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8013ACB0: addiu       $t9, $t9, 0x4D08
    ctx->r25 = ADD32(ctx->r25, 0X4D08);
    // 0x8013ACB4: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8013ACB8: addu        $v1, $t8, $t9
    ctx->r3 = ADD32(ctx->r24, ctx->r25);
    // 0x8013ACBC: lbu         $a1, 0x22($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X22);
    // 0x8013ACC0: lbu         $t0, 0x23($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X23);
    // 0x8013ACC4: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x8013ACC8: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x8013ACCC: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x8013ACD0: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x8013ACD4: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x8013ACD8: sw          $zero, 0xA8($v0)
    MEM_W(0XA8, ctx->r2) = 0;
    // 0x8013ACDC: sh          $zero, 0xAC($v0)
    MEM_H(0XAC, ctx->r2) = 0;
    // 0x8013ACE0: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8013ACE4: bne         $a1, $zero, L_8013AD1C
    if (ctx->r5 != 0) {
        // 0x8013ACE8: sw          $t0, 0x48($v0)
        MEM_W(0X48, ctx->r2) = ctx->r8;
            goto L_8013AD1C;
    }
    // 0x8013ACE8: sw          $t0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r8;
    // 0x8013ACEC: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8013ACF0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8013ACF4: addu        $a2, $a2, $t1
    ctx->r6 = ADD32(ctx->r6, ctx->r9);
    // 0x8013ACF8: lw          $a2, -0x4270($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4270);
    // 0x8013ACFC: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8013AD00: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8013AD04: bnel        $a3, $a2, L_8013AD20
    if (ctx->r7 != ctx->r6) {
        // 0x8013AD08: sw          $a1, 0x84($v0)
        MEM_W(0X84, ctx->r2) = ctx->r5;
            goto L_8013AD20;
    }
    goto skip_0;
    // 0x8013AD08: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
    skip_0:
    // 0x8013AD0C: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x8013AD10: sw          $t2, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r10;
    // 0x8013AD14: b           L_8013AD38
    // 0x8013AD18: sw          $a1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r5;
        goto L_8013AD38;
    // 0x8013AD18: sw          $a1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r5;
L_8013AD1C:
    // 0x8013AD1C: sw          $a1, 0x84($v0)
    MEM_W(0X84, ctx->r2) = ctx->r5;
L_8013AD20:
    // 0x8013AD20: sll         $t3, $a0, 2
    ctx->r11 = S32(ctx->r4 << 2);
    // 0x8013AD24: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x8013AD28: addu        $a2, $a2, $t3
    ctx->r6 = ADD32(ctx->r6, ctx->r11);
    // 0x8013AD2C: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8013AD30: lw          $a2, -0x4270($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4270);
    // 0x8013AD34: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
L_8013AD38:
    // 0x8013AD38: lw          $t7, 0x84($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X84);
    // 0x8013AD3C: lbu         $t4, 0x20($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X20);
    // 0x8013AD40: lbu         $t5, 0x21($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X21);
    // 0x8013AD44: lbu         $t6, 0x24($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X24);
    // 0x8013AD48: sw          $t4, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r12;
    // 0x8013AD4C: sw          $t5, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r13;
    // 0x8013AD50: bne         $t7, $zero, L_8013AD70
    if (ctx->r15 != 0) {
        // 0x8013AD54: sw          $t6, 0x40($v0)
        MEM_W(0X40, ctx->r2) = ctx->r14;
            goto L_8013AD70;
    }
    // 0x8013AD54: sw          $t6, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->r14;
    // 0x8013AD58: lw          $t8, 0x48($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X48);
    // 0x8013AD5C: bnel        $a1, $t8, L_8013AD74
    if (ctx->r5 != ctx->r24) {
        // 0x8013AD60: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_8013AD74;
    }
    goto skip_1;
    // 0x8013AD60: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    skip_1:
    // 0x8013AD64: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
    // 0x8013AD68: b           L_8013AD7C
    // 0x8013AD6C: sw          $a0, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r4;
        goto L_8013AD7C;
    // 0x8013AD6C: sw          $a0, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r4;
L_8013AD70:
    // 0x8013AD70: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
L_8013AD74:
    // 0x8013AD74: sw          $t9, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r25;
    // 0x8013AD78: sw          $a3, 0x80($v0)
    MEM_W(0X80, ctx->r2) = ctx->r7;
L_8013AD7C:
    // 0x8013AD7C: lw          $t0, 0x48($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X48);
    // 0x8013AD80: bnel        $a1, $t0, L_8013ADA0
    if (ctx->r5 != ctx->r8) {
        // 0x8013AD84: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8013ADA0;
    }
    goto skip_2;
    // 0x8013AD84: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    skip_2:
    // 0x8013AD88: sw          $zero, 0x88($v0)
    MEM_W(0X88, ctx->r2) = 0;
    // 0x8013AD8C: sw          $zero, 0x58($v0)
    MEM_W(0X58, ctx->r2) = 0;
    // 0x8013AD90: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x8013AD94: b           L_8013ADB0
    // 0x8013AD98: sw          $zero, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = 0;
        goto L_8013ADB0;
    // 0x8013AD98: sw          $zero, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = 0;
    // 0x8013AD9C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8013ADA0:
    // 0x8013ADA0: sw          $a1, 0x88($v0)
    MEM_W(0X88, ctx->r2) = ctx->r5;
    // 0x8013ADA4: sw          $a1, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r5;
    // 0x8013ADA8: sw          $zero, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = 0;
    // 0x8013ADAC: sw          $zero, 0x8C($v0)
    MEM_W(0X8C, ctx->r2) = 0;
L_8013ADB0:
    // 0x8013ADB0: lbu         $t1, 0x26($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X26);
    // 0x8013ADB4: lbu         $t2, 0x27($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X27);
    // 0x8013ADB8: sw          $t1, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r9;
    // 0x8013ADBC: beq         $a3, $a2, L_8013ADD8
    if (ctx->r7 == ctx->r6) {
        // 0x8013ADC0: sw          $t2, 0x50($v0)
        MEM_W(0X50, ctx->r2) = ctx->r10;
            goto L_8013ADD8;
    }
    // 0x8013ADC0: sw          $t2, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r10;
    // 0x8013ADC4: lw          $t3, 0x84($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X84);
    // 0x8013ADC8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013ADCC: bne         $t3, $at, L_8013ADD8
    if (ctx->r11 != ctx->r1) {
        // 0x8013ADD0: nop
    
            goto L_8013ADD8;
    }
    // 0x8013ADD0: nop

    // 0x8013ADD4: sw          $a0, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r4;
L_8013ADD8:
    // 0x8013ADD8: jr          $ra
    // 0x8013ADDC: nop

    return;
    // 0x8013ADDC: nop

;}
RECOMP_FUNC void ftParamGetGroundHazardKnockback(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9FC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E9FC4: beq         $a3, $zero, L_800EA088
    if (ctx->r7 == 0) {
        // 0x800E9FC8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800EA088;
    }
    // 0x800E9FC8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E9FCC: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800E9FD0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800E9FD4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800E9FD8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800E9FDC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800E9FE0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800E9FE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9FE8: lwc1        $f16, -0xD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0XD0);
    // 0x800E9FEC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x800E9FF0: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800E9FF4: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800E9FF8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800E9FFC: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800EA000: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800EA004: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA008: addiu       $v0, $v0, -0x37D0
    ctx->r2 = ADD32(ctx->r2, -0X37D0);
    // 0x800EA00C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800EA010: lwc1        $f10, -0xCC($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XCC);
    // 0x800EA014: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x800EA018: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800EA01C: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800EA020: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800EA024: add.s       $f6, $f12, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f18.fl;
    // 0x800EA028: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800EA02C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA030: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800EA034: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800EA038: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800EA03C: addu        $t3, $v0, $t2
    ctx->r11 = ADD32(ctx->r2, ctx->r10);
    // 0x800EA040: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800EA044: lwc1        $f10, -0xC8($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0XC8);
    // 0x800EA048: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EA04C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800EA050: add.s       $f6, $f16, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800EA054: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800EA058: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800EA05C: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800EA060: lwc1        $f16, -0x8($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, -0X8);
    // 0x800EA064: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800EA068: lwc1        $f18, -0x4($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, -0X4);
    // 0x800EA06C: mul.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800EA070: nop

    // 0x800EA074: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800EA078: nop

    // 0x800EA07C: mul.s       $f2, $f18, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800EA080: b           L_800EA150
    // 0x800EA084: nop

        goto L_800EA150;
    // 0x800EA084: nop

L_800EA088:
    // 0x800EA088: addu        $t4, $a0, $a1
    ctx->r12 = ADD32(ctx->r4, ctx->r5);
    // 0x800EA08C: mtc1        $t4, $f8
    ctx->f8.u32l = ctx->r12;
    // 0x800EA090: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x800EA094: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800EA098: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800EA09C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800EA0A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA0A4: lwc1        $f18, -0xC4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0XC4);
    // 0x800EA0A8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA0AC: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800EA0B0: lwc1        $f8, -0xC0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XC0);
    // 0x800EA0B4: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x800EA0B8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA0BC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800EA0C0: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800EA0C4: mul.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800EA0C8: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800EA0CC: addiu       $v0, $v0, -0x37D0
    ctx->r2 = ADD32(ctx->r2, -0X37D0);
    // 0x800EA0D0: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800EA0D4: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800EA0D8: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x800EA0DC: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800EA0E0: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800EA0E4: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800EA0E8: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800EA0EC: lwc1        $f8, -0xBC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XBC);
    // 0x800EA0F0: lui         $at, 0x4190
    ctx->r1 = S32(0X4190 << 16);
    // 0x800EA0F4: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x800EA0F8: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800EA0FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800EA100: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA104: mul.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800EA108: mtc1        $t5, $f16
    ctx->f16.u32l = ctx->r13;
    // 0x800EA10C: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800EA110: lwc1        $f8, -0xB8($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0XB8);
    // 0x800EA114: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EA118: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800EA11C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800EA120: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800EA124: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800EA128: mul.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800EA12C: lwc1        $f10, -0x8($t9)
    ctx->f10.u32l = MEM_W(ctx->r25, -0X8);
    // 0x800EA130: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x800EA134: lwc1        $f4, -0x4($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, -0X4);
    // 0x800EA138: mul.s       $f6, $f8, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x800EA13C: nop

    // 0x800EA140: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800EA144: nop

    // 0x800EA148: mul.s       $f2, $f4, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f16.fl);
    // 0x800EA14C: nop

L_800EA150:
    // 0x800EA150: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800EA154: lwc1        $f0, -0xB4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XB4);
    // 0x800EA158: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x800EA15C: c.le.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl <= ctx->f2.fl;
    // 0x800EA160: nop

    // 0x800EA164: bc1f        L_800EA170
    if (!c1cs) {
        // 0x800EA168: nop
    
            goto L_800EA170;
    }
    // 0x800EA168: nop

    // 0x800EA16C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800EA170:
    // 0x800EA170: lbu         $t3, 0x4AC2($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4AC2);
    // 0x800EA174: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x800EA178: beql        $t4, $zero, L_800EA1A0
    if (ctx->r12 == 0) {
        // 0x800EA17C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800EA1A0;
    }
    goto skip_0;
    // 0x800EA17C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800EA180: jal         0x80018948
    // 0x800EA184: nop

    syUtilsRandFloat(rdram, ctx);
        goto after_0;
    // 0x800EA184: nop

    after_0:
    // 0x800EA188: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800EA18C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800EA190: nop

    // 0x800EA194: mul.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800EA198: nop

    // 0x800EA19C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800EA1A0:
    // 0x800EA1A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800EA1A4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x800EA1A8: jr          $ra
    // 0x800EA1AC: nop

    return;
    // 0x800EA1AC: nop

;}
RECOMP_FUNC void ftPhysicsApplyAirVelDrift(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D90E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D90E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D90E8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D90EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D90F0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x800D90F4: lw          $t6, 0x18C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X18C);
    // 0x800D90F8: lw          $s1, 0x9C8($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X9C8);
    // 0x800D90FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D9100: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800D9104: bgez        $t8, L_800D911C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800D9108: or          $a1, $s1, $zero
        ctx->r5 = ctx->r17 | 0;
            goto L_800D911C;
    }
    // 0x800D9108: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800D910C: jal         0x800D8DA0
    // 0x800D9110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftPhysicsApplyFastFall(rdram, ctx);
        goto after_0;
    // 0x800D9110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D9114: b           L_800D9128
    // 0x800D9118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800D9128;
    // 0x800D9118: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D911C:
    // 0x800D911C: jal         0x800D8E50
    // 0x800D9120: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyGravityDefault(rdram, ctx);
        goto after_1;
    // 0x800D9120: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800D9124: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800D9128:
    // 0x800D9128: jal         0x800D8FA8
    // 0x800D912C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsCheckClampAirVelXDecMax(rdram, ctx);
        goto after_2;
    // 0x800D912C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x800D9130: bne         $v0, $zero, L_800D914C
    if (ctx->r2 != 0) {
        // 0x800D9134: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800D914C;
    }
    // 0x800D9134: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D9138: jal         0x800D9044
    // 0x800D913C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsClampAirVelXStickDefault(rdram, ctx);
        goto after_3;
    // 0x800D913C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
    // 0x800D9140: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800D9144: jal         0x800D9074
    // 0x800D9148: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftPhysicsApplyAirVelXFriction(rdram, ctx);
        goto after_4;
    // 0x800D9148: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_4:
L_800D914C:
    // 0x800D914C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D9150: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D9154: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D9158: jr          $ra
    // 0x800D915C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D915C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void grHyruleTwisterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010A91C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x8010A920: lbu         $t6, 0x1418($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X1418);
    // 0x8010A924: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8010A928: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8010A92C: sltiu       $at, $t6, 0x7
    ctx->r1 = ctx->r14 < 0X7 ? 1 : 0;
    // 0x8010A930: beq         $at, $zero, L_8010A9B8
    if (ctx->r1 == 0) {
        // 0x8010A934: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8010A9B8;
    }
    // 0x8010A934: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8010A938: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8010A93C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010A940: addu        $at, $at, $t6
    gpr jr_addend_8010A948 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8010A944: lw          $t6, 0xB90($at)
    ctx->r14 = ADD32(ctx->r1, 0XB90);
    // 0x8010A948: jr          $t6
    // 0x8010A94C: nop

    switch (jr_addend_8010A948 >> 2) {
        case 0: goto L_8010A950; break;
        case 1: goto L_8010A960; break;
        case 2: goto L_8010A970; break;
        case 3: goto L_8010A980; break;
        case 4: goto L_8010A990; break;
        case 5: goto L_8010A9A0; break;
        case 6: goto L_8010A9B0; break;
        default: switch_error(__func__, 0x8010A948, 0x80130B90);
    }
    // 0x8010A94C: nop

L_8010A950:
    // 0x8010A950: jal         0x8010A36C
    // 0x8010A954: nop

    grHyruleTwisterUpdateSleep(rdram, ctx);
        goto after_0;
    // 0x8010A954: nop

    after_0:
    // 0x8010A958: b           L_8010A9BC
    // 0x8010A95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A9BC;
    // 0x8010A95C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A960:
    // 0x8010A960: jal         0x8010A3B4
    // 0x8010A964: nop

    grHyruleTwisterUpdateWait(rdram, ctx);
        goto after_1;
    // 0x8010A964: nop

    after_1:
    // 0x8010A968: b           L_8010A9BC
    // 0x8010A96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A9BC;
    // 0x8010A96C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A970:
    // 0x8010A970: jal         0x8010A444
    // 0x8010A974: nop

    grHyruleTwisterUpdateSummon(rdram, ctx);
        goto after_2;
    // 0x8010A974: nop

    after_2:
    // 0x8010A978: b           L_8010A9BC
    // 0x8010A97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A9BC;
    // 0x8010A97C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A980:
    // 0x8010A980: jal         0x8010A610
    // 0x8010A984: nop

    grHyruleTwisterUpdateMove(rdram, ctx);
        goto after_3;
    // 0x8010A984: nop

    after_3:
    // 0x8010A988: b           L_8010A9BC
    // 0x8010A98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A9BC;
    // 0x8010A98C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A990:
    // 0x8010A990: jal         0x8010A7CC
    // 0x8010A994: nop

    grHyruleTwisterUpdateTurn(rdram, ctx);
        goto after_4;
    // 0x8010A994: nop

    after_4:
    // 0x8010A998: b           L_8010A9BC
    // 0x8010A99C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A9BC;
    // 0x8010A99C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A9A0:
    // 0x8010A9A0: jal         0x8010A824
    // 0x8010A9A4: nop

    grHyruleTwisterUpdateStop(rdram, ctx);
        goto after_5;
    // 0x8010A9A4: nop

    after_5:
    // 0x8010A9A8: b           L_8010A9BC
    // 0x8010A9AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010A9BC;
    // 0x8010A9AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A9B0:
    // 0x8010A9B0: jal         0x8010A8B4
    // 0x8010A9B4: nop

    grHyruleTwisterUpdateSubside(rdram, ctx);
        goto after_6;
    // 0x8010A9B4: nop

    after_6:
L_8010A9B8:
    // 0x8010A9B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010A9BC:
    // 0x8010A9BC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8010A9C0: jr          $ra
    // 0x8010A9C4: nop

    return;
    // 0x8010A9C4: nop

;}
RECOMP_FUNC void mnOptionFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013346C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80133470: lui         $t6, 0x1B
    ctx->r14 = S32(0X1B << 16);
    // 0x80133474: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80133478: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x8013347C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80133480: addiu       $t6, $t6, -0x3790
    ctx->r14 = ADD32(ctx->r14, -0X3790);
    // 0x80133484: addiu       $t7, $t7, 0x854
    ctx->r15 = ADD32(ctx->r15, 0X854);
    // 0x80133488: addiu       $t8, $t8, 0x37F0
    ctx->r24 = ADD32(ctx->r24, 0X37F0);
    // 0x8013348C: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x80133490: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x80133494: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80133498: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x8013349C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801334A0: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x801334A4: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x801334A8: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x801334AC: sw          $zero, 0x44($sp)
    MEM_W(0X44, ctx->r29) = 0;
    // 0x801334B0: jal         0x800CDF78
    // 0x801334B4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    lbRelocInitSetup(rdram, ctx);
        goto after_0;
    // 0x801334B4: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_0:
    // 0x801334B8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801334BC: addiu       $a0, $a0, 0x3620
    ctx->r4 = ADD32(ctx->r4, 0X3620);
    // 0x801334C0: jal         0x800CDEEC
    // 0x801334C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    lbRelocGetAllocSize(rdram, ctx);
        goto after_1;
    // 0x801334C4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_1:
    // 0x801334C8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801334CC: jal         0x80004980
    // 0x801334D0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x801334D0: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x801334D4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801334D8: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801334DC: addiu       $a2, $a2, 0x38B0
    ctx->r6 = ADD32(ctx->r6, 0X38B0);
    // 0x801334E0: addiu       $a0, $a0, 0x3620
    ctx->r4 = ADD32(ctx->r4, 0X3620);
    // 0x801334E4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x801334E8: jal         0x800CDE04
    // 0x801334EC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    lbRelocLoadFilesExtern(rdram, ctx);
        goto after_3;
    // 0x801334EC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x801334F0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801334F4: addiu       $a1, $a1, 0x2E4C
    ctx->r5 = ADD32(ctx->r5, 0X2E4C);
    // 0x801334F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801334FC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80133500: jal         0x80009968
    // 0x80133504: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_4;
    // 0x80133504: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_4:
    // 0x80133508: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013350C: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x80133510: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x80133514: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80133518: jal         0x8000B9FC
    // 0x8013351C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_5;
    // 0x8013351C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80133520: jal         0x80132D60
    // 0x80133524: nop

    mnOptionInitVars(rdram, ctx);
        goto after_6;
    // 0x80133524: nop

    after_6:
    // 0x80133528: jal         0x80132CC0
    // 0x8013352C: nop

    mnOptionMakeDecalsCamera(rdram, ctx);
        goto after_7;
    // 0x8013352C: nop

    after_7:
    // 0x80133530: jal         0x80132C20
    // 0x80133534: nop

    mnOptionMakeLabelsCamera(rdram, ctx);
        goto after_8;
    // 0x80133534: nop

    after_8:
    // 0x80133538: jal         0x80132B80
    // 0x8013353C: nop

    mnOptionMakeOptionsCamera(rdram, ctx);
        goto after_9;
    // 0x8013353C: nop

    after_9:
    // 0x80133540: jal         0x80132A40
    // 0x80133544: nop

    mnOptionMakeSoundUnderlineCamera(rdram, ctx);
        goto after_10;
    // 0x80133544: nop

    after_10:
    // 0x80133548: jal         0x80132AE0
    // 0x8013354C: nop

    mnOptionMakeLink4Camera(rdram, ctx);
        goto after_11;
    // 0x8013354C: nop

    after_11:
    // 0x80133550: jal         0x80132484
    // 0x80133554: nop

    mnOptionMakeDecals(rdram, ctx);
        goto after_12;
    // 0x80133554: nop

    after_12:
    // 0x80133558: jal         0x8013238C
    // 0x8013355C: nop

    mnOptionMakeLabels(rdram, ctx);
        goto after_13;
    // 0x8013355C: nop

    after_13:
    // 0x80133560: jal         0x80131EF0
    // 0x80133564: nop

    mnOptionMakeSound(rdram, ctx);
        goto after_14;
    // 0x80133564: nop

    after_14:
    // 0x80133568: jal         0x80131D98
    // 0x8013356C: nop

    mnOptionMakeSoundToggle(rdram, ctx);
        goto after_15;
    // 0x8013356C: nop

    after_15:
    // 0x80133570: jal         0x80131FC4
    // 0x80133574: nop

    mnOptionMakeScreenAdjust(rdram, ctx);
        goto after_16;
    // 0x80133574: nop

    after_16:
    // 0x80133578: jal         0x8013209C
    // 0x8013357C: nop

    mnOptionMakeBackupClear(rdram, ctx);
        goto after_17;
    // 0x8013357C: nop

    after_17:
    // 0x80133580: jal         0x801329F4
    // 0x80133584: nop

    mnOptionMakeSoundUnderline(rdram, ctx);
        goto after_18;
    // 0x80133584: nop

    after_18:
    // 0x80133588: jal         0x801321A8
    // 0x8013358C: nop

    mnOptionMakeMenuGObj(rdram, ctx);
        goto after_19;
    // 0x8013358C: nop

    after_19:
    // 0x80133590: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80133594: lbu         $t0, 0x4AD1($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X4AD1);
    // 0x80133598: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x8013359C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801335A0: bnel        $t0, $at, L_801335B4
    if (ctx->r8 != ctx->r1) {
        // 0x801335A4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801335B4;
    }
    goto skip_0;
    // 0x801335A4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x801335A8: jal         0x80020AB4
    // 0x801335AC: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    syAudioPlayBGM(rdram, ctx);
        goto after_20;
    // 0x801335AC: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    after_20:
    // 0x801335B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801335B4:
    // 0x801335B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x801335B8: jr          $ra
    // 0x801335BC: nop

    return;
    // 0x801335BC: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateCPOptionSprite(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018EEE8: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018EEEC: addiu       $v1, $v1, 0xB58
    ctx->r3 = ADD32(ctx->r3, 0XB58);
    // 0x8018EEF0: lw          $t8, 0x14($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X14);
    // 0x8018EEF4: lw          $t7, 0x30($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X30);
    // 0x8018EEF8: lw          $t6, 0x58($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X58);
    // 0x8018EEFC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8018EF00: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8018EF04: lw          $t1, 0x54($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X54);
    // 0x8018EF08: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x8018EF0C: addiu       $t5, $t1, 0x3C
    ctx->r13 = ADD32(ctx->r9, 0X3C);
    // 0x8018EF10: or          $t4, $v0, $zero
    ctx->r12 = ctx->r2 | 0;
L_8018EF14:
    // 0x8018EF14: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018EF18: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018EF1C: addiu       $t4, $t4, 0xC
    ctx->r12 = ADD32(ctx->r12, 0XC);
    // 0x8018EF20: sw          $t3, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r11;
    // 0x8018EF24: lw          $t2, -0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, -0X8);
    // 0x8018EF28: sw          $t2, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->r10;
    // 0x8018EF2C: lw          $t3, -0x4($t1)
    ctx->r11 = MEM_W(ctx->r9, -0X4);
    // 0x8018EF30: bne         $t1, $t5, L_8018EF14
    if (ctx->r9 != ctx->r13) {
        // 0x8018EF34: sw          $t3, 0xC($t4)
        MEM_W(0XC, ctx->r12) = ctx->r11;
            goto L_8018EF14;
    }
    // 0x8018EF34: sw          $t3, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->r11;
    // 0x8018EF38: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8018EF3C: addiu       $t7, $zero, 0xBF
    ctx->r15 = ADD32(0, 0XBF);
    // 0x8018EF40: sw          $t3, 0x10($t4)
    MEM_W(0X10, ctx->r12) = ctx->r11;
    // 0x8018EF44: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x8018EF48: sw          $t2, 0x14($t4)
    MEM_W(0X14, ctx->r12) = ctx->r10;
    // 0x8018EF4C: lh          $t6, 0x14($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X14);
    // 0x8018EF50: bgez        $t6, L_8018EF60
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8018EF54: sra         $t8, $t6, 1
        ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
            goto L_8018EF60;
    }
    // 0x8018EF54: sra         $t8, $t6, 1
    ctx->r24 = S32(SIGNED(ctx->r14) >> 1);
    // 0x8018EF58: addiu       $at, $t6, 0x1
    ctx->r1 = ADD32(ctx->r14, 0X1);
    // 0x8018EF5C: sra         $t8, $at, 1
    ctx->r24 = S32(SIGNED(ctx->r1) >> 1);
L_8018EF60:
    // 0x8018EF60: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x8018EF64: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8018EF68: nop

    // 0x8018EF6C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8018EF70: jr          $ra
    // 0x8018EF74: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
    return;
    // 0x8018EF74: swc1        $f6, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f6.u32l;
;}
RECOMP_FUNC void mnPlayers1PGameSelectFighterPuck(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132384: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132388: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013238C: lui         $s0, 0x8014
    ctx->r16 = S32(0X8014 << 16);
    // 0x80132390: addiu       $s0, $s0, -0x7118
    ctx->r16 = ADD32(ctx->r16, -0X7118);
    // 0x80132394: lw          $t6, 0x54($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X54);
    // 0x80132398: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013239C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x801323A0: lw          $a0, 0x20($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X20);
    // 0x801323A4: jal         0x800EC0EC
    // 0x801323A8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x801323A8: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801323AC: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x801323B0: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x801323B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x801323B8: jal         0x800E9248
    // 0x801323BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_1;
    // 0x801323BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x801323C0: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x801323C4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801323C8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801323CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x801323D0: sw          $t8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->r24;
    // 0x801323D4: sw          $t9, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r25;
    // 0x801323D8: sw          $a2, 0x28($s0)
    MEM_W(0X28, ctx->r16) = ctx->r6;
    // 0x801323DC: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x801323E0: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801323E4: jal         0x801352BC
    // 0x801323E8: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    mnPlayers1PGameUpdateCursor(rdram, ctx);
        goto after_2;
    // 0x801323E8: sw          $t7, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r15;
    after_2:
    // 0x801323EC: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x801323F0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801323F4: sw          $t1, 0x54($s0)
    MEM_W(0X54, ctx->r16) = ctx->r9;
    // 0x801323F8: sw          $t2, 0x58($s0)
    MEM_W(0X58, ctx->r16) = ctx->r10;
    // 0x801323FC: jal         0x80135CF4
    // 0x80132400: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mnPlayers1PGameUpdateCursorPlacementPriorities(rdram, ctx);
        goto after_3;
    // 0x80132400: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80132404: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80132408: jal         0x80135B30
    // 0x8013240C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    mnPlayers1PGameAnnounceFighter(rdram, ctx);
        goto after_4;
    // 0x8013240C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_4:
    // 0x80132410: jal         0x801359FC
    // 0x80132414: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mnPlayers1PGameMakePortraitFlash(rdram, ctx);
        goto after_5;
    // 0x80132414: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_5:
    // 0x80132418: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8013241C: lw          $a0, -0x7048($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7048);
    // 0x80132420: jal         0x8013419C
    // 0x80132424: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    mnPlayers1PGameMakeStock(rdram, ctx);
        goto after_6;
    // 0x80132424: lw          $a1, 0x20($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X20);
    after_6:
    // 0x80132428: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8013242C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80132430: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132434: jr          $ra
    // 0x80132438: nop

    return;
    // 0x80132438: nop

;}
RECOMP_FUNC void mnVSOptionsFuncRun(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133A40: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133A44: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133A48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133A4C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80133A50: addiu       $t7, $t7, 0x47FC
    ctx->r15 = ADD32(ctx->r15, 0X47FC);
    // 0x80133A54: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133A58: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80133A5C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x80133A60: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80133A64: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80133A68: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x80133A6C: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80133A70: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80133A74: lw          $t9, 0x10($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X10);
    // 0x80133A78: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133A7C: addiu       $v1, $v1, 0x490C
    ctx->r3 = ADD32(ctx->r3, 0X490C);
    // 0x80133A80: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x80133A84: sw          $t9, 0x10($t6)
    MEM_W(0X10, ctx->r14) = ctx->r25;
    // 0x80133A88: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x80133A8C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133A90: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x80133A94: slti        $at, $t1, 0xA
    ctx->r1 = SIGNED(ctx->r9) < 0XA ? 1 : 0;
    // 0x80133A98: bne         $at, $zero, L_801344F4
    if (ctx->r1 != 0) {
        // 0x80133A9C: sw          $t1, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r9;
            goto L_801344F4;
    }
    // 0x80133A9C: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x80133AA0: lw          $t2, 0x4910($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X4910);
    // 0x80133AA4: bne         $t2, $t1, L_80133AD4
    if (ctx->r10 != ctx->r9) {
        // 0x80133AA8: lui         $v1, 0x800A
        ctx->r3 = S32(0X800A << 16);
            goto L_80133AD4;
    }
    // 0x80133AA8: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133AAC: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80133AB0: lbu         $t3, 0x0($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X0);
    // 0x80133AB4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80133AB8: sb          $t4, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r12;
    // 0x80133ABC: jal         0x8013394C
    // 0x80133AC0: sb          $t3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r11;
    mnVSOptionsSetAllSettings(rdram, ctx);
        goto after_0;
    // 0x80133AC0: sb          $t3, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r11;
    after_0:
    // 0x80133AC4: jal         0x80005C74
    // 0x80133AC8: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_1;
    // 0x80133AC8: nop

    after_1:
    // 0x80133ACC: b           L_801344F8
    // 0x80133AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801344F8;
    // 0x80133AD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80133AD4:
    // 0x80133AD4: jal         0x80390B7C
    // 0x80133AD8: nop

    scSubsysControllerCheckNoInputAll(rdram, ctx);
        goto after_2;
    // 0x80133AD8: nop

    after_2:
    // 0x80133ADC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133AE0: bne         $v0, $zero, L_80133AF8
    if (ctx->r2 != 0) {
        // 0x80133AE4: addiu       $v1, $v1, 0x490C
        ctx->r3 = ADD32(ctx->r3, 0X490C);
            goto L_80133AF8;
    }
    // 0x80133AE4: addiu       $v1, $v1, 0x490C
    ctx->r3 = ADD32(ctx->r3, 0X490C);
    // 0x80133AE8: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80133AEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133AF0: addiu       $t6, $t5, 0x4650
    ctx->r14 = ADD32(ctx->r13, 0X4650);
    // 0x80133AF4: sw          $t6, 0x4910($at)
    MEM_W(0X4910, ctx->r1) = ctx->r14;
L_80133AF8:
    // 0x80133AF8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133AFC: addiu       $v1, $v1, 0x4908
    ctx->r3 = ADD32(ctx->r3, 0X4908);
    // 0x80133B00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133B04: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133B08: beq         $v0, $zero, L_80133B14
    if (ctx->r2 == 0) {
        // 0x80133B0C: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_80133B14;
    }
    // 0x80133B0C: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x80133B10: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
L_80133B14:
    // 0x80133B14: jal         0x80390A04
    // 0x80133B18: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeLR(rdram, ctx);
        goto after_3;
    // 0x80133B18: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_3:
    // 0x80133B1C: beq         $v0, $zero, L_80133B58
    if (ctx->r2 == 0) {
        // 0x80133B20: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80133B58;
    }
    // 0x80133B20: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133B24: jal         0x80390AC0
    // 0x80133B28: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    scSubsysControllerGetPlayerStickInRangeUD(rdram, ctx);
        goto after_4;
    // 0x80133B28: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    after_4:
    // 0x80133B2C: beq         $v0, $zero, L_80133B58
    if (ctx->r2 == 0) {
        // 0x80133B30: nop
    
            goto L_80133B58;
    }
    // 0x80133B30: nop

    // 0x80133B34: jal         0x80390804
    // 0x80133B38: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_5;
    // 0x80133B38: addiu       $a0, $zero, 0x919
    ctx->r4 = ADD32(0, 0X919);
    after_5:
    // 0x80133B3C: bne         $v0, $zero, L_80133B58
    if (ctx->r2 != 0) {
        // 0x80133B40: nop
    
            goto L_80133B58;
    }
    // 0x80133B40: nop

    // 0x80133B44: jal         0x80390804
    // 0x80133B48: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_6;
    // 0x80133B48: addiu       $a0, $zero, 0x626
    ctx->r4 = ADD32(0, 0X626);
    after_6:
    // 0x80133B4C: bne         $v0, $zero, L_80133B58
    if (ctx->r2 != 0) {
        // 0x80133B50: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80133B58;
    }
    // 0x80133B50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133B54: sw          $zero, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = 0;
L_80133B58:
    // 0x80133B58: jal         0x8039076C
    // 0x80133B5C: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_7;
    // 0x80133B5C: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_7:
    // 0x80133B60: beq         $v0, $zero, L_80133BA4
    if (ctx->r2 == 0) {
        // 0x80133B64: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_80133BA4;
    }
    // 0x80133B64: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133B68: lw          $t8, 0x48E0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X48E0);
    // 0x80133B6C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80133B70: bne         $t8, $at, L_80133BA4
    if (ctx->r24 != ctx->r1) {
        // 0x80133B74: nop
    
            goto L_80133BA4;
    }
    // 0x80133B74: nop

    // 0x80133B78: jal         0x800269C0
    // 0x80133B7C: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_8;
    // 0x80133B7C: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_8:
    // 0x80133B80: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133B84: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80133B88: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x80133B8C: addiu       $t0, $zero, 0xB
    ctx->r8 = ADD32(0, 0XB);
    // 0x80133B90: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
    // 0x80133B94: jal         0x8013394C
    // 0x80133B98: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    mnVSOptionsSetAllSettings(rdram, ctx);
        goto after_9;
    // 0x80133B98: sb          $t9, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r25;
    after_9:
    // 0x80133B9C: jal         0x80005C74
    // 0x80133BA0: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_10;
    // 0x80133BA0: nop

    after_10:
L_80133BA4:
    // 0x80133BA4: jal         0x8039076C
    // 0x80133BA8: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_11;
    // 0x80133BA8: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_11:
    // 0x80133BAC: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133BB0: beq         $v0, $zero, L_80133BD4
    if (ctx->r2 == 0) {
        // 0x80133BB4: addiu       $v1, $v1, 0x4AD0
        ctx->r3 = ADD32(ctx->r3, 0X4AD0);
            goto L_80133BD4;
    }
    // 0x80133BB4: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80133BB8: lbu         $t1, 0x0($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X0);
    // 0x80133BBC: addiu       $t2, $zero, 0x9
    ctx->r10 = ADD32(0, 0X9);
    // 0x80133BC0: sb          $t2, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r10;
    // 0x80133BC4: jal         0x8013394C
    // 0x80133BC8: sb          $t1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r9;
    mnVSOptionsSetAllSettings(rdram, ctx);
        goto after_12;
    // 0x80133BC8: sb          $t1, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r9;
    after_12:
    // 0x80133BCC: jal         0x80005C74
    // 0x80133BD0: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_13;
    // 0x80133BD0: nop

    after_13:
L_80133BD4:
    // 0x80133BD4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133BD8: lw          $v0, 0x4908($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4908);
    // 0x80133BDC: bne         $v0, $zero, L_80133BFC
    if (ctx->r2 != 0) {
        // 0x80133BE0: nop
    
            goto L_80133BFC;
    }
    // 0x80133BE0: nop

    // 0x80133BE4: jal         0x80390804
    // 0x80133BE8: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_14;
    // 0x80133BE8: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    after_14:
    // 0x80133BEC: bne         $v0, $zero, L_80133C14
    if (ctx->r2 != 0) {
        // 0x80133BF0: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80133C14;
    }
    // 0x80133BF0: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80133BF4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133BF8: lw          $v0, 0x4908($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4908);
L_80133BFC:
    // 0x80133BFC: bne         $v0, $zero, L_80133D00
    if (ctx->r2 != 0) {
        // 0x80133C00: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_80133D00;
    }
    // 0x80133C00: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80133C04: jal         0x80390950
    // 0x80133C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_15;
    // 0x80133C08: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_15:
    // 0x80133C0C: beq         $v0, $zero, L_80133D00
    if (ctx->r2 == 0) {
        // 0x80133C10: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80133D00;
    }
    // 0x80133C10: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80133C14:
    // 0x80133C14: jal         0x800269C0
    // 0x80133C18: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_16;
    // 0x80133C18: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_16:
    // 0x80133C1C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80133C20: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80133C24: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x80133C28: beq         $t3, $zero, L_80133C40
    if (ctx->r11 == 0) {
        // 0x80133C2C: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_80133C40;
    }
    // 0x80133C2C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133C30: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x80133C34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C38: b           L_80133C58
    // 0x80133C3C: sw          $t4, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r12;
        goto L_80133C58;
    // 0x80133C3C: sw          $t4, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r12;
L_80133C40:
    // 0x80133C40: subu        $t7, $t6, $t5
    ctx->r15 = SUB32(ctx->r14, ctx->r13);
    // 0x80133C44: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133C48: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80133C4C: mflo        $t8
    ctx->r24 = lo;
    // 0x80133C50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C54: sw          $t8, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r24;
L_80133C58:
    // 0x80133C58: lw          $t9, 0x48E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X48E0);
    // 0x80133C5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133C60: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x80133C64: addu        $t1, $sp, $t0
    ctx->r9 = ADD32(ctx->r29, ctx->r8);
    // 0x80133C68: lw          $t1, 0x28($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X28);
    // 0x80133C6C: jal         0x80131F74
    // 0x80133C70: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    mnVSOptionsSetOptionSpriteColors(rdram, ctx);
        goto after_17;
    // 0x80133C70: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    after_17:
    // 0x80133C74: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133C78: addiu       $v1, $v1, 0x48E0
    ctx->r3 = ADD32(ctx->r3, 0X48E0);
    // 0x80133C7C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80133C80: lw          $t2, 0x48FC($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X48FC);
    // 0x80133C84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133C88: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80133C8C: bne         $t2, $v0, L_80133CA0
    if (ctx->r10 != ctx->r2) {
        // 0x80133C90: addiu       $t4, $v0, -0x1
        ctx->r12 = ADD32(ctx->r2, -0X1);
            goto L_80133CA0;
    }
    // 0x80133C90: addiu       $t4, $v0, -0x1
    ctx->r12 = ADD32(ctx->r2, -0X1);
    // 0x80133C94: lw          $t3, 0x4900($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X4900);
    // 0x80133C98: b           L_80133CA4
    // 0x80133C9C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
        goto L_80133CA4;
    // 0x80133C9C: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
L_80133CA0:
    // 0x80133CA0: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
L_80133CA4:
    // 0x80133CA4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80133CA8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80133CAC: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x80133CB0: addu        $t7, $sp, $t5
    ctx->r15 = ADD32(ctx->r29, ctx->r13);
    // 0x80133CB4: lw          $t7, 0x28($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X28);
    // 0x80133CB8: jal         0x80131F74
    // 0x80133CBC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    mnVSOptionsSetOptionSpriteColors(rdram, ctx);
        goto after_18;
    // 0x80133CBC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    after_18:
    // 0x80133CC0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133CC4: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133CC8: lw          $t9, 0x48E0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X48E0);
    // 0x80133CCC: lw          $t8, 0x48FC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X48FC);
    // 0x80133CD0: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133CD4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133CD8: bne         $t8, $t9, L_80133CF0
    if (ctx->r24 != ctx->r25) {
        // 0x80133CDC: nop
    
            goto L_80133CF0;
    }
    // 0x80133CDC: nop

    // 0x80133CE0: lw          $t0, 0x4908($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4908);
    // 0x80133CE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CE8: addiu       $t1, $t0, 0x8
    ctx->r9 = ADD32(ctx->r8, 0X8);
    // 0x80133CEC: sw          $t1, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r9;
L_80133CF0:
    // 0x80133CF0: jal         0x80009A84
    // 0x80133CF4: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_19;
    // 0x80133CF4: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_19:
    // 0x80133CF8: jal         0x80132E58
    // 0x80133CFC: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_20;
    // 0x80133CFC: nop

    after_20:
L_80133D00:
    // 0x80133D00: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133D04: lw          $v0, 0x4908($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4908);
    // 0x80133D08: bne         $v0, $zero, L_80133D28
    if (ctx->r2 != 0) {
        // 0x80133D0C: nop
    
            goto L_80133D28;
    }
    // 0x80133D0C: nop

    // 0x80133D10: jal         0x80390804
    // 0x80133D14: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_21;
    // 0x80133D14: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    after_21:
    // 0x80133D18: bne         $v0, $zero, L_80133D40
    if (ctx->r2 != 0) {
        // 0x80133D1C: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80133D40;
    }
    // 0x80133D1C: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80133D20: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133D24: lw          $v0, 0x4908($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4908);
L_80133D28:
    // 0x80133D28: bne         $v0, $zero, L_80133E28
    if (ctx->r2 != 0) {
        // 0x80133D2C: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_80133E28;
    }
    // 0x80133D2C: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133D30: jal         0x80390950
    // 0x80133D34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickUD(rdram, ctx);
        goto after_22;
    // 0x80133D34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x80133D38: beq         $v0, $zero, L_80133E28
    if (ctx->r2 == 0) {
        // 0x80133D3C: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_80133E28;
    }
    // 0x80133D3C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80133D40:
    // 0x80133D40: jal         0x800269C0
    // 0x80133D44: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_23;
    // 0x80133D44: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_23:
    // 0x80133D48: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80133D4C: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80133D50: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133D54: beq         $t2, $zero, L_80133D6C
    if (ctx->r10 == 0) {
        // 0x80133D58: addiu       $t6, $t4, 0xA0
        ctx->r14 = ADD32(ctx->r12, 0XA0);
            goto L_80133D6C;
    }
    // 0x80133D58: addiu       $t6, $t4, 0xA0
    ctx->r14 = ADD32(ctx->r12, 0XA0);
    // 0x80133D5C: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80133D60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D64: b           L_80133D80
    // 0x80133D68: sw          $t3, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r11;
        goto L_80133D80;
    // 0x80133D68: sw          $t3, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r11;
L_80133D6C:
    // 0x80133D6C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133D70: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x80133D74: mflo        $t5
    ctx->r13 = lo;
    // 0x80133D78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D7C: sw          $t5, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r13;
L_80133D80:
    // 0x80133D80: lw          $t7, 0x48E0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X48E0);
    // 0x80133D84: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133D88: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80133D8C: addu        $t9, $sp, $t8
    ctx->r25 = ADD32(ctx->r29, ctx->r24);
    // 0x80133D90: lw          $t9, 0x28($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X28);
    // 0x80133D94: jal         0x80131F74
    // 0x80133D98: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    mnVSOptionsSetOptionSpriteColors(rdram, ctx);
        goto after_24;
    // 0x80133D98: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    after_24:
    // 0x80133D9C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80133DA0: addiu       $v1, $v1, 0x48E0
    ctx->r3 = ADD32(ctx->r3, 0X48E0);
    // 0x80133DA4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80133DA8: lw          $t0, 0x4900($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4900);
    // 0x80133DAC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80133DB0: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80133DB4: bne         $t0, $v0, L_80133DC8
    if (ctx->r8 != ctx->r2) {
        // 0x80133DB8: addiu       $t2, $v0, 0x1
        ctx->r10 = ADD32(ctx->r2, 0X1);
            goto L_80133DC8;
    }
    // 0x80133DB8: addiu       $t2, $v0, 0x1
    ctx->r10 = ADD32(ctx->r2, 0X1);
    // 0x80133DBC: lw          $t1, 0x48FC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X48FC);
    // 0x80133DC0: b           L_80133DCC
    // 0x80133DC4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
        goto L_80133DCC;
    // 0x80133DC4: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
L_80133DC8:
    // 0x80133DC8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_80133DCC:
    // 0x80133DCC: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x80133DD0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80133DD4: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80133DD8: addu        $t6, $sp, $t4
    ctx->r14 = ADD32(ctx->r29, ctx->r12);
    // 0x80133DDC: lw          $t6, 0x28($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X28);
    // 0x80133DE0: jal         0x80131F74
    // 0x80133DE4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    mnVSOptionsSetOptionSpriteColors(rdram, ctx);
        goto after_25;
    // 0x80133DE4: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    after_25:
    // 0x80133DE8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80133DEC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133DF0: lw          $t7, 0x48E0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X48E0);
    // 0x80133DF4: lw          $t5, 0x4900($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X4900);
    // 0x80133DF8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80133DFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133E00: bne         $t5, $t7, L_80133E18
    if (ctx->r13 != ctx->r15) {
        // 0x80133E04: nop
    
            goto L_80133E18;
    }
    // 0x80133E04: nop

    // 0x80133E08: lw          $t8, 0x4908($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X4908);
    // 0x80133E0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133E10: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80133E14: sw          $t9, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r25;
L_80133E18:
    // 0x80133E18: jal         0x80009A84
    // 0x80133E1C: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_26;
    // 0x80133E1C: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_26:
    // 0x80133E20: jal         0x80132E58
    // 0x80133E24: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_27;
    // 0x80133E24: nop

    after_27:
L_80133E28:
    // 0x80133E28: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133E2C: lw          $v0, 0x4908($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4908);
    // 0x80133E30: bne         $v0, $zero, L_80133E50
    if (ctx->r2 != 0) {
        // 0x80133E34: nop
    
            goto L_80133E50;
    }
    // 0x80133E34: nop

    // 0x80133E38: jal         0x80390804
    // 0x80133E3C: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_28;
    // 0x80133E3C: addiu       $a0, $zero, 0x222
    ctx->r4 = ADD32(0, 0X222);
    after_28:
    // 0x80133E40: bne         $v0, $zero, L_80133E68
    if (ctx->r2 != 0) {
        // 0x80133E44: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_80133E68;
    }
    // 0x80133E44: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80133E48: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133E4C: lw          $v0, 0x4908($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4908);
L_80133E50:
    // 0x80133E50: bne         $v0, $zero, L_801340DC
    if (ctx->r2 != 0) {
        // 0x80133E54: addiu       $a0, $zero, -0x14
        ctx->r4 = ADD32(0, -0X14);
            goto L_801340DC;
    }
    // 0x80133E54: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80133E58: jal         0x8039089C
    // 0x80133E5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_29;
    // 0x80133E5C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x80133E60: beq         $v0, $zero, L_801340DC
    if (ctx->r2 == 0) {
        // 0x80133E64: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_801340DC;
    }
    // 0x80133E64: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_80133E68:
    // 0x80133E68: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133E6C: lw          $v0, 0x48E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X48E0);
    // 0x80133E70: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133E74: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133E78: beq         $v0, $zero, L_80133EA8
    if (ctx->r2 == 0) {
        // 0x80133E7C: nop
    
            goto L_80133EA8;
    }
    // 0x80133E7C: nop

    // 0x80133E80: beq         $v0, $at, L_80133F48
    if (ctx->r2 == ctx->r1) {
        // 0x80133E84: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_80133F48;
    }
    // 0x80133E84: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133E88: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80133E8C: beq         $v0, $at, L_80133FC4
    if (ctx->r2 == ctx->r1) {
        // 0x80133E90: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_80133FC4;
    }
    // 0x80133E90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133E94: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80133E98: beq         $v0, $at, L_80134040
    if (ctx->r2 == ctx->r1) {
        // 0x80133E9C: nop
    
            goto L_80134040;
    }
    // 0x80133E9C: nop

    // 0x80133EA0: b           L_801340DC
    // 0x80133EA4: nop

        goto L_801340DC;
    // 0x80133EA4: nop

L_80133EA8:
    // 0x80133EA8: lw          $a1, 0x48E4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E4);
    // 0x80133EAC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80133EB0: beq         $a1, $at, L_80133F04
    if (ctx->r5 == ctx->r1) {
        // 0x80133EB4: nop
    
            goto L_80133F04;
    }
    // 0x80133EB4: nop

    // 0x80133EB8: bne         $a1, $zero, L_80133ED0
    if (ctx->r5 != 0) {
        // 0x80133EBC: addiu       $t1, $zero, 0x1
        ctx->r9 = ADD32(0, 0X1);
            goto L_80133ED0;
    }
    // 0x80133EBC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133EC0: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80133EC4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133EC8: b           L_80133ED8
    // 0x80133ECC: sw          $t0, 0x48E4($at)
    MEM_W(0X48E4, ctx->r1) = ctx->r8;
        goto L_80133ED8;
    // 0x80133ECC: sw          $t0, 0x48E4($at)
    MEM_W(0X48E4, ctx->r1) = ctx->r8;
L_80133ED0:
    // 0x80133ED0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133ED4: sw          $t1, 0x48E4($at)
    MEM_W(0X48E4, ctx->r1) = ctx->r9;
L_80133ED8:
    // 0x80133ED8: jal         0x800269C0
    // 0x80133EDC: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_30;
    // 0x80133EDC: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_30:
    // 0x80133EE0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133EE4: jal         0x80009A84
    // 0x80133EE8: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_31;
    // 0x80133EE8: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_31:
    // 0x80133EEC: jal         0x80132E58
    // 0x80133EF0: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_32;
    // 0x80133EF0: nop

    after_32:
    // 0x80133EF4: jal         0x801339C4
    // 0x80133EF8: nop

    mnVSOptionsSetHandicapSettings(rdram, ctx);
        goto after_33;
    // 0x80133EF8: nop

    after_33:
    // 0x80133EFC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133F00: lw          $a1, 0x48E4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E4);
L_80133F04:
    // 0x80133F04: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133F08: jal         0x80132184
    // 0x80133F0C: lw          $a0, 0x48C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C0);
    mnVSOptionsSetHandicapSpriteColors(rdram, ctx);
        goto after_34;
    // 0x80133F0C: lw          $a0, 0x48C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C0);
    after_34:
    // 0x80133F10: lw          $t2, 0x20($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X20);
    // 0x80133F14: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x80133F18: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133F1C: beq         $t2, $zero, L_80133F34
    if (ctx->r10 == 0) {
        // 0x80133F20: addiu       $t6, $t4, 0xA0
        ctx->r14 = ADD32(ctx->r12, 0XA0);
            goto L_80133F34;
    }
    // 0x80133F20: addiu       $t6, $t4, 0xA0
    ctx->r14 = ADD32(ctx->r12, 0XA0);
    // 0x80133F24: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80133F28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133F2C: b           L_801340DC
    // 0x80133F30: sw          $t3, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r11;
        goto L_801340DC;
    // 0x80133F30: sw          $t3, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r11;
L_80133F34:
    // 0x80133F34: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x80133F38: mflo        $t5
    ctx->r13 = lo;
    // 0x80133F3C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133F40: b           L_801340DC
    // 0x80133F44: sw          $t5, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r13;
        goto L_801340DC;
    // 0x80133F44: sw          $t5, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r13;
L_80133F48:
    // 0x80133F48: lw          $a1, 0x48E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E8);
    // 0x80133F4C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80133F50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133F54: bne         $a1, $zero, L_80133F80
    if (ctx->r5 != 0) {
        // 0x80133F58: addiu       $a0, $zero, 0xA3
        ctx->r4 = ADD32(0, 0XA3);
            goto L_80133F80;
    }
    // 0x80133F58: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    // 0x80133F5C: jal         0x800269C0
    // 0x80133F60: sw          $t7, 0x48E8($at)
    MEM_W(0X48E8, ctx->r1) = ctx->r15;
    func_800269C0_275C0(rdram, ctx);
        goto after_35;
    // 0x80133F60: sw          $t7, 0x48E8($at)
    MEM_W(0X48E8, ctx->r1) = ctx->r15;
    after_35:
    // 0x80133F64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133F68: jal         0x80009A84
    // 0x80133F6C: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_36;
    // 0x80133F6C: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_36:
    // 0x80133F70: jal         0x80132E58
    // 0x80133F74: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_37;
    // 0x80133F74: nop

    after_37:
    // 0x80133F78: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133F7C: lw          $a1, 0x48E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E8);
L_80133F80:
    // 0x80133F80: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133F84: jal         0x80131FFC
    // 0x80133F88: lw          $a0, 0x48C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C4);
    mnVSOptionsSetToggleSpriteColors(rdram, ctx);
        goto after_38;
    // 0x80133F88: lw          $a0, 0x48C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C4);
    after_38:
    // 0x80133F8C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80133F90: lw          $t0, 0x24($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X24);
    // 0x80133F94: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80133F98: beq         $t8, $zero, L_80133FB0
    if (ctx->r24 == 0) {
        // 0x80133F9C: addiu       $t1, $t0, 0xA0
        ctx->r9 = ADD32(ctx->r8, 0XA0);
            goto L_80133FB0;
    }
    // 0x80133F9C: addiu       $t1, $t0, 0xA0
    ctx->r9 = ADD32(ctx->r8, 0XA0);
    // 0x80133FA0: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80133FA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133FA8: b           L_801340DC
    // 0x80133FAC: sw          $t9, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r25;
        goto L_801340DC;
    // 0x80133FAC: sw          $t9, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r25;
L_80133FB0:
    // 0x80133FB0: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x80133FB4: mflo        $t2
    ctx->r10 = lo;
    // 0x80133FB8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133FBC: b           L_801340DC
    // 0x80133FC0: sw          $t2, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r10;
        goto L_801340DC;
    // 0x80133FC0: sw          $t2, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r10;
L_80133FC4:
    // 0x80133FC4: lw          $a1, 0x48EC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48EC);
    // 0x80133FC8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133FCC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133FD0: bne         $a1, $zero, L_80133FFC
    if (ctx->r5 != 0) {
        // 0x80133FD4: addiu       $a0, $zero, 0xA3
        ctx->r4 = ADD32(0, 0XA3);
            goto L_80133FFC;
    }
    // 0x80133FD4: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    // 0x80133FD8: jal         0x800269C0
    // 0x80133FDC: sw          $t3, 0x48EC($at)
    MEM_W(0X48EC, ctx->r1) = ctx->r11;
    func_800269C0_275C0(rdram, ctx);
        goto after_39;
    // 0x80133FDC: sw          $t3, 0x48EC($at)
    MEM_W(0X48EC, ctx->r1) = ctx->r11;
    after_39:
    // 0x80133FE0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133FE4: jal         0x80009A84
    // 0x80133FE8: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_40;
    // 0x80133FE8: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_40:
    // 0x80133FEC: jal         0x80132E58
    // 0x80133FF0: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_41;
    // 0x80133FF0: nop

    after_41:
    // 0x80133FF4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80133FF8: lw          $a1, 0x48EC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48EC);
L_80133FFC:
    // 0x80133FFC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134000: jal         0x80131FFC
    // 0x80134004: lw          $a0, 0x48C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C8);
    mnVSOptionsSetToggleSpriteColors(rdram, ctx);
        goto after_42;
    // 0x80134004: lw          $a0, 0x48C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C8);
    after_42:
    // 0x80134008: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8013400C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80134010: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80134014: beq         $t4, $zero, L_8013402C
    if (ctx->r12 == 0) {
        // 0x80134018: addiu       $t7, $t5, 0xA0
        ctx->r15 = ADD32(ctx->r13, 0XA0);
            goto L_8013402C;
    }
    // 0x80134018: addiu       $t7, $t5, 0xA0
    ctx->r15 = ADD32(ctx->r13, 0XA0);
    // 0x8013401C: addiu       $t6, $zero, 0xC
    ctx->r14 = ADD32(0, 0XC);
    // 0x80134020: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134024: b           L_801340DC
    // 0x80134028: sw          $t6, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r14;
        goto L_801340DC;
    // 0x80134028: sw          $t6, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r14;
L_8013402C:
    // 0x8013402C: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x80134030: mflo        $t8
    ctx->r24 = lo;
    // 0x80134034: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134038: b           L_801340DC
    // 0x8013403C: sw          $t8, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r24;
        goto L_801340DC;
    // 0x8013403C: sw          $t8, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r24;
L_80134040:
    // 0x80134040: jal         0x800269C0
    // 0x80134044: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_43;
    // 0x80134044: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_43:
    // 0x80134048: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8013404C: addiu       $a2, $a2, 0x48F0
    ctx->r6 = ADD32(ctx->r6, 0X48F0);
    // 0x80134050: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80134054: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x80134058: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013405C: bne         $v1, $at, L_80134070
    if (ctx->r3 != ctx->r1) {
        // 0x80134060: addiu       $t0, $v1, -0x1
        ctx->r8 = ADD32(ctx->r3, -0X1);
            goto L_80134070;
    }
    // 0x80134060: addiu       $t0, $v1, -0x1
    ctx->r8 = ADD32(ctx->r3, -0X1);
    // 0x80134064: addiu       $t9, $zero, 0xC8
    ctx->r25 = ADD32(0, 0XC8);
    // 0x80134068: b           L_80134074
    // 0x8013406C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
        goto L_80134074;
    // 0x8013406C: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80134070:
    // 0x80134070: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
L_80134074:
    // 0x80134074: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x80134078: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x8013407C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80134080: beq         $t1, $zero, L_80134098
    if (ctx->r9 == 0) {
        // 0x80134084: addiu       $t4, $t3, 0xA0
        ctx->r12 = ADD32(ctx->r11, 0XA0);
            goto L_80134098;
    }
    // 0x80134084: addiu       $t4, $t3, 0xA0
    ctx->r12 = ADD32(ctx->r11, 0XA0);
    // 0x80134088: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8013408C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134090: b           L_801340A8
    // 0x80134094: sw          $t2, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r10;
        goto L_801340A8;
    // 0x80134094: sw          $t2, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r10;
L_80134098:
    // 0x80134098: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x8013409C: mflo        $t6
    ctx->r14 = lo;
    // 0x801340A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801340A4: sw          $t6, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r14;
L_801340A8:
    // 0x801340A8: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x801340AC: addiu       $at, $zero, 0x32
    ctx->r1 = ADD32(0, 0X32);
    // 0x801340B0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801340B4: bne         $t5, $at, L_801340CC
    if (ctx->r13 != ctx->r1) {
        // 0x801340B8: nop
    
            goto L_801340CC;
    }
    // 0x801340B8: nop

    // 0x801340BC: lw          $t7, 0x4908($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X4908);
    // 0x801340C0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801340C4: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x801340C8: sw          $t8, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r24;
L_801340CC:
    // 0x801340CC: jal         0x80009A84
    // 0x801340D0: lw          $a0, 0x48F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F8);
    gcEjectGObj(rdram, ctx);
        goto after_44;
    // 0x801340D0: lw          $a0, 0x48F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F8);
    after_44:
    // 0x801340D4: jal         0x80132478
    // 0x801340D8: nop

    mnVSOptionsMakeDamageDigits(rdram, ctx);
        goto after_45;
    // 0x801340D8: nop

    after_45:
L_801340DC:
    // 0x801340DC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801340E0: lw          $v0, 0x4908($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4908);
    // 0x801340E4: bne         $v0, $zero, L_8013410C
    if (ctx->r2 != 0) {
        // 0x801340E8: nop
    
            goto L_8013410C;
    }
    // 0x801340E8: nop

    // 0x801340EC: jal         0x80390804
    // 0x801340F0: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    scSubsysControllerGetPlayerHoldButtons(rdram, ctx);
        goto after_46;
    // 0x801340F0: addiu       $a0, $zero, 0x111
    ctx->r4 = ADD32(0, 0X111);
    after_46:
    // 0x801340F4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x801340F8: addiu       $a2, $a2, 0x48F0
    ctx->r6 = ADD32(ctx->r6, 0X48F0);
    // 0x801340FC: bne         $v0, $zero, L_8013412C
    if (ctx->r2 != 0) {
        // 0x80134100: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_8013412C;
    }
    // 0x80134100: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x80134104: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134108: lw          $v0, 0x4908($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X4908);
L_8013410C:
    // 0x8013410C: bne         $v0, $zero, L_801343A4
    if (ctx->r2 != 0) {
        // 0x80134110: addiu       $a0, $zero, 0x14
        ctx->r4 = ADD32(0, 0X14);
            goto L_801343A4;
    }
    // 0x80134110: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80134114: jal         0x8039089C
    // 0x80134118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_47;
    // 0x80134118: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_47:
    // 0x8013411C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x80134120: addiu       $a2, $a2, 0x48F0
    ctx->r6 = ADD32(ctx->r6, 0X48F0);
    // 0x80134124: beq         $v0, $zero, L_801343A4
    if (ctx->r2 == 0) {
        // 0x80134128: sw          $v0, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r2;
            goto L_801343A4;
    }
    // 0x80134128: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
L_8013412C:
    // 0x8013412C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134130: lw          $v0, 0x48E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X48E0);
    // 0x80134134: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134138: beq         $v0, $zero, L_80134168
    if (ctx->r2 == 0) {
        // 0x8013413C: nop
    
            goto L_80134168;
    }
    // 0x8013413C: nop

    // 0x80134140: beq         $v0, $at, L_80134208
    if (ctx->r2 == ctx->r1) {
        // 0x80134144: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_80134208;
    }
    // 0x80134144: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134148: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013414C: beq         $v0, $at, L_80134288
    if (ctx->r2 == ctx->r1) {
        // 0x80134150: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_80134288;
    }
    // 0x80134150: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80134154: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80134158: beql        $v0, $at, L_8013430C
    if (ctx->r2 == ctx->r1) {
        // 0x8013415C: lw          $v1, 0x0($a2)
        ctx->r3 = MEM_W(ctx->r6, 0X0);
            goto L_8013430C;
    }
    goto skip_0;
    // 0x8013415C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    skip_0:
    // 0x80134160: b           L_801343A4
    // 0x80134164: nop

        goto L_801343A4;
    // 0x80134164: nop

L_80134168:
    // 0x80134168: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013416C: addiu       $v0, $v0, 0x48E4
    ctx->r2 = ADD32(ctx->r2, 0X48E4);
    // 0x80134170: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80134174: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134178: beq         $a1, $zero, L_801341C0
    if (ctx->r5 == 0) {
        // 0x8013417C: nop
    
            goto L_801341C0;
    }
    // 0x8013417C: nop

    // 0x80134180: bne         $a1, $at, L_80134190
    if (ctx->r5 != ctx->r1) {
        // 0x80134184: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_80134190;
    }
    // 0x80134184: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80134188: b           L_80134194
    // 0x8013418C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
        goto L_80134194;
    // 0x8013418C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80134190:
    // 0x80134190: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80134194:
    // 0x80134194: jal         0x800269C0
    // 0x80134198: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_48;
    // 0x80134198: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_48:
    // 0x8013419C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801341A0: jal         0x80009A84
    // 0x801341A4: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_49;
    // 0x801341A4: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_49:
    // 0x801341A8: jal         0x80132E58
    // 0x801341AC: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_50;
    // 0x801341AC: nop

    after_50:
    // 0x801341B0: jal         0x801339C4
    // 0x801341B4: nop

    mnVSOptionsSetHandicapSettings(rdram, ctx);
        goto after_51;
    // 0x801341B4: nop

    after_51:
    // 0x801341B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801341BC: lw          $a1, 0x48E4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E4);
L_801341C0:
    // 0x801341C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801341C4: jal         0x80132184
    // 0x801341C8: lw          $a0, 0x48C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C0);
    mnVSOptionsSetHandicapSpriteColors(rdram, ctx);
        goto after_52;
    // 0x801341C8: lw          $a0, 0x48C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C0);
    after_52:
    // 0x801341CC: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x801341D0: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x801341D4: addiu       $t3, $zero, 0xA0
    ctx->r11 = ADD32(0, 0XA0);
    // 0x801341D8: beq         $t0, $zero, L_801341F0
    if (ctx->r8 == 0) {
        // 0x801341DC: subu        $t4, $t3, $t2
        ctx->r12 = SUB32(ctx->r11, ctx->r10);
            goto L_801341F0;
    }
    // 0x801341DC: subu        $t4, $t3, $t2
    ctx->r12 = SUB32(ctx->r11, ctx->r10);
    // 0x801341E0: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x801341E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801341E8: b           L_801343A4
    // 0x801341EC: sw          $t1, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r9;
        goto L_801343A4;
    // 0x801341EC: sw          $t1, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r9;
L_801341F0:
    // 0x801341F0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801341F4: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x801341F8: mflo        $t6
    ctx->r14 = lo;
    // 0x801341FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134200: b           L_801343A4
    // 0x80134204: sw          $t6, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r14;
        goto L_801343A4;
    // 0x80134204: sw          $t6, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r14;
L_80134208:
    // 0x80134208: lw          $a1, 0x48E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E8);
    // 0x8013420C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134210: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    // 0x80134214: bne         $a1, $at, L_80134240
    if (ctx->r5 != ctx->r1) {
        // 0x80134218: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80134240;
    }
    // 0x80134218: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013421C: jal         0x800269C0
    // 0x80134220: sw          $zero, 0x48E8($at)
    MEM_W(0X48E8, ctx->r1) = 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_53;
    // 0x80134220: sw          $zero, 0x48E8($at)
    MEM_W(0X48E8, ctx->r1) = 0;
    after_53:
    // 0x80134224: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134228: jal         0x80009A84
    // 0x8013422C: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_54;
    // 0x8013422C: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_54:
    // 0x80134230: jal         0x80132E58
    // 0x80134234: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_55;
    // 0x80134234: nop

    after_55:
    // 0x80134238: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013423C: lw          $a1, 0x48E8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48E8);
L_80134240:
    // 0x80134240: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134244: jal         0x80131FFC
    // 0x80134248: lw          $a0, 0x48C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C4);
    mnVSOptionsSetToggleSpriteColors(rdram, ctx);
        goto after_56;
    // 0x80134248: lw          $a0, 0x48C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C4);
    after_56:
    // 0x8013424C: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x80134250: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80134254: addiu       $t9, $zero, 0xA0
    ctx->r25 = ADD32(0, 0XA0);
    // 0x80134258: beq         $t5, $zero, L_80134270
    if (ctx->r13 == 0) {
        // 0x8013425C: subu        $t0, $t9, $t8
        ctx->r8 = SUB32(ctx->r25, ctx->r24);
            goto L_80134270;
    }
    // 0x8013425C: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x80134260: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80134264: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134268: b           L_801343A4
    // 0x8013426C: sw          $t7, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r15;
        goto L_801343A4;
    // 0x8013426C: sw          $t7, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r15;
L_80134270:
    // 0x80134270: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80134274: div         $zero, $t0, $at
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r1)));
    // 0x80134278: mflo        $t1
    ctx->r9 = lo;
    // 0x8013427C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134280: b           L_801343A4
    // 0x80134284: sw          $t1, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r9;
        goto L_801343A4;
    // 0x80134284: sw          $t1, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r9;
L_80134288:
    // 0x80134288: lw          $a1, 0x48EC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48EC);
    // 0x8013428C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134290: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    // 0x80134294: bne         $a1, $at, L_801342C0
    if (ctx->r5 != ctx->r1) {
        // 0x80134298: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_801342C0;
    }
    // 0x80134298: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013429C: jal         0x800269C0
    // 0x801342A0: sw          $zero, 0x48EC($at)
    MEM_W(0X48EC, ctx->r1) = 0;
    func_800269C0_275C0(rdram, ctx);
        goto after_57;
    // 0x801342A0: sw          $zero, 0x48EC($at)
    MEM_W(0X48EC, ctx->r1) = 0;
    after_57:
    // 0x801342A4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801342A8: jal         0x80009A84
    // 0x801342AC: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_58;
    // 0x801342AC: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_58:
    // 0x801342B0: jal         0x80132E58
    // 0x801342B4: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_59;
    // 0x801342B4: nop

    after_59:
    // 0x801342B8: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801342BC: lw          $a1, 0x48EC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X48EC);
L_801342C0:
    // 0x801342C0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801342C4: jal         0x80131FFC
    // 0x801342C8: lw          $a0, 0x48C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C8);
    mnVSOptionsSetToggleSpriteColors(rdram, ctx);
        goto after_60;
    // 0x801342C8: lw          $a0, 0x48C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C8);
    after_60:
    // 0x801342CC: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x801342D0: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x801342D4: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x801342D8: beq         $t3, $zero, L_801342F0
    if (ctx->r11 == 0) {
        // 0x801342DC: subu        $t5, $t6, $t4
        ctx->r13 = SUB32(ctx->r14, ctx->r12);
            goto L_801342F0;
    }
    // 0x801342DC: subu        $t5, $t6, $t4
    ctx->r13 = SUB32(ctx->r14, ctx->r12);
    // 0x801342E0: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x801342E4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342E8: b           L_801343A4
    // 0x801342EC: sw          $t2, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r10;
        goto L_801343A4;
    // 0x801342EC: sw          $t2, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r10;
L_801342F0:
    // 0x801342F0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801342F4: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x801342F8: mflo        $t7
    ctx->r15 = lo;
    // 0x801342FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134300: b           L_801343A4
    // 0x80134304: sw          $t7, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r15;
        goto L_801343A4;
    // 0x80134304: sw          $t7, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r15;
    // 0x80134308: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
L_8013430C:
    // 0x8013430C: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80134310: addiu       $t9, $zero, 0x32
    ctx->r25 = ADD32(0, 0X32);
    // 0x80134314: bne         $v1, $at, L_80134324
    if (ctx->r3 != ctx->r1) {
        // 0x80134318: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_80134324;
    }
    // 0x80134318: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x8013431C: b           L_80134328
    // 0x80134320: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
        goto L_80134328;
    // 0x80134320: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
L_80134324:
    // 0x80134324: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_80134328:
    // 0x80134328: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8013432C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134330: addiu       $v0, $v0, 0x4908
    ctx->r2 = ADD32(ctx->r2, 0X4908);
    // 0x80134334: beq         $t0, $zero, L_80134344
    if (ctx->r8 == 0) {
        // 0x80134338: addiu       $t1, $zero, 0xC
        ctx->r9 = ADD32(0, 0XC);
            goto L_80134344;
    }
    // 0x80134338: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8013433C: b           L_8013436C
    // 0x80134340: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
        goto L_8013436C;
    // 0x80134340: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_80134344:
    // 0x80134344: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x80134348: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x8013434C: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x80134350: subu        $t6, $t2, $t3
    ctx->r14 = SUB32(ctx->r10, ctx->r11);
    // 0x80134354: div         $zero, $t6, $at
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r1)));
    // 0x80134358: mflo        $t4
    ctx->r12 = lo;
    // 0x8013435C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80134360: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80134364: addiu       $v0, $v0, 0x4908
    ctx->r2 = ADD32(ctx->r2, 0X4908);
    // 0x80134368: sw          $t4, 0x4908($at)
    MEM_W(0X4908, ctx->r1) = ctx->r12;
L_8013436C:
    // 0x8013436C: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80134370: addiu       $at, $zero, 0xC8
    ctx->r1 = ADD32(0, 0XC8);
    // 0x80134374: bne         $t5, $at, L_80134388
    if (ctx->r13 != ctx->r1) {
        // 0x80134378: nop
    
            goto L_80134388;
    }
    // 0x80134378: nop

    // 0x8013437C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80134380: addiu       $t9, $t7, 0x8
    ctx->r25 = ADD32(ctx->r15, 0X8);
    // 0x80134384: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80134388:
    // 0x80134388: jal         0x800269C0
    // 0x8013438C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_61;
    // 0x8013438C: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_61:
    // 0x80134390: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134394: jal         0x80009A84
    // 0x80134398: lw          $a0, 0x48F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F8);
    gcEjectGObj(rdram, ctx);
        goto after_62;
    // 0x80134398: lw          $a0, 0x48F8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F8);
    after_62:
    // 0x8013439C: jal         0x80132478
    // 0x801343A0: nop

    mnVSOptionsMakeDamageDigits(rdram, ctx);
        goto after_63;
    // 0x801343A0: nop

    after_63:
L_801343A4:
    // 0x801343A4: jal         0x8039076C
    // 0x801343A8: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_64;
    // 0x801343A8: ori         $a0, $zero, 0x8000
    ctx->r4 = 0 | 0X8000;
    after_64:
    // 0x801343AC: beq         $v0, $zero, L_801344F4
    if (ctx->r2 == 0) {
        // 0x801343B0: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_801344F4;
    }
    // 0x801343B0: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801343B4: lw          $v0, 0x48E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X48E0);
    // 0x801343B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801343BC: beq         $v0, $zero, L_801343DC
    if (ctx->r2 == 0) {
        // 0x801343C0: nop
    
            goto L_801343DC;
    }
    // 0x801343C0: nop

    // 0x801343C4: beq         $v0, $at, L_8013444C
    if (ctx->r2 == ctx->r1) {
        // 0x801343C8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8013444C;
    }
    // 0x801343C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801343CC: beq         $v0, $at, L_801344A4
    if (ctx->r2 == ctx->r1) {
        // 0x801343D0: nop
    
            goto L_801344A4;
    }
    // 0x801343D0: nop

    // 0x801343D4: b           L_801344F8
    // 0x801343D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801344F8;
    // 0x801343D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801343DC:
    // 0x801343DC: jal         0x800269C0
    // 0x801343E0: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_65;
    // 0x801343E0: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_65:
    // 0x801343E4: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801343E8: addiu       $v1, $v1, 0x48E4
    ctx->r3 = ADD32(ctx->r3, 0X48E4);
    // 0x801343EC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x801343F0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801343F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801343F8: bne         $a1, $zero, L_80134408
    if (ctx->r5 != 0) {
        // 0x801343FC: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80134408;
    }
    // 0x801343FC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134400: b           L_8013441C
    // 0x80134404: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
        goto L_8013441C;
    // 0x80134404: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80134408:
    // 0x80134408: bne         $a1, $at, L_80134418
    if (ctx->r5 != ctx->r1) {
        // 0x8013440C: addiu       $t0, $zero, 0x2
        ctx->r8 = ADD32(0, 0X2);
            goto L_80134418;
    }
    // 0x8013440C: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x80134410: b           L_8013441C
    // 0x80134414: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8013441C;
    // 0x80134414: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80134418:
    // 0x80134418: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
L_8013441C:
    // 0x8013441C: lw          $a0, 0x48C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C0);
    // 0x80134420: jal         0x80132184
    // 0x80134424: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    mnVSOptionsSetHandicapSpriteColors(rdram, ctx);
        goto after_66;
    // 0x80134424: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_66:
    // 0x80134428: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013442C: jal         0x80009A84
    // 0x80134430: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_67;
    // 0x80134430: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_67:
    // 0x80134434: jal         0x80132E58
    // 0x80134438: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_68;
    // 0x80134438: nop

    after_68:
    // 0x8013443C: jal         0x801339C4
    // 0x80134440: nop

    mnVSOptionsSetHandicapSettings(rdram, ctx);
        goto after_69;
    // 0x80134440: nop

    after_69:
    // 0x80134444: b           L_801344F8
    // 0x80134448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801344F8;
    // 0x80134448: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013444C:
    // 0x8013444C: jal         0x800269C0
    // 0x80134450: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_70;
    // 0x80134450: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_70:
    // 0x80134454: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x80134458: addiu       $v1, $v1, 0x48E8
    ctx->r3 = ADD32(ctx->r3, 0X48E8);
    // 0x8013445C: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x80134460: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80134464: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80134468: bne         $t1, $at, L_80134478
    if (ctx->r9 != ctx->r1) {
        // 0x8013446C: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_80134478;
    }
    // 0x8013446C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80134470: b           L_8013447C
    // 0x80134474: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_8013447C;
    // 0x80134474: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80134478:
    // 0x80134478: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
L_8013447C:
    // 0x8013447C: lw          $a0, 0x48C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C4);
    // 0x80134480: jal         0x80131FFC
    // 0x80134484: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    mnVSOptionsSetToggleSpriteColors(rdram, ctx);
        goto after_71;
    // 0x80134484: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_71:
    // 0x80134488: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x8013448C: jal         0x80009A84
    // 0x80134490: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_72;
    // 0x80134490: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_72:
    // 0x80134494: jal         0x80132E58
    // 0x80134498: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_73;
    // 0x80134498: nop

    after_73:
    // 0x8013449C: b           L_801344F8
    // 0x801344A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801344F8;
    // 0x801344A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801344A4:
    // 0x801344A4: jal         0x800269C0
    // 0x801344A8: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    func_800269C0_275C0(rdram, ctx);
        goto after_74;
    // 0x801344A8: addiu       $a0, $zero, 0xA3
    ctx->r4 = ADD32(0, 0XA3);
    after_74:
    // 0x801344AC: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x801344B0: addiu       $v1, $v1, 0x48EC
    ctx->r3 = ADD32(ctx->r3, 0X48EC);
    // 0x801344B4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x801344B8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801344BC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x801344C0: bne         $t3, $at, L_801344D0
    if (ctx->r11 != ctx->r1) {
        // 0x801344C4: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_801344D0;
    }
    // 0x801344C4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801344C8: b           L_801344D4
    // 0x801344CC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
        goto L_801344D4;
    // 0x801344CC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_801344D0:
    // 0x801344D0: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_801344D4:
    // 0x801344D4: lw          $a0, 0x48C8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48C8);
    // 0x801344D8: jal         0x80131FFC
    // 0x801344DC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    mnVSOptionsSetToggleSpriteColors(rdram, ctx);
        goto after_75;
    // 0x801344DC: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    after_75:
    // 0x801344E0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801344E4: jal         0x80009A84
    // 0x801344E8: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    gcEjectGObj(rdram, ctx);
        goto after_76;
    // 0x801344E8: lw          $a0, 0x48F4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X48F4);
    after_76:
    // 0x801344EC: jal         0x80132E58
    // 0x801344F0: nop

    mnVSOptionsMakeSubtitle(rdram, ctx);
        goto after_77;
    // 0x801344F0: nop

    after_77:
L_801344F4:
    // 0x801344F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801344F8:
    // 0x801344F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801344FC: jr          $ra
    // 0x80134500: nop

    return;
    // 0x80134500: nop

;}
RECOMP_FUNC void efManagerDamageNormalLightMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FDC04: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800FDC08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800FDC0C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800FDC10: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800FDC14: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800FDC18: jal         0x800FD4B8
    // 0x800FDC1C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x800FDC1C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800FDC20: bne         $v0, $zero, L_800FDC30
    if (ctx->r2 != 0) {
        // 0x800FDC24: sw          $v0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r2;
            goto L_800FDC30;
    }
    // 0x800FDC24: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800FDC28: b           L_800FDE2C
    // 0x800FDC2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FDE2C;
    // 0x800FDC2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FDC30:
    // 0x800FDC30: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FDC34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FDC38: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FDC3C: jal         0x80009968
    // 0x800FDC40: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x800FDC40: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x800FDC44: bne         $v0, $zero, L_800FDC5C
    if (ctx->r2 != 0) {
        // 0x800FDC48: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800FDC5C;
    }
    // 0x800FDC48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800FDC4C: jal         0x800FD4F8
    // 0x800FDC50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    efManagerSetPrevStructAlloc(rdram, ctx);
        goto after_2;
    // 0x800FDC50: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x800FDC54: b           L_800FDE2C
    // 0x800FDC58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FDE2C;
    // 0x800FDC58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FDC5C:
    // 0x800FDC5C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800FDC60: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800FDC64: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800FDC68: sw          $t6, 0x84($v1)
    MEM_W(0X84, ctx->r3) = ctx->r14;
    // 0x800FDC6C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800FDC70: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x800FDC74: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x800FDC78: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800FDC7C: jal         0x800CE9E8
    // 0x800FDC80: lbu         $a1, -0x20E0($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X20E0);
    lbParticleMakeScriptID(rdram, ctx);
        goto after_3;
    // 0x800FDC80: lbu         $a1, -0x20E0($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X20E0);
    after_3:
    // 0x800FDC84: beq         $v0, $zero, L_800FDE1C
    if (ctx->r2 == 0) {
        // 0x800FDC88: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_800FDE1C;
    }
    // 0x800FDC88: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x800FDC8C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FDC90: jal         0x800CE1DC
    // 0x800FDC94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_4;
    // 0x800FDC94: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800FDC98: beq         $v0, $zero, L_800FDE0C
    if (ctx->r2 == 0) {
        // 0x800FDC9C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_800FDE0C;
    }
    // 0x800FDC9C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800FDCA0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800FDCA4: lui         $t9, 0x8010
    ctx->r25 = S32(0X8010 << 16);
    // 0x800FDCA8: addiu       $t9, $t9, -0x2478
    ctx->r25 = ADD32(ctx->r25, -0X2478);
    // 0x800FDCAC: sw          $t9, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->r25;
    // 0x800FDCB0: sw          $t8, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->r24;
    // 0x800FDCB4: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800FDCB8: jal         0x800CEA14
    // 0x800FDCBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    LBParticleProcessStruct(rdram, ctx);
        goto after_5;
    // 0x800FDCBC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_5:
    // 0x800FDCC0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FDCC4: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FDCC8: addiu       $a1, $a1, -0x2434
    ctx->r5 = ADD32(ctx->r5, -0X2434);
    // 0x800FDCCC: lhu         $t0, 0x2A($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X2A);
    // 0x800FDCD0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x800FDCD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800FDCD8: bne         $t0, $zero, L_800FDCE8
    if (ctx->r8 != 0) {
        // 0x800FDCDC: addiu       $a3, $zero, 0x3
        ctx->r7 = ADD32(0, 0X3);
            goto L_800FDCE8;
    }
    // 0x800FDCDC: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800FDCE0: b           L_800FDE2C
    // 0x800FDCE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800FDE2C;
    // 0x800FDCE4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800FDCE8:
    // 0x800FDCE8: jal         0x80008188
    // 0x800FDCEC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x800FDCEC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_6:
    // 0x800FDCF0: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FDCF4: lw          $t1, 0x20($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X20);
    // 0x800FDCF8: sw          $v1, 0x28($t1)
    MEM_W(0X28, ctx->r9) = ctx->r3;
    // 0x800FDCFC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x800FDD00: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x800FDD04: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800FDD08: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x800FDD0C: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x800FDD10: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x800FDD14: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x800FDD18: lw          $t5, 0x3C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X3C);
    // 0x800FDD1C: beq         $t5, $zero, L_800FDD30
    if (ctx->r13 == 0) {
        // 0x800FDD20: nop
    
            goto L_800FDD30;
    }
    // 0x800FDD20: nop

    // 0x800FDD24: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800FDD28: b           L_800FDD58
    // 0x800FDD2C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
        goto L_800FDD58;
    // 0x800FDD2C: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
L_800FDD30:
    // 0x800FDD30: jal         0x80018948
    // 0x800FDD34: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x800FDD34: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_7:
    // 0x800FDD38: lui         $at, 0x4218
    ctx->r1 = S32(0X4218 << 16);
    // 0x800FDD3C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FDD40: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800FDD44: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800FDD48: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800FDD4C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FDD50: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800FDD54: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
L_800FDD58:
    // 0x800FDD58: jal         0x80018948
    // 0x800FDD5C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    syUtilsRandFloat(rdram, ctx);
        goto after_8;
    // 0x800FDD5C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_8:
    // 0x800FDD60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDD64: lwc1        $f18, 0x920($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X920);
    // 0x800FDD68: mul.s       $f12, $f0, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800FDD6C: jal         0x80035CD0
    // 0x800FDD70: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    __cosf_recomp(rdram, ctx);
        goto after_9;
    // 0x800FDD70: swc1        $f12, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f12.u32l;
    after_9:
    // 0x800FDD74: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800FDD78: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800FDD7C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800FDD80: swc1        $f6, 0x18($t6)
    MEM_W(0X18, ctx->r14) = ctx->f6.u32l;
    // 0x800FDD84: jal         0x800303F0
    // 0x800FDD88: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    __sinf_recomp(rdram, ctx);
        goto after_10;
    // 0x800FDD88: lwc1        $f12, 0x1C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X1C);
    after_10:
    // 0x800FDD8C: lwc1        $f8, 0x18($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800FDD90: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
    // 0x800FDD94: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x800FDD98: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800FDD9C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800FDDA0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x800FDDA4: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x800FDDA8: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800FDDAC: addiu       $t0, $v0, -0xA
    ctx->r8 = ADD32(ctx->r2, -0XA);
    // 0x800FDDB0: beq         $at, $zero, L_800FDDDC
    if (ctx->r1 == 0) {
        // 0x800FDDB4: swc1        $f10, 0x1C($t7)
        MEM_W(0X1C, ctx->r15) = ctx->f10.u32l;
            goto L_800FDDDC;
    }
    // 0x800FDDB4: swc1        $f10, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f10.u32l;
    // 0x800FDDB8: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800FDDBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDDC0: lwc1        $f4, 0x924($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X924);
    // 0x800FDDC4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800FDDC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FDDCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800FDDD0: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800FDDD4: b           L_800FDDFC
    // 0x800FDDD8: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
        goto L_800FDDFC;
    // 0x800FDDD8: add.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f8.fl;
L_800FDDDC:
    // 0x800FDDDC: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x800FDDE0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800FDDE4: lwc1        $f18, 0x928($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X928);
    // 0x800FDDE8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800FDDEC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800FDDF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800FDDF4: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800FDDF8: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
L_800FDDFC:
    // 0x800FDDFC: swc1        $f0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f0.u32l;
    // 0x800FDE00: swc1        $f0, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f0.u32l;
    // 0x800FDE04: b           L_800FDE28
    // 0x800FDE08: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
        goto L_800FDE28;
    // 0x800FDE08: swc1        $f0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f0.u32l;
L_800FDE0C:
    // 0x800FDE0C: jal         0x800FDB3C
    // 0x800FDE10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_11;
    // 0x800FDE10: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_11:
    // 0x800FDE14: b           L_800FDE28
    // 0x800FDE18: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
        goto L_800FDE28;
    // 0x800FDE18: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_800FDE1C:
    // 0x800FDE1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800FDE20: jal         0x800FDB3C
    // 0x800FDE24: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    efManagerDestroyParticleGObj(rdram, ctx);
        goto after_12;
    // 0x800FDE24: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    after_12:
L_800FDE28:
    // 0x800FDE28: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_800FDE2C:
    // 0x800FDE2C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800FDE30: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800FDE34: jr          $ra
    // 0x800FDE38: nop

    return;
    // 0x800FDE38: nop

;}
RECOMP_FUNC void mnSoundTestMakeBButtonSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C90: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132C94: lw          $t6, 0x4468($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4468);
    // 0x80132C98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132C9C: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132CA4: addiu       $t7, $t7, 0xA88
    ctx->r15 = ADD32(ctx->r15, 0XA88);
    // 0x80132CA8: jal         0x800CCFDC
    // 0x80132CAC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132CAC: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80132CB0: lui         $at, 0x435A
    ctx->r1 = S32(0X435A << 16);
    // 0x80132CB4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132CB8: lui         $at, 0x434D
    ctx->r1 = S32(0X434D << 16);
    // 0x80132CBC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132CC0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132CC4: addiu       $t9, $zero, 0x6E
    ctx->r25 = ADD32(0, 0X6E);
    // 0x80132CC8: addiu       $t0, $zero, 0x77
    ctx->r8 = ADD32(0, 0X77);
    // 0x80132CCC: addiu       $t1, $zero, 0x5D
    ctx->r9 = ADD32(0, 0X5D);
    // 0x80132CD0: addiu       $t2, $zero, 0x29
    ctx->r10 = ADD32(0, 0X29);
    // 0x80132CD4: addiu       $t3, $zero, 0x37
    ctx->r11 = ADD32(0, 0X37);
    // 0x80132CD8: addiu       $t4, $zero, 0x16
    ctx->r12 = ADD32(0, 0X16);
    // 0x80132CDC: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132CE0: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80132CE4: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80132CE8: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80132CEC: sb          $t2, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r10;
    // 0x80132CF0: sb          $t3, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r11;
    // 0x80132CF4: sb          $t4, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r12;
    // 0x80132CF8: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132CFC: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132D04: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132D08: jr          $ra
    // 0x80132D0C: nop

    return;
    // 0x80132D0C: nop

;}
RECOMP_FUNC void itStarmieWeaponSwiftProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182418: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018241C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182420: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80182424: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80182428: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8018242C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80182430: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x80182434: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80182438: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x8018243C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80182440: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x80182444: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80182448: jal         0x80019438
    // 0x8018244C: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x8018244C: nop

    after_0:
    // 0x80182450: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80182454: lwc1        $f12, 0x24($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80182458: jal         0x8001863C
    // 0x8018245C: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x8018245C: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    after_1:
    // 0x80182460: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80182464: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80182468: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018246C: lw          $t7, 0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X74);
    // 0x80182470: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80182474: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80182478: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
    // 0x8018247C: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x80182480: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80182484: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80182488: swc1        $f10, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f10.u32l;
    // 0x8018248C: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80182490: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80182494: nop

    // 0x80182498: bc1fl       L_801824AC
    if (!c1cs) {
        // 0x8018249C: sw          $t0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r8;
            goto L_801824AC;
    }
    goto skip_0;
    // 0x8018249C: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    skip_0:
    // 0x801824A0: b           L_801824AC
    // 0x801824A4: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
        goto L_801824AC;
    // 0x801824A4: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x801824A8: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_801824AC:
    // 0x801824AC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801824B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801824B4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801824B8: jr          $ra
    // 0x801824BC: nop

    return;
    // 0x801824BC: nop

;}
RECOMP_FUNC void gmCollisionCheckItemAttackFighterAttackCollide(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F02BC: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800F02C0: sw          $s1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r17;
    // 0x800F02C4: sw          $s0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r16;
    // 0x800F02C8: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800F02CC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F02D0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800F02D4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800F02D8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800F02DC: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x800F02E0: addiu       $v1, $s0, 0x44
    ctx->r3 = ADD32(ctx->r16, 0X44);
    // 0x800F02E4: addiu       $t0, $s0, 0x50
    ctx->r8 = ADD32(ctx->r16, 0X50);
    // 0x800F02E8: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800F02EC: sw          $v1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r3;
    // 0x800F02F0: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800F02F4: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800F02F8: subu        $t7, $t7, $a1
    ctx->r15 = SUB32(ctx->r15, ctx->r5);
    // 0x800F02FC: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800F0300: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800F0304: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x800F0308: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x800F030C: addiu       $a0, $v0, 0x58
    ctx->r4 = ADD32(ctx->r2, 0X58);
    // 0x800F0310: addiu       $a1, $v0, 0x64
    ctx->r5 = ADD32(ctx->r2, 0X64);
    // 0x800F0314: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    // 0x800F0318: sw          $a0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r4;
    // 0x800F031C: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800F0320: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x800F0324: jal         0x800EF5D4
    // 0x800F0328: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    func_ovl2_800EF5D4(rdram, ctx);
        goto after_0;
    // 0x800F0328: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    after_0:
    // 0x800F032C: bne         $v0, $zero, L_800F033C
    if (ctx->r2 != 0) {
        // 0x800F0330: lw          $a1, 0x44($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X44);
            goto L_800F033C;
    }
    // 0x800F0330: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x800F0334: b           L_800F03A4
    // 0x800F0338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F03A4;
    // 0x800F0338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F033C:
    // 0x800F033C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800F0340: addiu       $v0, $s0, 0x80
    ctx->r2 = ADD32(ctx->r16, 0X80);
    // 0x800F0344: addiu       $t9, $s0, 0xC0
    ctx->r25 = ADD32(ctx->r16, 0XC0);
    // 0x800F0348: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800F034C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F0350: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800F0354: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800F0358: jal         0x800EE050
    // 0x800F035C: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    func_ovl2_800EE050(rdram, ctx);
        goto after_1;
    // 0x800F035C: addiu       $a3, $s0, 0x7C
    ctx->r7 = ADD32(ctx->r16, 0X7C);
    after_1:
    // 0x800F0360: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0364: lw          $a2, 0x2C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X2C);
    // 0x800F0368: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800F036C: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F0370: lw          $t1, 0x7C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X7C);
    // 0x800F0374: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800F0378: lw          $a0, 0x4C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X4C);
    // 0x800F037C: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800F0380: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x800F0384: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800F0388: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800F038C: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x800F0390: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x800F0394: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x800F0398: lwc1        $f8, 0xC0($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC0);
    // 0x800F039C: jal         0x800EEEAC
    // 0x800F03A0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    func_ovl2_800EEEAC(rdram, ctx);
        goto after_2;
    // 0x800F03A0: swc1        $f8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f8.u32l;
    after_2:
L_800F03A4:
    // 0x800F03A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800F03A8: lw          $s0, 0x2C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X2C);
    // 0x800F03AC: lw          $s1, 0x30($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X30);
    // 0x800F03B0: jr          $ra
    // 0x800F03B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800F03B4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_ovl8_8037D6D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037D6D4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8037D6D8: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8037D6DC: addiu       $a2, $a2, -0xFF8
    ctx->r6 = ADD32(ctx->r6, -0XFF8);
    // 0x8037D6E0: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8037D6E4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x8037D6E8: lhu         $t8, 0x2($a2)
    ctx->r24 = MEM_HU(ctx->r6, 0X2);
    // 0x8037D6EC: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8037D6F0: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x8037D6F4: lw          $t7, 0x8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8);
    // 0x8037D6F8: sw          $t7, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r15;
    // 0x8037D6FC: lw          $t6, 0xC($a0)
    ctx->r14 = MEM_W(ctx->r4, 0XC);
    // 0x8037D700: sw          $t6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r14;
    // 0x8037D704: lbu         $v1, 0xC($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0XC);
    // 0x8037D708: lw          $t7, 0x10($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X10);
    // 0x8037D70C: lui         $t6, 0x8038
    ctx->r14 = S32(0X8038 << 16);
    // 0x8037D710: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037D714: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8037D718: addiu       $t6, $t6, -0x2A54
    ctx->r14 = ADD32(ctx->r14, -0X2A54);
    // 0x8037D71C: sw          $t7, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r15;
    // 0x8037D720: mflo        $v0
    ctx->r2 = lo;
    // 0x8037D724: andi        $a1, $v0, 0xFFFF
    ctx->r5 = ctx->r2 & 0XFFFF;
    // 0x8037D728: andi        $t9, $a1, 0x7
    ctx->r25 = ctx->r5 & 0X7;
    // 0x8037D72C: beq         $t9, $zero, L_8037D73C
    if (ctx->r25 == 0) {
        // 0x8037D730: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8037D73C;
    }
    // 0x8037D730: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8037D734: b           L_8037D73C
    // 0x8037D738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8037D73C;
    // 0x8037D738: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8037D73C:
    // 0x8037D73C: lhu         $t2, 0x4($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X4);
    // 0x8037D740: bgez        $a1, L_8037D750
    if (SIGNED(ctx->r5) >= 0) {
        // 0x8037D744: sra         $t0, $a1, 3
        ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8037D750;
    }
    // 0x8037D744: sra         $t0, $a1, 3
    ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8037D748: addiu       $at, $a1, 0x7
    ctx->r1 = ADD32(ctx->r5, 0X7);
    // 0x8037D74C: sra         $t0, $at, 3
    ctx->r8 = S32(SIGNED(ctx->r1) >> 3);
L_8037D750:
    // 0x8037D750: addu        $t1, $t0, $v0
    ctx->r9 = ADD32(ctx->r8, ctx->r2);
    // 0x8037D754: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037D758: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D75C: mflo        $t3
    ctx->r11 = lo;
    // 0x8037D760: sh          $t3, -0xFD0($at)
    MEM_H(-0XFD0, ctx->r1) = ctx->r11;
    // 0x8037D764: bne         $a0, $v1, L_8037D780
    if (ctx->r4 != ctx->r3) {
        // 0x8037D768: sllv        $t5, $t4, $v1
        ctx->r13 = S32(ctx->r12 << (ctx->r3 & 31));
            goto L_8037D780;
    }
    // 0x8037D768: sllv        $t5, $t4, $v1
    ctx->r13 = S32(ctx->r12 << (ctx->r3 & 31));
    // 0x8037D76C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8037D770: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8037D774: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D778: b           L_8037D790
    // 0x8037D77C: swc1        $f4, -0xFCC($at)
    MEM_W(-0XFCC, ctx->r1) = ctx->f4.u32l;
        goto L_8037D790;
    // 0x8037D77C: swc1        $f4, -0xFCC($at)
    MEM_W(-0XFCC, ctx->r1) = ctx->f4.u32l;
L_8037D780:
    // 0x8037D780: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8037D784: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D788: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8037D78C: swc1        $f8, -0xFCC($at)
    MEM_W(-0XFCC, ctx->r1) = ctx->f8.u32l;
L_8037D790:
    // 0x8037D790: bne         $a0, $v1, L_8037D7A4
    if (ctx->r4 != ctx->r3) {
        // 0x8037D794: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8037D7A4;
    }
    // 0x8037D794: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8037D798: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D79C: jr          $ra
    // 0x8037D7A0: sw          $t6, -0xFC4($at)
    MEM_W(-0XFC4, ctx->r1) = ctx->r14;
    return;
    // 0x8037D7A0: sw          $t6, -0xFC4($at)
    MEM_W(-0XFC4, ctx->r1) = ctx->r14;
L_8037D7A4:
    // 0x8037D7A4: bne         $v1, $at, L_8037D7C0
    if (ctx->r3 != ctx->r1) {
        // 0x8037D7A8: lui         $t8, 0x8038
        ctx->r24 = S32(0X8038 << 16);
            goto L_8037D7C0;
    }
    // 0x8037D7A8: lui         $t8, 0x8038
    ctx->r24 = S32(0X8038 << 16);
    // 0x8037D7AC: lui         $t7, 0x8038
    ctx->r15 = S32(0X8038 << 16);
    // 0x8037D7B0: addiu       $t7, $t7, -0x2AE8
    ctx->r15 = ADD32(ctx->r15, -0X2AE8);
    // 0x8037D7B4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D7B8: jr          $ra
    // 0x8037D7BC: sw          $t7, -0xFC4($at)
    MEM_W(-0XFC4, ctx->r1) = ctx->r15;
    return;
    // 0x8037D7BC: sw          $t7, -0xFC4($at)
    MEM_W(-0XFC4, ctx->r1) = ctx->r15;
L_8037D7C0:
    // 0x8037D7C0: addiu       $t8, $t8, -0x2B90
    ctx->r24 = ADD32(ctx->r24, -0X2B90);
    // 0x8037D7C4: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8037D7C8: sw          $t8, -0xFC4($at)
    MEM_W(-0XFC4, ctx->r1) = ctx->r24;
    // 0x8037D7CC: jr          $ra
    // 0x8037D7D0: nop

    return;
    // 0x8037D7D0: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void syTaskmanLoadScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006548: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x8000654C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80006550: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80006554: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x80006558: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000655C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80006560: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80006564: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80006568: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x8000656C: lw          $t6, 0x18($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18);
    // 0x80006570: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80006574: addiu       $s5, $s5, 0x6640
    ctx->r21 = ADD32(ctx->r21, 0X6640);
    // 0x80006578: sw          $t6, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r14;
    // 0x8000657C: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x80006580: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006584: addiu       $v0, $v0, 0x65F8
    ctx->r2 = ADD32(ctx->r2, 0X65F8);
    // 0x80006588: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8000658C: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    // 0x80006590: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80006594: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80006598: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8000659C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800065A0: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x800065A4: lw          $t0, 0x14($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X14);
    // 0x800065A8: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x800065AC: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x800065B0: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x800065B4: multu       $t1, $t6
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800065B8: mflo        $a0
    ctx->r4 = lo;
    // 0x800065BC: jal         0x80004980
    // 0x800065C0: nop

    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800065C0: nop

    after_0:
    // 0x800065C4: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800065C8: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800065CC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800065D0: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x800065D4: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800065D8: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x800065DC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x800065E0: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x800065E4: jal         0x80004980
    // 0x800065E8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    syTaskmanMalloc(rdram, ctx);
        goto after_1;
    // 0x800065E8: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    after_1:
    // 0x800065EC: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800065F0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800065F4: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x800065F8: addu        $at, $a0, $zero
    ctx->r1 = ADD32(ctx->r4, 0);
    // 0x800065FC: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    // 0x80006600: subu        $a0, $a0, $at
    ctx->r4 = SUB32(ctx->r4, ctx->r1);
    // 0x80006604: jal         0x80004980
    // 0x80006608: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    syTaskmanMalloc(rdram, ctx);
        goto after_2;
    // 0x80006608: sll         $a0, $a0, 3
    ctx->r4 = S32(ctx->r4 << 3);
    after_2:
    // 0x8000660C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80006610: lw          $a1, 0x14($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X14);
    // 0x80006614: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80006618: jal         0x80004DB4
    // 0x8000661C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    func_80004DB4(rdram, ctx);
        goto after_3;
    // 0x8000661C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_3:
    // 0x80006620: lw          $t3, 0x0($s5)
    ctx->r11 = MEM_W(ctx->r21, 0X0);
    // 0x80006624: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80006628: blez        $t3, L_800066A8
    if (SIGNED(ctx->r11) <= 0) {
        // 0x8000662C: addiu       $s0, $sp, 0x44
        ctx->r16 = ADD32(ctx->r29, 0X44);
            goto L_800066A8;
    }
    // 0x8000662C: addiu       $s0, $sp, 0x44
    ctx->r16 = ADD32(ctx->r29, 0X44);
L_80006630:
    // 0x80006630: lw          $a0, 0x1C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X1C);
    // 0x80006634: jal         0x80004980
    // 0x80006638: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_4;
    // 0x80006638: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_4:
    // 0x8000663C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80006640: lw          $t4, 0x1C($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X1C);
    // 0x80006644: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80006648: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x8000664C: jal         0x80004980
    // 0x80006650: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    syTaskmanMalloc(rdram, ctx);
        goto after_5;
    // 0x80006650: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    after_5:
    // 0x80006654: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x80006658: lw          $t5, 0x20($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X20);
    // 0x8000665C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80006660: sw          $t5, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->r13;
    // 0x80006664: jal         0x80004980
    // 0x80006668: lw          $a0, 0x24($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X24);
    syTaskmanMalloc(rdram, ctx);
        goto after_6;
    // 0x80006668: lw          $a0, 0x24($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X24);
    after_6:
    // 0x8000666C: sw          $v0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->r2;
    // 0x80006670: lw          $t6, 0x24($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X24);
    // 0x80006674: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80006678: sw          $t6, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->r14;
    // 0x8000667C: jal         0x80004980
    // 0x80006680: lw          $a0, 0x28($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X28);
    syTaskmanMalloc(rdram, ctx);
        goto after_7;
    // 0x80006680: lw          $a0, 0x28($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X28);
    after_7:
    // 0x80006684: lw          $t8, 0x0($s5)
    ctx->r24 = MEM_W(ctx->r21, 0X0);
    // 0x80006688: sw          $v0, 0x18($s0)
    MEM_W(0X18, ctx->r16) = ctx->r2;
    // 0x8000668C: lw          $t7, 0x28($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X28);
    // 0x80006690: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80006694: slt         $at, $s3, $t8
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80006698: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x8000669C: bne         $at, $zero, L_80006630
    if (ctx->r1 != 0) {
        // 0x800066A0: sw          $t7, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r15;
            goto L_80006630;
    }
    // 0x800066A0: sw          $t7, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r15;
    // 0x800066A4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_800066A8:
    // 0x800066A8: jal         0x80004A0C
    // 0x800066AC: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    syTaskmanSetDLBuffer(rdram, ctx);
        goto after_8;
    // 0x800066AC: addiu       $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    after_8:
    // 0x800066B0: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x800066B4: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x800066B8: addiu       $s0, $s0, 0x6648
    ctx->r16 = ADD32(ctx->r16, 0X6648);
    // 0x800066BC: blez        $t9, L_80006724
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800066C0: lui         $s4, 0x1
        ctx->r20 = S32(0X1 << 16);
            goto L_80006724;
    }
    // 0x800066C0: lui         $s4, 0x1
    ctx->r20 = S32(0X1 << 16);
    // 0x800066C4: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x800066C8: addiu       $s1, $s1, 0x65D8
    ctx->r17 = ADD32(ctx->r17, 0X65D8);
    // 0x800066CC: ori         $s4, $s4, 0x2
    ctx->r20 = ctx->r20 | 0X2;
L_800066D0:
    // 0x800066D0: lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X2C);
    // 0x800066D4: jal         0x80004980
    // 0x800066D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    syTaskmanMalloc(rdram, ctx);
        goto after_9;
    // 0x800066D8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_9:
    // 0x800066DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800066E0: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800066E4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800066E8: jal         0x80006D54
    // 0x800066EC: lw          $a3, 0x2C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X2C);
    syMallocInit(rdram, ctx);
        goto after_10;
    // 0x800066EC: lw          $a3, 0x2C($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X2C);
    after_10:
    // 0x800066F0: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x800066F4: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x800066F8: lw          $t1, 0x4($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X4);
    // 0x800066FC: lw          $t2, 0x8($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X8);
    // 0x80006700: lw          $t3, 0xC($s1)
    ctx->r11 = MEM_W(ctx->r17, 0XC);
    // 0x80006704: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80006708: slt         $at, $s3, $t4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8000670C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80006710: sw          $t0, -0x10($s0)
    MEM_W(-0X10, ctx->r16) = ctx->r8;
    // 0x80006714: sw          $t1, -0xC($s0)
    MEM_W(-0XC, ctx->r16) = ctx->r9;
    // 0x80006718: sw          $t2, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r10;
    // 0x8000671C: bne         $at, $zero, L_800066D0
    if (ctx->r1 != 0) {
        // 0x80006720: sw          $t3, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r11;
            goto L_800066D0;
    }
    // 0x80006720: sw          $t3, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r11;
L_80006724:
    // 0x80006724: lw          $v0, 0x34($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X34);
    // 0x80006728: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8000672C: sh          $t5, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r13;
    // 0x80006730: bne         $v0, $zero, L_80006740
    if (ctx->r2 != 0) {
        // 0x80006734: addiu       $a1, $zero, 0x10
        ctx->r5 = ADD32(0, 0X10);
            goto L_80006740;
    }
    // 0x80006734: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80006738: addiu       $v0, $zero, 0x1000
    ctx->r2 = ADD32(0, 0X1000);
    // 0x8000673C: sw          $v0, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->r2;
L_80006740:
    // 0x80006740: jal         0x80004980
    // 0x80006744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    syTaskmanMalloc(rdram, ctx);
        goto after_11;
    // 0x80006744: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_11:
    // 0x80006748: lhu         $a0, 0x30($s2)
    ctx->r4 = MEM_HU(ctx->r18, 0X30);
    // 0x8000674C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80006750: jal         0x80004CB4
    // 0x80006754: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    syTaskmanSetRdpOutputBuffer(rdram, ctx);
        goto after_12;
    // 0x80006754: lw          $a2, 0x34($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X34);
    after_12:
    // 0x80006758: jal         0x80007168
    // 0x8000675C: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    syRdpSetFuncLights(rdram, ctx);
        goto after_13;
    // 0x8000675C: lw          $a0, 0x38($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X38);
    after_13:
    // 0x80006760: lw          $t7, 0x3C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X3C);
    // 0x80006764: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006768: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8000676C: addiu       $v0, $v0, 0x6668
    ctx->r2 = ADD32(ctx->r2, 0X6668);
    // 0x80006770: addiu       $t9, $t9, 0x42E8
    ctx->r25 = ADD32(ctx->r25, 0X42E8);
    // 0x80006774: beq         $t7, $t9, L_80006784
    if (ctx->r15 == ctx->r25) {
        // 0x80006778: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80006784;
    }
    // 0x80006778: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000677C: b           L_80006788
    // 0x80006780: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80006788;
    // 0x80006780: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80006784:
    // 0x80006784: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80006788:
    // 0x80006788: jal         0x80004368
    // 0x8000678C: nop

    syControllerSetAutoRead(rdram, ctx);
        goto after_14;
    // 0x8000678C: nop

    after_14:
    // 0x80006790: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x80006794: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80006798: addiu       $v0, $v0, -0x4918
    ctx->r2 = ADD32(ctx->r2, -0X4918);
    // 0x8000679C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800067A0: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800067A4: beq         $v1, $zero, L_800067B4
    if (ctx->r3 == 0) {
        // 0x800067A8: sw          $zero, -0x491C($at)
        MEM_W(-0X491C, ctx->r1) = 0;
            goto L_800067B4;
    }
    // 0x800067A8: sw          $zero, -0x491C($at)
    MEM_W(-0X491C, ctx->r1) = 0;
    // 0x800067AC: jalr        $v1
    // 0x800067B0: nop

    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_15;
    // 0x800067B0: nop

    after_15:
L_800067B4:
    // 0x800067B4: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800067B8: jal         0x80005DA0
    // 0x800067BC: addiu       $a0, $a0, 0x65F8
    ctx->r4 = ADD32(ctx->r4, 0X65F8);
    syTaskmanRunTask(rdram, ctx);
        goto after_16;
    // 0x800067BC: addiu       $a0, $a0, 0x65F8
    ctx->r4 = ADD32(ctx->r4, 0X65F8);
    after_16:
    // 0x800067C0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800067C4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800067C8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800067CC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800067D0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800067D4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800067D8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800067DC: jr          $ra
    // 0x800067E0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x800067E0: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void sc1PManagerTrySaveBackup(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6738: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800D673C: addiu       $a1, $a1, 0x4AD0
    ctx->r5 = ADD32(ctx->r5, 0X4AD0);
    // 0x800D6740: lbu         $t6, 0x14($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X14);
    // 0x800D6744: lui         $a3, 0x800A
    ctx->r7 = S32(0X800A << 16);
    // 0x800D6748: addiu       $a3, $a3, 0x44E0
    ctx->r7 = ADD32(ctx->r7, 0X44E0);
    // 0x800D674C: sll         $t7, $t6, 5
    ctx->r15 = S32(ctx->r14 << 5);
    // 0x800D6750: addu        $v0, $a3, $t7
    ctx->r2 = ADD32(ctx->r7, ctx->r15);
    // 0x800D6754: lw          $t8, 0x45C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X45C);
    // 0x800D6758: lw          $v1, 0x20($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X20);
    // 0x800D675C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800D6760: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D6764: sltu        $at, $t8, $v1
    ctx->r1 = ctx->r24 < ctx->r3 ? 1 : 0;
    // 0x800D6768: beq         $at, $zero, L_800D67A0
    if (ctx->r1 == 0) {
        // 0x800D676C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800D67A0;
    }
    // 0x800D676C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6770: lw          $t9, 0x24($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X24);
    // 0x800D6774: lw          $t0, 0x28($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X28);
    // 0x800D6778: sw          $v1, 0x45C($v0)
    MEM_W(0X45C, ctx->r2) = ctx->r3;
    // 0x800D677C: sw          $t9, 0x460($v0)
    MEM_W(0X460, ctx->r2) = ctx->r25;
    // 0x800D6780: beq         $a0, $zero, L_800D6798
    if (ctx->r4 == 0) {
        // 0x800D6784: sw          $t0, 0x464($v0)
        MEM_W(0X464, ctx->r2) = ctx->r8;
            goto L_800D6798;
    }
    // 0x800D6784: sw          $t0, 0x464($v0)
    MEM_W(0X464, ctx->r2) = ctx->r8;
    // 0x800D6788: lbu         $t1, 0x45A($a3)
    ctx->r9 = MEM_BU(ctx->r7, 0X45A);
    // 0x800D678C: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800D6790: b           L_800D679C
    // 0x800D6794: sb          $t2, 0x468($v0)
    MEM_B(0X468, ctx->r2) = ctx->r10;
        goto L_800D679C;
    // 0x800D6794: sb          $t2, 0x468($v0)
    MEM_B(0X468, ctx->r2) = ctx->r10;
L_800D6798:
    // 0x800D6798: sb          $zero, 0x468($v0)
    MEM_B(0X468, ctx->r2) = 0;
L_800D679C:
    // 0x800D679C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800D67A0:
    // 0x800D67A0: lbu         $t3, 0x479($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X479);
    // 0x800D67A4: bne         $t3, $zero, L_800D67BC
    if (ctx->r11 != 0) {
        // 0x800D67A8: nop
    
            goto L_800D67BC;
    }
    // 0x800D67A8: nop

    // 0x800D67AC: beq         $a0, $zero, L_800D67BC
    if (ctx->r4 == 0) {
        // 0x800D67B0: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800D67BC;
    }
    // 0x800D67B0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800D67B4: sb          $t4, 0x479($v0)
    MEM_B(0X479, ctx->r2) = ctx->r12;
    // 0x800D67B8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800D67BC:
    // 0x800D67BC: beql        $a2, $zero, L_800D67D0
    if (ctx->r6 == 0) {
        // 0x800D67C0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800D67D0;
    }
    goto skip_0;
    // 0x800D67C0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800D67C4: jal         0x800D45F4
    // 0x800D67C8: nop

    lbBackupWrite(rdram, ctx);
        goto after_0;
    // 0x800D67C8: nop

    after_0:
    // 0x800D67CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800D67D0:
    // 0x800D67D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800D67D4: jr          $ra
    // 0x800D67D8: nop

    return;
    // 0x800D67D8: nop

;}
RECOMP_FUNC void mpCollisionGetUDEdge(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F4488: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F448C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800F4490: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800F4494: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F4498: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800F449C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800F44A0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F44A4: beq         $a0, $at, L_800F44B8
    if (ctx->r4 == ctx->r1) {
        // 0x800F44A8: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_800F44B8;
    }
    // 0x800F44A8: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800F44AC: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800F44B0: bne         $a0, $at, L_800F44DC
    if (ctx->r4 != ctx->r1) {
        // 0x800F44B4: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800F44DC;
    }
    // 0x800F44B4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
L_800F44B8:
    // 0x800F44B8: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F44BC: addiu       $s0, $s0, 0x35C
    ctx->r16 = ADD32(ctx->r16, 0X35C);
    // 0x800F44C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800F44C4:
    // 0x800F44C4: jal         0x80023624
    // 0x800F44C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800F44C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_0:
    // 0x800F44CC: jal         0x800A3040
    // 0x800F44D0: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800F44D0: nop

    after_1:
    // 0x800F44D4: b           L_800F44C4
    // 0x800F44D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_800F44C4;
    // 0x800F44D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800F44DC:
    // 0x800F44DC: lw          $t6, 0x136C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X136C);
    // 0x800F44E0: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800F44E4: addu        $t7, $t7, $s1
    ctx->r15 = ADD32(ctx->r15, ctx->r17);
    // 0x800F44E8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800F44EC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800F44F0: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800F44F4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F44F8: lw          $t7, 0x1304($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1304);
    // 0x800F44FC: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800F4500: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800F4504: lw          $t2, 0x0($t8)
    ctx->r10 = MEM_W(ctx->r24, 0X0);
    // 0x800F4508: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800F450C: lw          $t9, 0x84($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X84);
    // 0x800F4510: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x800F4514: bne         $at, $zero, L_800F453C
    if (ctx->r1 != 0) {
        // 0x800F4518: nop
    
            goto L_800F453C;
    }
    // 0x800F4518: nop

    // 0x800F451C: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800F4520: addiu       $s0, $s0, 0x374
    ctx->r16 = ADD32(ctx->r16, 0X374);
L_800F4524:
    // 0x800F4524: jal         0x80023624
    // 0x800F4528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800F4528: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800F452C: jal         0x800A3040
    // 0x800F4530: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800F4530: nop

    after_3:
    // 0x800F4534: b           L_800F4524
    // 0x800F4538: nop

        goto L_800F4524;
    // 0x800F4538: nop

L_800F453C:
    // 0x800F453C: lw          $t6, 0x1378($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1378);
    // 0x800F4540: sll         $t7, $s1, 2
    ctx->r15 = S32(ctx->r17 << 2);
    // 0x800F4544: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800F4548: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x800F454C: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x800F4550: lw          $a1, 0x1374($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1374);
    // 0x800F4554: addiu       $t5, $zero, 0x6
    ctx->r13 = ADD32(0, 0X6);
    // 0x800F4558: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x800F455C: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x800F4560: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x800F4564: lhu         $t8, 0x2($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X2);
    // 0x800F4568: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F456C: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F4570: addu        $a2, $t8, $v1
    ctx->r6 = ADD32(ctx->r24, ctx->r3);
    // 0x800F4574: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800F4578: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x800F457C: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x800F4580: lhu         $t6, 0x0($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X0);
    // 0x800F4584: lw          $a0, 0x1370($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1370);
    // 0x800F4588: mflo        $t8
    ctx->r24 = lo;
    // 0x800F458C: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x800F4590: lh          $t0, 0x2($t3)
    ctx->r8 = MEM_H(ctx->r11, 0X2);
    // 0x800F4594: multu       $t6, $t5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F4598: mflo        $t8
    ctx->r24 = lo;
    // 0x800F459C: addu        $t4, $a0, $t8
    ctx->r12 = ADD32(ctx->r4, ctx->r24);
    // 0x800F45A0: bgez        $s0, L_800F45B0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x800F45A4: lh          $t1, 0x2($t4)
        ctx->r9 = MEM_H(ctx->r12, 0X2);
            goto L_800F45B0;
    }
    // 0x800F45A4: lh          $t1, 0x2($t4)
    ctx->r9 = MEM_H(ctx->r12, 0X2);
    // 0x800F45A8: b           L_800F45B4
    // 0x800F45AC: slt         $v0, $t0, $t1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
        goto L_800F45B4;
    // 0x800F45AC: slt         $v0, $t0, $t1
    ctx->r2 = SIGNED(ctx->r8) < SIGNED(ctx->r9) ? 1 : 0;
L_800F45B0:
    // 0x800F45B0: slt         $v0, $t1, $t0
    ctx->r2 = SIGNED(ctx->r9) < SIGNED(ctx->r8) ? 1 : 0;
L_800F45B4:
    // 0x800F45B4: beql        $v0, $zero, L_800F45E0
    if (ctx->r2 == 0) {
        // 0x800F45B8: lh          $t7, 0x0($t4)
        ctx->r15 = MEM_H(ctx->r12, 0X0);
            goto L_800F45E0;
    }
    goto skip_0;
    // 0x800F45B8: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    skip_0:
    // 0x800F45BC: lh          $t9, 0x0($t3)
    ctx->r25 = MEM_H(ctx->r11, 0X0);
    // 0x800F45C0: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x800F45C4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800F45C8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F45CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F45D0: swc1        $f10, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f10.u32l;
    // 0x800F45D4: b           L_800F45F8
    // 0x800F45D8: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
        goto L_800F45F8;
    // 0x800F45D8: swc1        $f6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f6.u32l;
    // 0x800F45DC: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
L_800F45E0:
    // 0x800F45E0: mtc1        $t1, $f4
    ctx->f4.u32l = ctx->r9;
    // 0x800F45E4: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800F45E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F45EC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800F45F0: swc1        $f6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f6.u32l;
    // 0x800F45F4: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
L_800F45F8:
    // 0x800F45F8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800F45FC: nop

    // 0x800F4600: swc1        $f8, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f8.u32l;
    // 0x800F4604: lw          $t6, 0x70($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X70);
    // 0x800F4608: bnel        $t6, $zero, L_800F4620
    if (ctx->r14 != 0) {
        // 0x800F460C: lwc1        $f10, 0x0($a3)
        ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
            goto L_800F4620;
    }
    goto skip_1;
    // 0x800F460C: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
    skip_1:
    // 0x800F4610: lw          $t8, 0x84($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X84);
    // 0x800F4614: beql        $t8, $zero, L_800F4640
    if (ctx->r24 == 0) {
        // 0x800F4618: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800F4640;
    }
    goto skip_2;
    // 0x800F4618: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x800F461C: lwc1        $f10, 0x0($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X0);
L_800F4620:
    // 0x800F4620: lwc1        $f16, 0x1C($t2)
    ctx->f16.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x800F4624: lwc1        $f4, 0x4($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800F4628: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F462C: swc1        $f18, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f18.u32l;
    // 0x800F4630: lwc1        $f6, 0x20($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0X20);
    // 0x800F4634: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F4638: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x800F463C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800F4640:
    // 0x800F4640: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800F4644: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800F4648: jr          $ra
    // 0x800F464C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800F464C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void itPakkunAppearProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017D298: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017D29C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017D2A0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017D2A4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017D2A8: lbu         $t6, 0x35C($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X35C);
    // 0x8017D2AC: beql        $t6, $zero, L_8017D2DC
    if (ctx->r14 == 0) {
        // 0x8017D2B0: lw          $v1, 0x74($a0)
        ctx->r3 = MEM_W(ctx->r4, 0X74);
            goto L_8017D2DC;
    }
    goto skip_0;
    // 0x8017D2B0: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    skip_0:
    // 0x8017D2B4: lwc1        $f4, -0x3200($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X3200);
    // 0x8017D2B8: lw          $t7, 0x74($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X74);
    // 0x8017D2BC: swc1        $f4, 0x74($t7)
    MEM_W(0X74, ctx->r15) = ctx->f4.u32l;
    // 0x8017D2C0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017D2C4: jal         0x8017D190
    // 0x8017D2C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    itPakkunWaitInitVars(rdram, ctx);
        goto after_0;
    // 0x8017D2C8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8017D2CC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8017D2D0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017D2D4: sb          $zero, 0x35C($v0)
    MEM_B(0X35C, ctx->r2) = 0;
    // 0x8017D2D8: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
L_8017D2DC:
    // 0x8017D2DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017D2E0: lwc1        $f6, -0x31FC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X31FC);
    // 0x8017D2E4: lwc1        $f8, 0x74($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X74);
    // 0x8017D2E8: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x8017D2EC: nop

    // 0x8017D2F0: bc1fl       L_8017D30C
    if (!c1cs) {
        // 0x8017D2F4: lwc1        $f10, 0x20($v1)
        ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
            goto L_8017D30C;
    }
    goto skip_1;
    // 0x8017D2F4: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
    skip_1:
    // 0x8017D2F8: jal         0x8017D190
    // 0x8017D2FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    itPakkunWaitInitVars(rdram, ctx);
        goto after_1;
    // 0x8017D2FC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8017D300: b           L_8017D318
    // 0x8017D304: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
        goto L_8017D318;
    // 0x8017D304: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017D308: lwc1        $f10, 0x20($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X20);
L_8017D30C:
    // 0x8017D30C: lwc1        $f16, 0x354($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X354);
    // 0x8017D310: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8017D314: swc1        $f18, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f18.u32l;
L_8017D318:
    // 0x8017D318: jal         0x8017D1DC
    // 0x8017D31C: nop

    itPakkunAppearUpdateDamageColl(rdram, ctx);
        goto after_2;
    // 0x8017D31C: nop

    after_2:
    // 0x8017D320: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017D324: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017D328: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017D32C: jr          $ra
    // 0x8017D330: nop

    return;
    // 0x8017D330: nop

;}
RECOMP_FUNC void mnVSItemSwitchInitToggles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132368: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8013236C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80132370: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132374: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80132378: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8013237C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80132380: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80132384: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80132388: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8013238C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80132390: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80132394: jal         0x80132224
    // 0x80132398: lw          $a0, 0x3420($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3420);
    mnVSItemSwitchMakeAppearance(rdram, ctx);
        goto after_0;
    // 0x80132398: lw          $a0, 0x3420($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X3420);
    after_0:
    // 0x8013239C: lui         $at, 0x4374
    ctx->r1 = S32(0X4374 << 16);
    // 0x801323A0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x801323A4: lui         $s6, 0x800D
    ctx->r22 = S32(0X800D << 16);
    // 0x801323A8: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x801323AC: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x801323B0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801323B4: addiu       $s5, $s5, 0x3460
    ctx->r21 = ADD32(ctx->r21, 0X3460);
    // 0x801323B8: addiu       $s1, $s1, 0x3424
    ctx->r17 = ADD32(ctx->r17, 0X3424);
    // 0x801323BC: addiu       $s6, $s6, -0x3100
    ctx->r22 = ADD32(ctx->r22, -0X3100);
    // 0x801323C0: addiu       $s2, $s2, 0x33E4
    ctx->r18 = ADD32(ctx->r18, 0X33E4);
    // 0x801323C4: addiu       $s3, $zero, 0x40
    ctx->r19 = ADD32(0, 0X40);
    // 0x801323C8: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
L_801323CC:
    // 0x801323CC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801323D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801323D4: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801323D8: jal         0x80009968
    // 0x801323DC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x801323DC: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_1:
    // 0x801323E0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801323E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801323E8: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x801323EC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801323F0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801323F4: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x801323F8: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801323FC: jal         0x80009DF4
    // 0x80132400: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80132400: or          $a3, $s4, $zero
    ctx->r7 = ctx->r20 | 0;
    after_2:
    // 0x80132404: mtc1        $s3, $f4
    ctx->f4.u32l = ctx->r19;
    // 0x80132408: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x8013240C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132410: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132414: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80132418: jal         0x80131B98
    // 0x8013241C: nop

    mnVSItemSwitchMakeToggle(rdram, ctx);
        goto after_3;
    // 0x8013241C: nop

    after_3:
    // 0x80132420: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132424: jal         0x80131B24
    // 0x80132428: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    mnVSItemSwitchSetToggleSpriteColors(rdram, ctx);
        goto after_4;
    // 0x80132428: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    after_4:
    // 0x8013242C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80132430: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80132434: bne         $s1, $s5, L_801323CC
    if (ctx->r17 != ctx->r21) {
        // 0x80132438: addiu       $s3, $s3, 0xA
        ctx->r19 = ADD32(ctx->r19, 0XA);
            goto L_801323CC;
    }
    // 0x80132438: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    // 0x8013243C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80132440: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80132444: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80132448: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8013244C: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80132450: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80132454: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80132458: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8013245C: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80132460: jr          $ra
    // 0x80132464: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80132464: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void mnVSOptionsFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x46E0
    ctx->r24 = ADD32(ctx->r24, 0X46E0);
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
RECOMP_FUNC void mnPlayers1PTrainingCheckReady(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137274: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80137278: lw          $t6, -0x776C($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X776C);
    // 0x8013727C: addiu       $v1, $zero, 0xB8
    ctx->r3 = ADD32(0, 0XB8);
    // 0x80137280: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80137284: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80137288: addiu       $v0, $v0, -0x7AA8
    ctx->r2 = ADD32(ctx->r2, -0X7AA8);
    // 0x8013728C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80137290: mflo        $t7
    ctx->r15 = lo;
    // 0x80137294: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80137298: lw          $t9, 0x84($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X84);
    // 0x8013729C: beql        $t9, $zero, L_801372CC
    if (ctx->r25 == 0) {
        // 0x801372A0: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801372CC;
    }
    goto skip_0;
    // 0x801372A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x801372A4: lw          $t0, -0x7768($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X7768);
    // 0x801372A8: multu       $t0, $v1
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801372AC: mflo        $t1
    ctx->r9 = lo;
    // 0x801372B0: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x801372B4: lw          $t3, 0x84($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X84);
    // 0x801372B8: beql        $t3, $zero, L_801372CC
    if (ctx->r11 == 0) {
        // 0x801372BC: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_801372CC;
    }
    goto skip_1;
    // 0x801372BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x801372C0: jr          $ra
    // 0x801372C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801372C4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801372C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801372CC:
    // 0x801372CC: jr          $ra
    // 0x801372D0: nop

    return;
    // 0x801372D0: nop

;}
RECOMP_FUNC void ftBossWalkLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80159994: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80159998: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015999C: jal         0x800DDDA8
    // 0x801599A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x801599A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x801599A4: bnel        $v0, $zero, L_801599B8
    if (ctx->r2 != 0) {
        // 0x801599A8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801599B8;
    }
    goto skip_0;
    // 0x801599A8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801599AC: jal         0x80159A54
    // 0x801599B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftBossWalkWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x801599B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x801599B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801599B8:
    // 0x801599B8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801599BC: jr          $ra
    // 0x801599C0: nop

    return;
    // 0x801599C0: nop

;}
RECOMP_FUNC void ftCommonAttack100LoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014F3C0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8014F3C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014F3C8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014F3CC: lw          $t6, 0x8($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X8);
    // 0x8014F3D0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8014F3D4: sltiu       $at, $t7, 0x18
    ctx->r1 = ctx->r15 < 0X18 ? 1 : 0;
    // 0x8014F3D8: beq         $at, $zero, L_8014F42C
    if (ctx->r1 == 0) {
        // 0x8014F3DC: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8014F42C;
    }
    // 0x8014F3DC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8014F3E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8014F3E4: addu        $at, $at, $t7
    gpr jr_addend_8014F3EC = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8014F3E8: lw          $t7, -0x3C80($at)
    ctx->r15 = ADD32(ctx->r1, -0X3C80);
    // 0x8014F3EC: jr          $t7
    // 0x8014F3F0: nop

    switch (jr_addend_8014F3EC >> 2) {
        case 0: goto L_8014F3F4; break;
        case 1: goto L_8014F42C; break;
        case 2: goto L_8014F42C; break;
        case 3: goto L_8014F42C; break;
        case 4: goto L_8014F400; break;
        case 5: goto L_8014F42C; break;
        case 6: goto L_8014F424; break;
        case 7: goto L_8014F40C; break;
        case 8: goto L_8014F42C; break;
        case 9: goto L_8014F418; break;
        case 10: goto L_8014F42C; break;
        case 11: goto L_8014F42C; break;
        case 12: goto L_8014F42C; break;
        case 13: goto L_8014F42C; break;
        case 14: goto L_8014F3F4; break;
        case 15: goto L_8014F42C; break;
        case 16: goto L_8014F42C; break;
        case 17: goto L_8014F42C; break;
        case 18: goto L_8014F400; break;
        case 19: goto L_8014F42C; break;
        case 20: goto L_8014F424; break;
        case 21: goto L_8014F40C; break;
        case 22: goto L_8014F42C; break;
        case 23: goto L_8014F418; break;
        default: switch_error(__func__, 0x8014F3EC, 0x8018C380);
    }
    // 0x8014F3F0: nop

L_8014F3F4:
    // 0x8014F3F4: addiu       $t8, $zero, 0xDD
    ctx->r24 = ADD32(0, 0XDD);
    // 0x8014F3F8: b           L_8014F42C
    // 0x8014F3FC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
        goto L_8014F42C;
    // 0x8014F3FC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_8014F400:
    // 0x8014F400: addiu       $t9, $zero, 0xDE
    ctx->r25 = ADD32(0, 0XDE);
    // 0x8014F404: b           L_8014F42C
    // 0x8014F408: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
        goto L_8014F42C;
    // 0x8014F408: sw          $t9, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r25;
L_8014F40C:
    // 0x8014F40C: addiu       $t0, $zero, 0xDD
    ctx->r8 = ADD32(0, 0XDD);
    // 0x8014F410: b           L_8014F42C
    // 0x8014F414: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
        goto L_8014F42C;
    // 0x8014F414: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
L_8014F418:
    // 0x8014F418: addiu       $t1, $zero, 0xDD
    ctx->r9 = ADD32(0, 0XDD);
    // 0x8014F41C: b           L_8014F42C
    // 0x8014F420: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
        goto L_8014F42C;
    // 0x8014F420: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_8014F424:
    // 0x8014F424: addiu       $t2, $zero, 0xDE
    ctx->r10 = ADD32(0, 0XDE);
    // 0x8014F428: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
L_8014F42C:
    // 0x8014F42C: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x8014F430: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8014F434: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8014F438: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8014F43C: jal         0x800E6F24
    // 0x8014F440: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8014F440: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8014F444: jal         0x8014F1BC
    // 0x8014F448: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftCommonAttack100LoopKirbyUpdateEffect(rdram, ctx);
        goto after_1;
    // 0x8014F448: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x8014F44C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8014F450: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8014F454: jr          $ra
    // 0x8014F458: nop

    return;
    // 0x8014F458: nop

;}
RECOMP_FUNC void ftComputerUpdateInputs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80131C6C: addiu       $t0, $a0, 0x1CC
    ctx->r8 = ADD32(ctx->r4, 0X1CC);
    // 0x80131C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80131C74: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    // 0x80131C78: lbu         $t6, 0x1D3($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1D3);
    // 0x80131C7C: beql        $t6, $zero, L_80132558
    if (ctx->r14 == 0) {
        // 0x80131C80: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132558;
    }
    goto skip_0;
    // 0x80131C80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80131C84: lbu         $t7, 0x7($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X7);
    // 0x80131C88: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80131C8C: andi        $v0, $t8, 0xFF
    ctx->r2 = ctx->r24 & 0XFF;
    // 0x80131C90: bne         $v0, $zero, L_80132554
    if (ctx->r2 != 0) {
        // 0x80131C94: sb          $t8, 0x7($t0)
        MEM_B(0X7, ctx->r8) = ctx->r24;
            goto L_80132554;
    }
    // 0x80131C94: sb          $t8, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r24;
    // 0x80131C98: bne         $v0, $zero, L_80132550
    if (ctx->r2 != 0) {
        // 0x80131C9C: lw          $a2, 0x8($t0)
        ctx->r6 = MEM_W(ctx->r8, 0X8);
            goto L_80132550;
    }
    // 0x80131C9C: lw          $a2, 0x8($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X8);
    // 0x80131CA0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80131CA4: addiu       $ra, $zero, 0x50
    ctx->r31 = ADD32(0, 0X50);
    // 0x80131CA8: addiu       $t5, $zero, -0x28
    ctx->r13 = ADD32(0, -0X28);
    // 0x80131CAC: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x80131CB0: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80131CB4: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x80131CB8: lb          $t1, 0x3E($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X3E);
    // 0x80131CBC: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
L_80131CC0:
    // 0x80131CC0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131CC4: slti        $at, $v1, 0xF0
    ctx->r1 = SIGNED(ctx->r3) < 0XF0 ? 1 : 0;
    // 0x80131CC8: beq         $at, $zero, L_801324AC
    if (ctx->r1 == 0) {
        // 0x80131CCC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801324AC;
    }
    // 0x80131CCC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80131CD0: andi        $t6, $v1, 0xF0
    ctx->r14 = ctx->r3 & 0XF0;
    // 0x80131CD4: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x80131CD8: sltiu       $at, $t6, 0xE1
    ctx->r1 = ctx->r14 < 0XE1 ? 1 : 0;
    // 0x80131CDC: beq         $at, $zero, L_8013253C
    if (ctx->r1 == 0) {
        // 0x80131CE0: sb          $t9, 0x7($t0)
        MEM_B(0X7, ctx->r8) = ctx->r25;
            goto L_8013253C;
    }
    // 0x80131CE0: sb          $t9, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r25;
    // 0x80131CE4: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80131CE8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80131CEC: addu        $at, $at, $t6
    gpr jr_addend_80131CF4 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80131CF0: lw          $t6, -0x4840($at)
    ctx->r14 = ADD32(ctx->r1, -0X4840);
    // 0x80131CF4: jr          $t6
    // 0x80131CF8: nop

    switch (jr_addend_80131CF4 >> 2) {
        case 0: goto L_80131CFC; break;
        case 1: goto L_8013253C; break;
        case 2: goto L_8013253C; break;
        case 3: goto L_8013253C; break;
        case 4: goto L_8013253C; break;
        case 5: goto L_8013253C; break;
        case 6: goto L_8013253C; break;
        case 7: goto L_8013253C; break;
        case 8: goto L_8013253C; break;
        case 9: goto L_8013253C; break;
        case 10: goto L_8013253C; break;
        case 11: goto L_8013253C; break;
        case 12: goto L_8013253C; break;
        case 13: goto L_8013253C; break;
        case 14: goto L_8013253C; break;
        case 15: goto L_8013253C; break;
        case 16: goto L_80131D0C; break;
        case 17: goto L_8013253C; break;
        case 18: goto L_8013253C; break;
        case 19: goto L_8013253C; break;
        case 20: goto L_8013253C; break;
        case 21: goto L_8013253C; break;
        case 22: goto L_8013253C; break;
        case 23: goto L_8013253C; break;
        case 24: goto L_8013253C; break;
        case 25: goto L_8013253C; break;
        case 26: goto L_8013253C; break;
        case 27: goto L_8013253C; break;
        case 28: goto L_8013253C; break;
        case 29: goto L_8013253C; break;
        case 30: goto L_8013253C; break;
        case 31: goto L_8013253C; break;
        case 32: goto L_80131D24; break;
        case 33: goto L_8013253C; break;
        case 34: goto L_8013253C; break;
        case 35: goto L_8013253C; break;
        case 36: goto L_8013253C; break;
        case 37: goto L_8013253C; break;
        case 38: goto L_8013253C; break;
        case 39: goto L_8013253C; break;
        case 40: goto L_8013253C; break;
        case 41: goto L_8013253C; break;
        case 42: goto L_8013253C; break;
        case 43: goto L_8013253C; break;
        case 44: goto L_8013253C; break;
        case 45: goto L_8013253C; break;
        case 46: goto L_8013253C; break;
        case 47: goto L_8013253C; break;
        case 48: goto L_80131D34; break;
        case 49: goto L_8013253C; break;
        case 50: goto L_8013253C; break;
        case 51: goto L_8013253C; break;
        case 52: goto L_8013253C; break;
        case 53: goto L_8013253C; break;
        case 54: goto L_8013253C; break;
        case 55: goto L_8013253C; break;
        case 56: goto L_8013253C; break;
        case 57: goto L_8013253C; break;
        case 58: goto L_8013253C; break;
        case 59: goto L_8013253C; break;
        case 60: goto L_8013253C; break;
        case 61: goto L_8013253C; break;
        case 62: goto L_8013253C; break;
        case 63: goto L_8013253C; break;
        case 64: goto L_80131D44; break;
        case 65: goto L_8013253C; break;
        case 66: goto L_8013253C; break;
        case 67: goto L_8013253C; break;
        case 68: goto L_8013253C; break;
        case 69: goto L_8013253C; break;
        case 70: goto L_8013253C; break;
        case 71: goto L_8013253C; break;
        case 72: goto L_8013253C; break;
        case 73: goto L_8013253C; break;
        case 74: goto L_8013253C; break;
        case 75: goto L_8013253C; break;
        case 76: goto L_8013253C; break;
        case 77: goto L_8013253C; break;
        case 78: goto L_8013253C; break;
        case 79: goto L_8013253C; break;
        case 80: goto L_80131D54; break;
        case 81: goto L_8013253C; break;
        case 82: goto L_8013253C; break;
        case 83: goto L_8013253C; break;
        case 84: goto L_8013253C; break;
        case 85: goto L_8013253C; break;
        case 86: goto L_8013253C; break;
        case 87: goto L_8013253C; break;
        case 88: goto L_8013253C; break;
        case 89: goto L_8013253C; break;
        case 90: goto L_8013253C; break;
        case 91: goto L_8013253C; break;
        case 92: goto L_8013253C; break;
        case 93: goto L_8013253C; break;
        case 94: goto L_8013253C; break;
        case 95: goto L_8013253C; break;
        case 96: goto L_80131D64; break;
        case 97: goto L_8013253C; break;
        case 98: goto L_8013253C; break;
        case 99: goto L_8013253C; break;
        case 100: goto L_8013253C; break;
        case 101: goto L_8013253C; break;
        case 102: goto L_8013253C; break;
        case 103: goto L_8013253C; break;
        case 104: goto L_8013253C; break;
        case 105: goto L_8013253C; break;
        case 106: goto L_8013253C; break;
        case 107: goto L_8013253C; break;
        case 108: goto L_8013253C; break;
        case 109: goto L_8013253C; break;
        case 110: goto L_8013253C; break;
        case 111: goto L_8013253C; break;
        case 112: goto L_80131D74; break;
        case 113: goto L_8013253C; break;
        case 114: goto L_8013253C; break;
        case 115: goto L_8013253C; break;
        case 116: goto L_8013253C; break;
        case 117: goto L_8013253C; break;
        case 118: goto L_8013253C; break;
        case 119: goto L_8013253C; break;
        case 120: goto L_8013253C; break;
        case 121: goto L_8013253C; break;
        case 122: goto L_8013253C; break;
        case 123: goto L_8013253C; break;
        case 124: goto L_8013253C; break;
        case 125: goto L_8013253C; break;
        case 126: goto L_8013253C; break;
        case 127: goto L_8013253C; break;
        case 128: goto L_80131D84; break;
        case 129: goto L_8013253C; break;
        case 130: goto L_8013253C; break;
        case 131: goto L_8013253C; break;
        case 132: goto L_8013253C; break;
        case 133: goto L_8013253C; break;
        case 134: goto L_8013253C; break;
        case 135: goto L_8013253C; break;
        case 136: goto L_8013253C; break;
        case 137: goto L_8013253C; break;
        case 138: goto L_8013253C; break;
        case 139: goto L_8013253C; break;
        case 140: goto L_8013253C; break;
        case 141: goto L_8013253C; break;
        case 142: goto L_8013253C; break;
        case 143: goto L_8013253C; break;
        case 144: goto L_80131D94; break;
        case 145: goto L_8013253C; break;
        case 146: goto L_8013253C; break;
        case 147: goto L_8013253C; break;
        case 148: goto L_8013253C; break;
        case 149: goto L_8013253C; break;
        case 150: goto L_8013253C; break;
        case 151: goto L_8013253C; break;
        case 152: goto L_8013253C; break;
        case 153: goto L_8013253C; break;
        case 154: goto L_8013253C; break;
        case 155: goto L_8013253C; break;
        case 156: goto L_8013253C; break;
        case 157: goto L_8013253C; break;
        case 158: goto L_8013253C; break;
        case 159: goto L_8013253C; break;
        case 160: goto L_80131DA4; break;
        case 161: goto L_8013253C; break;
        case 162: goto L_8013253C; break;
        case 163: goto L_8013253C; break;
        case 164: goto L_8013253C; break;
        case 165: goto L_8013253C; break;
        case 166: goto L_8013253C; break;
        case 167: goto L_8013253C; break;
        case 168: goto L_8013253C; break;
        case 169: goto L_8013253C; break;
        case 170: goto L_8013253C; break;
        case 171: goto L_8013253C; break;
        case 172: goto L_8013253C; break;
        case 173: goto L_8013253C; break;
        case 174: goto L_8013253C; break;
        case 175: goto L_8013253C; break;
        case 176: goto L_80131E30; break;
        case 177: goto L_8013253C; break;
        case 178: goto L_8013253C; break;
        case 179: goto L_8013253C; break;
        case 180: goto L_8013253C; break;
        case 181: goto L_8013253C; break;
        case 182: goto L_8013253C; break;
        case 183: goto L_8013253C; break;
        case 184: goto L_8013253C; break;
        case 185: goto L_8013253C; break;
        case 186: goto L_8013253C; break;
        case 187: goto L_8013253C; break;
        case 188: goto L_8013253C; break;
        case 189: goto L_8013253C; break;
        case 190: goto L_8013253C; break;
        case 191: goto L_8013253C; break;
        case 192: goto L_80131EBC; break;
        case 193: goto L_8013253C; break;
        case 194: goto L_8013253C; break;
        case 195: goto L_8013253C; break;
        case 196: goto L_8013253C; break;
        case 197: goto L_8013253C; break;
        case 198: goto L_8013253C; break;
        case 199: goto L_8013253C; break;
        case 200: goto L_8013253C; break;
        case 201: goto L_8013253C; break;
        case 202: goto L_8013253C; break;
        case 203: goto L_8013253C; break;
        case 204: goto L_8013253C; break;
        case 205: goto L_8013253C; break;
        case 206: goto L_8013253C; break;
        case 207: goto L_8013253C; break;
        case 208: goto L_8013249C; break;
        case 209: goto L_8013253C; break;
        case 210: goto L_8013253C; break;
        case 211: goto L_8013253C; break;
        case 212: goto L_8013253C; break;
        case 213: goto L_8013253C; break;
        case 214: goto L_8013253C; break;
        case 215: goto L_8013253C; break;
        case 216: goto L_8013253C; break;
        case 217: goto L_8013253C; break;
        case 218: goto L_8013253C; break;
        case 219: goto L_8013253C; break;
        case 220: goto L_8013253C; break;
        case 221: goto L_8013253C; break;
        case 222: goto L_8013253C; break;
        case 223: goto L_8013253C; break;
        case 224: goto L_801324A4; break;
        default: switch_error(__func__, 0x80131CF4, 0x8018B7C0);
    }
    // 0x80131CF8: nop

L_80131CFC:
    // 0x80131CFC: lhu         $t7, 0x1C6($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1C6);
    // 0x80131D00: ori         $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 | 0X8000;
    // 0x80131D04: b           L_8013253C
    // 0x80131D08: sh          $t8, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r24;
        goto L_8013253C;
    // 0x80131D08: sh          $t8, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r24;
L_80131D0C:
    // 0x80131D0C: lhu         $t9, 0x1C6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X1C6);
    // 0x80131D10: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80131D14: ori         $at, $at, 0x7FFF
    ctx->r1 = ctx->r1 | 0X7FFF;
    // 0x80131D18: and         $t6, $t9, $at
    ctx->r14 = ctx->r25 & ctx->r1;
    // 0x80131D1C: b           L_8013253C
    // 0x80131D20: sh          $t6, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r14;
        goto L_8013253C;
    // 0x80131D20: sh          $t6, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r14;
L_80131D24:
    // 0x80131D24: lhu         $t7, 0x1C6($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1C6);
    // 0x80131D28: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x80131D2C: b           L_8013253C
    // 0x80131D30: sh          $t8, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r24;
        goto L_8013253C;
    // 0x80131D30: sh          $t8, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r24;
L_80131D34:
    // 0x80131D34: lhu         $t9, 0x1C6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X1C6);
    // 0x80131D38: andi        $t6, $t9, 0xBFFF
    ctx->r14 = ctx->r25 & 0XBFFF;
    // 0x80131D3C: b           L_8013253C
    // 0x80131D40: sh          $t6, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r14;
        goto L_8013253C;
    // 0x80131D40: sh          $t6, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r14;
L_80131D44:
    // 0x80131D44: lhu         $t7, 0x1C6($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1C6);
    // 0x80131D48: ori         $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 | 0X2000;
    // 0x80131D4C: b           L_8013253C
    // 0x80131D50: sh          $t8, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r24;
        goto L_8013253C;
    // 0x80131D50: sh          $t8, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r24;
L_80131D54:
    // 0x80131D54: lhu         $t9, 0x1C6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X1C6);
    // 0x80131D58: andi        $t6, $t9, 0xDFFF
    ctx->r14 = ctx->r25 & 0XDFFF;
    // 0x80131D5C: b           L_8013253C
    // 0x80131D60: sh          $t6, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r14;
        goto L_8013253C;
    // 0x80131D60: sh          $t6, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r14;
L_80131D64:
    // 0x80131D64: lhu         $t7, 0x1C6($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1C6);
    // 0x80131D68: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80131D6C: b           L_8013253C
    // 0x80131D70: sh          $t8, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r24;
        goto L_8013253C;
    // 0x80131D70: sh          $t8, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r24;
L_80131D74:
    // 0x80131D74: lhu         $t9, 0x1C6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X1C6);
    // 0x80131D78: andi        $t6, $t9, 0xFFDF
    ctx->r14 = ctx->r25 & 0XFFDF;
    // 0x80131D7C: b           L_8013253C
    // 0x80131D80: sh          $t6, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r14;
        goto L_8013253C;
    // 0x80131D80: sh          $t6, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r14;
L_80131D84:
    // 0x80131D84: lhu         $t7, 0x1C6($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X1C6);
    // 0x80131D88: ori         $t8, $t7, 0x1000
    ctx->r24 = ctx->r15 | 0X1000;
    // 0x80131D8C: b           L_8013253C
    // 0x80131D90: sh          $t8, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r24;
        goto L_8013253C;
    // 0x80131D90: sh          $t8, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r24;
L_80131D94:
    // 0x80131D94: lhu         $t9, 0x1C6($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X1C6);
    // 0x80131D98: andi        $t6, $t9, 0xEFFF
    ctx->r14 = ctx->r25 & 0XEFFF;
    // 0x80131D9C: b           L_8013253C
    // 0x80131DA0: sh          $t6, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r14;
        goto L_8013253C;
    // 0x80131DA0: sh          $t6, 0x1C6($a0)
    MEM_H(0X1C6, ctx->r4) = ctx->r14;
L_80131DA4:
    // 0x80131DA4: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x80131DA8: beql        $v1, $t2, L_80131DC8
    if (ctx->r3 == ctx->r10) {
        // 0x80131DAC: lw          $t7, 0x8E8($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X8E8);
            goto L_80131DC8;
    }
    goto skip_1;
    // 0x80131DAC: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
    skip_1:
    // 0x80131DB0: beql        $v1, $t3, L_80131E00
    if (ctx->r3 == ctx->r11) {
        // 0x80131DB4: lw          $t9, 0x8E8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X8E8);
            goto L_80131E00;
    }
    goto skip_2;
    // 0x80131DB4: lw          $t9, 0x8E8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8E8);
    skip_2:
    // 0x80131DB8: sb          $v1, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r3;
    // 0x80131DBC: b           L_8013253C
    // 0x80131DC0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8013253C;
    // 0x80131DC0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131DC4: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
L_80131DC8:
    // 0x80131DC8: lwc1        $f6, 0x60($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X60);
    // 0x80131DCC: addiu       $t8, $zero, -0x50
    ctx->r24 = ADD32(0, -0X50);
    // 0x80131DD0: lwc1        $f4, 0x1C($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X1C);
    // 0x80131DD4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80131DD8: nop

    // 0x80131DDC: bc1fl       L_80131DF4
    if (!c1cs) {
        // 0x80131DE0: sb          $t8, 0x1C8($a0)
        MEM_B(0X1C8, ctx->r4) = ctx->r24;
            goto L_80131DF4;
    }
    goto skip_3;
    // 0x80131DE0: sb          $t8, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r24;
    skip_3:
    // 0x80131DE4: sb          $ra, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r31;
    // 0x80131DE8: b           L_8013253C
    // 0x80131DEC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8013253C;
    // 0x80131DEC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131DF0: sb          $t8, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r24;
L_80131DF4:
    // 0x80131DF4: b           L_8013253C
    // 0x80131DF8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8013253C;
    // 0x80131DF8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131DFC: lw          $t9, 0x8E8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8E8);
L_80131E00:
    // 0x80131E00: lwc1        $f10, 0x60($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X60);
    // 0x80131E04: lwc1        $f8, 0x1C($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X1C);
    // 0x80131E08: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80131E0C: nop

    // 0x80131E10: bc1fl       L_80131E28
    if (!c1cs) {
        // 0x80131E14: sb          $t5, 0x1C8($a0)
        MEM_B(0X1C8, ctx->r4) = ctx->r13;
            goto L_80131E28;
    }
    goto skip_4;
    // 0x80131E14: sb          $t5, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r13;
    skip_4:
    // 0x80131E18: sb          $t4, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r12;
    // 0x80131E1C: b           L_8013253C
    // 0x80131E20: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8013253C;
    // 0x80131E20: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131E24: sb          $t5, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r13;
L_80131E28:
    // 0x80131E28: b           L_8013253C
    // 0x80131E2C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8013253C;
    // 0x80131E2C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80131E30:
    // 0x80131E30: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    // 0x80131E34: beql        $v1, $t2, L_80131E54
    if (ctx->r3 == ctx->r10) {
        // 0x80131E38: lw          $t6, 0x8E8($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X8E8);
            goto L_80131E54;
    }
    goto skip_5;
    // 0x80131E38: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    skip_5:
    // 0x80131E3C: beql        $v1, $t3, L_80131E8C
    if (ctx->r3 == ctx->r11) {
        // 0x80131E40: lw          $t8, 0x8E8($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X8E8);
            goto L_80131E8C;
    }
    goto skip_6;
    // 0x80131E40: lw          $t8, 0x8E8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8E8);
    skip_6:
    // 0x80131E44: sb          $v1, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r3;
    // 0x80131E48: b           L_8013253C
    // 0x80131E4C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8013253C;
    // 0x80131E4C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131E50: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
L_80131E54:
    // 0x80131E54: lwc1        $f6, 0x64($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X64);
    // 0x80131E58: addiu       $t7, $zero, -0x50
    ctx->r15 = ADD32(0, -0X50);
    // 0x80131E5C: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x80131E60: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80131E64: nop

    // 0x80131E68: bc1fl       L_80131E80
    if (!c1cs) {
        // 0x80131E6C: sb          $t7, 0x1C9($a0)
        MEM_B(0X1C9, ctx->r4) = ctx->r15;
            goto L_80131E80;
    }
    goto skip_7;
    // 0x80131E6C: sb          $t7, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r15;
    skip_7:
    // 0x80131E70: sb          $ra, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r31;
    // 0x80131E74: b           L_8013253C
    // 0x80131E78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8013253C;
    // 0x80131E78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131E7C: sb          $t7, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r15;
L_80131E80:
    // 0x80131E80: b           L_8013253C
    // 0x80131E84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8013253C;
    // 0x80131E84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131E88: lw          $t8, 0x8E8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8E8);
L_80131E8C:
    // 0x80131E8C: lwc1        $f10, 0x64($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X64);
    // 0x80131E90: lwc1        $f8, 0x20($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X20);
    // 0x80131E94: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80131E98: nop

    // 0x80131E9C: bc1fl       L_80131EB4
    if (!c1cs) {
        // 0x80131EA0: sb          $t5, 0x1C9($a0)
        MEM_B(0X1C9, ctx->r4) = ctx->r13;
            goto L_80131EB4;
    }
    goto skip_8;
    // 0x80131EA0: sb          $t5, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r13;
    skip_8:
    // 0x80131EA4: sb          $t4, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r12;
    // 0x80131EA8: b           L_8013253C
    // 0x80131EAC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8013253C;
    // 0x80131EAC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80131EB0: sb          $t5, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r13;
L_80131EB4:
    // 0x80131EB4: b           L_8013253C
    // 0x80131EB8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
        goto L_8013253C;
    // 0x80131EB8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80131EBC:
    // 0x80131EBC: lw          $v0, 0x8E8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X8E8);
    // 0x80131EC0: lwc1        $f4, 0x60($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X60);
    // 0x80131EC4: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80131EC8: lwc1        $f8, 0x20($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80131ECC: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80131ED0: swc1        $f8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f8.u32l;
    // 0x80131ED4: lw          $a3, 0x14C($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X14C);
    // 0x80131ED8: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80131EDC: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80131EE0: lwc1        $f10, 0x64($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X64);
    // 0x80131EE4: bne         $a3, $zero, L_80131F40
    if (ctx->r7 != 0) {
        // 0x80131EE8: sub.s       $f18, $f10, $f4
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
            goto L_80131F40;
    }
    // 0x80131EE8: sub.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80131EEC: lbu         $t9, 0x13($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X13);
    // 0x80131EF0: slti        $at, $t9, 0x5
    ctx->r1 = SIGNED(ctx->r25) < 0X5 ? 1 : 0;
    // 0x80131EF4: beq         $at, $zero, L_80131F40
    if (ctx->r1 == 0) {
        // 0x80131EF8: nop
    
            goto L_80131F40;
    }
    // 0x80131EF8: nop

    // 0x80131EFC: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80131F00: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80131F04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131F08: sll         $v1, $t4, 16
    ctx->r3 = S32(ctx->r12 << 16);
    // 0x80131F0C: bc1fl       L_80131F20
    if (!c1cs) {
        // 0x80131F10: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_80131F20;
    }
    goto skip_9;
    // 0x80131F10: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_9:
    // 0x80131F14: b           L_80131F20
    // 0x80131F18: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
        goto L_80131F20;
    // 0x80131F18: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x80131F1C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80131F20:
    // 0x80131F20: c.lt.s      $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f6.fl < ctx->f2.fl;
    // 0x80131F24: nop

    // 0x80131F28: bc1f        L_80131F38
    if (!c1cs) {
        // 0x80131F2C: nop
    
            goto L_80131F38;
    }
    // 0x80131F2C: nop

    // 0x80131F30: b           L_801320AC
    // 0x80131F34: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_801320AC;
    // 0x80131F34: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80131F38:
    // 0x80131F38: b           L_801320AC
    // 0x80131F3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_801320AC;
    // 0x80131F3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80131F40:
    // 0x80131F40: bne         $a3, $zero, L_8013204C
    if (ctx->r7 != 0) {
        // 0x80131F44: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_8013204C;
    }
    // 0x80131F44: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80131F48: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80131F4C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80131F50: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131F54: sll         $v1, $ra, 16
    ctx->r3 = S32(ctx->r31 << 16);
    // 0x80131F58: bc1fl       L_80131F6C
    if (!c1cs) {
        // 0x80131F5C: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_80131F6C;
    }
    goto skip_10;
    // 0x80131F5C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_10:
    // 0x80131F60: b           L_80131F6C
    // 0x80131F64: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
        goto L_80131F6C;
    // 0x80131F64: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x80131F68: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80131F6C:
    // 0x80131F6C: lwc1        $f12, 0x8C($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X8C);
    // 0x80131F70: mul.s       $f10, $f12, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x80131F74: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80131F78: nop

    // 0x80131F7C: bc1fl       L_80131F90
    if (!c1cs) {
        // 0x80131F80: c.lt.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
            goto L_80131F90;
    }
    goto skip_11;
    // 0x80131F80: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    skip_11:
    // 0x80131F84: b           L_801320AC
    // 0x80131F88: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_801320AC;
    // 0x80131F88: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80131F8C: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
L_80131F90:
    // 0x80131F90: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80131F94: bc1fl       L_80131FA8
    if (!c1cs) {
        // 0x80131F98: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_80131FA8;
    }
    goto skip_12;
    // 0x80131F98: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_12:
    // 0x80131F9C: b           L_80131FA8
    // 0x80131FA0: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
        goto L_80131FA8;
    // 0x80131FA0: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x80131FA4: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80131FA8:
    // 0x80131FA8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80131FAC: nop

    // 0x80131FB0: bc1fl       L_80132010
    if (!c1cs) {
        // 0x80131FB4: c.lt.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
            goto L_80132010;
    }
    goto skip_13;
    // 0x80131FB4: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    skip_13:
    // 0x80131FB8: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80131FBC: nop

    // 0x80131FC0: bc1fl       L_80131FD4
    if (!c1cs) {
        // 0x80131FC4: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_80131FD4;
    }
    goto skip_14;
    // 0x80131FC4: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_14:
    // 0x80131FC8: b           L_80131FD4
    // 0x80131FCC: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
        goto L_80131FD4;
    // 0x80131FCC: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x80131FD0: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_80131FD4:
    // 0x80131FD4: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80131FD8: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80131FDC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80131FE0: div.s       $f0, $f4, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80131FE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131FE8: add.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x80131FEC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80131FF0: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80131FF4: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80131FF8: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80131FFC: nop

    // 0x80132000: sll         $v1, $v1, 16
    ctx->r3 = S32(ctx->r3 << 16);
    // 0x80132004: b           L_801320AC
    // 0x80132008: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_801320AC;
    // 0x80132008: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x8013200C: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
L_80132010:
    // 0x80132010: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80132014: sll         $v1, $t4, 16
    ctx->r3 = S32(ctx->r12 << 16);
    // 0x80132018: bc1fl       L_8013202C
    if (!c1cs) {
        // 0x8013201C: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_8013202C;
    }
    goto skip_15;
    // 0x8013201C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_15:
    // 0x80132020: b           L_8013202C
    // 0x80132024: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
        goto L_8013202C;
    // 0x80132024: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x80132028: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_8013202C:
    // 0x8013202C: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x80132030: nop

    // 0x80132034: bc1f        L_80132044
    if (!c1cs) {
        // 0x80132038: nop
    
            goto L_80132044;
    }
    // 0x80132038: nop

    // 0x8013203C: b           L_801320AC
    // 0x80132040: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_801320AC;
    // 0x80132040: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
L_80132044:
    // 0x80132044: b           L_801320AC
    // 0x80132048: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_801320AC;
    // 0x80132048: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8013204C:
    // 0x8013204C: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80132050: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132054: sll         $v1, $ra, 16
    ctx->r3 = S32(ctx->r31 << 16);
    // 0x80132058: bc1fl       L_8013206C
    if (!c1cs) {
        // 0x8013205C: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_8013206C;
    }
    goto skip_16;
    // 0x8013205C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_16:
    // 0x80132060: b           L_8013206C
    // 0x80132064: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
        goto L_8013206C;
    // 0x80132064: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x80132068: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_8013206C:
    // 0x8013206C: c.lt.s      $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f4.fl < ctx->f2.fl;
    // 0x80132070: nop

    // 0x80132074: bc1t        L_801320A0
    if (c1cs) {
        // 0x80132078: nop
    
            goto L_801320A0;
    }
    // 0x80132078: nop

    // 0x8013207C: lw          $t7, 0x44($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X44);
    // 0x80132080: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80132084: nop

    // 0x80132088: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013208C: mul.s       $f10, $f8, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f14.fl);
    // 0x80132090: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80132094: nop

    // 0x80132098: bc1fl       L_801320AC
    if (!c1cs) {
        // 0x8013209C: addiu       $v1, $zero, 0x14
        ctx->r3 = ADD32(0, 0X14);
            goto L_801320AC;
    }
    goto skip_17;
    // 0x8013209C: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
    skip_17:
L_801320A0:
    // 0x801320A0: b           L_801320AC
    // 0x801320A4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
        goto L_801320AC;
    // 0x801320A4: sra         $v1, $v1, 16
    ctx->r3 = S32(SIGNED(ctx->r3) >> 16);
    // 0x801320A8: addiu       $v1, $zero, 0x14
    ctx->r3 = ADD32(0, 0X14);
L_801320AC:
    // 0x801320AC: bnel        $a3, $zero, L_80132138
    if (ctx->r7 != 0) {
        // 0x801320B0: lw          $t9, 0x8($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X8);
            goto L_80132138;
    }
    goto skip_18;
    // 0x801320B0: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    skip_18:
    // 0x801320B4: lw          $t8, 0x24($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X24);
    // 0x801320B8: addiu       $at, $zero, 0x14
    ctx->r1 = ADD32(0, 0X14);
    // 0x801320BC: beql        $t8, $at, L_80132238
    if (ctx->r24 == ctx->r1) {
        // 0x801320C0: c.eq.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
            goto L_80132238;
    }
    goto skip_19;
    // 0x801320C0: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    skip_19:
    // 0x801320C4: lw          $t9, 0xEC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XEC);
    // 0x801320C8: lw          $t6, 0x5C($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X5C);
    // 0x801320CC: bnel        $t9, $t6, L_801320F0
    if (ctx->r25 != ctx->r14) {
        // 0x801320D0: lw          $t8, 0x48($t0)
        ctx->r24 = MEM_W(ctx->r8, 0X48);
            goto L_801320F0;
    }
    goto skip_20;
    // 0x801320D0: lw          $t8, 0x48($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X48);
    skip_20:
    // 0x801320D4: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801320D8: mov.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = ctx->f16.fl;
    // 0x801320DC: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x801320E0: nop

    // 0x801320E4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801320E8: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x801320EC: lw          $t8, 0x48($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X48);
L_801320F0:
    // 0x801320F0: sll         $t6, $t8, 17
    ctx->r14 = S32(ctx->r24 << 17);
    // 0x801320F4: bgezl       $t6, L_80132238
    if (SIGNED(ctx->r14) >= 0) {
        // 0x801320F8: c.eq.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
            goto L_80132238;
    }
    goto skip_21;
    // 0x801320F8: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    skip_21:
    // 0x801320FC: lw          $t7, 0x6C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X6C);
    // 0x80132100: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x80132104: lw          $v0, 0x24($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X24);
    // 0x80132108: beq         $v0, $at, L_80132118
    if (ctx->r2 == ctx->r1) {
        // 0x8013210C: addiu       $at, $zero, 0x55
        ctx->r1 = ADD32(0, 0X55);
            goto L_80132118;
    }
    // 0x8013210C: addiu       $at, $zero, 0x55
    ctx->r1 = ADD32(0, 0X55);
    // 0x80132110: bnel        $v0, $at, L_80132238
    if (ctx->r2 != ctx->r1) {
        // 0x80132114: c.eq.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
            goto L_80132238;
    }
    goto skip_22;
    // 0x80132114: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    skip_22:
L_80132118:
    // 0x80132118: trunc.w.s   $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8013211C: mov.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = ctx->f16.fl;
    // 0x80132120: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80132124: nop

    // 0x80132128: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8013212C: b           L_80132234
    // 0x80132130: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
        goto L_80132234;
    // 0x80132130: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80132134: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
L_80132138:
    // 0x80132138: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013213C: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80132140: bnel        $t9, $at, L_80132174
    if (ctx->r25 != ctx->r1) {
        // 0x80132144: mtc1        $zero, $f8
        ctx->f8.u32l = 0;
            goto L_80132174;
    }
    goto skip_23;
    // 0x80132144: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    skip_23:
    // 0x80132148: lw          $v0, 0x24($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X24);
    // 0x8013214C: addiu       $at, $zero, 0xE3
    ctx->r1 = ADD32(0, 0XE3);
    // 0x80132150: beq         $v0, $at, L_801321A0
    if (ctx->r2 == ctx->r1) {
        // 0x80132154: addiu       $at, $zero, 0xE4
        ctx->r1 = ADD32(0, 0XE4);
            goto L_801321A0;
    }
    // 0x80132154: addiu       $at, $zero, 0xE4
    ctx->r1 = ADD32(0, 0XE4);
    // 0x80132158: beq         $v0, $at, L_801321A0
    if (ctx->r2 == ctx->r1) {
        // 0x8013215C: addiu       $at, $zero, 0xE5
        ctx->r1 = ADD32(0, 0XE5);
            goto L_801321A0;
    }
    // 0x8013215C: addiu       $at, $zero, 0xE5
    ctx->r1 = ADD32(0, 0XE5);
    // 0x80132160: beq         $v0, $at, L_801321A0
    if (ctx->r2 == ctx->r1) {
        // 0x80132164: addiu       $at, $zero, 0xE6
        ctx->r1 = ADD32(0, 0XE6);
            goto L_801321A0;
    }
    // 0x80132164: addiu       $at, $zero, 0xE6
    ctx->r1 = ADD32(0, 0XE6);
    // 0x80132168: beql        $v0, $at, L_801321A4
    if (ctx->r2 == ctx->r1) {
        // 0x8013216C: lbu         $v0, 0x3($t0)
        ctx->r2 = MEM_BU(ctx->r8, 0X3);
            goto L_801321A4;
    }
    goto skip_24;
    // 0x8013216C: lbu         $v0, 0x3($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X3);
    skip_24:
    // 0x80132170: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
L_80132174:
    // 0x80132174: nop

    // 0x80132178: c.lt.s      $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f18.fl < ctx->f8.fl;
    // 0x8013217C: nop

    // 0x80132180: bc1fl       L_801321A4
    if (!c1cs) {
        // 0x80132184: lbu         $v0, 0x3($t0)
        ctx->r2 = MEM_BU(ctx->r8, 0X3);
            goto L_801321A4;
    }
    goto skip_25;
    // 0x80132184: lbu         $v0, 0x3($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X3);
    skip_25:
    // 0x80132188: trunc.w.s   $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x8013218C: mov.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = ctx->f16.fl;
    // 0x80132190: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80132194: nop

    // 0x80132198: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x8013219C: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_801321A0:
    // 0x801321A0: lbu         $v0, 0x3($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0X3);
L_801321A4:
    // 0x801321A4: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x801321A8: beq         $v0, $at, L_801321CC
    if (ctx->r2 == ctx->r1) {
        // 0x801321AC: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_801321CC;
    }
    // 0x801321AC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x801321B0: beq         $v0, $at, L_80132200
    if (ctx->r2 == ctx->r1) {
        // 0x801321B4: lwc1        $f10, 0x1C($sp)
        ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
            goto L_80132200;
    }
    // 0x801321B4: lwc1        $f10, 0x1C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801321B8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x801321BC: beql        $v0, $at, L_80132204
    if (ctx->r2 == ctx->r1) {
        // 0x801321C0: lui         $at, 0xC396
        ctx->r1 = S32(0XC396 << 16);
            goto L_80132204;
    }
    goto skip_26;
    // 0x801321C0: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
    skip_26:
    // 0x801321C4: b           L_80132238
    // 0x801321C8: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
        goto L_80132238;
    // 0x801321C8: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
L_801321CC:
    // 0x801321CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801321D0: nop

    // 0x801321D4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801321D8: nop

    // 0x801321DC: bc1fl       L_80132238
    if (!c1cs) {
        // 0x801321E0: c.eq.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
            goto L_80132238;
    }
    goto skip_27;
    // 0x801321E0: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    skip_27:
    // 0x801321E4: trunc.w.s   $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x801321E8: mov.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = ctx->f16.fl;
    // 0x801321EC: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x801321F0: nop

    // 0x801321F4: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x801321F8: b           L_80132234
    // 0x801321FC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
        goto L_80132234;
    // 0x801321FC: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_80132200:
    // 0x80132200: lui         $at, 0xC396
    ctx->r1 = S32(0XC396 << 16);
L_80132204:
    // 0x80132204: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132208: nop

    // 0x8013220C: c.lt.s      $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f10.fl < ctx->f4.fl;
    // 0x80132210: nop

    // 0x80132214: bc1fl       L_80132238
    if (!c1cs) {
        // 0x80132218: c.eq.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
            goto L_80132238;
    }
    goto skip_28;
    // 0x80132218: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    skip_28:
    // 0x8013221C: trunc.w.s   $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80132220: mov.s       $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = ctx->f16.fl;
    // 0x80132224: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x80132228: nop

    // 0x8013222C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80132230: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
L_80132234:
    // 0x80132234: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
L_80132238:
    // 0x80132238: nop

    // 0x8013223C: bc1tl       L_80132388
    if (c1cs) {
        // 0x80132240: c.eq.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
            goto L_80132388;
    }
    goto skip_29;
    // 0x80132240: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    skip_29:
    // 0x80132244: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    // 0x80132248: nop

    // 0x8013224C: bc1tl       L_80132388
    if (c1cs) {
        // 0x80132250: c.eq.s      $f14, $f16
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
            goto L_80132388;
    }
    goto skip_30;
    // 0x80132250: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
    skip_30:
    // 0x80132254: c.lt.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl < ctx->f16.fl;
    // 0x80132258: nop

    // 0x8013225C: bc1fl       L_80132270
    if (!c1cs) {
        // 0x80132260: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_80132270;
    }
    goto skip_31;
    // 0x80132260: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    skip_31:
    // 0x80132264: b           L_80132270
    // 0x80132268: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
        goto L_80132270;
    // 0x80132268: neg.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = -ctx->f18.fl;
    // 0x8013226C: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
L_80132270:
    // 0x80132270: c.lt.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl < ctx->f16.fl;
    // 0x80132274: nop

    // 0x80132278: bc1fl       L_8013228C
    if (!c1cs) {
        // 0x8013227C: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_8013228C;
    }
    goto skip_32;
    // 0x8013227C: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    skip_32:
    // 0x80132280: b           L_8013228C
    // 0x80132284: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
        goto L_8013228C;
    // 0x80132284: neg.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = -ctx->f14.fl;
    // 0x80132288: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_8013228C:
    // 0x8013228C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80132290: nop

    // 0x80132294: bc1fl       L_80132318
    if (!c1cs) {
        // 0x80132298: div.s       $f0, $f14, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f18.fl);
            goto L_80132318;
    }
    goto skip_33;
    // 0x80132298: div.s       $f0, $f14, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f18.fl);
    skip_33:
    // 0x8013229C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x801322A0: negu        $t9, $v1
    ctx->r25 = SUB32(0, ctx->r3);
    // 0x801322A4: div.s       $f0, $f18, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f14.fl);
    // 0x801322A8: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
    // 0x801322AC: bc1fl       L_801322C0
    if (!c1cs) {
        // 0x801322B0: sb          $t9, 0x1C8($a0)
        MEM_B(0X1C8, ctx->r4) = ctx->r25;
            goto L_801322C0;
    }
    goto skip_34;
    // 0x801322B0: sb          $t9, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r25;
    skip_34:
    // 0x801322B4: b           L_801322C0
    // 0x801322B8: sb          $v1, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r3;
        goto L_801322C0;
    // 0x801322B8: sb          $v1, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r3;
    // 0x801322BC: sb          $t9, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r25;
L_801322C0:
    // 0x801322C0: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801322C4: nop

    // 0x801322C8: bc1fl       L_801322DC
    if (!c1cs) {
        // 0x801322CC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_801322DC;
    }
    goto skip_35;
    // 0x801322CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_35:
    // 0x801322D0: b           L_801322DC
    // 0x801322D4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_801322DC;
    // 0x801322D4: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x801322D8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801322DC:
    // 0x801322DC: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x801322E0: nop

    // 0x801322E4: bc1f        L_801322F4
    if (!c1cs) {
        // 0x801322E8: nop
    
            goto L_801322F4;
    }
    // 0x801322E8: nop

    // 0x801322EC: b           L_801322F4
    // 0x801322F0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_801322F4;
    // 0x801322F0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_801322F4:
    // 0x801322F4: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801322F8: nop

    // 0x801322FC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132300: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80132304: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80132308: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8013230C: b           L_8013253C
    // 0x80132310: sb          $t7, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r15;
        goto L_8013253C;
    // 0x80132310: sb          $t7, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r15;
    // 0x80132314: div.s       $f0, $f14, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f18.fl);
L_80132318:
    // 0x80132318: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x8013231C: negu        $t6, $a1
    ctx->r14 = SUB32(0, ctx->r5);
    // 0x80132320: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80132324: nop

    // 0x80132328: bc1fl       L_8013233C
    if (!c1cs) {
        // 0x8013232C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8013233C;
    }
    goto skip_36;
    // 0x8013232C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_36:
    // 0x80132330: b           L_8013233C
    // 0x80132334: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_8013233C;
    // 0x80132334: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80132338: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_8013233C:
    // 0x8013233C: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x80132340: nop

    // 0x80132344: bc1f        L_80132354
    if (!c1cs) {
        // 0x80132348: nop
    
            goto L_80132354;
    }
    // 0x80132348: nop

    // 0x8013234C: b           L_80132354
    // 0x80132350: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_80132354;
    // 0x80132350: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80132354:
    // 0x80132354: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80132358: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x8013235C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132360: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80132364: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80132368: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8013236C: bc1f        L_8013237C
    if (!c1cs) {
        // 0x80132370: sb          $t9, 0x1C8($a0)
        MEM_B(0X1C8, ctx->r4) = ctx->r25;
            goto L_8013237C;
    }
    // 0x80132370: sb          $t9, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r25;
    // 0x80132374: b           L_8013253C
    // 0x80132378: sb          $a1, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r5;
        goto L_8013253C;
    // 0x80132378: sb          $a1, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r5;
L_8013237C:
    // 0x8013237C: b           L_8013253C
    // 0x80132380: sb          $t6, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r14;
        goto L_8013253C;
    // 0x80132380: sb          $t6, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r14;
    // 0x80132384: c.eq.s      $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f14.fl == ctx->f16.fl;
L_80132388:
    // 0x80132388: nop

    // 0x8013238C: bc1tl       L_80132410
    if (c1cs) {
        // 0x80132390: c.eq.s      $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
            goto L_80132410;
    }
    goto skip_37;
    // 0x80132390: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
    skip_37:
    // 0x80132394: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x80132398: negu        $t7, $v1
    ctx->r15 = SUB32(0, ctx->r3);
    // 0x8013239C: div.s       $f0, $f18, $f14
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f14.fl);
    // 0x801323A0: negu        $v0, $a1
    ctx->r2 = SUB32(0, ctx->r5);
    // 0x801323A4: bc1fl       L_801323B8
    if (!c1cs) {
        // 0x801323A8: sb          $t7, 0x1C8($a0)
        MEM_B(0X1C8, ctx->r4) = ctx->r15;
            goto L_801323B8;
    }
    goto skip_38;
    // 0x801323A8: sb          $t7, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r15;
    skip_38:
    // 0x801323AC: b           L_801323B8
    // 0x801323B0: sb          $v1, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r3;
        goto L_801323B8;
    // 0x801323B0: sb          $v1, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r3;
    // 0x801323B4: sb          $t7, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r15;
L_801323B8:
    // 0x801323B8: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x801323BC: nop

    // 0x801323C0: bc1fl       L_801323D4
    if (!c1cs) {
        // 0x801323C4: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_801323D4;
    }
    goto skip_39;
    // 0x801323C4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_39:
    // 0x801323C8: b           L_801323D4
    // 0x801323CC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_801323D4;
    // 0x801323CC: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x801323D0: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_801323D4:
    // 0x801323D4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x801323D8: nop

    // 0x801323DC: bc1f        L_801323EC
    if (!c1cs) {
        // 0x801323E0: nop
    
            goto L_801323EC;
    }
    // 0x801323E0: nop

    // 0x801323E4: b           L_801323EC
    // 0x801323E8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
        goto L_801323EC;
    // 0x801323E8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_801323EC:
    // 0x801323EC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x801323F0: nop

    // 0x801323F4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801323F8: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x801323FC: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80132400: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80132404: b           L_8013253C
    // 0x80132408: sb          $t9, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r25;
        goto L_8013253C;
    // 0x80132408: sb          $t9, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r25;
    // 0x8013240C: c.eq.s      $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f18.fl == ctx->f16.fl;
L_80132410:
    // 0x80132410: nop

    // 0x80132414: bc1tl       L_80132490
    if (c1cs) {
        // 0x80132418: sb          $zero, 0x1C9($a0)
        MEM_B(0X1C9, ctx->r4) = 0;
            goto L_80132490;
    }
    goto skip_40;
    // 0x80132418: sb          $zero, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = 0;
    skip_40:
    // 0x8013241C: div.s       $f0, $f14, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f14.fl, ctx->f18.fl);
    // 0x80132420: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80132424: negu        $t8, $a1
    ctx->r24 = SUB32(0, ctx->r5);
    // 0x80132428: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8013242C: nop

    // 0x80132430: bc1fl       L_80132444
    if (!c1cs) {
        // 0x80132434: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80132444;
    }
    goto skip_41;
    // 0x80132434: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_41:
    // 0x80132438: b           L_80132444
    // 0x8013243C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80132444;
    // 0x8013243C: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80132440: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80132444:
    // 0x80132444: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x80132448: nop

    // 0x8013244C: bc1f        L_8013245C
    if (!c1cs) {
        // 0x80132450: nop
    
            goto L_8013245C;
    }
    // 0x80132450: nop

    // 0x80132454: b           L_8013245C
    // 0x80132458: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8013245C;
    // 0x80132458: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8013245C:
    // 0x8013245C: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80132460: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x80132464: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80132468: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8013246C: trunc.w.s   $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80132470: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80132474: bc1f        L_80132484
    if (!c1cs) {
        // 0x80132478: sb          $t7, 0x1C8($a0)
        MEM_B(0X1C8, ctx->r4) = ctx->r15;
            goto L_80132484;
    }
    // 0x80132478: sb          $t7, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r15;
    // 0x8013247C: b           L_8013253C
    // 0x80132480: sb          $a1, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r5;
        goto L_8013253C;
    // 0x80132480: sb          $a1, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r5;
L_80132484:
    // 0x80132484: b           L_8013253C
    // 0x80132488: sb          $t8, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r24;
        goto L_8013253C;
    // 0x80132488: sb          $t8, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r24;
    // 0x8013248C: sb          $zero, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = 0;
L_80132490:
    // 0x80132490: lb          $t9, 0x1C9($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X1C9);
    // 0x80132494: b           L_8013253C
    // 0x80132498: sb          $t9, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r25;
        goto L_8013253C;
    // 0x80132498: sb          $t9, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r25;
L_8013249C:
    // 0x8013249C: b           L_8013253C
    // 0x801324A0: sb          $t1, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r9;
        goto L_8013253C;
    // 0x801324A0: sb          $t1, 0x1C8($a0)
    MEM_B(0X1C8, ctx->r4) = ctx->r9;
L_801324A4:
    // 0x801324A4: b           L_8013253C
    // 0x801324A8: sb          $t1, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r9;
        goto L_8013253C;
    // 0x801324A8: sb          $t1, 0x1C9($a0)
    MEM_B(0X1C9, ctx->r4) = ctx->r9;
L_801324AC:
    // 0x801324AC: addiu       $t6, $v0, -0xF0
    ctx->r14 = ADD32(ctx->r2, -0XF0);
    // 0x801324B0: sltiu       $at, $t6, 0x10
    ctx->r1 = ctx->r14 < 0X10 ? 1 : 0;
    // 0x801324B4: beq         $at, $zero, L_8013253C
    if (ctx->r1 == 0) {
        // 0x801324B8: sll         $t6, $t6, 2
        ctx->r14 = S32(ctx->r14 << 2);
            goto L_8013253C;
    }
    // 0x801324B8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x801324BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801324C0: addu        $at, $at, $t6
    gpr jr_addend_801324C8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x801324C4: lw          $t6, -0x44BC($at)
    ctx->r14 = ADD32(ctx->r1, -0X44BC);
    // 0x801324C8: jr          $t6
    // 0x801324CC: nop

    switch (jr_addend_801324C8 >> 2) {
        case 0: goto L_801324D0; break;
        case 1: goto L_801324E0; break;
        case 2: goto L_801324E8; break;
        case 3: goto L_801324F0; break;
        case 4: goto L_8013253C; break;
        case 5: goto L_8013253C; break;
        case 6: goto L_8013253C; break;
        case 7: goto L_8013253C; break;
        case 8: goto L_8013253C; break;
        case 9: goto L_8013253C; break;
        case 10: goto L_8013253C; break;
        case 11: goto L_8013253C; break;
        case 12: goto L_8013253C; break;
        case 13: goto L_8013253C; break;
        case 14: goto L_8013253C; break;
        case 15: goto L_80132530; break;
        default: switch_error(__func__, 0x801324C8, 0x8018BB44);
    }
    // 0x801324CC: nop

L_801324D0:
    // 0x801324D0: lbu         $t7, 0x0($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X0);
    // 0x801324D4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x801324D8: b           L_8013253C
    // 0x801324DC: sb          $t7, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r15;
        goto L_8013253C;
    // 0x801324DC: sb          $t7, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r15;
L_801324E0:
    // 0x801324E0: b           L_8013253C
    // 0x801324E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
        goto L_8013253C;
    // 0x801324E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_801324E8:
    // 0x801324E8: b           L_8013253C
    // 0x801324EC: sb          $t1, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r9;
        goto L_8013253C;
    // 0x801324EC: sb          $t1, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r9;
L_801324F0:
    // 0x801324F0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x801324F4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x801324F8: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801324FC: jal         0x80131BA0
    // 0x80132500: sb          $t1, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r9;
    ftComputerSetControlPKThunder(rdram, ctx);
        goto after_0;
    // 0x80132500: sb          $t1, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r9;
    after_0:
    // 0x80132504: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80132508: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x8013250C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80132510: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80132514: lb          $t1, 0x3E($sp)
    ctx->r9 = MEM_B(ctx->r29, 0X3E);
    // 0x80132518: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x8013251C: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80132520: addiu       $t4, $zero, 0x28
    ctx->r12 = ADD32(0, 0X28);
    // 0x80132524: addiu       $t5, $zero, -0x28
    ctx->r13 = ADD32(0, -0X28);
    // 0x80132528: b           L_8013253C
    // 0x8013252C: addiu       $ra, $zero, 0x50
    ctx->r31 = ADD32(0, 0X50);
        goto L_8013253C;
    // 0x8013252C: addiu       $ra, $zero, 0x50
    ctx->r31 = ADD32(0, 0X50);
L_80132530:
    // 0x80132530: sb          $zero, 0x7($t0)
    MEM_B(0X7, ctx->r8) = 0;
    // 0x80132534: b           L_80132554
    // 0x80132538: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
        goto L_80132554;
    // 0x80132538: sw          $zero, 0x8($t0)
    MEM_W(0X8, ctx->r8) = 0;
L_8013253C:
    // 0x8013253C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80132540: lbu         $t9, 0x7($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X7);
    // 0x80132544: beql        $t9, $zero, L_80131CC0
    if (ctx->r25 == 0) {
        // 0x80132548: lbu         $v1, 0x0($a2)
        ctx->r3 = MEM_BU(ctx->r6, 0X0);
            goto L_80131CC0;
    }
    goto skip_42;
    // 0x80132548: lbu         $v1, 0x0($a2)
    ctx->r3 = MEM_BU(ctx->r6, 0X0);
    skip_42:
    // 0x8013254C: sb          $t1, 0x3E($sp)
    MEM_B(0X3E, ctx->r29) = ctx->r9;
L_80132550:
    // 0x80132550: sw          $a2, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r6;
L_80132554:
    // 0x80132554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132558:
    // 0x80132558: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8013255C: jr          $ra
    // 0x80132560: nop

    return;
    // 0x80132560: nop

;}
RECOMP_FUNC void sySchedulerVRetrace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000205C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80002060: addiu       $v0, $v0, 0x501C
    ctx->r2 = ADD32(ctx->r2, 0X501C);
    // 0x80002064: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80002068: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000206C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80002070: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x80002074: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80002078: lui         $s0, 0x8004
    ctx->r16 = S32(0X8004 << 16);
    // 0x8000207C: lw          $s0, 0x4EC0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4EC0);
    // 0x80002080: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002084: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80002088: beq         $s0, $zero, L_800020AC
    if (ctx->r16 == 0) {
        // 0x8000208C: nop
    
            goto L_800020AC;
    }
    // 0x8000208C: nop

    // 0x80002090: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
L_80002094:
    // 0x80002094: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80002098: jal         0x80030000
    // 0x8000209C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osSendMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8000209C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800020A0: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x800020A4: bnel        $s0, $zero, L_80002094
    if (ctx->r16 != 0) {
        // 0x800020A8: lw          $a0, 0x4($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X4);
            goto L_80002094;
    }
    goto skip_0;
    // 0x800020A8: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    skip_0:
L_800020AC:
    // 0x800020AC: jal         0x800016D8
    // 0x800020B0: nop

    sySchedulerSwapBuffer(rdram, ctx);
        goto after_1;
    // 0x800020B0: nop

    after_1:
    // 0x800020B4: jal         0x80001E64
    // 0x800020B8: nop

    sySchedulerExecuteTasksAll(rdram, ctx);
        goto after_2;
    // 0x800020B8: nop

    after_2:
    // 0x800020BC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800020C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800020C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800020C8: jr          $ra
    // 0x800020CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800020CC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void alCents2Ratio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036360: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80036364: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80036368: bltz        $a0, L_8003637C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8003636C: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_8003637C;
    }
    // 0x8003636C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80036370: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80036374: b           L_80036384
    // 0x80036378: lwc1        $f0, -0xC80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC80);
        goto L_80036384;
    // 0x80036378: lwc1        $f0, -0xC80($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC80);
L_8003637C:
    // 0x8003637C: lwc1        $f0, -0xC7C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0XC7C);
    // 0x80036380: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_80036384:
    // 0x80036384: beq         $a0, $zero, L_800363A8
    if (ctx->r4 == 0) {
        // 0x80036388: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_800363A8;
    }
L_80036388:
    // 0x80036388: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x8003638C: beq         $t6, $zero, L_8003639C
    if (ctx->r14 == 0) {
        // 0x80036390: sra         $t7, $a0, 1
        ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
            goto L_8003639C;
    }
    // 0x80036390: sra         $t7, $a0, 1
    ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
    // 0x80036394: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80036398: nop

L_8003639C:
    // 0x8003639C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800363A0: bne         $t7, $zero, L_80036388
    if (ctx->r15 != 0) {
        // 0x800363A4: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_80036388;
    }
    // 0x800363A4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800363A8:
    // 0x800363A8: jr          $ra
    // 0x800363AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800363AC: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void mnPlayers1PGameCenterPuckInPortrait(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137034: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80137038: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013703C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80137040: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80137044: jal         0x801327EC
    // 0x80137048: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayers1PGameGetPortrait(rdram, ctx);
        goto after_0;
    // 0x80137048: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8013704C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80137050: bne         $at, $zero, L_80137098
    if (ctx->r1 != 0) {
        // 0x80137054: lw          $a2, 0x18($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X18);
            goto L_80137098;
    }
    // 0x80137054: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80137058: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8013705C: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80137060: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80137064: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x80137068: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013706C: addu        $t6, $t6, $v0
    ctx->r14 = ADD32(ctx->r14, ctx->r2);
    // 0x80137070: addiu       $t7, $t6, -0xEA
    ctx->r15 = ADD32(ctx->r14, -0XEA);
    // 0x80137074: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80137078: lw          $t8, 0x74($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X74);
    // 0x8013707C: lui         $at, 0x42B2
    ctx->r1 = S32(0X42B2 << 16);
    // 0x80137080: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80137084: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80137088: swc1        $f6, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->f6.u32l;
    // 0x8013708C: lw          $t9, 0x74($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X74);
    // 0x80137090: b           L_801370D4
    // 0x80137094: swc1        $f8, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f8.u32l;
        goto L_801370D4;
    // 0x80137094: swc1        $f8, 0x5C($t9)
    MEM_W(0X5C, ctx->r25) = ctx->f8.u32l;
L_80137098:
    // 0x80137098: sll         $t0, $v0, 2
    ctx->r8 = S32(ctx->r2 << 2);
    // 0x8013709C: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x801370A0: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801370A4: subu        $t0, $t0, $v0
    ctx->r8 = SUB32(ctx->r8, ctx->r2);
    // 0x801370A8: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x801370AC: addu        $t0, $t0, $v0
    ctx->r8 = ADD32(ctx->r8, ctx->r2);
    // 0x801370B0: addiu       $t1, $t0, 0x24
    ctx->r9 = ADD32(ctx->r8, 0X24);
    // 0x801370B4: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x801370B8: lw          $t2, 0x74($a2)
    ctx->r10 = MEM_W(ctx->r6, 0X74);
    // 0x801370BC: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x801370C0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x801370C4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x801370C8: swc1        $f16, 0x58($t2)
    MEM_W(0X58, ctx->r10) = ctx->f16.u32l;
    // 0x801370CC: lw          $t3, 0x74($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X74);
    // 0x801370D0: swc1        $f18, 0x5C($t3)
    MEM_W(0X5C, ctx->r11) = ctx->f18.u32l;
L_801370D4:
    // 0x801370D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801370D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801370DC: jr          $ra
    // 0x801370E0: nop

    return;
    // 0x801370E0: nop

;}
RECOMP_FUNC void syMatrixTraRotRpyDF(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D51C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D520: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8001D524: lwc1        $f0, -0x1C24($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X1C24);
    // 0x8001D528: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8001D52C: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8001D530: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8001D534: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D538: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8001D53C: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x8001D540: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8001D544: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8001D548: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x8001D54C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D550: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x8001D554: mfc1        $a2, $f14
    ctx->r6 = (int32_t)ctx->f14.u32l;
    // 0x8001D558: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x8001D55C: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001D560: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8001D564: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x8001D568: swc1        $f8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f8.u32l;
    // 0x8001D56C: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8001D570: swc1        $f18, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f18.u32l;
    // 0x8001D574: jal         0x8001C1C8
    // 0x8001D578: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    syMatrixTraRotRpyRF(rdram, ctx);
        goto after_0;
    // 0x8001D578: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8001D57C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D580: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D584: jr          $ra
    // 0x8001D588: nop

    return;
    // 0x8001D588: nop

;}
RECOMP_FUNC void mvUnknownMarioFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D1A0: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x8018D1A4: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018D1A8: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D1AC: addiu       $v1, $v1, -0x28A8
    ctx->r3 = ADD32(ctx->r3, -0X28A8);
    // 0x8018D1B0: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D1B4: addiu       $t6, $t6, 0x3FC8
    ctx->r14 = ADD32(ctx->r14, 0X3FC8);
    // 0x8018D1B8: addiu       $v0, $v0, 0x50E8
    ctx->r2 = ADD32(ctx->r2, 0X50E8);
    // 0x8018D1BC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8018D1C0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8018D1C4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8018D1C8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8018D1CC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8018D1D0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8018D1D4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8018D1D8: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8018D1DC: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8018D1E0: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8018D1E4: sdc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X30, ctx->r29);
    // 0x8018D1E8: sdc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X28, ctx->r29);
    // 0x8018D1EC: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    // 0x8018D1F0: addiu       $t0, $t6, 0x1EC
    ctx->r8 = ADD32(ctx->r14, 0X1EC);
    // 0x8018D1F4: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_8018D1F8:
    // 0x8018D1F8: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D1FC: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018D200: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018D204: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018D208: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018D20C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018D210: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018D214: bne         $t6, $t0, L_8018D1F8
    if (ctx->r14 != ctx->r8) {
        // 0x8018D218: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018D1F8;
    }
    // 0x8018D218: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018D21C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018D220: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D224: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8018D228: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018D22C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x8018D230: sb          $a0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r4;
    // 0x8018D234: sb          $a0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r4;
    // 0x8018D238: sb          $t3, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r11;
    // 0x8018D23C: sb          $zero, 0x23($v1)
    MEM_B(0X23, ctx->r3) = 0;
    // 0x8018D240: jal         0x8018D0C0
    // 0x8018D244: sb          $t0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r8;
    mvUnknownMarioSetupFiles(rdram, ctx);
        goto after_0;
    // 0x8018D244: sb          $t0, 0x22($v1)
    MEM_B(0X22, ctx->r3) = ctx->r8;
    after_0:
    // 0x8018D248: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x8018D24C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D250: addiu       $a1, $a1, -0x2EA0
    ctx->r5 = ADD32(ctx->r5, -0X2EA0);
    // 0x8018D254: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8018D258: addiu       $a0, $zero, 0x3F7
    ctx->r4 = ADD32(0, 0X3F7);
    // 0x8018D25C: jal         0x80009968
    // 0x8018D260: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x8018D260: addiu       $a2, $zero, 0xD
    ctx->r6 = ADD32(0, 0XD);
    after_1:
    // 0x8018D264: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8018D268: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8018D26C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8018D270: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8018D274: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x8018D278: jal         0x8000B9FC
    // 0x8018D27C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_2;
    // 0x8018D27C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_2:
    // 0x8018D280: jal         0x80115890
    // 0x8018D284: nop

    efParticleInitAll(rdram, ctx);
        goto after_3;
    // 0x8018D284: nop

    after_3:
    // 0x8018D288: jal         0x800EC130
    // 0x8018D28C: nop

    ftParamInitGame(rdram, ctx);
        goto after_4;
    // 0x8018D28C: nop

    after_4:
    // 0x8018D290: jal         0x800FC284
    // 0x8018D294: nop

    mpCollisionInitGroundData(rdram, ctx);
        goto after_5;
    // 0x8018D294: nop

    after_5:
    // 0x8018D298: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x8018D29C: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8018D2A0: addiu       $a2, $zero, 0x136
    ctx->r6 = ADD32(0, 0X136);
    // 0x8018D2A4: jal         0x8010E598
    // 0x8018D2A8: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    gmCameraSetViewportDimensions(rdram, ctx);
        goto after_6;
    // 0x8018D2A8: addiu       $a3, $zero, 0xE6
    ctx->r7 = ADD32(0, 0XE6);
    after_6:
    // 0x8018D2AC: jal         0x8010DB54
    // 0x8018D2B0: nop

    gmCameraMakeWallpaperCamera(rdram, ctx);
        goto after_7;
    // 0x8018D2B0: nop

    after_7:
    // 0x8018D2B4: jal         0x80104BDC
    // 0x8018D2B8: nop

    grWallpaperMakeDecideKind(rdram, ctx);
        goto after_8;
    // 0x8018D2B8: nop

    after_8:
    // 0x8018D2BC: jal         0x8010DB00
    // 0x8018D2C0: nop

    gmCameraMakeBattleCamera(rdram, ctx);
        goto after_9;
    // 0x8018D2C0: nop

    after_9:
    // 0x8018D2C4: jal         0x80105600
    // 0x8018D2C8: nop

    grCommonSetupInitAll(rdram, ctx);
        goto after_10;
    // 0x8018D2C8: nop

    after_10:
    // 0x8018D2CC: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x8018D2D0: jal         0x800D7194
    // 0x8018D2D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftManagerAllocFighter(rdram, ctx);
        goto after_11;
    // 0x8018D2D4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x8018D2D8: jal         0x801654B0
    // 0x8018D2DC: nop

    wpManagerAllocWeapons(rdram, ctx);
        goto after_12;
    // 0x8018D2DC: nop

    after_12:
    // 0x8018D2E0: jal         0x8016DEA0
    // 0x8018D2E4: nop

    itManagerInitItems(rdram, ctx);
        goto after_13;
    // 0x8018D2E4: nop

    after_13:
    // 0x8018D2E8: jal         0x800FD300
    // 0x8018D2EC: nop

    efManagerInitEffects(rdram, ctx);
        goto after_14;
    // 0x8018D2EC: nop

    after_14:
    // 0x8018D2F0: jal         0x801156E4
    // 0x8018D2F4: nop

    gmRumbleMakeActor(rdram, ctx);
        goto after_15;
    // 0x8018D2F4: nop

    after_15:
    // 0x8018D2F8: jal         0x801653E0
    // 0x8018D2FC: nop

    ftPublicMakeActor(rdram, ctx);
        goto after_16;
    // 0x8018D2FC: nop

    after_16:
    // 0x8018D300: lui         $at, 0x4316
    ctx->r1 = S32(0X4316 << 16);
    // 0x8018D304: lui         $fp, 0x8019
    ctx->r30 = S32(0X8019 << 16);
    // 0x8018D308: lui         $s5, 0x8011
    ctx->r21 = S32(0X8011 << 16);
    // 0x8018D30C: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8018D310: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8018D314: addiu       $s5, $s5, 0x6DD0
    ctx->r21 = ADD32(ctx->r21, 0X6DD0);
    // 0x8018D318: addiu       $fp, $fp, -0x28B0
    ctx->r30 = ADD32(ctx->r30, -0X28B0);
    // 0x8018D31C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8018D320: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018D324: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x8018D328: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8018D32C: addiu       $s4, $sp, 0x74
    ctx->r20 = ADD32(ctx->r29, 0X74);
L_8018D330:
    // 0x8018D330: or          $t1, $s5, $zero
    ctx->r9 = ctx->r21 | 0;
    // 0x8018D334: or          $t2, $s4, $zero
    ctx->r10 = ctx->r20 | 0;
    // 0x8018D338: addiu       $t3, $s5, 0x3C
    ctx->r11 = ADD32(ctx->r21, 0X3C);
L_8018D33C:
    // 0x8018D33C: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8018D340: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x8018D344: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8018D348: sw          $t8, -0xC($t2)
    MEM_W(-0XC, ctx->r10) = ctx->r24;
    // 0x8018D34C: lw          $t7, -0x8($t1)
    ctx->r15 = MEM_W(ctx->r9, -0X8);
    // 0x8018D350: sw          $t7, -0x8($t2)
    MEM_W(-0X8, ctx->r10) = ctx->r15;
    // 0x8018D354: lw          $t8, -0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, -0X4);
    // 0x8018D358: bne         $t1, $t3, L_8018D33C
    if (ctx->r9 != ctx->r11) {
        // 0x8018D35C: sw          $t8, -0x4($t2)
        MEM_W(-0X4, ctx->r10) = ctx->r24;
            goto L_8018D33C;
    }
    // 0x8018D35C: sw          $t8, -0x4($t2)
    MEM_W(-0X4, ctx->r10) = ctx->r24;
    // 0x8018D360: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x8018D364: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x8018D368: sll         $t0, $s1, 2
    ctx->r8 = S32(ctx->r17 << 2);
    // 0x8018D36C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8018D370: lw          $t4, 0x50E8($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X50E8);
    // 0x8018D374: addu        $t0, $t0, $s1
    ctx->r8 = ADD32(ctx->r8, ctx->r17);
    // 0x8018D378: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8018D37C: addu        $s0, $t4, $s2
    ctx->r16 = ADD32(ctx->r12, ctx->r18);
    // 0x8018D380: lbu         $t5, 0x22($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D384: addiu       $t6, $t6, 0x5228
    ctx->r14 = ADD32(ctx->r14, 0X5228);
    // 0x8018D388: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8018D38C: beq         $s6, $t5, L_8018D440
    if (ctx->r22 == ctx->r13) {
        // 0x8018D390: addu        $s3, $t0, $t6
        ctx->r19 = ADD32(ctx->r8, ctx->r14);
            goto L_8018D440;
    }
    // 0x8018D390: addu        $s3, $t0, $t6
    ctx->r19 = ADD32(ctx->r8, ctx->r14);
    // 0x8018D394: jal         0x800D786C
    // 0x8018D398: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerSetupFilesAllKind(rdram, ctx);
        goto after_17;
    // 0x8018D398: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_17:
    // 0x8018D39C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D3A0: lw          $v0, 0x50E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X50E8);
    // 0x8018D3A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018D3A8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D3AC: addu        $s0, $v0, $s2
    ctx->r16 = ADD32(ctx->r2, ctx->r18);
    // 0x8018D3B0: lbu         $t9, 0x23($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X23);
    // 0x8018D3B4: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x8018D3B8: swc1        $f22, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f22.u32l;
    // 0x8018D3BC: swc1        $f20, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f20.u32l;
    // 0x8018D3C0: sw          $t3, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r11;
    // 0x8018D3C4: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8018D3C8: lbu         $t1, 0x24($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X24);
    // 0x8018D3CC: sb          $s1, 0x89($sp)
    MEM_B(0X89, ctx->r29) = ctx->r17;
    // 0x8018D3D0: sb          $t2, 0x8A($sp)
    MEM_B(0X8A, ctx->r29) = ctx->r10;
    // 0x8018D3D4: sb          $t1, 0x88($sp)
    MEM_B(0X88, ctx->r29) = ctx->r9;
    // 0x8018D3D8: lbu         $t7, 0x26($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X26);
    // 0x8018D3DC: sb          $t7, 0x8B($sp)
    MEM_B(0X8B, ctx->r29) = ctx->r15;
    // 0x8018D3E0: lbu         $t8, 0x21($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X21);
    // 0x8018D3E4: sb          $t8, 0x8D($sp)
    MEM_B(0X8D, ctx->r29) = ctx->r24;
    // 0x8018D3E8: lbu         $t4, 0x20($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X20);
    // 0x8018D3EC: sb          $t4, 0x8E($sp)
    MEM_B(0X8E, ctx->r29) = ctx->r12;
    // 0x8018D3F0: lbu         $t5, 0x7($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X7);
    // 0x8018D3F4: sw          $zero, 0x98($sp)
    MEM_W(0X98, ctx->r29) = 0;
    // 0x8018D3F8: sb          $t5, 0x8F($sp)
    MEM_B(0X8F, ctx->r29) = ctx->r13;
    // 0x8018D3FC: lbu         $t0, 0x22($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X22);
    // 0x8018D400: sw          $s3, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r19;
    // 0x8018D404: sw          $t0, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r8;
    // 0x8018D408: jal         0x800D78B4
    // 0x8018D40C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    ftManagerAllocFigatreeHeapKind(rdram, ctx);
        goto after_18;
    // 0x8018D40C: lbu         $a0, 0x23($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X23);
    after_18:
    // 0x8018D410: sw          $v0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r2;
    // 0x8018D414: jal         0x800D7F3C
    // 0x8018D418: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    ftManagerMakeFighter(rdram, ctx);
        goto after_19;
    // 0x8018D418: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_19:
    // 0x8018D41C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D420: sw          $v0, 0x0($fp)
    MEM_W(0X0, ctx->r30) = ctx->r2;
    // 0x8018D424: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8018D428: jal         0x800E7C4C
    // 0x8018D42C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    ftParamInitPlayerBattleStats(rdram, ctx);
        goto after_20;
    // 0x8018D42C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_20:
    // 0x8018D430: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D434: addiu       $a1, $a1, -0x2A80
    ctx->r5 = ADD32(ctx->r5, -0X2A80);
    // 0x8018D438: jal         0x800E9B30
    // 0x8018D43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftParamSetKey(rdram, ctx);
        goto after_21;
    // 0x8018D43C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_21:
L_8018D440:
    // 0x8018D440: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8018D444: bne         $s1, $s7, L_8018D330
    if (ctx->r17 != ctx->r23) {
        // 0x8018D448: addiu       $s2, $s2, 0x74
        ctx->r18 = ADD32(ctx->r18, 0X74);
            goto L_8018D330;
    }
    // 0x8018D448: addiu       $s2, $s2, 0x74
    ctx->r18 = ADD32(ctx->r18, 0X74);
    // 0x8018D44C: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018D450: addiu       $t6, $t6, -0x2A48
    ctx->r14 = ADD32(ctx->r14, -0X2A48);
    // 0x8018D454: lw          $t3, 0x0($t6)
    ctx->r11 = MEM_W(ctx->r14, 0X0);
    // 0x8018D458: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    // 0x8018D45C: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8018D460: sw          $t3, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r11;
    // 0x8018D464: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D468: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8018D46C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8018D470: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8018D474: addiu       $a0, $zero, 0x3FD
    ctx->r4 = ADD32(0, 0X3FD);
    // 0x8018D478: addiu       $a1, $zero, 0xD
    ctx->r5 = ADD32(0, 0XD);
    // 0x8018D47C: jal         0x800D4060
    // 0x8018D480: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    lbFadeMakeActor(rdram, ctx);
        goto after_22;
    // 0x8018D480: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_22:
    // 0x8018D484: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8018D488: ldc1        $f20, 0x28($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X28);
    // 0x8018D48C: ldc1        $f22, 0x30($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X30);
    // 0x8018D490: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8018D494: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8018D498: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8018D49C: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8018D4A0: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8018D4A4: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8018D4A8: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8018D4AC: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8018D4B0: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8018D4B4: jr          $ra
    // 0x8018D4B8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x8018D4B8: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void mnVSResultsGetDisplayPlace(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013607C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80136080: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136084: jal         0x8013205C
    // 0x80136088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnVSResultsGetPresentCount(rdram, ctx);
        goto after_0;
    // 0x80136088: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013608C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80136090: bne         $v0, $at, L_801360D8
    if (ctx->r2 != ctx->r1) {
        // 0x80136094: lui         $t6, 0x8014
        ctx->r14 = S32(0X8014 << 16);
            goto L_801360D8;
    }
    // 0x80136094: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80136098: lbu         $t6, -0x63EC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X63EC);
    // 0x8013609C: bnel        $t6, $zero, L_801360DC
    if (ctx->r14 != 0) {
        // 0x801360A0: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_801360DC;
    }
    goto skip_0;
    // 0x801360A0: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x801360A4: jal         0x80133684
    // 0x801360A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    mnVSResultsGetPlayerCountPlace(rdram, ctx);
        goto after_1;
    // 0x801360A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801360AC: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x801360B0: bne         $v0, $v1, L_801360D8
    if (ctx->r2 != ctx->r3) {
        // 0x801360B4: lw          $t7, 0x18($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X18);
            goto L_801360D8;
    }
    // 0x801360B4: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x801360B8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801360BC: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801360C0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801360C4: lw          $t9, -0x6450($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6450);
    // 0x801360C8: bnel        $v1, $t9, L_801360DC
    if (ctx->r3 != ctx->r25) {
        // 0x801360CC: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_801360DC;
    }
    goto skip_1;
    // 0x801360CC: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    skip_1:
    // 0x801360D0: b           L_801360F0
    // 0x801360D4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_801360F0;
    // 0x801360D4: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_801360D8:
    // 0x801360D8: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_801360DC:
    // 0x801360DC: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801360E0: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x801360E4: addu        $v0, $v0, $t1
    ctx->r2 = ADD32(ctx->r2, ctx->r9);
    // 0x801360E8: lw          $v0, -0x6450($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X6450);
    // 0x801360EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_801360F0:
    // 0x801360F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801360F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801360F8: jr          $ra
    // 0x801360FC: nop

    return;
    // 0x801360FC: nop

;}
RECOMP_FUNC void mnCongraCheckPlayerControllerConnected(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80131B04: lb          $t6, 0x51A4($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X51A4);
    // 0x80131B08: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80131B0C: bne         $a0, $t6, L_80131B1C
    if (ctx->r4 != ctx->r14) {
        // 0x80131B10: nop
    
            goto L_80131B1C;
    }
    // 0x80131B10: nop

    // 0x80131B14: jr          $ra
    // 0x80131B18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B18: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B1C:
    // 0x80131B1C: lb          $t7, 0x51A5($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X51A5);
    // 0x80131B20: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80131B24: bne         $a0, $t7, L_80131B34
    if (ctx->r4 != ctx->r15) {
        // 0x80131B28: nop
    
            goto L_80131B34;
    }
    // 0x80131B28: nop

    // 0x80131B2C: jr          $ra
    // 0x80131B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B30: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B34:
    // 0x80131B34: lb          $t8, 0x51A6($t8)
    ctx->r24 = MEM_B(ctx->r24, 0X51A6);
    // 0x80131B38: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80131B3C: bne         $a0, $t8, L_80131B4C
    if (ctx->r4 != ctx->r24) {
        // 0x80131B40: nop
    
            goto L_80131B4C;
    }
    // 0x80131B40: nop

    // 0x80131B44: jr          $ra
    // 0x80131B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B4C:
    // 0x80131B4C: lb          $t9, 0x51A7($t9)
    ctx->r25 = MEM_B(ctx->r25, 0X51A7);
    // 0x80131B50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80131B54: bne         $a0, $t9, L_80131B64
    if (ctx->r4 != ctx->r25) {
        // 0x80131B58: nop
    
            goto L_80131B64;
    }
    // 0x80131B58: nop

    // 0x80131B5C: jr          $ra
    // 0x80131B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x80131B60: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80131B64:
    // 0x80131B64: jr          $ra
    // 0x80131B68: nop

    return;
    // 0x80131B68: nop

;}
RECOMP_FUNC void func_ovl8_80384748(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80384748: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8038474C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80384750: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80384754: lw          $t9, 0xEC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XEC);
    // 0x80384758: lh          $t6, 0xE8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE8);
    // 0x8038475C: jalr        $t9
    // 0x80384760: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80384760: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80384764: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80384768: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8038476C: jr          $ra
    // 0x80384770: nop

    return;
    // 0x80384770: nop

;}
RECOMP_FUNC void func_ovl8_803737DC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803737DC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803737E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803737E4: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x803737E8: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x803737EC: swc1        $f12, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f12.u32l;
    // 0x803737F0: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x803737F4: nop

    // 0x803737F8: bc1fl       L_8037381C
    if (!c1cs) {
        // 0x803737FC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8037381C;
    }
    goto skip_0;
    // 0x803737FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80373800: lw          $v0, 0x30($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X30);
    // 0x80373804: mfc1        $a1, $f12
    ctx->r5 = (int32_t)ctx->f12.u32l;
    // 0x80373808: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x8037380C: lh          $t6, 0x40($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X40);
    // 0x80373810: jalr        $t9
    // 0x80373814: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80373814: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x80373818: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8037381C:
    // 0x8037381C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80373820: jr          $ra
    // 0x80373824: nop

    return;
    // 0x80373824: nop

;}
RECOMP_FUNC void mnVSResultsGetStatusLose(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801334CC: lui         $v0, 0x1
    ctx->r2 = S32(0X1 << 16);
    // 0x801334D0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x801334D4: jr          $ra
    // 0x801334D8: ori         $v0, $v0, 0x5
    ctx->r2 = ctx->r2 | 0X5;
    return;
    // 0x801334D8: ori         $v0, $v0, 0x5
    ctx->r2 = ctx->r2 | 0X5;
;}
RECOMP_FUNC void mnPlayersVSReadyProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80139DE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80139DE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80139DE8: jal         0x8013A5E4
    // 0x80139DEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mnPlayersVSCheckReady(rdram, ctx);
        goto after_0;
    // 0x80139DEC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80139DF0: beq         $v0, $zero, L_80139E3C
    if (ctx->r2 == 0) {
        // 0x80139DF4: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80139E3C;
    }
    // 0x80139DF4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80139DF8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80139DFC: addiu       $v1, $v1, -0x423C
    ctx->r3 = ADD32(ctx->r3, -0X423C);
    // 0x80139E00: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80139E04: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80139E08: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80139E0C: addiu       $v0, $t6, 0x1
    ctx->r2 = ADD32(ctx->r14, 0X1);
    // 0x80139E10: bne         $v0, $at, L_80139E20
    if (ctx->r2 != ctx->r1) {
        // 0x80139E14: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_80139E20;
    }
    // 0x80139E14: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80139E18: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x80139E1C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80139E20:
    // 0x80139E20: slti        $at, $v0, 0x1E
    ctx->r1 = SIGNED(ctx->r2) < 0X1E ? 1 : 0;
    // 0x80139E24: beq         $at, $zero, L_80139E34
    if (ctx->r1 == 0) {
        // 0x80139E28: nop
    
            goto L_80139E34;
    }
    // 0x80139E28: nop

    // 0x80139E2C: b           L_80139E50
    // 0x80139E30: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
        goto L_80139E50;
    // 0x80139E30: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
L_80139E34:
    // 0x80139E34: b           L_80139E50
    // 0x80139E38: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
        goto L_80139E50;
    // 0x80139E38: sw          $t8, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r24;
L_80139E3C:
    // 0x80139E3C: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80139E40: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80139E44: addiu       $v1, $v1, -0x423C
    ctx->r3 = ADD32(ctx->r3, -0X423C);
    // 0x80139E48: sw          $t9, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r25;
    // 0x80139E4C: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80139E50:
    // 0x80139E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80139E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80139E58: jr          $ra
    // 0x80139E5C: nop

    return;
    // 0x80139E5C: nop

;}
RECOMP_FUNC void ftBossOkukoukiProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015A2F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015A2F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015A2F8: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015A2FC: jal         0x800D9480
    // 0x8015A300: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015A300: addiu       $a1, $a1, -0x6FC0
    ctx->r5 = ADD32(ctx->r5, -0X6FC0);
    after_0:
    // 0x8015A304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015A308: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015A30C: jr          $ra
    // 0x8015A310: nop

    return;
    // 0x8015A310: nop

;}
RECOMP_FUNC void mnCharactersMakeWorksWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322F0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801322F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801322F8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x801322FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132300: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80132304: jal         0x80009968
    // 0x80132308: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132308: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013230C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80132310: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132314: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132318: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013231C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132320: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132324: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80132328: jal         0x80009DF4
    // 0x8013232C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013232C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132330: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132334: lw          $t7, 0x6A78($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6A78);
    // 0x80132338: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8013233C: addiu       $t8, $t8, 0x5058
    ctx->r24 = ADD32(ctx->r24, 0X5058);
    // 0x80132340: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132344: jal         0x800CCFDC
    // 0x80132348: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132348: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8013234C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132350: lui         $at, 0x42E8
    ctx->r1 = S32(0X42E8 << 16);
    // 0x80132354: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132358: lui         $at, 0x432D
    ctx->r1 = S32(0X432D << 16);
    // 0x8013235C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132360: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132364: addiu       $v1, $zero, 0xCF
    ctx->r3 = ADD32(0, 0XCF);
    // 0x80132368: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x8013236C: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80132370: addiu       $t3, $zero, 0xAE
    ctx->r11 = ADD32(0, 0XAE);
    // 0x80132374: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132378: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x8013237C: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132380: sb          $t3, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r11;
    // 0x80132384: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132388: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013238C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132390: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132394: jr          $ra
    // 0x80132398: nop

    return;
    // 0x80132398: nop

;}
RECOMP_FUNC void scSubsysFighterDrawLightColorGetAlpha(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80390534: lw          $a1, 0x0($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X0);
    // 0x80390538: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x8039053C: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80390540: addiu       $t6, $a1, 0x8
    ctx->r14 = ADD32(ctx->r5, 0X8);
    // 0x80390544: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80390548: addiu       $a2, $a2, 0x29E0
    ctx->r6 = ADD32(ctx->r6, 0X29E0);
    // 0x8039054C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80390550: lbu         $t2, 0x1($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0X1);
    // 0x80390554: lbu         $t9, 0x0($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X0);
    // 0x80390558: lbu         $t6, 0x2($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X2);
    // 0x8039055C: lbu         $t1, 0x3($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X3);
    // 0x80390560: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x80390564: sll         $t0, $t9, 24
    ctx->r8 = S32(ctx->r25 << 24);
    // 0x80390568: or          $t4, $t0, $t3
    ctx->r12 = ctx->r8 | ctx->r11;
    // 0x8039056C: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x80390570: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80390574: or          $t2, $t8, $t1
    ctx->r10 = ctx->r24 | ctx->r9;
    // 0x80390578: sw          $t2, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r10;
    // 0x8039057C: jr          $ra
    // 0x80390580: lbu         $v0, 0x3($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X3);
    return;
    // 0x80390580: lbu         $v0, 0x3($a2)
    ctx->r2 = MEM_BU(ctx->r6, 0X3);
;}
RECOMP_FUNC void itMSBombExplodeInitStatusVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801769AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801769B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801769B4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801769B8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801769BC: beq         $a1, $zero, L_801769D0
    if (ctx->r5 == 0) {
        // 0x801769C0: lw          $v0, 0x74($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X74);
            goto L_801769D0;
    }
    // 0x801769C0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801769C4: jal         0x80176934
    // 0x801769C8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    itMSBombExplodeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801769C8: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    after_0:
    // 0x801769CC: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
L_801769D0:
    // 0x801769D0: jal         0x801005C8
    // 0x801769D4: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x801769D4: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    after_1:
    // 0x801769D8: beq         $v0, $zero, L_801769FC
    if (ctx->r2 == 0) {
        // 0x801769DC: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801769FC;
    }
    // 0x801769DC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801769E0: lwc1        $f0, -0x32DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X32DC);
    // 0x801769E4: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
    // 0x801769E8: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x801769EC: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    // 0x801769F0: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x801769F4: lw          $t8, 0x5C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5C);
    // 0x801769F8: swc1        $f0, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f0.u32l;
L_801769FC:
    // 0x801769FC: jal         0x801008F4
    // 0x80176A00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_2;
    // 0x80176A00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_2:
    // 0x80176A04: jal         0x8017275C
    // 0x80176A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_3;
    // 0x80176A08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80176A0C: jal         0x80176F2C
    // 0x80176A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMSBombExplodeSetStatus(rdram, ctx);
        goto after_4;
    // 0x80176A10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80176A14: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80176A18: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80176A1C: sb          $t9, 0x54($t0)
    MEM_B(0X54, ctx->r8) = ctx->r25;
    // 0x80176A20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80176A24: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80176A28: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80176A2C: jr          $ra
    // 0x80176A30: nop

    return;
    // 0x80176A30: nop

;}
RECOMP_FUNC void efManagerFoxEntryArwingMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801037EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801037F0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801037F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801037F8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801037FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80103800: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80103804: jal         0x800FDAFC
    // 0x80103808: addiu       $a0, $a0, -0x190C
    ctx->r4 = ADD32(ctx->r4, -0X190C);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80103808: addiu       $a0, $a0, -0x190C
    ctx->r4 = ADD32(ctx->r4, -0X190C);
    after_0:
    // 0x8010380C: bne         $v0, $zero, L_8010381C
    if (ctx->r2 != 0) {
        // 0x80103810: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8010381C;
    }
    // 0x80103810: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80103814: b           L_80103904
    // 0x80103818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103904;
    // 0x80103818: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010381C:
    // 0x8010381C: lw          $s0, 0x74($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X74);
    // 0x80103820: addiu       $a1, $zero, 0x2C
    ctx->r5 = ADD32(0, 0X2C);
    // 0x80103824: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80103828: lw          $t6, 0x10($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X10);
    // 0x8010382C: lw          $t7, 0x10($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X10);
    // 0x80103830: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80103834: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80103838: lw          $t0, 0x8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X8);
    // 0x8010383C: lw          $t1, 0x8($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X8);
    // 0x80103840: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x80103844: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80103848: lw          $t4, 0x8($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X8);
    // 0x8010384C: lw          $a0, 0x10($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X10);
    // 0x80103850: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80103854: jal         0x80008CC0
    // 0x80103858: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80103858: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x8010385C: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80103860: lw          $t5, 0xEA4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XEA4);
    // 0x80103864: lui         $t6, 0x0
    ctx->r14 = S32(0X0 << 16);
    // 0x80103868: addiu       $t6, $t6, 0x2E74
    ctx->r14 = ADD32(ctx->r14, 0X2E74);
    // 0x8010386C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80103870: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80103874: jal         0x8000BD1C
    // 0x80103878: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_2;
    // 0x80103878: addu        $a1, $t5, $t6
    ctx->r5 = ADD32(ctx->r13, ctx->r14);
    after_2:
    // 0x8010387C: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x80103880: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80103884: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80103888: bne         $t7, $at, L_801038B8
    if (ctx->r15 != ctx->r1) {
        // 0x8010388C: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_801038B8;
    }
    // 0x8010388C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80103890: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80103894: lw          $t8, 0xEA0($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XEA0);
    // 0x80103898: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x8010389C: addiu       $t9, $t9, 0x9E0
    ctx->r25 = ADD32(ctx->r25, 0X9E0);
    // 0x801038A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801038A4: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x801038A8: jal         0x800C8758
    // 0x801038AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    lbCommonAddDObjAnimJointAll(rdram, ctx);
        goto after_3;
    // 0x801038AC: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
    after_3:
    // 0x801038B0: b           L_801038D4
    // 0x801038B4: nop

        goto L_801038D4;
    // 0x801038B4: nop

L_801038B8:
    // 0x801038B8: lw          $t0, 0xEA0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XEA0);
    // 0x801038BC: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x801038C0: addiu       $t1, $t1, 0x590
    ctx->r9 = ADD32(ctx->r9, 0X590);
    // 0x801038C4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801038C8: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x801038CC: jal         0x800C8758
    // 0x801038D0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    lbCommonAddDObjAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x801038D0: addu        $a1, $t0, $t1
    ctx->r5 = ADD32(ctx->r8, ctx->r9);
    after_4:
L_801038D4:
    // 0x801038D4: jal         0x8000DF34
    // 0x801038D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x801038D8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_5:
    // 0x801038DC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x801038E0: lw          $a0, 0x10($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X10);
    // 0x801038E4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x801038E8: sw          $t4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r12;
    // 0x801038EC: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x801038F0: sw          $t3, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r11;
    // 0x801038F4: lw          $t4, 0x8($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X8);
    // 0x801038F8: jal         0x800FD60C
    // 0x801038FC: sw          $t4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r12;
    efManagerSortZNeg(rdram, ctx);
        goto after_6;
    // 0x801038FC: sw          $t4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r12;
    after_6:
    // 0x80103900: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
L_80103904:
    // 0x80103904: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80103908: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8010390C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80103910: jr          $ra
    // 0x80103914: nop

    return;
    // 0x80103914: nop

;}
RECOMP_FUNC void ftFoxSpecialHiStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CAB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015CAB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015CAB8: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8015CABC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015CAC0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015CAC4: addiu       $a1, $zero, 0xE3
    ctx->r5 = ADD32(0, 0XE3);
    // 0x8015CAC8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015CACC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015CAD0: jal         0x800E6F24
    // 0x8015CAD4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015CAD4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x8015CAD8: jal         0x800E0830
    // 0x8015CADC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015CADC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015CAE0: jal         0x8015CAA4
    // 0x8015CAE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftFoxSpecialHiStartInitGravity(rdram, ctx);
        goto after_2;
    // 0x8015CAE4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015CAE8: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8015CAEC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8015CAF0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8015CAF4: lwc1        $f4, 0x60($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X60);
    // 0x8015CAF8: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8015CAFC: swc1        $f8, 0x60($t7)
    MEM_W(0X60, ctx->r15) = ctx->f8.u32l;
    // 0x8015CB00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015CB04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015CB08: jr          $ra
    // 0x8015CB0C: nop

    return;
    // 0x8015CB0C: nop

;}
RECOMP_FUNC void sc1PManagerUpdateScene(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D67DC: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800D67E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800D67E4: lui         $s2, 0x800A
    ctx->r18 = S32(0X800A << 16);
    // 0x800D67E8: addiu       $s2, $s2, 0x4AD0
    ctx->r18 = ADD32(ctx->r18, 0X4AD0);
    // 0x800D67EC: lbu         $t6, 0x1($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X1);
    // 0x800D67F0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800D67F4: lui         $s4, 0x800A
    ctx->r20 = S32(0X800A << 16);
    // 0x800D67F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D67FC: addiu       $s4, $s4, 0x4B18
    ctx->r20 = ADD32(ctx->r20, 0X4B18);
    // 0x800D6800: sb          $t6, 0xD60($at)
    MEM_B(0XD60, ctx->r1) = ctx->r14;
    // 0x800D6804: lbu         $t9, 0x1D($s4)
    ctx->r25 = MEM_BU(ctx->r20, 0X1D);
    // 0x800D6808: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x800D680C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D6810: andi        $t2, $t9, 0xFF7F
    ctx->r10 = ctx->r25 & 0XFF7F;
    // 0x800D6814: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x800D6818: sb          $t2, 0x1D($s4)
    MEM_B(0X1D, ctx->r20) = ctx->r10;
    // 0x800D681C: ori         $t3, $t2, 0x40
    ctx->r11 = ctx->r10 | 0X40;
    // 0x800D6820: sb          $t7, 0x2($s4)
    MEM_B(0X2, ctx->r20) = ctx->r15;
    // 0x800D6824: sb          $a3, 0x3($s4)
    MEM_B(0X3, ctx->r20) = ctx->r7;
    // 0x800D6828: sb          $t8, 0xB($s4)
    MEM_B(0XB, ctx->r20) = ctx->r24;
    // 0x800D682C: sb          $t3, 0x1D($s4)
    MEM_B(0X1D, ctx->r20) = ctx->r11;
    // 0x800D6830: lui         $t4, 0x800A
    ctx->r12 = S32(0X800A << 16);
    // 0x800D6834: lbu         $t4, 0x4AC2($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X4AC2);
    // 0x800D6838: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800D683C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800D6840: andi        $t5, $t4, 0x4
    ctx->r13 = ctx->r12 & 0X4;
    // 0x800D6844: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800D6848: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800D684C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800D6850: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800D6854: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800D6858: beq         $t5, $zero, L_800D6868
    if (ctx->r13 == 0) {
        // 0x800D685C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_800D6868;
    }
    // 0x800D685C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800D6860: sb          $zero, 0x14($s2)
    MEM_B(0X14, ctx->r18) = 0;
    // 0x800D6864: sb          $zero, 0x15($s2)
    MEM_B(0X15, ctx->r18) = 0;
L_800D6868:
    // 0x800D6868: lbu         $v0, 0x13($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X13);
    // 0x800D686C: addiu       $s5, $zero, 0x74
    ctx->r21 = ADD32(0, 0X74);
    // 0x800D6870: lbu         $t7, 0x14($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X14);
    // 0x800D6874: multu       $v0, $s5
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6878: lbu         $t8, 0x15($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X15);
    // 0x800D687C: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800D6880: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D6884: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800D6888: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800D688C: addiu       $s7, $s7, 0xD74
    ctx->r23 = ADD32(ctx->r23, 0XD74);
    // 0x800D6890: addiu       $s6, $s6, 0xD70
    ctx->r22 = ADD32(ctx->r22, 0XD70);
    // 0x800D6894: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800D6898: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D689C: mflo        $t6
    ctx->r14 = lo;
    // 0x800D68A0: addu        $a0, $s4, $t6
    ctx->r4 = ADD32(ctx->r20, ctx->r14);
    // 0x800D68A4: sb          $a3, 0x21($a0)
    MEM_B(0X21, ctx->r4) = ctx->r7;
    // 0x800D68A8: sb          $zero, 0x22($a0)
    MEM_B(0X22, ctx->r4) = 0;
    // 0x800D68AC: sb          $zero, 0x24($a0)
    MEM_B(0X24, ctx->r4) = 0;
    // 0x800D68B0: sb          $zero, 0x27($a0)
    MEM_B(0X27, ctx->r4) = 0;
    // 0x800D68B4: sb          $v0, 0x28($a0)
    MEM_B(0X28, ctx->r4) = ctx->r2;
    // 0x800D68B8: sb          $v0, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r2;
    // 0x800D68BC: sb          $t7, 0x23($a0)
    MEM_B(0X23, ctx->r4) = ctx->r15;
    // 0x800D68C0: sb          $t8, 0x26($a0)
    MEM_B(0X26, ctx->r4) = ctx->r24;
    // 0x800D68C4: lbu         $t9, 0x493B($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X493B);
    // 0x800D68C8: sb          $zero, 0x2C($a0)
    MEM_B(0X2C, ctx->r4) = 0;
    // 0x800D68CC: sw          $zero, 0x20($s2)
    MEM_W(0X20, ctx->r18) = 0;
    // 0x800D68D0: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
    // 0x800D68D4: sw          $zero, 0x28($s2)
    MEM_W(0X28, ctx->r18) = 0;
    // 0x800D68D8: sb          $t9, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r25;
    // 0x800D68DC: sw          $zero, 0xD64($at)
    MEM_W(0XD64, ctx->r1) = 0;
    // 0x800D68E0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D68E4: sw          $zero, 0xD68($at)
    MEM_W(0XD68, ctx->r1) = 0;
    // 0x800D68E8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D68EC: sw          $zero, 0xD6C($at)
    MEM_W(0XD6C, ctx->r1) = 0;
    // 0x800D68F0: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D68F4: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    // 0x800D68F8: sb          $t0, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r8;
    // 0x800D68FC: addiu       $a0, $a0, 0x4AD2
    ctx->r4 = ADD32(ctx->r4, 0X4AD2);
    // 0x800D6900: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x800D6904: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_800D6908:
    // 0x800D6908: bnel        $v0, $a2, L_800D691C
    if (ctx->r2 != ctx->r6) {
        // 0x800D690C: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800D691C;
    }
    goto skip_0;
    // 0x800D690C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800D6910: b           L_800D691C
    // 0x800D6914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800D691C;
    // 0x800D6914: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D6918: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800D691C:
    // 0x800D691C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D6920: bne         $v1, $a0, L_800D6908
    if (ctx->r3 != ctx->r4) {
        // 0x800D6924: sb          $v0, 0x17($v1)
        MEM_B(0X17, ctx->r3) = ctx->r2;
            goto L_800D6908;
    }
    // 0x800D6924: sb          $v0, 0x17($v1)
    MEM_B(0X17, ctx->r3) = ctx->r2;
    // 0x800D6928: lbu         $a1, 0x17($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X17);
    // 0x800D692C: slti        $at, $a1, 0xE
    ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    // 0x800D6930: bnel        $at, $zero, L_800D6944
    if (ctx->r1 != 0) {
        // 0x800D6934: slti        $at, $a1, 0xE
        ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
            goto L_800D6944;
    }
    goto skip_1;
    // 0x800D6934: slti        $at, $a1, 0xE
    ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    skip_1:
    // 0x800D6938: b           L_800D6DB8
    // 0x800D693C: addiu       $fp, $zero, 0x34
    ctx->r30 = ADD32(0, 0X34);
        goto L_800D6DB8;
    // 0x800D693C: addiu       $fp, $zero, 0x34
    ctx->r30 = ADD32(0, 0X34);
    // 0x800D6940: slti        $at, $a1, 0xE
    ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
L_800D6944:
    // 0x800D6944: beq         $at, $zero, L_800D6D38
    if (ctx->r1 == 0) {
        // 0x800D6948: addiu       $fp, $zero, 0x34
        ctx->r30 = ADD32(0, 0X34);
            goto L_800D6D38;
    }
    // 0x800D6948: addiu       $fp, $zero, 0x34
    ctx->r30 = ADD32(0, 0X34);
    // 0x800D694C: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x800D6950: addiu       $s3, $s3, 0x4ADC
    ctx->r19 = ADD32(ctx->r19, 0X4ADC);
    // 0x800D6954: addiu       $s0, $zero, 0x20
    ctx->r16 = ADD32(0, 0X20);
L_800D6958:
    // 0x800D6958: lbu         $t2, 0x14($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X14);
    // 0x800D695C: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D6960: lhu         $v1, 0x4938($v1)
    ctx->r3 = MEM_HU(ctx->r3, 0X4938);
    // 0x800D6964: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D6968: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x800D696C: nor         $t5, $t4, $zero
    ctx->r13 = ~(ctx->r12 | 0);
    // 0x800D6970: ori         $t1, $v1, 0x36F
    ctx->r9 = ctx->r3 | 0X36F;
    // 0x800D6974: and         $s1, $t1, $t5
    ctx->r17 = ctx->r9 & ctx->r13;
    // 0x800D6978: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D697C: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x800D6980: beq         $a1, $at, L_800D69A4
    if (ctx->r5 == ctx->r1) {
        // 0x800D6984: sw          $zero, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = 0;
            goto L_800D69A4;
    }
    // 0x800D6984: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x800D6988: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800D698C: beq         $a1, $at, L_800D6A1C
    if (ctx->r5 == ctx->r1) {
        // 0x800D6990: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_800D6A1C;
    }
    // 0x800D6990: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800D6994: beql        $a1, $at, L_800D6AB8
    if (ctx->r5 == ctx->r1) {
        // 0x800D6998: ori         $s1, $v1, 0x100
        ctx->r17 = ctx->r3 | 0X100;
            goto L_800D6AB8;
    }
    goto skip_2;
    // 0x800D6998: ori         $s1, $v1, 0x100
    ctx->r17 = ctx->r3 | 0X100;
    skip_2:
    // 0x800D699C: b           L_800D6AFC
    // 0x800D69A0: nop

        goto L_800D6AFC;
    // 0x800D69A0: nop

L_800D69A4:
    // 0x800D69A4: andi        $s1, $s1, 0xFFFE
    ctx->r17 = ctx->r17 & 0XFFFE;
    // 0x800D69A8: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x800D69AC: jal         0x800D6490
    // 0x800D69B0: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    sc1PManagerGetFighterKindsNum(rdram, ctx);
        goto after_0;
    // 0x800D69B0: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_0:
    // 0x800D69B4: jal         0x80018994
    // 0x800D69B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    syUtilsRandIntRange(rdram, ctx);
        goto after_1;
    // 0x800D69B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800D69BC: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x800D69C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D69C4: jal         0x800D6508
    // 0x800D69C8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    sc1PManagerGetShuffledFighterKind(rdram, ctx);
        goto after_2;
    // 0x800D69C8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_2:
    // 0x800D69CC: lbu         $t6, 0x18($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X18);
    // 0x800D69D0: andi        $t8, $v0, 0xFF
    ctx->r24 = ctx->r2 & 0XFF;
    // 0x800D69D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800D69D8: multu       $t6, $s5
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D69DC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x800D69E0: mflo        $t7
    ctx->r15 = lo;
    // 0x800D69E4: addu        $v1, $s4, $t7
    ctx->r3 = ADD32(ctx->r20, ctx->r15);
    // 0x800D69E8: bne         $t8, $at, L_800D6A10
    if (ctx->r24 != ctx->r1) {
        // 0x800D69EC: sb          $v0, 0x23($v1)
        MEM_B(0X23, ctx->r3) = ctx->r2;
            goto L_800D6A10;
    }
    // 0x800D69EC: sb          $v0, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r2;
    // 0x800D69F0: jal         0x800EC0EC
    // 0x800D69F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_3;
    // 0x800D69F4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x800D69F8: lbu         $t9, 0x18($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X18);
    // 0x800D69FC: multu       $t9, $s5
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6A00: mflo        $t0
    ctx->r8 = lo;
    // 0x800D6A04: addu        $v1, $s4, $t0
    ctx->r3 = ADD32(ctx->r20, ctx->r8);
    // 0x800D6A08: b           L_800D6A14
    // 0x800D6A0C: sb          $v0, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r2;
        goto L_800D6A14;
    // 0x800D6A0C: sb          $v0, 0x26($v1)
    MEM_B(0X26, ctx->r3) = ctx->r2;
L_800D6A10:
    // 0x800D6A10: sb          $zero, 0x26($v1)
    MEM_B(0X26, ctx->r3) = 0;
L_800D6A14:
    // 0x800D6A14: b           L_800D6AFC
    // 0x800D6A18: sb          $zero, 0x27($v1)
    MEM_B(0X27, ctx->r3) = 0;
        goto L_800D6AFC;
    // 0x800D6A18: sb          $zero, 0x27($v1)
    MEM_B(0X27, ctx->r3) = 0;
L_800D6A1C:
    // 0x800D6A1C: jal         0x800D6490
    // 0x800D6A20: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    sc1PManagerGetFighterKindsNum(rdram, ctx);
        goto after_4;
    // 0x800D6A20: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_4:
    // 0x800D6A24: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800D6A28: jal         0x80018994
    // 0x800D6A2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    syUtilsRandIntRange(rdram, ctx);
        goto after_5;
    // 0x800D6A2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_5:
    // 0x800D6A30: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x800D6A34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6A38: jal         0x800D6508
    // 0x800D6A3C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    sc1PManagerGetShuffledFighterKind(rdram, ctx);
        goto after_6;
    // 0x800D6A3C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_6:
    // 0x800D6A40: lbu         $t3, 0x18($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X18);
    // 0x800D6A44: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800D6A48: multu       $t3, $s5
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6A4C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800D6A50: mflo        $t2
    ctx->r10 = lo;
    // 0x800D6A54: addu        $v1, $s4, $t2
    ctx->r3 = ADD32(ctx->r20, ctx->r10);
    // 0x800D6A58: sb          $v0, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r2;
    // 0x800D6A5C: sb          $zero, 0x26($v1)
    MEM_B(0X26, ctx->r3) = 0;
    // 0x800D6A60: jal         0x80018994
    // 0x800D6A64: sb          $zero, 0x27($v1)
    MEM_B(0X27, ctx->r3) = 0;
    syUtilsRandIntRange(rdram, ctx);
        goto after_7;
    // 0x800D6A64: sb          $zero, 0x27($v1)
    MEM_B(0X27, ctx->r3) = 0;
    after_7:
    // 0x800D6A68: lbu         $t4, 0x18($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X18);
    // 0x800D6A6C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D6A70: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x800D6A74: multu       $t4, $s5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6A78: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800D6A7C: mflo        $t1
    ctx->r9 = lo;
    // 0x800D6A80: addu        $t5, $s4, $t1
    ctx->r13 = ADD32(ctx->r20, ctx->r9);
    // 0x800D6A84: lbu         $t6, 0x23($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X23);
    // 0x800D6A88: sllv        $a1, $t7, $t6
    ctx->r5 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800D6A8C: jal         0x800D6508
    // 0x800D6A90: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    sc1PManagerGetShuffledFighterKind(rdram, ctx);
        goto after_8;
    // 0x800D6A90: andi        $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 & 0XFFFF;
    after_8:
    // 0x800D6A94: lbu         $t8, 0x19($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X19);
    // 0x800D6A98: multu       $t8, $s5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6A9C: mflo        $t9
    ctx->r25 = lo;
    // 0x800D6AA0: addu        $v1, $s4, $t9
    ctx->r3 = ADD32(ctx->r20, ctx->r25);
    // 0x800D6AA4: sb          $v0, 0x23($v1)
    MEM_B(0X23, ctx->r3) = ctx->r2;
    // 0x800D6AA8: sb          $zero, 0x26($v1)
    MEM_B(0X26, ctx->r3) = 0;
    // 0x800D6AAC: b           L_800D6AFC
    // 0x800D6AB0: sb          $zero, 0x27($v1)
    MEM_B(0X27, ctx->r3) = 0;
        goto L_800D6AFC;
    // 0x800D6AB0: sb          $zero, 0x27($v1)
    MEM_B(0X27, ctx->r3) = 0;
    // 0x800D6AB4: ori         $s1, $v1, 0x100
    ctx->r17 = ctx->r3 | 0X100;
L_800D6AB8:
    // 0x800D6AB8: andi        $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 & 0XFFFF;
    // 0x800D6ABC: jal         0x800D6490
    // 0x800D6AC0: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    sc1PManagerGetFighterKindsNum(rdram, ctx);
        goto after_9;
    // 0x800D6AC0: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    after_9:
    // 0x800D6AC4: jal         0x80018994
    // 0x800D6AC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    syUtilsRandIntRange(rdram, ctx);
        goto after_10;
    // 0x800D6AC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_10:
    // 0x800D6ACC: andi        $a0, $s1, 0xFFFF
    ctx->r4 = ctx->r17 & 0XFFFF;
    // 0x800D6AD0: jal         0x800D6554
    // 0x800D6AD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    sc1PManagerGetShuffledKirbyCopy(rdram, ctx);
        goto after_11;
    // 0x800D6AD4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_11:
    // 0x800D6AD8: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800D6ADC: addiu       $v1, $v1, 0xD75
    ctx->r3 = ADD32(ctx->r3, 0XD75);
    // 0x800D6AE0: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x800D6AE4: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x800D6AE8: sb          $v0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r2;
    // 0x800D6AEC: addu        $t3, $t3, $t0
    ctx->r11 = ADD32(ctx->r11, ctx->r8);
    // 0x800D6AF0: lbu         $t3, 0x6DA0($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X6DA0);
    // 0x800D6AF4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800D6AF8: sb          $t3, 0xD76($at)
    MEM_B(0XD76, ctx->r1) = ctx->r11;
L_800D6AFC:
    // 0x800D6AFC: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6B00: jal         0x80002BE4
    // 0x800D6B04: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    syDmaLoadOverlay(rdram, ctx);
        goto after_12;
    // 0x800D6B04: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    after_12:
    // 0x800D6B08: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6B0C: jal         0x80002BE4
    // 0x800D6B10: addiu       $a0, $a0, 0x6C14
    ctx->r4 = ADD32(ctx->r4, 0X6C14);
    syDmaLoadOverlay(rdram, ctx);
        goto after_13;
    // 0x800D6B10: addiu       $a0, $a0, 0x6C14
    ctx->r4 = ADD32(ctx->r4, 0X6C14);
    after_13:
    // 0x800D6B14: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x800D6B18: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6B1C: jal         0x80134D98
    // 0x800D6B20: sb          $t2, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r10;
    sc1PIntroStartScene(rdram, ctx);
        goto after_14;
    // 0x800D6B20: sb          $t2, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r10;
    after_14:
    // 0x800D6B24: lbu         $v0, 0x17($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X17);
    // 0x800D6B28: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800D6B2C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6B30: beq         $v0, $at, L_800D6B40
    if (ctx->r2 == ctx->r1) {
        // 0x800D6B34: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_800D6B40;
    }
    // 0x800D6B34: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800D6B38: bne         $v0, $at, L_800D6B6C
    if (ctx->r2 != ctx->r1) {
        // 0x800D6B3C: nop
    
            goto L_800D6B6C;
    }
    // 0x800D6B3C: nop

L_800D6B40:
    // 0x800D6B40: jal         0x80002BE4
    // 0x800D6B44: addiu       $a0, $a0, 0x6D34
    ctx->r4 = ADD32(ctx->r4, 0X6D34);
    syDmaLoadOverlay(rdram, ctx);
        goto after_15;
    // 0x800D6B44: addiu       $a0, $a0, 0x6D34
    ctx->r4 = ADD32(ctx->r4, 0X6D34);
    after_15:
    // 0x800D6B48: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6B4C: jal         0x80002BE4
    // 0x800D6B50: addiu       $a0, $a0, 0x6D58
    ctx->r4 = ADD32(ctx->r4, 0X6D58);
    syDmaLoadOverlay(rdram, ctx);
        goto after_16;
    // 0x800D6B50: addiu       $a0, $a0, 0x6D58
    ctx->r4 = ADD32(ctx->r4, 0X6D58);
    after_16:
    // 0x800D6B54: addiu       $t4, $zero, 0x35
    ctx->r12 = ADD32(0, 0X35);
    // 0x800D6B58: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6B5C: jal         0x8018EACC
    // 0x800D6B60: sb          $t4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r12;
    sc1PBonusStageStartScene(rdram, ctx);
        goto after_17;
    // 0x800D6B60: sb          $t4, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r12;
    after_17:
    // 0x800D6B64: b           L_800D6BD4
    // 0x800D6B68: lbu         $t3, 0x12($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X12);
        goto L_800D6BD4;
    // 0x800D6B68: lbu         $t3, 0x12($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X12);
L_800D6B6C:
    // 0x800D6B6C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6B70: jal         0x80002BE4
    // 0x800D6B74: addiu       $a0, $a0, 0x6D34
    ctx->r4 = ADD32(ctx->r4, 0X6D34);
    syDmaLoadOverlay(rdram, ctx);
        goto after_18;
    // 0x800D6B74: addiu       $a0, $a0, 0x6D34
    ctx->r4 = ADD32(ctx->r4, 0X6D34);
    after_18:
    // 0x800D6B78: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6B7C: jal         0x80002BE4
    // 0x800D6B80: addiu       $a0, $a0, 0x6D10
    ctx->r4 = ADD32(ctx->r4, 0X6D10);
    syDmaLoadOverlay(rdram, ctx);
        goto after_19;
    // 0x800D6B80: addiu       $a0, $a0, 0x6D10
    ctx->r4 = ADD32(ctx->r4, 0X6D10);
    after_19:
    // 0x800D6B84: jal         0x80190FD8
    // 0x800D6B88: nop

    sc1PGameStartScene(rdram, ctx);
        goto after_20;
    // 0x800D6B88: nop

    after_20:
    // 0x800D6B8C: lbu         $t1, 0x17($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X17);
    // 0x800D6B90: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x800D6B94: beql        $t1, $at, L_800D6BD4
    if (ctx->r9 == ctx->r1) {
        // 0x800D6B98: lbu         $t3, 0x12($s2)
        ctx->r11 = MEM_BU(ctx->r18, 0X12);
            goto L_800D6BD4;
    }
    goto skip_3;
    // 0x800D6B98: lbu         $t3, 0x12($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X12);
    skip_3:
    // 0x800D6B9C: lbu         $t5, 0x13($s2)
    ctx->r13 = MEM_BU(ctx->r18, 0X13);
    // 0x800D6BA0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D6BA4: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800D6BA8: multu       $t5, $s5
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6BAC: mflo        $t7
    ctx->r15 = lo;
    // 0x800D6BB0: addu        $t6, $s4, $t7
    ctx->r14 = ADD32(ctx->r20, ctx->r15);
    // 0x800D6BB4: lb          $t8, 0x2B($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X2B);
    // 0x800D6BB8: beql        $t8, $at, L_800D6BD0
    if (ctx->r24 == ctx->r1) {
        // 0x800D6BBC: sw          $t0, 0x4C($sp)
        MEM_W(0X4C, ctx->r29) = ctx->r8;
            goto L_800D6BD0;
    }
    goto skip_4;
    // 0x800D6BBC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    skip_4:
    // 0x800D6BC0: lw          $t9, 0x14($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X14);
    // 0x800D6BC4: bnel        $t9, $zero, L_800D6BD4
    if (ctx->r25 != 0) {
        // 0x800D6BC8: lbu         $t3, 0x12($s2)
        ctx->r11 = MEM_BU(ctx->r18, 0X12);
            goto L_800D6BD4;
    }
    goto skip_5;
    // 0x800D6BC8: lbu         $t3, 0x12($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X12);
    skip_5:
    // 0x800D6BCC: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
L_800D6BD0:
    // 0x800D6BD0: lbu         $t3, 0x12($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X12);
L_800D6BD4:
    // 0x800D6BD4: addiu       $t2, $zero, 0x8
    ctx->r10 = ADD32(0, 0X8);
    // 0x800D6BD8: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800D6BDC: beq         $t3, $zero, L_800D6BF0
    if (ctx->r11 == 0) {
        // 0x800D6BE0: nop
    
            goto L_800D6BF0;
    }
    // 0x800D6BE0: nop

    // 0x800D6BE4: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6BE8: b           L_800D6FAC
    // 0x800D6BEC: sb          $t2, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r10;
        goto L_800D6FAC;
    // 0x800D6BEC: sb          $t2, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r10;
L_800D6BF0:
    // 0x800D6BF0: beq         $t4, $zero, L_800D6CAC
    if (ctx->r12 == 0) {
        // 0x800D6BF4: addiu       $t2, $zero, 0x2
        ctx->r10 = ADD32(0, 0X2);
            goto L_800D6CAC;
    }
    // 0x800D6BF4: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x800D6BF8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6BFC: jal         0x80002BE4
    // 0x800D6C00: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    syDmaLoadOverlay(rdram, ctx);
        goto after_21;
    // 0x800D6C00: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    after_21:
    // 0x800D6C04: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6C08: jal         0x80002BE4
    // 0x800D6C0C: addiu       $a0, $a0, 0x6D7C
    ctx->r4 = ADD32(ctx->r4, 0X6D7C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_22;
    // 0x800D6C0C: addiu       $a0, $a0, 0x6D7C
    ctx->r4 = ADD32(ctx->r4, 0X6D7C);
    after_22:
    // 0x800D6C10: jal         0x801340FC
    // 0x800D6C14: nop

    mnPlayers1PGameContinueStartScene(rdram, ctx);
        goto after_23;
    // 0x800D6C14: nop

    after_23:
    // 0x800D6C18: lbu         $t1, 0x11($s2)
    ctx->r9 = MEM_BU(ctx->r18, 0X11);
    // 0x800D6C1C: beq         $t1, $zero, L_800D6C94
    if (ctx->r9 == 0) {
        // 0x800D6C20: nop
    
            goto L_800D6C94;
    }
    // 0x800D6C20: nop

    // 0x800D6C24: lbu         $t8, 0x13($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X13);
    // 0x800D6C28: lw          $t5, 0x24($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X24);
    // 0x800D6C2C: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800D6C30: multu       $t8, $s5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6C34: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x800D6C38: sw          $t7, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r15;
    // 0x800D6C3C: lbu         $t6, 0x493B($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X493B);
    // 0x800D6C40: mflo        $t9
    ctx->r25 = lo;
    // 0x800D6C44: addu        $t0, $s4, $t9
    ctx->r8 = ADD32(ctx->r20, ctx->r25);
    // 0x800D6C48: sb          $t6, 0x2B($t0)
    MEM_B(0X2B, ctx->r8) = ctx->r14;
    // 0x800D6C4C: lbu         $t4, 0x0($s7)
    ctx->r12 = MEM_BU(ctx->r23, 0X0);
    // 0x800D6C50: lbu         $t3, 0x17($s2)
    ctx->r11 = MEM_BU(ctx->r18, 0X17);
    // 0x800D6C54: addiu       $t1, $t4, -0x1
    ctx->r9 = ADD32(ctx->r12, -0X1);
    // 0x800D6C58: andi        $t5, $t1, 0xFF
    ctx->r13 = ctx->r9 & 0XFF;
    // 0x800D6C5C: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x800D6C60: sb          $t2, 0x17($s2)
    MEM_B(0X17, ctx->r18) = ctx->r10;
    // 0x800D6C64: bne         $t5, $zero, L_800D6D20
    if (ctx->r13 != 0) {
        // 0x800D6C68: sb          $t1, 0x0($s7)
        MEM_B(0X0, ctx->r23) = ctx->r9;
            goto L_800D6D20;
    }
    // 0x800D6C68: sb          $t1, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r9;
    // 0x800D6C6C: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x800D6C70: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800D6C74: sb          $t7, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r15;
    // 0x800D6C78: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D6C7C: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x800D6C80: bne         $at, $zero, L_800D6D20
    if (ctx->r1 != 0) {
        // 0x800D6C84: sw          $t9, 0x0($s6)
        MEM_W(0X0, ctx->r22) = ctx->r25;
            goto L_800D6D20;
    }
    // 0x800D6C84: sw          $t9, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r25;
    // 0x800D6C88: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800D6C8C: b           L_800D6D20
    // 0x800D6C90: sw          $t0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r8;
        goto L_800D6D20;
    // 0x800D6C90: sw          $t0, 0x0($s6)
    MEM_W(0X0, ctx->r22) = ctx->r8;
L_800D6C94:
    // 0x800D6C94: jal         0x800D6738
    // 0x800D6C98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sc1PManagerTrySaveBackup(rdram, ctx);
        goto after_24;
    // 0x800D6C98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
    // 0x800D6C9C: addiu       $t3, $zero, 0x1B
    ctx->r11 = ADD32(0, 0X1B);
    // 0x800D6CA0: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6CA4: b           L_800D6FAC
    // 0x800D6CA8: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
        goto L_800D6FAC;
    // 0x800D6CA8: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
L_800D6CAC:
    // 0x800D6CAC: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D6CB0: sw          $zero, 0x0($s6)
    MEM_W(0X0, ctx->r22) = 0;
    // 0x800D6CB4: sb          $t2, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r10;
    // 0x800D6CB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800D6CBC: addiu       $a0, $a0, 0x4AD0
    ctx->r4 = ADD32(ctx->r4, 0X4AD0);
    // 0x800D6CC0: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
L_800D6CC4:
    // 0x800D6CC4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800D6CC8:
    // 0x800D6CC8: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    // 0x800D6CCC: beq         $t4, $zero, L_800D6CD8
    if (ctx->r12 == 0) {
        // 0x800D6CD0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800D6CD8;
    }
    // 0x800D6CD0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800D6CD4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
L_800D6CD8:
    // 0x800D6CD8: bne         $v1, $s0, L_800D6CC8
    if (ctx->r3 != ctx->r16) {
        // 0x800D6CDC: srl         $v0, $v0, 1
        ctx->r2 = S32(U32(ctx->r2) >> 1);
            goto L_800D6CC8;
    }
    // 0x800D6CDC: srl         $v0, $v0, 1
    ctx->r2 = S32(U32(ctx->r2) >> 1);
    // 0x800D6CE0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800D6CE4: bnel        $a0, $s3, L_800D6CC4
    if (ctx->r4 != ctx->r19) {
        // 0x800D6CE8: lw          $v0, 0x2C($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X2C);
            goto L_800D6CC4;
    }
    goto skip_6;
    // 0x800D6CE8: lw          $v0, 0x2C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X2C);
    skip_6:
    // 0x800D6CEC: lw          $t1, 0x28($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X28);
    // 0x800D6CF0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6CF4: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    // 0x800D6CF8: addu        $t5, $t1, $a1
    ctx->r13 = ADD32(ctx->r9, ctx->r5);
    // 0x800D6CFC: jal         0x80002BE4
    // 0x800D6D00: sw          $t5, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r13;
    syDmaLoadOverlay(rdram, ctx);
        goto after_25;
    // 0x800D6D00: sw          $t5, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r13;
    after_25:
    // 0x800D6D04: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6D08: jal         0x80002BE4
    // 0x800D6D0C: addiu       $a0, $a0, 0x6C38
    ctx->r4 = ADD32(ctx->r4, 0X6C38);
    syDmaLoadOverlay(rdram, ctx);
        goto after_26;
    // 0x800D6D0C: addiu       $a0, $a0, 0x6C38
    ctx->r4 = ADD32(ctx->r4, 0X6C38);
    after_26:
    // 0x800D6D10: addiu       $t7, $zero, 0x33
    ctx->r15 = ADD32(0, 0X33);
    // 0x800D6D14: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6D18: jal         0x80134E84
    // 0x800D6D1C: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
    sc1PStageClearStartScene(rdram, ctx);
        goto after_27;
    // 0x800D6D1C: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
    after_27:
L_800D6D20:
    // 0x800D6D20: lbu         $t8, 0x17($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X17);
    // 0x800D6D24: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D6D28: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
    // 0x800D6D2C: slti        $at, $a1, 0xE
    ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    // 0x800D6D30: bne         $at, $zero, L_800D6958
    if (ctx->r1 != 0) {
        // 0x800D6D34: sb          $t9, 0x17($s2)
        MEM_B(0X17, ctx->r18) = ctx->r25;
            goto L_800D6958;
    }
    // 0x800D6D34: sb          $t9, 0x17($s2)
    MEM_B(0X17, ctx->r18) = ctx->r25;
L_800D6D38:
    // 0x800D6D38: addiu       $fp, $zero, 0x34
    ctx->r30 = ADD32(0, 0X34);
    // 0x800D6D3C: jal         0x800D6738
    // 0x800D6D40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sc1PManagerTrySaveBackup(rdram, ctx);
        goto after_28;
    // 0x800D6D40: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_28:
    // 0x800D6D44: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6D48: jal         0x80002BE4
    // 0x800D6D4C: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    syDmaLoadOverlay(rdram, ctx);
        goto after_29;
    // 0x800D6D4C: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    after_29:
    // 0x800D6D50: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6D54: jal         0x80002BE4
    // 0x800D6D58: addiu       $a0, $a0, 0x6C80
    ctx->r4 = ADD32(ctx->r4, 0X6C80);
    syDmaLoadOverlay(rdram, ctx);
        goto after_30;
    // 0x800D6D58: addiu       $a0, $a0, 0x6C80
    ctx->r4 = ADD32(ctx->r4, 0X6C80);
    after_30:
    // 0x800D6D5C: addiu       $t6, $zero, 0x30
    ctx->r14 = ADD32(0, 0X30);
    // 0x800D6D60: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6D64: jal         0x80132A78
    // 0x800D6D68: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
    mvEndingStartScene(rdram, ctx);
        goto after_31;
    // 0x800D6D68: sb          $t6, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r14;
    after_31:
    // 0x800D6D6C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6D70: jal         0x80002BE4
    // 0x800D6D74: addiu       $a0, $a0, 0x6CEC
    ctx->r4 = ADD32(ctx->r4, 0X6CEC);
    syDmaLoadOverlay(rdram, ctx);
        goto after_32;
    // 0x800D6D74: addiu       $a0, $a0, 0x6CEC
    ctx->r4 = ADD32(ctx->r4, 0X6CEC);
    after_32:
    // 0x800D6D78: addiu       $t0, $zero, 0x38
    ctx->r8 = ADD32(0, 0X38);
    // 0x800D6D7C: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6D80: jal         0x801351B8
    // 0x800D6D84: sb          $t0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r8;
    scStaffrollStartScene(rdram, ctx);
        goto after_33;
    // 0x800D6D84: sb          $t0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r8;
    after_33:
    // 0x800D6D88: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6D8C: jal         0x80002BE4
    // 0x800D6D90: addiu       $a0, $a0, 0x6CC8
    ctx->r4 = ADD32(ctx->r4, 0X6CC8);
    syDmaLoadOverlay(rdram, ctx);
        goto after_34;
    // 0x800D6D90: addiu       $a0, $a0, 0x6CC8
    ctx->r4 = ADD32(ctx->r4, 0X6CC8);
    after_34:
    // 0x800D6D94: addiu       $t3, $zero, 0x37
    ctx->r11 = ADD32(0, 0X37);
    // 0x800D6D98: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6D9C: jal         0x8013200C
    // 0x800D6DA0: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
    mnCongraStartScene(rdram, ctx);
        goto after_35;
    // 0x800D6DA0: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
    after_35:
    // 0x800D6DA4: lbu         $t2, 0x17($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X17);
    // 0x800D6DA8: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x800D6DAC: jal         0x800D6590
    // 0x800D6DB0: sb          $t4, 0x17($s2)
    MEM_B(0X17, ctx->r18) = ctx->r12;
    sc1PManagerTrySetChallengers(rdram, ctx);
        goto after_36;
    // 0x800D6DB0: sb          $t4, 0x17($s2)
    MEM_B(0X17, ctx->r18) = ctx->r12;
    after_36:
    // 0x800D6DB4: lbu         $a1, 0x17($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X17);
L_800D6DB8:
    // 0x800D6DB8: slti        $at, $a1, 0xE
    ctx->r1 = SIGNED(ctx->r5) < 0XE ? 1 : 0;
    // 0x800D6DBC: bne         $at, $zero, L_800D6F00
    if (ctx->r1 != 0) {
        // 0x800D6DC0: sll         $t1, $a1, 2
        ctx->r9 = S32(ctx->r5 << 2);
            goto L_800D6F00;
    }
    // 0x800D6DC0: sll         $t1, $a1, 2
    ctx->r9 = S32(ctx->r5 << 2);
    // 0x800D6DC4: lui         $t5, 0x8011
    ctx->r13 = S32(0X8011 << 16);
    // 0x800D6DC8: addu        $t5, $t5, $t1
    ctx->r13 = ADD32(ctx->r13, ctx->r9);
    // 0x800D6DCC: lw          $t5, 0x6D74($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D74);
    // 0x800D6DD0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6DD4: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    // 0x800D6DD8: jal         0x80002BE4
    // 0x800D6DDC: sb          $t5, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r13;
    syDmaLoadOverlay(rdram, ctx);
        goto after_37;
    // 0x800D6DDC: sb          $t5, 0x9($s2)
    MEM_B(0X9, ctx->r18) = ctx->r13;
    after_37:
    // 0x800D6DE0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6DE4: jal         0x80002BE4
    // 0x800D6DE8: addiu       $a0, $a0, 0x6C5C
    ctx->r4 = ADD32(ctx->r4, 0X6C5C);
    syDmaLoadOverlay(rdram, ctx);
        goto after_38;
    // 0x800D6DE8: addiu       $a0, $a0, 0x6C5C
    ctx->r4 = ADD32(ctx->r4, 0X6C5C);
    after_38:
    // 0x800D6DEC: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x800D6DF0: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6DF4: jal         0x80132310
    // 0x800D6DF8: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
    sc1PChallengerStartScene(rdram, ctx);
        goto after_39;
    // 0x800D6DF8: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
    after_39:
    // 0x800D6DFC: lbu         $t8, 0x13($s2)
    ctx->r24 = MEM_BU(ctx->r18, 0X13);
    // 0x800D6E00: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6E04: addiu       $a0, $a0, 0x6D34
    ctx->r4 = ADD32(ctx->r4, 0X6D34);
    // 0x800D6E08: multu       $t8, $s5
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6E0C: mflo        $t9
    ctx->r25 = lo;
    // 0x800D6E10: addu        $t6, $s4, $t9
    ctx->r14 = ADD32(ctx->r20, ctx->r25);
    // 0x800D6E14: jal         0x80002BE4
    // 0x800D6E18: sb          $zero, 0x2B($t6)
    MEM_B(0X2B, ctx->r14) = 0;
    syDmaLoadOverlay(rdram, ctx);
        goto after_40;
    // 0x800D6E18: sb          $zero, 0x2B($t6)
    MEM_B(0X2B, ctx->r14) = 0;
    after_40:
    // 0x800D6E1C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6E20: jal         0x80002BE4
    // 0x800D6E24: addiu       $a0, $a0, 0x6D10
    ctx->r4 = ADD32(ctx->r4, 0X6D10);
    syDmaLoadOverlay(rdram, ctx);
        goto after_41;
    // 0x800D6E24: addiu       $a0, $a0, 0x6D10
    ctx->r4 = ADD32(ctx->r4, 0X6D10);
    after_41:
    // 0x800D6E28: jal         0x80190FD8
    // 0x800D6E2C: nop

    sc1PGameStartScene(rdram, ctx);
        goto after_42;
    // 0x800D6E2C: nop

    after_42:
    // 0x800D6E30: lbu         $t0, 0x12($s2)
    ctx->r8 = MEM_BU(ctx->r18, 0X12);
    // 0x800D6E34: addiu       $t3, $zero, 0x8
    ctx->r11 = ADD32(0, 0X8);
    // 0x800D6E38: beql        $t0, $zero, L_800D6E50
    if (ctx->r8 == 0) {
        // 0x800D6E3C: lbu         $t2, 0x13($s2)
        ctx->r10 = MEM_BU(ctx->r18, 0X13);
            goto L_800D6E50;
    }
    goto skip_7;
    // 0x800D6E3C: lbu         $t2, 0x13($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X13);
    skip_7:
    // 0x800D6E40: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6E44: b           L_800D6FAC
    // 0x800D6E48: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
        goto L_800D6FAC;
    // 0x800D6E48: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
    // 0x800D6E4C: lbu         $t2, 0x13($s2)
    ctx->r10 = MEM_BU(ctx->r18, 0X13);
L_800D6E50:
    // 0x800D6E50: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800D6E54: multu       $t2, $s5
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800D6E58: mflo        $t4
    ctx->r12 = lo;
    // 0x800D6E5C: addu        $t1, $s4, $t4
    ctx->r9 = ADD32(ctx->r20, ctx->r12);
    // 0x800D6E60: lb          $t5, 0x2B($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X2B);
    // 0x800D6E64: beql        $t5, $at, L_800D6ED0
    if (ctx->r13 == ctx->r1) {
        // 0x800D6E68: lbu         $v0, 0x43($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X43);
            goto L_800D6ED0;
    }
    goto skip_8;
    // 0x800D6E68: lbu         $v0, 0x43($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X43);
    skip_8:
    // 0x800D6E6C: lw          $t7, 0x14($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X14);
    // 0x800D6E70: lui         $t8, 0x800A
    ctx->r24 = S32(0X800A << 16);
    // 0x800D6E74: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x800D6E78: beql        $t7, $zero, L_800D6ED0
    if (ctx->r15 == 0) {
        // 0x800D6E7C: lbu         $v0, 0x43($s2)
        ctx->r2 = MEM_BU(ctx->r18, 0X43);
            goto L_800D6ED0;
    }
    goto skip_9;
    // 0x800D6E7C: lbu         $v0, 0x43($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X43);
    skip_9:
    // 0x800D6E80: lbu         $t9, 0x17($s2)
    ctx->r25 = MEM_BU(ctx->r18, 0X17);
    // 0x800D6E84: lbu         $t8, 0x3FC3($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X3FC3);
    // 0x800D6E88: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6E8C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800D6E90: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x800D6E94: sb          $t8, 0x43($s2)
    MEM_B(0X43, ctx->r18) = ctx->r24;
    // 0x800D6E98: lw          $t0, 0x6D84($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6D84);
    // 0x800D6E9C: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    // 0x800D6EA0: jal         0x80002BE4
    // 0x800D6EA4: sb          $t0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r8;
    syDmaLoadOverlay(rdram, ctx);
        goto after_43;
    // 0x800D6EA4: sb          $t0, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r8;
    after_43:
    // 0x800D6EA8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6EAC: jal         0x80002BE4
    // 0x800D6EB0: addiu       $a0, $a0, 0x6CA4
    ctx->r4 = ADD32(ctx->r4, 0X6CA4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_44;
    // 0x800D6EB0: addiu       $a0, $a0, 0x6CA4
    ctx->r4 = ADD32(ctx->r4, 0X6CA4);
    after_44:
    // 0x800D6EB4: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x800D6EB8: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6EBC: jal         0x801323F8
    // 0x800D6EC0: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
    LOOKUP_FUNC(0x801323F8)(rdram, ctx);
        goto after_45;
    // 0x800D6EC0: sb          $t3, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r11;
    after_45:
    // 0x800D6EC4: b           L_800D6EE4
    // 0x800D6EC8: lbu         $t4, 0x17($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X17);
        goto L_800D6EE4;
    // 0x800D6EC8: lbu         $t4, 0x17($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X17);
    // 0x800D6ECC: lbu         $v0, 0x43($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X43);
L_800D6ED0:
    // 0x800D6ED0: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x800D6ED4: beq         $at, $zero, L_800D6EE0
    if (ctx->r1 == 0) {
        // 0x800D6ED8: addiu       $t2, $v0, 0x2
        ctx->r10 = ADD32(ctx->r2, 0X2);
            goto L_800D6EE0;
    }
    // 0x800D6ED8: addiu       $t2, $v0, 0x2
    ctx->r10 = ADD32(ctx->r2, 0X2);
    // 0x800D6EDC: sb          $t2, 0x43($s2)
    MEM_B(0X43, ctx->r18) = ctx->r10;
L_800D6EE0:
    // 0x800D6EE0: lbu         $t4, 0x17($s2)
    ctx->r12 = MEM_BU(ctx->r18, 0X17);
L_800D6EE4:
    // 0x800D6EE4: addiu       $at, $zero, 0xE
    ctx->r1 = ADD32(0, 0XE);
    // 0x800D6EE8: addiu       $t1, $zero, 0x35
    ctx->r9 = ADD32(0, 0X35);
    // 0x800D6EEC: bne         $t4, $at, L_800D6F00
    if (ctx->r12 != ctx->r1) {
        // 0x800D6EF0: addiu       $t5, $zero, 0x13
        ctx->r13 = ADD32(0, 0X13);
            goto L_800D6F00;
    }
    // 0x800D6EF0: addiu       $t5, $zero, 0x13
    ctx->r13 = ADD32(0, 0X13);
    // 0x800D6EF4: sb          $t1, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r9;
    // 0x800D6EF8: b           L_800D6FAC
    // 0x800D6EFC: sb          $t5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r13;
        goto L_800D6FAC;
    // 0x800D6EFC: sb          $t5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r13;
L_800D6F00:
    // 0x800D6F00: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x800D6F04: lbu         $t7, 0x4937($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4937);
    // 0x800D6F08: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x800D6F0C: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x800D6F10: bnel        $t8, $zero, L_800D6FA4
    if (ctx->r24 != 0) {
        // 0x800D6F14: addiu       $t7, $zero, 0x1B
        ctx->r15 = ADD32(0, 0X1B);
            goto L_800D6FA4;
    }
    goto skip_10;
    // 0x800D6F14: addiu       $t7, $zero, 0x1B
    ctx->r15 = ADD32(0, 0X1B);
    skip_10:
    // 0x800D6F18: lhu         $t9, 0x4ABC($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X4ABC);
    // 0x800D6F1C: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800D6F20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6F24: andi        $t6, $t9, 0xFF
    ctx->r14 = ctx->r25 & 0XFF;
    // 0x800D6F28: bne         $t6, $at, L_800D6FA0
    if (ctx->r14 != ctx->r1) {
        // 0x800D6F2C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800D6FA0;
    }
    // 0x800D6F2C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D6F30: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D6F34: addiu       $v0, $v0, 0x44E0
    ctx->r2 = ADD32(ctx->r2, 0X44E0);
    // 0x800D6F38: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
L_800D6F3C:
    // 0x800D6F3C: lbu         $t0, 0x479($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X479);
    // 0x800D6F40: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D6F44: sllv        $t2, $t3, $a2
    ctx->r10 = S32(ctx->r11 << (ctx->r6 & 31));
    // 0x800D6F48: beql        $t0, $zero, L_800D6F5C
    if (ctx->r8 == 0) {
        // 0x800D6F4C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800D6F5C;
    }
    goto skip_11;
    // 0x800D6F4C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_11:
    // 0x800D6F50: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
    // 0x800D6F54: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800D6F58: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800D6F5C:
    // 0x800D6F5C: bne         $a2, $a0, L_800D6F3C
    if (ctx->r6 != ctx->r4) {
        // 0x800D6F60: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_800D6F3C;
    }
    // 0x800D6F60: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x800D6F64: andi        $t4, $v1, 0x36F
    ctx->r12 = ctx->r3 & 0X36F;
    // 0x800D6F68: addiu       $at, $zero, 0x36F
    ctx->r1 = ADD32(0, 0X36F);
    // 0x800D6F6C: bne         $t4, $at, L_800D6FA0
    if (ctx->r12 != ctx->r1) {
        // 0x800D6F70: addiu       $t1, $zero, 0x4
        ctx->r9 = ADD32(0, 0X4);
            goto L_800D6FA0;
    }
    // 0x800D6F70: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x800D6F74: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6F78: sb          $t1, 0x2($s2)
    MEM_B(0X2, ctx->r18) = ctx->r9;
    // 0x800D6F7C: jal         0x80002BE4
    // 0x800D6F80: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    syDmaLoadOverlay(rdram, ctx);
        goto after_46;
    // 0x800D6F80: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    after_46:
    // 0x800D6F84: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800D6F88: jal         0x80002BE4
    // 0x800D6F8C: addiu       $a0, $a0, 0x6CA4
    ctx->r4 = ADD32(ctx->r4, 0X6CA4);
    syDmaLoadOverlay(rdram, ctx);
        goto after_47;
    // 0x800D6F8C: addiu       $a0, $a0, 0x6CA4
    ctx->r4 = ADD32(ctx->r4, 0X6CA4);
    after_47:
    // 0x800D6F90: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x800D6F94: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6F98: jal         0x801323F8
    // 0x800D6F9C: sb          $t5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r13;
    LOOKUP_FUNC(0x801323F8)(rdram, ctx);
        goto after_48;
    // 0x800D6F9C: sb          $t5, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r13;
    after_48:
L_800D6FA0:
    // 0x800D6FA0: addiu       $t7, $zero, 0x1B
    ctx->r15 = ADD32(0, 0X1B);
L_800D6FA4:
    // 0x800D6FA4: sb          $fp, 0x1($s2)
    MEM_B(0X1, ctx->r18) = ctx->r30;
    // 0x800D6FA8: sb          $t7, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r15;
L_800D6FAC:
    // 0x800D6FAC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800D6FB0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800D6FB4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800D6FB8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800D6FBC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800D6FC0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800D6FC4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800D6FC8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800D6FCC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800D6FD0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800D6FD4: jr          $ra
    // 0x800D6FD8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800D6FD8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_ovl8_80374D5C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80374D5C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80374D60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80374D64: beq         $a1, $zero, L_80374D8C
    if (ctx->r5 == 0) {
        // 0x80374D68: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_80374D8C;
    }
    // 0x80374D68: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80374D6C: lw          $v1, 0x38($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X38);
    // 0x80374D70: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80374D74: lw          $t9, 0xEC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XEC);
    // 0x80374D78: lh          $t6, 0xE8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE8);
    // 0x80374D7C: jalr        $t9
    // 0x80374D80: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80374D80: addu        $a0, $t6, $v1
    ctx->r4 = ADD32(ctx->r14, ctx->r3);
    after_0:
    // 0x80374D84: b           L_80374DA8
    // 0x80374D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80374DA8;
    // 0x80374D88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80374D8C:
    // 0x80374D8C: lw          $v1, 0x38($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X38);
    // 0x80374D90: lw          $v0, 0x58($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X58);
    // 0x80374D94: lw          $t9, 0xF4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XF4);
    // 0x80374D98: lh          $t7, 0xF0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XF0);
    // 0x80374D9C: jalr        $t9
    // 0x80374DA0: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80374DA0: addu        $a0, $t7, $v1
    ctx->r4 = ADD32(ctx->r15, ctx->r3);
    after_1:
    // 0x80374DA4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80374DA8:
    // 0x80374DA8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80374DAC: jr          $ra
    // 0x80374DB0: nop

    return;
    // 0x80374DB0: nop

;}
RECOMP_FUNC void SC1PGameBossWallpaper2ProcUpdate1(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80191F28: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x80191F2C: lw          $t7, 0x38EC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X38EC);
    // 0x80191F30: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80191F34: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x80191F38: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80191F3C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x80191F40: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80191F44: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x80191F48: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80191F4C: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80191F50: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80191F54: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80191F58: lw          $t0, 0x6C($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X6C);
    // 0x80191F5C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80191F60: slti        $at, $t0, 0x10F
    ctx->r1 = SIGNED(ctx->r8) < 0X10F ? 1 : 0;
    // 0x80191F64: bnel        $at, $zero, L_80191F80
    if (ctx->r1 != 0) {
        // 0x80191F68: sw          $t1, 0x7C($a0)
        MEM_W(0X7C, ctx->r4) = ctx->r9;
            goto L_80191F80;
    }
    goto skip_0;
    // 0x80191F68: sw          $t1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r9;
    skip_0:
    // 0x80191F6C: jal         0x80191AEC
    // 0x80191F70: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    SC1PGameBossWallpaper3ProcUpdate0(rdram, ctx);
        goto after_0;
    // 0x80191F70: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    after_0:
    // 0x80191F74: b           L_80191F84
    // 0x80191F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80191F84;
    // 0x80191F78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80191F7C: sw          $t1, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r9;
L_80191F80:
    // 0x80191F80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80191F84:
    // 0x80191F84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80191F88: jr          $ra
    // 0x80191F8C: nop

    return;
    // 0x80191F8C: nop

;}
RECOMP_FUNC void mvOpeningYamabukiMakeWallpaper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B58: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131B5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131B60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131B64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131B68: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80131B6C: jal         0x80009968
    // 0x80131B70: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131B70: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131B74: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131B78: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131B7C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131B80: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131B84: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131B88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131B8C: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    // 0x80131B90: jal         0x80009DF4
    // 0x80131B94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131B94: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131B98: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131B9C: lw          $t7, 0x2658($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2658);
    // 0x80131BA0: lui         $t8, 0x4
    ctx->r24 = S32(0X4 << 16);
    // 0x80131BA4: addiu       $t8, $t8, -0x11A8
    ctx->r24 = ADD32(ctx->r24, -0X11A8);
    // 0x80131BA8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131BAC: jal         0x800CCFDC
    // 0x80131BB0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80131BB0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x80131BB4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131BB8: nop

    // 0x80131BBC: swc1        $f0, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f0.u32l;
    // 0x80131BC0: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80131BC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131BC8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131BCC: jr          $ra
    // 0x80131BD0: nop

    return;
    // 0x80131BD0: nop

;}
RECOMP_FUNC void ftMainUpdateDamageStatFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E2D44: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800E2D48: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800E2D4C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800E2D50: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800E2D54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800E2D58: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800E2D5C: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x800E2D60: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800E2D64: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x800E2D68: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800E2D6C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800E2D70: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800E2D74: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800E2D78: jal         0x800E26BC
    // 0x800E2D7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ftMainSetHitInteractStats(rdram, ctx);
        goto after_0;
    // 0x800E2D7C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_0:
    // 0x800E2D80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2D84: jal         0x800EA40C
    // 0x800E2D88: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    ftParamGetCapturedDamage(rdram, ctx);
        goto after_1;
    // 0x800E2D88: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    after_1:
    // 0x800E2D8C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x800E2D90: lw          $t6, 0x7B0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X7B0);
    // 0x800E2D94: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E2D98: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800E2D9C: beql        $at, $zero, L_800E2DAC
    if (ctx->r1 == 0) {
        // 0x800E2DA0: lw          $t7, 0x5AC($s0)
        ctx->r15 = MEM_W(ctx->r16, 0X5AC);
            goto L_800E2DAC;
    }
    goto skip_0;
    // 0x800E2DA0: lw          $t7, 0x5AC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X5AC);
    skip_0:
    // 0x800E2DA4: sw          $v0, 0x7B0($s1)
    MEM_W(0X7B0, ctx->r17) = ctx->r2;
    // 0x800E2DA8: lw          $t7, 0x5AC($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X5AC);
L_800E2DAC:
    // 0x800E2DAC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800E2DB0: bnel        $a2, $t7, L_800E2EC8
    if (ctx->r6 != ctx->r15) {
        // 0x800E2DB4: addiu       $s0, $sp, 0x3C
        ctx->r16 = ADD32(ctx->r29, 0X3C);
            goto L_800E2EC8;
    }
    goto skip_1;
    // 0x800E2DB4: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    skip_1:
    // 0x800E2DB8: lw          $t8, 0x5B4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X5B4);
    // 0x800E2DBC: bnel        $a2, $t8, L_800E2EC8
    if (ctx->r6 != ctx->r24) {
        // 0x800E2DC0: addiu       $s0, $sp, 0x3C
        ctx->r16 = ADD32(ctx->r29, 0X3C);
            goto L_800E2EC8;
    }
    goto skip_2;
    // 0x800E2DC0: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    skip_2:
    // 0x800E2DC4: lw          $t9, 0x5B8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X5B8);
    // 0x800E2DC8: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x800E2DCC: bnel        $a2, $t9, L_800E2EC8
    if (ctx->r6 != ctx->r25) {
        // 0x800E2DD0: addiu       $s0, $sp, 0x3C
        ctx->r16 = ADD32(ctx->r29, 0X3C);
            goto L_800E2EC8;
    }
    goto skip_3;
    // 0x800E2DD0: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    skip_3:
    // 0x800E2DD4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800E2DD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2DDC: bnel        $a2, $t1, L_800E2EC8
    if (ctx->r6 != ctx->r9) {
        // 0x800E2DE0: addiu       $s0, $sp, 0x3C
        ctx->r16 = ADD32(ctx->r29, 0X3C);
            goto L_800E2EC8;
    }
    goto skip_4;
    // 0x800E2DE0: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    skip_4:
    // 0x800E2DE4: jal         0x800E2CC0
    // 0x800E2DE8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    ftMainCheckGetUpdateDamage(rdram, ctx);
        goto after_2;
    // 0x800E2DE8: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    after_2:
    // 0x800E2DEC: beq         $v0, $zero, L_800E2E9C
    if (ctx->r2 == 0) {
        // 0x800E2DF0: addiu       $a2, $zero, 0x1
        ctx->r6 = ADD32(0, 0X1);
            goto L_800E2E9C;
    }
    // 0x800E2DF0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800E2DF4: lw          $t2, 0x278($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X278);
    // 0x800E2DF8: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800E2DFC: addiu       $a3, $a3, 0x11C0
    ctx->r7 = ADD32(ctx->r7, 0X11C0);
    // 0x800E2E00: beq         $t2, $zero, L_800E2E14
    if (ctx->r10 == 0) {
        // 0x800E2E04: lui         $t4, 0x8013
        ctx->r12 = S32(0X8013 << 16);
            goto L_800E2E14;
    }
    // 0x800E2E04: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800E2E08: lbu         $a0, 0x281($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X281);
    // 0x800E2E0C: b           L_800E2E1C
    // 0x800E2E10: lw          $v1, 0x284($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X284);
        goto L_800E2E1C;
    // 0x800E2E10: lw          $v1, 0x284($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X284);
L_800E2E14:
    // 0x800E2E14: lbu         $a0, 0xD($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0XD);
    // 0x800E2E18: lw          $v1, 0x18($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X18);
L_800E2E1C:
    // 0x800E2E1C: lw          $a1, 0x0($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X0);
    // 0x800E2E20: addiu       $t4, $t4, 0x11C8
    ctx->r12 = ADD32(ctx->r12, 0X11C8);
    // 0x800E2E24: slti        $at, $a1, 0xA
    ctx->r1 = SIGNED(ctx->r5) < 0XA ? 1 : 0;
    // 0x800E2E28: beq         $at, $zero, L_800E2E68
    if (ctx->r1 == 0) {
        // 0x800E2E2C: sll         $t3, $a1, 3
        ctx->r11 = S32(ctx->r5 << 3);
            goto L_800E2E68;
    }
    // 0x800E2E2C: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x800E2E30: subu        $t3, $t3, $a1
    ctx->r11 = SUB32(ctx->r11, ctx->r5);
    // 0x800E2E34: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800E2E38: addu        $v0, $t3, $t4
    ctx->r2 = ADD32(ctx->r11, ctx->r12);
    // 0x800E2E3C: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800E2E40: sw          $s2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r18;
    // 0x800E2E44: lw          $t5, 0x68($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X68);
    // 0x800E2E48: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x800E2E4C: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x800E2E50: sb          $a0, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r4;
    // 0x800E2E54: sw          $v1, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r3;
    // 0x800E2E58: sw          $t6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r14;
    // 0x800E2E5C: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800E2E60: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800E2E64: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_800E2E68:
    // 0x800E2E68: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x800E2E6C: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800E2E70: jal         0x800EA98C
    // 0x800E2E74: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    ftParamUpdatePlayerBattleStats(rdram, ctx);
        goto after_3;
    // 0x800E2E74: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    after_3:
    // 0x800E2E78: lw          $a2, 0x3C($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X3C);
    // 0x800E2E7C: lw          $a0, 0x50($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X50);
    // 0x800E2E80: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x800E2E84: sll         $a2, $a2, 11
    ctx->r6 = S32(ctx->r6 << 11);
    // 0x800E2E88: srl         $a2, $a2, 26
    ctx->r6 = S32(U32(ctx->r6) >> 26);
    // 0x800E2E8C: jal         0x800EA614
    // 0x800E2E90: lhu         $a3, 0x40($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X40);
    ftParamUpdateStaleQueue(rdram, ctx);
        goto after_4;
    // 0x800E2E90: lhu         $a3, 0x40($s2)
    ctx->r7 = MEM_HU(ctx->r18, 0X40);
    after_4:
    // 0x800E2E94: b           L_800E2EE4
    // 0x800E2E98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800E2EE4;
    // 0x800E2E98: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800E2E9C:
    // 0x800E2E9C: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
    // 0x800E2EA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2EA4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800E2EA8: jal         0x800F0A90
    // 0x800E2EAC: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    gmCollisionGetFighterAttackDamagePosition(rdram, ctx);
        goto after_5;
    // 0x800E2EAC: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    after_5:
    // 0x800E2EB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2EB4: jal         0x80100BF0
    // 0x800E2EB8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_6;
    // 0x800E2EB8: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_6:
    // 0x800E2EBC: b           L_800E2EE4
    // 0x800E2EC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800E2EE4;
    // 0x800E2EC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800E2EC4: addiu       $s0, $sp, 0x3C
    ctx->r16 = ADD32(ctx->r29, 0X3C);
L_800E2EC8:
    // 0x800E2EC8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2ECC: jal         0x800F0A90
    // 0x800E2ED0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    gmCollisionGetFighterAttackDamagePosition(rdram, ctx);
        goto after_7;
    // 0x800E2ED0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    after_7:
    // 0x800E2ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800E2ED8: jal         0x80100BF0
    // 0x800E2EDC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    efManagerSetOffMakeEffect(rdram, ctx);
        goto after_8;
    // 0x800E2EDC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    after_8:
    // 0x800E2EE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800E2EE4:
    // 0x800E2EE4: jal         0x800E2C24
    // 0x800E2EE8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    ftMainPlayHitSFX(rdram, ctx);
        goto after_9;
    // 0x800E2EE8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_9:
    // 0x800E2EEC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800E2EF0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800E2EF4: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800E2EF8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800E2EFC: jr          $ra
    // 0x800E2F00: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800E2F00: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void itBombHeiExplodeMapSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177B78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177B7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177B80: jal         0x80177208
    // 0x80177B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    itBombHeiCommonSetHitStatusNormal(rdram, ctx);
        goto after_0;
    // 0x80177B84: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80177B88: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80177B8C: addiu       $a1, $a1, -0x6034
    ctx->r5 = ADD32(ctx->r5, -0X6034);
    // 0x80177B90: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80177B94: jal         0x80172EC8
    // 0x80177B98: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80177B98: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x80177B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177BA0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177BA4: jr          $ra
    // 0x80177BA8: nop

    return;
    // 0x80177BA8: nop

;}
RECOMP_FUNC void itMarumineExplodeMakeEffectGotoSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801837A0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801837A4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801837A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801837AC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x801837B0: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x801837B4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801837B8: sw          $zero, 0x248($v1)
    MEM_W(0X248, ctx->r3) = 0;
    // 0x801837BC: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x801837C0: jal         0x801005C8
    // 0x801837C4: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801837C4: addiu       $a0, $v0, 0x1C
    ctx->r4 = ADD32(ctx->r2, 0X1C);
    after_0:
    // 0x801837C8: beq         $v0, $zero, L_801837EC
    if (ctx->r2 == 0) {
        // 0x801837CC: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801837EC;
    }
    // 0x801837CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801837D0: lwc1        $f0, -0x3110($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3110);
    // 0x801837D4: lw          $t6, 0x5C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X5C);
    // 0x801837D8: swc1        $f0, 0x1C($t6)
    MEM_W(0X1C, ctx->r14) = ctx->f0.u32l;
    // 0x801837DC: lw          $t7, 0x5C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X5C);
    // 0x801837E0: swc1        $f0, 0x20($t7)
    MEM_W(0X20, ctx->r15) = ctx->f0.u32l;
    // 0x801837E4: lw          $t8, 0x5C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X5C);
    // 0x801837E8: swc1        $f0, 0x24($t8)
    MEM_W(0X24, ctx->r24) = ctx->f0.u32l;
L_801837EC:
    // 0x801837EC: jal         0x801008F4
    // 0x801837F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    efManagerQuakeMakeEffect(rdram, ctx);
        goto after_1;
    // 0x801837F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x801837F4: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x801837F8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x801837FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80183800: sb          $t9, 0x54($t0)
    MEM_B(0X54, ctx->r8) = ctx->r25;
    // 0x80183804: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80183808: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018380C: jal         0x8017275C
    // 0x80183810: sh          $t1, 0x156($t2)
    MEM_H(0X156, ctx->r10) = ctx->r9;
    itMainRefreshAttackColl(rdram, ctx);
        goto after_2;
    // 0x80183810: sh          $t1, 0x156($t2)
    MEM_H(0X156, ctx->r10) = ctx->r9;
    after_2:
    // 0x80183814: jal         0x80183A20
    // 0x80183818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    itMarumineExplodeSetStatus(rdram, ctx);
        goto after_3;
    // 0x80183818: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8018381C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80183820: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80183824: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80183828: jr          $ra
    // 0x8018382C: nop

    return;
    // 0x8018382C: nop

;}
RECOMP_FUNC void ftNessSpecialLwEndSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155AC8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80155ACC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155AD0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80155AD4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x80155AD8: addiu       $a1, $zero, 0xF0
    ctx->r5 = ADD32(0, 0XF0);
    // 0x80155ADC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80155AE0: jal         0x800E6F24
    // 0x80155AE4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80155AE4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x80155AE8: jal         0x800E0830
    // 0x80155AEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x80155AEC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80155AF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80155AF4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80155AF8: jr          $ra
    // 0x80155AFC: nop

    return;
    // 0x80155AFC: nop

;}
RECOMP_FUNC void ftKirbySpecialNLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162774: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80162778: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8016277C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80162780: jal         0x800DDDDC
    // 0x80162784: addiu       $a1, $a1, 0x2B04
    ctx->r5 = ADD32(ctx->r5, 0X2B04);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80162784: addiu       $a1, $a1, 0x2B04
    ctx->r5 = ADD32(ctx->r5, 0X2B04);
    after_0:
    // 0x80162788: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016278C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80162790: jr          $ra
    // 0x80162794: nop

    return;
    // 0x80162794: nop

;}
RECOMP_FUNC void ftCommonFallProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013F9A0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013F9A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013F9A8: jal         0x80150F08
    // 0x8013F9AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftCommonSpecialAirCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8013F9AC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013F9B0: bnel        $v0, $zero, L_8013F9D4
    if (ctx->r2 != 0) {
        // 0x8013F9B4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013F9D4;
    }
    goto skip_0;
    // 0x8013F9B4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013F9B8: jal         0x80150B00
    // 0x8013F9BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonAttackAirCheckInterruptCommon(rdram, ctx);
        goto after_1;
    // 0x8013F9BC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x8013F9C0: bnel        $v0, $zero, L_8013F9D4
    if (ctx->r2 != 0) {
        // 0x8013F9C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8013F9D4;
    }
    goto skip_1;
    // 0x8013F9C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x8013F9C8: jal         0x8014019C
    // 0x8013F9CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftCommonJumpAerialCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x8013F9CC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x8013F9D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8013F9D4:
    // 0x8013F9D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8013F9D8: jr          $ra
    // 0x8013F9DC: nop

    return;
    // 0x8013F9DC: nop

;}
RECOMP_FUNC void ftKirbyCopySamusSpecialNStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80156F54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80156F58: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80156F5C: lwc1        $f6, 0x78($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80156F60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80156F64: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80156F68: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80156F6C: nop

    // 0x80156F70: bc1fl       L_80156FC0
    if (!c1cs) {
        // 0x80156F74: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80156FC0;
    }
    goto skip_0;
    // 0x80156F74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80156F78: lw          $t6, 0x14C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14C);
    // 0x80156F7C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80156F80: bnel        $t6, $at, L_80156F9C
    if (ctx->r14 != ctx->r1) {
        // 0x80156F84: lw          $t7, 0xB18($v0)
        ctx->r15 = MEM_W(ctx->r2, 0XB18);
            goto L_80156F9C;
    }
    goto skip_1;
    // 0x80156F84: lw          $t7, 0xB18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB18);
    skip_1:
    // 0x80156F88: jal         0x80157610
    // 0x80156F8C: nop

    ftKirbyCopySamusSpecialAirNEndSetStatus(rdram, ctx);
        goto after_0;
    // 0x80156F8C: nop

    after_0:
    // 0x80156F90: b           L_80156FC0
    // 0x80156F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80156FC0;
    // 0x80156F94: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80156F98: lw          $t7, 0xB18($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XB18);
L_80156F9C:
    // 0x80156F9C: beq         $t7, $zero, L_80156FB4
    if (ctx->r15 == 0) {
        // 0x80156FA0: nop
    
            goto L_80156FB4;
    }
    // 0x80156FA0: nop

    // 0x80156FA4: jal         0x801575C8
    // 0x80156FA8: nop

    ftKirbyCopySamusSpecialNEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x80156FA8: nop

    after_1:
    // 0x80156FAC: b           L_80156FC0
    // 0x80156FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80156FC0;
    // 0x80156FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80156FB4:
    // 0x80156FB4: jal         0x8015729C
    // 0x80156FB8: nop

    ftKirbyCopySamusSpecialNLoopSetStatus(rdram, ctx);
        goto after_2;
    // 0x80156FB8: nop

    after_2:
    // 0x80156FBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80156FC0:
    // 0x80156FC0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80156FC4: jr          $ra
    // 0x80156FC8: nop

    return;
    // 0x80156FC8: nop

;}
RECOMP_FUNC void n_alSynAllocVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D8E0: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002D8E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8002D8E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D8EC: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8002D8F0: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x8002D8F4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8002D8F8: sh          $t6, 0x16($a0)
    MEM_H(0X16, ctx->r4) = ctx->r14;
    // 0x8002D8FC: lbu         $t7, 0x4($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X4);
    // 0x8002D900: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x8002D904: sh          $t7, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r15;
    // 0x8002D908: lh          $t8, 0x2($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2);
    // 0x8002D90C: sh          $zero, 0x14($a0)
    MEM_H(0X14, ctx->r4) = 0;
    // 0x8002D910: sw          $zero, 0x8($a0)
    MEM_W(0X8, ctx->r4) = 0;
    // 0x8002D914: sh          $t8, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r24;
    // 0x8002D918: lh          $a1, 0x0($a1)
    ctx->r5 = MEM_H(ctx->r5, 0X0);
    // 0x8002D91C: jal         0x8002D7F0
    // 0x8002D920: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    _allocatePVoice(rdram, ctx);
        goto after_0;
    // 0x8002D920: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    after_0:
    // 0x8002D924: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D928: beql        $t9, $zero, L_8002DA04
    if (ctx->r25 == 0) {
        // 0x8002D92C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8002DA04;
    }
    goto skip_0;
    // 0x8002D92C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8002D930: beq         $v0, $zero, L_8002D9EC
    if (ctx->r2 == 0) {
        // 0x8002D934: lw          $t7, 0x2C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X2C);
            goto L_8002D9EC;
    }
    // 0x8002D934: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D938: addiu       $t0, $zero, 0x200
    ctx->r8 = ADD32(0, 0X200);
    // 0x8002D93C: sw          $t0, 0x88($t9)
    MEM_W(0X88, ctx->r25) = ctx->r8;
    // 0x8002D940: lw          $t1, 0x2C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D944: lw          $t2, 0x8($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X8);
    // 0x8002D948: sw          $zero, 0x8($t2)
    MEM_W(0X8, ctx->r10) = 0;
    // 0x8002D94C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D950: sw          $s0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r16;
    // 0x8002D954: lw          $t4, 0x2C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D958: jal         0x8002C618
    // 0x8002D95C: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    __n_allocParam(rdram, ctx);
        goto after_1;
    // 0x8002D95C: sw          $t4, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r12;
    after_1:
    // 0x8002D960: beq         $v0, $zero, L_8002D9A0
    if (ctx->r2 == 0) {
        // 0x8002D964: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002D9A0;
    }
    // 0x8002D964: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002D968: lui         $t5, 0x8004
    ctx->r13 = S32(0X8004 << 16);
    // 0x8002D96C: lw          $t5, -0x2CEC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2CEC);
    // 0x8002D970: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8002D974: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x8002D978: lw          $t6, 0x28($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X28);
    // 0x8002D97C: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x8002D980: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8002D984: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002D988: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D98C: lw          $t0, 0x88($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X88);
    // 0x8002D990: addiu       $t9, $t0, -0x40
    ctx->r25 = ADD32(ctx->r8, -0X40);
    // 0x8002D994: sw          $t9, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r25;
    // 0x8002D998: jal         0x8002A230
    // 0x8002D99C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    n_alEnvmixerParam(rdram, ctx);
        goto after_2;
    // 0x8002D99C: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    after_2:
L_8002D9A0:
    // 0x8002D9A0: jal         0x8002C618
    // 0x8002D9A4: nop

    __n_allocParam(rdram, ctx);
        goto after_3;
    // 0x8002D9A4: nop

    after_3:
    // 0x8002D9A8: beq         $v0, $zero, L_8002DA00
    if (ctx->r2 == 0) {
        // 0x8002D9AC: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_8002DA00;
    }
    // 0x8002D9AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8002D9B0: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8002D9B4: lw          $t1, -0x2CEC($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2CEC);
    // 0x8002D9B8: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D9BC: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x8002D9C0: lw          $t2, 0x28($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X28);
    // 0x8002D9C4: lw          $t4, 0x88($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X88);
    // 0x8002D9C8: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x8002D9CC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8002D9D0: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8002D9D4: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8002D9D8: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8002D9DC: jal         0x8002A230
    // 0x8002D9E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    n_alEnvmixerParam(rdram, ctx);
        goto after_4;
    // 0x8002D9E0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    after_4:
    // 0x8002D9E4: b           L_8002DA04
    // 0x8002D9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8002DA04;
    // 0x8002D9E8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002D9EC:
    // 0x8002D9EC: sw          $zero, 0x88($t7)
    MEM_W(0X88, ctx->r15) = 0;
    // 0x8002D9F0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D9F4: sw          $s0, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r16;
    // 0x8002D9F8: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D9FC: sw          $t0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r8;
L_8002DA00:
    // 0x8002DA00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8002DA04:
    // 0x8002DA04: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x8002DA08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002DA0C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8002DA10: jr          $ra
    // 0x8002DA14: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
    return;
    // 0x8002DA14: sltu        $v0, $zero, $v0
    ctx->r2 = 0 < ctx->r2 ? 1 : 0;
;}
RECOMP_FUNC void ftParamSetHammerParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E8744: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E8748: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E874C: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E8750: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800E8754: addiu       $a1, $zero, 0x15
    ctx->r5 = ADD32(0, 0X15);
    // 0x800E8758: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x800E875C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800E8760: beq         $v1, $at, L_800E8770
    if (ctx->r3 == ctx->r1) {
        // 0x800E8764: addiu       $at, $zero, 0x13
        ctx->r1 = ADD32(0, 0X13);
            goto L_800E8770;
    }
    // 0x800E8764: addiu       $at, $zero, 0x13
    ctx->r1 = ADD32(0, 0X13);
    // 0x800E8768: bne         $v1, $at, L_800E8788
    if (ctx->r3 != ctx->r1) {
        // 0x800E876C: nop
    
            goto L_800E8788;
    }
    // 0x800E876C: nop

L_800E8770:
    // 0x800E8770: jal         0x800E8EAC
    // 0x800E8774: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    ftParamSetModelPartDefaultID(rdram, ctx);
        goto after_0;
    // 0x800E8774: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800E8778: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800E877C: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x800E8780: jal         0x800E8EAC
    // 0x800E8784: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamSetModelPartDefaultID(rdram, ctx);
        goto after_1;
    // 0x800E8784: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
L_800E8788:
    // 0x800E8788: jal         0x800E7B54
    // 0x800E878C: nop

    ftParamTryUpdateItemMusic(rdram, ctx);
        goto after_2;
    // 0x800E878C: nop

    after_2:
    // 0x800E8790: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8794: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8798: jr          $ra
    // 0x800E879C: nop

    return;
    // 0x800E879C: nop

;}
RECOMP_FUNC void ftCommonRunProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013EE50: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8013EE54: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8013EE58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8013EE5C: jal         0x80151098
    // 0x8013EE60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    ftCommonSpecialNCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8013EE60: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x8013EE64: bnel        $v0, $zero, L_8013EED8
    if (ctx->r2 != 0) {
        // 0x8013EE68: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EED8;
    }
    goto skip_0;
    // 0x8013EE68: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013EE6C: jal         0x80149D80
    // 0x8013EE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonCatchCheckInterruptDashRun(rdram, ctx);
        goto after_1;
    // 0x8013EE70: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8013EE74: bnel        $v0, $zero, L_8013EED8
    if (ctx->r2 != 0) {
        // 0x8013EE78: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EED8;
    }
    goto skip_1;
    // 0x8013EE78: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8013EE7C: jal         0x8014F69C
    // 0x8013EE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAttackDashCheckInterruptCommon(rdram, ctx);
        goto after_2;
    // 0x8013EE80: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013EE84: bne         $v0, $zero, L_8013EED4
    if (ctx->r2 != 0) {
        // 0x8013EE88: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8013EED4;
    }
    // 0x8013EE88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013EE8C: jal         0x80148D2C
    // 0x8013EE90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    ftCommonGuardOnCheckInterruptDashRun(rdram, ctx);
        goto after_3;
    // 0x8013EE90: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_3:
    // 0x8013EE94: bnel        $v0, $zero, L_8013EED8
    if (ctx->r2 != 0) {
        // 0x8013EE98: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EED8;
    }
    goto skip_2;
    // 0x8013EE98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x8013EE9C: jal         0x8014E764
    // 0x8013EEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonAppealCheckInterruptCommon(rdram, ctx);
        goto after_4;
    // 0x8013EEA0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8013EEA4: bnel        $v0, $zero, L_8013EED8
    if (ctx->r2 != 0) {
        // 0x8013EEA8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EED8;
    }
    goto skip_3;
    // 0x8013EEA8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_3:
    // 0x8013EEAC: jal         0x8013F598
    // 0x8013EEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonKneeBendCheckInterruptRun(rdram, ctx);
        goto after_5;
    // 0x8013EEB0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8013EEB4: bnel        $v0, $zero, L_8013EED8
    if (ctx->r2 != 0) {
        // 0x8013EEB8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EED8;
    }
    goto skip_4;
    // 0x8013EEB8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_4:
    // 0x8013EEBC: jal         0x8013F248
    // 0x8013EEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonTurnRunCheckInterruptRun(rdram, ctx);
        goto after_6;
    // 0x8013EEC0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8013EEC4: bnel        $v0, $zero, L_8013EED8
    if (ctx->r2 != 0) {
        // 0x8013EEC8: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8013EED8;
    }
    goto skip_5;
    // 0x8013EEC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_5:
    // 0x8013EECC: jal         0x8013F0A0
    // 0x8013EED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonRunBrakeCheckInterruptRun(rdram, ctx);
        goto after_7;
    // 0x8013EED0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
L_8013EED4:
    // 0x8013EED4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8013EED8:
    // 0x8013EED8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8013EEDC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8013EEE0: jr          $ra
    // 0x8013EEE4: nop

    return;
    // 0x8013EEE4: nop

;}
RECOMP_FUNC void gcGetDObjDistFromEye(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014798: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x8001479C: lw          $t6, 0x6A58($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6A58);
    // 0x800147A0: lwc1        $f4, 0x1C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800147A4: lwc1        $f8, 0x20($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800147A8: lw          $v0, 0x74($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X74);
    // 0x800147AC: lwc1        $f16, 0x24($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800147B0: lwc1        $f6, 0x3C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3C);
    // 0x800147B4: lwc1        $f10, 0x40($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X40);
    // 0x800147B8: lwc1        $f18, 0x44($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X44);
    // 0x800147BC: sub.s       $f2, $f4, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800147C0: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800147C4: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800147C8: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800147CC: mul.s       $f6, $f12, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800147D0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800147D4: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800147D8: jr          $ra
    // 0x800147DC: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    return;
    // 0x800147DC: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
;}
RECOMP_FUNC void ftPikachuSpecialAirLwEndProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80152668: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015266C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80152670: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x80152674: jal         0x800DE6E4
    // 0x80152678: addiu       $a1, $a1, 0x268C
    ctx->r5 = ADD32(ctx->r5, 0X268C);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80152678: addiu       $a1, $a1, 0x268C
    ctx->r5 = ADD32(ctx->r5, 0X268C);
    after_0:
    // 0x8015267C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80152680: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80152684: jr          $ra
    // 0x80152688: nop

    return;
    // 0x80152688: nop

;}
RECOMP_FUNC void mnVSResultsMakeString(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133F6C: addiu       $sp, $sp, -0x198
    ctx->r29 = ADD32(ctx->r29, -0X198);
    // 0x80133F70: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x80133F74: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80133F78: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80133F7C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80133F80: addiu       $t7, $t7, -0x6C4C
    ctx->r15 = ADD32(ctx->r15, -0X6C4C);
    // 0x80133F84: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x80133F88: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x80133F8C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80133F90: lui         $s1, 0x8000
    ctx->r17 = S32(0X8000 << 16);
    // 0x80133F94: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80133F98: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80133F9C: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80133FA0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80133FA4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80133FA8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80133FAC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80133FB0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80133FB4: sdc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X40, ctx->r29);
    // 0x80133FB8: sdc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X38, ctx->r29);
    // 0x80133FBC: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x80133FC0: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x80133FC4: sw          $a3, 0x1A4($sp)
    MEM_W(0X1A4, ctx->r29) = ctx->r7;
    // 0x80133FC8: addiu       $t0, $t7, 0x6C
    ctx->r8 = ADD32(ctx->r15, 0X6C);
    // 0x80133FCC: addiu       $t6, $sp, 0x114
    ctx->r14 = ADD32(ctx->r29, 0X114);
L_80133FD0:
    // 0x80133FD0: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133FD4: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80133FD8: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133FDC: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80133FE0: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80133FE4: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80133FE8: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80133FEC: bne         $t7, $t0, L_80133FD0
    if (ctx->r15 != ctx->r8) {
        // 0x80133FF0: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80133FD0;
    }
    // 0x80133FF0: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80133FF4: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80133FF8: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80133FFC: addiu       $t2, $t2, -0x6BDC
    ctx->r10 = ADD32(ctx->r10, -0X6BDC);
    // 0x80134000: addiu       $t5, $t2, 0x6C
    ctx->r13 = ADD32(ctx->r10, 0X6C);
    // 0x80134004: addiu       $t1, $sp, 0xA4
    ctx->r9 = ADD32(ctx->r29, 0XA4);
    // 0x80134008: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
L_8013400C:
    // 0x8013400C: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80134010: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80134014: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80134018: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x8013401C: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80134020: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80134024: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80134028: bne         $t2, $t5, L_8013400C
    if (ctx->r10 != ctx->r13) {
        // 0x8013402C: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_8013400C;
    }
    // 0x8013402C: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80134030: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80134034: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80134038: addiu       $t7, $t7, -0x6B6C
    ctx->r15 = ADD32(ctx->r15, -0X6B6C);
    // 0x8013403C: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80134040: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80134044: addiu       $t0, $sp, 0x84
    ctx->r8 = ADD32(ctx->r29, 0X84);
    // 0x80134048: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x8013404C: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80134050: lw          $t8, 0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X8);
    // 0x80134054: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x80134058: lw          $t6, 0xC($t7)
    ctx->r14 = MEM_W(ctx->r15, 0XC);
    // 0x8013405C: sw          $t8, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r24;
    // 0x80134060: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x80134064: sw          $t6, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r14;
    // 0x80134068: lw          $t6, 0x14($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X14);
    // 0x8013406C: sw          $t8, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r24;
    // 0x80134070: lw          $t8, 0x18($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X18);
    // 0x80134074: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80134078: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8013407C: sw          $t8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->r24;
    // 0x80134080: lhu         $t8, 0x1C($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X1C);
    // 0x80134084: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134088: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x8013408C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x80134090: sw          $t6, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r14;
    // 0x80134094: jal         0x80009968
    // 0x80134098: sh          $t8, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r24;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80134098: sh          $t8, 0x1C($t0)
    MEM_H(0X1C, ctx->r8) = ctx->r24;
    after_0:
    // 0x8013409C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801340A0: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801340A4: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
    // 0x801340A8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x801340AC: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801340B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801340B4: addiu       $a2, $zero, 0x1D
    ctx->r6 = ADD32(0, 0X1D);
    // 0x801340B8: jal         0x80009DF4
    // 0x801340BC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801340BC: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_1:
    // 0x801340C0: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x801340C4: or          $s3, $s0, $zero
    ctx->r19 = ctx->r16 | 0;
    // 0x801340C8: lui         $at, 0x41D0
    ctx->r1 = S32(0X41D0 << 16);
    // 0x801340CC: beq         $t5, $zero, L_801341F8
    if (ctx->r13 == 0) {
        // 0x801340D0: andi        $a0, $t5, 0xFF
        ctx->r4 = ctx->r13 & 0XFF;
            goto L_801341F8;
    }
    // 0x801340D0: andi        $a0, $t5, 0xFF
    ctx->r4 = ctx->r13 & 0XFF;
    // 0x801340D4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x801340D8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801340DC: lui         $s5, 0x8014
    ctx->r21 = S32(0X8014 << 16);
    // 0x801340E0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x801340E4: addiu       $s5, $s5, -0x5FB8
    ctx->r21 = ADD32(ctx->r21, -0X5FB8);
    // 0x801340E8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x801340EC: lwc1        $f22, 0x1A8($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1A8);
    // 0x801340F0: addiu       $s7, $zero, -0x21
    ctx->r23 = ADD32(0, -0X21);
    // 0x801340F4: addiu       $s6, $sp, 0x110
    ctx->r22 = ADD32(ctx->r29, 0X110);
    // 0x801340F8: addiu       $s4, $zero, 0x1C
    ctx->r20 = ADD32(0, 0X1C);
L_801340FC:
    // 0x801340FC: slti        $at, $v0, 0x30
    ctx->r1 = SIGNED(ctx->r2) < 0X30 ? 1 : 0;
    // 0x80134100: bne         $at, $zero, L_80134124
    if (ctx->r1 != 0) {
        // 0x80134104: slti        $at, $v0, 0x3A
        ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
            goto L_80134124;
    }
    // 0x80134104: slti        $at, $v0, 0x3A
    ctx->r1 = SIGNED(ctx->r2) < 0X3A ? 1 : 0;
    // 0x80134108: beq         $at, $zero, L_80134124
    if (ctx->r1 == 0) {
        // 0x8013410C: addiu       $t2, $v0, -0x30
        ctx->r10 = ADD32(ctx->r2, -0X30);
            goto L_80134124;
    }
    // 0x8013410C: addiu       $t2, $v0, -0x30
    ctx->r10 = ADD32(ctx->r2, -0X30);
    // 0x80134110: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80134114: nop

    // 0x80134118: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013411C: b           L_801341E8
    // 0x80134120: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
        goto L_801341E8;
    // 0x80134120: add.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f6.fl;
L_80134124:
    // 0x80134124: jal         0x80133F1C
    // 0x80134128: nop

    mnVSResultsGetCharacterID(rdram, ctx);
        goto after_2;
    // 0x80134128: nop

    after_2:
    // 0x8013412C: bne         $v0, $s4, L_80134140
    if (ctx->r2 != ctx->r20) {
        // 0x80134130: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80134140;
    }
    // 0x80134130: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80134134: mul.s       $f8, $f26, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f22.fl);
    // 0x80134138: b           L_801341E8
    // 0x8013413C: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
        goto L_801341E8;
    // 0x8013413C: add.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f8.fl;
L_80134140:
    // 0x80134140: lw          $t0, 0x1A4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1A4);
    // 0x80134144: sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3 << 2);
    // 0x80134148: addiu       $t1, $sp, 0xA4
    ctx->r9 = ADD32(ctx->r29, 0XA4);
    // 0x8013414C: addu        $s2, $s1, $t1
    ctx->r18 = ADD32(ctx->r17, ctx->r9);
    // 0x80134150: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80134154: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x80134158: lw          $t4, 0x18($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X18);
    // 0x8013415C: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x80134160: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x80134164: addiu       $t6, $sp, 0x84
    ctx->r14 = ADD32(ctx->r29, 0X84);
    // 0x80134168: addu        $s0, $t7, $t6
    ctx->r16 = ADD32(ctx->r15, ctx->r14);
    // 0x8013416C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80134170: jal         0x800CCFDC
    // 0x80134174: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80134174: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_3:
    // 0x80134178: swc1        $f22, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f22.u32l;
    // 0x8013417C: bne         $s2, $s6, L_80134190
    if (ctx->r18 != ctx->r22) {
        // 0x80134180: swc1        $f20, 0x58($v0)
        MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
            goto L_80134190;
    }
    // 0x80134180: swc1        $f20, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f20.u32l;
    // 0x80134184: add.s       $f10, $f24, $f28
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f10.fl = ctx->f24.fl + ctx->f28.fl;
    // 0x80134188: b           L_80134194
    // 0x8013418C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
        goto L_80134194;
    // 0x8013418C: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
L_80134190:
    // 0x80134190: swc1        $f24, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f24.u32l;
L_80134194:
    // 0x80134194: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x80134198: and         $t5, $t8, $s7
    ctx->r13 = ctx->r24 & ctx->r23;
    // 0x8013419C: sh          $t5, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r13;
    // 0x801341A0: ori         $t2, $t5, 0x1
    ctx->r10 = ctx->r13 | 0X1;
    // 0x801341A4: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801341A8: lbu         $t1, 0x0($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X0);
    // 0x801341AC: addu        $t8, $sp, $s1
    ctx->r24 = ADD32(ctx->r29, ctx->r17);
    // 0x801341B0: sb          $t1, 0x60($v0)
    MEM_B(0X60, ctx->r2) = ctx->r9;
    // 0x801341B4: lbu         $t3, 0x1($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X1);
    // 0x801341B8: sb          $t3, 0x61($v0)
    MEM_B(0X61, ctx->r2) = ctx->r11;
    // 0x801341BC: lbu         $t4, 0x2($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X2);
    // 0x801341C0: sb          $t4, 0x62($v0)
    MEM_B(0X62, ctx->r2) = ctx->r12;
    // 0x801341C4: lbu         $t0, 0x3($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X3);
    // 0x801341C8: sb          $t0, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r8;
    // 0x801341CC: lbu         $t7, 0x4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X4);
    // 0x801341D0: sb          $t7, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r15;
    // 0x801341D4: lbu         $t6, 0x5($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X5);
    // 0x801341D8: sb          $t6, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r14;
    // 0x801341DC: lwc1        $f16, 0x114($t8)
    ctx->f16.u32l = MEM_W(ctx->r24, 0X114);
    // 0x801341E0: mul.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f22.fl);
    // 0x801341E4: add.s       $f20, $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f18.fl;
L_801341E8:
    // 0x801341E8: lbu         $a0, 0x1($s3)
    ctx->r4 = MEM_BU(ctx->r19, 0X1);
    // 0x801341EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x801341F0: bne         $a0, $zero, L_801340FC
    if (ctx->r4 != 0) {
        // 0x801341F4: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_801340FC;
    }
    // 0x801341F4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_801341F8:
    // 0x801341F8: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x801341FC: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x80134200: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x80134204: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x80134208: ldc1        $f26, 0x38($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X38);
    // 0x8013420C: ldc1        $f28, 0x40($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X40);
    // 0x80134210: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80134214: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80134218: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x8013421C: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80134220: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80134224: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80134228: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x8013422C: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80134230: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    // 0x80134234: jr          $ra
    // 0x80134238: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
    return;
    // 0x80134238: addiu       $sp, $sp, 0x198
    ctx->r29 = ADD32(ctx->r29, 0X198);
;}
RECOMP_FUNC void grInishieMakeGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109C0C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80109C10: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80109C14: jal         0x80109BD4
    // 0x80109C18: nop

    grInishieInitHeaders(rdram, ctx);
        goto after_0;
    // 0x80109C18: nop

    after_0:
    // 0x80109C1C: jal         0x801094A0
    // 0x80109C20: nop

    grInishieMakeScale(rdram, ctx);
        goto after_1;
    // 0x80109C20: nop

    after_1:
    // 0x80109C24: jal         0x80109774
    // 0x80109C28: nop

    grInishieMakePakkun(rdram, ctx);
        goto after_2;
    // 0x80109C28: nop

    after_2:
    // 0x80109C2C: jal         0x801099D4
    // 0x80109C30: nop

    grInishieMakePowerBlock(rdram, ctx);
        goto after_3;
    // 0x80109C30: nop

    after_3:
    // 0x80109C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80109C38: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80109C3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80109C40: jr          $ra
    // 0x80109C44: nop

    return;
    // 0x80109C44: nop

;}
RECOMP_FUNC void gcAddAObjForCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009010: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80009014: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80009018: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000901C: jal         0x80007E04
    // 0x80009020: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    gcGetAObjSetNextAlloc(rdram, ctx);
        goto after_0;
    // 0x80009020: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80009024: lbu         $t6, 0x27($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X27);
    // 0x80009028: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000902C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80009030: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009034: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80009038: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    // 0x8000903C: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x80009040: sb          $t6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r14;
    // 0x80009044: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x80009048: swc1        $f0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f0.u32l;
    // 0x8000904C: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x80009050: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x80009054: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x80009058: swc1        $f4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f4.u32l;
    // 0x8000905C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80009060: jal         0x80007EA0
    // 0x80009064: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    gcAppendAObjToCamera(rdram, ctx);
        goto after_1;
    // 0x80009064: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_1:
    // 0x80009068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000906C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80009070: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80009074: jr          $ra
    // 0x80009078: nop

    return;
    // 0x80009078: nop

;}
RECOMP_FUNC void efGroundMakeEffectID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011677C: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80116780: addiu       $t0, $t0, 0x1AD8
    ctx->r8 = ADD32(ctx->r8, 0X1AD8);
    // 0x80116784: lw          $t7, 0x18($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X18);
    // 0x80116788: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8011678C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80116790: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x80116794: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80116798: sll         $a2, $a0, 6
    ctx->r6 = S32(ctx->r4 << 6);
    // 0x8011679C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x801167A0: addiu       $t6, $t6, 0x1AEC
    ctx->r14 = ADD32(ctx->r14, 0X1AEC);
    // 0x801167A4: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x801167A8: sw          $t6, 0x1C($t9)
    MEM_W(0X1C, ctx->r25) = ctx->r14;
    // 0x801167AC: lw          $t1, 0x18($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X18);
    // 0x801167B0: lw          $a1, 0x10($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X10);
    // 0x801167B4: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x801167B8: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x801167BC: addu        $a0, $t2, $a2
    ctx->r4 = ADD32(ctx->r10, ctx->r6);
    // 0x801167C0: jal         0x8011652C
    // 0x801167C4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    efGroundMakeEffect(rdram, ctx);
        goto after_0;
    // 0x801167C4: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
    after_0:
    // 0x801167C8: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801167CC: addiu       $t0, $t0, 0x1AD8
    ctx->r8 = ADD32(ctx->r8, 0X1AD8);
    // 0x801167D0: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x801167D4: beq         $v0, $zero, L_8011688C
    if (ctx->r2 == 0) {
        // 0x801167D8: sw          $v0, 0x2C($sp)
        MEM_W(0X2C, ctx->r29) = ctx->r2;
            goto L_8011688C;
    }
    // 0x801167D8: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x801167DC: lw          $t3, 0x18($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X18);
    // 0x801167E0: lw          $a0, 0x84($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84);
    // 0x801167E4: lw          $t4, 0xC($t3)
    ctx->r12 = MEM_W(ctx->r11, 0XC);
    // 0x801167E8: addu        $t5, $t4, $a2
    ctx->r13 = ADD32(ctx->r12, ctx->r6);
    // 0x801167EC: lhu         $t7, 0x10($t5)
    ctx->r15 = MEM_HU(ctx->r13, 0X10);
    // 0x801167F0: sw          $t7, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r15;
    // 0x801167F4: lw          $t8, 0x18($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X18);
    // 0x801167F8: lw          $t6, 0xC($t8)
    ctx->r14 = MEM_W(ctx->r24, 0XC);
    // 0x801167FC: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80116800: addu        $v1, $t6, $a2
    ctx->r3 = ADD32(ctx->r14, ctx->r6);
    // 0x80116804: lw          $a3, 0x38($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X38);
    // 0x80116808: lw          $t9, 0x1C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1C);
    // 0x8011680C: beq         $a3, $zero, L_80116820
    if (ctx->r7 == 0) {
        // 0x80116810: lw          $a1, 0x0($t9)
        ctx->r5 = MEM_W(ctx->r25, 0X0);
            goto L_80116820;
    }
    // 0x80116810: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x80116814: addu        $t1, $a3, $a1
    ctx->r9 = ADD32(ctx->r7, ctx->r5);
    // 0x80116818: b           L_80116824
    // 0x8011681C: sw          $t1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r9;
        goto L_80116824;
    // 0x8011681C: sw          $t1, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->r9;
L_80116820:
    // 0x80116820: sw          $zero, 0x30($a0)
    MEM_W(0X30, ctx->r4) = 0;
L_80116824:
    // 0x80116824: lw          $t2, 0x18($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X18);
    // 0x80116828: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x8011682C: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x80116830: lw          $v0, 0x3C($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X3C);
    // 0x80116834: beq         $v0, $zero, L_80116844
    if (ctx->r2 == 0) {
        // 0x80116838: addu        $t5, $v0, $a1
        ctx->r13 = ADD32(ctx->r2, ctx->r5);
            goto L_80116844;
    }
    // 0x80116838: addu        $t5, $v0, $a1
    ctx->r13 = ADD32(ctx->r2, ctx->r5);
    // 0x8011683C: b           L_80116848
    // 0x80116840: sw          $t5, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r13;
        goto L_80116848;
    // 0x80116840: sw          $t5, 0x34($a0)
    MEM_W(0X34, ctx->r4) = ctx->r13;
L_80116844:
    // 0x80116844: sw          $zero, 0x34($a0)
    MEM_W(0X34, ctx->r4) = 0;
L_80116848:
    // 0x80116848: lw          $t7, 0x10($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X10);
    // 0x8011684C: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x80116850: beq         $t7, $at, L_8011686C
    if (ctx->r15 == ctx->r1) {
        // 0x80116854: sw          $t7, 0x2C($a0)
        MEM_W(0X2C, ctx->r4) = ctx->r15;
            goto L_8011686C;
    }
    // 0x80116854: sw          $t7, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r15;
    // 0x80116858: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8011685C: beq         $t7, $at, L_80116874
    if (ctx->r15 == ctx->r1) {
        // 0x80116860: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80116874;
    }
    // 0x80116860: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80116864: b           L_8011687C
    // 0x80116868: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_8011687C;
    // 0x80116868: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_8011686C:
    // 0x8011686C: b           L_80116878
    // 0x80116870: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
        goto L_80116878;
    // 0x80116870: sw          $t8, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r24;
L_80116874:
    // 0x80116874: sw          $t6, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->r14;
L_80116878:
    // 0x80116878: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_8011687C:
    // 0x8011687C: jal         0x80116204
    // 0x80116880: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    efGroundUpdatePhysics(rdram, ctx);
        goto after_1;
    // 0x80116880: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80116884: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80116888: addiu       $t0, $t0, 0x1AD8
    ctx->r8 = ADD32(ctx->r8, 0X1AD8);
L_8011688C:
    // 0x8011688C: lhu         $t9, 0x6($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X6);
    // 0x80116890: addiu       $t2, $zero, 0x1E
    ctx->r10 = ADD32(0, 0X1E);
    // 0x80116894: bnel        $t9, $zero, L_801168BC
    if (ctx->r25 != 0) {
        // 0x80116898: sw          $t2, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->r10;
            goto L_801168BC;
    }
    goto skip_0;
    // 0x80116898: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    skip_0:
    // 0x8011689C: jal         0x80018994
    // 0x801168A0: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x801168A0: addiu       $a0, $zero, 0x2710
    ctx->r4 = ADD32(0, 0X2710);
    after_2:
    // 0x801168A4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x801168A8: addiu       $t0, $t0, 0x1AD8
    ctx->r8 = ADD32(ctx->r8, 0X1AD8);
    // 0x801168AC: addiu       $t1, $v0, 0x1770
    ctx->r9 = ADD32(ctx->r2, 0X1770);
    // 0x801168B0: b           L_801168BC
    // 0x801168B4: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
        goto L_801168BC;
    // 0x801168B4: sw          $t1, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r9;
    // 0x801168B8: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
L_801168BC:
    // 0x801168BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801168C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801168C4: jr          $ra
    // 0x801168C8: nop

    return;
    // 0x801168C8: nop

;}
RECOMP_FUNC void itMBallThrownProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017C8D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017C8DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017C8E0: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017C8E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017C8E8: lhu         $t6, 0x350($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X350);
    // 0x8017C8EC: beq         $t6, $zero, L_8017C91C
    if (ctx->r14 == 0) {
        // 0x8017C8F0: nop
    
            goto L_8017C91C;
    }
    // 0x8017C8F0: nop

    // 0x8017C8F4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017C8F8: lwc1        $f0, -0x320C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X320C);
    // 0x8017C8FC: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8017C900: addiu       $a3, $a3, -0x3378
    ctx->r7 = ADD32(ctx->r7, -0X3378);
    // 0x8017C904: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8017C908: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017C90C: jal         0x80173C68
    // 0x8017C910: nop

    itMapCheckLanding(rdram, ctx);
        goto after_0;
    // 0x8017C910: nop

    after_0:
    // 0x8017C914: b           L_8017C93C
    // 0x8017C918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8017C93C;
    // 0x8017C918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017C91C:
    // 0x8017C91C: lwc1        $f0, -0x3208($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3208);
    // 0x8017C920: lui         $a3, 0x8018
    ctx->r7 = S32(0X8018 << 16);
    // 0x8017C924: addiu       $a3, $a3, -0x3378
    ctx->r7 = ADD32(ctx->r7, -0X3378);
    // 0x8017C928: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8017C92C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8017C930: jal         0x80173B24
    // 0x8017C934: nop

    itMapCheckDestroyDropped(rdram, ctx);
        goto after_1;
    // 0x8017C934: nop

    after_1:
    // 0x8017C938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8017C93C:
    // 0x8017C93C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017C940: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017C944: jr          $ra
    // 0x8017C948: nop

    return;
    // 0x8017C948: nop

;}
RECOMP_FUNC void dbUiNodeListDispatch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381D40: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80381D44: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80381D48: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80381D4C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80381D50: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80381D54: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80381D58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80381D5C: lhu         $v1, 0x10($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X10);
    // 0x80381D60: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80381D64: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80381D68: beq         $v1, $zero, L_80381DA8
    if (ctx->r3 == 0) {
        // 0x80381D6C: addiu       $s3, $zero, 0x6
        ctx->r19 = ADD32(0, 0X6);
            goto L_80381DA8;
    }
    // 0x80381D6C: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x80381D70: addiu       $s2, $zero, 0x4
    ctx->r18 = ADD32(0, 0X4);
    // 0x80381D74: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80381D78:
    // 0x80381D78: beql        $v1, $s1, L_80381D9C
    if (ctx->r3 == ctx->r17) {
        // 0x80381D7C: lhu         $v1, 0x38($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X38);
            goto L_80381D9C;
    }
    goto skip_0;
    // 0x80381D7C: lhu         $v1, 0x38($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X38);
    skip_0:
    // 0x80381D80: beql        $v1, $s2, L_80381D9C
    if (ctx->r3 == ctx->r18) {
        // 0x80381D84: lhu         $v1, 0x38($s0)
        ctx->r3 = MEM_HU(ctx->r16, 0X38);
            goto L_80381D9C;
    }
    goto skip_1;
    // 0x80381D84: lhu         $v1, 0x38($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X38);
    skip_1:
    // 0x80381D88: beq         $v1, $s3, L_80381D98
    if (ctx->r3 == ctx->r19) {
        // 0x80381D8C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80381D98;
    }
    // 0x80381D8C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80381D90: jal         0x80381BD0
    // 0x80381D94: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    dbUiNodeDispatch(rdram, ctx);
        goto after_0;
    // 0x80381D94: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
L_80381D98:
    // 0x80381D98: lhu         $v1, 0x38($s0)
    ctx->r3 = MEM_HU(ctx->r16, 0X38);
L_80381D9C:
    // 0x80381D9C: addiu       $s0, $s0, 0x28
    ctx->r16 = ADD32(ctx->r16, 0X28);
    // 0x80381DA0: bne         $v1, $zero, L_80381D78
    if (ctx->r3 != 0) {
        // 0x80381DA4: nop
    
            goto L_80381D78;
    }
    // 0x80381DA4: nop

L_80381DA8:
    // 0x80381DA8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80381DAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80381DB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80381DB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80381DB8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80381DBC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80381DC0: jr          $ra
    // 0x80381DC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80381DC4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonLGunShootProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80146FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80146FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80146FB8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80146FBC: jal         0x800D9480
    // 0x80146FC0: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x80146FC0: addiu       $a1, $a1, -0x11AC
    ctx->r5 = ADD32(ctx->r5, -0X11AC);
    after_0:
    // 0x80146FC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80146FC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80146FCC: jr          $ra
    // 0x80146FD0: nop

    return;
    // 0x80146FD0: nop

;}

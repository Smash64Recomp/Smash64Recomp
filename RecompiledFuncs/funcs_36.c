#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void lbRelocFindStatusBufferFile(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CD620: lui         $v0, 0x800D
    ctx->r2 = S32(0X800D << 16);
    // 0x800CD624: lw          $v0, 0x62F8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X62F8);
    // 0x800CD628: bne         $v0, $zero, L_800CD638
    if (ctx->r2 != 0) {
        // 0x800CD62C: nop
    
            goto L_800CD638;
    }
    // 0x800CD62C: nop

    // 0x800CD630: jr          $ra
    // 0x800CD634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800CD634: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800CD638:
    // 0x800CD638: blez        $v0, L_800CD66C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800CD63C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800CD66C;
    }
    // 0x800CD63C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800CD640: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800CD644: lw          $a1, 0x6300($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6300);
L_800CD648:
    // 0x800CD648: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800CD64C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800CD650: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800CD654: bne         $a0, $t6, L_800CD664
    if (ctx->r4 != ctx->r14) {
        // 0x800CD658: nop
    
            goto L_800CD664;
    }
    // 0x800CD658: nop

    // 0x800CD65C: jr          $ra
    // 0x800CD660: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
    return;
    // 0x800CD660: lw          $v0, 0x4($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4);
L_800CD664:
    // 0x800CD664: bne         $at, $zero, L_800CD648
    if (ctx->r1 != 0) {
        // 0x800CD668: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_800CD648;
    }
    // 0x800CD668: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_800CD66C:
    // 0x800CD66C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CD670: jr          $ra
    // 0x800CD674: nop

    return;
    // 0x800CD674: nop

;}
RECOMP_FUNC void itMapProcAllCheckCollisionFlag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801736B4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801736B8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801736BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801736C0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x801736C4: lw          $t6, 0x84($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X84);
    // 0x801736C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x801736CC: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    // 0x801736D0: lw          $t7, 0x74($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X74);
    // 0x801736D4: jal         0x800DB838
    // 0x801736D8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    mpProcessCheckTestLWallCollisionAdjNew(rdram, ctx);
        goto after_0;
    // 0x801736D8: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
    after_0:
    // 0x801736DC: beq         $v0, $zero, L_801736EC
    if (ctx->r2 == 0) {
        // 0x801736E0: nop
    
            goto L_801736EC;
    }
    // 0x801736E0: nop

    // 0x801736E4: jal         0x800DBF58
    // 0x801736E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunLWallCollisionAdjNew(rdram, ctx);
        goto after_1;
    // 0x801736E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_801736EC:
    // 0x801736EC: jal         0x800DC3C8
    // 0x801736F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestRWallCollisionAdjNew(rdram, ctx);
        goto after_2;
    // 0x801736F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801736F4: beq         $v0, $zero, L_80173704
    if (ctx->r2 == 0) {
        // 0x801736F8: nop
    
            goto L_80173704;
    }
    // 0x801736F8: nop

    // 0x801736FC: jal         0x800DCAE8
    // 0x80173700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunRWallCollisionAdjNew(rdram, ctx);
        goto after_3;
    // 0x80173700: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
L_80173704:
    // 0x80173704: jal         0x800DCF58
    // 0x80173708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestCeilCollisionAdjNew(rdram, ctx);
        goto after_4;
    // 0x80173708: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8017370C: beq         $v0, $zero, L_80173734
    if (ctx->r2 == 0) {
        // 0x80173710: nop
    
            goto L_80173734;
    }
    // 0x80173710: nop

    // 0x80173714: jal         0x800DD160
    // 0x80173718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunCeilCollisionAdjNew(rdram, ctx);
        goto after_5;
    // 0x80173718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x8017371C: lhu         $t8, 0x5A($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X5A);
    // 0x80173720: andi        $t9, $t8, 0x400
    ctx->r25 = ctx->r24 & 0X400;
    // 0x80173724: beq         $t9, $zero, L_80173734
    if (ctx->r25 == 0) {
        // 0x80173728: nop
    
            goto L_80173734;
    }
    // 0x80173728: nop

    // 0x8017372C: jal         0x800D99B8
    // 0x80173730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunCeilEdgeAdjust(rdram, ctx);
        goto after_6;
    // 0x80173730: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
L_80173734:
    // 0x80173734: jal         0x800DD578
    // 0x80173738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorCollisionAdjNewNULL(rdram, ctx);
        goto after_7;
    // 0x80173738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x8017373C: beql        $v0, $zero, L_8017378C
    if (ctx->r2 == 0) {
        // 0x80173740: lhu         $t5, 0x56($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X56);
            goto L_8017378C;
    }
    goto skip_0;
    // 0x80173740: lhu         $t5, 0x56($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X56);
    skip_0:
    // 0x80173744: jal         0x800DD59C
    // 0x80173748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetLandingFloor(rdram, ctx);
        goto after_8;
    // 0x80173748: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_8:
    // 0x8017374C: lhu         $t0, 0x5A($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X5A);
    // 0x80173750: andi        $t1, $t0, 0x800
    ctx->r9 = ctx->r8 & 0X800;
    // 0x80173754: beql        $t1, $zero, L_8017378C
    if (ctx->r9 == 0) {
        // 0x80173758: lhu         $t5, 0x56($s0)
        ctx->r13 = MEM_HU(ctx->r16, 0X56);
            goto L_8017378C;
    }
    goto skip_1;
    // 0x80173758: lhu         $t5, 0x56($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X56);
    skip_1:
    // 0x8017375C: jal         0x800D9F84
    // 0x80173760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_9;
    // 0x80173760: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x80173764: jal         0x800269C0
    // 0x80173768: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    func_800269C0_275C0(rdram, ctx);
        goto after_10;
    // 0x80173768: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    after_10:
    // 0x8017376C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80173770: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80173774: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80173778: swc1        $f0, 0x344($t2)
    MEM_W(0X344, ctx->r10) = ctx->f0.u32l;
    // 0x8017377C: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x80173780: swc1        $f0, 0x38($t3)
    MEM_W(0X38, ctx->r11) = ctx->f0.u32l;
    // 0x80173784: sw          $t4, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r12;
    // 0x80173788: lhu         $t5, 0x56($s0)
    ctx->r13 = MEM_HU(ctx->r16, 0X56);
L_8017378C:
    // 0x8017378C: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x80173790: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80173794: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80173798: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8017379C: beq         $t7, $zero, L_801737AC
    if (ctx->r15 == 0) {
        // 0x801737A0: nop
    
            goto L_801737AC;
    }
    // 0x801737A0: nop

    // 0x801737A4: b           L_801737AC
    // 0x801737A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801737AC;
    // 0x801737A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801737AC:
    // 0x801737AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801737B0: jr          $ra
    // 0x801737B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x801737B4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnMapsGetGroundKind(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132430: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80132434: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132438: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x8013243C: addiu       $t6, $t6, 0x4644
    ctx->r14 = ADD32(ctx->r14, 0X4644);
    // 0x80132440: addiu       $t0, $t6, 0x24
    ctx->r8 = ADD32(ctx->r14, 0X24);
    // 0x80132444: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80132448:
    // 0x80132448: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8013244C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132450: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132454: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80132458: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8013245C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132460: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132464: bne         $t6, $t0, L_80132448
    if (ctx->r14 != ctx->r8) {
        // 0x80132468: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80132448;
    }
    // 0x80132468: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8013246C: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132470: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x80132474: bne         $a0, $at, L_80132484
    if (ctx->r4 != ctx->r1) {
        // 0x80132478: sw          $t8, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->r24;
            goto L_80132484;
    }
    // 0x80132478: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8013247C: b           L_80132490
    // 0x80132480: addiu       $v0, $zero, 0xDE
    ctx->r2 = ADD32(0, 0XDE);
        goto L_80132490;
    // 0x80132480: addiu       $v0, $zero, 0xDE
    ctx->r2 = ADD32(0, 0XDE);
L_80132484:
    // 0x80132484: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x80132488: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x8013248C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
L_80132490:
    // 0x80132490: jr          $ra
    // 0x80132494: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80132494: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnBackupClearUpdateOptionConfirmMenu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132930: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132938: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8013293C: jal         0x8039076C
    // 0x80132940: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_0;
    // 0x80132940: ori         $a0, $zero, 0x9000
    ctx->r4 = 0 | 0X9000;
    after_0:
    // 0x80132944: beq         $v0, $zero, L_80132A4C
    if (ctx->r2 == 0) {
        // 0x80132948: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_80132A4C;
    }
    // 0x80132948: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013294C: lw          $v0, 0x30CC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X30CC);
    // 0x80132950: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132954: beq         $v0, $zero, L_8013296C
    if (ctx->r2 == 0) {
        // 0x80132958: nop
    
            goto L_8013296C;
    }
    // 0x80132958: nop

    // 0x8013295C: beq         $v0, $at, L_80132A28
    if (ctx->r2 == ctx->r1) {
        // 0x80132960: nop
    
            goto L_80132A28;
    }
    // 0x80132960: nop

    // 0x80132964: b           L_80132A4C
    // 0x80132968: nop

        goto L_80132A4C;
    // 0x80132968: nop

L_8013296C:
    // 0x8013296C: jal         0x800269C0
    // 0x80132970: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80132970: addiu       $a0, $zero, 0x9E
    ctx->r4 = ADD32(0, 0X9E);
    after_1:
    // 0x80132974: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80132978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8013297C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132980: bne         $t6, $at, L_801329D0
    if (ctx->r14 != ctx->r1) {
        // 0x80132984: lui         $v0, 0x8013
        ctx->r2 = S32(0X8013 << 16);
            goto L_801329D0;
    }
    // 0x80132984: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80132988: lw          $t7, 0x30C0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30C0);
    // 0x8013298C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80132990: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80132994: bne         $t7, $at, L_801329D0
    if (ctx->r15 != ctx->r1) {
        // 0x80132998: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_801329D0;
    }
    // 0x80132998: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8013299C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329A0: sw          $t8, 0x30D0($at)
    MEM_W(0X30D0, ctx->r1) = ctx->r24;
    // 0x801329A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329A8: jal         0x80132124
    // 0x801329AC: sw          $t9, 0x30CC($at)
    MEM_W(0X30CC, ctx->r1) = ctx->r25;
    mnBackupClearEjectOptionConfirmGObj(rdram, ctx);
        goto after_2;
    // 0x801329AC: sw          $t9, 0x30CC($at)
    MEM_W(0X30CC, ctx->r1) = ctx->r25;
    after_2:
    // 0x801329B0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801329B4: lw          $a1, 0x30CC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30CC);
    // 0x801329B8: jal         0x80132148
    // 0x801329BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mnBackupClearMakeOptionConfirm(rdram, ctx);
        goto after_3;
    // 0x801329BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x801329C0: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x801329C4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329C8: b           L_80132B8C
    // 0x801329CC: sw          $t0, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r8;
        goto L_80132B8C;
    // 0x801329CC: sw          $t0, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r8;
L_801329D0:
    // 0x801329D0: lw          $v0, 0x30C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X30C8);
    // 0x801329D4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801329D8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801329DC: lw          $t1, 0x74($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X74);
    // 0x801329E0: lw          $t3, 0x31B4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X31B4);
    // 0x801329E4: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801329E8: lw          $t2, 0x30($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X30);
    // 0x801329EC: addiu       $t4, $t4, 0x7550
    ctx->r12 = ADD32(ctx->r12, 0X7550);
    // 0x801329F0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x801329F4: sw          $t2, 0x30D4($at)
    MEM_W(0X30D4, ctx->r1) = ctx->r10;
    // 0x801329F8: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x801329FC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A00: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80132A04: sw          $t5, 0x30($t6)
    MEM_W(0X30, ctx->r14) = ctx->r13;
    // 0x80132A08: sw          $zero, 0x30D0($at)
    MEM_W(0X30D0, ctx->r1) = 0;
    // 0x80132A0C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A10: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80132A14: sw          $t7, 0x30E8($at)
    MEM_W(0X30E8, ctx->r1) = ctx->r15;
    // 0x80132A18: jal         0x8013251C
    // 0x80132A1C: lw          $a0, 0x30C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C0);
    mnBackupClearApplyOptionID(rdram, ctx);
        goto after_4;
    // 0x80132A1C: lw          $a0, 0x30C0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30C0);
    after_4:
    // 0x80132A20: b           L_80132B90
    // 0x80132A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132B90;
    // 0x80132A24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132A28:
    // 0x80132A28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A2C: jal         0x80132124
    // 0x80132A30: sw          $zero, 0x30D0($at)
    MEM_W(0X30D0, ctx->r1) = 0;
    mnBackupClearEjectOptionConfirmGObj(rdram, ctx);
        goto after_5;
    // 0x80132A30: sw          $zero, 0x30D0($at)
    MEM_W(0X30D0, ctx->r1) = 0;
    after_5:
    // 0x80132A34: jal         0x80131D44
    // 0x80132A38: nop

    mnBackupClearSetOptionSpriteColors(rdram, ctx);
        goto after_6;
    // 0x80132A38: nop

    after_6:
    // 0x80132A3C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80132A40: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A44: b           L_80132B8C
    // 0x80132A48: sw          $t8, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r24;
        goto L_80132B8C;
    // 0x80132A48: sw          $t8, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r24;
L_80132A4C:
    // 0x80132A4C: jal         0x8039076C
    // 0x80132A50: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_7;
    // 0x80132A50: addiu       $a0, $zero, 0x4000
    ctx->r4 = ADD32(0, 0X4000);
    after_7:
    // 0x80132A54: beq         $v0, $zero, L_80132A7C
    if (ctx->r2 == 0) {
        // 0x80132A58: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_80132A7C;
    }
    // 0x80132A58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A5C: jal         0x80132124
    // 0x80132A60: sw          $zero, 0x30D0($at)
    MEM_W(0X30D0, ctx->r1) = 0;
    mnBackupClearEjectOptionConfirmGObj(rdram, ctx);
        goto after_8;
    // 0x80132A60: sw          $zero, 0x30D0($at)
    MEM_W(0X30D0, ctx->r1) = 0;
    after_8:
    // 0x80132A64: jal         0x80131D44
    // 0x80132A68: nop

    mnBackupClearSetOptionSpriteColors(rdram, ctx);
        goto after_9;
    // 0x80132A68: nop

    after_9:
    // 0x80132A6C: addiu       $t9, $zero, 0xA
    ctx->r25 = ADD32(0, 0XA);
    // 0x80132A70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132A74: b           L_80132B8C
    // 0x80132A78: sw          $t9, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r25;
        goto L_80132B8C;
    // 0x80132A78: sw          $t9, 0x30E4($at)
    MEM_W(0X30E4, ctx->r1) = ctx->r25;
L_80132A7C:
    // 0x80132A7C: jal         0x8039076C
    // 0x80132A80: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_10;
    // 0x80132A80: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    after_10:
    // 0x80132A84: bne         $v0, $zero, L_80132AAC
    if (ctx->r2 != 0) {
        // 0x80132A88: lui         $t0, 0x8013
        ctx->r8 = S32(0X8013 << 16);
            goto L_80132AAC;
    }
    // 0x80132A88: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132A8C: lw          $t0, 0x30DC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30DC);
    // 0x80132A90: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x80132A94: bne         $t0, $zero, L_80132B08
    if (ctx->r8 != 0) {
        // 0x80132A98: nop
    
            goto L_80132B08;
    }
    // 0x80132A98: nop

    // 0x80132A9C: jal         0x8039089C
    // 0x80132AA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_11;
    // 0x80132AA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_11:
    // 0x80132AA4: beq         $v0, $zero, L_80132B08
    if (ctx->r2 == 0) {
        // 0x80132AA8: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80132B08;
    }
    // 0x80132AA8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80132AAC:
    // 0x80132AAC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x80132AB0: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132AB4: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132AB8: addiu       $t2, $t1, 0xA0
    ctx->r10 = ADD32(ctx->r9, 0XA0);
    // 0x80132ABC: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x80132AC0: lw          $t4, 0x30CC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X30CC);
    // 0x80132AC4: mflo        $t3
    ctx->r11 = lo;
    // 0x80132AC8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132ACC: sw          $t3, 0x30DC($at)
    MEM_W(0X30DC, ctx->r1) = ctx->r11;
    // 0x80132AD0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80132AD4: bnel        $t4, $at, L_80132B90
    if (ctx->r12 != ctx->r1) {
        // 0x80132AD8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132B90;
    }
    goto skip_0;
    // 0x80132AD8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80132ADC: jal         0x800269C0
    // 0x80132AE0: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_12;
    // 0x80132AE0: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_12:
    // 0x80132AE4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132AE8: jal         0x80132124
    // 0x80132AEC: sw          $zero, 0x30CC($at)
    MEM_W(0X30CC, ctx->r1) = 0;
    mnBackupClearEjectOptionConfirmGObj(rdram, ctx);
        goto after_13;
    // 0x80132AEC: sw          $zero, 0x30CC($at)
    MEM_W(0X30CC, ctx->r1) = 0;
    after_13:
    // 0x80132AF0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132AF4: lw          $a1, 0x30CC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30CC);
    // 0x80132AF8: jal         0x80132148
    // 0x80132AFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnBackupClearMakeOptionConfirm(rdram, ctx);
        goto after_14;
    // 0x80132AFC: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_14:
    // 0x80132B00: b           L_80132B90
    // 0x80132B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132B90;
    // 0x80132B04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132B08:
    // 0x80132B08: jal         0x8039076C
    // 0x80132B0C: addiu       $a0, $zero, 0x202
    ctx->r4 = ADD32(0, 0X202);
    scSubsysControllerGetPlayerTapButtons(rdram, ctx);
        goto after_15;
    // 0x80132B0C: addiu       $a0, $zero, 0x202
    ctx->r4 = ADD32(0, 0X202);
    after_15:
    // 0x80132B10: bne         $v0, $zero, L_80132B38
    if (ctx->r2 != 0) {
        // 0x80132B14: lui         $t5, 0x8013
        ctx->r13 = S32(0X8013 << 16);
            goto L_80132B38;
    }
    // 0x80132B14: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x80132B18: lw          $t5, 0x30DC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30DC);
    // 0x80132B1C: addiu       $a0, $zero, -0x14
    ctx->r4 = ADD32(0, -0X14);
    // 0x80132B20: bnel        $t5, $zero, L_80132B90
    if (ctx->r13 != 0) {
        // 0x80132B24: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132B90;
    }
    goto skip_1;
    // 0x80132B24: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80132B28: jal         0x8039089C
    // 0x80132B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    scSubsysControllerGetPlayerStickLR(rdram, ctx);
        goto after_16;
    // 0x80132B2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x80132B30: beq         $v0, $zero, L_80132B8C
    if (ctx->r2 == 0) {
        // 0x80132B34: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_80132B8C;
    }
    // 0x80132B34: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80132B38:
    // 0x80132B38: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132B3C: lw          $t6, 0x30CC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30CC);
    // 0x80132B40: bnel        $t6, $zero, L_80132B90
    if (ctx->r14 != 0) {
        // 0x80132B44: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132B90;
    }
    goto skip_2;
    // 0x80132B44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x80132B48: jal         0x800269C0
    // 0x80132B4C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_17;
    // 0x80132B4C: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_17:
    // 0x80132B50: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x80132B54: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80132B58: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B5C: sw          $t7, 0x30CC($at)
    MEM_W(0X30CC, ctx->r1) = ctx->r15;
    // 0x80132B60: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80132B64: addiu       $t9, $t8, 0xA0
    ctx->r25 = ADD32(ctx->r24, 0XA0);
    // 0x80132B68: div         $zero, $t9, $at
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r1)));
    // 0x80132B6C: mflo        $t0
    ctx->r8 = lo;
    // 0x80132B70: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132B74: jal         0x80132124
    // 0x80132B78: sw          $t0, 0x30DC($at)
    MEM_W(0X30DC, ctx->r1) = ctx->r8;
    mnBackupClearEjectOptionConfirmGObj(rdram, ctx);
        goto after_18;
    // 0x80132B78: sw          $t0, 0x30DC($at)
    MEM_W(0X30DC, ctx->r1) = ctx->r8;
    after_18:
    // 0x80132B7C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132B80: lw          $a1, 0x30CC($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X30CC);
    // 0x80132B84: jal         0x80132148
    // 0x80132B88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    mnBackupClearMakeOptionConfirm(rdram, ctx);
        goto after_19;
    // 0x80132B88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_19:
L_80132B8C:
    // 0x80132B8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132B90:
    // 0x80132B90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132B94: jr          $ra
    // 0x80132B98: nop

    return;
    // 0x80132B98: nop

;}
RECOMP_FUNC void func_ovl8_8037A0FC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037A0FC: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8037A100: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8037A104: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8037A108: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x8037A10C: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x8037A110: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x8037A114: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8037A118: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x8037A11C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x8037A120: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8037A124: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8037A128: sw          $a1, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r5;
    // 0x8037A12C: lwl         $t8, 0x0($a1)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r5, 0X0);
    // 0x8037A130: lwr         $t8, 0x3($a1)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r5, 0X3);
    // 0x8037A134: addiu       $s1, $sp, 0xB0
    ctx->r17 = ADD32(ctx->r29, 0XB0);
    // 0x8037A138: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8037A13C: swl         $t8, 0x0($s1)
    do_swl(rdram, 0X0, ctx->r17, ctx->r24);
    // 0x8037A140: swr         $t8, 0x3($s1)
    do_swr(rdram, 0X3, ctx->r17, ctx->r24);
    // 0x8037A144: lwl         $t7, 0x4($a1)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r5, 0X4);
    // 0x8037A148: lwr         $t7, 0x7($a1)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r5, 0X7);
    // 0x8037A14C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8037A150: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8037A154: swl         $t7, 0x4($s1)
    do_swl(rdram, 0X4, ctx->r17, ctx->r15);
    // 0x8037A158: swr         $t7, 0x7($s1)
    do_swr(rdram, 0X7, ctx->r17, ctx->r15);
    // 0x8037A15C: lbu         $v0, 0x31($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X31);
    // 0x8037A160: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8037A164: bnel        $v0, $at, L_8037A178
    if (ctx->r2 != ctx->r1) {
        // 0x8037A168: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8037A178;
    }
    goto skip_0;
    // 0x8037A168: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    skip_0:
    // 0x8037A16C: b           L_8037A190
    // 0x8037A170: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8037A190;
    // 0x8037A170: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8037A174: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8037A178:
    // 0x8037A178: bnel        $v0, $at, L_8037A18C
    if (ctx->r2 != ctx->r1) {
        // 0x8037A17C: addiu       $v0, $zero, 0x4
        ctx->r2 = ADD32(0, 0X4);
            goto L_8037A18C;
    }
    goto skip_1;
    // 0x8037A17C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    skip_1:
    // 0x8037A180: b           L_8037A18C
    // 0x8037A184: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_8037A18C;
    // 0x8037A184: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x8037A188: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8037A18C:
    // 0x8037A18C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8037A190:
    // 0x8037A190: sw          $s0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r16;
    // 0x8037A194: sh          $zero, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = 0;
    // 0x8037A198: sh          $zero, 0x98($sp)
    MEM_H(0X98, ctx->r29) = 0;
    // 0x8037A19C: lh          $t9, 0x4($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X4);
    // 0x8037A1A0: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x8037A1A4: addiu       $a2, $sp, 0xA8
    ctx->r6 = ADD32(ctx->r29, 0XA8);
    // 0x8037A1A8: sh          $t9, 0x9C($sp)
    MEM_H(0X9C, ctx->r29) = ctx->r25;
    // 0x8037A1AC: lh          $t0, 0x6($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X6);
    // 0x8037A1B0: sw          $a3, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->r7;
    // 0x8037A1B4: jal         0x8037A67C
    // 0x8037A1B8: sh          $t0, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r8;
    func_ovl8_8037A67C(rdram, ctx);
        goto after_0;
    // 0x8037A1B8: sh          $t0, 0x9E($sp)
    MEM_H(0X9E, ctx->r29) = ctx->r8;
    after_0:
    // 0x8037A1BC: jal         0x8037AA5C
    // 0x8037A1C0: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    func_ovl8_8037AA5C(rdram, ctx);
        goto after_1;
    // 0x8037A1C0: addiu       $a0, $sp, 0xA8
    ctx->r4 = ADD32(ctx->r29, 0XA8);
    after_1:
    // 0x8037A1C4: bne         $v0, $zero, L_8037A588
    if (ctx->r2 != 0) {
        // 0x8037A1C8: lw          $t1, 0xBC($sp)
        ctx->r9 = MEM_W(ctx->r29, 0XBC);
            goto L_8037A588;
    }
    // 0x8037A1C8: lw          $t1, 0xBC($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XBC);
    // 0x8037A1CC: lh          $t2, 0xAA($sp)
    ctx->r10 = MEM_H(ctx->r29, 0XAA);
    // 0x8037A1D0: lh          $t3, 0xB2($sp)
    ctx->r11 = MEM_H(ctx->r29, 0XB2);
    // 0x8037A1D4: lhu         $v0, 0x4($t1)
    ctx->r2 = MEM_HU(ctx->r9, 0X4);
    // 0x8037A1D8: lh          $t6, 0xA8($sp)
    ctx->r14 = MEM_H(ctx->r29, 0XA8);
    // 0x8037A1DC: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x8037A1E0: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A1E4: lh          $t7, 0xB0($sp)
    ctx->r15 = MEM_H(ctx->r29, 0XB0);
    // 0x8037A1E8: lw          $t1, 0xB8($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB8);
    // 0x8037A1EC: addiu       $fp, $sp, 0xA0
    ctx->r30 = ADD32(ctx->r29, 0XA0);
    // 0x8037A1F0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x8037A1F4: lw          $v1, 0x34($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X34);
    // 0x8037A1F8: lh          $s3, 0x0($v1)
    ctx->r19 = MEM_H(ctx->r3, 0X0);
    // 0x8037A1FC: lh          $s6, 0xC($v1)
    ctx->r22 = MEM_H(ctx->r3, 0XC);
    // 0x8037A200: mflo        $t5
    ctx->r13 = lo;
    // 0x8037A204: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x8037A208: nop

    // 0x8037A20C: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A210: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037A214: mflo        $t0
    ctx->r8 = lo;
    // 0x8037A218: addu        $a2, $s2, $t0
    ctx->r6 = ADD32(ctx->r18, ctx->r8);
    // 0x8037A21C: nop

    // 0x8037A220: div         $zero, $t6, $s3
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r19)));
    // 0x8037A224: mflo        $t3
    ctx->r11 = lo;
    // 0x8037A228: sw          $t3, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r11;
    // 0x8037A22C: bne         $s3, $zero, L_8037A238
    if (ctx->r19 != 0) {
        // 0x8037A230: nop
    
            goto L_8037A238;
    }
    // 0x8037A230: nop

    // 0x8037A234: break       7
    do_break(2151129652);
L_8037A238:
    // 0x8037A238: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037A23C: bne         $s3, $at, L_8037A250
    if (ctx->r19 != ctx->r1) {
        // 0x8037A240: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037A250;
    }
    // 0x8037A240: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037A244: bne         $t6, $at, L_8037A250
    if (ctx->r14 != ctx->r1) {
        // 0x8037A248: nop
    
            goto L_8037A250;
    }
    // 0x8037A248: nop

    // 0x8037A24C: break       6
    do_break(2151129676);
L_8037A250:
    // 0x8037A250: div         $zero, $t2, $s6
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r22)));
    // 0x8037A254: mflo        $t4
    ctx->r12 = lo;
    // 0x8037A258: sw          $t4, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r12;
    // 0x8037A25C: lh          $a0, 0x4($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X4);
    // 0x8037A260: bne         $s6, $zero, L_8037A26C
    if (ctx->r22 != 0) {
        // 0x8037A264: nop
    
            goto L_8037A26C;
    }
    // 0x8037A264: nop

    // 0x8037A268: break       7
    do_break(2151129704);
L_8037A26C:
    // 0x8037A26C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037A270: bne         $s6, $at, L_8037A284
    if (ctx->r22 != ctx->r1) {
        // 0x8037A274: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037A284;
    }
    // 0x8037A274: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037A278: bne         $t2, $at, L_8037A284
    if (ctx->r10 != ctx->r1) {
        // 0x8037A27C: nop
    
            goto L_8037A284;
    }
    // 0x8037A27C: nop

    // 0x8037A280: break       6
    do_break(2151129728);
L_8037A284:
    // 0x8037A284: div         $zero, $a0, $s3
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r19)));
    // 0x8037A288: mfhi        $t7
    ctx->r15 = hi;
    // 0x8037A28C: bne         $s3, $zero, L_8037A298
    if (ctx->r19 != 0) {
        // 0x8037A290: nop
    
            goto L_8037A298;
    }
    // 0x8037A290: nop

    // 0x8037A294: break       7
    do_break(2151129748);
L_8037A298:
    // 0x8037A298: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037A29C: bne         $s3, $at, L_8037A2B0
    if (ctx->r19 != ctx->r1) {
        // 0x8037A2A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037A2B0;
    }
    // 0x8037A2A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037A2A4: bne         $a0, $at, L_8037A2B0
    if (ctx->r4 != ctx->r1) {
        // 0x8037A2A8: nop
    
            goto L_8037A2B0;
    }
    // 0x8037A2A8: nop

    // 0x8037A2AC: break       6
    do_break(2151129772);
L_8037A2B0:
    // 0x8037A2B0: beq         $t7, $zero, L_8037A2C0
    if (ctx->r15 == 0) {
        // 0x8037A2B4: nop
    
            goto L_8037A2C0;
    }
    // 0x8037A2B4: nop

    // 0x8037A2B8: b           L_8037A2C0
    // 0x8037A2BC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8037A2C0;
    // 0x8037A2BC: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8037A2C0:
    // 0x8037A2C0: div         $zero, $a0, $s3
    lo = S32(S64(S32(ctx->r4)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r4)) % S64(S32(ctx->r19)));
    // 0x8037A2C4: lhu         $v1, 0xAC($sp)
    ctx->r3 = MEM_HU(ctx->r29, 0XAC);
    // 0x8037A2C8: mflo        $t5
    ctx->r13 = lo;
    // 0x8037A2CC: addu        $t8, $t5, $s0
    ctx->r24 = ADD32(ctx->r13, ctx->r16);
    // 0x8037A2D0: bne         $s3, $zero, L_8037A2DC
    if (ctx->r19 != 0) {
        // 0x8037A2D4: nop
    
            goto L_8037A2DC;
    }
    // 0x8037A2D4: nop

    // 0x8037A2D8: break       7
    do_break(2151129816);
L_8037A2DC:
    // 0x8037A2DC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037A2E0: bne         $s3, $at, L_8037A2F4
    if (ctx->r19 != ctx->r1) {
        // 0x8037A2E4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037A2F4;
    }
    // 0x8037A2E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037A2E8: bne         $a0, $at, L_8037A2F4
    if (ctx->r4 != ctx->r1) {
        // 0x8037A2EC: nop
    
            goto L_8037A2F4;
    }
    // 0x8037A2EC: nop

    // 0x8037A2F0: break       6
    do_break(2151129840);
L_8037A2F4:
    // 0x8037A2F4: div         $zero, $v1, $s3
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r19)));
    // 0x8037A2F8: mfhi        $t9
    ctx->r25 = hi;
    // 0x8037A2FC: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
    // 0x8037A300: bne         $s3, $zero, L_8037A30C
    if (ctx->r19 != 0) {
        // 0x8037A304: nop
    
            goto L_8037A30C;
    }
    // 0x8037A304: nop

    // 0x8037A308: break       7
    do_break(2151129864);
L_8037A30C:
    // 0x8037A30C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037A310: bne         $s3, $at, L_8037A324
    if (ctx->r19 != ctx->r1) {
        // 0x8037A314: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037A324;
    }
    // 0x8037A314: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037A318: bne         $v1, $at, L_8037A324
    if (ctx->r3 != ctx->r1) {
        // 0x8037A31C: nop
    
            goto L_8037A324;
    }
    // 0x8037A31C: nop

    // 0x8037A320: break       6
    do_break(2151129888);
L_8037A324:
    // 0x8037A324: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037A328: beq         $t9, $zero, L_8037A338
    if (ctx->r25 == 0) {
        // 0x8037A32C: nop
    
            goto L_8037A338;
    }
    // 0x8037A32C: nop

    // 0x8037A330: b           L_8037A338
    // 0x8037A334: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8037A338;
    // 0x8037A334: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8037A338:
    // 0x8037A338: div         $zero, $v1, $s3
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r19)));
    // 0x8037A33C: lhu         $a1, 0xAE($sp)
    ctx->r5 = MEM_HU(ctx->r29, 0XAE);
    // 0x8037A340: mflo        $t0
    ctx->r8 = lo;
    // 0x8037A344: addu        $t6, $t0, $s0
    ctx->r14 = ADD32(ctx->r8, ctx->r16);
    // 0x8037A348: bne         $s3, $zero, L_8037A354
    if (ctx->r19 != 0) {
        // 0x8037A34C: nop
    
            goto L_8037A354;
    }
    // 0x8037A34C: nop

    // 0x8037A350: break       7
    do_break(2151129936);
L_8037A354:
    // 0x8037A354: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037A358: bne         $s3, $at, L_8037A36C
    if (ctx->r19 != ctx->r1) {
        // 0x8037A35C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037A36C;
    }
    // 0x8037A35C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037A360: bne         $v1, $at, L_8037A36C
    if (ctx->r3 != ctx->r1) {
        // 0x8037A364: nop
    
            goto L_8037A36C;
    }
    // 0x8037A364: nop

    // 0x8037A368: break       6
    do_break(2151129960);
L_8037A36C:
    // 0x8037A36C: div         $zero, $a1, $s6
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r22)));
    // 0x8037A370: addiu       $t3, $t6, 0x1
    ctx->r11 = ADD32(ctx->r14, 0X1);
    // 0x8037A374: mfhi        $t2
    ctx->r10 = hi;
    // 0x8037A378: sw          $t3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r11;
    // 0x8037A37C: bne         $s6, $zero, L_8037A388
    if (ctx->r22 != 0) {
        // 0x8037A380: nop
    
            goto L_8037A388;
    }
    // 0x8037A380: nop

    // 0x8037A384: break       7
    do_break(2151129988);
L_8037A388:
    // 0x8037A388: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037A38C: bne         $s6, $at, L_8037A3A0
    if (ctx->r22 != ctx->r1) {
        // 0x8037A390: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037A3A0;
    }
    // 0x8037A390: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037A394: bne         $a1, $at, L_8037A3A0
    if (ctx->r5 != ctx->r1) {
        // 0x8037A398: nop
    
            goto L_8037A3A0;
    }
    // 0x8037A398: nop

    // 0x8037A39C: break       6
    do_break(2151130012);
L_8037A3A0:
    // 0x8037A3A0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037A3A4: beq         $t2, $zero, L_8037A3B4
    if (ctx->r10 == 0) {
        // 0x8037A3A8: nop
    
            goto L_8037A3B4;
    }
    // 0x8037A3A8: nop

    // 0x8037A3AC: b           L_8037A3B4
    // 0x8037A3B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_8037A3B4;
    // 0x8037A3B0: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8037A3B4:
    // 0x8037A3B4: div         $zero, $a1, $s6
    lo = S32(S64(S32(ctx->r5)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r5)) % S64(S32(ctx->r22)));
    // 0x8037A3B8: mflo        $t4
    ctx->r12 = lo;
    // 0x8037A3BC: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    // 0x8037A3C0: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8037A3C4: bne         $s6, $zero, L_8037A3D0
    if (ctx->r22 != 0) {
        // 0x8037A3C8: nop
    
            goto L_8037A3D0;
    }
    // 0x8037A3C8: nop

    // 0x8037A3CC: break       7
    do_break(2151130060);
L_8037A3D0:
    // 0x8037A3D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037A3D4: bne         $s6, $at, L_8037A3E8
    if (ctx->r22 != ctx->r1) {
        // 0x8037A3D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037A3E8;
    }
    // 0x8037A3D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037A3DC: bne         $a1, $at, L_8037A3E8
    if (ctx->r5 != ctx->r1) {
        // 0x8037A3E0: nop
    
            goto L_8037A3E8;
    }
    // 0x8037A3E0: nop

    // 0x8037A3E4: break       6
    do_break(2151130084);
L_8037A3E8:
    // 0x8037A3E8: sw          $a0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r4;
    // 0x8037A3EC: blez        $a0, L_8037A588
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8037A3F0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8037A588;
    }
    // 0x8037A3F0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8037A3F4: lw          $s7, 0x70($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X70);
    // 0x8037A3F8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8037A3FC: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
L_8037A400:
    // 0x8037A400: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8037A404: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8037A408: blez        $t1, L_8037A554
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8037A40C: lw          $t7, 0x78($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X78);
            goto L_8037A554;
    }
    // 0x8037A40C: lw          $t7, 0x78($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X78);
    // 0x8037A410: multu       $t7, $s3
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A414: lw          $t5, 0x74($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X74);
    // 0x8037A418: sw          $v1, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r3;
    // 0x8037A41C: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    // 0x8037A420: addu        $s4, $t5, $v1
    ctx->r20 = ADD32(ctx->r13, ctx->r3);
    // 0x8037A424: mflo        $s2
    ctx->r18 = lo;
    // 0x8037A428: nop

    // 0x8037A42C: nop

    // 0x8037A430: multu       $s4, $s6
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A434: mflo        $s5
    ctx->r21 = lo;
    // 0x8037A438: nop

    // 0x8037A43C: nop

    // 0x8037A440: sh          $s2, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r18;
L_8037A444:
    // 0x8037A444: sh          $s5, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r21;
    // 0x8037A448: sh          $s3, 0xA4($sp)
    MEM_H(0XA4, ctx->r29) = ctx->r19;
    // 0x8037A44C: sh          $s6, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r22;
    // 0x8037A450: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x8037A454: addiu       $a1, $sp, 0xA8
    ctx->r5 = ADD32(ctx->r29, 0XA8);
    // 0x8037A458: jal         0x8037A67C
    // 0x8037A45C: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    func_ovl8_8037A67C(rdram, ctx);
        goto after_2;
    // 0x8037A45C: addiu       $a2, $sp, 0x98
    ctx->r6 = ADD32(ctx->r29, 0X98);
    after_2:
    // 0x8037A460: beq         $v0, $zero, L_8037A51C
    if (ctx->r2 == 0) {
        // 0x8037A464: lh          $t8, 0x98($sp)
        ctx->r24 = MEM_H(ctx->r29, 0X98);
            goto L_8037A51C;
    }
    // 0x8037A464: lh          $t8, 0x98($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X98);
    // 0x8037A468: div         $zero, $t8, $s3
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r19))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r19)));
    // 0x8037A46C: mfhi        $t9
    ctx->r25 = hi;
    // 0x8037A470: lh          $t0, 0x9A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X9A);
    // 0x8037A474: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8037A478: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x8037A47C: div         $zero, $t0, $s6
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r22))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r22)));
    // 0x8037A480: mfhi        $t6
    ctx->r14 = hi;
    // 0x8037A484: sh          $t9, 0x98($sp)
    MEM_H(0X98, ctx->r29) = ctx->r25;
    // 0x8037A488: bne         $s3, $zero, L_8037A494
    if (ctx->r19 != 0) {
        // 0x8037A48C: nop
    
            goto L_8037A494;
    }
    // 0x8037A48C: nop

    // 0x8037A490: break       7
    do_break(2151130256);
L_8037A494:
    // 0x8037A494: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037A498: bne         $s3, $at, L_8037A4AC
    if (ctx->r19 != ctx->r1) {
        // 0x8037A49C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037A4AC;
    }
    // 0x8037A49C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037A4A0: bne         $t8, $at, L_8037A4AC
    if (ctx->r24 != ctx->r1) {
        // 0x8037A4A4: nop
    
            goto L_8037A4AC;
    }
    // 0x8037A4A4: nop

    // 0x8037A4A8: break       6
    do_break(2151130280);
L_8037A4AC:
    // 0x8037A4AC: multu       $s4, $t2
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A4B0: sh          $t6, 0x9A($sp)
    MEM_H(0X9A, ctx->r29) = ctx->r14;
    // 0x8037A4B4: lw          $t3, 0x34($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X34);
    // 0x8037A4B8: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8037A4BC: lw          $t6, 0xBC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XBC);
    // 0x8037A4C0: sll         $t5, $s0, 4
    ctx->r13 = S32(ctx->r16 << 4);
    // 0x8037A4C4: bne         $s6, $zero, L_8037A4D0
    if (ctx->r22 != 0) {
        // 0x8037A4C8: nop
    
            goto L_8037A4D0;
    }
    // 0x8037A4C8: nop

    // 0x8037A4CC: break       7
    do_break(2151130316);
L_8037A4D0:
    // 0x8037A4D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8037A4D4: bne         $s6, $at, L_8037A4E8
    if (ctx->r22 != ctx->r1) {
        // 0x8037A4D8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8037A4E8;
    }
    // 0x8037A4D8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8037A4DC: bne         $t0, $at, L_8037A4E8
    if (ctx->r8 != ctx->r1) {
        // 0x8037A4E0: nop
    
            goto L_8037A4E8;
    }
    // 0x8037A4E0: nop

    // 0x8037A4E4: break       6
    do_break(2151130340);
L_8037A4E8:
    // 0x8037A4E8: mflo        $t4
    ctx->r12 = lo;
    // 0x8037A4EC: sll         $t1, $t4, 4
    ctx->r9 = S32(ctx->r12 << 4);
    // 0x8037A4F0: addu        $t7, $t3, $t1
    ctx->r15 = ADD32(ctx->r11, ctx->r9);
    // 0x8037A4F4: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x8037A4F8: addiu       $t2, $sp, 0x98
    ctx->r10 = ADD32(ctx->r29, 0X98);
    // 0x8037A4FC: lbu         $a3, 0x31($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X31);
    // 0x8037A500: sll         $t0, $t9, 4
    ctx->r8 = S32(ctx->r25 << 4);
    // 0x8037A504: lhu         $a1, 0x4($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X4);
    // 0x8037A508: addu        $a2, $t8, $t0
    ctx->r6 = ADD32(ctx->r24, ctx->r8);
    // 0x8037A50C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8037A510: jal         0x80379D74
    // 0x8037A514: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_ovl8_80379D74(rdram, ctx);
        goto after_3;
    // 0x8037A514: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8037A518: lhu         $s7, 0x9E($sp)
    ctx->r23 = MEM_HU(ctx->r29, 0X9E);
L_8037A51C:
    // 0x8037A51C: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8037A520: lhu         $t4, 0x9C($sp)
    ctx->r12 = MEM_HU(ctx->r29, 0X9C);
    // 0x8037A524: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x8037A528: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8037A52C: multu       $t4, $a3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A530: addu        $s2, $s2, $s3
    ctx->r18 = ADD32(ctx->r18, ctx->r19);
    // 0x8037A534: mflo        $t3
    ctx->r11 = lo;
    // 0x8037A538: addu        $s1, $s1, $t3
    ctx->r17 = ADD32(ctx->r17, ctx->r11);
    // 0x8037A53C: bnel        $s0, $t1, L_8037A444
    if (ctx->r16 != ctx->r9) {
        // 0x8037A540: sh          $s2, 0xA0($sp)
        MEM_H(0XA0, ctx->r29) = ctx->r18;
            goto L_8037A444;
    }
    goto skip_2;
    // 0x8037A540: sh          $s2, 0xA0($sp)
    MEM_H(0XA0, ctx->r29) = ctx->r18;
    skip_2:
    // 0x8037A544: lw          $t7, 0xBC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XBC);
    // 0x8037A548: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8037A54C: lw          $v1, 0x90($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X90);
    // 0x8037A550: lhu         $v0, 0x4($t7)
    ctx->r2 = MEM_HU(ctx->r15, 0X4);
L_8037A554:
    // 0x8037A554: multu       $s7, $v0
    result = U64(U32(ctx->r23)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A558: lw          $t8, 0x88($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X88);
    // 0x8037A55C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8037A560: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8037A564: mflo        $t5
    ctx->r13 = lo;
    // 0x8037A568: nop

    // 0x8037A56C: nop

    // 0x8037A570: multu       $t5, $a3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8037A574: mflo        $t9
    ctx->r25 = lo;
    // 0x8037A578: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
    // 0x8037A57C: bnel        $at, $zero, L_8037A400
    if (ctx->r1 != 0) {
        // 0x8037A580: lw          $t1, 0x8C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X8C);
            goto L_8037A400;
    }
    goto skip_3;
    // 0x8037A580: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    skip_3:
    // 0x8037A584: sw          $s7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r23;
L_8037A588:
    // 0x8037A588: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8037A58C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8037A590: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x8037A594: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8037A598: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x8037A59C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x8037A5A0: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x8037A5A4: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8037A5A8: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x8037A5AC: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x8037A5B0: jr          $ra
    // 0x8037A5B4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x8037A5B4: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void syTaskmanCheckBreakLoop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80005C9C: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80005CA0: lw          $v0, 0x65D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X65D0);
    // 0x80005CA4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80005CA8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80005CAC: beq         $v0, $at, L_80005CC8
    if (ctx->r2 == ctx->r1) {
        // 0x80005CB0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80005CC8;
    }
    // 0x80005CB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80005CB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80005CB8: beq         $v0, $at, L_80005CD0
    if (ctx->r2 == ctx->r1) {
        // 0x80005CBC: lui         $t6, 0x8004
        ctx->r14 = S32(0X8004 << 16);
            goto L_80005CD0;
    }
    // 0x80005CBC: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80005CC0: b           L_80005D00
    // 0x80005CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005D00;
    // 0x80005CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80005CC8:
    // 0x80005CC8: b           L_80005D00
    // 0x80005CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80005D00;
    // 0x80005CCC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80005CD0:
    // 0x80005CD0: lw          $t6, 0x4FA4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4FA4);
    // 0x80005CD4: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x80005CD8: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x80005CDC: beq         $t6, $zero, L_80005CF8
    if (ctx->r14 == 0) {
        // 0x80005CE0: addiu       $a0, $sp, 0x1C
        ctx->r4 = ADD32(ctx->r29, 0X1C);
            goto L_80005CF8;
    }
    // 0x80005CE0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x80005CE4: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x80005CE8: jal         0x80000970
    // 0x80005CEC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    func_80000970(rdram, ctx);
        goto after_0;
    // 0x80005CEC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
    after_0:
    // 0x80005CF0: b           L_80005D00
    // 0x80005CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80005D00;
    // 0x80005CF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80005CF8:
    // 0x80005CF8: b           L_80005D00
    // 0x80005CFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80005D00;
    // 0x80005CFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80005D00:
    // 0x80005D00: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80005D04: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80005D08: jr          $ra
    // 0x80005D0C: nop

    return;
    // 0x80005D0C: nop

;}
RECOMP_FUNC void __initFromBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DE68: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8002DE6C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002DE70: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002DE74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8002DE78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002DE7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002DE80: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x8002DE84: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x8002DE88: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
L_8002DE8C:
    // 0x8002DE8C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8002DE90: beql        $s1, $zero, L_8002DE8C
    if (ctx->r17 == 0) {
        // 0x8002DE94: lw          $s1, 0xC($v0)
        ctx->r17 = MEM_W(ctx->r2, 0XC);
            goto L_8002DE8C;
    }
    goto skip_0;
    // 0x8002DE94: lw          $s1, 0xC($v0)
    ctx->r17 = MEM_W(ctx->r2, 0XC);
    skip_0:
    // 0x8002DE98: lbu         $t6, 0x3C($s2)
    ctx->r14 = MEM_BU(ctx->r18, 0X3C);
    // 0x8002DE9C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002DEA0: blez        $t6, L_8002DED4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8002DEA4: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8002DED4;
    }
    // 0x8002DEA4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_8002DEA8:
    // 0x8002DEA8: jal         0x8002DDB8
    // 0x8002DEAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __n_resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x8002DEAC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8002DEB0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002DEB4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8002DEB8: jal         0x8002DD4C
    // 0x8002DEBC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    __setInstChanState(rdram, ctx);
        goto after_1;
    // 0x8002DEBC: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_1:
    // 0x8002DEC0: lbu         $t7, 0x3C($s2)
    ctx->r15 = MEM_BU(ctx->r18, 0X3C);
    // 0x8002DEC4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002DEC8: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002DECC: bnel        $at, $zero, L_8002DEA8
    if (ctx->r1 != 0) {
        // 0x8002DED0: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8002DEA8;
    }
    goto skip_1;
    // 0x8002DED0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    skip_1:
L_8002DED4:
    // 0x8002DED4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8002DED8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002DEDC: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8002DEE0: beql        $t9, $zero, L_8002DF08
    if (ctx->r25 == 0) {
        // 0x8002DEE4: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8002DF08;
    }
    goto skip_2;
    // 0x8002DEE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_2:
    // 0x8002DEE8: jal         0x8002DDB8
    // 0x8002DEEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __n_resetPerfChanState(rdram, ctx);
        goto after_2;
    // 0x8002DEEC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x8002DEF0: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x8002DEF4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002DEF8: addiu       $a2, $zero, 0x9
    ctx->r6 = ADD32(0, 0X9);
    // 0x8002DEFC: jal         0x8002DD4C
    // 0x8002DF00: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    __setInstChanState(rdram, ctx);
        goto after_3;
    // 0x8002DF00: lw          $a1, 0x8($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X8);
    after_3:
    // 0x8002DF04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8002DF08:
    // 0x8002DF08: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002DF0C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002DF10: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002DF14: jr          $ra
    // 0x8002DF18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8002DF18: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl28_80133004(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133004: jr          $ra
    // 0x80133008: nop

    return;
    // 0x80133008: nop

;}
RECOMP_FUNC void grJungleMakeTaruCann(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80109E84: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80109E88: lw          $t6, 0x1300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1300);
    // 0x80109E8C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80109E90: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80109E94: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80109E98: lw          $t7, 0x80($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X80);
    // 0x80109E9C: lui         $v1, 0x0
    ctx->r3 = S32(0X0 << 16);
    // 0x80109EA0: addiu       $v1, $v1, 0xA98
    ctx->r3 = ADD32(ctx->r3, 0XA98);
    // 0x80109EA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109EA8: subu        $v0, $t7, $v1
    ctx->r2 = SUB32(ctx->r15, ctx->r3);
    // 0x80109EAC: sw          $v0, 0x13F0($at)
    MEM_W(0X13F0, ctx->r1) = ctx->r2;
    // 0x80109EB0: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x80109EB4: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x80109EB8: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x80109EBC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80109EC0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80109EC4: jal         0x80009968
    // 0x80109EC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80109EC8: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80109ECC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109ED0: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80109ED4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80109ED8: sw          $v0, 0x13F4($at)
    MEM_W(0X13F4, ctx->r1) = ctx->r2;
    // 0x80109EDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80109EE0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80109EE4: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80109EE8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80109EEC: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x80109EF0: jal         0x80009DF4
    // 0x80109EF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80109EF4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80109EF8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x80109EFC: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80109F00: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x80109F04: addiu       $a3, $a3, -0x14B0
    ctx->r7 = ADD32(ctx->r7, -0X14B0);
    // 0x80109F08: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80109F0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80109F10: jal         0x80105760
    // 0x80109F14: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    grModelSetupGroundDObjs(rdram, ctx);
        goto after_2;
    // 0x80109F14: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_2:
    // 0x80109F18: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80109F1C: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x80109F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80109F24: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80109F28: jal         0x80008188
    // 0x80109F2C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x80109F2C: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x80109F30: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80109F34: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80109F38: addiu       $t2, $t2, 0xB20
    ctx->r10 = ADD32(ctx->r10, 0XB20);
    // 0x80109F3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80109F40: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80109F44: jal         0x8000BD8C
    // 0x80109F48: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    gcAddAnimJointAll(rdram, ctx);
        goto after_4;
    // 0x80109F48: addu        $a1, $t1, $t2
    ctx->r5 = ADD32(ctx->r9, ctx->r10);
    after_4:
    // 0x80109F4C: jal         0x8000DF34
    // 0x80109F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_5;
    // 0x80109F50: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80109F54: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80109F58: addiu       $a1, $a1, -0x61CC
    ctx->r5 = ADD32(ctx->r5, -0X61CC);
    // 0x80109F5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80109F60: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80109F64: jal         0x80008188
    // 0x80109F68: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    gcAddGObjProcess(rdram, ctx);
        goto after_6;
    // 0x80109F68: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_6:
    // 0x80109F6C: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80109F70: addiu       $a1, $a1, -0x6028
    ctx->r5 = ADD32(ctx->r5, -0X6028);
    // 0x80109F74: jal         0x800E1D48
    // 0x80109F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainCheckAddGroundObstacle(rdram, ctx);
        goto after_7;
    // 0x80109F78: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80109F7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109F80: sb          $zero, 0x13F8($at)
    MEM_B(0X13F8, ctx->r1) = 0;
    // 0x80109F84: jal         0x80018994
    // 0x80109F88: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    syUtilsRandIntRange(rdram, ctx);
        goto after_8;
    // 0x80109F88: addiu       $a0, $zero, 0xB4
    ctx->r4 = ADD32(0, 0XB4);
    after_8:
    // 0x80109F8C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80109F90: addiu       $t3, $v0, 0xB4
    ctx->r11 = ADD32(ctx->r2, 0XB4);
    // 0x80109F94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109F98: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80109F9C: sh          $t3, 0x13FA($at)
    MEM_H(0X13FA, ctx->r1) = ctx->r11;
    // 0x80109FA0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80109FA4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80109FA8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80109FAC: jr          $ra
    // 0x80109FB0: swc1        $f4, 0x13FC($at)
    MEM_W(0X13FC, ctx->r1) = ctx->f4.u32l;
    return;
    // 0x80109FB0: swc1        $f4, 0x13FC($at)
    MEM_W(0X13FC, ctx->r1) = ctx->f4.u32l;
;}
RECOMP_FUNC void syDebugReportCPUBreakFault(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80023190: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80023194: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80023198: lui         $s1, 0x800A
    ctx->r17 = S32(0X800A << 16);
    // 0x8002319C: addiu       $s1, $s1, -0x1C48
    ctx->r17 = ADD32(ctx->r17, -0X1C48);
    // 0x800231A0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800231A4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800231A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800231AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800231B0: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800231B4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800231B8: jal         0x800334A0
    // 0x800231BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800231BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800231C0: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800231C4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800231C8: jal         0x800334A0
    // 0x800231CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800231CC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x800231D0: addiu       $s0, $sp, 0x2C
    ctx->r16 = ADD32(ctx->r29, 0X2C);
L_800231D4:
    // 0x800231D4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800231D8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800231DC: jal         0x80030210
    // 0x800231E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800231E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
    // 0x800231E4: jal         0x80022F98
    // 0x800231E8: nop

    syDebugGetFaultThread(rdram, ctx);
        goto after_3;
    // 0x800231E8: nop

    after_3:
    // 0x800231EC: beq         $v0, $zero, L_800231D4
    if (ctx->r2 == 0) {
        // 0x800231F0: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_800231D4;
    }
    // 0x800231F0: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800231F4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800231F8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800231FC: sb          $t6, -0x3188($at)
    MEM_B(-0X3188, ctx->r1) = ctx->r14;
    // 0x80023200: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023204: jal         0x80022908
    // 0x80023208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_4;
    // 0x80023208: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8002320C: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x80023210: jal         0x80022908
    // 0x80023214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_5;
    // 0x80023214: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x80023218: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002321C: jal         0x80022908
    // 0x80023220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_6;
    // 0x80023220: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x80023224: addiu       $a0, $zero, 0x808
    ctx->r4 = ADD32(0, 0X808);
    // 0x80023228: jal         0x80022908
    // 0x8002322C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_7;
    // 0x8002322C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80023230: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023234: jal         0x80022908
    // 0x80023238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_8;
    // 0x80023238: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8002323C: ori         $a0, $zero, 0x8200
    ctx->r4 = 0 | 0X8200;
    // 0x80023240: jal         0x80022908
    // 0x80023244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_9;
    // 0x80023244: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_9:
    // 0x80023248: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8002324C: jal         0x80022908
    // 0x80023250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_10;
    // 0x80023250: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80023254: addiu       $a0, $zero, 0x4100
    ctx->r4 = ADD32(0, 0X4100);
    // 0x80023258: jal         0x80022908
    // 0x8002325C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_11;
    // 0x8002325C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80023260: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80023264: jal         0x80022908
    // 0x80023268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_12;
    // 0x80023268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8002326C: addiu       $a0, $zero, 0x404
    ctx->r4 = ADD32(0, 0X404);
    // 0x80023270: jal         0x80022908
    // 0x80023274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_13;
    // 0x80023274: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80023278: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8002327C: jal         0x80022984
    // 0x80023280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    syDebugFramebufferPrintThreadStatus(rdram, ctx);
        goto after_14;
    // 0x80023280: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_14:
    // 0x80023284: lui         $s0, 0x800A
    ctx->r16 = S32(0X800A << 16);
    // 0x80023288: addiu       $s0, $s0, -0x1C28
    ctx->r16 = ADD32(ctx->r16, -0X1C28);
    // 0x8002328C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80023290: beq         $t7, $zero, L_80023304
    if (ctx->r15 == 0) {
        // 0x80023294: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80023304;
    }
    // 0x80023294: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80023298:
    // 0x80023298: jal         0x80022908
    // 0x8002329C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_15;
    // 0x8002329C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800232A0: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x800232A4: jal         0x80022908
    // 0x800232A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_16;
    // 0x800232A8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x800232AC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x800232B0: addiu       $a1, $zero, 0x14
    ctx->r5 = ADD32(0, 0X14);
    // 0x800232B4: addiu       $a2, $zero, 0x10E
    ctx->r6 = ADD32(0, 0X10E);
    // 0x800232B8: jal         0x800223F4
    // 0x800232BC: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    syDebugFramebufferDrawBlackRectangle(rdram, ctx);
        goto after_17;
    // 0x800232BC: addiu       $a3, $zero, 0xD2
    ctx->r7 = ADD32(0, 0XD2);
    after_17:
    // 0x800232C0: addiu       $a0, $zero, 0x1E
    ctx->r4 = ADD32(0, 0X1E);
    // 0x800232C4: jal         0x80023010
    // 0x800232C8: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    syDebugResetMesgCursor(rdram, ctx);
        goto after_18;
    // 0x800232C8: addiu       $a1, $zero, 0x19
    ctx->r5 = ADD32(0, 0X19);
    after_18:
    // 0x800232CC: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800232D0: jalr        $t9
    // 0x800232D4: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_19;
    // 0x800232D4: nop

    after_19:
    // 0x800232D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800232DC: jal         0x80022908
    // 0x800232E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_20;
    // 0x800232E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_20:
    // 0x800232E4: addiu       $a0, $zero, 0x2030
    ctx->r4 = ADD32(0, 0X2030);
    // 0x800232E8: jal         0x80022908
    // 0x800232EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugWaitFramebufferOrController(rdram, ctx);
        goto after_21;
    // 0x800232EC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_21:
    // 0x800232F0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800232F4: jal         0x80022984
    // 0x800232F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    syDebugFramebufferPrintThreadStatus(rdram, ctx);
        goto after_22;
    // 0x800232F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_22:
    // 0x800232FC: b           L_80023298
    // 0x80023300: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_80023298;
    // 0x80023300: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80023304:
    // 0x80023304: b           L_80023304
    pause_self(rdram);
    // 0x80023308: nop

    // 0x8002330C: nop

    // 0x80023310: nop

    // 0x80023314: nop

    // 0x80023318: nop

    // 0x8002331C: nop

    // 0x80023320: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80023324: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80023328: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002332C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80023330: jr          $ra
    // 0x80023334: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80023334: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mpCollisionGetFCCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3A78: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800F3A7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800F3A80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F3A84: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x800F3A88: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800F3A8C: beq         $a0, $at, L_800F3AA0
    if (ctx->r4 == ctx->r1) {
        // 0x800F3A90: sw          $a3, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r7;
            goto L_800F3AA0;
    }
    // 0x800F3A90: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800F3A94: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800F3A98: bne         $a0, $at, L_800F3AC0
    if (ctx->r4 != ctx->r1) {
        // 0x800F3A9C: lw          $t8, 0x50($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X50);
            goto L_800F3AC0;
    }
    // 0x800F3A9C: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
L_800F3AA0:
    // 0x800F3AA0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F3AA4: addiu       $a0, $a0, 0x270
    ctx->r4 = ADD32(ctx->r4, 0X270);
    // 0x800F3AA8: jal         0x80023624
    // 0x800F3AAC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800F3AAC: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    after_0:
    // 0x800F3AB0: jal         0x800A3040
    // 0x800F3AB4: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_1;
    // 0x800F3AB4: nop

    after_1:
    // 0x800F3AB8: b           L_800F3AA0
    // 0x800F3ABC: nop

        goto L_800F3AA0;
    // 0x800F3ABC: nop

L_800F3AC0:
    // 0x800F3AC0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800F3AC4: lw          $t7, 0x136C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X136C);
    // 0x800F3AC8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800F3ACC: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800F3AD0: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x800F3AD4: addu        $t4, $t7, $t9
    ctx->r12 = ADD32(ctx->r15, ctx->r25);
    // 0x800F3AD8: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x800F3ADC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F3AE0: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800F3AE4: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800F3AE8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800F3AEC: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800F3AF0: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x800F3AF4: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x800F3AF8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800F3AFC: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800F3B00: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F3B04: bne         $at, $zero, L_800F3B24
    if (ctx->r1 != 0) {
        // 0x800F3B08: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800F3B24;
    }
L_800F3B08:
    // 0x800F3B08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F3B0C: jal         0x80023624
    // 0x800F3B10: addiu       $a0, $a0, 0x28C
    ctx->r4 = ADD32(ctx->r4, 0X28C);
    syDebugPrintf(rdram, ctx);
        goto after_2;
    // 0x800F3B10: addiu       $a0, $a0, 0x28C
    ctx->r4 = ADD32(ctx->r4, 0X28C);
    after_2:
    // 0x800F3B14: jal         0x800A3040
    // 0x800F3B18: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_3;
    // 0x800F3B18: nop

    after_3:
    // 0x800F3B1C: b           L_800F3B08
    // 0x800F3B20: nop

        goto L_800F3B08;
    // 0x800F3B20: nop

L_800F3B24:
    // 0x800F3B24: lw          $t8, 0x70($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X70);
    // 0x800F3B28: lw          $t5, 0x1378($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X1378);
    // 0x800F3B2C: sll         $t4, $t9, 2
    ctx->r12 = S32(ctx->r25 << 2);
    // 0x800F3B30: bne         $t8, $zero, L_800F3B40
    if (ctx->r24 != 0) {
        // 0x800F3B34: addu        $t3, $t4, $t5
        ctx->r11 = ADD32(ctx->r12, ctx->r13);
            goto L_800F3B40;
    }
    // 0x800F3B34: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x800F3B38: beql        $v1, $zero, L_800F3B60
    if (ctx->r3 == 0) {
        // 0x800F3B3C: lwc1        $f12, 0x0($a1)
        ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
            goto L_800F3B60;
    }
    goto skip_0;
    // 0x800F3B3C: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
    skip_0:
L_800F3B40:
    // 0x800F3B40: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800F3B44: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800F3B48: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800F3B4C: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x800F3B50: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800F3B54: b           L_800F3B64
    // 0x800F3B58: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
        goto L_800F3B64;
    // 0x800F3B58: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800F3B5C: lwc1        $f12, 0x0($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X0);
L_800F3B60:
    // 0x800F3B60: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
L_800F3B64:
    // 0x800F3B64: lhu         $v0, 0x0($t3)
    ctx->r2 = MEM_HU(ctx->r11, 0X0);
    // 0x800F3B68: lw          $t1, 0x1374($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X1374);
    // 0x800F3B6C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800F3B70: sll         $t6, $v0, 1
    ctx->r14 = S32(ctx->r2 << 1);
    // 0x800F3B74: addu        $v1, $t1, $t6
    ctx->r3 = ADD32(ctx->r9, ctx->r14);
    // 0x800F3B78: lhu         $t7, 0x0($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X0);
    // 0x800F3B7C: lhu         $t2, 0x2($t3)
    ctx->r10 = MEM_HU(ctx->r11, 0X2);
    // 0x800F3B80: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x800F3B84: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F3B88: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800F3B8C: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800F3B90: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800F3B94: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x800F3B98: lhu         $t7, 0x0($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X0);
    // 0x800F3B9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F3BA0: lw          $a0, 0x1370($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1370);
    // 0x800F3BA4: mflo        $t9
    ctx->r25 = lo;
    // 0x800F3BA8: addu        $a2, $a0, $t9
    ctx->r6 = ADD32(ctx->r4, ctx->r25);
    // 0x800F3BAC: lh          $a1, 0x0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X0);
    // 0x800F3BB0: multu       $t7, $t0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F3BB4: mflo        $t9
    ctx->r25 = lo;
    // 0x800F3BB8: addu        $t4, $a0, $t9
    ctx->r12 = ADD32(ctx->r4, ctx->r25);
    // 0x800F3BBC: lh          $a3, 0x0($t4)
    ctx->r7 = MEM_H(ctx->r12, 0X0);
    // 0x800F3BC0: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800F3BC4: beql        $at, $zero, L_800F3BE4
    if (ctx->r1 == 0) {
        // 0x800F3BC8: mtc1        $a3, $f6
        ctx->f6.u32l = ctx->r7;
            goto L_800F3BE4;
    }
    goto skip_1;
    // 0x800F3BC8: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    skip_1:
    // 0x800F3BCC: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800F3BD0: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800F3BD4: cvt.s.w     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    ctx->f2.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800F3BD8: b           L_800F3BF0
    // 0x800F3BDC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
        goto L_800F3BF0;
    // 0x800F3BDC: cvt.s.w     $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    ctx->f14.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F3BE0: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
L_800F3BE4:
    // 0x800F3BE4: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800F3BE8: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F3BEC: cvt.s.w     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    ctx->f14.fl = CVT_S_W(ctx->f8.u32l);
L_800F3BF0:
    // 0x800F3BF0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F3BF4: lwc1        $f0, 0x770($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X770);
    // 0x800F3BF8: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800F3BFC: c.le.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl <= ctx->f10.fl;
    // 0x800F3C00: nop

    // 0x800F3C04: bc1t        L_800F3C24
    if (c1cs) {
        // 0x800F3C08: nop
    
            goto L_800F3C24;
    }
    // 0x800F3C08: nop

    // 0x800F3C0C: add.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x800F3C10: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800F3C14: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x800F3C18: nop

    // 0x800F3C1C: bc1fl       L_800F3C30
    if (!c1cs) {
        // 0x800F3C20: c.le.s      $f12, $f14
        CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
            goto L_800F3C30;
    }
    goto skip_2;
    // 0x800F3C20: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
    skip_2:
L_800F3C24:
    // 0x800F3C24: b           L_800F3DC8
    // 0x800F3C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800F3DC8;
    // 0x800F3C28: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F3C2C: c.le.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl <= ctx->f14.fl;
L_800F3C30:
    // 0x800F3C30: nop

    // 0x800F3C34: bc1fl       L_800F3C48
    if (!c1cs) {
        // 0x800F3C38: c.le.s      $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
            goto L_800F3C48;
    }
    goto skip_3;
    // 0x800F3C38: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
    skip_3:
    // 0x800F3C3C: b           L_800F3C58
    // 0x800F3C40: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_800F3C58;
    // 0x800F3C40: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
    // 0x800F3C44: c.le.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl <= ctx->f12.fl;
L_800F3C48:
    // 0x800F3C48: nop

    // 0x800F3C4C: bc1f        L_800F3C58
    if (!c1cs) {
        // 0x800F3C50: nop
    
            goto L_800F3C58;
    }
    // 0x800F3C50: nop

    // 0x800F3C54: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_800F3C58:
    // 0x800F3C58: beql        $t2, $at, L_800F3D38
    if (ctx->r10 == ctx->r1) {
        // 0x800F3C5C: lh          $t8, 0x2($a2)
        ctx->r24 = MEM_H(ctx->r6, 0X2);
            goto L_800F3D38;
    }
    goto skip_4;
    // 0x800F3C5C: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    skip_4:
    // 0x800F3C60: blez        $t2, L_800F3D34
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800F3C64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800F3D34;
    }
    // 0x800F3C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F3C68:
    // 0x800F3C68: lhu         $t5, 0x0($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X0);
    // 0x800F3C6C: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x800F3C70: multu       $t5, $t0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F3C74: mflo        $t8
    ctx->r24 = lo;
    // 0x800F3C78: addu        $a2, $a0, $t8
    ctx->r6 = ADD32(ctx->r4, ctx->r24);
    // 0x800F3C7C: lh          $a1, 0x0($a2)
    ctx->r5 = MEM_H(ctx->r6, 0X0);
    // 0x800F3C80: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F3C84: mflo        $t7
    ctx->r15 = lo;
    // 0x800F3C88: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x800F3C8C: lh          $a3, 0x0($t9)
    ctx->r7 = MEM_H(ctx->r25, 0X0);
    // 0x800F3C90: bnel        $a3, $a1, L_800F3CB8
    if (ctx->r7 != ctx->r5) {
        // 0x800F3C94: mtc1        $a1, $f4
        ctx->f4.u32l = ctx->r5;
            goto L_800F3CB8;
    }
    goto skip_5;
    // 0x800F3C94: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    skip_5:
L_800F3C98:
    // 0x800F3C98: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800F3C9C: jal         0x80023624
    // 0x800F3CA0: addiu       $a0, $a0, 0x2AC
    ctx->r4 = ADD32(ctx->r4, 0X2AC);
    syDebugPrintf(rdram, ctx);
        goto after_4;
    // 0x800F3CA0: addiu       $a0, $a0, 0x2AC
    ctx->r4 = ADD32(ctx->r4, 0X2AC);
    after_4:
    // 0x800F3CA4: jal         0x800A3040
    // 0x800F3CA8: nop

    scManagerRunPrintGObjStatus(rdram, ctx);
        goto after_5;
    // 0x800F3CA8: nop

    after_5:
    // 0x800F3CAC: b           L_800F3C98
    // 0x800F3CB0: nop

        goto L_800F3C98;
    // 0x800F3CB0: nop

    // 0x800F3CB4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
L_800F3CB8:
    // 0x800F3CB8: nop

    // 0x800F3CBC: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F3CC0: c.le.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl <= ctx->f12.fl;
    // 0x800F3CC4: nop

    // 0x800F3CC8: bc1fl       L_800F3CF0
    if (!c1cs) {
        // 0x800F3CCC: mtc1        $a3, $f10
        ctx->f10.u32l = ctx->r7;
            goto L_800F3CF0;
    }
    goto skip_6;
    // 0x800F3CCC: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    skip_6:
    // 0x800F3CD0: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x800F3CD4: nop

    // 0x800F3CD8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800F3CDC: c.le.s      $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f12.fl <= ctx->f8.fl;
    // 0x800F3CE0: nop

    // 0x800F3CE4: bc1tl       L_800F3D38
    if (c1cs) {
        // 0x800F3CE8: lh          $t8, 0x2($a2)
        ctx->r24 = MEM_H(ctx->r6, 0X2);
            goto L_800F3D38;
    }
    goto skip_7;
    // 0x800F3CE8: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    skip_7:
    // 0x800F3CEC: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
L_800F3CF0:
    // 0x800F3CF0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800F3CF4: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F3CF8: c.le.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl <= ctx->f12.fl;
    // 0x800F3CFC: nop

    // 0x800F3D00: bc1f        L_800F3D18
    if (!c1cs) {
        // 0x800F3D04: nop
    
            goto L_800F3D18;
    }
    // 0x800F3D04: nop

    // 0x800F3D08: c.le.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl <= ctx->f0.fl;
    // 0x800F3D0C: nop

    // 0x800F3D10: bc1tl       L_800F3D38
    if (c1cs) {
        // 0x800F3D14: lh          $t8, 0x2($a2)
        ctx->r24 = MEM_H(ctx->r6, 0X2);
            goto L_800F3D38;
    }
    goto skip_8;
    // 0x800F3D14: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    skip_8:
L_800F3D18:
    // 0x800F3D18: bne         $v0, $t2, L_800F3C68
    if (ctx->r2 != ctx->r10) {
        // 0x800F3D1C: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_800F3C68;
    }
    // 0x800F3D1C: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x800F3D20: lhu         $t4, 0x0($v1)
    ctx->r12 = MEM_HU(ctx->r3, 0X0);
    // 0x800F3D24: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800F3D28: subu        $t5, $t5, $t4
    ctx->r13 = SUB32(ctx->r13, ctx->r12);
    // 0x800F3D2C: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x800F3D30: addu        $a2, $a0, $t5
    ctx->r6 = ADD32(ctx->r4, ctx->r13);
L_800F3D34:
    // 0x800F3D34: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
L_800F3D38:
    // 0x800F3D38: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800F3D3C: sw          $t8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r24;
    // 0x800F3D40: lhu         $t6, 0x2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X2);
    // 0x800F3D44: multu       $t6, $t0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F3D48: mflo        $t7
    ctx->r15 = lo;
    // 0x800F3D4C: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x800F3D50: beq         $t4, $zero, L_800F3D60
    if (ctx->r12 == 0) {
        // 0x800F3D54: lh          $v0, 0x2($t9)
        ctx->r2 = MEM_H(ctx->r25, 0X2);
            goto L_800F3D60;
    }
    // 0x800F3D54: lh          $v0, 0x2($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X2);
    // 0x800F3D58: lhu         $t5, 0x4($a2)
    ctx->r13 = MEM_HU(ctx->r6, 0X4);
    // 0x800F3D5C: sw          $t5, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r13;
L_800F3D60:
    // 0x800F3D60: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x800F3D64: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800F3D68: beql        $t8, $zero, L_800F3DA8
    if (ctx->r24 == 0) {
        // 0x800F3D6C: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_800F3DA8;
    }
    goto skip_9;
    // 0x800F3D6C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    skip_9:
    // 0x800F3D70: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F3D74: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800F3D78: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800F3D7C: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800F3D80: jal         0x800F39F0
    // 0x800F3D84: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    mpCollisionGetLineDistanceFC(rdram, ctx);
        goto after_6;
    // 0x800F3D84: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    after_6:
    // 0x800F3D88: lwc1        $f16, 0x24($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800F3D8C: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800F3D90: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x800F3D94: sub.s       $f4, $f0, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f16.fl;
    // 0x800F3D98: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800F3D9C: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x800F3DA0: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x800F3DA4: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
L_800F3DA8:
    // 0x800F3DA8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800F3DAC: beql        $a0, $zero, L_800F3DC8
    if (ctx->r4 == 0) {
        // 0x800F3DB0: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_800F3DC8;
    }
    goto skip_10;
    // 0x800F3DB0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    skip_10:
    // 0x800F3DB4: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800F3DB8: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800F3DBC: jal         0x800F46D0
    // 0x800F3DC0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    mpCollisionGetFCAngle(rdram, ctx);
        goto after_7;
    // 0x800F3DC0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_7:
    // 0x800F3DC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F3DC8:
    // 0x800F3DC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F3DCC: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800F3DD0: jr          $ra
    // 0x800F3DD4: nop

    return;
    // 0x800F3DD4: nop

;}
RECOMP_FUNC void mnMapsInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133C6C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C70: sw          $zero, 0x4BE0($at)
    MEM_W(0X4BE0, ctx->r1) = 0;
    // 0x80133C74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C78: sw          $zero, 0x4BE4($at)
    MEM_W(0X4BE4, ctx->r1) = 0;
    // 0x80133C7C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C80: sw          $zero, 0x4BE8($at)
    MEM_W(0X4BE8, ctx->r1) = 0;
    // 0x80133C84: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C88: sw          $zero, 0x4BF0($at)
    MEM_W(0X4BF0, ctx->r1) = 0;
    // 0x80133C8C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C90: sw          $zero, 0x4C00($at)
    MEM_W(0X4C00, ctx->r1) = 0;
    // 0x80133C94: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133C98: sw          $zero, 0x4BF4($at)
    MEM_W(0X4BF4, ctx->r1) = 0;
    // 0x80133C9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CA0: sw          $zero, 0x4C04($at)
    MEM_W(0X4C04, ctx->r1) = 0;
    // 0x80133CA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CA8: sw          $zero, 0x4BF8($at)
    MEM_W(0X4BF8, ctx->r1) = 0;
    // 0x80133CAC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CB0: sw          $zero, 0x4C08($at)
    MEM_W(0X4C08, ctx->r1) = 0;
    // 0x80133CB4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CB8: sw          $zero, 0x4BFC($at)
    MEM_W(0X4BFC, ctx->r1) = 0;
    // 0x80133CBC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CC0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x80133CC4: addiu       $v1, $v1, 0x4AD0
    ctx->r3 = ADD32(ctx->r3, 0X4AD0);
    // 0x80133CC8: sw          $zero, 0x4C0C($at)
    MEM_W(0X4C0C, ctx->r1) = 0;
    // 0x80133CCC: lbu         $v0, 0x1($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X1);
    // 0x80133CD0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80133CD4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80133CD8: beq         $v0, $at, L_80133D08
    if (ctx->r2 == ctx->r1) {
        // 0x80133CDC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80133D08;
    }
    // 0x80133CDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80133CE0: addiu       $at, $zero, 0x12
    ctx->r1 = ADD32(0, 0X12);
    // 0x80133CE4: bne         $v0, $at, L_80133D20
    if (ctx->r2 != ctx->r1) {
        // 0x80133CE8: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80133D20;
    }
    // 0x80133CE8: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80133CEC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133CF0: sw          $t6, 0x4C18($at)
    MEM_W(0X4C18, ctx->r1) = ctx->r14;
    // 0x80133CF4: jal         0x80132498
    // 0x80133CF8: lbu         $a0, 0x42($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X42);
    mnMapsGetSlot(rdram, ctx);
        goto after_0;
    // 0x80133CF8: lbu         $a0, 0x42($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X42);
    after_0:
    // 0x80133CFC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D00: b           L_80133D20
    // 0x80133D04: sw          $v0, 0x4BD8($at)
    MEM_W(0X4BD8, ctx->r1) = ctx->r2;
        goto L_80133D20;
    // 0x80133D04: sw          $v0, 0x4BD8($at)
    MEM_W(0X4BD8, ctx->r1) = ctx->r2;
L_80133D08:
    // 0x80133D08: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D0C: sw          $zero, 0x4C18($at)
    MEM_W(0X4C18, ctx->r1) = 0;
    // 0x80133D10: jal         0x80132498
    // 0x80133D14: lbu         $a0, 0x41($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X41);
    mnMapsGetSlot(rdram, ctx);
        goto after_1;
    // 0x80133D14: lbu         $a0, 0x41($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X41);
    after_1:
    // 0x80133D18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D1C: sw          $v0, 0x4BD8($at)
    MEM_W(0X4BD8, ctx->r1) = ctx->r2;
L_80133D20:
    // 0x80133D20: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80133D24: lbu         $t7, 0x4937($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4937);
    // 0x80133D28: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D2C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80133D30: sb          $t7, 0x4C1C($at)
    MEM_B(0X4C1C, ctx->r1) = ctx->r15;
    // 0x80133D34: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80133D3C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80133D40: sw          $t8, 0x4C20($at)
    MEM_W(0X4C20, ctx->r1) = ctx->r24;
    // 0x80133D44: addiu       $v0, $v0, 0x4C24
    ctx->r2 = ADD32(ctx->r2, 0X4C24);
    // 0x80133D48: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80133D4C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133D50: addiu       $t0, $zero, 0x4650
    ctx->r8 = ADD32(0, 0X4650);
    // 0x80133D54: sw          $t0, 0x4C2C($at)
    MEM_W(0X4C2C, ctx->r1) = ctx->r8;
    // 0x80133D58: jr          $ra
    // 0x80133D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80133D5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void _Litob(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038A40: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80038A44: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80038A48: andi        $v0, $a1, 0xFF
    ctx->r2 = ctx->r5 & 0XFF;
    // 0x80038A4C: addiu       $v1, $zero, 0x58
    ctx->r3 = ADD32(0, 0X58);
    // 0x80038A50: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80038A54: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80038A58: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x80038A5C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x80038A60: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80038A64: bne         $v1, $v0, L_80038A78
    if (ctx->r3 != ctx->r2) {
        // 0x80038A68: sw          $a1, 0x94($sp)
        MEM_W(0X94, ctx->r29) = ctx->r5;
            goto L_80038A78;
    }
    // 0x80038A68: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x80038A6C: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80038A70: b           L_80038A80
    // 0x80038A74: addiu       $s3, $s3, -0x29FC
    ctx->r19 = ADD32(ctx->r19, -0X29FC);
        goto L_80038A80;
    // 0x80038A74: addiu       $s3, $s3, -0x29FC
    ctx->r19 = ADD32(ctx->r19, -0X29FC);
L_80038A78:
    // 0x80038A78: lui         $s3, 0x8004
    ctx->r19 = S32(0X8004 << 16);
    // 0x80038A7C: addiu       $s3, $s3, -0x2A10
    ctx->r19 = ADD32(ctx->r19, -0X2A10);
L_80038A80:
    // 0x80038A80: addiu       $at, $zero, 0x6F
    ctx->r1 = ADD32(0, 0X6F);
    // 0x80038A84: bne         $v0, $at, L_80038A94
    if (ctx->r2 != ctx->r1) {
        // 0x80038A88: addiu       $s0, $zero, 0x18
        ctx->r16 = ADD32(0, 0X18);
            goto L_80038A94;
    }
    // 0x80038A88: addiu       $s0, $zero, 0x18
    ctx->r16 = ADD32(0, 0X18);
    // 0x80038A8C: b           L_80038AB4
    // 0x80038A90: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
        goto L_80038AB4;
    // 0x80038A90: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
L_80038A94:
    // 0x80038A94: addiu       $at, $zero, 0x78
    ctx->r1 = ADD32(0, 0X78);
    // 0x80038A98: beq         $v0, $at, L_80038AB0
    if (ctx->r2 == ctx->r1) {
        // 0x80038A9C: addiu       $t0, $zero, 0x10
        ctx->r8 = ADD32(0, 0X10);
            goto L_80038AB0;
    }
    // 0x80038A9C: addiu       $t0, $zero, 0x10
    ctx->r8 = ADD32(0, 0X10);
    // 0x80038AA0: beq         $v1, $v0, L_80038AB0
    if (ctx->r3 == ctx->r2) {
        // 0x80038AA4: nop
    
            goto L_80038AB0;
    }
    // 0x80038AA4: nop

    // 0x80038AA8: b           L_80038AB0
    // 0x80038AAC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
        goto L_80038AB0;
    // 0x80038AAC: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
L_80038AB0:
    // 0x80038AB0: or          $t1, $t0, $zero
    ctx->r9 = ctx->r8 | 0;
L_80038AB4:
    // 0x80038AB4: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80038AB8: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80038ABC: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80038AC0: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80038AC4: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80038AC8: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80038ACC: beq         $v0, $at, L_80038AE0
    if (ctx->r2 == ctx->r1) {
        // 0x80038AD0: sw          $t9, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r25;
            goto L_80038AE0;
    }
    // 0x80038AD0: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80038AD4: addiu       $at, $zero, 0x69
    ctx->r1 = ADD32(0, 0X69);
    // 0x80038AD8: bnel        $v0, $at, L_80038B1C
    if (ctx->r2 != ctx->r1) {
        // 0x80038ADC: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_80038B1C;
    }
    goto skip_0;
    // 0x80038ADC: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_0:
L_80038AE0:
    // 0x80038AE0: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x80038AE4: bgtzl       $t4, L_80038B1C
    if (SIGNED(ctx->r12) > 0) {
        // 0x80038AE8: lw          $t2, 0x60($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X60);
            goto L_80038B1C;
    }
    goto skip_1;
    // 0x80038AE8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    skip_1:
    // 0x80038AEC: bltz        $t4, L_80038AFC
    if (SIGNED(ctx->r12) < 0) {
        // 0x80038AF0: lw          $t6, 0x60($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X60);
            goto L_80038AFC;
    }
    // 0x80038AF0: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x80038AF4: b           L_80038B1C
    // 0x80038AF8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
        goto L_80038B1C;
    // 0x80038AF8: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_80038AFC:
    // 0x80038AFC: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80038B00: nor         $t8, $t6, $zero
    ctx->r24 = ~(ctx->r14 | 0);
    // 0x80038B04: sltiu       $at, $t7, 0x1
    ctx->r1 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80038B08: addu        $t8, $t8, $at
    ctx->r24 = ADD32(ctx->r24, ctx->r1);
    // 0x80038B0C: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x80038B10: sw          $t9, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r25;
    // 0x80038B14: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
    // 0x80038B18: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
L_80038B1C:
    // 0x80038B1C: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80038B20: addiu       $t0, $zero, 0x17
    ctx->r8 = ADD32(0, 0X17);
    // 0x80038B24: bne         $t2, $zero, L_80038B40
    if (ctx->r10 != 0) {
        // 0x80038B28: lw          $a0, 0x60($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X60);
            goto L_80038B40;
    }
    // 0x80038B28: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80038B2C: bnel        $t3, $zero, L_80038B44
    if (ctx->r11 != 0) {
        // 0x80038B30: addiu       $s0, $zero, 0x17
        ctx->r16 = ADD32(0, 0X17);
            goto L_80038B44;
    }
    goto skip_2;
    // 0x80038B30: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
    skip_2:
    // 0x80038B34: lw          $t4, 0x24($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X24);
    // 0x80038B38: beql        $t4, $zero, L_80038B7C
    if (ctx->r12 == 0) {
        // 0x80038B3C: addiu       $s2, $sp, 0x78
        ctx->r18 = ADD32(ctx->r29, 0X78);
            goto L_80038B7C;
    }
    goto skip_3;
    // 0x80038B3C: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    skip_3:
L_80038B40:
    // 0x80038B40: addiu       $s0, $zero, 0x17
    ctx->r16 = ADD32(0, 0X17);
L_80038B44:
    // 0x80038B44: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80038B48: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80038B4C: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80038B50: sw          $t0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r8;
    // 0x80038B54: jal         0x800309DC
    // 0x80038B58: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x80038B58: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_0:
    // 0x80038B5C: lw          $t0, 0x4C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X4C);
    // 0x80038B60: addu        $t6, $v1, $s3
    ctx->r14 = ADD32(ctx->r3, ctx->r19);
    // 0x80038B64: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x80038B68: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
    // 0x80038B6C: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80038B70: addu        $t8, $s2, $t0
    ctx->r24 = ADD32(ctx->r18, ctx->r8);
    // 0x80038B74: sb          $t7, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r15;
    // 0x80038B78: addiu       $s2, $sp, 0x78
    ctx->r18 = ADD32(ctx->r29, 0X78);
L_80038B7C:
    // 0x80038B7C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x80038B80: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x80038B84: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80038B88: sra         $a2, $t1, 31
    ctx->r6 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80038B8C: jal         0x80030A18
    // 0x80038B90: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x80038B90: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    after_1:
    // 0x80038B94: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80038B98: sw          $v1, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r3;
    // 0x80038B9C: bltz        $v0, L_80038C4C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80038BA0: sw          $v0, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r2;
            goto L_80038C4C;
    }
    // 0x80038BA0: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x80038BA4: bgtz        $v0, L_80038BB4
    if (SIGNED(ctx->r2) > 0) {
        // 0x80038BA8: nop
    
            goto L_80038BB4;
    }
    // 0x80038BA8: nop

    // 0x80038BAC: beql        $v1, $zero, L_80038C50
    if (ctx->r3 == 0) {
        // 0x80038BB0: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80038C50;
    }
    goto skip_4;
    // 0x80038BB0: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_4:
L_80038BB4:
    // 0x80038BB4: blez        $s0, L_80038C4C
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80038BB8: sra         $t4, $t1, 31
        ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
            goto L_80038C4C;
    }
    // 0x80038BB8: sra         $t4, $t1, 31
    ctx->r12 = S32(SIGNED(ctx->r9) >> 31);
    // 0x80038BBC: lw          $t2, 0x0($s1)
    ctx->r10 = MEM_W(ctx->r17, 0X0);
    // 0x80038BC0: lw          $t3, 0x4($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X4);
    // 0x80038BC4: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80038BC8: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x80038BCC: sw          $t2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r10;
    // 0x80038BD0: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x80038BD4: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
L_80038BD8:
    // 0x80038BD8: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80038BDC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80038BE0: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80038BE4: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80038BE8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80038BEC: jal         0x800388B0
    // 0x80038BF0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    lldiv_recomp(rdram, ctx);
        goto after_2;
    // 0x80038BF0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_2:
    // 0x80038BF4: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80038BF8: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80038BFC: addiu       $a0, $s0, -0x1
    ctx->r4 = ADD32(ctx->r16, -0X1);
    // 0x80038C00: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80038C04: sw          $t9, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r25;
    // 0x80038C08: lw          $t3, 0x5C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X5C);
    // 0x80038C0C: addu        $t7, $s2, $a0
    ctx->r15 = ADD32(ctx->r18, ctx->r4);
    // 0x80038C10: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80038C14: addu        $t5, $t3, $s3
    ctx->r13 = ADD32(ctx->r11, ctx->r19);
    // 0x80038C18: lbu         $t6, 0x0($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X0);
    // 0x80038C1C: sb          $t6, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r14;
    // 0x80038C20: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80038C24: lw          $t9, 0x4($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4);
    // 0x80038C28: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x80038C2C: bltz        $t8, L_80038C4C
    if (SIGNED(ctx->r24) < 0) {
        // 0x80038C30: sw          $t9, 0x44($sp)
        MEM_W(0X44, ctx->r29) = ctx->r25;
            goto L_80038C4C;
    }
    // 0x80038C30: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x80038C34: bgtz        $t8, L_80038C44
    if (SIGNED(ctx->r24) > 0) {
        // 0x80038C38: nop
    
            goto L_80038C44;
    }
    // 0x80038C38: nop

    // 0x80038C3C: beql        $t9, $zero, L_80038C50
    if (ctx->r25 == 0) {
        // 0x80038C40: addiu       $t4, $zero, 0x18
        ctx->r12 = ADD32(0, 0X18);
            goto L_80038C50;
    }
    goto skip_5;
    // 0x80038C40: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
    skip_5:
L_80038C44:
    // 0x80038C44: bgtzl       $s0, L_80038BD8
    if (SIGNED(ctx->r16) > 0) {
        // 0x80038C48: lw          $t6, 0x38($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X38);
            goto L_80038BD8;
    }
    goto skip_6;
    // 0x80038C48: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    skip_6:
L_80038C4C:
    // 0x80038C4C: addiu       $t4, $zero, 0x18
    ctx->r12 = ADD32(0, 0X18);
L_80038C50:
    // 0x80038C50: subu        $a2, $t4, $s0
    ctx->r6 = SUB32(ctx->r12, ctx->r16);
    // 0x80038C54: sw          $a2, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->r6;
    // 0x80038C58: lw          $a0, 0x8($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X8);
    // 0x80038C5C: jal         0x800343E0
    // 0x80038C60: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    memcpy_recomp(rdram, ctx);
        goto after_3;
    // 0x80038C60: addu        $a1, $s2, $s0
    ctx->r5 = ADD32(ctx->r18, ctx->r16);
    after_3:
    // 0x80038C64: lw          $a1, 0x14($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X14);
    // 0x80038C68: lw          $a0, 0x24($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X24);
    // 0x80038C6C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80038C70: beq         $at, $zero, L_80038C7C
    if (ctx->r1 == 0) {
        // 0x80038C74: subu        $t5, $a0, $a1
        ctx->r13 = SUB32(ctx->r4, ctx->r5);
            goto L_80038C7C;
    }
    // 0x80038C74: subu        $t5, $a0, $a1
    ctx->r13 = SUB32(ctx->r4, ctx->r5);
    // 0x80038C78: sw          $t5, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r13;
L_80038C7C:
    // 0x80038C7C: bgezl       $a0, L_80038CC0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80038C80: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80038CC0;
    }
    goto skip_7;
    // 0x80038C80: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_7:
    // 0x80038C84: lw          $t6, 0x30($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X30);
    // 0x80038C88: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x80038C8C: andi        $t7, $t6, 0x14
    ctx->r15 = ctx->r14 & 0X14;
    // 0x80038C90: bnel        $t7, $at, L_80038CC0
    if (ctx->r15 != ctx->r1) {
        // 0x80038C94: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80038CC0;
    }
    goto skip_8;
    // 0x80038C94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_8:
    // 0x80038C98: lw          $t8, 0x28($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X28);
    // 0x80038C9C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x80038CA0: lw          $v0, 0x10($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X10);
    // 0x80038CA4: subu        $t2, $t8, $t9
    ctx->r10 = SUB32(ctx->r24, ctx->r25);
    // 0x80038CA8: subu        $t3, $t2, $v0
    ctx->r11 = SUB32(ctx->r10, ctx->r2);
    // 0x80038CAC: subu        $s0, $t3, $a1
    ctx->r16 = SUB32(ctx->r11, ctx->r5);
    // 0x80038CB0: blez        $s0, L_80038CBC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x80038CB4: addu        $t4, $v0, $s0
        ctx->r12 = ADD32(ctx->r2, ctx->r16);
            goto L_80038CBC;
    }
    // 0x80038CB4: addu        $t4, $v0, $s0
    ctx->r12 = ADD32(ctx->r2, ctx->r16);
    // 0x80038CB8: sw          $t4, 0x10($s1)
    MEM_W(0X10, ctx->r17) = ctx->r12;
L_80038CBC:
    // 0x80038CBC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80038CC0:
    // 0x80038CC0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80038CC4: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80038CC8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x80038CCC: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x80038CD0: jr          $ra
    // 0x80038CD4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x80038CD4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void efManagerDeadExplodeMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801021C0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x801021C4: andi        $t7, $a2, 0x1
    ctx->r15 = ctx->r6 & 0X1;
    // 0x801021C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x801021CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801021D0: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x801021D4: addu        $t9, $t8, $a1
    ctx->r25 = ADD32(ctx->r24, ctx->r5);
    // 0x801021D8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x801021DC: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801021E0: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x801021E4: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801021E8: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x801021EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801021F0: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x801021F4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x801021F8: lbu         $a1, -0x1C9C($a1)
    ctx->r5 = MEM_BU(ctx->r5, -0X1C9C);
    // 0x801021FC: jal         0x800CE9E8
    // 0x80102200: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    lbParticleMakeScriptID(rdram, ctx);
        goto after_0;
    // 0x80102200: ori         $a0, $a0, 0x10
    ctx->r4 = ctx->r4 | 0X10;
    after_0:
    // 0x80102204: beq         $v0, $zero, L_80102298
    if (ctx->r2 == 0) {
        // 0x80102208: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80102298;
    }
    // 0x80102208: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010220C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80102210: jal         0x800CE1DC
    // 0x80102214: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    lbParticleAddTransformForStruct(rdram, ctx);
        goto after_1;
    // 0x80102214: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x80102218: beq         $v0, $zero, L_80102290
    if (ctx->r2 == 0) {
        // 0x8010221C: lw          $a0, 0x28($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X28);
            goto L_80102290;
    }
    // 0x8010221C: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80102220: jal         0x800CEA14
    // 0x80102224: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    LBParticleProcessStruct(rdram, ctx);
        goto after_2;
    // 0x80102224: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_2:
    // 0x80102228: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8010222C: lw          $t3, 0x40($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X40);
    // 0x80102230: lhu         $t2, 0x2A($v1)
    ctx->r10 = MEM_HU(ctx->r3, 0X2A);
    // 0x80102234: bnel        $t2, $zero, L_80102248
    if (ctx->r10 != 0) {
        // 0x80102238: lw          $t5, 0x0($t3)
        ctx->r13 = MEM_W(ctx->r11, 0X0);
            goto L_80102248;
    }
    goto skip_0;
    // 0x80102238: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
    skip_0:
    // 0x8010223C: b           L_801023C0
    // 0x80102240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801023C0;
    // 0x80102240: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80102244: lw          $t5, 0x0($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X0);
L_80102248:
    // 0x80102248: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010224C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80102250: lw          $t4, 0x4($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X4);
    // 0x80102254: sw          $t4, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r12;
    // 0x80102258: lw          $t5, 0x8($t3)
    ctx->r13 = MEM_W(ctx->r11, 0X8);
    // 0x8010225C: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x80102260: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x80102264: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80102268: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8010226C: lwc1        $f4, -0x20F0($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X20F0);
    // 0x80102270: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80102274: lwc1        $f6, 0x9F4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X9F4);
    // 0x80102278: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x8010227C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80102280: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80102284: div.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80102288: b           L_80102298
    // 0x8010228C: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
        goto L_80102298;
    // 0x8010228C: swc1        $f16, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->f16.u32l;
L_80102290:
    // 0x80102290: jal         0x800CEA40
    // 0x80102294: nop

    lbParticleEjectStruct(rdram, ctx);
        goto after_3;
    // 0x80102294: nop

    after_3:
L_80102298:
    // 0x80102298: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8010229C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801022A0: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x801022A4: lw          $t9, -0x1C94($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1C94);
    // 0x801022A8: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801022AC: addiu       $a0, $a0, -0x1CC4
    ctx->r4 = ADD32(ctx->r4, -0X1CC4);
    // 0x801022B0: jal         0x800FDB1C
    // 0x801022B4: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    efManagerMakeEffectForce(rdram, ctx);
        goto after_4;
    // 0x801022B4: sw          $t9, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r25;
    after_4:
    // 0x801022B8: bne         $v0, $zero, L_801022C8
    if (ctx->r2 != 0) {
        // 0x801022BC: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_801022C8;
    }
    // 0x801022BC: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x801022C0: b           L_801023C0
    // 0x801022C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801023C0;
    // 0x801022C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801022C8:
    // 0x801022C8: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x801022CC: lw          $a0, 0x74($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X74);
    // 0x801022D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801022D4: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801022D8: lw          $a1, 0x10($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X10);
    // 0x801022DC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801022E0: sw          $t3, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r11;
    // 0x801022E4: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801022E8: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x801022EC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x801022F0: sw          $t2, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->r10;
    // 0x801022F4: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801022F8: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x801022FC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x80102300: sw          $t3, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->r11;
    // 0x80102304: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80102308: addu        $t2, $t2, $s0
    ctx->r10 = ADD32(ctx->r10, ctx->r16);
    // 0x8010230C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x80102310: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80102314: addu        $at, $at, $t5
    ctx->r1 = ADD32(ctx->r1, ctx->r13);
    // 0x80102318: lwc1        $f18, -0x20F0($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X20F0);
    // 0x8010231C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80102320: lwc1        $f4, 0x9F8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X9F8);
    // 0x80102324: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80102328: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010232C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80102330: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80102334: swc1        $f10, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->f10.u32l;
    // 0x80102338: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x8010233C: lbu         $t7, -0x2108($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X2108);
    // 0x80102340: lw          $v1, 0x8($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X8);
    // 0x80102344: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80102348: addu        $t6, $t6, $s0
    ctx->r14 = ADD32(ctx->r14, ctx->r16);
    // 0x8010234C: lw          $t8, 0x80($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X80);
    // 0x80102350: sb          $t7, 0x60($t8)
    MEM_B(0X60, ctx->r24) = ctx->r15;
    // 0x80102354: lbu         $t9, -0x2104($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X2104);
    // 0x80102358: lw          $t1, 0x80($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X80);
    // 0x8010235C: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80102360: addu        $t8, $t8, $s0
    ctx->r24 = ADD32(ctx->r24, ctx->r16);
    // 0x80102364: sb          $t9, 0x61($t1)
    MEM_B(0X61, ctx->r9) = ctx->r25;
    // 0x80102368: lbu         $t2, -0x2100($t2)
    ctx->r10 = MEM_BU(ctx->r10, -0X2100);
    // 0x8010236C: lw          $t3, 0x80($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X80);
    // 0x80102370: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80102374: addu        $t1, $t1, $s0
    ctx->r9 = ADD32(ctx->r9, ctx->r16);
    // 0x80102378: sb          $t2, 0x62($t3)
    MEM_B(0X62, ctx->r11) = ctx->r10;
    // 0x8010237C: lw          $a2, 0x80($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X80);
    // 0x80102380: lhu         $t4, 0x38($a2)
    ctx->r12 = MEM_HU(ctx->r6, 0X38);
    // 0x80102384: ori         $t5, $t4, 0x400
    ctx->r13 = ctx->r12 | 0X400;
    // 0x80102388: sh          $t5, 0x38($a2)
    MEM_H(0X38, ctx->r6) = ctx->r13;
    // 0x8010238C: lbu         $t6, -0x20FC($t6)
    ctx->r14 = MEM_BU(ctx->r14, -0X20FC);
    // 0x80102390: lw          $t7, 0x80($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X80);
    // 0x80102394: sb          $t6, 0x60($t7)
    MEM_B(0X60, ctx->r15) = ctx->r14;
    // 0x80102398: lbu         $t8, -0x20F8($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X20F8);
    // 0x8010239C: lw          $t9, 0x80($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X80);
    // 0x801023A0: sb          $t8, 0x61($t9)
    MEM_B(0X61, ctx->r25) = ctx->r24;
    // 0x801023A4: lbu         $t1, -0x20F4($t1)
    ctx->r9 = MEM_BU(ctx->r9, -0X20F4);
    // 0x801023A8: lw          $t2, 0x80($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X80);
    // 0x801023AC: sb          $t1, 0x62($t2)
    MEM_B(0X62, ctx->r10) = ctx->r9;
    // 0x801023B0: lw          $v1, 0x80($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X80);
    // 0x801023B4: lhu         $t3, 0x38($v1)
    ctx->r11 = MEM_HU(ctx->r3, 0X38);
    // 0x801023B8: ori         $t4, $t3, 0x400
    ctx->r12 = ctx->r11 | 0X400;
    // 0x801023BC: sh          $t4, 0x38($v1)
    MEM_H(0X38, ctx->r3) = ctx->r12;
L_801023C0:
    // 0x801023C0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801023C4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801023C8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801023CC: jr          $ra
    // 0x801023D0: nop

    return;
    // 0x801023D0: nop

;}
RECOMP_FUNC void ftCaptainSpecialAirNProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F914: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8015F918: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F91C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015F920: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x8015F924: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015F928: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x8015F92C: beq         $t7, $zero, L_8015F99C
    if (ctx->r15 == 0) {
        // 0x8015F930: nop
    
            goto L_8015F99C;
    }
    // 0x8015F930: nop

    // 0x8015F934: lw          $t8, 0xADC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XADC);
    // 0x8015F938: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8015F93C: lb          $a0, 0x1C3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1C3);
    // 0x8015F940: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8015F944: jal         0x8015F874
    // 0x8015F948: sw          $t9, 0xADC($s0)
    MEM_W(0XADC, ctx->r16) = ctx->r25;
    ftCaptainSpecialNGetAngle(rdram, ctx);
        goto after_0;
    // 0x8015F948: sw          $t9, 0xADC($s0)
    MEM_W(0XADC, ctx->r16) = ctx->r25;
    after_0:
    // 0x8015F94C: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x8015F950: jal         0x800303F0
    // 0x8015F954: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8015F954: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x8015F958: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8015F95C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8015F960: nop

    // 0x8015F964: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8015F968: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x8015F96C: jal         0x80035CD0
    // 0x8015F970: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x8015F970: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015F974: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x8015F978: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x8015F97C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8015F980: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8015F984: nop

    // 0x8015F988: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8015F98C: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8015F990: nop

    // 0x8015F994: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8015F998: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
L_8015F99C:
    // 0x8015F99C: jal         0x8015F7F0
    // 0x8015F9A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftCaptainSpecialNUpdateEffect(rdram, ctx);
        goto after_3;
    // 0x8015F9A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x8015F9A4: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
    // 0x8015F9A8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015F9AC: beq         $v0, $zero, L_8015F9CC
    if (ctx->r2 == 0) {
        // 0x8015F9B0: nop
    
            goto L_8015F9CC;
    }
    // 0x8015F9B0: nop

    // 0x8015F9B4: beq         $v0, $at, L_8015F9DC
    if (ctx->r2 == ctx->r1) {
        // 0x8015F9B8: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8015F9DC;
    }
    // 0x8015F9B8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8015F9BC: beq         $v0, $at, L_8015FA10
    if (ctx->r2 == ctx->r1) {
        // 0x8015F9C0: nop
    
            goto L_8015FA10;
    }
    // 0x8015F9C0: nop

    // 0x8015F9C4: b           L_8015FA1C
    // 0x8015F9C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8015FA1C;
    // 0x8015F9C8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015F9CC:
    // 0x8015F9CC: jal         0x800D91EC
    // 0x8015F9D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftPhysicsApplyAirVelFriction(rdram, ctx);
        goto after_4;
    // 0x8015F9D0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
    // 0x8015F9D4: b           L_8015FA1C
    // 0x8015F9D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8015FA1C;
    // 0x8015F9D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015F9DC:
    // 0x8015F9DC: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x8015F9E0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015F9E4: ldc1        $f0, -0x3708($at)
    CHECK_FR(ctx, 0);
    ctx->f0.u64 = LD(ctx->r1, -0X3708);
    // 0x8015F9E8: lwc1        $f18, 0x48($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X48);
    // 0x8015F9EC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8015F9F0: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x8015F9F4: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8015F9F8: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8015F9FC: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8015FA00: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8015FA04: swc1        $f16, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f16.u32l;
    // 0x8015FA08: b           L_8015FA18
    // 0x8015FA0C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
        goto L_8015FA18;
    // 0x8015FA0C: swc1        $f8, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f8.u32l;
L_8015FA10:
    // 0x8015FA10: jal         0x800D9160
    // 0x8015FA14: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftPhysicsApplyAirVelDriftFastFall(rdram, ctx);
        goto after_5;
    // 0x8015FA14: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_5:
L_8015FA18:
    // 0x8015FA18: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015FA1C:
    // 0x8015FA1C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015FA20: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8015FA24: jr          $ra
    // 0x8015FA28: nop

    return;
    // 0x8015FA28: nop

;}
RECOMP_FUNC void ftFoxSpecialNProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015BBD8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015BBDC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015BBE0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8015BBE4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015BBE8: lw          $t6, 0x180($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X180);
    // 0x8015BBEC: beql        $t6, $zero, L_8015BC58
    if (ctx->r14 == 0) {
        // 0x8015BBF0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015BC58;
    }
    goto skip_0;
    // 0x8015BBF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8015BBF4: lhu         $t7, 0x1BE($s0)
    ctx->r15 = MEM_HU(ctx->r16, 0X1BE);
    // 0x8015BBF8: lhu         $t8, 0x1B6($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0X1B6);
    // 0x8015BBFC: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x8015BC00: beql        $t9, $zero, L_8015BC58
    if (ctx->r25 == 0) {
        // 0x8015BC04: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8015BC58;
    }
    goto skip_1;
    // 0x8015BC04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8015BC08: lw          $t0, 0x14C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X14C);
    // 0x8015BC0C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015BC10: bne         $t0, $at, L_8015BC28
    if (ctx->r8 != ctx->r1) {
        // 0x8015BC14: nop
    
            goto L_8015BC28;
    }
    // 0x8015BC14: nop

    // 0x8015BC18: jal         0x8015BCB8
    // 0x8015BC1C: nop

    ftFoxSpecialAirNSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015BC1C: nop

    after_0:
    // 0x8015BC20: b           L_8015BC34
    // 0x8015BC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
        goto L_8015BC34;
    // 0x8015BC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8015BC28:
    // 0x8015BC28: jal         0x8015BC78
    // 0x8015BC2C: nop

    ftFoxSpecialNSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015BC2C: nop

    after_1:
    // 0x8015BC30: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8015BC34:
    // 0x8015BC34: jal         0x800EA5E8
    // 0x8015BC38: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    ftParamSetMotionID(rdram, ctx);
        goto after_2;
    // 0x8015BC38: addiu       $a1, $zero, 0x12
    ctx->r5 = ADD32(0, 0X12);
    after_2:
    // 0x8015BC3C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015BC40: jal         0x800EA778
    // 0x8015BC44: lhu         $a1, 0x28E($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X28E);
    ftParamSetStatUpdate(rdram, ctx);
        goto after_3;
    // 0x8015BC44: lhu         $a1, 0x28E($s0)
    ctx->r5 = MEM_HU(ctx->r16, 0X28E);
    after_3:
    // 0x8015BC48: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8015BC4C: jal         0x800EA7B0
    // 0x8015BC50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamUpdate1PGameAttackStats(rdram, ctx);
        goto after_4;
    // 0x8015BC50: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8015BC54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015BC58:
    // 0x8015BC58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8015BC5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015BC60: jr          $ra
    // 0x8015BC64: nop

    return;
    // 0x8015BC64: nop

;}
RECOMP_FUNC void mvOpeningRoomInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801342E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801342E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801342EC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342F0: jal         0x80134270
    // 0x801342F4: sw          $zero, 0x4CE4($at)
    MEM_W(0X4CE4, ctx->r1) = 0;
    mvOpeningRoomGetPulledFighterKind(rdram, ctx);
        goto after_0;
    // 0x801342F4: sw          $zero, 0x4CE4($at)
    MEM_W(0X4CE4, ctx->r1) = 0;
    after_0:
    // 0x801342F8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801342FC: jal         0x801341B4
    // 0x80134300: sw          $v0, 0x4CF8($at)
    MEM_W(0X4CF8, ctx->r1) = ctx->r2;
    mvOpeningRoomGetDroppedFighterKind(rdram, ctx);
        goto after_1;
    // 0x80134300: sw          $v0, 0x4CF8($at)
    MEM_W(0X4CF8, ctx->r1) = ctx->r2;
    after_1:
    // 0x80134304: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134308: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013430C: sw          $v0, 0x4CFC($at)
    MEM_W(0X4CFC, ctx->r1) = ctx->r2;
    // 0x80134310: jr          $ra
    // 0x80134314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80134314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void itHarisenDroppedSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801753C4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801753C8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801753CC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801753D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801753D4: addiu       $a1, $a1, -0x6554
    ctx->r5 = ADD32(ctx->r5, -0X6554);
    // 0x801753D8: jal         0x80172EC8
    // 0x801753DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801753DC: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    after_0:
    // 0x801753E0: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x801753E4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801753E8: lwc1        $f4, -0x331C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X331C);
    // 0x801753EC: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x801753F0: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x801753F4: swc1        $f4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f4.u32l;
    // 0x801753F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801753FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175400: jr          $ra
    // 0x80175404: nop

    return;
    // 0x80175404: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134108: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8013410C: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80134110: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80134114: addiu       $t7, $t7, 0x6DD0
    ctx->r15 = ADD32(ctx->r15, 0X6DD0);
    // 0x80134118: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013411C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80134120: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x80134124: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80134128: addiu       $t0, $t7, 0x3C
    ctx->r8 = ADD32(ctx->r15, 0X3C);
    // 0x8013412C: addiu       $t6, $sp, 0x24
    ctx->r14 = ADD32(ctx->r29, 0X24);
L_80134130:
    // 0x80134130: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134134: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80134138: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8013413C: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80134140: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80134144: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80134148: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x8013414C: bne         $t7, $t0, L_80134130
    if (ctx->r15 != ctx->r8) {
        // 0x80134150: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80134130;
    }
    // 0x80134150: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80134154: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80134158: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8013415C: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x80134160: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x80134164: beql        $t1, $at, L_80134264
    if (ctx->r9 == ctx->r1) {
        // 0x80134168: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80134264;
    }
    goto skip_0;
    // 0x80134168: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x8013416C: beql        $s0, $zero, L_80134194
    if (ctx->r16 == 0) {
        // 0x80134170: mtc1        $zero, $f6
        ctx->f6.u32l = 0;
            goto L_80134194;
    }
    goto skip_1;
    // 0x80134170: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    skip_1:
    // 0x80134174: lw          $t2, 0x74($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X74);
    // 0x80134178: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013417C: lwc1        $f4, 0x34($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X34);
    // 0x80134180: jal         0x800D78E8
    // 0x80134184: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    ftManagerDestroyFighter(rdram, ctx);
        goto after_0;
    // 0x80134184: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80134188: b           L_801341A0
    // 0x8013418C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
        goto L_801341A0;
    // 0x8013418C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
    // 0x80134190: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
L_80134194:
    // 0x80134194: nop

    // 0x80134198: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
    // 0x8013419C: lw          $a0, 0x70($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X70);
L_801341A0:
    // 0x801341A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801341A4: jal         0x80133F5C
    // 0x801341A8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mnPlayers1PBonusGetCostume(rdram, ctx);
        goto after_1;
    // 0x801341A8: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_1:
    // 0x801341AC: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x801341B0: lw          $t5, 0x7710($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X7710);
    // 0x801341B4: lw          $t0, 0x6C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X6C);
    // 0x801341B8: andi        $t4, $v0, 0xFF
    ctx->r12 = ctx->r2 & 0XFF;
    // 0x801341BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801341C0: sw          $t4, 0x766C($at)
    MEM_W(0X766C, ctx->r1) = ctx->r12;
    // 0x801341C4: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x801341C8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x801341CC: sw          $t5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r13;
    // 0x801341D0: jal         0x800D7F3C
    // 0x801341D4: sb          $t0, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r8;
    ftManagerMakeFighter(rdram, ctx);
        goto after_2;
    // 0x801341D4: sb          $t0, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r8;
    after_2:
    // 0x801341D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x801341DC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x801341E0: sw          $v0, 0x7650($at)
    MEM_W(0X7650, ctx->r1) = ctx->r2;
    // 0x801341E4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x801341E8: addiu       $a1, $a1, 0x3FE8
    ctx->r5 = ADD32(ctx->r5, 0X3FE8);
    // 0x801341EC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801341F0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801341F4: jal         0x80008188
    // 0x801341F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x801341F8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x801341FC: lui         $at, 0xC42F
    ctx->r1 = S32(0XC42F << 16);
    // 0x80134200: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80134204: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80134208: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013420C: lui         $t2, 0x8039
    ctx->r10 = S32(0X8039 << 16);
    // 0x80134210: swc1        $f8, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f8.u32l;
    // 0x80134214: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80134218: lwc1        $f10, 0x7630($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X7630);
    // 0x8013421C: addiu       $t2, $t2, 0xD90
    ctx->r10 = ADD32(ctx->r10, 0XD90);
    // 0x80134220: swc1        $f10, 0x20($t6)
    MEM_W(0X20, ctx->r14) = ctx->f10.u32l;
    // 0x80134224: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x80134228: lwc1        $f16, 0x64($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8013422C: swc1        $f16, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->f16.u32l;
    // 0x80134230: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x80134234: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x80134238: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8013423C: addu        $v1, $t1, $t2
    ctx->r3 = ADD32(ctx->r9, ctx->r10);
    // 0x80134240: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80134244: swc1        $f18, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f18.u32l;
    // 0x80134248: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8013424C: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80134250: swc1        $f4, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f4.u32l;
    // 0x80134254: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80134258: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8013425C: swc1        $f6, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f6.u32l;
    // 0x80134260: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80134264:
    // 0x80134264: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80134268: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8013426C: jr          $ra
    // 0x80134270: nop

    return;
    // 0x80134270: nop

;}
RECOMP_FUNC void func_ovl47_80131BF8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131BF8: jr          $ra
    // 0x80131BFC: nop

    return;
    // 0x80131BFC: nop

;}
RECOMP_FUNC void grZebesProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801083C4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801083C8: lbu         $v0, 0x1406($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X1406);
    // 0x801083CC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801083D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801083D4: beq         $v0, $zero, L_80108400
    if (ctx->r2 == 0) {
        // 0x801083D8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80108400;
    }
    // 0x801083D8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801083DC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801083E0: beq         $v0, $at, L_80108410
    if (ctx->r2 == ctx->r1) {
        // 0x801083E4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80108410;
    }
    // 0x801083E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801083E8: beq         $v0, $at, L_80108420
    if (ctx->r2 == ctx->r1) {
        // 0x801083EC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80108420;
    }
    // 0x801083EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801083F0: beq         $v0, $at, L_80108430
    if (ctx->r2 == ctx->r1) {
        // 0x801083F4: nop
    
            goto L_80108430;
    }
    // 0x801083F4: nop

    // 0x801083F8: b           L_8010843C
    // 0x801083FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010843C;
    // 0x801083FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80108400:
    // 0x80108400: jal         0x80108240
    // 0x80108404: nop

    grZebesAcidUpdateWait(rdram, ctx);
        goto after_0;
    // 0x80108404: nop

    after_0:
    // 0x80108408: b           L_8010843C
    // 0x8010840C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010843C;
    // 0x8010840C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80108410:
    // 0x80108410: jal         0x801082B4
    // 0x80108414: nop

    grZebesAcidUpdateNormal(rdram, ctx);
        goto after_1;
    // 0x80108414: nop

    after_1:
    // 0x80108418: b           L_8010843C
    // 0x8010841C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010843C;
    // 0x8010841C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80108420:
    // 0x80108420: jal         0x801082EC
    // 0x80108424: nop

    grZebesAcidUpdateShake(rdram, ctx);
        goto after_2;
    // 0x80108424: nop

    after_2:
    // 0x80108428: b           L_8010843C
    // 0x8010842C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8010843C;
    // 0x8010842C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80108430:
    // 0x80108430: jal         0x8010833C
    // 0x80108434: nop

    grZebesAcidUpdateRise(rdram, ctx);
        goto after_3;
    // 0x80108434: nop

    after_3:
    // 0x80108438: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8010843C:
    // 0x8010843C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80108440: jr          $ra
    // 0x80108444: nop

    return;
    // 0x80108444: nop

;}
RECOMP_FUNC void gcSetGObjProcessFunction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800078BC: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x800078C0: jr          $ra
    // 0x800078C4: sw          $a0, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = ctx->r4;
    return;
    // 0x800078C4: sw          $a0, 0x66C8($at)
    MEM_W(0X66C8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void mnPlayers1PGameUpdateCostume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136B44: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80136B48: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80136B4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80136B50: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136B54: jal         0x800EC0EC
    // 0x80136B58: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x80136B58: lw          $a0, -0x70F8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X70F8);
    after_0:
    // 0x80136B5C: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136B60: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80136B64: lw          $a0, -0x7110($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7110);
    // 0x80136B68: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80136B6C: jal         0x800E9248
    // 0x80136B70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ftParamInitAllParts(rdram, ctx);
        goto after_1;
    // 0x80136B70: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80136B74: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80136B78: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80136B7C: addiu       $v0, $v0, -0x7118
    ctx->r2 = ADD32(ctx->r2, -0X7118);
    // 0x80136B80: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80136B84: sw          $t6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r14;
    // 0x80136B88: lw          $a0, -0x7048($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X7048);
    // 0x80136B8C: jal         0x8013419C
    // 0x80136B90: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    mnPlayers1PGameMakeStock(rdram, ctx);
        goto after_2;
    // 0x80136B90: lw          $a1, 0x20($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X20);
    after_2:
    // 0x80136B94: jal         0x800269C0
    // 0x80136B98: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    func_800269C0_275C0(rdram, ctx);
        goto after_3;
    // 0x80136B98: addiu       $a0, $zero, 0xA4
    ctx->r4 = ADD32(0, 0XA4);
    after_3:
    // 0x80136B9C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80136BA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80136BA4: jr          $ra
    // 0x80136BA8: nop

    return;
    // 0x80136BA8: nop

;}
RECOMP_FUNC void ftFoxSpecialAirLwLoopSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015CDCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015CDD0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015CDD4: addiu       $t6, $zero, 0x6
    ctx->r14 = ADD32(0, 0X6);
    // 0x8015CDD8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015CDDC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8015CDE0: addiu       $a1, $zero, 0xF4
    ctx->r5 = ADD32(0, 0XF4);
    // 0x8015CDE4: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015CDE8: jal         0x800E6F24
    // 0x8015CDEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015CDEC: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015CDF0: jal         0x8015CD7C
    // 0x8015CDF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftFoxSpecialLwLoopSetReflectFlag(rdram, ctx);
        goto after_1;
    // 0x8015CDF4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015CDF8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015CDFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015CE00: jr          $ra
    // 0x8015CE04: nop

    return;
    // 0x8015CE04: nop

;}
RECOMP_FUNC void itNBumperHitAirProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BD80: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017BD84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BD88: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8017BD8C: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x8017BD90: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8017BD94: lui         $a1, 0x4080
    ctx->r5 = S32(0X4080 << 16);
    // 0x8017BD98: lhu         $v1, 0x350($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X350);
    // 0x8017BD9C: lui         $a2, 0x42A0
    ctx->r6 = S32(0X42A0 << 16);
    // 0x8017BDA0: bne         $v1, $zero, L_8017BDD4
    if (ctx->r3 != 0) {
        // 0x8017BDA4: addiu       $t7, $v1, -0x1
        ctx->r15 = ADD32(ctx->r3, -0X1);
            goto L_8017BDD4;
    }
    // 0x8017BDA4: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8017BDA8: lw          $a0, 0x80($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X80);
    // 0x8017BDAC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BDB0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8017BDB4: lwc1        $f6, 0x88($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X88);
    // 0x8017BDB8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x8017BDBC: nop

    // 0x8017BDC0: bc1fl       L_8017BDD8
    if (!c1cs) {
        // 0x8017BDC4: sh          $t7, 0x350($a3)
        MEM_H(0X350, ctx->r7) = ctx->r15;
            goto L_8017BDD8;
    }
    goto skip_0;
    // 0x8017BDC4: sh          $t7, 0x350($a3)
    MEM_H(0X350, ctx->r7) = ctx->r15;
    skip_0:
    // 0x8017BDC8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8017BDCC: b           L_8017BDD8
    // 0x8017BDD0: swc1        $f8, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f8.u32l;
        goto L_8017BDD8;
    // 0x8017BDD0: swc1        $f8, 0x88($a0)
    MEM_W(0X88, ctx->r4) = ctx->f8.u32l;
L_8017BDD4:
    // 0x8017BDD4: sh          $t7, 0x350($a3)
    MEM_H(0X350, ctx->r7) = ctx->r15;
L_8017BDD8:
    // 0x8017BDD8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8017BDDC: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x8017BDE0: jal         0x80172558
    // 0x8017BDE4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x8017BDE4: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8017BDE8: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BDEC: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8017BDF0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8017BDF4: lhu         $v1, 0x33E($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X33E);
    // 0x8017BDF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8017BDFC: beq         $v1, $zero, L_8017BE40
    if (ctx->r3 == 0) {
        // 0x8017BE00: subu        $t9, $t8, $v1
        ctx->r25 = SUB32(ctx->r24, ctx->r3);
            goto L_8017BE40;
    }
    // 0x8017BE00: subu        $t9, $t8, $v1
    ctx->r25 = SUB32(ctx->r24, ctx->r3);
    // 0x8017BE04: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8017BE08: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8017BE0C: lwc1        $f18, -0x3240($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3240);
    // 0x8017BE10: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8017BE14: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8017BE18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8017BE1C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8017BE20: sub.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x8017BE24: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8017BE28: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x8017BE2C: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
    // 0x8017BE30: lhu         $t0, 0x33E($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X33E);
    // 0x8017BE34: addiu       $t1, $t0, -0x1
    ctx->r9 = ADD32(ctx->r8, -0X1);
    // 0x8017BE38: b           L_8017BE54
    // 0x8017BE3C: sh          $t1, 0x33E($a3)
    MEM_H(0X33E, ctx->r7) = ctx->r9;
        goto L_8017BE54;
    // 0x8017BE3C: sh          $t1, 0x33E($a3)
    MEM_H(0X33E, ctx->r7) = ctx->r9;
L_8017BE40:
    // 0x8017BE40: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8017BE44: nop

    // 0x8017BE48: swc1        $f0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f0.u32l;
    // 0x8017BE4C: swc1        $f0, 0x44($v0)
    MEM_W(0X44, ctx->r2) = ctx->f0.u32l;
    // 0x8017BE50: swc1        $f0, 0x40($v0)
    MEM_W(0X40, ctx->r2) = ctx->f0.u32l;
L_8017BE54:
    // 0x8017BE54: lhu         $v0, 0x354($a3)
    ctx->r2 = MEM_HU(ctx->r7, 0X354);
    // 0x8017BE58: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8017BE5C: bnel        $v0, $zero, L_8017BE80
    if (ctx->r2 != 0) {
        // 0x8017BE60: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_8017BE80;
    }
    goto skip_1;
    // 0x8017BE60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    skip_1:
    // 0x8017BE64: jal         0x8017279C
    // 0x8017BE68: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itMainClearOwnerStats(rdram, ctx);
        goto after_1;
    // 0x8017BE68: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x8017BE6C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8017BE70: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x8017BE74: andi        $v0, $t2, 0xFFFF
    ctx->r2 = ctx->r10 & 0XFFFF;
    // 0x8017BE78: sh          $t2, 0x354($a3)
    MEM_H(0X354, ctx->r7) = ctx->r10;
    // 0x8017BE7C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
L_8017BE80:
    // 0x8017BE80: beq         $v0, $at, L_8017BE8C
    if (ctx->r2 == ctx->r1) {
        // 0x8017BE84: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8017BE8C;
    }
    // 0x8017BE84: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8017BE88: sh          $t3, 0x354($a3)
    MEM_H(0X354, ctx->r7) = ctx->r11;
L_8017BE8C:
    // 0x8017BE8C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017BE90: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017BE94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017BE98: jr          $ra
    // 0x8017BE9C: nop

    return;
    // 0x8017BE9C: nop

;}
RECOMP_FUNC void itDisplayHitCollisions(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80171410: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80171414: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80171418: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x8017141C: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x80171420: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80171424: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80171428: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x8017142C: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80171430: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80171434: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80171438: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8017143C: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x80171440: sw          $a0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r4;
    // 0x80171444: lw          $t7, 0x84($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X84);
    // 0x80171448: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x8017144C: addiu       $s5, $s5, 0x65D8
    ctx->r21 = ADD32(ctx->r21, 0X65D8);
    // 0x80171450: addiu       $s6, $t7, 0x10C
    ctx->r22 = ADD32(ctx->r15, 0X10C);
    // 0x80171454: sw          $s6, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r22;
    // 0x80171458: sw          $t7, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r15;
    // 0x8017145C: lw          $t8, 0x160($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X160);
    // 0x80171460: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80171464: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x80171468: blez        $t8, L_80171750
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8017146C: lui         $at, 0x4170
        ctx->r1 = S32(0X4170 << 16);
            goto L_80171750;
    }
    // 0x8017146C: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80171470: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80171474: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80171478: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
L_8017147C:
    // 0x8017147C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80171480: beql        $v0, $zero, L_8017173C
    if (ctx->r2 == 0) {
        // 0x80171484: lw          $t8, 0xD4($sp)
        ctx->r24 = MEM_W(ctx->r29, 0XD4);
            goto L_8017173C;
    }
    goto skip_0;
    // 0x80171484: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
    skip_0:
    // 0x80171488: beq         $v0, $at, L_80171738
    if (ctx->r2 == ctx->r1) {
        // 0x8017148C: lui         $t0, 0xE700
        ctx->r8 = S32(0XE700 << 16);
            goto L_80171738;
    }
    // 0x8017148C: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80171490: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171494: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80171498: addiu       $t1, $t1, -0x3CF0
    ctx->r9 = ADD32(ctx->r9, -0X3CF0);
    // 0x8017149C: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x801714A0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801714A4: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x801714A8: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801714AC: lw          $t3, 0xDC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XDC);
    // 0x801714B0: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x801714B4: sll         $t2, $fp, 2
    ctx->r10 = S32(ctx->r30 << 2);
    // 0x801714B8: lw          $t4, 0x374($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X374);
    // 0x801714BC: subu        $t2, $t2, $fp
    ctx->r10 = SUB32(ctx->r10, ctx->r30);
    // 0x801714C0: sll         $t2, $t2, 5
    ctx->r10 = S32(ctx->r10 << 5);
    // 0x801714C4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x801714C8: bne         $t4, $at, L_80171528
    if (ctx->r12 != ctx->r1) {
        // 0x801714CC: addu        $s4, $s6, $t2
        ctx->r20 = ADD32(ctx->r22, ctx->r10);
            goto L_80171528;
    }
    // 0x801714CC: addu        $s4, $s6, $t2
    ctx->r20 = ADD32(ctx->r22, ctx->r10);
    // 0x801714D0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801714D4: lui         $a1, 0xB000
    ctx->r5 = S32(0XB000 << 16);
    // 0x801714D8: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x801714DC: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x801714E0: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x801714E4: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x801714E8: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x801714EC: sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // 0x801714F0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801714F4: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x801714F8: lui         $t0, 0xF900
    ctx->r8 = S32(0XF900 << 16);
    // 0x801714FC: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80171500: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80171504: sw          $a1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r5;
    // 0x80171508: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x8017150C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171510: addiu       $t1, $zero, 0xE0
    ctx->r9 = ADD32(0, 0XE0);
    // 0x80171514: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80171518: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8017151C: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x80171520: b           L_8017157C
    // 0x80171524: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
        goto L_8017157C;
    // 0x80171524: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
L_80171528:
    // 0x80171528: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8017152C: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x80171530: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80171534: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x80171538: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8017153C: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80171540: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80171544: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171548: lui         $t7, 0xB000
    ctx->r15 = S32(0XB000 << 16);
    // 0x8017154C: ori         $t7, $t7, 0xFF
    ctx->r15 = ctx->r15 | 0XFF;
    // 0x80171550: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80171554: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80171558: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x8017155C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80171560: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80171564: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171568: lui         $t9, 0xF900
    ctx->r25 = S32(0XF900 << 16);
    // 0x8017156C: addiu       $t8, $s0, 0x8
    ctx->r24 = ADD32(ctx->r16, 0X8);
    // 0x80171570: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x80171574: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80171578: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_8017157C:
    // 0x8017157C: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x80171580: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80171584: bnel        $t0, $at, L_80171650
    if (ctx->r8 != ctx->r1) {
        // 0x80171588: lw          $a0, 0xC($s5)
        ctx->r4 = MEM_W(ctx->r21, 0XC);
            goto L_80171650;
    }
    goto skip_1;
    // 0x80171588: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    skip_1:
    // 0x8017158C: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x80171590: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x80171594: addiu       $s7, $s7, -0x3ED8
    ctx->r23 = ADD32(ctx->r23, -0X3ED8);
    // 0x80171598: addiu       $t1, $a0, 0x40
    ctx->r9 = ADD32(ctx->r4, 0X40);
    // 0x8017159C: sw          $t1, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r9;
    // 0x801715A0: lw          $a3, 0x6C($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X6C);
    // 0x801715A4: lw          $a2, 0x68($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X68);
    // 0x801715A8: lw          $a1, 0x64($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X64);
    // 0x801715AC: jal         0x8001B9C4
    // 0x801715B0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    syMatrixTra(rdram, ctx);
        goto after_0;
    // 0x801715B0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    after_0:
    // 0x801715B4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801715B8: lui         $t3, 0xDA38
    ctx->r11 = S32(0XDA38 << 16);
    // 0x801715BC: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x801715C0: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x801715C4: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x801715C8: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x801715CC: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x801715D0: addiu       $t4, $a0, 0x40
    ctx->r12 = ADD32(ctx->r4, 0X40);
    // 0x801715D4: sw          $t4, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r12;
    // 0x801715D8: lwc1        $f4, 0x2C($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X2C);
    // 0x801715DC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801715E0: div.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x801715E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801715E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801715EC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801715F0: jal         0x8001B780
    // 0x801715F4: nop

    syMatrixSca(rdram, ctx);
        goto after_1;
    // 0x801715F4: nop

    after_1:
    // 0x801715F8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801715FC: lui         $t6, 0xDA38
    ctx->r14 = S32(0XDA38 << 16);
    // 0x80171600: ori         $t6, $t6, 0x1
    ctx->r14 = ctx->r14 | 0X1;
    // 0x80171604: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x80171608: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8017160C: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80171610: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80171614: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171618: lui         $t8, 0xDE00
    ctx->r24 = S32(0XDE00 << 16);
    // 0x8017161C: lui         $t0, 0xD838
    ctx->r8 = S32(0XD838 << 16);
    // 0x80171620: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80171624: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80171628: sw          $s7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r23;
    // 0x8017162C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80171630: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171634: ori         $t0, $t0, 0x2
    ctx->r8 = ctx->r8 | 0X2;
    // 0x80171638: addiu       $t1, $zero, 0x40
    ctx->r9 = ADD32(0, 0X40);
    // 0x8017163C: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80171640: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80171644: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x80171648: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8017164C: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
L_80171650:
    // 0x80171650: addiu       $t2, $a0, 0x40
    ctx->r10 = ADD32(ctx->r4, 0X40);
    // 0x80171654: sw          $t2, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r10;
    // 0x80171658: lw          $a3, 0x60($s4)
    ctx->r7 = MEM_W(ctx->r20, 0X60);
    // 0x8017165C: lw          $a2, 0x5C($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X5C);
    // 0x80171660: lw          $a1, 0x58($s4)
    ctx->r5 = MEM_W(ctx->r20, 0X58);
    // 0x80171664: jal         0x8001B9C4
    // 0x80171668: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    syMatrixTra(rdram, ctx);
        goto after_2;
    // 0x80171668: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    after_2:
    // 0x8017166C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171670: lui         $t4, 0xDA38
    ctx->r12 = S32(0XDA38 << 16);
    // 0x80171674: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x80171678: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x8017167C: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x80171680: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80171684: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x80171688: addiu       $t5, $a0, 0x40
    ctx->r13 = ADD32(ctx->r4, 0X40);
    // 0x8017168C: sw          $t5, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r13;
    // 0x80171690: lwc1        $f6, 0x2C($s6)
    ctx->f6.u32l = MEM_W(ctx->r22, 0X2C);
    // 0x80171694: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80171698: div.s       $f0, $f6, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8017169C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801716A0: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801716A4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x801716A8: jal         0x8001B780
    // 0x801716AC: nop

    syMatrixSca(rdram, ctx);
        goto after_3;
    // 0x801716AC: nop

    after_3:
    // 0x801716B0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801716B4: lui         $t7, 0xDA38
    ctx->r15 = S32(0XDA38 << 16);
    // 0x801716B8: ori         $t7, $t7, 0x1
    ctx->r15 = ctx->r15 | 0X1;
    // 0x801716BC: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x801716C0: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x801716C4: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x801716C8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x801716CC: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x801716D0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x801716D4: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x801716D8: bnel        $t8, $at, L_80171700
    if (ctx->r24 != ctx->r1) {
        // 0x801716DC: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80171700;
    }
    goto skip_2;
    // 0x801716DC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_2:
    // 0x801716E0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801716E4: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801716E8: addiu       $t1, $t1, -0x3EA0
    ctx->r9 = ADD32(ctx->r9, -0X3EA0);
    // 0x801716EC: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x801716F0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x801716F4: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x801716F8: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x801716FC: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80171700:
    // 0x80171700: lui         $t3, 0xDE00
    ctx->r11 = S32(0XDE00 << 16);
    // 0x80171704: lui         $t6, 0xD838
    ctx->r14 = S32(0XD838 << 16);
    // 0x80171708: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x8017170C: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x80171710: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x80171714: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x80171718: ori         $t6, $t6, 0x2
    ctx->r14 = ctx->r14 | 0X2;
    // 0x8017171C: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80171720: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80171724: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171728: addiu       $t5, $s0, 0x8
    ctx->r13 = ADD32(ctx->r16, 0X8);
    // 0x8017172C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x80171730: sw          $t7, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r15;
    // 0x80171734: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
L_80171738:
    // 0x80171738: lw          $t8, 0xD4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XD4);
L_8017173C:
    // 0x8017173C: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80171740: lw          $t9, 0x54($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X54);
    // 0x80171744: slt         $at, $fp, $t9
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80171748: bnel        $at, $zero, L_8017147C
    if (ctx->r1 != 0) {
        // 0x8017174C: lw          $v0, 0x0($s6)
        ctx->r2 = MEM_W(ctx->r22, 0X0);
            goto L_8017147C;
    }
    goto skip_3;
    // 0x8017174C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    skip_3:
L_80171750:
    // 0x80171750: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x80171754: lui         $at, 0x4170
    ctx->r1 = S32(0X4170 << 16);
    // 0x80171758: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x8017175C: lw          $t1, 0x248($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X248);
    // 0x80171760: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80171764: lui         $s5, 0x8004
    ctx->r21 = S32(0X8004 << 16);
    // 0x80171768: addiu       $s5, $s5, 0x65D8
    ctx->r21 = ADD32(ctx->r21, 0X65D8);
    // 0x8017176C: beq         $t1, $zero, L_80171978
    if (ctx->r9 == 0) {
        // 0x80171770: addiu       $s1, $s1, 0x65B0
        ctx->r17 = ADD32(ctx->r17, 0X65B0);
            goto L_80171978;
    }
    // 0x80171770: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80171774: lw          $t2, 0xE0($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XE0);
    // 0x80171778: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x8017177C: lw          $s4, 0xDC($sp)
    ctx->r20 = MEM_W(ctx->r29, 0XDC);
    // 0x80171780: lw          $v0, 0x74($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X74);
    // 0x80171784: addiu       $t3, $a0, 0x40
    ctx->r11 = ADD32(ctx->r4, 0X40);
    // 0x80171788: sw          $t3, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r11;
    // 0x8017178C: lwc1        $f8, 0x24C($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X24C);
    // 0x80171790: lwc1        $f10, 0x1C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80171794: lwc1        $f18, 0x250($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X250);
    // 0x80171798: lwc1        $f4, 0x20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8017179C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801717A0: lwc1        $f8, 0x254($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X254);
    // 0x801717A4: lwc1        $f10, 0x24($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X24);
    // 0x801717A8: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x801717AC: mfc1        $a1, $f16
    ctx->r5 = (int32_t)ctx->f16.u32l;
    // 0x801717B0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801717B4: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x801717B8: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x801717BC: addiu       $s4, $s4, 0x244
    ctx->r20 = ADD32(ctx->r20, 0X244);
    // 0x801717C0: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x801717C4: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x801717C8: jal         0x8001B9C4
    // 0x801717CC: nop

    syMatrixTra(rdram, ctx);
        goto after_4;
    // 0x801717CC: nop

    after_4:
    // 0x801717D0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801717D4: lui         $t5, 0xDA38
    ctx->r13 = S32(0XDA38 << 16);
    // 0x801717D8: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x801717DC: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801717E0: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x801717E4: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x801717E8: lw          $a0, 0xC($s5)
    ctx->r4 = MEM_W(ctx->r21, 0XC);
    // 0x801717EC: addiu       $t6, $a0, 0x40
    ctx->r14 = ADD32(ctx->r4, 0X40);
    // 0x801717F0: sw          $t6, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r14;
    // 0x801717F4: lwc1        $f10, 0x1C($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X1C);
    // 0x801717F8: lwc1        $f6, 0x18($s4)
    ctx->f6.u32l = MEM_W(ctx->r20, 0X18);
    // 0x801717FC: lwc1        $f18, 0x14($s4)
    ctx->f18.u32l = MEM_W(ctx->r20, 0X14);
    // 0x80171800: div.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f20.fl);
    // 0x80171804: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80171808: div.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8017180C: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x80171810: div.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80171814: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80171818: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8017181C: jal         0x8001B780
    // 0x80171820: nop

    syMatrixSca(rdram, ctx);
        goto after_5;
    // 0x80171820: nop

    after_5:
    // 0x80171824: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171828: lui         $t8, 0xDA38
    ctx->r24 = S32(0XDA38 << 16);
    // 0x8017182C: ori         $t8, $t8, 0x1
    ctx->r24 = ctx->r24 | 0X1;
    // 0x80171830: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x80171834: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x80171838: sw          $s2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r18;
    // 0x8017183C: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80171840: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171844: lui         $t0, 0xE700
    ctx->r8 = S32(0XE700 << 16);
    // 0x80171848: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8017184C: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80171850: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x80171854: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x80171858: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x8017185C: lw          $a0, 0x4($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X4);
    // 0x80171860: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x80171864: beq         $a0, $at, L_80171888
    if (ctx->r4 == ctx->r1) {
        // 0x80171868: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80171888;
    }
    // 0x80171868: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8017186C: beq         $a0, $at, L_801718C4
    if (ctx->r4 == ctx->r1) {
        // 0x80171870: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_801718C4;
    }
    // 0x80171870: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80171874: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80171878: beql        $a0, $at, L_80171904
    if (ctx->r4 == ctx->r1) {
        // 0x8017187C: lw          $s0, 0x0($s1)
        ctx->r16 = MEM_W(ctx->r17, 0X0);
            goto L_80171904;
    }
    goto skip_4;
    // 0x8017187C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    skip_4:
    // 0x80171880: b           L_8017193C
    // 0x80171884: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
        goto L_8017193C;
    // 0x80171884: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80171888:
    // 0x80171888: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8017188C: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x80171890: lui         $t6, 0xD0D0
    ctx->r14 = S32(0XD0D0 << 16);
    // 0x80171894: addiu       $t1, $s0, 0x8
    ctx->r9 = ADD32(ctx->r16, 0X8);
    // 0x80171898: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x8017189C: sw          $t3, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r11;
    // 0x801718A0: sw          $t2, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r10;
    // 0x801718A4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801718A8: ori         $t6, $t6, 0xFF
    ctx->r14 = ctx->r14 | 0XFF;
    // 0x801718AC: lui         $t5, 0xFB00
    ctx->r13 = S32(0XFB00 << 16);
    // 0x801718B0: addiu       $t4, $s0, 0x8
    ctx->r12 = ADD32(ctx->r16, 0X8);
    // 0x801718B4: sw          $t4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r12;
    // 0x801718B8: sw          $t6, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r14;
    // 0x801718BC: b           L_80171938
    // 0x801718C0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_80171938;
    // 0x801718C0: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_801718C4:
    // 0x801718C4: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801718C8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x801718CC: lui         $t2, 0xD0
    ctx->r10 = S32(0XD0 << 16);
    // 0x801718D0: addiu       $t7, $s0, 0x8
    ctx->r15 = ADD32(ctx->r16, 0X8);
    // 0x801718D4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x801718D8: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x801718DC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x801718E0: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x801718E4: ori         $t2, $t2, 0xFF
    ctx->r10 = ctx->r10 | 0XFF;
    // 0x801718E8: lui         $t1, 0xFB00
    ctx->r9 = S32(0XFB00 << 16);
    // 0x801718EC: addiu       $t0, $s0, 0x8
    ctx->r8 = ADD32(ctx->r16, 0X8);
    // 0x801718F0: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
    // 0x801718F4: sw          $t2, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r10;
    // 0x801718F8: b           L_80171938
    // 0x801718FC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
        goto L_80171938;
    // 0x801718FC: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x80171900: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_80171904:
    // 0x80171904: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x80171908: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8017190C: addiu       $t3, $s0, 0x8
    ctx->r11 = ADD32(ctx->r16, 0X8);
    // 0x80171910: sw          $t3, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r11;
    // 0x80171914: sw          $t5, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r13;
    // 0x80171918: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x8017191C: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x80171920: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x80171924: ori         $t8, $zero, 0xD0FF
    ctx->r24 = 0 | 0XD0FF;
    // 0x80171928: addiu       $t6, $s0, 0x8
    ctx->r14 = ADD32(ctx->r16, 0X8);
    // 0x8017192C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x80171930: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80171934: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_80171938:
    // 0x80171938: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
L_8017193C:
    // 0x8017193C: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80171940: addiu       $t1, $t1, -0x3FA8
    ctx->r9 = ADD32(ctx->r9, -0X3FA8);
    // 0x80171944: addiu       $t9, $s0, 0x8
    ctx->r25 = ADD32(ctx->r16, 0X8);
    // 0x80171948: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8017194C: lui         $t0, 0xDE00
    ctx->r8 = S32(0XDE00 << 16);
    // 0x80171950: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80171954: sw          $t1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r9;
    // 0x80171958: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8017195C: lui         $t3, 0xD838
    ctx->r11 = S32(0XD838 << 16);
    // 0x80171960: ori         $t3, $t3, 0x2
    ctx->r11 = ctx->r11 | 0X2;
    // 0x80171964: addiu       $t2, $s0, 0x8
    ctx->r10 = ADD32(ctx->r16, 0X8);
    // 0x80171968: sw          $t2, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r10;
    // 0x8017196C: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x80171970: sw          $t4, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r12;
    // 0x80171974: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_80171978:
    // 0x80171978: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8017197C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80171980: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80171984: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80171988: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8017198C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80171990: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80171994: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80171998: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8017199C: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x801719A0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x801719A4: jr          $ra
    // 0x801719A8: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    return;
    // 0x801719A8: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
;}
RECOMP_FUNC void ftKirbySpecialLwHoldDecideNextStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801616F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801616F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801616F8: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x801616FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80161700: jal         0x801614B4
    // 0x80161704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftKirbySpecialLwCheckRelease(rdram, ctx);
        goto after_0;
    // 0x80161704: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x80161708: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8016170C: bne         $v0, $at, L_80161734
    if (ctx->r2 != ctx->r1) {
        // 0x80161710: lw          $t6, 0x1C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1C);
            goto L_80161734;
    }
    // 0x80161710: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80161714: bne         $t6, $zero, L_8016172C
    if (ctx->r14 != 0) {
        // 0x80161718: nop
    
            goto L_8016172C;
    }
    // 0x80161718: nop

    // 0x8016171C: jal         0x80161B2C
    // 0x80161720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftKirbySpecialLwEndSetStatus(rdram, ctx);
        goto after_1;
    // 0x80161720: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80161724: b           L_80161734
    // 0x80161728: nop

        goto L_80161734;
    // 0x80161728: nop

L_8016172C:
    // 0x8016172C: jal         0x80161C5C
    // 0x80161730: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftKirbySpecialAirLwEndSetStatus(rdram, ctx);
        goto after_2;
    // 0x80161730: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
L_80161734:
    // 0x80161734: jal         0x80161368
    // 0x80161738: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    ftKirbySpecialLwUpdateColAnim(rdram, ctx);
        goto after_3;
    // 0x80161738: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x8016173C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80161740: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80161744: jr          $ra
    // 0x80161748: nop

    return;
    // 0x80161748: nop

;}
RECOMP_FUNC void mnPlayersVSShutterProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132C6C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132C70: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132C74: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80132C78: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132C7C: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80132C80: sll         $t6, $a1, 2
    ctx->r14 = S32(ctx->r5 << 2);
    // 0x80132C84: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80132C88: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80132C8C: subu        $t6, $t6, $a1
    ctx->r14 = SUB32(ctx->r14, ctx->r5);
    // 0x80132C90: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80132C94: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80132C98: lw          $t8, 0x84($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X84);
    // 0x80132C9C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132CA0: bnel        $a2, $t8, L_80132CF0
    if (ctx->r6 != ctx->r24) {
        // 0x80132CA4: lw          $v0, 0xA4($v1)
        ctx->r2 = MEM_W(ctx->r3, 0XA4);
            goto L_80132CF0;
    }
    goto skip_0;
    // 0x80132CA4: lw          $v0, 0xA4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XA4);
    skip_0:
    // 0x80132CA8: lw          $v0, 0xA4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XA4);
    // 0x80132CAC: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x80132CB0: beq         $at, $zero, L_80132D0C
    if (ctx->r1 == 0) {
        // 0x80132CB4: addiu       $t9, $v0, 0x2
        ctx->r25 = ADD32(ctx->r2, 0X2);
            goto L_80132D0C;
    }
    // 0x80132CB4: addiu       $t9, $v0, 0x2
    ctx->r25 = ADD32(ctx->r2, 0X2);
    // 0x80132CB8: slti        $at, $t9, 0x29
    ctx->r1 = SIGNED(ctx->r25) < 0X29 ? 1 : 0;
    // 0x80132CBC: bne         $at, $zero, L_80132CDC
    if (ctx->r1 != 0) {
        // 0x80132CC0: sw          $t9, 0xA4($v1)
        MEM_W(0XA4, ctx->r3) = ctx->r25;
            goto L_80132CDC;
    }
    // 0x80132CC0: sw          $t9, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r25;
    // 0x80132CC4: addiu       $t1, $zero, 0x29
    ctx->r9 = ADD32(0, 0X29);
    // 0x80132CC8: sw          $t1, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r9;
    // 0x80132CCC: addiu       $a0, $zero, 0xA6
    ctx->r4 = ADD32(0, 0XA6);
    // 0x80132CD0: jal         0x800269C0
    // 0x80132CD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80132CD4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80132CD8: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
L_80132CDC:
    // 0x80132CDC: jal         0x80132BF4
    // 0x80132CE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayersVSUpdateShutter(rdram, ctx);
        goto after_1;
    // 0x80132CE0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_1:
    // 0x80132CE4: b           L_80132D10
    // 0x80132CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80132D10;
    // 0x80132CE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132CEC: lw          $v0, 0xA4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0XA4);
L_80132CF0:
    // 0x80132CF0: blez        $v0, L_80132D0C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80132CF4: addiu       $t2, $v0, -0x2
        ctx->r10 = ADD32(ctx->r2, -0X2);
            goto L_80132D0C;
    }
    // 0x80132CF4: addiu       $t2, $v0, -0x2
    ctx->r10 = ADD32(ctx->r2, -0X2);
    // 0x80132CF8: bgez        $t2, L_80132D04
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80132CFC: sw          $t2, 0xA4($v1)
        MEM_W(0XA4, ctx->r3) = ctx->r10;
            goto L_80132D04;
    }
    // 0x80132CFC: sw          $t2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->r10;
    // 0x80132D00: sw          $zero, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = 0;
L_80132D04:
    // 0x80132D04: jal         0x80132BF4
    // 0x80132D08: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    mnPlayersVSUpdateShutter(rdram, ctx);
        goto after_2;
    // 0x80132D08: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_2:
L_80132D0C:
    // 0x80132D0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132D10:
    // 0x80132D10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132D14: jr          $ra
    // 0x80132D18: nop

    return;
    // 0x80132D18: nop

;}
RECOMP_FUNC void wpMapProcLRWallCheckFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167880: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80167884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80167888: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8016788C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80167890: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80167894: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80167898: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8016789C: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x801678A0: jal         0x800DA294
    // 0x801678A4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpProcessCheckTestLWallCollision(rdram, ctx);
        goto after_0;
    // 0x801678A4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x801678A8: beq         $v0, $zero, L_801678C0
    if (ctx->r2 == 0) {
        // 0x801678AC: nop
    
            goto L_801678C0;
    }
    // 0x801678AC: nop

    // 0x801678B0: jal         0x800DA658
    // 0x801678B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunLWallCollision(rdram, ctx);
        goto after_1;
    // 0x801678B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x801678B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x801678BC: sw          $t7, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r15;
L_801678C0:
    // 0x801678C0: jal         0x800DAAA8
    // 0x801678C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestRWallCollision(rdram, ctx);
        goto after_2;
    // 0x801678C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x801678C8: beq         $v0, $zero, L_801678E0
    if (ctx->r2 == 0) {
        // 0x801678CC: nop
    
            goto L_801678E0;
    }
    // 0x801678CC: nop

    // 0x801678D0: jal         0x800DAE6C
    // 0x801678D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunRWallCollision(rdram, ctx);
        goto after_3;
    // 0x801678D4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x801678D8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x801678DC: sw          $t8, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r24;
L_801678E0:
    // 0x801678E0: jal         0x800DB2BC
    // 0x801678E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessCheckTestFloorCollisionNew(rdram, ctx);
        goto after_4;
    // 0x801678E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x801678E8: beq         $v0, $zero, L_80167914
    if (ctx->r2 == 0) {
        // 0x801678EC: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_80167914;
    }
    // 0x801678EC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801678F0: lhu         $t9, 0x5A($s0)
    ctx->r25 = MEM_HU(ctx->r16, 0X5A);
    // 0x801678F4: andi        $t0, $t9, 0x800
    ctx->r8 = ctx->r25 & 0X800;
    // 0x801678F8: beql        $t0, $zero, L_8016791C
    if (ctx->r8 == 0) {
        // 0x801678FC: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8016791C;
    }
    goto skip_0;
    // 0x801678FC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    skip_0:
    // 0x80167900: jal         0x800D9F84
    // 0x80167904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_5;
    // 0x80167904: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_5:
    // 0x80167908: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8016790C: b           L_80167918
    // 0x80167910: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
        goto L_80167918;
    // 0x80167910: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
L_80167914:
    // 0x80167914: sw          $t2, 0x64($s0)
    MEM_W(0X64, ctx->r16) = ctx->r10;
L_80167918:
    // 0x80167918: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_8016791C:
    // 0x8016791C: jal         0x800DB474
    // 0x80167920: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    mpProcessCheckTestFloorCollision(rdram, ctx);
        goto after_6;
    // 0x80167920: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    after_6:
    // 0x80167924: beql        $v0, $zero, L_8016795C
    if (ctx->r2 == 0) {
        // 0x80167928: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8016795C;
    }
    goto skip_1;
    // 0x80167928: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x8016792C: jal         0x800DD59C
    // 0x80167930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpProcessSetLandingFloor(rdram, ctx);
        goto after_7;
    // 0x80167930: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80167934: lhu         $t3, 0x5A($s0)
    ctx->r11 = MEM_HU(ctx->r16, 0X5A);
    // 0x80167938: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8016793C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80167940: andi        $t4, $t3, 0x800
    ctx->r12 = ctx->r11 & 0X800;
    // 0x80167944: beql        $t4, $zero, L_80167958
    if (ctx->r12 == 0) {
        // 0x80167948: sw          $zero, 0x64($s0)
        MEM_W(0X64, ctx->r16) = 0;
            goto L_80167958;
    }
    goto skip_2;
    // 0x80167948: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
    skip_2:
    // 0x8016794C: jal         0x800D9F84
    // 0x80167950: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    mpProcessRunFloorEdgeAdjust(rdram, ctx);
        goto after_8;
    // 0x80167950: sw          $t5, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r13;
    after_8:
    // 0x80167954: sw          $zero, 0x64($s0)
    MEM_W(0X64, ctx->r16) = 0;
L_80167958:
    // 0x80167958: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8016795C:
    // 0x8016795C: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x80167960: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80167964: jr          $ra
    // 0x80167968: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80167968: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnVSRecordDrawRankingGrid(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132EE4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132EE8: addiu       $v1, $sp, 0x20
    ctx->r3 = ADD32(ctx->r29, 0X20);
    // 0x80132EEC: addiu       $v0, $sp, 0x3C
    ctx->r2 = ADD32(ctx->r29, 0X3C);
L_80132EF0:
    // 0x80132EF0: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x80132EF4: bnel        $at, $zero, L_80132F04
    if (ctx->r1 != 0) {
        // 0x80132EF8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80132F04;
    }
    goto skip_0;
    // 0x80132EF8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    skip_0:
    // 0x80132EFC: addiu       $a0, $a0, -0x7
    ctx->r4 = ADD32(ctx->r4, -0X7);
    // 0x80132F00: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80132F04:
    // 0x80132F04: sltu        $at, $v1, $v0
    ctx->r1 = ctx->r3 < ctx->r2 ? 1 : 0;
    // 0x80132F08: sw          $a0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r4;
    // 0x80132F0C: bne         $at, $zero, L_80132EF0
    if (ctx->r1 != 0) {
        // 0x80132F10: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80132EF0;
    }
    // 0x80132F10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80132F14: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x80132F18: addiu       $t1, $t1, 0x65B0
    ctx->r9 = ADD32(ctx->r9, 0X65B0);
    // 0x80132F1C: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80132F20: lui         $a2, 0x6
    ctx->r6 = S32(0X6 << 16);
    // 0x80132F24: lui         $t7, 0xF649
    ctx->r15 = S32(0XF649 << 16);
    // 0x80132F28: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80132F2C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80132F30: ori         $a2, $a2, 0xB8
    ctx->r6 = ctx->r6 | 0XB8;
    // 0x80132F34: ori         $t7, $t7, 0xC0B8
    ctx->r15 = ctx->r15 | 0XC0B8;
    // 0x80132F38: lui         $a3, 0xF649
    ctx->r7 = S32(0XF649 << 16);
    // 0x80132F3C: ori         $a3, $a3, 0xC000
    ctx->r7 = ctx->r7 | 0XC000;
    // 0x80132F40: addiu       $a1, $zero, 0x3D
    ctx->r5 = ADD32(0, 0X3D);
    // 0x80132F44: lui         $t0, 0x6
    ctx->r8 = S32(0X6 << 16);
    // 0x80132F48: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x80132F4C: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
L_80132F50:
    // 0x80132F50: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80132F54: andi        $v1, $a1, 0x3FF
    ctx->r3 = ctx->r5 & 0X3FF;
    // 0x80132F58: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80132F5C: addiu       $a1, $a1, 0xD
    ctx->r5 = ADD32(ctx->r5, 0XD);
    // 0x80132F60: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80132F64: slti        $at, $a1, 0xE6
    ctx->r1 = SIGNED(ctx->r5) < 0XE6 ? 1 : 0;
    // 0x80132F68: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x80132F6C: or          $t9, $v1, $a3
    ctx->r25 = ctx->r3 | ctx->r7;
    // 0x80132F70: or          $t6, $v1, $t0
    ctx->r14 = ctx->r3 | ctx->r8;
    // 0x80132F74: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80132F78: bne         $at, $zero, L_80132F50
    if (ctx->r1 != 0) {
        // 0x80132F7C: sw          $t9, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r25;
            goto L_80132F50;
    }
    // 0x80132F7C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80132F80: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80132F84: lui         $t8, 0xF606
    ctx->r24 = S32(0XF606 << 16);
    // 0x80132F88: ori         $t8, $t8, 0x364
    ctx->r24 = ctx->r24 | 0X364;
    // 0x80132F8C: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x80132F90: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80132F94: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132F98: addiu       $a1, $zero, 0x30
    ctx->r5 = ADD32(0, 0X30);
    // 0x80132F9C: addiu       $t3, $t3, 0x6630
    ctx->r11 = ADD32(ctx->r11, 0X6630);
    // 0x80132FA0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80132FA4: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x80132FA8: addiu       $t4, $sp, 0x20
    ctx->r12 = ADD32(ctx->r29, 0X20);
    // 0x80132FAC: lui         $t2, 0xF600
    ctx->r10 = S32(0XF600 << 16);
    // 0x80132FB0: sw          $a2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r6;
    // 0x80132FB4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80132FB8: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
L_80132FBC:
    // 0x80132FBC: andi        $a2, $a1, 0x3FF
    ctx->r6 = ctx->r5 & 0X3FF;
    // 0x80132FC0: sll         $a2, $a2, 14
    ctx->r6 = S32(ctx->r6 << 14);
    // 0x80132FC4: or          $a3, $a2, $t2
    ctx->r7 = ctx->r6 | ctx->r10;
    // 0x80132FC8: addiu       $t9, $a0, 0x8
    ctx->r25 = ADD32(ctx->r4, 0X8);
    // 0x80132FCC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x80132FD0: ori         $a3, $a3, 0x364
    ctx->r7 = ctx->r7 | 0X364;
    // 0x80132FD4: ori         $t0, $a2, 0xB8
    ctx->r8 = ctx->r6 | 0XB8;
    // 0x80132FD8: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80132FDC: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80132FE0: beq         $at, $zero, L_80133018
    if (ctx->r1 == 0) {
        // 0x80132FE4: sw          $a3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r7;
            goto L_80133018;
    }
    // 0x80132FE4: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x80132FE8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80132FEC: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x80132FF0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132FF4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80132FF8: addu        $t6, $t3, $t9
    ctx->r14 = ADD32(ctx->r11, ctx->r25);
    // 0x80132FFC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80133000: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80133004: andi        $a2, $a1, 0x3FF
    ctx->r6 = ctx->r5 & 0X3FF;
    // 0x80133008: sll         $a2, $a2, 14
    ctx->r6 = S32(ctx->r6 << 14);
    // 0x8013300C: or          $a3, $a2, $t2
    ctx->r7 = ctx->r6 | ctx->r10;
    // 0x80133010: ori         $a3, $a3, 0x364
    ctx->r7 = ctx->r7 | 0X364;
    // 0x80133014: ori         $t0, $a2, 0xB8
    ctx->r8 = ctx->r6 | 0XB8;
L_80133018:
    // 0x80133018: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8013301C: slti        $at, $v0, 0x6
    ctx->r1 = SIGNED(ctx->r2) < 0X6 ? 1 : 0;
    // 0x80133020: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80133024: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80133028: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8013302C: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x80133030: beq         $at, $zero, L_80133064
    if (ctx->r1 == 0) {
        // 0x80133034: sw          $a3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r7;
            goto L_80133064;
    }
    // 0x80133034: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x80133038: addu        $t6, $t4, $t9
    ctx->r14 = ADD32(ctx->r12, ctx->r25);
    // 0x8013303C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80133040: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80133044: addu        $t9, $t3, $t8
    ctx->r25 = ADD32(ctx->r11, ctx->r24);
    // 0x80133048: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8013304C: addu        $a1, $a1, $t6
    ctx->r5 = ADD32(ctx->r5, ctx->r14);
    // 0x80133050: andi        $a2, $a1, 0x3FF
    ctx->r6 = ctx->r5 & 0X3FF;
    // 0x80133054: sll         $a2, $a2, 14
    ctx->r6 = S32(ctx->r6 << 14);
    // 0x80133058: or          $a3, $a2, $t2
    ctx->r7 = ctx->r6 | ctx->r10;
    // 0x8013305C: ori         $a3, $a3, 0x364
    ctx->r7 = ctx->r7 | 0X364;
    // 0x80133060: ori         $t0, $a2, 0xB8
    ctx->r8 = ctx->r6 | 0XB8;
L_80133064:
    // 0x80133064: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80133068: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x8013306C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x80133070: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x80133074: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x80133078: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x8013307C: beq         $at, $zero, L_801330B0
    if (ctx->r1 == 0) {
        // 0x80133080: sw          $a3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r7;
            goto L_801330B0;
    }
    // 0x80133080: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x80133084: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x80133088: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8013308C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80133090: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x80133094: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80133098: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8013309C: andi        $a2, $a1, 0x3FF
    ctx->r6 = ctx->r5 & 0X3FF;
    // 0x801330A0: sll         $a2, $a2, 14
    ctx->r6 = S32(ctx->r6 << 14);
    // 0x801330A4: or          $a3, $a2, $t2
    ctx->r7 = ctx->r6 | ctx->r10;
    // 0x801330A8: ori         $a3, $a3, 0x364
    ctx->r7 = ctx->r7 | 0X364;
    // 0x801330AC: ori         $t0, $a2, 0xB8
    ctx->r8 = ctx->r6 | 0XB8;
L_801330B0:
    // 0x801330B0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x801330B4: slti        $at, $v0, 0x4
    ctx->r1 = SIGNED(ctx->r2) < 0X4 ? 1 : 0;
    // 0x801330B8: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x801330BC: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x801330C0: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x801330C4: sw          $t0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r8;
    // 0x801330C8: beq         $at, $zero, L_801330E8
    if (ctx->r1 == 0) {
        // 0x801330CC: sw          $a3, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r7;
            goto L_801330E8;
    }
    // 0x801330CC: sw          $a3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r7;
    // 0x801330D0: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x801330D4: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x801330D8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x801330DC: addu        $t7, $t3, $t6
    ctx->r15 = ADD32(ctx->r11, ctx->r14);
    // 0x801330E0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801330E4: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
L_801330E8:
    // 0x801330E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801330EC: bnel        $v0, $t5, L_80132FBC
    if (ctx->r2 != ctx->r13) {
        // 0x801330F0: lw          $a0, 0x0($t1)
        ctx->r4 = MEM_W(ctx->r9, 0X0);
            goto L_80132FBC;
    }
    goto skip_1;
    // 0x801330F0: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    skip_1:
    // 0x801330F4: jr          $ra
    // 0x801330F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x801330F8: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void ftCommonAttackHi4CheckInterruptCommon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015070C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80150710: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80150714: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80150718: jal         0x80150628
    // 0x8015071C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    ftCommonAttackHi4CheckInputSuccess(rdram, ctx);
        goto after_0;
    // 0x8015071C: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80150720: beq         $v0, $zero, L_80150748
    if (ctx->r2 == 0) {
        // 0x80150724: lw          $a0, 0x1C($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X1C);
            goto L_80150748;
    }
    // 0x80150724: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80150728: lbu         $t6, 0x269($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X269);
    // 0x8015072C: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80150730: beql        $at, $zero, L_8015074C
    if (ctx->r1 == 0) {
        // 0x80150734: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8015074C;
    }
    goto skip_0;
    // 0x80150734: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_0:
    // 0x80150738: jal         0x80150660
    // 0x8015073C: nop

    ftCommonAttackHi4CheckInterruptMain(rdram, ctx);
        goto after_1;
    // 0x8015073C: nop

    after_1:
    // 0x80150740: b           L_80150750
    // 0x80150744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80150750;
    // 0x80150744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150748:
    // 0x80150748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8015074C:
    // 0x8015074C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80150750:
    // 0x80150750: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80150754: jr          $ra
    // 0x80150758: nop

    return;
    // 0x80150758: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirLwStartSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F04C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015F050: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F054: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015F058: lui         $t6, 0x8016
    ctx->r14 = S32(0X8016 << 16);
    // 0x8015F05C: addiu       $t6, $t6, -0x102C
    ctx->r14 = ADD32(ctx->r14, -0X102C);
    // 0x8015F060: sw          $t6, 0xA0C($v0)
    MEM_W(0XA0C, ctx->r2) = ctx->r14;
    // 0x8015F064: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015F068: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015F06C: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x8015F070: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015F074: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015F078: jal         0x800E6F24
    // 0x8015F07C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015F07C: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x8015F080: jal         0x800E0830
    // 0x8015F084: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015F084: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_1:
    // 0x8015F088: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x8015F08C: lw          $t7, 0x9C8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X9C8);
    // 0x8015F090: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x8015F094: sb          $t8, 0x148($v0)
    MEM_B(0X148, ctx->r2) = ctx->r24;
    // 0x8015F098: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F09C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015F0A0: jr          $ra
    // 0x8015F0A4: nop

    return;
    // 0x8015F0A4: nop

;}
RECOMP_FUNC void mnVSResultsCheckTeamBattle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801365B4: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801365B8: jr          $ra
    // 0x801365BC: lbu         $v0, -0x63EC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X63EC);
    return;
    // 0x801365BC: lbu         $v0, -0x63EC($v0)
    ctx->r2 = MEM_BU(ctx->r2, -0X63EC);
;}
RECOMP_FUNC void gcDLLinkGObjTail(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007C00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80007C04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80007C08: lbu         $t6, 0xD($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0XD);
    // 0x80007C0C: lui         $a1, 0x8004
    ctx->r5 = S32(0X8004 << 16);
    // 0x80007C10: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80007C14: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x80007C18: lw          $a1, 0x6908($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6908);
    // 0x80007C1C: beq         $a1, $zero, L_80007C54
    if (ctx->r5 == 0) {
        // 0x80007C20: nop
    
            goto L_80007C54;
    }
    // 0x80007C20: nop

    // 0x80007C24: lw          $v0, 0x28($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X28);
    // 0x80007C28: lw          $t8, 0x28($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X28);
    // 0x80007C2C: sltu        $at, $t8, $v0
    ctx->r1 = ctx->r24 < ctx->r2 ? 1 : 0;
    // 0x80007C30: beq         $at, $zero, L_80007C54
    if (ctx->r1 == 0) {
        // 0x80007C34: nop
    
            goto L_80007C54;
    }
    // 0x80007C34: nop

    // 0x80007C38: lw          $a1, 0x24($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X24);
L_80007C3C:
    // 0x80007C3C: beq         $a1, $zero, L_80007C54
    if (ctx->r5 == 0) {
        // 0x80007C40: nop
    
            goto L_80007C54;
    }
    // 0x80007C40: nop

    // 0x80007C44: lw          $t9, 0x28($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X28);
    // 0x80007C48: sltu        $at, $t9, $v0
    ctx->r1 = ctx->r25 < ctx->r2 ? 1 : 0;
    // 0x80007C4C: bnel        $at, $zero, L_80007C3C
    if (ctx->r1 != 0) {
        // 0x80007C50: lw          $a1, 0x24($a1)
        ctx->r5 = MEM_W(ctx->r5, 0X24);
            goto L_80007C3C;
    }
    goto skip_0;
    // 0x80007C50: lw          $a1, 0x24($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X24);
    skip_0:
L_80007C54:
    // 0x80007C54: jal         0x80007B98
    // 0x80007C58: nop

    gcAppendGObjToDLLinkedList(rdram, ctx);
        goto after_0;
    // 0x80007C58: nop

    after_0:
    // 0x80007C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80007C60: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80007C64: jr          $ra
    // 0x80007C68: nop

    return;
    // 0x80007C68: nop

;}
RECOMP_FUNC void func_ovl34_801322C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801322C8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801322CC: lw          $v1, 0x8EC($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8EC);
    // 0x801322D0: lwc1        $f6, 0x19C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X19C);
    // 0x801322D4: lw          $a1, 0x8E8($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X8E8);
    // 0x801322D8: lwc1        $f4, 0x1C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x801322DC: lwc1        $f10, 0x1C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x801322E0: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801322E4: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x801322E8: lwc1        $f10, 0x20($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X20);
    // 0x801322EC: swc1        $f16, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f16.u32l;
    // 0x801322F0: lwc1        $f4, 0x1A0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1A0);
    // 0x801322F4: lwc1        $f18, 0x20($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X20);
    // 0x801322F8: sub.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x801322FC: add.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80132300: lwc1        $f10, 0x24($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X24);
    // 0x80132304: swc1        $f8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f8.u32l;
    // 0x80132308: lwc1        $f18, 0x1A4($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1A4);
    // 0x8013230C: lwc1        $f16, 0x24($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X24);
    // 0x80132310: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80132314: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80132318: jr          $ra
    // 0x8013231C: swc1        $f6, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f6.u32l;
    return;
    // 0x8013231C: swc1        $f6, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f6.u32l;
;}
RECOMP_FUNC void itDogasAttackInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80182E78: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80182E7C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80182E80: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80182E84: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80182E88: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80182E8C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x80182E90: addiu       $at, $zero, 0x2A
    ctx->r1 = ADD32(0, 0X2A);
    // 0x80182E94: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80182E98: sh          $t6, 0x33E($v0)
    MEM_H(0X33E, ctx->r2) = ctx->r14;
    // 0x80182E9C: bne         $t7, $at, L_80182EFC
    if (ctx->r15 != ctx->r1) {
        // 0x80182EA0: sw          $zero, 0x35C($v0)
        MEM_W(0X35C, ctx->r2) = 0;
            goto L_80182EFC;
    }
    // 0x80182EA0: sw          $zero, 0x35C($v0)
    MEM_W(0X35C, ctx->r2) = 0;
    // 0x80182EA4: lw          $t9, 0x1C($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X1C);
    // 0x80182EA8: lw          $t0, 0x2D4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X2D4);
    // 0x80182EAC: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x80182EB0: sw          $t9, 0x350($v0)
    MEM_W(0X350, ctx->r2) = ctx->r25;
    // 0x80182EB4: lw          $t8, 0x20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X20);
    // 0x80182EB8: addiu       $t2, $t2, 0x2820
    ctx->r10 = ADD32(ctx->r10, 0X2820);
    // 0x80182EBC: lui         $t4, 0x1
    ctx->r12 = S32(0X1 << 16);
    // 0x80182EC0: sw          $t8, 0x354($v0)
    MEM_W(0X354, ctx->r2) = ctx->r24;
    // 0x80182EC4: lw          $t9, 0x24($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X24);
    // 0x80182EC8: addiu       $t4, $t4, 0x28DC
    ctx->r12 = ADD32(ctx->r12, 0X28DC);
    // 0x80182ECC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80182ED0: sw          $t9, 0x358($v0)
    MEM_W(0X358, ctx->r2) = ctx->r25;
    // 0x80182ED4: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80182ED8: lw          $a0, 0x10($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X10);
    // 0x80182EDC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80182EE0: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80182EE4: jal         0x8000BD1C
    // 0x80182EE8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    gcAddDObjAnimJoint(rdram, ctx);
        goto after_0;
    // 0x80182EE8: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_0:
    // 0x80182EEC: jal         0x8000DF34
    // 0x80182EF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x80182EF0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80182EF4: jal         0x800269C0
    // 0x80182EF8: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x80182EF8: addiu       $a0, $zero, 0x135
    ctx->r4 = ADD32(0, 0X135);
    after_2:
L_80182EFC:
    // 0x80182EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80182F00: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80182F04: jr          $ra
    // 0x80182F08: nop

    return;
    // 0x80182F08: nop

;}
RECOMP_FUNC void ftCommonTwisterSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80143BC4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80143BC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80143BCC: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80143BD0: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80143BD4: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x80143BD8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80143BDC: jal         0x800E823C
    // 0x80143BE0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    ftParamStopVoiceRunProcDamage(rdram, ctx);
        goto after_0;
    // 0x80143BE0: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80143BE4: lw          $v0, 0x84C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X84C);
    // 0x80143BE8: beql        $v0, $zero, L_80143C28
    if (ctx->r2 == 0) {
        // 0x80143BEC: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_80143C28;
    }
    goto skip_0;
    // 0x80143BEC: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_0:
    // 0x80143BF0: lw          $t6, 0x84($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84);
    // 0x80143BF4: lbu         $t7, 0x2CE($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X2CE);
    // 0x80143BF8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80143BFC: bnel        $t8, $zero, L_80143C28
    if (ctx->r24 != 0) {
        // 0x80143C00: lw          $a0, 0x840($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X840);
            goto L_80143C28;
    }
    goto skip_1;
    // 0x80143C00: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
    skip_1:
    // 0x80143C04: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80143C08: addiu       $a1, $sp, 0x30
    ctx->r5 = ADD32(ctx->r29, 0X30);
    // 0x80143C0C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80143C10: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80143C14: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80143C18: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x80143C1C: jal         0x80172AEC
    // 0x80143C20: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_1;
    // 0x80143C20: lw          $a0, 0x84C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X84C);
    after_1:
    // 0x80143C24: lw          $a0, 0x840($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X840);
L_80143C28:
    // 0x80143C28: beql        $a0, $zero, L_80143C44
    if (ctx->r4 == 0) {
        // 0x80143C2C: lw          $a0, 0x844($s0)
        ctx->r4 = MEM_W(ctx->r16, 0X844);
            goto L_80143C44;
    }
    goto skip_2;
    // 0x80143C2C: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
    skip_2:
    // 0x80143C30: jal         0x8014B330
    // 0x80143C34: nop

    ftCommonThrownSetStatusDamageRelease(rdram, ctx);
        goto after_2;
    // 0x80143C34: nop

    after_2:
    // 0x80143C38: b           L_80143C54
    // 0x80143C3C: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
        goto L_80143C54;
    // 0x80143C3C: sw          $zero, 0x840($s0)
    MEM_W(0X840, ctx->r16) = 0;
    // 0x80143C40: lw          $a0, 0x844($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X844);
L_80143C44:
    // 0x80143C44: beql        $a0, $zero, L_80143C58
    if (ctx->r4 == 0) {
        // 0x80143C48: lw          $t9, 0x14C($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X14C);
            goto L_80143C58;
    }
    goto skip_3;
    // 0x80143C48: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
    skip_3:
    // 0x80143C4C: jal         0x8014AECC
    // 0x80143C50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    ftCommonThrownDecideFighterLoseGrip(rdram, ctx);
        goto after_3;
    // 0x80143C50: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_3:
L_80143C54:
    // 0x80143C54: lw          $t9, 0x14C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X14C);
L_80143C58:
    // 0x80143C58: bnel        $t9, $zero, L_80143C6C
    if (ctx->r25 != 0) {
        // 0x80143C5C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80143C6C;
    }
    goto skip_4;
    // 0x80143C5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_4:
    // 0x80143C60: jal         0x800DEEC8
    // 0x80143C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_4;
    // 0x80143C64: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x80143C68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80143C6C:
    // 0x80143C6C: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
    // 0x80143C70: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x80143C74: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80143C78: jal         0x800E6F24
    // 0x80143C7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_5;
    // 0x80143C7C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_5:
    // 0x80143C80: jal         0x800E0830
    // 0x80143C84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_6;
    // 0x80143C84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80143C88: jal         0x800D9444
    // 0x80143C8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftPhysicsStopVelAll(rdram, ctx);
        goto after_7;
    // 0x80143C8C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80143C90: sw          $zero, 0xB18($s0)
    MEM_W(0XB18, ctx->r16) = 0;
    // 0x80143C94: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80143C98: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80143C9C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    // 0x80143CA0: jal         0x800E8098
    // 0x80143CA4: sw          $t0, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r8;
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_8;
    // 0x80143CA4: sw          $t0, 0xB1C($s0)
    MEM_W(0XB1C, ctx->r16) = ctx->r8;
    after_8:
    // 0x80143CA8: jal         0x800269C0
    // 0x80143CAC: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    func_800269C0_275C0(rdram, ctx);
        goto after_9;
    // 0x80143CAC: addiu       $a0, $zero, 0x11C
    ctx->r4 = ADD32(0, 0X11C);
    after_9:
    // 0x80143CB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80143CB4: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80143CB8: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80143CBC: jr          $ra
    // 0x80143CC0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80143CC0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mnPlayersVSCheckBackInRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80138218: lw          $v0, 0x74($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X74);
    // 0x8013821C: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80138220: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80138224: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80138228: lui         $at, 0x4150
    ctx->r1 = S32(0X4150 << 16);
    // 0x8013822C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80138230: add.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80138234: lui         $at, 0x4208
    ctx->r1 = S32(0X4208 << 16);
    // 0x80138238: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x8013823C: nop

    // 0x80138240: bc1t        L_80138260
    if (c1cs) {
        // 0x80138244: nop
    
            goto L_80138260;
    }
    // 0x80138244: nop

    // 0x80138248: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8013824C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80138250: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x80138254: nop

    // 0x80138258: bc1f        L_80138268
    if (!c1cs) {
        // 0x8013825C: nop
    
            goto L_80138268;
    }
    // 0x8013825C: nop

L_80138260:
    // 0x80138260: b           L_80138268
    // 0x80138264: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_80138268;
    // 0x80138264: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80138268:
    // 0x80138268: beq         $v1, $zero, L_80138278
    if (ctx->r3 == 0) {
        // 0x8013826C: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_80138278;
    }
    // 0x8013826C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80138270: jr          $ra
    // 0x80138274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80138274: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80138278:
    // 0x80138278: lwc1        $f16, 0x58($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X58);
    // 0x8013827C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80138280: lui         $at, 0x4374
    ctx->r1 = S32(0X4374 << 16);
    // 0x80138284: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80138288: add.s       $f0, $f16, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8013828C: lui         $at, 0x4392
    ctx->r1 = S32(0X4392 << 16);
    // 0x80138290: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80138294: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80138298: c.le.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl <= ctx->f0.fl;
    // 0x8013829C: nop

    // 0x801382A0: bc1f        L_801382C8
    if (!c1cs) {
        // 0x801382A4: nop
    
            goto L_801382C8;
    }
    // 0x801382A4: nop

    // 0x801382A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801382AC: nop

    // 0x801382B0: c.le.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl <= ctx->f6.fl;
    // 0x801382B4: nop

    // 0x801382B8: bc1f        L_801382C8
    if (!c1cs) {
        // 0x801382BC: nop
    
            goto L_801382C8;
    }
    // 0x801382BC: nop

    // 0x801382C0: b           L_801382C8
    // 0x801382C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_801382C8;
    // 0x801382C4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_801382C8:
    // 0x801382C8: beq         $v1, $zero, L_801382D8
    if (ctx->r3 == 0) {
        // 0x801382CC: nop
    
            goto L_801382D8;
    }
    // 0x801382CC: nop

    // 0x801382D0: jr          $ra
    // 0x801382D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x801382D4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801382D8:
    // 0x801382D8: jr          $ra
    // 0x801382DC: nop

    return;
    // 0x801382DC: nop

;}
RECOMP_FUNC void mnDataFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131B00: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80131B04: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x80131B08: addiu       $t8, $t8, 0x2F40
    ctx->r24 = ADD32(ctx->r24, 0X2F40);
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
RECOMP_FUNC void func_ovl8_8037295C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8037295C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80372960: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80372964: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80372968: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8037296C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80372970: beq         $a0, $zero, L_80372A28
    if (ctx->r4 == 0) {
        // 0x80372974: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_80372A28;
    }
    // 0x80372974: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80372978: lw          $t8, 0x20($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X20);
    // 0x8037297C: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80372980: addiu       $t6, $t6, -0x71A0
    ctx->r14 = ADD32(ctx->r14, -0X71A0);
    // 0x80372984: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80372988: addiu       $t7, $t7, -0x70E8
    ctx->r15 = ADD32(ctx->r15, -0X70E8);
    // 0x8037298C: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80372990: sw          $t7, 0x58($t8)
    MEM_W(0X58, ctx->r24) = ctx->r15;
    // 0x80372994: lw          $t0, 0x1C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X1C);
    // 0x80372998: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x8037299C: addiu       $t9, $t9, -0x6F90
    ctx->r25 = ADD32(ctx->r25, -0X6F90);
    // 0x803729A0: jal         0x80373160
    // 0x803729A4: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    func_ovl8_80373160(rdram, ctx);
        goto after_0;
    // 0x803729A4: sw          $t9, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r25;
    after_0:
    // 0x803729A8: beq         $v0, $zero, L_803729E0
    if (ctx->r2 == 0) {
        // 0x803729AC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_803729E0;
    }
    // 0x803729AC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x803729B0: beql        $v0, $zero, L_803729E4
    if (ctx->r2 == 0) {
        // 0x803729B4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_803729E4;
    }
    goto skip_0;
    // 0x803729B4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    skip_0:
L_803729B8:
    // 0x803729B8: beq         $v1, $zero, L_803729D8
    if (ctx->r3 == 0) {
        // 0x803729BC: lw          $s0, 0x28($v1)
        ctx->r16 = MEM_W(ctx->r3, 0X28);
            goto L_803729D8;
    }
    // 0x803729BC: lw          $s0, 0x28($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X28);
    // 0x803729C0: lw          $v0, 0x30($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X30);
    // 0x803729C4: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x803729C8: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x803729CC: lh          $t1, 0x8($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X8);
    // 0x803729D0: jalr        $t9
    // 0x803729D4: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x803729D4: addu        $a0, $t1, $v1
    ctx->r4 = ADD32(ctx->r9, ctx->r3);
    after_1:
L_803729D8:
    // 0x803729D8: bne         $s0, $zero, L_803729B8
    if (ctx->r16 != 0) {
        // 0x803729DC: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_803729B8;
    }
    // 0x803729DC: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_803729E0:
    // 0x803729E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_803729E4:
    // 0x803729E4: jal         0x80375270
    // 0x803729E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_80375270(rdram, ctx);
        goto after_2;
    // 0x803729E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x803729EC: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x803729F0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803729F4: beql        $t2, $zero, L_80372A14
    if (ctx->r10 == 0) {
        // 0x803729F8: lw          $t3, 0x24($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X24);
            goto L_80372A14;
    }
    goto skip_1;
    // 0x803729F8: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    skip_1:
    // 0x803729FC: jal         0x8037C30C
    // 0x80372A00: lw          $a0, 0x1C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1C);
    func_ovl8_8037C30C(rdram, ctx);
        goto after_3;
    // 0x80372A00: lw          $a0, 0x1C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X1C);
    after_3:
    // 0x80372A04: lw          $a0, 0x20($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X20);
    // 0x80372A08: jal         0x803718C4
    // 0x80372A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_803718C4(rdram, ctx);
        goto after_4;
    // 0x80372A0C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x80372A10: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
L_80372A14:
    // 0x80372A14: andi        $t4, $t3, 0x1
    ctx->r12 = ctx->r11 & 0X1;
    // 0x80372A18: beql        $t4, $zero, L_80372A2C
    if (ctx->r12 == 0) {
        // 0x80372A1C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80372A2C;
    }
    goto skip_2;
    // 0x80372A1C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80372A20: jal         0x803717C0
    // 0x80372A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    func_ovl8_803717C0(rdram, ctx);
        goto after_5;
    // 0x80372A24: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
L_80372A28:
    // 0x80372A28: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80372A2C:
    // 0x80372A2C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80372A30: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80372A34: jr          $ra
    // 0x80372A38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80372A38: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_ovl8_80373A28(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373A28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80373A2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80373A30: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x80373A34: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x80373A38: sdc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X10, ctx->r29);
    // 0x80373A3C: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
    // 0x80373A40: mtc1        $a1, $f20
    ctx->f20.u32l = ctx->r5;
    // 0x80373A44: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80373A48: jal         0x80373160
    // 0x80373A4C: lw          $a0, 0x4C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4C);
    func_ovl8_80373160(rdram, ctx);
        goto after_0;
    // 0x80373A4C: lw          $a0, 0x4C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4C);
    after_0:
    // 0x80373A50: beq         $v0, $zero, L_80373AA4
    if (ctx->r2 == 0) {
        // 0x80373A54: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80373AA4;
    }
    // 0x80373A54: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80373A58: beql        $v0, $zero, L_80373AA8
    if (ctx->r2 == 0) {
        // 0x80373A5C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80373AA8;
    }
    goto skip_0;
    // 0x80373A5C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_0:
    // 0x80373A60: lh          $v0, 0x1E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1E);
L_80373A64:
    // 0x80373A64: blezl       $v0, L_80373A9C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80373A68: lw          $s0, 0x28($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X28);
            goto L_80373A9C;
    }
    goto skip_1;
    // 0x80373A68: lw          $s0, 0x28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X28);
    skip_1:
    // 0x80373A6C: beql        $s1, $s0, L_80373A9C
    if (ctx->r17 == ctx->r16) {
        // 0x80373A70: lw          $s0, 0x28($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X28);
            goto L_80373A9C;
    }
    goto skip_2;
    // 0x80373A70: lw          $s0, 0x28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X28);
    skip_2:
    // 0x80373A74: lh          $t6, 0x1E($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X1E);
    // 0x80373A78: bnel        $v0, $t6, L_80373A9C
    if (ctx->r2 != ctx->r14) {
        // 0x80373A7C: lw          $s0, 0x28($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X28);
            goto L_80373A9C;
    }
    goto skip_3;
    // 0x80373A7C: lw          $s0, 0x28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X28);
    skip_3:
    // 0x80373A80: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80373A84: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80373A88: lw          $t9, 0x44($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X44);
    // 0x80373A8C: lh          $t7, 0x40($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X40);
    // 0x80373A90: jalr        $t9
    // 0x80373A94: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80373A94: addu        $a0, $t7, $s0
    ctx->r4 = ADD32(ctx->r15, ctx->r16);
    after_1:
    // 0x80373A98: lw          $s0, 0x28($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X28);
L_80373A9C:
    // 0x80373A9C: bnel        $s0, $zero, L_80373A64
    if (ctx->r16 != 0) {
        // 0x80373AA0: lh          $v0, 0x1E($s0)
        ctx->r2 = MEM_H(ctx->r16, 0X1E);
            goto L_80373A64;
    }
    goto skip_4;
    // 0x80373AA0: lh          $v0, 0x1E($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X1E);
    skip_4:
L_80373AA4:
    // 0x80373AA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80373AA8:
    // 0x80373AA8: ldc1        $f20, 0x10($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X10);
    // 0x80373AAC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x80373AB0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x80373AB4: jr          $ra
    // 0x80373AB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80373AB8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void func_ovl0_800C9F30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C9F30: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800C9F34: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C9F38: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800C9F3C: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x800C9F40: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x800C9F44: lw          $a1, 0x84($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X84);
    // 0x800C9F48: jal         0x800C9A38
    // 0x800C9F4C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    func_ovl0_800C9A38(rdram, ctx);
        goto after_0;
    // 0x800C9F4C: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x800C9F50: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800C9F54: jal         0x80019EA0
    // 0x800C9F58: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    syMatrixF2LFixedW(rdram, ctx);
        goto after_1;
    // 0x800C9F58: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    after_1:
    // 0x800C9F5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C9F60: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800C9F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C9F68: jr          $ra
    // 0x800C9F6C: nop

    return;
    // 0x800C9F6C: nop

;}
RECOMP_FUNC void ftPurinSpecialAirHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801515F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801515F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801515F8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801515FC: jal         0x800DE6E4
    // 0x80151600: addiu       $a1, $a1, 0x1614
    ctx->r5 = ADD32(ctx->r5, 0X1614);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80151600: addiu       $a1, $a1, 0x1614
    ctx->r5 = ADD32(ctx->r5, 0X1614);
    after_0:
    // 0x80151604: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151608: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015160C: jr          $ra
    // 0x80151610: nop

    return;
    // 0x80151610: nop

;}
RECOMP_FUNC void scExplainMakeSceneInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E13C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018E140: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E144: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018E148: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018E14C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8018E150: jal         0x80009968
    // 0x8018E154: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018E154: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018E158: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018E15C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8018E160: addiu       $a1, $a1, -0x1EEC
    ctx->r5 = ADD32(ctx->r5, -0X1EEC);
    // 0x8018E164: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018E168: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018E16C: jal         0x80008188
    // 0x8018E170: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x8018E170: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_1:
    // 0x8018E174: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018E178: addiu       $v1, $v1, -0x1610
    ctx->r3 = ADD32(ctx->r3, -0X1610);
    // 0x8018E17C: sw          $zero, 0x28($v1)
    MEM_W(0X28, ctx->r3) = 0;
    // 0x8018E180: sw          $zero, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = 0;
    // 0x8018E184: jal         0x8018E114
    // 0x8018E188: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    scExplainSceneInterfaceProcUpdate(rdram, ctx);
        goto after_2;
    // 0x8018E188: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    after_2:
    // 0x8018E18C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E190: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E194: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018E198: jr          $ra
    // 0x8018E19C: nop

    return;
    // 0x8018E19C: nop

;}
RECOMP_FUNC void ftCommonFuraFuraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80149810: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80149814: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80149818: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x8014981C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80149820: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80149824: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x80149828: addiu       $t8, $zero, 0x1E
    ctx->r24 = ADD32(0, 0X1E);
    // 0x8014982C: addiu       $t7, $zero, 0x1E
    ctx->r15 = ADD32(0, 0X1E);
    // 0x80149830: bnel        $t6, $at, L_80149844
    if (ctx->r14 != ctx->r1) {
        // 0x80149834: sw          $t8, 0x34($a1)
        MEM_W(0X34, ctx->r5) = ctx->r24;
            goto L_80149844;
    }
    goto skip_0;
    // 0x80149834: sw          $t8, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r24;
    skip_0:
    // 0x80149838: b           L_80149844
    // 0x8014983C: sw          $t7, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r15;
        goto L_80149844;
    // 0x8014983C: sw          $t7, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r15;
    // 0x80149840: sw          $t8, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r24;
L_80149844:
    // 0x80149844: lw          $t9, 0x26C($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X26C);
    // 0x80149848: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8014984C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80149850: sw          $t0, 0x26C($a1)
    MEM_W(0X26C, ctx->r5) = ctx->r8;
    // 0x80149854: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80149858: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8014985C: jal         0x8014E400
    // 0x80149860: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    ftCommonCaptureTrappedUpdateBreakoutVars(rdram, ctx);
        goto after_0;
    // 0x80149860: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80149864: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80149868: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x8014986C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80149870: lw          $v0, 0x26C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X26C);
    // 0x80149874: subu        $t3, $v0, $t2
    ctx->r11 = SUB32(ctx->r2, ctx->r10);
    // 0x80149878: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8014987C: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80149880: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x80149884: bgtz        $t5, L_80149894
    if (SIGNED(ctx->r13) > 0) {
        // 0x80149888: sw          $t5, 0x26C($a1)
        MEM_W(0X26C, ctx->r5) = ctx->r13;
            goto L_80149894;
    }
    // 0x80149888: sw          $t5, 0x26C($a1)
    MEM_W(0X26C, ctx->r5) = ctx->r13;
    // 0x8014988C: jal         0x8013E1C8
    // 0x80149890: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonWaitSetStatus(rdram, ctx);
        goto after_1;
    // 0x80149890: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_1:
L_80149894:
    // 0x80149894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80149898: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014989C: jr          $ra
    // 0x801498A0: nop

    return;
    // 0x801498A0: nop

;}
RECOMP_FUNC void scVSBattleFuncLights(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E144: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018E148: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E14C: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8018E150: lui         $t7, 0xD9FF
    ctx->r15 = S32(0XD9FF << 16);
    // 0x8018E154: ori         $t7, $t7, 0xFFFF
    ctx->r15 = ctx->r15 | 0XFFFF;
    // 0x8018E158: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x8018E15C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8018E160: lui         $t8, 0x2
    ctx->r24 = S32(0X2 << 16);
    // 0x8018E164: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8018E168: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x8018E16C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8018E170: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8018E174: lw          $a2, 0x1394($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X1394);
    // 0x8018E178: jal         0x800FCB70
    // 0x8018E17C: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    ftDisplayLightsDrawReflect(rdram, ctx);
        goto after_0;
    // 0x8018E17C: lw          $a1, 0x1390($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1390);
    after_0:
    // 0x8018E180: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E184: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018E188: jr          $ra
    // 0x8018E18C: nop

    return;
    // 0x8018E18C: nop

;}
RECOMP_FUNC void wpMarioFireballProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801686F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801686FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168700: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80168704: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80168708: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8016870C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80168710: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x80168714: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x80168718: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x8016871C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80168720: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80168724: jal         0x80019438
    // 0x80168728: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x80168728: nop

    after_0:
    // 0x8016872C: jal         0x80167FA0
    // 0x80168730: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    wpMainVelSetModelPitch(rdram, ctx);
        goto after_1;
    // 0x80168730: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80168734: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168738: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8016873C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80168740: jr          $ra
    // 0x80168744: nop

    return;
    // 0x80168744: nop

;}
RECOMP_FUNC void itSpearWeaponSwarmMakeWeapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801804A4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801804A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801804AC: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x801804B0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x801804B4: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x801804B8: bne         $a2, $at, L_801804CC
    if (ctx->r6 != ctx->r1) {
        // 0x801804BC: lw          $t0, 0x84($a0)
        ctx->r8 = MEM_W(ctx->r4, 0X84);
            goto L_801804CC;
    }
    // 0x801804BC: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x801804C0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801804C4: b           L_801804D4
    // 0x801804C8: addiu       $a1, $a1, -0x518C
    ctx->r5 = ADD32(ctx->r5, -0X518C);
        goto L_801804D4;
    // 0x801804C8: addiu       $a1, $a1, -0x518C
    ctx->r5 = ADD32(ctx->r5, -0X518C);
L_801804CC:
    // 0x801804CC: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x801804D0: addiu       $a1, $a1, -0x5158
    ctx->r5 = ADD32(ctx->r5, -0X5158);
L_801804D4:
    // 0x801804D4: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x801804D8: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x801804DC: jal         0x801655C8
    // 0x801804E0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    wpManagerMakeWeapon(rdram, ctx);
        goto after_0;
    // 0x801804E0: sw          $t0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r8;
    after_0:
    // 0x801804E4: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x801804E8: bne         $v0, $zero, L_801804F8
    if (ctx->r2 != 0) {
        // 0x801804EC: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_801804F8;
    }
    // 0x801804EC: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x801804F0: b           L_801805F8
    // 0x801804F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_801805F8;
    // 0x801804F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_801804F8:
    // 0x801804F8: lw          $t7, 0x24($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X24);
    // 0x801804FC: lui         $at, 0x4302
    ctx->r1 = S32(0X4302 << 16);
    // 0x80180500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80180504: negu        $t9, $t7
    ctx->r25 = SUB32(0, ctx->r15);
    // 0x80180508: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x8018050C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x80180510: addiu       $at, $zero, 0x25
    ctx->r1 = ADD32(0, 0X25);
    // 0x80180514: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80180518: sw          $t9, 0x18($v1)
    MEM_W(0X18, ctx->r3) = ctx->r25;
    // 0x8018051C: lui         $t6, 0x8018
    ctx->r14 = S32(0X8018 << 16);
    // 0x80180520: addiu       $t6, $t6, 0x480
    ctx->r14 = ADD32(ctx->r14, 0X480);
    // 0x80180524: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80180528: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018052C: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80180530: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x80180534: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80180538: lw          $a3, 0x74($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X74);
    // 0x8018053C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x80180540: bnel        $t1, $at, L_80180598
    if (ctx->r9 != ctx->r1) {
        // 0x80180544: sw          $t6, 0x2C($t7)
        MEM_W(0X2C, ctx->r15) = ctx->r14;
            goto L_80180598;
    }
    goto skip_0;
    // 0x80180544: sw          $t6, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r14;
    skip_0:
    // 0x80180548: lw          $t2, 0x10($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X10);
    // 0x8018054C: addiu       $a1, $zero, 0x48
    ctx->r5 = ADD32(0, 0X48);
    // 0x80180550: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80180554: lw          $a0, 0x10($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X10);
    // 0x80180558: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x8018055C: jal         0x80008CC0
    // 0x80180560: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_1;
    // 0x80180560: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80180564: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80180568: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8018056C: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80180570: lw          $t3, 0x18($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X18);
    // 0x80180574: bnel        $t3, $at, L_801805D0
    if (ctx->r11 != ctx->r1) {
        // 0x80180578: lw          $t1, 0x34($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X34);
            goto L_801805D0;
    }
    goto skip_1;
    // 0x80180578: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    skip_1:
    // 0x8018057C: lw          $t4, 0x10($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X10);
    // 0x80180580: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80180584: lwc1        $f16, -0x317C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X317C);
    // 0x80180588: lw          $t5, 0x10($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X10);
    // 0x8018058C: b           L_801805CC
    // 0x80180590: swc1        $f16, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f16.u32l;
        goto L_801805CC;
    // 0x80180590: swc1        $f16, 0x34($t5)
    MEM_W(0X34, ctx->r13) = ctx->f16.u32l;
    // 0x80180594: sw          $t6, 0x2C($t7)
    MEM_W(0X2C, ctx->r15) = ctx->r14;
L_80180598:
    // 0x80180598: lw          $a0, 0x10($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X10);
    // 0x8018059C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x801805A0: jal         0x80008CC0
    // 0x801805A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_2;
    // 0x801805A4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_2:
    // 0x801805A8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x801805AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x801805B0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x801805B4: lw          $t8, 0x18($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X18);
    // 0x801805B8: bne         $t8, $at, L_801805CC
    if (ctx->r24 != ctx->r1) {
        // 0x801805BC: lui         $at, 0x8019
        ctx->r1 = S32(0X8019 << 16);
            goto L_801805CC;
    }
    // 0x801805BC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801805C0: lwc1        $f18, -0x3178($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X3178);
    // 0x801805C4: lw          $t9, 0x10($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X10);
    // 0x801805C8: swc1        $f18, 0x34($t9)
    MEM_W(0X34, ctx->r25) = ctx->f18.u32l;
L_801805CC:
    // 0x801805CC: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
L_801805D0:
    // 0x801805D0: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x801805D4: sw          $t3, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r11;
    // 0x801805D8: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x801805DC: sw          $t2, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r10;
    // 0x801805E0: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x801805E4: sw          $t3, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r11;
    // 0x801805E8: lbu         $t5, 0x260($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X260);
    // 0x801805EC: ori         $t6, $t5, 0x80
    ctx->r14 = ctx->r13 | 0X80;
    // 0x801805F0: sb          $t6, 0x260($v1)
    MEM_B(0X260, ctx->r3) = ctx->r14;
    // 0x801805F4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
L_801805F8:
    // 0x801805F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801805FC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80180600: jr          $ra
    // 0x80180604: nop

    return;
    // 0x80180604: nop

;}
RECOMP_FUNC void func_ovl29_80136988(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136988: jr          $ra
    // 0x8013698C: nop

    return;
    // 0x8013698C: nop

;}
RECOMP_FUNC void itHarisenHoldSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017526C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80175270: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175274: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80175278: lw          $a3, 0x74($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X74);
    // 0x8017527C: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    // 0x80175280: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80175284: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80175288: jal         0x80008CC0
    // 0x8017528C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_0;
    // 0x8017528C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80175290: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80175294: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80175298: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017529C: addiu       $a1, $a1, -0x6554
    ctx->r5 = ADD32(ctx->r5, -0X6554);
    // 0x801752A0: swc1        $f4, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->f4.u32l;
    // 0x801752A4: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x801752A8: jal         0x80172EC8
    // 0x801752AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    itMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801752AC: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_1:
    // 0x801752B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801752B4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801752B8: jr          $ra
    // 0x801752BC: nop

    return;
    // 0x801752BC: nop

;}

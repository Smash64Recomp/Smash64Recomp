#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void mnVSResultsGetWinPlayer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013234C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80132350: lw          $v0, -0x63F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X63F0);
    // 0x80132354: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80132358: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8013235C: beq         $v0, $zero, L_80132370
    if (ctx->r2 == 0) {
        // 0x80132360: addiu       $t0, $zero, 0x29A
        ctx->r8 = ADD32(0, 0X29A);
            goto L_80132370;
    }
    // 0x80132360: addiu       $t0, $zero, 0x29A
    ctx->r8 = ADD32(0, 0X29A);
    // 0x80132364: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132368: bne         $t1, $v0, L_80132410
    if (ctx->r9 != ctx->r2) {
        // 0x8013236C: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80132410;
    }
    // 0x8013236C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80132370:
    // 0x80132370: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80132374: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x80132378: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013237C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80132380: bne         $t1, $t6, L_8013239C
    if (ctx->r9 != ctx->r14) {
        // 0x80132384: lui         $t7, 0x8014
        ctx->r15 = S32(0X8014 << 16);
            goto L_8013239C;
    }
    // 0x80132384: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132388: lw          $t7, -0x6450($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6450);
    // 0x8013238C: bne         $t7, $zero, L_8013239C
    if (ctx->r15 != 0) {
        // 0x80132390: nop
    
            goto L_8013239C;
    }
    // 0x80132390: nop

    // 0x80132394: b           L_80132A1C
    // 0x80132398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80132A1C;
    // 0x80132398: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8013239C:
    // 0x8013239C: lw          $t8, -0x642C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X642C);
    // 0x801323A0: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801323A4: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x801323A8: bne         $t1, $t8, L_801323C4
    if (ctx->r9 != ctx->r24) {
        // 0x801323AC: nop
    
            goto L_801323C4;
    }
    // 0x801323AC: nop

    // 0x801323B0: lw          $t9, -0x644C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X644C);
    // 0x801323B4: bne         $t9, $zero, L_801323C4
    if (ctx->r25 != 0) {
        // 0x801323B8: nop
    
            goto L_801323C4;
    }
    // 0x801323B8: nop

    // 0x801323BC: b           L_80132A1C
    // 0x801323C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80132A1C;
    // 0x801323C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801323C4:
    // 0x801323C4: lw          $t6, -0x6428($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6428);
    // 0x801323C8: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x801323CC: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x801323D0: bne         $t1, $t6, L_801323EC
    if (ctx->r9 != ctx->r14) {
        // 0x801323D4: nop
    
            goto L_801323EC;
    }
    // 0x801323D4: nop

    // 0x801323D8: lw          $t7, -0x6448($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6448);
    // 0x801323DC: bne         $t7, $zero, L_801323EC
    if (ctx->r15 != 0) {
        // 0x801323E0: nop
    
            goto L_801323EC;
    }
    // 0x801323E0: nop

    // 0x801323E4: b           L_80132A1C
    // 0x801323E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80132A1C;
    // 0x801323E8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_801323EC:
    // 0x801323EC: lw          $t8, -0x6424($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6424);
    // 0x801323F0: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801323F4: bnel        $t1, $t8, L_80132A20
    if (ctx->r9 != ctx->r24) {
        // 0x801323F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132A20;
    }
    goto skip_0;
    // 0x801323F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801323FC: lw          $t9, -0x6444($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6444);
    // 0x80132400: bnel        $t9, $zero, L_80132A20
    if (ctx->r25 != 0) {
        // 0x80132404: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132A20;
    }
    goto skip_1;
    // 0x80132404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80132408: b           L_80132A1C
    // 0x8013240C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80132A1C;
    // 0x8013240C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80132410:
    // 0x80132410: addiu       $v1, $sp, 0x5C
    ctx->r3 = ADD32(ctx->r29, 0X5C);
L_80132414:
    // 0x80132414: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80132418: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    // 0x8013241C: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    // 0x80132420: jal         0x80136C08
    // 0x80132424: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    mnVSResultsGetPointsDirect(rdram, ctx);
        goto after_0;
    // 0x80132424: sw          $t0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r8;
    after_0:
    // 0x80132428: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x8013242C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x80132430: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x80132434: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80132438: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x8013243C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132440: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80132444: bne         $at, $zero, L_80132414
    if (ctx->r1 != 0) {
        // 0x80132448: sw          $v0, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r2;
            goto L_80132414;
    }
    // 0x80132448: sw          $v0, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r2;
    // 0x8013244C: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80132450: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80132454: addiu       $a1, $a1, -0x6450
    ctx->r5 = ADD32(ctx->r5, -0X6450);
    // 0x80132458: addiu       $v0, $v0, -0x6430
    ctx->r2 = ADD32(ctx->r2, -0X6430);
    // 0x8013245C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132460: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80132464: addiu       $a0, $sp, 0x6C
    ctx->r4 = ADD32(ctx->r29, 0X6C);
    // 0x80132468: addiu       $a3, $zero, 0x29A
    ctx->r7 = ADD32(0, 0X29A);
L_8013246C:
    // 0x8013246C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80132470: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80132474: addu        $t7, $a1, $v1
    ctx->r15 = ADD32(ctx->r5, ctx->r3);
    // 0x80132478: beql        $t6, $zero, L_801324A4
    if (ctx->r14 == 0) {
        // 0x8013247C: sw          $zero, 0x0($a0)
        MEM_W(0X0, ctx->r4) = 0;
            goto L_801324A4;
    }
    goto skip_2;
    // 0x8013247C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    skip_2:
    // 0x80132480: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132484: bnel        $t8, $zero, L_801324A4
    if (ctx->r24 != 0) {
        // 0x80132488: sw          $zero, 0x0($a0)
        MEM_W(0X0, ctx->r4) = 0;
            goto L_801324A4;
    }
    goto skip_3;
    // 0x80132488: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    skip_3:
    // 0x8013248C: bne         $t0, $a3, L_80132498
    if (ctx->r8 != ctx->r7) {
        // 0x80132490: nop
    
            goto L_80132498;
    }
    // 0x80132490: nop

    // 0x80132494: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_80132498:
    // 0x80132498: b           L_801324A4
    // 0x8013249C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
        goto L_801324A4;
    // 0x8013249C: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x801324A0: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
L_801324A4:
    // 0x801324A4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x801324A8: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x801324AC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x801324B0: bne         $at, $zero, L_8013246C
    if (ctx->r1 != 0) {
        // 0x801324B4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8013246C;
    }
    // 0x801324B4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x801324B8: addiu       $v0, $sp, 0x48
    ctx->r2 = ADD32(ctx->r29, 0X48);
    // 0x801324BC: addiu       $v1, $sp, 0x58
    ctx->r3 = ADD32(ctx->r29, 0X58);
L_801324C0:
    // 0x801324C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801324C4: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x801324C8: bne         $at, $zero, L_801324C0
    if (ctx->r1 != 0) {
        // 0x801324CC: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_801324C0;
    }
    // 0x801324CC: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x801324D0: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x801324D4: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x801324D8: beq         $at, $zero, L_8013261C
    if (ctx->r1 == 0) {
        // 0x801324DC: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_8013261C;
    }
    // 0x801324DC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x801324E0: addiu       $ra, $zero, 0x4
    ctx->r31 = ADD32(0, 0X4);
    // 0x801324E4: subu        $t4, $ra, $t5
    ctx->r12 = SUB32(ctx->r31, ctx->r13);
    // 0x801324E8: andi        $t4, $t4, 0x3
    ctx->r12 = ctx->r12 & 0X3;
    // 0x801324EC: beq         $t4, $zero, L_80132544
    if (ctx->r12 == 0) {
        // 0x801324F0: addu        $v0, $t4, $t5
        ctx->r2 = ADD32(ctx->r12, ctx->r13);
            goto L_80132544;
    }
    // 0x801324F0: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x801324F4: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x801324F8: addiu       $t9, $sp, 0x6C
    ctx->r25 = ADD32(ctx->r29, 0X6C);
    // 0x801324FC: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    // 0x80132500: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
L_80132504:
    // 0x80132504: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80132508: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8013250C: addu        $t8, $a1, $t7
    ctx->r24 = ADD32(ctx->r5, ctx->r15);
    // 0x80132510: beq         $t6, $zero, L_80132534
    if (ctx->r14 == 0) {
        // 0x80132514: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_80132534;
    }
    // 0x80132514: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80132518: addu        $t6, $a1, $v1
    ctx->r14 = ADD32(ctx->r5, ctx->r3);
    // 0x8013251C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80132520: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x80132524: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80132528: beql        $at, $zero, L_80132538
    if (ctx->r1 == 0) {
        // 0x8013252C: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_80132538;
    }
    goto skip_4;
    // 0x8013252C: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_4:
    // 0x80132530: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_80132534:
    // 0x80132534: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_80132538:
    // 0x80132538: bne         $v0, $a2, L_80132504
    if (ctx->r2 != ctx->r6) {
        // 0x8013253C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80132504;
    }
    // 0x8013253C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80132540: beq         $a2, $ra, L_80132614
    if (ctx->r6 == ctx->r31) {
        // 0x80132544: sll         $v1, $a2, 2
        ctx->r3 = S32(ctx->r6 << 2);
            goto L_80132614;
    }
L_80132544:
    // 0x80132544: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80132548: addiu       $t8, $sp, 0x6C
    ctx->r24 = ADD32(ctx->r29, 0X6C);
    // 0x8013254C: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
    // 0x80132550: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
L_80132554:
    // 0x80132554: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x80132558: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8013255C: addu        $t7, $a1, $t9
    ctx->r15 = ADD32(ctx->r5, ctx->r25);
    // 0x80132560: beq         $t6, $zero, L_80132580
    if (ctx->r14 == 0) {
        // 0x80132564: addu        $t6, $a1, $v1
        ctx->r14 = ADD32(ctx->r5, ctx->r3);
            goto L_80132580;
    }
    // 0x80132564: addu        $t6, $a1, $v1
    ctx->r14 = ADD32(ctx->r5, ctx->r3);
    // 0x80132568: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x8013256C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132570: slt         $at, $t8, $t9
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80132574: beql        $at, $zero, L_80132584
    if (ctx->r1 == 0) {
        // 0x80132578: lw          $t7, 0x4($a0)
        ctx->r15 = MEM_W(ctx->r4, 0X4);
            goto L_80132584;
    }
    goto skip_5;
    // 0x80132578: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    skip_5:
    // 0x8013257C: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_80132580:
    // 0x80132580: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
L_80132584:
    // 0x80132584: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x80132588: addu        $t8, $a1, $t6
    ctx->r24 = ADD32(ctx->r5, ctx->r14);
    // 0x8013258C: beq         $t7, $zero, L_801325AC
    if (ctx->r15 == 0) {
        // 0x80132590: addu        $t7, $a1, $v1
        ctx->r15 = ADD32(ctx->r5, ctx->r3);
            goto L_801325AC;
    }
    // 0x80132590: addu        $t7, $a1, $v1
    ctx->r15 = ADD32(ctx->r5, ctx->r3);
    // 0x80132594: lw          $t6, 0x4($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X4);
    // 0x80132598: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8013259C: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801325A0: beql        $at, $zero, L_801325B0
    if (ctx->r1 == 0) {
        // 0x801325A4: lw          $t8, 0x8($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X8);
            goto L_801325B0;
    }
    goto skip_6;
    // 0x801325A4: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    skip_6:
    // 0x801325A8: addiu       $t0, $a2, 0x1
    ctx->r8 = ADD32(ctx->r6, 0X1);
L_801325AC:
    // 0x801325AC: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
L_801325B0:
    // 0x801325B0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x801325B4: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x801325B8: beq         $t8, $zero, L_801325D8
    if (ctx->r24 == 0) {
        // 0x801325BC: addu        $t8, $a1, $v1
        ctx->r24 = ADD32(ctx->r5, ctx->r3);
            goto L_801325D8;
    }
    // 0x801325BC: addu        $t8, $a1, $v1
    ctx->r24 = ADD32(ctx->r5, ctx->r3);
    // 0x801325C0: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x801325C4: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x801325C8: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x801325CC: beql        $at, $zero, L_801325DC
    if (ctx->r1 == 0) {
        // 0x801325D0: lw          $t9, 0xC($a0)
        ctx->r25 = MEM_W(ctx->r4, 0XC);
            goto L_801325DC;
    }
    goto skip_7;
    // 0x801325D0: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
    skip_7:
    // 0x801325D4: addiu       $t0, $a2, 0x2
    ctx->r8 = ADD32(ctx->r6, 0X2);
L_801325D8:
    // 0x801325D8: lw          $t9, 0xC($a0)
    ctx->r25 = MEM_W(ctx->r4, 0XC);
L_801325DC:
    // 0x801325DC: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x801325E0: addu        $t6, $a1, $t8
    ctx->r14 = ADD32(ctx->r5, ctx->r24);
    // 0x801325E4: beq         $t9, $zero, L_80132608
    if (ctx->r25 == 0) {
        // 0x801325E8: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80132608;
    }
    // 0x801325E8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x801325EC: addu        $t9, $a1, $v1
    ctx->r25 = ADD32(ctx->r5, ctx->r3);
    // 0x801325F0: lw          $t8, 0xC($t9)
    ctx->r24 = MEM_W(ctx->r25, 0XC);
    // 0x801325F4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801325F8: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x801325FC: beql        $at, $zero, L_8013260C
    if (ctx->r1 == 0) {
        // 0x80132600: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_8013260C;
    }
    goto skip_8;
    // 0x80132600: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_8:
    // 0x80132604: addiu       $t0, $a2, 0x3
    ctx->r8 = ADD32(ctx->r6, 0X3);
L_80132608:
    // 0x80132608: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_8013260C:
    // 0x8013260C: bne         $a2, $ra, L_80132554
    if (ctx->r6 != ctx->r31) {
        // 0x80132610: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_80132554;
    }
    // 0x80132610: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80132614:
    // 0x80132614: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
    // 0x80132618: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
L_8013261C:
    // 0x8013261C: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80132620: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x80132624: addiu       $ra, $zero, 0x4
    ctx->r31 = ADD32(0, 0X4);
    // 0x80132628: beq         $at, $zero, L_801327A0
    if (ctx->r1 == 0) {
        // 0x8013262C: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_801327A0;
    }
    // 0x8013262C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80132630: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80132634: subu        $t4, $t6, $t5
    ctx->r12 = SUB32(ctx->r14, ctx->r13);
    // 0x80132638: andi        $t4, $t4, 0x3
    ctx->r12 = ctx->r12 & 0X3;
    // 0x8013263C: beq         $t4, $zero, L_801326A0
    if (ctx->r12 == 0) {
        // 0x80132640: addu        $t3, $t4, $t5
        ctx->r11 = ADD32(ctx->r12, ctx->r13);
            goto L_801326A0;
    }
    // 0x80132640: addu        $t3, $t4, $t5
    ctx->r11 = ADD32(ctx->r12, ctx->r13);
    // 0x80132644: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80132648: addiu       $t9, $sp, 0x6C
    ctx->r25 = ADD32(ctx->r29, 0X6C);
    // 0x8013264C: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    // 0x80132650: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
L_80132654:
    // 0x80132654: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x80132658: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8013265C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80132660: beq         $t7, $zero, L_80132694
    if (ctx->r15 == 0) {
        // 0x80132664: sll         $v0, $t0, 2
        ctx->r2 = S32(ctx->r8 << 2);
            goto L_80132694;
    }
    // 0x80132664: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80132668: addu        $t8, $a1, $v0
    ctx->r24 = ADD32(ctx->r5, ctx->r2);
    // 0x8013266C: addu        $t9, $a1, $v1
    ctx->r25 = ADD32(ctx->r5, ctx->r3);
    // 0x80132670: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80132674: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80132678: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x8013267C: addu        $t9, $a3, $v0
    ctx->r25 = ADD32(ctx->r7, ctx->r2);
    // 0x80132680: bne         $t6, $t7, L_80132694
    if (ctx->r14 != ctx->r15) {
        // 0x80132684: nop
    
            goto L_80132694;
    }
    // 0x80132684: nop

    // 0x80132688: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x8013268C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x80132690: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
L_80132694:
    // 0x80132694: bne         $t3, $a2, L_80132654
    if (ctx->r11 != ctx->r6) {
        // 0x80132698: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80132654;
    }
    // 0x80132698: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8013269C: beq         $a2, $ra, L_801327A0
    if (ctx->r6 == ctx->r31) {
        // 0x801326A0: sll         $v1, $a2, 2
        ctx->r3 = S32(ctx->r6 << 2);
            goto L_801327A0;
    }
L_801326A0:
    // 0x801326A0: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x801326A4: addiu       $t6, $sp, 0x6C
    ctx->r14 = ADD32(ctx->r29, 0X6C);
    // 0x801326A8: addu        $a0, $v1, $t6
    ctx->r4 = ADD32(ctx->r3, ctx->r14);
    // 0x801326AC: addiu       $a2, $sp, 0x7C
    ctx->r6 = ADD32(ctx->r29, 0X7C);
    // 0x801326B0: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
L_801326B4:
    // 0x801326B4: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x801326B8: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x801326BC: addu        $t8, $a1, $v0
    ctx->r24 = ADD32(ctx->r5, ctx->r2);
    // 0x801326C0: beq         $t7, $zero, L_801326EC
    if (ctx->r15 == 0) {
        // 0x801326C4: addu        $t6, $a1, $v1
        ctx->r14 = ADD32(ctx->r5, ctx->r3);
            goto L_801326EC;
    }
    // 0x801326C4: addu        $t6, $a1, $v1
    ctx->r14 = ADD32(ctx->r5, ctx->r3);
    // 0x801326C8: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x801326CC: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x801326D0: addu        $t6, $a3, $v0
    ctx->r14 = ADD32(ctx->r7, ctx->r2);
    // 0x801326D4: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x801326D8: bnel        $t9, $t7, L_801326F0
    if (ctx->r25 != ctx->r15) {
        // 0x801326DC: lw          $t9, 0x4($a0)
        ctx->r25 = MEM_W(ctx->r4, 0X4);
            goto L_801326F0;
    }
    goto skip_9;
    // 0x801326DC: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    skip_9:
    // 0x801326E0: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
    // 0x801326E4: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801326E8: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
L_801326EC:
    // 0x801326EC: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
L_801326F0:
    // 0x801326F0: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x801326F4: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x801326F8: beq         $t9, $zero, L_80132724
    if (ctx->r25 == 0) {
        // 0x801326FC: addu        $t6, $a1, $v1
        ctx->r14 = ADD32(ctx->r5, ctx->r3);
            goto L_80132724;
    }
    // 0x801326FC: addu        $t6, $a1, $v1
    ctx->r14 = ADD32(ctx->r5, ctx->r3);
    // 0x80132700: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132704: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80132708: addu        $t6, $a3, $v0
    ctx->r14 = ADD32(ctx->r7, ctx->r2);
    // 0x8013270C: addu        $t7, $a3, $v1
    ctx->r15 = ADD32(ctx->r7, ctx->r3);
    // 0x80132710: bnel        $t8, $t9, L_80132728
    if (ctx->r24 != ctx->r25) {
        // 0x80132714: lw          $t8, 0x8($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X8);
            goto L_80132728;
    }
    goto skip_10;
    // 0x80132714: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    skip_10:
    // 0x80132718: sw          $t1, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r9;
    // 0x8013271C: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x80132720: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
L_80132724:
    // 0x80132724: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
L_80132728:
    // 0x80132728: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x8013272C: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x80132730: beq         $t8, $zero, L_8013275C
    if (ctx->r24 == 0) {
        // 0x80132734: addu        $t6, $a1, $v1
        ctx->r14 = ADD32(ctx->r5, ctx->r3);
            goto L_8013275C;
    }
    // 0x80132734: addu        $t6, $a1, $v1
    ctx->r14 = ADD32(ctx->r5, ctx->r3);
    // 0x80132738: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x8013273C: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80132740: addu        $t6, $a3, $v0
    ctx->r14 = ADD32(ctx->r7, ctx->r2);
    // 0x80132744: addu        $t9, $a3, $v1
    ctx->r25 = ADD32(ctx->r7, ctx->r3);
    // 0x80132748: bnel        $t7, $t8, L_80132760
    if (ctx->r15 != ctx->r24) {
        // 0x8013274C: lw          $t7, 0xC($a0)
        ctx->r15 = MEM_W(ctx->r4, 0XC);
            goto L_80132760;
    }
    goto skip_11;
    // 0x8013274C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    skip_11:
    // 0x80132750: sw          $t1, 0x8($t9)
    MEM_W(0X8, ctx->r25) = ctx->r9;
    // 0x80132754: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x80132758: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
L_8013275C:
    // 0x8013275C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
L_80132760:
    // 0x80132760: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80132764: addu        $t8, $a1, $v0
    ctx->r24 = ADD32(ctx->r5, ctx->r2);
    // 0x80132768: beq         $t7, $zero, L_80132798
    if (ctx->r15 == 0) {
        // 0x8013276C: addiu       $a0, $a0, 0x10
        ctx->r4 = ADD32(ctx->r4, 0X10);
            goto L_80132798;
    }
    // 0x8013276C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80132770: addu        $t6, $a1, $v1
    ctx->r14 = ADD32(ctx->r5, ctx->r3);
    // 0x80132774: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x80132778: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8013277C: addu        $t8, $a3, $v1
    ctx->r24 = ADD32(ctx->r7, ctx->r3);
    // 0x80132780: addu        $t6, $a3, $v0
    ctx->r14 = ADD32(ctx->r7, ctx->r2);
    // 0x80132784: bne         $t9, $t7, L_80132798
    if (ctx->r25 != ctx->r15) {
        // 0x80132788: nop
    
            goto L_80132798;
    }
    // 0x80132788: nop

    // 0x8013278C: sw          $t1, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->r9;
    // 0x80132790: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x80132794: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
L_80132798:
    // 0x80132798: bne         $a0, $a2, L_801326B4
    if (ctx->r4 != ctx->r6) {
        // 0x8013279C: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_801326B4;
    }
    // 0x8013279C: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_801327A0:
    // 0x801327A0: beq         $t2, $zero, L_80132A18
    if (ctx->r10 == 0) {
        // 0x801327A4: slti        $at, $t5, 0x4
        ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
            goto L_80132A18;
    }
    // 0x801327A4: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x801327A8: beq         $at, $zero, L_801328F0
    if (ctx->r1 == 0) {
        // 0x801327AC: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_801328F0;
    }
    // 0x801327AC: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x801327B0: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x801327B4: subu        $t4, $t9, $t5
    ctx->r12 = SUB32(ctx->r25, ctx->r13);
    // 0x801327B8: andi        $t4, $t4, 0x3
    ctx->r12 = ctx->r12 & 0X3;
    // 0x801327BC: beq         $t4, $zero, L_80132818
    if (ctx->r12 == 0) {
        // 0x801327C0: addu        $a1, $t4, $t5
        ctx->r5 = ADD32(ctx->r12, ctx->r13);
            goto L_80132818;
    }
    // 0x801327C0: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x801327C4: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x801327C8: addiu       $t7, $sp, 0x48
    ctx->r15 = ADD32(ctx->r29, 0X48);
    // 0x801327CC: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x801327D0: addiu       $a0, $a0, -0x6480
    ctx->r4 = ADD32(ctx->r4, -0X6480);
    // 0x801327D4: addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
L_801327D8:
    // 0x801327D8: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x801327DC: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x801327E0: addu        $t9, $a0, $t6
    ctx->r25 = ADD32(ctx->r4, ctx->r14);
    // 0x801327E4: beq         $t8, $zero, L_80132808
    if (ctx->r24 == 0) {
        // 0x801327E8: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80132808;
    }
    // 0x801327E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x801327EC: addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // 0x801327F0: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x801327F4: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x801327F8: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801327FC: beql        $at, $zero, L_8013280C
    if (ctx->r1 == 0) {
        // 0x80132800: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8013280C;
    }
    goto skip_12;
    // 0x80132800: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    skip_12:
    // 0x80132804: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_80132808:
    // 0x80132808: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8013280C:
    // 0x8013280C: bne         $a1, $a2, L_801327D8
    if (ctx->r5 != ctx->r6) {
        // 0x80132810: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_801327D8;
    }
    // 0x80132810: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80132814: beq         $a2, $ra, L_801328EC
    if (ctx->r6 == ctx->r31) {
        // 0x80132818: lui         $a0, 0x8014
        ctx->r4 = S32(0X8014 << 16);
            goto L_801328EC;
    }
L_80132818:
    // 0x80132818: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x8013281C: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80132820: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x80132824: addu        $v0, $v1, $t9
    ctx->r2 = ADD32(ctx->r3, ctx->r25);
    // 0x80132828: addiu       $a0, $a0, -0x6480
    ctx->r4 = ADD32(ctx->r4, -0X6480);
L_8013282C:
    // 0x8013282C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80132830: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x80132834: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x80132838: beq         $t8, $zero, L_80132858
    if (ctx->r24 == 0) {
        // 0x8013283C: addu        $t8, $a0, $v1
        ctx->r24 = ADD32(ctx->r4, ctx->r3);
            goto L_80132858;
    }
    // 0x8013283C: addu        $t8, $a0, $v1
    ctx->r24 = ADD32(ctx->r4, ctx->r3);
    // 0x80132840: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x80132844: lw          $t9, 0x0($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X0);
    // 0x80132848: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8013284C: beql        $at, $zero, L_8013285C
    if (ctx->r1 == 0) {
        // 0x80132850: lw          $t6, 0x4($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X4);
            goto L_8013285C;
    }
    goto skip_13;
    // 0x80132850: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    skip_13:
    // 0x80132854: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
L_80132858:
    // 0x80132858: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
L_8013285C:
    // 0x8013285C: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x80132860: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x80132864: beq         $t6, $zero, L_80132884
    if (ctx->r14 == 0) {
        // 0x80132868: addu        $t6, $a0, $v1
        ctx->r14 = ADD32(ctx->r4, ctx->r3);
            goto L_80132884;
    }
    // 0x80132868: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x8013286C: lw          $t8, 0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X4);
    // 0x80132870: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x80132874: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80132878: beql        $at, $zero, L_80132888
    if (ctx->r1 == 0) {
        // 0x8013287C: lw          $t9, 0x8($v0)
        ctx->r25 = MEM_W(ctx->r2, 0X8);
            goto L_80132888;
    }
    goto skip_14;
    // 0x8013287C: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    skip_14:
    // 0x80132880: addiu       $t0, $a2, 0x1
    ctx->r8 = ADD32(ctx->r6, 0X1);
L_80132884:
    // 0x80132884: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
L_80132888:
    // 0x80132888: sll         $t6, $t0, 2
    ctx->r14 = S32(ctx->r8 << 2);
    // 0x8013288C: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x80132890: beq         $t9, $zero, L_801328B0
    if (ctx->r25 == 0) {
        // 0x80132894: addu        $t9, $a0, $v1
        ctx->r25 = ADD32(ctx->r4, ctx->r3);
            goto L_801328B0;
    }
    // 0x80132894: addu        $t9, $a0, $v1
    ctx->r25 = ADD32(ctx->r4, ctx->r3);
    // 0x80132898: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8013289C: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x801328A0: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x801328A4: beql        $at, $zero, L_801328B4
    if (ctx->r1 == 0) {
        // 0x801328A8: lw          $t7, 0xC($v0)
        ctx->r15 = MEM_W(ctx->r2, 0XC);
            goto L_801328B4;
    }
    goto skip_15;
    // 0x801328A8: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    skip_15:
    // 0x801328AC: addiu       $t0, $a2, 0x2
    ctx->r8 = ADD32(ctx->r6, 0X2);
L_801328B0:
    // 0x801328B0: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
L_801328B4:
    // 0x801328B4: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x801328B8: addu        $t8, $a0, $t9
    ctx->r24 = ADD32(ctx->r4, ctx->r25);
    // 0x801328BC: beq         $t7, $zero, L_801328E0
    if (ctx->r15 == 0) {
        // 0x801328C0: addiu       $v0, $v0, 0x10
        ctx->r2 = ADD32(ctx->r2, 0X10);
            goto L_801328E0;
    }
    // 0x801328C0: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x801328C4: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x801328C8: lw          $t9, 0xC($t7)
    ctx->r25 = MEM_W(ctx->r15, 0XC);
    // 0x801328CC: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x801328D0: slt         $at, $t6, $t9
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x801328D4: beql        $at, $zero, L_801328E4
    if (ctx->r1 == 0) {
        // 0x801328D8: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_801328E4;
    }
    goto skip_16;
    // 0x801328D8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    skip_16:
    // 0x801328DC: addiu       $t0, $a2, 0x3
    ctx->r8 = ADD32(ctx->r6, 0X3);
L_801328E0:
    // 0x801328E0: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_801328E4:
    // 0x801328E4: bne         $a2, $ra, L_8013282C
    if (ctx->r6 != ctx->r31) {
        // 0x801328E8: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_8013282C;
    }
    // 0x801328E8: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_801328EC:
    // 0x801328EC: addiu       $t5, $t0, 0x1
    ctx->r13 = ADD32(ctx->r8, 0X1);
L_801328F0:
    // 0x801328F0: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x801328F4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801328F8: addiu       $v1, $v1, -0x63D0
    ctx->r3 = ADD32(ctx->r3, -0X63D0);
    // 0x801328FC: addiu       $v0, $v0, -0x63E0
    ctx->r2 = ADD32(ctx->r2, -0X63E0);
L_80132900:
    // 0x80132900: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80132904: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x80132908: bne         $at, $zero, L_80132900
    if (ctx->r1 != 0) {
        // 0x8013290C: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80132900;
    }
    // 0x8013290C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80132910: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x80132914: beq         $at, $zero, L_80132A18
    if (ctx->r1 == 0) {
        // 0x80132918: or          $a2, $t5, $zero
        ctx->r6 = ctx->r13 | 0;
            goto L_80132A18;
    }
    // 0x80132918: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    // 0x8013291C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80132920: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x80132924: subu        $t4, $t6, $t5
    ctx->r12 = SUB32(ctx->r14, ctx->r13);
    // 0x80132928: addiu       $t8, $t8, -0x6480
    ctx->r24 = ADD32(ctx->r24, -0X6480);
    // 0x8013292C: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x80132930: addu        $t7, $v0, $t8
    ctx->r15 = ADD32(ctx->r2, ctx->r24);
    // 0x80132934: andi        $t4, $t4, 0x3
    ctx->r12 = ctx->r12 & 0X3;
    // 0x80132938: beq         $t4, $zero, L_80132980
    if (ctx->r12 == 0) {
        // 0x8013293C: lw          $a3, 0x0($t7)
        ctx->r7 = MEM_W(ctx->r15, 0X0);
            goto L_80132980;
    }
    // 0x8013293C: lw          $a3, 0x0($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X0);
    // 0x80132940: sll         $v1, $t5, 2
    ctx->r3 = S32(ctx->r13 << 2);
    // 0x80132944: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80132948: addiu       $a1, $a1, -0x63E0
    ctx->r5 = ADD32(ctx->r5, -0X63E0);
    // 0x8013294C: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
    // 0x80132950: addu        $t2, $t4, $t5
    ctx->r10 = ADD32(ctx->r12, ctx->r13);
L_80132954:
    // 0x80132954: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80132958: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8013295C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80132960: bne         $a3, $t9, L_80132974
    if (ctx->r7 != ctx->r25) {
        // 0x80132964: addu        $t7, $a1, $v1
        ctx->r15 = ADD32(ctx->r5, ctx->r3);
            goto L_80132974;
    }
    // 0x80132964: addu        $t7, $a1, $v1
    ctx->r15 = ADD32(ctx->r5, ctx->r3);
    // 0x80132968: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x8013296C: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x80132970: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
L_80132974:
    // 0x80132974: bne         $t2, $a2, L_80132954
    if (ctx->r10 != ctx->r6) {
        // 0x80132978: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80132954;
    }
    // 0x80132978: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8013297C: beq         $a2, $ra, L_80132A18
    if (ctx->r6 == ctx->r31) {
        // 0x80132980: sll         $v1, $a2, 2
        ctx->r3 = S32(ctx->r6 << 2);
            goto L_80132A18;
    }
L_80132980:
    // 0x80132980: sll         $v1, $a2, 2
    ctx->r3 = S32(ctx->r6 << 2);
    // 0x80132984: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80132988: addiu       $t8, $t8, -0x6480
    ctx->r24 = ADD32(ctx->r24, -0X6480);
    // 0x8013298C: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x80132990: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x80132994: addiu       $a1, $a1, -0x63E0
    ctx->r5 = ADD32(ctx->r5, -0X63E0);
    // 0x80132998: addiu       $a2, $a2, -0x6470
    ctx->r6 = ADD32(ctx->r6, -0X6470);
    // 0x8013299C: addu        $a0, $v1, $t8
    ctx->r4 = ADD32(ctx->r3, ctx->r24);
L_801329A0:
    // 0x801329A0: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x801329A4: addu        $t7, $a1, $v1
    ctx->r15 = ADD32(ctx->r5, ctx->r3);
    // 0x801329A8: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x801329AC: bnel        $a3, $t9, L_801329C0
    if (ctx->r7 != ctx->r25) {
        // 0x801329B0: lw          $t8, 0x4($a0)
        ctx->r24 = MEM_W(ctx->r4, 0X4);
            goto L_801329C0;
    }
    goto skip_17;
    // 0x801329B0: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
    skip_17:
    // 0x801329B4: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x801329B8: sw          $t1, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r9;
    // 0x801329BC: lw          $t8, 0x4($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4);
L_801329C0:
    // 0x801329C0: addu        $t9, $a1, $v1
    ctx->r25 = ADD32(ctx->r5, ctx->r3);
    // 0x801329C4: addu        $t7, $a1, $v0
    ctx->r15 = ADD32(ctx->r5, ctx->r2);
    // 0x801329C8: bnel        $a3, $t8, L_801329DC
    if (ctx->r7 != ctx->r24) {
        // 0x801329CC: lw          $t6, 0x8($a0)
        ctx->r14 = MEM_W(ctx->r4, 0X8);
            goto L_801329DC;
    }
    goto skip_18;
    // 0x801329CC: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    skip_18:
    // 0x801329D0: sw          $t1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r9;
    // 0x801329D4: sw          $t1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r9;
    // 0x801329D8: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
L_801329DC:
    // 0x801329DC: addu        $t8, $a1, $v1
    ctx->r24 = ADD32(ctx->r5, ctx->r3);
    // 0x801329E0: addu        $t9, $a1, $v0
    ctx->r25 = ADD32(ctx->r5, ctx->r2);
    // 0x801329E4: bnel        $a3, $t6, L_801329F8
    if (ctx->r7 != ctx->r14) {
        // 0x801329E8: lw          $t7, 0xC($a0)
        ctx->r15 = MEM_W(ctx->r4, 0XC);
            goto L_801329F8;
    }
    goto skip_19;
    // 0x801329E8: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    skip_19:
    // 0x801329EC: sw          $t1, 0x8($t8)
    MEM_W(0X8, ctx->r24) = ctx->r9;
    // 0x801329F0: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x801329F4: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
L_801329F8:
    // 0x801329F8: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x801329FC: addu        $t6, $a1, $v1
    ctx->r14 = ADD32(ctx->r5, ctx->r3);
    // 0x80132A00: bne         $a3, $t7, L_80132A10
    if (ctx->r7 != ctx->r15) {
        // 0x80132A04: addu        $t8, $a1, $v0
        ctx->r24 = ADD32(ctx->r5, ctx->r2);
            goto L_80132A10;
    }
    // 0x80132A04: addu        $t8, $a1, $v0
    ctx->r24 = ADD32(ctx->r5, ctx->r2);
    // 0x80132A08: sw          $t1, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r9;
    // 0x80132A0C: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
L_80132A10:
    // 0x80132A10: bne         $a0, $a2, L_801329A0
    if (ctx->r4 != ctx->r6) {
        // 0x80132A14: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_801329A0;
    }
    // 0x80132A14: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
L_80132A18:
    // 0x80132A18: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_80132A1C:
    // 0x80132A1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132A20:
    // 0x80132A20: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    // 0x80132A24: jr          $ra
    // 0x80132A28: nop

    return;
    // 0x80132A28: nop

;}
RECOMP_FUNC void itFFlowerCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80175C9C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80175CA0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80175CA4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80175CA8: jal         0x80172FE0
    // 0x80175CAC: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x80175CAC: sw          $zero, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = 0;
    after_0:
    // 0x80175CB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80175CB4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80175CB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80175CBC: jr          $ra
    // 0x80175CC0: nop

    return;
    // 0x80175CC0: nop

;}
RECOMP_FUNC void func_ovl8_803747B8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803747B8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x803747BC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803747C0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x803747C4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x803747C8: jal         0x803717A0
    // 0x803747CC: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x803747CC: addiu       $a0, $zero, 0xA8
    ctx->r4 = ADD32(0, 0XA8);
    after_0:
    // 0x803747D0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x803747D4: beq         $v0, $zero, L_80374804
    if (ctx->r2 == 0) {
        // 0x803747D8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80374804;
    }
    // 0x803747D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x803747DC: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x803747E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x803747E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x803747E8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x803747EC: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x803747F0: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x803747F4: jal         0x8038259C
    // 0x803747F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    func_ovl8_8038259C(rdram, ctx);
        goto after_1;
    // 0x803747F8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    after_1:
    // 0x803747FC: b           L_80374808
    // 0x80374800: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
        goto L_80374808;
    // 0x80374800: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
L_80374804:
    // 0x80374804: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80374808:
    // 0x80374808: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8037480C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80374810: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80374814: jr          $ra
    // 0x80374818: nop

    return;
    // 0x80374818: nop

;}
RECOMP_FUNC void sc1PStageClearGetNoMissMultiplier(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133128: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8013312C: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133130: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80133134: addiu       $t6, $t6, 0x5198
    ctx->r14 = ADD32(ctx->r14, 0X5198);
    // 0x80133138: addiu       $t0, $t6, 0x30
    ctx->r8 = ADD32(ctx->r14, 0X30);
    // 0x8013313C: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80133140:
    // 0x80133140: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133144: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80133148: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8013314C: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80133150: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80133154: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80133158: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8013315C: bne         $t6, $t0, L_80133140
    if (ctx->r14 != ctx->r8) {
        // 0x80133160: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80133140;
    }
    // 0x80133160: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80133164: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80133168: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8013316C: addu        $t2, $v1, $t1
    ctx->r10 = ADD32(ctx->r3, ctx->r9);
    // 0x80133170: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80133174: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x80133178: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8013317C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80133180: jr          $ra
    // 0x80133184: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80133184: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void gcAddMObjMatAnimJoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000BD54: lw          $v0, 0x90($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X90);
    // 0x8000BD58: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x8000BD5C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000BD60: beql        $v0, $zero, L_8000BD7C
    if (ctx->r2 == 0) {
        // 0x8000BD64: sw          $a1, 0x94($a0)
        MEM_W(0X94, ctx->r4) = ctx->r5;
            goto L_8000BD7C;
    }
    goto skip_0;
    // 0x8000BD64: sw          $a1, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r5;
    skip_0:
    // 0x8000BD68: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
L_8000BD6C:
    // 0x8000BD6C: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    // 0x8000BD70: bnel        $v0, $zero, L_8000BD6C
    if (ctx->r2 != 0) {
        // 0x8000BD74: sb          $zero, 0x5($v0)
        MEM_B(0X5, ctx->r2) = 0;
            goto L_8000BD6C;
    }
    goto skip_1;
    // 0x8000BD74: sb          $zero, 0x5($v0)
    MEM_B(0X5, ctx->r2) = 0;
    skip_1:
    // 0x8000BD78: sw          $a1, 0x94($a0)
    MEM_W(0X94, ctx->r4) = ctx->r5;
L_8000BD7C:
    // 0x8000BD7C: lwc1        $f4, -0x222C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X222C);
    // 0x8000BD80: swc1        $f12, 0xA0($a0)
    MEM_W(0XA0, ctx->r4) = ctx->f12.u32l;
    // 0x8000BD84: jr          $ra
    // 0x8000BD88: swc1        $f4, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x8000BD88: swc1        $f4, 0x98($a0)
    MEM_W(0X98, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void mn1PModeMakeBonus2Practice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320F8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801320FC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132100: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132104: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132108: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x8013210C: jal         0x80009968
    // 0x80132110: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132110: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132114: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132118: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8013211C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132120: sw          $v0, 0x31AC($at)
    MEM_W(0X31AC, ctx->r1) = ctx->r2;
    // 0x80132124: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80132128: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013212C: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80132130: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132134: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80132138: jal         0x80009DF4
    // 0x8013213C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8013213C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80132140: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80132144: lw          $t7, 0x3294($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3294);
    // 0x80132148: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8013214C: addiu       $t8, $t8, 0x1108
    ctx->r24 = ADD32(ctx->r24, 0X1108);
    // 0x80132150: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132154: jal         0x800CCFDC
    // 0x80132158: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x80132158: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8013215C: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80132160: lui         $at, 0x4286
    ctx->r1 = S32(0X4286 << 16);
    // 0x80132164: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132168: lui         $at, 0x4314
    ctx->r1 = S32(0X4314 << 16);
    // 0x8013216C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132170: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80132174: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80132178: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x8013217C: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80132180: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132184: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132188: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x8013218C: lw          $a1, 0x31B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31B8);
    // 0x80132190: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80132194: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80132198: xori        $a1, $a1, 0x3
    ctx->r5 = ctx->r5 ^ 0X3;
    // 0x8013219C: jal         0x80131B24
    // 0x801321A0: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x801321A0: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x801321A4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x801321A8: lw          $t3, 0x3294($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3294);
    // 0x801321AC: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x801321B0: addiu       $t4, $t4, 0x6388
    ctx->r12 = ADD32(ctx->r12, 0X6388);
    // 0x801321B4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801321B8: jal         0x800CCFDC
    // 0x801321BC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x801321BC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_4:
    // 0x801321C0: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x801321C4: lui         $at, 0x42AC
    ctx->r1 = S32(0X42AC << 16);
    // 0x801321C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x801321CC: lui         $at, 0x4315
    ctx->r1 = S32(0X4315 << 16);
    // 0x801321D0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801321D4: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x801321D8: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x801321DC: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x801321E0: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x801321E4: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x801321E8: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x801321EC: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801321F0: swc1        $f8, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f8.u32l;
    // 0x801321F4: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x801321F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801321FC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80132200: jr          $ra
    // 0x80132204: nop

    return;
    // 0x80132204: nop

;}
RECOMP_FUNC void n_alCSeqNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028884: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80028888: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002888C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80028890: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80028894: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80028898: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002889C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800288A0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800288A4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800288A8: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800288AC: sw          $a1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r5;
    // 0x800288B0: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800288B4: sw          $zero, 0x10($a0)
    MEM_W(0X10, ctx->r4) = 0;
    // 0x800288B8: sw          $zero, 0xC($a0)
    MEM_W(0XC, ctx->r4) = 0;
    // 0x800288BC: sw          $t6, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r14;
    // 0x800288C0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800288C4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800288C8: addiu       $s3, $zero, 0x10
    ctx->r19 = ADD32(0, 0X10);
    // 0x800288CC: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x800288D0: or          $t4, $a0, $zero
    ctx->r12 = ctx->r4 | 0;
L_800288D4:
    // 0x800288D4: sb          $zero, 0xA8($s1)
    MEM_B(0XA8, ctx->r17) = 0;
    // 0x800288D8: sw          $zero, 0x58($t4)
    MEM_W(0X58, ctx->r12) = 0;
    // 0x800288DC: sb          $zero, 0x98($s1)
    MEM_B(0X98, ctx->r17) = 0;
    // 0x800288E0: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800288E4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800288E8: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800288EC: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800288F0: sllv        $t7, $t6, $t5
    ctx->r15 = S32(ctx->r14 << (ctx->r13 & 31));
    // 0x800288F4: beq         $v0, $zero, L_80028920
    if (ctx->r2 == 0) {
        // 0x800288F8: addu        $t6, $s4, $v0
        ctx->r14 = ADD32(ctx->r20, ctx->r2);
            goto L_80028920;
    }
    // 0x800288F8: addu        $t6, $s4, $v0
    ctx->r14 = ADD32(ctx->r20, ctx->r2);
    // 0x800288FC: lw          $t9, 0x4($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X4);
    // 0x80028900: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x80028904: or          $t3, $t5, $zero
    ctx->r11 = ctx->r13 | 0;
    // 0x80028908: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x8002890C: sw          $t8, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r24;
    // 0x80028910: jal         0x8002852C
    // 0x80028914: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    __readVarLen(rdram, ctx);
        goto after_0;
    // 0x80028914: sw          $t6, 0x18($t4)
    MEM_W(0X18, ctx->r12) = ctx->r14;
    after_0:
    // 0x80028918: b           L_80028924
    // 0x8002891C: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
        goto L_80028924;
    // 0x8002891C: sw          $v0, 0xB8($t4)
    MEM_W(0XB8, ctx->r12) = ctx->r2;
L_80028920:
    // 0x80028920: sw          $zero, 0x18($t4)
    MEM_W(0X18, ctx->r12) = 0;
L_80028924:
    // 0x80028924: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x80028928: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8002892C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80028930: bne         $t5, $s3, L_800288D4
    if (ctx->r13 != ctx->r19) {
        // 0x80028934: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_800288D4;
    }
    // 0x80028934: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80028938: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8002893C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80028940: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80028944: lw          $t7, 0x40($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X40);
    // 0x80028948: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8002894C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80028950: bgez        $t7, L_80028964
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80028954: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80028964;
    }
    // 0x80028954: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80028958: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8002895C: nop

    // 0x80028960: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80028964:
    // 0x80028964: div.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80028968: swc1        $f6, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f6.u32l;
    // 0x8002896C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80028970: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80028974: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80028978: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002897C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80028980: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80028984: jr          $ra
    // 0x80028988: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80028988: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeRoomCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133718: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013371C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133720: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133724: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80133728: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x8013372C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133730: lui         $t9, 0x2000
    ctx->r25 = S32(0X2000 << 16);
    // 0x80133734: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80133738: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013373C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133740: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133744: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80133748: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013374C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80133750: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133754: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133758: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013375C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80133760: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133764: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133768: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8013376C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133770: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133774: jal         0x8000B93C
    // 0x80133778: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133778: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013377C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80133780: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133784: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133788: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8013378C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133790: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133794: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133798: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x8013379C: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801337A0: jal         0x80007080
    // 0x801337A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801337A4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801337A8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801337AC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801337B0: jr          $ra
    // 0x801337B4: nop

    return;
    // 0x801337B4: nop

;}
RECOMP_FUNC void ftHammerCheckHoldHammer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F3794: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800F3798: lw          $v1, 0x84C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84C);
    // 0x800F379C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800F37A0: beq         $v1, $zero, L_800F37C4
    if (ctx->r3 == 0) {
        // 0x800F37A4: nop
    
            goto L_800F37C4;
    }
    // 0x800F37A4: nop

    // 0x800F37A8: lw          $t6, 0x84($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X84);
    // 0x800F37AC: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x800F37B0: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x800F37B4: bne         $t7, $at, L_800F37C4
    if (ctx->r15 != ctx->r1) {
        // 0x800F37B8: nop
    
            goto L_800F37C4;
    }
    // 0x800F37B8: nop

    // 0x800F37BC: jr          $ra
    // 0x800F37C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800F37C0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F37C4:
    // 0x800F37C4: jr          $ra
    // 0x800F37C8: nop

    return;
    // 0x800F37C8: nop

;}
RECOMP_FUNC void sc1PGameSetupStageAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D60C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018D610: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8018D614: lui         $fp, 0x800A
    ctx->r30 = S32(0X800A << 16);
    // 0x8018D618: addiu       $fp, $fp, 0x4AD0
    ctx->r30 = ADD32(ctx->r30, 0X4AD0);
    // 0x8018D61C: lbu         $v0, 0x17($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X17);
    // 0x8018D620: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8018D624: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D628: lui         $s6, 0x800A
    ctx->r22 = S32(0X800A << 16);
    // 0x8018D62C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8018D630: addiu       $t7, $t7, 0x29BC
    ctx->r15 = ADD32(ctx->r15, 0X29BC);
    // 0x8018D634: sll         $t6, $v0, 4
    ctx->r14 = S32(ctx->r2 << 4);
    // 0x8018D638: addiu       $s6, $s6, 0x50E8
    ctx->r22 = ADD32(ctx->r22, 0X50E8);
    // 0x8018D63C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018D640: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8018D644: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8018D648: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8018D64C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8018D650: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8018D654: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018D658: addu        $s7, $t6, $t7
    ctx->r23 = ADD32(ctx->r14, ctx->r15);
    // 0x8018D65C: sb          $zero, 0x12($fp)
    MEM_B(0X12, ctx->r30) = 0;
    // 0x8018D660: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8018D664: lbu         $t4, 0x1($s7)
    ctx->r12 = MEM_BU(ctx->r23, 0X1);
    // 0x8018D668: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8018D66C: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8018D670: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018D674: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D678: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x8018D67C: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8018D680: addiu       $t9, $t9, 0x2830
    ctx->r25 = ADD32(ctx->r25, 0X2830);
    // 0x8018D684: sb          $t4, 0x1($t5)
    MEM_B(0X1, ctx->r13) = ctx->r12;
    // 0x8018D688: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8018D68C: lbu         $t6, 0x0($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X0);
    // 0x8018D690: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8018D694: sb          $t6, 0x9($t7)
    MEM_B(0X9, ctx->r15) = ctx->r14;
    // 0x8018D698: lbu         $t8, 0x17($fp)
    ctx->r24 = MEM_BU(ctx->r30, 0X17);
    // 0x8018D69C: addiu       $t9, $t8, -0xB
    ctx->r25 = ADD32(ctx->r24, -0XB);
    // 0x8018D6A0: sltiu       $at, $t9, 0x7
    ctx->r1 = ctx->r25 < 0X7 ? 1 : 0;
    // 0x8018D6A4: beq         $at, $zero, L_8018D6E0
    if (ctx->r1 == 0) {
        // 0x8018D6A8: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_8018D6E0;
    }
    // 0x8018D6A8: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8018D6AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D6B0: addu        $at, $at, $t9
    gpr jr_addend_8018D6B8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8018D6B4: lw          $t9, 0x2E68($at)
    ctx->r25 = ADD32(ctx->r1, 0X2E68);
    // 0x8018D6B8: jr          $t9
    // 0x8018D6BC: nop

    switch (jr_addend_8018D6B8 >> 2) {
        case 0: goto L_8018D6C0; break;
        case 1: goto L_8018D6E0; break;
        case 2: goto L_8018D6E0; break;
        case 3: goto L_8018D6D0; break;
        case 4: goto L_8018D6D0; break;
        case 5: goto L_8018D6D0; break;
        case 6: goto L_8018D6D0; break;
        default: switch_error(__func__, 0x8018D6B8, 0x80192E68);
    }
    // 0x8018D6BC: nop

L_8018D6C0:
    // 0x8018D6C0: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8018D6C4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018D6C8: b           L_8018D6EC
    // 0x8018D6CC: sb          $t4, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r12;
        goto L_8018D6EC;
    // 0x8018D6CC: sb          $t4, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r12;
L_8018D6D0:
    // 0x8018D6D0: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8018D6D4: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x8018D6D8: b           L_8018D6EC
    // 0x8018D6DC: sb          $t6, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r14;
        goto L_8018D6EC;
    // 0x8018D6DC: sb          $t6, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r14;
L_8018D6E0:
    // 0x8018D6E0: lbu         $t8, 0x16($fp)
    ctx->r24 = MEM_BU(ctx->r30, 0X16);
    // 0x8018D6E4: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x8018D6E8: sb          $t8, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r24;
L_8018D6EC:
    // 0x8018D6EC: lw          $t4, 0x4($s7)
    ctx->r12 = MEM_W(ctx->r23, 0X4);
    // 0x8018D6F0: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8018D6F4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018D6F8: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D6FC: sw          $t4, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->r12;
    // 0x8018D700: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8018D704: lbu         $t6, 0x1($t3)
    ctx->r14 = MEM_BU(ctx->r11, 0X1);
    // 0x8018D708: addiu       $a1, $a1, 0x2FA1
    ctx->r5 = ADD32(ctx->r5, 0X2FA1);
    // 0x8018D70C: addiu       $a0, $a0, 0x2FA8
    ctx->r4 = ADD32(ctx->r4, 0X2FA8);
    // 0x8018D710: sb          $t6, 0x1C($t7)
    MEM_B(0X1C, ctx->r15) = ctx->r14;
    // 0x8018D714: lbu         $t4, 0x8($s7)
    ctx->r12 = MEM_BU(ctx->r23, 0X8);
    // 0x8018D718: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D71C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018D720: sb          $t4, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r12;
    // 0x8018D724: sb          $t4, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r12;
    // 0x8018D728: sb          $t4, 0x2FA0($at)
    MEM_B(0X2FA0, ctx->r1) = ctx->r12;
    // 0x8018D72C: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D730: sw          $zero, 0x2FA4($at)
    MEM_W(0X2FA4, ctx->r1) = 0;
    // 0x8018D734: lbu         $v1, 0x13($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X13);
    // 0x8018D738: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018D73C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018D740: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8018D744: addiu       $v0, $v0, 0x2FE0
    ctx->r2 = ADD32(ctx->r2, 0X2FE0);
    // 0x8018D748: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8018D74C: addiu       $t2, $zero, 0x74
    ctx->r10 = ADD32(0, 0X74);
    // 0x8018D750: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8018D754: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_8018D758:
    // 0x8018D758: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8018D75C: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x8018D760: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8018D764: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8018D768: sw          $zero, 0x14($v0)
    MEM_W(0X14, ctx->r2) = 0;
    // 0x8018D76C: sb          $zero, 0x18($v0)
    MEM_B(0X18, ctx->r2) = 0;
    // 0x8018D770: beq         $s3, $t0, L_8018D794
    if (ctx->r19 == ctx->r8) {
        // 0x8018D774: swc1        $f0, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
            goto L_8018D794;
    }
    // 0x8018D774: swc1        $f0, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f0.u32l;
    // 0x8018D778: multu       $s3, $t2
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D77C: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8018D780: mflo        $t6
    ctx->r14 = lo;
    // 0x8018D784: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8018D788: sb          $a0, 0x22($t7)
    MEM_B(0X22, ctx->r15) = ctx->r4;
    // 0x8018D78C: lbu         $v1, 0x13($fp)
    ctx->r3 = MEM_BU(ctx->r30, 0X13);
    // 0x8018D790: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_8018D794:
    // 0x8018D794: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018D798: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8018D79C: bne         $at, $zero, L_8018D758
    if (ctx->r1 != 0) {
        // 0x8018D7A0: addiu       $v0, $v0, 0x20
        ctx->r2 = ADD32(ctx->r2, 0X20);
            goto L_8018D758;
    }
    // 0x8018D7A0: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    // 0x8018D7A4: lbu         $a3, 0x17($fp)
    ctx->r7 = MEM_BU(ctx->r30, 0X17);
    // 0x8018D7A8: addiu       $a2, $zero, 0x74
    ctx->r6 = ADD32(0, 0X74);
    // 0x8018D7AC: addiu       $s1, $zero, 0xD
    ctx->r17 = ADD32(0, 0XD);
    // 0x8018D7B0: slti        $at, $a3, 0xE
    ctx->r1 = SIGNED(ctx->r7) < 0XE ? 1 : 0;
    // 0x8018D7B4: beq         $at, $zero, L_8018D7F0
    if (ctx->r1 == 0) {
        // 0x8018D7B8: nop
    
            goto L_8018D7F0;
    }
    // 0x8018D7B8: nop

    // 0x8018D7BC: addiu       $a2, $zero, 0x74
    ctx->r6 = ADD32(0, 0X74);
    // 0x8018D7C0: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D7C4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8018D7C8: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018D7CC: addiu       $t4, $t4, 0x2FE0
    ctx->r12 = ADD32(ctx->r12, 0X2FE0);
    // 0x8018D7D0: sll         $t9, $v1, 5
    ctx->r25 = S32(ctx->r3 << 5);
    // 0x8018D7D4: addu        $v0, $t9, $t4
    ctx->r2 = ADD32(ctx->r25, ctx->r12);
    // 0x8018D7D8: addiu       $t5, $zero, 0x21
    ctx->r13 = ADD32(0, 0X21);
    // 0x8018D7DC: mflo        $t8
    ctx->r24 = lo;
    // 0x8018D7E0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x8018D7E4: sb          $zero, 0x4B41($at)
    MEM_B(0X4B41, ctx->r1) = 0;
    // 0x8018D7E8: b           L_8018D820
    // 0x8018D7EC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
        goto L_8018D820;
    // 0x8018D7EC: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_8018D7F0:
    // 0x8018D7F0: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D7F4: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x8018D7F8: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D7FC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018D800: addiu       $t9, $t9, 0x2FE0
    ctx->r25 = ADD32(ctx->r25, 0X2FE0);
    // 0x8018D804: sll         $t8, $v1, 5
    ctx->r24 = S32(ctx->r3 << 5);
    // 0x8018D808: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x8018D80C: addiu       $t4, $zero, 0x2C
    ctx->r12 = ADD32(0, 0X2C);
    // 0x8018D810: mflo        $t7
    ctx->r15 = lo;
    // 0x8018D814: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8018D818: sb          $t6, 0x4B41($at)
    MEM_B(0X4B41, ctx->r1) = ctx->r14;
    // 0x8018D81C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8018D820:
    // 0x8018D820: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8018D824: beq         $a3, $at, L_8018D840
    if (ctx->r7 == ctx->r1) {
        // 0x8018D828: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_8018D840;
    }
    // 0x8018D828: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8018D82C: beql        $a1, $s1, L_8018D844
    if (ctx->r5 == ctx->r17) {
        // 0x8018D830: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8018D844;
    }
    goto skip_0;
    // 0x8018D830: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    skip_0:
    // 0x8018D834: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x8018D838: b           L_8018D850
    // 0x8018D83C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
        goto L_8018D850;
    // 0x8018D83C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
L_8018D840:
    // 0x8018D840: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8018D844:
    // 0x8018D844: addiu       $s1, $zero, 0xD
    ctx->r17 = ADD32(0, 0XD);
    // 0x8018D848: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x8018D84C: sw          $t3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r11;
L_8018D850:
    // 0x8018D850: sltiu       $at, $a3, 0x12
    ctx->r1 = ctx->r7 < 0X12 ? 1 : 0;
    // 0x8018D854: beq         $at, $zero, L_8018DFF0
    if (ctx->r1 == 0) {
        // 0x8018D858: or          $s4, $t0, $zero
        ctx->r20 = ctx->r8 | 0;
            goto L_8018DFF0;
    }
    // 0x8018D858: or          $s4, $t0, $zero
    ctx->r20 = ctx->r8 | 0;
    // 0x8018D85C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8018D860: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018D864: addu        $at, $at, $t6
    gpr jr_addend_8018D86C = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x8018D868: lw          $t6, 0x2E84($at)
    ctx->r14 = ADD32(ctx->r1, 0X2E84);
    // 0x8018D86C: jr          $t6
    // 0x8018D870: nop

    switch (jr_addend_8018D86C >> 2) {
        case 0: goto L_8018D874; break;
        case 1: goto L_8018DAC0; break;
        case 2: goto L_8018D874; break;
        case 3: goto L_8018DFF0; break;
        case 4: goto L_8018D874; break;
        case 5: goto L_8018D874; break;
        case 6: goto L_8018D874; break;
        case 7: goto L_8018DFF0; break;
        case 8: goto L_8018DDD0; break;
        case 9: goto L_8018D874; break;
        case 10: goto L_8018D874; break;
        case 11: goto L_8018DEEC; break;
        case 12: goto L_8018DC64; break;
        case 13: goto L_8018D874; break;
        case 14: goto L_8018D874; break;
        case 15: goto L_8018D874; break;
        case 16: goto L_8018D874; break;
        case 17: goto L_8018D874; break;
        default: switch_error(__func__, 0x8018D86C, 0x80192E84);
    }
    // 0x8018D870: nop

L_8018D874:
    // 0x8018D874: lbu         $t7, 0xC($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0XC);
    // 0x8018D878: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8018D87C: addiu       $v0, $v0, 0x4AD0
    ctx->r2 = ADD32(ctx->r2, 0X4AD0);
    // 0x8018D880: blez        $t7, L_8018D9D0
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8018D884: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8018D9D0;
    }
    // 0x8018D884: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8018D888: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018D88C: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x8018D890: addiu       $a1, $a1, 0x44E0
    ctx->r5 = ADD32(ctx->r5, 0X44E0);
    // 0x8018D894: addiu       $t0, $t0, 0x2FE0
    ctx->r8 = ADD32(ctx->r8, 0X2FE0);
    // 0x8018D898: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018D89C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x8018D8A0: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    // 0x8018D8A4: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
L_8018D8A8:
    // 0x8018D8A8: lbu         $t8, 0x45A($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X45A);
    // 0x8018D8AC: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8018D8B0: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D8B4: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x8018D8B8: lbu         $t4, 0xC($t9)
    ctx->r12 = MEM_BU(ctx->r25, 0XC);
    // 0x8018D8BC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8018D8C0: mflo        $t7
    ctx->r15 = lo;
    // 0x8018D8C4: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x8018D8C8: sb          $t4, 0x20($t8)
    MEM_B(0X20, ctx->r24) = ctx->r12;
    // 0x8018D8CC: lbu         $t4, 0x17($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X17);
    // 0x8018D8D0: lbu         $t9, 0x45A($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X45A);
    // 0x8018D8D4: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8018D8D8: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D8DC: addu        $t6, $t1, $t9
    ctx->r14 = ADD32(ctx->r9, ctx->r25);
    // 0x8018D8E0: lbu         $t5, 0x11($t6)
    ctx->r13 = MEM_BU(ctx->r14, 0X11);
    // 0x8018D8E4: mflo        $t8
    ctx->r24 = lo;
    // 0x8018D8E8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8018D8EC: sb          $t5, 0x21($t9)
    MEM_B(0X21, ctx->r25) = ctx->r13;
    // 0x8018D8F0: lbu         $t4, 0x17($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X17);
    // 0x8018D8F4: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x8018D8F8: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D8FC: mflo        $t7
    ctx->r15 = lo;
    // 0x8018D900: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8018D904: sb          $zero, 0x24($t8)
    MEM_B(0X24, ctx->r24) = 0;
    // 0x8018D908: lbu         $t4, 0x17($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X17);
    // 0x8018D90C: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x8018D910: lbu         $t5, 0x13($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0X13);
    // 0x8018D914: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D918: mflo        $t6
    ctx->r14 = lo;
    // 0x8018D91C: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x8018D920: sb          $t5, 0x28($t7)
    MEM_B(0X28, ctx->r15) = ctx->r13;
    // 0x8018D924: lbu         $t4, 0x17($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X17);
    // 0x8018D928: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x8018D92C: multu       $t4, $a2
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D930: mflo        $t9
    ctx->r25 = lo;
    // 0x8018D934: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x8018D938: sb          $a3, 0x2A($t6)
    MEM_B(0X2A, ctx->r14) = ctx->r7;
    // 0x8018D93C: lbu         $t7, 0x17($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X17);
    // 0x8018D940: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8018D944: multu       $t7, $a2
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D948: mflo        $t4
    ctx->r12 = lo;
    // 0x8018D94C: addu        $t8, $t5, $t4
    ctx->r24 = ADD32(ctx->r13, ctx->r12);
    // 0x8018D950: sb          $t2, 0x29($t8)
    MEM_B(0X29, ctx->r24) = ctx->r10;
    // 0x8018D954: lbu         $t6, 0x17($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X17);
    // 0x8018D958: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x8018D95C: multu       $t6, $a2
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D960: mflo        $t7
    ctx->r15 = lo;
    // 0x8018D964: addu        $t5, $t9, $t7
    ctx->r13 = ADD32(ctx->r25, ctx->r15);
    // 0x8018D968: sb          $zero, 0x2B($t5)
    MEM_B(0X2B, ctx->r13) = 0;
    // 0x8018D96C: lbu         $t8, 0x17($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X17);
    // 0x8018D970: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x8018D974: multu       $t8, $a2
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D978: mflo        $t6
    ctx->r14 = lo;
    // 0x8018D97C: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x8018D980: sb          $zero, 0x2C($t9)
    MEM_B(0X2C, ctx->r25) = 0;
    // 0x8018D984: lbu         $t5, 0x17($v0)
    ctx->r13 = MEM_BU(ctx->r2, 0X17);
    // 0x8018D988: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8018D98C: addiu       $t9, $s3, 0x22
    ctx->r25 = ADD32(ctx->r19, 0X22);
    // 0x8018D990: multu       $t5, $a2
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8018D994: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018D998: mflo        $t8
    ctx->r24 = lo;
    // 0x8018D99C: addu        $t4, $t7, $t8
    ctx->r12 = ADD32(ctx->r15, ctx->r24);
    // 0x8018D9A0: sb          $t2, 0x22($t4)
    MEM_B(0X22, ctx->r12) = ctx->r10;
    // 0x8018D9A4: lbu         $s4, 0x17($v0)
    ctx->r20 = MEM_BU(ctx->r2, 0X17);
    // 0x8018D9A8: sll         $t6, $s4, 5
    ctx->r14 = S32(ctx->r20 << 5);
    // 0x8018D9AC: addu        $a0, $t0, $t6
    ctx->r4 = ADD32(ctx->r8, ctx->r14);
    // 0x8018D9B0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8018D9B4: lbu         $t5, 0xD($s7)
    ctx->r13 = MEM_BU(ctx->r23, 0XD);
    // 0x8018D9B8: sb          $t5, 0x18($a0)
    MEM_B(0X18, ctx->r4) = ctx->r13;
    // 0x8018D9BC: lbu         $t7, 0xC($s7)
    ctx->r15 = MEM_BU(ctx->r23, 0XC);
    // 0x8018D9C0: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8018D9C4: bnel        $at, $zero, L_8018D8A8
    if (ctx->r1 != 0) {
        // 0x8018D9C8: lbu         $t6, 0x18($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X18);
            goto L_8018D8A8;
    }
    goto skip_1;
    // 0x8018D9C8: lbu         $t6, 0x18($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X18);
    skip_1:
    // 0x8018D9CC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8018D9D0:
    // 0x8018D9D0: lbu         $t8, 0x8($s7)
    ctx->r24 = MEM_BU(ctx->r23, 0X8);
    // 0x8018D9D4: blezl       $t8, L_8018DFF4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8018D9D8: lw          $t5, 0x0($s6)
        ctx->r13 = MEM_W(ctx->r22, 0X0);
            goto L_8018DFF4;
    }
    goto skip_2;
    // 0x8018D9D8: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    skip_2:
L_8018D9DC:
    // 0x8018D9DC: jal         0x8018D280
    // 0x8018D9E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    sc1PGameGetNextFreePlayerPort(rdram, ctx);
        goto after_0;
    // 0x8018D9E0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_0:
    // 0x8018D9E4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018D9E8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8018D9EC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8018D9F0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8018D9F4: jal         0x8018D4EC
    // 0x8018D9F8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    sc1PGameSetupEnemyPlayer(rdram, ctx);
        goto after_1;
    // 0x8018D9F8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_1:
    // 0x8018D9FC: jal         0x8018D29C
    // 0x8018DA00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    sc1PGameGetNextFreeCostume(rdram, ctx);
        goto after_2;
    // 0x8018DA00: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x8018DA04: sll         $s0, $s4, 3
    ctx->r16 = S32(ctx->r20 << 3);
    // 0x8018DA08: subu        $s0, $s0, $s4
    ctx->r16 = SUB32(ctx->r16, ctx->r20);
    // 0x8018DA0C: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x8018DA10: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8018DA14: addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    // 0x8018DA18: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8018DA1C: addu        $t6, $t4, $s0
    ctx->r14 = ADD32(ctx->r12, ctx->r16);
    // 0x8018DA20: sb          $v0, 0x26($t6)
    MEM_B(0X26, ctx->r14) = ctx->r2;
    // 0x8018DA24: lbu         $a3, 0x17($fp)
    ctx->r7 = MEM_BU(ctx->r30, 0X17);
    // 0x8018DA28: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018DA2C: addiu       $t4, $t4, 0x2FE0
    ctx->r12 = ADD32(ctx->r12, 0X2FE0);
    // 0x8018DA30: slti        $at, $a3, 0xE
    ctx->r1 = SIGNED(ctx->r7) < 0XE ? 1 : 0;
    // 0x8018DA34: beq         $at, $zero, L_8018DA58
    if (ctx->r1 == 0) {
        // 0x8018DA38: sll         $t8, $s4, 5
        ctx->r24 = S32(ctx->r20 << 5);
            goto L_8018DA58;
    }
    // 0x8018DA38: sll         $t8, $s4, 5
    ctx->r24 = S32(ctx->r20 << 5);
    // 0x8018DA3C: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x8018DA40: addiu       $t5, $t5, 0x2FE0
    ctx->r13 = ADD32(ctx->r13, 0X2FE0);
    // 0x8018DA44: sll         $t9, $s4, 5
    ctx->r25 = S32(ctx->r20 << 5);
    // 0x8018DA48: addu        $v0, $t9, $t5
    ctx->r2 = ADD32(ctx->r25, ctx->r13);
    // 0x8018DA4C: addiu       $t7, $s3, 0x25
    ctx->r15 = ADD32(ctx->r19, 0X25);
    // 0x8018DA50: b           L_8018DA98
    // 0x8018DA54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
        goto L_8018DA98;
    // 0x8018DA54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8018DA58:
    // 0x8018DA58: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x8018DA5C: addu        $v0, $t8, $t4
    ctx->r2 = ADD32(ctx->r24, ctx->r12);
    // 0x8018DA60: addiu       $t6, $s3, 0x2D
    ctx->r14 = ADD32(ctx->r19, 0X2D);
    // 0x8018DA64: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018DA68: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x8018DA6C: lbu         $t5, 0x20($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X20);
    // 0x8018DA70: lbu         $t7, 0x43($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X43);
    // 0x8018DA74: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018DA78: subu        $v1, $t5, $t7
    ctx->r3 = SUB32(ctx->r13, ctx->r15);
    // 0x8018DA7C: bgtzl       $v1, L_8018DA94
    if (SIGNED(ctx->r3) > 0) {
        // 0x8018DA80: sb          $v1, 0x20($a0)
        MEM_B(0X20, ctx->r4) = ctx->r3;
            goto L_8018DA94;
    }
    goto skip_3;
    // 0x8018DA80: sb          $v1, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r3;
    skip_3:
    // 0x8018DA84: sb          $t8, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r24;
    // 0x8018DA88: b           L_8018DA98
    // 0x8018DA8C: lbu         $a3, 0x17($fp)
    ctx->r7 = MEM_BU(ctx->r30, 0X17);
        goto L_8018DA98;
    // 0x8018DA8C: lbu         $a3, 0x17($fp)
    ctx->r7 = MEM_BU(ctx->r30, 0X17);
    // 0x8018DA90: sb          $v1, 0x20($a0)
    MEM_B(0X20, ctx->r4) = ctx->r3;
L_8018DA94:
    // 0x8018DA94: lbu         $a3, 0x17($fp)
    ctx->r7 = MEM_BU(ctx->r30, 0X17);
L_8018DA98:
    // 0x8018DA98: bne         $s1, $a3, L_8018DAA4
    if (ctx->r17 != ctx->r7) {
        // 0x8018DA9C: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_8018DAA4;
    }
    // 0x8018DA9C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8018DAA0: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
L_8018DAA4:
    // 0x8018DAA4: lbu         $t6, 0x8($s7)
    ctx->r14 = MEM_BU(ctx->r23, 0X8);
    // 0x8018DAA8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018DAAC: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8018DAB0: bne         $at, $zero, L_8018D9DC
    if (ctx->r1 != 0) {
        // 0x8018DAB4: nop
    
            goto L_8018D9DC;
    }
    // 0x8018DAB4: nop

    // 0x8018DAB8: b           L_8018DFF4
    // 0x8018DABC: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
        goto L_8018DFF4;
    // 0x8018DABC: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
L_8018DAC0:
    // 0x8018DAC0: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018DAC4: lui         $s3, 0x8019
    ctx->r19 = S32(0X8019 << 16);
    // 0x8018DAC8: addiu       $s1, $zero, 0x6
    ctx->r17 = ADD32(0, 0X6);
    // 0x8018DACC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018DAD0: addiu       $s3, $s3, 0x2FB6
    ctx->r19 = ADD32(ctx->r19, 0X2FB6);
    // 0x8018DAD4: addiu       $s0, $s0, 0x2FB0
    ctx->r16 = ADD32(ctx->r16, 0X2FB0);
L_8018DAD8:
    // 0x8018DAD8: jal         0x80018994
    // 0x8018DADC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syUtilsRandIntRange(rdram, ctx);
        goto after_3;
    // 0x8018DADC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x8018DAE0: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x8018DAE4: jal         0x8018D394
    // 0x8018DAE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    sc1PGameGetFighterKindsNum(rdram, ctx);
        goto after_4;
    // 0x8018DAE8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_4:
    // 0x8018DAEC: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8018DAF0: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018DAF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018DAF8: sllv        $t7, $t5, $t9
    ctx->r15 = S32(ctx->r13 << (ctx->r25 & 31));
    // 0x8018DAFC: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8018DB00: or          $s2, $s2, $t7
    ctx->r18 = ctx->r18 | ctx->r15;
    // 0x8018DB04: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // 0x8018DB08: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x8018DB0C: bne         $at, $zero, L_8018DAD8
    if (ctx->r1 != 0) {
        // 0x8018DB10: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8018DAD8;
    }
    // 0x8018DB10: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8018DB14: lbu         $t8, 0x8($s7)
    ctx->r24 = MEM_BU(ctx->r23, 0X8);
    // 0x8018DB18: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018DB1C: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
    // 0x8018DB20: slti        $at, $t8, 0x7
    ctx->r1 = SIGNED(ctx->r24) < 0X7 ? 1 : 0;
    // 0x8018DB24: bne         $at, $zero, L_8018DB74
    if (ctx->r1 != 0) {
        // 0x8018DB28: lui         $s1, 0x8019
        ctx->r17 = S32(0X8019 << 16);
            goto L_8018DB74;
    }
    // 0x8018DB28: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018DB2C: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018DB30: lui         $s5, 0x8019
    ctx->r21 = S32(0X8019 << 16);
    // 0x8018DB34: addiu       $s5, $s5, 0x2FB0
    ctx->r21 = ADD32(ctx->r21, 0X2FB0);
    // 0x8018DB38: addiu       $s0, $s0, 0x2FB6
    ctx->r16 = ADD32(ctx->r16, 0X2FB6);
    // 0x8018DB3C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x8018DB40: addu        $t4, $s5, $v0
    ctx->r12 = ADD32(ctx->r21, ctx->r2);
L_8018DB44:
    // 0x8018DB44: lbu         $t6, 0x0($t4)
    ctx->r14 = MEM_BU(ctx->r12, 0X0);
    // 0x8018DB48: bne         $v0, $v1, L_8018DB58
    if (ctx->r2 != ctx->r3) {
        // 0x8018DB4C: sb          $t6, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r14;
            goto L_8018DB58;
    }
    // 0x8018DB4C: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8018DB50: b           L_8018DB5C
    // 0x8018DB54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018DB5C;
    // 0x8018DB54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018DB58:
    // 0x8018DB58: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8018DB5C:
    // 0x8018DB5C: lbu         $t5, 0x8($s7)
    ctx->r13 = MEM_BU(ctx->r23, 0X8);
    // 0x8018DB60: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018DB64: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018DB68: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8018DB6C: bnel        $at, $zero, L_8018DB44
    if (ctx->r1 != 0) {
        // 0x8018DB70: addu        $t4, $s5, $v0
        ctx->r12 = ADD32(ctx->r21, ctx->r2);
            goto L_8018DB44;
    }
    goto skip_4;
    // 0x8018DB70: addu        $t4, $s5, $v0
    ctx->r12 = ADD32(ctx->r21, ctx->r2);
    skip_4:
L_8018DB74:
    // 0x8018DB74: addiu       $s1, $s1, 0x2FA9
    ctx->r17 = ADD32(ctx->r17, 0X2FA9);
    // 0x8018DB78: lui         $s5, 0x8019
    ctx->r21 = S32(0X8019 << 16);
    // 0x8018DB7C: addiu       $s5, $s5, 0x2FB0
    ctx->r21 = ADD32(ctx->r21, 0X2FB0);
    // 0x8018DB80: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x8018DB84: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8018DB88: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8018DB8C:
    // 0x8018DB8C: jal         0x8018D280
    // 0x8018DB90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    sc1PGameGetNextFreePlayerPort(rdram, ctx);
        goto after_5;
    // 0x8018DB90: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_5:
    // 0x8018DB94: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018DB98: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8018DB9C: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8018DBA0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8018DBA4: jal         0x8018D4EC
    // 0x8018DBA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sc1PGameSetupEnemyPlayer(rdram, ctx);
        goto after_6;
    // 0x8018DBA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8018DBAC: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x8018DBB0: sll         $s0, $s4, 3
    ctx->r16 = S32(ctx->r20 << 3);
    // 0x8018DBB4: subu        $s0, $s0, $s4
    ctx->r16 = SUB32(ctx->r16, ctx->r20);
    // 0x8018DBB8: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x8018DBBC: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8018DBC0: addu        $t7, $s5, $t9
    ctx->r15 = ADD32(ctx->r21, ctx->r25);
    // 0x8018DBC4: lbu         $t8, 0x0($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X0);
    // 0x8018DBC8: addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    // 0x8018DBCC: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8018DBD0: addu        $t6, $t4, $s0
    ctx->r14 = ADD32(ctx->r12, ctx->r16);
    // 0x8018DBD4: sb          $t8, 0x26($t6)
    MEM_B(0X26, ctx->r14) = ctx->r24;
    // 0x8018DBD8: lbu         $t5, 0x14($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0X14);
    // 0x8018DBDC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8018DBE0: bnel        $t5, $at, L_8018DC10
    if (ctx->r13 != ctx->r1) {
        // 0x8018DBE4: lw          $t6, 0x0($s6)
        ctx->r14 = MEM_W(ctx->r22, 0X0);
            goto L_8018DC10;
    }
    goto skip_5;
    // 0x8018DBE4: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    skip_5:
    // 0x8018DBE8: lw          $t9, 0x0($s6)
    ctx->r25 = MEM_W(ctx->r22, 0X0);
    // 0x8018DBEC: lbu         $t7, 0x15($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X15);
    // 0x8018DBF0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018DBF4: addu        $a0, $t9, $s0
    ctx->r4 = ADD32(ctx->r25, ctx->r16);
    // 0x8018DBF8: lbu         $t4, 0x26($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X26);
    // 0x8018DBFC: bnel        $t7, $t4, L_8018DC10
    if (ctx->r15 != ctx->r12) {
        // 0x8018DC00: lw          $t6, 0x0($s6)
        ctx->r14 = MEM_W(ctx->r22, 0X0);
            goto L_8018DC10;
    }
    goto skip_6;
    // 0x8018DC00: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    skip_6:
    // 0x8018DC04: b           L_8018DC18
    // 0x8018DC08: sb          $t8, 0x27($a0)
    MEM_B(0X27, ctx->r4) = ctx->r24;
        goto L_8018DC18;
    // 0x8018DC08: sb          $t8, 0x27($a0)
    MEM_B(0X27, ctx->r4) = ctx->r24;
    // 0x8018DC0C: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
L_8018DC10:
    // 0x8018DC10: addu        $t5, $t6, $s0
    ctx->r13 = ADD32(ctx->r14, ctx->r16);
    // 0x8018DC14: sb          $zero, 0x27($t5)
    MEM_B(0X27, ctx->r13) = 0;
L_8018DC18:
    // 0x8018DC18: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018DC1C: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8018DC20: addiu       $t7, $t7, 0x2FE0
    ctx->r15 = ADD32(ctx->r15, 0X2FE0);
    // 0x8018DC24: sll         $t9, $s4, 5
    ctx->r25 = S32(ctx->r20 << 5);
    // 0x8018DC28: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x8018DC2C: addiu       $t4, $s3, 0x25
    ctx->r12 = ADD32(ctx->r19, 0X25);
    // 0x8018DC30: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8018DC34: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DC38: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8018DC3C: lwc1        $f4, 0x2ECC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X2ECC);
    // 0x8018DC40: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018DC44: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018DC48: addiu       $t6, $v1, 0x1
    ctx->r14 = ADD32(ctx->r3, 0X1);
    // 0x8018DC4C: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    // 0x8018DC50: sb          $t6, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r14;
    // 0x8018DC54: bne         $s3, $s2, L_8018DB8C
    if (ctx->r19 != ctx->r18) {
        // 0x8018DC58: swc1        $f4, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
            goto L_8018DB8C;
    }
    // 0x8018DC58: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x8018DC5C: b           L_8018DFF4
    // 0x8018DC60: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
        goto L_8018DFF4;
    // 0x8018DC60: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
L_8018DC64:
    // 0x8018DC64: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018DC68: lui         $s3, 0x8019
    ctx->r19 = S32(0X8019 << 16);
    // 0x8018DC6C: addiu       $fp, $zero, 0xB
    ctx->r30 = ADD32(0, 0XB);
    // 0x8018DC70: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x8018DC74: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018DC78: addiu       $s3, $s3, 0x2FBC
    ctx->r19 = ADD32(ctx->r19, 0X2FBC);
    // 0x8018DC7C: addiu       $s0, $s0, 0x2FB0
    ctx->r16 = ADD32(ctx->r16, 0X2FB0);
L_8018DC80:
    // 0x8018DC80: jal         0x80018994
    // 0x8018DC84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syUtilsRandIntRange(rdram, ctx);
        goto after_7;
    // 0x8018DC84: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x8018DC88: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x8018DC8C: jal         0x8018D394
    // 0x8018DC90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    sc1PGameGetFighterKindsNum(rdram, ctx);
        goto after_8;
    // 0x8018DC90: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_8:
    // 0x8018DC94: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8018DC98: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8018DC9C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018DCA0: sllv        $t9, $t5, $v1
    ctx->r25 = S32(ctx->r13 << (ctx->r3 & 31));
    // 0x8018DCA4: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8018DCA8: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // 0x8018DCAC: or          $s2, $s2, $t9
    ctx->r18 = ctx->r18 | ctx->r25;
    // 0x8018DCB0: addiu       $t7, $v1, 0xE
    ctx->r15 = ADD32(ctx->r3, 0XE);
    // 0x8018DCB4: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x8018DCB8: sb          $t7, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r15;
    // 0x8018DCBC: bne         $at, $zero, L_8018DC80
    if (ctx->r1 != 0) {
        // 0x8018DCC0: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8018DC80;
    }
    // 0x8018DCC0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8018DCC4: lbu         $t4, 0x8($s7)
    ctx->r12 = MEM_BU(ctx->r23, 0X8);
    // 0x8018DCC8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018DCCC: addiu       $s3, $zero, 0xC
    ctx->r19 = ADD32(0, 0XC);
    // 0x8018DCD0: slti        $at, $t4, 0xD
    ctx->r1 = SIGNED(ctx->r12) < 0XD ? 1 : 0;
    // 0x8018DCD4: bne         $at, $zero, L_8018DD20
    if (ctx->r1 != 0) {
        // 0x8018DCD8: lui         $s1, 0x8019
        ctx->r17 = S32(0X8019 << 16);
            goto L_8018DD20;
    }
    // 0x8018DCD8: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018DCDC: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018DCE0: lui         $s5, 0x8019
    ctx->r21 = S32(0X8019 << 16);
    // 0x8018DCE4: addiu       $s5, $s5, 0x2FB0
    ctx->r21 = ADD32(ctx->r21, 0X2FB0);
    // 0x8018DCE8: addiu       $s0, $s0, 0x2FBC
    ctx->r16 = ADD32(ctx->r16, 0X2FBC);
    // 0x8018DCEC: addu        $t8, $s5, $v0
    ctx->r24 = ADD32(ctx->r21, ctx->r2);
L_8018DCF0:
    // 0x8018DCF0: lbu         $t6, 0x0($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X0);
    // 0x8018DCF4: bne         $v0, $fp, L_8018DD04
    if (ctx->r2 != ctx->r30) {
        // 0x8018DCF8: sb          $t6, 0x0($s0)
        MEM_B(0X0, ctx->r16) = ctx->r14;
            goto L_8018DD04;
    }
    // 0x8018DCF8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
    // 0x8018DCFC: b           L_8018DD08
    // 0x8018DD00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8018DD08;
    // 0x8018DD00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8018DD04:
    // 0x8018DD04: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8018DD08:
    // 0x8018DD08: lbu         $t5, 0x8($s7)
    ctx->r13 = MEM_BU(ctx->r23, 0X8);
    // 0x8018DD0C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018DD10: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018DD14: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8018DD18: bnel        $at, $zero, L_8018DCF0
    if (ctx->r1 != 0) {
        // 0x8018DD1C: addu        $t8, $s5, $v0
        ctx->r24 = ADD32(ctx->r21, ctx->r2);
            goto L_8018DCF0;
    }
    goto skip_7;
    // 0x8018DD1C: addu        $t8, $s5, $v0
    ctx->r24 = ADD32(ctx->r21, ctx->r2);
    skip_7:
L_8018DD20:
    // 0x8018DD20: addiu       $s1, $s1, 0x2FA9
    ctx->r17 = ADD32(ctx->r17, 0X2FA9);
    // 0x8018DD24: lui         $s5, 0x8019
    ctx->r21 = S32(0X8019 << 16);
    // 0x8018DD28: addiu       $s5, $s5, 0x2FB0
    ctx->r21 = ADD32(ctx->r21, 0X2FB0);
    // 0x8018DD2C: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x8018DD30: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8018DD34: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8018DD38:
    // 0x8018DD38: jal         0x8018D280
    // 0x8018DD3C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    sc1PGameGetNextFreePlayerPort(rdram, ctx);
        goto after_9;
    // 0x8018DD3C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_9:
    // 0x8018DD40: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018DD44: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8018DD48: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8018DD4C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8018DD50: jal         0x8018D4EC
    // 0x8018DD54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sc1PGameSetupEnemyPlayer(rdram, ctx);
        goto after_10;
    // 0x8018DD54: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_10:
    // 0x8018DD58: lbu         $t9, 0x0($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X0);
    // 0x8018DD5C: sll         $t6, $s4, 3
    ctx->r14 = S32(ctx->r20 << 3);
    // 0x8018DD60: subu        $t6, $t6, $s4
    ctx->r14 = SUB32(ctx->r14, ctx->r20);
    // 0x8018DD64: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x8018DD68: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018DD6C: addu        $t7, $s5, $t9
    ctx->r15 = ADD32(ctx->r21, ctx->r25);
    // 0x8018DD70: lbu         $t4, 0x0($t7)
    ctx->r12 = MEM_BU(ctx->r15, 0X0);
    // 0x8018DD74: addu        $t6, $t6, $s4
    ctx->r14 = ADD32(ctx->r14, ctx->r20);
    // 0x8018DD78: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8018DD7C: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x8018DD80: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018DD84: sb          $t4, 0x23($t5)
    MEM_B(0X23, ctx->r13) = ctx->r12;
    // 0x8018DD88: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8018DD8C: addiu       $t7, $t7, 0x2FE0
    ctx->r15 = ADD32(ctx->r15, 0X2FE0);
    // 0x8018DD90: sll         $t9, $s4, 5
    ctx->r25 = S32(ctx->r20 << 5);
    // 0x8018DD94: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x8018DD98: addiu       $t8, $s3, 0x25
    ctx->r24 = ADD32(ctx->r19, 0X25);
    // 0x8018DD9C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8018DDA0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DDA4: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8018DDA8: lwc1        $f6, 0x2ED0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X2ED0);
    // 0x8018DDAC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018DDB0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018DDB4: addiu       $t4, $v1, 0x1
    ctx->r12 = ADD32(ctx->r3, 0X1);
    // 0x8018DDB8: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x8018DDBC: sb          $t4, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r12;
    // 0x8018DDC0: bne         $s3, $s2, L_8018DD38
    if (ctx->r19 != ctx->r18) {
        // 0x8018DDC4: swc1        $f6, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
            goto L_8018DD38;
    }
    // 0x8018DDC4: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8018DDC8: b           L_8018DFF4
    // 0x8018DDCC: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
        goto L_8018DFF4;
    // 0x8018DDCC: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
L_8018DDD0:
    // 0x8018DDD0: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018DDD4: addiu       $s1, $s1, 0x2FA9
    ctx->r17 = ADD32(ctx->r17, 0X2FA9);
    // 0x8018DDD8: lui         $s5, 0x8019
    ctx->r21 = S32(0X8019 << 16);
    // 0x8018DDDC: lui         $s2, 0x8019
    ctx->r18 = S32(0X8019 << 16);
    // 0x8018DDE0: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x8018DDE4: addiu       $s2, $s2, 0x3060
    ctx->r18 = ADD32(ctx->r18, 0X3060);
    // 0x8018DDE8: addiu       $s5, $s5, 0x2800
    ctx->r21 = ADD32(ctx->r21, 0X2800);
    // 0x8018DDEC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8018DDF0:
    // 0x8018DDF0: jal         0x8018D280
    // 0x8018DDF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    sc1PGameGetNextFreePlayerPort(rdram, ctx);
        goto after_11;
    // 0x8018DDF4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_11:
    // 0x8018DDF8: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018DDFC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8018DE00: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8018DE04: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8018DE08: jal         0x8018D4EC
    // 0x8018DE0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sc1PGameSetupEnemyPlayer(rdram, ctx);
        goto after_12;
    // 0x8018DE0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x8018DE10: lbu         $t5, 0x14($fp)
    ctx->r13 = MEM_BU(ctx->r30, 0X14);
    // 0x8018DE14: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8018DE18: sll         $s0, $s4, 3
    ctx->r16 = S32(ctx->r20 << 3);
    // 0x8018DE1C: bne         $t5, $at, L_8018DE64
    if (ctx->r13 != ctx->r1) {
        // 0x8018DE20: subu        $s0, $s0, $s4
        ctx->r16 = SUB32(ctx->r16, ctx->r20);
            goto L_8018DE64;
    }
    // 0x8018DE20: subu        $s0, $s0, $s4
    ctx->r16 = SUB32(ctx->r16, ctx->r20);
    // 0x8018DE24: lw          $t7, 0x0($s6)
    ctx->r15 = MEM_W(ctx->r22, 0X0);
    // 0x8018DE28: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8018DE2C: addu        $s0, $s0, $s4
    ctx->r16 = ADD32(ctx->r16, ctx->r20);
    // 0x8018DE30: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x8018DE34: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8018DE38: lbu         $t6, 0x26($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X26);
    // 0x8018DE3C: lbu         $t9, 0x15($fp)
    ctx->r25 = MEM_BU(ctx->r30, 0X15);
    // 0x8018DE40: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8018DE44: bnel        $t9, $t6, L_8018DE68
    if (ctx->r25 != ctx->r14) {
        // 0x8018DE48: sll         $t7, $s4, 3
        ctx->r15 = S32(ctx->r20 << 3);
            goto L_8018DE68;
    }
    goto skip_8;
    // 0x8018DE48: sll         $t7, $s4, 3
    ctx->r15 = S32(ctx->r20 << 3);
    skip_8:
    // 0x8018DE4C: jal         0x800EC0EC
    // 0x8018DE50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_13;
    // 0x8018DE50: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_13:
    // 0x8018DE54: lw          $t4, 0x0($s6)
    ctx->r12 = MEM_W(ctx->r22, 0X0);
    // 0x8018DE58: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8018DE5C: b           L_8018DE84
    // 0x8018DE60: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
        goto L_8018DE84;
    // 0x8018DE60: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
L_8018DE64:
    // 0x8018DE64: sll         $t7, $s4, 3
    ctx->r15 = S32(ctx->r20 << 3);
L_8018DE68:
    // 0x8018DE68: subu        $t7, $t7, $s4
    ctx->r15 = SUB32(ctx->r15, ctx->r20);
    // 0x8018DE6C: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
    // 0x8018DE70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018DE74: addu        $t7, $t7, $s4
    ctx->r15 = ADD32(ctx->r15, ctx->r20);
    // 0x8018DE78: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8018DE7C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DE80: addu        $a0, $t5, $t7
    ctx->r4 = ADD32(ctx->r13, ctx->r15);
L_8018DE84:
    // 0x8018DE84: sb          $a1, 0x26($a0)
    MEM_B(0X26, ctx->r4) = ctx->r5;
    // 0x8018DE88: lbu         $v1, 0x0($s1)
    ctx->r3 = MEM_BU(ctx->r17, 0X0);
    // 0x8018DE8C: lui         $t6, 0x8019
    ctx->r14 = S32(0X8019 << 16);
    // 0x8018DE90: addiu       $t6, $t6, 0x2FE0
    ctx->r14 = ADD32(ctx->r14, 0X2FE0);
    // 0x8018DE94: sll         $t9, $s4, 5
    ctx->r25 = S32(ctx->r20 << 5);
    // 0x8018DE98: addu        $t4, $s5, $v1
    ctx->r12 = ADD32(ctx->r21, ctx->r3);
    // 0x8018DE9C: lbu         $t5, 0x0($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X0);
    // 0x8018DEA0: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x8018DEA4: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x8018DEA8: addiu       $t7, $s3, 0x25
    ctx->r15 = ADD32(ctx->r19, 0X25);
    // 0x8018DEAC: sw          $t8, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r24;
    // 0x8018DEB0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8018DEB4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DEB8: sw          $v1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r3;
    // 0x8018DEBC: sw          $t5, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r13;
    // 0x8018DEC0: lwc1        $f8, 0x2ED4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X2ED4);
    // 0x8018DEC4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8018DEC8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018DECC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8018DED0: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x8018DED4: sw          $t8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r24;
    // 0x8018DED8: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x8018DEDC: bne         $s3, $at, L_8018DDF0
    if (ctx->r19 != ctx->r1) {
        // 0x8018DEE0: swc1        $f8, 0x1C($v0)
        MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
            goto L_8018DDF0;
    }
    // 0x8018DEE0: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8018DEE4: b           L_8018DFF4
    // 0x8018DEE8: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
        goto L_8018DFF4;
    // 0x8018DEE8: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
L_8018DEEC:
    // 0x8018DEEC: lui         $s0, 0x8019
    ctx->r16 = S32(0X8019 << 16);
    // 0x8018DEF0: lui         $s3, 0x8019
    ctx->r19 = S32(0X8019 << 16);
    // 0x8018DEF4: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
    // 0x8018DEF8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8018DEFC: addiu       $s3, $s3, 0x2FB3
    ctx->r19 = ADD32(ctx->r19, 0X2FB3);
    // 0x8018DF00: addiu       $s0, $s0, 0x2FB0
    ctx->r16 = ADD32(ctx->r16, 0X2FB0);
L_8018DF04:
    // 0x8018DF04: jal         0x80018994
    // 0x8018DF08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    syUtilsRandIntRange(rdram, ctx);
        goto after_14;
    // 0x8018DF08: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_14:
    // 0x8018DF0C: andi        $a0, $s2, 0xFFFF
    ctx->r4 = ctx->r18 & 0XFFFF;
    // 0x8018DF10: jal         0x8018D394
    // 0x8018DF14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    sc1PGameGetFighterKindsNum(rdram, ctx);
        goto after_15;
    // 0x8018DF14: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_15:
    // 0x8018DF18: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x8018DF1C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8018DF20: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8018DF24: sllv        $t4, $t6, $v1
    ctx->r12 = S32(ctx->r14 << (ctx->r3 & 31));
    // 0x8018DF28: sltu        $at, $s0, $s3
    ctx->r1 = ctx->r16 < ctx->r19 ? 1 : 0;
    // 0x8018DF2C: sb          $v0, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r2;
    // 0x8018DF30: or          $s2, $s2, $t4
    ctx->r18 = ctx->r18 | ctx->r12;
    // 0x8018DF34: addiu       $t5, $v1, 0xE
    ctx->r13 = ADD32(ctx->r3, 0XE);
    // 0x8018DF38: andi        $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 & 0XFFFF;
    // 0x8018DF3C: sb          $t5, -0x1($s0)
    MEM_B(-0X1, ctx->r16) = ctx->r13;
    // 0x8018DF40: bne         $at, $zero, L_8018DF04
    if (ctx->r1 != 0) {
        // 0x8018DF44: addiu       $s1, $s1, -0x1
        ctx->r17 = ADD32(ctx->r17, -0X1);
            goto L_8018DF04;
    }
    // 0x8018DF44: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8018DF48: lui         $s1, 0x8019
    ctx->r17 = S32(0X8019 << 16);
    // 0x8018DF4C: addiu       $s1, $s1, 0x2FA9
    ctx->r17 = ADD32(ctx->r17, 0X2FA9);
    // 0x8018DF50: lui         $s5, 0x8019
    ctx->r21 = S32(0X8019 << 16);
    // 0x8018DF54: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x8018DF58: addiu       $s5, $s5, 0x2FB0
    ctx->r21 = ADD32(ctx->r21, 0X2FB0);
    // 0x8018DF5C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8018DF60: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8018DF64:
    // 0x8018DF64: jal         0x8018D280
    // 0x8018DF68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    sc1PGameGetNextFreePlayerPort(rdram, ctx);
        goto after_16;
    // 0x8018DF68: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_16:
    // 0x8018DF6C: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8018DF70: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8018DF74: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x8018DF78: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8018DF7C: jal         0x8018D4EC
    // 0x8018DF80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    sc1PGameSetupEnemyPlayer(rdram, ctx);
        goto after_17;
    // 0x8018DF80: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_17:
    // 0x8018DF84: lbu         $t7, 0x0($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X0);
    // 0x8018DF88: sll         $t4, $s4, 3
    ctx->r12 = S32(ctx->r20 << 3);
    // 0x8018DF8C: subu        $t4, $t4, $s4
    ctx->r12 = SUB32(ctx->r12, ctx->r20);
    // 0x8018DF90: lw          $t6, 0x0($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X0);
    // 0x8018DF94: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018DF98: addu        $t8, $s5, $t7
    ctx->r24 = ADD32(ctx->r21, ctx->r15);
    // 0x8018DF9C: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x8018DFA0: addu        $t4, $t4, $s4
    ctx->r12 = ADD32(ctx->r12, ctx->r20);
    // 0x8018DFA4: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x8018DFA8: addu        $t5, $t6, $t4
    ctx->r13 = ADD32(ctx->r14, ctx->r12);
    // 0x8018DFAC: sb          $t9, 0x23($t5)
    MEM_B(0X23, ctx->r13) = ctx->r25;
    // 0x8018DFB0: lbu         $t4, 0x0($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X0);
    // 0x8018DFB4: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x8018DFB8: addiu       $t8, $t8, 0x2FE0
    ctx->r24 = ADD32(ctx->r24, 0X2FE0);
    // 0x8018DFBC: sll         $t7, $s4, 5
    ctx->r15 = S32(ctx->r20 << 5);
    // 0x8018DFC0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8018DFC4: addiu       $t6, $s3, 0x25
    ctx->r14 = ADD32(ctx->r19, 0X25);
    // 0x8018DFC8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8018DFCC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8018DFD0: addiu       $t9, $t4, 0x1
    ctx->r25 = ADD32(ctx->r12, 0X1);
    // 0x8018DFD4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8018DFD8: sw          $v1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r3;
    // 0x8018DFDC: sw          $v1, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r3;
    // 0x8018DFE0: bne         $s3, $s2, L_8018DF64
    if (ctx->r19 != ctx->r18) {
        // 0x8018DFE4: sb          $t9, 0x0($s1)
        MEM_B(0X0, ctx->r17) = ctx->r25;
            goto L_8018DF64;
    }
    // 0x8018DFE4: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
    // 0x8018DFE8: b           L_8018DFF4
    // 0x8018DFEC: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
        goto L_8018DFF4;
    // 0x8018DFEC: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
L_8018DFF0:
    // 0x8018DFF0: lw          $t5, 0x0($s6)
    ctx->r13 = MEM_W(ctx->r22, 0X0);
L_8018DFF4:
    // 0x8018DFF4: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018DFF8: lui         $a2, 0x8019
    ctx->r6 = S32(0X8019 << 16);
    // 0x8018DFFC: sb          $zero, 0x5($t5)
    MEM_B(0X5, ctx->r13) = 0;
    // 0x8018E000: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x8018E004: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018E008: addiu       $a0, $a0, 0x3798
    ctx->r4 = ADD32(ctx->r4, 0X3798);
    // 0x8018E00C: lbu         $t7, 0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X5);
    // 0x8018E010: addiu       $a2, $a2, 0x37A0
    ctx->r6 = ADD32(ctx->r6, 0X37A0);
    // 0x8018E014: lui         $a3, 0x8019
    ctx->r7 = S32(0X8019 << 16);
    // 0x8018E018: sb          $t7, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r15;
    // 0x8018E01C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
L_8018E020:
    // 0x8018E020: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8018E024: addu        $t8, $v0, $v1
    ctx->r24 = ADD32(ctx->r2, ctx->r3);
    // 0x8018E028: lbu         $a1, 0x22($t8)
    ctx->r5 = MEM_BU(ctx->r24, 0X22);
    // 0x8018E02C: addiu       $v1, $v1, 0x74
    ctx->r3 = ADD32(ctx->r3, 0X74);
    // 0x8018E030: beql        $a1, $zero, L_8018E04C
    if (ctx->r5 == 0) {
        // 0x8018E034: lbu         $t6, 0x4($v0)
        ctx->r14 = MEM_BU(ctx->r2, 0X4);
            goto L_8018E04C;
    }
    goto skip_9;
    // 0x8018E034: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
    skip_9:
    // 0x8018E038: beql        $a1, $at, L_8018E05C
    if (ctx->r5 == ctx->r1) {
        // 0x8018E03C: lbu         $t9, 0x5($v0)
        ctx->r25 = MEM_BU(ctx->r2, 0X5);
            goto L_8018E05C;
    }
    goto skip_10;
    // 0x8018E03C: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
    skip_10:
    // 0x8018E040: b           L_8018E068
    // 0x8018E044: slti        $at, $v1, 0x1D0
    ctx->r1 = SIGNED(ctx->r3) < 0X1D0 ? 1 : 0;
        goto L_8018E068;
    // 0x8018E044: slti        $at, $v1, 0x1D0
    ctx->r1 = SIGNED(ctx->r3) < 0X1D0 ? 1 : 0;
    // 0x8018E048: lbu         $t6, 0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X4);
L_8018E04C:
    // 0x8018E04C: addiu       $t4, $t6, 0x1
    ctx->r12 = ADD32(ctx->r14, 0X1);
    // 0x8018E050: b           L_8018E064
    // 0x8018E054: sb          $t4, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r12;
        goto L_8018E064;
    // 0x8018E054: sb          $t4, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r12;
    // 0x8018E058: lbu         $t9, 0x5($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X5);
L_8018E05C:
    // 0x8018E05C: addiu       $t5, $t9, 0x1
    ctx->r13 = ADD32(ctx->r25, 0X1);
    // 0x8018E060: sb          $t5, 0x5($v0)
    MEM_B(0X5, ctx->r2) = ctx->r13;
L_8018E064:
    // 0x8018E064: slti        $at, $v1, 0x1D0
    ctx->r1 = SIGNED(ctx->r3) < 0X1D0 ? 1 : 0;
L_8018E068:
    // 0x8018E068: bnel        $at, $zero, L_8018E020
    if (ctx->r1 != 0) {
        // 0x8018E06C: lw          $v0, 0x0($s6)
        ctx->r2 = MEM_W(ctx->r22, 0X0);
            goto L_8018E020;
    }
    goto skip_11;
    // 0x8018E06C: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    skip_11:
    // 0x8018E070: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E074: sb          $zero, 0x36A8($at)
    MEM_B(0X36A8, ctx->r1) = 0;
    // 0x8018E078: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E07C: sb          $zero, 0x36A9($at)
    MEM_B(0X36A9, ctx->r1) = 0;
    // 0x8018E080: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E084: sb          $zero, 0x36AA($at)
    MEM_B(0X36AA, ctx->r1) = 0;
    // 0x8018E088: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E08C: sb          $zero, 0x36AB($at)
    MEM_B(0X36AB, ctx->r1) = 0;
    // 0x8018E090: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E094: sb          $zero, 0x36AC($at)
    MEM_B(0X36AC, ctx->r1) = 0;
    // 0x8018E098: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E09C: sb          $zero, 0x36AD($at)
    MEM_B(0X36AD, ctx->r1) = 0;
    // 0x8018E0A0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E0A4: sw          $zero, 0x33C4($at)
    MEM_W(0X33C4, ctx->r1) = 0;
    // 0x8018E0A8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E0AC: sw          $zero, 0x33C0($at)
    MEM_W(0X33C0, ctx->r1) = 0;
    // 0x8018E0B0: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E0B4: sw          $zero, 0x36A0($at)
    MEM_W(0X36A0, ctx->r1) = 0;
    // 0x8018E0B8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E0BC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8018E0C0: sw          $t7, 0x33C8($at)
    MEM_W(0X33C8, ctx->r1) = ctx->r15;
    // 0x8018E0C4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E0C8: sw          $zero, 0x33CC($at)
    MEM_W(0X33CC, ctx->r1) = 0;
    // 0x8018E0CC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018E0D0: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018E0D4: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E0D8: sw          $zero, 0x36A4($at)
    MEM_W(0X36A4, ctx->r1) = 0;
    // 0x8018E0DC: addiu       $v0, $v0, 0x36B0
    ctx->r2 = ADD32(ctx->r2, 0X36B0);
    // 0x8018E0E0: addiu       $v1, $v1, 0x37B0
    ctx->r3 = ADD32(ctx->r3, 0X37B0);
L_8018E0E4:
    // 0x8018E0E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8018E0E8: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8018E0EC: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8018E0F0: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8018E0F4: bne         $at, $zero, L_8018E0E4
    if (ctx->r1 != 0) {
        // 0x8018E0F8: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8018E0E4;
    }
    // 0x8018E0F8: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8018E0FC: lui         $v1, 0x8019
    ctx->r3 = S32(0X8019 << 16);
    // 0x8018E100: lui         $a0, 0x8019
    ctx->r4 = S32(0X8019 << 16);
    // 0x8018E104: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018E108: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E10C: lui         $t0, 0x8019
    ctx->r8 = S32(0X8019 << 16);
    // 0x8018E110: addiu       $t0, $t0, 0x37B0
    ctx->r8 = ADD32(ctx->r8, 0X37B0);
    // 0x8018E114: addiu       $v0, $v0, 0x37A8
    ctx->r2 = ADD32(ctx->r2, 0X37A8);
    // 0x8018E118: addiu       $a1, $a1, 0x38A0
    ctx->r5 = ADD32(ctx->r5, 0X38A0);
    // 0x8018E11C: addiu       $a0, $a0, 0x3798
    ctx->r4 = ADD32(ctx->r4, 0X3798);
    // 0x8018E120: addiu       $v1, $v1, 0x3898
    ctx->r3 = ADD32(ctx->r3, 0X3898);
    // 0x8018E124: addiu       $a3, $a3, 0x38A8
    ctx->r7 = ADD32(ctx->r7, 0X38A8);
L_8018E128:
    // 0x8018E128: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8018E12C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8018E130: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8018E134: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8018E138: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8018E13C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8018E140: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8018E144: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x8018E148: sw          $zero, -0x4($a1)
    MEM_W(-0X4, ctx->r5) = 0;
    // 0x8018E14C: sw          $zero, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = 0;
    // 0x8018E150: sw          $zero, -0x4($a3)
    MEM_W(-0X4, ctx->r7) = 0;
    // 0x8018E154: bne         $v0, $t0, L_8018E128
    if (ctx->r2 != ctx->r8) {
        // 0x8018E158: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8018E128;
    }
    // 0x8018E158: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8018E15C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018E160: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018E164: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E168: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8018E16C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8018E170: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8018E174: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8018E178: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8018E17C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8018E180: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8018E184: jr          $ra
    // 0x8018E188: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8018E188: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void efManagerMarioEntryDokanMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801036EC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801036F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801036F4: beq         $a1, $zero, L_80103710
    if (ctx->r5 == 0) {
        // 0x801036F8: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80103710;
    }
    // 0x801036F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x801036FC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80103700: beq         $a1, $at, L_80103724
    if (ctx->r5 == ctx->r1) {
        // 0x80103704: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_80103724;
    }
    // 0x80103704: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80103708: b           L_80103730
    // 0x8010370C: nop

        goto L_80103730;
    // 0x8010370C: nop

L_80103710:
    // 0x80103710: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80103714: addiu       $t6, $t6, 0xE40
    ctx->r14 = ADD32(ctx->r14, 0XE40);
    // 0x80103718: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010371C: b           L_80103730
    // 0x80103720: sw          $t6, -0x1930($at)
    MEM_W(-0X1930, ctx->r1) = ctx->r14;
        goto L_80103730;
    // 0x80103720: sw          $t6, -0x1930($at)
    MEM_W(-0X1930, ctx->r1) = ctx->r14;
L_80103724:
    // 0x80103724: addiu       $t7, $t7, 0xF80
    ctx->r15 = ADD32(ctx->r15, 0XF80);
    // 0x80103728: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010372C: sw          $t7, -0x1930($at)
    MEM_W(-0X1930, ctx->r1) = ctx->r15;
L_80103730:
    // 0x80103730: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80103734: jal         0x800FDAFC
    // 0x80103738: addiu       $a0, $a0, -0x1934
    ctx->r4 = ADD32(ctx->r4, -0X1934);
    efManagerMakeEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80103738: addiu       $a0, $a0, -0x1934
    ctx->r4 = ADD32(ctx->r4, -0X1934);
    after_0:
    // 0x8010373C: bne         $v0, $zero, L_8010374C
    if (ctx->r2 != 0) {
        // 0x80103740: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8010374C;
    }
    // 0x80103740: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80103744: b           L_80103770
    // 0x80103748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80103770;
    // 0x80103748: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8010374C:
    // 0x8010374C: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x80103750: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80103754: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80103758: lw          $t0, 0x0($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X0);
    // 0x8010375C: sw          $t0, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->r8;
    // 0x80103760: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x80103764: sw          $t9, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->r25;
    // 0x80103768: lw          $t0, 0x8($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X8);
    // 0x8010376C: sw          $t0, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->r8;
L_80103770:
    // 0x80103770: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80103774: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80103778: jr          $ra
    // 0x8010377C: nop

    return;
    // 0x8010377C: nop

;}
RECOMP_FUNC void mnVSItemSwitchMakeCursor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132178: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8013217C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132180: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80132184: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132188: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013218C: addiu       $a2, $zero, 0x5
    ctx->r6 = ADD32(0, 0X5);
    // 0x80132190: jal         0x80009968
    // 0x80132194: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132194: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132198: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013219C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x801321A0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x801321A4: sw          $v0, 0x3460($at)
    MEM_W(0X3460, ctx->r1) = ctx->r2;
    // 0x801321A8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x801321AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801321B0: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x801321B4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x801321B8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x801321BC: jal         0x80009DF4
    // 0x801321C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x801321C0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x801321C4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801321C8: lw          $t7, 0x3530($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3530);
    // 0x801321CC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x801321D0: addiu       $t8, $t8, 0x63A8
    ctx->r24 = ADD32(ctx->r24, 0X63A8);
    // 0x801321D4: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x801321D8: jal         0x800CCFDC
    // 0x801321DC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_2;
    // 0x801321DC: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x801321E0: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x801321E4: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x801321E8: addiu       $t4, $zero, 0xDE
    ctx->r12 = ADD32(0, 0XDE);
    // 0x801321EC: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x801321F0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801321F4: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x801321F8: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x801321FC: sb          $t3, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r11;
    // 0x80132200: sb          $t4, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r12;
    // 0x80132204: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80132208: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8013220C: jal         0x8013212C
    // 0x80132210: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mnVSItemSwitchSetCursorPosition(rdram, ctx);
        goto after_3;
    // 0x80132210: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_3:
    // 0x80132214: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132218: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8013221C: jr          $ra
    // 0x80132220: nop

    return;
    // 0x80132220: nop

;}
RECOMP_FUNC void mnModeSelectMakeDecalsCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132438: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8013243C: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132440: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132444: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132448: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x8013244C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132450: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80132454: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132458: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8013245C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132460: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132464: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132468: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8013246C: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132470: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132474: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132478: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8013247C: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132480: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132484: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132488: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8013248C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132490: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132494: jal         0x8000B93C
    // 0x80132498: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132498: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8013249C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801324A0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801324A4: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801324A8: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801324AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801324B0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801324B4: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801324B8: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801324BC: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801324C0: jal         0x80007080
    // 0x801324C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801324C4: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801324C8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x801324CC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x801324D0: jr          $ra
    // 0x801324D4: nop

    return;
    // 0x801324D4: nop

;}
RECOMP_FUNC void func_ovl24_801348EC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801348EC: jr          $ra
    // 0x801348F0: nop

    return;
    // 0x801348F0: nop

;}
RECOMP_FUNC void ifCommonItemArrowProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80111D64: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80111D68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80111D6C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80111D70: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80111D74: lh          $t8, 0x2CE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2CE);
    // 0x80111D78: bgezl       $t8, L_80111EB4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80111D7C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80111EB4;
    }
    goto skip_0;
    // 0x80111D7C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80111D80: lbu         $t9, 0x34C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X34C);
    // 0x80111D84: slti        $at, $t9, 0xF
    ctx->r1 = SIGNED(ctx->r25) < 0XF ? 1 : 0;
    // 0x80111D88: bnel        $at, $zero, L_80111EB4
    if (ctx->r1 != 0) {
        // 0x80111D8C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80111EB4;
    }
    goto skip_1;
    // 0x80111D8C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x80111D90: lw          $t0, 0x4($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X4);
    // 0x80111D94: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80111D98: addiu       $a2, $sp, 0x24
    ctx->r6 = ADD32(ctx->r29, 0X24);
    // 0x80111D9C: lw          $t1, 0x74($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X74);
    // 0x80111DA0: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80111DA4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80111DA8: lw          $t3, 0x1C($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X1C);
    // 0x80111DAC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80111DB0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80111DB4: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x80111DB8: lw          $t2, 0x20($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X20);
    // 0x80111DBC: addiu       $t5, $sp, 0x30
    ctx->r13 = ADD32(ctx->r29, 0X30);
    // 0x80111DC0: addiu       $a1, $a1, 0x1470
    ctx->r5 = ADD32(ctx->r5, 0X1470);
    // 0x80111DC4: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x80111DC8: lw          $t3, 0x24($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X24);
    // 0x80111DCC: addiu       $a3, $sp, 0x34
    ctx->r7 = ADD32(ctx->r29, 0X34);
    // 0x80111DD0: sw          $t3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r11;
    // 0x80111DD4: lwc1        $f4, 0x70($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X70);
    // 0x80111DD8: lwc1        $f10, 0x28($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80111DDC: lw          $t4, 0x1460($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1460);
    // 0x80111DE0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80111DE4: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x80111DE8: swc1        $f16, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f16.u32l;
    // 0x80111DEC: lw          $a0, 0x74($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X74);
    // 0x80111DF0: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80111DF4: jal         0x800EB924
    // 0x80111DF8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    func_ovl2_800EB924(rdram, ctx);
        goto after_0;
    // 0x80111DF8: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    after_0:
    // 0x80111DFC: lwc1        $f12, 0x34($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80111E00: jal         0x8010E5F4
    // 0x80111E04: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    gmCameraCheckTargetInBounds(rdram, ctx);
        goto after_1;
    // 0x80111E04: lwc1        $f14, 0x30($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X30);
    after_1:
    // 0x80111E08: beq         $v0, $zero, L_80111EB0
    if (ctx->r2 == 0) {
        // 0x80111E0C: lw          $v1, 0x38($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X38);
            goto L_80111EB0;
    }
    // 0x80111E0C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x80111E10: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x80111E14: addiu       $v0, $v0, 0x14B0
    ctx->r2 = ADD32(ctx->r2, 0X14B0);
    // 0x80111E18: lw          $t7, 0x30($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X30);
    // 0x80111E1C: lh          $t8, 0x14($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X14);
    // 0x80111E20: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80111E24: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80111E28: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80111E2C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80111E30: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80111E34: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80111E38: lh          $t1, 0x16($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X16);
    // 0x80111E3C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80111E40: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80111E44: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80111E48: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80111E4C: trunc.w.s   $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = TRUNC_W_S(ctx->f6.fl);
    // 0x80111E50: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80111E54: nop

    // 0x80111E58: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x80111E5C: nop

    // 0x80111E60: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80111E64: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80111E68: swc1        $f18, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f18.u32l;
    // 0x80111E6C: lw          $t0, 0x34($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X34);
    // 0x80111E70: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80111E74: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80111E78: mtc1        $t0, $f10
    ctx->f10.u32l = ctx->r8;
    // 0x80111E7C: nop

    // 0x80111E80: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80111E84: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80111E88: sub.s       $f10, $f8, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80111E8C: trunc.w.s   $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x80111E90: mfc1        $t3, $f4
    ctx->r11 = (int32_t)ctx->f4.u32l;
    // 0x80111E94: nop

    // 0x80111E98: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80111E9C: nop

    // 0x80111EA0: cvt.s.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80111EA4: swc1        $f16, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f16.u32l;
    // 0x80111EA8: jal         0x800CCF00
    // 0x80111EAC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_2;
    // 0x80111EAC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
L_80111EB0:
    // 0x80111EB0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80111EB4:
    // 0x80111EB4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80111EB8: jr          $ra
    // 0x80111EBC: nop

    return;
    // 0x80111EBC: nop

;}
RECOMP_FUNC void ftCommonHeavyGetProcDamage(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80145D28: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80145D2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80145D30: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80145D34: lw          $t6, 0x84C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X84C);
    // 0x80145D38: beql        $t6, $zero, L_80145D64
    if (ctx->r14 == 0) {
        // 0x80145D3C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80145D64;
    }
    goto skip_0;
    // 0x80145D3C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80145D40: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80145D44: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80145D48: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    // 0x80145D4C: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x80145D50: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x80145D54: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80145D58: jal         0x80172AEC
    // 0x80145D5C: lw          $a0, 0x84C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84C);
    itMainSetFighterDrop(rdram, ctx);
        goto after_0;
    // 0x80145D5C: lw          $a0, 0x84C($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X84C);
    after_0:
    // 0x80145D60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80145D64:
    // 0x80145D64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80145D68: jr          $ra
    // 0x80145D6C: nop

    return;
    // 0x80145D6C: nop

;}
RECOMP_FUNC void ftKirbySpecialNSetCatchParams(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161E3C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80161E40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80161E44: lw          $t6, 0x14C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14C);
    // 0x80161E48: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80161E4C: addiu       $a2, $a2, 0x3430
    ctx->r6 = ADD32(ctx->r6, 0X3430);
    // 0x80161E50: bne         $t6, $zero, L_80161E78
    if (ctx->r14 != 0) {
        // 0x80161E54: addiu       $a1, $zero, 0x2
        ctx->r5 = ADD32(0, 0X2);
            goto L_80161E78;
    }
    // 0x80161E54: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x80161E58: lui         $a2, 0x8016
    ctx->r6 = S32(0X8016 << 16);
    // 0x80161E5C: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x80161E60: addiu       $a3, $a3, -0x4698
    ctx->r7 = ADD32(ctx->r7, -0X4698);
    // 0x80161E64: addiu       $a2, $a2, 0x31E4
    ctx->r6 = ADD32(ctx->r6, 0X31E4);
    // 0x80161E68: jal         0x800E80A4
    // 0x80161E6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    ftParamSetCatchParams(rdram, ctx);
        goto after_0;
    // 0x80161E6C: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_0:
    // 0x80161E70: b           L_80161E88
    // 0x80161E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80161E88;
    // 0x80161E74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80161E78:
    // 0x80161E78: lui         $a3, 0x8015
    ctx->r7 = S32(0X8015 << 16);
    // 0x80161E7C: jal         0x800E80A4
    // 0x80161E80: addiu       $a3, $a3, -0x4698
    ctx->r7 = ADD32(ctx->r7, -0X4698);
    ftParamSetCatchParams(rdram, ctx);
        goto after_1;
    // 0x80161E80: addiu       $a3, $a3, -0x4698
    ctx->r7 = ADD32(ctx->r7, -0X4698);
    after_1:
    // 0x80161E84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80161E88:
    // 0x80161E88: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80161E8C: jr          $ra
    // 0x80161E90: nop

    return;
    // 0x80161E90: nop

;}
RECOMP_FUNC void func_80020EA0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020EA0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80020EA4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020EA8: sltu        $at, $a1, $at
    ctx->r1 = ctx->r5 < ctx->r1 ? 1 : 0;
    // 0x80020EAC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020EB0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80020EB4: bne         $at, $zero, L_80020EC0
    if (ctx->r1 != 0) {
        // 0x80020EB8: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80020EC0;
    }
    // 0x80020EB8: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80020EBC: addiu       $a2, $zero, 0x7FFF
    ctx->r6 = ADD32(0, 0X7FFF);
L_80020EC0:
    // 0x80020EC0: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x80020EC4: lw          $t6, -0x26AC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X26AC);
    // 0x80020EC8: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80020ECC: srl         $a1, $a2, 8
    ctx->r5 = S32(U32(ctx->r6) >> 8);
    // 0x80020ED0: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80020ED4: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x80020ED8: beql        $a0, $zero, L_80020EEC
    if (ctx->r4 == 0) {
        // 0x80020EDC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80020EEC;
    }
    goto skip_0;
    // 0x80020EDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80020EE0: jal         0x80026174
    // 0x80020EE4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    func_80026174_26D74(rdram, ctx);
        goto after_0;
    // 0x80020EE4: andi        $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 & 0XFF;
    after_0:
    // 0x80020EE8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80020EEC:
    // 0x80020EEC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020EF0: jr          $ra
    // 0x80020EF4: nop

    return;
    // 0x80020EF4: nop

;}
RECOMP_FUNC void unref_80004928(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004928: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x8000492C: jr          $ra
    // 0x80004930: sw          $a0, 0x6620($at)
    MEM_W(0X6620, ctx->r1) = ctx->r4;
    return;
    // 0x80004930: sw          $a0, 0x6620($at)
    MEM_W(0X6620, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void func_ovl8_803863A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803863A4: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x803863A8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x803863AC: sw          $a0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r4;
    // 0x803863B0: beq         $a2, $zero, L_803863D4
    if (ctx->r6 == 0) {
        // 0x803863B4: sw          $a1, 0x13C($sp)
        MEM_W(0X13C, ctx->r29) = ctx->r5;
            goto L_803863D4;
    }
    // 0x803863B4: sw          $a1, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r5;
    // 0x803863B8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x803863BC: jal         0x80386BE0
    // 0x803863C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    func_ovl8_80386BE0(rdram, ctx);
        goto after_0;
    // 0x803863C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x803863C4: jal         0x8037E7A8
    // 0x803863C8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    func_ovl8_8037E7A8(rdram, ctx);
        goto after_1;
    // 0x803863C8: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x803863CC: b           L_803863D8
    // 0x803863D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_803863D8;
    // 0x803863D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_803863D4:
    // 0x803863D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_803863D8:
    // 0x803863D8: lw          $t6, 0x138($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X138);
    // 0x803863DC: addiu       $t7, $zero, 0x18
    ctx->r15 = ADD32(0, 0X18);
    // 0x803863E0: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x803863E4: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x803863E8: slti        $at, $v0, 0x119
    ctx->r1 = SIGNED(ctx->r2) < 0X119 ? 1 : 0;
    // 0x803863EC: bne         $at, $zero, L_803863F8
    if (ctx->r1 != 0) {
        // 0x803863F0: sw          $v0, 0x12C($sp)
        MEM_W(0X12C, ctx->r29) = ctx->r2;
            goto L_803863F8;
    }
    // 0x803863F0: sw          $v0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->r2;
    // 0x803863F4: addiu       $v0, $zero, 0x118
    ctx->r2 = ADD32(0, 0X118);
L_803863F8:
    // 0x803863F8: sw          $t7, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r15;
    // 0x803863FC: addiu       $a1, $sp, 0x12C
    ctx->r5 = ADD32(ctx->r29, 0X12C);
    // 0x80386400: addiu       $a2, $sp, 0x128
    ctx->r6 = ADD32(ctx->r29, 0X128);
    // 0x80386404: jal         0x8037B85C
    // 0x80386408: sw          $v0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r2;
    func_ovl8_8037B85C(rdram, ctx);
        goto after_2;
    // 0x80386408: sw          $v0, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r2;
    after_2:
    // 0x8038640C: lw          $t8, 0x128($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X128);
    // 0x80386410: lw          $a3, 0x12C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X12C);
    // 0x80386414: lw          $a0, 0x134($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X134);
    // 0x80386418: addiu       $a1, $zero, 0x18
    ctx->r5 = ADD32(0, 0X18);
    // 0x8038641C: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80386420: jal         0x8037ACAC
    // 0x80386424: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    func_ovl8_8037ACAC(rdram, ctx);
        goto after_3;
    // 0x80386424: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_3:
    // 0x80386428: lw          $t0, 0x134($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X134);
    // 0x8038642C: lui         $a2, 0x8039
    ctx->r6 = S32(0X8039 << 16);
    // 0x80386430: addiu       $a2, $a2, -0x1E20
    ctx->r6 = ADD32(ctx->r6, -0X1E20);
    // 0x80386434: lui         $v1, 0x8039
    ctx->r3 = S32(0X8039 << 16);
    // 0x80386438: addiu       $v1, $v1, 0x3C4
    ctx->r3 = ADD32(ctx->r3, 0X3C4);
    // 0x8038643C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80386440: sw          $v0, 0x24($a2)
    MEM_W(0X24, ctx->r6) = ctx->r2;
    // 0x80386444: addiu       $t1, $zero, 0x18
    ctx->r9 = ADD32(0, 0X18);
    // 0x80386448: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038644C: sh          $t0, 0x4($a2)
    MEM_H(0X4, ctx->r6) = ctx->r8;
    // 0x80386450: sh          $t1, -0x1E1A($at)
    MEM_H(-0X1E1A, ctx->r1) = ctx->r9;
    // 0x80386454: lw          $a0, 0x13C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X13C);
    // 0x80386458: jal         0x80385F44
    // 0x8038645C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    func_ovl8_80385F44(rdram, ctx);
        goto after_4;
    // 0x8038645C: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_4:
    // 0x80386460: lui         $a0, 0x8039
    ctx->r4 = S32(0X8039 << 16);
    // 0x80386464: addiu       $a0, $a0, -0x1DF8
    ctx->r4 = ADD32(ctx->r4, -0X1DF8);
    // 0x80386468: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8038646C: jal         0x80377108
    // 0x80386470: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    func_ovl8_80377108(rdram, ctx);
        goto after_5;
    // 0x80386470: addiu       $a2, $zero, 0xC8
    ctx->r6 = ADD32(0, 0XC8);
    after_5:
    // 0x80386474: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80386478: lui         $at, 0x8039
    ctx->r1 = S32(0X8039 << 16);
    // 0x8038647C: sw          $zero, 0x3C8($at)
    MEM_W(0X3C8, ctx->r1) = 0;
    // 0x80386480: jr          $ra
    // 0x80386484: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    return;
    // 0x80386484: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
;}
RECOMP_FUNC void ifCommonBattleInterfaceResumeGObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8011366C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80113670: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80113674: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80113678: jal         0x8000B2B8
    // 0x8011367C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    gcResumeGObjProcessAll(rdram, ctx);
        goto after_0;
    // 0x8011367C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80113680: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80113684: addiu       $at, $zero, -0x41
    ctx->r1 = ADD32(0, -0X41);
    // 0x80113688: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x8011368C: and         $t7, $t6, $at
    ctx->r15 = ctx->r14 & ctx->r1;
    // 0x80113690: sw          $t7, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r15;
    // 0x80113694: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80113698: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8011369C: jr          $ra
    // 0x801136A0: nop

    return;
    // 0x801136A0: nop

;}
RECOMP_FUNC void ftParamStopLoopSFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E81E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800E81E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800E81EC: lw          $a1, 0xA20($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XA20);
    // 0x800E81F0: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800E81F4: beql        $a1, $zero, L_800E8228
    if (ctx->r5 == 0) {
        // 0x800E81F8: sw          $zero, 0xA20($a2)
        MEM_W(0XA20, ctx->r6) = 0;
            goto L_800E8228;
    }
    goto skip_0;
    // 0x800E81F8: sw          $zero, 0xA20($a2)
    MEM_W(0XA20, ctx->r6) = 0;
    skip_0:
    // 0x800E81FC: lhu         $v0, 0x26($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0X26);
    // 0x800E8200: beql        $v0, $zero, L_800E8228
    if (ctx->r2 == 0) {
        // 0x800E8204: sw          $zero, 0xA20($a2)
        MEM_W(0XA20, ctx->r6) = 0;
            goto L_800E8228;
    }
    goto skip_1;
    // 0x800E8204: sw          $zero, 0xA20($a2)
    MEM_W(0XA20, ctx->r6) = 0;
    skip_1:
    // 0x800E8208: lhu         $t6, 0xA24($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0XA24);
    // 0x800E820C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800E8210: bnel        $t6, $v0, L_800E8228
    if (ctx->r14 != ctx->r2) {
        // 0x800E8214: sw          $zero, 0xA20($a2)
        MEM_W(0XA20, ctx->r6) = 0;
            goto L_800E8228;
    }
    goto skip_2;
    // 0x800E8214: sw          $zero, 0xA20($a2)
    MEM_W(0XA20, ctx->r6) = 0;
    skip_2:
    // 0x800E8218: jal         0x80026738
    // 0x800E821C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    func_80026738_27338(rdram, ctx);
        goto after_0;
    // 0x800E821C: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x800E8220: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x800E8224: sw          $zero, 0xA20($a2)
    MEM_W(0XA20, ctx->r6) = 0;
L_800E8228:
    // 0x800E8228: sh          $zero, 0xA24($a2)
    MEM_H(0XA24, ctx->r6) = 0;
    // 0x800E822C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800E8230: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800E8234: jr          $ra
    // 0x800E8238: nop

    return;
    // 0x800E8238: nop

;}
RECOMP_FUNC void lbBackupClearPrize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D4C0C: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x800D4C10: addiu       $v0, $v0, 0x44E0
    ctx->r2 = ADD32(ctx->r2, 0X44E0);
    // 0x800D4C14: lbu         $t6, 0x457($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X457);
    // 0x800D4C18: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800D4C1C: addiu       $v1, $v1, 0x3994
    ctx->r3 = ADD32(ctx->r3, 0X3994);
    // 0x800D4C20: lbu         $t9, 0x457($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X457);
    // 0x800D4C24: andi        $t8, $t6, 0xFF8F
    ctx->r24 = ctx->r14 & 0XFF8F;
    // 0x800D4C28: lhu         $t1, 0x5DC($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X5DC);
    // 0x800D4C2C: lbu         $t2, 0x5DE($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X5DE);
    // 0x800D4C30: sb          $t8, 0x457($v0)
    MEM_B(0X457, ctx->r2) = ctx->r24;
    // 0x800D4C34: or          $t0, $t8, $t9
    ctx->r8 = ctx->r24 | ctx->r25;
    // 0x800D4C38: sb          $t0, 0x457($v0)
    MEM_B(0X457, ctx->r2) = ctx->r8;
    // 0x800D4C3C: sh          $t1, 0x5DC($v0)
    MEM_H(0X5DC, ctx->r2) = ctx->r9;
    // 0x800D4C40: jr          $ra
    // 0x800D4C44: sb          $t2, 0x5DE($v0)
    MEM_B(0X5DE, ctx->r2) = ctx->r10;
    return;
    // 0x800D4C44: sb          $t2, 0x5DE($v0)
    MEM_B(0X5DE, ctx->r2) = ctx->r10;
;}
RECOMP_FUNC void ftKirbySpecialLwUnkProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80161920: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80161924: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80161928: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8016192C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80161930: jal         0x800DDDA8
    // 0x80161934: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    mpCommonCheckFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x80161934: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_0:
    // 0x80161938: bnel        $v0, $zero, L_80161968
    if (ctx->r2 != 0) {
        // 0x8016193C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80161968;
    }
    goto skip_0;
    // 0x8016193C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80161940: jal         0x800DEEC8
    // 0x80161944: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    mpCommonSetFighterAir(rdram, ctx);
        goto after_1;
    // 0x80161944: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_1:
    // 0x80161948: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8016194C: addiu       $t7, $zero, 0x12
    ctx->r15 = ADD32(0, 0X12);
    // 0x80161950: addiu       $a1, $zero, 0x109
    ctx->r5 = ADD32(0, 0X109);
    // 0x80161954: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80161958: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8016195C: jal         0x800E6F24
    // 0x80161960: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_2;
    // 0x80161960: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_2:
    // 0x80161964: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80161968:
    // 0x80161968: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8016196C: jr          $ra
    // 0x80161970: nop

    return;
    // 0x80161970: nop

;}
RECOMP_FUNC void ftCommonHammerFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80147BE8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80147BEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80147BF0: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x80147BF4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80147BF8: jal         0x800DE6B0
    // 0x80147BFC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    mpCommonCheckFighterLanding(rdram, ctx);
        goto after_0;
    // 0x80147BFC: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80147C00: beq         $v0, $zero, L_80147C40
    if (ctx->r2 == 0) {
        // 0x80147C04: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_80147C40;
    }
    // 0x80147C04: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80147C08: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80147C0C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x80147C10: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80147C14: lwc1        $f6, 0x4C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X4C);
    // 0x80147C18: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x80147C1C: nop

    // 0x80147C20: bc1f        L_80147C38
    if (!c1cs) {
        // 0x80147C24: nop
    
            goto L_80147C38;
    }
    // 0x80147C24: nop

    // 0x80147C28: jal         0x800F3938
    // 0x80147C2C: nop

    ftHammerSetStatusHammerWait(rdram, ctx);
        goto after_1;
    // 0x80147C2C: nop

    after_1:
    // 0x80147C30: b           L_80147C44
    // 0x80147C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80147C44;
    // 0x80147C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80147C38:
    // 0x80147C38: jal         0x801480A4
    // 0x80147C3C: nop

    ftCommonHammerLandingSetStatus(rdram, ctx);
        goto after_2;
    // 0x80147C3C: nop

    after_2:
L_80147C40:
    // 0x80147C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80147C44:
    // 0x80147C44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80147C48: jr          $ra
    // 0x80147C4C: nop

    return;
    // 0x80147C4C: nop

;}
RECOMP_FUNC void itKamexFallInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80180860: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80180864: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80180868: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8018086C: jal         0x80173F78
    // 0x80180870: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    itMapSetAir(rdram, ctx);
        goto after_0;
    // 0x80180870: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_0:
    // 0x80180874: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x80180878: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018087C: lbu         $t6, 0x2CE($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X2CE);
    // 0x80180880: swc1        $f0, 0x30($a0)
    MEM_W(0X30, ctx->r4) = ctx->f0.u32l;
    // 0x80180884: swc1        $f0, 0x2C($a0)
    MEM_W(0X2C, ctx->r4) = ctx->f0.u32l;
    // 0x80180888: andi        $t7, $t6, 0xFF7F
    ctx->r15 = ctx->r14 & 0XFF7F;
    // 0x8018088C: sb          $t7, 0x2CE($a0)
    MEM_B(0X2CE, ctx->r4) = ctx->r15;
    // 0x80180890: swc1        $f0, 0x354($a0)
    MEM_W(0X354, ctx->r4) = ctx->f0.u32l;
    // 0x80180894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80180898: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018089C: jr          $ra
    // 0x801808A0: nop

    return;
    // 0x801808A0: nop

;}
RECOMP_FUNC void sc1PManagerCheckUnlockSoundTest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D6630: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x800D6634: lbu         $t6, 0x4937($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4937);
    // 0x800D6638: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D663C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D6640: andi        $t7, $t6, 0x20
    ctx->r15 = ctx->r14 & 0X20;
    // 0x800D6644: bne         $t7, $zero, L_800D672C
    if (ctx->r15 != 0) {
        // 0x800D6648: lui         $a0, 0x800A
        ctx->r4 = S32(0X800A << 16);
            goto L_800D672C;
    }
    // 0x800D6648: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D664C: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    // 0x800D6650: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
L_800D6654:
    // 0x800D6654: lbu         $t8, 0x470($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X470);
    // 0x800D6658: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800D665C: sllv        $t0, $t9, $v0
    ctx->r8 = S32(ctx->r25 << (ctx->r2 & 31));
    // 0x800D6660: bnel        $a1, $t8, L_800D6674
    if (ctx->r5 != ctx->r24) {
        // 0x800D6664: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_800D6674;
    }
    goto skip_0;
    // 0x800D6664: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    skip_0:
    // 0x800D6668: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x800D666C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x800D6670: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_800D6674:
    // 0x800D6674: slti        $at, $v0, 0xC
    ctx->r1 = SIGNED(ctx->r2) < 0XC ? 1 : 0;
    // 0x800D6678: bne         $at, $zero, L_800D6654
    if (ctx->r1 != 0) {
        // 0x800D667C: addiu       $a0, $a0, 0x20
        ctx->r4 = ADD32(ctx->r4, 0X20);
            goto L_800D6654;
    }
    // 0x800D667C: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    // 0x800D6680: addiu       $a2, $zero, 0xFFF
    ctx->r6 = ADD32(0, 0XFFF);
    // 0x800D6684: andi        $t1, $v1, 0xFFF
    ctx->r9 = ctx->r3 & 0XFFF;
    // 0x800D6688: bne         $a2, $t1, L_800D672C
    if (ctx->r6 != ctx->r9) {
        // 0x800D668C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D672C;
    }
    // 0x800D668C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D6690: lui         $a0, 0x800A
    ctx->r4 = S32(0X800A << 16);
    // 0x800D6694: addiu       $a0, $a0, 0x44E0
    ctx->r4 = ADD32(ctx->r4, 0X44E0);
    // 0x800D6698: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800D669C: addiu       $a3, $zero, 0xC
    ctx->r7 = ADD32(0, 0XC);
L_800D66A0:
    // 0x800D66A0: lbu         $t2, 0x478($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X478);
    // 0x800D66A4: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800D66A8: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x800D66AC: bne         $a1, $t2, L_800D66BC
    if (ctx->r5 != ctx->r10) {
        // 0x800D66B0: sllv        $t4, $t3, $v0
        ctx->r12 = S32(ctx->r11 << (ctx->r2 & 31));
            goto L_800D66BC;
    }
    // 0x800D66B0: sllv        $t4, $t3, $v0
    ctx->r12 = S32(ctx->r11 << (ctx->r2 & 31));
    // 0x800D66B4: or          $v1, $v1, $t4
    ctx->r3 = ctx->r3 | ctx->r12;
    // 0x800D66B8: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_800D66BC:
    // 0x800D66BC: lbu         $t5, 0x498($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X498);
    // 0x800D66C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800D66C4: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800D66C8: bne         $a1, $t5, L_800D66D8
    if (ctx->r5 != ctx->r13) {
        // 0x800D66CC: addiu       $t0, $v0, 0x2
        ctx->r8 = ADD32(ctx->r2, 0X2);
            goto L_800D66D8;
    }
    // 0x800D66CC: addiu       $t0, $v0, 0x2
    ctx->r8 = ADD32(ctx->r2, 0X2);
    // 0x800D66D0: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x800D66D4: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_800D66D8:
    // 0x800D66D8: lbu         $t9, 0x4B8($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X4B8);
    // 0x800D66DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800D66E0: sllv        $t2, $t1, $t0
    ctx->r10 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x800D66E4: bne         $a1, $t9, L_800D66F4
    if (ctx->r5 != ctx->r25) {
        // 0x800D66E8: addiu       $t4, $v0, 0x3
        ctx->r12 = ADD32(ctx->r2, 0X3);
            goto L_800D66F4;
    }
    // 0x800D66E8: addiu       $t4, $v0, 0x3
    ctx->r12 = ADD32(ctx->r2, 0X3);
    // 0x800D66EC: or          $v1, $v1, $t2
    ctx->r3 = ctx->r3 | ctx->r10;
    // 0x800D66F0: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_800D66F4:
    // 0x800D66F4: lbu         $t3, 0x4D8($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X4D8);
    // 0x800D66F8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800D66FC: sllv        $t7, $t5, $t4
    ctx->r15 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x800D6700: bne         $a1, $t3, L_800D6710
    if (ctx->r5 != ctx->r11) {
        // 0x800D6704: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800D6710;
    }
    // 0x800D6704: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800D6708: or          $v1, $v1, $t7
    ctx->r3 = ctx->r3 | ctx->r15;
    // 0x800D670C: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
L_800D6710:
    // 0x800D6710: bne         $v0, $a3, L_800D66A0
    if (ctx->r2 != ctx->r7) {
        // 0x800D6714: addiu       $a0, $a0, 0x80
        ctx->r4 = ADD32(ctx->r4, 0X80);
            goto L_800D66A0;
    }
    // 0x800D6714: addiu       $a0, $a0, 0x80
    ctx->r4 = ADD32(ctx->r4, 0X80);
    // 0x800D6718: andi        $t6, $v1, 0xFFF
    ctx->r14 = ctx->r3 & 0XFFF;
    // 0x800D671C: bnel        $a2, $t6, L_800D6730
    if (ctx->r6 != ctx->r14) {
        // 0x800D6720: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800D6730;
    }
    goto skip_1;
    // 0x800D6720: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    skip_1:
    // 0x800D6724: jr          $ra
    // 0x800D6728: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800D6728: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800D672C:
    // 0x800D672C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800D6730:
    // 0x800D6730: jr          $ra
    // 0x800D6734: nop

    return;
    // 0x800D6734: nop

;}
RECOMP_FUNC void gcResumeGObjProcessByProc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B35C: bnel        $a0, $zero, L_8000B370
    if (ctx->r4 != 0) {
        // 0x8000B360: lw          $v0, 0x18($a0)
        ctx->r2 = MEM_W(ctx->r4, 0X18);
            goto L_8000B370;
    }
    goto skip_0;
    // 0x8000B360: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    skip_0:
    // 0x8000B364: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x8000B368: lw          $a0, 0x6A54($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A54);
    // 0x8000B36C: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
L_8000B370:
    // 0x8000B370: beq         $v0, $zero, L_8000B394
    if (ctx->r2 == 0) {
        // 0x8000B374: nop
    
            goto L_8000B394;
    }
    // 0x8000B374: nop

    // 0x8000B378: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
L_8000B37C:
    // 0x8000B37C: bnel        $a1, $t6, L_8000B38C
    if (ctx->r5 != ctx->r14) {
        // 0x8000B380: lw          $v0, 0x0($v0)
        ctx->r2 = MEM_W(ctx->r2, 0X0);
            goto L_8000B38C;
    }
    goto skip_1;
    // 0x8000B380: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
    skip_1:
    // 0x8000B384: sb          $zero, 0x15($v0)
    MEM_B(0X15, ctx->r2) = 0;
    // 0x8000B388: lw          $v0, 0x0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X0);
L_8000B38C:
    // 0x8000B38C: bnel        $v0, $zero, L_8000B37C
    if (ctx->r2 != 0) {
        // 0x8000B390: lw          $t6, 0x20($v0)
        ctx->r14 = MEM_W(ctx->r2, 0X20);
            goto L_8000B37C;
    }
    goto skip_2;
    // 0x8000B390: lw          $t6, 0x20($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X20);
    skip_2:
L_8000B394:
    // 0x8000B394: jr          $ra
    // 0x8000B398: nop

    return;
    // 0x8000B398: nop

;}
RECOMP_FUNC void func_ovl2_800F8FFC(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F8FFC: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x800F9000: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800F9004: lw          $v0, 0x1368($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1368);
    // 0x800F9008: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800F900C: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800F9010: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800F9014: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800F9018: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800F901C: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800F9020: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800F9024: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800F9028: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800F902C: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800F9030: sdc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X30, ctx->r29);
    // 0x800F9034: sdc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X28, ctx->r29);
    // 0x800F9038: sdc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X20, ctx->r29);
    // 0x800F903C: sw          $a0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r4;
    // 0x800F9040: lw          $t6, 0x10($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10);
    // 0x800F9044: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x800F9048: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800F904C: sw          $t6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r14;
    // 0x800F9050: lhu         $a1, 0x0($v0)
    ctx->r5 = MEM_HU(ctx->r2, 0X0);
    // 0x800F9054: addiu       $s5, $s5, 0x1374
    ctx->r21 = ADD32(ctx->r21, 0X1374);
    // 0x800F9058: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800F905C: blez        $a1, L_800F9308
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800F9060: lui         $at, 0x8013
        ctx->r1 = S32(0X8013 << 16);
            goto L_800F9308;
    }
    // 0x800F9060: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800F9064: lwc1        $f24, 0x8E8($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X8E8);
    // 0x800F9068: addiu       $s4, $s4, 0x1370
    ctx->r20 = ADD32(ctx->r20, 0X1370);
    // 0x800F906C: addiu       $s3, $zero, 0x6
    ctx->r19 = ADD32(0, 0X6);
L_800F9070:
    // 0x800F9070: lw          $t7, 0x6C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X6C);
    // 0x800F9074: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800F9078: lw          $t8, 0x1304($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X1304);
    // 0x800F907C: lhu         $t9, 0x0($t7)
    ctx->r25 = MEM_HU(ctx->r15, 0X0);
    // 0x800F9080: lhu         $t4, 0x4($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X4);
    // 0x800F9084: addiu       $a0, $t7, 0x2
    ctx->r4 = ADD32(ctx->r15, 0X2);
    // 0x800F9088: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800F908C: addu        $t3, $t8, $t2
    ctx->r11 = ADD32(ctx->r24, ctx->r10);
    // 0x800F9090: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800F9094: beq         $t4, $zero, L_800F92E8
    if (ctx->r12 == 0) {
        // 0x800F9098: lw          $v0, 0x0($t3)
        ctx->r2 = MEM_W(ctx->r11, 0X0);
            goto L_800F92E8;
    }
    // 0x800F9098: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800F909C: lw          $v1, 0x84($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X84);
    // 0x800F90A0: lw          $t5, 0x70($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X70);
    // 0x800F90A4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800F90A8: beql        $at, $zero, L_800F92EC
    if (ctx->r1 == 0) {
        // 0x800F90AC: lw          $t5, 0x64($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X64);
            goto L_800F92EC;
    }
    goto skip_0;
    // 0x800F90AC: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
    skip_0:
    // 0x800F90B0: lw          $t6, 0x70($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X70);
    // 0x800F90B4: lwc1        $f0, 0x0($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800F90B8: lwc1        $f2, 0x4($t5)
    ctx->f2.u32l = MEM_W(ctx->r13, 0X4);
    // 0x800F90BC: bnel        $t6, $zero, L_800F90D0
    if (ctx->r14 != 0) {
        // 0x800F90C0: lwc1        $f6, 0x20($v0)
        ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
            goto L_800F90D0;
    }
    goto skip_1;
    // 0x800F90C0: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
    skip_1:
    // 0x800F90C4: beql        $v1, $zero, L_800F90E8
    if (ctx->r3 == 0) {
        // 0x800F90C8: mov.s       $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
            goto L_800F90E8;
    }
    goto skip_2;
    // 0x800F90C8: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    skip_2:
    // 0x800F90CC: lwc1        $f6, 0x20($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X20);
L_800F90D0:
    // 0x800F90D0: lwc1        $f4, 0x1C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800F90D4: sub.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800F90D8: sub.s       $f20, $f0, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800F90DC: b           L_800F90EC
    // 0x800F90E0: add.s       $f22, $f8, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f24.fl;
        goto L_800F90EC;
    // 0x800F90E0: add.s       $f22, $f8, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f8.fl + ctx->f24.fl;
    // 0x800F90E4: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
L_800F90E8:
    // 0x800F90E8: add.s       $f22, $f2, $f24
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f22.fl = ctx->f2.fl + ctx->f24.fl;
L_800F90EC:
    // 0x800F90EC: lhu         $v0, 0x0($a0)
    ctx->r2 = MEM_HU(ctx->r4, 0X0);
    // 0x800F90F0: lhu         $t9, 0x2($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X2);
    // 0x800F90F4: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x800F90F8: addu        $t8, $v0, $t9
    ctx->r24 = ADD32(ctx->r2, ctx->r25);
    // 0x800F90FC: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800F9100: beq         $at, $zero, L_800F92E8
    if (ctx->r1 == 0) {
        // 0x800F9104: sll         $s7, $v0, 2
        ctx->r23 = S32(ctx->r2 << 2);
            goto L_800F92E8;
    }
    // 0x800F9104: sll         $s7, $v0, 2
    ctx->r23 = S32(ctx->r2 << 2);
    // 0x800F9108: addu        $s7, $s7, $v0
    ctx->r23 = ADD32(ctx->r23, ctx->r2);
    // 0x800F910C: sll         $s7, $s7, 1
    ctx->r23 = S32(ctx->r23 << 1);
L_800F9110:
    // 0x800F9110: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800F9114: lw          $t2, 0x136C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X136C);
    // 0x800F9118: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800F911C: addu        $t3, $t2, $s7
    ctx->r11 = ADD32(ctx->r10, ctx->r23);
    // 0x800F9120: lh          $t7, 0x4($t3)
    ctx->r15 = MEM_H(ctx->r11, 0X4);
    // 0x800F9124: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800F9128: nop

    // 0x800F912C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800F9130: c.le.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl <= ctx->f22.fl;
    // 0x800F9134: nop

    // 0x800F9138: bc1fl       L_800F92C0
    if (!c1cs) {
        // 0x800F913C: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F92C0;
    }
    goto skip_3;
    // 0x800F913C: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_3:
    // 0x800F9140: lw          $t4, 0x1378($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1378);
    // 0x800F9144: sll         $t5, $s6, 2
    ctx->r13 = S32(ctx->r22 << 2);
    // 0x800F9148: lw          $t1, 0x0($s5)
    ctx->r9 = MEM_W(ctx->r21, 0X0);
    // 0x800F914C: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x800F9150: lhu         $v0, 0x0($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X0);
    // 0x800F9154: lhu         $s2, 0x2($a2)
    ctx->r18 = MEM_HU(ctx->r6, 0X2);
    // 0x800F9158: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800F915C: sll         $s1, $v0, 1
    ctx->r17 = S32(ctx->r2 << 1);
    // 0x800F9160: addu        $a0, $t1, $s1
    ctx->r4 = ADD32(ctx->r9, ctx->r17);
    // 0x800F9164: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    // 0x800F9168: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800F916C: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800F9170: multu       $t6, $s3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9174: sll         $t3, $s2, 1
    ctx->r11 = S32(ctx->r18 << 1);
    // 0x800F9178: addu        $t2, $t1, $t8
    ctx->r10 = ADD32(ctx->r9, ctx->r24);
    // 0x800F917C: addu        $t7, $t2, $t3
    ctx->r15 = ADD32(ctx->r10, ctx->r11);
    // 0x800F9180: lhu         $t4, 0x0($t7)
    ctx->r12 = MEM_HU(ctx->r15, 0X0);
    // 0x800F9184: mflo        $t9
    ctx->r25 = lo;
    // 0x800F9188: addu        $t0, $v1, $t9
    ctx->r8 = ADD32(ctx->r3, ctx->r25);
    // 0x800F918C: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    // 0x800F9190: multu       $t4, $s3
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9194: mtc1        $a1, $f18
    ctx->f18.u32l = ctx->r5;
    // 0x800F9198: nop

    // 0x800F919C: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800F91A0: mflo        $t5
    ctx->r13 = lo;
    // 0x800F91A4: c.le.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl <= ctx->f20.fl;
    // 0x800F91A8: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x800F91AC: lh          $a3, 0x0($t6)
    ctx->r7 = MEM_H(ctx->r14, 0X0);
    // 0x800F91B0: bc1fl       L_800F91D8
    if (!c1cs) {
        // 0x800F91B4: mtc1        $a3, $f8
        ctx->f8.u32l = ctx->r7;
            goto L_800F91D8;
    }
    goto skip_4;
    // 0x800F91B4: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    skip_4:
    // 0x800F91B8: mtc1        $a3, $f4
    ctx->f4.u32l = ctx->r7;
    // 0x800F91BC: nop

    // 0x800F91C0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800F91C4: c.le.s      $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f20.fl <= ctx->f6.fl;
    // 0x800F91C8: nop

    // 0x800F91CC: bc1tl       L_800F9200
    if (c1cs) {
        // 0x800F91D0: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800F9200;
    }
    goto skip_5;
    // 0x800F91D0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_5:
    // 0x800F91D4: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
L_800F91D8:
    // 0x800F91D8: nop

    // 0x800F91DC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800F91E0: c.le.s      $f10, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f10.fl <= ctx->f20.fl;
    // 0x800F91E4: nop

    // 0x800F91E8: bc1fl       L_800F92C0
    if (!c1cs) {
        // 0x800F91EC: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F92C0;
    }
    goto skip_6;
    // 0x800F91EC: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_6:
    // 0x800F91F0: c.le.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl <= ctx->f0.fl;
    // 0x800F91F4: nop

    // 0x800F91F8: bc1f        L_800F92BC
    if (!c1cs) {
        // 0x800F91FC: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800F92BC;
    }
    // 0x800F91FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_800F9200:
    // 0x800F9200: beql        $s2, $at, L_800F9284
    if (ctx->r18 == ctx->r1) {
        // 0x800F9204: lhu         $t5, 0x2($a0)
        ctx->r13 = MEM_HU(ctx->r4, 0X2);
            goto L_800F9284;
    }
    goto skip_7;
    // 0x800F9204: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
    skip_7:
    // 0x800F9208: blez        $s2, L_800F92BC
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800F920C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800F92BC;
    }
    // 0x800F920C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800F9210:
    // 0x800F9210: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x800F9214: lw          $v1, 0x0($s4)
    ctx->r3 = MEM_W(ctx->r20, 0X0);
    // 0x800F9218: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800F921C: addu        $a0, $t9, $s1
    ctx->r4 = ADD32(ctx->r25, ctx->r17);
    // 0x800F9220: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x800F9224: lhu         $t3, 0x2($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X2);
    // 0x800F9228: multu       $t8, $s3
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F922C: mflo        $t2
    ctx->r10 = lo;
    // 0x800F9230: addu        $t0, $v1, $t2
    ctx->r8 = ADD32(ctx->r3, ctx->r10);
    // 0x800F9234: lh          $a1, 0x0($t0)
    ctx->r5 = MEM_H(ctx->r8, 0X0);
    // 0x800F9238: multu       $t3, $s3
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F923C: lh          $a2, 0x2($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X2);
    // 0x800F9240: mflo        $t7
    ctx->r15 = lo;
    // 0x800F9244: addu        $v0, $v1, $t7
    ctx->r2 = ADD32(ctx->r3, ctx->r15);
    // 0x800F9248: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x800F924C: lh          $a3, 0x0($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X0);
    // 0x800F9250: jal         0x800F39F0
    // 0x800F9254: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    mpCollisionGetLineDistanceFC(rdram, ctx);
        goto after_0;
    // 0x800F9254: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_0:
    // 0x800F9258: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800F925C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800F9260: bc1f        L_800F9270
    if (!c1cs) {
        // 0x800F9264: nop
    
            goto L_800F9270;
    }
    // 0x800F9264: nop

    // 0x800F9268: b           L_800F930C
    // 0x800F926C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F930C;
    // 0x800F926C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F9270:
    // 0x800F9270: bne         $s0, $s2, L_800F9210
    if (ctx->r16 != ctx->r18) {
        // 0x800F9274: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_800F9210;
    }
    // 0x800F9274: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800F9278: b           L_800F92C0
    // 0x800F927C: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
        goto L_800F92C0;
    // 0x800F927C: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    // 0x800F9280: lhu         $t5, 0x2($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X2);
L_800F9284:
    // 0x800F9284: lh          $a2, 0x2($t0)
    ctx->r6 = MEM_H(ctx->r8, 0X2);
    // 0x800F9288: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x800F928C: multu       $t5, $s3
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r19)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800F9290: mflo        $t6
    ctx->r14 = lo;
    // 0x800F9294: addu        $t9, $v1, $t6
    ctx->r25 = ADD32(ctx->r3, ctx->r14);
    // 0x800F9298: lh          $t8, 0x2($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X2);
    // 0x800F929C: jal         0x800F39F0
    // 0x800F92A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    mpCollisionGetLineDistanceFC(rdram, ctx);
        goto after_1;
    // 0x800F92A0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x800F92A4: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x800F92A8: nop

    // 0x800F92AC: bc1fl       L_800F92C0
    if (!c1cs) {
        // 0x800F92B0: lhu         $t2, 0x0($fp)
        ctx->r10 = MEM_HU(ctx->r30, 0X0);
            goto L_800F92C0;
    }
    goto skip_8;
    // 0x800F92B0: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
    skip_8:
    // 0x800F92B4: b           L_800F930C
    // 0x800F92B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800F930C;
    // 0x800F92B8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800F92BC:
    // 0x800F92BC: lhu         $t2, 0x0($fp)
    ctx->r10 = MEM_HU(ctx->r30, 0X0);
L_800F92C0:
    // 0x800F92C0: lhu         $t3, 0x2($fp)
    ctx->r11 = MEM_HU(ctx->r30, 0X2);
    // 0x800F92C4: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x800F92C8: addiu       $s7, $s7, 0xA
    ctx->r23 = ADD32(ctx->r23, 0XA);
    // 0x800F92CC: addu        $t7, $t2, $t3
    ctx->r15 = ADD32(ctx->r10, ctx->r11);
    // 0x800F92D0: slt         $at, $s6, $t7
    ctx->r1 = SIGNED(ctx->r22) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800F92D4: bne         $at, $zero, L_800F9110
    if (ctx->r1 != 0) {
        // 0x800F92D8: nop
    
            goto L_800F9110;
    }
    // 0x800F92D8: nop

    // 0x800F92DC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800F92E0: lw          $t4, 0x1368($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X1368);
    // 0x800F92E4: lhu         $a1, 0x0($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X0);
L_800F92E8:
    // 0x800F92E8: lw          $t5, 0x64($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X64);
L_800F92EC:
    // 0x800F92EC: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800F92F0: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800F92F4: slt         $at, $t6, $a1
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800F92F8: addiu       $t8, $t9, 0x12
    ctx->r24 = ADD32(ctx->r25, 0X12);
    // 0x800F92FC: sw          $t8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r24;
    // 0x800F9300: bne         $at, $zero, L_800F9070
    if (ctx->r1 != 0) {
        // 0x800F9304: sw          $t6, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r14;
            goto L_800F9070;
    }
    // 0x800F9304: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
L_800F9308:
    // 0x800F9308: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800F930C:
    // 0x800F930C: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800F9310: ldc1        $f20, 0x20($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X20);
    // 0x800F9314: ldc1        $f22, 0x28($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X28);
    // 0x800F9318: ldc1        $f24, 0x30($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X30);
    // 0x800F931C: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800F9320: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800F9324: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800F9328: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800F932C: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800F9330: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800F9334: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800F9338: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800F933C: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800F9340: jr          $ra
    // 0x800F9344: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x800F9344: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void func_ovl3_80179F50(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179F58: jal         0x80172FE0
    // 0x80179F5C: nop

    itMainVelSetRebound(rdram, ctx);
        goto after_0;
    // 0x80179F5C: nop

    after_0:
    // 0x80179F60: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179F64: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179F68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80179F6C: jr          $ra
    // 0x80179F70: nop

    return;
    // 0x80179F70: nop

;}
RECOMP_FUNC void ftMainUpdateHiddenPartID(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E69C4: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800E69C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800E69CC: lw          $v0, 0x9C8($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X9C8);
    // 0x800E69D0: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x800E69D4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800E69D8: lw          $t6, 0x2D0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2D0);
    // 0x800E69DC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800E69E0: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800E69E4: addu        $t0, $t6, $t7
    ctx->r8 = ADD32(ctx->r14, ctx->r15);
    // 0x800E69E8: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x800E69EC: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x800E69F0: bne         $at, $zero, L_800E6A4C
    if (ctx->r1 != 0) {
        // 0x800E69F4: nop
    
            goto L_800E6A4C;
    }
    // 0x800E69F4: nop

    // 0x800E69F8: lbu         $t8, 0xE($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XE);
    // 0x800E69FC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E6A00: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x800E6A04: bnel        $t8, $at, L_800E6A18
    if (ctx->r24 != ctx->r1) {
        // 0x800E6A08: lw          $v0, 0x2D4($t2)
        ctx->r2 = MEM_W(ctx->r10, 0X2D4);
            goto L_800E6A18;
    }
    goto skip_0;
    // 0x800E6A08: lw          $v0, 0x2D4($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2D4);
    skip_0:
    // 0x800E6A0C: b           L_800E6A4C
    // 0x800E6A10: lw          $v1, 0x2D4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2D4);
        goto L_800E6A4C;
    // 0x800E6A10: lw          $v1, 0x2D4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X2D4);
    // 0x800E6A14: lw          $v0, 0x2D4($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X2D4);
L_800E6A18:
    // 0x800E6A18: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x800E6A1C: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800E6A20: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x800E6A24: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x800E6A28: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800E6A2C: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x800E6A30: lw          $t5, -0xAC($t4)
    ctx->r13 = MEM_W(ctx->r12, -0XAC);
    // 0x800E6A34: beq         $t5, $zero, L_800E6A44
    if (ctx->r13 == 0) {
        // 0x800E6A38: nop
    
            goto L_800E6A44;
    }
    // 0x800E6A38: nop

    // 0x800E6A3C: b           L_800E6A4C
    // 0x800E6A40: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
        goto L_800E6A4C;
    // 0x800E6A40: addiu       $v1, $v0, 0x10
    ctx->r3 = ADD32(ctx->r2, 0X10);
L_800E6A44:
    // 0x800E6A44: b           L_800E6A4C
    // 0x800E6A48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_800E6A4C;
    // 0x800E6A48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800E6A4C:
    // 0x800E6A4C: beq         $v1, $zero, L_800E6A78
    if (ctx->r3 == 0) {
        // 0x800E6A50: sll         $t7, $a2, 2
        ctx->r15 = S32(ctx->r6 << 2);
            goto L_800E6A78;
    }
    // 0x800E6A50: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800E6A54: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800E6A58: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800E6A5C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E6A60: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x800E6A64: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800E6A68: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800E6A6C: lw          $t9, -0xAC($t8)
    ctx->r25 = MEM_W(ctx->r24, -0XAC);
    // 0x800E6A70: b           L_800E6A7C
    // 0x800E6A74: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
        goto L_800E6A7C;
    // 0x800E6A74: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
L_800E6A78:
    // 0x800E6A78: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
L_800E6A7C:
    // 0x800E6A7C: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x800E6A80: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800E6A84: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800E6A88: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x800E6A8C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800E6A90: jal         0x800092D0
    // 0x800E6A94: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    gcAddDObjForGObj(rdram, ctx);
        goto after_0;
    // 0x800E6A94: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    after_0:
    // 0x800E6A98: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x800E6A9C: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800E6AA0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800E6AA4: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800E6AA8: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800E6AAC: sw          $zero, 0x8($t3)
    MEM_W(0X8, ctx->r11) = 0;
    // 0x800E6AB0: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x800E6AB4: lw          $t4, 0x38($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X38);
    // 0x800E6AB8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800E6ABC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E6AC0: beq         $t4, $zero, L_800E6B34
    if (ctx->r12 == 0) {
        // 0x800E6AC4: nop
    
            goto L_800E6B34;
    }
    // 0x800E6AC4: nop

    // 0x800E6AC8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800E6ACC: lbu         $t9, 0x10($t1)
    ctx->r25 = MEM_BU(ctx->r9, 0X10);
    // 0x800E6AD0: lw          $t5, 0x4($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X4);
    // 0x800E6AD4: lw          $t7, 0x8($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X8);
    // 0x800E6AD8: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x800E6ADC: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800E6AE0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800E6AE4: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800E6AE8: lw          $a2, -0x10($t8)
    ctx->r6 = MEM_W(ctx->r24, -0X10);
    // 0x800E6AEC: lw          $a1, -0x10($t6)
    ctx->r5 = MEM_W(ctx->r14, -0X10);
    // 0x800E6AF0: bgez        $t9, L_800E6B08
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800E6AF4: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800E6B08;
    }
    // 0x800E6AF4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800E6AF8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800E6AFC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800E6B00: nop

    // 0x800E6B04: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800E6B08:
    // 0x800E6B08: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    // 0x800E6B0C: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x800E6B10: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x800E6B14: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800E6B18: jal         0x800C8CB8
    // 0x800E6B1C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    lbCommonAddMObjForFighterPartsDObj(rdram, ctx);
        goto after_1;
    // 0x800E6B1C: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    after_1:
    // 0x800E6B20: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x800E6B24: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800E6B28: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800E6B2C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800E6B30: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
L_800E6B34:
    // 0x800E6B34: beq         $v1, $zero, L_800E6B6C
    if (ctx->r3 == 0) {
        // 0x800E6B38: lw          $t3, 0x38($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X38);
            goto L_800E6B6C;
    }
    // 0x800E6B38: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800E6B3C: beq         $t3, $zero, L_800E6B4C
    if (ctx->r11 == 0) {
        // 0x800E6B40: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_800E6B4C;
    }
    // 0x800E6B40: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800E6B44: b           L_800E6B4C
    // 0x800E6B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800E6B4C;
    // 0x800E6B48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800E6B4C:
    // 0x800E6B4C: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800E6B50: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x800E6B54: addu        $t6, $t1, $t5
    ctx->r14 = ADD32(ctx->r9, ctx->r13);
    // 0x800E6B58: sb          $v0, 0x975($t6)
    MEM_B(0X975, ctx->r14) = ctx->r2;
    // 0x800E6B5C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800E6B60: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800E6B64: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x800E6B68: sb          $v0, 0x974($t9)
    MEM_B(0X974, ctx->r25) = ctx->r2;
L_800E6B6C:
    // 0x800E6B6C: lw          $t3, 0x4($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X4);
    // 0x800E6B70: lw          $v0, 0xC($t0)
    ctx->r2 = MEM_W(ctx->r8, 0XC);
    // 0x800E6B74: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800E6B78: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800E6B7C: addu        $t5, $t1, $t4
    ctx->r13 = ADD32(ctx->r9, ctx->r12);
    // 0x800E6B80: beq         $v0, $zero, L_800E6BA8
    if (ctx->r2 == 0) {
        // 0x800E6B84: lw          $a2, 0x8E8($t5)
        ctx->r6 = MEM_W(ctx->r13, 0X8E8);
            goto L_800E6BA8;
    }
    // 0x800E6B84: lw          $a2, 0x8E8($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X8E8);
    // 0x800E6B88: beq         $v0, $at, L_800E6BEC
    if (ctx->r2 == ctx->r1) {
        // 0x800E6B8C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800E6BEC;
    }
    // 0x800E6B8C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800E6B90: beq         $v0, $at, L_800E6C0C
    if (ctx->r2 == ctx->r1) {
        // 0x800E6B94: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800E6C0C;
    }
    // 0x800E6B94: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800E6B98: beql        $v0, $at, L_800E6C34
    if (ctx->r2 == ctx->r1) {
        // 0x800E6B9C: lw          $a1, 0x10($a2)
        ctx->r5 = MEM_W(ctx->r6, 0X10);
            goto L_800E6C34;
    }
    goto skip_1;
    // 0x800E6B9C: lw          $a1, 0x10($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X10);
    skip_1:
    // 0x800E6BA0: b           L_800E6C5C
    // 0x800E6BA4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
        goto L_800E6C5C;
    // 0x800E6BA4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
L_800E6BA8:
    // 0x800E6BA8: lw          $a1, 0x10($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X10);
    // 0x800E6BAC: beql        $a1, $zero, L_800E6BE4
    if (ctx->r5 == 0) {
        // 0x800E6BB0: sw          $a0, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->r4;
            goto L_800E6BE4;
    }
    goto skip_2;
    // 0x800E6BB0: sw          $a0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r4;
    skip_2:
    // 0x800E6BB4: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x800E6BB8: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800E6BBC: beql        $v1, $zero, L_800E6BD8
    if (ctx->r3 == 0) {
        // 0x800E6BC0: sw          $a0, 0x8($v0)
        MEM_W(0X8, ctx->r2) = ctx->r4;
            goto L_800E6BD8;
    }
    goto skip_3;
    // 0x800E6BC0: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    skip_3:
    // 0x800E6BC4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800E6BC8:
    // 0x800E6BC8: lw          $v1, 0x8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X8);
    // 0x800E6BCC: bnel        $v1, $zero, L_800E6BC8
    if (ctx->r3 != 0) {
        // 0x800E6BD0: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800E6BC8;
    }
    goto skip_4;
    // 0x800E6BD0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    skip_4:
    // 0x800E6BD4: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_800E6BD8:
    // 0x800E6BD8: b           L_800E6BE4
    // 0x800E6BDC: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
        goto L_800E6BE4;
    // 0x800E6BDC: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x800E6BE0: sw          $a0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r4;
L_800E6BE4:
    // 0x800E6BE4: b           L_800E6C58
    // 0x800E6BE8: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
        goto L_800E6C58;
    // 0x800E6BE8: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800E6BEC:
    // 0x800E6BEC: lw          $a1, 0x10($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X10);
    // 0x800E6BF0: beql        $a1, $zero, L_800E6C04
    if (ctx->r5 == 0) {
        // 0x800E6BF4: sw          $a0, 0x10($a2)
        MEM_W(0X10, ctx->r6) = ctx->r4;
            goto L_800E6C04;
    }
    goto skip_5;
    // 0x800E6BF4: sw          $a0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r4;
    skip_5:
    // 0x800E6BF8: sw          $a0, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r4;
    // 0x800E6BFC: sw          $a1, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r5;
    // 0x800E6C00: sw          $a0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r4;
L_800E6C04:
    // 0x800E6C04: b           L_800E6C58
    // 0x800E6C08: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
        goto L_800E6C58;
    // 0x800E6C08: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800E6C0C:
    // 0x800E6C0C: lw          $t6, 0x10($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X10);
    // 0x800E6C10: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x800E6C14: sw          $a0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r4;
    // 0x800E6C18: sw          $v0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r2;
    // 0x800E6C1C: lw          $v0, 0x10($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X10);
    // 0x800E6C20: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
    // 0x800E6C24: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
    // 0x800E6C28: b           L_800E6C58
    // 0x800E6C2C: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
        goto L_800E6C58;
    // 0x800E6C2C: sw          $v0, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r2;
    // 0x800E6C30: lw          $a1, 0x10($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X10);
L_800E6C34:
    // 0x800E6C34: beq         $a1, $zero, L_800E6C50
    if (ctx->r5 == 0) {
        // 0x800E6C38: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800E6C50;
    }
    // 0x800E6C38: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800E6C3C: sw          $a1, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r5;
    // 0x800E6C40: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
L_800E6C44:
    // 0x800E6C44: lw          $v0, 0x8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X8);
    // 0x800E6C48: bnel        $v0, $zero, L_800E6C44
    if (ctx->r2 != 0) {
        // 0x800E6C4C: sw          $a0, 0x14($v0)
        MEM_W(0X14, ctx->r2) = ctx->r4;
            goto L_800E6C44;
    }
    goto skip_6;
    // 0x800E6C4C: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    skip_6:
L_800E6C50:
    // 0x800E6C50: sw          $a0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r4;
    // 0x800E6C54: sw          $a2, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r6;
L_800E6C58:
    // 0x800E6C58: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
L_800E6C5C:
    // 0x800E6C5C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800E6C60: addu        $t9, $t1, $t8
    ctx->r25 = ADD32(ctx->r9, ctx->r24);
    // 0x800E6C64: sw          $a0, 0x8E8($t9)
    MEM_W(0X8E8, ctx->r25) = ctx->r4;
    // 0x800E6C68: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x800E6C6C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800E6C70: jal         0x800D7604
    // 0x800E6C74: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    ftManagerGetNextPartsAlloc(rdram, ctx);
        goto after_2;
    // 0x800E6C74: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    after_2:
    // 0x800E6C78: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800E6C7C: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x800E6C80: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x800E6C84: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800E6C88: sw          $v0, 0x84($a0)
    MEM_W(0X84, ctx->r4) = ctx->r2;
    // 0x800E6C8C: lbu         $t4, 0xE($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0XE);
    // 0x800E6C90: lw          $t3, 0x2D4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X2D4);
    // 0x800E6C94: addiu       $a1, $zero, 0x4B
    ctx->r5 = ADD32(0, 0X4B);
    // 0x800E6C98: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800E6C9C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x800E6CA0: lbu         $t7, -0x4($t6)
    ctx->r15 = MEM_BU(ctx->r14, -0X4);
    // 0x800E6CA4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800E6CA8: sb          $t7, 0xC($v0)
    MEM_B(0XC, ctx->r2) = ctx->r15;
    // 0x800E6CAC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800E6CB0: sb          $t8, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r24;
    // 0x800E6CB4: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800E6CB8: beql        $t9, $zero, L_800E6CD4
    if (ctx->r25 == 0) {
        // 0x800E6CBC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800E6CD4;
    }
    goto skip_7;
    // 0x800E6CBC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_7:
    // 0x800E6CC0: lbu         $t4, 0x149($t1)
    ctx->r12 = MEM_BU(ctx->r9, 0X149);
    // 0x800E6CC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800E6CC8: jal         0x800C8A58
    // 0x800E6CCC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    lbCommonInitDObj(rdram, ctx);
        goto after_3;
    // 0x800E6CCC: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_3:
    // 0x800E6CD0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800E6CD4:
    // 0x800E6CD4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800E6CD8: jr          $ra
    // 0x800E6CDC: nop

    return;
    // 0x800E6CDC: nop

;}
RECOMP_FUNC void drawbitmap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800238B8: addiu       $sp, $sp, -0x1F8
    ctx->r29 = ADD32(ctx->r29, -0X1F8);
    // 0x800238BC: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800238C0: sw          $a0, 0x1F8($sp)
    MEM_W(0X1F8, ctx->r29) = ctx->r4;
    // 0x800238C4: sw          $a1, 0x1FC($sp)
    MEM_W(0X1FC, ctx->r29) = ctx->r5;
    // 0x800238C8: sw          $a2, 0x200($sp)
    MEM_W(0X200, ctx->r29) = ctx->r6;
    // 0x800238CC: sw          $a3, 0x204($sp)
    MEM_W(0X204, ctx->r29) = ctx->r7;
    // 0x800238D0: lui         $v1, 0x800A
    ctx->r3 = S32(0X800A << 16);
    // 0x800238D4: lh          $t8, 0x2E($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X2E);
    // 0x800238D8: lw          $v1, -0x1240($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1240);
    // 0x800238DC: lh          $s0, 0x2($a2)
    ctx->r16 = MEM_H(ctx->r6, 0X2);
    // 0x800238E0: sw          $t8, 0x1D4($sp)
    MEM_W(0X1D4, ctx->r29) = ctx->r24;
    // 0x800238E4: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800238E8: beq         $at, $zero, L_80024FC8
    if (ctx->r1 == 0) {
        // 0x800238EC: lw          $t1, 0x0($a0)
        ctx->r9 = MEM_W(ctx->r4, 0X0);
            goto L_80024FC8;
    }
    // 0x800238EC: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800238F0: lui         $a1, 0x800A
    ctx->r5 = S32(0X800A << 16);
    // 0x800238F4: lw          $a1, -0x123C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X123C);
    // 0x800238F8: lw          $a0, 0x208($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X208);
    // 0x800238FC: lw          $a2, 0x20C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20C);
    // 0x80023900: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x80023904: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80023908: beql        $at, $zero, L_80024FCC
    if (ctx->r1 == 0) {
        // 0x8002390C: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_80024FCC;
    }
    goto skip_0;
    // 0x8002390C: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_0:
    // 0x80023910: lw          $t0, -0x1238($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X1238);
    // 0x80023914: lw          $a3, 0x210($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X210);
    // 0x80023918: lui         $v0, 0x800A
    ctx->r2 = S32(0X800A << 16);
    // 0x8002391C: slt         $at, $a2, $t0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80023920: bnel        $at, $zero, L_80024FCC
    if (ctx->r1 != 0) {
        // 0x80023924: lw          $s0, 0x4($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X4);
            goto L_80024FCC;
    }
    goto skip_1;
    // 0x80023924: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    skip_1:
    // 0x80023928: lw          $v0, -0x1234($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X1234);
    // 0x8002392C: lw          $t7, 0x204($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X204);
    // 0x80023930: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80023934: bne         $at, $zero, L_80024FC8
    if (ctx->r1 != 0) {
        // 0x80023938: slt         $at, $t7, $t0
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
            goto L_80024FC8;
    }
    // 0x80023938: slt         $at, $t7, $t0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8002393C: beql        $at, $zero, L_80023984
    if (ctx->r1 == 0) {
        // 0x80023940: lw          $t7, 0x204($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X204);
            goto L_80023984;
    }
    goto skip_2;
    // 0x80023940: lw          $t7, 0x204($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X204);
    skip_2:
    // 0x80023944: lw          $t9, 0x200($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X200);
    // 0x80023948: sll         $t8, $t0, 2
    ctx->r24 = S32(ctx->r8 << 2);
    // 0x8002394C: sw          $t8, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->r24;
    // 0x80023950: lh          $t6, 0x4($t9)
    ctx->r14 = MEM_H(ctx->r25, 0X4);
    // 0x80023954: lw          $t9, 0x214($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X214);
    // 0x80023958: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x8002395C: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x80023960: lw          $t9, 0x21C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X21C);
    // 0x80023964: subu        $t8, $t0, $t7
    ctx->r24 = SUB32(ctx->r8, ctx->r15);
    // 0x80023968: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002396C: mflo        $t7
    ctx->r15 = lo;
    // 0x80023970: sra         $t8, $t7, 5
    ctx->r24 = S32(SIGNED(ctx->r15) >> 5);
    // 0x80023974: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80023978: b           L_800239A4
    // 0x8002397C: sw          $t9, 0x1F4($sp)
    MEM_W(0X1F4, ctx->r29) = ctx->r25;
        goto L_800239A4;
    // 0x8002397C: sw          $t9, 0x1F4($sp)
    MEM_W(0X1F4, ctx->r29) = ctx->r25;
    // 0x80023980: lw          $t7, 0x204($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X204);
L_80023984:
    // 0x80023984: lw          $t8, 0x200($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X200);
    // 0x80023988: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8002398C: sw          $t6, 0x1EC($sp)
    MEM_W(0X1EC, ctx->r29) = ctx->r14;
    // 0x80023990: lh          $t9, 0x4($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X4);
    // 0x80023994: lw          $t6, 0x214($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X214);
    // 0x80023998: sll         $t7, $t9, 5
    ctx->r15 = S32(ctx->r25 << 5);
    // 0x8002399C: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800239A0: sw          $t8, 0x1F4($sp)
    MEM_W(0X1F4, ctx->r29) = ctx->r24;
L_800239A4:
    // 0x800239A4: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800239A8: beql        $at, $zero, L_800239F0
    if (ctx->r1 == 0) {
        // 0x800239AC: lw          $t7, 0x200($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X200);
            goto L_800239F0;
    }
    goto skip_3;
    // 0x800239AC: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    skip_3:
    // 0x800239B0: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    // 0x800239B4: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800239B8: sw          $t9, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->r25;
    // 0x800239BC: lh          $t6, 0x6($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X6);
    // 0x800239C0: lw          $t9, 0x218($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X218);
    // 0x800239C4: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x800239C8: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x800239CC: lw          $t8, 0x220($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X220);
    // 0x800239D0: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800239D4: multu       $t6, $t8
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800239D8: mflo        $t9
    ctx->r25 = lo;
    // 0x800239DC: sra         $t6, $t9, 5
    ctx->r14 = S32(SIGNED(ctx->r25) >> 5);
    // 0x800239E0: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x800239E4: b           L_80023A0C
    // 0x800239E8: sw          $t8, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = ctx->r24;
        goto L_80023A0C;
    // 0x800239E8: sw          $t8, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = ctx->r24;
    // 0x800239EC: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
L_800239F0:
    // 0x800239F0: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800239F4: sw          $t9, 0x1E8($sp)
    MEM_W(0X1E8, ctx->r29) = ctx->r25;
    // 0x800239F8: lh          $t6, 0x6($t7)
    ctx->r14 = MEM_H(ctx->r15, 0X6);
    // 0x800239FC: lw          $t9, 0x218($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X218);
    // 0x80023A00: sll         $t8, $t6, 5
    ctx->r24 = S32(ctx->r14 << 5);
    // 0x80023A04: addu        $t7, $t8, $t9
    ctx->r15 = ADD32(ctx->r24, ctx->r25);
    // 0x80023A08: sw          $t7, 0x1F0($sp)
    MEM_W(0X1F0, ctx->r29) = ctx->r15;
L_80023A0C:
    // 0x80023A0C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80023A10: bne         $at, $zero, L_80023A24
    if (ctx->r1 != 0) {
        // 0x80023A14: sll         $t8, $a2, 2
        ctx->r24 = S32(ctx->r6 << 2);
            goto L_80023A24;
    }
    // 0x80023A14: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x80023A18: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x80023A1C: b           L_80023A28
    // 0x80023A20: sw          $t6, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->r14;
        goto L_80023A28;
    // 0x80023A20: sw          $t6, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->r14;
L_80023A24:
    // 0x80023A24: sw          $t8, 0x1E4($sp)
    MEM_W(0X1E4, ctx->r29) = ctx->r24;
L_80023A28:
    // 0x80023A28: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80023A2C: bne         $at, $zero, L_80023A40
    if (ctx->r1 != 0) {
        // 0x80023A30: sll         $t7, $a3, 2
        ctx->r15 = S32(ctx->r7 << 2);
            goto L_80023A40;
    }
    // 0x80023A30: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80023A34: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80023A38: b           L_80023A44
    // 0x80023A3C: sw          $t9, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r25;
        goto L_80023A44;
    // 0x80023A3C: sw          $t9, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r25;
L_80023A40:
    // 0x80023A40: sw          $t7, 0x1E0($sp)
    MEM_W(0X1E0, ctx->r29) = ctx->r15;
L_80023A44:
    // 0x80023A44: lw          $t6, 0x200($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X200);
    // 0x80023A48: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80023A4C: lw          $t8, -0x2F90($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2F90);
    // 0x80023A50: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
    // 0x80023A54: lw          $t9, 0x1FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023A58: beql        $t8, $v0, L_80024E38
    if (ctx->r24 == ctx->r2) {
        // 0x80023A5C: addiu       $v0, $sp, 0x1C4
        ctx->r2 = ADD32(ctx->r29, 0X1C4);
            goto L_80024E38;
    }
    goto skip_4;
    // 0x80023A5C: addiu       $v0, $sp, 0x1C4
    ctx->r2 = ADD32(ctx->r29, 0X1C4);
    skip_4:
    // 0x80023A60: lbu         $a0, 0x31($t9)
    ctx->r4 = MEM_BU(ctx->r25, 0X31);
    // 0x80023A64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80023A68: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023A6C: beql        $a0, $zero, L_80023AA0
    if (ctx->r4 == 0) {
        // 0x80023A70: lhu         $t6, 0x14($t7)
        ctx->r14 = MEM_HU(ctx->r15, 0X14);
            goto L_80023AA0;
    }
    goto skip_5;
    // 0x80023A70: lhu         $t6, 0x14($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X14);
    skip_5:
    // 0x80023A74: beq         $a0, $at, L_80023DE8
    if (ctx->r4 == ctx->r1) {
        // 0x80023A78: lw          $t6, 0x1FC($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X1FC);
            goto L_80023DE8;
    }
    // 0x80023A78: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023A7C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80023A80: beq         $a0, $at, L_80024138
    if (ctx->r4 == ctx->r1) {
        // 0x80023A84: lw          $a2, 0x1FC($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1FC);
            goto L_80024138;
    }
    // 0x80023A84: lw          $a2, 0x1FC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023A88: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80023A8C: beq         $a0, $at, L_80024AFC
    if (ctx->r4 == ctx->r1) {
        // 0x80023A90: lw          $a2, 0x1FC($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X1FC);
            goto L_80024AFC;
    }
    // 0x80023A90: lw          $a2, 0x1FC($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023A94: b           L_80024E2C
    // 0x80023A98: nop

        goto L_80024E2C;
    // 0x80023A98: nop

    // 0x80023A9C: lhu         $t6, 0x14($t7)
    ctx->r14 = MEM_HU(ctx->r15, 0X14);
L_80023AA0:
    // 0x80023AA0: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x80023AA4: andi        $t8, $t6, 0x200
    ctx->r24 = ctx->r14 & 0X200;
    // 0x80023AA8: beql        $t8, $zero, L_80023C14
    if (ctx->r24 == 0) {
        // 0x80023AAC: lw          $t8, 0x1FC($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1FC);
            goto L_80023C14;
    }
    goto skip_6;
    // 0x80023AAC: lw          $t8, 0x1FC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1FC);
    skip_6:
    // 0x80023AB0: lbu         $t9, 0x30($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X30);
    // 0x80023AB4: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x80023AB8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80023ABC: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x80023AC0: sll         $t8, $t6, 21
    ctx->r24 = S32(ctx->r14 << 21);
    // 0x80023AC4: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80023AC8: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x80023ACC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80023AD0: lw          $t6, 0x200($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X200);
    // 0x80023AD4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023AD8: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80023ADC: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x80023AE0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80023AE4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023AE8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80023AEC: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023AF0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80023AF4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023AF8: lbu         $t9, 0x30($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X30);
    // 0x80023AFC: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80023B00: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023B04: andi        $t6, $t9, 0x7
    ctx->r14 = ctx->r25 & 0X7;
    // 0x80023B08: sll         $t8, $t6, 21
    ctx->r24 = S32(ctx->r14 << 21);
    // 0x80023B0C: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x80023B10: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x80023B14: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80023B18: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x80023B1C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80023B20: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x80023B24: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80023B28: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80023B2C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80023B30: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x80023B34: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80023B38: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x80023B3C: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x80023B40: multu       $s0, $t9
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023B44: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x80023B48: mflo        $v0
    ctx->r2 = lo;
    // 0x80023B4C: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80023B50: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80023B54: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80023B58: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x80023B5C: beq         $at, $zero, L_80023B6C
    if (ctx->r1 == 0) {
        // 0x80023B60: nop
    
            goto L_80023B6C;
    }
    // 0x80023B60: nop

    // 0x80023B64: b           L_80023B6C
    // 0x80023B68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80023B6C;
    // 0x80023B68: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80023B6C:
    // 0x80023B6C: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x80023B70: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x80023B74: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80023B78: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80023B7C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x80023B80: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80023B84: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80023B88: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80023B8C: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023B90: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023B94: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80023B98: lbu         $t8, 0x30($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X30);
    // 0x80023B9C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023BA0: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80023BA4: andi        $t7, $t8, 0x7
    ctx->r15 = ctx->r24 & 0X7;
    // 0x80023BA8: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x80023BAC: sra         $t8, $s0, 1
    ctx->r24 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80023BB0: addiu       $t7, $t8, 0x7
    ctx->r15 = ADD32(ctx->r24, 0X7);
    // 0x80023BB4: or          $t6, $t9, $t3
    ctx->r14 = ctx->r25 | ctx->r11;
    // 0x80023BB8: sra         $t9, $t7, 3
    ctx->r25 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80023BBC: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x80023BC0: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x80023BC4: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80023BC8: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x80023BCC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80023BD0: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80023BD4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80023BD8: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x80023BDC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80023BE0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80023BE4: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80023BE8: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x80023BEC: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80023BF0: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80023BF4: addiu       $t9, $t7, -0x1
    ctx->r25 = ADD32(ctx->r15, -0X1);
    // 0x80023BF8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80023BFC: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80023C00: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80023C04: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80023C08: b           L_80023DDC
    // 0x80023C0C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_80023DDC;
    // 0x80023C0C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023C10: lw          $t8, 0x1FC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1FC);
L_80023C14:
    // 0x80023C14: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x80023C18: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x80023C1C: lbu         $t6, 0x30($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X30);
    // 0x80023C20: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80023C24: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023C28: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80023C2C: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x80023C30: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80023C34: or          $t6, $t8, $a3
    ctx->r14 = ctx->r24 | ctx->r7;
    // 0x80023C38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80023C3C: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    // 0x80023C40: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80023C44: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80023C48: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80023C4C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023C50: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80023C54: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80023C58: lw          $t8, 0x1FC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023C5C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023C60: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x80023C64: lbu         $t6, 0x30($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X30);
    // 0x80023C68: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80023C6C: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x80023C70: or          $t8, $t9, $t3
    ctx->r24 = ctx->r25 | ctx->r11;
    // 0x80023C74: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x80023C78: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80023C7C: or          $t6, $t8, $a3
    ctx->r14 = ctx->r24 | ctx->r7;
    // 0x80023C80: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80023C84: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80023C88: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80023C8C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80023C90: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80023C94: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80023C98: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80023C9C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80023CA0: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x80023CA4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023CA8: multu       $s0, $t6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023CAC: mflo        $v0
    ctx->r2 = lo;
    // 0x80023CB0: addiu       $v0, $v0, 0x3
    ctx->r2 = ADD32(ctx->r2, 0X3);
    // 0x80023CB4: sra         $v0, $v0, 2
    ctx->r2 = S32(SIGNED(ctx->r2) >> 2);
    // 0x80023CB8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80023CBC: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x80023CC0: beq         $at, $zero, L_80023CD0
    if (ctx->r1 == 0) {
        // 0x80023CC4: nop
    
            goto L_80023CD0;
    }
    // 0x80023CC4: nop

    // 0x80023CC8: b           L_80023CD0
    // 0x80023CCC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80023CD0;
    // 0x80023CCC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80023CD0:
    // 0x80023CD0: bgez        $s0, L_80023CE0
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80023CD4: sra         $v0, $s0, 4
        ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
            goto L_80023CE0;
    }
    // 0x80023CD4: sra         $v0, $s0, 4
    ctx->r2 = S32(SIGNED(ctx->r16) >> 4);
    // 0x80023CD8: addiu       $at, $s0, 0xF
    ctx->r1 = ADD32(ctx->r16, 0XF);
    // 0x80023CDC: sra         $v0, $at, 4
    ctx->r2 = S32(SIGNED(ctx->r1) >> 4);
L_80023CE0:
    // 0x80023CE0: bgtz        $v0, L_80023CF0
    if (SIGNED(ctx->r2) > 0) {
        // 0x80023CE4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80023CF0;
    }
    // 0x80023CE4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80023CE8: b           L_80023CF0
    // 0x80023CEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80023CF0;
    // 0x80023CEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80023CF0:
    // 0x80023CF0: bgtz        $v0, L_80023D00
    if (SIGNED(ctx->r2) > 0) {
        // 0x80023CF4: addiu       $t7, $a1, 0x7FF
        ctx->r15 = ADD32(ctx->r5, 0X7FF);
            goto L_80023D00;
    }
    // 0x80023CF4: addiu       $t7, $a1, 0x7FF
    ctx->r15 = ADD32(ctx->r5, 0X7FF);
    // 0x80023CF8: b           L_80023D04
    // 0x80023CFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80023D04;
    // 0x80023CFC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80023D00:
    // 0x80023D00: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80023D04:
    // 0x80023D04: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x80023D08: bne         $a0, $zero, L_80023D14
    if (ctx->r4 != 0) {
        // 0x80023D0C: nop
    
            goto L_80023D14;
    }
    // 0x80023D0C: nop

    // 0x80023D10: break       7
    do_break(2147630352);
L_80023D14:
    // 0x80023D14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80023D18: bne         $a0, $at, L_80023D2C
    if (ctx->r4 != ctx->r1) {
        // 0x80023D1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80023D2C;
    }
    // 0x80023D1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80023D20: bne         $t7, $at, L_80023D2C
    if (ctx->r15 != ctx->r1) {
        // 0x80023D24: nop
    
            goto L_80023D2C;
    }
    // 0x80023D24: nop

    // 0x80023D28: break       6
    do_break(2147630376);
L_80023D2C:
    // 0x80023D2C: mflo        $t9
    ctx->r25 = lo;
    // 0x80023D30: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80023D34: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80023D38: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x80023D3C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x80023D40: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80023D44: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80023D48: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80023D4C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80023D50: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80023D54: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80023D58: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80023D5C: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023D60: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023D64: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80023D68: lbu         $t9, 0x30($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X30);
    // 0x80023D6C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023D70: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80023D74: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x80023D78: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x80023D7C: sra         $t9, $s0, 1
    ctx->r25 = S32(SIGNED(ctx->r16) >> 1);
    // 0x80023D80: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x80023D84: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x80023D88: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x80023D8C: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x80023D90: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x80023D94: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80023D98: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80023D9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80023DA0: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80023DA4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80023DA8: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x80023DAC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80023DB0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80023DB4: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80023DB8: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x80023DBC: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80023DC0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80023DC4: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80023DC8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80023DCC: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80023DD0: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80023DD4: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80023DD8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_80023DDC:
    // 0x80023DDC: lw          $t9, 0x200($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X200);
    // 0x80023DE0: b           L_80024E2C
    // 0x80023DE4: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
        goto L_80024E2C;
    // 0x80023DE4: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
L_80023DE8:
    // 0x80023DE8: lhu         $t8, 0x14($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X14);
    // 0x80023DEC: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x80023DF0: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
    // 0x80023DF4: andi        $t7, $t8, 0x200
    ctx->r15 = ctx->r24 & 0X200;
    // 0x80023DF8: beq         $t7, $zero, L_80023F60
    if (ctx->r15 == 0) {
        // 0x80023DFC: lw          $t8, 0x1FC($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X1FC);
            goto L_80023F60;
    }
    // 0x80023DFC: lw          $t8, 0x1FC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023E00: lbu         $t9, 0x30($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X30);
    // 0x80023E04: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x80023E08: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x80023E0C: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x80023E10: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x80023E14: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x80023E18: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x80023E1C: or          $t9, $t6, $a3
    ctx->r25 = ctx->r14 | ctx->r7;
    // 0x80023E20: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80023E24: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80023E28: lw          $t8, 0x200($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X200);
    // 0x80023E2C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023E30: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80023E34: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80023E38: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80023E3C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023E40: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80023E44: lbu         $t6, 0x30($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X30);
    // 0x80023E48: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80023E4C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023E50: andi        $t9, $t6, 0x7
    ctx->r25 = ctx->r14 & 0X7;
    // 0x80023E54: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x80023E58: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x80023E5C: lui         $t9, 0x708
    ctx->r25 = S32(0X708 << 16);
    // 0x80023E60: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80023E64: or          $t6, $t7, $a3
    ctx->r14 = ctx->r15 | ctx->r7;
    // 0x80023E68: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80023E6C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80023E70: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80023E74: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80023E78: lw          $a3, 0x1D4($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1D4);
    // 0x80023E7C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80023E80: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x80023E84: multu       $s0, $a3
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023E88: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80023E8C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80023E90: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023E94: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x80023E98: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80023E9C: mflo        $v0
    ctx->r2 = lo;
    // 0x80023EA0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80023EA4: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80023EA8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80023EAC: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x80023EB0: beq         $at, $zero, L_80023EC0
    if (ctx->r1 == 0) {
        // 0x80023EB4: nop
    
            goto L_80023EC0;
    }
    // 0x80023EB4: nop

    // 0x80023EB8: b           L_80023EC0
    // 0x80023EBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80023EC0;
    // 0x80023EBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80023EC0:
    // 0x80023EC0: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x80023EC4: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80023EC8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80023ECC: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80023ED0: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80023ED4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80023ED8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80023EDC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80023EE0: lbu         $t6, 0x30($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X30);
    // 0x80023EE4: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x80023EE8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023EEC: andi        $t9, $t6, 0x7
    ctx->r25 = ctx->r14 & 0X7;
    // 0x80023EF0: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x80023EF4: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x80023EF8: addiu       $t9, $s0, 0x7
    ctx->r25 = ADD32(ctx->r16, 0X7);
    // 0x80023EFC: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x80023F00: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x80023F04: andi        $t7, $t8, 0x1FF
    ctx->r15 = ctx->r24 & 0X1FF;
    // 0x80023F08: sll         $t9, $t7, 9
    ctx->r25 = S32(ctx->r15 << 9);
    // 0x80023F0C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80023F10: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80023F14: lui         $t7, 0x8
    ctx->r15 = S32(0X8 << 16);
    // 0x80023F18: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80023F1C: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80023F20: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x80023F24: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023F28: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80023F2C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80023F30: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80023F34: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80023F38: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80023F3C: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x80023F40: addiu       $t9, $a3, -0x1
    ctx->r25 = ADD32(ctx->r7, -0X1);
    // 0x80023F44: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x80023F48: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x80023F4C: andi        $t7, $t8, 0xFFF
    ctx->r15 = ctx->r24 & 0XFFF;
    // 0x80023F50: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x80023F54: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80023F58: b           L_8002412C
    // 0x80023F5C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_8002412C;
    // 0x80023F5C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_80023F60:
    // 0x80023F60: lbu         $t6, 0x30($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X30);
    // 0x80023F64: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x80023F68: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80023F6C: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80023F70: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x80023F74: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x80023F78: or          $t6, $t8, $a3
    ctx->r14 = ctx->r24 | ctx->r7;
    // 0x80023F7C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80023F80: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    // 0x80023F84: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023F88: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80023F8C: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80023F90: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80023F94: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023F98: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80023F9C: lw          $t8, 0x1FC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1FC);
    // 0x80023FA0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80023FA4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023FA8: lbu         $t6, 0x30($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X30);
    // 0x80023FAC: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x80023FB0: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80023FB4: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x80023FB8: or          $t8, $t9, $t3
    ctx->r24 = ctx->r25 | ctx->r11;
    // 0x80023FBC: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x80023FC0: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80023FC4: or          $t6, $t8, $a3
    ctx->r14 = ctx->r24 | ctx->r7;
    // 0x80023FC8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80023FCC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80023FD0: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80023FD4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80023FD8: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80023FDC: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x80023FE0: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80023FE4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x80023FE8: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x80023FEC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80023FF0: multu       $s0, $t6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80023FF4: mflo        $v0
    ctx->r2 = lo;
    // 0x80023FF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80023FFC: sra         $v0, $v0, 1
    ctx->r2 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80024000: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80024004: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x80024008: beq         $at, $zero, L_80024018
    if (ctx->r1 == 0) {
        // 0x8002400C: nop
    
            goto L_80024018;
    }
    // 0x8002400C: nop

    // 0x80024010: b           L_80024018
    // 0x80024014: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80024018;
    // 0x80024014: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80024018:
    // 0x80024018: bgez        $t0, L_80024028
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8002401C: sra         $t2, $t0, 3
        ctx->r10 = S32(SIGNED(ctx->r8) >> 3);
            goto L_80024028;
    }
    // 0x8002401C: sra         $t2, $t0, 3
    ctx->r10 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80024020: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x80024024: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
L_80024028:
    // 0x80024028: bgtz        $t2, L_80024038
    if (SIGNED(ctx->r10) > 0) {
        // 0x8002402C: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80024038;
    }
    // 0x8002402C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024030: b           L_8002403C
    // 0x80024034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_8002403C;
    // 0x80024034: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80024038:
    // 0x80024038: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_8002403C:
    // 0x8002403C: bgtz        $t2, L_8002404C
    if (SIGNED(ctx->r10) > 0) {
        // 0x80024040: addiu       $t7, $a1, 0x7FF
        ctx->r15 = ADD32(ctx->r5, 0X7FF);
            goto L_8002404C;
    }
    // 0x80024040: addiu       $t7, $a1, 0x7FF
    ctx->r15 = ADD32(ctx->r5, 0X7FF);
    // 0x80024044: b           L_80024050
    // 0x80024048: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024050;
    // 0x80024048: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8002404C:
    // 0x8002404C: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_80024050:
    // 0x80024050: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x80024054: bne         $a0, $zero, L_80024060
    if (ctx->r4 != 0) {
        // 0x80024058: nop
    
            goto L_80024060;
    }
    // 0x80024058: nop

    // 0x8002405C: break       7
    do_break(2147631196);
L_80024060:
    // 0x80024060: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024064: bne         $a0, $at, L_80024078
    if (ctx->r4 != ctx->r1) {
        // 0x80024068: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024078;
    }
    // 0x80024068: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8002406C: bne         $t7, $at, L_80024078
    if (ctx->r15 != ctx->r1) {
        // 0x80024070: nop
    
            goto L_80024078;
    }
    // 0x80024070: nop

    // 0x80024074: break       6
    do_break(2147631220);
L_80024078:
    // 0x80024078: mflo        $t9
    ctx->r25 = lo;
    // 0x8002407C: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80024080: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80024084: andi        $t7, $a2, 0xFFF
    ctx->r15 = ctx->r6 & 0XFFF;
    // 0x80024088: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8002408C: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80024090: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80024094: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x80024098: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8002409C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800240A0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800240A4: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    // 0x800240A8: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x800240AC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800240B0: lbu         $t9, 0x30($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X30);
    // 0x800240B4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800240B8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800240BC: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x800240C0: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800240C4: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x800240C8: addiu       $t8, $t0, 0x7
    ctx->r24 = ADD32(ctx->r8, 0X7);
    // 0x800240CC: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800240D0: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800240D4: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x800240D8: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x800240DC: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x800240E0: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x800240E4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800240E8: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800240EC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800240F0: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x800240F4: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x800240F8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800240FC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80024100: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80024104: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x80024108: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8002410C: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x80024110: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x80024114: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80024118: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8002411C: or          $t7, $t9, $t8
    ctx->r15 = ctx->r25 | ctx->r24;
    // 0x80024120: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80024124: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024128: lw          $t0, 0x1FC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1FC);
L_8002412C:
    // 0x8002412C: lw          $t6, 0x200($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X200);
    // 0x80024130: b           L_80024E2C
    // 0x80024134: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
        goto L_80024E2C;
    // 0x80024134: lw          $v0, 0x8($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X8);
L_80024138:
    // 0x80024138: lbu         $a0, 0x30($a2)
    ctx->r4 = MEM_BU(ctx->r6, 0X30);
    // 0x8002413C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024140: bnel        $a0, $at, L_800247D8
    if (ctx->r4 != ctx->r1) {
        // 0x80024144: lhu         $t6, 0x14($a2)
        ctx->r14 = MEM_HU(ctx->r6, 0X14);
            goto L_800247D8;
    }
    goto skip_7;
    // 0x80024144: lhu         $t6, 0x14($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X14);
    skip_7:
    // 0x80024148: lhu         $t9, 0x14($a2)
    ctx->r25 = MEM_HU(ctx->r6, 0X14);
    // 0x8002414C: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x80024150: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024154: andi        $t8, $t9, 0x200
    ctx->r24 = ctx->r25 & 0X200;
    // 0x80024158: beq         $t8, $zero, L_800242A8
    if (ctx->r24 == 0) {
        // 0x8002415C: lw          $t0, 0x200($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X200);
            goto L_800242A8;
    }
    // 0x8002415C: lw          $t0, 0x200($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X200);
    // 0x80024160: andi        $t7, $a0, 0x7
    ctx->r15 = ctx->r4 & 0X7;
    // 0x80024164: sll         $t6, $t7, 21
    ctx->r14 = S32(ctx->r15 << 21);
    // 0x80024168: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x8002416C: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x80024170: or          $t8, $t9, $a3
    ctx->r24 = ctx->r25 | ctx->r7;
    // 0x80024174: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80024178: lw          $t7, 0x200($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X200);
    // 0x8002417C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024180: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80024184: lw          $t6, 0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, 0X8);
    // 0x80024188: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8002418C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024190: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80024194: lbu         $t9, 0x30($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X30);
    // 0x80024198: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x8002419C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800241A0: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x800241A4: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x800241A8: or          $t6, $t7, $t3
    ctx->r14 = ctx->r15 | ctx->r11;
    // 0x800241AC: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x800241B0: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x800241B4: or          $t9, $t6, $a3
    ctx->r25 = ctx->r14 | ctx->r7;
    // 0x800241B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800241BC: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800241C0: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x800241C4: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x800241C8: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x800241CC: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800241D0: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x800241D4: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800241D8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800241DC: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800241E0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800241E4: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x800241E8: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800241EC: mflo        $v0
    ctx->r2 = lo;
    // 0x800241F0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800241F4: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800241F8: beq         $at, $zero, L_80024208
    if (ctx->r1 == 0) {
        // 0x800241FC: nop
    
            goto L_80024208;
    }
    // 0x800241FC: nop

    // 0x80024200: b           L_80024208
    // 0x80024204: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80024208;
    // 0x80024204: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80024208:
    // 0x80024208: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8002420C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80024210: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80024214: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x80024218: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8002421C: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024220: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80024224: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80024228: lw          $t9, 0x1FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1FC);
    // 0x8002422C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024230: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80024234: lbu         $t8, 0x30($t9)
    ctx->r24 = MEM_BU(ctx->r25, 0X30);
    // 0x80024238: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002423C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80024240: andi        $t7, $t8, 0x7
    ctx->r15 = ctx->r24 & 0X7;
    // 0x80024244: sll         $t6, $t7, 21
    ctx->r14 = S32(ctx->r15 << 21);
    // 0x80024248: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x8002424C: addiu       $t7, $s0, 0x7
    ctx->r15 = ADD32(ctx->r16, 0X7);
    // 0x80024250: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80024254: or          $t8, $t9, $a3
    ctx->r24 = ctx->r25 | ctx->r7;
    // 0x80024258: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8002425C: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x80024260: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x80024264: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80024268: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002426C: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80024270: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x80024274: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80024278: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x8002427C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80024280: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80024284: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80024288: addiu       $t7, $t0, -0x1
    ctx->r15 = ADD32(ctx->r8, -0X1);
    // 0x8002428C: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x80024290: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80024294: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80024298: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8002429C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800242A0: b           L_80024AF0
    // 0x800242A4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_80024AF0;
    // 0x800242A4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_800242A8:
    // 0x800242A8: lh          $t6, 0xE($t0)
    ctx->r14 = MEM_H(ctx->r8, 0XE);
    // 0x800242AC: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800242B0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800242B4: beq         $t6, $zero, L_80024624
    if (ctx->r14 == 0) {
        // 0x800242B8: andi        $t9, $a0, 0x7
        ctx->r25 = ctx->r4 & 0X7;
            goto L_80024624;
    }
    // 0x800242B8: andi        $t9, $a0, 0x7
    ctx->r25 = ctx->r4 & 0X7;
    // 0x800242BC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800242C0: lui         $t8, 0xFD88
    ctx->r24 = S32(0XFD88 << 16);
    // 0x800242C4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800242C8: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x800242CC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800242D0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800242D4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800242D8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800242DC: lui         $t7, 0xF588
    ctx->r15 = S32(0XF588 << 16);
    // 0x800242E0: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x800242E4: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x800242E8: ori         $t7, $t7, 0x100
    ctx->r15 = ctx->r15 | 0X100;
    // 0x800242EC: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800242F0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800242F4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800242F8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800242FC: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80024300: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80024304: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80024308: or          $a3, $t1, $zero
    ctx->r7 = ctx->r9 | 0;
    // 0x8002430C: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80024310: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80024314: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x80024318: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x8002431C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024320: multu       $s0, $t7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024324: or          $t2, $s0, $zero
    ctx->r10 = ctx->r16 | 0;
    // 0x80024328: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x8002432C: subu        $t5, $t5, $s0
    ctx->r13 = SUB32(ctx->r13, ctx->r16);
    // 0x80024330: mflo        $v1
    ctx->r3 = lo;
    // 0x80024334: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x80024338: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8002433C: beq         $at, $zero, L_8002434C
    if (ctx->r1 == 0) {
        // 0x80024340: nop
    
            goto L_8002434C;
    }
    // 0x80024340: nop

    // 0x80024344: b           L_8002434C
    // 0x80024348: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_8002434C;
    // 0x80024348: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8002434C:
    // 0x8002434C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80024350: bgez        $t2, L_8002435C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80024354: addu        $at, $t2, $zero
        ctx->r1 = ADD32(ctx->r10, 0);
            goto L_8002435C;
    }
    // 0x80024354: addu        $at, $t2, $zero
    ctx->r1 = ADD32(ctx->r10, 0);
    // 0x80024358: addiu       $at, $t2, 0x7
    ctx->r1 = ADD32(ctx->r10, 0X7);
L_8002435C:
    // 0x8002435C: sra         $t2, $at, 3
    ctx->r10 = S32(SIGNED(ctx->r1) >> 3);
    // 0x80024360: bgtz        $t2, L_80024370
    if (SIGNED(ctx->r10) > 0) {
        // 0x80024364: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_80024370;
    }
    // 0x80024364: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024368: b           L_80024374
    // 0x8002436C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80024374;
    // 0x8002436C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80024370:
    // 0x80024370: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_80024374:
    // 0x80024374: bgtz        $t2, L_80024384
    if (SIGNED(ctx->r10) > 0) {
        // 0x80024378: addiu       $t6, $a1, 0x7FF
        ctx->r14 = ADD32(ctx->r5, 0X7FF);
            goto L_80024384;
    }
    // 0x80024378: addiu       $t6, $a1, 0x7FF
    ctx->r14 = ADD32(ctx->r5, 0X7FF);
    // 0x8002437C: b           L_80024388
    // 0x80024380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024388;
    // 0x80024380: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024384:
    // 0x80024384: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_80024388:
    // 0x80024388: div         $zero, $t6, $a0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r4)));
    // 0x8002438C: bne         $a0, $zero, L_80024398
    if (ctx->r4 != 0) {
        // 0x80024390: nop
    
            goto L_80024398;
    }
    // 0x80024390: nop

    // 0x80024394: break       7
    do_break(2147632020);
L_80024398:
    // 0x80024398: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002439C: bne         $a0, $at, L_800243B0
    if (ctx->r4 != ctx->r1) {
        // 0x800243A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800243B0;
    }
    // 0x800243A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800243A4: bne         $t6, $at, L_800243B0
    if (ctx->r14 != ctx->r1) {
        // 0x800243A8: nop
    
            goto L_800243B0;
    }
    // 0x800243A8: nop

    // 0x800243AC: break       6
    do_break(2147632044);
L_800243B0:
    // 0x800243B0: mflo        $t8
    ctx->r24 = lo;
    // 0x800243B4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800243B8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800243BC: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x800243C0: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x800243C4: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x800243C8: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800243CC: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800243D0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800243D4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800243D8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800243DC: lw          $t8, 0x200($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X200);
    // 0x800243E0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800243E4: bgez        $v1, L_800243F4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800243E8: sra         $t7, $v1, 1
        ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800243F4;
    }
    // 0x800243E8: sra         $t7, $v1, 1
    ctx->r15 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800243EC: addiu       $at, $v1, 0x1
    ctx->r1 = ADD32(ctx->r3, 0X1);
    // 0x800243F0: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800243F4:
    // 0x800243F4: lh          $t9, 0xE($t8)
    ctx->r25 = MEM_H(ctx->r24, 0XE);
    // 0x800243F8: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800243FC: multu       $t7, $t9
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024400: lw          $t7, 0x8($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X8);
    // 0x80024404: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x80024408: addiu       $t3, $t8, -0x2
    ctx->r11 = ADD32(ctx->r24, -0X2);
    // 0x8002440C: mflo        $t6
    ctx->r14 = lo;
    // 0x80024410: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80024414: sw          $t9, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->r25;
    // 0x80024418: bgez        $t8, L_80024428
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8002441C: sra         $t4, $t8, 1
        ctx->r12 = S32(SIGNED(ctx->r24) >> 1);
            goto L_80024428;
    }
    // 0x8002441C: sra         $t4, $t8, 1
    ctx->r12 = S32(SIGNED(ctx->r24) >> 1);
    // 0x80024420: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x80024424: sra         $t4, $at, 1
    ctx->r12 = S32(SIGNED(ctx->r1) >> 1);
L_80024428:
    // 0x80024428: bltzl       $t4, L_8002459C
    if (SIGNED(ctx->r12) < 0) {
        // 0x8002442C: lw          $t7, 0x1FC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X1FC);
            goto L_8002459C;
    }
    goto skip_8;
    // 0x8002442C: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    skip_8:
    // 0x80024430: bgez        $s0, L_80024440
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80024434: sra         $t7, $s0, 3
        ctx->r15 = S32(SIGNED(ctx->r16) >> 3);
            goto L_80024440;
    }
    // 0x80024434: sra         $t7, $s0, 3
    ctx->r15 = S32(SIGNED(ctx->r16) >> 3);
    // 0x80024438: addiu       $at, $s0, 0x7
    ctx->r1 = ADD32(ctx->r16, 0X7);
    // 0x8002443C: sra         $t7, $at, 3
    ctx->r15 = S32(SIGNED(ctx->r1) >> 3);
L_80024440:
    // 0x80024440: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
L_80024444:
    // 0x80024444: subu        $t6, $t4, $t0
    ctx->r14 = SUB32(ctx->r12, ctx->r8);
    // 0x80024448: addiu       $t9, $t6, -0x2
    ctx->r25 = ADD32(ctx->r14, -0X2);
    // 0x8002444C: multu       $t9, $s0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024450: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80024454: lw          $t8, 0x118($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X118);
    // 0x80024458: or          $a3, $t5, $zero
    ctx->r7 = ctx->r13 | 0;
    // 0x8002445C: lui         $t9, 0xFD88
    ctx->r25 = S32(0XFD88 << 16);
    // 0x80024460: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x80024464: mflo        $t7
    ctx->r15 = lo;
    // 0x80024468: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8002446C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80024470: multu       $t6, $t3
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024474: lui         $t6, 0x708
    ctx->r14 = S32(0X708 << 16);
    // 0x80024478: addiu       $t3, $t3, -0x2
    ctx->r11 = ADD32(ctx->r11, -0X2);
    // 0x8002447C: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80024480: mflo        $v1
    ctx->r3 = lo;
    // 0x80024484: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x80024488: bgez        $v1, L_800244A0
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8002448C: negu        $v0, $v1
        ctx->r2 = SUB32(0, ctx->r3);
            goto L_800244A0;
    }
    // 0x8002448C: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80024490: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x80024494: addu        $a1, $a0, $v0
    ctx->r5 = ADD32(ctx->r4, ctx->r2);
    // 0x80024498: subu        $a3, $t5, $v0
    ctx->r7 = SUB32(ctx->r13, ctx->r2);
    // 0x8002449C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800244A0:
    // 0x800244A0: bne         $t0, $zero, L_800244AC
    if (ctx->r8 != 0) {
        // 0x800244A4: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800244AC;
    }
    // 0x800244A4: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800244A8: sll         $a3, $s0, 1
    ctx->r7 = S32(ctx->r16 << 1);
L_800244AC:
    // 0x800244AC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800244B0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800244B4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800244B8: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x800244BC: andi        $t7, $a2, 0x1FF
    ctx->r15 = ctx->r6 & 0X1FF;
    // 0x800244C0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800244C4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800244C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800244CC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800244D0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800244D4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800244D8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800244DC: addiu       $v0, $a3, -0x1
    ctx->r2 = ADD32(ctx->r7, -0X1);
    // 0x800244E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800244E4: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x800244E8: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800244EC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800244F0: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800244F4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800244F8: beq         $at, $zero, L_80024508
    if (ctx->r1 == 0) {
        // 0x800244FC: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_80024508;
    }
    // 0x800244FC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024500: b           L_8002450C
    // 0x80024504: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_8002450C;
    // 0x80024504: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80024508:
    // 0x80024508: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
L_8002450C:
    // 0x8002450C: bgtz        $t2, L_8002451C
    if (SIGNED(ctx->r10) > 0) {
        // 0x80024510: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_8002451C;
    }
    // 0x80024510: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024514: b           L_80024520
    // 0x80024518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80024520;
    // 0x80024518: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8002451C:
    // 0x8002451C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
L_80024520:
    // 0x80024520: bgtz        $t2, L_80024530
    if (SIGNED(ctx->r10) > 0) {
        // 0x80024524: addiu       $t8, $a1, 0x7FF
        ctx->r24 = ADD32(ctx->r5, 0X7FF);
            goto L_80024530;
    }
    // 0x80024524: addiu       $t8, $a1, 0x7FF
    ctx->r24 = ADD32(ctx->r5, 0X7FF);
    // 0x80024528: b           L_80024534
    // 0x8002452C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024534;
    // 0x8002452C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024530:
    // 0x80024530: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
L_80024534:
    // 0x80024534: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x80024538: bne         $a0, $zero, L_80024544
    if (ctx->r4 != 0) {
        // 0x8002453C: nop
    
            goto L_80024544;
    }
    // 0x8002453C: nop

    // 0x80024540: break       7
    do_break(2147632448);
L_80024544:
    // 0x80024544: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024548: bne         $a0, $at, L_8002455C
    if (ctx->r4 != ctx->r1) {
        // 0x8002454C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8002455C;
    }
    // 0x8002454C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024550: bne         $t8, $at, L_8002455C
    if (ctx->r24 != ctx->r1) {
        // 0x80024554: nop
    
            goto L_8002455C;
    }
    // 0x80024554: nop

    // 0x80024558: break       6
    do_break(2147632472);
L_8002455C:
    // 0x8002455C: mflo        $t6
    ctx->r14 = lo;
    // 0x80024560: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80024564: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80024568: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x8002456C: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80024570: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80024574: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80024578: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8002457C: slt         $at, $t4, $t0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x80024580: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80024584: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80024588: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002458C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80024590: beq         $at, $zero, L_80024444
    if (ctx->r1 == 0) {
        // 0x80024594: addiu       $t1, $t1, 0x8
        ctx->r9 = ADD32(ctx->r9, 0X8);
            goto L_80024444;
    }
    // 0x80024594: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024598: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
L_8002459C:
    // 0x8002459C: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800245A0: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800245A4: lbu         $t6, 0x30($t7)
    ctx->r14 = MEM_BU(ctx->r15, 0X30);
    // 0x800245A8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800245AC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800245B0: andi        $t9, $t6, 0x7
    ctx->r25 = ctx->r14 & 0X7;
    // 0x800245B4: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x800245B8: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800245BC: or          $t7, $t8, $t3
    ctx->r15 = ctx->r24 | ctx->r11;
    // 0x800245C0: or          $t6, $t7, $a3
    ctx->r14 = ctx->r15 | ctx->r7;
    // 0x800245C4: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x800245C8: sra         $t7, $t8, 3
    ctx->r15 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800245CC: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x800245D0: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x800245D4: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800245D8: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x800245DC: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x800245E0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800245E4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800245E8: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x800245EC: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800245F0: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800245F4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800245F8: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800245FC: lw          $t8, 0x1D4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1D4);
    // 0x80024600: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80024604: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80024608: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x8002460C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x80024610: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80024614: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x80024618: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8002461C: b           L_80024AF0
    // 0x80024620: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_80024AF0;
    // 0x80024620: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_80024624:
    // 0x80024624: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x80024628: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x8002462C: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x80024630: or          $t7, $t8, $a3
    ctx->r15 = ctx->r24 | ctx->r7;
    // 0x80024634: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80024638: lw          $t9, 0x8($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X8);
    // 0x8002463C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024640: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80024644: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80024648: lbu         $t6, 0x30($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X30);
    // 0x8002464C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80024650: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024654: andi        $t8, $t6, 0x7
    ctx->r24 = ctx->r14 & 0X7;
    // 0x80024658: sll         $t7, $t8, 21
    ctx->r15 = S32(ctx->r24 << 21);
    // 0x8002465C: or          $t9, $t7, $t3
    ctx->r25 = ctx->r15 | ctx->r11;
    // 0x80024660: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x80024664: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80024668: or          $t6, $t9, $a3
    ctx->r14 = ctx->r25 | ctx->r7;
    // 0x8002466C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80024670: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80024674: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80024678: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002467C: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x80024680: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80024684: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80024688: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8002468C: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80024690: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80024694: lw          $t6, 0x1D4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1D4);
    // 0x80024698: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002469C: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x800246A0: multu       $s0, $t6
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800246A4: mflo        $v0
    ctx->r2 = lo;
    // 0x800246A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800246AC: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800246B0: beq         $at, $zero, L_800246C0
    if (ctx->r1 == 0) {
        // 0x800246B4: nop
    
            goto L_800246C0;
    }
    // 0x800246B4: nop

    // 0x800246B8: b           L_800246C0
    // 0x800246BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800246C0;
    // 0x800246BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800246C0:
    // 0x800246C0: sll         $v0, $s0, 1
    ctx->r2 = S32(ctx->r16 << 1);
    // 0x800246C4: bgez        $v0, L_800246D0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800246C8: addu        $at, $v0, $zero
        ctx->r1 = ADD32(ctx->r2, 0);
            goto L_800246D0;
    }
    // 0x800246C8: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x800246CC: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
L_800246D0:
    // 0x800246D0: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
    // 0x800246D4: bgtz        $v0, L_800246E4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800246D8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800246E4;
    }
    // 0x800246D8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800246DC: b           L_800246E4
    // 0x800246E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_800246E4;
    // 0x800246E0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800246E4:
    // 0x800246E4: bgtz        $v0, L_800246F4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800246E8: addiu       $t8, $a1, 0x7FF
        ctx->r24 = ADD32(ctx->r5, 0X7FF);
            goto L_800246F4;
    }
    // 0x800246E8: addiu       $t8, $a1, 0x7FF
    ctx->r24 = ADD32(ctx->r5, 0X7FF);
    // 0x800246EC: b           L_800246F8
    // 0x800246F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_800246F8;
    // 0x800246F0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_800246F4:
    // 0x800246F4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800246F8:
    // 0x800246F8: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x800246FC: bne         $a0, $zero, L_80024708
    if (ctx->r4 != 0) {
        // 0x80024700: nop
    
            goto L_80024708;
    }
    // 0x80024700: nop

    // 0x80024704: break       7
    do_break(2147632900);
L_80024708:
    // 0x80024708: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002470C: bne         $a0, $at, L_80024720
    if (ctx->r4 != ctx->r1) {
        // 0x80024710: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024720;
    }
    // 0x80024710: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024714: bne         $t8, $at, L_80024720
    if (ctx->r24 != ctx->r1) {
        // 0x80024718: nop
    
            goto L_80024720;
    }
    // 0x80024718: nop

    // 0x8002471C: break       6
    do_break(2147632924);
L_80024720:
    // 0x80024720: mflo        $t7
    ctx->r15 = lo;
    // 0x80024724: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80024728: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8002472C: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x80024730: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80024734: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80024738: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8002473C: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x80024740: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024744: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80024748: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8002474C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80024750: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    // 0x80024754: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024758: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x8002475C: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x80024760: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024764: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024768: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x8002476C: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x80024770: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x80024774: addiu       $t9, $s0, 0x7
    ctx->r25 = ADD32(ctx->r16, 0X7);
    // 0x80024778: sra         $t8, $t9, 3
    ctx->r24 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8002477C: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x80024780: andi        $t6, $t8, 0x1FF
    ctx->r14 = ctx->r24 & 0X1FF;
    // 0x80024784: sll         $t9, $t6, 9
    ctx->r25 = S32(ctx->r14 << 9);
    // 0x80024788: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8002478C: lui         $t6, 0x8
    ctx->r14 = S32(0X8 << 16);
    // 0x80024790: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80024794: ori         $t6, $t6, 0x200
    ctx->r14 = ctx->r14 | 0X200;
    // 0x80024798: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8002479C: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x800247A0: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x800247A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800247A8: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x800247AC: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800247B0: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x800247B4: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800247B8: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800247BC: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800247C0: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x800247C4: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800247C8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800247CC: b           L_80024AF0
    // 0x800247D0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_80024AF0;
    // 0x800247D0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800247D4: lhu         $t6, 0x14($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X14);
L_800247D8:
    // 0x800247D8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800247DC: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800247E0: andi        $t7, $t6, 0x200
    ctx->r15 = ctx->r14 & 0X200;
    // 0x800247E4: beq         $t7, $zero, L_80024940
    if (ctx->r15 == 0) {
        // 0x800247E8: lui         $t3, 0xF500
        ctx->r11 = S32(0XF500 << 16);
            goto L_80024940;
    }
    // 0x800247E8: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x800247EC: andi        $t9, $a0, 0x7
    ctx->r25 = ctx->r4 & 0X7;
    // 0x800247F0: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x800247F4: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x800247F8: lui         $a3, 0x10
    ctx->r7 = S32(0X10 << 16);
    // 0x800247FC: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x80024800: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x80024804: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024808: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002480C: lw          $t9, 0x200($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X200);
    // 0x80024810: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024814: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80024818: lw          $t8, 0x8($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X8);
    // 0x8002481C: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80024820: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024824: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80024828: lbu         $t6, 0x30($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X30);
    // 0x8002482C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80024830: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024834: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80024838: sll         $t9, $t7, 21
    ctx->r25 = S32(ctx->r15 << 21);
    // 0x8002483C: or          $t8, $t9, $t3
    ctx->r24 = ctx->r25 | ctx->r11;
    // 0x80024840: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x80024844: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80024848: or          $t6, $t8, $a3
    ctx->r14 = ctx->r24 | ctx->r7;
    // 0x8002484C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80024850: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80024854: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80024858: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8002485C: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x80024860: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x80024864: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x80024868: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002486C: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80024870: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80024874: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024878: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x8002487C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80024880: mflo        $v0
    ctx->r2 = lo;
    // 0x80024884: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80024888: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x8002488C: beq         $at, $zero, L_8002489C
    if (ctx->r1 == 0) {
        // 0x80024890: nop
    
            goto L_8002489C;
    }
    // 0x80024890: nop

    // 0x80024894: b           L_8002489C
    // 0x80024898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_8002489C;
    // 0x80024898: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_8002489C:
    // 0x8002489C: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x800248A0: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x800248A4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800248A8: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800248AC: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x800248B0: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800248B4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800248B8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800248BC: lw          $t6, 0x1FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1FC);
    // 0x800248C0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800248C4: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x800248C8: lbu         $t7, 0x30($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X30);
    // 0x800248CC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800248D0: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x800248D4: andi        $t9, $t7, 0x7
    ctx->r25 = ctx->r15 & 0X7;
    // 0x800248D8: sll         $t8, $t9, 21
    ctx->r24 = S32(ctx->r25 << 21);
    // 0x800248DC: or          $t6, $t8, $t3
    ctx->r14 = ctx->r24 | ctx->r11;
    // 0x800248E0: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x800248E4: addiu       $t8, $t9, 0x7
    ctx->r24 = ADD32(ctx->r25, 0X7);
    // 0x800248E8: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x800248EC: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x800248F0: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x800248F4: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x800248F8: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x800248FC: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80024900: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80024904: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80024908: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8002490C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80024910: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80024914: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80024918: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8002491C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80024920: addiu       $t8, $t0, -0x1
    ctx->r24 = ADD32(ctx->r8, -0X1);
    // 0x80024924: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x80024928: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8002492C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80024930: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x80024934: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80024938: b           L_80024AF0
    // 0x8002493C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_80024AF0;
    // 0x8002493C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_80024940:
    // 0x80024940: andi        $t6, $a0, 0x7
    ctx->r14 = ctx->r4 & 0X7;
    // 0x80024944: sll         $t7, $t6, 21
    ctx->r15 = S32(ctx->r14 << 21);
    // 0x80024948: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x8002494C: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80024950: or          $t8, $t9, $a3
    ctx->r24 = ctx->r25 | ctx->r7;
    // 0x80024954: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80024958: lw          $t6, 0x200($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X200);
    // 0x8002495C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024960: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80024964: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x80024968: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002496C: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80024970: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80024974: lbu         $t9, 0x30($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X30);
    // 0x80024978: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x8002497C: or          $t2, $t1, $zero
    ctx->r10 = ctx->r9 | 0;
    // 0x80024980: andi        $t8, $t9, 0x7
    ctx->r24 = ctx->r25 & 0X7;
    // 0x80024984: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x80024988: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x8002498C: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x80024990: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80024994: or          $t9, $t7, $a3
    ctx->r25 = ctx->r15 | ctx->r7;
    // 0x80024998: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8002499C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800249A0: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x800249A4: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x800249A8: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x800249AC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x800249B0: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x800249B4: lw          $t9, 0x1D4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1D4);
    // 0x800249B8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x800249BC: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x800249C0: multu       $s0, $t9
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800249C4: sll         $t0, $s0, 1
    ctx->r8 = S32(ctx->r16 << 1);
    // 0x800249C8: mflo        $v0
    ctx->r2 = lo;
    // 0x800249CC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800249D0: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x800249D4: beq         $at, $zero, L_800249E4
    if (ctx->r1 == 0) {
        // 0x800249D8: nop
    
            goto L_800249E4;
    }
    // 0x800249D8: nop

    // 0x800249DC: b           L_800249E4
    // 0x800249E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_800249E4;
    // 0x800249E0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800249E4:
    // 0x800249E4: bgez        $t0, L_800249F4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800249E8: sra         $v0, $t0, 3
        ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
            goto L_800249F4;
    }
    // 0x800249E8: sra         $v0, $t0, 3
    ctx->r2 = S32(SIGNED(ctx->r8) >> 3);
    // 0x800249EC: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x800249F0: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800249F4:
    // 0x800249F4: bgtz        $v0, L_80024A04
    if (SIGNED(ctx->r2) > 0) {
        // 0x800249F8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80024A04;
    }
    // 0x800249F8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800249FC: b           L_80024A04
    // 0x80024A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80024A04;
    // 0x80024A00: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80024A04:
    // 0x80024A04: bgtz        $v0, L_80024A14
    if (SIGNED(ctx->r2) > 0) {
        // 0x80024A08: addiu       $t8, $a1, 0x7FF
        ctx->r24 = ADD32(ctx->r5, 0X7FF);
            goto L_80024A14;
    }
    // 0x80024A08: addiu       $t8, $a1, 0x7FF
    ctx->r24 = ADD32(ctx->r5, 0X7FF);
    // 0x80024A0C: b           L_80024A18
    // 0x80024A10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024A18;
    // 0x80024A10: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024A14:
    // 0x80024A14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80024A18:
    // 0x80024A18: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x80024A1C: bne         $a0, $zero, L_80024A28
    if (ctx->r4 != 0) {
        // 0x80024A20: nop
    
            goto L_80024A28;
    }
    // 0x80024A20: nop

    // 0x80024A24: break       7
    do_break(2147633700);
L_80024A28:
    // 0x80024A28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024A2C: bne         $a0, $at, L_80024A40
    if (ctx->r4 != ctx->r1) {
        // 0x80024A30: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024A40;
    }
    // 0x80024A30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024A34: bne         $t8, $at, L_80024A40
    if (ctx->r24 != ctx->r1) {
        // 0x80024A38: nop
    
            goto L_80024A40;
    }
    // 0x80024A38: nop

    // 0x80024A3C: break       6
    do_break(2147633724);
L_80024A40:
    // 0x80024A40: mflo        $t6
    ctx->r14 = lo;
    // 0x80024A44: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80024A48: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80024A4C: andi        $t8, $a2, 0xFFF
    ctx->r24 = ctx->r6 & 0XFFF;
    // 0x80024A50: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x80024A54: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80024A58: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x80024A5C: sw          $t7, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r15;
    // 0x80024A60: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024A64: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x80024A68: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80024A6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80024A70: lw          $t9, 0x1FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1FC);
    // 0x80024A74: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024A78: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80024A7C: lbu         $t6, 0x30($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X30);
    // 0x80024A80: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024A84: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024A88: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80024A8C: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x80024A90: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x80024A94: addiu       $t7, $t0, 0x7
    ctx->r15 = ADD32(ctx->r8, 0X7);
    // 0x80024A98: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x80024A9C: or          $t6, $t9, $a3
    ctx->r14 = ctx->r25 | ctx->r7;
    // 0x80024AA0: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x80024AA4: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x80024AA8: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80024AAC: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80024AB0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80024AB4: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80024AB8: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80024ABC: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x80024AC0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x80024AC4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80024AC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80024ACC: lw          $t7, 0x1D4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1D4);
    // 0x80024AD0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x80024AD4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x80024AD8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80024ADC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80024AE0: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80024AE4: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80024AE8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80024AEC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_80024AF0:
    // 0x80024AF0: lw          $t9, 0x200($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X200);
    // 0x80024AF4: b           L_80024E2C
    // 0x80024AF8: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
        goto L_80024E2C;
    // 0x80024AF8: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
L_80024AFC:
    // 0x80024AFC: lhu         $t6, 0x14($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X14);
    // 0x80024B00: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024B04: lui         $a3, 0x18
    ctx->r7 = S32(0X18 << 16);
    // 0x80024B08: andi        $t7, $t6, 0x200
    ctx->r15 = ctx->r14 & 0X200;
    // 0x80024B0C: beql        $t7, $zero, L_80024C6C
    if (ctx->r15 == 0) {
        // 0x80024B10: lbu         $t7, 0x30($a2)
        ctx->r15 = MEM_BU(ctx->r6, 0X30);
            goto L_80024C6C;
    }
    goto skip_9;
    // 0x80024B10: lbu         $t7, 0x30($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X30);
    skip_9:
    // 0x80024B14: lbu         $t8, 0x30($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0X30);
    // 0x80024B18: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x80024B1C: lui         $a3, 0x18
    ctx->r7 = S32(0X18 << 16);
    // 0x80024B20: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x80024B24: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x80024B28: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x80024B2C: or          $t8, $t7, $a3
    ctx->r24 = ctx->r15 | ctx->r7;
    // 0x80024B30: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80024B34: lw          $t9, 0x200($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X200);
    // 0x80024B38: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024B3C: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80024B40: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x80024B44: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80024B48: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024B4C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80024B50: lbu         $t7, 0x30($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X30);
    // 0x80024B54: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80024B58: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024B5C: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80024B60: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80024B64: or          $t6, $t9, $t3
    ctx->r14 = ctx->r25 | ctx->r11;
    // 0x80024B68: lui         $t8, 0x708
    ctx->r24 = S32(0X708 << 16);
    // 0x80024B6C: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80024B70: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x80024B74: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80024B78: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80024B7C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x80024B80: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x80024B84: lw          $t0, 0x1D4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1D4);
    // 0x80024B88: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80024B8C: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x80024B90: multu       $s0, $t0
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024B94: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    // 0x80024B98: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x80024B9C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024BA0: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x80024BA4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80024BA8: mflo        $v0
    ctx->r2 = lo;
    // 0x80024BAC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80024BB0: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x80024BB4: beq         $at, $zero, L_80024BC4
    if (ctx->r1 == 0) {
        // 0x80024BB8: nop
    
            goto L_80024BC4;
    }
    // 0x80024BB8: nop

    // 0x80024BBC: b           L_80024BC4
    // 0x80024BC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_80024BC4;
    // 0x80024BC0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80024BC4:
    // 0x80024BC4: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x80024BC8: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x80024BCC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80024BD0: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80024BD4: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x80024BD8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024BDC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80024BE0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80024BE4: lw          $t7, 0x1FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1FC);
    // 0x80024BE8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024BEC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80024BF0: lbu         $t8, 0x30($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X30);
    // 0x80024BF4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024BF8: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x80024BFC: andi        $t9, $t8, 0x7
    ctx->r25 = ctx->r24 & 0X7;
    // 0x80024C00: sll         $t6, $t9, 21
    ctx->r14 = S32(ctx->r25 << 21);
    // 0x80024C04: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x80024C08: sll         $t9, $s0, 1
    ctx->r25 = S32(ctx->r16 << 1);
    // 0x80024C0C: addiu       $t6, $t9, 0x7
    ctx->r14 = ADD32(ctx->r25, 0X7);
    // 0x80024C10: or          $t8, $t7, $a3
    ctx->r24 = ctx->r15 | ctx->r7;
    // 0x80024C14: sra         $t7, $t6, 3
    ctx->r15 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80024C18: andi        $t9, $t7, 0x1FF
    ctx->r25 = ctx->r15 & 0X1FF;
    // 0x80024C1C: sll         $t6, $t9, 9
    ctx->r14 = S32(ctx->r25 << 9);
    // 0x80024C20: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x80024C24: lui         $t9, 0x8
    ctx->r25 = S32(0X8 << 16);
    // 0x80024C28: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80024C2C: ori         $t9, $t9, 0x200
    ctx->r25 = ctx->r25 | 0X200;
    // 0x80024C30: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x80024C34: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80024C38: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80024C3C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80024C40: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x80024C44: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x80024C48: addiu       $t6, $t0, -0x1
    ctx->r14 = ADD32(ctx->r8, -0X1);
    // 0x80024C4C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80024C50: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x80024C54: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x80024C58: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80024C5C: sw          $t6, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r14;
    // 0x80024C60: b           L_80024E24
    // 0x80024C64: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
        goto L_80024E24;
    // 0x80024C64: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024C68: lbu         $t7, 0x30($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X30);
L_80024C6C:
    // 0x80024C6C: lui         $at, 0xFD00
    ctx->r1 = S32(0XFD00 << 16);
    // 0x80024C70: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024C74: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80024C78: sll         $t9, $t8, 21
    ctx->r25 = S32(ctx->r24 << 21);
    // 0x80024C7C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80024C80: or          $t7, $t6, $a3
    ctx->r15 = ctx->r14 | ctx->r7;
    // 0x80024C84: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80024C88: lw          $t8, 0x200($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X200);
    // 0x80024C8C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024C90: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80024C94: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x80024C98: lui         $t3, 0xF500
    ctx->r11 = S32(0XF500 << 16);
    // 0x80024C9C: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024CA0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80024CA4: lbu         $t6, 0x30($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X30);
    // 0x80024CA8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80024CAC: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024CB0: andi        $t7, $t6, 0x7
    ctx->r15 = ctx->r14 & 0X7;
    // 0x80024CB4: sll         $t8, $t7, 21
    ctx->r24 = S32(ctx->r15 << 21);
    // 0x80024CB8: or          $t9, $t8, $t3
    ctx->r25 = ctx->r24 | ctx->r11;
    // 0x80024CBC: lui         $t7, 0x708
    ctx->r15 = S32(0X708 << 16);
    // 0x80024CC0: ori         $t7, $t7, 0x200
    ctx->r15 = ctx->r15 | 0X200;
    // 0x80024CC4: or          $t6, $t9, $a3
    ctx->r14 = ctx->r25 | ctx->r7;
    // 0x80024CC8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80024CCC: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x80024CD0: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x80024CD4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80024CD8: lw          $t2, 0x1D4($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X1D4);
    // 0x80024CDC: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x80024CE0: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x80024CE4: multu       $s0, $t2
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80024CE8: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x80024CEC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80024CF0: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024CF4: addiu       $a2, $zero, 0x7FF
    ctx->r6 = ADD32(0, 0X7FF);
    // 0x80024CF8: mflo        $v0
    ctx->r2 = lo;
    // 0x80024CFC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80024D00: slti        $at, $v0, 0x7FF
    ctx->r1 = SIGNED(ctx->r2) < 0X7FF ? 1 : 0;
    // 0x80024D04: beq         $at, $zero, L_80024D14
    if (ctx->r1 == 0) {
        // 0x80024D08: nop
    
            goto L_80024D14;
    }
    // 0x80024D08: nop

    // 0x80024D0C: b           L_80024D14
    // 0x80024D10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80024D14;
    // 0x80024D10: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80024D14:
    // 0x80024D14: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x80024D18: bgez        $v0, L_80024D24
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80024D1C: addu        $at, $v0, $zero
        ctx->r1 = ADD32(ctx->r2, 0);
            goto L_80024D24;
    }
    // 0x80024D1C: addu        $at, $v0, $zero
    ctx->r1 = ADD32(ctx->r2, 0);
    // 0x80024D20: addiu       $at, $v0, 0x7
    ctx->r1 = ADD32(ctx->r2, 0X7);
L_80024D24:
    // 0x80024D24: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
    // 0x80024D28: bgtz        $v0, L_80024D38
    if (SIGNED(ctx->r2) > 0) {
        // 0x80024D2C: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_80024D38;
    }
    // 0x80024D2C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80024D30: b           L_80024D38
    // 0x80024D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
        goto L_80024D38;
    // 0x80024D34: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80024D38:
    // 0x80024D38: bgtz        $v0, L_80024D48
    if (SIGNED(ctx->r2) > 0) {
        // 0x80024D3C: addiu       $t6, $a1, 0x7FF
        ctx->r14 = ADD32(ctx->r5, 0X7FF);
            goto L_80024D48;
    }
    // 0x80024D3C: addiu       $t6, $a1, 0x7FF
    ctx->r14 = ADD32(ctx->r5, 0X7FF);
    // 0x80024D40: b           L_80024D4C
    // 0x80024D44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_80024D4C;
    // 0x80024D44: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_80024D48:
    // 0x80024D48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_80024D4C:
    // 0x80024D4C: div         $zero, $t6, $a0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r4)));
    // 0x80024D50: bne         $a0, $zero, L_80024D5C
    if (ctx->r4 != 0) {
        // 0x80024D54: nop
    
            goto L_80024D5C;
    }
    // 0x80024D54: nop

    // 0x80024D58: break       7
    do_break(2147634520);
L_80024D5C:
    // 0x80024D5C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80024D60: bne         $a0, $at, L_80024D74
    if (ctx->r4 != ctx->r1) {
        // 0x80024D64: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80024D74;
    }
    // 0x80024D64: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80024D68: bne         $t6, $at, L_80024D74
    if (ctx->r14 != ctx->r1) {
        // 0x80024D6C: nop
    
            goto L_80024D74;
    }
    // 0x80024D6C: nop

    // 0x80024D70: break       6
    do_break(2147634544);
L_80024D74:
    // 0x80024D74: mflo        $t7
    ctx->r15 = lo;
    // 0x80024D78: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x80024D7C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80024D80: andi        $t6, $a2, 0xFFF
    ctx->r14 = ctx->r6 & 0XFFF;
    // 0x80024D84: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80024D88: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x80024D8C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80024D90: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x80024D94: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024D98: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x80024D9C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80024DA0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80024DA4: lw          $t9, 0x1FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1FC);
    // 0x80024DA8: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024DAC: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80024DB0: lbu         $t7, 0x30($t9)
    ctx->r15 = MEM_BU(ctx->r25, 0X30);
    // 0x80024DB4: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
    // 0x80024DB8: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x80024DBC: andi        $t8, $t7, 0x7
    ctx->r24 = ctx->r15 & 0X7;
    // 0x80024DC0: sll         $t6, $t8, 21
    ctx->r14 = S32(ctx->r24 << 21);
    // 0x80024DC4: or          $t9, $t6, $t3
    ctx->r25 = ctx->r14 | ctx->r11;
    // 0x80024DC8: sll         $t8, $s0, 1
    ctx->r24 = S32(ctx->r16 << 1);
    // 0x80024DCC: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x80024DD0: or          $t7, $t9, $a3
    ctx->r15 = ctx->r25 | ctx->r7;
    // 0x80024DD4: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x80024DD8: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x80024DDC: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x80024DE0: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80024DE4: lui         $t8, 0x8
    ctx->r24 = S32(0X8 << 16);
    // 0x80024DE8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80024DEC: ori         $t8, $t8, 0x200
    ctx->r24 = ctx->r24 | 0X200;
    // 0x80024DF0: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x80024DF4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80024DF8: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80024DFC: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80024E00: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x80024E04: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80024E08: addiu       $t6, $t2, -0x1
    ctx->r14 = ADD32(ctx->r10, -0X1);
    // 0x80024E0C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x80024E10: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x80024E14: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80024E18: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x80024E1C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80024E20: addiu       $t1, $t1, 0x8
    ctx->r9 = ADD32(ctx->r9, 0X8);
L_80024E24:
    // 0x80024E24: lw          $t9, 0x200($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X200);
    // 0x80024E28: lw          $v0, 0x8($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X8);
L_80024E2C:
    // 0x80024E2C: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80024E30: sw          $v0, -0x2F90($at)
    MEM_W(-0X2F90, ctx->r1) = ctx->r2;
    // 0x80024E34: addiu       $v0, $sp, 0x1C4
    ctx->r2 = ADD32(ctx->r29, 0X1C4);
L_80024E38:
    // 0x80024E38: lbu         $t8, 0x4($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4);
    // 0x80024E3C: addiu       $t7, $zero, 0xE4
    ctx->r15 = ADD32(0, 0XE4);
    // 0x80024E40: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80024E44: andi        $t6, $t8, 0xFFF8
    ctx->r14 = ctx->r24 & 0XFFF8;
    // 0x80024E48: sb          $t6, 0x4($v0)
    MEM_B(0X4, ctx->r2) = ctx->r14;
    // 0x80024E4C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80024E50: lw          $t7, 0x1EC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1EC);
    // 0x80024E54: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80024E58: srl         $t8, $v1, 12
    ctx->r24 = S32(U32(ctx->r3) >> 12);
    // 0x80024E5C: xor         $t6, $t7, $t8
    ctx->r14 = ctx->r15 ^ ctx->r24;
    // 0x80024E60: sll         $t9, $t6, 20
    ctx->r25 = S32(ctx->r14 << 20);
    // 0x80024E64: srl         $t7, $t9, 8
    ctx->r15 = S32(U32(ctx->r25) >> 8);
    // 0x80024E68: xor         $t8, $t7, $v1
    ctx->r24 = ctx->r15 ^ ctx->r3;
    // 0x80024E6C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80024E70: lw          $t9, 0x1E4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1E4);
    // 0x80024E74: srl         $t7, $a0, 12
    ctx->r15 = S32(U32(ctx->r4) >> 12);
    // 0x80024E78: addiu       $a1, $t1, 0x8
    ctx->r5 = ADD32(ctx->r9, 0X8);
    // 0x80024E7C: xor         $t8, $t9, $t7
    ctx->r24 = ctx->r25 ^ ctx->r15;
    // 0x80024E80: sll         $t6, $t8, 20
    ctx->r14 = S32(ctx->r24 << 20);
    // 0x80024E84: srl         $t9, $t6, 8
    ctx->r25 = S32(U32(ctx->r14) >> 8);
    // 0x80024E88: xor         $t7, $t9, $a0
    ctx->r15 = ctx->r25 ^ ctx->r4;
    // 0x80024E8C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80024E90: lw          $t6, 0x1E8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1E8);
    // 0x80024E94: lhu         $t7, 0x6($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X6);
    // 0x80024E98: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x80024E9C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x80024EA0: andi        $t8, $t7, 0xF000
    ctx->r24 = ctx->r15 & 0XF000;
    // 0x80024EA4: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80024EA8: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x80024EAC: lw          $t9, 0x1E0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1E0);
    // 0x80024EB0: lhu         $t6, 0x2($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X2);
    // 0x80024EB4: addiu       $a2, $a1, 0x8
    ctx->r6 = ADD32(ctx->r5, 0X8);
    // 0x80024EB8: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x80024EBC: andi        $t7, $t6, 0xF000
    ctx->r15 = ctx->r14 & 0XF000;
    // 0x80024EC0: or          $t9, $t8, $t7
    ctx->r25 = ctx->r24 | ctx->r15;
    // 0x80024EC4: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x80024EC8: lw          $t6, 0x1F4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1F4);
    // 0x80024ECC: lw          $t8, 0x1F0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1F0);
    // 0x80024ED0: lw          $v1, 0x1FC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1FC);
    // 0x80024ED4: sh          $t6, 0x1CC($sp)
    MEM_H(0X1CC, ctx->r29) = ctx->r14;
    // 0x80024ED8: sh          $t8, 0x1CE($sp)
    MEM_H(0X1CE, ctx->r29) = ctx->r24;
    // 0x80024EDC: lhu         $t7, 0x14($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0X14);
    // 0x80024EE0: andi        $t9, $t7, 0x20
    ctx->r25 = ctx->r15 & 0X20;
    // 0x80024EE4: beql        $t9, $zero, L_80024F0C
    if (ctx->r25 == 0) {
        // 0x80024EE8: lw          $t9, 0x21C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X21C);
            goto L_80024F0C;
    }
    goto skip_10;
    // 0x80024EE8: lw          $t9, 0x21C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X21C);
    skip_10:
    // 0x80024EEC: lbu         $t6, 0x30($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X30);
    // 0x80024EF0: lw          $t8, 0x21C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X21C);
    // 0x80024EF4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80024EF8: beq         $t6, $at, L_80024F08
    if (ctx->r14 == ctx->r1) {
        // 0x80024EFC: sll         $t7, $t8, 2
        ctx->r15 = S32(ctx->r24 << 2);
            goto L_80024F08;
    }
    // 0x80024EFC: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x80024F00: b           L_80024F10
    // 0x80024F04: sh          $t7, 0x1D0($sp)
    MEM_H(0X1D0, ctx->r29) = ctx->r15;
        goto L_80024F10;
    // 0x80024F04: sh          $t7, 0x1D0($sp)
    MEM_H(0X1D0, ctx->r29) = ctx->r15;
L_80024F08:
    // 0x80024F08: lw          $t9, 0x21C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X21C);
L_80024F0C:
    // 0x80024F0C: sh          $t9, 0x1D0($sp)
    MEM_H(0X1D0, ctx->r29) = ctx->r25;
L_80024F10:
    // 0x80024F10: lw          $t8, 0x1C4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C4);
    // 0x80024F14: lw          $t6, 0x220($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X220);
    // 0x80024F18: lui         $at, 0xE400
    ctx->r1 = S32(0XE400 << 16);
    // 0x80024F1C: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x80024F20: srl         $t9, $t7, 20
    ctx->r25 = S32(U32(ctx->r15) >> 20);
    // 0x80024F24: sh          $t6, 0x1D2($sp)
    MEM_H(0X1D2, ctx->r29) = ctx->r14;
    // 0x80024F28: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x80024F2C: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x80024F30: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x80024F34: or          $t6, $t8, $zero
    ctx->r14 = ctx->r24 | 0;
    // 0x80024F38: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x80024F3C: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80024F40: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80024F44: lbu         $t9, 0x1C8($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X1C8);
    // 0x80024F48: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80024F4C: addiu       $v0, $a2, 0x8
    ctx->r2 = ADD32(ctx->r6, 0X8);
    // 0x80024F50: andi        $t7, $t9, 0x7
    ctx->r15 = ctx->r25 & 0X7;
    // 0x80024F54: sll         $t6, $v1, 8
    ctx->r14 = S32(ctx->r3 << 8);
    // 0x80024F58: srl         $t9, $t6, 20
    ctx->r25 = S32(U32(ctx->r14) >> 20);
    // 0x80024F5C: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x80024F60: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x80024F64: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x80024F68: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80024F6C: andi        $t8, $v1, 0xFFF
    ctx->r24 = ctx->r3 & 0XFFF;
    // 0x80024F70: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x80024F74: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x80024F78: lui         $t7, 0xE100
    ctx->r15 = S32(0XE100 << 16);
    // 0x80024F7C: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x80024F80: lhu         $t8, 0x1CC($sp)
    ctx->r24 = MEM_HU(ctx->r29, 0X1CC);
    // 0x80024F84: lhu         $t9, 0x1CE($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1CE);
    // 0x80024F88: lui         $t7, 0xF100
    ctx->r15 = S32(0XF100 << 16);
    // 0x80024F8C: sll         $t6, $t8, 16
    ctx->r14 = S32(ctx->r24 << 16);
    // 0x80024F90: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80024F94: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x80024F98: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x80024F9C: lhu         $t9, 0x1D0($sp)
    ctx->r25 = MEM_HU(ctx->r29, 0X1D0);
    // 0x80024FA0: lhu         $t6, 0x1D2($sp)
    ctx->r14 = MEM_HU(ctx->r29, 0X1D2);
    // 0x80024FA4: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x80024FA8: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x80024FAC: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x80024FB0: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x80024FB4: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80024FB8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80024FBC: lw          $t8, 0x1F8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1F8);
    // 0x80024FC0: addiu       $t1, $v0, 0x8
    ctx->r9 = ADD32(ctx->r2, 0X8);
    // 0x80024FC4: sw          $t1, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r9;
L_80024FC8:
    // 0x80024FC8: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
L_80024FCC:
    // 0x80024FCC: jr          $ra
    // 0x80024FD0: addiu       $sp, $sp, 0x1F8
    ctx->r29 = ADD32(ctx->r29, 0X1F8);
    return;
    // 0x80024FD0: addiu       $sp, $sp, 0x1F8
    ctx->r29 = ADD32(ctx->r29, 0X1F8);
;}
RECOMP_FUNC void itStarmieAttackProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80181D24: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80181D28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181D2C: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80181D30: lhu         $t6, 0x33E($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X33E);
    // 0x80181D34: bne         $t6, $zero, L_80181D44
    if (ctx->r14 != 0) {
        // 0x80181D38: nop
    
            goto L_80181D44;
    }
    // 0x80181D38: nop

    // 0x80181D3C: b           L_80181D7C
    // 0x80181D40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80181D7C;
    // 0x80181D40: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80181D44:
    // 0x80181D44: jal         0x80181C20
    // 0x80181D48: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itStarmieAttackUpdateSwift(rdram, ctx);
        goto after_0;
    // 0x80181D48: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80181D4C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80181D50: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80181D54: lwc1        $f4, 0x2C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X2C);
    // 0x80181D58: lwc1        $f6, 0x370($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X370);
    // 0x80181D5C: lw          $t7, 0x354($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X354);
    // 0x80181D60: lhu         $t9, 0x33E($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X33E);
    // 0x80181D64: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80181D68: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80181D6C: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x80181D70: sw          $t8, 0x354($v1)
    MEM_W(0X354, ctx->r3) = ctx->r24;
    // 0x80181D74: swc1        $f8, 0x2C($v1)
    MEM_W(0X2C, ctx->r3) = ctx->f8.u32l;
    // 0x80181D78: sh          $t0, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r8;
L_80181D7C:
    // 0x80181D7C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181D80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80181D84: jr          $ra
    // 0x80181D88: nop

    return;
    // 0x80181D88: nop

;}
RECOMP_FUNC void itTosakintoCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017EA48: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8017EA4C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017EA50: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8017EA54: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017EA58: bnel        $a1, $zero, L_8017EA80
    if (ctx->r5 != 0) {
        // 0x8017EA5C: addiu       $t6, $a1, -0x1
        ctx->r14 = ADD32(ctx->r5, -0X1);
            goto L_8017EA80;
    }
    goto skip_0;
    // 0x8017EA5C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    skip_0:
    // 0x8017EA60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8017EA64: nop

    // 0x8017EA68: swc1        $f4, 0x30($v1)
    MEM_W(0X30, ctx->r3) = ctx->f4.u32l;
    // 0x8017EA6C: jal         0x8017E828
    // 0x8017EA70: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    itTosakintoAppearSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017EA70: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8017EA74: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8017EA78: lhu         $a1, 0x33E($v1)
    ctx->r5 = MEM_HU(ctx->r3, 0X33E);
    // 0x8017EA7C: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
L_8017EA80:
    // 0x8017EA80: sh          $t6, 0x33E($v1)
    MEM_H(0X33E, ctx->r3) = ctx->r14;
    // 0x8017EA84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017EA88: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8017EA8C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8017EA90: jr          $ra
    // 0x8017EA94: nop

    return;
    // 0x8017EA94: nop

;}
RECOMP_FUNC void ftCommonCliffEscapeSlow1SetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801458BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x801458C0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801458C4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801458C8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x801458CC: addiu       $a1, $zero, 0x62
    ctx->r5 = ADD32(0, 0X62);
    // 0x801458D0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x801458D4: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x801458D8: jal         0x800E6F24
    // 0x801458DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x801458DC: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    after_0:
    // 0x801458E0: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801458E4: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x801458E8: addiu       $t9, $t9, 0x4CF8
    ctx->r25 = ADD32(ctx->r25, 0X4CF8);
    // 0x801458EC: lbu         $t7, 0x190($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X190);
    // 0x801458F0: sw          $t9, 0x9EC($v0)
    MEM_W(0X9EC, ctx->r2) = ctx->r25;
    // 0x801458F4: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x801458F8: sb          $t8, 0x190($v0)
    MEM_B(0X190, ctx->r2) = ctx->r24;
    // 0x801458FC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80145900: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80145904: jr          $ra
    // 0x80145908: nop

    return;
    // 0x80145908: nop

;}
RECOMP_FUNC void ftCommonDeadRightSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013C30C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8013C310: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8013C314: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8013C318: lw          $t6, 0x84($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X84);
    // 0x8013C31C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8013C320: jal         0x8013C050
    // 0x8013C324: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    ftCommonDeadResetCommonVars(rdram, ctx);
        goto after_0;
    // 0x8013C324: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    after_0:
    // 0x8013C328: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8013C32C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8013C330: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8013C334: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8013C338: jal         0x800E6F24
    // 0x8013C33C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8013C33C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8013C340: jal         0x8013C0B0
    // 0x8013C344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDeadResetSpecialStats(rdram, ctx);
        goto after_2;
    // 0x8013C344: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x8013C348: jal         0x8013C120
    // 0x8013C34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonDeadInitStatusVars(rdram, ctx);
        goto after_3;
    // 0x8013C34C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8013C350: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x8013C354: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8013C358: lui         $t0, 0x800A
    ctx->r8 = S32(0X800A << 16);
    // 0x8013C35C: lw          $t9, 0x1C($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X1C);
    // 0x8013C360: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013C364: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x8013C368: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8013C36C: lw          $t8, 0x20($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X20);
    // 0x8013C370: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8013C374: lw          $t9, 0x24($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X24);
    // 0x8013C378: sw          $t9, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r25;
    // 0x8013C37C: lw          $t0, 0x50E8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X50E8);
    // 0x8013C380: lbu         $t1, 0x0($t0)
    ctx->r9 = MEM_BU(ctx->r8, 0X0);
    // 0x8013C384: beql        $t1, $at, L_8013C3E4
    if (ctx->r9 == ctx->r1) {
        // 0x8013C388: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_8013C3E4;
    }
    goto skip_0;
    // 0x8013C388: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_0:
    // 0x8013C38C: lw          $v0, 0x1300($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1300);
    // 0x8013C390: lwc1        $f6, 0x3C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8013C394: lh          $t2, 0x6C($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X6C);
    // 0x8013C398: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x8013C39C: nop

    // 0x8013C3A0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8013C3A4: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x8013C3A8: nop

    // 0x8013C3AC: bc1fl       L_8013C3BC
    if (!c1cs) {
        // 0x8013C3B0: lh          $t3, 0x6E($v0)
        ctx->r11 = MEM_H(ctx->r2, 0X6E);
            goto L_8013C3BC;
    }
    goto skip_1;
    // 0x8013C3B0: lh          $t3, 0x6E($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6E);
    skip_1:
    // 0x8013C3B4: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8013C3B8: lh          $t3, 0x6E($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X6E);
L_8013C3BC:
    // 0x8013C3BC: lwc1        $f10, 0x3C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8013C3C0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8013C3C4: nop

    // 0x8013C3C8: cvt.s.w     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    ctx->f0.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8013C3CC: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x8013C3D0: nop

    // 0x8013C3D4: bc1fl       L_8013C3E4
    if (!c1cs) {
        // 0x8013C3D8: lw          $t4, 0x44($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X44);
            goto L_8013C3E4;
    }
    goto skip_2;
    // 0x8013C3D8: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    skip_2:
    // 0x8013C3DC: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8013C3E0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
L_8013C3E4:
    // 0x8013C3E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8013C3E8: jal         0x801021C0
    // 0x8013C3EC: lbu         $a1, 0xD($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0XD);
    efManagerDeadExplodeMakeEffect(rdram, ctx);
        goto after_4;
    // 0x8013C3EC: lbu         $a1, 0xD($t4)
    ctx->r5 = MEM_BU(ctx->r12, 0XD);
    after_4:
    // 0x8013C3F0: addiu       $a0, $zero, 0x51
    ctx->r4 = ADD32(0, 0X51);
    // 0x8013C3F4: jal         0x80115BF0
    // 0x8013C3F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ifScreenFlashSetColAnimID(rdram, ctx);
        goto after_5;
    // 0x8013C3F8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8013C3FC: lui         $t5, 0x800A
    ctx->r13 = S32(0X800A << 16);
    // 0x8013C400: lw          $t5, 0x50E8($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X50E8);
    // 0x8013C404: lbu         $v0, 0x1($t5)
    ctx->r2 = MEM_BU(ctx->r13, 0X1);
    // 0x8013C408: slti        $at, $v0, 0x11
    ctx->r1 = SIGNED(ctx->r2) < 0X11 ? 1 : 0;
    // 0x8013C40C: bne         $at, $zero, L_8013C418
    if (ctx->r1 != 0) {
        // 0x8013C410: slti        $at, $v0, 0x1D
        ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
            goto L_8013C418;
    }
    // 0x8013C410: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8013C414: bne         $at, $zero, L_8013C42C
    if (ctx->r1 != 0) {
        // 0x8013C418: slti        $at, $v0, 0x1D
        ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
            goto L_8013C42C;
    }
L_8013C418:
    // 0x8013C418: slti        $at, $v0, 0x1D
    ctx->r1 = SIGNED(ctx->r2) < 0X1D ? 1 : 0;
    // 0x8013C41C: bne         $at, $zero, L_8013C434
    if (ctx->r1 != 0) {
        // 0x8013C420: slti        $at, $v0, 0x29
        ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
            goto L_8013C434;
    }
    // 0x8013C420: slti        $at, $v0, 0x29
    ctx->r1 = SIGNED(ctx->r2) < 0X29 ? 1 : 0;
    // 0x8013C424: beql        $at, $zero, L_8013C438
    if (ctx->r1 == 0) {
        // 0x8013C428: addiu       $v0, $zero, 0x9A
        ctx->r2 = ADD32(0, 0X9A);
            goto L_8013C438;
    }
    goto skip_3;
    // 0x8013C428: addiu       $v0, $zero, 0x9A
    ctx->r2 = ADD32(0, 0X9A);
    skip_3:
L_8013C42C:
    // 0x8013C42C: b           L_8013C438
    // 0x8013C430: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
        goto L_8013C438;
    // 0x8013C430: addiu       $v0, $zero, 0x9B
    ctx->r2 = ADD32(0, 0X9B);
L_8013C434:
    // 0x8013C434: addiu       $v0, $zero, 0x9A
    ctx->r2 = ADD32(0, 0X9A);
L_8013C438:
    // 0x8013C438: jal         0x8013BC60
    // 0x8013C43C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    ftCommonDeadAddDeadSFXSoundQueue(rdram, ctx);
        goto after_6;
    // 0x8013C43C: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    after_6:
    // 0x8013C440: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8013C444: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8013C448: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8013C44C: jr          $ra
    // 0x8013C450: nop

    return;
    // 0x8013C450: nop

;}
RECOMP_FUNC void mvOpeningFoxMakePosedFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DA68: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8018DA6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8018DA70: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x8018DA74: addiu       $s0, $sp, 0x24
    ctx->r16 = ADD32(ctx->r29, 0X24);
    // 0x8018DA78: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x8018DA7C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8018DA80: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x8018DA84: or          $t9, $s0, $zero
    ctx->r25 = ctx->r16 | 0;
L_8018DA88:
    // 0x8018DA88: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DA8C: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x8018DA90: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x8018DA94: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8018DA98: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x8018DA9C: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x8018DAA0: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x8018DAA4: bne         $t6, $t0, L_8018DA88
    if (ctx->r14 != ctx->r8) {
        // 0x8018DAA8: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_8018DA88;
    }
    // 0x8018DAA8: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x8018DAAC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x8018DAB0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DAB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8018DAB8: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x8018DABC: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DAC0: jal         0x800EC0EC
    // 0x8018DAC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    ftParamGetCostumeCommonID(rdram, ctx);
        goto after_0;
    // 0x8018DAC4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x8018DAC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8018DACC: lui         $t2, 0x8019
    ctx->r10 = S32(0X8019 << 16);
    // 0x8018DAD0: lui         $at, 0x4416
    ctx->r1 = S32(0X4416 << 16);
    // 0x8018DAD4: lw          $t2, -0x1DF4($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X1DF4);
    // 0x8018DAD8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DADC: sb          $v0, 0x3B($sp)
    MEM_B(0X3B, ctx->r29) = ctx->r2;
    // 0x8018DAE0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DAE4: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8018DAE8: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8018DAEC: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8018DAF0: jal         0x800D7F3C
    // 0x8018DAF4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_1;
    // 0x8018DAF4: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DAF8: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x8018DAFC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018DB00: ori         $a1, $a1, 0xC
    ctx->r5 = ctx->r5 | 0XC;
    // 0x8018DB04: jal         0x803905CC
    // 0x8018DB08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_2;
    // 0x8018DB08: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_2:
    // 0x8018DB0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB10: addiu       $a1, $zero, 0x1A
    ctx->r5 = ADD32(0, 0X1A);
    // 0x8018DB14: jal         0x8000A0D0
    // 0x8018DB18: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    gcMoveGObjDL(rdram, ctx);
        goto after_3;
    // 0x8018DB18: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    after_3:
    // 0x8018DB1C: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018DB20: addiu       $a1, $a1, -0x2668
    ctx->r5 = ADD32(ctx->r5, -0X2668);
    // 0x8018DB24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018DB28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DB2C: jal         0x80008188
    // 0x8018DB30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8018DB30: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_4:
    // 0x8018DB34: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8018DB38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DB3C: lw          $t3, 0x74($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB40: swc1        $f0, 0x40($t3)
    MEM_W(0X40, ctx->r11) = ctx->f0.u32l;
    // 0x8018DB44: lw          $t4, 0x74($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB48: swc1        $f0, 0x44($t4)
    MEM_W(0X44, ctx->r12) = ctx->f0.u32l;
    // 0x8018DB4C: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x8018DB50: swc1        $f0, 0x48($t5)
    MEM_W(0X48, ctx->r13) = ctx->f0.u32l;
    // 0x8018DB54: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8018DB58: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8018DB5C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x8018DB60: jr          $ra
    // 0x8018DB64: nop

    return;
    // 0x8018DB64: nop

;}
RECOMP_FUNC void mnVSResultsSetFighterKindAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013315C: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80133160: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x80133164: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80133168: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x8013316C: beq         $t6, $zero, L_80133184
    if (ctx->r14 == 0) {
        // 0x80133170: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_80133184;
    }
    // 0x80133170: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80133174: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80133178: lbu         $t7, 0x4D2B($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4D2B);
    // 0x8013317C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80133180: sw          $t7, -0x6410($at)
    MEM_W(-0X6410, ctx->r1) = ctx->r15;
L_80133184:
    // 0x80133184: lw          $t8, -0x642C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X642C);
    // 0x80133188: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x8013318C: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80133190: beq         $t8, $zero, L_801331A4
    if (ctx->r24 == 0) {
        // 0x80133194: lui         $t3, 0x800A
        ctx->r11 = S32(0X800A << 16);
            goto L_801331A4;
    }
    // 0x80133194: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80133198: lbu         $t9, 0x4D9F($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4D9F);
    // 0x8013319C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801331A0: sw          $t9, -0x640C($at)
    MEM_W(-0X640C, ctx->r1) = ctx->r25;
L_801331A4:
    // 0x801331A4: lw          $t0, -0x6428($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6428);
    // 0x801331A8: beq         $t0, $zero, L_801331BC
    if (ctx->r8 == 0) {
        // 0x801331AC: nop
    
            goto L_801331BC;
    }
    // 0x801331AC: nop

    // 0x801331B0: lbu         $t1, 0x4E13($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X4E13);
    // 0x801331B4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801331B8: sw          $t1, -0x6408($at)
    MEM_W(-0X6408, ctx->r1) = ctx->r9;
L_801331BC:
    // 0x801331BC: lw          $t2, -0x6424($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6424);
    // 0x801331C0: beq         $t2, $zero, L_801331D4
    if (ctx->r10 == 0) {
        // 0x801331C4: nop
    
            goto L_801331D4;
    }
    // 0x801331C4: nop

    // 0x801331C8: lbu         $t3, 0x4E87($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4E87);
    // 0x801331CC: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801331D0: sw          $t3, -0x6404($at)
    MEM_W(-0X6404, ctx->r1) = ctx->r11;
L_801331D4:
    // 0x801331D4: jr          $ra
    // 0x801331D8: nop

    return;
    // 0x801331D8: nop

;}
RECOMP_FUNC void mnPlayers1PBonusMakeBestTaskCount(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801339C8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x801339CC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801339D0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801339D4: addiu       $t7, $t7, 0x73C8
    ctx->r15 = ADD32(ctx->r15, 0X73C8);
    // 0x801339D8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801339DC: addiu       $t6, $sp, 0x4C
    ctx->r14 = ADD32(ctx->r29, 0X4C);
    // 0x801339E0: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801339E4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801339E8: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x801339EC: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x801339F0: addiu       $t1, $t1, 0x73D4
    ctx->r9 = ADD32(ctx->r9, 0X73D4);
    // 0x801339F4: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801339F8: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x801339FC: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x80133A00: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x80133A04: addiu       $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x80133A08: sw          $t2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r10;
    // 0x80133A0C: sw          $t3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r11;
    // 0x80133A10: lw          $t3, 0x8($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X8);
    // 0x80133A14: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x80133A18: sw          $t3, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r11;
    // 0x80133A1C: sw          $t2, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r10;
    // 0x80133A20: lw          $t2, 0x14($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X14);
    // 0x80133A24: lw          $t3, 0x10($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X10);
    // 0x80133A28: sw          $t2, 0x14($t0)
    MEM_W(0X14, ctx->r8) = ctx->r10;
    // 0x80133A2C: jal         0x80134E50
    // 0x80133A30: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    mnPlayers1PBonusGetForcePuckFighterKind(rdram, ctx);
        goto after_0;
    // 0x80133A30: sw          $t3, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->r11;
    after_0:
    // 0x80133A34: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x80133A38: lw          $a0, 0x76FC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X76FC);
    // 0x80133A3C: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x80133A40: beql        $a0, $zero, L_80133A5C
    if (ctx->r4 == 0) {
        // 0x80133A44: lw          $t4, 0x30($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X30);
            goto L_80133A5C;
    }
    goto skip_0;
    // 0x80133A44: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80133A48: jal         0x80009A84
    // 0x80133A4C: nop

    gcEjectGObj(rdram, ctx);
        goto after_1;
    // 0x80133A4C: nop

    after_1:
    // 0x80133A50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133A54: sw          $zero, 0x76FC($at)
    MEM_W(0X76FC, ctx->r1) = 0;
    // 0x80133A58: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
L_80133A5C:
    // 0x80133A5C: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x80133A60: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80133A64: beq         $t4, $at, L_80133B6C
    if (ctx->r12 == ctx->r1) {
        // 0x80133A68: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80133B6C;
    }
    // 0x80133A68: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80133A6C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80133A70: jal         0x80009968
    // 0x80133A74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x80133A74: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80133A78: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80133A7C: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80133A80: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x80133A84: sw          $v0, 0x76FC($at)
    MEM_W(0X76FC, ctx->r1) = ctx->r2;
    // 0x80133A88: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x80133A8C: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80133A90: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80133A94: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80133A98: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80133A9C: jal         0x80009DF4
    // 0x80133AA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x80133AA0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_3:
    // 0x80133AA4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80133AA8: lw          $t6, 0x7714($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7714);
    // 0x80133AAC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80133AB0: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x80133AB4: bne         $t6, $zero, L_80133AE0
    if (ctx->r14 != 0) {
        // 0x80133AB8: lui         $t0, 0x0
        ctx->r8 = S32(0X0 << 16);
            goto L_80133AE0;
    }
    // 0x80133AB8: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80133ABC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80133AC0: lw          $t7, 0x7E0C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7E0C);
    // 0x80133AC4: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80133AC8: addiu       $t8, $t8, 0x1658
    ctx->r24 = ADD32(ctx->r24, 0X1658);
    // 0x80133ACC: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80133AD0: jal         0x800CCFDC
    // 0x80133AD4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80133AD4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x80133AD8: b           L_80133AF4
    // 0x80133ADC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80133AF4;
    // 0x80133ADC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80133AE0:
    // 0x80133AE0: lw          $t9, 0x7E0C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7E0C);
    // 0x80133AE4: addiu       $t0, $t0, 0x1898
    ctx->r8 = ADD32(ctx->r8, 0X1898);
    // 0x80133AE8: jal         0x800CCFDC
    // 0x80133AEC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_5;
    // 0x80133AEC: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_5:
    // 0x80133AF0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80133AF4:
    // 0x80133AF4: lhu         $t1, 0x24($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X24);
    // 0x80133AF8: lui         $at, 0x436B
    ctx->r1 = S32(0X436B << 16);
    // 0x80133AFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80133B00: lui         $at, 0x4343
    ctx->r1 = S32(0X4343 << 16);
    // 0x80133B04: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80133B08: andi        $t3, $t1, 0xFFDF
    ctx->r11 = ctx->r9 & 0XFFDF;
    // 0x80133B0C: sh          $t3, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r11;
    // 0x80133B10: ori         $t4, $t3, 0x1
    ctx->r12 = ctx->r11 | 0X1;
    // 0x80133B14: addiu       $t5, $zero, 0x7E
    ctx->r13 = ADD32(0, 0X7E);
    // 0x80133B18: addiu       $t6, $zero, 0x7C
    ctx->r14 = ADD32(0, 0X7C);
    // 0x80133B1C: addiu       $t7, $zero, 0x77
    ctx->r15 = ADD32(0, 0X77);
    // 0x80133B20: sh          $t4, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r12;
    // 0x80133B24: sb          $t5, 0x28($v1)
    MEM_B(0X28, ctx->r3) = ctx->r13;
    // 0x80133B28: sb          $t6, 0x29($v1)
    MEM_B(0X29, ctx->r3) = ctx->r14;
    // 0x80133B2C: sb          $t7, 0x2A($v1)
    MEM_B(0X2A, ctx->r3) = ctx->r15;
    // 0x80133B30: swc1        $f4, 0x58($v1)
    MEM_W(0X58, ctx->r3) = ctx->f4.u32l;
    // 0x80133B34: swc1        $f6, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f6.u32l;
    // 0x80133B38: jal         0x80133990
    // 0x80133B3C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    mnPlayers1PBonusGetBestTaskCount(rdram, ctx);
        goto after_6;
    // 0x80133B3C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_6:
    // 0x80133B40: addiu       $t8, $sp, 0x34
    ctx->r24 = ADD32(ctx->r29, 0X34);
    // 0x80133B44: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80133B48: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80133B4C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x80133B50: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x80133B54: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80133B58: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x80133B5C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80133B60: lui         $a2, 0x4361
    ctx->r6 = S32(0X4361 << 16);
    // 0x80133B64: jal         0x80131CEC
    // 0x80133B68: lui         $a3, 0x4342
    ctx->r7 = S32(0X4342 << 16);
    mnPlayers1PBonusMakeNumber(rdram, ctx);
        goto after_7;
    // 0x80133B68: lui         $a3, 0x4342
    ctx->r7 = S32(0X4342 << 16);
    after_7:
L_80133B6C:
    // 0x80133B6C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80133B70: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80133B74: jr          $ra
    // 0x80133B78: nop

    return;
    // 0x80133B78: nop

;}
RECOMP_FUNC void ftKirbySpecialAirNLoopProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801628B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801628BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801628C0: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x801628C4: jal         0x800DE6E4
    // 0x801628C8: addiu       $a1, $a1, 0x2A20
    ctx->r5 = ADD32(ctx->r5, 0X2A20);
    mpCommonProcFighterLanding(rdram, ctx);
        goto after_0;
    // 0x801628C8: addiu       $a1, $a1, 0x2A20
    ctx->r5 = ADD32(ctx->r5, 0X2A20);
    after_0:
    // 0x801628CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801628D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801628D4: jr          $ra
    // 0x801628D8: nop

    return;
    // 0x801628D8: nop

;}
RECOMP_FUNC void mnOptionMakeLink4Camera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132AE0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80132AE4: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80132AE8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80132AEC: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x80132AF0: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x80132AF4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80132AF8: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80132AFC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80132B00: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80132B04: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80132B08: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80132B0C: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x80132B10: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x80132B14: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x80132B18: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80132B1C: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80132B20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132B24: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80132B28: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80132B2C: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80132B30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80132B34: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132B38: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132B3C: jal         0x8000B93C
    // 0x80132B40: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80132B40: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80132B44: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80132B48: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132B4C: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80132B50: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80132B54: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132B58: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80132B5C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80132B60: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80132B64: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x80132B68: jal         0x80007080
    // 0x80132B6C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80132B6C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80132B70: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80132B74: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80132B78: jr          $ra
    // 0x80132B7C: nop

    return;
    // 0x80132B7C: nop

;}
RECOMP_FUNC void ftManagerSetupFilesPlayablesAll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D782C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D7830: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800D7834: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800D7838: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D783C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800D7840: addiu       $s1, $zero, 0xC
    ctx->r17 = ADD32(0, 0XC);
L_800D7844:
    // 0x800D7844: jal         0x800D7710
    // 0x800D7848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftManagerSetupFilesKind(rdram, ctx);
        goto after_0;
    // 0x800D7848: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800D784C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800D7850: bne         $s0, $s1, L_800D7844
    if (ctx->r16 != ctx->r17) {
        // 0x800D7854: nop
    
            goto L_800D7844;
    }
    // 0x800D7854: nop

    // 0x800D7858: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D785C: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800D7860: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800D7864: jr          $ra
    // 0x800D7868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800D7868: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void efDisplayMakeXLU(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800FCE6C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800FCE70: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800FCE74: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FCE78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FCE7C: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FCE80: jal         0x80009968
    // 0x800FCE84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800FCE84: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x800FCE88: lui         $a1, 0x8010
    ctx->r5 = S32(0X8010 << 16);
    // 0x800FCE8C: addiu       $a1, $a1, -0x329C
    ctx->r5 = ADD32(ctx->r5, -0X329C);
    // 0x800FCE90: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800FCE94: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800FCE98: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x800FCE9C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FCEA0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x800FCEA4: jal         0x80009DF4
    // 0x800FCEA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x800FCEA8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x800FCEAC: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x800FCEB0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800FCEB4: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x800FCEB8: jal         0x80009968
    // 0x800FCEBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_2;
    // 0x800FCEBC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x800FCEC0: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800FCEC4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800FCEC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800FCECC: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x800FCED0: addiu       $a2, $zero, 0x12
    ctx->r6 = ADD32(0, 0X12);
    // 0x800FCED4: jal         0x80009DF4
    // 0x800FCED8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_3;
    // 0x800FCED8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x800FCEDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800FCEE0: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800FCEE4: jr          $ra
    // 0x800FCEE8: nop

    return;
    // 0x800FCEE8: nop

;}
RECOMP_FUNC void syDmaDecodeVpk0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002E18: addiu       $sp, $sp, -0x458
    ctx->r29 = ADD32(ctx->r29, -0X458);
    // 0x80002E1C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80002E20: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80002E24: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80002E28: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80002E2C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80002E30: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80002E34: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x80002E38: or          $s6, $a2, $zero
    ctx->r22 = ctx->r6 | 0;
    // 0x80002E3C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x80002E40: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80002E44: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80002E48: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80002E4C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80002E50: sw          $a3, 0x464($sp)
    MEM_W(0X464, ctx->r29) = ctx->r7;
    // 0x80002E54: jalr        $a2
    // 0x80002E58: addiu       $s3, $sp, 0x14C
    ctx->r19 = ADD32(ctx->r29, 0X14C);
    LOOKUP_FUNC(ctx->r6)(rdram, ctx);
        goto after_0;
    // 0x80002E58: addiu       $s3, $sp, 0x14C
    ctx->r19 = ADD32(ctx->r29, 0X14C);
    after_0:
    // 0x80002E5C: lhu         $t6, 0x0($s4)
    ctx->r14 = MEM_HU(ctx->r20, 0X0);
    // 0x80002E60: addiu       $a0, $s4, 0x2
    ctx->r4 = ADD32(ctx->r20, 0X2);
    // 0x80002E64: addu        $s5, $s4, $s0
    ctx->r21 = ADD32(ctx->r20, ctx->r16);
    // 0x80002E68: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80002E6C: addiu       $s1, $zero, 0x10
    ctx->r17 = ADD32(0, 0X10);
    // 0x80002E70: bne         $at, $zero, L_80002E84
    if (ctx->r1 != 0) {
        // 0x80002E74: or          $s2, $zero, $t6
        ctx->r18 = 0 | ctx->r14;
            goto L_80002E84;
    }
    // 0x80002E74: or          $s2, $zero, $t6
    ctx->r18 = 0 | ctx->r14;
    // 0x80002E78: jalr        $s6
    // 0x80002E7C: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_1;
    // 0x80002E7C: nop

    after_1:
    // 0x80002E80: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80002E84:
    // 0x80002E84: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x80002E88: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80002E8C: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80002E90: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80002E94: addiu       $s1, $s1, -0x10
    ctx->r17 = ADD32(ctx->r17, -0X10);
    // 0x80002E98: lw          $fp, 0x464($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X464);
    // 0x80002E9C: bne         $at, $zero, L_80002EB0
    if (ctx->r1 != 0) {
        // 0x80002EA0: or          $s2, $s2, $t7
        ctx->r18 = ctx->r18 | ctx->r15;
            goto L_80002EB0;
    }
    // 0x80002EA0: or          $s2, $s2, $t7
    ctx->r18 = ctx->r18 | ctx->r15;
    // 0x80002EA4: jalr        $s6
    // 0x80002EA8: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_2;
    // 0x80002EA8: nop

    after_2:
    // 0x80002EAC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80002EB0:
    // 0x80002EB0: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    // 0x80002EB4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80002EB8: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80002EBC: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80002EC0: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80002EC4: bne         $at, $zero, L_80002ED8
    if (ctx->r1 != 0) {
        // 0x80002EC8: or          $s2, $s2, $t8
        ctx->r18 = ctx->r18 | ctx->r24;
            goto L_80002ED8;
    }
    // 0x80002EC8: or          $s2, $s2, $t8
    ctx->r18 = ctx->r18 | ctx->r24;
    // 0x80002ECC: jalr        $s6
    // 0x80002ED0: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_3;
    // 0x80002ED0: nop

    after_3:
    // 0x80002ED4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_80002ED8:
    // 0x80002ED8: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    // 0x80002EDC: lw          $t2, 0x464($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X464);
    // 0x80002EE0: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80002EE4: addiu       $s1, $s1, -0x10
    ctx->r17 = ADD32(ctx->r17, -0X10);
    // 0x80002EE8: negu        $t0, $s1
    ctx->r8 = SUB32(0, ctx->r17);
    // 0x80002EEC: or          $s2, $s2, $t9
    ctx->r18 = ctx->r18 | ctx->r25;
    // 0x80002EF0: sllv        $t1, $s2, $t0
    ctx->r9 = S32(ctx->r18 << (ctx->r8 & 31));
    // 0x80002EF4: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x80002EF8: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x80002EFC: sw          $t3, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r11;
    // 0x80002F00: beq         $at, $zero, L_80002F34
    if (ctx->r1 == 0) {
        // 0x80002F04: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_80002F34;
    }
    // 0x80002F04: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80002F08: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80002F0C: bnel        $at, $zero, L_80002F24
    if (ctx->r1 != 0) {
        // 0x80002F10: lhu         $t4, 0x0($a0)
        ctx->r12 = MEM_HU(ctx->r4, 0X0);
            goto L_80002F24;
    }
    goto skip_0;
    // 0x80002F10: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
    skip_0:
    // 0x80002F14: jalr        $s6
    // 0x80002F18: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_4;
    // 0x80002F18: nop

    after_4:
    // 0x80002F1C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80002F20: lhu         $t4, 0x0($a0)
    ctx->r12 = MEM_HU(ctx->r4, 0X0);
L_80002F24:
    // 0x80002F24: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80002F28: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80002F2C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80002F30: or          $s2, $s2, $t4
    ctx->r18 = ctx->r18 | ctx->r12;
L_80002F34:
    // 0x80002F34: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
    // 0x80002F38: addiu       $t5, $zero, 0x18
    ctx->r13 = ADD32(0, 0X18);
    // 0x80002F3C: subu        $t6, $t5, $s1
    ctx->r14 = SUB32(ctx->r13, ctx->r17);
    // 0x80002F40: sllv        $t7, $s2, $t6
    ctx->r15 = S32(ctx->r18 << (ctx->r14 & 31));
    // 0x80002F44: srl         $t8, $t7, 24
    ctx->r24 = S32(U32(ctx->r15) >> 24);
    // 0x80002F48: sw          $t8, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->r24;
    // 0x80002F4C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80002F50: sw          $zero, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = 0;
    // 0x80002F54: addiu       $s7, $zero, 0x1F
    ctx->r23 = ADD32(0, 0X1F);
L_80002F58:
    // 0x80002F58: bgtz        $s1, L_80002F8C
    if (SIGNED(ctx->r17) > 0) {
        // 0x80002F5C: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_80002F8C;
    }
    // 0x80002F5C: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80002F60: bnel        $at, $zero, L_80002F7C
    if (ctx->r1 != 0) {
        // 0x80002F64: lhu         $t9, 0x0($a0)
        ctx->r25 = MEM_HU(ctx->r4, 0X0);
            goto L_80002F7C;
    }
    goto skip_1;
    // 0x80002F64: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    skip_1:
    // 0x80002F68: jalr        $s6
    // 0x80002F6C: sw          $v1, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_5;
    // 0x80002F6C: sw          $v1, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r3;
    after_5:
    // 0x80002F70: lw          $v1, 0xE0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE0);
    // 0x80002F74: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80002F78: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
L_80002F7C:
    // 0x80002F7C: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80002F80: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80002F84: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80002F88: or          $s2, $s2, $t9
    ctx->r18 = ctx->r18 | ctx->r25;
L_80002F8C:
    // 0x80002F8C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80002F90: subu        $t0, $s7, $s1
    ctx->r8 = SUB32(ctx->r23, ctx->r17);
    // 0x80002F94: sllv        $v0, $s2, $t0
    ctx->r2 = S32(ctx->r18 << (ctx->r8 & 31));
    // 0x80002F98: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x80002F9C: beq         $v0, $zero, L_80002FA8
    if (ctx->r2 == 0) {
        // 0x80002FA0: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_80002FA8;
    }
    // 0x80002FA0: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80002FA4: bne         $at, $zero, L_80003060
    if (ctx->r1 != 0) {
        // 0x80002FA8: sll         $t1, $v1, 2
        ctx->r9 = S32(ctx->r3 << 2);
            goto L_80003060;
    }
L_80002FA8:
    // 0x80002FA8: sll         $t1, $v1, 2
    ctx->r9 = S32(ctx->r3 << 2);
    // 0x80002FAC: addiu       $t2, $sp, 0xE4
    ctx->r10 = ADD32(ctx->r29, 0XE4);
    // 0x80002FB0: beq         $v0, $zero, L_80002FE8
    if (ctx->r2 == 0) {
        // 0x80002FB4: addu        $s0, $t1, $t2
        ctx->r16 = ADD32(ctx->r9, ctx->r10);
            goto L_80002FE8;
    }
    // 0x80002FB4: addu        $s0, $t1, $t2
    ctx->r16 = ADD32(ctx->r9, ctx->r10);
    // 0x80002FB8: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x80002FBC: sw          $zero, 0x4($s3)
    MEM_W(0X4, ctx->r19) = 0;
    // 0x80002FC0: sw          $zero, 0x8($s3)
    MEM_W(0X8, ctx->r19) = 0;
    // 0x80002FC4: lw          $t3, -0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, -0X8);
    // 0x80002FC8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80002FCC: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x80002FD0: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80002FD4: lw          $t4, -0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, -0X4);
    // 0x80002FD8: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80002FDC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80002FE0: b           L_80002F58
    // 0x80002FE4: sw          $v0, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r2;
        goto L_80002F58;
    // 0x80002FE4: sw          $v0, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r2;
L_80002FE8:
    // 0x80002FE8: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80002FEC: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x80002FF0: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x80002FF4: sw          $zero, -0xC($s3)
    MEM_W(-0XC, ctx->r19) = 0;
    // 0x80002FF8: sw          $zero, -0x8($s3)
    MEM_W(-0X8, ctx->r19) = 0;
    // 0x80002FFC: beq         $at, $zero, L_8000303C
    if (ctx->r1 == 0) {
        // 0x80003000: sw          $zero, -0x4($s3)
        MEM_W(-0X4, ctx->r19) = 0;
            goto L_8000303C;
    }
    // 0x80003000: sw          $zero, -0x4($s3)
    MEM_W(-0X4, ctx->r19) = 0;
    // 0x80003004: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80003008: bnel        $at, $zero, L_8000302C
    if (ctx->r1 != 0) {
        // 0x8000300C: lhu         $t5, 0x0($a0)
        ctx->r13 = MEM_HU(ctx->r4, 0X0);
            goto L_8000302C;
    }
    goto skip_2;
    // 0x8000300C: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
    skip_2:
    // 0x80003010: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    // 0x80003014: jalr        $s6
    // 0x80003018: sw          $v1, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_6;
    // 0x80003018: sw          $v1, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r3;
    after_6:
    // 0x8000301C: lw          $v0, 0xD4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD4);
    // 0x80003020: lw          $v1, 0xE0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XE0);
    // 0x80003024: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003028: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
L_8000302C:
    // 0x8000302C: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80003030: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003034: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80003038: or          $s2, $s2, $t5
    ctx->r18 = ctx->r18 | ctx->r13;
L_8000303C:
    // 0x8000303C: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
    // 0x80003040: addiu       $t6, $zero, 0x18
    ctx->r14 = ADD32(0, 0X18);
    // 0x80003044: subu        $t7, $t6, $s1
    ctx->r15 = SUB32(ctx->r14, ctx->r17);
    // 0x80003048: sllv        $t8, $s2, $t7
    ctx->r24 = S32(ctx->r18 << (ctx->r15 & 31));
    // 0x8000304C: srl         $t9, $t8, 24
    ctx->r25 = S32(U32(ctx->r24) >> 24);
    // 0x80003050: sw          $t9, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r25;
    // 0x80003054: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80003058: b           L_80002F58
    // 0x8000305C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80002F58;
    // 0x8000305C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80003060:
    // 0x80003060: lw          $t0, 0xE4($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XE4);
    // 0x80003064: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80003068: sw          $zero, 0x84($sp)
    MEM_W(0X84, ctx->r29) = 0;
    // 0x8000306C: sw          $t0, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r8;
L_80003070:
    // 0x80003070: bgtz        $s1, L_800030A4
    if (SIGNED(ctx->r17) > 0) {
        // 0x80003074: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_800030A4;
    }
    // 0x80003074: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80003078: bnel        $at, $zero, L_80003094
    if (ctx->r1 != 0) {
        // 0x8000307C: lhu         $t1, 0x0($a0)
        ctx->r9 = MEM_HU(ctx->r4, 0X0);
            goto L_80003094;
    }
    goto skip_3;
    // 0x8000307C: lhu         $t1, 0x0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X0);
    skip_3:
    // 0x80003080: jalr        $s6
    // 0x80003084: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_7;
    // 0x80003084: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    after_7:
    // 0x80003088: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x8000308C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003090: lhu         $t1, 0x0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X0);
L_80003094:
    // 0x80003094: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80003098: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8000309C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800030A0: or          $s2, $s2, $t1
    ctx->r18 = ctx->r18 | ctx->r9;
L_800030A4:
    // 0x800030A4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800030A8: subu        $t2, $s7, $s1
    ctx->r10 = SUB32(ctx->r23, ctx->r17);
    // 0x800030AC: sllv        $v0, $s2, $t2
    ctx->r2 = S32(ctx->r18 << (ctx->r10 & 31));
    // 0x800030B0: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x800030B4: beq         $v0, $zero, L_800030C0
    if (ctx->r2 == 0) {
        // 0x800030B8: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800030C0;
    }
    // 0x800030B8: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800030BC: bne         $at, $zero, L_80003178
    if (ctx->r1 != 0) {
        // 0x800030C0: sll         $t3, $v1, 2
        ctx->r11 = S32(ctx->r3 << 2);
            goto L_80003178;
    }
L_800030C0:
    // 0x800030C0: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800030C4: addiu       $t4, $sp, 0x84
    ctx->r12 = ADD32(ctx->r29, 0X84);
    // 0x800030C8: beq         $v0, $zero, L_80003100
    if (ctx->r2 == 0) {
        // 0x800030CC: addu        $s0, $t3, $t4
        ctx->r16 = ADD32(ctx->r11, ctx->r12);
            goto L_80003100;
    }
    // 0x800030CC: addu        $s0, $t3, $t4
    ctx->r16 = ADD32(ctx->r11, ctx->r12);
    // 0x800030D0: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x800030D4: sw          $zero, 0x4($s3)
    MEM_W(0X4, ctx->r19) = 0;
    // 0x800030D8: sw          $zero, 0x8($s3)
    MEM_W(0X8, ctx->r19) = 0;
    // 0x800030DC: lw          $t5, -0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, -0X8);
    // 0x800030E0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800030E4: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x800030E8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800030EC: lw          $t6, -0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, -0X4);
    // 0x800030F0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800030F4: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800030F8: b           L_80003070
    // 0x800030FC: sw          $v0, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r2;
        goto L_80003070;
    // 0x800030FC: sw          $v0, -0x8($s0)
    MEM_W(-0X8, ctx->r16) = ctx->r2;
L_80003100:
    // 0x80003100: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80003104: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x80003108: addiu       $s3, $s3, 0xC
    ctx->r19 = ADD32(ctx->r19, 0XC);
    // 0x8000310C: sw          $zero, -0xC($s3)
    MEM_W(-0XC, ctx->r19) = 0;
    // 0x80003110: sw          $zero, -0x8($s3)
    MEM_W(-0X8, ctx->r19) = 0;
    // 0x80003114: beq         $at, $zero, L_80003154
    if (ctx->r1 == 0) {
        // 0x80003118: sw          $zero, -0x4($s3)
        MEM_W(-0X4, ctx->r19) = 0;
            goto L_80003154;
    }
    // 0x80003118: sw          $zero, -0x4($s3)
    MEM_W(-0X4, ctx->r19) = 0;
    // 0x8000311C: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80003120: bnel        $at, $zero, L_80003144
    if (ctx->r1 != 0) {
        // 0x80003124: lhu         $t7, 0x0($a0)
        ctx->r15 = MEM_HU(ctx->r4, 0X0);
            goto L_80003144;
    }
    goto skip_4;
    // 0x80003124: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    skip_4:
    // 0x80003128: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8000312C: jalr        $s6
    // 0x80003130: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_8;
    // 0x80003130: sw          $v1, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r3;
    after_8:
    // 0x80003134: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80003138: lw          $v1, 0x80($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X80);
    // 0x8000313C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003140: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
L_80003144:
    // 0x80003144: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80003148: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8000314C: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80003150: or          $s2, $s2, $t7
    ctx->r18 = ctx->r18 | ctx->r15;
L_80003154:
    // 0x80003154: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
    // 0x80003158: addiu       $t8, $zero, 0x18
    ctx->r24 = ADD32(0, 0X18);
    // 0x8000315C: subu        $t9, $t8, $s1
    ctx->r25 = SUB32(ctx->r24, ctx->r17);
    // 0x80003160: sllv        $t0, $s2, $t9
    ctx->r8 = S32(ctx->r18 << (ctx->r25 & 31));
    // 0x80003164: srl         $t1, $t0, 24
    ctx->r9 = S32(U32(ctx->r8) >> 24);
    // 0x80003168: sw          $t1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r9;
    // 0x8000316C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x80003170: b           L_80003070
    // 0x80003174: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
        goto L_80003070;
    // 0x80003174: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80003178:
    // 0x80003178: lw          $t3, 0x464($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X464);
    // 0x8000317C: lw          $t4, 0x138($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X138);
    // 0x80003180: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x80003184: sltu        $at, $t3, $t4
    ctx->r1 = ctx->r11 < ctx->r12 ? 1 : 0;
    // 0x80003188: beq         $at, $zero, L_800035B0
    if (ctx->r1 == 0) {
        // 0x8000318C: sw          $t2, 0x140($sp)
        MEM_W(0X140, ctx->r29) = ctx->r10;
            goto L_800035B0;
    }
    // 0x8000318C: sw          $t2, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r10;
L_80003190:
    // 0x80003190: bgtz        $s1, L_800031C0
    if (SIGNED(ctx->r17) > 0) {
        // 0x80003194: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_800031C0;
    }
    // 0x80003194: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80003198: bnel        $at, $zero, L_800031B0
    if (ctx->r1 != 0) {
        // 0x8000319C: lhu         $t5, 0x0($a0)
        ctx->r13 = MEM_HU(ctx->r4, 0X0);
            goto L_800031B0;
    }
    goto skip_5;
    // 0x8000319C: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
    skip_5:
    // 0x800031A0: jalr        $s6
    // 0x800031A4: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_9;
    // 0x800031A4: nop

    after_9:
    // 0x800031A8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800031AC: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
L_800031B0:
    // 0x800031B0: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800031B4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800031B8: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800031BC: or          $s2, $s2, $t5
    ctx->r18 = ctx->r18 | ctx->r13;
L_800031C0:
    // 0x800031C0: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800031C4: subu        $t6, $s7, $s1
    ctx->r14 = SUB32(ctx->r23, ctx->r17);
    // 0x800031C8: sllv        $t7, $s2, $t6
    ctx->r15 = S32(ctx->r18 << (ctx->r14 & 31));
    // 0x800031CC: srl         $t8, $t7, 31
    ctx->r24 = S32(U32(ctx->r15) >> 31);
    // 0x800031D0: bne         $t8, $zero, L_8000322C
    if (ctx->r24 != 0) {
        // 0x800031D4: lw          $t5, 0x134($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X134);
            goto L_8000322C;
    }
    // 0x800031D4: lw          $t5, 0x134($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X134);
    // 0x800031D8: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x800031DC: beq         $at, $zero, L_8000320C
    if (ctx->r1 == 0) {
        // 0x800031E0: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_8000320C;
    }
    // 0x800031E0: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x800031E4: bnel        $at, $zero, L_800031FC
    if (ctx->r1 != 0) {
        // 0x800031E8: lhu         $t9, 0x0($a0)
        ctx->r25 = MEM_HU(ctx->r4, 0X0);
            goto L_800031FC;
    }
    goto skip_6;
    // 0x800031E8: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    skip_6:
    // 0x800031EC: jalr        $s6
    // 0x800031F0: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_10;
    // 0x800031F0: nop

    after_10:
    // 0x800031F4: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800031F8: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
L_800031FC:
    // 0x800031FC: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80003200: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003204: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80003208: or          $s2, $s2, $t9
    ctx->r18 = ctx->r18 | ctx->r25;
L_8000320C:
    // 0x8000320C: addiu       $s1, $s1, -0x8
    ctx->r17 = ADD32(ctx->r17, -0X8);
    // 0x80003210: addiu       $t0, $zero, 0x18
    ctx->r8 = ADD32(0, 0X18);
    // 0x80003214: subu        $t1, $t0, $s1
    ctx->r9 = SUB32(ctx->r8, ctx->r17);
    // 0x80003218: sllv        $t2, $s2, $t1
    ctx->r10 = S32(ctx->r18 << (ctx->r9 & 31));
    // 0x8000321C: srl         $t3, $t2, 24
    ctx->r11 = S32(U32(ctx->r10) >> 24);
    // 0x80003220: sb          $t3, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r11;
    // 0x80003224: b           L_800035A0
    // 0x80003228: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
        goto L_800035A0;
    // 0x80003228: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
L_8000322C:
    // 0x8000322C: lw          $t4, 0x144($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X144);
    // 0x80003230: lw          $s3, 0x140($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X140);
    // 0x80003234: beq         $t5, $zero, L_800033F4
    if (ctx->r13 == 0) {
        // 0x80003238: lw          $v0, 0x0($t4)
        ctx->r2 = MEM_W(ctx->r12, 0X0);
            goto L_800033F4;
    }
    // 0x80003238: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x8000323C: sw          $zero, 0x64($sp)
    MEM_W(0X64, ctx->r29) = 0;
    // 0x80003240: beq         $v0, $zero, L_800032A8
    if (ctx->r2 == 0) {
        // 0x80003244: or          $s0, $t4, $zero
        ctx->r16 = ctx->r12 | 0;
            goto L_800032A8;
    }
    // 0x80003244: or          $s0, $t4, $zero
    ctx->r16 = ctx->r12 | 0;
L_80003248:
    // 0x80003248: bgtz        $s1, L_80003278
    if (SIGNED(ctx->r17) > 0) {
        // 0x8000324C: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_80003278;
    }
    // 0x8000324C: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80003250: bnel        $at, $zero, L_80003268
    if (ctx->r1 != 0) {
        // 0x80003254: lhu         $t6, 0x0($a0)
        ctx->r14 = MEM_HU(ctx->r4, 0X0);
            goto L_80003268;
    }
    goto skip_7;
    // 0x80003254: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
    skip_7:
    // 0x80003258: jalr        $s6
    // 0x8000325C: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_11;
    // 0x8000325C: nop

    after_11:
    // 0x80003260: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003264: lhu         $t6, 0x0($a0)
    ctx->r14 = MEM_HU(ctx->r4, 0X0);
L_80003268:
    // 0x80003268: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x8000326C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003270: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80003274: or          $s2, $s2, $t6
    ctx->r18 = ctx->r18 | ctx->r14;
L_80003278:
    // 0x80003278: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x8000327C: subu        $t7, $s7, $s1
    ctx->r15 = SUB32(ctx->r23, ctx->r17);
    // 0x80003280: sllv        $t8, $s2, $t7
    ctx->r24 = S32(ctx->r18 << (ctx->r15 & 31));
    // 0x80003284: srl         $t9, $t8, 31
    ctx->r25 = S32(U32(ctx->r24) >> 31);
    // 0x80003288: bnel        $t9, $zero, L_8000329C
    if (ctx->r25 != 0) {
        // 0x8000328C: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_8000329C;
    }
    goto skip_8;
    // 0x8000328C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_8:
    // 0x80003290: b           L_8000329C
    // 0x80003294: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
        goto L_8000329C;
    // 0x80003294: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80003298: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_8000329C:
    // 0x8000329C: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x800032A0: bne         $t0, $zero, L_80003248
    if (ctx->r8 != 0) {
        // 0x800032A4: nop
    
            goto L_80003248;
    }
    // 0x800032A4: nop

L_800032A8:
    // 0x800032A8: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800032AC: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800032B0: beq         $at, $zero, L_800032E4
    if (ctx->r1 == 0) {
        // 0x800032B4: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_800032E4;
    }
    // 0x800032B4: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x800032B8: bnel        $at, $zero, L_800032D4
    if (ctx->r1 != 0) {
        // 0x800032BC: lhu         $t1, 0x0($a0)
        ctx->r9 = MEM_HU(ctx->r4, 0X0);
            goto L_800032D4;
    }
    goto skip_9;
    // 0x800032BC: lhu         $t1, 0x0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X0);
    skip_9:
    // 0x800032C0: jalr        $s6
    // 0x800032C4: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_12;
    // 0x800032C4: nop

    after_12:
    // 0x800032C8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800032CC: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800032D0: lhu         $t1, 0x0($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X0);
L_800032D4:
    // 0x800032D4: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800032D8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800032DC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800032E0: or          $s2, $s2, $t1
    ctx->r18 = ctx->r18 | ctx->r9;
L_800032E4:
    // 0x800032E4: subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // 0x800032E8: negu        $t2, $v1
    ctx->r10 = SUB32(0, ctx->r3);
    // 0x800032EC: subu        $t3, $t2, $s1
    ctx->r11 = SUB32(ctx->r10, ctx->r17);
    // 0x800032F0: sllv        $t5, $s2, $t3
    ctx->r13 = S32(ctx->r18 << (ctx->r11 & 31));
    // 0x800032F4: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    // 0x800032F8: srlv        $v0, $t5, $t4
    ctx->r2 = S32(U32(ctx->r13) >> (ctx->r12 & 31));
    // 0x800032FC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80003300: beql        $at, $zero, L_800033D8
    if (ctx->r1 == 0) {
        // 0x80003304: lw          $t1, 0x64($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X64);
            goto L_800033D8;
    }
    goto skip_10;
    // 0x80003304: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    skip_10:
    // 0x80003308: lw          $s0, 0x144($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X144);
    // 0x8000330C: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x80003310: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x80003314: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80003318: beql        $t8, $zero, L_80003384
    if (ctx->r24 == 0) {
        // 0x8000331C: lw          $v1, 0x8($s0)
        ctx->r3 = MEM_W(ctx->r16, 0X8);
            goto L_80003384;
    }
    goto skip_11;
    // 0x8000331C: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    skip_11:
L_80003320:
    // 0x80003320: bgtz        $s1, L_80003350
    if (SIGNED(ctx->r17) > 0) {
        // 0x80003324: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_80003350;
    }
    // 0x80003324: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80003328: bnel        $at, $zero, L_80003340
    if (ctx->r1 != 0) {
        // 0x8000332C: lhu         $t9, 0x0($a0)
        ctx->r25 = MEM_HU(ctx->r4, 0X0);
            goto L_80003340;
    }
    goto skip_12;
    // 0x8000332C: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    skip_12:
    // 0x80003330: jalr        $s6
    // 0x80003334: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_13;
    // 0x80003334: nop

    after_13:
    // 0x80003338: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8000333C: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
L_80003340:
    // 0x80003340: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80003344: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003348: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8000334C: or          $s2, $s2, $t9
    ctx->r18 = ctx->r18 | ctx->r25;
L_80003350:
    // 0x80003350: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80003354: subu        $t0, $s7, $s1
    ctx->r8 = SUB32(ctx->r23, ctx->r17);
    // 0x80003358: sllv        $t1, $s2, $t0
    ctx->r9 = S32(ctx->r18 << (ctx->r8 & 31));
    // 0x8000335C: srl         $t2, $t1, 31
    ctx->r10 = S32(U32(ctx->r9) >> 31);
    // 0x80003360: bnel        $t2, $zero, L_80003374
    if (ctx->r10 != 0) {
        // 0x80003364: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80003374;
    }
    goto skip_13;
    // 0x80003364: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_13:
    // 0x80003368: b           L_80003374
    // 0x8000336C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
        goto L_80003374;
    // 0x8000336C: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x80003370: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80003374:
    // 0x80003374: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80003378: bne         $t3, $zero, L_80003320
    if (ctx->r11 != 0) {
        // 0x8000337C: nop
    
            goto L_80003320;
    }
    // 0x8000337C: nop

    // 0x80003380: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
L_80003384:
    // 0x80003384: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80003388: beq         $at, $zero, L_800033BC
    if (ctx->r1 == 0) {
        // 0x8000338C: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_800033BC;
    }
    // 0x8000338C: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80003390: bnel        $at, $zero, L_800033AC
    if (ctx->r1 != 0) {
        // 0x80003394: lhu         $t5, 0x0($a0)
        ctx->r13 = MEM_HU(ctx->r4, 0X0);
            goto L_800033AC;
    }
    goto skip_14;
    // 0x80003394: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
    skip_14:
    // 0x80003398: jalr        $s6
    // 0x8000339C: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_14;
    // 0x8000339C: nop

    after_14:
    // 0x800033A0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800033A4: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x800033A8: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
L_800033AC:
    // 0x800033AC: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800033B0: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800033B4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800033B8: or          $s2, $s2, $t5
    ctx->r18 = ctx->r18 | ctx->r13;
L_800033BC:
    // 0x800033BC: subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // 0x800033C0: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    // 0x800033C4: subu        $t6, $t4, $s1
    ctx->r14 = SUB32(ctx->r12, ctx->r17);
    // 0x800033C8: sllv        $t7, $s2, $t6
    ctx->r15 = S32(ctx->r18 << (ctx->r14 & 31));
    // 0x800033CC: negu        $t8, $v1
    ctx->r24 = SUB32(0, ctx->r3);
    // 0x800033D0: srlv        $v0, $t7, $t8
    ctx->r2 = S32(U32(ctx->r15) >> (ctx->r24 & 31));
    // 0x800033D4: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
L_800033D8:
    // 0x800033D8: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800033DC: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800033E0: subu        $t0, $fp, $t9
    ctx->r8 = SUB32(ctx->r30, ctx->r25);
    // 0x800033E4: subu        $s0, $t0, $t1
    ctx->r16 = SUB32(ctx->r8, ctx->r9);
    // 0x800033E8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x800033EC: b           L_800034BC
    // 0x800033F0: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
        goto L_800034BC;
    // 0x800033F0: lw          $a1, 0x0($t2)
    ctx->r5 = MEM_W(ctx->r10, 0X0);
L_800033F4:
    // 0x800033F4: beq         $v0, $zero, L_8000345C
    if (ctx->r2 == 0) {
        // 0x800033F8: lw          $s0, 0x144($sp)
        ctx->r16 = MEM_W(ctx->r29, 0X144);
            goto L_8000345C;
    }
    // 0x800033F8: lw          $s0, 0x144($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X144);
L_800033FC:
    // 0x800033FC: bgtz        $s1, L_8000342C
    if (SIGNED(ctx->r17) > 0) {
        // 0x80003400: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_8000342C;
    }
    // 0x80003400: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80003404: bnel        $at, $zero, L_8000341C
    if (ctx->r1 != 0) {
        // 0x80003408: lhu         $t3, 0x0($a0)
        ctx->r11 = MEM_HU(ctx->r4, 0X0);
            goto L_8000341C;
    }
    goto skip_15;
    // 0x80003408: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
    skip_15:
    // 0x8000340C: jalr        $s6
    // 0x80003410: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_15;
    // 0x80003410: nop

    after_15:
    // 0x80003414: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003418: lhu         $t3, 0x0($a0)
    ctx->r11 = MEM_HU(ctx->r4, 0X0);
L_8000341C:
    // 0x8000341C: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80003420: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003424: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80003428: or          $s2, $s2, $t3
    ctx->r18 = ctx->r18 | ctx->r11;
L_8000342C:
    // 0x8000342C: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80003430: subu        $t5, $s7, $s1
    ctx->r13 = SUB32(ctx->r23, ctx->r17);
    // 0x80003434: sllv        $t4, $s2, $t5
    ctx->r12 = S32(ctx->r18 << (ctx->r13 & 31));
    // 0x80003438: srl         $t6, $t4, 31
    ctx->r14 = S32(U32(ctx->r12) >> 31);
    // 0x8000343C: bnel        $t6, $zero, L_80003450
    if (ctx->r14 != 0) {
        // 0x80003440: lw          $s0, 0x4($s0)
        ctx->r16 = MEM_W(ctx->r16, 0X4);
            goto L_80003450;
    }
    goto skip_16;
    // 0x80003440: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
    skip_16:
    // 0x80003444: b           L_80003450
    // 0x80003448: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
        goto L_80003450;
    // 0x80003448: lw          $s0, 0x0($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X0);
    // 0x8000344C: lw          $s0, 0x4($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X4);
L_80003450:
    // 0x80003450: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x80003454: bne         $t7, $zero, L_800033FC
    if (ctx->r15 != 0) {
        // 0x80003458: nop
    
            goto L_800033FC;
    }
    // 0x80003458: nop

L_8000345C:
    // 0x8000345C: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80003460: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80003464: beq         $at, $zero, L_80003498
    if (ctx->r1 == 0) {
        // 0x80003468: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_80003498;
    }
    // 0x80003468: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x8000346C: bnel        $at, $zero, L_80003488
    if (ctx->r1 != 0) {
        // 0x80003470: lhu         $t8, 0x0($a0)
        ctx->r24 = MEM_HU(ctx->r4, 0X0);
            goto L_80003488;
    }
    goto skip_17;
    // 0x80003470: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
    skip_17:
    // 0x80003474: jalr        $s6
    // 0x80003478: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_16;
    // 0x80003478: nop

    after_16:
    // 0x8000347C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003480: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80003484: lhu         $t8, 0x0($a0)
    ctx->r24 = MEM_HU(ctx->r4, 0X0);
L_80003488:
    // 0x80003488: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x8000348C: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003490: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x80003494: or          $s2, $s2, $t8
    ctx->r18 = ctx->r18 | ctx->r24;
L_80003498:
    // 0x80003498: subu        $s1, $s1, $v1
    ctx->r17 = SUB32(ctx->r17, ctx->r3);
    // 0x8000349C: negu        $t9, $v1
    ctx->r25 = SUB32(0, ctx->r3);
    // 0x800034A0: lw          $t3, 0x140($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X140);
    // 0x800034A4: subu        $t0, $t9, $s1
    ctx->r8 = SUB32(ctx->r25, ctx->r17);
    // 0x800034A8: sllv        $t1, $s2, $t0
    ctx->r9 = S32(ctx->r18 << (ctx->r8 & 31));
    // 0x800034AC: negu        $t2, $v1
    ctx->r10 = SUB32(0, ctx->r3);
    // 0x800034B0: srlv        $v0, $t1, $t2
    ctx->r2 = S32(U32(ctx->r9) >> (ctx->r10 & 31));
    // 0x800034B4: subu        $s0, $fp, $v0
    ctx->r16 = SUB32(ctx->r30, ctx->r2);
    // 0x800034B8: lw          $a1, 0x0($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X0);
L_800034BC:
    // 0x800034BC: beql        $a1, $zero, L_80003528
    if (ctx->r5 == 0) {
        // 0x800034C0: lw          $a1, 0x8($s3)
        ctx->r5 = MEM_W(ctx->r19, 0X8);
            goto L_80003528;
    }
    goto skip_18;
    // 0x800034C0: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    skip_18:
L_800034C4:
    // 0x800034C4: bgtz        $s1, L_800034F4
    if (SIGNED(ctx->r17) > 0) {
        // 0x800034C8: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_800034F4;
    }
    // 0x800034C8: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x800034CC: bnel        $at, $zero, L_800034E4
    if (ctx->r1 != 0) {
        // 0x800034D0: lhu         $t5, 0x0($a0)
        ctx->r13 = MEM_HU(ctx->r4, 0X0);
            goto L_800034E4;
    }
    goto skip_19;
    // 0x800034D0: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
    skip_19:
    // 0x800034D4: jalr        $s6
    // 0x800034D8: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_17;
    // 0x800034D8: nop

    after_17:
    // 0x800034DC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800034E0: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
L_800034E4:
    // 0x800034E4: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x800034E8: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800034EC: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800034F0: or          $s2, $s2, $t5
    ctx->r18 = ctx->r18 | ctx->r13;
L_800034F4:
    // 0x800034F4: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x800034F8: subu        $t4, $s7, $s1
    ctx->r12 = SUB32(ctx->r23, ctx->r17);
    // 0x800034FC: sllv        $t6, $s2, $t4
    ctx->r14 = S32(ctx->r18 << (ctx->r12 & 31));
    // 0x80003500: srl         $t7, $t6, 31
    ctx->r15 = S32(U32(ctx->r14) >> 31);
    // 0x80003504: bnel        $t7, $zero, L_80003518
    if (ctx->r15 != 0) {
        // 0x80003508: lw          $s3, 0x4($s3)
        ctx->r19 = MEM_W(ctx->r19, 0X4);
            goto L_80003518;
    }
    goto skip_20;
    // 0x80003508: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
    skip_20:
    // 0x8000350C: b           L_80003518
    // 0x80003510: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
        goto L_80003518;
    // 0x80003510: lw          $s3, 0x0($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X0);
    // 0x80003514: lw          $s3, 0x4($s3)
    ctx->r19 = MEM_W(ctx->r19, 0X4);
L_80003518:
    // 0x80003518: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8000351C: bne         $t8, $zero, L_800034C4
    if (ctx->r24 != 0) {
        // 0x80003520: nop
    
            goto L_800034C4;
    }
    // 0x80003520: nop

    // 0x80003524: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
L_80003528:
    // 0x80003528: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000352C: beq         $at, $zero, L_80003560
    if (ctx->r1 == 0) {
        // 0x80003530: sltu        $at, $a0, $s5
        ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
            goto L_80003560;
    }
    // 0x80003530: sltu        $at, $a0, $s5
    ctx->r1 = ctx->r4 < ctx->r21 ? 1 : 0;
    // 0x80003534: bnel        $at, $zero, L_80003550
    if (ctx->r1 != 0) {
        // 0x80003538: lhu         $t9, 0x0($a0)
        ctx->r25 = MEM_HU(ctx->r4, 0X0);
            goto L_80003550;
    }
    goto skip_21;
    // 0x80003538: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
    skip_21:
    // 0x8000353C: jalr        $s6
    // 0x80003540: nop

    LOOKUP_FUNC(ctx->r22)(rdram, ctx);
        goto after_18;
    // 0x80003540: nop

    after_18:
    // 0x80003544: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80003548: lw          $a1, 0x8($s3)
    ctx->r5 = MEM_W(ctx->r19, 0X8);
    // 0x8000354C: lhu         $t9, 0x0($a0)
    ctx->r25 = MEM_HU(ctx->r4, 0X0);
L_80003550:
    // 0x80003550: sll         $s2, $s2, 16
    ctx->r18 = S32(ctx->r18 << 16);
    // 0x80003554: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80003558: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x8000355C: or          $s2, $s2, $t9
    ctx->r18 = ctx->r18 | ctx->r25;
L_80003560:
    // 0x80003560: subu        $s1, $s1, $a1
    ctx->r17 = SUB32(ctx->r17, ctx->r5);
    // 0x80003564: negu        $t0, $a1
    ctx->r8 = SUB32(0, ctx->r5);
    // 0x80003568: subu        $t1, $t0, $s1
    ctx->r9 = SUB32(ctx->r8, ctx->r17);
    // 0x8000356C: sllv        $t2, $s2, $t1
    ctx->r10 = S32(ctx->r18 << (ctx->r9 & 31));
    // 0x80003570: negu        $t3, $a1
    ctx->r11 = SUB32(0, ctx->r5);
    // 0x80003574: srlv        $v0, $t2, $t3
    ctx->r2 = S32(U32(ctx->r10) >> (ctx->r11 & 31));
    // 0x80003578: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000357C: beq         $v1, $zero, L_800035A0
    if (ctx->r3 == 0) {
        // 0x80003580: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800035A0;
    }
    // 0x80003580: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
L_80003584:
    // 0x80003584: lbu         $t5, 0x0($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X0);
    // 0x80003588: slt         $v1, $zero, $v0
    ctx->r3 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000358C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x80003590: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x80003594: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80003598: bne         $v1, $zero, L_80003584
    if (ctx->r3 != 0) {
        // 0x8000359C: sb          $t5, -0x1($fp)
        MEM_B(-0X1, ctx->r30) = ctx->r13;
            goto L_80003584;
    }
    // 0x8000359C: sb          $t5, -0x1($fp)
    MEM_B(-0X1, ctx->r30) = ctx->r13;
L_800035A0:
    // 0x800035A0: lw          $t4, 0x138($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X138);
    // 0x800035A4: sltu        $at, $fp, $t4
    ctx->r1 = ctx->r30 < ctx->r12 ? 1 : 0;
    // 0x800035A8: bne         $at, $zero, L_80003190
    if (ctx->r1 != 0) {
        // 0x800035AC: nop
    
            goto L_80003190;
    }
    // 0x800035AC: nop

L_800035B0:
    // 0x800035B0: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800035B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800035B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800035BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800035C0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800035C4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800035C8: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800035CC: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800035D0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800035D4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800035D8: jr          $ra
    // 0x800035DC: addiu       $sp, $sp, 0x458
    ctx->r29 = ADD32(ctx->r29, 0X458);
    return;
    // 0x800035DC: addiu       $sp, $sp, 0x458
    ctx->r29 = ADD32(ctx->r29, 0X458);
;}
RECOMP_FUNC void itLinkBombWaitProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80185DCC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80185DD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80185DD4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80185DD8: lw          $a3, 0x84($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X84);
    // 0x80185DDC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80185DE0: lwc1        $f0, 0x2C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x80185DE4: c.eq.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl == ctx->f0.fl;
    // 0x80185DE8: nop

    // 0x80185DEC: bc1tl       L_80185E20
    if (c1cs) {
        // 0x80185DF0: c.lt.s      $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
            goto L_80185E20;
    }
    goto skip_0;
    // 0x80185DF0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    skip_0:
    // 0x80185DF4: lw          $t7, 0x24($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X24);
    // 0x80185DF8: lui         $at, 0xBF80
    ctx->r1 = S32(0XBF80 << 16);
    // 0x80185DFC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80185E00: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80185E04: nop

    // 0x80185E08: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80185E0C: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80185E10: add.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x80185E14: swc1        $f16, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f16.u32l;
    // 0x80185E18: lwc1        $f0, 0x2C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x80185E1C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
L_80185E20:
    // 0x80185E20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80185E24: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80185E28: bc1fl       L_80185E3C
    if (!c1cs) {
        // 0x80185E2C: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80185E3C;
    }
    goto skip_1;
    // 0x80185E2C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_1:
    // 0x80185E30: b           L_80185E3C
    // 0x80185E34: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80185E3C;
    // 0x80185E34: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80185E38: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80185E3C:
    // 0x80185E3C: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80185E40: nop

    // 0x80185E44: bc1fl       L_80185E5C
    if (!c1cs) {
        // 0x80185E48: lw          $v1, 0x2C0($a3)
        ctx->r3 = MEM_W(ctx->r7, 0X2C0);
            goto L_80185E5C;
    }
    goto skip_2;
    // 0x80185E48: lw          $v1, 0x2C0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C0);
    skip_2:
    // 0x80185E4C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80185E50: nop

    // 0x80185E54: swc1        $f6, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->f6.u32l;
    // 0x80185E58: lw          $v1, 0x2C0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C0);
L_80185E5C:
    // 0x80185E5C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80185E60: bnel        $v1, $zero, L_80185E7C
    if (ctx->r3 != 0) {
        // 0x80185E64: mtc1        $v1, $f4
        ctx->f4.u32l = ctx->r3;
            goto L_80185E7C;
    }
    goto skip_3;
    // 0x80185E64: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    skip_3:
    // 0x80185E68: jal         0x80186368
    // 0x80185E6C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itLinkBombExplodeInitVars(rdram, ctx);
        goto after_0;
    // 0x80185E6C: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80185E70: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80185E74: lw          $v1, 0x2C0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C0);
    // 0x80185E78: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
L_80185E7C:
    // 0x80185E7C: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x80185E80: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80185E84: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80185E88: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80185E8C: addiu       $a1, $zero, 0x4F
    ctx->r5 = ADD32(0, 0X4F);
    // 0x80185E90: addiu       $a2, $zero, 0x60
    ctx->r6 = ADD32(0, 0X60);
    // 0x80185E94: c.eq.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl == ctx->f0.fl;
    // 0x80185E98: nop

    // 0x80185E9C: bc1fl       L_80185ECC
    if (!c1cs) {
        // 0x80185EA0: lui         $at, 0x42C0
        ctx->r1 = S32(0X42C0 << 16);
            goto L_80185ECC;
    }
    goto skip_4;
    // 0x80185EA0: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    skip_4:
    // 0x80185EA4: jal         0x80172F98
    // 0x80185EA8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itMainCheckSetColAnimID(rdram, ctx);
        goto after_1;
    // 0x80185EA8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_1:
    // 0x80185EAC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80185EB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80185EB4: lw          $v1, 0x2C0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C0);
    // 0x80185EB8: sh          $t8, 0x354($a3)
    MEM_H(0X354, ctx->r7) = ctx->r24;
    // 0x80185EBC: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80185EC0: nop

    // 0x80185EC4: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80185EC8: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
L_80185ECC:
    // 0x80185ECC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80185ED0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80185ED4: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x80185ED8: nop

    // 0x80185EDC: bc1fl       L_80185EF8
    if (!c1cs) {
        // 0x80185EE0: addiu       $t9, $v1, -0x1
        ctx->r25 = ADD32(ctx->r3, -0X1);
            goto L_80185EF8;
    }
    goto skip_5;
    // 0x80185EE0: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
    skip_5:
    // 0x80185EE4: jal         0x801859C0
    // 0x80185EE8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    itLinkBombExplodeWaitUpdateScale(rdram, ctx);
        goto after_2;
    // 0x80185EE8: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_2:
    // 0x80185EEC: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80185EF0: lw          $v1, 0x2C0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X2C0);
    // 0x80185EF4: addiu       $t9, $v1, -0x1
    ctx->r25 = ADD32(ctx->r3, -0X1);
L_80185EF8:
    // 0x80185EF8: sw          $t9, 0x2C0($a3)
    MEM_W(0X2C0, ctx->r7) = ctx->r25;
    // 0x80185EFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80185F00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80185F04: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80185F08: jr          $ra
    // 0x80185F0C: nop

    return;
    // 0x80185F0C: nop

;}
RECOMP_FUNC void ftPurinSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801513F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801513F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801513F8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801513FC: jal         0x800DDE84
    // 0x80151400: addiu       $a1, $a1, 0x1478
    ctx->r5 = ADD32(ctx->r5, 0X1478);
    mpCommonProcFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x80151400: addiu       $a1, $a1, 0x1478
    ctx->r5 = ADD32(ctx->r5, 0X1478);
    after_0:
    // 0x80151404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80151408: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015140C: jr          $ra
    // 0x80151410: nop

    return;
    // 0x80151410: nop

;}
RECOMP_FUNC void ftCommonThrownDecideFighterLoseGrip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014AECC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014AED0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014AED4: lw          $t6, 0x84($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X84);
    // 0x8014AED8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8014AEDC: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8014AEE0: lw          $t7, 0x190($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X190);
    // 0x8014AEE4: sll         $t9, $t7, 19
    ctx->r25 = S32(ctx->r15 << 19);
    // 0x8014AEE8: bgezl       $t9, L_8014AF04
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8014AEEC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8014AF04;
    }
    goto skip_0;
    // 0x8014AEEC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x8014AEF0: jal         0x8014ADB0
    // 0x8014AEF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftCommonThrownReleaseFighterLoseGrip(rdram, ctx);
        goto after_0;
    // 0x8014AEF4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8014AEF8: b           L_8014AF10
    // 0x8014AEFC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
        goto L_8014AF10;
    // 0x8014AEFC: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8014AF00: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_8014AF04:
    // 0x8014AF04: jal         0x8014ADB0
    // 0x8014AF08: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    ftCommonThrownReleaseFighterLoseGrip(rdram, ctx);
        goto after_1;
    // 0x8014AF08: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8014AF0C: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
L_8014AF10:
    // 0x8014AF10: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8014AF14: sw          $zero, 0x844($t0)
    MEM_W(0X844, ctx->r8) = 0;
    // 0x8014AF18: sw          $zero, 0x840($v0)
    MEM_W(0X840, ctx->r2) = 0;
    // 0x8014AF1C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8014AF20: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014AF24: jr          $ra
    // 0x8014AF28: nop

    return;
    // 0x8014AF28: nop

;}
RECOMP_FUNC void mn1PModeMake1PGame(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131E38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131E3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131E44: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80131E48: jal         0x80009968
    // 0x80131E4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131E4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131E50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131E54: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x80131E58: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80131E5C: sw          $v0, 0x31A0($at)
    MEM_W(0X31A0, ctx->r1) = ctx->r2;
    // 0x80131E60: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131E64: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80131E68: addiu       $a1, $a1, -0x3100
    ctx->r5 = ADD32(ctx->r5, -0X3100);
    // 0x80131E6C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131E70: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x80131E74: jal         0x80009DF4
    // 0x80131E78: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80131E78: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x80131E7C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131E80: lui         $a1, 0x42F8
    ctx->r5 = S32(0X42F8 << 16);
    // 0x80131E84: lui         $a2, 0x4228
    ctx->r6 = S32(0X4228 << 16);
    // 0x80131E88: jal         0x80131D04
    // 0x80131E8C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    mn1PModeMakeOptionTab(rdram, ctx);
        goto after_2;
    // 0x80131E8C: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x80131E90: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131E94: lw          $a1, 0x31B8($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X31B8);
    // 0x80131E98: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131E9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131EA0: jal         0x80131B24
    // 0x80131EA4: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    mn1PModeSetOptionSpriteColors(rdram, ctx);
        goto after_3;
    // 0x80131EA4: sltiu       $a1, $a1, 0x1
    ctx->r5 = ctx->r5 < 0X1 ? 1 : 0;
    after_3:
    // 0x80131EA8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x80131EAC: lw          $t7, 0x3294($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3294);
    // 0x80131EB0: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x80131EB4: addiu       $t8, $t8, 0x2A28
    ctx->r24 = ADD32(ctx->r24, 0X2A28);
    // 0x80131EB8: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131EBC: jal         0x800CCFDC
    // 0x80131EC0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_4;
    // 0x80131EC0: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_4:
    // 0x80131EC4: lhu         $t9, 0x24($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X24);
    // 0x80131EC8: lui         $at, 0x4321
    ctx->r1 = S32(0X4321 << 16);
    // 0x80131ECC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80131ED0: lui         $at, 0x4238
    ctx->r1 = S32(0X4238 << 16);
    // 0x80131ED4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80131ED8: andi        $t1, $t9, 0xFFDF
    ctx->r9 = ctx->r25 & 0XFFDF;
    // 0x80131EDC: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x80131EE0: ori         $t2, $t1, 0x1
    ctx->r10 = ctx->r9 | 0X1;
    // 0x80131EE4: sh          $t2, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r10;
    // 0x80131EE8: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80131EEC: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80131EF0: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x80131EF4: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80131EF8: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80131EFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131F00: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131F04: jr          $ra
    // 0x80131F08: nop

    return;
    // 0x80131F08: nop

;}
RECOMP_FUNC void itMapCheckMapReboundProcNoFloor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80173EE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80173EEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80173EF0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80173EF4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80173EF8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80173EFC: jal         0x801737B8
    // 0x80173F00: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    itMapTestAllCollisionFlag(rdram, ctx);
        goto after_0;
    // 0x80173F00: addiu       $a1, $zero, 0x800
    ctx->r5 = ADD32(0, 0X800);
    after_0:
    // 0x80173F04: beq         $v0, $zero, L_80173F1C
    if (ctx->r2 == 0) {
        // 0x80173F08: lw          $v1, 0x20($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X20);
            goto L_80173F1C;
    }
    // 0x80173F08: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80173F0C: beql        $v1, $zero, L_80173F20
    if (ctx->r3 == 0) {
        // 0x80173F10: lw          $a0, 0x18($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X18);
            goto L_80173F20;
    }
    goto skip_0;
    // 0x80173F10: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    skip_0:
    // 0x80173F14: jalr        $v1
    // 0x80173F18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    LOOKUP_FUNC(ctx->r3)(rdram, ctx);
        goto after_1;
    // 0x80173F18: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
L_80173F1C:
    // 0x80173F1C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
L_80173F20:
    // 0x80173F20: addiu       $a1, $zero, 0x421
    ctx->r5 = ADD32(0, 0X421);
    // 0x80173F24: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80173F28: jal         0x801737EC
    // 0x80173F2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    itMapCheckCollideAllRebound(rdram, ctx);
        goto after_2;
    // 0x80173F2C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80173F30: beql        $v0, $zero, L_80173F44
    if (ctx->r2 == 0) {
        // 0x80173F34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80173F44;
    }
    goto skip_1;
    // 0x80173F34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80173F38: jal         0x80172508
    // 0x80173F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainSetSpinVelLR(rdram, ctx);
        goto after_3;
    // 0x80173F3C: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80173F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80173F44:
    // 0x80173F44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80173F48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80173F4C: jr          $ra
    // 0x80173F50: nop

    return;
    // 0x80173F50: nop

;}
RECOMP_FUNC void mnPlayersVSMakeTimeSelect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80133FAC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80133FB0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80133FB4: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80133FB8: lw          $a0, -0x4288($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4288);
    // 0x80133FBC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80133FC0: beq         $a0, $zero, L_80133FD0
    if (ctx->r4 == 0) {
        // 0x80133FC4: nop
    
            goto L_80133FD0;
    }
    // 0x80133FC4: nop

    // 0x80133FC8: jal         0x80009A84
    // 0x80133FCC: nop

    gcEjectGObj(rdram, ctx);
        goto after_0;
    // 0x80133FCC: nop

    after_0:
L_80133FD0:
    // 0x80133FD0: lui         $t9, 0x8014
    ctx->r25 = S32(0X8014 << 16);
    // 0x80133FD4: lw          $t9, -0x3B60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3B60);
    // 0x80133FD8: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x80133FDC: addiu       $t0, $t0, 0x48B0
    ctx->r8 = ADD32(ctx->r8, 0X48B0);
    // 0x80133FE0: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133FE4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x80133FE8: addiu       $t6, $t6, -0x3100
    ctx->r14 = ADD32(ctx->r14, -0X3100);
    // 0x80133FEC: addiu       $t7, $zero, 0x1A
    ctx->r15 = ADD32(0, 0X1A);
    // 0x80133FF0: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80133FF4: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133FF8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80133FFC: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80134000: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x80134004: sw          $t3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r11;
    // 0x80134008: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8013400C: sw          $t8, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r24;
    // 0x80134010: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80134014: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80134018: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x8013401C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80134020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80134024: addiu       $a2, $zero, 0x19
    ctx->r6 = ADD32(0, 0X19);
    // 0x80134028: jal         0x800CD050
    // 0x8013402C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    lbCommonMakeSpriteGObj(rdram, ctx);
        goto after_1;
    // 0x8013402C: sw          $zero, 0x28($sp)
    MEM_W(0X28, ctx->r29) = 0;
    after_1:
    // 0x80134030: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134034: sw          $v0, -0x4288($at)
    MEM_W(-0X4288, ctx->r1) = ctx->r2;
    // 0x80134038: lui         $at, 0x430C
    ctx->r1 = S32(0X430C << 16);
    // 0x8013403C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80134040: lw          $t4, 0x74($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X74);
    // 0x80134044: lui         $at, 0x41B0
    ctx->r1 = S32(0X41B0 << 16);
    // 0x80134048: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8013404C: swc1        $f4, 0x58($t4)
    MEM_W(0X58, ctx->r12) = ctx->f4.u32l;
    // 0x80134050: lw          $t5, 0x74($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X74);
    // 0x80134054: lui         $a0, 0x8014
    ctx->r4 = S32(0X8014 << 16);
    // 0x80134058: swc1        $f6, 0x5C($t5)
    MEM_W(0X5C, ctx->r13) = ctx->f6.u32l;
    // 0x8013405C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80134060: lhu         $t6, 0x24($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X24);
    // 0x80134064: andi        $t7, $t6, 0xFFDF
    ctx->r15 = ctx->r14 & 0XFFDF;
    // 0x80134068: sh          $t7, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r15;
    // 0x8013406C: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80134070: lhu         $t8, 0x24($v1)
    ctx->r24 = MEM_HU(ctx->r3, 0X24);
    // 0x80134074: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x80134078: sh          $t9, 0x24($v1)
    MEM_H(0X24, ctx->r3) = ctx->r25;
    // 0x8013407C: jal         0x80133E28
    // 0x80134080: lw          $a0, -0x4284($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4284);
    mnPlayersVSMakeTimeSetting(rdram, ctx);
        goto after_2;
    // 0x80134080: lw          $a0, -0x4284($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X4284);
    after_2:
    // 0x80134084: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80134088: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x8013408C: jr          $ra
    // 0x80134090: nop

    return;
    // 0x80134090: nop

;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void ftKirbyCopyLinkSpecialNMakeBoomerang(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164688: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8016468C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80164690: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80164694: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80164698: lw          $t6, 0x17C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X17C);
    // 0x8016469C: beql        $t6, $zero, L_801646E4
    if (ctx->r14 == 0) {
        // 0x801646A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801646E4;
    }
    goto skip_0;
    // 0x801646A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x801646A4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x801646A8: sw          $zero, 0x17C($v1)
    MEM_W(0X17C, ctx->r3) = 0;
    // 0x801646AC: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x801646B0: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x801646B4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    // 0x801646B8: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x801646BC: lw          $a0, 0x8E8($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X8E8);
    // 0x801646C0: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x801646C4: jal         0x800EDF24
    // 0x801646C8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    gmCollisionGetFighterPartsWorldPosition(rdram, ctx);
        goto after_0;
    // 0x801646C8: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    after_0:
    // 0x801646CC: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x801646D0: jal         0x8016DA78
    // 0x801646D4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    wpLinkBoomerangMakeWeapon(rdram, ctx);
        goto after_1;
    // 0x801646D4: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    after_1:
    // 0x801646D8: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x801646DC: sw          $v0, 0xAF8($v1)
    MEM_W(0XAF8, ctx->r3) = ctx->r2;
    // 0x801646E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801646E4:
    // 0x801646E4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801646E8: jr          $ra
    // 0x801646EC: nop

    return;
    // 0x801646EC: nop

;}
RECOMP_FUNC void func_ovl8_80373990(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373990: beq         $a0, $zero, L_8037399C
    if (ctx->r4 == 0) {
        // 0x80373994: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8037399C;
    }
    // 0x80373994: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80373998: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
L_8037399C:
    // 0x8037399C: lwl         $t7, 0x2($v0)
    ctx->r15 = do_lwl(rdram, ctx->r15, ctx->r2, 0X2);
    // 0x803739A0: lwr         $t7, 0x5($v0)
    ctx->r15 = do_lwr(rdram, ctx->r15, ctx->r2, 0X5);
    // 0x803739A4: swl         $t7, 0x0($a1)
    do_swl(rdram, 0X0, ctx->r5, ctx->r15);
    // 0x803739A8: swr         $t7, 0x3($a1)
    do_swr(rdram, 0X3, ctx->r5, ctx->r15);
    // 0x803739AC: lwl         $t6, 0x6($v0)
    ctx->r14 = do_lwl(rdram, ctx->r14, ctx->r2, 0X6);
    // 0x803739B0: lwr         $t6, 0x9($v0)
    ctx->r14 = do_lwr(rdram, ctx->r14, ctx->r2, 0X9);
    // 0x803739B4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x803739B8: swl         $t6, 0x4($a1)
    do_swl(rdram, 0X4, ctx->r5, ctx->r14);
    // 0x803739BC: beq         $a0, $zero, L_803739C8
    if (ctx->r4 == 0) {
        // 0x803739C0: swr         $t6, 0x7($a1)
        do_swr(rdram, 0X7, ctx->r5, ctx->r14);
            goto L_803739C8;
    }
    // 0x803739C0: swr         $t6, 0x7($a1)
    do_swr(rdram, 0X7, ctx->r5, ctx->r14);
    // 0x803739C4: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
L_803739C8:
    // 0x803739C8: lwl         $t9, 0x14($v0)
    ctx->r25 = do_lwl(rdram, ctx->r25, ctx->r2, 0X14);
    // 0x803739CC: lwr         $t9, 0x17($v0)
    ctx->r25 = do_lwr(rdram, ctx->r25, ctx->r2, 0X17);
    // 0x803739D0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x803739D4: swl         $t9, 0x8($a1)
    do_swl(rdram, 0X8, ctx->r5, ctx->r25);
    // 0x803739D8: beq         $a0, $zero, L_803739E4
    if (ctx->r4 == 0) {
        // 0x803739DC: swr         $t9, 0xB($a1)
        do_swr(rdram, 0XB, ctx->r5, ctx->r25);
            goto L_803739E4;
    }
    // 0x803739DC: swr         $t9, 0xB($a1)
    do_swr(rdram, 0XB, ctx->r5, ctx->r25);
    // 0x803739E0: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
L_803739E4:
    // 0x803739E4: lwl         $t1, 0x18($v0)
    ctx->r9 = do_lwl(rdram, ctx->r9, ctx->r2, 0X18);
    // 0x803739E8: lwr         $t1, 0x1B($v0)
    ctx->r9 = do_lwr(rdram, ctx->r9, ctx->r2, 0X1B);
    // 0x803739EC: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x803739F0: swl         $t1, 0xC($a1)
    do_swl(rdram, 0XC, ctx->r5, ctx->r9);
    // 0x803739F4: beq         $a0, $zero, L_80373A00
    if (ctx->r4 == 0) {
        // 0x803739F8: swr         $t1, 0xF($a1)
        do_swr(rdram, 0XF, ctx->r5, ctx->r9);
            goto L_80373A00;
    }
    // 0x803739F8: swr         $t1, 0xF($a1)
    do_swr(rdram, 0XF, ctx->r5, ctx->r9);
    // 0x803739FC: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
L_80373A00:
    // 0x80373A00: lw          $t2, 0xC($v0)
    ctx->r10 = MEM_W(ctx->r2, 0XC);
    // 0x80373A04: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x80373A08: beq         $a0, $zero, L_80373A14
    if (ctx->r4 == 0) {
        // 0x80373A0C: sw          $t2, 0x18($a1)
        MEM_W(0X18, ctx->r5) = ctx->r10;
            goto L_80373A14;
    }
    // 0x80373A0C: sw          $t2, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->r10;
    // 0x80373A10: lw          $v0, 0x38($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X38);
L_80373A14:
    // 0x80373A14: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x80373A18: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
    // 0x80373A1C: lh          $t4, 0x1E($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X1E);
    // 0x80373A20: jr          $ra
    // 0x80373A24: sh          $t4, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r12;
    return;
    // 0x80373A24: sh          $t4, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r12;
;}
RECOMP_FUNC void mnPlayersVSUpdateFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80136128: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x8013612C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80136130: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x80136134: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80136138: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8013613C: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80136140: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80136144: addiu       $t7, $t7, -0x4578
    ctx->r15 = ADD32(ctx->r15, -0X4578);
    // 0x80136148: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8013614C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x80136150: lw          $v1, 0x8($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X8);
    // 0x80136154: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80136158: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8013615C: beq         $v1, $zero, L_801361AC
    if (ctx->r3 == 0) {
        // 0x80136160: nop
    
            goto L_801361AC;
    }
    // 0x80136160: nop

    // 0x80136164: lw          $t8, 0x84($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X84);
    // 0x80136168: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8013616C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80136170: bnel        $t8, $at, L_80136188
    if (ctx->r24 != ctx->r1) {
        // 0x80136174: lw          $t0, 0x48($s0)
        ctx->r8 = MEM_W(ctx->r16, 0X48);
            goto L_80136188;
    }
    goto skip_0;
    // 0x80136174: lw          $t0, 0x48($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X48);
    skip_0:
    // 0x80136178: sw          $t9, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->r25;
    // 0x8013617C: b           L_801361AC
    // 0x80136180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_801361AC;
    // 0x80136180: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80136184: lw          $t0, 0x48($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X48);
L_80136188:
    // 0x80136188: addiu       $at, $zero, 0x1C
    ctx->r1 = ADD32(0, 0X1C);
    // 0x8013618C: bne         $t0, $at, L_801361AC
    if (ctx->r8 != ctx->r1) {
        // 0x80136190: nop
    
            goto L_801361AC;
    }
    // 0x80136190: nop

    // 0x80136194: lw          $t1, 0x58($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X58);
    // 0x80136198: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8013619C: bne         $t1, $zero, L_801361AC
    if (ctx->r9 != 0) {
        // 0x801361A0: nop
    
            goto L_801361AC;
    }
    // 0x801361A0: nop

    // 0x801361A4: sw          $t2, 0x7C($v1)
    MEM_W(0X7C, ctx->r3) = ctx->r10;
    // 0x801361A8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_801361AC:
    // 0x801361AC: bnel        $v0, $zero, L_801361E8
    if (ctx->r2 != 0) {
        // 0x801361B0: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_801361E8;
    }
    goto skip_1;
    // 0x801361B0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_1:
    // 0x801361B4: jal         0x80131B78
    // 0x801361B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    mnPlayersVSGetShade(rdram, ctx);
        goto after_0;
    // 0x801361B8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x801361BC: sw          $v0, 0x50($s0)
    MEM_W(0X50, ctx->r16) = ctx->r2;
    // 0x801361C0: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x801361C4: jal         0x8013487C
    // 0x801361C8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    mnPlayersVSGetFreeCostume(rdram, ctx);
        goto after_1;
    // 0x801361C8: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x801361CC: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x801361D0: lw          $a1, 0x20($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X20);
    // 0x801361D4: lw          $a2, 0x48($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X48);
    // 0x801361D8: jal         0x80134A8C
    // 0x801361DC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    mnPlayersVSMakeFighter(rdram, ctx);
        goto after_2;
    // 0x801361DC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    after_2:
    // 0x801361E0: sw          $zero, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = 0;
    // 0x801361E4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801361E8:
    // 0x801361E8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801361EC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801361F0: jr          $ra
    // 0x801361F4: nop

    return;
    // 0x801361F4: nop

;}
RECOMP_FUNC void ftCommonGuardSetHitStatusYoshi(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80148218: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8014821C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80148220: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80148224: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x80148228: jal         0x800E8884
    // 0x8014822C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_0;
    // 0x8014822C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x80148230: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148234: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x80148238: jal         0x800E8884
    // 0x8014823C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_1;
    // 0x8014823C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_1:
    // 0x80148240: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148244: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x80148248: jal         0x800E8884
    // 0x8014824C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_2;
    // 0x8014824C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_2:
    // 0x80148250: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148254: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80148258: jal         0x800E8884
    // 0x8014825C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_3;
    // 0x8014825C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_3:
    // 0x80148260: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148264: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80148268: jal         0x800E8884
    // 0x8014826C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_4;
    // 0x8014826C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_4:
    // 0x80148270: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148274: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x80148278: jal         0x800E8884
    // 0x8014827C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_5;
    // 0x8014827C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_5:
    // 0x80148280: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148284: addiu       $a1, $zero, 0xC
    ctx->r5 = ADD32(0, 0XC);
    // 0x80148288: jal         0x800E8884
    // 0x8014828C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_6;
    // 0x8014828C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_6:
    // 0x80148290: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80148294: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80148298: jal         0x800E8884
    // 0x8014829C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_7;
    // 0x8014829C: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_7:
    // 0x801482A0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801482A4: addiu       $a1, $zero, 0x16
    ctx->r5 = ADD32(0, 0X16);
    // 0x801482A8: jal         0x800E8884
    // 0x801482AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_8;
    // 0x801482AC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_8:
    // 0x801482B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801482B4: addiu       $a1, $zero, 0x1C
    ctx->r5 = ADD32(0, 0X1C);
    // 0x801482B8: jal         0x800E8884
    // 0x801482BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_9;
    // 0x801482BC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_9:
    // 0x801482C0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801482C4: addiu       $a1, $zero, 0x17
    ctx->r5 = ADD32(0, 0X17);
    // 0x801482C8: jal         0x800E8884
    // 0x801482CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    ftParamSetHitStatusPartID(rdram, ctx);
        goto after_10;
    // 0x801482CC: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    after_10:
    // 0x801482D0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801482D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801482D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801482DC: jr          $ra
    // 0x801482E0: nop

    return;
    // 0x801482E0: nop

;}
RECOMP_FUNC void ftNessSpecialAirHiHoldProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80154210: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80154214: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80154218: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x8015421C: jal         0x800DE80C
    // 0x80154220: addiu       $a1, $a1, 0x4268
    ctx->r5 = ADD32(ctx->r5, 0X4268);
    mpCommonProcFighterCliff(rdram, ctx);
        goto after_0;
    // 0x80154220: addiu       $a1, $a1, 0x4268
    ctx->r5 = ADD32(ctx->r5, 0X4268);
    after_0:
    // 0x80154224: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80154228: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015422C: jr          $ra
    // 0x80154230: nop

    return;
    // 0x80154230: nop

;}
RECOMP_FUNC void ftKirbySpecialLwSetDamageResist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016141C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80161420: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80161424: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80161428: addiu       $t9, $zero, 0x26
    ctx->r25 = ADD32(0, 0X26);
    // 0x8016142C: addiu       $t0, $zero, 0xA0
    ctx->r8 = ADD32(0, 0XA0);
    // 0x80161430: lbu         $t7, 0x191($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X191);
    // 0x80161434: addiu       $t1, $zero, 0x33
    ctx->r9 = ADD32(0, 0X33);
    // 0x80161438: addiu       $a1, $zero, 0x33
    ctx->r5 = ADD32(0, 0X33);
    // 0x8016143C: ori         $t8, $t7, 0x20
    ctx->r24 = ctx->r15 | 0X20;
    // 0x80161440: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80161444: sb          $t8, 0x191($v0)
    MEM_B(0X191, ctx->r2) = ctx->r24;
    // 0x80161448: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
    // 0x8016144C: sh          $t0, 0xB18($v0)
    MEM_H(0XB18, ctx->r2) = ctx->r8;
    // 0x80161450: jal         0x800E9814
    // 0x80161454: sh          $t1, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r9;
    ftParamCheckSetFighterColAnimID(rdram, ctx);
        goto after_0;
    // 0x80161454: sh          $t1, 0xB1C($v0)
    MEM_H(0XB1C, ctx->r2) = ctx->r9;
    after_0:
    // 0x80161458: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8016145C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80161460: jr          $ra
    // 0x80161464: nop

    return;
    // 0x80161464: nop

;}
RECOMP_FUNC void mnSoundTestMakeStartFunctionSObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132DF8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132DFC: lw          $t6, 0x4478($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4478);
    // 0x80132E00: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132E04: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80132E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132E0C: addiu       $t7, $t7, 0x1348
    ctx->r15 = ADD32(ctx->r15, 0X1348);
    // 0x80132E10: jal         0x800CCFDC
    // 0x80132E14: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132E14: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80132E18: lui         $at, 0x4314
    ctx->r1 = S32(0X4314 << 16);
    // 0x80132E1C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132E20: lui         $at, 0x4350
    ctx->r1 = S32(0X4350 << 16);
    // 0x80132E24: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132E28: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80132E2C: addiu       $t9, $zero, 0x73
    ctx->r25 = ADD32(0, 0X73);
    // 0x80132E30: addiu       $t0, $zero, 0x6B
    ctx->r8 = ADD32(0, 0X6B);
    // 0x80132E34: addiu       $t1, $zero, 0x59
    ctx->r9 = ADD32(0, 0X59);
    // 0x80132E38: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132E3C: sb          $t9, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r25;
    // 0x80132E40: sb          $t0, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r8;
    // 0x80132E44: sb          $t1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r9;
    // 0x80132E48: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132E4C: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132E50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80132E54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80132E58: jr          $ra
    // 0x80132E5C: nop

    return;
    // 0x80132E5C: nop

;}
RECOMP_FUNC void ftPikachuSpecialAirLwHitSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801524EC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801524F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801524F4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x801524F8: jal         0x800DEE98
    // 0x801524FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x801524FC: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    after_0:
    // 0x80152500: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80152504: addiu       $t7, $zero, 0x97
    ctx->r15 = ADD32(0, 0X97);
    // 0x80152508: addiu       $a1, $zero, 0xE2
    ctx->r5 = ADD32(0, 0XE2);
    // 0x8015250C: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80152510: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80152514: jal         0x800E6F24
    // 0x80152518: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80152518: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015251C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80152520: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80152524: jr          $ra
    // 0x80152528: nop

    return;
    // 0x80152528: nop

;}
RECOMP_FUNC void func_ovl8_803762B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803762B4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x803762B8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803762BC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x803762C0: beq         $a0, $zero, L_803762CC
    if (ctx->r4 == 0) {
        // 0x803762C4: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_803762CC;
    }
    // 0x803762C4: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x803762C8: lw          $v1, 0x20($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X20);
L_803762CC:
    // 0x803762CC: lbu         $t6, 0x1B($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X1B);
    // 0x803762D0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x803762D4: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x803762D8: beql        $t6, $zero, L_80376498
    if (ctx->r14 == 0) {
        // 0x803762DC: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_80376498;
    }
    goto skip_0;
    // 0x803762DC: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    skip_0:
    // 0x803762E0: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x803762E4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x803762E8: lui         $t2, 0xE300
    ctx->r10 = S32(0XE300 << 16);
    // 0x803762EC: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x803762F0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x803762F4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x803762F8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x803762FC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80376300: ori         $t2, $t2, 0xA01
    ctx->r10 = ctx->r10 | 0XA01;
    // 0x80376304: lui         $t3, 0x30
    ctx->r11 = S32(0X30 << 16);
    // 0x80376308: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x8037630C: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80376310: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x80376314: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x80376318: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8037631C: lui         $t5, 0xF700
    ctx->r13 = S32(0XF700 << 16);
    // 0x80376320: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x80376324: sw          $t4, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r12;
    // 0x80376328: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8037632C: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80376330: beq         $a1, $zero, L_8037633C
    if (ctx->r5 == 0) {
        // 0x80376334: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8037633C;
    }
    // 0x80376334: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80376338: lw          $v1, 0x20($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X20);
L_8037633C:
    // 0x8037633C: beq         $a1, $zero, L_80376348
    if (ctx->r5 == 0) {
        // 0x80376340: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_80376348;
    }
    // 0x80376340: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80376344: lw          $v0, 0x20($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X20);
L_80376348:
    // 0x80376348: beq         $a1, $zero, L_80376354
    if (ctx->r5 == 0) {
        // 0x8037634C: or          $t0, $a1, $zero
        ctx->r8 = ctx->r5 | 0;
            goto L_80376354;
    }
    // 0x8037634C: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x80376350: lw          $t0, 0x20($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X20);
L_80376354:
    // 0x80376354: beq         $a1, $zero, L_80376360
    if (ctx->r5 == 0) {
        // 0x80376358: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80376360;
    }
    // 0x80376358: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8037635C: lw          $a2, 0x20($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X20);
L_80376360:
    // 0x80376360: lbu         $t6, 0x18($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X18);
    // 0x80376364: lbu         $t8, 0x19($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X19);
    // 0x80376368: lbu         $t3, 0x1A($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X1A);
    // 0x8037636C: sll         $t7, $t6, 24
    ctx->r15 = S32(ctx->r14 << 24);
    // 0x80376370: lbu         $t6, 0x1B($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0X1B);
    // 0x80376374: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x80376378: or          $t2, $t7, $t9
    ctx->r10 = ctx->r15 | ctx->r25;
    // 0x8037637C: sll         $t4, $t3, 8
    ctx->r12 = S32(ctx->r11 << 8);
    // 0x80376380: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x80376384: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x80376388: sw          $a1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r5;
    // 0x8037638C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80376390: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x80376394: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80376398: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x8037639C: jal         0x80006D70
    // 0x803763A0: or          $a0, $t5, $t6
    ctx->r4 = ctx->r13 | ctx->r14;
    syVideoGetFillColor(rdram, ctx);
        goto after_0;
    // 0x803763A0: or          $a0, $t5, $t6
    ctx->r4 = ctx->r13 | ctx->r14;
    after_0:
    // 0x803763A4: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x803763A8: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x803763AC: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x803763B0: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x803763B4: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x803763B8: addiu       $a3, $a3, 0x65B0
    ctx->r7 = ADD32(ctx->r7, 0X65B0);
    // 0x803763BC: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x803763C0: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x803763C4: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x803763C8: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x803763CC: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x803763D0: beq         $a1, $zero, L_803763DC
    if (ctx->r5 == 0) {
        // 0x803763D4: sw          $t8, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r24;
            goto L_803763DC;
    }
    // 0x803763D4: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x803763D8: lw          $v1, 0x20($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X20);
L_803763DC:
    // 0x803763DC: beq         $a1, $zero, L_803763E8
    if (ctx->r5 == 0) {
        // 0x803763E0: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_803763E8;
    }
    // 0x803763E0: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x803763E4: lw          $v0, 0x20($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X20);
L_803763E8:
    // 0x803763E8: beq         $a1, $zero, L_803763F4
    if (ctx->r5 == 0) {
        // 0x803763EC: nop
    
            goto L_803763F4;
    }
    // 0x803763EC: nop

    // 0x803763F0: lw          $t0, 0x20($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X20);
L_803763F4:
    // 0x803763F4: beql        $a1, $zero, L_80376404
    if (ctx->r5 == 0) {
        // 0x803763F8: lh          $t7, 0x2($v1)
        ctx->r15 = MEM_H(ctx->r3, 0X2);
            goto L_80376404;
    }
    goto skip_1;
    // 0x803763F8: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
    skip_1:
    // 0x803763FC: lw          $a2, 0x20($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X20);
    // 0x80376400: lh          $t7, 0x2($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X2);
L_80376404:
    // 0x80376404: lhu         $t9, 0x6($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X6);
    // 0x80376408: lh          $t8, 0x4($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X4);
    // 0x8037640C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80376410: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x80376414: lhu         $t7, 0x8($a2)
    ctx->r15 = MEM_HU(ctx->r6, 0X8);
    // 0x80376418: addiu       $t2, $t3, -0x1
    ctx->r10 = ADD32(ctx->r11, -0X1);
    // 0x8037641C: andi        $t4, $t2, 0x3FF
    ctx->r12 = ctx->r10 & 0X3FF;
    // 0x80376420: addu        $t9, $t8, $t7
    ctx->r25 = ADD32(ctx->r24, ctx->r15);
    // 0x80376424: addiu       $t3, $t9, -0x1
    ctx->r11 = ADD32(ctx->r25, -0X1);
    // 0x80376428: sll         $t5, $t4, 14
    ctx->r13 = S32(ctx->r12 << 14);
    // 0x8037642C: andi        $t2, $t3, 0x3FF
    ctx->r10 = ctx->r11 & 0X3FF;
    // 0x80376430: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x80376434: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80376438: or          $t5, $t6, $t4
    ctx->r13 = ctx->r14 | ctx->r12;
    // 0x8037643C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80376440: beq         $a1, $zero, L_8037644C
    if (ctx->r5 == 0) {
        // 0x80376444: or          $v1, $a1, $zero
        ctx->r3 = ctx->r5 | 0;
            goto L_8037644C;
    }
    // 0x80376444: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80376448: lw          $v1, 0x20($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X20);
L_8037644C:
    // 0x8037644C: beql        $a1, $zero, L_8037645C
    if (ctx->r5 == 0) {
        // 0x80376450: lh          $t8, 0x2($v1)
        ctx->r24 = MEM_H(ctx->r3, 0X2);
            goto L_8037645C;
    }
    goto skip_2;
    // 0x80376450: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
    skip_2:
    // 0x80376454: lw          $v0, 0x20($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X20);
    // 0x80376458: lh          $t8, 0x2($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X2);
L_8037645C:
    // 0x8037645C: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x80376460: andi        $t7, $t8, 0x3FF
    ctx->r15 = ctx->r24 & 0X3FF;
    // 0x80376464: andi        $t2, $t3, 0x3FF
    ctx->r10 = ctx->r11 & 0X3FF;
    // 0x80376468: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8037646C: sll         $t9, $t7, 14
    ctx->r25 = S32(ctx->r15 << 14);
    // 0x80376470: or          $t4, $t9, $t6
    ctx->r12 = ctx->r25 | ctx->r14;
    // 0x80376474: sw          $t4, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r12;
    // 0x80376478: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8037647C: lui         $t8, 0xE300
    ctx->r24 = S32(0XE300 << 16);
    // 0x80376480: ori         $t8, $t8, 0xA01
    ctx->r24 = ctx->r24 | 0XA01;
    // 0x80376484: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x80376488: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8037648C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x80376490: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80376494: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
L_80376498:
    // 0x80376498: jal         0x80375354
    // 0x8037649C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_80375354(rdram, ctx);
        goto after_1;
    // 0x8037649C: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x803764A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x803764A4: lw          $v1, 0x18($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X18);
    // 0x803764A8: lw          $t9, 0x84($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X84);
    // 0x803764AC: lh          $t7, 0x80($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X80);
    // 0x803764B0: jalr        $t9
    // 0x803764B4: addu        $a0, $t7, $a1
    ctx->r4 = ADD32(ctx->r15, ctx->r5);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x803764B4: addu        $a0, $t7, $a1
    ctx->r4 = ADD32(ctx->r15, ctx->r5);
    after_2:
    // 0x803764B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803764BC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x803764C0: jr          $ra
    // 0x803764C4: nop

    return;
    // 0x803764C4: nop

;}
RECOMP_FUNC void func_ovl8_80371FB0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371FB0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80371FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80371FB8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80371FBC: bne         $a0, $zero, L_80371FDC
    if (ctx->r4 != 0) {
        // 0x80371FC0: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80371FDC;
    }
    // 0x80371FC0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80371FC4: addiu       $a0, $zero, 0x70
    ctx->r4 = ADD32(0, 0X70);
    // 0x80371FC8: jal         0x803717A0
    // 0x80371FCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80371FCC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80371FD0: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x80371FD4: beq         $v0, $zero, L_80372028
    if (ctx->r2 == 0) {
        // 0x80371FD8: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_80372028;
    }
    // 0x80371FD8: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80371FDC:
    // 0x80371FDC: bne         $a3, $zero, L_80371FF8
    if (ctx->r7 != 0) {
        // 0x80371FE0: addiu       $a0, $a2, 0x14
        ctx->r4 = ADD32(ctx->r6, 0X14);
            goto L_80371FF8;
    }
    // 0x80371FE0: addiu       $a0, $a2, 0x14
    ctx->r4 = ADD32(ctx->r6, 0X14);
    // 0x80371FE4: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80371FE8: jal         0x803717E0
    // 0x80371FEC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x80371FEC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x80371FF0: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80371FF4: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
L_80371FF8:
    // 0x80371FF8: lui         $t6, 0x8039
    ctx->r14 = S32(0X8039 << 16);
    // 0x80371FFC: addiu       $t6, $t6, -0x7520
    ctx->r14 = ADD32(ctx->r14, -0X7520);
    // 0x80372000: lui         $t7, 0x8039
    ctx->r15 = S32(0X8039 << 16);
    // 0x80372004: addiu       $t7, $t7, -0x74C0
    ctx->r15 = ADD32(ctx->r15, -0X74C0);
    // 0x80372008: sw          $t6, 0xC($a2)
    MEM_W(0XC, ctx->r6) = ctx->r14;
    // 0x8037200C: sw          $a3, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r7;
    // 0x80372010: sw          $t7, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r15;
    // 0x80372014: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80372018: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8037201C: jal         0x80372420
    // 0x80372020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_ovl8_80372420(rdram, ctx);
        goto after_2;
    // 0x80372020: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80372024: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
L_80372028:
    // 0x80372028: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037202C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80372030: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x80372034: jr          $ra
    // 0x80372038: nop

    return;
    // 0x80372038: nop

;}
RECOMP_FUNC void itProcessSetHitInteractStats(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F930: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x8016F934: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8016F938: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_8016F93C:
    // 0x8016F93C: lw          $t6, 0x118($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X118);
    // 0x8016F940: bne         $a1, $t6, L_8016FA04
    if (ctx->r5 != ctx->r14) {
        // 0x8016F944: sltiu       $at, $a2, 0x7
        ctx->r1 = ctx->r6 < 0X7 ? 1 : 0;
            goto L_8016FA04;
    }
    // 0x8016F944: sltiu       $at, $a2, 0x7
    ctx->r1 = ctx->r6 < 0X7 ? 1 : 0;
    // 0x8016F948: beq         $at, $zero, L_8016FA14
    if (ctx->r1 == 0) {
        // 0x8016F94C: sll         $t7, $a2, 2
        ctx->r15 = S32(ctx->r6 << 2);
            goto L_8016FA14;
    }
    // 0x8016F94C: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x8016F950: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016F954: addu        $at, $at, $t7
    gpr jr_addend_8016F95C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8016F958: lw          $t7, -0x33E0($at)
    ctx->r15 = ADD32(ctx->r1, -0X33E0);
    // 0x8016F95C: jr          $t7
    // 0x8016F960: nop

    switch (jr_addend_8016F95C >> 2) {
        case 0: goto L_8016F964; break;
        case 1: goto L_8016F974; break;
        case 2: goto L_8016F984; break;
        case 3: goto L_8016F9C4; break;
        case 4: goto L_8016F9E4; break;
        case 5: goto L_8016FA14; break;
        case 6: goto L_8016F9A4; break;
        default: switch_error(__func__, 0x8016F95C, 0x8018CC20);
    }
    // 0x8016F960: nop

L_8016F964:
    // 0x8016F964: lbu         $t9, 0x11C($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016F968: ori         $t1, $t9, 0x80
    ctx->r9 = ctx->r25 | 0X80;
    // 0x8016F96C: b           L_8016FA14
    // 0x8016F970: sb          $t1, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r9;
        goto L_8016FA14;
    // 0x8016F970: sb          $t1, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r9;
L_8016F974:
    // 0x8016F974: lbu         $t3, 0x11C($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016F978: ori         $t4, $t3, 0x40
    ctx->r12 = ctx->r11 | 0X40;
    // 0x8016F97C: b           L_8016FA14
    // 0x8016F980: sb          $t4, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r12;
        goto L_8016FA14;
    // 0x8016F980: sb          $t4, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r12;
L_8016F984:
    // 0x8016F984: lbu         $t6, 0x11C($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016F988: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8016F98C: sb          $t7, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r15;
    // 0x8016F990: lhu         $t8, 0x11C($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X11C);
    // 0x8016F994: andi        $t9, $t8, 0xFE07
    ctx->r25 = ctx->r24 & 0XFE07;
    // 0x8016F998: ori         $t1, $t9, 0x80
    ctx->r9 = ctx->r25 | 0X80;
    // 0x8016F99C: b           L_8016FA14
    // 0x8016F9A0: sh          $t1, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r9;
        goto L_8016FA14;
    // 0x8016F9A0: sh          $t1, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r9;
L_8016F9A4:
    // 0x8016F9A4: lbu         $t3, 0x11C($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016F9A8: ori         $t4, $t3, 0x20
    ctx->r12 = ctx->r11 | 0X20;
    // 0x8016F9AC: sb          $t4, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r12;
    // 0x8016F9B0: lhu         $t5, 0x11C($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0X11C);
    // 0x8016F9B4: andi        $t6, $t5, 0xFE07
    ctx->r14 = ctx->r13 & 0XFE07;
    // 0x8016F9B8: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x8016F9BC: b           L_8016FA14
    // 0x8016F9C0: sh          $t7, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r15;
        goto L_8016FA14;
    // 0x8016F9C0: sh          $t7, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r15;
L_8016F9C4:
    // 0x8016F9C4: lw          $t9, 0xC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC);
    // 0x8016F9C8: lbu         $t3, 0x11C($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016F9CC: sll         $t1, $t9, 1
    ctx->r9 = S32(ctx->r25 << 1);
    // 0x8016F9D0: andi        $t2, $t1, 0xE
    ctx->r10 = ctx->r9 & 0XE;
    // 0x8016F9D4: andi        $t4, $t3, 0xFFF1
    ctx->r12 = ctx->r11 & 0XFFF1;
    // 0x8016F9D8: or          $t5, $t2, $t4
    ctx->r13 = ctx->r10 | ctx->r12;
    // 0x8016F9DC: b           L_8016FA14
    // 0x8016F9E0: sb          $t5, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r13;
        goto L_8016FA14;
    // 0x8016F9E0: sb          $t5, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r13;
L_8016F9E4:
    // 0x8016F9E4: lbu         $t7, 0x11C($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016F9E8: ori         $t8, $t7, 0x80
    ctx->r24 = ctx->r15 | 0X80;
    // 0x8016F9EC: sb          $t8, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r24;
    // 0x8016F9F0: lhu         $t9, 0x11C($t0)
    ctx->r25 = MEM_HU(ctx->r8, 0X11C);
    // 0x8016F9F4: andi        $t1, $t9, 0xFE07
    ctx->r9 = ctx->r25 & 0XFE07;
    // 0x8016F9F8: ori         $t3, $t1, 0x80
    ctx->r11 = ctx->r9 | 0X80;
    // 0x8016F9FC: b           L_8016FA14
    // 0x8016FA00: sh          $t3, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r11;
        goto L_8016FA14;
    // 0x8016FA00: sh          $t3, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r11;
L_8016FA04:
    // 0x8016FA04: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8016FA08: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8016FA0C: bne         $at, $zero, L_8016F93C
    if (ctx->r1 != 0) {
        // 0x8016FA10: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8016F93C;
    }
    // 0x8016FA10: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
L_8016FA14:
    // 0x8016FA14: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x8016FA18: bne         $v1, $at, L_8016FB10
    if (ctx->r3 != ctx->r1) {
        // 0x8016FA1C: or          $t0, $a0, $zero
        ctx->r8 = ctx->r4 | 0;
            goto L_8016FB10;
    }
    // 0x8016FA1C: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x8016FA20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8016FA24: or          $a3, $a2, $zero
    ctx->r7 = ctx->r6 | 0;
L_8016FA28:
    // 0x8016FA28: lw          $t2, 0x118($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X118);
    // 0x8016FA2C: beql        $t2, $zero, L_8016FA48
    if (ctx->r10 == 0) {
        // 0x8016FA30: addiu       $at, $zero, 0x20
        ctx->r1 = ADD32(0, 0X20);
            goto L_8016FA48;
    }
    goto skip_0;
    // 0x8016FA30: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    skip_0:
    // 0x8016FA34: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8016FA38: slti        $at, $v1, 0x20
    ctx->r1 = SIGNED(ctx->r3) < 0X20 ? 1 : 0;
    // 0x8016FA3C: bne         $at, $zero, L_8016FA28
    if (ctx->r1 != 0) {
        // 0x8016FA40: addiu       $t0, $t0, 0x8
        ctx->r8 = ADD32(ctx->r8, 0X8);
            goto L_8016FA28;
    }
    // 0x8016FA40: addiu       $t0, $t0, 0x8
    ctx->r8 = ADD32(ctx->r8, 0X8);
    // 0x8016FA44: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
L_8016FA48:
    // 0x8016FA48: bne         $v1, $at, L_8016FA54
    if (ctx->r3 != ctx->r1) {
        // 0x8016FA4C: sll         $t4, $a3, 2
        ctx->r12 = S32(ctx->r7 << 2);
            goto L_8016FA54;
    }
    // 0x8016FA4C: sll         $t4, $a3, 2
    ctx->r12 = S32(ctx->r7 << 2);
    // 0x8016FA50: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_8016FA54:
    // 0x8016FA54: sltiu       $at, $a3, 0x7
    ctx->r1 = ctx->r7 < 0X7 ? 1 : 0;
    // 0x8016FA58: beq         $at, $zero, L_8016FB10
    if (ctx->r1 == 0) {
        // 0x8016FA5C: sw          $a1, 0x118($t0)
        MEM_W(0X118, ctx->r8) = ctx->r5;
            goto L_8016FB10;
    }
    // 0x8016FA5C: sw          $a1, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->r5;
    // 0x8016FA60: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8016FA64: addu        $at, $at, $t4
    gpr jr_addend_8016FA6C = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8016FA68: lw          $t4, -0x33C4($at)
    ctx->r12 = ADD32(ctx->r1, -0X33C4);
    // 0x8016FA6C: jr          $t4
    // 0x8016FA70: nop

    switch (jr_addend_8016FA6C >> 2) {
        case 0: goto L_8016FA74; break;
        case 1: goto L_8016FA84; break;
        case 2: goto L_8016FA94; break;
        case 3: goto L_8016FAD4; break;
        case 4: goto L_8016FAF4; break;
        case 5: goto L_8016FB10; break;
        case 6: goto L_8016FAB4; break;
        default: switch_error(__func__, 0x8016FA6C, 0x8018CC3C);
    }
    // 0x8016FA70: nop

L_8016FA74:
    // 0x8016FA74: lbu         $t6, 0x11C($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016FA78: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x8016FA7C: jr          $ra
    // 0x8016FA80: sb          $t7, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r15;
    return;
    // 0x8016FA80: sb          $t7, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r15;
L_8016FA84:
    // 0x8016FA84: lbu         $t9, 0x11C($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016FA88: ori         $t1, $t9, 0x40
    ctx->r9 = ctx->r25 | 0X40;
    // 0x8016FA8C: jr          $ra
    // 0x8016FA90: sb          $t1, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r9;
    return;
    // 0x8016FA90: sb          $t1, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r9;
L_8016FA94:
    // 0x8016FA94: lbu         $t2, 0x11C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016FA98: ori         $t4, $t2, 0x40
    ctx->r12 = ctx->r10 | 0X40;
    // 0x8016FA9C: sb          $t4, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r12;
    // 0x8016FAA0: lhu         $t5, 0x11C($t0)
    ctx->r13 = MEM_HU(ctx->r8, 0X11C);
    // 0x8016FAA4: andi        $t6, $t5, 0xFE07
    ctx->r14 = ctx->r13 & 0XFE07;
    // 0x8016FAA8: ori         $t7, $t6, 0x80
    ctx->r15 = ctx->r14 | 0X80;
    // 0x8016FAAC: jr          $ra
    // 0x8016FAB0: sh          $t7, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r15;
    return;
    // 0x8016FAB0: sh          $t7, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r15;
L_8016FAB4:
    // 0x8016FAB4: lbu         $t9, 0x11C($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016FAB8: ori         $t1, $t9, 0x20
    ctx->r9 = ctx->r25 | 0X20;
    // 0x8016FABC: sb          $t1, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r9;
    // 0x8016FAC0: lhu         $t3, 0x11C($t0)
    ctx->r11 = MEM_HU(ctx->r8, 0X11C);
    // 0x8016FAC4: andi        $t2, $t3, 0xFE07
    ctx->r10 = ctx->r11 & 0XFE07;
    // 0x8016FAC8: ori         $t4, $t2, 0x80
    ctx->r12 = ctx->r10 | 0X80;
    // 0x8016FACC: jr          $ra
    // 0x8016FAD0: sh          $t4, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r12;
    return;
    // 0x8016FAD0: sh          $t4, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r12;
L_8016FAD4:
    // 0x8016FAD4: lw          $t6, 0xC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC);
    // 0x8016FAD8: lbu         $t9, 0x11C($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016FADC: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8016FAE0: andi        $t8, $t7, 0xE
    ctx->r24 = ctx->r15 & 0XE;
    // 0x8016FAE4: andi        $t1, $t9, 0xFFF1
    ctx->r9 = ctx->r25 & 0XFFF1;
    // 0x8016FAE8: or          $t3, $t8, $t1
    ctx->r11 = ctx->r24 | ctx->r9;
    // 0x8016FAEC: jr          $ra
    // 0x8016FAF0: sb          $t3, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r11;
    return;
    // 0x8016FAF0: sb          $t3, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r11;
L_8016FAF4:
    // 0x8016FAF4: lbu         $t4, 0x11C($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X11C);
    // 0x8016FAF8: ori         $t5, $t4, 0x80
    ctx->r13 = ctx->r12 | 0X80;
    // 0x8016FAFC: sb          $t5, 0x11C($t0)
    MEM_B(0X11C, ctx->r8) = ctx->r13;
    // 0x8016FB00: lhu         $t6, 0x11C($t0)
    ctx->r14 = MEM_HU(ctx->r8, 0X11C);
    // 0x8016FB04: andi        $t7, $t6, 0xFE07
    ctx->r15 = ctx->r14 & 0XFE07;
    // 0x8016FB08: ori         $t9, $t7, 0x80
    ctx->r25 = ctx->r15 | 0X80;
    // 0x8016FB0C: sh          $t9, 0x11C($t0)
    MEM_H(0X11C, ctx->r8) = ctx->r25;
L_8016FB10:
    // 0x8016FB10: jr          $ra
    // 0x8016FB14: nop

    return;
    // 0x8016FB14: nop

;}
RECOMP_FUNC void mvOpeningPortraitsFuncLights(uint8_t* rdram, recomp_context* ctx) {
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
RECOMP_FUNC void ftPurinSpecialAirNProcPhysics(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801512EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801512F0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x801512F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x801512F8: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801512FC: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80151300: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x80151304: beql        $t7, $zero, L_80151378
    if (ctx->r15 == 0) {
        // 0x80151308: lw          $v0, 0x184($s0)
        ctx->r2 = MEM_W(ctx->r16, 0X184);
            goto L_80151378;
    }
    goto skip_0;
    // 0x80151308: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
    skip_0:
    // 0x8015130C: lw          $t8, 0xADC($s0)
    ctx->r24 = MEM_W(ctx->r16, 0XADC);
    // 0x80151310: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x80151314: lb          $a0, 0x1C3($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X1C3);
    // 0x80151318: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8015131C: jal         0x80151274
    // 0x80151320: sw          $t9, 0xADC($s0)
    MEM_W(0XADC, ctx->r16) = ctx->r25;
    ftPurinSpecialNGetAngle(rdram, ctx);
        goto after_0;
    // 0x80151320: sw          $t9, 0xADC($s0)
    MEM_W(0XADC, ctx->r16) = ctx->r25;
    after_0:
    // 0x80151324: swc1        $f0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f0.u32l;
    // 0x80151328: jal         0x800303F0
    // 0x8015132C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    __sinf_recomp(rdram, ctx);
        goto after_1;
    // 0x8015132C: mov.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    ctx->f12.fl = ctx->f0.fl;
    after_1:
    // 0x80151330: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80151334: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80151338: nop

    // 0x8015133C: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80151340: swc1        $f6, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f6.u32l;
    // 0x80151344: jal         0x80035CD0
    // 0x80151348: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    __cosf_recomp(rdram, ctx);
        goto after_2;
    // 0x80151348: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015134C: lw          $t0, 0x44($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X44);
    // 0x80151350: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80151354: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80151358: mtc1        $t0, $f8
    ctx->f8.u32l = ctx->r8;
    // 0x8015135C: nop

    // 0x80151360: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80151364: mul.s       $f16, $f0, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x80151368: nop

    // 0x8015136C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80151370: swc1        $f4, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f4.u32l;
    // 0x80151374: lw          $v0, 0x184($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X184);
L_80151378:
    // 0x80151378: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015137C: beq         $v0, $zero, L_8015139C
    if (ctx->r2 == 0) {
        // 0x80151380: nop
    
            goto L_8015139C;
    }
    // 0x80151380: nop

    // 0x80151384: beq         $v0, $at, L_801513AC
    if (ctx->r2 == ctx->r1) {
        // 0x80151388: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_801513AC;
    }
    // 0x80151388: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8015138C: beq         $v0, $at, L_801513D4
    if (ctx->r2 == ctx->r1) {
        // 0x80151390: nop
    
            goto L_801513D4;
    }
    // 0x80151390: nop

    // 0x80151394: b           L_801513E0
    // 0x80151398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801513E0;
    // 0x80151398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8015139C:
    // 0x8015139C: jal         0x800D91EC
    // 0x801513A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftPhysicsApplyAirVelFriction(rdram, ctx);
        goto after_3;
    // 0x801513A0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_3:
    // 0x801513A4: b           L_801513E0
    // 0x801513A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_801513E0;
    // 0x801513A8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801513AC:
    // 0x801513AC: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x801513B0: lwc1        $f0, -0x3ADC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3ADC);
    // 0x801513B4: lwc1        $f6, 0x4C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x801513B8: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x801513BC: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x801513C0: nop

    // 0x801513C4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x801513C8: swc1        $f8, 0x4C($s0)
    MEM_W(0X4C, ctx->r16) = ctx->f8.u32l;
    // 0x801513CC: b           L_801513DC
    // 0x801513D0: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
        goto L_801513DC;
    // 0x801513D0: swc1        $f16, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f16.u32l;
L_801513D4:
    // 0x801513D4: jal         0x800D9160
    // 0x801513D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    ftPhysicsApplyAirVelDriftFastFall(rdram, ctx);
        goto after_4;
    // 0x801513D8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_4:
L_801513DC:
    // 0x801513DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_801513E0:
    // 0x801513E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x801513E4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x801513E8: jr          $ra
    // 0x801513EC: nop

    return;
    // 0x801513EC: nop

;}
RECOMP_FUNC void sc1PIntroGetTotalNameOffsetX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013291C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132920: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132924: jal         0x8013283C
    // 0x80132928: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    sc1PIntroGetPlayerNameOffsetX(rdram, ctx);
        goto after_0;
    // 0x80132928: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8013292C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80132930: jal         0x801328F4
    // 0x80132934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    sc1PIntroGetVSNameOffsetX(rdram, ctx);
        goto after_1;
    // 0x80132934: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x80132938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013293C: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x80132940: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132944: jr          $ra
    // 0x80132948: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    return;
    // 0x80132948: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
;}
RECOMP_FUNC void mpCollisionGetLRCommonRWall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F41C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800F41C4: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800F41C8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800F41CC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800F41D0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800F41D4: jal         0x800F3E30
    // 0x800F41D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    mpCollisionGetLRCommon(rdram, ctx);
        goto after_0;
    // 0x800F41D8: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x800F41DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800F41E0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800F41E4: jr          $ra
    // 0x800F41E8: nop

    return;
    // 0x800F41E8: nop

;}
RECOMP_FUNC void func_ovl8_8038456C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8038456C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80384570: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80384574: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80384578: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8038457C: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80384580: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80384584: bne         $a0, $zero, L_8038459C
    if (ctx->r4 != 0) {
        // 0x80384588: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_8038459C;
    }
    // 0x80384588: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8038458C: jal         0x803717A0
    // 0x80384590: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80384590: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x80384594: beq         $v0, $zero, L_80384640
    if (ctx->r2 == 0) {
        // 0x80384598: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_80384640;
    }
    // 0x80384598: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_8038459C:
    // 0x8038459C: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x803845A0: addiu       $a0, $s0, 0x64
    ctx->r4 = ADD32(ctx->r16, 0X64);
    // 0x803845A4: addiu       $a1, $s0, 0x58
    ctx->r5 = ADD32(ctx->r16, 0X58);
    // 0x803845A8: bnel        $t6, $zero, L_803845CC
    if (ctx->r14 != 0) {
        // 0x803845AC: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_803845CC;
    }
    goto skip_0;
    // 0x803845AC: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x803845B0: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x803845B4: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x803845B8: jal         0x803717E0
    // 0x803845BC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803845BC: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x803845C0: jal         0x8037C2D0
    // 0x803845C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803845C4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    after_2:
    // 0x803845C8: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_803845CC:
    // 0x803845CC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803845D0: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x803845D4: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x803845D8: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x803845DC: jal         0x80383450
    // 0x803845E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_80383450(rdram, ctx);
        goto after_3;
    // 0x803845E0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x803845E4: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x803845E8: lw          $a1, 0x44($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X44);
    // 0x803845EC: addiu       $t8, $t8, -0x2F30
    ctx->r24 = ADD32(ctx->r24, -0X2F30);
    // 0x803845F0: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x803845F4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x803845F8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803845FC: addiu       $t9, $t9, -0x2DE8
    ctx->r25 = ADD32(ctx->r25, -0X2DE8);
    // 0x80384600: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x80384604: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x80384608: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x8038460C: addiu       $t1, $t1, -0x2C90
    ctx->r9 = ADD32(ctx->r9, -0X2C90);
    // 0x80384610: beq         $a1, $zero, L_8038462C
    if (ctx->r5 == 0) {
        // 0x80384614: sw          $t1, 0x8($t2)
        MEM_W(0X8, ctx->r10) = ctx->r9;
            goto L_8038462C;
    }
    // 0x80384614: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    // 0x80384618: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x8038461C: lw          $t9, 0x10C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10C);
    // 0x80384620: lh          $t3, 0x108($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X108);
    // 0x80384624: jalr        $t9
    // 0x80384628: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_4;
    // 0x80384628: addu        $a0, $t3, $s0
    ctx->r4 = ADD32(ctx->r11, ctx->r16);
    after_4:
L_8038462C:
    // 0x8038462C: lw          $v0, 0x30($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X30);
    // 0x80384630: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80384634: lh          $t4, 0x10($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X10);
    // 0x80384638: jalr        $t9
    // 0x8038463C: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_5;
    // 0x8038463C: addu        $a0, $t4, $s0
    ctx->r4 = ADD32(ctx->r12, ctx->r16);
    after_5:
L_80384640:
    // 0x80384640: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80384644: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80384648: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8038464C: jr          $ra
    // 0x80384650: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80384650: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonFallSpecialProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014384C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80143850: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80143854: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x80143858: lui         $a1, 0x8014
    ctx->r5 = S32(0X8014 << 16);
    // 0x8014385C: addiu       $a1, $a1, 0x3808
    ctx->r5 = ADD32(ctx->r5, 0X3808);
    // 0x80143860: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80143864: jal         0x800DE798
    // 0x80143868: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    mpCommonCheckFighterPassCliff(rdram, ctx);
        goto after_0;
    // 0x80143868: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014386C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80143870: beq         $v0, $zero, L_801438E0
    if (ctx->r2 == 0) {
        // 0x80143874: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_801438E0;
    }
    // 0x80143874: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80143878: lhu         $t6, 0xD2($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0XD2);
    // 0x8014387C: andi        $t7, $t6, 0x3000
    ctx->r15 = ctx->r14 & 0X3000;
    // 0x80143880: beql        $t7, $zero, L_8014389C
    if (ctx->r15 == 0) {
        // 0x80143884: lw          $t8, 0xB20($v1)
        ctx->r24 = MEM_W(ctx->r3, 0XB20);
            goto L_8014389C;
    }
    goto skip_0;
    // 0x80143884: lw          $t8, 0xB20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XB20);
    skip_0:
    // 0x80143888: jal         0x80144C24
    // 0x8014388C: nop

    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_1;
    // 0x8014388C: nop

    after_1:
    // 0x80143890: b           L_801438E4
    // 0x80143894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801438E4;
    // 0x80143894: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80143898: lw          $t8, 0xB20($v1)
    ctx->r24 = MEM_W(ctx->r3, 0XB20);
L_8014389C:
    // 0x8014389C: lui         $at, 0xC1A0
    ctx->r1 = S32(0XC1A0 << 16);
    // 0x801438A0: bnel        $t8, $zero, L_801438C8
    if (ctx->r24 != 0) {
        // 0x801438A4: lw          $a1, 0xB28($v1)
        ctx->r5 = MEM_W(ctx->r3, 0XB28);
            goto L_801438C8;
    }
    goto skip_1;
    // 0x801438A4: lw          $a1, 0xB28($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XB28);
    skip_1:
    // 0x801438A8: lwc1        $f4, 0x4C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x801438AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801438B0: nop

    // 0x801438B4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801438B8: nop

    // 0x801438BC: bc1f        L_801438D8
    if (!c1cs) {
        // 0x801438C0: nop
    
            goto L_801438D8;
    }
    // 0x801438C0: nop

    // 0x801438C4: lw          $a1, 0xB28($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XB28);
L_801438C8:
    // 0x801438C8: jal         0x80142E3C
    // 0x801438CC: lw          $a2, 0xB24($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XB24);
    ftCommonLandingFallSpecialSetStatus(rdram, ctx);
        goto after_2;
    // 0x801438CC: lw          $a2, 0xB24($v1)
    ctx->r6 = MEM_W(ctx->r3, 0XB24);
    after_2:
    // 0x801438D0: b           L_801438E4
    // 0x801438D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801438E4;
    // 0x801438D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801438D8:
    // 0x801438D8: jal         0x8013E1C8
    // 0x801438DC: nop

    ftCommonWaitSetStatus(rdram, ctx);
        goto after_3;
    // 0x801438DC: nop

    after_3:
L_801438E0:
    // 0x801438E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801438E4:
    // 0x801438E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801438E8: jr          $ra
    // 0x801438EC: nop

    return;
    // 0x801438EC: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F314: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8015F318: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015F31C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F320: jal         0x800DDDDC
    // 0x8015F324: addiu       $a1, $a1, -0xBA4
    ctx->r5 = ADD32(ctx->r5, -0XBA4);
    mpCommonProcFighterOnFloor(rdram, ctx);
        goto after_0;
    // 0x8015F324: addiu       $a1, $a1, -0xBA4
    ctx->r5 = ADD32(ctx->r5, -0XBA4);
    after_0:
    // 0x8015F328: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015F32C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8015F330: jr          $ra
    // 0x8015F334: nop

    return;
    // 0x8015F334: nop

;}
RECOMP_FUNC void mvOpeningCliffMakeHills(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C34: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80131C38: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80131C3C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80131C40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80131C44: addiu       $a2, $zero, 0x11
    ctx->r6 = ADD32(0, 0X11);
    // 0x80131C48: jal         0x80009968
    // 0x80131C4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80131C4C: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80131C50: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80131C54: lw          $t6, 0x2998($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2998);
    // 0x80131C58: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80131C5C: addiu       $t7, $t7, 0x37A0
    ctx->r15 = ADD32(ctx->r15, 0X37A0);
    // 0x80131C60: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80131C64: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80131C68: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80131C6C: jal         0x8000F120
    // 0x80131C70: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_1;
    // 0x80131C70: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_1:
    // 0x80131C74: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80131C78: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80131C7C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80131C80: addiu       $a1, $a1, 0x1B58
    ctx->r5 = ADD32(ctx->r5, 0X1B58);
    // 0x80131C84: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80131C88: addiu       $a2, $zero, 0x1A
    ctx->r6 = ADD32(0, 0X1A);
    // 0x80131C8C: jal         0x80009DF4
    // 0x80131C90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80131C90: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_2:
    // 0x80131C94: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80131C98: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80131C9C: jr          $ra
    // 0x80131CA0: nop

    return;
    // 0x80131CA0: nop

;}
RECOMP_FUNC void mnVSModeMakeMenuNameViewport(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013356C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80133570: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x80133574: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80133578: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x8013357C: addiu       $t7, $zero, 0x3C
    ctx->r15 = ADD32(0, 0X3C);
    // 0x80133580: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x80133584: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80133588: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8013358C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80133590: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80133594: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x80133598: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x8013359C: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801335A0: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801335A4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x801335A8: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x801335AC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x801335B0: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x801335B4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x801335B8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x801335BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x801335C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x801335C4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x801335C8: jal         0x8000B93C
    // 0x801335CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x801335CC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x801335D0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x801335D4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x801335D8: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x801335DC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x801335E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x801335E4: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x801335E8: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x801335EC: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x801335F0: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x801335F4: jal         0x80007080
    // 0x801335F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x801335F8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x801335FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133600: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x80133604: jr          $ra
    // 0x80133608: nop

    return;
    // 0x80133608: nop

;}
RECOMP_FUNC void grYamabukiMakeGate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010B1AC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8010B1B0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8010B1B4: addiu       $a0, $zero, 0x3F2
    ctx->r4 = ADD32(0, 0X3F2);
    // 0x8010B1B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8010B1BC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B1C0: jal         0x80009968
    // 0x8010B1C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8010B1C4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8010B1C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8010B1CC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8010B1D0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8010B1D4: sw          $v0, 0x13FC($at)
    MEM_W(0X13FC, ctx->r1) = ctx->r2;
    // 0x8010B1D8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8010B1DC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8010B1E0: addiu       $a1, $a1, 0x4768
    ctx->r5 = ADD32(ctx->r5, 0X4768);
    // 0x8010B1E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8010B1E8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8010B1EC: jal         0x80009DF4
    // 0x8010B1F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8010B1F0: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8010B1F4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x8010B1F8: lw          $t7, 0x13F0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X13F0);
    // 0x8010B1FC: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8010B200: addiu       $t8, $t8, 0x8A0
    ctx->r24 = ADD32(ctx->r24, 0X8A0);
    // 0x8010B204: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8010B208: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8010B20C: addiu       $a3, $zero, 0x1B
    ctx->r7 = ADD32(0, 0X1B);
    // 0x8010B210: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8010B214: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8010B218: jal         0x8000F590
    // 0x8010B21C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_2;
    // 0x8010B21C: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8010B220: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8010B224: addiu       $a1, $a1, -0x20CC
    ctx->r5 = ADD32(ctx->r5, -0X20CC);
    // 0x8010B228: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8010B22C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8010B230: jal         0x80008188
    // 0x8010B234: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8010B234: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_3:
    // 0x8010B238: jal         0x8010AEFC
    // 0x8010B23C: nop

    grYamabukiGateAddAnimClose(rdram, ctx);
        goto after_4;
    // 0x8010B23C: nop

    after_4:
    // 0x8010B240: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8010B244: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8010B248: jr          $ra
    // 0x8010B24C: nop

    return;
    // 0x8010B24C: nop

;}
RECOMP_FUNC void gcRemoveAObjFromMObj(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008FB0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80008FB4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80008FB8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80008FBC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80008FC0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80008FC4: lw          $s0, 0x90($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X90);
    // 0x80008FC8: beql        $s0, $zero, L_80008FE8
    if (ctx->r16 == 0) {
        // 0x80008FCC: lw          $t7, 0x20($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X20);
            goto L_80008FE8;
    }
    goto skip_0;
    // 0x80008FCC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    skip_0:
L_80008FD0:
    // 0x80008FD0: lw          $s1, 0x0($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X0);
    // 0x80008FD4: jal         0x80007EB0
    // 0x80008FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcSetAObjPrevAlloc(rdram, ctx);
        goto after_0;
    // 0x80008FD8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80008FDC: bne         $s1, $zero, L_80008FD0
    if (ctx->r17 != 0) {
        // 0x80008FE0: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80008FD0;
    }
    // 0x80008FE0: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80008FE4: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
L_80008FE8:
    // 0x80008FE8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80008FEC: sw          $zero, 0x90($t7)
    MEM_W(0X90, ctx->r15) = 0;
    // 0x80008FF0: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80008FF4: lwc1        $f4, -0x2298($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2298);
    // 0x80008FF8: swc1        $f4, 0x98($t8)
    MEM_W(0X98, ctx->r24) = ctx->f4.u32l;
    // 0x80008FFC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80009000: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80009004: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80009008: jr          $ra
    // 0x8000900C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8000900C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void grSectorArwingWeaponLaser3DProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801075E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x801075E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801075E8: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x801075EC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x801075F0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x801075F4: lwc1        $f0, 0x24($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X24);
    // 0x801075F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x801075FC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80107600: nop

    // 0x80107604: bc1fl       L_80107618
    if (!c1cs) {
        // 0x80107608: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_80107618;
    }
    goto skip_0;
    // 0x80107608: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    skip_0:
    // 0x8010760C: b           L_80107618
    // 0x80107610: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
        goto L_80107618;
    // 0x80107610: neg.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = -ctx->f0.fl;
    // 0x80107614: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80107618:
    // 0x80107618: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x8010761C: nop

    // 0x80107620: bc1fl       L_80107660
    if (!c1cs) {
        // 0x80107624: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80107660;
    }
    goto skip_1;
    // 0x80107624: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x80107628: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x8010762C: jal         0x80167C04
    // 0x80107630: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    wpMapTestAllCheckCollEnd(rdram, ctx);
        goto after_0;
    // 0x80107630: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80107634: beq         $v0, $zero, L_8010765C
    if (ctx->r2 == 0) {
        // 0x80107638: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8010765C;
    }
    // 0x80107638: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8010763C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80107640: jal         0x800269C0
    // 0x80107644: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x80107644: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x80107648: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8010764C: jal         0x801005C8
    // 0x80107650: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    efManagerSparkleWhiteMultiExplodeMakeEffect(rdram, ctx);
        goto after_2;
    // 0x80107650: addiu       $a0, $v1, 0x1C
    ctx->r4 = ADD32(ctx->r3, 0X1C);
    after_2:
    // 0x80107654: jal         0x80107544
    // 0x80107658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    grSectorArwingWeaponLaserExplodeInitVars(rdram, ctx);
        goto after_3;
    // 0x80107658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_3:
L_8010765C:
    // 0x8010765C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80107660:
    // 0x80107660: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80107664: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80107668: jr          $ra
    // 0x8010766C: nop

    return;
    // 0x8010766C: nop

;}
RECOMP_FUNC void itNBumperHitAirSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017BEA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8017BEA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8017BEA8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017BEAC: addiu       $t6, $zero, 0x10
    ctx->r14 = ADD32(0, 0X10);
    // 0x8017BEB0: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8017BEB4: addiu       $a1, $a1, -0x593C
    ctx->r5 = ADD32(ctx->r5, -0X593C);
    // 0x8017BEB8: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    // 0x8017BEBC: jal         0x80172EC8
    // 0x8017BEC0: sh          $t6, 0x354($v0)
    MEM_H(0X354, ctx->r2) = ctx->r14;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8017BEC0: sh          $t6, 0x354($v0)
    MEM_H(0X354, ctx->r2) = ctx->r14;
    after_0:
    // 0x8017BEC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8017BEC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017BECC: jr          $ra
    // 0x8017BED0: nop

    return;
    // 0x8017BED0: nop

;}
RECOMP_FUNC void func_ovl8_80373138(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80373138: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8037313C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80373140: jal         0x80371DDC
    // 0x80373144: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    func_ovl8_80371DDC(rdram, ctx);
        goto after_0;
    // 0x80373144: lw          $a0, 0x20($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X20);
    after_0:
    // 0x80373148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8037314C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80373150: jr          $ra
    // 0x80373154: nop

    return;
    // 0x80373154: nop

;}
RECOMP_FUNC void mnMapsGetCharacterSpacing(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131C5C: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x80131C60: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80131C64: addiu       $t7, $t6, -0x27
    ctx->r15 = ADD32(ctx->r14, -0X27);
    // 0x80131C68: sltiu       $at, $t7, 0x33
    ctx->r1 = ctx->r15 < 0X33 ? 1 : 0;
    // 0x80131C6C: beq         $at, $zero, L_80131D50
    if (ctx->r1 == 0) {
        // 0x80131C70: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_80131D50;
    }
    // 0x80131C70: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80131C74: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131C78: addu        $at, $at, $t7
    gpr jr_addend_80131C80 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80131C7C: lw          $t7, 0x4A7C($at)
    ctx->r15 = ADD32(ctx->r1, 0X4A7C);
    // 0x80131C80: jr          $t7
    // 0x80131C84: nop

    switch (jr_addend_80131C80 >> 2) {
        case 0: goto L_80131D30; break;
        case 1: goto L_80131D50; break;
        case 2: goto L_80131D50; break;
        case 3: goto L_80131D50; break;
        case 4: goto L_80131D50; break;
        case 5: goto L_80131D50; break;
        case 6: goto L_80131D50; break;
        case 7: goto L_80131D40; break;
        case 8: goto L_80131D50; break;
        case 9: goto L_80131D50; break;
        case 10: goto L_80131D50; break;
        case 11: goto L_80131D50; break;
        case 12: goto L_80131D50; break;
        case 13: goto L_80131D50; break;
        case 14: goto L_80131D50; break;
        case 15: goto L_80131D50; break;
        case 16: goto L_80131D50; break;
        case 17: goto L_80131D50; break;
        case 18: goto L_80131D50; break;
        case 19: goto L_80131D50; break;
        case 20: goto L_80131D50; break;
        case 21: goto L_80131D50; break;
        case 22: goto L_80131D50; break;
        case 23: goto L_80131D50; break;
        case 24: goto L_80131D50; break;
        case 25: goto L_80131D50; break;
        case 26: goto L_80131C88; break;
        case 27: goto L_80131D50; break;
        case 28: goto L_80131D50; break;
        case 29: goto L_80131D50; break;
        case 30: goto L_80131D50; break;
        case 31: goto L_80131CCC; break;
        case 32: goto L_80131D50; break;
        case 33: goto L_80131D50; break;
        case 34: goto L_80131D50; break;
        case 35: goto L_80131D50; break;
        case 36: goto L_80131D50; break;
        case 37: goto L_80131D50; break;
        case 38: goto L_80131D50; break;
        case 39: goto L_80131D50; break;
        case 40: goto L_80131D50; break;
        case 41: goto L_80131CCC; break;
        case 42: goto L_80131D00; break;
        case 43: goto L_80131D50; break;
        case 44: goto L_80131D50; break;
        case 45: goto L_80131D00; break;
        case 46: goto L_80131D50; break;
        case 47: goto L_80131CCC; break;
        case 48: goto L_80131D50; break;
        case 49: goto L_80131D50; break;
        case 50: goto L_80131CCC; break;
        default: switch_error(__func__, 0x80131C80, 0x80134A7C);
    }
    // 0x80131C84: nop

L_80131C88:
    // 0x80131C88: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x80131C8C: addiu       $t9, $t8, -0x46
    ctx->r25 = ADD32(ctx->r24, -0X46);
    // 0x80131C90: sltiu       $at, $t9, 0x14
    ctx->r1 = ctx->r25 < 0X14 ? 1 : 0;
    // 0x80131C94: beq         $at, $zero, L_80131CBC
    if (ctx->r1 == 0) {
        // 0x80131C98: sll         $t9, $t9, 2
        ctx->r25 = S32(ctx->r25 << 2);
            goto L_80131CBC;
    }
    // 0x80131C98: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80131C9C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80131CA0: addu        $at, $at, $t9
    gpr jr_addend_80131CA8 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80131CA4: lw          $t9, 0x4B48($at)
    ctx->r25 = ADD32(ctx->r1, 0X4B48);
    // 0x80131CA8: jr          $t9
    // 0x80131CAC: nop

    switch (jr_addend_80131CA8 >> 2) {
        case 0: goto L_80131CB0; break;
        case 1: goto L_80131CBC; break;
        case 2: goto L_80131CBC; break;
        case 3: goto L_80131CBC; break;
        case 4: goto L_80131CBC; break;
        case 5: goto L_80131CBC; break;
        case 6: goto L_80131CBC; break;
        case 7: goto L_80131CBC; break;
        case 8: goto L_80131CBC; break;
        case 9: goto L_80131CBC; break;
        case 10: goto L_80131CB0; break;
        case 11: goto L_80131CBC; break;
        case 12: goto L_80131CBC; break;
        case 13: goto L_80131CBC; break;
        case 14: goto L_80131CB0; break;
        case 15: goto L_80131CBC; break;
        case 16: goto L_80131CB0; break;
        case 17: goto L_80131CBC; break;
        case 18: goto L_80131CBC; break;
        case 19: goto L_80131CB0; break;
        default: switch_error(__func__, 0x80131CA8, 0x80134B48);
    }
    // 0x80131CAC: nop

L_80131CB0:
    // 0x80131CB0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131CB4: jr          $ra
    // 0x80131CB8: nop

    return;
    // 0x80131CB8: nop

L_80131CBC:
    // 0x80131CBC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131CC0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131CC4: jr          $ra
    // 0x80131CC8: nop

    return;
    // 0x80131CC8: nop

L_80131CCC:
    // 0x80131CCC: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x80131CD0: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x80131CD4: beq         $v1, $at, L_80131CE4
    if (ctx->r3 == ctx->r1) {
        // 0x80131CD8: addiu       $at, $zero, 0x54
        ctx->r1 = ADD32(0, 0X54);
            goto L_80131CE4;
    }
    // 0x80131CD8: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x80131CDC: bnel        $v1, $at, L_80131CF4
    if (ctx->r3 != ctx->r1) {
        // 0x80131CE0: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80131CF4;
    }
    goto skip_0;
    // 0x80131CE0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_0:
L_80131CE4:
    // 0x80131CE4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131CE8: jr          $ra
    // 0x80131CEC: nop

    return;
    // 0x80131CEC: nop

    // 0x80131CF0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80131CF4:
    // 0x80131CF4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131CF8: jr          $ra
    // 0x80131CFC: nop

    return;
    // 0x80131CFC: nop

L_80131D00:
    // 0x80131D00: lbu         $v1, 0x1($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X1);
    // 0x80131D04: addiu       $at, $zero, 0x27
    ctx->r1 = ADD32(0, 0X27);
    // 0x80131D08: beq         $v1, $at, L_80131D14
    if (ctx->r3 == ctx->r1) {
        // 0x80131D0C: addiu       $at, $zero, 0x2E
        ctx->r1 = ADD32(0, 0X2E);
            goto L_80131D14;
    }
    // 0x80131D0C: addiu       $at, $zero, 0x2E
    ctx->r1 = ADD32(0, 0X2E);
    // 0x80131D10: bne         $v1, $at, L_80131D24
    if (ctx->r3 != ctx->r1) {
        // 0x80131D14: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80131D24;
    }
L_80131D14:
    // 0x80131D14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131D18: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131D1C: jr          $ra
    // 0x80131D20: nop

    return;
    // 0x80131D20: nop

L_80131D24:
    // 0x80131D24: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131D28: jr          $ra
    // 0x80131D2C: nop

    return;
    // 0x80131D2C: nop

L_80131D30:
    // 0x80131D30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131D34: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131D38: jr          $ra
    // 0x80131D3C: nop

    return;
    // 0x80131D3C: nop

L_80131D40:
    // 0x80131D40: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80131D44: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131D48: jr          $ra
    // 0x80131D4C: nop

    return;
    // 0x80131D4C: nop

L_80131D50:
    // 0x80131D50: lbu         $t0, 0x1($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X1);
    // 0x80131D54: addiu       $at, $zero, 0x54
    ctx->r1 = ADD32(0, 0X54);
    // 0x80131D58: bnel        $t0, $at, L_80131D70
    if (ctx->r8 != ctx->r1) {
        // 0x80131D5C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80131D70;
    }
    goto skip_1;
    // 0x80131D5C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    skip_1:
    // 0x80131D60: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80131D64: jr          $ra
    // 0x80131D68: nop

    return;
    // 0x80131D68: nop

    // 0x80131D6C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_80131D70:
    // 0x80131D70: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80131D74: nop

    // 0x80131D78: jr          $ra
    // 0x80131D7C: nop

    return;
    // 0x80131D7C: nop

;}
RECOMP_FUNC void ftCommonDamageDecHitStunSetPublic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801404B8: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x801404BC: lw          $v1, 0xB18($v0)
    ctx->r3 = MEM_W(ctx->r2, 0XB18);
    // 0x801404C0: beq         $v1, $zero, L_801404D8
    if (ctx->r3 == 0) {
        // 0x801404C4: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_801404D8;
    }
    // 0x801404C4: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x801404C8: bne         $t6, $zero, L_801404D8
    if (ctx->r14 != 0) {
        // 0x801404CC: sw          $t6, 0xB18($v0)
        MEM_W(0XB18, ctx->r2) = ctx->r14;
            goto L_801404D8;
    }
    // 0x801404CC: sw          $t6, 0xB18($v0)
    MEM_W(0XB18, ctx->r2) = ctx->r14;
    // 0x801404D0: lwc1        $f4, 0xB20($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XB20);
    // 0x801404D4: swc1        $f4, 0x82C($v0)
    MEM_W(0X82C, ctx->r2) = ctx->f4.u32l;
L_801404D8:
    // 0x801404D8: jr          $ra
    // 0x801404DC: nop

    return;
    // 0x801404DC: nop

;}
RECOMP_FUNC void syDmaReadVpk0Buf(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80003648: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000364C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80003650: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80003654: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80003658: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000365C: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80003660: jal         0x800035E0
    // 0x80003664: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    syDmaInitVpk0Stream(rdram, ctx);
        goto after_0;
    // 0x80003664: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    after_0:
    // 0x80003668: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x8000366C: addiu       $a2, $a2, 0x35FC
    ctx->r6 = ADD32(ctx->r6, 0X35FC);
    // 0x80003670: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80003674: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80003678: jal         0x80002E18
    // 0x8000367C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    syDmaDecodeVpk0(rdram, ctx);
        goto after_1;
    // 0x8000367C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    after_1:
    // 0x80003680: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80003684: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80003688: jr          $ra
    // 0x8000368C: nop

    return;
    // 0x8000368C: nop

;}
RECOMP_FUNC void ifCommonAnnounceTimeUpInitInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80114D98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80114D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80114DA0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80114DA4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x80114DA8: addiu       $a1, $a1, 0x42B4
    ctx->r5 = ADD32(ctx->r5, 0X42B4);
    // 0x80114DAC: addiu       $a0, $a0, 0x4B40
    ctx->r4 = ADD32(ctx->r4, 0X4B40);
    // 0x80114DB0: addiu       $a2, $zero, 0x20F
    ctx->r6 = ADD32(0, 0X20F);
    // 0x80114DB4: jal         0x80114B80
    // 0x80114DB8: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    ifCommonBattleSetInterface(rdram, ctx);
        goto after_0;
    // 0x80114DB8: addiu       $a3, $zero, 0x5A
    ctx->r7 = ADD32(0, 0X5A);
    after_0:
    // 0x80114DBC: jal         0x80112814
    // 0x80114DC0: nop

    ifCommonAnnounceTimeUpMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80114DC0: nop

    after_1:
    // 0x80114DC4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80114DC8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80114DCC: jr          $ra
    // 0x80114DD0: nop

    return;
    // 0x80114DD0: nop

;}
RECOMP_FUNC void lbParticleAllocTransforms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CE040: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CE044: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800CE048: lui         $s3, 0x800D
    ctx->r19 = S32(0X800D << 16);
    // 0x800CE04C: addiu       $s3, $s3, 0x6454
    ctx->r19 = ADD32(ctx->r19, 0X6454);
    // 0x800CE050: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800CE054: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800CE058: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800CE05C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800CE060: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800CE064: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CE068: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
    // 0x800CE06C: blez        $a0, L_800CE0A8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800CE070: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800CE0A8;
    }
    // 0x800CE070: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800CE074:
    // 0x800CE074: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800CE078: jal         0x80004980
    // 0x800CE07C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    syTaskmanMalloc(rdram, ctx);
        goto after_0;
    // 0x800CE07C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_0:
    // 0x800CE080: bnel        $v0, $zero, L_800CE094
    if (ctx->r2 != 0) {
        // 0x800CE084: lw          $t6, 0x0($s3)
        ctx->r14 = MEM_W(ctx->r19, 0X0);
            goto L_800CE094;
    }
    goto skip_0;
    // 0x800CE084: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    skip_0:
    // 0x800CE088: b           L_800CE0BC
    // 0x800CE08C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
        goto L_800CE0BC;
    // 0x800CE08C: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800CE090: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
L_800CE094:
    // 0x800CE094: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800CE098: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CE09C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800CE0A0: bne         $s0, $s1, L_800CE074
    if (ctx->r16 != ctx->r17) {
        // 0x800CE0A4: sw          $v0, 0x6454($at)
        MEM_W(0X6454, ctx->r1) = ctx->r2;
            goto L_800CE074;
    }
    // 0x800CE0A4: sw          $v0, 0x6454($at)
    MEM_W(0X6454, ctx->r1) = ctx->r2;
L_800CE0A8:
    // 0x800CE0A8: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CE0AC: sh          $zero, 0x644C($at)
    MEM_H(0X644C, ctx->r1) = 0;
    // 0x800CE0B0: lui         $at, 0x800D
    ctx->r1 = S32(0X800D << 16);
    // 0x800CE0B4: sh          $zero, 0x6452($at)
    MEM_H(0X6452, ctx->r1) = 0;
    // 0x800CE0B8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
L_800CE0BC:
    // 0x800CE0BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CE0C0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800CE0C4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800CE0C8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800CE0CC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800CE0D0: jr          $ra
    // 0x800CE0D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800CE0D4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mvEndingMakeRoomLight(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013243C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80132440: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80132444: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80132448: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x8013244C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80132450: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132454: addiu       $a2, $zero, 0x15
    ctx->r6 = ADD32(0, 0X15);
    // 0x80132458: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    // 0x8013245C: jal         0x80009968
    // 0x80132460: swc1        $f4, 0x2BFC($at)
    MEM_W(0X2BFC, ctx->r1) = ctx->f4.u32l;
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80132460: swc1        $f4, 0x2BFC($at)
    MEM_W(0X2BFC, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80132464: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132468: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013246C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132470: sw          $v0, 0x2C04($at)
    MEM_W(0X2C04, ctx->r1) = ctx->r2;
    // 0x80132474: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132478: addiu       $a1, $a1, 0x2244
    ctx->r5 = ADD32(ctx->r5, 0X2244);
    // 0x8013247C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132480: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    // 0x80132484: jal         0x80009DF4
    // 0x80132488: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x80132488: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8013248C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80132490: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80132494: jr          $ra
    // 0x80132498: nop

    return;
    // 0x80132498: nop

;}
RECOMP_FUNC void ftSamusSpecialHiProcPass(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DD20: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8015DD24: lw          $t6, 0xF4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XF4);
    // 0x8015DD28: andi        $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 & 0X4000;
    // 0x8015DD2C: beq         $t7, $zero, L_8015DD48
    if (ctx->r15 == 0) {
        // 0x8015DD30: nop
    
            goto L_8015DD48;
    }
    // 0x8015DD30: nop

    // 0x8015DD34: lb          $t8, 0x1C3($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1C3);
    // 0x8015DD38: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8015DD3C: slti        $at, $t8, -0x2C
    ctx->r1 = SIGNED(ctx->r24) < -0X2C ? 1 : 0;
    // 0x8015DD40: bne         $at, $zero, L_8015DD50
    if (ctx->r1 != 0) {
        // 0x8015DD44: nop
    
            goto L_8015DD50;
    }
    // 0x8015DD44: nop

L_8015DD48:
    // 0x8015DD48: jr          $ra
    // 0x8015DD4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x8015DD4C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8015DD50:
    // 0x8015DD50: jr          $ra
    // 0x8015DD54: nop

    return;
    // 0x8015DD54: nop

;}
RECOMP_FUNC void gcSetXObjPrevAlloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007DD8: lui         $v0, 0x8004
    ctx->r2 = S32(0X8004 << 16);
    // 0x80007DDC: addiu       $v0, $v0, 0x6A14
    ctx->r2 = ADD32(ctx->r2, 0X6A14);
    // 0x80007DE0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80007DE4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80007DE8: addiu       $v1, $v1, 0x6A18
    ctx->r3 = ADD32(ctx->r3, 0X6A18);
    // 0x80007DEC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80007DF0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x80007DF4: sw          $a0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r4;
    // 0x80007DF8: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80007DFC: jr          $ra
    // 0x80007E00: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    return;
    // 0x80007E00: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
;}
RECOMP_FUNC void efGroundCommonProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80115F5C: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x80115F60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80115F64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80115F68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80115F6C: lw          $v1, 0x74($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X74);
    // 0x80115F70: lw          $t0, 0x84($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X84);
    // 0x80115F74: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80115F78: lw          $s0, 0x10($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X10);
    // 0x80115F7C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80115F80: jal         0x80115E80
    // 0x80115F84: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    efGroundCheckEffectInBounds(rdram, ctx);
        goto after_0;
    // 0x80115F84: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_0:
    // 0x80115F88: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80115F8C: beq         $v0, $zero, L_8011607C
    if (ctx->r2 == 0) {
        // 0x80115F90: lw          $t0, 0x34($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X34);
            goto L_8011607C;
    }
    // 0x80115F90: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80115F94: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80115F98: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80115F9C: jal         0x8000DF34
    // 0x80115FA0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    gcPlayAnimAll(rdram, ctx);
        goto after_1;
    // 0x80115FA0: sw          $t0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r8;
    after_1:
    // 0x80115FA4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80115FA8: lwc1        $f4, 0xD30($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XD30);
    // 0x80115FAC: lwc1        $f6, 0x74($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X74);
    // 0x80115FB0: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x80115FB4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x80115FB8: c.eq.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl == ctx->f6.fl;
    // 0x80115FBC: nop

    // 0x80115FC0: bc1fl       L_80116080
    if (!c1cs) {
        // 0x80115FC4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80116080;
    }
    goto skip_0;
    // 0x80115FC4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_0:
    // 0x80115FC8: lw          $v0, 0x24($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X24);
    // 0x80115FCC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x80115FD0: beql        $a0, $v0, L_80115FE4
    if (ctx->r4 == ctx->r2) {
        // 0x80115FD4: lw          $t8, 0x1C($s0)
        ctx->r24 = MEM_W(ctx->r16, 0X1C);
            goto L_80115FE4;
    }
    goto skip_1;
    // 0x80115FD4: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
    skip_1:
    // 0x80115FD8: beql        $v0, $zero, L_80116080
    if (ctx->r2 == 0) {
        // 0x80115FDC: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80116080;
    }
    goto skip_2;
    // 0x80115FDC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    skip_2:
    // 0x80115FE0: lw          $t8, 0x1C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X1C);
L_80115FE4:
    // 0x80115FE4: addiu       $t6, $sp, 0x28
    ctx->r14 = ADD32(ctx->r29, 0X28);
    // 0x80115FE8: sw          $t8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r24;
    // 0x80115FEC: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x80115FF0: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80115FF4: lw          $t8, 0x24($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X24);
    // 0x80115FF8: sw          $t8, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r24;
    // 0x80115FFC: lw          $t9, 0x2C($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X2C);
    // 0x80116000: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80116004: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80116008: bnel        $a0, $t9, L_8011602C
    if (ctx->r4 != ctx->r25) {
        // 0x8011600C: lwc1        $f8, 0x40($v1)
        ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
            goto L_8011602C;
    }
    goto skip_3;
    // 0x8011600C: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
    skip_3:
    // 0x80116010: lwc1        $f10, 0x40($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X40);
    // 0x80116014: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80116018: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8011601C: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80116020: b           L_8011603C
    // 0x80116024: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
        goto L_8011603C;
    // 0x80116024: swc1        $f4, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f4.u32l;
    // 0x80116028: lwc1        $f8, 0x40($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X40);
L_8011602C:
    // 0x8011602C: lwc1        $f18, 0x1C($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X1C);
    // 0x80116030: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80116034: sub.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80116038: swc1        $f16, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f16.u32l;
L_8011603C:
    // 0x8011603C: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80116040: lwc1        $f6, 0x44($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X44);
    // 0x80116044: lwc1        $f18, 0x20($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X20);
    // 0x80116048: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8011604C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80116050: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80116054: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80116058: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8011605C: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x80116060: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x80116064: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
    // 0x80116068: lw          $a2, 0x34($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X34);
    // 0x8011606C: jal         0x800C88AC
    // 0x80116070: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    lbCommonAddTreeDObjsAnimAll(rdram, ctx);
        goto after_2;
    // 0x80116070: lw          $a1, 0x30($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X30);
    after_2:
    // 0x80116074: jal         0x8000DF34
    // 0x80116078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_3;
    // 0x80116078: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_8011607C:
    // 0x8011607C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80116080:
    // 0x80116080: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80116084: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80116088: jr          $ra
    // 0x8011608C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8011608C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void gmCollisionGetItemAttackItemDamagePosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F0F44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800F0F48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F0F4C: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800F0F50: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x800F0F54: jal         0x800F095C
    // 0x800F0F58: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    gmCollisionGetItemAttackPosition(rdram, ctx);
        goto after_0;
    // 0x800F0F58: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800F0F5C: lw          $v0, 0x40($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X40);
    // 0x800F0F60: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x800F0F64: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800F0F68: lw          $t6, 0x74($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X74);
    // 0x800F0F6C: lwc1        $f6, 0x8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800F0F70: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x800F0F74: lwc1        $f4, 0x1C($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x800F0F78: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    // 0x800F0F7C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0F80: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x800F0F84: lw          $t7, 0x74($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X74);
    // 0x800F0F88: lwc1        $f16, 0xC($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800F0F8C: lwc1        $f10, 0x20($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X20);
    // 0x800F0F90: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800F0F94: swc1        $f18, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f18.u32l;
    // 0x800F0F98: lw          $t8, 0x74($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X74);
    // 0x800F0F9C: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800F0FA0: lwc1        $f4, 0x24($t8)
    ctx->f4.u32l = MEM_W(ctx->r24, 0X24);
    // 0x800F0FA4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800F0FA8: jal         0x800F0A48
    // 0x800F0FAC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    gmCollisionGetCommonImpactPosition(rdram, ctx);
        goto after_1;
    // 0x800F0FAC: swc1        $f8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x800F0FB0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0FB4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800F0FB8: jr          $ra
    // 0x800F0FBC: nop

    return;
    // 0x800F0FBC: nop

;}
RECOMP_FUNC void itProcessUpdateAttackRecords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016F3D4: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8016F3D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8016F3DC: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    // 0x8016F3E0: lw          $t6, 0x10C($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X10C);
    // 0x8016F3E4: addiu       $a1, $v0, 0x10C
    ctx->r5 = ADD32(ctx->r2, 0X10C);
    // 0x8016F3E8: beq         $t6, $zero, L_8016F52C
    if (ctx->r14 == 0) {
        // 0x8016F3EC: nop
    
            goto L_8016F52C;
    }
    // 0x8016F3EC: nop

L_8016F3F0:
    // 0x8016F3F0: lw          $t7, 0x118($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X118);
    // 0x8016F3F4: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8016F3F8: addiu       $v1, $a1, 0x118
    ctx->r3 = ADD32(ctx->r5, 0X118);
    // 0x8016F3FC: beql        $t7, $zero, L_8016F490
    if (ctx->r15 == 0) {
        // 0x8016F400: lw          $t2, 0x120($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X120);
            goto L_8016F490;
    }
    goto skip_0;
    // 0x8016F400: lw          $t2, 0x120($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X120);
    skip_0:
    // 0x8016F404: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8016F408: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
    // 0x8016F40C: srl         $v0, $v0, 26
    ctx->r2 = S32(U32(ctx->r2) >> 26);
    // 0x8016F410: beq         $v0, $zero, L_8016F48C
    if (ctx->r2 == 0) {
        // 0x8016F414: addiu       $t8, $v0, -0x1
        ctx->r24 = ADD32(ctx->r2, -0X1);
            goto L_8016F48C;
    }
    // 0x8016F414: addiu       $t8, $v0, -0x1
    ctx->r24 = ADD32(ctx->r2, -0X1);
    // 0x8016F418: lhu         $t1, 0x4($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X4);
    // 0x8016F41C: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x8016F420: andi        $t0, $t9, 0x1F8
    ctx->r8 = ctx->r25 & 0X1F8;
    // 0x8016F424: andi        $t2, $t1, 0xFE07
    ctx->r10 = ctx->r9 & 0XFE07;
    // 0x8016F428: or          $t3, $t0, $t2
    ctx->r11 = ctx->r8 | ctx->r10;
    // 0x8016F42C: sh          $t3, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r11;
    // 0x8016F430: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x8016F434: sll         $t5, $t4, 7
    ctx->r13 = S32(ctx->r12 << 7);
    // 0x8016F438: srl         $t6, $t5, 26
    ctx->r14 = S32(U32(ctx->r13) >> 26);
    // 0x8016F43C: bnel        $t6, $zero, L_8016F490
    if (ctx->r14 != 0) {
        // 0x8016F440: lw          $t2, 0x120($a1)
        ctx->r10 = MEM_W(ctx->r5, 0X120);
            goto L_8016F490;
    }
    goto skip_1;
    // 0x8016F440: lw          $t2, 0x120($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X120);
    skip_1:
    // 0x8016F444: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x8016F448: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8016F44C: andi        $t0, $t7, 0xFFDF
    ctx->r8 = ctx->r15 & 0XFFDF;
    // 0x8016F450: sb          $t0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r8;
    // 0x8016F454: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8016F458: andi        $t2, $t0, 0xBF
    ctx->r10 = ctx->r8 & 0XBF;
    // 0x8016F45C: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8016F460: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x8016F464: sll         $t9, $v0, 6
    ctx->r25 = S32(ctx->r2 << 6);
    // 0x8016F468: andi        $t1, $t9, 0x40
    ctx->r9 = ctx->r25 & 0X40;
    // 0x8016F46C: or          $t6, $t1, $t2
    ctx->r14 = ctx->r9 | ctx->r10;
    // 0x8016F470: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x8016F474: sll         $t5, $v0, 7
    ctx->r13 = S32(ctx->r2 << 7);
    // 0x8016F478: or          $t0, $t5, $t7
    ctx->r8 = ctx->r13 | ctx->r15;
    // 0x8016F47C: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
    // 0x8016F480: sb          $t0, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r8;
    // 0x8016F484: ori         $t1, $t0, 0xE
    ctx->r9 = ctx->r8 | 0XE;
    // 0x8016F488: sb          $t1, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r9;
L_8016F48C:
    // 0x8016F48C: lw          $t2, 0x120($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X120);
L_8016F490:
    // 0x8016F490: addiu       $v1, $a1, 0x120
    ctx->r3 = ADD32(ctx->r5, 0X120);
    // 0x8016F494: beq         $t2, $zero, L_8016F524
    if (ctx->r10 == 0) {
        // 0x8016F498: nop
    
            goto L_8016F524;
    }
    // 0x8016F498: nop

    // 0x8016F49C: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8016F4A0: sll         $v0, $v0, 7
    ctx->r2 = S32(ctx->r2 << 7);
    // 0x8016F4A4: srl         $v0, $v0, 26
    ctx->r2 = S32(U32(ctx->r2) >> 26);
    // 0x8016F4A8: beq         $v0, $zero, L_8016F524
    if (ctx->r2 == 0) {
        // 0x8016F4AC: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8016F524;
    }
    // 0x8016F4AC: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x8016F4B0: lhu         $t5, 0x4($v1)
    ctx->r13 = MEM_HU(ctx->r3, 0X4);
    // 0x8016F4B4: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x8016F4B8: andi        $t6, $t4, 0x1F8
    ctx->r14 = ctx->r12 & 0X1F8;
    // 0x8016F4BC: andi        $t7, $t5, 0xFE07
    ctx->r15 = ctx->r13 & 0XFE07;
    // 0x8016F4C0: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8016F4C4: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x8016F4C8: lw          $t9, 0x4($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X4);
    // 0x8016F4CC: sll         $t0, $t9, 7
    ctx->r8 = S32(ctx->r25 << 7);
    // 0x8016F4D0: srl         $t1, $t0, 26
    ctx->r9 = S32(U32(ctx->r8) >> 26);
    // 0x8016F4D4: bne         $t1, $zero, L_8016F524
    if (ctx->r9 != 0) {
        // 0x8016F4D8: nop
    
            goto L_8016F524;
    }
    // 0x8016F4D8: nop

    // 0x8016F4DC: lbu         $t2, 0x4($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X4);
    // 0x8016F4E0: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8016F4E4: andi        $t6, $t2, 0xFFDF
    ctx->r14 = ctx->r10 & 0XFFDF;
    // 0x8016F4E8: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
    // 0x8016F4EC: lw          $v0, 0x4($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4);
    // 0x8016F4F0: andi        $t7, $t6, 0xBF
    ctx->r15 = ctx->r14 & 0XBF;
    // 0x8016F4F4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8016F4F8: srl         $v0, $v0, 31
    ctx->r2 = S32(U32(ctx->r2) >> 31);
    // 0x8016F4FC: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x8016F500: andi        $t5, $t4, 0x40
    ctx->r13 = ctx->r12 & 0X40;
    // 0x8016F504: or          $t1, $t5, $t7
    ctx->r9 = ctx->r13 | ctx->r15;
    // 0x8016F508: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x8016F50C: sll         $t0, $v0, 7
    ctx->r8 = S32(ctx->r2 << 7);
    // 0x8016F510: or          $t6, $t0, $t2
    ctx->r14 = ctx->r8 | ctx->r10;
    // 0x8016F514: sb          $t1, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r9;
    // 0x8016F518: sb          $t6, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r14;
    // 0x8016F51C: ori         $t5, $t6, 0xE
    ctx->r13 = ctx->r14 | 0XE;
    // 0x8016F520: sb          $t5, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r13;
L_8016F524:
    // 0x8016F524: bne         $a0, $a2, L_8016F3F0
    if (ctx->r4 != ctx->r6) {
        // 0x8016F528: addiu       $a1, $a1, 0x10
        ctx->r5 = ADD32(ctx->r5, 0X10);
            goto L_8016F3F0;
    }
    // 0x8016F528: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
L_8016F52C:
    // 0x8016F52C: jr          $ra
    // 0x8016F530: nop

    return;
    // 0x8016F530: nop

;}
RECOMP_FUNC void gmCameraCalcFighterZoomRange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8010BB98: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x8010BB9C: lwc1        $f4, 0x860($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X860);
    // 0x8010BBA0: lwc1        $f6, 0x864($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X864);
    // 0x8010BBA4: lw          $t6, 0x24($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X24);
    // 0x8010BBA8: mul.s       $f12, $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x8010BBAC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x8010BBB0: mul.s       $f12, $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f6.fl);
    // 0x8010BBB4: bne         $t6, $at, L_8010BBDC
    if (ctx->r14 != ctx->r1) {
        // 0x8010BBB8: nop
    
            goto L_8010BBDC;
    }
    // 0x8010BBB8: nop

    // 0x8010BBBC: lw          $t7, 0x1C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X1C);
    // 0x8010BBC0: sltiu       $at, $t7, 0x78
    ctx->r1 = ctx->r15 < 0X78 ? 1 : 0;
    // 0x8010BBC4: bne         $at, $zero, L_8010BBDC
    if (ctx->r1 != 0) {
        // 0x8010BBC8: lui         $at, 0x3F40
        ctx->r1 = S32(0X3F40 << 16);
            goto L_8010BBDC;
    }
    // 0x8010BBC8: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8010BBCC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8010BBD0: nop

    // 0x8010BBD4: mul.s       $f12, $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f8.fl);
    // 0x8010BBD8: nop

L_8010BBDC:
    // 0x8010BBDC: jr          $ra
    // 0x8010BBE0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x8010BBE0: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void ftParamSetKey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800E9B30: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800E9B34: sw          $zero, 0xA94($v0)
    MEM_W(0XA94, ctx->r2) = 0;
    // 0x800E9B38: jr          $ra
    // 0x800E9B3C: sw          $a1, 0xA98($v0)
    MEM_W(0XA98, ctx->r2) = ctx->r5;
    return;
    // 0x800E9B3C: sw          $a1, 0xA98($v0)
    MEM_W(0XA98, ctx->r2) = ctx->r5;
;}
RECOMP_FUNC void func_ovl8_803769D4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x803769D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x803769D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x803769DC: lw          $v0, 0x18($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X18);
    // 0x803769E0: lw          $t9, 0x8C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8C);
    // 0x803769E4: lh          $t6, 0x88($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X88);
    // 0x803769E8: jalr        $t9
    // 0x803769EC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x803769EC: addu        $a0, $t6, $a0
    ctx->r4 = ADD32(ctx->r14, ctx->r4);
    after_0:
    // 0x803769F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x803769F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x803769F8: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x803769FC: jr          $ra
    // 0x80376A00: nop

    return;
    // 0x80376A00: nop

;}
RECOMP_FUNC void mvOpeningSamusMakePosedFighterCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018DC68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8018DC6C: lui         $t6, 0x8001
    ctx->r14 = S32(0X8001 << 16);
    // 0x8018DC70: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8018DC74: addiu       $t6, $t6, 0x7EC0
    ctx->r14 = ADD32(ctx->r14, 0X7EC0);
    // 0x8018DC78: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8018DC7C: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8018DC80: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x8018DC84: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8018DC88: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018DC8C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8018DC90: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018DC94: sw          $t3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r11;
    // 0x8018DC98: sw          $t2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r10;
    // 0x8018DC9C: sw          $t1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r9;
    // 0x8018DCA0: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x8018DCA4: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8018DCA8: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8018DCAC: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8018DCB0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018DCB4: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x8018DCB8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x8018DCBC: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x8018DCC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018DCC4: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x8018DCC8: jal         0x8000B93C
    // 0x8018DCCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x8018DCCC: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018DCD0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8018DCD4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8018DCD8: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8018DCDC: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x8018DCE0: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x8018DCE4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8018DCE8: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8018DCEC: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8018DCF0: lui         $a3, 0x42DC
    ctx->r7 = S32(0X42DC << 16);
    // 0x8018DCF4: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8018DCF8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x8018DCFC: jal         0x80007080
    // 0x8018DD00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x8018DD00: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x8018DD04: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8018DD08: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x8018DD0C: lwc1        $f6, -0x1D9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X1D9C);
    // 0x8018DD10: lui         $t4, 0x8019
    ctx->r12 = S32(0X8019 << 16);
    // 0x8018DD14: lui         $t5, 0x0
    ctx->r13 = S32(0X0 << 16);
    // 0x8018DD18: swc1        $f6, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f6.u32l;
    // 0x8018DD1C: lw          $t4, -0x1B6C($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X1B6C);
    // 0x8018DD20: addiu       $t5, $t5, 0x60
    ctx->r13 = ADD32(ctx->r13, 0X60);
    // 0x8018DD24: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8018DD28: jal         0x8000FA3C
    // 0x8018DD2C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    gcAddCObjCamAnimJoint(rdram, ctx);
        goto after_2;
    // 0x8018DD2C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    after_2:
    // 0x8018DD30: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x8018DD34: addiu       $a1, $a1, 0x580
    ctx->r5 = ADD32(ctx->r5, 0X580);
    // 0x8018DD38: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x8018DD3C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018DD40: jal         0x80008188
    // 0x8018DD44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_3;
    // 0x8018DD44: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_3:
    // 0x8018DD48: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8018DD4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8018DD50: jr          $ra
    // 0x8018DD54: nop

    return;
    // 0x8018DD54: nop

;}
RECOMP_FUNC void itTaruBombContainerSmashMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80184B44: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x80184B48: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80184B4C: sw          $s5, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r21;
    // 0x80184B50: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80184B54: sw          $s4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r20;
    // 0x80184B58: sw          $s3, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r19;
    // 0x80184B5C: sw          $s2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r18;
    // 0x80184B60: sw          $s1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r17;
    // 0x80184B64: sw          $s0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r16;
    // 0x80184B68: sdc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    SD(ctx->f30.u64, 0X40, ctx->r29);
    // 0x80184B6C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80184B70: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x80184B74: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x80184B78: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x80184B7C: jal         0x800FD4B8
    // 0x80184B80: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    efManagerGetEffectNoForce(rdram, ctx);
        goto after_0;
    // 0x80184B80: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    after_0:
    // 0x80184B84: beq         $v0, $zero, L_80184D38
    if (ctx->r2 == 0) {
        // 0x80184B88: sw          $v0, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r2;
            goto L_80184D38;
    }
    // 0x80184B88: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x80184B8C: lui         $s0, 0x8000
    ctx->r16 = S32(0X8000 << 16);
    // 0x80184B90: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x80184B94: addiu       $a0, $zero, 0x3F3
    ctx->r4 = ADD32(0, 0X3F3);
    // 0x80184B98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80184B9C: jal         0x80009968
    // 0x80184BA0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_1;
    // 0x80184BA0: addiu       $a2, $zero, 0x6
    ctx->r6 = ADD32(0, 0X6);
    after_1:
    // 0x80184BA4: beq         $v0, $zero, L_80184D38
    if (ctx->r2 == 0) {
        // 0x80184BA8: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_80184D38;
    }
    // 0x80184BA8: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x80184BAC: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80184BB0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80184BB4: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80184BB8: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80184BBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80184BC0: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x80184BC4: jal         0x80009DF4
    // 0x80184BC8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    gcAddGObjDisplay(rdram, ctx);
        goto after_2;
    // 0x80184BC8: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_2:
    // 0x80184BCC: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80184BD0: addiu       $v0, $v0, -0x4A60
    ctx->r2 = ADD32(ctx->r2, -0X4A60);
    // 0x80184BD4: lui         $at, 0xC1C0
    ctx->r1 = S32(0XC1C0 << 16);
    // 0x80184BD8: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80184BDC: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80184BE0: lui         $at, 0x4240
    ctx->r1 = S32(0X4240 << 16);
    // 0x80184BE4: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80184BE8: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x80184BEC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80184BF0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x80184BF4: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80184BF8: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80184BFC: lwc1        $f24, -0x30BC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, -0X30BC);
    // 0x80184C00: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80184C04: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80184C08: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x80184C0C: lui         $t2, 0x0
    ctx->r10 = S32(0X0 << 16);
    // 0x80184C10: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80184C14: addiu       $t2, $t2, 0x788
    ctx->r10 = ADD32(ctx->r10, 0X788);
    // 0x80184C18: lui         $t4, 0x0
    ctx->r12 = S32(0X0 << 16);
    // 0x80184C1C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80184C20: addiu       $t4, $t4, 0x8A0
    ctx->r12 = ADD32(ctx->r12, 0X8A0);
    // 0x80184C24: subu        $t3, $t1, $t2
    ctx->r11 = SUB32(ctx->r9, ctx->r10);
    // 0x80184C28: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80184C2C: addu        $s4, $t3, $t4
    ctx->r20 = ADD32(ctx->r11, ctx->r12);
    // 0x80184C30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80184C34: addiu       $s2, $zero, 0x7
    ctx->r18 = ADD32(0, 0X7);
L_80184C38:
    // 0x80184C38: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80184C3C: jal         0x800092D0
    // 0x80184C40: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    gcAddDObjForGObj(rdram, ctx);
        goto after_3;
    // 0x80184C40: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_3:
    // 0x80184C44: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80184C48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80184C4C: addiu       $a1, $zero, 0x1B
    ctx->r5 = ADD32(0, 0X1B);
    // 0x80184C50: jal         0x80008CC0
    // 0x80184C54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    gcAddXObjForDObjFixed(rdram, ctx);
        goto after_4;
    // 0x80184C54: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_4:
    // 0x80184C58: lw          $t6, 0x0($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X0);
    // 0x80184C5C: sw          $t6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->r14;
    // 0x80184C60: lw          $t5, 0x4($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X4);
    // 0x80184C64: sw          $t5, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->r13;
    // 0x80184C68: lw          $t6, 0x8($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X8);
    // 0x80184C6C: jal         0x80018948
    // 0x80184C70: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    syUtilsRandFloat(rdram, ctx);
        goto after_5;
    // 0x80184C70: sw          $t6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->r14;
    after_5:
    // 0x80184C74: mul.s       $f4, $f0, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f28.fl);
    // 0x80184C78: add.s       $f6, $f4, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f30.fl;
    // 0x80184C7C: jal         0x80018948
    // 0x80184C80: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_6;
    // 0x80184C80: swc1        $f6, 0x40($s0)
    MEM_W(0X40, ctx->r16) = ctx->f6.u32l;
    after_6:
    // 0x80184C84: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x80184C88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80184C8C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80184C90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80184C94: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80184C98: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80184C9C: jal         0x80018948
    // 0x80184CA0: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_7;
    // 0x80184CA0: swc1        $f18, 0x44($s0)
    MEM_W(0X44, ctx->r16) = ctx->f18.u32l;
    after_7:
    // 0x80184CA4: lui         $at, 0x4200
    ctx->r1 = S32(0X4200 << 16);
    // 0x80184CA8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80184CAC: lui         $at, 0xC180
    ctx->r1 = S32(0XC180 << 16);
    // 0x80184CB0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80184CB4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80184CB8: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80184CBC: jal         0x80018948
    // 0x80184CC0: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_8;
    // 0x80184CC0: swc1        $f10, 0x48($s0)
    MEM_W(0X48, ctx->r16) = ctx->f10.u32l;
    after_8:
    // 0x80184CC4: mul.s       $f16, $f0, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80184CC8: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x80184CCC: mul.s       $f4, $f18, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f24.fl);
    // 0x80184CD0: div.s       $f6, $f4, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80184CD4: jal         0x80018948
    // 0x80184CD8: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_9;
    // 0x80184CD8: swc1        $f6, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->f6.u32l;
    after_9:
    // 0x80184CDC: mul.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80184CE0: add.s       $f10, $f8, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x80184CE4: mul.s       $f16, $f10, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f24.fl);
    // 0x80184CE8: div.s       $f18, $f16, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f26.fl);
    // 0x80184CEC: jal         0x80018948
    // 0x80184CF0: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    syUtilsRandFloat(rdram, ctx);
        goto after_10;
    // 0x80184CF0: swc1        $f18, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->f18.u32l;
    after_10:
    // 0x80184CF4: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80184CF8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80184CFC: add.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f22.fl;
    // 0x80184D00: mul.s       $f8, $f6, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f24.fl);
    // 0x80184D04: div.s       $f10, $f8, $f26
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f26.fl);
    // 0x80184D08: bne         $s1, $s2, L_80184C38
    if (ctx->r17 != ctx->r18) {
        // 0x80184D0C: swc1        $f10, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
            goto L_80184C38;
    }
    // 0x80184D0C: swc1        $f10, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->f10.u32l;
    // 0x80184D10: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x80184D14: addiu       $t7, $zero, 0x5A
    ctx->r15 = ADD32(0, 0X5A);
    // 0x80184D18: lui         $a1, 0x8018
    ctx->r5 = S32(0X8018 << 16);
    // 0x80184D1C: sw          $t7, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r15;
    // 0x80184D20: addiu       $a1, $a1, 0x4A70
    ctx->r5 = ADD32(ctx->r5, 0X4A70);
    // 0x80184D24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80184D28: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80184D2C: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x80184D30: jal         0x80008188
    // 0x80184D34: sw          $v0, 0x84($s3)
    MEM_W(0X84, ctx->r19) = ctx->r2;
    gcAddGObjProcess(rdram, ctx);
        goto after_11;
    // 0x80184D34: sw          $v0, 0x84($s3)
    MEM_W(0X84, ctx->r19) = ctx->r2;
    after_11:
L_80184D38:
    // 0x80184D38: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80184D3C: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80184D40: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x80184D44: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x80184D48: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x80184D4C: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x80184D50: ldc1        $f30, 0x40($sp)
    CHECK_FR(ctx, 30);
    ctx->f30.u64 = LD(ctx->r29, 0X40);
    // 0x80184D54: lw          $s0, 0x4C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4C);
    // 0x80184D58: lw          $s1, 0x50($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X50);
    // 0x80184D5C: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80184D60: lw          $s3, 0x58($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X58);
    // 0x80184D64: lw          $s4, 0x5C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X5C);
    // 0x80184D68: lw          $s5, 0x60($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60);
    // 0x80184D6C: jr          $ra
    // 0x80184D70: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x80184D70: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void efManagerRippleMakeEffect(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801014A8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801014AC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x801014B0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801014B4: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x801014B8: lw          $a0, 0x13C4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X13C4);
    // 0x801014BC: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x801014C0: jal         0x800D35DC
    // 0x801014C4: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    lbParticleMakeGenerator(rdram, ctx);
        goto after_0;
    // 0x801014C4: addiu       $a1, $zero, 0x61
    ctx->r5 = ADD32(0, 0X61);
    after_0:
    // 0x801014C8: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x801014CC: beq         $v0, $zero, L_801014EC
    if (ctx->r2 == 0) {
        // 0x801014D0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_801014EC;
    }
    // 0x801014D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x801014D4: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x801014D8: swc1        $f4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f4.u32l;
    // 0x801014DC: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x801014E0: swc1        $f6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->f6.u32l;
    // 0x801014E4: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x801014E8: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
L_801014EC:
    // 0x801014EC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801014F0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801014F4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801014F8: jr          $ra
    // 0x801014FC: nop

    return;
    // 0x801014FC: nop

;}
RECOMP_FUNC void sc1PTrainingModeComboDisplayProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018E56C: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E570: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018E574: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x8018E578: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018E57C: lw          $t6, 0x50E8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X50E8);
    // 0x8018E580: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x8018E584: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8018E588: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E58C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8018E590: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018E594: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8018E598: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018E59C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8018E5A0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8018E5A4: lw          $a1, 0x74($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X74);
    // 0x8018E5A8: slti        $at, $a1, 0x64
    ctx->r1 = SIGNED(ctx->r5) < 0X64 ? 1 : 0;
    // 0x8018E5AC: bne         $at, $zero, L_8018E5B8
    if (ctx->r1 != 0) {
        // 0x8018E5B0: nop
    
            goto L_8018E5B8;
    }
    // 0x8018E5B0: nop

    // 0x8018E5B4: addiu       $a1, $zero, 0x63
    ctx->r5 = ADD32(0, 0X63);
L_8018E5B8:
    // 0x8018E5B8: bnel        $a1, $zero, L_8018E5F0
    if (ctx->r5 != 0) {
        // 0x8018E5BC: lw          $t4, 0x8($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X8);
            goto L_8018E5F0;
    }
    goto skip_0;
    // 0x8018E5BC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    skip_0:
    // 0x8018E5C0: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8018E5C4: addiu       $t1, $zero, 0x5A
    ctx->r9 = ADD32(0, 0X5A);
    // 0x8018E5C8: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8018E5CC: beql        $t0, $zero, L_8018E5E0
    if (ctx->r8 == 0) {
        // 0x8018E5D0: lbu         $t2, 0xD1($v0)
        ctx->r10 = MEM_BU(ctx->r2, 0XD1);
            goto L_8018E5E0;
    }
    goto skip_1;
    // 0x8018E5D0: lbu         $t2, 0xD1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XD1);
    skip_1:
    // 0x8018E5D4: sb          $t1, 0xD1($v0)
    MEM_B(0XD1, ctx->r2) = ctx->r9;
    // 0x8018E5D8: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8018E5DC: lbu         $t2, 0xD1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0XD1);
L_8018E5E0:
    // 0x8018E5E0: bnel        $t2, $zero, L_8018E5F0
    if (ctx->r10 != 0) {
        // 0x8018E5E4: lw          $t4, 0x8($v0)
        ctx->r12 = MEM_W(ctx->r2, 0X8);
            goto L_8018E5F0;
    }
    goto skip_2;
    // 0x8018E5E4: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    skip_2:
    // 0x8018E5E8: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x8018E5EC: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
L_8018E5F0:
    // 0x8018E5F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8018E5F4: beq         $a1, $t4, L_8018E614
    if (ctx->r5 == ctx->r12) {
        // 0x8018E5F8: nop
    
            goto L_8018E614;
    }
    // 0x8018E5F8: nop

    // 0x8018E5FC: jal         0x8018E424
    // 0x8018E600: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    sc1PTrainingModeUpdateComboDisplay(rdram, ctx);
        goto after_0;
    // 0x8018E600: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8018E604: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8018E608: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x8018E60C: addiu       $v0, $v0, 0xB58
    ctx->r2 = ADD32(ctx->r2, 0XB58);
    // 0x8018E610: sw          $a1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r5;
L_8018E614:
    // 0x8018E614: jal         0x800CCF00
    // 0x8018E618: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    lbCommonDrawSObjAttr(rdram, ctx);
        goto after_1;
    // 0x8018E618: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8018E61C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018E620: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8018E624: jr          $ra
    // 0x8018E628: nop

    return;
    // 0x8018E628: nop

;}
RECOMP_FUNC void ftNessSpecialAirLwHitSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80155880: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80155884: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80155888: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015588C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80155890: jal         0x800DEE98
    // 0x80155894: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80155894: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80155898: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015589C: addiu       $t7, $zero, 0x897
    ctx->r15 = ADD32(0, 0X897);
    // 0x801558A0: addiu       $a1, $zero, 0xEF
    ctx->r5 = ADD32(0, 0XEF);
    // 0x801558A4: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x801558A8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x801558AC: jal         0x800E6F24
    // 0x801558B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x801558B0: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x801558B4: lw          $v0, 0x24($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X24);
    // 0x801558B8: lbu         $t9, 0x18D($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X18D);
    // 0x801558BC: ori         $t0, $t9, 0x80
    ctx->r8 = ctx->r25 | 0X80;
    // 0x801558C0: sb          $t0, 0x18D($v0)
    MEM_B(0X18D, ctx->r2) = ctx->r8;
    // 0x801558C4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x801558C8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x801558CC: jr          $ra
    // 0x801558D0: nop

    return;
    // 0x801558D0: nop

;}
RECOMP_FUNC void gmCollisionGetWorldPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ED3C0: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800ED3C4: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED3C8: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800ED3CC: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED3D0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800ED3D4: lwc1        $f6, 0x20($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800ED3D8: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800ED3DC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800ED3E0: lwc1        $f10, 0x8($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED3E4: addiu       $t6, $sp, 0x4
    ctx->r14 = ADD32(ctx->r29, 0X4);
    // 0x800ED3E8: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800ED3EC: add.s       $f4, $f8, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800ED3F0: lwc1        $f18, 0x30($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800ED3F4: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x800ED3F8: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800ED3FC: swc1        $f6, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f6.u32l;
    // 0x800ED400: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED404: lwc1        $f10, 0x4($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X4);
    // 0x800ED408: lwc1        $f8, 0x4($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED40C: lwc1        $f18, 0x14($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800ED410: mul.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800ED414: lwc1        $f4, 0x24($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800ED418: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800ED41C: lwc1        $f18, 0x8($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED420: mul.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f18.fl);
    // 0x800ED424: add.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800ED428: lwc1        $f6, 0x34($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X34);
    // 0x800ED42C: add.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800ED430: add.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800ED434: swc1        $f4, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f4.u32l;
    // 0x800ED438: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800ED43C: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800ED440: lwc1        $f16, 0x4($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X4);
    // 0x800ED444: lwc1        $f6, 0x18($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800ED448: mul.s       $f8, $f18, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f10.fl);
    // 0x800ED44C: lwc1        $f10, 0x28($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800ED450: mul.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800ED454: lwc1        $f6, 0x8($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X8);
    // 0x800ED458: mul.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800ED45C: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800ED460: lwc1        $f4, 0x38($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X38);
    // 0x800ED464: add.s       $f8, $f18, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800ED468: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800ED46C: swc1        $f10, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f10.u32l;
    // 0x800ED470: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800ED474: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x800ED478: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x800ED47C: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x800ED480: lw          $t8, 0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X8);
    // 0x800ED484: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    // 0x800ED488: jr          $ra
    // 0x800ED48C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
    return;
    // 0x800ED48C: sw          $t8, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r24;
;}
RECOMP_FUNC void scAutoDemoGetFighterKindsNum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D7FC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8018D800: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8018D804: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D808: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8018D80C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_8018D810:
    // 0x8018D810: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x8018D814: beq         $t6, $zero, L_8018D820
    if (ctx->r14 == 0) {
        // 0x8018D818: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8018D820;
    }
    // 0x8018D818: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8018D81C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8018D820:
    // 0x8018D820: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8018D824: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x8018D828: andi        $t7, $a1, 0x1
    ctx->r15 = ctx->r5 & 0X1;
    // 0x8018D82C: beq         $t7, $zero, L_8018D838
    if (ctx->r15 == 0) {
        // 0x8018D830: sra         $a0, $a1, 1
        ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8018D838;
    }
    // 0x8018D830: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8018D834: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8018D838:
    // 0x8018D838: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x8018D83C: andi        $t8, $a1, 0x1
    ctx->r24 = ctx->r5 & 0X1;
    // 0x8018D840: beq         $t8, $zero, L_8018D84C
    if (ctx->r24 == 0) {
        // 0x8018D844: sra         $a0, $a1, 1
        ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
            goto L_8018D84C;
    }
    // 0x8018D844: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8018D848: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8018D84C:
    // 0x8018D84C: andi        $a1, $a0, 0xFFFF
    ctx->r5 = ctx->r4 & 0XFFFF;
    // 0x8018D850: andi        $t9, $a1, 0x1
    ctx->r25 = ctx->r5 & 0X1;
    // 0x8018D854: beq         $t9, $zero, L_8018D860
    if (ctx->r25 == 0) {
        // 0x8018D858: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8018D860;
    }
    // 0x8018D858: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8018D85C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_8018D860:
    // 0x8018D860: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x8018D864: bne         $v0, $a2, L_8018D810
    if (ctx->r2 != ctx->r6) {
        // 0x8018D868: andi        $a0, $a0, 0xFFFF
        ctx->r4 = ctx->r4 & 0XFFFF;
            goto L_8018D810;
    }
    // 0x8018D868: andi        $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 & 0XFFFF;
    // 0x8018D86C: jr          $ra
    // 0x8018D870: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8018D870: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void scExplainMakeControlStickInterface(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D748: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8018D74C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8018D750: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8018D754: addiu       $a0, $zero, 0x3F8
    ctx->r4 = ADD32(0, 0X3F8);
    // 0x8018D758: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8018D75C: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
    // 0x8018D760: jal         0x80009968
    // 0x8018D764: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x8018D764: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x8018D768: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D76C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8018D770: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8018D774: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8018D778: addiu       $a1, $a1, -0x2A04
    ctx->r5 = ADD32(ctx->r5, -0X2A04);
    // 0x8018D77C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8018D780: addiu       $a2, $zero, 0x1B
    ctx->r6 = ADD32(0, 0X1B);
    // 0x8018D784: jal         0x80009DF4
    // 0x8018D788: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_1;
    // 0x8018D788: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_1:
    // 0x8018D78C: lui         $t7, 0x8019
    ctx->r15 = S32(0X8019 << 16);
    // 0x8018D790: lw          $t7, -0x1620($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1620);
    // 0x8018D794: lui         $t8, 0x0
    ctx->r24 = S32(0X0 << 16);
    // 0x8018D798: addiu       $t8, $t8, 0x5300
    ctx->r24 = ADD32(ctx->r24, 0X5300);
    // 0x8018D79C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D7A0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8018D7A4: addiu       $a3, $zero, 0x12
    ctx->r7 = ADD32(0, 0X12);
    // 0x8018D7A8: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8018D7AC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8018D7B0: jal         0x8000F590
    // 0x8018D7B4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    gcSetupCustomDObjs(rdram, ctx);
        goto after_2;
    // 0x8018D7B4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    after_2:
    // 0x8018D7B8: lui         $t9, 0x8019
    ctx->r25 = S32(0X8019 << 16);
    // 0x8018D7BC: lw          $t9, -0x1620($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X1620);
    // 0x8018D7C0: lui         $t0, 0x0
    ctx->r8 = S32(0X0 << 16);
    // 0x8018D7C4: addiu       $t0, $t0, 0x5028
    ctx->r8 = ADD32(ctx->r8, 0X5028);
    // 0x8018D7C8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D7CC: jal         0x8000F8F4
    // 0x8018D7D0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    gcAddMObjAll(rdram, ctx);
        goto after_3;
    // 0x8018D7D0: addu        $a1, $t9, $t0
    ctx->r5 = ADD32(ctx->r25, ctx->r8);
    after_3:
    // 0x8018D7D4: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018D7D8: addiu       $a1, $a1, -0x2924
    ctx->r5 = ADD32(ctx->r5, -0X2924);
    // 0x8018D7DC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8018D7E0: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8018D7E4: jal         0x80008188
    // 0x8018D7E8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    gcAddGObjProcess(rdram, ctx);
        goto after_4;
    // 0x8018D7E8: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_4:
    // 0x8018D7EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8018D7F0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x8018D7F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8018D7F8: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x8018D7FC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8018D800: jr          $ra
    // 0x8018D804: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8018D804: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void mnVSModeMakeLeftArrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132570: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80132574: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x80132578: lw          $t6, 0x4A48($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X4A48);
    // 0x8013257C: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x80132580: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80132584: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132588: addiu       $t7, $t7, -0x21D0
    ctx->r15 = ADD32(ctx->r15, -0X21D0);
    // 0x8013258C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80132590: jal         0x800CCFDC
    // 0x80132594: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_0;
    // 0x80132594: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    after_0:
    // 0x80132598: lhu         $t8, 0x24($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X24);
    // 0x8013259C: sw          $zero, 0x54($v0)
    MEM_W(0X54, ctx->r2) = 0;
    // 0x801325A0: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x801325A4: andi        $t0, $t8, 0xFFDF
    ctx->r8 = ctx->r24 & 0XFFDF;
    // 0x801325A8: sh          $t0, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r8;
    // 0x801325AC: ori         $t1, $t0, 0x1
    ctx->r9 = ctx->r8 | 0X1;
    // 0x801325B0: sh          $t1, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r9;
    // 0x801325B4: lwc1        $f4, 0x1C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x801325B8: addiu       $t3, $zero, 0xAE
    ctx->r11 = ADD32(0, 0XAE);
    // 0x801325BC: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x801325C0: lwc1        $f6, 0x20($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X20);
    // 0x801325C4: sb          $t2, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r10;
    // 0x801325C8: sb          $t3, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r11;
    // 0x801325CC: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x801325D0: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x801325D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801325D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801325DC: jr          $ra
    // 0x801325E0: nop

    return;
    // 0x801325E0: nop

;}
RECOMP_FUNC void wpMapTestAllCheckCollEnd(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80167C04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80167C08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80167C0C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80167C10: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80167C14: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x80167C18: addiu       $a1, $a1, 0x7B8C
    ctx->r5 = ADD32(ctx->r5, 0X7B8C);
    // 0x80167C1C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80167C20: jal         0x800DA034
    // 0x80167C24: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x80167C24: addiu       $a0, $a0, 0x2C
    ctx->r4 = ADD32(ctx->r4, 0X2C);
    after_0:
    // 0x80167C28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80167C2C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80167C30: jr          $ra
    // 0x80167C34: nop

    return;
    // 0x80167C34: nop

;}
RECOMP_FUNC void mnPlayers1PTrainingSetPortraitWallpaperPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131E0C: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80131E10: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80131E14: addiu       $v1, $sp, 0x0
    ctx->r3 = ADD32(ctx->r29, 0X0);
    // 0x80131E18: addiu       $t6, $t6, -0x7FF0
    ctx->r14 = ADD32(ctx->r14, -0X7FF0);
    // 0x80131E1C: addiu       $t0, $t6, 0x60
    ctx->r8 = ADD32(ctx->r14, 0X60);
    // 0x80131E20: or          $t9, $v1, $zero
    ctx->r25 = ctx->r3 | 0;
L_80131E24:
    // 0x80131E24: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80131E28: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80131E2C: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80131E30: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x80131E34: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80131E38: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80131E3C: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80131E40: bne         $t6, $t0, L_80131E24
    if (ctx->r14 != ctx->r8) {
        // 0x80131E44: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_80131E24;
    }
    // 0x80131E44: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80131E48: sll         $t1, $a1, 3
    ctx->r9 = S32(ctx->r5 << 3);
    // 0x80131E4C: addu        $v0, $v1, $t1
    ctx->r2 = ADD32(ctx->r3, ctx->r9);
    // 0x80131E50: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80131E54: swc1        $f4, 0x58($a0)
    MEM_W(0X58, ctx->r4) = ctx->f4.u32l;
    // 0x80131E58: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80131E5C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x80131E60: jr          $ra
    // 0x80131E64: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
    return;
    // 0x80131E64: swc1        $f6, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->f6.u32l;
;}

#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void syTaskmanCommonTaskUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80006350: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80006354: lw          $t9, 0x6668($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6668);
    // 0x80006358: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000635C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80006360: jalr        $t9
    // 0x80006364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x80006364: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80006368: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x8000636C: lw          $t9, 0x4($t6)
    ctx->r25 = MEM_W(ctx->r14, 0X4);
    // 0x80006370: jalr        $t9
    // 0x80006374: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x80006374: nop

    after_1:
    // 0x80006378: jal         0x80005C9C
    // 0x8000637C: nop

    syTaskmanCheckBreakLoop(rdram, ctx);
        goto after_2;
    // 0x8000637C: nop

    after_2:
    // 0x80006380: beql        $v0, $zero, L_80006394
    if (ctx->r2 == 0) {
        // 0x80006384: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006394;
    }
    goto skip_0;
    // 0x80006384: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x80006388: jal         0x8000B7B4
    // 0x8000638C: nop

    gcEjectAll(rdram, ctx);
        goto after_3;
    // 0x8000638C: nop

    after_3:
    // 0x80006390: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006394:
    // 0x80006394: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80006398: jr          $ra
    // 0x8000639C: nop

    return;
    // 0x8000639C: nop

;}
RECOMP_FUNC void func_ovl8_80371980(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371980: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x80371984: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x80371988: lh          $t9, 0x2($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X2);
    // 0x8037198C: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80371990: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
    // 0x80371994: lh          $t0, 0x4($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4);
    // 0x80371998: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x8037199C: jr          $ra
    // 0x803719A0: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
    return;
    // 0x803719A0: sh          $t1, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void itTaruCommonProcHit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80179C20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80179C24: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80179C28: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80179C2C: jal         0x800269C0
    // 0x80179C30: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80179C30: addiu       $a0, $zero, 0x3B
    ctx->r4 = ADD32(0, 0X3B);
    after_0:
    // 0x80179C34: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x80179C38: lw          $a0, 0x74($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X74);
    // 0x80179C3C: jal         0x801791F4
    // 0x80179C40: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    itBoxContainerSmashMakeEffect(rdram, ctx);
        goto after_1;
    // 0x80179C40: addiu       $a0, $a0, 0x1C
    ctx->r4 = ADD32(ctx->r4, 0X1C);
    after_1:
    // 0x80179C44: jal         0x801730D4
    // 0x80179C48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itMainMakeContainerItem(rdram, ctx);
        goto after_2;
    // 0x80179C48: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_2:
    // 0x80179C4C: beq         $v0, $zero, L_80179C5C
    if (ctx->r2 == 0) {
        // 0x80179C50: nop
    
            goto L_80179C5C;
    }
    // 0x80179C50: nop

    // 0x80179C54: b           L_80179C68
    // 0x80179C58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80179C68;
    // 0x80179C58: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80179C5C:
    // 0x80179C5C: jal         0x8017A30C
    // 0x80179C60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itTaruExplodeMakeEffectGotoSetStatus(rdram, ctx);
        goto after_3;
    // 0x80179C60: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_3:
    // 0x80179C64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80179C68:
    // 0x80179C68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80179C6C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80179C70: jr          $ra
    // 0x80179C74: nop

    return;
    // 0x80179C74: nop

;}
RECOMP_FUNC void gcAddDObjSiblingRpyD(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B528: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000B52C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000B530: jal         0x80009380
    // 0x8000B534: nop

    gcAddSiblingForDObj(rdram, ctx);
        goto after_0;
    // 0x8000B534: nop

    after_0:
    // 0x8000B538: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8000B53C: jal         0x8000B3EC
    // 0x8000B540: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    gcAddDObjMatrixSetsRpyD(rdram, ctx);
        goto after_1;
    // 0x8000B540: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8000B544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000B548: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B54C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000B550: jr          $ra
    // 0x8000B554: nop

    return;
    // 0x8000B554: nop

;}
RECOMP_FUNC void mnVSResultsGetTKO(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801358C4: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x801358C8: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x801358CC: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
    // 0x801358D0: lw          $v1, -0x6470($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6470);
    // 0x801358D4: slti        $at, $v1, 0x3E8
    ctx->r1 = SIGNED(ctx->r3) < 0X3E8 ? 1 : 0;
    // 0x801358D8: bne         $at, $zero, L_801358E8
    if (ctx->r1 != 0) {
        // 0x801358DC: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_801358E8;
    }
    // 0x801358DC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x801358E0: jr          $ra
    // 0x801358E4: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
    return;
    // 0x801358E4: addiu       $v0, $zero, 0x3E7
    ctx->r2 = ADD32(0, 0X3E7);
L_801358E8:
    // 0x801358E8: jr          $ra
    // 0x801358EC: nop

    return;
    // 0x801358EC: nop

;}
RECOMP_FUNC void func_ovl8_80372C00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80372C00: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80372C04: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80372C08: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80372C0C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80372C10: addiu       $s3, $sp, 0x30
    ctx->r19 = ADD32(ctx->r29, 0X30);
    // 0x80372C14: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80372C18: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80372C1C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80372C20: jal         0x8037726C
    // 0x80372C24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_ovl8_8037726C(rdram, ctx);
        goto after_0;
    // 0x80372C24: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x80372C28: beq         $s1, $zero, L_80372C34
    if (ctx->r17 == 0) {
        // 0x80372C2C: or          $s0, $s1, $zero
        ctx->r16 = ctx->r17 | 0;
            goto L_80372C34;
    }
    // 0x80372C2C: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80372C30: lw          $s0, 0x20($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X20);
L_80372C34:
    // 0x80372C34: jal         0x80377244
    // 0x80372C38: nop

    func_ovl8_80377244(rdram, ctx);
        goto after_1;
    // 0x80372C38: nop

    after_1:
    // 0x80372C3C: lw          $t6, 0x30($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X30);
    // 0x80372C40: addiu       $s2, $sp, 0x34
    ctx->r18 = ADD32(ctx->r29, 0X34);
    // 0x80372C44: and         $t7, $v0, $t6
    ctx->r15 = ctx->r2 & ctx->r14;
    // 0x80372C48: beq         $t7, $zero, L_80372CF4
    if (ctx->r15 == 0) {
        // 0x80372C4C: nop
    
            goto L_80372CF4;
    }
    // 0x80372C4C: nop

L_80372C50:
    // 0x80372C50: jal         0x8037726C
    // 0x80372C54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    func_ovl8_8037726C(rdram, ctx);
        goto after_2;
    // 0x80372C54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_2:
    // 0x80372C58: lh          $t8, 0x34($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X34);
    // 0x80372C5C: lh          $t9, 0x30($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X30);
    // 0x80372C60: lh          $t0, 0x36($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X36);
    // 0x80372C64: lh          $t1, 0x32($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X32);
    // 0x80372C68: bne         $t8, $t9, L_80372C78
    if (ctx->r24 != ctx->r25) {
        // 0x80372C6C: lh          $t3, 0x34($sp)
        ctx->r11 = MEM_H(ctx->r29, 0X34);
            goto L_80372C78;
    }
    // 0x80372C6C: lh          $t3, 0x34($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X34);
    // 0x80372C70: beq         $t0, $t1, L_80372CC0
    if (ctx->r8 == ctx->r9) {
        // 0x80372C74: nop
    
            goto L_80372CC0;
    }
    // 0x80372C74: nop

L_80372C78:
    // 0x80372C78: lw          $s0, 0x18($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X18);
    // 0x80372C7C: lh          $t4, 0x30($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X30);
    // 0x80372C80: lh          $t5, 0x36($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X36);
    // 0x80372C84: lh          $t6, 0x32($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X32);
    // 0x80372C88: lw          $t9, 0x5C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X5C);
    // 0x80372C8C: lh          $t2, 0x58($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X58);
    // 0x80372C90: subu        $a1, $t3, $t4
    ctx->r5 = SUB32(ctx->r11, ctx->r12);
    // 0x80372C94: subu        $a2, $t5, $t6
    ctx->r6 = SUB32(ctx->r13, ctx->r14);
    // 0x80372C98: sll         $a2, $a2, 16
    ctx->r6 = S32(ctx->r6 << 16);
    // 0x80372C9C: sll         $a1, $a1, 16
    ctx->r5 = S32(ctx->r5 << 16);
    // 0x80372CA0: sra         $a1, $a1, 16
    ctx->r5 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80372CA4: sra         $a2, $a2, 16
    ctx->r6 = S32(SIGNED(ctx->r6) >> 16);
    // 0x80372CA8: jalr        $t9
    // 0x80372CAC: addu        $a0, $t2, $s1
    ctx->r4 = ADD32(ctx->r10, ctx->r17);
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_3;
    // 0x80372CAC: addu        $a0, $t2, $s1
    ctx->r4 = ADD32(ctx->r10, ctx->r17);
    after_3:
    // 0x80372CB0: lwl         $t8, 0x0($s2)
    ctx->r24 = do_lwl(rdram, ctx->r24, ctx->r18, 0X0);
    // 0x80372CB4: lwr         $t8, 0x3($s2)
    ctx->r24 = do_lwr(rdram, ctx->r24, ctx->r18, 0X3);
    // 0x80372CB8: swl         $t8, 0x0($s3)
    do_swl(rdram, 0X0, ctx->r19, ctx->r24);
    // 0x80372CBC: swr         $t8, 0x3($s3)
    do_swr(rdram, 0X3, ctx->r19, ctx->r24);
L_80372CC0:
    // 0x80372CC0: jal         0x8037D45C
    // 0x80372CC4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    func_ovl8_8037D45C(rdram, ctx);
        goto after_4;
    // 0x80372CC4: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    after_4:
    // 0x80372CC8: jal         0x8000B1E8
    // 0x80372CCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_5;
    // 0x80372CCC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80372CD0: beq         $s1, $zero, L_80372CDC
    if (ctx->r17 == 0) {
        // 0x80372CD4: nop
    
            goto L_80372CDC;
    }
    // 0x80372CD4: nop

    // 0x80372CD8: lw          $s0, 0x20($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X20);
L_80372CDC:
    // 0x80372CDC: jal         0x80377244
    // 0x80372CE0: nop

    func_ovl8_80377244(rdram, ctx);
        goto after_6;
    // 0x80372CE0: nop

    after_6:
    // 0x80372CE4: lw          $t0, 0x30($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X30);
    // 0x80372CE8: and         $t1, $v0, $t0
    ctx->r9 = ctx->r2 & ctx->r8;
    // 0x80372CEC: bne         $t1, $zero, L_80372C50
    if (ctx->r9 != 0) {
        // 0x80372CF0: nop
    
            goto L_80372C50;
    }
    // 0x80372CF0: nop

L_80372CF4:
    // 0x80372CF4: jal         0x8037D45C
    // 0x80372CF8: nop

    func_ovl8_8037D45C(rdram, ctx);
        goto after_7;
    // 0x80372CF8: nop

    after_7:
    // 0x80372CFC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80372D00: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80372D04: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80372D08: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80372D0C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80372D10: jr          $ra
    // 0x80372D14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80372D14: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void func_ovl8_80381AF0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80381AF0: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80381AF4: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x80381AF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80381AFC: jr          $ra
    // 0x80381B00: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    return;
    // 0x80381B00: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
;}
RECOMP_FUNC void itBombHeiFallProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177440: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177444: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177448: lui         $a1, 0x3ECC
    ctx->r5 = S32(0X3ECC << 16);
    // 0x8017744C: lui         $a2, 0x3E99
    ctx->r6 = S32(0X3E99 << 16);
    // 0x80177450: lui         $a3, 0x8017
    ctx->r7 = S32(0X8017 << 16);
    // 0x80177454: addiu       $a3, $a3, 0x7474
    ctx->r7 = ADD32(ctx->r7, 0X7474);
    // 0x80177458: ori         $a2, $a2, 0x999A
    ctx->r6 = ctx->r6 | 0X999A;
    // 0x8017745C: jal         0x80173B24
    // 0x80177460: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    itMapCheckDestroyDropped(rdram, ctx);
        goto after_0;
    // 0x80177460: ori         $a1, $a1, 0xCCCD
    ctx->r5 = ctx->r5 | 0XCCCD;
    after_0:
    // 0x80177464: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177468: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8017746C: jr          $ra
    // 0x80177470: nop

    return;
    // 0x80177470: nop

;}
RECOMP_FUNC void ftSamusSpecialHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015DD58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015DD5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8015DD60: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015DD64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015DD68: lw          $t6, 0x14C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X14C);
    // 0x8015DD6C: bne         $t6, $at, L_8015DDF4
    if (ctx->r14 != ctx->r1) {
        // 0x8015DD70: nop
    
            goto L_8015DDF4;
    }
    // 0x8015DD70: nop

    // 0x8015DD74: lwc1        $f4, 0x4C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4C);
    // 0x8015DD78: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8015DD7C: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015DD80: addiu       $a1, $a1, -0x22E0
    ctx->r5 = ADD32(ctx->r5, -0X22E0);
    // 0x8015DD84: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x8015DD88: nop

    // 0x8015DD8C: bc1fl       L_8015DDA8
    if (!c1cs) {
        // 0x8015DD90: sw          $v1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r3;
            goto L_8015DDA8;
    }
    goto skip_0;
    // 0x8015DD90: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    skip_0:
    // 0x8015DD94: jal         0x800DE724
    // 0x8015DD98: nop

    mpCommonCheckFighterProject(rdram, ctx);
        goto after_0;
    // 0x8015DD98: nop

    after_0:
    // 0x8015DD9C: b           L_8015DE00
    // 0x8015DDA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015DE00;
    // 0x8015DDA0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8015DDA4: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
L_8015DDA8:
    // 0x8015DDA8: jal         0x800DE798
    // 0x8015DDAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    mpCommonCheckFighterPassCliff(rdram, ctx);
        goto after_1;
    // 0x8015DDAC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_1:
    // 0x8015DDB0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8015DDB4: beq         $v0, $zero, L_8015DDFC
    if (ctx->r2 == 0) {
        // 0x8015DDB8: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8015DDFC;
    }
    // 0x8015DDB8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8015DDBC: lhu         $t7, 0xD2($v1)
    ctx->r15 = MEM_HU(ctx->r3, 0XD2);
    // 0x8015DDC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8015DDC4: lui         $a2, 0x3ECC
    ctx->r6 = S32(0X3ECC << 16);
    // 0x8015DDC8: andi        $t8, $t7, 0x3000
    ctx->r24 = ctx->r15 & 0X3000;
    // 0x8015DDCC: beq         $t8, $zero, L_8015DDE4
    if (ctx->r24 == 0) {
        // 0x8015DDD0: nop
    
            goto L_8015DDE4;
    }
    // 0x8015DDD0: nop

    // 0x8015DDD4: jal         0x80144C24
    // 0x8015DDD8: nop

    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_2;
    // 0x8015DDD8: nop

    after_2:
    // 0x8015DDDC: b           L_8015DE00
    // 0x8015DDE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015DE00;
    // 0x8015DDE0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015DDE4:
    // 0x8015DDE4: jal         0x80142E3C
    // 0x8015DDE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    ftCommonLandingFallSpecialSetStatus(rdram, ctx);
        goto after_3;
    // 0x8015DDE8: ori         $a2, $a2, 0xCCCD
    ctx->r6 = ctx->r6 | 0XCCCD;
    after_3:
    // 0x8015DDEC: b           L_8015DE00
    // 0x8015DDF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8015DE00;
    // 0x8015DDF0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015DDF4:
    // 0x8015DDF4: jal         0x800DDF44
    // 0x8015DDF8: nop

    mpCommonSetFighterFallOnEdgeBreak(rdram, ctx);
        goto after_4;
    // 0x8015DDF8: nop

    after_4:
L_8015DDFC:
    // 0x8015DDFC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8015DE00:
    // 0x8015DE00: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015DE04: jr          $ra
    // 0x8015DE08: nop

    return;
    // 0x8015DE08: nop

;}
RECOMP_FUNC void mnVSRecordSubtitleProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801328D4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x801328D8: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x801328DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801328E0: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x801328E4: addiu       $t7, $t7, 0x676C
    ctx->r15 = ADD32(ctx->r15, 0X676C);
    // 0x801328E8: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x801328EC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801328F0: addiu       $t6, $sp, 0x1C
    ctx->r14 = ADD32(ctx->r29, 0X1C);
    // 0x801328F4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x801328F8: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x801328FC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x80132900: lw          $t9, 0x8($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X8);
    // 0x80132904: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x80132908: sw          $t8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->r24;
    // 0x8013290C: sw          $t9, 0x8($t6)
    MEM_W(0X8, ctx->r14) = ctx->r25;
    // 0x80132910: lw          $t0, 0x6C1C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6C1C);
    // 0x80132914: beql        $t0, $zero, L_80132988
    if (ctx->r8 == 0) {
        // 0x80132918: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80132988;
    }
    goto skip_0;
    // 0x80132918: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8013291C: jal         0x8000B760
    // 0x80132920: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    gcRemoveSObjAll(rdram, ctx);
        goto after_0;
    // 0x80132920: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    after_0:
    // 0x80132924: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x80132928: lw          $t1, 0x6C18($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6C18);
    // 0x8013292C: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x80132930: lw          $t4, 0x6D88($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D88);
    // 0x80132934: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80132938: addu        $t3, $sp, $t2
    ctx->r11 = ADD32(ctx->r29, ctx->r10);
    // 0x8013293C: lw          $t3, 0x1C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X1C);
    // 0x80132940: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80132944: jal         0x800CCFDC
    // 0x80132948: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    lbCommonMakeSObjForGObj(rdram, ctx);
        goto after_1;
    // 0x80132948: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    after_1:
    // 0x8013294C: lhu         $t5, 0x24($v0)
    ctx->r13 = MEM_HU(ctx->r2, 0X24);
    // 0x80132950: lui         $at, 0x435E
    ctx->r1 = S32(0X435E << 16);
    // 0x80132954: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80132958: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x8013295C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80132960: andi        $t7, $t5, 0xFFDF
    ctx->r15 = ctx->r13 & 0XFFDF;
    // 0x80132964: sh          $t7, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r15;
    // 0x80132968: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x8013296C: sh          $t8, 0x24($v0)
    MEM_H(0X24, ctx->r2) = ctx->r24;
    // 0x80132970: sb          $zero, 0x28($v0)
    MEM_B(0X28, ctx->r2) = 0;
    // 0x80132974: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x80132978: sb          $zero, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = 0;
    // 0x8013297C: swc1        $f4, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f4.u32l;
    // 0x80132980: swc1        $f6, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f6.u32l;
    // 0x80132984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80132988:
    // 0x80132988: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8013298C: jr          $ra
    // 0x80132990: nop

    return;
    // 0x80132990: nop

;}
RECOMP_FUNC void mnVSResultsTintProcDisplay(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134C5C: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80134C60: addiu       $t4, $t4, -0x6440
    ctx->r12 = ADD32(ctx->r12, -0X6440);
    // 0x80134C64: lw          $v0, 0x0($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X0);
    // 0x80134C68: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80134C6C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80134C70: sltiu       $at, $v0, 0x80
    ctx->r1 = ctx->r2 < 0X80 ? 1 : 0;
    // 0x80134C74: beq         $at, $zero, L_80134C94
    if (ctx->r1 == 0) {
        // 0x80134C78: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80134C94;
    }
    // 0x80134C78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80134C7C: addiu       $t6, $v0, 0x9
    ctx->r14 = ADD32(ctx->r2, 0X9);
    // 0x80134C80: sltiu       $at, $t6, 0x81
    ctx->r1 = ctx->r14 < 0X81 ? 1 : 0;
    // 0x80134C84: bne         $at, $zero, L_80134C94
    if (ctx->r1 != 0) {
        // 0x80134C88: sw          $t6, 0x0($t4)
        MEM_W(0X0, ctx->r12) = ctx->r14;
            goto L_80134C94;
    }
    // 0x80134C88: sw          $t6, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r14;
    // 0x80134C8C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80134C90: sw          $t8, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r24;
L_80134C94:
    // 0x80134C94: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x80134C98: addiu       $v1, $v1, 0x65B0
    ctx->r3 = ADD32(ctx->r3, 0X65B0);
    // 0x80134C9C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134CA0: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80134CA4: lui         $t7, 0xE300
    ctx->r15 = S32(0XE300 << 16);
    // 0x80134CA8: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80134CAC: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80134CB0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80134CB4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80134CB8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134CBC: ori         $t7, $t7, 0xA01
    ctx->r15 = ctx->r15 | 0XA01;
    // 0x80134CC0: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x80134CC4: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80134CC8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80134CCC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80134CD0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80134CD4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134CD8: lui         $ra, 0xE200
    ctx->r31 = S32(0XE200 << 16);
    // 0x80134CDC: ori         $ra, $ra, 0x1C
    ctx->r31 = ctx->r31 | 0X1C;
    // 0x80134CE0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80134CE4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80134CE8: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80134CEC: lw          $t6, 0x0($t4)
    ctx->r14 = MEM_W(ctx->r12, 0X0);
    // 0x80134CF0: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x80134CF4: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x80134CF8: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80134CFC: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80134D00: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134D04: lui         $t6, 0xFFFD
    ctx->r14 = S32(0XFFFD << 16);
    // 0x80134D08: ori         $t6, $t6, 0xF6FB
    ctx->r14 = ctx->r14 | 0XF6FB;
    // 0x80134D0C: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80134D10: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80134D14: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80134D18: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80134D1C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134D20: lui         $t8, 0x50
    ctx->r24 = S32(0X50 << 16);
    // 0x80134D24: ori         $t8, $t8, 0x41C8
    ctx->r24 = ctx->r24 | 0X41C8;
    // 0x80134D28: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80134D2C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80134D30: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x80134D34: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80134D38: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134D3C: lui         $t7, 0x2
    ctx->r15 = S32(0X2 << 16);
    // 0x80134D40: lui         $t6, 0xF64D
    ctx->r14 = S32(0XF64D << 16);
    // 0x80134D44: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80134D48: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80134D4C: ori         $t6, $t6, 0x8398
    ctx->r14 = ctx->r14 | 0X8398;
    // 0x80134D50: ori         $t7, $t7, 0x8028
    ctx->r15 = ctx->r15 | 0X8028;
    // 0x80134D54: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80134D58: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80134D5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134D60: lui         $t6, 0x55
    ctx->r14 = S32(0X55 << 16);
    // 0x80134D64: ori         $t6, $t6, 0x2078
    ctx->r14 = ctx->r14 | 0X2078;
    // 0x80134D68: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80134D6C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80134D70: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x80134D74: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80134D78: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80134D7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80134D80: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80134D84: sw          $ra, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r31;
    // 0x80134D88: jal         0x800CCEAC
    // 0x80134D8C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    lbCommonClearExternSpriteParams(rdram, ctx);
        goto after_0;
    // 0x80134D8C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    after_0:
    // 0x80134D90: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80134D94: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80134D98: jr          $ra
    // 0x80134D9C: nop

    return;
    // 0x80134D9C: nop

;}
RECOMP_FUNC void dbFallsFuncStart(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D660C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800D6610: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800D6614: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x800D6618: addiu       $a1, $a1, 0x64C4
    ctx->r5 = ADD32(ctx->r5, 0X64C4);
    // 0x800D661C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6620: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800D6624: jal         0x80009968
    // 0x800D6628: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x800D6628: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x800D662C: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x800D6630: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800D6634: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800D6638: lui         $a1, 0x8000
    ctx->r5 = S32(0X8000 << 16);
    // 0x800D663C: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    // 0x800D6640: jal         0x8000B9FC
    // 0x800D6644: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    gcMakeDefaultCameraGObj(rdram, ctx);
        goto after_1;
    // 0x800D6644: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_1:
    // 0x800D6648: jal         0x800D6544
    // 0x800D664C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    dbFallsMakeCamera(rdram, ctx);
        goto after_2;
    // 0x800D664C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800D6650: jal         0x80369EE0
    // 0x800D6654: nop

    dbMenuInitMenu(rdram, ctx);
        goto after_3;
    // 0x800D6654: nop

    after_3:
    // 0x800D6658: lui         $a3, 0x800D
    ctx->r7 = S32(0X800D << 16);
    // 0x800D665C: addiu       $t7, $zero, 0xD
    ctx->r15 = ADD32(0, 0XD);
    // 0x800D6660: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800D6664: addiu       $a3, $a3, 0x6738
    ctx->r7 = ADD32(ctx->r7, 0X6738);
    // 0x800D6668: addiu       $a0, $zero, 0x32
    ctx->r4 = ADD32(0, 0X32);
    // 0x800D666C: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x800D6670: jal         0x80369D78
    // 0x800D6674: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    dbMenuMakeMenu(rdram, ctx);
        goto after_4;
    // 0x800D6674: addiu       $a2, $zero, 0x64
    ctx->r6 = ADD32(0, 0X64);
    after_4:
    // 0x800D6678: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800D667C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800D6680: jr          $ra
    // 0x800D6684: nop

    return;
    // 0x800D6684: nop

;}
RECOMP_FUNC void sc1PTrainingModeUpdateExitOption(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8018D830: lui         $t6, 0x800A
    ctx->r14 = S32(0X800A << 16);
    // 0x8018D834: lbu         $t6, 0x4AE3($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X4AE3);
    // 0x8018D838: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x8018D83C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8018D840: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8018D844: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x8018D848: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8018D84C: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8018D850: lhu         $t8, 0x522A($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X522A);
    // 0x8018D854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8018D858: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8018D85C: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8018D860: beq         $t9, $zero, L_8018D888
    if (ctx->r25 == 0) {
        // 0x8018D864: nop
    
            goto L_8018D888;
    }
    // 0x8018D864: nop

    // 0x8018D868: jal         0x800266A0
    // 0x8018D86C: nop

    func_800266A0_272A0(rdram, ctx);
        goto after_0;
    // 0x8018D86C: nop

    after_0:
    // 0x8018D870: jal         0x800269C0
    // 0x8018D874: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    func_800269C0_275C0(rdram, ctx);
        goto after_1;
    // 0x8018D874: addiu       $a0, $zero, 0xA2
    ctx->r4 = ADD32(0, 0XA2);
    after_1:
    // 0x8018D878: jal         0x80005C74
    // 0x8018D87C: nop

    syTaskmanSetLoadScene(rdram, ctx);
        goto after_2;
    // 0x8018D87C: nop

    after_2:
    // 0x8018D880: b           L_8018D888
    // 0x8018D884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8018D888;
    // 0x8018D884: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8018D888:
    // 0x8018D888: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8018D88C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8018D890: jr          $ra
    // 0x8018D894: nop

    return;
    // 0x8018D894: nop

;}
RECOMP_FUNC void itGShellThrownSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80178B28: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80178B2C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178B30: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80178B34: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80178B38: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x80178B3C: addiu       $a1, $a1, -0x5DCC
    ctx->r5 = ADD32(ctx->r5, -0X5DCC);
    // 0x80178B40: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80178B44: sb          $v1, 0x352($v0)
    MEM_B(0X352, ctx->r2) = ctx->r3;
    // 0x80178B48: jal         0x80172EC8
    // 0x80178B4C: sb          $v1, 0x353($v0)
    MEM_B(0X353, ctx->r2) = ctx->r3;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x80178B4C: sb          $v1, 0x353($v0)
    MEM_B(0X353, ctx->r2) = ctx->r3;
    after_0:
    // 0x80178B50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80178B54: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80178B58: jr          $ra
    // 0x80178B5C: nop

    return;
    // 0x80178B5C: nop

;}
RECOMP_FUNC void syMainThreadStackOverflow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800004E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800004E4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800004E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800004EC: lui         $a0, 0x8004
    ctx->r4 = S32(0X8004 << 16);
    // 0x800004F0: jal         0x80023624
    // 0x800004F4: addiu       $a0, $a0, -0x29B0
    ctx->r4 = ADD32(ctx->r4, -0X29B0);
    syDebugPrintf(rdram, ctx);
        goto after_0;
    // 0x800004F4: addiu       $a0, $a0, -0x29B0
    ctx->r4 = ADD32(ctx->r4, -0X29B0);
    after_0:
L_800004F8:
    // 0x800004F8: b           L_800004F8
    pause_self(rdram);
    // 0x800004FC: nop

    // 0x80000500: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80000504: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000508: jr          $ra
    // 0x8000050C: nop

    return;
    // 0x8000050C: nop

;}
RECOMP_FUNC void itMLuckyDisappearSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801813F8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801813FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80181400: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80181404: addiu       $t6, $zero, 0x5A
    ctx->r14 = ADD32(0, 0X5A);
    // 0x80181408: lui         $a1, 0x8019
    ctx->r5 = S32(0X8019 << 16);
    // 0x8018140C: addiu       $a1, $a1, -0x501C
    ctx->r5 = ADD32(ctx->r5, -0X501C);
    // 0x80181410: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x80181414: sh          $t6, 0x352($v0)
    MEM_H(0X352, ctx->r2) = ctx->r14;
    // 0x80181418: jal         0x80172EC8
    // 0x8018141C: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    itMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8018141C: sw          $zero, 0x248($v0)
    MEM_W(0X248, ctx->r2) = 0;
    after_0:
    // 0x80181420: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80181424: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80181428: jr          $ra
    // 0x8018142C: nop

    return;
    // 0x8018142C: nop

;}
RECOMP_FUNC void ftCaptainSpecialLwBoundCheckGoto(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015FEB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015FEB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015FEBC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015FEC0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015FEC4: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x8015FEC8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8015FECC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8015FED0: lw          $t7, 0x180($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X180);
    // 0x8015FED4: bne         $t7, $at, L_8015FF18
    if (ctx->r15 != ctx->r1) {
        // 0x8015FED8: nop
    
            goto L_8015FF18;
    }
    // 0x8015FED8: nop

    // 0x8015FEDC: lhu         $t8, 0xCE($s0)
    ctx->r24 = MEM_HU(ctx->r16, 0XCE);
    // 0x8015FEE0: andi        $t9, $t8, 0x21
    ctx->r25 = ctx->r24 & 0X21;
    // 0x8015FEE4: beq         $t9, $zero, L_8015FF18
    if (ctx->r25 == 0) {
        // 0x8015FEE8: nop
    
            goto L_8015FF18;
    }
    // 0x8015FEE8: nop

    // 0x8015FEEC: jal         0x800DEEC8
    // 0x8015FEF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015FEF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8015FEF4: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015FEF8: addiu       $a1, $zero, 0xEA
    ctx->r5 = ADD32(0, 0XEA);
    // 0x8015FEFC: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015FF00: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015FF04: jal         0x800E6F24
    // 0x8015FF08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015FF08: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
    // 0x8015FF0C: sw          $zero, 0x180($s0)
    MEM_W(0X180, ctx->r16) = 0;
    // 0x8015FF10: b           L_8015FF18
    // 0x8015FF14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_8015FF18;
    // 0x8015FF14: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_8015FF18:
    // 0x8015FF18: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015FF1C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015FF20: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015FF24: jr          $ra
    // 0x8015FF28: nop

    return;
    // 0x8015FF28: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeRoomFadeInCamera(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801333C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x801333C8: lui         $t6, 0x800D
    ctx->r14 = S32(0X800D << 16);
    // 0x801333CC: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x801333D0: addiu       $t6, $t6, -0x2D34
    ctx->r14 = ADD32(ctx->r14, -0X2D34);
    // 0x801333D4: addiu       $t7, $zero, 0x50
    ctx->r15 = ADD32(0, 0X50);
    // 0x801333D8: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x801333DC: lui         $t9, 0x400
    ctx->r25 = S32(0X400 << 16);
    // 0x801333E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801333E4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x801333E8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x801333EC: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x801333F0: sw          $t1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r9;
    // 0x801333F4: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x801333F8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x801333FC: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80133400: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80133404: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80133408: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x8013340C: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x80133410: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x80133414: addiu       $a0, $zero, 0x401
    ctx->r4 = ADD32(0, 0X401);
    // 0x80133418: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8013341C: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x80133420: jal         0x8000B93C
    // 0x80133424: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeCameraGObj(rdram, ctx);
        goto after_0;
    // 0x80133424: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80133428: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8013342C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80133430: lw          $v1, 0x74($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X74);
    // 0x80133434: lui         $at, 0x4366
    ctx->r1 = S32(0X4366 << 16);
    // 0x80133438: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013343C: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80133440: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80133444: lui         $a3, 0x439B
    ctx->r7 = S32(0X439B << 16);
    // 0x80133448: addiu       $a0, $v1, 0x8
    ctx->r4 = ADD32(ctx->r3, 0X8);
    // 0x8013344C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x80133450: jal         0x80007080
    // 0x80133454: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    syRdpSetViewport(rdram, ctx);
        goto after_1;
    // 0x80133454: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_1:
    // 0x80133458: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8013345C: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x80133460: sw          $t3, 0x80($v1)
    MEM_W(0X80, ctx->r3) = ctx->r11;
    // 0x80133464: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80133468: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8013346C: jr          $ra
    // 0x80133470: nop

    return;
    // 0x80133470: nop

;}
RECOMP_FUNC void itMapCheckCollideAllRebound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801737EC: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x801737F0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x801737F4: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x801737F8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x801737FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80173800: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80173804: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x80173808: sw          $a3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r7;
    // 0x8017380C: lw          $s2, 0x84($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X84);
    // 0x80173810: lw          $s3, 0x74($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X74);
    // 0x80173814: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80173818: lhu         $t6, 0x8C($s2)
    ctx->r14 = MEM_HU(ctx->r18, 0X8C);
    // 0x8017381C: lhu         $v0, 0x8E($s2)
    ctx->r2 = MEM_HU(ctx->r18, 0X8E);
    // 0x80173820: addiu       $s0, $s2, 0x2C
    ctx->r16 = ADD32(ctx->r18, 0X2C);
    // 0x80173824: addiu       $s3, $s3, 0x1C
    ctx->r19 = ADD32(ctx->r19, 0X1C);
    // 0x80173828: xor         $t7, $t6, $v0
    ctx->r15 = ctx->r14 ^ ctx->r2;
    // 0x8017382C: and         $v1, $t7, $v0
    ctx->r3 = ctx->r15 & ctx->r2;
    // 0x80173830: andi        $v1, $v1, 0xC21
    ctx->r3 = ctx->r3 & 0XC21;
    // 0x80173834: andi        $v1, $v1, 0xFFFF
    ctx->r3 = ctx->r3 & 0XFFFF;
    // 0x80173838: and         $t8, $v1, $a1
    ctx->r24 = ctx->r3 & ctx->r5;
    // 0x8017383C: andi        $t0, $t8, 0x1
    ctx->r8 = ctx->r24 & 0X1;
    // 0x80173840: beq         $t0, $zero, L_801738AC
    if (ctx->r8 == 0) {
        // 0x80173844: sw          $t8, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r24;
            goto L_801738AC;
    }
    // 0x80173844: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80173848: addiu       $s1, $s2, 0x38
    ctx->r17 = ADD32(ctx->r18, 0X38);
    // 0x8017384C: addiu       $a1, $s1, 0xA8
    ctx->r5 = ADD32(ctx->r17, 0XA8);
    // 0x80173850: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80173854: jal         0x800C7C0C
    // 0x80173858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbCommonSim2D(rdram, ctx);
        goto after_0;
    // 0x80173858: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x8017385C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80173860: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80173864: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x80173868: nop

    // 0x8017386C: bc1fl       L_801738B0
    if (!c1cs) {
        // 0x80173870: lw          $t2, 0x30($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X30);
            goto L_801738B0;
    }
    goto skip_0;
    // 0x80173870: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    skip_0:
    // 0x80173874: jal         0x800C7B08
    // 0x80173878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    lbCommonReflect2D(rdram, ctx);
        goto after_1;
    // 0x80173878: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8017387C: lwc1        $f6, 0x0($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80173880: lwc1        $f8, 0x44($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X44);
    // 0x80173884: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80173888: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x8017388C: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80173890: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x80173894: lwc1        $f18, 0x3C($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x80173898: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x8017389C: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x801738A0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x801738A4: jal         0x800269C0
    // 0x801738A8: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    func_800269C0_275C0(rdram, ctx);
        goto after_2;
    // 0x801738A8: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    after_2:
L_801738AC:
    // 0x801738AC: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
L_801738B0:
    // 0x801738B0: addiu       $s0, $s2, 0x2C
    ctx->r16 = ADD32(ctx->r18, 0X2C);
    // 0x801738B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801738B8: andi        $t3, $t2, 0x20
    ctx->r11 = ctx->r10 & 0X20;
    // 0x801738BC: beq         $t3, $zero, L_8017391C
    if (ctx->r11 == 0) {
        // 0x801738C0: addiu       $s1, $s2, 0x38
        ctx->r17 = ADD32(ctx->r18, 0X38);
            goto L_8017391C;
    }
    // 0x801738C0: addiu       $s1, $s2, 0x38
    ctx->r17 = ADD32(ctx->r18, 0X38);
    // 0x801738C4: addiu       $a1, $s1, 0xBC
    ctx->r5 = ADD32(ctx->r17, 0XBC);
    // 0x801738C8: jal         0x800C7C0C
    // 0x801738CC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    lbCommonSim2D(rdram, ctx);
        goto after_3;
    // 0x801738CC: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_3:
    // 0x801738D0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801738D4: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x801738D8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801738DC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x801738E0: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x801738E4: bc1fl       L_80173920
    if (!c1cs) {
        // 0x801738E8: lw          $t5, 0x30($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X30);
            goto L_80173920;
    }
    goto skip_1;
    // 0x801738E8: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
    skip_1:
    // 0x801738EC: jal         0x800C7B08
    // 0x801738F0: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    lbCommonReflect2D(rdram, ctx);
        goto after_4;
    // 0x801738F0: sw          $t4, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r12;
    after_4:
    // 0x801738F4: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x801738F8: lwc1        $f10, 0x44($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X44);
    // 0x801738FC: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x80173900: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80173904: swc1        $f16, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f16.u32l;
    // 0x80173908: lwc1        $f4, 0x3C($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x8017390C: lwc1        $f18, 0x4($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80173910: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80173914: jal         0x800269C0
    // 0x80173918: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    func_800269C0_275C0(rdram, ctx);
        goto after_5;
    // 0x80173918: swc1        $f6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f6.u32l;
    after_5:
L_8017391C:
    // 0x8017391C: lw          $t5, 0x30($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X30);
L_80173920:
    // 0x80173920: addiu       $s0, $s2, 0x2C
    ctx->r16 = ADD32(ctx->r18, 0X2C);
    // 0x80173924: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80173928: andi        $t6, $t5, 0x400
    ctx->r14 = ctx->r13 & 0X400;
    // 0x8017392C: beq         $t6, $zero, L_8017397C
    if (ctx->r14 == 0) {
        // 0x80173930: addiu       $s1, $s2, 0x38
        ctx->r17 = ADD32(ctx->r18, 0X38);
            goto L_8017397C;
    }
    // 0x80173930: addiu       $s1, $s2, 0x38
    ctx->r17 = ADD32(ctx->r18, 0X38);
    // 0x80173934: addiu       $a1, $s1, 0x94
    ctx->r5 = ADD32(ctx->r17, 0X94);
    // 0x80173938: jal         0x800C7C0C
    // 0x8017393C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    lbCommonSim2D(rdram, ctx);
        goto after_6;
    // 0x8017393C: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    after_6:
    // 0x80173940: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80173944: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x80173948: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8017394C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80173950: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80173954: bc1fl       L_80173980
    if (!c1cs) {
        // 0x80173958: lw          $t8, 0x30($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X30);
            goto L_80173980;
    }
    goto skip_2;
    // 0x80173958: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    skip_2:
    // 0x8017395C: jal         0x800C7B08
    // 0x80173960: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    lbCommonReflect2D(rdram, ctx);
        goto after_7;
    // 0x80173960: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    after_7:
    // 0x80173964: lwc1        $f10, 0x0($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X0);
    // 0x80173968: swc1        $f10, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f10.u32l;
    // 0x8017396C: lwc1        $f18, 0x38($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X38);
    // 0x80173970: lwc1        $f16, 0x4($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X4);
    // 0x80173974: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80173978: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
L_8017397C:
    // 0x8017397C: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
L_80173980:
    // 0x80173980: addiu       $s0, $s2, 0x2C
    ctx->r16 = ADD32(ctx->r18, 0X2C);
    // 0x80173984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80173988: andi        $t9, $t8, 0x800
    ctx->r25 = ctx->r24 & 0X800;
    // 0x8017398C: beq         $t9, $zero, L_801739E4
    if (ctx->r25 == 0) {
        // 0x80173990: addiu       $s1, $s2, 0x38
        ctx->r17 = ADD32(ctx->r18, 0X38);
            goto L_801739E4;
    }
    // 0x80173990: addiu       $s1, $s2, 0x38
    ctx->r17 = ADD32(ctx->r18, 0X38);
    // 0x80173994: addiu       $a1, $s1, 0x80
    ctx->r5 = ADD32(ctx->r17, 0X80);
    // 0x80173998: jal         0x800C7C0C
    // 0x8017399C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    lbCommonSim2D(rdram, ctx);
        goto after_8;
    // 0x8017399C: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    after_8:
    // 0x801739A0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801739A4: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x801739A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x801739AC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x801739B0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x801739B4: bc1fl       L_801739E8
    if (!c1cs) {
        // 0x801739B8: lw          $t1, 0x3C($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X3C);
            goto L_801739E8;
    }
    goto skip_3;
    // 0x801739B8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    skip_3:
    // 0x801739BC: jal         0x800C7B08
    // 0x801739C0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    lbCommonReflect2D(rdram, ctx);
        goto after_9;
    // 0x801739C0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_9:
    // 0x801739C4: lwc1        $f8, 0x0($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X0);
    // 0x801739C8: addiu       $a0, $zero, 0x2E
    ctx->r4 = ADD32(0, 0X2E);
    // 0x801739CC: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x801739D0: lwc1        $f16, 0x40($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X40);
    // 0x801739D4: lwc1        $f10, 0x4($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X4);
    // 0x801739D8: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x801739DC: jal         0x800269C0
    // 0x801739E0: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    func_800269C0_275C0(rdram, ctx);
        goto after_10;
    // 0x801739E0: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_10:
L_801739E4:
    // 0x801739E4: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
L_801739E8:
    // 0x801739E8: addiu       $a0, $s2, 0x2C
    ctx->r4 = ADD32(ctx->r18, 0X2C);
    // 0x801739EC: beql        $t1, $zero, L_80173A2C
    if (ctx->r9 == 0) {
        // 0x801739F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80173A2C;
    }
    goto skip_4;
    // 0x801739F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_4:
    // 0x801739F4: jal         0x800C7AE0
    // 0x801739F8: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    lbCommonScale2D(rdram, ctx);
        goto after_11;
    // 0x801739F8: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    after_11:
    // 0x801739FC: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x80173A00: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80173A04: beql        $t2, $zero, L_80173A2C
    if (ctx->r10 == 0) {
        // 0x80173A08: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80173A2C;
    }
    goto skip_5;
    // 0x80173A08: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    skip_5:
    // 0x80173A0C: swc1        $f4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->f4.u32l;
    // 0x80173A10: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x80173A14: lwc1        $f6, 0x44($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80173A18: swc1        $f6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->f6.u32l;
    // 0x80173A1C: lw          $t4, 0x64($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X64);
    // 0x80173A20: lwc1        $f8, 0x8($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X8);
    // 0x80173A24: swc1        $f8, 0x8($t4)
    MEM_W(0X8, ctx->r12) = ctx->f8.u32l;
    // 0x80173A28: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80173A2C:
    // 0x80173A2C: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x80173A30: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80173A34: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80173A38: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80173A3C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80173A40: jr          $ra
    // 0x80173A44: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x80173A44: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void ftBossOkutsubushiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015ABEC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8015ABF0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8015ABF4: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x8015ABF8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015ABFC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8015AC00: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8015AC04: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x8015AC08: sw          $zero, 0x44($v1)
    MEM_W(0X44, ctx->r3) = 0;
    // 0x8015AC0C: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015AC10: addiu       $a1, $zero, 0xF7
    ctx->r5 = ADD32(0, 0XF7);
    // 0x8015AC14: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x8015AC18: jal         0x800E6F24
    // 0x8015AC1C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015AC1C: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_0:
    // 0x8015AC20: jal         0x800E0830
    // 0x8015AC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_1;
    // 0x8015AC24: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x8015AC28: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8015AC2C: lw          $v0, 0x74($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X74);
    // 0x8015AC30: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015AC34: lwc1        $f4, 0xB18($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XB18);
    // 0x8015AC38: addiu       $t6, $zero, 0x3D
    ctx->r14 = ADD32(0, 0X3D);
    // 0x8015AC3C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8015AC40: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x8015AC44: lwc1        $f6, 0xB1C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB1C);
    // 0x8015AC48: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
    // 0x8015AC4C: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    // 0x8015AC50: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x8015AC54: lwc1        $f8, -0x37B0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X37B0);
    // 0x8015AC58: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x8015AC5C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8015AC60: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x8015AC64: sh          $t6, 0xB24($v1)
    MEM_H(0XB24, ctx->r3) = ctx->r14;
    // 0x8015AC68: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8015AC6C: lwc1        $f16, -0x37AC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X37AC);
    // 0x8015AC70: addiu       $v0, $v0, 0x1C
    ctx->r2 = ADD32(ctx->r2, 0X1C);
    // 0x8015AC74: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x8015AC78: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x8015AC7C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    // 0x8015AC80: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8015AC84: swc1        $f10, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f10.u32l;
    // 0x8015AC88: jal         0x8010D0A4
    // 0x8015AC8C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    gmCameraSetStatusMapZoom(rdram, ctx);
        goto after_2;
    // 0x8015AC8C: swc1        $f16, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f16.u32l;
    after_2:
    // 0x8015AC90: jal         0x80158604
    // 0x8015AC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftBossCommonSetUseFogColor(rdram, ctx);
        goto after_3;
    // 0x8015AC94: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x8015AC98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8015AC9C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x8015ACA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8015ACA4: jr          $ra
    // 0x8015ACA8: nop

    return;
    // 0x8015ACA8: nop

;}
RECOMP_FUNC void ftKirbyCopyDonkeySpecialAirNStartProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801577D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801577D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801577D8: lui         $a1, 0x8015
    ctx->r5 = S32(0X8015 << 16);
    // 0x801577DC: jal         0x800D9480
    // 0x801577E0: addiu       $a1, $a1, 0x7BEC
    ctx->r5 = ADD32(ctx->r5, 0X7BEC);
    ftAnimEndCheckSetStatus(rdram, ctx);
        goto after_0;
    // 0x801577E0: addiu       $a1, $a1, 0x7BEC
    ctx->r5 = ADD32(ctx->r5, 0X7BEC);
    after_0:
    // 0x801577E4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801577E8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801577EC: jr          $ra
    // 0x801577F0: nop

    return;
    // 0x801577F0: nop

;}
RECOMP_FUNC void ftKirbyCopyYoshiSpecialNSwitchStatusAir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015F45C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8015F460: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015F464: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8015F468: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x8015F46C: jal         0x800DEEC8
    // 0x8015F470: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterAir(rdram, ctx);
        goto after_0;
    // 0x8015F470: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x8015F474: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8015F478: addiu       $t7, $zero, 0x25
    ctx->r15 = ADD32(0, 0X25);
    // 0x8015F47C: addiu       $a1, $zero, 0x12C
    ctx->r5 = ADD32(0, 0X12C);
    // 0x8015F480: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x8015F484: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8015F488: jal         0x800E6F24
    // 0x8015F48C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x8015F48C: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x8015F490: lui         $a1, 0x8016
    ctx->r5 = S32(0X8016 << 16);
    // 0x8015F494: addiu       $a1, $a1, -0x910
    ctx->r5 = ADD32(ctx->r5, -0X910);
    // 0x8015F498: jal         0x8015F180
    // 0x8015F49C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    ftKirbyCopyYoshiSpecialNSetCatchParams(rdram, ctx);
        goto after_2;
    // 0x8015F49C: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    after_2:
    // 0x8015F4A0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015F4A4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8015F4A8: jr          $ra
    // 0x8015F4AC: nop

    return;
    // 0x8015F4AC: nop

;}
RECOMP_FUNC void gmCollisionGetShieldPosition(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800F09F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800F09F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800F09F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800F09FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800F0A00: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800F0A04: lw          $v0, 0x84($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X84);
    // 0x800F0A08: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800F0A0C: swc1        $f0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f0.u32l;
    // 0x800F0A10: swc1        $f0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f0.u32l;
    // 0x800F0A14: swc1        $f0, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f0.u32l;
    // 0x800F0A18: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x800F0A1C: jal         0x800ED3C0
    // 0x800F0A20: addiu       $a0, $v0, 0x50
    ctx->r4 = ADD32(ctx->r2, 0X50);
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_0;
    // 0x800F0A20: addiu       $a0, $v0, 0x50
    ctx->r4 = ADD32(ctx->r2, 0X50);
    after_0:
    // 0x800F0A24: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800F0A28: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800F0A2C: lw          $t7, 0x74($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X74);
    // 0x800F0A30: lwc1        $f4, 0x24($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X24);
    // 0x800F0A34: swc1        $f4, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f4.u32l;
    // 0x800F0A38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800F0A3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800F0A40: jr          $ra
    // 0x800F0A44: nop

    return;
    // 0x800F0A44: nop

;}
RECOMP_FUNC void mnVSResultsSetPlaceStock(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137334: lui         $t6, 0x8014
    ctx->r14 = S32(0X8014 << 16);
    // 0x80137338: lw          $t6, -0x6430($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X6430);
    // 0x8013733C: lui         $t8, 0x8014
    ctx->r24 = S32(0X8014 << 16);
    // 0x80137340: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80137344: beq         $t6, $zero, L_8013735C
    if (ctx->r14 == 0) {
        // 0x80137348: lui         $t2, 0x8014
        ctx->r10 = S32(0X8014 << 16);
            goto L_8013735C;
    }
    // 0x80137348: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x8013734C: lui         $t7, 0x800A
    ctx->r15 = S32(0X800A << 16);
    // 0x80137350: lbu         $t7, 0x4D35($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X4D35);
    // 0x80137354: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137358: sw          $t7, -0x6450($at)
    MEM_W(-0X6450, ctx->r1) = ctx->r15;
L_8013735C:
    // 0x8013735C: lw          $t8, -0x642C($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X642C);
    // 0x80137360: lui         $t9, 0x800A
    ctx->r25 = S32(0X800A << 16);
    // 0x80137364: lui         $t1, 0x800A
    ctx->r9 = S32(0X800A << 16);
    // 0x80137368: beq         $t8, $zero, L_8013737C
    if (ctx->r24 == 0) {
        // 0x8013736C: lui         $t3, 0x800A
        ctx->r11 = S32(0X800A << 16);
            goto L_8013737C;
    }
    // 0x8013736C: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80137370: lbu         $t9, 0x4DA9($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X4DA9);
    // 0x80137374: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137378: sw          $t9, -0x644C($at)
    MEM_W(-0X644C, ctx->r1) = ctx->r25;
L_8013737C:
    // 0x8013737C: lw          $t0, -0x6428($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X6428);
    // 0x80137380: beq         $t0, $zero, L_80137394
    if (ctx->r8 == 0) {
        // 0x80137384: nop
    
            goto L_80137394;
    }
    // 0x80137384: nop

    // 0x80137388: lbu         $t1, 0x4E1D($t1)
    ctx->r9 = MEM_BU(ctx->r9, 0X4E1D);
    // 0x8013738C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80137390: sw          $t1, -0x6448($at)
    MEM_W(-0X6448, ctx->r1) = ctx->r9;
L_80137394:
    // 0x80137394: lw          $t2, -0x6424($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X6424);
    // 0x80137398: beq         $t2, $zero, L_801373AC
    if (ctx->r10 == 0) {
        // 0x8013739C: nop
    
            goto L_801373AC;
    }
    // 0x8013739C: nop

    // 0x801373A0: lbu         $t3, 0x4E91($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4E91);
    // 0x801373A4: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x801373A8: sw          $t3, -0x6444($at)
    MEM_W(-0X6444, ctx->r1) = ctx->r11;
L_801373AC:
    // 0x801373AC: jr          $ra
    // 0x801373B0: nop

    return;
    // 0x801373B0: nop

;}
RECOMP_FUNC void mnPlayers1PGameContinueMakeFighter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801320D4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x801320D8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x801320DC: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x801320E0: addiu       $a0, $sp, 0x1C
    ctx->r4 = ADD32(ctx->r29, 0X1C);
    // 0x801320E4: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x801320E8: addiu       $t6, $t6, 0x6DD0
    ctx->r14 = ADD32(ctx->r14, 0X6DD0);
    // 0x801320EC: addiu       $v0, $v0, 0x4348
    ctx->r2 = ADD32(ctx->r2, 0X4348);
    // 0x801320F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801320F4: addiu       $t0, $t6, 0x3C
    ctx->r8 = ADD32(ctx->r14, 0X3C);
    // 0x801320F8: or          $t9, $a0, $zero
    ctx->r25 = ctx->r4 | 0;
L_801320FC:
    // 0x801320FC: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132100: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132104: addiu       $t9, $t9, 0xC
    ctx->r25 = ADD32(ctx->r25, 0XC);
    // 0x80132108: sw          $t8, -0xC($t9)
    MEM_W(-0XC, ctx->r25) = ctx->r24;
    // 0x8013210C: lw          $t7, -0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, -0X8);
    // 0x80132110: sw          $t7, -0x8($t9)
    MEM_W(-0X8, ctx->r25) = ctx->r15;
    // 0x80132114: lw          $t8, -0x4($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X4);
    // 0x80132118: bne         $t6, $t0, L_801320FC
    if (ctx->r14 != ctx->r8) {
        // 0x8013211C: sw          $t8, -0x4($t9)
        MEM_W(-0X4, ctx->r25) = ctx->r24;
            goto L_801320FC;
    }
    // 0x8013211C: sw          $t8, -0x4($t9)
    MEM_W(-0X4, ctx->r25) = ctx->r24;
    // 0x80132120: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x80132124: lui         $at, 0x42B4
    ctx->r1 = S32(0X42B4 << 16);
    // 0x80132128: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8013212C: sw          $t8, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r24;
    // 0x80132130: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x80132134: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132138: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8013213C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80132140: lw          $t3, 0x42F8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X42F8);
    // 0x80132144: lwc1        $f6, 0x42E0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X42E0);
    // 0x80132148: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8013214C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80132150: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x80132154: sb          $t1, 0x33($sp)
    MEM_B(0X33, ctx->r29) = ctx->r9;
    // 0x80132158: sb          $t2, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r10;
    // 0x8013215C: sw          $t3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r11;
    // 0x80132160: swc1        $f6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f6.u32l;
    // 0x80132164: jal         0x800D7F3C
    // 0x80132168: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    ftManagerMakeFighter(rdram, ctx);
        goto after_0;
    // 0x80132168: swc1        $f8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x8013216C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x80132170: lui         $a1, 0x1
    ctx->r5 = S32(0X1 << 16);
    // 0x80132174: sw          $v0, 0x4300($at)
    MEM_W(0X4300, ctx->r1) = ctx->r2;
    // 0x80132178: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8013217C: ori         $a1, $a1, 0x9
    ctx->r5 = ctx->r5 | 0X9;
    // 0x80132180: jal         0x803905CC
    // 0x80132184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    scSubsysFighterSetStatus(rdram, ctx);
        goto after_1;
    // 0x80132184: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80132188: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x8013218C: lw          $a1, 0x4348($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4348);
    // 0x80132190: jal         0x8013209C
    // 0x80132194: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    mnPlayers1PGameContinueSetFighterScale(rdram, ctx);
        goto after_2;
    // 0x80132194: lw          $a0, 0x5C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X5C);
    after_2:
    // 0x80132198: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8013219C: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x801321A0: jr          $ra
    // 0x801321A4: nop

    return;
    // 0x801321A4: nop

;}
RECOMP_FUNC void syMainVerifyStackProbes(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000510: lui         $t6, 0x8004
    ctx->r14 = S32(0X8004 << 16);
    // 0x80000514: lw          $t6, -0x4F8($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X4F8);
    // 0x80000518: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000051C: lui         $t7, 0x8004
    ctx->r15 = S32(0X8004 << 16);
    // 0x80000520: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80000524: bne         $t6, $zero, L_8000053C
    if (ctx->r14 != 0) {
        // 0x80000528: lw          $t7, -0x4F4($t7)
        ctx->r15 = MEM_W(ctx->r15, -0X4F4);
            goto L_8000053C;
    }
    // 0x80000528: lw          $t7, -0x4F4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F4);
    // 0x8000052C: lui         $at, 0xFEDC
    ctx->r1 = S32(0XFEDC << 16);
    // 0x80000530: ori         $at, $at, 0xBA98
    ctx->r1 = ctx->r1 | 0XBA98;
    // 0x80000534: beq         $t7, $at, L_80000544
    if (ctx->r15 == ctx->r1) {
        // 0x80000538: nop
    
            goto L_80000544;
    }
    // 0x80000538: nop

L_8000053C:
    // 0x8000053C: jal         0x800004E0
    // 0x80000540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    syMainThreadStackOverflow(rdram, ctx);
        goto after_0;
    // 0x80000540: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
L_80000544:
    // 0x80000544: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80000548: lw          $t8, -0x148($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X148);
    // 0x8000054C: lui         $t9, 0x8004
    ctx->r25 = S32(0X8004 << 16);
    // 0x80000550: lw          $t9, -0x144($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X144);
    // 0x80000554: bne         $t8, $zero, L_80000568
    if (ctx->r24 != 0) {
        // 0x80000558: lui         $at, 0xFEDC
        ctx->r1 = S32(0XFEDC << 16);
            goto L_80000568;
    }
    // 0x80000558: lui         $at, 0xFEDC
    ctx->r1 = S32(0XFEDC << 16);
    // 0x8000055C: ori         $at, $at, 0xBA98
    ctx->r1 = ctx->r1 | 0XBA98;
    // 0x80000560: beq         $t9, $at, L_80000570
    if (ctx->r25 == ctx->r1) {
        // 0x80000564: nop
    
            goto L_80000570;
    }
    // 0x80000564: nop

L_80000568:
    // 0x80000568: jal         0x800004E0
    // 0x8000056C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    syMainThreadStackOverflow(rdram, ctx);
        goto after_1;
    // 0x8000056C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_80000570:
    // 0x80000570: lui         $t0, 0x8004
    ctx->r8 = S32(0X8004 << 16);
    // 0x80000574: lw          $t0, 0x168($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X168);
    // 0x80000578: lui         $t1, 0x8004
    ctx->r9 = S32(0X8004 << 16);
    // 0x8000057C: lw          $t1, 0x16C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X16C);
    // 0x80000580: bne         $t0, $zero, L_80000594
    if (ctx->r8 != 0) {
        // 0x80000584: lui         $at, 0xFEDC
        ctx->r1 = S32(0XFEDC << 16);
            goto L_80000594;
    }
    // 0x80000584: lui         $at, 0xFEDC
    ctx->r1 = S32(0XFEDC << 16);
    // 0x80000588: ori         $at, $at, 0xBA98
    ctx->r1 = ctx->r1 | 0XBA98;
    // 0x8000058C: beq         $t1, $at, L_8000059C
    if (ctx->r9 == ctx->r1) {
        // 0x80000590: nop
    
            goto L_8000059C;
    }
    // 0x80000590: nop

L_80000594:
    // 0x80000594: jal         0x800004E0
    // 0x80000598: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syMainThreadStackOverflow(rdram, ctx);
        goto after_2;
    // 0x80000598: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
L_8000059C:
    // 0x8000059C: lui         $t2, 0x8004
    ctx->r10 = S32(0X8004 << 16);
    // 0x800005A0: lw          $t2, 0xEC8($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XEC8);
    // 0x800005A4: lui         $t3, 0x8004
    ctx->r11 = S32(0X8004 << 16);
    // 0x800005A8: lw          $t3, 0xECC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XECC);
    // 0x800005AC: bne         $t2, $zero, L_800005C0
    if (ctx->r10 != 0) {
        // 0x800005B0: lui         $at, 0xFEDC
        ctx->r1 = S32(0XFEDC << 16);
            goto L_800005C0;
    }
    // 0x800005B0: lui         $at, 0xFEDC
    ctx->r1 = S32(0XFEDC << 16);
    // 0x800005B4: ori         $at, $at, 0xBA98
    ctx->r1 = ctx->r1 | 0XBA98;
    // 0x800005B8: beql        $t3, $at, L_800005CC
    if (ctx->r11 == ctx->r1) {
        // 0x800005BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800005CC;
    }
    goto skip_0;
    // 0x800005BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
L_800005C0:
    // 0x800005C0: jal         0x800004E0
    // 0x800005C4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    syMainThreadStackOverflow(rdram, ctx);
        goto after_3;
    // 0x800005C4: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_3:
    // 0x800005C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800005CC:
    // 0x800005CC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800005D0: jr          $ra
    // 0x800005D4: nop

    return;
    // 0x800005D4: nop

;}
RECOMP_FUNC void scStaffrollInitVars(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134E08: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80134E0C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E10: sw          $t6, -0x5740($at)
    MEM_W(-0X5740, ctx->r1) = ctx->r14;
    // 0x80134E14: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E18: sw          $zero, -0x5748($at)
    MEM_W(-0X5748, ctx->r1) = 0;
    // 0x80134E1C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E20: lwc1        $f4, -0x5838($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5838);
    // 0x80134E24: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E28: lui         $v0, 0x8014
    ctx->r2 = S32(0X8014 << 16);
    // 0x80134E2C: swc1        $f4, -0x5744($at)
    MEM_W(-0X5744, ctx->r1) = ctx->f4.u32l;
    // 0x80134E30: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E34: lw          $v0, -0x55F0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X55F0);
    // 0x80134E38: sw          $zero, -0x573C($at)
    MEM_W(-0X573C, ctx->r1) = 0;
    // 0x80134E3C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E40: lui         $t7, 0x0
    ctx->r15 = S32(0X0 << 16);
    // 0x80134E44: sw          $zero, -0x5730($at)
    MEM_W(-0X5730, ctx->r1) = 0;
    // 0x80134E48: addiu       $t7, $t7, 0x7304
    ctx->r15 = ADD32(ctx->r15, 0X7304);
    // 0x80134E4C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E50: lui         $t9, 0x0
    ctx->r25 = S32(0X0 << 16);
    // 0x80134E54: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x80134E58: sw          $t8, -0x5720($at)
    MEM_W(-0X5720, ctx->r1) = ctx->r24;
    // 0x80134E5C: addiu       $t9, $t9, 0x7338
    ctx->r25 = ADD32(ctx->r25, 0X7338);
    // 0x80134E60: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E64: lui         $t1, 0x0
    ctx->r9 = S32(0X0 << 16);
    // 0x80134E68: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x80134E6C: sw          $t0, -0x5724($at)
    MEM_W(-0X5724, ctx->r1) = ctx->r8;
    // 0x80134E70: addiu       $t1, $t1, 0x78C0
    ctx->r9 = ADD32(ctx->r9, 0X78C0);
    // 0x80134E74: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E78: addu        $t2, $v0, $t1
    ctx->r10 = ADD32(ctx->r2, ctx->r9);
    // 0x80134E7C: sw          $t2, -0x5718($at)
    MEM_W(-0X5718, ctx->r1) = ctx->r10;
    // 0x80134E80: lui         $t3, 0x800A
    ctx->r11 = S32(0X800A << 16);
    // 0x80134E84: lbu         $t3, 0x4AE3($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X4AE3);
    // 0x80134E88: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E8C: sw          $zero, -0x5700($at)
    MEM_W(-0X5700, ctx->r1) = 0;
    // 0x80134E90: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E94: sb          $t3, -0x56FC($at)
    MEM_B(-0X56FC, ctx->r1) = ctx->r11;
    // 0x80134E98: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80134E9C: addiu       $t4, $zero, 0x3C
    ctx->r12 = ADD32(0, 0X3C);
    // 0x80134EA0: jr          $ra
    // 0x80134EA4: sw          $t4, -0x56F8($at)
    MEM_W(-0X56F8, ctx->r1) = ctx->r12;
    return;
    // 0x80134EA4: sw          $t4, -0x56F8($at)
    MEM_W(-0X56F8, ctx->r1) = ctx->r12;
;}
RECOMP_FUNC void ftKirbySpecialAirNCatchSwitchStatusGround(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80162C40: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80162C44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80162C48: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80162C4C: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80162C50: jal         0x800DEE98
    // 0x80162C54: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_0;
    // 0x80162C54: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    after_0:
    // 0x80162C58: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80162C5C: addiu       $t7, $zero, 0x24
    ctx->r15 = ADD32(0, 0X24);
    // 0x80162C60: addiu       $a1, $zero, 0x110
    ctx->r5 = ADD32(0, 0X110);
    // 0x80162C64: lw          $a2, 0x78($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X78);
    // 0x80162C68: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80162C6C: jal         0x800E6F24
    // 0x80162C70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_1;
    // 0x80162C70: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_1:
    // 0x80162C74: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x80162C78: jal         0x800E8098
    // 0x80162C7C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    ftParamSetCaptureImmuneMask(rdram, ctx);
        goto after_2;
    // 0x80162C7C: addiu       $a1, $zero, 0x3F
    ctx->r5 = ADD32(0, 0X3F);
    after_2:
    // 0x80162C80: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80162C84: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80162C88: jr          $ra
    // 0x80162C8C: nop

    return;
    // 0x80162C8C: nop

;}
RECOMP_FUNC void mnVSOptionsSetToggleSpriteColors(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80131FFC: lw          $t6, 0x74($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X74);
    // 0x80132000: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x80132004: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x80132008: lw          $t7, 0x8($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X8);
    // 0x8013200C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80132010: beq         $a1, $zero, L_80132048
    if (ctx->r5 == 0) {
        // 0x80132014: lw          $v0, 0x8($t7)
        ctx->r2 = MEM_W(ctx->r15, 0X8);
            goto L_80132048;
    }
    // 0x80132014: lw          $v0, 0x8($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X8);
    // 0x80132018: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x8013201C: addiu       $t9, $zero, 0x28
    ctx->r25 = ADD32(0, 0X28);
    // 0x80132020: addiu       $v1, $zero, 0x32
    ctx->r3 = ADD32(0, 0X32);
    // 0x80132024: sb          $t8, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r24;
    // 0x80132028: sb          $zero, 0x29($v0)
    MEM_B(0X29, ctx->r2) = 0;
    // 0x8013202C: sb          $t9, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r25;
    // 0x80132030: sb          $v1, 0x28($t0)
    MEM_B(0X28, ctx->r8) = ctx->r3;
    // 0x80132034: lw          $t1, 0x8($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X8);
    // 0x80132038: sb          $v1, 0x29($t1)
    MEM_B(0X29, ctx->r9) = ctx->r3;
    // 0x8013203C: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x80132040: jr          $ra
    // 0x80132044: sb          $v1, 0x2A($t2)
    MEM_B(0X2A, ctx->r10) = ctx->r3;
    return;
    // 0x80132044: sb          $v1, 0x2A($t2)
    MEM_B(0X2A, ctx->r10) = ctx->r3;
L_80132048:
    // 0x80132048: lw          $t4, 0x8($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X8);
    // 0x8013204C: sb          $v1, 0x28($v0)
    MEM_B(0X28, ctx->r2) = ctx->r3;
    // 0x80132050: sb          $v1, 0x29($v0)
    MEM_B(0X29, ctx->r2) = ctx->r3;
    // 0x80132054: sb          $v1, 0x2A($v0)
    MEM_B(0X2A, ctx->r2) = ctx->r3;
    // 0x80132058: sb          $t3, 0x28($t4)
    MEM_B(0X28, ctx->r12) = ctx->r11;
    // 0x8013205C: lw          $t5, 0x8($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X8);
    // 0x80132060: addiu       $t6, $zero, 0x28
    ctx->r14 = ADD32(0, 0X28);
    // 0x80132064: sb          $zero, 0x29($t5)
    MEM_B(0X29, ctx->r13) = 0;
    // 0x80132068: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x8013206C: sb          $t6, 0x2A($t7)
    MEM_B(0X2A, ctx->r15) = ctx->r14;
    // 0x80132070: jr          $ra
    // 0x80132074: nop

    return;
    // 0x80132074: nop

;}
RECOMP_FUNC void ftComputerCheckSetTargetEdgeLeft(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80134368: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x8013436C: sdc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    SD(ctx->f28.u64, 0X38, ctx->r29);
    // 0x80134370: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x80134374: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x80134378: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x8013437C: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80134380: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80134384: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x80134388: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x8013438C: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x80134390: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x80134394: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x80134398: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8013439C: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x801343A0: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x801343A4: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x801343A8: mtc1        $zero, $f28
    ctx->f28.u32l = 0;
    // 0x801343AC: lwc1        $f4, 0x4C($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X4C);
    // 0x801343B0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x801343B4: lui         $s3, 0x800A
    ctx->r19 = S32(0X800A << 16);
    // 0x801343B8: c.le.s      $f28, $f4
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f28.fl <= ctx->f4.fl;
    // 0x801343BC: or          $fp, $a1, $zero
    ctx->r30 = ctx->r5 | 0;
    // 0x801343C0: addiu       $s4, $s2, 0x1CC
    ctx->r20 = ADD32(ctx->r18, 0X1CC);
    // 0x801343C4: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x801343C8: bc1f        L_80134400
    if (!c1cs) {
        // 0x801343CC: addiu       $s3, $s3, 0x50E8
        ctx->r19 = ADD32(ctx->r19, 0X50E8);
            goto L_80134400;
    }
    // 0x801343CC: addiu       $s3, $s3, 0x50E8
    ctx->r19 = ADD32(ctx->r19, 0X50E8);
    // 0x801343D0: lw          $t6, 0x8E8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8E8);
    // 0x801343D4: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x801343D8: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x801343DC: lwc1        $f6, 0x1C($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X1C);
    // 0x801343E0: addiu       $s4, $a0, 0x1CC
    ctx->r20 = ADD32(ctx->r4, 0X1CC);
    // 0x801343E4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x801343E8: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x801343EC: swc1        $f8, 0x60($s4)
    MEM_W(0X60, ctx->r20) = ctx->f8.u32l;
    // 0x801343F0: lw          $t7, 0x8E8($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X8E8);
    // 0x801343F4: lwc1        $f10, 0x20($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X20);
    // 0x801343F8: b           L_80134690
    // 0x801343FC: swc1        $f10, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->f10.u32l;
        goto L_80134690;
    // 0x801343FC: swc1        $f10, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->f10.u32l;
L_80134400:
    // 0x80134400: lwc1        $f16, 0x90($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X90);
    // 0x80134404: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80134408: lw          $t8, 0x8($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X8);
    // 0x8013440C: addiu       $at, $zero, 0xD
    ctx->r1 = ADD32(0, 0XD);
    // 0x80134410: mul.s       $f24, $f16, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x80134414: bne         $t8, $at, L_80134424
    if (ctx->r24 != ctx->r1) {
        // 0x80134418: lui         $s5, 0x8013
        ctx->r21 = S32(0X8013 << 16);
            goto L_80134424;
    }
    // 0x80134418: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x8013441C: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80134420: nop

L_80134424:
    // 0x80134424: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80134428: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8013442C: addiu       $s5, $s5, 0x1348
    ctx->r21 = ADD32(ctx->r21, 0X1348);
    // 0x80134430: lbu         $t0, 0x1($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X1);
    // 0x80134434: addiu       $s7, $zero, 0x8
    ctx->r23 = ADD32(0, 0X8);
    // 0x80134438: addiu       $s6, $zero, 0x3
    ctx->r22 = ADD32(0, 0X3);
    // 0x8013443C: bnel        $t0, $at, L_80134450
    if (ctx->r8 != ctx->r1) {
        // 0x80134440: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_80134450;
    }
    goto skip_0;
    // 0x80134440: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_0:
    // 0x80134444: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80134448: nop

    // 0x8013444C: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
L_80134450:
    // 0x80134450: lw          $v0, 0x4($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X4);
    // 0x80134454: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80134458: blez        $t1, L_8013468C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8013445C: lui         $at, 0x40A0
        ctx->r1 = S32(0X40A0 << 16);
            goto L_8013468C;
    }
    // 0x8013445C: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80134460: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80134464: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80134468: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8013446C: lui         $at, 0x43FA
    ctx->r1 = S32(0X43FA << 16);
    // 0x80134470: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80134474: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80134478:
    // 0x80134478: jal         0x800FC67C
    // 0x8013447C: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    mpCollisionCheckExistLineID(rdram, ctx);
        goto after_0;
    // 0x8013447C: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_0:
    // 0x80134480: beq         $v0, $zero, L_80134674
    if (ctx->r2 == 0) {
        // 0x80134484: addiu       $a1, $sp, 0x98
        ctx->r5 = ADD32(ctx->r29, 0X98);
            goto L_80134674;
    }
    // 0x80134484: addiu       $a1, $sp, 0x98
    ctx->r5 = ADD32(ctx->r29, 0X98);
    // 0x80134488: jal         0x800F4428
    // 0x8013448C: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    mpCollisionGetFloorEdgeL(rdram, ctx);
        goto after_1;
    // 0x8013448C: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_1:
    // 0x80134490: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80134494: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x80134498: lbu         $t3, 0x1($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X1);
    // 0x8013449C: bnel        $s6, $t3, L_801344EC
    if (ctx->r22 != ctx->r11) {
        // 0x801344A0: lw          $t4, 0x0($s3)
        ctx->r12 = MEM_W(ctx->r19, 0X0);
            goto L_801344EC;
    }
    goto skip_1;
    // 0x801344A0: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    skip_1:
    // 0x801344A4: jal         0x8010850C
    // 0x801344A8: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    grZebesAcidGetLevelInfo(rdram, ctx);
        goto after_2;
    // 0x801344A8: addiu       $a1, $sp, 0x90
    ctx->r5 = ADD32(ctx->r29, 0X90);
    after_2:
    // 0x801344AC: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x801344B0: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x801344B4: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x801344B8: add.s       $f6, $f0, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x801344BC: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801344C0: nop

    // 0x801344C4: bc1tl       L_80134678
    if (c1cs) {
        // 0x801344C8: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_80134678;
    }
    goto skip_2;
    // 0x801344C8: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_2:
    // 0x801344CC: mul.s       $f10, $f26, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f26.fl, ctx->f8.fl);
    // 0x801344D0: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x801344D4: add.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f20.fl;
    // 0x801344D8: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x801344DC: nop

    // 0x801344E0: bc1tl       L_80134678
    if (c1cs) {
        // 0x801344E4: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_80134678;
    }
    goto skip_3;
    // 0x801344E4: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_3:
    // 0x801344E8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
L_801344EC:
    // 0x801344EC: lbu         $t5, 0x1($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X1);
    // 0x801344F0: bnel        $s7, $t5, L_8013450C
    if (ctx->r23 != ctx->r13) {
        // 0x801344F4: lw          $a1, 0x8E8($s2)
        ctx->r5 = MEM_W(ctx->r18, 0X8E8);
            goto L_8013450C;
    }
    goto skip_4;
    // 0x801344F4: lw          $a1, 0x8E8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8E8);
    skip_4:
    // 0x801344F8: jal         0x800FCA18
    // 0x801344FC: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    mpCollisionCheckExistPlatformLineID(rdram, ctx);
        goto after_3;
    // 0x801344FC: lhu         $a0, 0x0($s0)
    ctx->r4 = MEM_HU(ctx->r16, 0X0);
    after_3:
    // 0x80134500: bnel        $v0, $zero, L_80134678
    if (ctx->r2 != 0) {
        // 0x80134504: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_80134678;
    }
    goto skip_5;
    // 0x80134504: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_5:
    // 0x80134508: lw          $a1, 0x8E8($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X8E8);
L_8013450C:
    // 0x8013450C: lwc1        $f8, 0x98($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80134510: lwc1        $f6, 0x1C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x80134514: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80134518: c.lt.s      $f12, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f12.fl < ctx->f28.fl;
    // 0x8013451C: nop

    // 0x80134520: bc1fl       L_80134678
    if (!c1cs) {
        // 0x80134524: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_80134678;
    }
    goto skip_6;
    // 0x80134524: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_6:
    // 0x80134528: lw          $v1, 0x9C8($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X9C8);
    // 0x8013452C: lwc1        $f0, 0x4C($s2)
    ctx->f0.u32l = MEM_W(ctx->r18, 0X4C);
    // 0x80134530: lwc1        $f14, 0x5C($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x80134534: lwc1        $f10, 0x50($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X50);
    // 0x80134538: lwc1        $f2, 0x58($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X58);
    // 0x8013453C: neg.s       $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = -ctx->f14.fl;
    // 0x80134540: neg.s       $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = -ctx->f10.fl;
    // 0x80134544: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80134548: div.s       $f4, $f12, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f12.fl, ctx->f16.fl);
    // 0x8013454C: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80134550: div.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80134554: trunc.w.s   $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = TRUNC_W_S(ctx->f4.fl);
    // 0x80134558: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x8013455C: trunc.w.s   $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = TRUNC_W_S(ctx->f16.fl);
    // 0x80134560: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80134564: nop

    // 0x80134568: bgtz        $a0, L_80134588
    if (SIGNED(ctx->r4) > 0) {
        // 0x8013456C: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80134588;
    }
    // 0x8013456C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80134570: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80134574: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80134578: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8013457C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80134580: b           L_80134610
    // 0x80134584: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
        goto L_80134610;
    // 0x80134584: add.s       $f12, $f18, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f10.fl;
L_80134588:
    // 0x80134588: beq         $at, $zero, L_801345CC
    if (ctx->r1 == 0) {
        // 0x8013458C: nop
    
            goto L_801345CC;
    }
    // 0x8013458C: nop

    // 0x80134590: multu       $v0, $v0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80134594: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x80134598: nop

    // 0x8013459C: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801345A0: mflo        $t8
    ctx->r24 = lo;
    // 0x801345A4: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x801345A8: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x801345AC: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x801345B0: lwc1        $f8, 0x20($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X20);
    // 0x801345B4: mul.s       $f10, $f2, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x801345B8: nop

    // 0x801345BC: mul.s       $f16, $f10, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x801345C0: sub.s       $f4, $f6, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f16.fl;
    // 0x801345C4: b           L_80134610
    // 0x801345C8: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
        goto L_80134610;
    // 0x801345C8: add.s       $f12, $f8, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f4.fl;
L_801345CC:
    // 0x801345CC: multu       $a0, $a0
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801345D0: mtc1        $v0, $f18
    ctx->f18.u32l = ctx->r2;
    // 0x801345D4: subu        $t0, $v0, $a0
    ctx->r8 = SUB32(ctx->r2, ctx->r4);
    // 0x801345D8: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x801345DC: mflo        $t9
    ctx->r25 = lo;
    // 0x801345E0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x801345E4: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x801345E8: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801345EC: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x801345F0: mul.s       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x801345F4: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x801345F8: mul.s       $f18, $f4, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x801345FC: sub.s       $f10, $f6, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80134600: mul.s       $f4, $f14, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f8.fl);
    // 0x80134604: lwc1        $f18, 0x20($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80134608: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x8013460C: add.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f6.fl;
L_80134610:
    // 0x80134610: bne         $fp, $zero, L_80134630
    if (ctx->r30 != 0) {
        // 0x80134614: lwc1        $f16, 0x9C($sp)
        ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
            goto L_80134630;
    }
    // 0x80134614: lwc1        $f16, 0x9C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80134618: lwc1        $f8, 0x90($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0X90);
    // 0x8013461C: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x80134620: c.lt.s      $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f12.fl < ctx->f10.fl;
    // 0x80134624: nop

    // 0x80134628: bc1tl       L_80134678
    if (c1cs) {
        // 0x8013462C: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_80134678;
    }
    goto skip_7;
    // 0x8013462C: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_7:
L_80134630:
    // 0x80134630: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80134634: c.lt.s      $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f12.fl < ctx->f4.fl;
    // 0x80134638: nop

    // 0x8013463C: bc1fl       L_8013465C
    if (!c1cs) {
        // 0x80134640: lwc1        $f6, 0x98($sp)
        ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
            goto L_8013465C;
    }
    goto skip_8;
    // 0x80134640: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
    skip_8:
    // 0x80134644: sub.s       $f18, $f4, $f24
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f24.fl;
    // 0x80134648: c.lt.s      $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f18.fl < ctx->f12.fl;
    // 0x8013464C: nop

    // 0x80134650: bc1tl       L_80134678
    if (c1cs) {
        // 0x80134654: lhu         $t1, 0x0($s5)
        ctx->r9 = MEM_HU(ctx->r21, 0X0);
            goto L_80134678;
    }
    goto skip_9;
    // 0x80134654: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
    skip_9:
    // 0x80134658: lwc1        $f6, 0x98($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X98);
L_8013465C:
    // 0x8013465C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80134660: add.s       $f16, $f6, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80134664: swc1        $f16, 0x60($s4)
    MEM_W(0X60, ctx->r20) = ctx->f16.u32l;
    // 0x80134668: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x8013466C: b           L_80134690
    // 0x80134670: swc1        $f8, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->f8.u32l;
        goto L_80134690;
    // 0x80134670: swc1        $f8, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->f8.u32l;
L_80134674:
    // 0x80134674: lhu         $t1, 0x0($s5)
    ctx->r9 = MEM_HU(ctx->r21, 0X0);
L_80134678:
    // 0x80134678: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8013467C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80134680: slt         $at, $s1, $t1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80134684: bne         $at, $zero, L_80134478
    if (ctx->r1 != 0) {
        // 0x80134688: nop
    
            goto L_80134478;
    }
    // 0x80134688: nop

L_8013468C:
    // 0x8013468C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80134690:
    // 0x80134690: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x80134694: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x80134698: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8013469C: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x801346A0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x801346A4: ldc1        $f28, 0x38($sp)
    CHECK_FR(ctx, 28);
    ctx->f28.u64 = LD(ctx->r29, 0X38);
    // 0x801346A8: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x801346AC: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x801346B0: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x801346B4: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x801346B8: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x801346BC: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x801346C0: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x801346C4: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x801346C8: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x801346CC: jr          $ra
    // 0x801346D0: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x801346D0: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void ftDonkeyThrowFKneeBendProcInterrupt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8014D8E4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8014D8E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8014D8EC: lw          $v1, 0x84($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X84);
    // 0x8014D8F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8014D8F4: jal         0x80146BE0
    // 0x8014D8F8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftCommonHeavyThrowCheckInterruptCommon(rdram, ctx);
        goto after_0;
    // 0x8014D8F8: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x8014D8FC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014D900: bne         $v0, $zero, L_8014D940
    if (ctx->r2 != 0) {
        // 0x8014D904: lw          $a0, 0x20($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X20);
            goto L_8014D940;
    }
    // 0x8014D904: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8014D908: jal         0x8014DFA8
    // 0x8014D90C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    ftDonkeyThrowFFCheckInterruptThrowFCommon(rdram, ctx);
        goto after_1;
    // 0x8014D90C: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_1:
    // 0x8014D910: bne         $v0, $zero, L_8014D940
    if (ctx->r2 != 0) {
        // 0x8014D914: lw          $v1, 0x1C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X1C);
            goto L_8014D940;
    }
    // 0x8014D914: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8014D918: lb          $t6, 0x1C3($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1C3);
    // 0x8014D91C: lwc1        $f6, 0xB18($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XB18);
    // 0x8014D920: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8014D924: nop

    // 0x8014D928: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8014D92C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x8014D930: nop

    // 0x8014D934: bc1fl       L_8014D944
    if (!c1cs) {
        // 0x8014D938: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8014D944;
    }
    goto skip_0;
    // 0x8014D938: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x8014D93C: swc1        $f0, 0xB18($v1)
    MEM_W(0XB18, ctx->r3) = ctx->f0.u32l;
L_8014D940:
    // 0x8014D940: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8014D944:
    // 0x8014D944: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8014D948: jr          $ra
    // 0x8014D94C: nop

    return;
    // 0x8014D94C: nop

;}
RECOMP_FUNC void mvOpeningSectorCameraProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801323E0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801323E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801323E8: jal         0x80010580
    // 0x801323EC: nop

    gcPlayCamAnim(rdram, ctx);
        goto after_0;
    // 0x801323EC: nop

    after_0:
    // 0x801323F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801323F4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x801323F8: jr          $ra
    // 0x801323FC: nop

    return;
    // 0x801323FC: nop

;}
RECOMP_FUNC void ftYoshiSpecialAirHiSetStatus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8015ED7C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8015ED80: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8015ED84: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8015ED88: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8015ED8C: addiu       $a1, $zero, 0xDF
    ctx->r5 = ADD32(0, 0XDF);
    // 0x8015ED90: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x8015ED94: jal         0x800E6F24
    // 0x8015ED98: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    ftMainSetStatus(rdram, ctx);
        goto after_0;
    // 0x8015ED98: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    after_0:
    // 0x8015ED9C: jal         0x8015ED18
    // 0x8015EDA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftYoshiSpecialHiInitStatusVars(rdram, ctx);
        goto after_1;
    // 0x8015EDA0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_1:
    // 0x8015EDA4: jal         0x800E0830
    // 0x8015EDA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftMainPlayAnimEventsAll(rdram, ctx);
        goto after_2;
    // 0x8015EDA8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_2:
    // 0x8015EDAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8015EDB0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8015EDB4: jr          $ra
    // 0x8015EDB8: nop

    return;
    // 0x8015EDB8: nop

;}
RECOMP_FUNC void ftPublicTryInterruptCall(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80164C18: lui         $v0, 0x8019
    ctx->r2 = S32(0X8019 << 16);
    // 0x80164C1C: lw          $v0, -0x3048($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3048);
    // 0x80164C20: slti        $at, $v0, 0x9
    ctx->r1 = SIGNED(ctx->r2) < 0X9 ? 1 : 0;
    // 0x80164C24: beq         $at, $zero, L_80164C3C
    if (ctx->r1 == 0) {
        // 0x80164C28: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_80164C3C;
    }
    // 0x80164C28: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80164C2C: bne         $at, $zero, L_80164C3C
    if (ctx->r1 != 0) {
        // 0x80164C30: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80164C3C;
    }
    // 0x80164C30: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80164C34: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x80164C38: sw          $t6, -0x305C($at)
    MEM_W(-0X305C, ctx->r1) = ctx->r14;
L_80164C3C:
    // 0x80164C3C: jr          $ra
    // 0x80164C40: nop

    return;
    // 0x80164C40: nop

;}
RECOMP_FUNC void ifCommonEntryAllThread(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80112A34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80112A38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80112A3C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80112A40: jal         0x8000B1E8
    // 0x80112A44: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_0;
    // 0x80112A44: addiu       $a0, $zero, 0x5A
    ctx->r4 = ADD32(0, 0X5A);
    after_0:
    // 0x80112A48: jal         0x80112668
    // 0x80112A4C: nop

    ifCommonCountdownMakeInterface(rdram, ctx);
        goto after_1;
    // 0x80112A4C: nop

    after_1:
    // 0x80112A50: jal         0x80018994
    // 0x80112A54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    syUtilsRandIntRange(rdram, ctx);
        goto after_2;
    // 0x80112A54: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x80112A58: jal         0x801129DC
    // 0x80112A5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    ifCommonEntryFocusMakeInterface(rdram, ctx);
        goto after_3;
    // 0x80112A5C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80112A60: jal         0x80009A84
    // 0x80112A64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    gcEjectGObj(rdram, ctx);
        goto after_4;
    // 0x80112A64: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80112A68: jal         0x8000B1E8
    // 0x80112A6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    gcSleepCurrentGObjThread(rdram, ctx);
        goto after_5;
    // 0x80112A6C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x80112A70: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80112A74: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80112A78: jr          $ra
    // 0x80112A7C: nop

    return;
    // 0x80112A7C: nop

;}
RECOMP_FUNC void itStarRodWeaponStarProcHop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8017835C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80178360: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80178364: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80178368: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x8017836C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80178370: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80178374: lwc1        $f4, 0x244($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X244);
    // 0x80178378: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8017837C: addiu       $a0, $v0, 0x20
    ctx->r4 = ADD32(ctx->r2, 0X20);
    // 0x80178380: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80178384: addiu       $a1, $v0, 0x248
    ctx->r5 = ADD32(ctx->r2, 0X248);
    // 0x80178388: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x8017838C: jal         0x80019438
    // 0x80178390: nop

    syVectorRotateAbout3D(rdram, ctx);
        goto after_0;
    // 0x80178390: nop

    after_0:
    // 0x80178394: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80178398: lwc1        $f12, 0x24($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8017839C: jal         0x8001863C
    // 0x801783A0: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    syUtilsArcTan2(rdram, ctx);
        goto after_1;
    // 0x801783A0: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    after_1:
    // 0x801783A4: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x801783A8: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x801783AC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x801783B0: lw          $t7, 0x74($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X74);
    // 0x801783B4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x801783B8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x801783BC: swc1        $f0, 0x38($t7)
    MEM_W(0X38, ctx->r15) = ctx->f0.u32l;
    // 0x801783C0: lw          $t8, 0x74($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X74);
    // 0x801783C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x801783C8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x801783CC: swc1        $f10, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f10.u32l;
    // 0x801783D0: lwc1        $f18, 0x20($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X20);
    // 0x801783D4: c.lt.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl < ctx->f18.fl;
    // 0x801783D8: nop

    // 0x801783DC: bc1fl       L_801783F0
    if (!c1cs) {
        // 0x801783E0: sw          $t0, 0x18($v0)
        MEM_W(0X18, ctx->r2) = ctx->r8;
            goto L_801783F0;
    }
    goto skip_0;
    // 0x801783E0: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
    skip_0:
    // 0x801783E4: b           L_801783F0
    // 0x801783E8: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
        goto L_801783F0;
    // 0x801783E8: sw          $t9, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r25;
    // 0x801783EC: sw          $t0, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r8;
L_801783F0:
    // 0x801783F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x801783F4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801783F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x801783FC: jr          $ra
    // 0x80178400: nop

    return;
    // 0x80178400: nop

;}
RECOMP_FUNC void func_ovl8_80371D00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80371D00: jr          $ra
    // 0x80371D04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    return;
    // 0x80371D04: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
;}
RECOMP_FUNC void mpCommonCheckFighterCeilHeavyCliff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800DE87C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800DE880: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800DE884: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x800DE888: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800DE88C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800DE890: addiu       $a1, $a1, -0x1BA4
    ctx->r5 = ADD32(ctx->r5, -0X1BA4);
    // 0x800DE894: addiu       $a3, $zero, 0x9
    ctx->r7 = ADD32(0, 0X9);
    // 0x800DE898: jal         0x800DA034
    // 0x800DE89C: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    mpProcessUpdateMain(rdram, ctx);
        goto after_0;
    // 0x800DE89C: addiu       $a0, $v0, 0x78
    ctx->r4 = ADD32(ctx->r2, 0X78);
    after_0:
    // 0x800DE8A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800DE8A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800DE8A8: jr          $ra
    // 0x800DE8AC: nop

    return;
    // 0x800DE8AC: nop

;}
RECOMP_FUNC void ftKirbySpecialHiProcMap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8016104C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80161050: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80161054: lw          $a1, 0x84($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X84);
    // 0x80161058: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8016105C: lw          $t6, 0x14C($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X14C);
    // 0x80161060: bnel        $t6, $zero, L_80161088
    if (ctx->r14 != 0) {
        // 0x80161064: or          $a0, $a2, $zero
        ctx->r4 = ctx->r6 | 0;
            goto L_80161088;
    }
    goto skip_0;
    // 0x80161064: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    skip_0:
    // 0x80161068: jal         0x800DDE50
    // 0x8016106C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    mpCommonCheckFighterOnEdge(rdram, ctx);
        goto after_0;
    // 0x8016106C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80161070: bne         $v0, $zero, L_801610F4
    if (ctx->r2 != 0) {
        // 0x80161074: lw          $a1, 0x1C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X1C);
            goto L_801610F4;
    }
    // 0x80161074: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80161078: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8016107C: b           L_801610F4
    // 0x80161080: sw          $t7, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->r15;
        goto L_801610F4;
    // 0x80161080: sw          $t7, 0x14C($a1)
    MEM_W(0X14C, ctx->r5) = ctx->r15;
    // 0x80161084: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
L_80161088:
    // 0x80161088: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8016108C: jal         0x800DE87C
    // 0x80161090: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    mpCommonCheckFighterCeilHeavyCliff(rdram, ctx);
        goto after_1;
    // 0x80161090: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x80161094: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80161098: beq         $v0, $zero, L_801610F4
    if (ctx->r2 == 0) {
        // 0x8016109C: lw          $a2, 0x20($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X20);
            goto L_801610F4;
    }
    // 0x8016109C: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x801610A0: lhu         $v0, 0xD2($a1)
    ctx->r2 = MEM_HU(ctx->r5, 0XD2);
    // 0x801610A4: andi        $t8, $v0, 0x3000
    ctx->r24 = ctx->r2 & 0X3000;
    // 0x801610A8: beq         $t8, $zero, L_801610C0
    if (ctx->r24 == 0) {
        // 0x801610AC: andi        $t9, $v0, 0x800
        ctx->r25 = ctx->r2 & 0X800;
            goto L_801610C0;
    }
    // 0x801610AC: andi        $t9, $v0, 0x800
    ctx->r25 = ctx->r2 & 0X800;
    // 0x801610B0: jal         0x80144C24
    // 0x801610B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    ftCommonCliffCatchSetStatus(rdram, ctx);
        goto after_2;
    // 0x801610B4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_2:
    // 0x801610B8: b           L_801610F8
    // 0x801610BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_801610F8;
    // 0x801610BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801610C0:
    // 0x801610C0: beql        $t9, $zero, L_801610F8
    if (ctx->r25 == 0) {
        // 0x801610C4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801610F8;
    }
    goto skip_1;
    // 0x801610C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x801610C8: lwc1        $f4, 0x4C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X4C);
    // 0x801610CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x801610D0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x801610D4: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x801610D8: nop

    // 0x801610DC: bc1fl       L_801610F8
    if (!c1cs) {
        // 0x801610E0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_801610F8;
    }
    goto skip_2;
    // 0x801610E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_2:
    // 0x801610E4: jal         0x800DEE98
    // 0x801610E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    mpCommonSetFighterGround(rdram, ctx);
        goto after_3;
    // 0x801610E8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x801610EC: jal         0x80161210
    // 0x801610F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    ftKirbySpecialHiLandingSetStatus(rdram, ctx);
        goto after_4;
    // 0x801610F0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    after_4:
L_801610F4:
    // 0x801610F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_801610F8:
    // 0x801610F8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x801610FC: jr          $ra
    // 0x80161100: nop

    return;
    // 0x80161100: nop

;}
RECOMP_FUNC void syAudioSetBGMVolumeFade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80020BC0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80020BC4: sltiu       $at, $a1, 0x7801
    ctx->r1 = ctx->r5 < 0X7801 ? 1 : 0;
    // 0x80020BC8: bne         $at, $zero, L_80020BD4
    if (ctx->r1 != 0) {
        // 0x80020BCC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80020BD4;
    }
    // 0x80020BCC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80020BD0: addiu       $a1, $zero, 0x7800
    ctx->r5 = ADD32(0, 0X7800);
L_80020BD4:
    // 0x80020BD4: beq         $a2, $zero, L_80020C44
    if (ctx->r6 == 0) {
        // 0x80020BD8: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_80020C44;
    }
    // 0x80020BD8: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
    // 0x80020BDC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80020BE0: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80020BE4: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020BE8: sw          $a2, -0x2688($at)
    MEM_W(-0X2688, ctx->r1) = ctx->r6;
    // 0x80020BEC: bgez        $a1, L_80020C04
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80020BF0: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80020C04;
    }
    // 0x80020BF0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80020BF4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80020BF8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80020BFC: nop

    // 0x80020C00: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80020C04:
    // 0x80020C04: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80020C08: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020C0C: lwc1        $f10, -0x2684($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X2684);
    // 0x80020C10: mtc1        $a2, $f18
    ctx->f18.u32l = ctx->r6;
    // 0x80020C14: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80020C18: sub.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80020C1C: bgez        $a2, L_80020C30
    if (SIGNED(ctx->r6) >= 0) {
        // 0x80020C20: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80020C30;
    }
    // 0x80020C20: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80020C24: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80020C28: nop

    // 0x80020C2C: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_80020C30:
    // 0x80020C30: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80020C34: lui         $at, 0x800A
    ctx->r1 = S32(0X800A << 16);
    // 0x80020C38: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80020C3C: b           L_80020C4C
    // 0x80020C40: swc1        $f6, -0x2680($at)
    MEM_W(-0X2680, ctx->r1) = ctx->f6.u32l;
        goto L_80020C4C;
    // 0x80020C40: swc1        $f6, -0x2680($at)
    MEM_W(-0X2680, ctx->r1) = ctx->f6.u32l;
L_80020C44:
    // 0x80020C44: jal         0x80020B38
    // 0x80020C48: nop

    syAudioSetBGMVolume(rdram, ctx);
        goto after_0;
    // 0x80020C48: nop

    after_0:
L_80020C4C:
    // 0x80020C4C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80020C50: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80020C54: jr          $ra
    // 0x80020C58: nop

    return;
    // 0x80020C58: nop

;}
RECOMP_FUNC void wpSamusChargeShotLaunch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80168B00: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80168B04: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80168B08: lw          $v0, 0x84($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X84);
    // 0x80168B0C: lui         $t8, 0x8019
    ctx->r24 = S32(0X8019 << 16);
    // 0x80168B10: addiu       $t8, $t8, -0x70F0
    ctx->r24 = ADD32(ctx->r24, -0X70F0);
    // 0x80168B14: lw          $t9, 0x18($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X18);
    // 0x80168B18: lw          $t6, 0x2A4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X2A4);
    // 0x80168B1C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80168B20: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x80168B24: sll         $t7, $t6, 3
    ctx->r15 = S32(ctx->r14 << 3);
    // 0x80168B28: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80168B2C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80168B30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80168B34: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x80168B38: lwc1        $f4, 0x4($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80168B3C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80168B40: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80168B44: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x80168B48: lw          $t0, 0x8($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X8);
    // 0x80168B4C: sw          $t0, 0x104($v0)
    MEM_W(0X104, ctx->r2) = ctx->r8;
    // 0x80168B50: lw          $t1, 0xC($v1)
    ctx->r9 = MEM_W(ctx->r3, 0XC);
    // 0x80168B54: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x80168B58: nop

    // 0x80168B5C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80168B60: mul.s       $f6, $f18, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80168B64: swc1        $f6, 0x128($v0)
    MEM_W(0X128, ctx->r2) = ctx->f6.u32l;
    // 0x80168B68: lw          $t2, 0x10($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X10);
    // 0x80168B6C: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80168B70: nop

    // 0x80168B74: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80168B78: mul.s       $f0, $f8, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80168B7C: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80168B80: swc1        $f0, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->f0.u32l;
    // 0x80168B84: swc1        $f0, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->f0.u32l;
    // 0x80168B88: swc1        $f10, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f10.u32l;
    // 0x80168B8C: lhu         $a0, 0x16($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X16);
    // 0x80168B90: jal         0x800269C0
    // 0x80168B94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    func_800269C0_275C0(rdram, ctx);
        goto after_0;
    // 0x80168B94: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_0:
    // 0x80168B98: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x80168B9C: lui         $t5, 0x8019
    ctx->r13 = S32(0X8019 << 16);
    // 0x80168BA0: addiu       $t5, $t5, -0x70F0
    ctx->r13 = ADD32(ctx->r13, -0X70F0);
    // 0x80168BA4: lw          $t3, 0x2A4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X2A4);
    // 0x80168BA8: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x80168BAC: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x80168BB0: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80168BB4: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
    // 0x80168BB8: lw          $t6, 0x1C($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X1C);
    // 0x80168BBC: sh          $t6, 0x146($v0)
    MEM_H(0X146, ctx->r2) = ctx->r14;
    // 0x80168BC0: lw          $t7, 0x20($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X20);
    // 0x80168BC4: sw          $zero, 0x2A8($v0)
    MEM_W(0X2A8, ctx->r2) = 0;
    // 0x80168BC8: sw          $t7, 0x140($v0)
    MEM_W(0X140, ctx->r2) = ctx->r15;
    // 0x80168BCC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80168BD0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80168BD4: jr          $ra
    // 0x80168BD8: nop

    return;
    // 0x80168BD8: nop

;}
RECOMP_FUNC void mnVSResultsMakeEmblem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80132B20: addiu       $sp, $sp, -0xE0
    ctx->r29 = ADD32(ctx->r29, -0XE0);
    // 0x80132B24: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132B28: addiu       $t7, $t7, -0x701C
    ctx->r15 = ADD32(ctx->r15, -0X701C);
    // 0x80132B2C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80132B30: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80132B34: addiu       $t0, $t7, 0x30
    ctx->r8 = ADD32(ctx->r15, 0X30);
    // 0x80132B38: addiu       $t6, $sp, 0xA0
    ctx->r14 = ADD32(ctx->r29, 0XA0);
L_80132B3C:
    // 0x80132B3C: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x80132B40: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132B44: addiu       $t6, $t6, 0xC
    ctx->r14 = ADD32(ctx->r14, 0XC);
    // 0x80132B48: sw          $t9, -0xC($t6)
    MEM_W(-0XC, ctx->r14) = ctx->r25;
    // 0x80132B4C: lw          $t8, -0x8($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X8);
    // 0x80132B50: sw          $t8, -0x8($t6)
    MEM_W(-0X8, ctx->r14) = ctx->r24;
    // 0x80132B54: lw          $t9, -0x4($t7)
    ctx->r25 = MEM_W(ctx->r15, -0X4);
    // 0x80132B58: bne         $t7, $t0, L_80132B3C
    if (ctx->r15 != ctx->r8) {
        // 0x80132B5C: sw          $t9, -0x4($t6)
        MEM_W(-0X4, ctx->r14) = ctx->r25;
            goto L_80132B3C;
    }
    // 0x80132B5C: sw          $t9, -0x4($t6)
    MEM_W(-0X4, ctx->r14) = ctx->r25;
    // 0x80132B60: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132B64: addiu       $t2, $t2, -0x6FEC
    ctx->r10 = ADD32(ctx->r10, -0X6FEC);
    // 0x80132B68: addiu       $t5, $t2, 0x30
    ctx->r13 = ADD32(ctx->r10, 0X30);
    // 0x80132B6C: addiu       $t1, $sp, 0x70
    ctx->r9 = ADD32(ctx->r29, 0X70);
L_80132B70:
    // 0x80132B70: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x80132B74: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x80132B78: addiu       $t1, $t1, 0xC
    ctx->r9 = ADD32(ctx->r9, 0XC);
    // 0x80132B7C: sw          $t4, -0xC($t1)
    MEM_W(-0XC, ctx->r9) = ctx->r12;
    // 0x80132B80: lw          $t3, -0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, -0X8);
    // 0x80132B84: sw          $t3, -0x8($t1)
    MEM_W(-0X8, ctx->r9) = ctx->r11;
    // 0x80132B88: lw          $t4, -0x4($t2)
    ctx->r12 = MEM_W(ctx->r10, -0X4);
    // 0x80132B8C: bne         $t2, $t5, L_80132B70
    if (ctx->r10 != ctx->r13) {
        // 0x80132B90: sw          $t4, -0x4($t1)
        MEM_W(-0X4, ctx->r9) = ctx->r12;
            goto L_80132B70;
    }
    // 0x80132B90: sw          $t4, -0x4($t1)
    MEM_W(-0X4, ctx->r9) = ctx->r12;
    // 0x80132B94: lui         $t7, 0x8014
    ctx->r15 = S32(0X8014 << 16);
    // 0x80132B98: addiu       $t7, $t7, -0x6FBC
    ctx->r15 = ADD32(ctx->r15, -0X6FBC);
    // 0x80132B9C: addiu       $t9, $t7, 0x30
    ctx->r25 = ADD32(ctx->r15, 0X30);
    // 0x80132BA0: addiu       $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
L_80132BA4:
    // 0x80132BA4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80132BA8: addiu       $t7, $t7, 0xC
    ctx->r15 = ADD32(ctx->r15, 0XC);
    // 0x80132BAC: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x80132BB0: sw          $t8, -0xC($t0)
    MEM_W(-0XC, ctx->r8) = ctx->r24;
    // 0x80132BB4: lw          $t6, -0x8($t7)
    ctx->r14 = MEM_W(ctx->r15, -0X8);
    // 0x80132BB8: sw          $t6, -0x8($t0)
    MEM_W(-0X8, ctx->r8) = ctx->r14;
    // 0x80132BBC: lw          $t8, -0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, -0X4);
    // 0x80132BC0: bne         $t7, $t9, L_80132BA4
    if (ctx->r15 != ctx->r25) {
        // 0x80132BC4: sw          $t8, -0x4($t0)
        MEM_W(-0X4, ctx->r8) = ctx->r24;
            goto L_80132BA4;
    }
    // 0x80132BC4: sw          $t8, -0x4($t0)
    MEM_W(-0X4, ctx->r8) = ctx->r24;
    // 0x80132BC8: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132BCC: addiu       $t2, $t2, -0x6F8C
    ctx->r10 = ADD32(ctx->r10, -0X6F8C);
    // 0x80132BD0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80132BD4: addiu       $t5, $sp, 0x34
    ctx->r13 = ADD32(ctx->r29, 0X34);
    // 0x80132BD8: lw          $t1, 0x4($t2)
    ctx->r9 = MEM_W(ctx->r10, 0X4);
    // 0x80132BDC: sw          $t3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r11;
    // 0x80132BE0: lw          $t3, 0x8($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X8);
    // 0x80132BE4: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80132BE8: sw          $t1, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r9;
    // 0x80132BEC: sw          $t3, 0x8($t5)
    MEM_W(0X8, ctx->r13) = ctx->r11;
    // 0x80132BF0: lbu         $v1, -0x63EC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X63EC);
    // 0x80132BF4: bnel        $v1, $zero, L_80132C24
    if (ctx->r3 != 0) {
        // 0x80132BF8: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80132C24;
    }
    goto skip_0;
    // 0x80132BF8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    skip_0:
    // 0x80132BFC: jal         0x8013234C
    // 0x80132C00: nop

    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_0;
    // 0x80132C00: nop

    after_0:
    // 0x80132C04: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132C08: jal         0x80133148
    // 0x80132C0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_1;
    // 0x80132C0C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80132C10: lui         $v1, 0x8014
    ctx->r3 = S32(0X8014 << 16);
    // 0x80132C14: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    // 0x80132C18: lbu         $v1, -0x63EC($v1)
    ctx->r3 = MEM_BU(ctx->r3, -0X63EC);
    // 0x80132C1C: sw          $s0, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r16;
    // 0x80132C20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80132C24:
    // 0x80132C24: bnel        $v1, $at, L_80132C58
    if (ctx->r3 != ctx->r1) {
        // 0x80132C28: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80132C58;
    }
    goto skip_1;
    // 0x80132C28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    skip_1:
    // 0x80132C2C: jal         0x8013234C
    // 0x80132C30: nop

    mnVSResultsGetWinPlayer(rdram, ctx);
        goto after_2;
    // 0x80132C30: nop

    after_2:
    // 0x80132C34: jal         0x80133148
    // 0x80132C38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mnVSResultsGetFighterKind(rdram, ctx);
        goto after_3;
    // 0x80132C38: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x80132C3C: jal         0x80132A2C
    // 0x80132C40: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    mnVSResultsGetWinTeam(rdram, ctx);
        goto after_4;
    // 0x80132C40: sw          $v0, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r2;
    after_4:
    // 0x80132C44: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80132C48: addu        $t9, $sp, $t4
    ctx->r25 = ADD32(ctx->r29, ctx->r12);
    // 0x80132C4C: lw          $t9, 0x34($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X34);
    // 0x80132C50: sw          $t9, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r25;
    // 0x80132C54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80132C58:
    // 0x80132C58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80132C5C: addiu       $a2, $zero, 0x17
    ctx->r6 = ADD32(0, 0X17);
    // 0x80132C60: jal         0x80009968
    // 0x80132C64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_5;
    // 0x80132C64: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_5:
    // 0x80132C68: lw          $v1, 0xD4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD4);
    // 0x80132C6C: lui         $t0, 0x8014
    ctx->r8 = S32(0X8014 << 16);
    // 0x80132C70: lw          $t0, -0x5FA8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5FA8);
    // 0x80132C74: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x80132C78: addu        $t7, $sp, $v1
    ctx->r15 = ADD32(ctx->r29, ctx->r3);
    // 0x80132C7C: lw          $t7, 0xA0($t7)
    ctx->r15 = MEM_W(ctx->r15, 0XA0);
    // 0x80132C80: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80132C84: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80132C88: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80132C8C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80132C90: jal         0x8000F120
    // 0x80132C94: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    gcSetupCommonDObjs(rdram, ctx);
        goto after_6;
    // 0x80132C94: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    after_6:
    // 0x80132C98: lui         $a1, 0x8001
    ctx->r5 = S32(0X8001 << 16);
    // 0x80132C9C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x80132CA0: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80132CA4: addiu       $a1, $a1, 0x4038
    ctx->r5 = ADD32(ctx->r5, 0X4038);
    // 0x80132CA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132CAC: addiu       $a2, $zero, 0x21
    ctx->r6 = ADD32(0, 0X21);
    // 0x80132CB0: jal         0x80009DF4
    // 0x80132CB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcAddGObjDisplay(rdram, ctx);
        goto after_7;
    // 0x80132CB4: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_7:
    // 0x80132CB8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80132CBC: lui         $t2, 0x8014
    ctx->r10 = S32(0X8014 << 16);
    // 0x80132CC0: lw          $t2, -0x5FA8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5FA8);
    // 0x80132CC4: addu        $t5, $sp, $t8
    ctx->r13 = ADD32(ctx->r29, ctx->r24);
    // 0x80132CC8: lw          $t5, 0x70($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X70);
    // 0x80132CCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132CD0: jal         0x8000F8F4
    // 0x80132CD4: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    gcAddMObjAll(rdram, ctx);
        goto after_8;
    // 0x80132CD4: addu        $a1, $t5, $t2
    ctx->r5 = ADD32(ctx->r13, ctx->r10);
    after_8:
    // 0x80132CD8: lw          $t9, 0xD0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD0);
    // 0x80132CDC: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x80132CE0: lui         $t4, 0x8014
    ctx->r12 = S32(0X8014 << 16);
    // 0x80132CE4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80132CE8: addu        $t3, $sp, $t1
    ctx->r11 = ADD32(ctx->r29, ctx->r9);
    // 0x80132CEC: lw          $t3, 0x40($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X40);
    // 0x80132CF0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80132CF4: lw          $t4, -0x5FA8($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5FA8);
    // 0x80132CF8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132CFC: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x80132D00: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80132D04: jal         0x8000BE28
    // 0x80132D08: nop

    gcAddMatAnimJointAll(rdram, ctx);
        goto after_9;
    // 0x80132D08: nop

    after_9:
    // 0x80132D0C: jal         0x8000DF34
    // 0x80132D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gcPlayAnimAll(rdram, ctx);
        goto after_10;
    // 0x80132D10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80132D14: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80132D18: addiu       $a1, $a1, 0x2A68
    ctx->r5 = ADD32(ctx->r5, 0X2A68);
    // 0x80132D1C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80132D20: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x80132D24: jal         0x80008188
    // 0x80132D28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_11;
    // 0x80132D28: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_11:
    // 0x80132D2C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80132D30: lw          $t7, 0x74($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X74);
    // 0x80132D34: lui         $at, 0x41C8
    ctx->r1 = S32(0X41C8 << 16);
    // 0x80132D38: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80132D3C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80132D40: swc1        $f6, 0x1C($t7)
    MEM_W(0X1C, ctx->r15) = ctx->f6.u32l;
    // 0x80132D44: lw          $t0, 0x74($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X74);
    // 0x80132D48: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80132D4C: lui         $at, 0x8014
    ctx->r1 = S32(0X8014 << 16);
    // 0x80132D50: swc1        $f8, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f8.u32l;
    // 0x80132D54: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80132D58: lwc1        $f10, -0x679C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X679C);
    // 0x80132D5C: swc1        $f10, 0x24($t6)
    MEM_W(0X24, ctx->r14) = ctx->f10.u32l;
    // 0x80132D60: lw          $t8, 0x74($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X74);
    // 0x80132D64: swc1        $f0, 0x40($t8)
    MEM_W(0X40, ctx->r24) = ctx->f0.u32l;
    // 0x80132D68: lw          $t5, 0x74($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X74);
    // 0x80132D6C: swc1        $f0, 0x44($t5)
    MEM_W(0X44, ctx->r13) = ctx->f0.u32l;
    // 0x80132D70: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80132D74: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80132D78: addiu       $sp, $sp, 0xE0
    ctx->r29 = ADD32(ctx->r29, 0XE0);
    // 0x80132D7C: jr          $ra
    // 0x80132D80: nop

    return;
    // 0x80132D80: nop

;}
RECOMP_FUNC void func_ovl8_80383450(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80383450: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80383454: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80383458: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8038345C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80383460: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x80383464: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80383468: bne         $a0, $zero, L_80383480
    if (ctx->r4 != 0) {
        // 0x8038346C: sw          $a3, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r7;
            goto L_80383480;
    }
    // 0x8038346C: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80383470: jal         0x803717A0
    // 0x80383474: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    func_ovl8_803717A0(rdram, ctx);
        goto after_0;
    // 0x80383474: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    after_0:
    // 0x80383478: beq         $v0, $zero, L_803834FC
    if (ctx->r2 == 0) {
        // 0x8038347C: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_803834FC;
    }
    // 0x8038347C: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_80383480:
    // 0x80383480: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x80383484: addiu       $a0, $s0, 0x58
    ctx->r4 = ADD32(ctx->r16, 0X58);
    // 0x80383488: addiu       $a1, $s0, 0xB4
    ctx->r5 = ADD32(ctx->r16, 0XB4);
    // 0x8038348C: bnel        $t6, $zero, L_803834B0
    if (ctx->r14 != 0) {
        // 0x80383490: lw          $t7, 0x40($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X40);
            goto L_803834B0;
    }
    goto skip_0;
    // 0x80383490: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    skip_0:
    // 0x80383494: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80383498: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x8038349C: jal         0x803717E0
    // 0x803834A0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    func_ovl8_803717E0(rdram, ctx);
        goto after_1;
    // 0x803834A0: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_1:
    // 0x803834A4: jal         0x8037C2D0
    // 0x803834A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    func_ovl8_8037C2D0(rdram, ctx);
        goto after_2;
    // 0x803834A8: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    after_2:
    // 0x803834AC: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
L_803834B0:
    // 0x803834B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803834B4: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x803834B8: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x803834BC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x803834C0: jal         0x8037345C
    // 0x803834C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    func_ovl8_8037345C(rdram, ctx);
        goto after_3;
    // 0x803834C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_3:
    // 0x803834C8: lui         $t8, 0x8039
    ctx->r24 = S32(0X8039 << 16);
    // 0x803834CC: addiu       $t8, $t8, -0x35F0
    ctx->r24 = ADD32(ctx->r24, -0X35F0);
    // 0x803834D0: sw          $t8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->r24;
    // 0x803834D4: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x803834D8: lui         $t9, 0x8039
    ctx->r25 = S32(0X8039 << 16);
    // 0x803834DC: addiu       $t9, $t9, -0x34A8
    ctx->r25 = ADD32(ctx->r25, -0X34A8);
    // 0x803834E0: sw          $t9, 0x58($t0)
    MEM_W(0X58, ctx->r8) = ctx->r25;
    // 0x803834E4: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x803834E8: lui         $t1, 0x8039
    ctx->r9 = S32(0X8039 << 16);
    // 0x803834EC: addiu       $t1, $t1, -0x3350
    ctx->r9 = ADD32(ctx->r9, -0X3350);
    // 0x803834F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x803834F4: jal         0x80383B58
    // 0x803834F8: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    func_ovl8_80383B58(rdram, ctx);
        goto after_4;
    // 0x803834F8: sw          $t1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r9;
    after_4:
L_803834FC:
    // 0x803834FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80383500: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x80383504: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80383508: jr          $ra
    // 0x8038350C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8038350C: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void ftCommonGuardOnProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80148A88: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80148A8C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80148A90: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80148A94: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80148A98: lw          $s0, 0x84($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X84);
    // 0x80148A9C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80148AA0: jal         0x80148120
    // 0x80148AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    ftCommonGuardCheckScheduleRelease(rdram, ctx);
        goto after_0;
    // 0x80148AA4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x80148AA8: jal         0x80148304
    // 0x80148AAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardUpdateShieldVars(rdram, ctx);
        goto after_1;
    // 0x80148AAC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x80148AB0: lw          $t6, 0x34($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X34);
    // 0x80148AB4: bnel        $t6, $zero, L_80148AD0
    if (ctx->r14 != 0) {
        // 0x80148AB8: mtc1        $zero, $f4
        ctx->f4.u32l = 0;
            goto L_80148AD0;
    }
    goto skip_0;
    // 0x80148AB8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    skip_0:
    // 0x80148ABC: jal         0x80149510
    // 0x80148AC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonShieldBreakFlyCommonSetStatus(rdram, ctx);
        goto after_2;
    // 0x80148AC0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80148AC4: b           L_80148B74
    // 0x80148AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80148B74;
    // 0x80148AC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80148ACC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_80148AD0:
    // 0x80148AD0: lwc1        $f6, 0x78($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X78);
    // 0x80148AD4: c.le.s      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.fl <= ctx->f4.fl;
    // 0x80148AD8: nop

    // 0x80148ADC: bc1f        L_80148B68
    if (!c1cs) {
        // 0x80148AE0: nop
    
            goto L_80148B68;
    }
    // 0x80148AE0: nop

    // 0x80148AE4: lw          $t7, 0xB24($s0)
    ctx->r15 = MEM_W(ctx->r16, 0XB24);
    // 0x80148AE8: beql        $t7, $zero, L_80148B1C
    if (ctx->r15 == 0) {
        // 0x80148AEC: lw          $t9, 0x8($s0)
        ctx->r25 = MEM_W(ctx->r16, 0X8);
            goto L_80148B1C;
    }
    goto skip_1;
    // 0x80148AEC: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
    skip_1:
    // 0x80148AF0: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x80148AF4: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80148AF8: bne         $t8, $at, L_80148B08
    if (ctx->r24 != ctx->r1) {
        // 0x80148AFC: nop
    
            goto L_80148B08;
    }
    // 0x80148AFC: nop

    // 0x80148B00: jal         0x801482E4
    // 0x80148B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardOffSetHitStatusYoshi(rdram, ctx);
        goto after_3;
    // 0x80148B04: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
L_80148B08:
    // 0x80148B08: jal         0x80148FF0
    // 0x80148B0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardOffSetStatus(rdram, ctx);
        goto after_4;
    // 0x80148B0C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
    // 0x80148B10: b           L_80148B74
    // 0x80148B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80148B74;
    // 0x80148B14: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80148B18: lw          $t9, 0x8($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X8);
L_80148B1C:
    // 0x80148B1C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80148B20: bne         $t9, $at, L_80148B58
    if (ctx->r25 != ctx->r1) {
        // 0x80148B24: nop
    
            goto L_80148B58;
    }
    // 0x80148B24: nop

    // 0x80148B28: jal         0x80101374
    // 0x80148B2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    efManagerYoshiShieldMakeEffect(rdram, ctx);
        goto after_5;
    // 0x80148B2C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x80148B30: sw          $v0, 0xB20($s0)
    MEM_W(0XB20, ctx->r16) = ctx->r2;
    // 0x80148B34: jal         0x800E90F8
    // 0x80148B38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftParamHideModelPartAll(rdram, ctx);
        goto after_6;
    // 0x80148B38: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_6:
    // 0x80148B3C: jal         0x80148214
    // 0x80148B40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardSetHitStatusYoshi(rdram, ctx);
        goto after_7;
    // 0x80148B40: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x80148B44: lbu         $t1, 0x18F($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X18F);
    // 0x80148B48: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x80148B4C: ori         $t2, $t1, 0x20
    ctx->r10 = ctx->r9 | 0X20;
    // 0x80148B50: jal         0x80148714
    // 0x80148B54: sb          $t2, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r10;
    ftCommonGuardUpdateJoints(rdram, ctx);
        goto after_8;
    // 0x80148B54: sb          $t2, 0x18F($s0)
    MEM_B(0X18F, ctx->r16) = ctx->r10;
    after_8:
L_80148B58:
    // 0x80148B58: jal         0x80148DDC
    // 0x80148B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardSetStatus(rdram, ctx);
        goto after_9;
    // 0x80148B5C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x80148B60: b           L_80148B74
    // 0x80148B64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80148B74;
    // 0x80148B64: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80148B68:
    // 0x80148B68: jal         0x80148714
    // 0x80148B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    ftCommonGuardUpdateJoints(rdram, ctx);
        goto after_10;
    // 0x80148B6C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x80148B70: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80148B74:
    // 0x80148B74: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80148B78: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80148B7C: jr          $ra
    // 0x80148B80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80148B80: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80014CD0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80014CD0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80014CD4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80014CD8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80014CDC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80014CE0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80014CE4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80014CE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80014CEC: lbu         $t6, 0x54($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X54);
    // 0x80014CF0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80014CF4: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80014CF8: andi        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 & 0X2;
    // 0x80014CFC: bne         $t7, $zero, L_80014FB0
    if (ctx->r15 != 0) {
        // 0x80014D00: lui         $at, 0x8004
        ctx->r1 = S32(0X8004 << 16);
            goto L_80014FB0;
    }
    // 0x80014D00: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014D04: lwc1        $f4, 0x6FA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6FA4);
    // 0x80014D08: lui         $s2, 0x8004
    ctx->r18 = S32(0X8004 << 16);
    // 0x80014D0C: addiu       $s2, $s2, 0x70B0
    ctx->r18 = ADD32(ctx->r18, 0X70B0);
    // 0x80014D10: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x80014D14: lw          $s0, 0x50($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X50);
    // 0x80014D18: lui         $t8, 0x8004
    ctx->r24 = S32(0X8004 << 16);
    // 0x80014D1C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80014D20: beql        $s0, $zero, L_80014D40
    if (ctx->r16 == 0) {
        // 0x80014D24: lw          $t6, 0x0($s2)
        ctx->r14 = MEM_W(ctx->r18, 0X0);
            goto L_80014D40;
    }
    goto skip_0;
    // 0x80014D24: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    skip_0:
    // 0x80014D28: lw          $t8, 0x72A8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X72A8);
    // 0x80014D2C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80014D30: addu        $t5, $s0, $t9
    ctx->r13 = ADD32(ctx->r16, ctx->r25);
    // 0x80014D34: lw          $a2, 0x0($t5)
    ctx->r6 = MEM_W(ctx->r13, 0X0);
    // 0x80014D38: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80014D3C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
L_80014D40:
    // 0x80014D40: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80014D44: jal         0x80010D70
    // 0x80014D48: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    gcPrepDObjMatrix(rdram, ctx);
        goto after_0;
    // 0x80014D48: sw          $t6, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r14;
    after_0:
    // 0x80014D4C: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80014D50: beq         $s0, $zero, L_80014EB4
    if (ctx->r16 == 0) {
        // 0x80014D54: or          $t3, $v0, $zero
        ctx->r11 = ctx->r2 | 0;
            goto L_80014EB4;
    }
    // 0x80014D54: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x80014D58: beql        $a2, $zero, L_80014EB8
    if (ctx->r6 == 0) {
        // 0x80014D5C: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_80014EB8;
    }
    goto skip_1;
    // 0x80014D5C: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_1:
    // 0x80014D60: lbu         $t7, 0x54($s3)
    ctx->r15 = MEM_BU(ctx->r19, 0X54);
    // 0x80014D64: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x80014D68: bnel        $t8, $zero, L_80014EB8
    if (ctx->r24 != 0) {
        // 0x80014D6C: lw          $a0, 0x10($s3)
        ctx->r4 = MEM_W(ctx->r19, 0X10);
            goto L_80014EB8;
    }
    goto skip_2;
    // 0x80014D6C: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
    skip_2:
    // 0x80014D70: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x80014D74: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80014D78: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80014D7C: beq         $v0, $at, L_80014EB4
    if (ctx->r2 == ctx->r1) {
        // 0x80014D80: addiu       $s1, $s1, 0x65B0
        ctx->r17 = ADD32(ctx->r17, 0X65B0);
            goto L_80014EB4;
    }
    // 0x80014D80: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80014D84: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80014D88: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x80014D8C: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
L_80014D90:
    // 0x80014D90: sll         $s0, $v0, 2
    ctx->r16 = S32(ctx->r2 << 2);
    // 0x80014D94: addu        $t5, $a3, $s0
    ctx->r13 = ADD32(ctx->r7, ctx->r16);
    // 0x80014D98: beql        $t9, $zero, L_80014EA4
    if (ctx->r25 == 0) {
        // 0x80014D9C: lw          $v0, 0x8($a2)
        ctx->r2 = MEM_W(ctx->r6, 0X8);
            goto L_80014EA4;
    }
    goto skip_3;
    // 0x80014D9C: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
    skip_3:
    // 0x80014DA0: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x80014DA4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80014DA8: beq         $t6, $a0, L_80014E10
    if (ctx->r14 == ctx->r4) {
        // 0x80014DAC: addu        $t7, $s1, $s0
        ctx->r15 = ADD32(ctx->r17, ctx->r16);
            goto L_80014E10;
    }
    // 0x80014DAC: addu        $t7, $s1, $s0
    ctx->r15 = ADD32(ctx->r17, ctx->r16);
L_80014DB0:
    // 0x80014DB0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80014DB4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80014DB8: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x80014DBC: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x80014DC0: sw          $t9, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r25;
    // 0x80014DC4: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80014DC8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80014DCC: addu        $v1, $s1, $t7
    ctx->r3 = ADD32(ctx->r17, ctx->r15);
    // 0x80014DD0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80014DD4: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80014DD8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80014DDC: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x80014DE0: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80014DE4: addu        $v0, $a3, $t6
    ctx->r2 = ADD32(ctx->r7, ctx->r14);
    // 0x80014DE8: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x80014DEC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80014DF0: addiu       $t8, $t7, 0x8
    ctx->r24 = ADD32(ctx->r15, 0X8);
    // 0x80014DF4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80014DF8: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80014DFC: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
    // 0x80014E00: addu        $t9, $a3, $s0
    ctx->r25 = ADD32(ctx->r7, ctx->r16);
    // 0x80014E04: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x80014E08: bnel        $t5, $a0, L_80014DB0
    if (ctx->r13 != ctx->r4) {
        // 0x80014E0C: addu        $t7, $s1, $s0
        ctx->r15 = ADD32(ctx->r17, ctx->r16);
            goto L_80014DB0;
    }
    goto skip_4;
    // 0x80014E0C: addu        $t7, $s1, $s0
    ctx->r15 = ADD32(ctx->r17, ctx->r16);
    skip_4:
L_80014E10:
    // 0x80014E10: lw          $t6, 0x80($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X80);
    // 0x80014E14: beql        $t6, $zero, L_80014E84
    if (ctx->r14 == 0) {
        // 0x80014E18: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_80014E84;
    }
    goto skip_5;
    // 0x80014E18: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    skip_5:
    // 0x80014E1C: bne         $s4, $zero, L_80014E5C
    if (ctx->r20 != 0) {
        // 0x80014E20: addu        $v1, $s1, $s0
        ctx->r3 = ADD32(ctx->r17, ctx->r16);
            goto L_80014E5C;
    }
    // 0x80014E20: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
    // 0x80014E24: lui         $s4, 0x8004
    ctx->r20 = S32(0X8004 << 16);
    // 0x80014E28: lw          $s4, 0x65E4($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X65E4);
    // 0x80014E2C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80014E30: addu        $a1, $s1, $s0
    ctx->r5 = ADD32(ctx->r17, ctx->r16);
    // 0x80014E34: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80014E38: jal         0x80012D90
    // 0x80014E3C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    gcDrawMObjForDObj(rdram, ctx);
        goto after_1;
    // 0x80014E3C: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_1:
    // 0x80014E40: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80014E44: lui         $a3, 0x8004
    ctx->r7 = S32(0X8004 << 16);
    // 0x80014E48: addiu       $a3, $a3, 0x70B8
    ctx->r7 = ADD32(ctx->r7, 0X70B8);
    // 0x80014E4C: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80014E50: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80014E54: b           L_80014E80
    // 0x80014E58: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
        goto L_80014E80;
    // 0x80014E58: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_80014E5C:
    // 0x80014E5C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80014E60: lui         $t8, 0xDB06
    ctx->r24 = S32(0XDB06 << 16);
    // 0x80014E64: ori         $t8, $t8, 0x38
    ctx->r24 = ctx->r24 | 0X38;
    // 0x80014E68: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80014E6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80014E70: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x80014E74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80014E78: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x80014E7C: sll         $s0, $s0, 2
    ctx->r16 = S32(ctx->r16 << 2);
L_80014E80:
    // 0x80014E80: addu        $v1, $s1, $s0
    ctx->r3 = ADD32(ctx->r17, ctx->r16);
L_80014E84:
    // 0x80014E84: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80014E88: lui         $t5, 0xDE00
    ctx->r13 = S32(0XDE00 << 16);
    // 0x80014E8C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80014E90: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x80014E94: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80014E98: lw          $t6, 0x4($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X4);
    // 0x80014E9C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x80014EA0: lw          $v0, 0x8($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X8);
L_80014EA4:
    // 0x80014EA4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80014EA8: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x80014EAC: bnel        $v0, $at, L_80014D90
    if (ctx->r2 != ctx->r1) {
        // 0x80014EB0: lw          $t9, 0x4($a2)
        ctx->r25 = MEM_W(ctx->r6, 0X4);
            goto L_80014D90;
    }
    goto skip_6;
    // 0x80014EB0: lw          $t9, 0x4($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X4);
    skip_6:
L_80014EB4:
    // 0x80014EB4: lw          $a0, 0x10($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X10);
L_80014EB8:
    // 0x80014EB8: lui         $s1, 0x8004
    ctx->r17 = S32(0X8004 << 16);
    // 0x80014EBC: addiu       $s1, $s1, 0x65B0
    ctx->r17 = ADD32(ctx->r17, 0X65B0);
    // 0x80014EC0: beql        $a0, $zero, L_80014ED8
    if (ctx->r4 == 0) {
        // 0x80014EC4: lw          $t7, 0x3C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X3C);
            goto L_80014ED8;
    }
    goto skip_7;
    // 0x80014EC4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    skip_7:
    // 0x80014EC8: jal         0x80014CD0
    // 0x80014ECC: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    func_80014CD0(rdram, ctx);
        goto after_2;
    // 0x80014ECC: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_2:
    // 0x80014ED0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80014ED4: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
L_80014ED8:
    // 0x80014ED8: lui         $a2, 0x8004
    ctx->r6 = S32(0X8004 << 16);
    // 0x80014EDC: lui         $t4, 0x8004
    ctx->r12 = S32(0X8004 << 16);
    // 0x80014EE0: lui         $t1, 0xD838
    ctx->r9 = S32(0XD838 << 16);
    // 0x80014EE4: ori         $t1, $t1, 0x2
    ctx->r9 = ctx->r9 | 0X2;
    // 0x80014EE8: addiu       $t4, $t4, 0x70C8
    ctx->r12 = ADD32(ctx->r12, 0X70C8);
    // 0x80014EEC: addiu       $a2, $a2, 0x70B8
    ctx->r6 = ADD32(ctx->r6, 0X70B8);
    // 0x80014EF0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80014EF4: addiu       $t2, $zero, 0x40
    ctx->r10 = ADD32(0, 0X40);
    // 0x80014EF8: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80014EFC: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
L_80014F00:
    // 0x80014F00: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x80014F04: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80014F08: sltu        $at, $a1, $t8
    ctx->r1 = ctx->r5 < ctx->r24 ? 1 : 0;
    // 0x80014F0C: beql        $at, $zero, L_80014F54
    if (ctx->r1 == 0) {
        // 0x80014F10: lw          $t7, 0x4($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X4);
            goto L_80014F54;
    }
    goto skip_8;
    // 0x80014F10: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    skip_8:
    // 0x80014F14: beq         $t3, $zero, L_80014F50
    if (ctx->r11 == 0) {
        // 0x80014F18: sw          $a1, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r5;
            goto L_80014F50;
    }
    // 0x80014F18: sw          $a1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r5;
    // 0x80014F1C: lw          $t9, 0x14($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X14);
    // 0x80014F20: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x80014F24: beql        $t0, $t9, L_80014F3C
    if (ctx->r8 == ctx->r25) {
        // 0x80014F28: lw          $a0, 0x0($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X0);
            goto L_80014F3C;
    }
    goto skip_9;
    // 0x80014F28: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    skip_9:
    // 0x80014F2C: lw          $t5, 0x8($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X8);
    // 0x80014F30: beql        $t5, $zero, L_80014F54
    if (ctx->r13 == 0) {
        // 0x80014F34: lw          $t7, 0x4($a2)
        ctx->r15 = MEM_W(ctx->r6, 0X4);
            goto L_80014F54;
    }
    goto skip_10;
    // 0x80014F34: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
    skip_10:
    // 0x80014F38: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
L_80014F3C:
    // 0x80014F3C: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80014F40: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80014F44: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80014F48: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
    // 0x80014F4C: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
L_80014F50:
    // 0x80014F50: lw          $t7, 0x4($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4);
L_80014F54:
    // 0x80014F54: sltu        $at, $a1, $t7
    ctx->r1 = ctx->r5 < ctx->r15 ? 1 : 0;
    // 0x80014F58: beql        $at, $zero, L_80014F9C
    if (ctx->r1 == 0) {
        // 0x80014F5C: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80014F9C;
    }
    goto skip_11;
    // 0x80014F5C: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_11:
    // 0x80014F60: beq         $t3, $zero, L_80014F98
    if (ctx->r11 == 0) {
        // 0x80014F64: sw          $a1, 0x4($a2)
        MEM_W(0X4, ctx->r6) = ctx->r5;
            goto L_80014F98;
    }
    // 0x80014F64: sw          $a1, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r5;
    // 0x80014F68: lw          $t8, 0x14($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X14);
    // 0x80014F6C: addu        $v1, $s1, $a3
    ctx->r3 = ADD32(ctx->r17, ctx->r7);
    // 0x80014F70: beql        $t0, $t8, L_80014F88
    if (ctx->r8 == ctx->r24) {
        // 0x80014F74: lw          $a0, 0x4($v1)
        ctx->r4 = MEM_W(ctx->r3, 0X4);
            goto L_80014F88;
    }
    goto skip_12;
    // 0x80014F74: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
    skip_12:
    // 0x80014F78: lw          $t9, 0x8($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X8);
    // 0x80014F7C: beql        $t9, $zero, L_80014F9C
    if (ctx->r25 == 0) {
        // 0x80014F80: addiu       $a2, $a2, 0x8
        ctx->r6 = ADD32(ctx->r6, 0X8);
            goto L_80014F9C;
    }
    goto skip_13;
    // 0x80014F80: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    skip_13:
    // 0x80014F84: lw          $a0, 0x4($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X4);
L_80014F88:
    // 0x80014F88: addiu       $t5, $a0, 0x8
    ctx->r13 = ADD32(ctx->r4, 0X8);
    // 0x80014F8C: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80014F90: sw          $t2, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r10;
    // 0x80014F94: sw          $t1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r9;
L_80014F98:
    // 0x80014F98: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
L_80014F9C:
    // 0x80014F9C: bne         $a2, $t4, L_80014F00
    if (ctx->r6 != ctx->r12) {
        // 0x80014FA0: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_80014F00;
    }
    // 0x80014FA0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x80014FA4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80014FA8: lui         $at, 0x8004
    ctx->r1 = S32(0X8004 << 16);
    // 0x80014FAC: swc1        $f6, 0x6FA4($at)
    MEM_W(0X6FA4, ctx->r1) = ctx->f6.u32l;
L_80014FB0:
    // 0x80014FB0: lw          $t6, 0xC($s3)
    ctx->r14 = MEM_W(ctx->r19, 0XC);
    // 0x80014FB4: bnel        $t6, $zero, L_80014FE0
    if (ctx->r14 != 0) {
        // 0x80014FB8: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80014FE0;
    }
    goto skip_14;
    // 0x80014FB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_14:
    // 0x80014FBC: lw          $s0, 0x8($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X8);
    // 0x80014FC0: beql        $s0, $zero, L_80014FE0
    if (ctx->r16 == 0) {
        // 0x80014FC4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80014FE0;
    }
    goto skip_15;
    // 0x80014FC4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    skip_15:
L_80014FC8:
    // 0x80014FC8: jal         0x80014CD0
    // 0x80014FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    func_80014CD0(rdram, ctx);
        goto after_3;
    // 0x80014FCC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80014FD0: lw          $s0, 0x8($s0)
    ctx->r16 = MEM_W(ctx->r16, 0X8);
    // 0x80014FD4: bne         $s0, $zero, L_80014FC8
    if (ctx->r16 != 0) {
        // 0x80014FD8: nop
    
            goto L_80014FC8;
    }
    // 0x80014FD8: nop

    // 0x80014FDC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80014FE0:
    // 0x80014FE0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80014FE4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80014FE8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80014FEC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80014FF0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80014FF4: jr          $ra
    // 0x80014FF8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80014FF8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void mnPlayersVSGetPuckDistance(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801392A8: addiu       $a3, $zero, 0xBC
    ctx->r7 = ADD32(0, 0XBC);
    // 0x801392AC: multu       $a1, $a3
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801392B0: lui         $a2, 0x8014
    ctx->r6 = S32(0X8014 << 16);
    // 0x801392B4: addiu       $a2, $a2, -0x4578
    ctx->r6 = ADD32(ctx->r6, -0X4578);
    // 0x801392B8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x801392BC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x801392C0: mflo        $t6
    ctx->r14 = lo;
    // 0x801392C4: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x801392C8: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x801392CC: multu       $a0, $a3
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x801392D0: lw          $v0, 0x74($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X74);
    // 0x801392D4: lwc1        $f4, 0x5C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x801392D8: lwc1        $f8, 0x58($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X58);
    // 0x801392DC: mflo        $t9
    ctx->r25 = lo;
    // 0x801392E0: addu        $t0, $a2, $t9
    ctx->r8 = ADD32(ctx->r6, ctx->r25);
    // 0x801392E4: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x801392E8: lw          $v1, 0x74($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X74);
    // 0x801392EC: lwc1        $f6, 0x5C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x801392F0: lwc1        $f10, 0x58($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X58);
    // 0x801392F4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x801392F8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x801392FC: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80139300: nop

    // 0x80139304: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80139308: jal         0x80033510
    // 0x8013930C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8013930C: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x80139310: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80139314: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80139318: jr          $ra
    // 0x8013931C: nop

    return;
    // 0x8013931C: nop

;}
RECOMP_FUNC void func_ovl31_80137938(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80137938: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8013793C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80137940: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80137944: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80137948: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x8013794C: jal         0x80009968
    // 0x80137950: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    gcMakeGObjSPAfter(rdram, ctx);
        goto after_0;
    // 0x80137950: lui         $a3, 0x8000
    ctx->r7 = S32(0X8000 << 16);
    after_0:
    // 0x80137954: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x80137958: addiu       $a1, $a1, 0x7898
    ctx->r5 = ADD32(ctx->r5, 0X7898);
    // 0x8013795C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80137960: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80137964: jal         0x80008188
    // 0x80137968: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    gcAddGObjProcess(rdram, ctx);
        goto after_1;
    // 0x80137968: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_1:
    // 0x8013796C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80137970: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80137974: jr          $ra
    // 0x80137978: nop

    return;
    // 0x80137978: nop

;}
RECOMP_FUNC void func_ovl28_801375D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x801375D0: jr          $ra
    // 0x801375D4: nop

    return;
    // 0x801375D4: nop

;}
RECOMP_FUNC void itStarRodFallProcUpdate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80177E80: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80177E84: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80177E88: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80177E8C: lui         $a1, 0x3F99
    ctx->r5 = S32(0X3F99 << 16);
    // 0x80177E90: lw          $a0, 0x84($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X84);
    // 0x80177E94: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x80177E98: jal         0x80172558
    // 0x80177E9C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    itMainApplyGravityClampTVel(rdram, ctx);
        goto after_0;
    // 0x80177E9C: lui         $a2, 0x42C8
    ctx->r6 = S32(0X42C8 << 16);
    after_0:
    // 0x80177EA0: jal         0x801713F4
    // 0x80177EA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    itVisualsUpdateSpin(rdram, ctx);
        goto after_1;
    // 0x80177EA4: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    after_1:
    // 0x80177EA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80177EAC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80177EB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80177EB4: jr          $ra
    // 0x80177EB8: nop

    return;
    // 0x80177EB8: nop

;}
RECOMP_FUNC void ftComputerSetFighterDamageDetectSize(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8013AC00: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8013AC04: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x8013AC08: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x8013AC0C: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x8013AC10: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8013AC14: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8013AC18: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8013AC1C: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8013AC20: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8013AC24: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8013AC28: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8013AC2C: sdc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    SD(ctx->f26.u64, 0X30, ctx->r29);
    // 0x8013AC30: sdc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    SD(ctx->f24.u64, 0X28, ctx->r29);
    // 0x8013AC34: sdc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    SD(ctx->f22.u64, 0X20, ctx->r29);
    // 0x8013AC38: sdc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    SD(ctx->f20.u64, 0X18, ctx->r29);
    // 0x8013AC3C: lw          $s6, 0x84($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X84);
    // 0x8013AC40: addiu       $s4, $sp, 0x90
    ctx->r20 = ADD32(ctx->r29, 0X90);
    // 0x8013AC44: addiu       $s5, $zero, 0x8
    ctx->r21 = ADD32(0, 0X8);
    // 0x8013AC48: sw          $s6, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r22;
    // 0x8013AC4C: lw          $v0, 0x8E8($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X8E8);
    // 0x8013AC50: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8013AC54: addiu       $fp, $zero, 0x1
    ctx->r30 = ADD32(0, 0X1);
    // 0x8013AC58: lwc1        $f20, 0x1C($v0)
    ctx->f20.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8013AC5C: lwc1        $f22, 0x20($v0)
    ctx->f22.u32l = MEM_W(ctx->r2, 0X20);
    // 0x8013AC60: mov.s       $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    ctx->f24.fl = ctx->f20.fl;
    // 0x8013AC64: mov.s       $f26, $f22
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 22);
    ctx->f26.fl = ctx->f22.fl;
L_8013AC68:
    // 0x8013AC68: lw          $t8, 0x5BC($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X5BC);
    // 0x8013AC6C: addiu       $s0, $s6, 0x5BC
    ctx->r16 = ADD32(ctx->r22, 0X5BC);
    // 0x8013AC70: bnel        $fp, $t8, L_8013AD94
    if (ctx->r30 != ctx->r24) {
        // 0x8013AC74: addiu       $s7, $s7, 0x2C
        ctx->r23 = ADD32(ctx->r23, 0X2C);
            goto L_8013AD94;
    }
    goto skip_0;
    // 0x8013AC74: addiu       $s7, $s7, 0x2C
    ctx->r23 = ADD32(ctx->r23, 0X2C);
    skip_0:
    // 0x8013AC78: lw          $a0, 0x8($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X8);
    // 0x8013AC7C: lw          $s3, 0x84($a0)
    ctx->r19 = MEM_W(ctx->r4, 0X84);
    // 0x8013AC80: lbu         $t9, 0x5($s3)
    ctx->r25 = MEM_BU(ctx->r19, 0X5);
    // 0x8013AC84: bnel        $t9, $zero, L_8013AC98
    if (ctx->r25 != 0) {
        // 0x8013AC88: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8013AC98;
    }
    goto skip_1;
    // 0x8013AC88: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    skip_1:
    // 0x8013AC8C: jal         0x800EDBA4
    // 0x8013AC90: nop

    func_ovl2_800EDBA4(rdram, ctx);
        goto after_0;
    // 0x8013AC90: nop

    after_0:
    // 0x8013AC94: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8013AC98:
    // 0x8013AC98: addiu       $s2, $s3, 0x50
    ctx->r18 = ADD32(ctx->r19, 0X50);
    // 0x8013AC9C: andi        $t0, $s1, 0x1
    ctx->r8 = ctx->r17 & 0X1;
L_8013ACA0:
    // 0x8013ACA0: beq         $t0, $zero, L_8013ACBC
    if (ctx->r8 == 0) {
        // 0x8013ACA4: andi        $t1, $s1, 0x2
        ctx->r9 = ctx->r17 & 0X2;
            goto L_8013ACBC;
    }
    // 0x8013ACA4: andi        $t1, $s1, 0x2
    ctx->r9 = ctx->r17 & 0X2;
    // 0x8013ACA8: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8013ACAC: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8013ACB0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013ACB4: b           L_8013ACCC
    // 0x8013ACB8: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
        goto L_8013ACCC;
    // 0x8013ACB8: swc1        $f8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f8.u32l;
L_8013ACBC:
    // 0x8013ACBC: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8013ACC0: lwc1        $f16, 0x20($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8013ACC4: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8013ACC8: swc1        $f18, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f18.u32l;
L_8013ACCC:
    // 0x8013ACCC: beq         $t1, $zero, L_8013ACE8
    if (ctx->r9 == 0) {
        // 0x8013ACD0: andi        $t2, $s1, 0x4
        ctx->r10 = ctx->r17 & 0X4;
            goto L_8013ACE8;
    }
    // 0x8013ACD0: andi        $t2, $s1, 0x4
    ctx->r10 = ctx->r17 & 0X4;
    // 0x8013ACD4: lwc1        $f4, 0x18($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8013ACD8: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8013ACDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013ACE0: b           L_8013ACF8
    // 0x8013ACE4: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
        goto L_8013ACF8;
    // 0x8013ACE4: swc1        $f8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f8.u32l;
L_8013ACE8:
    // 0x8013ACE8: lwc1        $f10, 0x18($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X18);
    // 0x8013ACEC: lwc1        $f16, 0x24($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8013ACF0: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8013ACF4: swc1        $f18, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f18.u32l;
L_8013ACF8:
    // 0x8013ACF8: beq         $t2, $zero, L_8013AD14
    if (ctx->r10 == 0) {
        // 0x8013ACFC: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8013AD14;
    }
    // 0x8013ACFC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8013AD00: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8013AD04: lwc1        $f6, 0x28($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8013AD08: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8013AD0C: b           L_8013AD24
    // 0x8013AD10: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
        goto L_8013AD24;
    // 0x8013AD10: swc1        $f8, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f8.u32l;
L_8013AD14:
    // 0x8013AD14: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8013AD18: lwc1        $f16, 0x28($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X28);
    // 0x8013AD1C: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8013AD20: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
L_8013AD24:
    // 0x8013AD24: jal         0x800ED3C0
    // 0x8013AD28: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    gmCollisionGetWorldPosition(rdram, ctx);
        goto after_1;
    // 0x8013AD28: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_1:
    // 0x8013AD2C: lwc1        $f0, 0x90($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8013AD30: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8013AD34: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8013AD38: nop

    // 0x8013AD3C: bc1fl       L_8013AD4C
    if (!c1cs) {
        // 0x8013AD40: c.lt.s      $f20, $f0
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
            goto L_8013AD4C;
    }
    goto skip_2;
    // 0x8013AD40: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    skip_2:
    // 0x8013AD44: mov.s       $f24, $f0
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    ctx->f24.fl = ctx->f0.fl;
    // 0x8013AD48: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
L_8013AD4C:
    // 0x8013AD4C: nop

    // 0x8013AD50: bc1fl       L_8013AD60
    if (!c1cs) {
        // 0x8013AD54: lwc1        $f0, 0x94($sp)
        ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
            goto L_8013AD60;
    }
    goto skip_3;
    // 0x8013AD54: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    skip_3:
    // 0x8013AD58: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8013AD5C: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
L_8013AD60:
    // 0x8013AD60: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
    // 0x8013AD64: nop

    // 0x8013AD68: bc1fl       L_8013AD78
    if (!c1cs) {
        // 0x8013AD6C: c.lt.s      $f22, $f0
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
            goto L_8013AD78;
    }
    goto skip_4;
    // 0x8013AD6C: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
    skip_4:
    // 0x8013AD70: mov.s       $f26, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    ctx->f26.fl = ctx->f0.fl;
    // 0x8013AD74: c.lt.s      $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f22.fl < ctx->f0.fl;
L_8013AD78:
    // 0x8013AD78: nop

    // 0x8013AD7C: bc1f        L_8013AD88
    if (!c1cs) {
        // 0x8013AD80: nop
    
            goto L_8013AD88;
    }
    // 0x8013AD80: nop

    // 0x8013AD84: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
L_8013AD88:
    // 0x8013AD88: bnel        $s1, $s5, L_8013ACA0
    if (ctx->r17 != ctx->r21) {
        // 0x8013AD8C: andi        $t0, $s1, 0x1
        ctx->r8 = ctx->r17 & 0X1;
            goto L_8013ACA0;
    }
    goto skip_5;
    // 0x8013AD8C: andi        $t0, $s1, 0x1
    ctx->r8 = ctx->r17 & 0X1;
    skip_5:
    // 0x8013AD90: addiu       $s7, $s7, 0x2C
    ctx->r23 = ADD32(ctx->r23, 0X2C);
L_8013AD94:
    // 0x8013AD94: addiu       $at, $zero, 0x1E4
    ctx->r1 = ADD32(0, 0X1E4);
    // 0x8013AD98: bne         $s7, $at, L_8013AC68
    if (ctx->r23 != ctx->r1) {
        // 0x8013AD9C: addiu       $s6, $s6, 0x2C
        ctx->r22 = ADD32(ctx->r22, 0X2C);
            goto L_8013AC68;
    }
    // 0x8013AD9C: addiu       $s6, $s6, 0x2C
    ctx->r22 = ADD32(ctx->r22, 0X2C);
    // 0x8013ADA0: sub.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x8013ADA4: lui         $at, 0x8019
    ctx->r1 = S32(0X8019 << 16);
    // 0x8013ADA8: lwc1        $f0, -0x3FD4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X3FD4);
    // 0x8013ADAC: sub.s       $f8, $f22, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = ctx->f22.fl - ctx->f26.fl;
    // 0x8013ADB0: lw          $t3, 0xA4($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XA4);
    // 0x8013ADB4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8013ADB8: swc1        $f6, 0x260($t3)
    MEM_W(0X260, ctx->r11) = ctx->f6.u32l;
    // 0x8013ADBC: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8013ADC0: lw          $t4, 0xA4($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XA4);
    // 0x8013ADC4: swc1        $f10, 0x264($t4)
    MEM_W(0X264, ctx->r12) = ctx->f10.u32l;
    // 0x8013ADC8: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x8013ADCC: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8013ADD0: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8013ADD4: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8013ADD8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8013ADDC: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8013ADE0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8013ADE4: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8013ADE8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8013ADEC: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8013ADF0: ldc1        $f26, 0x30($sp)
    CHECK_FR(ctx, 26);
    ctx->f26.u64 = LD(ctx->r29, 0X30);
    // 0x8013ADF4: ldc1        $f24, 0x28($sp)
    CHECK_FR(ctx, 24);
    ctx->f24.u64 = LD(ctx->r29, 0X28);
    // 0x8013ADF8: ldc1        $f22, 0x20($sp)
    CHECK_FR(ctx, 22);
    ctx->f22.u64 = LD(ctx->r29, 0X20);
    // 0x8013ADFC: ldc1        $f20, 0x18($sp)
    CHECK_FR(ctx, 20);
    ctx->f20.u64 = LD(ctx->r29, 0X18);
    // 0x8013AE00: jr          $ra
    // 0x8013AE04: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8013AE04: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
